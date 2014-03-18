#include "EwkAnalysis/include/IsrAnalysis.h"
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
PennSusyFrame::IsrAnalysis::IsrAnalysis(TTree* tree) : PennSusyFrame::PennSusyFrameCore(tree)
                                                     , m_out_hist_file_name("IsrHist.root")
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
                                                     , m_num_light_jets_min(-1)
                                                     , m_num_light_jets_max(-1)
{
  // set defaults
  setSFOSMllCut(20.e3, -1);
  setEmmaMtCut(-1, 50.e3);
  setMetRelCut(40.e3, -1);
  setDphillCut(1.3, -1);
  setNumLightJetsCut(1, -1);
}

// -----------------------------------------------------------------------------
PennSusyFrame::IsrAnalysis::~IsrAnalysis()
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::IsrAnalysis::prepareTools()
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
void PennSusyFrame::IsrAnalysis::prepareSelection()
{
  PennSusyFrameCore::prepareSelection();

  std::cout << "preparing selection\n";


}
// -----------------------------------------------------------------------------
void PennSusyFrame::IsrAnalysis::beginRun()
{

  PennSusyFrameCore::beginRun();

  prepareSelection();
  m_histogram_handlers.resize(ISR_HIST_N);
  
  for (unsigned int hist_level = 0; hist_level != ISR_HIST_N; ++hist_level) {
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::EventLevelHists(      PennSusyFrame::ISR_HIST_LEVEL_STRINGS[hist_level]) );
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::LeptonKinematicsHists(PennSusyFrame::ISR_HIST_LEVEL_STRINGS[hist_level]) );
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::JetKinematicsHists(   PennSusyFrame::ISR_HIST_LEVEL_STRINGS[hist_level]) );
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::MetHists(             PennSusyFrame::ISR_HIST_LEVEL_STRINGS[hist_level]) );
   
    m_isr_histogram_handler.push_back(new PennSusyFrame::EwkHists(PennSusyFrame::ISR_HIST_LEVEL_STRINGS[hist_level]));
 }


  // configureTnt(m_out_tnt_file_name, "TNT");
}

