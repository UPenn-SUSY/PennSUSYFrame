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
                                                     , m_do_isr_sr(true)
                                                     , m_do_noisr_sr(true)  
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
                                                     , m_bdt_score_m20isr(-999.)  
                                                     , m_bdt_score_m20noisr(-999.)  
                                                     , m_bdt_score_m35isr(-999.)  
                                                     , m_bdt_score_m35noisr(-999.)  
                                                     , m_bdt_score_m65isr(-999.)  
                                                     , m_bdt_score_m65noisr(-999.)  
                                                     , m_bdt_score_m100isr(-999.)  
                                                     , m_bdt_score_m100noisr(-999.)  
                                                       
						     
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

  m_tmva_reader_isr.AddVariable("Mll", &m_tmva_mll);
  m_tmva_reader_isr.AddVariable("METrel", &m_tmva_met_rel);
  m_tmva_reader_isr.AddVariable("DphiLL", &m_tmva_dphi_ll);
  m_tmva_reader_isr.AddVariable("Ht", &m_tmva_ht);
  m_tmva_reader_isr.AddVariable("MT2", &m_tmva_mt2);
  m_tmva_reader_isr.AddVariable("Mtr1", &m_tmva_mtr1);
  m_tmva_reader_isr.AddVariable("Mtr2", &m_tmva_mtr2);
  m_tmva_reader_isr.AddVariable("pTll", &m_tmva_pt_ll);
  m_tmva_reader_isr.AddVariable("METpTjet", &m_tmva_met_pt_jet);
  m_tmva_reader_isr.AddVariable("PtLepJet", &m_tmva_pt_lep_jet);
  m_tmva_reader_isr.AddVariable("DphiMETjet", &m_tmva_dphi_met_jet);

  m_tmva_reader_noisr.AddVariable("Mll", &m_tmva_mll);
  m_tmva_reader_noisr.AddVariable("METrel", &m_tmva_met_rel);
  m_tmva_reader_noisr.AddVariable("DphiLL", &m_tmva_dphi_ll);
  m_tmva_reader_noisr.AddVariable("Ht", &m_tmva_ht);
  m_tmva_reader_noisr.AddVariable("MT2", &m_tmva_mt2);
  m_tmva_reader_noisr.AddVariable("Mtr1", &m_tmva_mtr1);
  m_tmva_reader_noisr.AddVariable("Mtr2", &m_tmva_mtr2);
  m_tmva_reader_noisr.AddVariable("pTll", &m_tmva_pt_ll);


  std::string tmvaWeightFile_m20_isr = base_dir + "/data/BDT/TMVAClassification_BDTD.weights_dM20ISR.xml";
  std::string tmvaWeightFile_m20_noisr = base_dir + "/data/BDT/TMVAClassification_BDTD.weights_dM20noISR.xml";
  std::string tmvaWeightFile_m35_isr = base_dir + "/data/BDT/TMVAClassification_BDTD.weights_dM35ISR.xml";
  std::string tmvaWeightFile_m35_noisr = base_dir + "/data/BDT/TMVAClassification_BDTD.weights_dM35noISR.xml";
  std::string tmvaWeightFile_m65_isr = base_dir + "/data/BDT/TMVAClassification_BDTD.weights_dM65ISR.xml";
  std::string tmvaWeightFile_m65_noisr = base_dir + "/data/BDT/TMVAClassification_BDTD.weights_dM65noISR.xml";
  std::string tmvaWeightFile_m100_isr = base_dir + "/data/BDT/TMVAClassification_BDTD.weights_dM100ISR.xml";
  std::string tmvaWeightFile_m100_noisr = base_dir + "/data/BDT/TMVAClassification_BDTD.weights_dM100noISR.xml";


  m_tmva_reader_isr.BookMVA("m20_isr signal", tmvaWeightFile_m20_isr);
  m_tmva_reader_isr.BookMVA("m35_isr signal", tmvaWeightFile_m35_isr);
  m_tmva_reader_isr.BookMVA("m65_isr signal", tmvaWeightFile_m65_isr);
  m_tmva_reader_isr.BookMVA("m100_isr signal", tmvaWeightFile_m100_isr);
 
  m_tmva_reader_noisr.BookMVA("m20_noisr signal", tmvaWeightFile_m20_noisr);
  m_tmva_reader_noisr.BookMVA("m35_noisr signal", tmvaWeightFile_m35_noisr);
  m_tmva_reader_noisr.BookMVA("m65_noisr signal", tmvaWeightFile_m65_noisr);
  m_tmva_reader_noisr.BookMVA("m100_noisr signal", tmvaWeightFile_m100_noisr);

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
  //  m_electron_selectors.at(EL_SIGNAL).setPtIsoCut(-1,0.05);
  //m_electron_selectors.at(EL_SIGNAL).setEtIsoCut(-1,0.11);
  m_electron_selectors.at(EL_SIGNAL).setD0SignificanceCut(-1,3);
  m_electron_selectors.at(EL_SIGNAL).setZ0SignThetaCut(-1, 0.4);
  m_electron_selectors.at(EL_SIGNAL).setElectronQuality(EL_QUALITY_TIGHTPP);
  //  m_electron_selectors.at(EL_SIGNAL).

  m_muon_selectors.at(MU_BASELINE).setPtCut(10.e3, -1);


  m_muon_selectors.at(MU_SIGNAL).setPtIsoCut(-1,0.06);
  m_muon_selectors.at(MU_SIGNAL).setEtIsoCut(-1, 0.14);
