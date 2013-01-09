#include <iostream>
#include <iomanip>
#include "include/NtupleLooper.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

// -----------------------------------------------------------------------------
NtupleLooper::NtupleLooper(TTree *tree) : fChain(0)
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
NtupleLooper::~NtupleLooper()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

// -----------------------------------------------------------------------------
Int_t NtupleLooper::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}

// -----------------------------------------------------------------------------
Long64_t NtupleLooper::LoadTree(Long64_t entry)
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
void NtupleLooper::Init(TTree *tree)
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
   m_mu_ptcone20 = 0;
   m_mu_ptcone30 = 0;
   m_mu_ptcone40 = 0;
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

   int branch_num = 0;
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
Bool_t NtupleLooper::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

// -----------------------------------------------------------------------------
void NtupleLooper::Loop()
{
  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntriesFast();
  std::cout << "number evens: " << nentries << "\n";

  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);
    nbytes += nb;

    processEvent();
  }
}

// -----------------------------------------------------------------------------
void NtupleLooper::processEvent()
{
  if (m_event_number % 10 == 0)
    std::cout << "event: " << m_event_number
              << " -- mll: " << m_mll << " MeV"
              << "\n";
}
