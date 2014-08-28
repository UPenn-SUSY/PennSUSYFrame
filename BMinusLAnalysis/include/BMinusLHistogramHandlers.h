#ifndef PennSusyFrame_BMinusLHistogramHandlers_h
#define PennSusyFrame_BMinusLHistogramHandlers_h

// =============================================================================
#include <vector>
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "HistogramHandlers/include/HistogramHandlers.h"
#include "PennSusyFrameCore/include/PennSusyFrameCore.h"
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
      // number of b jets
      std::vector<TH1F*> m_h_num_b_jet; //~ ~

      // dR/dPhi/dEta betwen b and lepton in a pair
      std::vector<TH1F*> m_h_bl_dr_all; //~ ~
      std::vector<TH1F*> m_h_bl_dr_0; //~ ~
      std::vector<TH1F*> m_h_bl_dr_1; //~ ~

      std::vector<TH1F*> m_h_bl_dphi_all; //~ ~
      std::vector<TH1F*> m_h_bl_dphi_0; //~ ~
      std::vector<TH1F*> m_h_bl_dphi_1; //~ ~

      std::vector<TH1F*> m_h_bl_deta_all; //~ ~
      std::vector<TH1F*> m_h_bl_deta_0; //~ ~
      std::vector<TH1F*> m_h_bl_deta_1; //~ ~

      // b jet pt
      std::vector<TH1F*> m_h_b_jet_pt_all; //~ ~
      std::vector<TH1F*> m_h_b_jet_pt_0; //~ ~
      std::vector<TH1F*> m_h_b_jet_pt_1; //~ ~

      // dR/dPhi/dEta between b jets
      std::vector<TH1F*> m_h_dr_bb; //~ ~
      std::vector<TH1F*> m_h_dphi_bb; //~ ~
      std::vector<TH1F*> m_h_deta_bb; //~ ~

      // eta of b jets
      std::vector<TH1F*> m_h_b_jet_eta_all; //~ ~
      std::vector<TH1F*> m_h_b_jet_eta_0; //~ ~
      std::vector<TH1F*> m_h_b_jet_eta_1; //~ ~

      // various mbl plots
      std::vector<TH1F*> m_h_mbl_all; //~ ~
      std::vector<TH1F*> m_h_mbl_0; //~ ~
      std::vector<TH1F*> m_h_mbl_1; //~ ~
      std::vector<TH1F*> m_h_mbl_diff; //~ ~
      std::vector<TH1F*> m_h_mbl_ratio; //~ ~
      std::vector<TH1F*> m_h_mbl_asym; //~ ~
      std::vector<TH2F*> m_h_mbl_2d; //~ ~

      std::vector<TH1F*> m_h_mbl_coarse_all; //~ ~
      std::vector<TH1F*> m_h_mbl_coarse_0; //~ ~
      std::vector<TH1F*> m_h_mbl_coarse_1; //~ ~
      std::vector<TH2F*> m_h_mbl_coarse_2d; //~ ~

      // various ptbl plots
      std::vector<TH1F*> m_h_ptbl_all; //~ ~
      std::vector<TH1F*> m_h_ptbl_0; //~ ~
      std::vector<TH1F*> m_h_ptbl_1; //~ ~
      std::vector<TH1F*> m_h_ptbl_diff; //~ ~
      std::vector<TH2F*> m_h_ptbl_2d; //~ ~

      // bbll mass and pt
      std::vector<TH1F*> m_h_mbbll; //~ ~
      std::vector<TH1F*> m_h_ptbbll; //~ ~
  };

  // =============================================================================
  // = BMinusLDetailedHists
  // =============================================================================
  class BMinusLDetailedHists : public HistogramHandler
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      BMinusLDetailedHists(std::string name_tag = "");
      virtual ~BMinusLDetailedHists();

      virtual void FillSpecial( const PennSusyFrame::Event&
                              , const PennSusyFrame::EventLevelQuantities&
                              , const std::vector<PennSusyFrame::Jet*>* b_jets
                              , const PennSusyFrame::blPair&
                              , const PennSusyFrame::blPair&
                              , const PennSusyFrame::MCTruth&
                              , PennSusyFrame::TruthMatchTool&
                              , float weight
                              );
      virtual void write(TDirectory*);
      virtual bool pass(float eta_0, float eta_1, float eta_0_l, float eta_1_l);
      void calcEff2d(TH2F*, TH2F*, TH2F*, bool raw);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    private:
      // dR between leptons and jets broken down by flavor
      std::vector<TH1F*> m_h_dr_ee; //~ ~
      std::vector<TH1F*> m_h_dr_mm; //~ ~
      std::vector<TH1F*> m_h_dr_em; //~ ~
      std::vector<TH1F*> m_h_dr_ej; //~ ~
      std::vector<TH1F*> m_h_dr_mj; //~ ~

      // dR between jet and b quark which is matched to jet
      std::vector<TH1F*> m_h_b_jet_dr_q_all; //~ ~
      std::vector<TH1F*> m_h_b_jet_dr_q_0; //~ ~
      std::vector<TH1F*> m_h_b_jet_dr_q_1; //~ ~

      // raw b jet pT
      std::vector<TH1F*> m_h_b_jet_raw_pt_all; //~ ~
      std::vector<TH1F*> m_h_b_jet_raw_pt_0; //~ ~
      std::vector<TH1F*> m_h_b_jet_raw_pt_1; //~ ~

      // pT of b jet from the stop
      std::vector<TH1F*> m_h_b_jet_from_stop_pt_all; //~ ~
      std::vector<TH1F*> m_h_b_jet_from_stop_pt_0; //~ ~
      std::vector<TH1F*> m_h_b_jet_from_stop_pt_1; //~ ~
      std::vector<TH1F*> m_h_b_jet_from_stop_raw_pt_all;

      // pT of b jets when both are coming from stops
      std::vector<TH1F*> m_h_b_jet_both_from_stop_pt_all; //~ ~
      std::vector<TH1F*> m_h_b_jet_both_from_stop_pt_0; //~ ~
      std::vector<TH1F*> m_h_b_jet_both_from_stop_pt_1; //~ ~
      std::vector<TH1F*> m_h_b_jet_both_from_stop_raw_pt_all; //~ ~
      std::vector<TH1F*> m_h_b_jet_both_from_stop_raw_pt_1; //~ ~

      // pT of leptons when coming from the stop
      std::vector<TH1F*> m_h_lep_from_stop_pt_all; //~ ~
      std::vector<TH1F*> m_h_lep_from_stop_pt_0; //~ ~
      std::vector<TH1F*> m_h_lep_from_stop_pt_1; //~ ~
      std::vector<TH1F*> m_h_lep_from_stop_raw_pt_all; //~ ~

      // pT of leptons when both are coming from the stop
      std::vector<TH1F*> m_h_lep_both_from_stop_pt_all; //~ ~
      std::vector<TH1F*> m_h_lep_both_from_stop_pt_0; //~ ~
      std::vector<TH1F*> m_h_lep_both_from_stop_pt_1; //~ ~
      std::vector<TH1F*> m_h_lep_both_from_stop_raw_pt_all; //~ ~
      std::vector<TH1F*> m_h_lep_both_from_stop_raw_pt_1; //~ ~

      // jet multiplicity vs pT for b jets
      std::vector<TH2F*> m_h_b_jet_mult_pt_all; //~ ~
      std::vector<TH2F*> m_h_b_jet_mult_pt_0; //~ ~
      std::vector<TH2F*> m_h_b_jet_mult_pt_1; //~ ~
      std::vector<TH2F*> m_h_b_jet_mult_raw_pt_all; //~ ~
      std::vector<TH2F*> m_h_b_jet_mult_raw_pt_1; //~ ~

      // mbl vs hT
      std::vector<TH2F*> m_h_mbl_vs_ht_all; //~ ~
      std::vector<TH2F*> m_h_mbl_vs_ht_0; //~ ~
      std::vector<TH2F*> m_h_mbl_vs_ht_1; //~ ~

      // 2d histograms of lepton and bjet pt for efficiency studies
      std::vector<TH2F*> m_h_b_jet1vl1_pt; //~ ~
      std::vector<TH2F*> m_h_b_jet1vl1_pt_eff; //~ ~
      std::vector<TH2F*> m_h_b_jet1vl1_pt_num; //~ ~
      std::vector<TH2F*> m_h_b_jet1vl1_raw_pt; //~ ~
      std::vector<TH2F*> m_h_b_jet1vl1_raw_pt_eff; //~ ~
      std::vector<TH2F*> m_h_b_jet1vl1_raw_pt_num; //~ ~
      std::vector<TH2F*> m_h_b_jet1vl1_all_from_stop_pt; //~ ~
      std::vector<TH2F*> m_h_b_jet1vl1_all_from_stop_pt_eff; //~ ~
      std::vector<TH2F*> m_h_b_jet1vl1_all_from_stop_pt_num; //~ ~
      std::vector<TH2F*> m_h_b_jet1vl1_all_from_stop_raw_pt; //~ ~
      std::vector<TH2F*> m_h_b_jet1vl1_all_from_stop_raw_pt_eff; //~ ~
      std::vector<TH2F*> m_h_b_jet1vl1_all_from_stop_raw_pt_num; //~ ~

      // mbl for anti-paired bl pairs
      std::vector<TH1F*> m_h_mbl_anti_pairing_all; //~ ~
      std::vector<TH1F*> m_h_mbl_anti_pairing_0; //~ ~
      std::vector<TH1F*> m_h_mbl_anti_pairing_1; //~ ~
      std::vector<TH1F*> m_h_mbl_anti_pairing_diff; //~ ~
      std::vector<TH1F*> m_h_mbl_anti_pairing_ratio; //~ ~

      // did we pair correctly?
      std::vector<TH1F*> m_h_num_leptons_from_stop; //~ ~
      std::vector<TH1F*> m_h_num_jets_from_stop; //~ ~
      std::vector<TH1F*> m_h_num_jets_paired_to_quark; //~ ~
      std::vector<TH1F*> m_h_jet_from_stop_when_paired_to_quark; //~ ~
      std::vector<TH1F*> m_h_num_same_parent_pairing; //~ ~
      std::vector<TH1F*> m_h_same_parent_pairing_pair_0; //~ ~
      std::vector<TH1F*> m_h_same_parent_pairing_pair_1; //~ ~
      std::vector<TH1F*> m_h_same_parent_pairing_lep_0; //~ ~
      std::vector<TH1F*> m_h_same_parent_pairing_lep_1; //~ ~
      std::vector<TH1F*> m_h_same_parent_pairing_jet_0; //~ ~
      std::vector<TH1F*> m_h_same_parent_pairing_jet_1; //~ ~

      std::vector<TH2F*> m_h_b_jet_E_resolution_all; //~ ~
      std::vector<TH2F*> m_h_b_jet_E_resolution_0; //~ ~
      std::vector<TH2F*> m_h_b_jet_E_resolution_1; //~ ~

      std::vector<TH2F*> m_h_electron_E_resolution_all; //~ ~
      std::vector<TH2F*> m_h_electron_E_resolution_0; //~ ~
      std::vector<TH2F*> m_h_electron_E_resolution_1; //~ ~

      std::vector<TH2F*> m_h_muon_inverse_pt_resolution_all; //~ ~
      std::vector<TH2F*> m_h_muon_inverse_pt_resolution_0; //~ ~
      std::vector<TH2F*> m_h_muon_inverse_pt_resolution_1; //~ ~

      // mbl for differnt pairing algorithms
      std::vector<TH1F*> m_h_mbl_same_parent_pairing; //~ ~
      std::vector<TH1F*> m_h_mbl_diff_parent_pairing; //~ ~

      std::vector<TH1F*> m_h_mbl_ratio_same_parent_pairing; //~ ~
      std::vector<TH1F*> m_h_mbl_ratio_diff_parent_pairing; //~ ~

      std::vector<TH1F*> m_h_bl_dr_same_parent_pairing; //~ ~
      std::vector<TH1F*> m_h_bl_dr_diff_parent_pairing; //~ ~

      std::vector<TH1F*> m_h_bl_dphi_same_parent_pairing; //~ ~
      std::vector<TH1F*> m_h_bl_dphi_diff_parent_pairing; //~ ~

      std::vector<TH1F*> m_h_bl_deta_same_parent_pairing; //~ ~
      std::vector<TH1F*> m_h_bl_deta_diff_parent_pairing; //~ ~
  };
}

#endif