//  m_muon_selectors.at(MU_SIGNAL).setPtIsoCut(-1,0.05);
  //m_muon_selectors.at(MU_SIGNAL).setEtIsoCut(-1, 0.11);


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

  m_bdt_score_m20isr = -999;
  m_bdt_score_m20noisr = -999;
  m_bdt_score_m35isr = -999;
  m_bdt_score_m35noisr = -999;
  m_bdt_score_m65isr = -999;
  m_bdt_score_m65noisr = -999;
  m_bdt_score_m100isr = -999;
  m_bdt_score_m100noisr = -999;

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

  if (m_pass_event)  getBDTScores();

  // Make the Z veto for EE
  bool pass_z_veto =(m_event.getFlavorChannel() != FLAVOR_EE) || ((m_event_quantities.getMll() < 75.e3)  
								  || (m_event_quantities.getMll() > 100.e3) );

  // passes if not ee channel or if ee channel if not in z window
  m_pass_event = m_pass_event && pass_z_veto;

  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_EE_Z_VETO);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_EE_Z_VETO, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_EE_Z_VETO);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_EE_Z_VETO, m_event_weight);
  }
 

  if(m_do_fake_cr) doFakeCR();

  if(!m_do_fake_est) doSignalLeptonCuts();
  else m_event_weight *= m_event_quantities.getFakeWeight(); 

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get charge flip weight
  // TODO move this to more sensible location
  m_event_quantities.setCFWeight(m_charge_flip_tool.getSF( m_event.getFlavorChannel()
                                                           , m_electrons.getCollection(EL_GOOD)
                                                           , m_muons.getCollection(MU_GOOD)
                                                           )
                                 );
  
  if (m_do_cf_est) m_event_weight *= m_event_quantities.getCFWeight();
  //std::cout<<"flavor channel: "<<m_event.getFlavorChannel()<<" cf: "<<m_event_quantities.getCFWeight()<<std::endl;;
  
  //Signal Region Stuff from Here down:

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // check for SS leptons
  // TODO validate SS leptons requirement

  bool pass_ss  = true;

  if (!m_do_cf_est){ //we'll use weighted OS for CF
    pass_ss = (m_event.getSignChannel() == SIGN_SS);
  }
  else{
    pass_ss = (m_event.getSignChannel() == SIGN_OS);
  }    
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

  doISRSR();
  doNoISRSR();
    

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
  float target_lumi = 1.;
  //float target_lumi = 20281.4; // in pb-1
  if(!m_is_data)
    {
      m_event_weight *= m_xsec_weight;
      m_event_weight *= target_lumi;
    }
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
void PennSusyFrame::EwkAnalysis::getBDTScores()
{
  //std::cout<<"ABOUT TO GET BDT SCORE"<<std::endl;
  m_tmva_mll = m_event_quantities.getMll()/1.e3;
  m_tmva_met_rel = m_met.getMetRel()/1.e3;
  m_tmva_dphi_ll = m_event_quantities.getDphill();
  m_tmva_ht = m_event_quantities.getHtSignal()/1.e3;
  m_tmva_mt2 = m_event_quantities.getMt2()/1.e3;
  m_tmva_pt_ll = m_event_quantities.getPtll()/1.e3;
  m_tmva_mtr1 = PennSusyFrame::getLeadingMt(m_event.getFlavorChannel()
                                            , m_electrons.getCollection(EL_SELECTED)
                                            , m_muons.getCollection(MU_SELECTED)
                                            , &m_met)/1.e3;
  m_tmva_mtr2 = PennSusyFrame::getSubleadingMt(m_event.getFlavorChannel()
                                               , m_electrons.getCollection(EL_SELECTED)
                                               , m_muons.getCollection(MU_SELECTED)
                                               , &m_met)/1.e3;
  bool is_isr = m_jets.getCollection(JET_ALL_SIGNAL)->size() > 0;
  if (is_isr)
    {
      m_tmva_met_pt_jet = m_met.getMetEt()/(m_jets.getCollection(JET_ALL_SIGNAL)->at(0)->getPt());
      m_tmva_pt_lep_jet = PennSusyFrame::getPtRatioLepJet( m_event.getFlavorChannel()
                                                           , m_electrons.getCollection(EL_SELECTED)
                                                           , m_muons.getCollection(MU_SELECTED)
                                                           , m_jets.getCollection(JET_ALL_SIGNAL)
                                                           );
      m_tmva_dphi_met_jet = m_met.getDPhi(m_jets.getCollection(JET_ALL_SIGNAL)->at(0));
    }
  
  else 
    {
      m_tmva_met_pt_jet = 0.;
      m_tmva_pt_lep_jet = 0.;
      m_tmva_dphi_met_jet = 0.;
    }
  
  m_bdt_score_m20isr = m_tmva_reader_isr.EvaluateMVA("m20_isr signal");
  m_bdt_score_m35isr = m_tmva_reader_isr.EvaluateMVA("m35_isr signal");
  m_bdt_score_m65isr = m_tmva_reader_isr.EvaluateMVA("m65_isr signal");
  m_bdt_score_m100isr = m_tmva_reader_isr.EvaluateMVA("m100_isr signal");
  
  m_bdt_score_m20noisr = m_tmva_reader_noisr.EvaluateMVA("m20_noisr signal");
  m_bdt_score_m35noisr = m_tmva_reader_noisr.EvaluateMVA("m35_noisr signal");
  m_bdt_score_m65noisr = m_tmva_reader_noisr.EvaluateMVA("m65_noisr signal");
  m_bdt_score_m100noisr = m_tmva_reader_noisr.EvaluateMVA("m100_noisr signal");
   
  //    std::cout<<"BDT score: "<<m_bdt_score_m20isr<<std::endl;
  //    std::cout<<"BDT score: "<<m_bdt_score_m20noisr<<std::endl;
  //    std::cout<<"BDT score: "<<m_bdt_score_m35isr<<std::endl;
  //    std::cout<<"BDT score: "<<m_bdt_score_m35noisr<<std::endl;
  //    std::cout<<"BDT score: "<<m_bdt_score_m65isr<<std::endl;
  //    std::cout<<"BDT score: "<<m_bdt_score_m65noisr<<std::endl;
  //    std::cout<<"BDT score: "<<m_bdt_score_m100isr<<std::endl;
  //    std::cout<<"BDT score: "<<m_bdt_score_m100noisr<<std::endl;
  //    std::cout<<std::endl;
}


