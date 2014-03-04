#ifndef EWKANALYSIS_H
#define EWKANALYSIS_H

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "PennSusyFrameCore/include/PennSusyFrameCore.h"
#include "PennSusyFrameCore/include/EventSelectors.h"
#include "HistogramHandlers/include/HistogramHandlers.h"
#include "EwkAnalysis/include/EwkHistogramHandlers.h"
#include "EwkAnalysis/include/EwkCutFlowTracker.h"
#include "EwkAnalysis/include/EwkChargeFlipTool.h"

// =============================================================================
namespace PennSusyFrame
{

  enum EWK_HIST_LEVELS { EWK_HIST_ZVETO
			 , EWK_HIST_MET
			 , EWK_HIST_N
  };

  const std::string EWK_HIST_LEVEL_STRINGS[] = {"EWK_ZVETO"
						, "EWK_MET"
  };


  // ===========================================================================
  class EwkAnalysis : public PennSusyFrame::PennSusyFrameCore
  {
    public :
      EwkAnalysis(TTree *tree=0);
      virtual ~EwkAnalysis();

      virtual void prepareTools();
      virtual void prepareSelection();

      virtual void beginRun();
      virtual void processEvent();
      virtual void finalizeEvent();
      virtual void finalizeRun();

      void setOutTntFileName(std::string val) { m_out_tnt_file_name = val; }

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

      void setSFOSMllCut(double min, double max) { m_sfos_mll_min = min; m_sfos_mll_max = max; }
      void setEmmaMtCut(double min, double max)  { m_emma_mt_min = min; m_emma_mt_max = max; }
      void setMetRelCut(double min, double max)  { m_met_rel_min = min; m_met_rel_max = max; }
      void setDphillCut(double min, double max)  { m_dphi_ll_min = min; m_dphi_ll_max = max; }
      void setNumLightJetsCut(double min, double max) { m_num_light_jets_min = min; m_num_light_jets_max = max; }

      void setOutHistFileName(std::string val) { m_out_hist_file_name = val; }

    protected:
      std::string m_out_tnt_file_name;
      std::string m_out_hist_file_name;


      void fillHistHandles(EWK_HIST_LEVELS
			   , float weight
			   );

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
      bool m_crit_cut_mll_sfos;
      bool m_crit_cut_signal_lep;
      bool m_crit_cut_phase_space;
      bool m_crit_cut_trigger;
      bool m_crit_cut_trigger_match;
      bool m_crit_cut_tau_veto;
      bool m_crit_cut_ss;
      bool m_crit_cut_prompt_leptons;
      bool m_crit_cut_stream_overlap;
      bool m_crit_cut_no_charge_flip;
      bool m_crit_cut_emma_mt;
      bool m_crit_cut_met_rel;
      bool m_crit_cut_dphi_ll;
      bool m_crit_cut_b_veto;
      bool m_crit_cut_num_jet;

      PennSusyFrame::GrlTool m_grl;
      PennSusyFrame::TileTripTool m_tile_trip_tool;
      PennSusyFrame::HFORTool m_hfor_tool;

      PennSusyFrame::ChargeFlipTool m_charge_flip_tool;

      EwkCutFlowTracker m_raw_cutflow_tracker;
      EwkCutFlowTracker m_cutflow_tracker;

      double m_sfos_mll_min;
      double m_sfos_mll_max;

      double m_emma_mt_min;
      double m_emma_mt_max;

      double m_met_rel_min;
      double m_met_rel_max;

      double m_dphi_ll_min;
      double m_dphi_ll_max;

      int m_num_light_jets_min;
      int m_num_light_jets_max;

      std::vector<PennSusyFrame::EwkHists*> m_ewk_histogram_handler;

    private:

  };
}

#endif
