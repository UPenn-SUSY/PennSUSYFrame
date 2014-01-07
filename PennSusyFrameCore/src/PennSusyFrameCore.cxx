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

  m_electrons.init();
  m_muons.init();
  m_jets.init();

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

    std::cout << "Loading tree for entry " << jentry << "\n";
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    std::cout << "getting entry for entry " << jentry << "\n";
    m_d3pd_reader->GetEntry(jentry);
    std::cout << "done getting entry " << jentry << "\n";

    // // nb = fChain->GetEntry(jentry);
    // nb = fChain->GetEntry(jentry);
    // nbytes += nb;

    // clearObjects();
    // constructObjects();
    // processEvent();
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::clearObjects()
{
  std::cout << "clearObjects()\n";
  // TODO clear objects
  m_electrons.clear();
  m_muons.clear();
  m_jets.clear();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::constructObjects()
{
  std::cout << "constructObjects()\n";
  // TODO construct obejects
  m_electrons.prep(m_d3pd_reader);
  m_muons.prep(m_d3pd_reader);
  m_jets.prep(m_d3pd_reader);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::PennSusyFrameCore::processEvent()
{
  // TODO make template processEvent
  std::cout << "--------------------------------------------------------------------------------\n";
  std::cout << "event number: " << m_d3pd_reader->EventNumber << "\n";
  m_electrons.print(EL_ALL);
}
