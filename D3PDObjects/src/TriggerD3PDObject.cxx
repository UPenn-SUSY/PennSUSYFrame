// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <TPRegexp.h>

#include "../include/TriggerD3PDObject.h"

ClassImp( D3PDReader::TriggerD3PDObject )

namespace D3PDReader {

   /**
    * This constructor should be used when the object will be used to read
    * variables from an existing ntuple. The object will also be able to
    * output variables, but it will also need to read them from somewhere.
    *
    * @param master Reference to the variable holding the current event number
    * @param prefix Prefix of the variables in the D3PD
    */
   TriggerD3PDObject::TriggerD3PDObject( const ::Long64_t& master, const char* prefix )
      : TObject(),
        EF_2e12Tvh_loose1( this, ::TString( prefix ) + "EF_2e12Tvh_loose1", &master ),
// -- slimmed --         EF_2e5_tight1_Jpsi( this, ::TString( prefix ) + "EF_2e5_tight1_Jpsi", &master ),
        EF_2e7T_loose1_mu6( this, ::TString( prefix ) + "EF_2e7T_loose1_mu6", &master ),
        EF_2e7T_medium1_mu6( this, ::TString( prefix ) + "EF_2e7T_medium1_mu6", &master ),
// -- slimmed --         EF_2g15vh_medium_g10_medium( this, ::TString( prefix ) + "EF_2g15vh_medium_g10_medium", &master ),
// -- slimmed --         EF_2g20vh_medium( this, ::TString( prefix ) + "EF_2g20vh_medium", &master ),
// -- slimmed --         EF_2g40_loose( this, ::TString( prefix ) + "EF_2g40_loose", &master ),
        EF_2mu10( this, ::TString( prefix ) + "EF_2mu10", &master ),
// -- slimmed --         EF_2mu10_MSonly_g10_loose( this, ::TString( prefix ) + "EF_2mu10_MSonly_g10_loose", &master ),
        EF_2mu13( this, ::TString( prefix ) + "EF_2mu13", &master ),
        EF_2mu13_Zmumu_IDTrkNoCut( this, ::TString( prefix ) + "EF_2mu13_Zmumu_IDTrkNoCut", &master ),
        EF_2mu13_l2muonSA( this, ::TString( prefix ) + "EF_2mu13_l2muonSA", &master ),
        EF_2mu15( this, ::TString( prefix ) + "EF_2mu15", &master ),
        EF_2mu4T( this, ::TString( prefix ) + "EF_2mu4T", &master ),
        EF_2mu4T_2e5_tight1( this, ::TString( prefix ) + "EF_2mu4T_2e5_tight1", &master ),
        EF_2mu4T_Bmumu( this, ::TString( prefix ) + "EF_2mu4T_Bmumu", &master ),
        EF_2mu4T_Bmumu_Barrel( this, ::TString( prefix ) + "EF_2mu4T_Bmumu_Barrel", &master ),
        EF_2mu4T_Bmumu_BarrelOnly( this, ::TString( prefix ) + "EF_2mu4T_Bmumu_BarrelOnly", &master ),
        EF_2mu4T_Bmumux( this, ::TString( prefix ) + "EF_2mu4T_Bmumux", &master ),
        EF_2mu4T_Bmumux_Barrel( this, ::TString( prefix ) + "EF_2mu4T_Bmumux_Barrel", &master ),
        EF_2mu4T_Bmumux_BarrelOnly( this, ::TString( prefix ) + "EF_2mu4T_Bmumux_BarrelOnly", &master ),
        EF_2mu4T_DiMu( this, ::TString( prefix ) + "EF_2mu4T_DiMu", &master ),
        EF_2mu4T_DiMu_Barrel( this, ::TString( prefix ) + "EF_2mu4T_DiMu_Barrel", &master ),
        EF_2mu4T_DiMu_BarrelOnly( this, ::TString( prefix ) + "EF_2mu4T_DiMu_BarrelOnly", &master ),
        EF_2mu4T_DiMu_L2StarB( this, ::TString( prefix ) + "EF_2mu4T_DiMu_L2StarB", &master ),
        EF_2mu4T_DiMu_L2StarC( this, ::TString( prefix ) + "EF_2mu4T_DiMu_L2StarC", &master ),
        EF_2mu4T_DiMu_e5_tight1( this, ::TString( prefix ) + "EF_2mu4T_DiMu_e5_tight1", &master ),
        EF_2mu4T_DiMu_l2muonSA( this, ::TString( prefix ) + "EF_2mu4T_DiMu_l2muonSA", &master ),
        EF_2mu4T_DiMu_noVtx_noOS( this, ::TString( prefix ) + "EF_2mu4T_DiMu_noVtx_noOS", &master ),
// -- slimmed --         EF_2mu4T_Jpsimumu( this, ::TString( prefix ) + "EF_2mu4T_Jpsimumu", &master ),
// -- slimmed --         EF_2mu4T_Jpsimumu_Barrel( this, ::TString( prefix ) + "EF_2mu4T_Jpsimumu_Barrel", &master ),
// -- slimmed --         EF_2mu4T_Jpsimumu_BarrelOnly( this, ::TString( prefix ) + "EF_2mu4T_Jpsimumu_BarrelOnly", &master ),
// -- slimmed --         EF_2mu4T_Jpsimumu_IDTrkNoCut( this, ::TString( prefix ) + "EF_2mu4T_Jpsimumu_IDTrkNoCut", &master ),
// -- slimmed --         EF_2mu4T_Upsimumu( this, ::TString( prefix ) + "EF_2mu4T_Upsimumu", &master ),
// -- slimmed --         EF_2mu4T_Upsimumu_Barrel( this, ::TString( prefix ) + "EF_2mu4T_Upsimumu_Barrel", &master ),
// -- slimmed --         EF_2mu4T_Upsimumu_BarrelOnly( this, ::TString( prefix ) + "EF_2mu4T_Upsimumu_BarrelOnly", &master ),
        EF_2mu4T_xe60( this, ::TString( prefix ) + "EF_2mu4T_xe60", &master ),
        EF_2mu4T_xe60_tclcw( this, ::TString( prefix ) + "EF_2mu4T_xe60_tclcw", &master ),
        EF_2mu6( this, ::TString( prefix ) + "EF_2mu6", &master ),
        EF_2mu6_Bmumu( this, ::TString( prefix ) + "EF_2mu6_Bmumu", &master ),
        EF_2mu6_Bmumux( this, ::TString( prefix ) + "EF_2mu6_Bmumux", &master ),
        EF_2mu6_DiMu( this, ::TString( prefix ) + "EF_2mu6_DiMu", &master ),
        EF_2mu6_DiMu_DY20( this, ::TString( prefix ) + "EF_2mu6_DiMu_DY20", &master ),
        EF_2mu6_DiMu_DY25( this, ::TString( prefix ) + "EF_2mu6_DiMu_DY25", &master ),
        EF_2mu6_DiMu_noVtx_noOS( this, ::TString( prefix ) + "EF_2mu6_DiMu_noVtx_noOS", &master ),
// -- slimmed --         EF_2mu6_Jpsimumu( this, ::TString( prefix ) + "EF_2mu6_Jpsimumu", &master ),
// -- slimmed --         EF_2mu6_Upsimumu( this, ::TString( prefix ) + "EF_2mu6_Upsimumu", &master ),
        EF_2mu6i_DiMu_DY( this, ::TString( prefix ) + "EF_2mu6i_DiMu_DY", &master ),
        EF_2mu6i_DiMu_DY_2j25_a4tchad( this, ::TString( prefix ) + "EF_2mu6i_DiMu_DY_2j25_a4tchad", &master ),
        EF_2mu6i_DiMu_DY_noVtx_noOS( this, ::TString( prefix ) + "EF_2mu6i_DiMu_DY_noVtx_noOS", &master ),
        EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad( this, ::TString( prefix ) + "EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad", &master ),
        EF_2mu8_EFxe30( this, ::TString( prefix ) + "EF_2mu8_EFxe30", &master ),
        EF_2mu8_EFxe30_tclcw( this, ::TString( prefix ) + "EF_2mu8_EFxe30_tclcw", &master ),
        EF_e11_etcut( this, ::TString( prefix ) + "EF_e11_etcut", &master ),
        EF_e12Tvh_loose1( this, ::TString( prefix ) + "EF_e12Tvh_loose1", &master ),
        EF_e12Tvh_medium1( this, ::TString( prefix ) + "EF_e12Tvh_medium1", &master ),
        EF_e12Tvh_medium1_mu6_topo_medium( this, ::TString( prefix ) + "EF_e12Tvh_medium1_mu6_topo_medium", &master ),
        EF_e12Tvh_medium1_mu8( this, ::TString( prefix ) + "EF_e12Tvh_medium1_mu8", &master ),
        EF_e13_etcutTrk_xs60( this, ::TString( prefix ) + "EF_e13_etcutTrk_xs60", &master ),
        EF_e13_etcutTrk_xs60_dphi2j15xe20( this, ::TString( prefix ) + "EF_e13_etcutTrk_xs60_dphi2j15xe20", &master ),
// -- slimmed --         EF_e14_tight1_e4_etcut_Jpsi( this, ::TString( prefix ) + "EF_e14_tight1_e4_etcut_Jpsi", &master ),
        EF_e15vh_medium1( this, ::TString( prefix ) + "EF_e15vh_medium1", &master ),
        EF_e18_loose1( this, ::TString( prefix ) + "EF_e18_loose1", &master ),
// -- slimmed --         EF_e18_loose1_g25_medium( this, ::TString( prefix ) + "EF_e18_loose1_g25_medium", &master ),
        EF_e18_medium1( this, ::TString( prefix ) + "EF_e18_medium1", &master ),
// -- slimmed --         EF_e18_medium1_g25_loose( this, ::TString( prefix ) + "EF_e18_medium1_g25_loose", &master ),
        EF_e18vh_medium1( this, ::TString( prefix ) + "EF_e18vh_medium1", &master ),
        EF_e18vh_medium1_2e7T_medium1( this, ::TString( prefix ) + "EF_e18vh_medium1_2e7T_medium1", &master ),
        EF_e20_etcutTrk_xe30_dphi2j15xe20( this, ::TString( prefix ) + "EF_e20_etcutTrk_xe30_dphi2j15xe20", &master ),
        EF_e20_etcutTrk_xs60_dphi2j15xe20( this, ::TString( prefix ) + "EF_e20_etcutTrk_xs60_dphi2j15xe20", &master ),
// -- slimmed -- // -- slimmed --         EF_e20vhT_medium1_g6T_etcut_Upsi( this, ::TString( prefix ) + "EF_e20vhT_medium1_g6T_etcut_Upsi", &master ),
// -- slimmed -- // -- slimmed --         EF_e20vhT_tight1_g6T_etcut_Upsi( this, ::TString( prefix ) + "EF_e20vhT_tight1_g6T_etcut_Upsi", &master ),
        EF_e22vh_loose( this, ::TString( prefix ) + "EF_e22vh_loose", &master ),
        EF_e22vh_loose0( this, ::TString( prefix ) + "EF_e22vh_loose0", &master ),
        EF_e22vh_loose1( this, ::TString( prefix ) + "EF_e22vh_loose1", &master ),
        EF_e22vh_medium1( this, ::TString( prefix ) + "EF_e22vh_medium1", &master ),
        EF_e22vh_medium1_IDTrkNoCut( this, ::TString( prefix ) + "EF_e22vh_medium1_IDTrkNoCut", &master ),
        EF_e22vhi_medium1( this, ::TString( prefix ) + "EF_e22vhi_medium1", &master ),
        EF_e24vh_loose( this, ::TString( prefix ) + "EF_e24vh_loose", &master ),
        EF_e24vh_loose0( this, ::TString( prefix ) + "EF_e24vh_loose0", &master ),
        EF_e24vh_loose1( this, ::TString( prefix ) + "EF_e24vh_loose1", &master ),
        EF_e24vh_medium1( this, ::TString( prefix ) + "EF_e24vh_medium1", &master ),
        EF_e24vh_medium1_EFxe30( this, ::TString( prefix ) + "EF_e24vh_medium1_EFxe30", &master ),
        EF_e24vh_medium1_EFxe30_tcem( this, ::TString( prefix ) + "EF_e24vh_medium1_EFxe30_tcem", &master ),
        EF_e24vh_medium1_EFxe35_tcem( this, ::TString( prefix ) + "EF_e24vh_medium1_EFxe35_tcem", &master ),
        EF_e24vh_medium1_EFxe35_tclcw( this, ::TString( prefix ) + "EF_e24vh_medium1_EFxe35_tclcw", &master ),
        EF_e24vh_medium1_EFxe40( this, ::TString( prefix ) + "EF_e24vh_medium1_EFxe40", &master ),
        EF_e24vh_medium1_IDTrkNoCut( this, ::TString( prefix ) + "EF_e24vh_medium1_IDTrkNoCut", &master ),
        EF_e24vh_medium1_IdScan( this, ::TString( prefix ) + "EF_e24vh_medium1_IdScan", &master ),
        EF_e24vh_medium1_L2StarB( this, ::TString( prefix ) + "EF_e24vh_medium1_L2StarB", &master ),
        EF_e24vh_medium1_L2StarC( this, ::TString( prefix ) + "EF_e24vh_medium1_L2StarC", &master ),
        EF_e24vh_medium1_SiTrk( this, ::TString( prefix ) + "EF_e24vh_medium1_SiTrk", &master ),
        EF_e24vh_medium1_TRT( this, ::TString( prefix ) + "EF_e24vh_medium1_TRT", &master ),
        EF_e24vh_medium1_b35_mediumEF_j35_a4tchad( this, ::TString( prefix ) + "EF_e24vh_medium1_b35_mediumEF_j35_a4tchad", &master ),
        EF_e24vh_medium1_e7_medium1( this, ::TString( prefix ) + "EF_e24vh_medium1_e7_medium1", &master ),
        EF_e24vh_tight1_e15_NoCut_Zee( this, ::TString( prefix ) + "EF_e24vh_tight1_e15_NoCut_Zee", &master ),
        EF_e24vhi_loose1_mu8( this, ::TString( prefix ) + "EF_e24vhi_loose1_mu8", &master ),
        EF_e24vhi_medium1( this, ::TString( prefix ) + "EF_e24vhi_medium1", &master ),
        EF_e45_medium1( this, ::TString( prefix ) + "EF_e45_medium1", &master ),
        EF_e5_tight1( this, ::TString( prefix ) + "EF_e5_tight1", &master ),
// -- slimmed --         EF_e5_tight1_e14_etcut_Jpsi( this, ::TString( prefix ) + "EF_e5_tight1_e14_etcut_Jpsi", &master ),
// -- slimmed --         EF_e5_tight1_e4_etcut_Jpsi( this, ::TString( prefix ) + "EF_e5_tight1_e4_etcut_Jpsi", &master ),
// -- slimmed --         EF_e5_tight1_e4_etcut_Jpsi_L2StarB( this, ::TString( prefix ) + "EF_e5_tight1_e4_etcut_Jpsi_L2StarB", &master ),
// -- slimmed --         EF_e5_tight1_e4_etcut_Jpsi_L2StarC( this, ::TString( prefix ) + "EF_e5_tight1_e4_etcut_Jpsi_L2StarC", &master ),
        EF_e5_tight1_e5_NoCut( this, ::TString( prefix ) + "EF_e5_tight1_e5_NoCut", &master ),
// -- slimmed --         EF_e5_tight1_e9_etcut_Jpsi( this, ::TString( prefix ) + "EF_e5_tight1_e9_etcut_Jpsi", &master ),
        EF_e60_medium1( this, ::TString( prefix ) + "EF_e60_medium1", &master ),
        EF_e7T_loose1( this, ::TString( prefix ) + "EF_e7T_loose1", &master ),
        EF_e7T_loose1_2mu6( this, ::TString( prefix ) + "EF_e7T_loose1_2mu6", &master ),
        EF_e7T_medium1( this, ::TString( prefix ) + "EF_e7T_medium1", &master ),
        EF_e7T_medium1_2mu6( this, ::TString( prefix ) + "EF_e7T_medium1_2mu6", &master ),
// -- slimmed --         EF_e9_tight1_e4_etcut_Jpsi( this, ::TString( prefix ) + "EF_e9_tight1_e4_etcut_Jpsi", &master ),
        EF_eb_physics( this, ::TString( prefix ) + "EF_eb_physics", &master ),
        EF_eb_physics_empty( this, ::TString( prefix ) + "EF_eb_physics_empty", &master ),
        EF_eb_physics_firstempty( this, ::TString( prefix ) + "EF_eb_physics_firstempty", &master ),
        EF_eb_physics_noL1PS( this, ::TString( prefix ) + "EF_eb_physics_noL1PS", &master ),
        EF_eb_physics_unpaired_iso( this, ::TString( prefix ) + "EF_eb_physics_unpaired_iso", &master ),
        EF_eb_physics_unpaired_noniso( this, ::TString( prefix ) + "EF_eb_physics_unpaired_noniso", &master ),
        EF_eb_random( this, ::TString( prefix ) + "EF_eb_random", &master ),
        EF_eb_random_empty( this, ::TString( prefix ) + "EF_eb_random_empty", &master ),
        EF_eb_random_firstempty( this, ::TString( prefix ) + "EF_eb_random_firstempty", &master ),
        EF_eb_random_unpaired_iso( this, ::TString( prefix ) + "EF_eb_random_unpaired_iso", &master ),
// -- slimmed --         EF_g100_loose( this, ::TString( prefix ) + "EF_g100_loose", &master ),
// -- slimmed --         EF_g10_NoCut_cosmic( this, ::TString( prefix ) + "EF_g10_NoCut_cosmic", &master ),
// -- slimmed --         EF_g10_loose( this, ::TString( prefix ) + "EF_g10_loose", &master ),
// -- slimmed --         EF_g10_medium( this, ::TString( prefix ) + "EF_g10_medium", &master ),
// -- slimmed --         EF_g120_loose( this, ::TString( prefix ) + "EF_g120_loose", &master ),
// -- slimmed --         EF_g12Tvh_loose( this, ::TString( prefix ) + "EF_g12Tvh_loose", &master ),
// -- slimmed --         EF_g12Tvh_loose_larcalib( this, ::TString( prefix ) + "EF_g12Tvh_loose_larcalib", &master ),
// -- slimmed --         EF_g15_loose( this, ::TString( prefix ) + "EF_g15_loose", &master ),
// -- slimmed --         EF_g15vh_medium( this, ::TString( prefix ) + "EF_g15vh_medium", &master ),
// -- slimmed --         EF_g200_etcut( this, ::TString( prefix ) + "EF_g200_etcut", &master ),
// -- slimmed --         EF_g20_etcut( this, ::TString( prefix ) + "EF_g20_etcut", &master ),
// -- slimmed --         EF_g20_loose( this, ::TString( prefix ) + "EF_g20_loose", &master ),
// -- slimmed --         EF_g20_loose_larcalib( this, ::TString( prefix ) + "EF_g20_loose_larcalib", &master ),
// -- slimmed --         EF_g20_medium( this, ::TString( prefix ) + "EF_g20_medium", &master ),
// -- slimmed --         EF_g30_loose_g20_loose( this, ::TString( prefix ) + "EF_g30_loose_g20_loose", &master ),
// -- slimmed --         EF_g30_medium_g20_medium( this, ::TString( prefix ) + "EF_g30_medium_g20_medium", &master ),
// -- slimmed --         EF_g35_loose_g25_loose( this, ::TString( prefix ) + "EF_g35_loose_g25_loose", &master ),
// -- slimmed --         EF_g35_loose_g30_loose( this, ::TString( prefix ) + "EF_g35_loose_g30_loose", &master ),
// -- slimmed --         EF_g40_loose( this, ::TString( prefix ) + "EF_g40_loose", &master ),
// -- slimmed --         EF_g40_loose_L2EFxe60( this, ::TString( prefix ) + "EF_g40_loose_L2EFxe60", &master ),
// -- slimmed --         EF_g40_loose_L2EFxe60_tclcw( this, ::TString( prefix ) + "EF_g40_loose_L2EFxe60_tclcw", &master ),
// -- slimmed --         EF_g40_loose_g25_loose( this, ::TString( prefix ) + "EF_g40_loose_g25_loose", &master ),
// -- slimmed --         EF_g40_loose_g30_loose( this, ::TString( prefix ) + "EF_g40_loose_g30_loose", &master ),
// -- slimmed --         EF_g40_loose_larcalib( this, ::TString( prefix ) + "EF_g40_loose_larcalib", &master ),
// -- slimmed --         EF_g5_NoCut_cosmic( this, ::TString( prefix ) + "EF_g5_NoCut_cosmic", &master ),
// -- slimmed --         EF_g60_loose( this, ::TString( prefix ) + "EF_g60_loose", &master ),
// -- slimmed --         EF_g60_loose_larcalib( this, ::TString( prefix ) + "EF_g60_loose_larcalib", &master ),
// -- slimmed --         EF_g80_loose( this, ::TString( prefix ) + "EF_g80_loose", &master ),
// -- slimmed --         EF_g80_loose_larcalib( this, ::TString( prefix ) + "EF_g80_loose_larcalib", &master ),
        EF_mu10( this, ::TString( prefix ) + "EF_mu10", &master ),
// -- slimmed --         EF_mu10_Jpsimumu( this, ::TString( prefix ) + "EF_mu10_Jpsimumu", &master ),
        EF_mu10_MSonly( this, ::TString( prefix ) + "EF_mu10_MSonly", &master ),
// -- slimmed --         EF_mu10_Upsimumu_tight_FS( this, ::TString( prefix ) + "EF_mu10_Upsimumu_tight_FS", &master ),
// -- slimmed --         EF_mu10i_g10_medium( this, ::TString( prefix ) + "EF_mu10i_g10_medium", &master ),
// -- slimmed --         EF_mu10i_g10_medium_TauMass( this, ::TString( prefix ) + "EF_mu10i_g10_medium_TauMass", &master ),
// -- slimmed --         EF_mu10i_loose_g12Tvh_medium( this, ::TString( prefix ) + "EF_mu10i_loose_g12Tvh_medium", &master ),
// -- slimmed --         EF_mu10i_loose_g12Tvh_medium_TauMass( this, ::TString( prefix ) + "EF_mu10i_loose_g12Tvh_medium_TauMass", &master ),
        EF_mu11_empty_NoAlg( this, ::TString( prefix ) + "EF_mu11_empty_NoAlg", &master ),
        EF_mu13( this, ::TString( prefix ) + "EF_mu13", &master ),
        EF_mu15( this, ::TString( prefix ) + "EF_mu15", &master ),
        EF_mu18( this, ::TString( prefix ) + "EF_mu18", &master ),
// -- slimmed --         EF_mu18_2g10_loose( this, ::TString( prefix ) + "EF_mu18_2g10_loose", &master ),
// -- slimmed --         EF_mu18_2g10_medium( this, ::TString( prefix ) + "EF_mu18_2g10_medium", &master ),
        EF_mu18_IDTrkNoCut_tight( this, ::TString( prefix ) + "EF_mu18_IDTrkNoCut_tight", &master ),
        EF_mu18_medium( this, ::TString( prefix ) + "EF_mu18_medium", &master ),
        EF_mu18_tight( this, ::TString( prefix ) + "EF_mu18_tight", &master ),
        EF_mu18_tight_2mu4_EFFS( this, ::TString( prefix ) + "EF_mu18_tight_2mu4_EFFS", &master ),
        EF_mu18_tight_e7_medium1( this, ::TString( prefix ) + "EF_mu18_tight_e7_medium1", &master ),
        EF_mu18_tight_mu8_EFFS( this, ::TString( prefix ) + "EF_mu18_tight_mu8_EFFS", &master ),
        EF_mu18i4_tight( this, ::TString( prefix ) + "EF_mu18i4_tight", &master ),
// -- slimmed --         EF_mu20i_tight_g5_loose_TauMass( this, ::TString( prefix ) + "EF_mu20i_tight_g5_loose_TauMass", &master ),
// -- slimmed --         EF_mu20i_tight_g5_medium( this, ::TString( prefix ) + "EF_mu20i_tight_g5_medium", &master ),
// -- slimmed --         EF_mu20i_tight_g5_medium_TauMass( this, ::TString( prefix ) + "EF_mu20i_tight_g5_medium_TauMass", &master ),
        EF_mu20it_tight( this, ::TString( prefix ) + "EF_mu20it_tight", &master ),
        EF_mu22_IDTrkNoCut_tight( this, ::TString( prefix ) + "EF_mu22_IDTrkNoCut_tight", &master ),
        EF_mu24( this, ::TString( prefix ) + "EF_mu24", &master ),
// -- slimmed --         EF_mu24_g20vh_loose( this, ::TString( prefix ) + "EF_mu24_g20vh_loose", &master ),
// -- slimmed --         EF_mu24_g20vh_medium( this, ::TString( prefix ) + "EF_mu24_g20vh_medium", &master ),
        EF_mu24_j65_a4tchad( this, ::TString( prefix ) + "EF_mu24_j65_a4tchad", &master ),
        EF_mu24_j65_a4tchad_EFxe40( this, ::TString( prefix ) + "EF_mu24_j65_a4tchad_EFxe40", &master ),
        EF_mu24_j65_a4tchad_EFxe40_tclcw( this, ::TString( prefix ) + "EF_mu24_j65_a4tchad_EFxe40_tclcw", &master ),
        EF_mu24_j65_a4tchad_EFxe60_tclcw( this, ::TString( prefix ) + "EF_mu24_j65_a4tchad_EFxe60_tclcw", &master ),
        EF_mu24_medium( this, ::TString( prefix ) + "EF_mu24_medium", &master ),
        EF_mu24_muCombTag_NoEF_tight( this, ::TString( prefix ) + "EF_mu24_muCombTag_NoEF_tight", &master ),
        EF_mu24_tight( this, ::TString( prefix ) + "EF_mu24_tight", &master ),
        EF_mu24_tight_3j35_a4tchad( this, ::TString( prefix ) + "EF_mu24_tight_3j35_a4tchad", &master ),
        EF_mu24_tight_EFxe40( this, ::TString( prefix ) + "EF_mu24_tight_EFxe40", &master ),
        EF_mu24_tight_L2StarB( this, ::TString( prefix ) + "EF_mu24_tight_L2StarB", &master ),
        EF_mu24_tight_L2StarC( this, ::TString( prefix ) + "EF_mu24_tight_L2StarC", &master ),
        EF_mu24_tight_MG( this, ::TString( prefix ) + "EF_mu24_tight_MG", &master ),
        EF_mu24_tight_MuonEF( this, ::TString( prefix ) + "EF_mu24_tight_MuonEF", &master ),
        EF_mu24_tight_b35_mediumEF_j35_a4tchad( this, ::TString( prefix ) + "EF_mu24_tight_b35_mediumEF_j35_a4tchad", &master ),
        EF_mu24_tight_mu6_EFFS( this, ::TString( prefix ) + "EF_mu24_tight_mu6_EFFS", &master ),
        EF_mu24i_tight( this, ::TString( prefix ) + "EF_mu24i_tight", &master ),
        EF_mu24i_tight_MG( this, ::TString( prefix ) + "EF_mu24i_tight_MG", &master ),
        EF_mu24i_tight_MuonEF( this, ::TString( prefix ) + "EF_mu24i_tight_MuonEF", &master ),
        EF_mu24i_tight_l2muonSA( this, ::TString( prefix ) + "EF_mu24i_tight_l2muonSA", &master ),
        EF_mu36_tight( this, ::TString( prefix ) + "EF_mu36_tight", &master ),
        EF_mu40_MSonly_barrel_tight( this, ::TString( prefix ) + "EF_mu40_MSonly_barrel_tight", &master ),
        EF_mu40_muCombTag_NoEF( this, ::TString( prefix ) + "EF_mu40_muCombTag_NoEF", &master ),
        EF_mu40_slow_outOfTime_tight( this, ::TString( prefix ) + "EF_mu40_slow_outOfTime_tight", &master ),
        EF_mu40_slow_tight( this, ::TString( prefix ) + "EF_mu40_slow_tight", &master ),
        EF_mu40_tight( this, ::TString( prefix ) + "EF_mu40_tight", &master ),
        EF_mu4T( this, ::TString( prefix ) + "EF_mu4T", &master ),
        EF_mu4T_cosmic( this, ::TString( prefix ) + "EF_mu4T_cosmic", &master ),
        EF_mu4T_j110_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j110_a4tchad_L2FS_matched", &master ),
        EF_mu4T_j110_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j110_a4tchad_matched", &master ),
        EF_mu4T_j145_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j145_a4tchad_L2FS_matched", &master ),
        EF_mu4T_j145_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j145_a4tchad_matched", &master ),
        EF_mu4T_j15_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j15_a4tchad_matched", &master ),
        EF_mu4T_j15_a4tchad_matchedZ( this, ::TString( prefix ) + "EF_mu4T_j15_a4tchad_matchedZ", &master ),
        EF_mu4T_j180_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j180_a4tchad_L2FS_matched", &master ),
        EF_mu4T_j180_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j180_a4tchad_matched", &master ),
        EF_mu4T_j220_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j220_a4tchad_L2FS_matched", &master ),
        EF_mu4T_j220_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j220_a4tchad_matched", &master ),
        EF_mu4T_j25_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j25_a4tchad_matched", &master ),
        EF_mu4T_j25_a4tchad_matchedZ( this, ::TString( prefix ) + "EF_mu4T_j25_a4tchad_matchedZ", &master ),
        EF_mu4T_j280_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j280_a4tchad_L2FS_matched", &master ),
        EF_mu4T_j280_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j280_a4tchad_matched", &master ),
        EF_mu4T_j35_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j35_a4tchad_matched", &master ),
        EF_mu4T_j35_a4tchad_matchedZ( this, ::TString( prefix ) + "EF_mu4T_j35_a4tchad_matchedZ", &master ),
        EF_mu4T_j45_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j45_a4tchad_L2FS_matched", &master ),
        EF_mu4T_j45_a4tchad_L2FS_matchedZ( this, ::TString( prefix ) + "EF_mu4T_j45_a4tchad_L2FS_matchedZ", &master ),
        EF_mu4T_j45_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j45_a4tchad_matched", &master ),
        EF_mu4T_j45_a4tchad_matchedZ( this, ::TString( prefix ) + "EF_mu4T_j45_a4tchad_matchedZ", &master ),
        EF_mu4T_j55_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j55_a4tchad_L2FS_matched", &master ),
        EF_mu4T_j55_a4tchad_L2FS_matchedZ( this, ::TString( prefix ) + "EF_mu4T_j55_a4tchad_L2FS_matchedZ", &master ),
        EF_mu4T_j55_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j55_a4tchad_matched", &master ),
        EF_mu4T_j55_a4tchad_matchedZ( this, ::TString( prefix ) + "EF_mu4T_j55_a4tchad_matchedZ", &master ),
        EF_mu4T_j65_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j65_a4tchad_L2FS_matched", &master ),
        EF_mu4T_j65_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j65_a4tchad_matched", &master ),
        EF_mu4T_j65_a4tchad_xe60_tclcw_loose( this, ::TString( prefix ) + "EF_mu4T_j65_a4tchad_xe60_tclcw_loose", &master ),
        EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose( this, ::TString( prefix ) + "EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose", &master ),
        EF_mu4T_j80_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j80_a4tchad_L2FS_matched", &master ),
        EF_mu4T_j80_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j80_a4tchad_matched", &master ),
// -- slimmed --         EF_mu4Ti_g20Tvh_medium( this, ::TString( prefix ) + "EF_mu4Ti_g20Tvh_medium", &master ),
// -- slimmed --         EF_mu4Ti_g20Tvh_medium_TauMass( this, ::TString( prefix ) + "EF_mu4Ti_g20Tvh_medium_TauMass", &master ),
        EF_mu4Tmu6_Bmumu( this, ::TString( prefix ) + "EF_mu4Tmu6_Bmumu", &master ),
        EF_mu4Tmu6_Bmumu_Barrel( this, ::TString( prefix ) + "EF_mu4Tmu6_Bmumu_Barrel", &master ),
        EF_mu4Tmu6_Bmumux( this, ::TString( prefix ) + "EF_mu4Tmu6_Bmumux", &master ),
        EF_mu4Tmu6_Bmumux_Barrel( this, ::TString( prefix ) + "EF_mu4Tmu6_Bmumux_Barrel", &master ),
        EF_mu4Tmu6_DiMu( this, ::TString( prefix ) + "EF_mu4Tmu6_DiMu", &master ),
        EF_mu4Tmu6_DiMu_Barrel( this, ::TString( prefix ) + "EF_mu4Tmu6_DiMu_Barrel", &master ),
        EF_mu4Tmu6_DiMu_noVtx_noOS( this, ::TString( prefix ) + "EF_mu4Tmu6_DiMu_noVtx_noOS", &master ),
// -- slimmed --         EF_mu4Tmu6_Jpsimumu( this, ::TString( prefix ) + "EF_mu4Tmu6_Jpsimumu", &master ),
// -- slimmed --         EF_mu4Tmu6_Jpsimumu_Barrel( this, ::TString( prefix ) + "EF_mu4Tmu6_Jpsimumu_Barrel", &master ),
// -- slimmed --         EF_mu4Tmu6_Jpsimumu_IDTrkNoCut( this, ::TString( prefix ) + "EF_mu4Tmu6_Jpsimumu_IDTrkNoCut", &master ),
// -- slimmed --         EF_mu4Tmu6_Upsimumu( this, ::TString( prefix ) + "EF_mu4Tmu6_Upsimumu", &master ),
// -- slimmed --         EF_mu4Tmu6_Upsimumu_Barrel( this, ::TString( prefix ) + "EF_mu4Tmu6_Upsimumu_Barrel", &master ),
        EF_mu4_L1MU11_MSonly_cosmic( this, ::TString( prefix ) + "EF_mu4_L1MU11_MSonly_cosmic", &master ),
        EF_mu4_L1MU11_cosmic( this, ::TString( prefix ) + "EF_mu4_L1MU11_cosmic", &master ),
        EF_mu4_empty_NoAlg( this, ::TString( prefix ) + "EF_mu4_empty_NoAlg", &master ),
        EF_mu4_firstempty_NoAlg( this, ::TString( prefix ) + "EF_mu4_firstempty_NoAlg", &master ),
        EF_mu4_unpaired_iso_NoAlg( this, ::TString( prefix ) + "EF_mu4_unpaired_iso_NoAlg", &master ),
        EF_mu50_MSonly_barrel_tight( this, ::TString( prefix ) + "EF_mu50_MSonly_barrel_tight", &master ),
        EF_mu6( this, ::TString( prefix ) + "EF_mu6", &master ),
        EF_mu60_slow_outOfTime_tight1( this, ::TString( prefix ) + "EF_mu60_slow_outOfTime_tight1", &master ),
        EF_mu60_slow_tight1( this, ::TString( prefix ) + "EF_mu60_slow_tight1", &master ),
// -- slimmed --         EF_mu6_Jpsimumu_tight( this, ::TString( prefix ) + "EF_mu6_Jpsimumu_tight", &master ),
        EF_mu6_MSonly( this, ::TString( prefix ) + "EF_mu6_MSonly", &master ),
// -- slimmed --         EF_mu6_Trk_Jpsi_loose( this, ::TString( prefix ) + "EF_mu6_Trk_Jpsi_loose", &master ),
        EF_mu8( this, ::TString( prefix ) + "EF_mu8", &master ),
        EF_mu8_4j45_a4tchad_L2FS( this, ::TString( prefix ) + "EF_mu8_4j45_a4tchad_L2FS", &master ),
        // =============================================================================
        // = from MC D3PD
        // =============================================================================
// -- slimmed --         EF_2g15vh_loose_g10_loose( this, ::TString( prefix ) + "EF_2g15vh_loose_g10_loose", &master ),
// -- slimmed --         EF_2g15vh_medium( this, ::TString( prefix ) + "EF_2g15vh_medium", &master ),
// -- slimmed --         EF_2g20_loose( this, ::TString( prefix ) + "EF_2g20_loose", &master ),
// -- slimmed --         EF_2g30_loose( this, ::TString( prefix ) + "EF_2g30_loose", &master ),
// -- slimmed --         EF_2mu10_MSonly_g10_loose_EMPTY( this, ::TString( prefix ) + "EF_2mu10_MSonly_g10_loose_EMPTY", &master ),
// -- slimmed --         EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO( this, ::TString( prefix ) + "EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO", &master ),
        EF_2mu4T_xe50_tclcw( this, ::TString( prefix ) + "EF_2mu4T_xe50_tclcw", &master ),
        EF_e12Tvh_loose1_mu8( this, ::TString( prefix ) + "EF_e12Tvh_loose1_mu8", &master ),
        EF_e12Tvh_medium1_mu10( this, ::TString( prefix ) + "EF_e12Tvh_medium1_mu10", &master ),
        EF_e12Tvh_medium1_mu6( this, ::TString( prefix ) + "EF_e12Tvh_medium1_mu6", &master ),
// -- slimmed --         EF_e18_loose1_g35_loose( this, ::TString( prefix ) + "EF_e18_loose1_g35_loose", &master ),
// -- slimmed --         EF_e18_loose1_g35_medium( this, ::TString( prefix ) + "EF_e18_loose1_g35_medium", &master ),
// -- slimmed --         EF_e18_medium1_g25_medium( this, ::TString( prefix ) + "EF_e18_medium1_g25_medium", &master ),
// -- slimmed --         EF_e18_medium1_g35_loose( this, ::TString( prefix ) + "EF_e18_medium1_g35_loose", &master ),
// -- slimmed --         EF_e18_medium1_g35_medium( this, ::TString( prefix ) + "EF_e18_medium1_g35_medium", &master ),
        EF_e22vh_medium1_IdScan( this, ::TString( prefix ) + "EF_e22vh_medium1_IdScan", &master ),
        EF_e22vh_medium1_SiTrk( this, ::TString( prefix ) + "EF_e22vh_medium1_SiTrk", &master ),
        EF_e22vh_medium1_TRT( this, ::TString( prefix ) + "EF_e22vh_medium1_TRT", &master ),
        EF_e45_etcut( this, ::TString( prefix ) + "EF_e45_etcut", &master ),
// -- slimmed --         EF_e5_tight1_e4_etcut_Jpsi_IdScan( this, ::TString( prefix ) + "EF_e5_tight1_e4_etcut_Jpsi_IdScan", &master ),
// -- slimmed --         EF_e5_tight1_e4_etcut_Jpsi_SiTrk( this, ::TString( prefix ) + "EF_e5_tight1_e4_etcut_Jpsi_SiTrk", &master ),
// -- slimmed --         EF_e5_tight1_e4_etcut_Jpsi_TRT( this, ::TString( prefix ) + "EF_e5_tight1_e4_etcut_Jpsi_TRT", &master ),
        EF_e60_etcut( this, ::TString( prefix ) + "EF_e60_etcut", &master ),
// -- slimmed --         EF_g12Tvh_medium( this, ::TString( prefix ) + "EF_g12Tvh_medium", &master ),
// -- slimmed --         EF_g15vh_loose( this, ::TString( prefix ) + "EF_g15vh_loose", &master ),
// -- slimmed --         EF_g20Tvh_medium( this, ::TString( prefix ) + "EF_g20Tvh_medium", &master ),
// -- slimmed --         EF_g20vh_medium( this, ::TString( prefix ) + "EF_g20vh_medium", &master ),
// -- slimmed --         EF_g40_loose_EFxe50( this, ::TString( prefix ) + "EF_g40_loose_EFxe50", &master ),
// -- slimmed --         EF_g40_loose_L2EFxe50( this, ::TString( prefix ) + "EF_g40_loose_L2EFxe50", &master ),
// -- slimmed --         EF_mu10i_g10_loose( this, ::TString( prefix ) + "EF_mu10i_g10_loose", &master ),
// -- slimmed --         EF_mu10i_g10_loose_TauMass( this, ::TString( prefix ) + "EF_mu10i_g10_loose_TauMass", &master ),
// -- slimmed --         EF_mu10i_loose_g12Tvh_loose( this, ::TString( prefix ) + "EF_mu10i_loose_g12Tvh_loose", &master ),
// -- slimmed --         EF_mu10i_loose_g12Tvh_loose_TauMass( this, ::TString( prefix ) + "EF_mu10i_loose_g12Tvh_loose_TauMass", &master ),
// -- slimmed --         EF_mu18_2g15_loose( this, ::TString( prefix ) + "EF_mu18_2g15_loose", &master ),
// -- slimmed --         EF_mu18_g20vh_loose( this, ::TString( prefix ) + "EF_mu18_g20vh_loose", &master ),
        EF_mu18it_tight( this, ::TString( prefix ) + "EF_mu18it_tight", &master ),
// -- slimmed --         EF_mu20i_tight_g5_loose( this, ::TString( prefix ) + "EF_mu20i_tight_g5_loose", &master ),
        EF_mu24_j65_a4tchad_EFxe50_tclcw( this, ::TString( prefix ) + "EF_mu24_j65_a4tchad_EFxe50_tclcw", &master ),
        EF_mu24_tight_2j35_a4tchad( this, ::TString( prefix ) + "EF_mu24_tight_2j35_a4tchad", &master ),
        EF_mu24_tight_4j35_a4tchad( this, ::TString( prefix ) + "EF_mu24_tight_4j35_a4tchad", &master ),
// -- slimmed --         EF_mu4T_Trk_Jpsi( this, ::TString( prefix ) + "EF_mu4T_Trk_Jpsi", &master ),
        EF_mu4T_j360_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j360_a4tchad_L2FS_matched", &master ),
        EF_mu4T_j360_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j360_a4tchad_matched", &master ),
// -- slimmed --         EF_mu4Ti_g20Tvh_loose( this, ::TString( prefix ) + "EF_mu4Ti_g20Tvh_loose", &master ),
// -- slimmed --         EF_mu4Ti_g20Tvh_loose_TauMass( this, ::TString( prefix ) + "EF_mu4Ti_g20Tvh_loose_TauMass", &master ),
        EF_mu6i( this, ::TString( prefix ) + "EF_mu6i", &master ),
        
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) {

      fHandles[ "EF_2e12Tvh_loose1" ] = &EF_2e12Tvh_loose1;
// -- slimmed --       fHandles[ "EF_2e5_tight1_Jpsi" ] = &EF_2e5_tight1_Jpsi;
      fHandles[ "EF_2e7T_loose1_mu6" ] = &EF_2e7T_loose1_mu6;
      fHandles[ "EF_2e7T_medium1_mu6" ] = &EF_2e7T_medium1_mu6;
// -- slimmed --       fHandles[ "EF_2g15vh_medium_g10_medium" ] = &EF_2g15vh_medium_g10_medium;
// -- slimmed --       fHandles[ "EF_2g20vh_medium" ] = &EF_2g20vh_medium;
// -- slimmed --       fHandles[ "EF_2g40_loose" ] = &EF_2g40_loose;
      fHandles[ "EF_2mu10" ] = &EF_2mu10;
// -- slimmed --       fHandles[ "EF_2mu10_MSonly_g10_loose" ] = &EF_2mu10_MSonly_g10_loose;
      fHandles[ "EF_2mu13" ] = &EF_2mu13;
      fHandles[ "EF_2mu13_Zmumu_IDTrkNoCut" ] = &EF_2mu13_Zmumu_IDTrkNoCut;
      fHandles[ "EF_2mu13_l2muonSA" ] = &EF_2mu13_l2muonSA;
      fHandles[ "EF_2mu15" ] = &EF_2mu15;
      fHandles[ "EF_2mu4T" ] = &EF_2mu4T;
      fHandles[ "EF_2mu4T_2e5_tight1" ] = &EF_2mu4T_2e5_tight1;
      fHandles[ "EF_2mu4T_Bmumu" ] = &EF_2mu4T_Bmumu;
      fHandles[ "EF_2mu4T_Bmumu_Barrel" ] = &EF_2mu4T_Bmumu_Barrel;
      fHandles[ "EF_2mu4T_Bmumu_BarrelOnly" ] = &EF_2mu4T_Bmumu_BarrelOnly;
      fHandles[ "EF_2mu4T_Bmumux" ] = &EF_2mu4T_Bmumux;
      fHandles[ "EF_2mu4T_Bmumux_Barrel" ] = &EF_2mu4T_Bmumux_Barrel;
      fHandles[ "EF_2mu4T_Bmumux_BarrelOnly" ] = &EF_2mu4T_Bmumux_BarrelOnly;
      fHandles[ "EF_2mu4T_DiMu" ] = &EF_2mu4T_DiMu;
      fHandles[ "EF_2mu4T_DiMu_Barrel" ] = &EF_2mu4T_DiMu_Barrel;
      fHandles[ "EF_2mu4T_DiMu_BarrelOnly" ] = &EF_2mu4T_DiMu_BarrelOnly;
      fHandles[ "EF_2mu4T_DiMu_L2StarB" ] = &EF_2mu4T_DiMu_L2StarB;
      fHandles[ "EF_2mu4T_DiMu_L2StarC" ] = &EF_2mu4T_DiMu_L2StarC;
      fHandles[ "EF_2mu4T_DiMu_e5_tight1" ] = &EF_2mu4T_DiMu_e5_tight1;
      fHandles[ "EF_2mu4T_DiMu_l2muonSA" ] = &EF_2mu4T_DiMu_l2muonSA;
      fHandles[ "EF_2mu4T_DiMu_noVtx_noOS" ] = &EF_2mu4T_DiMu_noVtx_noOS;
// -- slimmed --       fHandles[ "EF_2mu4T_Jpsimumu" ] = &EF_2mu4T_Jpsimumu;
// -- slimmed --       fHandles[ "EF_2mu4T_Jpsimumu_Barrel" ] = &EF_2mu4T_Jpsimumu_Barrel;
// -- slimmed --       fHandles[ "EF_2mu4T_Jpsimumu_BarrelOnly" ] = &EF_2mu4T_Jpsimumu_BarrelOnly;
// -- slimmed --       fHandles[ "EF_2mu4T_Jpsimumu_IDTrkNoCut" ] = &EF_2mu4T_Jpsimumu_IDTrkNoCut;
// -- slimmed --       fHandles[ "EF_2mu4T_Upsimumu" ] = &EF_2mu4T_Upsimumu;
// -- slimmed --       fHandles[ "EF_2mu4T_Upsimumu_Barrel" ] = &EF_2mu4T_Upsimumu_Barrel;
// -- slimmed --       fHandles[ "EF_2mu4T_Upsimumu_BarrelOnly" ] = &EF_2mu4T_Upsimumu_BarrelOnly;
      fHandles[ "EF_2mu4T_xe60" ] = &EF_2mu4T_xe60;
      fHandles[ "EF_2mu4T_xe60_tclcw" ] = &EF_2mu4T_xe60_tclcw;
      fHandles[ "EF_2mu6" ] = &EF_2mu6;
      fHandles[ "EF_2mu6_Bmumu" ] = &EF_2mu6_Bmumu;
      fHandles[ "EF_2mu6_Bmumux" ] = &EF_2mu6_Bmumux;
      fHandles[ "EF_2mu6_DiMu" ] = &EF_2mu6_DiMu;
      fHandles[ "EF_2mu6_DiMu_DY20" ] = &EF_2mu6_DiMu_DY20;
      fHandles[ "EF_2mu6_DiMu_DY25" ] = &EF_2mu6_DiMu_DY25;
      fHandles[ "EF_2mu6_DiMu_noVtx_noOS" ] = &EF_2mu6_DiMu_noVtx_noOS;
// -- slimmed --       fHandles[ "EF_2mu6_Jpsimumu" ] = &EF_2mu6_Jpsimumu;
// -- slimmed --       fHandles[ "EF_2mu6_Upsimumu" ] = &EF_2mu6_Upsimumu;
      fHandles[ "EF_2mu6i_DiMu_DY" ] = &EF_2mu6i_DiMu_DY;
      fHandles[ "EF_2mu6i_DiMu_DY_2j25_a4tchad" ] = &EF_2mu6i_DiMu_DY_2j25_a4tchad;
      fHandles[ "EF_2mu6i_DiMu_DY_noVtx_noOS" ] = &EF_2mu6i_DiMu_DY_noVtx_noOS;
      fHandles[ "EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad" ] = &EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad;
      fHandles[ "EF_2mu8_EFxe30" ] = &EF_2mu8_EFxe30;
      fHandles[ "EF_2mu8_EFxe30_tclcw" ] = &EF_2mu8_EFxe30_tclcw;
      fHandles[ "EF_e11_etcut" ] = &EF_e11_etcut;
      fHandles[ "EF_e12Tvh_loose1" ] = &EF_e12Tvh_loose1;
      fHandles[ "EF_e12Tvh_medium1" ] = &EF_e12Tvh_medium1;
      fHandles[ "EF_e12Tvh_medium1_mu6_topo_medium" ] = &EF_e12Tvh_medium1_mu6_topo_medium;
      fHandles[ "EF_e12Tvh_medium1_mu8" ] = &EF_e12Tvh_medium1_mu8;
      fHandles[ "EF_e13_etcutTrk_xs60" ] = &EF_e13_etcutTrk_xs60;
      fHandles[ "EF_e13_etcutTrk_xs60_dphi2j15xe20" ] = &EF_e13_etcutTrk_xs60_dphi2j15xe20;
// -- slimmed --       fHandles[ "EF_e14_tight1_e4_etcut_Jpsi" ] = &EF_e14_tight1_e4_etcut_Jpsi;
      fHandles[ "EF_e15vh_medium1" ] = &EF_e15vh_medium1;
      fHandles[ "EF_e18_loose1" ] = &EF_e18_loose1;
// -- slimmed --       fHandles[ "EF_e18_loose1_g25_medium" ] = &EF_e18_loose1_g25_medium;
      fHandles[ "EF_e18_medium1" ] = &EF_e18_medium1;
// -- slimmed --       fHandles[ "EF_e18_medium1_g25_loose" ] = &EF_e18_medium1_g25_loose;
      fHandles[ "EF_e18vh_medium1" ] = &EF_e18vh_medium1;
      fHandles[ "EF_e18vh_medium1_2e7T_medium1" ] = &EF_e18vh_medium1_2e7T_medium1;
      fHandles[ "EF_e20_etcutTrk_xe30_dphi2j15xe20" ] = &EF_e20_etcutTrk_xe30_dphi2j15xe20;
      fHandles[ "EF_e20_etcutTrk_xs60_dphi2j15xe20" ] = &EF_e20_etcutTrk_xs60_dphi2j15xe20;
// -- slimmed -- // -- slimmed --       fHandles[ "EF_e20vhT_medium1_g6T_etcut_Upsi" ] = &EF_e20vhT_medium1_g6T_etcut_Upsi;
// -- slimmed -- // -- slimmed --       fHandles[ "EF_e20vhT_tight1_g6T_etcut_Upsi" ] = &EF_e20vhT_tight1_g6T_etcut_Upsi;
      fHandles[ "EF_e22vh_loose" ] = &EF_e22vh_loose;
      fHandles[ "EF_e22vh_loose0" ] = &EF_e22vh_loose0;
      fHandles[ "EF_e22vh_loose1" ] = &EF_e22vh_loose1;
      fHandles[ "EF_e22vh_medium1" ] = &EF_e22vh_medium1;
      fHandles[ "EF_e22vh_medium1_IDTrkNoCut" ] = &EF_e22vh_medium1_IDTrkNoCut;
      fHandles[ "EF_e22vhi_medium1" ] = &EF_e22vhi_medium1;
      fHandles[ "EF_e24vh_loose" ] = &EF_e24vh_loose;
      fHandles[ "EF_e24vh_loose0" ] = &EF_e24vh_loose0;
      fHandles[ "EF_e24vh_loose1" ] = &EF_e24vh_loose1;
      fHandles[ "EF_e24vh_medium1" ] = &EF_e24vh_medium1;
      fHandles[ "EF_e24vh_medium1_EFxe30" ] = &EF_e24vh_medium1_EFxe30;
      fHandles[ "EF_e24vh_medium1_EFxe30_tcem" ] = &EF_e24vh_medium1_EFxe30_tcem;
      fHandles[ "EF_e24vh_medium1_EFxe35_tcem" ] = &EF_e24vh_medium1_EFxe35_tcem;
      fHandles[ "EF_e24vh_medium1_EFxe35_tclcw" ] = &EF_e24vh_medium1_EFxe35_tclcw;
      fHandles[ "EF_e24vh_medium1_EFxe40" ] = &EF_e24vh_medium1_EFxe40;
      fHandles[ "EF_e24vh_medium1_IDTrkNoCut" ] = &EF_e24vh_medium1_IDTrkNoCut;
      fHandles[ "EF_e24vh_medium1_IdScan" ] = &EF_e24vh_medium1_IdScan;
      fHandles[ "EF_e24vh_medium1_L2StarB" ] = &EF_e24vh_medium1_L2StarB;
      fHandles[ "EF_e24vh_medium1_L2StarC" ] = &EF_e24vh_medium1_L2StarC;
      fHandles[ "EF_e24vh_medium1_SiTrk" ] = &EF_e24vh_medium1_SiTrk;
      fHandles[ "EF_e24vh_medium1_TRT" ] = &EF_e24vh_medium1_TRT;
      fHandles[ "EF_e24vh_medium1_b35_mediumEF_j35_a4tchad" ] = &EF_e24vh_medium1_b35_mediumEF_j35_a4tchad;
      fHandles[ "EF_e24vh_medium1_e7_medium1" ] = &EF_e24vh_medium1_e7_medium1;
      fHandles[ "EF_e24vh_tight1_e15_NoCut_Zee" ] = &EF_e24vh_tight1_e15_NoCut_Zee;
      fHandles[ "EF_e24vhi_loose1_mu8" ] = &EF_e24vhi_loose1_mu8;
      fHandles[ "EF_e24vhi_medium1" ] = &EF_e24vhi_medium1;
      fHandles[ "EF_e45_medium1" ] = &EF_e45_medium1;
      fHandles[ "EF_e5_tight1" ] = &EF_e5_tight1;
// -- slimmed --       fHandles[ "EF_e5_tight1_e14_etcut_Jpsi" ] = &EF_e5_tight1_e14_etcut_Jpsi;
// -- slimmed --       fHandles[ "EF_e5_tight1_e4_etcut_Jpsi" ] = &EF_e5_tight1_e4_etcut_Jpsi;
// -- slimmed --       fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_L2StarB" ] = &EF_e5_tight1_e4_etcut_Jpsi_L2StarB;
// -- slimmed --       fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_L2StarC" ] = &EF_e5_tight1_e4_etcut_Jpsi_L2StarC;
      fHandles[ "EF_e5_tight1_e5_NoCut" ] = &EF_e5_tight1_e5_NoCut;
// -- slimmed --       fHandles[ "EF_e5_tight1_e9_etcut_Jpsi" ] = &EF_e5_tight1_e9_etcut_Jpsi;
      fHandles[ "EF_e60_medium1" ] = &EF_e60_medium1;
      fHandles[ "EF_e7T_loose1" ] = &EF_e7T_loose1;
      fHandles[ "EF_e7T_loose1_2mu6" ] = &EF_e7T_loose1_2mu6;
      fHandles[ "EF_e7T_medium1" ] = &EF_e7T_medium1;
      fHandles[ "EF_e7T_medium1_2mu6" ] = &EF_e7T_medium1_2mu6;
// -- slimmed --       fHandles[ "EF_e9_tight1_e4_etcut_Jpsi" ] = &EF_e9_tight1_e4_etcut_Jpsi;
      fHandles[ "EF_eb_physics" ] = &EF_eb_physics;
      fHandles[ "EF_eb_physics_empty" ] = &EF_eb_physics_empty;
      fHandles[ "EF_eb_physics_firstempty" ] = &EF_eb_physics_firstempty;
      fHandles[ "EF_eb_physics_noL1PS" ] = &EF_eb_physics_noL1PS;
      fHandles[ "EF_eb_physics_unpaired_iso" ] = &EF_eb_physics_unpaired_iso;
      fHandles[ "EF_eb_physics_unpaired_noniso" ] = &EF_eb_physics_unpaired_noniso;
      fHandles[ "EF_eb_random" ] = &EF_eb_random;
      fHandles[ "EF_eb_random_empty" ] = &EF_eb_random_empty;
      fHandles[ "EF_eb_random_firstempty" ] = &EF_eb_random_firstempty;
      fHandles[ "EF_eb_random_unpaired_iso" ] = &EF_eb_random_unpaired_iso;
// -- slimmed --       fHandles[ "EF_g100_loose" ] = &EF_g100_loose;
// -- slimmed --       fHandles[ "EF_g10_NoCut_cosmic" ] = &EF_g10_NoCut_cosmic;
// -- slimmed --       fHandles[ "EF_g10_loose" ] = &EF_g10_loose;
// -- slimmed --       fHandles[ "EF_g10_medium" ] = &EF_g10_medium;
// -- slimmed --       fHandles[ "EF_g120_loose" ] = &EF_g120_loose;
// -- slimmed --       fHandles[ "EF_g12Tvh_loose" ] = &EF_g12Tvh_loose;
// -- slimmed --       fHandles[ "EF_g12Tvh_loose_larcalib" ] = &EF_g12Tvh_loose_larcalib;
// -- slimmed --       fHandles[ "EF_g15_loose" ] = &EF_g15_loose;
// -- slimmed --       fHandles[ "EF_g15vh_medium" ] = &EF_g15vh_medium;
// -- slimmed --       fHandles[ "EF_g200_etcut" ] = &EF_g200_etcut;
// -- slimmed --       fHandles[ "EF_g20_etcut" ] = &EF_g20_etcut;
// -- slimmed --       fHandles[ "EF_g20_loose" ] = &EF_g20_loose;
// -- slimmed --       fHandles[ "EF_g20_loose_larcalib" ] = &EF_g20_loose_larcalib;
// -- slimmed --       fHandles[ "EF_g20_medium" ] = &EF_g20_medium;
// -- slimmed --       fHandles[ "EF_g30_loose_g20_loose" ] = &EF_g30_loose_g20_loose;
// -- slimmed --       fHandles[ "EF_g30_medium_g20_medium" ] = &EF_g30_medium_g20_medium;
// -- slimmed --       fHandles[ "EF_g35_loose_g25_loose" ] = &EF_g35_loose_g25_loose;
// -- slimmed --       fHandles[ "EF_g35_loose_g30_loose" ] = &EF_g35_loose_g30_loose;
// -- slimmed --       fHandles[ "EF_g40_loose" ] = &EF_g40_loose;
// -- slimmed --       fHandles[ "EF_g40_loose_L2EFxe60" ] = &EF_g40_loose_L2EFxe60;
// -- slimmed --       fHandles[ "EF_g40_loose_L2EFxe60_tclcw" ] = &EF_g40_loose_L2EFxe60_tclcw;
// -- slimmed --       fHandles[ "EF_g40_loose_g25_loose" ] = &EF_g40_loose_g25_loose;
// -- slimmed --       fHandles[ "EF_g40_loose_g30_loose" ] = &EF_g40_loose_g30_loose;
// -- slimmed --       fHandles[ "EF_g40_loose_larcalib" ] = &EF_g40_loose_larcalib;
// -- slimmed --       fHandles[ "EF_g5_NoCut_cosmic" ] = &EF_g5_NoCut_cosmic;
// -- slimmed --       fHandles[ "EF_g60_loose" ] = &EF_g60_loose;
// -- slimmed --       fHandles[ "EF_g60_loose_larcalib" ] = &EF_g60_loose_larcalib;
// -- slimmed --       fHandles[ "EF_g80_loose" ] = &EF_g80_loose;
// -- slimmed --       fHandles[ "EF_g80_loose_larcalib" ] = &EF_g80_loose_larcalib;
      fHandles[ "EF_mu10" ] = &EF_mu10;
// -- slimmed --       fHandles[ "EF_mu10_Jpsimumu" ] = &EF_mu10_Jpsimumu;
      fHandles[ "EF_mu10_MSonly" ] = &EF_mu10_MSonly;
// -- slimmed --       fHandles[ "EF_mu10_Upsimumu_tight_FS" ] = &EF_mu10_Upsimumu_tight_FS;
// -- slimmed --       fHandles[ "EF_mu10i_g10_medium" ] = &EF_mu10i_g10_medium;
// -- slimmed --       fHandles[ "EF_mu10i_g10_medium_TauMass" ] = &EF_mu10i_g10_medium_TauMass;
// -- slimmed --       fHandles[ "EF_mu10i_loose_g12Tvh_medium" ] = &EF_mu10i_loose_g12Tvh_medium;
// -- slimmed --       fHandles[ "EF_mu10i_loose_g12Tvh_medium_TauMass" ] = &EF_mu10i_loose_g12Tvh_medium_TauMass;
      fHandles[ "EF_mu11_empty_NoAlg" ] = &EF_mu11_empty_NoAlg;
      fHandles[ "EF_mu13" ] = &EF_mu13;
      fHandles[ "EF_mu15" ] = &EF_mu15;
      fHandles[ "EF_mu18" ] = &EF_mu18;
// -- slimmed --       fHandles[ "EF_mu18_2g10_loose" ] = &EF_mu18_2g10_loose;
// -- slimmed --       fHandles[ "EF_mu18_2g10_medium" ] = &EF_mu18_2g10_medium;
      fHandles[ "EF_mu18_IDTrkNoCut_tight" ] = &EF_mu18_IDTrkNoCut_tight;
      fHandles[ "EF_mu18_medium" ] = &EF_mu18_medium;
      fHandles[ "EF_mu18_tight" ] = &EF_mu18_tight;
      fHandles[ "EF_mu18_tight_2mu4_EFFS" ] = &EF_mu18_tight_2mu4_EFFS;
      fHandles[ "EF_mu18_tight_e7_medium1" ] = &EF_mu18_tight_e7_medium1;
      fHandles[ "EF_mu18_tight_mu8_EFFS" ] = &EF_mu18_tight_mu8_EFFS;
      fHandles[ "EF_mu18i4_tight" ] = &EF_mu18i4_tight;
// -- slimmed --       fHandles[ "EF_mu20i_tight_g5_loose_TauMass" ] = &EF_mu20i_tight_g5_loose_TauMass;
// -- slimmed --       fHandles[ "EF_mu20i_tight_g5_medium" ] = &EF_mu20i_tight_g5_medium;
// -- slimmed --       fHandles[ "EF_mu20i_tight_g5_medium_TauMass" ] = &EF_mu20i_tight_g5_medium_TauMass;
      fHandles[ "EF_mu20it_tight" ] = &EF_mu20it_tight;
      fHandles[ "EF_mu22_IDTrkNoCut_tight" ] = &EF_mu22_IDTrkNoCut_tight;
      fHandles[ "EF_mu24" ] = &EF_mu24;
// -- slimmed --       fHandles[ "EF_mu24_g20vh_loose" ] = &EF_mu24_g20vh_loose;
// -- slimmed --       fHandles[ "EF_mu24_g20vh_medium" ] = &EF_mu24_g20vh_medium;
      fHandles[ "EF_mu24_j65_a4tchad" ] = &EF_mu24_j65_a4tchad;
      fHandles[ "EF_mu24_j65_a4tchad_EFxe40" ] = &EF_mu24_j65_a4tchad_EFxe40;
      fHandles[ "EF_mu24_j65_a4tchad_EFxe40_tclcw" ] = &EF_mu24_j65_a4tchad_EFxe40_tclcw;
      fHandles[ "EF_mu24_j65_a4tchad_EFxe60_tclcw" ] = &EF_mu24_j65_a4tchad_EFxe60_tclcw;
      fHandles[ "EF_mu24_medium" ] = &EF_mu24_medium;
      fHandles[ "EF_mu24_muCombTag_NoEF_tight" ] = &EF_mu24_muCombTag_NoEF_tight;
      fHandles[ "EF_mu24_tight" ] = &EF_mu24_tight;
      fHandles[ "EF_mu24_tight_3j35_a4tchad" ] = &EF_mu24_tight_3j35_a4tchad;
      fHandles[ "EF_mu24_tight_EFxe40" ] = &EF_mu24_tight_EFxe40;
      fHandles[ "EF_mu24_tight_L2StarB" ] = &EF_mu24_tight_L2StarB;
      fHandles[ "EF_mu24_tight_L2StarC" ] = &EF_mu24_tight_L2StarC;
      fHandles[ "EF_mu24_tight_MG" ] = &EF_mu24_tight_MG;
      fHandles[ "EF_mu24_tight_MuonEF" ] = &EF_mu24_tight_MuonEF;
      fHandles[ "EF_mu24_tight_b35_mediumEF_j35_a4tchad" ] = &EF_mu24_tight_b35_mediumEF_j35_a4tchad;
      fHandles[ "EF_mu24_tight_mu6_EFFS" ] = &EF_mu24_tight_mu6_EFFS;
      fHandles[ "EF_mu24i_tight" ] = &EF_mu24i_tight;
      fHandles[ "EF_mu24i_tight_MG" ] = &EF_mu24i_tight_MG;
      fHandles[ "EF_mu24i_tight_MuonEF" ] = &EF_mu24i_tight_MuonEF;
      fHandles[ "EF_mu24i_tight_l2muonSA" ] = &EF_mu24i_tight_l2muonSA;
      fHandles[ "EF_mu36_tight" ] = &EF_mu36_tight;
      fHandles[ "EF_mu40_MSonly_barrel_tight" ] = &EF_mu40_MSonly_barrel_tight;
      fHandles[ "EF_mu40_muCombTag_NoEF" ] = &EF_mu40_muCombTag_NoEF;
      fHandles[ "EF_mu40_slow_outOfTime_tight" ] = &EF_mu40_slow_outOfTime_tight;
      fHandles[ "EF_mu40_slow_tight" ] = &EF_mu40_slow_tight;
      fHandles[ "EF_mu40_tight" ] = &EF_mu40_tight;
      fHandles[ "EF_mu4T" ] = &EF_mu4T;
      fHandles[ "EF_mu4T_cosmic" ] = &EF_mu4T_cosmic;
      fHandles[ "EF_mu4T_j110_a4tchad_L2FS_matched" ] = &EF_mu4T_j110_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j110_a4tchad_matched" ] = &EF_mu4T_j110_a4tchad_matched;
      fHandles[ "EF_mu4T_j145_a4tchad_L2FS_matched" ] = &EF_mu4T_j145_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j145_a4tchad_matched" ] = &EF_mu4T_j145_a4tchad_matched;
      fHandles[ "EF_mu4T_j15_a4tchad_matched" ] = &EF_mu4T_j15_a4tchad_matched;
      fHandles[ "EF_mu4T_j15_a4tchad_matchedZ" ] = &EF_mu4T_j15_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j180_a4tchad_L2FS_matched" ] = &EF_mu4T_j180_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j180_a4tchad_matched" ] = &EF_mu4T_j180_a4tchad_matched;
      fHandles[ "EF_mu4T_j220_a4tchad_L2FS_matched" ] = &EF_mu4T_j220_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j220_a4tchad_matched" ] = &EF_mu4T_j220_a4tchad_matched;
      fHandles[ "EF_mu4T_j25_a4tchad_matched" ] = &EF_mu4T_j25_a4tchad_matched;
      fHandles[ "EF_mu4T_j25_a4tchad_matchedZ" ] = &EF_mu4T_j25_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j280_a4tchad_L2FS_matched" ] = &EF_mu4T_j280_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j280_a4tchad_matched" ] = &EF_mu4T_j280_a4tchad_matched;
      fHandles[ "EF_mu4T_j35_a4tchad_matched" ] = &EF_mu4T_j35_a4tchad_matched;
      fHandles[ "EF_mu4T_j35_a4tchad_matchedZ" ] = &EF_mu4T_j35_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j45_a4tchad_L2FS_matched" ] = &EF_mu4T_j45_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j45_a4tchad_L2FS_matchedZ" ] = &EF_mu4T_j45_a4tchad_L2FS_matchedZ;
      fHandles[ "EF_mu4T_j45_a4tchad_matched" ] = &EF_mu4T_j45_a4tchad_matched;
      fHandles[ "EF_mu4T_j45_a4tchad_matchedZ" ] = &EF_mu4T_j45_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j55_a4tchad_L2FS_matched" ] = &EF_mu4T_j55_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j55_a4tchad_L2FS_matchedZ" ] = &EF_mu4T_j55_a4tchad_L2FS_matchedZ;
      fHandles[ "EF_mu4T_j55_a4tchad_matched" ] = &EF_mu4T_j55_a4tchad_matched;
      fHandles[ "EF_mu4T_j55_a4tchad_matchedZ" ] = &EF_mu4T_j55_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j65_a4tchad_L2FS_matched" ] = &EF_mu4T_j65_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j65_a4tchad_matched" ] = &EF_mu4T_j65_a4tchad_matched;
      fHandles[ "EF_mu4T_j65_a4tchad_xe60_tclcw_loose" ] = &EF_mu4T_j65_a4tchad_xe60_tclcw_loose;
      fHandles[ "EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose" ] = &EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose;
      fHandles[ "EF_mu4T_j80_a4tchad_L2FS_matched" ] = &EF_mu4T_j80_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j80_a4tchad_matched" ] = &EF_mu4T_j80_a4tchad_matched;
