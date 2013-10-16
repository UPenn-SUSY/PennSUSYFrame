#ifndef NtupleLooper_h
#define NtupleLooper_h

// =============================================================================
#include <TROOT.h>
#include <vector>

#include "SusyAnalysisTools/include/ElectronDescription.h"
#include "SusyAnalysisTools/include/MuonDescription.h"

// =============================================================================
class ProgressBar;
class TBranch;
class TChain;
class TTree;

// =============================================================================
namespace NtupleHelper
{
  enum ISO_STYLE { EWK_STYLE
                 , EWK_HIGGS_STYLE
                 , STRONG_STYLE
                 , STRONG_STYLE_CONE_30
                 };

  enum ISO_TYPE { ETCONE
                , TOPOETCONE
                , PTCONE
                };

  enum CONE_SIZE { CONE_20
                 , CONE_30
                 , CONE_40
                 };

// =============================================================================
class NtupleLooper
{
  // ---------------------------------------------------------------------------
  public :
    NtupleLooper(TTree *tree, double num_events);
    virtual ~NtupleLooper();
    virtual Int_t    GetEntry(Long64_t entry);
    virtual Long64_t LoadTree(Long64_t entry);
    virtual void     Init(TTree *tree);
    virtual void     Loop();
    virtual Bool_t   Notify();

    virtual void processEvent();
    virtual bool isSignalElectron( const size_t el_index
                                 , const SusyAnalysisTools::ElectronDescription&
                                 , bool use_default_decision = true
                                 , NtupleHelper::ISO_STYLE iso_type = EWK_STYLE
                                 , float d0_sig_cut = 5.
                                 );
    virtual bool isSignalMuon( const size_t mu_index
                             , const SusyAnalysisTools::MuonDescription&
                             , bool use_default_decision = true
                             , NtupleHelper::ISO_STYLE iso_type = EWK_STYLE
                             , float d0_sig_cut = 3.
                             );

    unsigned int getNumGoodVertices(unsigned int min_num_trks);
    double getElIsoCorr(unsigned int index, NtupleHelper::ISO_TYPE, NtupleHelper::CONE_SIZE);
    double getMuIsoCorr(unsigned int index, NtupleHelper::ISO_TYPE, NtupleHelper::CONE_SIZE);

  // ---------------------------------------------------------------------------
  protected:
    TTree* fChain;   //!pointer to the analyzed TTree or TChain
    Int_t  fCurrent; //!current Tree number in a TChain

    double m_num_events;

