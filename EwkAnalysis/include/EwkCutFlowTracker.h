#ifndef EwkCutFlowTracker_h
#define EwkCutFlowTracker_h

// =============================================================================
#include "CutFlowTracker/include/CutFlowTracker.h"
#include <vector>
#include "TH1D.h"

// =============================================================================
enum EWK_CUTS { EWK_CUT_ALL
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
              , EWK_CUT_GE_2_BASELINE_LEPTONS
              , EWK_CUT_EQ_2_BASELINE_LEPTONS
              , EWK_CUT_TAU_VETO
              , EWK_CUT_MLL_SFOS
              , EWK_CUT_EQ_2_SIGNAL_LEPTON
              , EWK_CUT_PHASE_SPACE
              , EWK_CUT_TRIGGER
              , EWK_CUT_TRIGGER_MATCHING
              , EWK_CUT_N
              };
const std::string EWK_CUT_STRINGS[] = { "EWK_CUT_GRL"
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
                                      , "EWK_CUT_GE_2_BASELINE_LEPTONS"
                                      , "EWK_CUT_EQ_2_BASELINE_LEPTONS"
                                      , "EWK_CUT_TAU_VETO"
                                      , "EWK_CUT_MLL_SFOS"
                                      , "EWK_CUT_EQ_2_SIGNAL_LEPTON"
                                      , "EWK_CUT_PHASE_SPACE"
                                      , "EWK_CUT_TRIGGER"
                                      , "EWK_CUT_TRIGGER_MATCHING"
                                      };

// =============================================================================
class EwkCutFlowTracker : public CutFlowTracker
{
  // ---------------------------------------------------------------------------
  public:
    EwkCutFlowTracker();

    virtual void fillHist(int channel, int bin, float weight);

    // virtual void printToScreen();
    // virtual void printToFile(std::string out_file_name);

  // ---------------------------------------------------------------------------
  protected:
    virtual void initBinList();
    virtual void initCutFlowHists();

  // -----------------------------------------------------------------------------
  private:
};

#endif
