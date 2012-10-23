// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <limits>

#include <TPRegexp.h>

#include "../include/TriggerVecD3PDObject.h"

ClassImp( D3PDReader::TriggerVecD3PDObjectElement )
ClassImp( D3PDReader::TriggerVecD3PDObject )

namespace D3PDReader {

   /**
    * This constructor can be used to create new proxy objects from scratch.
    * Since the constructor of such an object is quite complicated and
    * error prone, it is only visible to the parent class TriggerVecD3PDObject.
    */
   TriggerVecD3PDObjectElement::TriggerVecD3PDObjectElement( size_t index, const TriggerVecD3PDObject& parent )
      : trig_EF_el_EF_2e12Tvh_loose1( parent.trig_EF_el_EF_2e12Tvh_loose1, index, this ),
        trig_EF_el_EF_2e5_tight1_Jpsi( parent.trig_EF_el_EF_2e5_tight1_Jpsi, index, this ),
        trig_EF_el_EF_2e7T_loose1_mu6( parent.trig_EF_el_EF_2e7T_loose1_mu6, index, this ),
        trig_EF_el_EF_2e7T_medium1_mu6( parent.trig_EF_el_EF_2e7T_medium1_mu6, index, this ),
        trig_EF_el_EF_e11_etcut( parent.trig_EF_el_EF_e11_etcut, index, this ),
        trig_EF_el_EF_e12Tvh_loose1( parent.trig_EF_el_EF_e12Tvh_loose1, index, this ),
        trig_EF_el_EF_e12Tvh_medium1( parent.trig_EF_el_EF_e12Tvh_medium1, index, this ),
        trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium( parent.trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium, index, this ),
        trig_EF_el_EF_e12Tvh_medium1_mu8( parent.trig_EF_el_EF_e12Tvh_medium1_mu8, index, this ),
        trig_EF_el_EF_e13_etcutTrk_xs60( parent.trig_EF_el_EF_e13_etcutTrk_xs60, index, this ),
        trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20( parent.trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20, index, this ),
        trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi( parent.trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi, index, this ),
        trig_EF_el_EF_e15vh_medium1( parent.trig_EF_el_EF_e15vh_medium1, index, this ),
        trig_EF_el_EF_e18_loose1( parent.trig_EF_el_EF_e18_loose1, index, this ),
        trig_EF_el_EF_e18_loose1_g25_medium( parent.trig_EF_el_EF_e18_loose1_g25_medium, index, this ),
        trig_EF_el_EF_e18_medium1( parent.trig_EF_el_EF_e18_medium1, index, this ),
        trig_EF_el_EF_e18_medium1_g25_loose( parent.trig_EF_el_EF_e18_medium1_g25_loose, index, this ),
        trig_EF_el_EF_e18vh_medium1( parent.trig_EF_el_EF_e18vh_medium1, index, this ),
        trig_EF_el_EF_e18vh_medium1_2e7T_medium1( parent.trig_EF_el_EF_e18vh_medium1_2e7T_medium1, index, this ),
        trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20( parent.trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20, index, this ),
        trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20( parent.trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20, index, this ),
        trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi( parent.trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi, index, this ),
        trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi( parent.trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi, index, this ),
        trig_EF_el_EF_e22vh_loose( parent.trig_EF_el_EF_e22vh_loose, index, this ),
        trig_EF_el_EF_e22vh_loose0( parent.trig_EF_el_EF_e22vh_loose0, index, this ),
        trig_EF_el_EF_e22vh_loose1( parent.trig_EF_el_EF_e22vh_loose1, index, this ),
        trig_EF_el_EF_e22vh_medium1( parent.trig_EF_el_EF_e22vh_medium1, index, this ),
        trig_EF_el_EF_e22vh_medium1_IDTrkNoCut( parent.trig_EF_el_EF_e22vh_medium1_IDTrkNoCut, index, this ),
        trig_EF_el_EF_e22vhi_medium1( parent.trig_EF_el_EF_e22vhi_medium1, index, this ),
        trig_EF_el_EF_e24vh_loose( parent.trig_EF_el_EF_e24vh_loose, index, this ),
        trig_EF_el_EF_e24vh_loose0( parent.trig_EF_el_EF_e24vh_loose0, index, this ),
        trig_EF_el_EF_e24vh_loose1( parent.trig_EF_el_EF_e24vh_loose1, index, this ),
        trig_EF_el_EF_e24vh_medium1( parent.trig_EF_el_EF_e24vh_medium1, index, this ),
        trig_EF_el_EF_e24vh_medium1_EFxe30( parent.trig_EF_el_EF_e24vh_medium1_EFxe30, index, this ),
        trig_EF_el_EF_e24vh_medium1_EFxe30_tcem( parent.trig_EF_el_EF_e24vh_medium1_EFxe30_tcem, index, this ),
        trig_EF_el_EF_e24vh_medium1_EFxe35_tcem( parent.trig_EF_el_EF_e24vh_medium1_EFxe35_tcem, index, this ),
        trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw( parent.trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw, index, this ),
        trig_EF_el_EF_e24vh_medium1_EFxe40( parent.trig_EF_el_EF_e24vh_medium1_EFxe40, index, this ),
        trig_EF_el_EF_e24vh_medium1_IDTrkNoCut( parent.trig_EF_el_EF_e24vh_medium1_IDTrkNoCut, index, this ),
        trig_EF_el_EF_e24vh_medium1_IdScan( parent.trig_EF_el_EF_e24vh_medium1_IdScan, index, this ),
        trig_EF_el_EF_e24vh_medium1_L2StarB( parent.trig_EF_el_EF_e24vh_medium1_L2StarB, index, this ),
        trig_EF_el_EF_e24vh_medium1_L2StarC( parent.trig_EF_el_EF_e24vh_medium1_L2StarC, index, this ),
        trig_EF_el_EF_e24vh_medium1_SiTrk( parent.trig_EF_el_EF_e24vh_medium1_SiTrk, index, this ),
        trig_EF_el_EF_e24vh_medium1_TRT( parent.trig_EF_el_EF_e24vh_medium1_TRT, index, this ),
        trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad( parent.trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad, index, this ),
        trig_EF_el_EF_e24vh_medium1_e7_medium1( parent.trig_EF_el_EF_e24vh_medium1_e7_medium1, index, this ),
        trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee( parent.trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee, index, this ),
        trig_EF_el_EF_e24vhi_loose1_mu8( parent.trig_EF_el_EF_e24vhi_loose1_mu8, index, this ),
        trig_EF_el_EF_e24vhi_medium1( parent.trig_EF_el_EF_e24vhi_medium1, index, this ),
        trig_EF_el_EF_e45_medium1( parent.trig_EF_el_EF_e45_medium1, index, this ),
        trig_EF_el_EF_e5_tight1( parent.trig_EF_el_EF_e5_tight1, index, this ),
        trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi( parent.trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi, index, this ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi( parent.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi, index, this ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB( parent.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB, index, this ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC( parent.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC, index, this ),
        trig_EF_el_EF_e5_tight1_e5_NoCut( parent.trig_EF_el_EF_e5_tight1_e5_NoCut, index, this ),
        trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi( parent.trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi, index, this ),
        trig_EF_el_EF_e60_medium1( parent.trig_EF_el_EF_e60_medium1, index, this ),
        trig_EF_el_EF_e7T_loose1( parent.trig_EF_el_EF_e7T_loose1, index, this ),
        trig_EF_el_EF_e7T_loose1_2mu6( parent.trig_EF_el_EF_e7T_loose1_2mu6, index, this ),
        trig_EF_el_EF_e7T_medium1( parent.trig_EF_el_EF_e7T_medium1, index, this ),
        trig_EF_el_EF_e7T_medium1_2mu6( parent.trig_EF_el_EF_e7T_medium1_2mu6, index, this ),
        trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi( parent.trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi, index, this ),
        trig_EF_el_EF_eb_physics( parent.trig_EF_el_EF_eb_physics, index, this ),
        trig_EF_el_EF_eb_physics_empty( parent.trig_EF_el_EF_eb_physics_empty, index, this ),
        trig_EF_el_EF_eb_physics_firstempty( parent.trig_EF_el_EF_eb_physics_firstempty, index, this ),
        trig_EF_el_EF_eb_physics_noL1PS( parent.trig_EF_el_EF_eb_physics_noL1PS, index, this ),
        trig_EF_el_EF_eb_physics_unpaired_iso( parent.trig_EF_el_EF_eb_physics_unpaired_iso, index, this ),
        trig_EF_el_EF_eb_physics_unpaired_noniso( parent.trig_EF_el_EF_eb_physics_unpaired_noniso, index, this ),
        trig_EF_el_EF_eb_random( parent.trig_EF_el_EF_eb_random, index, this ),
        trig_EF_el_EF_eb_random_empty( parent.trig_EF_el_EF_eb_random_empty, index, this ),
        trig_EF_el_EF_eb_random_firstempty( parent.trig_EF_el_EF_eb_random_firstempty, index, this ),
        trig_EF_el_EF_eb_random_unpaired_iso( parent.trig_EF_el_EF_eb_random_unpaired_iso, index, this ),
        trig_EF_emcl_pt( parent.trig_EF_emcl_pt, index, this ),
        trig_EF_emcl_eta( parent.trig_EF_emcl_eta, index, this ),
        trig_EF_emcl_phi( parent.trig_EF_emcl_phi, index, this ),
        trig_EF_emcl_E_em( parent.trig_EF_emcl_E_em, index, this ),
        trig_EF_emcl_E_had( parent.trig_EF_emcl_E_had, index, this ),
        trig_EF_emcl_slw_pt( parent.trig_EF_emcl_slw_pt, index, this ),
        trig_EF_emcl_slw_eta( parent.trig_EF_emcl_slw_eta, index, this ),
        trig_EF_emcl_slw_phi( parent.trig_EF_emcl_slw_phi, index, this ),
        trig_EF_emcl_slw_E_em( parent.trig_EF_emcl_slw_E_em, index, this ),
        trig_EF_emcl_slw_E_had( parent.trig_EF_emcl_slw_E_had, index, this ),
        trig_EF_el_E( parent.trig_EF_el_E, index, this ),
        trig_EF_el_Et( parent.trig_EF_el_Et, index, this ),
        trig_EF_el_pt( parent.trig_EF_el_pt, index, this ),
        trig_EF_el_m( parent.trig_EF_el_m, index, this ),
        trig_EF_el_eta( parent.trig_EF_el_eta, index, this ),
        trig_EF_el_phi( parent.trig_EF_el_phi, index, this ),
        trig_EF_el_px( parent.trig_EF_el_px, index, this ),
        trig_EF_el_py( parent.trig_EF_el_py, index, this ),
        trig_EF_el_pz( parent.trig_EF_el_pz, index, this ),
        trig_EF_el_charge( parent.trig_EF_el_charge, index, this ),
        trig_EF_el_author( parent.trig_EF_el_author, index, this ),
        trig_EF_el_isEM( parent.trig_EF_el_isEM, index, this ),
        trig_EF_el_isEMLoose( parent.trig_EF_el_isEMLoose, index, this ),
        trig_EF_el_isEMMedium( parent.trig_EF_el_isEMMedium, index, this ),
        trig_EF_el_isEMTight( parent.trig_EF_el_isEMTight, index, this ),
        trig_EF_el_loose( parent.trig_EF_el_loose, index, this ),
        trig_EF_el_looseIso( parent.trig_EF_el_looseIso, index, this ),
        trig_EF_el_medium( parent.trig_EF_el_medium, index, this ),
        trig_EF_el_mediumIso( parent.trig_EF_el_mediumIso, index, this ),
        trig_EF_el_mediumWithoutTrack( parent.trig_EF_el_mediumWithoutTrack, index, this ),
        trig_EF_el_mediumIsoWithoutTrack( parent.trig_EF_el_mediumIsoWithoutTrack, index, this ),
        trig_EF_el_tight( parent.trig_EF_el_tight, index, this ),
        trig_EF_el_tightIso( parent.trig_EF_el_tightIso, index, this ),
        trig_EF_el_tightWithoutTrack( parent.trig_EF_el_tightWithoutTrack, index, this ),
        trig_EF_el_tightIsoWithoutTrack( parent.trig_EF_el_tightIsoWithoutTrack, index, this ),
        trig_EF_el_loosePP( parent.trig_EF_el_loosePP, index, this ),
        trig_EF_el_loosePPIso( parent.trig_EF_el_loosePPIso, index, this ),
        trig_EF_el_mediumPP( parent.trig_EF_el_mediumPP, index, this ),
        trig_EF_el_mediumPPIso( parent.trig_EF_el_mediumPPIso, index, this ),
        trig_EF_el_tightPP( parent.trig_EF_el_tightPP, index, this ),
        trig_EF_el_tightPPIso( parent.trig_EF_el_tightPPIso, index, this ),
        trig_EF_el_vertweight( parent.trig_EF_el_vertweight, index, this ),
        trig_EF_el_hastrack( parent.trig_EF_el_hastrack, index, this ),
        trig_EF_trigmuonef_track_CB_pt( parent.trig_EF_trigmuonef_track_CB_pt, index, this ),
        trig_EF_trigmuonef_track_CB_eta( parent.trig_EF_trigmuonef_track_CB_eta, index, this ),
        trig_EF_trigmuonef_track_CB_phi( parent.trig_EF_trigmuonef_track_CB_phi, index, this ),
        trig_EF_trigmuonef_track_CB_hasCB( parent.trig_EF_trigmuonef_track_CB_hasCB, index, this ) ,

    // =============================================================================
    // = Data only
    // =============================================================================
        trig_EF_trigmuonef_EF_2mu10( parent.trig_EF_trigmuonef_EF_2mu10, index, this ),
        trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose( parent.trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose, index, this ),
        trig_EF_trigmuonef_EF_2mu13( parent.trig_EF_trigmuonef_EF_2mu13, index, this ),
        trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut( parent.trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut, index, this ),
        trig_EF_trigmuonef_EF_2mu13_l2muonSA( parent.trig_EF_trigmuonef_EF_2mu13_l2muonSA, index, this ),
        trig_EF_trigmuonef_EF_2mu15( parent.trig_EF_trigmuonef_EF_2mu15, index, this ),
        trig_EF_trigmuonef_EF_2mu4T( parent.trig_EF_trigmuonef_EF_2mu4T, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_2e5_tight1( parent.trig_EF_trigmuonef_EF_2mu4T_2e5_tight1, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumu( parent.trig_EF_trigmuonef_EF_2mu4T_Bmumu, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel( parent.trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly( parent.trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumux( parent.trig_EF_trigmuonef_EF_2mu4T_Bmumux, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel( parent.trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly( parent.trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu( parent.trig_EF_trigmuonef_EF_2mu4T_DiMu, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel( parent.trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly( parent.trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB( parent.trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC( parent.trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1( parent.trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA( parent.trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS( parent.trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_Jpsimumu( parent.trig_EF_trigmuonef_EF_2mu4T_Jpsimumu, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel( parent.trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly( parent.trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut( parent.trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_Upsimumu( parent.trig_EF_trigmuonef_EF_2mu4T_Upsimumu, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel( parent.trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly( parent.trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_xe60( parent.trig_EF_trigmuonef_EF_2mu4T_xe60, index, this ),
        trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw( parent.trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw, index, this ),
        trig_EF_trigmuonef_EF_2mu6( parent.trig_EF_trigmuonef_EF_2mu6, index, this ),
        trig_EF_trigmuonef_EF_2mu6_Bmumu( parent.trig_EF_trigmuonef_EF_2mu6_Bmumu, index, this ),
        trig_EF_trigmuonef_EF_2mu6_Bmumux( parent.trig_EF_trigmuonef_EF_2mu6_Bmumux, index, this ),
        trig_EF_trigmuonef_EF_2mu6_DiMu( parent.trig_EF_trigmuonef_EF_2mu6_DiMu, index, this ),
        trig_EF_trigmuonef_EF_2mu6_DiMu_DY20( parent.trig_EF_trigmuonef_EF_2mu6_DiMu_DY20, index, this ),
        trig_EF_trigmuonef_EF_2mu6_DiMu_DY25( parent.trig_EF_trigmuonef_EF_2mu6_DiMu_DY25, index, this ),
        trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS( parent.trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS, index, this ),
        trig_EF_trigmuonef_EF_2mu6_Jpsimumu( parent.trig_EF_trigmuonef_EF_2mu6_Jpsimumu, index, this ),
        trig_EF_trigmuonef_EF_2mu6_Upsimumu( parent.trig_EF_trigmuonef_EF_2mu6_Upsimumu, index, this ),
        trig_EF_trigmuonef_EF_2mu6i_DiMu_DY( parent.trig_EF_trigmuonef_EF_2mu6i_DiMu_DY, index, this ),
        trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad( parent.trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad, index, this ),
        trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS( parent.trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS, index, this ),
        trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad( parent.trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad, index, this ),
        trig_EF_trigmuonef_EF_2mu8_EFxe30( parent.trig_EF_trigmuonef_EF_2mu8_EFxe30, index, this ),
        trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw( parent.trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw, index, this ),
        trig_EF_trigmuonef_EF_mu10( parent.trig_EF_trigmuonef_EF_mu10, index, this ),
        trig_EF_trigmuonef_EF_mu10_Jpsimumu( parent.trig_EF_trigmuonef_EF_mu10_Jpsimumu, index, this ),
        trig_EF_trigmuonef_EF_mu10_MSonly( parent.trig_EF_trigmuonef_EF_mu10_MSonly, index, this ),
        trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS( parent.trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS, index, this ),
        trig_EF_trigmuonef_EF_mu10i_g10_medium( parent.trig_EF_trigmuonef_EF_mu10i_g10_medium, index, this ),
        trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass( parent.trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass, index, this ),
        trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium( parent.trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium, index, this ),
        trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass( parent.trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass, index, this ),
        trig_EF_trigmuonef_EF_mu11_empty_NoAlg( parent.trig_EF_trigmuonef_EF_mu11_empty_NoAlg, index, this ),
        trig_EF_trigmuonef_EF_mu13( parent.trig_EF_trigmuonef_EF_mu13, index, this ),
        trig_EF_trigmuonef_EF_mu15( parent.trig_EF_trigmuonef_EF_mu15, index, this ),
        trig_EF_trigmuonef_EF_mu18( parent.trig_EF_trigmuonef_EF_mu18, index, this ),
        trig_EF_trigmuonef_EF_mu18_2g10_loose( parent.trig_EF_trigmuonef_EF_mu18_2g10_loose, index, this ),
        trig_EF_trigmuonef_EF_mu18_2g10_medium( parent.trig_EF_trigmuonef_EF_mu18_2g10_medium, index, this ),
        trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight( parent.trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight, index, this ),
        trig_EF_trigmuonef_EF_mu18_medium( parent.trig_EF_trigmuonef_EF_mu18_medium, index, this ),
        trig_EF_trigmuonef_EF_mu18_tight( parent.trig_EF_trigmuonef_EF_mu18_tight, index, this ),
        trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS( parent.trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS, index, this ),
        trig_EF_trigmuonef_EF_mu18_tight_e7_medium1( parent.trig_EF_trigmuonef_EF_mu18_tight_e7_medium1, index, this ),
        trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS( parent.trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS, index, this ),
        trig_EF_trigmuonef_EF_mu18i4_tight( parent.trig_EF_trigmuonef_EF_mu18i4_tight, index, this ),
        trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass( parent.trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass, index, this ),
        trig_EF_trigmuonef_EF_mu20i_tight_g5_medium( parent.trig_EF_trigmuonef_EF_mu20i_tight_g5_medium, index, this ),
        trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass( parent.trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass, index, this ),
        trig_EF_trigmuonef_EF_mu20it_tight( parent.trig_EF_trigmuonef_EF_mu20it_tight, index, this ),
        trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight( parent.trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight, index, this ),
        trig_EF_trigmuonef_EF_mu24( parent.trig_EF_trigmuonef_EF_mu24, index, this ),
        trig_EF_trigmuonef_EF_mu24_g20vh_loose( parent.trig_EF_trigmuonef_EF_mu24_g20vh_loose, index, this ),
        trig_EF_trigmuonef_EF_mu24_g20vh_medium( parent.trig_EF_trigmuonef_EF_mu24_g20vh_medium, index, this ),
        trig_EF_trigmuonef_EF_mu24_j65_a4tchad( parent.trig_EF_trigmuonef_EF_mu24_j65_a4tchad, index, this ),
        trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40( parent.trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40, index, this ),
        trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw( parent.trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw, index, this ),
        trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw( parent.trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw, index, this ),
        trig_EF_trigmuonef_EF_mu24_medium( parent.trig_EF_trigmuonef_EF_mu24_medium, index, this ),
        trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight( parent.trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight, index, this ),
        trig_EF_trigmuonef_EF_mu24_tight( parent.trig_EF_trigmuonef_EF_mu24_tight, index, this ),
        trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad( parent.trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad, index, this ),
        trig_EF_trigmuonef_EF_mu24_tight_EFxe40( parent.trig_EF_trigmuonef_EF_mu24_tight_EFxe40, index, this ),
        trig_EF_trigmuonef_EF_mu24_tight_L2StarB( parent.trig_EF_trigmuonef_EF_mu24_tight_L2StarB, index, this ),
        trig_EF_trigmuonef_EF_mu24_tight_L2StarC( parent.trig_EF_trigmuonef_EF_mu24_tight_L2StarC, index, this ),
        trig_EF_trigmuonef_EF_mu24_tight_MG( parent.trig_EF_trigmuonef_EF_mu24_tight_MG, index, this ),
        trig_EF_trigmuonef_EF_mu24_tight_MuonEF( parent.trig_EF_trigmuonef_EF_mu24_tight_MuonEF, index, this ),
        trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad( parent.trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad, index, this ),
        trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS( parent.trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS, index, this ),
        trig_EF_trigmuonef_EF_mu24i_tight( parent.trig_EF_trigmuonef_EF_mu24i_tight, index, this ),
        trig_EF_trigmuonef_EF_mu24i_tight_MG( parent.trig_EF_trigmuonef_EF_mu24i_tight_MG, index, this ),
        trig_EF_trigmuonef_EF_mu24i_tight_MuonEF( parent.trig_EF_trigmuonef_EF_mu24i_tight_MuonEF, index, this ),
        trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA( parent.trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA, index, this ),
        trig_EF_trigmuonef_EF_mu36_tight( parent.trig_EF_trigmuonef_EF_mu36_tight, index, this ),
        trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight( parent.trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight, index, this ),
        trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF( parent.trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF, index, this ),
        trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight( parent.trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight, index, this ),
        trig_EF_trigmuonef_EF_mu40_slow_tight( parent.trig_EF_trigmuonef_EF_mu40_slow_tight, index, this ),
        trig_EF_trigmuonef_EF_mu40_tight( parent.trig_EF_trigmuonef_EF_mu40_tight, index, this ),
        trig_EF_trigmuonef_EF_mu4T( parent.trig_EF_trigmuonef_EF_mu4T, index, this ),
        trig_EF_trigmuonef_EF_mu4T_cosmic( parent.trig_EF_trigmuonef_EF_mu4T_cosmic, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched( parent.trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched( parent.trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ( parent.trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched( parent.trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched( parent.trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ( parent.trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched( parent.trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ( parent.trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched( parent.trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ( parent.trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ( parent.trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched( parent.trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ( parent.trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ( parent.trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched( parent.trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose( parent.trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose( parent.trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched( parent.trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched, index, this ),
        trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium( parent.trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium, index, this ),
        trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass( parent.trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass, index, this ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu( parent.trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu, index, this ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel( parent.trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel, index, this ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux( parent.trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux, index, this ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel( parent.trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel, index, this ),
        trig_EF_trigmuonef_EF_mu4Tmu6_DiMu( parent.trig_EF_trigmuonef_EF_mu4Tmu6_DiMu, index, this ),
        trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel( parent.trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel, index, this ),
        trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS( parent.trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS, index, this ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu( parent.trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu, index, this ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel( parent.trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel, index, this ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut( parent.trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut, index, this ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu( parent.trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu, index, this ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel( parent.trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel, index, this ),
        trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic( parent.trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic, index, this ),
        trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic( parent.trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic, index, this ),
        trig_EF_trigmuonef_EF_mu4_empty_NoAlg( parent.trig_EF_trigmuonef_EF_mu4_empty_NoAlg, index, this ),
        trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg( parent.trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg, index, this ),
        trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg( parent.trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg, index, this ),
        trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight( parent.trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight, index, this ),
        trig_EF_trigmuonef_EF_mu6( parent.trig_EF_trigmuonef_EF_mu6, index, this ),
        trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1( parent.trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1, index, this ),
        trig_EF_trigmuonef_EF_mu60_slow_tight1( parent.trig_EF_trigmuonef_EF_mu60_slow_tight1, index, this ),
        trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight( parent.trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight, index, this ),
        trig_EF_trigmuonef_EF_mu6_MSonly( parent.trig_EF_trigmuonef_EF_mu6_MSonly, index, this ),
        trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose( parent.trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose, index, this ),
        trig_EF_trigmuonef_EF_mu8( parent.trig_EF_trigmuonef_EF_mu8, index, this ),
        trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS( parent.trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS, index, this ),
        trig_EF_trigmuonef_track_MuonType( parent.trig_EF_trigmuonef_track_MuonType, index, this ),
        trig_EF_trigmuonef_track_MS_pt( parent.trig_EF_trigmuonef_track_MS_pt, index, this ),
        trig_EF_trigmuonef_track_MS_eta( parent.trig_EF_trigmuonef_track_MS_eta, index, this ),
        trig_EF_trigmuonef_track_MS_phi( parent.trig_EF_trigmuonef_track_MS_phi, index, this ),
        trig_EF_trigmuonef_track_MS_hasMS( parent.trig_EF_trigmuonef_track_MS_hasMS, index, this ),
        trig_EF_trigmuonef_track_SA_pt( parent.trig_EF_trigmuonef_track_SA_pt, index, this ),
        trig_EF_trigmuonef_track_SA_eta( parent.trig_EF_trigmuonef_track_SA_eta, index, this ),
        trig_EF_trigmuonef_track_SA_phi( parent.trig_EF_trigmuonef_track_SA_phi, index, this ),
        trig_EF_trigmuonef_track_SA_hasSA( parent.trig_EF_trigmuonef_track_SA_hasSA, index, this ),
    
    // =============================================================================
    // = MC only
    // =============================================================================
        trig_EF_el_EF_e12Tvh_loose1_mu8( parent.trig_EF_el_EF_e12Tvh_loose1_mu8, index, this ),
        trig_EF_el_EF_e12Tvh_medium1_mu10( parent.trig_EF_el_EF_e12Tvh_medium1_mu10, index, this ),
        trig_EF_el_EF_e12Tvh_medium1_mu6( parent.trig_EF_el_EF_e12Tvh_medium1_mu6, index, this ),
        trig_EF_el_EF_e18_loose1_g35_loose( parent.trig_EF_el_EF_e18_loose1_g35_loose, index, this ),
        trig_EF_el_EF_e18_loose1_g35_medium( parent.trig_EF_el_EF_e18_loose1_g35_medium, index, this ),
        trig_EF_el_EF_e18_medium1_g25_medium( parent.trig_EF_el_EF_e18_medium1_g25_medium, index, this ),
        trig_EF_el_EF_e18_medium1_g35_loose( parent.trig_EF_el_EF_e18_medium1_g35_loose, index, this ),
        trig_EF_el_EF_e18_medium1_g35_medium( parent.trig_EF_el_EF_e18_medium1_g35_medium, index, this ),
        trig_EF_el_EF_e22vh_medium1_IdScan( parent.trig_EF_el_EF_e22vh_medium1_IdScan, index, this ),
        trig_EF_el_EF_e22vh_medium1_SiTrk( parent.trig_EF_el_EF_e22vh_medium1_SiTrk, index, this ),
        trig_EF_el_EF_e22vh_medium1_TRT( parent.trig_EF_el_EF_e22vh_medium1_TRT, index, this ),
        trig_EF_el_EF_e45_etcut( parent.trig_EF_el_EF_e45_etcut, index, this ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan( parent.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan, index, this ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk( parent.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk, index, this ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT( parent.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT, index, this ),
        trig_EF_el_EF_e60_etcut( parent.trig_EF_el_EF_e60_etcut, index, this )
    
  {

   }

   /**
    * This constructor is useful for creating copies of proxy objects.
    * Such objects are fairly cheap to copy, so the user is allowed to have
    * his/her containers of them inside an analysis code. (To select and
    * sort objects according to some criteria for instance.)
    *
    * @param parent The proxy object that should be copied
    */
   TriggerVecD3PDObjectElement::TriggerVecD3PDObjectElement( const TriggerVecD3PDObjectElement& parent )
      : TObject( parent ),
        trig_EF_el_EF_2e12Tvh_loose1( parent.trig_EF_el_EF_2e12Tvh_loose1 ),
        trig_EF_el_EF_2e5_tight1_Jpsi( parent.trig_EF_el_EF_2e5_tight1_Jpsi ),
        trig_EF_el_EF_2e7T_loose1_mu6( parent.trig_EF_el_EF_2e7T_loose1_mu6 ),
        trig_EF_el_EF_2e7T_medium1_mu6( parent.trig_EF_el_EF_2e7T_medium1_mu6 ),
        trig_EF_el_EF_e11_etcut( parent.trig_EF_el_EF_e11_etcut ),
        trig_EF_el_EF_e12Tvh_loose1( parent.trig_EF_el_EF_e12Tvh_loose1 ),
        trig_EF_el_EF_e12Tvh_medium1( parent.trig_EF_el_EF_e12Tvh_medium1 ),
        trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium( parent.trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium ),
        trig_EF_el_EF_e12Tvh_medium1_mu8( parent.trig_EF_el_EF_e12Tvh_medium1_mu8 ),
        trig_EF_el_EF_e13_etcutTrk_xs60( parent.trig_EF_el_EF_e13_etcutTrk_xs60 ),
        trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20( parent.trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20 ),
        trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi( parent.trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi ),
        trig_EF_el_EF_e15vh_medium1( parent.trig_EF_el_EF_e15vh_medium1 ),
        trig_EF_el_EF_e18_loose1( parent.trig_EF_el_EF_e18_loose1 ),
        trig_EF_el_EF_e18_loose1_g25_medium( parent.trig_EF_el_EF_e18_loose1_g25_medium ),
        trig_EF_el_EF_e18_medium1( parent.trig_EF_el_EF_e18_medium1 ),
        trig_EF_el_EF_e18_medium1_g25_loose( parent.trig_EF_el_EF_e18_medium1_g25_loose ),
        trig_EF_el_EF_e18vh_medium1( parent.trig_EF_el_EF_e18vh_medium1 ),
        trig_EF_el_EF_e18vh_medium1_2e7T_medium1( parent.trig_EF_el_EF_e18vh_medium1_2e7T_medium1 ),
        trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20( parent.trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20 ),
        trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20( parent.trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20 ),
        trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi( parent.trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi ),
        trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi( parent.trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi ),
        trig_EF_el_EF_e22vh_loose( parent.trig_EF_el_EF_e22vh_loose ),
        trig_EF_el_EF_e22vh_loose0( parent.trig_EF_el_EF_e22vh_loose0 ),
        trig_EF_el_EF_e22vh_loose1( parent.trig_EF_el_EF_e22vh_loose1 ),
        trig_EF_el_EF_e22vh_medium1( parent.trig_EF_el_EF_e22vh_medium1 ),
        trig_EF_el_EF_e22vh_medium1_IDTrkNoCut( parent.trig_EF_el_EF_e22vh_medium1_IDTrkNoCut ),
        trig_EF_el_EF_e22vhi_medium1( parent.trig_EF_el_EF_e22vhi_medium1 ),
        trig_EF_el_EF_e24vh_loose( parent.trig_EF_el_EF_e24vh_loose ),
        trig_EF_el_EF_e24vh_loose0( parent.trig_EF_el_EF_e24vh_loose0 ),
        trig_EF_el_EF_e24vh_loose1( parent.trig_EF_el_EF_e24vh_loose1 ),
        trig_EF_el_EF_e24vh_medium1( parent.trig_EF_el_EF_e24vh_medium1 ),
        trig_EF_el_EF_e24vh_medium1_EFxe30( parent.trig_EF_el_EF_e24vh_medium1_EFxe30 ),
        trig_EF_el_EF_e24vh_medium1_EFxe30_tcem( parent.trig_EF_el_EF_e24vh_medium1_EFxe30_tcem ),
        trig_EF_el_EF_e24vh_medium1_EFxe35_tcem( parent.trig_EF_el_EF_e24vh_medium1_EFxe35_tcem ),
        trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw( parent.trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw ),
        trig_EF_el_EF_e24vh_medium1_EFxe40( parent.trig_EF_el_EF_e24vh_medium1_EFxe40 ),
        trig_EF_el_EF_e24vh_medium1_IDTrkNoCut( parent.trig_EF_el_EF_e24vh_medium1_IDTrkNoCut ),
        trig_EF_el_EF_e24vh_medium1_IdScan( parent.trig_EF_el_EF_e24vh_medium1_IdScan ),
        trig_EF_el_EF_e24vh_medium1_L2StarB( parent.trig_EF_el_EF_e24vh_medium1_L2StarB ),
        trig_EF_el_EF_e24vh_medium1_L2StarC( parent.trig_EF_el_EF_e24vh_medium1_L2StarC ),
        trig_EF_el_EF_e24vh_medium1_SiTrk( parent.trig_EF_el_EF_e24vh_medium1_SiTrk ),
        trig_EF_el_EF_e24vh_medium1_TRT( parent.trig_EF_el_EF_e24vh_medium1_TRT ),
        trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad( parent.trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad ),
        trig_EF_el_EF_e24vh_medium1_e7_medium1( parent.trig_EF_el_EF_e24vh_medium1_e7_medium1 ),
        trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee( parent.trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee ),
        trig_EF_el_EF_e24vhi_loose1_mu8( parent.trig_EF_el_EF_e24vhi_loose1_mu8 ),
        trig_EF_el_EF_e24vhi_medium1( parent.trig_EF_el_EF_e24vhi_medium1 ),
        trig_EF_el_EF_e45_medium1( parent.trig_EF_el_EF_e45_medium1 ),
        trig_EF_el_EF_e5_tight1( parent.trig_EF_el_EF_e5_tight1 ),
        trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi( parent.trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi( parent.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB( parent.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC( parent.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC ),
        trig_EF_el_EF_e5_tight1_e5_NoCut( parent.trig_EF_el_EF_e5_tight1_e5_NoCut ),
        trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi( parent.trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi ),
        trig_EF_el_EF_e60_medium1( parent.trig_EF_el_EF_e60_medium1 ),
        trig_EF_el_EF_e7T_loose1( parent.trig_EF_el_EF_e7T_loose1 ),
        trig_EF_el_EF_e7T_loose1_2mu6( parent.trig_EF_el_EF_e7T_loose1_2mu6 ),
        trig_EF_el_EF_e7T_medium1( parent.trig_EF_el_EF_e7T_medium1 ),
        trig_EF_el_EF_e7T_medium1_2mu6( parent.trig_EF_el_EF_e7T_medium1_2mu6 ),
        trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi( parent.trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi ),
        trig_EF_el_EF_eb_physics( parent.trig_EF_el_EF_eb_physics ),
        trig_EF_el_EF_eb_physics_empty( parent.trig_EF_el_EF_eb_physics_empty ),
        trig_EF_el_EF_eb_physics_firstempty( parent.trig_EF_el_EF_eb_physics_firstempty ),
        trig_EF_el_EF_eb_physics_noL1PS( parent.trig_EF_el_EF_eb_physics_noL1PS ),
        trig_EF_el_EF_eb_physics_unpaired_iso( parent.trig_EF_el_EF_eb_physics_unpaired_iso ),
        trig_EF_el_EF_eb_physics_unpaired_noniso( parent.trig_EF_el_EF_eb_physics_unpaired_noniso ),
        trig_EF_el_EF_eb_random( parent.trig_EF_el_EF_eb_random ),
        trig_EF_el_EF_eb_random_empty( parent.trig_EF_el_EF_eb_random_empty ),
        trig_EF_el_EF_eb_random_firstempty( parent.trig_EF_el_EF_eb_random_firstempty ),
        trig_EF_el_EF_eb_random_unpaired_iso( parent.trig_EF_el_EF_eb_random_unpaired_iso ),
        trig_EF_emcl_pt( parent.trig_EF_emcl_pt ),
        trig_EF_emcl_eta( parent.trig_EF_emcl_eta ),
        trig_EF_emcl_phi( parent.trig_EF_emcl_phi ),
        trig_EF_emcl_E_em( parent.trig_EF_emcl_E_em ),
        trig_EF_emcl_E_had( parent.trig_EF_emcl_E_had ),
        trig_EF_emcl_slw_pt( parent.trig_EF_emcl_slw_pt ),
        trig_EF_emcl_slw_eta( parent.trig_EF_emcl_slw_eta ),
        trig_EF_emcl_slw_phi( parent.trig_EF_emcl_slw_phi ),
        trig_EF_emcl_slw_E_em( parent.trig_EF_emcl_slw_E_em ),
        trig_EF_emcl_slw_E_had( parent.trig_EF_emcl_slw_E_had ),
        trig_EF_el_E( parent.trig_EF_el_E ),
        trig_EF_el_Et( parent.trig_EF_el_Et ),
        trig_EF_el_pt( parent.trig_EF_el_pt ),
        trig_EF_el_m( parent.trig_EF_el_m ),
        trig_EF_el_eta( parent.trig_EF_el_eta ),
        trig_EF_el_phi( parent.trig_EF_el_phi ),
        trig_EF_el_px( parent.trig_EF_el_px ),
        trig_EF_el_py( parent.trig_EF_el_py ),
        trig_EF_el_pz( parent.trig_EF_el_pz ),
        trig_EF_el_charge( parent.trig_EF_el_charge ),
        trig_EF_el_author( parent.trig_EF_el_author ),
        trig_EF_el_isEM( parent.trig_EF_el_isEM ),
        trig_EF_el_isEMLoose( parent.trig_EF_el_isEMLoose ),
        trig_EF_el_isEMMedium( parent.trig_EF_el_isEMMedium ),
        trig_EF_el_isEMTight( parent.trig_EF_el_isEMTight ),
        trig_EF_el_loose( parent.trig_EF_el_loose ),
        trig_EF_el_looseIso( parent.trig_EF_el_looseIso ),
        trig_EF_el_medium( parent.trig_EF_el_medium ),
        trig_EF_el_mediumIso( parent.trig_EF_el_mediumIso ),
        trig_EF_el_mediumWithoutTrack( parent.trig_EF_el_mediumWithoutTrack ),
        trig_EF_el_mediumIsoWithoutTrack( parent.trig_EF_el_mediumIsoWithoutTrack ),
        trig_EF_el_tight( parent.trig_EF_el_tight ),
        trig_EF_el_tightIso( parent.trig_EF_el_tightIso ),
        trig_EF_el_tightWithoutTrack( parent.trig_EF_el_tightWithoutTrack ),
        trig_EF_el_tightIsoWithoutTrack( parent.trig_EF_el_tightIsoWithoutTrack ),
        trig_EF_el_loosePP( parent.trig_EF_el_loosePP ),
        trig_EF_el_loosePPIso( parent.trig_EF_el_loosePPIso ),
        trig_EF_el_mediumPP( parent.trig_EF_el_mediumPP ),
        trig_EF_el_mediumPPIso( parent.trig_EF_el_mediumPPIso ),
        trig_EF_el_tightPP( parent.trig_EF_el_tightPP ),
        trig_EF_el_tightPPIso( parent.trig_EF_el_tightPPIso ),
        trig_EF_el_vertweight( parent.trig_EF_el_vertweight ),
        trig_EF_el_hastrack( parent.trig_EF_el_hastrack ),
        trig_EF_trigmuonef_track_CB_pt( parent.trig_EF_trigmuonef_track_CB_pt ),
        trig_EF_trigmuonef_track_CB_eta( parent.trig_EF_trigmuonef_track_CB_eta ),
        trig_EF_trigmuonef_track_CB_phi( parent.trig_EF_trigmuonef_track_CB_phi ),
        trig_EF_trigmuonef_track_CB_hasCB( parent.trig_EF_trigmuonef_track_CB_hasCB ) ,

    // =============================================================================
    // = Data only
    // =============================================================================
        trig_EF_trigmuonef_EF_2mu10( parent.trig_EF_trigmuonef_EF_2mu10 ),
        trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose( parent.trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose ),
        trig_EF_trigmuonef_EF_2mu13( parent.trig_EF_trigmuonef_EF_2mu13 ),
        trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut( parent.trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut ),
        trig_EF_trigmuonef_EF_2mu13_l2muonSA( parent.trig_EF_trigmuonef_EF_2mu13_l2muonSA ),
        trig_EF_trigmuonef_EF_2mu15( parent.trig_EF_trigmuonef_EF_2mu15 ),
        trig_EF_trigmuonef_EF_2mu4T( parent.trig_EF_trigmuonef_EF_2mu4T ),
        trig_EF_trigmuonef_EF_2mu4T_2e5_tight1( parent.trig_EF_trigmuonef_EF_2mu4T_2e5_tight1 ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumu( parent.trig_EF_trigmuonef_EF_2mu4T_Bmumu ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel( parent.trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly( parent.trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumux( parent.trig_EF_trigmuonef_EF_2mu4T_Bmumux ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel( parent.trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly( parent.trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu( parent.trig_EF_trigmuonef_EF_2mu4T_DiMu ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel( parent.trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly( parent.trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB( parent.trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC( parent.trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1( parent.trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1 ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA( parent.trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS( parent.trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS ),
        trig_EF_trigmuonef_EF_2mu4T_Jpsimumu( parent.trig_EF_trigmuonef_EF_2mu4T_Jpsimumu ),
        trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel( parent.trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel ),
        trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly( parent.trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly ),
        trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut( parent.trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut ),
        trig_EF_trigmuonef_EF_2mu4T_Upsimumu( parent.trig_EF_trigmuonef_EF_2mu4T_Upsimumu ),
        trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel( parent.trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel ),
        trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly( parent.trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly ),
        trig_EF_trigmuonef_EF_2mu4T_xe60( parent.trig_EF_trigmuonef_EF_2mu4T_xe60 ),
        trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw( parent.trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw ),
        trig_EF_trigmuonef_EF_2mu6( parent.trig_EF_trigmuonef_EF_2mu6 ),
        trig_EF_trigmuonef_EF_2mu6_Bmumu( parent.trig_EF_trigmuonef_EF_2mu6_Bmumu ),
        trig_EF_trigmuonef_EF_2mu6_Bmumux( parent.trig_EF_trigmuonef_EF_2mu6_Bmumux ),
        trig_EF_trigmuonef_EF_2mu6_DiMu( parent.trig_EF_trigmuonef_EF_2mu6_DiMu ),
        trig_EF_trigmuonef_EF_2mu6_DiMu_DY20( parent.trig_EF_trigmuonef_EF_2mu6_DiMu_DY20 ),
        trig_EF_trigmuonef_EF_2mu6_DiMu_DY25( parent.trig_EF_trigmuonef_EF_2mu6_DiMu_DY25 ),
        trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS( parent.trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS ),
        trig_EF_trigmuonef_EF_2mu6_Jpsimumu( parent.trig_EF_trigmuonef_EF_2mu6_Jpsimumu ),
        trig_EF_trigmuonef_EF_2mu6_Upsimumu( parent.trig_EF_trigmuonef_EF_2mu6_Upsimumu ),
        trig_EF_trigmuonef_EF_2mu6i_DiMu_DY( parent.trig_EF_trigmuonef_EF_2mu6i_DiMu_DY ),
        trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad( parent.trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad ),
        trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS( parent.trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS ),
        trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad( parent.trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad ),
        trig_EF_trigmuonef_EF_2mu8_EFxe30( parent.trig_EF_trigmuonef_EF_2mu8_EFxe30 ),
        trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw( parent.trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw ),
        trig_EF_trigmuonef_EF_mu10( parent.trig_EF_trigmuonef_EF_mu10 ),
        trig_EF_trigmuonef_EF_mu10_Jpsimumu( parent.trig_EF_trigmuonef_EF_mu10_Jpsimumu ),
        trig_EF_trigmuonef_EF_mu10_MSonly( parent.trig_EF_trigmuonef_EF_mu10_MSonly ),
        trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS( parent.trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS ),
        trig_EF_trigmuonef_EF_mu10i_g10_medium( parent.trig_EF_trigmuonef_EF_mu10i_g10_medium ),
        trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass( parent.trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass ),
        trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium( parent.trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium ),
        trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass( parent.trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass ),
        trig_EF_trigmuonef_EF_mu11_empty_NoAlg( parent.trig_EF_trigmuonef_EF_mu11_empty_NoAlg ),
        trig_EF_trigmuonef_EF_mu13( parent.trig_EF_trigmuonef_EF_mu13 ),
        trig_EF_trigmuonef_EF_mu15( parent.trig_EF_trigmuonef_EF_mu15 ),
        trig_EF_trigmuonef_EF_mu18( parent.trig_EF_trigmuonef_EF_mu18 ),
        trig_EF_trigmuonef_EF_mu18_2g10_loose( parent.trig_EF_trigmuonef_EF_mu18_2g10_loose ),
        trig_EF_trigmuonef_EF_mu18_2g10_medium( parent.trig_EF_trigmuonef_EF_mu18_2g10_medium ),
        trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight( parent.trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight ),
        trig_EF_trigmuonef_EF_mu18_medium( parent.trig_EF_trigmuonef_EF_mu18_medium ),
        trig_EF_trigmuonef_EF_mu18_tight( parent.trig_EF_trigmuonef_EF_mu18_tight ),
        trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS( parent.trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS ),
        trig_EF_trigmuonef_EF_mu18_tight_e7_medium1( parent.trig_EF_trigmuonef_EF_mu18_tight_e7_medium1 ),
        trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS( parent.trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS ),
        trig_EF_trigmuonef_EF_mu18i4_tight( parent.trig_EF_trigmuonef_EF_mu18i4_tight ),
        trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass( parent.trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass ),
        trig_EF_trigmuonef_EF_mu20i_tight_g5_medium( parent.trig_EF_trigmuonef_EF_mu20i_tight_g5_medium ),
        trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass( parent.trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass ),
        trig_EF_trigmuonef_EF_mu20it_tight( parent.trig_EF_trigmuonef_EF_mu20it_tight ),
        trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight( parent.trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight ),
        trig_EF_trigmuonef_EF_mu24( parent.trig_EF_trigmuonef_EF_mu24 ),
        trig_EF_trigmuonef_EF_mu24_g20vh_loose( parent.trig_EF_trigmuonef_EF_mu24_g20vh_loose ),
        trig_EF_trigmuonef_EF_mu24_g20vh_medium( parent.trig_EF_trigmuonef_EF_mu24_g20vh_medium ),
        trig_EF_trigmuonef_EF_mu24_j65_a4tchad( parent.trig_EF_trigmuonef_EF_mu24_j65_a4tchad ),
        trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40( parent.trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40 ),
        trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw( parent.trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw ),
        trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw( parent.trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw ),
        trig_EF_trigmuonef_EF_mu24_medium( parent.trig_EF_trigmuonef_EF_mu24_medium ),
        trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight( parent.trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight ),
        trig_EF_trigmuonef_EF_mu24_tight( parent.trig_EF_trigmuonef_EF_mu24_tight ),
        trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad( parent.trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad ),
        trig_EF_trigmuonef_EF_mu24_tight_EFxe40( parent.trig_EF_trigmuonef_EF_mu24_tight_EFxe40 ),
        trig_EF_trigmuonef_EF_mu24_tight_L2StarB( parent.trig_EF_trigmuonef_EF_mu24_tight_L2StarB ),
        trig_EF_trigmuonef_EF_mu24_tight_L2StarC( parent.trig_EF_trigmuonef_EF_mu24_tight_L2StarC ),
        trig_EF_trigmuonef_EF_mu24_tight_MG( parent.trig_EF_trigmuonef_EF_mu24_tight_MG ),
        trig_EF_trigmuonef_EF_mu24_tight_MuonEF( parent.trig_EF_trigmuonef_EF_mu24_tight_MuonEF ),
        trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad( parent.trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad ),
        trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS( parent.trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS ),
        trig_EF_trigmuonef_EF_mu24i_tight( parent.trig_EF_trigmuonef_EF_mu24i_tight ),
        trig_EF_trigmuonef_EF_mu24i_tight_MG( parent.trig_EF_trigmuonef_EF_mu24i_tight_MG ),
        trig_EF_trigmuonef_EF_mu24i_tight_MuonEF( parent.trig_EF_trigmuonef_EF_mu24i_tight_MuonEF ),
        trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA( parent.trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA ),
        trig_EF_trigmuonef_EF_mu36_tight( parent.trig_EF_trigmuonef_EF_mu36_tight ),
        trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight( parent.trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight ),
        trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF( parent.trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF ),
        trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight( parent.trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight ),
        trig_EF_trigmuonef_EF_mu40_slow_tight( parent.trig_EF_trigmuonef_EF_mu40_slow_tight ),
        trig_EF_trigmuonef_EF_mu40_tight( parent.trig_EF_trigmuonef_EF_mu40_tight ),
        trig_EF_trigmuonef_EF_mu4T( parent.trig_EF_trigmuonef_EF_mu4T ),
        trig_EF_trigmuonef_EF_mu4T_cosmic( parent.trig_EF_trigmuonef_EF_mu4T_cosmic ),
        trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched( parent.trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched ),
        trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched ),
        trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched( parent.trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched ),
        trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched ),
        trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched ),
        trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ( parent.trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ ),
        trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched( parent.trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched ),
        trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched ),
        trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched( parent.trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched ),
        trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched ),
        trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched ),
        trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ( parent.trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ ),
        trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched( parent.trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched ),
        trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched ),
        trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched ),
        trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ( parent.trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ ),
        trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched( parent.trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched ),
        trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ( parent.trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ ),
        trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched ),
        trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ( parent.trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ ),
        trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched( parent.trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched ),
        trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ( parent.trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ ),
        trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched ),
        trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ( parent.trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ ),
        trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched( parent.trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched ),
        trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched ),
        trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose( parent.trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose ),
        trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose( parent.trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose ),
        trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched( parent.trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched ),
        trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched( parent.trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched ),
        trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium( parent.trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium ),
        trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass( parent.trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu( parent.trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel( parent.trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux( parent.trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel( parent.trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel ),
        trig_EF_trigmuonef_EF_mu4Tmu6_DiMu( parent.trig_EF_trigmuonef_EF_mu4Tmu6_DiMu ),
        trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel( parent.trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel ),
        trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS( parent.trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu( parent.trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel( parent.trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut( parent.trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu( parent.trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel( parent.trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel ),
        trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic( parent.trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic ),
        trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic( parent.trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic ),
        trig_EF_trigmuonef_EF_mu4_empty_NoAlg( parent.trig_EF_trigmuonef_EF_mu4_empty_NoAlg ),
        trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg( parent.trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg ),
        trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg( parent.trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg ),
        trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight( parent.trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight ),
        trig_EF_trigmuonef_EF_mu6( parent.trig_EF_trigmuonef_EF_mu6 ),
        trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1( parent.trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1 ),
        trig_EF_trigmuonef_EF_mu60_slow_tight1( parent.trig_EF_trigmuonef_EF_mu60_slow_tight1 ),
        trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight( parent.trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight ),
        trig_EF_trigmuonef_EF_mu6_MSonly( parent.trig_EF_trigmuonef_EF_mu6_MSonly ),
        trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose( parent.trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose ),
        trig_EF_trigmuonef_EF_mu8( parent.trig_EF_trigmuonef_EF_mu8 ),
        trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS( parent.trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS ),
        trig_EF_trigmuonef_track_MuonType( parent.trig_EF_trigmuonef_track_MuonType ),
        trig_EF_trigmuonef_track_MS_pt( parent.trig_EF_trigmuonef_track_MS_pt ),
        trig_EF_trigmuonef_track_MS_eta( parent.trig_EF_trigmuonef_track_MS_eta ),
        trig_EF_trigmuonef_track_MS_phi( parent.trig_EF_trigmuonef_track_MS_phi ),
        trig_EF_trigmuonef_track_MS_hasMS( parent.trig_EF_trigmuonef_track_MS_hasMS ),
        trig_EF_trigmuonef_track_SA_pt( parent.trig_EF_trigmuonef_track_SA_pt ),
        trig_EF_trigmuonef_track_SA_eta( parent.trig_EF_trigmuonef_track_SA_eta ),
        trig_EF_trigmuonef_track_SA_phi( parent.trig_EF_trigmuonef_track_SA_phi ),
        trig_EF_trigmuonef_track_SA_hasSA( parent.trig_EF_trigmuonef_track_SA_hasSA ),
    
    // =============================================================================
    // = MC only
    // =============================================================================
        trig_EF_el_EF_e12Tvh_loose1_mu8( parent.trig_EF_el_EF_e12Tvh_loose1_mu8 ),
        trig_EF_el_EF_e12Tvh_medium1_mu10( parent.trig_EF_el_EF_e12Tvh_medium1_mu10 ),
        trig_EF_el_EF_e12Tvh_medium1_mu6( parent.trig_EF_el_EF_e12Tvh_medium1_mu6 ),
        trig_EF_el_EF_e18_loose1_g35_loose( parent.trig_EF_el_EF_e18_loose1_g35_loose ),
        trig_EF_el_EF_e18_loose1_g35_medium( parent.trig_EF_el_EF_e18_loose1_g35_medium ),
        trig_EF_el_EF_e18_medium1_g25_medium( parent.trig_EF_el_EF_e18_medium1_g25_medium ),
        trig_EF_el_EF_e18_medium1_g35_loose( parent.trig_EF_el_EF_e18_medium1_g35_loose ),
        trig_EF_el_EF_e18_medium1_g35_medium( parent.trig_EF_el_EF_e18_medium1_g35_medium ),
        trig_EF_el_EF_e22vh_medium1_IdScan( parent.trig_EF_el_EF_e22vh_medium1_IdScan ),
        trig_EF_el_EF_e22vh_medium1_SiTrk( parent.trig_EF_el_EF_e22vh_medium1_SiTrk ),
        trig_EF_el_EF_e22vh_medium1_TRT( parent.trig_EF_el_EF_e22vh_medium1_TRT ),
        trig_EF_el_EF_e45_etcut( parent.trig_EF_el_EF_e45_etcut ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan( parent.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk( parent.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT( parent.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT ),
        trig_EF_el_EF_e60_etcut( parent.trig_EF_el_EF_e60_etcut )
    
  
 {

   }

   /**
    * This constructor should be used when the object will be used to read
    * variables from an existing ntuple. The object will also be able to
    * output variables, but it will also need to read them from somewhere.
    *
    * @param master Reference to the variable holding the current event number
    * @param prefix Prefix of the variables in the D3PD
    */
   TriggerVecD3PDObject::TriggerVecD3PDObject( const ::Long64_t& master, const char* prefix )
      : TObject(),
        trig_EF_el_EF_2e12Tvh_loose1( this, ::TString( prefix ) + "trig_EF_el_EF_2e12Tvh_loose1", &master ),
        trig_EF_el_EF_2e5_tight1_Jpsi( this, ::TString( prefix ) + "trig_EF_el_EF_2e5_tight1_Jpsi", &master ),
        trig_EF_el_EF_2e7T_loose1_mu6( this, ::TString( prefix ) + "trig_EF_el_EF_2e7T_loose1_mu6", &master ),
        trig_EF_el_EF_2e7T_medium1_mu6( this, ::TString( prefix ) + "trig_EF_el_EF_2e7T_medium1_mu6", &master ),
        trig_EF_el_EF_e11_etcut( this, ::TString( prefix ) + "trig_EF_el_EF_e11_etcut", &master ),
        trig_EF_el_EF_e12Tvh_loose1( this, ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_loose1", &master ),
        trig_EF_el_EF_e12Tvh_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_medium1", &master ),
        trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium( this, ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium", &master ),
        trig_EF_el_EF_e12Tvh_medium1_mu8( this, ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_medium1_mu8", &master ),
        trig_EF_el_EF_e13_etcutTrk_xs60( this, ::TString( prefix ) + "trig_EF_el_EF_e13_etcutTrk_xs60", &master ),
        trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20( this, ::TString( prefix ) + "trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20", &master ),
        trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi( this, ::TString( prefix ) + "trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi", &master ),
        trig_EF_el_EF_e15vh_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e15vh_medium1", &master ),
        trig_EF_el_EF_e18_loose1( this, ::TString( prefix ) + "trig_EF_el_EF_e18_loose1", &master ),
        trig_EF_el_EF_e18_loose1_g25_medium( this, ::TString( prefix ) + "trig_EF_el_EF_e18_loose1_g25_medium", &master ),
        trig_EF_el_EF_e18_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e18_medium1", &master ),
        trig_EF_el_EF_e18_medium1_g25_loose( this, ::TString( prefix ) + "trig_EF_el_EF_e18_medium1_g25_loose", &master ),
        trig_EF_el_EF_e18vh_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e18vh_medium1", &master ),
        trig_EF_el_EF_e18vh_medium1_2e7T_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e18vh_medium1_2e7T_medium1", &master ),
        trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20( this, ::TString( prefix ) + "trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20", &master ),
        trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20( this, ::TString( prefix ) + "trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20", &master ),
        trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi( this, ::TString( prefix ) + "trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi", &master ),
        trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi( this, ::TString( prefix ) + "trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi", &master ),
        trig_EF_el_EF_e22vh_loose( this, ::TString( prefix ) + "trig_EF_el_EF_e22vh_loose", &master ),
        trig_EF_el_EF_e22vh_loose0( this, ::TString( prefix ) + "trig_EF_el_EF_e22vh_loose0", &master ),
        trig_EF_el_EF_e22vh_loose1( this, ::TString( prefix ) + "trig_EF_el_EF_e22vh_loose1", &master ),
        trig_EF_el_EF_e22vh_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e22vh_medium1", &master ),
        trig_EF_el_EF_e22vh_medium1_IDTrkNoCut( this, ::TString( prefix ) + "trig_EF_el_EF_e22vh_medium1_IDTrkNoCut", &master ),
        trig_EF_el_EF_e22vhi_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e22vhi_medium1", &master ),
        trig_EF_el_EF_e24vh_loose( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_loose", &master ),
        trig_EF_el_EF_e24vh_loose0( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_loose0", &master ),
        trig_EF_el_EF_e24vh_loose1( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_loose1", &master ),
        trig_EF_el_EF_e24vh_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1", &master ),
        trig_EF_el_EF_e24vh_medium1_EFxe30( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_EFxe30", &master ),
        trig_EF_el_EF_e24vh_medium1_EFxe30_tcem( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_EFxe30_tcem", &master ),
        trig_EF_el_EF_e24vh_medium1_EFxe35_tcem( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_EFxe35_tcem", &master ),
        trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw", &master ),
        trig_EF_el_EF_e24vh_medium1_EFxe40( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_EFxe40", &master ),
        trig_EF_el_EF_e24vh_medium1_IDTrkNoCut( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_IDTrkNoCut", &master ),
        trig_EF_el_EF_e24vh_medium1_IdScan( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_IdScan", &master ),
        trig_EF_el_EF_e24vh_medium1_L2StarB( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_L2StarB", &master ),
        trig_EF_el_EF_e24vh_medium1_L2StarC( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_L2StarC", &master ),
        trig_EF_el_EF_e24vh_medium1_SiTrk( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_SiTrk", &master ),
        trig_EF_el_EF_e24vh_medium1_TRT( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_TRT", &master ),
        trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad", &master ),
        trig_EF_el_EF_e24vh_medium1_e7_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_e7_medium1", &master ),
        trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee", &master ),
        trig_EF_el_EF_e24vhi_loose1_mu8( this, ::TString( prefix ) + "trig_EF_el_EF_e24vhi_loose1_mu8", &master ),
        trig_EF_el_EF_e24vhi_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e24vhi_medium1", &master ),
        trig_EF_el_EF_e45_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e45_medium1", &master ),
        trig_EF_el_EF_e5_tight1( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1", &master ),
        trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi", &master ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi", &master ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB", &master ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC", &master ),
        trig_EF_el_EF_e5_tight1_e5_NoCut( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e5_NoCut", &master ),
        trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi", &master ),
        trig_EF_el_EF_e60_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e60_medium1", &master ),
        trig_EF_el_EF_e7T_loose1( this, ::TString( prefix ) + "trig_EF_el_EF_e7T_loose1", &master ),
        trig_EF_el_EF_e7T_loose1_2mu6( this, ::TString( prefix ) + "trig_EF_el_EF_e7T_loose1_2mu6", &master ),
        trig_EF_el_EF_e7T_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e7T_medium1", &master ),
        trig_EF_el_EF_e7T_medium1_2mu6( this, ::TString( prefix ) + "trig_EF_el_EF_e7T_medium1_2mu6", &master ),
        trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi( this, ::TString( prefix ) + "trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi", &master ),
        trig_EF_el_EF_eb_physics( this, ::TString( prefix ) + "trig_EF_el_EF_eb_physics", &master ),
        trig_EF_el_EF_eb_physics_empty( this, ::TString( prefix ) + "trig_EF_el_EF_eb_physics_empty", &master ),
        trig_EF_el_EF_eb_physics_firstempty( this, ::TString( prefix ) + "trig_EF_el_EF_eb_physics_firstempty", &master ),
        trig_EF_el_EF_eb_physics_noL1PS( this, ::TString( prefix ) + "trig_EF_el_EF_eb_physics_noL1PS", &master ),
        trig_EF_el_EF_eb_physics_unpaired_iso( this, ::TString( prefix ) + "trig_EF_el_EF_eb_physics_unpaired_iso", &master ),
        trig_EF_el_EF_eb_physics_unpaired_noniso( this, ::TString( prefix ) + "trig_EF_el_EF_eb_physics_unpaired_noniso", &master ),
        trig_EF_el_EF_eb_random( this, ::TString( prefix ) + "trig_EF_el_EF_eb_random", &master ),
        trig_EF_el_EF_eb_random_empty( this, ::TString( prefix ) + "trig_EF_el_EF_eb_random_empty", &master ),
        trig_EF_el_EF_eb_random_firstempty( this, ::TString( prefix ) + "trig_EF_el_EF_eb_random_firstempty", &master ),
        trig_EF_el_EF_eb_random_unpaired_iso( this, ::TString( prefix ) + "trig_EF_el_EF_eb_random_unpaired_iso", &master ),
        trig_EF_emcl_pt( this, ::TString( prefix ) + "trig_EF_emcl_pt", &master ),
        trig_EF_emcl_eta( this, ::TString( prefix ) + "trig_EF_emcl_eta", &master ),
        trig_EF_emcl_phi( this, ::TString( prefix ) + "trig_EF_emcl_phi", &master ),
        trig_EF_emcl_E_em( this, ::TString( prefix ) + "trig_EF_emcl_E_em", &master ),
        trig_EF_emcl_E_had( this, ::TString( prefix ) + "trig_EF_emcl_E_had", &master ),
        trig_EF_emcl_slw_pt( this, ::TString( prefix ) + "trig_EF_emcl_slw_pt", &master ),
        trig_EF_emcl_slw_eta( this, ::TString( prefix ) + "trig_EF_emcl_slw_eta", &master ),
        trig_EF_emcl_slw_phi( this, ::TString( prefix ) + "trig_EF_emcl_slw_phi", &master ),
        trig_EF_emcl_slw_E_em( this, ::TString( prefix ) + "trig_EF_emcl_slw_E_em", &master ),
        trig_EF_emcl_slw_E_had( this, ::TString( prefix ) + "trig_EF_emcl_slw_E_had", &master ),
        trig_EF_el_E( this, ::TString( prefix ) + "trig_EF_el_E", &master ),
        trig_EF_el_Et( this, ::TString( prefix ) + "trig_EF_el_Et", &master ),
        trig_EF_el_pt( this, ::TString( prefix ) + "trig_EF_el_pt", &master ),
        trig_EF_el_m( this, ::TString( prefix ) + "trig_EF_el_m", &master ),
        trig_EF_el_eta( this, ::TString( prefix ) + "trig_EF_el_eta", &master ),
        trig_EF_el_phi( this, ::TString( prefix ) + "trig_EF_el_phi", &master ),
        trig_EF_el_px( this, ::TString( prefix ) + "trig_EF_el_px", &master ),
        trig_EF_el_py( this, ::TString( prefix ) + "trig_EF_el_py", &master ),
        trig_EF_el_pz( this, ::TString( prefix ) + "trig_EF_el_pz", &master ),
        trig_EF_el_charge( this, ::TString( prefix ) + "trig_EF_el_charge", &master ),
        trig_EF_el_author( this, ::TString( prefix ) + "trig_EF_el_author", &master ),
        trig_EF_el_isEM( this, ::TString( prefix ) + "trig_EF_el_isEM", &master ),
        trig_EF_el_isEMLoose( this, ::TString( prefix ) + "trig_EF_el_isEMLoose", &master ),
        trig_EF_el_isEMMedium( this, ::TString( prefix ) + "trig_EF_el_isEMMedium", &master ),
        trig_EF_el_isEMTight( this, ::TString( prefix ) + "trig_EF_el_isEMTight", &master ),
        trig_EF_el_loose( this, ::TString( prefix ) + "trig_EF_el_loose", &master ),
        trig_EF_el_looseIso( this, ::TString( prefix ) + "trig_EF_el_looseIso", &master ),
        trig_EF_el_medium( this, ::TString( prefix ) + "trig_EF_el_medium", &master ),
        trig_EF_el_mediumIso( this, ::TString( prefix ) + "trig_EF_el_mediumIso", &master ),
        trig_EF_el_mediumWithoutTrack( this, ::TString( prefix ) + "trig_EF_el_mediumWithoutTrack", &master ),
        trig_EF_el_mediumIsoWithoutTrack( this, ::TString( prefix ) + "trig_EF_el_mediumIsoWithoutTrack", &master ),
        trig_EF_el_tight( this, ::TString( prefix ) + "trig_EF_el_tight", &master ),
        trig_EF_el_tightIso( this, ::TString( prefix ) + "trig_EF_el_tightIso", &master ),
        trig_EF_el_tightWithoutTrack( this, ::TString( prefix ) + "trig_EF_el_tightWithoutTrack", &master ),
        trig_EF_el_tightIsoWithoutTrack( this, ::TString( prefix ) + "trig_EF_el_tightIsoWithoutTrack", &master ),
        trig_EF_el_loosePP( this, ::TString( prefix ) + "trig_EF_el_loosePP", &master ),
        trig_EF_el_loosePPIso( this, ::TString( prefix ) + "trig_EF_el_loosePPIso", &master ),
        trig_EF_el_mediumPP( this, ::TString( prefix ) + "trig_EF_el_mediumPP", &master ),
        trig_EF_el_mediumPPIso( this, ::TString( prefix ) + "trig_EF_el_mediumPPIso", &master ),
        trig_EF_el_tightPP( this, ::TString( prefix ) + "trig_EF_el_tightPP", &master ),
        trig_EF_el_tightPPIso( this, ::TString( prefix ) + "trig_EF_el_tightPPIso", &master ),
        trig_EF_el_vertweight( this, ::TString( prefix ) + "trig_EF_el_vertweight", &master ),
        trig_EF_el_hastrack( this, ::TString( prefix ) + "trig_EF_el_hastrack", &master ),
        trig_EF_trigmuonef_track_CB_pt( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_pt", &master ),
        trig_EF_trigmuonef_track_CB_eta( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_eta", &master ),
        trig_EF_trigmuonef_track_CB_phi( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_phi", &master ),
        trig_EF_trigmuonef_track_CB_hasCB( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_hasCB", &master ),

    // =============================================================================
    // = Data only
    // =============================================================================
        trig_EF_trigmuonef_EF_2mu10( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu10", &master ),
        trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose", &master ),
        trig_EF_trigmuonef_EF_2mu13( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu13", &master ),
        trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut", &master ),
        trig_EF_trigmuonef_EF_2mu13_l2muonSA( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu13_l2muonSA", &master ),
        trig_EF_trigmuonef_EF_2mu15( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu15", &master ),
        trig_EF_trigmuonef_EF_2mu4T( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T", &master ),
        trig_EF_trigmuonef_EF_2mu4T_2e5_tight1( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_2e5_tight1", &master ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Bmumu", &master ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel", &master ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly", &master ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumux( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Bmumux", &master ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel", &master ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly", &master ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu", &master ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel", &master ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly", &master ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB", &master ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC", &master ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1", &master ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA", &master ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS", &master ),
        trig_EF_trigmuonef_EF_2mu4T_Jpsimumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu", &master ),
        trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel", &master ),
        trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly", &master ),
        trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut", &master ),
        trig_EF_trigmuonef_EF_2mu4T_Upsimumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Upsimumu", &master ),
        trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel", &master ),
        trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly", &master ),
        trig_EF_trigmuonef_EF_2mu4T_xe60( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_xe60", &master ),
        trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw", &master ),
        trig_EF_trigmuonef_EF_2mu6( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6", &master ),
        trig_EF_trigmuonef_EF_2mu6_Bmumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_Bmumu", &master ),
        trig_EF_trigmuonef_EF_2mu6_Bmumux( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_Bmumux", &master ),
        trig_EF_trigmuonef_EF_2mu6_DiMu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_DiMu", &master ),
        trig_EF_trigmuonef_EF_2mu6_DiMu_DY20( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_DiMu_DY20", &master ),
        trig_EF_trigmuonef_EF_2mu6_DiMu_DY25( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_DiMu_DY25", &master ),
        trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS", &master ),
        trig_EF_trigmuonef_EF_2mu6_Jpsimumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_Jpsimumu", &master ),
        trig_EF_trigmuonef_EF_2mu6_Upsimumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_Upsimumu", &master ),
        trig_EF_trigmuonef_EF_2mu6i_DiMu_DY( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY", &master ),
        trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad", &master ),
        trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS", &master ),
        trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad", &master ),
        trig_EF_trigmuonef_EF_2mu8_EFxe30( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu8_EFxe30", &master ),
        trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw", &master ),
        trig_EF_trigmuonef_EF_mu10( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10", &master ),
        trig_EF_trigmuonef_EF_mu10_Jpsimumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10_Jpsimumu", &master ),
        trig_EF_trigmuonef_EF_mu10_MSonly( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10_MSonly", &master ),
        trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS", &master ),
        trig_EF_trigmuonef_EF_mu10i_g10_medium( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10i_g10_medium", &master ),
        trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass", &master ),
        trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium", &master ),
        trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass", &master ),
        trig_EF_trigmuonef_EF_mu11_empty_NoAlg( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu11_empty_NoAlg", &master ),
        trig_EF_trigmuonef_EF_mu13( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu13", &master ),
        trig_EF_trigmuonef_EF_mu15( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu15", &master ),
        trig_EF_trigmuonef_EF_mu18( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18", &master ),
        trig_EF_trigmuonef_EF_mu18_2g10_loose( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_2g10_loose", &master ),
        trig_EF_trigmuonef_EF_mu18_2g10_medium( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_2g10_medium", &master ),
        trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight", &master ),
        trig_EF_trigmuonef_EF_mu18_medium( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_medium", &master ),
        trig_EF_trigmuonef_EF_mu18_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_tight", &master ),
        trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS", &master ),
        trig_EF_trigmuonef_EF_mu18_tight_e7_medium1( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_tight_e7_medium1", &master ),
        trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS", &master ),
        trig_EF_trigmuonef_EF_mu18i4_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18i4_tight", &master ),
        trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass", &master ),
        trig_EF_trigmuonef_EF_mu20i_tight_g5_medium( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu20i_tight_g5_medium", &master ),
        trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass", &master ),
        trig_EF_trigmuonef_EF_mu20it_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu20it_tight", &master ),
        trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight", &master ),
        trig_EF_trigmuonef_EF_mu24( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24", &master ),
        trig_EF_trigmuonef_EF_mu24_g20vh_loose( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_g20vh_loose", &master ),
        trig_EF_trigmuonef_EF_mu24_g20vh_medium( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_g20vh_medium", &master ),
        trig_EF_trigmuonef_EF_mu24_j65_a4tchad( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_j65_a4tchad", &master ),
        trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40", &master ),
        trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw", &master ),
        trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw", &master ),
        trig_EF_trigmuonef_EF_mu24_medium( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_medium", &master ),
        trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight", &master ),
        trig_EF_trigmuonef_EF_mu24_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight", &master ),
        trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad", &master ),
        trig_EF_trigmuonef_EF_mu24_tight_EFxe40( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_EFxe40", &master ),
        trig_EF_trigmuonef_EF_mu24_tight_L2StarB( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_L2StarB", &master ),
        trig_EF_trigmuonef_EF_mu24_tight_L2StarC( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_L2StarC", &master ),
        trig_EF_trigmuonef_EF_mu24_tight_MG( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_MG", &master ),
        trig_EF_trigmuonef_EF_mu24_tight_MuonEF( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_MuonEF", &master ),
        trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad", &master ),
        trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS", &master ),
        trig_EF_trigmuonef_EF_mu24i_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24i_tight", &master ),
        trig_EF_trigmuonef_EF_mu24i_tight_MG( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24i_tight_MG", &master ),
        trig_EF_trigmuonef_EF_mu24i_tight_MuonEF( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24i_tight_MuonEF", &master ),
        trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA", &master ),
        trig_EF_trigmuonef_EF_mu36_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu36_tight", &master ),
        trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight", &master ),
        trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF", &master ),
        trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight", &master ),
        trig_EF_trigmuonef_EF_mu40_slow_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu40_slow_tight", &master ),
        trig_EF_trigmuonef_EF_mu40_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu40_tight", &master ),
        trig_EF_trigmuonef_EF_mu4T( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T", &master ),
        trig_EF_trigmuonef_EF_mu4T_cosmic( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_cosmic", &master ),
        trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ", &master ),
        trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ", &master ),
        trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ", &master ),
        trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ", &master ),
        trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ", &master ),
        trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ", &master ),
        trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ", &master ),
        trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose", &master ),
        trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose", &master ),
        trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched", &master ),
        trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched", &master ),
        trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium", &master ),
        trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass", &master ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu", &master ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel", &master ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux", &master ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel", &master ),
        trig_EF_trigmuonef_EF_mu4Tmu6_DiMu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_DiMu", &master ),
        trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel", &master ),
        trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS", &master ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu", &master ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel", &master ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut", &master ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu", &master ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel", &master ),
        trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic", &master ),
        trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic", &master ),
        trig_EF_trigmuonef_EF_mu4_empty_NoAlg( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4_empty_NoAlg", &master ),
        trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg", &master ),
        trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg", &master ),
        trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight", &master ),
        trig_EF_trigmuonef_EF_mu6( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu6", &master ),
        trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1", &master ),
        trig_EF_trigmuonef_EF_mu60_slow_tight1( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu60_slow_tight1", &master ),
        trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight", &master ),
        trig_EF_trigmuonef_EF_mu6_MSonly( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu6_MSonly", &master ),
        trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose", &master ),
        trig_EF_trigmuonef_EF_mu8( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu8", &master ),
        trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS", &master ),
        trig_EF_trigmuonef_track_MuonType( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_MuonType", &master ),
        trig_EF_trigmuonef_track_MS_pt( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_MS_pt", &master ),
        trig_EF_trigmuonef_track_MS_eta( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_MS_eta", &master ),
        trig_EF_trigmuonef_track_MS_phi( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_MS_phi", &master ),
        trig_EF_trigmuonef_track_MS_hasMS( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_MS_hasMS", &master ),
        trig_EF_trigmuonef_track_SA_pt( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_SA_pt", &master ),
        trig_EF_trigmuonef_track_SA_eta( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_SA_eta", &master ),
        trig_EF_trigmuonef_track_SA_phi( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_SA_phi", &master ),
        trig_EF_trigmuonef_track_SA_hasSA( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_SA_hasSA", &master ),
    
    // =============================================================================
    // = MC only
    // =============================================================================
        trig_EF_el_EF_e12Tvh_loose1_mu8( this, ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_loose1_mu8", &master ),
        trig_EF_el_EF_e12Tvh_medium1_mu10( this, ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_medium1_mu10", &master ),
        trig_EF_el_EF_e12Tvh_medium1_mu6( this, ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_medium1_mu6", &master ),
        trig_EF_el_EF_e18_loose1_g35_loose( this, ::TString( prefix ) + "trig_EF_el_EF_e18_loose1_g35_loose", &master ),
        trig_EF_el_EF_e18_loose1_g35_medium( this, ::TString( prefix ) + "trig_EF_el_EF_e18_loose1_g35_medium", &master ),
        trig_EF_el_EF_e18_medium1_g25_medium( this, ::TString( prefix ) + "trig_EF_el_EF_e18_medium1_g25_medium", &master ),
        trig_EF_el_EF_e18_medium1_g35_loose( this, ::TString( prefix ) + "trig_EF_el_EF_e18_medium1_g35_loose", &master ),
        trig_EF_el_EF_e18_medium1_g35_medium( this, ::TString( prefix ) + "trig_EF_el_EF_e18_medium1_g35_medium", &master ),
        trig_EF_el_EF_e22vh_medium1_IdScan( this, ::TString( prefix ) + "trig_EF_el_EF_e22vh_medium1_IdScan", &master ),
        trig_EF_el_EF_e22vh_medium1_SiTrk( this, ::TString( prefix ) + "trig_EF_el_EF_e22vh_medium1_SiTrk", &master ),
        trig_EF_el_EF_e22vh_medium1_TRT( this, ::TString( prefix ) + "trig_EF_el_EF_e22vh_medium1_TRT", &master ),
        trig_EF_el_EF_e45_etcut( this, ::TString( prefix ) + "trig_EF_el_EF_e45_etcut", &master ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan", &master ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk", &master ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT", &master ),
        trig_EF_el_EF_e60_etcut( this, ::TString( prefix ) + "trig_EF_el_EF_e60_etcut", &master ),
    
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) {

      fHandles[ "trig_EF_el_EF_2e12Tvh_loose1" ] = &trig_EF_el_EF_2e12Tvh_loose1;
      fHandles[ "trig_EF_el_EF_2e5_tight1_Jpsi" ] = &trig_EF_el_EF_2e5_tight1_Jpsi;
      fHandles[ "trig_EF_el_EF_2e7T_loose1_mu6" ] = &trig_EF_el_EF_2e7T_loose1_mu6;
      fHandles[ "trig_EF_el_EF_2e7T_medium1_mu6" ] = &trig_EF_el_EF_2e7T_medium1_mu6;
      fHandles[ "trig_EF_el_EF_e11_etcut" ] = &trig_EF_el_EF_e11_etcut;
      fHandles[ "trig_EF_el_EF_e12Tvh_loose1" ] = &trig_EF_el_EF_e12Tvh_loose1;
      fHandles[ "trig_EF_el_EF_e12Tvh_medium1" ] = &trig_EF_el_EF_e12Tvh_medium1;
      fHandles[ "trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium" ] = &trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium;
      fHandles[ "trig_EF_el_EF_e12Tvh_medium1_mu8" ] = &trig_EF_el_EF_e12Tvh_medium1_mu8;
      fHandles[ "trig_EF_el_EF_e13_etcutTrk_xs60" ] = &trig_EF_el_EF_e13_etcutTrk_xs60;
      fHandles[ "trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20" ] = &trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20;
      fHandles[ "trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi" ] = &trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi;
      fHandles[ "trig_EF_el_EF_e15vh_medium1" ] = &trig_EF_el_EF_e15vh_medium1;
      fHandles[ "trig_EF_el_EF_e18_loose1" ] = &trig_EF_el_EF_e18_loose1;
      fHandles[ "trig_EF_el_EF_e18_loose1_g25_medium" ] = &trig_EF_el_EF_e18_loose1_g25_medium;
      fHandles[ "trig_EF_el_EF_e18_medium1" ] = &trig_EF_el_EF_e18_medium1;
      fHandles[ "trig_EF_el_EF_e18_medium1_g25_loose" ] = &trig_EF_el_EF_e18_medium1_g25_loose;
      fHandles[ "trig_EF_el_EF_e18vh_medium1" ] = &trig_EF_el_EF_e18vh_medium1;
      fHandles[ "trig_EF_el_EF_e18vh_medium1_2e7T_medium1" ] = &trig_EF_el_EF_e18vh_medium1_2e7T_medium1;
      fHandles[ "trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20" ] = &trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20;
      fHandles[ "trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20" ] = &trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20;
      fHandles[ "trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi" ] = &trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi;
      fHandles[ "trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi" ] = &trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi;
      fHandles[ "trig_EF_el_EF_e22vh_loose" ] = &trig_EF_el_EF_e22vh_loose;
      fHandles[ "trig_EF_el_EF_e22vh_loose0" ] = &trig_EF_el_EF_e22vh_loose0;
      fHandles[ "trig_EF_el_EF_e22vh_loose1" ] = &trig_EF_el_EF_e22vh_loose1;
      fHandles[ "trig_EF_el_EF_e22vh_medium1" ] = &trig_EF_el_EF_e22vh_medium1;
      fHandles[ "trig_EF_el_EF_e22vh_medium1_IDTrkNoCut" ] = &trig_EF_el_EF_e22vh_medium1_IDTrkNoCut;
      fHandles[ "trig_EF_el_EF_e22vhi_medium1" ] = &trig_EF_el_EF_e22vhi_medium1;
      fHandles[ "trig_EF_el_EF_e24vh_loose" ] = &trig_EF_el_EF_e24vh_loose;
      fHandles[ "trig_EF_el_EF_e24vh_loose0" ] = &trig_EF_el_EF_e24vh_loose0;
      fHandles[ "trig_EF_el_EF_e24vh_loose1" ] = &trig_EF_el_EF_e24vh_loose1;
      fHandles[ "trig_EF_el_EF_e24vh_medium1" ] = &trig_EF_el_EF_e24vh_medium1;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_EFxe30" ] = &trig_EF_el_EF_e24vh_medium1_EFxe30;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_EFxe30_tcem" ] = &trig_EF_el_EF_e24vh_medium1_EFxe30_tcem;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_EFxe35_tcem" ] = &trig_EF_el_EF_e24vh_medium1_EFxe35_tcem;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw" ] = &trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_EFxe40" ] = &trig_EF_el_EF_e24vh_medium1_EFxe40;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_IDTrkNoCut" ] = &trig_EF_el_EF_e24vh_medium1_IDTrkNoCut;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_IdScan" ] = &trig_EF_el_EF_e24vh_medium1_IdScan;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_L2StarB" ] = &trig_EF_el_EF_e24vh_medium1_L2StarB;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_L2StarC" ] = &trig_EF_el_EF_e24vh_medium1_L2StarC;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_SiTrk" ] = &trig_EF_el_EF_e24vh_medium1_SiTrk;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_TRT" ] = &trig_EF_el_EF_e24vh_medium1_TRT;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad" ] = &trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_e7_medium1" ] = &trig_EF_el_EF_e24vh_medium1_e7_medium1;
      fHandles[ "trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee" ] = &trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee;
      fHandles[ "trig_EF_el_EF_e24vhi_loose1_mu8" ] = &trig_EF_el_EF_e24vhi_loose1_mu8;
      fHandles[ "trig_EF_el_EF_e24vhi_medium1" ] = &trig_EF_el_EF_e24vhi_medium1;
      fHandles[ "trig_EF_el_EF_e45_medium1" ] = &trig_EF_el_EF_e45_medium1;
      fHandles[ "trig_EF_el_EF_e5_tight1" ] = &trig_EF_el_EF_e5_tight1;
      fHandles[ "trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi" ] = &trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi;
      fHandles[ "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi" ] = &trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi;
      fHandles[ "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB" ] = &trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB;
      fHandles[ "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC" ] = &trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC;
      fHandles[ "trig_EF_el_EF_e5_tight1_e5_NoCut" ] = &trig_EF_el_EF_e5_tight1_e5_NoCut;
      fHandles[ "trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi" ] = &trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi;
      fHandles[ "trig_EF_el_EF_e60_medium1" ] = &trig_EF_el_EF_e60_medium1;
      fHandles[ "trig_EF_el_EF_e7T_loose1" ] = &trig_EF_el_EF_e7T_loose1;
      fHandles[ "trig_EF_el_EF_e7T_loose1_2mu6" ] = &trig_EF_el_EF_e7T_loose1_2mu6;
      fHandles[ "trig_EF_el_EF_e7T_medium1" ] = &trig_EF_el_EF_e7T_medium1;
      fHandles[ "trig_EF_el_EF_e7T_medium1_2mu6" ] = &trig_EF_el_EF_e7T_medium1_2mu6;
      fHandles[ "trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi" ] = &trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi;
      fHandles[ "trig_EF_el_EF_eb_physics" ] = &trig_EF_el_EF_eb_physics;
      fHandles[ "trig_EF_el_EF_eb_physics_empty" ] = &trig_EF_el_EF_eb_physics_empty;
      fHandles[ "trig_EF_el_EF_eb_physics_firstempty" ] = &trig_EF_el_EF_eb_physics_firstempty;
      fHandles[ "trig_EF_el_EF_eb_physics_noL1PS" ] = &trig_EF_el_EF_eb_physics_noL1PS;
      fHandles[ "trig_EF_el_EF_eb_physics_unpaired_iso" ] = &trig_EF_el_EF_eb_physics_unpaired_iso;
      fHandles[ "trig_EF_el_EF_eb_physics_unpaired_noniso" ] = &trig_EF_el_EF_eb_physics_unpaired_noniso;
      fHandles[ "trig_EF_el_EF_eb_random" ] = &trig_EF_el_EF_eb_random;
      fHandles[ "trig_EF_el_EF_eb_random_empty" ] = &trig_EF_el_EF_eb_random_empty;
      fHandles[ "trig_EF_el_EF_eb_random_firstempty" ] = &trig_EF_el_EF_eb_random_firstempty;
      fHandles[ "trig_EF_el_EF_eb_random_unpaired_iso" ] = &trig_EF_el_EF_eb_random_unpaired_iso;
      fHandles[ "trig_EF_emcl_pt" ] = &trig_EF_emcl_pt;
      fHandles[ "trig_EF_emcl_eta" ] = &trig_EF_emcl_eta;
      fHandles[ "trig_EF_emcl_phi" ] = &trig_EF_emcl_phi;
      fHandles[ "trig_EF_emcl_E_em" ] = &trig_EF_emcl_E_em;
      fHandles[ "trig_EF_emcl_E_had" ] = &trig_EF_emcl_E_had;
      fHandles[ "trig_EF_emcl_slw_pt" ] = &trig_EF_emcl_slw_pt;
      fHandles[ "trig_EF_emcl_slw_eta" ] = &trig_EF_emcl_slw_eta;
      fHandles[ "trig_EF_emcl_slw_phi" ] = &trig_EF_emcl_slw_phi;
      fHandles[ "trig_EF_emcl_slw_E_em" ] = &trig_EF_emcl_slw_E_em;
      fHandles[ "trig_EF_emcl_slw_E_had" ] = &trig_EF_emcl_slw_E_had;
      fHandles[ "trig_EF_el_E" ] = &trig_EF_el_E;
      fHandles[ "trig_EF_el_Et" ] = &trig_EF_el_Et;
      fHandles[ "trig_EF_el_pt" ] = &trig_EF_el_pt;
      fHandles[ "trig_EF_el_m" ] = &trig_EF_el_m;
      fHandles[ "trig_EF_el_eta" ] = &trig_EF_el_eta;
      fHandles[ "trig_EF_el_phi" ] = &trig_EF_el_phi;
      fHandles[ "trig_EF_el_px" ] = &trig_EF_el_px;
      fHandles[ "trig_EF_el_py" ] = &trig_EF_el_py;
      fHandles[ "trig_EF_el_pz" ] = &trig_EF_el_pz;
      fHandles[ "trig_EF_el_charge" ] = &trig_EF_el_charge;
      fHandles[ "trig_EF_el_author" ] = &trig_EF_el_author;
      fHandles[ "trig_EF_el_isEM" ] = &trig_EF_el_isEM;
      fHandles[ "trig_EF_el_isEMLoose" ] = &trig_EF_el_isEMLoose;
      fHandles[ "trig_EF_el_isEMMedium" ] = &trig_EF_el_isEMMedium;
      fHandles[ "trig_EF_el_isEMTight" ] = &trig_EF_el_isEMTight;
      fHandles[ "trig_EF_el_loose" ] = &trig_EF_el_loose;
      fHandles[ "trig_EF_el_looseIso" ] = &trig_EF_el_looseIso;
      fHandles[ "trig_EF_el_medium" ] = &trig_EF_el_medium;
      fHandles[ "trig_EF_el_mediumIso" ] = &trig_EF_el_mediumIso;
      fHandles[ "trig_EF_el_mediumWithoutTrack" ] = &trig_EF_el_mediumWithoutTrack;
      fHandles[ "trig_EF_el_mediumIsoWithoutTrack" ] = &trig_EF_el_mediumIsoWithoutTrack;
      fHandles[ "trig_EF_el_tight" ] = &trig_EF_el_tight;
      fHandles[ "trig_EF_el_tightIso" ] = &trig_EF_el_tightIso;
      fHandles[ "trig_EF_el_tightWithoutTrack" ] = &trig_EF_el_tightWithoutTrack;
      fHandles[ "trig_EF_el_tightIsoWithoutTrack" ] = &trig_EF_el_tightIsoWithoutTrack;
      fHandles[ "trig_EF_el_loosePP" ] = &trig_EF_el_loosePP;
      fHandles[ "trig_EF_el_loosePPIso" ] = &trig_EF_el_loosePPIso;
      fHandles[ "trig_EF_el_mediumPP" ] = &trig_EF_el_mediumPP;
      fHandles[ "trig_EF_el_mediumPPIso" ] = &trig_EF_el_mediumPPIso;
      fHandles[ "trig_EF_el_tightPP" ] = &trig_EF_el_tightPP;
      fHandles[ "trig_EF_el_tightPPIso" ] = &trig_EF_el_tightPPIso;
      fHandles[ "trig_EF_el_vertweight" ] = &trig_EF_el_vertweight;
      fHandles[ "trig_EF_el_hastrack" ] = &trig_EF_el_hastrack;
      fHandles[ "trig_EF_trigmuonef_track_CB_pt" ] = &trig_EF_trigmuonef_track_CB_pt;
      fHandles[ "trig_EF_trigmuonef_track_CB_eta" ] = &trig_EF_trigmuonef_track_CB_eta;
      fHandles[ "trig_EF_trigmuonef_track_CB_phi" ] = &trig_EF_trigmuonef_track_CB_phi;
      fHandles[ "trig_EF_trigmuonef_track_CB_hasCB" ] = &trig_EF_trigmuonef_track_CB_hasCB;

    // =============================================================================
    // = Data only
    // =============================================================================
      fHandles[ "trig_EF_trigmuonef_EF_2mu10" ] = &trig_EF_trigmuonef_EF_2mu10;
      fHandles[ "trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose" ] = &trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose;
      fHandles[ "trig_EF_trigmuonef_EF_2mu13" ] = &trig_EF_trigmuonef_EF_2mu13;
      fHandles[ "trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut" ] = &trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut;
      fHandles[ "trig_EF_trigmuonef_EF_2mu13_l2muonSA" ] = &trig_EF_trigmuonef_EF_2mu13_l2muonSA;
      fHandles[ "trig_EF_trigmuonef_EF_2mu15" ] = &trig_EF_trigmuonef_EF_2mu15;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T" ] = &trig_EF_trigmuonef_EF_2mu4T;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_2e5_tight1" ] = &trig_EF_trigmuonef_EF_2mu4T_2e5_tight1;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Bmumu" ] = &trig_EF_trigmuonef_EF_2mu4T_Bmumu;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel" ] = &trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly" ] = &trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Bmumux" ] = &trig_EF_trigmuonef_EF_2mu4T_Bmumux;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel" ] = &trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly" ] = &trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_DiMu" ] = &trig_EF_trigmuonef_EF_2mu4T_DiMu;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel" ] = &trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly" ] = &trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB" ] = &trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC" ] = &trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1" ] = &trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA" ] = &trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS" ] = &trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu" ] = &trig_EF_trigmuonef_EF_2mu4T_Jpsimumu;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel" ] = &trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly" ] = &trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut" ] = &trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Upsimumu" ] = &trig_EF_trigmuonef_EF_2mu4T_Upsimumu;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel" ] = &trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly" ] = &trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_xe60" ] = &trig_EF_trigmuonef_EF_2mu4T_xe60;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw" ] = &trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6" ] = &trig_EF_trigmuonef_EF_2mu6;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6_Bmumu" ] = &trig_EF_trigmuonef_EF_2mu6_Bmumu;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6_Bmumux" ] = &trig_EF_trigmuonef_EF_2mu6_Bmumux;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6_DiMu" ] = &trig_EF_trigmuonef_EF_2mu6_DiMu;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6_DiMu_DY20" ] = &trig_EF_trigmuonef_EF_2mu6_DiMu_DY20;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6_DiMu_DY25" ] = &trig_EF_trigmuonef_EF_2mu6_DiMu_DY25;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS" ] = &trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6_Jpsimumu" ] = &trig_EF_trigmuonef_EF_2mu6_Jpsimumu;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6_Upsimumu" ] = &trig_EF_trigmuonef_EF_2mu6_Upsimumu;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY" ] = &trig_EF_trigmuonef_EF_2mu6i_DiMu_DY;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad" ] = &trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS" ] = &trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad" ] = &trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad;
      fHandles[ "trig_EF_trigmuonef_EF_2mu8_EFxe30" ] = &trig_EF_trigmuonef_EF_2mu8_EFxe30;
      fHandles[ "trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw" ] = &trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw;
      fHandles[ "trig_EF_trigmuonef_EF_mu10" ] = &trig_EF_trigmuonef_EF_mu10;
      fHandles[ "trig_EF_trigmuonef_EF_mu10_Jpsimumu" ] = &trig_EF_trigmuonef_EF_mu10_Jpsimumu;
      fHandles[ "trig_EF_trigmuonef_EF_mu10_MSonly" ] = &trig_EF_trigmuonef_EF_mu10_MSonly;
      fHandles[ "trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS" ] = &trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS;
      fHandles[ "trig_EF_trigmuonef_EF_mu10i_g10_medium" ] = &trig_EF_trigmuonef_EF_mu10i_g10_medium;
      fHandles[ "trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass" ] = &trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass;
      fHandles[ "trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium" ] = &trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium;
      fHandles[ "trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass" ] = &trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass;
      fHandles[ "trig_EF_trigmuonef_EF_mu11_empty_NoAlg" ] = &trig_EF_trigmuonef_EF_mu11_empty_NoAlg;
      fHandles[ "trig_EF_trigmuonef_EF_mu13" ] = &trig_EF_trigmuonef_EF_mu13;
      fHandles[ "trig_EF_trigmuonef_EF_mu15" ] = &trig_EF_trigmuonef_EF_mu15;
      fHandles[ "trig_EF_trigmuonef_EF_mu18" ] = &trig_EF_trigmuonef_EF_mu18;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_2g10_loose" ] = &trig_EF_trigmuonef_EF_mu18_2g10_loose;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_2g10_medium" ] = &trig_EF_trigmuonef_EF_mu18_2g10_medium;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight" ] = &trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_medium" ] = &trig_EF_trigmuonef_EF_mu18_medium;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_tight" ] = &trig_EF_trigmuonef_EF_mu18_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS" ] = &trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_tight_e7_medium1" ] = &trig_EF_trigmuonef_EF_mu18_tight_e7_medium1;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS" ] = &trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS;
      fHandles[ "trig_EF_trigmuonef_EF_mu18i4_tight" ] = &trig_EF_trigmuonef_EF_mu18i4_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass" ] = &trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass;
      fHandles[ "trig_EF_trigmuonef_EF_mu20i_tight_g5_medium" ] = &trig_EF_trigmuonef_EF_mu20i_tight_g5_medium;
      fHandles[ "trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass" ] = &trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass;
      fHandles[ "trig_EF_trigmuonef_EF_mu20it_tight" ] = &trig_EF_trigmuonef_EF_mu20it_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight" ] = &trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu24" ] = &trig_EF_trigmuonef_EF_mu24;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_g20vh_loose" ] = &trig_EF_trigmuonef_EF_mu24_g20vh_loose;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_g20vh_medium" ] = &trig_EF_trigmuonef_EF_mu24_g20vh_medium;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_j65_a4tchad" ] = &trig_EF_trigmuonef_EF_mu24_j65_a4tchad;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40" ] = &trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw" ] = &trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw" ] = &trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_medium" ] = &trig_EF_trigmuonef_EF_mu24_medium;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight" ] = &trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_tight" ] = &trig_EF_trigmuonef_EF_mu24_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad" ] = &trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_tight_EFxe40" ] = &trig_EF_trigmuonef_EF_mu24_tight_EFxe40;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_tight_L2StarB" ] = &trig_EF_trigmuonef_EF_mu24_tight_L2StarB;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_tight_L2StarC" ] = &trig_EF_trigmuonef_EF_mu24_tight_L2StarC;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_tight_MG" ] = &trig_EF_trigmuonef_EF_mu24_tight_MG;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_tight_MuonEF" ] = &trig_EF_trigmuonef_EF_mu24_tight_MuonEF;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad" ] = &trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS" ] = &trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS;
      fHandles[ "trig_EF_trigmuonef_EF_mu24i_tight" ] = &trig_EF_trigmuonef_EF_mu24i_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu24i_tight_MG" ] = &trig_EF_trigmuonef_EF_mu24i_tight_MG;
      fHandles[ "trig_EF_trigmuonef_EF_mu24i_tight_MuonEF" ] = &trig_EF_trigmuonef_EF_mu24i_tight_MuonEF;
      fHandles[ "trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA" ] = &trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA;
      fHandles[ "trig_EF_trigmuonef_EF_mu36_tight" ] = &trig_EF_trigmuonef_EF_mu36_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight" ] = &trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF" ] = &trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF;
      fHandles[ "trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight" ] = &trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu40_slow_tight" ] = &trig_EF_trigmuonef_EF_mu40_slow_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu40_tight" ] = &trig_EF_trigmuonef_EF_mu40_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T" ] = &trig_EF_trigmuonef_EF_mu4T;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_cosmic" ] = &trig_EF_trigmuonef_EF_mu4T_cosmic;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ" ] = &trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ" ] = &trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ" ] = &trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ" ] = &trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ" ] = &trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ" ] = &trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ" ] = &trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose" ] = &trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose" ] = &trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium" ] = &trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass" ] = &trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_DiMu" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_DiMu;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic" ] = &trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic;
      fHandles[ "trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic" ] = &trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic;
      fHandles[ "trig_EF_trigmuonef_EF_mu4_empty_NoAlg" ] = &trig_EF_trigmuonef_EF_mu4_empty_NoAlg;
      fHandles[ "trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg" ] = &trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg;
      fHandles[ "trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg" ] = &trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg;
      fHandles[ "trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight" ] = &trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu6" ] = &trig_EF_trigmuonef_EF_mu6;
      fHandles[ "trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1" ] = &trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1;
      fHandles[ "trig_EF_trigmuonef_EF_mu60_slow_tight1" ] = &trig_EF_trigmuonef_EF_mu60_slow_tight1;
      fHandles[ "trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight" ] = &trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu6_MSonly" ] = &trig_EF_trigmuonef_EF_mu6_MSonly;
      fHandles[ "trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose" ] = &trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose;
      fHandles[ "trig_EF_trigmuonef_EF_mu8" ] = &trig_EF_trigmuonef_EF_mu8;
      fHandles[ "trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS" ] = &trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS;
      fHandles[ "trig_EF_trigmuonef_track_MuonType" ] = &trig_EF_trigmuonef_track_MuonType;
      fHandles[ "trig_EF_trigmuonef_track_MS_pt" ] = &trig_EF_trigmuonef_track_MS_pt;
      fHandles[ "trig_EF_trigmuonef_track_MS_eta" ] = &trig_EF_trigmuonef_track_MS_eta;
      fHandles[ "trig_EF_trigmuonef_track_MS_phi" ] = &trig_EF_trigmuonef_track_MS_phi;
      fHandles[ "trig_EF_trigmuonef_track_MS_hasMS" ] = &trig_EF_trigmuonef_track_MS_hasMS;
      fHandles[ "trig_EF_trigmuonef_track_SA_pt" ] = &trig_EF_trigmuonef_track_SA_pt;
      fHandles[ "trig_EF_trigmuonef_track_SA_eta" ] = &trig_EF_trigmuonef_track_SA_eta;
      fHandles[ "trig_EF_trigmuonef_track_SA_phi" ] = &trig_EF_trigmuonef_track_SA_phi;
      fHandles[ "trig_EF_trigmuonef_track_SA_hasSA" ] = &trig_EF_trigmuonef_track_SA_hasSA;
    
    // =============================================================================
    // = MC only
    // =============================================================================
      fHandles[ "trig_EF_el_EF_e12Tvh_loose1_mu8" ] = &trig_EF_el_EF_e12Tvh_loose1_mu8;
      fHandles[ "trig_EF_el_EF_e12Tvh_medium1_mu10" ] = &trig_EF_el_EF_e12Tvh_medium1_mu10;
      fHandles[ "trig_EF_el_EF_e12Tvh_medium1_mu6" ] = &trig_EF_el_EF_e12Tvh_medium1_mu6;
      fHandles[ "trig_EF_el_EF_e18_loose1_g35_loose" ] = &trig_EF_el_EF_e18_loose1_g35_loose;
      fHandles[ "trig_EF_el_EF_e18_loose1_g35_medium" ] = &trig_EF_el_EF_e18_loose1_g35_medium;
      fHandles[ "trig_EF_el_EF_e18_medium1_g25_medium" ] = &trig_EF_el_EF_e18_medium1_g25_medium;
      fHandles[ "trig_EF_el_EF_e18_medium1_g35_loose" ] = &trig_EF_el_EF_e18_medium1_g35_loose;
      fHandles[ "trig_EF_el_EF_e18_medium1_g35_medium" ] = &trig_EF_el_EF_e18_medium1_g35_medium;
      fHandles[ "trig_EF_el_EF_e22vh_medium1_IdScan" ] = &trig_EF_el_EF_e22vh_medium1_IdScan;
      fHandles[ "trig_EF_el_EF_e22vh_medium1_SiTrk" ] = &trig_EF_el_EF_e22vh_medium1_SiTrk;
      fHandles[ "trig_EF_el_EF_e22vh_medium1_TRT" ] = &trig_EF_el_EF_e22vh_medium1_TRT;
      fHandles[ "trig_EF_el_EF_e45_etcut" ] = &trig_EF_el_EF_e45_etcut;
      fHandles[ "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan" ] = &trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan;
      fHandles[ "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk" ] = &trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk;
      fHandles[ "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT" ] = &trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT;
      fHandles[ "trig_EF_el_EF_e60_etcut" ] = &trig_EF_el_EF_e60_etcut;
    
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   TriggerVecD3PDObject::TriggerVecD3PDObject( const char* prefix )
      : TObject(),
        trig_EF_el_EF_2e12Tvh_loose1( this, ::TString( prefix ) + "trig_EF_el_EF_2e12Tvh_loose1", 0 ),
        trig_EF_el_EF_2e5_tight1_Jpsi( this, ::TString( prefix ) + "trig_EF_el_EF_2e5_tight1_Jpsi", 0 ),
        trig_EF_el_EF_2e7T_loose1_mu6( this, ::TString( prefix ) + "trig_EF_el_EF_2e7T_loose1_mu6", 0 ),
        trig_EF_el_EF_2e7T_medium1_mu6( this, ::TString( prefix ) + "trig_EF_el_EF_2e7T_medium1_mu6", 0 ),
        trig_EF_el_EF_e11_etcut( this, ::TString( prefix ) + "trig_EF_el_EF_e11_etcut", 0 ),
        trig_EF_el_EF_e12Tvh_loose1( this, ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_loose1", 0 ),
        trig_EF_el_EF_e12Tvh_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_medium1", 0 ),
        trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium( this, ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium", 0 ),
        trig_EF_el_EF_e12Tvh_medium1_mu8( this, ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_medium1_mu8", 0 ),
        trig_EF_el_EF_e13_etcutTrk_xs60( this, ::TString( prefix ) + "trig_EF_el_EF_e13_etcutTrk_xs60", 0 ),
        trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20( this, ::TString( prefix ) + "trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20", 0 ),
        trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi( this, ::TString( prefix ) + "trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi", 0 ),
        trig_EF_el_EF_e15vh_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e15vh_medium1", 0 ),
        trig_EF_el_EF_e18_loose1( this, ::TString( prefix ) + "trig_EF_el_EF_e18_loose1", 0 ),
        trig_EF_el_EF_e18_loose1_g25_medium( this, ::TString( prefix ) + "trig_EF_el_EF_e18_loose1_g25_medium", 0 ),
        trig_EF_el_EF_e18_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e18_medium1", 0 ),
        trig_EF_el_EF_e18_medium1_g25_loose( this, ::TString( prefix ) + "trig_EF_el_EF_e18_medium1_g25_loose", 0 ),
        trig_EF_el_EF_e18vh_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e18vh_medium1", 0 ),
        trig_EF_el_EF_e18vh_medium1_2e7T_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e18vh_medium1_2e7T_medium1", 0 ),
        trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20( this, ::TString( prefix ) + "trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20", 0 ),
        trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20( this, ::TString( prefix ) + "trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20", 0 ),
        trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi( this, ::TString( prefix ) + "trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi", 0 ),
        trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi( this, ::TString( prefix ) + "trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi", 0 ),
        trig_EF_el_EF_e22vh_loose( this, ::TString( prefix ) + "trig_EF_el_EF_e22vh_loose", 0 ),
        trig_EF_el_EF_e22vh_loose0( this, ::TString( prefix ) + "trig_EF_el_EF_e22vh_loose0", 0 ),
        trig_EF_el_EF_e22vh_loose1( this, ::TString( prefix ) + "trig_EF_el_EF_e22vh_loose1", 0 ),
        trig_EF_el_EF_e22vh_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e22vh_medium1", 0 ),
        trig_EF_el_EF_e22vh_medium1_IDTrkNoCut( this, ::TString( prefix ) + "trig_EF_el_EF_e22vh_medium1_IDTrkNoCut", 0 ),
        trig_EF_el_EF_e22vhi_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e22vhi_medium1", 0 ),
        trig_EF_el_EF_e24vh_loose( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_loose", 0 ),
        trig_EF_el_EF_e24vh_loose0( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_loose0", 0 ),
        trig_EF_el_EF_e24vh_loose1( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_loose1", 0 ),
        trig_EF_el_EF_e24vh_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1", 0 ),
        trig_EF_el_EF_e24vh_medium1_EFxe30( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_EFxe30", 0 ),
        trig_EF_el_EF_e24vh_medium1_EFxe30_tcem( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_EFxe30_tcem", 0 ),
        trig_EF_el_EF_e24vh_medium1_EFxe35_tcem( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_EFxe35_tcem", 0 ),
        trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw", 0 ),
        trig_EF_el_EF_e24vh_medium1_EFxe40( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_EFxe40", 0 ),
        trig_EF_el_EF_e24vh_medium1_IDTrkNoCut( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_IDTrkNoCut", 0 ),
        trig_EF_el_EF_e24vh_medium1_IdScan( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_IdScan", 0 ),
        trig_EF_el_EF_e24vh_medium1_L2StarB( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_L2StarB", 0 ),
        trig_EF_el_EF_e24vh_medium1_L2StarC( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_L2StarC", 0 ),
        trig_EF_el_EF_e24vh_medium1_SiTrk( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_SiTrk", 0 ),
        trig_EF_el_EF_e24vh_medium1_TRT( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_TRT", 0 ),
        trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad", 0 ),
        trig_EF_el_EF_e24vh_medium1_e7_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_e7_medium1", 0 ),
        trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee", 0 ),
        trig_EF_el_EF_e24vhi_loose1_mu8( this, ::TString( prefix ) + "trig_EF_el_EF_e24vhi_loose1_mu8", 0 ),
        trig_EF_el_EF_e24vhi_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e24vhi_medium1", 0 ),
        trig_EF_el_EF_e45_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e45_medium1", 0 ),
        trig_EF_el_EF_e5_tight1( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1", 0 ),
        trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi", 0 ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi", 0 ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB", 0 ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC", 0 ),
        trig_EF_el_EF_e5_tight1_e5_NoCut( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e5_NoCut", 0 ),
        trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi", 0 ),
        trig_EF_el_EF_e60_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e60_medium1", 0 ),
        trig_EF_el_EF_e7T_loose1( this, ::TString( prefix ) + "trig_EF_el_EF_e7T_loose1", 0 ),
        trig_EF_el_EF_e7T_loose1_2mu6( this, ::TString( prefix ) + "trig_EF_el_EF_e7T_loose1_2mu6", 0 ),
        trig_EF_el_EF_e7T_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e7T_medium1", 0 ),
        trig_EF_el_EF_e7T_medium1_2mu6( this, ::TString( prefix ) + "trig_EF_el_EF_e7T_medium1_2mu6", 0 ),
        trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi( this, ::TString( prefix ) + "trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi", 0 ),
        trig_EF_el_EF_eb_physics( this, ::TString( prefix ) + "trig_EF_el_EF_eb_physics", 0 ),
        trig_EF_el_EF_eb_physics_empty( this, ::TString( prefix ) + "trig_EF_el_EF_eb_physics_empty", 0 ),
        trig_EF_el_EF_eb_physics_firstempty( this, ::TString( prefix ) + "trig_EF_el_EF_eb_physics_firstempty", 0 ),
        trig_EF_el_EF_eb_physics_noL1PS( this, ::TString( prefix ) + "trig_EF_el_EF_eb_physics_noL1PS", 0 ),
        trig_EF_el_EF_eb_physics_unpaired_iso( this, ::TString( prefix ) + "trig_EF_el_EF_eb_physics_unpaired_iso", 0 ),
        trig_EF_el_EF_eb_physics_unpaired_noniso( this, ::TString( prefix ) + "trig_EF_el_EF_eb_physics_unpaired_noniso", 0 ),
        trig_EF_el_EF_eb_random( this, ::TString( prefix ) + "trig_EF_el_EF_eb_random", 0 ),
        trig_EF_el_EF_eb_random_empty( this, ::TString( prefix ) + "trig_EF_el_EF_eb_random_empty", 0 ),
        trig_EF_el_EF_eb_random_firstempty( this, ::TString( prefix ) + "trig_EF_el_EF_eb_random_firstempty", 0 ),
        trig_EF_el_EF_eb_random_unpaired_iso( this, ::TString( prefix ) + "trig_EF_el_EF_eb_random_unpaired_iso", 0 ),
        trig_EF_emcl_pt( this, ::TString( prefix ) + "trig_EF_emcl_pt", 0 ),
        trig_EF_emcl_eta( this, ::TString( prefix ) + "trig_EF_emcl_eta", 0 ),
        trig_EF_emcl_phi( this, ::TString( prefix ) + "trig_EF_emcl_phi", 0 ),
        trig_EF_emcl_E_em( this, ::TString( prefix ) + "trig_EF_emcl_E_em", 0 ),
        trig_EF_emcl_E_had( this, ::TString( prefix ) + "trig_EF_emcl_E_had", 0 ),
        trig_EF_emcl_slw_pt( this, ::TString( prefix ) + "trig_EF_emcl_slw_pt", 0 ),
        trig_EF_emcl_slw_eta( this, ::TString( prefix ) + "trig_EF_emcl_slw_eta", 0 ),
        trig_EF_emcl_slw_phi( this, ::TString( prefix ) + "trig_EF_emcl_slw_phi", 0 ),
        trig_EF_emcl_slw_E_em( this, ::TString( prefix ) + "trig_EF_emcl_slw_E_em", 0 ),
        trig_EF_emcl_slw_E_had( this, ::TString( prefix ) + "trig_EF_emcl_slw_E_had", 0 ),
        trig_EF_el_E( this, ::TString( prefix ) + "trig_EF_el_E", 0 ),
        trig_EF_el_Et( this, ::TString( prefix ) + "trig_EF_el_Et", 0 ),
        trig_EF_el_pt( this, ::TString( prefix ) + "trig_EF_el_pt", 0 ),
        trig_EF_el_m( this, ::TString( prefix ) + "trig_EF_el_m", 0 ),
        trig_EF_el_eta( this, ::TString( prefix ) + "trig_EF_el_eta", 0 ),
        trig_EF_el_phi( this, ::TString( prefix ) + "trig_EF_el_phi", 0 ),
        trig_EF_el_px( this, ::TString( prefix ) + "trig_EF_el_px", 0 ),
        trig_EF_el_py( this, ::TString( prefix ) + "trig_EF_el_py", 0 ),
        trig_EF_el_pz( this, ::TString( prefix ) + "trig_EF_el_pz", 0 ),
        trig_EF_el_charge( this, ::TString( prefix ) + "trig_EF_el_charge", 0 ),
        trig_EF_el_author( this, ::TString( prefix ) + "trig_EF_el_author", 0 ),
        trig_EF_el_isEM( this, ::TString( prefix ) + "trig_EF_el_isEM", 0 ),
        trig_EF_el_isEMLoose( this, ::TString( prefix ) + "trig_EF_el_isEMLoose", 0 ),
        trig_EF_el_isEMMedium( this, ::TString( prefix ) + "trig_EF_el_isEMMedium", 0 ),
        trig_EF_el_isEMTight( this, ::TString( prefix ) + "trig_EF_el_isEMTight", 0 ),
        trig_EF_el_loose( this, ::TString( prefix ) + "trig_EF_el_loose", 0 ),
        trig_EF_el_looseIso( this, ::TString( prefix ) + "trig_EF_el_looseIso", 0 ),
        trig_EF_el_medium( this, ::TString( prefix ) + "trig_EF_el_medium", 0 ),
        trig_EF_el_mediumIso( this, ::TString( prefix ) + "trig_EF_el_mediumIso", 0 ),
        trig_EF_el_mediumWithoutTrack( this, ::TString( prefix ) + "trig_EF_el_mediumWithoutTrack", 0 ),
        trig_EF_el_mediumIsoWithoutTrack( this, ::TString( prefix ) + "trig_EF_el_mediumIsoWithoutTrack", 0 ),
        trig_EF_el_tight( this, ::TString( prefix ) + "trig_EF_el_tight", 0 ),
        trig_EF_el_tightIso( this, ::TString( prefix ) + "trig_EF_el_tightIso", 0 ),
        trig_EF_el_tightWithoutTrack( this, ::TString( prefix ) + "trig_EF_el_tightWithoutTrack", 0 ),
        trig_EF_el_tightIsoWithoutTrack( this, ::TString( prefix ) + "trig_EF_el_tightIsoWithoutTrack", 0 ),
        trig_EF_el_loosePP( this, ::TString( prefix ) + "trig_EF_el_loosePP", 0 ),
        trig_EF_el_loosePPIso( this, ::TString( prefix ) + "trig_EF_el_loosePPIso", 0 ),
        trig_EF_el_mediumPP( this, ::TString( prefix ) + "trig_EF_el_mediumPP", 0 ),
        trig_EF_el_mediumPPIso( this, ::TString( prefix ) + "trig_EF_el_mediumPPIso", 0 ),
        trig_EF_el_tightPP( this, ::TString( prefix ) + "trig_EF_el_tightPP", 0 ),
        trig_EF_el_tightPPIso( this, ::TString( prefix ) + "trig_EF_el_tightPPIso", 0 ),
        trig_EF_el_vertweight( this, ::TString( prefix ) + "trig_EF_el_vertweight", 0 ),
        trig_EF_el_hastrack( this, ::TString( prefix ) + "trig_EF_el_hastrack", 0 ),
        trig_EF_trigmuonef_track_CB_pt( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_pt", 0 ),
        trig_EF_trigmuonef_track_CB_eta( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_eta", 0 ),
        trig_EF_trigmuonef_track_CB_phi( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_phi", 0 ),
        trig_EF_trigmuonef_track_CB_hasCB( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_hasCB", 0 ),

    // =============================================================================
    // = Data only
    // =============================================================================
        trig_EF_trigmuonef_EF_2mu10( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu10", 0 ),
        trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose", 0 ),
        trig_EF_trigmuonef_EF_2mu13( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu13", 0 ),
        trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut", 0 ),
        trig_EF_trigmuonef_EF_2mu13_l2muonSA( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu13_l2muonSA", 0 ),
        trig_EF_trigmuonef_EF_2mu15( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu15", 0 ),
        trig_EF_trigmuonef_EF_2mu4T( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_2e5_tight1( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_2e5_tight1", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Bmumu", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumux( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Bmumux", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_Jpsimumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_Upsimumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_upsimumu", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_upsimumu_Barrel", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_upsimumu_BarrelOnly", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_xe60( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_xe60", 0 ),
        trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw", 0 ),
        trig_EF_trigmuonef_EF_2mu6( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6", 0 ),
        trig_EF_trigmuonef_EF_2mu6_Bmumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_Bmumu", 0 ),
        trig_EF_trigmuonef_EF_2mu6_Bmumux( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_Bmumux", 0 ),
        trig_EF_trigmuonef_EF_2mu6_DiMu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_DiMu", 0 ),
        trig_EF_trigmuonef_EF_2mu6_DiMu_DY20( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_DiMu_DY20", 0 ),
        trig_EF_trigmuonef_EF_2mu6_DiMu_DY25( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_DiMu_DY25", 0 ),
        trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS", 0 ),
        trig_EF_trigmuonef_EF_2mu6_Jpsimumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_Jpsimumu", 0 ),
        trig_EF_trigmuonef_EF_2mu6_Upsimumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_upsimumu", 0 ),
        trig_EF_trigmuonef_EF_2mu6i_DiMu_DY( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY", 0 ),
        trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad", 0 ),
        trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS", 0 ),
        trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad", 0 ),
        trig_EF_trigmuonef_EF_2mu8_EFxe30( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu8_EFxe30", 0 ),
        trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw", 0 ),
        trig_EF_trigmuonef_EF_mu10( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10", 0 ),
        trig_EF_trigmuonef_EF_mu10_Jpsimumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10_Jpsimumu", 0 ),
        trig_EF_trigmuonef_EF_mu10_MSonly( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10_MSonly", 0 ),
        trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10_upsimumu_tight_FS", 0 ),
        trig_EF_trigmuonef_EF_mu10i_g10_medium( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10i_g10_medium", 0 ),
        trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass", 0 ),
        trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium", 0 ),
        trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass", 0 ),
        trig_EF_trigmuonef_EF_mu11_empty_NoAlg( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu11_empty_NoAlg", 0 ),
        trig_EF_trigmuonef_EF_mu13( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu13", 0 ),
        trig_EF_trigmuonef_EF_mu15( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu15", 0 ),
        trig_EF_trigmuonef_EF_mu18( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18", 0 ),
        trig_EF_trigmuonef_EF_mu18_2g10_loose( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_2g10_loose", 0 ),
        trig_EF_trigmuonef_EF_mu18_2g10_medium( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_2g10_medium", 0 ),
        trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight", 0 ),
        trig_EF_trigmuonef_EF_mu18_medium( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_medium", 0 ),
        trig_EF_trigmuonef_EF_mu18_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_tight", 0 ),
        trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS", 0 ),
        trig_EF_trigmuonef_EF_mu18_tight_e7_medium1( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_tight_e7_medium1", 0 ),
        trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS", 0 ),
        trig_EF_trigmuonef_EF_mu18i4_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18i4_tight", 0 ),
        trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass", 0 ),
        trig_EF_trigmuonef_EF_mu20i_tight_g5_medium( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu20i_tight_g5_medium", 0 ),
        trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass", 0 ),
        trig_EF_trigmuonef_EF_mu20it_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu20it_tight", 0 ),
        trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight", 0 ),
        trig_EF_trigmuonef_EF_mu24( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24", 0 ),
        trig_EF_trigmuonef_EF_mu24_g20vh_loose( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_g20vh_loose", 0 ),
        trig_EF_trigmuonef_EF_mu24_g20vh_medium( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_g20vh_medium", 0 ),
        trig_EF_trigmuonef_EF_mu24_j65_a4tchad( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_j65_a4tchad", 0 ),
        trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40", 0 ),
        trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw", 0 ),
        trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw", 0 ),
        trig_EF_trigmuonef_EF_mu24_medium( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_medium", 0 ),
        trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight", 0 ),
        trig_EF_trigmuonef_EF_mu24_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight", 0 ),
        trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad", 0 ),
        trig_EF_trigmuonef_EF_mu24_tight_EFxe40( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_EFxe40", 0 ),
        trig_EF_trigmuonef_EF_mu24_tight_L2StarB( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_L2StarB", 0 ),
        trig_EF_trigmuonef_EF_mu24_tight_L2StarC( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_L2StarC", 0 ),
        trig_EF_trigmuonef_EF_mu24_tight_MG( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_mg", 0 ),
        trig_EF_trigmuonef_EF_mu24_tight_MuonEF( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_MuonEF", 0 ),
        trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad", 0 ),
        trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS", 0 ),
        trig_EF_trigmuonef_EF_mu24i_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24i_tight", 0 ),
        trig_EF_trigmuonef_EF_mu24i_tight_MG( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24i_tight_mg", 0 ),
        trig_EF_trigmuonef_EF_mu24i_tight_MuonEF( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24i_tight_MuonEF", 0 ),
        trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA", 0 ),
        trig_EF_trigmuonef_EF_mu36_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu36_tight", 0 ),
        trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight", 0 ),
        trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF", 0 ),
        trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight", 0 ),
        trig_EF_trigmuonef_EF_mu40_slow_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu40_slow_tight", 0 ),
        trig_EF_trigmuonef_EF_mu40_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu40_tight", 0 ),
        trig_EF_trigmuonef_EF_mu4T( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T", 0 ),
        trig_EF_trigmuonef_EF_mu4T_cosmic( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_cosmic", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched", 0 ),
        trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium", 0 ),
        trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass", 0 ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu", 0 ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel", 0 ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux", 0 ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel", 0 ),
        trig_EF_trigmuonef_EF_mu4Tmu6_DiMu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_DiMu", 0 ),
        trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel", 0 ),
        trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS", 0 ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu", 0 ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel", 0 ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut", 0 ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_upsimumu", 0 ),
        trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_upsimumu_Barrel", 0 ),
        trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic", 0 ),
        trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic", 0 ),
        trig_EF_trigmuonef_EF_mu4_empty_NoAlg( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4_empty_NoAlg", 0 ),
        trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg", 0 ),
        trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg", 0 ),
        trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight", 0 ),
        trig_EF_trigmuonef_EF_mu6( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu6", 0 ),
        trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1", 0 ),
        trig_EF_trigmuonef_EF_mu60_slow_tight1( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu60_slow_tight1", 0 ),
        trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight", 0 ),
        trig_EF_trigmuonef_EF_mu6_MSonly( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu6_MSonly", 0 ),
        trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose", 0 ),
        trig_EF_trigmuonef_EF_mu8( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu8", 0 ),
        trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS", 0 ),
        trig_EF_trigmuonef_track_MuonType( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_MuonType", 0 ),
        trig_EF_trigmuonef_track_MS_pt( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_MS_pt", 0 ),
        trig_EF_trigmuonef_track_MS_eta( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_MS_eta", 0 ),
        trig_EF_trigmuonef_track_MS_phi( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_MS_phi", 0 ),
        trig_EF_trigmuonef_track_MS_hasMS( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_MS_hasMS", 0 ),
        trig_EF_trigmuonef_track_SA_pt( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_SA_pt", 0 ),
        trig_EF_trigmuonef_track_SA_eta( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_SA_eta", 0 ),
        trig_EF_trigmuonef_track_SA_phi( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_SA_phi", 0 ),
        trig_EF_trigmuonef_track_SA_hasSA( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_SA_hasSA", 0 ),
    
    // =============================================================================
    // = MC only
    // =============================================================================
        trig_EF_el_EF_e12Tvh_loose1_mu8( this, ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_loose1_mu8", 0 ),
        trig_EF_el_EF_e12Tvh_medium1_mu10( this, ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_medium1_mu10", 0 ),
        trig_EF_el_EF_e12Tvh_medium1_mu6( this, ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_medium1_mu6", 0 ),
        trig_EF_el_EF_e18_loose1_g35_loose( this, ::TString( prefix ) + "trig_EF_el_EF_e18_loose1_g35_loose", 0 ),
        trig_EF_el_EF_e18_loose1_g35_medium( this, ::TString( prefix ) + "trig_EF_el_EF_e18_loose1_g35_medium", 0 ),
        trig_EF_el_EF_e18_medium1_g25_medium( this, ::TString( prefix ) + "trig_EF_el_EF_e18_medium1_g25_medium", 0 ),
        trig_EF_el_EF_e18_medium1_g35_loose( this, ::TString( prefix ) + "trig_EF_el_EF_e18_medium1_g35_loose", 0 ),
        trig_EF_el_EF_e18_medium1_g35_medium( this, ::TString( prefix ) + "trig_EF_el_EF_e18_medium1_g35_medium", 0 ),
        trig_EF_el_EF_e22vh_medium1_IdScan( this, ::TString( prefix ) + "trig_EF_el_EF_e22vh_medium1_IdScan", 0 ),
        trig_EF_el_EF_e22vh_medium1_SiTrk( this, ::TString( prefix ) + "trig_EF_el_EF_e22vh_medium1_SiTrk", 0 ),
        trig_EF_el_EF_e22vh_medium1_TRT( this, ::TString( prefix ) + "trig_EF_el_EF_e22vh_medium1_TRT", 0 ),
        trig_EF_el_EF_e45_etcut( this, ::TString( prefix ) + "trig_EF_el_EF_e45_etcut", 0 ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan", 0 ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk", 0 ),
        trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT( this, ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT", 0 ),
        trig_EF_el_EF_e60_etcut( this, ::TString( prefix ) + "trig_EF_el_EF_e60_etcut", 0 ),
    
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) {

      fHandles[ "trig_EF_el_EF_2e12Tvh_loose1" ] = &trig_EF_el_EF_2e12Tvh_loose1;
      fHandles[ "trig_EF_el_EF_2e5_tight1_Jpsi" ] = &trig_EF_el_EF_2e5_tight1_Jpsi;
      fHandles[ "trig_EF_el_EF_2e7T_loose1_mu6" ] = &trig_EF_el_EF_2e7T_loose1_mu6;
      fHandles[ "trig_EF_el_EF_2e7T_medium1_mu6" ] = &trig_EF_el_EF_2e7T_medium1_mu6;
      fHandles[ "trig_EF_el_EF_e11_etcut" ] = &trig_EF_el_EF_e11_etcut;
      fHandles[ "trig_EF_el_EF_e12Tvh_loose1" ] = &trig_EF_el_EF_e12Tvh_loose1;
      fHandles[ "trig_EF_el_EF_e12Tvh_medium1" ] = &trig_EF_el_EF_e12Tvh_medium1;
      fHandles[ "trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium" ] = &trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium;
      fHandles[ "trig_EF_el_EF_e12Tvh_medium1_mu8" ] = &trig_EF_el_EF_e12Tvh_medium1_mu8;
      fHandles[ "trig_EF_el_EF_e13_etcutTrk_xs60" ] = &trig_EF_el_EF_e13_etcutTrk_xs60;
      fHandles[ "trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20" ] = &trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20;
      fHandles[ "trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi" ] = &trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi;
      fHandles[ "trig_EF_el_EF_e15vh_medium1" ] = &trig_EF_el_EF_e15vh_medium1;
      fHandles[ "trig_EF_el_EF_e18_loose1" ] = &trig_EF_el_EF_e18_loose1;
      fHandles[ "trig_EF_el_EF_e18_loose1_g25_medium" ] = &trig_EF_el_EF_e18_loose1_g25_medium;
      fHandles[ "trig_EF_el_EF_e18_medium1" ] = &trig_EF_el_EF_e18_medium1;
      fHandles[ "trig_EF_el_EF_e18_medium1_g25_loose" ] = &trig_EF_el_EF_e18_medium1_g25_loose;
      fHandles[ "trig_EF_el_EF_e18vh_medium1" ] = &trig_EF_el_EF_e18vh_medium1;
      fHandles[ "trig_EF_el_EF_e18vh_medium1_2e7T_medium1" ] = &trig_EF_el_EF_e18vh_medium1_2e7T_medium1;
      fHandles[ "trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20" ] = &trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20;
      fHandles[ "trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20" ] = &trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20;
      fHandles[ "trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi" ] = &trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi;
      fHandles[ "trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi" ] = &trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi;
      fHandles[ "trig_EF_el_EF_e22vh_loose" ] = &trig_EF_el_EF_e22vh_loose;
      fHandles[ "trig_EF_el_EF_e22vh_loose0" ] = &trig_EF_el_EF_e22vh_loose0;
      fHandles[ "trig_EF_el_EF_e22vh_loose1" ] = &trig_EF_el_EF_e22vh_loose1;
      fHandles[ "trig_EF_el_EF_e22vh_medium1" ] = &trig_EF_el_EF_e22vh_medium1;
      fHandles[ "trig_EF_el_EF_e22vh_medium1_IDTrkNoCut" ] = &trig_EF_el_EF_e22vh_medium1_IDTrkNoCut;
      fHandles[ "trig_EF_el_EF_e22vhi_medium1" ] = &trig_EF_el_EF_e22vhi_medium1;
      fHandles[ "trig_EF_el_EF_e24vh_loose" ] = &trig_EF_el_EF_e24vh_loose;
      fHandles[ "trig_EF_el_EF_e24vh_loose0" ] = &trig_EF_el_EF_e24vh_loose0;
      fHandles[ "trig_EF_el_EF_e24vh_loose1" ] = &trig_EF_el_EF_e24vh_loose1;
      fHandles[ "trig_EF_el_EF_e24vh_medium1" ] = &trig_EF_el_EF_e24vh_medium1;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_EFxe30" ] = &trig_EF_el_EF_e24vh_medium1_EFxe30;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_EFxe30_tcem" ] = &trig_EF_el_EF_e24vh_medium1_EFxe30_tcem;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_EFxe35_tcem" ] = &trig_EF_el_EF_e24vh_medium1_EFxe35_tcem;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw" ] = &trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_EFxe40" ] = &trig_EF_el_EF_e24vh_medium1_EFxe40;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_IDTrkNoCut" ] = &trig_EF_el_EF_e24vh_medium1_IDTrkNoCut;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_IdScan" ] = &trig_EF_el_EF_e24vh_medium1_IdScan;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_L2StarB" ] = &trig_EF_el_EF_e24vh_medium1_L2StarB;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_L2StarC" ] = &trig_EF_el_EF_e24vh_medium1_L2StarC;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_SiTrk" ] = &trig_EF_el_EF_e24vh_medium1_SiTrk;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_TRT" ] = &trig_EF_el_EF_e24vh_medium1_TRT;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad" ] = &trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_e7_medium1" ] = &trig_EF_el_EF_e24vh_medium1_e7_medium1;
      fHandles[ "trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee" ] = &trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee;
      fHandles[ "trig_EF_el_EF_e24vhi_loose1_mu8" ] = &trig_EF_el_EF_e24vhi_loose1_mu8;
      fHandles[ "trig_EF_el_EF_e24vhi_medium1" ] = &trig_EF_el_EF_e24vhi_medium1;
      fHandles[ "trig_EF_el_EF_e45_medium1" ] = &trig_EF_el_EF_e45_medium1;
      fHandles[ "trig_EF_el_EF_e5_tight1" ] = &trig_EF_el_EF_e5_tight1;
      fHandles[ "trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi" ] = &trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi;
      fHandles[ "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi" ] = &trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi;
      fHandles[ "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB" ] = &trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB;
      fHandles[ "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC" ] = &trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC;
      fHandles[ "trig_EF_el_EF_e5_tight1_e5_NoCut" ] = &trig_EF_el_EF_e5_tight1_e5_NoCut;
      fHandles[ "trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi" ] = &trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi;
      fHandles[ "trig_EF_el_EF_e60_medium1" ] = &trig_EF_el_EF_e60_medium1;
      fHandles[ "trig_EF_el_EF_e7T_loose1" ] = &trig_EF_el_EF_e7T_loose1;
      fHandles[ "trig_EF_el_EF_e7T_loose1_2mu6" ] = &trig_EF_el_EF_e7T_loose1_2mu6;
      fHandles[ "trig_EF_el_EF_e7T_medium1" ] = &trig_EF_el_EF_e7T_medium1;
      fHandles[ "trig_EF_el_EF_e7T_medium1_2mu6" ] = &trig_EF_el_EF_e7T_medium1_2mu6;
      fHandles[ "trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi" ] = &trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi;
      fHandles[ "trig_EF_el_EF_eb_physics" ] = &trig_EF_el_EF_eb_physics;
      fHandles[ "trig_EF_el_EF_eb_physics_empty" ] = &trig_EF_el_EF_eb_physics_empty;
      fHandles[ "trig_EF_el_EF_eb_physics_firstempty" ] = &trig_EF_el_EF_eb_physics_firstempty;
      fHandles[ "trig_EF_el_EF_eb_physics_noL1PS" ] = &trig_EF_el_EF_eb_physics_noL1PS;
      fHandles[ "trig_EF_el_EF_eb_physics_unpaired_iso" ] = &trig_EF_el_EF_eb_physics_unpaired_iso;
      fHandles[ "trig_EF_el_EF_eb_physics_unpaired_noniso" ] = &trig_EF_el_EF_eb_physics_unpaired_noniso;
      fHandles[ "trig_EF_el_EF_eb_random" ] = &trig_EF_el_EF_eb_random;
      fHandles[ "trig_EF_el_EF_eb_random_empty" ] = &trig_EF_el_EF_eb_random_empty;
      fHandles[ "trig_EF_el_EF_eb_random_firstempty" ] = &trig_EF_el_EF_eb_random_firstempty;
      fHandles[ "trig_EF_el_EF_eb_random_unpaired_iso" ] = &trig_EF_el_EF_eb_random_unpaired_iso;
      fHandles[ "trig_EF_emcl_pt" ] = &trig_EF_emcl_pt;
      fHandles[ "trig_EF_emcl_eta" ] = &trig_EF_emcl_eta;
      fHandles[ "trig_EF_emcl_phi" ] = &trig_EF_emcl_phi;
      fHandles[ "trig_EF_emcl_E_em" ] = &trig_EF_emcl_E_em;
      fHandles[ "trig_EF_emcl_E_had" ] = &trig_EF_emcl_E_had;
      fHandles[ "trig_EF_emcl_slw_pt" ] = &trig_EF_emcl_slw_pt;
      fHandles[ "trig_EF_emcl_slw_eta" ] = &trig_EF_emcl_slw_eta;
      fHandles[ "trig_EF_emcl_slw_phi" ] = &trig_EF_emcl_slw_phi;
      fHandles[ "trig_EF_emcl_slw_E_em" ] = &trig_EF_emcl_slw_E_em;
      fHandles[ "trig_EF_emcl_slw_E_had" ] = &trig_EF_emcl_slw_E_had;
      fHandles[ "trig_EF_el_E" ] = &trig_EF_el_E;
      fHandles[ "trig_EF_el_Et" ] = &trig_EF_el_Et;
      fHandles[ "trig_EF_el_pt" ] = &trig_EF_el_pt;
      fHandles[ "trig_EF_el_m" ] = &trig_EF_el_m;
      fHandles[ "trig_EF_el_eta" ] = &trig_EF_el_eta;
      fHandles[ "trig_EF_el_phi" ] = &trig_EF_el_phi;
      fHandles[ "trig_EF_el_px" ] = &trig_EF_el_px;
      fHandles[ "trig_EF_el_py" ] = &trig_EF_el_py;
      fHandles[ "trig_EF_el_pz" ] = &trig_EF_el_pz;
      fHandles[ "trig_EF_el_charge" ] = &trig_EF_el_charge;
      fHandles[ "trig_EF_el_author" ] = &trig_EF_el_author;
      fHandles[ "trig_EF_el_isEM" ] = &trig_EF_el_isEM;
      fHandles[ "trig_EF_el_isEMLoose" ] = &trig_EF_el_isEMLoose;
      fHandles[ "trig_EF_el_isEMMedium" ] = &trig_EF_el_isEMMedium;
      fHandles[ "trig_EF_el_isEMTight" ] = &trig_EF_el_isEMTight;
      fHandles[ "trig_EF_el_loose" ] = &trig_EF_el_loose;
      fHandles[ "trig_EF_el_looseIso" ] = &trig_EF_el_looseIso;
      fHandles[ "trig_EF_el_medium" ] = &trig_EF_el_medium;
      fHandles[ "trig_EF_el_mediumIso" ] = &trig_EF_el_mediumIso;
      fHandles[ "trig_EF_el_mediumWithoutTrack" ] = &trig_EF_el_mediumWithoutTrack;
      fHandles[ "trig_EF_el_mediumIsoWithoutTrack" ] = &trig_EF_el_mediumIsoWithoutTrack;
      fHandles[ "trig_EF_el_tight" ] = &trig_EF_el_tight;
      fHandles[ "trig_EF_el_tightIso" ] = &trig_EF_el_tightIso;
      fHandles[ "trig_EF_el_tightWithoutTrack" ] = &trig_EF_el_tightWithoutTrack;
      fHandles[ "trig_EF_el_tightIsoWithoutTrack" ] = &trig_EF_el_tightIsoWithoutTrack;
      fHandles[ "trig_EF_el_loosePP" ] = &trig_EF_el_loosePP;
      fHandles[ "trig_EF_el_loosePPIso" ] = &trig_EF_el_loosePPIso;
      fHandles[ "trig_EF_el_mediumPP" ] = &trig_EF_el_mediumPP;
      fHandles[ "trig_EF_el_mediumPPIso" ] = &trig_EF_el_mediumPPIso;
      fHandles[ "trig_EF_el_tightPP" ] = &trig_EF_el_tightPP;
      fHandles[ "trig_EF_el_tightPPIso" ] = &trig_EF_el_tightPPIso;
      fHandles[ "trig_EF_el_vertweight" ] = &trig_EF_el_vertweight;
      fHandles[ "trig_EF_el_hastrack" ] = &trig_EF_el_hastrack;
      fHandles[ "trig_EF_trigmuonef_track_CB_pt" ] = &trig_EF_trigmuonef_track_CB_pt;
      fHandles[ "trig_EF_trigmuonef_track_CB_eta" ] = &trig_EF_trigmuonef_track_CB_eta;
      fHandles[ "trig_EF_trigmuonef_track_CB_phi" ] = &trig_EF_trigmuonef_track_CB_phi;
      fHandles[ "trig_EF_trigmuonef_track_CB_hasCB" ] = &trig_EF_trigmuonef_track_CB_hasCB;

    // =============================================================================
    // = Data only
    // =============================================================================
      fHandles[ "trig_EF_trigmuonef_EF_2mu10" ] = &trig_EF_trigmuonef_EF_2mu10;
      fHandles[ "trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose" ] = &trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose;
      fHandles[ "trig_EF_trigmuonef_EF_2mu13" ] = &trig_EF_trigmuonef_EF_2mu13;
      fHandles[ "trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut" ] = &trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut;
      fHandles[ "trig_EF_trigmuonef_EF_2mu13_l2muonSA" ] = &trig_EF_trigmuonef_EF_2mu13_l2muonSA;
      fHandles[ "trig_EF_trigmuonef_EF_2mu15" ] = &trig_EF_trigmuonef_EF_2mu15;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T" ] = &trig_EF_trigmuonef_EF_2mu4T;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_2e5_tight1" ] = &trig_EF_trigmuonef_EF_2mu4T_2e5_tight1;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Bmumu" ] = &trig_EF_trigmuonef_EF_2mu4T_Bmumu;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel" ] = &trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly" ] = &trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Bmumux" ] = &trig_EF_trigmuonef_EF_2mu4T_Bmumux;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel" ] = &trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly" ] = &trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_DiMu" ] = &trig_EF_trigmuonef_EF_2mu4T_DiMu;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel" ] = &trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly" ] = &trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB" ] = &trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC" ] = &trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1" ] = &trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA" ] = &trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS" ] = &trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu" ] = &trig_EF_trigmuonef_EF_2mu4T_Jpsimumu;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel" ] = &trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly" ] = &trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut" ] = &trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Upsimumu" ] = &trig_EF_trigmuonef_EF_2mu4T_Upsimumu;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel" ] = &trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly" ] = &trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_xe60" ] = &trig_EF_trigmuonef_EF_2mu4T_xe60;
      fHandles[ "trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw" ] = &trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6" ] = &trig_EF_trigmuonef_EF_2mu6;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6_Bmumu" ] = &trig_EF_trigmuonef_EF_2mu6_Bmumu;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6_Bmumux" ] = &trig_EF_trigmuonef_EF_2mu6_Bmumux;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6_DiMu" ] = &trig_EF_trigmuonef_EF_2mu6_DiMu;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6_DiMu_DY20" ] = &trig_EF_trigmuonef_EF_2mu6_DiMu_DY20;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6_DiMu_DY25" ] = &trig_EF_trigmuonef_EF_2mu6_DiMu_DY25;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS" ] = &trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6_Jpsimumu" ] = &trig_EF_trigmuonef_EF_2mu6_Jpsimumu;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6_Upsimumu" ] = &trig_EF_trigmuonef_EF_2mu6_Upsimumu;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY" ] = &trig_EF_trigmuonef_EF_2mu6i_DiMu_DY;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad" ] = &trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS" ] = &trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS;
      fHandles[ "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad" ] = &trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad;
      fHandles[ "trig_EF_trigmuonef_EF_2mu8_EFxe30" ] = &trig_EF_trigmuonef_EF_2mu8_EFxe30;
      fHandles[ "trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw" ] = &trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw;
      fHandles[ "trig_EF_trigmuonef_EF_mu10" ] = &trig_EF_trigmuonef_EF_mu10;
      fHandles[ "trig_EF_trigmuonef_EF_mu10_Jpsimumu" ] = &trig_EF_trigmuonef_EF_mu10_Jpsimumu;
      fHandles[ "trig_EF_trigmuonef_EF_mu10_MSonly" ] = &trig_EF_trigmuonef_EF_mu10_MSonly;
      fHandles[ "trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS" ] = &trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS;
      fHandles[ "trig_EF_trigmuonef_EF_mu10i_g10_medium" ] = &trig_EF_trigmuonef_EF_mu10i_g10_medium;
      fHandles[ "trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass" ] = &trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass;
      fHandles[ "trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium" ] = &trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium;
      fHandles[ "trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass" ] = &trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass;
      fHandles[ "trig_EF_trigmuonef_EF_mu11_empty_NoAlg" ] = &trig_EF_trigmuonef_EF_mu11_empty_NoAlg;
      fHandles[ "trig_EF_trigmuonef_EF_mu13" ] = &trig_EF_trigmuonef_EF_mu13;
      fHandles[ "trig_EF_trigmuonef_EF_mu15" ] = &trig_EF_trigmuonef_EF_mu15;
      fHandles[ "trig_EF_trigmuonef_EF_mu18" ] = &trig_EF_trigmuonef_EF_mu18;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_2g10_loose" ] = &trig_EF_trigmuonef_EF_mu18_2g10_loose;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_2g10_medium" ] = &trig_EF_trigmuonef_EF_mu18_2g10_medium;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight" ] = &trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_medium" ] = &trig_EF_trigmuonef_EF_mu18_medium;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_tight" ] = &trig_EF_trigmuonef_EF_mu18_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS" ] = &trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_tight_e7_medium1" ] = &trig_EF_trigmuonef_EF_mu18_tight_e7_medium1;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS" ] = &trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS;
      fHandles[ "trig_EF_trigmuonef_EF_mu18i4_tight" ] = &trig_EF_trigmuonef_EF_mu18i4_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass" ] = &trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass;
      fHandles[ "trig_EF_trigmuonef_EF_mu20i_tight_g5_medium" ] = &trig_EF_trigmuonef_EF_mu20i_tight_g5_medium;
      fHandles[ "trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass" ] = &trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass;
      fHandles[ "trig_EF_trigmuonef_EF_mu20it_tight" ] = &trig_EF_trigmuonef_EF_mu20it_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight" ] = &trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu24" ] = &trig_EF_trigmuonef_EF_mu24;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_g20vh_loose" ] = &trig_EF_trigmuonef_EF_mu24_g20vh_loose;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_g20vh_medium" ] = &trig_EF_trigmuonef_EF_mu24_g20vh_medium;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_j65_a4tchad" ] = &trig_EF_trigmuonef_EF_mu24_j65_a4tchad;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40" ] = &trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw" ] = &trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw" ] = &trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_medium" ] = &trig_EF_trigmuonef_EF_mu24_medium;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight" ] = &trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_tight" ] = &trig_EF_trigmuonef_EF_mu24_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad" ] = &trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_tight_EFxe40" ] = &trig_EF_trigmuonef_EF_mu24_tight_EFxe40;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_tight_L2StarB" ] = &trig_EF_trigmuonef_EF_mu24_tight_L2StarB;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_tight_L2StarC" ] = &trig_EF_trigmuonef_EF_mu24_tight_L2StarC;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_tight_MG" ] = &trig_EF_trigmuonef_EF_mu24_tight_MG;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_tight_MuonEF" ] = &trig_EF_trigmuonef_EF_mu24_tight_MuonEF;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad" ] = &trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad;
      fHandles[ "trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS" ] = &trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS;
      fHandles[ "trig_EF_trigmuonef_EF_mu24i_tight" ] = &trig_EF_trigmuonef_EF_mu24i_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu24i_tight_MG" ] = &trig_EF_trigmuonef_EF_mu24i_tight_MG;
      fHandles[ "trig_EF_trigmuonef_EF_mu24i_tight_MuonEF" ] = &trig_EF_trigmuonef_EF_mu24i_tight_MuonEF;
      fHandles[ "trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA" ] = &trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA;
      fHandles[ "trig_EF_trigmuonef_EF_mu36_tight" ] = &trig_EF_trigmuonef_EF_mu36_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight" ] = &trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF" ] = &trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF;
      fHandles[ "trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight" ] = &trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu40_slow_tight" ] = &trig_EF_trigmuonef_EF_mu40_slow_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu40_tight" ] = &trig_EF_trigmuonef_EF_mu40_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T" ] = &trig_EF_trigmuonef_EF_mu4T;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_cosmic" ] = &trig_EF_trigmuonef_EF_mu4T_cosmic;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ" ] = &trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ" ] = &trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ" ] = &trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ" ] = &trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ" ] = &trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ" ] = &trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ" ] = &trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose" ] = &trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose" ] = &trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched" ] = &trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium" ] = &trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass" ] = &trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_DiMu" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_DiMu;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu;
      fHandles[ "trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel" ] = &trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel;
      fHandles[ "trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic" ] = &trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic;
      fHandles[ "trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic" ] = &trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic;
      fHandles[ "trig_EF_trigmuonef_EF_mu4_empty_NoAlg" ] = &trig_EF_trigmuonef_EF_mu4_empty_NoAlg;
      fHandles[ "trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg" ] = &trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg;
      fHandles[ "trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg" ] = &trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg;
      fHandles[ "trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight" ] = &trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu6" ] = &trig_EF_trigmuonef_EF_mu6;
      fHandles[ "trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1" ] = &trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1;
      fHandles[ "trig_EF_trigmuonef_EF_mu60_slow_tight1" ] = &trig_EF_trigmuonef_EF_mu60_slow_tight1;
      fHandles[ "trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight" ] = &trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu6_MSonly" ] = &trig_EF_trigmuonef_EF_mu6_MSonly;
      fHandles[ "trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose" ] = &trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose;
      fHandles[ "trig_EF_trigmuonef_EF_mu8" ] = &trig_EF_trigmuonef_EF_mu8;
      fHandles[ "trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS" ] = &trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS;
      fHandles[ "trig_EF_trigmuonef_track_MuonType" ] = &trig_EF_trigmuonef_track_MuonType;
      fHandles[ "trig_EF_trigmuonef_track_MS_pt" ] = &trig_EF_trigmuonef_track_MS_pt;
      fHandles[ "trig_EF_trigmuonef_track_MS_eta" ] = &trig_EF_trigmuonef_track_MS_eta;
      fHandles[ "trig_EF_trigmuonef_track_MS_phi" ] = &trig_EF_trigmuonef_track_MS_phi;
      fHandles[ "trig_EF_trigmuonef_track_MS_hasMS" ] = &trig_EF_trigmuonef_track_MS_hasMS;
      fHandles[ "trig_EF_trigmuonef_track_SA_pt" ] = &trig_EF_trigmuonef_track_SA_pt;
      fHandles[ "trig_EF_trigmuonef_track_SA_eta" ] = &trig_EF_trigmuonef_track_SA_eta;
      fHandles[ "trig_EF_trigmuonef_track_SA_phi" ] = &trig_EF_trigmuonef_track_SA_phi;
      fHandles[ "trig_EF_trigmuonef_track_SA_hasSA" ] = &trig_EF_trigmuonef_track_SA_hasSA;
    
    // =============================================================================
    // = MC only
    // =============================================================================
      fHandles[ "trig_EF_el_EF_e12Tvh_loose1_mu8" ] = &trig_EF_el_EF_e12Tvh_loose1_mu8;
      fHandles[ "trig_EF_el_EF_e12Tvh_medium1_mu10" ] = &trig_EF_el_EF_e12Tvh_medium1_mu10;
      fHandles[ "trig_EF_el_EF_e12Tvh_medium1_mu6" ] = &trig_EF_el_EF_e12Tvh_medium1_mu6;
      fHandles[ "trig_EF_el_EF_e18_loose1_g35_loose" ] = &trig_EF_el_EF_e18_loose1_g35_loose;
      fHandles[ "trig_EF_el_EF_e18_loose1_g35_medium" ] = &trig_EF_el_EF_e18_loose1_g35_medium;
      fHandles[ "trig_EF_el_EF_e18_medium1_g25_medium" ] = &trig_EF_el_EF_e18_medium1_g25_medium;
      fHandles[ "trig_EF_el_EF_e18_medium1_g35_loose" ] = &trig_EF_el_EF_e18_medium1_g35_loose;
      fHandles[ "trig_EF_el_EF_e18_medium1_g35_medium" ] = &trig_EF_el_EF_e18_medium1_g35_medium;
      fHandles[ "trig_EF_el_EF_e22vh_medium1_IdScan" ] = &trig_EF_el_EF_e22vh_medium1_IdScan;
      fHandles[ "trig_EF_el_EF_e22vh_medium1_SiTrk" ] = &trig_EF_el_EF_e22vh_medium1_SiTrk;
      fHandles[ "trig_EF_el_EF_e22vh_medium1_TRT" ] = &trig_EF_el_EF_e22vh_medium1_TRT;
      fHandles[ "trig_EF_el_EF_e45_etcut" ] = &trig_EF_el_EF_e45_etcut;
      fHandles[ "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan" ] = &trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan;
      fHandles[ "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk" ] = &trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk;
      fHandles[ "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT" ] = &trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT;
      fHandles[ "trig_EF_el_EF_e60_etcut" ] = &trig_EF_el_EF_e60_etcut;
    
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* TriggerVecD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void TriggerVecD3PDObject::SetPrefix( const char* prefix ) {

      trig_EF_el_EF_2e12Tvh_loose1.SetName( ::TString( prefix ) + "trig_EF_el_EF_2e12Tvh_loose1" );
      trig_EF_el_EF_2e5_tight1_Jpsi.SetName( ::TString( prefix ) + "trig_EF_el_EF_2e5_tight1_Jpsi" );
      trig_EF_el_EF_2e7T_loose1_mu6.SetName( ::TString( prefix ) + "trig_EF_el_EF_2e7T_loose1_mu6" );
      trig_EF_el_EF_2e7T_medium1_mu6.SetName( ::TString( prefix ) + "trig_EF_el_EF_2e7T_medium1_mu6" );
      trig_EF_el_EF_e11_etcut.SetName( ::TString( prefix ) + "trig_EF_el_EF_e11_etcut" );
      trig_EF_el_EF_e12Tvh_loose1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_loose1" );
      trig_EF_el_EF_e12Tvh_medium1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_medium1" );
      trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium.SetName( ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium" );
      trig_EF_el_EF_e12Tvh_medium1_mu8.SetName( ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_medium1_mu8" );
      trig_EF_el_EF_e13_etcutTrk_xs60.SetName( ::TString( prefix ) + "trig_EF_el_EF_e13_etcutTrk_xs60" );
      trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20.SetName( ::TString( prefix ) + "trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20" );
      trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi.SetName( ::TString( prefix ) + "trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi" );
      trig_EF_el_EF_e15vh_medium1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e15vh_medium1" );
      trig_EF_el_EF_e18_loose1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e18_loose1" );
      trig_EF_el_EF_e18_loose1_g25_medium.SetName( ::TString( prefix ) + "trig_EF_el_EF_e18_loose1_g25_medium" );
      trig_EF_el_EF_e18_medium1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e18_medium1" );
      trig_EF_el_EF_e18_medium1_g25_loose.SetName( ::TString( prefix ) + "trig_EF_el_EF_e18_medium1_g25_loose" );
      trig_EF_el_EF_e18vh_medium1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e18vh_medium1" );
      trig_EF_el_EF_e18vh_medium1_2e7T_medium1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e18vh_medium1_2e7T_medium1" );
      trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20.SetName( ::TString( prefix ) + "trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20" );
      trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20.SetName( ::TString( prefix ) + "trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20" );
      trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi.SetName( ::TString( prefix ) + "trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi" );
      trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi.SetName( ::TString( prefix ) + "trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi" );
      trig_EF_el_EF_e22vh_loose.SetName( ::TString( prefix ) + "trig_EF_el_EF_e22vh_loose" );
      trig_EF_el_EF_e22vh_loose0.SetName( ::TString( prefix ) + "trig_EF_el_EF_e22vh_loose0" );
      trig_EF_el_EF_e22vh_loose1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e22vh_loose1" );
      trig_EF_el_EF_e22vh_medium1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e22vh_medium1" );
      trig_EF_el_EF_e22vh_medium1_IDTrkNoCut.SetName( ::TString( prefix ) + "trig_EF_el_EF_e22vh_medium1_IDTrkNoCut" );
      trig_EF_el_EF_e22vhi_medium1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e22vhi_medium1" );
      trig_EF_el_EF_e24vh_loose.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_loose" );
      trig_EF_el_EF_e24vh_loose0.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_loose0" );
      trig_EF_el_EF_e24vh_loose1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_loose1" );
      trig_EF_el_EF_e24vh_medium1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1" );
      trig_EF_el_EF_e24vh_medium1_EFxe30.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_EFxe30" );
      trig_EF_el_EF_e24vh_medium1_EFxe30_tcem.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_EFxe30_tcem" );
      trig_EF_el_EF_e24vh_medium1_EFxe35_tcem.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_EFxe35_tcem" );
      trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw" );
      trig_EF_el_EF_e24vh_medium1_EFxe40.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_EFxe40" );
      trig_EF_el_EF_e24vh_medium1_IDTrkNoCut.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_IDTrkNoCut" );
      trig_EF_el_EF_e24vh_medium1_IdScan.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_IdScan" );
      trig_EF_el_EF_e24vh_medium1_L2StarB.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_L2StarB" );
      trig_EF_el_EF_e24vh_medium1_L2StarC.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_L2StarC" );
      trig_EF_el_EF_e24vh_medium1_SiTrk.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_SiTrk" );
      trig_EF_el_EF_e24vh_medium1_TRT.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_TRT" );
      trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad" );
      trig_EF_el_EF_e24vh_medium1_e7_medium1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_e7_medium1" );
      trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee" );
      trig_EF_el_EF_e24vhi_loose1_mu8.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vhi_loose1_mu8" );
      trig_EF_el_EF_e24vhi_medium1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vhi_medium1" );
      trig_EF_el_EF_e45_medium1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e45_medium1" );
      trig_EF_el_EF_e5_tight1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e5_tight1" );
      trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi.SetName( ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi" );
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi.SetName( ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi" );
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB.SetName( ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB" );
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC.SetName( ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC" );
      trig_EF_el_EF_e5_tight1_e5_NoCut.SetName( ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e5_NoCut" );
      trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi.SetName( ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi" );
      trig_EF_el_EF_e60_medium1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e60_medium1" );
      trig_EF_el_EF_e7T_loose1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e7T_loose1" );
      trig_EF_el_EF_e7T_loose1_2mu6.SetName( ::TString( prefix ) + "trig_EF_el_EF_e7T_loose1_2mu6" );
      trig_EF_el_EF_e7T_medium1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e7T_medium1" );
      trig_EF_el_EF_e7T_medium1_2mu6.SetName( ::TString( prefix ) + "trig_EF_el_EF_e7T_medium1_2mu6" );
      trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi.SetName( ::TString( prefix ) + "trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi" );
      trig_EF_el_EF_eb_physics.SetName( ::TString( prefix ) + "trig_EF_el_EF_eb_physics" );
      trig_EF_el_EF_eb_physics_empty.SetName( ::TString( prefix ) + "trig_EF_el_EF_eb_physics_empty" );
      trig_EF_el_EF_eb_physics_firstempty.SetName( ::TString( prefix ) + "trig_EF_el_EF_eb_physics_firstempty" );
      trig_EF_el_EF_eb_physics_noL1PS.SetName( ::TString( prefix ) + "trig_EF_el_EF_eb_physics_noL1PS" );
      trig_EF_el_EF_eb_physics_unpaired_iso.SetName( ::TString( prefix ) + "trig_EF_el_EF_eb_physics_unpaired_iso" );
      trig_EF_el_EF_eb_physics_unpaired_noniso.SetName( ::TString( prefix ) + "trig_EF_el_EF_eb_physics_unpaired_noniso" );
      trig_EF_el_EF_eb_random.SetName( ::TString( prefix ) + "trig_EF_el_EF_eb_random" );
      trig_EF_el_EF_eb_random_empty.SetName( ::TString( prefix ) + "trig_EF_el_EF_eb_random_empty" );
      trig_EF_el_EF_eb_random_firstempty.SetName( ::TString( prefix ) + "trig_EF_el_EF_eb_random_firstempty" );
      trig_EF_el_EF_eb_random_unpaired_iso.SetName( ::TString( prefix ) + "trig_EF_el_EF_eb_random_unpaired_iso" );
      trig_EF_emcl_pt.SetName( ::TString( prefix ) + "trig_EF_emcl_pt" );
      trig_EF_emcl_eta.SetName( ::TString( prefix ) + "trig_EF_emcl_eta" );
      trig_EF_emcl_phi.SetName( ::TString( prefix ) + "trig_EF_emcl_phi" );
      trig_EF_emcl_E_em.SetName( ::TString( prefix ) + "trig_EF_emcl_E_em" );
      trig_EF_emcl_E_had.SetName( ::TString( prefix ) + "trig_EF_emcl_E_had" );
      trig_EF_emcl_slw_pt.SetName( ::TString( prefix ) + "trig_EF_emcl_slw_pt" );
      trig_EF_emcl_slw_eta.SetName( ::TString( prefix ) + "trig_EF_emcl_slw_eta" );
      trig_EF_emcl_slw_phi.SetName( ::TString( prefix ) + "trig_EF_emcl_slw_phi" );
      trig_EF_emcl_slw_E_em.SetName( ::TString( prefix ) + "trig_EF_emcl_slw_E_em" );
      trig_EF_emcl_slw_E_had.SetName( ::TString( prefix ) + "trig_EF_emcl_slw_E_had" );
      trig_EF_el_E.SetName( ::TString( prefix ) + "trig_EF_el_E" );
      trig_EF_el_Et.SetName( ::TString( prefix ) + "trig_EF_el_Et" );
      trig_EF_el_pt.SetName( ::TString( prefix ) + "trig_EF_el_pt" );
      trig_EF_el_m.SetName( ::TString( prefix ) + "trig_EF_el_m" );
      trig_EF_el_eta.SetName( ::TString( prefix ) + "trig_EF_el_eta" );
      trig_EF_el_phi.SetName( ::TString( prefix ) + "trig_EF_el_phi" );
      trig_EF_el_px.SetName( ::TString( prefix ) + "trig_EF_el_px" );
      trig_EF_el_py.SetName( ::TString( prefix ) + "trig_EF_el_py" );
      trig_EF_el_pz.SetName( ::TString( prefix ) + "trig_EF_el_pz" );
      trig_EF_el_charge.SetName( ::TString( prefix ) + "trig_EF_el_charge" );
      trig_EF_el_author.SetName( ::TString( prefix ) + "trig_EF_el_author" );
      trig_EF_el_isEM.SetName( ::TString( prefix ) + "trig_EF_el_isEM" );
      trig_EF_el_isEMLoose.SetName( ::TString( prefix ) + "trig_EF_el_isEMLoose" );
      trig_EF_el_isEMMedium.SetName( ::TString( prefix ) + "trig_EF_el_isEMMedium" );
      trig_EF_el_isEMTight.SetName( ::TString( prefix ) + "trig_EF_el_isEMTight" );
      trig_EF_el_loose.SetName( ::TString( prefix ) + "trig_EF_el_loose" );
      trig_EF_el_looseIso.SetName( ::TString( prefix ) + "trig_EF_el_looseIso" );
      trig_EF_el_medium.SetName( ::TString( prefix ) + "trig_EF_el_medium" );
      trig_EF_el_mediumIso.SetName( ::TString( prefix ) + "trig_EF_el_mediumIso" );
      trig_EF_el_mediumWithoutTrack.SetName( ::TString( prefix ) + "trig_EF_el_mediumWithoutTrack" );
      trig_EF_el_mediumIsoWithoutTrack.SetName( ::TString( prefix ) + "trig_EF_el_mediumIsoWithoutTrack" );
      trig_EF_el_tight.SetName( ::TString( prefix ) + "trig_EF_el_tight" );
      trig_EF_el_tightIso.SetName( ::TString( prefix ) + "trig_EF_el_tightIso" );
      trig_EF_el_tightWithoutTrack.SetName( ::TString( prefix ) + "trig_EF_el_tightWithoutTrack" );
      trig_EF_el_tightIsoWithoutTrack.SetName( ::TString( prefix ) + "trig_EF_el_tightIsoWithoutTrack" );
      trig_EF_el_loosePP.SetName( ::TString( prefix ) + "trig_EF_el_loosePP" );
      trig_EF_el_loosePPIso.SetName( ::TString( prefix ) + "trig_EF_el_loosePPIso" );
      trig_EF_el_mediumPP.SetName( ::TString( prefix ) + "trig_EF_el_mediumPP" );
      trig_EF_el_mediumPPIso.SetName( ::TString( prefix ) + "trig_EF_el_mediumPPIso" );
      trig_EF_el_tightPP.SetName( ::TString( prefix ) + "trig_EF_el_tightPP" );
      trig_EF_el_tightPPIso.SetName( ::TString( prefix ) + "trig_EF_el_tightPPIso" );
      trig_EF_el_vertweight.SetName( ::TString( prefix ) + "trig_EF_el_vertweight" );
      trig_EF_el_hastrack.SetName( ::TString( prefix ) + "trig_EF_el_hastrack" );
      trig_EF_trigmuonef_track_CB_pt.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_pt" );
      trig_EF_trigmuonef_track_CB_eta.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_eta" );
      trig_EF_trigmuonef_track_CB_phi.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_phi" );
      trig_EF_trigmuonef_track_CB_hasCB.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_hasCB" );

    // =============================================================================
    // = Data only
    // =============================================================================
      trig_EF_trigmuonef_EF_2mu10.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu10" );
      trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose" );
      trig_EF_trigmuonef_EF_2mu13.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu13" );
      trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut" );
      trig_EF_trigmuonef_EF_2mu13_l2muonSA.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu13_l2muonSA" );
      trig_EF_trigmuonef_EF_2mu15.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu15" );
      trig_EF_trigmuonef_EF_2mu4T.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T" );
      trig_EF_trigmuonef_EF_2mu4T_2e5_tight1.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_2e5_tight1" );
      trig_EF_trigmuonef_EF_2mu4T_Bmumu.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Bmumu" );
      trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel" );
      trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly" );
      trig_EF_trigmuonef_EF_2mu4T_Bmumux.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Bmumux" );
      trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel" );
      trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly" );
      trig_EF_trigmuonef_EF_2mu4T_DiMu.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu" );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel" );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly" );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB" );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC" );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1" );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA" );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS" );
      trig_EF_trigmuonef_EF_2mu4T_Jpsimumu.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu" );
      trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel" );
      trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly" );
      trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut" );
      trig_EF_trigmuonef_EF_2mu4T_Upsimumu.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Upsimumu" );
      trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel" );
      trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly" );
      trig_EF_trigmuonef_EF_2mu4T_xe60.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_xe60" );
      trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw" );
      trig_EF_trigmuonef_EF_2mu6.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6" );
      trig_EF_trigmuonef_EF_2mu6_Bmumu.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_Bmumu" );
      trig_EF_trigmuonef_EF_2mu6_Bmumux.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_Bmumux" );
      trig_EF_trigmuonef_EF_2mu6_DiMu.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_DiMu" );
      trig_EF_trigmuonef_EF_2mu6_DiMu_DY20.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_DiMu_DY20" );
      trig_EF_trigmuonef_EF_2mu6_DiMu_DY25.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_DiMu_DY25" );
      trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS" );
      trig_EF_trigmuonef_EF_2mu6_Jpsimumu.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_Jpsimumu" );
      trig_EF_trigmuonef_EF_2mu6_Upsimumu.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6_Upsimumu" );
      trig_EF_trigmuonef_EF_2mu6i_DiMu_DY.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY" );
      trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad" );
      trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS" );
      trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad" );
      trig_EF_trigmuonef_EF_2mu8_EFxe30.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu8_EFxe30" );
      trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw" );
      trig_EF_trigmuonef_EF_mu10.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10" );
      trig_EF_trigmuonef_EF_mu10_Jpsimumu.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10_Jpsimumu" );
      trig_EF_trigmuonef_EF_mu10_MSonly.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10_MSonly" );
      trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS" );
      trig_EF_trigmuonef_EF_mu10i_g10_medium.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10i_g10_medium" );
      trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass" );
      trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium" );
      trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass" );
      trig_EF_trigmuonef_EF_mu11_empty_NoAlg.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu11_empty_NoAlg" );
      trig_EF_trigmuonef_EF_mu13.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu13" );
      trig_EF_trigmuonef_EF_mu15.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu15" );
      trig_EF_trigmuonef_EF_mu18.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18" );
      trig_EF_trigmuonef_EF_mu18_2g10_loose.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_2g10_loose" );
      trig_EF_trigmuonef_EF_mu18_2g10_medium.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_2g10_medium" );
      trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight" );
      trig_EF_trigmuonef_EF_mu18_medium.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_medium" );
      trig_EF_trigmuonef_EF_mu18_tight.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_tight" );
      trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS" );
      trig_EF_trigmuonef_EF_mu18_tight_e7_medium1.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_tight_e7_medium1" );
      trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS" );
      trig_EF_trigmuonef_EF_mu18i4_tight.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18i4_tight" );
      trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass" );
      trig_EF_trigmuonef_EF_mu20i_tight_g5_medium.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu20i_tight_g5_medium" );
      trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass" );
      trig_EF_trigmuonef_EF_mu20it_tight.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu20it_tight" );
      trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight" );
      trig_EF_trigmuonef_EF_mu24.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24" );
      trig_EF_trigmuonef_EF_mu24_g20vh_loose.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_g20vh_loose" );
      trig_EF_trigmuonef_EF_mu24_g20vh_medium.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_g20vh_medium" );
      trig_EF_trigmuonef_EF_mu24_j65_a4tchad.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_j65_a4tchad" );
      trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40" );
      trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw" );
      trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw" );
      trig_EF_trigmuonef_EF_mu24_medium.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_medium" );
      trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight" );
      trig_EF_trigmuonef_EF_mu24_tight.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight" );
      trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad" );
      trig_EF_trigmuonef_EF_mu24_tight_EFxe40.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_EFxe40" );
      trig_EF_trigmuonef_EF_mu24_tight_L2StarB.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_L2StarB" );
      trig_EF_trigmuonef_EF_mu24_tight_L2StarC.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_L2StarC" );
      trig_EF_trigmuonef_EF_mu24_tight_MG.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_MG" );
      trig_EF_trigmuonef_EF_mu24_tight_MuonEF.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_MuonEF" );
      trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad" );
      trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS" );
      trig_EF_trigmuonef_EF_mu24i_tight.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24i_tight" );
      trig_EF_trigmuonef_EF_mu24i_tight_MG.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24i_tight_MG" );
      trig_EF_trigmuonef_EF_mu24i_tight_MuonEF.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24i_tight_MuonEF" );
      trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA" );
      trig_EF_trigmuonef_EF_mu36_tight.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu36_tight" );
      trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight" );
      trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF" );
      trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight" );
      trig_EF_trigmuonef_EF_mu40_slow_tight.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu40_slow_tight" );
      trig_EF_trigmuonef_EF_mu40_tight.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu40_tight" );
      trig_EF_trigmuonef_EF_mu4T.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T" );
      trig_EF_trigmuonef_EF_mu4T_cosmic.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_cosmic" );
      trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched" );
      trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched" );
      trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched" );
      trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched" );
      trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched" );
      trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ" );
      trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched" );
      trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched" );
      trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched" );
      trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched" );
      trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched" );
      trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ" );
      trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched" );
      trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched" );
      trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched" );
      trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ" );
      trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched" );
      trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ" );
      trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched" );
      trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ" );
      trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched" );
      trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ" );
      trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched" );
      trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ" );
      trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched" );
      trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched" );
      trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose" );
      trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose" );
      trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched" );
      trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched" );
      trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium" );
      trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass" );
      trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu" );
      trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel" );
      trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux" );
      trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel" );
      trig_EF_trigmuonef_EF_mu4Tmu6_DiMu.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_DiMu" );
      trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel" );
      trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS" );
      trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu" );
      trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel" );
      trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut" );
      trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu" );
      trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel" );
      trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic" );
      trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic" );
      trig_EF_trigmuonef_EF_mu4_empty_NoAlg.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4_empty_NoAlg" );
      trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg" );
      trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg" );
      trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight" );
      trig_EF_trigmuonef_EF_mu6.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu6" );
      trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1" );
      trig_EF_trigmuonef_EF_mu60_slow_tight1.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu60_slow_tight1" );
      trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight" );
      trig_EF_trigmuonef_EF_mu6_MSonly.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu6_MSonly" );
      trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose" );
      trig_EF_trigmuonef_EF_mu8.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu8" );
      trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS" );
      trig_EF_trigmuonef_track_MuonType.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_track_MuonType" );
      trig_EF_trigmuonef_track_MS_pt.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_track_MS_pt" );
      trig_EF_trigmuonef_track_MS_eta.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_track_MS_eta" );
      trig_EF_trigmuonef_track_MS_phi.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_track_MS_phi" );
      trig_EF_trigmuonef_track_MS_hasMS.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_track_MS_hasMS" );
      trig_EF_trigmuonef_track_SA_pt.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_track_SA_pt" );
      trig_EF_trigmuonef_track_SA_eta.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_track_SA_eta" );
      trig_EF_trigmuonef_track_SA_phi.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_track_SA_phi" );
      trig_EF_trigmuonef_track_SA_hasSA.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_track_SA_hasSA" );
    
    // =============================================================================
    // = MC only
    // =============================================================================
      trig_EF_el_EF_e12Tvh_loose1_mu8.SetName( ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_loose1_mu8" );
      trig_EF_el_EF_e12Tvh_medium1_mu10.SetName( ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_medium1_mu10" );
      trig_EF_el_EF_e12Tvh_medium1_mu6.SetName( ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_medium1_mu6" );
      trig_EF_el_EF_e18_loose1_g35_loose.SetName( ::TString( prefix ) + "trig_EF_el_EF_e18_loose1_g35_loose" );
      trig_EF_el_EF_e18_loose1_g35_medium.SetName( ::TString( prefix ) + "trig_EF_el_EF_e18_loose1_g35_medium" );
      trig_EF_el_EF_e18_medium1_g25_medium.SetName( ::TString( prefix ) + "trig_EF_el_EF_e18_medium1_g25_medium" );
      trig_EF_el_EF_e18_medium1_g35_loose.SetName( ::TString( prefix ) + "trig_EF_el_EF_e18_medium1_g35_loose" );
      trig_EF_el_EF_e18_medium1_g35_medium.SetName( ::TString( prefix ) + "trig_EF_el_EF_e18_medium1_g35_medium" );
      trig_EF_el_EF_e22vh_medium1_IdScan.SetName( ::TString( prefix ) + "trig_EF_el_EF_e22vh_medium1_IdScan" );
      trig_EF_el_EF_e22vh_medium1_SiTrk.SetName( ::TString( prefix ) + "trig_EF_el_EF_e22vh_medium1_SiTrk" );
      trig_EF_el_EF_e22vh_medium1_TRT.SetName( ::TString( prefix ) + "trig_EF_el_EF_e22vh_medium1_TRT" );
      trig_EF_el_EF_e45_etcut.SetName( ::TString( prefix ) + "trig_EF_el_EF_e45_etcut" );
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan.SetName( ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan" );
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk.SetName( ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk" );
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT.SetName( ::TString( prefix ) + "trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT" );
      trig_EF_el_EF_e60_etcut.SetName( ::TString( prefix ) + "trig_EF_el_EF_e60_etcut" );
    
      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void TriggerVecD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      trig_EF_el_EF_2e12Tvh_loose1.ReadFrom( tree );
      trig_EF_el_EF_2e5_tight1_Jpsi.ReadFrom( tree );
      trig_EF_el_EF_2e7T_loose1_mu6.ReadFrom( tree );
      trig_EF_el_EF_2e7T_medium1_mu6.ReadFrom( tree );
      trig_EF_el_EF_e11_etcut.ReadFrom( tree );
      trig_EF_el_EF_e12Tvh_loose1.ReadFrom( tree );
      trig_EF_el_EF_e12Tvh_medium1.ReadFrom( tree );
      trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium.ReadFrom( tree );
      trig_EF_el_EF_e12Tvh_medium1_mu8.ReadFrom( tree );
      trig_EF_el_EF_e13_etcutTrk_xs60.ReadFrom( tree );
      trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20.ReadFrom( tree );
      trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi.ReadFrom( tree );
      trig_EF_el_EF_e15vh_medium1.ReadFrom( tree );
      trig_EF_el_EF_e18_loose1.ReadFrom( tree );
      trig_EF_el_EF_e18_loose1_g25_medium.ReadFrom( tree );
      trig_EF_el_EF_e18_medium1.ReadFrom( tree );
      trig_EF_el_EF_e18_medium1_g25_loose.ReadFrom( tree );
      trig_EF_el_EF_e18vh_medium1.ReadFrom( tree );
      trig_EF_el_EF_e18vh_medium1_2e7T_medium1.ReadFrom( tree );
      trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20.ReadFrom( tree );
      trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20.ReadFrom( tree );
      trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi.ReadFrom( tree );
      trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi.ReadFrom( tree );
      trig_EF_el_EF_e22vh_loose.ReadFrom( tree );
      trig_EF_el_EF_e22vh_loose0.ReadFrom( tree );
      trig_EF_el_EF_e22vh_loose1.ReadFrom( tree );
      trig_EF_el_EF_e22vh_medium1.ReadFrom( tree );
      trig_EF_el_EF_e22vh_medium1_IDTrkNoCut.ReadFrom( tree );
      trig_EF_el_EF_e22vhi_medium1.ReadFrom( tree );
      trig_EF_el_EF_e24vh_loose.ReadFrom( tree );
      trig_EF_el_EF_e24vh_loose0.ReadFrom( tree );
      trig_EF_el_EF_e24vh_loose1.ReadFrom( tree );
      trig_EF_el_EF_e24vh_medium1.ReadFrom( tree );
      trig_EF_el_EF_e24vh_medium1_EFxe30.ReadFrom( tree );
      trig_EF_el_EF_e24vh_medium1_EFxe30_tcem.ReadFrom( tree );
      trig_EF_el_EF_e24vh_medium1_EFxe35_tcem.ReadFrom( tree );
      trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw.ReadFrom( tree );
      trig_EF_el_EF_e24vh_medium1_EFxe40.ReadFrom( tree );
      trig_EF_el_EF_e24vh_medium1_IDTrkNoCut.ReadFrom( tree );
      trig_EF_el_EF_e24vh_medium1_IdScan.ReadFrom( tree );
      trig_EF_el_EF_e24vh_medium1_L2StarB.ReadFrom( tree );
      trig_EF_el_EF_e24vh_medium1_L2StarC.ReadFrom( tree );
      trig_EF_el_EF_e24vh_medium1_SiTrk.ReadFrom( tree );
      trig_EF_el_EF_e24vh_medium1_TRT.ReadFrom( tree );
      trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad.ReadFrom( tree );
      trig_EF_el_EF_e24vh_medium1_e7_medium1.ReadFrom( tree );
      trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee.ReadFrom( tree );
      trig_EF_el_EF_e24vhi_loose1_mu8.ReadFrom( tree );
      trig_EF_el_EF_e24vhi_medium1.ReadFrom( tree );
      trig_EF_el_EF_e45_medium1.ReadFrom( tree );
      trig_EF_el_EF_e5_tight1.ReadFrom( tree );
      trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi.ReadFrom( tree );
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi.ReadFrom( tree );
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB.ReadFrom( tree );
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC.ReadFrom( tree );
      trig_EF_el_EF_e5_tight1_e5_NoCut.ReadFrom( tree );
      trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi.ReadFrom( tree );
      trig_EF_el_EF_e60_medium1.ReadFrom( tree );
      trig_EF_el_EF_e7T_loose1.ReadFrom( tree );
      trig_EF_el_EF_e7T_loose1_2mu6.ReadFrom( tree );
      trig_EF_el_EF_e7T_medium1.ReadFrom( tree );
      trig_EF_el_EF_e7T_medium1_2mu6.ReadFrom( tree );
      trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi.ReadFrom( tree );
      trig_EF_el_EF_eb_physics.ReadFrom( tree );
      trig_EF_el_EF_eb_physics_empty.ReadFrom( tree );
      trig_EF_el_EF_eb_physics_firstempty.ReadFrom( tree );
      trig_EF_el_EF_eb_physics_noL1PS.ReadFrom( tree );
      trig_EF_el_EF_eb_physics_unpaired_iso.ReadFrom( tree );
      trig_EF_el_EF_eb_physics_unpaired_noniso.ReadFrom( tree );
      trig_EF_el_EF_eb_random.ReadFrom( tree );
      trig_EF_el_EF_eb_random_empty.ReadFrom( tree );
      trig_EF_el_EF_eb_random_firstempty.ReadFrom( tree );
      trig_EF_el_EF_eb_random_unpaired_iso.ReadFrom( tree );
      trig_EF_emcl_pt.ReadFrom( tree );
      trig_EF_emcl_eta.ReadFrom( tree );
      trig_EF_emcl_phi.ReadFrom( tree );
      trig_EF_emcl_E_em.ReadFrom( tree );
      trig_EF_emcl_E_had.ReadFrom( tree );
      trig_EF_emcl_slw_pt.ReadFrom( tree );
      trig_EF_emcl_slw_eta.ReadFrom( tree );
      trig_EF_emcl_slw_phi.ReadFrom( tree );
      trig_EF_emcl_slw_E_em.ReadFrom( tree );
      trig_EF_emcl_slw_E_had.ReadFrom( tree );
      trig_EF_el_E.ReadFrom( tree );
      trig_EF_el_Et.ReadFrom( tree );
      trig_EF_el_pt.ReadFrom( tree );
      trig_EF_el_m.ReadFrom( tree );
      trig_EF_el_eta.ReadFrom( tree );
      trig_EF_el_phi.ReadFrom( tree );
      trig_EF_el_px.ReadFrom( tree );
      trig_EF_el_py.ReadFrom( tree );
      trig_EF_el_pz.ReadFrom( tree );
      trig_EF_el_charge.ReadFrom( tree );
      trig_EF_el_author.ReadFrom( tree );
      trig_EF_el_isEM.ReadFrom( tree );
      trig_EF_el_isEMLoose.ReadFrom( tree );
      trig_EF_el_isEMMedium.ReadFrom( tree );
      trig_EF_el_isEMTight.ReadFrom( tree );
      trig_EF_el_loose.ReadFrom( tree );
      trig_EF_el_looseIso.ReadFrom( tree );
      trig_EF_el_medium.ReadFrom( tree );
      trig_EF_el_mediumIso.ReadFrom( tree );
      trig_EF_el_mediumWithoutTrack.ReadFrom( tree );
      trig_EF_el_mediumIsoWithoutTrack.ReadFrom( tree );
      trig_EF_el_tight.ReadFrom( tree );
      trig_EF_el_tightIso.ReadFrom( tree );
      trig_EF_el_tightWithoutTrack.ReadFrom( tree );
      trig_EF_el_tightIsoWithoutTrack.ReadFrom( tree );
      trig_EF_el_loosePP.ReadFrom( tree );
      trig_EF_el_loosePPIso.ReadFrom( tree );
      trig_EF_el_mediumPP.ReadFrom( tree );
      trig_EF_el_mediumPPIso.ReadFrom( tree );
      trig_EF_el_tightPP.ReadFrom( tree );
      trig_EF_el_tightPPIso.ReadFrom( tree );
      trig_EF_el_vertweight.ReadFrom( tree );
      trig_EF_el_hastrack.ReadFrom( tree );
      trig_EF_trigmuonef_track_CB_pt.ReadFrom( tree );
      trig_EF_trigmuonef_track_CB_eta.ReadFrom( tree );
      trig_EF_trigmuonef_track_CB_phi.ReadFrom( tree );
      trig_EF_trigmuonef_track_CB_hasCB.ReadFrom( tree );

    // =============================================================================
    // = Data only
    // =============================================================================
      trig_EF_trigmuonef_EF_2mu10.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu13.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu13_l2muonSA.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu15.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_2e5_tight1.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_Bmumu.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_Bmumux.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_DiMu.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_Jpsimumu.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_Upsimumu.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_xe60.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu6.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu6_Bmumu.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu6_Bmumux.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu6_DiMu.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu6_DiMu_DY20.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu6_DiMu_DY25.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu6_Jpsimumu.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu6_Upsimumu.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu6i_DiMu_DY.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu8_EFxe30.ReadFrom( tree );
      trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu10.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu10_Jpsimumu.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu10_MSonly.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu10i_g10_medium.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu11_empty_NoAlg.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu13.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu15.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu18.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu18_2g10_loose.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu18_2g10_medium.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu18_medium.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu18_tight.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu18_tight_e7_medium1.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu18i4_tight.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu20i_tight_g5_medium.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu20it_tight.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24_g20vh_loose.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24_g20vh_medium.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24_j65_a4tchad.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24_medium.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24_tight.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24_tight_EFxe40.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24_tight_L2StarB.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24_tight_L2StarC.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24_tight_MG.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24_tight_MuonEF.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24i_tight.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24i_tight_MG.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24i_tight_MuonEF.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu36_tight.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu40_slow_tight.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu40_tight.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_cosmic.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_DiMu.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4_empty_NoAlg.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu6.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu60_slow_tight1.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu6_MSonly.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu8.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS.ReadFrom( tree );
      trig_EF_trigmuonef_track_MuonType.ReadFrom( tree );
      trig_EF_trigmuonef_track_MS_pt.ReadFrom( tree );
      trig_EF_trigmuonef_track_MS_eta.ReadFrom( tree );
      trig_EF_trigmuonef_track_MS_phi.ReadFrom( tree );
      trig_EF_trigmuonef_track_MS_hasMS.ReadFrom( tree );
      trig_EF_trigmuonef_track_SA_pt.ReadFrom( tree );
      trig_EF_trigmuonef_track_SA_eta.ReadFrom( tree );
      trig_EF_trigmuonef_track_SA_phi.ReadFrom( tree );
      trig_EF_trigmuonef_track_SA_hasSA.ReadFrom( tree );
    
    // =============================================================================
    // = MC only
    // =============================================================================
      trig_EF_el_EF_e12Tvh_loose1_mu8.ReadFrom( tree );
      trig_EF_el_EF_e12Tvh_medium1_mu10.ReadFrom( tree );
      trig_EF_el_EF_e12Tvh_medium1_mu6.ReadFrom( tree );
      trig_EF_el_EF_e18_loose1_g35_loose.ReadFrom( tree );
      trig_EF_el_EF_e18_loose1_g35_medium.ReadFrom( tree );
      trig_EF_el_EF_e18_medium1_g25_medium.ReadFrom( tree );
      trig_EF_el_EF_e18_medium1_g35_loose.ReadFrom( tree );
      trig_EF_el_EF_e18_medium1_g35_medium.ReadFrom( tree );
      trig_EF_el_EF_e22vh_medium1_IdScan.ReadFrom( tree );
      trig_EF_el_EF_e22vh_medium1_SiTrk.ReadFrom( tree );
      trig_EF_el_EF_e22vh_medium1_TRT.ReadFrom( tree );
      trig_EF_el_EF_e45_etcut.ReadFrom( tree );
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan.ReadFrom( tree );
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk.ReadFrom( tree );
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT.ReadFrom( tree );
      trig_EF_el_EF_e60_etcut.ReadFrom( tree );
    

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void TriggerVecD3PDObject::WriteTo( TTree* tree ) {

      trig_EF_el_EF_2e12Tvh_loose1.WriteTo( tree );
      trig_EF_el_EF_2e5_tight1_Jpsi.WriteTo( tree );
      trig_EF_el_EF_2e7T_loose1_mu6.WriteTo( tree );
      trig_EF_el_EF_2e7T_medium1_mu6.WriteTo( tree );
      trig_EF_el_EF_e11_etcut.WriteTo( tree );
      trig_EF_el_EF_e12Tvh_loose1.WriteTo( tree );
      trig_EF_el_EF_e12Tvh_medium1.WriteTo( tree );
      trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium.WriteTo( tree );
      trig_EF_el_EF_e12Tvh_medium1_mu8.WriteTo( tree );
      trig_EF_el_EF_e13_etcutTrk_xs60.WriteTo( tree );
      trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20.WriteTo( tree );
      trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi.WriteTo( tree );
      trig_EF_el_EF_e15vh_medium1.WriteTo( tree );
      trig_EF_el_EF_e18_loose1.WriteTo( tree );
      trig_EF_el_EF_e18_loose1_g25_medium.WriteTo( tree );
      trig_EF_el_EF_e18_medium1.WriteTo( tree );
      trig_EF_el_EF_e18_medium1_g25_loose.WriteTo( tree );
      trig_EF_el_EF_e18vh_medium1.WriteTo( tree );
      trig_EF_el_EF_e18vh_medium1_2e7T_medium1.WriteTo( tree );
      trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20.WriteTo( tree );
      trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20.WriteTo( tree );
      trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi.WriteTo( tree );
      trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi.WriteTo( tree );
      trig_EF_el_EF_e22vh_loose.WriteTo( tree );
      trig_EF_el_EF_e22vh_loose0.WriteTo( tree );
      trig_EF_el_EF_e22vh_loose1.WriteTo( tree );
      trig_EF_el_EF_e22vh_medium1.WriteTo( tree );
      trig_EF_el_EF_e22vh_medium1_IDTrkNoCut.WriteTo( tree );
      trig_EF_el_EF_e22vhi_medium1.WriteTo( tree );
      trig_EF_el_EF_e24vh_loose.WriteTo( tree );
      trig_EF_el_EF_e24vh_loose0.WriteTo( tree );
      trig_EF_el_EF_e24vh_loose1.WriteTo( tree );
      trig_EF_el_EF_e24vh_medium1.WriteTo( tree );
      trig_EF_el_EF_e24vh_medium1_EFxe30.WriteTo( tree );
      trig_EF_el_EF_e24vh_medium1_EFxe30_tcem.WriteTo( tree );
      trig_EF_el_EF_e24vh_medium1_EFxe35_tcem.WriteTo( tree );
      trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw.WriteTo( tree );
      trig_EF_el_EF_e24vh_medium1_EFxe40.WriteTo( tree );
      trig_EF_el_EF_e24vh_medium1_IDTrkNoCut.WriteTo( tree );
      trig_EF_el_EF_e24vh_medium1_IdScan.WriteTo( tree );
      trig_EF_el_EF_e24vh_medium1_L2StarB.WriteTo( tree );
      trig_EF_el_EF_e24vh_medium1_L2StarC.WriteTo( tree );
      trig_EF_el_EF_e24vh_medium1_SiTrk.WriteTo( tree );
      trig_EF_el_EF_e24vh_medium1_TRT.WriteTo( tree );
      trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad.WriteTo( tree );
      trig_EF_el_EF_e24vh_medium1_e7_medium1.WriteTo( tree );
      trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee.WriteTo( tree );
      trig_EF_el_EF_e24vhi_loose1_mu8.WriteTo( tree );
      trig_EF_el_EF_e24vhi_medium1.WriteTo( tree );
      trig_EF_el_EF_e45_medium1.WriteTo( tree );
      trig_EF_el_EF_e5_tight1.WriteTo( tree );
      trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi.WriteTo( tree );
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi.WriteTo( tree );
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB.WriteTo( tree );
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC.WriteTo( tree );
      trig_EF_el_EF_e5_tight1_e5_NoCut.WriteTo( tree );
      trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi.WriteTo( tree );
      trig_EF_el_EF_e60_medium1.WriteTo( tree );
      trig_EF_el_EF_e7T_loose1.WriteTo( tree );
      trig_EF_el_EF_e7T_loose1_2mu6.WriteTo( tree );
      trig_EF_el_EF_e7T_medium1.WriteTo( tree );
      trig_EF_el_EF_e7T_medium1_2mu6.WriteTo( tree );
      trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi.WriteTo( tree );
      trig_EF_el_EF_eb_physics.WriteTo( tree );
      trig_EF_el_EF_eb_physics_empty.WriteTo( tree );
      trig_EF_el_EF_eb_physics_firstempty.WriteTo( tree );
      trig_EF_el_EF_eb_physics_noL1PS.WriteTo( tree );
      trig_EF_el_EF_eb_physics_unpaired_iso.WriteTo( tree );
      trig_EF_el_EF_eb_physics_unpaired_noniso.WriteTo( tree );
      trig_EF_el_EF_eb_random.WriteTo( tree );
      trig_EF_el_EF_eb_random_empty.WriteTo( tree );
      trig_EF_el_EF_eb_random_firstempty.WriteTo( tree );
      trig_EF_el_EF_eb_random_unpaired_iso.WriteTo( tree );
      trig_EF_emcl_pt.WriteTo( tree );
      trig_EF_emcl_eta.WriteTo( tree );
      trig_EF_emcl_phi.WriteTo( tree );
      trig_EF_emcl_E_em.WriteTo( tree );
      trig_EF_emcl_E_had.WriteTo( tree );
      trig_EF_emcl_slw_pt.WriteTo( tree );
      trig_EF_emcl_slw_eta.WriteTo( tree );
      trig_EF_emcl_slw_phi.WriteTo( tree );
      trig_EF_emcl_slw_E_em.WriteTo( tree );
      trig_EF_emcl_slw_E_had.WriteTo( tree );
      trig_EF_el_E.WriteTo( tree );
      trig_EF_el_Et.WriteTo( tree );
      trig_EF_el_pt.WriteTo( tree );
      trig_EF_el_m.WriteTo( tree );
      trig_EF_el_eta.WriteTo( tree );
      trig_EF_el_phi.WriteTo( tree );
      trig_EF_el_px.WriteTo( tree );
      trig_EF_el_py.WriteTo( tree );
      trig_EF_el_pz.WriteTo( tree );
      trig_EF_el_charge.WriteTo( tree );
      trig_EF_el_author.WriteTo( tree );
      trig_EF_el_isEM.WriteTo( tree );
      trig_EF_el_isEMLoose.WriteTo( tree );
      trig_EF_el_isEMMedium.WriteTo( tree );
      trig_EF_el_isEMTight.WriteTo( tree );
      trig_EF_el_loose.WriteTo( tree );
      trig_EF_el_looseIso.WriteTo( tree );
      trig_EF_el_medium.WriteTo( tree );
      trig_EF_el_mediumIso.WriteTo( tree );
      trig_EF_el_mediumWithoutTrack.WriteTo( tree );
      trig_EF_el_mediumIsoWithoutTrack.WriteTo( tree );
      trig_EF_el_tight.WriteTo( tree );
      trig_EF_el_tightIso.WriteTo( tree );
      trig_EF_el_tightWithoutTrack.WriteTo( tree );
      trig_EF_el_tightIsoWithoutTrack.WriteTo( tree );
      trig_EF_el_loosePP.WriteTo( tree );
      trig_EF_el_loosePPIso.WriteTo( tree );
      trig_EF_el_mediumPP.WriteTo( tree );
      trig_EF_el_mediumPPIso.WriteTo( tree );
      trig_EF_el_tightPP.WriteTo( tree );
      trig_EF_el_tightPPIso.WriteTo( tree );
      trig_EF_el_vertweight.WriteTo( tree );
      trig_EF_el_hastrack.WriteTo( tree );
      trig_EF_trigmuonef_track_CB_pt.WriteTo( tree );
      trig_EF_trigmuonef_track_CB_eta.WriteTo( tree );
      trig_EF_trigmuonef_track_CB_phi.WriteTo( tree );
      trig_EF_trigmuonef_track_CB_hasCB.WriteTo( tree );


    // =============================================================================
    // = Data only
    // =============================================================================
      trig_EF_trigmuonef_EF_2mu10.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu13.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu13_l2muonSA.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu15.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_2e5_tight1.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_Bmumu.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_Bmumux.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_DiMu.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_Jpsimumu.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_Upsimumu.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_xe60.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu6.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu6_Bmumu.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu6_Bmumux.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu6_DiMu.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu6_DiMu_DY20.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu6_DiMu_DY25.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu6_Jpsimumu.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu6_Upsimumu.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu6i_DiMu_DY.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu8_EFxe30.WriteTo( tree );
      trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu10.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu10_Jpsimumu.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu10_MSonly.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu10i_g10_medium.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu11_empty_NoAlg.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu13.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu15.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu18.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu18_2g10_loose.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu18_2g10_medium.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu18_medium.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu18_tight.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu18_tight_e7_medium1.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu18i4_tight.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu20i_tight_g5_medium.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu20it_tight.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24_g20vh_loose.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24_g20vh_medium.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24_j65_a4tchad.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24_medium.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24_tight.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24_tight_EFxe40.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24_tight_L2StarB.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24_tight_L2StarC.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24_tight_MG.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24_tight_MuonEF.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24i_tight.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24i_tight_MG.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24i_tight_MuonEF.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu36_tight.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu40_slow_tight.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu40_tight.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_cosmic.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_DiMu.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4_empty_NoAlg.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu6.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu60_slow_tight1.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu6_MSonly.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu8.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS.WriteTo( tree );
      trig_EF_trigmuonef_track_MuonType.WriteTo( tree );
      trig_EF_trigmuonef_track_MS_pt.WriteTo( tree );
      trig_EF_trigmuonef_track_MS_eta.WriteTo( tree );
      trig_EF_trigmuonef_track_MS_phi.WriteTo( tree );
      trig_EF_trigmuonef_track_MS_hasMS.WriteTo( tree );
      trig_EF_trigmuonef_track_SA_pt.WriteTo( tree );
      trig_EF_trigmuonef_track_SA_eta.WriteTo( tree );
      trig_EF_trigmuonef_track_SA_phi.WriteTo( tree );
      trig_EF_trigmuonef_track_SA_hasSA.WriteTo( tree );
    
    // =============================================================================
    // = MC only
    // =============================================================================
      trig_EF_el_EF_e12Tvh_loose1_mu8.WriteTo( tree );
      trig_EF_el_EF_e12Tvh_medium1_mu10.WriteTo( tree );
      trig_EF_el_EF_e12Tvh_medium1_mu6.WriteTo( tree );
      trig_EF_el_EF_e18_loose1_g35_loose.WriteTo( tree );
      trig_EF_el_EF_e18_loose1_g35_medium.WriteTo( tree );
      trig_EF_el_EF_e18_medium1_g25_medium.WriteTo( tree );
      trig_EF_el_EF_e18_medium1_g35_loose.WriteTo( tree );
      trig_EF_el_EF_e18_medium1_g35_medium.WriteTo( tree );
      trig_EF_el_EF_e22vh_medium1_IdScan.WriteTo( tree );
      trig_EF_el_EF_e22vh_medium1_SiTrk.WriteTo( tree );
      trig_EF_el_EF_e22vh_medium1_TRT.WriteTo( tree );
      trig_EF_el_EF_e45_etcut.WriteTo( tree );
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan.WriteTo( tree );
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk.WriteTo( tree );
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT.WriteTo( tree );
      trig_EF_el_EF_e60_etcut.WriteTo( tree );
    
      return;
   }

   /**
    * This is a convenience function for turning the branches active or
    * inactive conveniently. If the parameter is set to <code>kTRUE</code>
    * then the branches available from the input which match the given
    * pattern are turned active.
    * When it's set to <code>kFALSE</code> then all the variables matching
    * the pattern are turned inactive.
    *
    * @param active Flag behaving as explained above
    * @param pattern Regular expression specifying which branches to modify
    */
   void TriggerVecD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

      ::TPRegexp re( pattern );

      std::map< TString, VarHandleBase* >::const_iterator itr = fHandles.begin();
      std::map< TString, VarHandleBase* >::const_iterator end = fHandles.end();
      for( ; itr != end; ++itr ) {
         if( ! re.Match( itr->first ) ) continue;
         if( active ) {
            if( itr->second->IsAvailable() ) itr->second->SetActive( active );
         } else {
            itr->second->SetActive( active );
         }
      }
      return;
   }

   /**
    * This function can be used to read in all the branches from the input
    * TTree which are set active for writing out. This can simplify writing
    * event selector codes immensely. Remember to set the desired variable
    * active before calling this function.
    */
   void TriggerVecD3PDObject::ReadAllActive() {

      // Check if it makes sense to call this function:
      if( ! fFromInput ) {
         static ::Bool_t wPrinted = kFALSE;
         if( ! wPrinted ) {
            Warning( "ReadAllActive", "Function only meaningful when used on objects" );
            Warning( "ReadAllActive", "which are used to read information from a D3PD" );
            wPrinted = kTRUE;
         }
      }

      if( trig_EF_el_EF_2e12Tvh_loose1.IsActive() ) trig_EF_el_EF_2e12Tvh_loose1();
      if( trig_EF_el_EF_2e5_tight1_Jpsi.IsActive() ) trig_EF_el_EF_2e5_tight1_Jpsi();
      if( trig_EF_el_EF_2e7T_loose1_mu6.IsActive() ) trig_EF_el_EF_2e7T_loose1_mu6();
      if( trig_EF_el_EF_2e7T_medium1_mu6.IsActive() ) trig_EF_el_EF_2e7T_medium1_mu6();
      if( trig_EF_el_EF_e11_etcut.IsActive() ) trig_EF_el_EF_e11_etcut();
      if( trig_EF_el_EF_e12Tvh_loose1.IsActive() ) trig_EF_el_EF_e12Tvh_loose1();
      if( trig_EF_el_EF_e12Tvh_medium1.IsActive() ) trig_EF_el_EF_e12Tvh_medium1();
      if( trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium.IsActive() ) trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium();
      if( trig_EF_el_EF_e12Tvh_medium1_mu8.IsActive() ) trig_EF_el_EF_e12Tvh_medium1_mu8();
      if( trig_EF_el_EF_e13_etcutTrk_xs60.IsActive() ) trig_EF_el_EF_e13_etcutTrk_xs60();
      if( trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20.IsActive() ) trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20();
      if( trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi.IsActive() ) trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi();
      if( trig_EF_el_EF_e15vh_medium1.IsActive() ) trig_EF_el_EF_e15vh_medium1();
      if( trig_EF_el_EF_e18_loose1.IsActive() ) trig_EF_el_EF_e18_loose1();
      if( trig_EF_el_EF_e18_loose1_g25_medium.IsActive() ) trig_EF_el_EF_e18_loose1_g25_medium();
      if( trig_EF_el_EF_e18_medium1.IsActive() ) trig_EF_el_EF_e18_medium1();
      if( trig_EF_el_EF_e18_medium1_g25_loose.IsActive() ) trig_EF_el_EF_e18_medium1_g25_loose();
      if( trig_EF_el_EF_e18vh_medium1.IsActive() ) trig_EF_el_EF_e18vh_medium1();
      if( trig_EF_el_EF_e18vh_medium1_2e7T_medium1.IsActive() ) trig_EF_el_EF_e18vh_medium1_2e7T_medium1();
      if( trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20.IsActive() ) trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20();
      if( trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20.IsActive() ) trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20();
      if( trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi.IsActive() ) trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi();
      if( trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi.IsActive() ) trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi();
      if( trig_EF_el_EF_e22vh_loose.IsActive() ) trig_EF_el_EF_e22vh_loose();
      if( trig_EF_el_EF_e22vh_loose0.IsActive() ) trig_EF_el_EF_e22vh_loose0();
      if( trig_EF_el_EF_e22vh_loose1.IsActive() ) trig_EF_el_EF_e22vh_loose1();
      if( trig_EF_el_EF_e22vh_medium1.IsActive() ) trig_EF_el_EF_e22vh_medium1();
      if( trig_EF_el_EF_e22vh_medium1_IDTrkNoCut.IsActive() ) trig_EF_el_EF_e22vh_medium1_IDTrkNoCut();
      if( trig_EF_el_EF_e22vhi_medium1.IsActive() ) trig_EF_el_EF_e22vhi_medium1();
      if( trig_EF_el_EF_e24vh_loose.IsActive() ) trig_EF_el_EF_e24vh_loose();
      if( trig_EF_el_EF_e24vh_loose0.IsActive() ) trig_EF_el_EF_e24vh_loose0();
      if( trig_EF_el_EF_e24vh_loose1.IsActive() ) trig_EF_el_EF_e24vh_loose1();
      if( trig_EF_el_EF_e24vh_medium1.IsActive() ) trig_EF_el_EF_e24vh_medium1();
      if( trig_EF_el_EF_e24vh_medium1_EFxe30.IsActive() ) trig_EF_el_EF_e24vh_medium1_EFxe30();
      if( trig_EF_el_EF_e24vh_medium1_EFxe30_tcem.IsActive() ) trig_EF_el_EF_e24vh_medium1_EFxe30_tcem();
      if( trig_EF_el_EF_e24vh_medium1_EFxe35_tcem.IsActive() ) trig_EF_el_EF_e24vh_medium1_EFxe35_tcem();
      if( trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw.IsActive() ) trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw();
      if( trig_EF_el_EF_e24vh_medium1_EFxe40.IsActive() ) trig_EF_el_EF_e24vh_medium1_EFxe40();
      if( trig_EF_el_EF_e24vh_medium1_IDTrkNoCut.IsActive() ) trig_EF_el_EF_e24vh_medium1_IDTrkNoCut();
      if( trig_EF_el_EF_e24vh_medium1_IdScan.IsActive() ) trig_EF_el_EF_e24vh_medium1_IdScan();
      if( trig_EF_el_EF_e24vh_medium1_L2StarB.IsActive() ) trig_EF_el_EF_e24vh_medium1_L2StarB();
      if( trig_EF_el_EF_e24vh_medium1_L2StarC.IsActive() ) trig_EF_el_EF_e24vh_medium1_L2StarC();
      if( trig_EF_el_EF_e24vh_medium1_SiTrk.IsActive() ) trig_EF_el_EF_e24vh_medium1_SiTrk();
      if( trig_EF_el_EF_e24vh_medium1_TRT.IsActive() ) trig_EF_el_EF_e24vh_medium1_TRT();
      if( trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad.IsActive() ) trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad();
      if( trig_EF_el_EF_e24vh_medium1_e7_medium1.IsActive() ) trig_EF_el_EF_e24vh_medium1_e7_medium1();
      if( trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee.IsActive() ) trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee();
      if( trig_EF_el_EF_e24vhi_loose1_mu8.IsActive() ) trig_EF_el_EF_e24vhi_loose1_mu8();
      if( trig_EF_el_EF_e24vhi_medium1.IsActive() ) trig_EF_el_EF_e24vhi_medium1();
      if( trig_EF_el_EF_e45_medium1.IsActive() ) trig_EF_el_EF_e45_medium1();
      if( trig_EF_el_EF_e5_tight1.IsActive() ) trig_EF_el_EF_e5_tight1();
      if( trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi.IsActive() ) trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi();
      if( trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi.IsActive() ) trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi();
      if( trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB.IsActive() ) trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB();
      if( trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC.IsActive() ) trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC();
      if( trig_EF_el_EF_e5_tight1_e5_NoCut.IsActive() ) trig_EF_el_EF_e5_tight1_e5_NoCut();
      if( trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi.IsActive() ) trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi();
      if( trig_EF_el_EF_e60_medium1.IsActive() ) trig_EF_el_EF_e60_medium1();
      if( trig_EF_el_EF_e7T_loose1.IsActive() ) trig_EF_el_EF_e7T_loose1();
      if( trig_EF_el_EF_e7T_loose1_2mu6.IsActive() ) trig_EF_el_EF_e7T_loose1_2mu6();
      if( trig_EF_el_EF_e7T_medium1.IsActive() ) trig_EF_el_EF_e7T_medium1();
      if( trig_EF_el_EF_e7T_medium1_2mu6.IsActive() ) trig_EF_el_EF_e7T_medium1_2mu6();
      if( trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi.IsActive() ) trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi();
      if( trig_EF_el_EF_eb_physics.IsActive() ) trig_EF_el_EF_eb_physics();
      if( trig_EF_el_EF_eb_physics_empty.IsActive() ) trig_EF_el_EF_eb_physics_empty();
      if( trig_EF_el_EF_eb_physics_firstempty.IsActive() ) trig_EF_el_EF_eb_physics_firstempty();
      if( trig_EF_el_EF_eb_physics_noL1PS.IsActive() ) trig_EF_el_EF_eb_physics_noL1PS();
      if( trig_EF_el_EF_eb_physics_unpaired_iso.IsActive() ) trig_EF_el_EF_eb_physics_unpaired_iso();
      if( trig_EF_el_EF_eb_physics_unpaired_noniso.IsActive() ) trig_EF_el_EF_eb_physics_unpaired_noniso();
      if( trig_EF_el_EF_eb_random.IsActive() ) trig_EF_el_EF_eb_random();
      if( trig_EF_el_EF_eb_random_empty.IsActive() ) trig_EF_el_EF_eb_random_empty();
      if( trig_EF_el_EF_eb_random_firstempty.IsActive() ) trig_EF_el_EF_eb_random_firstempty();
      if( trig_EF_el_EF_eb_random_unpaired_iso.IsActive() ) trig_EF_el_EF_eb_random_unpaired_iso();
      if( trig_EF_emcl_pt.IsActive() ) trig_EF_emcl_pt();
      if( trig_EF_emcl_eta.IsActive() ) trig_EF_emcl_eta();
      if( trig_EF_emcl_phi.IsActive() ) trig_EF_emcl_phi();
      if( trig_EF_emcl_E_em.IsActive() ) trig_EF_emcl_E_em();
      if( trig_EF_emcl_E_had.IsActive() ) trig_EF_emcl_E_had();
      if( trig_EF_emcl_slw_pt.IsActive() ) trig_EF_emcl_slw_pt();
      if( trig_EF_emcl_slw_eta.IsActive() ) trig_EF_emcl_slw_eta();
      if( trig_EF_emcl_slw_phi.IsActive() ) trig_EF_emcl_slw_phi();
      if( trig_EF_emcl_slw_E_em.IsActive() ) trig_EF_emcl_slw_E_em();
      if( trig_EF_emcl_slw_E_had.IsActive() ) trig_EF_emcl_slw_E_had();
      if( trig_EF_el_E.IsActive() ) trig_EF_el_E();
      if( trig_EF_el_Et.IsActive() ) trig_EF_el_Et();
      if( trig_EF_el_pt.IsActive() ) trig_EF_el_pt();
      if( trig_EF_el_m.IsActive() ) trig_EF_el_m();
      if( trig_EF_el_eta.IsActive() ) trig_EF_el_eta();
      if( trig_EF_el_phi.IsActive() ) trig_EF_el_phi();
      if( trig_EF_el_px.IsActive() ) trig_EF_el_px();
      if( trig_EF_el_py.IsActive() ) trig_EF_el_py();
      if( trig_EF_el_pz.IsActive() ) trig_EF_el_pz();
      if( trig_EF_el_charge.IsActive() ) trig_EF_el_charge();
      if( trig_EF_el_author.IsActive() ) trig_EF_el_author();
      if( trig_EF_el_isEM.IsActive() ) trig_EF_el_isEM();
      if( trig_EF_el_isEMLoose.IsActive() ) trig_EF_el_isEMLoose();
      if( trig_EF_el_isEMMedium.IsActive() ) trig_EF_el_isEMMedium();
      if( trig_EF_el_isEMTight.IsActive() ) trig_EF_el_isEMTight();
      if( trig_EF_el_loose.IsActive() ) trig_EF_el_loose();
      if( trig_EF_el_looseIso.IsActive() ) trig_EF_el_looseIso();
      if( trig_EF_el_medium.IsActive() ) trig_EF_el_medium();
      if( trig_EF_el_mediumIso.IsActive() ) trig_EF_el_mediumIso();
      if( trig_EF_el_mediumWithoutTrack.IsActive() ) trig_EF_el_mediumWithoutTrack();
      if( trig_EF_el_mediumIsoWithoutTrack.IsActive() ) trig_EF_el_mediumIsoWithoutTrack();
      if( trig_EF_el_tight.IsActive() ) trig_EF_el_tight();
      if( trig_EF_el_tightIso.IsActive() ) trig_EF_el_tightIso();
      if( trig_EF_el_tightWithoutTrack.IsActive() ) trig_EF_el_tightWithoutTrack();
      if( trig_EF_el_tightIsoWithoutTrack.IsActive() ) trig_EF_el_tightIsoWithoutTrack();
      if( trig_EF_el_loosePP.IsActive() ) trig_EF_el_loosePP();
      if( trig_EF_el_loosePPIso.IsActive() ) trig_EF_el_loosePPIso();
      if( trig_EF_el_mediumPP.IsActive() ) trig_EF_el_mediumPP();
      if( trig_EF_el_mediumPPIso.IsActive() ) trig_EF_el_mediumPPIso();
      if( trig_EF_el_tightPP.IsActive() ) trig_EF_el_tightPP();
      if( trig_EF_el_tightPPIso.IsActive() ) trig_EF_el_tightPPIso();
      if( trig_EF_el_vertweight.IsActive() ) trig_EF_el_vertweight();
      if( trig_EF_el_hastrack.IsActive() ) trig_EF_el_hastrack();
      if( trig_EF_trigmuonef_track_CB_pt.IsActive() ) trig_EF_trigmuonef_track_CB_pt();
      if( trig_EF_trigmuonef_track_CB_eta.IsActive() ) trig_EF_trigmuonef_track_CB_eta();
      if( trig_EF_trigmuonef_track_CB_phi.IsActive() ) trig_EF_trigmuonef_track_CB_phi();
      if( trig_EF_trigmuonef_track_CB_hasCB.IsActive() ) trig_EF_trigmuonef_track_CB_hasCB();


    // =============================================================================
    // = Data only
    // =============================================================================
      if( trig_EF_trigmuonef_EF_2mu10.IsActive() ) trig_EF_trigmuonef_EF_2mu10();
      if( trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose.IsActive() ) trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose();
      if( trig_EF_trigmuonef_EF_2mu13.IsActive() ) trig_EF_trigmuonef_EF_2mu13();
      if( trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut.IsActive() ) trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut();
      if( trig_EF_trigmuonef_EF_2mu13_l2muonSA.IsActive() ) trig_EF_trigmuonef_EF_2mu13_l2muonSA();
      if( trig_EF_trigmuonef_EF_2mu15.IsActive() ) trig_EF_trigmuonef_EF_2mu15();
      if( trig_EF_trigmuonef_EF_2mu4T.IsActive() ) trig_EF_trigmuonef_EF_2mu4T();
      if( trig_EF_trigmuonef_EF_2mu4T_2e5_tight1.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_2e5_tight1();
      if( trig_EF_trigmuonef_EF_2mu4T_Bmumu.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_Bmumu();
      if( trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel();
      if( trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly();
      if( trig_EF_trigmuonef_EF_2mu4T_Bmumux.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_Bmumux();
      if( trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel();
      if( trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly();
      if( trig_EF_trigmuonef_EF_2mu4T_DiMu.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_DiMu();
      if( trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel();
      if( trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly();
      if( trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB();
      if( trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC();
      if( trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1();
      if( trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA();
      if( trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS();
      if( trig_EF_trigmuonef_EF_2mu4T_Jpsimumu.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_Jpsimumu();
      if( trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel();
      if( trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly();
      if( trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut();
      if( trig_EF_trigmuonef_EF_2mu4T_Upsimumu.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_Upsimumu();
      if( trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel();
      if( trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly();
      if( trig_EF_trigmuonef_EF_2mu4T_xe60.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_xe60();
      if( trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw.IsActive() ) trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw();
      if( trig_EF_trigmuonef_EF_2mu6.IsActive() ) trig_EF_trigmuonef_EF_2mu6();
      if( trig_EF_trigmuonef_EF_2mu6_Bmumu.IsActive() ) trig_EF_trigmuonef_EF_2mu6_Bmumu();
      if( trig_EF_trigmuonef_EF_2mu6_Bmumux.IsActive() ) trig_EF_trigmuonef_EF_2mu6_Bmumux();
      if( trig_EF_trigmuonef_EF_2mu6_DiMu.IsActive() ) trig_EF_trigmuonef_EF_2mu6_DiMu();
      if( trig_EF_trigmuonef_EF_2mu6_DiMu_DY20.IsActive() ) trig_EF_trigmuonef_EF_2mu6_DiMu_DY20();
      if( trig_EF_trigmuonef_EF_2mu6_DiMu_DY25.IsActive() ) trig_EF_trigmuonef_EF_2mu6_DiMu_DY25();
      if( trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS.IsActive() ) trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS();
      if( trig_EF_trigmuonef_EF_2mu6_Jpsimumu.IsActive() ) trig_EF_trigmuonef_EF_2mu6_Jpsimumu();
      if( trig_EF_trigmuonef_EF_2mu6_Upsimumu.IsActive() ) trig_EF_trigmuonef_EF_2mu6_Upsimumu();
      if( trig_EF_trigmuonef_EF_2mu6i_DiMu_DY.IsActive() ) trig_EF_trigmuonef_EF_2mu6i_DiMu_DY();
      if( trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad.IsActive() ) trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad();
      if( trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS.IsActive() ) trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS();
      if( trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad.IsActive() ) trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad();
      if( trig_EF_trigmuonef_EF_2mu8_EFxe30.IsActive() ) trig_EF_trigmuonef_EF_2mu8_EFxe30();
      if( trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw.IsActive() ) trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw();
      if( trig_EF_trigmuonef_EF_mu10.IsActive() ) trig_EF_trigmuonef_EF_mu10();
      if( trig_EF_trigmuonef_EF_mu10_Jpsimumu.IsActive() ) trig_EF_trigmuonef_EF_mu10_Jpsimumu();
      if( trig_EF_trigmuonef_EF_mu10_MSonly.IsActive() ) trig_EF_trigmuonef_EF_mu10_MSonly();
      if( trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS.IsActive() ) trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS();
      if( trig_EF_trigmuonef_EF_mu10i_g10_medium.IsActive() ) trig_EF_trigmuonef_EF_mu10i_g10_medium();
      if( trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass.IsActive() ) trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass();
      if( trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium.IsActive() ) trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium();
      if( trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass.IsActive() ) trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass();
      if( trig_EF_trigmuonef_EF_mu11_empty_NoAlg.IsActive() ) trig_EF_trigmuonef_EF_mu11_empty_NoAlg();
      if( trig_EF_trigmuonef_EF_mu13.IsActive() ) trig_EF_trigmuonef_EF_mu13();
      if( trig_EF_trigmuonef_EF_mu15.IsActive() ) trig_EF_trigmuonef_EF_mu15();
      if( trig_EF_trigmuonef_EF_mu18.IsActive() ) trig_EF_trigmuonef_EF_mu18();
      if( trig_EF_trigmuonef_EF_mu18_2g10_loose.IsActive() ) trig_EF_trigmuonef_EF_mu18_2g10_loose();
      if( trig_EF_trigmuonef_EF_mu18_2g10_medium.IsActive() ) trig_EF_trigmuonef_EF_mu18_2g10_medium();
      if( trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight.IsActive() ) trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight();
      if( trig_EF_trigmuonef_EF_mu18_medium.IsActive() ) trig_EF_trigmuonef_EF_mu18_medium();
      if( trig_EF_trigmuonef_EF_mu18_tight.IsActive() ) trig_EF_trigmuonef_EF_mu18_tight();
      if( trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS.IsActive() ) trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS();
      if( trig_EF_trigmuonef_EF_mu18_tight_e7_medium1.IsActive() ) trig_EF_trigmuonef_EF_mu18_tight_e7_medium1();
      if( trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS.IsActive() ) trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS();
      if( trig_EF_trigmuonef_EF_mu18i4_tight.IsActive() ) trig_EF_trigmuonef_EF_mu18i4_tight();
      if( trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass.IsActive() ) trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass();
      if( trig_EF_trigmuonef_EF_mu20i_tight_g5_medium.IsActive() ) trig_EF_trigmuonef_EF_mu20i_tight_g5_medium();
      if( trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass.IsActive() ) trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass();
      if( trig_EF_trigmuonef_EF_mu20it_tight.IsActive() ) trig_EF_trigmuonef_EF_mu20it_tight();
      if( trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight.IsActive() ) trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight();
      if( trig_EF_trigmuonef_EF_mu24.IsActive() ) trig_EF_trigmuonef_EF_mu24();
      if( trig_EF_trigmuonef_EF_mu24_g20vh_loose.IsActive() ) trig_EF_trigmuonef_EF_mu24_g20vh_loose();
      if( trig_EF_trigmuonef_EF_mu24_g20vh_medium.IsActive() ) trig_EF_trigmuonef_EF_mu24_g20vh_medium();
      if( trig_EF_trigmuonef_EF_mu24_j65_a4tchad.IsActive() ) trig_EF_trigmuonef_EF_mu24_j65_a4tchad();
      if( trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40.IsActive() ) trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40();
      if( trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw.IsActive() ) trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw();
      if( trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw.IsActive() ) trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw();
      if( trig_EF_trigmuonef_EF_mu24_medium.IsActive() ) trig_EF_trigmuonef_EF_mu24_medium();
      if( trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight.IsActive() ) trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight();
      if( trig_EF_trigmuonef_EF_mu24_tight.IsActive() ) trig_EF_trigmuonef_EF_mu24_tight();
      if( trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad.IsActive() ) trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad();
      if( trig_EF_trigmuonef_EF_mu24_tight_EFxe40.IsActive() ) trig_EF_trigmuonef_EF_mu24_tight_EFxe40();
      if( trig_EF_trigmuonef_EF_mu24_tight_L2StarB.IsActive() ) trig_EF_trigmuonef_EF_mu24_tight_L2StarB();
      if( trig_EF_trigmuonef_EF_mu24_tight_L2StarC.IsActive() ) trig_EF_trigmuonef_EF_mu24_tight_L2StarC();
      if( trig_EF_trigmuonef_EF_mu24_tight_MG.IsActive() ) trig_EF_trigmuonef_EF_mu24_tight_MG();
      if( trig_EF_trigmuonef_EF_mu24_tight_MuonEF.IsActive() ) trig_EF_trigmuonef_EF_mu24_tight_MuonEF();
      if( trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad.IsActive() ) trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad();
      if( trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS.IsActive() ) trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS();
      if( trig_EF_trigmuonef_EF_mu24i_tight.IsActive() ) trig_EF_trigmuonef_EF_mu24i_tight();
      if( trig_EF_trigmuonef_EF_mu24i_tight_MG.IsActive() ) trig_EF_trigmuonef_EF_mu24i_tight_MG();
      if( trig_EF_trigmuonef_EF_mu24i_tight_MuonEF.IsActive() ) trig_EF_trigmuonef_EF_mu24i_tight_MuonEF();
      if( trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA.IsActive() ) trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA();
      if( trig_EF_trigmuonef_EF_mu36_tight.IsActive() ) trig_EF_trigmuonef_EF_mu36_tight();
      if( trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight.IsActive() ) trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight();
      if( trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF.IsActive() ) trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF();
      if( trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight.IsActive() ) trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight();
      if( trig_EF_trigmuonef_EF_mu40_slow_tight.IsActive() ) trig_EF_trigmuonef_EF_mu40_slow_tight();
      if( trig_EF_trigmuonef_EF_mu40_tight.IsActive() ) trig_EF_trigmuonef_EF_mu40_tight();
      if( trig_EF_trigmuonef_EF_mu4T.IsActive() ) trig_EF_trigmuonef_EF_mu4T();
      if( trig_EF_trigmuonef_EF_mu4T_cosmic.IsActive() ) trig_EF_trigmuonef_EF_mu4T_cosmic();
      if( trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ();
      if( trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ();
      if( trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ();
      if( trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ();
      if( trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ();
      if( trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ();
      if( trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ();
      if( trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose();
      if( trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose();
      if( trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched();
      if( trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched.IsActive() ) trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched();
      if( trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium.IsActive() ) trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium();
      if( trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass.IsActive() ) trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass();
      if( trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu.IsActive() ) trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu();
      if( trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel.IsActive() ) trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel();
      if( trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux.IsActive() ) trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux();
      if( trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel.IsActive() ) trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel();
      if( trig_EF_trigmuonef_EF_mu4Tmu6_DiMu.IsActive() ) trig_EF_trigmuonef_EF_mu4Tmu6_DiMu();
      if( trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel.IsActive() ) trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel();
      if( trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS.IsActive() ) trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS();
      if( trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu.IsActive() ) trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu();
      if( trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel.IsActive() ) trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel();
      if( trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut.IsActive() ) trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut();
      if( trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu.IsActive() ) trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu();
      if( trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel.IsActive() ) trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel();
      if( trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic.IsActive() ) trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic();
      if( trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic.IsActive() ) trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic();
      if( trig_EF_trigmuonef_EF_mu4_empty_NoAlg.IsActive() ) trig_EF_trigmuonef_EF_mu4_empty_NoAlg();
      if( trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg.IsActive() ) trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg();
      if( trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg.IsActive() ) trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg();
      if( trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight.IsActive() ) trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight();
      if( trig_EF_trigmuonef_EF_mu6.IsActive() ) trig_EF_trigmuonef_EF_mu6();
      if( trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1.IsActive() ) trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1();
      if( trig_EF_trigmuonef_EF_mu60_slow_tight1.IsActive() ) trig_EF_trigmuonef_EF_mu60_slow_tight1();
      if( trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight.IsActive() ) trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight();
      if( trig_EF_trigmuonef_EF_mu6_MSonly.IsActive() ) trig_EF_trigmuonef_EF_mu6_MSonly();
      if( trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose.IsActive() ) trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose();
      if( trig_EF_trigmuonef_EF_mu8.IsActive() ) trig_EF_trigmuonef_EF_mu8();
      if( trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS.IsActive() ) trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS();
      if( trig_EF_trigmuonef_track_MuonType.IsActive() ) trig_EF_trigmuonef_track_MuonType();
      if( trig_EF_trigmuonef_track_MS_pt.IsActive() ) trig_EF_trigmuonef_track_MS_pt();
      if( trig_EF_trigmuonef_track_MS_eta.IsActive() ) trig_EF_trigmuonef_track_MS_eta();
      if( trig_EF_trigmuonef_track_MS_phi.IsActive() ) trig_EF_trigmuonef_track_MS_phi();
      if( trig_EF_trigmuonef_track_MS_hasMS.IsActive() ) trig_EF_trigmuonef_track_MS_hasMS();
      if( trig_EF_trigmuonef_track_SA_pt.IsActive() ) trig_EF_trigmuonef_track_SA_pt();
      if( trig_EF_trigmuonef_track_SA_eta.IsActive() ) trig_EF_trigmuonef_track_SA_eta();
      if( trig_EF_trigmuonef_track_SA_phi.IsActive() ) trig_EF_trigmuonef_track_SA_phi();
      if( trig_EF_trigmuonef_track_SA_hasSA.IsActive() ) trig_EF_trigmuonef_track_SA_hasSA();
    
    // =============================================================================
    // = MC only
    // =============================================================================
      if( trig_EF_el_EF_e12Tvh_loose1_mu8.IsActive() ) trig_EF_el_EF_e12Tvh_loose1_mu8();
      if( trig_EF_el_EF_e12Tvh_medium1_mu10.IsActive() ) trig_EF_el_EF_e12Tvh_medium1_mu10();
      if( trig_EF_el_EF_e12Tvh_medium1_mu6.IsActive() ) trig_EF_el_EF_e12Tvh_medium1_mu6();
      if( trig_EF_el_EF_e18_loose1_g35_loose.IsActive() ) trig_EF_el_EF_e18_loose1_g35_loose();
      if( trig_EF_el_EF_e18_loose1_g35_medium.IsActive() ) trig_EF_el_EF_e18_loose1_g35_medium();
      if( trig_EF_el_EF_e18_medium1_g25_medium.IsActive() ) trig_EF_el_EF_e18_medium1_g25_medium();
      if( trig_EF_el_EF_e18_medium1_g35_loose.IsActive() ) trig_EF_el_EF_e18_medium1_g35_loose();
      if( trig_EF_el_EF_e18_medium1_g35_medium.IsActive() ) trig_EF_el_EF_e18_medium1_g35_medium();
      if( trig_EF_el_EF_e22vh_medium1_IdScan.IsActive() ) trig_EF_el_EF_e22vh_medium1_IdScan();
      if( trig_EF_el_EF_e22vh_medium1_SiTrk.IsActive() ) trig_EF_el_EF_e22vh_medium1_SiTrk();
      if( trig_EF_el_EF_e22vh_medium1_TRT.IsActive() ) trig_EF_el_EF_e22vh_medium1_TRT();
      if( trig_EF_el_EF_e45_etcut.IsActive() ) trig_EF_el_EF_e45_etcut();
      if( trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan.IsActive() ) trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan();
      if( trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk.IsActive() ) trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk();
      if( trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT.IsActive() ) trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT();
      if( trig_EF_el_EF_e60_etcut.IsActive() ) trig_EF_el_EF_e60_etcut();
    
      return;
   }

   /**
    * This function makes it easier to clear out the object completely.
    * It cleares all the vector variables, and sets the element number
    * variable to 0. Very useful when performing object selection.
    * The option argument is not used at the moment for anything.
    * It's only there because the <code>Clear</code> function defined in
    * TObject has this parameter as well.
    *
    * @param option Ignored at the moment
    */
   void TriggerVecD3PDObject::Clear( Option_t* ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Clear", "Objects used for reading a D3PD can't be cleared!" );
         return;
      }

      trig_EF_el_EF_2e12Tvh_loose1()->clear();
      trig_EF_el_EF_2e5_tight1_Jpsi()->clear();
      trig_EF_el_EF_2e7T_loose1_mu6()->clear();
      trig_EF_el_EF_2e7T_medium1_mu6()->clear();
      trig_EF_el_EF_e11_etcut()->clear();
      trig_EF_el_EF_e12Tvh_loose1()->clear();
      trig_EF_el_EF_e12Tvh_medium1()->clear();
      trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium()->clear();
      trig_EF_el_EF_e12Tvh_medium1_mu8()->clear();
      trig_EF_el_EF_e13_etcutTrk_xs60()->clear();
      trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20()->clear();
      trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi()->clear();
      trig_EF_el_EF_e15vh_medium1()->clear();
      trig_EF_el_EF_e18_loose1()->clear();
      trig_EF_el_EF_e18_loose1_g25_medium()->clear();
      trig_EF_el_EF_e18_medium1()->clear();
      trig_EF_el_EF_e18_medium1_g25_loose()->clear();
      trig_EF_el_EF_e18vh_medium1()->clear();
      trig_EF_el_EF_e18vh_medium1_2e7T_medium1()->clear();
      trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20()->clear();
      trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20()->clear();
      trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi()->clear();
      trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi()->clear();
      trig_EF_el_EF_e22vh_loose()->clear();
      trig_EF_el_EF_e22vh_loose0()->clear();
      trig_EF_el_EF_e22vh_loose1()->clear();
      trig_EF_el_EF_e22vh_medium1()->clear();
      trig_EF_el_EF_e22vh_medium1_IDTrkNoCut()->clear();
      trig_EF_el_EF_e22vhi_medium1()->clear();
      trig_EF_el_EF_e24vh_loose()->clear();
      trig_EF_el_EF_e24vh_loose0()->clear();
      trig_EF_el_EF_e24vh_loose1()->clear();
      trig_EF_el_EF_e24vh_medium1()->clear();
      trig_EF_el_EF_e24vh_medium1_EFxe30()->clear();
      trig_EF_el_EF_e24vh_medium1_EFxe30_tcem()->clear();
      trig_EF_el_EF_e24vh_medium1_EFxe35_tcem()->clear();
      trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw()->clear();
      trig_EF_el_EF_e24vh_medium1_EFxe40()->clear();
      trig_EF_el_EF_e24vh_medium1_IDTrkNoCut()->clear();
      trig_EF_el_EF_e24vh_medium1_IdScan()->clear();
      trig_EF_el_EF_e24vh_medium1_L2StarB()->clear();
      trig_EF_el_EF_e24vh_medium1_L2StarC()->clear();
      trig_EF_el_EF_e24vh_medium1_SiTrk()->clear();
      trig_EF_el_EF_e24vh_medium1_TRT()->clear();
      trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad()->clear();
      trig_EF_el_EF_e24vh_medium1_e7_medium1()->clear();
      trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee()->clear();
      trig_EF_el_EF_e24vhi_loose1_mu8()->clear();
      trig_EF_el_EF_e24vhi_medium1()->clear();
      trig_EF_el_EF_e45_medium1()->clear();
      trig_EF_el_EF_e5_tight1()->clear();
      trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi()->clear();
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi()->clear();
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB()->clear();
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC()->clear();
      trig_EF_el_EF_e5_tight1_e5_NoCut()->clear();
      trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi()->clear();
      trig_EF_el_EF_e60_medium1()->clear();
      trig_EF_el_EF_e7T_loose1()->clear();
      trig_EF_el_EF_e7T_loose1_2mu6()->clear();
      trig_EF_el_EF_e7T_medium1()->clear();
      trig_EF_el_EF_e7T_medium1_2mu6()->clear();
      trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi()->clear();
      trig_EF_el_EF_eb_physics()->clear();
      trig_EF_el_EF_eb_physics_empty()->clear();
      trig_EF_el_EF_eb_physics_firstempty()->clear();
      trig_EF_el_EF_eb_physics_noL1PS()->clear();
      trig_EF_el_EF_eb_physics_unpaired_iso()->clear();
      trig_EF_el_EF_eb_physics_unpaired_noniso()->clear();
      trig_EF_el_EF_eb_random()->clear();
      trig_EF_el_EF_eb_random_empty()->clear();
      trig_EF_el_EF_eb_random_firstempty()->clear();
      trig_EF_el_EF_eb_random_unpaired_iso()->clear();
      trig_EF_emcl_pt()->clear();
      trig_EF_emcl_eta()->clear();
      trig_EF_emcl_phi()->clear();
      trig_EF_emcl_E_em()->clear();
      trig_EF_emcl_E_had()->clear();
      trig_EF_emcl_slw_pt()->clear();
      trig_EF_emcl_slw_eta()->clear();
      trig_EF_emcl_slw_phi()->clear();
      trig_EF_emcl_slw_E_em()->clear();
      trig_EF_emcl_slw_E_had()->clear();
      trig_EF_el_E()->clear();
      trig_EF_el_Et()->clear();
      trig_EF_el_pt()->clear();
      trig_EF_el_m()->clear();
      trig_EF_el_eta()->clear();
      trig_EF_el_phi()->clear();
      trig_EF_el_px()->clear();
      trig_EF_el_py()->clear();
      trig_EF_el_pz()->clear();
      trig_EF_el_charge()->clear();
      trig_EF_el_author()->clear();
      trig_EF_el_isEM()->clear();
      trig_EF_el_isEMLoose()->clear();
      trig_EF_el_isEMMedium()->clear();
      trig_EF_el_isEMTight()->clear();
      trig_EF_el_loose()->clear();
      trig_EF_el_looseIso()->clear();
      trig_EF_el_medium()->clear();
      trig_EF_el_mediumIso()->clear();
      trig_EF_el_mediumWithoutTrack()->clear();
      trig_EF_el_mediumIsoWithoutTrack()->clear();
      trig_EF_el_tight()->clear();
      trig_EF_el_tightIso()->clear();
      trig_EF_el_tightWithoutTrack()->clear();
      trig_EF_el_tightIsoWithoutTrack()->clear();
      trig_EF_el_loosePP()->clear();
      trig_EF_el_loosePPIso()->clear();
      trig_EF_el_mediumPP()->clear();
      trig_EF_el_mediumPPIso()->clear();
      trig_EF_el_tightPP()->clear();
      trig_EF_el_tightPPIso()->clear();
      trig_EF_el_vertweight()->clear();
      trig_EF_el_hastrack()->clear();
      trig_EF_trigmuonef_track_CB_pt()->clear();
      trig_EF_trigmuonef_track_CB_eta()->clear();
      trig_EF_trigmuonef_track_CB_phi()->clear();
      trig_EF_trigmuonef_track_CB_hasCB()->clear();

    // =============================================================================
    // = Data only
    // =============================================================================
      trig_EF_trigmuonef_EF_2mu10()->clear();
      trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose()->clear();
      trig_EF_trigmuonef_EF_2mu13()->clear();
      trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut()->clear();
      trig_EF_trigmuonef_EF_2mu13_l2muonSA()->clear();
      trig_EF_trigmuonef_EF_2mu15()->clear();
      trig_EF_trigmuonef_EF_2mu4T()->clear();
      trig_EF_trigmuonef_EF_2mu4T_2e5_tight1()->clear();
      trig_EF_trigmuonef_EF_2mu4T_Bmumu()->clear();
      trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel()->clear();
      trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly()->clear();
      trig_EF_trigmuonef_EF_2mu4T_Bmumux()->clear();
      trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel()->clear();
      trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly()->clear();
      trig_EF_trigmuonef_EF_2mu4T_DiMu()->clear();
      trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel()->clear();
      trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly()->clear();
      trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB()->clear();
      trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC()->clear();
      trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1()->clear();
      trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA()->clear();
      trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS()->clear();
      trig_EF_trigmuonef_EF_2mu4T_Jpsimumu()->clear();
      trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel()->clear();
      trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly()->clear();
      trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut()->clear();
      trig_EF_trigmuonef_EF_2mu4T_Upsimumu()->clear();
      trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel()->clear();
      trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly()->clear();
      trig_EF_trigmuonef_EF_2mu4T_xe60()->clear();
      trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw()->clear();
      trig_EF_trigmuonef_EF_2mu6()->clear();
      trig_EF_trigmuonef_EF_2mu6_Bmumu()->clear();
      trig_EF_trigmuonef_EF_2mu6_Bmumux()->clear();
      trig_EF_trigmuonef_EF_2mu6_DiMu()->clear();
      trig_EF_trigmuonef_EF_2mu6_DiMu_DY20()->clear();
      trig_EF_trigmuonef_EF_2mu6_DiMu_DY25()->clear();
      trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS()->clear();
      trig_EF_trigmuonef_EF_2mu6_Jpsimumu()->clear();
      trig_EF_trigmuonef_EF_2mu6_Upsimumu()->clear();
      trig_EF_trigmuonef_EF_2mu6i_DiMu_DY()->clear();
      trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad()->clear();
      trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS()->clear();
      trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad()->clear();
      trig_EF_trigmuonef_EF_2mu8_EFxe30()->clear();
      trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw()->clear();
      trig_EF_trigmuonef_EF_mu10()->clear();
      trig_EF_trigmuonef_EF_mu10_Jpsimumu()->clear();
      trig_EF_trigmuonef_EF_mu10_MSonly()->clear();
      trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS()->clear();
      trig_EF_trigmuonef_EF_mu10i_g10_medium()->clear();
      trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass()->clear();
      trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium()->clear();
      trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass()->clear();
      trig_EF_trigmuonef_EF_mu11_empty_NoAlg()->clear();
      trig_EF_trigmuonef_EF_mu13()->clear();
      trig_EF_trigmuonef_EF_mu15()->clear();
      trig_EF_trigmuonef_EF_mu18()->clear();
      trig_EF_trigmuonef_EF_mu18_2g10_loose()->clear();
      trig_EF_trigmuonef_EF_mu18_2g10_medium()->clear();
      trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight()->clear();
      trig_EF_trigmuonef_EF_mu18_medium()->clear();
      trig_EF_trigmuonef_EF_mu18_tight()->clear();
      trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS()->clear();
      trig_EF_trigmuonef_EF_mu18_tight_e7_medium1()->clear();
      trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS()->clear();
      trig_EF_trigmuonef_EF_mu18i4_tight()->clear();
      trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass()->clear();
      trig_EF_trigmuonef_EF_mu20i_tight_g5_medium()->clear();
      trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass()->clear();
      trig_EF_trigmuonef_EF_mu20it_tight()->clear();
      trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight()->clear();
      trig_EF_trigmuonef_EF_mu24()->clear();
      trig_EF_trigmuonef_EF_mu24_g20vh_loose()->clear();
      trig_EF_trigmuonef_EF_mu24_g20vh_medium()->clear();
      trig_EF_trigmuonef_EF_mu24_j65_a4tchad()->clear();
      trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40()->clear();
      trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw()->clear();
      trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw()->clear();
      trig_EF_trigmuonef_EF_mu24_medium()->clear();
      trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight()->clear();
      trig_EF_trigmuonef_EF_mu24_tight()->clear();
      trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad()->clear();
      trig_EF_trigmuonef_EF_mu24_tight_EFxe40()->clear();
      trig_EF_trigmuonef_EF_mu24_tight_L2StarB()->clear();
      trig_EF_trigmuonef_EF_mu24_tight_L2StarC()->clear();
      trig_EF_trigmuonef_EF_mu24_tight_MG()->clear();
      trig_EF_trigmuonef_EF_mu24_tight_MuonEF()->clear();
      trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad()->clear();
      trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS()->clear();
      trig_EF_trigmuonef_EF_mu24i_tight()->clear();
      trig_EF_trigmuonef_EF_mu24i_tight_MG()->clear();
      trig_EF_trigmuonef_EF_mu24i_tight_MuonEF()->clear();
      trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA()->clear();
      trig_EF_trigmuonef_EF_mu36_tight()->clear();
      trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight()->clear();
      trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF()->clear();
      trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight()->clear();
      trig_EF_trigmuonef_EF_mu40_slow_tight()->clear();
      trig_EF_trigmuonef_EF_mu40_tight()->clear();
      trig_EF_trigmuonef_EF_mu4T()->clear();
      trig_EF_trigmuonef_EF_mu4T_cosmic()->clear();
      trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ()->clear();
      trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ()->clear();
      trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ()->clear();
      trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ()->clear();
      trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ()->clear();
      trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ()->clear();
      trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ()->clear();
      trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose()->clear();
      trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose()->clear();
      trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched()->clear();
      trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched()->clear();
      trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium()->clear();
      trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass()->clear();
      trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu()->clear();
      trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel()->clear();
      trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux()->clear();
      trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel()->clear();
      trig_EF_trigmuonef_EF_mu4Tmu6_DiMu()->clear();
      trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel()->clear();
      trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS()->clear();
      trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu()->clear();
      trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel()->clear();
      trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut()->clear();
      trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu()->clear();
      trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel()->clear();
      trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic()->clear();
      trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic()->clear();
      trig_EF_trigmuonef_EF_mu4_empty_NoAlg()->clear();
      trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg()->clear();
      trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg()->clear();
      trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight()->clear();
      trig_EF_trigmuonef_EF_mu6()->clear();
      trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1()->clear();
      trig_EF_trigmuonef_EF_mu60_slow_tight1()->clear();
      trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight()->clear();
      trig_EF_trigmuonef_EF_mu6_MSonly()->clear();
      trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose()->clear();
      trig_EF_trigmuonef_EF_mu8()->clear();
      trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS()->clear();
      trig_EF_trigmuonef_track_MuonType()->clear();
      trig_EF_trigmuonef_track_MS_pt()->clear();
      trig_EF_trigmuonef_track_MS_eta()->clear();
      trig_EF_trigmuonef_track_MS_phi()->clear();
      trig_EF_trigmuonef_track_MS_hasMS()->clear();
      trig_EF_trigmuonef_track_SA_pt()->clear();
      trig_EF_trigmuonef_track_SA_eta()->clear();
      trig_EF_trigmuonef_track_SA_phi()->clear();
      trig_EF_trigmuonef_track_SA_hasSA()->clear();
    
    // =============================================================================
    // = MC only
    // =============================================================================
      trig_EF_el_EF_e12Tvh_loose1_mu8()->clear();
      trig_EF_el_EF_e12Tvh_medium1_mu10()->clear();
      trig_EF_el_EF_e12Tvh_medium1_mu6()->clear();
      trig_EF_el_EF_e18_loose1_g35_loose()->clear();
      trig_EF_el_EF_e18_loose1_g35_medium()->clear();
      trig_EF_el_EF_e18_medium1_g25_medium()->clear();
      trig_EF_el_EF_e18_medium1_g35_loose()->clear();
      trig_EF_el_EF_e18_medium1_g35_medium()->clear();
      trig_EF_el_EF_e22vh_medium1_IdScan()->clear();
      trig_EF_el_EF_e22vh_medium1_SiTrk()->clear();
      trig_EF_el_EF_e22vh_medium1_TRT()->clear();
      trig_EF_el_EF_e45_etcut()->clear();
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan()->clear();
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk()->clear();
      trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT()->clear();
      trig_EF_el_EF_e60_etcut()->clear();
    

      return;
   }

   /**
    * This function can be used to easily add an 'element' describing one
    * object to an output collection. Comes in very handy when performing
    * object selection.
    *
    * Note that variables which are not available from the input, will be
    * filled with dummy values.
    *
    * @param el The 'element' that should be added to the collection
    */
   TriggerVecD3PDObject& TriggerVecD3PDObject::Add( const TriggerVecD3PDObjectElement& el ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Add", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      if( el.trig_EF_el_EF_2e12Tvh_loose1.IsAvailable() ) {
         trig_EF_el_EF_2e12Tvh_loose1()->push_back( el.trig_EF_el_EF_2e12Tvh_loose1() );
      } else {
         trig_EF_el_EF_2e12Tvh_loose1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_2e5_tight1_Jpsi.IsAvailable() ) {
         trig_EF_el_EF_2e5_tight1_Jpsi()->push_back( el.trig_EF_el_EF_2e5_tight1_Jpsi() );
      } else {
         trig_EF_el_EF_2e5_tight1_Jpsi()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_2e7T_loose1_mu6.IsAvailable() ) {
         trig_EF_el_EF_2e7T_loose1_mu6()->push_back( el.trig_EF_el_EF_2e7T_loose1_mu6() );
      } else {
         trig_EF_el_EF_2e7T_loose1_mu6()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_2e7T_medium1_mu6.IsAvailable() ) {
         trig_EF_el_EF_2e7T_medium1_mu6()->push_back( el.trig_EF_el_EF_2e7T_medium1_mu6() );
      } else {
         trig_EF_el_EF_2e7T_medium1_mu6()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e11_etcut.IsAvailable() ) {
         trig_EF_el_EF_e11_etcut()->push_back( el.trig_EF_el_EF_e11_etcut() );
      } else {
         trig_EF_el_EF_e11_etcut()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e12Tvh_loose1.IsAvailable() ) {
         trig_EF_el_EF_e12Tvh_loose1()->push_back( el.trig_EF_el_EF_e12Tvh_loose1() );
      } else {
         trig_EF_el_EF_e12Tvh_loose1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e12Tvh_medium1.IsAvailable() ) {
         trig_EF_el_EF_e12Tvh_medium1()->push_back( el.trig_EF_el_EF_e12Tvh_medium1() );
      } else {
         trig_EF_el_EF_e12Tvh_medium1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium.IsAvailable() ) {
         trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium()->push_back( el.trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium() );
      } else {
         trig_EF_el_EF_e12Tvh_medium1_mu6_topo_medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e12Tvh_medium1_mu8.IsAvailable() ) {
         trig_EF_el_EF_e12Tvh_medium1_mu8()->push_back( el.trig_EF_el_EF_e12Tvh_medium1_mu8() );
      } else {
         trig_EF_el_EF_e12Tvh_medium1_mu8()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e13_etcutTrk_xs60.IsAvailable() ) {
         trig_EF_el_EF_e13_etcutTrk_xs60()->push_back( el.trig_EF_el_EF_e13_etcutTrk_xs60() );
      } else {
         trig_EF_el_EF_e13_etcutTrk_xs60()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20.IsAvailable() ) {
         trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20()->push_back( el.trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20() );
      } else {
         trig_EF_el_EF_e13_etcutTrk_xs60_dphi2j15xe20()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi.IsAvailable() ) {
         trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi()->push_back( el.trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi() );
      } else {
         trig_EF_el_EF_e14_tight1_e4_etcut_Jpsi()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e15vh_medium1.IsAvailable() ) {
         trig_EF_el_EF_e15vh_medium1()->push_back( el.trig_EF_el_EF_e15vh_medium1() );
      } else {
         trig_EF_el_EF_e15vh_medium1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e18_loose1.IsAvailable() ) {
         trig_EF_el_EF_e18_loose1()->push_back( el.trig_EF_el_EF_e18_loose1() );
      } else {
         trig_EF_el_EF_e18_loose1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e18_loose1_g25_medium.IsAvailable() ) {
         trig_EF_el_EF_e18_loose1_g25_medium()->push_back( el.trig_EF_el_EF_e18_loose1_g25_medium() );
      } else {
         trig_EF_el_EF_e18_loose1_g25_medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e18_medium1.IsAvailable() ) {
         trig_EF_el_EF_e18_medium1()->push_back( el.trig_EF_el_EF_e18_medium1() );
      } else {
         trig_EF_el_EF_e18_medium1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e18_medium1_g25_loose.IsAvailable() ) {
         trig_EF_el_EF_e18_medium1_g25_loose()->push_back( el.trig_EF_el_EF_e18_medium1_g25_loose() );
      } else {
         trig_EF_el_EF_e18_medium1_g25_loose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e18vh_medium1.IsAvailable() ) {
         trig_EF_el_EF_e18vh_medium1()->push_back( el.trig_EF_el_EF_e18vh_medium1() );
      } else {
         trig_EF_el_EF_e18vh_medium1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e18vh_medium1_2e7T_medium1.IsAvailable() ) {
         trig_EF_el_EF_e18vh_medium1_2e7T_medium1()->push_back( el.trig_EF_el_EF_e18vh_medium1_2e7T_medium1() );
      } else {
         trig_EF_el_EF_e18vh_medium1_2e7T_medium1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20.IsAvailable() ) {
         trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20()->push_back( el.trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20() );
      } else {
         trig_EF_el_EF_e20_etcutTrk_xe30_dphi2j15xe20()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20.IsAvailable() ) {
         trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20()->push_back( el.trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20() );
      } else {
         trig_EF_el_EF_e20_etcutTrk_xs60_dphi2j15xe20()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi.IsAvailable() ) {
         trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi()->push_back( el.trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi() );
      } else {
         trig_EF_el_EF_e20vhT_medium1_g6T_etcut_Upsi()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi.IsAvailable() ) {
         trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi()->push_back( el.trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi() );
      } else {
         trig_EF_el_EF_e20vhT_tight1_g6T_etcut_Upsi()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e22vh_loose.IsAvailable() ) {
         trig_EF_el_EF_e22vh_loose()->push_back( el.trig_EF_el_EF_e22vh_loose() );
      } else {
         trig_EF_el_EF_e22vh_loose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e22vh_loose0.IsAvailable() ) {
         trig_EF_el_EF_e22vh_loose0()->push_back( el.trig_EF_el_EF_e22vh_loose0() );
      } else {
         trig_EF_el_EF_e22vh_loose0()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e22vh_loose1.IsAvailable() ) {
         trig_EF_el_EF_e22vh_loose1()->push_back( el.trig_EF_el_EF_e22vh_loose1() );
      } else {
         trig_EF_el_EF_e22vh_loose1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e22vh_medium1.IsAvailable() ) {
         trig_EF_el_EF_e22vh_medium1()->push_back( el.trig_EF_el_EF_e22vh_medium1() );
      } else {
         trig_EF_el_EF_e22vh_medium1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e22vh_medium1_IDTrkNoCut.IsAvailable() ) {
         trig_EF_el_EF_e22vh_medium1_IDTrkNoCut()->push_back( el.trig_EF_el_EF_e22vh_medium1_IDTrkNoCut() );
      } else {
         trig_EF_el_EF_e22vh_medium1_IDTrkNoCut()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e22vhi_medium1.IsAvailable() ) {
         trig_EF_el_EF_e22vhi_medium1()->push_back( el.trig_EF_el_EF_e22vhi_medium1() );
      } else {
         trig_EF_el_EF_e22vhi_medium1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_loose.IsAvailable() ) {
         trig_EF_el_EF_e24vh_loose()->push_back( el.trig_EF_el_EF_e24vh_loose() );
      } else {
         trig_EF_el_EF_e24vh_loose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_loose0.IsAvailable() ) {
         trig_EF_el_EF_e24vh_loose0()->push_back( el.trig_EF_el_EF_e24vh_loose0() );
      } else {
         trig_EF_el_EF_e24vh_loose0()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_loose1.IsAvailable() ) {
         trig_EF_el_EF_e24vh_loose1()->push_back( el.trig_EF_el_EF_e24vh_loose1() );
      } else {
         trig_EF_el_EF_e24vh_loose1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_medium1.IsAvailable() ) {
         trig_EF_el_EF_e24vh_medium1()->push_back( el.trig_EF_el_EF_e24vh_medium1() );
      } else {
         trig_EF_el_EF_e24vh_medium1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_medium1_EFxe30.IsAvailable() ) {
         trig_EF_el_EF_e24vh_medium1_EFxe30()->push_back( el.trig_EF_el_EF_e24vh_medium1_EFxe30() );
      } else {
         trig_EF_el_EF_e24vh_medium1_EFxe30()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_medium1_EFxe30_tcem.IsAvailable() ) {
         trig_EF_el_EF_e24vh_medium1_EFxe30_tcem()->push_back( el.trig_EF_el_EF_e24vh_medium1_EFxe30_tcem() );
      } else {
         trig_EF_el_EF_e24vh_medium1_EFxe30_tcem()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_medium1_EFxe35_tcem.IsAvailable() ) {
         trig_EF_el_EF_e24vh_medium1_EFxe35_tcem()->push_back( el.trig_EF_el_EF_e24vh_medium1_EFxe35_tcem() );
      } else {
         trig_EF_el_EF_e24vh_medium1_EFxe35_tcem()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw.IsAvailable() ) {
         trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw()->push_back( el.trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw() );
      } else {
         trig_EF_el_EF_e24vh_medium1_EFxe35_tclcw()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_medium1_EFxe40.IsAvailable() ) {
         trig_EF_el_EF_e24vh_medium1_EFxe40()->push_back( el.trig_EF_el_EF_e24vh_medium1_EFxe40() );
      } else {
         trig_EF_el_EF_e24vh_medium1_EFxe40()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_medium1_IDTrkNoCut.IsAvailable() ) {
         trig_EF_el_EF_e24vh_medium1_IDTrkNoCut()->push_back( el.trig_EF_el_EF_e24vh_medium1_IDTrkNoCut() );
      } else {
         trig_EF_el_EF_e24vh_medium1_IDTrkNoCut()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_medium1_IdScan.IsAvailable() ) {
         trig_EF_el_EF_e24vh_medium1_IdScan()->push_back( el.trig_EF_el_EF_e24vh_medium1_IdScan() );
      } else {
         trig_EF_el_EF_e24vh_medium1_IdScan()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_medium1_L2StarB.IsAvailable() ) {
         trig_EF_el_EF_e24vh_medium1_L2StarB()->push_back( el.trig_EF_el_EF_e24vh_medium1_L2StarB() );
      } else {
         trig_EF_el_EF_e24vh_medium1_L2StarB()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_medium1_L2StarC.IsAvailable() ) {
         trig_EF_el_EF_e24vh_medium1_L2StarC()->push_back( el.trig_EF_el_EF_e24vh_medium1_L2StarC() );
      } else {
         trig_EF_el_EF_e24vh_medium1_L2StarC()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_medium1_SiTrk.IsAvailable() ) {
         trig_EF_el_EF_e24vh_medium1_SiTrk()->push_back( el.trig_EF_el_EF_e24vh_medium1_SiTrk() );
      } else {
         trig_EF_el_EF_e24vh_medium1_SiTrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_medium1_TRT.IsAvailable() ) {
         trig_EF_el_EF_e24vh_medium1_TRT()->push_back( el.trig_EF_el_EF_e24vh_medium1_TRT() );
      } else {
         trig_EF_el_EF_e24vh_medium1_TRT()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad.IsAvailable() ) {
         trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad()->push_back( el.trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad() );
      } else {
         trig_EF_el_EF_e24vh_medium1_b35_mediumEF_j35_a4tchad()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_medium1_e7_medium1.IsAvailable() ) {
         trig_EF_el_EF_e24vh_medium1_e7_medium1()->push_back( el.trig_EF_el_EF_e24vh_medium1_e7_medium1() );
      } else {
         trig_EF_el_EF_e24vh_medium1_e7_medium1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee.IsAvailable() ) {
         trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee()->push_back( el.trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee() );
      } else {
         trig_EF_el_EF_e24vh_tight1_e15_NoCut_Zee()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vhi_loose1_mu8.IsAvailable() ) {
         trig_EF_el_EF_e24vhi_loose1_mu8()->push_back( el.trig_EF_el_EF_e24vhi_loose1_mu8() );
      } else {
         trig_EF_el_EF_e24vhi_loose1_mu8()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vhi_medium1.IsAvailable() ) {
         trig_EF_el_EF_e24vhi_medium1()->push_back( el.trig_EF_el_EF_e24vhi_medium1() );
      } else {
         trig_EF_el_EF_e24vhi_medium1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e45_medium1.IsAvailable() ) {
         trig_EF_el_EF_e45_medium1()->push_back( el.trig_EF_el_EF_e45_medium1() );
      } else {
         trig_EF_el_EF_e45_medium1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e5_tight1.IsAvailable() ) {
         trig_EF_el_EF_e5_tight1()->push_back( el.trig_EF_el_EF_e5_tight1() );
      } else {
         trig_EF_el_EF_e5_tight1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi.IsAvailable() ) {
         trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi()->push_back( el.trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi() );
      } else {
         trig_EF_el_EF_e5_tight1_e14_etcut_Jpsi()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi.IsAvailable() ) {
         trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi()->push_back( el.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi() );
      } else {
         trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB.IsAvailable() ) {
         trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB()->push_back( el.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB() );
      } else {
         trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarB()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC.IsAvailable() ) {
         trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC()->push_back( el.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC() );
      } else {
         trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_L2StarC()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e5_tight1_e5_NoCut.IsAvailable() ) {
         trig_EF_el_EF_e5_tight1_e5_NoCut()->push_back( el.trig_EF_el_EF_e5_tight1_e5_NoCut() );
      } else {
         trig_EF_el_EF_e5_tight1_e5_NoCut()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi.IsAvailable() ) {
         trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi()->push_back( el.trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi() );
      } else {
         trig_EF_el_EF_e5_tight1_e9_etcut_Jpsi()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e60_medium1.IsAvailable() ) {
         trig_EF_el_EF_e60_medium1()->push_back( el.trig_EF_el_EF_e60_medium1() );
      } else {
         trig_EF_el_EF_e60_medium1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e7T_loose1.IsAvailable() ) {
         trig_EF_el_EF_e7T_loose1()->push_back( el.trig_EF_el_EF_e7T_loose1() );
      } else {
         trig_EF_el_EF_e7T_loose1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e7T_loose1_2mu6.IsAvailable() ) {
         trig_EF_el_EF_e7T_loose1_2mu6()->push_back( el.trig_EF_el_EF_e7T_loose1_2mu6() );
      } else {
         trig_EF_el_EF_e7T_loose1_2mu6()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e7T_medium1.IsAvailable() ) {
         trig_EF_el_EF_e7T_medium1()->push_back( el.trig_EF_el_EF_e7T_medium1() );
      } else {
         trig_EF_el_EF_e7T_medium1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e7T_medium1_2mu6.IsAvailable() ) {
         trig_EF_el_EF_e7T_medium1_2mu6()->push_back( el.trig_EF_el_EF_e7T_medium1_2mu6() );
      } else {
         trig_EF_el_EF_e7T_medium1_2mu6()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi.IsAvailable() ) {
         trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi()->push_back( el.trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi() );
      } else {
         trig_EF_el_EF_e9_tight1_e4_etcut_Jpsi()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_eb_physics.IsAvailable() ) {
         trig_EF_el_EF_eb_physics()->push_back( el.trig_EF_el_EF_eb_physics() );
      } else {
         trig_EF_el_EF_eb_physics()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_eb_physics_empty.IsAvailable() ) {
         trig_EF_el_EF_eb_physics_empty()->push_back( el.trig_EF_el_EF_eb_physics_empty() );
      } else {
         trig_EF_el_EF_eb_physics_empty()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_eb_physics_firstempty.IsAvailable() ) {
         trig_EF_el_EF_eb_physics_firstempty()->push_back( el.trig_EF_el_EF_eb_physics_firstempty() );
      } else {
         trig_EF_el_EF_eb_physics_firstempty()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_eb_physics_noL1PS.IsAvailable() ) {
         trig_EF_el_EF_eb_physics_noL1PS()->push_back( el.trig_EF_el_EF_eb_physics_noL1PS() );
      } else {
         trig_EF_el_EF_eb_physics_noL1PS()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_eb_physics_unpaired_iso.IsAvailable() ) {
         trig_EF_el_EF_eb_physics_unpaired_iso()->push_back( el.trig_EF_el_EF_eb_physics_unpaired_iso() );
      } else {
         trig_EF_el_EF_eb_physics_unpaired_iso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_eb_physics_unpaired_noniso.IsAvailable() ) {
         trig_EF_el_EF_eb_physics_unpaired_noniso()->push_back( el.trig_EF_el_EF_eb_physics_unpaired_noniso() );
      } else {
         trig_EF_el_EF_eb_physics_unpaired_noniso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_eb_random.IsAvailable() ) {
         trig_EF_el_EF_eb_random()->push_back( el.trig_EF_el_EF_eb_random() );
      } else {
         trig_EF_el_EF_eb_random()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_eb_random_empty.IsAvailable() ) {
         trig_EF_el_EF_eb_random_empty()->push_back( el.trig_EF_el_EF_eb_random_empty() );
      } else {
         trig_EF_el_EF_eb_random_empty()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_eb_random_firstempty.IsAvailable() ) {
         trig_EF_el_EF_eb_random_firstempty()->push_back( el.trig_EF_el_EF_eb_random_firstempty() );
      } else {
         trig_EF_el_EF_eb_random_firstempty()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_eb_random_unpaired_iso.IsAvailable() ) {
         trig_EF_el_EF_eb_random_unpaired_iso()->push_back( el.trig_EF_el_EF_eb_random_unpaired_iso() );
      } else {
         trig_EF_el_EF_eb_random_unpaired_iso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_emcl_pt.IsAvailable() ) {
         trig_EF_emcl_pt()->push_back( el.trig_EF_emcl_pt() );
      } else {
         trig_EF_emcl_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_emcl_eta.IsAvailable() ) {
         trig_EF_emcl_eta()->push_back( el.trig_EF_emcl_eta() );
      } else {
         trig_EF_emcl_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_emcl_phi.IsAvailable() ) {
         trig_EF_emcl_phi()->push_back( el.trig_EF_emcl_phi() );
      } else {
         trig_EF_emcl_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_emcl_E_em.IsAvailable() ) {
         trig_EF_emcl_E_em()->push_back( el.trig_EF_emcl_E_em() );
      } else {
         trig_EF_emcl_E_em()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_emcl_E_had.IsAvailable() ) {
         trig_EF_emcl_E_had()->push_back( el.trig_EF_emcl_E_had() );
      } else {
         trig_EF_emcl_E_had()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_emcl_slw_pt.IsAvailable() ) {
         trig_EF_emcl_slw_pt()->push_back( el.trig_EF_emcl_slw_pt() );
      } else {
         trig_EF_emcl_slw_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_emcl_slw_eta.IsAvailable() ) {
         trig_EF_emcl_slw_eta()->push_back( el.trig_EF_emcl_slw_eta() );
      } else {
         trig_EF_emcl_slw_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_emcl_slw_phi.IsAvailable() ) {
         trig_EF_emcl_slw_phi()->push_back( el.trig_EF_emcl_slw_phi() );
      } else {
         trig_EF_emcl_slw_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_emcl_slw_E_em.IsAvailable() ) {
         trig_EF_emcl_slw_E_em()->push_back( el.trig_EF_emcl_slw_E_em() );
      } else {
         trig_EF_emcl_slw_E_em()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_emcl_slw_E_had.IsAvailable() ) {
         trig_EF_emcl_slw_E_had()->push_back( el.trig_EF_emcl_slw_E_had() );
      } else {
         trig_EF_emcl_slw_E_had()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_el_E.IsAvailable() ) {
         trig_EF_el_E()->push_back( el.trig_EF_el_E() );
      } else {
         trig_EF_el_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_el_Et.IsAvailable() ) {
         trig_EF_el_Et()->push_back( el.trig_EF_el_Et() );
      } else {
         trig_EF_el_Et()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_el_pt.IsAvailable() ) {
         trig_EF_el_pt()->push_back( el.trig_EF_el_pt() );
      } else {
         trig_EF_el_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_el_m.IsAvailable() ) {
         trig_EF_el_m()->push_back( el.trig_EF_el_m() );
      } else {
         trig_EF_el_m()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_el_eta.IsAvailable() ) {
         trig_EF_el_eta()->push_back( el.trig_EF_el_eta() );
      } else {
         trig_EF_el_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_el_phi.IsAvailable() ) {
         trig_EF_el_phi()->push_back( el.trig_EF_el_phi() );
      } else {
         trig_EF_el_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_el_px.IsAvailable() ) {
         trig_EF_el_px()->push_back( el.trig_EF_el_px() );
      } else {
         trig_EF_el_px()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_el_py.IsAvailable() ) {
         trig_EF_el_py()->push_back( el.trig_EF_el_py() );
      } else {
         trig_EF_el_py()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_el_pz.IsAvailable() ) {
         trig_EF_el_pz()->push_back( el.trig_EF_el_pz() );
      } else {
         trig_EF_el_pz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_el_charge.IsAvailable() ) {
         trig_EF_el_charge()->push_back( el.trig_EF_el_charge() );
      } else {
         trig_EF_el_charge()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_el_author.IsAvailable() ) {
         trig_EF_el_author()->push_back( el.trig_EF_el_author() );
      } else {
         trig_EF_el_author()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_isEM.IsAvailable() ) {
         trig_EF_el_isEM()->push_back( el.trig_EF_el_isEM() );
      } else {
         trig_EF_el_isEM()->push_back( std::numeric_limits< unsigned int >::min() );
      }
      if( el.trig_EF_el_isEMLoose.IsAvailable() ) {
         trig_EF_el_isEMLoose()->push_back( el.trig_EF_el_isEMLoose() );
      } else {
         trig_EF_el_isEMLoose()->push_back( std::numeric_limits< unsigned int >::min() );
      }
      if( el.trig_EF_el_isEMMedium.IsAvailable() ) {
         trig_EF_el_isEMMedium()->push_back( el.trig_EF_el_isEMMedium() );
      } else {
         trig_EF_el_isEMMedium()->push_back( std::numeric_limits< unsigned int >::min() );
      }
      if( el.trig_EF_el_isEMTight.IsAvailable() ) {
         trig_EF_el_isEMTight()->push_back( el.trig_EF_el_isEMTight() );
      } else {
         trig_EF_el_isEMTight()->push_back( std::numeric_limits< unsigned int >::min() );
      }
      if( el.trig_EF_el_loose.IsAvailable() ) {
         trig_EF_el_loose()->push_back( el.trig_EF_el_loose() );
      } else {
         trig_EF_el_loose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_looseIso.IsAvailable() ) {
         trig_EF_el_looseIso()->push_back( el.trig_EF_el_looseIso() );
      } else {
         trig_EF_el_looseIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_medium.IsAvailable() ) {
         trig_EF_el_medium()->push_back( el.trig_EF_el_medium() );
      } else {
         trig_EF_el_medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_mediumIso.IsAvailable() ) {
         trig_EF_el_mediumIso()->push_back( el.trig_EF_el_mediumIso() );
      } else {
         trig_EF_el_mediumIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_mediumWithoutTrack.IsAvailable() ) {
         trig_EF_el_mediumWithoutTrack()->push_back( el.trig_EF_el_mediumWithoutTrack() );
      } else {
         trig_EF_el_mediumWithoutTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_mediumIsoWithoutTrack.IsAvailable() ) {
         trig_EF_el_mediumIsoWithoutTrack()->push_back( el.trig_EF_el_mediumIsoWithoutTrack() );
      } else {
         trig_EF_el_mediumIsoWithoutTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_tight.IsAvailable() ) {
         trig_EF_el_tight()->push_back( el.trig_EF_el_tight() );
      } else {
         trig_EF_el_tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_tightIso.IsAvailable() ) {
         trig_EF_el_tightIso()->push_back( el.trig_EF_el_tightIso() );
      } else {
         trig_EF_el_tightIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_tightWithoutTrack.IsAvailable() ) {
         trig_EF_el_tightWithoutTrack()->push_back( el.trig_EF_el_tightWithoutTrack() );
      } else {
         trig_EF_el_tightWithoutTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_tightIsoWithoutTrack.IsAvailable() ) {
         trig_EF_el_tightIsoWithoutTrack()->push_back( el.trig_EF_el_tightIsoWithoutTrack() );
      } else {
         trig_EF_el_tightIsoWithoutTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_loosePP.IsAvailable() ) {
         trig_EF_el_loosePP()->push_back( el.trig_EF_el_loosePP() );
      } else {
         trig_EF_el_loosePP()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_loosePPIso.IsAvailable() ) {
         trig_EF_el_loosePPIso()->push_back( el.trig_EF_el_loosePPIso() );
      } else {
         trig_EF_el_loosePPIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_mediumPP.IsAvailable() ) {
         trig_EF_el_mediumPP()->push_back( el.trig_EF_el_mediumPP() );
      } else {
         trig_EF_el_mediumPP()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_mediumPPIso.IsAvailable() ) {
         trig_EF_el_mediumPPIso()->push_back( el.trig_EF_el_mediumPPIso() );
      } else {
         trig_EF_el_mediumPPIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_tightPP.IsAvailable() ) {
         trig_EF_el_tightPP()->push_back( el.trig_EF_el_tightPP() );
      } else {
         trig_EF_el_tightPP()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_tightPPIso.IsAvailable() ) {
         trig_EF_el_tightPPIso()->push_back( el.trig_EF_el_tightPPIso() );
      } else {
         trig_EF_el_tightPPIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_vertweight.IsAvailable() ) {
         trig_EF_el_vertweight()->push_back( el.trig_EF_el_vertweight() );
      } else {
         trig_EF_el_vertweight()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_el_hastrack.IsAvailable() ) {
         trig_EF_el_hastrack()->push_back( el.trig_EF_el_hastrack() );
      } else {
         trig_EF_el_hastrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_track_CB_pt.IsAvailable() ) {
         trig_EF_trigmuonef_track_CB_pt()->push_back( el.trig_EF_trigmuonef_track_CB_pt() );
      } else {
         trig_EF_trigmuonef_track_CB_pt()->push_back( vector<float>() );
      }
      if( el.trig_EF_trigmuonef_track_CB_eta.IsAvailable() ) {
         trig_EF_trigmuonef_track_CB_eta()->push_back( el.trig_EF_trigmuonef_track_CB_eta() );
      } else {
         trig_EF_trigmuonef_track_CB_eta()->push_back( vector<float>() );
      }
      if( el.trig_EF_trigmuonef_track_CB_phi.IsAvailable() ) {
         trig_EF_trigmuonef_track_CB_phi()->push_back( el.trig_EF_trigmuonef_track_CB_phi() );
      } else {
         trig_EF_trigmuonef_track_CB_phi()->push_back( vector<float>() );
      }
      if( el.trig_EF_trigmuonef_track_CB_hasCB.IsAvailable() ) {
         trig_EF_trigmuonef_track_CB_hasCB()->push_back( el.trig_EF_trigmuonef_track_CB_hasCB() );
      } else {
         trig_EF_trigmuonef_track_CB_hasCB()->push_back( vector<int>() );
      }

    // =============================================================================
    // = Data only
    // =============================================================================
      if( el.trig_EF_trigmuonef_EF_2mu10.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu10()->push_back( el.trig_EF_trigmuonef_EF_2mu10() );
      } else {
         trig_EF_trigmuonef_EF_2mu10()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose()->push_back( el.trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose() );
      } else {
         trig_EF_trigmuonef_EF_2mu10_MSonly_g10_loose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu13.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu13()->push_back( el.trig_EF_trigmuonef_EF_2mu13() );
      } else {
         trig_EF_trigmuonef_EF_2mu13()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut()->push_back( el.trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut() );
      } else {
         trig_EF_trigmuonef_EF_2mu13_Zmumu_IDTrkNoCut()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu13_l2muonSA.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu13_l2muonSA()->push_back( el.trig_EF_trigmuonef_EF_2mu13_l2muonSA() );
      } else {
         trig_EF_trigmuonef_EF_2mu13_l2muonSA()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu15.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu15()->push_back( el.trig_EF_trigmuonef_EF_2mu15() );
      } else {
         trig_EF_trigmuonef_EF_2mu15()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T()->push_back( el.trig_EF_trigmuonef_EF_2mu4T() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_2e5_tight1.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_2e5_tight1()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_2e5_tight1() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_2e5_tight1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_Bmumu.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_Bmumu()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_Bmumu() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_Bmumu()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_Bmumu_Barrel()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_Bmumu_BarrelOnly()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_Bmumux.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_Bmumux()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_Bmumux() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_Bmumux()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_Bmumux_Barrel()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_Bmumux_BarrelOnly()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_DiMu.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_DiMu()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_DiMu() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_DiMu()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_DiMu_Barrel()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_DiMu_BarrelOnly()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarB()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_DiMu_L2StarC()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_DiMu_e5_tight1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_DiMu_l2muonSA()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_DiMu_noVtx_noOS()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_Jpsimumu.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_Jpsimumu()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_Jpsimumu() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_Jpsimumu()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_Barrel()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_BarrelOnly()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_Jpsimumu_IDTrkNoCut()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_Upsimumu.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_Upsimumu()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_Upsimumu() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_Upsimumu()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_Upsimumu_Barrel()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_Upsimumu_BarrelOnly()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_xe60.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_xe60()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_xe60() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_xe60()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw()->push_back( el.trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw() );
      } else {
         trig_EF_trigmuonef_EF_2mu4T_xe60_tclcw()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu6.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu6()->push_back( el.trig_EF_trigmuonef_EF_2mu6() );
      } else {
         trig_EF_trigmuonef_EF_2mu6()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu6_Bmumu.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu6_Bmumu()->push_back( el.trig_EF_trigmuonef_EF_2mu6_Bmumu() );
      } else {
         trig_EF_trigmuonef_EF_2mu6_Bmumu()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu6_Bmumux.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu6_Bmumux()->push_back( el.trig_EF_trigmuonef_EF_2mu6_Bmumux() );
      } else {
         trig_EF_trigmuonef_EF_2mu6_Bmumux()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu6_DiMu.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu6_DiMu()->push_back( el.trig_EF_trigmuonef_EF_2mu6_DiMu() );
      } else {
         trig_EF_trigmuonef_EF_2mu6_DiMu()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu6_DiMu_DY20.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu6_DiMu_DY20()->push_back( el.trig_EF_trigmuonef_EF_2mu6_DiMu_DY20() );
      } else {
         trig_EF_trigmuonef_EF_2mu6_DiMu_DY20()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu6_DiMu_DY25.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu6_DiMu_DY25()->push_back( el.trig_EF_trigmuonef_EF_2mu6_DiMu_DY25() );
      } else {
         trig_EF_trigmuonef_EF_2mu6_DiMu_DY25()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS()->push_back( el.trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS() );
      } else {
         trig_EF_trigmuonef_EF_2mu6_DiMu_noVtx_noOS()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu6_Jpsimumu.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu6_Jpsimumu()->push_back( el.trig_EF_trigmuonef_EF_2mu6_Jpsimumu() );
      } else {
         trig_EF_trigmuonef_EF_2mu6_Jpsimumu()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu6_Upsimumu.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu6_Upsimumu()->push_back( el.trig_EF_trigmuonef_EF_2mu6_Upsimumu() );
      } else {
         trig_EF_trigmuonef_EF_2mu6_Upsimumu()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu6i_DiMu_DY.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu6i_DiMu_DY()->push_back( el.trig_EF_trigmuonef_EF_2mu6i_DiMu_DY() );
      } else {
         trig_EF_trigmuonef_EF_2mu6i_DiMu_DY()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad()->push_back( el.trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad() );
      } else {
         trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_2j25_a4tchad()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS()->push_back( el.trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS() );
      } else {
         trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad()->push_back( el.trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad() );
      } else {
         trig_EF_trigmuonef_EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu8_EFxe30.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu8_EFxe30()->push_back( el.trig_EF_trigmuonef_EF_2mu8_EFxe30() );
      } else {
         trig_EF_trigmuonef_EF_2mu8_EFxe30()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw.IsAvailable() ) {
         trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw()->push_back( el.trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw() );
      } else {
         trig_EF_trigmuonef_EF_2mu8_EFxe30_tclcw()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu10.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu10()->push_back( el.trig_EF_trigmuonef_EF_mu10() );
      } else {
         trig_EF_trigmuonef_EF_mu10()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu10_Jpsimumu.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu10_Jpsimumu()->push_back( el.trig_EF_trigmuonef_EF_mu10_Jpsimumu() );
      } else {
         trig_EF_trigmuonef_EF_mu10_Jpsimumu()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu10_MSonly.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu10_MSonly()->push_back( el.trig_EF_trigmuonef_EF_mu10_MSonly() );
      } else {
         trig_EF_trigmuonef_EF_mu10_MSonly()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS()->push_back( el.trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS() );
      } else {
         trig_EF_trigmuonef_EF_mu10_Upsimumu_tight_FS()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu10i_g10_medium.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu10i_g10_medium()->push_back( el.trig_EF_trigmuonef_EF_mu10i_g10_medium() );
      } else {
         trig_EF_trigmuonef_EF_mu10i_g10_medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass()->push_back( el.trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass() );
      } else {
         trig_EF_trigmuonef_EF_mu10i_g10_medium_TauMass()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium()->push_back( el.trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium() );
      } else {
         trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass()->push_back( el.trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass() );
      } else {
         trig_EF_trigmuonef_EF_mu10i_loose_g12Tvh_medium_TauMass()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu11_empty_NoAlg.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu11_empty_NoAlg()->push_back( el.trig_EF_trigmuonef_EF_mu11_empty_NoAlg() );
      } else {
         trig_EF_trigmuonef_EF_mu11_empty_NoAlg()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu13.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu13()->push_back( el.trig_EF_trigmuonef_EF_mu13() );
      } else {
         trig_EF_trigmuonef_EF_mu13()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu15.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu15()->push_back( el.trig_EF_trigmuonef_EF_mu15() );
      } else {
         trig_EF_trigmuonef_EF_mu15()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu18.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu18()->push_back( el.trig_EF_trigmuonef_EF_mu18() );
      } else {
         trig_EF_trigmuonef_EF_mu18()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu18_2g10_loose.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu18_2g10_loose()->push_back( el.trig_EF_trigmuonef_EF_mu18_2g10_loose() );
      } else {
         trig_EF_trigmuonef_EF_mu18_2g10_loose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu18_2g10_medium.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu18_2g10_medium()->push_back( el.trig_EF_trigmuonef_EF_mu18_2g10_medium() );
      } else {
         trig_EF_trigmuonef_EF_mu18_2g10_medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight()->push_back( el.trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight() );
      } else {
         trig_EF_trigmuonef_EF_mu18_IDTrkNoCut_tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu18_medium.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu18_medium()->push_back( el.trig_EF_trigmuonef_EF_mu18_medium() );
      } else {
         trig_EF_trigmuonef_EF_mu18_medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu18_tight.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu18_tight()->push_back( el.trig_EF_trigmuonef_EF_mu18_tight() );
      } else {
         trig_EF_trigmuonef_EF_mu18_tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS()->push_back( el.trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS() );
      } else {
         trig_EF_trigmuonef_EF_mu18_tight_2mu4_EFFS()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu18_tight_e7_medium1.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu18_tight_e7_medium1()->push_back( el.trig_EF_trigmuonef_EF_mu18_tight_e7_medium1() );
      } else {
         trig_EF_trigmuonef_EF_mu18_tight_e7_medium1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS()->push_back( el.trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS() );
      } else {
         trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu18i4_tight.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu18i4_tight()->push_back( el.trig_EF_trigmuonef_EF_mu18i4_tight() );
      } else {
         trig_EF_trigmuonef_EF_mu18i4_tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass()->push_back( el.trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass() );
      } else {
         trig_EF_trigmuonef_EF_mu20i_tight_g5_loose_TauMass()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu20i_tight_g5_medium.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu20i_tight_g5_medium()->push_back( el.trig_EF_trigmuonef_EF_mu20i_tight_g5_medium() );
      } else {
         trig_EF_trigmuonef_EF_mu20i_tight_g5_medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass()->push_back( el.trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass() );
      } else {
         trig_EF_trigmuonef_EF_mu20i_tight_g5_medium_TauMass()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu20it_tight.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu20it_tight()->push_back( el.trig_EF_trigmuonef_EF_mu20it_tight() );
      } else {
         trig_EF_trigmuonef_EF_mu20it_tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight()->push_back( el.trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight() );
      } else {
         trig_EF_trigmuonef_EF_mu22_IDTrkNoCut_tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24()->push_back( el.trig_EF_trigmuonef_EF_mu24() );
      } else {
         trig_EF_trigmuonef_EF_mu24()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24_g20vh_loose.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24_g20vh_loose()->push_back( el.trig_EF_trigmuonef_EF_mu24_g20vh_loose() );
      } else {
         trig_EF_trigmuonef_EF_mu24_g20vh_loose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24_g20vh_medium.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24_g20vh_medium()->push_back( el.trig_EF_trigmuonef_EF_mu24_g20vh_medium() );
      } else {
         trig_EF_trigmuonef_EF_mu24_g20vh_medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24_j65_a4tchad.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24_j65_a4tchad()->push_back( el.trig_EF_trigmuonef_EF_mu24_j65_a4tchad() );
      } else {
         trig_EF_trigmuonef_EF_mu24_j65_a4tchad()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40()->push_back( el.trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40() );
      } else {
         trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw()->push_back( el.trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw() );
      } else {
         trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe40_tclcw()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw()->push_back( el.trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw() );
      } else {
         trig_EF_trigmuonef_EF_mu24_j65_a4tchad_EFxe60_tclcw()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24_medium.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24_medium()->push_back( el.trig_EF_trigmuonef_EF_mu24_medium() );
      } else {
         trig_EF_trigmuonef_EF_mu24_medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight()->push_back( el.trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight() );
      } else {
         trig_EF_trigmuonef_EF_mu24_muCombTag_NoEF_tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24_tight.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24_tight()->push_back( el.trig_EF_trigmuonef_EF_mu24_tight() );
      } else {
         trig_EF_trigmuonef_EF_mu24_tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad()->push_back( el.trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad() );
      } else {
         trig_EF_trigmuonef_EF_mu24_tight_3j35_a4tchad()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24_tight_EFxe40.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24_tight_EFxe40()->push_back( el.trig_EF_trigmuonef_EF_mu24_tight_EFxe40() );
      } else {
         trig_EF_trigmuonef_EF_mu24_tight_EFxe40()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24_tight_L2StarB.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24_tight_L2StarB()->push_back( el.trig_EF_trigmuonef_EF_mu24_tight_L2StarB() );
      } else {
         trig_EF_trigmuonef_EF_mu24_tight_L2StarB()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24_tight_L2StarC.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24_tight_L2StarC()->push_back( el.trig_EF_trigmuonef_EF_mu24_tight_L2StarC() );
      } else {
         trig_EF_trigmuonef_EF_mu24_tight_L2StarC()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24_tight_MG.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24_tight_MG()->push_back( el.trig_EF_trigmuonef_EF_mu24_tight_MG() );
      } else {
         trig_EF_trigmuonef_EF_mu24_tight_MG()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24_tight_MuonEF.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24_tight_MuonEF()->push_back( el.trig_EF_trigmuonef_EF_mu24_tight_MuonEF() );
      } else {
         trig_EF_trigmuonef_EF_mu24_tight_MuonEF()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad()->push_back( el.trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad() );
      } else {
         trig_EF_trigmuonef_EF_mu24_tight_b35_mediumEF_j35_a4tchad()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS()->push_back( el.trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS() );
      } else {
         trig_EF_trigmuonef_EF_mu24_tight_mu6_EFFS()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24i_tight.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24i_tight()->push_back( el.trig_EF_trigmuonef_EF_mu24i_tight() );
      } else {
         trig_EF_trigmuonef_EF_mu24i_tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24i_tight_MG.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24i_tight_MG()->push_back( el.trig_EF_trigmuonef_EF_mu24i_tight_MG() );
      } else {
         trig_EF_trigmuonef_EF_mu24i_tight_MG()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24i_tight_MuonEF.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24i_tight_MuonEF()->push_back( el.trig_EF_trigmuonef_EF_mu24i_tight_MuonEF() );
      } else {
         trig_EF_trigmuonef_EF_mu24i_tight_MuonEF()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA()->push_back( el.trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA() );
      } else {
         trig_EF_trigmuonef_EF_mu24i_tight_l2muonSA()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu36_tight.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu36_tight()->push_back( el.trig_EF_trigmuonef_EF_mu36_tight() );
      } else {
         trig_EF_trigmuonef_EF_mu36_tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight()->push_back( el.trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight() );
      } else {
         trig_EF_trigmuonef_EF_mu40_MSonly_barrel_tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF()->push_back( el.trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF() );
      } else {
         trig_EF_trigmuonef_EF_mu40_muCombTag_NoEF()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight()->push_back( el.trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight() );
      } else {
         trig_EF_trigmuonef_EF_mu40_slow_outOfTime_tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu40_slow_tight.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu40_slow_tight()->push_back( el.trig_EF_trigmuonef_EF_mu40_slow_tight() );
      } else {
         trig_EF_trigmuonef_EF_mu40_slow_tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu40_tight.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu40_tight()->push_back( el.trig_EF_trigmuonef_EF_mu40_tight() );
      } else {
         trig_EF_trigmuonef_EF_mu40_tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T()->push_back( el.trig_EF_trigmuonef_EF_mu4T() );
      } else {
         trig_EF_trigmuonef_EF_mu4T()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_cosmic.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_cosmic()->push_back( el.trig_EF_trigmuonef_EF_mu4T_cosmic() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_cosmic()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_L2FS_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j110_a4tchad_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_L2FS_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j145_a4tchad_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j15_a4tchad_matchedZ()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_L2FS_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j180_a4tchad_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_L2FS_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j220_a4tchad_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j25_a4tchad_matchedZ()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_L2FS_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j280_a4tchad_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j35_a4tchad_matchedZ()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_L2FS_matchedZ()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j45_a4tchad_matchedZ()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_L2FS_matchedZ()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j55_a4tchad_matchedZ()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_L2FS_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe60_tclcw_loose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_L2FS_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched()->push_back( el.trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched() );
      } else {
         trig_EF_trigmuonef_EF_mu4T_j80_a4tchad_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium()->push_back( el.trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium() );
      } else {
         trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass()->push_back( el.trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass() );
      } else {
         trig_EF_trigmuonef_EF_mu4Ti_g20Tvh_medium_TauMass()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu()->push_back( el.trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu() );
      } else {
         trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel()->push_back( el.trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel() );
      } else {
         trig_EF_trigmuonef_EF_mu4Tmu6_Bmumu_Barrel()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux()->push_back( el.trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux() );
      } else {
         trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel()->push_back( el.trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel() );
      } else {
         trig_EF_trigmuonef_EF_mu4Tmu6_Bmumux_Barrel()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4Tmu6_DiMu.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4Tmu6_DiMu()->push_back( el.trig_EF_trigmuonef_EF_mu4Tmu6_DiMu() );
      } else {
         trig_EF_trigmuonef_EF_mu4Tmu6_DiMu()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel()->push_back( el.trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel() );
      } else {
         trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_Barrel()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS()->push_back( el.trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS() );
      } else {
         trig_EF_trigmuonef_EF_mu4Tmu6_DiMu_noVtx_noOS()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu()->push_back( el.trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu() );
      } else {
         trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel()->push_back( el.trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel() );
      } else {
         trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_Barrel()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut()->push_back( el.trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut() );
      } else {
         trig_EF_trigmuonef_EF_mu4Tmu6_Jpsimumu_IDTrkNoCut()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu()->push_back( el.trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu() );
      } else {
         trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel()->push_back( el.trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel() );
      } else {
         trig_EF_trigmuonef_EF_mu4Tmu6_Upsimumu_Barrel()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic()->push_back( el.trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic() );
      } else {
         trig_EF_trigmuonef_EF_mu4_L1MU11_MSonly_cosmic()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic()->push_back( el.trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic() );
      } else {
         trig_EF_trigmuonef_EF_mu4_L1MU11_cosmic()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4_empty_NoAlg.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4_empty_NoAlg()->push_back( el.trig_EF_trigmuonef_EF_mu4_empty_NoAlg() );
      } else {
         trig_EF_trigmuonef_EF_mu4_empty_NoAlg()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg()->push_back( el.trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg() );
      } else {
         trig_EF_trigmuonef_EF_mu4_firstempty_NoAlg()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg()->push_back( el.trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg() );
      } else {
         trig_EF_trigmuonef_EF_mu4_unpaired_iso_NoAlg()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight()->push_back( el.trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight() );
      } else {
         trig_EF_trigmuonef_EF_mu50_MSonly_barrel_tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu6.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu6()->push_back( el.trig_EF_trigmuonef_EF_mu6() );
      } else {
         trig_EF_trigmuonef_EF_mu6()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1()->push_back( el.trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1() );
      } else {
         trig_EF_trigmuonef_EF_mu60_slow_outOfTime_tight1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu60_slow_tight1.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu60_slow_tight1()->push_back( el.trig_EF_trigmuonef_EF_mu60_slow_tight1() );
      } else {
         trig_EF_trigmuonef_EF_mu60_slow_tight1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight()->push_back( el.trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight() );
      } else {
         trig_EF_trigmuonef_EF_mu6_Jpsimumu_tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu6_MSonly.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu6_MSonly()->push_back( el.trig_EF_trigmuonef_EF_mu6_MSonly() );
      } else {
         trig_EF_trigmuonef_EF_mu6_MSonly()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose()->push_back( el.trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose() );
      } else {
         trig_EF_trigmuonef_EF_mu6_Trk_Jpsi_loose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu8.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu8()->push_back( el.trig_EF_trigmuonef_EF_mu8() );
      } else {
         trig_EF_trigmuonef_EF_mu8()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS()->push_back( el.trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS() );
      } else {
         trig_EF_trigmuonef_EF_mu8_4j45_a4tchad_L2FS()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_track_MuonType.IsAvailable() ) {
         trig_EF_trigmuonef_track_MuonType()->push_back( el.trig_EF_trigmuonef_track_MuonType() );
      } else {
         trig_EF_trigmuonef_track_MuonType()->push_back( vector<int>() );
      }
      if( el.trig_EF_trigmuonef_track_MS_pt.IsAvailable() ) {
         trig_EF_trigmuonef_track_MS_pt()->push_back( el.trig_EF_trigmuonef_track_MS_pt() );
      } else {
         trig_EF_trigmuonef_track_MS_pt()->push_back( vector<float>() );
      }
      if( el.trig_EF_trigmuonef_track_MS_eta.IsAvailable() ) {
         trig_EF_trigmuonef_track_MS_eta()->push_back( el.trig_EF_trigmuonef_track_MS_eta() );
      } else {
         trig_EF_trigmuonef_track_MS_eta()->push_back( vector<float>() );
      }
      if( el.trig_EF_trigmuonef_track_MS_phi.IsAvailable() ) {
         trig_EF_trigmuonef_track_MS_phi()->push_back( el.trig_EF_trigmuonef_track_MS_phi() );
      } else {
         trig_EF_trigmuonef_track_MS_phi()->push_back( vector<float>() );
      }
      if( el.trig_EF_trigmuonef_track_MS_hasMS.IsAvailable() ) {
         trig_EF_trigmuonef_track_MS_hasMS()->push_back( el.trig_EF_trigmuonef_track_MS_hasMS() );
      } else {
         trig_EF_trigmuonef_track_MS_hasMS()->push_back( vector<int>() );
      }
      if( el.trig_EF_trigmuonef_track_SA_pt.IsAvailable() ) {
         trig_EF_trigmuonef_track_SA_pt()->push_back( el.trig_EF_trigmuonef_track_SA_pt() );
      } else {
         trig_EF_trigmuonef_track_SA_pt()->push_back( vector<float>() );
      }
      if( el.trig_EF_trigmuonef_track_SA_eta.IsAvailable() ) {
         trig_EF_trigmuonef_track_SA_eta()->push_back( el.trig_EF_trigmuonef_track_SA_eta() );
      } else {
         trig_EF_trigmuonef_track_SA_eta()->push_back( vector<float>() );
      }
      if( el.trig_EF_trigmuonef_track_SA_phi.IsAvailable() ) {
         trig_EF_trigmuonef_track_SA_phi()->push_back( el.trig_EF_trigmuonef_track_SA_phi() );
      } else {
         trig_EF_trigmuonef_track_SA_phi()->push_back( vector<float>() );
      }
      if( el.trig_EF_trigmuonef_track_SA_hasSA.IsAvailable() ) {
         trig_EF_trigmuonef_track_SA_hasSA()->push_back( el.trig_EF_trigmuonef_track_SA_hasSA() );
      } else {
         trig_EF_trigmuonef_track_SA_hasSA()->push_back( vector<int>() );
      }
    
    // =============================================================================
    // = MC only
    // =============================================================================
      if( el.trig_EF_el_EF_e12Tvh_loose1_mu8.IsAvailable() ) {
         trig_EF_el_EF_e12Tvh_loose1_mu8()->push_back( el.trig_EF_el_EF_e12Tvh_loose1_mu8() );
      } else {
         trig_EF_el_EF_e12Tvh_loose1_mu8()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e12Tvh_medium1_mu10.IsAvailable() ) {
         trig_EF_el_EF_e12Tvh_medium1_mu10()->push_back( el.trig_EF_el_EF_e12Tvh_medium1_mu10() );
      } else {
         trig_EF_el_EF_e12Tvh_medium1_mu10()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e12Tvh_medium1_mu6.IsAvailable() ) {
         trig_EF_el_EF_e12Tvh_medium1_mu6()->push_back( el.trig_EF_el_EF_e12Tvh_medium1_mu6() );
      } else {
         trig_EF_el_EF_e12Tvh_medium1_mu6()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e18_loose1_g35_loose.IsAvailable() ) {
         trig_EF_el_EF_e18_loose1_g35_loose()->push_back( el.trig_EF_el_EF_e18_loose1_g35_loose() );
      } else {
         trig_EF_el_EF_e18_loose1_g35_loose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e18_loose1_g35_medium.IsAvailable() ) {
         trig_EF_el_EF_e18_loose1_g35_medium()->push_back( el.trig_EF_el_EF_e18_loose1_g35_medium() );
      } else {
         trig_EF_el_EF_e18_loose1_g35_medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e18_medium1_g25_medium.IsAvailable() ) {
         trig_EF_el_EF_e18_medium1_g25_medium()->push_back( el.trig_EF_el_EF_e18_medium1_g25_medium() );
      } else {
         trig_EF_el_EF_e18_medium1_g25_medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e18_medium1_g35_loose.IsAvailable() ) {
         trig_EF_el_EF_e18_medium1_g35_loose()->push_back( el.trig_EF_el_EF_e18_medium1_g35_loose() );
      } else {
         trig_EF_el_EF_e18_medium1_g35_loose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e18_medium1_g35_medium.IsAvailable() ) {
         trig_EF_el_EF_e18_medium1_g35_medium()->push_back( el.trig_EF_el_EF_e18_medium1_g35_medium() );
      } else {
         trig_EF_el_EF_e18_medium1_g35_medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e22vh_medium1_IdScan.IsAvailable() ) {
         trig_EF_el_EF_e22vh_medium1_IdScan()->push_back( el.trig_EF_el_EF_e22vh_medium1_IdScan() );
      } else {
         trig_EF_el_EF_e22vh_medium1_IdScan()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e22vh_medium1_SiTrk.IsAvailable() ) {
         trig_EF_el_EF_e22vh_medium1_SiTrk()->push_back( el.trig_EF_el_EF_e22vh_medium1_SiTrk() );
      } else {
         trig_EF_el_EF_e22vh_medium1_SiTrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e22vh_medium1_TRT.IsAvailable() ) {
         trig_EF_el_EF_e22vh_medium1_TRT()->push_back( el.trig_EF_el_EF_e22vh_medium1_TRT() );
      } else {
         trig_EF_el_EF_e22vh_medium1_TRT()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e45_etcut.IsAvailable() ) {
         trig_EF_el_EF_e45_etcut()->push_back( el.trig_EF_el_EF_e45_etcut() );
      } else {
         trig_EF_el_EF_e45_etcut()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan.IsAvailable() ) {
         trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan()->push_back( el.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan() );
      } else {
         trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_IdScan()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk.IsAvailable() ) {
         trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk()->push_back( el.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk() );
      } else {
         trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_SiTrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT.IsAvailable() ) {
         trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT()->push_back( el.trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT() );
      } else {
         trig_EF_el_EF_e5_tight1_e4_etcut_Jpsi_TRT()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e60_etcut.IsAvailable() ) {
         trig_EF_el_EF_e60_etcut()->push_back( el.trig_EF_el_EF_e60_etcut() );
      } else {
         trig_EF_el_EF_e60_etcut()->push_back( std::numeric_limits< int >::min() );
      }
    
      return *this;
   }

   /**
    * This operator can be used to get access to one element in the
    * collection. This element can then be passed around between parts
    * of the analysis code easily.
    *
    * This version is useful when modifying the variable contents through
    * the proxy objects.
    *
    * @param index Index of the element inside the collection
    */
   TriggerVecD3PDObjectElement& TriggerVecD3PDObject::operator[]( size_t index ) {

      while( fProxies.size() <= index ) {
         fProxies.push_back( TriggerVecD3PDObjectElement( fProxies.size(), *this ) );
      }
      return fProxies[ index ];
   }

   /**
    * This operator can be used to get access to one element in the
    * collection. This element can then be passed around between parts
    * of the analysis code easily.
    *
    * This version is useful when only reading the variables.
    *
    * @param index Index of the element inside the collection
    */
   const TriggerVecD3PDObjectElement& TriggerVecD3PDObject::operator[]( size_t index ) const {

      while( fProxies.size() <= index ) {
         fProxies.push_back( TriggerVecD3PDObjectElement( fProxies.size(), *this ) );
      }
      return fProxies[ index ];
   }

   /**
    * A convenience operator for adding an 'element' to this collection.
    *
    * @see Add
    * @param el The 'element' that should be added to the collection
    */
   TriggerVecD3PDObject& TriggerVecD3PDObject::operator+=( const TriggerVecD3PDObjectElement& el ) {

      return this->Add( el );
   }

} // namespace D3PDReader