// -----------------------------------------------------------------------------
void PennSusyFrame::IsrAnalysis::processEvent()
{
  m_event_weight = 1.;

  m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_ALL);
  m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_ALL, m_event_weight);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set mc event weight
  // TODO validate MC event weight
  m_event_weight *= m_event_quantities.getMcEventWeight();
  m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_MC_EVENT_WEIGHT);
  m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_MC_EVENT_WEIGHT, m_event_weight);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set pile up weight
  // TODO validate pile up weight
  m_event_weight *= m_event_quantities.getPileUpSF();
  m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_PILEUP_WEIGHT);
  m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_PILEUP_WEIGHT, m_event_weight);
 // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set xsec weight
  // TODO validate cross section weight

  m_event_weight *= m_xsec_weight;
  m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_XSEC_WEIGHT);
  m_cutflow_tracker.fillHist( FLAVOR_NONE, ISR_CUT_XSEC_WEIGHT, m_event_weight);

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
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_GRL);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_GRL, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // incomplete event cut
  // TODO validate incomplete event cut
  bool pass_incomplete_event = PennSusyFrame::passIncompleteEvent(m_event);
  m_pass_event = (m_pass_event && pass_incomplete_event);
  if (m_crit_cut_incomplete_event && !pass_incomplete_event) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_INCOMPLETE_EVENT);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_INCOMPLETE_EVENT, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // LAr error cut
  // TODO validate LAr error cut
  bool pass_lar_error = PennSusyFrame::passLarError(m_event);
  m_pass_event = (m_pass_event && pass_lar_error);
  if (m_crit_cut_lar_error && !pass_lar_error) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_LAR_ERROR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_LAR_ERROR, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile error cut
  // TODO validate tile error cut
  bool pass_tile_error = PennSusyFrame::passTileError(m_event);
  m_pass_event = (m_pass_event && pass_tile_error);
  if (m_crit_cut_tile_error && !pass_tile_error) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_TILE_ERROR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_TILE_ERROR, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile hot spot cut
  // TODO validate tile hot spot cut
  bool pass_tile_hot_spot = PennSusyFrame::TileHotSpotTool::passTileHotSpot(m_event, m_jets);
  m_pass_event = (m_pass_event && pass_tile_hot_spot);
  if (m_crit_cut_tile_hot_spot && !pass_tile_hot_spot) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_TILE_HOT_SPOT);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_TILE_HOT_SPOT, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile trip cut
  // TODO validate tile trip cut
  bool pass_tile_trip = m_tile_trip_tool.passTileTrip(m_event);
  m_pass_event = (m_pass_event && pass_tile_trip);
  if (m_crit_cut_tile_trip && !pass_tile_trip) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_TILE_TRIP);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_TILE_TRIP, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // bad jet veto
  bool pass_bad_jet_veto = (m_jets.num(JET_BAD) == 0);
  m_pass_event = (m_pass_event && pass_bad_jet_veto);
  if (m_crit_cut_bad_jet_veto && !pass_bad_jet_veto) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_BAD_JET_VETO);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_BAD_JET_VETO, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // calo problem jet cut
  bool pass_calo_problem_jet = (m_jets.num(JET_CALO_PROBLEM) == 0);
  m_pass_event = (m_pass_event && pass_calo_problem_jet);
  if (m_crit_cut_calo_problem_jet && !pass_calo_problem_jet) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_CALO_PROBLEM_JET);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_CALO_PROBLEM_JET, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // primary vertex cut
  bool pass_primary_vertex = PennSusyFrame::passPrimaryVertex(m_vertices);
  m_pass_event = (m_pass_event && pass_primary_vertex);
  if (m_crit_cut_primary_vertex && !pass_primary_vertex) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_PRIMARY_VERTEX);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_PRIMARY_VERTEX, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // bad muon cut
  bool pass_bad_mu_veto = (m_muons.num(MU_BAD) == 0);
  m_pass_event = (m_pass_event && pass_bad_mu_veto);
  if (m_crit_cut_bad_mu_veto && !pass_bad_mu_veto) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_BAD_MUON);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_BAD_MUON, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // cosmic muon veto
  bool pass_cosmic_mu_veto = (m_muons.num(MU_COSMIC) == 0);
  m_pass_event = (m_pass_event && pass_cosmic_mu_veto);
  if (m_crit_cut_cosmic_mu_veto && !pass_cosmic_mu_veto) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_COSMIC_MUON_VETO);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_COSMIC_MUON_VETO, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // HFOR cut
  // TODO validate HFOR cut
  bool pass_hfor = m_hfor_tool.passHFOR(m_mc_truth);
  m_pass_event = (m_pass_event && pass_hfor);
  if (m_crit_cut_hfor && !pass_hfor) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_HFOR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_HFOR, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // mc overlap cut
  // TODO validate mc overlap cut
  bool pass_mc_overlap = (  PennSusyFrame::passSherpaWWOverlapRemoval(m_event, m_mc_truth)
                         && PennSusyFrame::passZOverlapRemoval(m_mc_truth)
                         );
  m_pass_event = (m_pass_event && pass_mc_overlap);
  if (m_crit_cut_mc_overlap && !pass_mc_overlap) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_MC_OVERLAP);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_MC_OVERLAP, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get number of good leptons
  int num_good_leptons = m_electrons.num(EL_GOOD) + m_muons.num(MU_GOOD);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // >= 2 baseline leptons cut
  bool pass_ge_2_lep = (num_good_leptons >= 2);
  m_pass_event = (m_pass_event && pass_ge_2_lep);
  if (m_crit_cut_ge_2_lep && !pass_ge_2_lep) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_GE_2_BASELINE_LEPTONS);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_GE_2_BASELINE_LEPTONS, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // == 2 baseline leptons cut
  bool pass_2_lep = (num_good_leptons == 2);
  m_pass_event = (m_pass_event && pass_2_lep);
  if (m_crit_cut_2_lep && !pass_2_lep) return;
  if (m_pass_event) {
    {
      m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_EQ_2_BASELINE_LEPTONS);
      m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_EQ_2_BASELINE_LEPTONS, m_event_weight);
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // mll SFOS cut
  bool pass_mll_sfos = ( PennSusyFrame::passCut( m_event_quantities.getMll()
                                               , m_sfos_mll_min
                                               , m_sfos_mll_max
                                               )
                       );
  m_pass_event = (m_pass_event && pass_mll_sfos);
  if (m_crit_cut_mll_sfos && !pass_mll_sfos) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_MLL_SFOS);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_MLL_SFOS, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get number of signal leptons
  int num_signal_leptons = m_electrons.num(EL_SIGNAL) + m_muons.num(MU_SIGNAL);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // == 2 signal lepton cut
  bool pass_signal_lep = (num_signal_leptons == 2);
  m_pass_event = (m_pass_event && pass_signal_lep);
  if (m_crit_cut_signal_lep && !pass_signal_lep) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_EQ_2_SIGNAL_LEPTON);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_EQ_2_SIGNAL_LEPTON, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // lepton scale factor
  // TODO validate lepton sf
  m_event_weight *= m_event_quantities.getLeptonSF();
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_LEP_SF);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_LEP_SF, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), ISR_CUT_LEP_SF);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), ISR_CUT_LEP_SF, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // phase space cut
  bool pass_phase_space = (m_event.getTriggerPhase() != TRIG_NONE);
  m_pass_event = (m_pass_event && pass_phase_space);
  if (m_crit_cut_phase_space && !pass_phase_space) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_PHASE_SPACE);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_PHASE_SPACE, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), ISR_CUT_PHASE_SPACE);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), ISR_CUT_PHASE_SPACE, m_event_weight);
  }

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
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_TRIGGER);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_TRIGGER, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), ISR_CUT_TRIGGER);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), ISR_CUT_TRIGGER, m_event_weight);
  }

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
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_TRIGGER_MATCHING);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_TRIGGER_MATCHING, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), ISR_CUT_TRIGGER_MATCHING);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), ISR_CUT_TRIGGER_MATCHING, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // TODO implement trigger SF
  m_event_weight *= m_event_quantities.getTriggerWeight();
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_TRIGGER_WEIGHT);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_TRIGGER_WEIGHT, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), ISR_CUT_TRIGGER_WEIGHT);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), ISR_CUT_TRIGGER_WEIGHT, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tau veto
  // TODO validate tau veto
  bool pass_tau_veto = (m_taus.num(TAU_SIGNAL) == 0);
  m_pass_event = (m_pass_event && pass_tau_veto);
  if (m_crit_cut_tau_veto && !pass_tau_veto) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_TAU_VETO);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_TAU_VETO, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), ISR_CUT_TAU_VETO);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), ISR_CUT_TAU_VETO, m_event_weight);
  }
