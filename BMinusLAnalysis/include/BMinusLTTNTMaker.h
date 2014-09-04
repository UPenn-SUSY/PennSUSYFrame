#ifndef BMINUSLTTNTMAKER_H
#define BMINUSLTTNTMAKER_H

#include <TROOT.h>
#include <TChain.h>

#include "PennSusyFrameCore/include/EventSelectors.h"
#include "BMinusLAnalysis/include/BMinusLAnalysis.h"

// =============================================================================
class TFile;
class TTree;

// =============================================================================
namespace PennSusyFrame
{
  // ---------------------------------------------------------------------------
  class blPair;

  // ===========================================================================
  class BMinusLTTNTMaker : public PennSusyFrame::BMinusLAnalysis
  {
    public :
      BMinusLTTNTMaker(TTree *tree=0);
      virtual ~BMinusLTTNTMaker();

      virtual void prepareTools();
      virtual void beginRun();
      // virtual void initializeEvent();
      virtual void finalizeEvent();
      virtual void finalizeRun();

      void setOutNtupleFileName(std::string val) { m_out_ntuple_file_name = val; }

    protected:
      std::string m_out_ntuple_file_name;

      // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    private:
  };
}

#endif