// -- slimmed --       fHandles[ "EF_mu4Ti_g20Tvh_medium" ] = &EF_mu4Ti_g20Tvh_medium;
// -- slimmed --       fHandles[ "EF_mu4Ti_g20Tvh_medium_TauMass" ] = &EF_mu4Ti_g20Tvh_medium_TauMass;
      fHandles[ "EF_mu4Tmu6_Bmumu" ] = &EF_mu4Tmu6_Bmumu;
      fHandles[ "EF_mu4Tmu6_Bmumu_Barrel" ] = &EF_mu4Tmu6_Bmumu_Barrel;
      fHandles[ "EF_mu4Tmu6_Bmumux" ] = &EF_mu4Tmu6_Bmumux;
      fHandles[ "EF_mu4Tmu6_Bmumux_Barrel" ] = &EF_mu4Tmu6_Bmumux_Barrel;
      fHandles[ "EF_mu4Tmu6_DiMu" ] = &EF_mu4Tmu6_DiMu;
      fHandles[ "EF_mu4Tmu6_DiMu_Barrel" ] = &EF_mu4Tmu6_DiMu_Barrel;
      fHandles[ "EF_mu4Tmu6_DiMu_noVtx_noOS" ] = &EF_mu4Tmu6_DiMu_noVtx_noOS;
