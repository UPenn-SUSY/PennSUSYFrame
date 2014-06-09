#include "BMinusLAnalysis/include/BMinusLOptimizeNtupleMaker.h"
#include "BMinusLAnalysis/include/BMinusLUtils.h"
#include "PennSusyFrameCore/include/PennSusyFrameCore.h"

#include "TFile.h"
#include "TTree.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <dirent.h>
#include <math.h>
#include <algorithm>

#include "PennSusyFrameCore/include/ObjectContainers.h"
#include "PennSusyFrameCore/include/Calculators.h"
#include "PennSusyFrameCore/include/D3PDReader.h"
#include "PennSusyFrameCore/include/SelectorHelpers.h"

// -----------------------------------------------------------------------------
PennSusyFrame::BMinusLOptimizeNtupleMaker::BMinusLOptimizeNtupleMaker(TTree* tree) : PennSusyFrame::PennSusyFrameCore(tree)
                                                                                   , m_out_ntuple_file_name("BMinusL.ntup.root")
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
                                                                                   , m_crit_cut_b_jets(false)
                                                                                   , m_crit_cut_z_veto(false)
                                                                                   , m_min_el_pt_baseline(20.e3)
                                                                                   , m_max_el_pt_baseline(-1)
                                                                                   , m_min_mu_pt_baseline(20.e3)
                                                                                   , m_max_mu_pt_baseline(-1)
                                                                                   , m_min_b_jet_pt_baseline(20.e3)
                                                                                   , m_max_b_jet_pt_baseline(-1)
                                                                                   , m_output_file(0)
                                                                                   , m_output_tree(0)
{
}

