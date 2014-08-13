#include "EwkAnalysis/include/EwkNtupleMaker.h"
#include "EwkAnalysis/include/EwkHistogramHandlers.h"
#include "PennSusyFrameCore/include/PennSusyFrameCore.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <dirent.h>
#include <math.h>
#include <algorithm>

#include "PennSusyFrameCore/include/ObjectContainers.h"
#include "PennSusyFrameCore/include/Calculators.h"
#include "PennSusyFrameCore/include/SelectorHelpers.h"
#include "EwkAnalysis/include/EwkTrigger.h"
#include "EwkAnalysis/include/EwkCutFlowTracker.h"
#include "PennSusyFrameCore/include/D3PDReader.h"

// -----------------------------------------------------------------------------
PennSusyFrame::EwkNtupleMaker::EwkNtupleMaker(TTree* tree) : PennSusyFrame::PennSusyFrameCore(tree)
                                                     , m_out_ntuple_file_name("EwkNtup.root")
                                                     , m_crit_cut_grl(false)
                                                     , m_crit_cut_incomplete_event(false)
                                                     , m_crit_cut_lar_error(false)
                                                     , m_crit_cut_tile_error(false)
                                                     , m_crit_cut_tile_hot_spot(false)
                                                     , m_crit_cut_tile_trip(false)
                                                     , m_crit_cut_bad_jet_veto(false)
                                                     , m_crit_cut_calo_problem_jet(false)
                                                     , m_crit_cut_primary_vertex(false)
                                                     , m_crit_cut_bad_mu_veto(false)
                                                     , m_crit_cut_cosmic_mu_veto(false)
                                                     , m_crit_cut_hfor(false)
                                                     , m_crit_cut_mc_overlap(false)
                                                     , m_crit_cut_ge_2_lep(false)
                                                     , m_crit_cut_2_lep(false)
                                                     , m_crit_cut_mll_sfos(false)
                                                     , m_crit_cut_signal_lep(false)
                                                     , m_crit_cut_phase_space(false)
                                                     , m_crit_cut_trigger(false)
                                                     , m_crit_cut_trigger_match(false)
                                                     , m_crit_cut_tau_veto(false)
                                                     , m_crit_cut_ss(false)
                                                     , m_crit_cut_prompt_leptons(false)
                                                     , m_crit_cut_stream_overlap(false)
                                                     , m_crit_cut_no_charge_flip(false)
                                                     , m_crit_cut_emma_mt(false)
                                                     , m_crit_cut_met_rel(false)
                                                     , m_crit_cut_dphi_ll(false)
                                                     , m_crit_cut_b_veto(false)
                                                     , m_crit_cut_num_jet(false)
                                                     , m_sfos_mll_min(-1)
                                                     , m_sfos_mll_max(-1)
                                                     , m_emma_mt_min(-1)
                                                     , m_emma_mt_max(-1)
                                                     , m_met_rel_min(-1)
                                                     , m_met_rel_max(-1)
                                                     , m_dphi_ll_min(-1)
                                                     , m_dphi_ll_max(-1)
                                                     , doBaselineSkim(false)
{
  // set defaults
  /*setSFOSMllCut(20.e3, -1);
  setEmmaMtCut(-1, 50.e3);
  setMetRelCut(40.e3, -1);
  setDphillCut(1.3, -1);
  setNumLightJetsCut(1, -1);*/
}

// -----------------------------------------------------------------------------
PennSusyFrame::EwkNtupleMaker::~EwkNtupleMaker()
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::EwkNtupleMaker::prepareTools()
{
  PennSusyFrameCore::prepareTools();

  std::string base_dir = getenv("BASE_WORK_DIR");
  if (m_is_data) {
    // TODO make this configurable
    m_grl.init( base_dir
              + "/data/data12_8TeV.periodAllYear_DetStatus-v58-pro14-01_DQDefects-00-00-33_PHYS_StandardGRL_All_Good.xml"
              );
  }

  m_charge_flip_tool.init();
}
// -----------------------------------------------------------------------------
void PennSusyFrame::EwkNtupleMaker::prepareSelection()
{
  PennSusyFrameCore::prepareSelection();
  std::cout << "preparing selection\n";
}
// -----------------------------------------------------------------------------
void PennSusyFrame::EwkNtupleMaker::beginRun()
{
  PennSusyFrameCore::beginRun();
  prepareSelection();
  configureOutput(m_out_ntuple_file_name, "optimize");
}

