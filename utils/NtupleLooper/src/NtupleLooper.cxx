#include "NtupleLooper/include/NtupleLooper.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <dirent.h>
#include <math.h>
#include <algorithm>

#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>

#include "SusyAnalysisTools/include/ElectronDescription.h"
#include "SusyAnalysisTools/include/MuonDescription.h"

#include "ProgressBar/include/ProgressBar.h"

// -----------------------------------------------------------------------------
NtupleHelper::NtupleLooper::NtupleLooper(TTree *tree, double events) : fChain(0)
                                                       , m_num_events(events)
{
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.
  if (tree == 0) {
    std::cout << "input tree not found\n";
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("SusyDiLeptonCutFlowCycle.MC.egamma.2012_10_15.1.ttbar_small_cutflow_challenge.root");
    if (!f || !f->IsOpen()) {
      f = new TFile("SusyDiLeptonCutFlowCycle.MC.egamma.2012_10_15.1.ttbar_small_cutflow_challenge.root");
    }
    f->GetObject("output",tree);
  }

  Init(tree);
}

// -----------------------------------------------------------------------------
NtupleHelper::NtupleLooper::~NtupleLooper()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

// -----------------------------------------------------------------------------
Int_t NtupleHelper::NtupleLooper::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}

// -----------------------------------------------------------------------------
Long64_t NtupleHelper::NtupleLooper::LoadTree(Long64_t entry)
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
void NtupleHelper::NtupleLooper::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

  std::cout << "Init our input tree\n";
   m_lbn = 0;
   m_run_number = 0;
   m_event_number = 0;
   m_event_desc = 0;
   m_sr_helper = 0;
   m_mc_event_weight = 0;
   m_pile_up_weight = 0;
   m_trigger_weight = 0;
   m_lepton_weight = 0;
   m_b_tag_weight = 0;
   m_cross_section_weight = 0;
   m_k_factor = 0;
   m_eff_times_cross_section = 0;
   m_fake_weight_nom = 0;
   m_fake_weight_max = 0;
   m_fake_weight_min = 0;
   m_charge_flip_weight = 0;
   m_charge_flip_weight_max = 0;
   m_charge_flip_weight_min = 0;
   m_mc_channel_number = 0;
   m_actual_int_per_crossing = 0;
   m_average_int_per_crossing = 0;
   m_mll = 0;
   m_ptll = 0;
   m_mt2 = 0;
   m_el_E = 0;
   m_el_Et = 0;
   m_el_pt = 0;
   m_el_eta = 0;
   m_el_eta_cl = 0;
   m_el_eta_track = 0;
   m_el_phi = 0;
   m_el_phi_cl = 0;
   m_el_phi_track = 0;
   m_el_d0 = 0;
   m_el_d0_physics = 0;
   m_el_d0_pv = 0;
   m_el_z0 = 0;
   m_el_z0_pv = 0;
   m_el_d0_pv_sig = 0;
   m_el_z0_pv_sig = 0;
   m_el_d0_sig = 0;
   m_el_z0_sin_theta = 0;
   m_el_charge = 0;
   m_el_desc = 0;
   m_el_cf_smeared_pt = 0;
   m_el_etcone20 = 0;
   m_el_etcone30 = 0;
   m_el_etcone40 = 0;
   m_el_ptcone20 = 0;
   m_el_ptcone30 = 0;
   m_el_ptcone40 = 0;
   m_el_topoetcone20 = 0;
   m_el_topoetcone30 = 0;
   m_el_topoetcone40 = 0;
   m_el_topoetcone20_corrected = 0;
   m_el_topoetcone30_corrected = 0;
   m_el_topoetcone40_corrected = 0;
   m_el_raw_topoetcone20_corrected = 0;
   m_el_raw_topoetcone30_corrected = 0;
   m_el_raw_topoetcone40_corrected = 0;
   m_el_truth_charge = 0;
   m_mu_pt = 0;
   m_mu_eta = 0;
   m_mu_phi = 0;
   m_mu_cov_d0 = 0;
   m_mu_d0 = 0;
   m_mu_z0 = 0;
   m_mu_d0_sig = 0;
   m_mu_z0_sin_theta = 0;
   m_mu_charge = 0;
   m_mu_etcone20 = 0;
   m_mu_etcone30 = 0;
   m_mu_etcone40 = 0;
   m_mu_raw_etcone20 = 0;
   m_mu_raw_etcone30 = 0;
   m_mu_raw_etcone40 = 0;
   m_mu_ptcone20 = 0;
   m_mu_ptcone30 = 0;
   m_mu_ptcone40 = 0;
   m_mu_ptcone20_trkelstyle = 0;
   m_mu_ptcone30_trkelstyle = 0;
   m_mu_ptcone40_trkelstyle = 0;
   m_mu_desc = 0;
   m_jet_pt = 0;
   m_jet_eta = 0;
   m_jet_phi = 0;
   m_jet_bjet_mv1 = 0;
   m_jet_dr_signal_lep = 0;
   m_jet_jvf = 0;
   m_jet_desc = 0;
   m_met_et = 0;
   m_met_rel_et = 0;
   m_met_rel_delta_phi = 0;
   m_met_phi = 0;
   m_met_sumet = 0;
   m_vtx_n = 0;
   m_vtx_x = 0;
   m_vtx_y = 0;
   m_vtx_z = 0;
   m_vtx_n_tracks = 0;
   m_vtx_sum_pt = 0;


   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   // fChain->SetMakeClass(1);

   // int branch_num = 0;
   fChain->SetBranchAddress( "lbn"
                           , &m_lbn
                           , &b_lbn
                           );
   fChain->SetBranchAddress( "run_number"
                           , &m_run_number
                           , &b_run_number
                           );
   fChain->SetBranchAddress( "event_number"
                           , &m_event_number
                           , &b_event_number
                           );
   fChain->SetBranchAddress( "event_desc"
                           , &m_event_desc
                           , &b_event_desc
                           );
   fChain->SetBranchAddress( "sr_helper"
                           , &m_sr_helper
                           , &b_sr_helper
                           );
   fChain->SetBranchAddress( "mc_event_weight"
                           , &m_mc_event_weight
                           , &b_mc_event_weight
                           );
   fChain->SetBranchAddress( "pile_up_weight"
                           , &m_pile_up_weight
                           , &b_pile_up_weight
                           );
   fChain->SetBranchAddress( "trigger_weight"
                           , &m_trigger_weight
                           , &b_trigger_weight
                           );
   fChain->SetBranchAddress( "lepton_weight"
                           , &m_lepton_weight
                           , &b_lepton_weight
                           );
   fChain->SetBranchAddress( "b_tag_weight"
                           , &m_b_tag_weight
                           , &b_b_tag_weight
                           );
   fChain->SetBranchAddress( "cross_section_weight"
                           , &m_cross_section_weight
                           , &b_cross_section_weight
                           );
   fChain->SetBranchAddress( "k_factor"
                           , &m_k_factor
                           , &b_k_factor
                           );
   fChain->SetBranchAddress( "eff_times_cross_section"
                           , &m_eff_times_cross_section
                           , &b_eff_times_cross_section
                           );
   fChain->SetBranchAddress( "fake_weight_nom"
                           , &m_fake_weight_nom
                           , &b_fake_weight_nom
                           );
   fChain->SetBranchAddress( "fake_weight_max"
                           , &m_fake_weight_max
                           , &b_fake_weight_max
                           );
   fChain->SetBranchAddress( "fake_weight_min"
                           , &m_fake_weight_min
                           , &b_fake_weight_min
                           );
   fChain->SetBranchAddress( "charge_flip_weight"
                           , &m_charge_flip_weight
                           , &b_charge_flip_weight
                           );
   fChain->SetBranchAddress( "charge_flip_weight_max"
                           , &m_charge_flip_weight_max
                           , &b_charge_flip_weight_max
                           );
   fChain->SetBranchAddress( "charge_flip_weight_min"
                           , &m_charge_flip_weight_min
                           , &b_charge_flip_weight_min
                           );
   fChain->SetBranchAddress( "mc_channel_number"
                           , &m_mc_channel_number
                           , &b_mc_channel_number
                           );
   fChain->SetBranchAddress( "actual_int_per_crossing"
                           , &m_actual_int_per_crossing
                           , &b_actual_int_per_crossing
                           );
   fChain->SetBranchAddress( "average_int_per_crossing"
                           , &m_average_int_per_crossing
                           , &b_average_int_per_crossing
                           );
   fChain->SetBranchAddress( "mll"
                           , &m_mll
                           , &b_mll
                           );
   fChain->SetBranchAddress( "ptll"
                           , &m_ptll
                           , &b_ptll
                           );
   fChain->SetBranchAddress( "mt2"
                           , &m_mt2
                           , &b_mt2
                           );
   fChain->SetBranchAddress( "el_E"
                           , &m_el_E
                           , &b_el_E
                           );
   fChain->SetBranchAddress( "el_Et"
                           , &m_el_Et
                           , &b_el_Et
                           );
   fChain->SetBranchAddress( "el_pt"
                           , &m_el_pt
                           , &b_el_pt
                           );
   fChain->SetBranchAddress( "el_eta"
                           , &m_el_eta
                           , &b_el_eta
                           );
   fChain->SetBranchAddress( "el_eta_cl"
                           , &m_el_eta_cl
                           , &b_el_eta_cl
                           );
   fChain->SetBranchAddress( "el_eta_track"
                           , &m_el_eta_track
                           , &b_el_eta_track
                           );
   fChain->SetBranchAddress( "el_phi"
                           , &m_el_phi
                           , &b_el_phi
                           );
   fChain->SetBranchAddress( "el_phi_cl"
                           , &m_el_phi_cl
                           , &b_el_phi_cl
                           );
   fChain->SetBranchAddress( "el_phi_track"
                           , &m_el_phi_track
                           , &b_el_phi_track
                           );
   fChain->SetBranchAddress( "el_d0"
                           , &m_el_d0
                           , &b_el_d0
                           );
   fChain->SetBranchAddress( "el_d0_physics"
                           , &m_el_d0_physics
                           , &b_el_d0_physics
                           );
   fChain->SetBranchAddress( "el_d0_pv"
                           , &m_el_d0_pv
                           , &b_el_d0_pv
                           );
   fChain->SetBranchAddress( "el_z0"
                           , &m_el_z0
                           , &b_el_z0
                           );
   fChain->SetBranchAddress( "el_z0_pv"
                           , &m_el_z0_pv
                           , &b_el_z0_pv
                           );
   fChain->SetBranchAddress( "el_d0_pv_sig"
                           , &m_el_d0_pv_sig
                           , &b_el_d0_pv_sig
                           );
   fChain->SetBranchAddress( "el_z0_pv_sig"
                           , &m_el_z0_pv_sig
                           , &b_el_z0_pv_sig
                           );
   fChain->SetBranchAddress( "el_d0_sig"
                           , &m_el_d0_sig
                           , &b_el_d0_sig
                           );
   fChain->SetBranchAddress( "el_z0_sin_theta"
                           , &m_el_z0_sin_theta
                           , &b_el_z0_sin_theta
                           );
   fChain->SetBranchAddress( "el_charge"
                           , &m_el_charge
                           , &b_el_charge
                           );
   fChain->SetBranchAddress( "el_desc"
                           , &m_el_desc
                           , &b_el_desc
                           );
   fChain->SetBranchAddress( "el_cf_smeared_pt"
                           , &m_el_cf_smeared_pt
                           , &b_el_cf_smeared_pt
                           );
   fChain->SetBranchAddress( "el_etcone20"
                           , &m_el_etcone20
                           , &b_el_etcone20
                           );
   fChain->SetBranchAddress( "el_etcone30"
                           , &m_el_etcone30
                           , &b_el_etcone30
                           );
   fChain->SetBranchAddress( "el_etcone40"
                           , &m_el_etcone40
                           , &b_el_etcone40
                           );
   fChain->SetBranchAddress( "el_ptcone20"
                           , &m_el_ptcone20
                           , &b_el_ptcone20
                           );
   fChain->SetBranchAddress( "el_ptcone30"
                           , &m_el_ptcone30
                           , &b_el_ptcone30
                           );
   fChain->SetBranchAddress( "el_ptcone40"
                           , &m_el_ptcone40
                           , &b_el_ptcone40
                           );
   fChain->SetBranchAddress( "el_topoetcone20"
                           , &m_el_topoetcone20
                           , &b_el_topoetcone20
                           );
   fChain->SetBranchAddress( "el_topoetcone30"
                           , &m_el_topoetcone30
                           , &b_el_topoetcone30
                           );
   fChain->SetBranchAddress( "el_topoetcone40"
                           , &m_el_topoetcone40
                           , &b_el_topoetcone40
                           );
   fChain->SetBranchAddress( "el_topoetcone20_corrected"
                           , &m_el_topoetcone20_corrected
                           , &b_el_topoetcone20_corrected
                           );
   fChain->SetBranchAddress( "el_topoetcone30_corrected"
                           , &m_el_topoetcone30_corrected
                           , &b_el_topoetcone30_corrected
                           );
   fChain->SetBranchAddress( "el_topoetcone40_corrected"
                           , &m_el_topoetcone40_corrected
                           , &b_el_topoetcone40_corrected
                           );
   fChain->SetBranchAddress( "el_raw_topoetcone20_corrected"
                           , &m_el_raw_topoetcone20_corrected
                           , &b_el_raw_topoetcone20_corrected
                           );
   fChain->SetBranchAddress( "el_raw_topoetcone30_corrected"
                           , &m_el_raw_topoetcone30_corrected
                           , &b_el_raw_topoetcone30_corrected
                           );
   fChain->SetBranchAddress( "el_raw_topoetcone40_corrected"
                           , &m_el_raw_topoetcone40_corrected
                           , &b_el_raw_topoetcone40_corrected
                           );
   fChain->SetBranchAddress( "el_truth_charge"
                           , &m_el_truth_charge
                           , &b_el_truth_charge
                           );
   fChain->SetBranchAddress( "mu_pt"
                           , &m_mu_pt
                           , &b_mu_pt
                           );
   fChain->SetBranchAddress( "mu_eta"
                           , &m_mu_eta
                           , &b_mu_eta
                           );
   fChain->SetBranchAddress( "mu_phi"
                           , &m_mu_phi
                           , &b_mu_phi
                           );
   fChain->SetBranchAddress( "mu_cov_d0"
                           , &m_mu_cov_d0
                           , &b_mu_cov_d0
                           );
   fChain->SetBranchAddress( "mu_d0"
                           , &m_mu_d0
                           , &b_mu_d0
                           );
   fChain->SetBranchAddress( "mu_z0"
                           , &m_mu_z0
                           , &b_mu_z0
                           );
   fChain->SetBranchAddress( "mu_d0_sig"
                           , &m_mu_d0_sig
                           , &b_mu_d0_sig
                           );
   fChain->SetBranchAddress( "mu_z0_sin_theta"
                           , &m_mu_z0_sin_theta
                           , &b_mu_z0_sin_theta
                           );
   fChain->SetBranchAddress( "mu_charge"
                           , &m_mu_charge
                           , &b_mu_charge
                           );
   fChain->SetBranchAddress( "mu_etcone20"
                           , &m_mu_etcone20
                           , &b_mu_etcone20
                           );
   fChain->SetBranchAddress( "mu_etcone30"
                           , &m_mu_etcone30
                           , &b_mu_etcone30
                           );
   fChain->SetBranchAddress( "mu_etcone40"
                           , &m_mu_etcone40
                           , &b_mu_etcone40
                           );
   fChain->SetBranchAddress( "mu_raw_etcone20"
                           , &m_mu_raw_etcone20
                           , &b_mu_raw_etcone20
                           );
   fChain->SetBranchAddress( "mu_raw_etcone30"
                           , &m_mu_raw_etcone30
                           , &b_mu_raw_etcone30
                           );
   fChain->SetBranchAddress( "mu_raw_etcone40"
                           , &m_mu_raw_etcone40
                           , &b_mu_raw_etcone40
                           );
   fChain->SetBranchAddress( "mu_ptcone20"
                           , &m_mu_ptcone20
                           , &b_mu_ptcone20
                           );
   fChain->SetBranchAddress( "mu_ptcone30"
                           , &m_mu_ptcone30
                           , &b_mu_ptcone30
                           );
   fChain->SetBranchAddress( "mu_ptcone40"
                           , &m_mu_ptcone40
                           , &b_mu_ptcone40
                           );
   fChain->SetBranchAddress( "mu_ptcone20_trkelstyle"
                           , &m_mu_ptcone20_trkelstyle
                           , &b_mu_ptcone20_trkelstyle
                           );
   fChain->SetBranchAddress( "mu_ptcone30_trkelstyle"
                           , &m_mu_ptcone30_trkelstyle
                           , &b_mu_ptcone30_trkelstyle
                           );
   fChain->SetBranchAddress( "mu_ptcone40_trkelstyle"
                           , &m_mu_ptcone40_trkelstyle
                           , &b_mu_ptcone40_trkelstyle
                           );
   fChain->SetBranchAddress( "mu_desc"
                           , &m_mu_desc
                           , &b_mu_desc
                           );
   fChain->SetBranchAddress( "jet_pt"
                           , &m_jet_pt
                           , &b_jet_pt
                           );
   fChain->SetBranchAddress( "jet_eta"
                           , &m_jet_eta
                           , &b_jet_eta
                           );
   fChain->SetBranchAddress( "jet_phi"
                           , &m_jet_phi
                           , &b_jet_phi
                           );
   fChain->SetBranchAddress( "jet_bjet_mv1"
                           , &m_jet_bjet_mv1
                           , &b_jet_bjet_mv1
                           );
   fChain->SetBranchAddress( "jet_dr_signal_lep"
                           , &m_jet_dr_signal_lep
                           , &b_jet_dr_signal_lep
                           );
   fChain->SetBranchAddress( "jet_jvf"
                           , &m_jet_jvf
                           , &b_jet_jvf
                           );
   fChain->SetBranchAddress( "jet_desc"
                           , &m_jet_desc
                           , &b_jet_desc
                           );
   fChain->SetBranchAddress( "met_et"
                           , &m_met_et
                           , &b_met_et
                           );
   fChain->SetBranchAddress( "met_rel_et"
                           , &m_met_rel_et
                           , &b_met_rel_et
                           );
   fChain->SetBranchAddress( "met_rel_delta_phi"
                           , &m_met_rel_delta_phi
                           , &b_met_rel_delta_phi
                           );
   fChain->SetBranchAddress( "met_phi"
                           , &m_met_phi
                           , &b_met_phi
                           );
   fChain->SetBranchAddress( "met_sumet"
                           , &m_met_sumet
                           , &b_met_sumet
                           );
   fChain->SetBranchAddress( "vtx_n"
                           , &m_vtx_n
                           , &b_vtx_n
                           );
   fChain->SetBranchAddress( "vtx_x"
                           , &m_vtx_x
                           , &b_vtx_x
                           );
   fChain->SetBranchAddress( "vtx_y"
                           , &m_vtx_y
                           , &b_vtx_y
                           );
   fChain->SetBranchAddress( "vtx_z"
                           , &m_vtx_z
                           , &b_vtx_z
                           );
   fChain->SetBranchAddress( "vtx_n_tracks"
                           , &m_vtx_n_tracks
                           , &b_vtx_n_tracks
                           );
   fChain->SetBranchAddress( "vtx_sum_pt"
                           , &m_vtx_sum_pt
                           , &b_vtx_sum_pt
                           );

   Notify();
}

