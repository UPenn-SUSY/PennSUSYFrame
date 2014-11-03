#ifndef BMINUSANALYSISLOOSEJETS_H
#define BMINUSANALYSISLOOSEJETS_H

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
  enum BMINUSL_LOOSE_HIST_LEVELS { BMINUSL_LLJJ_HIST_BL_PAIRING
                                 , BMINUSL_LLJJ_HIST_Z_VETO

                                 , BMINUSL_LLJJ_HIST_SR
                                 , BMINUSL_LLJJ_HIST_CR_TOP
                                 , BMINUSL_LLJJ_HIST_CR_Z
                                 , BMINUSL_LLJJ_HIST_VR_1
                                 , BMINUSL_LLJJ_HIST_VR_2
                                 , BMINUSL_LLJJ_HIST_VR_3
                                 , BMINUSL_LLJJ_HIST_VR_4
                                 , BMINUSL_LLJJ_HIST_VR_5
                                 , BMINUSL_LLJJ_HIST_VR_6
                                 , BMINUSL_LLJJ_HIST_VR_7

                                 , BMINUSL_LLBJ_HIST_BL_PAIRING
                                 , BMINUSL_LLBJ_HIST_Z_VETO
                                 , BMINUSL_LLBJ_HIST_SR
                                 , BMINUSL_LLBJ_HIST_CR_TOP
                                 , BMINUSL_LLBJ_HIST_CR_Z
                                 , BMINUSL_LLBJ_HIST_VR_1
                                 , BMINUSL_LLBJ_HIST_VR_2
                                 , BMINUSL_LLBJ_HIST_VR_3
                                 , BMINUSL_LLBJ_HIST_VR_4
                                 , BMINUSL_LLBJ_HIST_VR_5
                                 , BMINUSL_LLBJ_HIST_VR_6
                                 , BMINUSL_LLBJ_HIST_VR_7

                                 , BMINUSL_LOOSE_HIST_N
                                 };

  const std::string BMINUSL_LOOSE_HIST_LEVEL_STRINGS[] = { "BMINUSL_LLJJ_BL_PAIRING"
                                                         , "BMINUSL_LLJJ_ZVETO"
                                                         , "BMINUSL_LLJJ_HIST_SR"
                                                         , "BMINUSL_LLJJ_HIST_CR_TOP"
                                                         , "BMINUSL_LLJJ_HIST_CR_Z"
                                                         , "BMINUSL_LLJJ_HIST_VR_1"
                                                         , "BMINUSL_LLJJ_HIST_VR_2"
                                                         , "BMINUSL_LLJJ_HIST_VR_3"
                                                         , "BMINUSL_LLJJ_HIST_VR_4"
                                                         , "BMINUSL_LLJJ_HIST_VR_5"
                                                         , "BMINUSL_LLJJ_HIST_VR_6"
                                                         , "BMINUSL_LLJJ_HIST_VR_7"

                                                         , "BMINUSL_LLBJ_BL_PAIRING"
                                                         , "BMINUSL_LLBJ_ZVETO"
                                                         , "BMINUSL_LLBJ_HIST_SR"
                                                         , "BMINUSL_LLBJ_HIST_CR_TOP"
                                                         , "BMINUSL_LLBJ_HIST_CR_Z"
                                                         , "BMINUSL_LLBJ_HIST_VR_1"
                                                         , "BMINUSL_LLBJ_HIST_VR_2"
                                                         , "BMINUSL_LLBJ_HIST_VR_3"
                                                         , "BMINUSL_LLBJ_HIST_VR_4"
                                                         , "BMINUSL_LLBJ_HIST_VR_5"
                                                         , "BMINUSL_LLBJ_HIST_VR_6"
                                                         , "BMINUSL_LLBJ_HIST_VR_7"

                                                         , "BMINUSL_LOOSE_N"
                                                         };


  // ---------------------------------------------------------------------------
  class blPair;

  // ===========================================================================
  class BMinusLAnalysisLooseJets : public PennSusyFrame::BMinusLAnalysis
  {
    public :
      BMinusLAnalysisLooseJets(TTree *tree=0);
      virtual ~BMinusLAnalysisLooseJets();

      virtual void beginRun();
      virtual void initializeEvent();
      virtual void processEvent();
      virtual void finalizeEvent();
      virtual void finalizeRun();

    protected:
      // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      void fillHistHandles( BMINUSL_LOOSE_HIST_LEVELS
                          , const std::vector<PennSusyFrame::Electron*>*
                          , const std::vector<PennSusyFrame::Muon*>*
                          , const std::vector<PennSusyFrame::Jet*>*
                          , const PennSusyFrame::blPair*
                          , const PennSusyFrame::blPair*
                          , float weight
                          );

      // jet collection for llbj selection
      std::vector<PennSusyFrame::Jet*> m_llbj_jet_collection;

      // jl pair for the lljj selection
      PennSusyFrame::blPair* m_lljj_jl_0;
      PennSusyFrame::blPair* m_lljj_jl_1;

      // jl pair for the bljj selection
      PennSusyFrame::blPair* m_llbj_jl_0;
      PennSusyFrame::blPair* m_llbj_jl_1;

      bool m_pass_lljj_pairing;
      bool m_pass_llbj_pairing;

      float m_lljj_ht_signal;
      float m_llbj_ht_signal;

    private:
  };
}

#endif