//
//  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // check for OS leptons
  // TODO validate SS leptons requirement
  bool pass_os = (m_event.getSignChannel() == SIGN_OS);
  m_pass_event = (m_pass_event && pass_os);
  if (m_crit_cut_ss && !pass_os) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_OS);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_OS, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), ISR_CUT_OS);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), ISR_CUT_OS, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // check for prompt leptons
  // TODO validate check for prompt leptons
  bool pass_prompt_leptons = (m_is_data || m_event.getPromptLeptons());
  m_pass_event = (m_pass_event && pass_prompt_leptons);
  if (m_crit_cut_prompt_leptons && !pass_prompt_leptons) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_PROMPT_LEP);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_PROMPT_LEP, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), ISR_CUT_PROMPT_LEP);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), ISR_CUT_PROMPT_LEP, m_event_weight);
  }


  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // check for Z-window
  // to do make this configurable
  bool pass_z_window =( fabs(m_event_quantities.getMll() - 91.e3) < 10.e3 );
  m_pass_event = (m_pass_event && pass_z_window);
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_Z_WINDOW);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_Z_WINDOW, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), ISR_CUT_Z_WINDOW);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), ISR_CUT_Z_WINDOW, m_event_weight);
  }



  // fill histograms for ZVETO hist level
  if (m_pass_event) {
    fillHistHandles( PennSusyFrame::ISR_HIST_ZVETO
		     , m_event_weight
		     );
  }

