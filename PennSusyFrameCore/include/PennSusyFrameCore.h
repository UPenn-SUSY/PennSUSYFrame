#ifndef PENNSUSYFRAME_H
#define PENNSUSYFRAME_H

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// =============================================================================
class TBranch;

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
      TTree          *fChain;   //!pointer to the analyzed TTree or TChain
      Int_t           fCurrent; //!current Tree number in a TChain

    private:
  };
}

#endif