    // Declaration of leaf types
    UInt_t                     m_lbn;
    UInt_t                     m_run_number;
    UInt_t                     m_event_number;
    ULong64_t                  m_event_desc;
    ULong64_t                  m_sr_helper;
    Double_t                   m_mc_event_weight;
    Double_t                   m_pile_up_weight;
    Double_t                   m_trigger_weight;
    Double_t                   m_lepton_weight;
    Double_t                   m_b_tag_weight;
    Double_t                   m_cross_section_weight;
    Double_t                   m_k_factor;
    Double_t                   m_eff_times_cross_section;
    Double_t                   m_fake_weight_nom;
    Double_t                   m_fake_weight_max;
    Double_t                   m_fake_weight_min;
    Double_t                   m_charge_flip_weight;
    Double_t                   m_charge_flip_weight_max;
    Double_t                   m_charge_flip_weight_min;
    UInt_t                     m_mc_channel_number;
    Float_t                    m_actual_int_per_crossing;
    Float_t                    m_average_int_per_crossing;
    Float_t                    m_mll;
    Float_t                    m_ptll;
    Float_t                    m_mt2;
    std::vector<float>*        m_el_E;
    std::vector<float>*        m_el_Et;
    std::vector<float>*        m_el_pt;
    std::vector<float>*        m_el_eta;
    std::vector<float>*        m_el_eta_cl;
    std::vector<float>*        m_el_eta_track;
    std::vector<float>*        m_el_phi;
    std::vector<float>*        m_el_phi_cl;
    std::vector<float>*        m_el_phi_track;
    std::vector<float>*        m_el_d0;
    std::vector<float>*        m_el_d0_physics;
    std::vector<float>*        m_el_d0_pv;
    std::vector<float>*        m_el_z0;
    std::vector<float>*        m_el_z0_pv;
    std::vector<float>*        m_el_d0_pv_sig;
    std::vector<float>*        m_el_z0_pv_sig;
    std::vector<float>*        m_el_d0_sig;
    std::vector<float>*        m_el_z0_sin_theta;
    std::vector<short>*        m_el_charge;
    std::vector<ULong64_t>*    m_el_desc;
    std::vector<float>*        m_el_cf_smeared_pt;
    std::vector<float>*        m_el_etcone20;
    std::vector<float>*        m_el_etcone30;
    std::vector<float>*        m_el_etcone40;
    std::vector<float>*        m_el_ptcone20;
    std::vector<float>*        m_el_ptcone30;
    std::vector<float>*        m_el_ptcone40;
    std::vector<float>*        m_el_topoetcone20;
    std::vector<float>*        m_el_topoetcone30;
    std::vector<float>*        m_el_topoetcone40;
    std::vector<float>*        m_el_topoetcone20_corrected;
    std::vector<float>*        m_el_topoetcone30_corrected;
    std::vector<float>*        m_el_topoetcone40_corrected;
    std::vector<float>*        m_el_raw_topoetcone20_corrected;
    std::vector<float>*        m_el_raw_topoetcone30_corrected;
    std::vector<float>*        m_el_raw_topoetcone40_corrected;
    std::vector<float>*        m_el_truth_charge;
    std::vector<float>*        m_mu_pt;
    std::vector<float>*        m_mu_eta;
    std::vector<float>*        m_mu_phi;
    std::vector<float>*        m_mu_cov_d0;
    std::vector<float>*        m_mu_d0;
    std::vector<float>*        m_mu_z0;
    std::vector<float>*        m_mu_d0_sig;
    std::vector<float>*        m_mu_z0_sin_theta;
    std::vector<short>*        m_mu_charge;
    std::vector<float>*        m_mu_etcone20;
    std::vector<float>*        m_mu_etcone30;
    std::vector<float>*        m_mu_etcone40;
    std::vector<float>*        m_mu_raw_etcone20;
    std::vector<float>*        m_mu_raw_etcone30;
    std::vector<float>*        m_mu_raw_etcone40;
    std::vector<float>*        m_mu_ptcone20;
    std::vector<float>*        m_mu_ptcone30;
    std::vector<float>*        m_mu_ptcone40;
    std::vector<float>*        m_mu_ptcone20_trkelstyle;
    std::vector<float>*        m_mu_ptcone30_trkelstyle;
    std::vector<float>*        m_mu_ptcone40_trkelstyle;
    std::vector<ULong64_t>*    m_mu_desc;
    std::vector<float>*        m_jet_pt;
    std::vector<float>*        m_jet_eta;
    std::vector<float>*        m_jet_phi;
    std::vector<float>*        m_jet_bjet_mv1;
    std::vector<float>*        m_jet_dr_signal_lep;
    std::vector<float>*        m_jet_jvf;
    std::vector<ULong64_t>*    m_jet_desc;
    Float_t                    m_met_et;
    Float_t                    m_met_rel_et;
    Float_t                    m_met_rel_delta_phi;
    Float_t                    m_met_phi;
    Float_t                    m_met_sumet;
    UInt_t                     m_vtx_n;
    std::vector<float>*        m_vtx_x;
    std::vector<float>*        m_vtx_y;
    std::vector<float>*        m_vtx_z;
    std::vector<unsigned int>* m_vtx_n_tracks;
    std::vector<float>*        m_vtx_sum_pt;