// -- slimmed --       fHandles[ "EF_mu4Tmu6_Jpsimumu" ] = &EF_mu4Tmu6_Jpsimumu;
// -- slimmed --       fHandles[ "EF_mu4Tmu6_Jpsimumu_Barrel" ] = &EF_mu4Tmu6_Jpsimumu_Barrel;
// -- slimmed --       fHandles[ "EF_mu4Tmu6_Jpsimumu_IDTrkNoCut" ] = &EF_mu4Tmu6_Jpsimumu_IDTrkNoCut;
// -- slimmed --       fHandles[ "EF_mu4Tmu6_Upsimumu" ] = &EF_mu4Tmu6_Upsimumu;
// -- slimmed --       fHandles[ "EF_mu4Tmu6_Upsimumu_Barrel" ] = &EF_mu4Tmu6_Upsimumu_Barrel;
      fHandles[ "EF_mu4_L1MU11_MSonly_cosmic" ] = &EF_mu4_L1MU11_MSonly_cosmic;
      fHandles[ "EF_mu4_L1MU11_cosmic" ] = &EF_mu4_L1MU11_cosmic;
      fHandles[ "EF_mu4_empty_NoAlg" ] = &EF_mu4_empty_NoAlg;
      fHandles[ "EF_mu4_firstempty_NoAlg" ] = &EF_mu4_firstempty_NoAlg;
      fHandles[ "EF_mu4_unpaired_iso_NoAlg" ] = &EF_mu4_unpaired_iso_NoAlg;
      fHandles[ "EF_mu50_MSonly_barrel_tight" ] = &EF_mu50_MSonly_barrel_tight;
      fHandles[ "EF_mu6" ] = &EF_mu6;
      fHandles[ "EF_mu60_slow_outOfTime_tight1" ] = &EF_mu60_slow_outOfTime_tight1;
      fHandles[ "EF_mu60_slow_tight1" ] = &EF_mu60_slow_tight1;
// -- slimmed --       fHandles[ "EF_mu6_Jpsimumu_tight" ] = &EF_mu6_Jpsimumu_tight;
      fHandles[ "EF_mu6_MSonly" ] = &EF_mu6_MSonly;
// -- slimmed --       fHandles[ "EF_mu6_Trk_Jpsi_loose" ] = &EF_mu6_Trk_Jpsi_loose;
      fHandles[ "EF_mu8" ] = &EF_mu8;
      fHandles[ "EF_mu8_4j45_a4tchad_L2FS" ] = &EF_mu8_4j45_a4tchad_L2FS;

      // =============================================================================
      // = from MC D3PD
      // =============================================================================
// -- slimmed --       fHandles[ "EF_2g15vh_loose_g10_loose" ] = &EF_2g15vh_loose_g10_loose;
// -- slimmed --       fHandles[ "EF_2g15vh_medium" ] = &EF_2g15vh_medium;
// -- slimmed --       fHandles[ "EF_2g20_loose" ] = &EF_2g20_loose;
// -- slimmed --       fHandles[ "EF_2g30_loose" ] = &EF_2g30_loose;
// -- slimmed --       fHandles[ "EF_2mu10_MSonly_g10_loose_EMPTY" ] = &EF_2mu10_MSonly_g10_loose_EMPTY;
// -- slimmed --       fHandles[ "EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO" ] = &EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO;
      fHandles[ "EF_2mu4T_xe50_tclcw" ] = &EF_2mu4T_xe50_tclcw;
      fHandles[ "EF_e12Tvh_loose1_mu8" ] = &EF_e12Tvh_loose1_mu8;
      fHandles[ "EF_e12Tvh_medium1_mu10" ] = &EF_e12Tvh_medium1_mu10;
      fHandles[ "EF_e12Tvh_medium1_mu6" ] = &EF_e12Tvh_medium1_mu6;
// -- slimmed --       fHandles[ "EF_e18_loose1_g35_loose" ] = &EF_e18_loose1_g35_loose;
// -- slimmed --       fHandles[ "EF_e18_loose1_g35_medium" ] = &EF_e18_loose1_g35_medium;
// -- slimmed --       fHandles[ "EF_e18_medium1_g25_medium" ] = &EF_e18_medium1_g25_medium;
// -- slimmed --       fHandles[ "EF_e18_medium1_g35_loose" ] = &EF_e18_medium1_g35_loose;
// -- slimmed --       fHandles[ "EF_e18_medium1_g35_medium" ] = &EF_e18_medium1_g35_medium;
      fHandles[ "EF_e22vh_medium1_IdScan" ] = &EF_e22vh_medium1_IdScan;
      fHandles[ "EF_e22vh_medium1_SiTrk" ] = &EF_e22vh_medium1_SiTrk;
      fHandles[ "EF_e22vh_medium1_TRT" ] = &EF_e22vh_medium1_TRT;
      fHandles[ "EF_e45_etcut" ] = &EF_e45_etcut;
// -- slimmed --       fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_IdScan" ] = &EF_e5_tight1_e4_etcut_Jpsi_IdScan;
// -- slimmed --       fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_SiTrk" ] = &EF_e5_tight1_e4_etcut_Jpsi_SiTrk;
// -- slimmed --       fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_TRT" ] = &EF_e5_tight1_e4_etcut_Jpsi_TRT;
      fHandles[ "EF_e60_etcut" ] = &EF_e60_etcut;
// -- slimmed --       fHandles[ "EF_g12Tvh_medium" ] = &EF_g12Tvh_medium;
// -- slimmed --       fHandles[ "EF_g15vh_loose" ] = &EF_g15vh_loose;
// -- slimmed --       fHandles[ "EF_g20Tvh_medium" ] = &EF_g20Tvh_medium;
// -- slimmed --       fHandles[ "EF_g20vh_medium" ] = &EF_g20vh_medium;
// -- slimmed --       fHandles[ "EF_g40_loose_EFxe50" ] = &EF_g40_loose_EFxe50;
// -- slimmed --       fHandles[ "EF_g40_loose_L2EFxe50" ] = &EF_g40_loose_L2EFxe50;
// -- slimmed --       fHandles[ "EF_mu10i_g10_loose" ] = &EF_mu10i_g10_loose;
// -- slimmed --       fHandles[ "EF_mu10i_g10_loose_TauMass" ] = &EF_mu10i_g10_loose_TauMass;
// -- slimmed --       fHandles[ "EF_mu10i_loose_g12Tvh_loose" ] = &EF_mu10i_loose_g12Tvh_loose;
// -- slimmed --       fHandles[ "EF_mu10i_loose_g12Tvh_loose_TauMass" ] = &EF_mu10i_loose_g12Tvh_loose_TauMass;
// -- slimmed --       fHandles[ "EF_mu18_2g15_loose" ] = &EF_mu18_2g15_loose;
// -- slimmed --       fHandles[ "EF_mu18_g20vh_loose" ] = &EF_mu18_g20vh_loose;
      fHandles[ "EF_mu18it_tight" ] = &EF_mu18it_tight;
// -- slimmed --       fHandles[ "EF_mu20i_tight_g5_loose" ] = &EF_mu20i_tight_g5_loose;
      fHandles[ "EF_mu24_j65_a4tchad_EFxe50_tclcw" ] = &EF_mu24_j65_a4tchad_EFxe50_tclcw;
      fHandles[ "EF_mu24_tight_2j35_a4tchad" ] = &EF_mu24_tight_2j35_a4tchad;
      fHandles[ "EF_mu24_tight_4j35_a4tchad" ] = &EF_mu24_tight_4j35_a4tchad;
// -- slimmed --       fHandles[ "EF_mu4T_Trk_Jpsi" ] = &EF_mu4T_Trk_Jpsi;
      fHandles[ "EF_mu4T_j360_a4tchad_L2FS_matched" ] = &EF_mu4T_j360_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j360_a4tchad_matched" ] = &EF_mu4T_j360_a4tchad_matched;
// -- slimmed --       fHandles[ "EF_mu4Ti_g20Tvh_loose" ] = &EF_mu4Ti_g20Tvh_loose;
// -- slimmed --       fHandles[ "EF_mu4Ti_g20Tvh_loose_TauMass" ] = &EF_mu4Ti_g20Tvh_loose_TauMass;
      fHandles[ "EF_mu6i" ] = &EF_mu6i;
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   TriggerD3PDObject::TriggerD3PDObject( const char* prefix )
      : TObject(),
        EF_2e12Tvh_loose1( this, ::TString( prefix ) + "EF_2e12Tvh_loose1", 0 ),
// -- slimmed --         EF_2e5_tight1_Jpsi( this, ::TString( prefix ) + "EF_2e5_tight1_Jpsi", 0 ),
        EF_2e7T_loose1_mu6( this, ::TString( prefix ) + "EF_2e7T_loose1_mu6", 0 ),
        EF_2e7T_medium1_mu6( this, ::TString( prefix ) + "EF_2e7T_medium1_mu6", 0 ),
// -- slimmed --         EF_2g15vh_medium_g10_medium( this, ::TString( prefix ) + "EF_2g15vh_medium_g10_medium", 0 ),
// -- slimmed --         EF_2g20vh_medium( this, ::TString( prefix ) + "EF_2g20vh_medium", 0 ),
// -- slimmed --         EF_2g40_loose( this, ::TString( prefix ) + "EF_2g40_loose", 0 ),
        EF_2mu10( this, ::TString( prefix ) + "EF_2mu10", 0 ),
// -- slimmed --         EF_2mu10_MSonly_g10_loose( this, ::TString( prefix ) + "EF_2mu10_MSonly_g10_loose", 0 ),
        EF_2mu13( this, ::TString( prefix ) + "EF_2mu13", 0 ),
        EF_2mu13_Zmumu_IDTrkNoCut( this, ::TString( prefix ) + "EF_2mu13_Zmumu_IDTrkNoCut", 0 ),
        EF_2mu13_l2muonSA( this, ::TString( prefix ) + "EF_2mu13_l2muonSA", 0 ),
        EF_2mu15( this, ::TString( prefix ) + "EF_2mu15", 0 ),
        EF_2mu4T( this, ::TString( prefix ) + "EF_2mu4T", 0 ),
        EF_2mu4T_2e5_tight1( this, ::TString( prefix ) + "EF_2mu4T_2e5_tight1", 0 ),
        EF_2mu4T_Bmumu( this, ::TString( prefix ) + "EF_2mu4T_Bmumu", 0 ),
        EF_2mu4T_Bmumu_Barrel( this, ::TString( prefix ) + "EF_2mu4T_Bmumu_Barrel", 0 ),
        EF_2mu4T_Bmumu_BarrelOnly( this, ::TString( prefix ) + "EF_2mu4T_Bmumu_BarrelOnly", 0 ),
        EF_2mu4T_Bmumux( this, ::TString( prefix ) + "EF_2mu4T_Bmumux", 0 ),
        EF_2mu4T_Bmumux_Barrel( this, ::TString( prefix ) + "EF_2mu4T_Bmumux_Barrel", 0 ),
        EF_2mu4T_Bmumux_BarrelOnly( this, ::TString( prefix ) + "EF_2mu4T_Bmumux_BarrelOnly", 0 ),
        EF_2mu4T_DiMu( this, ::TString( prefix ) + "EF_2mu4T_DiMu", 0 ),
        EF_2mu4T_DiMu_Barrel( this, ::TString( prefix ) + "EF_2mu4T_DiMu_Barrel", 0 ),
        EF_2mu4T_DiMu_BarrelOnly( this, ::TString( prefix ) + "EF_2mu4T_DiMu_BarrelOnly", 0 ),
        EF_2mu4T_DiMu_L2StarB( this, ::TString( prefix ) + "EF_2mu4T_DiMu_L2StarB", 0 ),
        EF_2mu4T_DiMu_L2StarC( this, ::TString( prefix ) + "EF_2mu4T_DiMu_L2StarC", 0 ),
        EF_2mu4T_DiMu_e5_tight1( this, ::TString( prefix ) + "EF_2mu4T_DiMu_e5_tight1", 0 ),
        EF_2mu4T_DiMu_l2muonSA( this, ::TString( prefix ) + "EF_2mu4T_DiMu_l2muonSA", 0 ),
        EF_2mu4T_DiMu_noVtx_noOS( this, ::TString( prefix ) + "EF_2mu4T_DiMu_noVtx_noOS", 0 ),
// -- slimmed --         EF_2mu4T_Jpsimumu( this, ::TString( prefix ) + "EF_2mu4T_Jpsimumu", 0 ),
// -- slimmed --         EF_2mu4T_Jpsimumu_Barrel( this, ::TString( prefix ) + "EF_2mu4T_Jpsimumu_Barrel", 0 ),
// -- slimmed --         EF_2mu4T_Jpsimumu_BarrelOnly( this, ::TString( prefix ) + "EF_2mu4T_Jpsimumu_BarrelOnly", 0 ),
// -- slimmed --         EF_2mu4T_Jpsimumu_IDTrkNoCut( this, ::TString( prefix ) + "EF_2mu4T_Jpsimumu_IDTrkNoCut", 0 ),
// -- slimmed --         EF_2mu4T_Upsimumu( this, ::TString( prefix ) + "EF_2mu4T_Upsimumu", 0 ),
// -- slimmed --         EF_2mu4T_Upsimumu_Barrel( this, ::TString( prefix ) + "EF_2mu4T_Upsimumu_Barrel", 0 ),
// -- slimmed --         EF_2mu4T_Upsimumu_BarrelOnly( this, ::TString( prefix ) + "EF_2mu4T_Upsimumu_BarrelOnly", 0 ),
        EF_2mu4T_xe60( this, ::TString( prefix ) + "EF_2mu4T_xe60", 0 ),
        EF_2mu4T_xe60_tclcw( this, ::TString( prefix ) + "EF_2mu4T_xe60_tclcw", 0 ),
        EF_2mu6( this, ::TString( prefix ) + "EF_2mu6", 0 ),
        EF_2mu6_Bmumu( this, ::TString( prefix ) + "EF_2mu6_Bmumu", 0 ),
        EF_2mu6_Bmumux( this, ::TString( prefix ) + "EF_2mu6_Bmumux", 0 ),
        EF_2mu6_DiMu( this, ::TString( prefix ) + "EF_2mu6_DiMu", 0 ),
        EF_2mu6_DiMu_DY20( this, ::TString( prefix ) + "EF_2mu6_DiMu_DY20", 0 ),
        EF_2mu6_DiMu_DY25( this, ::TString( prefix ) + "EF_2mu6_DiMu_DY25", 0 ),
        EF_2mu6_DiMu_noVtx_noOS( this, ::TString( prefix ) + "EF_2mu6_DiMu_noVtx_noOS", 0 ),
// -- slimmed --         EF_2mu6_Jpsimumu( this, ::TString( prefix ) + "EF_2mu6_Jpsimumu", 0 ),
// -- slimmed --         EF_2mu6_Upsimumu( this, ::TString( prefix ) + "EF_2mu6_Upsimumu", 0 ),
        EF_2mu6i_DiMu_DY( this, ::TString( prefix ) + "EF_2mu6i_DiMu_DY", 0 ),
        EF_2mu6i_DiMu_DY_2j25_a4tchad( this, ::TString( prefix ) + "EF_2mu6i_DiMu_DY_2j25_a4tchad", 0 ),
        EF_2mu6i_DiMu_DY_noVtx_noOS( this, ::TString( prefix ) + "EF_2mu6i_DiMu_DY_noVtx_noOS", 0 ),
        EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad( this, ::TString( prefix ) + "EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad", 0 ),
        EF_2mu8_EFxe30( this, ::TString( prefix ) + "EF_2mu8_EFxe30", 0 ),
        EF_2mu8_EFxe30_tclcw( this, ::TString( prefix ) + "EF_2mu8_EFxe30_tclcw", 0 ),
        EF_e11_etcut( this, ::TString( prefix ) + "EF_e11_etcut", 0 ),
        EF_e12Tvh_loose1( this, ::TString( prefix ) + "EF_e12Tvh_loose1", 0 ),
        EF_e12Tvh_medium1( this, ::TString( prefix ) + "EF_e12Tvh_medium1", 0 ),
        EF_e12Tvh_medium1_mu6_topo_medium( this, ::TString( prefix ) + "EF_e12Tvh_medium1_mu6_topo_medium", 0 ),
        EF_e12Tvh_medium1_mu8( this, ::TString( prefix ) + "EF_e12Tvh_medium1_mu8", 0 ),
        EF_e13_etcutTrk_xs60( this, ::TString( prefix ) + "EF_e13_etcutTrk_xs60", 0 ),
        EF_e13_etcutTrk_xs60_dphi2j15xe20( this, ::TString( prefix ) + "EF_e13_etcutTrk_xs60_dphi2j15xe20", 0 ),
// -- slimmed --         EF_e14_tight1_e4_etcut_Jpsi( this, ::TString( prefix ) + "EF_e14_tight1_e4_etcut_Jpsi", 0 ),
        EF_e15vh_medium1( this, ::TString( prefix ) + "EF_e15vh_medium1", 0 ),
        EF_e18_loose1( this, ::TString( prefix ) + "EF_e18_loose1", 0 ),
// -- slimmed --         EF_e18_loose1_g25_medium( this, ::TString( prefix ) + "EF_e18_loose1_g25_medium", 0 ),
        EF_e18_medium1( this, ::TString( prefix ) + "EF_e18_medium1", 0 ),
// -- slimmed --         EF_e18_medium1_g25_loose( this, ::TString( prefix ) + "EF_e18_medium1_g25_loose", 0 ),
        EF_e18vh_medium1( this, ::TString( prefix ) + "EF_e18vh_medium1", 0 ),
        EF_e18vh_medium1_2e7T_medium1( this, ::TString( prefix ) + "EF_e18vh_medium1_2e7T_medium1", 0 ),
        EF_e20_etcutTrk_xe30_dphi2j15xe20( this, ::TString( prefix ) + "EF_e20_etcutTrk_xe30_dphi2j15xe20", 0 ),
        EF_e20_etcutTrk_xs60_dphi2j15xe20( this, ::TString( prefix ) + "EF_e20_etcutTrk_xs60_dphi2j15xe20", 0 ),
// -- slimmed -- // -- slimmed --         EF_e20vhT_medium1_g6T_etcut_Upsi( this, ::TString( prefix ) + "EF_e20vhT_medium1_g6T_etcut_Upsi", 0 ),
// -- slimmed -- // -- slimmed --         EF_e20vhT_tight1_g6T_etcut_Upsi( this, ::TString( prefix ) + "EF_e20vhT_tight1_g6T_etcut_Upsi", 0 ),
        EF_e22vh_loose( this, ::TString( prefix ) + "EF_e22vh_loose", 0 ),
        EF_e22vh_loose0( this, ::TString( prefix ) + "EF_e22vh_loose0", 0 ),
        EF_e22vh_loose1( this, ::TString( prefix ) + "EF_e22vh_loose1", 0 ),
        EF_e22vh_medium1( this, ::TString( prefix ) + "EF_e22vh_medium1", 0 ),
        EF_e22vh_medium1_IDTrkNoCut( this, ::TString( prefix ) + "EF_e22vh_medium1_IDTrkNoCut", 0 ),
        EF_e22vhi_medium1( this, ::TString( prefix ) + "EF_e22vhi_medium1", 0 ),
        EF_e24vh_loose( this, ::TString( prefix ) + "EF_e24vh_loose", 0 ),
        EF_e24vh_loose0( this, ::TString( prefix ) + "EF_e24vh_loose0", 0 ),
        EF_e24vh_loose1( this, ::TString( prefix ) + "EF_e24vh_loose1", 0 ),
        EF_e24vh_medium1( this, ::TString( prefix ) + "EF_e24vh_medium1", 0 ),
        EF_e24vh_medium1_EFxe30( this, ::TString( prefix ) + "EF_e24vh_medium1_EFxe30", 0 ),
        EF_e24vh_medium1_EFxe30_tcem( this, ::TString( prefix ) + "EF_e24vh_medium1_EFxe30_tcem", 0 ),
        EF_e24vh_medium1_EFxe35_tcem( this, ::TString( prefix ) + "EF_e24vh_medium1_EFxe35_tcem", 0 ),
        EF_e24vh_medium1_EFxe35_tclcw( this, ::TString( prefix ) + "EF_e24vh_medium1_EFxe35_tclcw", 0 ),
        EF_e24vh_medium1_EFxe40( this, ::TString( prefix ) + "EF_e24vh_medium1_EFxe40", 0 ),
        EF_e24vh_medium1_IDTrkNoCut( this, ::TString( prefix ) + "EF_e24vh_medium1_IDTrkNoCut", 0 ),
        EF_e24vh_medium1_IdScan( this, ::TString( prefix ) + "EF_e24vh_medium1_IdScan", 0 ),
        EF_e24vh_medium1_L2StarB( this, ::TString( prefix ) + "EF_e24vh_medium1_L2StarB", 0 ),
        EF_e24vh_medium1_L2StarC( this, ::TString( prefix ) + "EF_e24vh_medium1_L2StarC", 0 ),
        EF_e24vh_medium1_SiTrk( this, ::TString( prefix ) + "EF_e24vh_medium1_SiTrk", 0 ),
        EF_e24vh_medium1_TRT( this, ::TString( prefix ) + "EF_e24vh_medium1_TRT", 0 ),
        EF_e24vh_medium1_b35_mediumEF_j35_a4tchad( this, ::TString( prefix ) + "EF_e24vh_medium1_b35_mediumEF_j35_a4tchad", 0 ),
        EF_e24vh_medium1_e7_medium1( this, ::TString( prefix ) + "EF_e24vh_medium1_e7_medium1", 0 ),
        EF_e24vh_tight1_e15_NoCut_Zee( this, ::TString( prefix ) + "EF_e24vh_tight1_e15_NoCut_Zee", 0 ),
        EF_e24vhi_loose1_mu8( this, ::TString( prefix ) + "EF_e24vhi_loose1_mu8", 0 ),
        EF_e24vhi_medium1( this, ::TString( prefix ) + "EF_e24vhi_medium1", 0 ),
        EF_e45_medium1( this, ::TString( prefix ) + "EF_e45_medium1", 0 ),
        EF_e5_tight1( this, ::TString( prefix ) + "EF_e5_tight1", 0 ),
// -- slimmed --         EF_e5_tight1_e14_etcut_Jpsi( this, ::TString( prefix ) + "EF_e5_tight1_e14_etcut_Jpsi", 0 ),
// -- slimmed --         EF_e5_tight1_e4_etcut_Jpsi( this, ::TString( prefix ) + "EF_e5_tight1_e4_etcut_Jpsi", 0 ),
// -- slimmed --         EF_e5_tight1_e4_etcut_Jpsi_L2StarB( this, ::TString( prefix ) + "EF_e5_tight1_e4_etcut_Jpsi_L2StarB", 0 ),
// -- slimmed --         EF_e5_tight1_e4_etcut_Jpsi_L2StarC( this, ::TString( prefix ) + "EF_e5_tight1_e4_etcut_Jpsi_L2StarC", 0 ),
        EF_e5_tight1_e5_NoCut( this, ::TString( prefix ) + "EF_e5_tight1_e5_NoCut", 0 ),
// -- slimmed --         EF_e5_tight1_e9_etcut_Jpsi( this, ::TString( prefix ) + "EF_e5_tight1_e9_etcut_Jpsi", 0 ),
        EF_e60_medium1( this, ::TString( prefix ) + "EF_e60_medium1", 0 ),
        EF_e7T_loose1( this, ::TString( prefix ) + "EF_e7T_loose1", 0 ),
        EF_e7T_loose1_2mu6( this, ::TString( prefix ) + "EF_e7T_loose1_2mu6", 0 ),
        EF_e7T_medium1( this, ::TString( prefix ) + "EF_e7T_medium1", 0 ),
        EF_e7T_medium1_2mu6( this, ::TString( prefix ) + "EF_e7T_medium1_2mu6", 0 ),
// -- slimmed --         EF_e9_tight1_e4_etcut_Jpsi( this, ::TString( prefix ) + "EF_e9_tight1_e4_etcut_Jpsi", 0 ),
        EF_eb_physics( this, ::TString( prefix ) + "EF_eb_physics", 0 ),
        EF_eb_physics_empty( this, ::TString( prefix ) + "EF_eb_physics_empty", 0 ),
        EF_eb_physics_firstempty( this, ::TString( prefix ) + "EF_eb_physics_firstempty", 0 ),
        EF_eb_physics_noL1PS( this, ::TString( prefix ) + "EF_eb_physics_noL1PS", 0 ),
        EF_eb_physics_unpaired_iso( this, ::TString( prefix ) + "EF_eb_physics_unpaired_iso", 0 ),
        EF_eb_physics_unpaired_noniso( this, ::TString( prefix ) + "EF_eb_physics_unpaired_noniso", 0 ),
        EF_eb_random( this, ::TString( prefix ) + "EF_eb_random", 0 ),
        EF_eb_random_empty( this, ::TString( prefix ) + "EF_eb_random_empty", 0 ),
        EF_eb_random_firstempty( this, ::TString( prefix ) + "EF_eb_random_firstempty", 0 ),
        EF_eb_random_unpaired_iso( this, ::TString( prefix ) + "EF_eb_random_unpaired_iso", 0 ),
// -- slimmed --         EF_g100_loose( this, ::TString( prefix ) + "EF_g100_loose", 0 ),
// -- slimmed --         EF_g10_NoCut_cosmic( this, ::TString( prefix ) + "EF_g10_NoCut_cosmic", 0 ),
// -- slimmed --         EF_g10_loose( this, ::TString( prefix ) + "EF_g10_loose", 0 ),
// -- slimmed --         EF_g10_medium( this, ::TString( prefix ) + "EF_g10_medium", 0 ),
// -- slimmed --         EF_g120_loose( this, ::TString( prefix ) + "EF_g120_loose", 0 ),
// -- slimmed --         EF_g12Tvh_loose( this, ::TString( prefix ) + "EF_g12Tvh_loose", 0 ),
// -- slimmed --         EF_g12Tvh_loose_larcalib( this, ::TString( prefix ) + "EF_g12Tvh_loose_larcalib", 0 ),
// -- slimmed --         EF_g15_loose( this, ::TString( prefix ) + "EF_g15_loose", 0 ),
// -- slimmed --         EF_g15vh_medium( this, ::TString( prefix ) + "EF_g15vh_medium", 0 ),
// -- slimmed --         EF_g200_etcut( this, ::TString( prefix ) + "EF_g200_etcut", 0 ),
// -- slimmed --         EF_g20_etcut( this, ::TString( prefix ) + "EF_g20_etcut", 0 ),
// -- slimmed --         EF_g20_loose( this, ::TString( prefix ) + "EF_g20_loose", 0 ),
// -- slimmed --         EF_g20_loose_larcalib( this, ::TString( prefix ) + "EF_g20_loose_larcalib", 0 ),
// -- slimmed --         EF_g20_medium( this, ::TString( prefix ) + "EF_g20_medium", 0 ),
// -- slimmed --         EF_g30_loose_g20_loose( this, ::TString( prefix ) + "EF_g30_loose_g20_loose", 0 ),
// -- slimmed --         EF_g30_medium_g20_medium( this, ::TString( prefix ) + "EF_g30_medium_g20_medium", 0 ),
// -- slimmed --         EF_g35_loose_g25_loose( this, ::TString( prefix ) + "EF_g35_loose_g25_loose", 0 ),
// -- slimmed --         EF_g35_loose_g30_loose( this, ::TString( prefix ) + "EF_g35_loose_g30_loose", 0 ),
// -- slimmed --         EF_g40_loose( this, ::TString( prefix ) + "EF_g40_loose", 0 ),
// -- slimmed --         EF_g40_loose_L2EFxe60( this, ::TString( prefix ) + "EF_g40_loose_L2EFxe60", 0 ),
// -- slimmed --         EF_g40_loose_L2EFxe60_tclcw( this, ::TString( prefix ) + "EF_g40_loose_L2EFxe60_tclcw", 0 ),
// -- slimmed --         EF_g40_loose_g25_loose( this, ::TString( prefix ) + "EF_g40_loose_g25_loose", 0 ),
// -- slimmed --         EF_g40_loose_g30_loose( this, ::TString( prefix ) + "EF_g40_loose_g30_loose", 0 ),
// -- slimmed --         EF_g40_loose_larcalib( this, ::TString( prefix ) + "EF_g40_loose_larcalib", 0 ),
// -- slimmed --         EF_g5_NoCut_cosmic( this, ::TString( prefix ) + "EF_g5_NoCut_cosmic", 0 ),
// -- slimmed --         EF_g60_loose( this, ::TString( prefix ) + "EF_g60_loose", 0 ),
// -- slimmed --         EF_g60_loose_larcalib( this, ::TString( prefix ) + "EF_g60_loose_larcalib", 0 ),
// -- slimmed --         EF_g80_loose( this, ::TString( prefix ) + "EF_g80_loose", 0 ),
// -- slimmed --         EF_g80_loose_larcalib( this, ::TString( prefix ) + "EF_g80_loose_larcalib", 0 ),
        EF_mu10( this, ::TString( prefix ) + "EF_mu10", 0 ),
// -- slimmed --         EF_mu10_Jpsimumu( this, ::TString( prefix ) + "EF_mu10_Jpsimumu", 0 ),
        EF_mu10_MSonly( this, ::TString( prefix ) + "EF_mu10_MSonly", 0 ),
// -- slimmed --         EF_mu10_Upsimumu_tight_FS( this, ::TString( prefix ) + "EF_mu10_Upsimumu_tight_FS", 0 ),
// -- slimmed --         EF_mu10i_g10_medium( this, ::TString( prefix ) + "EF_mu10i_g10_medium", 0 ),
// -- slimmed --         EF_mu10i_g10_medium_TauMass( this, ::TString( prefix ) + "EF_mu10i_g10_medium_TauMass", 0 ),
// -- slimmed --         EF_mu10i_loose_g12Tvh_medium( this, ::TString( prefix ) + "EF_mu10i_loose_g12Tvh_medium", 0 ),
// -- slimmed --         EF_mu10i_loose_g12Tvh_medium_TauMass( this, ::TString( prefix ) + "EF_mu10i_loose_g12Tvh_medium_TauMass", 0 ),
        EF_mu11_empty_NoAlg( this, ::TString( prefix ) + "EF_mu11_empty_NoAlg", 0 ),
        EF_mu13( this, ::TString( prefix ) + "EF_mu13", 0 ),
        EF_mu15( this, ::TString( prefix ) + "EF_mu15", 0 ),
        EF_mu18( this, ::TString( prefix ) + "EF_mu18", 0 ),
// -- slimmed --         EF_mu18_2g10_loose( this, ::TString( prefix ) + "EF_mu18_2g10_loose", 0 ),
// -- slimmed --         EF_mu18_2g10_medium( this, ::TString( prefix ) + "EF_mu18_2g10_medium", 0 ),
        EF_mu18_IDTrkNoCut_tight( this, ::TString( prefix ) + "EF_mu18_IDTrkNoCut_tight", 0 ),
        EF_mu18_medium( this, ::TString( prefix ) + "EF_mu18_medium", 0 ),
        EF_mu18_tight( this, ::TString( prefix ) + "EF_mu18_tight", 0 ),
        EF_mu18_tight_2mu4_EFFS( this, ::TString( prefix ) + "EF_mu18_tight_2mu4_EFFS", 0 ),
        EF_mu18_tight_e7_medium1( this, ::TString( prefix ) + "EF_mu18_tight_e7_medium1", 0 ),
        EF_mu18_tight_mu8_EFFS( this, ::TString( prefix ) + "EF_mu18_tight_mu8_EFFS", 0 ),
        EF_mu18i4_tight( this, ::TString( prefix ) + "EF_mu18i4_tight", 0 ),
// -- slimmed --         EF_mu20i_tight_g5_loose_TauMass( this, ::TString( prefix ) + "EF_mu20i_tight_g5_loose_TauMass", 0 ),
// -- slimmed --         EF_mu20i_tight_g5_medium( this, ::TString( prefix ) + "EF_mu20i_tight_g5_medium", 0 ),
// -- slimmed --         EF_mu20i_tight_g5_medium_TauMass( this, ::TString( prefix ) + "EF_mu20i_tight_g5_medium_TauMass", 0 ),
        EF_mu20it_tight( this, ::TString( prefix ) + "EF_mu20it_tight", 0 ),
        EF_mu22_IDTrkNoCut_tight( this, ::TString( prefix ) + "EF_mu22_IDTrkNoCut_tight", 0 ),
        EF_mu24( this, ::TString( prefix ) + "EF_mu24", 0 ),
// -- slimmed --         EF_mu24_g20vh_loose( this, ::TString( prefix ) + "EF_mu24_g20vh_loose", 0 ),
// -- slimmed --         EF_mu24_g20vh_medium( this, ::TString( prefix ) + "EF_mu24_g20vh_medium", 0 ),
        EF_mu24_j65_a4tchad( this, ::TString( prefix ) + "EF_mu24_j65_a4tchad", 0 ),
        EF_mu24_j65_a4tchad_EFxe40( this, ::TString( prefix ) + "EF_mu24_j65_a4tchad_EFxe40", 0 ),
        EF_mu24_j65_a4tchad_EFxe40_tclcw( this, ::TString( prefix ) + "EF_mu24_j65_a4tchad_EFxe40_tclcw", 0 ),
        EF_mu24_j65_a4tchad_EFxe60_tclcw( this, ::TString( prefix ) + "EF_mu24_j65_a4tchad_EFxe60_tclcw", 0 ),
        EF_mu24_medium( this, ::TString( prefix ) + "EF_mu24_medium", 0 ),
        EF_mu24_muCombTag_NoEF_tight( this, ::TString( prefix ) + "EF_mu24_muCombTag_NoEF_tight", 0 ),
        EF_mu24_tight( this, ::TString( prefix ) + "EF_mu24_tight", 0 ),
        EF_mu24_tight_3j35_a4tchad( this, ::TString( prefix ) + "EF_mu24_tight_3j35_a4tchad", 0 ),
        EF_mu24_tight_EFxe40( this, ::TString( prefix ) + "EF_mu24_tight_EFxe40", 0 ),
        EF_mu24_tight_L2StarB( this, ::TString( prefix ) + "EF_mu24_tight_L2StarB", 0 ),
        EF_mu24_tight_L2StarC( this, ::TString( prefix ) + "EF_mu24_tight_L2StarC", 0 ),
        EF_mu24_tight_MG( this, ::TString( prefix ) + "EF_mu24_tight_MG", 0 ),
        EF_mu24_tight_MuonEF( this, ::TString( prefix ) + "EF_mu24_tight_MuonEF", 0 ),
        EF_mu24_tight_b35_mediumEF_j35_a4tchad( this, ::TString( prefix ) + "EF_mu24_tight_b35_mediumEF_j35_a4tchad", 0 ),
        EF_mu24_tight_mu6_EFFS( this, ::TString( prefix ) + "EF_mu24_tight_mu6_EFFS", 0 ),
        EF_mu24i_tight( this, ::TString( prefix ) + "EF_mu24i_tight", 0 ),
        EF_mu24i_tight_MG( this, ::TString( prefix ) + "EF_mu24i_tight_MG", 0 ),
        EF_mu24i_tight_MuonEF( this, ::TString( prefix ) + "EF_mu24i_tight_MuonEF", 0 ),
        EF_mu24i_tight_l2muonSA( this, ::TString( prefix ) + "EF_mu24i_tight_l2muonSA", 0 ),
        EF_mu36_tight( this, ::TString( prefix ) + "EF_mu36_tight", 0 ),
        EF_mu40_MSonly_barrel_tight( this, ::TString( prefix ) + "EF_mu40_MSonly_barrel_tight", 0 ),
        EF_mu40_muCombTag_NoEF( this, ::TString( prefix ) + "EF_mu40_muCombTag_NoEF", 0 ),
        EF_mu40_slow_outOfTime_tight( this, ::TString( prefix ) + "EF_mu40_slow_outOfTime_tight", 0 ),
        EF_mu40_slow_tight( this, ::TString( prefix ) + "EF_mu40_slow_tight", 0 ),
        EF_mu40_tight( this, ::TString( prefix ) + "EF_mu40_tight", 0 ),
        EF_mu4T( this, ::TString( prefix ) + "EF_mu4T", 0 ),
        EF_mu4T_cosmic( this, ::TString( prefix ) + "EF_mu4T_cosmic", 0 ),
        EF_mu4T_j110_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j110_a4tchad_L2FS_matched", 0 ),
        EF_mu4T_j110_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j110_a4tchad_matched", 0 ),
        EF_mu4T_j145_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j145_a4tchad_L2FS_matched", 0 ),
        EF_mu4T_j145_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j145_a4tchad_matched", 0 ),
        EF_mu4T_j15_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j15_a4tchad_matched", 0 ),
        EF_mu4T_j15_a4tchad_matchedZ( this, ::TString( prefix ) + "EF_mu4T_j15_a4tchad_matchedZ", 0 ),
        EF_mu4T_j180_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j180_a4tchad_L2FS_matched", 0 ),
        EF_mu4T_j180_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j180_a4tchad_matched", 0 ),
        EF_mu4T_j220_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j220_a4tchad_L2FS_matched", 0 ),
        EF_mu4T_j220_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j220_a4tchad_matched", 0 ),
        EF_mu4T_j25_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j25_a4tchad_matched", 0 ),
        EF_mu4T_j25_a4tchad_matchedZ( this, ::TString( prefix ) + "EF_mu4T_j25_a4tchad_matchedZ", 0 ),
        EF_mu4T_j280_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j280_a4tchad_L2FS_matched", 0 ),
        EF_mu4T_j280_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j280_a4tchad_matched", 0 ),
        EF_mu4T_j35_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j35_a4tchad_matched", 0 ),
        EF_mu4T_j35_a4tchad_matchedZ( this, ::TString( prefix ) + "EF_mu4T_j35_a4tchad_matchedZ", 0 ),
        EF_mu4T_j45_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j45_a4tchad_L2FS_matched", 0 ),
        EF_mu4T_j45_a4tchad_L2FS_matchedZ( this, ::TString( prefix ) + "EF_mu4T_j45_a4tchad_L2FS_matchedZ", 0 ),
        EF_mu4T_j45_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j45_a4tchad_matched", 0 ),
        EF_mu4T_j45_a4tchad_matchedZ( this, ::TString( prefix ) + "EF_mu4T_j45_a4tchad_matchedZ", 0 ),
        EF_mu4T_j55_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j55_a4tchad_L2FS_matched", 0 ),
        EF_mu4T_j55_a4tchad_L2FS_matchedZ( this, ::TString( prefix ) + "EF_mu4T_j55_a4tchad_L2FS_matchedZ", 0 ),
        EF_mu4T_j55_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j55_a4tchad_matched", 0 ),
        EF_mu4T_j55_a4tchad_matchedZ( this, ::TString( prefix ) + "EF_mu4T_j55_a4tchad_matchedZ", 0 ),
        EF_mu4T_j65_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j65_a4tchad_L2FS_matched", 0 ),
        EF_mu4T_j65_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j65_a4tchad_matched", 0 ),
        EF_mu4T_j65_a4tchad_xe60_tclcw_loose( this, ::TString( prefix ) + "EF_mu4T_j65_a4tchad_xe60_tclcw_loose", 0 ),
        EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose( this, ::TString( prefix ) + "EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose", 0 ),
        EF_mu4T_j80_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j80_a4tchad_L2FS_matched", 0 ),
        EF_mu4T_j80_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j80_a4tchad_matched", 0 ),
