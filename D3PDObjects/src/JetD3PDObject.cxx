// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <limits>

#include <TPRegexp.h>

#include "../include/JetD3PDObject.h"

ClassImp( D3PDReader::JetD3PDObjectElement )
ClassImp( D3PDReader::JetD3PDObject )

namespace D3PDReader {

   /**
    * This constructor can be used to create new proxy objects from scratch.
    * Since the constructor of such an object is quite complicated and
    * error prone, it is only visible to the parent class JetD3PDObject.
    */
   JetD3PDObjectElement::JetD3PDObjectElement( size_t index, const JetD3PDObject& parent , bool is_data )
      : MET_Egamma10NoTau_wpx( parent.MET_Egamma10NoTau_wpx, index, this ),
        MET_Egamma10NoTau_wpy( parent.MET_Egamma10NoTau_wpy, index, this ),
        MET_Egamma10NoTau_wet( parent.MET_Egamma10NoTau_wet, index, this ),
        MET_Egamma10NoTau_statusWord( parent.MET_Egamma10NoTau_statusWord, index, this ),
        MET_Egamma10NoTau_STVF_wpx( parent.MET_Egamma10NoTau_STVF_wpx, index, this ),
        MET_Egamma10NoTau_STVF_wpy( parent.MET_Egamma10NoTau_STVF_wpy, index, this ),
        MET_Egamma10NoTau_STVF_wet( parent.MET_Egamma10NoTau_STVF_wet, index, this ),
        MET_Egamma10NoTau_STVF_statusWord( parent.MET_Egamma10NoTau_STVF_statusWord, index, this ),
// -- slimmed --         MET_LooseEgamma10NoTau_wpx( parent.MET_LooseEgamma10NoTau_wpx, index, this ),
// -- slimmed --         MET_LooseEgamma10NoTau_wpy( parent.MET_LooseEgamma10NoTau_wpy, index, this ),
// -- slimmed --         MET_LooseEgamma10NoTau_wet( parent.MET_LooseEgamma10NoTau_wet, index, this ),
// -- slimmed --         MET_LooseEgamma10NoTau_statusWord( parent.MET_LooseEgamma10NoTau_statusWord, index, this ),
// -- slimmed --         MET_wpx( parent.MET_wpx, index, this ),
// -- slimmed --         MET_wpy( parent.MET_wpy, index, this ),
// -- slimmed --         MET_wet( parent.MET_wet, index, this ),
// -- slimmed --         MET_statusWord( parent.MET_statusWord, index, this ),
// -- slimmed --         MET_STVF_wpx( parent.MET_STVF_wpx, index, this ),
// -- slimmed --         MET_STVF_wpy( parent.MET_STVF_wpy, index, this ),
// -- slimmed --         MET_STVF_wet( parent.MET_STVF_wet, index, this ),
// -- slimmed --         MET_STVF_statusWord( parent.MET_STVF_statusWord, index, this ),
        E( parent.E, index, this ),
        pt( parent.pt, index, this ),
        m( parent.m, index, this ),
        eta( parent.eta, index, this ),
        phi( parent.phi, index, this ),
        EtaOrigin( parent.EtaOrigin, index, this ),
        PhiOrigin( parent.PhiOrigin, index, this ),
        MOrigin( parent.MOrigin, index, this ),
        EtaOriginEM( parent.EtaOriginEM, index, this ),
        PhiOriginEM( parent.PhiOriginEM, index, this ),
        MOriginEM( parent.MOriginEM, index, this ),
// -- slimmed --         WIDTH( parent.WIDTH, index, this ),
// -- slimmed --         n90( parent.n90, index, this ),
// -- slimmed --         Timing( parent.Timing, index, this ),
        LArQuality( parent.LArQuality, index, this ),
        nTrk( parent.nTrk, index, this ),
        sumPtTrk( parent.sumPtTrk, index, this ),
        OriginIndex( parent.OriginIndex, index, this ),
        HECQuality( parent.HECQuality, index, this ),
        NegativeE( parent.NegativeE, index, this ),
        AverageLArQF( parent.AverageLArQF, index, this ),
// -- slimmed --         YFlip12( parent.YFlip12, index, this ),
// -- slimmed --         YFlip23( parent.YFlip23, index, this ),
// -- slimmed --         BCH_CORR_CELL( parent.BCH_CORR_CELL, index, this ),
// -- slimmed --         BCH_CORR_DOTX( parent.BCH_CORR_DOTX, index, this ),
// -- slimmed --         BCH_CORR_JET( parent.BCH_CORR_JET, index, this ),
// -- slimmed --         BCH_CORR_JET_FORCELL( parent.BCH_CORR_JET_FORCELL, index, this ),
        ENG_BAD_CELLS( parent.ENG_BAD_CELLS, index, this ),
        N_BAD_CELLS( parent.N_BAD_CELLS, index, this ),
        N_BAD_CELLS_CORR( parent.N_BAD_CELLS_CORR, index, this ),
        BAD_CELLS_CORR_E( parent.BAD_CELLS_CORR_E, index, this ),
// -- slimmed --         NumTowers( parent.NumTowers, index, this ),
// -- slimmed --         ootFracCells5( parent.ootFracCells5, index, this ),
// -- slimmed --         ootFracCells10( parent.ootFracCells10, index, this ),
// -- slimmed --         ootFracClusters5( parent.ootFracClusters5, index, this ),
// -- slimmed --         ootFracClusters10( parent.ootFracClusters10, index, this ),
        SamplingMax( parent.SamplingMax, index, this ),
        fracSamplingMax( parent.fracSamplingMax, index, this ),
        hecf( parent.hecf, index, this ),
// -- slimmed --         tgap3f( parent.tgap3f, index, this ),
// -- slimmed --         isUgly( parent.isUgly, index, this ),
// -- slimmed --         isBadLooseMinus( parent.isBadLooseMinus, index, this ),
// -- slimmed --         isBadLoose( parent.isBadLoose, index, this ),
// -- slimmed --         isBadMedium( parent.isBadMedium, index, this ),
// -- slimmed --         isBadTight( parent.isBadTight, index, this ),
        emfrac( parent.emfrac, index, this ),
        Offset( parent.Offset, index, this ),
        EMJES( parent.EMJES, index, this ),
        EMJES_EtaCorr( parent.EMJES_EtaCorr, index, this ),
        EMJESnooffset( parent.EMJESnooffset, index, this ),
        GCWJES( parent.GCWJES, index, this ),
        GCWJES_EtaCorr( parent.GCWJES_EtaCorr, index, this ),
        CB( parent.CB, index, this ),
        LCJES( parent.LCJES, index, this ),
        emscale_E( parent.emscale_E, index, this ),
        emscale_pt( parent.emscale_pt, index, this ),
        emscale_m( parent.emscale_m, index, this ),
        emscale_eta( parent.emscale_eta, index, this ),
        emscale_phi( parent.emscale_phi, index, this ),
        jvtx_x( parent.jvtx_x, index, this ),
        jvtx_y( parent.jvtx_y, index, this ),
        jvtx_z( parent.jvtx_z, index, this ),
        jvtxf( parent.jvtxf, index, this ),
        jvtxfFull( parent.jvtxfFull, index, this ),
        GSCFactorF( parent.GSCFactorF, index, this ),
        WidthFraction( parent.WidthFraction, index, this ),
        e_PreSamplerB( parent.e_PreSamplerB, index, this ),
// -- slimmed --         e_EMB1( parent.e_EMB1, index, this ),
// -- slimmed --         e_EMB2( parent.e_EMB2, index, this ),
// -- slimmed --         e_EMB3( parent.e_EMB3, index, this ),
// -- slimmed --         e_PreSamplerE( parent.e_PreSamplerE, index, this ),
// -- slimmed --         e_EME1( parent.e_EME1, index, this ),
// -- slimmed --         e_EME2( parent.e_EME2, index, this ),
// -- slimmed --         e_EME3( parent.e_EME3, index, this ),
// -- slimmed --         e_HEC0( parent.e_HEC0, index, this ),
// -- slimmed --         e_HEC1( parent.e_HEC1, index, this ),
// -- slimmed --         e_HEC2( parent.e_HEC2, index, this ),
// -- slimmed --         e_HEC3( parent.e_HEC3, index, this ),
// -- slimmed --         e_TileBar0( parent.e_TileBar0, index, this ),
// -- slimmed --         e_TileBar1( parent.e_TileBar1, index, this ),
// -- slimmed --         e_TileBar2( parent.e_TileBar2, index, this ),
// -- slimmed --         e_TileGap1( parent.e_TileGap1, index, this ),
// -- slimmed --         e_TileGap2( parent.e_TileGap2, index, this ),
// -- slimmed --         e_TileGap3( parent.e_TileGap3, index, this ),
// -- slimmed --         e_TileExt0( parent.e_TileExt0, index, this ),
// -- slimmed --         e_TileExt1( parent.e_TileExt1, index, this ),
// -- slimmed --         e_TileExt2( parent.e_TileExt2, index, this ),
// -- slimmed --         e_FCAL0( parent.e_FCAL0, index, this ),
// -- slimmed --         e_FCAL1( parent.e_FCAL1, index, this ),
// -- slimmed --         e_FCAL2( parent.e_FCAL2, index, this ),
// -- slimmed --         Nconst( parent.Nconst, index, this ),
// -- slimmed --         ptconst_default( parent.ptconst_default, index, this ),
// -- slimmed --         econst_default( parent.econst_default, index, this ),
// -- slimmed --         etaconst_default( parent.etaconst_default, index, this ),
// -- slimmed --         phiconst_default( parent.phiconst_default, index, this ),
// -- slimmed --         weightconst_default( parent.weightconst_default, index, this ),
        constscale_E( parent.constscale_E, index, this ),
        constscale_pt( parent.constscale_pt, index, this ),
        constscale_m( parent.constscale_m, index, this ),
        constscale_eta( parent.constscale_eta, index, this ),
        constscale_phi( parent.constscale_phi, index, this ),
        flavor_weight_Comb( parent.flavor_weight_Comb, index, this ),
        flavor_weight_IP2D( parent.flavor_weight_IP2D, index, this ),
        flavor_weight_IP3D( parent.flavor_weight_IP3D, index, this ),
        flavor_weight_SV0( parent.flavor_weight_SV0, index, this ),
        flavor_weight_SV1( parent.flavor_weight_SV1, index, this ),
        flavor_weight_SV2( parent.flavor_weight_SV2, index, this ),
        flavor_weight_SoftMuonTagChi2( parent.flavor_weight_SoftMuonTagChi2, index, this ),
        flavor_weight_SecondSoftMuonTagChi2( parent.flavor_weight_SecondSoftMuonTagChi2, index, this ),
        flavor_weight_JetFitterTagNN( parent.flavor_weight_JetFitterTagNN, index, this ),
        flavor_weight_JetFitterCOMBNN( parent.flavor_weight_JetFitterCOMBNN, index, this ),
        flavor_weight_MV1( parent.flavor_weight_MV1, index, this ),
        flavor_weight_MV2( parent.flavor_weight_MV2, index, this ),
        flavor_weight_GbbNN( parent.flavor_weight_GbbNN, index, this ),
// MC only
        flavor_truth_label( parent.flavor_truth_label, index, this ),
        flavor_truth_dRminToB( parent.flavor_truth_dRminToB, index, this ),
        flavor_truth_dRminToC( parent.flavor_truth_dRminToC, index, this ),
        flavor_truth_dRminToT( parent.flavor_truth_dRminToT, index, this ),
        flavor_truth_BHadronpdg( parent.flavor_truth_BHadronpdg, index, this ),
        flavor_truth_vx_x( parent.flavor_truth_vx_x, index, this ),
        flavor_truth_vx_y( parent.flavor_truth_vx_y, index, this ),
        flavor_truth_vx_z( parent.flavor_truth_vx_z, index, this ),
// end MC only
// -- slimmed --         flavor_component_ip2d_pu( parent.flavor_component_ip2d_pu, index, this ),
// -- slimmed --         flavor_component_ip2d_pb( parent.flavor_component_ip2d_pb, index, this ),
// -- slimmed --         flavor_component_ip2d_isValid( parent.flavor_component_ip2d_isValid, index, this ),
// -- slimmed --         flavor_component_ip2d_ntrk( parent.flavor_component_ip2d_ntrk, index, this ),
// -- slimmed --         flavor_component_ip3d_pu( parent.flavor_component_ip3d_pu, index, this ),
// -- slimmed --         flavor_component_ip3d_pb( parent.flavor_component_ip3d_pb, index, this ),
// -- slimmed --         flavor_component_ip3d_isValid( parent.flavor_component_ip3d_isValid, index, this ),
// -- slimmed --         flavor_component_ip3d_ntrk( parent.flavor_component_ip3d_ntrk, index, this ),
// -- slimmed --         flavor_component_sv1_pu( parent.flavor_component_sv1_pu, index, this ),
// -- slimmed --         flavor_component_sv1_pb( parent.flavor_component_sv1_pb, index, this ),
// -- slimmed --         flavor_component_sv1_isValid( parent.flavor_component_sv1_isValid, index, this ),
// -- slimmed --         flavor_component_sv2_pu( parent.flavor_component_sv2_pu, index, this ),
// -- slimmed --         flavor_component_sv2_pb( parent.flavor_component_sv2_pb, index, this ),
// -- slimmed --         flavor_component_sv2_isValid( parent.flavor_component_sv2_isValid, index, this ),
// -- slimmed --         flavor_component_jfit_pu( parent.flavor_component_jfit_pu, index, this ),
// -- slimmed --         flavor_component_jfit_pb( parent.flavor_component_jfit_pb, index, this ),
// -- slimmed --         flavor_component_jfit_pc( parent.flavor_component_jfit_pc, index, this ),
// -- slimmed --         flavor_component_jfit_isValid( parent.flavor_component_jfit_isValid, index, this ),
// -- slimmed --         flavor_component_jfitcomb_pu( parent.flavor_component_jfitcomb_pu, index, this ),
// -- slimmed --         flavor_component_jfitcomb_pb( parent.flavor_component_jfitcomb_pb, index, this ),
// -- slimmed --         flavor_component_jfitcomb_pc( parent.flavor_component_jfitcomb_pc, index, this ),
// -- slimmed --         flavor_component_jfitcomb_isValid( parent.flavor_component_jfitcomb_isValid, index, this ),
// -- slimmed --         flavor_component_jfit_nvtx( parent.flavor_component_jfit_nvtx, index, this ),
// -- slimmed --         flavor_component_jfit_nvtx1t( parent.flavor_component_jfit_nvtx1t, index, this ),
// -- slimmed --         flavor_component_jfit_ntrkAtVx( parent.flavor_component_jfit_ntrkAtVx, index, this ),
// -- slimmed --         flavor_component_jfit_efrc( parent.flavor_component_jfit_efrc, index, this ),
// -- slimmed --         flavor_component_jfit_mass( parent.flavor_component_jfit_mass, index, this ),
// -- slimmed --         flavor_component_jfit_sig3d( parent.flavor_component_jfit_sig3d, index, this ),
// -- slimmed --         flavor_component_jfit_deltaPhi( parent.flavor_component_jfit_deltaPhi, index, this ),
// -- slimmed --         flavor_component_jfit_deltaEta( parent.flavor_component_jfit_deltaEta, index, this ),
// -- slimmed --         flavor_component_svp_isValid( parent.flavor_component_svp_isValid, index, this ),
// -- slimmed --         flavor_component_svp_ntrkv( parent.flavor_component_svp_ntrkv, index, this ),
// -- slimmed --         flavor_component_svp_ntrkj( parent.flavor_component_svp_ntrkj, index, this ),
// -- slimmed --         flavor_component_svp_n2t( parent.flavor_component_svp_n2t, index, this ),
// -- slimmed --         flavor_component_svp_mass( parent.flavor_component_svp_mass, index, this ),
// -- slimmed --         flavor_component_svp_efrc( parent.flavor_component_svp_efrc, index, this ),
// -- slimmed --         flavor_component_svp_x( parent.flavor_component_svp_x, index, this ),
// -- slimmed --         flavor_component_svp_y( parent.flavor_component_svp_y, index, this ),
// -- slimmed --         flavor_component_svp_z( parent.flavor_component_svp_z, index, this ),
// -- slimmed --         flavor_component_svp_err_x( parent.flavor_component_svp_err_x, index, this ),
// -- slimmed --         flavor_component_svp_err_y( parent.flavor_component_svp_err_y, index, this ),
// -- slimmed --         flavor_component_svp_err_z( parent.flavor_component_svp_err_z, index, this ),
// -- slimmed --         flavor_component_svp_cov_xy( parent.flavor_component_svp_cov_xy, index, this ),
// -- slimmed --         flavor_component_svp_cov_xz( parent.flavor_component_svp_cov_xz, index, this ),
// -- slimmed --         flavor_component_svp_cov_yz( parent.flavor_component_svp_cov_yz, index, this ),
// -- slimmed --         flavor_component_svp_chi2( parent.flavor_component_svp_chi2, index, this ),
// -- slimmed --         flavor_component_svp_ndof( parent.flavor_component_svp_ndof, index, this ),
// -- slimmed --         flavor_component_svp_ntrk( parent.flavor_component_svp_ntrk, index, this ),
// -- slimmed --         flavor_component_sv0p_isValid( parent.flavor_component_sv0p_isValid, index, this ),
// -- slimmed --         flavor_component_sv0p_ntrkv( parent.flavor_component_sv0p_ntrkv, index, this ),
// -- slimmed --         flavor_component_sv0p_ntrkj( parent.flavor_component_sv0p_ntrkj, index, this ),
// -- slimmed --         flavor_component_sv0p_n2t( parent.flavor_component_sv0p_n2t, index, this ),
// -- slimmed --         flavor_component_sv0p_mass( parent.flavor_component_sv0p_mass, index, this ),
// -- slimmed --         flavor_component_sv0p_efrc( parent.flavor_component_sv0p_efrc, index, this ),
// -- slimmed --         flavor_component_sv0p_x( parent.flavor_component_sv0p_x, index, this ),
// -- slimmed --         flavor_component_sv0p_y( parent.flavor_component_sv0p_y, index, this ),
// -- slimmed --         flavor_component_sv0p_z( parent.flavor_component_sv0p_z, index, this ),
// -- slimmed --         flavor_component_sv0p_err_x( parent.flavor_component_sv0p_err_x, index, this ),
// -- slimmed --         flavor_component_sv0p_err_y( parent.flavor_component_sv0p_err_y, index, this ),
// -- slimmed --         flavor_component_sv0p_err_z( parent.flavor_component_sv0p_err_z, index, this ),
// -- slimmed --         flavor_component_sv0p_cov_xy( parent.flavor_component_sv0p_cov_xy, index, this ),
// -- slimmed --         flavor_component_sv0p_cov_xz( parent.flavor_component_sv0p_cov_xz, index, this ),
// -- slimmed --         flavor_component_sv0p_cov_yz( parent.flavor_component_sv0p_cov_yz, index, this ),
// -- slimmed --         flavor_component_sv0p_chi2( parent.flavor_component_sv0p_chi2, index, this ),
// -- slimmed --         flavor_component_sv0p_ndof( parent.flavor_component_sv0p_ndof, index, this ),
// -- slimmed --         flavor_component_sv0p_ntrk( parent.flavor_component_sv0p_ntrk, index, this ),
// -- slimmed --         flavor_assoctrk_n( parent.flavor_assoctrk_n, index, this ),
// -- slimmed --         flavor_assoctrk_index( parent.flavor_assoctrk_index, index, this ),
// -- slimmed --         el_dr( parent.el_dr, index, this ),
// -- slimmed --         el_matched( parent.el_matched, index, this ),
// -- slimmed --         mu_dr( parent.mu_dr, index, this ),
// -- slimmed --         mu_matched( parent.mu_matched, index, this ),
// -- slimmed --         L1_dr( parent.L1_dr, index, this ),
// -- slimmed --         L1_matched( parent.L1_matched, index, this ),
// -- slimmed --         L2_dr( parent.L2_dr, index, this ),
// -- slimmed --         L2_matched( parent.L2_matched, index, this ),
// -- slimmed --         EF_dr( parent.EF_dr, index, this ),
// -- slimmed --         EF_matched( parent.EF_matched, index, this ),
// -- slimmed --         bbDecision( parent.bbDecision, index, this ),
// -- slimmed --         SmearingFactor( parent.SmearingFactor, index, this ) , 
is_data(is_data) {

   }

   /**
    * This constructor is useful for creating copies of proxy objects.
    * Such objects are fairly cheap to copy, so the user is allowed to have
    * his/her containers of them inside an analysis code. (To select and
    * sort objects according to some criteria for instance.)
    *
    * @param parent The proxy object that should be copied
    */
   JetD3PDObjectElement::JetD3PDObjectElement( const JetD3PDObjectElement& parent , bool is_data )
      : TObject( parent ),
        MET_Egamma10NoTau_wpx( parent.MET_Egamma10NoTau_wpx ),
        MET_Egamma10NoTau_wpy( parent.MET_Egamma10NoTau_wpy ),
        MET_Egamma10NoTau_wet( parent.MET_Egamma10NoTau_wet ),
        MET_Egamma10NoTau_statusWord( parent.MET_Egamma10NoTau_statusWord ),
        MET_Egamma10NoTau_STVF_wpx( parent.MET_Egamma10NoTau_STVF_wpx ),
        MET_Egamma10NoTau_STVF_wpy( parent.MET_Egamma10NoTau_STVF_wpy ),
        MET_Egamma10NoTau_STVF_wet( parent.MET_Egamma10NoTau_STVF_wet ),
        MET_Egamma10NoTau_STVF_statusWord( parent.MET_Egamma10NoTau_STVF_statusWord ),
// -- slimmed --         MET_LooseEgamma10NoTau_wpx( parent.MET_LooseEgamma10NoTau_wpx ),
// -- slimmed --         MET_LooseEgamma10NoTau_wpy( parent.MET_LooseEgamma10NoTau_wpy ),
// -- slimmed --         MET_LooseEgamma10NoTau_wet( parent.MET_LooseEgamma10NoTau_wet ),
// -- slimmed --         MET_LooseEgamma10NoTau_statusWord( parent.MET_LooseEgamma10NoTau_statusWord ),
// -- slimmed --         MET_wpx( parent.MET_wpx ),
// -- slimmed --         MET_wpy( parent.MET_wpy ),
// -- slimmed --         MET_wet( parent.MET_wet ),
// -- slimmed --         MET_statusWord( parent.MET_statusWord ),
// -- slimmed --         MET_STVF_wpx( parent.MET_STVF_wpx ),
// -- slimmed --         MET_STVF_wpy( parent.MET_STVF_wpy ),
// -- slimmed --         MET_STVF_wet( parent.MET_STVF_wet ),
// -- slimmed --         MET_STVF_statusWord( parent.MET_STVF_statusWord ),
        E( parent.E ),
        pt( parent.pt ),
        m( parent.m ),
        eta( parent.eta ),
        phi( parent.phi ),
        EtaOrigin( parent.EtaOrigin ),
        PhiOrigin( parent.PhiOrigin ),
        MOrigin( parent.MOrigin ),
        EtaOriginEM( parent.EtaOriginEM ),
        PhiOriginEM( parent.PhiOriginEM ),
        MOriginEM( parent.MOriginEM ),
// -- slimmed --         WIDTH( parent.WIDTH ),
// -- slimmed --         n90( parent.n90 ),
// -- slimmed --         Timing( parent.Timing ),
        LArQuality( parent.LArQuality ),
        nTrk( parent.nTrk ),
        sumPtTrk( parent.sumPtTrk ),
        OriginIndex( parent.OriginIndex ),
        HECQuality( parent.HECQuality ),
        NegativeE( parent.NegativeE ),
        AverageLArQF( parent.AverageLArQF ),
// -- slimmed --         YFlip12( parent.YFlip12 ),
// -- slimmed --         YFlip23( parent.YFlip23 ),
// -- slimmed --         BCH_CORR_CELL( parent.BCH_CORR_CELL ),
// -- slimmed --         BCH_CORR_DOTX( parent.BCH_CORR_DOTX ),
// -- slimmed --         BCH_CORR_JET( parent.BCH_CORR_JET ),
// -- slimmed --         BCH_CORR_JET_FORCELL( parent.BCH_CORR_JET_FORCELL ),
        ENG_BAD_CELLS( parent.ENG_BAD_CELLS ),
        N_BAD_CELLS( parent.N_BAD_CELLS ),
        N_BAD_CELLS_CORR( parent.N_BAD_CELLS_CORR ),
        BAD_CELLS_CORR_E( parent.BAD_CELLS_CORR_E ),
// -- slimmed --         NumTowers( parent.NumTowers ),
// -- slimmed --         ootFracCells5( parent.ootFracCells5 ),
// -- slimmed --         ootFracCells10( parent.ootFracCells10 ),
// -- slimmed --         ootFracClusters5( parent.ootFracClusters5 ),
// -- slimmed --         ootFracClusters10( parent.ootFracClusters10 ),
        SamplingMax( parent.SamplingMax ),
        fracSamplingMax( parent.fracSamplingMax ),
        hecf( parent.hecf ),
// -- slimmed --         tgap3f( parent.tgap3f ),
// -- slimmed --         isUgly( parent.isUgly ),
// -- slimmed --         isBadLooseMinus( parent.isBadLooseMinus ),
// -- slimmed --         isBadLoose( parent.isBadLoose ),
// -- slimmed --         isBadMedium( parent.isBadMedium ),
// -- slimmed --         isBadTight( parent.isBadTight ),
        emfrac( parent.emfrac ),
        Offset( parent.Offset ),
        EMJES( parent.EMJES ),
        EMJES_EtaCorr( parent.EMJES_EtaCorr ),
        EMJESnooffset( parent.EMJESnooffset ),
        GCWJES( parent.GCWJES ),
        GCWJES_EtaCorr( parent.GCWJES_EtaCorr ),
        CB( parent.CB ),
        LCJES( parent.LCJES ),
        emscale_E( parent.emscale_E ),
        emscale_pt( parent.emscale_pt ),
        emscale_m( parent.emscale_m ),
        emscale_eta( parent.emscale_eta ),
        emscale_phi( parent.emscale_phi ),
        jvtx_x( parent.jvtx_x ),
        jvtx_y( parent.jvtx_y ),
        jvtx_z( parent.jvtx_z ),
        jvtxf( parent.jvtxf ),
        jvtxfFull( parent.jvtxfFull ),
        GSCFactorF( parent.GSCFactorF ),
        WidthFraction( parent.WidthFraction ),
        e_PreSamplerB( parent.e_PreSamplerB ),
// -- slimmed --         e_EMB1( parent.e_EMB1 ),
// -- slimmed --         e_EMB2( parent.e_EMB2 ),
// -- slimmed --         e_EMB3( parent.e_EMB3 ),
// -- slimmed --         e_PreSamplerE( parent.e_PreSamplerE ),
// -- slimmed --         e_EME1( parent.e_EME1 ),
// -- slimmed --         e_EME2( parent.e_EME2 ),
// -- slimmed --         e_EME3( parent.e_EME3 ),
// -- slimmed --         e_HEC0( parent.e_HEC0 ),
// -- slimmed --         e_HEC1( parent.e_HEC1 ),
// -- slimmed --         e_HEC2( parent.e_HEC2 ),
// -- slimmed --         e_HEC3( parent.e_HEC3 ),
// -- slimmed --         e_TileBar0( parent.e_TileBar0 ),
// -- slimmed --         e_TileBar1( parent.e_TileBar1 ),
// -- slimmed --         e_TileBar2( parent.e_TileBar2 ),
// -- slimmed --         e_TileGap1( parent.e_TileGap1 ),
// -- slimmed --         e_TileGap2( parent.e_TileGap2 ),
// -- slimmed --         e_TileGap3( parent.e_TileGap3 ),
// -- slimmed --         e_TileExt0( parent.e_TileExt0 ),
// -- slimmed --         e_TileExt1( parent.e_TileExt1 ),
// -- slimmed --         e_TileExt2( parent.e_TileExt2 ),
// -- slimmed --         e_FCAL0( parent.e_FCAL0 ),
// -- slimmed --         e_FCAL1( parent.e_FCAL1 ),
// -- slimmed --         e_FCAL2( parent.e_FCAL2 ),
// -- slimmed --         Nconst( parent.Nconst ),
// -- slimmed --         ptconst_default( parent.ptconst_default ),
// -- slimmed --         econst_default( parent.econst_default ),
// -- slimmed --         etaconst_default( parent.etaconst_default ),
// -- slimmed --         phiconst_default( parent.phiconst_default ),
// -- slimmed --         weightconst_default( parent.weightconst_default ),
        constscale_E( parent.constscale_E ),
        constscale_pt( parent.constscale_pt ),
        constscale_m( parent.constscale_m ),
        constscale_eta( parent.constscale_eta ),
        constscale_phi( parent.constscale_phi ),
        flavor_weight_Comb( parent.flavor_weight_Comb ),
        flavor_weight_IP2D( parent.flavor_weight_IP2D ),
        flavor_weight_IP3D( parent.flavor_weight_IP3D ),
        flavor_weight_SV0( parent.flavor_weight_SV0 ),
        flavor_weight_SV1( parent.flavor_weight_SV1 ),
        flavor_weight_SV2( parent.flavor_weight_SV2 ),
        flavor_weight_SoftMuonTagChi2( parent.flavor_weight_SoftMuonTagChi2 ),
        flavor_weight_SecondSoftMuonTagChi2( parent.flavor_weight_SecondSoftMuonTagChi2 ),
        flavor_weight_JetFitterTagNN( parent.flavor_weight_JetFitterTagNN ),
        flavor_weight_JetFitterCOMBNN( parent.flavor_weight_JetFitterCOMBNN ),
        flavor_weight_MV1( parent.flavor_weight_MV1 ),
        flavor_weight_MV2( parent.flavor_weight_MV2 ),
        flavor_weight_GbbNN( parent.flavor_weight_GbbNN ),
// MC only
        flavor_truth_label( parent.flavor_truth_label ),
        flavor_truth_dRminToB( parent.flavor_truth_dRminToB ),
        flavor_truth_dRminToC( parent.flavor_truth_dRminToC ),
        flavor_truth_dRminToT( parent.flavor_truth_dRminToT ),
        flavor_truth_BHadronpdg( parent.flavor_truth_BHadronpdg ),
        flavor_truth_vx_x( parent.flavor_truth_vx_x ),
        flavor_truth_vx_y( parent.flavor_truth_vx_y ),
        flavor_truth_vx_z( parent.flavor_truth_vx_z ),
// end MC only
// -- slimmed --         flavor_component_ip2d_pu( parent.flavor_component_ip2d_pu ),
// -- slimmed --         flavor_component_ip2d_pb( parent.flavor_component_ip2d_pb ),
// -- slimmed --         flavor_component_ip2d_isValid( parent.flavor_component_ip2d_isValid ),
// -- slimmed --         flavor_component_ip2d_ntrk( parent.flavor_component_ip2d_ntrk ),
// -- slimmed --         flavor_component_ip3d_pu( parent.flavor_component_ip3d_pu ),
// -- slimmed --         flavor_component_ip3d_pb( parent.flavor_component_ip3d_pb ),
// -- slimmed --         flavor_component_ip3d_isValid( parent.flavor_component_ip3d_isValid ),
// -- slimmed --         flavor_component_ip3d_ntrk( parent.flavor_component_ip3d_ntrk ),
// -- slimmed --         flavor_component_sv1_pu( parent.flavor_component_sv1_pu ),
// -- slimmed --         flavor_component_sv1_pb( parent.flavor_component_sv1_pb ),
// -- slimmed --         flavor_component_sv1_isValid( parent.flavor_component_sv1_isValid ),
// -- slimmed --         flavor_component_sv2_pu( parent.flavor_component_sv2_pu ),
// -- slimmed --         flavor_component_sv2_pb( parent.flavor_component_sv2_pb ),
// -- slimmed --         flavor_component_sv2_isValid( parent.flavor_component_sv2_isValid ),
// -- slimmed --         flavor_component_jfit_pu( parent.flavor_component_jfit_pu ),
// -- slimmed --         flavor_component_jfit_pb( parent.flavor_component_jfit_pb ),
// -- slimmed --         flavor_component_jfit_pc( parent.flavor_component_jfit_pc ),
// -- slimmed --         flavor_component_jfit_isValid( parent.flavor_component_jfit_isValid ),
// -- slimmed --         flavor_component_jfitcomb_pu( parent.flavor_component_jfitcomb_pu ),
// -- slimmed --         flavor_component_jfitcomb_pb( parent.flavor_component_jfitcomb_pb ),
// -- slimmed --         flavor_component_jfitcomb_pc( parent.flavor_component_jfitcomb_pc ),
// -- slimmed --         flavor_component_jfitcomb_isValid( parent.flavor_component_jfitcomb_isValid ),
// -- slimmed --         flavor_component_jfit_nvtx( parent.flavor_component_jfit_nvtx ),
// -- slimmed --         flavor_component_jfit_nvtx1t( parent.flavor_component_jfit_nvtx1t ),
// -- slimmed --         flavor_component_jfit_ntrkAtVx( parent.flavor_component_jfit_ntrkAtVx ),
// -- slimmed --         flavor_component_jfit_efrc( parent.flavor_component_jfit_efrc ),
// -- slimmed --         flavor_component_jfit_mass( parent.flavor_component_jfit_mass ),
// -- slimmed --         flavor_component_jfit_sig3d( parent.flavor_component_jfit_sig3d ),
// -- slimmed --         flavor_component_jfit_deltaPhi( parent.flavor_component_jfit_deltaPhi ),
// -- slimmed --         flavor_component_jfit_deltaEta( parent.flavor_component_jfit_deltaEta ),
// -- slimmed --         flavor_component_svp_isValid( parent.flavor_component_svp_isValid ),
// -- slimmed --         flavor_component_svp_ntrkv( parent.flavor_component_svp_ntrkv ),
// -- slimmed --         flavor_component_svp_ntrkj( parent.flavor_component_svp_ntrkj ),
// -- slimmed --         flavor_component_svp_n2t( parent.flavor_component_svp_n2t ),
// -- slimmed --         flavor_component_svp_mass( parent.flavor_component_svp_mass ),
// -- slimmed --         flavor_component_svp_efrc( parent.flavor_component_svp_efrc ),
// -- slimmed --         flavor_component_svp_x( parent.flavor_component_svp_x ),
// -- slimmed --         flavor_component_svp_y( parent.flavor_component_svp_y ),
// -- slimmed --         flavor_component_svp_z( parent.flavor_component_svp_z ),
// -- slimmed --         flavor_component_svp_err_x( parent.flavor_component_svp_err_x ),
// -- slimmed --         flavor_component_svp_err_y( parent.flavor_component_svp_err_y ),
// -- slimmed --         flavor_component_svp_err_z( parent.flavor_component_svp_err_z ),
// -- slimmed --         flavor_component_svp_cov_xy( parent.flavor_component_svp_cov_xy ),
// -- slimmed --         flavor_component_svp_cov_xz( parent.flavor_component_svp_cov_xz ),
// -- slimmed --         flavor_component_svp_cov_yz( parent.flavor_component_svp_cov_yz ),
// -- slimmed --         flavor_component_svp_chi2( parent.flavor_component_svp_chi2 ),
// -- slimmed --         flavor_component_svp_ndof( parent.flavor_component_svp_ndof ),
// -- slimmed --         flavor_component_svp_ntrk( parent.flavor_component_svp_ntrk ),
// -- slimmed --         flavor_component_sv0p_isValid( parent.flavor_component_sv0p_isValid ),
// -- slimmed --         flavor_component_sv0p_ntrkv( parent.flavor_component_sv0p_ntrkv ),
// -- slimmed --         flavor_component_sv0p_ntrkj( parent.flavor_component_sv0p_ntrkj ),
// -- slimmed --         flavor_component_sv0p_n2t( parent.flavor_component_sv0p_n2t ),
// -- slimmed --         flavor_component_sv0p_mass( parent.flavor_component_sv0p_mass ),
// -- slimmed --         flavor_component_sv0p_efrc( parent.flavor_component_sv0p_efrc ),
// -- slimmed --         flavor_component_sv0p_x( parent.flavor_component_sv0p_x ),
// -- slimmed --         flavor_component_sv0p_y( parent.flavor_component_sv0p_y ),
// -- slimmed --         flavor_component_sv0p_z( parent.flavor_component_sv0p_z ),
// -- slimmed --         flavor_component_sv0p_err_x( parent.flavor_component_sv0p_err_x ),
// -- slimmed --         flavor_component_sv0p_err_y( parent.flavor_component_sv0p_err_y ),
// -- slimmed --         flavor_component_sv0p_err_z( parent.flavor_component_sv0p_err_z ),
// -- slimmed --         flavor_component_sv0p_cov_xy( parent.flavor_component_sv0p_cov_xy ),
// -- slimmed --         flavor_component_sv0p_cov_xz( parent.flavor_component_sv0p_cov_xz ),
// -- slimmed --         flavor_component_sv0p_cov_yz( parent.flavor_component_sv0p_cov_yz ),
// -- slimmed --         flavor_component_sv0p_chi2( parent.flavor_component_sv0p_chi2 ),
// -- slimmed --         flavor_component_sv0p_ndof( parent.flavor_component_sv0p_ndof ),
// -- slimmed --         flavor_component_sv0p_ntrk( parent.flavor_component_sv0p_ntrk ),
// -- slimmed --         flavor_assoctrk_n( parent.flavor_assoctrk_n ),
// -- slimmed --         flavor_assoctrk_index( parent.flavor_assoctrk_index ),
// -- slimmed --         el_dr( parent.el_dr ),
// -- slimmed --         el_matched( parent.el_matched ),
// -- slimmed --         mu_dr( parent.mu_dr ),
// -- slimmed --         mu_matched( parent.mu_matched ),
// -- slimmed --         L1_dr( parent.L1_dr ),
// -- slimmed --         L1_matched( parent.L1_matched ),
// -- slimmed --         L2_dr( parent.L2_dr ),
// -- slimmed --         L2_matched( parent.L2_matched ),
// -- slimmed --         EF_dr( parent.EF_dr ),
// -- slimmed --         EF_matched( parent.EF_matched ),
// -- slimmed --         bbDecision( parent.bbDecision ),
// -- slimmed --         SmearingFactor( parent.SmearingFactor ) , 
is_data(is_data) {

   }