    // List of branches
    TBranch* b_lbn;
    TBranch* b_run_number;
    TBranch* b_event_number;
    TBranch* b_event_desc;
    TBranch* b_sr_helper;
    TBranch* b_mc_event_weight;
    TBranch* b_pile_up_weight;
    TBranch* b_trigger_weight;
    TBranch* b_lepton_weight;
    TBranch* b_b_tag_weight;
    TBranch* b_cross_section_weight;
    TBranch* b_k_factor;
    TBranch* b_eff_times_cross_section;
    TBranch* b_fake_weight_nom;
    TBranch* b_fake_weight_max;
    TBranch* b_fake_weight_min;
    TBranch* b_charge_flip_weight;
    TBranch* b_charge_flip_weight_max;
    TBranch* b_charge_flip_weight_min;
    TBranch* b_mc_channel_number;
    TBranch* b_actual_int_per_crossing;
    TBranch* b_average_int_per_crossing;
    TBranch* b_mll;
    TBranch* b_ptll;
    TBranch* b_mt2;
    TBranch* b_el_E;
    TBranch* b_el_Et;
    TBranch* b_el_pt;
    TBranch* b_el_eta;
    TBranch* b_el_eta_cl;
    TBranch* b_el_eta_track;
    TBranch* b_el_phi;
    TBranch* b_el_phi_cl;
    TBranch* b_el_phi_track;
    TBranch* b_el_d0;
    TBranch* b_el_d0_physics;
    TBranch* b_el_d0_pv;
    TBranch* b_el_z0;
    TBranch* b_el_z0_pv;
    TBranch* b_el_d0_pv_sig;
    TBranch* b_el_z0_pv_sig;
    TBranch* b_el_d0_sig;
    TBranch* b_el_z0_sin_theta;
    TBranch* b_el_charge;
    TBranch* b_el_desc;
    TBranch* b_el_cf_smeared_pt;
    TBranch* b_el_etcone20;
    TBranch* b_el_etcone30;
    TBranch* b_el_etcone40;
    TBranch* b_el_ptcone20;
    TBranch* b_el_ptcone30;
    TBranch* b_el_ptcone40;
    TBranch* b_el_topoetcone20;
    TBranch* b_el_topoetcone30;
    TBranch* b_el_topoetcone40;
    TBranch* b_el_topoetcone20_corrected;
    TBranch* b_el_topoetcone30_corrected;
    TBranch* b_el_topoetcone40_corrected;
    TBranch* b_el_raw_topoetcone20_corrected;
    TBranch* b_el_raw_topoetcone30_corrected;
    TBranch* b_el_raw_topoetcone40_corrected;
    TBranch* b_el_truth_charge;
    TBranch* b_mu_pt;
    TBranch* b_mu_eta;
    TBranch* b_mu_phi;
    TBranch* b_mu_cov_d0;
    TBranch* b_mu_d0;
    TBranch* b_mu_z0;
    TBranch* b_mu_d0_sig;
    TBranch* b_mu_z0_sin_theta;
    TBranch* b_mu_charge;
    TBranch* b_mu_etcone20;
    TBranch* b_mu_etcone30;
    TBranch* b_mu_etcone40;
    TBranch* b_mu_raw_etcone20;
    TBranch* b_mu_raw_etcone30;
    TBranch* b_mu_raw_etcone40;
    TBranch* b_mu_ptcone20;
    TBranch* b_mu_ptcone30;
    TBranch* b_mu_ptcone40;
    TBranch* b_mu_ptcone20_trkelstyle;
    TBranch* b_mu_ptcone30_trkelstyle;
    TBranch* b_mu_ptcone40_trkelstyle;
    TBranch* b_mu_desc;
    TBranch* b_jet_pt;
    TBranch* b_jet_eta;
    TBranch* b_jet_phi;
    TBranch* b_jet_bjet_mv1;
    TBranch* b_jet_dr_signal_lep;
    TBranch* b_jet_jvf;
    TBranch* b_jet_desc;
    TBranch* b_met_et;
    TBranch* b_met_rel_et;
    TBranch* b_met_rel_delta_phi;
    TBranch* b_met_phi;
    TBranch* b_met_sumet;
    TBranch* b_vtx_n;
    TBranch* b_vtx_x;
    TBranch* b_vtx_y;
    TBranch* b_vtx_z;
    TBranch* b_vtx_n_tracks;
    TBranch* b_vtx_sum_pt;

  private:
    // ProgressBar* m_progress_bar;
};

}

#endif
