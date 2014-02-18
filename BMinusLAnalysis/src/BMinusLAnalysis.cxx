#include "BMinusLAnalysis/include/BMinusLAnalysis.h"
#include "PennSusyFrameCore/include/PennSusyFrameCore.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <dirent.h>
#include <math.h>
#include <algorithm>

#include "PennSusyFrameCore/include/ObjectContainers.h"
#include "PennSusyFrameCore/include/Calculators.h"

// -----------------------------------------------------------------------------
PennSusyFrame::BMinusLAnalysis::BMinusLAnalysis(TTree* tree) : PennSusyFrame::PennSusyFrameCore(tree)
                                                             , m_out_hist_file_name("BMinusL.hists.root")
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
                                                             , m_crit_cut_signal_lep(false)
{
}

// -----------------------------------------------------------------------------
PennSusyFrame::BMinusLAnalysis::~BMinusLAnalysis()
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::prepareTools()
{
  PennSusyFrameCore::prepareTools();

  std::string base_dir = getenv("BASE_WORK_DIR");
  if (m_is_data) {
    // TODO make this configurable
    m_grl.init( base_dir
              + "/data/data12_8TeV.periodAllYear_DetStatus-v58-pro14-01_DQDefects-00-00-33_PHYS_StandardGRL_All_Good.xml"
              );
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::prepareSelection()
{
  PennSusyFrameCore::prepareSelection();

  std::cout << "preparing selection\n";

  // EL_BASELINE
  m_electron_selectors.at(EL_BASELINE).setElectronQuality(EL_QUALITY_MEDPP);
  m_electron_selectors.at(EL_BASELINE).setPtCut(20.e3, -1);
  m_electron_selectors.at(EL_BASELINE).setEtaCut(-1, 2.47);

  // EL_SIGNAL
  m_electron_selectors.at(EL_SIGNAL).setElectronQuality(EL_QUALITY_TIGHTPP);
  m_electron_selectors.at(EL_SIGNAL).setD0SignificanceCut(-1, 3);
  m_electron_selectors.at(EL_SIGNAL).setZ0SignThetaCut(-1, 0.4);
  m_electron_selectors.at(EL_SIGNAL).setPtIsoCut(-1, 0.13);
  m_electron_selectors.at(EL_SIGNAL).setEtIsoCut(-1, 0.21);

  // MU_BASELINE
  m_muon_selectors.at(MU_BASELINE).setPtCut(20.e3, -1);
  m_muon_selectors.at(MU_BASELINE).setEtaCut(-1, 2.5);
  m_muon_selectors.at(MU_BASELINE).setBLayerHitsCut(1, -1);
  m_muon_selectors.at(MU_BASELINE).setPixelHitsCut(1, -1);
  m_muon_selectors.at(MU_BASELINE).setSctHitsCut(5, -1);
  m_muon_selectors.at(MU_BASELINE).setSiHolesCut(-1, 2);
  m_muon_selectors.at(MU_BASELINE).setTrtEtaCut(0.1, 1.9);
  m_muon_selectors.at(MU_BASELINE).setTrtHitsCut(6, -1);
  m_muon_selectors.at(MU_BASELINE).setTrtOlFractionCut(-1, 0.9);

  // MU_SIGNAL
  m_muon_selectors.at(MU_SIGNAL).setEtaCut(-1, 2.4);
  m_muon_selectors.at(MU_SIGNAL).setD0SignificanceCut(-1, 3.);
  m_muon_selectors.at(MU_SIGNAL).setZ0SignThetaCut(-1, 1.);
  m_muon_selectors.at(MU_SIGNAL).setPtIsoCut(-1, 0.11);
  m_muon_selectors.at(MU_SIGNAL).setEtIsoCut(-1, 0.19);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::beginRun()
{
  prepareSelection();

  m_histogram_handlers.push_back( new PennSusyFrame::LeptonKinematicsHists() );
  m_histogram_handlers.push_back( new PennSusyFrame::JetKinematicsHists() );
  m_histogram_handlers.push_back( new PennSusyFrame::MetHists() );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::processEvent()
{
  m_event_weight = 1.;

  m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_ALL);
  m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_ALL, m_event_weight);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set mc event weight
  // TODO validate MC event weight
  m_event_weight *= m_event_quantities.getMcEventWeight();
  m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_MC_EVENT_WEIGHT);
  m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_MC_EVENT_WEIGHT, m_event_weight);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set pile up weight
  // TODO validate pile up weight
  m_event_weight *= m_event_quantities.getPileUpSF();
  m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_PILEUP_WEIGHT);
  m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_PILEUP_WEIGHT, m_event_weight);

  // -----------------------------------------------------------------------------
  // TODO get phase space in a proper way
  // m_event.setTriggerPhase( PennSusyFrame::getTriggerPhase( m_electrons.getCollection(EL_GOOD)
  //                                                        , m_muons.getCollection(MU_GOOD)
  //                                                        )
  //                        );
  // m_event.setPhaseSpace(PennSusyFrame::getPhaseSpaceFromTriggerPhase(m_event.getTriggerPhase()));
  if      (m_event.getFlavorChannel() == FLAVOR_EE) m_event.setPhaseSpace(PHASE_EE);
  else if (m_event.getFlavorChannel() == FLAVOR_MM) m_event.setPhaseSpace(PHASE_MM);
  // not currently distinguishing between EM and ME phase space channels
  else if (m_event.getFlavorChannel() == FLAVOR_EM) m_event.setPhaseSpace(PHASE_EM);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // GRL cut
  // TODO validate grl cut
  // only check grl cut on data
  bool pass_grl = (!m_is_data || m_grl.passEvent(m_event));
  m_pass_event = (m_pass_event && pass_grl);
  if (m_crit_cut_grl && !pass_grl) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_GRL);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_GRL, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // incomplete event cut
  // TODO validate incomplete event cut
  bool pass_incomplete_event = PennSusyFrame::passIncompleteEvent(m_event);
  m_pass_event = (m_pass_event && pass_incomplete_event);
  if (m_crit_cut_incomplete_event && !pass_incomplete_event) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_INCOMPLETE_EVENT);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_INCOMPLETE_EVENT, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // LAr error cut
  // TODO validate LAr error cut
  bool pass_lar_error = PennSusyFrame::passLarError(m_event);
  m_pass_event = (m_pass_event && pass_lar_error);
  if (m_crit_cut_lar_error && !pass_lar_error) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_LAR_ERROR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_LAR_ERROR, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile error cut
  // TODO validate tile error cut
  bool pass_tile_error = PennSusyFrame::passTileError(m_event);
  m_pass_event = (m_pass_event && pass_tile_error);
  if (m_crit_cut_tile_error && !pass_tile_error) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_TILE_ERROR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_TILE_ERROR, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile hot spot cut
  // TODO validate tile hot spot cut
  bool pass_tile_hot_spot = PennSusyFrame::TileHotSpotTool::passTileHotSpot(m_event, m_jets);
  m_pass_event = (m_pass_event && pass_tile_hot_spot);
  if (m_crit_cut_tile_hot_spot && !pass_tile_hot_spot) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_TILE_HOT_SPOT);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_TILE_HOT_SPOT, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile trip cut
  // TODO validate tile trip cut
  bool pass_tile_trip = m_tile_trip_tool.passTileTrip(m_event);
  m_pass_event = (m_pass_event && pass_tile_trip);
  if (m_crit_cut_tile_trip && !pass_tile_trip) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_TILE_TRIP);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_TILE_TRIP, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // bad jet veto
  bool pass_bad_jet_veto = (m_jets.num(JET_BAD) == 0);
  m_pass_event = (m_pass_event && pass_bad_jet_veto);
  if (m_crit_cut_bad_jet_veto && !pass_bad_jet_veto) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_BAD_JET_VETO);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_BAD_JET_VETO, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // calo problem jet cut
  bool pass_calo_problem_jet = (m_jets.num(JET_CALO_PROBLEM) == 0);
  m_pass_event = (m_pass_event && pass_calo_problem_jet);
  if (m_crit_cut_calo_problem_jet && !pass_calo_problem_jet) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_CALO_PROBLEM_JET);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_CALO_PROBLEM_JET, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // primary vertex cut
  bool pass_primary_vertex = PennSusyFrame::passPrimaryVertex(m_vertices);
  m_pass_event = (m_pass_event && pass_primary_vertex);
  if (m_crit_cut_primary_vertex && !pass_primary_vertex) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_PRIMARY_VERTEX);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_PRIMARY_VERTEX, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // bad muon cut
  bool pass_bad_mu_veto = (m_muons.num(MU_BAD) == 0);
  m_pass_event = (m_pass_event && pass_bad_mu_veto);
  if (m_crit_cut_bad_mu_veto && !pass_bad_mu_veto) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_BAD_MUON);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_BAD_MUON, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // cosmic muon veto
  bool pass_cosmic_mu_veto = (m_muons.num(MU_COSMIC) == 0);
  m_pass_event = (m_pass_event && pass_cosmic_mu_veto);
  if (m_crit_cut_cosmic_mu_veto && !pass_cosmic_mu_veto) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_COSMIC_MUON_VETO);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_COSMIC_MUON_VETO, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // HFOR cut
  // TODO validate HFOR cut
  bool pass_hfor = m_hfor_tool.passHFOR(m_mc_truth);
  m_pass_event = (m_pass_event && pass_hfor);
  if (m_crit_cut_hfor && !pass_hfor) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_HFOR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_HFOR, m_event_weight);
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
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_MC_OVERLAP);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_MC_OVERLAP, m_event_weight);
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
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_GE_2_BASELINE_LEPTONS);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_GE_2_BASELINE_LEPTONS, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // == 2 baseline leptons cut
  bool pass_2_lep = (num_good_leptons == 2);
  m_pass_event = (m_pass_event && pass_2_lep);
  if (m_crit_cut_2_lep && !pass_2_lep) return;
  if (m_pass_event) {
    {
      m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_EQ_2_BASELINE_LEPTONS);
      m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_EQ_2_BASELINE_LEPTONS, m_event_weight);
    }
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
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_EQ_2_SIGNAL_LEPTON);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_EQ_2_SIGNAL_LEPTON, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // lepton scale factor
  // TODO validate lepton sf
  m_event_weight *= m_event_quantities.getLeptonSF();
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_LEP_SF);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_LEP_SF, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), BMINUSL_CUT_LEP_SF);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), BMINUSL_CUT_LEP_SF, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // fill histograms
  size_t num_hists = m_histogram_handlers.size();
  for (size_t hist_it = 0; hist_it != num_hists; ++hist_it) {
    m_histogram_handlers.at(hist_it)->Fill( m_event
                                          , m_electrons.getCollection(EL_GOOD)
                                          , m_muons.getCollection(MU_GOOD)
                                          , m_jets.getCollection(JET_GOOD)
                                          , m_met
                                          , m_event_weight
                                          );
  }
  m_bminusl_histogram_handler.FillSpecial( m_event
                                         , m_jets.getCollection(JET_B)
                                         , m_event_weight
                                         );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::finalizeEvent()
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::finalizeRun()
{
  std::cout << "BMinusLAnalysis::finalizeRun()\n";
  std::cout << "creating output histogram file\n";
  TFile out_hist_file(m_out_hist_file_name.c_str(), "RECREATE");

  std::cout << "about to write histograms to file\n";
  size_t num_hists = m_histogram_handlers.size();
  for (size_t hist_it = 0; hist_it != num_hists; ++hist_it) {
    std::cout << "\twriting histogram handler " << hist_it << " to file\n";
    m_histogram_handlers.at(hist_it)->write(&out_hist_file);
  }
  m_bminusl_histogram_handler.write(&out_hist_file);
  std::cout << "done writing histograms to file\n";

  // out_hist_file.Write();
  out_hist_file.Close();
  std::cout << "file is closed!\n";

  std::cout << "Deleting histogram handlers\n";
  // for (size_t hist_it = 0; hist_it != num_hists; ++hist_it) {
  //   std::cout << "\tdeleting histogram handler " << hist_it << " to file\n";
  //   delete m_histogram_handlers.at(hist_it);
  // }
  // m_histogram_handlers.clear();
}
