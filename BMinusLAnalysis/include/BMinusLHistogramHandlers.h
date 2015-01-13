#ifndef PennSusyFrame_BMinusLHistogramHandlers_h
#define PennSusyFrame_BMinusLHistogramHandlers_h

// =============================================================================
#include <vector>
#include <string>
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
                              , PennSusyFrame::Trigger m_trigger
                              , float weight
                              );
      virtual void write(TDirectory*);
      virtual bool pass(float eta_0, float eta_1, float eta_0_l, float eta_1_l);
      void calcEff2d(TH2F*, TH2F*, TH2F*, bool raw);
      virtual void passTriggerMatching(const PennSusyFrame::Event& event
				       , const PennSusyFrame::Trigger trigger
				       , const PennSusyFrame::blPair& bl_0
				       , const PennSusyFrame::blPair& bl_1
				       , bool trigger_matching[12]
				       );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    private:
      // dR between jet and b quark which is matched to jet
      std::vector<TH2F*> m_h_lep_pt_v_flavor_channel;
      std::vector<TH2F*> m_h_el_pt_v_flavor_channel;
      std::vector<TH2F*> m_h_mu_pt_v_flavor_channel;

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

      // lepton pt isolation
      std::vector<TH1F*> m_h_ptiso_all_lep_from_stop;
      std::vector<TH1F*> m_h_ptiso_all_lep_not_from_stop;

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
      std::vector<TH1F*> m_h_mbl_asym_after_ht_cut; //~ ~

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

      // trigger studies
      std::vector<TH1F*> m_h_single_triggers_passed;
      std::vector<TH1F*> m_h_doubleAND_triggers_passed;
      std::vector<TH1F*> m_h_doubleOR_triggers_passed;
      std::vector<TH2F*> m_h_lep_pt_v_single_triggers_passed;
      std::vector<TH2F*> m_h_lep_pt_v_doubleAND_triggers_passed;
      std::vector<TH2F*> m_h_lep_pt_v_doubleOR_triggers_passed;
      std::vector<TH2F*> m_h_el_pt_v_single_triggers_passed;
      std::vector<TH2F*> m_h_el_pt_v_doubleAND_triggers_passed;
      std::vector<TH2F*> m_h_el_pt_v_doubleOR_triggers_passed;
      std::vector<TH2F*> m_h_mu_pt_v_single_triggers_passed;
      std::vector<TH2F*> m_h_mu_pt_v_doubleAND_triggers_passed;
      std::vector<TH2F*> m_h_mu_pt_v_doubleOR_triggers_passed;
      std::vector<TH1F*> m_h_single_trigger_matching_passed;
  };

  // =============================================================================
  // = Weight Hists
  // =============================================================================
  class WeightHists : public HistogramHandler
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      WeightHists(std::string name_tag = "");
      virtual ~WeightHists();

      virtual void FillSpecial( const PennSusyFrame::Event& event
                              , const PennSusyFrame::EventLevelQuantities& event_quantities
                              , float cross_section_weight
                              , float ttbar_pt_weight
                              );
      virtual void write(TDirectory*);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    private:
      std::vector<TH1F*> m_h_cross_section_weight;
      std::vector<TH1F*> m_h_mc_event_weight;
      std::vector<TH1F*> m_h_pile_up_weight;
      std::vector<TH1F*> m_h_lep_sf;
      std::vector<TH1F*> m_h_btag_sf;
      std::vector<TH1F*> m_h_ttbar_pt_weight;
      std::vector<TH1F*> m_h_total_weight;
      std::vector<TH1F*> m_h_all_but_cross_section_weight;

      std::vector<TH1F*> m_h_lep_sf_egamma_up;
      std::vector<TH1F*> m_h_lep_sf_egamma_down;
      std::vector<TH1F*> m_h_lep_sf_muon_up;
      std::vector<TH1F*> m_h_lep_sf_muon_down;

      std::vector<TH1F*> m_h_lep_sf_ratio_egamma_up;
      std::vector<TH1F*> m_h_lep_sf_ratio_egamma_down;
      std::vector<TH1F*> m_h_lep_sf_ratio_muon_up;
      std::vector<TH1F*> m_h_lep_sf_ratio_muon_down;

      std::vector<TH1F*> m_h_btag_sf_up;
      std::vector<TH1F*> m_h_btag_sf_down;

      std::vector<TH1F*> m_h_btag_sf_ratio_up;
      std::vector<TH1F*> m_h_btag_sf_ratio_down;
  };

  // =============================================================================
  // = parent Hists
  // =============================================================================
  class ParentHists : public HistogramHandler
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      ParentHists(std::string name_tag = "");
      virtual ~ParentHists();

      virtual void FillSpecial( const PennSusyFrame::Event& event
                              , const PennSusyFrame::blPair&
                              , const PennSusyFrame::blPair&
                              , const PennSusyFrame::MCTruth&
                              , float weight
                              );
      virtual void write(TDirectory*);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    private:
      std::vector<TH1F*> m_h_parentid_all;
      std::vector<TH1F*> m_h_parentid_0;
      std::vector<TH1F*> m_h_parentid_1;
      std::vector<TH1F*> m_h_ptz_truth;
  };

  // =============================================================================
  // = dR Hists
  // =============================================================================
  class DRHists : public HistogramHandler
  {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    public:
      DRHists(std::string name_tag = "");
      virtual ~DRHists();

      virtual void FilldR(      const PennSusyFrame::Event& event
			      , const std::vector<PennSusyFrame::Electron*>&
                              , const std::vector<PennSusyFrame::Muon*>&
                              , const std::vector<PennSusyFrame::Jet*>&
				, const PennSusyFrame::MCTruth&
				, PennSusyFrame::Trigger m_trigger
                              );
      virtual void FilldR(      const PennSusyFrame::Event& event
			      , const std::vector<PennSusyFrame::Electron*>&
                              , const std::vector<PennSusyFrame::Muon*>&
                              , const std::vector<PennSusyFrame::Jet*>&
				, PennSusyFrame::Trigger m_trigger
                              );
      virtual void write(TDirectory*);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    private:
      // dR between leading lep and closest object
      std::vector<TH1D*> m_h_dr_leadinglep_closest_fc_match;
      std::vector<TH1D*> m_h_dr_leadinglep_closest_fc_mismatch;
      std::vector<TH1D*> m_h_dr_subleadinglep_closest_fc_match;
      std::vector<TH1D*> m_h_dr_subleadinglep_closest_fc_mismatch;

      // dR between leptons and jets broken down by flavor
      std::vector<TH1F*> m_h_dr_ee_from_stop;
      std::vector<TH1F*> m_h_dr_mm_from_stop;
      std::vector<TH1F*> m_h_dr_em_from_stop;
      std::vector<TH1F*> m_h_dr_ej_from_stop;
      std::vector<TH1F*> m_h_dr_mj_from_stop;
      std::vector<TH1F*> m_h_dr_ee_not_from_stop;
      std::vector<TH1F*> m_h_dr_mm_not_from_stop;
      std::vector<TH1F*> m_h_dr_em_not_from_stop;
      std::vector<TH1F*> m_h_dr_ej_not_from_stop;
      std::vector<TH1F*> m_h_dr_mj_not_from_stop;

      std::vector<TH2F*> m_h_flavor_channel_tvr;
      std::vector<TH2F*> m_h_flavor_channel_tvr_lepfromstop;
      std::vector<TH2F*> m_h_flavor_channel_tvr_lepnotfromstop;
      std::vector<TH2F*> m_h_flavor_channel_tvr_jetfromstop;
      std::vector<TH2F*> m_h_flavor_channel_tvr_jetnotfromstop;

      std::vector<TH1F*> m_h_dr_ereco_mutrig_all;
      std::vector<TH1F*> m_h_dr_breco_mutrig_all;

      std::vector<TH1F*> m_h_muon_qoverpratio;
  };
}

#endif