//  // // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  // // check for stream overlap
//  // // TODO implement check for stream overlap
//  // bool pass_stream_overlap = true;
//  // m_pass_event = (m_pass_event && pass_stream_overlap);
//  // if (m_crit_cut_stream_overlap && !pass_stream_overlap) return;
//
//  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  // require no charge flip
//  // TODO validate no charge flip cut
//  bool pass_no_charge_flip = (  m_is_data
//                             || m_event.getTruthSignChannel() == m_event.getSignChannel()
//                             );
//  m_pass_event = (m_pass_event && pass_no_charge_flip);
//  if (m_crit_cut_no_charge_flip && !pass_no_charge_flip) return;
//  if (m_pass_event) {
//    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_NO_CHARGE_FLIP);
//    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_NO_CHARGE_FLIP, m_event_weight);
//
//    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), ISR_CUT_NO_CHARGE_FLIP);
//    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), ISR_CUT_NO_CHARGE_FLIP, m_event_weight);
//  }
//
//  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  // emma mt cut
//  // TODO validate emma mt cut
//  bool pass_emma_mt = ( PennSusyFrame::passCut( m_event_quantities.getEmmaMt()
//                                              , m_emma_mt_min
//                                              , m_emma_mt_max
//                                              )
//                      );
//  m_pass_event = (m_pass_event && pass_emma_mt);
//  if (m_crit_cut_emma_mt && !pass_emma_mt) return;
//  if (m_pass_event) {
//    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_EMMA_MT);
//    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_EMMA_MT, m_event_weight);
//
//    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), ISR_CUT_EMMA_MT);
//    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), ISR_CUT_EMMA_MT, m_event_weight);
//  }
//
//  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  // met rel cut
//  // TODO validate met-rel cut
//  bool pass_met_rel = ( PennSusyFrame::passCut( m_met.getMetRel()
//                                              , m_met_rel_min
//                                              , m_met_rel_max
//                                              )
//                      );
//  m_pass_event = (m_pass_event && pass_met_rel);
//  if (m_crit_cut_met_rel && !pass_met_rel) return;
//  if (m_pass_event) {
//    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_MET_REL);
//    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_MET_REL, m_event_weight);
//
//    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), ISR_CUT_MET_REL);
//    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), ISR_CUT_MET_REL, m_event_weight);
//  }
//
//  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  // dphi_ll cut
//  // TODO validate dphill cut
//  bool pass_dphi_ll = ( PennSusyFrame::passCut( m_event_quantities.getDphill()
//                                              , m_dphi_ll_min
//                                              , m_dphi_ll_max
//                                              )
//                      );
//  m_pass_event = (m_pass_event && pass_dphi_ll);
//  if (m_crit_cut_dphi_ll && !pass_dphi_ll) return;
//  if (m_pass_event) {
//    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_DPHI_LL);
//    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_DPHI_LL, m_event_weight);
//
//    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), ISR_CUT_DPHI_LL);
//    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), ISR_CUT_DPHI_LL, m_event_weight);
//  }
//
//  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  // b jet veto
//  // TODO validate b veto cut
//  bool pass_b_veto = (m_jets.num(JET_B) == 0);
//  m_pass_event = (m_pass_event && pass_b_veto);
//  if (m_crit_cut_b_veto && !pass_b_veto) return;
//  if (m_pass_event) {
//    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_B_VETO);
//    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_B_VETO, m_event_weight);
//
//    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), ISR_CUT_B_VETO);
//    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), ISR_CUT_B_VETO, m_event_weight);
//  }
//
//  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  // b tag sf
//  // TODO validate b tag SF
//  m_event_weight *= m_event_quantities.getBTagSF();
//  if (m_pass_event) {
//    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_B_TAG_SF);
//    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_B_TAG_SF, m_event_weight);
//
//    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), ISR_CUT_B_TAG_SF);
//    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), ISR_CUT_B_TAG_SF, m_event_weight);
//  }
//
//  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  // # light jet cut
//  // TODO validate light jet cut
//  bool pass_num_jet = ( PennSusyFrame::passCut( static_cast<int>(m_jets.num(JET_LIGHT))
//                                              , m_num_light_jets_min
//                                              , m_num_light_jets_max
//                                              )
//                      );
//  m_pass_event = (m_pass_event && pass_num_jet);
//  if (m_crit_cut_num_jet && !pass_num_jet) return;
//  if (m_pass_event) {
//    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, ISR_CUT_NUM_JET);
//    m_cutflow_tracker.fillHist(    FLAVOR_NONE, ISR_CUT_NUM_JET, m_event_weight);
//
//    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), ISR_CUT_NUM_JET);
//    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), ISR_CUT_NUM_JET, m_event_weight);
//  }
//
//  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  // get charge flip weight
//  // TODO move this to more sensible location
//  m_event_quantities.setCFWeight(m_charge_flip_tool.getSF( m_event.getFlavorChannel()
//                                                         , m_electrons.getCollection(EL_GOOD)
//                                                         , m_muons.getCollection(MU_GOOD)
//                                                         )
//                                );
//
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
}

