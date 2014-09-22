#ifndef BMinusLCutFlowTracker_h
#define BMinusLCutFlowTracker_h

// =============================================================================
#include "CutFlowTracker/include/CutFlowTracker.h"
#include <vector>
#include "TH1D.h"

// =============================================================================
enum BMINUSL_CUTS { BMINUSL_CUT_ALL
                  , BMINUSL_CUT_BREAK_0
                  , BMINUSL_CUT_MC_EVENT_WEIGHT
                  , BMINUSL_CUT_PILEUP_WEIGHT
                  , BMINUSL_CUT_XSEC_WEIGHT
                  , BMINUSL_CUT_BREAK_1
                  , BMINUSL_CUT_GRL
                  , BMINUSL_CUT_INCOMPLETE_EVENT
                  , BMINUSL_CUT_LAR_ERROR
                  , BMINUSL_CUT_TILE_ERROR
                  , BMINUSL_CUT_TILE_HOT_SPOT
                  , BMINUSL_CUT_TILE_TRIP
                  , BMINUSL_CUT_BAD_JET_VETO
                  , BMINUSL_CUT_CALO_PROBLEM_JET
                  , BMINUSL_CUT_PRIMARY_VERTEX
                  , BMINUSL_CUT_BAD_MUON
                  , BMINUSL_CUT_COSMIC_MUON_VETO
                  , BMINUSL_CUT_HFOR
                  , BMINUSL_CUT_MC_OVERLAP
                  , BMINUSL_CUT_BREAK_2
                  , BMINUSL_CUT_GE_2_BASELINE_LEPTONS
                  // , BMINUSL_CUT_EQ_2_BASELINE_LEPTONS
                  , BMINUSL_CUT_GE_2_SIGNAL_LEPTON
                  // , BMINUSL_CUT_EQ_2_SIGNAL_LEPTON
                  , BMINUSL_CUT_LEP_SF
                  , BMINUSL_CUT_OS_LEP
                  , BMINUSL_CUT_BREAK_5
                  , BMINUSL_CUT_TRIGGER
                  , BMINUSL_CUT_PHASE
                  , BMINUSL_CUT_TRIGGER_WEIGHT
                  , BMINUSL_CUT_BREAK_3
                  , BMINUSL_CUT_GE_2_B_JET
                  // , BMINUSL_CUT_EQ_2_B_JET
                  , BMINUSL_CUT_B_TAG_SF
                  , BMINUSL_CUT_BL_PAIRING
                  , BMINUSL_CUT_TTBAR_WEIGHT
                  , BMINUSL_CUT_BREAK_4
                  , BMINUSL_CUT_ZVETO
                  // , BMINUSL_CUT_MET
                  , BMINUSL_CUT_N
                  };
const std::string BMINUSL_CUT_STRINGS[] = { "BMINUSL_CUT_ALL"
                                          , "BREAK"
                                          , "BMINUSL_CUT_MC_EVENT_WEIGHT"
                                          , "BMINUSL_CUT_PILEUP_WEIGHT"
                                          , "BMINUSL_CUT_XSEC_WEIGHT"
                                          , "BREAK"
                                          , "BMINUSL_CUT_GRL"
                                          , "BMINUSL_CUT_INCOMPLETE_EVENT"
                                          , "BMINUSL_CUT_LAR_ERROR"
                                          , "BMINUSL_CUT_TILE_ERROR"
                                          , "BMINUSL_CUT_TILE_HOT_SPOT"
                                          , "BMINUSL_CUT_TILE_TRIP"
                                          , "BMINUSL_CUT_BAD_JET_VETO"
                                          , "BMINUSL_CUT_CALO_PROBLEM_JET"
                                          , "BMINUSL_CUT_PRIMARY_VERTEX"
                                          , "BMINUSL_CUT_BAD_MUON"
                                          , "BMINUSL_CUT_COSMIC_MUON_VETO"
                                          , "BMINUSL_CUT_HFOR"
                                          , "BMINUSL_CUT_MC_OVERLAP"
                                          , "BREAK"
                                          , "BMINUSL_CUT_GE_2_BASELINE_LEPTONS"
                                          // , "BMINUSL_CUT_EQ_2_BASELINE_LEPTONS"
                                          , "BMINUSL_CUT_GE_2_SIGNAL_LEPTON"
                                          // , "BMINUSL_CUT_EQ_2_SIGNAL_LEPTON"
                                          , "BMINUSL_CUT_LEP_SF"
                                          , "BMINUSL_CUT_OS_LEP"
                                          , "BREAK"
                                          , "BMINUSL_CUT_TRIGGER"
                                          , "BMINUSL_CUT_PHASE"
                                          , "BMINUSL_CUT_TRIGGER_WEIGHT"
                                          , "BREAK"
                                          , "BMINUSL_CUT_GE_2_B_JET"
                                          // , "BMINUSL_CUT_EQ_2_B_JET"
                                          , "BMINUSL_CUT_B_TAG_SF"
                                          , "BMINUSL_CUT_BL_PAIRING"
                                          , "BMINUSL_CUT_TTBAR_WEIGHT"
                                          , "BREAK"
                                          , "BMINUSL_CUT_ZVETO"
                                          // , "BMINUSL_CUT_MET"
                                          };

// =============================================================================
class BMinusLCutFlowTracker : public CutFlowTracker
{
  // ---------------------------------------------------------------------------
  public:
    BMinusLCutFlowTracker();
    virtual ~BMinusLCutFlowTracker();

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
