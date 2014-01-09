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
  // TODO check good vertex definitions
  m_vertex_selectors.resize(VERTEX_N);
  m_vertex_selectors.at(VERTEX_GOOD).setNumTracksCut(5, -1);

  m_vertex_selectors.at(VERTEX_GT_2).setNumTracksCut(2, -1);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // electron selectors
  // TODO check baseline electron definitions
  m_electron_selectors.resize(EL_N);
  m_electron_selectors.at(EL_BASELINE).setPtCut(10.e3, -1);
  m_electron_selectors.at(EL_BASELINE).setEtaCut(-1, 2.4);

  // TODO check signal electron definitions

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // muons selectors
  m_muon_selectors.resize(MU_N);
  // TODO check baseline muon definitions
  m_muon_selectors.at(MU_BASELINE).setPtCut(10.e3, -1);
  m_muon_selectors.at(MU_BASELINE).setEtaCut(-1, 2.4);

  // TODO check signal muon definitions

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // tau selectors
  m_tau_selectors.resize(TAU_N);
  // TODO check baseline tau definitions
  m_tau_selectors.at(TAU_BASELINE).setPtCut(10.e3, -1);
  m_tau_selectors.at(TAU_BASELINE).setEtaCut(-1, 2.4);

  // TODO check signal tau definitions

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // jet selectors
  m_jet_selectors.resize(JET_N);
  // TODO check baseline jet definitions
  m_jet_selectors.at(JET_BASELINE).setPtCut(20.e3, -1);
  m_jet_selectors.at(JET_BASELINE).setEtaCut(-1, 4.9);

  // TODO check baseline bad definitions

  // TODO check baseline good definitions

  // TODO check baseline light jet definitions

  // TODO check baseline b jet definitions

  // TODO check baseline forward jet definitions
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
  m_vertices.clear();
  m_electrons.clear();
  m_muons.clear();
  m_taus.clear();
  m_jets.clear();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::constructObjects()
{
  m_event.getEvent(m_d3pd_reader);

  m_vertices.prep(m_d3pd_reader);
  m_vertices.setCollection( VERTEX_GOOD
                          , PennSusyFrame::selectObjects( m_vertex_selectors.at(VERTEX_GOOD)
                                                        , m_vertices.getCollection(VERTEX_ALL)
                                                        )
                          );
  m_vertices.setCollection( VERTEX_GT_2
                          , PennSusyFrame::selectObjects( m_vertex_selectors.at(VERTEX_GT_2)
                                                        , m_vertices.getCollection(VERTEX_ALL)
                                                        )
                          );

  // m_electrons.prep(m_d3pd_reader);
  // m_muons.prep(m_d3pd_reader);
  // m_taus.prep(m_d3pd_reader);
  // m_jets.prep(m_d3pd_reader, &m_event, &m_vertices);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::processEvent()
{
  // // TODO make template processEvent
  // std::cout << "\n================================================================================\n";
  // m_event.print();
  // m_vertices.print(VERTEX_ALL);
  // m_electrons.print(EL_ALL);
  // m_muons.print(MU_ALL);
  // m_taus.print(TAU_ALL);
  // m_jets.print(JET_ALL);
}
