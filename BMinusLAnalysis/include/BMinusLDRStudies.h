#ifndef BMINUSLDRSTUDY_H
#define BMINUSLDRSTUDY_H

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <fstream>

#include "PennSusyFrameCore/include/PennSusyFrameCore.h"
#include "PennSusyFrameCore/include/EventSelectors.h"
#include "HistogramHandlers/include/HistogramHandlers.h"
#include "BMinusLAnalysis/include/BMinusLCutFlowTracker.h"
#include "BMinusLAnalysis/include/BMinusLHistogramHandlers.h"
#include "BMinusLAnalysis/include/BMinusLAnalysis.h"

// =============================================================================
namespace PennSusyFrame
{
  enum BMINUSL_DR_HIST_LEVELS { BMINUSL_NO_OR
                              , BMINUSL_EE_OR
                              , BMINUSL_EJ_OR
                              , BMINUSL_MJ_OR
                              , BMINUSL_JE_OR
                              , BMINUSL_JM_OR
                              , BMINUSL_EM_OR
                              , BMINUSL_MM_OR
                              , BMINUSL_DR_HIST_N
                              };

  const std::string BMINUSL_DR_HIST_LEVEL_STRINGS[] = { "BMINUSL_NO_OR"
                                                      , "BMINUSL_EE_OR"
                                                      , "BMINUSL_EJ_OR"
                                                      , "BMINUSL_MJ_OR"
                                                      , "BMINUSL_JE_OR"
                                                      , "BMINUSL_JM_OR"
                                                      , "BMINUSL_EM_OR"
                                                      , "BMINUSL_MM_OR"
                                                      , "BMINUSL_DR_HIST_N"
                                                      };

  // ---------------------------------------------------------------------------
  class blPair;
  
  // ===========================================================================
  class BMinusLDRStudies : public PennSusyFrame::BMinusLAnalysis
    {
    public:
      BMinusLDRStudies(TTree *tree=0);
      virtual ~BMinusLDRStudies();

      virtual void beginRun();
      virtual void finalizeEvent();
      virtual void finalizeRun();

      void reproduceFullObjectCleaning( const PennSusyFrame::Event&
                                      , const PennSusyFrame::MCTruth&
                                      , PennSusyFrame::ObjectCleaning
                                      , const std::vector<PennSusyFrame::Electron*>*
                                      , const std::vector<PennSusyFrame::Muon*>*
                                      , const std::vector<PennSusyFrame::Jet*>*
                                      , const std::vector<PennSusyFrame::Jet*>*
                                      );

    protected:
      void filldRHistHandles( BMINUSL_DR_HIST_LEVELS
                            , const PennSusyFrame::Event&
                            , const PennSusyFrame::MCTruth&
                            , const std::vector<PennSusyFrame::Electron*>&
                            , const std::vector<PennSusyFrame::Muon*>&
                            , const std::vector<PennSusyFrame::Jet*>&
                            );
      std::vector<PennSusyFrame::DRHists*> m_bminusl_dr_histogram_handler;
  };
}

#endif