// -----------------------------------------------------------------------------
PennSusyFrame::BMinusLOptimizeNtupleMaker::~BMinusLOptimizeNtupleMaker()
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLOptimizeNtupleMaker::prepareTools()
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
void PennSusyFrame::BMinusLOptimizeNtupleMaker::prepareSelection()
{
  PennSusyFrameCore::prepareSelection();

  std::cout << "preparing selection\n";

  // EL_BASELINE
  m_electron_selectors.at(EL_BASELINE).setElectronQuality(EL_QUALITY_MEDPP);
  // m_electron_selectors.at(EL_BASELINE).setPtCut(20.e3, -1);
  m_electron_selectors.at(EL_BASELINE).setPtCut(m_min_el_pt_baseline, m_max_el_pt_baseline);
  m_electron_selectors.at(EL_BASELINE).setEtaCut(-1, 2.47);

  // EL_SIGNAL
  m_electron_selectors.at(EL_SIGNAL).setElectronQuality(EL_QUALITY_TIGHTPP);
  m_electron_selectors.at(EL_SIGNAL).setD0SignificanceCut(-1, 3);
  m_electron_selectors.at(EL_SIGNAL).setZ0SignThetaCut(-1, 0.4);
  m_electron_selectors.at(EL_SIGNAL).setPtIsoCut(-1, 0.13);
  m_electron_selectors.at(EL_SIGNAL).setEtIsoCut(-1, 0.21);

  // MU_BASELINE
  // m_muon_selectors.at(MU_BASELINE).setPtCut(20.e3, -1);
  m_muon_selectors.at(MU_BASELINE).setPtCut(m_min_mu_pt_baseline, m_max_mu_pt_baseline);
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

  // JET_B
  m_jet_selectors.at(JET_B).setPtCut(m_min_b_jet_pt_baseline, m_max_b_jet_pt_baseline);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLOptimizeNtupleMaker::beginRun()
{
  PennSusyFrameCore::beginRun();

  // prepare selection
  prepareSelection();

  configureOutput(m_out_ntuple_file_name, "optimize");
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLOptimizeNtupleMaker::processEvent()
{
  clearVariables();

  m_event_weight = 1.;

  // m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_ALL);
  // m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_ALL, m_event_weight);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set mc event weight
  m_event_weight *= m_event_quantities.getMcEventWeight();
  // m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_MC_EVENT_WEIGHT);
  // m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_MC_EVENT_WEIGHT, m_event_weight);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set pile up weight
  m_event_weight *= m_event_quantities.getPileUpSF();
  // m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_PILEUP_WEIGHT);
  // m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_PILEUP_WEIGHT, m_event_weight);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set cross section weight
  m_event_weight *= m_xsec_weight;
  // m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_XSEC_WEIGHT);
  // m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_XSEC_WEIGHT, m_event_weight);

  // -----------------------------------------------------------------------------
  m_event.setPhaseSpace(getPhaseSpace());

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // GRL cut
  // only check grl cut on data
  bool pass_grl = (!m_is_data || m_grl.passEvent(m_event));
  m_pass_event = (m_pass_event && pass_grl);
  // if (m_crit_cut_grl && !pass_grl) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_GRL);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_GRL, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // incomplete event cut
  bool pass_incomplete_event = PennSusyFrame::passIncompleteEvent(m_event);
  m_pass_event = (m_pass_event && pass_incomplete_event);
  // if (m_crit_cut_incomplete_event && !pass_incomplete_event) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_INCOMPLETE_EVENT);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_INCOMPLETE_EVENT, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // LAr error cut
  bool pass_lar_error = PennSusyFrame::passLarError(m_event);
  m_pass_event = (m_pass_event && pass_lar_error);
  // if (m_crit_cut_lar_error && !pass_lar_error) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_LAR_ERROR);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_LAR_ERROR, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile error cut
  bool pass_tile_error = PennSusyFrame::passTileError(m_event);
  m_pass_event = (m_pass_event && pass_tile_error);
  // if (m_crit_cut_tile_error && !pass_tile_error) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_TILE_ERROR);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_TILE_ERROR, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile hot spot cut
  bool pass_tile_hot_spot = PennSusyFrame::TileHotSpotTool::passTileHotSpot(m_event, m_jets);
  m_pass_event = (m_pass_event && pass_tile_hot_spot);
  // if (m_crit_cut_tile_hot_spot && !pass_tile_hot_spot) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_TILE_HOT_SPOT);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_TILE_HOT_SPOT, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile trip cut
  bool pass_tile_trip = m_tile_trip_tool.passTileTrip(m_event);
  m_pass_event = (m_pass_event && pass_tile_trip);
  // if (m_crit_cut_tile_trip && !pass_tile_trip) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_TILE_TRIP);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_TILE_TRIP, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // bad jet veto
  bool pass_bad_jet_veto = (m_jets.num(JET_BAD) == 0);
  m_pass_event = (m_pass_event && pass_bad_jet_veto);
  // if (m_crit_cut_bad_jet_veto && !pass_bad_jet_veto) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_BAD_JET_VETO);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_BAD_JET_VETO, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // calo problem jet cut
  bool pass_calo_problem_jet = (m_jets.num(JET_CALO_PROBLEM) == 0);
  m_pass_event = (m_pass_event && pass_calo_problem_jet);
  // if (m_crit_cut_calo_problem_jet && !pass_calo_problem_jet) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_CALO_PROBLEM_JET);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_CALO_PROBLEM_JET, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // primary vertex cut
  bool pass_primary_vertex = PennSusyFrame::passPrimaryVertex(m_vertices);
  m_pass_event = (m_pass_event && pass_primary_vertex);
  // if (m_crit_cut_primary_vertex && !pass_primary_vertex) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_PRIMARY_VERTEX);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_PRIMARY_VERTEX, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // bad muon cut
  bool pass_bad_mu_veto = (m_muons.num(MU_BAD) == 0);
  m_pass_event = (m_pass_event && pass_bad_mu_veto);
  // if (m_crit_cut_bad_mu_veto && !pass_bad_mu_veto) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_BAD_MUON);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_BAD_MUON, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // cosmic muon veto
  bool pass_cosmic_mu_veto = (m_muons.num(MU_COSMIC) == 0);
  m_pass_event = (m_pass_event && pass_cosmic_mu_veto);
  // if (m_crit_cut_cosmic_mu_veto && !pass_cosmic_mu_veto) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_COSMIC_MUON_VETO);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_COSMIC_MUON_VETO, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // HFOR cut
  bool pass_hfor = m_hfor_tool.passHFOR(m_mc_truth);
  m_pass_event = (m_pass_event && pass_hfor);
  // if (m_crit_cut_hfor && !pass_hfor) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_HFOR);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_HFOR, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // mc overlap cut
  bool pass_mc_overlap = (  PennSusyFrame::passSherpaWWOverlapRemoval(m_event, m_mc_truth)
                         && PennSusyFrame::passZOverlapRemoval(m_mc_truth)
                         );
  m_pass_event = (m_pass_event && pass_mc_overlap);
  // if (m_crit_cut_mc_overlap && !pass_mc_overlap) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_MC_OVERLAP);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_MC_OVERLAP, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get number of good leptons
  int num_good_leptons = m_electrons.num(EL_GOOD) + m_muons.num(MU_GOOD);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // >= 2 baseline leptons cut
  bool pass_ge_2_lep = (num_good_leptons >= 2);
  m_pass_event = (m_pass_event && pass_ge_2_lep);
  // if (m_crit_cut_ge_2_lep && !pass_ge_2_lep) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_GE_2_BASELINE_LEPTONS);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_GE_2_BASELINE_LEPTONS, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // == 2 baseline leptons cut
  bool pass_2_lep = (num_good_leptons == 2);
  m_pass_event = (m_pass_event && pass_2_lep);
  // if (m_crit_cut_2_lep && !pass_2_lep) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_EQ_2_BASELINE_LEPTONS);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_EQ_2_BASELINE_LEPTONS, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get number of signal leptons
  int num_signal_leptons = m_electrons.num(EL_SIGNAL) + m_muons.num(MU_SIGNAL);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // == 2 signal lepton cut
  bool pass_signal_lep = (num_signal_leptons == 2);
  m_pass_event = (m_pass_event && pass_signal_lep);
  // if (m_crit_cut_signal_lep && !pass_signal_lep) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_EQ_2_SIGNAL_LEPTON);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_EQ_2_SIGNAL_LEPTON, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // lepton scale factor
  m_event_weight *= m_event_quantities.getLeptonSF();
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_LEP_SF);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_LEP_SF, m_event_weight);

  //   m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), BMINUSL_CUT_LEP_SF);
  //   m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), BMINUSL_CUT_LEP_SF, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get number of b jets
  int num_b_jets = m_jets.num(JET_B);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // check number of b jets >= 2
  bool pass_ge_2_b_jet = (num_b_jets >= 2);
  m_pass_event = (m_pass_event && pass_ge_2_b_jet);
  // if (m_crit_cut_b_jets && ! pass_ge_2_b_jet) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_GE_2_B_JET);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_GE_2_B_JET, m_event_weight);

  //   m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), BMINUSL_CUT_GE_2_B_JET);
  //   m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), BMINUSL_CUT_GE_2_B_JET, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // check number of b jets == 2
  bool pass_eq_2_b_jet = (num_b_jets == 2);
  m_pass_event = (m_pass_event && pass_eq_2_b_jet);
  // if (m_crit_cut_b_jets && ! pass_eq_2_b_jet) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_EQ_2_B_JET);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_EQ_2_B_JET, m_event_weight);

  //   m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), BMINUSL_CUT_EQ_2_B_JET);
  //   m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), BMINUSL_CUT_EQ_2_B_JET, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // b tag sf
  m_event_weight *= m_event_quantities.getBTagSF();
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_B_TAG_SF);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_B_TAG_SF, m_event_weight);

  //   m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), BMINUSL_CUT_B_TAG_SF);
  //   m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), BMINUSL_CUT_B_TAG_SF, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do b-l pairing
  PennSusyFrame::blPair bl_0;
  PennSusyFrame::blPair bl_1;

  bool pass_bl_pairing = PennSusyFrame::doBLPairing( m_event
                                                   , m_electrons.getCollection(EL_GOOD)
                                                   , m_muons.getCollection(MU_GOOD)
                                                   , m_jets.getCollection(JET_B)
                                                   , bl_0
                                                   , bl_1
                                                   );
  m_pass_event = (m_pass_event && pass_bl_pairing);
  // if (m_crit_cut_bl_pairing && !pass_bl_pairing) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_BL_PAIRING);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_BL_PAIRING, m_event_weight);

  //   m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), BMINUSL_CUT_BL_PAIRING);
  //   m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), BMINUSL_CUT_BL_PAIRING, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do z veto fo SFOS lepton pairs
  bool pass_z_veto = true;
  if (  m_event.getFlavorChannel() == FLAVOR_EE
     || m_event.getFlavorChannel() == FLAVOR_MM
     ) {
    pass_z_veto = ( fabs(m_event_quantities.getMll() - 91.e3) > 10.e3 );
  }
  m_pass_event = (m_pass_event && pass_z_veto);
  // if (m_crit_cut_z_veto && !pass_z_veto) return;
  // if (m_pass_event) {
  //   m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_ZVETO);
  //   m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_ZVETO, m_event_weight);

  //   m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), BMINUSL_CUT_ZVETO);
  //   m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), BMINUSL_CUT_ZVETO, m_event_weight);
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // fill ntuple for this event if passed
  if (m_pass_event) {
    fillNtuple( &bl_0
              , &bl_1
              , m_event_weight
              );
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLOptimizeNtupleMaker::finalizeEvent()
{
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLOptimizeNtupleMaker::finalizeRun()
{
  // m_d3pd_reader->writeNumEvents();

  m_output_file->Write();
  m_output_file->Close();

  // m_raw_cutflow_tracker.printToScreen();
  // m_cutflow_tracker.printToScreen();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLOptimizeNtupleMaker::clearVariables()
{
  m_weight = 1.;

  m_mbl_0 = 0 ;
  m_mbl_1 = 0 ;

  m_ptbl_0 = 0 ;
  m_ptbl_1 = 0 ;

  m_mbbll  = 0 ;
  m_ptbbll = 0 ;

  m_mll = 0 ;

  m_met_et  = 0 ;
  m_met_rel = 0 ;

  m_ht_all      = 0 ;
  m_ht_baseline = 0 ;
  m_ht_good     = 0 ;
  m_ht_signal   = 0 ;

  m_pt_l_0 = 0 ;
  m_pt_l_1 = 0 ;
  m_pt_b_0 = 0 ;
  m_pt_b_1 = 0 ;

  m_dphi_bl_0 = 0 ;
  m_dphi_bl_1 = 0 ;
  m_deta_bl_0 = 0 ;
  m_deta_bl_1 = 0 ;
  m_dr_bl_0 = 0 ;
  m_dr_bl_1 = 0 ;

  m_dphi_ll = 0 ;
  m_deta_ll = 0 ;
  m_dr_ll = 0 ;

  m_dphi_bb = 0 ;
  m_deta_bb = 0 ;
  m_dr_bb = 0 ;
}

// -----------------------------------------------------------------------------
// TODO move to PennSusyFrameCore
PHASE_SPACE PennSusyFrame::BMinusLOptimizeNtupleMaker::getPhaseSpace()
{
  if (m_event.getFlavorChannel() == FLAVOR_EE) return PHASE_EE;
  if (m_event.getFlavorChannel() == FLAVOR_MM) return PHASE_MM;
  if (m_event.getFlavorChannel() == FLAVOR_EM) {
    float pt_e = m_electrons.getCollection(EL_GOOD)->at(0)->getPt();
    float pt_m = m_muons.getCollection(    MU_GOOD)->at(0)->getPt();
    if (pt_e >= pt_m) return PHASE_EM;
    return PHASE_ME;
  }

  return PHASE_NONE;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLOptimizeNtupleMaker::configureOutput( std::string out_file_name
                                                               , std::string out_tree_name
                                                               )
{
  m_output_file = new TFile(out_file_name.c_str(), "RECREATE");
  m_output_tree = new TTree(out_tree_name.c_str(), out_tree_name.c_str());

  // connect branches for output
  m_output_tree->Branch( "weight" , &m_weight);
                                        
  m_output_tree->Branch( "mbl_0" , &m_mbl_0);
  m_output_tree->Branch( "mbl_1" , &m_mbl_1);
  m_output_tree->Branch( "mbbll" , &m_mbbll);
                                        
  m_output_tree->Branch( "ptbl_0" , &m_ptbl_0);
  m_output_tree->Branch( "ptbl_1" , &m_ptbl_1);
  m_output_tree->Branch( "ptbbll" , &m_ptbbll);
                                        
  m_output_tree->Branch( "mll"  , &m_mll);
  m_output_tree->Branch( "ptll" , &m_ptll);
                                        
  m_output_tree->Branch( "met_et"  , &m_met_et);
  m_output_tree->Branch( "met_rel" , &m_met_rel);
                                        
  m_output_tree->Branch( "ht_all"      , &m_ht_all);
  m_output_tree->Branch( "ht_baseline" , &m_ht_baseline);
  m_output_tree->Branch( "ht_good"     , &m_ht_good);
  m_output_tree->Branch( "ht_signal"   , &m_ht_signal);
                                        
  m_output_tree->Branch( "pt_l_0" , &m_pt_l_0);
  m_output_tree->Branch( "pt_l_1" , &m_pt_l_1);
  m_output_tree->Branch( "pt_b_0" , &m_pt_b_0);
  m_output_tree->Branch( "pt_b_1" , &m_pt_b_1);
                                        
  m_output_tree->Branch( "dphi_bl_0" , &m_dphi_bl_0);
  m_output_tree->Branch( "dphi_bl_1" , &m_dphi_bl_1);
  m_output_tree->Branch( "deta_bl_0" , &m_deta_bl_0);
  m_output_tree->Branch( "deta_bl_1" , &m_deta_bl_1);
  m_output_tree->Branch( "dr_bl_0"   , &m_dr_bl_0);
  m_output_tree->Branch( "dr_bl_1"   , &m_dr_bl_1);
                                        
  m_output_tree->Branch( "dphi_ll" , &m_dphi_ll);
  m_output_tree->Branch( "deta_ll" , &m_deta_ll);
  m_output_tree->Branch( "dr_ll"   , &m_dr_ll);
                                        
  m_output_tree->Branch( "dphi_bb" , &m_dphi_bb);
  m_output_tree->Branch( "deta_bb" , &m_deta_bb);
  m_output_tree->Branch( "dr_bb"   , &m_dr_bb);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLOptimizeNtupleMaker::fillNtuple( const PennSusyFrame::blPair* bl_0
                                                          , const PennSusyFrame::blPair* bl_1
                                                          , float weight
                                                          )
{
  m_weight = weight;

  m_mbl_0 = bl_0->getMbl()/1.e3;
  m_mbl_1 = bl_1->getMbl()/1.e3;

  m_ptbl_0 = bl_0->getPtbl()/1.e3;
  m_ptbl_1 = bl_1->getPtbl()/1.e3;

  m_mbbll  = PennSusyFrame::calcMbbll( *bl_0, *bl_1)/1.e3;
  m_ptbbll = PennSusyFrame::calcPtbbll(*bl_0, *bl_1)/1.e3;

  m_mll  = m_event_quantities.getMll()/1.e3;
  m_ptll = m_event_quantities.getPtll()/1.e3;

  m_met_et  = m_met.getMetEt() /1.e3;
  m_met_rel = m_met.getMetRel()/1.e3;

  m_ht_all      = m_event_quantities.getHtAll()/1.e3;
  m_ht_baseline = m_event_quantities.getHtBaseline()/1.e3;
  m_ht_good     = m_event_quantities.getHtGood()/1.e3;
  m_ht_signal   = m_event_quantities.getHtSignal()/1.e3;

  m_pt_l_0 = bl_0->getLepton()->getPt();
  m_pt_l_1 = bl_1->getLepton()->getPt();
  m_pt_b_0 = bl_0->getJet()->getPt();
  m_pt_b_1 = bl_1->getJet()->getPt();

  m_dphi_bl_0 = bl_0->getDphi();
  m_dphi_bl_1 = bl_1->getDphi();

  m_deta_bl_0 = bl_0->getDeta();
  m_deta_bl_1 = bl_1->getDeta();

  m_dr_bl_0 = bl_0->getDr();
  m_dr_bl_1 = bl_1->getDr();

  float phi_l_0   = bl_0->getLepton()->getPhi();
  float phi_l_1   = bl_1->getLepton()->getPhi();

  float eta_l_0   = bl_0->getLepton()->getEta();
  float eta_l_1   = bl_1->getLepton()->getEta();

  m_dphi_ll = PennSusyFrame::calcDphi(phi_l_0, phi_l_1);
  m_deta_ll = fabs(eta_l_0 - eta_l_1);
  m_dr_ll = sqrt(m_dphi_ll*m_dphi_ll + m_deta_ll*m_deta_ll);

  float phi_b_0   = bl_0->getJet()->getPhi();
  float phi_b_1   = bl_1->getJet()->getPhi();

  float eta_b_0   = bl_0->getJet()->getEta();
  float eta_b_1   = bl_1->getJet()->getEta();

  m_dphi_bb = PennSusyFrame::calcDphi(phi_b_0, phi_b_1);
  m_deta_bb = fabs(eta_b_0 - eta_b_1);
  m_dr_bb   = sqrt(m_dphi_bb*m_dphi_bb + m_deta_bb*m_deta_bb);

  // fill output tree
  m_output_tree->Fill();
}