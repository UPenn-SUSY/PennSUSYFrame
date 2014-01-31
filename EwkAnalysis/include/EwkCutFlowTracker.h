#ifndef EwkCutFlowTracker_h
#define EwkCutFlowTracker_h

// =============================================================================
#include "CutFlowTracker/include/CutFlowTracker.h"
#include <vector>
#include "TH1D.h"

// =============================================================================
enum EWK_CUTS { EWK_CUT_ALL
              , EWK_CUT_BREAK_0
              , EWK_CUT_GRL
              , EWK_CUT_INCOMPLETE_EVENT
              , EWK_CUT_LAR_ERROR
              , EWK_CUT_TILE_ERROR
              , EWK_CUT_TILE_HOT_SPOT
              , EWK_CUT_TILE_TRIP
              , EWK_CUT_BAD_JET_VETO
              , EWK_CUT_CALO_PROBLEM_JET
              , EWK_CUT_PRIMARY_VERTEX
              , EWK_CUT_BAD_MUON
              , EWK_CUT_COSMIC_MUON_VETO
              , EWK_CUT_HFOR
              , EWK_CUT_MC_OVERLAP
              , EWK_CUT_BREAK_1
              , EWK_CUT_GE_2_BASELINE_LEPTONS
              , EWK_CUT_EQ_2_BASELINE_LEPTONS
              , EWK_CUT_MLL_SFOS
              , EWK_CUT_EQ_2_SIGNAL_LEPTON
              , EWK_CUT_BREAK_2
              , EWK_CUT_PHASE_SPACE
              , EWK_CUT_TRIGGER
              , EWK_CUT_TRIGGER_MATCHING
              , EWK_CUT_BREAK_3
              , EWK_CUT_TAU_VETO
              , EWK_CUT_SS
              , EWK_CUT_PROMPT_LEP
              , EWK_CUT_NO_CHARGE_FLIP
              , EWK_CUT_BREAK_4
              , EWK_CUT_EMMA_MT
              , EWK_CUT_MET_REL
              , EWK_CUT_DPHI_LL
              , EWK_CUT_B_VETO
              , EWK_CUT_NUM_JET
              , EWK_CUT_N
              };
const std::string EWK_CUT_STRINGS[] = { "EWK_CUT_ALL"
                                      , "BREAK"
                                      , "EWK_CUT_GRL"
                                      , "EWK_CUT_INCOMPLETE_EVENT"
                                      , "EWK_CUT_LAR_ERROR"
                                      , "EWK_CUT_TILE_ERROR"
                                      , "EWK_CUT_TILE_HOT_SPOT"
                                      , "EWK_CUT_TILE_TRIP"
                                      , "EWK_CUT_BAD_JET_VETO"
                                      , "EWK_CUT_CALO_PROBLEM_JET"
                                      , "EWK_CUT_PRIMARY_VERTEX"
                                      , "EWK_CUT_BAD_MUON"
                                      , "EWK_CUT_COSMIC_MUON_VETO"
                                      , "EWK_CUT_HFOR"
                                      , "EWK_CUT_MC_OVERLAP"
                                      , "BREAK"
                                      , "EWK_CUT_GE_2_BASELINE_LEPTONS"
                                      , "EWK_CUT_EQ_2_BASELINE_LEPTONS"
                                      , "EWK_CUT_MLL_SFOS"
                                      , "EWK_CUT_EQ_2_SIGNAL_LEPTON"
                                      , "BREAK"
                                      , "EWK_CUT_PHASE_SPACE"
                                      , "EWK_CUT_TRIGGER"
                                      , "EWK_CUT_TRIGGER_MATCHING"
                                      , "BREAK"
                                      , "EWK_CUT_TAU_VETO"
                                      , "EWK_SS"
                                      , "EWK_PROMPT_LEP"
                                      , "EWK_NO_CHARGE_FLIP"
                                      , "BREAK"
                                      , "EWK_EMMA_MT"
                                      , "EWK_MET_REL"
                                      , "EWK_DPHI_LL"
                                      , "EWK_B_VETO"
                                      , "EWK_NUM_JET"
                                      };

// =============================================================================
class EwkCutFlowTracker : public CutFlowTracker
{
  // ---------------------------------------------------------------------------
  public:
    EwkCutFlowTracker();

    virtual void fillHist(int channel, int bin, float weight);

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
