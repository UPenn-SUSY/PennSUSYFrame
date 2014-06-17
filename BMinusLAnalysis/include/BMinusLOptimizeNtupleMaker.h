#ifndef BMINUSLOPTIMIZENTUPLEMAKER_H
#define BMINUSLOPTIMIZENTUPLEMAKER_H

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
  // ---------------------------------------------------------------------------
  class blPair;

  // ===========================================================================
  class BMinusLOptimizeNtupleMaker : public PennSusyFrame::BMinusLAnalysis
  {
    public :
      BMinusLOptimizeNtupleMaker(TTree *tree=0);
      virtual ~BMinusLOptimizeNtupleMaker();

      // virtual void prepareTools();

      // virtual void prepareSelection();

      virtual void beginRun();
      virtual void initializeEvent();
      // virtual void processEvent();
      virtual void finalizeEvent();
      virtual void finalizeRun();

      void clearVariables();

      void setOutNtupleFileName(std::string val) { m_out_ntuple_file_name = val; }

      // void setElPtCut(  float min, float max) { m_min_el_pt_baseline    = min ; m_max_el_pt_baseline    = max; }
      // void setMuPtCut(  float min, float max) { m_min_mu_pt_baseline    = min ; m_max_mu_pt_baseline    = max; }
      // void setBJetPtCut(float min, float max) { m_min_b_jet_pt_baseline = min ; m_max_b_jet_pt_baseline = max; }

    protected:
      void configureOutput( std::string out_file_name
                          , std::string out_tree_name
                          );
      void fillNtuple( const PennSusyFrame::blPair*
                     , const PennSusyFrame::blPair*
                     , float weight
                     );
      std::string m_out_ntuple_file_name;

      // bool m_crit_cut_grl;
      // bool m_crit_cut_incomplete_event;
      // bool m_crit_cut_lar_error;
      // bool m_crit_cut_tile_error;
      // bool m_crit_cut_tile_hot_spot;
      // bool m_crit_cut_tile_trip;
      // bool m_crit_cut_bad_jet_veto;
      // bool m_crit_cut_calo_problem_jet;
      // bool m_crit_cut_primary_vertex;
      // bool m_crit_cut_bad_mu_veto;
      // bool m_crit_cut_cosmic_mu_veto;
      // bool m_crit_cut_hfor;
      // bool m_crit_cut_mc_overlap;
      // bool m_crit_cut_ge_2_lep;
      // bool m_crit_cut_2_lep;
      // bool m_crit_cut_signal_lep;
      // bool m_crit_cut_b_jets;
      // bool m_crit_cut_bl_pairing;
      // bool m_crit_cut_z_veto;

      // PennSusyFrame::GrlTool m_grl;
      // PennSusyFrame::TileTripTool m_tile_trip_tool;
      // PennSusyFrame::HFORTool m_hfor_tool;

      // BMinusLCutFlowTracker m_raw_cutflow_tracker;
      // BMinusLCutFlowTracker m_cutflow_tracker;

      // double m_min_el_pt_baseline;
      // double m_max_el_pt_baseline;

      // double m_min_mu_pt_baseline;
      // double m_max_mu_pt_baseline;

      // double m_min_b_jet_pt_baseline;
      // double m_max_b_jet_pt_baseline;

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
