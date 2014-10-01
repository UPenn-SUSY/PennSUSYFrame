#include "EwkAnalysis/include/EwkAnalysis.h"
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
PennSusyFrame::EwkAnalysis::EwkAnalysis(TTree* tree) : PennSusyFrame::PennSusyFrameCore(tree)
                                                     , m_out_hist_file_name("EwkHist.root")
                                                     , m_crit_cut_grl(false)
                                                     , m_crit_cut_incomplete_event(false)
                                                     , m_crit_cut_lar_error(false)
                                                     , m_crit_cut_tile_error(false)
                                                     , m_crit_cut_tile_hot_spot(false)
                                                     , m_crit_cut_tile_trip(false)
                                                     , m_crit_cut_bad_jet_veto(false)
                                                     , m_crit_cut_calo_problem_jet(false)
						     , m_crit_cut_bch_cleaning(false)
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
						     , m_crit_cut_pt_ll(false)
						     , m_crit_cut_ht(false)
						     , m_crit_cut_mll(false)
						     , m_crit_cut_mt2(false)
						     , m_do_fake_est(false)
                                                     , m_do_fake_cr(false)  
                                                     , m_do_cf_est(false)  
                                                     , m_print_event_details(false)  
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
						     , m_pt_ll_min(-1)
						     , m_pt_ll_max(-1)
						     , m_ht_min(-1)
						     , m_ht_max(-1)
						     , m_mll_min(-1)
						     , m_mll_max(-1)
						     , m_mt2_min(-1)
						     , m_mt2_max(-1)
                                                     , m_bdt_score(-999.)  
                                                       
						     
{
  // set defaults
  setSFOSMllCut(20.e3, -1);
  setEmmaMtCut(-1, 50.e3);
  setMetRelCut(60.e3, -1);
  setDphillCut(1.3, -1);
  setNumLightJetsCut(1, -1);
  setMt2Cut(-1, 35e3);
  setPtllCut(-1, 25e3);
  setMllCut(-1, 75e3);
  setHtCut(-1, 65e3);
  

}