// -- slimmed --         EF_mu4Ti_g20Tvh_medium( this, ::TString( prefix ) + "EF_mu4Ti_g20Tvh_medium", 0 ),
// -- slimmed --         EF_mu4Ti_g20Tvh_medium_TauMass( this, ::TString( prefix ) + "EF_mu4Ti_g20Tvh_medium_TauMass", 0 ),
        EF_mu4Tmu6_Bmumu( this, ::TString( prefix ) + "EF_mu4Tmu6_Bmumu", 0 ),
        EF_mu4Tmu6_Bmumu_Barrel( this, ::TString( prefix ) + "EF_mu4Tmu6_Bmumu_Barrel", 0 ),
        EF_mu4Tmu6_Bmumux( this, ::TString( prefix ) + "EF_mu4Tmu6_Bmumux", 0 ),
        EF_mu4Tmu6_Bmumux_Barrel( this, ::TString( prefix ) + "EF_mu4Tmu6_Bmumux_Barrel", 0 ),
        EF_mu4Tmu6_DiMu( this, ::TString( prefix ) + "EF_mu4Tmu6_DiMu", 0 ),
        EF_mu4Tmu6_DiMu_Barrel( this, ::TString( prefix ) + "EF_mu4Tmu6_DiMu_Barrel", 0 ),
        EF_mu4Tmu6_DiMu_noVtx_noOS( this, ::TString( prefix ) + "EF_mu4Tmu6_DiMu_noVtx_noOS", 0 ),
// -- slimmed --         EF_mu4Tmu6_Jpsimumu( this, ::TString( prefix ) + "EF_mu4Tmu6_Jpsimumu", 0 ),
// -- slimmed --         EF_mu4Tmu6_Jpsimumu_Barrel( this, ::TString( prefix ) + "EF_mu4Tmu6_Jpsimumu_Barrel", 0 ),
// -- slimmed --         EF_mu4Tmu6_Jpsimumu_IDTrkNoCut( this, ::TString( prefix ) + "EF_mu4Tmu6_Jpsimumu_IDTrkNoCut", 0 ),
// -- slimmed --         EF_mu4Tmu6_Upsimumu( this, ::TString( prefix ) + "EF_mu4Tmu6_Upsimumu", 0 ),
// -- slimmed --         EF_mu4Tmu6_Upsimumu_Barrel( this, ::TString( prefix ) + "EF_mu4Tmu6_Upsimumu_Barrel", 0 ),
        EF_mu4_L1MU11_MSonly_cosmic( this, ::TString( prefix ) + "EF_mu4_L1MU11_MSonly_cosmic", 0 ),
        EF_mu4_L1MU11_cosmic( this, ::TString( prefix ) + "EF_mu4_L1MU11_cosmic", 0 ),
        EF_mu4_empty_NoAlg( this, ::TString( prefix ) + "EF_mu4_empty_NoAlg", 0 ),
        EF_mu4_firstempty_NoAlg( this, ::TString( prefix ) + "EF_mu4_firstempty_NoAlg", 0 ),
        EF_mu4_unpaired_iso_NoAlg( this, ::TString( prefix ) + "EF_mu4_unpaired_iso_NoAlg", 0 ),
        EF_mu50_MSonly_barrel_tight( this, ::TString( prefix ) + "EF_mu50_MSonly_barrel_tight", 0 ),
        EF_mu6( this, ::TString( prefix ) + "EF_mu6", 0 ),
        EF_mu60_slow_outOfTime_tight1( this, ::TString( prefix ) + "EF_mu60_slow_outOfTime_tight1", 0 ),
        EF_mu60_slow_tight1( this, ::TString( prefix ) + "EF_mu60_slow_tight1", 0 ),
// -- slimmed --         EF_mu6_Jpsimumu_tight( this, ::TString( prefix ) + "EF_mu6_Jpsimumu_tight", 0 ),
        EF_mu6_MSonly( this, ::TString( prefix ) + "EF_mu6_MSonly", 0 ),
// -- slimmed --         EF_mu6_Trk_Jpsi_loose( this, ::TString( prefix ) + "EF_mu6_Trk_Jpsi_loose", 0 ),
        EF_mu8( this, ::TString( prefix ) + "EF_mu8", 0 ),
        EF_mu8_4j45_a4tchad_L2FS( this, ::TString( prefix ) + "EF_mu8_4j45_a4tchad_L2FS", 0 ),

      // =============================================================================
      // = from MC D3PD
      // =============================================================================
// -- slimmed --         EF_2g15vh_loose_g10_loose( this, ::TString( prefix ) + "EF_2g15vh_loose_g10_loose", 0 ),
// -- slimmed --         EF_2g15vh_medium( this, ::TString( prefix ) + "EF_2g15vh_medium", 0 ),
// -- slimmed --         EF_2g20_loose( this, ::TString( prefix ) + "EF_2g20_loose", 0 ),
// -- slimmed --         EF_2g30_loose( this, ::TString( prefix ) + "EF_2g30_loose", 0 ),
// -- slimmed --         EF_2mu10_MSonly_g10_loose_EMPTY( this, ::TString( prefix ) + "EF_2mu10_MSonly_g10_loose_EMPTY", 0 ),
// -- slimmed --         EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO( this, ::TString( prefix ) + "EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO", 0 ),
        EF_2mu4T_xe50_tclcw( this, ::TString( prefix ) + "EF_2mu4T_xe50_tclcw", 0 ),
        EF_e12Tvh_loose1_mu8( this, ::TString( prefix ) + "EF_e12Tvh_loose1_mu8", 0 ),
        EF_e12Tvh_medium1_mu10( this, ::TString( prefix ) + "EF_e12Tvh_medium1_mu10", 0 ),
        EF_e12Tvh_medium1_mu6( this, ::TString( prefix ) + "EF_e12Tvh_medium1_mu6", 0 ),
// -- slimmed --         EF_e18_loose1_g35_loose( this, ::TString( prefix ) + "EF_e18_loose1_g35_loose", 0 ),
// -- slimmed --         EF_e18_loose1_g35_medium( this, ::TString( prefix ) + "EF_e18_loose1_g35_medium", 0 ),
// -- slimmed --         EF_e18_medium1_g25_medium( this, ::TString( prefix ) + "EF_e18_medium1_g25_medium", 0 ),
// -- slimmed --         EF_e18_medium1_g35_loose( this, ::TString( prefix ) + "EF_e18_medium1_g35_loose", 0 ),
// -- slimmed --         EF_e18_medium1_g35_medium( this, ::TString( prefix ) + "EF_e18_medium1_g35_medium", 0 ),
        EF_e22vh_medium1_IdScan( this, ::TString( prefix ) + "EF_e22vh_medium1_IdScan", 0 ),
        EF_e22vh_medium1_SiTrk( this, ::TString( prefix ) + "EF_e22vh_medium1_SiTrk", 0 ),
        EF_e22vh_medium1_TRT( this, ::TString( prefix ) + "EF_e22vh_medium1_TRT", 0 ),
        EF_e45_etcut( this, ::TString( prefix ) + "EF_e45_etcut", 0 ),
// -- slimmed --         EF_e5_tight1_e4_etcut_Jpsi_IdScan( this, ::TString( prefix ) + "EF_e5_tight1_e4_etcut_Jpsi_IdScan", 0 ),
// -- slimmed --         EF_e5_tight1_e4_etcut_Jpsi_SiTrk( this, ::TString( prefix ) + "EF_e5_tight1_e4_etcut_Jpsi_SiTrk", 0 ),
// -- slimmed --         EF_e5_tight1_e4_etcut_Jpsi_TRT( this, ::TString( prefix ) + "EF_e5_tight1_e4_etcut_Jpsi_TRT", 0 ),
        EF_e60_etcut( this, ::TString( prefix ) + "EF_e60_etcut", 0 ),
// -- slimmed --         EF_g12Tvh_medium( this, ::TString( prefix ) + "EF_g12Tvh_medium", 0 ),
// -- slimmed --         EF_g15vh_loose( this, ::TString( prefix ) + "EF_g15vh_loose", 0 ),
// -- slimmed --         EF_g20Tvh_medium( this, ::TString( prefix ) + "EF_g20Tvh_medium", 0 ),
// -- slimmed --         EF_g20vh_medium( this, ::TString( prefix ) + "EF_g20vh_medium", 0 ),
// -- slimmed --         EF_g40_loose_EFxe50( this, ::TString( prefix ) + "EF_g40_loose_EFxe50", 0 ),
// -- slimmed --         EF_g40_loose_L2EFxe50( this, ::TString( prefix ) + "EF_g40_loose_L2EFxe50", 0 ),
// -- slimmed --         EF_mu10i_g10_loose( this, ::TString( prefix ) + "EF_mu10i_g10_loose", 0 ),
// -- slimmed --         EF_mu10i_g10_loose_TauMass( this, ::TString( prefix ) + "EF_mu10i_g10_loose_TauMass", 0 ),
// -- slimmed --         EF_mu10i_loose_g12Tvh_loose( this, ::TString( prefix ) + "EF_mu10i_loose_g12Tvh_loose", 0 ),
// -- slimmed --         EF_mu10i_loose_g12Tvh_loose_TauMass( this, ::TString( prefix ) + "EF_mu10i_loose_g12Tvh_loose_TauMass", 0 ),
// -- slimmed --         EF_mu18_2g15_loose( this, ::TString( prefix ) + "EF_mu18_2g15_loose", 0 ),
// -- slimmed --         EF_mu18_g20vh_loose( this, ::TString( prefix ) + "EF_mu18_g20vh_loose", 0 ),
        EF_mu18it_tight( this, ::TString( prefix ) + "EF_mu18it_tight", 0 ),
// -- slimmed --         EF_mu20i_tight_g5_loose( this, ::TString( prefix ) + "EF_mu20i_tight_g5_loose", 0 ),
        EF_mu24_j65_a4tchad_EFxe50_tclcw( this, ::TString( prefix ) + "EF_mu24_j65_a4tchad_EFxe50_tclcw", 0 ),
        EF_mu24_tight_2j35_a4tchad( this, ::TString( prefix ) + "EF_mu24_tight_2j35_a4tchad", 0 ),
        EF_mu24_tight_4j35_a4tchad( this, ::TString( prefix ) + "EF_mu24_tight_4j35_a4tchad", 0 ),
// -- slimmed --         EF_mu4T_Trk_Jpsi( this, ::TString( prefix ) + "EF_mu4T_Trk_Jpsi", 0 ),
        EF_mu4T_j360_a4tchad_L2FS_matched( this, ::TString( prefix ) + "EF_mu4T_j360_a4tchad_L2FS_matched", 0 ),
        EF_mu4T_j360_a4tchad_matched( this, ::TString( prefix ) + "EF_mu4T_j360_a4tchad_matched", 0 ),
// -- slimmed --         EF_mu4Ti_g20Tvh_loose( this, ::TString( prefix ) + "EF_mu4Ti_g20Tvh_loose", 0 ),
// -- slimmed --         EF_mu4Ti_g20Tvh_loose_TauMass( this, ::TString( prefix ) + "EF_mu4Ti_g20Tvh_loose_TauMass", 0 ),
        EF_mu6i( this, ::TString( prefix ) + "EF_mu6i", 0 ),

        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) {

      fHandles[ "EF_2e12Tvh_loose1" ] = &EF_2e12Tvh_loose1;
// -- slimmed --       fHandles[ "EF_2e5_tight1_Jpsi" ] = &EF_2e5_tight1_Jpsi;
      fHandles[ "EF_2e7T_loose1_mu6" ] = &EF_2e7T_loose1_mu6;
      fHandles[ "EF_2e7T_medium1_mu6" ] = &EF_2e7T_medium1_mu6;
// -- slimmed --       fHandles[ "EF_2g15vh_medium_g10_medium" ] = &EF_2g15vh_medium_g10_medium;
// -- slimmed --       fHandles[ "EF_2g20vh_medium" ] = &EF_2g20vh_medium;
// -- slimmed --       fHandles[ "EF_2g40_loose" ] = &EF_2g40_loose;
      fHandles[ "EF_2mu10" ] = &EF_2mu10;
// -- slimmed --       fHandles[ "EF_2mu10_MSonly_g10_loose" ] = &EF_2mu10_MSonly_g10_loose;
      fHandles[ "EF_2mu13" ] = &EF_2mu13;
      fHandles[ "EF_2mu13_Zmumu_IDTrkNoCut" ] = &EF_2mu13_Zmumu_IDTrkNoCut;
      fHandles[ "EF_2mu13_l2muonSA" ] = &EF_2mu13_l2muonSA;
      fHandles[ "EF_2mu15" ] = &EF_2mu15;
      fHandles[ "EF_2mu4T" ] = &EF_2mu4T;
      fHandles[ "EF_2mu4T_2e5_tight1" ] = &EF_2mu4T_2e5_tight1;
      fHandles[ "EF_2mu4T_Bmumu" ] = &EF_2mu4T_Bmumu;
      fHandles[ "EF_2mu4T_Bmumu_Barrel" ] = &EF_2mu4T_Bmumu_Barrel;
      fHandles[ "EF_2mu4T_Bmumu_BarrelOnly" ] = &EF_2mu4T_Bmumu_BarrelOnly;
      fHandles[ "EF_2mu4T_Bmumux" ] = &EF_2mu4T_Bmumux;
      fHandles[ "EF_2mu4T_Bmumux_Barrel" ] = &EF_2mu4T_Bmumux_Barrel;
      fHandles[ "EF_2mu4T_Bmumux_BarrelOnly" ] = &EF_2mu4T_Bmumux_BarrelOnly;
      fHandles[ "EF_2mu4T_DiMu" ] = &EF_2mu4T_DiMu;
      fHandles[ "EF_2mu4T_DiMu_Barrel" ] = &EF_2mu4T_DiMu_Barrel;
      fHandles[ "EF_2mu4T_DiMu_BarrelOnly" ] = &EF_2mu4T_DiMu_BarrelOnly;
      fHandles[ "EF_2mu4T_DiMu_L2StarB" ] = &EF_2mu4T_DiMu_L2StarB;
      fHandles[ "EF_2mu4T_DiMu_L2StarC" ] = &EF_2mu4T_DiMu_L2StarC;
      fHandles[ "EF_2mu4T_DiMu_e5_tight1" ] = &EF_2mu4T_DiMu_e5_tight1;
      fHandles[ "EF_2mu4T_DiMu_l2muonSA" ] = &EF_2mu4T_DiMu_l2muonSA;
      fHandles[ "EF_2mu4T_DiMu_noVtx_noOS" ] = &EF_2mu4T_DiMu_noVtx_noOS;
// -- slimmed --       fHandles[ "EF_2mu4T_Jpsimumu" ] = &EF_2mu4T_Jpsimumu;
// -- slimmed --       fHandles[ "EF_2mu4T_Jpsimumu_Barrel" ] = &EF_2mu4T_Jpsimumu_Barrel;
// -- slimmed --       fHandles[ "EF_2mu4T_Jpsimumu_BarrelOnly" ] = &EF_2mu4T_Jpsimumu_BarrelOnly;
// -- slimmed --       fHandles[ "EF_2mu4T_Jpsimumu_IDTrkNoCut" ] = &EF_2mu4T_Jpsimumu_IDTrkNoCut;
// -- slimmed --       fHandles[ "EF_2mu4T_Upsimumu" ] = &EF_2mu4T_Upsimumu;
// -- slimmed --       fHandles[ "EF_2mu4T_Upsimumu_Barrel" ] = &EF_2mu4T_Upsimumu_Barrel;
// -- slimmed --       fHandles[ "EF_2mu4T_Upsimumu_BarrelOnly" ] = &EF_2mu4T_Upsimumu_BarrelOnly;
      fHandles[ "EF_2mu4T_xe60" ] = &EF_2mu4T_xe60;
      fHandles[ "EF_2mu4T_xe60_tclcw" ] = &EF_2mu4T_xe60_tclcw;
      fHandles[ "EF_2mu6" ] = &EF_2mu6;
      fHandles[ "EF_2mu6_Bmumu" ] = &EF_2mu6_Bmumu;
      fHandles[ "EF_2mu6_Bmumux" ] = &EF_2mu6_Bmumux;
      fHandles[ "EF_2mu6_DiMu" ] = &EF_2mu6_DiMu;
      fHandles[ "EF_2mu6_DiMu_DY20" ] = &EF_2mu6_DiMu_DY20;
      fHandles[ "EF_2mu6_DiMu_DY25" ] = &EF_2mu6_DiMu_DY25;
      fHandles[ "EF_2mu6_DiMu_noVtx_noOS" ] = &EF_2mu6_DiMu_noVtx_noOS;
// -- slimmed --       fHandles[ "EF_2mu6_Jpsimumu" ] = &EF_2mu6_Jpsimumu;
// -- slimmed --       fHandles[ "EF_2mu6_Upsimumu" ] = &EF_2mu6_Upsimumu;
      fHandles[ "EF_2mu6i_DiMu_DY" ] = &EF_2mu6i_DiMu_DY;
      fHandles[ "EF_2mu6i_DiMu_DY_2j25_a4tchad" ] = &EF_2mu6i_DiMu_DY_2j25_a4tchad;
      fHandles[ "EF_2mu6i_DiMu_DY_noVtx_noOS" ] = &EF_2mu6i_DiMu_DY_noVtx_noOS;
      fHandles[ "EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad" ] = &EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad;
      fHandles[ "EF_2mu8_EFxe30" ] = &EF_2mu8_EFxe30;
      fHandles[ "EF_2mu8_EFxe30_tclcw" ] = &EF_2mu8_EFxe30_tclcw;
      fHandles[ "EF_e11_etcut" ] = &EF_e11_etcut;
      fHandles[ "EF_e12Tvh_loose1" ] = &EF_e12Tvh_loose1;
      fHandles[ "EF_e12Tvh_medium1" ] = &EF_e12Tvh_medium1;
      fHandles[ "EF_e12Tvh_medium1_mu6_topo_medium" ] = &EF_e12Tvh_medium1_mu6_topo_medium;
      fHandles[ "EF_e12Tvh_medium1_mu8" ] = &EF_e12Tvh_medium1_mu8;
      fHandles[ "EF_e13_etcutTrk_xs60" ] = &EF_e13_etcutTrk_xs60;
      fHandles[ "EF_e13_etcutTrk_xs60_dphi2j15xe20" ] = &EF_e13_etcutTrk_xs60_dphi2j15xe20;
// -- slimmed --       fHandles[ "EF_e14_tight1_e4_etcut_Jpsi" ] = &EF_e14_tight1_e4_etcut_Jpsi;
      fHandles[ "EF_e15vh_medium1" ] = &EF_e15vh_medium1;
      fHandles[ "EF_e18_loose1" ] = &EF_e18_loose1;
// -- slimmed --       fHandles[ "EF_e18_loose1_g25_medium" ] = &EF_e18_loose1_g25_medium;
      fHandles[ "EF_e18_medium1" ] = &EF_e18_medium1;
// -- slimmed --       fHandles[ "EF_e18_medium1_g25_loose" ] = &EF_e18_medium1_g25_loose;
      fHandles[ "EF_e18vh_medium1" ] = &EF_e18vh_medium1;
      fHandles[ "EF_e18vh_medium1_2e7T_medium1" ] = &EF_e18vh_medium1_2e7T_medium1;
      fHandles[ "EF_e20_etcutTrk_xe30_dphi2j15xe20" ] = &EF_e20_etcutTrk_xe30_dphi2j15xe20;
      fHandles[ "EF_e20_etcutTrk_xs60_dphi2j15xe20" ] = &EF_e20_etcutTrk_xs60_dphi2j15xe20;
// -- slimmed -- // -- slimmed --       fHandles[ "EF_e20vhT_medium1_g6T_etcut_Upsi" ] = &EF_e20vhT_medium1_g6T_etcut_Upsi;
// -- slimmed -- // -- slimmed --       fHandles[ "EF_e20vhT_tight1_g6T_etcut_Upsi" ] = &EF_e20vhT_tight1_g6T_etcut_Upsi;
      fHandles[ "EF_e22vh_loose" ] = &EF_e22vh_loose;
      fHandles[ "EF_e22vh_loose0" ] = &EF_e22vh_loose0;
      fHandles[ "EF_e22vh_loose1" ] = &EF_e22vh_loose1;
      fHandles[ "EF_e22vh_medium1" ] = &EF_e22vh_medium1;
      fHandles[ "EF_e22vh_medium1_IDTrkNoCut" ] = &EF_e22vh_medium1_IDTrkNoCut;
      fHandles[ "EF_e22vhi_medium1" ] = &EF_e22vhi_medium1;
      fHandles[ "EF_e24vh_loose" ] = &EF_e24vh_loose;
      fHandles[ "EF_e24vh_loose0" ] = &EF_e24vh_loose0;
      fHandles[ "EF_e24vh_loose1" ] = &EF_e24vh_loose1;
      fHandles[ "EF_e24vh_medium1" ] = &EF_e24vh_medium1;
      fHandles[ "EF_e24vh_medium1_EFxe30" ] = &EF_e24vh_medium1_EFxe30;
      fHandles[ "EF_e24vh_medium1_EFxe30_tcem" ] = &EF_e24vh_medium1_EFxe30_tcem;
      fHandles[ "EF_e24vh_medium1_EFxe35_tcem" ] = &EF_e24vh_medium1_EFxe35_tcem;
      fHandles[ "EF_e24vh_medium1_EFxe35_tclcw" ] = &EF_e24vh_medium1_EFxe35_tclcw;
      fHandles[ "EF_e24vh_medium1_EFxe40" ] = &EF_e24vh_medium1_EFxe40;
      fHandles[ "EF_e24vh_medium1_IDTrkNoCut" ] = &EF_e24vh_medium1_IDTrkNoCut;
      fHandles[ "EF_e24vh_medium1_IdScan" ] = &EF_e24vh_medium1_IdScan;
      fHandles[ "EF_e24vh_medium1_L2StarB" ] = &EF_e24vh_medium1_L2StarB;
      fHandles[ "EF_e24vh_medium1_L2StarC" ] = &EF_e24vh_medium1_L2StarC;
      fHandles[ "EF_e24vh_medium1_SiTrk" ] = &EF_e24vh_medium1_SiTrk;
      fHandles[ "EF_e24vh_medium1_TRT" ] = &EF_e24vh_medium1_TRT;
      fHandles[ "EF_e24vh_medium1_b35_mediumEF_j35_a4tchad" ] = &EF_e24vh_medium1_b35_mediumEF_j35_a4tchad;
      fHandles[ "EF_e24vh_medium1_e7_medium1" ] = &EF_e24vh_medium1_e7_medium1;
      fHandles[ "EF_e24vh_tight1_e15_NoCut_Zee" ] = &EF_e24vh_tight1_e15_NoCut_Zee;
      fHandles[ "EF_e24vhi_loose1_mu8" ] = &EF_e24vhi_loose1_mu8;
      fHandles[ "EF_e24vhi_medium1" ] = &EF_e24vhi_medium1;
      fHandles[ "EF_e45_medium1" ] = &EF_e45_medium1;
      fHandles[ "EF_e5_tight1" ] = &EF_e5_tight1;
// -- slimmed --       fHandles[ "EF_e5_tight1_e14_etcut_Jpsi" ] = &EF_e5_tight1_e14_etcut_Jpsi;
// -- slimmed --       fHandles[ "EF_e5_tight1_e4_etcut_Jpsi" ] = &EF_e5_tight1_e4_etcut_Jpsi;
// -- slimmed --       fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_L2StarB" ] = &EF_e5_tight1_e4_etcut_Jpsi_L2StarB;
// -- slimmed --       fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_L2StarC" ] = &EF_e5_tight1_e4_etcut_Jpsi_L2StarC;
      fHandles[ "EF_e5_tight1_e5_NoCut" ] = &EF_e5_tight1_e5_NoCut;
// -- slimmed --       fHandles[ "EF_e5_tight1_e9_etcut_Jpsi" ] = &EF_e5_tight1_e9_etcut_Jpsi;
      fHandles[ "EF_e60_medium1" ] = &EF_e60_medium1;
      fHandles[ "EF_e7T_loose1" ] = &EF_e7T_loose1;
      fHandles[ "EF_e7T_loose1_2mu6" ] = &EF_e7T_loose1_2mu6;
      fHandles[ "EF_e7T_medium1" ] = &EF_e7T_medium1;
      fHandles[ "EF_e7T_medium1_2mu6" ] = &EF_e7T_medium1_2mu6;
// -- slimmed --       fHandles[ "EF_e9_tight1_e4_etcut_Jpsi" ] = &EF_e9_tight1_e4_etcut_Jpsi;
      fHandles[ "EF_eb_physics" ] = &EF_eb_physics;
      fHandles[ "EF_eb_physics_empty" ] = &EF_eb_physics_empty;
      fHandles[ "EF_eb_physics_firstempty" ] = &EF_eb_physics_firstempty;
      fHandles[ "EF_eb_physics_noL1PS" ] = &EF_eb_physics_noL1PS;
      fHandles[ "EF_eb_physics_unpaired_iso" ] = &EF_eb_physics_unpaired_iso;
      fHandles[ "EF_eb_physics_unpaired_noniso" ] = &EF_eb_physics_unpaired_noniso;
      fHandles[ "EF_eb_random" ] = &EF_eb_random;
      fHandles[ "EF_eb_random_empty" ] = &EF_eb_random_empty;
      fHandles[ "EF_eb_random_firstempty" ] = &EF_eb_random_firstempty;
      fHandles[ "EF_eb_random_unpaired_iso" ] = &EF_eb_random_unpaired_iso;
// -- slimmed --       fHandles[ "EF_g100_loose" ] = &EF_g100_loose;
// -- slimmed --       fHandles[ "EF_g10_NoCut_cosmic" ] = &EF_g10_NoCut_cosmic;
// -- slimmed --       fHandles[ "EF_g10_loose" ] = &EF_g10_loose;
// -- slimmed --       fHandles[ "EF_g10_medium" ] = &EF_g10_medium;
// -- slimmed --       fHandles[ "EF_g120_loose" ] = &EF_g120_loose;
// -- slimmed --       fHandles[ "EF_g12Tvh_loose" ] = &EF_g12Tvh_loose;
// -- slimmed --       fHandles[ "EF_g12Tvh_loose_larcalib" ] = &EF_g12Tvh_loose_larcalib;
// -- slimmed --       fHandles[ "EF_g15_loose" ] = &EF_g15_loose;
// -- slimmed --       fHandles[ "EF_g15vh_medium" ] = &EF_g15vh_medium;
// -- slimmed --       fHandles[ "EF_g200_etcut" ] = &EF_g200_etcut;
// -- slimmed --       fHandles[ "EF_g20_etcut" ] = &EF_g20_etcut;
// -- slimmed --       fHandles[ "EF_g20_loose" ] = &EF_g20_loose;
// -- slimmed --       fHandles[ "EF_g20_loose_larcalib" ] = &EF_g20_loose_larcalib;
// -- slimmed --       fHandles[ "EF_g20_medium" ] = &EF_g20_medium;
// -- slimmed --       fHandles[ "EF_g30_loose_g20_loose" ] = &EF_g30_loose_g20_loose;
// -- slimmed --       fHandles[ "EF_g30_medium_g20_medium" ] = &EF_g30_medium_g20_medium;
// -- slimmed --       fHandles[ "EF_g35_loose_g25_loose" ] = &EF_g35_loose_g25_loose;
// -- slimmed --       fHandles[ "EF_g35_loose_g30_loose" ] = &EF_g35_loose_g30_loose;
// -- slimmed --       fHandles[ "EF_g40_loose" ] = &EF_g40_loose;
// -- slimmed --       fHandles[ "EF_g40_loose_L2EFxe60" ] = &EF_g40_loose_L2EFxe60;
// -- slimmed --       fHandles[ "EF_g40_loose_L2EFxe60_tclcw" ] = &EF_g40_loose_L2EFxe60_tclcw;
// -- slimmed --       fHandles[ "EF_g40_loose_g25_loose" ] = &EF_g40_loose_g25_loose;
// -- slimmed --       fHandles[ "EF_g40_loose_g30_loose" ] = &EF_g40_loose_g30_loose;
// -- slimmed --       fHandles[ "EF_g40_loose_larcalib" ] = &EF_g40_loose_larcalib;
// -- slimmed --       fHandles[ "EF_g5_NoCut_cosmic" ] = &EF_g5_NoCut_cosmic;
// -- slimmed --       fHandles[ "EF_g60_loose" ] = &EF_g60_loose;
// -- slimmed --       fHandles[ "EF_g60_loose_larcalib" ] = &EF_g60_loose_larcalib;
// -- slimmed --       fHandles[ "EF_g80_loose" ] = &EF_g80_loose;
// -- slimmed --       fHandles[ "EF_g80_loose_larcalib" ] = &EF_g80_loose_larcalib;
      fHandles[ "EF_mu10" ] = &EF_mu10;
// -- slimmed --       fHandles[ "EF_mu10_Jpsimumu" ] = &EF_mu10_Jpsimumu;
      fHandles[ "EF_mu10_MSonly" ] = &EF_mu10_MSonly;
// -- slimmed --       fHandles[ "EF_mu10_Upsimumu_tight_FS" ] = &EF_mu10_Upsimumu_tight_FS;
// -- slimmed --       fHandles[ "EF_mu10i_g10_medium" ] = &EF_mu10i_g10_medium;
// -- slimmed --       fHandles[ "EF_mu10i_g10_medium_TauMass" ] = &EF_mu10i_g10_medium_TauMass;
// -- slimmed --       fHandles[ "EF_mu10i_loose_g12Tvh_medium" ] = &EF_mu10i_loose_g12Tvh_medium;
// -- slimmed --       fHandles[ "EF_mu10i_loose_g12Tvh_medium_TauMass" ] = &EF_mu10i_loose_g12Tvh_medium_TauMass;
      fHandles[ "EF_mu11_empty_NoAlg" ] = &EF_mu11_empty_NoAlg;
      fHandles[ "EF_mu13" ] = &EF_mu13;
      fHandles[ "EF_mu15" ] = &EF_mu15;
      fHandles[ "EF_mu18" ] = &EF_mu18;
// -- slimmed --       fHandles[ "EF_mu18_2g10_loose" ] = &EF_mu18_2g10_loose;
// -- slimmed --       fHandles[ "EF_mu18_2g10_medium" ] = &EF_mu18_2g10_medium;
      fHandles[ "EF_mu18_IDTrkNoCut_tight" ] = &EF_mu18_IDTrkNoCut_tight;
      fHandles[ "EF_mu18_medium" ] = &EF_mu18_medium;
      fHandles[ "EF_mu18_tight" ] = &EF_mu18_tight;
      fHandles[ "EF_mu18_tight_2mu4_EFFS" ] = &EF_mu18_tight_2mu4_EFFS;
      fHandles[ "EF_mu18_tight_e7_medium1" ] = &EF_mu18_tight_e7_medium1;
      fHandles[ "EF_mu18_tight_mu8_EFFS" ] = &EF_mu18_tight_mu8_EFFS;
      fHandles[ "EF_mu18i4_tight" ] = &EF_mu18i4_tight;
// -- slimmed --       fHandles[ "EF_mu20i_tight_g5_loose_TauMass" ] = &EF_mu20i_tight_g5_loose_TauMass;
// -- slimmed --       fHandles[ "EF_mu20i_tight_g5_medium" ] = &EF_mu20i_tight_g5_medium;
// -- slimmed --       fHandles[ "EF_mu20i_tight_g5_medium_TauMass" ] = &EF_mu20i_tight_g5_medium_TauMass;
      fHandles[ "EF_mu20it_tight" ] = &EF_mu20it_tight;
      fHandles[ "EF_mu22_IDTrkNoCut_tight" ] = &EF_mu22_IDTrkNoCut_tight;
      fHandles[ "EF_mu24" ] = &EF_mu24;
// -- slimmed --       fHandles[ "EF_mu24_g20vh_loose" ] = &EF_mu24_g20vh_loose;
// -- slimmed --       fHandles[ "EF_mu24_g20vh_medium" ] = &EF_mu24_g20vh_medium;
      fHandles[ "EF_mu24_j65_a4tchad" ] = &EF_mu24_j65_a4tchad;
      fHandles[ "EF_mu24_j65_a4tchad_EFxe40" ] = &EF_mu24_j65_a4tchad_EFxe40;
      fHandles[ "EF_mu24_j65_a4tchad_EFxe40_tclcw" ] = &EF_mu24_j65_a4tchad_EFxe40_tclcw;
      fHandles[ "EF_mu24_j65_a4tchad_EFxe60_tclcw" ] = &EF_mu24_j65_a4tchad_EFxe60_tclcw;
      fHandles[ "EF_mu24_medium" ] = &EF_mu24_medium;
      fHandles[ "EF_mu24_muCombTag_NoEF_tight" ] = &EF_mu24_muCombTag_NoEF_tight;
      fHandles[ "EF_mu24_tight" ] = &EF_mu24_tight;
      fHandles[ "EF_mu24_tight_3j35_a4tchad" ] = &EF_mu24_tight_3j35_a4tchad;
      fHandles[ "EF_mu24_tight_EFxe40" ] = &EF_mu24_tight_EFxe40;
      fHandles[ "EF_mu24_tight_L2StarB" ] = &EF_mu24_tight_L2StarB;
      fHandles[ "EF_mu24_tight_L2StarC" ] = &EF_mu24_tight_L2StarC;
      fHandles[ "EF_mu24_tight_MG" ] = &EF_mu24_tight_MG;
      fHandles[ "EF_mu24_tight_MuonEF" ] = &EF_mu24_tight_MuonEF;
      fHandles[ "EF_mu24_tight_b35_mediumEF_j35_a4tchad" ] = &EF_mu24_tight_b35_mediumEF_j35_a4tchad;
      fHandles[ "EF_mu24_tight_mu6_EFFS" ] = &EF_mu24_tight_mu6_EFFS;
      fHandles[ "EF_mu24i_tight" ] = &EF_mu24i_tight;
      fHandles[ "EF_mu24i_tight_MG" ] = &EF_mu24i_tight_MG;
      fHandles[ "EF_mu24i_tight_MuonEF" ] = &EF_mu24i_tight_MuonEF;
      fHandles[ "EF_mu24i_tight_l2muonSA" ] = &EF_mu24i_tight_l2muonSA;
      fHandles[ "EF_mu36_tight" ] = &EF_mu36_tight;
      fHandles[ "EF_mu40_MSonly_barrel_tight" ] = &EF_mu40_MSonly_barrel_tight;
      fHandles[ "EF_mu40_muCombTag_NoEF" ] = &EF_mu40_muCombTag_NoEF;
      fHandles[ "EF_mu40_slow_outOfTime_tight" ] = &EF_mu40_slow_outOfTime_tight;
      fHandles[ "EF_mu40_slow_tight" ] = &EF_mu40_slow_tight;
      fHandles[ "EF_mu40_tight" ] = &EF_mu40_tight;
      fHandles[ "EF_mu4T" ] = &EF_mu4T;
      fHandles[ "EF_mu4T_cosmic" ] = &EF_mu4T_cosmic;
      fHandles[ "EF_mu4T_j110_a4tchad_L2FS_matched" ] = &EF_mu4T_j110_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j110_a4tchad_matched" ] = &EF_mu4T_j110_a4tchad_matched;
      fHandles[ "EF_mu4T_j145_a4tchad_L2FS_matched" ] = &EF_mu4T_j145_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j145_a4tchad_matched" ] = &EF_mu4T_j145_a4tchad_matched;
      fHandles[ "EF_mu4T_j15_a4tchad_matched" ] = &EF_mu4T_j15_a4tchad_matched;
      fHandles[ "EF_mu4T_j15_a4tchad_matchedZ" ] = &EF_mu4T_j15_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j180_a4tchad_L2FS_matched" ] = &EF_mu4T_j180_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j180_a4tchad_matched" ] = &EF_mu4T_j180_a4tchad_matched;
      fHandles[ "EF_mu4T_j220_a4tchad_L2FS_matched" ] = &EF_mu4T_j220_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j220_a4tchad_matched" ] = &EF_mu4T_j220_a4tchad_matched;
      fHandles[ "EF_mu4T_j25_a4tchad_matched" ] = &EF_mu4T_j25_a4tchad_matched;
      fHandles[ "EF_mu4T_j25_a4tchad_matchedZ" ] = &EF_mu4T_j25_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j280_a4tchad_L2FS_matched" ] = &EF_mu4T_j280_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j280_a4tchad_matched" ] = &EF_mu4T_j280_a4tchad_matched;
      fHandles[ "EF_mu4T_j35_a4tchad_matched" ] = &EF_mu4T_j35_a4tchad_matched;
      fHandles[ "EF_mu4T_j35_a4tchad_matchedZ" ] = &EF_mu4T_j35_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j45_a4tchad_L2FS_matched" ] = &EF_mu4T_j45_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j45_a4tchad_L2FS_matchedZ" ] = &EF_mu4T_j45_a4tchad_L2FS_matchedZ;
      fHandles[ "EF_mu4T_j45_a4tchad_matched" ] = &EF_mu4T_j45_a4tchad_matched;
      fHandles[ "EF_mu4T_j45_a4tchad_matchedZ" ] = &EF_mu4T_j45_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j55_a4tchad_L2FS_matched" ] = &EF_mu4T_j55_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j55_a4tchad_L2FS_matchedZ" ] = &EF_mu4T_j55_a4tchad_L2FS_matchedZ;
      fHandles[ "EF_mu4T_j55_a4tchad_matched" ] = &EF_mu4T_j55_a4tchad_matched;
      fHandles[ "EF_mu4T_j55_a4tchad_matchedZ" ] = &EF_mu4T_j55_a4tchad_matchedZ;
      fHandles[ "EF_mu4T_j65_a4tchad_L2FS_matched" ] = &EF_mu4T_j65_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j65_a4tchad_matched" ] = &EF_mu4T_j65_a4tchad_matched;
      fHandles[ "EF_mu4T_j65_a4tchad_xe60_tclcw_loose" ] = &EF_mu4T_j65_a4tchad_xe60_tclcw_loose;
      fHandles[ "EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose" ] = &EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose;
      fHandles[ "EF_mu4T_j80_a4tchad_L2FS_matched" ] = &EF_mu4T_j80_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j80_a4tchad_matched" ] = &EF_mu4T_j80_a4tchad_matched;
