#ifndef PENNSUSYFRAME_H
#define PENNSUSYFRAME_H

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "PennSusyFrameCore/include/ObjectContainers.h"

// =============================================================================
class TBranch;

namespace PennSusyFrame
{
  class D3PDReader;
}

// =============================================================================
namespace PennSusyFrame
{
  // ===========================================================================
  class PennSusyFrameCore {
    public :
      PennSusyFrameCore(TTree *tree=0);
      virtual ~PennSusyFrameCore();
      virtual Int_t    GetEntry(Long64_t entry);
      virtual Long64_t LoadTree(Long64_t entry);
      virtual void     Init(TTree *tree);
      virtual void     Loop();
      virtual Bool_t   Notify();

      virtual void clearObjects();
      virtual void constructObjects();
      virtual void processEvent();

    protected:
      // TTree          *fChain;   //!pointer to the analyzed TTree or TChain
      // Int_t           fCurrent; //!current Tree number in a TChain

      PennSusyFrame::D3PDReader* m_d3pd_reader;

      PennSusyFrame::ElectronContainer m_electrons;
      PennSusyFrame::MuonContainer     m_muons;
      PennSusyFrame::JetContainer      m_jets;

    private:
  };
}

#endif