// -----------------------------------------------------------------------------
PennSusyFrame::EwkAnalysis::~EwkAnalysis()
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::EwkAnalysis::prepareTools()
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
  m_bch_cleaning_tool.init(m_event, m_tile_trip_tool);

  m_tmva_reader.AddVariable("Mll", &m_tmva_mll);
  m_tmva_reader.AddVariable("METrel", &m_tmva_met_rel);
  m_tmva_reader.AddVariable("DphiLL", &m_tmva_dphi_ll);
  m_tmva_reader.AddVariable("Ht", &m_tmva_ht);
  m_tmva_reader.AddVariable("MT2", &m_tmva_mt2);
  m_tmva_reader.AddVariable("Mtr1", &m_tmva_mtr1);
  m_tmva_reader.AddVariable("Mtr2", &m_tmva_mtr2);
  m_tmva_reader.AddVariable("pTll", &m_tmva_pt_ll);
  m_tmva_reader.AddVariable("METpTjet", &m_tmva_met_pt_jet);
  m_tmva_reader.AddVariable("PtLepJet", &m_tmva_pt_lep_jet);
  m_tmva_reader.AddVariable("DphiMETjet", &m_tmva_dphi_met_jet);

  std::string tmvaWeightFile = base_dir + "/data/BDT/TMVAClassification_BDTD.weights_dM20_ISR.xml";
  m_tmva_reader.BookMVA("BDTD method for this signal", tmvaWeightFile);
}
// -----------------------------------------------------------------------------
void PennSusyFrame::EwkAnalysis::prepareSelection()
{
  PennSusyFrameCore::prepareSelection();

  m_electron_selectors.at(EL_BASELINE).setPtCut(10.e3, -1);
  m_electron_selectors.at(EL_BASELINE).setEtaCut(-2.47, 2.47);
  m_electron_selectors.at(EL_BASELINE).setElectronQuality(EL_QUALITY_MEDPP);

  m_electron_selectors.at(EL_SIGNAL).setPtIsoCut(-1,0.07);
  m_electron_selectors.at(EL_SIGNAL).setEtIsoCut(-1,0.13);
  m_electron_selectors.at(EL_SIGNAL).setD0SignificanceCut(-1,3);
  m_electron_selectors.at(EL_SIGNAL).setZ0SignThetaCut(-1, 0.4);
  m_electron_selectors.at(EL_SIGNAL).setElectronQuality(EL_QUALITY_TIGHTPP);
  //  m_electron_selectors.at(EL_SIGNAL).

  m_muon_selectors.at(MU_BASELINE).setPtCut(10.e3, -1);


  m_muon_selectors.at(MU_SIGNAL).setPtIsoCut(-1,0.06);
  m_muon_selectors.at(MU_SIGNAL).setEtIsoCut(-1, 0.14);
  m_muon_selectors.at(MU_SIGNAL).setD0SignificanceCut(-1, 3.);
  m_muon_selectors.at(MU_SIGNAL).setZ0SignThetaCut(-1, 1.);


  m_muon_selectors.at(MU_BASELINE).setEtaCut(-1, 2.4);

  m_jet_selectors.at(JET_B).setMV1Cut(0.3511,-1);
  m_jet_selectors.at(JET_B).setEtaCut(-1,2.4);
  m_jet_selectors.at(JET_B).setConstScaleEtaCut(-1,-1);

  m_object_cleaning.setEEConeSize(0.05); 
  m_object_cleaning.setEJConeSize(0.2); 
  m_object_cleaning.setMJConeSize(0.0); 
  m_object_cleaning.setETConeSize(0.2); 
  m_object_cleaning.setMTConeSize(0.2); 
  m_object_cleaning.setJEConeSize(0.4); 
  m_object_cleaning.setJMConeSize(0.4); 
  m_object_cleaning.setEMConeSize(0.01); 
  m_object_cleaning.setMMConeSize(0.05); 
  m_object_cleaning.setTJConeSize(0.2); 
  m_object_cleaning.setSFOSMllMin(12.e3);




  std::cout << "preparing selection\n";


}
// -----------------------------------------------------------------------------
void PennSusyFrame::EwkAnalysis::beginRun()
{

  PennSusyFrameCore::beginRun();

  prepareSelection();
  //std::cout<<"size to resize to: "<<EWK_HIST_N<<std::endl;
  m_histogram_handlers.resize(EWK_HIST_N);
    
  for (unsigned int hist_level = 0; hist_level != EWK_HIST_N; ++hist_level) {
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::EventLevelHists(      PennSusyFrame::EWK_HIST_LEVEL_STRINGS[hist_level]) );
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::LeptonKinematicsHists(PennSusyFrame::EWK_HIST_LEVEL_STRINGS[hist_level]) );
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::JetKinematicsHists(   PennSusyFrame::EWK_HIST_LEVEL_STRINGS[hist_level]) );
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::MetHists(             PennSusyFrame::EWK_HIST_LEVEL_STRINGS[hist_level]) );
    
    m_ewk_histogram_handler.push_back(new PennSusyFrame::EwkHists(PennSusyFrame::EWK_HIST_LEVEL_STRINGS[hist_level]));
  }


  // configureTnt(m_out_tnt_file_name, "TNT");
}

