#include "PennSusyFrameCore/include/PennSusyFrameCore.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <dirent.h>
#include <math.h>
#include <algorithm>

#include "PennSusyFrameCore/include/D3PDReader.h"
#include "PennSusyFrameCore/include/ObjectContainers.h"

// #include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
// #include "PennSusyFrameCore/include/ObjectDefs.h"
// #include "PennSusyFrameCore/include/OverlapRemoval.h"
#include "ProgressBar/include/ProgressBar.h"

// -----------------------------------------------------------------------------
// PennSusyFrame::PennSusyFrameCore::PennSusyFrameCore(TTree* tree) : fChain(0)
PennSusyFrame::PennSusyFrameCore::PennSusyFrameCore(TTree* tree) : m_d3pd_reader(0)
{
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.
  Init(tree);
}

// -----------------------------------------------------------------------------
PennSusyFrame::PennSusyFrameCore::~PennSusyFrameCore()
{
  // if (!fChain) return;
  // delete fChain->GetCurrentFile();

  if (m_d3pd_reader) delete m_d3pd_reader;
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
  // m_d3pd_reader->Init(tree);
  m_d3pd_reader = new PennSusyFrame::D3PDReader(tree);

  m_event.init();
  m_vertices.init();
  m_electrons.init();
  m_muons.init();
  m_taus.init();
  m_jets.init();

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
  m_electron_selectors.at(EL_SIGNAL).setPtIsoCut(-1, 0.16);
  m_electron_selectors.at(EL_SIGNAL).setEtIsoCut(-1, 0.18);

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
  m_muon_selectors.at(MU_SIGNAL).setPtIsoCut(-1, 0.12);

  // MU_BAD
  m_muon_selectors.at(MU_BAD).setQOverPRatioCut(0.2, -1);

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
  // TODO check calo problem definitions
  m_jet_selectors.at(JET_CALO_PROBLEM).setPtCut(40.e3, -1);
  m_jet_selectors.at(JET_CALO_PROBLEM).setBchCorrCut(0.05, -1);
  m_jet_selectors.at(JET_CALO_PROBLEM).setDphiMet(-1, 0.3);

  // JET_LIGHT
  m_jet_selectors.at(JET_LIGHT).setPtCut(20.e3, -1);
  // m_jet_selectors.at(JET_LIGHT).setEtaCut(-1, 2.4);
  m_jet_selectors.at(JET_LIGHT).setConstScaleEtaCut(-1, 2.4);
  m_jet_selectors.at(JET_LIGHT).setJvfCut(0.0, -1);
  m_jet_selectors.at(JET_LIGHT).setJvfPtThresh(50.e3, -1);
  m_jet_selectors.at(JET_LIGHT).setMV1Cut(-1, 0.3511);

  // JET_B
  m_jet_selectors.at(JET_B).setPtCut(20.e3, -1);
  // m_jet_selectors.at(JET_B).setEtaCut(-1, 2.4);
  m_jet_selectors.at(JET_B).setConstScaleEtaCut(-1, 2.4);
  m_jet_selectors.at(JET_B).setMV1Cut(0.3511, -1);

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
  // if (fChain == 0) {
  //   std::cout << "Chain is empty - cannot loop over events :-(\n";
  //   return;
  // }

  // Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nentries = m_d3pd_reader->getNumEvents();
  std::cout << "Processing " << nentries << " events\n";

  ProgressBar progress_bar(nentries, 100);

  // Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {

    if (jentry > 1000) break;

    progress_bar.checkProgress(jentry);

    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    m_d3pd_reader->GetEntry(jentry);

    // // nb = fChain->GetEntry(jentry);
    // nb = fChain->GetEntry(jentry);
    // nbytes += nb;

    clearObjects();
    constructObjects();
    processEvent();
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::clearObjects()
{
  m_met.clear();
  m_vertices.clear();
  m_electrons.clear();
  m_muons.clear();
  m_taus.clear();
  m_jets.clear();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::constructObjects()
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // get basic event variables
  m_event.getEvent(m_d3pd_reader);

  // // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // // prep vertices
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
  m_met.prep( m_d3pd_reader
            , m_event
            , m_electrons.getCollection(EL_GOOD)
            , m_muons.getCollection(MU_GOOD)
            , m_jets.getCollection(JET_GOOD)
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

  // select signal jets from good jets
  m_jets.setCollection( JET_LIGHT
                      , PennSusyFrame::selectObjects( m_jet_selectors.at(JET_LIGHT)
                                                    , m_jets.getCollection(JET_GOOD)
                                                    )
                      );
  m_jets.setCollection( JET_B
                      , PennSusyFrame::selectObjects( m_jet_selectors.at(JET_B)
                                                    , m_jets.getCollection(JET_GOOD)
                                                    )
                      );
  m_jets.setCollection( JET_FORWARD
                      , PennSusyFrame::selectObjects( m_jet_selectors.at(JET_FORWARD)
                                                    , m_jets.getCollection(JET_GOOD)
                                                    )
                      );

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // construct met-rel
  m_met.constructMetRel( m_electrons.getCollection(EL_GOOD)
                       , m_muons.getCollection(MU_GOOD)
                       , m_jets.getCollection(JET_GOOD)
                       );
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::processEvent()
{
  // TODO make placeholder processEvent
  std::cout << "\n";
  std::cout << "\n================================================================================\n";
  m_event.print();

  // std::cout << "\n";
  // m_vertices.print(VERTEX_ALL);
  // m_vertices.print(VERTEX_GT_2);
  // m_vertices.print(VERTEX_GOOD);

  std::cout << "\n";
  m_electrons.print(EL_ALL);
  m_electrons.print(EL_BASELINE);
  m_electrons.print(EL_GOOD);
  m_electrons.print(EL_SIGNAL);

  std::cout << "\n";
  m_muons.print(MU_ALL);
  m_muons.print(MU_BASELINE);
  m_muons.print(MU_GOOD);
  m_muons.print(MU_SIGNAL);
  m_muons.print(MU_BAD);
  m_muons.print(MU_COSMIC);

  std::cout << "\n";
  m_taus.print(TAU_ALL);
  m_taus.print(TAU_BASELINE);
  m_taus.print(TAU_GOOD);
  m_taus.print(TAU_SIGNAL);

  std::cout << "\n";
  m_jets.print(JET_ALL);
  m_jets.print(JET_BASELINE_GOOD);
  m_jets.print(JET_GOOD);
  m_jets.print(JET_BASELINE_BAD);
  m_jets.print(JET_BAD);
  m_jets.print(JET_LIGHT);
  m_jets.print(JET_B);
  m_jets.print(JET_FORWARD);

  // std::cout << "\n";
  // m_met.print();




  // std::cout << "\n";
  // m_electrons.print(EL_ALL);
  // m_electrons.print(EL_BASELINE);
  // m_electrons.print(EL_GOOD);
  // m_electrons.print(EL_SIGNAL);

  // std::cout << "\n";
  // m_muons.print(MU_ALL);
  // m_muons.print(MU_BASELINE);
  // m_muons.print(MU_GOOD);
  // m_muons.print(MU_COSMIC);
  // m_muons.print(MU_BAD);
  // m_muons.print(MU_SIGNAL);

  // std::cout << "\n";
  // m_taus.print(TAU_ALL);
  // m_taus.print(TAU_BASELINE);
  // m_taus.print(TAU_GOOD);
  // m_taus.print(TAU_SIGNAL);

  // std::cout << "\n";
  // m_jets.print(JET_ALL);
  // m_jets.print(JET_BASELINE);
  // m_jets.print(JET_BASELINE_GOOD);
  // m_jets.print(JET_BASELINE_BAD);
  // m_jets.print(JET_GOOD);
  // m_jets.print(JET_BAD);
  // m_jets.print(JET_CALO_PROBLEM);
  // m_jets.print(JET_LIGHT);
  // m_jets.print(JET_B);
  // m_jets.print(JET_FORWARD);

  // std::cout << "\n";
  // m_met.print();

  // std::cout << "\n";
  // m_vertices.print(VERTEX_ALL);
  // m_vertices.print(VERTEX_GT_2);
  // m_vertices.print(VERTEX_GOOD);
}
