#ifndef HistMaker_h
#define HistMaker_h

#include <iostream>

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>

#include "NtupleLooper/include/NtupleLooper.h"

#include "Selection/include/EventSelection.h"

#include "SusyAnalysisTools/include/EventDescription.h"
#include "SusyAnalysisTools/include/SRHelper.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class HistMaker : public NtupleLooper
{
  // ---------------------------------------------------------------------------
  public :
    HistMaker(TTree *tree=0);
    virtual ~HistMaker();

    virtual void processEvent();

  // ---------------------------------------------------------------------------
  protected:
};

#endif
