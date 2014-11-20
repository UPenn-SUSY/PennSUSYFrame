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

      virtual void beginRun();
      virtual void initializeEvent();
      virtual void finalizeEvent();
      virtual void finalizeRun();

      void clearVariables();

      void setOutNtupleFileName(std::string val) { m_out_ntuple_file_name = val; }

    protected:
      void configureOutput( std::string out_file_name
                          , std::string out_tree_name
                          );
      void fillNtuple( const PennSusyFrame::blPair*
                     , const PennSusyFrame::blPair*
                     , float weight
                     );
      std::string m_out_ntuple_file_name;

      // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      TFile* m_output_file;
      TTree* m_output_tree;

      // variables to store to optimize ntuple
      float m_weight;

      float m_btag_sf_up_frac;
      float m_btag_sf_down_frac;

      int m_flavor_channel;

      bool m_is_ee;
      bool m_is_mm;
      bool m_is_em;

      bool m_is_sr;
      bool m_is_cr_top;
      bool m_is_cr_z;
      bool m_is_vr_1;
      bool m_is_vr_2;
      bool m_is_vr_3;
      bool m_is_vr_4;
      bool m_is_vr_5;
      bool m_is_vr_6;
      bool m_is_vr_7;

      float m_mbl_0;
      float m_mbl_1;
      float m_mbl_asym;
      float m_mbbll;

      float m_ptbl_0;
      float m_ptbl_1;
      float m_ptbl_asym;
      float m_ptbbll;

      float m_mll;
      float m_ptll;

      float m_met_et;
      float m_met_rel;
      float m_met_sig_signal;

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
