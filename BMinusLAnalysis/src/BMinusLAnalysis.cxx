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
  // m_electron_selectors.at(EL_BASELINE).setEtaCut(-1, 2.47);

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
  // m_muon_selectors.at(MU_BASELINE).setEtaCut(-1, 2.5);
  // m_muon_selectors.at(MU_BASELINE).setBLayerHitsCut(1, -1);
  // m_muon_selectors.at(MU_BASELINE).setPixelHitsCut(1, -1);
  // m_muon_selectors.at(MU_BASELINE).setSctHitsCut(5, -1);
  // m_muon_selectors.at(MU_BASELINE).setSiHolesCut(-1, 2);
  // m_muon_selectors.at(MU_BASELINE).setTrtEtaCut(0.1, 1.9);
  // m_muon_selectors.at(MU_BASELINE).setTrtHitsCut(6, -1);
  // m_muon_selectors.at(MU_BASELINE).setTrtOlFractionCut(-1, 0.9);

  // MU_SIGNAL
  // m_muon_selectors.at(MU_SIGNAL).setEtaCut(-1, 2.4);
  m_muon_selectors.at(MU_SIGNAL).setD0SignificanceCut(-1, 3.);
  m_muon_selectors.at(MU_SIGNAL).setZ0SignThetaCut(-1, 1.);
  // m_muon_selectors.at(MU_SIGNAL).setPtIsoCut(-1, 0.11);
  // m_muon_selectors.at(MU_SIGNAL).setEtIsoCut(-1, 0.19);
  m_muon_selectors.at(MU_SIGNAL).setPtIsoCut(-1, -1);
  m_muon_selectors.at(MU_SIGNAL).setEtIsoCut(-1, -1);

  // JET_B
  // m_jet_selectors.at(JET_BASELINE).setPtCut(m_min_b_jet_pt_baseline, m_max_b_jet_pt_baseline);
  m_jet_selectors.at(JET_BASELINE).setPtCut(std::min(40.e3, m_min_b_jet_pt_baseline), -1);

  m_jet_selectors.at(JET_B).setPtCut(m_min_b_jet_pt_baseline, m_max_b_jet_pt_baseline);

  // TAU_BASELINE -- we don't want taus
  m_tau_selectors.at(TAU_BASELINE).setPtCut(1.e10, 1.e10+1);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::beginRun()
{
  PennSusyFrameCore::beginRun();

  // prepare selection
  prepareSelection();

  m_histogram_handlers.resize(BMINUSL_HIST_N);

  for (unsigned int hist_level = 0; hist_level != BMINUSL_HIST_N; ++hist_level) {
    std::cout << "creating histograms with hist level: " << hist_level << " -- " << PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level] << "\n";
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::EventLevelHists(      PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]) );
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::LeptonKinematicsHists(PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]) );
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::JetKinematicsHists(   PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]) );
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::MetHists(             PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]) );

    m_bminusl_histogram_handler.push_back(         new PennSusyFrame::BMinusLHists(        PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]));
    m_bminusl_detailed_histogram_handler.push_back(new PennSusyFrame::BMinusLDetailedHists(PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]));
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::initializeEvent()
{
  m_event_weight    = 1.;
  m_mc_event_weight = 1.;
  m_pile_up_sf      = 1.;
  m_lepton_sf       = 1.;
  m_btag_sf         = 1.;

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
  m_mc_event_weight = m_event_quantities.getMcEventWeight();
  m_event_weight *= m_mc_event_weight;
  m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_MC_EVENT_WEIGHT);
  m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_MC_EVENT_WEIGHT, m_event_weight);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set pile up weight
  m_pile_up_sf = m_event_quantities.getPileUpSF();
  m_event_weight *= m_pile_up_sf;
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
  m_lepton_sf = m_event_quantities.getLeptonSF();
  m_event_weight *= m_lepton_sf;
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
  // m_pass_event = (m_pass_event && m_pass_eq_2_b_jet);
  if (m_crit_cut_b_jets && ! m_pass_eq_2_b_jet) return;
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, BMINUSL_CUT_EQ_2_B_JET);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, BMINUSL_CUT_EQ_2_B_JET, m_event_weight);

    m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), BMINUSL_CUT_EQ_2_B_JET);
    m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), BMINUSL_CUT_EQ_2_B_JET, m_event_weight);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // b tag sf
  m_btag_sf = m_event_quantities.getBTagSF();
  m_event_weight *= m_btag_sf;
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
                                                // , m_jets.getCollection(JET_B)
                                                , m_jets.getCollection(JET_SELECTED)
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
                   , ( m_mc_event_weight
                     * m_pile_up_sf
                     * m_xsec_weight
                     // * m_lepton_sf
                     // * m_btag_sf
                     )
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
     // && m_pass_eq_2_b_jet
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
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
    // fill histograms for GE_4_OBJECTS hist level
  fillHistHandles( PennSusyFrame::BMINUSL_HIST_GE_4_OBJECTS
		   , m_bl_0
		   , m_bl_1
		   , m_event_weight
		   );

