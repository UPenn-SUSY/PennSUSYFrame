#include "BMinusLAnalysis/include/BMinusLAnalysis.h"
#include "BMinusLAnalysis/include/BMinusLUtils.h"
#include "BMinusLAnalysis/include/BMinusLHistogramHandlers.h"
#include "PennSusyFrameCore/include/PennSusyFrameCore.h"

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
                                                             , m_crit_cut_b_jets(false)
                                                             , m_crit_cut_z_veto(false)
                                                             , m_crit_cut_met(false)
                                                             , m_bl_0(0)
                                                             , m_bl_1(0)
                                                             , m_met_min(-1)
                                                             , m_met_max(-1)
                                                             , m_min_el_pt_baseline(20.e3)
                                                             , m_max_el_pt_baseline(-1)
                                                             , m_min_mu_pt_baseline(20.e3)
                                                             , m_max_mu_pt_baseline(-1)
                                                             , m_min_b_jet_pt_baseline(20.e3)
                                                             , m_max_b_jet_pt_baseline(-1)
                                                             , m_num_events_passing_basic_cleaning(0)
                                                             , m_num_events_passing_ge_2_lep(0)
                                                             , m_num_events_passing_2_lep(0)
                                                             , m_num_events_passing_signal_lep(0)
                                                             , m_num_events_passing_ge_2_b_jet(0)
                                                             , m_num_events_passing_eq_2_b_jet(0)
                                                             , m_num_events_passing_bl_pairing(0)
                                                             , m_num_events_passing_bl_pairing_but_not_lep_or_b(0)
{
}