// -- slimmed --       fHandles[ "EF_mu4Ti_g20Tvh_medium" ] = &EF_mu4Ti_g20Tvh_medium;
// -- slimmed --       fHandles[ "EF_mu4Ti_g20Tvh_medium_TauMass" ] = &EF_mu4Ti_g20Tvh_medium_TauMass;
      fHandles[ "EF_mu4Tmu6_Bmumu" ] = &EF_mu4Tmu6_Bmumu;
      fHandles[ "EF_mu4Tmu6_Bmumu_Barrel" ] = &EF_mu4Tmu6_Bmumu_Barrel;
      fHandles[ "EF_mu4Tmu6_Bmumux" ] = &EF_mu4Tmu6_Bmumux;
      fHandles[ "EF_mu4Tmu6_Bmumux_Barrel" ] = &EF_mu4Tmu6_Bmumux_Barrel;
      fHandles[ "EF_mu4Tmu6_DiMu" ] = &EF_mu4Tmu6_DiMu;
      fHandles[ "EF_mu4Tmu6_DiMu_Barrel" ] = &EF_mu4Tmu6_DiMu_Barrel;
      fHandles[ "EF_mu4Tmu6_DiMu_noVtx_noOS" ] = &EF_mu4Tmu6_DiMu_noVtx_noOS;
// -- slimmed --       fHandles[ "EF_mu4Tmu6_Jpsimumu" ] = &EF_mu4Tmu6_Jpsimumu;
// -- slimmed --       fHandles[ "EF_mu4Tmu6_Jpsimumu_Barrel" ] = &EF_mu4Tmu6_Jpsimumu_Barrel;
// -- slimmed --       fHandles[ "EF_mu4Tmu6_Jpsimumu_IDTrkNoCut" ] = &EF_mu4Tmu6_Jpsimumu_IDTrkNoCut;
// -- slimmed --       fHandles[ "EF_mu4Tmu6_Upsimumu" ] = &EF_mu4Tmu6_Upsimumu;
// -- slimmed --       fHandles[ "EF_mu4Tmu6_Upsimumu_Barrel" ] = &EF_mu4Tmu6_Upsimumu_Barrel;
      fHandles[ "EF_mu4_L1MU11_MSonly_cosmic" ] = &EF_mu4_L1MU11_MSonly_cosmic;
      fHandles[ "EF_mu4_L1MU11_cosmic" ] = &EF_mu4_L1MU11_cosmic;
      fHandles[ "EF_mu4_empty_NoAlg" ] = &EF_mu4_empty_NoAlg;
      fHandles[ "EF_mu4_firstempty_NoAlg" ] = &EF_mu4_firstempty_NoAlg;
      fHandles[ "EF_mu4_unpaired_iso_NoAlg" ] = &EF_mu4_unpaired_iso_NoAlg;
      fHandles[ "EF_mu50_MSonly_barrel_tight" ] = &EF_mu50_MSonly_barrel_tight;
      fHandles[ "EF_mu6" ] = &EF_mu6;
      fHandles[ "EF_mu60_slow_outOfTime_tight1" ] = &EF_mu60_slow_outOfTime_tight1;
      fHandles[ "EF_mu60_slow_tight1" ] = &EF_mu60_slow_tight1;
// -- slimmed --       fHandles[ "EF_mu6_Jpsimumu_tight" ] = &EF_mu6_Jpsimumu_tight;
      fHandles[ "EF_mu6_MSonly" ] = &EF_mu6_MSonly;
// -- slimmed --       fHandles[ "EF_mu6_Trk_Jpsi_loose" ] = &EF_mu6_Trk_Jpsi_loose;
      fHandles[ "EF_mu8" ] = &EF_mu8;
      fHandles[ "EF_mu8_4j45_a4tchad_L2FS" ] = &EF_mu8_4j45_a4tchad_L2FS;

      // =============================================================================
      // = from MC D3PD
      // =============================================================================
// -- slimmed --       fHandles[ "EF_2g15vh_loose_g10_loose" ] = &EF_2g15vh_loose_g10_loose;
// -- slimmed --       fHandles[ "EF_2g15vh_medium" ] = &EF_2g15vh_medium;
// -- slimmed --       fHandles[ "EF_2g20_loose" ] = &EF_2g20_loose;
// -- slimmed --       fHandles[ "EF_2g30_loose" ] = &EF_2g30_loose;
// -- slimmed --       fHandles[ "EF_2mu10_MSonly_g10_loose_EMPTY" ] = &EF_2mu10_MSonly_g10_loose_EMPTY;
// -- slimmed --       fHandles[ "EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO" ] = &EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO;
      fHandles[ "EF_2mu4T_xe50_tclcw" ] = &EF_2mu4T_xe50_tclcw;
      fHandles[ "EF_e12Tvh_loose1_mu8" ] = &EF_e12Tvh_loose1_mu8;
      fHandles[ "EF_e12Tvh_medium1_mu10" ] = &EF_e12Tvh_medium1_mu10;
      fHandles[ "EF_e12Tvh_medium1_mu6" ] = &EF_e12Tvh_medium1_mu6;
// -- slimmed --       fHandles[ "EF_e18_loose1_g35_loose" ] = &EF_e18_loose1_g35_loose;
// -- slimmed --       fHandles[ "EF_e18_loose1_g35_medium" ] = &EF_e18_loose1_g35_medium;
// -- slimmed --       fHandles[ "EF_e18_medium1_g25_medium" ] = &EF_e18_medium1_g25_medium;
// -- slimmed --       fHandles[ "EF_e18_medium1_g35_loose" ] = &EF_e18_medium1_g35_loose;
// -- slimmed --       fHandles[ "EF_e18_medium1_g35_medium" ] = &EF_e18_medium1_g35_medium;
      fHandles[ "EF_e22vh_medium1_IdScan" ] = &EF_e22vh_medium1_IdScan;
      fHandles[ "EF_e22vh_medium1_SiTrk" ] = &EF_e22vh_medium1_SiTrk;
      fHandles[ "EF_e22vh_medium1_TRT" ] = &EF_e22vh_medium1_TRT;
      fHandles[ "EF_e45_etcut" ] = &EF_e45_etcut;
// -- slimmed --       fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_IdScan" ] = &EF_e5_tight1_e4_etcut_Jpsi_IdScan;
// -- slimmed --       fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_SiTrk" ] = &EF_e5_tight1_e4_etcut_Jpsi_SiTrk;
// -- slimmed --       fHandles[ "EF_e5_tight1_e4_etcut_Jpsi_TRT" ] = &EF_e5_tight1_e4_etcut_Jpsi_TRT;
      fHandles[ "EF_e60_etcut" ] = &EF_e60_etcut;
// -- slimmed --       fHandles[ "EF_g12Tvh_medium" ] = &EF_g12Tvh_medium;
// -- slimmed --       fHandles[ "EF_g15vh_loose" ] = &EF_g15vh_loose;
// -- slimmed --       fHandles[ "EF_g20Tvh_medium" ] = &EF_g20Tvh_medium;
// -- slimmed --       fHandles[ "EF_g20vh_medium" ] = &EF_g20vh_medium;
// -- slimmed --       fHandles[ "EF_g40_loose_EFxe50" ] = &EF_g40_loose_EFxe50;
// -- slimmed --       fHandles[ "EF_g40_loose_L2EFxe50" ] = &EF_g40_loose_L2EFxe50;
// -- slimmed --       fHandles[ "EF_mu10i_g10_loose" ] = &EF_mu10i_g10_loose;
// -- slimmed --       fHandles[ "EF_mu10i_g10_loose_TauMass" ] = &EF_mu10i_g10_loose_TauMass;
// -- slimmed --       fHandles[ "EF_mu10i_loose_g12Tvh_loose" ] = &EF_mu10i_loose_g12Tvh_loose;
// -- slimmed --       fHandles[ "EF_mu10i_loose_g12Tvh_loose_TauMass" ] = &EF_mu10i_loose_g12Tvh_loose_TauMass;
// -- slimmed --       fHandles[ "EF_mu18_2g15_loose" ] = &EF_mu18_2g15_loose;
// -- slimmed --       fHandles[ "EF_mu18_g20vh_loose" ] = &EF_mu18_g20vh_loose;
      fHandles[ "EF_mu18it_tight" ] = &EF_mu18it_tight;
// -- slimmed --       fHandles[ "EF_mu20i_tight_g5_loose" ] = &EF_mu20i_tight_g5_loose;
      fHandles[ "EF_mu24_j65_a4tchad_EFxe50_tclcw" ] = &EF_mu24_j65_a4tchad_EFxe50_tclcw;
      fHandles[ "EF_mu24_tight_2j35_a4tchad" ] = &EF_mu24_tight_2j35_a4tchad;
      fHandles[ "EF_mu24_tight_4j35_a4tchad" ] = &EF_mu24_tight_4j35_a4tchad;
// -- slimmed --       fHandles[ "EF_mu4T_Trk_Jpsi" ] = &EF_mu4T_Trk_Jpsi;
      fHandles[ "EF_mu4T_j360_a4tchad_L2FS_matched" ] = &EF_mu4T_j360_a4tchad_L2FS_matched;
      fHandles[ "EF_mu4T_j360_a4tchad_matched" ] = &EF_mu4T_j360_a4tchad_matched;
// -- slimmed --       fHandles[ "EF_mu4Ti_g20Tvh_loose" ] = &EF_mu4Ti_g20Tvh_loose;
// -- slimmed --       fHandles[ "EF_mu4Ti_g20Tvh_loose_TauMass" ] = &EF_mu4Ti_g20Tvh_loose_TauMass;
      fHandles[ "EF_mu6i" ] = &EF_mu6i;
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* TriggerD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void TriggerD3PDObject::SetPrefix( const char* prefix ) {

      EF_2e12Tvh_loose1.SetName( ::TString( prefix ) + "EF_2e12Tvh_loose1" );
// -- slimmed --       EF_2e5_tight1_Jpsi.SetName( ::TString( prefix ) + "EF_2e5_tight1_Jpsi" );
      EF_2e7T_loose1_mu6.SetName( ::TString( prefix ) + "EF_2e7T_loose1_mu6" );
      EF_2e7T_medium1_mu6.SetName( ::TString( prefix ) + "EF_2e7T_medium1_mu6" );
// -- slimmed --       EF_2g15vh_medium_g10_medium.SetName( ::TString( prefix ) + "EF_2g15vh_medium_g10_medium" );
// -- slimmed --       EF_2g20vh_medium.SetName( ::TString( prefix ) + "EF_2g20vh_medium" );
// -- slimmed --       EF_2g40_loose.SetName( ::TString( prefix ) + "EF_2g40_loose" );
      EF_2mu10.SetName( ::TString( prefix ) + "EF_2mu10" );
// -- slimmed --       EF_2mu10_MSonly_g10_loose.SetName( ::TString( prefix ) + "EF_2mu10_MSonly_g10_loose" );
      EF_2mu13.SetName( ::TString( prefix ) + "EF_2mu13" );
      EF_2mu13_Zmumu_IDTrkNoCut.SetName( ::TString( prefix ) + "EF_2mu13_Zmumu_IDTrkNoCut" );
      EF_2mu13_l2muonSA.SetName( ::TString( prefix ) + "EF_2mu13_l2muonSA" );
      EF_2mu15.SetName( ::TString( prefix ) + "EF_2mu15" );
      EF_2mu4T.SetName( ::TString( prefix ) + "EF_2mu4T" );
      EF_2mu4T_2e5_tight1.SetName( ::TString( prefix ) + "EF_2mu4T_2e5_tight1" );
      EF_2mu4T_Bmumu.SetName( ::TString( prefix ) + "EF_2mu4T_Bmumu" );
      EF_2mu4T_Bmumu_Barrel.SetName( ::TString( prefix ) + "EF_2mu4T_Bmumu_Barrel" );
      EF_2mu4T_Bmumu_BarrelOnly.SetName( ::TString( prefix ) + "EF_2mu4T_Bmumu_BarrelOnly" );
      EF_2mu4T_Bmumux.SetName( ::TString( prefix ) + "EF_2mu4T_Bmumux" );
      EF_2mu4T_Bmumux_Barrel.SetName( ::TString( prefix ) + "EF_2mu4T_Bmumux_Barrel" );
      EF_2mu4T_Bmumux_BarrelOnly.SetName( ::TString( prefix ) + "EF_2mu4T_Bmumux_BarrelOnly" );
      EF_2mu4T_DiMu.SetName( ::TString( prefix ) + "EF_2mu4T_DiMu" );
      EF_2mu4T_DiMu_Barrel.SetName( ::TString( prefix ) + "EF_2mu4T_DiMu_Barrel" );
      EF_2mu4T_DiMu_BarrelOnly.SetName( ::TString( prefix ) + "EF_2mu4T_DiMu_BarrelOnly" );
      EF_2mu4T_DiMu_L2StarB.SetName( ::TString( prefix ) + "EF_2mu4T_DiMu_L2StarB" );
      EF_2mu4T_DiMu_L2StarC.SetName( ::TString( prefix ) + "EF_2mu4T_DiMu_L2StarC" );
      EF_2mu4T_DiMu_e5_tight1.SetName( ::TString( prefix ) + "EF_2mu4T_DiMu_e5_tight1" );
      EF_2mu4T_DiMu_l2muonSA.SetName( ::TString( prefix ) + "EF_2mu4T_DiMu_l2muonSA" );
      EF_2mu4T_DiMu_noVtx_noOS.SetName( ::TString( prefix ) + "EF_2mu4T_DiMu_noVtx_noOS" );
// -- slimmed --       EF_2mu4T_Jpsimumu.SetName( ::TString( prefix ) + "EF_2mu4T_Jpsimumu" );
// -- slimmed --       EF_2mu4T_Jpsimumu_Barrel.SetName( ::TString( prefix ) + "EF_2mu4T_Jpsimumu_Barrel" );
// -- slimmed --       EF_2mu4T_Jpsimumu_BarrelOnly.SetName( ::TString( prefix ) + "EF_2mu4T_Jpsimumu_BarrelOnly" );
// -- slimmed --       EF_2mu4T_Jpsimumu_IDTrkNoCut.SetName( ::TString( prefix ) + "EF_2mu4T_Jpsimumu_IDTrkNoCut" );
// -- slimmed --       EF_2mu4T_Upsimumu.SetName( ::TString( prefix ) + "EF_2mu4T_Upsimumu" );
// -- slimmed --       EF_2mu4T_Upsimumu_Barrel.SetName( ::TString( prefix ) + "EF_2mu4T_Upsimumu_Barrel" );
// -- slimmed --       EF_2mu4T_Upsimumu_BarrelOnly.SetName( ::TString( prefix ) + "EF_2mu4T_Upsimumu_BarrelOnly" );
      EF_2mu4T_xe60.SetName( ::TString( prefix ) + "EF_2mu4T_xe60" );
      EF_2mu4T_xe60_tclcw.SetName( ::TString( prefix ) + "EF_2mu4T_xe60_tclcw" );
      EF_2mu6.SetName( ::TString( prefix ) + "EF_2mu6" );
      EF_2mu6_Bmumu.SetName( ::TString( prefix ) + "EF_2mu6_Bmumu" );
      EF_2mu6_Bmumux.SetName( ::TString( prefix ) + "EF_2mu6_Bmumux" );
      EF_2mu6_DiMu.SetName( ::TString( prefix ) + "EF_2mu6_DiMu" );
      EF_2mu6_DiMu_DY20.SetName( ::TString( prefix ) + "EF_2mu6_DiMu_DY20" );
      EF_2mu6_DiMu_DY25.SetName( ::TString( prefix ) + "EF_2mu6_DiMu_DY25" );
      EF_2mu6_DiMu_noVtx_noOS.SetName( ::TString( prefix ) + "EF_2mu6_DiMu_noVtx_noOS" );
// -- slimmed --       EF_2mu6_Jpsimumu.SetName( ::TString( prefix ) + "EF_2mu6_Jpsimumu" );
// -- slimmed --       EF_2mu6_Upsimumu.SetName( ::TString( prefix ) + "EF_2mu6_Upsimumu" );
      EF_2mu6i_DiMu_DY.SetName( ::TString( prefix ) + "EF_2mu6i_DiMu_DY" );
      EF_2mu6i_DiMu_DY_2j25_a4tchad.SetName( ::TString( prefix ) + "EF_2mu6i_DiMu_DY_2j25_a4tchad" );
      EF_2mu6i_DiMu_DY_noVtx_noOS.SetName( ::TString( prefix ) + "EF_2mu6i_DiMu_DY_noVtx_noOS" );
      EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad.SetName( ::TString( prefix ) + "EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad" );
      EF_2mu8_EFxe30.SetName( ::TString( prefix ) + "EF_2mu8_EFxe30" );
      EF_2mu8_EFxe30_tclcw.SetName( ::TString( prefix ) + "EF_2mu8_EFxe30_tclcw" );
      EF_e11_etcut.SetName( ::TString( prefix ) + "EF_e11_etcut" );
      EF_e12Tvh_loose1.SetName( ::TString( prefix ) + "EF_e12Tvh_loose1" );
      EF_e12Tvh_medium1.SetName( ::TString( prefix ) + "EF_e12Tvh_medium1" );
      EF_e12Tvh_medium1_mu6_topo_medium.SetName( ::TString( prefix ) + "EF_e12Tvh_medium1_mu6_topo_medium" );
      EF_e12Tvh_medium1_mu8.SetName( ::TString( prefix ) + "EF_e12Tvh_medium1_mu8" );
      EF_e13_etcutTrk_xs60.SetName( ::TString( prefix ) + "EF_e13_etcutTrk_xs60" );
      EF_e13_etcutTrk_xs60_dphi2j15xe20.SetName( ::TString( prefix ) + "EF_e13_etcutTrk_xs60_dphi2j15xe20" );
// -- slimmed --       EF_e14_tight1_e4_etcut_Jpsi.SetName( ::TString( prefix ) + "EF_e14_tight1_e4_etcut_Jpsi" );
      EF_e15vh_medium1.SetName( ::TString( prefix ) + "EF_e15vh_medium1" );
      EF_e18_loose1.SetName( ::TString( prefix ) + "EF_e18_loose1" );
// -- slimmed --       EF_e18_loose1_g25_medium.SetName( ::TString( prefix ) + "EF_e18_loose1_g25_medium" );
      EF_e18_medium1.SetName( ::TString( prefix ) + "EF_e18_medium1" );
// -- slimmed --       EF_e18_medium1_g25_loose.SetName( ::TString( prefix ) + "EF_e18_medium1_g25_loose" );
      EF_e18vh_medium1.SetName( ::TString( prefix ) + "EF_e18vh_medium1" );
      EF_e18vh_medium1_2e7T_medium1.SetName( ::TString( prefix ) + "EF_e18vh_medium1_2e7T_medium1" );
      EF_e20_etcutTrk_xe30_dphi2j15xe20.SetName( ::TString( prefix ) + "EF_e20_etcutTrk_xe30_dphi2j15xe20" );
      EF_e20_etcutTrk_xs60_dphi2j15xe20.SetName( ::TString( prefix ) + "EF_e20_etcutTrk_xs60_dphi2j15xe20" );
// -- slimmed -- // -- slimmed --       EF_e20vhT_medium1_g6T_etcut_Upsi.SetName( ::TString( prefix ) + "EF_e20vhT_medium1_g6T_etcut_Upsi" );
// -- slimmed -- // -- slimmed --       EF_e20vhT_tight1_g6T_etcut_Upsi.SetName( ::TString( prefix ) + "EF_e20vhT_tight1_g6T_etcut_Upsi" );
      EF_e22vh_loose.SetName( ::TString( prefix ) + "EF_e22vh_loose" );
      EF_e22vh_loose0.SetName( ::TString( prefix ) + "EF_e22vh_loose0" );
      EF_e22vh_loose1.SetName( ::TString( prefix ) + "EF_e22vh_loose1" );
      EF_e22vh_medium1.SetName( ::TString( prefix ) + "EF_e22vh_medium1" );
      EF_e22vh_medium1_IDTrkNoCut.SetName( ::TString( prefix ) + "EF_e22vh_medium1_IDTrkNoCut" );
      EF_e22vhi_medium1.SetName( ::TString( prefix ) + "EF_e22vhi_medium1" );
      EF_e24vh_loose.SetName( ::TString( prefix ) + "EF_e24vh_loose" );
      EF_e24vh_loose0.SetName( ::TString( prefix ) + "EF_e24vh_loose0" );
      EF_e24vh_loose1.SetName( ::TString( prefix ) + "EF_e24vh_loose1" );
      EF_e24vh_medium1.SetName( ::TString( prefix ) + "EF_e24vh_medium1" );
      EF_e24vh_medium1_EFxe30.SetName( ::TString( prefix ) + "EF_e24vh_medium1_EFxe30" );
      EF_e24vh_medium1_EFxe30_tcem.SetName( ::TString( prefix ) + "EF_e24vh_medium1_EFxe30_tcem" );
      EF_e24vh_medium1_EFxe35_tcem.SetName( ::TString( prefix ) + "EF_e24vh_medium1_EFxe35_tcem" );
      EF_e24vh_medium1_EFxe35_tclcw.SetName( ::TString( prefix ) + "EF_e24vh_medium1_EFxe35_tclcw" );
      EF_e24vh_medium1_EFxe40.SetName( ::TString( prefix ) + "EF_e24vh_medium1_EFxe40" );
      EF_e24vh_medium1_IDTrkNoCut.SetName( ::TString( prefix ) + "EF_e24vh_medium1_IDTrkNoCut" );
      EF_e24vh_medium1_IdScan.SetName( ::TString( prefix ) + "EF_e24vh_medium1_IdScan" );
      EF_e24vh_medium1_L2StarB.SetName( ::TString( prefix ) + "EF_e24vh_medium1_L2StarB" );
      EF_e24vh_medium1_L2StarC.SetName( ::TString( prefix ) + "EF_e24vh_medium1_L2StarC" );
      EF_e24vh_medium1_SiTrk.SetName( ::TString( prefix ) + "EF_e24vh_medium1_SiTrk" );
      EF_e24vh_medium1_TRT.SetName( ::TString( prefix ) + "EF_e24vh_medium1_TRT" );
      EF_e24vh_medium1_b35_mediumEF_j35_a4tchad.SetName( ::TString( prefix ) + "EF_e24vh_medium1_b35_mediumEF_j35_a4tchad" );
      EF_e24vh_medium1_e7_medium1.SetName( ::TString( prefix ) + "EF_e24vh_medium1_e7_medium1" );
      EF_e24vh_tight1_e15_NoCut_Zee.SetName( ::TString( prefix ) + "EF_e24vh_tight1_e15_NoCut_Zee" );
      EF_e24vhi_loose1_mu8.SetName( ::TString( prefix ) + "EF_e24vhi_loose1_mu8" );
      EF_e24vhi_medium1.SetName( ::TString( prefix ) + "EF_e24vhi_medium1" );
      EF_e45_medium1.SetName( ::TString( prefix ) + "EF_e45_medium1" );
      EF_e5_tight1.SetName( ::TString( prefix ) + "EF_e5_tight1" );
// -- slimmed --       EF_e5_tight1_e14_etcut_Jpsi.SetName( ::TString( prefix ) + "EF_e5_tight1_e14_etcut_Jpsi" );
// -- slimmed --       EF_e5_tight1_e4_etcut_Jpsi.SetName( ::TString( prefix ) + "EF_e5_tight1_e4_etcut_Jpsi" );
// -- slimmed --       EF_e5_tight1_e4_etcut_Jpsi_L2StarB.SetName( ::TString( prefix ) + "EF_e5_tight1_e4_etcut_Jpsi_L2StarB" );
// -- slimmed --       EF_e5_tight1_e4_etcut_Jpsi_L2StarC.SetName( ::TString( prefix ) + "EF_e5_tight1_e4_etcut_Jpsi_L2StarC" );
      EF_e5_tight1_e5_NoCut.SetName( ::TString( prefix ) + "EF_e5_tight1_e5_NoCut" );
// -- slimmed --       EF_e5_tight1_e9_etcut_Jpsi.SetName( ::TString( prefix ) + "EF_e5_tight1_e9_etcut_Jpsi" );
      EF_e60_medium1.SetName( ::TString( prefix ) + "EF_e60_medium1" );
      EF_e7T_loose1.SetName( ::TString( prefix ) + "EF_e7T_loose1" );
      EF_e7T_loose1_2mu6.SetName( ::TString( prefix ) + "EF_e7T_loose1_2mu6" );
      EF_e7T_medium1.SetName( ::TString( prefix ) + "EF_e7T_medium1" );
      EF_e7T_medium1_2mu6.SetName( ::TString( prefix ) + "EF_e7T_medium1_2mu6" );
// -- slimmed --       EF_e9_tight1_e4_etcut_Jpsi.SetName( ::TString( prefix ) + "EF_e9_tight1_e4_etcut_Jpsi" );
      EF_eb_physics.SetName( ::TString( prefix ) + "EF_eb_physics" );
      EF_eb_physics_empty.SetName( ::TString( prefix ) + "EF_eb_physics_empty" );
      EF_eb_physics_firstempty.SetName( ::TString( prefix ) + "EF_eb_physics_firstempty" );
      EF_eb_physics_noL1PS.SetName( ::TString( prefix ) + "EF_eb_physics_noL1PS" );
      EF_eb_physics_unpaired_iso.SetName( ::TString( prefix ) + "EF_eb_physics_unpaired_iso" );
      EF_eb_physics_unpaired_noniso.SetName( ::TString( prefix ) + "EF_eb_physics_unpaired_noniso" );
      EF_eb_random.SetName( ::TString( prefix ) + "EF_eb_random" );
      EF_eb_random_empty.SetName( ::TString( prefix ) + "EF_eb_random_empty" );
      EF_eb_random_firstempty.SetName( ::TString( prefix ) + "EF_eb_random_firstempty" );
      EF_eb_random_unpaired_iso.SetName( ::TString( prefix ) + "EF_eb_random_unpaired_iso" );
// -- slimmed --       EF_g100_loose.SetName( ::TString( prefix ) + "EF_g100_loose" );
// -- slimmed --       EF_g10_NoCut_cosmic.SetName( ::TString( prefix ) + "EF_g10_NoCut_cosmic" );
// -- slimmed --       EF_g10_loose.SetName( ::TString( prefix ) + "EF_g10_loose" );
// -- slimmed --       EF_g10_medium.SetName( ::TString( prefix ) + "EF_g10_medium" );
// -- slimmed --       EF_g120_loose.SetName( ::TString( prefix ) + "EF_g120_loose" );
// -- slimmed --       EF_g12Tvh_loose.SetName( ::TString( prefix ) + "EF_g12Tvh_loose" );
// -- slimmed --       EF_g12Tvh_loose_larcalib.SetName( ::TString( prefix ) + "EF_g12Tvh_loose_larcalib" );
// -- slimmed --       EF_g15_loose.SetName( ::TString( prefix ) + "EF_g15_loose" );
// -- slimmed --       EF_g15vh_medium.SetName( ::TString( prefix ) + "EF_g15vh_medium" );
// -- slimmed --       EF_g200_etcut.SetName( ::TString( prefix ) + "EF_g200_etcut" );
// -- slimmed --       EF_g20_etcut.SetName( ::TString( prefix ) + "EF_g20_etcut" );
// -- slimmed --       EF_g20_loose.SetName( ::TString( prefix ) + "EF_g20_loose" );
// -- slimmed --       EF_g20_loose_larcalib.SetName( ::TString( prefix ) + "EF_g20_loose_larcalib" );
// -- slimmed --       EF_g20_medium.SetName( ::TString( prefix ) + "EF_g20_medium" );
// -- slimmed --       EF_g30_loose_g20_loose.SetName( ::TString( prefix ) + "EF_g30_loose_g20_loose" );
// -- slimmed --       EF_g30_medium_g20_medium.SetName( ::TString( prefix ) + "EF_g30_medium_g20_medium" );
// -- slimmed --       EF_g35_loose_g25_loose.SetName( ::TString( prefix ) + "EF_g35_loose_g25_loose" );
// -- slimmed --       EF_g35_loose_g30_loose.SetName( ::TString( prefix ) + "EF_g35_loose_g30_loose" );
// -- slimmed --       EF_g40_loose.SetName( ::TString( prefix ) + "EF_g40_loose" );
// -- slimmed --       EF_g40_loose_L2EFxe60.SetName( ::TString( prefix ) + "EF_g40_loose_L2EFxe60" );
// -- slimmed --       EF_g40_loose_L2EFxe60_tclcw.SetName( ::TString( prefix ) + "EF_g40_loose_L2EFxe60_tclcw" );
// -- slimmed --       EF_g40_loose_g25_loose.SetName( ::TString( prefix ) + "EF_g40_loose_g25_loose" );
// -- slimmed --       EF_g40_loose_g30_loose.SetName( ::TString( prefix ) + "EF_g40_loose_g30_loose" );
// -- slimmed --       EF_g40_loose_larcalib.SetName( ::TString( prefix ) + "EF_g40_loose_larcalib" );
// -- slimmed --       EF_g5_NoCut_cosmic.SetName( ::TString( prefix ) + "EF_g5_NoCut_cosmic" );
// -- slimmed --       EF_g60_loose.SetName( ::TString( prefix ) + "EF_g60_loose" );
// -- slimmed --       EF_g60_loose_larcalib.SetName( ::TString( prefix ) + "EF_g60_loose_larcalib" );
// -- slimmed --       EF_g80_loose.SetName( ::TString( prefix ) + "EF_g80_loose" );
// -- slimmed --       EF_g80_loose_larcalib.SetName( ::TString( prefix ) + "EF_g80_loose_larcalib" );
      EF_mu10.SetName( ::TString( prefix ) + "EF_mu10" );
// -- slimmed --       EF_mu10_Jpsimumu.SetName( ::TString( prefix ) + "EF_mu10_Jpsimumu" );
      EF_mu10_MSonly.SetName( ::TString( prefix ) + "EF_mu10_MSonly" );
// -- slimmed --       EF_mu10_Upsimumu_tight_FS.SetName( ::TString( prefix ) + "EF_mu10_Upsimumu_tight_FS" );
// -- slimmed --       EF_mu10i_g10_medium.SetName( ::TString( prefix ) + "EF_mu10i_g10_medium" );
// -- slimmed --       EF_mu10i_g10_medium_TauMass.SetName( ::TString( prefix ) + "EF_mu10i_g10_medium_TauMass" );
// -- slimmed --       EF_mu10i_loose_g12Tvh_medium.SetName( ::TString( prefix ) + "EF_mu10i_loose_g12Tvh_medium" );
// -- slimmed --       EF_mu10i_loose_g12Tvh_medium_TauMass.SetName( ::TString( prefix ) + "EF_mu10i_loose_g12Tvh_medium_TauMass" );
      EF_mu11_empty_NoAlg.SetName( ::TString( prefix ) + "EF_mu11_empty_NoAlg" );
      EF_mu13.SetName( ::TString( prefix ) + "EF_mu13" );
      EF_mu15.SetName( ::TString( prefix ) + "EF_mu15" );
      EF_mu18.SetName( ::TString( prefix ) + "EF_mu18" );
// -- slimmed --       EF_mu18_2g10_loose.SetName( ::TString( prefix ) + "EF_mu18_2g10_loose" );
// -- slimmed --       EF_mu18_2g10_medium.SetName( ::TString( prefix ) + "EF_mu18_2g10_medium" );
      EF_mu18_IDTrkNoCut_tight.SetName( ::TString( prefix ) + "EF_mu18_IDTrkNoCut_tight" );
      EF_mu18_medium.SetName( ::TString( prefix ) + "EF_mu18_medium" );
      EF_mu18_tight.SetName( ::TString( prefix ) + "EF_mu18_tight" );
      EF_mu18_tight_2mu4_EFFS.SetName( ::TString( prefix ) + "EF_mu18_tight_2mu4_EFFS" );
      EF_mu18_tight_e7_medium1.SetName( ::TString( prefix ) + "EF_mu18_tight_e7_medium1" );
      EF_mu18_tight_mu8_EFFS.SetName( ::TString( prefix ) + "EF_mu18_tight_mu8_EFFS" );
      EF_mu18i4_tight.SetName( ::TString( prefix ) + "EF_mu18i4_tight" );
// -- slimmed --       EF_mu20i_tight_g5_loose_TauMass.SetName( ::TString( prefix ) + "EF_mu20i_tight_g5_loose_TauMass" );
// -- slimmed --       EF_mu20i_tight_g5_medium.SetName( ::TString( prefix ) + "EF_mu20i_tight_g5_medium" );
// -- slimmed --       EF_mu20i_tight_g5_medium_TauMass.SetName( ::TString( prefix ) + "EF_mu20i_tight_g5_medium_TauMass" );
      EF_mu20it_tight.SetName( ::TString( prefix ) + "EF_mu20it_tight" );
      EF_mu22_IDTrkNoCut_tight.SetName( ::TString( prefix ) + "EF_mu22_IDTrkNoCut_tight" );
      EF_mu24.SetName( ::TString( prefix ) + "EF_mu24" );
// -- slimmed --       EF_mu24_g20vh_loose.SetName( ::TString( prefix ) + "EF_mu24_g20vh_loose" );
// -- slimmed --       EF_mu24_g20vh_medium.SetName( ::TString( prefix ) + "EF_mu24_g20vh_medium" );
      EF_mu24_j65_a4tchad.SetName( ::TString( prefix ) + "EF_mu24_j65_a4tchad" );
      EF_mu24_j65_a4tchad_EFxe40.SetName( ::TString( prefix ) + "EF_mu24_j65_a4tchad_EFxe40" );
      EF_mu24_j65_a4tchad_EFxe40_tclcw.SetName( ::TString( prefix ) + "EF_mu24_j65_a4tchad_EFxe40_tclcw" );
      EF_mu24_j65_a4tchad_EFxe60_tclcw.SetName( ::TString( prefix ) + "EF_mu24_j65_a4tchad_EFxe60_tclcw" );
      EF_mu24_medium.SetName( ::TString( prefix ) + "EF_mu24_medium" );
      EF_mu24_muCombTag_NoEF_tight.SetName( ::TString( prefix ) + "EF_mu24_muCombTag_NoEF_tight" );
      EF_mu24_tight.SetName( ::TString( prefix ) + "EF_mu24_tight" );
      EF_mu24_tight_3j35_a4tchad.SetName( ::TString( prefix ) + "EF_mu24_tight_3j35_a4tchad" );
      EF_mu24_tight_EFxe40.SetName( ::TString( prefix ) + "EF_mu24_tight_EFxe40" );
      EF_mu24_tight_L2StarB.SetName( ::TString( prefix ) + "EF_mu24_tight_L2StarB" );
      EF_mu24_tight_L2StarC.SetName( ::TString( prefix ) + "EF_mu24_tight_L2StarC" );
      EF_mu24_tight_MG.SetName( ::TString( prefix ) + "EF_mu24_tight_MG" );
      EF_mu24_tight_MuonEF.SetName( ::TString( prefix ) + "EF_mu24_tight_MuonEF" );
      EF_mu24_tight_b35_mediumEF_j35_a4tchad.SetName( ::TString( prefix ) + "EF_mu24_tight_b35_mediumEF_j35_a4tchad" );
      EF_mu24_tight_mu6_EFFS.SetName( ::TString( prefix ) + "EF_mu24_tight_mu6_EFFS" );
      EF_mu24i_tight.SetName( ::TString( prefix ) + "EF_mu24i_tight" );
      EF_mu24i_tight_MG.SetName( ::TString( prefix ) + "EF_mu24i_tight_MG" );
      EF_mu24i_tight_MuonEF.SetName( ::TString( prefix ) + "EF_mu24i_tight_MuonEF" );
      EF_mu24i_tight_l2muonSA.SetName( ::TString( prefix ) + "EF_mu24i_tight_l2muonSA" );
      EF_mu36_tight.SetName( ::TString( prefix ) + "EF_mu36_tight" );
      EF_mu40_MSonly_barrel_tight.SetName( ::TString( prefix ) + "EF_mu40_MSonly_barrel_tight" );
      EF_mu40_muCombTag_NoEF.SetName( ::TString( prefix ) + "EF_mu40_muCombTag_NoEF" );
      EF_mu40_slow_outOfTime_tight.SetName( ::TString( prefix ) + "EF_mu40_slow_outOfTime_tight" );
      EF_mu40_slow_tight.SetName( ::TString( prefix ) + "EF_mu40_slow_tight" );
      EF_mu40_tight.SetName( ::TString( prefix ) + "EF_mu40_tight" );
      EF_mu4T.SetName( ::TString( prefix ) + "EF_mu4T" );
      EF_mu4T_cosmic.SetName( ::TString( prefix ) + "EF_mu4T_cosmic" );
      EF_mu4T_j110_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "EF_mu4T_j110_a4tchad_L2FS_matched" );
      EF_mu4T_j110_a4tchad_matched.SetName( ::TString( prefix ) + "EF_mu4T_j110_a4tchad_matched" );
      EF_mu4T_j145_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "EF_mu4T_j145_a4tchad_L2FS_matched" );
      EF_mu4T_j145_a4tchad_matched.SetName( ::TString( prefix ) + "EF_mu4T_j145_a4tchad_matched" );
      EF_mu4T_j15_a4tchad_matched.SetName( ::TString( prefix ) + "EF_mu4T_j15_a4tchad_matched" );
      EF_mu4T_j15_a4tchad_matchedZ.SetName( ::TString( prefix ) + "EF_mu4T_j15_a4tchad_matchedZ" );
      EF_mu4T_j180_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "EF_mu4T_j180_a4tchad_L2FS_matched" );
      EF_mu4T_j180_a4tchad_matched.SetName( ::TString( prefix ) + "EF_mu4T_j180_a4tchad_matched" );
      EF_mu4T_j220_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "EF_mu4T_j220_a4tchad_L2FS_matched" );
      EF_mu4T_j220_a4tchad_matched.SetName( ::TString( prefix ) + "EF_mu4T_j220_a4tchad_matched" );
      EF_mu4T_j25_a4tchad_matched.SetName( ::TString( prefix ) + "EF_mu4T_j25_a4tchad_matched" );
      EF_mu4T_j25_a4tchad_matchedZ.SetName( ::TString( prefix ) + "EF_mu4T_j25_a4tchad_matchedZ" );
      EF_mu4T_j280_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "EF_mu4T_j280_a4tchad_L2FS_matched" );
      EF_mu4T_j280_a4tchad_matched.SetName( ::TString( prefix ) + "EF_mu4T_j280_a4tchad_matched" );
      EF_mu4T_j35_a4tchad_matched.SetName( ::TString( prefix ) + "EF_mu4T_j35_a4tchad_matched" );
      EF_mu4T_j35_a4tchad_matchedZ.SetName( ::TString( prefix ) + "EF_mu4T_j35_a4tchad_matchedZ" );
      EF_mu4T_j45_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "EF_mu4T_j45_a4tchad_L2FS_matched" );
      EF_mu4T_j45_a4tchad_L2FS_matchedZ.SetName( ::TString( prefix ) + "EF_mu4T_j45_a4tchad_L2FS_matchedZ" );
      EF_mu4T_j45_a4tchad_matched.SetName( ::TString( prefix ) + "EF_mu4T_j45_a4tchad_matched" );
      EF_mu4T_j45_a4tchad_matchedZ.SetName( ::TString( prefix ) + "EF_mu4T_j45_a4tchad_matchedZ" );
      EF_mu4T_j55_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "EF_mu4T_j55_a4tchad_L2FS_matched" );
      EF_mu4T_j55_a4tchad_L2FS_matchedZ.SetName( ::TString( prefix ) + "EF_mu4T_j55_a4tchad_L2FS_matchedZ" );
      EF_mu4T_j55_a4tchad_matched.SetName( ::TString( prefix ) + "EF_mu4T_j55_a4tchad_matched" );
      EF_mu4T_j55_a4tchad_matchedZ.SetName( ::TString( prefix ) + "EF_mu4T_j55_a4tchad_matchedZ" );
      EF_mu4T_j65_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "EF_mu4T_j65_a4tchad_L2FS_matched" );
      EF_mu4T_j65_a4tchad_matched.SetName( ::TString( prefix ) + "EF_mu4T_j65_a4tchad_matched" );
      EF_mu4T_j65_a4tchad_xe60_tclcw_loose.SetName( ::TString( prefix ) + "EF_mu4T_j65_a4tchad_xe60_tclcw_loose" );
      EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose.SetName( ::TString( prefix ) + "EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose" );
      EF_mu4T_j80_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "EF_mu4T_j80_a4tchad_L2FS_matched" );
      EF_mu4T_j80_a4tchad_matched.SetName( ::TString( prefix ) + "EF_mu4T_j80_a4tchad_matched" );