// -----------------------------------------------------------------------------
void PennSusyFrame::IsrAnalysis::finalizeEvent()
{
  // fillTnt();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::IsrAnalysis::finalizeRun()
{
  std::cout<< "IsrAnalysis::finalizeRun()\n";
  std::cout<< "creating output histogram file\n";
  TFile out_hist_file(m_out_hist_file_name.c_str(), "RECREATE");

  m_d3pd_reader->writeNumEvents();


  std::cout << "about to write histograms to file\n";
  for ( unsigned int hist_level = 0
	  ; hist_level != ISR_HIST_N
	  ; ++hist_level
	) {
    TDirectory* hist_dir_cut_level = out_hist_file.mkdir(PennSusyFrame::ISR_HIST_LEVEL_STRINGS[hist_level].c_str());
    
    size_t num_hists = m_histogram_handlers.at(hist_level).size();
    for (size_t hist_it = 0; hist_it != num_hists; ++hist_it) {
      std::cout << "\twriting histogram handler " << hist_it << " to file\n";
      m_histogram_handlers.at(hist_level).at(hist_it)->write(hist_dir_cut_level);
    }
    
    //m_isr_histogram_handler.at(hist_level)->write(hist_dir_cut_level);
  }
  std::cout << "done writing histograms to file\n";

  out_hist_file.Close();
  std::cout << "file is closed!\n";


  m_raw_cutflow_tracker.printToScreen();
  m_cutflow_tracker.printToScreen();

  // writeTnt();
}
// -----------------------------------------------------------------------------
void PennSusyFrame::IsrAnalysis::fillHistHandles( PennSusyFrame::ISR_HIST_LEVELS hist_level
						  , float weight
                                                  )
{
  size_t num_hists = m_histogram_handlers.at(hist_level).size();
  for (size_t hist_it = 0; hist_it != num_hists; ++hist_it) {
    m_histogram_handlers.at(hist_level).at(hist_it)->Fill( m_event
                                                         , m_event_quantities
                                                         , m_electrons.getCollection(EL_GOOD)
                                                         , m_muons.getCollection(MU_GOOD)
                                                         , m_jets.getCollection(JET_GOOD)
                                                         , m_met
                                                         , weight
                                                         );
  }
// m_isr_histogram_handler.at(hist_level)->FillSpecial( m_event
//                                                        , m_jets.getCollection(JET_B)
//                                                        , bl_0
//                                                        , bl_1
//                                                        , m_mc_truth
//                                                        , weight
//                                                        );
}