   /**
    * This constructor should be used when the object will be used to read
    * variables from an existing ntuple. The object will also be able to
    * output variables, but it will also need to read them from somewhere.
    *
    * @param master Reference to the variable holding the current event number
    * @param prefix Prefix of the variables in the D3PD
    */
   JetD3PDObject::JetD3PDObject( const ::Long64_t& master, const char* prefix , bool is_data )
      : TObject(),
        MET_Egamma10NoTau_wpx( this, ::TString( prefix ) + "MET_Egamma10NoTau_wpx", &master ),
        MET_Egamma10NoTau_wpy( this, ::TString( prefix ) + "MET_Egamma10NoTau_wpy", &master ),
        MET_Egamma10NoTau_wet( this, ::TString( prefix ) + "MET_Egamma10NoTau_wet", &master ),
        MET_Egamma10NoTau_statusWord( this, ::TString( prefix ) + "MET_Egamma10NoTau_statusWord", &master ),
        MET_Egamma10NoTau_STVF_wpx( this, ::TString( prefix ) + "MET_Egamma10NoTau_STVF_wpx", &master ),
        MET_Egamma10NoTau_STVF_wpy( this, ::TString( prefix ) + "MET_Egamma10NoTau_STVF_wpy", &master ),
        MET_Egamma10NoTau_STVF_wet( this, ::TString( prefix ) + "MET_Egamma10NoTau_STVF_wet", &master ),
        MET_Egamma10NoTau_STVF_statusWord( this, ::TString( prefix ) + "MET_Egamma10NoTau_STVF_statusWord", &master ),
// -- slimmed --         MET_LooseEgamma10NoTau_wpx( this, ::TString( prefix ) + "MET_LooseEgamma10NoTau_wpx", &master ),
// -- slimmed --         MET_LooseEgamma10NoTau_wpy( this, ::TString( prefix ) + "MET_LooseEgamma10NoTau_wpy", &master ),
// -- slimmed --         MET_LooseEgamma10NoTau_wet( this, ::TString( prefix ) + "MET_LooseEgamma10NoTau_wet", &master ),
// -- slimmed --         MET_LooseEgamma10NoTau_statusWord( this, ::TString( prefix ) + "MET_LooseEgamma10NoTau_statusWord", &master ),
// -- slimmed --         MET_wpx( this, ::TString( prefix ) + "MET_wpx", &master ),
// -- slimmed --         MET_wpy( this, ::TString( prefix ) + "MET_wpy", &master ),
// -- slimmed --         MET_wet( this, ::TString( prefix ) + "MET_wet", &master ),
// -- slimmed --         MET_statusWord( this, ::TString( prefix ) + "MET_statusWord", &master ),
// -- slimmed --         MET_STVF_wpx( this, ::TString( prefix ) + "MET_STVF_wpx", &master ),
// -- slimmed --         MET_STVF_wpy( this, ::TString( prefix ) + "MET_STVF_wpy", &master ),
// -- slimmed --         MET_STVF_wet( this, ::TString( prefix ) + "MET_STVF_wet", &master ),
// -- slimmed --         MET_STVF_statusWord( this, ::TString( prefix ) + "MET_STVF_statusWord", &master ),
        n( this, ::TString( prefix ) + "n", &master ),
        E( this, ::TString( prefix ) + "E", &master ),
        pt( this, ::TString( prefix ) + "pt", &master ),
        m( this, ::TString( prefix ) + "m", &master ),
        eta( this, ::TString( prefix ) + "eta", &master ),
        phi( this, ::TString( prefix ) + "phi", &master ),
        EtaOrigin( this, ::TString( prefix ) + "EtaOrigin", &master ),
        PhiOrigin( this, ::TString( prefix ) + "PhiOrigin", &master ),
        MOrigin( this, ::TString( prefix ) + "MOrigin", &master ),
        EtaOriginEM( this, ::TString( prefix ) + "EtaOriginEM", &master ),
        PhiOriginEM( this, ::TString( prefix ) + "PhiOriginEM", &master ),
        MOriginEM( this, ::TString( prefix ) + "MOriginEM", &master ),
// -- slimmed --         WIDTH( this, ::TString( prefix ) + "WIDTH", &master ),
// -- slimmed --         n90( this, ::TString( prefix ) + "n90", &master ),
// -- slimmed --         Timing( this, ::TString( prefix ) + "Timing", &master ),
        LArQuality( this, ::TString( prefix ) + "LArQuality", &master ),
        nTrk( this, ::TString( prefix ) + "nTrk", &master ),
        sumPtTrk( this, ::TString( prefix ) + "sumPtTrk", &master ),
        OriginIndex( this, ::TString( prefix ) + "OriginIndex", &master ),
        HECQuality( this, ::TString( prefix ) + "HECQuality", &master ),
        NegativeE( this, ::TString( prefix ) + "NegativeE", &master ),
        AverageLArQF( this, ::TString( prefix ) + "AverageLArQF", &master ),
// -- slimmed --         YFlip12( this, ::TString( prefix ) + "YFlip12", &master ),
// -- slimmed --         YFlip23( this, ::TString( prefix ) + "YFlip23", &master ),
// -- slimmed --         BCH_CORR_CELL( this, ::TString( prefix ) + "BCH_CORR_CELL", &master ),
// -- slimmed --         BCH_CORR_DOTX( this, ::TString( prefix ) + "BCH_CORR_DOTX", &master ),
// -- slimmed --         BCH_CORR_JET( this, ::TString( prefix ) + "BCH_CORR_JET", &master ),
// -- slimmed --         BCH_CORR_JET_FORCELL( this, ::TString( prefix ) + "BCH_CORR_JET_FORCELL", &master ),
        ENG_BAD_CELLS( this, ::TString( prefix ) + "ENG_BAD_CELLS", &master ),
        N_BAD_CELLS( this, ::TString( prefix ) + "N_BAD_CELLS", &master ),
        N_BAD_CELLS_CORR( this, ::TString( prefix ) + "N_BAD_CELLS_CORR", &master ),
        BAD_CELLS_CORR_E( this, ::TString( prefix ) + "BAD_CELLS_CORR_E", &master ),
// -- slimmed --         NumTowers( this, ::TString( prefix ) + "NumTowers", &master ),
// -- slimmed --         ootFracCells5( this, ::TString( prefix ) + "ootFracCells5", &master ),
// -- slimmed --         ootFracCells10( this, ::TString( prefix ) + "ootFracCells10", &master ),
// -- slimmed --         ootFracClusters5( this, ::TString( prefix ) + "ootFracClusters5", &master ),
// -- slimmed --         ootFracClusters10( this, ::TString( prefix ) + "ootFracClusters10", &master ),
        SamplingMax( this, ::TString( prefix ) + "SamplingMax", &master ),
        fracSamplingMax( this, ::TString( prefix ) + "fracSamplingMax", &master ),
        hecf( this, ::TString( prefix ) + "hecf", &master ),
// -- slimmed --         tgap3f( this, ::TString( prefix ) + "tgap3f", &master ),
// -- slimmed --         isUgly( this, ::TString( prefix ) + "isUgly", &master ),
// -- slimmed --         isBadLooseMinus( this, ::TString( prefix ) + "isBadLooseMinus", &master ),
// -- slimmed --         isBadLoose( this, ::TString( prefix ) + "isBadLoose", &master ),
// -- slimmed --         isBadMedium( this, ::TString( prefix ) + "isBadMedium", &master ),
// -- slimmed --         isBadTight( this, ::TString( prefix ) + "isBadTight", &master ),
        emfrac( this, ::TString( prefix ) + "emfrac", &master ),
        Offset( this, ::TString( prefix ) + "Offset", &master ),
        EMJES( this, ::TString( prefix ) + "EMJES", &master ),
        EMJES_EtaCorr( this, ::TString( prefix ) + "EMJES_EtaCorr", &master ),
        EMJESnooffset( this, ::TString( prefix ) + "EMJESnooffset", &master ),
        GCWJES( this, ::TString( prefix ) + "GCWJES", &master ),
        GCWJES_EtaCorr( this, ::TString( prefix ) + "GCWJES_EtaCorr", &master ),
        CB( this, ::TString( prefix ) + "CB", &master ),
        LCJES( this, ::TString( prefix ) + "LCJES", &master ),
        emscale_E( this, ::TString( prefix ) + "emscale_E", &master ),
        emscale_pt( this, ::TString( prefix ) + "emscale_pt", &master ),
        emscale_m( this, ::TString( prefix ) + "emscale_m", &master ),
        emscale_eta( this, ::TString( prefix ) + "emscale_eta", &master ),
        emscale_phi( this, ::TString( prefix ) + "emscale_phi", &master ),
        jvtx_x( this, ::TString( prefix ) + "jvtx_x", &master ),
        jvtx_y( this, ::TString( prefix ) + "jvtx_y", &master ),
        jvtx_z( this, ::TString( prefix ) + "jvtx_z", &master ),
        jvtxf( this, ::TString( prefix ) + "jvtxf", &master ),
        jvtxfFull( this, ::TString( prefix ) + "jvtxfFull", &master ),
        GSCFactorF( this, ::TString( prefix ) + "GSCFactorF", &master ),
        WidthFraction( this, ::TString( prefix ) + "WidthFraction", &master ),
        e_PreSamplerB( this, ::TString( prefix ) + "e_PreSamplerB", &master ),
// -- slimmed --         e_EMB1( this, ::TString( prefix ) + "e_EMB1", &master ),
// -- slimmed --         e_EMB2( this, ::TString( prefix ) + "e_EMB2", &master ),
// -- slimmed --         e_EMB3( this, ::TString( prefix ) + "e_EMB3", &master ),
// -- slimmed --         e_PreSamplerE( this, ::TString( prefix ) + "e_PreSamplerE", &master ),
// -- slimmed --         e_EME1( this, ::TString( prefix ) + "e_EME1", &master ),
// -- slimmed --         e_EME2( this, ::TString( prefix ) + "e_EME2", &master ),
// -- slimmed --         e_EME3( this, ::TString( prefix ) + "e_EME3", &master ),
// -- slimmed --         e_HEC0( this, ::TString( prefix ) + "e_HEC0", &master ),
// -- slimmed --         e_HEC1( this, ::TString( prefix ) + "e_HEC1", &master ),
// -- slimmed --         e_HEC2( this, ::TString( prefix ) + "e_HEC2", &master ),
// -- slimmed --         e_HEC3( this, ::TString( prefix ) + "e_HEC3", &master ),
// -- slimmed --         e_TileBar0( this, ::TString( prefix ) + "e_TileBar0", &master ),
// -- slimmed --         e_TileBar1( this, ::TString( prefix ) + "e_TileBar1", &master ),
// -- slimmed --         e_TileBar2( this, ::TString( prefix ) + "e_TileBar2", &master ),
// -- slimmed --         e_TileGap1( this, ::TString( prefix ) + "e_TileGap1", &master ),
// -- slimmed --         e_TileGap2( this, ::TString( prefix ) + "e_TileGap2", &master ),
// -- slimmed --         e_TileGap3( this, ::TString( prefix ) + "e_TileGap3", &master ),
// -- slimmed --         e_TileExt0( this, ::TString( prefix ) + "e_TileExt0", &master ),
// -- slimmed --         e_TileExt1( this, ::TString( prefix ) + "e_TileExt1", &master ),
// -- slimmed --         e_TileExt2( this, ::TString( prefix ) + "e_TileExt2", &master ),
// -- slimmed --         e_FCAL0( this, ::TString( prefix ) + "e_FCAL0", &master ),
// -- slimmed --         e_FCAL1( this, ::TString( prefix ) + "e_FCAL1", &master ),
// -- slimmed --         e_FCAL2( this, ::TString( prefix ) + "e_FCAL2", &master ),
// -- slimmed --         Nconst( this, ::TString( prefix ) + "Nconst", &master ),
// -- slimmed --         ptconst_default( this, ::TString( prefix ) + "ptconst_default", &master ),
// -- slimmed --         econst_default( this, ::TString( prefix ) + "econst_default", &master ),
// -- slimmed --         etaconst_default( this, ::TString( prefix ) + "etaconst_default", &master ),
// -- slimmed --         phiconst_default( this, ::TString( prefix ) + "phiconst_default", &master ),
// -- slimmed --         weightconst_default( this, ::TString( prefix ) + "weightconst_default", &master ),
        constscale_E( this, ::TString( prefix ) + "constscale_E", &master ),
        constscale_pt( this, ::TString( prefix ) + "constscale_pt", &master ),
        constscale_m( this, ::TString( prefix ) + "constscale_m", &master ),
        constscale_eta( this, ::TString( prefix ) + "constscale_eta", &master ),
        constscale_phi( this, ::TString( prefix ) + "constscale_phi", &master ),
        flavor_weight_Comb( this, ::TString( prefix ) + "flavor_weight_Comb", &master ),
        flavor_weight_IP2D( this, ::TString( prefix ) + "flavor_weight_IP2D", &master ),
        flavor_weight_IP3D( this, ::TString( prefix ) + "flavor_weight_IP3D", &master ),
        flavor_weight_SV0( this, ::TString( prefix ) + "flavor_weight_SV0", &master ),
        flavor_weight_SV1( this, ::TString( prefix ) + "flavor_weight_SV1", &master ),
        flavor_weight_SV2( this, ::TString( prefix ) + "flavor_weight_SV2", &master ),
        flavor_weight_SoftMuonTagChi2( this, ::TString( prefix ) + "flavor_weight_SoftMuonTagChi2", &master ),
        flavor_weight_SecondSoftMuonTagChi2( this, ::TString( prefix ) + "flavor_weight_SecondSoftMuonTagChi2", &master ),
        flavor_weight_JetFitterTagNN( this, ::TString( prefix ) + "flavor_weight_JetFitterTagNN", &master ),
        flavor_weight_JetFitterCOMBNN( this, ::TString( prefix ) + "flavor_weight_JetFitterCOMBNN", &master ),
        flavor_weight_MV1( this, ::TString( prefix ) + "flavor_weight_MV1", &master ),
        flavor_weight_MV2( this, ::TString( prefix ) + "flavor_weight_MV2", &master ),
        flavor_weight_GbbNN( this, ::TString( prefix ) + "flavor_weight_GbbNN", &master ),
// MC only
        flavor_truth_label( this, ::TString( prefix ) + "flavor_truth_label", &master ),
        flavor_truth_dRminToB( this, ::TString( prefix ) + "flavor_truth_dRminToB", &master ),
        flavor_truth_dRminToC( this, ::TString( prefix ) + "flavor_truth_dRminToC", &master ),
        flavor_truth_dRminToT( this, ::TString( prefix ) + "flavor_truth_dRminToT", &master ),
        flavor_truth_BHadronpdg( this, ::TString( prefix ) + "flavor_truth_BHadronpdg", &master ),
        flavor_truth_vx_x( this, ::TString( prefix ) + "flavor_truth_vx_x", &master ),
        flavor_truth_vx_y( this, ::TString( prefix ) + "flavor_truth_vx_y", &master ),
        flavor_truth_vx_z( this, ::TString( prefix ) + "flavor_truth_vx_z", &master ),
// end MC only
// -- slimmed --         flavor_component_ip2d_pu( this, ::TString( prefix ) + "flavor_component_ip2d_pu", &master ),
// -- slimmed --         flavor_component_ip2d_pb( this, ::TString( prefix ) + "flavor_component_ip2d_pb", &master ),
// -- slimmed --         flavor_component_ip2d_isValid( this, ::TString( prefix ) + "flavor_component_ip2d_isValid", &master ),
// -- slimmed --         flavor_component_ip2d_ntrk( this, ::TString( prefix ) + "flavor_component_ip2d_ntrk", &master ),
// -- slimmed --         flavor_component_ip3d_pu( this, ::TString( prefix ) + "flavor_component_ip3d_pu", &master ),
// -- slimmed --         flavor_component_ip3d_pb( this, ::TString( prefix ) + "flavor_component_ip3d_pb", &master ),
// -- slimmed --         flavor_component_ip3d_isValid( this, ::TString( prefix ) + "flavor_component_ip3d_isValid", &master ),
// -- slimmed --         flavor_component_ip3d_ntrk( this, ::TString( prefix ) + "flavor_component_ip3d_ntrk", &master ),
// -- slimmed --         flavor_component_sv1_pu( this, ::TString( prefix ) + "flavor_component_sv1_pu", &master ),
// -- slimmed --         flavor_component_sv1_pb( this, ::TString( prefix ) + "flavor_component_sv1_pb", &master ),
// -- slimmed --         flavor_component_sv1_isValid( this, ::TString( prefix ) + "flavor_component_sv1_isValid", &master ),
// -- slimmed --         flavor_component_sv2_pu( this, ::TString( prefix ) + "flavor_component_sv2_pu", &master ),
// -- slimmed --         flavor_component_sv2_pb( this, ::TString( prefix ) + "flavor_component_sv2_pb", &master ),
// -- slimmed --         flavor_component_sv2_isValid( this, ::TString( prefix ) + "flavor_component_sv2_isValid", &master ),
// -- slimmed --         flavor_component_jfit_pu( this, ::TString( prefix ) + "flavor_component_jfit_pu", &master ),
// -- slimmed --         flavor_component_jfit_pb( this, ::TString( prefix ) + "flavor_component_jfit_pb", &master ),
// -- slimmed --         flavor_component_jfit_pc( this, ::TString( prefix ) + "flavor_component_jfit_pc", &master ),
// -- slimmed --         flavor_component_jfit_isValid( this, ::TString( prefix ) + "flavor_component_jfit_isValid", &master ),
// -- slimmed --         flavor_component_jfitcomb_pu( this, ::TString( prefix ) + "flavor_component_jfitcomb_pu", &master ),
// -- slimmed --         flavor_component_jfitcomb_pb( this, ::TString( prefix ) + "flavor_component_jfitcomb_pb", &master ),
// -- slimmed --         flavor_component_jfitcomb_pc( this, ::TString( prefix ) + "flavor_component_jfitcomb_pc", &master ),
// -- slimmed --         flavor_component_jfitcomb_isValid( this, ::TString( prefix ) + "flavor_component_jfitcomb_isValid", &master ),
// -- slimmed --         flavor_component_jfit_nvtx( this, ::TString( prefix ) + "flavor_component_jfit_nvtx", &master ),
// -- slimmed --         flavor_component_jfit_nvtx1t( this, ::TString( prefix ) + "flavor_component_jfit_nvtx1t", &master ),
// -- slimmed --         flavor_component_jfit_ntrkAtVx( this, ::TString( prefix ) + "flavor_component_jfit_ntrkAtVx", &master ),
// -- slimmed --         flavor_component_jfit_efrc( this, ::TString( prefix ) + "flavor_component_jfit_efrc", &master ),
// -- slimmed --         flavor_component_jfit_mass( this, ::TString( prefix ) + "flavor_component_jfit_mass", &master ),
// -- slimmed --         flavor_component_jfit_sig3d( this, ::TString( prefix ) + "flavor_component_jfit_sig3d", &master ),
// -- slimmed --         flavor_component_jfit_deltaPhi( this, ::TString( prefix ) + "flavor_component_jfit_deltaPhi", &master ),
// -- slimmed --         flavor_component_jfit_deltaEta( this, ::TString( prefix ) + "flavor_component_jfit_deltaEta", &master ),
// -- slimmed --         flavor_component_svp_isValid( this, ::TString( prefix ) + "flavor_component_svp_isValid", &master ),
// -- slimmed --         flavor_component_svp_ntrkv( this, ::TString( prefix ) + "flavor_component_svp_ntrkv", &master ),
// -- slimmed --         flavor_component_svp_ntrkj( this, ::TString( prefix ) + "flavor_component_svp_ntrkj", &master ),
// -- slimmed --         flavor_component_svp_n2t( this, ::TString( prefix ) + "flavor_component_svp_n2t", &master ),
// -- slimmed --         flavor_component_svp_mass( this, ::TString( prefix ) + "flavor_component_svp_mass", &master ),
// -- slimmed --         flavor_component_svp_efrc( this, ::TString( prefix ) + "flavor_component_svp_efrc", &master ),
// -- slimmed --         flavor_component_svp_x( this, ::TString( prefix ) + "flavor_component_svp_x", &master ),
// -- slimmed --         flavor_component_svp_y( this, ::TString( prefix ) + "flavor_component_svp_y", &master ),
// -- slimmed --         flavor_component_svp_z( this, ::TString( prefix ) + "flavor_component_svp_z", &master ),
// -- slimmed --         flavor_component_svp_err_x( this, ::TString( prefix ) + "flavor_component_svp_err_x", &master ),
// -- slimmed --         flavor_component_svp_err_y( this, ::TString( prefix ) + "flavor_component_svp_err_y", &master ),
// -- slimmed --         flavor_component_svp_err_z( this, ::TString( prefix ) + "flavor_component_svp_err_z", &master ),
// -- slimmed --         flavor_component_svp_cov_xy( this, ::TString( prefix ) + "flavor_component_svp_cov_xy", &master ),
// -- slimmed --         flavor_component_svp_cov_xz( this, ::TString( prefix ) + "flavor_component_svp_cov_xz", &master ),
// -- slimmed --         flavor_component_svp_cov_yz( this, ::TString( prefix ) + "flavor_component_svp_cov_yz", &master ),
// -- slimmed --         flavor_component_svp_chi2( this, ::TString( prefix ) + "flavor_component_svp_chi2", &master ),
// -- slimmed --         flavor_component_svp_ndof( this, ::TString( prefix ) + "flavor_component_svp_ndof", &master ),
// -- slimmed --         flavor_component_svp_ntrk( this, ::TString( prefix ) + "flavor_component_svp_ntrk", &master ),
// -- slimmed --         flavor_component_sv0p_isValid( this, ::TString( prefix ) + "flavor_component_sv0p_isValid", &master ),
// -- slimmed --         flavor_component_sv0p_ntrkv( this, ::TString( prefix ) + "flavor_component_sv0p_ntrkv", &master ),
// -- slimmed --         flavor_component_sv0p_ntrkj( this, ::TString( prefix ) + "flavor_component_sv0p_ntrkj", &master ),
// -- slimmed --         flavor_component_sv0p_n2t( this, ::TString( prefix ) + "flavor_component_sv0p_n2t", &master ),
// -- slimmed --         flavor_component_sv0p_mass( this, ::TString( prefix ) + "flavor_component_sv0p_mass", &master ),
// -- slimmed --         flavor_component_sv0p_efrc( this, ::TString( prefix ) + "flavor_component_sv0p_efrc", &master ),
// -- slimmed --         flavor_component_sv0p_x( this, ::TString( prefix ) + "flavor_component_sv0p_x", &master ),
// -- slimmed --         flavor_component_sv0p_y( this, ::TString( prefix ) + "flavor_component_sv0p_y", &master ),
// -- slimmed --         flavor_component_sv0p_z( this, ::TString( prefix ) + "flavor_component_sv0p_z", &master ),
// -- slimmed --         flavor_component_sv0p_err_x( this, ::TString( prefix ) + "flavor_component_sv0p_err_x", &master ),
// -- slimmed --         flavor_component_sv0p_err_y( this, ::TString( prefix ) + "flavor_component_sv0p_err_y", &master ),
// -- slimmed --         flavor_component_sv0p_err_z( this, ::TString( prefix ) + "flavor_component_sv0p_err_z", &master ),
// -- slimmed --         flavor_component_sv0p_cov_xy( this, ::TString( prefix ) + "flavor_component_sv0p_cov_xy", &master ),
// -- slimmed --         flavor_component_sv0p_cov_xz( this, ::TString( prefix ) + "flavor_component_sv0p_cov_xz", &master ),
// -- slimmed --         flavor_component_sv0p_cov_yz( this, ::TString( prefix ) + "flavor_component_sv0p_cov_yz", &master ),
// -- slimmed --         flavor_component_sv0p_chi2( this, ::TString( prefix ) + "flavor_component_sv0p_chi2", &master ),
// -- slimmed --         flavor_component_sv0p_ndof( this, ::TString( prefix ) + "flavor_component_sv0p_ndof", &master ),
// -- slimmed --         flavor_component_sv0p_ntrk( this, ::TString( prefix ) + "flavor_component_sv0p_ntrk", &master ),
// -- slimmed --         flavor_assoctrk_n( this, ::TString( prefix ) + "flavor_assoctrk_n", &master ),
// -- slimmed --         flavor_assoctrk_index( this, ::TString( prefix ) + "flavor_assoctrk_index", &master ),
// -- slimmed --         el_dr( this, ::TString( prefix ) + "el_dr", &master ),
// -- slimmed --         el_matched( this, ::TString( prefix ) + "el_matched", &master ),
// -- slimmed --         mu_dr( this, ::TString( prefix ) + "mu_dr", &master ),
// -- slimmed --         mu_matched( this, ::TString( prefix ) + "mu_matched", &master ),
// -- slimmed --         L1_dr( this, ::TString( prefix ) + "L1_dr", &master ),
// -- slimmed --         L1_matched( this, ::TString( prefix ) + "L1_matched", &master ),
// -- slimmed --         L2_dr( this, ::TString( prefix ) + "L2_dr", &master ),
// -- slimmed --         L2_matched( this, ::TString( prefix ) + "L2_matched", &master ),
// -- slimmed --         EF_dr( this, ::TString( prefix ) + "EF_dr", &master ),
// -- slimmed --         EF_matched( this, ::TString( prefix ) + "EF_matched", &master ),
// -- slimmed --         bbDecision( this, ::TString( prefix ) + "bbDecision", &master ),
// -- slimmed --         SmearingFactor( this, ::TString( prefix ) + "SmearingFactor", &master ),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "MET_Egamma10NoTau_wpx" ] = &MET_Egamma10NoTau_wpx;
      fHandles[ "MET_Egamma10NoTau_wpy" ] = &MET_Egamma10NoTau_wpy;
      fHandles[ "MET_Egamma10NoTau_wet" ] = &MET_Egamma10NoTau_wet;
      fHandles[ "MET_Egamma10NoTau_statusWord" ] = &MET_Egamma10NoTau_statusWord;
      fHandles[ "MET_Egamma10NoTau_STVF_wpx" ] = &MET_Egamma10NoTau_STVF_wpx;
      fHandles[ "MET_Egamma10NoTau_STVF_wpy" ] = &MET_Egamma10NoTau_STVF_wpy;
      fHandles[ "MET_Egamma10NoTau_STVF_wet" ] = &MET_Egamma10NoTau_STVF_wet;
      fHandles[ "MET_Egamma10NoTau_STVF_statusWord" ] = &MET_Egamma10NoTau_STVF_statusWord;
// -- slimmed --       fHandles[ "MET_LooseEgamma10NoTau_wpx" ] = &MET_LooseEgamma10NoTau_wpx;
// -- slimmed --       fHandles[ "MET_LooseEgamma10NoTau_wpy" ] = &MET_LooseEgamma10NoTau_wpy;
// -- slimmed --       fHandles[ "MET_LooseEgamma10NoTau_wet" ] = &MET_LooseEgamma10NoTau_wet;
// -- slimmed --       fHandles[ "MET_LooseEgamma10NoTau_statusWord" ] = &MET_LooseEgamma10NoTau_statusWord;
// -- slimmed --       fHandles[ "MET_wpx" ] = &MET_wpx;
// -- slimmed --       fHandles[ "MET_wpy" ] = &MET_wpy;
// -- slimmed --       fHandles[ "MET_wet" ] = &MET_wet;
// -- slimmed --       fHandles[ "MET_statusWord" ] = &MET_statusWord;
// -- slimmed --       fHandles[ "MET_STVF_wpx" ] = &MET_STVF_wpx;
// -- slimmed --       fHandles[ "MET_STVF_wpy" ] = &MET_STVF_wpy;
// -- slimmed --       fHandles[ "MET_STVF_wet" ] = &MET_STVF_wet;
// -- slimmed --       fHandles[ "MET_STVF_statusWord" ] = &MET_STVF_statusWord;
      fHandles[ "n" ] = &n;
      fHandles[ "E" ] = &E;
      fHandles[ "pt" ] = &pt;
      fHandles[ "m" ] = &m;
      fHandles[ "eta" ] = &eta;
      fHandles[ "phi" ] = &phi;
      fHandles[ "EtaOrigin" ] = &EtaOrigin;
      fHandles[ "PhiOrigin" ] = &PhiOrigin;
      fHandles[ "MOrigin" ] = &MOrigin;
      fHandles[ "EtaOriginEM" ] = &EtaOriginEM;
      fHandles[ "PhiOriginEM" ] = &PhiOriginEM;
      fHandles[ "MOriginEM" ] = &MOriginEM;
// -- slimmed --       fHandles[ "WIDTH" ] = &WIDTH;
// -- slimmed --       fHandles[ "n90" ] = &n90;
// -- slimmed --       fHandles[ "Timing" ] = &Timing;
      fHandles[ "LArQuality" ] = &LArQuality;
      fHandles[ "nTrk" ] = &nTrk;
      fHandles[ "sumPtTrk" ] = &sumPtTrk;
      fHandles[ "OriginIndex" ] = &OriginIndex;
      fHandles[ "HECQuality" ] = &HECQuality;
      fHandles[ "NegativeE" ] = &NegativeE;
      fHandles[ "AverageLArQF" ] = &AverageLArQF;
// -- slimmed --       fHandles[ "YFlip12" ] = &YFlip12;
// -- slimmed --       fHandles[ "YFlip23" ] = &YFlip23;
// -- slimmed --       fHandles[ "BCH_CORR_CELL" ] = &BCH_CORR_CELL;
// -- slimmed --       fHandles[ "BCH_CORR_DOTX" ] = &BCH_CORR_DOTX;
// -- slimmed --       fHandles[ "BCH_CORR_JET" ] = &BCH_CORR_JET;
// -- slimmed --       fHandles[ "BCH_CORR_JET_FORCELL" ] = &BCH_CORR_JET_FORCELL;
      fHandles[ "ENG_BAD_CELLS" ] = &ENG_BAD_CELLS;
      fHandles[ "N_BAD_CELLS" ] = &N_BAD_CELLS;
      fHandles[ "N_BAD_CELLS_CORR" ] = &N_BAD_CELLS_CORR;
      fHandles[ "BAD_CELLS_CORR_E" ] = &BAD_CELLS_CORR_E;
// -- slimmed --       fHandles[ "NumTowers" ] = &NumTowers;
// -- slimmed --       fHandles[ "ootFracCells5" ] = &ootFracCells5;
// -- slimmed --       fHandles[ "ootFracCells10" ] = &ootFracCells10;
// -- slimmed --       fHandles[ "ootFracClusters5" ] = &ootFracClusters5;
// -- slimmed --       fHandles[ "ootFracClusters10" ] = &ootFracClusters10;
      fHandles[ "SamplingMax" ] = &SamplingMax;
      fHandles[ "fracSamplingMax" ] = &fracSamplingMax;
      fHandles[ "hecf" ] = &hecf;
// -- slimmed --       fHandles[ "tgap3f" ] = &tgap3f;
// -- slimmed --       fHandles[ "isUgly" ] = &isUgly;
// -- slimmed --       fHandles[ "isBadLooseMinus" ] = &isBadLooseMinus;
// -- slimmed --       fHandles[ "isBadLoose" ] = &isBadLoose;
// -- slimmed --       fHandles[ "isBadMedium" ] = &isBadMedium;
// -- slimmed --       fHandles[ "isBadTight" ] = &isBadTight;
      fHandles[ "emfrac" ] = &emfrac;
      fHandles[ "Offset" ] = &Offset;
      fHandles[ "EMJES" ] = &EMJES;
      fHandles[ "EMJES_EtaCorr" ] = &EMJES_EtaCorr;
      fHandles[ "EMJESnooffset" ] = &EMJESnooffset;
      fHandles[ "GCWJES" ] = &GCWJES;
      fHandles[ "GCWJES_EtaCorr" ] = &GCWJES_EtaCorr;
      fHandles[ "CB" ] = &CB;
      fHandles[ "LCJES" ] = &LCJES;
      fHandles[ "emscale_E" ] = &emscale_E;
      fHandles[ "emscale_pt" ] = &emscale_pt;
      fHandles[ "emscale_m" ] = &emscale_m;
      fHandles[ "emscale_eta" ] = &emscale_eta;
      fHandles[ "emscale_phi" ] = &emscale_phi;
      fHandles[ "jvtx_x" ] = &jvtx_x;
      fHandles[ "jvtx_y" ] = &jvtx_y;
      fHandles[ "jvtx_z" ] = &jvtx_z;
      fHandles[ "jvtxf" ] = &jvtxf;
      fHandles[ "jvtxfFull" ] = &jvtxfFull;
      fHandles[ "GSCFactorF" ] = &GSCFactorF;
      fHandles[ "WidthFraction" ] = &WidthFraction;
      fHandles[ "e_PreSamplerB" ] = &e_PreSamplerB;
// -- slimmed --       fHandles[ "e_EMB1" ] = &e_EMB1;
// -- slimmed --       fHandles[ "e_EMB2" ] = &e_EMB2;
// -- slimmed --       fHandles[ "e_EMB3" ] = &e_EMB3;
// -- slimmed --       fHandles[ "e_PreSamplerE" ] = &e_PreSamplerE;
// -- slimmed --       fHandles[ "e_EME1" ] = &e_EME1;
// -- slimmed --       fHandles[ "e_EME2" ] = &e_EME2;
// -- slimmed --       fHandles[ "e_EME3" ] = &e_EME3;
// -- slimmed --       fHandles[ "e_HEC0" ] = &e_HEC0;
// -- slimmed --       fHandles[ "e_HEC1" ] = &e_HEC1;
// -- slimmed --       fHandles[ "e_HEC2" ] = &e_HEC2;
// -- slimmed --       fHandles[ "e_HEC3" ] = &e_HEC3;
// -- slimmed --       fHandles[ "e_TileBar0" ] = &e_TileBar0;
// -- slimmed --       fHandles[ "e_TileBar1" ] = &e_TileBar1;
// -- slimmed --       fHandles[ "e_TileBar2" ] = &e_TileBar2;
// -- slimmed --       fHandles[ "e_TileGap1" ] = &e_TileGap1;
// -- slimmed --       fHandles[ "e_TileGap2" ] = &e_TileGap2;
// -- slimmed --       fHandles[ "e_TileGap3" ] = &e_TileGap3;
// -- slimmed --       fHandles[ "e_TileExt0" ] = &e_TileExt0;
// -- slimmed --       fHandles[ "e_TileExt1" ] = &e_TileExt1;
// -- slimmed --       fHandles[ "e_TileExt2" ] = &e_TileExt2;
// -- slimmed --       fHandles[ "e_FCAL0" ] = &e_FCAL0;
// -- slimmed --       fHandles[ "e_FCAL1" ] = &e_FCAL1;
// -- slimmed --       fHandles[ "e_FCAL2" ] = &e_FCAL2;
// -- slimmed --       fHandles[ "Nconst" ] = &Nconst;
// -- slimmed --       fHandles[ "ptconst_default" ] = &ptconst_default;
// -- slimmed --       fHandles[ "econst_default" ] = &econst_default;
// -- slimmed --       fHandles[ "etaconst_default" ] = &etaconst_default;
// -- slimmed --       fHandles[ "phiconst_default" ] = &phiconst_default;
// -- slimmed --       fHandles[ "weightconst_default" ] = &weightconst_default;
      fHandles[ "constscale_E" ] = &constscale_E;
      fHandles[ "constscale_pt" ] = &constscale_pt;
      fHandles[ "constscale_m" ] = &constscale_m;
      fHandles[ "constscale_eta" ] = &constscale_eta;
      fHandles[ "constscale_phi" ] = &constscale_phi;
      fHandles[ "flavor_weight_Comb" ] = &flavor_weight_Comb;
      fHandles[ "flavor_weight_IP2D" ] = &flavor_weight_IP2D;
      fHandles[ "flavor_weight_IP3D" ] = &flavor_weight_IP3D;
      fHandles[ "flavor_weight_SV0" ] = &flavor_weight_SV0;
      fHandles[ "flavor_weight_SV1" ] = &flavor_weight_SV1;
      fHandles[ "flavor_weight_SV2" ] = &flavor_weight_SV2;
      fHandles[ "flavor_weight_SoftMuonTagChi2" ] = &flavor_weight_SoftMuonTagChi2;
      fHandles[ "flavor_weight_SecondSoftMuonTagChi2" ] = &flavor_weight_SecondSoftMuonTagChi2;
      fHandles[ "flavor_weight_JetFitterTagNN" ] = &flavor_weight_JetFitterTagNN;
      fHandles[ "flavor_weight_JetFitterCOMBNN" ] = &flavor_weight_JetFitterCOMBNN;
      fHandles[ "flavor_weight_MV1" ] = &flavor_weight_MV1;
      fHandles[ "flavor_weight_MV2" ] = &flavor_weight_MV2;
      fHandles[ "flavor_weight_GbbNN" ] = &flavor_weight_GbbNN;
if (!is_data) {
      fHandles[ "flavor_truth_label" ] = &flavor_truth_label;
      fHandles[ "flavor_truth_dRminToB" ] = &flavor_truth_dRminToB;
      fHandles[ "flavor_truth_dRminToC" ] = &flavor_truth_dRminToC;
      fHandles[ "flavor_truth_dRminToT" ] = &flavor_truth_dRminToT;
      fHandles[ "flavor_truth_BHadronpdg" ] = &flavor_truth_BHadronpdg;
      fHandles[ "flavor_truth_vx_x" ] = &flavor_truth_vx_x;
      fHandles[ "flavor_truth_vx_y" ] = &flavor_truth_vx_y;
      fHandles[ "flavor_truth_vx_z" ] = &flavor_truth_vx_z;
} // end !is_data
// -- slimmed --       fHandles[ "flavor_component_ip2d_pu" ] = &flavor_component_ip2d_pu;
// -- slimmed --       fHandles[ "flavor_component_ip2d_pb" ] = &flavor_component_ip2d_pb;
// -- slimmed --       fHandles[ "flavor_component_ip2d_isValid" ] = &flavor_component_ip2d_isValid;
// -- slimmed --       fHandles[ "flavor_component_ip2d_ntrk" ] = &flavor_component_ip2d_ntrk;
// -- slimmed --       fHandles[ "flavor_component_ip3d_pu" ] = &flavor_component_ip3d_pu;
// -- slimmed --       fHandles[ "flavor_component_ip3d_pb" ] = &flavor_component_ip3d_pb;
// -- slimmed --       fHandles[ "flavor_component_ip3d_isValid" ] = &flavor_component_ip3d_isValid;
// -- slimmed --       fHandles[ "flavor_component_ip3d_ntrk" ] = &flavor_component_ip3d_ntrk;
// -- slimmed --       fHandles[ "flavor_component_sv1_pu" ] = &flavor_component_sv1_pu;
// -- slimmed --       fHandles[ "flavor_component_sv1_pb" ] = &flavor_component_sv1_pb;
// -- slimmed --       fHandles[ "flavor_component_sv1_isValid" ] = &flavor_component_sv1_isValid;
// -- slimmed --       fHandles[ "flavor_component_sv2_pu" ] = &flavor_component_sv2_pu;
// -- slimmed --       fHandles[ "flavor_component_sv2_pb" ] = &flavor_component_sv2_pb;
// -- slimmed --       fHandles[ "flavor_component_sv2_isValid" ] = &flavor_component_sv2_isValid;
// -- slimmed --       fHandles[ "flavor_component_jfit_pu" ] = &flavor_component_jfit_pu;
// -- slimmed --       fHandles[ "flavor_component_jfit_pb" ] = &flavor_component_jfit_pb;
// -- slimmed --       fHandles[ "flavor_component_jfit_pc" ] = &flavor_component_jfit_pc;
// -- slimmed --       fHandles[ "flavor_component_jfit_isValid" ] = &flavor_component_jfit_isValid;
// -- slimmed --       fHandles[ "flavor_component_jfitcomb_pu" ] = &flavor_component_jfitcomb_pu;
// -- slimmed --       fHandles[ "flavor_component_jfitcomb_pb" ] = &flavor_component_jfitcomb_pb;
// -- slimmed --       fHandles[ "flavor_component_jfitcomb_pc" ] = &flavor_component_jfitcomb_pc;
// -- slimmed --       fHandles[ "flavor_component_jfitcomb_isValid" ] = &flavor_component_jfitcomb_isValid;
// -- slimmed --       fHandles[ "flavor_component_jfit_nvtx" ] = &flavor_component_jfit_nvtx;
// -- slimmed --       fHandles[ "flavor_component_jfit_nvtx1t" ] = &flavor_component_jfit_nvtx1t;
// -- slimmed --       fHandles[ "flavor_component_jfit_ntrkAtVx" ] = &flavor_component_jfit_ntrkAtVx;
// -- slimmed --       fHandles[ "flavor_component_jfit_efrc" ] = &flavor_component_jfit_efrc;
// -- slimmed --       fHandles[ "flavor_component_jfit_mass" ] = &flavor_component_jfit_mass;
// -- slimmed --       fHandles[ "flavor_component_jfit_sig3d" ] = &flavor_component_jfit_sig3d;
// -- slimmed --       fHandles[ "flavor_component_jfit_deltaPhi" ] = &flavor_component_jfit_deltaPhi;
// -- slimmed --       fHandles[ "flavor_component_jfit_deltaEta" ] = &flavor_component_jfit_deltaEta;
// -- slimmed --       fHandles[ "flavor_component_svp_isValid" ] = &flavor_component_svp_isValid;
// -- slimmed --       fHandles[ "flavor_component_svp_ntrkv" ] = &flavor_component_svp_ntrkv;
// -- slimmed --       fHandles[ "flavor_component_svp_ntrkj" ] = &flavor_component_svp_ntrkj;
// -- slimmed --       fHandles[ "flavor_component_svp_n2t" ] = &flavor_component_svp_n2t;
// -- slimmed --       fHandles[ "flavor_component_svp_mass" ] = &flavor_component_svp_mass;
// -- slimmed --       fHandles[ "flavor_component_svp_efrc" ] = &flavor_component_svp_efrc;
// -- slimmed --       fHandles[ "flavor_component_svp_x" ] = &flavor_component_svp_x;
// -- slimmed --       fHandles[ "flavor_component_svp_y" ] = &flavor_component_svp_y;
// -- slimmed --       fHandles[ "flavor_component_svp_z" ] = &flavor_component_svp_z;
// -- slimmed --       fHandles[ "flavor_component_svp_err_x" ] = &flavor_component_svp_err_x;
// -- slimmed --       fHandles[ "flavor_component_svp_err_y" ] = &flavor_component_svp_err_y;
// -- slimmed --       fHandles[ "flavor_component_svp_err_z" ] = &flavor_component_svp_err_z;
// -- slimmed --       fHandles[ "flavor_component_svp_cov_xy" ] = &flavor_component_svp_cov_xy;
// -- slimmed --       fHandles[ "flavor_component_svp_cov_xz" ] = &flavor_component_svp_cov_xz;
// -- slimmed --       fHandles[ "flavor_component_svp_cov_yz" ] = &flavor_component_svp_cov_yz;
// -- slimmed --       fHandles[ "flavor_component_svp_chi2" ] = &flavor_component_svp_chi2;
// -- slimmed --       fHandles[ "flavor_component_svp_ndof" ] = &flavor_component_svp_ndof;
// -- slimmed --       fHandles[ "flavor_component_svp_ntrk" ] = &flavor_component_svp_ntrk;
// -- slimmed --       fHandles[ "flavor_component_sv0p_isValid" ] = &flavor_component_sv0p_isValid;
// -- slimmed --       fHandles[ "flavor_component_sv0p_ntrkv" ] = &flavor_component_sv0p_ntrkv;
// -- slimmed --       fHandles[ "flavor_component_sv0p_ntrkj" ] = &flavor_component_sv0p_ntrkj;
// -- slimmed --       fHandles[ "flavor_component_sv0p_n2t" ] = &flavor_component_sv0p_n2t;
// -- slimmed --       fHandles[ "flavor_component_sv0p_mass" ] = &flavor_component_sv0p_mass;
// -- slimmed --       fHandles[ "flavor_component_sv0p_efrc" ] = &flavor_component_sv0p_efrc;
// -- slimmed --       fHandles[ "flavor_component_sv0p_x" ] = &flavor_component_sv0p_x;
// -- slimmed --       fHandles[ "flavor_component_sv0p_y" ] = &flavor_component_sv0p_y;
// -- slimmed --       fHandles[ "flavor_component_sv0p_z" ] = &flavor_component_sv0p_z;
// -- slimmed --       fHandles[ "flavor_component_sv0p_err_x" ] = &flavor_component_sv0p_err_x;
// -- slimmed --       fHandles[ "flavor_component_sv0p_err_y" ] = &flavor_component_sv0p_err_y;
// -- slimmed --       fHandles[ "flavor_component_sv0p_err_z" ] = &flavor_component_sv0p_err_z;
// -- slimmed --       fHandles[ "flavor_component_sv0p_cov_xy" ] = &flavor_component_sv0p_cov_xy;
// -- slimmed --       fHandles[ "flavor_component_sv0p_cov_xz" ] = &flavor_component_sv0p_cov_xz;
// -- slimmed --       fHandles[ "flavor_component_sv0p_cov_yz" ] = &flavor_component_sv0p_cov_yz;
// -- slimmed --       fHandles[ "flavor_component_sv0p_chi2" ] = &flavor_component_sv0p_chi2;
// -- slimmed --       fHandles[ "flavor_component_sv0p_ndof" ] = &flavor_component_sv0p_ndof;
// -- slimmed --       fHandles[ "flavor_component_sv0p_ntrk" ] = &flavor_component_sv0p_ntrk;
// -- slimmed --       fHandles[ "flavor_assoctrk_n" ] = &flavor_assoctrk_n;
// -- slimmed --       fHandles[ "flavor_assoctrk_index" ] = &flavor_assoctrk_index;
// -- slimmed --       fHandles[ "el_dr" ] = &el_dr;
// -- slimmed --       fHandles[ "el_matched" ] = &el_matched;
// -- slimmed --       fHandles[ "mu_dr" ] = &mu_dr;
// -- slimmed --       fHandles[ "mu_matched" ] = &mu_matched;
// -- slimmed --       fHandles[ "L1_dr" ] = &L1_dr;
// -- slimmed --       fHandles[ "L1_matched" ] = &L1_matched;
// -- slimmed --       fHandles[ "L2_dr" ] = &L2_dr;
// -- slimmed --       fHandles[ "L2_matched" ] = &L2_matched;
// -- slimmed --       fHandles[ "EF_dr" ] = &EF_dr;
// -- slimmed --       fHandles[ "EF_matched" ] = &EF_matched;
// -- slimmed --       fHandles[ "bbDecision" ] = &bbDecision;
// -- slimmed --       fHandles[ "SmearingFactor" ] = &SmearingFactor;
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   JetD3PDObject::JetD3PDObject( const char* prefix , bool is_data )
      : TObject(),
        MET_Egamma10NoTau_wpx( this, ::TString( prefix ) + "MET_Egamma10NoTau_wpx", 0 ),
        MET_Egamma10NoTau_wpy( this, ::TString( prefix ) + "MET_Egamma10NoTau_wpy", 0 ),
        MET_Egamma10NoTau_wet( this, ::TString( prefix ) + "MET_Egamma10NoTau_wet", 0 ),
        MET_Egamma10NoTau_statusWord( this, ::TString( prefix ) + "MET_Egamma10NoTau_statusWord", 0 ),
        MET_Egamma10NoTau_STVF_wpx( this, ::TString( prefix ) + "MET_Egamma10NoTau_STVF_wpx", 0 ),
        MET_Egamma10NoTau_STVF_wpy( this, ::TString( prefix ) + "MET_Egamma10NoTau_STVF_wpy", 0 ),
        MET_Egamma10NoTau_STVF_wet( this, ::TString( prefix ) + "MET_Egamma10NoTau_STVF_wet", 0 ),
        MET_Egamma10NoTau_STVF_statusWord( this, ::TString( prefix ) + "MET_Egamma10NoTau_STVF_statusWord", 0 ),
// -- slimmed --         MET_LooseEgamma10NoTau_wpx( this, ::TString( prefix ) + "MET_LooseEgamma10NoTau_wpx", 0 ),
// -- slimmed --         MET_LooseEgamma10NoTau_wpy( this, ::TString( prefix ) + "MET_LooseEgamma10NoTau_wpy", 0 ),
// -- slimmed --         MET_LooseEgamma10NoTau_wet( this, ::TString( prefix ) + "MET_LooseEgamma10NoTau_wet", 0 ),
// -- slimmed --         MET_LooseEgamma10NoTau_statusWord( this, ::TString( prefix ) + "MET_LooseEgamma10NoTau_statusWord", 0 ),
// -- slimmed --         MET_wpx( this, ::TString( prefix ) + "MET_wpx", 0 ),
// -- slimmed --         MET_wpy( this, ::TString( prefix ) + "MET_wpy", 0 ),
// -- slimmed --         MET_wet( this, ::TString( prefix ) + "MET_wet", 0 ),
// -- slimmed --         MET_statusWord( this, ::TString( prefix ) + "MET_statusWord", 0 ),
// -- slimmed --         MET_STVF_wpx( this, ::TString( prefix ) + "MET_STVF_wpx", 0 ),
// -- slimmed --         MET_STVF_wpy( this, ::TString( prefix ) + "MET_STVF_wpy", 0 ),
// -- slimmed --         MET_STVF_wet( this, ::TString( prefix ) + "MET_STVF_wet", 0 ),
// -- slimmed --         MET_STVF_statusWord( this, ::TString( prefix ) + "MET_STVF_statusWord", 0 ),
        n( this, ::TString( prefix ) + "n", 0 ),
        E( this, ::TString( prefix ) + "E", 0 ),
        pt( this, ::TString( prefix ) + "pt", 0 ),
        m( this, ::TString( prefix ) + "m", 0 ),
        eta( this, ::TString( prefix ) + "eta", 0 ),
        phi( this, ::TString( prefix ) + "phi", 0 ),
        EtaOrigin( this, ::TString( prefix ) + "EtaOrigin", 0 ),
        PhiOrigin( this, ::TString( prefix ) + "PhiOrigin", 0 ),
        MOrigin( this, ::TString( prefix ) + "MOrigin", 0 ),
        EtaOriginEM( this, ::TString( prefix ) + "EtaOriginEM", 0 ),
        PhiOriginEM( this, ::TString( prefix ) + "PhiOriginEM", 0 ),
        MOriginEM( this, ::TString( prefix ) + "MOriginEM", 0 ),
// -- slimmed --         WIDTH( this, ::TString( prefix ) + "WIDTH", 0 ),
// -- slimmed --         n90( this, ::TString( prefix ) + "n90", 0 ),
// -- slimmed --         Timing( this, ::TString( prefix ) + "Timing", 0 ),
        LArQuality( this, ::TString( prefix ) + "LArQuality", 0 ),
        nTrk( this, ::TString( prefix ) + "nTrk", 0 ),
        sumPtTrk( this, ::TString( prefix ) + "sumPtTrk", 0 ),
        OriginIndex( this, ::TString( prefix ) + "OriginIndex", 0 ),
        HECQuality( this, ::TString( prefix ) + "HECQuality", 0 ),
        NegativeE( this, ::TString( prefix ) + "NegativeE", 0 ),
        AverageLArQF( this, ::TString( prefix ) + "AverageLArQF", 0 ),
// -- slimmed --         YFlip12( this, ::TString( prefix ) + "YFlip12", 0 ),
// -- slimmed --         YFlip23( this, ::TString( prefix ) + "YFlip23", 0 ),
// -- slimmed --         BCH_CORR_CELL( this, ::TString( prefix ) + "BCH_CORR_CELL", 0 ),
// -- slimmed --         BCH_CORR_DOTX( this, ::TString( prefix ) + "BCH_CORR_DOTX", 0 ),
// -- slimmed --         BCH_CORR_JET( this, ::TString( prefix ) + "BCH_CORR_JET", 0 ),
// -- slimmed --         BCH_CORR_JET_FORCELL( this, ::TString( prefix ) + "BCH_CORR_JET_FORCELL", 0 ),
        ENG_BAD_CELLS( this, ::TString( prefix ) + "ENG_BAD_CELLS", 0 ),
        N_BAD_CELLS( this, ::TString( prefix ) + "N_BAD_CELLS", 0 ),
        N_BAD_CELLS_CORR( this, ::TString( prefix ) + "N_BAD_CELLS_CORR", 0 ),
        BAD_CELLS_CORR_E( this, ::TString( prefix ) + "BAD_CELLS_CORR_E", 0 ),
// -- slimmed --         NumTowers( this, ::TString( prefix ) + "NumTowers", 0 ),
// -- slimmed --         ootFracCells5( this, ::TString( prefix ) + "ootFracCells5", 0 ),
// -- slimmed --         ootFracCells10( this, ::TString( prefix ) + "ootFracCells10", 0 ),
// -- slimmed --         ootFracClusters5( this, ::TString( prefix ) + "ootFracClusters5", 0 ),
// -- slimmed --         ootFracClusters10( this, ::TString( prefix ) + "ootFracClusters10", 0 ),
        SamplingMax( this, ::TString( prefix ) + "SamplingMax", 0 ),
        fracSamplingMax( this, ::TString( prefix ) + "fracSamplingMax", 0 ),
        hecf( this, ::TString( prefix ) + "hecf", 0 ),
// -- slimmed --         tgap3f( this, ::TString( prefix ) + "tgap3f", 0 ),
// -- slimmed --         isUgly( this, ::TString( prefix ) + "isUgly", 0 ),
// -- slimmed --         isBadLooseMinus( this, ::TString( prefix ) + "isBadLooseMinus", 0 ),
// -- slimmed --         isBadLoose( this, ::TString( prefix ) + "isBadLoose", 0 ),
// -- slimmed --         isBadMedium( this, ::TString( prefix ) + "isBadMedium", 0 ),
// -- slimmed --         isBadTight( this, ::TString( prefix ) + "isBadTight", 0 ),
        emfrac( this, ::TString( prefix ) + "emfrac", 0 ),
        Offset( this, ::TString( prefix ) + "Offset", 0 ),
        EMJES( this, ::TString( prefix ) + "EMJES", 0 ),
        EMJES_EtaCorr( this, ::TString( prefix ) + "EMJES_EtaCorr", 0 ),
        EMJESnooffset( this, ::TString( prefix ) + "EMJESnooffset", 0 ),
        GCWJES( this, ::TString( prefix ) + "GCWJES", 0 ),
        GCWJES_EtaCorr( this, ::TString( prefix ) + "GCWJES_EtaCorr", 0 ),
        CB( this, ::TString( prefix ) + "CB", 0 ),
        LCJES( this, ::TString( prefix ) + "LCJES", 0 ),
        emscale_E( this, ::TString( prefix ) + "emscale_E", 0 ),
        emscale_pt( this, ::TString( prefix ) + "emscale_pt", 0 ),
        emscale_m( this, ::TString( prefix ) + "emscale_m", 0 ),
        emscale_eta( this, ::TString( prefix ) + "emscale_eta", 0 ),
        emscale_phi( this, ::TString( prefix ) + "emscale_phi", 0 ),
        jvtx_x( this, ::TString( prefix ) + "jvtx_x", 0 ),
        jvtx_y( this, ::TString( prefix ) + "jvtx_y", 0 ),
        jvtx_z( this, ::TString( prefix ) + "jvtx_z", 0 ),
        jvtxf( this, ::TString( prefix ) + "jvtxf", 0 ),
        jvtxfFull( this, ::TString( prefix ) + "jvtxfFull", 0 ),
        GSCFactorF( this, ::TString( prefix ) + "GSCFactorF", 0 ),
        WidthFraction( this, ::TString( prefix ) + "WidthFraction", 0 ),
        e_PreSamplerB( this, ::TString( prefix ) + "e_PreSamplerB", 0 ),
// -- slimmed --         e_EMB1( this, ::TString( prefix ) + "e_EMB1", 0 ),
// -- slimmed --         e_EMB2( this, ::TString( prefix ) + "e_EMB2", 0 ),
// -- slimmed --         e_EMB3( this, ::TString( prefix ) + "e_EMB3", 0 ),
// -- slimmed --         e_PreSamplerE( this, ::TString( prefix ) + "e_PreSamplerE", 0 ),
// -- slimmed --         e_EME1( this, ::TString( prefix ) + "e_EME1", 0 ),
// -- slimmed --         e_EME2( this, ::TString( prefix ) + "e_EME2", 0 ),
// -- slimmed --         e_EME3( this, ::TString( prefix ) + "e_EME3", 0 ),
// -- slimmed --         e_HEC0( this, ::TString( prefix ) + "e_HEC0", 0 ),
// -- slimmed --         e_HEC1( this, ::TString( prefix ) + "e_HEC1", 0 ),
// -- slimmed --         e_HEC2( this, ::TString( prefix ) + "e_HEC2", 0 ),
// -- slimmed --         e_HEC3( this, ::TString( prefix ) + "e_HEC3", 0 ),
// -- slimmed --         e_TileBar0( this, ::TString( prefix ) + "e_TileBar0", 0 ),
// -- slimmed --         e_TileBar1( this, ::TString( prefix ) + "e_TileBar1", 0 ),
// -- slimmed --         e_TileBar2( this, ::TString( prefix ) + "e_TileBar2", 0 ),
// -- slimmed --         e_TileGap1( this, ::TString( prefix ) + "e_TileGap1", 0 ),
// -- slimmed --         e_TileGap2( this, ::TString( prefix ) + "e_TileGap2", 0 ),
// -- slimmed --         e_TileGap3( this, ::TString( prefix ) + "e_TileGap3", 0 ),
// -- slimmed --         e_TileExt0( this, ::TString( prefix ) + "e_TileExt0", 0 ),
// -- slimmed --         e_TileExt1( this, ::TString( prefix ) + "e_TileExt1", 0 ),
// -- slimmed --         e_TileExt2( this, ::TString( prefix ) + "e_TileExt2", 0 ),
// -- slimmed --         e_FCAL0( this, ::TString( prefix ) + "e_FCAL0", 0 ),
// -- slimmed --         e_FCAL1( this, ::TString( prefix ) + "e_FCAL1", 0 ),
// -- slimmed --         e_FCAL2( this, ::TString( prefix ) + "e_FCAL2", 0 ),
// -- slimmed --         Nconst( this, ::TString( prefix ) + "Nconst", 0 ),
// -- slimmed --         ptconst_default( this, ::TString( prefix ) + "ptconst_default", 0 ),
// -- slimmed --         econst_default( this, ::TString( prefix ) + "econst_default", 0 ),
// -- slimmed --         etaconst_default( this, ::TString( prefix ) + "etaconst_default", 0 ),
// -- slimmed --         phiconst_default( this, ::TString( prefix ) + "phiconst_default", 0 ),
// -- slimmed --         weightconst_default( this, ::TString( prefix ) + "weightconst_default", 0 ),
        constscale_E( this, ::TString( prefix ) + "constscale_E", 0 ),
        constscale_pt( this, ::TString( prefix ) + "constscale_pt", 0 ),
        constscale_m( this, ::TString( prefix ) + "constscale_m", 0 ),
        constscale_eta( this, ::TString( prefix ) + "constscale_eta", 0 ),
        constscale_phi( this, ::TString( prefix ) + "constscale_phi", 0 ),
        flavor_weight_Comb( this, ::TString( prefix ) + "flavor_weight_Comb", 0 ),
        flavor_weight_IP2D( this, ::TString( prefix ) + "flavor_weight_IP2D", 0 ),
        flavor_weight_IP3D( this, ::TString( prefix ) + "flavor_weight_IP3D", 0 ),
        flavor_weight_SV0( this, ::TString( prefix ) + "flavor_weight_SV0", 0 ),
        flavor_weight_SV1( this, ::TString( prefix ) + "flavor_weight_SV1", 0 ),
        flavor_weight_SV2( this, ::TString( prefix ) + "flavor_weight_SV2", 0 ),
        flavor_weight_SoftMuonTagChi2( this, ::TString( prefix ) + "flavor_weight_SoftMuonTagChi2", 0 ),
        flavor_weight_SecondSoftMuonTagChi2( this, ::TString( prefix ) + "flavor_weight_SecondSoftMuonTagChi2", 0 ),
        flavor_weight_JetFitterTagNN( this, ::TString( prefix ) + "flavor_weight_JetFitterTagNN", 0 ),
        flavor_weight_JetFitterCOMBNN( this, ::TString( prefix ) + "flavor_weight_JetFitterCOMBNN", 0 ),
        flavor_weight_MV1( this, ::TString( prefix ) + "flavor_weight_MV1", 0 ),
        flavor_weight_MV2( this, ::TString( prefix ) + "flavor_weight_MV2", 0 ),
        flavor_weight_GbbNN( this, ::TString( prefix ) + "flavor_weight_GbbNN", 0 ),
// MC only
        flavor_truth_label( this, ::TString( prefix ) + "flavor_truth_label", 0 ),
        flavor_truth_dRminToB( this, ::TString( prefix ) + "flavor_truth_dRminToB", 0 ),
        flavor_truth_dRminToC( this, ::TString( prefix ) + "flavor_truth_dRminToC", 0 ),
        flavor_truth_dRminToT( this, ::TString( prefix ) + "flavor_truth_dRminToT", 0 ),
        flavor_truth_BHadronpdg( this, ::TString( prefix ) + "flavor_truth_BHadronpdg", 0 ),
        flavor_truth_vx_x( this, ::TString( prefix ) + "flavor_truth_vx_x", 0 ),
        flavor_truth_vx_y( this, ::TString( prefix ) + "flavor_truth_vx_y", 0 ),
        flavor_truth_vx_z( this, ::TString( prefix ) + "flavor_truth_vx_z", 0 ),
// end MC only
// -- slimmed --         flavor_component_ip2d_pu( this, ::TString( prefix ) + "flavor_component_ip2d_pu", 0 ),
// -- slimmed --         flavor_component_ip2d_pb( this, ::TString( prefix ) + "flavor_component_ip2d_pb", 0 ),
// -- slimmed --         flavor_component_ip2d_isValid( this, ::TString( prefix ) + "flavor_component_ip2d_isValid", 0 ),
// -- slimmed --         flavor_component_ip2d_ntrk( this, ::TString( prefix ) + "flavor_component_ip2d_ntrk", 0 ),
// -- slimmed --         flavor_component_ip3d_pu( this, ::TString( prefix ) + "flavor_component_ip3d_pu", 0 ),
// -- slimmed --         flavor_component_ip3d_pb( this, ::TString( prefix ) + "flavor_component_ip3d_pb", 0 ),
// -- slimmed --         flavor_component_ip3d_isValid( this, ::TString( prefix ) + "flavor_component_ip3d_isValid", 0 ),
// -- slimmed --         flavor_component_ip3d_ntrk( this, ::TString( prefix ) + "flavor_component_ip3d_ntrk", 0 ),
// -- slimmed --         flavor_component_sv1_pu( this, ::TString( prefix ) + "flavor_component_sv1_pu", 0 ),
// -- slimmed --         flavor_component_sv1_pb( this, ::TString( prefix ) + "flavor_component_sv1_pb", 0 ),
// -- slimmed --         flavor_component_sv1_isValid( this, ::TString( prefix ) + "flavor_component_sv1_isValid", 0 ),
// -- slimmed --         flavor_component_sv2_pu( this, ::TString( prefix ) + "flavor_component_sv2_pu", 0 ),
// -- slimmed --         flavor_component_sv2_pb( this, ::TString( prefix ) + "flavor_component_sv2_pb", 0 ),
// -- slimmed --         flavor_component_sv2_isValid( this, ::TString( prefix ) + "flavor_component_sv2_isValid", 0 ),
// -- slimmed --         flavor_component_jfit_pu( this, ::TString( prefix ) + "flavor_component_jfit_pu", 0 ),
// -- slimmed --         flavor_component_jfit_pb( this, ::TString( prefix ) + "flavor_component_jfit_pb", 0 ),
// -- slimmed --         flavor_component_jfit_pc( this, ::TString( prefix ) + "flavor_component_jfit_pc", 0 ),
// -- slimmed --         flavor_component_jfit_isValid( this, ::TString( prefix ) + "flavor_component_jfit_isValid", 0 ),
// -- slimmed --         flavor_component_jfitcomb_pu( this, ::TString( prefix ) + "flavor_component_jfitcomb_pu", 0 ),
// -- slimmed --         flavor_component_jfitcomb_pb( this, ::TString( prefix ) + "flavor_component_jfitcomb_pb", 0 ),
// -- slimmed --         flavor_component_jfitcomb_pc( this, ::TString( prefix ) + "flavor_component_jfitcomb_pc", 0 ),
// -- slimmed --         flavor_component_jfitcomb_isValid( this, ::TString( prefix ) + "flavor_component_jfitcomb_isValid", 0 ),
// -- slimmed --         flavor_component_jfit_nvtx( this, ::TString( prefix ) + "flavor_component_jfit_nvtx", 0 ),
// -- slimmed --         flavor_component_jfit_nvtx1t( this, ::TString( prefix ) + "flavor_component_jfit_nvtx1t", 0 ),
// -- slimmed --         flavor_component_jfit_ntrkAtVx( this, ::TString( prefix ) + "flavor_component_jfit_ntrkAtVx", 0 ),
// -- slimmed --         flavor_component_jfit_efrc( this, ::TString( prefix ) + "flavor_component_jfit_efrc", 0 ),
// -- slimmed --         flavor_component_jfit_mass( this, ::TString( prefix ) + "flavor_component_jfit_mass", 0 ),
// -- slimmed --         flavor_component_jfit_sig3d( this, ::TString( prefix ) + "flavor_component_jfit_sig3d", 0 ),
// -- slimmed --         flavor_component_jfit_deltaPhi( this, ::TString( prefix ) + "flavor_component_jfit_deltaPhi", 0 ),
// -- slimmed --         flavor_component_jfit_deltaEta( this, ::TString( prefix ) + "flavor_component_jfit_deltaEta", 0 ),
// -- slimmed --         flavor_component_svp_isValid( this, ::TString( prefix ) + "flavor_component_svp_isValid", 0 ),
// -- slimmed --         flavor_component_svp_ntrkv( this, ::TString( prefix ) + "flavor_component_svp_ntrkv", 0 ),
// -- slimmed --         flavor_component_svp_ntrkj( this, ::TString( prefix ) + "flavor_component_svp_ntrkj", 0 ),
// -- slimmed --         flavor_component_svp_n2t( this, ::TString( prefix ) + "flavor_component_svp_n2t", 0 ),
// -- slimmed --         flavor_component_svp_mass( this, ::TString( prefix ) + "flavor_component_svp_mass", 0 ),
// -- slimmed --         flavor_component_svp_efrc( this, ::TString( prefix ) + "flavor_component_svp_efrc", 0 ),
// -- slimmed --         flavor_component_svp_x( this, ::TString( prefix ) + "flavor_component_svp_x", 0 ),
// -- slimmed --         flavor_component_svp_y( this, ::TString( prefix ) + "flavor_component_svp_y", 0 ),
// -- slimmed --         flavor_component_svp_z( this, ::TString( prefix ) + "flavor_component_svp_z", 0 ),
// -- slimmed --         flavor_component_svp_err_x( this, ::TString( prefix ) + "flavor_component_svp_err_x", 0 ),
// -- slimmed --         flavor_component_svp_err_y( this, ::TString( prefix ) + "flavor_component_svp_err_y", 0 ),
// -- slimmed --         flavor_component_svp_err_z( this, ::TString( prefix ) + "flavor_component_svp_err_z", 0 ),
// -- slimmed --         flavor_component_svp_cov_xy( this, ::TString( prefix ) + "flavor_component_svp_cov_xy", 0 ),
// -- slimmed --         flavor_component_svp_cov_xz( this, ::TString( prefix ) + "flavor_component_svp_cov_xz", 0 ),
// -- slimmed --         flavor_component_svp_cov_yz( this, ::TString( prefix ) + "flavor_component_svp_cov_yz", 0 ),
// -- slimmed --         flavor_component_svp_chi2( this, ::TString( prefix ) + "flavor_component_svp_chi2", 0 ),
// -- slimmed --         flavor_component_svp_ndof( this, ::TString( prefix ) + "flavor_component_svp_ndof", 0 ),
// -- slimmed --         flavor_component_svp_ntrk( this, ::TString( prefix ) + "flavor_component_svp_ntrk", 0 ),
// -- slimmed --         flavor_component_sv0p_isValid( this, ::TString( prefix ) + "flavor_component_sv0p_isValid", 0 ),
// -- slimmed --         flavor_component_sv0p_ntrkv( this, ::TString( prefix ) + "flavor_component_sv0p_ntrkv", 0 ),
// -- slimmed --         flavor_component_sv0p_ntrkj( this, ::TString( prefix ) + "flavor_component_sv0p_ntrkj", 0 ),
// -- slimmed --         flavor_component_sv0p_n2t( this, ::TString( prefix ) + "flavor_component_sv0p_n2t", 0 ),
// -- slimmed --         flavor_component_sv0p_mass( this, ::TString( prefix ) + "flavor_component_sv0p_mass", 0 ),
// -- slimmed --         flavor_component_sv0p_efrc( this, ::TString( prefix ) + "flavor_component_sv0p_efrc", 0 ),
// -- slimmed --         flavor_component_sv0p_x( this, ::TString( prefix ) + "flavor_component_sv0p_x", 0 ),
// -- slimmed --         flavor_component_sv0p_y( this, ::TString( prefix ) + "flavor_component_sv0p_y", 0 ),
// -- slimmed --         flavor_component_sv0p_z( this, ::TString( prefix ) + "flavor_component_sv0p_z", 0 ),
// -- slimmed --         flavor_component_sv0p_err_x( this, ::TString( prefix ) + "flavor_component_sv0p_err_x", 0 ),
// -- slimmed --         flavor_component_sv0p_err_y( this, ::TString( prefix ) + "flavor_component_sv0p_err_y", 0 ),
// -- slimmed --         flavor_component_sv0p_err_z( this, ::TString( prefix ) + "flavor_component_sv0p_err_z", 0 ),
// -- slimmed --         flavor_component_sv0p_cov_xy( this, ::TString( prefix ) + "flavor_component_sv0p_cov_xy", 0 ),
// -- slimmed --         flavor_component_sv0p_cov_xz( this, ::TString( prefix ) + "flavor_component_sv0p_cov_xz", 0 ),
// -- slimmed --         flavor_component_sv0p_cov_yz( this, ::TString( prefix ) + "flavor_component_sv0p_cov_yz", 0 ),
// -- slimmed --         flavor_component_sv0p_chi2( this, ::TString( prefix ) + "flavor_component_sv0p_chi2", 0 ),
// -- slimmed --         flavor_component_sv0p_ndof( this, ::TString( prefix ) + "flavor_component_sv0p_ndof", 0 ),
// -- slimmed --         flavor_component_sv0p_ntrk( this, ::TString( prefix ) + "flavor_component_sv0p_ntrk", 0 ),
// -- slimmed --         flavor_assoctrk_n( this, ::TString( prefix ) + "flavor_assoctrk_n", 0 ),
// -- slimmed --         flavor_assoctrk_index( this, ::TString( prefix ) + "flavor_assoctrk_index", 0 ),
// -- slimmed --         el_dr( this, ::TString( prefix ) + "el_dr", 0 ),
// -- slimmed --         el_matched( this, ::TString( prefix ) + "el_matched", 0 ),
// -- slimmed --         mu_dr( this, ::TString( prefix ) + "mu_dr", 0 ),
// -- slimmed --         mu_matched( this, ::TString( prefix ) + "mu_matched", 0 ),
// -- slimmed --         L1_dr( this, ::TString( prefix ) + "L1_dr", 0 ),
// -- slimmed --         L1_matched( this, ::TString( prefix ) + "L1_matched", 0 ),
// -- slimmed --         L2_dr( this, ::TString( prefix ) + "L2_dr", 0 ),
// -- slimmed --         L2_matched( this, ::TString( prefix ) + "L2_matched", 0 ),
// -- slimmed --         EF_dr( this, ::TString( prefix ) + "EF_dr", 0 ),
// -- slimmed --         EF_matched( this, ::TString( prefix ) + "EF_matched", 0 ),
// -- slimmed --         bbDecision( this, ::TString( prefix ) + "bbDecision", 0 ),
// -- slimmed --         SmearingFactor( this, ::TString( prefix ) + "SmearingFactor", 0 ),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "MET_Egamma10NoTau_wpx" ] = &MET_Egamma10NoTau_wpx;
      fHandles[ "MET_Egamma10NoTau_wpy" ] = &MET_Egamma10NoTau_wpy;
      fHandles[ "MET_Egamma10NoTau_wet" ] = &MET_Egamma10NoTau_wet;
      fHandles[ "MET_Egamma10NoTau_statusWord" ] = &MET_Egamma10NoTau_statusWord;
      fHandles[ "MET_Egamma10NoTau_STVF_wpx" ] = &MET_Egamma10NoTau_STVF_wpx;
      fHandles[ "MET_Egamma10NoTau_STVF_wpy" ] = &MET_Egamma10NoTau_STVF_wpy;
      fHandles[ "MET_Egamma10NoTau_STVF_wet" ] = &MET_Egamma10NoTau_STVF_wet;
      fHandles[ "MET_Egamma10NoTau_STVF_statusWord" ] = &MET_Egamma10NoTau_STVF_statusWord;
// -- slimmed --       fHandles[ "MET_LooseEgamma10NoTau_wpx" ] = &MET_LooseEgamma10NoTau_wpx;
// -- slimmed --       fHandles[ "MET_LooseEgamma10NoTau_wpy" ] = &MET_LooseEgamma10NoTau_wpy;
// -- slimmed --       fHandles[ "MET_LooseEgamma10NoTau_wet" ] = &MET_LooseEgamma10NoTau_wet;
// -- slimmed --       fHandles[ "MET_LooseEgamma10NoTau_statusWord" ] = &MET_LooseEgamma10NoTau_statusWord;
// -- slimmed --       fHandles[ "MET_wpx" ] = &MET_wpx;
// -- slimmed --       fHandles[ "MET_wpy" ] = &MET_wpy;
// -- slimmed --       fHandles[ "MET_wet" ] = &MET_wet;
// -- slimmed --       fHandles[ "MET_statusWord" ] = &MET_statusWord;
// -- slimmed --       fHandles[ "MET_STVF_wpx" ] = &MET_STVF_wpx;
// -- slimmed --       fHandles[ "MET_STVF_wpy" ] = &MET_STVF_wpy;
// -- slimmed --       fHandles[ "MET_STVF_wet" ] = &MET_STVF_wet;
// -- slimmed --       fHandles[ "MET_STVF_statusWord" ] = &MET_STVF_statusWord;
      fHandles[ "n" ] = &n;
      fHandles[ "E" ] = &E;
      fHandles[ "pt" ] = &pt;
      fHandles[ "m" ] = &m;
      fHandles[ "eta" ] = &eta;
      fHandles[ "phi" ] = &phi;
      fHandles[ "EtaOrigin" ] = &EtaOrigin;
      fHandles[ "PhiOrigin" ] = &PhiOrigin;
      fHandles[ "MOrigin" ] = &MOrigin;
      fHandles[ "EtaOriginEM" ] = &EtaOriginEM;
      fHandles[ "PhiOriginEM" ] = &PhiOriginEM;
      fHandles[ "MOriginEM" ] = &MOriginEM;
// -- slimmed --       fHandles[ "WIDTH" ] = &WIDTH;
// -- slimmed --       fHandles[ "n90" ] = &n90;
// -- slimmed --       fHandles[ "Timing" ] = &Timing;
      fHandles[ "LArQuality" ] = &LArQuality;
      fHandles[ "nTrk" ] = &nTrk;
      fHandles[ "sumPtTrk" ] = &sumPtTrk;
      fHandles[ "OriginIndex" ] = &OriginIndex;
      fHandles[ "HECQuality" ] = &HECQuality;
      fHandles[ "NegativeE" ] = &NegativeE;
      fHandles[ "AverageLArQF" ] = &AverageLArQF;
// -- slimmed --       fHandles[ "YFlip12" ] = &YFlip12;
// -- slimmed --       fHandles[ "YFlip23" ] = &YFlip23;
// -- slimmed --       fHandles[ "BCH_CORR_CELL" ] = &BCH_CORR_CELL;
// -- slimmed --       fHandles[ "BCH_CORR_DOTX" ] = &BCH_CORR_DOTX;
// -- slimmed --       fHandles[ "BCH_CORR_JET" ] = &BCH_CORR_JET;
// -- slimmed --       fHandles[ "BCH_CORR_JET_FORCELL" ] = &BCH_CORR_JET_FORCELL;
      fHandles[ "ENG_BAD_CELLS" ] = &ENG_BAD_CELLS;
      fHandles[ "N_BAD_CELLS" ] = &N_BAD_CELLS;
      fHandles[ "N_BAD_CELLS_CORR" ] = &N_BAD_CELLS_CORR;
      fHandles[ "BAD_CELLS_CORR_E" ] = &BAD_CELLS_CORR_E;
// -- slimmed --       fHandles[ "NumTowers" ] = &NumTowers;
// -- slimmed --       fHandles[ "ootFracCells5" ] = &ootFracCells5;
// -- slimmed --       fHandles[ "ootFracCells10" ] = &ootFracCells10;
// -- slimmed --       fHandles[ "ootFracClusters5" ] = &ootFracClusters5;
// -- slimmed --       fHandles[ "ootFracClusters10" ] = &ootFracClusters10;
      fHandles[ "SamplingMax" ] = &SamplingMax;
      fHandles[ "fracSamplingMax" ] = &fracSamplingMax;
      fHandles[ "hecf" ] = &hecf;
// -- slimmed --       fHandles[ "tgap3f" ] = &tgap3f;
// -- slimmed --       fHandles[ "isUgly" ] = &isUgly;
// -- slimmed --       fHandles[ "isBadLooseMinus" ] = &isBadLooseMinus;
// -- slimmed --       fHandles[ "isBadLoose" ] = &isBadLoose;
// -- slimmed --       fHandles[ "isBadMedium" ] = &isBadMedium;
// -- slimmed --       fHandles[ "isBadTight" ] = &isBadTight;
      fHandles[ "emfrac" ] = &emfrac;
      fHandles[ "Offset" ] = &Offset;
      fHandles[ "EMJES" ] = &EMJES;
      fHandles[ "EMJES_EtaCorr" ] = &EMJES_EtaCorr;
      fHandles[ "EMJESnooffset" ] = &EMJESnooffset;
      fHandles[ "GCWJES" ] = &GCWJES;
      fHandles[ "GCWJES_EtaCorr" ] = &GCWJES_EtaCorr;
      fHandles[ "CB" ] = &CB;
      fHandles[ "LCJES" ] = &LCJES;
      fHandles[ "emscale_E" ] = &emscale_E;
      fHandles[ "emscale_pt" ] = &emscale_pt;
      fHandles[ "emscale_m" ] = &emscale_m;
      fHandles[ "emscale_eta" ] = &emscale_eta;
      fHandles[ "emscale_phi" ] = &emscale_phi;
      fHandles[ "jvtx_x" ] = &jvtx_x;
      fHandles[ "jvtx_y" ] = &jvtx_y;
      fHandles[ "jvtx_z" ] = &jvtx_z;
      fHandles[ "jvtxf" ] = &jvtxf;
      fHandles[ "jvtxfFull" ] = &jvtxfFull;
      fHandles[ "GSCFactorF" ] = &GSCFactorF;
      fHandles[ "WidthFraction" ] = &WidthFraction;
      fHandles[ "e_PreSamplerB" ] = &e_PreSamplerB;
// -- slimmed --       fHandles[ "e_EMB1" ] = &e_EMB1;
// -- slimmed --       fHandles[ "e_EMB2" ] = &e_EMB2;
// -- slimmed --       fHandles[ "e_EMB3" ] = &e_EMB3;
// -- slimmed --       fHandles[ "e_PreSamplerE" ] = &e_PreSamplerE;
// -- slimmed --       fHandles[ "e_EME1" ] = &e_EME1;
// -- slimmed --       fHandles[ "e_EME2" ] = &e_EME2;
// -- slimmed --       fHandles[ "e_EME3" ] = &e_EME3;
// -- slimmed --       fHandles[ "e_HEC0" ] = &e_HEC0;
// -- slimmed --       fHandles[ "e_HEC1" ] = &e_HEC1;
// -- slimmed --       fHandles[ "e_HEC2" ] = &e_HEC2;
// -- slimmed --       fHandles[ "e_HEC3" ] = &e_HEC3;
// -- slimmed --       fHandles[ "e_TileBar0" ] = &e_TileBar0;
// -- slimmed --       fHandles[ "e_TileBar1" ] = &e_TileBar1;
// -- slimmed --       fHandles[ "e_TileBar2" ] = &e_TileBar2;
// -- slimmed --       fHandles[ "e_TileGap1" ] = &e_TileGap1;
// -- slimmed --       fHandles[ "e_TileGap2" ] = &e_TileGap2;
// -- slimmed --       fHandles[ "e_TileGap3" ] = &e_TileGap3;
// -- slimmed --       fHandles[ "e_TileExt0" ] = &e_TileExt0;
// -- slimmed --       fHandles[ "e_TileExt1" ] = &e_TileExt1;
// -- slimmed --       fHandles[ "e_TileExt2" ] = &e_TileExt2;
// -- slimmed --       fHandles[ "e_FCAL0" ] = &e_FCAL0;
// -- slimmed --       fHandles[ "e_FCAL1" ] = &e_FCAL1;
// -- slimmed --       fHandles[ "e_FCAL2" ] = &e_FCAL2;
// -- slimmed --       fHandles[ "Nconst" ] = &Nconst;
// -- slimmed --       fHandles[ "ptconst_default" ] = &ptconst_default;
// -- slimmed --       fHandles[ "econst_default" ] = &econst_default;
// -- slimmed --       fHandles[ "etaconst_default" ] = &etaconst_default;
// -- slimmed --       fHandles[ "phiconst_default" ] = &phiconst_default;
// -- slimmed --       fHandles[ "weightconst_default" ] = &weightconst_default;
      fHandles[ "constscale_E" ] = &constscale_E;
      fHandles[ "constscale_pt" ] = &constscale_pt;
      fHandles[ "constscale_m" ] = &constscale_m;
      fHandles[ "constscale_eta" ] = &constscale_eta;
      fHandles[ "constscale_phi" ] = &constscale_phi;
      fHandles[ "flavor_weight_Comb" ] = &flavor_weight_Comb;
      fHandles[ "flavor_weight_IP2D" ] = &flavor_weight_IP2D;
      fHandles[ "flavor_weight_IP3D" ] = &flavor_weight_IP3D;
      fHandles[ "flavor_weight_SV0" ] = &flavor_weight_SV0;
      fHandles[ "flavor_weight_SV1" ] = &flavor_weight_SV1;
      fHandles[ "flavor_weight_SV2" ] = &flavor_weight_SV2;
      fHandles[ "flavor_weight_SoftMuonTagChi2" ] = &flavor_weight_SoftMuonTagChi2;
      fHandles[ "flavor_weight_SecondSoftMuonTagChi2" ] = &flavor_weight_SecondSoftMuonTagChi2;
      fHandles[ "flavor_weight_JetFitterTagNN" ] = &flavor_weight_JetFitterTagNN;
      fHandles[ "flavor_weight_JetFitterCOMBNN" ] = &flavor_weight_JetFitterCOMBNN;
      fHandles[ "flavor_weight_MV1" ] = &flavor_weight_MV1;
      fHandles[ "flavor_weight_MV2" ] = &flavor_weight_MV2;
      fHandles[ "flavor_weight_GbbNN" ] = &flavor_weight_GbbNN;
if (!is_data) {
      fHandles[ "flavor_truth_label" ] = &flavor_truth_label;
      fHandles[ "flavor_truth_dRminToB" ] = &flavor_truth_dRminToB;
      fHandles[ "flavor_truth_dRminToC" ] = &flavor_truth_dRminToC;
      fHandles[ "flavor_truth_dRminToT" ] = &flavor_truth_dRminToT;
      fHandles[ "flavor_truth_BHadronpdg" ] = &flavor_truth_BHadronpdg;
      fHandles[ "flavor_truth_vx_x" ] = &flavor_truth_vx_x;
      fHandles[ "flavor_truth_vx_y" ] = &flavor_truth_vx_y;
      fHandles[ "flavor_truth_vx_z" ] = &flavor_truth_vx_z;
} // end !is_data
// -- slimmed --       fHandles[ "flavor_component_ip2d_pu" ] = &flavor_component_ip2d_pu;
// -- slimmed --       fHandles[ "flavor_component_ip2d_pb" ] = &flavor_component_ip2d_pb;
// -- slimmed --       fHandles[ "flavor_component_ip2d_isValid" ] = &flavor_component_ip2d_isValid;
// -- slimmed --       fHandles[ "flavor_component_ip2d_ntrk" ] = &flavor_component_ip2d_ntrk;
// -- slimmed --       fHandles[ "flavor_component_ip3d_pu" ] = &flavor_component_ip3d_pu;
// -- slimmed --       fHandles[ "flavor_component_ip3d_pb" ] = &flavor_component_ip3d_pb;
// -- slimmed --       fHandles[ "flavor_component_ip3d_isValid" ] = &flavor_component_ip3d_isValid;
// -- slimmed --       fHandles[ "flavor_component_ip3d_ntrk" ] = &flavor_component_ip3d_ntrk;
// -- slimmed --       fHandles[ "flavor_component_sv1_pu" ] = &flavor_component_sv1_pu;
// -- slimmed --       fHandles[ "flavor_component_sv1_pb" ] = &flavor_component_sv1_pb;
// -- slimmed --       fHandles[ "flavor_component_sv1_isValid" ] = &flavor_component_sv1_isValid;
// -- slimmed --       fHandles[ "flavor_component_sv2_pu" ] = &flavor_component_sv2_pu;
// -- slimmed --       fHandles[ "flavor_component_sv2_pb" ] = &flavor_component_sv2_pb;
// -- slimmed --       fHandles[ "flavor_component_sv2_isValid" ] = &flavor_component_sv2_isValid;
// -- slimmed --       fHandles[ "flavor_component_jfit_pu" ] = &flavor_component_jfit_pu;
// -- slimmed --       fHandles[ "flavor_component_jfit_pb" ] = &flavor_component_jfit_pb;
// -- slimmed --       fHandles[ "flavor_component_jfit_pc" ] = &flavor_component_jfit_pc;
// -- slimmed --       fHandles[ "flavor_component_jfit_isValid" ] = &flavor_component_jfit_isValid;
// -- slimmed --       fHandles[ "flavor_component_jfitcomb_pu" ] = &flavor_component_jfitcomb_pu;
// -- slimmed --       fHandles[ "flavor_component_jfitcomb_pb" ] = &flavor_component_jfitcomb_pb;
// -- slimmed --       fHandles[ "flavor_component_jfitcomb_pc" ] = &flavor_component_jfitcomb_pc;
// -- slimmed --       fHandles[ "flavor_component_jfitcomb_isValid" ] = &flavor_component_jfitcomb_isValid;
// -- slimmed --       fHandles[ "flavor_component_jfit_nvtx" ] = &flavor_component_jfit_nvtx;
// -- slimmed --       fHandles[ "flavor_component_jfit_nvtx1t" ] = &flavor_component_jfit_nvtx1t;
// -- slimmed --       fHandles[ "flavor_component_jfit_ntrkAtVx" ] = &flavor_component_jfit_ntrkAtVx;
// -- slimmed --       fHandles[ "flavor_component_jfit_efrc" ] = &flavor_component_jfit_efrc;
// -- slimmed --       fHandles[ "flavor_component_jfit_mass" ] = &flavor_component_jfit_mass;
// -- slimmed --       fHandles[ "flavor_component_jfit_sig3d" ] = &flavor_component_jfit_sig3d;
// -- slimmed --       fHandles[ "flavor_component_jfit_deltaPhi" ] = &flavor_component_jfit_deltaPhi;
// -- slimmed --       fHandles[ "flavor_component_jfit_deltaEta" ] = &flavor_component_jfit_deltaEta;
// -- slimmed --       fHandles[ "flavor_component_svp_isValid" ] = &flavor_component_svp_isValid;
// -- slimmed --       fHandles[ "flavor_component_svp_ntrkv" ] = &flavor_component_svp_ntrkv;
// -- slimmed --       fHandles[ "flavor_component_svp_ntrkj" ] = &flavor_component_svp_ntrkj;
// -- slimmed --       fHandles[ "flavor_component_svp_n2t" ] = &flavor_component_svp_n2t;
// -- slimmed --       fHandles[ "flavor_component_svp_mass" ] = &flavor_component_svp_mass;
// -- slimmed --       fHandles[ "flavor_component_svp_efrc" ] = &flavor_component_svp_efrc;
// -- slimmed --       fHandles[ "flavor_component_svp_x" ] = &flavor_component_svp_x;
// -- slimmed --       fHandles[ "flavor_component_svp_y" ] = &flavor_component_svp_y;
// -- slimmed --       fHandles[ "flavor_component_svp_z" ] = &flavor_component_svp_z;
// -- slimmed --       fHandles[ "flavor_component_svp_err_x" ] = &flavor_component_svp_err_x;
// -- slimmed --       fHandles[ "flavor_component_svp_err_y" ] = &flavor_component_svp_err_y;
// -- slimmed --       fHandles[ "flavor_component_svp_err_z" ] = &flavor_component_svp_err_z;
// -- slimmed --       fHandles[ "flavor_component_svp_cov_xy" ] = &flavor_component_svp_cov_xy;
// -- slimmed --       fHandles[ "flavor_component_svp_cov_xz" ] = &flavor_component_svp_cov_xz;
// -- slimmed --       fHandles[ "flavor_component_svp_cov_yz" ] = &flavor_component_svp_cov_yz;
// -- slimmed --       fHandles[ "flavor_component_svp_chi2" ] = &flavor_component_svp_chi2;
// -- slimmed --       fHandles[ "flavor_component_svp_ndof" ] = &flavor_component_svp_ndof;
// -- slimmed --       fHandles[ "flavor_component_svp_ntrk" ] = &flavor_component_svp_ntrk;
// -- slimmed --       fHandles[ "flavor_component_sv0p_isValid" ] = &flavor_component_sv0p_isValid;
// -- slimmed --       fHandles[ "flavor_component_sv0p_ntrkv" ] = &flavor_component_sv0p_ntrkv;
// -- slimmed --       fHandles[ "flavor_component_sv0p_ntrkj" ] = &flavor_component_sv0p_ntrkj;
// -- slimmed --       fHandles[ "flavor_component_sv0p_n2t" ] = &flavor_component_sv0p_n2t;
// -- slimmed --       fHandles[ "flavor_component_sv0p_mass" ] = &flavor_component_sv0p_mass;
// -- slimmed --       fHandles[ "flavor_component_sv0p_efrc" ] = &flavor_component_sv0p_efrc;
// -- slimmed --       fHandles[ "flavor_component_sv0p_x" ] = &flavor_component_sv0p_x;
// -- slimmed --       fHandles[ "flavor_component_sv0p_y" ] = &flavor_component_sv0p_y;
// -- slimmed --       fHandles[ "flavor_component_sv0p_z" ] = &flavor_component_sv0p_z;
// -- slimmed --       fHandles[ "flavor_component_sv0p_err_x" ] = &flavor_component_sv0p_err_x;
// -- slimmed --       fHandles[ "flavor_component_sv0p_err_y" ] = &flavor_component_sv0p_err_y;
// -- slimmed --       fHandles[ "flavor_component_sv0p_err_z" ] = &flavor_component_sv0p_err_z;
// -- slimmed --       fHandles[ "flavor_component_sv0p_cov_xy" ] = &flavor_component_sv0p_cov_xy;
// -- slimmed --       fHandles[ "flavor_component_sv0p_cov_xz" ] = &flavor_component_sv0p_cov_xz;
// -- slimmed --       fHandles[ "flavor_component_sv0p_cov_yz" ] = &flavor_component_sv0p_cov_yz;
// -- slimmed --       fHandles[ "flavor_component_sv0p_chi2" ] = &flavor_component_sv0p_chi2;
// -- slimmed --       fHandles[ "flavor_component_sv0p_ndof" ] = &flavor_component_sv0p_ndof;
// -- slimmed --       fHandles[ "flavor_component_sv0p_ntrk" ] = &flavor_component_sv0p_ntrk;
// -- slimmed --       fHandles[ "flavor_assoctrk_n" ] = &flavor_assoctrk_n;
// -- slimmed --       fHandles[ "flavor_assoctrk_index" ] = &flavor_assoctrk_index;
// -- slimmed --       fHandles[ "el_dr" ] = &el_dr;
// -- slimmed --       fHandles[ "el_matched" ] = &el_matched;
// -- slimmed --       fHandles[ "mu_dr" ] = &mu_dr;
// -- slimmed --       fHandles[ "mu_matched" ] = &mu_matched;
// -- slimmed --       fHandles[ "L1_dr" ] = &L1_dr;
// -- slimmed --       fHandles[ "L1_matched" ] = &L1_matched;
// -- slimmed --       fHandles[ "L2_dr" ] = &L2_dr;
// -- slimmed --       fHandles[ "L2_matched" ] = &L2_matched;
// -- slimmed --       fHandles[ "EF_dr" ] = &EF_dr;
// -- slimmed --       fHandles[ "EF_matched" ] = &EF_matched;
// -- slimmed --       fHandles[ "bbDecision" ] = &bbDecision;
// -- slimmed --       fHandles[ "SmearingFactor" ] = &SmearingFactor;
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* JetD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void JetD3PDObject::SetPrefix( const char* prefix ) {

      MET_Egamma10NoTau_wpx.SetName( ::TString( prefix ) + "MET_Egamma10NoTau_wpx" );
      MET_Egamma10NoTau_wpy.SetName( ::TString( prefix ) + "MET_Egamma10NoTau_wpy" );
      MET_Egamma10NoTau_wet.SetName( ::TString( prefix ) + "MET_Egamma10NoTau_wet" );
      MET_Egamma10NoTau_statusWord.SetName( ::TString( prefix ) + "MET_Egamma10NoTau_statusWord" );
      MET_Egamma10NoTau_STVF_wpx.SetName( ::TString( prefix ) + "MET_Egamma10NoTau_STVF_wpx" );
      MET_Egamma10NoTau_STVF_wpy.SetName( ::TString( prefix ) + "MET_Egamma10NoTau_STVF_wpy" );
      MET_Egamma10NoTau_STVF_wet.SetName( ::TString( prefix ) + "MET_Egamma10NoTau_STVF_wet" );
      MET_Egamma10NoTau_STVF_statusWord.SetName( ::TString( prefix ) + "MET_Egamma10NoTau_STVF_statusWord" );
// -- slimmed --       MET_LooseEgamma10NoTau_wpx.SetName( ::TString( prefix ) + "MET_LooseEgamma10NoTau_wpx" );
// -- slimmed --       MET_LooseEgamma10NoTau_wpy.SetName( ::TString( prefix ) + "MET_LooseEgamma10NoTau_wpy" );
// -- slimmed --       MET_LooseEgamma10NoTau_wet.SetName( ::TString( prefix ) + "MET_LooseEgamma10NoTau_wet" );
// -- slimmed --       MET_LooseEgamma10NoTau_statusWord.SetName( ::TString( prefix ) + "MET_LooseEgamma10NoTau_statusWord" );
// -- slimmed --       MET_wpx.SetName( ::TString( prefix ) + "MET_wpx" );
// -- slimmed --       MET_wpy.SetName( ::TString( prefix ) + "MET_wpy" );
// -- slimmed --       MET_wet.SetName( ::TString( prefix ) + "MET_wet" );
// -- slimmed --       MET_statusWord.SetName( ::TString( prefix ) + "MET_statusWord" );
// -- slimmed --       MET_STVF_wpx.SetName( ::TString( prefix ) + "MET_STVF_wpx" );
// -- slimmed --       MET_STVF_wpy.SetName( ::TString( prefix ) + "MET_STVF_wpy" );
// -- slimmed --       MET_STVF_wet.SetName( ::TString( prefix ) + "MET_STVF_wet" );
// -- slimmed --       MET_STVF_statusWord.SetName( ::TString( prefix ) + "MET_STVF_statusWord" );
      n.SetName( ::TString( prefix ) + "n" );
      E.SetName( ::TString( prefix ) + "E" );
      pt.SetName( ::TString( prefix ) + "pt" );
      m.SetName( ::TString( prefix ) + "m" );
      eta.SetName( ::TString( prefix ) + "eta" );
      phi.SetName( ::TString( prefix ) + "phi" );
      EtaOrigin.SetName( ::TString( prefix ) + "EtaOrigin" );
      PhiOrigin.SetName( ::TString( prefix ) + "PhiOrigin" );
      MOrigin.SetName( ::TString( prefix ) + "MOrigin" );
      EtaOriginEM.SetName( ::TString( prefix ) + "EtaOriginEM" );
      PhiOriginEM.SetName( ::TString( prefix ) + "PhiOriginEM" );
      MOriginEM.SetName( ::TString( prefix ) + "MOriginEM" );
// -- slimmed --       WIDTH.SetName( ::TString( prefix ) + "WIDTH" );
// -- slimmed --       n90.SetName( ::TString( prefix ) + "n90" );
// -- slimmed --       Timing.SetName( ::TString( prefix ) + "Timing" );
      LArQuality.SetName( ::TString( prefix ) + "LArQuality" );
      nTrk.SetName( ::TString( prefix ) + "nTrk" );
      sumPtTrk.SetName( ::TString( prefix ) + "sumPtTrk" );
      OriginIndex.SetName( ::TString( prefix ) + "OriginIndex" );
      HECQuality.SetName( ::TString( prefix ) + "HECQuality" );
      NegativeE.SetName( ::TString( prefix ) + "NegativeE" );
      AverageLArQF.SetName( ::TString( prefix ) + "AverageLArQF" );
// -- slimmed --       YFlip12.SetName( ::TString( prefix ) + "YFlip12" );
// -- slimmed --       YFlip23.SetName( ::TString( prefix ) + "YFlip23" );
// -- slimmed --       BCH_CORR_CELL.SetName( ::TString( prefix ) + "BCH_CORR_CELL" );
// -- slimmed --       BCH_CORR_DOTX.SetName( ::TString( prefix ) + "BCH_CORR_DOTX" );
// -- slimmed --       BCH_CORR_JET.SetName( ::TString( prefix ) + "BCH_CORR_JET" );
// -- slimmed --       BCH_CORR_JET_FORCELL.SetName( ::TString( prefix ) + "BCH_CORR_JET_FORCELL" );
      ENG_BAD_CELLS.SetName( ::TString( prefix ) + "ENG_BAD_CELLS" );
      N_BAD_CELLS.SetName( ::TString( prefix ) + "N_BAD_CELLS" );
      N_BAD_CELLS_CORR.SetName( ::TString( prefix ) + "N_BAD_CELLS_CORR" );
      BAD_CELLS_CORR_E.SetName( ::TString( prefix ) + "BAD_CELLS_CORR_E" );
// -- slimmed --       NumTowers.SetName( ::TString( prefix ) + "NumTowers" );
// -- slimmed --       ootFracCells5.SetName( ::TString( prefix ) + "ootFracCells5" );
// -- slimmed --       ootFracCells10.SetName( ::TString( prefix ) + "ootFracCells10" );
// -- slimmed --       ootFracClusters5.SetName( ::TString( prefix ) + "ootFracClusters5" );
// -- slimmed --       ootFracClusters10.SetName( ::TString( prefix ) + "ootFracClusters10" );
      SamplingMax.SetName( ::TString( prefix ) + "SamplingMax" );
      fracSamplingMax.SetName( ::TString( prefix ) + "fracSamplingMax" );
      hecf.SetName( ::TString( prefix ) + "hecf" );
// -- slimmed --       tgap3f.SetName( ::TString( prefix ) + "tgap3f" );
// -- slimmed --       isUgly.SetName( ::TString( prefix ) + "isUgly" );
// -- slimmed --       isBadLooseMinus.SetName( ::TString( prefix ) + "isBadLooseMinus" );
// -- slimmed --       isBadLoose.SetName( ::TString( prefix ) + "isBadLoose" );
// -- slimmed --       isBadMedium.SetName( ::TString( prefix ) + "isBadMedium" );
// -- slimmed --       isBadTight.SetName( ::TString( prefix ) + "isBadTight" );
      emfrac.SetName( ::TString( prefix ) + "emfrac" );
      Offset.SetName( ::TString( prefix ) + "Offset" );
      EMJES.SetName( ::TString( prefix ) + "EMJES" );
      EMJES_EtaCorr.SetName( ::TString( prefix ) + "EMJES_EtaCorr" );
      EMJESnooffset.SetName( ::TString( prefix ) + "EMJESnooffset" );
      GCWJES.SetName( ::TString( prefix ) + "GCWJES" );
      GCWJES_EtaCorr.SetName( ::TString( prefix ) + "GCWJES_EtaCorr" );
      CB.SetName( ::TString( prefix ) + "CB" );
      LCJES.SetName( ::TString( prefix ) + "LCJES" );
      emscale_E.SetName( ::TString( prefix ) + "emscale_E" );
      emscale_pt.SetName( ::TString( prefix ) + "emscale_pt" );
      emscale_m.SetName( ::TString( prefix ) + "emscale_m" );
      emscale_eta.SetName( ::TString( prefix ) + "emscale_eta" );
      emscale_phi.SetName( ::TString( prefix ) + "emscale_phi" );
      jvtx_x.SetName( ::TString( prefix ) + "jvtx_x" );
      jvtx_y.SetName( ::TString( prefix ) + "jvtx_y" );
      jvtx_z.SetName( ::TString( prefix ) + "jvtx_z" );
      jvtxf.SetName( ::TString( prefix ) + "jvtxf" );
      jvtxfFull.SetName( ::TString( prefix ) + "jvtxfFull" );
      GSCFactorF.SetName( ::TString( prefix ) + "GSCFactorF" );
      WidthFraction.SetName( ::TString( prefix ) + "WidthFraction" );
      e_PreSamplerB.SetName( ::TString( prefix ) + "e_PreSamplerB" );
// -- slimmed --       e_EMB1.SetName( ::TString( prefix ) + "e_EMB1" );
// -- slimmed --       e_EMB2.SetName( ::TString( prefix ) + "e_EMB2" );
// -- slimmed --       e_EMB3.SetName( ::TString( prefix ) + "e_EMB3" );
// -- slimmed --       e_PreSamplerE.SetName( ::TString( prefix ) + "e_PreSamplerE" );
// -- slimmed --       e_EME1.SetName( ::TString( prefix ) + "e_EME1" );
// -- slimmed --       e_EME2.SetName( ::TString( prefix ) + "e_EME2" );
// -- slimmed --       e_EME3.SetName( ::TString( prefix ) + "e_EME3" );
// -- slimmed --       e_HEC0.SetName( ::TString( prefix ) + "e_HEC0" );
// -- slimmed --       e_HEC1.SetName( ::TString( prefix ) + "e_HEC1" );
// -- slimmed --       e_HEC2.SetName( ::TString( prefix ) + "e_HEC2" );
// -- slimmed --       e_HEC3.SetName( ::TString( prefix ) + "e_HEC3" );
// -- slimmed --       e_TileBar0.SetName( ::TString( prefix ) + "e_TileBar0" );
// -- slimmed --       e_TileBar1.SetName( ::TString( prefix ) + "e_TileBar1" );
// -- slimmed --       e_TileBar2.SetName( ::TString( prefix ) + "e_TileBar2" );
// -- slimmed --       e_TileGap1.SetName( ::TString( prefix ) + "e_TileGap1" );
// -- slimmed --       e_TileGap2.SetName( ::TString( prefix ) + "e_TileGap2" );
// -- slimmed --       e_TileGap3.SetName( ::TString( prefix ) + "e_TileGap3" );
// -- slimmed --       e_TileExt0.SetName( ::TString( prefix ) + "e_TileExt0" );
// -- slimmed --       e_TileExt1.SetName( ::TString( prefix ) + "e_TileExt1" );
// -- slimmed --       e_TileExt2.SetName( ::TString( prefix ) + "e_TileExt2" );
// -- slimmed --       e_FCAL0.SetName( ::TString( prefix ) + "e_FCAL0" );
// -- slimmed --       e_FCAL1.SetName( ::TString( prefix ) + "e_FCAL1" );
// -- slimmed --       e_FCAL2.SetName( ::TString( prefix ) + "e_FCAL2" );
// -- slimmed --       Nconst.SetName( ::TString( prefix ) + "Nconst" );
// -- slimmed --       ptconst_default.SetName( ::TString( prefix ) + "ptconst_default" );
// -- slimmed --       econst_default.SetName( ::TString( prefix ) + "econst_default" );
// -- slimmed --       etaconst_default.SetName( ::TString( prefix ) + "etaconst_default" );
// -- slimmed --       phiconst_default.SetName( ::TString( prefix ) + "phiconst_default" );
// -- slimmed --       weightconst_default.SetName( ::TString( prefix ) + "weightconst_default" );
      constscale_E.SetName( ::TString( prefix ) + "constscale_E" );
      constscale_pt.SetName( ::TString( prefix ) + "constscale_pt" );
      constscale_m.SetName( ::TString( prefix ) + "constscale_m" );
      constscale_eta.SetName( ::TString( prefix ) + "constscale_eta" );
      constscale_phi.SetName( ::TString( prefix ) + "constscale_phi" );
      flavor_weight_Comb.SetName( ::TString( prefix ) + "flavor_weight_Comb" );
      flavor_weight_IP2D.SetName( ::TString( prefix ) + "flavor_weight_IP2D" );
      flavor_weight_IP3D.SetName( ::TString( prefix ) + "flavor_weight_IP3D" );
      flavor_weight_SV0.SetName( ::TString( prefix ) + "flavor_weight_SV0" );
      flavor_weight_SV1.SetName( ::TString( prefix ) + "flavor_weight_SV1" );
      flavor_weight_SV2.SetName( ::TString( prefix ) + "flavor_weight_SV2" );
      flavor_weight_SoftMuonTagChi2.SetName( ::TString( prefix ) + "flavor_weight_SoftMuonTagChi2" );
      flavor_weight_SecondSoftMuonTagChi2.SetName( ::TString( prefix ) + "flavor_weight_SecondSoftMuonTagChi2" );
      flavor_weight_JetFitterTagNN.SetName( ::TString( prefix ) + "flavor_weight_JetFitterTagNN" );
      flavor_weight_JetFitterCOMBNN.SetName( ::TString( prefix ) + "flavor_weight_JetFitterCOMBNN" );
      flavor_weight_MV1.SetName( ::TString( prefix ) + "flavor_weight_MV1" );
      flavor_weight_MV2.SetName( ::TString( prefix ) + "flavor_weight_MV2" );
      flavor_weight_GbbNN.SetName( ::TString( prefix ) + "flavor_weight_GbbNN" );
if (!is_data) {
      flavor_truth_label.SetName( ::TString( prefix ) + "flavor_truth_label" );
      flavor_truth_dRminToB.SetName( ::TString( prefix ) + "flavor_truth_dRminToB" );
      flavor_truth_dRminToC.SetName( ::TString( prefix ) + "flavor_truth_dRminToC" );
      flavor_truth_dRminToT.SetName( ::TString( prefix ) + "flavor_truth_dRminToT" );
      flavor_truth_BHadronpdg.SetName( ::TString( prefix ) + "flavor_truth_BHadronpdg" );
      flavor_truth_vx_x.SetName( ::TString( prefix ) + "flavor_truth_vx_x" );
      flavor_truth_vx_y.SetName( ::TString( prefix ) + "flavor_truth_vx_y" );
      flavor_truth_vx_z.SetName( ::TString( prefix ) + "flavor_truth_vx_z" );
} // end !is_data
// -- slimmed --       flavor_component_ip2d_pu.SetName( ::TString( prefix ) + "flavor_component_ip2d_pu" );
// -- slimmed --       flavor_component_ip2d_pb.SetName( ::TString( prefix ) + "flavor_component_ip2d_pb" );
// -- slimmed --       flavor_component_ip2d_isValid.SetName( ::TString( prefix ) + "flavor_component_ip2d_isValid" );
// -- slimmed --       flavor_component_ip2d_ntrk.SetName( ::TString( prefix ) + "flavor_component_ip2d_ntrk" );
// -- slimmed --       flavor_component_ip3d_pu.SetName( ::TString( prefix ) + "flavor_component_ip3d_pu" );
// -- slimmed --       flavor_component_ip3d_pb.SetName( ::TString( prefix ) + "flavor_component_ip3d_pb" );
// -- slimmed --       flavor_component_ip3d_isValid.SetName( ::TString( prefix ) + "flavor_component_ip3d_isValid" );
// -- slimmed --       flavor_component_ip3d_ntrk.SetName( ::TString( prefix ) + "flavor_component_ip3d_ntrk" );
// -- slimmed --       flavor_component_sv1_pu.SetName( ::TString( prefix ) + "flavor_component_sv1_pu" );
// -- slimmed --       flavor_component_sv1_pb.SetName( ::TString( prefix ) + "flavor_component_sv1_pb" );
// -- slimmed --       flavor_component_sv1_isValid.SetName( ::TString( prefix ) + "flavor_component_sv1_isValid" );
// -- slimmed --       flavor_component_sv2_pu.SetName( ::TString( prefix ) + "flavor_component_sv2_pu" );
// -- slimmed --       flavor_component_sv2_pb.SetName( ::TString( prefix ) + "flavor_component_sv2_pb" );
// -- slimmed --       flavor_component_sv2_isValid.SetName( ::TString( prefix ) + "flavor_component_sv2_isValid" );
// -- slimmed --       flavor_component_jfit_pu.SetName( ::TString( prefix ) + "flavor_component_jfit_pu" );
// -- slimmed --       flavor_component_jfit_pb.SetName( ::TString( prefix ) + "flavor_component_jfit_pb" );
// -- slimmed --       flavor_component_jfit_pc.SetName( ::TString( prefix ) + "flavor_component_jfit_pc" );
// -- slimmed --       flavor_component_jfit_isValid.SetName( ::TString( prefix ) + "flavor_component_jfit_isValid" );
// -- slimmed --       flavor_component_jfitcomb_pu.SetName( ::TString( prefix ) + "flavor_component_jfitcomb_pu" );
// -- slimmed --       flavor_component_jfitcomb_pb.SetName( ::TString( prefix ) + "flavor_component_jfitcomb_pb" );
// -- slimmed --       flavor_component_jfitcomb_pc.SetName( ::TString( prefix ) + "flavor_component_jfitcomb_pc" );
// -- slimmed --       flavor_component_jfitcomb_isValid.SetName( ::TString( prefix ) + "flavor_component_jfitcomb_isValid" );
// -- slimmed --       flavor_component_jfit_nvtx.SetName( ::TString( prefix ) + "flavor_component_jfit_nvtx" );
// -- slimmed --       flavor_component_jfit_nvtx1t.SetName( ::TString( prefix ) + "flavor_component_jfit_nvtx1t" );
// -- slimmed --       flavor_component_jfit_ntrkAtVx.SetName( ::TString( prefix ) + "flavor_component_jfit_ntrkAtVx" );
// -- slimmed --       flavor_component_jfit_efrc.SetName( ::TString( prefix ) + "flavor_component_jfit_efrc" );
// -- slimmed --       flavor_component_jfit_mass.SetName( ::TString( prefix ) + "flavor_component_jfit_mass" );
// -- slimmed --       flavor_component_jfit_sig3d.SetName( ::TString( prefix ) + "flavor_component_jfit_sig3d" );
// -- slimmed --       flavor_component_jfit_deltaPhi.SetName( ::TString( prefix ) + "flavor_component_jfit_deltaPhi" );
// -- slimmed --       flavor_component_jfit_deltaEta.SetName( ::TString( prefix ) + "flavor_component_jfit_deltaEta" );
// -- slimmed --       flavor_component_svp_isValid.SetName( ::TString( prefix ) + "flavor_component_svp_isValid" );
// -- slimmed --       flavor_component_svp_ntrkv.SetName( ::TString( prefix ) + "flavor_component_svp_ntrkv" );
// -- slimmed --       flavor_component_svp_ntrkj.SetName( ::TString( prefix ) + "flavor_component_svp_ntrkj" );
// -- slimmed --       flavor_component_svp_n2t.SetName( ::TString( prefix ) + "flavor_component_svp_n2t" );
// -- slimmed --       flavor_component_svp_mass.SetName( ::TString( prefix ) + "flavor_component_svp_mass" );
// -- slimmed --       flavor_component_svp_efrc.SetName( ::TString( prefix ) + "flavor_component_svp_efrc" );
// -- slimmed --       flavor_component_svp_x.SetName( ::TString( prefix ) + "flavor_component_svp_x" );
// -- slimmed --       flavor_component_svp_y.SetName( ::TString( prefix ) + "flavor_component_svp_y" );
// -- slimmed --       flavor_component_svp_z.SetName( ::TString( prefix ) + "flavor_component_svp_z" );
// -- slimmed --       flavor_component_svp_err_x.SetName( ::TString( prefix ) + "flavor_component_svp_err_x" );
// -- slimmed --       flavor_component_svp_err_y.SetName( ::TString( prefix ) + "flavor_component_svp_err_y" );
// -- slimmed --       flavor_component_svp_err_z.SetName( ::TString( prefix ) + "flavor_component_svp_err_z" );
// -- slimmed --       flavor_component_svp_cov_xy.SetName( ::TString( prefix ) + "flavor_component_svp_cov_xy" );
// -- slimmed --       flavor_component_svp_cov_xz.SetName( ::TString( prefix ) + "flavor_component_svp_cov_xz" );
// -- slimmed --       flavor_component_svp_cov_yz.SetName( ::TString( prefix ) + "flavor_component_svp_cov_yz" );
// -- slimmed --       flavor_component_svp_chi2.SetName( ::TString( prefix ) + "flavor_component_svp_chi2" );
// -- slimmed --       flavor_component_svp_ndof.SetName( ::TString( prefix ) + "flavor_component_svp_ndof" );
// -- slimmed --       flavor_component_svp_ntrk.SetName( ::TString( prefix ) + "flavor_component_svp_ntrk" );
// -- slimmed --       flavor_component_sv0p_isValid.SetName( ::TString( prefix ) + "flavor_component_sv0p_isValid" );
// -- slimmed --       flavor_component_sv0p_ntrkv.SetName( ::TString( prefix ) + "flavor_component_sv0p_ntrkv" );
// -- slimmed --       flavor_component_sv0p_ntrkj.SetName( ::TString( prefix ) + "flavor_component_sv0p_ntrkj" );
// -- slimmed --       flavor_component_sv0p_n2t.SetName( ::TString( prefix ) + "flavor_component_sv0p_n2t" );
// -- slimmed --       flavor_component_sv0p_mass.SetName( ::TString( prefix ) + "flavor_component_sv0p_mass" );
// -- slimmed --       flavor_component_sv0p_efrc.SetName( ::TString( prefix ) + "flavor_component_sv0p_efrc" );
// -- slimmed --       flavor_component_sv0p_x.SetName( ::TString( prefix ) + "flavor_component_sv0p_x" );
// -- slimmed --       flavor_component_sv0p_y.SetName( ::TString( prefix ) + "flavor_component_sv0p_y" );
// -- slimmed --       flavor_component_sv0p_z.SetName( ::TString( prefix ) + "flavor_component_sv0p_z" );
// -- slimmed --       flavor_component_sv0p_err_x.SetName( ::TString( prefix ) + "flavor_component_sv0p_err_x" );
// -- slimmed --       flavor_component_sv0p_err_y.SetName( ::TString( prefix ) + "flavor_component_sv0p_err_y" );
// -- slimmed --       flavor_component_sv0p_err_z.SetName( ::TString( prefix ) + "flavor_component_sv0p_err_z" );
// -- slimmed --       flavor_component_sv0p_cov_xy.SetName( ::TString( prefix ) + "flavor_component_sv0p_cov_xy" );
// -- slimmed --       flavor_component_sv0p_cov_xz.SetName( ::TString( prefix ) + "flavor_component_sv0p_cov_xz" );
// -- slimmed --       flavor_component_sv0p_cov_yz.SetName( ::TString( prefix ) + "flavor_component_sv0p_cov_yz" );
// -- slimmed --       flavor_component_sv0p_chi2.SetName( ::TString( prefix ) + "flavor_component_sv0p_chi2" );
// -- slimmed --       flavor_component_sv0p_ndof.SetName( ::TString( prefix ) + "flavor_component_sv0p_ndof" );
// -- slimmed --       flavor_component_sv0p_ntrk.SetName( ::TString( prefix ) + "flavor_component_sv0p_ntrk" );
// -- slimmed --       flavor_assoctrk_n.SetName( ::TString( prefix ) + "flavor_assoctrk_n" );
// -- slimmed --       flavor_assoctrk_index.SetName( ::TString( prefix ) + "flavor_assoctrk_index" );
// -- slimmed --       el_dr.SetName( ::TString( prefix ) + "el_dr" );
// -- slimmed --       el_matched.SetName( ::TString( prefix ) + "el_matched" );
// -- slimmed --       mu_dr.SetName( ::TString( prefix ) + "mu_dr" );
// -- slimmed --       mu_matched.SetName( ::TString( prefix ) + "mu_matched" );
// -- slimmed --       L1_dr.SetName( ::TString( prefix ) + "L1_dr" );
// -- slimmed --       L1_matched.SetName( ::TString( prefix ) + "L1_matched" );
// -- slimmed --       L2_dr.SetName( ::TString( prefix ) + "L2_dr" );
// -- slimmed --       L2_matched.SetName( ::TString( prefix ) + "L2_matched" );
// -- slimmed --       EF_dr.SetName( ::TString( prefix ) + "EF_dr" );
// -- slimmed --       EF_matched.SetName( ::TString( prefix ) + "EF_matched" );
// -- slimmed --       bbDecision.SetName( ::TString( prefix ) + "bbDecision" );
// -- slimmed --       SmearingFactor.SetName( ::TString( prefix ) + "SmearingFactor" );
      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void JetD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      MET_Egamma10NoTau_wpx.ReadFrom( tree );
      MET_Egamma10NoTau_wpy.ReadFrom( tree );
      MET_Egamma10NoTau_wet.ReadFrom( tree );
      MET_Egamma10NoTau_statusWord.ReadFrom( tree );
      MET_Egamma10NoTau_STVF_wpx.ReadFrom( tree );
      MET_Egamma10NoTau_STVF_wpy.ReadFrom( tree );
      MET_Egamma10NoTau_STVF_wet.ReadFrom( tree );
      MET_Egamma10NoTau_STVF_statusWord.ReadFrom( tree );
// -- slimmed --       MET_LooseEgamma10NoTau_wpx.ReadFrom( tree );
// -- slimmed --       MET_LooseEgamma10NoTau_wpy.ReadFrom( tree );
// -- slimmed --       MET_LooseEgamma10NoTau_wet.ReadFrom( tree );
// -- slimmed --       MET_LooseEgamma10NoTau_statusWord.ReadFrom( tree );
// -- slimmed --       MET_wpx.ReadFrom( tree );
// -- slimmed --       MET_wpy.ReadFrom( tree );
// -- slimmed --       MET_wet.ReadFrom( tree );
// -- slimmed --       MET_statusWord.ReadFrom( tree );
// -- slimmed --       MET_STVF_wpx.ReadFrom( tree );
// -- slimmed --       MET_STVF_wpy.ReadFrom( tree );
// -- slimmed --       MET_STVF_wet.ReadFrom( tree );
// -- slimmed --       MET_STVF_statusWord.ReadFrom( tree );
      n.ReadFrom( tree );
      E.ReadFrom( tree );
      pt.ReadFrom( tree );
      m.ReadFrom( tree );
      eta.ReadFrom( tree );
      phi.ReadFrom( tree );
      EtaOrigin.ReadFrom( tree );
      PhiOrigin.ReadFrom( tree );
      MOrigin.ReadFrom( tree );
      EtaOriginEM.ReadFrom( tree );
      PhiOriginEM.ReadFrom( tree );
      MOriginEM.ReadFrom( tree );
// -- slimmed --       WIDTH.ReadFrom( tree );
// -- slimmed --       n90.ReadFrom( tree );
// -- slimmed --       Timing.ReadFrom( tree );
      LArQuality.ReadFrom( tree );
      nTrk.ReadFrom( tree );
      sumPtTrk.ReadFrom( tree );
      OriginIndex.ReadFrom( tree );
      HECQuality.ReadFrom( tree );
      NegativeE.ReadFrom( tree );
      AverageLArQF.ReadFrom( tree );
// -- slimmed --       YFlip12.ReadFrom( tree );
// -- slimmed --       YFlip23.ReadFrom( tree );
// -- slimmed --       BCH_CORR_CELL.ReadFrom( tree );
// -- slimmed --       BCH_CORR_DOTX.ReadFrom( tree );
// -- slimmed --       BCH_CORR_JET.ReadFrom( tree );
// -- slimmed --       BCH_CORR_JET_FORCELL.ReadFrom( tree );
      ENG_BAD_CELLS.ReadFrom( tree );
      N_BAD_CELLS.ReadFrom( tree );
      N_BAD_CELLS_CORR.ReadFrom( tree );
      BAD_CELLS_CORR_E.ReadFrom( tree );
// -- slimmed --       NumTowers.ReadFrom( tree );
// -- slimmed --       ootFracCells5.ReadFrom( tree );
// -- slimmed --       ootFracCells10.ReadFrom( tree );
// -- slimmed --       ootFracClusters5.ReadFrom( tree );
// -- slimmed --       ootFracClusters10.ReadFrom( tree );
      SamplingMax.ReadFrom( tree );
      fracSamplingMax.ReadFrom( tree );
      hecf.ReadFrom( tree );
// -- slimmed --       tgap3f.ReadFrom( tree );
// -- slimmed --       isUgly.ReadFrom( tree );
// -- slimmed --       isBadLooseMinus.ReadFrom( tree );
// -- slimmed --       isBadLoose.ReadFrom( tree );
// -- slimmed --       isBadMedium.ReadFrom( tree );
// -- slimmed --       isBadTight.ReadFrom( tree );
      emfrac.ReadFrom( tree );
      Offset.ReadFrom( tree );
      EMJES.ReadFrom( tree );
      EMJES_EtaCorr.ReadFrom( tree );
      EMJESnooffset.ReadFrom( tree );
      GCWJES.ReadFrom( tree );
      GCWJES_EtaCorr.ReadFrom( tree );
      CB.ReadFrom( tree );
      LCJES.ReadFrom( tree );
      emscale_E.ReadFrom( tree );
      emscale_pt.ReadFrom( tree );
      emscale_m.ReadFrom( tree );
      emscale_eta.ReadFrom( tree );
      emscale_phi.ReadFrom( tree );
      jvtx_x.ReadFrom( tree );
      jvtx_y.ReadFrom( tree );
      jvtx_z.ReadFrom( tree );
      jvtxf.ReadFrom( tree );
      jvtxfFull.ReadFrom( tree );
      GSCFactorF.ReadFrom( tree );
      WidthFraction.ReadFrom( tree );
      e_PreSamplerB.ReadFrom( tree );
// -- slimmed --       e_EMB1.ReadFrom( tree );
// -- slimmed --       e_EMB2.ReadFrom( tree );
// -- slimmed --       e_EMB3.ReadFrom( tree );
// -- slimmed --       e_PreSamplerE.ReadFrom( tree );
// -- slimmed --       e_EME1.ReadFrom( tree );
// -- slimmed --       e_EME2.ReadFrom( tree );
// -- slimmed --       e_EME3.ReadFrom( tree );
// -- slimmed --       e_HEC0.ReadFrom( tree );
// -- slimmed --       e_HEC1.ReadFrom( tree );
// -- slimmed --       e_HEC2.ReadFrom( tree );
// -- slimmed --       e_HEC3.ReadFrom( tree );
// -- slimmed --       e_TileBar0.ReadFrom( tree );
// -- slimmed --       e_TileBar1.ReadFrom( tree );
// -- slimmed --       e_TileBar2.ReadFrom( tree );
// -- slimmed --       e_TileGap1.ReadFrom( tree );
// -- slimmed --       e_TileGap2.ReadFrom( tree );
// -- slimmed --       e_TileGap3.ReadFrom( tree );
// -- slimmed --       e_TileExt0.ReadFrom( tree );
// -- slimmed --       e_TileExt1.ReadFrom( tree );
// -- slimmed --       e_TileExt2.ReadFrom( tree );
// -- slimmed --       e_FCAL0.ReadFrom( tree );
// -- slimmed --       e_FCAL1.ReadFrom( tree );
// -- slimmed --       e_FCAL2.ReadFrom( tree );
// -- slimmed --       Nconst.ReadFrom( tree );
// -- slimmed --       ptconst_default.ReadFrom( tree );
// -- slimmed --       econst_default.ReadFrom( tree );
// -- slimmed --       etaconst_default.ReadFrom( tree );
// -- slimmed --       phiconst_default.ReadFrom( tree );
// -- slimmed --       weightconst_default.ReadFrom( tree );
      constscale_E.ReadFrom( tree );
      constscale_pt.ReadFrom( tree );
      constscale_m.ReadFrom( tree );
      constscale_eta.ReadFrom( tree );
      constscale_phi.ReadFrom( tree );
      flavor_weight_Comb.ReadFrom( tree );
      flavor_weight_IP2D.ReadFrom( tree );
      flavor_weight_IP3D.ReadFrom( tree );
      flavor_weight_SV0.ReadFrom( tree );
      flavor_weight_SV1.ReadFrom( tree );
      flavor_weight_SV2.ReadFrom( tree );
      flavor_weight_SoftMuonTagChi2.ReadFrom( tree );
      flavor_weight_SecondSoftMuonTagChi2.ReadFrom( tree );
      flavor_weight_JetFitterTagNN.ReadFrom( tree );
      flavor_weight_JetFitterCOMBNN.ReadFrom( tree );
      flavor_weight_MV1.ReadFrom( tree );
      flavor_weight_MV2.ReadFrom( tree );
      flavor_weight_GbbNN.ReadFrom( tree );
if (!is_data) {
      flavor_truth_label.ReadFrom( tree );
      flavor_truth_dRminToB.ReadFrom( tree );
      flavor_truth_dRminToC.ReadFrom( tree );
      flavor_truth_dRminToT.ReadFrom( tree );
      flavor_truth_BHadronpdg.ReadFrom( tree );
      flavor_truth_vx_x.ReadFrom( tree );
      flavor_truth_vx_y.ReadFrom( tree );
      flavor_truth_vx_z.ReadFrom( tree );
} // end !is_data
// -- slimmed --       flavor_component_ip2d_pu.ReadFrom( tree );
// -- slimmed --       flavor_component_ip2d_pb.ReadFrom( tree );
// -- slimmed --       flavor_component_ip2d_isValid.ReadFrom( tree );
// -- slimmed --       flavor_component_ip2d_ntrk.ReadFrom( tree );
// -- slimmed --       flavor_component_ip3d_pu.ReadFrom( tree );
// -- slimmed --       flavor_component_ip3d_pb.ReadFrom( tree );
// -- slimmed --       flavor_component_ip3d_isValid.ReadFrom( tree );
// -- slimmed --       flavor_component_ip3d_ntrk.ReadFrom( tree );
// -- slimmed --       flavor_component_sv1_pu.ReadFrom( tree );
// -- slimmed --       flavor_component_sv1_pb.ReadFrom( tree );
// -- slimmed --       flavor_component_sv1_isValid.ReadFrom( tree );
// -- slimmed --       flavor_component_sv2_pu.ReadFrom( tree );
// -- slimmed --       flavor_component_sv2_pb.ReadFrom( tree );
// -- slimmed --       flavor_component_sv2_isValid.ReadFrom( tree );
// -- slimmed --       flavor_component_jfit_pu.ReadFrom( tree );
// -- slimmed --       flavor_component_jfit_pb.ReadFrom( tree );
// -- slimmed --       flavor_component_jfit_pc.ReadFrom( tree );
// -- slimmed --       flavor_component_jfit_isValid.ReadFrom( tree );
// -- slimmed --       flavor_component_jfitcomb_pu.ReadFrom( tree );
// -- slimmed --       flavor_component_jfitcomb_pb.ReadFrom( tree );
// -- slimmed --       flavor_component_jfitcomb_pc.ReadFrom( tree );
// -- slimmed --       flavor_component_jfitcomb_isValid.ReadFrom( tree );
// -- slimmed --       flavor_component_jfit_nvtx.ReadFrom( tree );
// -- slimmed --       flavor_component_jfit_nvtx1t.ReadFrom( tree );
// -- slimmed --       flavor_component_jfit_ntrkAtVx.ReadFrom( tree );
// -- slimmed --       flavor_component_jfit_efrc.ReadFrom( tree );
// -- slimmed --       flavor_component_jfit_mass.ReadFrom( tree );
// -- slimmed --       flavor_component_jfit_sig3d.ReadFrom( tree );
// -- slimmed --       flavor_component_jfit_deltaPhi.ReadFrom( tree );
// -- slimmed --       flavor_component_jfit_deltaEta.ReadFrom( tree );
// -- slimmed --       flavor_component_svp_isValid.ReadFrom( tree );
// -- slimmed --       flavor_component_svp_ntrkv.ReadFrom( tree );
// -- slimmed --       flavor_component_svp_ntrkj.ReadFrom( tree );
// -- slimmed --       flavor_component_svp_n2t.ReadFrom( tree );
// -- slimmed --       flavor_component_svp_mass.ReadFrom( tree );
// -- slimmed --       flavor_component_svp_efrc.ReadFrom( tree );
// -- slimmed --       flavor_component_svp_x.ReadFrom( tree );
// -- slimmed --       flavor_component_svp_y.ReadFrom( tree );
// -- slimmed --       flavor_component_svp_z.ReadFrom( tree );
// -- slimmed --       flavor_component_svp_err_x.ReadFrom( tree );
// -- slimmed --       flavor_component_svp_err_y.ReadFrom( tree );
// -- slimmed --       flavor_component_svp_err_z.ReadFrom( tree );
// -- slimmed --       flavor_component_svp_cov_xy.ReadFrom( tree );
// -- slimmed --       flavor_component_svp_cov_xz.ReadFrom( tree );
// -- slimmed --       flavor_component_svp_cov_yz.ReadFrom( tree );
// -- slimmed --       flavor_component_svp_chi2.ReadFrom( tree );
// -- slimmed --       flavor_component_svp_ndof.ReadFrom( tree );
// -- slimmed --       flavor_component_svp_ntrk.ReadFrom( tree );
// -- slimmed --       flavor_component_sv0p_isValid.ReadFrom( tree );
// -- slimmed --       flavor_component_sv0p_ntrkv.ReadFrom( tree );
// -- slimmed --       flavor_component_sv0p_ntrkj.ReadFrom( tree );
// -- slimmed --       flavor_component_sv0p_n2t.ReadFrom( tree );
// -- slimmed --       flavor_component_sv0p_mass.ReadFrom( tree );
// -- slimmed --       flavor_component_sv0p_efrc.ReadFrom( tree );
// -- slimmed --       flavor_component_sv0p_x.ReadFrom( tree );
// -- slimmed --       flavor_component_sv0p_y.ReadFrom( tree );
// -- slimmed --       flavor_component_sv0p_z.ReadFrom( tree );
// -- slimmed --       flavor_component_sv0p_err_x.ReadFrom( tree );
// -- slimmed --       flavor_component_sv0p_err_y.ReadFrom( tree );
// -- slimmed --       flavor_component_sv0p_err_z.ReadFrom( tree );
// -- slimmed --       flavor_component_sv0p_cov_xy.ReadFrom( tree );
// -- slimmed --       flavor_component_sv0p_cov_xz.ReadFrom( tree );
// -- slimmed --       flavor_component_sv0p_cov_yz.ReadFrom( tree );
// -- slimmed --       flavor_component_sv0p_chi2.ReadFrom( tree );
// -- slimmed --       flavor_component_sv0p_ndof.ReadFrom( tree );
// -- slimmed --       flavor_component_sv0p_ntrk.ReadFrom( tree );
// -- slimmed --       flavor_assoctrk_n.ReadFrom( tree );
// -- slimmed --       flavor_assoctrk_index.ReadFrom( tree );
// -- slimmed --       el_dr.ReadFrom( tree );
// -- slimmed --       el_matched.ReadFrom( tree );
// -- slimmed --       mu_dr.ReadFrom( tree );
// -- slimmed --       mu_matched.ReadFrom( tree );
// -- slimmed --       L1_dr.ReadFrom( tree );
// -- slimmed --       L1_matched.ReadFrom( tree );
// -- slimmed --       L2_dr.ReadFrom( tree );
// -- slimmed --       L2_matched.ReadFrom( tree );
// -- slimmed --       EF_dr.ReadFrom( tree );
// -- slimmed --       EF_matched.ReadFrom( tree );
// -- slimmed --       bbDecision.ReadFrom( tree );
// -- slimmed --       SmearingFactor.ReadFrom( tree );

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void JetD3PDObject::WriteTo( TTree* tree ) {

      MET_Egamma10NoTau_wpx.WriteTo( tree );
      MET_Egamma10NoTau_wpy.WriteTo( tree );
      MET_Egamma10NoTau_wet.WriteTo( tree );
      MET_Egamma10NoTau_statusWord.WriteTo( tree );
      MET_Egamma10NoTau_STVF_wpx.WriteTo( tree );
      MET_Egamma10NoTau_STVF_wpy.WriteTo( tree );
      MET_Egamma10NoTau_STVF_wet.WriteTo( tree );
      MET_Egamma10NoTau_STVF_statusWord.WriteTo( tree );
// -- slimmed --       MET_LooseEgamma10NoTau_wpx.WriteTo( tree );
// -- slimmed --       MET_LooseEgamma10NoTau_wpy.WriteTo( tree );
// -- slimmed --       MET_LooseEgamma10NoTau_wet.WriteTo( tree );
// -- slimmed --       MET_LooseEgamma10NoTau_statusWord.WriteTo( tree );
// -- slimmed --       MET_wpx.WriteTo( tree );
// -- slimmed --       MET_wpy.WriteTo( tree );
// -- slimmed --       MET_wet.WriteTo( tree );
// -- slimmed --       MET_statusWord.WriteTo( tree );
// -- slimmed --       MET_STVF_wpx.WriteTo( tree );
// -- slimmed --       MET_STVF_wpy.WriteTo( tree );
// -- slimmed --       MET_STVF_wet.WriteTo( tree );
// -- slimmed --       MET_STVF_statusWord.WriteTo( tree );
      n.WriteTo( tree );
      E.WriteTo( tree );
      pt.WriteTo( tree );
      m.WriteTo( tree );
      eta.WriteTo( tree );
      phi.WriteTo( tree );
      EtaOrigin.WriteTo( tree );
      PhiOrigin.WriteTo( tree );
      MOrigin.WriteTo( tree );
      EtaOriginEM.WriteTo( tree );
      PhiOriginEM.WriteTo( tree );
      MOriginEM.WriteTo( tree );
// -- slimmed --       WIDTH.WriteTo( tree );
// -- slimmed --       n90.WriteTo( tree );
// -- slimmed --       Timing.WriteTo( tree );
      LArQuality.WriteTo( tree );
      nTrk.WriteTo( tree );
      sumPtTrk.WriteTo( tree );
      OriginIndex.WriteTo( tree );
      HECQuality.WriteTo( tree );
      NegativeE.WriteTo( tree );
      AverageLArQF.WriteTo( tree );
// -- slimmed --       YFlip12.WriteTo( tree );
// -- slimmed --       YFlip23.WriteTo( tree );
// -- slimmed --       BCH_CORR_CELL.WriteTo( tree );
// -- slimmed --       BCH_CORR_DOTX.WriteTo( tree );
// -- slimmed --       BCH_CORR_JET.WriteTo( tree );
// -- slimmed --       BCH_CORR_JET_FORCELL.WriteTo( tree );
      ENG_BAD_CELLS.WriteTo( tree );
      N_BAD_CELLS.WriteTo( tree );
      N_BAD_CELLS_CORR.WriteTo( tree );
      BAD_CELLS_CORR_E.WriteTo( tree );
// -- slimmed --       NumTowers.WriteTo( tree );
// -- slimmed --       ootFracCells5.WriteTo( tree );
// -- slimmed --       ootFracCells10.WriteTo( tree );
// -- slimmed --       ootFracClusters5.WriteTo( tree );
// -- slimmed --       ootFracClusters10.WriteTo( tree );
      SamplingMax.WriteTo( tree );
      fracSamplingMax.WriteTo( tree );
      hecf.WriteTo( tree );
// -- slimmed --       tgap3f.WriteTo( tree );
// -- slimmed --       isUgly.WriteTo( tree );
// -- slimmed --       isBadLooseMinus.WriteTo( tree );
// -- slimmed --       isBadLoose.WriteTo( tree );
// -- slimmed --       isBadMedium.WriteTo( tree );
// -- slimmed --       isBadTight.WriteTo( tree );
      emfrac.WriteTo( tree );
      Offset.WriteTo( tree );
      EMJES.WriteTo( tree );
      EMJES_EtaCorr.WriteTo( tree );
      EMJESnooffset.WriteTo( tree );
      GCWJES.WriteTo( tree );
      GCWJES_EtaCorr.WriteTo( tree );
      CB.WriteTo( tree );
      LCJES.WriteTo( tree );
      emscale_E.WriteTo( tree );
      emscale_pt.WriteTo( tree );
      emscale_m.WriteTo( tree );
      emscale_eta.WriteTo( tree );
      emscale_phi.WriteTo( tree );
      jvtx_x.WriteTo( tree );
      jvtx_y.WriteTo( tree );
      jvtx_z.WriteTo( tree );
      jvtxf.WriteTo( tree );
      jvtxfFull.WriteTo( tree );
      GSCFactorF.WriteTo( tree );
      WidthFraction.WriteTo( tree );
      e_PreSamplerB.WriteTo( tree );
// -- slimmed --       e_EMB1.WriteTo( tree );
// -- slimmed --       e_EMB2.WriteTo( tree );
// -- slimmed --       e_EMB3.WriteTo( tree );
// -- slimmed --       e_PreSamplerE.WriteTo( tree );
// -- slimmed --       e_EME1.WriteTo( tree );
// -- slimmed --       e_EME2.WriteTo( tree );
// -- slimmed --       e_EME3.WriteTo( tree );
// -- slimmed --       e_HEC0.WriteTo( tree );
// -- slimmed --       e_HEC1.WriteTo( tree );
// -- slimmed --       e_HEC2.WriteTo( tree );
// -- slimmed --       e_HEC3.WriteTo( tree );
// -- slimmed --       e_TileBar0.WriteTo( tree );
// -- slimmed --       e_TileBar1.WriteTo( tree );
// -- slimmed --       e_TileBar2.WriteTo( tree );
// -- slimmed --       e_TileGap1.WriteTo( tree );
// -- slimmed --       e_TileGap2.WriteTo( tree );
// -- slimmed --       e_TileGap3.WriteTo( tree );
// -- slimmed --       e_TileExt0.WriteTo( tree );
// -- slimmed --       e_TileExt1.WriteTo( tree );
// -- slimmed --       e_TileExt2.WriteTo( tree );
// -- slimmed --       e_FCAL0.WriteTo( tree );
// -- slimmed --       e_FCAL1.WriteTo( tree );
// -- slimmed --       e_FCAL2.WriteTo( tree );
// -- slimmed --       Nconst.WriteTo( tree );
// -- slimmed --       ptconst_default.WriteTo( tree );
// -- slimmed --       econst_default.WriteTo( tree );
// -- slimmed --       etaconst_default.WriteTo( tree );
// -- slimmed --       phiconst_default.WriteTo( tree );
// -- slimmed --       weightconst_default.WriteTo( tree );
      constscale_E.WriteTo( tree );
      constscale_pt.WriteTo( tree );
      constscale_m.WriteTo( tree );
      constscale_eta.WriteTo( tree );
      constscale_phi.WriteTo( tree );
      flavor_weight_Comb.WriteTo( tree );
      flavor_weight_IP2D.WriteTo( tree );
      flavor_weight_IP3D.WriteTo( tree );
      flavor_weight_SV0.WriteTo( tree );
      flavor_weight_SV1.WriteTo( tree );
      flavor_weight_SV2.WriteTo( tree );
      flavor_weight_SoftMuonTagChi2.WriteTo( tree );
      flavor_weight_SecondSoftMuonTagChi2.WriteTo( tree );
      flavor_weight_JetFitterTagNN.WriteTo( tree );
      flavor_weight_JetFitterCOMBNN.WriteTo( tree );
      flavor_weight_MV1.WriteTo( tree );
      flavor_weight_MV2.WriteTo( tree );
      flavor_weight_GbbNN.WriteTo( tree );
if (!is_data) {
      flavor_truth_label.WriteTo( tree );
      flavor_truth_dRminToB.WriteTo( tree );
      flavor_truth_dRminToC.WriteTo( tree );
      flavor_truth_dRminToT.WriteTo( tree );
      flavor_truth_BHadronpdg.WriteTo( tree );
      flavor_truth_vx_x.WriteTo( tree );
      flavor_truth_vx_y.WriteTo( tree );
      flavor_truth_vx_z.WriteTo( tree );
} // end !is_data
// -- slimmed --       flavor_component_ip2d_pu.WriteTo( tree );
// -- slimmed --       flavor_component_ip2d_pb.WriteTo( tree );
// -- slimmed --       flavor_component_ip2d_isValid.WriteTo( tree );
// -- slimmed --       flavor_component_ip2d_ntrk.WriteTo( tree );
// -- slimmed --       flavor_component_ip3d_pu.WriteTo( tree );
// -- slimmed --       flavor_component_ip3d_pb.WriteTo( tree );
// -- slimmed --       flavor_component_ip3d_isValid.WriteTo( tree );
// -- slimmed --       flavor_component_ip3d_ntrk.WriteTo( tree );
// -- slimmed --       flavor_component_sv1_pu.WriteTo( tree );
// -- slimmed --       flavor_component_sv1_pb.WriteTo( tree );
// -- slimmed --       flavor_component_sv1_isValid.WriteTo( tree );
// -- slimmed --       flavor_component_sv2_pu.WriteTo( tree );
// -- slimmed --       flavor_component_sv2_pb.WriteTo( tree );
// -- slimmed --       flavor_component_sv2_isValid.WriteTo( tree );
// -- slimmed --       flavor_component_jfit_pu.WriteTo( tree );
// -- slimmed --       flavor_component_jfit_pb.WriteTo( tree );
// -- slimmed --       flavor_component_jfit_pc.WriteTo( tree );
// -- slimmed --       flavor_component_jfit_isValid.WriteTo( tree );
// -- slimmed --       flavor_component_jfitcomb_pu.WriteTo( tree );
// -- slimmed --       flavor_component_jfitcomb_pb.WriteTo( tree );
// -- slimmed --       flavor_component_jfitcomb_pc.WriteTo( tree );
// -- slimmed --       flavor_component_jfitcomb_isValid.WriteTo( tree );
// -- slimmed --       flavor_component_jfit_nvtx.WriteTo( tree );
// -- slimmed --       flavor_component_jfit_nvtx1t.WriteTo( tree );
// -- slimmed --       flavor_component_jfit_ntrkAtVx.WriteTo( tree );
// -- slimmed --       flavor_component_jfit_efrc.WriteTo( tree );
// -- slimmed --       flavor_component_jfit_mass.WriteTo( tree );
// -- slimmed --       flavor_component_jfit_sig3d.WriteTo( tree );
// -- slimmed --       flavor_component_jfit_deltaPhi.WriteTo( tree );
// -- slimmed --       flavor_component_jfit_deltaEta.WriteTo( tree );
// -- slimmed --       flavor_component_svp_isValid.WriteTo( tree );
// -- slimmed --       flavor_component_svp_ntrkv.WriteTo( tree );
// -- slimmed --       flavor_component_svp_ntrkj.WriteTo( tree );
// -- slimmed --       flavor_component_svp_n2t.WriteTo( tree );
// -- slimmed --       flavor_component_svp_mass.WriteTo( tree );
// -- slimmed --       flavor_component_svp_efrc.WriteTo( tree );
// -- slimmed --       flavor_component_svp_x.WriteTo( tree );
// -- slimmed --       flavor_component_svp_y.WriteTo( tree );
// -- slimmed --       flavor_component_svp_z.WriteTo( tree );
// -- slimmed --       flavor_component_svp_err_x.WriteTo( tree );
// -- slimmed --       flavor_component_svp_err_y.WriteTo( tree );
// -- slimmed --       flavor_component_svp_err_z.WriteTo( tree );
// -- slimmed --       flavor_component_svp_cov_xy.WriteTo( tree );
// -- slimmed --       flavor_component_svp_cov_xz.WriteTo( tree );
// -- slimmed --       flavor_component_svp_cov_yz.WriteTo( tree );
// -- slimmed --       flavor_component_svp_chi2.WriteTo( tree );
// -- slimmed --       flavor_component_svp_ndof.WriteTo( tree );
// -- slimmed --       flavor_component_svp_ntrk.WriteTo( tree );
// -- slimmed --       flavor_component_sv0p_isValid.WriteTo( tree );
// -- slimmed --       flavor_component_sv0p_ntrkv.WriteTo( tree );
// -- slimmed --       flavor_component_sv0p_ntrkj.WriteTo( tree );
// -- slimmed --       flavor_component_sv0p_n2t.WriteTo( tree );
// -- slimmed --       flavor_component_sv0p_mass.WriteTo( tree );
// -- slimmed --       flavor_component_sv0p_efrc.WriteTo( tree );
// -- slimmed --       flavor_component_sv0p_x.WriteTo( tree );
// -- slimmed --       flavor_component_sv0p_y.WriteTo( tree );
// -- slimmed --       flavor_component_sv0p_z.WriteTo( tree );
// -- slimmed --       flavor_component_sv0p_err_x.WriteTo( tree );
// -- slimmed --       flavor_component_sv0p_err_y.WriteTo( tree );
// -- slimmed --       flavor_component_sv0p_err_z.WriteTo( tree );
// -- slimmed --       flavor_component_sv0p_cov_xy.WriteTo( tree );
// -- slimmed --       flavor_component_sv0p_cov_xz.WriteTo( tree );
// -- slimmed --       flavor_component_sv0p_cov_yz.WriteTo( tree );
// -- slimmed --       flavor_component_sv0p_chi2.WriteTo( tree );
// -- slimmed --       flavor_component_sv0p_ndof.WriteTo( tree );
// -- slimmed --       flavor_component_sv0p_ntrk.WriteTo( tree );
// -- slimmed --       flavor_assoctrk_n.WriteTo( tree );
// -- slimmed --       flavor_assoctrk_index.WriteTo( tree );
// -- slimmed --       el_dr.WriteTo( tree );
// -- slimmed --       el_matched.WriteTo( tree );
// -- slimmed --       mu_dr.WriteTo( tree );
// -- slimmed --       mu_matched.WriteTo( tree );
// -- slimmed --       L1_dr.WriteTo( tree );
// -- slimmed --       L1_matched.WriteTo( tree );
// -- slimmed --       L2_dr.WriteTo( tree );
// -- slimmed --       L2_matched.WriteTo( tree );
// -- slimmed --       EF_dr.WriteTo( tree );
// -- slimmed --       EF_matched.WriteTo( tree );
// -- slimmed --       bbDecision.WriteTo( tree );
// -- slimmed --       SmearingFactor.WriteTo( tree );

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
   void JetD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void JetD3PDObject::ReadAllActive() {

      // Check if it makes sense to call this function:
      if( ! fFromInput ) {
         static ::Bool_t wPrinted = kFALSE;
         if( ! wPrinted ) {
            Warning( "ReadAllActive", "Function only meaningful when used on objects" );
            Warning( "ReadAllActive", "which are used to read information from a D3PD" );
            wPrinted = kTRUE;
         }
      }

      if( MET_Egamma10NoTau_wpx.IsActive() ) MET_Egamma10NoTau_wpx();
      if( MET_Egamma10NoTau_wpy.IsActive() ) MET_Egamma10NoTau_wpy();
      if( MET_Egamma10NoTau_wet.IsActive() ) MET_Egamma10NoTau_wet();
      if( MET_Egamma10NoTau_statusWord.IsActive() ) MET_Egamma10NoTau_statusWord();
      if( MET_Egamma10NoTau_STVF_wpx.IsActive() ) MET_Egamma10NoTau_STVF_wpx();
      if( MET_Egamma10NoTau_STVF_wpy.IsActive() ) MET_Egamma10NoTau_STVF_wpy();
      if( MET_Egamma10NoTau_STVF_wet.IsActive() ) MET_Egamma10NoTau_STVF_wet();
      if( MET_Egamma10NoTau_STVF_statusWord.IsActive() ) MET_Egamma10NoTau_STVF_statusWord();
// -- slimmed --       if( MET_LooseEgamma10NoTau_wpx.IsActive() ) MET_LooseEgamma10NoTau_wpx();
// -- slimmed --       if( MET_LooseEgamma10NoTau_wpy.IsActive() ) MET_LooseEgamma10NoTau_wpy();
// -- slimmed --       if( MET_LooseEgamma10NoTau_wet.IsActive() ) MET_LooseEgamma10NoTau_wet();
// -- slimmed --       if( MET_LooseEgamma10NoTau_statusWord.IsActive() ) MET_LooseEgamma10NoTau_statusWord();
// -- slimmed --       if( MET_wpx.IsActive() ) MET_wpx();
// -- slimmed --       if( MET_wpy.IsActive() ) MET_wpy();
// -- slimmed --       if( MET_wet.IsActive() ) MET_wet();
// -- slimmed --       if( MET_statusWord.IsActive() ) MET_statusWord();
// -- slimmed --       if( MET_STVF_wpx.IsActive() ) MET_STVF_wpx();
// -- slimmed --       if( MET_STVF_wpy.IsActive() ) MET_STVF_wpy();
// -- slimmed --       if( MET_STVF_wet.IsActive() ) MET_STVF_wet();
// -- slimmed --       if( MET_STVF_statusWord.IsActive() ) MET_STVF_statusWord();
      if( n.IsActive() ) n();
      if( E.IsActive() ) E();
      if( pt.IsActive() ) pt();
      if( m.IsActive() ) m();
      if( eta.IsActive() ) eta();
      if( phi.IsActive() ) phi();
      if( EtaOrigin.IsActive() ) EtaOrigin();
      if( PhiOrigin.IsActive() ) PhiOrigin();
      if( MOrigin.IsActive() ) MOrigin();
      if( EtaOriginEM.IsActive() ) EtaOriginEM();
      if( PhiOriginEM.IsActive() ) PhiOriginEM();
      if( MOriginEM.IsActive() ) MOriginEM();
// -- slimmed --       if( WIDTH.IsActive() ) WIDTH();
// -- slimmed --       if( n90.IsActive() ) n90();
// -- slimmed --       if( Timing.IsActive() ) Timing();
      if( LArQuality.IsActive() ) LArQuality();
      if( nTrk.IsActive() ) nTrk();
      if( sumPtTrk.IsActive() ) sumPtTrk();
      if( OriginIndex.IsActive() ) OriginIndex();
      if( HECQuality.IsActive() ) HECQuality();
      if( NegativeE.IsActive() ) NegativeE();
      if( AverageLArQF.IsActive() ) AverageLArQF();
// -- slimmed --       if( YFlip12.IsActive() ) YFlip12();
// -- slimmed --       if( YFlip23.IsActive() ) YFlip23();
// -- slimmed --       if( BCH_CORR_CELL.IsActive() ) BCH_CORR_CELL();
// -- slimmed --       if( BCH_CORR_DOTX.IsActive() ) BCH_CORR_DOTX();
// -- slimmed --       if( BCH_CORR_JET.IsActive() ) BCH_CORR_JET();
// -- slimmed --       if( BCH_CORR_JET_FORCELL.IsActive() ) BCH_CORR_JET_FORCELL();
      if( ENG_BAD_CELLS.IsActive() ) ENG_BAD_CELLS();
      if( N_BAD_CELLS.IsActive() ) N_BAD_CELLS();
      if( N_BAD_CELLS_CORR.IsActive() ) N_BAD_CELLS_CORR();
      if( BAD_CELLS_CORR_E.IsActive() ) BAD_CELLS_CORR_E();
// -- slimmed --       if( NumTowers.IsActive() ) NumTowers();
// -- slimmed --       if( ootFracCells5.IsActive() ) ootFracCells5();
// -- slimmed --       if( ootFracCells10.IsActive() ) ootFracCells10();
// -- slimmed --       if( ootFracClusters5.IsActive() ) ootFracClusters5();
// -- slimmed --       if( ootFracClusters10.IsActive() ) ootFracClusters10();
      if( SamplingMax.IsActive() ) SamplingMax();
      if( fracSamplingMax.IsActive() ) fracSamplingMax();
      if( hecf.IsActive() ) hecf();
// -- slimmed --       if( tgap3f.IsActive() ) tgap3f();
// -- slimmed --       if( isUgly.IsActive() ) isUgly();
// -- slimmed --       if( isBadLooseMinus.IsActive() ) isBadLooseMinus();
// -- slimmed --       if( isBadLoose.IsActive() ) isBadLoose();
// -- slimmed --       if( isBadMedium.IsActive() ) isBadMedium();
// -- slimmed --       if( isBadTight.IsActive() ) isBadTight();
      if( emfrac.IsActive() ) emfrac();
      if( Offset.IsActive() ) Offset();
      if( EMJES.IsActive() ) EMJES();
      if( EMJES_EtaCorr.IsActive() ) EMJES_EtaCorr();
      if( EMJESnooffset.IsActive() ) EMJESnooffset();
      if( GCWJES.IsActive() ) GCWJES();
      if( GCWJES_EtaCorr.IsActive() ) GCWJES_EtaCorr();
      if( CB.IsActive() ) CB();
      if( LCJES.IsActive() ) LCJES();
      if( emscale_E.IsActive() ) emscale_E();
      if( emscale_pt.IsActive() ) emscale_pt();
      if( emscale_m.IsActive() ) emscale_m();
      if( emscale_eta.IsActive() ) emscale_eta();
      if( emscale_phi.IsActive() ) emscale_phi();
      if( jvtx_x.IsActive() ) jvtx_x();
      if( jvtx_y.IsActive() ) jvtx_y();
      if( jvtx_z.IsActive() ) jvtx_z();
      if( jvtxf.IsActive() ) jvtxf();
      if( jvtxfFull.IsActive() ) jvtxfFull();
      if( GSCFactorF.IsActive() ) GSCFactorF();
      if( WidthFraction.IsActive() ) WidthFraction();
      if( e_PreSamplerB.IsActive() ) e_PreSamplerB();
// -- slimmed --       if( e_EMB1.IsActive() ) e_EMB1();
// -- slimmed --       if( e_EMB2.IsActive() ) e_EMB2();
// -- slimmed --       if( e_EMB3.IsActive() ) e_EMB3();
// -- slimmed --       if( e_PreSamplerE.IsActive() ) e_PreSamplerE();
// -- slimmed --       if( e_EME1.IsActive() ) e_EME1();
// -- slimmed --       if( e_EME2.IsActive() ) e_EME2();
// -- slimmed --       if( e_EME3.IsActive() ) e_EME3();
// -- slimmed --       if( e_HEC0.IsActive() ) e_HEC0();
// -- slimmed --       if( e_HEC1.IsActive() ) e_HEC1();
// -- slimmed --       if( e_HEC2.IsActive() ) e_HEC2();
// -- slimmed --       if( e_HEC3.IsActive() ) e_HEC3();
// -- slimmed --       if( e_TileBar0.IsActive() ) e_TileBar0();
// -- slimmed --       if( e_TileBar1.IsActive() ) e_TileBar1();
// -- slimmed --       if( e_TileBar2.IsActive() ) e_TileBar2();
// -- slimmed --       if( e_TileGap1.IsActive() ) e_TileGap1();
// -- slimmed --       if( e_TileGap2.IsActive() ) e_TileGap2();
// -- slimmed --       if( e_TileGap3.IsActive() ) e_TileGap3();
// -- slimmed --       if( e_TileExt0.IsActive() ) e_TileExt0();
// -- slimmed --       if( e_TileExt1.IsActive() ) e_TileExt1();
// -- slimmed --       if( e_TileExt2.IsActive() ) e_TileExt2();
// -- slimmed --       if( e_FCAL0.IsActive() ) e_FCAL0();
// -- slimmed --       if( e_FCAL1.IsActive() ) e_FCAL1();
// -- slimmed --       if( e_FCAL2.IsActive() ) e_FCAL2();
// -- slimmed --       if( Nconst.IsActive() ) Nconst();
// -- slimmed --       if( ptconst_default.IsActive() ) ptconst_default();
// -- slimmed --       if( econst_default.IsActive() ) econst_default();
// -- slimmed --       if( etaconst_default.IsActive() ) etaconst_default();
// -- slimmed --       if( phiconst_default.IsActive() ) phiconst_default();
// -- slimmed --       if( weightconst_default.IsActive() ) weightconst_default();
      if( constscale_E.IsActive() ) constscale_E();
      if( constscale_pt.IsActive() ) constscale_pt();
      if( constscale_m.IsActive() ) constscale_m();
      if( constscale_eta.IsActive() ) constscale_eta();
      if( constscale_phi.IsActive() ) constscale_phi();
      if( flavor_weight_Comb.IsActive() ) flavor_weight_Comb();
      if( flavor_weight_IP2D.IsActive() ) flavor_weight_IP2D();
      if( flavor_weight_IP3D.IsActive() ) flavor_weight_IP3D();
      if( flavor_weight_SV0.IsActive() ) flavor_weight_SV0();
      if( flavor_weight_SV1.IsActive() ) flavor_weight_SV1();
      if( flavor_weight_SV2.IsActive() ) flavor_weight_SV2();
      if( flavor_weight_SoftMuonTagChi2.IsActive() ) flavor_weight_SoftMuonTagChi2();
      if( flavor_weight_SecondSoftMuonTagChi2.IsActive() ) flavor_weight_SecondSoftMuonTagChi2();
      if( flavor_weight_JetFitterTagNN.IsActive() ) flavor_weight_JetFitterTagNN();
      if( flavor_weight_JetFitterCOMBNN.IsActive() ) flavor_weight_JetFitterCOMBNN();
      if( flavor_weight_MV1.IsActive() ) flavor_weight_MV1();
      if( flavor_weight_MV2.IsActive() ) flavor_weight_MV2();
      if( flavor_weight_GbbNN.IsActive() ) flavor_weight_GbbNN();
if (!is_data) {
      if( flavor_truth_label.IsActive() ) flavor_truth_label();
      if( flavor_truth_dRminToB.IsActive() ) flavor_truth_dRminToB();
      if( flavor_truth_dRminToC.IsActive() ) flavor_truth_dRminToC();
      if( flavor_truth_dRminToT.IsActive() ) flavor_truth_dRminToT();
      if( flavor_truth_BHadronpdg.IsActive() ) flavor_truth_BHadronpdg();
      if( flavor_truth_vx_x.IsActive() ) flavor_truth_vx_x();
      if( flavor_truth_vx_y.IsActive() ) flavor_truth_vx_y();
      if( flavor_truth_vx_z.IsActive() ) flavor_truth_vx_z();
} // end !is_data
// -- slimmed --       if( flavor_component_ip2d_pu.IsActive() ) flavor_component_ip2d_pu();
// -- slimmed --       if( flavor_component_ip2d_pb.IsActive() ) flavor_component_ip2d_pb();
// -- slimmed --       if( flavor_component_ip2d_isValid.IsActive() ) flavor_component_ip2d_isValid();
// -- slimmed --       if( flavor_component_ip2d_ntrk.IsActive() ) flavor_component_ip2d_ntrk();
// -- slimmed --       if( flavor_component_ip3d_pu.IsActive() ) flavor_component_ip3d_pu();
// -- slimmed --       if( flavor_component_ip3d_pb.IsActive() ) flavor_component_ip3d_pb();
// -- slimmed --       if( flavor_component_ip3d_isValid.IsActive() ) flavor_component_ip3d_isValid();
// -- slimmed --       if( flavor_component_ip3d_ntrk.IsActive() ) flavor_component_ip3d_ntrk();
// -- slimmed --       if( flavor_component_sv1_pu.IsActive() ) flavor_component_sv1_pu();
// -- slimmed --       if( flavor_component_sv1_pb.IsActive() ) flavor_component_sv1_pb();
// -- slimmed --       if( flavor_component_sv1_isValid.IsActive() ) flavor_component_sv1_isValid();
// -- slimmed --       if( flavor_component_sv2_pu.IsActive() ) flavor_component_sv2_pu();
// -- slimmed --       if( flavor_component_sv2_pb.IsActive() ) flavor_component_sv2_pb();
// -- slimmed --       if( flavor_component_sv2_isValid.IsActive() ) flavor_component_sv2_isValid();
// -- slimmed --       if( flavor_component_jfit_pu.IsActive() ) flavor_component_jfit_pu();
// -- slimmed --       if( flavor_component_jfit_pb.IsActive() ) flavor_component_jfit_pb();
// -- slimmed --       if( flavor_component_jfit_pc.IsActive() ) flavor_component_jfit_pc();
// -- slimmed --       if( flavor_component_jfit_isValid.IsActive() ) flavor_component_jfit_isValid();
// -- slimmed --       if( flavor_component_jfitcomb_pu.IsActive() ) flavor_component_jfitcomb_pu();
// -- slimmed --       if( flavor_component_jfitcomb_pb.IsActive() ) flavor_component_jfitcomb_pb();
// -- slimmed --       if( flavor_component_jfitcomb_pc.IsActive() ) flavor_component_jfitcomb_pc();
// -- slimmed --       if( flavor_component_jfitcomb_isValid.IsActive() ) flavor_component_jfitcomb_isValid();
// -- slimmed --       if( flavor_component_jfit_nvtx.IsActive() ) flavor_component_jfit_nvtx();
// -- slimmed --       if( flavor_component_jfit_nvtx1t.IsActive() ) flavor_component_jfit_nvtx1t();
// -- slimmed --       if( flavor_component_jfit_ntrkAtVx.IsActive() ) flavor_component_jfit_ntrkAtVx();
// -- slimmed --       if( flavor_component_jfit_efrc.IsActive() ) flavor_component_jfit_efrc();
// -- slimmed --       if( flavor_component_jfit_mass.IsActive() ) flavor_component_jfit_mass();
// -- slimmed --       if( flavor_component_jfit_sig3d.IsActive() ) flavor_component_jfit_sig3d();
// -- slimmed --       if( flavor_component_jfit_deltaPhi.IsActive() ) flavor_component_jfit_deltaPhi();
// -- slimmed --       if( flavor_component_jfit_deltaEta.IsActive() ) flavor_component_jfit_deltaEta();
// -- slimmed --       if( flavor_component_svp_isValid.IsActive() ) flavor_component_svp_isValid();
// -- slimmed --       if( flavor_component_svp_ntrkv.IsActive() ) flavor_component_svp_ntrkv();
// -- slimmed --       if( flavor_component_svp_ntrkj.IsActive() ) flavor_component_svp_ntrkj();
// -- slimmed --       if( flavor_component_svp_n2t.IsActive() ) flavor_component_svp_n2t();
// -- slimmed --       if( flavor_component_svp_mass.IsActive() ) flavor_component_svp_mass();
// -- slimmed --       if( flavor_component_svp_efrc.IsActive() ) flavor_component_svp_efrc();
// -- slimmed --       if( flavor_component_svp_x.IsActive() ) flavor_component_svp_x();
// -- slimmed --       if( flavor_component_svp_y.IsActive() ) flavor_component_svp_y();
// -- slimmed --       if( flavor_component_svp_z.IsActive() ) flavor_component_svp_z();
// -- slimmed --       if( flavor_component_svp_err_x.IsActive() ) flavor_component_svp_err_x();
// -- slimmed --       if( flavor_component_svp_err_y.IsActive() ) flavor_component_svp_err_y();
// -- slimmed --       if( flavor_component_svp_err_z.IsActive() ) flavor_component_svp_err_z();
// -- slimmed --       if( flavor_component_svp_cov_xy.IsActive() ) flavor_component_svp_cov_xy();
// -- slimmed --       if( flavor_component_svp_cov_xz.IsActive() ) flavor_component_svp_cov_xz();
// -- slimmed --       if( flavor_component_svp_cov_yz.IsActive() ) flavor_component_svp_cov_yz();
// -- slimmed --       if( flavor_component_svp_chi2.IsActive() ) flavor_component_svp_chi2();
// -- slimmed --       if( flavor_component_svp_ndof.IsActive() ) flavor_component_svp_ndof();
// -- slimmed --       if( flavor_component_svp_ntrk.IsActive() ) flavor_component_svp_ntrk();
// -- slimmed --       if( flavor_component_sv0p_isValid.IsActive() ) flavor_component_sv0p_isValid();
// -- slimmed --       if( flavor_component_sv0p_ntrkv.IsActive() ) flavor_component_sv0p_ntrkv();
// -- slimmed --       if( flavor_component_sv0p_ntrkj.IsActive() ) flavor_component_sv0p_ntrkj();
// -- slimmed --       if( flavor_component_sv0p_n2t.IsActive() ) flavor_component_sv0p_n2t();
// -- slimmed --       if( flavor_component_sv0p_mass.IsActive() ) flavor_component_sv0p_mass();
// -- slimmed --       if( flavor_component_sv0p_efrc.IsActive() ) flavor_component_sv0p_efrc();
// -- slimmed --       if( flavor_component_sv0p_x.IsActive() ) flavor_component_sv0p_x();
// -- slimmed --       if( flavor_component_sv0p_y.IsActive() ) flavor_component_sv0p_y();
// -- slimmed --       if( flavor_component_sv0p_z.IsActive() ) flavor_component_sv0p_z();
// -- slimmed --       if( flavor_component_sv0p_err_x.IsActive() ) flavor_component_sv0p_err_x();
// -- slimmed --       if( flavor_component_sv0p_err_y.IsActive() ) flavor_component_sv0p_err_y();
// -- slimmed --       if( flavor_component_sv0p_err_z.IsActive() ) flavor_component_sv0p_err_z();
// -- slimmed --       if( flavor_component_sv0p_cov_xy.IsActive() ) flavor_component_sv0p_cov_xy();
// -- slimmed --       if( flavor_component_sv0p_cov_xz.IsActive() ) flavor_component_sv0p_cov_xz();
// -- slimmed --       if( flavor_component_sv0p_cov_yz.IsActive() ) flavor_component_sv0p_cov_yz();
// -- slimmed --       if( flavor_component_sv0p_chi2.IsActive() ) flavor_component_sv0p_chi2();
// -- slimmed --       if( flavor_component_sv0p_ndof.IsActive() ) flavor_component_sv0p_ndof();
// -- slimmed --       if( flavor_component_sv0p_ntrk.IsActive() ) flavor_component_sv0p_ntrk();
// -- slimmed --       if( flavor_assoctrk_n.IsActive() ) flavor_assoctrk_n();
// -- slimmed --       if( flavor_assoctrk_index.IsActive() ) flavor_assoctrk_index();
// -- slimmed --       if( el_dr.IsActive() ) el_dr();
// -- slimmed --       if( el_matched.IsActive() ) el_matched();
// -- slimmed --       if( mu_dr.IsActive() ) mu_dr();
// -- slimmed --       if( mu_matched.IsActive() ) mu_matched();
// -- slimmed --       if( L1_dr.IsActive() ) L1_dr();
// -- slimmed --       if( L1_matched.IsActive() ) L1_matched();
// -- slimmed --       if( L2_dr.IsActive() ) L2_dr();
// -- slimmed --       if( L2_matched.IsActive() ) L2_matched();
// -- slimmed --       if( EF_dr.IsActive() ) EF_dr();
// -- slimmed --       if( EF_matched.IsActive() ) EF_matched();
// -- slimmed --       if( bbDecision.IsActive() ) bbDecision();
// -- slimmed --       if( SmearingFactor.IsActive() ) SmearingFactor();

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
   void JetD3PDObject::Clear( Option_t* ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Clear", "Objects used for reading a D3PD can't be cleared!" );
         return;
      }

      MET_Egamma10NoTau_wpx()->clear();
      MET_Egamma10NoTau_wpy()->clear();
      MET_Egamma10NoTau_wet()->clear();
      MET_Egamma10NoTau_statusWord()->clear();
      MET_Egamma10NoTau_STVF_wpx()->clear();
      MET_Egamma10NoTau_STVF_wpy()->clear();
      MET_Egamma10NoTau_STVF_wet()->clear();
      MET_Egamma10NoTau_STVF_statusWord()->clear();
// -- slimmed --       MET_LooseEgamma10NoTau_wpx()->clear();
// -- slimmed --       MET_LooseEgamma10NoTau_wpy()->clear();
// -- slimmed --       MET_LooseEgamma10NoTau_wet()->clear();
// -- slimmed --       MET_LooseEgamma10NoTau_statusWord()->clear();
// -- slimmed --       MET_wpx()->clear();
// -- slimmed --       MET_wpy()->clear();
// -- slimmed --       MET_wet()->clear();
// -- slimmed --       MET_statusWord()->clear();
// -- slimmed --       MET_STVF_wpx()->clear();
// -- slimmed --       MET_STVF_wpy()->clear();
// -- slimmed --       MET_STVF_wet()->clear();
// -- slimmed --       MET_STVF_statusWord()->clear();
      n() = 0;
      E()->clear();
      pt()->clear();
      m()->clear();
      eta()->clear();
      phi()->clear();
      EtaOrigin()->clear();
      PhiOrigin()->clear();
      MOrigin()->clear();
      EtaOriginEM()->clear();
      PhiOriginEM()->clear();
      MOriginEM()->clear();
// -- slimmed --       WIDTH()->clear();
// -- slimmed --       n90()->clear();
// -- slimmed --       Timing()->clear();
      LArQuality()->clear();
      nTrk()->clear();
      sumPtTrk()->clear();
      OriginIndex()->clear();
      HECQuality()->clear();
      NegativeE()->clear();
      AverageLArQF()->clear();
// -- slimmed --       YFlip12()->clear();
// -- slimmed --       YFlip23()->clear();
// -- slimmed --       BCH_CORR_CELL()->clear();
// -- slimmed --       BCH_CORR_DOTX()->clear();
// -- slimmed --       BCH_CORR_JET()->clear();
// -- slimmed --       BCH_CORR_JET_FORCELL()->clear();
      ENG_BAD_CELLS()->clear();
      N_BAD_CELLS()->clear();
      N_BAD_CELLS_CORR()->clear();
      BAD_CELLS_CORR_E()->clear();
// -- slimmed --       NumTowers()->clear();
// -- slimmed --       ootFracCells5()->clear();
// -- slimmed --       ootFracCells10()->clear();
// -- slimmed --       ootFracClusters5()->clear();
// -- slimmed --       ootFracClusters10()->clear();
      SamplingMax()->clear();
      fracSamplingMax()->clear();
      hecf()->clear();
// -- slimmed --       tgap3f()->clear();
// -- slimmed --       isUgly()->clear();
// -- slimmed --       isBadLooseMinus()->clear();
// -- slimmed --       isBadLoose()->clear();
// -- slimmed --       isBadMedium()->clear();
// -- slimmed --       isBadTight()->clear();
      emfrac()->clear();
      Offset()->clear();
      EMJES()->clear();
      EMJES_EtaCorr()->clear();
      EMJESnooffset()->clear();
      GCWJES()->clear();
      GCWJES_EtaCorr()->clear();
      CB()->clear();
      LCJES()->clear();
      emscale_E()->clear();
      emscale_pt()->clear();
      emscale_m()->clear();
      emscale_eta()->clear();
      emscale_phi()->clear();
      jvtx_x()->clear();
      jvtx_y()->clear();
      jvtx_z()->clear();
      jvtxf()->clear();
      jvtxfFull()->clear();
      GSCFactorF()->clear();
      WidthFraction()->clear();
      e_PreSamplerB()->clear();
// -- slimmed --       e_EMB1()->clear();
// -- slimmed --       e_EMB2()->clear();
// -- slimmed --       e_EMB3()->clear();
// -- slimmed --       e_PreSamplerE()->clear();
// -- slimmed --       e_EME1()->clear();
// -- slimmed --       e_EME2()->clear();
// -- slimmed --       e_EME3()->clear();
// -- slimmed --       e_HEC0()->clear();
// -- slimmed --       e_HEC1()->clear();
// -- slimmed --       e_HEC2()->clear();
// -- slimmed --       e_HEC3()->clear();
// -- slimmed --       e_TileBar0()->clear();
// -- slimmed --       e_TileBar1()->clear();
// -- slimmed --       e_TileBar2()->clear();
// -- slimmed --       e_TileGap1()->clear();
// -- slimmed --       e_TileGap2()->clear();
// -- slimmed --       e_TileGap3()->clear();
// -- slimmed --       e_TileExt0()->clear();
// -- slimmed --       e_TileExt1()->clear();
// -- slimmed --       e_TileExt2()->clear();
// -- slimmed --       e_FCAL0()->clear();
// -- slimmed --       e_FCAL1()->clear();
// -- slimmed --       e_FCAL2()->clear();
// -- slimmed --       Nconst()->clear();
// -- slimmed --       ptconst_default()->clear();
// -- slimmed --       econst_default()->clear();
// -- slimmed --       etaconst_default()->clear();
// -- slimmed --       phiconst_default()->clear();
// -- slimmed --       weightconst_default()->clear();
      constscale_E()->clear();
      constscale_pt()->clear();
      constscale_m()->clear();
      constscale_eta()->clear();
      constscale_phi()->clear();
      flavor_weight_Comb()->clear();
      flavor_weight_IP2D()->clear();
      flavor_weight_IP3D()->clear();
      flavor_weight_SV0()->clear();
      flavor_weight_SV1()->clear();
      flavor_weight_SV2()->clear();
      flavor_weight_SoftMuonTagChi2()->clear();
      flavor_weight_SecondSoftMuonTagChi2()->clear();
      flavor_weight_JetFitterTagNN()->clear();
      flavor_weight_JetFitterCOMBNN()->clear();
      flavor_weight_MV1()->clear();
      flavor_weight_MV2()->clear();
      flavor_weight_GbbNN()->clear();
if (!is_data) {
      flavor_truth_label()->clear();
      flavor_truth_dRminToB()->clear();
      flavor_truth_dRminToC()->clear();
      flavor_truth_dRminToT()->clear();
      flavor_truth_BHadronpdg()->clear();
      flavor_truth_vx_x()->clear();
      flavor_truth_vx_y()->clear();
      flavor_truth_vx_z()->clear();
} // end !is_data
// -- slimmed --       flavor_component_ip2d_pu()->clear();
// -- slimmed --       flavor_component_ip2d_pb()->clear();
// -- slimmed --       flavor_component_ip2d_isValid()->clear();
// -- slimmed --       flavor_component_ip2d_ntrk()->clear();
// -- slimmed --       flavor_component_ip3d_pu()->clear();
// -- slimmed --       flavor_component_ip3d_pb()->clear();
// -- slimmed --       flavor_component_ip3d_isValid()->clear();
// -- slimmed --       flavor_component_ip3d_ntrk()->clear();
// -- slimmed --       flavor_component_sv1_pu()->clear();
// -- slimmed --       flavor_component_sv1_pb()->clear();
// -- slimmed --       flavor_component_sv1_isValid()->clear();
// -- slimmed --       flavor_component_sv2_pu()->clear();
// -- slimmed --       flavor_component_sv2_pb()->clear();
// -- slimmed --       flavor_component_sv2_isValid()->clear();
// -- slimmed --       flavor_component_jfit_pu()->clear();
// -- slimmed --       flavor_component_jfit_pb()->clear();
// -- slimmed --       flavor_component_jfit_pc()->clear();
// -- slimmed --       flavor_component_jfit_isValid()->clear();
// -- slimmed --       flavor_component_jfitcomb_pu()->clear();
// -- slimmed --       flavor_component_jfitcomb_pb()->clear();
// -- slimmed --       flavor_component_jfitcomb_pc()->clear();
// -- slimmed --       flavor_component_jfitcomb_isValid()->clear();
// -- slimmed --       flavor_component_jfit_nvtx()->clear();
// -- slimmed --       flavor_component_jfit_nvtx1t()->clear();
// -- slimmed --       flavor_component_jfit_ntrkAtVx()->clear();
// -- slimmed --       flavor_component_jfit_efrc()->clear();
// -- slimmed --       flavor_component_jfit_mass()->clear();
// -- slimmed --       flavor_component_jfit_sig3d()->clear();
// -- slimmed --       flavor_component_jfit_deltaPhi()->clear();
// -- slimmed --       flavor_component_jfit_deltaEta()->clear();
// -- slimmed --       flavor_component_svp_isValid()->clear();
// -- slimmed --       flavor_component_svp_ntrkv()->clear();
// -- slimmed --       flavor_component_svp_ntrkj()->clear();
// -- slimmed --       flavor_component_svp_n2t()->clear();
// -- slimmed --       flavor_component_svp_mass()->clear();
// -- slimmed --       flavor_component_svp_efrc()->clear();
// -- slimmed --       flavor_component_svp_x()->clear();
// -- slimmed --       flavor_component_svp_y()->clear();
// -- slimmed --       flavor_component_svp_z()->clear();
// -- slimmed --       flavor_component_svp_err_x()->clear();
// -- slimmed --       flavor_component_svp_err_y()->clear();
// -- slimmed --       flavor_component_svp_err_z()->clear();
// -- slimmed --       flavor_component_svp_cov_xy()->clear();
// -- slimmed --       flavor_component_svp_cov_xz()->clear();
// -- slimmed --       flavor_component_svp_cov_yz()->clear();
// -- slimmed --       flavor_component_svp_chi2()->clear();
// -- slimmed --       flavor_component_svp_ndof()->clear();
// -- slimmed --       flavor_component_svp_ntrk()->clear();
// -- slimmed --       flavor_component_sv0p_isValid()->clear();
// -- slimmed --       flavor_component_sv0p_ntrkv()->clear();
// -- slimmed --       flavor_component_sv0p_ntrkj()->clear();
// -- slimmed --       flavor_component_sv0p_n2t()->clear();
// -- slimmed --       flavor_component_sv0p_mass()->clear();
// -- slimmed --       flavor_component_sv0p_efrc()->clear();
// -- slimmed --       flavor_component_sv0p_x()->clear();
// -- slimmed --       flavor_component_sv0p_y()->clear();
// -- slimmed --       flavor_component_sv0p_z()->clear();
// -- slimmed --       flavor_component_sv0p_err_x()->clear();
// -- slimmed --       flavor_component_sv0p_err_y()->clear();
// -- slimmed --       flavor_component_sv0p_err_z()->clear();
// -- slimmed --       flavor_component_sv0p_cov_xy()->clear();
// -- slimmed --       flavor_component_sv0p_cov_xz()->clear();
// -- slimmed --       flavor_component_sv0p_cov_yz()->clear();
// -- slimmed --       flavor_component_sv0p_chi2()->clear();
// -- slimmed --       flavor_component_sv0p_ndof()->clear();
// -- slimmed --       flavor_component_sv0p_ntrk()->clear();
// -- slimmed --       flavor_assoctrk_n()->clear();
// -- slimmed --       flavor_assoctrk_index()->clear();
// -- slimmed --       el_dr()->clear();
// -- slimmed --       el_matched()->clear();
// -- slimmed --       mu_dr()->clear();
// -- slimmed --       mu_matched()->clear();
// -- slimmed --       L1_dr()->clear();
// -- slimmed --       L1_matched()->clear();
// -- slimmed --       L2_dr()->clear();
// -- slimmed --       L2_matched()->clear();
// -- slimmed --       EF_dr()->clear();
// -- slimmed --       EF_matched()->clear();
// -- slimmed --       bbDecision()->clear();
// -- slimmed --       SmearingFactor()->clear();

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
   JetD3PDObject& JetD3PDObject::Add( const JetD3PDObjectElement& el ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Add", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      if( el.MET_Egamma10NoTau_wpx.IsAvailable() ) {
         MET_Egamma10NoTau_wpx()->push_back( el.MET_Egamma10NoTau_wpx() );
      } else {
         MET_Egamma10NoTau_wpx()->push_back( vector<float>() );
      }
      if( el.MET_Egamma10NoTau_wpy.IsAvailable() ) {
         MET_Egamma10NoTau_wpy()->push_back( el.MET_Egamma10NoTau_wpy() );
      } else {
         MET_Egamma10NoTau_wpy()->push_back( vector<float>() );
      }
      if( el.MET_Egamma10NoTau_wet.IsAvailable() ) {
         MET_Egamma10NoTau_wet()->push_back( el.MET_Egamma10NoTau_wet() );
      } else {
         MET_Egamma10NoTau_wet()->push_back( vector<float>() );
      }
      if( el.MET_Egamma10NoTau_statusWord.IsAvailable() ) {
         MET_Egamma10NoTau_statusWord()->push_back( el.MET_Egamma10NoTau_statusWord() );
      } else {
         MET_Egamma10NoTau_statusWord()->push_back( vector<unsigned int>() );
      }
      if( el.MET_Egamma10NoTau_STVF_wpx.IsAvailable() ) {
         MET_Egamma10NoTau_STVF_wpx()->push_back( el.MET_Egamma10NoTau_STVF_wpx() );
      } else {
         MET_Egamma10NoTau_STVF_wpx()->push_back( vector<float>() );
      }
      if( el.MET_Egamma10NoTau_STVF_wpy.IsAvailable() ) {
         MET_Egamma10NoTau_STVF_wpy()->push_back( el.MET_Egamma10NoTau_STVF_wpy() );
      } else {
         MET_Egamma10NoTau_STVF_wpy()->push_back( vector<float>() );
      }
      if( el.MET_Egamma10NoTau_STVF_wet.IsAvailable() ) {
         MET_Egamma10NoTau_STVF_wet()->push_back( el.MET_Egamma10NoTau_STVF_wet() );
      } else {
         MET_Egamma10NoTau_STVF_wet()->push_back( vector<float>() );
      }
      if( el.MET_Egamma10NoTau_STVF_statusWord.IsAvailable() ) {
         MET_Egamma10NoTau_STVF_statusWord()->push_back( el.MET_Egamma10NoTau_STVF_statusWord() );
      } else {
         MET_Egamma10NoTau_STVF_statusWord()->push_back( vector<unsigned int>() );
      }
// -- slimmed --       if( el.MET_LooseEgamma10NoTau_wpx.IsAvailable() ) {
// -- slimmed --          MET_LooseEgamma10NoTau_wpx()->push_back( el.MET_LooseEgamma10NoTau_wpx() );
// -- slimmed --       } else {
// -- slimmed --          MET_LooseEgamma10NoTau_wpx()->push_back( vector<float>() );
// -- slimmed --       }
// -- slimmed --       if( el.MET_LooseEgamma10NoTau_wpy.IsAvailable() ) {
// -- slimmed --          MET_LooseEgamma10NoTau_wpy()->push_back( el.MET_LooseEgamma10NoTau_wpy() );
// -- slimmed --       } else {
// -- slimmed --          MET_LooseEgamma10NoTau_wpy()->push_back( vector<float>() );
// -- slimmed --       }
// -- slimmed --       if( el.MET_LooseEgamma10NoTau_wet.IsAvailable() ) {
// -- slimmed --          MET_LooseEgamma10NoTau_wet()->push_back( el.MET_LooseEgamma10NoTau_wet() );
// -- slimmed --       } else {
// -- slimmed --          MET_LooseEgamma10NoTau_wet()->push_back( vector<float>() );
// -- slimmed --       }
// -- slimmed --       if( el.MET_LooseEgamma10NoTau_statusWord.IsAvailable() ) {
// -- slimmed --          MET_LooseEgamma10NoTau_statusWord()->push_back( el.MET_LooseEgamma10NoTau_statusWord() );
// -- slimmed --       } else {
// -- slimmed --          MET_LooseEgamma10NoTau_statusWord()->push_back( vector<unsigned int>() );
// -- slimmed --       }
// -- slimmed --       if( el.MET_wpx.IsAvailable() ) {
// -- slimmed --          MET_wpx()->push_back( el.MET_wpx() );
// -- slimmed --       } else {
// -- slimmed --          MET_wpx()->push_back( vector<float>() );
// -- slimmed --       }
// -- slimmed --       if( el.MET_wpy.IsAvailable() ) {
// -- slimmed --          MET_wpy()->push_back( el.MET_wpy() );
// -- slimmed --       } else {
// -- slimmed --          MET_wpy()->push_back( vector<float>() );
// -- slimmed --       }
// -- slimmed --       if( el.MET_wet.IsAvailable() ) {
// -- slimmed --          MET_wet()->push_back( el.MET_wet() );
// -- slimmed --       } else {
// -- slimmed --          MET_wet()->push_back( vector<float>() );
// -- slimmed --       }
// -- slimmed --       if( el.MET_statusWord.IsAvailable() ) {
// -- slimmed --          MET_statusWord()->push_back( el.MET_statusWord() );
// -- slimmed --       } else {
// -- slimmed --          MET_statusWord()->push_back( vector<unsigned int>() );
// -- slimmed --       }
// -- slimmed --       if( el.MET_STVF_wpx.IsAvailable() ) {
// -- slimmed --          MET_STVF_wpx()->push_back( el.MET_STVF_wpx() );
// -- slimmed --       } else {
// -- slimmed --          MET_STVF_wpx()->push_back( vector<float>() );
// -- slimmed --       }
// -- slimmed --       if( el.MET_STVF_wpy.IsAvailable() ) {
// -- slimmed --          MET_STVF_wpy()->push_back( el.MET_STVF_wpy() );
// -- slimmed --       } else {
// -- slimmed --          MET_STVF_wpy()->push_back( vector<float>() );
// -- slimmed --       }
// -- slimmed --       if( el.MET_STVF_wet.IsAvailable() ) {
// -- slimmed --          MET_STVF_wet()->push_back( el.MET_STVF_wet() );
// -- slimmed --       } else {
// -- slimmed --          MET_STVF_wet()->push_back( vector<float>() );
// -- slimmed --       }
// -- slimmed --       if( el.MET_STVF_statusWord.IsAvailable() ) {
// -- slimmed --          MET_STVF_statusWord()->push_back( el.MET_STVF_statusWord() );
// -- slimmed --       } else {
// -- slimmed --          MET_STVF_statusWord()->push_back( vector<unsigned int>() );
// -- slimmed --       }
      ++( n() );
      if( el.E.IsAvailable() ) {
         E()->push_back( el.E() );
      } else {
         E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pt.IsAvailable() ) {
         pt()->push_back( el.pt() );
      } else {
         pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.m.IsAvailable() ) {
         m()->push_back( el.m() );
      } else {
         m()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.eta.IsAvailable() ) {
         eta()->push_back( el.eta() );
      } else {
         eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.phi.IsAvailable() ) {
         phi()->push_back( el.phi() );
      } else {
         phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EtaOrigin.IsAvailable() ) {
         EtaOrigin()->push_back( el.EtaOrigin() );
      } else {
         EtaOrigin()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.PhiOrigin.IsAvailable() ) {
         PhiOrigin()->push_back( el.PhiOrigin() );
      } else {
         PhiOrigin()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.MOrigin.IsAvailable() ) {
         MOrigin()->push_back( el.MOrigin() );
      } else {
         MOrigin()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EtaOriginEM.IsAvailable() ) {
         EtaOriginEM()->push_back( el.EtaOriginEM() );
      } else {
         EtaOriginEM()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.PhiOriginEM.IsAvailable() ) {
         PhiOriginEM()->push_back( el.PhiOriginEM() );
      } else {
         PhiOriginEM()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.MOriginEM.IsAvailable() ) {
         MOriginEM()->push_back( el.MOriginEM() );
      } else {
         MOriginEM()->push_back( std::numeric_limits< float >::min() );
      }
// -- slimmed --       if( el.WIDTH.IsAvailable() ) {
// -- slimmed --          WIDTH()->push_back( el.WIDTH() );
// -- slimmed --       } else {
// -- slimmed --          WIDTH()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.n90.IsAvailable() ) {
// -- slimmed --          n90()->push_back( el.n90() );
// -- slimmed --       } else {
// -- slimmed --          n90()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.Timing.IsAvailable() ) {
// -- slimmed --          Timing()->push_back( el.Timing() );
// -- slimmed --       } else {
// -- slimmed --          Timing()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
      if( el.LArQuality.IsAvailable() ) {
         LArQuality()->push_back( el.LArQuality() );
      } else {
         LArQuality()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nTrk.IsAvailable() ) {
         nTrk()->push_back( el.nTrk() );
      } else {
         nTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.sumPtTrk.IsAvailable() ) {
         sumPtTrk()->push_back( el.sumPtTrk() );
      } else {
         sumPtTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.OriginIndex.IsAvailable() ) {
         OriginIndex()->push_back( el.OriginIndex() );
      } else {
         OriginIndex()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.HECQuality.IsAvailable() ) {
         HECQuality()->push_back( el.HECQuality() );
      } else {
         HECQuality()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.NegativeE.IsAvailable() ) {
         NegativeE()->push_back( el.NegativeE() );
      } else {
         NegativeE()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.AverageLArQF.IsAvailable() ) {
         AverageLArQF()->push_back( el.AverageLArQF() );
      } else {
         AverageLArQF()->push_back( std::numeric_limits< float >::min() );
      }
// -- slimmed --       if( el.YFlip12.IsAvailable() ) {
// -- slimmed --          YFlip12()->push_back( el.YFlip12() );
// -- slimmed --       } else {
// -- slimmed --          YFlip12()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.YFlip23.IsAvailable() ) {
// -- slimmed --          YFlip23()->push_back( el.YFlip23() );
// -- slimmed --       } else {
// -- slimmed --          YFlip23()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.BCH_CORR_CELL.IsAvailable() ) {
// -- slimmed --          BCH_CORR_CELL()->push_back( el.BCH_CORR_CELL() );
// -- slimmed --       } else {
// -- slimmed --          BCH_CORR_CELL()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.BCH_CORR_DOTX.IsAvailable() ) {
// -- slimmed --          BCH_CORR_DOTX()->push_back( el.BCH_CORR_DOTX() );
// -- slimmed --       } else {
// -- slimmed --          BCH_CORR_DOTX()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.BCH_CORR_JET.IsAvailable() ) {
// -- slimmed --          BCH_CORR_JET()->push_back( el.BCH_CORR_JET() );
// -- slimmed --       } else {
// -- slimmed --          BCH_CORR_JET()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.BCH_CORR_JET_FORCELL.IsAvailable() ) {
// -- slimmed --          BCH_CORR_JET_FORCELL()->push_back( el.BCH_CORR_JET_FORCELL() );
// -- slimmed --       } else {
// -- slimmed --          BCH_CORR_JET_FORCELL()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
      if( el.ENG_BAD_CELLS.IsAvailable() ) {
         ENG_BAD_CELLS()->push_back( el.ENG_BAD_CELLS() );
      } else {
         ENG_BAD_CELLS()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.N_BAD_CELLS.IsAvailable() ) {
         N_BAD_CELLS()->push_back( el.N_BAD_CELLS() );
      } else {
         N_BAD_CELLS()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.N_BAD_CELLS_CORR.IsAvailable() ) {
         N_BAD_CELLS_CORR()->push_back( el.N_BAD_CELLS_CORR() );
      } else {
         N_BAD_CELLS_CORR()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.BAD_CELLS_CORR_E.IsAvailable() ) {
         BAD_CELLS_CORR_E()->push_back( el.BAD_CELLS_CORR_E() );
      } else {
         BAD_CELLS_CORR_E()->push_back( std::numeric_limits< float >::min() );
      }
// -- slimmed --       if( el.NumTowers.IsAvailable() ) {
// -- slimmed --          NumTowers()->push_back( el.NumTowers() );
// -- slimmed --       } else {
// -- slimmed --          NumTowers()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.ootFracCells5.IsAvailable() ) {
// -- slimmed --          ootFracCells5()->push_back( el.ootFracCells5() );
// -- slimmed --       } else {
// -- slimmed --          ootFracCells5()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.ootFracCells10.IsAvailable() ) {
// -- slimmed --          ootFracCells10()->push_back( el.ootFracCells10() );
// -- slimmed --       } else {
// -- slimmed --          ootFracCells10()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.ootFracClusters5.IsAvailable() ) {
// -- slimmed --          ootFracClusters5()->push_back( el.ootFracClusters5() );
// -- slimmed --       } else {
// -- slimmed --          ootFracClusters5()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.ootFracClusters10.IsAvailable() ) {
// -- slimmed --          ootFracClusters10()->push_back( el.ootFracClusters10() );
// -- slimmed --       } else {
// -- slimmed --          ootFracClusters10()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
      if( el.SamplingMax.IsAvailable() ) {
         SamplingMax()->push_back( el.SamplingMax() );
      } else {
         SamplingMax()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.fracSamplingMax.IsAvailable() ) {
         fracSamplingMax()->push_back( el.fracSamplingMax() );
      } else {
         fracSamplingMax()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.hecf.IsAvailable() ) {
         hecf()->push_back( el.hecf() );
      } else {
         hecf()->push_back( std::numeric_limits< float >::min() );
      }
// -- slimmed --       if( el.tgap3f.IsAvailable() ) {
// -- slimmed --          tgap3f()->push_back( el.tgap3f() );
// -- slimmed --       } else {
// -- slimmed --          tgap3f()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.isUgly.IsAvailable() ) {
// -- slimmed --          isUgly()->push_back( el.isUgly() );
// -- slimmed --       } else {
// -- slimmed --          isUgly()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.isBadLooseMinus.IsAvailable() ) {
// -- slimmed --          isBadLooseMinus()->push_back( el.isBadLooseMinus() );
// -- slimmed --       } else {
// -- slimmed --          isBadLooseMinus()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.isBadLoose.IsAvailable() ) {
// -- slimmed --          isBadLoose()->push_back( el.isBadLoose() );
// -- slimmed --       } else {
// -- slimmed --          isBadLoose()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.isBadMedium.IsAvailable() ) {
// -- slimmed --          isBadMedium()->push_back( el.isBadMedium() );
// -- slimmed --       } else {
// -- slimmed --          isBadMedium()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.isBadTight.IsAvailable() ) {
// -- slimmed --          isBadTight()->push_back( el.isBadTight() );
// -- slimmed --       } else {
// -- slimmed --          isBadTight()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
      if( el.emfrac.IsAvailable() ) {
         emfrac()->push_back( el.emfrac() );
      } else {
         emfrac()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Offset.IsAvailable() ) {
         Offset()->push_back( el.Offset() );
      } else {
         Offset()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EMJES.IsAvailable() ) {
         EMJES()->push_back( el.EMJES() );
      } else {
         EMJES()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EMJES_EtaCorr.IsAvailable() ) {
         EMJES_EtaCorr()->push_back( el.EMJES_EtaCorr() );
      } else {
         EMJES_EtaCorr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EMJESnooffset.IsAvailable() ) {
         EMJESnooffset()->push_back( el.EMJESnooffset() );
      } else {
         EMJESnooffset()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.GCWJES.IsAvailable() ) {
         GCWJES()->push_back( el.GCWJES() );
      } else {
         GCWJES()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.GCWJES_EtaCorr.IsAvailable() ) {
         GCWJES_EtaCorr()->push_back( el.GCWJES_EtaCorr() );
      } else {
         GCWJES_EtaCorr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.CB.IsAvailable() ) {
         CB()->push_back( el.CB() );
      } else {
         CB()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.LCJES.IsAvailable() ) {
         LCJES()->push_back( el.LCJES() );
      } else {
         LCJES()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.emscale_E.IsAvailable() ) {
         emscale_E()->push_back( el.emscale_E() );
      } else {
         emscale_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.emscale_pt.IsAvailable() ) {
         emscale_pt()->push_back( el.emscale_pt() );
      } else {
         emscale_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.emscale_m.IsAvailable() ) {
         emscale_m()->push_back( el.emscale_m() );
      } else {
         emscale_m()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.emscale_eta.IsAvailable() ) {
         emscale_eta()->push_back( el.emscale_eta() );
      } else {
         emscale_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.emscale_phi.IsAvailable() ) {
         emscale_phi()->push_back( el.emscale_phi() );
      } else {
         emscale_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jvtx_x.IsAvailable() ) {
         jvtx_x()->push_back( el.jvtx_x() );
      } else {
         jvtx_x()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jvtx_y.IsAvailable() ) {
         jvtx_y()->push_back( el.jvtx_y() );
      } else {
         jvtx_y()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jvtx_z.IsAvailable() ) {
         jvtx_z()->push_back( el.jvtx_z() );
      } else {
         jvtx_z()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jvtxf.IsAvailable() ) {
         jvtxf()->push_back( el.jvtxf() );
      } else {
         jvtxf()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jvtxfFull.IsAvailable() ) {
         jvtxfFull()->push_back( el.jvtxfFull() );
      } else {
         jvtxfFull()->push_back( vector<float>() );
      }
      if( el.GSCFactorF.IsAvailable() ) {
         GSCFactorF()->push_back( el.GSCFactorF() );
      } else {
         GSCFactorF()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.WidthFraction.IsAvailable() ) {
         WidthFraction()->push_back( el.WidthFraction() );
      } else {
         WidthFraction()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_PreSamplerB.IsAvailable() ) {
         e_PreSamplerB()->push_back( el.e_PreSamplerB() );
      } else {
         e_PreSamplerB()->push_back( std::numeric_limits< float >::min() );
      }
// -- slimmed --       if( el.e_EMB1.IsAvailable() ) {
// -- slimmed --          e_EMB1()->push_back( el.e_EMB1() );
// -- slimmed --       } else {
// -- slimmed --          e_EMB1()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_EMB2.IsAvailable() ) {
// -- slimmed --          e_EMB2()->push_back( el.e_EMB2() );
// -- slimmed --       } else {
// -- slimmed --          e_EMB2()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_EMB3.IsAvailable() ) {
// -- slimmed --          e_EMB3()->push_back( el.e_EMB3() );
// -- slimmed --       } else {
// -- slimmed --          e_EMB3()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_PreSamplerE.IsAvailable() ) {
// -- slimmed --          e_PreSamplerE()->push_back( el.e_PreSamplerE() );
// -- slimmed --       } else {
// -- slimmed --          e_PreSamplerE()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_EME1.IsAvailable() ) {
// -- slimmed --          e_EME1()->push_back( el.e_EME1() );
// -- slimmed --       } else {
// -- slimmed --          e_EME1()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_EME2.IsAvailable() ) {
// -- slimmed --          e_EME2()->push_back( el.e_EME2() );
// -- slimmed --       } else {
// -- slimmed --          e_EME2()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_EME3.IsAvailable() ) {
// -- slimmed --          e_EME3()->push_back( el.e_EME3() );
// -- slimmed --       } else {
// -- slimmed --          e_EME3()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_HEC0.IsAvailable() ) {
// -- slimmed --          e_HEC0()->push_back( el.e_HEC0() );
// -- slimmed --       } else {
// -- slimmed --          e_HEC0()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_HEC1.IsAvailable() ) {
// -- slimmed --          e_HEC1()->push_back( el.e_HEC1() );
// -- slimmed --       } else {
// -- slimmed --          e_HEC1()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_HEC2.IsAvailable() ) {
// -- slimmed --          e_HEC2()->push_back( el.e_HEC2() );
// -- slimmed --       } else {
// -- slimmed --          e_HEC2()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_HEC3.IsAvailable() ) {
// -- slimmed --          e_HEC3()->push_back( el.e_HEC3() );
// -- slimmed --       } else {
// -- slimmed --          e_HEC3()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_TileBar0.IsAvailable() ) {
// -- slimmed --          e_TileBar0()->push_back( el.e_TileBar0() );
// -- slimmed --       } else {
// -- slimmed --          e_TileBar0()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_TileBar1.IsAvailable() ) {
// -- slimmed --          e_TileBar1()->push_back( el.e_TileBar1() );
// -- slimmed --       } else {
// -- slimmed --          e_TileBar1()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_TileBar2.IsAvailable() ) {
// -- slimmed --          e_TileBar2()->push_back( el.e_TileBar2() );
// -- slimmed --       } else {
// -- slimmed --          e_TileBar2()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_TileGap1.IsAvailable() ) {
// -- slimmed --          e_TileGap1()->push_back( el.e_TileGap1() );
// -- slimmed --       } else {
// -- slimmed --          e_TileGap1()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_TileGap2.IsAvailable() ) {
// -- slimmed --          e_TileGap2()->push_back( el.e_TileGap2() );
// -- slimmed --       } else {
// -- slimmed --          e_TileGap2()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_TileGap3.IsAvailable() ) {
// -- slimmed --          e_TileGap3()->push_back( el.e_TileGap3() );
// -- slimmed --       } else {
// -- slimmed --          e_TileGap3()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_TileExt0.IsAvailable() ) {
// -- slimmed --          e_TileExt0()->push_back( el.e_TileExt0() );
// -- slimmed --       } else {
// -- slimmed --          e_TileExt0()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_TileExt1.IsAvailable() ) {
// -- slimmed --          e_TileExt1()->push_back( el.e_TileExt1() );
// -- slimmed --       } else {
// -- slimmed --          e_TileExt1()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_TileExt2.IsAvailable() ) {
// -- slimmed --          e_TileExt2()->push_back( el.e_TileExt2() );
// -- slimmed --       } else {
// -- slimmed --          e_TileExt2()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_FCAL0.IsAvailable() ) {
// -- slimmed --          e_FCAL0()->push_back( el.e_FCAL0() );
// -- slimmed --       } else {
// -- slimmed --          e_FCAL0()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_FCAL1.IsAvailable() ) {
// -- slimmed --          e_FCAL1()->push_back( el.e_FCAL1() );
// -- slimmed --       } else {
// -- slimmed --          e_FCAL1()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.e_FCAL2.IsAvailable() ) {
// -- slimmed --          e_FCAL2()->push_back( el.e_FCAL2() );
// -- slimmed --       } else {
// -- slimmed --          e_FCAL2()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.Nconst.IsAvailable() ) {
// -- slimmed --          Nconst()->push_back( el.Nconst() );
// -- slimmed --       } else {
// -- slimmed --          Nconst()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.ptconst_default.IsAvailable() ) {
// -- slimmed --          ptconst_default()->push_back( el.ptconst_default() );
// -- slimmed --       } else {
// -- slimmed --          ptconst_default()->push_back( vector<float>() );
// -- slimmed --       }
// -- slimmed --       if( el.econst_default.IsAvailable() ) {
// -- slimmed --          econst_default()->push_back( el.econst_default() );
// -- slimmed --       } else {
// -- slimmed --          econst_default()->push_back( vector<float>() );
// -- slimmed --       }
// -- slimmed --       if( el.etaconst_default.IsAvailable() ) {
// -- slimmed --          etaconst_default()->push_back( el.etaconst_default() );
// -- slimmed --       } else {
// -- slimmed --          etaconst_default()->push_back( vector<float>() );
// -- slimmed --       }
// -- slimmed --       if( el.phiconst_default.IsAvailable() ) {
// -- slimmed --          phiconst_default()->push_back( el.phiconst_default() );
// -- slimmed --       } else {
// -- slimmed --          phiconst_default()->push_back( vector<float>() );
// -- slimmed --       }
// -- slimmed --       if( el.weightconst_default.IsAvailable() ) {
// -- slimmed --          weightconst_default()->push_back( el.weightconst_default() );
// -- slimmed --       } else {
// -- slimmed --          weightconst_default()->push_back( vector<float>() );
// -- slimmed --       }
      if( el.constscale_E.IsAvailable() ) {
         constscale_E()->push_back( el.constscale_E() );
      } else {
         constscale_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.constscale_pt.IsAvailable() ) {
         constscale_pt()->push_back( el.constscale_pt() );
      } else {
         constscale_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.constscale_m.IsAvailable() ) {
         constscale_m()->push_back( el.constscale_m() );
      } else {
         constscale_m()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.constscale_eta.IsAvailable() ) {
         constscale_eta()->push_back( el.constscale_eta() );
      } else {
         constscale_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.constscale_phi.IsAvailable() ) {
         constscale_phi()->push_back( el.constscale_phi() );
      } else {
         constscale_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_Comb.IsAvailable() ) {
         flavor_weight_Comb()->push_back( el.flavor_weight_Comb() );
      } else {
         flavor_weight_Comb()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_IP2D.IsAvailable() ) {
         flavor_weight_IP2D()->push_back( el.flavor_weight_IP2D() );
      } else {
         flavor_weight_IP2D()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_IP3D.IsAvailable() ) {
         flavor_weight_IP3D()->push_back( el.flavor_weight_IP3D() );
      } else {
         flavor_weight_IP3D()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_SV0.IsAvailable() ) {
         flavor_weight_SV0()->push_back( el.flavor_weight_SV0() );
      } else {
         flavor_weight_SV0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_SV1.IsAvailable() ) {
         flavor_weight_SV1()->push_back( el.flavor_weight_SV1() );
      } else {
         flavor_weight_SV1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_SV2.IsAvailable() ) {
         flavor_weight_SV2()->push_back( el.flavor_weight_SV2() );
      } else {
         flavor_weight_SV2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_SoftMuonTagChi2.IsAvailable() ) {
         flavor_weight_SoftMuonTagChi2()->push_back( el.flavor_weight_SoftMuonTagChi2() );
      } else {
         flavor_weight_SoftMuonTagChi2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_SecondSoftMuonTagChi2.IsAvailable() ) {
         flavor_weight_SecondSoftMuonTagChi2()->push_back( el.flavor_weight_SecondSoftMuonTagChi2() );
      } else {
         flavor_weight_SecondSoftMuonTagChi2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_JetFitterTagNN.IsAvailable() ) {
         flavor_weight_JetFitterTagNN()->push_back( el.flavor_weight_JetFitterTagNN() );
      } else {
         flavor_weight_JetFitterTagNN()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_JetFitterCOMBNN.IsAvailable() ) {
         flavor_weight_JetFitterCOMBNN()->push_back( el.flavor_weight_JetFitterCOMBNN() );
      } else {
         flavor_weight_JetFitterCOMBNN()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_MV1.IsAvailable() ) {
         flavor_weight_MV1()->push_back( el.flavor_weight_MV1() );
      } else {
         flavor_weight_MV1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_MV2.IsAvailable() ) {
         flavor_weight_MV2()->push_back( el.flavor_weight_MV2() );
      } else {
         flavor_weight_MV2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_weight_GbbNN.IsAvailable() ) {
         flavor_weight_GbbNN()->push_back( el.flavor_weight_GbbNN() );
      } else {
         flavor_weight_GbbNN()->push_back( std::numeric_limits< float >::min() );
      }
if (!is_data) {
      if( el.flavor_truth_label.IsAvailable() ) {
         flavor_truth_label()->push_back( el.flavor_truth_label() );
      } else {
         flavor_truth_label()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_truth_dRminToB.IsAvailable() ) {
         flavor_truth_dRminToB()->push_back( el.flavor_truth_dRminToB() );
      } else {
         flavor_truth_dRminToB()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_truth_dRminToC.IsAvailable() ) {
         flavor_truth_dRminToC()->push_back( el.flavor_truth_dRminToC() );
      } else {
         flavor_truth_dRminToC()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_truth_dRminToT.IsAvailable() ) {
         flavor_truth_dRminToT()->push_back( el.flavor_truth_dRminToT() );
      } else {
         flavor_truth_dRminToT()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_truth_BHadronpdg.IsAvailable() ) {
         flavor_truth_BHadronpdg()->push_back( el.flavor_truth_BHadronpdg() );
      } else {
         flavor_truth_BHadronpdg()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_truth_vx_x.IsAvailable() ) {
         flavor_truth_vx_x()->push_back( el.flavor_truth_vx_x() );
      } else {
         flavor_truth_vx_x()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_truth_vx_y.IsAvailable() ) {
         flavor_truth_vx_y()->push_back( el.flavor_truth_vx_y() );
      } else {
         flavor_truth_vx_y()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_truth_vx_z.IsAvailable() ) {
         flavor_truth_vx_z()->push_back( el.flavor_truth_vx_z() );
      } else {
         flavor_truth_vx_z()->push_back( std::numeric_limits< float >::min() );
      }
} // end !is_data
// -- slimmed --       if( el.flavor_component_ip2d_pu.IsAvailable() ) {
// -- slimmed --          flavor_component_ip2d_pu()->push_back( el.flavor_component_ip2d_pu() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_ip2d_pu()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_ip2d_pb.IsAvailable() ) {
// -- slimmed --          flavor_component_ip2d_pb()->push_back( el.flavor_component_ip2d_pb() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_ip2d_pb()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_ip2d_isValid.IsAvailable() ) {
// -- slimmed --          flavor_component_ip2d_isValid()->push_back( el.flavor_component_ip2d_isValid() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_ip2d_isValid()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_ip2d_ntrk.IsAvailable() ) {
// -- slimmed --          flavor_component_ip2d_ntrk()->push_back( el.flavor_component_ip2d_ntrk() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_ip2d_ntrk()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_ip3d_pu.IsAvailable() ) {
// -- slimmed --          flavor_component_ip3d_pu()->push_back( el.flavor_component_ip3d_pu() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_ip3d_pu()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_ip3d_pb.IsAvailable() ) {
// -- slimmed --          flavor_component_ip3d_pb()->push_back( el.flavor_component_ip3d_pb() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_ip3d_pb()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_ip3d_isValid.IsAvailable() ) {
// -- slimmed --          flavor_component_ip3d_isValid()->push_back( el.flavor_component_ip3d_isValid() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_ip3d_isValid()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_ip3d_ntrk.IsAvailable() ) {
// -- slimmed --          flavor_component_ip3d_ntrk()->push_back( el.flavor_component_ip3d_ntrk() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_ip3d_ntrk()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv1_pu.IsAvailable() ) {
// -- slimmed --          flavor_component_sv1_pu()->push_back( el.flavor_component_sv1_pu() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv1_pu()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv1_pb.IsAvailable() ) {
// -- slimmed --          flavor_component_sv1_pb()->push_back( el.flavor_component_sv1_pb() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv1_pb()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv1_isValid.IsAvailable() ) {
// -- slimmed --          flavor_component_sv1_isValid()->push_back( el.flavor_component_sv1_isValid() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv1_isValid()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv2_pu.IsAvailable() ) {
// -- slimmed --          flavor_component_sv2_pu()->push_back( el.flavor_component_sv2_pu() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv2_pu()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv2_pb.IsAvailable() ) {
// -- slimmed --          flavor_component_sv2_pb()->push_back( el.flavor_component_sv2_pb() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv2_pb()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv2_isValid.IsAvailable() ) {
// -- slimmed --          flavor_component_sv2_isValid()->push_back( el.flavor_component_sv2_isValid() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv2_isValid()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_jfit_pu.IsAvailable() ) {
// -- slimmed --          flavor_component_jfit_pu()->push_back( el.flavor_component_jfit_pu() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_jfit_pu()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_jfit_pb.IsAvailable() ) {
// -- slimmed --          flavor_component_jfit_pb()->push_back( el.flavor_component_jfit_pb() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_jfit_pb()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_jfit_pc.IsAvailable() ) {
// -- slimmed --          flavor_component_jfit_pc()->push_back( el.flavor_component_jfit_pc() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_jfit_pc()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_jfit_isValid.IsAvailable() ) {
// -- slimmed --          flavor_component_jfit_isValid()->push_back( el.flavor_component_jfit_isValid() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_jfit_isValid()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_jfitcomb_pu.IsAvailable() ) {
// -- slimmed --          flavor_component_jfitcomb_pu()->push_back( el.flavor_component_jfitcomb_pu() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_jfitcomb_pu()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_jfitcomb_pb.IsAvailable() ) {
// -- slimmed --          flavor_component_jfitcomb_pb()->push_back( el.flavor_component_jfitcomb_pb() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_jfitcomb_pb()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_jfitcomb_pc.IsAvailable() ) {
// -- slimmed --          flavor_component_jfitcomb_pc()->push_back( el.flavor_component_jfitcomb_pc() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_jfitcomb_pc()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_jfitcomb_isValid.IsAvailable() ) {
// -- slimmed --          flavor_component_jfitcomb_isValid()->push_back( el.flavor_component_jfitcomb_isValid() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_jfitcomb_isValid()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_jfit_nvtx.IsAvailable() ) {
// -- slimmed --          flavor_component_jfit_nvtx()->push_back( el.flavor_component_jfit_nvtx() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_jfit_nvtx()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_jfit_nvtx1t.IsAvailable() ) {
// -- slimmed --          flavor_component_jfit_nvtx1t()->push_back( el.flavor_component_jfit_nvtx1t() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_jfit_nvtx1t()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_jfit_ntrkAtVx.IsAvailable() ) {
// -- slimmed --          flavor_component_jfit_ntrkAtVx()->push_back( el.flavor_component_jfit_ntrkAtVx() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_jfit_ntrkAtVx()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_jfit_efrc.IsAvailable() ) {
// -- slimmed --          flavor_component_jfit_efrc()->push_back( el.flavor_component_jfit_efrc() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_jfit_efrc()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_jfit_mass.IsAvailable() ) {
// -- slimmed --          flavor_component_jfit_mass()->push_back( el.flavor_component_jfit_mass() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_jfit_mass()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_jfit_sig3d.IsAvailable() ) {
// -- slimmed --          flavor_component_jfit_sig3d()->push_back( el.flavor_component_jfit_sig3d() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_jfit_sig3d()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_jfit_deltaPhi.IsAvailable() ) {
// -- slimmed --          flavor_component_jfit_deltaPhi()->push_back( el.flavor_component_jfit_deltaPhi() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_jfit_deltaPhi()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_jfit_deltaEta.IsAvailable() ) {
// -- slimmed --          flavor_component_jfit_deltaEta()->push_back( el.flavor_component_jfit_deltaEta() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_jfit_deltaEta()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_svp_isValid.IsAvailable() ) {
// -- slimmed --          flavor_component_svp_isValid()->push_back( el.flavor_component_svp_isValid() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_svp_isValid()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_svp_ntrkv.IsAvailable() ) {
// -- slimmed --          flavor_component_svp_ntrkv()->push_back( el.flavor_component_svp_ntrkv() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_svp_ntrkv()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_svp_ntrkj.IsAvailable() ) {
// -- slimmed --          flavor_component_svp_ntrkj()->push_back( el.flavor_component_svp_ntrkj() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_svp_ntrkj()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_svp_n2t.IsAvailable() ) {
// -- slimmed --          flavor_component_svp_n2t()->push_back( el.flavor_component_svp_n2t() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_svp_n2t()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_svp_mass.IsAvailable() ) {
// -- slimmed --          flavor_component_svp_mass()->push_back( el.flavor_component_svp_mass() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_svp_mass()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_svp_efrc.IsAvailable() ) {
// -- slimmed --          flavor_component_svp_efrc()->push_back( el.flavor_component_svp_efrc() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_svp_efrc()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_svp_x.IsAvailable() ) {
// -- slimmed --          flavor_component_svp_x()->push_back( el.flavor_component_svp_x() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_svp_x()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_svp_y.IsAvailable() ) {
// -- slimmed --          flavor_component_svp_y()->push_back( el.flavor_component_svp_y() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_svp_y()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_svp_z.IsAvailable() ) {
// -- slimmed --          flavor_component_svp_z()->push_back( el.flavor_component_svp_z() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_svp_z()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_svp_err_x.IsAvailable() ) {
// -- slimmed --          flavor_component_svp_err_x()->push_back( el.flavor_component_svp_err_x() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_svp_err_x()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_svp_err_y.IsAvailable() ) {
// -- slimmed --          flavor_component_svp_err_y()->push_back( el.flavor_component_svp_err_y() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_svp_err_y()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_svp_err_z.IsAvailable() ) {
// -- slimmed --          flavor_component_svp_err_z()->push_back( el.flavor_component_svp_err_z() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_svp_err_z()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_svp_cov_xy.IsAvailable() ) {
// -- slimmed --          flavor_component_svp_cov_xy()->push_back( el.flavor_component_svp_cov_xy() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_svp_cov_xy()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_svp_cov_xz.IsAvailable() ) {
// -- slimmed --          flavor_component_svp_cov_xz()->push_back( el.flavor_component_svp_cov_xz() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_svp_cov_xz()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_svp_cov_yz.IsAvailable() ) {
// -- slimmed --          flavor_component_svp_cov_yz()->push_back( el.flavor_component_svp_cov_yz() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_svp_cov_yz()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_svp_chi2.IsAvailable() ) {
// -- slimmed --          flavor_component_svp_chi2()->push_back( el.flavor_component_svp_chi2() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_svp_chi2()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_svp_ndof.IsAvailable() ) {
// -- slimmed --          flavor_component_svp_ndof()->push_back( el.flavor_component_svp_ndof() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_svp_ndof()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_svp_ntrk.IsAvailable() ) {
// -- slimmed --          flavor_component_svp_ntrk()->push_back( el.flavor_component_svp_ntrk() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_svp_ntrk()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv0p_isValid.IsAvailable() ) {
// -- slimmed --          flavor_component_sv0p_isValid()->push_back( el.flavor_component_sv0p_isValid() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv0p_isValid()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv0p_ntrkv.IsAvailable() ) {
// -- slimmed --          flavor_component_sv0p_ntrkv()->push_back( el.flavor_component_sv0p_ntrkv() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv0p_ntrkv()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv0p_ntrkj.IsAvailable() ) {
// -- slimmed --          flavor_component_sv0p_ntrkj()->push_back( el.flavor_component_sv0p_ntrkj() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv0p_ntrkj()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv0p_n2t.IsAvailable() ) {
// -- slimmed --          flavor_component_sv0p_n2t()->push_back( el.flavor_component_sv0p_n2t() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv0p_n2t()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv0p_mass.IsAvailable() ) {
// -- slimmed --          flavor_component_sv0p_mass()->push_back( el.flavor_component_sv0p_mass() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv0p_mass()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv0p_efrc.IsAvailable() ) {
// -- slimmed --          flavor_component_sv0p_efrc()->push_back( el.flavor_component_sv0p_efrc() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv0p_efrc()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv0p_x.IsAvailable() ) {
// -- slimmed --          flavor_component_sv0p_x()->push_back( el.flavor_component_sv0p_x() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv0p_x()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv0p_y.IsAvailable() ) {
// -- slimmed --          flavor_component_sv0p_y()->push_back( el.flavor_component_sv0p_y() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv0p_y()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv0p_z.IsAvailable() ) {
// -- slimmed --          flavor_component_sv0p_z()->push_back( el.flavor_component_sv0p_z() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv0p_z()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv0p_err_x.IsAvailable() ) {
// -- slimmed --          flavor_component_sv0p_err_x()->push_back( el.flavor_component_sv0p_err_x() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv0p_err_x()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv0p_err_y.IsAvailable() ) {
// -- slimmed --          flavor_component_sv0p_err_y()->push_back( el.flavor_component_sv0p_err_y() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv0p_err_y()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv0p_err_z.IsAvailable() ) {
// -- slimmed --          flavor_component_sv0p_err_z()->push_back( el.flavor_component_sv0p_err_z() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv0p_err_z()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv0p_cov_xy.IsAvailable() ) {
// -- slimmed --          flavor_component_sv0p_cov_xy()->push_back( el.flavor_component_sv0p_cov_xy() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv0p_cov_xy()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv0p_cov_xz.IsAvailable() ) {
// -- slimmed --          flavor_component_sv0p_cov_xz()->push_back( el.flavor_component_sv0p_cov_xz() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv0p_cov_xz()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv0p_cov_yz.IsAvailable() ) {
// -- slimmed --          flavor_component_sv0p_cov_yz()->push_back( el.flavor_component_sv0p_cov_yz() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv0p_cov_yz()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv0p_chi2.IsAvailable() ) {
// -- slimmed --          flavor_component_sv0p_chi2()->push_back( el.flavor_component_sv0p_chi2() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv0p_chi2()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv0p_ndof.IsAvailable() ) {
// -- slimmed --          flavor_component_sv0p_ndof()->push_back( el.flavor_component_sv0p_ndof() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv0p_ndof()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_component_sv0p_ntrk.IsAvailable() ) {
// -- slimmed --          flavor_component_sv0p_ntrk()->push_back( el.flavor_component_sv0p_ntrk() );
// -- slimmed --       } else {
// -- slimmed --          flavor_component_sv0p_ntrk()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_assoctrk_n.IsAvailable() ) {
// -- slimmed --          flavor_assoctrk_n()->push_back( el.flavor_assoctrk_n() );
// -- slimmed --       } else {
// -- slimmed --          flavor_assoctrk_n()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.flavor_assoctrk_index.IsAvailable() ) {
// -- slimmed --          flavor_assoctrk_index()->push_back( el.flavor_assoctrk_index() );
// -- slimmed --       } else {
// -- slimmed --          flavor_assoctrk_index()->push_back( vector<int>() );
// -- slimmed --       }
// -- slimmed --       if( el.el_dr.IsAvailable() ) {
// -- slimmed --          el_dr()->push_back( el.el_dr() );
// -- slimmed --       } else {
// -- slimmed --          el_dr()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.el_matched.IsAvailable() ) {
// -- slimmed --          el_matched()->push_back( el.el_matched() );
// -- slimmed --       } else {
// -- slimmed --          el_matched()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.mu_dr.IsAvailable() ) {
// -- slimmed --          mu_dr()->push_back( el.mu_dr() );
// -- slimmed --       } else {
// -- slimmed --          mu_dr()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.mu_matched.IsAvailable() ) {
// -- slimmed --          mu_matched()->push_back( el.mu_matched() );
// -- slimmed --       } else {
// -- slimmed --          mu_matched()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.L1_dr.IsAvailable() ) {
// -- slimmed --          L1_dr()->push_back( el.L1_dr() );
// -- slimmed --       } else {
// -- slimmed --          L1_dr()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.L1_matched.IsAvailable() ) {
// -- slimmed --          L1_matched()->push_back( el.L1_matched() );
// -- slimmed --       } else {
// -- slimmed --          L1_matched()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.L2_dr.IsAvailable() ) {
// -- slimmed --          L2_dr()->push_back( el.L2_dr() );
// -- slimmed --       } else {
// -- slimmed --          L2_dr()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.L2_matched.IsAvailable() ) {
// -- slimmed --          L2_matched()->push_back( el.L2_matched() );
// -- slimmed --       } else {
// -- slimmed --          L2_matched()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.EF_dr.IsAvailable() ) {
// -- slimmed --          EF_dr()->push_back( el.EF_dr() );
// -- slimmed --       } else {
// -- slimmed --          EF_dr()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.EF_matched.IsAvailable() ) {
// -- slimmed --          EF_matched()->push_back( el.EF_matched() );
// -- slimmed --       } else {
// -- slimmed --          EF_matched()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.bbDecision.IsAvailable() ) {
// -- slimmed --          bbDecision()->push_back( el.bbDecision() );
// -- slimmed --       } else {
// -- slimmed --          bbDecision()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.SmearingFactor.IsAvailable() ) {
// -- slimmed --          SmearingFactor()->push_back( el.SmearingFactor() );
// -- slimmed --       } else {
// -- slimmed --          SmearingFactor()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
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
   JetD3PDObjectElement& JetD3PDObject::operator[]( size_t index ) {

      while( fProxies.size() <= index ) {
         fProxies.push_back( JetD3PDObjectElement( fProxies.size(), *this , is_data ) );
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
   const JetD3PDObjectElement& JetD3PDObject::operator[]( size_t index ) const {

      while( fProxies.size() <= index ) {
         fProxies.push_back( JetD3PDObjectElement( fProxies.size(), *this , is_data ) );
      }
      return fProxies[ index ];
   }

   /**
    * A convenience operator for adding an 'element' to this collection.
    *
    * @see Add
    * @param el The 'element' that should be added to the collection
    */
   JetD3PDObject& JetD3PDObject::operator+=( const JetD3PDObjectElement& el ) {

      return this->Add( el );
   }

} // namespace D3PDReader
