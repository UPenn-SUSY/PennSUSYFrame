#ifndef EWKNTUPLEMAKER_H
#define EWKNTUPLEMAKER_H

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




  // ===========================================================================
  class EwkNtupleMaker : public PennSusyFrame::PennSusyFrameCore
  {
    public :
      EwkNtupleMaker(TTree *tree=0);
      virtual ~EwkNtupleMaker();

      virtual void prepareTools();
      virtual void prepareSelection();

      virtual void beginRun();
      virtual void processEvent();
      virtual void finalizeEvent();
      virtual void finalizeRun();
      void clearVariables();

      void setOutNtupleFileName(std::string val) { m_out_ntuple_file_name = val; }

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

      void setDoBaselineSkim(bool val){m_do_baseline_skim = val;}

      void setSFOSMllCut(double min, double max) { m_sfos_mll_min = min; m_sfos_mll_max = max; }
      void setEmmaMtCut(double min, double max)  { m_emma_mt_min = min; m_emma_mt_max = max; }
      void setMetRelCut(double min, double max)  { m_met_rel_min = min; m_met_rel_max = max; }
      void setDphillCut(double min, double max)  { m_dphi_ll_min = min; m_dphi_ll_max = max; }

      std::vector<float> getSelectionPt (std::vector<PennSusyFrame::Particle*>* obj);
      std::vector<float> getSelectionPhi(std::vector<PennSusyFrame::Particle*>* obj);
      std::vector<float> getSelectionEta(std::vector<PennSusyFrame::Particle*>* obj);
      std::vector<bool> getSelectionSignal(std::vector<PennSusyFrame::Particle*>* obj);
      void getSortLepPts(float i1, float i2, std::vector<float> pt,  std::vector<float> eta,  std::vector<float> phi, std::vector<bool> signal);


      void setOutNtupFileName(std::string val) { m_out_ntuple_file_name = val; }

    protected:
      void configureOutput( std::string out_file_name
                          , std::string out_tree_name
                          );
      void fillNtuple( float weight);
      std::string m_out_ntuple_file_name;

      bool m_do_baseline_skim;

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

      int m_num_light_jets;
      int m_num_forward_jets;
      int m_num_jets;
      int m_num_el;
      int m_num_mu;

      TFile* m_output_file;
      TTree* m_output_tree;

      int m_event_number;
      int m_run_number;
      bool m_isSS;
      bool m_isEE;
      bool m_isEM;
      bool m_isMM;
      float m_weight;
      float m_cfweight;
      float m_mll;
      float m_ptll;
      float m_mt;
      float m_mt2;
      float m_dphill;

      std::vector<float> m_el_pt;
      std::vector<float> m_el_eta;
      std::vector<float> m_el_phi;
      std::vector<bool> m_el_signal;

      std::vector<float> m_mu_pt;
      std::vector<float> m_mu_eta;
      std::vector<float> m_mu_phi;
      std::vector<bool> m_mu_signal;

      std::vector<float> m_lep_pt;
      std::vector<float> m_lep_eta;
      std::vector<float> m_lep_phi;
      std::vector<bool> m_lep_signal;

      std::vector<float> m_jet_pt;
      std::vector<float> m_jet_eta;
      std::vector<float> m_jet_phi;

      std::vector<float> m_ljet_pt;
      std::vector<float> m_ljet_eta;
      std::vector<float> m_ljet_phi;

      float m_met_et;
      float m_met_rel;
      float m_met_phi;

      float m_ht_signal;
  };
}

#endif
