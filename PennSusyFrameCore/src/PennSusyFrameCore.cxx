#include "PennSusyFrameCore/include/PennSusyFrameCore.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <dirent.h>
#include <math.h>
#include <algorithm>

#include "PennSusyFrameCore/include/D3PDReader.h"
#include "PennSusyFrameCore/include/ObjectContainers.h"
#include "PennSusyFrameCore/include/Calculators.h"
#include "PennSusyFrameCore/include/SelectorHelpers.h"

// #include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
// #include "PennSusyFrameCore/include/ObjectDefs.h"
// #include "PennSusyFrameCore/include/OverlapRemoval.h"
#include "ProgressBar/include/ProgressBar.h"

// -----------------------------------------------------------------------------
PennSusyFrame::PennSusyFrameCore::PennSusyFrameCore(TTree* tree) : m_start_entry(0)
                                                                 , m_max_num_events(-1)
                                                                 , m_is_data(true)
                                                                 , m_is_egamma_stream(true)
                                                                 , m_is_blind(true)
                                                                 , m_is_af2(false)
                                                                 , m_is_mc12b(true)
                                                                 , m_event_weight(1.)
                                                                 , m_x_sec(1.)
                                                                 , m_k_factor(1.)
                                                                 , m_filter_eff(1.)
                                                                 , m_xsec_weight(1.)
                                                                 , m_num_entries(-1)
                                                                 , m_num_generated_events(-1)
                                                                 , m_sum_mc_event_weights(-1)
                                                                 , m_fancy_progress_bar(true)
                                                                 , m_process_label("")
                                                                 , m_mv1_cut_value(0.3511)
                                                                 , m_d3pd_reader(0)
{
  std::cout << "PennSusyFrameCore()\n";
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.
  Init(tree);
}

// -----------------------------------------------------------------------------
PennSusyFrame::PennSusyFrameCore::~PennSusyFrameCore()
{
  // if (!fChain) return;
  // delete fChain->GetCurrentFile();

  if (m_d3pd_reader) {
    delete m_d3pd_reader;
    m_d3pd_reader = 0;
  }

  size_t term_1 = m_histogram_handlers.size();
  for (size_t it_1 = 0; it_1 != term_1; ++it_1) {
    size_t term_2 = m_histogram_handlers.at(it_1).size();
    for (size_t it_2 = 0; it_2 != term_2; ++it_2) {
      if (m_histogram_handlers.at(it_1).at(it_2)) {
        delete m_histogram_handlers.at(it_1).at(it_2);
        m_histogram_handlers.at(it_1).at(it_2) = 0;
      }
    }
  }
}

// -----------------------------------------------------------------------------
Int_t PennSusyFrame::PennSusyFrameCore::GetEntry(Long64_t entry)
{
  // // Read contents of entry.
  // if (!fChain) return 0;
  // return fChain->GetEntry(entry);

  return m_d3pd_reader->GetEntry(entry);
}