// -----------------------------------------------------------------------------	
void PennSusyFrame::EwkAnalysis::doFakeCR()
{
  
  double event_fake_weight = m_event_weight * m_event_quantities.getFakeWeight();
  
  bool pass_fake_cr = m_pass_event;
  
  // Define Fake control regions
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
  
  double bdt_score_min = -999;
  double bdt_score_max = -0.1;

  bool pass_bdt_fake_cr = (PennSusyFrame::passCut(m_bdt_score_m20isr,
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
      //std::cout << "\twriting histogram handler " << hist_it << " to file\n";
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
void PennSusyFrame::EwkAnalysis::doISRSR()
{
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


  double m20_Isr_cut = 0.06;
  double m35_Isr_cut = 0.076;
  double m65_Isr_cut = 0.092;
  double m100_Isr_cut = 0.092;

  double bdt_max = 999999;



  double m20_Isr_vr_min_cut = 0.024;
  double m20_Isr_vr_max_cut = 0.124; 

  double m35_Isr_vr_min_cut = 0.088;
  double m35_Isr_vr_max_cut = 0.188; 

  double m65_Isr_vr_min_cut = 0.04;
  double m65_Isr_vr_max_cut = 0.14; 

  double m100_Isr_vr_min_cut = 0.056;
  double m100_Isr_vr_max_cut = 0.156; 


  bool pass_m20_isr_cut = m_pass_event && (PennSusyFrame::passCut(m_bdt_score_m20isr
                                                                  , m20_Isr_cut
                                                                  , bdt_max 
                                                                   ));
  bool pass_m35_isr_cut = m_pass_event && (PennSusyFrame::passCut(m_bdt_score_m35isr
                                                                  , m35_Isr_cut
                                                                  , bdt_max 
                                                                  ));

  bool pass_m65_isr_cut = m_pass_event && (PennSusyFrame::passCut(m_bdt_score_m65isr
                                                                  , m65_Isr_cut
                                                                  , bdt_max 
                                                                  ));

  bool pass_m100_isr_cut = m_pass_event && (PennSusyFrame::passCut(m_bdt_score_m100isr
                                                                  , m100_Isr_cut
                                                                  , bdt_max 
                                                                  ));



  //std::cout<<m_pass_event<<" cut: "<<(PennSusyFrame::passCut(m_bdt_score_m20isr
  //								 , m20_Isr_vr_min_cut
  //								 , m20_Isr_vr_max_cut
  //							     ))<<std::endl;

  bool pass_m20_isr_vr = m_pass_event && (PennSusyFrame::passCut(m_bdt_score_m20isr
								 , m20_Isr_vr_min_cut
								 , m20_Isr_vr_max_cut
								 ));

  //std::cout<<"after AND: "<<m_pass_event<<std::endl<<std::endl;
  bool pass_m35_isr_vr = m_pass_event && (PennSusyFrame::passCut(m_bdt_score_m35isr
								 , m35_Isr_vr_min_cut
								 , m35_Isr_vr_max_cut
								 ));

  bool pass_m65_isr_vr = m_pass_event && (PennSusyFrame::passCut(m_bdt_score_m65isr
								 , m65_Isr_vr_min_cut
								 , m65_Isr_vr_max_cut
								 ));

  bool pass_m100_isr_vr = m_pass_event && (PennSusyFrame::passCut(m_bdt_score_m100isr
								  , m100_Isr_vr_min_cut
								  , m100_Isr_vr_max_cut
								 ));


                                    
  if (pass_m20_isr_cut)  fillHistHandles( PennSusyFrame::EWK_HIST_SR_M20_ISR, m_event_weight);
  if (pass_m35_isr_cut)  fillHistHandles( PennSusyFrame::EWK_HIST_SR_M35_ISR, m_event_weight);
  if (pass_m65_isr_cut)  fillHistHandles( PennSusyFrame::EWK_HIST_SR_M65_ISR, m_event_weight);
  if (pass_m100_isr_cut) fillHistHandles( PennSusyFrame::EWK_HIST_SR_M100_ISR, m_event_weight); 

                                    
  if (pass_m20_isr_vr){
    fillHistHandles( PennSusyFrame::EWK_HIST_VR_M20_ISR, m_event_weight);
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_VR_M20_ISR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_VR_M20_ISR, m_event_weight);
    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_VR_M20_ISR);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_VR_M20_ISR, m_event_weight);
  }
  if (pass_m35_isr_vr){
    fillHistHandles( PennSusyFrame::EWK_HIST_VR_M35_ISR, m_event_weight);
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_VR_M35_ISR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_VR_M35_ISR, m_event_weight);
    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_VR_M35_ISR);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_VR_M35_ISR, m_event_weight);
  }
  if (pass_m65_isr_vr) {  
    fillHistHandles( PennSusyFrame::EWK_HIST_VR_M65_ISR, m_event_weight);
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_VR_M65_ISR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_VR_M65_ISR, m_event_weight);
    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_VR_M65_ISR);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_VR_M65_ISR, m_event_weight);
  }
  if (pass_m100_isr_vr){ 
    fillHistHandles( PennSusyFrame::EWK_HIST_VR_M100_ISR, m_event_weight); 
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_VR_M100_ISR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_VR_M100_ISR, m_event_weight);
    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_VR_M100_ISR);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_VR_M100_ISR, m_event_weight);
  }

}
// -----------------------------------------------------------------------------
void PennSusyFrame::EwkAnalysis::doNoISRSR()
{

  double m20_noIsr_cut = 0.156;
  double m35_noIsr_cut = 0.188;
  double m65_noIsr_cut = 0.124;
  double m100_noIsr_cut = 0.124;


  double m20_noIsr_vr_min_cut = 0.024;
  double m20_noIsr_vr_max_cut = 0.124; 

  double m35_noIsr_vr_min_cut = 0.088;
  double m35_noIsr_vr_max_cut = 0.188; 

  double m65_noIsr_vr_min_cut = 0.04;
  double m65_noIsr_vr_max_cut = 0.14; 

  double m100_noIsr_vr_min_cut = 0.056;
  double m100_noIsr_vr_max_cut = 0.156; 


  double bdt_max = 999999;


  bool pass_m20_noisr_cut = m_pass_event && (PennSusyFrame::passCut(m_bdt_score_m20noisr
                                                                    , m20_noIsr_cut
                                                                    , bdt_max 
                                                                    ));
  bool pass_m35_noisr_cut = m_pass_event && (PennSusyFrame::passCut(m_bdt_score_m35noisr
                                                                    , m35_noIsr_cut
                                                                    , bdt_max 
                                                                    ));
  
  bool pass_m65_noisr_cut = m_pass_event && (PennSusyFrame::passCut(m_bdt_score_m65noisr
                                                                    , m65_noIsr_cut
                                                                    , bdt_max 
                                                                    ));
  
  bool pass_m100_noisr_cut = m_pass_event && (PennSusyFrame::passCut(m_bdt_score_m100noisr
                                                                     , m100_noIsr_cut
                                                                     , bdt_max 
                                                                     ));


  bool pass_m20_noisr_vr = m_pass_event && (PennSusyFrame::passCut(m_bdt_score_m20noisr
								   , m20_noIsr_vr_min_cut
								   , m20_noIsr_vr_max_cut
								   ));
  bool pass_m35_noisr_vr = m_pass_event && (PennSusyFrame::passCut(m_bdt_score_m35noisr
								   , m35_noIsr_vr_min_cut
								   , m35_noIsr_vr_max_cut
                                                                    ));
  
  bool pass_m65_noisr_vr = m_pass_event && (PennSusyFrame::passCut(m_bdt_score_m65noisr
								   , m65_noIsr_vr_min_cut
								   , m65_noIsr_vr_max_cut
								   ));
  
  bool pass_m100_noisr_vr = m_pass_event && (PennSusyFrame::passCut(m_bdt_score_m100noisr
								    , m100_noIsr_vr_min_cut
								    , m100_noIsr_vr_max_cut
								    ));

  
  if (pass_m20_noisr_cut)  fillHistHandles( PennSusyFrame::EWK_HIST_SR_M20_NOISR, m_event_weight);
  if (pass_m35_noisr_cut)  fillHistHandles( PennSusyFrame::EWK_HIST_SR_M35_NOISR, m_event_weight);
  if (pass_m65_noisr_cut)  fillHistHandles( PennSusyFrame::EWK_HIST_SR_M65_NOISR, m_event_weight);
  if (pass_m100_noisr_cut)  fillHistHandles( PennSusyFrame::EWK_HIST_SR_M100_NOISR, m_event_weight); 

  if (pass_m20_noisr_vr){  
    fillHistHandles( PennSusyFrame::EWK_HIST_VR_M20_NOISR, m_event_weight);
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_VR_M20_NOISR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_VR_M20_NOISR, m_event_weight);
    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_VR_M20_NOISR);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_VR_M20_NOISR, m_event_weight);
  }
  if (pass_m35_noisr_vr) { 
    fillHistHandles( PennSusyFrame::EWK_HIST_VR_M35_NOISR, m_event_weight);
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_VR_M35_NOISR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_VR_M35_NOISR, m_event_weight);
    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_VR_M35_NOISR);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_VR_M35_NOISR, m_event_weight);
  }
  if (pass_m65_noisr_vr)  {
    fillHistHandles( PennSusyFrame::EWK_HIST_VR_M65_NOISR, m_event_weight);
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_VR_M65_NOISR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_VR_M65_NOISR, m_event_weight);
    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_VR_M65_NOISR);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_VR_M65_NOISR, m_event_weight);
  }
  if (pass_m100_noisr_vr)  {
    fillHistHandles( PennSusyFrame::EWK_HIST_VR_M100_NOISR, m_event_weight); 
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, EWK_CUT_VR_M100_NOISR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, EWK_CUT_VR_M100_NOISR, m_event_weight);
    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), EWK_CUT_VR_M100_NOISR);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), EWK_CUT_VR_M100_NOISR, m_event_weight);
  }


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

  m_ewk_histogram_handler.at(hist_level)->FillBDT(m_event, m_bdt_score_m20isr, weight);
  m_ewk_histogram_handler.at(hist_level)->FillIsr(m_event
						  , m_event_quantities
						  , m_electrons.getCollection(EL_GOOD)
						  , m_muons.getCollection(MU_GOOD)
						  , m_jets.getCollection(JET_ALL_SIGNAL)
						  , m_met
						  , weight
						  );
  m_ewk_histogram_handler.at(hist_level)->FillNoIsr(m_event
						  , m_event_quantities
						  , m_electrons.getCollection(EL_GOOD)
						  , m_muons.getCollection(MU_GOOD)
						  , m_jets.getCollection(JET_ALL_SIGNAL)
						  , m_met
						  , weight
						  );

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
