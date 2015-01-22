#define D3PDReader_cxx
#include "PennSusyFrameCore/include/D3PDReader.h"

#include "TVectorF.h"

#include <iostream>

// -----------------------------------------------------------------------------
PennSusyFrame::D3PDReader::D3PDReader(TTree *tree, bool is_data) : m_is_data(is_data)
                                                                 , fChain(0)
                                                                 , m_output_file(0)
                                                                 , m_output_tree(0)
{
  Init(tree);
}

// -----------------------------------------------------------------------------
PennSusyFrame::D3PDReader::~D3PDReader()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

// -----------------------------------------------------------------------------
Int_t PennSusyFrame::D3PDReader::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}

// -----------------------------------------------------------------------------
Long64_t PennSusyFrame::D3PDReader::LoadTree(Long64_t entry)
{
  // Set the environment to read one entry
  if (!fChain) return -5;
  Long64_t centry = fChain->LoadTree(entry);
  if (centry < 0) return centry;
  if (fChain->GetTreeNumber() != fCurrent) {
    fCurrent = fChain->GetTreeNumber();
    Notify();
  }
  return centry;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::D3PDReader::Init(TTree *tree)
{
  std::cout << "D3PDReader::Init() -- is_data: " << m_is_data << "\n";

  tree->SetBranchStatus("*",0);

  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  // initialize object pointer
  el_MET_Egamma10NoTau_statusWord = 0;
  el_MET_Egamma10NoTau_wet = 0;
  el_MET_Egamma10NoTau_wpx = 0;
  el_MET_Egamma10NoTau_wpy = 0;
  el_OQ = 0;
  el_author = 0;
  el_charge = 0;
  el_cl_E = 0;
  el_cl_eta = 0;
  el_cl_phi = 0;
  el_cl_pt = 0;
  el_eta = 0;
  el_phi = 0;
  el_mediumPP = 0;
  el_nSiHits = 0;
  el_ptcone30 = 0;
  el_tightPP = 0;
  el_topoEtcone30_corrected = 0;
  el_trackIPEstimate_d0_unbiasedpvunbiased = 0;
  el_trackIPEstimate_sigd0_unbiasedpvunbiased = 0;
  el_trackIPEstimate_z0_unbiasedpvunbiased = 0;
  el_tracketa = 0;
  el_trackphi = 0;
  jet_AntiKt4LCTopo_ActiveAreaE = 0;
  jet_AntiKt4LCTopo_ActiveAreaPx = 0;
  jet_AntiKt4LCTopo_ActiveAreaPy = 0;
  jet_AntiKt4LCTopo_ActiveAreaPz = 0;
  jet_AntiKt4LCTopo_AverageLArQF = 0;
  jet_AntiKt4LCTopo_BCH_CORR_CELL = 0;
  jet_AntiKt4LCTopo_BCH_CORR_JET = 0;
  jet_AntiKt4LCTopo_HECQuality = 0;
  jet_AntiKt4LCTopo_LArQuality = 0;
  jet_AntiKt4LCTopo_MET_Egamma10NoTau_statusWord = 0;
  jet_AntiKt4LCTopo_MET_Egamma10NoTau_wet = 0;
  jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpx = 0;
  jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpy = 0;
  jet_AntiKt4LCTopo_NegativeE = 0;
  jet_AntiKt4LCTopo_SamplingMax = 0;
  jet_AntiKt4LCTopo_constscale_E = 0;
  jet_AntiKt4LCTopo_constscale_eta = 0;
  jet_AntiKt4LCTopo_constscale_m = 0;
  jet_AntiKt4LCTopo_constscale_phi = 0;
  jet_AntiKt4LCTopo_emfrac = 0;
  jet_AntiKt4LCTopo_eta = 0;
  jet_AntiKt4LCTopo_flavor_weight_MV1 = 0;
  jet_AntiKt4LCTopo_fracSamplingMax = 0;
  jet_AntiKt4LCTopo_hecf = 0;
  jet_AntiKt4LCTopo_jvtxf = 0;
  jet_AntiKt4LCTopo_m = 0;
  jet_AntiKt4LCTopo_phi = 0;
  jet_AntiKt4LCTopo_pt = 0;
  jet_AntiKt4LCTopo_sumPtTrk_pv0_500MeV = 0;
  mu_staco_charge = 0;
  mu_staco_cov_qoverp_exPV = 0;
  mu_staco_d0_exPV = 0;
  mu_staco_eta = 0;
  mu_staco_etcone30 = 0;
  mu_staco_expectBLayerHit = 0;
  mu_staco_id_qoverp_exPV = 0;
  mu_staco_id_theta_exPV = 0;
  mu_staco_isCombinedMuon = 0;
  mu_staco_isSegmentTaggedMuon = 0;
  mu_staco_me_qoverp_exPV = 0;
  mu_staco_me_theta_exPV = 0;
  mu_staco_ms_phi = 0;
  mu_staco_ms_qoverp = 0;
  mu_staco_ms_theta = 0;
  mu_staco_nBLHits = 0;
  mu_staco_nPixHits = 0;
  mu_staco_nPixHoles = 0;
  mu_staco_nSCTDeadSensors = 0;
  mu_staco_nSCTHits = 0;
  mu_staco_nSCTHoles = 0;
  mu_staco_nTRTHits = 0;
  mu_staco_nTRTOutliers = 0;
  mu_staco_phi = 0;
  mu_staco_pt = 0;
  mu_staco_ptcone30_trkelstyle = 0;
  mu_staco_qoverp_exPV = 0;
  mu_staco_trackIPEstimate_d0_unbiasedpvunbiased = 0;
  mu_staco_trackIPEstimate_sigd0_unbiasedpvunbiased = 0;
  mu_staco_trackIPEstimate_z0_unbiasedpvunbiased = 0;
  mu_staco_z0_exPV = 0;
  tau_EleBDTLoose = 0;
  tau_EleBDTMedium = 0;
  tau_EleBDTTight = 0;
  tau_JetBDTSigLoose = 0;
  tau_JetBDTSigMedium = 0;
  tau_JetBDTSigTight = 0;
  tau_charge = 0;
  tau_eta = 0;
  tau_m = 0;
  tau_muonVeto = 0;
  tau_numTrack = 0;
  tau_phi = 0;
  tau_pt = 0;
  trig_EF_el_E = 0;
  trig_EF_el_EF_e12Tvh_loose1 = 0;
  trig_EF_el_EF_e12Tvh_medium1 = 0;
  trig_EF_el_EF_e24vh_medium1 = 0;
  trig_EF_el_EF_e24vh_medium1_e7_medium1 = 0;
  trig_EF_el_EF_e7T_medium1 = 0;
  trig_EF_el_px = 0;
  trig_EF_el_py = 0;
  trig_EF_el_pz = 0;
  trig_EF_trigmuonef_EF_mu13 = 0;
  trig_EF_trigmuonef_EF_mu18_tight = 0;
  trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS = 0;
  trig_EF_trigmuonef_EF_mu8 = 0;
  trig_EF_trigmuonef_EF_mu24i_tight = 0;
  trig_EF_trigmuonef_EF_mu36_tight = 0;
  trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS = 0;
  trig_EF_el_EF_e24vhi_medium1 = 0;
  trig_EF_el_EF_e60_medium1 = 0;
  trig_EF_trigmuonef_EF_mu24_tight = 0;
  trig_EF_trigmuonef_track_CB_eta = 0;
  trig_EF_trigmuonef_track_CB_hasCB = 0;
  trig_EF_trigmuonef_track_CB_phi = 0;
  trig_EF_trigmuonef_track_CB_pt = 0;
  vx_E = 0;
  vx_m = 0;
  vx_nTracks = 0;
  vx_x = 0;
  vx_y = 0;
  vx_z = 0;

  // MC only variables
  el_type = 0;
  el_origin = 0;
  el_truth_barcode = 0;
  el_truth_motherbarcode = 0;
  mc_barcode = 0;
  mc_charge = 0;
  mc_child_index = 0;
  mc_children = 0;
  mc_eta = 0;
  mc_m = 0;
  mc_parent_index = 0;
  mc_parents = 0;
  mc_pdgId = 0;
  mc_phi = 0;
  mc_pt = 0;
  mc_status = 0;
  mc_vx_barcode = 0;
  mu_staco_truth_barcode = 0;
  mu_staco_truth_motherbarcode = 0;
  muonTruth_barcode = 0;
  muonTruth_origin = 0;
  muonTruth_type = 0;
  jet_AntiKt4LCTopo_flavor_truth_label = 0;

  // Set branch addresses and branch pointers
  if (!tree) return;
  fChain = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);

  // turn on branches we want to use
  turnOnBranch(tree, "EF_2e12Tvh_loose1", &EF_2e12Tvh_loose1, &b_EF_2e12Tvh_loose1);
  turnOnBranch(tree, "EF_2mu13", &EF_2mu13, &b_EF_2mu13);
  turnOnBranch(tree, "EF_e12Tvh_medium1_mu8", &EF_e12Tvh_medium1_mu8, &b_EF_e12Tvh_medium1_mu8);
  turnOnBranch(tree, "EF_e24vh_medium1_e7_medium1", &EF_e24vh_medium1_e7_medium1, &b_EF_e24vh_medium1_e7_medium1);
  turnOnBranch(tree, "EF_mu18_tight_e7_medium1", &EF_mu18_tight_e7_medium1, &b_EF_mu18_tight_e7_medium1);
  turnOnBranch(tree, "EF_mu18_tight_mu8_EFFS", &EF_mu18_tight_mu8_EFFS, &b_EF_mu18_tight_mu8_EFFS);

  turnOnBranch(tree, "EF_mu24i_tight", &EF_mu24i_tight, &b_EF_mu24i_tight);
  turnOnBranch(tree, "EF_mu36_tight", &EF_mu36_tight, &b_EF_mu36_tight);
  turnOnBranch(tree, "EF_mu24_tight_mu6_EFFS", &EF_mu24_tight_mu6_EFFS, &b_EF_mu24_tight_mu6_EFFS);
  turnOnBranch(tree, "EF_e24vhi_medium1", &EF_e24vhi_medium1, &b_EF_e24vhi_medium1);
  turnOnBranch(tree, "EF_e60_medium1", &EF_e60_medium1, &b_EF_e60_medium1);

  turnOnBranch(tree, "EventNumber", &EventNumber, &b_EventNumber);
  turnOnBranch(tree, "Eventshape_rhoKt4LC", &Eventshape_rhoKt4LC, &b_Eventshape_rhoKt4LC);
  turnOnBranch(tree, "MET_Egamma10NoTau_CellOut_etx", &MET_Egamma10NoTau_CellOut_etx, &b_MET_Egamma10NoTau_CellOut_etx);
  turnOnBranch(tree, "MET_Egamma10NoTau_CellOut_ety", &MET_Egamma10NoTau_CellOut_ety, &b_MET_Egamma10NoTau_CellOut_ety);
  turnOnBranch(tree, "MET_Egamma10NoTau_CellOut_sumet", &MET_Egamma10NoTau_CellOut_sumet, &b_MET_Egamma10NoTau_CellOut_sumet);
  turnOnBranch(tree, "MET_Egamma10NoTau_RefGamma_etx", &MET_Egamma10NoTau_RefGamma_etx, &b_MET_Egamma10NoTau_RefGamma_etx);
  turnOnBranch(tree, "MET_Egamma10NoTau_RefGamma_ety", &MET_Egamma10NoTau_RefGamma_ety, &b_MET_Egamma10NoTau_RefGamma_ety);
  turnOnBranch(tree, "MET_Egamma10NoTau_RefGamma_sumet", &MET_Egamma10NoTau_RefGamma_sumet, &b_MET_Egamma10NoTau_RefGamma_sumet);
  turnOnBranch(tree, "RunNumber", &RunNumber, &b_RunNumber);
  turnOnBranch(tree, "averageIntPerXing", &averageIntPerXing, &b_averageIntPerXing);
  turnOnBranch(tree, "coreFlags", &coreFlags, &b_coreFlags);
  turnOnBranch(tree, "el_MET_Egamma10NoTau_statusWord", &el_MET_Egamma10NoTau_statusWord, &b_el_MET_Egamma10NoTau_statusWord);
  turnOnBranch(tree, "el_MET_Egamma10NoTau_wet", &el_MET_Egamma10NoTau_wet, &b_el_MET_Egamma10NoTau_wet);
  turnOnBranch(tree, "el_MET_Egamma10NoTau_wpx", &el_MET_Egamma10NoTau_wpx, &b_el_MET_Egamma10NoTau_wpx);
  turnOnBranch(tree, "el_MET_Egamma10NoTau_wpy", &el_MET_Egamma10NoTau_wpy, &b_el_MET_Egamma10NoTau_wpy);
  turnOnBranch(tree, "el_OQ", &el_OQ, &b_el_OQ);
  turnOnBranch(tree, "el_author", &el_author, &b_el_author);
  turnOnBranch(tree, "el_charge", &el_charge, &b_el_charge);
  turnOnBranch(tree, "el_cl_E", &el_cl_E, &b_el_cl_E);
  turnOnBranch(tree, "el_cl_eta", &el_cl_eta, &b_el_cl_eta);
  turnOnBranch(tree, "el_cl_phi", &el_cl_phi, &b_el_cl_phi);
  turnOnBranch(tree, "el_cl_pt", &el_cl_pt, &b_el_cl_pt);
  turnOnBranch(tree, "el_eta", &el_eta, &b_el_eta);
  turnOnBranch(tree, "el_phi", &el_phi, &b_el_phi);
  turnOnBranch(tree, "el_mediumPP", &el_mediumPP, &b_el_mediumPP);
  turnOnBranch(tree, "el_n", &el_n, &b_el_n);
  turnOnBranch(tree, "el_nSiHits", &el_nSiHits, &b_el_nSiHits);
  turnOnBranch(tree, "el_ptcone30", &el_ptcone30, &b_el_ptcone30);
  turnOnBranch(tree, "el_tightPP", &el_tightPP, &b_el_tightPP);
  turnOnBranch(tree, "el_topoEtcone30_corrected", &el_topoEtcone30_corrected, &b_el_topoEtcone30_corrected);
  turnOnBranch(tree, "el_trackIPEstimate_d0_unbiasedpvunbiased", &el_trackIPEstimate_d0_unbiasedpvunbiased, &b_el_trackIPEstimate_d0_unbiasedpvunbiased);
  turnOnBranch(tree, "el_trackIPEstimate_sigd0_unbiasedpvunbiased", &el_trackIPEstimate_sigd0_unbiasedpvunbiased, &b_el_trackIPEstimate_sigd0_unbiasedpvunbiased);
  turnOnBranch(tree, "el_trackIPEstimate_z0_unbiasedpvunbiased", &el_trackIPEstimate_z0_unbiasedpvunbiased, &b_el_trackIPEstimate_z0_unbiasedpvunbiased);
  turnOnBranch(tree, "el_tracketa", &el_tracketa, &b_el_tracketa);
  turnOnBranch(tree, "el_trackphi", &el_trackphi, &b_el_trackphi);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_ActiveAreaE", &jet_AntiKt4LCTopo_ActiveAreaE, &b_jet_AntiKt4LCTopo_ActiveAreaE);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_ActiveAreaPx", &jet_AntiKt4LCTopo_ActiveAreaPx, &b_jet_AntiKt4LCTopo_ActiveAreaPx);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_ActiveAreaPy", &jet_AntiKt4LCTopo_ActiveAreaPy, &b_jet_AntiKt4LCTopo_ActiveAreaPy);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_ActiveAreaPz", &jet_AntiKt4LCTopo_ActiveAreaPz, &b_jet_AntiKt4LCTopo_ActiveAreaPz);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_AverageLArQF", &jet_AntiKt4LCTopo_AverageLArQF, &b_jet_AntiKt4LCTopo_AverageLArQF);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_BCH_CORR_CELL", &jet_AntiKt4LCTopo_BCH_CORR_CELL, &b_jet_AntiKt4LCTopo_BCH_CORR_CELL);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_BCH_CORR_JET", &jet_AntiKt4LCTopo_BCH_CORR_JET, &b_jet_AntiKt4LCTopo_BCH_CORR_JET);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_HECQuality", &jet_AntiKt4LCTopo_HECQuality, &b_jet_AntiKt4LCTopo_HECQuality);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_LArQuality", &jet_AntiKt4LCTopo_LArQuality, &b_jet_AntiKt4LCTopo_LArQuality);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_MET_Egamma10NoTau_statusWord", &jet_AntiKt4LCTopo_MET_Egamma10NoTau_statusWord, &b_jet_AntiKt4LCTopo_MET_Egamma10NoTau_statusWord);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_MET_Egamma10NoTau_wet", &jet_AntiKt4LCTopo_MET_Egamma10NoTau_wet, &b_jet_AntiKt4LCTopo_MET_Egamma10NoTau_wet);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpx", &jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpx, &b_jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpx);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpy", &jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpy, &b_jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpy);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_NegativeE", &jet_AntiKt4LCTopo_NegativeE, &b_jet_AntiKt4LCTopo_NegativeE);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_SamplingMax", &jet_AntiKt4LCTopo_SamplingMax, &b_jet_AntiKt4LCTopo_SamplingMax);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_constscale_E", &jet_AntiKt4LCTopo_constscale_E, &b_jet_AntiKt4LCTopo_constscale_E);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_constscale_eta", &jet_AntiKt4LCTopo_constscale_eta, &b_jet_AntiKt4LCTopo_constscale_eta);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_constscale_m", &jet_AntiKt4LCTopo_constscale_m, &b_jet_AntiKt4LCTopo_constscale_m);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_constscale_phi", &jet_AntiKt4LCTopo_constscale_phi, &b_jet_AntiKt4LCTopo_constscale_phi);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_emfrac", &jet_AntiKt4LCTopo_emfrac, &b_jet_AntiKt4LCTopo_emfrac);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_eta", &jet_AntiKt4LCTopo_eta, &b_jet_AntiKt4LCTopo_eta);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_flavor_weight_MV1", &jet_AntiKt4LCTopo_flavor_weight_MV1, &b_jet_AntiKt4LCTopo_flavor_weight_MV1);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_fracSamplingMax", &jet_AntiKt4LCTopo_fracSamplingMax, &b_jet_AntiKt4LCTopo_fracSamplingMax);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_hecf", &jet_AntiKt4LCTopo_hecf, &b_jet_AntiKt4LCTopo_hecf);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_jvtxf", &jet_AntiKt4LCTopo_jvtxf, &b_jet_AntiKt4LCTopo_jvtxf);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_m", &jet_AntiKt4LCTopo_m, &b_jet_AntiKt4LCTopo_m);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_n", &jet_AntiKt4LCTopo_n, &b_jet_AntiKt4LCTopo_n);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_phi", &jet_AntiKt4LCTopo_phi, &b_jet_AntiKt4LCTopo_phi);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_pt", &jet_AntiKt4LCTopo_pt, &b_jet_AntiKt4LCTopo_pt);
  turnOnBranch(tree, "jet_AntiKt4LCTopo_sumPtTrk_pv0_500MeV", &jet_AntiKt4LCTopo_sumPtTrk_pv0_500MeV, &b_jet_AntiKt4LCTopo_sumPtTrk_pv0_500MeV);
  turnOnBranch(tree, "larError", &larError, &b_larError);
  turnOnBranch(tree, "lbn", &lbn, &b_lbn);
  turnOnBranch(tree, "mu_staco_charge", &mu_staco_charge, &b_mu_staco_charge);
  turnOnBranch(tree, "mu_staco_cov_qoverp_exPV", &mu_staco_cov_qoverp_exPV, &b_mu_staco_cov_qoverp_exPV);
  turnOnBranch(tree, "mu_staco_d0_exPV", &mu_staco_d0_exPV, &b_mu_staco_d0_exPV);
  turnOnBranch(tree, "mu_staco_eta", &mu_staco_eta, &b_mu_staco_eta);
  turnOnBranch(tree, "mu_staco_etcone30", &mu_staco_etcone30, &b_mu_staco_etcone30);
  turnOnBranch(tree, "mu_staco_expectBLayerHit", &mu_staco_expectBLayerHit, &b_mu_staco_expectBLayerHit);
  turnOnBranch(tree, "mu_staco_id_qoverp_exPV", &mu_staco_id_qoverp_exPV, &b_mu_staco_id_qoverp_exPV);
  turnOnBranch(tree, "mu_staco_id_theta_exPV", &mu_staco_id_theta_exPV, &b_mu_staco_id_theta_exPV);
  turnOnBranch(tree, "mu_staco_isCombinedMuon", &mu_staco_isCombinedMuon, &b_mu_staco_isCombinedMuon);
  turnOnBranch(tree, "mu_staco_isSegmentTaggedMuon", &mu_staco_isSegmentTaggedMuon, &b_mu_staco_isSegmentTaggedMuon);
  turnOnBranch(tree, "mu_staco_me_qoverp_exPV", &mu_staco_me_qoverp_exPV, &b_mu_staco_me_qoverp_exPV);
  turnOnBranch(tree, "mu_staco_me_theta_exPV", &mu_staco_me_theta_exPV, &b_mu_staco_me_theta_exPV);
  turnOnBranch(tree, "mu_staco_ms_phi", &mu_staco_ms_phi, &b_mu_staco_ms_phi);
  turnOnBranch(tree, "mu_staco_ms_qoverp", &mu_staco_ms_qoverp, &b_mu_staco_ms_qoverp);
  turnOnBranch(tree, "mu_staco_ms_theta", &mu_staco_ms_theta, &b_mu_staco_ms_theta);
  turnOnBranch(tree, "mu_staco_n", &mu_staco_n, &b_mu_staco_n);
  turnOnBranch(tree, "mu_staco_nBLHits", &mu_staco_nBLHits, &b_mu_staco_nBLHits);
  turnOnBranch(tree, "mu_staco_nPixHits", &mu_staco_nPixHits, &b_mu_staco_nPixHits);
  turnOnBranch(tree, "mu_staco_nPixHoles", &mu_staco_nPixHoles, &b_mu_staco_nPixHoles);
  turnOnBranch(tree, "mu_staco_nSCTDeadSensors", &mu_staco_nSCTDeadSensors, &b_mu_staco_nSCTDeadSensors);
  turnOnBranch(tree, "mu_staco_nSCTHits", &mu_staco_nSCTHits, &b_mu_staco_nSCTHits);
  turnOnBranch(tree, "mu_staco_nSCTHoles", &mu_staco_nSCTHoles, &b_mu_staco_nSCTHoles);
  turnOnBranch(tree, "mu_staco_nTRTHits", &mu_staco_nTRTHits, &b_mu_staco_nTRTHits);
  turnOnBranch(tree, "mu_staco_nTRTOutliers", &mu_staco_nTRTOutliers, &b_mu_staco_nTRTOutliers);
  turnOnBranch(tree, "mu_staco_phi", &mu_staco_phi, &b_mu_staco_phi);
  turnOnBranch(tree, "mu_staco_pt", &mu_staco_pt, &b_mu_staco_pt);
  turnOnBranch(tree, "mu_staco_ptcone30_trkelstyle", &mu_staco_ptcone30_trkelstyle, &b_mu_staco_ptcone30_trkelstyle);
  turnOnBranch(tree, "mu_staco_qoverp_exPV", &mu_staco_qoverp_exPV, &b_mu_staco_qoverp_exPV);
  turnOnBranch(tree, "mu_staco_trackIPEstimate_d0_unbiasedpvunbiased", &mu_staco_trackIPEstimate_d0_unbiasedpvunbiased, &b_mu_staco_trackIPEstimate_d0_unbiasedpvunbiased);
  turnOnBranch(tree, "mu_staco_trackIPEstimate_sigd0_unbiasedpvunbiased", &mu_staco_trackIPEstimate_sigd0_unbiasedpvunbiased, &b_mu_staco_trackIPEstimate_sigd0_unbiasedpvunbiased);
  turnOnBranch(tree, "mu_staco_trackIPEstimate_z0_unbiasedpvunbiased", &mu_staco_trackIPEstimate_z0_unbiasedpvunbiased, &b_mu_staco_trackIPEstimate_z0_unbiasedpvunbiased);
  turnOnBranch(tree, "mu_staco_z0_exPV", &mu_staco_z0_exPV, &b_mu_staco_z0_exPV);
  turnOnBranch(tree, "tau_EleBDTLoose", &tau_EleBDTLoose, &b_tau_EleBDTLoose);
  turnOnBranch(tree, "tau_EleBDTMedium", &tau_EleBDTMedium, &b_tau_EleBDTMedium);
  turnOnBranch(tree, "tau_EleBDTTight", &tau_EleBDTTight, &b_tau_EleBDTTight);
  turnOnBranch(tree, "tau_JetBDTSigLoose", &tau_JetBDTSigLoose, &b_tau_JetBDTSigLoose);
  turnOnBranch(tree, "tau_JetBDTSigMedium", &tau_JetBDTSigMedium, &b_tau_JetBDTSigMedium);
  turnOnBranch(tree, "tau_JetBDTSigTight", &tau_JetBDTSigTight, &b_tau_JetBDTSigTight);
  turnOnBranch(tree, "tau_charge", &tau_charge, &b_tau_charge);
  turnOnBranch(tree, "tau_eta", &tau_eta, &b_tau_eta);
  turnOnBranch(tree, "tau_m", &tau_m, &b_tau_m);
  turnOnBranch(tree, "tau_muonVeto", &tau_muonVeto, &b_tau_muonVeto);
  turnOnBranch(tree, "tau_n", &tau_n, &b_tau_n);
  turnOnBranch(tree, "tau_numTrack", &tau_numTrack, &b_tau_numTrack);
  turnOnBranch(tree, "tau_phi", &tau_phi, &b_tau_phi);
  turnOnBranch(tree, "tau_pt", &tau_pt, &b_tau_pt);
  turnOnBranch(tree, "tileError", &tileError, &b_tileError);
  turnOnBranch(tree, "trig_EF_el_E", &trig_EF_el_E, &b_trig_EF_el_E);
  turnOnBranch(tree, "trig_EF_el_EF_e12Tvh_loose1", &trig_EF_el_EF_e12Tvh_loose1, &b_trig_EF_el_EF_e12Tvh_loose1);
  turnOnBranch(tree, "trig_EF_el_EF_e12Tvh_medium1", &trig_EF_el_EF_e12Tvh_medium1, &b_trig_EF_el_EF_e12Tvh_medium1);
  turnOnBranch(tree, "trig_EF_el_EF_e24vh_medium1", &trig_EF_el_EF_e24vh_medium1, &b_trig_EF_el_EF_e24vh_medium1);
  turnOnBranch(tree, "trig_EF_el_EF_e24vh_medium1_e7_medium1", &trig_EF_el_EF_e24vh_medium1_e7_medium1, &b_trig_EF_el_EF_e24vh_medium1_e7_medium1);
  turnOnBranch(tree, "trig_EF_el_EF_e7T_medium1", &trig_EF_el_EF_e7T_medium1, &b_trig_EF_el_EF_e7T_medium1);
  turnOnBranch(tree, "trig_EF_el_px", &trig_EF_el_px, &b_trig_EF_el_px);
  turnOnBranch(tree, "trig_EF_el_py", &trig_EF_el_py, &b_trig_EF_el_py);
  turnOnBranch(tree, "trig_EF_el_pz", &trig_EF_el_pz, &b_trig_EF_el_pz);
  turnOnBranch(tree, "trig_EF_trigmuonef_EF_mu13", &trig_EF_trigmuonef_EF_mu13, &b_trig_EF_trigmuonef_EF_mu13);
  turnOnBranch(tree, "trig_EF_trigmuonef_EF_mu18_tight", &trig_EF_trigmuonef_EF_mu18_tight, &b_trig_EF_trigmuonef_EF_mu18_tight);
  turnOnBranch(tree, "trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS", &trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS, &b_trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS);
  turnOnBranch(tree, "trig_EF_trigmuonef_EF_mu8", &trig_EF_trigmuonef_EF_mu8, &b_trig_EF_trigmuonef_EF_mu8);
  turnOnBranch(tree, "trig_EF_trigmuonef_EF_mu24i_tight", &trig_EF_trigmuonef_EF_mu24i_tight, &b_trig_EF_trigmuonef_EF_mu24i_tight);
  turnOnBranch(tree, "trig_EF_trigmuonef_EF_mu36_tight", &trig_EF_trigmuonef_EF_mu36_tight, &b_trig_EF_trigmuonef_EF_mu36_tight);
  turnOnBranch(tree, "trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS", &trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS, &b_trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS);
  turnOnBranch(tree, "trig_EF_el_EF_e24vhi_medium1", &trig_EF_el_EF_e24vhi_medium1, &b_trig_EF_el_EF_e24vhi_medium1);
  turnOnBranch(tree, "trig_EF_el_EF_e60_medium1", &trig_EF_el_EF_e60_medium1, &b_trig_EF_el_EF_e60_medium1);
  turnOnBranch(tree, "trig_EF_trigmuonef_EF_mu24_tight", &trig_EF_trigmuonef_EF_mu24_tight, &b_trig_EF_trigmuonef_EF_mu24_tight);
  turnOnBranch(tree, "trig_EF_trigmuonef_track_CB_eta", &trig_EF_trigmuonef_track_CB_eta, &b_trig_EF_trigmuonef_track_CB_eta);
  turnOnBranch(tree, "trig_EF_trigmuonef_track_CB_hasCB", &trig_EF_trigmuonef_track_CB_hasCB, &b_trig_EF_trigmuonef_track_CB_hasCB);
  turnOnBranch(tree, "trig_EF_trigmuonef_track_CB_phi", &trig_EF_trigmuonef_track_CB_phi, &b_trig_EF_trigmuonef_track_CB_phi);
  turnOnBranch(tree, "trig_EF_trigmuonef_track_CB_pt", &trig_EF_trigmuonef_track_CB_pt, &b_trig_EF_trigmuonef_track_CB_pt);
  turnOnBranch(tree, "vx_E", &vx_E, &b_vx_E);
  turnOnBranch(tree, "vx_m", &vx_m, &b_vx_m);
  turnOnBranch(tree, "vx_n", &vx_n, &b_vx_n);
  turnOnBranch(tree, "vx_nTracks", &vx_nTracks, &b_vx_nTracks);
  turnOnBranch(tree, "vx_x", &vx_x, &b_vx_x);
  turnOnBranch(tree, "vx_y", &vx_y, &b_vx_y);
  turnOnBranch(tree, "vx_z", &vx_z, &b_vx_z);

  if (!m_is_data) {
    std::cout << "turning on MC only branches\n";
    turnOnBranch(tree, "el_type", &el_type, &b_el_type);
    turnOnBranch(tree, "el_origin", &el_origin, &b_el_origin);
    turnOnBranch(tree, "el_truth_barcode", &el_truth_barcode, &b_el_truth_barcode);
    turnOnBranch(tree, "el_truth_motherbarcode", &el_truth_motherbarcode, &b_el_truth_motherbarcode);
    turnOnBranch(tree, "mc_barcode", &mc_barcode, &b_mc_barcode);
    turnOnBranch(tree, "mc_channel_number", &mc_channel_number, &b_mc_channel_number);
    turnOnBranch(tree, "mc_charge", &mc_charge, &b_mc_charge);
    turnOnBranch(tree, "mc_child_index", &mc_child_index, &b_mc_child_index);
    turnOnBranch(tree, "mc_children", &mc_children, &b_mc_children);
    turnOnBranch(tree, "mc_eta", &mc_eta, &b_mc_eta);
    turnOnBranch(tree, "mc_event_weight", &mc_event_weight, &b_mc_event_weight);
    turnOnBranch(tree, "mc_m", &mc_m, &b_mc_m);
    turnOnBranch(tree, "mc_n", &mc_n, &b_mc_n);
    turnOnBranch(tree, "mc_parent_index", &mc_parent_index, &b_mc_parent_index);
    turnOnBranch(tree, "mc_parents", &mc_parents, &b_mc_parents);
    turnOnBranch(tree, "mc_pdgId", &mc_pdgId, &b_mc_pdgId);
    turnOnBranch(tree, "mc_phi", &mc_phi, &b_mc_phi);
    turnOnBranch(tree, "mc_pt", &mc_pt, &b_mc_pt);
    turnOnBranch(tree, "mc_status", &mc_status, &b_mc_status);
    turnOnBranch(tree, "mc_vx_barcode", &mc_vx_barcode, &b_mc_vx_barcode);
    turnOnBranch(tree, "mu_staco_truth_barcode", &mu_staco_truth_barcode, &b_mu_staco_truth_barcode);
    turnOnBranch(tree, "mu_staco_truth_motherbarcode", &mu_staco_truth_motherbarcode, &b_mu_staco_truth_motherbarcode);
    turnOnBranch(tree, "muonTruth_barcode", &muonTruth_barcode, &b_muonTruth_barcode);
    turnOnBranch(tree, "muonTruth_origin", &muonTruth_origin, &b_muonTruth_origin);
    turnOnBranch(tree, "muonTruth_type", &muonTruth_type, &b_muonTruth_type);
    turnOnBranch(tree, "jet_AntiKt4LCTopo_flavor_truth_label", &jet_AntiKt4LCTopo_flavor_truth_label, &b_jet_AntiKt4LCTopo_flavor_truth_label);
  }

  Notify();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::D3PDReader::ConfigureOutput( std::string out_file_name
                                               , std::string out_tree_name
                                               )
{
  std::cout << "\nD3PDReader::ConfigureOutput()\n";
  m_output_file = new TFile(out_file_name.c_str(), "RECREATE");
  m_output_tree = new TTree(out_tree_name.c_str(), out_tree_name.c_str());

  // connect branches for output
  m_output_tree->Branch( "EF_2e12Tvh_loose1", &EF_2e12Tvh_loose1);
  m_output_tree->Branch( "EF_2mu13", &EF_2mu13);
  m_output_tree->Branch( "EF_e12Tvh_medium1_mu8", &EF_e12Tvh_medium1_mu8);
  m_output_tree->Branch( "EF_e24vh_medium1_e7_medium1", &EF_e24vh_medium1_e7_medium1);
  m_output_tree->Branch( "EF_mu18_tight_e7_medium1", &EF_mu18_tight_e7_medium1);
  m_output_tree->Branch( "EF_mu18_tight_mu8_EFFS", &EF_mu18_tight_mu8_EFFS);

  m_output_tree->Branch( "EF_mu24i_tight", &EF_mu24i_tight);
  m_output_tree->Branch( "EF_mu36_tight", &EF_mu36_tight);
  m_output_tree->Branch( "EF_mu24_tight_mu6_EFFS", &EF_mu24_tight_mu6_EFFS);
  m_output_tree->Branch( "EF_e24vhi_medium1", &EF_e24vhi_medium1);
  m_output_tree->Branch( "EF_e60_medium1", &EF_e60_medium1);

  m_output_tree->Branch( "EventNumber", &EventNumber);
  m_output_tree->Branch( "Eventshape_rhoKt4LC", &Eventshape_rhoKt4LC);
  m_output_tree->Branch( "MET_Egamma10NoTau_CellOut_etx", &MET_Egamma10NoTau_CellOut_etx);
  m_output_tree->Branch( "MET_Egamma10NoTau_CellOut_ety", &MET_Egamma10NoTau_CellOut_ety);
  m_output_tree->Branch( "MET_Egamma10NoTau_CellOut_sumet", &MET_Egamma10NoTau_CellOut_sumet);
  m_output_tree->Branch( "MET_Egamma10NoTau_RefGamma_etx", &MET_Egamma10NoTau_RefGamma_etx);
  m_output_tree->Branch( "MET_Egamma10NoTau_RefGamma_ety", &MET_Egamma10NoTau_RefGamma_ety);
  m_output_tree->Branch( "MET_Egamma10NoTau_RefGamma_sumet", &MET_Egamma10NoTau_RefGamma_sumet);
  m_output_tree->Branch( "RunNumber", &RunNumber);
  m_output_tree->Branch( "averageIntPerXing", &averageIntPerXing);
  m_output_tree->Branch( "coreFlags", &coreFlags);
  m_output_tree->Branch( "el_MET_Egamma10NoTau_statusWord", &el_MET_Egamma10NoTau_statusWord);
  m_output_tree->Branch( "el_MET_Egamma10NoTau_wet", &el_MET_Egamma10NoTau_wet);
  m_output_tree->Branch( "el_MET_Egamma10NoTau_wpx", &el_MET_Egamma10NoTau_wpx);
  m_output_tree->Branch( "el_MET_Egamma10NoTau_wpy", &el_MET_Egamma10NoTau_wpy);
  m_output_tree->Branch( "el_OQ", &el_OQ);
  m_output_tree->Branch( "el_author", &el_author);
  m_output_tree->Branch( "el_charge", &el_charge);
  m_output_tree->Branch( "el_cl_E", &el_cl_E);
  m_output_tree->Branch( "el_cl_eta", &el_cl_eta);
  m_output_tree->Branch( "el_cl_phi", &el_cl_phi);
  m_output_tree->Branch( "el_cl_pt", &el_cl_pt);
  m_output_tree->Branch( "el_eta", &el_eta);
  m_output_tree->Branch( "el_phi", &el_phi);
  m_output_tree->Branch( "el_mediumPP", &el_mediumPP);
  m_output_tree->Branch( "el_n", &el_n);
  m_output_tree->Branch( "el_nSiHits", &el_nSiHits);
  m_output_tree->Branch( "el_origin", &el_origin);
  m_output_tree->Branch( "el_ptcone30", &el_ptcone30);
  m_output_tree->Branch( "el_tightPP", &el_tightPP);
  m_output_tree->Branch( "el_topoEtcone30_corrected", &el_topoEtcone30_corrected);
  m_output_tree->Branch( "el_trackIPEstimate_d0_unbiasedpvunbiased", &el_trackIPEstimate_d0_unbiasedpvunbiased);
  m_output_tree->Branch( "el_trackIPEstimate_sigd0_unbiasedpvunbiased", &el_trackIPEstimate_sigd0_unbiasedpvunbiased);
  m_output_tree->Branch( "el_trackIPEstimate_z0_unbiasedpvunbiased", &el_trackIPEstimate_z0_unbiasedpvunbiased);
  m_output_tree->Branch( "el_tracketa", &el_tracketa);
  m_output_tree->Branch( "el_trackphi", &el_trackphi);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_ActiveAreaE", &jet_AntiKt4LCTopo_ActiveAreaE);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_ActiveAreaPx", &jet_AntiKt4LCTopo_ActiveAreaPx);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_ActiveAreaPy", &jet_AntiKt4LCTopo_ActiveAreaPy);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_ActiveAreaPz", &jet_AntiKt4LCTopo_ActiveAreaPz);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_AverageLArQF", &jet_AntiKt4LCTopo_AverageLArQF);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_BCH_CORR_CELL", &jet_AntiKt4LCTopo_BCH_CORR_CELL);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_BCH_CORR_JET", &jet_AntiKt4LCTopo_BCH_CORR_JET);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_HECQuality", &jet_AntiKt4LCTopo_HECQuality);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_LArQuality", &jet_AntiKt4LCTopo_LArQuality);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_MET_Egamma10NoTau_statusWord", &jet_AntiKt4LCTopo_MET_Egamma10NoTau_statusWord);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_MET_Egamma10NoTau_wet", &jet_AntiKt4LCTopo_MET_Egamma10NoTau_wet);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpx", &jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpx);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpy", &jet_AntiKt4LCTopo_MET_Egamma10NoTau_wpy);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_NegativeE", &jet_AntiKt4LCTopo_NegativeE);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_SamplingMax", &jet_AntiKt4LCTopo_SamplingMax);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_constscale_E", &jet_AntiKt4LCTopo_constscale_E);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_constscale_eta", &jet_AntiKt4LCTopo_constscale_eta);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_constscale_m", &jet_AntiKt4LCTopo_constscale_m);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_constscale_phi", &jet_AntiKt4LCTopo_constscale_phi);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_emfrac", &jet_AntiKt4LCTopo_emfrac);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_eta", &jet_AntiKt4LCTopo_eta);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_flavor_weight_MV1", &jet_AntiKt4LCTopo_flavor_weight_MV1);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_fracSamplingMax", &jet_AntiKt4LCTopo_fracSamplingMax);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_hecf", &jet_AntiKt4LCTopo_hecf);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_jvtxf", &jet_AntiKt4LCTopo_jvtxf);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_m", &jet_AntiKt4LCTopo_m);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_n", &jet_AntiKt4LCTopo_n);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_phi", &jet_AntiKt4LCTopo_phi);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_pt", &jet_AntiKt4LCTopo_pt);
  m_output_tree->Branch( "jet_AntiKt4LCTopo_sumPtTrk_pv0_500MeV", &jet_AntiKt4LCTopo_sumPtTrk_pv0_500MeV);
  m_output_tree->Branch( "larError", &larError);
  m_output_tree->Branch( "lbn", &lbn);
  m_output_tree->Branch( "mu_staco_charge", &mu_staco_charge);
  m_output_tree->Branch( "mu_staco_cov_qoverp_exPV", &mu_staco_cov_qoverp_exPV);
  m_output_tree->Branch( "mu_staco_d0_exPV", &mu_staco_d0_exPV);
  m_output_tree->Branch( "mu_staco_eta", &mu_staco_eta);
  m_output_tree->Branch( "mu_staco_etcone30", &mu_staco_etcone30);
  m_output_tree->Branch( "mu_staco_expectBLayerHit", &mu_staco_expectBLayerHit);
  m_output_tree->Branch( "mu_staco_id_qoverp_exPV", &mu_staco_id_qoverp_exPV);
  m_output_tree->Branch( "mu_staco_id_theta_exPV", &mu_staco_id_theta_exPV);
  m_output_tree->Branch( "mu_staco_isCombinedMuon", &mu_staco_isCombinedMuon);
  m_output_tree->Branch( "mu_staco_isSegmentTaggedMuon", &mu_staco_isSegmentTaggedMuon);
  m_output_tree->Branch( "mu_staco_me_qoverp_exPV", &mu_staco_me_qoverp_exPV);
  m_output_tree->Branch( "mu_staco_me_theta_exPV", &mu_staco_me_theta_exPV);
  m_output_tree->Branch( "mu_staco_ms_phi", &mu_staco_ms_phi);
  m_output_tree->Branch( "mu_staco_ms_qoverp", &mu_staco_ms_qoverp);
  m_output_tree->Branch( "mu_staco_ms_theta", &mu_staco_ms_theta);
  m_output_tree->Branch( "mu_staco_n", &mu_staco_n);
  m_output_tree->Branch( "mu_staco_nBLHits", &mu_staco_nBLHits);
  m_output_tree->Branch( "mu_staco_nPixHits", &mu_staco_nPixHits);
  m_output_tree->Branch( "mu_staco_nPixHoles", &mu_staco_nPixHoles);
  m_output_tree->Branch( "mu_staco_nSCTDeadSensors", &mu_staco_nSCTDeadSensors);
  m_output_tree->Branch( "mu_staco_nSCTHits", &mu_staco_nSCTHits);
  m_output_tree->Branch( "mu_staco_nSCTHoles", &mu_staco_nSCTHoles);
  m_output_tree->Branch( "mu_staco_nTRTHits", &mu_staco_nTRTHits);
  m_output_tree->Branch( "mu_staco_nTRTOutliers", &mu_staco_nTRTOutliers);
  m_output_tree->Branch( "mu_staco_phi", &mu_staco_phi);
  m_output_tree->Branch( "mu_staco_pt", &mu_staco_pt);
  m_output_tree->Branch( "mu_staco_ptcone30_trkelstyle", &mu_staco_ptcone30_trkelstyle);
  m_output_tree->Branch( "mu_staco_qoverp_exPV", &mu_staco_qoverp_exPV);
  m_output_tree->Branch( "mu_staco_trackIPEstimate_d0_unbiasedpvunbiased", &mu_staco_trackIPEstimate_d0_unbiasedpvunbiased);
  m_output_tree->Branch( "mu_staco_trackIPEstimate_sigd0_unbiasedpvunbiased", &mu_staco_trackIPEstimate_sigd0_unbiasedpvunbiased);
  m_output_tree->Branch( "mu_staco_trackIPEstimate_z0_unbiasedpvunbiased", &mu_staco_trackIPEstimate_z0_unbiasedpvunbiased);
  m_output_tree->Branch( "mu_staco_z0_exPV", &mu_staco_z0_exPV);
  m_output_tree->Branch( "tau_EleBDTLoose", &tau_EleBDTLoose);
  m_output_tree->Branch( "tau_EleBDTMedium", &tau_EleBDTMedium);
  m_output_tree->Branch( "tau_EleBDTTight", &tau_EleBDTTight);
  m_output_tree->Branch( "tau_JetBDTSigLoose", &tau_JetBDTSigLoose);
  m_output_tree->Branch( "tau_JetBDTSigMedium", &tau_JetBDTSigMedium);
  m_output_tree->Branch( "tau_JetBDTSigTight", &tau_JetBDTSigTight);
  m_output_tree->Branch( "tau_charge", &tau_charge);
  m_output_tree->Branch( "tau_eta", &tau_eta);
  m_output_tree->Branch( "tau_m", &tau_m);
  m_output_tree->Branch( "tau_muonVeto", &tau_muonVeto);
  m_output_tree->Branch( "tau_n", &tau_n);
  m_output_tree->Branch( "tau_numTrack", &tau_numTrack);
  m_output_tree->Branch( "tau_phi", &tau_phi);
  m_output_tree->Branch( "tau_pt", &tau_pt);
  m_output_tree->Branch( "tileError", &tileError);
  m_output_tree->Branch( "trig_EF_el_E", &trig_EF_el_E);
  m_output_tree->Branch( "trig_EF_el_EF_e12Tvh_loose1", &trig_EF_el_EF_e12Tvh_loose1);
  m_output_tree->Branch( "trig_EF_el_EF_e12Tvh_medium1", &trig_EF_el_EF_e12Tvh_medium1);
  m_output_tree->Branch( "trig_EF_el_EF_e24vh_medium1", &trig_EF_el_EF_e24vh_medium1);
  m_output_tree->Branch( "trig_EF_el_EF_e24vh_medium1_e7_medium1", &trig_EF_el_EF_e24vh_medium1_e7_medium1);
  m_output_tree->Branch( "trig_EF_el_EF_e7T_medium1", &trig_EF_el_EF_e7T_medium1);
  m_output_tree->Branch( "trig_EF_el_px", &trig_EF_el_px);
  m_output_tree->Branch( "trig_EF_el_py", &trig_EF_el_py);
  m_output_tree->Branch( "trig_EF_el_pz", &trig_EF_el_pz);
  m_output_tree->Branch( "trig_EF_trigmuonef_EF_mu13", &trig_EF_trigmuonef_EF_mu13);
  m_output_tree->Branch( "trig_EF_trigmuonef_EF_mu18_tight", &trig_EF_trigmuonef_EF_mu18_tight);
  m_output_tree->Branch( "trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS", &trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS);
  m_output_tree->Branch( "trig_EF_trigmuonef_EF_mu8", &trig_EF_trigmuonef_EF_mu8);
  m_output_tree->Branch( "trig_EF_trigmuonef_EF_mu24i_tight", &trig_EF_trigmuonef_EF_mu24i_tight);
  m_output_tree->Branch( "trig_EF_trigmuonef_EF_mu36_tight", &trig_EF_trigmuonef_EF_mu36_tight);
  m_output_tree->Branch( "trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS", &trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS);
  m_output_tree->Branch( "trig_EF_el_EF_e24vhi_medium1", &trig_EF_el_EF_e24vhi_medium1);
  m_output_tree->Branch( "trig_EF_el_EF_e60_medium1", &trig_EF_el_EF_e60_medium1);
  m_output_tree->Branch( "trig_EF_trigmuonef_EF_mu24_tight", &trig_EF_trigmuonef_EF_mu24_tight);
  m_output_tree->Branch( "trig_EF_trigmuonef_track_CB_eta", &trig_EF_trigmuonef_track_CB_eta);
  m_output_tree->Branch( "trig_EF_trigmuonef_track_CB_hasCB", &trig_EF_trigmuonef_track_CB_hasCB);
  m_output_tree->Branch( "trig_EF_trigmuonef_track_CB_phi", &trig_EF_trigmuonef_track_CB_phi);
  m_output_tree->Branch( "trig_EF_trigmuonef_track_CB_pt", &trig_EF_trigmuonef_track_CB_pt);
  m_output_tree->Branch( "vx_E", &vx_E);
  m_output_tree->Branch( "vx_m", &vx_m);
  m_output_tree->Branch( "vx_n", &vx_n);
  m_output_tree->Branch( "vx_nTracks", &vx_nTracks);
  m_output_tree->Branch( "vx_x", &vx_x);
  m_output_tree->Branch( "vx_y", &vx_y);
  m_output_tree->Branch( "vx_z", &vx_z);

  if (!m_is_data) {
    std::cout << "connecting on MC only branches to output\n";
    m_output_tree->Branch( "el_origin", &el_origin);
    m_output_tree->Branch( "el_type", &el_type);
    m_output_tree->Branch( "el_truth_barcode", &el_truth_barcode);
    m_output_tree->Branch( "el_truth_motherbarcode", &el_truth_motherbarcode);
    m_output_tree->Branch( "mc_barcode", &mc_barcode);
    m_output_tree->Branch( "mc_channel_number", &mc_channel_number);
    m_output_tree->Branch( "mc_charge", &mc_charge);
    m_output_tree->Branch( "mc_child_index", &mc_child_index);
    m_output_tree->Branch( "mc_children", &mc_children);
    m_output_tree->Branch( "mc_eta", &mc_eta);
    m_output_tree->Branch( "mc_event_weight", &mc_event_weight);
    m_output_tree->Branch( "mc_m", &mc_m);
    m_output_tree->Branch( "mc_n", &mc_n);
    m_output_tree->Branch( "mc_parent_index", &mc_parent_index);
    m_output_tree->Branch( "mc_parents", &mc_parents);
    m_output_tree->Branch( "mc_pdgId", &mc_pdgId);
    m_output_tree->Branch( "mc_phi", &mc_phi);
    m_output_tree->Branch( "mc_pt", &mc_pt);
    m_output_tree->Branch( "mc_status", &mc_status);
    m_output_tree->Branch( "mc_vx_barcode", &mc_vx_barcode);
    m_output_tree->Branch( "mu_staco_truth_barcode", &mu_staco_truth_barcode);
    m_output_tree->Branch( "mu_staco_truth_motherbarcode", &mu_staco_truth_motherbarcode);
    m_output_tree->Branch( "muonTruth_barcode", &muonTruth_barcode);
    m_output_tree->Branch( "muonTruth_origin", &muonTruth_origin);
    m_output_tree->Branch( "muonTruth_type", &muonTruth_type);
    m_output_tree->Branch( "jet_AntiKt4LCTopo_flavor_truth_label", &jet_AntiKt4LCTopo_flavor_truth_label);
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::D3PDReader::FillEvent()
{
  m_output_tree->Fill();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::D3PDReader::FinalizeOutput( int   num_generated_events
                                              , float sum_mc_event_weights
                                              )
{
  m_output_tree->Write();

  writeNumEvents(num_generated_events, sum_mc_event_weights);
  // TVectorF num_events(1);
  // num_events[0] = getNumEvents();
  // num_events.Write("TotalNumEvents");

  m_output_file->Write();
  m_output_file->Close();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::D3PDReader::writeNumEvents( int   num_generated_events
                                              , float sum_mc_event_weights
                                              )
{
  TVectorF num_events(1);
  if (num_generated_events < 0) num_events[0] = getNumEvents();
  else                          num_events[0] = num_generated_events;
  num_events.Write("TotalNumEvents");

  TVectorF sum_weights(1);
  if (sum_mc_event_weights < 0) sum_weights[0] = num_events[0];
  else                          sum_weights[0] = sum_mc_event_weights;
  sum_weights.Write("SumMCEventWeights");
  std::cout << "writeNumEvents()"
            << "\n\t -- num events passed: " << num_generated_events << " -- num events written: " << num_events[0]
            << "\n\t -- sum mc event weihts: " << sum_mc_event_weights << " -- sum mc event weights: " << sum_weights[0]
            << "\n";
}

// -----------------------------------------------------------------------------
Bool_t PennSusyFrame::D3PDReader::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.

  return kTRUE;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::D3PDReader::Show(Long64_t entry)
{
  // Print contents of entry.
  // If entry is not specified, print current entry
  if (!fChain) return;
  fChain->Show(entry);
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::D3PDReader::checkStatus()
{
  std::cout << "checkStatus()\n";
  if (fChain == 0) {
    std::cout << "Chain is empty - cannot loop over events :-(\n";
    return false;
  }
  return true;
}

// -----------------------------------------------------------------------------
unsigned int PennSusyFrame::D3PDReader::getNumEvents()
{
  std::cout << "getNumEvents()\n";
  return fChain->GetEntries();
}