// -----------------------------------------------------------------------------
Bool_t NtupleHelper::NtupleLooper::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

// -----------------------------------------------------------------------------
void NtupleHelper::NtupleLooper::Loop()
{
  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntries();
  std::cout << "number evens: " << nentries << "\n";

  ProgressBar progress_bar(nentries, 100);

  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry = 0; jentry != nentries; ++jentry) {
    progress_bar.checkProgress(jentry);

    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);
    nbytes += nb;

    processEvent();
  }
}

// -----------------------------------------------------------------------------
void NtupleHelper::NtupleLooper::processEvent()
{
  // if (m_event_number % 10 == 0)
  //   std::cout << "event: " << m_event_number
  //             << " -- mll: " << m_mll << " MeV"
  //             << "\n";
}

// -----------------------------------------------------------------------------
bool NtupleHelper::NtupleLooper::isSignalElectron( const size_t el_index
                                   , const SusyAnalysisTools::ElectronDescription& el_desc
                                   , bool use_default_decision
                                   , NtupleHelper::ISO_STYLE iso_type
                                   , float /* d0_sig_cut */
                                   )
{
  bool is_signal_electron_cutflow = el_desc.getPassSignal();
  if (use_default_decision) return is_signal_electron_cutflow;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  double pt = m_el_pt->at(el_index)/1.e3;
  double eta = m_el_eta_cl->at(el_index);
  double d0_sig = m_el_d0_sig->at(el_index);
  double z0_sin_theta = m_el_z0_sin_theta->at(el_index);

  double et_iso = -999;
  double pt_iso = -999;
  double et_iso_frac = -999;
  double pt_iso_frac = -999;

  if (iso_type == NtupleHelper::EWK_STYLE) {
    et_iso = getElIsoCorr( el_index
                         , NtupleHelper::TOPOETCONE
                         , NtupleHelper::CONE_30
                         )/1.e3;
    pt_iso = getElIsoCorr( el_index
                         , NtupleHelper::PTCONE
                         , NtupleHelper::CONE_30
                         )/1.e3;
    // double et_iso_d3pd = m_el_topoetcone30_corrected->at(el_index)/1.e3;
    // double pt_iso_d3pd = m_el_ptcone30->at(el_index)/1.e3;

    // if (int(1.e3*et_iso) != int(1.e3*et_iso_d3pd))
    //   std::cout << "reco el etcone( " << et_iso
    //             << " ) != d3pd etcone( " << et_iso_d3pd
    //             << " )\n";
    // if (int(1.e3*pt_iso) != int(1.e3*pt_iso_d3pd))
    //   std::cout << "reco el ptcone( " << pt_iso
    //             << " ) != d3pd ptcone( " << pt_iso_d3pd
    //             << " )\n";

    et_iso_frac = et_iso/pt;
    pt_iso_frac = pt_iso/pt;
  }
  if (iso_type == NtupleHelper::EWK_HIGGS_STYLE) {
    et_iso = getElIsoCorr( el_index
                         , NtupleHelper::TOPOETCONE
                         , NtupleHelper::CONE_30
                         )/1.e3;
    pt_iso = getElIsoCorr( el_index
                         , NtupleHelper::PTCONE
                         , NtupleHelper::CONE_30
                         )/1.e3;

    et_iso_frac = et_iso/pt;
    pt_iso_frac = pt_iso/pt;
  }
  else if (iso_type == NtupleHelper::STRONG_STYLE) {
    et_iso = getElIsoCorr( el_index
                         , NtupleHelper::TOPOETCONE
                         , NtupleHelper::CONE_20
                         )/1.e3;
    pt_iso = getElIsoCorr( el_index
                         , NtupleHelper::PTCONE
                         , NtupleHelper::CONE_20
                         )/1.e3;

    et_iso_frac = et_iso/std::min(60., pt);
    pt_iso_frac = pt_iso/std::min(60., pt);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  bool pass_tightpp      = el_desc.getPassTightPP();
  bool pass_pt           = (pt > 10);
  bool pass_eta          = (fabs(eta) < 2.47);
  bool pass_d0_sig       = (fabs(d0_sig) < 5);
  bool pass_z0_sin_theta = (fabs(z0_sin_theta) < 0.4);

  bool pass_et_iso = true;
  bool pass_pt_iso = true;
  if (iso_type == NtupleHelper::EWK_STYLE) {
    pass_et_iso = (et_iso_frac < 0.18);
    pass_pt_iso = (pt_iso_frac < 0.16);
  }
  // TODO review these cut values
  if (iso_type == NtupleHelper::EWK_HIGGS_STYLE) {
    pass_et_iso = (et_iso_frac < 0.18);
    pass_pt_iso = (pt_iso_frac < 0.16);
  }
  else if (iso_type == NtupleHelper::STRONG_STYLE) {
    pass_et_iso = (et_iso_frac < 0.06);
    pass_pt_iso = (pt_iso_frac < 0.06);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  bool is_signal_electron = (  pass_tightpp
                            && pass_pt
                            && pass_eta
                            && pass_d0_sig
                            && pass_z0_sin_theta
                            && pass_et_iso
                            && pass_pt_iso
                            );

  // if (is_signal_electron != is_signal_electron_cutflow) {
  //   std::cout << "\nWARNING: recalculated is_signal_electron != is_signal_electron from CF\n";
  //   std::cout << "\tevent #:                 " << m_event_number << "\n";
  //   std::cout << "\telectron index:          " << el_index << "\n";
  //   std::cout << "\t is_signal_electron_cutflow: " << is_signal_electron_cutflow << "\n";
  //   std::cout << "\t is_signal_electron:         " << is_signal_electron << "\n";
  //   std::cout << "\t ---                     CF - recalc\n";
  //   std::cout << "\t pass_pt:                " << el_desc.getPassBaselinePt() << " - " << pass_pt << "\n";
  //   std::cout << "\t pass_eta:               " << el_desc.getPassBaselineEta()  << " - " << pass_eta << "\n";
  //   std::cout << "\t pass_d0_sig:            " << el_desc.getPassD0Sig()      << " - " << pass_d0_sig << "\n";
  //   std::cout << "\t pass_z0_sin_theta:      " << el_desc.getPassZ0SinTheta() << " - " << pass_z0_sin_theta << "\n";
  //   std::cout << "\t pass_et_iso:            " << el_desc.getPassCaloIso()      << " - " << pass_et_iso << "\n";
  //   std::cout << "\t pass_pt_iso:            " << el_desc.getPassPtIso()      << " - " << pass_pt_iso << "\n";
  //   std::cout << "\t\teta: "         << eta << "\n";
  //   std::cout << "\t\tpt: "          << pt << "\n";
  //   std::cout << "\t\tet_iso: "      << et_iso << "\n";
  //   std::cout << "\t\tet_iso_frac: " << et_iso_frac << "\n";
  //   std::cout << "\t\tpt_iso: "      << pt_iso << "\n";
  //   std::cout << "\t\tpt_iso_frac: " << pt_iso_frac << "\n";
  // }

  return is_signal_electron;
}

// -----------------------------------------------------------------------------
bool NtupleHelper::NtupleLooper::isSignalMuon( const size_t mu_index
                               , const SusyAnalysisTools::MuonDescription& mu_desc
                               , bool use_default_decision
                               , NtupleHelper::ISO_STYLE iso_type
                               , float /* d0_sig_cut */
                               )
{
  bool is_signal_muon_cutflow = mu_desc.getPassSignal();
  if (use_default_decision) return is_signal_muon_cutflow;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  double pt = m_mu_pt->at(mu_index)/1.e3;
  double eta = m_mu_eta->at(mu_index);
  double d0_sig = m_mu_d0_sig->at(mu_index);
  double z0_sin_theta = m_mu_z0_sin_theta->at(mu_index);

  double pt_iso = -999;
  double et_iso = -999;
  double pt_iso_frac = -999;
  double et_iso_frac = -999;
  if (iso_type == EWK_STYLE) {
    pt_iso = getMuIsoCorr( mu_index
                         , NtupleHelper::PTCONE
                         , NtupleHelper::CONE_30
                         )/1.e3;
    et_iso = getMuIsoCorr( mu_index
                         , NtupleHelper::ETCONE
                         , NtupleHelper::CONE_30
                         )/1.e3;
    // double pt_iso_d3pd = m_mu_ptcone30_trkelstyle->at(mu_index)/1.e3;
    // double et_iso_d3pd = m_mu_etcone30->at(mu_index)/1.e3;

    // if (int(1.e3*et_iso) != int(1.e3*et_iso_d3pd)) std::cout << "reco mu etcone( " << et_iso << " != d3pd etcone( " << et_iso_d3pd << "\n";
    // if (int(1.e3*pt_iso) != int(1.e3*pt_iso_d3pd)) std::cout << "reco mu ptcone( " << pt_iso << " != d3pd ptcone( " << pt_iso_d3pd << "\n";

    pt_iso_frac = pt_iso/pt;
    et_iso_frac = 0.;
  }
  if (iso_type == EWK_HIGGS_STYLE) {
    pt_iso = getMuIsoCorr( mu_index
                         , NtupleHelper::PTCONE
                         , NtupleHelper::CONE_30
                         )/1.e3;
    et_iso = getMuIsoCorr( mu_index
                         , NtupleHelper::ETCONE
                         , NtupleHelper::CONE_30
                         )/1.e3;
    pt_iso_frac = pt_iso/pt;
    et_iso_frac = et_iso/pt;
  }
  else if (iso_type == STRONG_STYLE) {
    pt_iso = getMuIsoCorr( mu_index
                         , NtupleHelper::PTCONE
                         , NtupleHelper::CONE_30
                         )/1.e3;
    et_iso = getMuIsoCorr( mu_index
                         , NtupleHelper::ETCONE
                         , NtupleHelper::CONE_30
                         )/1.e3;
    pt_iso_frac = pt_iso/std::min(60.,pt);
    et_iso_frac = et_iso/std::min(60.,pt);
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  bool pass_pt           = (pt > 10);
  bool pass_eta          = (fabs(eta) < 2.4);
  bool pass_d0_sig       = (fabs(d0_sig) < 3);
  bool pass_z0_sin_theta = (fabs(z0_sin_theta) < 1);

  bool pass_pt_iso = true;
  bool pass_et_iso = true;
  if (iso_type == EWK_STYLE) {
    pass_pt_iso = (pt_iso_frac < 0.12);
  }
  // TODO review these cuts
  if (iso_type == EWK_HIGGS_STYLE) {
    pass_pt_iso = (pt_iso_frac < 0.12);
    pass_et_iso = (et_iso_frac < 0.12);

    // std::cout << "HIGGS  ISO (mu):\tpt: " << pt << "\tpt iso: " << pt_iso << "\tet iso: " << et_iso << "\tpt iso frac: " << pt_iso_frac << "\tpass pt iso frac: " << pass_pt_iso << "\tet iso frac: " << et_iso_frac << "\tpass et iso frac: " << pass_et_iso << "\tpass pt: " << pass_pt << "\tpass eta: " << pass_eta << "\tpass d0: " << pass_d0_sig << "\tpass z0: " << pass_z0_sin_theta << "\n";
  }
  // TODO review these cuts
  else if (iso_type == STRONG_STYLE) {
    pass_pt_iso = (pt_iso_frac < 0.12);
    pass_et_iso = (et_iso_frac < 0.12);

    // std::cout << "STRONG  ISO (mu):\tpt: " << pt << "\tpt iso: " << pt_iso << "\tet iso: " << et_iso << "\tpt iso frac: " << pt_iso_frac << "\tpass pt iso frac: " << pass_pt_iso << "\tet iso frac: " << et_iso_frac << "\tpass et iso frac: " << pass_et_iso << "\tpass pt: " << pass_pt << "\tpass eta: " << pass_eta << "\tpass d0: " << pass_d0_sig << "\tpass z0: " << pass_z0_sin_theta << "\n";
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  bool is_signal_muon = (  pass_pt
                        && pass_eta
                        && pass_d0_sig
                        && pass_z0_sin_theta
                        && pass_pt_iso
                        && pass_et_iso
                        );

  // if (is_signal_muon != is_signal_muon_cutflow) {
  //   std::cout << "WARNING: recalculated is_signal_muon != is_signal_muon from CF\n";
  //   std::cout << "\tevent #:                 " << m_event_number << "\n";
  //   std::cout << "\tmuon index:              " << mu_index << "\n";
  //   std::cout << "\t is_signal_muon_cutflow: " << is_signal_muon_cutflow << "\n";
  //   std::cout << "\t is_signal_muon:         " << is_signal_muon << "\n";
  //   std::cout << "\t ---                     CF - recalc\n";
  //   std::cout << "\t pass_pt:                " << mu_desc.getPassBaselinePt() << " - " << pass_pt << "\n";
  //   std::cout << "\t pass_eta:               " << mu_desc.getPassSignalEta() << " - " << pass_eta << "\n";
  //   std::cout << "\t pass_d0_sig:            " << mu_desc.getPassD0Sig() << " - " << pass_d0_sig << "\n";
  //   std::cout << "\t pass_z0_sin_theta:      " << mu_desc.getPassZ0SinTheta() << " - " << pass_z0_sin_theta << "\n";
  //   std::cout << "\t pass_pt_iso:            " << mu_desc.getPassPtIso() << " - " << pass_pt_iso << "\n";
  //   std::cout << "\t\tpt: "          << pt << "\n";
  //   std::cout << "\t\tpt_iso: "      << pt_iso << "\n";
  //   std::cout << "\t\tpt_iso_frac: " << pt_iso_frac << "\n";
  // }

  return is_signal_muon;
}

// -----------------------------------------------------------------------------
unsigned int NtupleHelper::NtupleLooper::getNumGoodVertices(unsigned int min_num_trks)
{
  unsigned int num_vertices = m_vtx_n;
  unsigned int num_good_vertices = 0;

  for (unsigned int vtx_it = 0; vtx_it != num_vertices; ++vtx_it) {
    if (m_vtx_n_tracks->at(vtx_it) >= min_num_trks) ++num_good_vertices;
  }

  return num_good_vertices;
}

// -----------------------------------------------------------------------------
double NtupleHelper::NtupleLooper::getElIsoCorr( unsigned int index
                                               , NtupleHelper::ISO_TYPE iso_type
                                               , NtupleHelper::CONE_SIZE cone_size
                                               )
{
  double raw_iso = 9999;
  double correction_slope = 0;
  int num_good_vertices = getNumGoodVertices(5);

  // get raw isolation and correction slope
  if (iso_type == TOPOETCONE) {
    if (cone_size == CONE_20) {
      raw_iso = m_el_raw_topoetcone20_corrected->at(index);
      correction_slope = (4./9.)*17.94;
    }
    else if (cone_size == CONE_30) {
      raw_iso = m_el_raw_topoetcone30_corrected->at(index);
      correction_slope = 17.94;
    }
    else if (cone_size == CONE_40) {
      raw_iso = m_el_raw_topoetcone40_corrected->at(index);
      correction_slope = (16./9.)*17.94;
    }
  }
  if (iso_type == PTCONE) {
    if (cone_size == CONE_20) {
      raw_iso = m_el_ptcone20->at(index);
      correction_slope = 0.;
    }
    else if (cone_size == CONE_30) {
      raw_iso = m_el_ptcone30->at(index);
      correction_slope = 0.;
    }
    else if (cone_size == CONE_40) {
      raw_iso = m_el_ptcone40->at(index);
      correction_slope = 0.;
    }
  }

  // apply correction
  double iso_corr = raw_iso - correction_slope*num_good_vertices;
  return iso_corr;
}

// -----------------------------------------------------------------------------
double NtupleHelper::NtupleLooper::getMuIsoCorr( unsigned int index
                                 , NtupleHelper::ISO_TYPE iso_type
                                 , NtupleHelper::CONE_SIZE cone_size
                                 )
{
  double raw_iso = 9999;
  double correction_slope_p0 = 0.;
  double correction_slope_p1 = 0.;
  int num_good_vertices = getNumGoodVertices(5);

  // get raw isolation and correction slope
  if (iso_type == ETCONE) {
    if (cone_size == CONE_20) {
      raw_iso = m_mu_raw_etcone20->at(index);
      correction_slope_p0 = (4./9.) * 69.2;
      correction_slope_p0 = (4./9.) * 0.76;
    }
    else if (cone_size == CONE_30) {
      raw_iso = m_mu_raw_etcone30->at(index);
      correction_slope_p0 = 69.2;
      correction_slope_p0 = 0.76;
    }
    else if (cone_size == CONE_40) {
      raw_iso = m_mu_raw_etcone40->at(index);
      correction_slope_p0 = (16./9.) * 69.2;
      correction_slope_p0 = (16./9.) * 0.76;
    }
  }
  if (iso_type == PTCONE) {
    if (cone_size == CONE_20) {
      raw_iso = m_mu_ptcone20_trkelstyle->at(index);
      correction_slope_p0 = 0.;
    }
    else if (cone_size == CONE_30) {
      raw_iso = m_mu_ptcone30_trkelstyle->at(index);
      correction_slope_p0 = 0.;
    }
    else if (cone_size == CONE_40) {
      raw_iso = m_mu_ptcone40_trkelstyle->at(index);
      correction_slope_p0 = 0.;
    }
  }

  // apply correction
  double iso_corr = ( raw_iso
                    - correction_slope_p0*num_good_vertices
                    - correction_slope_p1*num_good_vertices*num_good_vertices
                    );
  return iso_corr;
}
