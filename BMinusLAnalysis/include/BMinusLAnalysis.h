#ifndef BMINUSLANALYSIS_H
#define BMINUSLANALYSIS_H

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "PennSusyFrameCore/include/PennSusyFrameCore.h"

// =============================================================================
namespace PennSusyFrame
{
  // ===========================================================================
  class BMinusLAnalysis : public PennSusyFrame::PennSusyFrameCore
  {
    public :
      BMinusLAnalysis(TTree *tree=0);
      virtual ~BMinusLAnalysis();

      virtual void processEvent();
      virtual void finalizeEvent();

    protected:

    private:
  };
}

#endif