// -----------------------------------------------------------------------------
PennSusyFrame::BMinusLAnalysis::~BMinusLAnalysis()
{
  size_t term_1 = m_bminusl_histogram_handler.size();
  for (size_t it_1 = 0; it_1 != term_1; ++it_1) {
    if ( m_bminusl_histogram_handler.at(it_1) ) {
      delete m_bminusl_histogram_handler.at(it_1);
      m_bminusl_histogram_handler.at(it_1) = 0;
    }
  }
}

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
  // m_electron_selectors.at(EL_BASELINE).setPtCut(20.e3, -1);
  m_electron_selectors.at(EL_BASELINE).setPtCut(m_min_el_pt_baseline, m_max_el_pt_baseline);
  m_electron_selectors.at(EL_BASELINE).setEtaCut(-1, 2.47);

  // EL_SIGNAL
  // m_electron_selectors.at(EL_SIGNAL).setElectronQuality(EL_QUALITY_TIGHTPP);
  m_electron_selectors.at(EL_SIGNAL).setElectronQuality(EL_QUALITY_MEDPP);
  m_electron_selectors.at(EL_SIGNAL).setD0SignificanceCut(-1, 3);
  m_electron_selectors.at(EL_SIGNAL).setZ0SignThetaCut(-1, 0.4);
  // m_electron_selectors.at(EL_SIGNAL).setPtIsoCut(-1, 0.13);
  // m_electron_selectors.at(EL_SIGNAL).setEtIsoCut(-1, 0.21);
  m_electron_selectors.at(EL_SIGNAL).setPtIsoCut(-1, -1);
  m_electron_selectors.at(EL_SIGNAL).setEtIsoCut(-1, -1);

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
  // m_muon_selectors.at(MU_SIGNAL).setPtIsoCut(-1, 0.11);
  // m_muon_selectors.at(MU_SIGNAL).setEtIsoCut(-1, 0.19);
  m_muon_selectors.at(MU_SIGNAL).setPtIsoCut(-1, -1);
  m_muon_selectors.at(MU_SIGNAL).setEtIsoCut(-1, -1);

  // JET_B
  m_jet_selectors.at(JET_B).setPtCut(m_min_b_jet_pt_baseline, m_max_b_jet_pt_baseline);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::beginRun()
{
  PennSusyFrameCore::beginRun();

  // prepare selection
  prepareSelection();

  m_histogram_handlers.resize(BMINUSL_HIST_N);

  for (unsigned int hist_level = 0; hist_level != BMINUSL_HIST_N; ++hist_level) {
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::EventLevelHists(      PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]) );
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::LeptonKinematicsHists(PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]) );
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::JetKinematicsHists(   PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]) );
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::MetHists(             PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]) );

    m_bminusl_histogram_handler.push_back(new PennSusyFrame::BMinusLHists(PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]));
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::initializeEvent()
{
  m_event_weight = 1.;

  m_pass_grl              = false;
  m_pass_incomplete_event = false;
  m_pass_lar_error        = false;
  m_pass_tile_error       = false;
  m_pass_tile_hot_spot    = false;
  m_pass_tile_trip        = false;
  m_pass_bad_jet_veto     = false;
  m_pass_calo_problem_jet = false;
  m_pass_primary_vertex   = false;
  m_pass_bad_mu_veto      = false;
  m_pass_cosmic_mu_veto   = false;
  m_pass_hfor             = false;
  m_pass_mc_overlap       = false;
  m_pass_ge_2_lep         = false;
  m_pass_2_lep            = false;
  m_pass_signal_lep       = false;
  m_pass_ge_2_b_jet       = false;
  m_pass_eq_2_b_jet       = false;
  m_pass_bl_pairing       = false;
  m_pass_z_veto           = false;
  m_pass_met              = false;

  if (m_bl_0 != 0) {
    delete m_bl_0;
    m_bl_0 = 0;
  }

  if (m_bl_1 != 0) {
    delete m_bl_1;
    m_bl_1 = 0;
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::processEvent()
{
  initializeEvent();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Fill cutflow trackers for "all events"
  m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_ALL);
  m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_ALL, m_event_weight);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set mc event weight
  m_event_weight *= m_event_quantities.getMcEventWeight();
  m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_MC_EVENT_WEIGHT);
  m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_MC_EVENT_WEIGHT, m_event_weight);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set pile up weight
  m_event_weight *= m_event_quantities.getPileUpSF();
  m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_PILEUP_WEIGHT);
  m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_PILEUP_WEIGHT, m_event_weight);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set cross section weight
  m_event_weight *= m_xsec_weight;
  m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_XSEC_WEIGHT);
  m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_XSEC_WEIGHT, m_event_weight);

  // -----------------------------------------------------------------------------
  m_event.setPhaseSpace(getPhaseSpace());

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // GRL cut
  // only check grl cut on data
  m_pass_grl = (!m_is_data || m_grl.passEvent(m_event));
  m_pass_event = (m_pass_event && m_pass_grl);
  if (m_crit_cut_grl && !m_pass_grl) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_GRL);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_GRL, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // incomplete event cut
  m_pass_incomplete_event = PennSusyFrame::passIncompleteEvent(m_event);
  m_pass_event = (m_pass_event && m_pass_incomplete_event);
  if (m_crit_cut_incomplete_event && !m_pass_incomplete_event) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_INCOMPLETE_EVENT);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_INCOMPLETE_EVENT, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // LAr error cut
  m_pass_lar_error = PennSusyFrame::passLarError(m_event);
  m_pass_event = (m_pass_event && m_pass_lar_error);
  if (m_crit_cut_lar_error && !m_pass_lar_error) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_LAR_ERROR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_LAR_ERROR, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile error cut
  m_pass_tile_error = PennSusyFrame::passTileError(m_event);
  m_pass_event = (m_pass_event && m_pass_tile_error);
  if (m_crit_cut_tile_error && !m_pass_tile_error) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_TILE_ERROR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_TILE_ERROR, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile hot spot cut
  m_pass_tile_hot_spot = PennSusyFrame::TileHotSpotTool::passTileHotSpot(m_event, m_jets);
  m_pass_event = (m_pass_event && m_pass_tile_hot_spot);
  if (m_crit_cut_tile_hot_spot && !m_pass_tile_hot_spot) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_TILE_HOT_SPOT);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_TILE_HOT_SPOT, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile trip cut
  m_pass_tile_trip = m_tile_trip_tool.passTileTrip(m_event);
  m_pass_event = (m_pass_event && m_pass_tile_trip);
  if (m_crit_cut_tile_trip && !m_pass_tile_trip) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_TILE_TRIP);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_TILE_TRIP, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // bad jet veto
  m_pass_bad_jet_veto = (m_jets.num(JET_BAD) == 0);
  m_pass_event = (m_pass_event && m_pass_bad_jet_veto);
  if (m_crit_cut_bad_jet_veto && !m_pass_bad_jet_veto) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_BAD_JET_VETO);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_BAD_JET_VETO, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // calo problem jet cut
  m_pass_calo_problem_jet = (m_jets.num(JET_CALO_PROBLEM) == 0);
  m_pass_event = (m_pass_event && m_pass_calo_problem_jet);
  if (m_crit_cut_calo_problem_jet && !m_pass_calo_problem_jet) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_CALO_PROBLEM_JET);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_CALO_PROBLEM_JET, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // primary vertex cut
  m_pass_primary_vertex = PennSusyFrame::passPrimaryVertex(m_vertices);
  m_pass_event = (m_pass_event && m_pass_primary_vertex);
  if (m_crit_cut_primary_vertex && !m_pass_primary_vertex) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_PRIMARY_VERTEX);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_PRIMARY_VERTEX, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // bad muon cut
  m_pass_bad_mu_veto = (m_muons.num(MU_BAD) == 0);
  m_pass_event = (m_pass_event && m_pass_bad_mu_veto);
  if (m_crit_cut_bad_mu_veto && !m_pass_bad_mu_veto) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_BAD_MUON);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_BAD_MUON, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // cosmic muon veto
  m_pass_cosmic_mu_veto = (m_muons.num(MU_COSMIC) == 0);
  m_pass_event = (m_pass_event && m_pass_cosmic_mu_veto);
  if (m_crit_cut_cosmic_mu_veto && !m_pass_cosmic_mu_veto) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_COSMIC_MUON_VETO);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_COSMIC_MUON_VETO, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // HFOR cut
  m_pass_hfor = m_hfor_tool.passHFOR(m_mc_truth);
  m_pass_event = (m_pass_event && m_pass_hfor);
  if (m_crit_cut_hfor && !m_pass_hfor) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_HFOR);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_HFOR, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // mc overlap cut
  m_pass_mc_overlap = (  PennSusyFrame::passSherpaWWOverlapRemoval(m_event, m_mc_truth)
                         && PennSusyFrame::passZOverlapRemoval(m_mc_truth)
                         );
  m_pass_event = (m_pass_event && m_pass_mc_overlap);
  if (m_crit_cut_mc_overlap && !m_pass_mc_overlap) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_MC_OVERLAP);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_MC_OVERLAP, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get number of good leptons
  int num_good_leptons = m_electrons.num(EL_SELECTED) + m_muons.num(MU_SELECTED);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // >= 2 baseline leptons cut
  m_pass_ge_2_lep = (num_good_leptons >= 2);
  m_pass_event = (m_pass_event && m_pass_ge_2_lep);
  if (m_crit_cut_ge_2_lep && !m_pass_ge_2_lep) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_GE_2_BASELINE_LEPTONS);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_GE_2_BASELINE_LEPTONS, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // == 2 baseline leptons cut
  // m_pass_2_lep = (num_good_leptons == 2);
  m_pass_2_lep = (num_good_leptons >= 2);
  m_pass_event = (m_pass_event && m_pass_2_lep);
  if (m_crit_cut_2_lep && !m_pass_2_lep) return;
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
  // m_pass_signal_lep = (num_signal_leptons == 2);
  m_pass_signal_lep = (num_signal_leptons >= 2);
  m_pass_event = (m_pass_event && m_pass_signal_lep);
  if (m_crit_cut_signal_lep && !m_pass_signal_lep) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_EQ_2_SIGNAL_LEPTON);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_EQ_2_SIGNAL_LEPTON, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // lepton scale factor
  m_event_weight *= m_event_quantities.getLeptonSF();
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_LEP_SF);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_LEP_SF, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), BMINUSL_CUT_LEP_SF);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), BMINUSL_CUT_LEP_SF, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get number of b jets
  int num_b_jets = m_jets.num(JET_B);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // check number of b jets >= 2
  m_pass_ge_2_b_jet = (num_b_jets >= 2);
  m_pass_event = (m_pass_event && m_pass_ge_2_b_jet);
  if (m_crit_cut_b_jets && ! m_pass_ge_2_b_jet) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_GE_2_B_JET);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_GE_2_B_JET, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), BMINUSL_CUT_GE_2_B_JET);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), BMINUSL_CUT_GE_2_B_JET, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // check number of b jets == 2
  m_pass_eq_2_b_jet = (num_b_jets == 2);
  // m_pass_eq_2_b_jet = (num_b_jets >= 2);
  m_pass_event = (m_pass_event && m_pass_eq_2_b_jet);
  if (m_crit_cut_b_jets && ! m_pass_eq_2_b_jet) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_EQ_2_B_JET);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_EQ_2_B_JET, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), BMINUSL_CUT_EQ_2_B_JET);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), BMINUSL_CUT_EQ_2_B_JET, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // b tag sf
  m_event_weight *= m_event_quantities.getBTagSF();
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_B_TAG_SF);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_B_TAG_SF, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), BMINUSL_CUT_B_TAG_SF);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), BMINUSL_CUT_B_TAG_SF, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do b-l pairing
  m_bl_0 = new PennSusyFrame::blPair();
  m_bl_1 = new PennSusyFrame::blPair();

  m_pass_bl_pairing = PennSusyFrame::doBLPairing( m_event
                                                , m_electrons.getCollection(EL_SELECTED)
                                                , m_muons.getCollection(MU_SELECTED)
                                                , m_jets.getCollection(JET_B)
                                                , *m_bl_0
                                                , *m_bl_1
                                                );
  m_pass_event = (m_pass_event && m_pass_bl_pairing);
  if (m_crit_cut_bl_pairing && !m_pass_bl_pairing) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_BL_PAIRING);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_BL_PAIRING, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), BMINUSL_CUT_BL_PAIRING);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), BMINUSL_CUT_BL_PAIRING, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do z veto fo SFOS lepton pairs
  m_pass_z_veto = true;
  if (  m_event.getFlavorChannel() == FLAVOR_EE
     || m_event.getFlavorChannel() == FLAVOR_MM
     ) {
    m_pass_z_veto = ( fabs(m_event_quantities.getMll() - 91.e3) > 10.e3 );
  }
  m_pass_event = (m_pass_event && m_pass_z_veto);
  if (m_crit_cut_z_veto && !m_pass_z_veto) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_ZVETO);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_ZVETO, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), BMINUSL_CUT_ZVETO);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), BMINUSL_CUT_ZVETO, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Apply met cut
  m_pass_met = ( PennSusyFrame::passCut( m_met.getMetEt()
                                          , m_met_min
                                          , m_met_max
                                          )
                  );
  m_pass_event = (m_pass_event && m_pass_met);
  if (m_crit_cut_met && !m_pass_met) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_MET);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_MET, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), BMINUSL_CUT_MET);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), BMINUSL_CUT_MET, m_event_weight);
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::finalizeEvent()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // fill histograms for BASIC_CLEANING hist level
  if (  m_pass_grl
     && m_pass_incomplete_event
     && m_pass_lar_error
     && m_pass_tile_error
     && m_pass_tile_hot_spot
     && m_pass_tile_trip
     && m_pass_bad_jet_veto
     && m_pass_calo_problem_jet
     && m_pass_primary_vertex
     && m_pass_bad_mu_veto
     && m_pass_cosmic_mu_veto
     && m_pass_hfor
     && m_pass_mc_overlap
     // && m_pass_ge_2_lep
     // && m_pass_2_lep
     // && m_pass_signal_lep
     // && m_pass_ge_2_b_jet
     // && m_pass_eq_2_b_jet
     // && m_pass_bl_pairing
     // && m_pass_z_veto
     // && m_pass_met
     ) {
    fillHistHandles( PennSusyFrame::BMINUSL_HIST_BASIC_CLEANING
                   , m_bl_0
                   , m_bl_1
                   , m_event_weight
                   );
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // fill histograms for BL_PAIRING hist level
  if (  m_pass_grl
     && m_pass_incomplete_event
     && m_pass_lar_error
     && m_pass_tile_error
     && m_pass_tile_hot_spot
     && m_pass_tile_trip
     && m_pass_bad_jet_veto
     && m_pass_calo_problem_jet
     && m_pass_primary_vertex
     && m_pass_bad_mu_veto
     && m_pass_cosmic_mu_veto
     && m_pass_hfor
     && m_pass_mc_overlap
     && m_pass_ge_2_lep
     && m_pass_2_lep
     && m_pass_signal_lep
     && m_pass_ge_2_b_jet
     && m_pass_eq_2_b_jet
     && m_pass_bl_pairing
     // && m_pass_z_veto
     // && m_pass_met
     ) {
    fillHistHandles( PennSusyFrame::BMINUSL_HIST_BL_PAIRING
                   , m_bl_0
                   , m_bl_1
                   , m_event_weight
                   );
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // fill histograms for ZVETO hist level
  if (  m_pass_grl
     && m_pass_incomplete_event
     && m_pass_lar_error
     && m_pass_tile_error
     && m_pass_tile_hot_spot
     && m_pass_tile_trip
     && m_pass_bad_jet_veto
     && m_pass_calo_problem_jet
     && m_pass_primary_vertex
     && m_pass_bad_mu_veto
     && m_pass_cosmic_mu_veto
     && m_pass_hfor
     && m_pass_mc_overlap
     && m_pass_ge_2_lep
     && m_pass_2_lep
     && m_pass_signal_lep
     && m_pass_ge_2_b_jet
     && m_pass_eq_2_b_jet
     && m_pass_bl_pairing
     && m_pass_z_veto
     // && m_pass_met
     ) {
    fillHistHandles( PennSusyFrame::BMINUSL_HIST_ZVETO
                   , m_bl_0
                   , m_bl_1
                   , m_event_weight
                   );
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // fill histograms for MET hist level
  if (  m_pass_grl
     && m_pass_incomplete_event
     && m_pass_lar_error
     && m_pass_tile_error
     && m_pass_tile_hot_spot
     && m_pass_tile_trip
     && m_pass_bad_jet_veto
     && m_pass_calo_problem_jet
     && m_pass_primary_vertex
     && m_pass_bad_mu_veto
     && m_pass_cosmic_mu_veto
     && m_pass_hfor
     && m_pass_mc_overlap
     && m_pass_ge_2_lep
     && m_pass_2_lep
     && m_pass_signal_lep
     && m_pass_ge_2_b_jet
     && m_pass_eq_2_b_jet
     && m_pass_bl_pairing
     && m_pass_z_veto
     && m_pass_met
     ) {
    fillHistHandles( PennSusyFrame::BMINUSL_HIST_MET
                   , m_bl_0
                   , m_bl_1
                   , m_event_weight
                   );
  }


  if (  m_pass_grl
     && m_pass_incomplete_event
     && m_pass_lar_error
     && m_pass_tile_error
     && m_pass_tile_hot_spot
     && m_pass_tile_trip
     && m_pass_bad_jet_veto
     && m_pass_calo_problem_jet
     && m_pass_primary_vertex
     && m_pass_bad_mu_veto
     && m_pass_cosmic_mu_veto
     && m_pass_hfor
     && m_pass_mc_overlap
     ) {
    // if (!m_pass_bl_pairing) {
    //   size_t num_good_leptons     = m_electrons.num(EL_GOOD)     + m_muons.num(MU_GOOD);
    //   size_t num_selected_leptons = m_electrons.num(EL_SELECTED) + m_muons.num(MU_SELECTED);
    //   size_t num_signal_leptons   = m_electrons.num(EL_SIGNAL)   + m_muons.num(MU_SIGNAL);
    //   size_t num_b_jets           = m_jets.num(JET_B);
    //   size_t num_good_jets        = m_jets.num(JET_GOOD);
    //   size_t num_selected_jets    = m_jets.num(JET_SELECTED);
    //   size_t num_central_jets     = m_jets.num(JET_ALL_CENTRAL);
    //   // std::cout << "\n\tEvent " << m_event.getEventNumber() << " passed basic cleaning, but not bl pairing"
    //   //           << "\n\t\tpass_ge_2_lep  : " << m_pass_ge_2_lep   << " -- num good leptons: " << num_good_leptons
    //   //           << "\n\t\tpass_2_lep     : " << m_pass_2_lep      << " -- num good leptons: " << num_good_leptons
    //   //           << "\n\t\tpass_signal_lep: " << m_pass_signal_lep << " -- num signal leptons: " << num_signal_leptons
    //   //           << "\n\t\tpass_ge_2_b_jet: " << m_pass_ge_2_b_jet << " -- num b jets: " << num_b_jets << " -- num good jets: " << num_good_jets << " -- num selected jets: " << num_selected_jets << " -- num central jets: " << num_central_jets
    //   //           << "\n\t\tpass_eq_2_b_jet: " << m_pass_eq_2_b_jet << " -- num b jets: " << num_b_jets << " -- num good jets: " << num_good_jets << " -- num selected jets: " << num_selected_jets << " -- num central jets: " << num_central_jets
    //   //           << "\n\t\tpass_bl_pairing: " << m_pass_bl_pairing
    //   //           << "\n\n";
    //   // // if (!m_pass_ge_2_b_jet) {
    //   // //   std::cout << "\tsomething wrong with our jets:\n";
    //   // //   m_jets.print(JET_ALL);
    //   // //   m_jets.print(JET_BASELINE_GOOD);
    //   // //   m_jets.print(JET_GOOD);
    //   // //   m_jets.print(JET_SELECTED);
    //   // //   m_jets.print(JET_LIGHT);
    //   // //   m_jets.print(JET_B);

    //   // //   m_electrons.print(EL_ALL);
    //   // //   m_electrons.print(EL_BASELINE);
    //   // //   m_electrons.print(EL_GOOD);
    //   // //   m_electrons.print(EL_SELECTED);
    //   // //   m_electrons.print(EL_SIGNAL);

    //   // //   m_muons.print(MU_ALL);
    //   // //   m_muons.print(MU_BASELINE);
    //   // //   m_muons.print(MU_GOOD);
    //   // //   m_muons.print(MU_SELECTED);
    //   // //   m_muons.print(MU_SIGNAL);
    //   // //   std::cout << "\n";
    //   // // }
    // }

    ++m_num_events_passing_basic_cleaning;
    if (m_pass_ge_2_lep  ) ++m_num_events_passing_ge_2_lep;
    if (m_pass_2_lep     ) ++m_num_events_passing_2_lep;
    if (m_pass_signal_lep) ++m_num_events_passing_signal_lep;
    if (m_pass_ge_2_b_jet) ++m_num_events_passing_ge_2_b_jet;
    if (m_pass_eq_2_b_jet) ++m_num_events_passing_eq_2_b_jet;
    if (m_pass_bl_pairing) ++m_num_events_passing_bl_pairing;

    if (m_pass_bl_pairing && (!m_pass_2_lep || !m_pass_ge_2_b_jet))
      ++m_num_events_passing_bl_pairing_but_not_lep_or_b;
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::finalizeRun()
{
  std::cout << "BMinusLAnalysis::finalizeRun()\n";
  std::cout << "creating output histogram file\n";
  TFile out_hist_file(m_out_hist_file_name.c_str(), "RECREATE");

  m_d3pd_reader->writeNumEvents();

  // TDirectory* hist_dir = out_hist_file.mkdir("hists");

  std::cout << "about to write histograms to file\n";
  for ( unsigned int hist_level = 0
      ; hist_level != BMINUSL_HIST_N
      ; ++hist_level
      ) {
    TDirectory* hist_dir_cut_level = out_hist_file.mkdir(PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level].c_str());

    size_t num_hists = m_histogram_handlers.at(hist_level).size();
    for (size_t hist_it = 0; hist_it != num_hists; ++hist_it) {
      std::cout << "\twriting histogram handler " << hist_it << " to file\n";
      m_histogram_handlers.at(hist_level).at(hist_it)->write(hist_dir_cut_level);
    }

    m_bminusl_histogram_handler.at(hist_level)->write(hist_dir_cut_level);
  }
  std::cout << "done writing histograms to file\n";

  out_hist_file.Close();
  std::cout << "file is closed!\n";

  m_raw_cutflow_tracker.printToScreen();
  m_cutflow_tracker.printToScreen();

  std::cout << "\nnum events passing basic cleaning: " << m_num_events_passing_basic_cleaning
            << "\nnum events passing >= 2 lep: "       << m_num_events_passing_ge_2_lep   << " :: " << float(m_num_events_passing_ge_2_lep  ) / m_num_events_passing_basic_cleaning
            << "\nnum events passing 2 lep: "          << m_num_events_passing_2_lep      << " :: " << float(m_num_events_passing_2_lep     ) / m_num_events_passing_basic_cleaning
            << "\nnum events passing signal lep: "     << m_num_events_passing_signal_lep << " :: " << float(m_num_events_passing_signal_lep) / m_num_events_passing_basic_cleaning
            << "\nnum events passing >= 2 b jets: "    << m_num_events_passing_ge_2_b_jet << " :: " << float(m_num_events_passing_ge_2_b_jet) / m_num_events_passing_basic_cleaning
            << "\nnum events passing 2 b jets: "       << m_num_events_passing_eq_2_b_jet << " :: " << float(m_num_events_passing_eq_2_b_jet) / m_num_events_passing_basic_cleaning
            << "\nnum events passing bl pairing: "     << m_num_events_passing_bl_pairing << " :: " << float(m_num_events_passing_bl_pairing) / m_num_events_passing_basic_cleaning
            << "\nnum events passing bl pairing when it should not: " << m_num_events_passing_bl_pairing_but_not_lep_or_b << " :: " << float(m_num_events_passing_bl_pairing_but_not_lep_or_b) / m_num_events_passing_basic_cleaning
            << "\n\n";

}

// -----------------------------------------------------------------------------
PHASE_SPACE PennSusyFrame::BMinusLAnalysis::getPhaseSpace()
{
  if (m_event.getFlavorChannel() == FLAVOR_EE) return PHASE_EE;
  if (m_event.getFlavorChannel() == FLAVOR_MM) return PHASE_MM;
  if (m_event.getFlavorChannel() == FLAVOR_EM) {
    float pt_e = m_electrons.getCollection(EL_SELECTED)->at(0)->getPt();
    float pt_m = m_muons.getCollection(    MU_SELECTED)->at(0)->getPt();
    if (pt_e >= pt_m) return PHASE_EM;
    return PHASE_ME;
  }

  return PHASE_NONE;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::getSelectedObjects()
{
  // select highest pt leptons
  const std::vector<PennSusyFrame::Electron*>* good_el_list = m_electrons.getCollection(EL_GOOD);
  const std::vector<PennSusyFrame::Muon*>*     good_mu_list = m_muons.getCollection(MU_GOOD);

  size_t num_good_el = good_el_list->size();
  size_t num_good_mu = good_mu_list->size();

  std::vector<PennSusyFrame::Electron*> selected_el_list;
  std::vector<PennSusyFrame::Muon*>     selected_mu_list;
  selected_el_list.reserve(std::min(static_cast<size_t>(2), num_good_el));
  selected_mu_list.reserve(std::min(static_cast<size_t>(2), num_good_mu));

  if (num_good_el + num_good_mu >= 2) {
    if (num_good_mu == 0) {
      selected_el_list.push_back(good_el_list->at(0));
      selected_el_list.push_back(good_el_list->at(1));
    }
    else if (num_good_el == 0) {
      selected_mu_list.push_back(good_mu_list->at(0));
      selected_mu_list.push_back(good_mu_list->at(1));
    }
    else if (num_good_el == 0) {
      selected_mu_list.push_back(good_mu_list->at(0));
      selected_mu_list.push_back(good_mu_list->at(1));
    }
    else {
      size_t next_el = 0;
      size_t next_mu = 0;
      size_t num_leps_stored = 0;

      float el_pt = -1;
      float mu_pt = -1;
      size_t num_it = 0;
      while (  num_leps_stored < 2
            && num_it < 10
            && (  next_el < num_good_el
               || next_mu < num_good_mu
               )
            ) {
        // get the next electron and muon pt values
        el_pt = ((next_el < num_good_el) ? good_el_list->at(next_el)->getPt() : -1);
        mu_pt = ((next_mu < num_good_mu) ? good_mu_list->at(next_mu)->getPt() : -1);

        if (el_pt >= mu_pt) {
          // if next electron is harder than next muon, add that to lepton list
          selected_el_list.push_back(good_el_list->at(next_el));
          ++next_el;
        }
        else {
          // if muon is harder than electron, add that to lepton list
          selected_mu_list.push_back(good_mu_list->at(next_mu));
          ++next_mu;
        }
        ++num_leps_stored;
      }
      // std::cout << "num selected leptons: " << num_leps_stored
      //           << " -- num good electrons: " << num_good_el
      //           << " -- num good muons: " << num_good_mu
      //           << " -- next el: " << next_el
      //           << " -- next mu: " << next_mu
      //           << " -- next mu: " << next_mu
      //           << "\n";

      if (num_leps_stored < 2) {
        selected_el_list.clear();
        selected_mu_list.clear();
      }
    }
  }

  m_electrons.setCollection(EL_SELECTED , selected_el_list);
  m_muons.setCollection(    MU_SELECTED , selected_mu_list);

  // simply copy the good jets and taus
  std::vector<PennSusyFrame::Jet*> good_jet_list(*m_jets.getCollection(JET_GOOD));
  m_jets.setCollection(JET_SELECTED , good_jet_list);

  std::vector<PennSusyFrame::Tau*> good_tau_list(*m_taus.getCollection(TAU_GOOD));
  m_taus.setCollection(TAU_SELECTED , good_tau_list);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::fillHistHandles( PennSusyFrame::BMINUSL_HIST_LEVELS hist_level
                                                    , const PennSusyFrame::blPair* bl_0
                                                    , const PennSusyFrame::blPair* bl_1
                                                    , float weight
                                                    )
{
  size_t num_hists = m_histogram_handlers.at(hist_level).size();
  for (size_t hist_it = 0; hist_it != num_hists; ++hist_it) {
    m_histogram_handlers.at(hist_level).at(hist_it)->Fill( m_event
                                                         , m_event_quantities
                                                         , m_electrons.getCollection(EL_SELECTED)
                                                         , m_muons.getCollection(MU_SELECTED)
                                                         , m_jets.getCollection(JET_SELECTED)
                                                         , m_met
                                                         , weight
                                                         );
  }

  if (m_pass_bl_pairing) {
    m_bminusl_histogram_handler.at(hist_level)->FillSpecial( m_event
                                                           , m_jets.getCollection(JET_B)
                                                           , *bl_0
                                                           , *bl_1
                                                           , m_mc_truth
                                                           , weight
                                                           );
  }
}