// -----------------------------------------------------------------------------
void PennSusyFrame::EwkNtupleMaker::processEvent()
{
  clearVariables();
  m_event_weight = 1.;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set mc event weight
  // TODO validate MC event weight
  m_event_weight *= m_event_quantities.getMcEventWeight();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set pile up weight
  // TODO validate pile up weight
  m_event_weight *= m_event_quantities.getPileUpSF();

  // -----------------------------------------------------------------------------
  m_event.setTriggerPhase( PennSusyFrame::getTriggerPhase( m_electrons.getCollection(EL_GOOD)
                                                         , m_muons.getCollection(MU_GOOD)
                                                         )
                         );
  m_event.setPhaseSpace(PennSusyFrame::getPhaseSpaceFromTriggerPhase(m_event.getTriggerPhase()));

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // GRL cut
  // TODO validate grl cut
  // only check grl cut on data
  bool pass_grl = (!m_is_data || m_grl.passEvent(m_event));
  m_pass_event = (m_pass_event && pass_grl);
  if (m_crit_cut_grl && !pass_grl) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // incomplete event cut
  // TODO validate incomplete event cut
  bool pass_incomplete_event = PennSusyFrame::passIncompleteEvent(m_event);
  m_pass_event = (m_pass_event && pass_incomplete_event);
  if (m_crit_cut_incomplete_event && !pass_incomplete_event) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // LAr error cut
  // TODO validate LAr error cut
  bool pass_lar_error = PennSusyFrame::passLarError(m_event);
  m_pass_event = (m_pass_event && pass_lar_error);
  if (m_crit_cut_lar_error && !pass_lar_error) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile error cut
  // TODO validate tile error cut
  bool pass_tile_error = PennSusyFrame::passTileError(m_event);
  m_pass_event = (m_pass_event && pass_tile_error);
  if (m_crit_cut_tile_error && !pass_tile_error) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile hot spot cut
  // TODO validate tile hot spot cut
  bool pass_tile_hot_spot = PennSusyFrame::TileHotSpotTool::passTileHotSpot(m_event, m_jets);
  m_pass_event = (m_pass_event && pass_tile_hot_spot);
  if (m_crit_cut_tile_hot_spot && !pass_tile_hot_spot) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile trip cut
  // TODO validate tile trip cut
  bool pass_tile_trip = m_tile_trip_tool.passTileTrip(m_event);
  m_pass_event = (m_pass_event && pass_tile_trip);
  if (m_crit_cut_tile_trip && !pass_tile_trip) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // bad jet veto
  bool pass_bad_jet_veto = (m_jets.num(JET_BAD) == 0);
  m_pass_event = (m_pass_event && pass_bad_jet_veto);
  if (m_crit_cut_bad_jet_veto && !pass_bad_jet_veto) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // calo problem jet cut
  bool pass_calo_problem_jet = (m_jets.num(JET_CALO_PROBLEM) == 0);
  m_pass_event = (m_pass_event && pass_calo_problem_jet);
  if (m_crit_cut_calo_problem_jet && !pass_calo_problem_jet) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // primary vertex cut
  bool pass_primary_vertex = PennSusyFrame::passPrimaryVertex(m_vertices);
  m_pass_event = (m_pass_event && pass_primary_vertex);
  if (m_crit_cut_primary_vertex && !pass_primary_vertex) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // bad muon cut
  bool pass_bad_mu_veto = (m_muons.num(MU_BAD) == 0);
  m_pass_event = (m_pass_event && pass_bad_mu_veto);
  if (m_crit_cut_bad_mu_veto && !pass_bad_mu_veto) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // cosmic muon veto
  bool pass_cosmic_mu_veto = (m_muons.num(MU_COSMIC) == 0);
  m_pass_event = (m_pass_event && pass_cosmic_mu_veto);
  if (m_crit_cut_cosmic_mu_veto && !pass_cosmic_mu_veto) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // HFOR cut
  // TODO validate HFOR cut
  bool pass_hfor = m_hfor_tool.passHFOR(m_mc_truth);
  m_pass_event = (m_pass_event && pass_hfor);
  if (m_crit_cut_hfor && !pass_hfor) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // mc overlap cut
  // TODO validate mc overlap cut
  bool pass_mc_overlap = (  PennSusyFrame::passSherpaWWOverlapRemoval(m_event, m_mc_truth)
                         && PennSusyFrame::passZOverlapRemoval(m_mc_truth)
                         );
  m_pass_event = (m_pass_event && pass_mc_overlap);
  if (m_crit_cut_mc_overlap && !pass_mc_overlap) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get number of good leptons
  int num_good_leptons = m_electrons.num(EL_GOOD) + m_muons.num(MU_GOOD);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // >= 2 baseline leptons cut
  bool pass_ge_2_lep = (num_good_leptons >= 2);
  m_pass_event = (m_pass_event && pass_ge_2_lep);
  if (m_crit_cut_ge_2_lep && !pass_ge_2_lep) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // == 2 baseline leptons cut

  bool pass_2_lep = (num_good_leptons == 2);
  m_pass_event = (m_pass_event && pass_2_lep);
  if (m_crit_cut_2_lep && !pass_2_lep) return;
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // mll SFOS cut
  bool pass_mll_sfos = ( PennSusyFrame::passCut( m_event_quantities.getMll()
                                               , m_sfos_mll_min
                                               , m_sfos_mll_max
                                               )
                       );
  m_pass_event = (m_pass_event && pass_mll_sfos);
  if (m_crit_cut_mll_sfos && !pass_mll_sfos) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get number of signal leptons
  int num_signal_leptons = m_electrons.num(EL_SIGNAL) + m_muons.num(MU_SIGNAL);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // == 2 signal lepton cut
  if (!doBaselineSkim){
  bool pass_signal_lep = (num_signal_leptons == 2);
  m_pass_event = (m_pass_event && pass_signal_lep);
  if (m_crit_cut_signal_lep && !pass_signal_lep) return;
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // lepton scale factor
  // TODO validate lepton sf
  m_event_weight *= m_event_quantities.getLeptonSF();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // phase space cut
  bool pass_phase_space = (m_event.getTriggerPhase() != TRIG_NONE);
  m_pass_event = (m_pass_event && pass_phase_space);
  if (m_crit_cut_phase_space && !pass_phase_space) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // trigger cut
  // TODO validate trigger cut
  bool pass_trigger = (  !m_is_data
                      || PennSusyFrame::passAnyTrigger( m_event
                                                      , m_trigger
                                                      )
                      );
  m_pass_event = (m_pass_event && pass_trigger);
  if (m_crit_cut_trigger && !pass_trigger) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // trigger matching
  // TODO validate trigger matching
  bool pass_trigger_match = (  !m_is_data
                            || PennSusyFrame::passTriggerMatching( m_event
                                                                 , m_trigger
                                                                 , m_electrons.getCollection(EL_GOOD)
                                                                 , m_muons.getCollection(MU_GOOD)
                                                                 )
                            );
  m_pass_event = (m_pass_event && pass_trigger_match);
  if (m_crit_cut_trigger_match && !pass_trigger_match) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // TODO implement trigger SF
  m_event_weight *= m_event_quantities.getTriggerWeight();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tau veto
  // TODO validate tau veto
  bool pass_tau_veto = (m_taus.num(TAU_SIGNAL) == 0);
  m_pass_event = (m_pass_event && pass_tau_veto);
  if (m_crit_cut_tau_veto && !pass_tau_veto) return;
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // check for SS leptons
  // TODO validate SS leptons requirement
  //bool pass_ss = (m_event.getSignChannel() == SIGN_SS);
  //m_pass_event = (m_pass_event && pass_ss);
  //if (m_crit_cut_ss && !pass_ss) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // check for prompt leptons
  // TODO validate check for prompt leptons
  bool pass_prompt_leptons = (m_is_data || m_event.getPromptLeptons());
  m_pass_event = (m_pass_event && pass_prompt_leptons);
  if (m_crit_cut_prompt_leptons && !pass_prompt_leptons) return;


  // // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // // check for stream overlap
  // // TODO implement check for stream overlap
  // bool pass_stream_overlap = true;
  // m_pass_event = (m_pass_event && pass_stream_overlap);
  // if (m_crit_cut_stream_overlap && !pass_stream_overlap) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // require no charge flip
  // TODO validate no charge flip cut
  bool pass_no_charge_flip = (  m_is_data
                             || m_event.getTruthSignChannel() == m_event.getSignChannel()
                             );
  m_pass_event = (m_pass_event && pass_no_charge_flip);
  if (m_crit_cut_no_charge_flip && !pass_no_charge_flip) return;
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // emma mt cut
  // TODO validate emma mt cut
  /*bool pass_emma_mt = ( PennSusyFrame::passCut( m_event_quantities.getEmmaMt()
                                              , m_emma_mt_min
                                              , m_emma_mt_max
                                              )
                      );
  m_pass_event = (m_pass_event && pass_emma_mt);
  if (m_crit_cut_emma_mt && !pass_emma_mt) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // met rel cut
  // TODO validate met-rel cut
  bool pass_met_rel = ( PennSusyFrame::passCut( m_met.getMetRel()
                                              , m_met_rel_min
                                              , m_met_rel_max
                                              )
                      );
  m_pass_event = (m_pass_event && pass_met_rel);
  if (m_crit_cut_met_rel && !pass_met_rel) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // dphi_ll cut
  // TODO validate dphill cut
  bool pass_dphi_ll = ( PennSusyFrame::passCut( m_event_quantities.getDphill()
                                              , m_dphi_ll_min
                                              , m_dphi_ll_max
                                              )
                      );
  m_pass_event = (m_pass_event && pass_dphi_ll);
  if (m_crit_cut_dphi_ll && !pass_dphi_ll) return;*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // b jet veto
  // TODO validate b veto cut
  bool pass_b_veto = (m_jets.num(JET_B) == 0);
  m_pass_event = (m_pass_event && pass_b_veto);
  if (m_crit_cut_b_veto && !pass_b_veto) return;
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // b tag sf
  // TODO validate b tag SF
  m_event_weight *= m_event_quantities.getBTagSF();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // # light jet cut
  // TODO validate light jet cut
  /*bool pass_num_jet = ( PennSusyFrame::passCut( static_cast<int>(m_jets.num(JET_LIGHT))
                                              , m_num_light_jets_min
                                              , m_num_light_jets_max
                                              )
                      );
  m_pass_event = (m_pass_event && pass_num_jet);
  if (m_crit_cut_num_jet && !pass_num_jet) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get charge flip weight
  // TODO move this to more sensible location
  m_event_quantities.setCFWeight(m_charge_flip_tool.getSF( m_event.getFlavorChannel()
                                                         , m_electrons.getCollection(EL_GOOD)
                                                         , m_muons.getCollection(MU_GOOD)
                                                         )
                                );*/

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // fill histograms
  // TODO reimpliment filling histograms after bugs are worked out
  // if (m_pass_event) {
  //   size_t num_hists = m_histogram_handlers.size();
  //   for (size_t hist_it = 0; hist_it != num_hists; ++hist_it) {
  //     m_histogram_handlers.at(hist_it)->Fill( m_event
  //                                           , m_event_quantities
  //                                           , m_electrons.getCollection(EL_GOOD)
  //                                           , m_muons.getCollection(MU_GOOD)
  //                                           , m_jets.getCollection(JET_GOOD)
  //                                           , m_met
  //                                           , m_event_weight
  //                                           );
  //   }
  // }
  
  if (m_pass_event) {
    fillNtuple( m_event_weight);
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::EwkNtupleMaker::finalizeEvent()
{
  // fillTnt();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::EwkNtupleMaker::finalizeRun()
{
  std::cout<< "EwkNtupleMaker::finalizeRun()\n";
  m_output_file->Write();
  m_output_file->Close();

  // writeTnt();
}

void PennSusyFrame::EwkNtupleMaker::clearVariables()
{
  m_weight = 1.;

  m_mll = 0 ;
  m_ptll = 0 ;
  m_mt = 0;

  m_met_et  = 0 ;
  m_met_rel = 0 ;
	
  m_el_pt.clear();
  m_el_eta.clear();
  m_el_phi.clear();
	
  m_mu_pt.clear();
  m_mu_eta.clear();
  m_mu_phi.clear();
	
  m_lep_pt.clear();
  m_lep_eta.clear();
  m_lep_phi.clear();
  m_lep_signal.clear();
	
  m_jet_pt.clear();
  m_jet_eta.clear();
  m_jet_phi.clear();
	
  m_ljet_pt.clear();
  m_ljet_eta.clear();
  m_ljet_phi.clear();

  m_ht_signal   = 0 ;
  m_num_light_jets = 0;
  m_num_forward_jets = 0;
}

void PennSusyFrame::EwkNtupleMaker::configureOutput( std::string out_file_name
                                                               , std::string out_tree_name
                                                               )
{
  m_output_file = new TFile(out_file_name.c_str(), "RECREATE");
  m_output_tree = new TTree(out_tree_name.c_str(), out_tree_name.c_str());

  // connect branches for output
  m_output_tree->Branch( "event_number" , &m_event_number);
  m_output_tree->Branch( "run_number" , &m_run_number);
  m_output_tree->Branch( "weight" , &m_weight);
  m_output_tree->Branch( "x_sec" , &m_x_sec);
  m_output_tree->Branch( "k_factor" , &m_k_factor);
  m_output_tree->Branch( "filter_eff" , &m_filter_eff);
  m_output_tree->Branch( "cfweight" , &m_cfweight);
  m_output_tree->Branch( "isSS" , &m_isSS);
  m_output_tree->Branch( "isEE" , &m_isEE);
  m_output_tree->Branch( "isEM" , &m_isEM);
  m_output_tree->Branch( "isMM" , &m_isMM);
	
  m_output_tree->Branch( "n_el" , &m_num_el);
  m_output_tree->Branch( "n_mu" , &m_num_mu);
	
  m_output_tree->Branch( "el_pt" , &m_el_pt);
  m_output_tree->Branch( "el_eta" , &m_el_eta);
  m_output_tree->Branch( "el_phi" , &m_el_phi);
	
  m_output_tree->Branch( "mu_pt" , &m_mu_pt);
  m_output_tree->Branch( "mu_eta" , &m_mu_eta);
  m_output_tree->Branch( "mu_phi" , &m_mu_phi);
	
  m_output_tree->Branch( "lep_pt" , &m_lep_pt);
  m_output_tree->Branch( "lep_eta" , &m_lep_eta);
  m_output_tree->Branch( "lep_phi" , &m_lep_phi);
  m_output_tree->Branch( "lep_signal" , &m_lep_signal);
	
  m_output_tree->Branch( "jet_pt" , &m_jet_pt);
  m_output_tree->Branch( "jet_eta" , &m_jet_eta);
  m_output_tree->Branch( "jet_phi" , &m_jet_phi);
	
  m_output_tree->Branch( "ljet_pt" , &m_ljet_pt);
  m_output_tree->Branch( "ljet_eta" , &m_ljet_eta);
  m_output_tree->Branch( "ljet_phi" , &m_ljet_phi);
                                                                   
  m_output_tree->Branch( "mll"  , &m_mll);
  m_output_tree->Branch( "ptll" , &m_ptll);
  m_output_tree->Branch( "mt" , &m_mt);
  m_output_tree->Branch( "mt2" , &m_mt2);
  m_output_tree->Branch( "dphill" , &m_dphill);
                                        
  m_output_tree->Branch( "met_et"  , &m_met_et);
  m_output_tree->Branch( "met_rel" , &m_met_rel);
  m_output_tree->Branch( "met_phi" , &m_met_phi);

                                        
  m_output_tree->Branch( "ht_signal"   , &m_ht_signal);
  m_output_tree->Branch( "n_ljets" , &m_num_light_jets);
  m_output_tree->Branch( "n_fjets" , &m_num_forward_jets);
	m_output_tree->Branch( "n_jets" , &m_num_jets);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::EwkNtupleMaker::fillNtuple( float weight)
{
	
  m_el_pt   = getSelectionPt ((std::vector<PennSusyFrame::Particle*>*)m_electrons.getCollection(EL_GOOD));
  m_el_signal   = getSelectionSignal ((std::vector<PennSusyFrame::Particle*>*)m_electrons.getCollection(EL_GOOD));
  m_mu_signal   = getSelectionSignal ((std::vector<PennSusyFrame::Particle*>*)m_muons.getCollection(MU_GOOD));
  m_mu_pt   = getSelectionPt ((std::vector<PennSusyFrame::Particle*>*)m_muons.getCollection(MU_GOOD));
  m_jet_pt  = getSelectionPt ((std::vector<PennSusyFrame::Particle*>*)m_jets.getCollection(JET_GOOD));
  m_ljet_pt  = getSelectionPt ((std::vector<PennSusyFrame::Particle*>*)m_jets.getCollection(JET_LIGHT));
  m_el_eta  = getSelectionEta((std::vector<PennSusyFrame::Particle*>*)m_electrons.getCollection(EL_GOOD));
  m_mu_eta  = getSelectionEta((std::vector<PennSusyFrame::Particle*>*)m_muons.getCollection(MU_GOOD));
  m_jet_eta = getSelectionEta((std::vector<PennSusyFrame::Particle*>*)m_jets.getCollection(JET_GOOD));
  m_ljet_eta = getSelectionEta((std::vector<PennSusyFrame::Particle*>*)m_jets.getCollection(JET_LIGHT));
  m_el_phi  = getSelectionPhi((std::vector<PennSusyFrame::Particle*>*)m_electrons.getCollection(EL_GOOD));
  m_mu_phi  = getSelectionPhi((std::vector<PennSusyFrame::Particle*>*)m_muons.getCollection(MU_GOOD));
  m_jet_phi = getSelectionPhi((std::vector<PennSusyFrame::Particle*>*)m_jets.getCollection(JET_GOOD));
  m_ljet_phi = getSelectionPhi((std::vector<PennSusyFrame::Particle*>*)m_jets.getCollection(JET_LIGHT));
	
  m_weight = weight;
  m_event_quantities.setCFWeight(m_charge_flip_tool.getSF( m_event.getFlavorChannel()
															, m_electrons.getCollection(EL_GOOD)
															, m_muons.getCollection(MU_GOOD)));
  m_cfweight = m_event_quantities.getCFWeight();
  m_event_number = m_event.getEventNumber();
  m_run_number = m_event.getRunNumber();
	
  m_isSS = (m_event.getSignChannel()==SIGN_SS);
  m_num_el = m_electrons.num(EL_GOOD);
  m_num_mu = m_muons.num(MU_GOOD);
	
  m_isEE = m_num_el == 2;
  m_isEM = m_num_el == 1 && m_num_mu == 1;
  m_isMM = m_num_mu == 2;
	


	
	if (m_isEE){
		if (m_el_pt[0] > m_el_pt[1])
			getSortLepPts(0,1,m_el_pt, m_el_eta, m_el_phi, m_el_signal);
		else 
			getSortLepPts(1,0,m_el_pt, m_el_eta, m_el_phi, m_el_signal);
		
	}else if (m_isMM){
		if (m_mu_pt[0] > m_mu_pt[1])
			getSortLepPts(0,1,m_mu_pt, m_mu_eta, m_mu_phi, m_mu_signal);
		else 
			getSortLepPts(1,0,m_mu_pt, m_mu_eta, m_mu_phi, m_mu_signal);
		
	}else if (m_isEM){
		if (m_mu_pt[0] > m_el_pt[0]){
			m_lep_pt.push_back( m_mu_pt[0]);
			m_lep_eta.push_back(m_mu_eta[0]);
			m_lep_phi.push_back(m_mu_phi[0]);
			m_lep_signal.push_back(m_mu_signal[0]);
			m_lep_pt.push_back( m_el_pt[0]);
			m_lep_eta.push_back(m_el_eta[0]);
			m_lep_phi.push_back(m_el_phi[0]);
			m_lep_signal.push_back(m_el_signal[0]);
		}else{
			m_lep_pt.push_back( m_el_pt[0]);
			m_lep_eta.push_back(m_el_eta[0]);
			m_lep_phi.push_back(m_el_phi[0]);
			m_lep_signal.push_back(m_el_signal[0]);
			m_lep_pt.push_back( m_mu_pt[0]);
			m_lep_eta.push_back(m_mu_eta[0]);
			m_lep_phi.push_back(m_mu_phi[0]);
			m_lep_signal.push_back(m_mu_signal[0]);
		}
	}
	
  m_mll  = m_event_quantities.getMll()/1.e3;
  m_ptll = m_event_quantities.getPtll()/1.e3;
  m_mt = m_event_quantities.getEmmaMt();
  m_mt2 = m_event_quantities.getMt2();
  m_dphill = m_event_quantities.getDphill();

  m_met_et  = m_met.getMetEt() /1.e3;
  m_met_rel = m_met.getMetRel()/1.e3;
  m_met_phi = m_met.getMetPhi();


  m_ht_signal   = m_event_quantities.getHtSignal()/1.e3;
  m_num_light_jets= m_jets.num(JET_LIGHT);
  m_num_jets= m_jets.num(JET_GOOD);
  m_num_forward_jets= m_jets.num(JET_FORWARD);
	
  // fill output tree
  m_output_tree->Fill();
}

void PennSusyFrame::EwkNtupleMaker::getSortLepPts(float i1, float i2,
												  std::vector<float> pt, 
												  std::vector<float> eta, 
												  std::vector<float> phi ,std::vector<bool> signal){
	m_lep_pt.push_back( pt[i1]);
	m_lep_eta.push_back(eta[i1]);
	m_lep_phi.push_back(phi[i1]);
	m_lep_signal.push_back(signal[i1]);
	m_lep_pt.push_back( pt[i2]);
	m_lep_eta.push_back(eta[i2]);
	m_lep_phi.push_back(phi[i2]);
	m_lep_signal.push_back(signal[i2]);


}

std::vector<bool> PennSusyFrame::EwkNtupleMaker::getSelectionSignal(std::vector<PennSusyFrame::Particle*>* obj){
	std::vector<bool> sig;
	for (unsigned int i = 0; i < obj->size(); i++)
		sig.push_back(obj->at(i)->getIsSignal());
	return sig;
}

std::vector<float> PennSusyFrame::EwkNtupleMaker::getSelectionPt(std::vector<PennSusyFrame::Particle*>* obj){
	std::vector<float> pt;
	for (unsigned int i = 0; i < obj->size(); i++)
		pt.push_back(obj->at(i)->getPt());
	return pt;
}

std::vector<float> PennSusyFrame::EwkNtupleMaker::getSelectionEta(std::vector<PennSusyFrame::Particle*>* obj){
	std::vector<float> eta;
	for (unsigned int i = 0; i < obj->size(); i++)
		eta.push_back(obj->at(i)->getEta());
	return eta;
}

std::vector<float> PennSusyFrame::EwkNtupleMaker::getSelectionPhi(std::vector<PennSusyFrame::Particle*>* obj){
	std::vector<float> phi;
	for (unsigned int i = 0; i < obj->size(); i++)
		phi.push_back(obj->at(i)->getPhi());
	return phi;
}