//}

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
     // && m_pass_eq_2_b_jet
     && m_pass_bl_pairing
     && m_pass_z_veto
     // && m_pass_met
     ) {
    // std::cout << "finalizeEvent():"
    //           << "\n\tevent: "             << m_event.getEventNumber()
    //           << "\n\tweight: "            << m_event_weight
    //           << "\n\t\tmc event weight: " << m_mc_event_weight
    //           << "\n\t\tpile up sf: "      << m_pile_up_sf
    //           << "\n\t\tx-sec weight: "    << m_xsec_weight
    //           << "\n\t\tlepton sf: "       << m_lepton_sf
    //           << "\n\t\tb-tag sf: "        << m_btag_sf
    //           << "\n\tmbl 0: mbl_0: "      << m_bl_0->getMbl()
    //           << "\n\tmbl 0: mbl_0: "      << m_bl_1->getMbl()
    //           << "\n\tht baseline: "       << m_event_quantities.getHtBaseline()
    //           << "\n\tmet et: "            << m_met.getMetEt()
    //           << "\n\tmet sig: "           << m_met.getMetSigBaseline()
    //           << "\n";


    fillHistHandles( PennSusyFrame::BMINUSL_HIST_ZVETO
                   , m_bl_0
                   , m_bl_1
                   , m_event_weight
                   );
  }

  // // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // // fill histograms for MET hist level
  // if (  m_pass_grl
  //    && m_pass_incomplete_event
  //    && m_pass_lar_error
  //    && m_pass_tile_error
  //    && m_pass_tile_hot_spot
  //    && m_pass_tile_trip
  //    && m_pass_bad_jet_veto
  //    && m_pass_calo_problem_jet
  //    && m_pass_primary_vertex
  //    && m_pass_bad_mu_veto
  //    && m_pass_cosmic_mu_veto
  //    && m_pass_hfor
  //    && m_pass_mc_overlap
  //    && m_pass_ge_2_lep
  //    && m_pass_2_lep
  //    && m_pass_signal_lep
  //    && m_pass_ge_2_b_jet
  //    // && m_pass_eq_2_b_jet
  //    && m_pass_bl_pairing
  //    && m_pass_z_veto
  //    && m_pass_met
  //    ) {
  //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_MET
  //                  , m_bl_0
  //                  , m_bl_1
  //                  , m_event_weight
  //                  );
  // }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // fill histograms in signal regions (and N-1 plots)
  // first, do a baseline cut
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
     // && m_pass_eq_2_b_jet
     && m_pass_bl_pairing
     && m_pass_z_veto
     ) {
    double mbl_asym = (m_bl_0->getMbl() - m_bl_1->getMbl()) / (m_bl_0->getMbl() + m_bl_1->getMbl());
    double ht = m_event_quantities.getHtBaseline() / 1.e3;
    double met_sig = m_met.getMetSigBaseline();

    bool pass_sr_900_mbl     = (mbl_asym < 0.27 );
    bool pass_sr_900_ht      = (ht       > 1854 );
    bool pass_sr_900_met_sig = (met_sig  < 6.48*10*sqrt(10) );

    bool pass_sr_1000_mbl         = (mbl_asym < 0.50  );
    bool pass_sr_1000_ht          = (ht       > 2189  );
    bool pass_sr_1000_met_sig     = (met_sig  < 29.83 );
    bool pass_sr_1000_mod_met_sig = (met_sig  < 6.48*10*sqrt(10)  );

    bool pass_sr_900_1000_v1_mbl     = (mbl_asym < 0.50 );
    bool pass_sr_900_1000_v1_ht      = (ht       > 2000 );
    bool pass_sr_900_1000_v1_met_sig = (met_sig  < 6.5*10*sqrt(10));

    bool pass_sr_900_1000_v2_mbl     = (mbl_asym < 0.60);
    bool pass_sr_900_1000_v2_ht      = (ht       > 2000);
    bool pass_sr_900_1000_v2_met_sig = (met_sig  < 6.5*10*sqrt(10));

    bool pass_sr_900_1000_v3_mbl     = (mbl_asym < 0.50);
    bool pass_sr_900_1000_v3_ht      = (ht       > 2000);
    bool pass_sr_900_1000_v3_met_sig = (met_sig  < 6.5*10*sqrt(10));

    // // fill various regions from 900 gev optimization
    // if (pass_sr_900_mbl) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_MBL
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (pass_sr_900_ht) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_HT
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (pass_sr_900_met_sig) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_MET
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_900_mbl
    //    && pass_sr_900_ht
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_MBL_HT
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_900_mbl
    //    && pass_sr_900_met_sig
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_MBL_MET
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_900_ht
    //    && pass_sr_900_met_sig
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_HT_MET
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_900_mbl
    //    && pass_sr_900_ht
    //    && pass_sr_900_met_sig
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }

    // // fill various regions from 1000 gev optimization
    // if (pass_sr_1000_mbl) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_1000_MBL
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (pass_sr_1000_ht) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_1000_HT
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (pass_sr_1000_met_sig) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_1000_MET
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_1000_mbl
    //    && pass_sr_1000_ht
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_1000_MBL_HT
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_1000_mbl
    //    && pass_sr_1000_met_sig
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_1000_MBL_MET
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_1000_ht
    //    && pass_sr_1000_met_sig
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_1000_HT_MET
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_1000_mbl
    //    && pass_sr_1000_ht
    //    && pass_sr_1000_met_sig
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_1000
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }

    // // fill various regions from 1000 gev optimization (with modified met cut
    // if (pass_sr_1000_mod_met_sig) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_1000_MOD_MET
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_1000_mbl
    //    && pass_sr_1000_mod_met_sig
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_1000_MOD_MBL_MET
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_1000_ht
    //    && pass_sr_1000_mod_met_sig
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_1000_MOD_HT_MET
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_1000_mbl
    //    && pass_sr_1000_ht
    //    && pass_sr_1000_mod_met_sig
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_1000_MOD
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }

    // fill various regions from 1000_v1 gev optimization
    if (pass_sr_900_1000_v1_mbl) {
      fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V1_MBL
                     , m_bl_0
                     , m_bl_1
                     , m_event_weight
                     );
    }
    if (pass_sr_900_1000_v1_ht) {
      fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V1_HT
                     , m_bl_0
                     , m_bl_1
                     , m_event_weight
                     );
    }
    if (pass_sr_900_1000_v1_met_sig) {
      fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V1_MET
                     , m_bl_0
                     , m_bl_1
                     , m_event_weight
                     );
    }
    if (  pass_sr_900_1000_v1_mbl
       && pass_sr_900_1000_v1_ht
       ) {
      fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V1_MBL_HT
                     , m_bl_0
                     , m_bl_1
                     , m_event_weight
                     );
    }
    if (  pass_sr_900_1000_v1_mbl
       && pass_sr_900_1000_v1_met_sig
       ) {
      fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V1_MBL_MET
                     , m_bl_0
                     , m_bl_1
                     , m_event_weight
                     );
    }
    if (  pass_sr_900_1000_v1_ht
       && pass_sr_900_1000_v1_met_sig
       ) {
      fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V1_HT_MET
                     , m_bl_0
                     , m_bl_1
                     , m_event_weight
                     );
    }
    if (  pass_sr_900_1000_v1_mbl
       && pass_sr_900_1000_v1_ht
       && pass_sr_900_1000_v1_met_sig
       ) {
      fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V1
                     , m_bl_0
                     , m_bl_1
                     , m_event_weight
                     );
    }


    // // fill various regions from 1000_v2 gev optimization
    // if (pass_sr_900_1000_v2_mbl) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V2_MBL
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (pass_sr_900_1000_v2_ht) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V2_HT
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (pass_sr_900_1000_v2_met_sig) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V2_MET
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_900_1000_v2_mbl
    //    && pass_sr_900_1000_v2_ht
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V2_MBL_HT
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_900_1000_v2_mbl
    //    && pass_sr_900_1000_v2_met_sig
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V2_MBL_MET
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_900_1000_v2_ht
    //    && pass_sr_900_1000_v2_met_sig
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V2_HT_MET
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_900_1000_v2_mbl
    //    && pass_sr_900_1000_v2_ht
    //    && pass_sr_900_1000_v2_met_sig
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V2
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }


    // // fill various regions from 1000_v3 gev optimization
    // if (pass_sr_900_1000_v3_mbl) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V3_MBL
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (pass_sr_900_1000_v3_ht) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V3_HT
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (pass_sr_900_1000_v3_met_sig) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V3_MET
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_900_1000_v3_mbl
    //    && pass_sr_900_1000_v3_ht
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V3_MBL_HT
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_900_1000_v3_mbl
    //    && pass_sr_900_1000_v3_met_sig
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V3_MBL_MET
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_900_1000_v3_ht
    //    && pass_sr_900_1000_v3_met_sig
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V3_HT_MET
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
    // if (  pass_sr_900_1000_v3_mbl
    //    && pass_sr_900_1000_v3_ht
    //    && pass_sr_900_1000_v3_met_sig
    //    ) {
    //   fillHistHandles( PennSusyFrame::BMINUSL_HIST_OPT_900_1000_V3
    //                  , m_bl_0
    //                  , m_bl_1
    //                  , m_event_weight
    //                  );
    // }
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
      // std::cout << "\twriting histogram handler " << hist_it << " to file\n";
      m_histogram_handlers.at(hist_level).at(hist_it)->write(hist_dir_cut_level);
    }

    m_bminusl_histogram_handler.at(hist_level)->write(hist_dir_cut_level);
    m_bminusl_detailed_histogram_handler.at(hist_level)->write(hist_dir_cut_level);
  }
  // std::cout << "done writing histograms to file\n";

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
void PennSusyFrame::BMinusLAnalysis::constructObjects()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get basic event variables
  m_event.getEvent(m_d3pd_reader);
  m_trigger.getEvent(m_d3pd_reader);
  if (!m_is_data) {
    m_mc_truth.getEvent(m_d3pd_reader);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // prep vertices
  m_vertices.prep(m_d3pd_reader);

  // select good vertex cuts
  m_vertices.setCollection( VERTEX_GOOD
                          , PennSusyFrame::selectObjects( m_vertex_selectors.at(VERTEX_GOOD)
                                                        , m_vertices.getCollection(VERTEX_ALL)
                                                        )
                          );

  // select >= 2 track vertex cuts
  m_vertices.setCollection( VERTEX_GT_2
                          , PennSusyFrame::selectObjects( m_vertex_selectors.at(VERTEX_GT_2)
                                                        , m_vertices.getCollection(VERTEX_ALL)
                                                        )
                          );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // prep object containers
  m_electrons.prep(m_d3pd_reader);
  m_muons.prep(m_d3pd_reader);
  m_taus.prep(m_d3pd_reader);
  m_jets.prep(m_d3pd_reader, &m_event, &m_vertices);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // select baseline electrons from all electrons
  m_electrons.setCollection( EL_BASELINE
                           , PennSusyFrame::selectObjects( m_electron_selectors.at(EL_BASELINE)
                                                         , m_electrons.getCollection(EL_ALL)
                                                         )
                           );

  // select baseline muons from all muons
  m_muons.setCollection( MU_BASELINE
                       , PennSusyFrame::selectObjects( m_muon_selectors.at(MU_BASELINE)
                                                     , m_muons.getCollection(MU_ALL)
                                                     )
                       );

  // select baseline taus from all taus
  m_taus.setCollection( TAU_BASELINE
                      , PennSusyFrame::selectObjects( m_tau_selectors.at(TAU_BASELINE)
                                                    , m_taus.getCollection(TAU_ALL)
                                                    )
                      );

  // select baseline jets from all jets
  m_jets.setCollection( JET_BASELINE
                      , PennSusyFrame::selectObjects( m_jet_selectors.at(JET_BASELINE)
                                                    , m_jets.getCollection(JET_ALL)
                                                    )
                      );
  m_jets.setCollection( JET_BASELINE_GOOD
                      , PennSusyFrame::selectObjects( m_jet_selectors.at(JET_BASELINE_GOOD)
                                                    , m_jets.getCollection(JET_BASELINE)
                                                    )
                      );
  m_jets.setCollection( JET_BASELINE_BAD
                      , PennSusyFrame::selectObjects( m_jet_selectors.at(JET_BASELINE_BAD)
                                                    , m_jets.getCollection(JET_BASELINE)
                                                    )
                      );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do overlap removal -- we will have "good objects" after this step
  m_object_cleaning.fullObjectCleaning( m_electrons
                                      , m_muons
                                      , m_taus
                                      , m_jets
                                      );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_met.prep( m_d3pd_reader
            , m_event
            // , m_event_quantities
            , m_electrons.getCollection(EL_ALL)
            , m_muons.getCollection(MU_BASELINE)
            , m_jets.getCollection(JET_ALL)
            );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_event.updateWithMet(m_met);
  m_electrons.updateWithMet(m_met);
  m_muons.updateWithMet(m_met);
  m_jets.updateWithMet(m_met);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  int num_vtx_good = m_vertices.num(VERTEX_GOOD);
  m_electrons.updateIsolation(&m_event, num_vtx_good);
  m_muons.updateIsolation(    &m_event, num_vtx_good);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // select jets which suggest calo problem in the event
  m_jets.setCollection( JET_CALO_PROBLEM
                      , PennSusyFrame::selectObjects( m_jet_selectors.at(JET_CALO_PROBLEM)
                                                    , m_jets.getCollection(JET_BASELINE)
                                                    )
                      );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // select signal electrons from good electrons
  m_electrons.setCollection( EL_SIGNAL
                           , PennSusyFrame::selectObjects( m_electron_selectors.at(EL_SIGNAL)
                                                         , m_electrons.getCollection(EL_GOOD)
                                                         )
                           );

  // select signal muons from good muons
  m_muons.setCollection( MU_SIGNAL
                       , PennSusyFrame::selectObjects( m_muon_selectors.at(MU_SIGNAL)
                                                     , m_muons.getCollection(MU_GOOD)
                                                     )
                       );

  // select bad muons from good muons
  m_muons.setCollection( MU_BAD
                       , PennSusyFrame::selectObjects( m_muon_selectors.at(MU_BAD)
                                                     , m_muons.getCollection(MU_GOOD)
                                                     )
                       );

  // select cosmic muons from good muons
  m_muons.setCollection( MU_COSMIC
                       , PennSusyFrame::selectObjects( m_muon_selectors.at(MU_COSMIC)
                                                     , m_muons.getCollection(MU_GOOD)
                                                     )
                       );

  // select signal taus from good taus
  m_taus.setCollection( TAU_SIGNAL
                      , PennSusyFrame::selectObjects( m_tau_selectors.at(TAU_SIGNAL)
                                                    , m_taus.getCollection(TAU_GOOD)
                                                    )
                      );

  // select signal quality light jets from good jets
  m_jets.setCollection( JET_LIGHT
                      , PennSusyFrame::selectObjects( m_jet_selectors.at(JET_LIGHT)
                                                    , m_jets.getCollection(JET_GOOD)
                                                    )
                      );
  // get b jets from good jets
  m_jets.setCollection( JET_B
                      , PennSusyFrame::selectObjects( m_jet_selectors.at(JET_B)
                                                    , m_jets.getCollection(JET_GOOD)
                                                    )
                      );
  // We probably don't care about forward jets for this analysis
  // m_jets.setCollection( JET_FORWARD
  //                     , PennSusyFrame::selectObjects( m_jet_selectors.at(JET_FORWARD)
  //                                                   // , m_jets.getCollection(JET_SELECTED)
  //                                                   , m_jets.getCollection(JET_GOOD)
  //                                                   )
  //                     );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // TODO can we remove this?
  std::vector<PennSusyFrame::Jet*> central_jets;
  central_jets.reserve(m_jets.num(JET_LIGHT) + m_jets.num(JET_B));
  central_jets.insert( central_jets.end()
                     , m_jets.getCollection(JET_LIGHT)->begin()
                     , m_jets.getCollection(JET_LIGHT)->end()
                     );
  central_jets.insert( central_jets.end()
                     , m_jets.getCollection(JET_B)->begin()
                     , m_jets.getCollection(JET_B)->end()
                     );
  m_jets.setCollection(JET_ALL_CENTRAL, central_jets);

  // // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // std::vector<PennSusyFrame::Jet*> signal_jets;
  // signal_jets.reserve(m_jets.num(JET_ALL_CENTRAL) + m_jets.num(JET_FORWARD));
  // signal_jets.insert( signal_jets.end()
  //                   , m_jets.getCollection(JET_ALL_CENTRAL)->begin()
  //                   , m_jets.getCollection(JET_ALL_CENTRAL)->end()
  //                   );
  // signal_jets.insert( signal_jets.end()
  //                   , m_jets.getCollection(JET_FORWARD)->begin()
  //                   , m_jets.getCollection(JET_FORWARD)->end()
  //                   );
  // m_jets.setCollection(JET_ALL_SIGNAL, signal_jets);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get objects which are selected for this analysis
  getSelectedObjects();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // calculate Ht variable
  m_event_quantities.setHtAll( PennSusyFrame::getHt( m_electrons.getCollection(EL_ALL)
                                                   , m_muons.getCollection(MU_ALL)
                                                   , m_jets.getCollection(JET_ALL)
                                                   )
                             );
  m_event_quantities.setHtBaseline( PennSusyFrame::getHt( m_electrons.getCollection(EL_BASELINE)
                                                        , m_muons.getCollection(MU_BASELINE)
                                                        , m_jets.getCollection(JET_BASELINE)
                                                        )
                                  );
  m_event_quantities.setHtGood( PennSusyFrame::getHt( m_electrons.getCollection(EL_GOOD)
                                                    , m_muons.getCollection(MU_GOOD)
                                                    , m_jets.getCollection(JET_GOOD)
                                                    )
                              );
  m_event_quantities.setHtSignal( PennSusyFrame::getHt( m_electrons.getCollection(EL_SIGNAL)
                                                      , m_muons.getCollection(MU_SIGNAL)
                                                      , m_jets.getCollection(JET_ALL_SIGNAL)
                                                      )
                                );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // construct met-sig
  m_met.constructMetSig(m_event_quantities);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // construct met-rel
  // m_met.constructMetRel( m_electrons.getCollection(EL_GOOD)
  //                      , m_muons.getCollection(MU_GOOD)
  m_met.constructMetRel( m_electrons.getCollection(EL_SELECTED)
                       , m_muons.getCollection(MU_SELECTED)
                       , m_jets.getCollection(JET_ALL_CENTRAL)
                       );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_event.setFlavorChannel(findFlavorChannel());
  m_event.setSignChannel(findSignCannel());

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_event_quantities.setMll( PennSusyFrame::getMll( m_event.getFlavorChannel()
                                                  // , m_electrons.getCollection(EL_GOOD)
                                                  // , m_muons.getCollection(MU_GOOD)
                                                  , m_electrons.getCollection(EL_SELECTED)
                                                  , m_muons.getCollection(MU_SELECTED)
                                                  )
                           );

  m_event_quantities.setPtll( PennSusyFrame::getPtll( m_event.getFlavorChannel()
                                                    // , m_electrons.getCollection(EL_GOOD)
                                                    // , m_muons.getCollection(MU_GOOD)
                                                    , m_electrons.getCollection(EL_SELECTED)
                                                    , m_muons.getCollection(MU_SELECTED)
                                                    )
                            );

  m_event_quantities.setMt2 (PennSusyFrame::getMt2( m_event.getFlavorChannel()
                                                  , &m_met
                                                  // , m_electrons.getCollection(EL_GOOD)
                                                  // , m_muons.getCollection(MU_GOOD)
                                                  , m_electrons.getCollection(EL_SELECTED)
                                                  , m_muons.getCollection(MU_SELECTED)
                                                  )
                           );

  m_event_quantities.setEmmaMt( PennSusyFrame::getEmmaMt( m_event.getFlavorChannel()
                                                        // , m_electrons.getCollection(EL_GOOD)
                                                        // , m_muons.getCollection(MU_GOOD)
                                                        , m_electrons.getCollection(EL_SELECTED)
                                                        , m_muons.getCollection(MU_SELECTED)
                                                        )
                              );

  m_event_quantities.setDphill( PennSusyFrame::getDphill( m_event.getFlavorChannel()
                                                        // , m_electrons.getCollection(EL_GOOD)
                                                        // , m_muons.getCollection(MU_GOOD)
                                                        , m_electrons.getCollection(EL_SELECTED)
                                                        , m_muons.getCollection(MU_SELECTED)
                                                        )
                              );

  if (!m_is_data) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // set mc event weight
    m_event_quantities.setMcEventWeight(m_d3pd_reader->mc_event_weight);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // set pile up weight
    m_event_quantities.setPileUpSF(m_pile_up_sf_tool.getPileupScaleFactor(m_event, m_mc_truth));

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // set lepton SF
    double lepton_sf = 1.;

    // size_t el_term = m_electrons.num(EL_GOOD);
    // const std::vector<PennSusyFrame::Electron*>* el_list = m_electrons.getCollection(EL_GOOD);
    size_t el_term = m_electrons.num(EL_SELECTED);
    const std::vector<PennSusyFrame::Electron*>* el_list = m_electrons.getCollection(EL_SELECTED);
    for (size_t el_it = 0; el_it != el_term; ++el_it) {
      lepton_sf *= m_egamma_sf_tool.getSF(m_event, el_list->at(el_it));
    }

    // size_t mu_term = m_muons.num(MU_GOOD);
    // const std::vector<PennSusyFrame::Muon*>* mu_list = m_muons.getCollection(MU_GOOD);
    size_t mu_term = m_muons.num(MU_SELECTED);
    const std::vector<PennSusyFrame::Muon*>* mu_list = m_muons.getCollection(MU_SELECTED);
    for (size_t mu_it = 0; mu_it != mu_term; ++mu_it) {
      lepton_sf *= m_muon_sf_tool.getSF(mu_list->at(mu_it));
    }

    m_event_quantities.setLeptonSF(lepton_sf);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // set trigger weight
    m_event_quantities.setTriggerWeight(m_trigger_weight_tool.getWeight( m_event.getFlavorChannel()
                                                                       // , m_electrons.getCollection(EL_GOOD)
                                                                       // , m_muons.getCollection(MU_GOOD)
                                                                       // , m_jets.getCollection(JET_GOOD)
                                                                       , m_electrons.getCollection(EL_SELECTED)
                                                                       , m_muons.getCollection(MU_SELECTED)
                                                                       , m_jets.getCollection(JET_SELECTED)
                                                                       , m_met
                                                                       , m_vertices.getCollection(VERTEX_GOOD)
                                                                       )
                                       );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // set b tag weight
    // m_event_quantities.setBTagSF(m_b_tag_sf_tool.getSF(m_jets.getCollection(JET_GOOD)));
    m_event_quantities.setBTagSF(m_b_tag_sf_tool.getSF(m_jets.getCollection(JET_SELECTED)));

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_truth_match_tool.prep(m_mc_truth);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // check for prompt leptons
    m_event.setPromptLeptons( m_truth_match_tool.isRealLeptonEvent( m_event.getFlavorChannel()
                                                                  // , m_electrons.getCollection(EL_GOOD)
                                                                  // , m_muons.getCollection(MU_GOOD)
                                                                  , m_electrons.getCollection(EL_SELECTED)
                                                                  , m_muons.getCollection(MU_SELECTED)
                                                                  , m_mc_truth
                                                                  )
                             );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // get the truth sign channel of the two leptons
    m_event.setTruthSignChannel( m_truth_match_tool.getTruthSign( m_event.getFlavorChannel()
                                                                // , m_electrons.getCollection(EL_GOOD)
                                                                // , m_muons.getCollection(MU_GOOD)
                                                                , m_electrons.getCollection(EL_SELECTED)
                                                                , m_muons.getCollection(MU_SELECTED)
                                                                , m_mc_truth
                                                                )
                               );
  }
}


// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::getSelectedObjects()
{
  // find the selected leptons for this analysis
  std::vector<PennSusyFrame::Electron*> selected_el_list;
  std::vector<PennSusyFrame::Muon*>     selected_mu_list;
  selected_el_list.reserve(2);
  selected_mu_list.reserve(2);

  size_t num_el_stored = 0;
  size_t num_mu_stored = 0;

  // first, check signal leptons
  const std::vector<PennSusyFrame::Electron*>* sig_el_list = m_electrons.getCollection(EL_SIGNAL);
  const std::vector<PennSusyFrame::Muon*>*     sig_mu_list = m_muons.getCollection(MU_SIGNAL);

  size_t num_sig_el = sig_el_list->size();
  size_t num_sig_mu = sig_mu_list->size();


  size_t next_sig_el = 0;
  size_t next_sig_mu = 0;

  float el_pt = -1;
  float mu_pt = -1;
  size_t num_it = 0;
  while (  num_el_stored + num_mu_stored < 2
        && num_it < 10
        && (  next_sig_el < num_sig_el
           || next_sig_mu < num_sig_mu
           )
        ) {
    // get the next electron and muon pt values
    el_pt = ((next_sig_el < num_sig_el) ? sig_el_list->at(next_sig_el)->getPt() : -1);
    mu_pt = ((next_sig_mu < num_sig_mu) ? sig_mu_list->at(next_sig_mu)->getPt() : -1);

    if (el_pt >= mu_pt) {
      // if next electron is harder than next muon, add that to lepton list
      selected_el_list.push_back(sig_el_list->at(next_sig_el));
      ++next_sig_el;
      ++num_el_stored;
    }
    else {
      // if muon is harder than electron, add that to lepton list
      selected_mu_list.push_back(sig_mu_list->at(next_sig_mu));
      ++next_sig_mu;
      ++num_mu_stored;
    }
  }

  // if we didn't find enough leptons in the signal lepton containers, look into the good lepton collections
  if ((num_el_stored + num_mu_stored) < 2) {
    const std::vector<PennSusyFrame::Electron*>* good_el_list = m_electrons.getCollection(EL_GOOD);
    const std::vector<PennSusyFrame::Muon*>*     good_mu_list = m_muons.getCollection(MU_GOOD);

    size_t num_good_el = good_el_list->size();
    size_t num_good_mu = good_mu_list->size();

    size_t next_good_el = 0;
    size_t next_good_mu = 0;

    el_pt = -1;
    mu_pt = -1;
    num_it = 0;
    while (  num_el_stored + num_mu_stored < 2
          && num_it < 10
          && (  next_good_el < num_good_el
             || next_good_mu < num_good_mu
             )
          ) {

      // get the next electron and muon pt values
      el_pt = ((next_good_el < num_good_el) ? good_el_list->at(next_good_el)->getPt() : -1);
      mu_pt = ((next_good_mu < num_good_mu) ? good_mu_list->at(next_good_mu)->getPt() : -1);

      if (el_pt >= mu_pt) {
        // if next electron is harder than next muon, add that to lepton list
        bool store_this_obj = ( (selected_el_list.size() == 0)
                              ? true
                              : (  selected_el_list.at(0)
                                != good_el_list->at(next_good_el)
                                )
                              );
        if (store_this_obj) {
          selected_el_list.push_back(good_el_list->at(next_good_el));
          ++num_el_stored;
        }
        ++next_good_el;
      }
      else {
        // if muon is harder than electron, add that to lepton list
        bool store_this_obj = ( (selected_mu_list.size() == 0)
                              ? true
                              : (  selected_mu_list.at(0)
                                != good_mu_list->at(next_good_mu)
                                )
                              );
        if (store_this_obj) {
          selected_mu_list.push_back(good_mu_list->at(next_good_mu));
          ++num_mu_stored;
        }
        ++next_good_mu;
      }
    }
  }

  m_electrons.setCollection(EL_SELECTED , selected_el_list);
  m_muons.setCollection(    MU_SELECTED , selected_mu_list);

  // select two leading b jets
  std::vector<PennSusyFrame::Jet*> selected_jets;
  selected_jets.reserve(2);
  const std::vector<PennSusyFrame::Jet*>* b_jets = m_jets.getCollection(JET_B);
  size_t num_b_jets = b_jets->size();
  if (num_b_jets >= 1) selected_jets.push_back(b_jets->at(0));
  if (num_b_jets >= 2) selected_jets.push_back(b_jets->at(1));
  m_jets.setCollection(JET_SELECTED , selected_jets);

  // simply copy the good taus
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
                                                         // , m_jets.getCollection(JET_SELECTED)
                                                         , m_jets.getCollection(JET_B)
                                                         , m_met
                                                         , weight
                                                         );
  }

  if (m_pass_bl_pairing) {
    m_bminusl_histogram_handler.at(hist_level)->FillSpecial( m_event
                                                           // , m_event_quantities
                                                           , m_jets.getCollection(JET_B)
                                                           , *bl_0
                                                           , *bl_1
                                                           , m_mc_truth
                                                           , weight
                                                           );
    m_bminusl_detailed_histogram_handler.at(hist_level)->FillSpecial( m_event
                                                                    , m_event_quantities
                                                                    , m_jets.getCollection(JET_B)
                                                                    , *bl_0
                                                                    , *bl_1
                                                                    , m_mc_truth
								    , m_truth_match_tool
                                                                    , weight
                                                                    );
  }
}
