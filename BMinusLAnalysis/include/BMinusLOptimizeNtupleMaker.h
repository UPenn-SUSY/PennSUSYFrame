#ifndef BMINUSLOPTIMIZENTUPLEMAKER_H
#define BMINUSLOPTIMIZENTUPLEMAKER_H

#include <TROOT.h>
#include <TChain.h>

#include "PennSusyFrameCore/include/PennSusyFrameCore.h"
#include "PennSusyFrameCore/include/EventSelectors.h"
// #include "HistogramHandlers/include/HistogramHandlers.h"
// #include "BMinusLAnalysis/include/BMinusLCutFlowTracker.h"
// #include "BMinusLAnalysis/include/BMinusLHistogramHandlers.h"

// =============================================================================
class TFile;
class TTree;

// =============================================================================
namespace PennSusyFrame
{
  // enum BMINUSL_HIST_LEVELS { BMINUSL_HIST_BASIC_CLEANING
  //                          , BMINUSL_HIST_BL_PAIRING
  //                          , BMINUSL_HIST_ZVETO
  //                          , BMINUSL_HIST_MET
  //                          , BMINUSL_HIST_N
  //                          };

  // const std::string BMINUSL_HIST_LEVEL_STRINGS[] = { "BMINUSL_BASIC_CLEANING"
  //                                                  , "BMINUSL_BL_PAIRING"
  //                                                  , "BMINUSL_ZVETO"
  //                                                  , "BMINUSL_MET"
  //                                                  };

  // ---------------------------------------------------------------------------
  class blPair;

  // ===========================================================================
  class BMinusLOptimizeNtupleMaker : public PennSusyFrame::PennSusyFrameCore
  {
    public :
      BMinusLOptimizeNtupleMaker(TTree *tree=0);
      virtual ~BMinusLOptimizeNtupleMaker();

      virtual void prepareTools();

      virtual void prepareSelection();

      virtual void beginRun();
      virtual void processEvent();
      virtual void finalizeEvent();
      virtual void finalizeRun();

      void clearVariables();

      PHASE_SPACE getPhaseSpace();

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
      void setCritCut2SignalLepton(  bool val) { m_crit_cut_signal_lep = val;       }
      void setCritCut2BJets(         bool val) { m_crit_cut_b_jets = val;           }
      void setCritCutBLPairing(      bool val) { m_crit_cut_bl_pairing = val;       }
      void setCritCutZVeto(          bool val) { m_crit_cut_z_veto = val;           }

      void setElPtCut(  float min, float max) { m_min_el_pt_baseline    = min ; m_max_el_pt_baseline    = max; }
      void setMuPtCut(  float min, float max) { m_min_mu_pt_baseline    = min ; m_max_mu_pt_baseline    = max; }
      void setBJetPtCut(float min, float max) { m_min_b_jet_pt_baseline = min ; m_max_b_jet_pt_baseline = max; }

    protected:
      void configureOutput( std::string out_file_name
                          , std::string out_tree_name
                          );
      void fillNtuple( const PennSusyFrame::blPair*
                     , const PennSusyFrame::blPair*
                     , float weight
                     );
      std::string m_out_ntuple_file_name;

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
      bool m_crit_cut_signal_lep;
      bool m_crit_cut_b_jets;
      bool m_crit_cut_bl_pairing;
      bool m_crit_cut_z_veto;

      PennSusyFrame::GrlTool m_grl;
      PennSusyFrame::TileTripTool m_tile_trip_tool;
      PennSusyFrame::HFORTool m_hfor_tool;

      // BMinusLCutFlowTracker m_raw_cutflow_tracker;
      // BMinusLCutFlowTracker m_cutflow_tracker;

      double m_min_el_pt_baseline;
      double m_max_el_pt_baseline;

      double m_min_mu_pt_baseline;
      double m_max_mu_pt_baseline;

      double m_min_b_jet_pt_baseline;
      double m_max_b_jet_pt_baseline;

      // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      TFile* m_output_file;
      TTree* m_output_tree;

      // variables to store to optimize ntuple
      float m_weight;

      float m_mbl_0;
      float m_mbl_1;
      float m_mbbll;

      float m_ptbl_0;
      float m_ptbl_1;
      float m_ptbbll;

      float m_mll;
      float m_ptll;

      float m_met_et;
      float m_met_rel;

      float m_ht_all;
      float m_ht_baseline;
      float m_ht_good;
      float m_ht_signal;

      float m_pt_l_0;
      float m_pt_l_1;
      float m_pt_b_0;
      float m_pt_b_1;

      float m_dphi_bl_0;
      float m_dphi_bl_1;
      float m_deta_bl_0;
      float m_deta_bl_1;
      float m_dr_bl_0;
      float m_dr_bl_1;

      float m_dphi_ll;
      float m_deta_ll;
      float m_dr_ll;

      float m_dphi_bb;
      float m_deta_bb;
      float m_dr_bb;

    private:
  };
}

#endif
