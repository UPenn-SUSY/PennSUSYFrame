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

      void setCritCutGrl(            bool val) { m_crit_cut_grl = val;              }
      void setCritCutIncompleteEvent(bool val) { m_crit_cut_incomplete_event = val; }
      void setCritCutLarError(       bool val) { m_crit_cut_lar_error = val;        }
      void setCritCutTileError(      bool val) { m_crit_cut_tile_error = val;       }
      void setCritCutTileHotSpot(    bool val) { m_crit_cut_tile_hot_spot = val;    }
      void setCritCutTileTrip(       bool val) { m_crit_cut_tile_trip = val;        }
      void setCritCutBadJetVeto(     bool val) { m_crit_cut_bad_jet_veto = val;     }
      void setCritCutCaloProblemJet( bool val) { m_crit_cut_calo_problem_jet = val; }
      void setCritCutPrimaryVertex(  bool val) { m_crit_cut_primary_vertex = val;   }
      void setCritCutBadMuonVeto(    bool val) { m_crit_cut_bad_mu_veto = val;      }
      void setCritCutCosmicMuonVeto( bool val) { m_crit_cut_cosmic_mu_veto = val;   }
      void setCritCutHFOR(           bool val) { m_crit_cut_hfor = val;             }
      void setCritCutMcOverlap(      bool val) { m_crit_cut_mc_overlap = val;       }
      void setCritCutGe2Lepton(      bool val) { m_crit_cut_ge_2_lep = val;         }
      void setCritCut2Lepton(        bool val) { m_crit_cut_2_lep = val;            }
      void setCritCutTauVeto(        bool val) { m_crit_cut_tau_veto = val;         }
      void setCritCutMllSfos(        bool val) { m_crit_cut_mll_sfos = val;         }
      void setCritCut2SignalLepton(  bool val) { m_crit_cut_signal_lep = val;       }
      void setCritCutPhaseSpace(     bool val) { m_crit_cut_phase_space = val;      }
      void setCritCutTrigger(        bool val) { m_crit_cut_trigger = val;          }
      void setCritCutTriggerMatch(   bool val) { m_crit_cut_trigger_match = val;    }
      void setCritCutPromptLeptons(  bool val) { m_crit_cut_prompt_leptons = val;   }
      void setCritCutStreamOverlap(  bool val) { m_crit_cut_stream_overlap = val;   }

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
      PennSusyFrame::TileTripTool m_tile_trip_tool;
      PennSusyFrame::HFORTool m_hfor_tool;

    private:

  };
}

#endif