// -----------------------------------------------------------------------------
void PennSusyFrame::EwkAnalysis::processEvent()
{
  m_event_weight = 1.;
  m_bdt_score = -999;

  m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_ALL);
  m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_ALL, m_event_weight);

  if(m_print_event_details){
    printEventDetails();
      }


  doBaselineCuts();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get BDT score
  // TODO validate BDT Score
  

  //For now only eval BDT if passes selection up to here.

  if (m_pass_event)    {
    m_tmva_mll = m_event_quantities.getMll();
    m_tmva_met_rel = m_met.getMetRel();
    m_tmva_dphi_ll = m_event_quantities.getDphill();
    m_tmva_ht = m_event_quantities.getHtSignal();
    m_tmva_mt2 = m_event_quantities.getMt2();
    m_tmva_pt_ll = m_event_quantities.getPtll();
    m_tmva_mtr1 = PennSusyFrame::getLeadingMt(m_event.getFlavorChannel()
                               , m_electrons.getCollection(EL_SIGNAL)
                               , m_muons.getCollection(MU_SIGNAL)
                               , &m_met);
    m_tmva_mtr2 = PennSusyFrame::getSubleadingMt(m_event.getFlavorChannel()
                                  , m_electrons.getCollection(EL_SIGNAL)
                                  , m_muons.getCollection(MU_SIGNAL)
                                  , &m_met);
    bool is_isr = true;
    if (is_isr)
      {
        m_tmva_met_pt_jet = m_met.getMetEt()/(m_jets.getCollection(JET_ALL_SIGNAL)->at(0)->getPt());
        m_tmva_pt_lep_jet = PennSusyFrame::getPtRatioLepJet( m_event.getFlavorChannel()
                                                             , m_electrons.getCollection(EL_SIGNAL)
                                                             , m_muons.getCollection(MU_SIGNAL)
                                                             , m_jets.getCollection(JET_ALL_SIGNAL)
                                                             );
        m_tmva_dphi_met_jet = m_met.getDPhi(m_jets.getCollection(JET_ALL_SIGNAL)->at(0));
      }
    m_bdt_score = m_tmva_reader.EvaluateMVA("BDTD method for this signal");
    //    std::cout<<"BDT score: "<<m_bdt_score<<std::endl;
  }

  if(m_do_fake_cr) doFakeCR();

  doSignalLeptonCuts();


  //Signal Region Stuff from Here down:

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // check for SS leptons
  // TODO validate SS leptons requirement
  bool pass_ss = (m_event.getSignChannel() == SIGN_SS);
  m_pass_event = (m_pass_event && pass_ss);
  if (m_crit_cut_ss && !pass_ss) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_SS);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_SS, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_SS);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_SS, m_event_weight);
  }

  // fill histograms for 2 SS lep hist level
  if (m_pass_event) {
    fillHistHandles( PennSusyFrame::EWK_HIST_2SS_SIG_LEP
		     , m_event_weight
		     );
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // # light jet cut
  // TODO validate light jet cut
  bool pass_num_jet = ( PennSusyFrame::passCut( static_cast<int>(m_jets.num(JET_LIGHT)+static_cast<int>(m_jets.num(JET_FORWARD))+static_cast<int>(m_jets.num(JET_B)) )
                                              , m_num_light_jets_min
                                              , m_num_light_jets_max
						, true	
                                              )
                      );
  m_pass_event = (m_pass_event && pass_num_jet);
  if (m_crit_cut_num_jet && !pass_num_jet) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_NUM_JET);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_NUM_JET, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_NUM_JET);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_NUM_JET, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // b jet veto

  // TODO validate b veto cut
  bool pass_b_veto = (m_jets.num(JET_B) == 0);
  m_pass_event = (m_pass_event && pass_b_veto);
  if (m_crit_cut_b_veto && !pass_b_veto) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_B_VETO);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_B_VETO, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_B_VETO);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_B_VETO, m_event_weight);
  }

  // fill histograms for 2 SS lep hist level
  if (m_pass_event) {
    fillHistHandles( PennSusyFrame::EWK_HIST_1_LIGHT_JET
		     , m_event_weight
		     );
  }


  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get charge flip weight
  // TODO move this to more sensible location
  m_event_quantities.setCFWeight(m_charge_flip_tool.getSF( m_event.getFlavorChannel()
                                                         , m_electrons.getCollection(EL_GOOD)
                                                         , m_muons.getCollection(MU_GOOD)
                                                         )
                                );

  if (m_do_cf_est) m_event_weight *= m_event_quantities.getCFWeight();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // pt_ll cut
  // TODO validate ptll cut
  bool pass_pt_ll = ( PennSusyFrame::passCut( m_event_quantities.getPtll()
                                              , m_pt_ll_min
                                              , m_pt_ll_max
                                              )
                      );
  m_pass_event = (m_pass_event && pass_pt_ll);
  if (m_crit_cut_pt_ll && !pass_pt_ll) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_PT_LL);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_PT_LL, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_PT_LL);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_PT_LL, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // ht cut
  // TODO validate ht cut
  bool pass_ht = ( PennSusyFrame::passCut( m_event_quantities.getHtSignal()
                                              , m_ht_min
                                              , m_ht_max
                                              )
                      );
  m_pass_event = (m_pass_event && pass_ht);
  if (m_crit_cut_ht && !pass_ht) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_HT);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_HT, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_HT);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_HT, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // mll cut
  // TODO validate ptll cut
  bool pass_mll = ( PennSusyFrame::passCut( m_event_quantities.getMll()
                                              , m_mll_min
                                              , m_mll_max
                                              )
                      );
  m_pass_event = (m_pass_event && pass_mll);
  if (m_crit_cut_mll && !pass_mll) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_MLL);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_MLL, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_MLL);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_MLL, m_event_weight);
  }




  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // mt2 cut
  // TODO validate mt2 cut
  bool pass_mt2 = ( PennSusyFrame::passCut( m_event_quantities.getMt2()
                                              , m_mt2_min
                                              , m_mt2_max
                                              )
                      );
  m_pass_event = (m_pass_event && pass_mt2);
  if (m_crit_cut_mt2 && !pass_mt2) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_MT2);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_MT2, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_MT2);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_MT2, m_event_weight);
  }




  //Print detailed Event Quantites 

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

