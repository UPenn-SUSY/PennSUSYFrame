#ifndef IsrCutFlowTracker_h
#define IsrCutFlowTracker_h

// =============================================================================
#include "CutFlowTracker/include/CutFlowTracker.h"
#include <vector>
#include "TH1D.h"

// =============================================================================
enum ISR_CUTS { ISR_CUT_ALL
              , ISR_CUT_BREAK_0
              , ISR_CUT_MC_EVENT_WEIGHT
              , ISR_CUT_PILEUP_WEIGHT
              , ISR_CUT_XSEC_WEIGHT
              , ISR_CUT_BREAK_1
              , ISR_CUT_GRL
              , ISR_CUT_INCOMPLETE_EVENT
              , ISR_CUT_LAR_ERROR
              , ISR_CUT_TILE_ERROR
              , ISR_CUT_TILE_HOT_SPOT
              , ISR_CUT_TILE_TRIP
              , ISR_CUT_BAD_JET_VETO
              , ISR_CUT_CALO_PROBLEM_JET
              , ISR_CUT_PRIMARY_VERTEX
              , ISR_CUT_BAD_MUON
              , ISR_CUT_COSMIC_MUON_VETO
              , ISR_CUT_HFOR
              , ISR_CUT_MC_OVERLAP
              , ISR_CUT_BREAK_2
              , ISR_CUT_GE_2_BASELINE_LEPTONS
              , ISR_CUT_EQ_2_BASELINE_LEPTONS
              , ISR_CUT_MLL_SFOS
              , ISR_CUT_EQ_2_SIGNAL_LEPTON
              , ISR_CUT_LEP_SF
              , ISR_CUT_BREAK_3
              , ISR_CUT_PHASE_SPACE
              , ISR_CUT_TRIGGER
              , ISR_CUT_TRIGGER_MATCHING
              , ISR_CUT_TRIGGER_WEIGHT
              , ISR_CUT_BREAK_4
              , ISR_CUT_TAU_VETO
	      , ISR_CUT_OS
	      , ISR_CUT_PROMPT_LEP
	      , ISR_CUT_Z_WINDOW
	      , ISR_CUT_N
              };
const std::string ISR_CUT_STRINGS[] = { "ISR_CUT_ALL"
                                      , "BREAK"
                                      , "ISR_CUT_MC_EVENT_WEIGHT"
                                      , "ISR_CUT_PILEUP_WEIGHT"
                                      , "ISR_CUT_XSEC_WEIGHT"
                                      , "BREAK"
                                      , "ISR_CUT_GRL"
                                      , "ISR_CUT_INCOMPLETE_EVENT"
                                      , "ISR_CUT_LAR_ERROR"
                                      , "ISR_CUT_TILE_ERROR"
                                      , "ISR_CUT_TILE_HOT_SPOT"
                                      , "ISR_CUT_TILE_TRIP"
                                      , "ISR_CUT_BAD_JET_VETO"
                                      , "ISR_CUT_CALO_PROBLEM_JET"
                                      , "ISR_CUT_PRIMARY_VERTEX"
                                      , "ISR_CUT_BAD_MUON"
                                      , "ISR_CUT_COSMIC_MUON_VETO"
                                      , "ISR_CUT_HFOR"
                                      , "ISR_CUT_MC_OVERLAP"
                                      , "BREAK"
                                      , "ISR_CUT_GE_2_BASELINE_LEPTONS"
                                      , "ISR_CUT_EQ_2_BASELINE_LEPTONS"
                                      , "ISR_CUT_MLL_SFOS"
                                      , "ISR_CUT_EQ_2_SIGNAL_LEPTON"
                                      , "ISR_CUT_LEP_SF"
                                      , "BREAK"
                                      , "ISR_CUT_PHASE_SPACE"
                                      , "ISR_CUT_TRIGGER"
                                      , "ISR_CUT_TRIGGER_MATCHING"
                                      , "ISR_CUT_TRIGGER_WEIGHT"
                                      , "BREAK"
                                      , "ISR_CUT_TAU_VETO"
				      , "ISR_CUT_OS"
				      ,  "ISR_CUT_PROMPT_LEP"
				      , "ISR_CUT_Z_WINDOW"

};

// =============================================================================
class IsrCutFlowTracker : public CutFlowTracker
{
  // ---------------------------------------------------------------------------
  public:
    IsrCutFlowTracker();
    virtual ~IsrCutFlowTracker();

    virtual void fillHist(int channel, int bin, float weight = 1.);

    virtual void printToScreen();
    virtual void printLine(int);
    // virtual void printToFile(std::string out_file_name);

  // ---------------------------------------------------------------------------
  protected:
    virtual void initBinList();
    virtual void initCutFlowHists();

  // -----------------------------------------------------------------------------
  private:
};

#endif
