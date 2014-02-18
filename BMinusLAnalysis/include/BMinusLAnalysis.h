#ifndef BMINUSLANALYSIS_H
#define BMINUSLANALYSIS_H

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include "PennSusyFrameCore/include/PennSusyFrameCore.h"
#include "PennSusyFrameCore/include/EventSelectors.h"
#include "HistogramHandlers/include/HistogramHandlers.h"
#include "BMinusLAnalysis/include/BMinusLCutFlowTracker.h"
#include "BMinusLAnalysis/include/BMinusLHistogramHandlers.h"

// =============================================================================
namespace PennSusyFrame
{
  // ===========================================================================
  class BMinusLAnalysis : public PennSusyFrame::PennSusyFrameCore
  {
    public :
      BMinusLAnalysis(TTree *tree=0);
      virtual ~BMinusLAnalysis();

      virtual void prepareTools();

      virtual void prepareSelection();

      virtual void beginRun();
      virtual void processEvent();
      virtual void finalizeEvent();
      virtual void finalizeRun();

      void setOutHistFileName(std::string val) { m_out_hist_file_name = val; }

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

    protected:
      std::string m_out_hist_file_name;

      PennSusyFrame::LeptonKinematicsHists m_lep_hists;

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

      PennSusyFrame::GrlTool m_grl;
      PennSusyFrame::TileTripTool m_tile_trip_tool;
      PennSusyFrame::HFORTool m_hfor_tool;

      BMinusLCutFlowTracker m_raw_cutflow_tracker;
      BMinusLCutFlowTracker m_cutflow_tracker;

      PennSusyFrame::BMinusLHists m_bminusl_histogram_handler;

    private:
  };
}

#endif