void PennSusyFrame::EwkAnalysis::doBaselineCuts()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set mc event weight
  // TODO validate MC event weight
  m_event_weight *= m_event_quantities.getMcEventWeight();
  m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_MC_EVENT_WEIGHT);
  m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_MC_EVENT_WEIGHT, m_event_weight);
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set pile up weight
  // TODO validate pile up weight
  m_event_weight *= m_event_quantities.getPileUpSF();
  m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_PILEUP_WEIGHT);
  m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_PILEUP_WEIGHT, m_event_weight);
  
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
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_GRL);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_GRL, m_event_weight);
  }
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile trip cut
  // TODO validate tile trip cut
  bool pass_tile_trip = m_tile_trip_tool.passTileTrip(m_event);
  m_pass_event = (m_pass_event && pass_tile_trip);
  if (m_crit_cut_tile_trip && !pass_tile_trip) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_TILE_TRIP);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_TILE_TRIP, m_event_weight);
  }
  
	
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // incomplete event cut
  // TODO validate incomplete event cut
  bool pass_incomplete_event = PennSusyFrame::passIncompleteEvent(m_event);
  m_pass_event = (m_pass_event && pass_incomplete_event);
  if (m_crit_cut_incomplete_event && !pass_incomplete_event) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_INCOMPLETE_EVENT);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_INCOMPLETE_EVENT, m_event_weight);
  }
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // LAr error cut
  // TODO validate LAr error cut
  bool pass_lar_error = PennSusyFrame::passLarError(m_event);
  m_pass_event = (m_pass_event && pass_lar_error);
  if (m_crit_cut_lar_error && !pass_lar_error) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_LAR_ERROR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_LAR_ERROR, m_event_weight);
  }
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile error cut
  // TODO validate tile error cut
  bool pass_tile_error = PennSusyFrame::passTileError(m_event);
  m_pass_event = (m_pass_event && pass_tile_error);
  if (m_crit_cut_tile_error && !pass_tile_error) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_TILE_ERROR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_TILE_ERROR, m_event_weight);
  }
  
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // primary vertex cut
  bool pass_primary_vertex = PennSusyFrame::passPrimaryVertex(m_vertices);
  m_pass_event = (m_pass_event && pass_primary_vertex);
  if (m_crit_cut_primary_vertex && !pass_primary_vertex) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_PRIMARY_VERTEX);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_PRIMARY_VERTEX, m_event_weight);
  }
	
	
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile hot spot cut
  // TODO validate tile hot spot cut
  bool pass_tile_hot_spot = PennSusyFrame::TileHotSpotTool::passTileHotSpot(m_event, m_jets);
  m_pass_event = (m_pass_event && pass_tile_hot_spot);
  if (m_crit_cut_tile_hot_spot && !pass_tile_hot_spot) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_TILE_HOT_SPOT);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_TILE_HOT_SPOT, m_event_weight);
  }
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // bad jet veto
  bool pass_bad_jet_veto = (m_jets.num(JET_BAD) == 0);
  m_pass_event = (m_pass_event && pass_bad_jet_veto);
  if (m_crit_cut_bad_jet_veto && !pass_bad_jet_veto) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_BAD_JET_VETO);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_BAD_JET_VETO, m_event_weight);
  }
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // calo problem jet cut
  bool pass_calo_problem_jet = (m_jets.num(JET_CALO_PROBLEM) == 0);
  m_pass_event = (m_pass_event && pass_calo_problem_jet);
  if (m_crit_cut_calo_problem_jet && !pass_calo_problem_jet) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_CALO_PROBLEM_JET);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_CALO_PROBLEM_JET, m_event_weight);
  }
  
  
  
  //generate random run number and lbn for BCH tool taken from SUSYTools
  
  int run_number = -999;
  int lumi_block = -999;
  
  int seed = -999;
  
  if (m_is_data)
    {
      run_number = m_event.getRunNumber();
      lumi_block = m_event.getLumiBlock();
    }
  else
    {                         
      //set the seed so that the bch cleaning random number is reproducible 
      seed = 314159+(m_event.getEventNumber())+2718*(m_mc_truth.getChannelNumber());
      m_pile_up_sf_tool.setRandomSeed(seed);
      
      run_number =  m_pile_up_sf_tool.getRandomRunNumber(m_event.getRunNumber(),m_event.getAverageIntPerXing());
      if (run_number>0) lumi_block =  m_pile_up_sf_tool.getRandomLumiBlockNumber(run_number);
    }	
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  //BCH Cleaning cut
  bool pass_bch_cleaning = (run_number>0 && m_bch_cleaning_tool.passBCHCleaning(m_jets, run_number, lumi_block));
  m_pass_event = (m_pass_event && pass_bch_cleaning);
  if (m_crit_cut_bch_cleaning && !pass_bch_cleaning) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_BCH_CLEANING);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_BCH_CLEANING, m_event_weight);
		
  }
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // bad muon cut
  bool pass_bad_mu_veto = (m_muons.num(MU_BAD) == 0);
  m_pass_event = (m_pass_event && pass_bad_mu_veto);
  if (m_crit_cut_bad_mu_veto && !pass_bad_mu_veto) return;
  if (m_pass_event) {
		m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_BAD_MUON);
		m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_BAD_MUON, m_event_weight);
  }
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // cosmic muon veto
  bool pass_cosmic_mu_veto = (m_muons.num(MU_COSMIC) == 0);
  m_pass_event = (m_pass_event && pass_cosmic_mu_veto);
  if (m_crit_cut_cosmic_mu_veto && !pass_cosmic_mu_veto) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_COSMIC_MUON_VETO);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_COSMIC_MUON_VETO, m_event_weight);
  }
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // HFOR cut
  // TODO validate HFOR cut
  bool pass_hfor = m_hfor_tool.passHFOR(m_mc_truth);
  m_pass_event = (m_pass_event && pass_hfor);
  if (m_crit_cut_hfor && !pass_hfor) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_HFOR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_HFOR, m_event_weight);
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
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_MC_OVERLAP);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_MC_OVERLAP, m_event_weight);
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
    
		
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_GE_2_BASELINE_LEPTONS);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_GE_2_BASELINE_LEPTONS, m_event_weight);
  }
  
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tau veto
  // TODO validate tau veto
  bool pass_tau_veto = (m_taus.num(TAU_SIGNAL) == 0);
  m_pass_event = (m_pass_event && pass_tau_veto);
  if (m_crit_cut_tau_veto && !pass_tau_veto) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_TAU_VETO);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_TAU_VETO, m_event_weight);
  }
  
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // == 2 baseline leptons cut
  bool pass_2_lep = (num_good_leptons == 2);
  m_pass_event = (m_pass_event && pass_2_lep);
  if (m_crit_cut_2_lep && !pass_2_lep) return;
  if (m_pass_event) {
    {
      
      m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_EQ_2_BASELINE_LEPTONS);
      m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_EQ_2_BASELINE_LEPTONS, m_event_weight);
      
      
      m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_EQ_2_BASELINE_LEPTONS);
      m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_EQ_2_BASELINE_LEPTONS, m_event_weight);
    }
  }
  
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get fake weight
  
  m_event_quantities.setFakeWeight(m_matrix_method_tool.getSF(m_event.getFlavorChannel()
                                                              , m_electrons.getCollection(EL_GOOD)
                                                              , m_muons.getCollection(MU_GOOD)
                                                              , m_met
                                                              )
                                   );
  
  
  //std::cout<<"Fake Weight: "<<m_event_quantities.getFakeWeight()<<std::endl;
  
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
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_MLL_SFOS);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_MLL_SFOS, m_event_weight);
    
    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_MLL_SFOS);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_MLL_SFOS, m_event_weight);
    
  }
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // phase space cut
  bool pass_phase_space = (m_event.getTriggerPhase() != TRIG_NONE);
  m_pass_event = (m_pass_event && pass_phase_space);
  if (m_crit_cut_phase_space && !pass_phase_space) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_PHASE_SPACE);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_PHASE_SPACE, m_event_weight);
    
    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_PHASE_SPACE);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_PHASE_SPACE, m_event_weight);
   
  }
  
  
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // TODO implement trigger SF
  m_event_weight *= m_event_quantities.getTriggerWeight();
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_TRIGGER_WEIGHT);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_TRIGGER_WEIGHT, m_event_weight);
    
    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_TRIGGER_WEIGHT);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_TRIGGER_WEIGHT, m_event_weight);
  }
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // lepton scale factor
  // TODO validate lepton sf
  m_event_weight *= m_event_quantities.getLeptonSF();
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_LEP_SF);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_LEP_SF, m_event_weight);
    
    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_LEP_SF);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_LEP_SF, m_event_weight);
  }
  
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // b tag sf
	// TODO validate b tag SF
  m_event_weight *= m_event_quantities.getBTagSF();
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_B_TAG_SF);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_B_TAG_SF, m_event_weight);
    
    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_B_TAG_SF);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_B_TAG_SF, m_event_weight);
  }
	
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // x sec sf
  // TODO validate x sec SF
  float target_lumi = 20281.4; // in pb-1
  
  m_event_weight *= m_xsec_weight;
  m_event_weight *= target_lumi;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_X_SEC_SF);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_X_SEC_SF, m_event_weight);
    
    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_X_SEC_SF);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_X_SEC_SF, m_event_weight);
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
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_TRIGGER);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_TRIGGER, m_event_weight);
    
    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_TRIGGER);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_TRIGGER, m_event_weight);
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
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_TRIGGER_MATCHING);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_TRIGGER_MATCHING, m_event_weight);
    
    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_TRIGGER_MATCHING);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_TRIGGER_MATCHING, m_event_weight);
  }
  
}
// -----------------------------------------------------------------------------
void PennSusyFrame::EwkAnalysis::doSignalLeptonCuts()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // check for prompt leptons
  // TODO validate check for prompt leptons
  bool pass_prompt_leptons = (m_is_data || m_event.getPromptLeptons());
  m_pass_event = (m_pass_event && pass_prompt_leptons);
  if (m_crit_cut_prompt_leptons && !pass_prompt_leptons) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_PROMPT_LEP);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_PROMPT_LEP, m_event_weight);
    
    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_PROMPT_LEP);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_PROMPT_LEP, m_event_weight);
  }
  
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // require no charge flip
  // TODO validate no charge flip cut
  bool pass_no_charge_flip = (  m_is_data
                                || m_event.getTruthSignChannel() == m_event.getSignChannel()
                                );
  m_pass_event = (m_pass_event && pass_no_charge_flip);
  if (m_crit_cut_no_charge_flip && !pass_no_charge_flip) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_NO_CHARGE_FLIP);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_NO_CHARGE_FLIP, m_event_weight);
    
    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_NO_CHARGE_FLIP);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_NO_CHARGE_FLIP, m_event_weight);
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
    

    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_EQ_2_SIGNAL_LEPTON);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_EQ_2_SIGNAL_LEPTON, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_EQ_2_SIGNAL_LEPTON);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_EQ_2_SIGNAL_LEPTON, m_event_weight);
    
  }

}
// -----------------------------------------------------------------------------	
void PennSusyFrame::EwkAnalysis::doFakeCR()
{
  
  double event_fake_weight = m_event_weight * m_event_quantities.getFakeWeight();
  
  bool pass_fake_cr = m_pass_event;
  
  // Define Fake control regions
  
//  //  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  // met rel cut
//  // Reverse Cut
//  bool pass_met_rel = !( PennSusyFrame::passCut( m_met.getMetRel()
//                                                 , m_met_rel_min
//                                                 , m_met_rel_max
//                                                 )
//                         );
//  pass_fake_cr = (pass_fake_cr && pass_met_rel);
//  if (m_crit_cut_met_rel && !pass_met_rel) return;
//  if (pass_fake_cr) {
//   // m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_MET_REL);
//   // m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_MET_REL, m_event_weight);
//   // 
//   // m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_MET_REL);
//   // m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_MET_REL, m_event_weight);
//  }
//  
//  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  // dphi_ll cut
//  // TODO validate dphill cut
//  bool pass_dphi_ll = ( PennSusyFrame::passCut( m_event_quantities.getDphill()
//                                                , m_dphi_ll_min
//                                                , m_dphi_ll_max
//                                                )
//                        );
//  pass_fake_cr = (pass_fake_cr && pass_dphi_ll);
//  if (m_crit_cut_dphi_ll && !pass_dphi_ll) return;
//  if (pass_fake_cr) {
//   // m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_DPHI_LL);
//   // m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_DPHI_LL, m_event_weight);
//   // 
//   // m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_DPHI_LL);
//   // m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_DPHI_LL, m_event_weight);
//		}
//  
  
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // # light jet cut
  // TODO validate light jet cut
  bool pass_num_jet = ( PennSusyFrame::passCut( static_cast<int>(m_jets.num(JET_LIGHT)+static_cast<int>(m_jets.num(JET_FORWARD))+static_cast<int>(m_jets.num(JET_B)) )
                                                , m_num_light_jets_min
                                                , m_num_light_jets_max
                                                , true	
                                                )
                        );
  pass_fake_cr = (pass_fake_cr && pass_num_jet);
  if (m_crit_cut_num_jet && !pass_num_jet) return;
  if (pass_fake_cr) {
   // m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_NUM_JET);
   // m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_NUM_JET, m_event_weight);
   // 
   // m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_NUM_JET);
   // m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_NUM_JET, m_event_weight);
  }
  
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // b jet veto
  
  // TODO validate b veto cut
  bool pass_b_veto = (m_jets.num(JET_B) == 0);
  pass_fake_cr = (pass_fake_cr && pass_b_veto);
  if (m_crit_cut_b_veto && !pass_b_veto) return;
  if (pass_fake_cr) {
  //  m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_B_VETO);
  //  m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_B_VETO, m_event_weight);
  //  
  //  m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_B_VETO);
  //  m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_B_VETO, m_event_weight);
  }
  

  // ----------------------------------------------------------------------------
  // cut on the BDT

  float bdt_score_min = -999;
  float bdt_score_max = -0.1;

  bool pass_bdt_fake_cr = (PennSusyFrame::passCut(m_bdt_score,
                                                  bdt_score_min,
                                                  bdt_score_max
                                                  ));
  pass_fake_cr = (pass_fake_cr && pass_bdt_fake_cr);
                                    
  if (pass_fake_cr)  fillHistHandles( PennSusyFrame::EWK_HIST_FAKE_CR, event_fake_weight);
  
  return;
}