// -- slimmed --       EF_mu4Ti_g20Tvh_medium.SetName( ::TString( prefix ) + "EF_mu4Ti_g20Tvh_medium" );
// -- slimmed --       EF_mu4Ti_g20Tvh_medium_TauMass.SetName( ::TString( prefix ) + "EF_mu4Ti_g20Tvh_medium_TauMass" );
      EF_mu4Tmu6_Bmumu.SetName( ::TString( prefix ) + "EF_mu4Tmu6_Bmumu" );
      EF_mu4Tmu6_Bmumu_Barrel.SetName( ::TString( prefix ) + "EF_mu4Tmu6_Bmumu_Barrel" );
      EF_mu4Tmu6_Bmumux.SetName( ::TString( prefix ) + "EF_mu4Tmu6_Bmumux" );
      EF_mu4Tmu6_Bmumux_Barrel.SetName( ::TString( prefix ) + "EF_mu4Tmu6_Bmumux_Barrel" );
      EF_mu4Tmu6_DiMu.SetName( ::TString( prefix ) + "EF_mu4Tmu6_DiMu" );
      EF_mu4Tmu6_DiMu_Barrel.SetName( ::TString( prefix ) + "EF_mu4Tmu6_DiMu_Barrel" );
      EF_mu4Tmu6_DiMu_noVtx_noOS.SetName( ::TString( prefix ) + "EF_mu4Tmu6_DiMu_noVtx_noOS" );
// -- slimmed --       EF_mu4Tmu6_Jpsimumu.SetName( ::TString( prefix ) + "EF_mu4Tmu6_Jpsimumu" );
// -- slimmed --       EF_mu4Tmu6_Jpsimumu_Barrel.SetName( ::TString( prefix ) + "EF_mu4Tmu6_Jpsimumu_Barrel" );
// -- slimmed --       EF_mu4Tmu6_Jpsimumu_IDTrkNoCut.SetName( ::TString( prefix ) + "EF_mu4Tmu6_Jpsimumu_IDTrkNoCut" );
// -- slimmed --       EF_mu4Tmu6_Upsimumu.SetName( ::TString( prefix ) + "EF_mu4Tmu6_Upsimumu" );
// -- slimmed --       EF_mu4Tmu6_Upsimumu_Barrel.SetName( ::TString( prefix ) + "EF_mu4Tmu6_Upsimumu_Barrel" );
      EF_mu4_L1MU11_MSonly_cosmic.SetName( ::TString( prefix ) + "EF_mu4_L1MU11_MSonly_cosmic" );
      EF_mu4_L1MU11_cosmic.SetName( ::TString( prefix ) + "EF_mu4_L1MU11_cosmic" );
      EF_mu4_empty_NoAlg.SetName( ::TString( prefix ) + "EF_mu4_empty_NoAlg" );
      EF_mu4_firstempty_NoAlg.SetName( ::TString( prefix ) + "EF_mu4_firstempty_NoAlg" );
      EF_mu4_unpaired_iso_NoAlg.SetName( ::TString( prefix ) + "EF_mu4_unpaired_iso_NoAlg" );
      EF_mu50_MSonly_barrel_tight.SetName( ::TString( prefix ) + "EF_mu50_MSonly_barrel_tight" );
      EF_mu6.SetName( ::TString( prefix ) + "EF_mu6" );
      EF_mu60_slow_outOfTime_tight1.SetName( ::TString( prefix ) + "EF_mu60_slow_outOfTime_tight1" );
      EF_mu60_slow_tight1.SetName( ::TString( prefix ) + "EF_mu60_slow_tight1" );
// -- slimmed --       EF_mu6_Jpsimumu_tight.SetName( ::TString( prefix ) + "EF_mu6_Jpsimumu_tight" );
      EF_mu6_MSonly.SetName( ::TString( prefix ) + "EF_mu6_MSonly" );
// -- slimmed --       EF_mu6_Trk_Jpsi_loose.SetName( ::TString( prefix ) + "EF_mu6_Trk_Jpsi_loose" );
      EF_mu8.SetName( ::TString( prefix ) + "EF_mu8" );
      EF_mu8_4j45_a4tchad_L2FS.SetName( ::TString( prefix ) + "EF_mu8_4j45_a4tchad_L2FS" );

      // =============================================================================
      // = from MC D3PD
      // =============================================================================
// -- slimmed --       EF_2g15vh_loose_g10_loose.SetName( ::TString( prefix ) + "EF_2g15vh_loose_g10_loose" );
// -- slimmed --       EF_2g15vh_medium.SetName( ::TString( prefix ) + "EF_2g15vh_medium" );
// -- slimmed --       EF_2g20_loose.SetName( ::TString( prefix ) + "EF_2g20_loose" );
// -- slimmed --       EF_2g30_loose.SetName( ::TString( prefix ) + "EF_2g30_loose" );
// -- slimmed --       EF_2mu10_MSonly_g10_loose_EMPTY.SetName( ::TString( prefix ) + "EF_2mu10_MSonly_g10_loose_EMPTY" );
// -- slimmed --       EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO.SetName( ::TString( prefix ) + "EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO" );
      EF_2mu4T_xe50_tclcw.SetName( ::TString( prefix ) + "EF_2mu4T_xe50_tclcw" );
      EF_e12Tvh_loose1_mu8.SetName( ::TString( prefix ) + "EF_e12Tvh_loose1_mu8" );
      EF_e12Tvh_medium1_mu10.SetName( ::TString( prefix ) + "EF_e12Tvh_medium1_mu10" );
      EF_e12Tvh_medium1_mu6.SetName( ::TString( prefix ) + "EF_e12Tvh_medium1_mu6" );
// -- slimmed --       EF_e18_loose1_g35_loose.SetName( ::TString( prefix ) + "EF_e18_loose1_g35_loose" );
// -- slimmed --       EF_e18_loose1_g35_medium.SetName( ::TString( prefix ) + "EF_e18_loose1_g35_medium" );
// -- slimmed --       EF_e18_medium1_g25_medium.SetName( ::TString( prefix ) + "EF_e18_medium1_g25_medium" );
// -- slimmed --       EF_e18_medium1_g35_loose.SetName( ::TString( prefix ) + "EF_e18_medium1_g35_loose" );
// -- slimmed --       EF_e18_medium1_g35_medium.SetName( ::TString( prefix ) + "EF_e18_medium1_g35_medium" );
      EF_e22vh_medium1_IdScan.SetName( ::TString( prefix ) + "EF_e22vh_medium1_IdScan" );
      EF_e22vh_medium1_SiTrk.SetName( ::TString( prefix ) + "EF_e22vh_medium1_SiTrk" );
      EF_e22vh_medium1_TRT.SetName( ::TString( prefix ) + "EF_e22vh_medium1_TRT" );
      EF_e45_etcut.SetName( ::TString( prefix ) + "EF_e45_etcut" );
// -- slimmed --       EF_e5_tight1_e4_etcut_Jpsi_IdScan.SetName( ::TString( prefix ) + "EF_e5_tight1_e4_etcut_Jpsi_IdScan" );
// -- slimmed --       EF_e5_tight1_e4_etcut_Jpsi_SiTrk.SetName( ::TString( prefix ) + "EF_e5_tight1_e4_etcut_Jpsi_SiTrk" );
// -- slimmed --       EF_e5_tight1_e4_etcut_Jpsi_TRT.SetName( ::TString( prefix ) + "EF_e5_tight1_e4_etcut_Jpsi_TRT" );
      EF_e60_etcut.SetName( ::TString( prefix ) + "EF_e60_etcut" );
// -- slimmed --       EF_g12Tvh_medium.SetName( ::TString( prefix ) + "EF_g12Tvh_medium" );
// -- slimmed --       EF_g15vh_loose.SetName( ::TString( prefix ) + "EF_g15vh_loose" );
// -- slimmed --       EF_g20Tvh_medium.SetName( ::TString( prefix ) + "EF_g20Tvh_medium" );
// -- slimmed --       EF_g20vh_medium.SetName( ::TString( prefix ) + "EF_g20vh_medium" );
// -- slimmed --       EF_g40_loose_EFxe50.SetName( ::TString( prefix ) + "EF_g40_loose_EFxe50" );
// -- slimmed --       EF_g40_loose_L2EFxe50.SetName( ::TString( prefix ) + "EF_g40_loose_L2EFxe50" );
// -- slimmed --       EF_mu10i_g10_loose.SetName( ::TString( prefix ) + "EF_mu10i_g10_loose" );
// -- slimmed --       EF_mu10i_g10_loose_TauMass.SetName( ::TString( prefix ) + "EF_mu10i_g10_loose_TauMass" );
// -- slimmed --       EF_mu10i_loose_g12Tvh_loose.SetName( ::TString( prefix ) + "EF_mu10i_loose_g12Tvh_loose" );
// -- slimmed --       EF_mu10i_loose_g12Tvh_loose_TauMass.SetName( ::TString( prefix ) + "EF_mu10i_loose_g12Tvh_loose_TauMass" );
// -- slimmed --       EF_mu18_2g15_loose.SetName( ::TString( prefix ) + "EF_mu18_2g15_loose" );
// -- slimmed --       EF_mu18_g20vh_loose.SetName( ::TString( prefix ) + "EF_mu18_g20vh_loose" );
      EF_mu18it_tight.SetName( ::TString( prefix ) + "EF_mu18it_tight" );
// -- slimmed --       EF_mu20i_tight_g5_loose.SetName( ::TString( prefix ) + "EF_mu20i_tight_g5_loose" );
      EF_mu24_j65_a4tchad_EFxe50_tclcw.SetName( ::TString( prefix ) + "EF_mu24_j65_a4tchad_EFxe50_tclcw" );
      EF_mu24_tight_2j35_a4tchad.SetName( ::TString( prefix ) + "EF_mu24_tight_2j35_a4tchad" );
      EF_mu24_tight_4j35_a4tchad.SetName( ::TString( prefix ) + "EF_mu24_tight_4j35_a4tchad" );
// -- slimmed --       EF_mu4T_Trk_Jpsi.SetName( ::TString( prefix ) + "EF_mu4T_Trk_Jpsi" );
      EF_mu4T_j360_a4tchad_L2FS_matched.SetName( ::TString( prefix ) + "EF_mu4T_j360_a4tchad_L2FS_matched" );
      EF_mu4T_j360_a4tchad_matched.SetName( ::TString( prefix ) + "EF_mu4T_j360_a4tchad_matched" );
// -- slimmed --       EF_mu4Ti_g20Tvh_loose.SetName( ::TString( prefix ) + "EF_mu4Ti_g20Tvh_loose" );
// -- slimmed --       EF_mu4Ti_g20Tvh_loose_TauMass.SetName( ::TString( prefix ) + "EF_mu4Ti_g20Tvh_loose_TauMass" );
      EF_mu6i.SetName( ::TString( prefix ) + "EF_mu6i" );
      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void TriggerD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      EF_2e12Tvh_loose1.ReadFrom( tree );
// -- slimmed --       EF_2e5_tight1_Jpsi.ReadFrom( tree );
      EF_2e7T_loose1_mu6.ReadFrom( tree );
      EF_2e7T_medium1_mu6.ReadFrom( tree );
// -- slimmed --       EF_2g15vh_medium_g10_medium.ReadFrom( tree );
// -- slimmed --       EF_2g20vh_medium.ReadFrom( tree );
// -- slimmed --       EF_2g40_loose.ReadFrom( tree );
      EF_2mu10.ReadFrom( tree );
// -- slimmed --       EF_2mu10_MSonly_g10_loose.ReadFrom( tree );
      EF_2mu13.ReadFrom( tree );
      EF_2mu13_Zmumu_IDTrkNoCut.ReadFrom( tree );
      EF_2mu13_l2muonSA.ReadFrom( tree );
      EF_2mu15.ReadFrom( tree );
      EF_2mu4T.ReadFrom( tree );
      EF_2mu4T_2e5_tight1.ReadFrom( tree );
      EF_2mu4T_Bmumu.ReadFrom( tree );
      EF_2mu4T_Bmumu_Barrel.ReadFrom( tree );
      EF_2mu4T_Bmumu_BarrelOnly.ReadFrom( tree );
      EF_2mu4T_Bmumux.ReadFrom( tree );
      EF_2mu4T_Bmumux_Barrel.ReadFrom( tree );
      EF_2mu4T_Bmumux_BarrelOnly.ReadFrom( tree );
      EF_2mu4T_DiMu.ReadFrom( tree );
      EF_2mu4T_DiMu_Barrel.ReadFrom( tree );
      EF_2mu4T_DiMu_BarrelOnly.ReadFrom( tree );
      EF_2mu4T_DiMu_L2StarB.ReadFrom( tree );
      EF_2mu4T_DiMu_L2StarC.ReadFrom( tree );
      EF_2mu4T_DiMu_e5_tight1.ReadFrom( tree );
      EF_2mu4T_DiMu_l2muonSA.ReadFrom( tree );
      EF_2mu4T_DiMu_noVtx_noOS.ReadFrom( tree );
// -- slimmed --       EF_2mu4T_Jpsimumu.ReadFrom( tree );
// -- slimmed --       EF_2mu4T_Jpsimumu_Barrel.ReadFrom( tree );
// -- slimmed --       EF_2mu4T_Jpsimumu_BarrelOnly.ReadFrom( tree );
// -- slimmed --       EF_2mu4T_Jpsimumu_IDTrkNoCut.ReadFrom( tree );
// -- slimmed --       EF_2mu4T_Upsimumu.ReadFrom( tree );
// -- slimmed --       EF_2mu4T_Upsimumu_Barrel.ReadFrom( tree );
// -- slimmed --       EF_2mu4T_Upsimumu_BarrelOnly.ReadFrom( tree );
      EF_2mu4T_xe60.ReadFrom( tree );
      EF_2mu4T_xe60_tclcw.ReadFrom( tree );
      EF_2mu6.ReadFrom( tree );
      EF_2mu6_Bmumu.ReadFrom( tree );
      EF_2mu6_Bmumux.ReadFrom( tree );
      EF_2mu6_DiMu.ReadFrom( tree );
      EF_2mu6_DiMu_DY20.ReadFrom( tree );
      EF_2mu6_DiMu_DY25.ReadFrom( tree );
      EF_2mu6_DiMu_noVtx_noOS.ReadFrom( tree );
// -- slimmed --       EF_2mu6_Jpsimumu.ReadFrom( tree );
// -- slimmed --       EF_2mu6_Upsimumu.ReadFrom( tree );
      EF_2mu6i_DiMu_DY.ReadFrom( tree );
      EF_2mu6i_DiMu_DY_2j25_a4tchad.ReadFrom( tree );
      EF_2mu6i_DiMu_DY_noVtx_noOS.ReadFrom( tree );
      EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad.ReadFrom( tree );
      EF_2mu8_EFxe30.ReadFrom( tree );
      EF_2mu8_EFxe30_tclcw.ReadFrom( tree );
      EF_e11_etcut.ReadFrom( tree );
      EF_e12Tvh_loose1.ReadFrom( tree );
      EF_e12Tvh_medium1.ReadFrom( tree );
      EF_e12Tvh_medium1_mu6_topo_medium.ReadFrom( tree );
      EF_e12Tvh_medium1_mu8.ReadFrom( tree );
      EF_e13_etcutTrk_xs60.ReadFrom( tree );
      EF_e13_etcutTrk_xs60_dphi2j15xe20.ReadFrom( tree );
// -- slimmed --       EF_e14_tight1_e4_etcut_Jpsi.ReadFrom( tree );
      EF_e15vh_medium1.ReadFrom( tree );
      EF_e18_loose1.ReadFrom( tree );
// -- slimmed --       EF_e18_loose1_g25_medium.ReadFrom( tree );
      EF_e18_medium1.ReadFrom( tree );
// -- slimmed --       EF_e18_medium1_g25_loose.ReadFrom( tree );
      EF_e18vh_medium1.ReadFrom( tree );
      EF_e18vh_medium1_2e7T_medium1.ReadFrom( tree );
      EF_e20_etcutTrk_xe30_dphi2j15xe20.ReadFrom( tree );
      EF_e20_etcutTrk_xs60_dphi2j15xe20.ReadFrom( tree );
// -- slimmed -- // -- slimmed --       EF_e20vhT_medium1_g6T_etcut_Upsi.ReadFrom( tree );
// -- slimmed -- // -- slimmed --       EF_e20vhT_tight1_g6T_etcut_Upsi.ReadFrom( tree );
      EF_e22vh_loose.ReadFrom( tree );
      EF_e22vh_loose0.ReadFrom( tree );
      EF_e22vh_loose1.ReadFrom( tree );
      EF_e22vh_medium1.ReadFrom( tree );
      EF_e22vh_medium1_IDTrkNoCut.ReadFrom( tree );
      EF_e22vhi_medium1.ReadFrom( tree );
      EF_e24vh_loose.ReadFrom( tree );
      EF_e24vh_loose0.ReadFrom( tree );
      EF_e24vh_loose1.ReadFrom( tree );
      EF_e24vh_medium1.ReadFrom( tree );
      EF_e24vh_medium1_EFxe30.ReadFrom( tree );
      EF_e24vh_medium1_EFxe30_tcem.ReadFrom( tree );
      EF_e24vh_medium1_EFxe35_tcem.ReadFrom( tree );
      EF_e24vh_medium1_EFxe35_tclcw.ReadFrom( tree );
      EF_e24vh_medium1_EFxe40.ReadFrom( tree );
      EF_e24vh_medium1_IDTrkNoCut.ReadFrom( tree );
      EF_e24vh_medium1_IdScan.ReadFrom( tree );
      EF_e24vh_medium1_L2StarB.ReadFrom( tree );
      EF_e24vh_medium1_L2StarC.ReadFrom( tree );
      EF_e24vh_medium1_SiTrk.ReadFrom( tree );
      EF_e24vh_medium1_TRT.ReadFrom( tree );
      EF_e24vh_medium1_b35_mediumEF_j35_a4tchad.ReadFrom( tree );
      EF_e24vh_medium1_e7_medium1.ReadFrom( tree );
      EF_e24vh_tight1_e15_NoCut_Zee.ReadFrom( tree );
      EF_e24vhi_loose1_mu8.ReadFrom( tree );
      EF_e24vhi_medium1.ReadFrom( tree );
      EF_e45_medium1.ReadFrom( tree );
      EF_e5_tight1.ReadFrom( tree );
// -- slimmed --       EF_e5_tight1_e14_etcut_Jpsi.ReadFrom( tree );
// -- slimmed --       EF_e5_tight1_e4_etcut_Jpsi.ReadFrom( tree );
// -- slimmed --       EF_e5_tight1_e4_etcut_Jpsi_L2StarB.ReadFrom( tree );
// -- slimmed --       EF_e5_tight1_e4_etcut_Jpsi_L2StarC.ReadFrom( tree );
      EF_e5_tight1_e5_NoCut.ReadFrom( tree );
// -- slimmed --       EF_e5_tight1_e9_etcut_Jpsi.ReadFrom( tree );
      EF_e60_medium1.ReadFrom( tree );
      EF_e7T_loose1.ReadFrom( tree );
      EF_e7T_loose1_2mu6.ReadFrom( tree );
      EF_e7T_medium1.ReadFrom( tree );
      EF_e7T_medium1_2mu6.ReadFrom( tree );
// -- slimmed --       EF_e9_tight1_e4_etcut_Jpsi.ReadFrom( tree );
      EF_eb_physics.ReadFrom( tree );
      EF_eb_physics_empty.ReadFrom( tree );
      EF_eb_physics_firstempty.ReadFrom( tree );
      EF_eb_physics_noL1PS.ReadFrom( tree );
      EF_eb_physics_unpaired_iso.ReadFrom( tree );
      EF_eb_physics_unpaired_noniso.ReadFrom( tree );
      EF_eb_random.ReadFrom( tree );
      EF_eb_random_empty.ReadFrom( tree );
      EF_eb_random_firstempty.ReadFrom( tree );
      EF_eb_random_unpaired_iso.ReadFrom( tree );
// -- slimmed --       EF_g100_loose.ReadFrom( tree );
// -- slimmed --       EF_g10_NoCut_cosmic.ReadFrom( tree );
// -- slimmed --       EF_g10_loose.ReadFrom( tree );
// -- slimmed --       EF_g10_medium.ReadFrom( tree );
// -- slimmed --       EF_g120_loose.ReadFrom( tree );
// -- slimmed --       EF_g12Tvh_loose.ReadFrom( tree );
// -- slimmed --       EF_g12Tvh_loose_larcalib.ReadFrom( tree );
// -- slimmed --       EF_g15_loose.ReadFrom( tree );
// -- slimmed --       EF_g15vh_medium.ReadFrom( tree );
// -- slimmed --       EF_g200_etcut.ReadFrom( tree );
// -- slimmed --       EF_g20_etcut.ReadFrom( tree );
// -- slimmed --       EF_g20_loose.ReadFrom( tree );
// -- slimmed --       EF_g20_loose_larcalib.ReadFrom( tree );
// -- slimmed --       EF_g20_medium.ReadFrom( tree );
// -- slimmed --       EF_g30_loose_g20_loose.ReadFrom( tree );
// -- slimmed --       EF_g30_medium_g20_medium.ReadFrom( tree );
// -- slimmed --       EF_g35_loose_g25_loose.ReadFrom( tree );
// -- slimmed --       EF_g35_loose_g30_loose.ReadFrom( tree );
// -- slimmed --       EF_g40_loose.ReadFrom( tree );
// -- slimmed --       EF_g40_loose_L2EFxe60.ReadFrom( tree );
// -- slimmed --       EF_g40_loose_L2EFxe60_tclcw.ReadFrom( tree );
// -- slimmed --       EF_g40_loose_g25_loose.ReadFrom( tree );
// -- slimmed --       EF_g40_loose_g30_loose.ReadFrom( tree );
// -- slimmed --       EF_g40_loose_larcalib.ReadFrom( tree );
// -- slimmed --       EF_g5_NoCut_cosmic.ReadFrom( tree );
// -- slimmed --       EF_g60_loose.ReadFrom( tree );
// -- slimmed --       EF_g60_loose_larcalib.ReadFrom( tree );
// -- slimmed --       EF_g80_loose.ReadFrom( tree );
// -- slimmed --       EF_g80_loose_larcalib.ReadFrom( tree );
      EF_mu10.ReadFrom( tree );
// -- slimmed --       EF_mu10_Jpsimumu.ReadFrom( tree );
      EF_mu10_MSonly.ReadFrom( tree );
// -- slimmed --       EF_mu10_Upsimumu_tight_FS.ReadFrom( tree );
// -- slimmed --       EF_mu10i_g10_medium.ReadFrom( tree );
// -- slimmed --       EF_mu10i_g10_medium_TauMass.ReadFrom( tree );
// -- slimmed --       EF_mu10i_loose_g12Tvh_medium.ReadFrom( tree );
// -- slimmed --       EF_mu10i_loose_g12Tvh_medium_TauMass.ReadFrom( tree );
      EF_mu11_empty_NoAlg.ReadFrom( tree );
      EF_mu13.ReadFrom( tree );
      EF_mu15.ReadFrom( tree );
      EF_mu18.ReadFrom( tree );
// -- slimmed --       EF_mu18_2g10_loose.ReadFrom( tree );
// -- slimmed --       EF_mu18_2g10_medium.ReadFrom( tree );
      EF_mu18_IDTrkNoCut_tight.ReadFrom( tree );
      EF_mu18_medium.ReadFrom( tree );
      EF_mu18_tight.ReadFrom( tree );
      EF_mu18_tight_2mu4_EFFS.ReadFrom( tree );
      EF_mu18_tight_e7_medium1.ReadFrom( tree );
      EF_mu18_tight_mu8_EFFS.ReadFrom( tree );
      EF_mu18i4_tight.ReadFrom( tree );
// -- slimmed --       EF_mu20i_tight_g5_loose_TauMass.ReadFrom( tree );
// -- slimmed --       EF_mu20i_tight_g5_medium.ReadFrom( tree );
// -- slimmed --       EF_mu20i_tight_g5_medium_TauMass.ReadFrom( tree );
      EF_mu20it_tight.ReadFrom( tree );
      EF_mu22_IDTrkNoCut_tight.ReadFrom( tree );
      EF_mu24.ReadFrom( tree );