// -----------------------------------------------------------------------------
Long64_t PennSusyFrame::PennSusyFrameCore::LoadTree(Long64_t entry)
{
  // Set the environment to read one entry
  return m_d3pd_reader->LoadTree(entry);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::Init(TTree* tree)
{
  std::cout << "Init()\n";
  m_tree = tree;
  prepareSelection();
  Notify();
}

// -----------------------------------------------------------------------------
Bool_t PennSusyFrame::PennSusyFrameCore::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.

  return kTRUE;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::prepareTools()
{
  std::cout << "preparing tool!\n";
  std::cout << "systematics this run: \n"
            << "  do jer: "      << m_syst_struct.getSyst("do_jer")      << "\n"
            << "  do jes up: "   << m_syst_struct.getSyst("do_jes_up")   << "\n"
            << "  do jes down: " << m_syst_struct.getSyst("do_jes_down") << "\n"
            << "\n";

  // m_d3pd_reader->Init(tree);
  m_d3pd_reader = new PennSusyFrame::D3PDReader(m_tree, m_is_data);

  m_event.init();
  m_event_quantities.init();
  m_trigger.init();
  m_vertices.init();
  m_electrons.init(m_is_data, m_is_af2, &m_syst_struct);
  m_muons.init(m_is_data, &m_syst_struct);
  m_taus.init(m_is_data, m_is_af2);
  m_jets.init( m_is_data
             , m_is_af2
             , m_is_mc12b
             , &m_syst_struct
             );

  if (m_is_af2) m_egamma_sf_tool.setAf2();
  else          m_egamma_sf_tool.setFullSim();

  m_egamma_sf_tool.init();
  m_b_tag_sf_tool.init(m_mv1_cut_value);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::prepareSelection()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // vertex selectors
  m_vertex_selectors.resize(VERTEX_N);

  // VERTEX_GOOD
  m_vertex_selectors.at(VERTEX_GOOD).setNumTracksCut(5, -1);

  // VERTEX_GT_2
  m_vertex_selectors.at(VERTEX_GT_2).setNumTracksCut(2, -1);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // electron selectors
  m_electron_selectors.resize(EL_N);

  // EL_BASELINE
  m_electron_selectors.at(EL_BASELINE).setElectronQuality(EL_QUALITY_MEDPP);
  m_electron_selectors.at(EL_BASELINE).setPtCut(10.e3, -1);
  m_electron_selectors.at(EL_BASELINE).setEtaCut(-1, 2.47);

  // EL_SIGNAL
  m_electron_selectors.at(EL_SIGNAL).setElectronQuality(EL_QUALITY_TIGHTPP);
  m_electron_selectors.at(EL_SIGNAL).setD0SignificanceCut(-1, 5);
  // m_electron_selectors.at(EL_SIGNAL).setD0SignificanceCut(-1, 3);
  m_electron_selectors.at(EL_SIGNAL).setZ0SignThetaCut(-1, 0.4);
  //  m_electron_selectors.at(EL_SIGNAL).setPtIsoCut(-1, 0.05); // this is to make efficiency plots
  m_electron_selectors.at(EL_SIGNAL).setPtIsoCut(-1, 0.07);// this is actual cut
  m_electron_selectors.at(EL_SIGNAL).setEtIsoCut(-1, 0.13);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // muons selectors
  m_muon_selectors.resize(MU_N);

  // MU_BASELINE
  m_muon_selectors.at(MU_BASELINE).setPtCut(10.e3, -1);
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
  //m_muon_selectors.at(MU_SIGNAL).setPtIsoCut(-1, 0.05);// this is to make efficiency plots
  m_muon_selectors.at(MU_SIGNAL).setPtIsoCut(-1, 0.06);// this is actual cut
  m_muon_selectors.at(MU_SIGNAL).setEtIsoCut(-1, 0.14);

  // MU_BAD
  m_muon_selectors.at(MU_BAD).setQOverPRatioCut(0.2, -1);// this is actual cut
  //  m_muon_selectors.at(MU_BAD).setQOverPRatioCut(-1, -1);// this is to make efficiency plots

  // MU_COSMIC
  m_muon_selectors.at(MU_COSMIC).setReversedSelector(true);
  m_muon_selectors.at(MU_COSMIC).setD0exPVCut(-1, 0.2);
  m_muon_selectors.at(MU_COSMIC).setZ0exPVCut(-1, 1.0);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tau selectors
  m_tau_selectors.resize(TAU_N);

  // TAU_BASELINE
  m_tau_selectors.at(TAU_BASELINE).setPtCut(20.e3, -1);
  m_tau_selectors.at(TAU_BASELINE).setEtaCut(-1, 2.47);
  m_tau_selectors.at(TAU_BASELINE).setJetBdtLevel(TAU_JET_BDT_MEDIUM);
  m_tau_selectors.at(TAU_BASELINE).setEleBdtLevel(TAU_ELE_BDT_LOOSE);
  m_tau_selectors.at(TAU_BASELINE).setMuVetoLevel(TAU_MU_TIGHT);

  // TAU_SIGNAL
  m_tau_selectors.at(TAU_SIGNAL).setJetBdtLevel(TAU_JET_BDT_MEDIUM);
  m_tau_selectors.at(TAU_SIGNAL).setEleBdtLevel(TAU_ELE_BDT_LOOSE);
  m_tau_selectors.at(TAU_SIGNAL).setMuVetoLevel(TAU_MU_TIGHT);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // jet selectors
  m_jet_selectors.resize(JET_N);

  // JET_BASELINE
  m_jet_selectors.at(JET_BASELINE).setPtCut(20.e3, -1);
  m_jet_selectors.at(JET_BASELINE).setEtaCut(-1, 4.9);

  // JET_BASELINE_GOOD
  m_jet_selectors.at(JET_BASELINE_GOOD).setIsBadJet(0);

  // JET_BASELINE_BAD
  m_jet_selectors.at(JET_BASELINE_BAD).setIsBadJet(1);

  // JET_CALO_PROBLEM
  m_jet_selectors.at(JET_CALO_PROBLEM).setPtCut(40.e3, -1);
  m_jet_selectors.at(JET_CALO_PROBLEM).setBchCorrCut(0.05, -1);
  m_jet_selectors.at(JET_CALO_PROBLEM).setDphiMet(-1, 0.3);

  // JET_LIGHT
  m_jet_selectors.at(JET_LIGHT).setPtCut(20.e3, -1);
  // m_jet_selectors.at(JET_LIGHT).setEtaCut(-1, 2.4);
  m_jet_selectors.at(JET_LIGHT).setConstScaleEtaCut(-1, 2.4);
  m_jet_selectors.at(JET_LIGHT).setJvfCut(0.0, -1);
  m_jet_selectors.at(JET_LIGHT).setJvfPtThresh(50.e3, -1);
  m_jet_selectors.at(JET_LIGHT).setMV1Cut(-1, m_mv1_cut_value);

  // JET_B
  m_jet_selectors.at(JET_B).setPtCut(20.e3, -1);
  // m_jet_selectors.at(JET_B).setEtaCut(-1, 2.4);
  m_jet_selectors.at(JET_B).setConstScaleEtaCut(-1, 2.4);
  m_jet_selectors.at(JET_B).setMV1Cut(m_mv1_cut_value, -1);

  // JET_FORWARD
  m_jet_selectors.at(JET_FORWARD).setPtCut(30.e3, -1);
  // m_jet_selectors.at(JET_FORWARD).setEtaCut(2.4, 4.5);
  m_jet_selectors.at(JET_FORWARD).setConstScaleEtaCut(2.4, 4.5);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::Loop()
{
  if (m_d3pd_reader->checkStatus() == false) {
    std::cout << "Chain is empty - cannot loop over events :-(\n";
    return;
  }

  // run beginRun() function to prepare tools
  beginRun();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // find number of total events to looper over
  // TODO clean up this code!!!
  Long64_t total_nentries = m_num_entries;
  if (total_nentries <= 0) {
    total_nentries = m_d3pd_reader->getNumEvents();
  }
  Long64_t nentries = total_nentries;

  // if we set the max # events, require we don't go over this number
  if (m_max_num_events > 0 && m_max_num_events < nentries) {
    nentries = m_max_num_events;
  }
  // if start entry + nentries > total number event, limit nentries to number remaining after start entry events
  if (m_start_entry + nentries > total_nentries) {
    nentries = total_nentries - m_start_entry;
  }
  std::cout << "Processing " << nentries << " events\n";

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // set up progress bar
  ProgressBar progress_bar(nentries, 100, m_fancy_progress_bar);
  if (m_process_label != "")
    progress_bar.setProcessLabel(m_process_label);

  // Actually loop over events
  for (Long64_t jentry=0; jentry != nentries; ++jentry) {
    // if (jentry == 50000) break;

    Long64_t this_entry = m_start_entry + jentry;

    // check progress in the progress bar
    progress_bar.checkProgress(this_entry);

    // get entry from tree
    Long64_t ientry = LoadTree(this_entry);
    if (ientry < 0) break;
    m_d3pd_reader->GetEntry(this_entry);

    // process events, etc...
    clearObjects();
    constructObjects();
    processEvent();
    finalizeEvent();
  }

  // call finalizeRun() to finish run - i.e. write to file, etc.
  finalizeRun();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::beginRun()
{
  if (!m_is_data) {
    std::cout << "num generated events: " << m_num_generated_events << "\n";
    if (m_num_generated_events <= 0) {
      std::cout << "resetting num generated events: ";
      m_num_generated_events = m_d3pd_reader->getNumEvents();
      std::cout << m_num_generated_events << "\n";
    }
    if (m_sum_mc_event_weights <= 0) {
      std::cout << "setting sum of mc event weights to the number of generated events: ";
      m_sum_mc_event_weights = m_num_generated_events;
      std::cout << m_sum_mc_event_weights << "\n";
    }

    // m_xsec_weight = m_x_sec * m_k_factor * m_filter_eff / m_d3pd_reader->getNumEvents();
    // m_xsec_weight = m_x_sec * m_k_factor * m_filter_eff / m_num_generated_events;
    m_xsec_weight = m_x_sec * m_k_factor * m_filter_eff / m_sum_mc_event_weights;
    std::cout << "\n\tx sec: "                   << m_x_sec
              << "\n\tk factor: "                << m_k_factor
              << "\n\tfilter eff: "              << m_filter_eff
              << "\n\tnum gen events: "          << m_num_generated_events
              << "\n\tsum of mc event weights: " << m_sum_mc_event_weights
              << "\n\t\tx section weight: "      << m_xsec_weight
              << "\n";
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::processEvent()
{ }

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::finalizeEvent()
{ }

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::finalizeRun()
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::clearObjects()
{
  m_event_weight = 1.;
  m_pass_event = true;

  m_met.clear();
  m_vertices.clear();
  m_electrons.clear();
  m_muons.clear();
  m_taus.clear();
  m_jets.clear();

  m_egamma_sf_tool.clear();
  m_b_tag_sf_tool.clear();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::constructObjects()
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
  // do overlap removal
  m_object_cleaning.fullObjectCleaning( m_electrons
                                      , m_muons
                                      , m_taus
                                      , m_jets
                                      );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get objects which are selected for this analysis
  getSelectedObjects();

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
  // select jets which suggest caol problem in the event
  m_jets.setCollection( JET_CALO_PROBLEM
                      , PennSusyFrame::selectObjects( m_jet_selectors.at(JET_CALO_PROBLEM)
                                                    , m_jets.getCollection(JET_BASELINE)
                                                    )
                      );


  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // select signal electrons from good electrons
  m_electrons.setCollection( EL_SIGNAL
                           , PennSusyFrame::selectObjects( m_electron_selectors.at(EL_SIGNAL)
                                                         // , m_electrons.getCollection(EL_GOOD)
                                                         , m_electrons.getCollection(EL_SELECTED)
                                                         )
                           );

  // select signal muons from good muons
  m_muons.setCollection( MU_SIGNAL
                       , PennSusyFrame::selectObjects( m_muon_selectors.at(MU_SIGNAL)
                                                     // , m_muons.getCollection(MU_GOOD)
                                                     , m_muons.getCollection(MU_SELECTED)
                                                     )
                       );

  // select bad muons from good muons
  m_muons.setCollection( MU_BAD
                       , PennSusyFrame::selectObjects( m_muon_selectors.at(MU_BAD)
                                                     // , m_muons.getCollection(MU_GOOD)
                                                     , m_muons.getCollection(MU_SELECTED)
                                                     )
                       );

  // select cosmic muons from good muons
  m_muons.setCollection( MU_COSMIC
                       , PennSusyFrame::selectObjects( m_muon_selectors.at(MU_COSMIC)
                                                     // , m_muons.getCollection(MU_GOOD)
                                                     , m_muons.getCollection(MU_GOOD)
                                                     )
                       );

  // select signal taus from good taus
  m_taus.setCollection( TAU_SIGNAL
                      , PennSusyFrame::selectObjects( m_tau_selectors.at(TAU_SIGNAL)
                                                    // , m_taus.getCollection(TAU_GOOD)
                                                    , m_taus.getCollection(TAU_SELECTED)
                                                    )
                      );

  // select signal jets from good jets
  m_jets.setCollection( JET_LIGHT
                      , PennSusyFrame::selectObjects( m_jet_selectors.at(JET_LIGHT)
                                                    // , m_jets.getCollection(JET_GOOD)
                                                    , m_jets.getCollection(JET_SELECTED)
                                                    )
                      );
  m_jets.setCollection( JET_B
                      , PennSusyFrame::selectObjects( m_jet_selectors.at(JET_B)
                                                    // , m_jets.getCollection(JET_GOOD)
                                                    , m_jets.getCollection(JET_SELECTED)
                                                    )
                      );
  m_jets.setCollection( JET_FORWARD
                      , PennSusyFrame::selectObjects( m_jet_selectors.at(JET_FORWARD)
                                                    // , m_jets.getCollection(JET_GOOD)
                                                    , m_jets.getCollection(JET_SELECTED)
                                                    )
                      );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  size_t num_signal_electrons = m_electrons.num(EL_SIGNAL);
  for (size_t el_it = 0; el_it != num_signal_electrons; ++el_it) {
    m_electrons.getCollection(EL_SIGNAL)->at(el_it)->setIsSignal(true);
  }

  size_t num_signal_muons = m_muons.num(MU_SIGNAL);
  for (size_t mu_it = 0; mu_it != num_signal_muons; ++mu_it) {
    m_muons.getCollection(MU_SIGNAL)->at(mu_it)->setIsSignal(true);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  std::vector<PennSusyFrame::Jet*> signal_jets;
  signal_jets.reserve(m_jets.num(JET_ALL_CENTRAL) + m_jets.num(JET_FORWARD));
  signal_jets.insert( signal_jets.end()
                    , m_jets.getCollection(JET_ALL_CENTRAL)->begin()
                    , m_jets.getCollection(JET_ALL_CENTRAL)->end()
                    );
  signal_jets.insert( signal_jets.end()
                    , m_jets.getCollection(JET_FORWARD)->begin()
                    , m_jets.getCollection(JET_FORWARD)->end()
                    );
  m_jets.setCollection(JET_ALL_SIGNAL, signal_jets);

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
    double lepton_sf             = 1.;
    double lepton_sf_egamma_down = 1.;
    double lepton_sf_egamma_up   = 1.;
    double lepton_sf_muon_down   = 1.;
    double lepton_sf_muon_up     = 1.;

    // size_t el_term = m_electrons.num(EL_GOOD);
    // const std::vector<PennSusyFrame::Electron*>* el_list = m_electrons.getCollection(EL_GOOD);
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
    // size_t mu_term = m_muons.num(MU_GOOD);
    // const std::vector<PennSusyFrame::Muon*>* mu_list = m_muons.getCollection(MU_GOOD);
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
    m_event_quantities.setBTagSF(     m_b_tag_sf_tool.getSF(         m_jets.getCollection(JET_SELECTED), m_mc_truth));
    m_event_quantities.setBTagSFBUp(  m_b_tag_sf_tool.getUncertBUp(  m_jets.getCollection(JET_SELECTED), m_mc_truth));
    m_event_quantities.setBTagSFCUp(  m_b_tag_sf_tool.getUncertCUp(  m_jets.getCollection(JET_SELECTED), m_mc_truth));
    m_event_quantities.setBTagSFLUp(  m_b_tag_sf_tool.getUncertLUp(  m_jets.getCollection(JET_SELECTED), m_mc_truth));
    m_event_quantities.setBTagSFBDown(m_b_tag_sf_tool.getUncertBDown(m_jets.getCollection(JET_SELECTED), m_mc_truth));
    m_event_quantities.setBTagSFCDown(m_b_tag_sf_tool.getUncertCDown(m_jets.getCollection(JET_SELECTED), m_mc_truth));
    m_event_quantities.setBTagSFLDown(m_b_tag_sf_tool.getUncertLDown(m_jets.getCollection(JET_SELECTED), m_mc_truth));

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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
  else //data
    {

      m_event.setPromptLeptons(true);
    }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::getSelectedObjects()
{
  // default selected objects will simply copy the "good" objects lists
  std::vector<PennSusyFrame::Electron*> good_el_list(*m_electrons.getCollection(EL_GOOD));
  m_electrons.setCollection(EL_SELECTED , good_el_list);

  std::vector<PennSusyFrame::Muon*> good_mu_list(*m_muons.getCollection(MU_GOOD));
  m_muons.setCollection(MU_SELECTED , good_mu_list);

  std::vector<PennSusyFrame::Jet*> good_jet_list(*m_jets.getCollection(JET_GOOD));
  m_jets.setCollection(JET_SELECTED , good_jet_list);

  std::vector<PennSusyFrame::Tau*> good_tau_list(*m_taus.getCollection(TAU_GOOD));
  m_taus.setCollection(TAU_SELECTED , good_tau_list);
}

// -----------------------------------------------------------------------------
FLAVOR_CHANNEL PennSusyFrame::PennSusyFrameCore::findFlavorChannel(bool exclusive_flavor_channel)
{
  size_t num_el = m_electrons.num(EL_GOOD);
  size_t num_mu = m_muons.num(MU_GOOD);
//  size_t num_el = m_electrons.num(EL_SELECTED);
//  size_t num_mu = m_muons.num(MU_SELECTED);
//
  if (num_el + num_mu < 2) return FLAVOR_NONE;

  if (!exclusive_flavor_channel && num_el+num_mu > 2) {
    // TODO if there are more than two leptons, and we set exclusive_flavor_channel == false, check flavor of leading two leptons
    // num_el = 0;
    // num_mu = 0;
  }

  if (num_el == 2 && num_mu == 0) return FLAVOR_EE;
  if (num_el == 1 && num_mu == 1) return FLAVOR_EM;
  if (num_el == 0 && num_mu == 2) return FLAVOR_MM;
  return FLAVOR_NONE;
}

// -----------------------------------------------------------------------------
SIGN_CHANNEL PennSusyFrame::PennSusyFrameCore::findSignCannel()
{
  // if no flavor channel, there is no sign channel -- return none
  if (m_event.getFlavorChannel() == FLAVOR_NONE) return SIGN_NONE;

  // find the sign channel - depends on which flavor channel we are in
  int sign = 1;
  if (m_event.getFlavorChannel() == FLAVOR_EE) {
    // sign *= m_electrons.getCollection(EL_GOOD)->at(0)->getCharge();
    // sign *= m_electrons.getCollection(EL_GOOD)->at(1)->getCharge();
    sign *= m_electrons.getCollection(EL_SELECTED)->at(0)->getCharge();
    sign *= m_electrons.getCollection(EL_SELECTED)->at(1)->getCharge();
  }
  else if (m_event.getFlavorChannel() == FLAVOR_EM) {
    // sign *= m_electrons.getCollection(EL_GOOD)->at(0)->getCharge();
    // sign *= m_muons.getCollection(MU_GOOD)->at(0)->getCharge();
    sign *= m_electrons.getCollection(EL_SELECTED)->at(0)->getCharge();
    sign *= m_muons.getCollection(MU_SELECTED)->at(0)->getCharge();
  }
  else if (m_event.getFlavorChannel() == FLAVOR_MM) {
    // sign *= m_muons.getCollection(MU_GOOD)->at(0)->getCharge();
    // sign *= m_muons.getCollection(MU_GOOD)->at(1)->getCharge();
    sign *= m_muons.getCollection(MU_SELECTED)->at(0)->getCharge();
    sign *= m_muons.getCollection(MU_SELECTED)->at(1)->getCharge();
  }

  // return the correct sign channel
  if (sign > 0) return SIGN_SS;
  if (sign < 0) return SIGN_OS;
  std::cout << "\nWARNING!!! Event " << m_event.getEventNumber()
            << " has flavor channel " << FLAVOR_CHANNEL_STRINGS[m_event.getFlavorChannel()]
            << " but does not fit in a sign channel! Something went wrong!\n";
  return SIGN_NONE;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::configureTnt( std::string out_file_name
                                                   , std::string in_file_name
                                                   )
{
  m_d3pd_reader->ConfigureOutput(out_file_name, in_file_name);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::fillTnt()
{
  m_d3pd_reader->FillEvent();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::writeTnt()
{
  std::cout << "num generated events: " << m_num_generated_events << "\n";
  if (m_num_generated_events <= 0) {
    std::cout << "resetting num generated events: ";
    m_num_generated_events = m_d3pd_reader->getNumEvents();
    std::cout << m_num_generated_events << "\n";
  }

  std::cout << "writeTnt():"
            << "\n\t-- total num events:    " << m_num_generated_events
            << "\n\t-- sum mc event weight: " << m_sum_mc_event_weights
            << "\n";
  m_d3pd_reader->FinalizeOutput(m_num_generated_events, m_sum_mc_event_weights);
}
