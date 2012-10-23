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
        MET_LooseEgamma10NoTau_wpx( parent.MET_LooseEgamma10NoTau_wpx, index, this ),
        MET_LooseEgamma10NoTau_wpy( parent.MET_LooseEgamma10NoTau_wpy, index, this ),
        MET_LooseEgamma10NoTau_wet( parent.MET_LooseEgamma10NoTau_wet, index, this ),
        MET_LooseEgamma10NoTau_statusWord( parent.MET_LooseEgamma10NoTau_statusWord, index, this ),
        MET_wpx( parent.MET_wpx, index, this ),
        MET_wpy( parent.MET_wpy, index, this ),
        MET_wet( parent.MET_wet, index, this ),
        MET_statusWord( parent.MET_statusWord, index, this ),
        MET_STVF_wpx( parent.MET_STVF_wpx, index, this ),
        MET_STVF_wpy( parent.MET_STVF_wpy, index, this ),
        MET_STVF_wet( parent.MET_STVF_wet, index, this ),
        MET_STVF_statusWord( parent.MET_STVF_statusWord, index, this ),
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
        WIDTH( parent.WIDTH, index, this ),
        n90( parent.n90, index, this ),
        Timing( parent.Timing, index, this ),
        LArQuality( parent.LArQuality, index, this ),
        nTrk( parent.nTrk, index, this ),
        sumPtTrk( parent.sumPtTrk, index, this ),
        OriginIndex( parent.OriginIndex, index, this ),
        HECQuality( parent.HECQuality, index, this ),
        NegativeE( parent.NegativeE, index, this ),
        AverageLArQF( parent.AverageLArQF, index, this ),
        YFlip12( parent.YFlip12, index, this ),
        YFlip23( parent.YFlip23, index, this ),
        BCH_CORR_CELL( parent.BCH_CORR_CELL, index, this ),
        BCH_CORR_DOTX( parent.BCH_CORR_DOTX, index, this ),
        BCH_CORR_JET( parent.BCH_CORR_JET, index, this ),
        BCH_CORR_JET_FORCELL( parent.BCH_CORR_JET_FORCELL, index, this ),
        ENG_BAD_CELLS( parent.ENG_BAD_CELLS, index, this ),
        N_BAD_CELLS( parent.N_BAD_CELLS, index, this ),
        N_BAD_CELLS_CORR( parent.N_BAD_CELLS_CORR, index, this ),
        BAD_CELLS_CORR_E( parent.BAD_CELLS_CORR_E, index, this ),
        NumTowers( parent.NumTowers, index, this ),
        ootFracCells5( parent.ootFracCells5, index, this ),
        ootFracCells10( parent.ootFracCells10, index, this ),
        ootFracClusters5( parent.ootFracClusters5, index, this ),
        ootFracClusters10( parent.ootFracClusters10, index, this ),
        SamplingMax( parent.SamplingMax, index, this ),
        fracSamplingMax( parent.fracSamplingMax, index, this ),
        hecf( parent.hecf, index, this ),
        tgap3f( parent.tgap3f, index, this ),
        isUgly( parent.isUgly, index, this ),
        isBadLooseMinus( parent.isBadLooseMinus, index, this ),
        isBadLoose( parent.isBadLoose, index, this ),
        isBadMedium( parent.isBadMedium, index, this ),
        isBadTight( parent.isBadTight, index, this ),
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
        e_EMB1( parent.e_EMB1, index, this ),
        e_EMB2( parent.e_EMB2, index, this ),
        e_EMB3( parent.e_EMB3, index, this ),
        e_PreSamplerE( parent.e_PreSamplerE, index, this ),
        e_EME1( parent.e_EME1, index, this ),
        e_EME2( parent.e_EME2, index, this ),
        e_EME3( parent.e_EME3, index, this ),
        e_HEC0( parent.e_HEC0, index, this ),
        e_HEC1( parent.e_HEC1, index, this ),
        e_HEC2( parent.e_HEC2, index, this ),
        e_HEC3( parent.e_HEC3, index, this ),
        e_TileBar0( parent.e_TileBar0, index, this ),
        e_TileBar1( parent.e_TileBar1, index, this ),
        e_TileBar2( parent.e_TileBar2, index, this ),
        e_TileGap1( parent.e_TileGap1, index, this ),
        e_TileGap2( parent.e_TileGap2, index, this ),
        e_TileGap3( parent.e_TileGap3, index, this ),
        e_TileExt0( parent.e_TileExt0, index, this ),
        e_TileExt1( parent.e_TileExt1, index, this ),
        e_TileExt2( parent.e_TileExt2, index, this ),
        e_FCAL0( parent.e_FCAL0, index, this ),
        e_FCAL1( parent.e_FCAL1, index, this ),
        e_FCAL2( parent.e_FCAL2, index, this ),
        Nconst( parent.Nconst, index, this ),
        ptconst_default( parent.ptconst_default, index, this ),
        econst_default( parent.econst_default, index, this ),
        etaconst_default( parent.etaconst_default, index, this ),
        phiconst_default( parent.phiconst_default, index, this ),
        weightconst_default( parent.weightconst_default, index, this ),
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
        flavor_component_ip2d_pu( parent.flavor_component_ip2d_pu, index, this ),
        flavor_component_ip2d_pb( parent.flavor_component_ip2d_pb, index, this ),
        flavor_component_ip2d_isValid( parent.flavor_component_ip2d_isValid, index, this ),
        flavor_component_ip2d_ntrk( parent.flavor_component_ip2d_ntrk, index, this ),
        flavor_component_ip3d_pu( parent.flavor_component_ip3d_pu, index, this ),
        flavor_component_ip3d_pb( parent.flavor_component_ip3d_pb, index, this ),
        flavor_component_ip3d_isValid( parent.flavor_component_ip3d_isValid, index, this ),
        flavor_component_ip3d_ntrk( parent.flavor_component_ip3d_ntrk, index, this ),
        flavor_component_sv1_pu( parent.flavor_component_sv1_pu, index, this ),
        flavor_component_sv1_pb( parent.flavor_component_sv1_pb, index, this ),
        flavor_component_sv1_isValid( parent.flavor_component_sv1_isValid, index, this ),
        flavor_component_sv2_pu( parent.flavor_component_sv2_pu, index, this ),
        flavor_component_sv2_pb( parent.flavor_component_sv2_pb, index, this ),
        flavor_component_sv2_isValid( parent.flavor_component_sv2_isValid, index, this ),
        flavor_component_jfit_pu( parent.flavor_component_jfit_pu, index, this ),
        flavor_component_jfit_pb( parent.flavor_component_jfit_pb, index, this ),
        flavor_component_jfit_pc( parent.flavor_component_jfit_pc, index, this ),
        flavor_component_jfit_isValid( parent.flavor_component_jfit_isValid, index, this ),
        flavor_component_jfitcomb_pu( parent.flavor_component_jfitcomb_pu, index, this ),
        flavor_component_jfitcomb_pb( parent.flavor_component_jfitcomb_pb, index, this ),
        flavor_component_jfitcomb_pc( parent.flavor_component_jfitcomb_pc, index, this ),
        flavor_component_jfitcomb_isValid( parent.flavor_component_jfitcomb_isValid, index, this ),
        flavor_component_jfit_nvtx( parent.flavor_component_jfit_nvtx, index, this ),
        flavor_component_jfit_nvtx1t( parent.flavor_component_jfit_nvtx1t, index, this ),
        flavor_component_jfit_ntrkAtVx( parent.flavor_component_jfit_ntrkAtVx, index, this ),
        flavor_component_jfit_efrc( parent.flavor_component_jfit_efrc, index, this ),
        flavor_component_jfit_mass( parent.flavor_component_jfit_mass, index, this ),
        flavor_component_jfit_sig3d( parent.flavor_component_jfit_sig3d, index, this ),
        flavor_component_jfit_deltaPhi( parent.flavor_component_jfit_deltaPhi, index, this ),
        flavor_component_jfit_deltaEta( parent.flavor_component_jfit_deltaEta, index, this ),
        flavor_component_svp_isValid( parent.flavor_component_svp_isValid, index, this ),
        flavor_component_svp_ntrkv( parent.flavor_component_svp_ntrkv, index, this ),
        flavor_component_svp_ntrkj( parent.flavor_component_svp_ntrkj, index, this ),
        flavor_component_svp_n2t( parent.flavor_component_svp_n2t, index, this ),
        flavor_component_svp_mass( parent.flavor_component_svp_mass, index, this ),
        flavor_component_svp_efrc( parent.flavor_component_svp_efrc, index, this ),
        flavor_component_svp_x( parent.flavor_component_svp_x, index, this ),
        flavor_component_svp_y( parent.flavor_component_svp_y, index, this ),
        flavor_component_svp_z( parent.flavor_component_svp_z, index, this ),
        flavor_component_svp_err_x( parent.flavor_component_svp_err_x, index, this ),
        flavor_component_svp_err_y( parent.flavor_component_svp_err_y, index, this ),
        flavor_component_svp_err_z( parent.flavor_component_svp_err_z, index, this ),
        flavor_component_svp_cov_xy( parent.flavor_component_svp_cov_xy, index, this ),
        flavor_component_svp_cov_xz( parent.flavor_component_svp_cov_xz, index, this ),
        flavor_component_svp_cov_yz( parent.flavor_component_svp_cov_yz, index, this ),
        flavor_component_svp_chi2( parent.flavor_component_svp_chi2, index, this ),
        flavor_component_svp_ndof( parent.flavor_component_svp_ndof, index, this ),
        flavor_component_svp_ntrk( parent.flavor_component_svp_ntrk, index, this ),
        flavor_component_sv0p_isValid( parent.flavor_component_sv0p_isValid, index, this ),
        flavor_component_sv0p_ntrkv( parent.flavor_component_sv0p_ntrkv, index, this ),
        flavor_component_sv0p_ntrkj( parent.flavor_component_sv0p_ntrkj, index, this ),
        flavor_component_sv0p_n2t( parent.flavor_component_sv0p_n2t, index, this ),
        flavor_component_sv0p_mass( parent.flavor_component_sv0p_mass, index, this ),
        flavor_component_sv0p_efrc( parent.flavor_component_sv0p_efrc, index, this ),
        flavor_component_sv0p_x( parent.flavor_component_sv0p_x, index, this ),
        flavor_component_sv0p_y( parent.flavor_component_sv0p_y, index, this ),
        flavor_component_sv0p_z( parent.flavor_component_sv0p_z, index, this ),
        flavor_component_sv0p_err_x( parent.flavor_component_sv0p_err_x, index, this ),
        flavor_component_sv0p_err_y( parent.flavor_component_sv0p_err_y, index, this ),
        flavor_component_sv0p_err_z( parent.flavor_component_sv0p_err_z, index, this ),
        flavor_component_sv0p_cov_xy( parent.flavor_component_sv0p_cov_xy, index, this ),
        flavor_component_sv0p_cov_xz( parent.flavor_component_sv0p_cov_xz, index, this ),
        flavor_component_sv0p_cov_yz( parent.flavor_component_sv0p_cov_yz, index, this ),
        flavor_component_sv0p_chi2( parent.flavor_component_sv0p_chi2, index, this ),
        flavor_component_sv0p_ndof( parent.flavor_component_sv0p_ndof, index, this ),
        flavor_component_sv0p_ntrk( parent.flavor_component_sv0p_ntrk, index, this ),
        flavor_assoctrk_n( parent.flavor_assoctrk_n, index, this ),
        flavor_assoctrk_index( parent.flavor_assoctrk_index, index, this ),
        el_dr( parent.el_dr, index, this ),
        el_matched( parent.el_matched, index, this ),
        mu_dr( parent.mu_dr, index, this ),
        mu_matched( parent.mu_matched, index, this ),
        L1_dr( parent.L1_dr, index, this ),
        L1_matched( parent.L1_matched, index, this ),
        L2_dr( parent.L2_dr, index, this ),
        L2_matched( parent.L2_matched, index, this ),
        EF_dr( parent.EF_dr, index, this ),
        EF_matched( parent.EF_matched, index, this ),
        bbDecision( parent.bbDecision, index, this ),
        SmearingFactor( parent.SmearingFactor, index, this ) , 
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
        MET_LooseEgamma10NoTau_wpx( parent.MET_LooseEgamma10NoTau_wpx ),
        MET_LooseEgamma10NoTau_wpy( parent.MET_LooseEgamma10NoTau_wpy ),
        MET_LooseEgamma10NoTau_wet( parent.MET_LooseEgamma10NoTau_wet ),
        MET_LooseEgamma10NoTau_statusWord( parent.MET_LooseEgamma10NoTau_statusWord ),
        MET_wpx( parent.MET_wpx ),
        MET_wpy( parent.MET_wpy ),
        MET_wet( parent.MET_wet ),
        MET_statusWord( parent.MET_statusWord ),
        MET_STVF_wpx( parent.MET_STVF_wpx ),
        MET_STVF_wpy( parent.MET_STVF_wpy ),
        MET_STVF_wet( parent.MET_STVF_wet ),
        MET_STVF_statusWord( parent.MET_STVF_statusWord ),
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
        WIDTH( parent.WIDTH ),
        n90( parent.n90 ),
        Timing( parent.Timing ),
        LArQuality( parent.LArQuality ),
        nTrk( parent.nTrk ),
        sumPtTrk( parent.sumPtTrk ),
        OriginIndex( parent.OriginIndex ),
        HECQuality( parent.HECQuality ),
        NegativeE( parent.NegativeE ),
        AverageLArQF( parent.AverageLArQF ),
        YFlip12( parent.YFlip12 ),
        YFlip23( parent.YFlip23 ),
        BCH_CORR_CELL( parent.BCH_CORR_CELL ),
        BCH_CORR_DOTX( parent.BCH_CORR_DOTX ),
        BCH_CORR_JET( parent.BCH_CORR_JET ),
        BCH_CORR_JET_FORCELL( parent.BCH_CORR_JET_FORCELL ),
        ENG_BAD_CELLS( parent.ENG_BAD_CELLS ),
        N_BAD_CELLS( parent.N_BAD_CELLS ),
        N_BAD_CELLS_CORR( parent.N_BAD_CELLS_CORR ),
        BAD_CELLS_CORR_E( parent.BAD_CELLS_CORR_E ),
        NumTowers( parent.NumTowers ),
        ootFracCells5( parent.ootFracCells5 ),
        ootFracCells10( parent.ootFracCells10 ),
        ootFracClusters5( parent.ootFracClusters5 ),
        ootFracClusters10( parent.ootFracClusters10 ),
        SamplingMax( parent.SamplingMax ),
        fracSamplingMax( parent.fracSamplingMax ),
        hecf( parent.hecf ),
        tgap3f( parent.tgap3f ),
        isUgly( parent.isUgly ),
        isBadLooseMinus( parent.isBadLooseMinus ),
        isBadLoose( parent.isBadLoose ),
        isBadMedium( parent.isBadMedium ),
        isBadTight( parent.isBadTight ),
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
        e_EMB1( parent.e_EMB1 ),
        e_EMB2( parent.e_EMB2 ),
        e_EMB3( parent.e_EMB3 ),
        e_PreSamplerE( parent.e_PreSamplerE ),
        e_EME1( parent.e_EME1 ),
        e_EME2( parent.e_EME2 ),
        e_EME3( parent.e_EME3 ),
        e_HEC0( parent.e_HEC0 ),
        e_HEC1( parent.e_HEC1 ),
        e_HEC2( parent.e_HEC2 ),
        e_HEC3( parent.e_HEC3 ),
        e_TileBar0( parent.e_TileBar0 ),
        e_TileBar1( parent.e_TileBar1 ),
        e_TileBar2( parent.e_TileBar2 ),
        e_TileGap1( parent.e_TileGap1 ),
        e_TileGap2( parent.e_TileGap2 ),
        e_TileGap3( parent.e_TileGap3 ),
        e_TileExt0( parent.e_TileExt0 ),
        e_TileExt1( parent.e_TileExt1 ),
        e_TileExt2( parent.e_TileExt2 ),
        e_FCAL0( parent.e_FCAL0 ),
        e_FCAL1( parent.e_FCAL1 ),
        e_FCAL2( parent.e_FCAL2 ),
        Nconst( parent.Nconst ),
        ptconst_default( parent.ptconst_default ),
        econst_default( parent.econst_default ),
        etaconst_default( parent.etaconst_default ),
        phiconst_default( parent.phiconst_default ),
        weightconst_default( parent.weightconst_default ),
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
        flavor_component_ip2d_pu( parent.flavor_component_ip2d_pu ),
        flavor_component_ip2d_pb( parent.flavor_component_ip2d_pb ),
        flavor_component_ip2d_isValid( parent.flavor_component_ip2d_isValid ),
        flavor_component_ip2d_ntrk( parent.flavor_component_ip2d_ntrk ),
        flavor_component_ip3d_pu( parent.flavor_component_ip3d_pu ),
        flavor_component_ip3d_pb( parent.flavor_component_ip3d_pb ),
        flavor_component_ip3d_isValid( parent.flavor_component_ip3d_isValid ),
        flavor_component_ip3d_ntrk( parent.flavor_component_ip3d_ntrk ),
        flavor_component_sv1_pu( parent.flavor_component_sv1_pu ),
        flavor_component_sv1_pb( parent.flavor_component_sv1_pb ),
        flavor_component_sv1_isValid( parent.flavor_component_sv1_isValid ),
        flavor_component_sv2_pu( parent.flavor_component_sv2_pu ),
        flavor_component_sv2_pb( parent.flavor_component_sv2_pb ),
        flavor_component_sv2_isValid( parent.flavor_component_sv2_isValid ),
        flavor_component_jfit_pu( parent.flavor_component_jfit_pu ),
        flavor_component_jfit_pb( parent.flavor_component_jfit_pb ),
        flavor_component_jfit_pc( parent.flavor_component_jfit_pc ),
        flavor_component_jfit_isValid( parent.flavor_component_jfit_isValid ),
        flavor_component_jfitcomb_pu( parent.flavor_component_jfitcomb_pu ),
        flavor_component_jfitcomb_pb( parent.flavor_component_jfitcomb_pb ),
        flavor_component_jfitcomb_pc( parent.flavor_component_jfitcomb_pc ),
        flavor_component_jfitcomb_isValid( parent.flavor_component_jfitcomb_isValid ),
        flavor_component_jfit_nvtx( parent.flavor_component_jfit_nvtx ),
        flavor_component_jfit_nvtx1t( parent.flavor_component_jfit_nvtx1t ),
        flavor_component_jfit_ntrkAtVx( parent.flavor_component_jfit_ntrkAtVx ),
        flavor_component_jfit_efrc( parent.flavor_component_jfit_efrc ),
        flavor_component_jfit_mass( parent.flavor_component_jfit_mass ),
        flavor_component_jfit_sig3d( parent.flavor_component_jfit_sig3d ),
        flavor_component_jfit_deltaPhi( parent.flavor_component_jfit_deltaPhi ),
        flavor_component_jfit_deltaEta( parent.flavor_component_jfit_deltaEta ),
        flavor_component_svp_isValid( parent.flavor_component_svp_isValid ),
        flavor_component_svp_ntrkv( parent.flavor_component_svp_ntrkv ),
        flavor_component_svp_ntrkj( parent.flavor_component_svp_ntrkj ),
        flavor_component_svp_n2t( parent.flavor_component_svp_n2t ),
        flavor_component_svp_mass( parent.flavor_component_svp_mass ),
        flavor_component_svp_efrc( parent.flavor_component_svp_efrc ),
        flavor_component_svp_x( parent.flavor_component_svp_x ),
        flavor_component_svp_y( parent.flavor_component_svp_y ),
        flavor_component_svp_z( parent.flavor_component_svp_z ),
        flavor_component_svp_err_x( parent.flavor_component_svp_err_x ),
        flavor_component_svp_err_y( parent.flavor_component_svp_err_y ),
        flavor_component_svp_err_z( parent.flavor_component_svp_err_z ),
        flavor_component_svp_cov_xy( parent.flavor_component_svp_cov_xy ),
        flavor_component_svp_cov_xz( parent.flavor_component_svp_cov_xz ),
        flavor_component_svp_cov_yz( parent.flavor_component_svp_cov_yz ),
        flavor_component_svp_chi2( parent.flavor_component_svp_chi2 ),
        flavor_component_svp_ndof( parent.flavor_component_svp_ndof ),
        flavor_component_svp_ntrk( parent.flavor_component_svp_ntrk ),
        flavor_component_sv0p_isValid( parent.flavor_component_sv0p_isValid ),
        flavor_component_sv0p_ntrkv( parent.flavor_component_sv0p_ntrkv ),
        flavor_component_sv0p_ntrkj( parent.flavor_component_sv0p_ntrkj ),
        flavor_component_sv0p_n2t( parent.flavor_component_sv0p_n2t ),
        flavor_component_sv0p_mass( parent.flavor_component_sv0p_mass ),
        flavor_component_sv0p_efrc( parent.flavor_component_sv0p_efrc ),
        flavor_component_sv0p_x( parent.flavor_component_sv0p_x ),
        flavor_component_sv0p_y( parent.flavor_component_sv0p_y ),
        flavor_component_sv0p_z( parent.flavor_component_sv0p_z ),
        flavor_component_sv0p_err_x( parent.flavor_component_sv0p_err_x ),
        flavor_component_sv0p_err_y( parent.flavor_component_sv0p_err_y ),
        flavor_component_sv0p_err_z( parent.flavor_component_sv0p_err_z ),
        flavor_component_sv0p_cov_xy( parent.flavor_component_sv0p_cov_xy ),
        flavor_component_sv0p_cov_xz( parent.flavor_component_sv0p_cov_xz ),
        flavor_component_sv0p_cov_yz( parent.flavor_component_sv0p_cov_yz ),
        flavor_component_sv0p_chi2( parent.flavor_component_sv0p_chi2 ),
        flavor_component_sv0p_ndof( parent.flavor_component_sv0p_ndof ),
        flavor_component_sv0p_ntrk( parent.flavor_component_sv0p_ntrk ),
        flavor_assoctrk_n( parent.flavor_assoctrk_n ),
        flavor_assoctrk_index( parent.flavor_assoctrk_index ),
        el_dr( parent.el_dr ),
        el_matched( parent.el_matched ),
        mu_dr( parent.mu_dr ),
        mu_matched( parent.mu_matched ),
        L1_dr( parent.L1_dr ),
        L1_matched( parent.L1_matched ),
        L2_dr( parent.L2_dr ),
        L2_matched( parent.L2_matched ),
        EF_dr( parent.EF_dr ),
        EF_matched( parent.EF_matched ),
        bbDecision( parent.bbDecision ),
        SmearingFactor( parent.SmearingFactor ) , 
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
        MET_LooseEgamma10NoTau_wpx( this, ::TString( prefix ) + "MET_LooseEgamma10NoTau_wpx", &master ),
        MET_LooseEgamma10NoTau_wpy( this, ::TString( prefix ) + "MET_LooseEgamma10NoTau_wpy", &master ),
        MET_LooseEgamma10NoTau_wet( this, ::TString( prefix ) + "MET_LooseEgamma10NoTau_wet", &master ),
        MET_LooseEgamma10NoTau_statusWord( this, ::TString( prefix ) + "MET_LooseEgamma10NoTau_statusWord", &master ),
        MET_wpx( this, ::TString( prefix ) + "MET_wpx", &master ),
        MET_wpy( this, ::TString( prefix ) + "MET_wpy", &master ),
        MET_wet( this, ::TString( prefix ) + "MET_wet", &master ),
        MET_statusWord( this, ::TString( prefix ) + "MET_statusWord", &master ),
        MET_STVF_wpx( this, ::TString( prefix ) + "MET_STVF_wpx", &master ),
        MET_STVF_wpy( this, ::TString( prefix ) + "MET_STVF_wpy", &master ),
        MET_STVF_wet( this, ::TString( prefix ) + "MET_STVF_wet", &master ),
        MET_STVF_statusWord( this, ::TString( prefix ) + "MET_STVF_statusWord", &master ),
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
        WIDTH( this, ::TString( prefix ) + "WIDTH", &master ),
        n90( this, ::TString( prefix ) + "n90", &master ),
        Timing( this, ::TString( prefix ) + "Timing", &master ),
        LArQuality( this, ::TString( prefix ) + "LArQuality", &master ),
        nTrk( this, ::TString( prefix ) + "nTrk", &master ),
        sumPtTrk( this, ::TString( prefix ) + "sumPtTrk", &master ),
        OriginIndex( this, ::TString( prefix ) + "OriginIndex", &master ),
        HECQuality( this, ::TString( prefix ) + "HECQuality", &master ),
        NegativeE( this, ::TString( prefix ) + "NegativeE", &master ),
        AverageLArQF( this, ::TString( prefix ) + "AverageLArQF", &master ),
        YFlip12( this, ::TString( prefix ) + "YFlip12", &master ),
        YFlip23( this, ::TString( prefix ) + "YFlip23", &master ),
        BCH_CORR_CELL( this, ::TString( prefix ) + "BCH_CORR_CELL", &master ),
        BCH_CORR_DOTX( this, ::TString( prefix ) + "BCH_CORR_DOTX", &master ),
        BCH_CORR_JET( this, ::TString( prefix ) + "BCH_CORR_JET", &master ),
        BCH_CORR_JET_FORCELL( this, ::TString( prefix ) + "BCH_CORR_JET_FORCELL", &master ),
        ENG_BAD_CELLS( this, ::TString( prefix ) + "ENG_BAD_CELLS", &master ),
        N_BAD_CELLS( this, ::TString( prefix ) + "N_BAD_CELLS", &master ),
        N_BAD_CELLS_CORR( this, ::TString( prefix ) + "N_BAD_CELLS_CORR", &master ),
        BAD_CELLS_CORR_E( this, ::TString( prefix ) + "BAD_CELLS_CORR_E", &master ),
        NumTowers( this, ::TString( prefix ) + "NumTowers", &master ),
        ootFracCells5( this, ::TString( prefix ) + "ootFracCells5", &master ),
        ootFracCells10( this, ::TString( prefix ) + "ootFracCells10", &master ),
        ootFracClusters5( this, ::TString( prefix ) + "ootFracClusters5", &master ),
        ootFracClusters10( this, ::TString( prefix ) + "ootFracClusters10", &master ),
        SamplingMax( this, ::TString( prefix ) + "SamplingMax", &master ),
        fracSamplingMax( this, ::TString( prefix ) + "fracSamplingMax", &master ),
        hecf( this, ::TString( prefix ) + "hecf", &master ),
        tgap3f( this, ::TString( prefix ) + "tgap3f", &master ),
        isUgly( this, ::TString( prefix ) + "isUgly", &master ),
        isBadLooseMinus( this, ::TString( prefix ) + "isBadLooseMinus", &master ),
        isBadLoose( this, ::TString( prefix ) + "isBadLoose", &master ),
        isBadMedium( this, ::TString( prefix ) + "isBadMedium", &master ),
        isBadTight( this, ::TString( prefix ) + "isBadTight", &master ),
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
        e_EMB1( this, ::TString( prefix ) + "e_EMB1", &master ),
        e_EMB2( this, ::TString( prefix ) + "e_EMB2", &master ),
        e_EMB3( this, ::TString( prefix ) + "e_EMB3", &master ),
        e_PreSamplerE( this, ::TString( prefix ) + "e_PreSamplerE", &master ),
        e_EME1( this, ::TString( prefix ) + "e_EME1", &master ),
        e_EME2( this, ::TString( prefix ) + "e_EME2", &master ),
        e_EME3( this, ::TString( prefix ) + "e_EME3", &master ),
        e_HEC0( this, ::TString( prefix ) + "e_HEC0", &master ),
        e_HEC1( this, ::TString( prefix ) + "e_HEC1", &master ),
        e_HEC2( this, ::TString( prefix ) + "e_HEC2", &master ),
        e_HEC3( this, ::TString( prefix ) + "e_HEC3", &master ),
        e_TileBar0( this, ::TString( prefix ) + "e_TileBar0", &master ),
        e_TileBar1( this, ::TString( prefix ) + "e_TileBar1", &master ),
        e_TileBar2( this, ::TString( prefix ) + "e_TileBar2", &master ),
        e_TileGap1( this, ::TString( prefix ) + "e_TileGap1", &master ),
        e_TileGap2( this, ::TString( prefix ) + "e_TileGap2", &master ),
        e_TileGap3( this, ::TString( prefix ) + "e_TileGap3", &master ),
        e_TileExt0( this, ::TString( prefix ) + "e_TileExt0", &master ),
        e_TileExt1( this, ::TString( prefix ) + "e_TileExt1", &master ),
        e_TileExt2( this, ::TString( prefix ) + "e_TileExt2", &master ),
        e_FCAL0( this, ::TString( prefix ) + "e_FCAL0", &master ),
        e_FCAL1( this, ::TString( prefix ) + "e_FCAL1", &master ),
        e_FCAL2( this, ::TString( prefix ) + "e_FCAL2", &master ),
        Nconst( this, ::TString( prefix ) + "Nconst", &master ),
        ptconst_default( this, ::TString( prefix ) + "ptconst_default", &master ),
        econst_default( this, ::TString( prefix ) + "econst_default", &master ),
        etaconst_default( this, ::TString( prefix ) + "etaconst_default", &master ),
        phiconst_default( this, ::TString( prefix ) + "phiconst_default", &master ),
        weightconst_default( this, ::TString( prefix ) + "weightconst_default", &master ),
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
        flavor_component_ip2d_pu( this, ::TString( prefix ) + "flavor_component_ip2d_pu", &master ),
        flavor_component_ip2d_pb( this, ::TString( prefix ) + "flavor_component_ip2d_pb", &master ),
        flavor_component_ip2d_isValid( this, ::TString( prefix ) + "flavor_component_ip2d_isValid", &master ),
        flavor_component_ip2d_ntrk( this, ::TString( prefix ) + "flavor_component_ip2d_ntrk", &master ),
        flavor_component_ip3d_pu( this, ::TString( prefix ) + "flavor_component_ip3d_pu", &master ),
        flavor_component_ip3d_pb( this, ::TString( prefix ) + "flavor_component_ip3d_pb", &master ),
        flavor_component_ip3d_isValid( this, ::TString( prefix ) + "flavor_component_ip3d_isValid", &master ),
        flavor_component_ip3d_ntrk( this, ::TString( prefix ) + "flavor_component_ip3d_ntrk", &master ),
        flavor_component_sv1_pu( this, ::TString( prefix ) + "flavor_component_sv1_pu", &master ),
        flavor_component_sv1_pb( this, ::TString( prefix ) + "flavor_component_sv1_pb", &master ),
        flavor_component_sv1_isValid( this, ::TString( prefix ) + "flavor_component_sv1_isValid", &master ),
        flavor_component_sv2_pu( this, ::TString( prefix ) + "flavor_component_sv2_pu", &master ),
        flavor_component_sv2_pb( this, ::TString( prefix ) + "flavor_component_sv2_pb", &master ),
        flavor_component_sv2_isValid( this, ::TString( prefix ) + "flavor_component_sv2_isValid", &master ),
        flavor_component_jfit_pu( this, ::TString( prefix ) + "flavor_component_jfit_pu", &master ),
        flavor_component_jfit_pb( this, ::TString( prefix ) + "flavor_component_jfit_pb", &master ),
        flavor_component_jfit_pc( this, ::TString( prefix ) + "flavor_component_jfit_pc", &master ),
        flavor_component_jfit_isValid( this, ::TString( prefix ) + "flavor_component_jfit_isValid", &master ),
        flavor_component_jfitcomb_pu( this, ::TString( prefix ) + "flavor_component_jfitcomb_pu", &master ),
        flavor_component_jfitcomb_pb( this, ::TString( prefix ) + "flavor_component_jfitcomb_pb", &master ),
        flavor_component_jfitcomb_pc( this, ::TString( prefix ) + "flavor_component_jfitcomb_pc", &master ),
        flavor_component_jfitcomb_isValid( this, ::TString( prefix ) + "flavor_component_jfitcomb_isValid", &master ),
        flavor_component_jfit_nvtx( this, ::TString( prefix ) + "flavor_component_jfit_nvtx", &master ),
        flavor_component_jfit_nvtx1t( this, ::TString( prefix ) + "flavor_component_jfit_nvtx1t", &master ),
        flavor_component_jfit_ntrkAtVx( this, ::TString( prefix ) + "flavor_component_jfit_ntrkAtVx", &master ),
        flavor_component_jfit_efrc( this, ::TString( prefix ) + "flavor_component_jfit_efrc", &master ),
        flavor_component_jfit_mass( this, ::TString( prefix ) + "flavor_component_jfit_mass", &master ),
        flavor_component_jfit_sig3d( this, ::TString( prefix ) + "flavor_component_jfit_sig3d", &master ),
        flavor_component_jfit_deltaPhi( this, ::TString( prefix ) + "flavor_component_jfit_deltaPhi", &master ),
        flavor_component_jfit_deltaEta( this, ::TString( prefix ) + "flavor_component_jfit_deltaEta", &master ),
        flavor_component_svp_isValid( this, ::TString( prefix ) + "flavor_component_svp_isValid", &master ),
        flavor_component_svp_ntrkv( this, ::TString( prefix ) + "flavor_component_svp_ntrkv", &master ),
        flavor_component_svp_ntrkj( this, ::TString( prefix ) + "flavor_component_svp_ntrkj", &master ),
        flavor_component_svp_n2t( this, ::TString( prefix ) + "flavor_component_svp_n2t", &master ),
        flavor_component_svp_mass( this, ::TString( prefix ) + "flavor_component_svp_mass", &master ),
        flavor_component_svp_efrc( this, ::TString( prefix ) + "flavor_component_svp_efrc", &master ),
        flavor_component_svp_x( this, ::TString( prefix ) + "flavor_component_svp_x", &master ),
        flavor_component_svp_y( this, ::TString( prefix ) + "flavor_component_svp_y", &master ),
        flavor_component_svp_z( this, ::TString( prefix ) + "flavor_component_svp_z", &master ),
        flavor_component_svp_err_x( this, ::TString( prefix ) + "flavor_component_svp_err_x", &master ),
        flavor_component_svp_err_y( this, ::TString( prefix ) + "flavor_component_svp_err_y", &master ),
        flavor_component_svp_err_z( this, ::TString( prefix ) + "flavor_component_svp_err_z", &master ),
        flavor_component_svp_cov_xy( this, ::TString( prefix ) + "flavor_component_svp_cov_xy", &master ),
        flavor_component_svp_cov_xz( this, ::TString( prefix ) + "flavor_component_svp_cov_xz", &master ),
        flavor_component_svp_cov_yz( this, ::TString( prefix ) + "flavor_component_svp_cov_yz", &master ),
        flavor_component_svp_chi2( this, ::TString( prefix ) + "flavor_component_svp_chi2", &master ),
        flavor_component_svp_ndof( this, ::TString( prefix ) + "flavor_component_svp_ndof", &master ),
        flavor_component_svp_ntrk( this, ::TString( prefix ) + "flavor_component_svp_ntrk", &master ),
        flavor_component_sv0p_isValid( this, ::TString( prefix ) + "flavor_component_sv0p_isValid", &master ),
        flavor_component_sv0p_ntrkv( this, ::TString( prefix ) + "flavor_component_sv0p_ntrkv", &master ),
        flavor_component_sv0p_ntrkj( this, ::TString( prefix ) + "flavor_component_sv0p_ntrkj", &master ),
        flavor_component_sv0p_n2t( this, ::TString( prefix ) + "flavor_component_sv0p_n2t", &master ),
        flavor_component_sv0p_mass( this, ::TString( prefix ) + "flavor_component_sv0p_mass", &master ),
        flavor_component_sv0p_efrc( this, ::TString( prefix ) + "flavor_component_sv0p_efrc", &master ),
        flavor_component_sv0p_x( this, ::TString( prefix ) + "flavor_component_sv0p_x", &master ),
        flavor_component_sv0p_y( this, ::TString( prefix ) + "flavor_component_sv0p_y", &master ),
        flavor_component_sv0p_z( this, ::TString( prefix ) + "flavor_component_sv0p_z", &master ),
        flavor_component_sv0p_err_x( this, ::TString( prefix ) + "flavor_component_sv0p_err_x", &master ),
        flavor_component_sv0p_err_y( this, ::TString( prefix ) + "flavor_component_sv0p_err_y", &master ),
        flavor_component_sv0p_err_z( this, ::TString( prefix ) + "flavor_component_sv0p_err_z", &master ),
        flavor_component_sv0p_cov_xy( this, ::TString( prefix ) + "flavor_component_sv0p_cov_xy", &master ),
        flavor_component_sv0p_cov_xz( this, ::TString( prefix ) + "flavor_component_sv0p_cov_xz", &master ),
        flavor_component_sv0p_cov_yz( this, ::TString( prefix ) + "flavor_component_sv0p_cov_yz", &master ),
        flavor_component_sv0p_chi2( this, ::TString( prefix ) + "flavor_component_sv0p_chi2", &master ),
        flavor_component_sv0p_ndof( this, ::TString( prefix ) + "flavor_component_sv0p_ndof", &master ),
        flavor_component_sv0p_ntrk( this, ::TString( prefix ) + "flavor_component_sv0p_ntrk", &master ),
        flavor_assoctrk_n( this, ::TString( prefix ) + "flavor_assoctrk_n", &master ),
        flavor_assoctrk_index( this, ::TString( prefix ) + "flavor_assoctrk_index", &master ),
        el_dr( this, ::TString( prefix ) + "el_dr", &master ),
        el_matched( this, ::TString( prefix ) + "el_matched", &master ),
        mu_dr( this, ::TString( prefix ) + "mu_dr", &master ),
        mu_matched( this, ::TString( prefix ) + "mu_matched", &master ),
        L1_dr( this, ::TString( prefix ) + "L1_dr", &master ),
        L1_matched( this, ::TString( prefix ) + "L1_matched", &master ),
        L2_dr( this, ::TString( prefix ) + "L2_dr", &master ),
        L2_matched( this, ::TString( prefix ) + "L2_matched", &master ),
        EF_dr( this, ::TString( prefix ) + "EF_dr", &master ),
        EF_matched( this, ::TString( prefix ) + "EF_matched", &master ),
        bbDecision( this, ::TString( prefix ) + "bbDecision", &master ),
        SmearingFactor( this, ::TString( prefix ) + "SmearingFactor", &master ),
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
      fHandles[ "MET_LooseEgamma10NoTau_wpx" ] = &MET_LooseEgamma10NoTau_wpx;
      fHandles[ "MET_LooseEgamma10NoTau_wpy" ] = &MET_LooseEgamma10NoTau_wpy;
      fHandles[ "MET_LooseEgamma10NoTau_wet" ] = &MET_LooseEgamma10NoTau_wet;
      fHandles[ "MET_LooseEgamma10NoTau_statusWord" ] = &MET_LooseEgamma10NoTau_statusWord;
      fHandles[ "MET_wpx" ] = &MET_wpx;
      fHandles[ "MET_wpy" ] = &MET_wpy;
      fHandles[ "MET_wet" ] = &MET_wet;
      fHandles[ "MET_statusWord" ] = &MET_statusWord;
      fHandles[ "MET_STVF_wpx" ] = &MET_STVF_wpx;
      fHandles[ "MET_STVF_wpy" ] = &MET_STVF_wpy;
      fHandles[ "MET_STVF_wet" ] = &MET_STVF_wet;
      fHandles[ "MET_STVF_statusWord" ] = &MET_STVF_statusWord;
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
      fHandles[ "WIDTH" ] = &WIDTH;
      fHandles[ "n90" ] = &n90;
      fHandles[ "Timing" ] = &Timing;
      fHandles[ "LArQuality" ] = &LArQuality;
      fHandles[ "nTrk" ] = &nTrk;
      fHandles[ "sumPtTrk" ] = &sumPtTrk;
      fHandles[ "OriginIndex" ] = &OriginIndex;
      fHandles[ "HECQuality" ] = &HECQuality;
      fHandles[ "NegativeE" ] = &NegativeE;
      fHandles[ "AverageLArQF" ] = &AverageLArQF;
      fHandles[ "YFlip12" ] = &YFlip12;
      fHandles[ "YFlip23" ] = &YFlip23;
      fHandles[ "BCH_CORR_CELL" ] = &BCH_CORR_CELL;
      fHandles[ "BCH_CORR_DOTX" ] = &BCH_CORR_DOTX;
      fHandles[ "BCH_CORR_JET" ] = &BCH_CORR_JET;
      fHandles[ "BCH_CORR_JET_FORCELL" ] = &BCH_CORR_JET_FORCELL;
      fHandles[ "ENG_BAD_CELLS" ] = &ENG_BAD_CELLS;
      fHandles[ "N_BAD_CELLS" ] = &N_BAD_CELLS;
      fHandles[ "N_BAD_CELLS_CORR" ] = &N_BAD_CELLS_CORR;
      fHandles[ "BAD_CELLS_CORR_E" ] = &BAD_CELLS_CORR_E;
      fHandles[ "NumTowers" ] = &NumTowers;
      fHandles[ "ootFracCells5" ] = &ootFracCells5;
      fHandles[ "ootFracCells10" ] = &ootFracCells10;
      fHandles[ "ootFracClusters5" ] = &ootFracClusters5;
      fHandles[ "ootFracClusters10" ] = &ootFracClusters10;
      fHandles[ "SamplingMax" ] = &SamplingMax;
      fHandles[ "fracSamplingMax" ] = &fracSamplingMax;
      fHandles[ "hecf" ] = &hecf;
      fHandles[ "tgap3f" ] = &tgap3f;
      fHandles[ "isUgly" ] = &isUgly;
      fHandles[ "isBadLooseMinus" ] = &isBadLooseMinus;
      fHandles[ "isBadLoose" ] = &isBadLoose;
      fHandles[ "isBadMedium" ] = &isBadMedium;
      fHandles[ "isBadTight" ] = &isBadTight;
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
      fHandles[ "e_EMB1" ] = &e_EMB1;
      fHandles[ "e_EMB2" ] = &e_EMB2;
      fHandles[ "e_EMB3" ] = &e_EMB3;
      fHandles[ "e_PreSamplerE" ] = &e_PreSamplerE;
      fHandles[ "e_EME1" ] = &e_EME1;
      fHandles[ "e_EME2" ] = &e_EME2;
      fHandles[ "e_EME3" ] = &e_EME3;
      fHandles[ "e_HEC0" ] = &e_HEC0;
      fHandles[ "e_HEC1" ] = &e_HEC1;
      fHandles[ "e_HEC2" ] = &e_HEC2;
      fHandles[ "e_HEC3" ] = &e_HEC3;
      fHandles[ "e_TileBar0" ] = &e_TileBar0;
      fHandles[ "e_TileBar1" ] = &e_TileBar1;
      fHandles[ "e_TileBar2" ] = &e_TileBar2;
      fHandles[ "e_TileGap1" ] = &e_TileGap1;
      fHandles[ "e_TileGap2" ] = &e_TileGap2;
      fHandles[ "e_TileGap3" ] = &e_TileGap3;
      fHandles[ "e_TileExt0" ] = &e_TileExt0;
      fHandles[ "e_TileExt1" ] = &e_TileExt1;
      fHandles[ "e_TileExt2" ] = &e_TileExt2;
      fHandles[ "e_FCAL0" ] = &e_FCAL0;
      fHandles[ "e_FCAL1" ] = &e_FCAL1;
      fHandles[ "e_FCAL2" ] = &e_FCAL2;
      fHandles[ "Nconst" ] = &Nconst;
      fHandles[ "ptconst_default" ] = &ptconst_default;
      fHandles[ "econst_default" ] = &econst_default;
      fHandles[ "etaconst_default" ] = &etaconst_default;
      fHandles[ "phiconst_default" ] = &phiconst_default;
      fHandles[ "weightconst_default" ] = &weightconst_default;
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
      fHandles[ "flavor_component_ip2d_pu" ] = &flavor_component_ip2d_pu;
      fHandles[ "flavor_component_ip2d_pb" ] = &flavor_component_ip2d_pb;
      fHandles[ "flavor_component_ip2d_isValid" ] = &flavor_component_ip2d_isValid;
      fHandles[ "flavor_component_ip2d_ntrk" ] = &flavor_component_ip2d_ntrk;
      fHandles[ "flavor_component_ip3d_pu" ] = &flavor_component_ip3d_pu;
      fHandles[ "flavor_component_ip3d_pb" ] = &flavor_component_ip3d_pb;
      fHandles[ "flavor_component_ip3d_isValid" ] = &flavor_component_ip3d_isValid;
      fHandles[ "flavor_component_ip3d_ntrk" ] = &flavor_component_ip3d_ntrk;
      fHandles[ "flavor_component_sv1_pu" ] = &flavor_component_sv1_pu;
      fHandles[ "flavor_component_sv1_pb" ] = &flavor_component_sv1_pb;
      fHandles[ "flavor_component_sv1_isValid" ] = &flavor_component_sv1_isValid;
      fHandles[ "flavor_component_sv2_pu" ] = &flavor_component_sv2_pu;
      fHandles[ "flavor_component_sv2_pb" ] = &flavor_component_sv2_pb;
      fHandles[ "flavor_component_sv2_isValid" ] = &flavor_component_sv2_isValid;
      fHandles[ "flavor_component_jfit_pu" ] = &flavor_component_jfit_pu;
      fHandles[ "flavor_component_jfit_pb" ] = &flavor_component_jfit_pb;
      fHandles[ "flavor_component_jfit_pc" ] = &flavor_component_jfit_pc;
      fHandles[ "flavor_component_jfit_isValid" ] = &flavor_component_jfit_isValid;
      fHandles[ "flavor_component_jfitcomb_pu" ] = &flavor_component_jfitcomb_pu;
      fHandles[ "flavor_component_jfitcomb_pb" ] = &flavor_component_jfitcomb_pb;
      fHandles[ "flavor_component_jfitcomb_pc" ] = &flavor_component_jfitcomb_pc;
      fHandles[ "flavor_component_jfitcomb_isValid" ] = &flavor_component_jfitcomb_isValid;
      fHandles[ "flavor_component_jfit_nvtx" ] = &flavor_component_jfit_nvtx;
      fHandles[ "flavor_component_jfit_nvtx1t" ] = &flavor_component_jfit_nvtx1t;
      fHandles[ "flavor_component_jfit_ntrkAtVx" ] = &flavor_component_jfit_ntrkAtVx;
      fHandles[ "flavor_component_jfit_efrc" ] = &flavor_component_jfit_efrc;
      fHandles[ "flavor_component_jfit_mass" ] = &flavor_component_jfit_mass;
      fHandles[ "flavor_component_jfit_sig3d" ] = &flavor_component_jfit_sig3d;
      fHandles[ "flavor_component_jfit_deltaPhi" ] = &flavor_component_jfit_deltaPhi;
      fHandles[ "flavor_component_jfit_deltaEta" ] = &flavor_component_jfit_deltaEta;
      fHandles[ "flavor_component_svp_isValid" ] = &flavor_component_svp_isValid;
      fHandles[ "flavor_component_svp_ntrkv" ] = &flavor_component_svp_ntrkv;
      fHandles[ "flavor_component_svp_ntrkj" ] = &flavor_component_svp_ntrkj;
      fHandles[ "flavor_component_svp_n2t" ] = &flavor_component_svp_n2t;
      fHandles[ "flavor_component_svp_mass" ] = &flavor_component_svp_mass;
      fHandles[ "flavor_component_svp_efrc" ] = &flavor_component_svp_efrc;
      fHandles[ "flavor_component_svp_x" ] = &flavor_component_svp_x;
      fHandles[ "flavor_component_svp_y" ] = &flavor_component_svp_y;
      fHandles[ "flavor_component_svp_z" ] = &flavor_component_svp_z;
      fHandles[ "flavor_component_svp_err_x" ] = &flavor_component_svp_err_x;
      fHandles[ "flavor_component_svp_err_y" ] = &flavor_component_svp_err_y;
      fHandles[ "flavor_component_svp_err_z" ] = &flavor_component_svp_err_z;
      fHandles[ "flavor_component_svp_cov_xy" ] = &flavor_component_svp_cov_xy;
      fHandles[ "flavor_component_svp_cov_xz" ] = &flavor_component_svp_cov_xz;
      fHandles[ "flavor_component_svp_cov_yz" ] = &flavor_component_svp_cov_yz;
      fHandles[ "flavor_component_svp_chi2" ] = &flavor_component_svp_chi2;
      fHandles[ "flavor_component_svp_ndof" ] = &flavor_component_svp_ndof;
      fHandles[ "flavor_component_svp_ntrk" ] = &flavor_component_svp_ntrk;
      fHandles[ "flavor_component_sv0p_isValid" ] = &flavor_component_sv0p_isValid;
      fHandles[ "flavor_component_sv0p_ntrkv" ] = &flavor_component_sv0p_ntrkv;
      fHandles[ "flavor_component_sv0p_ntrkj" ] = &flavor_component_sv0p_ntrkj;
      fHandles[ "flavor_component_sv0p_n2t" ] = &flavor_component_sv0p_n2t;
      fHandles[ "flavor_component_sv0p_mass" ] = &flavor_component_sv0p_mass;
      fHandles[ "flavor_component_sv0p_efrc" ] = &flavor_component_sv0p_efrc;
      fHandles[ "flavor_component_sv0p_x" ] = &flavor_component_sv0p_x;
      fHandles[ "flavor_component_sv0p_y" ] = &flavor_component_sv0p_y;
      fHandles[ "flavor_component_sv0p_z" ] = &flavor_component_sv0p_z;
      fHandles[ "flavor_component_sv0p_err_x" ] = &flavor_component_sv0p_err_x;
      fHandles[ "flavor_component_sv0p_err_y" ] = &flavor_component_sv0p_err_y;
      fHandles[ "flavor_component_sv0p_err_z" ] = &flavor_component_sv0p_err_z;
      fHandles[ "flavor_component_sv0p_cov_xy" ] = &flavor_component_sv0p_cov_xy;
      fHandles[ "flavor_component_sv0p_cov_xz" ] = &flavor_component_sv0p_cov_xz;
      fHandles[ "flavor_component_sv0p_cov_yz" ] = &flavor_component_sv0p_cov_yz;
      fHandles[ "flavor_component_sv0p_chi2" ] = &flavor_component_sv0p_chi2;
      fHandles[ "flavor_component_sv0p_ndof" ] = &flavor_component_sv0p_ndof;
      fHandles[ "flavor_component_sv0p_ntrk" ] = &flavor_component_sv0p_ntrk;
      fHandles[ "flavor_assoctrk_n" ] = &flavor_assoctrk_n;
      fHandles[ "flavor_assoctrk_index" ] = &flavor_assoctrk_index;
      fHandles[ "el_dr" ] = &el_dr;
      fHandles[ "el_matched" ] = &el_matched;
      fHandles[ "mu_dr" ] = &mu_dr;
      fHandles[ "mu_matched" ] = &mu_matched;
      fHandles[ "L1_dr" ] = &L1_dr;
      fHandles[ "L1_matched" ] = &L1_matched;
      fHandles[ "L2_dr" ] = &L2_dr;
      fHandles[ "L2_matched" ] = &L2_matched;
      fHandles[ "EF_dr" ] = &EF_dr;
      fHandles[ "EF_matched" ] = &EF_matched;
      fHandles[ "bbDecision" ] = &bbDecision;
      fHandles[ "SmearingFactor" ] = &SmearingFactor;
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
        MET_LooseEgamma10NoTau_wpx( this, ::TString( prefix ) + "MET_LooseEgamma10NoTau_wpx", 0 ),
        MET_LooseEgamma10NoTau_wpy( this, ::TString( prefix ) + "MET_LooseEgamma10NoTau_wpy", 0 ),
        MET_LooseEgamma10NoTau_wet( this, ::TString( prefix ) + "MET_LooseEgamma10NoTau_wet", 0 ),
        MET_LooseEgamma10NoTau_statusWord( this, ::TString( prefix ) + "MET_LooseEgamma10NoTau_statusWord", 0 ),
        MET_wpx( this, ::TString( prefix ) + "MET_wpx", 0 ),
        MET_wpy( this, ::TString( prefix ) + "MET_wpy", 0 ),
        MET_wet( this, ::TString( prefix ) + "MET_wet", 0 ),
        MET_statusWord( this, ::TString( prefix ) + "MET_statusWord", 0 ),
        MET_STVF_wpx( this, ::TString( prefix ) + "MET_STVF_wpx", 0 ),
        MET_STVF_wpy( this, ::TString( prefix ) + "MET_STVF_wpy", 0 ),
        MET_STVF_wet( this, ::TString( prefix ) + "MET_STVF_wet", 0 ),
        MET_STVF_statusWord( this, ::TString( prefix ) + "MET_STVF_statusWord", 0 ),
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
        WIDTH( this, ::TString( prefix ) + "WIDTH", 0 ),
        n90( this, ::TString( prefix ) + "n90", 0 ),
        Timing( this, ::TString( prefix ) + "Timing", 0 ),
        LArQuality( this, ::TString( prefix ) + "LArQuality", 0 ),
        nTrk( this, ::TString( prefix ) + "nTrk", 0 ),
        sumPtTrk( this, ::TString( prefix ) + "sumPtTrk", 0 ),
        OriginIndex( this, ::TString( prefix ) + "OriginIndex", 0 ),
        HECQuality( this, ::TString( prefix ) + "HECQuality", 0 ),
        NegativeE( this, ::TString( prefix ) + "NegativeE", 0 ),
        AverageLArQF( this, ::TString( prefix ) + "AverageLArQF", 0 ),
        YFlip12( this, ::TString( prefix ) + "YFlip12", 0 ),
        YFlip23( this, ::TString( prefix ) + "YFlip23", 0 ),
        BCH_CORR_CELL( this, ::TString( prefix ) + "BCH_CORR_CELL", 0 ),
        BCH_CORR_DOTX( this, ::TString( prefix ) + "BCH_CORR_DOTX", 0 ),
        BCH_CORR_JET( this, ::TString( prefix ) + "BCH_CORR_JET", 0 ),
        BCH_CORR_JET_FORCELL( this, ::TString( prefix ) + "BCH_CORR_JET_FORCELL", 0 ),
        ENG_BAD_CELLS( this, ::TString( prefix ) + "ENG_BAD_CELLS", 0 ),
        N_BAD_CELLS( this, ::TString( prefix ) + "N_BAD_CELLS", 0 ),
        N_BAD_CELLS_CORR( this, ::TString( prefix ) + "N_BAD_CELLS_CORR", 0 ),
        BAD_CELLS_CORR_E( this, ::TString( prefix ) + "BAD_CELLS_CORR_E", 0 ),
        NumTowers( this, ::TString( prefix ) + "NumTowers", 0 ),
        ootFracCells5( this, ::TString( prefix ) + "ootFracCells5", 0 ),
        ootFracCells10( this, ::TString( prefix ) + "ootFracCells10", 0 ),
        ootFracClusters5( this, ::TString( prefix ) + "ootFracClusters5", 0 ),
        ootFracClusters10( this, ::TString( prefix ) + "ootFracClusters10", 0 ),
        SamplingMax( this, ::TString( prefix ) + "SamplingMax", 0 ),
        fracSamplingMax( this, ::TString( prefix ) + "fracSamplingMax", 0 ),
        hecf( this, ::TString( prefix ) + "hecf", 0 ),
        tgap3f( this, ::TString( prefix ) + "tgap3f", 0 ),
        isUgly( this, ::TString( prefix ) + "isUgly", 0 ),
        isBadLooseMinus( this, ::TString( prefix ) + "isBadLooseMinus", 0 ),
        isBadLoose( this, ::TString( prefix ) + "isBadLoose", 0 ),
        isBadMedium( this, ::TString( prefix ) + "isBadMedium", 0 ),
        isBadTight( this, ::TString( prefix ) + "isBadTight", 0 ),
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
        e_EMB1( this, ::TString( prefix ) + "e_EMB1", 0 ),
        e_EMB2( this, ::TString( prefix ) + "e_EMB2", 0 ),
        e_EMB3( this, ::TString( prefix ) + "e_EMB3", 0 ),
        e_PreSamplerE( this, ::TString( prefix ) + "e_PreSamplerE", 0 ),
        e_EME1( this, ::TString( prefix ) + "e_EME1", 0 ),
        e_EME2( this, ::TString( prefix ) + "e_EME2", 0 ),
        e_EME3( this, ::TString( prefix ) + "e_EME3", 0 ),
        e_HEC0( this, ::TString( prefix ) + "e_HEC0", 0 ),
        e_HEC1( this, ::TString( prefix ) + "e_HEC1", 0 ),
        e_HEC2( this, ::TString( prefix ) + "e_HEC2", 0 ),
        e_HEC3( this, ::TString( prefix ) + "e_HEC3", 0 ),
        e_TileBar0( this, ::TString( prefix ) + "e_TileBar0", 0 ),
        e_TileBar1( this, ::TString( prefix ) + "e_TileBar1", 0 ),
        e_TileBar2( this, ::TString( prefix ) + "e_TileBar2", 0 ),
        e_TileGap1( this, ::TString( prefix ) + "e_TileGap1", 0 ),
        e_TileGap2( this, ::TString( prefix ) + "e_TileGap2", 0 ),
        e_TileGap3( this, ::TString( prefix ) + "e_TileGap3", 0 ),
        e_TileExt0( this, ::TString( prefix ) + "e_TileExt0", 0 ),
        e_TileExt1( this, ::TString( prefix ) + "e_TileExt1", 0 ),
        e_TileExt2( this, ::TString( prefix ) + "e_TileExt2", 0 ),
        e_FCAL0( this, ::TString( prefix ) + "e_FCAL0", 0 ),
        e_FCAL1( this, ::TString( prefix ) + "e_FCAL1", 0 ),
        e_FCAL2( this, ::TString( prefix ) + "e_FCAL2", 0 ),
        Nconst( this, ::TString( prefix ) + "Nconst", 0 ),
        ptconst_default( this, ::TString( prefix ) + "ptconst_default", 0 ),
        econst_default( this, ::TString( prefix ) + "econst_default", 0 ),
        etaconst_default( this, ::TString( prefix ) + "etaconst_default", 0 ),
        phiconst_default( this, ::TString( prefix ) + "phiconst_default", 0 ),
        weightconst_default( this, ::TString( prefix ) + "weightconst_default", 0 ),
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
        flavor_component_ip2d_pu( this, ::TString( prefix ) + "flavor_component_ip2d_pu", 0 ),
        flavor_component_ip2d_pb( this, ::TString( prefix ) + "flavor_component_ip2d_pb", 0 ),
        flavor_component_ip2d_isValid( this, ::TString( prefix ) + "flavor_component_ip2d_isValid", 0 ),
        flavor_component_ip2d_ntrk( this, ::TString( prefix ) + "flavor_component_ip2d_ntrk", 0 ),
        flavor_component_ip3d_pu( this, ::TString( prefix ) + "flavor_component_ip3d_pu", 0 ),
        flavor_component_ip3d_pb( this, ::TString( prefix ) + "flavor_component_ip3d_pb", 0 ),
        flavor_component_ip3d_isValid( this, ::TString( prefix ) + "flavor_component_ip3d_isValid", 0 ),
        flavor_component_ip3d_ntrk( this, ::TString( prefix ) + "flavor_component_ip3d_ntrk", 0 ),
        flavor_component_sv1_pu( this, ::TString( prefix ) + "flavor_component_sv1_pu", 0 ),
        flavor_component_sv1_pb( this, ::TString( prefix ) + "flavor_component_sv1_pb", 0 ),
        flavor_component_sv1_isValid( this, ::TString( prefix ) + "flavor_component_sv1_isValid", 0 ),
        flavor_component_sv2_pu( this, ::TString( prefix ) + "flavor_component_sv2_pu", 0 ),
        flavor_component_sv2_pb( this, ::TString( prefix ) + "flavor_component_sv2_pb", 0 ),
        flavor_component_sv2_isValid( this, ::TString( prefix ) + "flavor_component_sv2_isValid", 0 ),
        flavor_component_jfit_pu( this, ::TString( prefix ) + "flavor_component_jfit_pu", 0 ),
        flavor_component_jfit_pb( this, ::TString( prefix ) + "flavor_component_jfit_pb", 0 ),
        flavor_component_jfit_pc( this, ::TString( prefix ) + "flavor_component_jfit_pc", 0 ),
        flavor_component_jfit_isValid( this, ::TString( prefix ) + "flavor_component_jfit_isValid", 0 ),
        flavor_component_jfitcomb_pu( this, ::TString( prefix ) + "flavor_component_jfitcomb_pu", 0 ),
        flavor_component_jfitcomb_pb( this, ::TString( prefix ) + "flavor_component_jfitcomb_pb", 0 ),
        flavor_component_jfitcomb_pc( this, ::TString( prefix ) + "flavor_component_jfitcomb_pc", 0 ),
        flavor_component_jfitcomb_isValid( this, ::TString( prefix ) + "flavor_component_jfitcomb_isValid", 0 ),
        flavor_component_jfit_nvtx( this, ::TString( prefix ) + "flavor_component_jfit_nvtx", 0 ),
        flavor_component_jfit_nvtx1t( this, ::TString( prefix ) + "flavor_component_jfit_nvtx1t", 0 ),
        flavor_component_jfit_ntrkAtVx( this, ::TString( prefix ) + "flavor_component_jfit_ntrkAtVx", 0 ),
        flavor_component_jfit_efrc( this, ::TString( prefix ) + "flavor_component_jfit_efrc", 0 ),
        flavor_component_jfit_mass( this, ::TString( prefix ) + "flavor_component_jfit_mass", 0 ),
        flavor_component_jfit_sig3d( this, ::TString( prefix ) + "flavor_component_jfit_sig3d", 0 ),
        flavor_component_jfit_deltaPhi( this, ::TString( prefix ) + "flavor_component_jfit_deltaPhi", 0 ),
        flavor_component_jfit_deltaEta( this, ::TString( prefix ) + "flavor_component_jfit_deltaEta", 0 ),
        flavor_component_svp_isValid( this, ::TString( prefix ) + "flavor_component_svp_isValid", 0 ),
        flavor_component_svp_ntrkv( this, ::TString( prefix ) + "flavor_component_svp_ntrkv", 0 ),
        flavor_component_svp_ntrkj( this, ::TString( prefix ) + "flavor_component_svp_ntrkj", 0 ),
        flavor_component_svp_n2t( this, ::TString( prefix ) + "flavor_component_svp_n2t", 0 ),
        flavor_component_svp_mass( this, ::TString( prefix ) + "flavor_component_svp_mass", 0 ),
        flavor_component_svp_efrc( this, ::TString( prefix ) + "flavor_component_svp_efrc", 0 ),
        flavor_component_svp_x( this, ::TString( prefix ) + "flavor_component_svp_x", 0 ),
        flavor_component_svp_y( this, ::TString( prefix ) + "flavor_component_svp_y", 0 ),
        flavor_component_svp_z( this, ::TString( prefix ) + "flavor_component_svp_z", 0 ),
        flavor_component_svp_err_x( this, ::TString( prefix ) + "flavor_component_svp_err_x", 0 ),
        flavor_component_svp_err_y( this, ::TString( prefix ) + "flavor_component_svp_err_y", 0 ),
        flavor_component_svp_err_z( this, ::TString( prefix ) + "flavor_component_svp_err_z", 0 ),
        flavor_component_svp_cov_xy( this, ::TString( prefix ) + "flavor_component_svp_cov_xy", 0 ),
        flavor_component_svp_cov_xz( this, ::TString( prefix ) + "flavor_component_svp_cov_xz", 0 ),
        flavor_component_svp_cov_yz( this, ::TString( prefix ) + "flavor_component_svp_cov_yz", 0 ),
        flavor_component_svp_chi2( this, ::TString( prefix ) + "flavor_component_svp_chi2", 0 ),
        flavor_component_svp_ndof( this, ::TString( prefix ) + "flavor_component_svp_ndof", 0 ),
        flavor_component_svp_ntrk( this, ::TString( prefix ) + "flavor_component_svp_ntrk", 0 ),
        flavor_component_sv0p_isValid( this, ::TString( prefix ) + "flavor_component_sv0p_isValid", 0 ),
        flavor_component_sv0p_ntrkv( this, ::TString( prefix ) + "flavor_component_sv0p_ntrkv", 0 ),
        flavor_component_sv0p_ntrkj( this, ::TString( prefix ) + "flavor_component_sv0p_ntrkj", 0 ),
        flavor_component_sv0p_n2t( this, ::TString( prefix ) + "flavor_component_sv0p_n2t", 0 ),
        flavor_component_sv0p_mass( this, ::TString( prefix ) + "flavor_component_sv0p_mass", 0 ),
        flavor_component_sv0p_efrc( this, ::TString( prefix ) + "flavor_component_sv0p_efrc", 0 ),
        flavor_component_sv0p_x( this, ::TString( prefix ) + "flavor_component_sv0p_x", 0 ),
        flavor_component_sv0p_y( this, ::TString( prefix ) + "flavor_component_sv0p_y", 0 ),
        flavor_component_sv0p_z( this, ::TString( prefix ) + "flavor_component_sv0p_z", 0 ),
        flavor_component_sv0p_err_x( this, ::TString( prefix ) + "flavor_component_sv0p_err_x", 0 ),
        flavor_component_sv0p_err_y( this, ::TString( prefix ) + "flavor_component_sv0p_err_y", 0 ),
        flavor_component_sv0p_err_z( this, ::TString( prefix ) + "flavor_component_sv0p_err_z", 0 ),
        flavor_component_sv0p_cov_xy( this, ::TString( prefix ) + "flavor_component_sv0p_cov_xy", 0 ),
        flavor_component_sv0p_cov_xz( this, ::TString( prefix ) + "flavor_component_sv0p_cov_xz", 0 ),
        flavor_component_sv0p_cov_yz( this, ::TString( prefix ) + "flavor_component_sv0p_cov_yz", 0 ),
        flavor_component_sv0p_chi2( this, ::TString( prefix ) + "flavor_component_sv0p_chi2", 0 ),
        flavor_component_sv0p_ndof( this, ::TString( prefix ) + "flavor_component_sv0p_ndof", 0 ),
        flavor_component_sv0p_ntrk( this, ::TString( prefix ) + "flavor_component_sv0p_ntrk", 0 ),
        flavor_assoctrk_n( this, ::TString( prefix ) + "flavor_assoctrk_n", 0 ),
        flavor_assoctrk_index( this, ::TString( prefix ) + "flavor_assoctrk_index", 0 ),
        el_dr( this, ::TString( prefix ) + "el_dr", 0 ),
        el_matched( this, ::TString( prefix ) + "el_matched", 0 ),
        mu_dr( this, ::TString( prefix ) + "mu_dr", 0 ),
        mu_matched( this, ::TString( prefix ) + "mu_matched", 0 ),
        L1_dr( this, ::TString( prefix ) + "L1_dr", 0 ),
        L1_matched( this, ::TString( prefix ) + "L1_matched", 0 ),
        L2_dr( this, ::TString( prefix ) + "L2_dr", 0 ),
        L2_matched( this, ::TString( prefix ) + "L2_matched", 0 ),
        EF_dr( this, ::TString( prefix ) + "EF_dr", 0 ),
        EF_matched( this, ::TString( prefix ) + "EF_matched", 0 ),
        bbDecision( this, ::TString( prefix ) + "bbDecision", 0 ),
        SmearingFactor( this, ::TString( prefix ) + "SmearingFactor", 0 ),
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
      fHandles[ "MET_LooseEgamma10NoTau_wpx" ] = &MET_LooseEgamma10NoTau_wpx;
      fHandles[ "MET_LooseEgamma10NoTau_wpy" ] = &MET_LooseEgamma10NoTau_wpy;
      fHandles[ "MET_LooseEgamma10NoTau_wet" ] = &MET_LooseEgamma10NoTau_wet;
      fHandles[ "MET_LooseEgamma10NoTau_statusWord" ] = &MET_LooseEgamma10NoTau_statusWord;
      fHandles[ "MET_wpx" ] = &MET_wpx;
      fHandles[ "MET_wpy" ] = &MET_wpy;
      fHandles[ "MET_wet" ] = &MET_wet;
      fHandles[ "MET_statusWord" ] = &MET_statusWord;
      fHandles[ "MET_STVF_wpx" ] = &MET_STVF_wpx;
      fHandles[ "MET_STVF_wpy" ] = &MET_STVF_wpy;
      fHandles[ "MET_STVF_wet" ] = &MET_STVF_wet;
      fHandles[ "MET_STVF_statusWord" ] = &MET_STVF_statusWord;
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
      fHandles[ "WIDTH" ] = &WIDTH;
      fHandles[ "n90" ] = &n90;
      fHandles[ "Timing" ] = &Timing;
      fHandles[ "LArQuality" ] = &LArQuality;
      fHandles[ "nTrk" ] = &nTrk;
      fHandles[ "sumPtTrk" ] = &sumPtTrk;
      fHandles[ "OriginIndex" ] = &OriginIndex;
      fHandles[ "HECQuality" ] = &HECQuality;
      fHandles[ "NegativeE" ] = &NegativeE;
      fHandles[ "AverageLArQF" ] = &AverageLArQF;
      fHandles[ "YFlip12" ] = &YFlip12;
      fHandles[ "YFlip23" ] = &YFlip23;
      fHandles[ "BCH_CORR_CELL" ] = &BCH_CORR_CELL;
      fHandles[ "BCH_CORR_DOTX" ] = &BCH_CORR_DOTX;
      fHandles[ "BCH_CORR_JET" ] = &BCH_CORR_JET;
      fHandles[ "BCH_CORR_JET_FORCELL" ] = &BCH_CORR_JET_FORCELL;
      fHandles[ "ENG_BAD_CELLS" ] = &ENG_BAD_CELLS;
      fHandles[ "N_BAD_CELLS" ] = &N_BAD_CELLS;
      fHandles[ "N_BAD_CELLS_CORR" ] = &N_BAD_CELLS_CORR;
      fHandles[ "BAD_CELLS_CORR_E" ] = &BAD_CELLS_CORR_E;
      fHandles[ "NumTowers" ] = &NumTowers;
      fHandles[ "ootFracCells5" ] = &ootFracCells5;
      fHandles[ "ootFracCells10" ] = &ootFracCells10;
      fHandles[ "ootFracClusters5" ] = &ootFracClusters5;
      fHandles[ "ootFracClusters10" ] = &ootFracClusters10;
      fHandles[ "SamplingMax" ] = &SamplingMax;
      fHandles[ "fracSamplingMax" ] = &fracSamplingMax;
      fHandles[ "hecf" ] = &hecf;
      fHandles[ "tgap3f" ] = &tgap3f;
      fHandles[ "isUgly" ] = &isUgly;
      fHandles[ "isBadLooseMinus" ] = &isBadLooseMinus;
      fHandles[ "isBadLoose" ] = &isBadLoose;
      fHandles[ "isBadMedium" ] = &isBadMedium;
      fHandles[ "isBadTight" ] = &isBadTight;
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
      fHandles[ "e_EMB1" ] = &e_EMB1;
      fHandles[ "e_EMB2" ] = &e_EMB2;
      fHandles[ "e_EMB3" ] = &e_EMB3;
      fHandles[ "e_PreSamplerE" ] = &e_PreSamplerE;
      fHandles[ "e_EME1" ] = &e_EME1;
      fHandles[ "e_EME2" ] = &e_EME2;
      fHandles[ "e_EME3" ] = &e_EME3;
      fHandles[ "e_HEC0" ] = &e_HEC0;
      fHandles[ "e_HEC1" ] = &e_HEC1;
      fHandles[ "e_HEC2" ] = &e_HEC2;
      fHandles[ "e_HEC3" ] = &e_HEC3;
      fHandles[ "e_TileBar0" ] = &e_TileBar0;
      fHandles[ "e_TileBar1" ] = &e_TileBar1;
      fHandles[ "e_TileBar2" ] = &e_TileBar2;
      fHandles[ "e_TileGap1" ] = &e_TileGap1;
      fHandles[ "e_TileGap2" ] = &e_TileGap2;
      fHandles[ "e_TileGap3" ] = &e_TileGap3;
      fHandles[ "e_TileExt0" ] = &e_TileExt0;
      fHandles[ "e_TileExt1" ] = &e_TileExt1;
      fHandles[ "e_TileExt2" ] = &e_TileExt2;
      fHandles[ "e_FCAL0" ] = &e_FCAL0;
      fHandles[ "e_FCAL1" ] = &e_FCAL1;
      fHandles[ "e_FCAL2" ] = &e_FCAL2;
      fHandles[ "Nconst" ] = &Nconst;
      fHandles[ "ptconst_default" ] = &ptconst_default;
      fHandles[ "econst_default" ] = &econst_default;
      fHandles[ "etaconst_default" ] = &etaconst_default;
      fHandles[ "phiconst_default" ] = &phiconst_default;
      fHandles[ "weightconst_default" ] = &weightconst_default;
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
      fHandles[ "flavor_component_ip2d_pu" ] = &flavor_component_ip2d_pu;
      fHandles[ "flavor_component_ip2d_pb" ] = &flavor_component_ip2d_pb;
      fHandles[ "flavor_component_ip2d_isValid" ] = &flavor_component_ip2d_isValid;
      fHandles[ "flavor_component_ip2d_ntrk" ] = &flavor_component_ip2d_ntrk;
      fHandles[ "flavor_component_ip3d_pu" ] = &flavor_component_ip3d_pu;
      fHandles[ "flavor_component_ip3d_pb" ] = &flavor_component_ip3d_pb;
      fHandles[ "flavor_component_ip3d_isValid" ] = &flavor_component_ip3d_isValid;
      fHandles[ "flavor_component_ip3d_ntrk" ] = &flavor_component_ip3d_ntrk;
      fHandles[ "flavor_component_sv1_pu" ] = &flavor_component_sv1_pu;
      fHandles[ "flavor_component_sv1_pb" ] = &flavor_component_sv1_pb;
      fHandles[ "flavor_component_sv1_isValid" ] = &flavor_component_sv1_isValid;
      fHandles[ "flavor_component_sv2_pu" ] = &flavor_component_sv2_pu;
      fHandles[ "flavor_component_sv2_pb" ] = &flavor_component_sv2_pb;
      fHandles[ "flavor_component_sv2_isValid" ] = &flavor_component_sv2_isValid;
      fHandles[ "flavor_component_jfit_pu" ] = &flavor_component_jfit_pu;
      fHandles[ "flavor_component_jfit_pb" ] = &flavor_component_jfit_pb;
      fHandles[ "flavor_component_jfit_pc" ] = &flavor_component_jfit_pc;
      fHandles[ "flavor_component_jfit_isValid" ] = &flavor_component_jfit_isValid;
      fHandles[ "flavor_component_jfitcomb_pu" ] = &flavor_component_jfitcomb_pu;
      fHandles[ "flavor_component_jfitcomb_pb" ] = &flavor_component_jfitcomb_pb;
      fHandles[ "flavor_component_jfitcomb_pc" ] = &flavor_component_jfitcomb_pc;
      fHandles[ "flavor_component_jfitcomb_isValid" ] = &flavor_component_jfitcomb_isValid;
      fHandles[ "flavor_component_jfit_nvtx" ] = &flavor_component_jfit_nvtx;
      fHandles[ "flavor_component_jfit_nvtx1t" ] = &flavor_component_jfit_nvtx1t;
      fHandles[ "flavor_component_jfit_ntrkAtVx" ] = &flavor_component_jfit_ntrkAtVx;
      fHandles[ "flavor_component_jfit_efrc" ] = &flavor_component_jfit_efrc;
      fHandles[ "flavor_component_jfit_mass" ] = &flavor_component_jfit_mass;
      fHandles[ "flavor_component_jfit_sig3d" ] = &flavor_component_jfit_sig3d;
      fHandles[ "flavor_component_jfit_deltaPhi" ] = &flavor_component_jfit_deltaPhi;
      fHandles[ "flavor_component_jfit_deltaEta" ] = &flavor_component_jfit_deltaEta;
      fHandles[ "flavor_component_svp_isValid" ] = &flavor_component_svp_isValid;
      fHandles[ "flavor_component_svp_ntrkv" ] = &flavor_component_svp_ntrkv;
      fHandles[ "flavor_component_svp_ntrkj" ] = &flavor_component_svp_ntrkj;
      fHandles[ "flavor_component_svp_n2t" ] = &flavor_component_svp_n2t;
      fHandles[ "flavor_component_svp_mass" ] = &flavor_component_svp_mass;
      fHandles[ "flavor_component_svp_efrc" ] = &flavor_component_svp_efrc;
      fHandles[ "flavor_component_svp_x" ] = &flavor_component_svp_x;
      fHandles[ "flavor_component_svp_y" ] = &flavor_component_svp_y;
      fHandles[ "flavor_component_svp_z" ] = &flavor_component_svp_z;
      fHandles[ "flavor_component_svp_err_x" ] = &flavor_component_svp_err_x;
      fHandles[ "flavor_component_svp_err_y" ] = &flavor_component_svp_err_y;
      fHandles[ "flavor_component_svp_err_z" ] = &flavor_component_svp_err_z;
      fHandles[ "flavor_component_svp_cov_xy" ] = &flavor_component_svp_cov_xy;
      fHandles[ "flavor_component_svp_cov_xz" ] = &flavor_component_svp_cov_xz;
      fHandles[ "flavor_component_svp_cov_yz" ] = &flavor_component_svp_cov_yz;
      fHandles[ "flavor_component_svp_chi2" ] = &flavor_component_svp_chi2;
      fHandles[ "flavor_component_svp_ndof" ] = &flavor_component_svp_ndof;
      fHandles[ "flavor_component_svp_ntrk" ] = &flavor_component_svp_ntrk;
      fHandles[ "flavor_component_sv0p_isValid" ] = &flavor_component_sv0p_isValid;
      fHandles[ "flavor_component_sv0p_ntrkv" ] = &flavor_component_sv0p_ntrkv;
      fHandles[ "flavor_component_sv0p_ntrkj" ] = &flavor_component_sv0p_ntrkj;
      fHandles[ "flavor_component_sv0p_n2t" ] = &flavor_component_sv0p_n2t;
      fHandles[ "flavor_component_sv0p_mass" ] = &flavor_component_sv0p_mass;
      fHandles[ "flavor_component_sv0p_efrc" ] = &flavor_component_sv0p_efrc;
      fHandles[ "flavor_component_sv0p_x" ] = &flavor_component_sv0p_x;
      fHandles[ "flavor_component_sv0p_y" ] = &flavor_component_sv0p_y;
      fHandles[ "flavor_component_sv0p_z" ] = &flavor_component_sv0p_z;
      fHandles[ "flavor_component_sv0p_err_x" ] = &flavor_component_sv0p_err_x;
      fHandles[ "flavor_component_sv0p_err_y" ] = &flavor_component_sv0p_err_y;
      fHandles[ "flavor_component_sv0p_err_z" ] = &flavor_component_sv0p_err_z;
      fHandles[ "flavor_component_sv0p_cov_xy" ] = &flavor_component_sv0p_cov_xy;
      fHandles[ "flavor_component_sv0p_cov_xz" ] = &flavor_component_sv0p_cov_xz;
      fHandles[ "flavor_component_sv0p_cov_yz" ] = &flavor_component_sv0p_cov_yz;
      fHandles[ "flavor_component_sv0p_chi2" ] = &flavor_component_sv0p_chi2;
      fHandles[ "flavor_component_sv0p_ndof" ] = &flavor_component_sv0p_ndof;
      fHandles[ "flavor_component_sv0p_ntrk" ] = &flavor_component_sv0p_ntrk;
      fHandles[ "flavor_assoctrk_n" ] = &flavor_assoctrk_n;
      fHandles[ "flavor_assoctrk_index" ] = &flavor_assoctrk_index;
      fHandles[ "el_dr" ] = &el_dr;
      fHandles[ "el_matched" ] = &el_matched;
      fHandles[ "mu_dr" ] = &mu_dr;
      fHandles[ "mu_matched" ] = &mu_matched;
      fHandles[ "L1_dr" ] = &L1_dr;
      fHandles[ "L1_matched" ] = &L1_matched;
      fHandles[ "L2_dr" ] = &L2_dr;
      fHandles[ "L2_matched" ] = &L2_matched;
      fHandles[ "EF_dr" ] = &EF_dr;
      fHandles[ "EF_matched" ] = &EF_matched;
      fHandles[ "bbDecision" ] = &bbDecision;
      fHandles[ "SmearingFactor" ] = &SmearingFactor;
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
      MET_LooseEgamma10NoTau_wpx.SetName( ::TString( prefix ) + "MET_LooseEgamma10NoTau_wpx" );
      MET_LooseEgamma10NoTau_wpy.SetName( ::TString( prefix ) + "MET_LooseEgamma10NoTau_wpy" );
      MET_LooseEgamma10NoTau_wet.SetName( ::TString( prefix ) + "MET_LooseEgamma10NoTau_wet" );
      MET_LooseEgamma10NoTau_statusWord.SetName( ::TString( prefix ) + "MET_LooseEgamma10NoTau_statusWord" );
      MET_wpx.SetName( ::TString( prefix ) + "MET_wpx" );
      MET_wpy.SetName( ::TString( prefix ) + "MET_wpy" );
      MET_wet.SetName( ::TString( prefix ) + "MET_wet" );
      MET_statusWord.SetName( ::TString( prefix ) + "MET_statusWord" );
      MET_STVF_wpx.SetName( ::TString( prefix ) + "MET_STVF_wpx" );
      MET_STVF_wpy.SetName( ::TString( prefix ) + "MET_STVF_wpy" );
      MET_STVF_wet.SetName( ::TString( prefix ) + "MET_STVF_wet" );
      MET_STVF_statusWord.SetName( ::TString( prefix ) + "MET_STVF_statusWord" );
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
      WIDTH.SetName( ::TString( prefix ) + "WIDTH" );
      n90.SetName( ::TString( prefix ) + "n90" );
      Timing.SetName( ::TString( prefix ) + "Timing" );
      LArQuality.SetName( ::TString( prefix ) + "LArQuality" );
      nTrk.SetName( ::TString( prefix ) + "nTrk" );
      sumPtTrk.SetName( ::TString( prefix ) + "sumPtTrk" );
      OriginIndex.SetName( ::TString( prefix ) + "OriginIndex" );
      HECQuality.SetName( ::TString( prefix ) + "HECQuality" );
      NegativeE.SetName( ::TString( prefix ) + "NegativeE" );
      AverageLArQF.SetName( ::TString( prefix ) + "AverageLArQF" );
      YFlip12.SetName( ::TString( prefix ) + "YFlip12" );
      YFlip23.SetName( ::TString( prefix ) + "YFlip23" );
      BCH_CORR_CELL.SetName( ::TString( prefix ) + "BCH_CORR_CELL" );
      BCH_CORR_DOTX.SetName( ::TString( prefix ) + "BCH_CORR_DOTX" );
      BCH_CORR_JET.SetName( ::TString( prefix ) + "BCH_CORR_JET" );
      BCH_CORR_JET_FORCELL.SetName( ::TString( prefix ) + "BCH_CORR_JET_FORCELL" );
      ENG_BAD_CELLS.SetName( ::TString( prefix ) + "ENG_BAD_CELLS" );
      N_BAD_CELLS.SetName( ::TString( prefix ) + "N_BAD_CELLS" );
      N_BAD_CELLS_CORR.SetName( ::TString( prefix ) + "N_BAD_CELLS_CORR" );
      BAD_CELLS_CORR_E.SetName( ::TString( prefix ) + "BAD_CELLS_CORR_E" );
      NumTowers.SetName( ::TString( prefix ) + "NumTowers" );
      ootFracCells5.SetName( ::TString( prefix ) + "ootFracCells5" );
      ootFracCells10.SetName( ::TString( prefix ) + "ootFracCells10" );
      ootFracClusters5.SetName( ::TString( prefix ) + "ootFracClusters5" );
      ootFracClusters10.SetName( ::TString( prefix ) + "ootFracClusters10" );
      SamplingMax.SetName( ::TString( prefix ) + "SamplingMax" );
      fracSamplingMax.SetName( ::TString( prefix ) + "fracSamplingMax" );
      hecf.SetName( ::TString( prefix ) + "hecf" );
      tgap3f.SetName( ::TString( prefix ) + "tgap3f" );
      isUgly.SetName( ::TString( prefix ) + "isUgly" );
      isBadLooseMinus.SetName( ::TString( prefix ) + "isBadLooseMinus" );
      isBadLoose.SetName( ::TString( prefix ) + "isBadLoose" );
      isBadMedium.SetName( ::TString( prefix ) + "isBadMedium" );
      isBadTight.SetName( ::TString( prefix ) + "isBadTight" );
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
      e_EMB1.SetName( ::TString( prefix ) + "e_EMB1" );
      e_EMB2.SetName( ::TString( prefix ) + "e_EMB2" );
      e_EMB3.SetName( ::TString( prefix ) + "e_EMB3" );
      e_PreSamplerE.SetName( ::TString( prefix ) + "e_PreSamplerE" );
      e_EME1.SetName( ::TString( prefix ) + "e_EME1" );
      e_EME2.SetName( ::TString( prefix ) + "e_EME2" );
      e_EME3.SetName( ::TString( prefix ) + "e_EME3" );
      e_HEC0.SetName( ::TString( prefix ) + "e_HEC0" );
      e_HEC1.SetName( ::TString( prefix ) + "e_HEC1" );
      e_HEC2.SetName( ::TString( prefix ) + "e_HEC2" );
      e_HEC3.SetName( ::TString( prefix ) + "e_HEC3" );
      e_TileBar0.SetName( ::TString( prefix ) + "e_TileBar0" );
      e_TileBar1.SetName( ::TString( prefix ) + "e_TileBar1" );
      e_TileBar2.SetName( ::TString( prefix ) + "e_TileBar2" );
      e_TileGap1.SetName( ::TString( prefix ) + "e_TileGap1" );
      e_TileGap2.SetName( ::TString( prefix ) + "e_TileGap2" );
      e_TileGap3.SetName( ::TString( prefix ) + "e_TileGap3" );
      e_TileExt0.SetName( ::TString( prefix ) + "e_TileExt0" );
      e_TileExt1.SetName( ::TString( prefix ) + "e_TileExt1" );
      e_TileExt2.SetName( ::TString( prefix ) + "e_TileExt2" );
      e_FCAL0.SetName( ::TString( prefix ) + "e_FCAL0" );
      e_FCAL1.SetName( ::TString( prefix ) + "e_FCAL1" );
      e_FCAL2.SetName( ::TString( prefix ) + "e_FCAL2" );
      Nconst.SetName( ::TString( prefix ) + "Nconst" );
      ptconst_default.SetName( ::TString( prefix ) + "ptconst_default" );
      econst_default.SetName( ::TString( prefix ) + "econst_default" );
      etaconst_default.SetName( ::TString( prefix ) + "etaconst_default" );
      phiconst_default.SetName( ::TString( prefix ) + "phiconst_default" );
      weightconst_default.SetName( ::TString( prefix ) + "weightconst_default" );
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
      flavor_component_ip2d_pu.SetName( ::TString( prefix ) + "flavor_component_ip2d_pu" );
      flavor_component_ip2d_pb.SetName( ::TString( prefix ) + "flavor_component_ip2d_pb" );
      flavor_component_ip2d_isValid.SetName( ::TString( prefix ) + "flavor_component_ip2d_isValid" );
      flavor_component_ip2d_ntrk.SetName( ::TString( prefix ) + "flavor_component_ip2d_ntrk" );
      flavor_component_ip3d_pu.SetName( ::TString( prefix ) + "flavor_component_ip3d_pu" );
      flavor_component_ip3d_pb.SetName( ::TString( prefix ) + "flavor_component_ip3d_pb" );
      flavor_component_ip3d_isValid.SetName( ::TString( prefix ) + "flavor_component_ip3d_isValid" );
      flavor_component_ip3d_ntrk.SetName( ::TString( prefix ) + "flavor_component_ip3d_ntrk" );
      flavor_component_sv1_pu.SetName( ::TString( prefix ) + "flavor_component_sv1_pu" );
      flavor_component_sv1_pb.SetName( ::TString( prefix ) + "flavor_component_sv1_pb" );
      flavor_component_sv1_isValid.SetName( ::TString( prefix ) + "flavor_component_sv1_isValid" );
      flavor_component_sv2_pu.SetName( ::TString( prefix ) + "flavor_component_sv2_pu" );
      flavor_component_sv2_pb.SetName( ::TString( prefix ) + "flavor_component_sv2_pb" );
      flavor_component_sv2_isValid.SetName( ::TString( prefix ) + "flavor_component_sv2_isValid" );
      flavor_component_jfit_pu.SetName( ::TString( prefix ) + "flavor_component_jfit_pu" );
      flavor_component_jfit_pb.SetName( ::TString( prefix ) + "flavor_component_jfit_pb" );
      flavor_component_jfit_pc.SetName( ::TString( prefix ) + "flavor_component_jfit_pc" );
      flavor_component_jfit_isValid.SetName( ::TString( prefix ) + "flavor_component_jfit_isValid" );
      flavor_component_jfitcomb_pu.SetName( ::TString( prefix ) + "flavor_component_jfitcomb_pu" );
      flavor_component_jfitcomb_pb.SetName( ::TString( prefix ) + "flavor_component_jfitcomb_pb" );
      flavor_component_jfitcomb_pc.SetName( ::TString( prefix ) + "flavor_component_jfitcomb_pc" );
      flavor_component_jfitcomb_isValid.SetName( ::TString( prefix ) + "flavor_component_jfitcomb_isValid" );
      flavor_component_jfit_nvtx.SetName( ::TString( prefix ) + "flavor_component_jfit_nvtx" );
      flavor_component_jfit_nvtx1t.SetName( ::TString( prefix ) + "flavor_component_jfit_nvtx1t" );
      flavor_component_jfit_ntrkAtVx.SetName( ::TString( prefix ) + "flavor_component_jfit_ntrkAtVx" );
      flavor_component_jfit_efrc.SetName( ::TString( prefix ) + "flavor_component_jfit_efrc" );
      flavor_component_jfit_mass.SetName( ::TString( prefix ) + "flavor_component_jfit_mass" );
      flavor_component_jfit_sig3d.SetName( ::TString( prefix ) + "flavor_component_jfit_sig3d" );
      flavor_component_jfit_deltaPhi.SetName( ::TString( prefix ) + "flavor_component_jfit_deltaPhi" );
      flavor_component_jfit_deltaEta.SetName( ::TString( prefix ) + "flavor_component_jfit_deltaEta" );
      flavor_component_svp_isValid.SetName( ::TString( prefix ) + "flavor_component_svp_isValid" );
      flavor_component_svp_ntrkv.SetName( ::TString( prefix ) + "flavor_component_svp_ntrkv" );
      flavor_component_svp_ntrkj.SetName( ::TString( prefix ) + "flavor_component_svp_ntrkj" );
      flavor_component_svp_n2t.SetName( ::TString( prefix ) + "flavor_component_svp_n2t" );
      flavor_component_svp_mass.SetName( ::TString( prefix ) + "flavor_component_svp_mass" );
      flavor_component_svp_efrc.SetName( ::TString( prefix ) + "flavor_component_svp_efrc" );
      flavor_component_svp_x.SetName( ::TString( prefix ) + "flavor_component_svp_x" );
      flavor_component_svp_y.SetName( ::TString( prefix ) + "flavor_component_svp_y" );
      flavor_component_svp_z.SetName( ::TString( prefix ) + "flavor_component_svp_z" );
      flavor_component_svp_err_x.SetName( ::TString( prefix ) + "flavor_component_svp_err_x" );
      flavor_component_svp_err_y.SetName( ::TString( prefix ) + "flavor_component_svp_err_y" );
      flavor_component_svp_err_z.SetName( ::TString( prefix ) + "flavor_component_svp_err_z" );
      flavor_component_svp_cov_xy.SetName( ::TString( prefix ) + "flavor_component_svp_cov_xy" );
      flavor_component_svp_cov_xz.SetName( ::TString( prefix ) + "flavor_component_svp_cov_xz" );
      flavor_component_svp_cov_yz.SetName( ::TString( prefix ) + "flavor_component_svp_cov_yz" );
      flavor_component_svp_chi2.SetName( ::TString( prefix ) + "flavor_component_svp_chi2" );
      flavor_component_svp_ndof.SetName( ::TString( prefix ) + "flavor_component_svp_ndof" );
      flavor_component_svp_ntrk.SetName( ::TString( prefix ) + "flavor_component_svp_ntrk" );
      flavor_component_sv0p_isValid.SetName( ::TString( prefix ) + "flavor_component_sv0p_isValid" );
      flavor_component_sv0p_ntrkv.SetName( ::TString( prefix ) + "flavor_component_sv0p_ntrkv" );
      flavor_component_sv0p_ntrkj.SetName( ::TString( prefix ) + "flavor_component_sv0p_ntrkj" );
      flavor_component_sv0p_n2t.SetName( ::TString( prefix ) + "flavor_component_sv0p_n2t" );
      flavor_component_sv0p_mass.SetName( ::TString( prefix ) + "flavor_component_sv0p_mass" );
      flavor_component_sv0p_efrc.SetName( ::TString( prefix ) + "flavor_component_sv0p_efrc" );
      flavor_component_sv0p_x.SetName( ::TString( prefix ) + "flavor_component_sv0p_x" );
      flavor_component_sv0p_y.SetName( ::TString( prefix ) + "flavor_component_sv0p_y" );
      flavor_component_sv0p_z.SetName( ::TString( prefix ) + "flavor_component_sv0p_z" );
      flavor_component_sv0p_err_x.SetName( ::TString( prefix ) + "flavor_component_sv0p_err_x" );
      flavor_component_sv0p_err_y.SetName( ::TString( prefix ) + "flavor_component_sv0p_err_y" );
      flavor_component_sv0p_err_z.SetName( ::TString( prefix ) + "flavor_component_sv0p_err_z" );
      flavor_component_sv0p_cov_xy.SetName( ::TString( prefix ) + "flavor_component_sv0p_cov_xy" );
      flavor_component_sv0p_cov_xz.SetName( ::TString( prefix ) + "flavor_component_sv0p_cov_xz" );
      flavor_component_sv0p_cov_yz.SetName( ::TString( prefix ) + "flavor_component_sv0p_cov_yz" );
      flavor_component_sv0p_chi2.SetName( ::TString( prefix ) + "flavor_component_sv0p_chi2" );
      flavor_component_sv0p_ndof.SetName( ::TString( prefix ) + "flavor_component_sv0p_ndof" );
      flavor_component_sv0p_ntrk.SetName( ::TString( prefix ) + "flavor_component_sv0p_ntrk" );
      flavor_assoctrk_n.SetName( ::TString( prefix ) + "flavor_assoctrk_n" );
      flavor_assoctrk_index.SetName( ::TString( prefix ) + "flavor_assoctrk_index" );
      el_dr.SetName( ::TString( prefix ) + "el_dr" );
      el_matched.SetName( ::TString( prefix ) + "el_matched" );
      mu_dr.SetName( ::TString( prefix ) + "mu_dr" );
      mu_matched.SetName( ::TString( prefix ) + "mu_matched" );
      L1_dr.SetName( ::TString( prefix ) + "L1_dr" );
      L1_matched.SetName( ::TString( prefix ) + "L1_matched" );
      L2_dr.SetName( ::TString( prefix ) + "L2_dr" );
      L2_matched.SetName( ::TString( prefix ) + "L2_matched" );
      EF_dr.SetName( ::TString( prefix ) + "EF_dr" );
      EF_matched.SetName( ::TString( prefix ) + "EF_matched" );
      bbDecision.SetName( ::TString( prefix ) + "bbDecision" );
      SmearingFactor.SetName( ::TString( prefix ) + "SmearingFactor" );
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
      MET_LooseEgamma10NoTau_wpx.ReadFrom( tree );
      MET_LooseEgamma10NoTau_wpy.ReadFrom( tree );
      MET_LooseEgamma10NoTau_wet.ReadFrom( tree );
      MET_LooseEgamma10NoTau_statusWord.ReadFrom( tree );
      MET_wpx.ReadFrom( tree );
      MET_wpy.ReadFrom( tree );
      MET_wet.ReadFrom( tree );
      MET_statusWord.ReadFrom( tree );
      MET_STVF_wpx.ReadFrom( tree );
      MET_STVF_wpy.ReadFrom( tree );
      MET_STVF_wet.ReadFrom( tree );
      MET_STVF_statusWord.ReadFrom( tree );
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
      WIDTH.ReadFrom( tree );
      n90.ReadFrom( tree );
      Timing.ReadFrom( tree );
      LArQuality.ReadFrom( tree );
      nTrk.ReadFrom( tree );
      sumPtTrk.ReadFrom( tree );
      OriginIndex.ReadFrom( tree );
      HECQuality.ReadFrom( tree );
      NegativeE.ReadFrom( tree );
      AverageLArQF.ReadFrom( tree );
      YFlip12.ReadFrom( tree );
      YFlip23.ReadFrom( tree );
      BCH_CORR_CELL.ReadFrom( tree );
      BCH_CORR_DOTX.ReadFrom( tree );
      BCH_CORR_JET.ReadFrom( tree );
      BCH_CORR_JET_FORCELL.ReadFrom( tree );
      ENG_BAD_CELLS.ReadFrom( tree );
      N_BAD_CELLS.ReadFrom( tree );
      N_BAD_CELLS_CORR.ReadFrom( tree );
      BAD_CELLS_CORR_E.ReadFrom( tree );
      NumTowers.ReadFrom( tree );
      ootFracCells5.ReadFrom( tree );
      ootFracCells10.ReadFrom( tree );
      ootFracClusters5.ReadFrom( tree );
      ootFracClusters10.ReadFrom( tree );
      SamplingMax.ReadFrom( tree );
      fracSamplingMax.ReadFrom( tree );
      hecf.ReadFrom( tree );
      tgap3f.ReadFrom( tree );
      isUgly.ReadFrom( tree );
      isBadLooseMinus.ReadFrom( tree );
      isBadLoose.ReadFrom( tree );
      isBadMedium.ReadFrom( tree );
      isBadTight.ReadFrom( tree );
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
      e_EMB1.ReadFrom( tree );
      e_EMB2.ReadFrom( tree );
      e_EMB3.ReadFrom( tree );
      e_PreSamplerE.ReadFrom( tree );
      e_EME1.ReadFrom( tree );
      e_EME2.ReadFrom( tree );
      e_EME3.ReadFrom( tree );
      e_HEC0.ReadFrom( tree );
      e_HEC1.ReadFrom( tree );
      e_HEC2.ReadFrom( tree );
      e_HEC3.ReadFrom( tree );
      e_TileBar0.ReadFrom( tree );
      e_TileBar1.ReadFrom( tree );
      e_TileBar2.ReadFrom( tree );
      e_TileGap1.ReadFrom( tree );
      e_TileGap2.ReadFrom( tree );
      e_TileGap3.ReadFrom( tree );
      e_TileExt0.ReadFrom( tree );
      e_TileExt1.ReadFrom( tree );
      e_TileExt2.ReadFrom( tree );
      e_FCAL0.ReadFrom( tree );
      e_FCAL1.ReadFrom( tree );
      e_FCAL2.ReadFrom( tree );
      Nconst.ReadFrom( tree );
      ptconst_default.ReadFrom( tree );
      econst_default.ReadFrom( tree );
      etaconst_default.ReadFrom( tree );
      phiconst_default.ReadFrom( tree );
      weightconst_default.ReadFrom( tree );
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
      flavor_component_ip2d_pu.ReadFrom( tree );
      flavor_component_ip2d_pb.ReadFrom( tree );
      flavor_component_ip2d_isValid.ReadFrom( tree );
      flavor_component_ip2d_ntrk.ReadFrom( tree );
      flavor_component_ip3d_pu.ReadFrom( tree );
      flavor_component_ip3d_pb.ReadFrom( tree );
      flavor_component_ip3d_isValid.ReadFrom( tree );
      flavor_component_ip3d_ntrk.ReadFrom( tree );
      flavor_component_sv1_pu.ReadFrom( tree );
      flavor_component_sv1_pb.ReadFrom( tree );
      flavor_component_sv1_isValid.ReadFrom( tree );
      flavor_component_sv2_pu.ReadFrom( tree );
      flavor_component_sv2_pb.ReadFrom( tree );
      flavor_component_sv2_isValid.ReadFrom( tree );
      flavor_component_jfit_pu.ReadFrom( tree );
      flavor_component_jfit_pb.ReadFrom( tree );
      flavor_component_jfit_pc.ReadFrom( tree );
      flavor_component_jfit_isValid.ReadFrom( tree );
      flavor_component_jfitcomb_pu.ReadFrom( tree );
      flavor_component_jfitcomb_pb.ReadFrom( tree );
      flavor_component_jfitcomb_pc.ReadFrom( tree );
      flavor_component_jfitcomb_isValid.ReadFrom( tree );
      flavor_component_jfit_nvtx.ReadFrom( tree );
      flavor_component_jfit_nvtx1t.ReadFrom( tree );
      flavor_component_jfit_ntrkAtVx.ReadFrom( tree );
      flavor_component_jfit_efrc.ReadFrom( tree );
      flavor_component_jfit_mass.ReadFrom( tree );
      flavor_component_jfit_sig3d.ReadFrom( tree );
      flavor_component_jfit_deltaPhi.ReadFrom( tree );
      flavor_component_jfit_deltaEta.ReadFrom( tree );
      flavor_component_svp_isValid.ReadFrom( tree );
      flavor_component_svp_ntrkv.ReadFrom( tree );
      flavor_component_svp_ntrkj.ReadFrom( tree );
      flavor_component_svp_n2t.ReadFrom( tree );
      flavor_component_svp_mass.ReadFrom( tree );
      flavor_component_svp_efrc.ReadFrom( tree );
      flavor_component_svp_x.ReadFrom( tree );
      flavor_component_svp_y.ReadFrom( tree );
      flavor_component_svp_z.ReadFrom( tree );
      flavor_component_svp_err_x.ReadFrom( tree );
      flavor_component_svp_err_y.ReadFrom( tree );
      flavor_component_svp_err_z.ReadFrom( tree );
      flavor_component_svp_cov_xy.ReadFrom( tree );
      flavor_component_svp_cov_xz.ReadFrom( tree );
      flavor_component_svp_cov_yz.ReadFrom( tree );
      flavor_component_svp_chi2.ReadFrom( tree );
      flavor_component_svp_ndof.ReadFrom( tree );
      flavor_component_svp_ntrk.ReadFrom( tree );
      flavor_component_sv0p_isValid.ReadFrom( tree );
      flavor_component_sv0p_ntrkv.ReadFrom( tree );
      flavor_component_sv0p_ntrkj.ReadFrom( tree );
      flavor_component_sv0p_n2t.ReadFrom( tree );
      flavor_component_sv0p_mass.ReadFrom( tree );
      flavor_component_sv0p_efrc.ReadFrom( tree );
      flavor_component_sv0p_x.ReadFrom( tree );
      flavor_component_sv0p_y.ReadFrom( tree );
      flavor_component_sv0p_z.ReadFrom( tree );
      flavor_component_sv0p_err_x.ReadFrom( tree );
      flavor_component_sv0p_err_y.ReadFrom( tree );
      flavor_component_sv0p_err_z.ReadFrom( tree );
      flavor_component_sv0p_cov_xy.ReadFrom( tree );
      flavor_component_sv0p_cov_xz.ReadFrom( tree );
      flavor_component_sv0p_cov_yz.ReadFrom( tree );
      flavor_component_sv0p_chi2.ReadFrom( tree );
      flavor_component_sv0p_ndof.ReadFrom( tree );
      flavor_component_sv0p_ntrk.ReadFrom( tree );
      flavor_assoctrk_n.ReadFrom( tree );
      flavor_assoctrk_index.ReadFrom( tree );
      el_dr.ReadFrom( tree );
      el_matched.ReadFrom( tree );
      mu_dr.ReadFrom( tree );
      mu_matched.ReadFrom( tree );
      L1_dr.ReadFrom( tree );
      L1_matched.ReadFrom( tree );
      L2_dr.ReadFrom( tree );
      L2_matched.ReadFrom( tree );
      EF_dr.ReadFrom( tree );
      EF_matched.ReadFrom( tree );
      bbDecision.ReadFrom( tree );
      SmearingFactor.ReadFrom( tree );

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
      MET_LooseEgamma10NoTau_wpx.WriteTo( tree );
      MET_LooseEgamma10NoTau_wpy.WriteTo( tree );
      MET_LooseEgamma10NoTau_wet.WriteTo( tree );
      MET_LooseEgamma10NoTau_statusWord.WriteTo( tree );
      MET_wpx.WriteTo( tree );
      MET_wpy.WriteTo( tree );
      MET_wet.WriteTo( tree );
      MET_statusWord.WriteTo( tree );
      MET_STVF_wpx.WriteTo( tree );
      MET_STVF_wpy.WriteTo( tree );
      MET_STVF_wet.WriteTo( tree );
      MET_STVF_statusWord.WriteTo( tree );
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
      WIDTH.WriteTo( tree );
      n90.WriteTo( tree );
      Timing.WriteTo( tree );
      LArQuality.WriteTo( tree );
      nTrk.WriteTo( tree );
      sumPtTrk.WriteTo( tree );
      OriginIndex.WriteTo( tree );
      HECQuality.WriteTo( tree );
      NegativeE.WriteTo( tree );
      AverageLArQF.WriteTo( tree );
      YFlip12.WriteTo( tree );
      YFlip23.WriteTo( tree );
      BCH_CORR_CELL.WriteTo( tree );
      BCH_CORR_DOTX.WriteTo( tree );
      BCH_CORR_JET.WriteTo( tree );
      BCH_CORR_JET_FORCELL.WriteTo( tree );
      ENG_BAD_CELLS.WriteTo( tree );
      N_BAD_CELLS.WriteTo( tree );
      N_BAD_CELLS_CORR.WriteTo( tree );
      BAD_CELLS_CORR_E.WriteTo( tree );
      NumTowers.WriteTo( tree );
      ootFracCells5.WriteTo( tree );
      ootFracCells10.WriteTo( tree );
      ootFracClusters5.WriteTo( tree );
      ootFracClusters10.WriteTo( tree );
      SamplingMax.WriteTo( tree );
      fracSamplingMax.WriteTo( tree );
      hecf.WriteTo( tree );
      tgap3f.WriteTo( tree );
      isUgly.WriteTo( tree );
      isBadLooseMinus.WriteTo( tree );
      isBadLoose.WriteTo( tree );
      isBadMedium.WriteTo( tree );
      isBadTight.WriteTo( tree );
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
      e_EMB1.WriteTo( tree );
      e_EMB2.WriteTo( tree );
      e_EMB3.WriteTo( tree );
      e_PreSamplerE.WriteTo( tree );
      e_EME1.WriteTo( tree );
      e_EME2.WriteTo( tree );
      e_EME3.WriteTo( tree );
      e_HEC0.WriteTo( tree );
      e_HEC1.WriteTo( tree );
      e_HEC2.WriteTo( tree );
      e_HEC3.WriteTo( tree );
      e_TileBar0.WriteTo( tree );
      e_TileBar1.WriteTo( tree );
      e_TileBar2.WriteTo( tree );
      e_TileGap1.WriteTo( tree );
      e_TileGap2.WriteTo( tree );
      e_TileGap3.WriteTo( tree );
      e_TileExt0.WriteTo( tree );
      e_TileExt1.WriteTo( tree );
      e_TileExt2.WriteTo( tree );
      e_FCAL0.WriteTo( tree );
      e_FCAL1.WriteTo( tree );
      e_FCAL2.WriteTo( tree );
      Nconst.WriteTo( tree );
      ptconst_default.WriteTo( tree );
      econst_default.WriteTo( tree );
      etaconst_default.WriteTo( tree );
      phiconst_default.WriteTo( tree );
      weightconst_default.WriteTo( tree );
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
      flavor_component_ip2d_pu.WriteTo( tree );
      flavor_component_ip2d_pb.WriteTo( tree );
      flavor_component_ip2d_isValid.WriteTo( tree );
      flavor_component_ip2d_ntrk.WriteTo( tree );
      flavor_component_ip3d_pu.WriteTo( tree );
      flavor_component_ip3d_pb.WriteTo( tree );
      flavor_component_ip3d_isValid.WriteTo( tree );
      flavor_component_ip3d_ntrk.WriteTo( tree );
      flavor_component_sv1_pu.WriteTo( tree );
      flavor_component_sv1_pb.WriteTo( tree );
      flavor_component_sv1_isValid.WriteTo( tree );
      flavor_component_sv2_pu.WriteTo( tree );
      flavor_component_sv2_pb.WriteTo( tree );
      flavor_component_sv2_isValid.WriteTo( tree );
      flavor_component_jfit_pu.WriteTo( tree );
      flavor_component_jfit_pb.WriteTo( tree );
      flavor_component_jfit_pc.WriteTo( tree );
      flavor_component_jfit_isValid.WriteTo( tree );
      flavor_component_jfitcomb_pu.WriteTo( tree );
      flavor_component_jfitcomb_pb.WriteTo( tree );
      flavor_component_jfitcomb_pc.WriteTo( tree );
      flavor_component_jfitcomb_isValid.WriteTo( tree );
      flavor_component_jfit_nvtx.WriteTo( tree );
      flavor_component_jfit_nvtx1t.WriteTo( tree );
      flavor_component_jfit_ntrkAtVx.WriteTo( tree );
      flavor_component_jfit_efrc.WriteTo( tree );
      flavor_component_jfit_mass.WriteTo( tree );
      flavor_component_jfit_sig3d.WriteTo( tree );
      flavor_component_jfit_deltaPhi.WriteTo( tree );
      flavor_component_jfit_deltaEta.WriteTo( tree );
      flavor_component_svp_isValid.WriteTo( tree );
      flavor_component_svp_ntrkv.WriteTo( tree );
      flavor_component_svp_ntrkj.WriteTo( tree );
      flavor_component_svp_n2t.WriteTo( tree );
      flavor_component_svp_mass.WriteTo( tree );
      flavor_component_svp_efrc.WriteTo( tree );
      flavor_component_svp_x.WriteTo( tree );
      flavor_component_svp_y.WriteTo( tree );
      flavor_component_svp_z.WriteTo( tree );
      flavor_component_svp_err_x.WriteTo( tree );
      flavor_component_svp_err_y.WriteTo( tree );
      flavor_component_svp_err_z.WriteTo( tree );
      flavor_component_svp_cov_xy.WriteTo( tree );
      flavor_component_svp_cov_xz.WriteTo( tree );
      flavor_component_svp_cov_yz.WriteTo( tree );
      flavor_component_svp_chi2.WriteTo( tree );
      flavor_component_svp_ndof.WriteTo( tree );
      flavor_component_svp_ntrk.WriteTo( tree );
      flavor_component_sv0p_isValid.WriteTo( tree );
      flavor_component_sv0p_ntrkv.WriteTo( tree );
      flavor_component_sv0p_ntrkj.WriteTo( tree );
      flavor_component_sv0p_n2t.WriteTo( tree );
      flavor_component_sv0p_mass.WriteTo( tree );
      flavor_component_sv0p_efrc.WriteTo( tree );
      flavor_component_sv0p_x.WriteTo( tree );
      flavor_component_sv0p_y.WriteTo( tree );
      flavor_component_sv0p_z.WriteTo( tree );
      flavor_component_sv0p_err_x.WriteTo( tree );
      flavor_component_sv0p_err_y.WriteTo( tree );
      flavor_component_sv0p_err_z.WriteTo( tree );
      flavor_component_sv0p_cov_xy.WriteTo( tree );
      flavor_component_sv0p_cov_xz.WriteTo( tree );
      flavor_component_sv0p_cov_yz.WriteTo( tree );
      flavor_component_sv0p_chi2.WriteTo( tree );
      flavor_component_sv0p_ndof.WriteTo( tree );
      flavor_component_sv0p_ntrk.WriteTo( tree );
      flavor_assoctrk_n.WriteTo( tree );
      flavor_assoctrk_index.WriteTo( tree );
      el_dr.WriteTo( tree );
      el_matched.WriteTo( tree );
      mu_dr.WriteTo( tree );
      mu_matched.WriteTo( tree );
      L1_dr.WriteTo( tree );
      L1_matched.WriteTo( tree );
      L2_dr.WriteTo( tree );
      L2_matched.WriteTo( tree );
      EF_dr.WriteTo( tree );
      EF_matched.WriteTo( tree );
      bbDecision.WriteTo( tree );
      SmearingFactor.WriteTo( tree );

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
      if( MET_LooseEgamma10NoTau_wpx.IsActive() ) MET_LooseEgamma10NoTau_wpx();
      if( MET_LooseEgamma10NoTau_wpy.IsActive() ) MET_LooseEgamma10NoTau_wpy();
      if( MET_LooseEgamma10NoTau_wet.IsActive() ) MET_LooseEgamma10NoTau_wet();
      if( MET_LooseEgamma10NoTau_statusWord.IsActive() ) MET_LooseEgamma10NoTau_statusWord();
      if( MET_wpx.IsActive() ) MET_wpx();
      if( MET_wpy.IsActive() ) MET_wpy();
      if( MET_wet.IsActive() ) MET_wet();
      if( MET_statusWord.IsActive() ) MET_statusWord();
      if( MET_STVF_wpx.IsActive() ) MET_STVF_wpx();
      if( MET_STVF_wpy.IsActive() ) MET_STVF_wpy();
      if( MET_STVF_wet.IsActive() ) MET_STVF_wet();
      if( MET_STVF_statusWord.IsActive() ) MET_STVF_statusWord();
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
      if( WIDTH.IsActive() ) WIDTH();
      if( n90.IsActive() ) n90();
      if( Timing.IsActive() ) Timing();
      if( LArQuality.IsActive() ) LArQuality();
      if( nTrk.IsActive() ) nTrk();
      if( sumPtTrk.IsActive() ) sumPtTrk();
      if( OriginIndex.IsActive() ) OriginIndex();
      if( HECQuality.IsActive() ) HECQuality();
      if( NegativeE.IsActive() ) NegativeE();
      if( AverageLArQF.IsActive() ) AverageLArQF();
      if( YFlip12.IsActive() ) YFlip12();
      if( YFlip23.IsActive() ) YFlip23();
      if( BCH_CORR_CELL.IsActive() ) BCH_CORR_CELL();
      if( BCH_CORR_DOTX.IsActive() ) BCH_CORR_DOTX();
      if( BCH_CORR_JET.IsActive() ) BCH_CORR_JET();
      if( BCH_CORR_JET_FORCELL.IsActive() ) BCH_CORR_JET_FORCELL();
      if( ENG_BAD_CELLS.IsActive() ) ENG_BAD_CELLS();
      if( N_BAD_CELLS.IsActive() ) N_BAD_CELLS();
      if( N_BAD_CELLS_CORR.IsActive() ) N_BAD_CELLS_CORR();
      if( BAD_CELLS_CORR_E.IsActive() ) BAD_CELLS_CORR_E();
      if( NumTowers.IsActive() ) NumTowers();
      if( ootFracCells5.IsActive() ) ootFracCells5();
      if( ootFracCells10.IsActive() ) ootFracCells10();
      if( ootFracClusters5.IsActive() ) ootFracClusters5();
      if( ootFracClusters10.IsActive() ) ootFracClusters10();
      if( SamplingMax.IsActive() ) SamplingMax();
      if( fracSamplingMax.IsActive() ) fracSamplingMax();
      if( hecf.IsActive() ) hecf();
      if( tgap3f.IsActive() ) tgap3f();
      if( isUgly.IsActive() ) isUgly();
      if( isBadLooseMinus.IsActive() ) isBadLooseMinus();
      if( isBadLoose.IsActive() ) isBadLoose();
      if( isBadMedium.IsActive() ) isBadMedium();
      if( isBadTight.IsActive() ) isBadTight();
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
      if( e_EMB1.IsActive() ) e_EMB1();
      if( e_EMB2.IsActive() ) e_EMB2();
      if( e_EMB3.IsActive() ) e_EMB3();
      if( e_PreSamplerE.IsActive() ) e_PreSamplerE();
      if( e_EME1.IsActive() ) e_EME1();
      if( e_EME2.IsActive() ) e_EME2();
      if( e_EME3.IsActive() ) e_EME3();
      if( e_HEC0.IsActive() ) e_HEC0();
      if( e_HEC1.IsActive() ) e_HEC1();
      if( e_HEC2.IsActive() ) e_HEC2();
      if( e_HEC3.IsActive() ) e_HEC3();
      if( e_TileBar0.IsActive() ) e_TileBar0();
      if( e_TileBar1.IsActive() ) e_TileBar1();
      if( e_TileBar2.IsActive() ) e_TileBar2();
      if( e_TileGap1.IsActive() ) e_TileGap1();
      if( e_TileGap2.IsActive() ) e_TileGap2();
      if( e_TileGap3.IsActive() ) e_TileGap3();
      if( e_TileExt0.IsActive() ) e_TileExt0();
      if( e_TileExt1.IsActive() ) e_TileExt1();
      if( e_TileExt2.IsActive() ) e_TileExt2();
      if( e_FCAL0.IsActive() ) e_FCAL0();
      if( e_FCAL1.IsActive() ) e_FCAL1();
      if( e_FCAL2.IsActive() ) e_FCAL2();
      if( Nconst.IsActive() ) Nconst();
      if( ptconst_default.IsActive() ) ptconst_default();
      if( econst_default.IsActive() ) econst_default();
      if( etaconst_default.IsActive() ) etaconst_default();
      if( phiconst_default.IsActive() ) phiconst_default();
      if( weightconst_default.IsActive() ) weightconst_default();
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
      if( flavor_component_ip2d_pu.IsActive() ) flavor_component_ip2d_pu();
      if( flavor_component_ip2d_pb.IsActive() ) flavor_component_ip2d_pb();
      if( flavor_component_ip2d_isValid.IsActive() ) flavor_component_ip2d_isValid();
      if( flavor_component_ip2d_ntrk.IsActive() ) flavor_component_ip2d_ntrk();
      if( flavor_component_ip3d_pu.IsActive() ) flavor_component_ip3d_pu();
      if( flavor_component_ip3d_pb.IsActive() ) flavor_component_ip3d_pb();
      if( flavor_component_ip3d_isValid.IsActive() ) flavor_component_ip3d_isValid();
      if( flavor_component_ip3d_ntrk.IsActive() ) flavor_component_ip3d_ntrk();
      if( flavor_component_sv1_pu.IsActive() ) flavor_component_sv1_pu();
      if( flavor_component_sv1_pb.IsActive() ) flavor_component_sv1_pb();
      if( flavor_component_sv1_isValid.IsActive() ) flavor_component_sv1_isValid();
      if( flavor_component_sv2_pu.IsActive() ) flavor_component_sv2_pu();
      if( flavor_component_sv2_pb.IsActive() ) flavor_component_sv2_pb();
      if( flavor_component_sv2_isValid.IsActive() ) flavor_component_sv2_isValid();
      if( flavor_component_jfit_pu.IsActive() ) flavor_component_jfit_pu();
      if( flavor_component_jfit_pb.IsActive() ) flavor_component_jfit_pb();
      if( flavor_component_jfit_pc.IsActive() ) flavor_component_jfit_pc();
      if( flavor_component_jfit_isValid.IsActive() ) flavor_component_jfit_isValid();
      if( flavor_component_jfitcomb_pu.IsActive() ) flavor_component_jfitcomb_pu();
      if( flavor_component_jfitcomb_pb.IsActive() ) flavor_component_jfitcomb_pb();
      if( flavor_component_jfitcomb_pc.IsActive() ) flavor_component_jfitcomb_pc();
      if( flavor_component_jfitcomb_isValid.IsActive() ) flavor_component_jfitcomb_isValid();
      if( flavor_component_jfit_nvtx.IsActive() ) flavor_component_jfit_nvtx();
      if( flavor_component_jfit_nvtx1t.IsActive() ) flavor_component_jfit_nvtx1t();
      if( flavor_component_jfit_ntrkAtVx.IsActive() ) flavor_component_jfit_ntrkAtVx();
      if( flavor_component_jfit_efrc.IsActive() ) flavor_component_jfit_efrc();
      if( flavor_component_jfit_mass.IsActive() ) flavor_component_jfit_mass();
      if( flavor_component_jfit_sig3d.IsActive() ) flavor_component_jfit_sig3d();
      if( flavor_component_jfit_deltaPhi.IsActive() ) flavor_component_jfit_deltaPhi();
      if( flavor_component_jfit_deltaEta.IsActive() ) flavor_component_jfit_deltaEta();
      if( flavor_component_svp_isValid.IsActive() ) flavor_component_svp_isValid();
      if( flavor_component_svp_ntrkv.IsActive() ) flavor_component_svp_ntrkv();
      if( flavor_component_svp_ntrkj.IsActive() ) flavor_component_svp_ntrkj();
      if( flavor_component_svp_n2t.IsActive() ) flavor_component_svp_n2t();
      if( flavor_component_svp_mass.IsActive() ) flavor_component_svp_mass();
      if( flavor_component_svp_efrc.IsActive() ) flavor_component_svp_efrc();
      if( flavor_component_svp_x.IsActive() ) flavor_component_svp_x();
      if( flavor_component_svp_y.IsActive() ) flavor_component_svp_y();
      if( flavor_component_svp_z.IsActive() ) flavor_component_svp_z();
      if( flavor_component_svp_err_x.IsActive() ) flavor_component_svp_err_x();
      if( flavor_component_svp_err_y.IsActive() ) flavor_component_svp_err_y();
      if( flavor_component_svp_err_z.IsActive() ) flavor_component_svp_err_z();
      if( flavor_component_svp_cov_xy.IsActive() ) flavor_component_svp_cov_xy();
      if( flavor_component_svp_cov_xz.IsActive() ) flavor_component_svp_cov_xz();
      if( flavor_component_svp_cov_yz.IsActive() ) flavor_component_svp_cov_yz();
      if( flavor_component_svp_chi2.IsActive() ) flavor_component_svp_chi2();
      if( flavor_component_svp_ndof.IsActive() ) flavor_component_svp_ndof();
      if( flavor_component_svp_ntrk.IsActive() ) flavor_component_svp_ntrk();
      if( flavor_component_sv0p_isValid.IsActive() ) flavor_component_sv0p_isValid();
      if( flavor_component_sv0p_ntrkv.IsActive() ) flavor_component_sv0p_ntrkv();
      if( flavor_component_sv0p_ntrkj.IsActive() ) flavor_component_sv0p_ntrkj();
      if( flavor_component_sv0p_n2t.IsActive() ) flavor_component_sv0p_n2t();
      if( flavor_component_sv0p_mass.IsActive() ) flavor_component_sv0p_mass();
      if( flavor_component_sv0p_efrc.IsActive() ) flavor_component_sv0p_efrc();
      if( flavor_component_sv0p_x.IsActive() ) flavor_component_sv0p_x();
      if( flavor_component_sv0p_y.IsActive() ) flavor_component_sv0p_y();
      if( flavor_component_sv0p_z.IsActive() ) flavor_component_sv0p_z();
      if( flavor_component_sv0p_err_x.IsActive() ) flavor_component_sv0p_err_x();
      if( flavor_component_sv0p_err_y.IsActive() ) flavor_component_sv0p_err_y();
      if( flavor_component_sv0p_err_z.IsActive() ) flavor_component_sv0p_err_z();
      if( flavor_component_sv0p_cov_xy.IsActive() ) flavor_component_sv0p_cov_xy();
      if( flavor_component_sv0p_cov_xz.IsActive() ) flavor_component_sv0p_cov_xz();
      if( flavor_component_sv0p_cov_yz.IsActive() ) flavor_component_sv0p_cov_yz();
      if( flavor_component_sv0p_chi2.IsActive() ) flavor_component_sv0p_chi2();
      if( flavor_component_sv0p_ndof.IsActive() ) flavor_component_sv0p_ndof();
      if( flavor_component_sv0p_ntrk.IsActive() ) flavor_component_sv0p_ntrk();
      if( flavor_assoctrk_n.IsActive() ) flavor_assoctrk_n();
      if( flavor_assoctrk_index.IsActive() ) flavor_assoctrk_index();
      if( el_dr.IsActive() ) el_dr();
      if( el_matched.IsActive() ) el_matched();
      if( mu_dr.IsActive() ) mu_dr();
      if( mu_matched.IsActive() ) mu_matched();
      if( L1_dr.IsActive() ) L1_dr();
      if( L1_matched.IsActive() ) L1_matched();
      if( L2_dr.IsActive() ) L2_dr();
      if( L2_matched.IsActive() ) L2_matched();
      if( EF_dr.IsActive() ) EF_dr();
      if( EF_matched.IsActive() ) EF_matched();
      if( bbDecision.IsActive() ) bbDecision();
      if( SmearingFactor.IsActive() ) SmearingFactor();

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
      MET_LooseEgamma10NoTau_wpx()->clear();
      MET_LooseEgamma10NoTau_wpy()->clear();
      MET_LooseEgamma10NoTau_wet()->clear();
      MET_LooseEgamma10NoTau_statusWord()->clear();
      MET_wpx()->clear();
      MET_wpy()->clear();
      MET_wet()->clear();
      MET_statusWord()->clear();
      MET_STVF_wpx()->clear();
      MET_STVF_wpy()->clear();
      MET_STVF_wet()->clear();
      MET_STVF_statusWord()->clear();
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
      WIDTH()->clear();
      n90()->clear();
      Timing()->clear();
      LArQuality()->clear();
      nTrk()->clear();
      sumPtTrk()->clear();
      OriginIndex()->clear();
      HECQuality()->clear();
      NegativeE()->clear();
      AverageLArQF()->clear();
      YFlip12()->clear();
      YFlip23()->clear();
      BCH_CORR_CELL()->clear();
      BCH_CORR_DOTX()->clear();
      BCH_CORR_JET()->clear();
      BCH_CORR_JET_FORCELL()->clear();
      ENG_BAD_CELLS()->clear();
      N_BAD_CELLS()->clear();
      N_BAD_CELLS_CORR()->clear();
      BAD_CELLS_CORR_E()->clear();
      NumTowers()->clear();
      ootFracCells5()->clear();
      ootFracCells10()->clear();
      ootFracClusters5()->clear();
      ootFracClusters10()->clear();
      SamplingMax()->clear();
      fracSamplingMax()->clear();
      hecf()->clear();
      tgap3f()->clear();
      isUgly()->clear();
      isBadLooseMinus()->clear();
      isBadLoose()->clear();
      isBadMedium()->clear();
      isBadTight()->clear();
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
      e_EMB1()->clear();
      e_EMB2()->clear();
      e_EMB3()->clear();
      e_PreSamplerE()->clear();
      e_EME1()->clear();
      e_EME2()->clear();
      e_EME3()->clear();
      e_HEC0()->clear();
      e_HEC1()->clear();
      e_HEC2()->clear();
      e_HEC3()->clear();
      e_TileBar0()->clear();
      e_TileBar1()->clear();
      e_TileBar2()->clear();
      e_TileGap1()->clear();
      e_TileGap2()->clear();
      e_TileGap3()->clear();
      e_TileExt0()->clear();
      e_TileExt1()->clear();
      e_TileExt2()->clear();
      e_FCAL0()->clear();
      e_FCAL1()->clear();
      e_FCAL2()->clear();
      Nconst()->clear();
      ptconst_default()->clear();
      econst_default()->clear();
      etaconst_default()->clear();
      phiconst_default()->clear();
      weightconst_default()->clear();
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
      flavor_component_ip2d_pu()->clear();
      flavor_component_ip2d_pb()->clear();
      flavor_component_ip2d_isValid()->clear();
      flavor_component_ip2d_ntrk()->clear();
      flavor_component_ip3d_pu()->clear();
      flavor_component_ip3d_pb()->clear();
      flavor_component_ip3d_isValid()->clear();
      flavor_component_ip3d_ntrk()->clear();
      flavor_component_sv1_pu()->clear();
      flavor_component_sv1_pb()->clear();
      flavor_component_sv1_isValid()->clear();
      flavor_component_sv2_pu()->clear();
      flavor_component_sv2_pb()->clear();
      flavor_component_sv2_isValid()->clear();
      flavor_component_jfit_pu()->clear();
      flavor_component_jfit_pb()->clear();
      flavor_component_jfit_pc()->clear();
      flavor_component_jfit_isValid()->clear();
      flavor_component_jfitcomb_pu()->clear();
      flavor_component_jfitcomb_pb()->clear();
      flavor_component_jfitcomb_pc()->clear();
      flavor_component_jfitcomb_isValid()->clear();
      flavor_component_jfit_nvtx()->clear();
      flavor_component_jfit_nvtx1t()->clear();
      flavor_component_jfit_ntrkAtVx()->clear();
      flavor_component_jfit_efrc()->clear();
      flavor_component_jfit_mass()->clear();
      flavor_component_jfit_sig3d()->clear();
      flavor_component_jfit_deltaPhi()->clear();
      flavor_component_jfit_deltaEta()->clear();
      flavor_component_svp_isValid()->clear();
      flavor_component_svp_ntrkv()->clear();
      flavor_component_svp_ntrkj()->clear();
      flavor_component_svp_n2t()->clear();
      flavor_component_svp_mass()->clear();
      flavor_component_svp_efrc()->clear();
      flavor_component_svp_x()->clear();
      flavor_component_svp_y()->clear();
      flavor_component_svp_z()->clear();
      flavor_component_svp_err_x()->clear();
      flavor_component_svp_err_y()->clear();
      flavor_component_svp_err_z()->clear();
      flavor_component_svp_cov_xy()->clear();
      flavor_component_svp_cov_xz()->clear();
      flavor_component_svp_cov_yz()->clear();
      flavor_component_svp_chi2()->clear();
      flavor_component_svp_ndof()->clear();
      flavor_component_svp_ntrk()->clear();
      flavor_component_sv0p_isValid()->clear();
      flavor_component_sv0p_ntrkv()->clear();
      flavor_component_sv0p_ntrkj()->clear();
      flavor_component_sv0p_n2t()->clear();
      flavor_component_sv0p_mass()->clear();
      flavor_component_sv0p_efrc()->clear();
      flavor_component_sv0p_x()->clear();
      flavor_component_sv0p_y()->clear();
      flavor_component_sv0p_z()->clear();
      flavor_component_sv0p_err_x()->clear();
      flavor_component_sv0p_err_y()->clear();
      flavor_component_sv0p_err_z()->clear();
      flavor_component_sv0p_cov_xy()->clear();
      flavor_component_sv0p_cov_xz()->clear();
      flavor_component_sv0p_cov_yz()->clear();
      flavor_component_sv0p_chi2()->clear();
      flavor_component_sv0p_ndof()->clear();
      flavor_component_sv0p_ntrk()->clear();
      flavor_assoctrk_n()->clear();
      flavor_assoctrk_index()->clear();
      el_dr()->clear();
      el_matched()->clear();
      mu_dr()->clear();
      mu_matched()->clear();
      L1_dr()->clear();
      L1_matched()->clear();
      L2_dr()->clear();
      L2_matched()->clear();
      EF_dr()->clear();
      EF_matched()->clear();
      bbDecision()->clear();
      SmearingFactor()->clear();

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
      if( el.MET_LooseEgamma10NoTau_wpx.IsAvailable() ) {
         MET_LooseEgamma10NoTau_wpx()->push_back( el.MET_LooseEgamma10NoTau_wpx() );
      } else {
         MET_LooseEgamma10NoTau_wpx()->push_back( vector<float>() );
      }
      if( el.MET_LooseEgamma10NoTau_wpy.IsAvailable() ) {
         MET_LooseEgamma10NoTau_wpy()->push_back( el.MET_LooseEgamma10NoTau_wpy() );
      } else {
         MET_LooseEgamma10NoTau_wpy()->push_back( vector<float>() );
      }
      if( el.MET_LooseEgamma10NoTau_wet.IsAvailable() ) {
         MET_LooseEgamma10NoTau_wet()->push_back( el.MET_LooseEgamma10NoTau_wet() );
      } else {
         MET_LooseEgamma10NoTau_wet()->push_back( vector<float>() );
      }
      if( el.MET_LooseEgamma10NoTau_statusWord.IsAvailable() ) {
         MET_LooseEgamma10NoTau_statusWord()->push_back( el.MET_LooseEgamma10NoTau_statusWord() );
      } else {
         MET_LooseEgamma10NoTau_statusWord()->push_back( vector<unsigned int>() );
      }
      if( el.MET_wpx.IsAvailable() ) {
         MET_wpx()->push_back( el.MET_wpx() );
      } else {
         MET_wpx()->push_back( vector<float>() );
      }
      if( el.MET_wpy.IsAvailable() ) {
         MET_wpy()->push_back( el.MET_wpy() );
      } else {
         MET_wpy()->push_back( vector<float>() );
      }
      if( el.MET_wet.IsAvailable() ) {
         MET_wet()->push_back( el.MET_wet() );
      } else {
         MET_wet()->push_back( vector<float>() );
      }
      if( el.MET_statusWord.IsAvailable() ) {
         MET_statusWord()->push_back( el.MET_statusWord() );
      } else {
         MET_statusWord()->push_back( vector<unsigned int>() );
      }
      if( el.MET_STVF_wpx.IsAvailable() ) {
         MET_STVF_wpx()->push_back( el.MET_STVF_wpx() );
      } else {
         MET_STVF_wpx()->push_back( vector<float>() );
      }
      if( el.MET_STVF_wpy.IsAvailable() ) {
         MET_STVF_wpy()->push_back( el.MET_STVF_wpy() );
      } else {
         MET_STVF_wpy()->push_back( vector<float>() );
      }
      if( el.MET_STVF_wet.IsAvailable() ) {
         MET_STVF_wet()->push_back( el.MET_STVF_wet() );
      } else {
         MET_STVF_wet()->push_back( vector<float>() );
      }
      if( el.MET_STVF_statusWord.IsAvailable() ) {
         MET_STVF_statusWord()->push_back( el.MET_STVF_statusWord() );
      } else {
         MET_STVF_statusWord()->push_back( vector<unsigned int>() );
      }
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
      if( el.WIDTH.IsAvailable() ) {
         WIDTH()->push_back( el.WIDTH() );
      } else {
         WIDTH()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.n90.IsAvailable() ) {
         n90()->push_back( el.n90() );
      } else {
         n90()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Timing.IsAvailable() ) {
         Timing()->push_back( el.Timing() );
      } else {
         Timing()->push_back( std::numeric_limits< float >::min() );
      }
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
      if( el.YFlip12.IsAvailable() ) {
         YFlip12()->push_back( el.YFlip12() );
      } else {
         YFlip12()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.YFlip23.IsAvailable() ) {
         YFlip23()->push_back( el.YFlip23() );
      } else {
         YFlip23()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.BCH_CORR_CELL.IsAvailable() ) {
         BCH_CORR_CELL()->push_back( el.BCH_CORR_CELL() );
      } else {
         BCH_CORR_CELL()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.BCH_CORR_DOTX.IsAvailable() ) {
         BCH_CORR_DOTX()->push_back( el.BCH_CORR_DOTX() );
      } else {
         BCH_CORR_DOTX()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.BCH_CORR_JET.IsAvailable() ) {
         BCH_CORR_JET()->push_back( el.BCH_CORR_JET() );
      } else {
         BCH_CORR_JET()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.BCH_CORR_JET_FORCELL.IsAvailable() ) {
         BCH_CORR_JET_FORCELL()->push_back( el.BCH_CORR_JET_FORCELL() );
      } else {
         BCH_CORR_JET_FORCELL()->push_back( std::numeric_limits< float >::min() );
      }
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
      if( el.NumTowers.IsAvailable() ) {
         NumTowers()->push_back( el.NumTowers() );
      } else {
         NumTowers()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ootFracCells5.IsAvailable() ) {
         ootFracCells5()->push_back( el.ootFracCells5() );
      } else {
         ootFracCells5()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ootFracCells10.IsAvailable() ) {
         ootFracCells10()->push_back( el.ootFracCells10() );
      } else {
         ootFracCells10()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ootFracClusters5.IsAvailable() ) {
         ootFracClusters5()->push_back( el.ootFracClusters5() );
      } else {
         ootFracClusters5()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ootFracClusters10.IsAvailable() ) {
         ootFracClusters10()->push_back( el.ootFracClusters10() );
      } else {
         ootFracClusters10()->push_back( std::numeric_limits< float >::min() );
      }
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
      if( el.tgap3f.IsAvailable() ) {
         tgap3f()->push_back( el.tgap3f() );
      } else {
         tgap3f()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.isUgly.IsAvailable() ) {
         isUgly()->push_back( el.isUgly() );
      } else {
         isUgly()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isBadLooseMinus.IsAvailable() ) {
         isBadLooseMinus()->push_back( el.isBadLooseMinus() );
      } else {
         isBadLooseMinus()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isBadLoose.IsAvailable() ) {
         isBadLoose()->push_back( el.isBadLoose() );
      } else {
         isBadLoose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isBadMedium.IsAvailable() ) {
         isBadMedium()->push_back( el.isBadMedium() );
      } else {
         isBadMedium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isBadTight.IsAvailable() ) {
         isBadTight()->push_back( el.isBadTight() );
      } else {
         isBadTight()->push_back( std::numeric_limits< int >::min() );
      }
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
      if( el.e_EMB1.IsAvailable() ) {
         e_EMB1()->push_back( el.e_EMB1() );
      } else {
         e_EMB1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_EMB2.IsAvailable() ) {
         e_EMB2()->push_back( el.e_EMB2() );
      } else {
         e_EMB2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_EMB3.IsAvailable() ) {
         e_EMB3()->push_back( el.e_EMB3() );
      } else {
         e_EMB3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_PreSamplerE.IsAvailable() ) {
         e_PreSamplerE()->push_back( el.e_PreSamplerE() );
      } else {
         e_PreSamplerE()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_EME1.IsAvailable() ) {
         e_EME1()->push_back( el.e_EME1() );
      } else {
         e_EME1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_EME2.IsAvailable() ) {
         e_EME2()->push_back( el.e_EME2() );
      } else {
         e_EME2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_EME3.IsAvailable() ) {
         e_EME3()->push_back( el.e_EME3() );
      } else {
         e_EME3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_HEC0.IsAvailable() ) {
         e_HEC0()->push_back( el.e_HEC0() );
      } else {
         e_HEC0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_HEC1.IsAvailable() ) {
         e_HEC1()->push_back( el.e_HEC1() );
      } else {
         e_HEC1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_HEC2.IsAvailable() ) {
         e_HEC2()->push_back( el.e_HEC2() );
      } else {
         e_HEC2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_HEC3.IsAvailable() ) {
         e_HEC3()->push_back( el.e_HEC3() );
      } else {
         e_HEC3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_TileBar0.IsAvailable() ) {
         e_TileBar0()->push_back( el.e_TileBar0() );
      } else {
         e_TileBar0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_TileBar1.IsAvailable() ) {
         e_TileBar1()->push_back( el.e_TileBar1() );
      } else {
         e_TileBar1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_TileBar2.IsAvailable() ) {
         e_TileBar2()->push_back( el.e_TileBar2() );
      } else {
         e_TileBar2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_TileGap1.IsAvailable() ) {
         e_TileGap1()->push_back( el.e_TileGap1() );
      } else {
         e_TileGap1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_TileGap2.IsAvailable() ) {
         e_TileGap2()->push_back( el.e_TileGap2() );
      } else {
         e_TileGap2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_TileGap3.IsAvailable() ) {
         e_TileGap3()->push_back( el.e_TileGap3() );
      } else {
         e_TileGap3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_TileExt0.IsAvailable() ) {
         e_TileExt0()->push_back( el.e_TileExt0() );
      } else {
         e_TileExt0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_TileExt1.IsAvailable() ) {
         e_TileExt1()->push_back( el.e_TileExt1() );
      } else {
         e_TileExt1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_TileExt2.IsAvailable() ) {
         e_TileExt2()->push_back( el.e_TileExt2() );
      } else {
         e_TileExt2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_FCAL0.IsAvailable() ) {
         e_FCAL0()->push_back( el.e_FCAL0() );
      } else {
         e_FCAL0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_FCAL1.IsAvailable() ) {
         e_FCAL1()->push_back( el.e_FCAL1() );
      } else {
         e_FCAL1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.e_FCAL2.IsAvailable() ) {
         e_FCAL2()->push_back( el.e_FCAL2() );
      } else {
         e_FCAL2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Nconst.IsAvailable() ) {
         Nconst()->push_back( el.Nconst() );
      } else {
         Nconst()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.ptconst_default.IsAvailable() ) {
         ptconst_default()->push_back( el.ptconst_default() );
      } else {
         ptconst_default()->push_back( vector<float>() );
      }
      if( el.econst_default.IsAvailable() ) {
         econst_default()->push_back( el.econst_default() );
      } else {
         econst_default()->push_back( vector<float>() );
      }
      if( el.etaconst_default.IsAvailable() ) {
         etaconst_default()->push_back( el.etaconst_default() );
      } else {
         etaconst_default()->push_back( vector<float>() );
      }
      if( el.phiconst_default.IsAvailable() ) {
         phiconst_default()->push_back( el.phiconst_default() );
      } else {
         phiconst_default()->push_back( vector<float>() );
      }
      if( el.weightconst_default.IsAvailable() ) {
         weightconst_default()->push_back( el.weightconst_default() );
      } else {
         weightconst_default()->push_back( vector<float>() );
      }
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
      if( el.flavor_component_ip2d_pu.IsAvailable() ) {
         flavor_component_ip2d_pu()->push_back( el.flavor_component_ip2d_pu() );
      } else {
         flavor_component_ip2d_pu()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_ip2d_pb.IsAvailable() ) {
         flavor_component_ip2d_pb()->push_back( el.flavor_component_ip2d_pb() );
      } else {
         flavor_component_ip2d_pb()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_ip2d_isValid.IsAvailable() ) {
         flavor_component_ip2d_isValid()->push_back( el.flavor_component_ip2d_isValid() );
      } else {
         flavor_component_ip2d_isValid()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_ip2d_ntrk.IsAvailable() ) {
         flavor_component_ip2d_ntrk()->push_back( el.flavor_component_ip2d_ntrk() );
      } else {
         flavor_component_ip2d_ntrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_ip3d_pu.IsAvailable() ) {
         flavor_component_ip3d_pu()->push_back( el.flavor_component_ip3d_pu() );
      } else {
         flavor_component_ip3d_pu()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_ip3d_pb.IsAvailable() ) {
         flavor_component_ip3d_pb()->push_back( el.flavor_component_ip3d_pb() );
      } else {
         flavor_component_ip3d_pb()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_ip3d_isValid.IsAvailable() ) {
         flavor_component_ip3d_isValid()->push_back( el.flavor_component_ip3d_isValid() );
      } else {
         flavor_component_ip3d_isValid()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_ip3d_ntrk.IsAvailable() ) {
         flavor_component_ip3d_ntrk()->push_back( el.flavor_component_ip3d_ntrk() );
      } else {
         flavor_component_ip3d_ntrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_sv1_pu.IsAvailable() ) {
         flavor_component_sv1_pu()->push_back( el.flavor_component_sv1_pu() );
      } else {
         flavor_component_sv1_pu()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_sv1_pb.IsAvailable() ) {
         flavor_component_sv1_pb()->push_back( el.flavor_component_sv1_pb() );
      } else {
         flavor_component_sv1_pb()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_sv1_isValid.IsAvailable() ) {
         flavor_component_sv1_isValid()->push_back( el.flavor_component_sv1_isValid() );
      } else {
         flavor_component_sv1_isValid()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_sv2_pu.IsAvailable() ) {
         flavor_component_sv2_pu()->push_back( el.flavor_component_sv2_pu() );
      } else {
         flavor_component_sv2_pu()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_sv2_pb.IsAvailable() ) {
         flavor_component_sv2_pb()->push_back( el.flavor_component_sv2_pb() );
      } else {
         flavor_component_sv2_pb()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_sv2_isValid.IsAvailable() ) {
         flavor_component_sv2_isValid()->push_back( el.flavor_component_sv2_isValid() );
      } else {
         flavor_component_sv2_isValid()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_jfit_pu.IsAvailable() ) {
         flavor_component_jfit_pu()->push_back( el.flavor_component_jfit_pu() );
      } else {
         flavor_component_jfit_pu()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_jfit_pb.IsAvailable() ) {
         flavor_component_jfit_pb()->push_back( el.flavor_component_jfit_pb() );
      } else {
         flavor_component_jfit_pb()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_jfit_pc.IsAvailable() ) {
         flavor_component_jfit_pc()->push_back( el.flavor_component_jfit_pc() );
      } else {
         flavor_component_jfit_pc()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_jfit_isValid.IsAvailable() ) {
         flavor_component_jfit_isValid()->push_back( el.flavor_component_jfit_isValid() );
      } else {
         flavor_component_jfit_isValid()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_jfitcomb_pu.IsAvailable() ) {
         flavor_component_jfitcomb_pu()->push_back( el.flavor_component_jfitcomb_pu() );
      } else {
         flavor_component_jfitcomb_pu()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_jfitcomb_pb.IsAvailable() ) {
         flavor_component_jfitcomb_pb()->push_back( el.flavor_component_jfitcomb_pb() );
      } else {
         flavor_component_jfitcomb_pb()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_jfitcomb_pc.IsAvailable() ) {
         flavor_component_jfitcomb_pc()->push_back( el.flavor_component_jfitcomb_pc() );
      } else {
         flavor_component_jfitcomb_pc()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_jfitcomb_isValid.IsAvailable() ) {
         flavor_component_jfitcomb_isValid()->push_back( el.flavor_component_jfitcomb_isValid() );
      } else {
         flavor_component_jfitcomb_isValid()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_jfit_nvtx.IsAvailable() ) {
         flavor_component_jfit_nvtx()->push_back( el.flavor_component_jfit_nvtx() );
      } else {
         flavor_component_jfit_nvtx()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_jfit_nvtx1t.IsAvailable() ) {
         flavor_component_jfit_nvtx1t()->push_back( el.flavor_component_jfit_nvtx1t() );
      } else {
         flavor_component_jfit_nvtx1t()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_jfit_ntrkAtVx.IsAvailable() ) {
         flavor_component_jfit_ntrkAtVx()->push_back( el.flavor_component_jfit_ntrkAtVx() );
      } else {
         flavor_component_jfit_ntrkAtVx()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_jfit_efrc.IsAvailable() ) {
         flavor_component_jfit_efrc()->push_back( el.flavor_component_jfit_efrc() );
      } else {
         flavor_component_jfit_efrc()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_jfit_mass.IsAvailable() ) {
         flavor_component_jfit_mass()->push_back( el.flavor_component_jfit_mass() );
      } else {
         flavor_component_jfit_mass()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_jfit_sig3d.IsAvailable() ) {
         flavor_component_jfit_sig3d()->push_back( el.flavor_component_jfit_sig3d() );
      } else {
         flavor_component_jfit_sig3d()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_jfit_deltaPhi.IsAvailable() ) {
         flavor_component_jfit_deltaPhi()->push_back( el.flavor_component_jfit_deltaPhi() );
      } else {
         flavor_component_jfit_deltaPhi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_jfit_deltaEta.IsAvailable() ) {
         flavor_component_jfit_deltaEta()->push_back( el.flavor_component_jfit_deltaEta() );
      } else {
         flavor_component_jfit_deltaEta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_svp_isValid.IsAvailable() ) {
         flavor_component_svp_isValid()->push_back( el.flavor_component_svp_isValid() );
      } else {
         flavor_component_svp_isValid()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_svp_ntrkv.IsAvailable() ) {
         flavor_component_svp_ntrkv()->push_back( el.flavor_component_svp_ntrkv() );
      } else {
         flavor_component_svp_ntrkv()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_svp_ntrkj.IsAvailable() ) {
         flavor_component_svp_ntrkj()->push_back( el.flavor_component_svp_ntrkj() );
      } else {
         flavor_component_svp_ntrkj()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_svp_n2t.IsAvailable() ) {
         flavor_component_svp_n2t()->push_back( el.flavor_component_svp_n2t() );
      } else {
         flavor_component_svp_n2t()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_svp_mass.IsAvailable() ) {
         flavor_component_svp_mass()->push_back( el.flavor_component_svp_mass() );
      } else {
         flavor_component_svp_mass()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_svp_efrc.IsAvailable() ) {
         flavor_component_svp_efrc()->push_back( el.flavor_component_svp_efrc() );
      } else {
         flavor_component_svp_efrc()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_svp_x.IsAvailable() ) {
         flavor_component_svp_x()->push_back( el.flavor_component_svp_x() );
      } else {
         flavor_component_svp_x()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_svp_y.IsAvailable() ) {
         flavor_component_svp_y()->push_back( el.flavor_component_svp_y() );
      } else {
         flavor_component_svp_y()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_svp_z.IsAvailable() ) {
         flavor_component_svp_z()->push_back( el.flavor_component_svp_z() );
      } else {
         flavor_component_svp_z()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_svp_err_x.IsAvailable() ) {
         flavor_component_svp_err_x()->push_back( el.flavor_component_svp_err_x() );
      } else {
         flavor_component_svp_err_x()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_svp_err_y.IsAvailable() ) {
         flavor_component_svp_err_y()->push_back( el.flavor_component_svp_err_y() );
      } else {
         flavor_component_svp_err_y()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_svp_err_z.IsAvailable() ) {
         flavor_component_svp_err_z()->push_back( el.flavor_component_svp_err_z() );
      } else {
         flavor_component_svp_err_z()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_svp_cov_xy.IsAvailable() ) {
         flavor_component_svp_cov_xy()->push_back( el.flavor_component_svp_cov_xy() );
      } else {
         flavor_component_svp_cov_xy()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_svp_cov_xz.IsAvailable() ) {
         flavor_component_svp_cov_xz()->push_back( el.flavor_component_svp_cov_xz() );
      } else {
         flavor_component_svp_cov_xz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_svp_cov_yz.IsAvailable() ) {
         flavor_component_svp_cov_yz()->push_back( el.flavor_component_svp_cov_yz() );
      } else {
         flavor_component_svp_cov_yz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_svp_chi2.IsAvailable() ) {
         flavor_component_svp_chi2()->push_back( el.flavor_component_svp_chi2() );
      } else {
         flavor_component_svp_chi2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_svp_ndof.IsAvailable() ) {
         flavor_component_svp_ndof()->push_back( el.flavor_component_svp_ndof() );
      } else {
         flavor_component_svp_ndof()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_svp_ntrk.IsAvailable() ) {
         flavor_component_svp_ntrk()->push_back( el.flavor_component_svp_ntrk() );
      } else {
         flavor_component_svp_ntrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_sv0p_isValid.IsAvailable() ) {
         flavor_component_sv0p_isValid()->push_back( el.flavor_component_sv0p_isValid() );
      } else {
         flavor_component_sv0p_isValid()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_sv0p_ntrkv.IsAvailable() ) {
         flavor_component_sv0p_ntrkv()->push_back( el.flavor_component_sv0p_ntrkv() );
      } else {
         flavor_component_sv0p_ntrkv()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_sv0p_ntrkj.IsAvailable() ) {
         flavor_component_sv0p_ntrkj()->push_back( el.flavor_component_sv0p_ntrkj() );
      } else {
         flavor_component_sv0p_ntrkj()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_sv0p_n2t.IsAvailable() ) {
         flavor_component_sv0p_n2t()->push_back( el.flavor_component_sv0p_n2t() );
      } else {
         flavor_component_sv0p_n2t()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_sv0p_mass.IsAvailable() ) {
         flavor_component_sv0p_mass()->push_back( el.flavor_component_sv0p_mass() );
      } else {
         flavor_component_sv0p_mass()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_sv0p_efrc.IsAvailable() ) {
         flavor_component_sv0p_efrc()->push_back( el.flavor_component_sv0p_efrc() );
      } else {
         flavor_component_sv0p_efrc()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_sv0p_x.IsAvailable() ) {
         flavor_component_sv0p_x()->push_back( el.flavor_component_sv0p_x() );
      } else {
         flavor_component_sv0p_x()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_sv0p_y.IsAvailable() ) {
         flavor_component_sv0p_y()->push_back( el.flavor_component_sv0p_y() );
      } else {
         flavor_component_sv0p_y()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_sv0p_z.IsAvailable() ) {
         flavor_component_sv0p_z()->push_back( el.flavor_component_sv0p_z() );
      } else {
         flavor_component_sv0p_z()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_sv0p_err_x.IsAvailable() ) {
         flavor_component_sv0p_err_x()->push_back( el.flavor_component_sv0p_err_x() );
      } else {
         flavor_component_sv0p_err_x()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_sv0p_err_y.IsAvailable() ) {
         flavor_component_sv0p_err_y()->push_back( el.flavor_component_sv0p_err_y() );
      } else {
         flavor_component_sv0p_err_y()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_sv0p_err_z.IsAvailable() ) {
         flavor_component_sv0p_err_z()->push_back( el.flavor_component_sv0p_err_z() );
      } else {
         flavor_component_sv0p_err_z()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_sv0p_cov_xy.IsAvailable() ) {
         flavor_component_sv0p_cov_xy()->push_back( el.flavor_component_sv0p_cov_xy() );
      } else {
         flavor_component_sv0p_cov_xy()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_sv0p_cov_xz.IsAvailable() ) {
         flavor_component_sv0p_cov_xz()->push_back( el.flavor_component_sv0p_cov_xz() );
      } else {
         flavor_component_sv0p_cov_xz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_sv0p_cov_yz.IsAvailable() ) {
         flavor_component_sv0p_cov_yz()->push_back( el.flavor_component_sv0p_cov_yz() );
      } else {
         flavor_component_sv0p_cov_yz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_sv0p_chi2.IsAvailable() ) {
         flavor_component_sv0p_chi2()->push_back( el.flavor_component_sv0p_chi2() );
      } else {
         flavor_component_sv0p_chi2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.flavor_component_sv0p_ndof.IsAvailable() ) {
         flavor_component_sv0p_ndof()->push_back( el.flavor_component_sv0p_ndof() );
      } else {
         flavor_component_sv0p_ndof()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_component_sv0p_ntrk.IsAvailable() ) {
         flavor_component_sv0p_ntrk()->push_back( el.flavor_component_sv0p_ntrk() );
      } else {
         flavor_component_sv0p_ntrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_assoctrk_n.IsAvailable() ) {
         flavor_assoctrk_n()->push_back( el.flavor_assoctrk_n() );
      } else {
         flavor_assoctrk_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.flavor_assoctrk_index.IsAvailable() ) {
         flavor_assoctrk_index()->push_back( el.flavor_assoctrk_index() );
      } else {
         flavor_assoctrk_index()->push_back( vector<int>() );
      }
      if( el.el_dr.IsAvailable() ) {
         el_dr()->push_back( el.el_dr() );
      } else {
         el_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.el_matched.IsAvailable() ) {
         el_matched()->push_back( el.el_matched() );
      } else {
         el_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.mu_dr.IsAvailable() ) {
         mu_dr()->push_back( el.mu_dr() );
      } else {
         mu_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.mu_matched.IsAvailable() ) {
         mu_matched()->push_back( el.mu_matched() );
      } else {
         mu_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.L1_dr.IsAvailable() ) {
         L1_dr()->push_back( el.L1_dr() );
      } else {
         L1_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L1_matched.IsAvailable() ) {
         L1_matched()->push_back( el.L1_matched() );
      } else {
         L1_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.L2_dr.IsAvailable() ) {
         L2_dr()->push_back( el.L2_dr() );
      } else {
         L2_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2_matched.IsAvailable() ) {
         L2_matched()->push_back( el.L2_matched() );
      } else {
         L2_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.EF_dr.IsAvailable() ) {
         EF_dr()->push_back( el.EF_dr() );
      } else {
         EF_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_matched.IsAvailable() ) {
         EF_matched()->push_back( el.EF_matched() );
      } else {
         EF_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.bbDecision.IsAvailable() ) {
         bbDecision()->push_back( el.bbDecision() );
      } else {
         bbDecision()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.SmearingFactor.IsAvailable() ) {
         SmearingFactor()->push_back( el.SmearingFactor() );
      } else {
         SmearingFactor()->push_back( std::numeric_limits< float >::min() );
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