//End fake control region

// -----------------------------------------------------------------------------
void PennSusyFrame::EwkAnalysis::finalizeEvent()
{
  // fillTnt();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::EwkAnalysis::finalizeRun()
{
  std::cout<< "EwkAnalysis::finalizeRun()\n";
  std::cout<< "creating output histogram file\n";
  TFile out_hist_file(m_out_hist_file_name.c_str(), "RECREATE");

  m_d3pd_reader->writeNumEvents();


  std::cout << "about to write histograms to file\n";
  for ( unsigned int hist_level = 0
	  ; hist_level != EWK_HIST_N
	  ; ++hist_level
	) {
    TDirectory* hist_dir_cut_level = out_hist_file.mkdir(PennSusyFrame::EWK_HIST_LEVEL_STRINGS[hist_level].c_str());
    
    size_t num_hists = m_histogram_handlers.at(hist_level).size();
    for (size_t hist_it = 0; hist_it != num_hists; ++hist_it) {
      std::cout << "\twriting histogram handler " << hist_it << " to file\n";
      m_histogram_handlers.at(hist_level).at(hist_it)->write(hist_dir_cut_level);
    }
    
    m_ewk_histogram_handler.at(hist_level)->write(hist_dir_cut_level);
  }
  std::cout << "done writing histograms to file\n";

  out_hist_file.Close();
  std::cout << "file is closed!\n";


  m_raw_cutflow_tracker.printToScreen();
  m_cutflow_tracker.printToScreen();

  // writeTnt();
}
// -----------------------------------------------------------------------------
void PennSusyFrame::EwkAnalysis::fillHistHandles( PennSusyFrame::EWK_HIST_LEVELS hist_level
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
// m_ewk_histogram_handler.at(hist_level)->FillSpecial( m_event
//                                                        , m_jets.getCollection(JET_B)
//                                                        , bl_0
//                                                        , bl_1
//                                                        , m_mc_truth
//                                                        , weight
//                                                        );

  m_ewk_histogram_handler.at(hist_level)->FillBDT(m_event, m_bdt_score, weight);
}
// -----------------------------------------------------------------------------
void PennSusyFrame::EwkAnalysis::printEventDetails()
{
  m_event.print();
  m_event_quantities.print();
  std::cout<<"xsec: "<<m_x_sec<<" kfactor: "<<m_k_factor<<" x_sec_weight: "<<m_xsec_weight<<std::endl;
  //  m_vertices.print(VERTEX_ALL);
  //  m_vertices.print(VERTEX_GT_2);
  //  
  
  m_electrons.print(EL_ALL);
  m_muons.print(MU_ALL);
  m_jets.print(JET_ALL);
  m_met.print();
  m_taus.print(TAU_ALL);
  
  m_electrons.print(EL_BASELINE);
  m_muons.print(MU_BASELINE);
  m_jets.print(JET_BASELINE);
  
  m_electrons.print(EL_GOOD);
  m_muons.print(MU_GOOD);
  m_jets.print(JET_GOOD);
  m_taus.print(TAU_GOOD);
  
  m_electrons.print(EL_SIGNAL);
  m_muons.print(MU_SIGNAL);
  m_jets.print(JET_ALL_SIGNAL);
  m_taus.print(TAU_SIGNAL);
  
  
}