// -- slimmed --       EF_mu24_g20vh_loose.ReadFrom( tree );
// -- slimmed --       EF_mu24_g20vh_medium.ReadFrom( tree );
      EF_mu24_j65_a4tchad.ReadFrom( tree );
      EF_mu24_j65_a4tchad_EFxe40.ReadFrom( tree );
      EF_mu24_j65_a4tchad_EFxe40_tclcw.ReadFrom( tree );
      EF_mu24_j65_a4tchad_EFxe60_tclcw.ReadFrom( tree );
      EF_mu24_medium.ReadFrom( tree );
      EF_mu24_muCombTag_NoEF_tight.ReadFrom( tree );
      EF_mu24_tight.ReadFrom( tree );
      EF_mu24_tight_3j35_a4tchad.ReadFrom( tree );
      EF_mu24_tight_EFxe40.ReadFrom( tree );
      EF_mu24_tight_L2StarB.ReadFrom( tree );
      EF_mu24_tight_L2StarC.ReadFrom( tree );
      EF_mu24_tight_MG.ReadFrom( tree );
      EF_mu24_tight_MuonEF.ReadFrom( tree );
      EF_mu24_tight_b35_mediumEF_j35_a4tchad.ReadFrom( tree );
      EF_mu24_tight_mu6_EFFS.ReadFrom( tree );
      EF_mu24i_tight.ReadFrom( tree );
      EF_mu24i_tight_MG.ReadFrom( tree );
      EF_mu24i_tight_MuonEF.ReadFrom( tree );
      EF_mu24i_tight_l2muonSA.ReadFrom( tree );
      EF_mu36_tight.ReadFrom( tree );
      EF_mu40_MSonly_barrel_tight.ReadFrom( tree );
      EF_mu40_muCombTag_NoEF.ReadFrom( tree );
      EF_mu40_slow_outOfTime_tight.ReadFrom( tree );
      EF_mu40_slow_tight.ReadFrom( tree );
      EF_mu40_tight.ReadFrom( tree );
      EF_mu4T.ReadFrom( tree );
      EF_mu4T_cosmic.ReadFrom( tree );
      EF_mu4T_j110_a4tchad_L2FS_matched.ReadFrom( tree );
      EF_mu4T_j110_a4tchad_matched.ReadFrom( tree );
      EF_mu4T_j145_a4tchad_L2FS_matched.ReadFrom( tree );
      EF_mu4T_j145_a4tchad_matched.ReadFrom( tree );
      EF_mu4T_j15_a4tchad_matched.ReadFrom( tree );
      EF_mu4T_j15_a4tchad_matchedZ.ReadFrom( tree );
      EF_mu4T_j180_a4tchad_L2FS_matched.ReadFrom( tree );
      EF_mu4T_j180_a4tchad_matched.ReadFrom( tree );
      EF_mu4T_j220_a4tchad_L2FS_matched.ReadFrom( tree );
      EF_mu4T_j220_a4tchad_matched.ReadFrom( tree );
      EF_mu4T_j25_a4tchad_matched.ReadFrom( tree );
      EF_mu4T_j25_a4tchad_matchedZ.ReadFrom( tree );
      EF_mu4T_j280_a4tchad_L2FS_matched.ReadFrom( tree );
      EF_mu4T_j280_a4tchad_matched.ReadFrom( tree );
      EF_mu4T_j35_a4tchad_matched.ReadFrom( tree );
      EF_mu4T_j35_a4tchad_matchedZ.ReadFrom( tree );
      EF_mu4T_j45_a4tchad_L2FS_matched.ReadFrom( tree );
      EF_mu4T_j45_a4tchad_L2FS_matchedZ.ReadFrom( tree );
      EF_mu4T_j45_a4tchad_matched.ReadFrom( tree );
      EF_mu4T_j45_a4tchad_matchedZ.ReadFrom( tree );
      EF_mu4T_j55_a4tchad_L2FS_matched.ReadFrom( tree );
      EF_mu4T_j55_a4tchad_L2FS_matchedZ.ReadFrom( tree );
      EF_mu4T_j55_a4tchad_matched.ReadFrom( tree );
      EF_mu4T_j55_a4tchad_matchedZ.ReadFrom( tree );
      EF_mu4T_j65_a4tchad_L2FS_matched.ReadFrom( tree );
      EF_mu4T_j65_a4tchad_matched.ReadFrom( tree );
      EF_mu4T_j65_a4tchad_xe60_tclcw_loose.ReadFrom( tree );
      EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose.ReadFrom( tree );
      EF_mu4T_j80_a4tchad_L2FS_matched.ReadFrom( tree );
      EF_mu4T_j80_a4tchad_matched.ReadFrom( tree );
// -- slimmed --       EF_mu4Ti_g20Tvh_medium.ReadFrom( tree );
// -- slimmed --       EF_mu4Ti_g20Tvh_medium_TauMass.ReadFrom( tree );
      EF_mu4Tmu6_Bmumu.ReadFrom( tree );
      EF_mu4Tmu6_Bmumu_Barrel.ReadFrom( tree );
      EF_mu4Tmu6_Bmumux.ReadFrom( tree );
      EF_mu4Tmu6_Bmumux_Barrel.ReadFrom( tree );
      EF_mu4Tmu6_DiMu.ReadFrom( tree );
      EF_mu4Tmu6_DiMu_Barrel.ReadFrom( tree );
      EF_mu4Tmu6_DiMu_noVtx_noOS.ReadFrom( tree );
// -- slimmed --       EF_mu4Tmu6_Jpsimumu.ReadFrom( tree );
// -- slimmed --       EF_mu4Tmu6_Jpsimumu_Barrel.ReadFrom( tree );
// -- slimmed --       EF_mu4Tmu6_Jpsimumu_IDTrkNoCut.ReadFrom( tree );
// -- slimmed --       EF_mu4Tmu6_Upsimumu.ReadFrom( tree );
// -- slimmed --       EF_mu4Tmu6_Upsimumu_Barrel.ReadFrom( tree );
      EF_mu4_L1MU11_MSonly_cosmic.ReadFrom( tree );
      EF_mu4_L1MU11_cosmic.ReadFrom( tree );
      EF_mu4_empty_NoAlg.ReadFrom( tree );
      EF_mu4_firstempty_NoAlg.ReadFrom( tree );
      EF_mu4_unpaired_iso_NoAlg.ReadFrom( tree );
      EF_mu50_MSonly_barrel_tight.ReadFrom( tree );
      EF_mu6.ReadFrom( tree );
      EF_mu60_slow_outOfTime_tight1.ReadFrom( tree );
      EF_mu60_slow_tight1.ReadFrom( tree );
// -- slimmed --       EF_mu6_Jpsimumu_tight.ReadFrom( tree );
      EF_mu6_MSonly.ReadFrom( tree );
// -- slimmed --       EF_mu6_Trk_Jpsi_loose.ReadFrom( tree );
      EF_mu8.ReadFrom( tree );
      EF_mu8_4j45_a4tchad_L2FS.ReadFrom( tree );

      // =============================================================================
      // = from MC D3PD
      // =============================================================================
// -- slimmed --       EF_2g15vh_loose_g10_loose.ReadFrom( tree );
// -- slimmed --       EF_2g15vh_medium.ReadFrom( tree );
// -- slimmed --       EF_2g20_loose.ReadFrom( tree );
// -- slimmed --       EF_2g30_loose.ReadFrom( tree );
// -- slimmed --       EF_2mu10_MSonly_g10_loose_EMPTY.ReadFrom( tree );
// -- slimmed --       EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO.ReadFrom( tree );
      EF_2mu4T_xe50_tclcw.ReadFrom( tree );
      EF_e12Tvh_loose1_mu8.ReadFrom( tree );
      EF_e12Tvh_medium1_mu10.ReadFrom( tree );
      EF_e12Tvh_medium1_mu6.ReadFrom( tree );
// -- slimmed --       EF_e18_loose1_g35_loose.ReadFrom( tree );
// -- slimmed --       EF_e18_loose1_g35_medium.ReadFrom( tree );
// -- slimmed --       EF_e18_medium1_g25_medium.ReadFrom( tree );
// -- slimmed --       EF_e18_medium1_g35_loose.ReadFrom( tree );
// -- slimmed --       EF_e18_medium1_g35_medium.ReadFrom( tree );
      EF_e22vh_medium1_IdScan.ReadFrom( tree );
      EF_e22vh_medium1_SiTrk.ReadFrom( tree );
      EF_e22vh_medium1_TRT.ReadFrom( tree );
      EF_e45_etcut.ReadFrom( tree );
// -- slimmed --       EF_e5_tight1_e4_etcut_Jpsi_IdScan.ReadFrom( tree );
// -- slimmed --       EF_e5_tight1_e4_etcut_Jpsi_SiTrk.ReadFrom( tree );
// -- slimmed --       EF_e5_tight1_e4_etcut_Jpsi_TRT.ReadFrom( tree );
      EF_e60_etcut.ReadFrom( tree );
// -- slimmed --       EF_g12Tvh_medium.ReadFrom( tree );
// -- slimmed --       EF_g15vh_loose.ReadFrom( tree );
// -- slimmed --       EF_g20Tvh_medium.ReadFrom( tree );
// -- slimmed --       EF_g20vh_medium.ReadFrom( tree );
// -- slimmed --       EF_g40_loose_EFxe50.ReadFrom( tree );
// -- slimmed --       EF_g40_loose_L2EFxe50.ReadFrom( tree );
// -- slimmed --       EF_mu10i_g10_loose.ReadFrom( tree );
// -- slimmed --       EF_mu10i_g10_loose_TauMass.ReadFrom( tree );
// -- slimmed --       EF_mu10i_loose_g12Tvh_loose.ReadFrom( tree );
// -- slimmed --       EF_mu10i_loose_g12Tvh_loose_TauMass.ReadFrom( tree );
// -- slimmed --       EF_mu18_2g15_loose.ReadFrom( tree );
// -- slimmed --       EF_mu18_g20vh_loose.ReadFrom( tree );
      EF_mu18it_tight.ReadFrom( tree );
// -- slimmed --       EF_mu20i_tight_g5_loose.ReadFrom( tree );
      EF_mu24_j65_a4tchad_EFxe50_tclcw.ReadFrom( tree );
      EF_mu24_tight_2j35_a4tchad.ReadFrom( tree );
      EF_mu24_tight_4j35_a4tchad.ReadFrom( tree );
// -- slimmed --       EF_mu4T_Trk_Jpsi.ReadFrom( tree );
      EF_mu4T_j360_a4tchad_L2FS_matched.ReadFrom( tree );
      EF_mu4T_j360_a4tchad_matched.ReadFrom( tree );
