#ifndef CutFlowDump_h
#define CutFlowDump_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>

#include "NtupleLooper/include/NtupleLooper.h"

#include "SusyAnalysisTools/include/EventDescription.h"
#include "SusyAnalysisTools/include/SRHelper.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

enum WEIGHTS { WEIGHT_NONE = 0
             , WEIGHT_MC_EVENT
             , WEIGHT_PILE_UP
             , WEIGHT_LEPTON
             , WEIGHT_B_TAG
             , WEIGHT_TRIGGER
             , WEIGHT_ALL
             , WEIGHT_N
             };
std::string getWeightName(WEIGHTS);

// =============================================================================
class CutFlowDump : public NtupleLooper {
  // ---------------------------------------------------------------------------
  public :
    CutFlowDump(TTree *tree=0);
    virtual ~CutFlowDump();
    // virtual void     Init(TTree *tree);

    virtual void processEvent();

    void initCutFlowHists();
    void checkEvent(PHASE_SPACE, WEIGHTS);

    void fillHist( PHASE_SPACE phase
                 , WEIGHTS weight_type
                 , unsigned int cut_bin
                 , double weight = 1.
                 );

    void printToScreen();
    void printToScreen(WEIGHTS);
    void printToFile(std::string out_file_name);

    // ---------------------------------------------------------------------------
  protected:
    std::vector<std::vector<TH1D*> > m_cutflow;
};

#endif
