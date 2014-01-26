#ifndef EWKANALYSIS_H
#define EWKANALYSIS_H

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "PennSusyFrameCore/include/PennSusyFrameCore.h"
#include "PennSusyFrameCore/include/EventSelectors.h"

// =============================================================================
namespace PennSusyFrame
{
  // ===========================================================================
  class EwkAnalysis : public PennSusyFrame::PennSusyFrameCore
  {
    public :
      EwkAnalysis(TTree *tree=0);
      virtual ~EwkAnalysis();

      virtual void processEvent();
      virtual void finalizeEvent();

    protected:
      bool m_crit_cut_grl;
      bool m_crit_cut_incomplete_event;
      bool m_crit_cut_lar_error;
      bool m_crit_cut_tile_error;
      bool m_crit_cut_tile_hot_spot;
      bool m_crit_cut_tile_trip;
      bool m_crit_cut_bad_jet_veto;
      bool m_crit_cut_calo_problem_jet;
      bool m_crit_cut_primary_vertex;
      bool m_crit_cut_bad_mu_veto;
      bool m_crit_cut_cosmic_mu_veto;
      bool m_crit_cut_hfor;
      bool m_crit_cut_mc_overlap;
      bool m_crit_cut_ge_2_lep;
      bool m_crit_cut_2_lep;
      bool m_crit_cut_tau_veto;
      bool m_crit_cut_mll_sfos;
      bool m_crit_cut_signal_lep;
      bool m_crit_cut_phase_space;
      bool m_crit_cut_trigger;
      bool m_crit_cut_trigger_match;
      bool m_crit_cut_prompt_leptons;
      bool m_crit_cut_stream_overlap;

      PennSusyFrame::GrlTool m_grl;

    private:

  };
}

#endif
