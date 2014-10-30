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
#include "PennSusyFrameCore/include/ObjectSelectors.h"

// -----------------------------------------------------------------------------
PennSusyFrame::BMinusLAnalysis::BMinusLAnalysis(TTree* tree) : PennSusyFrame::PennSusyFrameCore(tree)
                                                             , m_out_hist_file_name("BMinusL.hists.root")
                                                             , m_do_detailed_bl_hists(false)
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
                                                             , m_crit_cut_os_lep(false)
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
  // set electron quality level in egamma SF tool
  m_egamma_sf_tool.setMediumPP();

  // prepare tools
  PennSusyFrameCore::prepareTools();
  m_bminusl_trigger_sf_tool.init();

  // set up grl
  // TODO make this configurable
  std::string base_dir = getenv("BASE_WORK_DIR");
  if (m_is_data) {
    m_grl.init( base_dir
              + "/data/data12_8TeV.periodAllYear_DetStatus-v58-pro14-01_DQDefects-00-00-33_PHYS_StandardGRL_All_Good.xml"
              );
  }

  // set up overlap removal
  m_object_cleaning.setEEConeSize(0.05);
  m_object_cleaning.setEJConeSize(0.20);
  m_object_cleaning.setMJConeSize(0.00);
  m_object_cleaning.setETConeSize(0.00);
  m_object_cleaning.setMTConeSize(0.00);
  m_object_cleaning.setJEConeSize(0.40);
  m_object_cleaning.setJMConeSize(0.40);
  m_object_cleaning.setEMConeSize(0.01);
  m_object_cleaning.setMMConeSize(0.05);
  m_object_cleaning.setTJConeSize(0.00);
  m_object_cleaning.setSFOSMllMin(12.e3);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::prepareSelection()
{
  PennSusyFrameCore::prepareSelection();

  std::cout << "preparing selection\n";

  // EL_BASELINE
  m_electron_selectors.at(EL_BASELINE).setElectronQuality(EL_QUALITY_MEDPP);
  m_electron_selectors.at(EL_BASELINE).setPtCut(m_min_el_pt_baseline, m_max_el_pt_baseline);
  m_electron_selectors.at(EL_BASELINE).setD0SignificanceCut(-1, 3);
  m_electron_selectors.at(EL_BASELINE).setZ0SignThetaCut(-1, 0.4);

  // EL_SIGNAL
  m_electron_selectors.at(EL_SIGNAL).setElectronQuality(EL_QUALITY_MEDPP);
  // m_electron_selectors.at(EL_SIGNAL).setElectronQuality(EL_QUALITY_TIGHTPP);
  m_electron_selectors.at(EL_SIGNAL).setD0SignificanceCut(-1, 3);
  m_electron_selectors.at(EL_SIGNAL).setZ0SignThetaCut(-1, 0.4);
  // m_electron_selectors.at(EL_SIGNAL).setPtIsoCut(-1, -1);
  m_electron_selectors.at(EL_SIGNAL).setPtIsoCut(-1, 0.1);
  m_electron_selectors.at(EL_SIGNAL).setEtIsoCut(-1, -1);

  // MU_BASELINE
  m_muon_selectors.at(MU_BASELINE).setPtCut(m_min_mu_pt_baseline, m_max_mu_pt_baseline);
  m_muon_selectors.at(MU_BASELINE).setD0SignificanceCut(-1, 3.);
  m_muon_selectors.at(MU_BASELINE).setZ0SignThetaCut(-1, 1.);

  // MU_SIGNAL
  m_muon_selectors.at(MU_SIGNAL).setD0SignificanceCut(-1, 3.);
  m_muon_selectors.at(MU_SIGNAL).setZ0SignThetaCut(-1, 1.);
  // m_muon_selectors.at(MU_SIGNAL).setPtIsoCut(-1, -1);
  m_muon_selectors.at(MU_SIGNAL).setPtIsoCut(-1, 0.1);
  m_muon_selectors.at(MU_SIGNAL).setEtIsoCut(-1, -1);

  // JET_B
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
  m_bminusl_histogram_handler.reserve(BMINUSL_HIST_N);
  if (m_do_detailed_bl_hists) {
    m_bminusl_detailed_histogram_handler.reserve(BMINUSL_HIST_N);
  }

  for (unsigned int hist_level = 0; hist_level != BMINUSL_HIST_N; ++hist_level) {
    std::cout << "creating histograms with hist level: " << hist_level << " -- " << PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level] << "\n";
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::HistogramHandler(     PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]) );
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::EventLevelHists(      PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]) );
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::LeptonKinematicsHists(PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]) );
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::JetKinematicsHists(   PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]) );
    m_histogram_handlers.at(hist_level).push_back( new PennSusyFrame::MetHists(             PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]) );

    m_bminusl_histogram_handler.push_back(         new PennSusyFrame::BMinusLHists(         PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]));
    m_weight_histogram_handler.push_back(          new PennSusyFrame::WeightHists(          PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]));
    m_parent_histogram_handler.push_back(          new PennSusyFrame::ParentHists(          PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]));
    if (m_do_detailed_bl_hists) {
      m_bminusl_detailed_histogram_handler.push_back(new PennSusyFrame::BMinusLDetailedHists(PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level]));
    }
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::initializeEvent()
{
  m_event_weight          = 1.;
  m_mc_event_weight       = 1.;
  m_pile_up_sf            = 1.;
  m_lepton_sf             = 1.;
  m_trigger_sf            = 1.;
  m_btag_sf               = 1.;
  m_ttbar_pt_weight       = 1.;
  m_fudge_k_factor_weight = 1.;

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
  m_pass_os               = false;
  m_pass_trigger          = false;
  m_pass_phase            = false;
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
  fillTrackers(BMINUSL_CUT_ALL);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set mc event weight
  m_mc_event_weight = m_event_quantities.getMcEventWeight();
  m_event_weight *= m_mc_event_weight;
  fillTrackers(BMINUSL_CUT_MC_EVENT_WEIGHT);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set pile up weight
  m_pile_up_sf = m_event_quantities.getPileUpSF();
  m_event_weight *= m_pile_up_sf;
  fillTrackers(BMINUSL_CUT_PILEUP_WEIGHT);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set cross section weight
  m_event_weight *= m_xsec_weight;
  fillTrackers(BMINUSL_CUT_XSEC_WEIGHT);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // fudge k-factor
  m_fudge_k_factor_weight = (m_is_data ? 1
                                       : getFudgeKFactor( m_is_data
                                                        , m_mc_truth.getChannelNumber()
                                                        )
                            );
  m_event_weight *= m_fudge_k_factor_weight;
  fillTrackers(BMINUSL_CUT_FUDGE_K_FACTOR_WEIGHT);

  // -----------------------------------------------------------------------------
  m_event.setPhaseSpace(getPhaseSpace());

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // GRL cut -- only check grl cut on data
  m_pass_grl = (!m_is_data || m_grl.passEvent(m_event));
  m_pass_event = (m_pass_event && m_pass_grl);
  if (m_crit_cut_grl && !m_pass_grl) return;
  fillTrackers(BMINUSL_CUT_GRL);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // incomplete event cut
  m_pass_incomplete_event = PennSusyFrame::passIncompleteEvent(m_event);
  m_pass_event = (m_pass_event && m_pass_incomplete_event);
  if (m_crit_cut_incomplete_event && !m_pass_incomplete_event) return;
  fillTrackers(BMINUSL_CUT_INCOMPLETE_EVENT);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // LAr error cut
  m_pass_lar_error = PennSusyFrame::passLarError(m_event);
  m_pass_event = (m_pass_event && m_pass_lar_error);
  if (m_crit_cut_lar_error && !m_pass_lar_error) return;
  fillTrackers(BMINUSL_CUT_LAR_ERROR);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile error cut
  m_pass_tile_error = PennSusyFrame::passTileError(m_event);
  m_pass_event = (m_pass_event && m_pass_tile_error);
  if (m_crit_cut_tile_error && !m_pass_tile_error) return;
  fillTrackers(BMINUSL_CUT_TILE_ERROR);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile hot spot cut
  m_pass_tile_hot_spot = PennSusyFrame::TileHotSpotTool::passTileHotSpot(m_event, m_jets);
  m_pass_event = (m_pass_event && m_pass_tile_hot_spot);
  if (m_crit_cut_tile_hot_spot && !m_pass_tile_hot_spot) return;
  fillTrackers(BMINUSL_CUT_TILE_HOT_SPOT);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tile trip cut
  m_pass_tile_trip = m_tile_trip_tool.passTileTrip(m_event);
  m_pass_event = (m_pass_event && m_pass_tile_trip);
  if (m_crit_cut_tile_trip && !m_pass_tile_trip) return;
  fillTrackers(BMINUSL_CUT_TILE_TRIP);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // bad jet veto
  m_pass_bad_jet_veto = (m_jets.num(JET_BAD) == 0);
  m_pass_event = (m_pass_event && m_pass_bad_jet_veto);
  if (m_crit_cut_bad_jet_veto && !m_pass_bad_jet_veto) return;
  fillTrackers(BMINUSL_CUT_BAD_JET_VETO);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // calo problem jet cut
  m_pass_calo_problem_jet = (m_jets.num(JET_CALO_PROBLEM) == 0);
  m_pass_event = (m_pass_event && m_pass_calo_problem_jet);
  if (m_crit_cut_calo_problem_jet && !m_pass_calo_problem_jet) return;
  fillTrackers(BMINUSL_CUT_CALO_PROBLEM_JET);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // primary vertex cut
  m_pass_primary_vertex = PennSusyFrame::passPrimaryVertex(m_vertices);
  m_pass_event = (m_pass_event && m_pass_primary_vertex);
  if (m_crit_cut_primary_vertex && !m_pass_primary_vertex) return;
  fillTrackers(BMINUSL_CUT_PRIMARY_VERTEX);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // bad muon cut
  m_pass_bad_mu_veto = (m_muons.num(MU_BAD) == 0);
  m_pass_event = (m_pass_event && m_pass_bad_mu_veto);
  if (m_crit_cut_bad_mu_veto && !m_pass_bad_mu_veto) return;
  fillTrackers(BMINUSL_CUT_BAD_MUON);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // cosmic muon veto
  m_pass_cosmic_mu_veto = (m_muons.num(MU_COSMIC) == 0);
  m_pass_event = (m_pass_event && m_pass_cosmic_mu_veto);
  if (m_crit_cut_cosmic_mu_veto && !m_pass_cosmic_mu_veto) return;
  fillTrackers(BMINUSL_CUT_COSMIC_MUON_VETO);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // HFOR cut
  m_pass_hfor = m_hfor_tool.passHFOR(m_mc_truth);
  m_pass_event = (m_pass_event && m_pass_hfor);
  if (m_crit_cut_hfor && !m_pass_hfor) return;
  fillTrackers(BMINUSL_CUT_HFOR);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // mc overlap cut
  m_pass_mc_overlap = (  PennSusyFrame::passSherpaZMassiveCBOverlapRemoval(m_mc_truth, m_event_quantities)
                      && PennSusyFrame::passSherpaDYOverlapRemoval(m_mc_truth, m_event_quantities)
                      );
  m_pass_event = (m_pass_event && m_pass_mc_overlap);
  if (m_crit_cut_mc_overlap && !m_pass_mc_overlap) return;
  fillTrackers(BMINUSL_CUT_MC_OVERLAP);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get number of good leptons
  int num_good_leptons = m_electrons.num(EL_SELECTED) + m_muons.num(MU_SELECTED);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // >= 2 baseline leptons cut
  m_pass_ge_2_lep = (num_good_leptons >= 2);
  m_pass_event = (m_pass_event && m_pass_ge_2_lep);
  if (m_crit_cut_ge_2_lep && !m_pass_ge_2_lep) return;
  fillTrackers(BMINUSL_CUT_GE_2_BASELINE_LEPTONS);

  // // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // // >= 2 baseline leptons cut
  // m_pass_2_lep = (num_good_leptons == 2);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get number of signal leptons
  int num_signal_leptons = m_electrons.num(EL_SIGNAL) + m_muons.num(MU_SIGNAL);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // == 2 signal lepton cut
  // TODO switch these lines back
  m_pass_signal_lep = (num_signal_leptons >= 2);
  // m_pass_signal_lep = (num_signal_leptons == 2);
  m_pass_event = (m_pass_event && m_pass_signal_lep);
  if (m_crit_cut_signal_lep && !m_pass_signal_lep) return;
  fillTrackers(BMINUSL_CUT_GE_2_SIGNAL_LEPTON);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // lepton scale factor
  m_lepton_sf = m_event_quantities.getLeptonSF();
  m_event_weight *= m_lepton_sf;
  fillTrackers(BMINUSL_CUT_LEP_SF);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // require OS leptons
  m_pass_os = (m_event.getSignChannel() == SIGN_OS);
  m_pass_event = (m_pass_event && m_pass_os);
  if (m_crit_cut_os_lep && !m_pass_os) return;
  fillTrackers(BMINUSL_CUT_OS_LEP);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check trigger
  m_pass_trigger = passBMinusLTrigger();
  m_pass_event = (m_pass_event && m_pass_trigger);
  fillTrackers(BMINUSL_CUT_TRIGGER);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Check phase
  m_pass_phase = passPhaseSpace();
  m_pass_event = (m_pass_event && m_pass_phase);
  fillTrackers(BMINUSL_CUT_PHASE);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // apply trigger weight
  // TODO validate trigger weight
  if (!m_is_data) {
    m_trigger_sf = m_bminusl_trigger_sf_tool.getSF( m_event
                                                  , m_pile_up_sf_tool
                                                  , m_electrons.getCollection(EL_SELECTED)
                                                  , m_muons.getCollection(MU_SELECTED)
                                                  );
  }
  m_event_weight *= m_trigger_sf;
  fillTrackers(BMINUSL_CUT_TRIGGER_WEIGHT);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get number of b jets
  int num_b_jets = m_jets.num(JET_B);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // check number of b jets >= 2
  m_pass_ge_2_b_jet = (num_b_jets >= 2);
  m_pass_event = (m_pass_event && m_pass_ge_2_b_jet);
  if (m_crit_cut_b_jets && ! m_pass_ge_2_b_jet) return;
  fillTrackers(BMINUSL_CUT_GE_2_B_JET);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // b tag sf
  m_btag_sf = m_event_quantities.getBTagSF();
  m_event_weight *= m_btag_sf;
  fillTrackers(BMINUSL_CUT_B_TAG_SF);

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
  fillTrackers(BMINUSL_CUT_BL_PAIRING);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // ttbar pt reweight
  m_ttbar_pt_weight = calculateTtbarPtReweight(m_mc_truth);
  m_event_weight *= m_ttbar_pt_weight;
  fillTrackers(BMINUSL_CUT_TTBAR_WEIGHT);

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
  fillTrackers(BMINUSL_CUT_ZVETO);
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
     ) {
    float this_weight = ( m_mc_event_weight
                        * m_pile_up_sf
                        * m_xsec_weight
                        * m_fudge_k_factor_weight
                        );
    fillHistHandles( PennSusyFrame::BMINUSL_HIST_BASIC_CLEANING
                   , m_bl_0
                   , m_bl_1
                   , this_weight
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
     && m_pass_signal_lep
     && m_pass_os
     && m_pass_trigger
     && m_pass_phase
     && m_pass_ge_2_b_jet
     && m_pass_bl_pairing
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
     && m_pass_signal_lep
     && m_pass_os
     && m_pass_trigger
     && m_pass_phase
     && m_pass_ge_2_b_jet
     && m_pass_bl_pairing
     && m_pass_z_veto
     ) {
    fillHistHandles( PennSusyFrame::BMINUSL_HIST_Z_VETO
                   , m_bl_0
                   , m_bl_1
                   , m_event_weight
                   );
  }

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
     && m_pass_signal_lep
     && m_pass_os
     && m_pass_trigger
     && m_pass_phase
     && m_pass_ge_2_b_jet
     && m_pass_bl_pairing
     ) {

    double mbl_asym = ( (m_bl_0->getMbl() - m_bl_1->getMbl())
                      / (m_bl_0->getMbl() + m_bl_1->getMbl())
                      );
    double ht       = m_event_quantities.getHtSignal() / 1.e3;
    double met_sig  = m_met.getMetSigSignal();

    bool ht_ge_1100    = (ht       >= 1100.0 );
    bool ht_ge_700     = (ht       >= 700.0 );
    bool ht_ge_600     = (ht       >= 600.0 );
    bool ht_ge_500     = (ht       >= 500.0 );
    bool mbl_le_4      = (mbl_asym <= 0.40   );
    bool met_sig_ge_4  = (met_sig  >= 4.     );

    // -------------------------------------------------------------------------
    // - Fill histograms for SR (don't fill for data if we are blind!)
    // -------------------------------------------------------------------------
    if ( !m_is_data || !m_is_blind ) {
      // signal region cuts
      if (m_pass_z_veto && ht_ge_1100 && mbl_le_4) {
        fillHistHandles( PennSusyFrame::BMINUSL_HIST_SR
                       , m_bl_0
                       , m_bl_1
                       , m_event_weight
                       );
      }
      if (m_pass_z_veto && mbl_le_4) {
        fillHistHandles( PennSusyFrame::BMINUSL_HIST_SR_MINUS_HT
                       , m_bl_0
                       , m_bl_1
                       , m_event_weight
                       );
      }
      if (m_pass_z_veto && ht_ge_1100) {
        fillHistHandles( PennSusyFrame::BMINUSL_HIST_SR_MINUS_MBL_ASYM
                       , m_bl_0
                       , m_bl_1
                       , m_event_weight
                       );
      }
      if (ht_ge_1100 && mbl_le_4) {
        fillHistHandles( PennSusyFrame::BMINUSL_HIST_SR_MINUS_Z_VETO
                       , m_bl_0
                       , m_bl_1
                       , m_event_weight
                       );
      }
    }

    // -------------------------------------------------------------------------
    // - Fill histograms for CR and VR
    // -------------------------------------------------------------------------
    // CR top region cuts
    if (m_pass_z_veto && !ht_ge_500 && mbl_le_4 && met_sig_ge_4) {
      fillHistHandles( PennSusyFrame::BMINUSL_HIST_CR_TOP
                     , m_bl_0
                     , m_bl_1
                     , m_event_weight
                     );
    }

    // CR Z region cuts
    if (!m_pass_z_veto && !ht_ge_500 && mbl_le_4) {
      fillHistHandles( PennSusyFrame::BMINUSL_HIST_CR_Z
                     , m_bl_0
                     , m_bl_1
                     , m_event_weight
                     );
    }

    // VR 1 region cuts
    // if (m_pass_z_veto && ht_ge_500 && !ht_ge_700 && mbl_le_4) {
    if (m_pass_z_veto && ht_ge_500 && !ht_ge_1100 && mbl_le_4 && met_sig_ge_4) {
      fillHistHandles( PennSusyFrame::BMINUSL_HIST_VR_1
                     , m_bl_0
                     , m_bl_1
                     , m_event_weight
                     );
    }

    // VR 2 region cuts
    // if (m_pass_z_veto && ht_ge_500 && !ht_ge_700 && !mbl_le_4) {
    if (m_pass_z_veto && ht_ge_500 && !ht_ge_600 && !mbl_le_4 && !met_sig_ge_4) {
      fillHistHandles( PennSusyFrame::BMINUSL_HIST_VR_2
                     , m_bl_0
                     , m_bl_1
                     , m_event_weight
                     );
    }

    // VR 3 region cuts
    if (m_pass_z_veto && !ht_ge_500 && mbl_le_4 && !met_sig_ge_4) {
      fillHistHandles( PennSusyFrame::BMINUSL_HIST_VR_3
                     , m_bl_0
                     , m_bl_1
                     , m_event_weight
                     );
    }

    // VR 4 region cuts
    if (m_pass_z_veto && !ht_ge_500 && mbl_le_4) {
      fillHistHandles( PennSusyFrame::BMINUSL_HIST_VR_4
                     , m_bl_0
                     , m_bl_1
                     , m_event_weight
                     );
    }

    // VR 5 region cuts
    if (!m_pass_z_veto && ht_ge_500 && !ht_ge_1100 && mbl_le_4) {
      fillHistHandles( PennSusyFrame::BMINUSL_HIST_VR_5
                     , m_bl_0
                     , m_bl_1
                     , m_event_weight
                     );
    }

    // VR 6 region cuts
    if (!m_pass_z_veto && ht_ge_500 && !ht_ge_1100 && !mbl_le_4) {
      fillHistHandles( PennSusyFrame::BMINUSL_HIST_VR_6
                     , m_bl_0
                     , m_bl_1
                     , m_event_weight
                     );
    }

    // VR 7 region cuts
    if (!m_pass_z_veto && !ht_ge_500 && !mbl_le_4) {
      fillHistHandles( PennSusyFrame::BMINUSL_HIST_VR_7
                     , m_bl_0
                     , m_bl_1
                     , m_event_weight
                     );
    }
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLAnalysis::finalizeRun()
{
  std::cout << "BMinusLAnalysis::finalizeRun()\n";
  std::cout << "creating output histogram file\n";
  TFile out_hist_file(m_out_hist_file_name.c_str(), "RECREATE");

  m_d3pd_reader->writeNumEvents();

  std::cout << "about to write histograms to file\n";
  for ( unsigned int hist_level = 0
      ; hist_level != BMINUSL_HIST_N
      ; ++hist_level
      ) {
    TDirectory* hist_dir_cut_level = out_hist_file.mkdir(PennSusyFrame::BMINUSL_HIST_LEVEL_STRINGS[hist_level].c_str());

    size_t num_hists = m_histogram_handlers.at(hist_level).size();
    for (size_t hist_it = 0; hist_it != num_hists; ++hist_it) {
      m_histogram_handlers.at(hist_level).at(hist_it)->write(hist_dir_cut_level);
    }

    m_bminusl_histogram_handler.at(hist_level)->write(hist_dir_cut_level);
    m_weight_histogram_handler.at( hist_level)->write(hist_dir_cut_level);
    m_parent_histogram_handler.at( hist_level)->write(hist_dir_cut_level);
    if (m_do_detailed_bl_hists) {
      m_bminusl_detailed_histogram_handler.at(hist_level)->write(hist_dir_cut_level);
    }
  }

  out_hist_file.Close();
  std::cout << "file is closed!\n";

  m_raw_cutflow_tracker.printToScreen();
  m_cutflow_tracker.printToScreen();
}

// -----------------------------------------------------------------------------
// fill cut flow trackers for this level
void PennSusyFrame::BMinusLAnalysis::fillTrackers(BMINUSL_CUTS this_cut_level) {
  if (m_pass_event) {
    m_raw_cutflow_tracker.fillHist(FLAVOR_NONE, this_cut_level);
    m_cutflow_tracker.fillHist(    FLAVOR_NONE, this_cut_level, m_event_weight);

    if (m_event.getPhaseSpace() != PHASE_NONE) {
      m_raw_cutflow_tracker.fillHist(m_event.getPhaseSpace(), this_cut_level);
      m_cutflow_tracker.fillHist(    m_event.getPhaseSpace(), this_cut_level, m_event_weight);
    }
  }
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
bool PennSusyFrame::BMinusLAnalysis::passPhaseSpace()
{
  // get the phase space of this event
  PHASE_SPACE phase_space = m_event.getPhaseSpace();

  // for MC, only check for phase != none   // for MC, only check for phase != none
  if (!m_is_data) return (phase_space != PHASE_NONE);

  // for data check that phase matches with data stream
  if (  m_is_egamma_stream
     && (phase_space == PHASE_EE || phase_space == PHASE_EM)
     ) {
    return true;
  }
  if (  !m_is_egamma_stream
     && (phase_space == PHASE_MM || phase_space == PHASE_ME)
     ) {
    return true;
  }

  return false;

  /*
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // TODO replace the above overlap removal with the one below after debugging
  FLAVOR_CHANNEL flavor_channel = m_event.getFlavorChannel();

  // for MC, only check for phase != none
  if (!m_is_data) return (flavor_channel != FLAVOR_NONE);

  // EE MM can only come from egamma and muon streams respectively
  if (m_is_egamma_stream  && flavor_channel == FLAVOR_EE) return true;
  if (!m_is_egamma_stream && flavor_channel == FLAVOR_MM) return true;

  // if EM stream, check trigger. if pass the single electron trigger, take from
  // egamma stream. Only take EM events from muons stream if the event fails the
  // electron trigger
  if (m_is_egamma_stream && flavor_channel == FLAVOR_EM) {
    return m_trigger.getEF_e24vhi_medium1();
  }

  if (!m_is_egamma_stream && flavor_channel == FLAVOR_EM) {
    return (  m_trigger.getEF_mu24i_tight()
           && !m_trigger.getEF_e24vhi_medium1()
           );
  }

  return false;
  */
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::BMinusLAnalysis::passBMinusLTrigger()
{
  FLAVOR_CHANNEL flavor_channel = m_event.getFlavorChannel();

  if (flavor_channel == FLAVOR_EE && m_trigger.getEF_e24vhi_medium1()) return true;
  if (flavor_channel == FLAVOR_MM && m_trigger.getEF_mu24i_tight())    return true;
  // if (flavor_channel == FLAVOR_MM && m_trigger.getEF_mu36_tight())     return true;
  if (flavor_channel == FLAVOR_EM && m_trigger.getEF_e24vhi_medium1()) return true;
  if (flavor_channel == FLAVOR_EM && m_trigger.getEF_mu24i_tight())    return true;
  // if (flavor_channel == FLAVOR_EM && m_trigger.getEF_mu36_tight())     return true;

  return false;
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
  // select all signal jets
  m_jets.setCollection( JET_ALL_SIGNAL
                      , *m_jets.getCollection(JET_B)
                      );

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
  m_met.constructMetRel( m_electrons.getCollection(EL_SELECTED)
                       , m_muons.getCollection(MU_SELECTED)
                       , m_jets.getCollection(JET_ALL_CENTRAL)
                       );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_event.setFlavorChannel(findFlavorChannel());
  m_event.setSignChannel(findSignCannel());

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // compute mll
  m_event_quantities.setMll( PennSusyFrame::getMll( m_event.getFlavorChannel()
                                                  , m_electrons.getCollection(EL_SELECTED)
                                                  , m_muons.getCollection(MU_SELECTED)
                                                  )
                           );

  // comput mbb
  m_event_quantities.setMbb(PennSusyFrame::getMjj(m_jets.getCollection(JET_B)));

  // compute ptll
  m_event_quantities.setPtll( PennSusyFrame::getPtll( m_event.getFlavorChannel()
                                                    , m_electrons.getCollection(EL_SELECTED)
                                                    , m_muons.getCollection(MU_SELECTED)
                                                    )
                            );

  // compute ptbb
  m_event_quantities.setPtbb(PennSusyFrame::getPtjj(m_jets.getCollection(JET_B)));

  // compute mt2
  m_event_quantities.setMt2( PennSusyFrame::getMt2( m_event.getFlavorChannel()
                                                  , &m_met
                                                  , m_electrons.getCollection(EL_SELECTED)
                                                  , m_muons.getCollection(MU_SELECTED)
                                                  )
                           );

  // compute emma mt
  m_event_quantities.setEmmaMt( PennSusyFrame::getEmmaMt( m_event.getFlavorChannel()
                                                        , m_electrons.getCollection(EL_SELECTED)
                                                        , m_muons.getCollection(MU_SELECTED)
                                                        )
                              );

  // compute dphill
  m_event_quantities.setDphill( PennSusyFrame::getDphill( m_event.getFlavorChannel()
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
    // TODO move this into function to avoid code duplication
    // set lepton SF
    double lepton_sf             = 1.;
    double lepton_sf_egamma_down = 1.;
    double lepton_sf_egamma_up   = 1.;
    double lepton_sf_muon_down   = 1.;
    double lepton_sf_muon_up     = 1.;

    size_t el_term = m_electrons.num(EL_SELECTED);
    const std::vector<PennSusyFrame::Electron*>* el_list = m_electrons.getCollection(EL_SELECTED);
    for (size_t el_it = 0; el_it != el_term; ++el_it) {
      m_egamma_sf_tool.clear();

      double this_lep_sf        = m_egamma_sf_tool.getSF(    m_event, el_list->at(el_it));
      double this_lep_sf_uncert = m_egamma_sf_tool.getUncert(m_event, el_list->at(el_it));

      lepton_sf             *= this_lep_sf;
      lepton_sf_egamma_down *= (this_lep_sf - this_lep_sf_uncert);
      lepton_sf_egamma_up   *= (this_lep_sf + this_lep_sf_uncert);
      lepton_sf_muon_down   *= this_lep_sf;
      lepton_sf_muon_up     *= this_lep_sf;
    }

    size_t mu_term = m_muons.num(MU_SELECTED);
    const std::vector<PennSusyFrame::Muon*>* mu_list = m_muons.getCollection(MU_SELECTED);
    for (size_t mu_it = 0; mu_it != mu_term; ++mu_it) {
      double this_lep_sf        = m_muon_sf_tool.getSF(mu_list->at(mu_it));
      double this_lep_sf_uncert = m_muon_sf_tool.getUncert(mu_list->at(mu_it));

      lepton_sf             *= this_lep_sf;
      lepton_sf_egamma_down *= this_lep_sf;
      lepton_sf_egamma_up   *= this_lep_sf;
      lepton_sf_muon_down   *= (this_lep_sf - this_lep_sf_uncert);
      lepton_sf_muon_up     *= (this_lep_sf + this_lep_sf_uncert);
    }

    m_event_quantities.setLeptonSF(          lepton_sf            );
    m_event_quantities.setLeptonSFEgammaUp(  lepton_sf_egamma_up  );
    m_event_quantities.setLeptonSFEgammaDown(lepton_sf_egamma_down);
    m_event_quantities.setLeptonSFMuonUp(    lepton_sf_muon_up    );
    m_event_quantities.setLeptonSFMuonDown(  lepton_sf_muon_down  );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // set trigger weight
    m_event_quantities.setTriggerWeight(m_trigger_weight_tool.getWeight( m_event.getFlavorChannel()
                                                                       , m_electrons.getCollection(EL_SELECTED)
                                                                       , m_muons.getCollection(MU_SELECTED)
                                                                       , m_jets.getCollection(JET_SELECTED)
                                                                       , m_met
                                                                       , m_vertices.getCollection(VERTEX_GOOD)
                                                                       )
                                       );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // set b tag weight
    m_event_quantities.setBTagSF(    m_b_tag_sf_tool.getSF(        m_jets.getCollection(JET_GOOD), m_mc_truth));
    m_event_quantities.setBTagSFUp(  m_b_tag_sf_tool.getUncertUp(  m_jets.getCollection(JET_GOOD), m_mc_truth));
    m_event_quantities.setBTagSFDown(m_b_tag_sf_tool.getUncertDown(m_jets.getCollection(JET_GOOD), m_mc_truth));

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // prepare truth match tool
    m_truth_match_tool.prep(m_mc_truth);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // check for prompt leptons
    m_event.setPromptLeptons( m_truth_match_tool.isRealLeptonEvent( m_event.getFlavorChannel()
                                                                  , m_electrons.getCollection(EL_SELECTED)
                                                                  , m_muons.getCollection(MU_SELECTED)
                                                                  , m_mc_truth
                                                                  )
                             );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // get the truth sign channel of the two leptons
    m_event.setTruthSignChannel( m_truth_match_tool.getTruthSign( m_event.getFlavorChannel()
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
  // if this is data, don't fill for wrong phase space + data stream combination
  //   (egamma = ee+em , muon = mm+me)
  if (m_is_data) {
    if (  m_is_egamma_stream
       && (  m_event.getPhaseSpace() == PHASE_MM
          || m_event.getPhaseSpace() == PHASE_ME
          )
       ) {
      return;
    }
    if (  !m_is_egamma_stream
       && (  m_event.getPhaseSpace() == PHASE_EE
          || m_event.getPhaseSpace() == PHASE_EM
         )
       ) {
      return;
    }
  }

  // loop through basic histogram handlers to fill
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

  // fill b-l histograms
  if (m_pass_bl_pairing) {
    m_bminusl_histogram_handler.at(hist_level)->FillSpecial( m_event
                                                           , m_jets.getCollection(JET_B)
                                                           , *bl_0
                                                           , *bl_1
                                                           , m_mc_truth
                                                           , weight
                                                           );
    m_weight_histogram_handler.at(hist_level)->FillSpecial( m_event
                                                          , m_event_quantities
                                                          , m_xsec_weight
                                                          , m_ttbar_pt_weight
                                                          );
    if (!m_is_data) {
      m_parent_histogram_handler.at(hist_level)->FillSpecial( m_event
                                                            , *bl_0
                                                            , *bl_1
                                                            , m_mc_truth
                                                            , weight
                                                            );
    }

    // if flagged, fill detailed b-l histograms
    if (m_do_detailed_bl_hists) {
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
}