// -- slimmed --       EF_mu4Ti_g20Tvh_loose.ReadFrom( tree );
// -- slimmed --       EF_mu4Ti_g20Tvh_loose_TauMass.ReadFrom( tree );
      EF_mu6i.ReadFrom( tree );

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void TriggerD3PDObject::WriteTo( TTree* tree ) {

      EF_2e12Tvh_loose1.WriteTo( tree );
// -- slimmed --       EF_2e5_tight1_Jpsi.WriteTo( tree );
      EF_2e7T_loose1_mu6.WriteTo( tree );
      EF_2e7T_medium1_mu6.WriteTo( tree );
// -- slimmed --       EF_2g15vh_medium_g10_medium.WriteTo( tree );
// -- slimmed --       EF_2g20vh_medium.WriteTo( tree );
// -- slimmed --       EF_2g40_loose.WriteTo( tree );
      EF_2mu10.WriteTo( tree );
// -- slimmed --       EF_2mu10_MSonly_g10_loose.WriteTo( tree );
      EF_2mu13.WriteTo( tree );
      EF_2mu13_Zmumu_IDTrkNoCut.WriteTo( tree );
      EF_2mu13_l2muonSA.WriteTo( tree );
      EF_2mu15.WriteTo( tree );
      EF_2mu4T.WriteTo( tree );
      EF_2mu4T_2e5_tight1.WriteTo( tree );
      EF_2mu4T_Bmumu.WriteTo( tree );
      EF_2mu4T_Bmumu_Barrel.WriteTo( tree );
      EF_2mu4T_Bmumu_BarrelOnly.WriteTo( tree );
      EF_2mu4T_Bmumux.WriteTo( tree );
      EF_2mu4T_Bmumux_Barrel.WriteTo( tree );
      EF_2mu4T_Bmumux_BarrelOnly.WriteTo( tree );
      EF_2mu4T_DiMu.WriteTo( tree );
      EF_2mu4T_DiMu_Barrel.WriteTo( tree );
      EF_2mu4T_DiMu_BarrelOnly.WriteTo( tree );
      EF_2mu4T_DiMu_L2StarB.WriteTo( tree );
      EF_2mu4T_DiMu_L2StarC.WriteTo( tree );
      EF_2mu4T_DiMu_e5_tight1.WriteTo( tree );
      EF_2mu4T_DiMu_l2muonSA.WriteTo( tree );
      EF_2mu4T_DiMu_noVtx_noOS.WriteTo( tree );
// -- slimmed --       EF_2mu4T_Jpsimumu.WriteTo( tree );
// -- slimmed --       EF_2mu4T_Jpsimumu_Barrel.WriteTo( tree );
// -- slimmed --       EF_2mu4T_Jpsimumu_BarrelOnly.WriteTo( tree );
// -- slimmed --       EF_2mu4T_Jpsimumu_IDTrkNoCut.WriteTo( tree );
// -- slimmed --       EF_2mu4T_Upsimumu.WriteTo( tree );
// -- slimmed --       EF_2mu4T_Upsimumu_Barrel.WriteTo( tree );
// -- slimmed --       EF_2mu4T_Upsimumu_BarrelOnly.WriteTo( tree );
      EF_2mu4T_xe60.WriteTo( tree );
      EF_2mu4T_xe60_tclcw.WriteTo( tree );
      EF_2mu6.WriteTo( tree );
      EF_2mu6_Bmumu.WriteTo( tree );
      EF_2mu6_Bmumux.WriteTo( tree );
      EF_2mu6_DiMu.WriteTo( tree );
      EF_2mu6_DiMu_DY20.WriteTo( tree );
      EF_2mu6_DiMu_DY25.WriteTo( tree );
      EF_2mu6_DiMu_noVtx_noOS.WriteTo( tree );
// -- slimmed --       EF_2mu6_Jpsimumu.WriteTo( tree );
// -- slimmed --       EF_2mu6_Upsimumu.WriteTo( tree );
      EF_2mu6i_DiMu_DY.WriteTo( tree );
      EF_2mu6i_DiMu_DY_2j25_a4tchad.WriteTo( tree );
      EF_2mu6i_DiMu_DY_noVtx_noOS.WriteTo( tree );
      EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad.WriteTo( tree );
      EF_2mu8_EFxe30.WriteTo( tree );
      EF_2mu8_EFxe30_tclcw.WriteTo( tree );
      EF_e11_etcut.WriteTo( tree );
      EF_e12Tvh_loose1.WriteTo( tree );
      EF_e12Tvh_medium1.WriteTo( tree );
      EF_e12Tvh_medium1_mu6_topo_medium.WriteTo( tree );
      EF_e12Tvh_medium1_mu8.WriteTo( tree );
      EF_e13_etcutTrk_xs60.WriteTo( tree );
      EF_e13_etcutTrk_xs60_dphi2j15xe20.WriteTo( tree );
// -- slimmed --       EF_e14_tight1_e4_etcut_Jpsi.WriteTo( tree );
      EF_e15vh_medium1.WriteTo( tree );
      EF_e18_loose1.WriteTo( tree );
// -- slimmed --       EF_e18_loose1_g25_medium.WriteTo( tree );
      EF_e18_medium1.WriteTo( tree );
// -- slimmed --       EF_e18_medium1_g25_loose.WriteTo( tree );
      EF_e18vh_medium1.WriteTo( tree );
      EF_e18vh_medium1_2e7T_medium1.WriteTo( tree );
      EF_e20_etcutTrk_xe30_dphi2j15xe20.WriteTo( tree );
      EF_e20_etcutTrk_xs60_dphi2j15xe20.WriteTo( tree );
// -- slimmed -- // -- slimmed --       EF_e20vhT_medium1_g6T_etcut_Upsi.WriteTo( tree );
// -- slimmed -- // -- slimmed --       EF_e20vhT_tight1_g6T_etcut_Upsi.WriteTo( tree );
      EF_e22vh_loose.WriteTo( tree );
      EF_e22vh_loose0.WriteTo( tree );
      EF_e22vh_loose1.WriteTo( tree );
      EF_e22vh_medium1.WriteTo( tree );
      EF_e22vh_medium1_IDTrkNoCut.WriteTo( tree );
      EF_e22vhi_medium1.WriteTo( tree );
      EF_e24vh_loose.WriteTo( tree );
      EF_e24vh_loose0.WriteTo( tree );
      EF_e24vh_loose1.WriteTo( tree );
      EF_e24vh_medium1.WriteTo( tree );
      EF_e24vh_medium1_EFxe30.WriteTo( tree );
      EF_e24vh_medium1_EFxe30_tcem.WriteTo( tree );
      EF_e24vh_medium1_EFxe35_tcem.WriteTo( tree );
      EF_e24vh_medium1_EFxe35_tclcw.WriteTo( tree );
      EF_e24vh_medium1_EFxe40.WriteTo( tree );
      EF_e24vh_medium1_IDTrkNoCut.WriteTo( tree );
      EF_e24vh_medium1_IdScan.WriteTo( tree );
      EF_e24vh_medium1_L2StarB.WriteTo( tree );
      EF_e24vh_medium1_L2StarC.WriteTo( tree );
      EF_e24vh_medium1_SiTrk.WriteTo( tree );
      EF_e24vh_medium1_TRT.WriteTo( tree );
      EF_e24vh_medium1_b35_mediumEF_j35_a4tchad.WriteTo( tree );
      EF_e24vh_medium1_e7_medium1.WriteTo( tree );
      EF_e24vh_tight1_e15_NoCut_Zee.WriteTo( tree );
      EF_e24vhi_loose1_mu8.WriteTo( tree );
      EF_e24vhi_medium1.WriteTo( tree );
      EF_e45_medium1.WriteTo( tree );
      EF_e5_tight1.WriteTo( tree );
// -- slimmed --       EF_e5_tight1_e14_etcut_Jpsi.WriteTo( tree );
// -- slimmed --       EF_e5_tight1_e4_etcut_Jpsi.WriteTo( tree );
// -- slimmed --       EF_e5_tight1_e4_etcut_Jpsi_L2StarB.WriteTo( tree );
// -- slimmed --       EF_e5_tight1_e4_etcut_Jpsi_L2StarC.WriteTo( tree );
      EF_e5_tight1_e5_NoCut.WriteTo( tree );
// -- slimmed --       EF_e5_tight1_e9_etcut_Jpsi.WriteTo( tree );
      EF_e60_medium1.WriteTo( tree );
      EF_e7T_loose1.WriteTo( tree );
      EF_e7T_loose1_2mu6.WriteTo( tree );
      EF_e7T_medium1.WriteTo( tree );
      EF_e7T_medium1_2mu6.WriteTo( tree );
// -- slimmed --       EF_e9_tight1_e4_etcut_Jpsi.WriteTo( tree );
      EF_eb_physics.WriteTo( tree );
      EF_eb_physics_empty.WriteTo( tree );
      EF_eb_physics_firstempty.WriteTo( tree );
      EF_eb_physics_noL1PS.WriteTo( tree );
      EF_eb_physics_unpaired_iso.WriteTo( tree );
      EF_eb_physics_unpaired_noniso.WriteTo( tree );
      EF_eb_random.WriteTo( tree );
      EF_eb_random_empty.WriteTo( tree );
      EF_eb_random_firstempty.WriteTo( tree );
      EF_eb_random_unpaired_iso.WriteTo( tree );
// -- slimmed --       EF_g100_loose.WriteTo( tree );
// -- slimmed --       EF_g10_NoCut_cosmic.WriteTo( tree );
// -- slimmed --       EF_g10_loose.WriteTo( tree );
// -- slimmed --       EF_g10_medium.WriteTo( tree );
// -- slimmed --       EF_g120_loose.WriteTo( tree );
// -- slimmed --       EF_g12Tvh_loose.WriteTo( tree );
// -- slimmed --       EF_g12Tvh_loose_larcalib.WriteTo( tree );
// -- slimmed --       EF_g15_loose.WriteTo( tree );
// -- slimmed --       EF_g15vh_medium.WriteTo( tree );
// -- slimmed --       EF_g200_etcut.WriteTo( tree );
// -- slimmed --       EF_g20_etcut.WriteTo( tree );
// -- slimmed --       EF_g20_loose.WriteTo( tree );
// -- slimmed --       EF_g20_loose_larcalib.WriteTo( tree );
// -- slimmed --       EF_g20_medium.WriteTo( tree );
// -- slimmed --       EF_g30_loose_g20_loose.WriteTo( tree );
// -- slimmed --       EF_g30_medium_g20_medium.WriteTo( tree );
// -- slimmed --       EF_g35_loose_g25_loose.WriteTo( tree );
// -- slimmed --       EF_g35_loose_g30_loose.WriteTo( tree );
// -- slimmed --       EF_g40_loose.WriteTo( tree );
// -- slimmed --       EF_g40_loose_L2EFxe60.WriteTo( tree );
// -- slimmed --       EF_g40_loose_L2EFxe60_tclcw.WriteTo( tree );
// -- slimmed --       EF_g40_loose_g25_loose.WriteTo( tree );
// -- slimmed --       EF_g40_loose_g30_loose.WriteTo( tree );
// -- slimmed --       EF_g40_loose_larcalib.WriteTo( tree );
// -- slimmed --       EF_g5_NoCut_cosmic.WriteTo( tree );
// -- slimmed --       EF_g60_loose.WriteTo( tree );
// -- slimmed --       EF_g60_loose_larcalib.WriteTo( tree );
// -- slimmed --       EF_g80_loose.WriteTo( tree );
// -- slimmed --       EF_g80_loose_larcalib.WriteTo( tree );
      EF_mu10.WriteTo( tree );
// -- slimmed --       EF_mu10_Jpsimumu.WriteTo( tree );
      EF_mu10_MSonly.WriteTo( tree );
// -- slimmed --       EF_mu10_Upsimumu_tight_FS.WriteTo( tree );
// -- slimmed --       EF_mu10i_g10_medium.WriteTo( tree );
// -- slimmed --       EF_mu10i_g10_medium_TauMass.WriteTo( tree );
// -- slimmed --       EF_mu10i_loose_g12Tvh_medium.WriteTo( tree );
// -- slimmed --       EF_mu10i_loose_g12Tvh_medium_TauMass.WriteTo( tree );
      EF_mu11_empty_NoAlg.WriteTo( tree );
      EF_mu13.WriteTo( tree );
      EF_mu15.WriteTo( tree );
      EF_mu18.WriteTo( tree );
// -- slimmed --       EF_mu18_2g10_loose.WriteTo( tree );
// -- slimmed --       EF_mu18_2g10_medium.WriteTo( tree );
      EF_mu18_IDTrkNoCut_tight.WriteTo( tree );
      EF_mu18_medium.WriteTo( tree );
      EF_mu18_tight.WriteTo( tree );
      EF_mu18_tight_2mu4_EFFS.WriteTo( tree );
      EF_mu18_tight_e7_medium1.WriteTo( tree );
      EF_mu18_tight_mu8_EFFS.WriteTo( tree );
      EF_mu18i4_tight.WriteTo( tree );
// -- slimmed --       EF_mu20i_tight_g5_loose_TauMass.WriteTo( tree );
// -- slimmed --       EF_mu20i_tight_g5_medium.WriteTo( tree );
// -- slimmed --       EF_mu20i_tight_g5_medium_TauMass.WriteTo( tree );
      EF_mu20it_tight.WriteTo( tree );
      EF_mu22_IDTrkNoCut_tight.WriteTo( tree );
      EF_mu24.WriteTo( tree );
// -- slimmed --       EF_mu24_g20vh_loose.WriteTo( tree );
// -- slimmed --       EF_mu24_g20vh_medium.WriteTo( tree );
      EF_mu24_j65_a4tchad.WriteTo( tree );
      EF_mu24_j65_a4tchad_EFxe40.WriteTo( tree );
      EF_mu24_j65_a4tchad_EFxe40_tclcw.WriteTo( tree );
      EF_mu24_j65_a4tchad_EFxe60_tclcw.WriteTo( tree );
      EF_mu24_medium.WriteTo( tree );
      EF_mu24_muCombTag_NoEF_tight.WriteTo( tree );
      EF_mu24_tight.WriteTo( tree );
      EF_mu24_tight_3j35_a4tchad.WriteTo( tree );
      EF_mu24_tight_EFxe40.WriteTo( tree );
      EF_mu24_tight_L2StarB.WriteTo( tree );
      EF_mu24_tight_L2StarC.WriteTo( tree );
      EF_mu24_tight_MG.WriteTo( tree );
      EF_mu24_tight_MuonEF.WriteTo( tree );
      EF_mu24_tight_b35_mediumEF_j35_a4tchad.WriteTo( tree );
      EF_mu24_tight_mu6_EFFS.WriteTo( tree );
      EF_mu24i_tight.WriteTo( tree );
      EF_mu24i_tight_MG.WriteTo( tree );
      EF_mu24i_tight_MuonEF.WriteTo( tree );
      EF_mu24i_tight_l2muonSA.WriteTo( tree );
      EF_mu36_tight.WriteTo( tree );
      EF_mu40_MSonly_barrel_tight.WriteTo( tree );
      EF_mu40_muCombTag_NoEF.WriteTo( tree );
      EF_mu40_slow_outOfTime_tight.WriteTo( tree );
      EF_mu40_slow_tight.WriteTo( tree );
      EF_mu40_tight.WriteTo( tree );
      EF_mu4T.WriteTo( tree );
      EF_mu4T_cosmic.WriteTo( tree );
      EF_mu4T_j110_a4tchad_L2FS_matched.WriteTo( tree );
      EF_mu4T_j110_a4tchad_matched.WriteTo( tree );
      EF_mu4T_j145_a4tchad_L2FS_matched.WriteTo( tree );
      EF_mu4T_j145_a4tchad_matched.WriteTo( tree );
      EF_mu4T_j15_a4tchad_matched.WriteTo( tree );
      EF_mu4T_j15_a4tchad_matchedZ.WriteTo( tree );
      EF_mu4T_j180_a4tchad_L2FS_matched.WriteTo( tree );
      EF_mu4T_j180_a4tchad_matched.WriteTo( tree );
      EF_mu4T_j220_a4tchad_L2FS_matched.WriteTo( tree );
      EF_mu4T_j220_a4tchad_matched.WriteTo( tree );
      EF_mu4T_j25_a4tchad_matched.WriteTo( tree );
      EF_mu4T_j25_a4tchad_matchedZ.WriteTo( tree );
      EF_mu4T_j280_a4tchad_L2FS_matched.WriteTo( tree );
      EF_mu4T_j280_a4tchad_matched.WriteTo( tree );
      EF_mu4T_j35_a4tchad_matched.WriteTo( tree );
      EF_mu4T_j35_a4tchad_matchedZ.WriteTo( tree );
      EF_mu4T_j45_a4tchad_L2FS_matched.WriteTo( tree );
      EF_mu4T_j45_a4tchad_L2FS_matchedZ.WriteTo( tree );
      EF_mu4T_j45_a4tchad_matched.WriteTo( tree );
      EF_mu4T_j45_a4tchad_matchedZ.WriteTo( tree );
      EF_mu4T_j55_a4tchad_L2FS_matched.WriteTo( tree );
      EF_mu4T_j55_a4tchad_L2FS_matchedZ.WriteTo( tree );
      EF_mu4T_j55_a4tchad_matched.WriteTo( tree );
      EF_mu4T_j55_a4tchad_matchedZ.WriteTo( tree );
      EF_mu4T_j65_a4tchad_L2FS_matched.WriteTo( tree );
      EF_mu4T_j65_a4tchad_matched.WriteTo( tree );
      EF_mu4T_j65_a4tchad_xe60_tclcw_loose.WriteTo( tree );
      EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose.WriteTo( tree );
      EF_mu4T_j80_a4tchad_L2FS_matched.WriteTo( tree );
      EF_mu4T_j80_a4tchad_matched.WriteTo( tree );
// -- slimmed --       EF_mu4Ti_g20Tvh_medium.WriteTo( tree );
// -- slimmed --       EF_mu4Ti_g20Tvh_medium_TauMass.WriteTo( tree );
      EF_mu4Tmu6_Bmumu.WriteTo( tree );
      EF_mu4Tmu6_Bmumu_Barrel.WriteTo( tree );
      EF_mu4Tmu6_Bmumux.WriteTo( tree );
      EF_mu4Tmu6_Bmumux_Barrel.WriteTo( tree );
      EF_mu4Tmu6_DiMu.WriteTo( tree );
      EF_mu4Tmu6_DiMu_Barrel.WriteTo( tree );
      EF_mu4Tmu6_DiMu_noVtx_noOS.WriteTo( tree );
// -- slimmed --       EF_mu4Tmu6_Jpsimumu.WriteTo( tree );
// -- slimmed --       EF_mu4Tmu6_Jpsimumu_Barrel.WriteTo( tree );
// -- slimmed --       EF_mu4Tmu6_Jpsimumu_IDTrkNoCut.WriteTo( tree );
// -- slimmed --       EF_mu4Tmu6_Upsimumu.WriteTo( tree );
// -- slimmed --       EF_mu4Tmu6_Upsimumu_Barrel.WriteTo( tree );
      EF_mu4_L1MU11_MSonly_cosmic.WriteTo( tree );
      EF_mu4_L1MU11_cosmic.WriteTo( tree );
      EF_mu4_empty_NoAlg.WriteTo( tree );
      EF_mu4_firstempty_NoAlg.WriteTo( tree );
      EF_mu4_unpaired_iso_NoAlg.WriteTo( tree );
      EF_mu50_MSonly_barrel_tight.WriteTo( tree );
      EF_mu6.WriteTo( tree );
      EF_mu60_slow_outOfTime_tight1.WriteTo( tree );
      EF_mu60_slow_tight1.WriteTo( tree );
// -- slimmed --       EF_mu6_Jpsimumu_tight.WriteTo( tree );
      EF_mu6_MSonly.WriteTo( tree );
// -- slimmed --       EF_mu6_Trk_Jpsi_loose.WriteTo( tree );
      EF_mu8.WriteTo( tree );
      EF_mu8_4j45_a4tchad_L2FS.WriteTo( tree );

      // =============================================================================
      // = from MC D3PD
      // =============================================================================
// -- slimmed --       EF_2g15vh_loose_g10_loose.WriteTo( tree );
// -- slimmed --       EF_2g15vh_medium.WriteTo( tree );
// -- slimmed --       EF_2g20_loose.WriteTo( tree );
// -- slimmed --       EF_2g30_loose.WriteTo( tree );
// -- slimmed --       EF_2mu10_MSonly_g10_loose_EMPTY.WriteTo( tree );
// -- slimmed --       EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO.WriteTo( tree );
      EF_2mu4T_xe50_tclcw.WriteTo( tree );
      EF_e12Tvh_loose1_mu8.WriteTo( tree );
      EF_e12Tvh_medium1_mu10.WriteTo( tree );
      EF_e12Tvh_medium1_mu6.WriteTo( tree );
// -- slimmed --       EF_e18_loose1_g35_loose.WriteTo( tree );
// -- slimmed --       EF_e18_loose1_g35_medium.WriteTo( tree );
// -- slimmed --       EF_e18_medium1_g25_medium.WriteTo( tree );
// -- slimmed --       EF_e18_medium1_g35_loose.WriteTo( tree );
// -- slimmed --       EF_e18_medium1_g35_medium.WriteTo( tree );
      EF_e22vh_medium1_IdScan.WriteTo( tree );
      EF_e22vh_medium1_SiTrk.WriteTo( tree );
      EF_e22vh_medium1_TRT.WriteTo( tree );
      EF_e45_etcut.WriteTo( tree );
// -- slimmed --       EF_e5_tight1_e4_etcut_Jpsi_IdScan.WriteTo( tree );
// -- slimmed --       EF_e5_tight1_e4_etcut_Jpsi_SiTrk.WriteTo( tree );
// -- slimmed --       EF_e5_tight1_e4_etcut_Jpsi_TRT.WriteTo( tree );
      EF_e60_etcut.WriteTo( tree );
// -- slimmed --       EF_g12Tvh_medium.WriteTo( tree );
// -- slimmed --       EF_g15vh_loose.WriteTo( tree );
// -- slimmed --       EF_g20Tvh_medium.WriteTo( tree );
// -- slimmed --       EF_g20vh_medium.WriteTo( tree );
// -- slimmed --       EF_g40_loose_EFxe50.WriteTo( tree );
// -- slimmed --       EF_g40_loose_L2EFxe50.WriteTo( tree );
// -- slimmed --       EF_mu10i_g10_loose.WriteTo( tree );
// -- slimmed --       EF_mu10i_g10_loose_TauMass.WriteTo( tree );
// -- slimmed --       EF_mu10i_loose_g12Tvh_loose.WriteTo( tree );
// -- slimmed --       EF_mu10i_loose_g12Tvh_loose_TauMass.WriteTo( tree );
// -- slimmed --       EF_mu18_2g15_loose.WriteTo( tree );
// -- slimmed --       EF_mu18_g20vh_loose.WriteTo( tree );
      EF_mu18it_tight.WriteTo( tree );
// -- slimmed --       EF_mu20i_tight_g5_loose.WriteTo( tree );
      EF_mu24_j65_a4tchad_EFxe50_tclcw.WriteTo( tree );
      EF_mu24_tight_2j35_a4tchad.WriteTo( tree );
      EF_mu24_tight_4j35_a4tchad.WriteTo( tree );
// -- slimmed --       EF_mu4T_Trk_Jpsi.WriteTo( tree );
      EF_mu4T_j360_a4tchad_L2FS_matched.WriteTo( tree );
      EF_mu4T_j360_a4tchad_matched.WriteTo( tree );
// -- slimmed --       EF_mu4Ti_g20Tvh_loose.WriteTo( tree );
// -- slimmed --       EF_mu4Ti_g20Tvh_loose_TauMass.WriteTo( tree );
      EF_mu6i.WriteTo( tree );

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
   void TriggerD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void TriggerD3PDObject::ReadAllActive() {

      // Check if it makes sense to call this function:
      if( ! fFromInput ) {
         static ::Bool_t wPrinted = kFALSE;
         if( ! wPrinted ) {
            Warning( "ReadAllActive", "Function only meaningful when used on objects" );
            Warning( "ReadAllActive", "which are used to read information from a D3PD" );
            wPrinted = kTRUE;
         }
      }

      if( EF_2e12Tvh_loose1.IsActive() ) EF_2e12Tvh_loose1();
// -- slimmed --       if( EF_2e5_tight1_Jpsi.IsActive() ) EF_2e5_tight1_Jpsi();
      if( EF_2e7T_loose1_mu6.IsActive() ) EF_2e7T_loose1_mu6();
      if( EF_2e7T_medium1_mu6.IsActive() ) EF_2e7T_medium1_mu6();
// -- slimmed --       if( EF_2g15vh_medium_g10_medium.IsActive() ) EF_2g15vh_medium_g10_medium();
// -- slimmed --       if( EF_2g20vh_medium.IsActive() ) EF_2g20vh_medium();
// -- slimmed --       if( EF_2g40_loose.IsActive() ) EF_2g40_loose();
      if( EF_2mu10.IsActive() ) EF_2mu10();
// -- slimmed --       if( EF_2mu10_MSonly_g10_loose.IsActive() ) EF_2mu10_MSonly_g10_loose();
      if( EF_2mu13.IsActive() ) EF_2mu13();
      if( EF_2mu13_Zmumu_IDTrkNoCut.IsActive() ) EF_2mu13_Zmumu_IDTrkNoCut();
      if( EF_2mu13_l2muonSA.IsActive() ) EF_2mu13_l2muonSA();
      if( EF_2mu15.IsActive() ) EF_2mu15();
      if( EF_2mu4T.IsActive() ) EF_2mu4T();
      if( EF_2mu4T_2e5_tight1.IsActive() ) EF_2mu4T_2e5_tight1();
      if( EF_2mu4T_Bmumu.IsActive() ) EF_2mu4T_Bmumu();
      if( EF_2mu4T_Bmumu_Barrel.IsActive() ) EF_2mu4T_Bmumu_Barrel();
      if( EF_2mu4T_Bmumu_BarrelOnly.IsActive() ) EF_2mu4T_Bmumu_BarrelOnly();
      if( EF_2mu4T_Bmumux.IsActive() ) EF_2mu4T_Bmumux();
      if( EF_2mu4T_Bmumux_Barrel.IsActive() ) EF_2mu4T_Bmumux_Barrel();
      if( EF_2mu4T_Bmumux_BarrelOnly.IsActive() ) EF_2mu4T_Bmumux_BarrelOnly();
      if( EF_2mu4T_DiMu.IsActive() ) EF_2mu4T_DiMu();
      if( EF_2mu4T_DiMu_Barrel.IsActive() ) EF_2mu4T_DiMu_Barrel();
      if( EF_2mu4T_DiMu_BarrelOnly.IsActive() ) EF_2mu4T_DiMu_BarrelOnly();
      if( EF_2mu4T_DiMu_L2StarB.IsActive() ) EF_2mu4T_DiMu_L2StarB();
      if( EF_2mu4T_DiMu_L2StarC.IsActive() ) EF_2mu4T_DiMu_L2StarC();
      if( EF_2mu4T_DiMu_e5_tight1.IsActive() ) EF_2mu4T_DiMu_e5_tight1();
      if( EF_2mu4T_DiMu_l2muonSA.IsActive() ) EF_2mu4T_DiMu_l2muonSA();
      if( EF_2mu4T_DiMu_noVtx_noOS.IsActive() ) EF_2mu4T_DiMu_noVtx_noOS();
// -- slimmed --       if( EF_2mu4T_Jpsimumu.IsActive() ) EF_2mu4T_Jpsimumu();
// -- slimmed --       if( EF_2mu4T_Jpsimumu_Barrel.IsActive() ) EF_2mu4T_Jpsimumu_Barrel();
// -- slimmed --       if( EF_2mu4T_Jpsimumu_BarrelOnly.IsActive() ) EF_2mu4T_Jpsimumu_BarrelOnly();
// -- slimmed --       if( EF_2mu4T_Jpsimumu_IDTrkNoCut.IsActive() ) EF_2mu4T_Jpsimumu_IDTrkNoCut();
// -- slimmed --       if( EF_2mu4T_Upsimumu.IsActive() ) EF_2mu4T_Upsimumu();
// -- slimmed --       if( EF_2mu4T_Upsimumu_Barrel.IsActive() ) EF_2mu4T_Upsimumu_Barrel();
// -- slimmed --       if( EF_2mu4T_Upsimumu_BarrelOnly.IsActive() ) EF_2mu4T_Upsimumu_BarrelOnly();
      if( EF_2mu4T_xe60.IsActive() ) EF_2mu4T_xe60();
      if( EF_2mu4T_xe60_tclcw.IsActive() ) EF_2mu4T_xe60_tclcw();
      if( EF_2mu6.IsActive() ) EF_2mu6();
      if( EF_2mu6_Bmumu.IsActive() ) EF_2mu6_Bmumu();
      if( EF_2mu6_Bmumux.IsActive() ) EF_2mu6_Bmumux();
      if( EF_2mu6_DiMu.IsActive() ) EF_2mu6_DiMu();
      if( EF_2mu6_DiMu_DY20.IsActive() ) EF_2mu6_DiMu_DY20();
      if( EF_2mu6_DiMu_DY25.IsActive() ) EF_2mu6_DiMu_DY25();
      if( EF_2mu6_DiMu_noVtx_noOS.IsActive() ) EF_2mu6_DiMu_noVtx_noOS();
// -- slimmed --       if( EF_2mu6_Jpsimumu.IsActive() ) EF_2mu6_Jpsimumu();
// -- slimmed --       if( EF_2mu6_Upsimumu.IsActive() ) EF_2mu6_Upsimumu();
      if( EF_2mu6i_DiMu_DY.IsActive() ) EF_2mu6i_DiMu_DY();
      if( EF_2mu6i_DiMu_DY_2j25_a4tchad.IsActive() ) EF_2mu6i_DiMu_DY_2j25_a4tchad();
      if( EF_2mu6i_DiMu_DY_noVtx_noOS.IsActive() ) EF_2mu6i_DiMu_DY_noVtx_noOS();
      if( EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad.IsActive() ) EF_2mu6i_DiMu_DY_noVtx_noOS_2j25_a4tchad();
      if( EF_2mu8_EFxe30.IsActive() ) EF_2mu8_EFxe30();
      if( EF_2mu8_EFxe30_tclcw.IsActive() ) EF_2mu8_EFxe30_tclcw();
      if( EF_e11_etcut.IsActive() ) EF_e11_etcut();
      if( EF_e12Tvh_loose1.IsActive() ) EF_e12Tvh_loose1();
      if( EF_e12Tvh_medium1.IsActive() ) EF_e12Tvh_medium1();
      if( EF_e12Tvh_medium1_mu6_topo_medium.IsActive() ) EF_e12Tvh_medium1_mu6_topo_medium();
      if( EF_e12Tvh_medium1_mu8.IsActive() ) EF_e12Tvh_medium1_mu8();
      if( EF_e13_etcutTrk_xs60.IsActive() ) EF_e13_etcutTrk_xs60();
      if( EF_e13_etcutTrk_xs60_dphi2j15xe20.IsActive() ) EF_e13_etcutTrk_xs60_dphi2j15xe20();
// -- slimmed --       if( EF_e14_tight1_e4_etcut_Jpsi.IsActive() ) EF_e14_tight1_e4_etcut_Jpsi();
      if( EF_e15vh_medium1.IsActive() ) EF_e15vh_medium1();
      if( EF_e18_loose1.IsActive() ) EF_e18_loose1();
// -- slimmed --       if( EF_e18_loose1_g25_medium.IsActive() ) EF_e18_loose1_g25_medium();
      if( EF_e18_medium1.IsActive() ) EF_e18_medium1();
// -- slimmed --       if( EF_e18_medium1_g25_loose.IsActive() ) EF_e18_medium1_g25_loose();
      if( EF_e18vh_medium1.IsActive() ) EF_e18vh_medium1();
      if( EF_e18vh_medium1_2e7T_medium1.IsActive() ) EF_e18vh_medium1_2e7T_medium1();
      if( EF_e20_etcutTrk_xe30_dphi2j15xe20.IsActive() ) EF_e20_etcutTrk_xe30_dphi2j15xe20();
      if( EF_e20_etcutTrk_xs60_dphi2j15xe20.IsActive() ) EF_e20_etcutTrk_xs60_dphi2j15xe20();
// -- slimmed -- // -- slimmed --       if( EF_e20vhT_medium1_g6T_etcut_Upsi.IsActive() ) EF_e20vhT_medium1_g6T_etcut_Upsi();
// -- slimmed -- // -- slimmed --       if( EF_e20vhT_tight1_g6T_etcut_Upsi.IsActive() ) EF_e20vhT_tight1_g6T_etcut_Upsi();
      if( EF_e22vh_loose.IsActive() ) EF_e22vh_loose();
      if( EF_e22vh_loose0.IsActive() ) EF_e22vh_loose0();
      if( EF_e22vh_loose1.IsActive() ) EF_e22vh_loose1();
      if( EF_e22vh_medium1.IsActive() ) EF_e22vh_medium1();
      if( EF_e22vh_medium1_IDTrkNoCut.IsActive() ) EF_e22vh_medium1_IDTrkNoCut();
      if( EF_e22vhi_medium1.IsActive() ) EF_e22vhi_medium1();
      if( EF_e24vh_loose.IsActive() ) EF_e24vh_loose();
      if( EF_e24vh_loose0.IsActive() ) EF_e24vh_loose0();
      if( EF_e24vh_loose1.IsActive() ) EF_e24vh_loose1();
      if( EF_e24vh_medium1.IsActive() ) EF_e24vh_medium1();
      if( EF_e24vh_medium1_EFxe30.IsActive() ) EF_e24vh_medium1_EFxe30();
      if( EF_e24vh_medium1_EFxe30_tcem.IsActive() ) EF_e24vh_medium1_EFxe30_tcem();
      if( EF_e24vh_medium1_EFxe35_tcem.IsActive() ) EF_e24vh_medium1_EFxe35_tcem();
      if( EF_e24vh_medium1_EFxe35_tclcw.IsActive() ) EF_e24vh_medium1_EFxe35_tclcw();
      if( EF_e24vh_medium1_EFxe40.IsActive() ) EF_e24vh_medium1_EFxe40();
      if( EF_e24vh_medium1_IDTrkNoCut.IsActive() ) EF_e24vh_medium1_IDTrkNoCut();
      if( EF_e24vh_medium1_IdScan.IsActive() ) EF_e24vh_medium1_IdScan();
      if( EF_e24vh_medium1_L2StarB.IsActive() ) EF_e24vh_medium1_L2StarB();
      if( EF_e24vh_medium1_L2StarC.IsActive() ) EF_e24vh_medium1_L2StarC();
      if( EF_e24vh_medium1_SiTrk.IsActive() ) EF_e24vh_medium1_SiTrk();
      if( EF_e24vh_medium1_TRT.IsActive() ) EF_e24vh_medium1_TRT();
      if( EF_e24vh_medium1_b35_mediumEF_j35_a4tchad.IsActive() ) EF_e24vh_medium1_b35_mediumEF_j35_a4tchad();
      if( EF_e24vh_medium1_e7_medium1.IsActive() ) EF_e24vh_medium1_e7_medium1();
      if( EF_e24vh_tight1_e15_NoCut_Zee.IsActive() ) EF_e24vh_tight1_e15_NoCut_Zee();
      if( EF_e24vhi_loose1_mu8.IsActive() ) EF_e24vhi_loose1_mu8();
      if( EF_e24vhi_medium1.IsActive() ) EF_e24vhi_medium1();
      if( EF_e45_medium1.IsActive() ) EF_e45_medium1();
      if( EF_e5_tight1.IsActive() ) EF_e5_tight1();
// -- slimmed --       if( EF_e5_tight1_e14_etcut_Jpsi.IsActive() ) EF_e5_tight1_e14_etcut_Jpsi();
// -- slimmed --       if( EF_e5_tight1_e4_etcut_Jpsi.IsActive() ) EF_e5_tight1_e4_etcut_Jpsi();
// -- slimmed --       if( EF_e5_tight1_e4_etcut_Jpsi_L2StarB.IsActive() ) EF_e5_tight1_e4_etcut_Jpsi_L2StarB();
// -- slimmed --       if( EF_e5_tight1_e4_etcut_Jpsi_L2StarC.IsActive() ) EF_e5_tight1_e4_etcut_Jpsi_L2StarC();
      if( EF_e5_tight1_e5_NoCut.IsActive() ) EF_e5_tight1_e5_NoCut();
// -- slimmed --       if( EF_e5_tight1_e9_etcut_Jpsi.IsActive() ) EF_e5_tight1_e9_etcut_Jpsi();
      if( EF_e60_medium1.IsActive() ) EF_e60_medium1();
      if( EF_e7T_loose1.IsActive() ) EF_e7T_loose1();
      if( EF_e7T_loose1_2mu6.IsActive() ) EF_e7T_loose1_2mu6();
      if( EF_e7T_medium1.IsActive() ) EF_e7T_medium1();
      if( EF_e7T_medium1_2mu6.IsActive() ) EF_e7T_medium1_2mu6();
// -- slimmed --       if( EF_e9_tight1_e4_etcut_Jpsi.IsActive() ) EF_e9_tight1_e4_etcut_Jpsi();
      if( EF_eb_physics.IsActive() ) EF_eb_physics();
      if( EF_eb_physics_empty.IsActive() ) EF_eb_physics_empty();
      if( EF_eb_physics_firstempty.IsActive() ) EF_eb_physics_firstempty();
      if( EF_eb_physics_noL1PS.IsActive() ) EF_eb_physics_noL1PS();
      if( EF_eb_physics_unpaired_iso.IsActive() ) EF_eb_physics_unpaired_iso();
      if( EF_eb_physics_unpaired_noniso.IsActive() ) EF_eb_physics_unpaired_noniso();
      if( EF_eb_random.IsActive() ) EF_eb_random();
      if( EF_eb_random_empty.IsActive() ) EF_eb_random_empty();
      if( EF_eb_random_firstempty.IsActive() ) EF_eb_random_firstempty();
      if( EF_eb_random_unpaired_iso.IsActive() ) EF_eb_random_unpaired_iso();
// -- slimmed --       if( EF_g100_loose.IsActive() ) EF_g100_loose();
// -- slimmed --       if( EF_g10_NoCut_cosmic.IsActive() ) EF_g10_NoCut_cosmic();
// -- slimmed --       if( EF_g10_loose.IsActive() ) EF_g10_loose();
// -- slimmed --       if( EF_g10_medium.IsActive() ) EF_g10_medium();
// -- slimmed --       if( EF_g120_loose.IsActive() ) EF_g120_loose();
// -- slimmed --       if( EF_g12Tvh_loose.IsActive() ) EF_g12Tvh_loose();
// -- slimmed --       if( EF_g12Tvh_loose_larcalib.IsActive() ) EF_g12Tvh_loose_larcalib();
// -- slimmed --       if( EF_g15_loose.IsActive() ) EF_g15_loose();
// -- slimmed --       if( EF_g15vh_medium.IsActive() ) EF_g15vh_medium();
// -- slimmed --       if( EF_g200_etcut.IsActive() ) EF_g200_etcut();
// -- slimmed --       if( EF_g20_etcut.IsActive() ) EF_g20_etcut();
// -- slimmed --       if( EF_g20_loose.IsActive() ) EF_g20_loose();
// -- slimmed --       if( EF_g20_loose_larcalib.IsActive() ) EF_g20_loose_larcalib();
// -- slimmed --       if( EF_g20_medium.IsActive() ) EF_g20_medium();
// -- slimmed --       if( EF_g30_loose_g20_loose.IsActive() ) EF_g30_loose_g20_loose();
// -- slimmed --       if( EF_g30_medium_g20_medium.IsActive() ) EF_g30_medium_g20_medium();
// -- slimmed --       if( EF_g35_loose_g25_loose.IsActive() ) EF_g35_loose_g25_loose();
// -- slimmed --       if( EF_g35_loose_g30_loose.IsActive() ) EF_g35_loose_g30_loose();
// -- slimmed --       if( EF_g40_loose.IsActive() ) EF_g40_loose();
// -- slimmed --       if( EF_g40_loose_L2EFxe60.IsActive() ) EF_g40_loose_L2EFxe60();
// -- slimmed --       if( EF_g40_loose_L2EFxe60_tclcw.IsActive() ) EF_g40_loose_L2EFxe60_tclcw();
// -- slimmed --       if( EF_g40_loose_g25_loose.IsActive() ) EF_g40_loose_g25_loose();
// -- slimmed --       if( EF_g40_loose_g30_loose.IsActive() ) EF_g40_loose_g30_loose();
// -- slimmed --       if( EF_g40_loose_larcalib.IsActive() ) EF_g40_loose_larcalib();
// -- slimmed --       if( EF_g5_NoCut_cosmic.IsActive() ) EF_g5_NoCut_cosmic();
// -- slimmed --       if( EF_g60_loose.IsActive() ) EF_g60_loose();
// -- slimmed --       if( EF_g60_loose_larcalib.IsActive() ) EF_g60_loose_larcalib();
// -- slimmed --       if( EF_g80_loose.IsActive() ) EF_g80_loose();
// -- slimmed --       if( EF_g80_loose_larcalib.IsActive() ) EF_g80_loose_larcalib();
      if( EF_mu10.IsActive() ) EF_mu10();
// -- slimmed --       if( EF_mu10_Jpsimumu.IsActive() ) EF_mu10_Jpsimumu();
      if( EF_mu10_MSonly.IsActive() ) EF_mu10_MSonly();
// -- slimmed --       if( EF_mu10_Upsimumu_tight_FS.IsActive() ) EF_mu10_Upsimumu_tight_FS();
// -- slimmed --       if( EF_mu10i_g10_medium.IsActive() ) EF_mu10i_g10_medium();
// -- slimmed --       if( EF_mu10i_g10_medium_TauMass.IsActive() ) EF_mu10i_g10_medium_TauMass();
// -- slimmed --       if( EF_mu10i_loose_g12Tvh_medium.IsActive() ) EF_mu10i_loose_g12Tvh_medium();
// -- slimmed --       if( EF_mu10i_loose_g12Tvh_medium_TauMass.IsActive() ) EF_mu10i_loose_g12Tvh_medium_TauMass();
      if( EF_mu11_empty_NoAlg.IsActive() ) EF_mu11_empty_NoAlg();
      if( EF_mu13.IsActive() ) EF_mu13();
      if( EF_mu15.IsActive() ) EF_mu15();
      if( EF_mu18.IsActive() ) EF_mu18();
// -- slimmed --       if( EF_mu18_2g10_loose.IsActive() ) EF_mu18_2g10_loose();
// -- slimmed --       if( EF_mu18_2g10_medium.IsActive() ) EF_mu18_2g10_medium();
      if( EF_mu18_IDTrkNoCut_tight.IsActive() ) EF_mu18_IDTrkNoCut_tight();
      if( EF_mu18_medium.IsActive() ) EF_mu18_medium();
      if( EF_mu18_tight.IsActive() ) EF_mu18_tight();
      if( EF_mu18_tight_2mu4_EFFS.IsActive() ) EF_mu18_tight_2mu4_EFFS();
      if( EF_mu18_tight_e7_medium1.IsActive() ) EF_mu18_tight_e7_medium1();
      if( EF_mu18_tight_mu8_EFFS.IsActive() ) EF_mu18_tight_mu8_EFFS();
      if( EF_mu18i4_tight.IsActive() ) EF_mu18i4_tight();
// -- slimmed --       if( EF_mu20i_tight_g5_loose_TauMass.IsActive() ) EF_mu20i_tight_g5_loose_TauMass();
// -- slimmed --       if( EF_mu20i_tight_g5_medium.IsActive() ) EF_mu20i_tight_g5_medium();
// -- slimmed --       if( EF_mu20i_tight_g5_medium_TauMass.IsActive() ) EF_mu20i_tight_g5_medium_TauMass();
      if( EF_mu20it_tight.IsActive() ) EF_mu20it_tight();
      if( EF_mu22_IDTrkNoCut_tight.IsActive() ) EF_mu22_IDTrkNoCut_tight();
      if( EF_mu24.IsActive() ) EF_mu24();
// -- slimmed --       if( EF_mu24_g20vh_loose.IsActive() ) EF_mu24_g20vh_loose();
// -- slimmed --       if( EF_mu24_g20vh_medium.IsActive() ) EF_mu24_g20vh_medium();
      if( EF_mu24_j65_a4tchad.IsActive() ) EF_mu24_j65_a4tchad();
      if( EF_mu24_j65_a4tchad_EFxe40.IsActive() ) EF_mu24_j65_a4tchad_EFxe40();
      if( EF_mu24_j65_a4tchad_EFxe40_tclcw.IsActive() ) EF_mu24_j65_a4tchad_EFxe40_tclcw();
      if( EF_mu24_j65_a4tchad_EFxe60_tclcw.IsActive() ) EF_mu24_j65_a4tchad_EFxe60_tclcw();
      if( EF_mu24_medium.IsActive() ) EF_mu24_medium();
      if( EF_mu24_muCombTag_NoEF_tight.IsActive() ) EF_mu24_muCombTag_NoEF_tight();
      if( EF_mu24_tight.IsActive() ) EF_mu24_tight();
      if( EF_mu24_tight_3j35_a4tchad.IsActive() ) EF_mu24_tight_3j35_a4tchad();
      if( EF_mu24_tight_EFxe40.IsActive() ) EF_mu24_tight_EFxe40();
      if( EF_mu24_tight_L2StarB.IsActive() ) EF_mu24_tight_L2StarB();
      if( EF_mu24_tight_L2StarC.IsActive() ) EF_mu24_tight_L2StarC();
      if( EF_mu24_tight_MG.IsActive() ) EF_mu24_tight_MG();
      if( EF_mu24_tight_MuonEF.IsActive() ) EF_mu24_tight_MuonEF();
      if( EF_mu24_tight_b35_mediumEF_j35_a4tchad.IsActive() ) EF_mu24_tight_b35_mediumEF_j35_a4tchad();
      if( EF_mu24_tight_mu6_EFFS.IsActive() ) EF_mu24_tight_mu6_EFFS();
      if( EF_mu24i_tight.IsActive() ) EF_mu24i_tight();
      if( EF_mu24i_tight_MG.IsActive() ) EF_mu24i_tight_MG();
      if( EF_mu24i_tight_MuonEF.IsActive() ) EF_mu24i_tight_MuonEF();
      if( EF_mu24i_tight_l2muonSA.IsActive() ) EF_mu24i_tight_l2muonSA();
      if( EF_mu36_tight.IsActive() ) EF_mu36_tight();
      if( EF_mu40_MSonly_barrel_tight.IsActive() ) EF_mu40_MSonly_barrel_tight();
      if( EF_mu40_muCombTag_NoEF.IsActive() ) EF_mu40_muCombTag_NoEF();
      if( EF_mu40_slow_outOfTime_tight.IsActive() ) EF_mu40_slow_outOfTime_tight();
      if( EF_mu40_slow_tight.IsActive() ) EF_mu40_slow_tight();
      if( EF_mu40_tight.IsActive() ) EF_mu40_tight();
      if( EF_mu4T.IsActive() ) EF_mu4T();
      if( EF_mu4T_cosmic.IsActive() ) EF_mu4T_cosmic();
      if( EF_mu4T_j110_a4tchad_L2FS_matched.IsActive() ) EF_mu4T_j110_a4tchad_L2FS_matched();
      if( EF_mu4T_j110_a4tchad_matched.IsActive() ) EF_mu4T_j110_a4tchad_matched();
      if( EF_mu4T_j145_a4tchad_L2FS_matched.IsActive() ) EF_mu4T_j145_a4tchad_L2FS_matched();
      if( EF_mu4T_j145_a4tchad_matched.IsActive() ) EF_mu4T_j145_a4tchad_matched();
      if( EF_mu4T_j15_a4tchad_matched.IsActive() ) EF_mu4T_j15_a4tchad_matched();
      if( EF_mu4T_j15_a4tchad_matchedZ.IsActive() ) EF_mu4T_j15_a4tchad_matchedZ();
      if( EF_mu4T_j180_a4tchad_L2FS_matched.IsActive() ) EF_mu4T_j180_a4tchad_L2FS_matched();
      if( EF_mu4T_j180_a4tchad_matched.IsActive() ) EF_mu4T_j180_a4tchad_matched();
      if( EF_mu4T_j220_a4tchad_L2FS_matched.IsActive() ) EF_mu4T_j220_a4tchad_L2FS_matched();
      if( EF_mu4T_j220_a4tchad_matched.IsActive() ) EF_mu4T_j220_a4tchad_matched();
      if( EF_mu4T_j25_a4tchad_matched.IsActive() ) EF_mu4T_j25_a4tchad_matched();
      if( EF_mu4T_j25_a4tchad_matchedZ.IsActive() ) EF_mu4T_j25_a4tchad_matchedZ();
      if( EF_mu4T_j280_a4tchad_L2FS_matched.IsActive() ) EF_mu4T_j280_a4tchad_L2FS_matched();
      if( EF_mu4T_j280_a4tchad_matched.IsActive() ) EF_mu4T_j280_a4tchad_matched();
      if( EF_mu4T_j35_a4tchad_matched.IsActive() ) EF_mu4T_j35_a4tchad_matched();
      if( EF_mu4T_j35_a4tchad_matchedZ.IsActive() ) EF_mu4T_j35_a4tchad_matchedZ();
      if( EF_mu4T_j45_a4tchad_L2FS_matched.IsActive() ) EF_mu4T_j45_a4tchad_L2FS_matched();
      if( EF_mu4T_j45_a4tchad_L2FS_matchedZ.IsActive() ) EF_mu4T_j45_a4tchad_L2FS_matchedZ();
      if( EF_mu4T_j45_a4tchad_matched.IsActive() ) EF_mu4T_j45_a4tchad_matched();
      if( EF_mu4T_j45_a4tchad_matchedZ.IsActive() ) EF_mu4T_j45_a4tchad_matchedZ();
      if( EF_mu4T_j55_a4tchad_L2FS_matched.IsActive() ) EF_mu4T_j55_a4tchad_L2FS_matched();
      if( EF_mu4T_j55_a4tchad_L2FS_matchedZ.IsActive() ) EF_mu4T_j55_a4tchad_L2FS_matchedZ();
      if( EF_mu4T_j55_a4tchad_matched.IsActive() ) EF_mu4T_j55_a4tchad_matched();
      if( EF_mu4T_j55_a4tchad_matchedZ.IsActive() ) EF_mu4T_j55_a4tchad_matchedZ();
      if( EF_mu4T_j65_a4tchad_L2FS_matched.IsActive() ) EF_mu4T_j65_a4tchad_L2FS_matched();
      if( EF_mu4T_j65_a4tchad_matched.IsActive() ) EF_mu4T_j65_a4tchad_matched();
      if( EF_mu4T_j65_a4tchad_xe60_tclcw_loose.IsActive() ) EF_mu4T_j65_a4tchad_xe60_tclcw_loose();
      if( EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose.IsActive() ) EF_mu4T_j65_a4tchad_xe70_tclcw_veryloose();
      if( EF_mu4T_j80_a4tchad_L2FS_matched.IsActive() ) EF_mu4T_j80_a4tchad_L2FS_matched();
      if( EF_mu4T_j80_a4tchad_matched.IsActive() ) EF_mu4T_j80_a4tchad_matched();
// -- slimmed --       if( EF_mu4Ti_g20Tvh_medium.IsActive() ) EF_mu4Ti_g20Tvh_medium();
// -- slimmed --       if( EF_mu4Ti_g20Tvh_medium_TauMass.IsActive() ) EF_mu4Ti_g20Tvh_medium_TauMass();
      if( EF_mu4Tmu6_Bmumu.IsActive() ) EF_mu4Tmu6_Bmumu();
      if( EF_mu4Tmu6_Bmumu_Barrel.IsActive() ) EF_mu4Tmu6_Bmumu_Barrel();
      if( EF_mu4Tmu6_Bmumux.IsActive() ) EF_mu4Tmu6_Bmumux();
      if( EF_mu4Tmu6_Bmumux_Barrel.IsActive() ) EF_mu4Tmu6_Bmumux_Barrel();
      if( EF_mu4Tmu6_DiMu.IsActive() ) EF_mu4Tmu6_DiMu();
      if( EF_mu4Tmu6_DiMu_Barrel.IsActive() ) EF_mu4Tmu6_DiMu_Barrel();
      if( EF_mu4Tmu6_DiMu_noVtx_noOS.IsActive() ) EF_mu4Tmu6_DiMu_noVtx_noOS();
// -- slimmed --       if( EF_mu4Tmu6_Jpsimumu.IsActive() ) EF_mu4Tmu6_Jpsimumu();
// -- slimmed --       if( EF_mu4Tmu6_Jpsimumu_Barrel.IsActive() ) EF_mu4Tmu6_Jpsimumu_Barrel();
// -- slimmed --       if( EF_mu4Tmu6_Jpsimumu_IDTrkNoCut.IsActive() ) EF_mu4Tmu6_Jpsimumu_IDTrkNoCut();
// -- slimmed --       if( EF_mu4Tmu6_Upsimumu.IsActive() ) EF_mu4Tmu6_Upsimumu();
// -- slimmed --       if( EF_mu4Tmu6_Upsimumu_Barrel.IsActive() ) EF_mu4Tmu6_Upsimumu_Barrel();
      if( EF_mu4_L1MU11_MSonly_cosmic.IsActive() ) EF_mu4_L1MU11_MSonly_cosmic();
      if( EF_mu4_L1MU11_cosmic.IsActive() ) EF_mu4_L1MU11_cosmic();
      if( EF_mu4_empty_NoAlg.IsActive() ) EF_mu4_empty_NoAlg();
      if( EF_mu4_firstempty_NoAlg.IsActive() ) EF_mu4_firstempty_NoAlg();
      if( EF_mu4_unpaired_iso_NoAlg.IsActive() ) EF_mu4_unpaired_iso_NoAlg();
      if( EF_mu50_MSonly_barrel_tight.IsActive() ) EF_mu50_MSonly_barrel_tight();
      if( EF_mu6.IsActive() ) EF_mu6();
      if( EF_mu60_slow_outOfTime_tight1.IsActive() ) EF_mu60_slow_outOfTime_tight1();
      if( EF_mu60_slow_tight1.IsActive() ) EF_mu60_slow_tight1();
// -- slimmed --       if( EF_mu6_Jpsimumu_tight.IsActive() ) EF_mu6_Jpsimumu_tight();
      if( EF_mu6_MSonly.IsActive() ) EF_mu6_MSonly();
// -- slimmed --       if( EF_mu6_Trk_Jpsi_loose.IsActive() ) EF_mu6_Trk_Jpsi_loose();
      if( EF_mu8.IsActive() ) EF_mu8();
      if( EF_mu8_4j45_a4tchad_L2FS.IsActive() ) EF_mu8_4j45_a4tchad_L2FS();

      // =============================================================================
      // = from MC D3PD
      // =============================================================================
// -- slimmed --       if( EF_2g15vh_loose_g10_loose.IsActive() ) EF_2g15vh_loose_g10_loose();
// -- slimmed --       if( EF_2g15vh_medium.IsActive() ) EF_2g15vh_medium();
// -- slimmed --       if( EF_2g20_loose.IsActive() ) EF_2g20_loose();
// -- slimmed --       if( EF_2g30_loose.IsActive() ) EF_2g30_loose();
// -- slimmed --       if( EF_2mu10_MSonly_g10_loose_EMPTY.IsActive() ) EF_2mu10_MSonly_g10_loose_EMPTY();
// -- slimmed --       if( EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO.IsActive() ) EF_2mu10_MSonly_g10_loose_UNPAIRED_ISO();
      if( EF_2mu4T_xe50_tclcw.IsActive() ) EF_2mu4T_xe50_tclcw();
      if( EF_e12Tvh_loose1_mu8.IsActive() ) EF_e12Tvh_loose1_mu8();
      if( EF_e12Tvh_medium1_mu10.IsActive() ) EF_e12Tvh_medium1_mu10();
      if( EF_e12Tvh_medium1_mu6.IsActive() ) EF_e12Tvh_medium1_mu6();
// -- slimmed --       if( EF_e18_loose1_g35_loose.IsActive() ) EF_e18_loose1_g35_loose();
// -- slimmed --       if( EF_e18_loose1_g35_medium.IsActive() ) EF_e18_loose1_g35_medium();
// -- slimmed --       if( EF_e18_medium1_g25_medium.IsActive() ) EF_e18_medium1_g25_medium();
// -- slimmed --       if( EF_e18_medium1_g35_loose.IsActive() ) EF_e18_medium1_g35_loose();
// -- slimmed --       if( EF_e18_medium1_g35_medium.IsActive() ) EF_e18_medium1_g35_medium();
      if( EF_e22vh_medium1_IdScan.IsActive() ) EF_e22vh_medium1_IdScan();
      if( EF_e22vh_medium1_SiTrk.IsActive() ) EF_e22vh_medium1_SiTrk();
      if( EF_e22vh_medium1_TRT.IsActive() ) EF_e22vh_medium1_TRT();
      if( EF_e45_etcut.IsActive() ) EF_e45_etcut();
// -- slimmed --       if( EF_e5_tight1_e4_etcut_Jpsi_IdScan.IsActive() ) EF_e5_tight1_e4_etcut_Jpsi_IdScan();
// -- slimmed --       if( EF_e5_tight1_e4_etcut_Jpsi_SiTrk.IsActive() ) EF_e5_tight1_e4_etcut_Jpsi_SiTrk();
// -- slimmed --       if( EF_e5_tight1_e4_etcut_Jpsi_TRT.IsActive() ) EF_e5_tight1_e4_etcut_Jpsi_TRT();
      if( EF_e60_etcut.IsActive() ) EF_e60_etcut();
// -- slimmed --       if( EF_g12Tvh_medium.IsActive() ) EF_g12Tvh_medium();
// -- slimmed --       if( EF_g15vh_loose.IsActive() ) EF_g15vh_loose();
// -- slimmed --       if( EF_g20Tvh_medium.IsActive() ) EF_g20Tvh_medium();
// -- slimmed --       if( EF_g20vh_medium.IsActive() ) EF_g20vh_medium();
// -- slimmed --       if( EF_g40_loose_EFxe50.IsActive() ) EF_g40_loose_EFxe50();
// -- slimmed --       if( EF_g40_loose_L2EFxe50.IsActive() ) EF_g40_loose_L2EFxe50();
// -- slimmed --       if( EF_mu10i_g10_loose.IsActive() ) EF_mu10i_g10_loose();
// -- slimmed --       if( EF_mu10i_g10_loose_TauMass.IsActive() ) EF_mu10i_g10_loose_TauMass();
// -- slimmed --       if( EF_mu10i_loose_g12Tvh_loose.IsActive() ) EF_mu10i_loose_g12Tvh_loose();
// -- slimmed --       if( EF_mu10i_loose_g12Tvh_loose_TauMass.IsActive() ) EF_mu10i_loose_g12Tvh_loose_TauMass();
// -- slimmed --       if( EF_mu18_2g15_loose.IsActive() ) EF_mu18_2g15_loose();
// -- slimmed --       if( EF_mu18_g20vh_loose.IsActive() ) EF_mu18_g20vh_loose();
      if( EF_mu18it_tight.IsActive() ) EF_mu18it_tight();
// -- slimmed --       if( EF_mu20i_tight_g5_loose.IsActive() ) EF_mu20i_tight_g5_loose();
      if( EF_mu24_j65_a4tchad_EFxe50_tclcw.IsActive() ) EF_mu24_j65_a4tchad_EFxe50_tclcw();
      if( EF_mu24_tight_2j35_a4tchad.IsActive() ) EF_mu24_tight_2j35_a4tchad();
      if( EF_mu24_tight_4j35_a4tchad.IsActive() ) EF_mu24_tight_4j35_a4tchad();
// -- slimmed --       if( EF_mu4T_Trk_Jpsi.IsActive() ) EF_mu4T_Trk_Jpsi();
      if( EF_mu4T_j360_a4tchad_L2FS_matched.IsActive() ) EF_mu4T_j360_a4tchad_L2FS_matched();
      if( EF_mu4T_j360_a4tchad_matched.IsActive() ) EF_mu4T_j360_a4tchad_matched();
// -- slimmed --       if( EF_mu4Ti_g20Tvh_loose.IsActive() ) EF_mu4Ti_g20Tvh_loose();
// -- slimmed --       if( EF_mu4Ti_g20Tvh_loose_TauMass.IsActive() ) EF_mu4Ti_g20Tvh_loose_TauMass();
      if( EF_mu6i.IsActive() ) EF_mu6i();

      return;
   }

} // namespace D3PDReader
