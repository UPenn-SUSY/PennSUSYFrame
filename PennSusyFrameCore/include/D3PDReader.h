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
    Bool_t          EF_mu24i_tight;
    Bool_t          EF_mu36_tight;
    Bool_t          EF_mu24_tight_mu6_EFFS;
    Bool_t          EF_e24vhi_medium1;
    Bool_t          EF_e60_medium1;
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
    std::vector<float>   *el_eta;
    std::vector<float>   *el_phi;
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
    std::vector<float>   *jet_AntiKt4LCTopo_BCH_CORR_CELL;
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
    std::vector<int>     *trig_EF_trigmuonef_EF_mu24i_tight;
    std::vector<int>     *trig_EF_trigmuonef_EF_mu36_tight;
    std::vector<int>     *trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS;
    std::vector<int>     *trig_EF_el_EF_e24vhi_medium1;
    std::vector<int>     *trig_EF_el_EF_e60_medium1;
    std::vector<int>     *trig_EF_trigmuonef_EF_mu24_tight;
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
    std::vector<int>     *muonTruth_barcode;
    std::vector<int>     *muonTruth_origin;
    std::vector<int>     *muonTruth_type;
    std::vector<int>     *jet_AntiKt4LCTopo_flavor_truth_label;

    // List of branches
    TBranch        *b_EF_2e12Tvh_loose1;   //!
    TBranch        *b_EF_2mu13;   //!
    TBranch        *b_EF_e12Tvh_medium1_mu8;   //!
    TBranch        *b_EF_e24vh_medium1_e7_medium1;   //!
    TBranch        *b_EF_mu18_tight_e7_medium1;   //!
    TBranch        *b_EF_mu18_tight_mu8_EFFS;   //!
    TBranch        *b_EF_mu24i_tight;   //!
    TBranch        *b_EF_mu36_tight;   //!
    TBranch        *b_EF_mu24_tight_mu6_EFFS;   //!
    TBranch        *b_EF_e24vhi_medium1;   //!
    TBranch        *b_EF_e60_medium1;   //!
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
    TBranch        *b_el_eta;   //!
    TBranch        *b_el_phi;   //!
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
    TBranch        *b_jet_AntiKt4LCTopo_BCH_CORR_CELL;   //!
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
    TBranch        *b_muonTruth_barcode;   //!
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
    TBranch        *b_trig_EF_trigmuonef_EF_mu24i_tight;   //!
    TBranch        *b_trig_EF_trigmuonef_EF_mu36_tight;   //!
    TBranch        *b_trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS;   //!
    TBranch        *b_trig_EF_el_EF_e24vhi_medium1;   //!
    TBranch        *b_trig_EF_el_EF_e60_medium1;   //!
    TBranch        *b_trig_EF_trigmuonef_EF_mu24_tight;   //!
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

    D3PDReader(TTree* tree, bool is_data);
    virtual ~D3PDReader();
    virtual Int_t    GetEntry(Long64_t entry);
    virtual Long64_t LoadTree(Long64_t entry);
    virtual void     Init(TTree *tree);
    virtual void     ConfigureOutput(std::string out_file_name, std::string out_tree_name);
    virtual void     FillEvent();
    virtual void     FinalizeOutput(int num_generated_events = -1, float sum_event_weights = -1);
    virtual void     writeNumEvents(int num_generated_events = -1, float sum_event_weights = -1);
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
