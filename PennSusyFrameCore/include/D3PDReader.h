#ifndef D3PDReader_h
#define D3PDReader_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>

namespace PennSusyFrame
{
  class D3PDReader {
  public :
    bool m_is_data;

    TTree          *fChain;   //!pointer to the analyzed TTree or TChain
    Int_t           fCurrent; //!current Tree number in a TChain

    TFile* m_output_file;
    TTree* m_output_tree;

    // Declaration of leaf types
    Bool_t          EF_2e12Tvh_loose1;
    Bool_t          EF_2mu13;
    Bool_t          EF_e12Tvh_medium1_mu8;
    Bool_t          EF_e24vh_medium1_e7_medium1;
    Bool_t          EF_mu18_tight_e7_medium1;
    Bool_t          EF_mu18_tight_mu8_EFFS;
    Float_t         Eventshape_rhoKt4LC;
    Float_t         MET_Egamma10NoTau_CellOut_etx;
    Float_t         MET_Egamma10NoTau_CellOut_ety;
    Float_t         MET_Egamma10NoTau_CellOut_sumet;
    Float_t         MET_Egamma10NoTau_RefGamma_etx;
    Float_t         MET_Egamma10NoTau_RefGamma_ety;
    Float_t         MET_Egamma10NoTau_RefGamma_sumet;
    Float_t         averageIntPerXing;
    Int_t           el_n;
    Int_t           jet_AntiKt4LCTopo_n;
    Int_t           mu_staco_n;
    Int_t           tau_n;
    Int_t           vx_n;
    UInt_t          EventNumber;
    UInt_t          RunNumber;
    UInt_t          coreFlags;
    UInt_t          larError;
    UInt_t          lbn;
    UInt_t          tileError;
    std::vector<float>   *el_charge;
    std::vector<float>   *el_cl_E;
    std::vector<float>   *el_cl_eta;
    std::vector<float>   *el_cl_phi;
    std::vector<float>   *el_cl_pt;
    std::vector<float>   *el_ptcone30;
    std::vector<float>   *el_topoEtcone30_corrected;
    std::vector<float>   *el_trackIPEstimate_d0_unbiasedpvunbiased;
    std::vector<float>   *el_trackIPEstimate_sigd0_unbiasedpvunbiased;
    std::vector<float>   *el_trackIPEstimate_z0_unbiasedpvunbiased;
    std::vector<float>   *el_tracketa;
    std::vector<float>   *el_trackphi;
    std::vector<float>   *jet_AntiKt4LCTopo_ActiveAreaE;
    std::vector<float>   *jet_AntiKt4LCTopo_ActiveAreaPx;
    std::vector<float>   *jet_AntiKt4LCTopo_ActiveAreaPy;
    std::vector<float>   *jet_AntiKt4LCTopo_ActiveAreaPz;
    std::vector<float>   *jet_AntiKt4LCTopo_AverageLArQF;
    std::vector<float>   *jet_AntiKt4LCTopo_BCH_CORR_JET;
    std::vector<float>   *jet_AntiKt4LCTopo_HECQuality;
    std::vector<float>   *jet_AntiKt4LCTopo_LArQuality;
    std::vector<float>   *jet_AntiKt4LCTopo_NegativeE;
    std::vector<float>   *jet_AntiKt4LCTopo_constscale_E;
    std::vector<float>   *jet_AntiKt4LCTopo_constscale_eta;
    std::vector<float>   *jet_AntiKt4LCTopo_constscale_m;
    std::vector<float>   *jet_AntiKt4LCTopo_constscale_phi;
    std::vector<float>   *jet_AntiKt4LCTopo_emfrac;
    std::vector<float>   *jet_AntiKt4LCTopo_eta;
    std::vector<float>   *jet_AntiKt4LCTopo_flavor_weight_MV1;
    std::vector<float>   *jet_AntiKt4LCTopo_fracSamplingMax;
    std::vector<float>   *jet_AntiKt4LCTopo_hecf;
    std::vector<float>   *jet_AntiKt4LCTopo_jvtxf;
    std::vector<float>   *jet_AntiKt4LCTopo_m;
    std::vector<float>   *jet_AntiKt4LCTopo_phi;
    std::vector<float>   *jet_AntiKt4LCTopo_pt;
    std::vector<float>   *jet_AntiKt4LCTopo_sumPtTrk_pv0_500MeV;
    std::vector<float>   *mu_staco_charge;
    std::vector<float>   *mu_staco_cov_qoverp_exPV;
    std::vector<float>   *mu_staco_d0_exPV;
    std::vector<float>   *mu_staco_eta;
    std::vector<float>   *mu_staco_etcone30;
    std::vector<float>   *mu_staco_id_qoverp_exPV;
    std::vector<float>   *mu_staco_id_theta_exPV;
    std::vector<float>   *mu_staco_me_qoverp_exPV;
    std::vector<float>   *mu_staco_me_theta_exPV;
    std::vector<float>   *mu_staco_ms_phi;
    std::vector<float>   *mu_staco_ms_qoverp;
    std::vector<float>   *mu_staco_ms_theta;
    std::vector<float>   *mu_staco_phi;
    std::vector<float>   *mu_staco_pt;
    std::vector<float>   *mu_staco_ptcone30_trkelstyle;
    std::vector<float>   *mu_staco_qoverp_exPV;
    std::vector<float>   *mu_staco_trackIPEstimate_d0_unbiasedpvunbiased;
    std::vector<float>   *mu_staco_trackIPEstimate_sigd0_unbiasedpvunbiased;
    std::vector<float>   *mu_staco_trackIPEstimate_z0_unbiasedpvunbiased;
    std::vector<float>   *mu_staco_z0_exPV;
    std::vector<float>   *tau_charge;
    std::vector<float>   *tau_eta;
    std::vector<float>   *tau_m;
    std::vector<float>   *tau_phi;
    std::vector<float>   *tau_pt;
    std::vector<float>   *trig_EF_el_E;
    std::vector<float>   *trig_EF_el_px;
    std::vector<float>   *trig_EF_el_py;
    std::vector<float>   *trig_EF_el_pz;
    std::vector<float>   *vx_E;
    std::vector<float>   *vx_m;
    std::vector<float>   *vx_x;
    std::vector<float>   *vx_y;
    std::vector<float>   *vx_z;
    std::vector<int>     *el_author;
    std::vector<int>     *el_mediumPP;
    std::vector<int>     *el_nSiHits;
    std::vector<int>     *el_tightPP;
    std::vector<int>     *jet_AntiKt4LCTopo_SamplingMax;
    std::vector<int>     *mu_staco_expectBLayerHit;
    std::vector<int>     *mu_staco_isCombinedMuon;
    std::vector<int>     *mu_staco_isSegmentTaggedMuon;
    std::vector<int>     *mu_staco_nBLHits;
    std::vector<int>     *mu_staco_nPixHits;
    std::vector<int>     *mu_staco_nPixHoles;
    std::vector<int>     *mu_staco_nSCTDeadSensors;
    std::vector<int>     *mu_staco_nSCTHits;
    std::vector<int>     *mu_staco_nSCTHoles;
    std::vector<int>     *mu_staco_nTRTHits;
    std::vector<int>     *mu_staco_nTRTOutliers;
    std::vector<int>     *tau_EleBDTLoose;
    std::vector<int>     *tau_EleBDTMedium;
    std::vector<int>     *tau_EleBDTTight;
    std::vector<int>     *tau_JetBDTSigLoose;
    std::vector<int>     *tau_JetBDTSigMedium;
    std::vector<int>     *tau_JetBDTSigTight;
    std::vector<int>     *tau_muonVeto;
    std::vector<int>     *tau_numTrack;
    std::vector<int>     *trig_EF_el_EF_e12Tvh_loose1;
    std::vector<int>     *trig_EF_el_EF_e12Tvh_medium1;
    std::vector<int>     *trig_EF_el_EF_e24vh_medium1;
    std::vector<int>     *trig_EF_el_EF_e24vh_medium1_e7_medium1;
    std::vector<int>     *trig_EF_el_EF_e7T_medium1;
    std::vector<int>     *trig_EF_trigmuonef_EF_mu13;
    std::vector<int>     *trig_EF_trigmuonef_EF_mu18_tight;
    std::vector<int>     *trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS;
    std::vector<int>     *trig_EF_trigmuonef_EF_mu8;
    std::vector<int>     *vx_nTracks;
    std::vector<std::vector<float> > *el_MET_Egamma10NoTau_wet;
    std::vector<std::vector<float> > *el_MET_Egamma10NoTau_wpx;
    std::vector<std::vector<float> > *el_MET_Egamma10NoTau_wpy;
    std::vector<std::vector<float> > *jet_AntiKt4LCTopo_MET_Egamma10NoTau_wet;
    std::vector<std::vector<float> > *jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpx;
    std::vector<std::vector<float> > *jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpy;
    std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_eta;
    std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_phi;
    std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_pt;
    std::vector<std::vector<int> > *trig_EF_trigmuonef_track_CB_hasCB;
    std::vector<std::vector<unsigned int> > *el_MET_Egamma10NoTau_statusWord;
    std::vector<std::vector<unsigned int> > *jet_AntiKt4LCTopo_MET_Egamma10NoTau_statusWord;
    std::vector<unsigned int> *el_OQ;

    // MC only variables
    std::vector<int>     *el_type;
    std::vector<int>     *el_origin;
    std::vector<int>     *el_truth_barcode;
    std::vector<int>     *el_truth_motherbarcode;
    Float_t         mc_event_weight;
    Int_t           mc_n;
    UInt_t          mc_channel_number;
    std::vector<float>   *mc_charge;
    std::vector<float>   *mc_eta;
    std::vector<float>   *mc_m;
    std::vector<float>   *mc_phi;
    std::vector<float>   *mc_pt;
    std::vector<int>     *mc_barcode;
    std::vector<int>     *mc_pdgId;
    std::vector<int>     *mc_status;
    std::vector<int>     *mc_vx_barcode;
    std::vector<std::vector<int> > *mc_child_index;
    std::vector<std::vector<int> > *mc_children;
    std::vector<std::vector<int> > *mc_parent_index;
    std::vector<std::vector<int> > *mc_parents;
    std::vector<int>     *mu_staco_truth_barcode;
    std::vector<int>     *mu_staco_truth_motherbarcode;
    std::vector<int>     *muonTruth_origin;
    std::vector<int>     *muonTruth_type;
    std::vector<int>     *jet_AntiKt4LCTopo_flavor_truth_label;

    // Int_t           mu_MET_Egamma10NoTau_n;
    // Int_t           mu_MET_n;
    // std::vector<std::vector<float> > *mu_MET_Egamma10NoTau_wet;
    // std::vector<std::vector<float> > *mu_MET_Egamma10NoTau_wpx;
    // std::vector<std::vector<float> > *mu_MET_Egamma10NoTau_wpy;
    // std::vector<std::vector<float> > *mu_MET_wet;
    // std::vector<std::vector<float> > *mu_MET_wpx;
    // std::vector<std::vector<float> > *mu_MET_wpy;
    // std::vector<std::vector<unsigned int> > *mu_MET_Egamma10NoTau_statusWord;
    // std::vector<std::vector<unsigned int> > *mu_MET_statusWord;
    // Bool_t          EF_2b35_loose_3j35_a4tchad_4L1J10;
    // Bool_t          EF_2b35_loose_3j35_a4tchad_4L1J15;
    // Bool_t          EF_2b35_loose_3j35_a4tchad_L2FS_4L1J10;
    // Bool_t          EF_2b35_loose_3j35_a4tchad_L2FS_4L1J15;
    // Bool_t          EF_2b35_loose_4j35_a4tchad;
    // Bool_t          EF_2b35_loose_4j35_a4tchad_L2FS;
    // Bool_t          EF_2b35_loose_j110_2j35_a4tchad;
    // Bool_t          EF_2b35_loose_j145_2j35_a4tchad;
    // Bool_t          EF_2b35_loose_j145_j100_j35_a4tchad;
    // Bool_t          EF_2b35_loose_j145_j35_a4tchad;
    // Bool_t          EF_2b35_medium_3j35_a4tchad_4L1J15;
    // Bool_t          EF_2b35_medium_3j35_a4tchad_L2FS_4L1J15;
    // Bool_t          EF_2b45_loose_j145_j45_a4tchad;
    // Bool_t          EF_2b45_loose_j145_j45_a4tchad_EFxe40_tclcw;
    // Bool_t          EF_2b45_medium_3j45_a4tchad_4L1J15;
    // Bool_t          EF_2b45_medium_3j45_a4tchad_L2FS_4L1J15;
    // Bool_t          EF_2b55_loose_4j55_a4tchad;
    // Bool_t          EF_2b55_loose_4j55_a4tchad_L2FS;
    // Bool_t          EF_2b55_loose_j110_j55_a4tchad;
    // Bool_t          EF_2b55_loose_j110_j55_a4tchad_1bL2;
    // Bool_t          EF_2b55_loose_j110_j55_a4tchad_ht500;
    // Bool_t          EF_2b55_loose_j145_j55_a4tchad;
    // Bool_t          EF_2b55_medium_3j55_a4tchad_4L1J15;
    // Bool_t          EF_2b55_medium_3j55_a4tchad_L2FS_4L1J15;
    // Bool_t          EF_2b55_medium_4j55_a4tchad;
    // Bool_t          EF_2b55_medium_4j55_a4tchad_L2FS;
    // Bool_t          EF_2b55_medium_j110_j55_a4tchad_ht500;
    // Bool_t          EF_2b55_medium_j165_j55_a4tchad_ht500;
    // Bool_t          EF_2b80_medium_j165_j80_a4tchad_ht500;
    // Bool_t          EF_2e5_tight1_Jpsi;
    // Bool_t          EF_2e7T_loose1_mu6;
    // Bool_t          EF_2e7T_medium1_mu6;
    // Bool_t          EF_2fj45_a4tchad_deta50_FB_L2FS_L1MBTS;
    // Bool_t          EF_2fj45_a4tchad_deta50_FB_L2FS_L1TE20;
    // Bool_t          EF_2fj55_a4tchad_deta50_FB_L2FS_L1MBTS;
    // Bool_t          EF_2fj55_a4tchad_deta50_FB_L2FS_L1TE20;
    // Bool_t          EF_2g15vh_loose_g10_loose;
    // Bool_t          EF_2g15vh_medium;
    // Bool_t          EF_2g15vh_medium_g10_medium;
    // Bool_t          EF_2g20_loose;
    // Bool_t          EF_2g20vh_medium;
    // Bool_t          EF_2g30_loose;
    // Bool_t          EF_2g40_loose;
    // Bool_t          EF_2j100_a2tcem;
    // Bool_t          EF_2j10_a4tchadloose_deta35_FC_L1MBTS;
    // Bool_t          EF_2j150_a2tcem;
    // Bool_t          EF_2j15_a4tchad_deta35_FC_L1MBTS;
    // Bool_t          EF_2j15_a4tchad_deta35_FC_L1TE20;
    // Bool_t          EF_2j200_a2tcem;
    // Bool_t          EF_2j240_a10tcem;
    // Bool_t          EF_2j240_a10tcem_L2FS;
    // Bool_t          EF_2j240_a10tclcw;
    // Bool_t          EF_2j240_a10tclcw_L2FS;
    // Bool_t          EF_2j250_a2tcem;
    // Bool_t          EF_2j25_a4tchad_deta35_FC_L1MBTS;
    // Bool_t          EF_2j25_a4tchad_deta35_FC_L1TE20;
    // Bool_t          EF_2j35_a4tchad_deta35_FC_L1MBTS;
    // Bool_t          EF_2j35_a4tchad_deta35_FC_L1TE20;
    // Bool_t          EF_2mu10;
    // Bool_t          EF_2mu10_MSonly_g10_loose;
    // Bool_t          EF_2mu10_MSonly_g10_loose_EMPTY;
    // Bool_t          EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO;
    // Bool_t          EF_2mu13_Zmumu_IDTrkNoCut;
    // Bool_t          EF_2mu13_l2muonSA;
    // Bool_t          EF_2mu15;
    // Bool_t          EF_2mu4T;
    // Bool_t          EF_2mu4T_2e5_tight1;
    // Bool_t          EF_2mu4T_Bmumu;
    // Bool_t          EF_2mu4T_Bmumu_Barrel;
    // Bool_t          EF_2mu4T_Bmumu_BarrelOnly;
    // Bool_t          EF_2mu4T_Bmumux;
    // Bool_t          EF_2mu4T_Bmumux_Barrel;
    // Bool_t          EF_2mu4T_Bmumux_BarrelOnly;
    // Bool_t          EF_2mu4T_DiMu;
    // Bool_t          EF_2mu4T_DiMu_Barrel;
    // Bool_t          EF_2mu4T_DiMu_BarrelOnly;
    // Bool_t          EF_2mu4T_DiMu_L2StarB;
    // Bool_t          EF_2mu4T_DiMu_L2StarC;
    // Bool_t          EF_2mu4T_DiMu_e5_tight1;
    // Bool_t          EF_2mu4T_DiMu_l2muonSA;
    // Bool_t          EF_2mu4T_DiMu_noVtx_noOS;
    // Bool_t          EF_2mu4T_Jpsimumu;
    // Bool_t          EF_2mu4T_Jpsimumu_Barrel;
    // Bool_t          EF_2mu4T_Jpsimumu_BarrelOnly;
    // Bool_t          EF_2mu4T_Jpsimumu_IDTrkNoCut;
    // Bool_t          EF_2mu4T_Upsimumu;
    // Bool_t          EF_2mu4T_Upsimumu_Barrel;
    // Bool_t          EF_2mu4T_Upsimumu_BarrelOnly;
    // Bool_t          EF_2mu4T_xe50_tclcw;
    // Bool_t          EF_2mu4T_xe60;
    // Bool_t          EF_2mu4T_xe60_tclcw;
    // Bool_t          EF_2mu6;
    // Bool_t          EF_2mu6_Bmumu;
    // Bool_t          EF_2mu6_Bmumux;
    // Bool_t          EF_2mu6_DiMu;
    // Bool_t          EF_2mu6_DiMu_DY20;
    // Bool_t          EF_2mu6_DiMu_DY25;
    // Bool_t          EF_2mu6_DiMu_noVtx_noOS;
    // Bool_t          EF_2mu6_Jpsimumu;
    // Bool_t          EF_2mu6_Upsimumu;
    // Bool_t          EF_2mu6i_DiMu_DY;
    // Bool_t          EF_2mu6i_DiMu_DY_2j25_a4tchad;
    // Bool_t          EF_2mu6i_DiMu_DY_noVtx_noOS;
    // Bool_t          EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad;
    // Bool_t          EF_2mu8_EFxe30;
    // Bool_t          EF_2mu8_EFxe30_tclcw;
    // Bool_t          EF_2tau29T_medium1;
    // Bool_t          EF_2tau29_medium1;
    // Bool_t          EF_2tau29i_medium1;
    // Bool_t          EF_2tau38T_medium1;
    // Bool_t          EF_2tau38T_medium1_llh;
    // Bool_t          EF_2tau38T_medium;
    // Bool_t          EF_3g15vh_loose;
    // Bool_t          EF_3g15vh_medium;
    // Bool_t          EF_3j10_a4tchadloose_L1MBTS;
    // Bool_t          EF_3j170_a4tchad_L1J75;
    // Bool_t          EF_3j170_a4tclcw_L1J75;
    // Bool_t          EF_3j180_a4tchad_L1J75;
    // Bool_t          EF_3j180_a4tthad;
    // Bool_t          EF_3j25_a4tchad;
    // Bool_t          EF_3j25_a4tchad_L1MBTS;
    // Bool_t          EF_3j35_a4tchad_L2FS_4L1J15;
    // Bool_t          EF_3j45_a4tchad_L2FS;
    // Bool_t          EF_3j45_a4tchad_L2FS_4L1J15;
    // Bool_t          EF_3j45_a4tchad_L2FS_L1RD0;
    // Bool_t          EF_3j55_a4tchad_L2FS;
    // Bool_t          EF_3mu4T;
    // Bool_t          EF_3mu4T_DiMu;
    // Bool_t          EF_3mu4T_Jpsi;
    // Bool_t          EF_3mu4T_Tau;
    // Bool_t          EF_3mu4T_Upsi;
    // Bool_t          EF_3mu6;
    // Bool_t          EF_3mu6_MSonly;
    // Bool_t          EF_3mu6_MSonly_EMPTY;
    // Bool_t          EF_3mu6_MSonly_UNPAIRED_ISO;
    // Bool_t          EF_4j10_a4tchadloose_L1MBTS;
    // Bool_t          EF_4j110_a4tchad_L2FS;
    // Bool_t          EF_4j110_a4tchad_L2FS_4L1J20;
    // Bool_t          EF_4j110_a4tchad_L2FS_5L1J15;
    // Bool_t          EF_4j110_a4tclcw_L2FS;
    // Bool_t          EF_4j25_a4tchad;
    // Bool_t          EF_4j25_a4tchad_L1MBTS;
    // Bool_t          EF_4j45_a4tchad_L2FS;
    // Bool_t          EF_4j45_a4tchad_L2FS_4L1J10;
    // Bool_t          EF_4j45_a4tchad_L2FS_L1RD0;
    // Bool_t          EF_4j55_a4tchad_L2FS;
    // Bool_t          EF_4j55_a4tchad_L2FSj15had;
    // Bool_t          EF_4j55_a4tchad_L2FSj25had;
    // Bool_t          EF_4j55_a4tthad_L2FS;
    // Bool_t          EF_4j65_a4tchad_L2FS;
    // Bool_t          EF_4j65_a4tchad_L2FS_4L1J20;
    // Bool_t          EF_4j65_a4tchad_L2FS_5L1J15;
    // Bool_t          EF_4j80_a4tchad_L2FS;
    // Bool_t          EF_4j80_a4tchad_L2FS_4L1J20;
    // Bool_t          EF_4j80_a4tchad_L2FS_5L1J15;
    // Bool_t          EF_4j80_a4tclcw_L2FS;
    // Bool_t          EF_4mu4T;
    // Bool_t          EF_5j10_a4tchadloose_L1MBTS;
    // Bool_t          EF_5j110_a4tchad_L2FS;
    // Bool_t          EF_5j110_a4tchad_L2FS_4L1J20;
    // Bool_t          EF_5j110_a4tchad_L2FS_5L1J15;
    // Bool_t          EF_5j25_a4tchad;
    // Bool_t          EF_5j25_a4tchad_L1MBTS;
    // Bool_t          EF_5j45_a4tchad_L2FS;
    // Bool_t          EF_5j45_a4tchad_L2FS_5L1J10;
    // Bool_t          EF_5j45_a4tchad_L2FS_L1RD0;
    // Bool_t          EF_5j45_a4tclcw_L2FS;
    // Bool_t          EF_5j55_a4tchad_L2FS;
    // Bool_t          EF_5j55_a4tchad_L2FSPS;
    // Bool_t          EF_5j55_a4tchad_L2FS_5L1J15;
    // Bool_t          EF_5j55_a4tchad_L2FSj15had;
    // Bool_t          EF_5j55_a4tchad_L2FSj25had;
    // Bool_t          EF_5j55_a4tchad_L2PS;
    // Bool_t          EF_5j65_a4tchad_L2FS;
    // Bool_t          EF_5j65_a4tchad_L2FS_4L1J20;
    // Bool_t          EF_5j65_a4tchad_L2FS_5L1J15;
    // Bool_t          EF_5j80_a4tchad_L2FS;
    // Bool_t          EF_5j80_a4tchad_L2FS_4L1J20;
    // Bool_t          EF_5j80_a4tchad_L2FS_5L1J15;
    // Bool_t          EF_6j35_a4tchad_L2FS_5L2j15;
    // Bool_t          EF_6j45_a4tchad_L2FS;
    // Bool_t          EF_6j45_a4tchad_L2FS_5L2j15;
    // Bool_t          EF_6j45_a4tclcw_L2FS_5L2j15;
    // Bool_t          EF_6j55_a4tchad_L2FS;
    // Bool_t          EF_6j55_a4tchad_L2FSPS;
    // Bool_t          EF_6j55_a4tchad_L2FS_5L1J15;
    // Bool_t          EF_6j55_a4tchad_L2FS_5L2j15;
    // Bool_t          EF_6j55_a4tchad_L2FSj15had;
    // Bool_t          EF_6j55_a4tchad_L2FSj25had;
    // Bool_t          EF_6j55_a4tchad_L2PS;
    // Bool_t          EF_6j65_a4tchad_L2FS;
    // Bool_t          EF_6j65_a4tchad_L2FS_5L1J15;
    // Bool_t          EF_7j35_a4tchad_L2FS_5L2j15;
    // Bool_t          EF_7j35_a4tclcw_L2FS_5L2j15;
    // Bool_t          EF_7j45_a4tchad_L2FS;
    // Bool_t          EF_7j45_a4tchad_L2FS_5L2j15;
    // Bool_t          EF_7j55_a4tchad_L2FS;
    // Bool_t          EF_7j55_a4tchad_L2FS_5L1J15;
    // Bool_t          EF_7j65_a4tchad_L2FS;
    // Bool_t          EF_7j65_a4tchad_L2FS_5L1J15;
    // Bool_t          EF_ALFA_Phys;
    // Bool_t          EF_Background;
    // Bool_t          EF_Background_RD0_EMPTY;
    // Bool_t          EF_Background_RD0_UNPAIRED_ISO;
    // Bool_t          EF_CosmicsAllTeEFID;
    // Bool_t          EF_CosmicsAllTeIDSCAN_AllPhysics_4Hits_TrkHypo;
    // Bool_t          EF_CosmicsAllTeIDSCAN_AllPhysics_TrkHypo;
    // Bool_t          EF_CosmicsAllTeSiTrack_AllPhysics_4Hits_TrkHypo;
    // Bool_t          EF_CosmicsAllTeSiTrack_AllPhysics_TrkHypo;
    // Bool_t          EF_CosmicsAllTeTRTxK_TRTTrkHypo_AllPhysics;
    // Bool_t          EF_CosmicsAllTeTRTxK_TRTTrkHypo_Pixel;
    // Bool_t          EF_Cosmics_MU11_TRTxK_TRTTrkHypo_AllID;
    // Bool_t          EF_Cosmics_MU11_TRTxK_TRTTrkHypo_Pixel;
    // Bool_t          EF_HLTTimeBurner;
    // Bool_t          EF_InDetMon_FS;
    // Bool_t          EF_L12MU4_NoAlg;
    // Bool_t          EF_L1Calo_NoAlg;
    // Bool_t          EF_L1FJ100_NoAlg;
    // Bool_t          EF_L1FJ30_empty_NoAlg;
    // Bool_t          EF_L1J10_empty_NoAlg;
    // Bool_t          EF_L1J10_firstempty_NoAlg;
    // Bool_t          EF_L1J30_empty_NoAlg;
    // Bool_t          EF_L1J30_firstempty_NoAlg;
    // Bool_t          EF_L1J350_NoAlg;
    // Bool_t          EF_L1JE140_NoAlg;
    // Bool_t          EF_L1JE200_NoAlg;
    // Bool_t          EF_L1JE350_NoAlg;
    // Bool_t          EF_L1JE500_NoAlg;
    // Bool_t          EF_L1MU10_NoAlg;
    // Bool_t          EF_L1MU15_NoAlg;
    // Bool_t          EF_L1MinBias_NoAlg;
    // Bool_t          EF_L1Muon_NoAlg;
    // Bool_t          EF_L1RD0_firstempty_NoAlg;
    // Bool_t          EF_L1TRT_NoAlg;
    // Bool_t          EF_PreS_L1EM3_empty;
    // Bool_t          EF_PreS_L1EM6_empty;
    // Bool_t          EF_PreS_L1J10_empty;
    // Bool_t          EF_PreS_L1J10_firstempty;
    // Bool_t          EF_PreS_L1J30_empty;
    // Bool_t          EF_PreS_L1J30_firstempty;
    // Bool_t          EF_PreS_L1TAU8_empty;
    // Bool_t          EF_ROBRequestMon;
    // Bool_t          EF_Standby;
    // Bool_t          EF_TileCalib_laser;
    // Bool_t          EF_VdM_mbSpTrk;
    // Bool_t          EF_allL1_NoAlg;
    // Bool_t          EF_b110_looseEF_j110_a4tchad;
    // Bool_t          EF_b110_loose_j110_a10tcem_L2FS_L1J75;
    // Bool_t          EF_b110_loose_j110_a4tchad_xe55_tclcw;
    // Bool_t          EF_b110_loose_j110_a4tchad_xe60_tclcw;
    // Bool_t          EF_b145_loose_j145_a10tcem_L2FS;
    // Bool_t          EF_b145_loose_j145_a4tchad;
    // Bool_t          EF_b145_mediumEF_j145_a4tchad_L2EFxe60_tclcw;
    // Bool_t          EF_b145_medium_j145_a4tchad_ht400;
    // Bool_t          EF_b15_NoCut_j15_a4tchad;
    // Bool_t          EF_b15_looseEF_j15_a4tchad;
    // Bool_t          EF_b165_medium_j165_a4tchad_ht500;
    // Bool_t          EF_b180_loose_j180_a10tcem_L2FS;
    // Bool_t          EF_b180_loose_j180_a10tcem_L2j140;
    // Bool_t          EF_b180_loose_j180_a10tcem_L2j140_EFxe50_tclcw;
    // Bool_t          EF_b180_loose_j180_a4tchad_L2j140;
    // Bool_t          EF_b180_medium_j180_a10tcem_L2j140_EFxe50_tclcw;
    // Bool_t          EF_b220_loose_j220_a10tcem;
    // Bool_t          EF_b220_loose_j220_a4tchad_L2j140;
    // Bool_t          EF_b240_loose_j240_a10tcem_L2FS;
    // Bool_t          EF_b240_loose_j240_a10tcem_L2j140;
    // Bool_t          EF_b25_looseEF_j25_a4tchad;
    // Bool_t          EF_b280_loose_j280_a10tcem;
    // Bool_t          EF_b280_loose_j280_a4tchad_L2j140;
    // Bool_t          EF_b35_NoCut_4j35_a4tchad;
    // Bool_t          EF_b35_NoCut_4j35_a4tchad_5L1J10;
    // Bool_t          EF_b35_NoCut_4j35_a4tchad_L2FS;
    // Bool_t          EF_b35_NoCut_4j35_a4tchad_L2FS_5L1J10;
    // Bool_t          EF_b35_looseEF_j35_a4tchad;
    // Bool_t          EF_b35_loose_4j35_a4tchad_5L1J10;
    // Bool_t          EF_b35_loose_4j35_a4tchad_L2FS_5L1J10;
    // Bool_t          EF_b35_loose_j110_2j35_a4tchad_EFxe80_tclcw;
    // Bool_t          EF_b35_medium_3j35_a4tchad_4L1J15;
    // Bool_t          EF_b35_medium_3j35_a4tchad_L2FS_4L1J15;
    // Bool_t          EF_b360_loose_j360_a4tchad_L2j140;
    // Bool_t          EF_b45_looseEF_j145_a4tchad_L2EFxe60_tclcw;
    // Bool_t          EF_b45_looseEF_j45_a4tchad;
    // Bool_t          EF_b45_mediumEF_j110_j45_xe60_tclcw;
    // Bool_t          EF_b45_medium_3j45_a4tchad_4L1J15;
    // Bool_t          EF_b45_medium_3j45_a4tchad_L2FS_4L1J15;
    // Bool_t          EF_b45_medium_4j45_a4tchad;
    // Bool_t          EF_b45_medium_4j45_a4tchad_4L1J10;
    // Bool_t          EF_b45_medium_4j45_a4tchad_L2FS;
    // Bool_t          EF_b45_medium_4j45_a4tchad_L2FS_4L1J10;
    // Bool_t          EF_b45_medium_j145_j45_a4tchad_ht400;
    // Bool_t          EF_b45_medium_j145_j45_a4tchad_ht500;
    // Bool_t          EF_b55_NoCut_j55_a4tchad;
    // Bool_t          EF_b55_NoCut_j55_a4tchad_L2FS;
    // Bool_t          EF_b55_looseEF_j55_a4tchad;
    // Bool_t          EF_b55_loose_4j55_a4tchad;
    // Bool_t          EF_b55_loose_4j55_a4tchad_L2FS;
    // Bool_t          EF_b55_mediumEF_j110_j55_xe60_tclcw;
    // Bool_t          EF_b55_medium_3j55_a4tchad_4L1J15;
    // Bool_t          EF_b55_medium_3j55_a4tchad_L2FS_4L1J15;
    // Bool_t          EF_b55_medium_4j55_a4tchad;
    // Bool_t          EF_b55_medium_4j55_a4tchad_4L1J10;
    // Bool_t          EF_b55_medium_4j55_a4tchad_L2FS;
    // Bool_t          EF_b55_medium_4j55_a4tchad_L2FS_4L1J10;
    // Bool_t          EF_b55_medium_j110_j55_a4tchad;
    // Bool_t          EF_b80_looseEF_j80_a4tchad;
    // Bool_t          EF_b80_loose_j80_a4tchad_xe55_tclcw;
    // Bool_t          EF_b80_loose_j80_a4tchad_xe60_tclcw;
    // Bool_t          EF_b80_loose_j80_a4tchad_xe70_tclcw;
    // Bool_t          EF_b80_loose_j80_a4tchad_xe75_tclcw;
    // Bool_t          EF_cost_monitor;
    // Bool_t          EF_e11_etcut;
    // Bool_t          EF_e12Tvh_loose1;
    // Bool_t          EF_e12Tvh_loose1_mu8;
    // Bool_t          EF_e12Tvh_medium1;
    // Bool_t          EF_e12Tvh_medium1_mu10;
    // Bool_t          EF_e12Tvh_medium1_mu6;
    // Bool_t          EF_e12Tvh_medium1_mu6_topo_medium;
    // Bool_t          EF_e13_etcutTrk_xs60;
    // Bool_t          EF_e13_etcutTrk_xs60_dphi2j15xe20;
    // Bool_t          EF_e14_tight1_e4_etcut_Jpsi;
    // Bool_t          EF_e15vh_medium1;
    // Bool_t          EF_e18_loose1;
    // Bool_t          EF_e18_loose1_g25_medium;
    // Bool_t          EF_e18_loose1_g35_loose;
    // Bool_t          EF_e18_loose1_g35_medium;
    // Bool_t          EF_e18_medium1;
    // Bool_t          EF_e18_medium1_g25_loose;
    // Bool_t          EF_e18_medium1_g25_medium;
    // Bool_t          EF_e18_medium1_g35_loose;
    // Bool_t          EF_e18_medium1_g35_medium;
    // Bool_t          EF_e18vh_medium1;
    // Bool_t          EF_e18vh_medium1_2e7T_medium1;
    // Bool_t          EF_e20_etcutTrk_xe30_dphi2j15xe20;
    // Bool_t          EF_e20_etcutTrk_xs60_dphi2j15xe20;
    // Bool_t          EF_e20vhT_medium1_g6T_etcut_Upsi;
    // Bool_t          EF_e20vhT_tight1_g6T_etcut_Upsi;
    // Bool_t          EF_e22vh_loose0;
    // Bool_t          EF_e22vh_loose1;
    // Bool_t          EF_e22vh_loose;
    // Bool_t          EF_e22vh_medium1;
    // Bool_t          EF_e22vh_medium1_IDTrkNoCut;
    // Bool_t          EF_e22vh_medium1_IdScan;
    // Bool_t          EF_e22vh_medium1_SiTrk;
    // Bool_t          EF_e22vh_medium1_TRT;
    // Bool_t          EF_e22vhi_medium1;
    // Bool_t          EF_e24vh_loose0;
    // Bool_t          EF_e24vh_loose1;
    // Bool_t          EF_e24vh_loose;
    // Bool_t          EF_e24vh_medium1;
    // Bool_t          EF_e24vh_medium1_EFxe30;
    // Bool_t          EF_e24vh_medium1_EFxe30_tcem;
    // Bool_t          EF_e24vh_medium1_EFxe35_tcem;
    // Bool_t          EF_e24vh_medium1_EFxe35_tclcw;
    // Bool_t          EF_e24vh_medium1_EFxe40;
    // Bool_t          EF_e24vh_medium1_IDTrkNoCut;
    // Bool_t          EF_e24vh_medium1_IdScan;
    // Bool_t          EF_e24vh_medium1_L2StarB;
    // Bool_t          EF_e24vh_medium1_L2StarC;
    // Bool_t          EF_e24vh_medium1_SiTrk;
    // Bool_t          EF_e24vh_medium1_TRT;
    // Bool_t          EF_e24vh_medium1_b35_mediumEF_j35_a4tchad;
    // Bool_t          EF_e24vh_tight1_e15_NoCut_Zee;
    // Bool_t          EF_e24vhi_loose1_mu8;
    // Bool_t          EF_e24vhi_medium1;
    // Bool_t          EF_e45_etcut;
    // Bool_t          EF_e45_medium1;
    // Bool_t          EF_e5_tight1;
    // Bool_t          EF_e5_tight1_e14_etcut_Jpsi;
    // Bool_t          EF_e5_tight1_e4_etcut_Jpsi;
    // Bool_t          EF_e5_tight1_e4_etcut_Jpsi_IdScan;
    // Bool_t          EF_e5_tight1_e4_etcut_Jpsi_L2StarB;
    // Bool_t          EF_e5_tight1_e4_etcut_Jpsi_L2StarC;
    // Bool_t          EF_e5_tight1_e4_etcut_Jpsi_SiTrk;
    // Bool_t          EF_e5_tight1_e4_etcut_Jpsi_TRT;
    // Bool_t          EF_e5_tight1_e5_NoCut;
    // Bool_t          EF_e5_tight1_e9_etcut_Jpsi;
    // Bool_t          EF_e60_etcut;
    // Bool_t          EF_e60_medium1;
    // Bool_t          EF_e7T_loose1;
    // Bool_t          EF_e7T_loose1_2mu6;
    // Bool_t          EF_e7T_medium1;
    // Bool_t          EF_e7T_medium1_2mu6;
    // Bool_t          EF_e9_tight1_e4_etcut_Jpsi;
    // Bool_t          EF_eb_physics;
    // Bool_t          EF_eb_physics_empty;
    // Bool_t          EF_eb_physics_firstempty;
    // Bool_t          EF_eb_physics_noL1PS;
    // Bool_t          EF_eb_physics_unpaired_iso;
    // Bool_t          EF_eb_physics_unpaired_noniso;
    // Bool_t          EF_eb_random;
    // Bool_t          EF_eb_random_empty;
    // Bool_t          EF_eb_random_firstempty;
    // Bool_t          EF_eb_random_unpaired_iso;
    // Bool_t          EF_fj10_a4tchadloose;
    // Bool_t          EF_fj10_a4tchadloose_L1MBTS;
    // Bool_t          EF_fj110_a4tchad;
    // Bool_t          EF_fj145_a4tchad;
    // Bool_t          EF_fj145_a4tclcw;
    // Bool_t          EF_fj15_a4tchad;
    // Bool_t          EF_fj15_a4tchad_L1MBTS;
    // Bool_t          EF_fj15_a4tchad_L1TE20;
    // Bool_t          EF_fj180_a4tchad;
    // Bool_t          EF_fj220_a4tchad;
    // Bool_t          EF_fj25_a4tchad;
    // Bool_t          EF_fj25_a4tchad_L1MBTS;
    // Bool_t          EF_fj25_a4tchad_L1TE20;
    // Bool_t          EF_fj35_a4tchad;
    // Bool_t          EF_fj35_a4tchad_L1MBTS;
    // Bool_t          EF_fj35_a4tchad_L1TE20;
    // Bool_t          EF_fj35_a4tclcw;
    // Bool_t          EF_fj45_a4tchad_L1RD0;
    // Bool_t          EF_fj45_a4tchad_L2FS;
    // Bool_t          EF_fj45_a4tchad_L2FS_L1MBTS;
    // Bool_t          EF_fj45_a4tchad_L2FS_L1TE20;
    // Bool_t          EF_fj55_a4tchad_L2FS;
    // Bool_t          EF_fj55_a4tchad_L2FS_L1MBTS;
    // Bool_t          EF_fj55_a4tchad_L2FS_L1TE20;
    // Bool_t          EF_fj80_a4tchad;
    // Bool_t          EF_g100_loose;
    // Bool_t          EF_g10_NoCut_cosmic;
    // Bool_t          EF_g10_loose;
    // Bool_t          EF_g10_medium;
    // Bool_t          EF_g120_loose;
    // Bool_t          EF_g12Tvh_loose;
    // Bool_t          EF_g12Tvh_loose_larcalib;
    // Bool_t          EF_g12Tvh_medium;
    // Bool_t          EF_g15_loose;
    // Bool_t          EF_g15vh_loose;
    // Bool_t          EF_g15vh_medium;
    // Bool_t          EF_g200_etcut;
    // Bool_t          EF_g20Tvh_medium;
    // Bool_t          EF_g20_etcut;
    // Bool_t          EF_g20_loose;
    // Bool_t          EF_g20_loose_larcalib;
    // Bool_t          EF_g20_medium;
    // Bool_t          EF_g20vh_medium;
    // Bool_t          EF_g30_loose_g20_loose;
    // Bool_t          EF_g30_medium_g20_medium;
    // Bool_t          EF_g35_loose_g25_loose;
    // Bool_t          EF_g35_loose_g30_loose;
    // Bool_t          EF_g40_loose;
    // Bool_t          EF_g40_loose_EFxe50;
    // Bool_t          EF_g40_loose_L2EFxe50;
    // Bool_t          EF_g40_loose_L2EFxe60;
    // Bool_t          EF_g40_loose_L2EFxe60_tclcw;
    // Bool_t          EF_g40_loose_g25_loose;
    // Bool_t          EF_g40_loose_g30_loose;
    // Bool_t          EF_g40_loose_larcalib;
    // Bool_t          EF_g5_NoCut_cosmic;
    // Bool_t          EF_g60_loose;
    // Bool_t          EF_g60_loose_larcalib;
    // Bool_t          EF_g80_loose;
    // Bool_t          EF_g80_loose_larcalib;
    // Bool_t          EF_hadCalib_trk18;
    // Bool_t          EF_hadCalib_trk18_L1HA8;
    // Bool_t          EF_hadCalib_trk18_L1RD0;
    // Bool_t          EF_hadCalib_trk9;
    // Bool_t          EF_hadCalib_trk9_L1HA8;
    // Bool_t          EF_hadCalib_trk9_L1RD0;
    // Bool_t          EF_hadCalib_trk9phi;
    // Bool_t          EF_high_eb_physics;
    // Bool_t          EF_j10_a4tchadloose;
    // Bool_t          EF_j10_a4tchadloose_L1MBTS;
    // Bool_t          EF_j10_fj10_a4tchadloose_deta50_FC_L1MBTS;
    // Bool_t          EF_j110_2j55_a4tchad;
    // Bool_t          EF_j110_2j55_a4tchad_L2FS;
    // Bool_t          EF_j110_a10tcem_L2FS;
    // Bool_t          EF_j110_a10tcem_L2FS_2j55_a4tchad;
    // Bool_t          EF_j110_a4tchad;
    // Bool_t          EF_j110_a4tchad_xe100_tclcw;
    // Bool_t          EF_j110_a4tchad_xe100_tclcw_veryloose;
    // Bool_t          EF_j110_a4tchad_xe50_tclcw;
    // Bool_t          EF_j110_a4tchad_xe55_tclcw;
    // Bool_t          EF_j110_a4tchad_xe60_tclcw;
    // Bool_t          EF_j110_a4tchad_xe60_tclcw_loose;
    // Bool_t          EF_j110_a4tchad_xe60_tclcw_veryloose;
    // Bool_t          EF_j110_a4tchad_xe65_tclcw;
    // Bool_t          EF_j110_a4tchad_xe70_tclcw_loose;
    // Bool_t          EF_j110_a4tchad_xe70_tclcw_veryloose;
    // Bool_t          EF_j110_a4tchad_xe75_tclcw;
    // Bool_t          EF_j110_a4tchad_xe80_tclcw_loose;
    // Bool_t          EF_j110_a4tchad_xe90_tclcw_loose;
    // Bool_t          EF_j110_a4tchad_xe90_tclcw_veryloose;
    // Bool_t          EF_j110_a4tclcw_xe100_tclcw_veryloose;
    // Bool_t          EF_j145_2j45_a4tchad_L2EFxe70_tclcw;
    // Bool_t          EF_j145_a10tcem_L2FS;
    // Bool_t          EF_j145_a10tcem_L2FS_L2xe60_tclcw;
    // Bool_t          EF_j145_a4tchad;
    // Bool_t          EF_j145_a4tchad_L2EFxe60_tclcw;
    // Bool_t          EF_j145_a4tchad_L2EFxe70_tclcw;
    // Bool_t          EF_j145_a4tchad_L2EFxe80_tclcw;
    // Bool_t          EF_j145_a4tchad_L2EFxe90_tclcw;
    // Bool_t          EF_j145_a4tchad_ht500_L2FS;
    // Bool_t          EF_j145_a4tchad_ht600_L2FS;
    // Bool_t          EF_j145_a4tchad_ht700_L2FS;
    // Bool_t          EF_j145_a4tclcw_L2EFxe90_tclcw;
    // Bool_t          EF_j145_j100_j35_a4tchad;
    // Bool_t          EF_j15_a4tchad;
    // Bool_t          EF_j15_a4tchad_L1MBTS;
    // Bool_t          EF_j15_a4tchad_L1TE20;
    // Bool_t          EF_j15_fj15_a4tchad_deta50_FC_L1MBTS;
    // Bool_t          EF_j15_fj15_a4tchad_deta50_FC_L1TE20;
    // Bool_t          EF_j165_u0uchad_LArNoiseBurst;
    // Bool_t          EF_j170_a4tchad_EFxe50_tclcw;
    // Bool_t          EF_j170_a4tchad_EFxe60_tclcw;
    // Bool_t          EF_j170_a4tchad_EFxe70_tclcw;
    // Bool_t          EF_j170_a4tchad_EFxe80_tclcw;
    // Bool_t          EF_j170_a4tchad_ht500;
    // Bool_t          EF_j170_a4tchad_ht600;
    // Bool_t          EF_j170_a4tchad_ht700;
    // Bool_t          EF_j180_a10tcem;
    // Bool_t          EF_j180_a10tcem_EFxe50_tclcw;
    // Bool_t          EF_j180_a10tcem_e45_loose1;
    // Bool_t          EF_j180_a10tclcw_EFxe50_tclcw;
    // Bool_t          EF_j180_a4tchad;
    // Bool_t          EF_j180_a4tclcw;
    // Bool_t          EF_j180_a4tthad;
    // Bool_t          EF_j220_a10tcem_e45_etcut;
    // Bool_t          EF_j220_a10tcem_e45_loose1;
    // Bool_t          EF_j220_a10tcem_e60_etcut;
    // Bool_t          EF_j220_a4tchad;
    // Bool_t          EF_j220_a4tthad;
    // Bool_t          EF_j240_a10tcem;
    // Bool_t          EF_j240_a10tcem_e45_etcut;
    // Bool_t          EF_j240_a10tcem_e45_loose1;
    // Bool_t          EF_j240_a10tcem_e60_etcut;
    // Bool_t          EF_j240_a10tcem_e60_loose1;
    // Bool_t          EF_j240_a10tclcw;
    // Bool_t          EF_j25_a4tchad;
    // Bool_t          EF_j25_a4tchad_L1MBTS;
    // Bool_t          EF_j25_a4tchad_L1TE20;
    // Bool_t          EF_j25_fj25_a4tchad_deta50_FC_L1MBTS;
    // Bool_t          EF_j25_fj25_a4tchad_deta50_FC_L1TE20;
    // Bool_t          EF_j260_a4tthad;
    // Bool_t          EF_j280_a10tclcw_L2FS;
    // Bool_t          EF_j280_a4tchad;
    // Bool_t          EF_j280_a4tchad_mjj2000dy34;
    // Bool_t          EF_j30_a4tcem_eta13_xe30_empty;
    // Bool_t          EF_j30_a4tcem_eta13_xe30_firstempty;
    // Bool_t          EF_j30_u0uchad_empty_LArNoiseBurst;
    // Bool_t          EF_j35_a10tcem;
    // Bool_t          EF_j35_a4tcem_L1TAU_LOF_HV;
    // Bool_t          EF_j35_a4tcem_L1TAU_LOF_HV_EMPTY;
    // Bool_t          EF_j35_a4tcem_L1TAU_LOF_HV_UNPAIRED_ISO;
    // Bool_t          EF_j35_a4tchad;
    // Bool_t          EF_j35_a4tchad_L1MBTS;
    // Bool_t          EF_j35_a4tchad_L1TE20;
    // Bool_t          EF_j35_a4tclcw;
    // Bool_t          EF_j35_a4tthad;
    // Bool_t          EF_j35_fj35_a4tchad_deta50_FC_L1MBTS;
    // Bool_t          EF_j35_fj35_a4tchad_deta50_FC_L1TE20;
    // Bool_t          EF_j360_a10tcem;
    // Bool_t          EF_j360_a10tclcw;
    // Bool_t          EF_j360_a4tchad;
    // Bool_t          EF_j360_a4tclcw;
    // Bool_t          EF_j360_a4tthad;
    // Bool_t          EF_j380_a4tthad;
    // Bool_t          EF_j45_a10tcem_L1RD0;
    // Bool_t          EF_j45_a4tchad;
    // Bool_t          EF_j45_a4tchad_L1RD0;
    // Bool_t          EF_j45_a4tchad_L2FS;
    // Bool_t          EF_j45_a4tchad_L2FS_L1RD0;
    // Bool_t          EF_j460_a10tcem;
    // Bool_t          EF_j460_a10tclcw;
    // Bool_t          EF_j460_a4tchad;
    // Bool_t          EF_j50_a4tcem_eta13_xe50_empty;
    // Bool_t          EF_j50_a4tcem_eta13_xe50_firstempty;
    // Bool_t          EF_j50_a4tcem_eta25_xe50_empty;
    // Bool_t          EF_j50_a4tcem_eta25_xe50_firstempty;
    // Bool_t          EF_j55_a4tchad;
    // Bool_t          EF_j55_a4tchad_L2FS;
    // Bool_t          EF_j55_a4tclcw;
    // Bool_t          EF_j55_u0uchad_firstempty_LArNoiseBurst;
    // Bool_t          EF_j65_a4tchad_L2FS;
    // Bool_t          EF_j80_a10tcem_L2FS;
    // Bool_t          EF_j80_a4tchad;
    // Bool_t          EF_j80_a4tchad_xe100_tclcw_loose;
    // Bool_t          EF_j80_a4tchad_xe100_tclcw_veryloose;
    // Bool_t          EF_j80_a4tchad_xe55_tclcw;
    // Bool_t          EF_j80_a4tchad_xe60_tclcw;
    // Bool_t          EF_j80_a4tchad_xe70_tclcw;
    // Bool_t          EF_j80_a4tchad_xe70_tclcw_dphi2j45xe10;
    // Bool_t          EF_j80_a4tchad_xe70_tclcw_loose;
    // Bool_t          EF_j80_a4tchad_xe80_tclcw_loose;
    // Bool_t          EF_j80_a4tchad_xe85_tclcw_dphi2j45xe10;
    // Bool_t          EF_l2j25_a4tcem_Trackless_HV;
    // Bool_t          EF_l2j25_a4tcem_Trackless_HV_EMPTY;
    // Bool_t          EF_l2j25_a4tcem_Trackless_HV_UNPAIRED_ISO;
    // Bool_t          EF_l2j30_a4tcem_2L1MU4_HV_EMPTY;
    // Bool_t          EF_l2j30_a4tcem_2L1MU6_HV;
    // Bool_t          EF_l2j30_a4tcem_2L1MU6_HV_UNPAIRED_ISO;
    // Bool_t          EF_mbLucid_eff;
    // Bool_t          EF_mbLucid_eff_empty;
    // Bool_t          EF_mbLucid_eff_unpaired_iso;
    // Bool_t          EF_mbMbts_1_NoAlg;
    // Bool_t          EF_mbMbts_1_eff;
    // Bool_t          EF_mbMbts_2_NoAlg;
    // Bool_t          EF_mbMbts_2_unpaired_iso_NoAlg;
    // Bool_t          EF_mbSpTrk;
    // Bool_t          EF_mbSpTrkVtxMh;
    // Bool_t          EF_mbSpTrkVtxMh_eff;
    // Bool_t          EF_mbSpTrk_empty;
    // Bool_t          EF_mbSpTrk_noiseSup;
    // Bool_t          EF_mbSpTrk_unpaired_iso;
    // Bool_t          EF_mbTE20_eff;
    // Bool_t          EF_mu10;
    // Bool_t          EF_mu10_Jpsimumu;
    // Bool_t          EF_mu10_MSonly;
    // Bool_t          EF_mu10_Upsimumu_tight_FS;
    // Bool_t          EF_mu10i_g10_loose;
    // Bool_t          EF_mu10i_g10_loose_TauMass;
    // Bool_t          EF_mu10i_g10_medium;
    // Bool_t          EF_mu10i_g10_medium_TauMass;
    // Bool_t          EF_mu10i_loose_g12Tvh_loose;
    // Bool_t          EF_mu10i_loose_g12Tvh_loose_TauMass;
    // Bool_t          EF_mu10i_loose_g12Tvh_medium;
    // Bool_t          EF_mu10i_loose_g12Tvh_medium_TauMass;
    // Bool_t          EF_mu11_empty_NoAlg;
    // Bool_t          EF_mu13;
    // Bool_t          EF_mu15;
    // Bool_t          EF_mu18;
    // Bool_t          EF_mu18_2g10_loose;
    // Bool_t          EF_mu18_2g10_medium;
    // Bool_t          EF_mu18_2g15_loose;
    // Bool_t          EF_mu18_IDTrkNoCut_tight;
    // Bool_t          EF_mu18_g20vh_loose;
    // Bool_t          EF_mu18_medium;
    // Bool_t          EF_mu18_tight;
    // Bool_t          EF_mu18_tight_2mu4_EFFS;
    // Bool_t          EF_mu18i4_tight;
    // Bool_t          EF_mu18it_tight;
    // Bool_t          EF_mu20i_tight_g5_loose;
    // Bool_t          EF_mu20i_tight_g5_loose_TauMass;
    // Bool_t          EF_mu20i_tight_g5_medium;
    // Bool_t          EF_mu20i_tight_g5_medium_TauMass;
    // Bool_t          EF_mu20it_tight;
    // Bool_t          EF_mu22_IDTrkNoCut_tight;
    // Bool_t          EF_mu24;
    // Bool_t          EF_mu24_g20vh_loose;
    // Bool_t          EF_mu24_g20vh_medium;
    // Bool_t          EF_mu24_j65_a4tchad;
    // Bool_t          EF_mu24_j65_a4tchad_EFxe40;
    // Bool_t          EF_mu24_j65_a4tchad_EFxe40_tclcw;
    // Bool_t          EF_mu24_j65_a4tchad_EFxe50_tclcw;
    // Bool_t          EF_mu24_j65_a4tchad_EFxe60_tclcw;
    // Bool_t          EF_mu24_medium;
    // Bool_t          EF_mu24_muCombTag_NoEF_tight;
    // Bool_t          EF_mu24_tight;
    // Bool_t          EF_mu24_tight_2j35_a4tchad;
    // Bool_t          EF_mu24_tight_3j35_a4tchad;
    // Bool_t          EF_mu24_tight_4j35_a4tchad;
    // Bool_t          EF_mu24_tight_EFxe40;
    // Bool_t          EF_mu24_tight_L2StarB;
    // Bool_t          EF_mu24_tight_L2StarC;
    // Bool_t          EF_mu24_tight_MG;
    // Bool_t          EF_mu24_tight_MuonEF;
    // Bool_t          EF_mu24_tight_b35_mediumEF_j35_a4tchad;
    // Bool_t          EF_mu24_tight_mu6_EFFS;
    // Bool_t          EF_mu24i_tight;
    // Bool_t          EF_mu24i_tight_MG;
    // Bool_t          EF_mu24i_tight_MuonEF;
    // Bool_t          EF_mu24i_tight_l2muonSA;
    // Bool_t          EF_mu36_tight;
    // Bool_t          EF_mu40_MSonly_barrel_tight;
    // Bool_t          EF_mu40_muCombTag_NoEF;
    // Bool_t          EF_mu40_slow_outOfTime_tight;
    // Bool_t          EF_mu40_slow_tight;
    // Bool_t          EF_mu40_tight;
    // Bool_t          EF_mu4T;
    // Bool_t          EF_mu4T_Trk_Jpsi;
    // Bool_t          EF_mu4T_cosmic;
    // Bool_t          EF_mu4T_j110_a4tchad_L2FS_matched;
    // Bool_t          EF_mu4T_j110_a4tchad_matched;
    // Bool_t          EF_mu4T_j145_a4tchad_L2FS_matched;
    // Bool_t          EF_mu4T_j145_a4tchad_matched;
    // Bool_t          EF_mu4T_j15_a4tchad_matched;
    // Bool_t          EF_mu4T_j15_a4tchad_matchedZ;
    // Bool_t          EF_mu4T_j180_a4tchad_L2FS_matched;
    // Bool_t          EF_mu4T_j180_a4tchad_matched;
    // Bool_t          EF_mu4T_j220_a4tchad_L2FS_matched;
    // Bool_t          EF_mu4T_j220_a4tchad_matched;
    // Bool_t          EF_mu4T_j25_a4tchad_matched;
    // Bool_t          EF_mu4T_j25_a4tchad_matchedZ;
    // Bool_t          EF_mu4T_j280_a4tchad_L2FS_matched;
    // Bool_t          EF_mu4T_j280_a4tchad_matched;
    // Bool_t          EF_mu4T_j35_a4tchad_matched;
    // Bool_t          EF_mu4T_j35_a4tchad_matchedZ;
    // Bool_t          EF_mu4T_j360_a4tchad_L2FS_matched;
    // Bool_t          EF_mu4T_j360_a4tchad_matched;
    // Bool_t          EF_mu4T_j45_a4tchad_L2FS_matched;
    // Bool_t          EF_mu4T_j45_a4tchad_L2FS_matchedZ;
    // Bool_t          EF_mu4T_j45_a4tchad_matched;
    // Bool_t          EF_mu4T_j45_a4tchad_matchedZ;
    // Bool_t          EF_mu4T_j55_a4tchad_L2FS_matched;
    // Bool_t          EF_mu4T_j55_a4tchad_L2FS_matchedZ;
    // Bool_t          EF_mu4T_j55_a4tchad_matched;
    // Bool_t          EF_mu4T_j55_a4tchad_matchedZ;
    // Bool_t          EF_mu4T_j65_a4tchad_L2FS_matched;
    // Bool_t          EF_mu4T_j65_a4tchad_matched;
    // Bool_t          EF_mu4T_j65_a4tchad_xe60_tclcw_loose;
    // Bool_t          EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose;
    // Bool_t          EF_mu4T_j80_a4tchad_L2FS_matched;
    // Bool_t          EF_mu4T_j80_a4tchad_matched;
    // Bool_t          EF_mu4Ti_g20Tvh_loose;
    // Bool_t          EF_mu4Ti_g20Tvh_loose_TauMass;
    // Bool_t          EF_mu4Ti_g20Tvh_medium;
    // Bool_t          EF_mu4Ti_g20Tvh_medium_TauMass;
    // Bool_t          EF_mu4Tmu6_Bmumu;
    // Bool_t          EF_mu4Tmu6_Bmumu_Barrel;
    // Bool_t          EF_mu4Tmu6_Bmumux;
    // Bool_t          EF_mu4Tmu6_Bmumux_Barrel;
    // Bool_t          EF_mu4Tmu6_DiMu;
    // Bool_t          EF_mu4Tmu6_DiMu_Barrel;
    // Bool_t          EF_mu4Tmu6_DiMu_noVtx_noOS;
    // Bool_t          EF_mu4Tmu6_Jpsimumu;
    // Bool_t          EF_mu4Tmu6_Jpsimumu_Barrel;
    // Bool_t          EF_mu4Tmu6_Jpsimumu_IDTrkNoCut;
    // Bool_t          EF_mu4Tmu6_Upsimumu;
    // Bool_t          EF_mu4Tmu6_Upsimumu_Barrel;
    // Bool_t          EF_mu4_L1MU11_MSonly_cosmic;
    // Bool_t          EF_mu4_L1MU11_cosmic;
    // Bool_t          EF_mu4_empty_NoAlg;
    // Bool_t          EF_mu4_firstempty_NoAlg;
    // Bool_t          EF_mu4_unpaired_iso_NoAlg;
    // Bool_t          EF_mu50_MSonly_barrel_tight;
    // Bool_t          EF_mu60_slow_outOfTime_tight1;
    // Bool_t          EF_mu60_slow_tight1;
    // Bool_t          EF_mu6;
    // Bool_t          EF_mu6_Jpsimumu_tight;
    // Bool_t          EF_mu6_MSonly;
    // Bool_t          EF_mu6_Trk_Jpsi_loose;
    // Bool_t          EF_mu6i;
    // Bool_t          EF_mu8;
    // Bool_t          EF_mu8_4j45_a4tchad_L2FS;
    // Bool_t          EF_rd0_empty_NoAlg;
    // Bool_t          EF_rd0_filled_NoAlg;
    // Bool_t          EF_rd0_unpaired_iso_NoAlg;
    // Bool_t          EF_rd1_empty_NoAlg;
    // Bool_t          EF_tau125_IDTrkNoCut;
    // Bool_t          EF_tau125_medium1;
    // Bool_t          EF_tau125_medium1_L2StarA;
    // Bool_t          EF_tau125_medium1_L2StarB;
    // Bool_t          EF_tau125_medium1_L2StarC;
    // Bool_t          EF_tau125_medium1_llh;
    // Bool_t          EF_tau20T_medium1;
    // Bool_t          EF_tau20T_medium1_e15vh_medium1;
    // Bool_t          EF_tau20T_medium1_mu15i;
    // Bool_t          EF_tau20T_medium;
    // Bool_t          EF_tau20T_medium_mu15;
    // Bool_t          EF_tau20Ti_medium1;
    // Bool_t          EF_tau20Ti_medium1_e18vh_medium1;
    // Bool_t          EF_tau20Ti_medium1_llh_e18vh_medium1;
    // Bool_t          EF_tau20Ti_medium;
    // Bool_t          EF_tau20Ti_medium_e18vh_medium1;
    // Bool_t          EF_tau20Ti_tight1;
    // Bool_t          EF_tau20Ti_tight1_llh;
    // Bool_t          EF_tau20_medium1;
    // Bool_t          EF_tau20_medium1_llh;
    // Bool_t          EF_tau20_medium1_llh_mu15;
    // Bool_t          EF_tau20_medium1_mu15;
    // Bool_t          EF_tau20_medium1_mu15i;
    // Bool_t          EF_tau20_medium1_mu18;
    // Bool_t          EF_tau20_medium;
    // Bool_t          EF_tau20_medium_llh;
    // Bool_t          EF_tau20_medium_mu15;
    // Bool_t          EF_tau29T_medium1;
    // Bool_t          EF_tau29T_medium1_tau20T_medium1;
    // Bool_t          EF_tau29T_medium1_xe40_tight;
    // Bool_t          EF_tau29T_medium1_xe45_tight;
    // Bool_t          EF_tau29T_medium;
    // Bool_t          EF_tau29T_medium_xe40_tight;
    // Bool_t          EF_tau29T_medium_xe45_tight;
    // Bool_t          EF_tau29T_tight1;
    // Bool_t          EF_tau29T_tight1_llh;
    // Bool_t          EF_tau29Ti_medium1;
    // Bool_t          EF_tau29Ti_medium1_llh_tau20Ti_medium1_llh;
    // Bool_t          EF_tau29Ti_medium1_llh_xe40_tight;
    // Bool_t          EF_tau29Ti_medium1_llh_xe45_tight;
    // Bool_t          EF_tau29Ti_medium1_tau20Ti_medium1;
    // Bool_t          EF_tau29Ti_medium1_xe40_tight;
    // Bool_t          EF_tau29Ti_medium1_xe45_tight;
    // Bool_t          EF_tau29Ti_medium1_xe55_tclcw;
    // Bool_t          EF_tau29Ti_medium1_xe55_tclcw_tight;
    // Bool_t          EF_tau29Ti_medium_xe40_tight;
    // Bool_t          EF_tau29Ti_medium_xe45_tight;
    // Bool_t          EF_tau29Ti_tight1;
    // Bool_t          EF_tau29Ti_tight1_llh;
    // Bool_t          EF_tau29Ti_tight1_llh_tau20Ti_tight1_llh;
    // Bool_t          EF_tau29Ti_tight1_tau20Ti_tight1;
    // Bool_t          EF_tau29_IDTrkNoCut;
    // Bool_t          EF_tau29_medium1;
    // Bool_t          EF_tau29_medium1_llh;
    // Bool_t          EF_tau29_medium;
    // Bool_t          EF_tau29_medium_2stTest;
    // Bool_t          EF_tau29_medium_L2StarA;
    // Bool_t          EF_tau29_medium_L2StarB;
    // Bool_t          EF_tau29_medium_L2StarC;
    // Bool_t          EF_tau29_medium_llh;
    // Bool_t          EF_tau29i_medium1;
    // Bool_t          EF_tau29i_medium;
    // Bool_t          EF_tau38T_medium1;
    // Bool_t          EF_tau38T_medium1_e18vh_medium1;
    // Bool_t          EF_tau38T_medium1_llh_e18vh_medium1;
    // Bool_t          EF_tau38T_medium1_xe40_tight;
    // Bool_t          EF_tau38T_medium1_xe45_tight;
    // Bool_t          EF_tau38T_medium1_xe55_tclcw_tight;
    // Bool_t          EF_tau38T_medium;
    // Bool_t          EF_tau38T_medium_e18vh_medium1;
    // Bool_t          EF_tau50_medium1_e18vh_medium1;
    // Bool_t          EF_tau50_medium;
    // Bool_t          EF_tau50_medium_e15vh_medium1;
    // Bool_t          EF_tauNoCut;
    // Bool_t          EF_tauNoCut_L1TAU40;
    // Bool_t          EF_tauNoCut_cosmic;
    // Bool_t          EF_te1000;
    // Bool_t          EF_te1400;
    // Bool_t          EF_te1600;
    // Bool_t          EF_te600;
    // Bool_t          EF_xe100;
    // Bool_t          EF_xe100T_tclcw;
    // Bool_t          EF_xe100T_tclcw_loose;
    // Bool_t          EF_xe100_tclcw;
    // Bool_t          EF_xe100_tclcw_loose;
    // Bool_t          EF_xe100_tclcw_veryloose;
    // Bool_t          EF_xe100_tclcw_verytight;
    // Bool_t          EF_xe100_tight;
    // Bool_t          EF_xe110;
    // Bool_t          EF_xe30;
    // Bool_t          EF_xe30_tclcw;
    // Bool_t          EF_xe40;
    // Bool_t          EF_xe50;
    // Bool_t          EF_xe55_LArNoiseBurst;
    // Bool_t          EF_xe55_tclcw;
    // Bool_t          EF_xe60;
    // Bool_t          EF_xe60T;
    // Bool_t          EF_xe60_tclcw;
    // Bool_t          EF_xe60_tclcw_loose;
    // Bool_t          EF_xe70;
    // Bool_t          EF_xe70_tclcw_loose;
    // Bool_t          EF_xe70_tclcw_veryloose;
    // Bool_t          EF_xe70_tight;
    // Bool_t          EF_xe70_tight_tclcw;
    // Bool_t          EF_xe75_tclcw;
    // Bool_t          EF_xe80;
    // Bool_t          EF_xe80T;
    // Bool_t          EF_xe80T_loose;
    // Bool_t          EF_xe80T_tclcw;
    // Bool_t          EF_xe80T_tclcw_loose;
    // Bool_t          EF_xe80_tclcw;
    // Bool_t          EF_xe80_tclcw_loose;
    // Bool_t          EF_xe80_tclcw_tight;
    // Bool_t          EF_xe80_tclcw_verytight;
    // Bool_t          EF_xe80_tight;
    // Bool_t          EF_xe90;
    // Bool_t          EF_xe90_tclcw;
    // Bool_t          EF_xe90_tclcw_tight;
    // Bool_t          EF_xe90_tclcw_veryloose;
    // Bool_t          EF_xe90_tclcw_verytight;
    // Bool_t          EF_xe90_tight;
    // Bool_t          EF_xe_NoCut_FEB_allL1;
    // Bool_t          EF_xe_NoCut_allL1;
    // Bool_t          EF_xe_NoCut_tclcw_allL1;
    // Bool_t          EF_xs100;
    // Bool_t          EF_xs120;
    // Bool_t          EF_xs30;
    // Bool_t          EF_xs45;
    // Bool_t          EF_xs60;
    // Bool_t          EF_xs75;
    // Bool_t          EF_zerobias_NoAlg;
    // Bool_t          EF_zerobias_Overlay_NoAlg;
    // Bool_t          isCalibration;
    // Bool_t          isSimulation;
    // Bool_t          isTestBeam;
    // Bool_t          trig_EF_truncated;
    // Char_t          trig_bgCode;
    // Float_t         Eventshape_rhoKt3EM;
    // Float_t         Eventshape_rhoKt3LC;
    // Float_t         Eventshape_rhoKt4EM;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_etx;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_ety;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_sumet;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_etx;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_ety;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_sumet;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetArea_etx;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetArea_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetArea_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetArea_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetArea_ety;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetArea_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetArea_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetArea_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetArea_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetArea_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetArea_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetArea_sumet;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetArea_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetArea_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_JetArea_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_STVF_etx;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_STVF_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_STVF_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_STVF_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_STVF_ety;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_STVF_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_STVF_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_STVF_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_STVF_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_STVF_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_STVF_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_STVF_sumet;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_STVF_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_STVF_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_STVF_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_etx;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_ety;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_sumet;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_Eflow_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_CellOut_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_CellOut_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_CellOut_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_MuonBoy_etx;
    // Float_t         MET_Egamma10NoTau_MuonBoy_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_MuonBoy_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_MuonBoy_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_MuonBoy_ety;
    // Float_t         MET_Egamma10NoTau_MuonBoy_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_MuonBoy_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_MuonBoy_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_MuonBoy_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_MuonBoy_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_MuonBoy_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_MuonBoy_sumet;
    // Float_t         MET_Egamma10NoTau_MuonBoy_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_MuonBoy_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_MuonBoy_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Muid_etx;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Muid_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Muid_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Muid_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Muid_ety;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Muid_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Muid_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Muid_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Muid_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Muid_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Muid_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Muid_sumet;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Muid_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Muid_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Muid_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Staco_etx;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Staco_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Staco_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Staco_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Staco_ety;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Staco_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Staco_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Staco_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Staco_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Staco_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Staco_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Staco_sumet;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Staco_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Staco_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_Isol_Staco_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Muid_etx;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Muid_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Muid_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Muid_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Muid_ety;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Muid_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Muid_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Muid_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Muid_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Muid_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Muid_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Muid_sumet;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Muid_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Muid_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Muid_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Staco_etx;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Staco_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Staco_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Staco_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Staco_ety;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Staco_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Staco_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Staco_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Staco_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Staco_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Staco_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Staco_sumet;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Staco_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Staco_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_NonIsol_Staco_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Muid_etx;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Muid_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Muid_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Muid_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Muid_ety;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Muid_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Muid_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Muid_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Muid_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Muid_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Muid_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Muid_sumet;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Muid_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Muid_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Muid_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Staco_etx;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Staco_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Staco_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Staco_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Staco_ety;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Staco_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Staco_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Staco_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Staco_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Staco_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Staco_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Staco_sumet;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Staco_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Staco_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Muon_Total_Staco_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefEle_etx;
    // Float_t         MET_Egamma10NoTau_RefEle_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefEle_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefEle_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefEle_ety;
    // Float_t         MET_Egamma10NoTau_RefEle_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefEle_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefEle_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefEle_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefEle_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefEle_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefEle_sumet;
    // Float_t         MET_Egamma10NoTau_RefEle_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefEle_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefEle_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefFinal_STVF_etx;
    // Float_t         MET_Egamma10NoTau_RefFinal_STVF_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefFinal_STVF_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefFinal_STVF_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefFinal_STVF_ety;
    // Float_t         MET_Egamma10NoTau_RefFinal_STVF_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefFinal_STVF_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefFinal_STVF_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefFinal_STVF_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefFinal_STVF_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefFinal_STVF_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefFinal_STVF_sumet;
    // Float_t         MET_Egamma10NoTau_RefFinal_STVF_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefFinal_STVF_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefFinal_STVF_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefFinal_etx;
    // Float_t         MET_Egamma10NoTau_RefFinal_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefFinal_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefFinal_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefFinal_ety;
    // Float_t         MET_Egamma10NoTau_RefFinal_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefFinal_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefFinal_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefFinal_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefFinal_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefFinal_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefFinal_sumet;
    // Float_t         MET_Egamma10NoTau_RefFinal_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefFinal_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefFinal_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefGamma_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefGamma_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefGamma_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefGamma_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefGamma_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefGamma_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefGamma_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefGamma_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefGamma_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefGamma_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefGamma_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefGamma_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefJet_JVFCut_etx;
    // Float_t         MET_Egamma10NoTau_RefJet_JVFCut_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefJet_JVFCut_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefJet_JVFCut_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefJet_JVFCut_ety;
    // Float_t         MET_Egamma10NoTau_RefJet_JVFCut_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefJet_JVFCut_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefJet_JVFCut_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefJet_JVFCut_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefJet_JVFCut_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefJet_JVFCut_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefJet_JVFCut_sumet;
    // Float_t         MET_Egamma10NoTau_RefJet_JVFCut_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefJet_JVFCut_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefJet_JVFCut_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefJet_JVF_etx;
    // Float_t         MET_Egamma10NoTau_RefJet_JVF_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefJet_JVF_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefJet_JVF_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefJet_JVF_ety;
    // Float_t         MET_Egamma10NoTau_RefJet_JVF_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefJet_JVF_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefJet_JVF_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefJet_JVF_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefJet_JVF_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefJet_JVF_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefJet_JVF_sumet;
    // Float_t         MET_Egamma10NoTau_RefJet_JVF_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefJet_JVF_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefJet_JVF_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefJet_etx;
    // Float_t         MET_Egamma10NoTau_RefJet_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefJet_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefJet_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefJet_ety;
    // Float_t         MET_Egamma10NoTau_RefJet_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefJet_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefJet_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefJet_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefJet_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefJet_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefJet_sumet;
    // Float_t         MET_Egamma10NoTau_RefJet_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefJet_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefJet_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Muid_etx;
    // Float_t         MET_Egamma10NoTau_RefMuon_Muid_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Muid_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Muid_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Muid_ety;
    // Float_t         MET_Egamma10NoTau_RefMuon_Muid_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Muid_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Muid_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Muid_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Muid_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Muid_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Muid_sumet;
    // Float_t         MET_Egamma10NoTau_RefMuon_Muid_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Muid_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Muid_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Staco_etx;
    // Float_t         MET_Egamma10NoTau_RefMuon_Staco_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Staco_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Staco_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Staco_ety;
    // Float_t         MET_Egamma10NoTau_RefMuon_Staco_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Staco_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Staco_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Staco_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Staco_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Staco_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Staco_sumet;
    // Float_t         MET_Egamma10NoTau_RefMuon_Staco_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Staco_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Staco_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Muid_etx;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Muid_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Muid_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Muid_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Muid_ety;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Muid_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Muid_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Muid_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Muid_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Muid_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Muid_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Muid_sumet;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Muid_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Muid_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Muid_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Staco_etx;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Staco_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Staco_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Staco_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Staco_ety;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Staco_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Staco_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Staco_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Staco_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Staco_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Staco_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Staco_sumet;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Staco_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Staco_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_Staco_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_etx;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_ety;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_sumet;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_Track_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_etx;
    // Float_t         MET_Egamma10NoTau_RefMuon_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_ety;
    // Float_t         MET_Egamma10NoTau_RefMuon_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_sumet;
    // Float_t         MET_Egamma10NoTau_RefMuon_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_RefMuon_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_RefMuon_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_SoftJets_etx;
    // Float_t         MET_Egamma10NoTau_SoftJets_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_SoftJets_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_SoftJets_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_SoftJets_ety;
    // Float_t         MET_Egamma10NoTau_SoftJets_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_SoftJets_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_SoftJets_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_SoftJets_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_SoftJets_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_SoftJets_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_SoftJets_sumet;
    // Float_t         MET_Egamma10NoTau_SoftJets_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_SoftJets_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_SoftJets_sumet_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Track_etx;
    // Float_t         MET_Egamma10NoTau_Track_etx_CentralReg;
    // Float_t         MET_Egamma10NoTau_Track_etx_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Track_etx_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Track_ety;
    // Float_t         MET_Egamma10NoTau_Track_ety_CentralReg;
    // Float_t         MET_Egamma10NoTau_Track_ety_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Track_ety_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Track_phi_CentralReg;
    // Float_t         MET_Egamma10NoTau_Track_phi_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Track_phi_ForwardReg;
    // Float_t         MET_Egamma10NoTau_Track_sumet;
    // Float_t         MET_Egamma10NoTau_Track_sumet_CentralReg;
    // Float_t         MET_Egamma10NoTau_Track_sumet_EndcapRegion;
    // Float_t         MET_Egamma10NoTau_Track_sumet_ForwardReg;
    // Float_t         MET_Track_etx;
    // Float_t         MET_Track_etx_CentralReg;
    // Float_t         MET_Track_etx_EndcapRegion;
    // Float_t         MET_Track_etx_ForwardReg;
    // Float_t         MET_Track_ety;
    // Float_t         MET_Track_ety_CentralReg;
    // Float_t         MET_Track_ety_EndcapRegion;
    // Float_t         MET_Track_ety_ForwardReg;
    // Float_t         MET_Track_phi_CentralReg;
    // Float_t         MET_Track_phi_EndcapRegion;
    // Float_t         MET_Track_phi_ForwardReg;
    // Float_t         MET_Track_sumet;
    // Float_t         MET_Track_sumet_CentralReg;
    // Float_t         MET_Track_sumet_EndcapRegion;
    // Float_t         MET_Track_sumet_ForwardReg;
    // Float_t         MET_Truth_IntCentral_etx;
    // Float_t         MET_Truth_IntCentral_ety;
    // Float_t         MET_Truth_IntCentral_sumet;
    // Float_t         MET_Truth_IntFwd_etx;
    // Float_t         MET_Truth_IntFwd_ety;
    // Float_t         MET_Truth_IntFwd_sumet;
    // Float_t         MET_Truth_IntMuons_etx;
    // Float_t         MET_Truth_IntMuons_ety;
    // Float_t         MET_Truth_IntMuons_sumet;
    // Float_t         MET_Truth_IntOutCover_etx;
    // Float_t         MET_Truth_IntOutCover_ety;
    // Float_t         MET_Truth_IntOutCover_sumet;
    // Float_t         MET_Truth_Int_etx;
    // Float_t         MET_Truth_Int_ety;
    // Float_t         MET_Truth_Int_sumet;
    // Float_t         MET_Truth_NonInt_etx;
    // Float_t         MET_Truth_NonInt_ety;
    // Float_t         MET_Truth_NonInt_sumet;
    // Float_t         actualIntPerXing;
    // Float_t         trig_EF_feb_met_MEx;
    // Float_t         trig_EF_feb_met_MEy;
    // Float_t         trig_EF_feb_met_MEz;
    // Float_t         trig_EF_feb_met_sumE;
    // Float_t         trig_EF_feb_met_sumEt;
    // Float_t         trig_EF_jetetsum_MEx;
    // Float_t         trig_EF_jetetsum_MEy;
    // Float_t         trig_EF_jetetsum_MEz;
    // Float_t         trig_EF_jetetsum_sumE;
    // Float_t         trig_EF_jetetsum_sumEt;
    // Float_t         trig_EF_met_MEx;
    // Float_t         trig_EF_met_MEy;
    // Float_t         trig_EF_met_MEz;
    // Float_t         trig_EF_met_sumE;
    // Float_t         trig_EF_met_sumEt;
    // Float_t         trig_EF_topocl_met_MEx;
    // Float_t         trig_EF_topocl_met_MEy;
    // Float_t         trig_EF_topocl_met_MEz;
    // Float_t         trig_EF_topocl_met_sumE;
    // Float_t         trig_EF_topocl_met_sumEt;
    // Int_t           SUSY_Spart1_pdgId;
    // Int_t           SUSY_Spart2_pdgId;
    // Int_t           bb_cl_n;
    // Int_t           bb_decision;
    // Int_t           bb_direction;
    // Int_t           bb_jet_n;
    // Int_t           bb_numClusterShape;
    // Int_t           bb_numMatched;
    // Int_t           bb_numNoTimeLoose;
    // Int_t           bb_numNoTimeMedium;
    // Int_t           bb_numNoTimeTight;
    // Int_t           bb_numOneSidedLoose;
    // Int_t           bb_numOneSidedMedium;
    // Int_t           bb_numOneSidedTight;
    // Int_t           bb_numSegment;
    // Int_t           bb_numSegmentAC;
    // Int_t           bb_numSegmentACNoTime;
    // Int_t           bb_numSegmentEarly;
    // Int_t           bb_numTwoSided;
    // Int_t           bb_numTwoSidedNoTime;
    // Int_t           el_MET_Egamma10NoTau_n;
    // Int_t           el_MET_n;
    // Int_t           jet_AntiKt4LCTopo_MET_Egamma10NoTau_n;
    // Int_t           jet_AntiKt4LCTopo_MET_n;
    // Int_t           jet_AntiKt4TrackZ_n;
    // Int_t           jet_AntiKt4TruthJets_n;
    // Int_t           jet_AntiKt6LCTopo_n;
    // Int_t           jet_AntiKt6TopoEM_n;
    // Int_t           mcVx_n;
    // Int_t           mcevt_n;
    // Int_t           mu_staco_MET_Egamma10NoTau_n;
    // Int_t           mu_staco_MET_n;
    // Int_t           muonTruth_n;
    // Int_t           ph_MET_Egamma10NoTau_n;
    // Int_t           ph_MET_n;
    // Int_t           ph_n;
    // Int_t           tau_MET_n;
    // Int_t           top_hfor_type;
    // Int_t           trig_EF_bjet_n;
    // Int_t           trig_EF_bjet_vertex_n;
    // Int_t           trig_EF_el_n;
    // Int_t           trig_EF_emcl_n;
    // Int_t           trig_EF_emcl_slw_n;
    // Int_t           trig_EF_feb_met_flag;
    // Int_t           trig_EF_jet_n;
    // Int_t           trig_EF_jetetsum_flag;
    // Int_t           trig_EF_met_flag;
    // Int_t           trig_EF_ph_n;
    // Int_t           trig_EF_pv_n;
    // Int_t           trig_EF_tau_n;
    // Int_t           trig_EF_topocl_met_flag;
    // Int_t           trig_EF_trigmuonef_n;
    // Int_t           trig_EF_trigmuonefisolation_n;
    // Int_t           trig_Nav_n;
    // Int_t           trig_roidescriptor_forID_n;
    // Int_t           trk_n;
    // Int_t           trueTau_n;
    // UInt_t          bcid;
    // UInt_t          bunch_configID;
    // UInt_t          coreError;
    // UInt_t          detmask0;
    // UInt_t          detmask1;
    // UInt_t          fwdError;
    // UInt_t          fwdFlags;
    // UInt_t          larFlags;
    // UInt_t          mc_event_number;
    // UInt_t          muonError;
    // UInt_t          muonFlags;
    // UInt_t          pixelError;
    // UInt_t          pixelFlags;
    // UInt_t          sctError;
    // UInt_t          sctFlags;
    // UInt_t          tileFlags;
    // UInt_t          timestamp;
    // UInt_t          timestamp_ns;
    // UInt_t          trig_DB_HLTPSK;
    // UInt_t          trig_DB_L1PSK;
    // UInt_t          trig_DB_SMK;
    // UInt_t          trtError;
    // UInt_t          trtFlags;
    // std::vector<double>  *mcevt_alphaQCD;
    // std::vector<double>  *mcevt_alphaQED;
    // std::vector<double>  *mcevt_event_scale;
    // std::vector<double>  *mcevt_pdf1;
    // std::vector<double>  *mcevt_pdf2;
    // std::vector<double>  *mcevt_pdf_scale;
    // std::vector<double>  *mcevt_pdf_x1;
    // std::vector<double>  *mcevt_pdf_x2;
    // std::vector<double>  *mu_staco_caloLRLikelihood;
    // std::vector<double>  *tau_jet_flavor_weight;
    // std::vector<double>  *tau_jet_flavor_weight_IP1D;
    // std::vector<double>  *tau_jet_flavor_weight_IP2D;
    // std::vector<double>  *tau_jet_flavor_weight_IP3D;
    // std::vector<double>  *tau_jet_flavor_weight_IP3DSV1;
    // std::vector<double>  *tau_jet_flavor_weight_JetFitterCOMB;
    // std::vector<double>  *tau_jet_flavor_weight_JetFitterCOMBNN;
    // std::vector<double>  *tau_jet_flavor_weight_JetFitterTag;
    // std::vector<double>  *tau_jet_flavor_weight_JetFitterTagNN;
    // std::vector<double>  *tau_jet_flavor_weight_JetProb;
    // std::vector<double>  *tau_jet_flavor_weight_SV0;
    // std::vector<double>  *tau_jet_flavor_weight_SV1;
    // std::vector<double>  *tau_jet_flavor_weight_SV2;
    // std::vector<double>  *tau_jet_flavor_weight_SoftElectronTag;
    // std::vector<double>  *tau_jet_flavor_weight_SoftMuonTag;
    // std::vector<double>  *tau_jet_flavor_weight_TrackCounting2D;
    // std::vector<double>  *tau_pantau_EflowAngleChargedAxisNeutralAxis;
    // std::vector<double>  *tau_pantau_EflowAngleJetAxisLeadingChargedQualified;
    // std::vector<double>  *tau_pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified;
    // std::vector<double>  *tau_pantau_EflowChargedSumEt;
    // std::vector<double>  *tau_pantau_EflowEtLeadingChrgQualifiedOverTotalEt;
    // std::vector<double>  *tau_pantau_EflowInvariantMassAll;
    // std::vector<double>  *tau_pantau_EflowJetMomentDRAll;
    // std::vector<double>  *tau_pantau_EflowJetMomentDRChrg;
    // std::vector<double>  *tau_pantau_EflowJetMomentDREMNeut;
    // std::vector<double>  *tau_pantau_EflowJetMomentDRHADNeut;
    // std::vector<double>  *tau_pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents;
    // std::vector<double>  *tau_pantau_EflowStdDevEtToSumEt;
    // std::vector<double>  *tau_pantau_EflowSumEAll;
    // std::vector<double>  *tau_pantau_EtIn01OverEtIn02InvSigm;
    // std::vector<double>  *tau_pantau_EtIn01OverEtIn04;
    // std::vector<double>  *tau_pantau_EtIn01OverEtIn04InvSigm;
    // std::vector<double>  *tau_pantau_EtIn02To04OverTotalEtInvSigm;
    // std::vector<double>  *tau_pantau_JetSphericity;
    // std::vector<double>  *tau_pantau_PanTauScore;
    // std::vector<double>  *tau_pantau_TransImpactParamSignfTrack1;
    // std::vector<double>  *trig_EF_tau_seedCalo_EMRadius;
    // std::vector<double>  *trig_EF_tau_seedCalo_centFrac;
    // std::vector<double>  *trig_EF_tau_seedCalo_etEMAtEMScale;
    // std::vector<double>  *trig_EF_tau_seedCalo_etEMCalib;
    // std::vector<double>  *trig_EF_tau_seedCalo_etHadAtEMScale;
    // std::vector<double>  *trig_EF_tau_seedCalo_etHadCalib;
    // std::vector<double>  *trig_EF_tau_seedCalo_eta;
    // std::vector<double>  *trig_EF_tau_seedCalo_hadRadius;
    // std::vector<double>  *trig_EF_tau_seedCalo_isolFrac;
    // std::vector<double>  *trig_EF_tau_seedCalo_phi;
    // std::vector<float>   *bb_cl_E_em;
    // std::vector<float>   *bb_cl_E_had;
    // std::vector<float>   *bb_cl_cellmaxfrac;
    // std::vector<float>   *bb_cl_centerlambda;
    // std::vector<float>   *bb_cl_centermag;
    // std::vector<float>   *bb_cl_deltaPhi;
    // std::vector<float>   *bb_cl_deltaTheta;
    // std::vector<float>   *bb_cl_drdz;
    // std::vector<float>   *bb_cl_eta;
    // std::vector<float>   *bb_cl_firstEdens;
    // std::vector<float>   *bb_cl_lateral;
    // std::vector<float>   *bb_cl_longitudinal;
    // std::vector<float>   *bb_cl_phi;
    // std::vector<float>   *bb_cl_pt;
    // std::vector<float>   *bb_cl_secondR;
    // std::vector<float>   *bb_cl_secondlambda;
    // std::vector<float>   *bb_cl_time;
    // std::vector<float>   *el_E233;
    // std::vector<float>   *el_E237;
    // std::vector<float>   *el_E277;
    // std::vector<float>   *el_E;
    // std::vector<float>   *el_ED_Njets;
    // std::vector<float>   *el_ED_median;
    // std::vector<float>   *el_ED_sigma;
    // std::vector<float>   *el_EF_dr;
    // std::vector<float>   *el_Emax2;
    // std::vector<float>   *el_Emins1;
    // std::vector<float>   *el_Es0;
    // std::vector<float>   *el_Es1;
    // std::vector<float>   *el_Es2;
    // std::vector<float>   *el_Es3;
    // std::vector<float>   *el_Et;
    // std::vector<float>   *el_Etcone15;
    // std::vector<float>   *el_Etcone20;
    // std::vector<float>   *el_Etcone25;
    // std::vector<float>   *el_Etcone30;
    // std::vector<float>   *el_Etcone35;
    // std::vector<float>   *el_Etcone40;
    // std::vector<float>   *el_Etcone40_ED_corrected;
    // std::vector<float>   *el_Etcone40_corrected;
    // std::vector<float>   *el_Etcone45;
    // std::vector<float>   *el_Ethad1;
    // std::vector<float>   *el_Ethad;
    // std::vector<float>   *el_Rconv;
    // std::vector<float>   *el_TRTHighTHitsRatio;
    // std::vector<float>   *el_TRTHighTOutliersRatio;
    // std::vector<float>   *el_cellmaxfrac;
    // std::vector<float>   *el_centerlambda;
    // std::vector<float>   *el_cl_time;
    // std::vector<float>   *el_convanglematch;
    // std::vector<float>   *el_convtrackmatch;
    // std::vector<float>   *el_convvtxchi2;
    // std::vector<float>   *el_convvtxx;
    // std::vector<float>   *el_convvtxy;
    // std::vector<float>   *el_convvtxz;
    // std::vector<float>   *el_deltaEs;
    // std::vector<float>   *el_deltaPhiFromLast;
    // std::vector<float>   *el_deltaPhiRot;
    // std::vector<float>   *el_deltaeta1;
    // std::vector<float>   *el_deltaeta2;
    // std::vector<float>   *el_deltaphi2;
    // std::vector<float>   *el_deltaphiRescaled;
    // std::vector<float>   *el_depth;
    // std::vector<float>   *el_emaxs1;
    // std::vector<float>   *el_errz;
    std::vector<float>   *el_eta;
    // std::vector<float>   *el_etaSampling1;
    // std::vector<float>   *el_etacorrmag;
    // std::vector<float>   *el_etap;
    // std::vector<float>   *el_etas0;
    // std::vector<float>   *el_etas1;
    // std::vector<float>   *el_etas2;
    // std::vector<float>   *el_etas3;
    // std::vector<float>   *el_expectHitInBLayer;
    // std::vector<float>   *el_f1;
    // std::vector<float>   *el_f1core;
    // std::vector<float>   *el_f3;
    // std::vector<float>   *el_f3core;
    // std::vector<float>   *el_firstEdens;
    // std::vector<float>   *el_fside;
    // std::vector<float>   *el_lateral;
    // std::vector<float>   *el_longitudinal;
    // std::vector<float>   *el_m;
    // std::vector<float>   *el_massPixeldEdx;
    // std::vector<float>   *el_maxEcell_energy;
    // std::vector<float>   *el_maxEcell_time;
    // std::vector<float>   *el_maxEcell_x;
    // std::vector<float>   *el_maxEcell_y;
    // std::vector<float>   *el_maxEcell_z;
    // std::vector<float>   *el_nucone20;
    // std::vector<float>   *el_nucone20_zpv05;
    // std::vector<float>   *el_nucone30;
    // std::vector<float>   *el_nucone30_zpv05;
    // std::vector<float>   *el_nucone40;
    // std::vector<float>   *el_nucone40_zpv05;
    std::vector<float>   *el_phi;
    // std::vector<float>   *el_phis0;
    // std::vector<float>   *el_phis1;
    // std::vector<float>   *el_phis2;
    // std::vector<float>   *el_phis3;
    // std::vector<float>   *el_pixeldEdx;
    // std::vector<float>   *el_pos7;
    // std::vector<float>   *el_pt1conv;
    // std::vector<float>   *el_pt2conv;
    // std::vector<float>   *el_pt;
    // std::vector<float>   *el_ptcone20;
    // std::vector<float>   *el_ptcone20_trk500MeV;
    // std::vector<float>   *el_ptcone20_zpv05;
    // std::vector<float>   *el_ptcone30_trk500MeV;
    // std::vector<float>   *el_ptcone30_zpv05;
    // std::vector<float>   *el_ptcone40;
    // std::vector<float>   *el_ptcone40_trk500MeV;
    // std::vector<float>   *el_ptcone40_zpv05;
    // std::vector<float>   *el_ptconv;
    // std::vector<float>   *el_px;
    // std::vector<float>   *el_py;
    // std::vector<float>   *el_pz;
    // std::vector<float>   *el_pzconv;
    // std::vector<float>   *el_reta;
    // std::vector<float>   *el_rphi;
    // std::vector<float>   *el_rphiallcalo;
    // std::vector<float>   *el_secondR;
    // std::vector<float>   *el_secondlambda;
    // std::vector<float>   *el_topoEtcone20;
    // std::vector<float>   *el_topoEtcone20_corrected;
    // std::vector<float>   *el_topoEtcone30;
    // std::vector<float>   *el_topoEtcone40;
    // std::vector<float>   *el_topoEtcone40_corrected;
    // std::vector<float>   *el_trackIPEstimate_d0_biasedpvunbiased;
    // std::vector<float>   *el_trackIPEstimate_sigd0_biasedpvunbiased;
    // std::vector<float>   *el_trackIPEstimate_sigz0_biasedpvunbiased;
    // std::vector<float>   *el_trackIPEstimate_sigz0_unbiasedpvunbiased;
    // std::vector<float>   *el_trackIPEstimate_z0_biasedpvunbiased;
    // std::vector<float>   *el_trackd0;
    // std::vector<float>   *el_trackd0_physics;
    // std::vector<float>   *el_trackd0pv;
    // std::vector<float>   *el_trackpt;
    // std::vector<float>   *el_trackqoverp;
    // std::vector<float>   *el_tracksigd0pv;
    // std::vector<float>   *el_tracksigz0pv;
    // std::vector<float>   *el_tracktheta;
    // std::vector<float>   *el_trackz0;
    // std::vector<float>   *el_trackz0pv;
    // std::vector<float>   *el_truth_E;
    // std::vector<float>   *el_truth_eta;
    // std::vector<float>   *el_truth_phi;
    // std::vector<float>   *el_truth_pt;
    // std::vector<float>   *el_vertweight;
    // std::vector<float>   *el_weta2;
    // std::vector<float>   *el_ws3;
    // std::vector<float>   *el_wstot;
    // std::vector<float>   *el_zconv;
    // std::vector<float>   *el_zvertex;
    // std::vector<float>   *jet_AntiKt4LCTopo_ActiveArea;
    // std::vector<float>   *jet_AntiKt4LCTopo_BAD_CELLS_CORR_E;
    std::vector<float>   *jet_AntiKt4LCTopo_BCH_CORR_CELL;
    // std::vector<float>   *jet_AntiKt4LCTopo_BCH_CORR_DOTX;
    // std::vector<float>   *jet_AntiKt4LCTopo_BCH_CORR_JET_FORCELL;
    // std::vector<float>   *jet_AntiKt4LCTopo_E;
    // std::vector<float>   *jet_AntiKt4LCTopo_EMJES;
    // std::vector<float>   *jet_AntiKt4LCTopo_EMJES_EtaCorr;
    // std::vector<float>   *jet_AntiKt4LCTopo_EMJESnooffset;
    // std::vector<float>   *jet_AntiKt4LCTopo_ENG_BAD_CELLS;
    // std::vector<float>   *jet_AntiKt4LCTopo_EtaOrigin;
    // std::vector<float>   *jet_AntiKt4LCTopo_GSCFactorF;
    // std::vector<float>   *jet_AntiKt4LCTopo_LCJES;
    // std::vector<float>   *jet_AntiKt4LCTopo_LCJES_EtaCorr;
    // std::vector<float>   *jet_AntiKt4LCTopo_MOrigin;
    // std::vector<float>   *jet_AntiKt4LCTopo_N_BAD_CELLS;
    // std::vector<float>   *jet_AntiKt4LCTopo_N_BAD_CELLS_CORR;
    // std::vector<float>   *jet_AntiKt4LCTopo_NumTowers;
    // std::vector<float>   *jet_AntiKt4LCTopo_Offset;
    // std::vector<float>   *jet_AntiKt4LCTopo_OriginIndex;
    // std::vector<float>   *jet_AntiKt4LCTopo_PhiOrigin;
    // std::vector<float>   *jet_AntiKt4LCTopo_SmearingFactor;
    // std::vector<float>   *jet_AntiKt4LCTopo_Timing;
    // std::vector<float>   *jet_AntiKt4LCTopo_TruthMF;
    // std::vector<float>   *jet_AntiKt4LCTopo_TruthMFindex;
    // std::vector<float>   *jet_AntiKt4LCTopo_WIDTH;
    // std::vector<float>   *jet_AntiKt4LCTopo_WidthFraction;
    // std::vector<float>   *jet_AntiKt4LCTopo_constscale_pt;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_EMB1;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_EMB2;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_EMB3;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_EME1;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_EME2;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_EME3;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_FCAL0;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_FCAL1;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_FCAL2;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_HEC0;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_HEC1;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_HEC2;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_HEC3;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_PreSamplerB;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_PreSamplerE;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_TileBar0;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_TileBar1;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_TileBar2;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_TileExt0;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_TileExt1;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_TileExt2;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_TileGap1;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_TileGap2;
    // std::vector<float>   *jet_AntiKt4LCTopo_e_TileGap3;
    // std::vector<float>   *jet_AntiKt4LCTopo_emscale_E;
    // std::vector<float>   *jet_AntiKt4LCTopo_emscale_eta;
    // std::vector<float>   *jet_AntiKt4LCTopo_emscale_m;
    // std::vector<float>   *jet_AntiKt4LCTopo_emscale_phi;
    // std::vector<float>   *jet_AntiKt4LCTopo_emscale_pt;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_ip2d_pb;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_ip2d_pu;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_ip3d_pb;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_ip3d_pc;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_ip3d_pu;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_jfit_deltaEta;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_jfit_deltaPhi;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_jfit_efrc;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_jfit_mass;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_jfit_pb;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_jfit_pc;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_jfit_pu;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_jfit_sig3d;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_jfitc_pb;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_jfitc_pc;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_jfitc_pu;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_jfitcomb_pb;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_jfitcomb_pc;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_jfitcomb_pu;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_sv0p_chi2;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_sv0p_cov_xy;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_sv0p_cov_xz;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_sv0p_cov_yz;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_sv0p_efrc;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_sv0p_err_x;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_sv0p_err_y;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_sv0p_err_z;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_sv0p_mass;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_sv0p_x;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_sv0p_y;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_sv0p_z;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_sv1_pb;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_sv1_pc;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_sv1_pu;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_sv2_pb;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_sv2_pu;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_svp_chi2;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_svp_cov_xy;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_svp_cov_xz;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_svp_cov_yz;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_svp_efrc;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_svp_err_x;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_svp_err_y;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_svp_err_z;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_svp_mass;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_svp_x;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_svp_y;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_component_svp_z;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_truth_dRminToB;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_truth_dRminToC;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_truth_dRminToT;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_truth_vx_x;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_truth_vx_y;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_truth_vx_z;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_weight_Comb;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_weight_GbbNN;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_weight_IP2D;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_weight_IP3D;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_weight_JetFitterCOMBNN;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_weight_JetFitterCharm;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_weight_JetFitterTagNN;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_weight_MV2;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_weight_SV0;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_weight_SV1;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_weight_SV2;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_weight_SecondSoftMuonTagChi2;
    // std::vector<float>   *jet_AntiKt4LCTopo_flavor_weight_SoftMuonTagChi2;
    // std::vector<float>   *jet_AntiKt4LCTopo_jvtx_x;
    // std::vector<float>   *jet_AntiKt4LCTopo_jvtx_y;
    // std::vector<float>   *jet_AntiKt4LCTopo_jvtx_z;
    // std::vector<float>   *jet_AntiKt4LCTopo_n90;
    // std::vector<float>   *jet_AntiKt4LCTopo_nTrk_allpv_1GeV;
    // std::vector<float>   *jet_AntiKt4LCTopo_nTrk_pv0_1GeV;
    // std::vector<float>   *jet_AntiKt4LCTopo_nTrk_pv0_500MeV;
    // std::vector<float>   *jet_AntiKt4LCTopo_ootFracCells10;
    // std::vector<float>   *jet_AntiKt4LCTopo_ootFracCells5;
    // std::vector<float>   *jet_AntiKt4LCTopo_ootFracClusters10;
    // std::vector<float>   *jet_AntiKt4LCTopo_ootFracClusters5;
    // std::vector<float>   *jet_AntiKt4LCTopo_sumPtTrk_allpv_1GeV;
    // std::vector<float>   *jet_AntiKt4LCTopo_sumPtTrk_pv0_1GeV;
    // std::vector<float>   *jet_AntiKt4LCTopo_tgap3f;
    // std::vector<float>   *jet_AntiKt4LCTopo_trackWIDTH_allpv_1GeV;
    // std::vector<float>   *jet_AntiKt4LCTopo_trackWIDTH_pv0_1GeV;
    // std::vector<float>   *jet_AntiKt4TrackZ_E;
    // std::vector<float>   *jet_AntiKt4TrackZ_eta;
    // std::vector<float>   *jet_AntiKt4TrackZ_m;
    // std::vector<float>   *jet_AntiKt4TrackZ_phi;
    // std::vector<float>   *jet_AntiKt4TrackZ_pt;
    // std::vector<float>   *jet_AntiKt4TruthJets_ActiveArea;
    // std::vector<float>   *jet_AntiKt4TruthJets_ActiveAreaE;
    // std::vector<float>   *jet_AntiKt4TruthJets_ActiveAreaPx;
    // std::vector<float>   *jet_AntiKt4TruthJets_ActiveAreaPy;
    // std::vector<float>   *jet_AntiKt4TruthJets_ActiveAreaPz;
    // std::vector<float>   *jet_AntiKt4TruthJets_AverageLArQF;
    // std::vector<float>   *jet_AntiKt4TruthJets_BAD_CELLS_CORR_E;
    // std::vector<float>   *jet_AntiKt4TruthJets_BCH_CORR_CELL;
    // std::vector<float>   *jet_AntiKt4TruthJets_BCH_CORR_DOTX;
    // std::vector<float>   *jet_AntiKt4TruthJets_BCH_CORR_JET;
    // std::vector<float>   *jet_AntiKt4TruthJets_BCH_CORR_JET_FORCELL;
    // std::vector<float>   *jet_AntiKt4TruthJets_E;
    // std::vector<float>   *jet_AntiKt4TruthJets_EMJES;
    // std::vector<float>   *jet_AntiKt4TruthJets_EMJES_EtaCorr;
    // std::vector<float>   *jet_AntiKt4TruthJets_EMJESnooffset;
    // std::vector<float>   *jet_AntiKt4TruthJets_ENG_BAD_CELLS;
    // std::vector<float>   *jet_AntiKt4TruthJets_EtaOrigin;
    // std::vector<float>   *jet_AntiKt4TruthJets_HECQuality;
    // std::vector<float>   *jet_AntiKt4TruthJets_LArQuality;
    // std::vector<float>   *jet_AntiKt4TruthJets_LCJES;
    // std::vector<float>   *jet_AntiKt4TruthJets_LCJES_EtaCorr;
    // std::vector<float>   *jet_AntiKt4TruthJets_MOrigin;
    // std::vector<float>   *jet_AntiKt4TruthJets_N_BAD_CELLS;
    // std::vector<float>   *jet_AntiKt4TruthJets_N_BAD_CELLS_CORR;
    // std::vector<float>   *jet_AntiKt4TruthJets_NegativeE;
    // std::vector<float>   *jet_AntiKt4TruthJets_NumTowers;
    // std::vector<float>   *jet_AntiKt4TruthJets_Offset;
    // std::vector<float>   *jet_AntiKt4TruthJets_OriginIndex;
    // std::vector<float>   *jet_AntiKt4TruthJets_PhiOrigin;
    // std::vector<float>   *jet_AntiKt4TruthJets_Timing;
    // std::vector<float>   *jet_AntiKt4TruthJets_WIDTH;
    // std::vector<float>   *jet_AntiKt4TruthJets_emfrac;
    // std::vector<float>   *jet_AntiKt4TruthJets_emscale_E;
    // std::vector<float>   *jet_AntiKt4TruthJets_emscale_eta;
    // std::vector<float>   *jet_AntiKt4TruthJets_emscale_m;
    // std::vector<float>   *jet_AntiKt4TruthJets_emscale_phi;
    // std::vector<float>   *jet_AntiKt4TruthJets_emscale_pt;
    // std::vector<float>   *jet_AntiKt4TruthJets_eta;
    // std::vector<float>   *jet_AntiKt4TruthJets_flavor_truth_dRminToB;
    // std::vector<float>   *jet_AntiKt4TruthJets_flavor_truth_dRminToC;
    // std::vector<float>   *jet_AntiKt4TruthJets_flavor_truth_dRminToT;
    // std::vector<float>   *jet_AntiKt4TruthJets_flavor_truth_vx_x;
    // std::vector<float>   *jet_AntiKt4TruthJets_flavor_truth_vx_y;
    // std::vector<float>   *jet_AntiKt4TruthJets_flavor_truth_vx_z;
    // std::vector<float>   *jet_AntiKt4TruthJets_fracSamplingMax;
    // std::vector<float>   *jet_AntiKt4TruthJets_hecf;
    // std::vector<float>   *jet_AntiKt4TruthJets_m;
    // std::vector<float>   *jet_AntiKt4TruthJets_n90;
    // std::vector<float>   *jet_AntiKt4TruthJets_ootFracCells10;
    // std::vector<float>   *jet_AntiKt4TruthJets_ootFracCells5;
    // std::vector<float>   *jet_AntiKt4TruthJets_ootFracClusters10;
    // std::vector<float>   *jet_AntiKt4TruthJets_ootFracClusters5;
    // std::vector<float>   *jet_AntiKt4TruthJets_phi;
    // std::vector<float>   *jet_AntiKt4TruthJets_pt;
    // std::vector<float>   *jet_AntiKt4TruthJets_tgap3f;
    // std::vector<float>   *jet_AntiKt6LCTopo_E;
    // std::vector<float>   *jet_AntiKt6LCTopo_eta;
    // std::vector<float>   *jet_AntiKt6LCTopo_m;
    // std::vector<float>   *jet_AntiKt6LCTopo_phi;
    // std::vector<float>   *jet_AntiKt6LCTopo_pt;
    // std::vector<float>   *jet_AntiKt6TopoEM_E;
    // std::vector<float>   *jet_AntiKt6TopoEM_eta;
    // std::vector<float>   *jet_AntiKt6TopoEM_m;
    // std::vector<float>   *jet_AntiKt6TopoEM_phi;
    // std::vector<float>   *jet_AntiKt6TopoEM_pt;
    // std::vector<float>   *mcVx_x;
    // std::vector<float>   *mcVx_y;
    // std::vector<float>   *mcVx_z;
    // std::vector<float>   *mc_vx_x;
    // std::vector<float>   *mc_vx_y;
    // std::vector<float>   *mc_vx_z;
    // std::vector<float>   *mu_staco_E;
    // std::vector<float>   *mu_staco_cb_d0_exPV;
    // std::vector<float>   *mu_staco_cb_phi_exPV;
    // std::vector<float>   *mu_staco_cb_qoverp_exPV;
    // std::vector<float>   *mu_staco_cb_theta_exPV;
    // std::vector<float>   *mu_staco_cb_z0_exPV;
    // std::vector<float>   *mu_staco_cov_d0_exPV;
    // std::vector<float>   *mu_staco_cov_d0_phi_exPV;
    // std::vector<float>   *mu_staco_cov_d0_qoverp_exPV;
    // std::vector<float>   *mu_staco_cov_d0_theta_exPV;
    // std::vector<float>   *mu_staco_cov_d0_z0_exPV;
    // std::vector<float>   *mu_staco_cov_phi_exPV;
    // std::vector<float>   *mu_staco_cov_phi_qoverp_exPV;
    // std::vector<float>   *mu_staco_cov_phi_theta_exPV;
    // std::vector<float>   *mu_staco_cov_theta_exPV;
    // std::vector<float>   *mu_staco_cov_theta_qoverp_exPV;
    // std::vector<float>   *mu_staco_cov_z0_exPV;
    // std::vector<float>   *mu_staco_cov_z0_phi_exPV;
    // std::vector<float>   *mu_staco_cov_z0_qoverp_exPV;
    // std::vector<float>   *mu_staco_cov_z0_theta_exPV;
    // std::vector<float>   *mu_staco_energyLossErr;
    // std::vector<float>   *mu_staco_energyLossPar;
    // std::vector<float>   *mu_staco_energyLossType;
    // std::vector<float>   *mu_staco_etCore;
    // std::vector<float>   *mu_staco_etcone20;
    // std::vector<float>   *mu_staco_etcone40;
    // std::vector<float>   *mu_staco_etconeNoEm10;
    // std::vector<float>   *mu_staco_etconeNoEm20;
    // std::vector<float>   *mu_staco_etconeNoEm30;
    // std::vector<float>   *mu_staco_etconeNoEm40;
    // std::vector<float>   *mu_staco_id_cov_d0_exPV;
    // std::vector<float>   *mu_staco_id_cov_d0_phi_exPV;
    // std::vector<float>   *mu_staco_id_cov_d0_qoverp_exPV;
    // std::vector<float>   *mu_staco_id_cov_d0_theta_exPV;
    // std::vector<float>   *mu_staco_id_cov_d0_z0_exPV;
    // std::vector<float>   *mu_staco_id_cov_phi_exPV;
    // std::vector<float>   *mu_staco_id_cov_phi_qoverp_exPV;
    // std::vector<float>   *mu_staco_id_cov_phi_theta_exPV;
    // std::vector<float>   *mu_staco_id_cov_qoverp_exPV;
    // std::vector<float>   *mu_staco_id_cov_theta_exPV;
    // std::vector<float>   *mu_staco_id_cov_theta_qoverp_exPV;
    // std::vector<float>   *mu_staco_id_cov_z0_exPV;
    // std::vector<float>   *mu_staco_id_cov_z0_phi_exPV;
    // std::vector<float>   *mu_staco_id_cov_z0_qoverp_exPV;
    // std::vector<float>   *mu_staco_id_cov_z0_theta_exPV;
    // std::vector<float>   *mu_staco_id_d0;
    // std::vector<float>   *mu_staco_id_d0_exPV;
    // std::vector<float>   *mu_staco_id_phi;
    // std::vector<float>   *mu_staco_id_phi_exPV;
    // std::vector<float>   *mu_staco_id_qoverp;
    // std::vector<float>   *mu_staco_id_theta;
    // std::vector<float>   *mu_staco_id_z0;
    // std::vector<float>   *mu_staco_id_z0_exPV;
    // std::vector<float>   *mu_staco_ie_d0;
    // std::vector<float>   *mu_staco_ie_d0_exPV;
    // std::vector<float>   *mu_staco_ie_phi;
    // std::vector<float>   *mu_staco_ie_phi_exPV;
    // std::vector<float>   *mu_staco_ie_qoverp;
    // std::vector<float>   *mu_staco_ie_qoverp_exPV;
    // std::vector<float>   *mu_staco_ie_theta;
    // std::vector<float>   *mu_staco_ie_theta_exPV;
    // std::vector<float>   *mu_staco_ie_z0;
    // std::vector<float>   *mu_staco_ie_z0_exPV;
    // std::vector<float>   *mu_staco_m;
    // std::vector<float>   *mu_staco_matchchi2;
    // std::vector<float>   *mu_staco_mc_dr;
    // std::vector<float>   *mu_staco_me_cov_d0_exPV;
    // std::vector<float>   *mu_staco_me_cov_phi_exPV;
    // std::vector<float>   *mu_staco_me_cov_qoverp_exPV;
    // std::vector<float>   *mu_staco_me_cov_theta_exPV;
    // std::vector<float>   *mu_staco_me_cov_z0_exPV;
    // std::vector<float>   *mu_staco_me_d0;
    // std::vector<float>   *mu_staco_me_d0_exPV;
    // std::vector<float>   *mu_staco_me_phi;
    // std::vector<float>   *mu_staco_me_phi_exPV;
    // std::vector<float>   *mu_staco_me_qoverp;
    // std::vector<float>   *mu_staco_me_theta;
    // std::vector<float>   *mu_staco_me_z0;
    // std::vector<float>   *mu_staco_me_z0_exPV;
    // std::vector<float>   *mu_staco_momentumBalanceSignificance;
    // std::vector<float>   *mu_staco_ms_d0;
    // std::vector<float>   *mu_staco_ms_z0;
    // std::vector<float>   *mu_staco_nucone20;
    // std::vector<float>   *mu_staco_nucone30;
    // std::vector<float>   *mu_staco_nucone40;
    // std::vector<float>   *mu_staco_phi_exPV;
    // std::vector<float>   *mu_staco_ptcone20;
    // std::vector<float>   *mu_staco_ptcone20_trk500MeV;
    // std::vector<float>   *mu_staco_ptcone20_trkelstyle;
    // std::vector<float>   *mu_staco_ptcone30;
    // std::vector<float>   *mu_staco_ptcone30_trk500MeV;
    // std::vector<float>   *mu_staco_ptcone40;
    // std::vector<float>   *mu_staco_ptcone40_trk500MeV;
    // std::vector<float>   *mu_staco_ptcone40_trkelstyle;
    // std::vector<float>   *mu_staco_px;
    // std::vector<float>   *mu_staco_py;
    // std::vector<float>   *mu_staco_pz;
    // std::vector<float>   *mu_staco_scatteringCurvatureSignificance;
    // std::vector<float>   *mu_staco_scatteringNeighbourSignificance;
    // std::vector<float>   *mu_staco_theta_exPV;
    // std::vector<float>   *mu_staco_trackIPEstimate_d0_biasedpvunbiased;
    // std::vector<float>   *mu_staco_trackIPEstimate_sigd0_biasedpvunbiased;
    // std::vector<float>   *mu_staco_trackIPEstimate_sigz0_biasedpvunbiased;
    // std::vector<float>   *mu_staco_trackIPEstimate_sigz0_unbiasedpvunbiased;
    // std::vector<float>   *mu_staco_trackIPEstimate_z0_biasedpvunbiased;
    // std::vector<float>   *mu_staco_trackcov_d0;
    // std::vector<float>   *mu_staco_trackcov_d0_phi;
    // std::vector<float>   *mu_staco_trackcov_d0_qoverp;
    // std::vector<float>   *mu_staco_trackcov_d0_theta;
    // std::vector<float>   *mu_staco_trackcov_d0_z0;
    // std::vector<float>   *mu_staco_trackcov_phi;
    // std::vector<float>   *mu_staco_trackcov_phi_qoverp;
    // std::vector<float>   *mu_staco_trackcov_phi_theta;
    // std::vector<float>   *mu_staco_trackcov_qoverp;
    // std::vector<float>   *mu_staco_trackcov_theta;
    // std::vector<float>   *mu_staco_trackcov_theta_qoverp;
    // std::vector<float>   *mu_staco_trackcov_z0;
    // std::vector<float>   *mu_staco_trackcov_z0_phi;
    // std::vector<float>   *mu_staco_trackcov_z0_qoverp;
    // std::vector<float>   *mu_staco_trackcov_z0_theta;
    // std::vector<float>   *mu_staco_trackd0;
    // std::vector<float>   *mu_staco_trackphi;
    // std::vector<float>   *mu_staco_trackqoverp;
    // std::vector<float>   *mu_staco_tracktheta;
    // std::vector<float>   *mu_staco_trackz0;
    // std::vector<float>   *mu_staco_truth_E;
    // std::vector<float>   *mu_staco_truth_dr;
    // std::vector<float>   *mu_staco_truth_eta;
    // std::vector<float>   *mu_staco_truth_phi;
    // std::vector<float>   *mu_staco_truth_pt;
    // std::vector<float>   *muonTruth_charge;
    // std::vector<float>   *muonTruth_eta;
    // std::vector<float>   *muonTruth_m;
    // std::vector<float>   *muonTruth_phi;
    // std::vector<float>   *muonTruth_pt;
    // std::vector<float>   *ph_E033;
    // std::vector<float>   *ph_E1152;
    // std::vector<float>   *ph_E132;
    // std::vector<float>   *ph_E233;
    // std::vector<float>   *ph_E237;
    // std::vector<float>   *ph_E277;
    // std::vector<float>   *ph_E;
    // std::vector<float>   *ph_ED_Njets;
    // std::vector<float>   *ph_ED_median;
    // std::vector<float>   *ph_ED_sigma;
    // std::vector<float>   *ph_Emax2;
    // std::vector<float>   *ph_Emins1;
    // std::vector<float>   *ph_Es0;
    // std::vector<float>   *ph_Es1;
    // std::vector<float>   *ph_Es2;
    // std::vector<float>   *ph_Es3;
    // std::vector<float>   *ph_Et;
    // std::vector<float>   *ph_Etcone15;
    // std::vector<float>   *ph_Etcone20;
    // std::vector<float>   *ph_Etcone25;
    // std::vector<float>   *ph_Etcone30;
    // std::vector<float>   *ph_Etcone35;
    // std::vector<float>   *ph_Etcone40;
    // std::vector<float>   *ph_Etcone40_ED_corrected;
    // std::vector<float>   *ph_Etcone40_corrected;
    // std::vector<float>   *ph_Etcone45;
    // std::vector<float>   *ph_Ethad1;
    // std::vector<float>   *ph_Ethad;
    // std::vector<float>   *ph_Rconv;
    // std::vector<float>   *ph_cl_E;
    // std::vector<float>   *ph_cl_eta;
    // std::vector<float>   *ph_cl_phi;
    // std::vector<float>   *ph_cl_pt;
    // std::vector<float>   *ph_cl_time;
    // std::vector<float>   *ph_convanglematch;
    // std::vector<float>   *ph_convtrackmatch;
    // std::vector<float>   *ph_convvtxchi2;
    // std::vector<float>   *ph_convvtxx;
    // std::vector<float>   *ph_convvtxy;
    // std::vector<float>   *ph_convvtxz;
    // std::vector<float>   *ph_deltaEmax2;
    // std::vector<float>   *ph_deltaEs;
    // std::vector<float>   *ph_depth;
    // std::vector<float>   *ph_emaxs1;
    // std::vector<float>   *ph_errz;
    // std::vector<float>   *ph_eta;
    // std::vector<float>   *ph_etap;
    // std::vector<float>   *ph_etas0;
    // std::vector<float>   *ph_etas1;
    // std::vector<float>   *ph_etas2;
    // std::vector<float>   *ph_etas3;
    // std::vector<float>   *ph_f1;
    // std::vector<float>   *ph_f1core;
    // std::vector<float>   *ph_f3;
    // std::vector<float>   *ph_f3core;
    // std::vector<float>   *ph_fside;
    // std::vector<float>   *ph_jet_dr;
    // std::vector<float>   *ph_m;
    // std::vector<float>   *ph_maxEcell_energy;
    // std::vector<float>   *ph_maxEcell_time;
    // std::vector<float>   *ph_maxEcell_x;
    // std::vector<float>   *ph_maxEcell_y;
    // std::vector<float>   *ph_maxEcell_z;
    // std::vector<float>   *ph_nucone20;
    // std::vector<float>   *ph_nucone20_zpv05;
    // std::vector<float>   *ph_nucone30;
    // std::vector<float>   *ph_nucone30_zpv05;
    // std::vector<float>   *ph_nucone40;
    // std::vector<float>   *ph_nucone40_zpv05;
    // std::vector<float>   *ph_phi;
    // std::vector<float>   *ph_phis0;
    // std::vector<float>   *ph_phis1;
    // std::vector<float>   *ph_phis2;
    // std::vector<float>   *ph_phis3;
    // std::vector<float>   *ph_pt1conv;
    // std::vector<float>   *ph_pt2conv;
    // std::vector<float>   *ph_pt;
    // std::vector<float>   *ph_ptcone20;
    // std::vector<float>   *ph_ptcone20_zpv05;
    // std::vector<float>   *ph_ptcone30;
    // std::vector<float>   *ph_ptcone30_zpv05;
    // std::vector<float>   *ph_ptcone40;
    // std::vector<float>   *ph_ptcone40_zpv05;
    // std::vector<float>   *ph_ptconv;
    // std::vector<float>   *ph_px;
    // std::vector<float>   *ph_py;
    // std::vector<float>   *ph_pz;
    // std::vector<float>   *ph_pzconv;
    // std::vector<float>   *ph_reta;
    // std::vector<float>   *ph_rphi;
    // std::vector<float>   *ph_rphiallcalo;
    // std::vector<float>   *ph_topoEtcone20;
    // std::vector<float>   *ph_topoEtcone20_corrected;
    // std::vector<float>   *ph_topoEtcone30;
    // std::vector<float>   *ph_topoEtcone30_corrected;
    // std::vector<float>   *ph_topoEtcone40;
    // std::vector<float>   *ph_topoEtcone40_corrected;
    // std::vector<float>   *ph_truth_E;
    // std::vector<float>   *ph_truth_Rconv;
    // std::vector<float>   *ph_truth_deltaRRecPhoton;
    // std::vector<float>   *ph_truth_eta;
    // std::vector<float>   *ph_truth_phi;
    // std::vector<float>   *ph_truth_pt;
    // std::vector<float>   *ph_truth_zconv;
    // std::vector<float>   *ph_weta2;
    // std::vector<float>   *ph_ws3;
    // std::vector<float>   *ph_wstot;
    // std::vector<float>   *ph_zconv;
    // std::vector<float>   *ph_zvertex;
    // std::vector<float>   *tau_BDTEleScore;
    // std::vector<float>   *tau_BDTJetScore;
    // std::vector<float>   *tau_EF_E;
    // std::vector<float>   *tau_EF_Et;
    // std::vector<float>   *tau_EF_dr;
    // std::vector<float>   *tau_EF_eta;
    // std::vector<float>   *tau_EF_phi;
    // std::vector<float>   *tau_EF_pt;
    // std::vector<float>   *tau_EM_TES_scale;
    // std::vector<float>   *tau_Et;
    // std::vector<float>   *tau_L1_Et;
    // std::vector<float>   *tau_L1_dr;
    // std::vector<float>   *tau_L1_eta;
    // std::vector<float>   *tau_L1_phi;
    // std::vector<float>   *tau_L1_pt;
    // std::vector<float>   *tau_L2_E;
    // std::vector<float>   *tau_L2_Et;
    // std::vector<float>   *tau_L2_dr;
    // std::vector<float>   *tau_L2_eta;
    // std::vector<float>   *tau_L2_phi;
    // std::vector<float>   *tau_L2_pt;
    // std::vector<float>   *tau_LC_TES_precalib;
    // std::vector<float>   *tau_SafeLikelihood;
    // std::vector<float>   *tau_TRTHTOverLT_LeadTrk;
    // std::vector<float>   *tau_calcVars_ChPiEMEOverCaloEME;
    // std::vector<float>   *tau_calcVars_EMFractionAtEMScale;
    // std::vector<float>   *tau_calcVars_EMFractionAtEMScale_MoveE3;
    // std::vector<float>   *tau_calcVars_EMPOverTrkSysP;
    // std::vector<float>   *tau_calcVars_PSSFraction;
    // std::vector<float>   *tau_calcVars_SecMaxStripEtOverPt;
    // std::vector<float>   *tau_calcVars_absDeltaEta;
    // std::vector<float>   *tau_calcVars_absDeltaPhi;
    // std::vector<float>   *tau_calcVars_calRadius;
    // std::vector<float>   *tau_calcVars_corrCentFrac;
    // std::vector<float>   *tau_calcVars_corrFTrk;
    // std::vector<float>   *tau_calcVars_drMin;
    // std::vector<float>   *tau_calcVars_etEM_EMScale_Pt3Trks;
    // std::vector<float>   *tau_calcVars_etHad_EMScale_Pt3Trks;
    // std::vector<float>   *tau_calcVars_interAxis_eta;
    // std::vector<float>   *tau_calcVars_interAxis_phi;
    // std::vector<float>   *tau_calcVars_ipSigLeadLooseTrk;
    // std::vector<float>   *tau_calcVars_pi0BDTPrimaryScore;
    // std::vector<float>   *tau_calcVars_pi0BDTSecondaryScore;
    // std::vector<float>   *tau_calcVars_trackIso;
    // std::vector<float>   *tau_cellBasedEnergyRing1;
    // std::vector<float>   *tau_cellBasedEnergyRing2;
    // std::vector<float>   *tau_cellBasedEnergyRing3;
    // std::vector<float>   *tau_cellBasedEnergyRing4;
    // std::vector<float>   *tau_cellBasedEnergyRing5;
    // std::vector<float>   *tau_cellBasedEnergyRing6;
    // std::vector<float>   *tau_cellBasedEnergyRing7;
    // std::vector<float>   *tau_chrgLooseTrk;
    // std::vector<float>   *tau_effTopoInvMass;
    // std::vector<float>   *tau_effTopoMeanDeltaR;
    // std::vector<float>   *tau_ele_E237E277;
    // std::vector<float>   *tau_ele_ECALFirstFraction;
    // std::vector<float>   *tau_ele_PresamplerFraction;
    // std::vector<float>   *tau_etEflow;
    // std::vector<float>   *tau_etOverPtLeadLooseTrk;
    // std::vector<float>   *tau_etOverPtLeadTrk;
    // std::vector<float>   *tau_ipSigLeadLooseTrk;
    // std::vector<float>   *tau_ipSigLeadTrk;
    // std::vector<float>   *tau_ipZ0SinThetaSigLeadTrk;
    // std::vector<float>   *tau_jet_BAD_CELLS_CORR_E;
    // std::vector<float>   *tau_jet_BCH_CORR_CELL;
    // std::vector<float>   *tau_jet_BCH_CORR_DOTX;
    // std::vector<float>   *tau_jet_BCH_CORR_JET;
    // std::vector<float>   *tau_jet_BCH_CORR_JET_FORCELL;
    // std::vector<float>   *tau_jet_EMJES;
    // std::vector<float>   *tau_jet_ENG_BAD_CELLS;
    // std::vector<float>   *tau_jet_Et;
    // std::vector<float>   *tau_jet_GCWJES;
    // std::vector<float>   *tau_jet_HECQuality;
    // std::vector<float>   *tau_jet_LArQuality;
    // std::vector<float>   *tau_jet_N_BAD_CELLS;
    // std::vector<float>   *tau_jet_N_BAD_CELLS_CORR;
    // std::vector<float>   *tau_jet_NegativeE;
    // std::vector<float>   *tau_jet_OriginIndex;
    // std::vector<float>   *tau_jet_Timing;
    // std::vector<float>   *tau_jet_WIDTH;
    // std::vector<float>   *tau_jet_YFlip12;
    // std::vector<float>   *tau_jet_YFlip23;
    // std::vector<float>   *tau_jet_e_EMB1;
    // std::vector<float>   *tau_jet_e_EMB2;
    // std::vector<float>   *tau_jet_e_EMB3;
    // std::vector<float>   *tau_jet_e_EME1;
    // std::vector<float>   *tau_jet_e_EME2;
    // std::vector<float>   *tau_jet_e_EME3;
    // std::vector<float>   *tau_jet_e_FCAL0;
    // std::vector<float>   *tau_jet_e_FCAL1;
    // std::vector<float>   *tau_jet_e_FCAL2;
    // std::vector<float>   *tau_jet_e_HEC0;
    // std::vector<float>   *tau_jet_e_HEC1;
    // std::vector<float>   *tau_jet_e_HEC2;
    // std::vector<float>   *tau_jet_e_HEC3;
    // std::vector<float>   *tau_jet_e_PreSamplerB;
    // std::vector<float>   *tau_jet_e_PreSamplerE;
    // std::vector<float>   *tau_jet_e_TileBar0;
    // std::vector<float>   *tau_jet_e_TileBar1;
    // std::vector<float>   *tau_jet_e_TileBar2;
    // std::vector<float>   *tau_jet_e_TileExt0;
    // std::vector<float>   *tau_jet_e_TileExt1;
    // std::vector<float>   *tau_jet_e_TileExt2;
    // std::vector<float>   *tau_jet_e_TileGap1;
    // std::vector<float>   *tau_jet_e_TileGap2;
    // std::vector<float>   *tau_jet_e_TileGap3;
    // std::vector<float>   *tau_jet_emfrac;
    // std::vector<float>   *tau_jet_emscale_E;
    // std::vector<float>   *tau_jet_emscale_eta;
    // std::vector<float>   *tau_jet_emscale_m;
    // std::vector<float>   *tau_jet_emscale_phi;
    // std::vector<float>   *tau_jet_emscale_pt;
    // std::vector<float>   *tau_jet_eta;
    // std::vector<float>   *tau_jet_fracSamplingMax;
    // std::vector<float>   *tau_jet_hecf;
    // std::vector<float>   *tau_jet_jvtx_x;
    // std::vector<float>   *tau_jet_jvtx_y;
    // std::vector<float>   *tau_jet_jvtx_z;
    // std::vector<float>   *tau_jet_jvtxf;
    // std::vector<float>   *tau_jet_m;
    // std::vector<float>   *tau_jet_n90;
    // std::vector<float>   *tau_jet_n90constituents;
    // std::vector<float>   *tau_jet_nTrk;
    // std::vector<float>   *tau_jet_phi;
    // std::vector<float>   *tau_jet_pt;
    // std::vector<float>   *tau_jet_sumPtTrk;
    // std::vector<float>   *tau_jet_tgap3f;
    // std::vector<float>   *tau_leadLooseTrkPt;
    // std::vector<float>   *tau_leadTrack_eta;
    // std::vector<float>   *tau_leadTrack_phi;
    // std::vector<float>   *tau_leadTrkPt;
    // std::vector<float>   *tau_likelihood;
    // std::vector<float>   *tau_mEflow;
    // std::vector<float>   *tau_massTrkSys;
    // std::vector<float>   *tau_numCells;
    // std::vector<float>   *tau_numEffTopoClusters;
    // std::vector<float>   *tau_pi0_cl1_eta;
    // std::vector<float>   *tau_pi0_cl1_phi;
    // std::vector<float>   *tau_pi0_cl1_pt;
    // std::vector<float>   *tau_pi0_cl2_eta;
    // std::vector<float>   *tau_pi0_cl2_phi;
    // std::vector<float>   *tau_pi0_cl2_pt;
    // std::vector<float>   *tau_pi0_vistau_eta;
    // std::vector<float>   *tau_pi0_vistau_m;
    // std::vector<float>   *tau_pi0_vistau_phi;
    // std::vector<float>   *tau_pi0_vistau_pt;
    // std::vector<float>   *tau_privtx_chiSquared;
    // std::vector<float>   *tau_privtx_jvf;
    // std::vector<float>   *tau_privtx_numberDoF;
    // std::vector<float>   *tau_privtx_x;
    // std::vector<float>   *tau_privtx_xx;
    // std::vector<float>   *tau_privtx_xy;
    // std::vector<float>   *tau_privtx_y;
    // std::vector<float>   *tau_privtx_yy;
    // std::vector<float>   *tau_privtx_yz;
    // std::vector<float>   *tau_privtx_z;
    // std::vector<float>   *tau_privtx_zx;
    // std::vector<float>   *tau_privtx_zz;
    // std::vector<float>   *tau_secvtx_chiSquared;
    // std::vector<float>   *tau_secvtx_numberDoF;
    // std::vector<float>   *tau_secvtx_x;
    // std::vector<float>   *tau_secvtx_xx;
    // std::vector<float>   *tau_secvtx_xy;
    // std::vector<float>   *tau_secvtx_y;
    // std::vector<float>   *tau_secvtx_yy;
    // std::vector<float>   *tau_secvtx_yz;
    // std::vector<float>   *tau_secvtx_z;
    // std::vector<float>   *tau_secvtx_zx;
    // std::vector<float>   *tau_secvtx_zz;
    // std::vector<float>   *tau_seedCalo_EMRadius;
    // std::vector<float>   *tau_seedCalo_caloIso;
    // std::vector<float>   *tau_seedCalo_caloIsoCorrected;
    // std::vector<float>   *tau_seedCalo_centFrac;
    // std::vector<float>   *tau_seedCalo_dRmax;
    // std::vector<float>   *tau_seedCalo_etEMAtEMScale;
    // std::vector<float>   *tau_seedCalo_etEMCalib;
    // std::vector<float>   *tau_seedCalo_etHadAtEMScale;
    // std::vector<float>   *tau_seedCalo_etHadCalib;
    // std::vector<float>   *tau_seedCalo_eta;
    // std::vector<float>   *tau_seedCalo_hadRadius;
    // std::vector<float>   *tau_seedCalo_isolFrac;
    // std::vector<float>   *tau_seedCalo_lead2ClusterEOverAllClusterE;
    // std::vector<float>   *tau_seedCalo_lead3ClusterEOverAllClusterE;
    // std::vector<float>   *tau_seedCalo_nIsolLooseTrk;
    // std::vector<float>   *tau_seedCalo_phi;
    // std::vector<float>   *tau_seedCalo_stripWidth2;
    // std::vector<float>   *tau_seedCalo_trkAvgDist;
    // std::vector<float>   *tau_seedCalo_trkRmsDist;
    // std::vector<float>   *tau_seedTrk_EMRadius;
    // std::vector<float>   *tau_seedTrk_etChrgEM;
    // std::vector<float>   *tau_seedTrk_etChrgHad;
    // std::vector<float>   *tau_seedTrk_etChrgHadOverSumTrkPt;
    // std::vector<float>   *tau_seedTrk_etEMAtEMScale;
    // std::vector<float>   *tau_seedTrk_etEMCL;
    // std::vector<float>   *tau_seedTrk_etHadAtEMScale;
    // std::vector<float>   *tau_seedTrk_etIsolEM;
    // std::vector<float>   *tau_seedTrk_etIsolHad;
    // std::vector<float>   *tau_seedTrk_etNeuEM;
    // std::vector<float>   *tau_seedTrk_etResNeuEM;
    // std::vector<float>   *tau_seedTrk_hadLeakEt;
    // std::vector<float>   *tau_seedTrk_isolFrac;
    // std::vector<float>   *tau_seedTrk_isolFracWide;
    // std::vector<float>   *tau_seedTrk_secMaxStripEt;
    // std::vector<float>   *tau_seedTrk_stripWidth2;
    // std::vector<float>   *tau_seedTrk_sumEMCellEtOverLeadTrkPt;
    // std::vector<float>   *tau_topoInvMass;
    // std::vector<float>   *tau_topoMeanDeltaR;
    // std::vector<float>   *tau_trFlightPathSig;
    // std::vector<float>   *tau_trkWidth2;
    // std::vector<float>   *tau_trueTauAssocSmall_dr;
    // std::vector<float>   *trig_EF_bjet_eta;
    // std::vector<float>   *trig_EF_bjet_phi;
    // std::vector<float>   *trig_EF_bjet_prmVtx;
    // std::vector<float>   *trig_EF_bjet_pt;
    // std::vector<float>   *trig_EF_bjet_vertex_chi2;
    // std::vector<float>   *trig_EF_bjet_vertex_energyFraction;
    // std::vector<float>   *trig_EF_bjet_vertex_mass;
    // std::vector<float>   *trig_EF_bjet_vertex_massVariance;
    // std::vector<float>   *trig_EF_bjet_vertex_x;
    // std::vector<float>   *trig_EF_bjet_vertex_y;
    // std::vector<float>   *trig_EF_bjet_vertex_z;
    // std::vector<float>   *trig_EF_bjet_xCHI2;
    // std::vector<float>   *trig_EF_bjet_xComb;
    // std::vector<float>   *trig_EF_bjet_xEVtx;
    // std::vector<float>   *trig_EF_bjet_xIP1D;
    // std::vector<float>   *trig_EF_bjet_xIP2D;
    // std::vector<float>   *trig_EF_bjet_xIP3D;
    // std::vector<float>   *trig_EF_bjet_xMVtx;
    // std::vector<float>   *trig_EF_bjet_xNVtx;
    // std::vector<float>   *trig_EF_bjet_xSV;
    // std::vector<float>   *trig_EF_el_E233;
    // std::vector<float>   *trig_EF_el_E237;
    // std::vector<float>   *trig_EF_el_E277;
    // std::vector<float>   *trig_EF_el_Emax2;
    // std::vector<float>   *trig_EF_el_Emins1;
    // std::vector<float>   *trig_EF_el_Et;
    // std::vector<float>   *trig_EF_el_Etcone15;
    // std::vector<float>   *trig_EF_el_Etcone20;
    // std::vector<float>   *trig_EF_el_Etcone25;
    // std::vector<float>   *trig_EF_el_Etcone30;
    // std::vector<float>   *trig_EF_el_Etcone35;
    // std::vector<float>   *trig_EF_el_Etcone40;
    // std::vector<float>   *trig_EF_el_Etcone45;
    // std::vector<float>   *trig_EF_el_Ethad1;
    // std::vector<float>   *trig_EF_el_Ethad;
    // std::vector<float>   *trig_EF_el_TRTHighTHitsRatio;
    // std::vector<float>   *trig_EF_el_TRTHighTOutliersRatio;
    // std::vector<float>   *trig_EF_el_charge;
    // std::vector<float>   *trig_EF_el_cl_E;
    // std::vector<float>   *trig_EF_el_cl_eta;
    // std::vector<float>   *trig_EF_el_cl_etas2;
    // std::vector<float>   *trig_EF_el_cl_phi;
    // std::vector<float>   *trig_EF_el_cl_pt;
    // std::vector<float>   *trig_EF_el_deltaEs;
    // std::vector<float>   *trig_EF_el_deltaeta1;
    // std::vector<float>   *trig_EF_el_deltaeta2;
    // std::vector<float>   *trig_EF_el_deltaphi2;
    // std::vector<float>   *trig_EF_el_eProbabilityBrem;
    // std::vector<float>   *trig_EF_el_eProbabilityComb;
    // std::vector<float>   *trig_EF_el_eProbabilityHT;
    // std::vector<float>   *trig_EF_el_eProbabilityToT;
    // std::vector<float>   *trig_EF_el_emaxs1;
    // std::vector<float>   *trig_EF_el_eta;
    // std::vector<float>   *trig_EF_el_etacorrmag;
    // std::vector<float>   *trig_EF_el_expectHitInBLayer;
    // std::vector<float>   *trig_EF_el_f1;
    // std::vector<float>   *trig_EF_el_f1core;
    // std::vector<float>   *trig_EF_el_f3;
    // std::vector<float>   *trig_EF_el_f3core;
    // std::vector<float>   *trig_EF_el_fside;
    // std::vector<float>   *trig_EF_el_m;
    // std::vector<float>   *trig_EF_el_massPixeldEdx;
    // std::vector<float>   *trig_EF_el_phi;
    // std::vector<float>   *trig_EF_el_pixeldEdx;
    // std::vector<float>   *trig_EF_el_pos7;
    // std::vector<float>   *trig_EF_el_pt;
    // std::vector<float>   *trig_EF_el_ptcone20;
    // std::vector<float>   *trig_EF_el_ptcone30;
    // std::vector<float>   *trig_EF_el_ptcone40;
    // std::vector<float>   *trig_EF_el_reta;
    // std::vector<float>   *trig_EF_el_rphi;
    // std::vector<float>   *trig_EF_el_rphiallcalo;
    // std::vector<float>   *trig_EF_el_trackd0;
    // std::vector<float>   *trig_EF_el_trackd0_physics;
    // std::vector<float>   *trig_EF_el_tracketa;
    // std::vector<float>   *trig_EF_el_trackphi;
    // std::vector<float>   *trig_EF_el_trackpt;
    // std::vector<float>   *trig_EF_el_trackqoverp;
    // std::vector<float>   *trig_EF_el_tracktheta;
    // std::vector<float>   *trig_EF_el_trackz0;
    // std::vector<float>   *trig_EF_el_vertweight;
    // std::vector<float>   *trig_EF_el_weta2;
    // std::vector<float>   *trig_EF_el_ws3;
    // std::vector<float>   *trig_EF_el_wstot;
    // std::vector<float>   *trig_EF_emcl_E_em;
    // std::vector<float>   *trig_EF_emcl_E_had;
    // std::vector<float>   *trig_EF_emcl_avg_lar_q;
    // std::vector<float>   *trig_EF_emcl_avg_tile_q;
    // std::vector<float>   *trig_EF_emcl_badlarq_frac;
    // std::vector<float>   *trig_EF_emcl_cellmaxfrac;
    // std::vector<float>   *trig_EF_emcl_centerlambda;
    // std::vector<float>   *trig_EF_emcl_centermag;
    // std::vector<float>   *trig_EF_emcl_deltaPhi;
    // std::vector<float>   *trig_EF_emcl_deltaTheta;
    // std::vector<float>   *trig_EF_emcl_eng_bad_cells;
    // std::vector<float>   *trig_EF_emcl_eng_pos;
    // std::vector<float>   *trig_EF_emcl_eta;
    // std::vector<float>   *trig_EF_emcl_firstEdens;
    // std::vector<float>   *trig_EF_emcl_isolation;
    // std::vector<float>   *trig_EF_emcl_lateral;
    // std::vector<float>   *trig_EF_emcl_longitudinal;
    // std::vector<float>   *trig_EF_emcl_n_bad_cells;
    // std::vector<float>   *trig_EF_emcl_phi;
    // std::vector<float>   *trig_EF_emcl_pt;
    // std::vector<float>   *trig_EF_emcl_secondR;
    // std::vector<float>   *trig_EF_emcl_secondlambda;
    // std::vector<float>   *trig_EF_emcl_significance;
    // std::vector<float>   *trig_EF_emcl_slw_E_em;
    // std::vector<float>   *trig_EF_emcl_slw_E_had;
    // std::vector<float>   *trig_EF_emcl_slw_avg_lar_q;
    // std::vector<float>   *trig_EF_emcl_slw_avg_tile_q;
    // std::vector<float>   *trig_EF_emcl_slw_badlarq_frac;
    // std::vector<float>   *trig_EF_emcl_slw_cellmaxfrac;
    // std::vector<float>   *trig_EF_emcl_slw_centerlambda;
    // std::vector<float>   *trig_EF_emcl_slw_centermag;
    // std::vector<float>   *trig_EF_emcl_slw_deltaPhi;
    // std::vector<float>   *trig_EF_emcl_slw_deltaTheta;
    // std::vector<float>   *trig_EF_emcl_slw_eng_bad_cells;
    // std::vector<float>   *trig_EF_emcl_slw_eng_pos;
    // std::vector<float>   *trig_EF_emcl_slw_eta;
    // std::vector<float>   *trig_EF_emcl_slw_firstEdens;
    // std::vector<float>   *trig_EF_emcl_slw_isolation;
    // std::vector<float>   *trig_EF_emcl_slw_lateral;
    // std::vector<float>   *trig_EF_emcl_slw_longitudinal;
    // std::vector<float>   *trig_EF_emcl_slw_n_bad_cells;
    // std::vector<float>   *trig_EF_emcl_slw_phi;
    // std::vector<float>   *trig_EF_emcl_slw_pt;
    // std::vector<float>   *trig_EF_emcl_slw_secondR;
    // std::vector<float>   *trig_EF_emcl_slw_secondlambda;
    // std::vector<float>   *trig_EF_emcl_slw_significance;
    // std::vector<float>   *trig_EF_emcl_slw_time;
    // std::vector<float>   *trig_EF_emcl_time;
    // std::vector<float>   *trig_EF_feb_met_MExComponent;
    // std::vector<float>   *trig_EF_feb_met_MEyComponent;
    // std::vector<float>   *trig_EF_feb_met_MEzComponent;
    // std::vector<float>   *trig_EF_feb_met_componentCalib0;
    // std::vector<float>   *trig_EF_feb_met_componentCalib1;
    // std::vector<float>   *trig_EF_feb_met_sumEComponent;
    // std::vector<float>   *trig_EF_feb_met_sumEtComponent;
    // std::vector<float>   *trig_EF_jet_AverageLArQF;
    // std::vector<float>   *trig_EF_jet_Discriminant;
    // std::vector<float>   *trig_EF_jet_E;
    // std::vector<float>   *trig_EF_jet_EMFraction;
    // std::vector<float>   *trig_EF_jet_EMJES;
    // std::vector<float>   *trig_EF_jet_EMJES_EtaCorr;
    // std::vector<float>   *trig_EF_jet_HECQuality;
    // std::vector<float>   *trig_EF_jet_LArQuality;
    // std::vector<float>   *trig_EF_jet_MeanTowerEtUnsubtr;
    // std::vector<float>   *trig_EF_jet_NegativeE;
    // std::vector<float>   *trig_EF_jet_SamplingMax;
    // std::vector<float>   *trig_EF_jet_TileQuality;
    // std::vector<float>   *trig_EF_jet_Timing;
    // std::vector<float>   *trig_EF_jet_TrigJetFeaturesUnpacker_Status;
    // std::vector<float>   *trig_EF_jet_constscale_E;
    // std::vector<float>   *trig_EF_jet_constscale_eta;
    // std::vector<float>   *trig_EF_jet_constscale_m;
    // std::vector<float>   *trig_EF_jet_constscale_phi;
    // std::vector<float>   *trig_EF_jet_constscale_pt;
    // std::vector<float>   *trig_EF_jet_emscale_E;
    // std::vector<float>   *trig_EF_jet_emscale_eta;
    // std::vector<float>   *trig_EF_jet_emscale_m;
    // std::vector<float>   *trig_EF_jet_emscale_phi;
    // std::vector<float>   *trig_EF_jet_emscale_pt;
    // std::vector<float>   *trig_EF_jet_eta;
    // std::vector<float>   *trig_EF_jet_fracSamplingMax;
    // std::vector<float>   *trig_EF_jet_hecF;
    // std::vector<float>   *trig_EF_jet_m;
    // std::vector<float>   *trig_EF_jet_n90;
    // std::vector<float>   *trig_EF_jet_n90constituents;
    // std::vector<float>   *trig_EF_jet_phi;
    // std::vector<float>   *trig_EF_jet_presamplerFraction;
    // std::vector<float>   *trig_EF_jet_pt;
    // std::vector<float>   *trig_EF_jetetsum_MExComponent;
    // std::vector<float>   *trig_EF_jetetsum_MEyComponent;
    // std::vector<float>   *trig_EF_jetetsum_MEzComponent;
    // std::vector<float>   *trig_EF_jetetsum_componentCalib0;
    // std::vector<float>   *trig_EF_jetetsum_componentCalib1;
    // std::vector<float>   *trig_EF_jetetsum_sumEComponent;
    // std::vector<float>   *trig_EF_jetetsum_sumEtComponent;
    // std::vector<float>   *trig_EF_met_MExComponent;
    // std::vector<float>   *trig_EF_met_MEyComponent;
    // std::vector<float>   *trig_EF_met_MEzComponent;
    // std::vector<float>   *trig_EF_met_componentCalib0;
    // std::vector<float>   *trig_EF_met_componentCalib1;
    // std::vector<float>   *trig_EF_met_sumEComponent;
    // std::vector<float>   *trig_EF_met_sumEtComponent;
    // std::vector<float>   *trig_EF_ph_E033;
    // std::vector<float>   *trig_EF_ph_E1152;
    // std::vector<float>   *trig_EF_ph_E132;
    // std::vector<float>   *trig_EF_ph_E233;
    // std::vector<float>   *trig_EF_ph_E237;
    // std::vector<float>   *trig_EF_ph_E277;
    // std::vector<float>   *trig_EF_ph_E;
    // std::vector<float>   *trig_EF_ph_Emax2;
    // std::vector<float>   *trig_EF_ph_Emins1;
    // std::vector<float>   *trig_EF_ph_Et;
    // std::vector<float>   *trig_EF_ph_Etcone15;
    // std::vector<float>   *trig_EF_ph_Etcone20;
    // std::vector<float>   *trig_EF_ph_Etcone25;
    // std::vector<float>   *trig_EF_ph_Etcone30;
    // std::vector<float>   *trig_EF_ph_Etcone35;
    // std::vector<float>   *trig_EF_ph_Etcone40;
    // std::vector<float>   *trig_EF_ph_Etcone45;
    // std::vector<float>   *trig_EF_ph_Ethad1;
    // std::vector<float>   *trig_EF_ph_Ethad;
    // std::vector<float>   *trig_EF_ph_Rconv;
    // std::vector<float>   *trig_EF_ph_cl_E;
    // std::vector<float>   *trig_EF_ph_cl_eta;
    // std::vector<float>   *trig_EF_ph_cl_etas2;
    // std::vector<float>   *trig_EF_ph_cl_phi;
    // std::vector<float>   *trig_EF_ph_cl_pt;
    // std::vector<float>   *trig_EF_ph_convanglematch;
    // std::vector<float>   *trig_EF_ph_convtrackmatch;
    // std::vector<float>   *trig_EF_ph_convvtxchi2;
    // std::vector<float>   *trig_EF_ph_convvtxx;
    // std::vector<float>   *trig_EF_ph_convvtxy;
    // std::vector<float>   *trig_EF_ph_convvtxz;
    // std::vector<float>   *trig_EF_ph_deltaEs;
    // std::vector<float>   *trig_EF_ph_emaxs1;
    // std::vector<float>   *trig_EF_ph_eta;
    // std::vector<float>   *trig_EF_ph_f1;
    // std::vector<float>   *trig_EF_ph_f1core;
    // std::vector<float>   *trig_EF_ph_f3;
    // std::vector<float>   *trig_EF_ph_f3core;
    // std::vector<float>   *trig_EF_ph_fside;
    // std::vector<float>   *trig_EF_ph_m;
    // std::vector<float>   *trig_EF_ph_phi;
    // std::vector<float>   *trig_EF_ph_pt1conv;
    // std::vector<float>   *trig_EF_ph_pt2conv;
    // std::vector<float>   *trig_EF_ph_pt;
    // std::vector<float>   *trig_EF_ph_ptcone20;
    // std::vector<float>   *trig_EF_ph_ptcone30;
    // std::vector<float>   *trig_EF_ph_ptcone40;
    // std::vector<float>   *trig_EF_ph_ptconv;
    // std::vector<float>   *trig_EF_ph_px;
    // std::vector<float>   *trig_EF_ph_py;
    // std::vector<float>   *trig_EF_ph_pz;
    // std::vector<float>   *trig_EF_ph_pzconv;
    // std::vector<float>   *trig_EF_ph_reta;
    // std::vector<float>   *trig_EF_ph_rphi;
    // std::vector<float>   *trig_EF_ph_rphiallcalo;
    // std::vector<float>   *trig_EF_ph_weta2;
    // std::vector<float>   *trig_EF_ph_ws3;
    // std::vector<float>   *trig_EF_ph_wstot;
    // std::vector<float>   *trig_EF_ph_zconv;
    // std::vector<float>   *trig_EF_pv_err_x;
    // std::vector<float>   *trig_EF_pv_err_y;
    // std::vector<float>   *trig_EF_pv_err_z;
    // std::vector<float>   *trig_EF_pv_x;
    // std::vector<float>   *trig_EF_pv_y;
    // std::vector<float>   *trig_EF_pv_z;
    // std::vector<float>   *trig_EF_tau_BDTJetScore;
    // std::vector<float>   *trig_EF_tau_Et;
    // std::vector<float>   *trig_EF_tau_LC_TES_precalib;
    // std::vector<float>   *trig_EF_tau_effTopoInvMass;
    // std::vector<float>   *trig_EF_tau_effTopoMeanDeltaR;
    // std::vector<float>   *trig_EF_tau_etOverPtLeadTrk;
    // std::vector<float>   *trig_EF_tau_eta;
    // std::vector<float>   *trig_EF_tau_ipSigLeadTrk;
    // std::vector<float>   *trig_EF_tau_ipZ0SinThetaSigLeadTrk;
    // std::vector<float>   *trig_EF_tau_leadTrkPt;
    // std::vector<float>   *trig_EF_tau_likelihood;
    // std::vector<float>   *trig_EF_tau_m;
    // std::vector<float>   *trig_EF_tau_massTrkSys;
    // std::vector<float>   *trig_EF_tau_numCells;
    // std::vector<float>   *trig_EF_tau_numEffTopoClusters;
    // std::vector<float>   *trig_EF_tau_phi;
    // std::vector<float>   *trig_EF_tau_pt;
    // std::vector<float>   *trig_EF_tau_px;
    // std::vector<float>   *trig_EF_tau_py;
    // std::vector<float>   *trig_EF_tau_pz;
    // std::vector<float>   *trig_EF_tau_seedCalo_dRmax;
    // std::vector<float>   *trig_EF_tau_seedCalo_lead2ClusterEOverAllClusterE;
    // std::vector<float>   *trig_EF_tau_seedCalo_lead3ClusterEOverAllClusterE;
    // std::vector<float>   *trig_EF_tau_seedCalo_stripWidth2;
    // std::vector<float>   *trig_EF_tau_seedCalo_trkAvgDist;
    // std::vector<float>   *trig_EF_tau_seedCalo_trkRmsDist;
    // std::vector<float>   *trig_EF_tau_topoInvMass;
    // std::vector<float>   *trig_EF_tau_topoMeanDeltaR;
    // std::vector<float>   *trig_EF_tau_trFlightPathSig;
    // std::vector<float>   *trig_EF_topocl_met_MExComponent;
    // std::vector<float>   *trig_EF_topocl_met_MEyComponent;
    // std::vector<float>   *trig_EF_topocl_met_MEzComponent;
    // std::vector<float>   *trig_EF_topocl_met_componentCalib0;
    // std::vector<float>   *trig_EF_topocl_met_componentCalib1;
    // std::vector<float>   *trig_EF_topocl_met_sumEComponent;
    // std::vector<float>   *trig_EF_topocl_met_sumEtComponent;
    // std::vector<float>   *trig_EF_trigmuonefisolation_sumEtCone01;
    // std::vector<float>   *trig_EF_trigmuonefisolation_sumEtCone02;
    // std::vector<float>   *trig_EF_trigmuonefisolation_sumEtCone03;
    // std::vector<float>   *trig_EF_trigmuonefisolation_sumEtCone04;
    // std::vector<float>   *trig_EF_trigmuonefisolation_sumTrkPtCone02;
    // std::vector<float>   *trig_EF_trigmuonefisolation_sumTrkPtCone03;
    // std::vector<float>   *trig_roidescriptor_forID_eta;
    // std::vector<float>   *trig_roidescriptor_forID_etaHalfWidth;
    // std::vector<float>   *trig_roidescriptor_forID_etaMinus;
    // std::vector<float>   *trig_roidescriptor_forID_etaPlus;
    // std::vector<float>   *trig_roidescriptor_forID_phi;
    // std::vector<float>   *trig_roidescriptor_forID_phiHalfWidth;
    // std::vector<float>   *trig_roidescriptor_forID_zed0;
    // std::vector<float>   *trig_roidescriptor_forID_zedHalfWidth;
    // std::vector<float>   *trk_IPEstimate_d0_biased_wrtPV;
    // std::vector<float>   *trk_IPEstimate_d0_unbiased_wrtPV;
    // std::vector<float>   *trk_IPEstimate_errPV_d0_biased_wrtPV;
    // std::vector<float>   *trk_IPEstimate_errPV_d0_unbiased_wrtPV;
    // std::vector<float>   *trk_IPEstimate_errPV_z0_biased_wrtPV;
    // std::vector<float>   *trk_IPEstimate_errPV_z0_unbiased_wrtPV;
    // std::vector<float>   *trk_IPEstimate_err_d0_biased_wrtPV;
    // std::vector<float>   *trk_IPEstimate_err_d0_unbiased_wrtPV;
    // std::vector<float>   *trk_IPEstimate_err_z0_biased_wrtPV;
    // std::vector<float>   *trk_IPEstimate_err_z0_unbiased_wrtPV;
    // std::vector<float>   *trk_IPEstimate_z0_biased_wrtPV;
    // std::vector<float>   *trk_IPEstimate_z0_unbiased_wrtPV;
    // std::vector<float>   *trk_TRTHighTHitsRatio;
    // std::vector<float>   *trk_TRTHighTOutliersRatio;
    // std::vector<float>   *trk_chi2;
    // std::vector<float>   *trk_cone20_caloIso;
    // std::vector<float>   *trk_cone20_trackIso;
    // std::vector<float>   *trk_cone30_caloIso;
    // std::vector<float>   *trk_cone30_trackIso;
    // std::vector<float>   *trk_cone40_caloIso;
    // std::vector<float>   *trk_cone40_ptmin1gev_caloIso;
    // std::vector<float>   *trk_cone40_ptmin1gev_trackIso;
    // std::vector<float>   *trk_cone40_ptmin2gev_caloIso;
    // std::vector<float>   *trk_cone40_ptmin2gev_trackIso;
    // std::vector<float>   *trk_cone40_ptmin3gev_caloIso;
    // std::vector<float>   *trk_cone40_ptmin3gev_hitschi_caloIso;
    // std::vector<float>   *trk_cone40_ptmin3gev_hitschi_trackIso;
    // std::vector<float>   *trk_cone40_ptmin3gev_trackIso;
    // std::vector<float>   *trk_cone40_ptmin4gev_caloIso;
    // std::vector<float>   *trk_cone40_ptmin4gev_trackIso;
    // std::vector<float>   *trk_cone40_ptmin5gev_caloIso;
    // std::vector<float>   *trk_cone40_ptmin5gev_trackIso;
    // std::vector<float>   *trk_cone40_trackIso;
    // std::vector<float>   *trk_cov_d0_phi_wrtBS;
    // std::vector<float>   *trk_cov_d0_qoverp_wrtBS;
    // std::vector<float>   *trk_cov_d0_theta_wrtBS;
    // std::vector<float>   *trk_cov_d0_wrtBS;
    // std::vector<float>   *trk_cov_d0_wrtPV;
    // std::vector<float>   *trk_cov_d0_z0_wrtBS;
    // std::vector<float>   *trk_cov_phi_qoverp_wrtBS;
    // std::vector<float>   *trk_cov_phi_theta_wrtBS;
    // std::vector<float>   *trk_cov_phi_wrtBS;
    // std::vector<float>   *trk_cov_phi_wrtPV;
    // std::vector<float>   *trk_cov_qoverp_wrtBS;
    // std::vector<float>   *trk_cov_qoverp_wrtPV;
    // std::vector<float>   *trk_cov_theta_qoverp_wrtBS;
    // std::vector<float>   *trk_cov_theta_wrtBS;
    // std::vector<float>   *trk_cov_theta_wrtPV;
    // std::vector<float>   *trk_cov_z0_phi_wrtBS;
    // std::vector<float>   *trk_cov_z0_qoverp_wrtBS;
    // std::vector<float>   *trk_cov_z0_theta_wrtBS;
    // std::vector<float>   *trk_cov_z0_wrtBS;
    // std::vector<float>   *trk_cov_z0_wrtPV;
    // std::vector<float>   *trk_d0_err_wrtBL;
    // std::vector<float>   *trk_d0_phi_err_wrtBL;
    // std::vector<float>   *trk_d0_qoverp_err_wrtBL;
    // std::vector<float>   *trk_d0_theta_err_wrtBL;
    // std::vector<float>   *trk_d0_wrtBL;
    // std::vector<float>   *trk_d0_wrtBS;
    // std::vector<float>   *trk_d0_wrtPV;
    // std::vector<float>   *trk_d0_z0_err_wrtBL;
    // std::vector<float>   *trk_eta;
    // std::vector<float>   *trk_mc_probability;
    // std::vector<float>   *trk_phi_err_wrtBL;
    // std::vector<float>   *trk_phi_qoverp_err_wrtBL;
    // std::vector<float>   *trk_phi_theta_err_wrtBL;
    // std::vector<float>   *trk_phi_wrtBL;
    // std::vector<float>   *trk_phi_wrtBS;
    // std::vector<float>   *trk_phi_wrtPV;
    // std::vector<float>   *trk_pt;
    // std::vector<float>   *trk_qoverp_err_wrtBL;
    // std::vector<float>   *trk_qoverp_wrtPV;
    // std::vector<float>   *trk_theta_err_wrtBL;
    // std::vector<float>   *trk_theta_qoverp_err_wrtBL;
    // std::vector<float>   *trk_theta_wrtPV;
    // std::vector<float>   *trk_z0_err_wrtBL;
    // std::vector<float>   *trk_z0_phi_err_wrtBL;
    // std::vector<float>   *trk_z0_qoverp_err_wrtBL;
    // std::vector<float>   *trk_z0_theta_err_wrtBL;
    // std::vector<float>   *trk_z0_wrtBL;
    // std::vector<float>   *trk_z0_wrtBS;
    // std::vector<float>   *trk_z0_wrtPV;
    // std::vector<float>   *trueTau_charge;
    // std::vector<float>   *trueTau_eta;
    // std::vector<float>   *trueTau_m;
    // std::vector<float>   *trueTau_phi;
    // std::vector<float>   *trueTau_pt;
    // std::vector<float>   *trueTau_tauAssocSmall_dr;
    // std::vector<float>   *trueTau_vis_Et;
    // std::vector<float>   *trueTau_vis_eta;
    // std::vector<float>   *trueTau_vis_m;
    // std::vector<float>   *trueTau_vis_phi;
    // std::vector<float>   *vx_px;
    // std::vector<float>   *vx_py;
    // std::vector<float>   *vx_pz;
    // std::vector<float>   *vx_sumPt;
    // std::vector<int>     *SkimDecision_DAODEGAMMA_accepted;
    // std::vector<int>     *SkimDecision_DAODJETS_accepted;
    // std::vector<int>     *SkimDecision_DAODMUONS_accepted;
    // std::vector<int>     *SkimDecision_NTPSUSY_accepted;
    // std::vector<int>     *bb_cl_bbDecision;
    // std::vector<int>     *bb_jet_bbDecision;
    // std::vector<int>     *el_EF_index;
    // std::vector<int>     *el_convFlag;
    // std::vector<int>     *el_convtrk1nBLHits;
    // std::vector<int>     *el_convtrk1nPixHits;
    // std::vector<int>     *el_convtrk1nSCTHits;
    // std::vector<int>     *el_convtrk1nTRTHits;
    // std::vector<int>     *el_convtrk2nBLHits;
    // std::vector<int>     *el_convtrk2nPixHits;
    // std::vector<int>     *el_convtrk2nSCTHits;
    // std::vector<int>     *el_convtrk2nTRTHits;
    // std::vector<int>     *el_expectBLayerHit;
    // std::vector<int>     *el_goodOQ;
    // std::vector<int>     *el_hasconv;
    // std::vector<int>     *el_hastrack;
    // std::vector<int>     *el_isConv;
    // std::vector<int>     *el_loose;
    // std::vector<int>     *el_looseIso;
    // std::vector<int>     *el_loosePP;
    // std::vector<int>     *el_loosePPIso;
    // std::vector<int>     *el_maxEcell_gain;
    // std::vector<int>     *el_medium;
    // std::vector<int>     *el_mediumIso;
    // std::vector<int>     *el_mediumIsoWithoutTrack;
    // std::vector<int>     *el_mediumPPIso;
    // std::vector<int>     *el_mediumWithoutTrack;
    // std::vector<int>     *el_nBLHits;
    // std::vector<int>     *el_nBLSharedHits;
    // std::vector<int>     *el_nBLayerOutliers;
    // std::vector<int>     *el_nBLayerSplitHits;
    // std::vector<int>     *el_nContribPixelLayers;
    // std::vector<int>     *el_nConv;
    // std::vector<int>     *el_nDoubleTrackConv;
    // std::vector<int>     *el_nGangedFlaggedFakes;
    // std::vector<int>     *el_nGangedPixels;
    // std::vector<int>     *el_nGoodHitsPixeldEdx;
    // std::vector<int>     *el_nPixHits;
    // std::vector<int>     *el_nPixHoles;
    // std::vector<int>     *el_nPixSharedHits;
    // std::vector<int>     *el_nPixSplitHits;
    // std::vector<int>     *el_nPixelDeadSensors;
    // std::vector<int>     *el_nPixelOutliers;
    // std::vector<int>     *el_nPixelSpoiltHits;
    // std::vector<int>     *el_nSCTDeadSensors;
    // std::vector<int>     *el_nSCTDoubleHoles;
    // std::vector<int>     *el_nSCTHits;
    // std::vector<int>     *el_nSCTHoles;
    // std::vector<int>     *el_nSCTOutliers;
    // std::vector<int>     *el_nSCTSharedHits;
    // std::vector<int>     *el_nSCTSpoiltHits;
    // std::vector<int>     *el_nSingleTrackConv;
    // std::vector<int>     *el_nTRTHighTHits;
    // std::vector<int>     *el_nTRTHighTOutliers;
    // std::vector<int>     *el_nTRTHits;
    // std::vector<int>     *el_nTRTHoles;
    // std::vector<int>     *el_nTRTOutliers;
    // std::vector<int>     *el_nTRTXenonHits;
    // std::vector<int>     *el_nucone20_trk500MeV;
    // std::vector<int>     *el_nucone30_trk500MeV;
    // std::vector<int>     *el_nucone40_trk500MeV;
    // std::vector<int>     *el_originbkg;
    // std::vector<int>     *el_refittedTrack_n;
    // std::vector<int>     *el_tight;
    // std::vector<int>     *el_tightIso;
    // std::vector<int>     *el_tightIsoWithoutTrack;
    // std::vector<int>     *el_tightPPIso;
    // std::vector<int>     *el_tightWithoutTrack;
    // std::vector<int>     *el_truth_hasHardBrem;
    // std::vector<int>     *el_truth_index;
    // std::vector<int>     *el_truth_matched;
    // std::vector<int>     *el_truth_mothertype;
    // std::vector<int>     *el_truth_status;
    // std::vector<int>     *el_truth_type;
    // std::vector<int>     *el_typebkg;
    // std::vector<int>     *jet_AntiKt4LCTopo_Nconst;
    // std::vector<int>     *jet_AntiKt4LCTopo_bbDecision;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_assoctrk_n;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_ip2d_isValid;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_ip2d_ntrk;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_ip3d_isValid;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_ip3d_ntrk;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_jfit_isValid;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_jfit_ntrkAtVx;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_jfit_nvtx1t;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_jfit_nvtx;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_jfitc_isValid;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_jfitcomb_isValid;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_sv0p_isValid;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_sv0p_n2t;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_sv0p_ndof;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_sv0p_ntrk;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_sv0p_ntrkj;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_sv0p_ntrkv;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_sv1_isValid;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_sv2_isValid;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_svp_isValid;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_svp_n2t;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_svp_ndof;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_svp_ntrk;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_svp_ntrkj;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_component_svp_ntrkv;
    // std::vector<int>     *jet_AntiKt4LCTopo_flavor_truth_BHadronpdg;
    // std::vector<int>     *jet_AntiKt4LCTopo_isBadLoose;
    // std::vector<int>     *jet_AntiKt4LCTopo_isBadLooseMinus;
    // std::vector<int>     *jet_AntiKt4LCTopo_isBadMedium;
    // std::vector<int>     *jet_AntiKt4LCTopo_isBadTight;
    // std::vector<int>     *jet_AntiKt4LCTopo_isUgly;
    // std::vector<int>     *jet_AntiKt4TruthJets_SamplingMax;
    // std::vector<int>     *jet_AntiKt4TruthJets_flavor_truth_BHadronpdg;
    // std::vector<int>     *jet_AntiKt4TruthJets_flavor_truth_label;
    // std::vector<int>     *jet_AntiKt4TruthJets_isBadLoose;
    // std::vector<int>     *jet_AntiKt4TruthJets_isBadLooseMinus;
    // std::vector<int>     *jet_AntiKt4TruthJets_isBadMedium;
    // std::vector<int>     *jet_AntiKt4TruthJets_isBadTight;
    // std::vector<int>     *jet_AntiKt4TruthJets_isUgly;
    // std::vector<int>     *mcevt_event_number;
    // std::vector<int>     *mcevt_nparticle;
    // std::vector<int>     *mcevt_pdf_id1;
    // std::vector<int>     *mcevt_pdf_id2;
    // std::vector<int>     *mcevt_signal_process_id;
    // std::vector<int>     *mu_staco_EFCB_index;
    // std::vector<int>     *mu_staco_EFME_index;
    // std::vector<int>     *mu_staco_EFMG_index;
    // std::vector<int>     *mu_staco_alsoFoundByCaloMuonId;
    // std::vector<int>     *mu_staco_alsoFoundByLowPt;
    // std::vector<int>     *mu_staco_author;
    // std::vector<int>     *mu_staco_barrelSectors;
    // std::vector<int>     *mu_staco_bestMatch;
    // std::vector<int>     *mu_staco_endcapSectors;
    // std::vector<int>     *mu_staco_hastrack;
    // std::vector<int>     *mu_staco_isCaloMuonId;
    // std::vector<int>     *mu_staco_isLowPtReconstructedMuon;
    // std::vector<int>     *mu_staco_isSiliconAssociatedForwardMuon;
    // std::vector<int>     *mu_staco_isStandAloneMuon;
    // std::vector<int>     *mu_staco_loose;
    // std::vector<int>     *mu_staco_matchndof;
    // std::vector<int>     *mu_staco_mc_index;
    // std::vector<int>     *mu_staco_medium;
    // std::vector<int>     *mu_staco_nBLSharedHits;
    // std::vector<int>     *mu_staco_nCSCEtaHits;
    // std::vector<int>     *mu_staco_nCSCEtaHoles;
    // std::vector<int>     *mu_staco_nCSCPhiHits;
    // std::vector<int>     *mu_staco_nCSCPhiHoles;
    // std::vector<int>     *mu_staco_nCSCUnspoiledEtaHits;
    // std::vector<int>     *mu_staco_nGangedPixels;
    // std::vector<int>     *mu_staco_nMDTBEEHits;
    // std::vector<int>     *mu_staco_nMDTBIHits;
    // std::vector<int>     *mu_staco_nMDTBIS78Hits;
    // std::vector<int>     *mu_staco_nMDTBMHits;
    // std::vector<int>     *mu_staco_nMDTBOHits;
    // std::vector<int>     *mu_staco_nMDTEEHits;
    // std::vector<int>     *mu_staco_nMDTEIHits;
    // std::vector<int>     *mu_staco_nMDTEMHits;
    // std::vector<int>     *mu_staco_nMDTEOHits;
    // std::vector<int>     *mu_staco_nMDTHits;
    // std::vector<int>     *mu_staco_nMDTHoles;
    // std::vector<int>     *mu_staco_nOutliersOnTrack;
    // std::vector<int>     *mu_staco_nPixSharedHits;
    // std::vector<int>     *mu_staco_nPixelDeadSensors;
    // std::vector<int>     *mu_staco_nRPCEtaHits;
    // std::vector<int>     *mu_staco_nRPCEtaHoles;
    // std::vector<int>     *mu_staco_nRPCLayer1EtaHits;
    // std::vector<int>     *mu_staco_nRPCLayer1PhiHits;
    // std::vector<int>     *mu_staco_nRPCLayer2EtaHits;
    // std::vector<int>     *mu_staco_nRPCLayer2PhiHits;
    // std::vector<int>     *mu_staco_nRPCLayer3EtaHits;
    // std::vector<int>     *mu_staco_nRPCLayer3PhiHits;
    // std::vector<int>     *mu_staco_nRPCPhiHits;
    // std::vector<int>     *mu_staco_nRPCPhiHoles;
    // std::vector<int>     *mu_staco_nSCTSharedHits;
    // std::vector<int>     *mu_staco_nTGCEtaHits;
    // std::vector<int>     *mu_staco_nTGCEtaHoles;
    // std::vector<int>     *mu_staco_nTGCLayer1EtaHits;
    // std::vector<int>     *mu_staco_nTGCLayer1PhiHits;
    // std::vector<int>     *mu_staco_nTGCLayer2EtaHits;
    // std::vector<int>     *mu_staco_nTGCLayer2PhiHits;
    // std::vector<int>     *mu_staco_nTGCLayer3EtaHits;
    // std::vector<int>     *mu_staco_nTGCLayer3PhiHits;
    // std::vector<int>     *mu_staco_nTGCLayer4EtaHits;
    // std::vector<int>     *mu_staco_nTGCLayer4PhiHits;
    // std::vector<int>     *mu_staco_nTGCPhiHits;
    // std::vector<int>     *mu_staco_nTGCPhiHoles;
    // std::vector<int>     *mu_staco_nTRTDeadStraws;
    // std::vector<int>     *mu_staco_nTRTHighTHits;
    // std::vector<int>     *mu_staco_nTRTHighTOutliers;
    // std::vector<int>     *mu_staco_nphiHoleLayers;
    // std::vector<int>     *mu_staco_nphiLayers;
    // std::vector<int>     *mu_staco_nprecisionHoleLayers;
    // std::vector<int>     *mu_staco_nprecisionLayers;
    // std::vector<int>     *mu_staco_ntrigEtaHoleLayers;
    // std::vector<int>     *mu_staco_ntrigEtaLayers;
    // std::vector<int>     *mu_staco_nucone20_trk500MeV;
    // std::vector<int>     *mu_staco_nucone20_trkelstyle;
    // std::vector<int>     *mu_staco_nucone30_trk500MeV;
    // std::vector<int>     *mu_staco_nucone30_trkelstyle;
    // std::vector<int>     *mu_staco_nucone40_trk500MeV;
    // std::vector<int>     *mu_staco_nucone40_trkelstyle;
    // std::vector<int>     *mu_staco_origin;
    // std::vector<int>     *mu_staco_tight;
    // std::vector<int>     *mu_staco_truth_matched;
    // std::vector<int>     *mu_staco_truth_mothertype;
    // std::vector<int>     *mu_staco_truth_status;
    // std::vector<int>     *mu_staco_truth_type;
    // std::vector<int>     *mu_staco_type;
    // std::vector<int>     *muonTruth_PDGID;
    std::vector<int>     *muonTruth_barcode;
    // std::vector<int>     *ph_author;
    // std::vector<int>     *ph_convFlag;
    // std::vector<int>     *ph_convtrk1nBLHits;
    // std::vector<int>     *ph_convtrk1nPixHits;
    // std::vector<int>     *ph_convtrk1nSCTHits;
    // std::vector<int>     *ph_convtrk1nTRTHits;
    // std::vector<int>     *ph_convtrk2nBLHits;
    // std::vector<int>     *ph_convtrk2nPixHits;
    // std::vector<int>     *ph_convtrk2nSCTHits;
    // std::vector<int>     *ph_convtrk2nTRTHits;
    // std::vector<int>     *ph_el_index;
    // std::vector<int>     *ph_goodOQ;
    // std::vector<int>     *ph_hasconv;
    // std::vector<int>     *ph_isConv;
    // std::vector<int>     *ph_isRecovered;
    // std::vector<int>     *ph_jet_matched;
    // std::vector<int>     *ph_loose;
    // std::vector<int>     *ph_looseAR;
    // std::vector<int>     *ph_looseARIso;
    // std::vector<int>     *ph_looseIso;
    // std::vector<int>     *ph_maxEcell_gain;
    // std::vector<int>     *ph_nConv;
    // std::vector<int>     *ph_nDoubleTrackConv;
    // std::vector<int>     *ph_nSingleTrackConv;
    // std::vector<int>     *ph_origin;
    // std::vector<int>     *ph_tight;
    // std::vector<int>     *ph_tightAR;
    // std::vector<int>     *ph_tightARIso;
    // std::vector<int>     *ph_tightIso;
    // std::vector<int>     *ph_truth_barcode;
    // std::vector<int>     *ph_truth_index;
    // std::vector<int>     *ph_truth_isBrem;
    // std::vector<int>     *ph_truth_isConv;
    // std::vector<int>     *ph_truth_isFromHardProc;
    // std::vector<int>     *ph_truth_isPhotonFromHardProc;
    // std::vector<int>     *ph_truth_matched;
    // std::vector<int>     *ph_truth_motherbarcode;
    // std::vector<int>     *ph_truth_mothertype;
    // std::vector<int>     *ph_truth_status;
    // std::vector<int>     *ph_truth_type;
    // std::vector<int>     *ph_type;
    // std::vector<int>     *ph_vx_n;
    // std::vector<int>     *tau_EF_matched;
    // std::vector<int>     *tau_L1_matched;
    // std::vector<int>     *tau_L2_matched;
    // std::vector<int>     *tau_RoIWord;
    // std::vector<int>     *tau_author;
    // std::vector<int>     *tau_electronVetoLoose;
    // std::vector<int>     *tau_electronVetoMedium;
    // std::vector<int>     *tau_electronVetoTight;
    // std::vector<int>     *tau_jet_SamplingMax;
    // std::vector<int>     *tau_jet_isBadLoose;
    // std::vector<int>     *tau_jet_isBadLooseMinus;
    // std::vector<int>     *tau_jet_isBadMedium;
    // std::vector<int>     *tau_jet_isBadTight;
    // std::vector<int>     *tau_jet_isUgly;
    // std::vector<int>     *tau_nLooseConvTrk;
    // std::vector<int>     *tau_nLooseTrk;
    // std::vector<int>     *tau_nOtherTrk;
    // std::vector<int>     *tau_nPi0;
    // std::vector<int>     *tau_nProng;
    // std::vector<int>     *tau_nProngLoose;
    // std::vector<int>     *tau_numTopoClusters;
    // std::vector<int>     *tau_otherTrk_atTJVA_n;
    // std::vector<int>     *tau_otherTrk_n;
    // std::vector<int>     *tau_out_track_n;
    // std::vector<int>     *tau_out_track_n_extended;
    // std::vector<int>     *tau_pantau_NChargedEFO;
    // std::vector<int>     *tau_pantau_NChargedQualifiedEFO;
    // std::vector<int>     *tau_pantau_NNeutralEFO;
    // std::vector<int>     *tau_pantau_isPanTauCandidate;
    // std::vector<int>     *tau_pi0_n;
    // std::vector<int>     *tau_seedCalo_nStrip;
    // std::vector<int>     *tau_seedCalo_nWideTrk;
    // std::vector<int>     *tau_seedCalo_numTrack;
    // std::vector<int>     *tau_seedCalo_track_n;
    // std::vector<int>     *tau_seedCalo_wideTrk_atTJVA_n;
    // std::vector<int>     *tau_seedCalo_wideTrk_n;
    // std::vector<int>     *tau_seedTrk_nIsolTrk;
    // std::vector<int>     *tau_seedTrk_nOtherCoreTrk;
    // std::vector<int>     *tau_seedTrk_nStrip;
    // std::vector<int>     *tau_tauLlhLoose;
    // std::vector<int>     *tau_tauLlhMedium;
    // std::vector<int>     *tau_tauLlhTight;
    // std::vector<int>     *tau_track_atTJVA_n;
    // std::vector<int>     *tau_track_n;
    // std::vector<int>     *tau_trueTauAssocSmall_index;
    // std::vector<int>     *tau_trueTauAssocSmall_matched;
    // std::vector<int>     *trig_EF_bjet_roiId;
    // std::vector<int>     *trig_EF_bjet_valid;
    // std::vector<int>     *trig_EF_bjet_vertex_algorithmId;
    // std::vector<int>     *trig_EF_bjet_vertex_nDoF;
    // std::vector<int>     *trig_EF_bjet_vertex_nTwoTrackSecVtx;
    // std::vector<int>     *trig_EF_el_EF_2e12Tvh_loose1
    // std::vector<int>     *trig_EF_el_EF_2e5_tight1_Jpsi;
    // std::vector<int>     *trig_EF_el_EF_2e7T_loose1_mu6;
    // std::vector<int>     *trig_EF_el_EF_2e7T_medium1_mu6;
    // std::vector<int>     *trig_EF_el_EF_e11_etcut;
    // std::vector<int>     *trig_EF_el_EF_e12Tvh_loose1_mu8;
    // std::vector<int>     *trig_EF_el_EF_e12Tvh_medium1_mu10;
    // std::vector<int>     *trig_EF_el_EF_e12Tvh_medium1_mu6;
    // std::vector<int>     *trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium;
    // std::vector<int>     *trig_EF_el_EF_e12Tvh_medium1_mu8;
    // std::vector<int>     *trig_EF_el_EF_e13_etcutTrk_xs60;
    // std::vector<int>     *trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20;
    // std::vector<int>     *trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi;
    // std::vector<int>     *trig_EF_el_EF_e15vh_medium1;
    // std::vector<int>     *trig_EF_el_EF_e18_loose1;
    // std::vector<int>     *trig_EF_el_EF_e18_loose1_g25_medium;
    // std::vector<int>     *trig_EF_el_EF_e18_loose1_g35_loose;
    // std::vector<int>     *trig_EF_el_EF_e18_loose1_g35_medium;
    // std::vector<int>     *trig_EF_el_EF_e18_medium1;
    // std::vector<int>     *trig_EF_el_EF_e18_medium1_g25_loose;
    // std::vector<int>     *trig_EF_el_EF_e18_medium1_g25_medium;
    // std::vector<int>     *trig_EF_el_EF_e18_medium1_g35_loose;
    // std::vector<int>     *trig_EF_el_EF_e18_medium1_g35_medium;
    // std::vector<int>     *trig_EF_el_EF_e18vh_medium1;
    // std::vector<int>     *trig_EF_el_EF_e18vh_medium1_2e7T_medium1;
    // std::vector<int>     *trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20;
    // std::vector<int>     *trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20;
    // std::vector<int>     *trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi;
    // std::vector<int>     *trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi;
    // std::vector<int>     *trig_EF_el_EF_e22vh_loose0;
    // std::vector<int>     *trig_EF_el_EF_e22vh_loose1;
    // std::vector<int>     *trig_EF_el_EF_e22vh_loose;
    // std::vector<int>     *trig_EF_el_EF_e22vh_medium1;
    // std::vector<int>     *trig_EF_el_EF_e22vh_medium1_IDTrkNoCut;
    // std::vector<int>     *trig_EF_el_EF_e22vh_medium1_IdScan;
    // std::vector<int>     *trig_EF_el_EF_e22vh_medium1_SiTrk;
    // std::vector<int>     *trig_EF_el_EF_e22vh_medium1_TRT;
    // std::vector<int>     *trig_EF_el_EF_e22vhi_medium1;
    // std::vector<int>     *trig_EF_el_EF_e24vh_loose0;
    // std::vector<int>     *trig_EF_el_EF_e24vh_loose1;
    // std::vector<int>     *trig_EF_el_EF_e24vh_loose;
    // std::vector<int>     *trig_EF_el_EF_e24vh_medium1_EFxe30;
    // std::vector<int>     *trig_EF_el_EF_e24vh_medium1_EFxe30_tcem;
    // std::vector<int>     *trig_EF_el_EF_e24vh_medium1_EFxe35_tcem;
    // std::vector<int>     *trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw;
    // std::vector<int>     *trig_EF_el_EF_e24vh_medium1_EFxe40;
    // std::vector<int>     *trig_EF_el_EF_e24vh_medium1_IDTrkNoCut;
    // std::vector<int>     *trig_EF_el_EF_e24vh_medium1_IdScan;
    // std::vector<int>     *trig_EF_el_EF_e24vh_medium1_L2StarB;
    // std::vector<int>     *trig_EF_el_EF_e24vh_medium1_L2StarC;
    // std::vector<int>     *trig_EF_el_EF_e24vh_medium1_SiTrk;
    // std::vector<int>     *trig_EF_el_EF_e24vh_medium1_TRT;
    // std::vector<int>     *trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad;
    // std::vector<int>     *trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee;
    // std::vector<int>     *trig_EF_el_EF_e24vhi_loose1_mu8;
    // std::vector<int>     *trig_EF_el_EF_e24vhi_medium1;
    // std::vector<int>     *trig_EF_el_EF_e45_etcut;
    // std::vector<int>     *trig_EF_el_EF_e45_medium1;
    // std::vector<int>     *trig_EF_el_EF_e5_tight1;
    // std::vector<int>     *trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi;
    // std::vector<int>     *trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi;
    // std::vector<int>     *trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan;
    // std::vector<int>     *trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB;
    // std::vector<int>     *trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC;
    // std::vector<int>     *trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk;
    // std::vector<int>     *trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT;
    // std::vector<int>     *trig_EF_el_EF_e5_tight1_e5_NoCut;
    // std::vector<int>     *trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi;
    // std::vector<int>     *trig_EF_el_EF_e60_etcut;
    // std::vector<int>     *trig_EF_el_EF_e60_medium1;
    // std::vector<int>     *trig_EF_el_EF_e7T_loose1;
    // std::vector<int>     *trig_EF_el_EF_e7T_loose1_2mu6;
    // std::vector<int>     *trig_EF_el_EF_e7T_medium1_2mu6;
    // std::vector<int>     *trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi;
    // std::vector<int>     *trig_EF_el_EF_eb_physics;
    // std::vector<int>     *trig_EF_el_EF_eb_physics_empty;
    // std::vector<int>     *trig_EF_el_EF_eb_physics_firstempty;
    // std::vector<int>     *trig_EF_el_EF_eb_physics_noL1PS;
    // std::vector<int>     *trig_EF_el_EF_eb_physics_unpaired_iso;
    // std::vector<int>     *trig_EF_el_EF_eb_physics_unpaired_noniso;
    // std::vector<int>     *trig_EF_el_EF_eb_random;
    // std::vector<int>     *trig_EF_el_EF_eb_random_empty;
    // std::vector<int>     *trig_EF_el_EF_eb_random_firstempty;
    // std::vector<int>     *trig_EF_el_EF_eb_random_unpaired_iso;
    // std::vector<int>     *trig_EF_el_author;
    // std::vector<int>     *trig_EF_el_expectBLayerHit;
    // std::vector<int>     *trig_EF_el_hastrack;
    // std::vector<int>     *trig_EF_el_loose;
    // std::vector<int>     *trig_EF_el_looseIso;
    // std::vector<int>     *trig_EF_el_loosePP;
    // std::vector<int>     *trig_EF_el_loosePPIso;
    // std::vector<int>     *trig_EF_el_medium;
    // std::vector<int>     *trig_EF_el_mediumIso;
    // std::vector<int>     *trig_EF_el_mediumIsoWithoutTrack;
    // std::vector<int>     *trig_EF_el_mediumPP;
    // std::vector<int>     *trig_EF_el_mediumPPIso;
    // std::vector<int>     *trig_EF_el_mediumWithoutTrack;
    // std::vector<int>     *trig_EF_el_nBLHits;
    // std::vector<int>     *trig_EF_el_nBLSharedHits;
    // std::vector<int>     *trig_EF_el_nBLayerOutliers;
    // std::vector<int>     *trig_EF_el_nBLayerSplitHits;
    // std::vector<int>     *trig_EF_el_nGoodHitsPixeldEdx;
    // std::vector<int>     *trig_EF_el_nPixHits;
    // std::vector<int>     *trig_EF_el_nPixHoles;
    // std::vector<int>     *trig_EF_el_nPixSharedHits;
    // std::vector<int>     *trig_EF_el_nPixSplitHits;
    // std::vector<int>     *trig_EF_el_nPixelDeadSensors;
    // std::vector<int>     *trig_EF_el_nPixelOutliers;
    // std::vector<int>     *trig_EF_el_nSCTDeadSensors;
    // std::vector<int>     *trig_EF_el_nSCTHits;
    // std::vector<int>     *trig_EF_el_nSCTHoles;
    // std::vector<int>     *trig_EF_el_nSCTOutliers;
    // std::vector<int>     *trig_EF_el_nSCTSharedHits;
    // std::vector<int>     *trig_EF_el_nSiHits;
    // std::vector<int>     *trig_EF_el_nTRTHighTHits;
    // std::vector<int>     *trig_EF_el_nTRTHighTOutliers;
    // std::vector<int>     *trig_EF_el_nTRTHits;
    // std::vector<int>     *trig_EF_el_nTRTHoles;
    // std::vector<int>     *trig_EF_el_nTRTOutliers;
    // std::vector<int>     *trig_EF_el_nTRTXenonHits;
    // std::vector<int>     *trig_EF_el_tight;
    // std::vector<int>     *trig_EF_el_tightIso;
    // std::vector<int>     *trig_EF_el_tightIsoWithoutTrack;
    // std::vector<int>     *trig_EF_el_tightPP;
    // std::vector<int>     *trig_EF_el_tightPPIso;
    // std::vector<int>     *trig_EF_el_tightWithoutTrack;
    // std::vector<int>     *trig_EF_jet_a10tc;
    // std::vector<int>     *trig_EF_jet_a2hi;
    // std::vector<int>     *trig_EF_jet_a4tc;
    // std::vector<int>     *trig_EF_ph_EF_2g15vh_loose_g10_loose;
    // std::vector<int>     *trig_EF_ph_EF_2g15vh_medium;
    // std::vector<int>     *trig_EF_ph_EF_2g15vh_medium_g10_medium;
    // std::vector<int>     *trig_EF_ph_EF_2g20_loose;
    // std::vector<int>     *trig_EF_ph_EF_2g20vh_medium;
    // std::vector<int>     *trig_EF_ph_EF_2g30_loose;
    // std::vector<int>     *trig_EF_ph_EF_2g40_loose;
    // std::vector<int>     *trig_EF_ph_EF_g100_loose;
    // std::vector<int>     *trig_EF_ph_EF_g10_NoCut_cosmic;
    // std::vector<int>     *trig_EF_ph_EF_g10_loose;
    // std::vector<int>     *trig_EF_ph_EF_g10_medium;
    // std::vector<int>     *trig_EF_ph_EF_g120_loose;
    // std::vector<int>     *trig_EF_ph_EF_g12Tvh_loose;
    // std::vector<int>     *trig_EF_ph_EF_g12Tvh_loose_larcalib;
    // std::vector<int>     *trig_EF_ph_EF_g12Tvh_medium;
    // std::vector<int>     *trig_EF_ph_EF_g15_loose;
    // std::vector<int>     *trig_EF_ph_EF_g15vh_loose;
    // std::vector<int>     *trig_EF_ph_EF_g15vh_medium;
    // std::vector<int>     *trig_EF_ph_EF_g200_etcut;
    // std::vector<int>     *trig_EF_ph_EF_g20Tvh_medium;
    // std::vector<int>     *trig_EF_ph_EF_g20_etcut;
    // std::vector<int>     *trig_EF_ph_EF_g20_loose;
    // std::vector<int>     *trig_EF_ph_EF_g20_loose_larcalib;
    // std::vector<int>     *trig_EF_ph_EF_g20_medium;
    // std::vector<int>     *trig_EF_ph_EF_g20vh_medium;
    // std::vector<int>     *trig_EF_ph_EF_g30_loose_g20_loose;
    // std::vector<int>     *trig_EF_ph_EF_g30_medium_g20_medium;
    // std::vector<int>     *trig_EF_ph_EF_g35_loose_g25_loose;
    // std::vector<int>     *trig_EF_ph_EF_g35_loose_g30_loose;
    // std::vector<int>     *trig_EF_ph_EF_g40_loose;
    // std::vector<int>     *trig_EF_ph_EF_g40_loose_EFxe50;
    // std::vector<int>     *trig_EF_ph_EF_g40_loose_L2EFxe50;
    // std::vector<int>     *trig_EF_ph_EF_g40_loose_L2EFxe60;
    // std::vector<int>     *trig_EF_ph_EF_g40_loose_L2EFxe60_tclcw;
    // std::vector<int>     *trig_EF_ph_EF_g40_loose_g25_loose;
    // std::vector<int>     *trig_EF_ph_EF_g40_loose_g30_loose;
    // std::vector<int>     *trig_EF_ph_EF_g40_loose_larcalib;
    // std::vector<int>     *trig_EF_ph_EF_g5_NoCut_cosmic;
    // std::vector<int>     *trig_EF_ph_EF_g60_loose;
    // std::vector<int>     *trig_EF_ph_EF_g60_loose_larcalib;
    // std::vector<int>     *trig_EF_ph_EF_g80_loose;
    // std::vector<int>     *trig_EF_ph_EF_g80_loose_larcalib;
    // std::vector<int>     *trig_EF_ph_author;
    // std::vector<int>     *trig_EF_ph_convFlag;
    // std::vector<int>     *trig_EF_ph_convtrk1nBLHits;
    // std::vector<int>     *trig_EF_ph_convtrk1nPixHits;
    // std::vector<int>     *trig_EF_ph_convtrk1nSCTHits;
    // std::vector<int>     *trig_EF_ph_convtrk1nTRTHits;
    // std::vector<int>     *trig_EF_ph_convtrk2nBLHits;
    // std::vector<int>     *trig_EF_ph_convtrk2nPixHits;
    // std::vector<int>     *trig_EF_ph_convtrk2nSCTHits;
    // std::vector<int>     *trig_EF_ph_convtrk2nTRTHits;
    // std::vector<int>     *trig_EF_ph_hasconv;
    // std::vector<int>     *trig_EF_ph_isConv;
    // std::vector<int>     *trig_EF_ph_isRecovered;
    // std::vector<int>     *trig_EF_ph_loose;
    // std::vector<int>     *trig_EF_ph_looseAR;
    // std::vector<int>     *trig_EF_ph_looseARIso;
    // std::vector<int>     *trig_EF_ph_looseIso;
    // std::vector<int>     *trig_EF_ph_nConv;
    // std::vector<int>     *trig_EF_ph_nDoubleTrackConv;
    // std::vector<int>     *trig_EF_ph_nSingleTrackConv;
    // std::vector<int>     *trig_EF_ph_tight;
    // std::vector<int>     *trig_EF_ph_tightAR;
    // std::vector<int>     *trig_EF_ph_tightARIso;
    // std::vector<int>     *trig_EF_ph_tightIso;
    // std::vector<int>     *trig_EF_pv_type;
    // std::vector<int>     *trig_EF_tau_EF_2tau29T_medium1;
    // std::vector<int>     *trig_EF_tau_EF_2tau29_medium1;
    // std::vector<int>     *trig_EF_tau_EF_2tau29i_medium1;
    // std::vector<int>     *trig_EF_tau_EF_2tau38T_medium1;
    // std::vector<int>     *trig_EF_tau_EF_2tau38T_medium1_llh;
    // std::vector<int>     *trig_EF_tau_EF_2tau38T_medium;
    // std::vector<int>     *trig_EF_tau_EF_tau125_IDTrkNoCut;
    // std::vector<int>     *trig_EF_tau_EF_tau125_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau125_medium1_L2StarA;
    // std::vector<int>     *trig_EF_tau_EF_tau125_medium1_L2StarB;
    // std::vector<int>     *trig_EF_tau_EF_tau125_medium1_L2StarC;
    // std::vector<int>     *trig_EF_tau_EF_tau125_medium1_llh;
    // std::vector<int>     *trig_EF_tau_EF_tau20T_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau20T_medium1_e15vh_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau20T_medium1_mu15i;
    // std::vector<int>     *trig_EF_tau_EF_tau20T_medium;
    // std::vector<int>     *trig_EF_tau_EF_tau20T_medium_mu15;
    // std::vector<int>     *trig_EF_tau_EF_tau20Ti_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau20Ti_medium1_e18vh_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau20Ti_medium1_llh_e18vh_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau20Ti_medium;
    // std::vector<int>     *trig_EF_tau_EF_tau20Ti_medium_e18vh_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau20Ti_tight1;
    // std::vector<int>     *trig_EF_tau_EF_tau20Ti_tight1_llh;
    // std::vector<int>     *trig_EF_tau_EF_tau20_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau20_medium1_llh;
    // std::vector<int>     *trig_EF_tau_EF_tau20_medium1_llh_mu15;
    // std::vector<int>     *trig_EF_tau_EF_tau20_medium1_mu15;
    // std::vector<int>     *trig_EF_tau_EF_tau20_medium1_mu15i;
    // std::vector<int>     *trig_EF_tau_EF_tau20_medium1_mu18;
    // std::vector<int>     *trig_EF_tau_EF_tau20_medium;
    // std::vector<int>     *trig_EF_tau_EF_tau20_medium_llh;
    // std::vector<int>     *trig_EF_tau_EF_tau20_medium_mu15;
    // std::vector<int>     *trig_EF_tau_EF_tau29T_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau29T_medium1_tau20T_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau29T_medium1_xe40_tight;
    // std::vector<int>     *trig_EF_tau_EF_tau29T_medium1_xe45_tight;
    // std::vector<int>     *trig_EF_tau_EF_tau29T_medium;
    // std::vector<int>     *trig_EF_tau_EF_tau29T_medium_xe40_tight;
    // std::vector<int>     *trig_EF_tau_EF_tau29T_medium_xe45_tight;
    // std::vector<int>     *trig_EF_tau_EF_tau29T_tight1;
    // std::vector<int>     *trig_EF_tau_EF_tau29T_tight1_llh;
    // std::vector<int>     *trig_EF_tau_EF_tau29Ti_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau29Ti_medium1_llh_tau20Ti_medium1_llh;
    // std::vector<int>     *trig_EF_tau_EF_tau29Ti_medium1_llh_xe40_tight;
    // std::vector<int>     *trig_EF_tau_EF_tau29Ti_medium1_llh_xe45_tight;
    // std::vector<int>     *trig_EF_tau_EF_tau29Ti_medium1_tau20Ti_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau29Ti_medium1_xe40_tight;
    // std::vector<int>     *trig_EF_tau_EF_tau29Ti_medium1_xe45_tight;
    // std::vector<int>     *trig_EF_tau_EF_tau29Ti_medium1_xe55_tclcw;
    // std::vector<int>     *trig_EF_tau_EF_tau29Ti_medium1_xe55_tclcw_tight;
    // std::vector<int>     *trig_EF_tau_EF_tau29Ti_medium_xe40_tight;
    // std::vector<int>     *trig_EF_tau_EF_tau29Ti_medium_xe45_tight;
    // std::vector<int>     *trig_EF_tau_EF_tau29Ti_tight1;
    // std::vector<int>     *trig_EF_tau_EF_tau29Ti_tight1_llh;
    // std::vector<int>     *trig_EF_tau_EF_tau29Ti_tight1_llh_tau20Ti_tight1_llh;
    // std::vector<int>     *trig_EF_tau_EF_tau29Ti_tight1_tau20Ti_tight1;
    // std::vector<int>     *trig_EF_tau_EF_tau29_IDTrkNoCut;
    // std::vector<int>     *trig_EF_tau_EF_tau29_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau29_medium1_llh;
    // std::vector<int>     *trig_EF_tau_EF_tau29_medium;
    // std::vector<int>     *trig_EF_tau_EF_tau29_medium_2stTest;
    // std::vector<int>     *trig_EF_tau_EF_tau29_medium_L2StarA;
    // std::vector<int>     *trig_EF_tau_EF_tau29_medium_L2StarB;
    // std::vector<int>     *trig_EF_tau_EF_tau29_medium_L2StarC;
    // std::vector<int>     *trig_EF_tau_EF_tau29_medium_llh;
    // std::vector<int>     *trig_EF_tau_EF_tau29i_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau29i_medium;
    // std::vector<int>     *trig_EF_tau_EF_tau38T_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau38T_medium1_e18vh_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau38T_medium1_llh_e18vh_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau38T_medium1_xe40_tight;
    // std::vector<int>     *trig_EF_tau_EF_tau38T_medium1_xe45_tight;
    // std::vector<int>     *trig_EF_tau_EF_tau38T_medium1_xe55_tclcw_tight;
    // std::vector<int>     *trig_EF_tau_EF_tau38T_medium;
    // std::vector<int>     *trig_EF_tau_EF_tau38T_medium_e18vh_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau50_medium1_e18vh_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tau50_medium;
    // std::vector<int>     *trig_EF_tau_EF_tau50_medium_e15vh_medium1;
    // std::vector<int>     *trig_EF_tau_EF_tauNoCut;
    // std::vector<int>     *trig_EF_tau_EF_tauNoCut_L1TAU40;
    // std::vector<int>     *trig_EF_tau_EF_tauNoCut_cosmic;
    // std::vector<int>     *trig_EF_tau_RoIWord;
    // std::vector<int>     *trig_EF_tau_author;
    // std::vector<int>     *trig_EF_tau_nOtherTrk;
    // std::vector<int>     *trig_EF_tau_nProng;
    // std::vector<int>     *trig_EF_tau_numTopoClusters;
    // std::vector<int>     *trig_EF_tau_numTrack;
    // std::vector<int>     *trig_EF_tau_otherTrk_n;
    // std::vector<int>     *trig_EF_tau_seedCalo_nStrip;
    // std::vector<int>     *trig_EF_tau_seedCalo_nWideTrk;
    // std::vector<int>     *trig_EF_tau_seedCalo_numTrack;
    // std::vector<int>     *trig_EF_tau_seedCalo_track_n;
    // std::vector<int>     *trig_EF_tau_seedCalo_wideTrk_n;
    // std::vector<int>     *trig_EF_tau_track_n;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu10;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose_EMPTY;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu13;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu13_l2muonSA;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu15;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_2e5_tight1;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_Bmumu;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_Bmumux;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_DiMu;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_Jpsimumu;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_Upsimumu;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_xe50_tclcw;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_xe60;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu6;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu6_Bmumu;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu6_Bmumux;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu6_DiMu;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu6_DiMu_DY20;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu6_DiMu_DY25;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu6_Jpsimumu;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu6_Upsimumu;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu6i_DiMu_DY;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu8_EFxe30;
    // std::vector<int>     *trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu10;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu10_Jpsimumu;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu10_MSonly;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu10i_g10_loose;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu10i_g10_loose_TauMass;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu10i_g10_medium;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_loose;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_loose_TauMass;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu11_empty_NoAlg;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu15;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu18;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu18_2g10_loose;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu18_2g10_medium;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu18_2g15_loose;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu18_g20vh_loose;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu18_medium;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu18_tight_e7_medium1;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu18i4_tight;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu18it_tight;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu20i_tight_g5_loose;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu20i_tight_g5_medium;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu20it_tight;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_g20vh_loose;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_g20vh_medium;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_j65_a4tchad;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe50_tclcw;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_medium;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_tight;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_tight_2j35_a4tchad;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_tight_4j35_a4tchad;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_tight_EFxe40;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_tight_L2StarB;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_tight_L2StarC;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_tight_MG;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_tight_MuonEF;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24i_tight;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24i_tight_MG;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24i_tight_MuonEF;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu36_tight;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu40_slow_tight;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu40_tight;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_Trk_Jpsi;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_cosmic;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j360_a4tchad_L2FS_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j360_a4tchad_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_loose;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_loose_TauMass;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4Tmu6_DiMu;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4_empty_NoAlg;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu60_slow_tight1;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu6;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu6_MSonly;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu6i;
    // std::vector<int>     *trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS;
    // std::vector<int>     *trig_EF_trigmuonef_effs15;
    // std::vector<int>     *trig_EF_trigmuonef_effs18;
    // std::vector<int>     *trig_EF_trigmuonef_effs24;
    // std::vector<int>     *trig_EF_trigmuonef_track_n;
    // std::vector<int>     *trig_EF_trigmuonefisolation_efinfoMG_index;
    // std::vector<int>     *trig_EF_trigmuonefisolation_efinfo_index;
    // std::vector<int>     *trig_EF_trigmuonefisolation_trackPosition;
    // std::vector<int>     *trk_cone20_nTrackIso;
    // std::vector<int>     *trk_cone30_nTrackIso;
    // std::vector<int>     *trk_cone40_nTrackIso;
    // std::vector<int>     *trk_cone40_ptmin1gev_nTrackIso;
    // std::vector<int>     *trk_cone40_ptmin2gev_nTrackIso;
    // std::vector<int>     *trk_cone40_ptmin3gev_hitschi_nTrackIso;
    // std::vector<int>     *trk_cone40_ptmin3gev_nTrackIso;
    // std::vector<int>     *trk_cone40_ptmin4gev_nTrackIso;
    // std::vector<int>     *trk_cone40_ptmin5gev_nTrackIso;
    // std::vector<int>     *trk_expectBLayerHit;
    // std::vector<int>     *trk_hitPattern;
    // std::vector<int>     *trk_mc_barcode;
    // std::vector<int>     *trk_nBLHits;
    // std::vector<int>     *trk_nBLSharedHits;
    // std::vector<int>     *trk_nBLayerSplitHits;
    // std::vector<int>     *trk_nCSCEtaHits;
    // std::vector<int>     *trk_nCSCPhiHits;
    // std::vector<int>     *trk_nHits;
    // std::vector<int>     *trk_nHoles;
    // std::vector<int>     *trk_nMDTHits;
    // std::vector<int>     *trk_nPixHits;
    // std::vector<int>     *trk_nPixHoles;
    // std::vector<int>     *trk_nPixSharedHits;
    // std::vector<int>     *trk_nPixSplitHits;
    // std::vector<int>     *trk_nPixelDeadSensors;
    // std::vector<int>     *trk_nRPCEtaHits;
    // std::vector<int>     *trk_nRPCPhiHits;
    // std::vector<int>     *trk_nSCTDeadSensors;
    // std::vector<int>     *trk_nSCTHits;
    // std::vector<int>     *trk_nSCTHoles;
    // std::vector<int>     *trk_nSCTSharedHits;
    // std::vector<int>     *trk_nTGCEtaHits;
    // std::vector<int>     *trk_nTGCPhiHits;
    // std::vector<int>     *trk_nTRTHighTHits;
    // std::vector<int>     *trk_nTRTHits;
    // std::vector<int>     *trk_nTRTHoles;
    // std::vector<int>     *trk_nTRTXenonHits;
    // std::vector<int>     *trk_ndof;
    // std::vector<int>     *trueTau_nPi0;
    // std::vector<int>     *trueTau_nProng;
    // std::vector<int>     *trueTau_tauAssocSmall_index;
    // std::vector<int>     *trueTau_tauAssocSmall_matched;
    // std::vector<short>   *mcevt_pileUpType;
    // std::vector<short>   *trig_EF_feb_met_status;
    // std::vector<short>   *trig_EF_feb_met_sumOfSigns;
    // std::vector<short>   *trig_EF_jetetsum_status;
    // std::vector<short>   *trig_EF_jetetsum_sumOfSigns;
    // std::vector<short>   *trig_EF_met_status;
    // std::vector<short>   *trig_EF_met_sumOfSigns;
    // std::vector<short>   *trig_EF_passedPhysics;
    // std::vector<short>   *trig_EF_passedRaw;
    // std::vector<short>   *trig_EF_passedThrough;
    // std::vector<short>   *trig_EF_resurrected;
    // std::vector<short>   *trig_EF_topocl_met_status;
    // std::vector<short>   *trig_EF_topocl_met_sumOfSigns;
    // std::vector<short>   *trig_EF_wasPrescaled;
    // std::vector<short>   *trig_EF_wasResurrected;
    // std::vector<short>   *trig_Nav_chain_ChainId;
    // std::vector<std::string>  *SkimDecision_DAODEGAMMA_name;
    // std::vector<std::string>  *SkimDecision_DAODJETS_name;
    // std::vector<std::string>  *SkimDecision_DAODMUONS_name;
    // std::vector<std::string>  *SkimDecision_NTPSUSY_name;
    // std::vector<std::string>  *trig_EF_feb_met_nameOfComponent;
    // std::vector<std::string>  *trig_EF_jet_author;
    // std::vector<std::string>  *trig_EF_jet_calibtags;
    // std::vector<std::string>  *trig_EF_jetetsum_nameOfComponent;
    // std::vector<std::string>  *trig_EF_met_nameOfComponent;
    // std::vector<std::string>  *trig_EF_topocl_met_nameOfComponent;
    // std::vector<std::vector<double> > *jet_AntiKt4LCTopo_flavor_component_jfitc_doublePropValue;
    // std::vector<std::vector<double> > *mcevt_weight;
    // std::vector<std::vector<float> > *el_MET_wet;
    // std::vector<std::vector<float> > *el_MET_wpx;
    // std::vector<std::vector<float> > *el_MET_wpy;
    // std::vector<std::vector<float> > *el_likelihoodsPixeldEdx;
    // std::vector<std::vector<float> > *jet_AntiKt4LCTopo_MET_wet;
    // std::vector<std::vector<float> > *jet_AntiKt4LCTopo_MET_wpx;
    // std::vector<std::vector<float> > *jet_AntiKt4LCTopo_MET_wpy;
    // std::vector<std::vector<float> > *jet_AntiKt4LCTopo_econst_default;
    // std::vector<std::vector<float> > *jet_AntiKt4LCTopo_etaconst_default;
    // std::vector<std::vector<float> > *jet_AntiKt4LCTopo_jvtxfFull;
    // std::vector<std::vector<float> > *jet_AntiKt4LCTopo_phiconst_default;
    // std::vector<std::vector<float> > *jet_AntiKt4LCTopo_ptconst_default;
    // std::vector<std::vector<float> > *jet_AntiKt4LCTopo_weightconst_default;
    // std::vector<std::vector<float> > *mu_staco_MET_Egamma10NoTau_wet;
    // std::vector<std::vector<float> > *mu_staco_MET_Egamma10NoTau_wpx;
    // std::vector<std::vector<float> > *mu_staco_MET_Egamma10NoTau_wpy;
    // std::vector<std::vector<float> > *mu_staco_MET_wet;
    // std::vector<std::vector<float> > *mu_staco_MET_wpx;
    // std::vector<std::vector<float> > *mu_staco_MET_wpy;
    // std::vector<std::vector<float> > *ph_MET_Egamma10NoTau_wet;
    // std::vector<std::vector<float> > *ph_MET_Egamma10NoTau_wpx;
    // std::vector<std::vector<float> > *ph_MET_Egamma10NoTau_wpy;
    // std::vector<std::vector<float> > *ph_MET_wet;
    // std::vector<std::vector<float> > *ph_MET_wpx;
    // std::vector<std::vector<float> > *ph_MET_wpy;
    // std::vector<std::vector<float> > *tau_MET_wet;
    // std::vector<std::vector<float> > *tau_MET_wpx;
    // std::vector<std::vector<float> > *tau_MET_wpy;
    // std::vector<std::vector<float> > *tau_Pi0Cluster_eta;
    // std::vector<std::vector<float> > *tau_Pi0Cluster_phi;
    // std::vector<std::vector<float> > *tau_Pi0Cluster_pt;
    // std::vector<std::vector<float> > *tau_cluster_E;
    // std::vector<std::vector<float> > *tau_cluster_EMLayer2F;
    // std::vector<std::vector<float> > *tau_cluster_EMLayer3F;
    // std::vector<std::vector<float> > *tau_cluster_PreSamplerStripF;
    // std::vector<std::vector<float> > *tau_cluster_eta;
    // std::vector<std::vector<float> > *tau_cluster_eta_atTJVA;
    // std::vector<std::vector<float> > *tau_cluster_phi;
    // std::vector<std::vector<float> > *tau_cluster_phi_atTJVA;
    // std::vector<std::vector<float> > *tau_jet_shapeBins;
    // std::vector<std::vector<float> > *tau_seedCalo_wideTrk_atTJVA_d0;
    // std::vector<std::vector<float> > *tau_seedCalo_wideTrk_atTJVA_eta;
    // std::vector<std::vector<float> > *tau_seedCalo_wideTrk_atTJVA_phi;
    // std::vector<std::vector<float> > *tau_seedCalo_wideTrk_atTJVA_pt;
    // std::vector<std::vector<float> > *tau_seedCalo_wideTrk_atTJVA_qoverp;
    // std::vector<std::vector<float> > *tau_seedCalo_wideTrk_atTJVA_theta;
    // std::vector<std::vector<float> > *tau_seedCalo_wideTrk_atTJVA_z0;
    // std::vector<std::vector<float> > *tau_track_TRTHighTHitsRatio;
    // std::vector<std::vector<float> > *tau_track_TRTHighTOutliersRatio;
    // std::vector<std::vector<float> > *tau_track_atPV_d0;
    // std::vector<std::vector<float> > *tau_track_atPV_eta;
    // std::vector<std::vector<float> > *tau_track_atPV_phi;
    // std::vector<std::vector<float> > *tau_track_atPV_pt;
    // std::vector<std::vector<float> > *tau_track_atPV_qoverp;
    // std::vector<std::vector<float> > *tau_track_atPV_theta;
    // std::vector<std::vector<float> > *tau_track_atPV_z0;
    // std::vector<std::vector<float> > *tau_track_atTJVA_cov_d0;
    // std::vector<std::vector<float> > *tau_track_atTJVA_cov_d0_phi;
    // std::vector<std::vector<float> > *tau_track_atTJVA_cov_d0_qoverp;
    // std::vector<std::vector<float> > *tau_track_atTJVA_cov_d0_theta;
    // std::vector<std::vector<float> > *tau_track_atTJVA_cov_d0_z0;
    // std::vector<std::vector<float> > *tau_track_atTJVA_cov_phi;
    // std::vector<std::vector<float> > *tau_track_atTJVA_cov_phi_qoverp;
    // std::vector<std::vector<float> > *tau_track_atTJVA_cov_phi_theta;
    // std::vector<std::vector<float> > *tau_track_atTJVA_cov_qoverp;
    // std::vector<std::vector<float> > *tau_track_atTJVA_cov_theta;
    // std::vector<std::vector<float> > *tau_track_atTJVA_cov_theta_qoverp;
    // std::vector<std::vector<float> > *tau_track_atTJVA_cov_z0;
    // std::vector<std::vector<float> > *tau_track_atTJVA_cov_z0_phi;
    // std::vector<std::vector<float> > *tau_track_atTJVA_cov_z0_qoverp;
    // std::vector<std::vector<float> > *tau_track_atTJVA_cov_z0_theta;
    // std::vector<std::vector<float> > *tau_track_atTJVA_d0;
    // std::vector<std::vector<float> > *tau_track_atTJVA_err_d0;
    // std::vector<std::vector<float> > *tau_track_atTJVA_err_phi;
    // std::vector<std::vector<float> > *tau_track_atTJVA_err_qoverp;
    // std::vector<std::vector<float> > *tau_track_atTJVA_err_theta;
    // std::vector<std::vector<float> > *tau_track_atTJVA_err_z0;
    // std::vector<std::vector<float> > *tau_track_atTJVA_eta;
    // std::vector<std::vector<float> > *tau_track_atTJVA_phi;
    // std::vector<std::vector<float> > *tau_track_atTJVA_pt;
    // std::vector<std::vector<float> > *tau_track_atTJVA_qoverp;
    // std::vector<std::vector<float> > *tau_track_atTJVA_theta;
    // std::vector<std::vector<float> > *tau_track_atTJVA_z0;
    // std::vector<std::vector<float> > *tau_track_d0;
    // std::vector<std::vector<float> > *tau_track_eta;
    // std::vector<std::vector<float> > *tau_track_phi;
    // std::vector<std::vector<float> > *tau_track_pt;
    // std::vector<std::vector<float> > *tau_track_qoverp;
    // std::vector<std::vector<float> > *tau_track_theta;
    // std::vector<std::vector<float> > *tau_track_z0;
    // std::vector<std::vector<float> > *trig_EF_bjet_vertex_covariance;
    // std::vector<std::vector<float> > *trig_EF_el_likelihoodsPixeldEdx;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_charge;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_chi2;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_chi2prob;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_d0;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_matchChi2;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_posX;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_posY;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_posZ;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_CB_z0;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_MS_charge;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_MS_chi2;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_MS_chi2prob;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_MS_d0;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_MS_eta;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_MS_phi;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_MS_posX;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_MS_posY;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_MS_posZ;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_MS_pt;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_MS_z0;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_SA_charge;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_SA_chi2;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_SA_chi2prob;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_SA_d0;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_SA_eta;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_SA_phi;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_SA_posX;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_SA_posY;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_SA_posZ;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_SA_pt;
    // std::vector<std::vector<float> > *trig_EF_trigmuonef_track_SA_z0;
    // std::vector<std::vector<int> > *jet_AntiKt4LCTopo_flavor_assoctrk_index;
    // std::vector<std::vector<int> > *jet_AntiKt4LCTopo_flavor_component_jfitc_intPropValue;
    // std::vector<std::vector<int> > *ph_vx_convTrk_n;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_expectBLayerHit;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nBLHits;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nBLSharedHits;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nBLayerOutliers;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nBLayerSplitHits;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nContribPixelLayers;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nGangedFlaggedFakes;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nGangedPixels;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nHits;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nPixHits;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nPixHoles;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nPixSharedHits;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nPixSplitHits;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nPixelDeadSensors;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nPixelOutliers;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nPixelSpoiltHits;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nSCTDeadSensors;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nSCTDoubleHoles;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nSCTHits;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nSCTHoles;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nSCTOutliers;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nSCTSharedHits;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nSCTSpoiltHits;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nTRTHighTHits;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nTRTHighTOutliers;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nTRTHits;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nTRTHoles;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nTRTOutliers;
    // std::vector<std::vector<int> > *tau_seedCalo_wideTrk_nTRTXenonHits;
    // std::vector<std::vector<int> > *tau_track_expectBLayerHit;
    // std::vector<std::vector<int> > *tau_track_nBLHits;
    // std::vector<std::vector<int> > *tau_track_nBLSharedHits;
    // std::vector<std::vector<int> > *tau_track_nBLayerOutliers;
    // std::vector<std::vector<int> > *tau_track_nBLayerSplitHits;
    // std::vector<std::vector<int> > *tau_track_nContribPixelLayers;
    // std::vector<std::vector<int> > *tau_track_nGangedFlaggedFakes;
    // std::vector<std::vector<int> > *tau_track_nGangedPixels;
    // std::vector<std::vector<int> > *tau_track_nHits;
    // std::vector<std::vector<int> > *tau_track_nPixHits;
    // std::vector<std::vector<int> > *tau_track_nPixHoles;
    // std::vector<std::vector<int> > *tau_track_nPixSharedHits;
    // std::vector<std::vector<int> > *tau_track_nPixSplitHits;
    // std::vector<std::vector<int> > *tau_track_nPixelDeadSensors;
    // std::vector<std::vector<int> > *tau_track_nPixelOutliers;
    // std::vector<std::vector<int> > *tau_track_nPixelSpoiltHits;
    // std::vector<std::vector<int> > *tau_track_nSCTDeadSensors;
    // std::vector<std::vector<int> > *tau_track_nSCTDoubleHoles;
    // std::vector<std::vector<int> > *tau_track_nSCTHits;
    // std::vector<std::vector<int> > *tau_track_nSCTHoles;
    // std::vector<std::vector<int> > *tau_track_nSCTOutliers;
    // std::vector<std::vector<int> > *tau_track_nSCTSharedHits;
    // std::vector<std::vector<int> > *tau_track_nSCTSpoiltHits;
    // std::vector<std::vector<int> > *tau_track_nTRTHighTHits;
    // std::vector<std::vector<int> > *tau_track_nTRTHighTOutliers;
    // std::vector<std::vector<int> > *tau_track_nTRTHits;
    // std::vector<std::vector<int> > *tau_track_nTRTHoles;
    // std::vector<std::vector<int> > *tau_track_nTRTOutliers;
    // std::vector<std::vector<int> > *tau_track_nTRTXenonHits;
    // std::vector<std::vector<int> > *trig_EF_trigmuonef_track_MS_hasMS;
    // std::vector<std::vector<int> > *trig_EF_trigmuonef_track_MuonType;
    // std::vector<std::vector<int> > *trig_EF_trigmuonef_track_SA_hasSA;
    // std::vector<std::vector<int> > *trig_Nav_chain_RoIIndex;
    // std::vector<std::vector<int> > *trig_Nav_chain_RoIType;
    // std::vector<std::vector<std::string> > *jet_AntiKt4LCTopo_flavor_component_jfitc_doublePropName;
    // std::vector<std::vector<std::string> > *jet_AntiKt4LCTopo_flavor_component_jfitc_intPropName;
    // std::vector<std::vector<std::vector<float> > > *ph_vx_convTrk_weight;
    // std::vector<std::vector<unsigned int> > *el_MET_statusWord;
    // std::vector<std::vector<unsigned int> > *jet_AntiKt4LCTopo_MET_statusWord;
    // std::vector<std::vector<unsigned int> > *mu_staco_MET_Egamma10NoTau_statusWord;
    // std::vector<std::vector<unsigned int> > *mu_staco_MET_statusWord;
    // std::vector<std::vector<unsigned int> > *ph_MET_Egamma10NoTau_statusWord;
    // std::vector<std::vector<unsigned int> > *ph_MET_statusWord;
    // std::vector<std::vector<unsigned int> > *tau_MET_statusWord;
    // std::vector<unsigned int> *el_isEM;
    // std::vector<unsigned int> *el_isEMLoose;
    // std::vector<unsigned int> *el_isEMMedium;
    // std::vector<unsigned int> *el_isEMTight;
    // std::vector<unsigned int> *el_maxEcell_onlId;
    // std::vector<unsigned int> *ph_OQ;
    // std::vector<unsigned int> *ph_isEM;
    // std::vector<unsigned int> *ph_isEMLoose;
    // std::vector<unsigned int> *ph_isEMMedium;
    // std::vector<unsigned int> *ph_isEMTight;
    // std::vector<unsigned int> *ph_maxEcell_onlId;
    // std::vector<unsigned int> *tau_cluster_n;
    // std::vector<unsigned int> *tau_pantau_AbsSumCharge;
    // std::vector<unsigned int> *trig_EF_el_isEM;
    // std::vector<unsigned int> *trig_EF_el_isEMLoose;
    // std::vector<unsigned int> *trig_EF_el_isEMMedium;
    // std::vector<unsigned int> *trig_EF_el_isEMTight;
    // std::vector<unsigned int> *trig_EF_jet_RoIword;
    // std::vector<unsigned int> *trig_EF_ph_isEM;
    // std::vector<unsigned int> *trig_EF_ph_isEMLoose;
    // std::vector<unsigned int> *trig_EF_ph_isEMMedium;
    // std::vector<unsigned int> *trig_EF_ph_isEMTight;
    // std::vector<unsigned short> *mu_staco_allauthor;
    // std::vector<unsigned short> *mu_staco_caloMuonIdTag;
    // std::vector<unsigned short> *trig_EF_feb_met_usedChannels;
    // std::vector<unsigned short> *trig_EF_jetetsum_usedChannels;
    // std::vector<unsigned short> *trig_EF_met_usedChannels;
    // std::vector<unsigned short> *trig_EF_topocl_met_usedChannels;

    // List of branches
    TBranch        *b_EF_2e12Tvh_loose1;   //!
    TBranch        *b_EF_2mu13;   //!
    TBranch        *b_EF_e12Tvh_medium1_mu8;   //!
    TBranch        *b_EF_e24vh_medium1_e7_medium1;   //!
    TBranch        *b_EF_mu18_tight_e7_medium1;   //!
    TBranch        *b_EF_mu18_tight_mu8_EFFS;   //!
    TBranch        *b_EventNumber;   //!
    TBranch        *b_Eventshape_rhoKt4LC;   //!
    TBranch        *b_MET_Egamma10NoTau_CellOut_etx;   //!
    TBranch        *b_MET_Egamma10NoTau_CellOut_ety;   //!
    TBranch        *b_MET_Egamma10NoTau_CellOut_sumet;   //!
    TBranch        *b_MET_Egamma10NoTau_RefGamma_etx;   //!
    TBranch        *b_MET_Egamma10NoTau_RefGamma_ety;   //!
    TBranch        *b_MET_Egamma10NoTau_RefGamma_sumet;   //!
    TBranch        *b_RunNumber;   //!
    TBranch        *b_averageIntPerXing;   //!
    TBranch        *b_coreFlags;   //!
    TBranch        *b_el_MET_Egamma10NoTau_statusWord;   //!
    TBranch        *b_el_MET_Egamma10NoTau_wet;   //!
    TBranch        *b_el_MET_Egamma10NoTau_wpx;   //!
    TBranch        *b_el_MET_Egamma10NoTau_wpy;   //!
    TBranch        *b_el_OQ;   //!
    TBranch        *b_el_author;   //!
    TBranch        *b_el_charge;   //!
    TBranch        *b_el_cl_E;   //!
    TBranch        *b_el_cl_eta;   //!
    TBranch        *b_el_cl_phi;   //!
    TBranch        *b_el_cl_pt;   //!
    TBranch        *b_el_mediumPP;   //!
    TBranch        *b_el_n;   //!
    TBranch        *b_el_nSiHits;   //!
    TBranch        *b_el_origin;   //!
    TBranch        *b_el_ptcone30;   //!
    TBranch        *b_el_tightPP;   //!
    TBranch        *b_el_truth_barcode;   //!
    TBranch        *b_el_truth_motherbarcode;   //!
    TBranch        *b_el_topoEtcone30_corrected;   //!
    TBranch        *b_el_trackIPEstimate_d0_unbiasedpvunbiased;   //!
    TBranch        *b_el_trackIPEstimate_sigd0_unbiasedpvunbiased;   //!
    TBranch        *b_el_trackIPEstimate_z0_unbiasedpvunbiased;   //!
    TBranch        *b_el_tracketa;   //!
    TBranch        *b_el_trackphi;   //!
    TBranch        *b_el_type;   //!
    TBranch        *b_jet_AntiKt4LCTopo_ActiveAreaE;   //!
    TBranch        *b_jet_AntiKt4LCTopo_ActiveAreaPx;   //!
    TBranch        *b_jet_AntiKt4LCTopo_ActiveAreaPy;   //!
    TBranch        *b_jet_AntiKt4LCTopo_ActiveAreaPz;   //!
    TBranch        *b_jet_AntiKt4LCTopo_AverageLArQF;   //!
    TBranch        *b_jet_AntiKt4LCTopo_BCH_CORR_JET;   //!
    TBranch        *b_jet_AntiKt4LCTopo_HECQuality;   //!
    TBranch        *b_jet_AntiKt4LCTopo_LArQuality;   //!
    TBranch        *b_jet_AntiKt4LCTopo_MET_Egamma10NoTau_statusWord;   //!
    TBranch        *b_jet_AntiKt4LCTopo_MET_Egamma10NoTau_wet;   //!
    TBranch        *b_jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpx;   //!
    TBranch        *b_jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpy;   //!
    TBranch        *b_jet_AntiKt4LCTopo_NegativeE;   //!
    TBranch        *b_jet_AntiKt4LCTopo_SamplingMax;   //!
    TBranch        *b_jet_AntiKt4LCTopo_constscale_E;   //!
    TBranch        *b_jet_AntiKt4LCTopo_constscale_eta;   //!
    TBranch        *b_jet_AntiKt4LCTopo_constscale_m;   //!
    TBranch        *b_jet_AntiKt4LCTopo_constscale_phi;   //!
    TBranch        *b_jet_AntiKt4LCTopo_emfrac;   //!
    TBranch        *b_jet_AntiKt4LCTopo_eta;   //!
    TBranch        *b_jet_AntiKt4LCTopo_flavor_truth_label;   //!
    TBranch        *b_jet_AntiKt4LCTopo_flavor_weight_MV1;   //!
    TBranch        *b_jet_AntiKt4LCTopo_fracSamplingMax;   //!
    TBranch        *b_jet_AntiKt4LCTopo_hecf;   //!
    TBranch        *b_jet_AntiKt4LCTopo_jvtxf;   //!
    TBranch        *b_jet_AntiKt4LCTopo_m;   //!
    TBranch        *b_jet_AntiKt4LCTopo_n;   //!
    TBranch        *b_jet_AntiKt4LCTopo_phi;   //!
    TBranch        *b_jet_AntiKt4LCTopo_pt;   //!
    TBranch        *b_jet_AntiKt4LCTopo_sumPtTrk_pv0_500MeV;   //!
    TBranch        *b_larError;   //!
    TBranch        *b_lbn;   //!
    TBranch        *b_mc_barcode;   //!
    TBranch        *b_mc_channel_number;   //!
    TBranch        *b_mc_charge;   //!
    TBranch        *b_mc_child_index;   //!
    TBranch        *b_mc_children;   //!
    TBranch        *b_mc_eta;   //!
    TBranch        *b_mc_event_weight;   //!
    TBranch        *b_mc_m;   //!
    TBranch        *b_mc_n;   //!
    TBranch        *b_mc_parent_index;   //!
    TBranch        *b_mc_parents;   //!
    TBranch        *b_mc_pdgId;   //!
    TBranch        *b_mc_phi;   //!
    TBranch        *b_mc_pt;   //!
    TBranch        *b_mc_status;   //!
    TBranch        *b_mc_vx_barcode;   //!
    TBranch        *b_mu_staco_charge;   //!
    TBranch        *b_mu_staco_cov_qoverp_exPV;   //!
    TBranch        *b_mu_staco_d0_exPV;   //!
    TBranch        *b_mu_staco_eta;   //!
    TBranch        *b_mu_staco_etcone30;   //!
    TBranch        *b_mu_staco_expectBLayerHit;   //!
    TBranch        *b_mu_staco_id_qoverp_exPV;   //!
    TBranch        *b_mu_staco_id_theta_exPV;   //!
    TBranch        *b_mu_staco_isCombinedMuon;   //!
    TBranch        *b_mu_staco_isSegmentTaggedMuon;   //!
    TBranch        *b_mu_staco_me_qoverp_exPV;   //!
    TBranch        *b_mu_staco_me_theta_exPV;   //!
    TBranch        *b_mu_staco_ms_phi;   //!
    TBranch        *b_mu_staco_ms_qoverp;   //!
    TBranch        *b_mu_staco_ms_theta;   //!
    TBranch        *b_mu_staco_n;   //!
    TBranch        *b_mu_staco_nBLHits;   //!
    TBranch        *b_mu_staco_nPixHits;   //!
    TBranch        *b_mu_staco_nPixHoles;   //!
    TBranch        *b_mu_staco_nSCTDeadSensors;   //!
    TBranch        *b_mu_staco_nSCTHits;   //!
    TBranch        *b_mu_staco_nSCTHoles;   //!
    TBranch        *b_mu_staco_nTRTHits;   //!
    TBranch        *b_mu_staco_nTRTOutliers;   //!
    TBranch        *b_mu_staco_phi;   //!
    TBranch        *b_mu_staco_pt;   //!
    TBranch        *b_mu_staco_ptcone30_trkelstyle;   //!
    TBranch        *b_mu_staco_qoverp_exPV;   //!
    TBranch        *b_mu_staco_trackIPEstimate_d0_unbiasedpvunbiased;   //!
    TBranch        *b_mu_staco_trackIPEstimate_sigd0_unbiasedpvunbiased;   //!
    TBranch        *b_mu_staco_trackIPEstimate_z0_unbiasedpvunbiased;   //!
    TBranch        *b_mu_staco_truth_barcode;   //!
    TBranch        *b_mu_staco_truth_motherbarcode;   //!
    TBranch        *b_mu_staco_z0_exPV;   //!
    TBranch        *b_muonTruth_origin;   //!
    TBranch        *b_muonTruth_type;   //!
    TBranch        *b_tau_EleBDTLoose;   //!
    TBranch        *b_tau_EleBDTMedium;   //!
    TBranch        *b_tau_EleBDTTight;   //!
    TBranch        *b_tau_JetBDTSigLoose;   //!
    TBranch        *b_tau_JetBDTSigMedium;   //!
    TBranch        *b_tau_JetBDTSigTight;   //!
    TBranch        *b_tau_charge;   //!
    TBranch        *b_tau_eta;   //!
    TBranch        *b_tau_m;   //!
    TBranch        *b_tau_muonVeto;   //!
    TBranch        *b_tau_n;   //!
    TBranch        *b_tau_numTrack;   //!
    TBranch        *b_tau_phi;   //!
    TBranch        *b_tau_pt;   //!
    TBranch        *b_tileError;   //!
    TBranch        *b_trig_EF_el_E;   //!
    TBranch        *b_trig_EF_el_EF_e12Tvh_loose1;   //!
    TBranch        *b_trig_EF_el_EF_e12Tvh_medium1;   //!
    TBranch        *b_trig_EF_el_EF_e24vh_medium1;   //!
    TBranch        *b_trig_EF_el_EF_e24vh_medium1_e7_medium1;   //!
    TBranch        *b_trig_EF_el_EF_e7T_medium1;   //!
    TBranch        *b_trig_EF_el_px;   //!
    TBranch        *b_trig_EF_el_py;   //!
    TBranch        *b_trig_EF_el_pz;   //!
    TBranch        *b_trig_EF_trigmuonef_EF_mu13;   //!
    TBranch        *b_trig_EF_trigmuonef_EF_mu18_tight;   //!
    TBranch        *b_trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS;   //!
    TBranch        *b_trig_EF_trigmuonef_EF_mu8;   //!
    TBranch        *b_trig_EF_trigmuonef_track_CB_eta;   //!
    TBranch        *b_trig_EF_trigmuonef_track_CB_hasCB;   //!
    TBranch        *b_trig_EF_trigmuonef_track_CB_phi;   //!
    TBranch        *b_trig_EF_trigmuonef_track_CB_pt;   //!
    TBranch        *b_vx_E;   //!
    TBranch        *b_vx_m;   //!
    TBranch        *b_vx_n;   //!
    TBranch        *b_vx_nTracks;   //!
    TBranch        *b_vx_x;   //!
    TBranch        *b_vx_y;   //!
    TBranch        *b_vx_z;   //!

    // TBranch        *b_EF_2b35_loose_3j35_a4tchad_4L1J10;   //!
    // TBranch        *b_EF_2b35_loose_3j35_a4tchad_4L1J15;   //!
    // TBranch        *b_EF_2b35_loose_3j35_a4tchad_L2FS_4L1J10;   //!
    // TBranch        *b_EF_2b35_loose_3j35_a4tchad_L2FS_4L1J15;   //!
    // TBranch        *b_EF_2b35_loose_4j35_a4tchad;   //!
    // TBranch        *b_EF_2b35_loose_4j35_a4tchad_L2FS;   //!
    // TBranch        *b_EF_2b35_loose_j110_2j35_a4tchad;   //!
    // TBranch        *b_EF_2b35_loose_j145_2j35_a4tchad;   //!
    // TBranch        *b_EF_2b35_loose_j145_j100_j35_a4tchad;   //!
    // TBranch        *b_EF_2b35_loose_j145_j35_a4tchad;   //!
    // TBranch        *b_EF_2b35_medium_3j35_a4tchad_4L1J15;   //!
    // TBranch        *b_EF_2b35_medium_3j35_a4tchad_L2FS_4L1J15;   //!
    // TBranch        *b_EF_2b45_loose_j145_j45_a4tchad;   //!
    // TBranch        *b_EF_2b45_loose_j145_j45_a4tchad_EFxe40_tclcw;   //!
    // TBranch        *b_EF_2b45_medium_3j45_a4tchad_4L1J15;   //!
    // TBranch        *b_EF_2b45_medium_3j45_a4tchad_L2FS_4L1J15;   //!
    // TBranch        *b_EF_2b55_loose_4j55_a4tchad;   //!
    // TBranch        *b_EF_2b55_loose_4j55_a4tchad_L2FS;   //!
    // TBranch        *b_EF_2b55_loose_j110_j55_a4tchad;   //!
    // TBranch        *b_EF_2b55_loose_j110_j55_a4tchad_1bL2;   //!
    // TBranch        *b_EF_2b55_loose_j110_j55_a4tchad_ht500;   //!
    // TBranch        *b_EF_2b55_loose_j145_j55_a4tchad;   //!
    // TBranch        *b_EF_2b55_medium_3j55_a4tchad_4L1J15;   //!
    // TBranch        *b_EF_2b55_medium_3j55_a4tchad_L2FS_4L1J15;   //!
    // TBranch        *b_EF_2b55_medium_4j55_a4tchad;   //!
    // TBranch        *b_EF_2b55_medium_4j55_a4tchad_L2FS;   //!
    // TBranch        *b_EF_2b55_medium_j110_j55_a4tchad_ht500;   //!
    // TBranch        *b_EF_2b55_medium_j165_j55_a4tchad_ht500;   //!
    // TBranch        *b_EF_2b80_medium_j165_j80_a4tchad_ht500;   //!
    // TBranch        *b_EF_2e5_tight1_Jpsi;   //!
    // TBranch        *b_EF_2e7T_loose1_mu6;   //!
    // TBranch        *b_EF_2e7T_medium1_mu6;   //!
    // TBranch        *b_EF_2fj45_a4tchad_deta50_FB_L2FS_L1MBTS;   //!
    // TBranch        *b_EF_2fj45_a4tchad_deta50_FB_L2FS_L1TE20;   //!
    // TBranch        *b_EF_2fj55_a4tchad_deta50_FB_L2FS_L1MBTS;   //!
    // TBranch        *b_EF_2fj55_a4tchad_deta50_FB_L2FS_L1TE20;   //!
    // TBranch        *b_EF_2g15vh_loose_g10_loose;   //!
    // TBranch        *b_EF_2g15vh_medium;   //!
    // TBranch        *b_EF_2g15vh_medium_g10_medium;   //!
    // TBranch        *b_EF_2g20_loose;   //!
    // TBranch        *b_EF_2g20vh_medium;   //!
    // TBranch        *b_EF_2g30_loose;   //!
    // TBranch        *b_EF_2g40_loose;   //!
    // TBranch        *b_EF_2j100_a2tcem;   //!
    // TBranch        *b_EF_2j10_a4tchadloose_deta35_FC_L1MBTS;   //!
    // TBranch        *b_EF_2j150_a2tcem;   //!
    // TBranch        *b_EF_2j15_a4tchad_deta35_FC_L1MBTS;   //!
    // TBranch        *b_EF_2j15_a4tchad_deta35_FC_L1TE20;   //!
    // TBranch        *b_EF_2j200_a2tcem;   //!
    // TBranch        *b_EF_2j240_a10tcem;   //!
    // TBranch        *b_EF_2j240_a10tcem_L2FS;   //!
    // TBranch        *b_EF_2j240_a10tclcw;   //!
    // TBranch        *b_EF_2j240_a10tclcw_L2FS;   //!
    // TBranch        *b_EF_2j250_a2tcem;   //!
    // TBranch        *b_EF_2j25_a4tchad_deta35_FC_L1MBTS;   //!
    // TBranch        *b_EF_2j25_a4tchad_deta35_FC_L1TE20;   //!
    // TBranch        *b_EF_2j35_a4tchad_deta35_FC_L1MBTS;   //!
    // TBranch        *b_EF_2j35_a4tchad_deta35_FC_L1TE20;   //!
    // TBranch        *b_EF_2mu10;   //!
    // TBranch        *b_EF_2mu10_MSonly_g10_loose;   //!
    // TBranch        *b_EF_2mu10_MSonly_g10_loose_EMPTY;   //!
    // TBranch        *b_EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO;   //!
    // TBranch        *b_EF_2mu13_Zmumu_IDTrkNoCut;   //!
    // TBranch        *b_EF_2mu13_l2muonSA;   //!
    // TBranch        *b_EF_2mu15;   //!
    // TBranch        *b_EF_2mu4T;   //!
    // TBranch        *b_EF_2mu4T_2e5_tight1;   //!
    // TBranch        *b_EF_2mu4T_Bmumu;   //!
    // TBranch        *b_EF_2mu4T_Bmumu_Barrel;   //!
    // TBranch        *b_EF_2mu4T_Bmumu_BarrelOnly;   //!
    // TBranch        *b_EF_2mu4T_Bmumux;   //!
    // TBranch        *b_EF_2mu4T_Bmumux_Barrel;   //!
    // TBranch        *b_EF_2mu4T_Bmumux_BarrelOnly;   //!
    // TBranch        *b_EF_2mu4T_DiMu;   //!
    // TBranch        *b_EF_2mu4T_DiMu_Barrel;   //!
    // TBranch        *b_EF_2mu4T_DiMu_BarrelOnly;   //!
    // TBranch        *b_EF_2mu4T_DiMu_L2StarB;   //!
    // TBranch        *b_EF_2mu4T_DiMu_L2StarC;   //!
    // TBranch        *b_EF_2mu4T_DiMu_e5_tight1;   //!
    // TBranch        *b_EF_2mu4T_DiMu_l2muonSA;   //!
    // TBranch        *b_EF_2mu4T_DiMu_noVtx_noOS;   //!
    // TBranch        *b_EF_2mu4T_Jpsimumu;   //!
    // TBranch        *b_EF_2mu4T_Jpsimumu_Barrel;   //!
    // TBranch        *b_EF_2mu4T_Jpsimumu_BarrelOnly;   //!
    // TBranch        *b_EF_2mu4T_Jpsimumu_IDTrkNoCut;   //!
    // TBranch        *b_EF_2mu4T_Upsimumu;   //!
    // TBranch        *b_EF_2mu4T_Upsimumu_Barrel;   //!
    // TBranch        *b_EF_2mu4T_Upsimumu_BarrelOnly;   //!
    // TBranch        *b_EF_2mu4T_xe50_tclcw;   //!
    // TBranch        *b_EF_2mu4T_xe60;   //!
    // TBranch        *b_EF_2mu4T_xe60_tclcw;   //!
    // TBranch        *b_EF_2mu6;   //!
    // TBranch        *b_EF_2mu6_Bmumu;   //!
    // TBranch        *b_EF_2mu6_Bmumux;   //!
    // TBranch        *b_EF_2mu6_DiMu;   //!
    // TBranch        *b_EF_2mu6_DiMu_DY20;   //!
    // TBranch        *b_EF_2mu6_DiMu_DY25;   //!
    // TBranch        *b_EF_2mu6_DiMu_noVtx_noOS;   //!
    // TBranch        *b_EF_2mu6_Jpsimumu;   //!
    // TBranch        *b_EF_2mu6_Upsimumu;   //!
    // TBranch        *b_EF_2mu6i_DiMu_DY;   //!
    // TBranch        *b_EF_2mu6i_DiMu_DY_2j25_a4tchad;   //!
    // TBranch        *b_EF_2mu6i_DiMu_DY_noVtx_noOS;   //!
    // TBranch        *b_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad;   //!
    // TBranch        *b_EF_2mu8_EFxe30;   //!
    // TBranch        *b_EF_2mu8_EFxe30_tclcw;   //!
    // TBranch        *b_EF_2tau29T_medium1;   //!
    // TBranch        *b_EF_2tau29_medium1;   //!
    // TBranch        *b_EF_2tau29i_medium1;   //!
    // TBranch        *b_EF_2tau38T_medium1;   //!
    // TBranch        *b_EF_2tau38T_medium1_llh;   //!
    // TBranch        *b_EF_2tau38T_medium;   //!
    // TBranch        *b_EF_3g15vh_loose;   //!
    // TBranch        *b_EF_3g15vh_medium;   //!
    // TBranch        *b_EF_3j10_a4tchadloose_L1MBTS;   //!
    // TBranch        *b_EF_3j170_a4tchad_L1J75;   //!
    // TBranch        *b_EF_3j170_a4tclcw_L1J75;   //!
    // TBranch        *b_EF_3j180_a4tchad_L1J75;   //!
    // TBranch        *b_EF_3j180_a4tthad;   //!
    // TBranch        *b_EF_3j25_a4tchad;   //!
    // TBranch        *b_EF_3j25_a4tchad_L1MBTS;   //!
    // TBranch        *b_EF_3j35_a4tchad_L2FS_4L1J15;   //!
    // TBranch        *b_EF_3j45_a4tchad_L2FS;   //!
    // TBranch        *b_EF_3j45_a4tchad_L2FS_4L1J15;   //!
    // TBranch        *b_EF_3j45_a4tchad_L2FS_L1RD0;   //!
    // TBranch        *b_EF_3j55_a4tchad_L2FS;   //!
    // TBranch        *b_EF_3mu4T;   //!
    // TBranch        *b_EF_3mu4T_DiMu;   //!
    // TBranch        *b_EF_3mu4T_Jpsi;   //!
    // TBranch        *b_EF_3mu4T_Tau;   //!
    // TBranch        *b_EF_3mu4T_Upsi;   //!
    // TBranch        *b_EF_3mu6;   //!
    // TBranch        *b_EF_3mu6_MSonly;   //!
    // TBranch        *b_EF_3mu6_MSonly_EMPTY;   //!
    // TBranch        *b_EF_3mu6_MSonly_UNPAIRED_ISO;   //!
    // TBranch        *b_EF_4j10_a4tchadloose_L1MBTS;   //!
    // TBranch        *b_EF_4j110_a4tchad_L2FS;   //!
    // TBranch        *b_EF_4j110_a4tchad_L2FS_4L1J20;   //!
    // TBranch        *b_EF_4j110_a4tchad_L2FS_5L1J15;   //!
    // TBranch        *b_EF_4j110_a4tclcw_L2FS;   //!
    // TBranch        *b_EF_4j25_a4tchad;   //!
    // TBranch        *b_EF_4j25_a4tchad_L1MBTS;   //!
    // TBranch        *b_EF_4j45_a4tchad_L2FS;   //!
    // TBranch        *b_EF_4j45_a4tchad_L2FS_4L1J10;   //!
    // TBranch        *b_EF_4j45_a4tchad_L2FS_L1RD0;   //!
    // TBranch        *b_EF_4j55_a4tchad_L2FS;   //!
    // TBranch        *b_EF_4j55_a4tchad_L2FSj15had;   //!
    // TBranch        *b_EF_4j55_a4tchad_L2FSj25had;   //!
    // TBranch        *b_EF_4j55_a4tthad_L2FS;   //!
    // TBranch        *b_EF_4j65_a4tchad_L2FS;   //!
    // TBranch        *b_EF_4j65_a4tchad_L2FS_4L1J20;   //!
    // TBranch        *b_EF_4j65_a4tchad_L2FS_5L1J15;   //!
    // TBranch        *b_EF_4j80_a4tchad_L2FS;   //!
    // TBranch        *b_EF_4j80_a4tchad_L2FS_4L1J20;   //!
    // TBranch        *b_EF_4j80_a4tchad_L2FS_5L1J15;   //!
    // TBranch        *b_EF_4j80_a4tclcw_L2FS;   //!
    // TBranch        *b_EF_4mu4T;   //!
    // TBranch        *b_EF_5j10_a4tchadloose_L1MBTS;   //!
    // TBranch        *b_EF_5j110_a4tchad_L2FS;   //!
    // TBranch        *b_EF_5j110_a4tchad_L2FS_4L1J20;   //!
    // TBranch        *b_EF_5j110_a4tchad_L2FS_5L1J15;   //!
    // TBranch        *b_EF_5j25_a4tchad;   //!
    // TBranch        *b_EF_5j25_a4tchad_L1MBTS;   //!
    // TBranch        *b_EF_5j45_a4tchad_L2FS;   //!
    // TBranch        *b_EF_5j45_a4tchad_L2FS_5L1J10;   //!
    // TBranch        *b_EF_5j45_a4tchad_L2FS_L1RD0;   //!
    // TBranch        *b_EF_5j45_a4tclcw_L2FS;   //!
    // TBranch        *b_EF_5j55_a4tchad_L2FS;   //!
    // TBranch        *b_EF_5j55_a4tchad_L2FSPS;   //!
    // TBranch        *b_EF_5j55_a4tchad_L2FS_5L1J15;   //!
    // TBranch        *b_EF_5j55_a4tchad_L2FSj15had;   //!
    // TBranch        *b_EF_5j55_a4tchad_L2FSj25had;   //!
    // TBranch        *b_EF_5j55_a4tchad_L2PS;   //!
    // TBranch        *b_EF_5j65_a4tchad_L2FS;   //!
    // TBranch        *b_EF_5j65_a4tchad_L2FS_4L1J20;   //!
    // TBranch        *b_EF_5j65_a4tchad_L2FS_5L1J15;   //!
    // TBranch        *b_EF_5j80_a4tchad_L2FS;   //!
    // TBranch        *b_EF_5j80_a4tchad_L2FS_4L1J20;   //!
    // TBranch        *b_EF_5j80_a4tchad_L2FS_5L1J15;   //!
    // TBranch        *b_EF_6j35_a4tchad_L2FS_5L2j15;   //!
    // TBranch        *b_EF_6j45_a4tchad_L2FS;   //!
    // TBranch        *b_EF_6j45_a4tchad_L2FS_5L2j15;   //!
    // TBranch        *b_EF_6j45_a4tclcw_L2FS_5L2j15;   //!
    // TBranch        *b_EF_6j55_a4tchad_L2FS;   //!
    // TBranch        *b_EF_6j55_a4tchad_L2FSPS;   //!
    // TBranch        *b_EF_6j55_a4tchad_L2FS_5L1J15;   //!
    // TBranch        *b_EF_6j55_a4tchad_L2FS_5L2j15;   //!
    // TBranch        *b_EF_6j55_a4tchad_L2FSj15had;   //!
    // TBranch        *b_EF_6j55_a4tchad_L2FSj25had;   //!
    // TBranch        *b_EF_6j55_a4tchad_L2PS;   //!
    // TBranch        *b_EF_6j65_a4tchad_L2FS;   //!
    // TBranch        *b_EF_6j65_a4tchad_L2FS_5L1J15;   //!
    // TBranch        *b_EF_7j35_a4tchad_L2FS_5L2j15;   //!
    // TBranch        *b_EF_7j35_a4tclcw_L2FS_5L2j15;   //!
    // TBranch        *b_EF_7j45_a4tchad_L2FS;   //!
    // TBranch        *b_EF_7j45_a4tchad_L2FS_5L2j15;   //!
    // TBranch        *b_EF_7j55_a4tchad_L2FS;   //!
    // TBranch        *b_EF_7j55_a4tchad_L2FS_5L1J15;   //!
    // TBranch        *b_EF_7j65_a4tchad_L2FS;   //!
    // TBranch        *b_EF_7j65_a4tchad_L2FS_5L1J15;   //!
    // TBranch        *b_EF_ALFA_Phys;   //!
    // TBranch        *b_EF_Background;   //!
    // TBranch        *b_EF_Background_RD0_EMPTY;   //!
    // TBranch        *b_EF_Background_RD0_UNPAIRED_ISO;   //!
    // TBranch        *b_EF_CosmicsAllTeEFID;   //!
    // TBranch        *b_EF_CosmicsAllTeIDSCAN_AllPhysics_4Hits_TrkHypo;   //!
    // TBranch        *b_EF_CosmicsAllTeIDSCAN_AllPhysics_TrkHypo;   //!
    // TBranch        *b_EF_CosmicsAllTeSiTrack_AllPhysics_4Hits_TrkHypo;   //!
    // TBranch        *b_EF_CosmicsAllTeSiTrack_AllPhysics_TrkHypo;   //!
    // TBranch        *b_EF_CosmicsAllTeTRTxK_TRTTrkHypo_AllPhysics;   //!
    // TBranch        *b_EF_CosmicsAllTeTRTxK_TRTTrkHypo_Pixel;   //!
    // TBranch        *b_EF_Cosmics_MU11_TRTxK_TRTTrkHypo_AllID;   //!
    // TBranch        *b_EF_Cosmics_MU11_TRTxK_TRTTrkHypo_Pixel;   //!
    // TBranch        *b_EF_HLTTimeBurner;   //!
    // TBranch        *b_EF_InDetMon_FS;   //!
    // TBranch        *b_EF_L12MU4_NoAlg;   //!
    // TBranch        *b_EF_L1Calo_NoAlg;   //!
    // TBranch        *b_EF_L1FJ100_NoAlg;   //!
    // TBranch        *b_EF_L1FJ30_empty_NoAlg;   //!
    // TBranch        *b_EF_L1J10_empty_NoAlg;   //!
    // TBranch        *b_EF_L1J10_firstempty_NoAlg;   //!
    // TBranch        *b_EF_L1J30_empty_NoAlg;   //!
    // TBranch        *b_EF_L1J30_firstempty_NoAlg;   //!
    // TBranch        *b_EF_L1J350_NoAlg;   //!
    // TBranch        *b_EF_L1JE140_NoAlg;   //!
    // TBranch        *b_EF_L1JE200_NoAlg;   //!
    // TBranch        *b_EF_L1JE350_NoAlg;   //!
    // TBranch        *b_EF_L1JE500_NoAlg;   //!
    // TBranch        *b_EF_L1MU10_NoAlg;   //!
    // TBranch        *b_EF_L1MU15_NoAlg;   //!
    // TBranch        *b_EF_L1MinBias_NoAlg;   //!
    // TBranch        *b_EF_L1Muon_NoAlg;   //!
    // TBranch        *b_EF_L1RD0_firstempty_NoAlg;   //!
    // TBranch        *b_EF_L1TRT_NoAlg;   //!
    // TBranch        *b_EF_PreS_L1EM3_empty;   //!
    // TBranch        *b_EF_PreS_L1EM6_empty;   //!
    // TBranch        *b_EF_PreS_L1J10_empty;   //!
    // TBranch        *b_EF_PreS_L1J10_firstempty;   //!
    // TBranch        *b_EF_PreS_L1J30_empty;   //!
    // TBranch        *b_EF_PreS_L1J30_firstempty;   //!
    // TBranch        *b_EF_PreS_L1TAU8_empty;   //!
    // TBranch        *b_EF_ROBRequestMon;   //!
    // TBranch        *b_EF_Standby;   //!
    // TBranch        *b_EF_TileCalib_laser;   //!
    // TBranch        *b_EF_VdM_mbSpTrk;   //!
    // TBranch        *b_EF_allL1_NoAlg;   //!
    // TBranch        *b_EF_b110_looseEF_j110_a4tchad;   //!
    // TBranch        *b_EF_b110_loose_j110_a10tcem_L2FS_L1J75;   //!
    // TBranch        *b_EF_b110_loose_j110_a4tchad_xe55_tclcw;   //!
    // TBranch        *b_EF_b110_loose_j110_a4tchad_xe60_tclcw;   //!
    // TBranch        *b_EF_b145_loose_j145_a10tcem_L2FS;   //!
    // TBranch        *b_EF_b145_loose_j145_a4tchad;   //!
    // TBranch        *b_EF_b145_mediumEF_j145_a4tchad_L2EFxe60_tclcw;   //!
    // TBranch        *b_EF_b145_medium_j145_a4tchad_ht400;   //!
    // TBranch        *b_EF_b15_NoCut_j15_a4tchad;   //!
    // TBranch        *b_EF_b15_looseEF_j15_a4tchad;   //!
    // TBranch        *b_EF_b165_medium_j165_a4tchad_ht500;   //!
    // TBranch        *b_EF_b180_loose_j180_a10tcem_L2FS;   //!
    // TBranch        *b_EF_b180_loose_j180_a10tcem_L2j140;   //!
    // TBranch        *b_EF_b180_loose_j180_a10tcem_L2j140_EFxe50_tclcw;   //!
    // TBranch        *b_EF_b180_loose_j180_a4tchad_L2j140;   //!
    // TBranch        *b_EF_b180_medium_j180_a10tcem_L2j140_EFxe50_tclcw;   //!
    // TBranch        *b_EF_b220_loose_j220_a10tcem;   //!
    // TBranch        *b_EF_b220_loose_j220_a4tchad_L2j140;   //!
    // TBranch        *b_EF_b240_loose_j240_a10tcem_L2FS;   //!
    // TBranch        *b_EF_b240_loose_j240_a10tcem_L2j140;   //!
    // TBranch        *b_EF_b25_looseEF_j25_a4tchad;   //!
    // TBranch        *b_EF_b280_loose_j280_a10tcem;   //!
    // TBranch        *b_EF_b280_loose_j280_a4tchad_L2j140;   //!
    // TBranch        *b_EF_b35_NoCut_4j35_a4tchad;   //!
    // TBranch        *b_EF_b35_NoCut_4j35_a4tchad_5L1J10;   //!
    // TBranch        *b_EF_b35_NoCut_4j35_a4tchad_L2FS;   //!
    // TBranch        *b_EF_b35_NoCut_4j35_a4tchad_L2FS_5L1J10;   //!
    // TBranch        *b_EF_b35_looseEF_j35_a4tchad;   //!
    // TBranch        *b_EF_b35_loose_4j35_a4tchad_5L1J10;   //!
    // TBranch        *b_EF_b35_loose_4j35_a4tchad_L2FS_5L1J10;   //!
    // TBranch        *b_EF_b35_loose_j110_2j35_a4tchad_EFxe80_tclcw;   //!
    // TBranch        *b_EF_b35_medium_3j35_a4tchad_4L1J15;   //!
    // TBranch        *b_EF_b35_medium_3j35_a4tchad_L2FS_4L1J15;   //!
    // TBranch        *b_EF_b360_loose_j360_a4tchad_L2j140;   //!
    // TBranch        *b_EF_b45_looseEF_j145_a4tchad_L2EFxe60_tclcw;   //!
    // TBranch        *b_EF_b45_looseEF_j45_a4tchad;   //!
    // TBranch        *b_EF_b45_mediumEF_j110_j45_xe60_tclcw;   //!
    // TBranch        *b_EF_b45_medium_3j45_a4tchad_4L1J15;   //!
    // TBranch        *b_EF_b45_medium_3j45_a4tchad_L2FS_4L1J15;   //!
    // TBranch        *b_EF_b45_medium_4j45_a4tchad;   //!
    // TBranch        *b_EF_b45_medium_4j45_a4tchad_4L1J10;   //!
    // TBranch        *b_EF_b45_medium_4j45_a4tchad_L2FS;   //!
    // TBranch        *b_EF_b45_medium_4j45_a4tchad_L2FS_4L1J10;   //!
    // TBranch        *b_EF_b45_medium_j145_j45_a4tchad_ht400;   //!
    // TBranch        *b_EF_b45_medium_j145_j45_a4tchad_ht500;   //!
    // TBranch        *b_EF_b55_NoCut_j55_a4tchad;   //!
    // TBranch        *b_EF_b55_NoCut_j55_a4tchad_L2FS;   //!
    // TBranch        *b_EF_b55_looseEF_j55_a4tchad;   //!
    // TBranch        *b_EF_b55_loose_4j55_a4tchad;   //!
    // TBranch        *b_EF_b55_loose_4j55_a4tchad_L2FS;   //!
    // TBranch        *b_EF_b55_mediumEF_j110_j55_xe60_tclcw;   //!
    // TBranch        *b_EF_b55_medium_3j55_a4tchad_4L1J15;   //!
    // TBranch        *b_EF_b55_medium_3j55_a4tchad_L2FS_4L1J15;   //!
    // TBranch        *b_EF_b55_medium_4j55_a4tchad;   //!
    // TBranch        *b_EF_b55_medium_4j55_a4tchad_4L1J10;   //!
    // TBranch        *b_EF_b55_medium_4j55_a4tchad_L2FS;   //!
    // TBranch        *b_EF_b55_medium_4j55_a4tchad_L2FS_4L1J10;   //!
    // TBranch        *b_EF_b55_medium_j110_j55_a4tchad;   //!
    // TBranch        *b_EF_b80_looseEF_j80_a4tchad;   //!
    // TBranch        *b_EF_b80_loose_j80_a4tchad_xe55_tclcw;   //!
    // TBranch        *b_EF_b80_loose_j80_a4tchad_xe60_tclcw;   //!
    // TBranch        *b_EF_b80_loose_j80_a4tchad_xe70_tclcw;   //!
    // TBranch        *b_EF_b80_loose_j80_a4tchad_xe75_tclcw;   //!
    // TBranch        *b_EF_cost_monitor;   //!
    // TBranch        *b_EF_e11_etcut;   //!
    // TBranch        *b_EF_e12Tvh_loose1;   //!
    // TBranch        *b_EF_e12Tvh_loose1_mu8;   //!
    // TBranch        *b_EF_e12Tvh_medium1;   //!
    // TBranch        *b_EF_e12Tvh_medium1_mu10;   //!
    // TBranch        *b_EF_e12Tvh_medium1_mu6;   //!
    // TBranch        *b_EF_e12Tvh_medium1_mu6_topo_medium;   //!
    // TBranch        *b_EF_e13_etcutTrk_xs60;   //!
    // TBranch        *b_EF_e13_etcutTrk_xs60_dphi2j15xe20;   //!
    // TBranch        *b_EF_e14_tight1_e4_etcut_Jpsi;   //!
    // TBranch        *b_EF_e15vh_medium1;   //!
    // TBranch        *b_EF_e18_loose1;   //!
    // TBranch        *b_EF_e18_loose1_g25_medium;   //!
    // TBranch        *b_EF_e18_loose1_g35_loose;   //!
    // TBranch        *b_EF_e18_loose1_g35_medium;   //!
    // TBranch        *b_EF_e18_medium1;   //!
    // TBranch        *b_EF_e18_medium1_g25_loose;   //!
    // TBranch        *b_EF_e18_medium1_g25_medium;   //!
    // TBranch        *b_EF_e18_medium1_g35_loose;   //!
    // TBranch        *b_EF_e18_medium1_g35_medium;   //!
    // TBranch        *b_EF_e18vh_medium1;   //!
    // TBranch        *b_EF_e18vh_medium1_2e7T_medium1;   //!
    // TBranch        *b_EF_e20_etcutTrk_xe30_dphi2j15xe20;   //!
    // TBranch        *b_EF_e20_etcutTrk_xs60_dphi2j15xe20;   //!
    // TBranch        *b_EF_e20vhT_medium1_g6T_etcut_Upsi;   //!
    // TBranch        *b_EF_e20vhT_tight1_g6T_etcut_Upsi;   //!
    // TBranch        *b_EF_e22vh_loose0;   //!
    // TBranch        *b_EF_e22vh_loose1;   //!
    // TBranch        *b_EF_e22vh_loose;   //!
    // TBranch        *b_EF_e22vh_medium1;   //!
    // TBranch        *b_EF_e22vh_medium1_IDTrkNoCut;   //!
    // TBranch        *b_EF_e22vh_medium1_IdScan;   //!
    // TBranch        *b_EF_e22vh_medium1_SiTrk;   //!
    // TBranch        *b_EF_e22vh_medium1_TRT;   //!
    // TBranch        *b_EF_e22vhi_medium1;   //!
    // TBranch        *b_EF_e24vh_loose0;   //!
    // TBranch        *b_EF_e24vh_loose1;   //!
    // TBranch        *b_EF_e24vh_loose;   //!
    // TBranch        *b_EF_e24vh_medium1;   //!
    // TBranch        *b_EF_e24vh_medium1_EFxe30;   //!
    // TBranch        *b_EF_e24vh_medium1_EFxe30_tcem;   //!
    // TBranch        *b_EF_e24vh_medium1_EFxe35_tcem;   //!
    // TBranch        *b_EF_e24vh_medium1_EFxe35_tclcw;   //!
    // TBranch        *b_EF_e24vh_medium1_EFxe40;   //!
    // TBranch        *b_EF_e24vh_medium1_IDTrkNoCut;   //!
    // TBranch        *b_EF_e24vh_medium1_IdScan;   //!
    // TBranch        *b_EF_e24vh_medium1_L2StarB;   //!
    // TBranch        *b_EF_e24vh_medium1_L2StarC;   //!
    // TBranch        *b_EF_e24vh_medium1_SiTrk;   //!
    // TBranch        *b_EF_e24vh_medium1_TRT;   //!
    // TBranch        *b_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad;   //!
    // TBranch        *b_EF_e24vh_tight1_e15_NoCut_Zee;   //!
    // TBranch        *b_EF_e24vhi_loose1_mu8;   //!
    // TBranch        *b_EF_e24vhi_medium1;   //!
    // TBranch        *b_EF_e45_etcut;   //!
    // TBranch        *b_EF_e45_medium1;   //!
    // TBranch        *b_EF_e5_tight1;   //!
    // TBranch        *b_EF_e5_tight1_e14_etcut_Jpsi;   //!
    // TBranch        *b_EF_e5_tight1_e4_etcut_Jpsi;   //!
    // TBranch        *b_EF_e5_tight1_e4_etcut_Jpsi_IdScan;   //!
    // TBranch        *b_EF_e5_tight1_e4_etcut_Jpsi_L2StarB;   //!
    // TBranch        *b_EF_e5_tight1_e4_etcut_Jpsi_L2StarC;   //!
    // TBranch        *b_EF_e5_tight1_e4_etcut_Jpsi_SiTrk;   //!
    // TBranch        *b_EF_e5_tight1_e4_etcut_Jpsi_TRT;   //!
    // TBranch        *b_EF_e5_tight1_e5_NoCut;   //!
    // TBranch        *b_EF_e5_tight1_e9_etcut_Jpsi;   //!
    // TBranch        *b_EF_e60_etcut;   //!
    // TBranch        *b_EF_e60_medium1;   //!
    // TBranch        *b_EF_e7T_loose1;   //!
    // TBranch        *b_EF_e7T_loose1_2mu6;   //!
    // TBranch        *b_EF_e7T_medium1;   //!
    // TBranch        *b_EF_e7T_medium1_2mu6;   //!
    // TBranch        *b_EF_e9_tight1_e4_etcut_Jpsi;   //!
    // TBranch        *b_EF_eb_physics;   //!
    // TBranch        *b_EF_eb_physics_empty;   //!
    // TBranch        *b_EF_eb_physics_firstempty;   //!
    // TBranch        *b_EF_eb_physics_noL1PS;   //!
    // TBranch        *b_EF_eb_physics_unpaired_iso;   //!
    // TBranch        *b_EF_eb_physics_unpaired_noniso;   //!
    // TBranch        *b_EF_eb_random;   //!
    // TBranch        *b_EF_eb_random_empty;   //!
    // TBranch        *b_EF_eb_random_firstempty;   //!
    // TBranch        *b_EF_eb_random_unpaired_iso;   //!
    // TBranch        *b_EF_fj10_a4tchadloose;   //!
    // TBranch        *b_EF_fj10_a4tchadloose_L1MBTS;   //!
    // TBranch        *b_EF_fj110_a4tchad;   //!
    // TBranch        *b_EF_fj145_a4tchad;   //!
    // TBranch        *b_EF_fj145_a4tclcw;   //!
    // TBranch        *b_EF_fj15_a4tchad;   //!
    // TBranch        *b_EF_fj15_a4tchad_L1MBTS;   //!
    // TBranch        *b_EF_fj15_a4tchad_L1TE20;   //!
    // TBranch        *b_EF_fj180_a4tchad;   //!
    // TBranch        *b_EF_fj220_a4tchad;   //!
    // TBranch        *b_EF_fj25_a4tchad;   //!
    // TBranch        *b_EF_fj25_a4tchad_L1MBTS;   //!
    // TBranch        *b_EF_fj25_a4tchad_L1TE20;   //!
    // TBranch        *b_EF_fj35_a4tchad;   //!
    // TBranch        *b_EF_fj35_a4tchad_L1MBTS;   //!
    // TBranch        *b_EF_fj35_a4tchad_L1TE20;   //!
    // TBranch        *b_EF_fj35_a4tclcw;   //!
    // TBranch        *b_EF_fj45_a4tchad_L1RD0;   //!
    // TBranch        *b_EF_fj45_a4tchad_L2FS;   //!
    // TBranch        *b_EF_fj45_a4tchad_L2FS_L1MBTS;   //!
    // TBranch        *b_EF_fj45_a4tchad_L2FS_L1TE20;   //!
    // TBranch        *b_EF_fj55_a4tchad_L2FS;   //!
    // TBranch        *b_EF_fj55_a4tchad_L2FS_L1MBTS;   //!
    // TBranch        *b_EF_fj55_a4tchad_L2FS_L1TE20;   //!
    // TBranch        *b_EF_fj80_a4tchad;   //!
    // TBranch        *b_EF_g100_loose;   //!
    // TBranch        *b_EF_g10_NoCut_cosmic;   //!
    // TBranch        *b_EF_g10_loose;   //!
    // TBranch        *b_EF_g10_medium;   //!
    // TBranch        *b_EF_g120_loose;   //!
    // TBranch        *b_EF_g12Tvh_loose;   //!
    // TBranch        *b_EF_g12Tvh_loose_larcalib;   //!
    // TBranch        *b_EF_g12Tvh_medium;   //!
    // TBranch        *b_EF_g15_loose;   //!
    // TBranch        *b_EF_g15vh_loose;   //!
    // TBranch        *b_EF_g15vh_medium;   //!
    // TBranch        *b_EF_g200_etcut;   //!
    // TBranch        *b_EF_g20Tvh_medium;   //!
    // TBranch        *b_EF_g20_etcut;   //!
    // TBranch        *b_EF_g20_loose;   //!
    // TBranch        *b_EF_g20_loose_larcalib;   //!
    // TBranch        *b_EF_g20_medium;   //!
    // TBranch        *b_EF_g20vh_medium;   //!
    // TBranch        *b_EF_g30_loose_g20_loose;   //!
    // TBranch        *b_EF_g30_medium_g20_medium;   //!
    // TBranch        *b_EF_g35_loose_g25_loose;   //!
    // TBranch        *b_EF_g35_loose_g30_loose;   //!
    // TBranch        *b_EF_g40_loose;   //!
    // TBranch        *b_EF_g40_loose_EFxe50;   //!
    // TBranch        *b_EF_g40_loose_L2EFxe50;   //!
    // TBranch        *b_EF_g40_loose_L2EFxe60;   //!
    // TBranch        *b_EF_g40_loose_L2EFxe60_tclcw;   //!
    // TBranch        *b_EF_g40_loose_g25_loose;   //!
    // TBranch        *b_EF_g40_loose_g30_loose;   //!
    // TBranch        *b_EF_g40_loose_larcalib;   //!
    // TBranch        *b_EF_g5_NoCut_cosmic;   //!
    // TBranch        *b_EF_g60_loose;   //!
    // TBranch        *b_EF_g60_loose_larcalib;   //!
    // TBranch        *b_EF_g80_loose;   //!
    // TBranch        *b_EF_g80_loose_larcalib;   //!
    // TBranch        *b_EF_hadCalib_trk18;   //!
    // TBranch        *b_EF_hadCalib_trk18_L1HA8;   //!
    // TBranch        *b_EF_hadCalib_trk18_L1RD0;   //!
    // TBranch        *b_EF_hadCalib_trk9;   //!
    // TBranch        *b_EF_hadCalib_trk9_L1HA8;   //!
    // TBranch        *b_EF_hadCalib_trk9_L1RD0;   //!
    // TBranch        *b_EF_hadCalib_trk9phi;   //!
    // TBranch        *b_EF_high_eb_physics;   //!
    // TBranch        *b_EF_j10_a4tchadloose;   //!
    // TBranch        *b_EF_j10_a4tchadloose_L1MBTS;   //!
    // TBranch        *b_EF_j10_fj10_a4tchadloose_deta50_FC_L1MBTS;   //!
    // TBranch        *b_EF_j110_2j55_a4tchad;   //!
    // TBranch        *b_EF_j110_2j55_a4tchad_L2FS;   //!
    // TBranch        *b_EF_j110_a10tcem_L2FS;   //!
    // TBranch        *b_EF_j110_a10tcem_L2FS_2j55_a4tchad;   //!
    // TBranch        *b_EF_j110_a4tchad;   //!
    // TBranch        *b_EF_j110_a4tchad_xe100_tclcw;   //!
    // TBranch        *b_EF_j110_a4tchad_xe100_tclcw_veryloose;   //!
    // TBranch        *b_EF_j110_a4tchad_xe50_tclcw;   //!
    // TBranch        *b_EF_j110_a4tchad_xe55_tclcw;   //!
    // TBranch        *b_EF_j110_a4tchad_xe60_tclcw;   //!
    // TBranch        *b_EF_j110_a4tchad_xe60_tclcw_loose;   //!
    // TBranch        *b_EF_j110_a4tchad_xe60_tclcw_veryloose;   //!
    // TBranch        *b_EF_j110_a4tchad_xe65_tclcw;   //!
    // TBranch        *b_EF_j110_a4tchad_xe70_tclcw_loose;   //!
    // TBranch        *b_EF_j110_a4tchad_xe70_tclcw_veryloose;   //!
    // TBranch        *b_EF_j110_a4tchad_xe75_tclcw;   //!
    // TBranch        *b_EF_j110_a4tchad_xe80_tclcw_loose;   //!
    // TBranch        *b_EF_j110_a4tchad_xe90_tclcw_loose;   //!
    // TBranch        *b_EF_j110_a4tchad_xe90_tclcw_veryloose;   //!
    // TBranch        *b_EF_j110_a4tclcw_xe100_tclcw_veryloose;   //!
    // TBranch        *b_EF_j145_2j45_a4tchad_L2EFxe70_tclcw;   //!
    // TBranch        *b_EF_j145_a10tcem_L2FS;   //!
    // TBranch        *b_EF_j145_a10tcem_L2FS_L2xe60_tclcw;   //!
    // TBranch        *b_EF_j145_a4tchad;   //!
    // TBranch        *b_EF_j145_a4tchad_L2EFxe60_tclcw;   //!
    // TBranch        *b_EF_j145_a4tchad_L2EFxe70_tclcw;   //!
    // TBranch        *b_EF_j145_a4tchad_L2EFxe80_tclcw;   //!
    // TBranch        *b_EF_j145_a4tchad_L2EFxe90_tclcw;   //!
    // TBranch        *b_EF_j145_a4tchad_ht500_L2FS;   //!
    // TBranch        *b_EF_j145_a4tchad_ht600_L2FS;   //!
    // TBranch        *b_EF_j145_a4tchad_ht700_L2FS;   //!
    // TBranch        *b_EF_j145_a4tclcw_L2EFxe90_tclcw;   //!
    // TBranch        *b_EF_j145_j100_j35_a4tchad;   //!
    // TBranch        *b_EF_j15_a4tchad;   //!
    // TBranch        *b_EF_j15_a4tchad_L1MBTS;   //!
    // TBranch        *b_EF_j15_a4tchad_L1TE20;   //!
    // TBranch        *b_EF_j15_fj15_a4tchad_deta50_FC_L1MBTS;   //!
    // TBranch        *b_EF_j15_fj15_a4tchad_deta50_FC_L1TE20;   //!
    // TBranch        *b_EF_j165_u0uchad_LArNoiseBurst;   //!
    // TBranch        *b_EF_j170_a4tchad_EFxe50_tclcw;   //!
    // TBranch        *b_EF_j170_a4tchad_EFxe60_tclcw;   //!
    // TBranch        *b_EF_j170_a4tchad_EFxe70_tclcw;   //!
    // TBranch        *b_EF_j170_a4tchad_EFxe80_tclcw;   //!
    // TBranch        *b_EF_j170_a4tchad_ht500;   //!
    // TBranch        *b_EF_j170_a4tchad_ht600;   //!
    // TBranch        *b_EF_j170_a4tchad_ht700;   //!
    // TBranch        *b_EF_j180_a10tcem;   //!
    // TBranch        *b_EF_j180_a10tcem_EFxe50_tclcw;   //!
    // TBranch        *b_EF_j180_a10tcem_e45_loose1;   //!
    // TBranch        *b_EF_j180_a10tclcw_EFxe50_tclcw;   //!
    // TBranch        *b_EF_j180_a4tchad;   //!
    // TBranch        *b_EF_j180_a4tclcw;   //!
    // TBranch        *b_EF_j180_a4tthad;   //!
    // TBranch        *b_EF_j220_a10tcem_e45_etcut;   //!
    // TBranch        *b_EF_j220_a10tcem_e45_loose1;   //!
    // TBranch        *b_EF_j220_a10tcem_e60_etcut;   //!
    // TBranch        *b_EF_j220_a4tchad;   //!
    // TBranch        *b_EF_j220_a4tthad;   //!
    // TBranch        *b_EF_j240_a10tcem;   //!
    // TBranch        *b_EF_j240_a10tcem_e45_etcut;   //!
    // TBranch        *b_EF_j240_a10tcem_e45_loose1;   //!
    // TBranch        *b_EF_j240_a10tcem_e60_etcut;   //!
    // TBranch        *b_EF_j240_a10tcem_e60_loose1;   //!
    // TBranch        *b_EF_j240_a10tclcw;   //!
    // TBranch        *b_EF_j25_a4tchad;   //!
    // TBranch        *b_EF_j25_a4tchad_L1MBTS;   //!
    // TBranch        *b_EF_j25_a4tchad_L1TE20;   //!
    // TBranch        *b_EF_j25_fj25_a4tchad_deta50_FC_L1MBTS;   //!
    // TBranch        *b_EF_j25_fj25_a4tchad_deta50_FC_L1TE20;   //!
    // TBranch        *b_EF_j260_a4tthad;   //!
    // TBranch        *b_EF_j280_a10tclcw_L2FS;   //!
    // TBranch        *b_EF_j280_a4tchad;   //!
    // TBranch        *b_EF_j280_a4tchad_mjj2000dy34;   //!
    // TBranch        *b_EF_j30_a4tcem_eta13_xe30_empty;   //!
    // TBranch        *b_EF_j30_a4tcem_eta13_xe30_firstempty;   //!
    // TBranch        *b_EF_j30_u0uchad_empty_LArNoiseBurst;   //!
    // TBranch        *b_EF_j35_a10tcem;   //!
    // TBranch        *b_EF_j35_a4tcem_L1TAU_LOF_HV;   //!
    // TBranch        *b_EF_j35_a4tcem_L1TAU_LOF_HV_EMPTY;   //!
    // TBranch        *b_EF_j35_a4tcem_L1TAU_LOF_HV_UNPAIRED_ISO;   //!
    // TBranch        *b_EF_j35_a4tchad;   //!
    // TBranch        *b_EF_j35_a4tchad_L1MBTS;   //!
    // TBranch        *b_EF_j35_a4tchad_L1TE20;   //!
    // TBranch        *b_EF_j35_a4tclcw;   //!
    // TBranch        *b_EF_j35_a4tthad;   //!
    // TBranch        *b_EF_j35_fj35_a4tchad_deta50_FC_L1MBTS;   //!
    // TBranch        *b_EF_j35_fj35_a4tchad_deta50_FC_L1TE20;   //!
    // TBranch        *b_EF_j360_a10tcem;   //!
    // TBranch        *b_EF_j360_a10tclcw;   //!
    // TBranch        *b_EF_j360_a4tchad;   //!
    // TBranch        *b_EF_j360_a4tclcw;   //!
    // TBranch        *b_EF_j360_a4tthad;   //!
    // TBranch        *b_EF_j380_a4tthad;   //!
    // TBranch        *b_EF_j45_a10tcem_L1RD0;   //!
    // TBranch        *b_EF_j45_a4tchad;   //!
    // TBranch        *b_EF_j45_a4tchad_L1RD0;   //!
    // TBranch        *b_EF_j45_a4tchad_L2FS;   //!
    // TBranch        *b_EF_j45_a4tchad_L2FS_L1RD0;   //!
    // TBranch        *b_EF_j460_a10tcem;   //!
    // TBranch        *b_EF_j460_a10tclcw;   //!
    // TBranch        *b_EF_j460_a4tchad;   //!
    // TBranch        *b_EF_j50_a4tcem_eta13_xe50_empty;   //!
    // TBranch        *b_EF_j50_a4tcem_eta13_xe50_firstempty;   //!
    // TBranch        *b_EF_j50_a4tcem_eta25_xe50_empty;   //!
    // TBranch        *b_EF_j50_a4tcem_eta25_xe50_firstempty;   //!
    // TBranch        *b_EF_j55_a4tchad;   //!
    // TBranch        *b_EF_j55_a4tchad_L2FS;   //!
    // TBranch        *b_EF_j55_a4tclcw;   //!
    // TBranch        *b_EF_j55_u0uchad_firstempty_LArNoiseBurst;   //!
    // TBranch        *b_EF_j65_a4tchad_L2FS;   //!
    // TBranch        *b_EF_j80_a10tcem_L2FS;   //!
    // TBranch        *b_EF_j80_a4tchad;   //!
    // TBranch        *b_EF_j80_a4tchad_xe100_tclcw_loose;   //!
    // TBranch        *b_EF_j80_a4tchad_xe100_tclcw_veryloose;   //!
    // TBranch        *b_EF_j80_a4tchad_xe55_tclcw;   //!
    // TBranch        *b_EF_j80_a4tchad_xe60_tclcw;   //!
    // TBranch        *b_EF_j80_a4tchad_xe70_tclcw;   //!
    // TBranch        *b_EF_j80_a4tchad_xe70_tclcw_dphi2j45xe10;   //!
    // TBranch        *b_EF_j80_a4tchad_xe70_tclcw_loose;   //!
    // TBranch        *b_EF_j80_a4tchad_xe80_tclcw_loose;   //!
    // TBranch        *b_EF_j80_a4tchad_xe85_tclcw_dphi2j45xe10;   //!
    // TBranch        *b_EF_l2j25_a4tcem_Trackless_HV;   //!
    // TBranch        *b_EF_l2j25_a4tcem_Trackless_HV_EMPTY;   //!
    // TBranch        *b_EF_l2j25_a4tcem_Trackless_HV_UNPAIRED_ISO;   //!
    // TBranch        *b_EF_l2j30_a4tcem_2L1MU4_HV_EMPTY;   //!
    // TBranch        *b_EF_l2j30_a4tcem_2L1MU6_HV;   //!
    // TBranch        *b_EF_l2j30_a4tcem_2L1MU6_HV_UNPAIRED_ISO;   //!
    // TBranch        *b_EF_mbLucid_eff;   //!
    // TBranch        *b_EF_mbLucid_eff_empty;   //!
    // TBranch        *b_EF_mbLucid_eff_unpaired_iso;   //!
    // TBranch        *b_EF_mbMbts_1_NoAlg;   //!
    // TBranch        *b_EF_mbMbts_1_eff;   //!
    // TBranch        *b_EF_mbMbts_2_NoAlg;   //!
    // TBranch        *b_EF_mbMbts_2_unpaired_iso_NoAlg;   //!
    // TBranch        *b_EF_mbSpTrk;   //!
    // TBranch        *b_EF_mbSpTrkVtxMh;   //!
    // TBranch        *b_EF_mbSpTrkVtxMh_eff;   //!
    // TBranch        *b_EF_mbSpTrk_empty;   //!
    // TBranch        *b_EF_mbSpTrk_noiseSup;   //!
    // TBranch        *b_EF_mbSpTrk_unpaired_iso;   //!
    // TBranch        *b_EF_mbTE20_eff;   //!
    // TBranch        *b_EF_mu10;   //!
    // TBranch        *b_EF_mu10_Jpsimumu;   //!
    // TBranch        *b_EF_mu10_MSonly;   //!
    // TBranch        *b_EF_mu10_Upsimumu_tight_FS;   //!
    // TBranch        *b_EF_mu10i_g10_loose;   //!
    // TBranch        *b_EF_mu10i_g10_loose_TauMass;   //!
    // TBranch        *b_EF_mu10i_g10_medium;   //!
    // TBranch        *b_EF_mu10i_g10_medium_TauMass;   //!
    // TBranch        *b_EF_mu10i_loose_g12Tvh_loose;   //!
    // TBranch        *b_EF_mu10i_loose_g12Tvh_loose_TauMass;   //!
    // TBranch        *b_EF_mu10i_loose_g12Tvh_medium;   //!
    // TBranch        *b_EF_mu10i_loose_g12Tvh_medium_TauMass;   //!
    // TBranch        *b_EF_mu11_empty_NoAlg;   //!
    // TBranch        *b_EF_mu13;   //!
    // TBranch        *b_EF_mu15;   //!
    // TBranch        *b_EF_mu18;   //!
    // TBranch        *b_EF_mu18_2g10_loose;   //!
    // TBranch        *b_EF_mu18_2g10_medium;   //!
    // TBranch        *b_EF_mu18_2g15_loose;   //!
    // TBranch        *b_EF_mu18_IDTrkNoCut_tight;   //!
    // TBranch        *b_EF_mu18_g20vh_loose;   //!
    // TBranch        *b_EF_mu18_medium;   //!
    // TBranch        *b_EF_mu18_tight;   //!
    // TBranch        *b_EF_mu18_tight_2mu4_EFFS;   //!
    // TBranch        *b_EF_mu18i4_tight;   //!
    // TBranch        *b_EF_mu18it_tight;   //!
    // TBranch        *b_EF_mu20i_tight_g5_loose;   //!
    // TBranch        *b_EF_mu20i_tight_g5_loose_TauMass;   //!
    // TBranch        *b_EF_mu20i_tight_g5_medium;   //!
    // TBranch        *b_EF_mu20i_tight_g5_medium_TauMass;   //!
    // TBranch        *b_EF_mu20it_tight;   //!
    // TBranch        *b_EF_mu22_IDTrkNoCut_tight;   //!
    // TBranch        *b_EF_mu24;   //!
    // TBranch        *b_EF_mu24_g20vh_loose;   //!
    // TBranch        *b_EF_mu24_g20vh_medium;   //!
    // TBranch        *b_EF_mu24_j65_a4tchad;   //!
    // TBranch        *b_EF_mu24_j65_a4tchad_EFxe40;   //!
    // TBranch        *b_EF_mu24_j65_a4tchad_EFxe40_tclcw;   //!
    // TBranch        *b_EF_mu24_j65_a4tchad_EFxe50_tclcw;   //!
    // TBranch        *b_EF_mu24_j65_a4tchad_EFxe60_tclcw;   //!
    // TBranch        *b_EF_mu24_medium;   //!
    // TBranch        *b_EF_mu24_muCombTag_NoEF_tight;   //!
    // TBranch        *b_EF_mu24_tight;   //!
    // TBranch        *b_EF_mu24_tight_2j35_a4tchad;   //!
    // TBranch        *b_EF_mu24_tight_3j35_a4tchad;   //!
    // TBranch        *b_EF_mu24_tight_4j35_a4tchad;   //!
    // TBranch        *b_EF_mu24_tight_EFxe40;   //!
    // TBranch        *b_EF_mu24_tight_L2StarB;   //!
    // TBranch        *b_EF_mu24_tight_L2StarC;   //!
    // TBranch        *b_EF_mu24_tight_MG;   //!
    // TBranch        *b_EF_mu24_tight_MuonEF;   //!
    // TBranch        *b_EF_mu24_tight_b35_mediumEF_j35_a4tchad;   //!
    // TBranch        *b_EF_mu24_tight_mu6_EFFS;   //!
    // TBranch        *b_EF_mu24i_tight;   //!
    // TBranch        *b_EF_mu24i_tight_MG;   //!
    // TBranch        *b_EF_mu24i_tight_MuonEF;   //!
    // TBranch        *b_EF_mu24i_tight_l2muonSA;   //!
    // TBranch        *b_EF_mu36_tight;   //!
    // TBranch        *b_EF_mu40_MSonly_barrel_tight;   //!
    // TBranch        *b_EF_mu40_muCombTag_NoEF;   //!
    // TBranch        *b_EF_mu40_slow_outOfTime_tight;   //!
    // TBranch        *b_EF_mu40_slow_tight;   //!
    // TBranch        *b_EF_mu40_tight;   //!
    // TBranch        *b_EF_mu4T;   //!
    // TBranch        *b_EF_mu4T_Trk_Jpsi;   //!
    // TBranch        *b_EF_mu4T_cosmic;   //!
    // TBranch        *b_EF_mu4T_j110_a4tchad_L2FS_matched;   //!
    // TBranch        *b_EF_mu4T_j110_a4tchad_matched;   //!
    // TBranch        *b_EF_mu4T_j145_a4tchad_L2FS_matched;   //!
    // TBranch        *b_EF_mu4T_j145_a4tchad_matched;   //!
    // TBranch        *b_EF_mu4T_j15_a4tchad_matched;   //!
    // TBranch        *b_EF_mu4T_j15_a4tchad_matchedZ;   //!
    // TBranch        *b_EF_mu4T_j180_a4tchad_L2FS_matched;   //!
    // TBranch        *b_EF_mu4T_j180_a4tchad_matched;   //!
    // TBranch        *b_EF_mu4T_j220_a4tchad_L2FS_matched;   //!
    // TBranch        *b_EF_mu4T_j220_a4tchad_matched;   //!
    // TBranch        *b_EF_mu4T_j25_a4tchad_matched;   //!
    // TBranch        *b_EF_mu4T_j25_a4tchad_matchedZ;   //!
    // TBranch        *b_EF_mu4T_j280_a4tchad_L2FS_matched;   //!
    // TBranch        *b_EF_mu4T_j280_a4tchad_matched;   //!
    // TBranch        *b_EF_mu4T_j35_a4tchad_matched;   //!
    // TBranch        *b_EF_mu4T_j35_a4tchad_matchedZ;   //!
    // TBranch        *b_EF_mu4T_j360_a4tchad_L2FS_matched;   //!
    // TBranch        *b_EF_mu4T_j360_a4tchad_matched;   //!
    // TBranch        *b_EF_mu4T_j45_a4tchad_L2FS_matched;   //!
    // TBranch        *b_EF_mu4T_j45_a4tchad_L2FS_matchedZ;   //!
    // TBranch        *b_EF_mu4T_j45_a4tchad_matched;   //!
    // TBranch        *b_EF_mu4T_j45_a4tchad_matchedZ;   //!
    // TBranch        *b_EF_mu4T_j55_a4tchad_L2FS_matched;   //!
    // TBranch        *b_EF_mu4T_j55_a4tchad_L2FS_matchedZ;   //!
    // TBranch        *b_EF_mu4T_j55_a4tchad_matched;   //!
    // TBranch        *b_EF_mu4T_j55_a4tchad_matchedZ;   //!
    // TBranch        *b_EF_mu4T_j65_a4tchad_L2FS_matched;   //!
    // TBranch        *b_EF_mu4T_j65_a4tchad_matched;   //!
    // TBranch        *b_EF_mu4T_j65_a4tchad_xe60_tclcw_loose;   //!
    // TBranch        *b_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose;   //!
    // TBranch        *b_EF_mu4T_j80_a4tchad_L2FS_matched;   //!
    // TBranch        *b_EF_mu4T_j80_a4tchad_matched;   //!
    // TBranch        *b_EF_mu4Ti_g20Tvh_loose;   //!
    // TBranch        *b_EF_mu4Ti_g20Tvh_loose_TauMass;   //!
    // TBranch        *b_EF_mu4Ti_g20Tvh_medium;   //!
    // TBranch        *b_EF_mu4Ti_g20Tvh_medium_TauMass;   //!
    // TBranch        *b_EF_mu4Tmu6_Bmumu;   //!
    // TBranch        *b_EF_mu4Tmu6_Bmumu_Barrel;   //!
    // TBranch        *b_EF_mu4Tmu6_Bmumux;   //!
    // TBranch        *b_EF_mu4Tmu6_Bmumux_Barrel;   //!
    // TBranch        *b_EF_mu4Tmu6_DiMu;   //!
    // TBranch        *b_EF_mu4Tmu6_DiMu_Barrel;   //!
    // TBranch        *b_EF_mu4Tmu6_DiMu_noVtx_noOS;   //!
    // TBranch        *b_EF_mu4Tmu6_Jpsimumu;   //!
    // TBranch        *b_EF_mu4Tmu6_Jpsimumu_Barrel;   //!
    // TBranch        *b_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut;   //!
    // TBranch        *b_EF_mu4Tmu6_Upsimumu;   //!
    // TBranch        *b_EF_mu4Tmu6_Upsimumu_Barrel;   //!
    // TBranch        *b_EF_mu4_L1MU11_MSonly_cosmic;   //!
    // TBranch        *b_EF_mu4_L1MU11_cosmic;   //!
    // TBranch        *b_EF_mu4_empty_NoAlg;   //!
    // TBranch        *b_EF_mu4_firstempty_NoAlg;   //!
    // TBranch        *b_EF_mu4_unpaired_iso_NoAlg;   //!
    // TBranch        *b_EF_mu50_MSonly_barrel_tight;   //!
    // TBranch        *b_EF_mu60_slow_outOfTime_tight1;   //!
    // TBranch        *b_EF_mu60_slow_tight1;   //!
    // TBranch        *b_EF_mu6;   //!
    // TBranch        *b_EF_mu6_Jpsimumu_tight;   //!
    // TBranch        *b_EF_mu6_MSonly;   //!
    // TBranch        *b_EF_mu6_Trk_Jpsi_loose;   //!
    // TBranch        *b_EF_mu6i;   //!
    // TBranch        *b_EF_mu8;   //!
    // TBranch        *b_EF_mu8_4j45_a4tchad_L2FS;   //!
    // TBranch        *b_EF_rd0_empty_NoAlg;   //!
    // TBranch        *b_EF_rd0_filled_NoAlg;   //!
    // TBranch        *b_EF_rd0_unpaired_iso_NoAlg;   //!
    // TBranch        *b_EF_rd1_empty_NoAlg;   //!
    // TBranch        *b_EF_tau125_IDTrkNoCut;   //!
    // TBranch        *b_EF_tau125_medium1;   //!
    // TBranch        *b_EF_tau125_medium1_L2StarA;   //!
    // TBranch        *b_EF_tau125_medium1_L2StarB;   //!
    // TBranch        *b_EF_tau125_medium1_L2StarC;   //!
    // TBranch        *b_EF_tau125_medium1_llh;   //!
    // TBranch        *b_EF_tau20T_medium1;   //!
    // TBranch        *b_EF_tau20T_medium1_e15vh_medium1;   //!
    // TBranch        *b_EF_tau20T_medium1_mu15i;   //!
    // TBranch        *b_EF_tau20T_medium;   //!
    // TBranch        *b_EF_tau20T_medium_mu15;   //!
    // TBranch        *b_EF_tau20Ti_medium1;   //!
    // TBranch        *b_EF_tau20Ti_medium1_e18vh_medium1;   //!
    // TBranch        *b_EF_tau20Ti_medium1_llh_e18vh_medium1;   //!
    // TBranch        *b_EF_tau20Ti_medium;   //!
    // TBranch        *b_EF_tau20Ti_medium_e18vh_medium1;   //!
    // TBranch        *b_EF_tau20Ti_tight1;   //!
    // TBranch        *b_EF_tau20Ti_tight1_llh;   //!
    // TBranch        *b_EF_tau20_medium1;   //!
    // TBranch        *b_EF_tau20_medium1_llh;   //!
    // TBranch        *b_EF_tau20_medium1_llh_mu15;   //!
    // TBranch        *b_EF_tau20_medium1_mu15;   //!
    // TBranch        *b_EF_tau20_medium1_mu15i;   //!
    // TBranch        *b_EF_tau20_medium1_mu18;   //!
    // TBranch        *b_EF_tau20_medium;   //!
    // TBranch        *b_EF_tau20_medium_llh;   //!
    // TBranch        *b_EF_tau20_medium_mu15;   //!
    // TBranch        *b_EF_tau29T_medium1;   //!
    // TBranch        *b_EF_tau29T_medium1_tau20T_medium1;   //!
    // TBranch        *b_EF_tau29T_medium1_xe40_tight;   //!
    // TBranch        *b_EF_tau29T_medium1_xe45_tight;   //!
    // TBranch        *b_EF_tau29T_medium;   //!
    // TBranch        *b_EF_tau29T_medium_xe40_tight;   //!
    // TBranch        *b_EF_tau29T_medium_xe45_tight;   //!
    // TBranch        *b_EF_tau29T_tight1;   //!
    // TBranch        *b_EF_tau29T_tight1_llh;   //!
    // TBranch        *b_EF_tau29Ti_medium1;   //!
    // TBranch        *b_EF_tau29Ti_medium1_llh_tau20Ti_medium1_llh;   //!
    // TBranch        *b_EF_tau29Ti_medium1_llh_xe40_tight;   //!
    // TBranch        *b_EF_tau29Ti_medium1_llh_xe45_tight;   //!
    // TBranch        *b_EF_tau29Ti_medium1_tau20Ti_medium1;   //!
    // TBranch        *b_EF_tau29Ti_medium1_xe40_tight;   //!
    // TBranch        *b_EF_tau29Ti_medium1_xe45_tight;   //!
    // TBranch        *b_EF_tau29Ti_medium1_xe55_tclcw;   //!
    // TBranch        *b_EF_tau29Ti_medium1_xe55_tclcw_tight;   //!
    // TBranch        *b_EF_tau29Ti_medium_xe40_tight;   //!
    // TBranch        *b_EF_tau29Ti_medium_xe45_tight;   //!
    // TBranch        *b_EF_tau29Ti_tight1;   //!
    // TBranch        *b_EF_tau29Ti_tight1_llh;   //!
    // TBranch        *b_EF_tau29Ti_tight1_llh_tau20Ti_tight1_llh;   //!
    // TBranch        *b_EF_tau29Ti_tight1_tau20Ti_tight1;   //!
    // TBranch        *b_EF_tau29_IDTrkNoCut;   //!
    // TBranch        *b_EF_tau29_medium1;   //!
    // TBranch        *b_EF_tau29_medium1_llh;   //!
    // TBranch        *b_EF_tau29_medium;   //!
    // TBranch        *b_EF_tau29_medium_2stTest;   //!
    // TBranch        *b_EF_tau29_medium_L2StarA;   //!
    // TBranch        *b_EF_tau29_medium_L2StarB;   //!
    // TBranch        *b_EF_tau29_medium_L2StarC;   //!
    // TBranch        *b_EF_tau29_medium_llh;   //!
    // TBranch        *b_EF_tau29i_medium1;   //!
    // TBranch        *b_EF_tau29i_medium;   //!
    // TBranch        *b_EF_tau38T_medium1;   //!
    // TBranch        *b_EF_tau38T_medium1_e18vh_medium1;   //!
    // TBranch        *b_EF_tau38T_medium1_llh_e18vh_medium1;   //!
    // TBranch        *b_EF_tau38T_medium1_xe40_tight;   //!
    // TBranch        *b_EF_tau38T_medium1_xe45_tight;   //!
    // TBranch        *b_EF_tau38T_medium1_xe55_tclcw_tight;   //!
    // TBranch        *b_EF_tau38T_medium;   //!
    // TBranch        *b_EF_tau38T_medium_e18vh_medium1;   //!
    // TBranch        *b_EF_tau50_medium1_e18vh_medium1;   //!
    // TBranch        *b_EF_tau50_medium;   //!
    // TBranch        *b_EF_tau50_medium_e15vh_medium1;   //!
    // TBranch        *b_EF_tauNoCut;   //!
    // TBranch        *b_EF_tauNoCut_L1TAU40;   //!
    // TBranch        *b_EF_tauNoCut_cosmic;   //!
    // TBranch        *b_EF_te1000;   //!
    // TBranch        *b_EF_te1400;   //!
    // TBranch        *b_EF_te1600;   //!
    // TBranch        *b_EF_te600;   //!
    // TBranch        *b_EF_xe100;   //!
    // TBranch        *b_EF_xe100T_tclcw;   //!
    // TBranch        *b_EF_xe100T_tclcw_loose;   //!
    // TBranch        *b_EF_xe100_tclcw;   //!
    // TBranch        *b_EF_xe100_tclcw_loose;   //!
    // TBranch        *b_EF_xe100_tclcw_veryloose;   //!
    // TBranch        *b_EF_xe100_tclcw_verytight;   //!
    // TBranch        *b_EF_xe100_tight;   //!
    // TBranch        *b_EF_xe110;   //!
    // TBranch        *b_EF_xe30;   //!
    // TBranch        *b_EF_xe30_tclcw;   //!
    // TBranch        *b_EF_xe40;   //!
    // TBranch        *b_EF_xe50;   //!
    // TBranch        *b_EF_xe55_LArNoiseBurst;   //!
    // TBranch        *b_EF_xe55_tclcw;   //!
    // TBranch        *b_EF_xe60;   //!
    // TBranch        *b_EF_xe60T;   //!
    // TBranch        *b_EF_xe60_tclcw;   //!
    // TBranch        *b_EF_xe60_tclcw_loose;   //!
    // TBranch        *b_EF_xe70;   //!
    // TBranch        *b_EF_xe70_tclcw_loose;   //!
    // TBranch        *b_EF_xe70_tclcw_veryloose;   //!
    // TBranch        *b_EF_xe70_tight;   //!
    // TBranch        *b_EF_xe70_tight_tclcw;   //!
    // TBranch        *b_EF_xe75_tclcw;   //!
    // TBranch        *b_EF_xe80;   //!
    // TBranch        *b_EF_xe80T;   //!
    // TBranch        *b_EF_xe80T_loose;   //!
    // TBranch        *b_EF_xe80T_tclcw;   //!
    // TBranch        *b_EF_xe80T_tclcw_loose;   //!
    // TBranch        *b_EF_xe80_tclcw;   //!
    // TBranch        *b_EF_xe80_tclcw_loose;   //!
    // TBranch        *b_EF_xe80_tclcw_tight;   //!
    // TBranch        *b_EF_xe80_tclcw_verytight;   //!
    // TBranch        *b_EF_xe80_tight;   //!
    // TBranch        *b_EF_xe90;   //!
    // TBranch        *b_EF_xe90_tclcw;   //!
    // TBranch        *b_EF_xe90_tclcw_tight;   //!
    // TBranch        *b_EF_xe90_tclcw_veryloose;   //!
    // TBranch        *b_EF_xe90_tclcw_verytight;   //!
    // TBranch        *b_EF_xe90_tight;   //!
    // TBranch        *b_EF_xe_NoCut_FEB_allL1;   //!
    // TBranch        *b_EF_xe_NoCut_allL1;   //!
    // TBranch        *b_EF_xe_NoCut_tclcw_allL1;   //!
    // TBranch        *b_EF_xs100;   //!
    // TBranch        *b_EF_xs120;   //!
    // TBranch        *b_EF_xs30;   //!
    // TBranch        *b_EF_xs45;   //!
    // TBranch        *b_EF_xs60;   //!
    // TBranch        *b_EF_xs75;   //!
    // TBranch        *b_EF_zerobias_NoAlg;   //!
    // TBranch        *b_EF_zerobias_Overlay_NoAlg;   //!
    // TBranch        *b_Eventshape_rhoKt3EM;   //!
    // TBranch        *b_Eventshape_rhoKt3LC;   //!
    // TBranch        *b_Eventshape_rhoKt4EM;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaJVF_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetAreaRhoEta5JVF_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetArea_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetArea_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetArea_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetArea_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetArea_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetArea_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetArea_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetArea_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetArea_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetArea_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetArea_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetArea_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetArea_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetArea_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_JetArea_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_STVF_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_STVF_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_STVF_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_STVF_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_STVF_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_STVF_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_STVF_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_STVF_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_STVF_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_STVF_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_STVF_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_STVF_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_STVF_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_STVF_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_STVF_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_Eflow_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_CellOut_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_MuonBoy_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_MuonBoy_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_MuonBoy_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_MuonBoy_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_MuonBoy_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_MuonBoy_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_MuonBoy_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_MuonBoy_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_MuonBoy_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_MuonBoy_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_MuonBoy_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_MuonBoy_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_MuonBoy_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_MuonBoy_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_MuonBoy_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Muid_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Muid_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Muid_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Muid_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Muid_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Muid_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Muid_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Muid_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Muid_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Muid_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Muid_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Muid_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Muid_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Muid_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Muid_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Staco_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Staco_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Staco_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Staco_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Staco_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Staco_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Staco_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Staco_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Staco_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Staco_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Staco_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Staco_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Staco_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Staco_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Isol_Staco_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Muid_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Muid_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Muid_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Muid_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Muid_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Muid_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Muid_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Muid_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Muid_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Muid_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Muid_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Muid_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Muid_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Muid_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Muid_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Staco_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Staco_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Staco_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Staco_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Staco_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Staco_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Staco_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Staco_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Staco_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Staco_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Staco_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Staco_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Staco_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Staco_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_NonIsol_Staco_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Muid_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Muid_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Muid_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Muid_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Muid_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Muid_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Muid_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Muid_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Muid_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Muid_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Muid_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Muid_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Muid_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Muid_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Muid_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Staco_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Staco_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Staco_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Staco_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Staco_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Staco_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Staco_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Staco_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Staco_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Staco_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Staco_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Staco_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Staco_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Staco_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Muon_Total_Staco_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefEle_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefEle_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefEle_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefEle_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefEle_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefEle_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefEle_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefEle_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefEle_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefEle_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefEle_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefEle_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefEle_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefEle_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefEle_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_STVF_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_STVF_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_STVF_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_STVF_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_STVF_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_STVF_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_STVF_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_STVF_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_STVF_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_STVF_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_STVF_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_STVF_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_STVF_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_STVF_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_STVF_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefFinal_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefGamma_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefGamma_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefGamma_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefGamma_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefGamma_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefGamma_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefGamma_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefGamma_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefGamma_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefGamma_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefGamma_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefGamma_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVFCut_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVFCut_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVFCut_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVFCut_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVFCut_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVFCut_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVFCut_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVFCut_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVFCut_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVFCut_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVFCut_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVFCut_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVFCut_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVFCut_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVFCut_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVF_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVF_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVF_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVF_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVF_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVF_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVF_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVF_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVF_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVF_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVF_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVF_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVF_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVF_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_JVF_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefJet_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Muid_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Muid_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Muid_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Muid_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Muid_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Muid_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Muid_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Muid_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Muid_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Muid_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Muid_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Muid_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Muid_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Muid_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Muid_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Staco_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Staco_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Staco_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Staco_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Staco_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Staco_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Staco_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Staco_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Staco_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Staco_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Staco_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Staco_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Staco_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Staco_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Staco_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Muid_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Muid_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Muid_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Muid_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Muid_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Muid_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Muid_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Muid_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Muid_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Muid_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Muid_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Muid_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Muid_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Muid_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Muid_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Staco_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Staco_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Staco_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Staco_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Staco_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Staco_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Staco_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Staco_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Staco_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Staco_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Staco_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Staco_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Staco_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Staco_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_Staco_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_Track_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_RefMuon_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_SoftJets_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_SoftJets_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_SoftJets_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_SoftJets_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_SoftJets_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_SoftJets_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_SoftJets_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_SoftJets_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_SoftJets_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_SoftJets_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_SoftJets_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_SoftJets_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_SoftJets_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_SoftJets_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_SoftJets_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Track_etx;   //!
    // TBranch        *b_MET_Egamma10NoTau_Track_etx_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Track_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Track_etx_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Track_ety;   //!
    // TBranch        *b_MET_Egamma10NoTau_Track_ety_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Track_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Track_ety_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Track_phi_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Track_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Track_phi_ForwardReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Track_sumet;   //!
    // TBranch        *b_MET_Egamma10NoTau_Track_sumet_CentralReg;   //!
    // TBranch        *b_MET_Egamma10NoTau_Track_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Egamma10NoTau_Track_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Track_etx;   //!
    // TBranch        *b_MET_Track_etx_CentralReg;   //!
    // TBranch        *b_MET_Track_etx_EndcapRegion;   //!
    // TBranch        *b_MET_Track_etx_ForwardReg;   //!
    // TBranch        *b_MET_Track_ety;   //!
    // TBranch        *b_MET_Track_ety_CentralReg;   //!
    // TBranch        *b_MET_Track_ety_EndcapRegion;   //!
    // TBranch        *b_MET_Track_ety_ForwardReg;   //!
    // TBranch        *b_MET_Track_phi_CentralReg;   //!
    // TBranch        *b_MET_Track_phi_EndcapRegion;   //!
    // TBranch        *b_MET_Track_phi_ForwardReg;   //!
    // TBranch        *b_MET_Track_sumet;   //!
    // TBranch        *b_MET_Track_sumet_CentralReg;   //!
    // TBranch        *b_MET_Track_sumet_EndcapRegion;   //!
    // TBranch        *b_MET_Track_sumet_ForwardReg;   //!
    // TBranch        *b_MET_Truth_IntCentral_etx;   //!
    // TBranch        *b_MET_Truth_IntCentral_ety;   //!
    // TBranch        *b_MET_Truth_IntCentral_sumet;   //!
    // TBranch        *b_MET_Truth_IntFwd_etx;   //!
    // TBranch        *b_MET_Truth_IntFwd_ety;   //!
    // TBranch        *b_MET_Truth_IntFwd_sumet;   //!
    // TBranch        *b_MET_Truth_IntMuons_etx;   //!
    // TBranch        *b_MET_Truth_IntMuons_ety;   //!
    // TBranch        *b_MET_Truth_IntMuons_sumet;   //!
    // TBranch        *b_MET_Truth_IntOutCover_etx;   //!
    // TBranch        *b_MET_Truth_IntOutCover_ety;   //!
    // TBranch        *b_MET_Truth_IntOutCover_sumet;   //!
    // TBranch        *b_MET_Truth_Int_etx;   //!
    // TBranch        *b_MET_Truth_Int_ety;   //!
    // TBranch        *b_MET_Truth_Int_sumet;   //!
    // TBranch        *b_MET_Truth_NonInt_etx;   //!
    // TBranch        *b_MET_Truth_NonInt_ety;   //!
    // TBranch        *b_MET_Truth_NonInt_sumet;   //!
    // TBranch        *b_SUSY_Spart1_pdgId;   //!
    // TBranch        *b_SUSY_Spart2_pdgId;   //!
    // TBranch        *b_SkimDecision_DAODEGAMMA_accepted;   //!
    // TBranch        *b_SkimDecision_DAODEGAMMA_name;   //!
    // TBranch        *b_SkimDecision_DAODJETS_accepted;   //!
    // TBranch        *b_SkimDecision_DAODJETS_name;   //!
    // TBranch        *b_SkimDecision_DAODMUONS_accepted;   //!
    // TBranch        *b_SkimDecision_DAODMUONS_name;   //!
    // TBranch        *b_SkimDecision_NTPSUSY_accepted;   //!
    // TBranch        *b_SkimDecision_NTPSUSY_name;   //!
    // TBranch        *b_actualIntPerXing;   //!
    // TBranch        *b_bb_cl_E_em;   //!
    // TBranch        *b_bb_cl_E_had;   //!
    // TBranch        *b_bb_cl_bbDecision;   //!
    // TBranch        *b_bb_cl_cellmaxfrac;   //!
    // TBranch        *b_bb_cl_centerlambda;   //!
    // TBranch        *b_bb_cl_centermag;   //!
    // TBranch        *b_bb_cl_deltaPhi;   //!
    // TBranch        *b_bb_cl_deltaTheta;   //!
    // TBranch        *b_bb_cl_drdz;   //!
    // TBranch        *b_bb_cl_eta;   //!
    // TBranch        *b_bb_cl_firstEdens;   //!
    // TBranch        *b_bb_cl_lateral;   //!
    // TBranch        *b_bb_cl_longitudinal;   //!
    // TBranch        *b_bb_cl_n;   //!
    // TBranch        *b_bb_cl_phi;   //!
    // TBranch        *b_bb_cl_pt;   //!
    // TBranch        *b_bb_cl_secondR;   //!
    // TBranch        *b_bb_cl_secondlambda;   //!
    // TBranch        *b_bb_cl_time;   //!
    // TBranch        *b_bb_decision;   //!
    // TBranch        *b_bb_direction;   //!
    // TBranch        *b_bb_jet_bbDecision;   //!
    // TBranch        *b_bb_jet_n;   //!
    // TBranch        *b_bb_numClusterShape;   //!
    // TBranch        *b_bb_numMatched;   //!
    // TBranch        *b_bb_numNoTimeLoose;   //!
    // TBranch        *b_bb_numNoTimeMedium;   //!
    // TBranch        *b_bb_numNoTimeTight;   //!
    // TBranch        *b_bb_numOneSidedLoose;   //!
    // TBranch        *b_bb_numOneSidedMedium;   //!
    // TBranch        *b_bb_numOneSidedTight;   //!
    // TBranch        *b_bb_numSegment;   //!
    // TBranch        *b_bb_numSegmentAC;   //!
    // TBranch        *b_bb_numSegmentACNoTime;   //!
    // TBranch        *b_bb_numSegmentEarly;   //!
    // TBranch        *b_bb_numTwoSided;   //!
    // TBranch        *b_bb_numTwoSidedNoTime;   //!
    // TBranch        *b_bcid;   //!
    // TBranch        *b_bunch_configID;   //!
    // TBranch        *b_coreError;   //!
    // TBranch        *b_detmask0;   //!
    // TBranch        *b_detmask1;   //!
    // TBranch        *b_el_E233;   //!
    // TBranch        *b_el_E237;   //!
    // TBranch        *b_el_E277;   //!
    // TBranch        *b_el_E;   //!
    // TBranch        *b_el_ED_Njets;   //!
    // TBranch        *b_el_ED_median;   //!
    // TBranch        *b_el_ED_sigma;   //!
    // TBranch        *b_el_EF_dr;   //!
    // TBranch        *b_el_EF_index;   //!
    // TBranch        *b_el_Emax2;   //!
    // TBranch        *b_el_Emins1;   //!
    // TBranch        *b_el_Es0;   //!
    // TBranch        *b_el_Es1;   //!
    // TBranch        *b_el_Es2;   //!
    // TBranch        *b_el_Es3;   //!
    // TBranch        *b_el_Et;   //!
    // TBranch        *b_el_Etcone15;   //!
    // TBranch        *b_el_Etcone20;   //!
    // TBranch        *b_el_Etcone25;   //!
    // TBranch        *b_el_Etcone30;   //!
    // TBranch        *b_el_Etcone35;   //!
    // TBranch        *b_el_Etcone40;   //!
    // TBranch        *b_el_Etcone40_ED_corrected;   //!
    // TBranch        *b_el_Etcone40_corrected;   //!
    // TBranch        *b_el_Etcone45;   //!
    // TBranch        *b_el_Ethad1;   //!
    // TBranch        *b_el_Ethad;   //!
    // TBranch        *b_el_MET_Egamma10NoTau_n;   //!
    // TBranch        *b_el_MET_n;   //!
    // TBranch        *b_el_MET_statusWord;   //!
    // TBranch        *b_el_MET_wet;   //!
    // TBranch        *b_el_MET_wpx;   //!
    // TBranch        *b_el_MET_wpy;   //!
    // TBranch        *b_el_Rconv;   //!
    // TBranch        *b_el_TRTHighTHitsRatio;   //!
    // TBranch        *b_el_TRTHighTOutliersRatio;   //!
    // TBranch        *b_el_cellmaxfrac;   //!
    // TBranch        *b_el_centerlambda;   //!
    // TBranch        *b_el_cl_time;   //!
    // TBranch        *b_el_convFlag;   //!
    // TBranch        *b_el_convanglematch;   //!
    // TBranch        *b_el_convtrackmatch;   //!
    // TBranch        *b_el_convtrk1nBLHits;   //!
    // TBranch        *b_el_convtrk1nPixHits;   //!
    // TBranch        *b_el_convtrk1nSCTHits;   //!
    // TBranch        *b_el_convtrk1nTRTHits;   //!
    // TBranch        *b_el_convtrk2nBLHits;   //!
    // TBranch        *b_el_convtrk2nPixHits;   //!
    // TBranch        *b_el_convtrk2nSCTHits;   //!
    // TBranch        *b_el_convtrk2nTRTHits;   //!
    // TBranch        *b_el_convvtxchi2;   //!
    // TBranch        *b_el_convvtxx;   //!
    // TBranch        *b_el_convvtxy;   //!
    // TBranch        *b_el_convvtxz;   //!
    // TBranch        *b_el_deltaEs;   //!
    // TBranch        *b_el_deltaPhiFromLast;   //!
    // TBranch        *b_el_deltaPhiRot;   //!
    // TBranch        *b_el_deltaeta1;   //!
    // TBranch        *b_el_deltaeta2;   //!
    // TBranch        *b_el_deltaphi2;   //!
    // TBranch        *b_el_deltaphiRescaled;   //!
    // TBranch        *b_el_depth;   //!
    // TBranch        *b_el_emaxs1;   //!
    // TBranch        *b_el_errz;   //!
    TBranch        *b_el_eta;   //!
    // TBranch        *b_el_etaSampling1;   //!
    // TBranch        *b_el_etacorrmag;   //!
    // TBranch        *b_el_etap;   //!
    // TBranch        *b_el_etas0;   //!
    // TBranch        *b_el_etas1;   //!
    // TBranch        *b_el_etas2;   //!
    // TBranch        *b_el_etas3;   //!
    // TBranch        *b_el_expectBLayerHit;   //!
    // TBranch        *b_el_expectHitInBLayer;   //!
    // TBranch        *b_el_f1;   //!
    // TBranch        *b_el_f1core;   //!
    // TBranch        *b_el_f3;   //!
    // TBranch        *b_el_f3core;   //!
    // TBranch        *b_el_firstEdens;   //!
    // TBranch        *b_el_fside;   //!
    // TBranch        *b_el_goodOQ;   //!
    // TBranch        *b_el_hasconv;   //!
    // TBranch        *b_el_hastrack;   //!
    // TBranch        *b_el_isConv;   //!
    // TBranch        *b_el_isEM;   //!
    // TBranch        *b_el_isEMLoose;   //!
    // TBranch        *b_el_isEMMedium;   //!
    // TBranch        *b_el_isEMTight;   //!
    // TBranch        *b_el_lateral;   //!
    // TBranch        *b_el_likelihoodsPixeldEdx;   //!
    // TBranch        *b_el_longitudinal;   //!
    // TBranch        *b_el_loose;   //!
    // TBranch        *b_el_looseIso;   //!
    // TBranch        *b_el_loosePP;   //!
    // TBranch        *b_el_loosePPIso;   //!
    // TBranch        *b_el_m;   //!
    // TBranch        *b_el_massPixeldEdx;   //!
    // TBranch        *b_el_maxEcell_energy;   //!
    // TBranch        *b_el_maxEcell_gain;   //!
    // TBranch        *b_el_maxEcell_onlId;   //!
    // TBranch        *b_el_maxEcell_time;   //!
    // TBranch        *b_el_maxEcell_x;   //!
    // TBranch        *b_el_maxEcell_y;   //!
    // TBranch        *b_el_maxEcell_z;   //!
    // TBranch        *b_el_medium;   //!
    // TBranch        *b_el_mediumIso;   //!
    // TBranch        *b_el_mediumIsoWithoutTrack;   //!
    // TBranch        *b_el_mediumPPIso;   //!
    // TBranch        *b_el_mediumWithoutTrack;   //!
    // TBranch        *b_el_nBLHits;   //!
    // TBranch        *b_el_nBLSharedHits;   //!
    // TBranch        *b_el_nBLayerOutliers;   //!
    // TBranch        *b_el_nBLayerSplitHits;   //!
    // TBranch        *b_el_nContribPixelLayers;   //!
    // TBranch        *b_el_nConv;   //!
    // TBranch        *b_el_nDoubleTrackConv;   //!
    // TBranch        *b_el_nGangedFlaggedFakes;   //!
    // TBranch        *b_el_nGangedPixels;   //!
    // TBranch        *b_el_nGoodHitsPixeldEdx;   //!
    // TBranch        *b_el_nPixHits;   //!
    // TBranch        *b_el_nPixHoles;   //!
    // TBranch        *b_el_nPixSharedHits;   //!
    // TBranch        *b_el_nPixSplitHits;   //!
    // TBranch        *b_el_nPixelDeadSensors;   //!
    // TBranch        *b_el_nPixelOutliers;   //!
    // TBranch        *b_el_nPixelSpoiltHits;   //!
    // TBranch        *b_el_nSCTDeadSensors;   //!
    // TBranch        *b_el_nSCTDoubleHoles;   //!
    // TBranch        *b_el_nSCTHits;   //!
    // TBranch        *b_el_nSCTHoles;   //!
    // TBranch        *b_el_nSCTOutliers;   //!
    // TBranch        *b_el_nSCTSharedHits;   //!
    // TBranch        *b_el_nSCTSpoiltHits;   //!
    // TBranch        *b_el_nSingleTrackConv;   //!
    // TBranch        *b_el_nTRTHighTHits;   //!
    // TBranch        *b_el_nTRTHighTOutliers;   //!
    // TBranch        *b_el_nTRTHits;   //!
    // TBranch        *b_el_nTRTHoles;   //!
    // TBranch        *b_el_nTRTOutliers;   //!
    // TBranch        *b_el_nTRTXenonHits;   //!
    // TBranch        *b_el_nucone20;   //!
    // TBranch        *b_el_nucone20_trk500MeV;   //!
    // TBranch        *b_el_nucone20_zpv05;   //!
    // TBranch        *b_el_nucone30;   //!
    // TBranch        *b_el_nucone30_trk500MeV;   //!
    // TBranch        *b_el_nucone30_zpv05;   //!
    // TBranch        *b_el_nucone40;   //!
    // TBranch        *b_el_nucone40_trk500MeV;   //!
    // TBranch        *b_el_nucone40_zpv05;   //!
    // TBranch        *b_el_originbkg;   //!
    TBranch        *b_el_phi;   //!
    // TBranch        *b_el_phis0;   //!
    // TBranch        *b_el_phis1;   //!
    // TBranch        *b_el_phis2;   //!
    // TBranch        *b_el_phis3;   //!
    // TBranch        *b_el_pixeldEdx;   //!
    // TBranch        *b_el_pos7;   //!
    // TBranch        *b_el_pt1conv;   //!
    // TBranch        *b_el_pt2conv;   //!
    // TBranch        *b_el_pt;   //!
    // TBranch        *b_el_ptcone20;   //!
    // TBranch        *b_el_ptcone20_trk500MeV;   //!
    // TBranch        *b_el_ptcone20_zpv05;   //!
    // TBranch        *b_el_ptcone30_trk500MeV;   //!
    // TBranch        *b_el_ptcone30_zpv05;   //!
    // TBranch        *b_el_ptcone40;   //!
    // TBranch        *b_el_ptcone40_trk500MeV;   //!
    // TBranch        *b_el_ptcone40_zpv05;   //!
    // TBranch        *b_el_ptconv;   //!
    // TBranch        *b_el_px;   //!
    // TBranch        *b_el_py;   //!
    // TBranch        *b_el_pz;   //!
    // TBranch        *b_el_pzconv;   //!
    // TBranch        *b_el_refittedTrack_n;   //!
    // TBranch        *b_el_reta;   //!
    // TBranch        *b_el_rphi;   //!
    // TBranch        *b_el_rphiallcalo;   //!
    // TBranch        *b_el_secondR;   //!
    // TBranch        *b_el_secondlambda;   //!
    // TBranch        *b_el_tight;   //!
    // TBranch        *b_el_tightIso;   //!
    // TBranch        *b_el_tightIsoWithoutTrack;   //!
    // TBranch        *b_el_tightPPIso;   //!
    // TBranch        *b_el_tightWithoutTrack;   //!
    // TBranch        *b_el_topoEtcone20;   //!
    // TBranch        *b_el_topoEtcone20_corrected;   //!
    // TBranch        *b_el_topoEtcone30;   //!
    // TBranch        *b_el_topoEtcone40;   //!
    // TBranch        *b_el_topoEtcone40_corrected;   //!
    // TBranch        *b_el_trackIPEstimate_d0_biasedpvunbiased;   //!
    // TBranch        *b_el_trackIPEstimate_sigd0_biasedpvunbiased;   //!
    // TBranch        *b_el_trackIPEstimate_sigz0_biasedpvunbiased;   //!
    // TBranch        *b_el_trackIPEstimate_sigz0_unbiasedpvunbiased;   //!
    // TBranch        *b_el_trackIPEstimate_z0_biasedpvunbiased;   //!
    // TBranch        *b_el_trackd0;   //!
    // TBranch        *b_el_trackd0_physics;   //!
    // TBranch        *b_el_trackd0pv;   //!
    // TBranch        *b_el_trackpt;   //!
    // TBranch        *b_el_trackqoverp;   //!
    // TBranch        *b_el_tracksigd0pv;   //!
    // TBranch        *b_el_tracksigz0pv;   //!
    // TBranch        *b_el_tracktheta;   //!
    // TBranch        *b_el_trackz0;   //!
    // TBranch        *b_el_trackz0pv;   //!
    // TBranch        *b_el_truth_E;   //!
    // TBranch        *b_el_truth_eta;   //!
    // TBranch        *b_el_truth_hasHardBrem;   //!
    // TBranch        *b_el_truth_index;   //!
    // TBranch        *b_el_truth_matched;   //!
    // TBranch        *b_el_truth_mothertype;   //!
    // TBranch        *b_el_truth_phi;   //!
    // TBranch        *b_el_truth_pt;   //!
    // TBranch        *b_el_truth_status;   //!
    // TBranch        *b_el_truth_type;   //!
    // TBranch        *b_el_typebkg;   //!
    // TBranch        *b_el_vertweight;   //!
    // TBranch        *b_el_weta2;   //!
    // TBranch        *b_el_ws3;   //!
    // TBranch        *b_el_wstot;   //!
    // TBranch        *b_el_zconv;   //!
    // TBranch        *b_el_zvertex;   //!
    // TBranch        *b_fwdError;   //!
    // TBranch        *b_fwdFlags;   //!
    // TBranch        *b_isCalibration;   //!
    // TBranch        *b_isSimulation;   //!
    // TBranch        *b_isTestBeam;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_ActiveArea;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_BAD_CELLS_CORR_E;   //!
    TBranch        *b_jet_AntiKt4LCTopo_BCH_CORR_CELL;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_BCH_CORR_DOTX;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_BCH_CORR_JET_FORCELL;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_E;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_EMJES;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_EMJES_EtaCorr;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_EMJESnooffset;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_ENG_BAD_CELLS;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_EtaOrigin;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_GSCFactorF;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_LCJES;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_LCJES_EtaCorr;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_MET_Egamma10NoTau_n;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_MET_n;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_MET_statusWord;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_MET_wet;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_MET_wpx;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_MET_wpy;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_MOrigin;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_N_BAD_CELLS;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_N_BAD_CELLS_CORR;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_Nconst;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_NumTowers;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_Offset;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_OriginIndex;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_PhiOrigin;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_SmearingFactor;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_Timing;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_TruthMF;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_TruthMFindex;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_WIDTH;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_WidthFraction;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_bbDecision;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_constscale_pt;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_EMB1;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_EMB2;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_EMB3;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_EME1;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_EME2;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_EME3;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_FCAL0;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_FCAL1;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_FCAL2;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_HEC0;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_HEC1;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_HEC2;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_HEC3;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_PreSamplerB;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_PreSamplerE;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_TileBar0;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_TileBar1;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_TileBar2;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_TileExt0;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_TileExt1;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_TileExt2;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_TileGap1;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_TileGap2;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_e_TileGap3;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_econst_default;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_emscale_E;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_emscale_eta;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_emscale_m;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_emscale_phi;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_emscale_pt;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_etaconst_default;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_assoctrk_index;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_assoctrk_n;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_ip2d_isValid;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_ip2d_ntrk;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_ip2d_pb;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_ip2d_pu;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_ip3d_isValid;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_ip3d_ntrk;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_ip3d_pb;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_ip3d_pc;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_ip3d_pu;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfit_deltaEta;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfit_deltaPhi;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfit_efrc;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfit_isValid;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfit_mass;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfit_ntrkAtVx;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfit_nvtx1t;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfit_nvtx;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfit_pb;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfit_pc;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfit_pu;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfit_sig3d;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfitc_doublePropName;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfitc_doublePropValue;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfitc_intPropName;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfitc_intPropValue;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfitc_isValid;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfitc_pb;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfitc_pc;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfitc_pu;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfitcomb_isValid;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfitcomb_pb;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfitcomb_pc;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_jfitcomb_pu;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv0p_chi2;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv0p_cov_xy;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv0p_cov_xz;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv0p_cov_yz;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv0p_efrc;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv0p_err_x;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv0p_err_y;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv0p_err_z;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv0p_isValid;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv0p_mass;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv0p_n2t;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv0p_ndof;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv0p_ntrk;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv0p_ntrkj;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv0p_ntrkv;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv0p_x;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv0p_y;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv0p_z;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv1_isValid;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv1_pb;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv1_pc;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv1_pu;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv2_isValid;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv2_pb;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_sv2_pu;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_svp_chi2;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_svp_cov_xy;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_svp_cov_xz;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_svp_cov_yz;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_svp_efrc;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_svp_err_x;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_svp_err_y;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_svp_err_z;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_svp_isValid;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_svp_mass;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_svp_n2t;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_svp_ndof;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_svp_ntrk;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_svp_ntrkj;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_svp_ntrkv;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_svp_x;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_svp_y;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_component_svp_z;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_truth_BHadronpdg;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_truth_dRminToB;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_truth_dRminToC;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_truth_dRminToT;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_truth_vx_x;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_truth_vx_y;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_truth_vx_z;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_weight_Comb;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_weight_GbbNN;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_weight_IP2D;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_weight_IP3D;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_weight_JetFitterCOMBNN;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_weight_JetFitterCharm;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_weight_JetFitterTagNN;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_weight_MV2;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_weight_SV0;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_weight_SV1;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_weight_SV2;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_weight_SecondSoftMuonTagChi2;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_flavor_weight_SoftMuonTagChi2;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_isBadLoose;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_isBadLooseMinus;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_isBadMedium;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_isBadTight;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_isUgly;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_jvtx_x;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_jvtx_y;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_jvtx_z;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_jvtxfFull;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_n90;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_nTrk_allpv_1GeV;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_nTrk_pv0_1GeV;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_nTrk_pv0_500MeV;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_ootFracCells10;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_ootFracCells5;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_ootFracClusters10;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_ootFracClusters5;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_phiconst_default;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_ptconst_default;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_sumPtTrk_allpv_1GeV;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_sumPtTrk_pv0_1GeV;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_tgap3f;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_trackWIDTH_allpv_1GeV;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_trackWIDTH_pv0_1GeV;   //!
    // TBranch        *b_jet_AntiKt4LCTopo_weightconst_default;   //!
    // TBranch        *b_jet_AntiKt4TrackZ_E;   //!
    // TBranch        *b_jet_AntiKt4TrackZ_eta;   //!
    // TBranch        *b_jet_AntiKt4TrackZ_m;   //!
    // TBranch        *b_jet_AntiKt4TrackZ_n;   //!
    // TBranch        *b_jet_AntiKt4TrackZ_phi;   //!
    // TBranch        *b_jet_AntiKt4TrackZ_pt;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_ActiveArea;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_ActiveAreaE;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_ActiveAreaPx;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_ActiveAreaPy;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_ActiveAreaPz;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_AverageLArQF;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_BAD_CELLS_CORR_E;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_BCH_CORR_CELL;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_BCH_CORR_DOTX;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_BCH_CORR_JET;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_BCH_CORR_JET_FORCELL;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_E;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_EMJES;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_EMJES_EtaCorr;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_EMJESnooffset;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_ENG_BAD_CELLS;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_EtaOrigin;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_HECQuality;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_LArQuality;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_LCJES;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_LCJES_EtaCorr;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_MOrigin;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_N_BAD_CELLS;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_N_BAD_CELLS_CORR;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_NegativeE;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_NumTowers;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_Offset;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_OriginIndex;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_PhiOrigin;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_SamplingMax;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_Timing;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_WIDTH;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_emfrac;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_emscale_E;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_emscale_eta;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_emscale_m;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_emscale_phi;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_emscale_pt;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_eta;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_flavor_truth_BHadronpdg;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_flavor_truth_dRminToB;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_flavor_truth_dRminToC;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_flavor_truth_dRminToT;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_flavor_truth_label;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_flavor_truth_vx_x;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_flavor_truth_vx_y;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_flavor_truth_vx_z;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_fracSamplingMax;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_hecf;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_isBadLoose;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_isBadLooseMinus;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_isBadMedium;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_isBadTight;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_isUgly;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_m;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_n90;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_n;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_ootFracCells10;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_ootFracCells5;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_ootFracClusters10;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_ootFracClusters5;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_phi;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_pt;   //!
    // TBranch        *b_jet_AntiKt4TruthJets_tgap3f;   //!
    // TBranch        *b_jet_AntiKt6LCTopo_E;   //!
    // TBranch        *b_jet_AntiKt6LCTopo_eta;   //!
    // TBranch        *b_jet_AntiKt6LCTopo_m;   //!
    // TBranch        *b_jet_AntiKt6LCTopo_n;   //!
    // TBranch        *b_jet_AntiKt6LCTopo_phi;   //!
    // TBranch        *b_jet_AntiKt6LCTopo_pt;   //!
    // TBranch        *b_jet_AntiKt6TopoEM_E;   //!
    // TBranch        *b_jet_AntiKt6TopoEM_eta;   //!
    // TBranch        *b_jet_AntiKt6TopoEM_m;   //!
    // TBranch        *b_jet_AntiKt6TopoEM_n;   //!
    // TBranch        *b_jet_AntiKt6TopoEM_phi;   //!
    // TBranch        *b_jet_AntiKt6TopoEM_pt;   //!
    // TBranch        *b_larFlags;   //!
    // TBranch        *b_mcVx_n;   //!
    // TBranch        *b_mcVx_x;   //!
    // TBranch        *b_mcVx_y;   //!
    // TBranch        *b_mcVx_z;   //!
    // TBranch        *b_mc_event_number;   //!
    // TBranch        *b_mc_vx_x;   //!
    // TBranch        *b_mc_vx_y;   //!
    // TBranch        *b_mc_vx_z;   //!
    // TBranch        *b_mcevt_alphaQCD;   //!
    // TBranch        *b_mcevt_alphaQED;   //!
    // TBranch        *b_mcevt_event_number;   //!
    // TBranch        *b_mcevt_event_scale;   //!
    // TBranch        *b_mcevt_n;   //!
    // TBranch        *b_mcevt_nparticle;   //!
    // TBranch        *b_mcevt_pdf1;   //!
    // TBranch        *b_mcevt_pdf2;   //!
    // TBranch        *b_mcevt_pdf_id1;   //!
    // TBranch        *b_mcevt_pdf_id2;   //!
    // TBranch        *b_mcevt_pdf_scale;   //!
    // TBranch        *b_mcevt_pdf_x1;   //!
    // TBranch        *b_mcevt_pdf_x2;   //!
    // TBranch        *b_mcevt_pileUpType;   //!
    // TBranch        *b_mcevt_signal_process_id;   //!
    // TBranch        *b_mcevt_weight;   //!
    // TBranch        *b_mu_staco_E;   //!
    // TBranch        *b_mu_staco_EFCB_index;   //!
    // TBranch        *b_mu_staco_EFME_index;   //!
    // TBranch        *b_mu_staco_EFMG_index;   //!
    // TBranch        *b_mu_staco_MET_Egamma10NoTau_n;   //!
    // TBranch        *b_mu_staco_MET_Egamma10NoTau_statusWord;   //!
    // TBranch        *b_mu_staco_MET_Egamma10NoTau_wet;   //!
    // TBranch        *b_mu_staco_MET_Egamma10NoTau_wpx;   //!
    // TBranch        *b_mu_staco_MET_Egamma10NoTau_wpy;   //!
    // TBranch        *b_mu_staco_MET_n;   //!
    // TBranch        *b_mu_staco_MET_statusWord;   //!
    // TBranch        *b_mu_staco_MET_wet;   //!
    // TBranch        *b_mu_staco_MET_wpx;   //!
    // TBranch        *b_mu_staco_MET_wpy;   //!
    // TBranch        *b_mu_staco_allauthor;   //!
    // TBranch        *b_mu_staco_alsoFoundByCaloMuonId;   //!
    // TBranch        *b_mu_staco_alsoFoundByLowPt;   //!
    // TBranch        *b_mu_staco_author;   //!
    // TBranch        *b_mu_staco_barrelSectors;   //!
    // TBranch        *b_mu_staco_bestMatch;   //!
    // TBranch        *b_mu_staco_caloLRLikelihood;   //!
    // TBranch        *b_mu_staco_caloMuonIdTag;   //!
    // TBranch        *b_mu_staco_cb_d0_exPV;   //!
    // TBranch        *b_mu_staco_cb_phi_exPV;   //!
    // TBranch        *b_mu_staco_cb_qoverp_exPV;   //!
    // TBranch        *b_mu_staco_cb_theta_exPV;   //!
    // TBranch        *b_mu_staco_cb_z0_exPV;   //!
    // TBranch        *b_mu_staco_cov_d0_exPV;   //!
    // TBranch        *b_mu_staco_cov_d0_phi_exPV;   //!
    // TBranch        *b_mu_staco_cov_d0_qoverp_exPV;   //!
    // TBranch        *b_mu_staco_cov_d0_theta_exPV;   //!
    // TBranch        *b_mu_staco_cov_d0_z0_exPV;   //!
    // TBranch        *b_mu_staco_cov_phi_exPV;   //!
    // TBranch        *b_mu_staco_cov_phi_qoverp_exPV;   //!
    // TBranch        *b_mu_staco_cov_phi_theta_exPV;   //!
    // TBranch        *b_mu_staco_cov_theta_exPV;   //!
    // TBranch        *b_mu_staco_cov_theta_qoverp_exPV;   //!
    // TBranch        *b_mu_staco_cov_z0_exPV;   //!
    // TBranch        *b_mu_staco_cov_z0_phi_exPV;   //!
    // TBranch        *b_mu_staco_cov_z0_qoverp_exPV;   //!
    // TBranch        *b_mu_staco_cov_z0_theta_exPV;   //!
    // TBranch        *b_mu_staco_endcapSectors;   //!
    // TBranch        *b_mu_staco_energyLossErr;   //!
    // TBranch        *b_mu_staco_energyLossPar;   //!
    // TBranch        *b_mu_staco_energyLossType;   //!
    // TBranch        *b_mu_staco_etCore;   //!
    // TBranch        *b_mu_staco_etcone20;   //!
    // TBranch        *b_mu_staco_etcone40;   //!
    // TBranch        *b_mu_staco_etconeNoEm10;   //!
    // TBranch        *b_mu_staco_etconeNoEm20;   //!
    // TBranch        *b_mu_staco_etconeNoEm30;   //!
    // TBranch        *b_mu_staco_etconeNoEm40;   //!
    // TBranch        *b_mu_staco_hastrack;   //!
    // TBranch        *b_mu_staco_id_cov_d0_exPV;   //!
    // TBranch        *b_mu_staco_id_cov_d0_phi_exPV;   //!
    // TBranch        *b_mu_staco_id_cov_d0_qoverp_exPV;   //!
    // TBranch        *b_mu_staco_id_cov_d0_theta_exPV;   //!
    // TBranch        *b_mu_staco_id_cov_d0_z0_exPV;   //!
    // TBranch        *b_mu_staco_id_cov_phi_exPV;   //!
    // TBranch        *b_mu_staco_id_cov_phi_qoverp_exPV;   //!
    // TBranch        *b_mu_staco_id_cov_phi_theta_exPV;   //!
    // TBranch        *b_mu_staco_id_cov_qoverp_exPV;   //!
    // TBranch        *b_mu_staco_id_cov_theta_exPV;   //!
    // TBranch        *b_mu_staco_id_cov_theta_qoverp_exPV;   //!
    // TBranch        *b_mu_staco_id_cov_z0_exPV;   //!
    // TBranch        *b_mu_staco_id_cov_z0_phi_exPV;   //!
    // TBranch        *b_mu_staco_id_cov_z0_qoverp_exPV;   //!
    // TBranch        *b_mu_staco_id_cov_z0_theta_exPV;   //!
    // TBranch        *b_mu_staco_id_d0;   //!
    // TBranch        *b_mu_staco_id_d0_exPV;   //!
    // TBranch        *b_mu_staco_id_phi;   //!
    // TBranch        *b_mu_staco_id_phi_exPV;   //!
    // TBranch        *b_mu_staco_id_qoverp;   //!
    // TBranch        *b_mu_staco_id_theta;   //!
    // TBranch        *b_mu_staco_id_z0;   //!
    // TBranch        *b_mu_staco_id_z0_exPV;   //!
    // TBranch        *b_mu_staco_ie_d0;   //!
    // TBranch        *b_mu_staco_ie_d0_exPV;   //!
    // TBranch        *b_mu_staco_ie_phi;   //!
    // TBranch        *b_mu_staco_ie_phi_exPV;   //!
    // TBranch        *b_mu_staco_ie_qoverp;   //!
    // TBranch        *b_mu_staco_ie_qoverp_exPV;   //!
    // TBranch        *b_mu_staco_ie_theta;   //!
    // TBranch        *b_mu_staco_ie_theta_exPV;   //!
    // TBranch        *b_mu_staco_ie_z0;   //!
    // TBranch        *b_mu_staco_ie_z0_exPV;   //!
    // TBranch        *b_mu_staco_isCaloMuonId;   //!
    // TBranch        *b_mu_staco_isLowPtReconstructedMuon;   //!
    // TBranch        *b_mu_staco_isSiliconAssociatedForwardMuon;   //!
    // TBranch        *b_mu_staco_isStandAloneMuon;   //!
    // TBranch        *b_mu_staco_loose;   //!
    // TBranch        *b_mu_staco_m;   //!
    // TBranch        *b_mu_staco_matchchi2;   //!
    // TBranch        *b_mu_staco_matchndof;   //!
    // TBranch        *b_mu_staco_mc_dr;   //!
    // TBranch        *b_mu_staco_mc_index;   //!
    // TBranch        *b_mu_staco_me_cov_d0_exPV;   //!
    // TBranch        *b_mu_staco_me_cov_phi_exPV;   //!
    // TBranch        *b_mu_staco_me_cov_qoverp_exPV;   //!
    // TBranch        *b_mu_staco_me_cov_theta_exPV;   //!
    // TBranch        *b_mu_staco_me_cov_z0_exPV;   //!
    // TBranch        *b_mu_staco_me_d0;   //!
    // TBranch        *b_mu_staco_me_d0_exPV;   //!
    // TBranch        *b_mu_staco_me_phi;   //!
    // TBranch        *b_mu_staco_me_phi_exPV;   //!
    // TBranch        *b_mu_staco_me_qoverp;   //!
    // TBranch        *b_mu_staco_me_theta;   //!
    // TBranch        *b_mu_staco_me_z0;   //!
    // TBranch        *b_mu_staco_me_z0_exPV;   //!
    // TBranch        *b_mu_staco_medium;   //!
    // TBranch        *b_mu_staco_momentumBalanceSignificance;   //!
    // TBranch        *b_mu_staco_ms_d0;   //!
    // TBranch        *b_mu_staco_ms_z0;   //!
    // TBranch        *b_mu_staco_nBLSharedHits;   //!
    // TBranch        *b_mu_staco_nCSCEtaHits;   //!
    // TBranch        *b_mu_staco_nCSCEtaHoles;   //!
    // TBranch        *b_mu_staco_nCSCPhiHits;   //!
    // TBranch        *b_mu_staco_nCSCPhiHoles;   //!
    // TBranch        *b_mu_staco_nCSCUnspoiledEtaHits;   //!
    // TBranch        *b_mu_staco_nGangedPixels;   //!
    // TBranch        *b_mu_staco_nMDTBEEHits;   //!
    // TBranch        *b_mu_staco_nMDTBIHits;   //!
    // TBranch        *b_mu_staco_nMDTBIS78Hits;   //!
    // TBranch        *b_mu_staco_nMDTBMHits;   //!
    // TBranch        *b_mu_staco_nMDTBOHits;   //!
    // TBranch        *b_mu_staco_nMDTEEHits;   //!
    // TBranch        *b_mu_staco_nMDTEIHits;   //!
    // TBranch        *b_mu_staco_nMDTEMHits;   //!
    // TBranch        *b_mu_staco_nMDTEOHits;   //!
    // TBranch        *b_mu_staco_nMDTHits;   //!
    // TBranch        *b_mu_staco_nMDTHoles;   //!
    // TBranch        *b_mu_staco_nOutliersOnTrack;   //!
    // TBranch        *b_mu_staco_nPixSharedHits;   //!
    // TBranch        *b_mu_staco_nPixelDeadSensors;   //!
    // TBranch        *b_mu_staco_nRPCEtaHits;   //!
    // TBranch        *b_mu_staco_nRPCEtaHoles;   //!
    // TBranch        *b_mu_staco_nRPCLayer1EtaHits;   //!
    // TBranch        *b_mu_staco_nRPCLayer1PhiHits;   //!
    // TBranch        *b_mu_staco_nRPCLayer2EtaHits;   //!
    // TBranch        *b_mu_staco_nRPCLayer2PhiHits;   //!
    // TBranch        *b_mu_staco_nRPCLayer3EtaHits;   //!
    // TBranch        *b_mu_staco_nRPCLayer3PhiHits;   //!
    // TBranch        *b_mu_staco_nRPCPhiHits;   //!
    // TBranch        *b_mu_staco_nRPCPhiHoles;   //!
    // TBranch        *b_mu_staco_nSCTSharedHits;   //!
    // TBranch        *b_mu_staco_nTGCEtaHits;   //!
    // TBranch        *b_mu_staco_nTGCEtaHoles;   //!
    // TBranch        *b_mu_staco_nTGCLayer1EtaHits;   //!
    // TBranch        *b_mu_staco_nTGCLayer1PhiHits;   //!
    // TBranch        *b_mu_staco_nTGCLayer2EtaHits;   //!
    // TBranch        *b_mu_staco_nTGCLayer2PhiHits;   //!
    // TBranch        *b_mu_staco_nTGCLayer3EtaHits;   //!
    // TBranch        *b_mu_staco_nTGCLayer3PhiHits;   //!
    // TBranch        *b_mu_staco_nTGCLayer4EtaHits;   //!
    // TBranch        *b_mu_staco_nTGCLayer4PhiHits;   //!
    // TBranch        *b_mu_staco_nTGCPhiHits;   //!
    // TBranch        *b_mu_staco_nTGCPhiHoles;   //!
    // TBranch        *b_mu_staco_nTRTDeadStraws;   //!
    // TBranch        *b_mu_staco_nTRTHighTHits;   //!
    // TBranch        *b_mu_staco_nTRTHighTOutliers;   //!
    // TBranch        *b_mu_staco_nphiHoleLayers;   //!
    // TBranch        *b_mu_staco_nphiLayers;   //!
    // TBranch        *b_mu_staco_nprecisionHoleLayers;   //!
    // TBranch        *b_mu_staco_nprecisionLayers;   //!
    // TBranch        *b_mu_staco_ntrigEtaHoleLayers;   //!
    // TBranch        *b_mu_staco_ntrigEtaLayers;   //!
    // TBranch        *b_mu_staco_nucone20;   //!
    // TBranch        *b_mu_staco_nucone20_trk500MeV;   //!
    // TBranch        *b_mu_staco_nucone20_trkelstyle;   //!
    // TBranch        *b_mu_staco_nucone30;   //!
    // TBranch        *b_mu_staco_nucone30_trk500MeV;   //!
    // TBranch        *b_mu_staco_nucone30_trkelstyle;   //!
    // TBranch        *b_mu_staco_nucone40;   //!
    // TBranch        *b_mu_staco_nucone40_trk500MeV;   //!
    // TBranch        *b_mu_staco_nucone40_trkelstyle;   //!
    // TBranch        *b_mu_staco_origin;   //!
    // TBranch        *b_mu_staco_phi_exPV;   //!
    // TBranch        *b_mu_staco_ptcone20;   //!
    // TBranch        *b_mu_staco_ptcone20_trk500MeV;   //!
    // TBranch        *b_mu_staco_ptcone20_trkelstyle;   //!
    // TBranch        *b_mu_staco_ptcone30;   //!
    // TBranch        *b_mu_staco_ptcone30_trk500MeV;   //!
    // TBranch        *b_mu_staco_ptcone40;   //!
    // TBranch        *b_mu_staco_ptcone40_trk500MeV;   //!
    // TBranch        *b_mu_staco_ptcone40_trkelstyle;   //!
    // TBranch        *b_mu_staco_px;   //!
    // TBranch        *b_mu_staco_py;   //!
    // TBranch        *b_mu_staco_pz;   //!
    // TBranch        *b_mu_staco_scatteringCurvatureSignificance;   //!
    // TBranch        *b_mu_staco_scatteringNeighbourSignificance;   //!
    // TBranch        *b_mu_staco_theta_exPV;   //!
    // TBranch        *b_mu_staco_tight;   //!
    // TBranch        *b_mu_staco_trackIPEstimate_d0_biasedpvunbiased;   //!
    // TBranch        *b_mu_staco_trackIPEstimate_sigd0_biasedpvunbiased;   //!
    // TBranch        *b_mu_staco_trackIPEstimate_sigz0_biasedpvunbiased;   //!
    // TBranch        *b_mu_staco_trackIPEstimate_sigz0_unbiasedpvunbiased;   //!
    // TBranch        *b_mu_staco_trackIPEstimate_z0_biasedpvunbiased;   //!
    // TBranch        *b_mu_staco_trackcov_d0;   //!
    // TBranch        *b_mu_staco_trackcov_d0_phi;   //!
    // TBranch        *b_mu_staco_trackcov_d0_qoverp;   //!
    // TBranch        *b_mu_staco_trackcov_d0_theta;   //!
    // TBranch        *b_mu_staco_trackcov_d0_z0;   //!
    // TBranch        *b_mu_staco_trackcov_phi;   //!
    // TBranch        *b_mu_staco_trackcov_phi_qoverp;   //!
    // TBranch        *b_mu_staco_trackcov_phi_theta;   //!
    // TBranch        *b_mu_staco_trackcov_qoverp;   //!
    // TBranch        *b_mu_staco_trackcov_theta;   //!
    // TBranch        *b_mu_staco_trackcov_theta_qoverp;   //!
    // TBranch        *b_mu_staco_trackcov_z0;   //!
    // TBranch        *b_mu_staco_trackcov_z0_phi;   //!
    // TBranch        *b_mu_staco_trackcov_z0_qoverp;   //!
    // TBranch        *b_mu_staco_trackcov_z0_theta;   //!
    // TBranch        *b_mu_staco_trackd0;   //!
    // TBranch        *b_mu_staco_trackphi;   //!
    // TBranch        *b_mu_staco_trackqoverp;   //!
    // TBranch        *b_mu_staco_tracktheta;   //!
    // TBranch        *b_mu_staco_trackz0;   //!
    // TBranch        *b_mu_staco_truth_E;   //!
    // TBranch        *b_mu_staco_truth_dr;   //!
    // TBranch        *b_mu_staco_truth_eta;   //!
    // TBranch        *b_mu_staco_truth_matched;   //!
    // TBranch        *b_mu_staco_truth_mothertype;   //!
    // TBranch        *b_mu_staco_truth_phi;   //!
    // TBranch        *b_mu_staco_truth_pt;   //!
    // TBranch        *b_mu_staco_truth_status;   //!
    // TBranch        *b_mu_staco_truth_type;   //!
    // TBranch        *b_mu_staco_type;   //!
    // TBranch        *b_muonError;   //!
    // TBranch        *b_muonFlags;   //!
    // TBranch        *b_muonTruth_PDGID;   //!
    TBranch        *b_muonTruth_barcode;   //!
    // TBranch        *b_muonTruth_charge;   //!
    // TBranch        *b_muonTruth_eta;   //!
    // TBranch        *b_muonTruth_m;   //!
    // TBranch        *b_muonTruth_n;   //!
    // TBranch        *b_muonTruth_phi;   //!
    // TBranch        *b_muonTruth_pt;   //!
    // TBranch        *b_ph_E033;   //!
    // TBranch        *b_ph_E1152;   //!
    // TBranch        *b_ph_E132;   //!
    // TBranch        *b_ph_E233;   //!
    // TBranch        *b_ph_E237;   //!
    // TBranch        *b_ph_E277;   //!
    // TBranch        *b_ph_E;   //!
    // TBranch        *b_ph_ED_Njets;   //!
    // TBranch        *b_ph_ED_median;   //!
    // TBranch        *b_ph_ED_sigma;   //!
    // TBranch        *b_ph_Emax2;   //!
    // TBranch        *b_ph_Emins1;   //!
    // TBranch        *b_ph_Es0;   //!
    // TBranch        *b_ph_Es1;   //!
    // TBranch        *b_ph_Es2;   //!
    // TBranch        *b_ph_Es3;   //!
    // TBranch        *b_ph_Et;   //!
    // TBranch        *b_ph_Etcone15;   //!
    // TBranch        *b_ph_Etcone20;   //!
    // TBranch        *b_ph_Etcone25;   //!
    // TBranch        *b_ph_Etcone30;   //!
    // TBranch        *b_ph_Etcone35;   //!
    // TBranch        *b_ph_Etcone40;   //!
    // TBranch        *b_ph_Etcone40_ED_corrected;   //!
    // TBranch        *b_ph_Etcone40_corrected;   //!
    // TBranch        *b_ph_Etcone45;   //!
    // TBranch        *b_ph_Ethad1;   //!
    // TBranch        *b_ph_Ethad;   //!
    // TBranch        *b_ph_MET_Egamma10NoTau_n;   //!
    // TBranch        *b_ph_MET_Egamma10NoTau_statusWord;   //!
    // TBranch        *b_ph_MET_Egamma10NoTau_wet;   //!
    // TBranch        *b_ph_MET_Egamma10NoTau_wpx;   //!
    // TBranch        *b_ph_MET_Egamma10NoTau_wpy;   //!
    // TBranch        *b_ph_MET_n;   //!
    // TBranch        *b_ph_MET_statusWord;   //!
    // TBranch        *b_ph_MET_wet;   //!
    // TBranch        *b_ph_MET_wpx;   //!
    // TBranch        *b_ph_MET_wpy;   //!
    // TBranch        *b_ph_OQ;   //!
    // TBranch        *b_ph_Rconv;   //!
    // TBranch        *b_ph_author;   //!
    // TBranch        *b_ph_cl_E;   //!
    // TBranch        *b_ph_cl_eta;   //!
    // TBranch        *b_ph_cl_phi;   //!
    // TBranch        *b_ph_cl_pt;   //!
    // TBranch        *b_ph_cl_time;   //!
    // TBranch        *b_ph_convFlag;   //!
    // TBranch        *b_ph_convanglematch;   //!
    // TBranch        *b_ph_convtrackmatch;   //!
    // TBranch        *b_ph_convtrk1nBLHits;   //!
    // TBranch        *b_ph_convtrk1nPixHits;   //!
    // TBranch        *b_ph_convtrk1nSCTHits;   //!
    // TBranch        *b_ph_convtrk1nTRTHits;   //!
    // TBranch        *b_ph_convtrk2nBLHits;   //!
    // TBranch        *b_ph_convtrk2nPixHits;   //!
    // TBranch        *b_ph_convtrk2nSCTHits;   //!
    // TBranch        *b_ph_convtrk2nTRTHits;   //!
    // TBranch        *b_ph_convvtxchi2;   //!
    // TBranch        *b_ph_convvtxx;   //!
    // TBranch        *b_ph_convvtxy;   //!
    // TBranch        *b_ph_convvtxz;   //!
    // TBranch        *b_ph_deltaEmax2;   //!
    // TBranch        *b_ph_deltaEs;   //!
    // TBranch        *b_ph_depth;   //!
    // TBranch        *b_ph_el_index;   //!
    // TBranch        *b_ph_emaxs1;   //!
    // TBranch        *b_ph_errz;   //!
    // TBranch        *b_ph_eta;   //!
    // TBranch        *b_ph_etap;   //!
    // TBranch        *b_ph_etas0;   //!
    // TBranch        *b_ph_etas1;   //!
    // TBranch        *b_ph_etas2;   //!
    // TBranch        *b_ph_etas3;   //!
    // TBranch        *b_ph_f1;   //!
    // TBranch        *b_ph_f1core;   //!
    // TBranch        *b_ph_f3;   //!
    // TBranch        *b_ph_f3core;   //!
    // TBranch        *b_ph_fside;   //!
    // TBranch        *b_ph_goodOQ;   //!
    // TBranch        *b_ph_hasconv;   //!
    // TBranch        *b_ph_isConv;   //!
    // TBranch        *b_ph_isEM;   //!
    // TBranch        *b_ph_isEMLoose;   //!
    // TBranch        *b_ph_isEMMedium;   //!
    // TBranch        *b_ph_isEMTight;   //!
    // TBranch        *b_ph_isRecovered;   //!
    // TBranch        *b_ph_jet_dr;   //!
    // TBranch        *b_ph_jet_matched;   //!
    // TBranch        *b_ph_loose;   //!
    // TBranch        *b_ph_looseAR;   //!
    // TBranch        *b_ph_looseARIso;   //!
    // TBranch        *b_ph_looseIso;   //!
    // TBranch        *b_ph_m;   //!
    // TBranch        *b_ph_maxEcell_energy;   //!
    // TBranch        *b_ph_maxEcell_gain;   //!
    // TBranch        *b_ph_maxEcell_onlId;   //!
    // TBranch        *b_ph_maxEcell_time;   //!
    // TBranch        *b_ph_maxEcell_x;   //!
    // TBranch        *b_ph_maxEcell_y;   //!
    // TBranch        *b_ph_maxEcell_z;   //!
    // TBranch        *b_ph_n;   //!
    // TBranch        *b_ph_nConv;   //!
    // TBranch        *b_ph_nDoubleTrackConv;   //!
    // TBranch        *b_ph_nSingleTrackConv;   //!
    // TBranch        *b_ph_nucone20;   //!
    // TBranch        *b_ph_nucone20_zpv05;   //!
    // TBranch        *b_ph_nucone30;   //!
    // TBranch        *b_ph_nucone30_zpv05;   //!
    // TBranch        *b_ph_nucone40;   //!
    // TBranch        *b_ph_nucone40_zpv05;   //!
    // TBranch        *b_ph_origin;   //!
    // TBranch        *b_ph_phi;   //!
    // TBranch        *b_ph_phis0;   //!
    // TBranch        *b_ph_phis1;   //!
    // TBranch        *b_ph_phis2;   //!
    // TBranch        *b_ph_phis3;   //!
    // TBranch        *b_ph_pt1conv;   //!
    // TBranch        *b_ph_pt2conv;   //!
    // TBranch        *b_ph_pt;   //!
    // TBranch        *b_ph_ptcone20;   //!
    // TBranch        *b_ph_ptcone20_zpv05;   //!
    // TBranch        *b_ph_ptcone30;   //!
    // TBranch        *b_ph_ptcone30_zpv05;   //!
    // TBranch        *b_ph_ptcone40;   //!
    // TBranch        *b_ph_ptcone40_zpv05;   //!
    // TBranch        *b_ph_ptconv;   //!
    // TBranch        *b_ph_px;   //!
    // TBranch        *b_ph_py;   //!
    // TBranch        *b_ph_pz;   //!
    // TBranch        *b_ph_pzconv;   //!
    // TBranch        *b_ph_reta;   //!
    // TBranch        *b_ph_rphi;   //!
    // TBranch        *b_ph_rphiallcalo;   //!
    // TBranch        *b_ph_tight;   //!
    // TBranch        *b_ph_tightAR;   //!
    // TBranch        *b_ph_tightARIso;   //!
    // TBranch        *b_ph_tightIso;   //!
    // TBranch        *b_ph_topoEtcone20;   //!
    // TBranch        *b_ph_topoEtcone20_corrected;   //!
    // TBranch        *b_ph_topoEtcone30;   //!
    // TBranch        *b_ph_topoEtcone30_corrected;   //!
    // TBranch        *b_ph_topoEtcone40;   //!
    // TBranch        *b_ph_topoEtcone40_corrected;   //!
    // TBranch        *b_ph_truth_E;   //!
    // TBranch        *b_ph_truth_Rconv;   //!
    // TBranch        *b_ph_truth_barcode;   //!
    // TBranch        *b_ph_truth_deltaRRecPhoton;   //!
    // TBranch        *b_ph_truth_eta;   //!
    // TBranch        *b_ph_truth_index;   //!
    // TBranch        *b_ph_truth_isBrem;   //!
    // TBranch        *b_ph_truth_isConv;   //!
    // TBranch        *b_ph_truth_isFromHardProc;   //!
    // TBranch        *b_ph_truth_isPhotonFromHardProc;   //!
    // TBranch        *b_ph_truth_matched;   //!
    // TBranch        *b_ph_truth_motherbarcode;   //!
    // TBranch        *b_ph_truth_mothertype;   //!
    // TBranch        *b_ph_truth_phi;   //!
    // TBranch        *b_ph_truth_pt;   //!
    // TBranch        *b_ph_truth_status;   //!
    // TBranch        *b_ph_truth_type;   //!
    // TBranch        *b_ph_truth_zconv;   //!
    // TBranch        *b_ph_type;   //!
    // TBranch        *b_ph_vx_convTrk_n;   //!
    // TBranch        *b_ph_vx_convTrk_weight;   //!
    // TBranch        *b_ph_vx_n;   //!
    // TBranch        *b_ph_weta2;   //!
    // TBranch        *b_ph_ws3;   //!
    // TBranch        *b_ph_wstot;   //!
    // TBranch        *b_ph_zconv;   //!
    // TBranch        *b_ph_zvertex;   //!
    // TBranch        *b_pixelError;   //!
    // TBranch        *b_pixelFlags;   //!
    // TBranch        *b_sctError;   //!
    // TBranch        *b_sctFlags;   //!
    // TBranch        *b_tau_BDTEleScore;   //!
    // TBranch        *b_tau_BDTJetScore;   //!
    // TBranch        *b_tau_EF_E;   //!
    // TBranch        *b_tau_EF_Et;   //!
    // TBranch        *b_tau_EF_dr;   //!
    // TBranch        *b_tau_EF_eta;   //!
    // TBranch        *b_tau_EF_matched;   //!
    // TBranch        *b_tau_EF_phi;   //!
    // TBranch        *b_tau_EF_pt;   //!
    // TBranch        *b_tau_EM_TES_scale;   //!
    // TBranch        *b_tau_Et;   //!
    // TBranch        *b_tau_L1_Et;   //!
    // TBranch        *b_tau_L1_dr;   //!
    // TBranch        *b_tau_L1_eta;   //!
    // TBranch        *b_tau_L1_matched;   //!
    // TBranch        *b_tau_L1_phi;   //!
    // TBranch        *b_tau_L1_pt;   //!
    // TBranch        *b_tau_L2_E;   //!
    // TBranch        *b_tau_L2_Et;   //!
    // TBranch        *b_tau_L2_dr;   //!
    // TBranch        *b_tau_L2_eta;   //!
    // TBranch        *b_tau_L2_matched;   //!
    // TBranch        *b_tau_L2_phi;   //!
    // TBranch        *b_tau_L2_pt;   //!
    // TBranch        *b_tau_LC_TES_precalib;   //!
    // TBranch        *b_tau_MET_n;   //!
    // TBranch        *b_tau_MET_statusWord;   //!
    // TBranch        *b_tau_MET_wet;   //!
    // TBranch        *b_tau_MET_wpx;   //!
    // TBranch        *b_tau_MET_wpy;   //!
    // TBranch        *b_tau_Pi0Cluster_eta;   //!
    // TBranch        *b_tau_Pi0Cluster_phi;   //!
    // TBranch        *b_tau_Pi0Cluster_pt;   //!
    // TBranch        *b_tau_RoIWord;   //!
    // TBranch        *b_tau_SafeLikelihood;   //!
    // TBranch        *b_tau_TRTHTOverLT_LeadTrk;   //!
    // TBranch        *b_tau_author;   //!
    // TBranch        *b_tau_calcVars_ChPiEMEOverCaloEME;   //!
    // TBranch        *b_tau_calcVars_EMFractionAtEMScale;   //!
    // TBranch        *b_tau_calcVars_EMFractionAtEMScale_MoveE3;   //!
    // TBranch        *b_tau_calcVars_EMPOverTrkSysP;   //!
    // TBranch        *b_tau_calcVars_PSSFraction;   //!
    // TBranch        *b_tau_calcVars_SecMaxStripEtOverPt;   //!
    // TBranch        *b_tau_calcVars_absDeltaEta;   //!
    // TBranch        *b_tau_calcVars_absDeltaPhi;   //!
    // TBranch        *b_tau_calcVars_calRadius;   //!
    // TBranch        *b_tau_calcVars_corrCentFrac;   //!
    // TBranch        *b_tau_calcVars_corrFTrk;   //!
    // TBranch        *b_tau_calcVars_drMin;   //!
    // TBranch        *b_tau_calcVars_etEM_EMScale_Pt3Trks;   //!
    // TBranch        *b_tau_calcVars_etHad_EMScale_Pt3Trks;   //!
    // TBranch        *b_tau_calcVars_interAxis_eta;   //!
    // TBranch        *b_tau_calcVars_interAxis_phi;   //!
    // TBranch        *b_tau_calcVars_ipSigLeadLooseTrk;   //!
    // TBranch        *b_tau_calcVars_pi0BDTPrimaryScore;   //!
    // TBranch        *b_tau_calcVars_pi0BDTSecondaryScore;   //!
    // TBranch        *b_tau_calcVars_trackIso;   //!
    // TBranch        *b_tau_cellBasedEnergyRing1;   //!
    // TBranch        *b_tau_cellBasedEnergyRing2;   //!
    // TBranch        *b_tau_cellBasedEnergyRing3;   //!
    // TBranch        *b_tau_cellBasedEnergyRing4;   //!
    // TBranch        *b_tau_cellBasedEnergyRing5;   //!
    // TBranch        *b_tau_cellBasedEnergyRing6;   //!
    // TBranch        *b_tau_cellBasedEnergyRing7;   //!
    // TBranch        *b_tau_chrgLooseTrk;   //!
    // TBranch        *b_tau_cluster_E;   //!
    // TBranch        *b_tau_cluster_EMLayer2F;   //!
    // TBranch        *b_tau_cluster_EMLayer3F;   //!
    // TBranch        *b_tau_cluster_PreSamplerStripF;   //!
    // TBranch        *b_tau_cluster_eta;   //!
    // TBranch        *b_tau_cluster_eta_atTJVA;   //!
    // TBranch        *b_tau_cluster_n;   //!
    // TBranch        *b_tau_cluster_phi;   //!
    // TBranch        *b_tau_cluster_phi_atTJVA;   //!
    // TBranch        *b_tau_effTopoInvMass;   //!
    // TBranch        *b_tau_effTopoMeanDeltaR;   //!
    // TBranch        *b_tau_ele_E237E277;   //!
    // TBranch        *b_tau_ele_ECALFirstFraction;   //!
    // TBranch        *b_tau_ele_PresamplerFraction;   //!
    // TBranch        *b_tau_electronVetoLoose;   //!
    // TBranch        *b_tau_electronVetoMedium;   //!
    // TBranch        *b_tau_electronVetoTight;   //!
    // TBranch        *b_tau_etEflow;   //!
    // TBranch        *b_tau_etOverPtLeadLooseTrk;   //!
    // TBranch        *b_tau_etOverPtLeadTrk;   //!
    // TBranch        *b_tau_ipSigLeadLooseTrk;   //!
    // TBranch        *b_tau_ipSigLeadTrk;   //!
    // TBranch        *b_tau_ipZ0SinThetaSigLeadTrk;   //!
    // TBranch        *b_tau_jet_BAD_CELLS_CORR_E;   //!
    // TBranch        *b_tau_jet_BCH_CORR_CELL;   //!
    // TBranch        *b_tau_jet_BCH_CORR_DOTX;   //!
    // TBranch        *b_tau_jet_BCH_CORR_JET;   //!
    // TBranch        *b_tau_jet_BCH_CORR_JET_FORCELL;   //!
    // TBranch        *b_tau_jet_EMJES;   //!
    // TBranch        *b_tau_jet_ENG_BAD_CELLS;   //!
    // TBranch        *b_tau_jet_Et;   //!
    // TBranch        *b_tau_jet_GCWJES;   //!
    // TBranch        *b_tau_jet_HECQuality;   //!
    // TBranch        *b_tau_jet_LArQuality;   //!
    // TBranch        *b_tau_jet_N_BAD_CELLS;   //!
    // TBranch        *b_tau_jet_N_BAD_CELLS_CORR;   //!
    // TBranch        *b_tau_jet_NegativeE;   //!
    // TBranch        *b_tau_jet_OriginIndex;   //!
    // TBranch        *b_tau_jet_SamplingMax;   //!
    // TBranch        *b_tau_jet_Timing;   //!
    // TBranch        *b_tau_jet_WIDTH;   //!
    // TBranch        *b_tau_jet_YFlip12;   //!
    // TBranch        *b_tau_jet_YFlip23;   //!
    // TBranch        *b_tau_jet_e_EMB1;   //!
    // TBranch        *b_tau_jet_e_EMB2;   //!
    // TBranch        *b_tau_jet_e_EMB3;   //!
    // TBranch        *b_tau_jet_e_EME1;   //!
    // TBranch        *b_tau_jet_e_EME2;   //!
    // TBranch        *b_tau_jet_e_EME3;   //!
    // TBranch        *b_tau_jet_e_FCAL0;   //!
    // TBranch        *b_tau_jet_e_FCAL1;   //!
    // TBranch        *b_tau_jet_e_FCAL2;   //!
    // TBranch        *b_tau_jet_e_HEC0;   //!
    // TBranch        *b_tau_jet_e_HEC1;   //!
    // TBranch        *b_tau_jet_e_HEC2;   //!
    // TBranch        *b_tau_jet_e_HEC3;   //!
    // TBranch        *b_tau_jet_e_PreSamplerB;   //!
    // TBranch        *b_tau_jet_e_PreSamplerE;   //!
    // TBranch        *b_tau_jet_e_TileBar0;   //!
    // TBranch        *b_tau_jet_e_TileBar1;   //!
    // TBranch        *b_tau_jet_e_TileBar2;   //!
    // TBranch        *b_tau_jet_e_TileExt0;   //!
    // TBranch        *b_tau_jet_e_TileExt1;   //!
    // TBranch        *b_tau_jet_e_TileExt2;   //!
    // TBranch        *b_tau_jet_e_TileGap1;   //!
    // TBranch        *b_tau_jet_e_TileGap2;   //!
    // TBranch        *b_tau_jet_e_TileGap3;   //!
    // TBranch        *b_tau_jet_emfrac;   //!
    // TBranch        *b_tau_jet_emscale_E;   //!
    // TBranch        *b_tau_jet_emscale_eta;   //!
    // TBranch        *b_tau_jet_emscale_m;   //!
    // TBranch        *b_tau_jet_emscale_phi;   //!
    // TBranch        *b_tau_jet_emscale_pt;   //!
    // TBranch        *b_tau_jet_eta;   //!
    // TBranch        *b_tau_jet_flavor_weight;   //!
    // TBranch        *b_tau_jet_flavor_weight_IP1D;   //!
    // TBranch        *b_tau_jet_flavor_weight_IP2D;   //!
    // TBranch        *b_tau_jet_flavor_weight_IP3D;   //!
    // TBranch        *b_tau_jet_flavor_weight_IP3DSV1;   //!
    // TBranch        *b_tau_jet_flavor_weight_JetFitterCOMB;   //!
    // TBranch        *b_tau_jet_flavor_weight_JetFitterCOMBNN;   //!
    // TBranch        *b_tau_jet_flavor_weight_JetFitterTag;   //!
    // TBranch        *b_tau_jet_flavor_weight_JetFitterTagNN;   //!
    // TBranch        *b_tau_jet_flavor_weight_JetProb;   //!
    // TBranch        *b_tau_jet_flavor_weight_SV0;   //!
    // TBranch        *b_tau_jet_flavor_weight_SV1;   //!
    // TBranch        *b_tau_jet_flavor_weight_SV2;   //!
    // TBranch        *b_tau_jet_flavor_weight_SoftElectronTag;   //!
    // TBranch        *b_tau_jet_flavor_weight_SoftMuonTag;   //!
    // TBranch        *b_tau_jet_flavor_weight_TrackCounting2D;   //!
    // TBranch        *b_tau_jet_fracSamplingMax;   //!
    // TBranch        *b_tau_jet_hecf;   //!
    // TBranch        *b_tau_jet_isBadLoose;   //!
    // TBranch        *b_tau_jet_isBadLooseMinus;   //!
    // TBranch        *b_tau_jet_isBadMedium;   //!
    // TBranch        *b_tau_jet_isBadTight;   //!
    // TBranch        *b_tau_jet_isUgly;   //!
    // TBranch        *b_tau_jet_jvtx_x;   //!
    // TBranch        *b_tau_jet_jvtx_y;   //!
    // TBranch        *b_tau_jet_jvtx_z;   //!
    // TBranch        *b_tau_jet_jvtxf;   //!
    // TBranch        *b_tau_jet_m;   //!
    // TBranch        *b_tau_jet_n90;   //!
    // TBranch        *b_tau_jet_n90constituents;   //!
    // TBranch        *b_tau_jet_nTrk;   //!
    // TBranch        *b_tau_jet_phi;   //!
    // TBranch        *b_tau_jet_pt;   //!
    // TBranch        *b_tau_jet_shapeBins;   //!
    // TBranch        *b_tau_jet_sumPtTrk;   //!
    // TBranch        *b_tau_jet_tgap3f;   //!
    // TBranch        *b_tau_leadLooseTrkPt;   //!
    // TBranch        *b_tau_leadTrack_eta;   //!
    // TBranch        *b_tau_leadTrack_phi;   //!
    // TBranch        *b_tau_leadTrkPt;   //!
    // TBranch        *b_tau_likelihood;   //!
    // TBranch        *b_tau_mEflow;   //!
    // TBranch        *b_tau_massTrkSys;   //!
    // TBranch        *b_tau_nLooseConvTrk;   //!
    // TBranch        *b_tau_nLooseTrk;   //!
    // TBranch        *b_tau_nOtherTrk;   //!
    // TBranch        *b_tau_nPi0;   //!
    // TBranch        *b_tau_nProng;   //!
    // TBranch        *b_tau_nProngLoose;   //!
    // TBranch        *b_tau_numCells;   //!
    // TBranch        *b_tau_numEffTopoClusters;   //!
    // TBranch        *b_tau_numTopoClusters;   //!
    // TBranch        *b_tau_otherTrk_atTJVA_n;   //!
    // TBranch        *b_tau_otherTrk_n;   //!
    // TBranch        *b_tau_out_track_n;   //!
    // TBranch        *b_tau_out_track_n_extended;   //!
    // TBranch        *b_tau_pantau_AbsSumCharge;   //!
    // TBranch        *b_tau_pantau_EflowAngleChargedAxisNeutralAxis;   //!
    // TBranch        *b_tau_pantau_EflowAngleJetAxisLeadingChargedQualified;   //!
    // TBranch        *b_tau_pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified;   //!
    // TBranch        *b_tau_pantau_EflowChargedSumEt;   //!
    // TBranch        *b_tau_pantau_EflowEtLeadingChrgQualifiedOverTotalEt;   //!
    // TBranch        *b_tau_pantau_EflowInvariantMassAll;   //!
    // TBranch        *b_tau_pantau_EflowJetMomentDRAll;   //!
    // TBranch        *b_tau_pantau_EflowJetMomentDRChrg;   //!
    // TBranch        *b_tau_pantau_EflowJetMomentDREMNeut;   //!
    // TBranch        *b_tau_pantau_EflowJetMomentDRHADNeut;   //!
    // TBranch        *b_tau_pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents;   //!
    // TBranch        *b_tau_pantau_EflowStdDevEtToSumEt;   //!
    // TBranch        *b_tau_pantau_EflowSumEAll;   //!
    // TBranch        *b_tau_pantau_EtIn01OverEtIn02InvSigm;   //!
    // TBranch        *b_tau_pantau_EtIn01OverEtIn04;   //!
    // TBranch        *b_tau_pantau_EtIn01OverEtIn04InvSigm;   //!
    // TBranch        *b_tau_pantau_EtIn02To04OverTotalEtInvSigm;   //!
    // TBranch        *b_tau_pantau_JetSphericity;   //!
    // TBranch        *b_tau_pantau_NChargedEFO;   //!
    // TBranch        *b_tau_pantau_NChargedQualifiedEFO;   //!
    // TBranch        *b_tau_pantau_NNeutralEFO;   //!
    // TBranch        *b_tau_pantau_PanTauScore;   //!
    // TBranch        *b_tau_pantau_TransImpactParamSignfTrack1;   //!
    // TBranch        *b_tau_pantau_isPanTauCandidate;   //!
    // TBranch        *b_tau_pi0_cl1_eta;   //!
    // TBranch        *b_tau_pi0_cl1_phi;   //!
    // TBranch        *b_tau_pi0_cl1_pt;   //!
    // TBranch        *b_tau_pi0_cl2_eta;   //!
    // TBranch        *b_tau_pi0_cl2_phi;   //!
    // TBranch        *b_tau_pi0_cl2_pt;   //!
    // TBranch        *b_tau_pi0_n;   //!
    // TBranch        *b_tau_pi0_vistau_eta;   //!
    // TBranch        *b_tau_pi0_vistau_m;   //!
    // TBranch        *b_tau_pi0_vistau_phi;   //!
    // TBranch        *b_tau_pi0_vistau_pt;   //!
    // TBranch        *b_tau_privtx_chiSquared;   //!
    // TBranch        *b_tau_privtx_jvf;   //!
    // TBranch        *b_tau_privtx_numberDoF;   //!
    // TBranch        *b_tau_privtx_x;   //!
    // TBranch        *b_tau_privtx_xx;   //!
    // TBranch        *b_tau_privtx_xy;   //!
    // TBranch        *b_tau_privtx_y;   //!
    // TBranch        *b_tau_privtx_yy;   //!
    // TBranch        *b_tau_privtx_yz;   //!
    // TBranch        *b_tau_privtx_z;   //!
    // TBranch        *b_tau_privtx_zx;   //!
    // TBranch        *b_tau_privtx_zz;   //!
    // TBranch        *b_tau_secvtx_chiSquared;   //!
    // TBranch        *b_tau_secvtx_numberDoF;   //!
    // TBranch        *b_tau_secvtx_x;   //!
    // TBranch        *b_tau_secvtx_xx;   //!
    // TBranch        *b_tau_secvtx_xy;   //!
    // TBranch        *b_tau_secvtx_y;   //!
    // TBranch        *b_tau_secvtx_yy;   //!
    // TBranch        *b_tau_secvtx_yz;   //!
    // TBranch        *b_tau_secvtx_z;   //!
    // TBranch        *b_tau_secvtx_zx;   //!
    // TBranch        *b_tau_secvtx_zz;   //!
    // TBranch        *b_tau_seedCalo_EMRadius;   //!
    // TBranch        *b_tau_seedCalo_caloIso;   //!
    // TBranch        *b_tau_seedCalo_caloIsoCorrected;   //!
    // TBranch        *b_tau_seedCalo_centFrac;   //!
    // TBranch        *b_tau_seedCalo_dRmax;   //!
    // TBranch        *b_tau_seedCalo_etEMAtEMScale;   //!
    // TBranch        *b_tau_seedCalo_etEMCalib;   //!
    // TBranch        *b_tau_seedCalo_etHadAtEMScale;   //!
    // TBranch        *b_tau_seedCalo_etHadCalib;   //!
    // TBranch        *b_tau_seedCalo_eta;   //!
    // TBranch        *b_tau_seedCalo_hadRadius;   //!
    // TBranch        *b_tau_seedCalo_isolFrac;   //!
    // TBranch        *b_tau_seedCalo_lead2ClusterEOverAllClusterE;   //!
    // TBranch        *b_tau_seedCalo_lead3ClusterEOverAllClusterE;   //!
    // TBranch        *b_tau_seedCalo_nIsolLooseTrk;   //!
    // TBranch        *b_tau_seedCalo_nStrip;   //!
    // TBranch        *b_tau_seedCalo_nWideTrk;   //!
    // TBranch        *b_tau_seedCalo_numTrack;   //!
    // TBranch        *b_tau_seedCalo_phi;   //!
    // TBranch        *b_tau_seedCalo_stripWidth2;   //!
    // TBranch        *b_tau_seedCalo_track_n;   //!
    // TBranch        *b_tau_seedCalo_trkAvgDist;   //!
    // TBranch        *b_tau_seedCalo_trkRmsDist;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_atTJVA_d0;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_atTJVA_eta;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_atTJVA_n;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_atTJVA_phi;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_atTJVA_pt;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_atTJVA_qoverp;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_atTJVA_theta;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_atTJVA_z0;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_expectBLayerHit;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_n;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nBLHits;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nBLSharedHits;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nBLayerOutliers;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nBLayerSplitHits;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nContribPixelLayers;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nGangedFlaggedFakes;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nGangedPixels;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nHits;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nPixHits;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nPixHoles;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nPixSharedHits;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nPixSplitHits;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nPixelDeadSensors;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nPixelOutliers;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nPixelSpoiltHits;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nSCTDeadSensors;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nSCTDoubleHoles;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nSCTHits;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nSCTHoles;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nSCTOutliers;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nSCTSharedHits;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nSCTSpoiltHits;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nTRTHighTHits;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nTRTHighTOutliers;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nTRTHits;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nTRTHoles;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nTRTOutliers;   //!
    // TBranch        *b_tau_seedCalo_wideTrk_nTRTXenonHits;   //!
    // TBranch        *b_tau_seedTrk_EMRadius;   //!
    // TBranch        *b_tau_seedTrk_etChrgEM;   //!
    // TBranch        *b_tau_seedTrk_etChrgHad;   //!
    // TBranch        *b_tau_seedTrk_etChrgHadOverSumTrkPt;   //!
    // TBranch        *b_tau_seedTrk_etEMAtEMScale;   //!
    // TBranch        *b_tau_seedTrk_etEMCL;   //!
    // TBranch        *b_tau_seedTrk_etHadAtEMScale;   //!
    // TBranch        *b_tau_seedTrk_etIsolEM;   //!
    // TBranch        *b_tau_seedTrk_etIsolHad;   //!
    // TBranch        *b_tau_seedTrk_etNeuEM;   //!
    // TBranch        *b_tau_seedTrk_etResNeuEM;   //!
    // TBranch        *b_tau_seedTrk_hadLeakEt;   //!
    // TBranch        *b_tau_seedTrk_isolFrac;   //!
    // TBranch        *b_tau_seedTrk_isolFracWide;   //!
    // TBranch        *b_tau_seedTrk_nIsolTrk;   //!
    // TBranch        *b_tau_seedTrk_nOtherCoreTrk;   //!
    // TBranch        *b_tau_seedTrk_nStrip;   //!
    // TBranch        *b_tau_seedTrk_secMaxStripEt;   //!
    // TBranch        *b_tau_seedTrk_stripWidth2;   //!
    // TBranch        *b_tau_seedTrk_sumEMCellEtOverLeadTrkPt;   //!
    // TBranch        *b_tau_tauLlhLoose;   //!
    // TBranch        *b_tau_tauLlhMedium;   //!
    // TBranch        *b_tau_tauLlhTight;   //!
    // TBranch        *b_tau_topoInvMass;   //!
    // TBranch        *b_tau_topoMeanDeltaR;   //!
    // TBranch        *b_tau_trFlightPathSig;   //!
    // TBranch        *b_tau_track_TRTHighTHitsRatio;   //!
    // TBranch        *b_tau_track_TRTHighTOutliersRatio;   //!
    // TBranch        *b_tau_track_atPV_d0;   //!
    // TBranch        *b_tau_track_atPV_eta;   //!
    // TBranch        *b_tau_track_atPV_phi;   //!
    // TBranch        *b_tau_track_atPV_pt;   //!
    // TBranch        *b_tau_track_atPV_qoverp;   //!
    // TBranch        *b_tau_track_atPV_theta;   //!
    // TBranch        *b_tau_track_atPV_z0;   //!
    // TBranch        *b_tau_track_atTJVA_cov_d0;   //!
    // TBranch        *b_tau_track_atTJVA_cov_d0_phi;   //!
    // TBranch        *b_tau_track_atTJVA_cov_d0_qoverp;   //!
    // TBranch        *b_tau_track_atTJVA_cov_d0_theta;   //!
    // TBranch        *b_tau_track_atTJVA_cov_d0_z0;   //!
    // TBranch        *b_tau_track_atTJVA_cov_phi;   //!
    // TBranch        *b_tau_track_atTJVA_cov_phi_qoverp;   //!
    // TBranch        *b_tau_track_atTJVA_cov_phi_theta;   //!
    // TBranch        *b_tau_track_atTJVA_cov_qoverp;   //!
    // TBranch        *b_tau_track_atTJVA_cov_theta;   //!
    // TBranch        *b_tau_track_atTJVA_cov_theta_qoverp;   //!
    // TBranch        *b_tau_track_atTJVA_cov_z0;   //!
    // TBranch        *b_tau_track_atTJVA_cov_z0_phi;   //!
    // TBranch        *b_tau_track_atTJVA_cov_z0_qoverp;   //!
    // TBranch        *b_tau_track_atTJVA_cov_z0_theta;   //!
    // TBranch        *b_tau_track_atTJVA_d0;   //!
    // TBranch        *b_tau_track_atTJVA_err_d0;   //!
    // TBranch        *b_tau_track_atTJVA_err_phi;   //!
    // TBranch        *b_tau_track_atTJVA_err_qoverp;   //!
    // TBranch        *b_tau_track_atTJVA_err_theta;   //!
    // TBranch        *b_tau_track_atTJVA_err_z0;   //!
    // TBranch        *b_tau_track_atTJVA_eta;   //!
    // TBranch        *b_tau_track_atTJVA_n;   //!
    // TBranch        *b_tau_track_atTJVA_phi;   //!
    // TBranch        *b_tau_track_atTJVA_pt;   //!
    // TBranch        *b_tau_track_atTJVA_qoverp;   //!
    // TBranch        *b_tau_track_atTJVA_theta;   //!
    // TBranch        *b_tau_track_atTJVA_z0;   //!
    // TBranch        *b_tau_track_d0;   //!
    // TBranch        *b_tau_track_eta;   //!
    // TBranch        *b_tau_track_expectBLayerHit;   //!
    // TBranch        *b_tau_track_n;   //!
    // TBranch        *b_tau_track_nBLHits;   //!
    // TBranch        *b_tau_track_nBLSharedHits;   //!
    // TBranch        *b_tau_track_nBLayerOutliers;   //!
    // TBranch        *b_tau_track_nBLayerSplitHits;   //!
    // TBranch        *b_tau_track_nContribPixelLayers;   //!
    // TBranch        *b_tau_track_nGangedFlaggedFakes;   //!
    // TBranch        *b_tau_track_nGangedPixels;   //!
    // TBranch        *b_tau_track_nHits;   //!
    // TBranch        *b_tau_track_nPixHits;   //!
    // TBranch        *b_tau_track_nPixHoles;   //!
    // TBranch        *b_tau_track_nPixSharedHits;   //!
    // TBranch        *b_tau_track_nPixSplitHits;   //!
    // TBranch        *b_tau_track_nPixelDeadSensors;   //!
    // TBranch        *b_tau_track_nPixelOutliers;   //!
    // TBranch        *b_tau_track_nPixelSpoiltHits;   //!
    // TBranch        *b_tau_track_nSCTDeadSensors;   //!
    // TBranch        *b_tau_track_nSCTDoubleHoles;   //!
    // TBranch        *b_tau_track_nSCTHits;   //!
    // TBranch        *b_tau_track_nSCTHoles;   //!
    // TBranch        *b_tau_track_nSCTOutliers;   //!
    // TBranch        *b_tau_track_nSCTSharedHits;   //!
    // TBranch        *b_tau_track_nSCTSpoiltHits;   //!
    // TBranch        *b_tau_track_nTRTHighTHits;   //!
    // TBranch        *b_tau_track_nTRTHighTOutliers;   //!
    // TBranch        *b_tau_track_nTRTHits;   //!
    // TBranch        *b_tau_track_nTRTHoles;   //!
    // TBranch        *b_tau_track_nTRTOutliers;   //!
    // TBranch        *b_tau_track_nTRTXenonHits;   //!
    // TBranch        *b_tau_track_phi;   //!
    // TBranch        *b_tau_track_pt;   //!
    // TBranch        *b_tau_track_qoverp;   //!
    // TBranch        *b_tau_track_theta;   //!
    // TBranch        *b_tau_track_z0;   //!
    // TBranch        *b_tau_trkWidth2;   //!
    // TBranch        *b_tau_trueTauAssocSmall_dr;   //!
    // TBranch        *b_tau_trueTauAssocSmall_index;   //!
    // TBranch        *b_tau_trueTauAssocSmall_matched;   //!
    // TBranch        *b_tileFlags;   //!
    // TBranch        *b_timestamp;   //!
    // TBranch        *b_timestamp_ns;   //!
    // TBranch        *b_top_hfor_type;   //!
    // TBranch        *b_trig_DB_HLTPSK;   //!
    // TBranch        *b_trig_DB_L1PSK;   //!
    // TBranch        *b_trig_DB_SMK;   //!
    // TBranch        *b_trig_EF_bjet_eta;   //!
    // TBranch        *b_trig_EF_bjet_n;   //!
    // TBranch        *b_trig_EF_bjet_phi;   //!
    // TBranch        *b_trig_EF_bjet_prmVtx;   //!
    // TBranch        *b_trig_EF_bjet_pt;   //!
    // TBranch        *b_trig_EF_bjet_roiId;   //!
    // TBranch        *b_trig_EF_bjet_valid;   //!
    // TBranch        *b_trig_EF_bjet_vertex_algorithmId;   //!
    // TBranch        *b_trig_EF_bjet_vertex_chi2;   //!
    // TBranch        *b_trig_EF_bjet_vertex_covariance;   //!
    // TBranch        *b_trig_EF_bjet_vertex_energyFraction;   //!
    // TBranch        *b_trig_EF_bjet_vertex_mass;   //!
    // TBranch        *b_trig_EF_bjet_vertex_massVariance;   //!
    // TBranch        *b_trig_EF_bjet_vertex_n;   //!
    // TBranch        *b_trig_EF_bjet_vertex_nDoF;   //!
    // TBranch        *b_trig_EF_bjet_vertex_nTwoTrackSecVtx;   //!
    // TBranch        *b_trig_EF_bjet_vertex_x;   //!
    // TBranch        *b_trig_EF_bjet_vertex_y;   //!
    // TBranch        *b_trig_EF_bjet_vertex_z;   //!
    // TBranch        *b_trig_EF_bjet_xCHI2;   //!
    // TBranch        *b_trig_EF_bjet_xComb;   //!
    // TBranch        *b_trig_EF_bjet_xEVtx;   //!
    // TBranch        *b_trig_EF_bjet_xIP1D;   //!
    // TBranch        *b_trig_EF_bjet_xIP2D;   //!
    // TBranch        *b_trig_EF_bjet_xIP3D;   //!
    // TBranch        *b_trig_EF_bjet_xMVtx;   //!
    // TBranch        *b_trig_EF_bjet_xNVtx;   //!
    // TBranch        *b_trig_EF_bjet_xSV;   //!
    // TBranch        *b_trig_EF_el_E233;   //!
    // TBranch        *b_trig_EF_el_E237;   //!
    // TBranch        *b_trig_EF_el_E277;   //!
    // TBranch        *b_trig_EF_el_EF_2e12Tvh_loose1;   //!
    // TBranch        *b_trig_EF_el_EF_2e5_tight1_Jpsi;   //!
    // TBranch        *b_trig_EF_el_EF_2e7T_loose1_mu6;   //!
    // TBranch        *b_trig_EF_el_EF_2e7T_medium1_mu6;   //!
    // TBranch        *b_trig_EF_el_EF_e11_etcut;   //!
    // TBranch        *b_trig_EF_el_EF_e12Tvh_loose1_mu8;   //!
    // TBranch        *b_trig_EF_el_EF_e12Tvh_medium1_mu10;   //!
    // TBranch        *b_trig_EF_el_EF_e12Tvh_medium1_mu6;   //!
    // TBranch        *b_trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium;   //!
    // TBranch        *b_trig_EF_el_EF_e12Tvh_medium1_mu8;   //!
    // TBranch        *b_trig_EF_el_EF_e13_etcutTrk_xs60;   //!
    // TBranch        *b_trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20;   //!
    // TBranch        *b_trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi;   //!
    // TBranch        *b_trig_EF_el_EF_e15vh_medium1;   //!
    // TBranch        *b_trig_EF_el_EF_e18_loose1;   //!
    // TBranch        *b_trig_EF_el_EF_e18_loose1_g25_medium;   //!
    // TBranch        *b_trig_EF_el_EF_e18_loose1_g35_loose;   //!
    // TBranch        *b_trig_EF_el_EF_e18_loose1_g35_medium;   //!
    // TBranch        *b_trig_EF_el_EF_e18_medium1;   //!
    // TBranch        *b_trig_EF_el_EF_e18_medium1_g25_loose;   //!
    // TBranch        *b_trig_EF_el_EF_e18_medium1_g25_medium;   //!
    // TBranch        *b_trig_EF_el_EF_e18_medium1_g35_loose;   //!
    // TBranch        *b_trig_EF_el_EF_e18_medium1_g35_medium;   //!
    // TBranch        *b_trig_EF_el_EF_e18vh_medium1;   //!
    // TBranch        *b_trig_EF_el_EF_e18vh_medium1_2e7T_medium1;   //!
    // TBranch        *b_trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20;   //!
    // TBranch        *b_trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20;   //!
    // TBranch        *b_trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi;   //!
    // TBranch        *b_trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi;   //!
    // TBranch        *b_trig_EF_el_EF_e22vh_loose0;   //!
    // TBranch        *b_trig_EF_el_EF_e22vh_loose1;   //!
    // TBranch        *b_trig_EF_el_EF_e22vh_loose;   //!
    // TBranch        *b_trig_EF_el_EF_e22vh_medium1;   //!
    // TBranch        *b_trig_EF_el_EF_e22vh_medium1_IDTrkNoCut;   //!
    // TBranch        *b_trig_EF_el_EF_e22vh_medium1_IdScan;   //!
    // TBranch        *b_trig_EF_el_EF_e22vh_medium1_SiTrk;   //!
    // TBranch        *b_trig_EF_el_EF_e22vh_medium1_TRT;   //!
    // TBranch        *b_trig_EF_el_EF_e22vhi_medium1;   //!
    // TBranch        *b_trig_EF_el_EF_e24vh_loose0;   //!
    // TBranch        *b_trig_EF_el_EF_e24vh_loose1;   //!
    // TBranch        *b_trig_EF_el_EF_e24vh_loose;   //!
    // TBranch        *b_trig_EF_el_EF_e24vh_medium1_EFxe30;   //!
    // TBranch        *b_trig_EF_el_EF_e24vh_medium1_EFxe30_tcem;   //!
    // TBranch        *b_trig_EF_el_EF_e24vh_medium1_EFxe35_tcem;   //!
    // TBranch        *b_trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw;   //!
    // TBranch        *b_trig_EF_el_EF_e24vh_medium1_EFxe40;   //!
    // TBranch        *b_trig_EF_el_EF_e24vh_medium1_IDTrkNoCut;   //!
    // TBranch        *b_trig_EF_el_EF_e24vh_medium1_IdScan;   //!
    // TBranch        *b_trig_EF_el_EF_e24vh_medium1_L2StarB;   //!
    // TBranch        *b_trig_EF_el_EF_e24vh_medium1_L2StarC;   //!
    // TBranch        *b_trig_EF_el_EF_e24vh_medium1_SiTrk;   //!
    // TBranch        *b_trig_EF_el_EF_e24vh_medium1_TRT;   //!
    // TBranch        *b_trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad;   //!
    // TBranch        *b_trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee;   //!
    // TBranch        *b_trig_EF_el_EF_e24vhi_loose1_mu8;   //!
    // TBranch        *b_trig_EF_el_EF_e24vhi_medium1;   //!
    // TBranch        *b_trig_EF_el_EF_e45_etcut;   //!
    // TBranch        *b_trig_EF_el_EF_e45_medium1;   //!
    // TBranch        *b_trig_EF_el_EF_e5_tight1;   //!
    // TBranch        *b_trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi;   //!
    // TBranch        *b_trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi;   //!
    // TBranch        *b_trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan;   //!
    // TBranch        *b_trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB;   //!
    // TBranch        *b_trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC;   //!
    // TBranch        *b_trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk;   //!
    // TBranch        *b_trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT;   //!
    // TBranch        *b_trig_EF_el_EF_e5_tight1_e5_NoCut;   //!
    // TBranch        *b_trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi;   //!
    // TBranch        *b_trig_EF_el_EF_e60_etcut;   //!
    // TBranch        *b_trig_EF_el_EF_e60_medium1;   //!
    // TBranch        *b_trig_EF_el_EF_e7T_loose1;   //!
    // TBranch        *b_trig_EF_el_EF_e7T_loose1_2mu6;   //!
    // TBranch        *b_trig_EF_el_EF_e7T_medium1_2mu6;   //!
    // TBranch        *b_trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi;   //!
    // TBranch        *b_trig_EF_el_EF_eb_physics;   //!
    // TBranch        *b_trig_EF_el_EF_eb_physics_empty;   //!
    // TBranch        *b_trig_EF_el_EF_eb_physics_firstempty;   //!
    // TBranch        *b_trig_EF_el_EF_eb_physics_noL1PS;   //!
    // TBranch        *b_trig_EF_el_EF_eb_physics_unpaired_iso;   //!
    // TBranch        *b_trig_EF_el_EF_eb_physics_unpaired_noniso;   //!
    // TBranch        *b_trig_EF_el_EF_eb_random;   //!
    // TBranch        *b_trig_EF_el_EF_eb_random_empty;   //!
    // TBranch        *b_trig_EF_el_EF_eb_random_firstempty;   //!
    // TBranch        *b_trig_EF_el_EF_eb_random_unpaired_iso;   //!
    // TBranch        *b_trig_EF_el_Emax2;   //!
    // TBranch        *b_trig_EF_el_Emins1;   //!
    // TBranch        *b_trig_EF_el_Et;   //!
    // TBranch        *b_trig_EF_el_Etcone15;   //!
    // TBranch        *b_trig_EF_el_Etcone20;   //!
    // TBranch        *b_trig_EF_el_Etcone25;   //!
    // TBranch        *b_trig_EF_el_Etcone30;   //!
    // TBranch        *b_trig_EF_el_Etcone35;   //!
    // TBranch        *b_trig_EF_el_Etcone40;   //!
    // TBranch        *b_trig_EF_el_Etcone45;   //!
    // TBranch        *b_trig_EF_el_Ethad1;   //!
    // TBranch        *b_trig_EF_el_Ethad;   //!
    // TBranch        *b_trig_EF_el_TRTHighTHitsRatio;   //!
    // TBranch        *b_trig_EF_el_TRTHighTOutliersRatio;   //!
    // TBranch        *b_trig_EF_el_author;   //!
    // TBranch        *b_trig_EF_el_charge;   //!
    // TBranch        *b_trig_EF_el_cl_E;   //!
    // TBranch        *b_trig_EF_el_cl_eta;   //!
    // TBranch        *b_trig_EF_el_cl_etas2;   //!
    // TBranch        *b_trig_EF_el_cl_phi;   //!
    // TBranch        *b_trig_EF_el_cl_pt;   //!
    // TBranch        *b_trig_EF_el_deltaEs;   //!
    // TBranch        *b_trig_EF_el_deltaeta1;   //!
    // TBranch        *b_trig_EF_el_deltaeta2;   //!
    // TBranch        *b_trig_EF_el_deltaphi2;   //!
    // TBranch        *b_trig_EF_el_eProbabilityBrem;   //!
    // TBranch        *b_trig_EF_el_eProbabilityComb;   //!
    // TBranch        *b_trig_EF_el_eProbabilityHT;   //!
    // TBranch        *b_trig_EF_el_eProbabilityToT;   //!
    // TBranch        *b_trig_EF_el_emaxs1;   //!
    // TBranch        *b_trig_EF_el_eta;   //!
    // TBranch        *b_trig_EF_el_etacorrmag;   //!
    // TBranch        *b_trig_EF_el_expectBLayerHit;   //!
    // TBranch        *b_trig_EF_el_expectHitInBLayer;   //!
    // TBranch        *b_trig_EF_el_f1;   //!
    // TBranch        *b_trig_EF_el_f1core;   //!
    // TBranch        *b_trig_EF_el_f3;   //!
    // TBranch        *b_trig_EF_el_f3core;   //!
    // TBranch        *b_trig_EF_el_fside;   //!
    // TBranch        *b_trig_EF_el_hastrack;   //!
    // TBranch        *b_trig_EF_el_isEM;   //!
    // TBranch        *b_trig_EF_el_isEMLoose;   //!
    // TBranch        *b_trig_EF_el_isEMMedium;   //!
    // TBranch        *b_trig_EF_el_isEMTight;   //!
    // TBranch        *b_trig_EF_el_likelihoodsPixeldEdx;   //!
    // TBranch        *b_trig_EF_el_loose;   //!
    // TBranch        *b_trig_EF_el_looseIso;   //!
    // TBranch        *b_trig_EF_el_loosePP;   //!
    // TBranch        *b_trig_EF_el_loosePPIso;   //!
    // TBranch        *b_trig_EF_el_m;   //!
    // TBranch        *b_trig_EF_el_massPixeldEdx;   //!
    // TBranch        *b_trig_EF_el_medium;   //!
    // TBranch        *b_trig_EF_el_mediumIso;   //!
    // TBranch        *b_trig_EF_el_mediumIsoWithoutTrack;   //!
    // TBranch        *b_trig_EF_el_mediumPP;   //!
    // TBranch        *b_trig_EF_el_mediumPPIso;   //!
    // TBranch        *b_trig_EF_el_mediumWithoutTrack;   //!
    // TBranch        *b_trig_EF_el_n;   //!
    // TBranch        *b_trig_EF_el_nBLHits;   //!
    // TBranch        *b_trig_EF_el_nBLSharedHits;   //!
    // TBranch        *b_trig_EF_el_nBLayerOutliers;   //!
    // TBranch        *b_trig_EF_el_nBLayerSplitHits;   //!
    // TBranch        *b_trig_EF_el_nGoodHitsPixeldEdx;   //!
    // TBranch        *b_trig_EF_el_nPixHits;   //!
    // TBranch        *b_trig_EF_el_nPixHoles;   //!
    // TBranch        *b_trig_EF_el_nPixSharedHits;   //!
    // TBranch        *b_trig_EF_el_nPixSplitHits;   //!
    // TBranch        *b_trig_EF_el_nPixelDeadSensors;   //!
    // TBranch        *b_trig_EF_el_nPixelOutliers;   //!
    // TBranch        *b_trig_EF_el_nSCTDeadSensors;   //!
    // TBranch        *b_trig_EF_el_nSCTHits;   //!
    // TBranch        *b_trig_EF_el_nSCTHoles;   //!
    // TBranch        *b_trig_EF_el_nSCTOutliers;   //!
    // TBranch        *b_trig_EF_el_nSCTSharedHits;   //!
    // TBranch        *b_trig_EF_el_nSiHits;   //!
    // TBranch        *b_trig_EF_el_nTRTHighTHits;   //!
    // TBranch        *b_trig_EF_el_nTRTHighTOutliers;   //!
    // TBranch        *b_trig_EF_el_nTRTHits;   //!
    // TBranch        *b_trig_EF_el_nTRTHoles;   //!
    // TBranch        *b_trig_EF_el_nTRTOutliers;   //!
    // TBranch        *b_trig_EF_el_nTRTXenonHits;   //!
    // TBranch        *b_trig_EF_el_phi;   //!
    // TBranch        *b_trig_EF_el_pixeldEdx;   //!
    // TBranch        *b_trig_EF_el_pos7;   //!
    // TBranch        *b_trig_EF_el_pt;   //!
    // TBranch        *b_trig_EF_el_ptcone20;   //!
    // TBranch        *b_trig_EF_el_ptcone30;   //!
    // TBranch        *b_trig_EF_el_ptcone40;   //!
    // TBranch        *b_trig_EF_el_reta;   //!
    // TBranch        *b_trig_EF_el_rphi;   //!
    // TBranch        *b_trig_EF_el_rphiallcalo;   //!
    // TBranch        *b_trig_EF_el_tight;   //!
    // TBranch        *b_trig_EF_el_tightIso;   //!
    // TBranch        *b_trig_EF_el_tightIsoWithoutTrack;   //!
    // TBranch        *b_trig_EF_el_tightPP;   //!
    // TBranch        *b_trig_EF_el_tightPPIso;   //!
    // TBranch        *b_trig_EF_el_tightWithoutTrack;   //!
    // TBranch        *b_trig_EF_el_trackd0;   //!
    // TBranch        *b_trig_EF_el_trackd0_physics;   //!
    // TBranch        *b_trig_EF_el_tracketa;   //!
    // TBranch        *b_trig_EF_el_trackphi;   //!
    // TBranch        *b_trig_EF_el_trackpt;   //!
    // TBranch        *b_trig_EF_el_trackqoverp;   //!
    // TBranch        *b_trig_EF_el_tracktheta;   //!
    // TBranch        *b_trig_EF_el_trackz0;   //!
    // TBranch        *b_trig_EF_el_vertweight;   //!
    // TBranch        *b_trig_EF_el_weta2;   //!
    // TBranch        *b_trig_EF_el_ws3;   //!
    // TBranch        *b_trig_EF_el_wstot;   //!
    // TBranch        *b_trig_EF_emcl_E_em;   //!
    // TBranch        *b_trig_EF_emcl_E_had;   //!
    // TBranch        *b_trig_EF_emcl_avg_lar_q;   //!
    // TBranch        *b_trig_EF_emcl_avg_tile_q;   //!
    // TBranch        *b_trig_EF_emcl_badlarq_frac;   //!
    // TBranch        *b_trig_EF_emcl_cellmaxfrac;   //!
    // TBranch        *b_trig_EF_emcl_centerlambda;   //!
    // TBranch        *b_trig_EF_emcl_centermag;   //!
    // TBranch        *b_trig_EF_emcl_deltaPhi;   //!
    // TBranch        *b_trig_EF_emcl_deltaTheta;   //!
    // TBranch        *b_trig_EF_emcl_eng_bad_cells;   //!
    // TBranch        *b_trig_EF_emcl_eng_pos;   //!
    // TBranch        *b_trig_EF_emcl_eta;   //!
    // TBranch        *b_trig_EF_emcl_firstEdens;   //!
    // TBranch        *b_trig_EF_emcl_isolation;   //!
    // TBranch        *b_trig_EF_emcl_lateral;   //!
    // TBranch        *b_trig_EF_emcl_longitudinal;   //!
    // TBranch        *b_trig_EF_emcl_n;   //!
    // TBranch        *b_trig_EF_emcl_n_bad_cells;   //!
    // TBranch        *b_trig_EF_emcl_phi;   //!
    // TBranch        *b_trig_EF_emcl_pt;   //!
    // TBranch        *b_trig_EF_emcl_secondR;   //!
    // TBranch        *b_trig_EF_emcl_secondlambda;   //!
    // TBranch        *b_trig_EF_emcl_significance;   //!
    // TBranch        *b_trig_EF_emcl_slw_E_em;   //!
    // TBranch        *b_trig_EF_emcl_slw_E_had;   //!
    // TBranch        *b_trig_EF_emcl_slw_avg_lar_q;   //!
    // TBranch        *b_trig_EF_emcl_slw_avg_tile_q;   //!
    // TBranch        *b_trig_EF_emcl_slw_badlarq_frac;   //!
    // TBranch        *b_trig_EF_emcl_slw_cellmaxfrac;   //!
    // TBranch        *b_trig_EF_emcl_slw_centerlambda;   //!
    // TBranch        *b_trig_EF_emcl_slw_centermag;   //!
    // TBranch        *b_trig_EF_emcl_slw_deltaPhi;   //!
    // TBranch        *b_trig_EF_emcl_slw_deltaTheta;   //!
    // TBranch        *b_trig_EF_emcl_slw_eng_bad_cells;   //!
    // TBranch        *b_trig_EF_emcl_slw_eng_pos;   //!
    // TBranch        *b_trig_EF_emcl_slw_eta;   //!
    // TBranch        *b_trig_EF_emcl_slw_firstEdens;   //!
    // TBranch        *b_trig_EF_emcl_slw_isolation;   //!
    // TBranch        *b_trig_EF_emcl_slw_lateral;   //!
    // TBranch        *b_trig_EF_emcl_slw_longitudinal;   //!
    // TBranch        *b_trig_EF_emcl_slw_n;   //!
    // TBranch        *b_trig_EF_emcl_slw_n_bad_cells;   //!
    // TBranch        *b_trig_EF_emcl_slw_phi;   //!
    // TBranch        *b_trig_EF_emcl_slw_pt;   //!
    // TBranch        *b_trig_EF_emcl_slw_secondR;   //!
    // TBranch        *b_trig_EF_emcl_slw_secondlambda;   //!
    // TBranch        *b_trig_EF_emcl_slw_significance;   //!
    // TBranch        *b_trig_EF_emcl_slw_time;   //!
    // TBranch        *b_trig_EF_emcl_time;   //!
    // TBranch        *b_trig_EF_feb_met_MEx;   //!
    // TBranch        *b_trig_EF_feb_met_MExComponent;   //!
    // TBranch        *b_trig_EF_feb_met_MEy;   //!
    // TBranch        *b_trig_EF_feb_met_MEyComponent;   //!
    // TBranch        *b_trig_EF_feb_met_MEz;   //!
    // TBranch        *b_trig_EF_feb_met_MEzComponent;   //!
    // TBranch        *b_trig_EF_feb_met_componentCalib0;   //!
    // TBranch        *b_trig_EF_feb_met_componentCalib1;   //!
    // TBranch        *b_trig_EF_feb_met_flag;   //!
    // TBranch        *b_trig_EF_feb_met_nameOfComponent;   //!
    // TBranch        *b_trig_EF_feb_met_status;   //!
    // TBranch        *b_trig_EF_feb_met_sumE;   //!
    // TBranch        *b_trig_EF_feb_met_sumEComponent;   //!
    // TBranch        *b_trig_EF_feb_met_sumEt;   //!
    // TBranch        *b_trig_EF_feb_met_sumEtComponent;   //!
    // TBranch        *b_trig_EF_feb_met_sumOfSigns;   //!
    // TBranch        *b_trig_EF_feb_met_usedChannels;   //!
    // TBranch        *b_trig_EF_jet_AverageLArQF;   //!
    // TBranch        *b_trig_EF_jet_Discriminant;   //!
    // TBranch        *b_trig_EF_jet_E;   //!
    // TBranch        *b_trig_EF_jet_EMFraction;   //!
    // TBranch        *b_trig_EF_jet_EMJES;   //!
    // TBranch        *b_trig_EF_jet_EMJES_EtaCorr;   //!
    // TBranch        *b_trig_EF_jet_HECQuality;   //!
    // TBranch        *b_trig_EF_jet_LArQuality;   //!
    // TBranch        *b_trig_EF_jet_MeanTowerEtUnsubtr;   //!
    // TBranch        *b_trig_EF_jet_NegativeE;   //!
    // TBranch        *b_trig_EF_jet_RoIword;   //!
    // TBranch        *b_trig_EF_jet_SamplingMax;   //!
    // TBranch        *b_trig_EF_jet_TileQuality;   //!
    // TBranch        *b_trig_EF_jet_Timing;   //!
    // TBranch        *b_trig_EF_jet_TrigJetFeaturesUnpacker_Status;   //!
    // TBranch        *b_trig_EF_jet_a10tc;   //!
    // TBranch        *b_trig_EF_jet_a2hi;   //!
    // TBranch        *b_trig_EF_jet_a4tc;   //!
    // TBranch        *b_trig_EF_jet_author;   //!
    // TBranch        *b_trig_EF_jet_calibtags;   //!
    // TBranch        *b_trig_EF_jet_constscale_E;   //!
    // TBranch        *b_trig_EF_jet_constscale_eta;   //!
    // TBranch        *b_trig_EF_jet_constscale_m;   //!
    // TBranch        *b_trig_EF_jet_constscale_phi;   //!
    // TBranch        *b_trig_EF_jet_constscale_pt;   //!
    // TBranch        *b_trig_EF_jet_emscale_E;   //!
    // TBranch        *b_trig_EF_jet_emscale_eta;   //!
    // TBranch        *b_trig_EF_jet_emscale_m;   //!
    // TBranch        *b_trig_EF_jet_emscale_phi;   //!
    // TBranch        *b_trig_EF_jet_emscale_pt;   //!
    // TBranch        *b_trig_EF_jet_eta;   //!
    // TBranch        *b_trig_EF_jet_fracSamplingMax;   //!
    // TBranch        *b_trig_EF_jet_hecF;   //!
    // TBranch        *b_trig_EF_jet_m;   //!
    // TBranch        *b_trig_EF_jet_n90;   //!
    // TBranch        *b_trig_EF_jet_n90constituents;   //!
    // TBranch        *b_trig_EF_jet_n;   //!
    // TBranch        *b_trig_EF_jet_phi;   //!
    // TBranch        *b_trig_EF_jet_presamplerFraction;   //!
    // TBranch        *b_trig_EF_jet_pt;   //!
    // TBranch        *b_trig_EF_jetetsum_MEx;   //!
    // TBranch        *b_trig_EF_jetetsum_MExComponent;   //!
    // TBranch        *b_trig_EF_jetetsum_MEy;   //!
    // TBranch        *b_trig_EF_jetetsum_MEyComponent;   //!
    // TBranch        *b_trig_EF_jetetsum_MEz;   //!
    // TBranch        *b_trig_EF_jetetsum_MEzComponent;   //!
    // TBranch        *b_trig_EF_jetetsum_componentCalib0;   //!
    // TBranch        *b_trig_EF_jetetsum_componentCalib1;   //!
    // TBranch        *b_trig_EF_jetetsum_flag;   //!
    // TBranch        *b_trig_EF_jetetsum_nameOfComponent;   //!
    // TBranch        *b_trig_EF_jetetsum_status;   //!
    // TBranch        *b_trig_EF_jetetsum_sumE;   //!
    // TBranch        *b_trig_EF_jetetsum_sumEComponent;   //!
    // TBranch        *b_trig_EF_jetetsum_sumEt;   //!
    // TBranch        *b_trig_EF_jetetsum_sumEtComponent;   //!
    // TBranch        *b_trig_EF_jetetsum_sumOfSigns;   //!
    // TBranch        *b_trig_EF_jetetsum_usedChannels;   //!
    // TBranch        *b_trig_EF_met_MEx;   //!
    // TBranch        *b_trig_EF_met_MExComponent;   //!
    // TBranch        *b_trig_EF_met_MEy;   //!
    // TBranch        *b_trig_EF_met_MEyComponent;   //!
    // TBranch        *b_trig_EF_met_MEz;   //!
    // TBranch        *b_trig_EF_met_MEzComponent;   //!
    // TBranch        *b_trig_EF_met_componentCalib0;   //!
    // TBranch        *b_trig_EF_met_componentCalib1;   //!
    // TBranch        *b_trig_EF_met_flag;   //!
    // TBranch        *b_trig_EF_met_nameOfComponent;   //!
    // TBranch        *b_trig_EF_met_status;   //!
    // TBranch        *b_trig_EF_met_sumE;   //!
    // TBranch        *b_trig_EF_met_sumEComponent;   //!
    // TBranch        *b_trig_EF_met_sumEt;   //!
    // TBranch        *b_trig_EF_met_sumEtComponent;   //!
    // TBranch        *b_trig_EF_met_sumOfSigns;   //!
    // TBranch        *b_trig_EF_met_usedChannels;   //!
    // TBranch        *b_trig_EF_passedPhysics;   //!
    // TBranch        *b_trig_EF_passedRaw;   //!
    // TBranch        *b_trig_EF_passedThrough;   //!
    // TBranch        *b_trig_EF_ph_E033;   //!
    // TBranch        *b_trig_EF_ph_E1152;   //!
    // TBranch        *b_trig_EF_ph_E132;   //!
    // TBranch        *b_trig_EF_ph_E233;   //!
    // TBranch        *b_trig_EF_ph_E237;   //!
    // TBranch        *b_trig_EF_ph_E277;   //!
    // TBranch        *b_trig_EF_ph_E;   //!
    // TBranch        *b_trig_EF_ph_EF_2g15vh_loose_g10_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_2g15vh_medium;   //!
    // TBranch        *b_trig_EF_ph_EF_2g15vh_medium_g10_medium;   //!
    // TBranch        *b_trig_EF_ph_EF_2g20_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_2g20vh_medium;   //!
    // TBranch        *b_trig_EF_ph_EF_2g30_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_2g40_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_g100_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_g10_NoCut_cosmic;   //!
    // TBranch        *b_trig_EF_ph_EF_g10_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_g10_medium;   //!
    // TBranch        *b_trig_EF_ph_EF_g120_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_g12Tvh_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_g12Tvh_loose_larcalib;   //!
    // TBranch        *b_trig_EF_ph_EF_g12Tvh_medium;   //!
    // TBranch        *b_trig_EF_ph_EF_g15_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_g15vh_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_g15vh_medium;   //!
    // TBranch        *b_trig_EF_ph_EF_g200_etcut;   //!
    // TBranch        *b_trig_EF_ph_EF_g20Tvh_medium;   //!
    // TBranch        *b_trig_EF_ph_EF_g20_etcut;   //!
    // TBranch        *b_trig_EF_ph_EF_g20_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_g20_loose_larcalib;   //!
    // TBranch        *b_trig_EF_ph_EF_g20_medium;   //!
    // TBranch        *b_trig_EF_ph_EF_g20vh_medium;   //!
    // TBranch        *b_trig_EF_ph_EF_g30_loose_g20_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_g30_medium_g20_medium;   //!
    // TBranch        *b_trig_EF_ph_EF_g35_loose_g25_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_g35_loose_g30_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_g40_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_g40_loose_EFxe50;   //!
    // TBranch        *b_trig_EF_ph_EF_g40_loose_L2EFxe50;   //!
    // TBranch        *b_trig_EF_ph_EF_g40_loose_L2EFxe60;   //!
    // TBranch        *b_trig_EF_ph_EF_g40_loose_L2EFxe60_tclcw;   //!
    // TBranch        *b_trig_EF_ph_EF_g40_loose_g25_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_g40_loose_g30_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_g40_loose_larcalib;   //!
    // TBranch        *b_trig_EF_ph_EF_g5_NoCut_cosmic;   //!
    // TBranch        *b_trig_EF_ph_EF_g60_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_g60_loose_larcalib;   //!
    // TBranch        *b_trig_EF_ph_EF_g80_loose;   //!
    // TBranch        *b_trig_EF_ph_EF_g80_loose_larcalib;   //!
    // TBranch        *b_trig_EF_ph_Emax2;   //!
    // TBranch        *b_trig_EF_ph_Emins1;   //!
    // TBranch        *b_trig_EF_ph_Et;   //!
    // TBranch        *b_trig_EF_ph_Etcone15;   //!
    // TBranch        *b_trig_EF_ph_Etcone20;   //!
    // TBranch        *b_trig_EF_ph_Etcone25;   //!
    // TBranch        *b_trig_EF_ph_Etcone30;   //!
    // TBranch        *b_trig_EF_ph_Etcone35;   //!
    // TBranch        *b_trig_EF_ph_Etcone40;   //!
    // TBranch        *b_trig_EF_ph_Etcone45;   //!
    // TBranch        *b_trig_EF_ph_Ethad1;   //!
    // TBranch        *b_trig_EF_ph_Ethad;   //!
    // TBranch        *b_trig_EF_ph_Rconv;   //!
    // TBranch        *b_trig_EF_ph_author;   //!
    // TBranch        *b_trig_EF_ph_cl_E;   //!
    // TBranch        *b_trig_EF_ph_cl_eta;   //!
    // TBranch        *b_trig_EF_ph_cl_etas2;   //!
    // TBranch        *b_trig_EF_ph_cl_phi;   //!
    // TBranch        *b_trig_EF_ph_cl_pt;   //!
    // TBranch        *b_trig_EF_ph_convFlag;   //!
    // TBranch        *b_trig_EF_ph_convanglematch;   //!
    // TBranch        *b_trig_EF_ph_convtrackmatch;   //!
    // TBranch        *b_trig_EF_ph_convtrk1nBLHits;   //!
    // TBranch        *b_trig_EF_ph_convtrk1nPixHits;   //!
    // TBranch        *b_trig_EF_ph_convtrk1nSCTHits;   //!
    // TBranch        *b_trig_EF_ph_convtrk1nTRTHits;   //!
    // TBranch        *b_trig_EF_ph_convtrk2nBLHits;   //!
    // TBranch        *b_trig_EF_ph_convtrk2nPixHits;   //!
    // TBranch        *b_trig_EF_ph_convtrk2nSCTHits;   //!
    // TBranch        *b_trig_EF_ph_convtrk2nTRTHits;   //!
    // TBranch        *b_trig_EF_ph_convvtxchi2;   //!
    // TBranch        *b_trig_EF_ph_convvtxx;   //!
    // TBranch        *b_trig_EF_ph_convvtxy;   //!
    // TBranch        *b_trig_EF_ph_convvtxz;   //!
    // TBranch        *b_trig_EF_ph_deltaEs;   //!
    // TBranch        *b_trig_EF_ph_emaxs1;   //!
    // TBranch        *b_trig_EF_ph_eta;   //!
    // TBranch        *b_trig_EF_ph_f1;   //!
    // TBranch        *b_trig_EF_ph_f1core;   //!
    // TBranch        *b_trig_EF_ph_f3;   //!
    // TBranch        *b_trig_EF_ph_f3core;   //!
    // TBranch        *b_trig_EF_ph_fside;   //!
    // TBranch        *b_trig_EF_ph_hasconv;   //!
    // TBranch        *b_trig_EF_ph_isConv;   //!
    // TBranch        *b_trig_EF_ph_isEM;   //!
    // TBranch        *b_trig_EF_ph_isEMLoose;   //!
    // TBranch        *b_trig_EF_ph_isEMMedium;   //!
    // TBranch        *b_trig_EF_ph_isEMTight;   //!
    // TBranch        *b_trig_EF_ph_isRecovered;   //!
    // TBranch        *b_trig_EF_ph_loose;   //!
    // TBranch        *b_trig_EF_ph_looseAR;   //!
    // TBranch        *b_trig_EF_ph_looseARIso;   //!
    // TBranch        *b_trig_EF_ph_looseIso;   //!
    // TBranch        *b_trig_EF_ph_m;   //!
    // TBranch        *b_trig_EF_ph_n;   //!
    // TBranch        *b_trig_EF_ph_nConv;   //!
    // TBranch        *b_trig_EF_ph_nDoubleTrackConv;   //!
    // TBranch        *b_trig_EF_ph_nSingleTrackConv;   //!
    // TBranch        *b_trig_EF_ph_phi;   //!
    // TBranch        *b_trig_EF_ph_pt1conv;   //!
    // TBranch        *b_trig_EF_ph_pt2conv;   //!
    // TBranch        *b_trig_EF_ph_pt;   //!
    // TBranch        *b_trig_EF_ph_ptcone20;   //!
    // TBranch        *b_trig_EF_ph_ptcone30;   //!
    // TBranch        *b_trig_EF_ph_ptcone40;   //!
    // TBranch        *b_trig_EF_ph_ptconv;   //!
    // TBranch        *b_trig_EF_ph_px;   //!
    // TBranch        *b_trig_EF_ph_py;   //!
    // TBranch        *b_trig_EF_ph_pz;   //!
    // TBranch        *b_trig_EF_ph_pzconv;   //!
    // TBranch        *b_trig_EF_ph_reta;   //!
    // TBranch        *b_trig_EF_ph_rphi;   //!
    // TBranch        *b_trig_EF_ph_rphiallcalo;   //!
    // TBranch        *b_trig_EF_ph_tight;   //!
    // TBranch        *b_trig_EF_ph_tightAR;   //!
    // TBranch        *b_trig_EF_ph_tightARIso;   //!
    // TBranch        *b_trig_EF_ph_tightIso;   //!
    // TBranch        *b_trig_EF_ph_weta2;   //!
    // TBranch        *b_trig_EF_ph_ws3;   //!
    // TBranch        *b_trig_EF_ph_wstot;   //!
    // TBranch        *b_trig_EF_ph_zconv;   //!
    // TBranch        *b_trig_EF_pv_err_x;   //!
    // TBranch        *b_trig_EF_pv_err_y;   //!
    // TBranch        *b_trig_EF_pv_err_z;   //!
    // TBranch        *b_trig_EF_pv_n;   //!
    // TBranch        *b_trig_EF_pv_type;   //!
    // TBranch        *b_trig_EF_pv_x;   //!
    // TBranch        *b_trig_EF_pv_y;   //!
    // TBranch        *b_trig_EF_pv_z;   //!
    // TBranch        *b_trig_EF_resurrected;   //!
    // TBranch        *b_trig_EF_tau_BDTJetScore;   //!
    // TBranch        *b_trig_EF_tau_EF_2tau29T_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_2tau29_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_2tau29i_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_2tau38T_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_2tau38T_medium1_llh;   //!
    // TBranch        *b_trig_EF_tau_EF_2tau38T_medium;   //!
    // TBranch        *b_trig_EF_tau_EF_tau125_IDTrkNoCut;   //!
    // TBranch        *b_trig_EF_tau_EF_tau125_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau125_medium1_L2StarA;   //!
    // TBranch        *b_trig_EF_tau_EF_tau125_medium1_L2StarB;   //!
    // TBranch        *b_trig_EF_tau_EF_tau125_medium1_L2StarC;   //!
    // TBranch        *b_trig_EF_tau_EF_tau125_medium1_llh;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20T_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20T_medium1_e15vh_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20T_medium1_mu15i;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20T_medium;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20T_medium_mu15;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20Ti_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20Ti_medium1_e18vh_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20Ti_medium1_llh_e18vh_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20Ti_medium;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20Ti_medium_e18vh_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20Ti_tight1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20Ti_tight1_llh;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20_medium1_llh;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20_medium1_llh_mu15;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20_medium1_mu15;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20_medium1_mu15i;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20_medium1_mu18;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20_medium;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20_medium_llh;   //!
    // TBranch        *b_trig_EF_tau_EF_tau20_medium_mu15;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29T_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29T_medium1_tau20T_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29T_medium1_xe40_tight;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29T_medium1_xe45_tight;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29T_medium;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29T_medium_xe40_tight;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29T_medium_xe45_tight;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29T_tight1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29T_tight1_llh;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29Ti_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29Ti_medium1_llh_tau20Ti_medium1_llh;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29Ti_medium1_llh_xe40_tight;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29Ti_medium1_llh_xe45_tight;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29Ti_medium1_tau20Ti_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29Ti_medium1_xe40_tight;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29Ti_medium1_xe45_tight;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29Ti_medium1_xe55_tclcw;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29Ti_medium1_xe55_tclcw_tight;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29Ti_medium_xe40_tight;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29Ti_medium_xe45_tight;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29Ti_tight1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29Ti_tight1_llh;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29Ti_tight1_llh_tau20Ti_tight1_llh;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29Ti_tight1_tau20Ti_tight1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29_IDTrkNoCut;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29_medium1_llh;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29_medium;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29_medium_2stTest;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29_medium_L2StarA;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29_medium_L2StarB;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29_medium_L2StarC;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29_medium_llh;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29i_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau29i_medium;   //!
    // TBranch        *b_trig_EF_tau_EF_tau38T_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau38T_medium1_e18vh_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau38T_medium1_llh_e18vh_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau38T_medium1_xe40_tight;   //!
    // TBranch        *b_trig_EF_tau_EF_tau38T_medium1_xe45_tight;   //!
    // TBranch        *b_trig_EF_tau_EF_tau38T_medium1_xe55_tclcw_tight;   //!
    // TBranch        *b_trig_EF_tau_EF_tau38T_medium;   //!
    // TBranch        *b_trig_EF_tau_EF_tau38T_medium_e18vh_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau50_medium1_e18vh_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tau50_medium;   //!
    // TBranch        *b_trig_EF_tau_EF_tau50_medium_e15vh_medium1;   //!
    // TBranch        *b_trig_EF_tau_EF_tauNoCut;   //!
    // TBranch        *b_trig_EF_tau_EF_tauNoCut_L1TAU40;   //!
    // TBranch        *b_trig_EF_tau_EF_tauNoCut_cosmic;   //!
    // TBranch        *b_trig_EF_tau_Et;   //!
    // TBranch        *b_trig_EF_tau_LC_TES_precalib;   //!
    // TBranch        *b_trig_EF_tau_RoIWord;   //!
    // TBranch        *b_trig_EF_tau_author;   //!
    // TBranch        *b_trig_EF_tau_effTopoInvMass;   //!
    // TBranch        *b_trig_EF_tau_effTopoMeanDeltaR;   //!
    // TBranch        *b_trig_EF_tau_etOverPtLeadTrk;   //!
    // TBranch        *b_trig_EF_tau_eta;   //!
    // TBranch        *b_trig_EF_tau_ipSigLeadTrk;   //!
    // TBranch        *b_trig_EF_tau_ipZ0SinThetaSigLeadTrk;   //!
    // TBranch        *b_trig_EF_tau_leadTrkPt;   //!
    // TBranch        *b_trig_EF_tau_likelihood;   //!
    // TBranch        *b_trig_EF_tau_m;   //!
    // TBranch        *b_trig_EF_tau_massTrkSys;   //!
    // TBranch        *b_trig_EF_tau_n;   //!
    // TBranch        *b_trig_EF_tau_nOtherTrk;   //!
    // TBranch        *b_trig_EF_tau_nProng;   //!
    // TBranch        *b_trig_EF_tau_numCells;   //!
    // TBranch        *b_trig_EF_tau_numEffTopoClusters;   //!
    // TBranch        *b_trig_EF_tau_numTopoClusters;   //!
    // TBranch        *b_trig_EF_tau_numTrack;   //!
    // TBranch        *b_trig_EF_tau_otherTrk_n;   //!
    // TBranch        *b_trig_EF_tau_phi;   //!
    // TBranch        *b_trig_EF_tau_pt;   //!
    // TBranch        *b_trig_EF_tau_px;   //!
    // TBranch        *b_trig_EF_tau_py;   //!
    // TBranch        *b_trig_EF_tau_pz;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_EMRadius;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_centFrac;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_dRmax;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_etEMAtEMScale;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_etEMCalib;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_etHadAtEMScale;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_etHadCalib;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_eta;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_hadRadius;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_isolFrac;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_lead2ClusterEOverAllClusterE;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_lead3ClusterEOverAllClusterE;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_nStrip;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_nWideTrk;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_numTrack;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_phi;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_stripWidth2;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_track_n;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_trkAvgDist;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_trkRmsDist;   //!
    // TBranch        *b_trig_EF_tau_seedCalo_wideTrk_n;   //!
    // TBranch        *b_trig_EF_tau_topoInvMass;   //!
    // TBranch        *b_trig_EF_tau_topoMeanDeltaR;   //!
    // TBranch        *b_trig_EF_tau_trFlightPathSig;   //!
    // TBranch        *b_trig_EF_tau_track_n;   //!
    // TBranch        *b_trig_EF_topocl_met_MEx;   //!
    // TBranch        *b_trig_EF_topocl_met_MExComponent;   //!
    // TBranch        *b_trig_EF_topocl_met_MEy;   //!
    // TBranch        *b_trig_EF_topocl_met_MEyComponent;   //!
    // TBranch        *b_trig_EF_topocl_met_MEz;   //!
    // TBranch        *b_trig_EF_topocl_met_MEzComponent;   //!
    // TBranch        *b_trig_EF_topocl_met_componentCalib0;   //!
    // TBranch        *b_trig_EF_topocl_met_componentCalib1;   //!
    // TBranch        *b_trig_EF_topocl_met_flag;   //!
    // TBranch        *b_trig_EF_topocl_met_nameOfComponent;   //!
    // TBranch        *b_trig_EF_topocl_met_status;   //!
    // TBranch        *b_trig_EF_topocl_met_sumE;   //!
    // TBranch        *b_trig_EF_topocl_met_sumEComponent;   //!
    // TBranch        *b_trig_EF_topocl_met_sumEt;   //!
    // TBranch        *b_trig_EF_topocl_met_sumEtComponent;   //!
    // TBranch        *b_trig_EF_topocl_met_sumOfSigns;   //!
    // TBranch        *b_trig_EF_topocl_met_usedChannels;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu10;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose_EMPTY;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu13;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu13_l2muonSA;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu15;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_2e5_tight1;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_Bmumu;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_Bmumux;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_DiMu;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_Jpsimumu;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_Upsimumu;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_xe50_tclcw;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_xe60;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu6;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu6_Bmumu;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu6_Bmumux;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu6_DiMu;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu6_DiMu_DY20;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu6_DiMu_DY25;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu6_Jpsimumu;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu6_Upsimumu;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu6i_DiMu_DY;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu8_EFxe30;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu10;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu10_Jpsimumu;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu10_MSonly;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu10i_g10_loose;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu10i_g10_loose_TauMass;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu10i_g10_medium;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_loose;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_loose_TauMass;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu11_empty_NoAlg;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu15;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu18;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu18_2g10_loose;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu18_2g10_medium;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu18_2g15_loose;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu18_g20vh_loose;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu18_medium;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu18_tight_e7_medium1;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu18i4_tight;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu18it_tight;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu20i_tight_g5_loose;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu20i_tight_g5_medium;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu20it_tight;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_g20vh_loose;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_g20vh_medium;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_j65_a4tchad;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe50_tclcw;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_medium;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_tight;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_tight_2j35_a4tchad;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_tight_4j35_a4tchad;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_tight_EFxe40;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_tight_L2StarB;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_tight_L2StarC;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_tight_MG;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_tight_MuonEF;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24i_tight;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24i_tight_MG;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24i_tight_MuonEF;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu36_tight;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu40_slow_tight;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu40_tight;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_Trk_Jpsi;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_cosmic;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j360_a4tchad_L2FS_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j360_a4tchad_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_loose;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_loose_TauMass;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4Tmu6_DiMu;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4_empty_NoAlg;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu60_slow_tight1;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu6;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu6_MSonly;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu6i;   //!
    // TBranch        *b_trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS;   //!
    // TBranch        *b_trig_EF_trigmuonef_effs15;   //!
    // TBranch        *b_trig_EF_trigmuonef_effs18;   //!
    // TBranch        *b_trig_EF_trigmuonef_effs24;   //!
    // TBranch        *b_trig_EF_trigmuonef_n;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_CB_charge;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_CB_chi2;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_CB_chi2prob;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_CB_d0;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_CB_matchChi2;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_CB_posX;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_CB_posY;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_CB_posZ;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_CB_z0;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_MS_charge;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_MS_chi2;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_MS_chi2prob;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_MS_d0;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_MS_eta;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_MS_hasMS;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_MS_phi;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_MS_posX;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_MS_posY;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_MS_posZ;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_MS_pt;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_MS_z0;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_MuonType;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_SA_charge;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_SA_chi2;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_SA_chi2prob;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_SA_d0;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_SA_eta;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_SA_hasSA;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_SA_phi;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_SA_posX;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_SA_posY;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_SA_posZ;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_SA_pt;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_SA_z0;   //!
    // TBranch        *b_trig_EF_trigmuonef_track_n;   //!
    // TBranch        *b_trig_EF_trigmuonefisolation_efinfoMG_index;   //!
    // TBranch        *b_trig_EF_trigmuonefisolation_efinfo_index;   //!
    // TBranch        *b_trig_EF_trigmuonefisolation_n;   //!
    // TBranch        *b_trig_EF_trigmuonefisolation_sumEtCone01;   //!
    // TBranch        *b_trig_EF_trigmuonefisolation_sumEtCone02;   //!
    // TBranch        *b_trig_EF_trigmuonefisolation_sumEtCone03;   //!
    // TBranch        *b_trig_EF_trigmuonefisolation_sumEtCone04;   //!
    // TBranch        *b_trig_EF_trigmuonefisolation_sumTrkPtCone02;   //!
    // TBranch        *b_trig_EF_trigmuonefisolation_sumTrkPtCone03;   //!
    // TBranch        *b_trig_EF_trigmuonefisolation_trackPosition;   //!
    // TBranch        *b_trig_EF_truncated;   //!
    // TBranch        *b_trig_EF_wasPrescaled;   //!
    // TBranch        *b_trig_EF_wasResurrected;   //!
    // TBranch        *b_trig_Nav_chain_ChainId;   //!
    // TBranch        *b_trig_Nav_chain_RoIIndex;   //!
    // TBranch        *b_trig_Nav_chain_RoIType;   //!
    // TBranch        *b_trig_Nav_n;   //!
    // TBranch        *b_trig_bgCode;   //!
    // TBranch        *b_trig_roidescriptor_forID_eta;   //!
    // TBranch        *b_trig_roidescriptor_forID_etaHalfWidth;   //!
    // TBranch        *b_trig_roidescriptor_forID_etaMinus;   //!
    // TBranch        *b_trig_roidescriptor_forID_etaPlus;   //!
    // TBranch        *b_trig_roidescriptor_forID_n;   //!
    // TBranch        *b_trig_roidescriptor_forID_phi;   //!
    // TBranch        *b_trig_roidescriptor_forID_phiHalfWidth;   //!
    // TBranch        *b_trig_roidescriptor_forID_zed0;   //!
    // TBranch        *b_trig_roidescriptor_forID_zedHalfWidth;   //!
    // TBranch        *b_trk_IPEstimate_d0_biased_wrtPV;   //!
    // TBranch        *b_trk_IPEstimate_d0_unbiased_wrtPV;   //!
    // TBranch        *b_trk_IPEstimate_errPV_d0_biased_wrtPV;   //!
    // TBranch        *b_trk_IPEstimate_errPV_d0_unbiased_wrtPV;   //!
    // TBranch        *b_trk_IPEstimate_errPV_z0_biased_wrtPV;   //!
    // TBranch        *b_trk_IPEstimate_errPV_z0_unbiased_wrtPV;   //!
    // TBranch        *b_trk_IPEstimate_err_d0_biased_wrtPV;   //!
    // TBranch        *b_trk_IPEstimate_err_d0_unbiased_wrtPV;   //!
    // TBranch        *b_trk_IPEstimate_err_z0_biased_wrtPV;   //!
    // TBranch        *b_trk_IPEstimate_err_z0_unbiased_wrtPV;   //!
    // TBranch        *b_trk_IPEstimate_z0_biased_wrtPV;   //!
    // TBranch        *b_trk_IPEstimate_z0_unbiased_wrtPV;   //!
    // TBranch        *b_trk_TRTHighTHitsRatio;   //!
    // TBranch        *b_trk_TRTHighTOutliersRatio;   //!
    // TBranch        *b_trk_chi2;   //!
    // TBranch        *b_trk_cone20_caloIso;   //!
    // TBranch        *b_trk_cone20_nTrackIso;   //!
    // TBranch        *b_trk_cone20_trackIso;   //!
    // TBranch        *b_trk_cone30_caloIso;   //!
    // TBranch        *b_trk_cone30_nTrackIso;   //!
    // TBranch        *b_trk_cone30_trackIso;   //!
    // TBranch        *b_trk_cone40_caloIso;   //!
    // TBranch        *b_trk_cone40_nTrackIso;   //!
    // TBranch        *b_trk_cone40_ptmin1gev_caloIso;   //!
    // TBranch        *b_trk_cone40_ptmin1gev_nTrackIso;   //!
    // TBranch        *b_trk_cone40_ptmin1gev_trackIso;   //!
    // TBranch        *b_trk_cone40_ptmin2gev_caloIso;   //!
    // TBranch        *b_trk_cone40_ptmin2gev_nTrackIso;   //!
    // TBranch        *b_trk_cone40_ptmin2gev_trackIso;   //!
    // TBranch        *b_trk_cone40_ptmin3gev_caloIso;   //!
    // TBranch        *b_trk_cone40_ptmin3gev_hitschi_caloIso;   //!
    // TBranch        *b_trk_cone40_ptmin3gev_hitschi_nTrackIso;   //!
    // TBranch        *b_trk_cone40_ptmin3gev_hitschi_trackIso;   //!
    // TBranch        *b_trk_cone40_ptmin3gev_nTrackIso;   //!
    // TBranch        *b_trk_cone40_ptmin3gev_trackIso;   //!
    // TBranch        *b_trk_cone40_ptmin4gev_caloIso;   //!
    // TBranch        *b_trk_cone40_ptmin4gev_nTrackIso;   //!
    // TBranch        *b_trk_cone40_ptmin4gev_trackIso;   //!
    // TBranch        *b_trk_cone40_ptmin5gev_caloIso;   //!
    // TBranch        *b_trk_cone40_ptmin5gev_nTrackIso;   //!
    // TBranch        *b_trk_cone40_ptmin5gev_trackIso;   //!
    // TBranch        *b_trk_cone40_trackIso;   //!
    // TBranch        *b_trk_cov_d0_phi_wrtBS;   //!
    // TBranch        *b_trk_cov_d0_qoverp_wrtBS;   //!
    // TBranch        *b_trk_cov_d0_theta_wrtBS;   //!
    // TBranch        *b_trk_cov_d0_wrtBS;   //!
    // TBranch        *b_trk_cov_d0_wrtPV;   //!
    // TBranch        *b_trk_cov_d0_z0_wrtBS;   //!
    // TBranch        *b_trk_cov_phi_qoverp_wrtBS;   //!
    // TBranch        *b_trk_cov_phi_theta_wrtBS;   //!
    // TBranch        *b_trk_cov_phi_wrtBS;   //!
    // TBranch        *b_trk_cov_phi_wrtPV;   //!
    // TBranch        *b_trk_cov_qoverp_wrtBS;   //!
    // TBranch        *b_trk_cov_qoverp_wrtPV;   //!
    // TBranch        *b_trk_cov_theta_qoverp_wrtBS;   //!
    // TBranch        *b_trk_cov_theta_wrtBS;   //!
    // TBranch        *b_trk_cov_theta_wrtPV;   //!
    // TBranch        *b_trk_cov_z0_phi_wrtBS;   //!
    // TBranch        *b_trk_cov_z0_qoverp_wrtBS;   //!
    // TBranch        *b_trk_cov_z0_theta_wrtBS;   //!
    // TBranch        *b_trk_cov_z0_wrtBS;   //!
    // TBranch        *b_trk_cov_z0_wrtPV;   //!
    // TBranch        *b_trk_d0_err_wrtBL;   //!
    // TBranch        *b_trk_d0_phi_err_wrtBL;   //!
    // TBranch        *b_trk_d0_qoverp_err_wrtBL;   //!
    // TBranch        *b_trk_d0_theta_err_wrtBL;   //!
    // TBranch        *b_trk_d0_wrtBL;   //!
    // TBranch        *b_trk_d0_wrtBS;   //!
    // TBranch        *b_trk_d0_wrtPV;   //!
    // TBranch        *b_trk_d0_z0_err_wrtBL;   //!
    // TBranch        *b_trk_eta;   //!
    // TBranch        *b_trk_expectBLayerHit;   //!
    // TBranch        *b_trk_hitPattern;   //!
    // TBranch        *b_trk_mc_barcode;   //!
    // TBranch        *b_trk_mc_probability;   //!
    // TBranch        *b_trk_n;   //!
    // TBranch        *b_trk_nBLHits;   //!
    // TBranch        *b_trk_nBLSharedHits;   //!
    // TBranch        *b_trk_nBLayerSplitHits;   //!
    // TBranch        *b_trk_nCSCEtaHits;   //!
    // TBranch        *b_trk_nCSCPhiHits;   //!
    // TBranch        *b_trk_nHits;   //!
    // TBranch        *b_trk_nHoles;   //!
    // TBranch        *b_trk_nMDTHits;   //!
    // TBranch        *b_trk_nPixHits;   //!
    // TBranch        *b_trk_nPixHoles;   //!
    // TBranch        *b_trk_nPixSharedHits;   //!
    // TBranch        *b_trk_nPixSplitHits;   //!
    // TBranch        *b_trk_nPixelDeadSensors;   //!
    // TBranch        *b_trk_nRPCEtaHits;   //!
    // TBranch        *b_trk_nRPCPhiHits;   //!
    // TBranch        *b_trk_nSCTDeadSensors;   //!
    // TBranch        *b_trk_nSCTHits;   //!
    // TBranch        *b_trk_nSCTHoles;   //!
    // TBranch        *b_trk_nSCTSharedHits;   //!
    // TBranch        *b_trk_nTGCEtaHits;   //!
    // TBranch        *b_trk_nTGCPhiHits;   //!
    // TBranch        *b_trk_nTRTHighTHits;   //!
    // TBranch        *b_trk_nTRTHits;   //!
    // TBranch        *b_trk_nTRTHoles;   //!
    // TBranch        *b_trk_nTRTXenonHits;   //!
    // TBranch        *b_trk_ndof;   //!
    // TBranch        *b_trk_phi_err_wrtBL;   //!
    // TBranch        *b_trk_phi_qoverp_err_wrtBL;   //!
    // TBranch        *b_trk_phi_theta_err_wrtBL;   //!
    // TBranch        *b_trk_phi_wrtBL;   //!
    // TBranch        *b_trk_phi_wrtBS;   //!
    // TBranch        *b_trk_phi_wrtPV;   //!
    // TBranch        *b_trk_pt;   //!
    // TBranch        *b_trk_qoverp_err_wrtBL;   //!
    // TBranch        *b_trk_qoverp_wrtPV;   //!
    // TBranch        *b_trk_theta_err_wrtBL;   //!
    // TBranch        *b_trk_theta_qoverp_err_wrtBL;   //!
    // TBranch        *b_trk_theta_wrtPV;   //!
    // TBranch        *b_trk_z0_err_wrtBL;   //!
    // TBranch        *b_trk_z0_phi_err_wrtBL;   //!
    // TBranch        *b_trk_z0_qoverp_err_wrtBL;   //!
    // TBranch        *b_trk_z0_theta_err_wrtBL;   //!
    // TBranch        *b_trk_z0_wrtBL;   //!
    // TBranch        *b_trk_z0_wrtBS;   //!
    // TBranch        *b_trk_z0_wrtPV;   //!
    // TBranch        *b_trtError;   //!
    // TBranch        *b_trtFlags;   //!
    // TBranch        *b_trueTau_charge;   //!
    // TBranch        *b_trueTau_eta;   //!
    // TBranch        *b_trueTau_m;   //!
    // TBranch        *b_trueTau_n;   //!
    // TBranch        *b_trueTau_nPi0;   //!
    // TBranch        *b_trueTau_nProng;   //!
    // TBranch        *b_trueTau_phi;   //!
    // TBranch        *b_trueTau_pt;   //!
    // TBranch        *b_trueTau_tauAssocSmall_dr;   //!
    // TBranch        *b_trueTau_tauAssocSmall_index;   //!
    // TBranch        *b_trueTau_tauAssocSmall_matched;   //!
    // TBranch        *b_trueTau_vis_Et;   //!
    // TBranch        *b_trueTau_vis_eta;   //!
    // TBranch        *b_trueTau_vis_m;   //!
    // TBranch        *b_trueTau_vis_phi;   //!
    // TBranch        *b_vx_px;   //!
    // TBranch        *b_vx_py;   //!
    // TBranch        *b_vx_pz;   //!
    // TBranch        *b_vx_sumPt;   //!

    D3PDReader(TTree* tree, bool is_data);
    virtual ~D3PDReader();
    virtual Int_t    GetEntry(Long64_t entry);
    virtual Long64_t LoadTree(Long64_t entry);
    virtual void     Init(TTree *tree);
    virtual void     ConfigureOutput(std::string out_file_name, std::string out_tree_name);
    virtual void     FillEvent();
    virtual void     FinalizeOutput(int num_generated_events = -1);
    virtual void     writeNumEvents(int num_generated_events = -1);
    virtual Bool_t   Notify();
    virtual void     Show(Long64_t entry = -1);

    template <class T> void turnOnBranch(TTree* tree, std::string str, T var_add, TBranch** branch_add);

    bool checkStatus();
    unsigned int getNumEvents();
  };
}

// Include the implementation:
#ifndef __CINT__
#include "D3PDReader.icc"
#endif // __CINT__

#endif
