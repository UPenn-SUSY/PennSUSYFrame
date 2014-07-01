#ifndef PennSusyFrame_BMinusLHistogramHandlers_h
#define PennSusyFrame_BMinusLHistogramHandlers_h

// =============================================================================
#include <vector>
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "HistogramHandlers/include/HistogramHandlers.h"

// =============================================================================
class TFile;
class TDirectory;
class TH1F;
class TH2F;

namespace PennSusyFrame
{
  class Event;
  class Electron;
  class Muon;
  class Jet;
  class Met;
  class MCTruth;

  class blPair;
}

// =============================================================================
namespace PennSusyFrame
{
  // =============================================================================
  // = BMinusLHists
  // =============================================================================
  class BMinusLHists : public HistogramHandler
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      BMinusLHists(std::string name_tag = "");
      virtual ~BMinusLHists();

      virtual void FillSpecial( const PennSusyFrame::Event&
                              , const PennSusyFrame::EventLevelQuantities&
                              , const std::vector<PennSusyFrame::Jet*>* b_jets
                              , const PennSusyFrame::blPair&
                              , const PennSusyFrame::blPair&
                              , const PennSusyFrame::MCTruth&
                              , float weight
                              );
      virtual void write(TDirectory*);
      virtual bool pass(float eta_0, float eta_1, float eta_0_l, float eta_1_l);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    private:
      std::vector<TH1F*> m_h_num_b_jet;

      std::vector<TH1F*> m_h_bl_dr_all;
      std::vector<TH1F*> m_h_bl_dr_0;
      std::vector<TH1F*> m_h_bl_dr_1;

      std::vector<TH1F*> m_h_bl_dphi_all;
      std::vector<TH1F*> m_h_bl_dphi_0;
      std::vector<TH1F*> m_h_bl_dphi_1;

      std::vector<TH1F*> m_h_bl_deta_all;
      std::vector<TH1F*> m_h_bl_deta_0;
      std::vector<TH1F*> m_h_bl_deta_1;

      std::vector<TH1F*> m_h_b_jet_pt_all;
      std::vector<TH1F*> m_h_b_jet_pt_0;
      std::vector<TH1F*> m_h_b_jet_pt_1;

      std::vector<TH1F*> m_h_b_jet_dr_q_all;
      std::vector<TH1F*> m_h_b_jet_dr_q_0;
      std::vector<TH1F*> m_h_b_jet_dr_q_1;

      std::vector<TH1F*> m_h_dr_bb;
      std::vector<TH1F*> m_h_dphi_bb;
      std::vector<TH1F*> m_h_deta_bb;

      std::vector<TH1F*> m_h_b_jet_eta_all;
      std::vector<TH1F*> m_h_b_jet_eta_0;
      std::vector<TH1F*> m_h_b_jet_eta_1;

      std::vector<TH1F*> m_h_mbl_all;
      std::vector<TH1F*> m_h_mbl_0;
      std::vector<TH1F*> m_h_mbl_1;
      std::vector<TH1F*> m_h_mbl_diff;
      std::vector<TH1F*> m_h_mbl_ratio;
      std::vector<TH1F*> m_h_mbl_asym;
      std::vector<TH2F*> m_h_mbl_2d;

      std::vector<TH2F*> m_h_mbl_vs_ht_all;
      std::vector<TH2F*> m_h_mbl_vs_ht_0;
      std::vector<TH2F*> m_h_mbl_vs_ht_1;

      std::vector<TH1F*> m_h_ptbl_all;
      std::vector<TH1F*> m_h_ptbl_0;
      std::vector<TH1F*> m_h_ptbl_1;
      std::vector<TH1F*> m_h_ptbl_diff;
      std::vector<TH2F*> m_h_ptbl_2d;

      std::vector<TH2F*> m_h_pt_b_jet1vl1;
      std::vector<TH2F*> m_h_fiducial_b_jet1vl1_pass;
      std::vector<TH2F*> m_h_fiducial_b_jet1vl1_fail;
      std::vector<TH1F*> m_h_mbl_anti_pairing_all;
      std::vector<TH1F*> m_h_mbl_anti_pairing_0;
      std::vector<TH1F*> m_h_mbl_anti_pairing_1;
      std::vector<TH1F*> m_h_mbl_anti_pairing_diff;
      std::vector<TH1F*> m_h_mbl_anti_pairing_ratio;

      std::vector<TH1F*> m_h_mbbll;
      std::vector<TH1F*> m_h_ptbbll;

      // do the b and l from the pair come from the same parent?
      std::vector<TH1F*> m_h_num_leptons_from_stop;
      std::vector<TH1F*> m_h_num_jets_from_stop;
      std::vector<TH1F*> m_h_num_jets_paired_to_quark;
      std::vector<TH1F*> m_h_jet_from_stop_when_paired_to_quark;

      std::vector<TH1F*> m_h_num_same_parent_pairing;
      std::vector<TH1F*> m_h_same_parent_pairing_pair_0;
      std::vector<TH1F*> m_h_same_parent_pairing_pair_1;
      std::vector<TH1F*> m_h_same_parent_pairing_lep_0;
      std::vector<TH1F*> m_h_same_parent_pairing_lep_1;
      std::vector<TH1F*> m_h_same_parent_pairing_jet_0;
      std::vector<TH1F*> m_h_same_parent_pairing_jet_1;
      // std::vector<TH1F*> m_h_same_parent_pairing_stop;
      // std::vector<TH1F*> m_h_same_parent_pairing_astp;

      std::vector<TH1F*> m_h_mbl_same_parent_pairing;
      std::vector<TH1F*> m_h_mbl_diff_parent_pairing;

      std::vector<TH1F*> m_h_mbl_ratio_same_parent_pairing;
      std::vector<TH1F*> m_h_mbl_ratio_diff_parent_pairing;

      std::vector<TH1F*> m_h_bl_dr_same_parent_pairing;
      std::vector<TH1F*> m_h_bl_dr_diff_parent_pairing;

      std::vector<TH1F*> m_h_bl_dphi_same_parent_pairing;
      std::vector<TH1F*> m_h_bl_dphi_diff_parent_pairing;

      std::vector<TH1F*> m_h_bl_deta_same_parent_pairing;
      std::vector<TH1F*> m_h_bl_deta_diff_parent_pairing;

      std::vector<TH1F*> m_h_eta_event_passfail;
  };
}

#endif
