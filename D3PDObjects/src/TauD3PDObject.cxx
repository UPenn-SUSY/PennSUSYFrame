// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <limits>

#include <TPRegexp.h>

#include "../include/TauD3PDObject.h"

ClassImp( D3PDReader::TauD3PDObjectElement )
ClassImp( D3PDReader::TauD3PDObject )

namespace D3PDReader {

   /**
    * This constructor can be used to create new proxy objects from scratch.
    * Since the constructor of such an object is quite complicated and
    * error prone, it is only visible to the parent class TauD3PDObject.
    */
   TauD3PDObjectElement::TauD3PDObjectElement( size_t index, const TauD3PDObject& parent , bool is_data )
      : Et( parent.Et, index, this ),
        pt( parent.pt, index, this ),
        m( parent.m, index, this ),
        eta( parent.eta, index, this ),
        phi( parent.phi, index, this ),
        charge( parent.charge, index, this ),
        BDTEleScore( parent.BDTEleScore, index, this ),
        BDTJetScore( parent.BDTJetScore, index, this ),
        likelihood( parent.likelihood, index, this ),
        SafeLikelihood( parent.SafeLikelihood, index, this ),
        electronVetoLoose( parent.electronVetoLoose, index, this ),
        electronVetoMedium( parent.electronVetoMedium, index, this ),
        electronVetoTight( parent.electronVetoTight, index, this ),
        muonVeto( parent.muonVeto, index, this ),
        tauLlhLoose( parent.tauLlhLoose, index, this ),
        tauLlhMedium( parent.tauLlhMedium, index, this ),
        tauLlhTight( parent.tauLlhTight, index, this ),
        JetBDTSigLoose( parent.JetBDTSigLoose, index, this ),
        JetBDTSigMedium( parent.JetBDTSigMedium, index, this ),
        JetBDTSigTight( parent.JetBDTSigTight, index, this ),
        EleBDTLoose( parent.EleBDTLoose, index, this ),
        EleBDTMedium( parent.EleBDTMedium, index, this ),
        EleBDTTight( parent.EleBDTTight, index, this ),
        author( parent.author, index, this ),
        RoIWord( parent.RoIWord, index, this ),
        nProng( parent.nProng, index, this ),
        numTrack( parent.numTrack, index, this ),
        seedCalo_numTrack( parent.seedCalo_numTrack, index, this ),
        seedCalo_nWideTrk( parent.seedCalo_nWideTrk, index, this ),
        nOtherTrk( parent.nOtherTrk, index, this ),
        etOverPtLeadTrk( parent.etOverPtLeadTrk, index, this ),
        ipZ0SinThetaSigLeadTrk( parent.ipZ0SinThetaSigLeadTrk, index, this ),
        leadTrkPt( parent.leadTrkPt, index, this ),
        nLooseTrk( parent.nLooseTrk, index, this ),
        nLooseConvTrk( parent.nLooseConvTrk, index, this ),
        nProngLoose( parent.nProngLoose, index, this ),
        ipSigLeadTrk( parent.ipSigLeadTrk, index, this ),
        ipSigLeadLooseTrk( parent.ipSigLeadLooseTrk, index, this ),
        etOverPtLeadLooseTrk( parent.etOverPtLeadLooseTrk, index, this ),
        leadLooseTrkPt( parent.leadLooseTrkPt, index, this ),
        chrgLooseTrk( parent.chrgLooseTrk, index, this ),
        massTrkSys( parent.massTrkSys, index, this ),
        trkWidth2( parent.trkWidth2, index, this ),
        trFlightPathSig( parent.trFlightPathSig, index, this ),
        etEflow( parent.etEflow, index, this ),
        mEflow( parent.mEflow, index, this ),
        nPi0( parent.nPi0, index, this ),
        ele_E237E277( parent.ele_E237E277, index, this ),
        ele_PresamplerFraction( parent.ele_PresamplerFraction, index, this ),
        ele_ECALFirstFraction( parent.ele_ECALFirstFraction, index, this ),
        EM_TES_scale( parent.EM_TES_scale, index, this ),
        LC_TES_precalib( parent.LC_TES_precalib, index, this ),
        TRTHTOverLT_LeadTrk( parent.TRTHTOverLT_LeadTrk, index, this ),
        seedCalo_EMRadius( parent.seedCalo_EMRadius, index, this ),
        seedCalo_hadRadius( parent.seedCalo_hadRadius, index, this ),
        seedCalo_etEMAtEMScale( parent.seedCalo_etEMAtEMScale, index, this ),
        seedCalo_etHadAtEMScale( parent.seedCalo_etHadAtEMScale, index, this ),
        seedCalo_isolFrac( parent.seedCalo_isolFrac, index, this ),
        seedCalo_centFrac( parent.seedCalo_centFrac, index, this ),
        seedCalo_stripWidth2( parent.seedCalo_stripWidth2, index, this ),
        seedCalo_nStrip( parent.seedCalo_nStrip, index, this ),
        seedCalo_eta( parent.seedCalo_eta, index, this ),
        seedCalo_phi( parent.seedCalo_phi, index, this ),
        seedCalo_nIsolLooseTrk( parent.seedCalo_nIsolLooseTrk, index, this ),
        seedCalo_trkAvgDist( parent.seedCalo_trkAvgDist, index, this ),
        seedCalo_trkRmsDist( parent.seedCalo_trkRmsDist, index, this ),
        seedCalo_caloIso( parent.seedCalo_caloIso, index, this ),
        seedCalo_caloIsoCorrected( parent.seedCalo_caloIsoCorrected, index, this ),
        seedCalo_dRmax( parent.seedCalo_dRmax, index, this ),
        seedCalo_lead2ClusterEOverAllClusterE( parent.seedCalo_lead2ClusterEOverAllClusterE, index, this ),
        seedCalo_lead3ClusterEOverAllClusterE( parent.seedCalo_lead3ClusterEOverAllClusterE, index, this ),
        seedCalo_etHadCalib( parent.seedCalo_etHadCalib, index, this ),
        seedCalo_etEMCalib( parent.seedCalo_etEMCalib, index, this ),
        numTopoClusters( parent.numTopoClusters, index, this ),
        numEffTopoClusters( parent.numEffTopoClusters, index, this ),
        topoInvMass( parent.topoInvMass, index, this ),
        effTopoInvMass( parent.effTopoInvMass, index, this ),
        topoMeanDeltaR( parent.topoMeanDeltaR, index, this ),
        effTopoMeanDeltaR( parent.effTopoMeanDeltaR, index, this ),
        numCells( parent.numCells, index, this ),
        seedTrk_EMRadius( parent.seedTrk_EMRadius, index, this ),
        seedTrk_isolFrac( parent.seedTrk_isolFrac, index, this ),
        seedTrk_etChrgHadOverSumTrkPt( parent.seedTrk_etChrgHadOverSumTrkPt, index, this ),
        seedTrk_isolFracWide( parent.seedTrk_isolFracWide, index, this ),
        seedTrk_etHadAtEMScale( parent.seedTrk_etHadAtEMScale, index, this ),
        seedTrk_etEMAtEMScale( parent.seedTrk_etEMAtEMScale, index, this ),
        seedTrk_etEMCL( parent.seedTrk_etEMCL, index, this ),
        seedTrk_etChrgEM( parent.seedTrk_etChrgEM, index, this ),
        seedTrk_etNeuEM( parent.seedTrk_etNeuEM, index, this ),
        seedTrk_etResNeuEM( parent.seedTrk_etResNeuEM, index, this ),
        seedTrk_hadLeakEt( parent.seedTrk_hadLeakEt, index, this ),
        seedTrk_sumEMCellEtOverLeadTrkPt( parent.seedTrk_sumEMCellEtOverLeadTrkPt, index, this ),
        seedTrk_secMaxStripEt( parent.seedTrk_secMaxStripEt, index, this ),
        seedTrk_stripWidth2( parent.seedTrk_stripWidth2, index, this ),
        seedTrk_nStrip( parent.seedTrk_nStrip, index, this ),
        seedTrk_etChrgHad( parent.seedTrk_etChrgHad, index, this ),
        seedTrk_nOtherCoreTrk( parent.seedTrk_nOtherCoreTrk, index, this ),
        seedTrk_nIsolTrk( parent.seedTrk_nIsolTrk, index, this ),
        seedTrk_etIsolEM( parent.seedTrk_etIsolEM, index, this ),
        seedTrk_etIsolHad( parent.seedTrk_etIsolHad, index, this ),
        cellBasedEnergyRing1( parent.cellBasedEnergyRing1, index, this ),
        cellBasedEnergyRing2( parent.cellBasedEnergyRing2, index, this ),
        cellBasedEnergyRing3( parent.cellBasedEnergyRing3, index, this ),
        cellBasedEnergyRing4( parent.cellBasedEnergyRing4, index, this ),
        cellBasedEnergyRing5( parent.cellBasedEnergyRing5, index, this ),
        cellBasedEnergyRing6( parent.cellBasedEnergyRing6, index, this ),
        cellBasedEnergyRing7( parent.cellBasedEnergyRing7, index, this ),
        calcVars_etHad_EMScale_Pt3Trks( parent.calcVars_etHad_EMScale_Pt3Trks, index, this ),
        calcVars_etEM_EMScale_Pt3Trks( parent.calcVars_etEM_EMScale_Pt3Trks, index, this ),
        calcVars_ipSigLeadLooseTrk( parent.calcVars_ipSigLeadLooseTrk, index, this ),
        calcVars_drMin( parent.calcVars_drMin, index, this ),
        calcVars_calRadius( parent.calcVars_calRadius, index, this ),
        calcVars_EMFractionAtEMScale( parent.calcVars_EMFractionAtEMScale, index, this ),
        calcVars_trackIso( parent.calcVars_trackIso, index, this ),
        calcVars_ChPiEMEOverCaloEME( parent.calcVars_ChPiEMEOverCaloEME, index, this ),
        calcVars_PSSFraction( parent.calcVars_PSSFraction, index, this ),
        calcVars_EMPOverTrkSysP( parent.calcVars_EMPOverTrkSysP, index, this ),
        calcVars_pi0BDTPrimaryScore( parent.calcVars_pi0BDTPrimaryScore, index, this ),
        calcVars_pi0BDTSecondaryScore( parent.calcVars_pi0BDTSecondaryScore, index, this ),
        calcVars_corrCentFrac( parent.calcVars_corrCentFrac, index, this ),
        calcVars_corrFTrk( parent.calcVars_corrFTrk, index, this ),
        calcVars_interAxis_eta( parent.calcVars_interAxis_eta, index, this ),
        calcVars_interAxis_phi( parent.calcVars_interAxis_phi, index, this ),
        pi0_cl1_pt( parent.pi0_cl1_pt, index, this ),
        pi0_cl1_eta( parent.pi0_cl1_eta, index, this ),
        pi0_cl1_phi( parent.pi0_cl1_phi, index, this ),
        pi0_cl2_pt( parent.pi0_cl2_pt, index, this ),
        pi0_cl2_eta( parent.pi0_cl2_eta, index, this ),
        pi0_cl2_phi( parent.pi0_cl2_phi, index, this ),
        pi0_vistau_pt( parent.pi0_vistau_pt, index, this ),
        pi0_vistau_eta( parent.pi0_vistau_eta, index, this ),
        pi0_vistau_phi( parent.pi0_vistau_phi, index, this ),
        pi0_vistau_m( parent.pi0_vistau_m, index, this ),
        pi0_n( parent.pi0_n, index, this ),
        pantau_isPanTauCandidate( parent.pantau_isPanTauCandidate, index, this ),
        pantau_PanTauScore( parent.pantau_PanTauScore, index, this ),
        pantau_NChargedEFO( parent.pantau_NChargedEFO, index, this ),
        pantau_NChargedQualifiedEFO( parent.pantau_NChargedQualifiedEFO, index, this ),
        pantau_NNeutralEFO( parent.pantau_NNeutralEFO, index, this ),
        pantau_AbsSumCharge( parent.pantau_AbsSumCharge, index, this ),
        pantau_EflowJetMomentDRAll( parent.pantau_EflowJetMomentDRAll, index, this ),
        pantau_EflowJetMomentDRChrg( parent.pantau_EflowJetMomentDRChrg, index, this ),
        pantau_EflowJetMomentDREMNeut( parent.pantau_EflowJetMomentDREMNeut, index, this ),
        pantau_EflowJetMomentDRHADNeut( parent.pantau_EflowJetMomentDRHADNeut, index, this ),
        pantau_EtIn01OverEtIn02InvSigm( parent.pantau_EtIn01OverEtIn02InvSigm, index, this ),
        pantau_EtIn02To04OverTotalEtInvSigm( parent.pantau_EtIn02To04OverTotalEtInvSigm, index, this ),
        pantau_EtIn01OverEtIn04InvSigm( parent.pantau_EtIn01OverEtIn04InvSigm, index, this ),
        pantau_EtIn01OverEtIn04( parent.pantau_EtIn01OverEtIn04, index, this ),
        pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents( parent.pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents, index, this ),
        pantau_JetSphericity( parent.pantau_JetSphericity, index, this ),
        pantau_TransImpactParamSignfTrack1( parent.pantau_TransImpactParamSignfTrack1, index, this ),
        pantau_EflowAngleJetAxisLeadingChargedQualified( parent.pantau_EflowAngleJetAxisLeadingChargedQualified, index, this ),
        pantau_EflowAngleChargedAxisNeutralAxis( parent.pantau_EflowAngleChargedAxisNeutralAxis, index, this ),
        pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified( parent.pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified, index, this ),
        pantau_EflowInvariantMassAll( parent.pantau_EflowInvariantMassAll, index, this ),
        pantau_EflowStdDevEtToSumEt( parent.pantau_EflowStdDevEtToSumEt, index, this ),
        pantau_EflowEtLeadingChrgQualifiedOverTotalEt( parent.pantau_EflowEtLeadingChrgQualifiedOverTotalEt, index, this ),
        pantau_EflowSumEAll( parent.pantau_EflowSumEAll, index, this ),
        pantau_EflowChargedSumEt( parent.pantau_EflowChargedSumEt, index, this ),
        leadTrack_eta( parent.leadTrack_eta, index, this ),
        leadTrack_phi( parent.leadTrack_phi, index, this ),
        cluster_E( parent.cluster_E, index, this ),
        cluster_eta( parent.cluster_eta, index, this ),
        cluster_phi( parent.cluster_phi, index, this ),
        cluster_eta_atTJVA( parent.cluster_eta_atTJVA, index, this ),
        cluster_phi_atTJVA( parent.cluster_phi_atTJVA, index, this ),
        cluster_PreSamplerStripF( parent.cluster_PreSamplerStripF, index, this ),
        cluster_EMLayer2F( parent.cluster_EMLayer2F, index, this ),
        cluster_EMLayer3F( parent.cluster_EMLayer3F, index, this ),
        cluster_n( parent.cluster_n, index, this ),
        Pi0Cluster_pt( parent.Pi0Cluster_pt, index, this ),
        Pi0Cluster_eta( parent.Pi0Cluster_eta, index, this ),
        Pi0Cluster_phi( parent.Pi0Cluster_phi, index, this ),
        secvtx_x( parent.secvtx_x, index, this ),
        secvtx_y( parent.secvtx_y, index, this ),
        secvtx_z( parent.secvtx_z, index, this ),
        secvtx_xx( parent.secvtx_xx, index, this ),
        secvtx_yy( parent.secvtx_yy, index, this ),
        secvtx_zz( parent.secvtx_zz, index, this ),
        secvtx_xy( parent.secvtx_xy, index, this ),
        secvtx_yz( parent.secvtx_yz, index, this ),
        secvtx_zx( parent.secvtx_zx, index, this ),
        secvtx_chiSquared( parent.secvtx_chiSquared, index, this ),
        secvtx_numberDoF( parent.secvtx_numberDoF, index, this ),
        privtx_x( parent.privtx_x, index, this ),
        privtx_y( parent.privtx_y, index, this ),
        privtx_z( parent.privtx_z, index, this ),
        privtx_xx( parent.privtx_xx, index, this ),
        privtx_yy( parent.privtx_yy, index, this ),
        privtx_zz( parent.privtx_zz, index, this ),
        privtx_xy( parent.privtx_xy, index, this ),
        privtx_yz( parent.privtx_yz, index, this ),
        privtx_zx( parent.privtx_zx, index, this ),
        privtx_chiSquared( parent.privtx_chiSquared, index, this ),
        privtx_numberDoF( parent.privtx_numberDoF, index, this ),
        privtx_jvf( parent.privtx_jvf, index, this ),
        jet_Et( parent.jet_Et, index, this ),
        jet_pt( parent.jet_pt, index, this ),
        jet_m( parent.jet_m, index, this ),
        jet_eta( parent.jet_eta, index, this ),
        jet_phi( parent.jet_phi, index, this ),
        jet_WIDTH( parent.jet_WIDTH, index, this ),
        jet_n90( parent.jet_n90, index, this ),
        jet_n90constituents( parent.jet_n90constituents, index, this ),
        jet_BCH_CORR_CELL( parent.jet_BCH_CORR_CELL, index, this ),
        jet_BCH_CORR_JET( parent.jet_BCH_CORR_JET, index, this ),
        jet_BCH_CORR_JET_FORCELL( parent.jet_BCH_CORR_JET_FORCELL, index, this ),
        jet_ENG_BAD_CELLS( parent.jet_ENG_BAD_CELLS, index, this ),
        jet_N_BAD_CELLS( parent.jet_N_BAD_CELLS, index, this ),
        jet_N_BAD_CELLS_CORR( parent.jet_N_BAD_CELLS_CORR, index, this ),
        jet_BAD_CELLS_CORR_E( parent.jet_BAD_CELLS_CORR_E, index, this ),
        jet_Timing( parent.jet_Timing, index, this ),
        jet_LArQuality( parent.jet_LArQuality, index, this ),
        jet_nTrk( parent.jet_nTrk, index, this ),
        jet_sumPtTrk( parent.jet_sumPtTrk, index, this ),
        jet_OriginIndex( parent.jet_OriginIndex, index, this ),
        jet_HECQuality( parent.jet_HECQuality, index, this ),
        jet_NegativeE( parent.jet_NegativeE, index, this ),
        jet_YFlip12( parent.jet_YFlip12, index, this ),
        jet_YFlip23( parent.jet_YFlip23, index, this ),
        jet_BCH_CORR_DOTX( parent.jet_BCH_CORR_DOTX, index, this ),
        jet_SamplingMax( parent.jet_SamplingMax, index, this ),
        jet_fracSamplingMax( parent.jet_fracSamplingMax, index, this ),
        jet_hecf( parent.jet_hecf, index, this ),
        jet_tgap3f( parent.jet_tgap3f, index, this ),
        jet_isUgly( parent.jet_isUgly, index, this ),
        jet_isBadLooseMinus( parent.jet_isBadLooseMinus, index, this ),
        jet_isBadLoose( parent.jet_isBadLoose, index, this ),
        jet_isBadMedium( parent.jet_isBadMedium, index, this ),
        jet_isBadTight( parent.jet_isBadTight, index, this ),
        jet_emfrac( parent.jet_emfrac, index, this ),
        jet_GCWJES( parent.jet_GCWJES, index, this ),
        jet_EMJES( parent.jet_EMJES, index, this ),
        jet_emscale_E( parent.jet_emscale_E, index, this ),
        jet_emscale_pt( parent.jet_emscale_pt, index, this ),
        jet_emscale_m( parent.jet_emscale_m, index, this ),
        jet_emscale_eta( parent.jet_emscale_eta, index, this ),
        jet_emscale_phi( parent.jet_emscale_phi, index, this ),
        jet_jvtx_x( parent.jet_jvtx_x, index, this ),
        jet_jvtx_y( parent.jet_jvtx_y, index, this ),
        jet_jvtx_z( parent.jet_jvtx_z, index, this ),
        jet_jvtxf( parent.jet_jvtxf, index, this ),
        jet_flavor_weight( parent.jet_flavor_weight, index, this ),
        jet_flavor_weight_TrackCounting2D( parent.jet_flavor_weight_TrackCounting2D, index, this ),
        jet_flavor_weight_JetProb( parent.jet_flavor_weight_JetProb, index, this ),
        jet_flavor_weight_IP1D( parent.jet_flavor_weight_IP1D, index, this ),
        jet_flavor_weight_IP2D( parent.jet_flavor_weight_IP2D, index, this ),
        jet_flavor_weight_IP3D( parent.jet_flavor_weight_IP3D, index, this ),
        jet_flavor_weight_SV0( parent.jet_flavor_weight_SV0, index, this ),
        jet_flavor_weight_SV1( parent.jet_flavor_weight_SV1, index, this ),
        jet_flavor_weight_SV2( parent.jet_flavor_weight_SV2, index, this ),
        jet_flavor_weight_JetFitterTag( parent.jet_flavor_weight_JetFitterTag, index, this ),
        jet_flavor_weight_JetFitterCOMB( parent.jet_flavor_weight_JetFitterCOMB, index, this ),
        jet_flavor_weight_JetFitterTagNN( parent.jet_flavor_weight_JetFitterTagNN, index, this ),
        jet_flavor_weight_JetFitterCOMBNN( parent.jet_flavor_weight_JetFitterCOMBNN, index, this ),
        jet_flavor_weight_SoftMuonTag( parent.jet_flavor_weight_SoftMuonTag, index, this ),
        jet_flavor_weight_SoftElectronTag( parent.jet_flavor_weight_SoftElectronTag, index, this ),
        jet_flavor_weight_IP3DSV1( parent.jet_flavor_weight_IP3DSV1, index, this ),
        jet_e_PreSamplerB( parent.jet_e_PreSamplerB, index, this ),
        jet_e_EMB1( parent.jet_e_EMB1, index, this ),
        jet_e_EMB2( parent.jet_e_EMB2, index, this ),
        jet_e_EMB3( parent.jet_e_EMB3, index, this ),
        jet_e_PreSamplerE( parent.jet_e_PreSamplerE, index, this ),
        jet_e_EME1( parent.jet_e_EME1, index, this ),
        jet_e_EME2( parent.jet_e_EME2, index, this ),
        jet_e_EME3( parent.jet_e_EME3, index, this ),
        jet_e_HEC0( parent.jet_e_HEC0, index, this ),
        jet_e_HEC1( parent.jet_e_HEC1, index, this ),
        jet_e_HEC2( parent.jet_e_HEC2, index, this ),
        jet_e_HEC3( parent.jet_e_HEC3, index, this ),
        jet_e_TileBar0( parent.jet_e_TileBar0, index, this ),
        jet_e_TileBar1( parent.jet_e_TileBar1, index, this ),
        jet_e_TileBar2( parent.jet_e_TileBar2, index, this ),
        jet_e_TileGap1( parent.jet_e_TileGap1, index, this ),
        jet_e_TileGap2( parent.jet_e_TileGap2, index, this ),
        jet_e_TileGap3( parent.jet_e_TileGap3, index, this ),
        jet_e_TileExt0( parent.jet_e_TileExt0, index, this ),
        jet_e_TileExt1( parent.jet_e_TileExt1, index, this ),
        jet_e_TileExt2( parent.jet_e_TileExt2, index, this ),
        jet_e_FCAL0( parent.jet_e_FCAL0, index, this ),
        jet_e_FCAL1( parent.jet_e_FCAL1, index, this ),
        jet_e_FCAL2( parent.jet_e_FCAL2, index, this ),
        jet_shapeBins( parent.jet_shapeBins, index, this ),
        track_atTJVA_n( parent.track_atTJVA_n, index, this ),
        track_atTJVA_d0( parent.track_atTJVA_d0, index, this ),
        track_atTJVA_z0( parent.track_atTJVA_z0, index, this ),
        track_atTJVA_phi( parent.track_atTJVA_phi, index, this ),
        track_atTJVA_theta( parent.track_atTJVA_theta, index, this ),
        track_atTJVA_qoverp( parent.track_atTJVA_qoverp, index, this ),
        track_atTJVA_pt( parent.track_atTJVA_pt, index, this ),
        track_atTJVA_eta( parent.track_atTJVA_eta, index, this ),
        seedCalo_wideTrk_atTJVA_n( parent.seedCalo_wideTrk_atTJVA_n, index, this ),
        seedCalo_wideTrk_atTJVA_d0( parent.seedCalo_wideTrk_atTJVA_d0, index, this ),
        seedCalo_wideTrk_atTJVA_z0( parent.seedCalo_wideTrk_atTJVA_z0, index, this ),
        seedCalo_wideTrk_atTJVA_phi( parent.seedCalo_wideTrk_atTJVA_phi, index, this ),
        seedCalo_wideTrk_atTJVA_theta( parent.seedCalo_wideTrk_atTJVA_theta, index, this ),
        seedCalo_wideTrk_atTJVA_qoverp( parent.seedCalo_wideTrk_atTJVA_qoverp, index, this ),
        seedCalo_wideTrk_atTJVA_pt( parent.seedCalo_wideTrk_atTJVA_pt, index, this ),
        seedCalo_wideTrk_atTJVA_eta( parent.seedCalo_wideTrk_atTJVA_eta, index, this ),
        otherTrk_atTJVA_n( parent.otherTrk_atTJVA_n, index, this ),
        track_n( parent.track_n, index, this ),
        track_d0( parent.track_d0, index, this ),
        track_z0( parent.track_z0, index, this ),
        track_phi( parent.track_phi, index, this ),
        track_theta( parent.track_theta, index, this ),
        track_qoverp( parent.track_qoverp, index, this ),
        track_pt( parent.track_pt, index, this ),
        track_eta( parent.track_eta, index, this ),
        track_atPV_d0( parent.track_atPV_d0, index, this ),
        track_atPV_z0( parent.track_atPV_z0, index, this ),
        track_atPV_phi( parent.track_atPV_phi, index, this ),
        track_atPV_theta( parent.track_atPV_theta, index, this ),
        track_atPV_qoverp( parent.track_atPV_qoverp, index, this ),
        track_atPV_pt( parent.track_atPV_pt, index, this ),
        track_atPV_eta( parent.track_atPV_eta, index, this ),
        track_nBLHits( parent.track_nBLHits, index, this ),
        track_nPixHits( parent.track_nPixHits, index, this ),
        track_nSCTHits( parent.track_nSCTHits, index, this ),
        track_nTRTHits( parent.track_nTRTHits, index, this ),
        track_nTRTHighTHits( parent.track_nTRTHighTHits, index, this ),
        track_nTRTXenonHits( parent.track_nTRTXenonHits, index, this ),
        track_nPixHoles( parent.track_nPixHoles, index, this ),
        track_nSCTHoles( parent.track_nSCTHoles, index, this ),
        track_nTRTHoles( parent.track_nTRTHoles, index, this ),
        track_nPixelDeadSensors( parent.track_nPixelDeadSensors, index, this ),
        track_nSCTDeadSensors( parent.track_nSCTDeadSensors, index, this ),
        track_nBLSharedHits( parent.track_nBLSharedHits, index, this ),
        track_nPixSharedHits( parent.track_nPixSharedHits, index, this ),
        track_nSCTSharedHits( parent.track_nSCTSharedHits, index, this ),
        track_nBLayerSplitHits( parent.track_nBLayerSplitHits, index, this ),
        track_nPixSplitHits( parent.track_nPixSplitHits, index, this ),
        track_nBLayerOutliers( parent.track_nBLayerOutliers, index, this ),
        track_nPixelOutliers( parent.track_nPixelOutliers, index, this ),
        track_nSCTOutliers( parent.track_nSCTOutliers, index, this ),
        track_nTRTOutliers( parent.track_nTRTOutliers, index, this ),
        track_nTRTHighTOutliers( parent.track_nTRTHighTOutliers, index, this ),
        track_nContribPixelLayers( parent.track_nContribPixelLayers, index, this ),
        track_nGangedPixels( parent.track_nGangedPixels, index, this ),
        track_nGangedFlaggedFakes( parent.track_nGangedFlaggedFakes, index, this ),
        track_nPixelSpoiltHits( parent.track_nPixelSpoiltHits, index, this ),
        track_nSCTDoubleHoles( parent.track_nSCTDoubleHoles, index, this ),
        track_nSCTSpoiltHits( parent.track_nSCTSpoiltHits, index, this ),
        track_expectBLayerHit( parent.track_expectBLayerHit, index, this ),
        track_nHits( parent.track_nHits, index, this ),
        track_TRTHighTHitsRatio( parent.track_TRTHighTHitsRatio, index, this ),
        track_TRTHighTOutliersRatio( parent.track_TRTHighTOutliersRatio, index, this ),
        seedCalo_track_n( parent.seedCalo_track_n, index, this ),
        seedCalo_wideTrk_n( parent.seedCalo_wideTrk_n, index, this ),
        seedCalo_wideTrk_nBLHits( parent.seedCalo_wideTrk_nBLHits, index, this ),
        seedCalo_wideTrk_nPixHits( parent.seedCalo_wideTrk_nPixHits, index, this ),
        seedCalo_wideTrk_nSCTHits( parent.seedCalo_wideTrk_nSCTHits, index, this ),
        seedCalo_wideTrk_nTRTHits( parent.seedCalo_wideTrk_nTRTHits, index, this ),
        seedCalo_wideTrk_nTRTHighTHits( parent.seedCalo_wideTrk_nTRTHighTHits, index, this ),
        seedCalo_wideTrk_nTRTXenonHits( parent.seedCalo_wideTrk_nTRTXenonHits, index, this ),
        seedCalo_wideTrk_nPixHoles( parent.seedCalo_wideTrk_nPixHoles, index, this ),
        seedCalo_wideTrk_nSCTHoles( parent.seedCalo_wideTrk_nSCTHoles, index, this ),
        seedCalo_wideTrk_nTRTHoles( parent.seedCalo_wideTrk_nTRTHoles, index, this ),
        seedCalo_wideTrk_nPixelDeadSensors( parent.seedCalo_wideTrk_nPixelDeadSensors, index, this ),
        seedCalo_wideTrk_nSCTDeadSensors( parent.seedCalo_wideTrk_nSCTDeadSensors, index, this ),
        seedCalo_wideTrk_nBLSharedHits( parent.seedCalo_wideTrk_nBLSharedHits, index, this ),
        seedCalo_wideTrk_nPixSharedHits( parent.seedCalo_wideTrk_nPixSharedHits, index, this ),
        seedCalo_wideTrk_nSCTSharedHits( parent.seedCalo_wideTrk_nSCTSharedHits, index, this ),
        seedCalo_wideTrk_nBLayerSplitHits( parent.seedCalo_wideTrk_nBLayerSplitHits, index, this ),
        seedCalo_wideTrk_nPixSplitHits( parent.seedCalo_wideTrk_nPixSplitHits, index, this ),
        seedCalo_wideTrk_nBLayerOutliers( parent.seedCalo_wideTrk_nBLayerOutliers, index, this ),
        seedCalo_wideTrk_nPixelOutliers( parent.seedCalo_wideTrk_nPixelOutliers, index, this ),
        seedCalo_wideTrk_nSCTOutliers( parent.seedCalo_wideTrk_nSCTOutliers, index, this ),
        seedCalo_wideTrk_nTRTOutliers( parent.seedCalo_wideTrk_nTRTOutliers, index, this ),
        seedCalo_wideTrk_nTRTHighTOutliers( parent.seedCalo_wideTrk_nTRTHighTOutliers, index, this ),
        seedCalo_wideTrk_nContribPixelLayers( parent.seedCalo_wideTrk_nContribPixelLayers, index, this ),
        seedCalo_wideTrk_nGangedPixels( parent.seedCalo_wideTrk_nGangedPixels, index, this ),
        seedCalo_wideTrk_nGangedFlaggedFakes( parent.seedCalo_wideTrk_nGangedFlaggedFakes, index, this ),
        seedCalo_wideTrk_nPixelSpoiltHits( parent.seedCalo_wideTrk_nPixelSpoiltHits, index, this ),
        seedCalo_wideTrk_nSCTDoubleHoles( parent.seedCalo_wideTrk_nSCTDoubleHoles, index, this ),
        seedCalo_wideTrk_nSCTSpoiltHits( parent.seedCalo_wideTrk_nSCTSpoiltHits, index, this ),
        seedCalo_wideTrk_expectBLayerHit( parent.seedCalo_wideTrk_expectBLayerHit, index, this ),
        seedCalo_wideTrk_nHits( parent.seedCalo_wideTrk_nHits, index, this ),
        otherTrk_n( parent.otherTrk_n, index, this ),
        EF_dr( parent.EF_dr, index, this ),
        EF_E( parent.EF_E, index, this ),
        EF_Et( parent.EF_Et, index, this ),
        EF_pt( parent.EF_pt, index, this ),
        EF_eta( parent.EF_eta, index, this ),
        EF_phi( parent.EF_phi, index, this ),
        EF_matched( parent.EF_matched, index, this ),
        L2_dr( parent.L2_dr, index, this ),
        L2_E( parent.L2_E, index, this ),
        L2_Et( parent.L2_Et, index, this ),
        L2_pt( parent.L2_pt, index, this ),
        L2_eta( parent.L2_eta, index, this ),
        L2_phi( parent.L2_phi, index, this ),
        L2_matched( parent.L2_matched, index, this ),
        L1_dr( parent.L1_dr, index, this ),
        L1_Et( parent.L1_Et, index, this ),
        L1_pt( parent.L1_pt, index, this ),
        L1_eta( parent.L1_eta, index, this ),
        L1_phi( parent.L1_phi, index, this ),
        L1_matched( parent.L1_matched, index, this ),
// MC only
        trueTauAssocSmall_dr( parent.trueTauAssocSmall_dr, index, this ),
        trueTauAssocSmall_index( parent.trueTauAssocSmall_index, index, this ),
        trueTauAssocSmall_matched( parent.trueTauAssocSmall_matched, index, this ),
// end MC only
        MET_Egamma10LooseTau_wpx( parent.MET_Egamma10LooseTau_wpx, index, this ),
        MET_Egamma10LooseTau_wpy( parent.MET_Egamma10LooseTau_wpy, index, this ),
        MET_Egamma10LooseTau_wet( parent.MET_Egamma10LooseTau_wet, index, this ),
        MET_Egamma10LooseTau_statusWord( parent.MET_Egamma10LooseTau_statusWord, index, this ),
        MET_wpx( parent.MET_wpx, index, this ),
        MET_wpy( parent.MET_wpy, index, this ),
        MET_wet( parent.MET_wet, index, this ),
        MET_statusWord( parent.MET_statusWord, index, this ) , 
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
   TauD3PDObjectElement::TauD3PDObjectElement( const TauD3PDObjectElement& parent , bool is_data )
      : TObject( parent ),
        Et( parent.Et ),
        pt( parent.pt ),
        m( parent.m ),
        eta( parent.eta ),
        phi( parent.phi ),
        charge( parent.charge ),
        BDTEleScore( parent.BDTEleScore ),
        BDTJetScore( parent.BDTJetScore ),
        likelihood( parent.likelihood ),
        SafeLikelihood( parent.SafeLikelihood ),
        electronVetoLoose( parent.electronVetoLoose ),
        electronVetoMedium( parent.electronVetoMedium ),
        electronVetoTight( parent.electronVetoTight ),
        muonVeto( parent.muonVeto ),
        tauLlhLoose( parent.tauLlhLoose ),
        tauLlhMedium( parent.tauLlhMedium ),
        tauLlhTight( parent.tauLlhTight ),
        JetBDTSigLoose( parent.JetBDTSigLoose ),
        JetBDTSigMedium( parent.JetBDTSigMedium ),
        JetBDTSigTight( parent.JetBDTSigTight ),
        EleBDTLoose( parent.EleBDTLoose ),
        EleBDTMedium( parent.EleBDTMedium ),
        EleBDTTight( parent.EleBDTTight ),
        author( parent.author ),
        RoIWord( parent.RoIWord ),
        nProng( parent.nProng ),
        numTrack( parent.numTrack ),
        seedCalo_numTrack( parent.seedCalo_numTrack ),
        seedCalo_nWideTrk( parent.seedCalo_nWideTrk ),
        nOtherTrk( parent.nOtherTrk ),
        etOverPtLeadTrk( parent.etOverPtLeadTrk ),
        ipZ0SinThetaSigLeadTrk( parent.ipZ0SinThetaSigLeadTrk ),
        leadTrkPt( parent.leadTrkPt ),
        nLooseTrk( parent.nLooseTrk ),
        nLooseConvTrk( parent.nLooseConvTrk ),
        nProngLoose( parent.nProngLoose ),
        ipSigLeadTrk( parent.ipSigLeadTrk ),
        ipSigLeadLooseTrk( parent.ipSigLeadLooseTrk ),
        etOverPtLeadLooseTrk( parent.etOverPtLeadLooseTrk ),
        leadLooseTrkPt( parent.leadLooseTrkPt ),
        chrgLooseTrk( parent.chrgLooseTrk ),
        massTrkSys( parent.massTrkSys ),
        trkWidth2( parent.trkWidth2 ),
        trFlightPathSig( parent.trFlightPathSig ),
        etEflow( parent.etEflow ),
        mEflow( parent.mEflow ),
        nPi0( parent.nPi0 ),
        ele_E237E277( parent.ele_E237E277 ),
        ele_PresamplerFraction( parent.ele_PresamplerFraction ),
        ele_ECALFirstFraction( parent.ele_ECALFirstFraction ),
        EM_TES_scale( parent.EM_TES_scale ),
        LC_TES_precalib( parent.LC_TES_precalib ),
        TRTHTOverLT_LeadTrk( parent.TRTHTOverLT_LeadTrk ),
        seedCalo_EMRadius( parent.seedCalo_EMRadius ),
        seedCalo_hadRadius( parent.seedCalo_hadRadius ),
        seedCalo_etEMAtEMScale( parent.seedCalo_etEMAtEMScale ),
        seedCalo_etHadAtEMScale( parent.seedCalo_etHadAtEMScale ),
        seedCalo_isolFrac( parent.seedCalo_isolFrac ),
        seedCalo_centFrac( parent.seedCalo_centFrac ),
        seedCalo_stripWidth2( parent.seedCalo_stripWidth2 ),
        seedCalo_nStrip( parent.seedCalo_nStrip ),
        seedCalo_eta( parent.seedCalo_eta ),
        seedCalo_phi( parent.seedCalo_phi ),
        seedCalo_nIsolLooseTrk( parent.seedCalo_nIsolLooseTrk ),
        seedCalo_trkAvgDist( parent.seedCalo_trkAvgDist ),
        seedCalo_trkRmsDist( parent.seedCalo_trkRmsDist ),
        seedCalo_caloIso( parent.seedCalo_caloIso ),
        seedCalo_caloIsoCorrected( parent.seedCalo_caloIsoCorrected ),
        seedCalo_dRmax( parent.seedCalo_dRmax ),
        seedCalo_lead2ClusterEOverAllClusterE( parent.seedCalo_lead2ClusterEOverAllClusterE ),
        seedCalo_lead3ClusterEOverAllClusterE( parent.seedCalo_lead3ClusterEOverAllClusterE ),
        seedCalo_etHadCalib( parent.seedCalo_etHadCalib ),
        seedCalo_etEMCalib( parent.seedCalo_etEMCalib ),
        numTopoClusters( parent.numTopoClusters ),
        numEffTopoClusters( parent.numEffTopoClusters ),
        topoInvMass( parent.topoInvMass ),
        effTopoInvMass( parent.effTopoInvMass ),
        topoMeanDeltaR( parent.topoMeanDeltaR ),
        effTopoMeanDeltaR( parent.effTopoMeanDeltaR ),
        numCells( parent.numCells ),
        seedTrk_EMRadius( parent.seedTrk_EMRadius ),
        seedTrk_isolFrac( parent.seedTrk_isolFrac ),
        seedTrk_etChrgHadOverSumTrkPt( parent.seedTrk_etChrgHadOverSumTrkPt ),
        seedTrk_isolFracWide( parent.seedTrk_isolFracWide ),
        seedTrk_etHadAtEMScale( parent.seedTrk_etHadAtEMScale ),
        seedTrk_etEMAtEMScale( parent.seedTrk_etEMAtEMScale ),
        seedTrk_etEMCL( parent.seedTrk_etEMCL ),
        seedTrk_etChrgEM( parent.seedTrk_etChrgEM ),
        seedTrk_etNeuEM( parent.seedTrk_etNeuEM ),
        seedTrk_etResNeuEM( parent.seedTrk_etResNeuEM ),
        seedTrk_hadLeakEt( parent.seedTrk_hadLeakEt ),
        seedTrk_sumEMCellEtOverLeadTrkPt( parent.seedTrk_sumEMCellEtOverLeadTrkPt ),
        seedTrk_secMaxStripEt( parent.seedTrk_secMaxStripEt ),
        seedTrk_stripWidth2( parent.seedTrk_stripWidth2 ),
        seedTrk_nStrip( parent.seedTrk_nStrip ),
        seedTrk_etChrgHad( parent.seedTrk_etChrgHad ),
        seedTrk_nOtherCoreTrk( parent.seedTrk_nOtherCoreTrk ),
        seedTrk_nIsolTrk( parent.seedTrk_nIsolTrk ),
        seedTrk_etIsolEM( parent.seedTrk_etIsolEM ),
        seedTrk_etIsolHad( parent.seedTrk_etIsolHad ),
        cellBasedEnergyRing1( parent.cellBasedEnergyRing1 ),
        cellBasedEnergyRing2( parent.cellBasedEnergyRing2 ),
        cellBasedEnergyRing3( parent.cellBasedEnergyRing3 ),
        cellBasedEnergyRing4( parent.cellBasedEnergyRing4 ),
        cellBasedEnergyRing5( parent.cellBasedEnergyRing5 ),
        cellBasedEnergyRing6( parent.cellBasedEnergyRing6 ),
        cellBasedEnergyRing7( parent.cellBasedEnergyRing7 ),
        calcVars_etHad_EMScale_Pt3Trks( parent.calcVars_etHad_EMScale_Pt3Trks ),
        calcVars_etEM_EMScale_Pt3Trks( parent.calcVars_etEM_EMScale_Pt3Trks ),
        calcVars_ipSigLeadLooseTrk( parent.calcVars_ipSigLeadLooseTrk ),
        calcVars_drMin( parent.calcVars_drMin ),
        calcVars_calRadius( parent.calcVars_calRadius ),
        calcVars_EMFractionAtEMScale( parent.calcVars_EMFractionAtEMScale ),
        calcVars_trackIso( parent.calcVars_trackIso ),
        calcVars_ChPiEMEOverCaloEME( parent.calcVars_ChPiEMEOverCaloEME ),
        calcVars_PSSFraction( parent.calcVars_PSSFraction ),
        calcVars_EMPOverTrkSysP( parent.calcVars_EMPOverTrkSysP ),
        calcVars_pi0BDTPrimaryScore( parent.calcVars_pi0BDTPrimaryScore ),
        calcVars_pi0BDTSecondaryScore( parent.calcVars_pi0BDTSecondaryScore ),
        calcVars_corrCentFrac( parent.calcVars_corrCentFrac ),
        calcVars_corrFTrk( parent.calcVars_corrFTrk ),
        calcVars_interAxis_eta( parent.calcVars_interAxis_eta ),
        calcVars_interAxis_phi( parent.calcVars_interAxis_phi ),
        pi0_cl1_pt( parent.pi0_cl1_pt ),
        pi0_cl1_eta( parent.pi0_cl1_eta ),
        pi0_cl1_phi( parent.pi0_cl1_phi ),
        pi0_cl2_pt( parent.pi0_cl2_pt ),
        pi0_cl2_eta( parent.pi0_cl2_eta ),
        pi0_cl2_phi( parent.pi0_cl2_phi ),
        pi0_vistau_pt( parent.pi0_vistau_pt ),
        pi0_vistau_eta( parent.pi0_vistau_eta ),
        pi0_vistau_phi( parent.pi0_vistau_phi ),
        pi0_vistau_m( parent.pi0_vistau_m ),
        pi0_n( parent.pi0_n ),
        pantau_isPanTauCandidate( parent.pantau_isPanTauCandidate ),
        pantau_PanTauScore( parent.pantau_PanTauScore ),
        pantau_NChargedEFO( parent.pantau_NChargedEFO ),
        pantau_NChargedQualifiedEFO( parent.pantau_NChargedQualifiedEFO ),
        pantau_NNeutralEFO( parent.pantau_NNeutralEFO ),
        pantau_AbsSumCharge( parent.pantau_AbsSumCharge ),
        pantau_EflowJetMomentDRAll( parent.pantau_EflowJetMomentDRAll ),
        pantau_EflowJetMomentDRChrg( parent.pantau_EflowJetMomentDRChrg ),
        pantau_EflowJetMomentDREMNeut( parent.pantau_EflowJetMomentDREMNeut ),
        pantau_EflowJetMomentDRHADNeut( parent.pantau_EflowJetMomentDRHADNeut ),
        pantau_EtIn01OverEtIn02InvSigm( parent.pantau_EtIn01OverEtIn02InvSigm ),
        pantau_EtIn02To04OverTotalEtInvSigm( parent.pantau_EtIn02To04OverTotalEtInvSigm ),
        pantau_EtIn01OverEtIn04InvSigm( parent.pantau_EtIn01OverEtIn04InvSigm ),
        pantau_EtIn01OverEtIn04( parent.pantau_EtIn01OverEtIn04 ),
        pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents( parent.pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents ),
        pantau_JetSphericity( parent.pantau_JetSphericity ),
        pantau_TransImpactParamSignfTrack1( parent.pantau_TransImpactParamSignfTrack1 ),
        pantau_EflowAngleJetAxisLeadingChargedQualified( parent.pantau_EflowAngleJetAxisLeadingChargedQualified ),
        pantau_EflowAngleChargedAxisNeutralAxis( parent.pantau_EflowAngleChargedAxisNeutralAxis ),
        pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified( parent.pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified ),
        pantau_EflowInvariantMassAll( parent.pantau_EflowInvariantMassAll ),
        pantau_EflowStdDevEtToSumEt( parent.pantau_EflowStdDevEtToSumEt ),
        pantau_EflowEtLeadingChrgQualifiedOverTotalEt( parent.pantau_EflowEtLeadingChrgQualifiedOverTotalEt ),
        pantau_EflowSumEAll( parent.pantau_EflowSumEAll ),
        pantau_EflowChargedSumEt( parent.pantau_EflowChargedSumEt ),
        leadTrack_eta( parent.leadTrack_eta ),
        leadTrack_phi( parent.leadTrack_phi ),
        cluster_E( parent.cluster_E ),
        cluster_eta( parent.cluster_eta ),
        cluster_phi( parent.cluster_phi ),
        cluster_eta_atTJVA( parent.cluster_eta_atTJVA ),
        cluster_phi_atTJVA( parent.cluster_phi_atTJVA ),
        cluster_PreSamplerStripF( parent.cluster_PreSamplerStripF ),
        cluster_EMLayer2F( parent.cluster_EMLayer2F ),
        cluster_EMLayer3F( parent.cluster_EMLayer3F ),
        cluster_n( parent.cluster_n ),
        Pi0Cluster_pt( parent.Pi0Cluster_pt ),
        Pi0Cluster_eta( parent.Pi0Cluster_eta ),
        Pi0Cluster_phi( parent.Pi0Cluster_phi ),
        secvtx_x( parent.secvtx_x ),
        secvtx_y( parent.secvtx_y ),
        secvtx_z( parent.secvtx_z ),
        secvtx_xx( parent.secvtx_xx ),
        secvtx_yy( parent.secvtx_yy ),
        secvtx_zz( parent.secvtx_zz ),
        secvtx_xy( parent.secvtx_xy ),
        secvtx_yz( parent.secvtx_yz ),
        secvtx_zx( parent.secvtx_zx ),
        secvtx_chiSquared( parent.secvtx_chiSquared ),
        secvtx_numberDoF( parent.secvtx_numberDoF ),
        privtx_x( parent.privtx_x ),
        privtx_y( parent.privtx_y ),
        privtx_z( parent.privtx_z ),
        privtx_xx( parent.privtx_xx ),
        privtx_yy( parent.privtx_yy ),
        privtx_zz( parent.privtx_zz ),
        privtx_xy( parent.privtx_xy ),
        privtx_yz( parent.privtx_yz ),
        privtx_zx( parent.privtx_zx ),
        privtx_chiSquared( parent.privtx_chiSquared ),
        privtx_numberDoF( parent.privtx_numberDoF ),
        privtx_jvf( parent.privtx_jvf ),
        jet_Et( parent.jet_Et ),
        jet_pt( parent.jet_pt ),
        jet_m( parent.jet_m ),
        jet_eta( parent.jet_eta ),
        jet_phi( parent.jet_phi ),
        jet_WIDTH( parent.jet_WIDTH ),
        jet_n90( parent.jet_n90 ),
        jet_n90constituents( parent.jet_n90constituents ),
        jet_BCH_CORR_CELL( parent.jet_BCH_CORR_CELL ),
        jet_BCH_CORR_JET( parent.jet_BCH_CORR_JET ),
        jet_BCH_CORR_JET_FORCELL( parent.jet_BCH_CORR_JET_FORCELL ),
        jet_ENG_BAD_CELLS( parent.jet_ENG_BAD_CELLS ),
        jet_N_BAD_CELLS( parent.jet_N_BAD_CELLS ),
        jet_N_BAD_CELLS_CORR( parent.jet_N_BAD_CELLS_CORR ),
        jet_BAD_CELLS_CORR_E( parent.jet_BAD_CELLS_CORR_E ),
        jet_Timing( parent.jet_Timing ),
        jet_LArQuality( parent.jet_LArQuality ),
        jet_nTrk( parent.jet_nTrk ),
        jet_sumPtTrk( parent.jet_sumPtTrk ),
        jet_OriginIndex( parent.jet_OriginIndex ),
        jet_HECQuality( parent.jet_HECQuality ),
        jet_NegativeE( parent.jet_NegativeE ),
        jet_YFlip12( parent.jet_YFlip12 ),
        jet_YFlip23( parent.jet_YFlip23 ),
        jet_BCH_CORR_DOTX( parent.jet_BCH_CORR_DOTX ),
        jet_SamplingMax( parent.jet_SamplingMax ),
        jet_fracSamplingMax( parent.jet_fracSamplingMax ),
        jet_hecf( parent.jet_hecf ),
        jet_tgap3f( parent.jet_tgap3f ),
        jet_isUgly( parent.jet_isUgly ),
        jet_isBadLooseMinus( parent.jet_isBadLooseMinus ),
        jet_isBadLoose( parent.jet_isBadLoose ),
        jet_isBadMedium( parent.jet_isBadMedium ),
        jet_isBadTight( parent.jet_isBadTight ),
        jet_emfrac( parent.jet_emfrac ),
        jet_GCWJES( parent.jet_GCWJES ),
        jet_EMJES( parent.jet_EMJES ),
        jet_emscale_E( parent.jet_emscale_E ),
        jet_emscale_pt( parent.jet_emscale_pt ),
        jet_emscale_m( parent.jet_emscale_m ),
        jet_emscale_eta( parent.jet_emscale_eta ),
        jet_emscale_phi( parent.jet_emscale_phi ),
        jet_jvtx_x( parent.jet_jvtx_x ),
        jet_jvtx_y( parent.jet_jvtx_y ),
        jet_jvtx_z( parent.jet_jvtx_z ),
        jet_jvtxf( parent.jet_jvtxf ),
        jet_flavor_weight( parent.jet_flavor_weight ),
        jet_flavor_weight_TrackCounting2D( parent.jet_flavor_weight_TrackCounting2D ),
        jet_flavor_weight_JetProb( parent.jet_flavor_weight_JetProb ),
        jet_flavor_weight_IP1D( parent.jet_flavor_weight_IP1D ),
        jet_flavor_weight_IP2D( parent.jet_flavor_weight_IP2D ),
        jet_flavor_weight_IP3D( parent.jet_flavor_weight_IP3D ),
        jet_flavor_weight_SV0( parent.jet_flavor_weight_SV0 ),
        jet_flavor_weight_SV1( parent.jet_flavor_weight_SV1 ),
        jet_flavor_weight_SV2( parent.jet_flavor_weight_SV2 ),
        jet_flavor_weight_JetFitterTag( parent.jet_flavor_weight_JetFitterTag ),
        jet_flavor_weight_JetFitterCOMB( parent.jet_flavor_weight_JetFitterCOMB ),
        jet_flavor_weight_JetFitterTagNN( parent.jet_flavor_weight_JetFitterTagNN ),
        jet_flavor_weight_JetFitterCOMBNN( parent.jet_flavor_weight_JetFitterCOMBNN ),
        jet_flavor_weight_SoftMuonTag( parent.jet_flavor_weight_SoftMuonTag ),
        jet_flavor_weight_SoftElectronTag( parent.jet_flavor_weight_SoftElectronTag ),
        jet_flavor_weight_IP3DSV1( parent.jet_flavor_weight_IP3DSV1 ),
        jet_e_PreSamplerB( parent.jet_e_PreSamplerB ),
        jet_e_EMB1( parent.jet_e_EMB1 ),
        jet_e_EMB2( parent.jet_e_EMB2 ),
        jet_e_EMB3( parent.jet_e_EMB3 ),
        jet_e_PreSamplerE( parent.jet_e_PreSamplerE ),
        jet_e_EME1( parent.jet_e_EME1 ),
        jet_e_EME2( parent.jet_e_EME2 ),
        jet_e_EME3( parent.jet_e_EME3 ),
        jet_e_HEC0( parent.jet_e_HEC0 ),
        jet_e_HEC1( parent.jet_e_HEC1 ),
        jet_e_HEC2( parent.jet_e_HEC2 ),
        jet_e_HEC3( parent.jet_e_HEC3 ),
        jet_e_TileBar0( parent.jet_e_TileBar0 ),
        jet_e_TileBar1( parent.jet_e_TileBar1 ),
        jet_e_TileBar2( parent.jet_e_TileBar2 ),
        jet_e_TileGap1( parent.jet_e_TileGap1 ),
        jet_e_TileGap2( parent.jet_e_TileGap2 ),
        jet_e_TileGap3( parent.jet_e_TileGap3 ),
        jet_e_TileExt0( parent.jet_e_TileExt0 ),
        jet_e_TileExt1( parent.jet_e_TileExt1 ),
        jet_e_TileExt2( parent.jet_e_TileExt2 ),
        jet_e_FCAL0( parent.jet_e_FCAL0 ),
        jet_e_FCAL1( parent.jet_e_FCAL1 ),
        jet_e_FCAL2( parent.jet_e_FCAL2 ),
        jet_shapeBins( parent.jet_shapeBins ),
        track_atTJVA_n( parent.track_atTJVA_n ),
        track_atTJVA_d0( parent.track_atTJVA_d0 ),
        track_atTJVA_z0( parent.track_atTJVA_z0 ),
        track_atTJVA_phi( parent.track_atTJVA_phi ),
        track_atTJVA_theta( parent.track_atTJVA_theta ),
        track_atTJVA_qoverp( parent.track_atTJVA_qoverp ),
        track_atTJVA_pt( parent.track_atTJVA_pt ),
        track_atTJVA_eta( parent.track_atTJVA_eta ),
        seedCalo_wideTrk_atTJVA_n( parent.seedCalo_wideTrk_atTJVA_n ),
        seedCalo_wideTrk_atTJVA_d0( parent.seedCalo_wideTrk_atTJVA_d0 ),
        seedCalo_wideTrk_atTJVA_z0( parent.seedCalo_wideTrk_atTJVA_z0 ),
        seedCalo_wideTrk_atTJVA_phi( parent.seedCalo_wideTrk_atTJVA_phi ),
        seedCalo_wideTrk_atTJVA_theta( parent.seedCalo_wideTrk_atTJVA_theta ),
        seedCalo_wideTrk_atTJVA_qoverp( parent.seedCalo_wideTrk_atTJVA_qoverp ),
        seedCalo_wideTrk_atTJVA_pt( parent.seedCalo_wideTrk_atTJVA_pt ),
        seedCalo_wideTrk_atTJVA_eta( parent.seedCalo_wideTrk_atTJVA_eta ),
        otherTrk_atTJVA_n( parent.otherTrk_atTJVA_n ),
        track_n( parent.track_n ),
        track_d0( parent.track_d0 ),
        track_z0( parent.track_z0 ),
        track_phi( parent.track_phi ),
        track_theta( parent.track_theta ),
        track_qoverp( parent.track_qoverp ),
        track_pt( parent.track_pt ),
        track_eta( parent.track_eta ),
        track_atPV_d0( parent.track_atPV_d0 ),
        track_atPV_z0( parent.track_atPV_z0 ),
        track_atPV_phi( parent.track_atPV_phi ),
        track_atPV_theta( parent.track_atPV_theta ),
        track_atPV_qoverp( parent.track_atPV_qoverp ),
        track_atPV_pt( parent.track_atPV_pt ),
        track_atPV_eta( parent.track_atPV_eta ),
        track_nBLHits( parent.track_nBLHits ),
        track_nPixHits( parent.track_nPixHits ),
        track_nSCTHits( parent.track_nSCTHits ),
        track_nTRTHits( parent.track_nTRTHits ),
        track_nTRTHighTHits( parent.track_nTRTHighTHits ),
        track_nTRTXenonHits( parent.track_nTRTXenonHits ),
        track_nPixHoles( parent.track_nPixHoles ),
        track_nSCTHoles( parent.track_nSCTHoles ),
        track_nTRTHoles( parent.track_nTRTHoles ),
        track_nPixelDeadSensors( parent.track_nPixelDeadSensors ),
        track_nSCTDeadSensors( parent.track_nSCTDeadSensors ),
        track_nBLSharedHits( parent.track_nBLSharedHits ),
        track_nPixSharedHits( parent.track_nPixSharedHits ),
        track_nSCTSharedHits( parent.track_nSCTSharedHits ),
        track_nBLayerSplitHits( parent.track_nBLayerSplitHits ),
        track_nPixSplitHits( parent.track_nPixSplitHits ),
        track_nBLayerOutliers( parent.track_nBLayerOutliers ),
        track_nPixelOutliers( parent.track_nPixelOutliers ),
        track_nSCTOutliers( parent.track_nSCTOutliers ),
        track_nTRTOutliers( parent.track_nTRTOutliers ),
        track_nTRTHighTOutliers( parent.track_nTRTHighTOutliers ),
        track_nContribPixelLayers( parent.track_nContribPixelLayers ),
        track_nGangedPixels( parent.track_nGangedPixels ),
        track_nGangedFlaggedFakes( parent.track_nGangedFlaggedFakes ),
        track_nPixelSpoiltHits( parent.track_nPixelSpoiltHits ),
        track_nSCTDoubleHoles( parent.track_nSCTDoubleHoles ),
        track_nSCTSpoiltHits( parent.track_nSCTSpoiltHits ),
        track_expectBLayerHit( parent.track_expectBLayerHit ),
        track_nHits( parent.track_nHits ),
        track_TRTHighTHitsRatio( parent.track_TRTHighTHitsRatio ),
        track_TRTHighTOutliersRatio( parent.track_TRTHighTOutliersRatio ),
        seedCalo_track_n( parent.seedCalo_track_n ),
        seedCalo_wideTrk_n( parent.seedCalo_wideTrk_n ),
        seedCalo_wideTrk_nBLHits( parent.seedCalo_wideTrk_nBLHits ),
        seedCalo_wideTrk_nPixHits( parent.seedCalo_wideTrk_nPixHits ),
        seedCalo_wideTrk_nSCTHits( parent.seedCalo_wideTrk_nSCTHits ),
        seedCalo_wideTrk_nTRTHits( parent.seedCalo_wideTrk_nTRTHits ),
        seedCalo_wideTrk_nTRTHighTHits( parent.seedCalo_wideTrk_nTRTHighTHits ),
        seedCalo_wideTrk_nTRTXenonHits( parent.seedCalo_wideTrk_nTRTXenonHits ),
        seedCalo_wideTrk_nPixHoles( parent.seedCalo_wideTrk_nPixHoles ),
        seedCalo_wideTrk_nSCTHoles( parent.seedCalo_wideTrk_nSCTHoles ),
        seedCalo_wideTrk_nTRTHoles( parent.seedCalo_wideTrk_nTRTHoles ),
        seedCalo_wideTrk_nPixelDeadSensors( parent.seedCalo_wideTrk_nPixelDeadSensors ),
        seedCalo_wideTrk_nSCTDeadSensors( parent.seedCalo_wideTrk_nSCTDeadSensors ),
        seedCalo_wideTrk_nBLSharedHits( parent.seedCalo_wideTrk_nBLSharedHits ),
        seedCalo_wideTrk_nPixSharedHits( parent.seedCalo_wideTrk_nPixSharedHits ),
        seedCalo_wideTrk_nSCTSharedHits( parent.seedCalo_wideTrk_nSCTSharedHits ),
        seedCalo_wideTrk_nBLayerSplitHits( parent.seedCalo_wideTrk_nBLayerSplitHits ),
        seedCalo_wideTrk_nPixSplitHits( parent.seedCalo_wideTrk_nPixSplitHits ),
        seedCalo_wideTrk_nBLayerOutliers( parent.seedCalo_wideTrk_nBLayerOutliers ),
        seedCalo_wideTrk_nPixelOutliers( parent.seedCalo_wideTrk_nPixelOutliers ),
        seedCalo_wideTrk_nSCTOutliers( parent.seedCalo_wideTrk_nSCTOutliers ),
        seedCalo_wideTrk_nTRTOutliers( parent.seedCalo_wideTrk_nTRTOutliers ),
        seedCalo_wideTrk_nTRTHighTOutliers( parent.seedCalo_wideTrk_nTRTHighTOutliers ),
        seedCalo_wideTrk_nContribPixelLayers( parent.seedCalo_wideTrk_nContribPixelLayers ),
        seedCalo_wideTrk_nGangedPixels( parent.seedCalo_wideTrk_nGangedPixels ),
        seedCalo_wideTrk_nGangedFlaggedFakes( parent.seedCalo_wideTrk_nGangedFlaggedFakes ),
        seedCalo_wideTrk_nPixelSpoiltHits( parent.seedCalo_wideTrk_nPixelSpoiltHits ),
        seedCalo_wideTrk_nSCTDoubleHoles( parent.seedCalo_wideTrk_nSCTDoubleHoles ),
        seedCalo_wideTrk_nSCTSpoiltHits( parent.seedCalo_wideTrk_nSCTSpoiltHits ),
        seedCalo_wideTrk_expectBLayerHit( parent.seedCalo_wideTrk_expectBLayerHit ),
        seedCalo_wideTrk_nHits( parent.seedCalo_wideTrk_nHits ),
        otherTrk_n( parent.otherTrk_n ),
        EF_dr( parent.EF_dr ),
        EF_E( parent.EF_E ),
        EF_Et( parent.EF_Et ),
        EF_pt( parent.EF_pt ),
        EF_eta( parent.EF_eta ),
        EF_phi( parent.EF_phi ),
        EF_matched( parent.EF_matched ),
        L2_dr( parent.L2_dr ),
        L2_E( parent.L2_E ),
        L2_Et( parent.L2_Et ),
        L2_pt( parent.L2_pt ),
        L2_eta( parent.L2_eta ),
        L2_phi( parent.L2_phi ),
        L2_matched( parent.L2_matched ),
        L1_dr( parent.L1_dr ),
        L1_Et( parent.L1_Et ),
        L1_pt( parent.L1_pt ),
        L1_eta( parent.L1_eta ),
        L1_phi( parent.L1_phi ),
        L1_matched( parent.L1_matched ),
// MC only
        trueTauAssocSmall_dr( parent.trueTauAssocSmall_dr ),
        trueTauAssocSmall_index( parent.trueTauAssocSmall_index ),
        trueTauAssocSmall_matched( parent.trueTauAssocSmall_matched ),
// end MC only
        MET_Egamma10LooseTau_wpx( parent.MET_Egamma10LooseTau_wpx ),
        MET_Egamma10LooseTau_wpy( parent.MET_Egamma10LooseTau_wpy ),
        MET_Egamma10LooseTau_wet( parent.MET_Egamma10LooseTau_wet ),
        MET_Egamma10LooseTau_statusWord( parent.MET_Egamma10LooseTau_statusWord ),
        MET_wpx( parent.MET_wpx ),
        MET_wpy( parent.MET_wpy ),
        MET_wet( parent.MET_wet ),
        MET_statusWord( parent.MET_statusWord ) , 
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
   TauD3PDObject::TauD3PDObject( const ::Long64_t& master, const char* prefix , bool is_data )
      : TObject(),
        n( this, ::TString( prefix ) + "n", &master ),
        Et( this, ::TString( prefix ) + "Et", &master ),
        pt( this, ::TString( prefix ) + "pt", &master ),
        m( this, ::TString( prefix ) + "m", &master ),
        eta( this, ::TString( prefix ) + "eta", &master ),
        phi( this, ::TString( prefix ) + "phi", &master ),
        charge( this, ::TString( prefix ) + "charge", &master ),
        BDTEleScore( this, ::TString( prefix ) + "BDTEleScore", &master ),
        BDTJetScore( this, ::TString( prefix ) + "BDTJetScore", &master ),
        likelihood( this, ::TString( prefix ) + "likelihood", &master ),
        SafeLikelihood( this, ::TString( prefix ) + "SafeLikelihood", &master ),
        electronVetoLoose( this, ::TString( prefix ) + "electronVetoLoose", &master ),
        electronVetoMedium( this, ::TString( prefix ) + "electronVetoMedium", &master ),
        electronVetoTight( this, ::TString( prefix ) + "electronVetoTight", &master ),
        muonVeto( this, ::TString( prefix ) + "muonVeto", &master ),
        tauLlhLoose( this, ::TString( prefix ) + "tauLlhLoose", &master ),
        tauLlhMedium( this, ::TString( prefix ) + "tauLlhMedium", &master ),
        tauLlhTight( this, ::TString( prefix ) + "tauLlhTight", &master ),
        JetBDTSigLoose( this, ::TString( prefix ) + "JetBDTSigLoose", &master ),
        JetBDTSigMedium( this, ::TString( prefix ) + "JetBDTSigMedium", &master ),
        JetBDTSigTight( this, ::TString( prefix ) + "JetBDTSigTight", &master ),
        EleBDTLoose( this, ::TString( prefix ) + "EleBDTLoose", &master ),
        EleBDTMedium( this, ::TString( prefix ) + "EleBDTMedium", &master ),
        EleBDTTight( this, ::TString( prefix ) + "EleBDTTight", &master ),
        author( this, ::TString( prefix ) + "author", &master ),
        RoIWord( this, ::TString( prefix ) + "RoIWord", &master ),
        nProng( this, ::TString( prefix ) + "nProng", &master ),
        numTrack( this, ::TString( prefix ) + "numTrack", &master ),
        seedCalo_numTrack( this, ::TString( prefix ) + "seedCalo_numTrack", &master ),
        seedCalo_nWideTrk( this, ::TString( prefix ) + "seedCalo_nWideTrk", &master ),
        nOtherTrk( this, ::TString( prefix ) + "nOtherTrk", &master ),
        etOverPtLeadTrk( this, ::TString( prefix ) + "etOverPtLeadTrk", &master ),
        ipZ0SinThetaSigLeadTrk( this, ::TString( prefix ) + "ipZ0SinThetaSigLeadTrk", &master ),
        leadTrkPt( this, ::TString( prefix ) + "leadTrkPt", &master ),
        nLooseTrk( this, ::TString( prefix ) + "nLooseTrk", &master ),
        nLooseConvTrk( this, ::TString( prefix ) + "nLooseConvTrk", &master ),
        nProngLoose( this, ::TString( prefix ) + "nProngLoose", &master ),
        ipSigLeadTrk( this, ::TString( prefix ) + "ipSigLeadTrk", &master ),
        ipSigLeadLooseTrk( this, ::TString( prefix ) + "ipSigLeadLooseTrk", &master ),
        etOverPtLeadLooseTrk( this, ::TString( prefix ) + "etOverPtLeadLooseTrk", &master ),
        leadLooseTrkPt( this, ::TString( prefix ) + "leadLooseTrkPt", &master ),
        chrgLooseTrk( this, ::TString( prefix ) + "chrgLooseTrk", &master ),
        massTrkSys( this, ::TString( prefix ) + "massTrkSys", &master ),
        trkWidth2( this, ::TString( prefix ) + "trkWidth2", &master ),
        trFlightPathSig( this, ::TString( prefix ) + "trFlightPathSig", &master ),
        etEflow( this, ::TString( prefix ) + "etEflow", &master ),
        mEflow( this, ::TString( prefix ) + "mEflow", &master ),
        nPi0( this, ::TString( prefix ) + "nPi0", &master ),
        ele_E237E277( this, ::TString( prefix ) + "ele_E237E277", &master ),
        ele_PresamplerFraction( this, ::TString( prefix ) + "ele_PresamplerFraction", &master ),
        ele_ECALFirstFraction( this, ::TString( prefix ) + "ele_ECALFirstFraction", &master ),
        EM_TES_scale( this, ::TString( prefix ) + "EM_TES_scale", &master ),
        LC_TES_precalib( this, ::TString( prefix ) + "LC_TES_precalib", &master ),
        TRTHTOverLT_LeadTrk( this, ::TString( prefix ) + "TRTHTOverLT_LeadTrk", &master ),
        seedCalo_EMRadius( this, ::TString( prefix ) + "seedCalo_EMRadius", &master ),
        seedCalo_hadRadius( this, ::TString( prefix ) + "seedCalo_hadRadius", &master ),
        seedCalo_etEMAtEMScale( this, ::TString( prefix ) + "seedCalo_etEMAtEMScale", &master ),
        seedCalo_etHadAtEMScale( this, ::TString( prefix ) + "seedCalo_etHadAtEMScale", &master ),
        seedCalo_isolFrac( this, ::TString( prefix ) + "seedCalo_isolFrac", &master ),
        seedCalo_centFrac( this, ::TString( prefix ) + "seedCalo_centFrac", &master ),
        seedCalo_stripWidth2( this, ::TString( prefix ) + "seedCalo_stripWidth2", &master ),
        seedCalo_nStrip( this, ::TString( prefix ) + "seedCalo_nStrip", &master ),
        seedCalo_eta( this, ::TString( prefix ) + "seedCalo_eta", &master ),
        seedCalo_phi( this, ::TString( prefix ) + "seedCalo_phi", &master ),
        seedCalo_nIsolLooseTrk( this, ::TString( prefix ) + "seedCalo_nIsolLooseTrk", &master ),
        seedCalo_trkAvgDist( this, ::TString( prefix ) + "seedCalo_trkAvgDist", &master ),
        seedCalo_trkRmsDist( this, ::TString( prefix ) + "seedCalo_trkRmsDist", &master ),
        seedCalo_caloIso( this, ::TString( prefix ) + "seedCalo_caloIso", &master ),
        seedCalo_caloIsoCorrected( this, ::TString( prefix ) + "seedCalo_caloIsoCorrected", &master ),
        seedCalo_dRmax( this, ::TString( prefix ) + "seedCalo_dRmax", &master ),
        seedCalo_lead2ClusterEOverAllClusterE( this, ::TString( prefix ) + "seedCalo_lead2ClusterEOverAllClusterE", &master ),
        seedCalo_lead3ClusterEOverAllClusterE( this, ::TString( prefix ) + "seedCalo_lead3ClusterEOverAllClusterE", &master ),
        seedCalo_etHadCalib( this, ::TString( prefix ) + "seedCalo_etHadCalib", &master ),
        seedCalo_etEMCalib( this, ::TString( prefix ) + "seedCalo_etEMCalib", &master ),
        numTopoClusters( this, ::TString( prefix ) + "numTopoClusters", &master ),
        numEffTopoClusters( this, ::TString( prefix ) + "numEffTopoClusters", &master ),
        topoInvMass( this, ::TString( prefix ) + "topoInvMass", &master ),
        effTopoInvMass( this, ::TString( prefix ) + "effTopoInvMass", &master ),
        topoMeanDeltaR( this, ::TString( prefix ) + "topoMeanDeltaR", &master ),
        effTopoMeanDeltaR( this, ::TString( prefix ) + "effTopoMeanDeltaR", &master ),
        numCells( this, ::TString( prefix ) + "numCells", &master ),
        seedTrk_EMRadius( this, ::TString( prefix ) + "seedTrk_EMRadius", &master ),
        seedTrk_isolFrac( this, ::TString( prefix ) + "seedTrk_isolFrac", &master ),
        seedTrk_etChrgHadOverSumTrkPt( this, ::TString( prefix ) + "seedTrk_etChrgHadOverSumTrkPt", &master ),
        seedTrk_isolFracWide( this, ::TString( prefix ) + "seedTrk_isolFracWide", &master ),
        seedTrk_etHadAtEMScale( this, ::TString( prefix ) + "seedTrk_etHadAtEMScale", &master ),
        seedTrk_etEMAtEMScale( this, ::TString( prefix ) + "seedTrk_etEMAtEMScale", &master ),
        seedTrk_etEMCL( this, ::TString( prefix ) + "seedTrk_etEMCL", &master ),
        seedTrk_etChrgEM( this, ::TString( prefix ) + "seedTrk_etChrgEM", &master ),
        seedTrk_etNeuEM( this, ::TString( prefix ) + "seedTrk_etNeuEM", &master ),
        seedTrk_etResNeuEM( this, ::TString( prefix ) + "seedTrk_etResNeuEM", &master ),
        seedTrk_hadLeakEt( this, ::TString( prefix ) + "seedTrk_hadLeakEt", &master ),
        seedTrk_sumEMCellEtOverLeadTrkPt( this, ::TString( prefix ) + "seedTrk_sumEMCellEtOverLeadTrkPt", &master ),
        seedTrk_secMaxStripEt( this, ::TString( prefix ) + "seedTrk_secMaxStripEt", &master ),
        seedTrk_stripWidth2( this, ::TString( prefix ) + "seedTrk_stripWidth2", &master ),
        seedTrk_nStrip( this, ::TString( prefix ) + "seedTrk_nStrip", &master ),
        seedTrk_etChrgHad( this, ::TString( prefix ) + "seedTrk_etChrgHad", &master ),
        seedTrk_nOtherCoreTrk( this, ::TString( prefix ) + "seedTrk_nOtherCoreTrk", &master ),
        seedTrk_nIsolTrk( this, ::TString( prefix ) + "seedTrk_nIsolTrk", &master ),
        seedTrk_etIsolEM( this, ::TString( prefix ) + "seedTrk_etIsolEM", &master ),
        seedTrk_etIsolHad( this, ::TString( prefix ) + "seedTrk_etIsolHad", &master ),
        cellBasedEnergyRing1( this, ::TString( prefix ) + "cellBasedEnergyRing1", &master ),
        cellBasedEnergyRing2( this, ::TString( prefix ) + "cellBasedEnergyRing2", &master ),
        cellBasedEnergyRing3( this, ::TString( prefix ) + "cellBasedEnergyRing3", &master ),
        cellBasedEnergyRing4( this, ::TString( prefix ) + "cellBasedEnergyRing4", &master ),
        cellBasedEnergyRing5( this, ::TString( prefix ) + "cellBasedEnergyRing5", &master ),
        cellBasedEnergyRing6( this, ::TString( prefix ) + "cellBasedEnergyRing6", &master ),
        cellBasedEnergyRing7( this, ::TString( prefix ) + "cellBasedEnergyRing7", &master ),
        calcVars_etHad_EMScale_Pt3Trks( this, ::TString( prefix ) + "calcVars_etHad_EMScale_Pt3Trks", &master ),
        calcVars_etEM_EMScale_Pt3Trks( this, ::TString( prefix ) + "calcVars_etEM_EMScale_Pt3Trks", &master ),
        calcVars_ipSigLeadLooseTrk( this, ::TString( prefix ) + "calcVars_ipSigLeadLooseTrk", &master ),
        calcVars_drMin( this, ::TString( prefix ) + "calcVars_drMin", &master ),
        calcVars_calRadius( this, ::TString( prefix ) + "calcVars_calRadius", &master ),
        calcVars_EMFractionAtEMScale( this, ::TString( prefix ) + "calcVars_EMFractionAtEMScale", &master ),
        calcVars_trackIso( this, ::TString( prefix ) + "calcVars_trackIso", &master ),
        calcVars_ChPiEMEOverCaloEME( this, ::TString( prefix ) + "calcVars_ChPiEMEOverCaloEME", &master ),
        calcVars_PSSFraction( this, ::TString( prefix ) + "calcVars_PSSFraction", &master ),
        calcVars_EMPOverTrkSysP( this, ::TString( prefix ) + "calcVars_EMPOverTrkSysP", &master ),
        calcVars_pi0BDTPrimaryScore( this, ::TString( prefix ) + "calcVars_pi0BDTPrimaryScore", &master ),
        calcVars_pi0BDTSecondaryScore( this, ::TString( prefix ) + "calcVars_pi0BDTSecondaryScore", &master ),
        calcVars_corrCentFrac( this, ::TString( prefix ) + "calcVars_corrCentFrac", &master ),
        calcVars_corrFTrk( this, ::TString( prefix ) + "calcVars_corrFTrk", &master ),
        calcVars_interAxis_eta( this, ::TString( prefix ) + "calcVars_interAxis_eta", &master ),
        calcVars_interAxis_phi( this, ::TString( prefix ) + "calcVars_interAxis_phi", &master ),
        pi0_cl1_pt( this, ::TString( prefix ) + "pi0_cl1_pt", &master ),
        pi0_cl1_eta( this, ::TString( prefix ) + "pi0_cl1_eta", &master ),
        pi0_cl1_phi( this, ::TString( prefix ) + "pi0_cl1_phi", &master ),
        pi0_cl2_pt( this, ::TString( prefix ) + "pi0_cl2_pt", &master ),
        pi0_cl2_eta( this, ::TString( prefix ) + "pi0_cl2_eta", &master ),
        pi0_cl2_phi( this, ::TString( prefix ) + "pi0_cl2_phi", &master ),
        pi0_vistau_pt( this, ::TString( prefix ) + "pi0_vistau_pt", &master ),
        pi0_vistau_eta( this, ::TString( prefix ) + "pi0_vistau_eta", &master ),
        pi0_vistau_phi( this, ::TString( prefix ) + "pi0_vistau_phi", &master ),
        pi0_vistau_m( this, ::TString( prefix ) + "pi0_vistau_m", &master ),
        pi0_n( this, ::TString( prefix ) + "pi0_n", &master ),
        pantau_isPanTauCandidate( this, ::TString( prefix ) + "pantau_isPanTauCandidate", &master ),
        pantau_PanTauScore( this, ::TString( prefix ) + "pantau_PanTauScore", &master ),
        pantau_NChargedEFO( this, ::TString( prefix ) + "pantau_NChargedEFO", &master ),
        pantau_NChargedQualifiedEFO( this, ::TString( prefix ) + "pantau_NChargedQualifiedEFO", &master ),
        pantau_NNeutralEFO( this, ::TString( prefix ) + "pantau_NNeutralEFO", &master ),
        pantau_AbsSumCharge( this, ::TString( prefix ) + "pantau_AbsSumCharge", &master ),
        pantau_EflowJetMomentDRAll( this, ::TString( prefix ) + "pantau_EflowJetMomentDRAll", &master ),
        pantau_EflowJetMomentDRChrg( this, ::TString( prefix ) + "pantau_EflowJetMomentDRChrg", &master ),
        pantau_EflowJetMomentDREMNeut( this, ::TString( prefix ) + "pantau_EflowJetMomentDREMNeut", &master ),
        pantau_EflowJetMomentDRHADNeut( this, ::TString( prefix ) + "pantau_EflowJetMomentDRHADNeut", &master ),
        pantau_EtIn01OverEtIn02InvSigm( this, ::TString( prefix ) + "pantau_EtIn01OverEtIn02InvSigm", &master ),
        pantau_EtIn02To04OverTotalEtInvSigm( this, ::TString( prefix ) + "pantau_EtIn02To04OverTotalEtInvSigm", &master ),
        pantau_EtIn01OverEtIn04InvSigm( this, ::TString( prefix ) + "pantau_EtIn01OverEtIn04InvSigm", &master ),
        pantau_EtIn01OverEtIn04( this, ::TString( prefix ) + "pantau_EtIn01OverEtIn04", &master ),
        pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents( this, ::TString( prefix ) + "pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents", &master ),
        pantau_JetSphericity( this, ::TString( prefix ) + "pantau_JetSphericity", &master ),
        pantau_TransImpactParamSignfTrack1( this, ::TString( prefix ) + "pantau_TransImpactParamSignfTrack1", &master ),
        pantau_EflowAngleJetAxisLeadingChargedQualified( this, ::TString( prefix ) + "pantau_EflowAngleJetAxisLeadingChargedQualified", &master ),
        pantau_EflowAngleChargedAxisNeutralAxis( this, ::TString( prefix ) + "pantau_EflowAngleChargedAxisNeutralAxis", &master ),
        pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified( this, ::TString( prefix ) + "pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified", &master ),
        pantau_EflowInvariantMassAll( this, ::TString( prefix ) + "pantau_EflowInvariantMassAll", &master ),
        pantau_EflowStdDevEtToSumEt( this, ::TString( prefix ) + "pantau_EflowStdDevEtToSumEt", &master ),
        pantau_EflowEtLeadingChrgQualifiedOverTotalEt( this, ::TString( prefix ) + "pantau_EflowEtLeadingChrgQualifiedOverTotalEt", &master ),
        pantau_EflowSumEAll( this, ::TString( prefix ) + "pantau_EflowSumEAll", &master ),
        pantau_EflowChargedSumEt( this, ::TString( prefix ) + "pantau_EflowChargedSumEt", &master ),
        leadTrack_eta( this, ::TString( prefix ) + "leadTrack_eta", &master ),
        leadTrack_phi( this, ::TString( prefix ) + "leadTrack_phi", &master ),
        cluster_E( this, ::TString( prefix ) + "cluster_E", &master ),
        cluster_eta( this, ::TString( prefix ) + "cluster_eta", &master ),
        cluster_phi( this, ::TString( prefix ) + "cluster_phi", &master ),
        cluster_eta_atTJVA( this, ::TString( prefix ) + "cluster_eta_atTJVA", &master ),
        cluster_phi_atTJVA( this, ::TString( prefix ) + "cluster_phi_atTJVA", &master ),
        cluster_PreSamplerStripF( this, ::TString( prefix ) + "cluster_PreSamplerStripF", &master ),
        cluster_EMLayer2F( this, ::TString( prefix ) + "cluster_EMLayer2F", &master ),
        cluster_EMLayer3F( this, ::TString( prefix ) + "cluster_EMLayer3F", &master ),
        cluster_n( this, ::TString( prefix ) + "cluster_n", &master ),
        Pi0Cluster_pt( this, ::TString( prefix ) + "Pi0Cluster_pt", &master ),
        Pi0Cluster_eta( this, ::TString( prefix ) + "Pi0Cluster_eta", &master ),
        Pi0Cluster_phi( this, ::TString( prefix ) + "Pi0Cluster_phi", &master ),
        secvtx_x( this, ::TString( prefix ) + "secvtx_x", &master ),
        secvtx_y( this, ::TString( prefix ) + "secvtx_y", &master ),
        secvtx_z( this, ::TString( prefix ) + "secvtx_z", &master ),
        secvtx_xx( this, ::TString( prefix ) + "secvtx_xx", &master ),
        secvtx_yy( this, ::TString( prefix ) + "secvtx_yy", &master ),
        secvtx_zz( this, ::TString( prefix ) + "secvtx_zz", &master ),
        secvtx_xy( this, ::TString( prefix ) + "secvtx_xy", &master ),
        secvtx_yz( this, ::TString( prefix ) + "secvtx_yz", &master ),
        secvtx_zx( this, ::TString( prefix ) + "secvtx_zx", &master ),
        secvtx_chiSquared( this, ::TString( prefix ) + "secvtx_chiSquared", &master ),
        secvtx_numberDoF( this, ::TString( prefix ) + "secvtx_numberDoF", &master ),
        privtx_x( this, ::TString( prefix ) + "privtx_x", &master ),
        privtx_y( this, ::TString( prefix ) + "privtx_y", &master ),
        privtx_z( this, ::TString( prefix ) + "privtx_z", &master ),
        privtx_xx( this, ::TString( prefix ) + "privtx_xx", &master ),
        privtx_yy( this, ::TString( prefix ) + "privtx_yy", &master ),
        privtx_zz( this, ::TString( prefix ) + "privtx_zz", &master ),
        privtx_xy( this, ::TString( prefix ) + "privtx_xy", &master ),
        privtx_yz( this, ::TString( prefix ) + "privtx_yz", &master ),
        privtx_zx( this, ::TString( prefix ) + "privtx_zx", &master ),
        privtx_chiSquared( this, ::TString( prefix ) + "privtx_chiSquared", &master ),
        privtx_numberDoF( this, ::TString( prefix ) + "privtx_numberDoF", &master ),
        privtx_jvf( this, ::TString( prefix ) + "privtx_jvf", &master ),
        jet_Et( this, ::TString( prefix ) + "jet_Et", &master ),
        jet_pt( this, ::TString( prefix ) + "jet_pt", &master ),
        jet_m( this, ::TString( prefix ) + "jet_m", &master ),
        jet_eta( this, ::TString( prefix ) + "jet_eta", &master ),
        jet_phi( this, ::TString( prefix ) + "jet_phi", &master ),
        jet_WIDTH( this, ::TString( prefix ) + "jet_WIDTH", &master ),
        jet_n90( this, ::TString( prefix ) + "jet_n90", &master ),
        jet_n90constituents( this, ::TString( prefix ) + "jet_n90constituents", &master ),
        jet_BCH_CORR_CELL( this, ::TString( prefix ) + "jet_BCH_CORR_CELL", &master ),
        jet_BCH_CORR_JET( this, ::TString( prefix ) + "jet_BCH_CORR_JET", &master ),
        jet_BCH_CORR_JET_FORCELL( this, ::TString( prefix ) + "jet_BCH_CORR_JET_FORCELL", &master ),
        jet_ENG_BAD_CELLS( this, ::TString( prefix ) + "jet_ENG_BAD_CELLS", &master ),
        jet_N_BAD_CELLS( this, ::TString( prefix ) + "jet_N_BAD_CELLS", &master ),
        jet_N_BAD_CELLS_CORR( this, ::TString( prefix ) + "jet_N_BAD_CELLS_CORR", &master ),
        jet_BAD_CELLS_CORR_E( this, ::TString( prefix ) + "jet_BAD_CELLS_CORR_E", &master ),
        jet_Timing( this, ::TString( prefix ) + "jet_Timing", &master ),
        jet_LArQuality( this, ::TString( prefix ) + "jet_LArQuality", &master ),
        jet_nTrk( this, ::TString( prefix ) + "jet_nTrk", &master ),
        jet_sumPtTrk( this, ::TString( prefix ) + "jet_sumPtTrk", &master ),
        jet_OriginIndex( this, ::TString( prefix ) + "jet_OriginIndex", &master ),
        jet_HECQuality( this, ::TString( prefix ) + "jet_HECQuality", &master ),
        jet_NegativeE( this, ::TString( prefix ) + "jet_NegativeE", &master ),
        jet_YFlip12( this, ::TString( prefix ) + "jet_YFlip12", &master ),
        jet_YFlip23( this, ::TString( prefix ) + "jet_YFlip23", &master ),
        jet_BCH_CORR_DOTX( this, ::TString( prefix ) + "jet_BCH_CORR_DOTX", &master ),
        jet_SamplingMax( this, ::TString( prefix ) + "jet_SamplingMax", &master ),
        jet_fracSamplingMax( this, ::TString( prefix ) + "jet_fracSamplingMax", &master ),
        jet_hecf( this, ::TString( prefix ) + "jet_hecf", &master ),
        jet_tgap3f( this, ::TString( prefix ) + "jet_tgap3f", &master ),
        jet_isUgly( this, ::TString( prefix ) + "jet_isUgly", &master ),
        jet_isBadLooseMinus( this, ::TString( prefix ) + "jet_isBadLooseMinus", &master ),
        jet_isBadLoose( this, ::TString( prefix ) + "jet_isBadLoose", &master ),
        jet_isBadMedium( this, ::TString( prefix ) + "jet_isBadMedium", &master ),
        jet_isBadTight( this, ::TString( prefix ) + "jet_isBadTight", &master ),
        jet_emfrac( this, ::TString( prefix ) + "jet_emfrac", &master ),
        jet_GCWJES( this, ::TString( prefix ) + "jet_GCWJES", &master ),
        jet_EMJES( this, ::TString( prefix ) + "jet_EMJES", &master ),
        jet_emscale_E( this, ::TString( prefix ) + "jet_emscale_E", &master ),
        jet_emscale_pt( this, ::TString( prefix ) + "jet_emscale_pt", &master ),
        jet_emscale_m( this, ::TString( prefix ) + "jet_emscale_m", &master ),
        jet_emscale_eta( this, ::TString( prefix ) + "jet_emscale_eta", &master ),
        jet_emscale_phi( this, ::TString( prefix ) + "jet_emscale_phi", &master ),
        jet_jvtx_x( this, ::TString( prefix ) + "jet_jvtx_x", &master ),
        jet_jvtx_y( this, ::TString( prefix ) + "jet_jvtx_y", &master ),
        jet_jvtx_z( this, ::TString( prefix ) + "jet_jvtx_z", &master ),
        jet_jvtxf( this, ::TString( prefix ) + "jet_jvtxf", &master ),
        jet_flavor_weight( this, ::TString( prefix ) + "jet_flavor_weight", &master ),
        jet_flavor_weight_TrackCounting2D( this, ::TString( prefix ) + "jet_flavor_weight_TrackCounting2D", &master ),
        jet_flavor_weight_JetProb( this, ::TString( prefix ) + "jet_flavor_weight_JetProb", &master ),
        jet_flavor_weight_IP1D( this, ::TString( prefix ) + "jet_flavor_weight_IP1D", &master ),
        jet_flavor_weight_IP2D( this, ::TString( prefix ) + "jet_flavor_weight_IP2D", &master ),
        jet_flavor_weight_IP3D( this, ::TString( prefix ) + "jet_flavor_weight_IP3D", &master ),
        jet_flavor_weight_SV0( this, ::TString( prefix ) + "jet_flavor_weight_SV0", &master ),
        jet_flavor_weight_SV1( this, ::TString( prefix ) + "jet_flavor_weight_SV1", &master ),
        jet_flavor_weight_SV2( this, ::TString( prefix ) + "jet_flavor_weight_SV2", &master ),
        jet_flavor_weight_JetFitterTag( this, ::TString( prefix ) + "jet_flavor_weight_JetFitterTag", &master ),
        jet_flavor_weight_JetFitterCOMB( this, ::TString( prefix ) + "jet_flavor_weight_JetFitterCOMB", &master ),
        jet_flavor_weight_JetFitterTagNN( this, ::TString( prefix ) + "jet_flavor_weight_JetFitterTagNN", &master ),
        jet_flavor_weight_JetFitterCOMBNN( this, ::TString( prefix ) + "jet_flavor_weight_JetFitterCOMBNN", &master ),
        jet_flavor_weight_SoftMuonTag( this, ::TString( prefix ) + "jet_flavor_weight_SoftMuonTag", &master ),
        jet_flavor_weight_SoftElectronTag( this, ::TString( prefix ) + "jet_flavor_weight_SoftElectronTag", &master ),
        jet_flavor_weight_IP3DSV1( this, ::TString( prefix ) + "jet_flavor_weight_IP3DSV1", &master ),
        jet_e_PreSamplerB( this, ::TString( prefix ) + "jet_e_PreSamplerB", &master ),
        jet_e_EMB1( this, ::TString( prefix ) + "jet_e_EMB1", &master ),
        jet_e_EMB2( this, ::TString( prefix ) + "jet_e_EMB2", &master ),
        jet_e_EMB3( this, ::TString( prefix ) + "jet_e_EMB3", &master ),
        jet_e_PreSamplerE( this, ::TString( prefix ) + "jet_e_PreSamplerE", &master ),
        jet_e_EME1( this, ::TString( prefix ) + "jet_e_EME1", &master ),
        jet_e_EME2( this, ::TString( prefix ) + "jet_e_EME2", &master ),
        jet_e_EME3( this, ::TString( prefix ) + "jet_e_EME3", &master ),
        jet_e_HEC0( this, ::TString( prefix ) + "jet_e_HEC0", &master ),
        jet_e_HEC1( this, ::TString( prefix ) + "jet_e_HEC1", &master ),
        jet_e_HEC2( this, ::TString( prefix ) + "jet_e_HEC2", &master ),
        jet_e_HEC3( this, ::TString( prefix ) + "jet_e_HEC3", &master ),
        jet_e_TileBar0( this, ::TString( prefix ) + "jet_e_TileBar0", &master ),
        jet_e_TileBar1( this, ::TString( prefix ) + "jet_e_TileBar1", &master ),
        jet_e_TileBar2( this, ::TString( prefix ) + "jet_e_TileBar2", &master ),
        jet_e_TileGap1( this, ::TString( prefix ) + "jet_e_TileGap1", &master ),
        jet_e_TileGap2( this, ::TString( prefix ) + "jet_e_TileGap2", &master ),
        jet_e_TileGap3( this, ::TString( prefix ) + "jet_e_TileGap3", &master ),
        jet_e_TileExt0( this, ::TString( prefix ) + "jet_e_TileExt0", &master ),
        jet_e_TileExt1( this, ::TString( prefix ) + "jet_e_TileExt1", &master ),
        jet_e_TileExt2( this, ::TString( prefix ) + "jet_e_TileExt2", &master ),
        jet_e_FCAL0( this, ::TString( prefix ) + "jet_e_FCAL0", &master ),
        jet_e_FCAL1( this, ::TString( prefix ) + "jet_e_FCAL1", &master ),
        jet_e_FCAL2( this, ::TString( prefix ) + "jet_e_FCAL2", &master ),
        jet_shapeBins( this, ::TString( prefix ) + "jet_shapeBins", &master ),
        track_atTJVA_n( this, ::TString( prefix ) + "track_atTJVA_n", &master ),
        track_atTJVA_d0( this, ::TString( prefix ) + "track_atTJVA_d0", &master ),
        track_atTJVA_z0( this, ::TString( prefix ) + "track_atTJVA_z0", &master ),
        track_atTJVA_phi( this, ::TString( prefix ) + "track_atTJVA_phi", &master ),
        track_atTJVA_theta( this, ::TString( prefix ) + "track_atTJVA_theta", &master ),
        track_atTJVA_qoverp( this, ::TString( prefix ) + "track_atTJVA_qoverp", &master ),
        track_atTJVA_pt( this, ::TString( prefix ) + "track_atTJVA_pt", &master ),
        track_atTJVA_eta( this, ::TString( prefix ) + "track_atTJVA_eta", &master ),
        seedCalo_wideTrk_atTJVA_n( this, ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_n", &master ),
        seedCalo_wideTrk_atTJVA_d0( this, ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_d0", &master ),
        seedCalo_wideTrk_atTJVA_z0( this, ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_z0", &master ),
        seedCalo_wideTrk_atTJVA_phi( this, ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_phi", &master ),
        seedCalo_wideTrk_atTJVA_theta( this, ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_theta", &master ),
        seedCalo_wideTrk_atTJVA_qoverp( this, ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_qoverp", &master ),
        seedCalo_wideTrk_atTJVA_pt( this, ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_pt", &master ),
        seedCalo_wideTrk_atTJVA_eta( this, ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_eta", &master ),
        otherTrk_atTJVA_n( this, ::TString( prefix ) + "otherTrk_atTJVA_n", &master ),
        track_n( this, ::TString( prefix ) + "track_n", &master ),
        track_d0( this, ::TString( prefix ) + "track_d0", &master ),
        track_z0( this, ::TString( prefix ) + "track_z0", &master ),
        track_phi( this, ::TString( prefix ) + "track_phi", &master ),
        track_theta( this, ::TString( prefix ) + "track_theta", &master ),
        track_qoverp( this, ::TString( prefix ) + "track_qoverp", &master ),
        track_pt( this, ::TString( prefix ) + "track_pt", &master ),
        track_eta( this, ::TString( prefix ) + "track_eta", &master ),
        track_atPV_d0( this, ::TString( prefix ) + "track_atPV_d0", &master ),
        track_atPV_z0( this, ::TString( prefix ) + "track_atPV_z0", &master ),
        track_atPV_phi( this, ::TString( prefix ) + "track_atPV_phi", &master ),
        track_atPV_theta( this, ::TString( prefix ) + "track_atPV_theta", &master ),
        track_atPV_qoverp( this, ::TString( prefix ) + "track_atPV_qoverp", &master ),
        track_atPV_pt( this, ::TString( prefix ) + "track_atPV_pt", &master ),
        track_atPV_eta( this, ::TString( prefix ) + "track_atPV_eta", &master ),
        track_nBLHits( this, ::TString( prefix ) + "track_nBLHits", &master ),
        track_nPixHits( this, ::TString( prefix ) + "track_nPixHits", &master ),
        track_nSCTHits( this, ::TString( prefix ) + "track_nSCTHits", &master ),
        track_nTRTHits( this, ::TString( prefix ) + "track_nTRTHits", &master ),
        track_nTRTHighTHits( this, ::TString( prefix ) + "track_nTRTHighTHits", &master ),
        track_nTRTXenonHits( this, ::TString( prefix ) + "track_nTRTXenonHits", &master ),
        track_nPixHoles( this, ::TString( prefix ) + "track_nPixHoles", &master ),
        track_nSCTHoles( this, ::TString( prefix ) + "track_nSCTHoles", &master ),
        track_nTRTHoles( this, ::TString( prefix ) + "track_nTRTHoles", &master ),
        track_nPixelDeadSensors( this, ::TString( prefix ) + "track_nPixelDeadSensors", &master ),
        track_nSCTDeadSensors( this, ::TString( prefix ) + "track_nSCTDeadSensors", &master ),
        track_nBLSharedHits( this, ::TString( prefix ) + "track_nBLSharedHits", &master ),
        track_nPixSharedHits( this, ::TString( prefix ) + "track_nPixSharedHits", &master ),
        track_nSCTSharedHits( this, ::TString( prefix ) + "track_nSCTSharedHits", &master ),
        track_nBLayerSplitHits( this, ::TString( prefix ) + "track_nBLayerSplitHits", &master ),
        track_nPixSplitHits( this, ::TString( prefix ) + "track_nPixSplitHits", &master ),
        track_nBLayerOutliers( this, ::TString( prefix ) + "track_nBLayerOutliers", &master ),
        track_nPixelOutliers( this, ::TString( prefix ) + "track_nPixelOutliers", &master ),
        track_nSCTOutliers( this, ::TString( prefix ) + "track_nSCTOutliers", &master ),
        track_nTRTOutliers( this, ::TString( prefix ) + "track_nTRTOutliers", &master ),
        track_nTRTHighTOutliers( this, ::TString( prefix ) + "track_nTRTHighTOutliers", &master ),
        track_nContribPixelLayers( this, ::TString( prefix ) + "track_nContribPixelLayers", &master ),
        track_nGangedPixels( this, ::TString( prefix ) + "track_nGangedPixels", &master ),
        track_nGangedFlaggedFakes( this, ::TString( prefix ) + "track_nGangedFlaggedFakes", &master ),
        track_nPixelSpoiltHits( this, ::TString( prefix ) + "track_nPixelSpoiltHits", &master ),
        track_nSCTDoubleHoles( this, ::TString( prefix ) + "track_nSCTDoubleHoles", &master ),
        track_nSCTSpoiltHits( this, ::TString( prefix ) + "track_nSCTSpoiltHits", &master ),
        track_expectBLayerHit( this, ::TString( prefix ) + "track_expectBLayerHit", &master ),
        track_nHits( this, ::TString( prefix ) + "track_nHits", &master ),
        track_TRTHighTHitsRatio( this, ::TString( prefix ) + "track_TRTHighTHitsRatio", &master ),
        track_TRTHighTOutliersRatio( this, ::TString( prefix ) + "track_TRTHighTOutliersRatio", &master ),
        seedCalo_track_n( this, ::TString( prefix ) + "seedCalo_track_n", &master ),
        seedCalo_wideTrk_n( this, ::TString( prefix ) + "seedCalo_wideTrk_n", &master ),
        seedCalo_wideTrk_nBLHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nBLHits", &master ),
        seedCalo_wideTrk_nPixHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nPixHits", &master ),
        seedCalo_wideTrk_nSCTHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nSCTHits", &master ),
        seedCalo_wideTrk_nTRTHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nTRTHits", &master ),
        seedCalo_wideTrk_nTRTHighTHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nTRTHighTHits", &master ),
        seedCalo_wideTrk_nTRTXenonHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nTRTXenonHits", &master ),
        seedCalo_wideTrk_nPixHoles( this, ::TString( prefix ) + "seedCalo_wideTrk_nPixHoles", &master ),
        seedCalo_wideTrk_nSCTHoles( this, ::TString( prefix ) + "seedCalo_wideTrk_nSCTHoles", &master ),
        seedCalo_wideTrk_nTRTHoles( this, ::TString( prefix ) + "seedCalo_wideTrk_nTRTHoles", &master ),
        seedCalo_wideTrk_nPixelDeadSensors( this, ::TString( prefix ) + "seedCalo_wideTrk_nPixelDeadSensors", &master ),
        seedCalo_wideTrk_nSCTDeadSensors( this, ::TString( prefix ) + "seedCalo_wideTrk_nSCTDeadSensors", &master ),
        seedCalo_wideTrk_nBLSharedHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nBLSharedHits", &master ),
        seedCalo_wideTrk_nPixSharedHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nPixSharedHits", &master ),
        seedCalo_wideTrk_nSCTSharedHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nSCTSharedHits", &master ),
        seedCalo_wideTrk_nBLayerSplitHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nBLayerSplitHits", &master ),
        seedCalo_wideTrk_nPixSplitHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nPixSplitHits", &master ),
        seedCalo_wideTrk_nBLayerOutliers( this, ::TString( prefix ) + "seedCalo_wideTrk_nBLayerOutliers", &master ),
        seedCalo_wideTrk_nPixelOutliers( this, ::TString( prefix ) + "seedCalo_wideTrk_nPixelOutliers", &master ),
        seedCalo_wideTrk_nSCTOutliers( this, ::TString( prefix ) + "seedCalo_wideTrk_nSCTOutliers", &master ),
        seedCalo_wideTrk_nTRTOutliers( this, ::TString( prefix ) + "seedCalo_wideTrk_nTRTOutliers", &master ),
        seedCalo_wideTrk_nTRTHighTOutliers( this, ::TString( prefix ) + "seedCalo_wideTrk_nTRTHighTOutliers", &master ),
        seedCalo_wideTrk_nContribPixelLayers( this, ::TString( prefix ) + "seedCalo_wideTrk_nContribPixelLayers", &master ),
        seedCalo_wideTrk_nGangedPixels( this, ::TString( prefix ) + "seedCalo_wideTrk_nGangedPixels", &master ),
        seedCalo_wideTrk_nGangedFlaggedFakes( this, ::TString( prefix ) + "seedCalo_wideTrk_nGangedFlaggedFakes", &master ),
        seedCalo_wideTrk_nPixelSpoiltHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nPixelSpoiltHits", &master ),
        seedCalo_wideTrk_nSCTDoubleHoles( this, ::TString( prefix ) + "seedCalo_wideTrk_nSCTDoubleHoles", &master ),
        seedCalo_wideTrk_nSCTSpoiltHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nSCTSpoiltHits", &master ),
        seedCalo_wideTrk_expectBLayerHit( this, ::TString( prefix ) + "seedCalo_wideTrk_expectBLayerHit", &master ),
        seedCalo_wideTrk_nHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nHits", &master ),
        otherTrk_n( this, ::TString( prefix ) + "otherTrk_n", &master ),
        EF_dr( this, ::TString( prefix ) + "EF_dr", &master ),
        EF_E( this, ::TString( prefix ) + "EF_E", &master ),
        EF_Et( this, ::TString( prefix ) + "EF_Et", &master ),
        EF_pt( this, ::TString( prefix ) + "EF_pt", &master ),
        EF_eta( this, ::TString( prefix ) + "EF_eta", &master ),
        EF_phi( this, ::TString( prefix ) + "EF_phi", &master ),
        EF_matched( this, ::TString( prefix ) + "EF_matched", &master ),
        L2_dr( this, ::TString( prefix ) + "L2_dr", &master ),
        L2_E( this, ::TString( prefix ) + "L2_E", &master ),
        L2_Et( this, ::TString( prefix ) + "L2_Et", &master ),
        L2_pt( this, ::TString( prefix ) + "L2_pt", &master ),
        L2_eta( this, ::TString( prefix ) + "L2_eta", &master ),
        L2_phi( this, ::TString( prefix ) + "L2_phi", &master ),
        L2_matched( this, ::TString( prefix ) + "L2_matched", &master ),
        L1_dr( this, ::TString( prefix ) + "L1_dr", &master ),
        L1_Et( this, ::TString( prefix ) + "L1_Et", &master ),
        L1_pt( this, ::TString( prefix ) + "L1_pt", &master ),
        L1_eta( this, ::TString( prefix ) + "L1_eta", &master ),
        L1_phi( this, ::TString( prefix ) + "L1_phi", &master ),
        L1_matched( this, ::TString( prefix ) + "L1_matched", &master ),
// MC only
        trueTauAssocSmall_dr( this, ::TString( prefix ) + "trueTauAssocSmall_dr", &master ),
        trueTauAssocSmall_index( this, ::TString( prefix ) + "trueTauAssocSmall_index", &master ),
        trueTauAssocSmall_matched( this, ::TString( prefix ) + "trueTauAssocSmall_matched", &master ),
// end MC only
        MET_Egamma10LooseTau_wpx( this, ::TString( prefix ) + "MET_Egamma10LooseTau_wpx", &master ),
        MET_Egamma10LooseTau_wpy( this, ::TString( prefix ) + "MET_Egamma10LooseTau_wpy", &master ),
        MET_Egamma10LooseTau_wet( this, ::TString( prefix ) + "MET_Egamma10LooseTau_wet", &master ),
        MET_Egamma10LooseTau_statusWord( this, ::TString( prefix ) + "MET_Egamma10LooseTau_statusWord", &master ),
        MET_wpx( this, ::TString( prefix ) + "MET_wpx", &master ),
        MET_wpy( this, ::TString( prefix ) + "MET_wpy", &master ),
        MET_wet( this, ::TString( prefix ) + "MET_wet", &master ),
        MET_statusWord( this, ::TString( prefix ) + "MET_statusWord", &master ),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "n" ] = &n;
      fHandles[ "Et" ] = &Et;
      fHandles[ "pt" ] = &pt;
      fHandles[ "m" ] = &m;
      fHandles[ "eta" ] = &eta;
      fHandles[ "phi" ] = &phi;
      fHandles[ "charge" ] = &charge;
      fHandles[ "BDTEleScore" ] = &BDTEleScore;
      fHandles[ "BDTJetScore" ] = &BDTJetScore;
      fHandles[ "likelihood" ] = &likelihood;
      fHandles[ "SafeLikelihood" ] = &SafeLikelihood;
      fHandles[ "electronVetoLoose" ] = &electronVetoLoose;
      fHandles[ "electronVetoMedium" ] = &electronVetoMedium;
      fHandles[ "electronVetoTight" ] = &electronVetoTight;
      fHandles[ "muonVeto" ] = &muonVeto;
      fHandles[ "tauLlhLoose" ] = &tauLlhLoose;
      fHandles[ "tauLlhMedium" ] = &tauLlhMedium;
      fHandles[ "tauLlhTight" ] = &tauLlhTight;
      fHandles[ "JetBDTSigLoose" ] = &JetBDTSigLoose;
      fHandles[ "JetBDTSigMedium" ] = &JetBDTSigMedium;
      fHandles[ "JetBDTSigTight" ] = &JetBDTSigTight;
      fHandles[ "EleBDTLoose" ] = &EleBDTLoose;
      fHandles[ "EleBDTMedium" ] = &EleBDTMedium;
      fHandles[ "EleBDTTight" ] = &EleBDTTight;
      fHandles[ "author" ] = &author;
      fHandles[ "RoIWord" ] = &RoIWord;
      fHandles[ "nProng" ] = &nProng;
      fHandles[ "numTrack" ] = &numTrack;
      fHandles[ "seedCalo_numTrack" ] = &seedCalo_numTrack;
      fHandles[ "seedCalo_nWideTrk" ] = &seedCalo_nWideTrk;
      fHandles[ "nOtherTrk" ] = &nOtherTrk;
      fHandles[ "etOverPtLeadTrk" ] = &etOverPtLeadTrk;
      fHandles[ "ipZ0SinThetaSigLeadTrk" ] = &ipZ0SinThetaSigLeadTrk;
      fHandles[ "leadTrkPt" ] = &leadTrkPt;
      fHandles[ "nLooseTrk" ] = &nLooseTrk;
      fHandles[ "nLooseConvTrk" ] = &nLooseConvTrk;
      fHandles[ "nProngLoose" ] = &nProngLoose;
      fHandles[ "ipSigLeadTrk" ] = &ipSigLeadTrk;
      fHandles[ "ipSigLeadLooseTrk" ] = &ipSigLeadLooseTrk;
      fHandles[ "etOverPtLeadLooseTrk" ] = &etOverPtLeadLooseTrk;
      fHandles[ "leadLooseTrkPt" ] = &leadLooseTrkPt;
      fHandles[ "chrgLooseTrk" ] = &chrgLooseTrk;
      fHandles[ "massTrkSys" ] = &massTrkSys;
      fHandles[ "trkWidth2" ] = &trkWidth2;
      fHandles[ "trFlightPathSig" ] = &trFlightPathSig;
      fHandles[ "etEflow" ] = &etEflow;
      fHandles[ "mEflow" ] = &mEflow;
      fHandles[ "nPi0" ] = &nPi0;
      fHandles[ "ele_E237E277" ] = &ele_E237E277;
      fHandles[ "ele_PresamplerFraction" ] = &ele_PresamplerFraction;
      fHandles[ "ele_ECALFirstFraction" ] = &ele_ECALFirstFraction;
      fHandles[ "EM_TES_scale" ] = &EM_TES_scale;
      fHandles[ "LC_TES_precalib" ] = &LC_TES_precalib;
      fHandles[ "TRTHTOverLT_LeadTrk" ] = &TRTHTOverLT_LeadTrk;
      fHandles[ "seedCalo_EMRadius" ] = &seedCalo_EMRadius;
      fHandles[ "seedCalo_hadRadius" ] = &seedCalo_hadRadius;
      fHandles[ "seedCalo_etEMAtEMScale" ] = &seedCalo_etEMAtEMScale;
      fHandles[ "seedCalo_etHadAtEMScale" ] = &seedCalo_etHadAtEMScale;
      fHandles[ "seedCalo_isolFrac" ] = &seedCalo_isolFrac;
      fHandles[ "seedCalo_centFrac" ] = &seedCalo_centFrac;
      fHandles[ "seedCalo_stripWidth2" ] = &seedCalo_stripWidth2;
      fHandles[ "seedCalo_nStrip" ] = &seedCalo_nStrip;
      fHandles[ "seedCalo_eta" ] = &seedCalo_eta;
      fHandles[ "seedCalo_phi" ] = &seedCalo_phi;
      fHandles[ "seedCalo_nIsolLooseTrk" ] = &seedCalo_nIsolLooseTrk;
      fHandles[ "seedCalo_trkAvgDist" ] = &seedCalo_trkAvgDist;
      fHandles[ "seedCalo_trkRmsDist" ] = &seedCalo_trkRmsDist;
      fHandles[ "seedCalo_caloIso" ] = &seedCalo_caloIso;
      fHandles[ "seedCalo_caloIsoCorrected" ] = &seedCalo_caloIsoCorrected;
      fHandles[ "seedCalo_dRmax" ] = &seedCalo_dRmax;
      fHandles[ "seedCalo_lead2ClusterEOverAllClusterE" ] = &seedCalo_lead2ClusterEOverAllClusterE;
      fHandles[ "seedCalo_lead3ClusterEOverAllClusterE" ] = &seedCalo_lead3ClusterEOverAllClusterE;
      fHandles[ "seedCalo_etHadCalib" ] = &seedCalo_etHadCalib;
      fHandles[ "seedCalo_etEMCalib" ] = &seedCalo_etEMCalib;
      fHandles[ "numTopoClusters" ] = &numTopoClusters;
      fHandles[ "numEffTopoClusters" ] = &numEffTopoClusters;
      fHandles[ "topoInvMass" ] = &topoInvMass;
      fHandles[ "effTopoInvMass" ] = &effTopoInvMass;
      fHandles[ "topoMeanDeltaR" ] = &topoMeanDeltaR;
      fHandles[ "effTopoMeanDeltaR" ] = &effTopoMeanDeltaR;
      fHandles[ "numCells" ] = &numCells;
      fHandles[ "seedTrk_EMRadius" ] = &seedTrk_EMRadius;
      fHandles[ "seedTrk_isolFrac" ] = &seedTrk_isolFrac;
      fHandles[ "seedTrk_etChrgHadOverSumTrkPt" ] = &seedTrk_etChrgHadOverSumTrkPt;
      fHandles[ "seedTrk_isolFracWide" ] = &seedTrk_isolFracWide;
      fHandles[ "seedTrk_etHadAtEMScale" ] = &seedTrk_etHadAtEMScale;
      fHandles[ "seedTrk_etEMAtEMScale" ] = &seedTrk_etEMAtEMScale;
      fHandles[ "seedTrk_etEMCL" ] = &seedTrk_etEMCL;
      fHandles[ "seedTrk_etChrgEM" ] = &seedTrk_etChrgEM;
      fHandles[ "seedTrk_etNeuEM" ] = &seedTrk_etNeuEM;
      fHandles[ "seedTrk_etResNeuEM" ] = &seedTrk_etResNeuEM;
      fHandles[ "seedTrk_hadLeakEt" ] = &seedTrk_hadLeakEt;
      fHandles[ "seedTrk_sumEMCellEtOverLeadTrkPt" ] = &seedTrk_sumEMCellEtOverLeadTrkPt;
      fHandles[ "seedTrk_secMaxStripEt" ] = &seedTrk_secMaxStripEt;
      fHandles[ "seedTrk_stripWidth2" ] = &seedTrk_stripWidth2;
      fHandles[ "seedTrk_nStrip" ] = &seedTrk_nStrip;
      fHandles[ "seedTrk_etChrgHad" ] = &seedTrk_etChrgHad;
      fHandles[ "seedTrk_nOtherCoreTrk" ] = &seedTrk_nOtherCoreTrk;
      fHandles[ "seedTrk_nIsolTrk" ] = &seedTrk_nIsolTrk;
      fHandles[ "seedTrk_etIsolEM" ] = &seedTrk_etIsolEM;
      fHandles[ "seedTrk_etIsolHad" ] = &seedTrk_etIsolHad;
      fHandles[ "cellBasedEnergyRing1" ] = &cellBasedEnergyRing1;
      fHandles[ "cellBasedEnergyRing2" ] = &cellBasedEnergyRing2;
      fHandles[ "cellBasedEnergyRing3" ] = &cellBasedEnergyRing3;
      fHandles[ "cellBasedEnergyRing4" ] = &cellBasedEnergyRing4;
      fHandles[ "cellBasedEnergyRing5" ] = &cellBasedEnergyRing5;
      fHandles[ "cellBasedEnergyRing6" ] = &cellBasedEnergyRing6;
      fHandles[ "cellBasedEnergyRing7" ] = &cellBasedEnergyRing7;
      fHandles[ "calcVars_etHad_EMScale_Pt3Trks" ] = &calcVars_etHad_EMScale_Pt3Trks;
      fHandles[ "calcVars_etEM_EMScale_Pt3Trks" ] = &calcVars_etEM_EMScale_Pt3Trks;
      fHandles[ "calcVars_ipSigLeadLooseTrk" ] = &calcVars_ipSigLeadLooseTrk;
      fHandles[ "calcVars_drMin" ] = &calcVars_drMin;
      fHandles[ "calcVars_calRadius" ] = &calcVars_calRadius;
      fHandles[ "calcVars_EMFractionAtEMScale" ] = &calcVars_EMFractionAtEMScale;
      fHandles[ "calcVars_trackIso" ] = &calcVars_trackIso;
      fHandles[ "calcVars_ChPiEMEOverCaloEME" ] = &calcVars_ChPiEMEOverCaloEME;
      fHandles[ "calcVars_PSSFraction" ] = &calcVars_PSSFraction;
      fHandles[ "calcVars_EMPOverTrkSysP" ] = &calcVars_EMPOverTrkSysP;
      fHandles[ "calcVars_pi0BDTPrimaryScore" ] = &calcVars_pi0BDTPrimaryScore;
      fHandles[ "calcVars_pi0BDTSecondaryScore" ] = &calcVars_pi0BDTSecondaryScore;
      fHandles[ "calcVars_corrCentFrac" ] = &calcVars_corrCentFrac;
      fHandles[ "calcVars_corrFTrk" ] = &calcVars_corrFTrk;
      fHandles[ "calcVars_interAxis_eta" ] = &calcVars_interAxis_eta;
      fHandles[ "calcVars_interAxis_phi" ] = &calcVars_interAxis_phi;
      fHandles[ "pi0_cl1_pt" ] = &pi0_cl1_pt;
      fHandles[ "pi0_cl1_eta" ] = &pi0_cl1_eta;
      fHandles[ "pi0_cl1_phi" ] = &pi0_cl1_phi;
      fHandles[ "pi0_cl2_pt" ] = &pi0_cl2_pt;
      fHandles[ "pi0_cl2_eta" ] = &pi0_cl2_eta;
      fHandles[ "pi0_cl2_phi" ] = &pi0_cl2_phi;
      fHandles[ "pi0_vistau_pt" ] = &pi0_vistau_pt;
      fHandles[ "pi0_vistau_eta" ] = &pi0_vistau_eta;
      fHandles[ "pi0_vistau_phi" ] = &pi0_vistau_phi;
      fHandles[ "pi0_vistau_m" ] = &pi0_vistau_m;
      fHandles[ "pi0_n" ] = &pi0_n;
      fHandles[ "pantau_isPanTauCandidate" ] = &pantau_isPanTauCandidate;
      fHandles[ "pantau_PanTauScore" ] = &pantau_PanTauScore;
      fHandles[ "pantau_NChargedEFO" ] = &pantau_NChargedEFO;
      fHandles[ "pantau_NChargedQualifiedEFO" ] = &pantau_NChargedQualifiedEFO;
      fHandles[ "pantau_NNeutralEFO" ] = &pantau_NNeutralEFO;
      fHandles[ "pantau_AbsSumCharge" ] = &pantau_AbsSumCharge;
      fHandles[ "pantau_EflowJetMomentDRAll" ] = &pantau_EflowJetMomentDRAll;
      fHandles[ "pantau_EflowJetMomentDRChrg" ] = &pantau_EflowJetMomentDRChrg;
      fHandles[ "pantau_EflowJetMomentDREMNeut" ] = &pantau_EflowJetMomentDREMNeut;
      fHandles[ "pantau_EflowJetMomentDRHADNeut" ] = &pantau_EflowJetMomentDRHADNeut;
      fHandles[ "pantau_EtIn01OverEtIn02InvSigm" ] = &pantau_EtIn01OverEtIn02InvSigm;
      fHandles[ "pantau_EtIn02To04OverTotalEtInvSigm" ] = &pantau_EtIn02To04OverTotalEtInvSigm;
      fHandles[ "pantau_EtIn01OverEtIn04InvSigm" ] = &pantau_EtIn01OverEtIn04InvSigm;
      fHandles[ "pantau_EtIn01OverEtIn04" ] = &pantau_EtIn01OverEtIn04;
      fHandles[ "pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents" ] = &pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents;
      fHandles[ "pantau_JetSphericity" ] = &pantau_JetSphericity;
      fHandles[ "pantau_TransImpactParamSignfTrack1" ] = &pantau_TransImpactParamSignfTrack1;
      fHandles[ "pantau_EflowAngleJetAxisLeadingChargedQualified" ] = &pantau_EflowAngleJetAxisLeadingChargedQualified;
      fHandles[ "pantau_EflowAngleChargedAxisNeutralAxis" ] = &pantau_EflowAngleChargedAxisNeutralAxis;
      fHandles[ "pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified" ] = &pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified;
      fHandles[ "pantau_EflowInvariantMassAll" ] = &pantau_EflowInvariantMassAll;
      fHandles[ "pantau_EflowStdDevEtToSumEt" ] = &pantau_EflowStdDevEtToSumEt;
      fHandles[ "pantau_EflowEtLeadingChrgQualifiedOverTotalEt" ] = &pantau_EflowEtLeadingChrgQualifiedOverTotalEt;
      fHandles[ "pantau_EflowSumEAll" ] = &pantau_EflowSumEAll;
      fHandles[ "pantau_EflowChargedSumEt" ] = &pantau_EflowChargedSumEt;
      fHandles[ "leadTrack_eta" ] = &leadTrack_eta;
      fHandles[ "leadTrack_phi" ] = &leadTrack_phi;
      fHandles[ "cluster_E" ] = &cluster_E;
      fHandles[ "cluster_eta" ] = &cluster_eta;
      fHandles[ "cluster_phi" ] = &cluster_phi;
      fHandles[ "cluster_eta_atTJVA" ] = &cluster_eta_atTJVA;
      fHandles[ "cluster_phi_atTJVA" ] = &cluster_phi_atTJVA;
      fHandles[ "cluster_PreSamplerStripF" ] = &cluster_PreSamplerStripF;
      fHandles[ "cluster_EMLayer2F" ] = &cluster_EMLayer2F;
      fHandles[ "cluster_EMLayer3F" ] = &cluster_EMLayer3F;
      fHandles[ "cluster_n" ] = &cluster_n;
      fHandles[ "Pi0Cluster_pt" ] = &Pi0Cluster_pt;
      fHandles[ "Pi0Cluster_eta" ] = &Pi0Cluster_eta;
      fHandles[ "Pi0Cluster_phi" ] = &Pi0Cluster_phi;
      fHandles[ "secvtx_x" ] = &secvtx_x;
      fHandles[ "secvtx_y" ] = &secvtx_y;
      fHandles[ "secvtx_z" ] = &secvtx_z;
      fHandles[ "secvtx_xx" ] = &secvtx_xx;
      fHandles[ "secvtx_yy" ] = &secvtx_yy;
      fHandles[ "secvtx_zz" ] = &secvtx_zz;
      fHandles[ "secvtx_xy" ] = &secvtx_xy;
      fHandles[ "secvtx_yz" ] = &secvtx_yz;
      fHandles[ "secvtx_zx" ] = &secvtx_zx;
      fHandles[ "secvtx_chiSquared" ] = &secvtx_chiSquared;
      fHandles[ "secvtx_numberDoF" ] = &secvtx_numberDoF;
      fHandles[ "privtx_x" ] = &privtx_x;
      fHandles[ "privtx_y" ] = &privtx_y;
      fHandles[ "privtx_z" ] = &privtx_z;
      fHandles[ "privtx_xx" ] = &privtx_xx;
      fHandles[ "privtx_yy" ] = &privtx_yy;
      fHandles[ "privtx_zz" ] = &privtx_zz;
      fHandles[ "privtx_xy" ] = &privtx_xy;
      fHandles[ "privtx_yz" ] = &privtx_yz;
      fHandles[ "privtx_zx" ] = &privtx_zx;
      fHandles[ "privtx_chiSquared" ] = &privtx_chiSquared;
      fHandles[ "privtx_numberDoF" ] = &privtx_numberDoF;
      fHandles[ "privtx_jvf" ] = &privtx_jvf;
      fHandles[ "jet_Et" ] = &jet_Et;
      fHandles[ "jet_pt" ] = &jet_pt;
      fHandles[ "jet_m" ] = &jet_m;
      fHandles[ "jet_eta" ] = &jet_eta;
      fHandles[ "jet_phi" ] = &jet_phi;
      fHandles[ "jet_WIDTH" ] = &jet_WIDTH;
      fHandles[ "jet_n90" ] = &jet_n90;
      fHandles[ "jet_n90constituents" ] = &jet_n90constituents;
      fHandles[ "jet_BCH_CORR_CELL" ] = &jet_BCH_CORR_CELL;
      fHandles[ "jet_BCH_CORR_JET" ] = &jet_BCH_CORR_JET;
      fHandles[ "jet_BCH_CORR_JET_FORCELL" ] = &jet_BCH_CORR_JET_FORCELL;
      fHandles[ "jet_ENG_BAD_CELLS" ] = &jet_ENG_BAD_CELLS;
      fHandles[ "jet_N_BAD_CELLS" ] = &jet_N_BAD_CELLS;
      fHandles[ "jet_N_BAD_CELLS_CORR" ] = &jet_N_BAD_CELLS_CORR;
      fHandles[ "jet_BAD_CELLS_CORR_E" ] = &jet_BAD_CELLS_CORR_E;
      fHandles[ "jet_Timing" ] = &jet_Timing;
      fHandles[ "jet_LArQuality" ] = &jet_LArQuality;
      fHandles[ "jet_nTrk" ] = &jet_nTrk;
      fHandles[ "jet_sumPtTrk" ] = &jet_sumPtTrk;
      fHandles[ "jet_OriginIndex" ] = &jet_OriginIndex;
      fHandles[ "jet_HECQuality" ] = &jet_HECQuality;
      fHandles[ "jet_NegativeE" ] = &jet_NegativeE;
      fHandles[ "jet_YFlip12" ] = &jet_YFlip12;
      fHandles[ "jet_YFlip23" ] = &jet_YFlip23;
      fHandles[ "jet_BCH_CORR_DOTX" ] = &jet_BCH_CORR_DOTX;
      fHandles[ "jet_SamplingMax" ] = &jet_SamplingMax;
      fHandles[ "jet_fracSamplingMax" ] = &jet_fracSamplingMax;
      fHandles[ "jet_hecf" ] = &jet_hecf;
      fHandles[ "jet_tgap3f" ] = &jet_tgap3f;
      fHandles[ "jet_isUgly" ] = &jet_isUgly;
      fHandles[ "jet_isBadLooseMinus" ] = &jet_isBadLooseMinus;
      fHandles[ "jet_isBadLoose" ] = &jet_isBadLoose;
      fHandles[ "jet_isBadMedium" ] = &jet_isBadMedium;
      fHandles[ "jet_isBadTight" ] = &jet_isBadTight;
      fHandles[ "jet_emfrac" ] = &jet_emfrac;
      fHandles[ "jet_GCWJES" ] = &jet_GCWJES;
      fHandles[ "jet_EMJES" ] = &jet_EMJES;
      fHandles[ "jet_emscale_E" ] = &jet_emscale_E;
      fHandles[ "jet_emscale_pt" ] = &jet_emscale_pt;
      fHandles[ "jet_emscale_m" ] = &jet_emscale_m;
      fHandles[ "jet_emscale_eta" ] = &jet_emscale_eta;
      fHandles[ "jet_emscale_phi" ] = &jet_emscale_phi;
      fHandles[ "jet_jvtx_x" ] = &jet_jvtx_x;
      fHandles[ "jet_jvtx_y" ] = &jet_jvtx_y;
      fHandles[ "jet_jvtx_z" ] = &jet_jvtx_z;
      fHandles[ "jet_jvtxf" ] = &jet_jvtxf;
      fHandles[ "jet_flavor_weight" ] = &jet_flavor_weight;
      fHandles[ "jet_flavor_weight_TrackCounting2D" ] = &jet_flavor_weight_TrackCounting2D;
      fHandles[ "jet_flavor_weight_JetProb" ] = &jet_flavor_weight_JetProb;
      fHandles[ "jet_flavor_weight_IP1D" ] = &jet_flavor_weight_IP1D;
      fHandles[ "jet_flavor_weight_IP2D" ] = &jet_flavor_weight_IP2D;
      fHandles[ "jet_flavor_weight_IP3D" ] = &jet_flavor_weight_IP3D;
      fHandles[ "jet_flavor_weight_SV0" ] = &jet_flavor_weight_SV0;
      fHandles[ "jet_flavor_weight_SV1" ] = &jet_flavor_weight_SV1;
      fHandles[ "jet_flavor_weight_SV2" ] = &jet_flavor_weight_SV2;
      fHandles[ "jet_flavor_weight_JetFitterTag" ] = &jet_flavor_weight_JetFitterTag;
      fHandles[ "jet_flavor_weight_JetFitterCOMB" ] = &jet_flavor_weight_JetFitterCOMB;
      fHandles[ "jet_flavor_weight_JetFitterTagNN" ] = &jet_flavor_weight_JetFitterTagNN;
      fHandles[ "jet_flavor_weight_JetFitterCOMBNN" ] = &jet_flavor_weight_JetFitterCOMBNN;
      fHandles[ "jet_flavor_weight_SoftMuonTag" ] = &jet_flavor_weight_SoftMuonTag;
      fHandles[ "jet_flavor_weight_SoftElectronTag" ] = &jet_flavor_weight_SoftElectronTag;
      fHandles[ "jet_flavor_weight_IP3DSV1" ] = &jet_flavor_weight_IP3DSV1;
      fHandles[ "jet_e_PreSamplerB" ] = &jet_e_PreSamplerB;
      fHandles[ "jet_e_EMB1" ] = &jet_e_EMB1;
      fHandles[ "jet_e_EMB2" ] = &jet_e_EMB2;
      fHandles[ "jet_e_EMB3" ] = &jet_e_EMB3;
      fHandles[ "jet_e_PreSamplerE" ] = &jet_e_PreSamplerE;
      fHandles[ "jet_e_EME1" ] = &jet_e_EME1;
      fHandles[ "jet_e_EME2" ] = &jet_e_EME2;
      fHandles[ "jet_e_EME3" ] = &jet_e_EME3;
      fHandles[ "jet_e_HEC0" ] = &jet_e_HEC0;
      fHandles[ "jet_e_HEC1" ] = &jet_e_HEC1;
      fHandles[ "jet_e_HEC2" ] = &jet_e_HEC2;
      fHandles[ "jet_e_HEC3" ] = &jet_e_HEC3;
      fHandles[ "jet_e_TileBar0" ] = &jet_e_TileBar0;
      fHandles[ "jet_e_TileBar1" ] = &jet_e_TileBar1;
      fHandles[ "jet_e_TileBar2" ] = &jet_e_TileBar2;
      fHandles[ "jet_e_TileGap1" ] = &jet_e_TileGap1;
      fHandles[ "jet_e_TileGap2" ] = &jet_e_TileGap2;
      fHandles[ "jet_e_TileGap3" ] = &jet_e_TileGap3;
      fHandles[ "jet_e_TileExt0" ] = &jet_e_TileExt0;
      fHandles[ "jet_e_TileExt1" ] = &jet_e_TileExt1;
      fHandles[ "jet_e_TileExt2" ] = &jet_e_TileExt2;
      fHandles[ "jet_e_FCAL0" ] = &jet_e_FCAL0;
      fHandles[ "jet_e_FCAL1" ] = &jet_e_FCAL1;
      fHandles[ "jet_e_FCAL2" ] = &jet_e_FCAL2;
      fHandles[ "jet_shapeBins" ] = &jet_shapeBins;
      fHandles[ "track_atTJVA_n" ] = &track_atTJVA_n;
      fHandles[ "track_atTJVA_d0" ] = &track_atTJVA_d0;
      fHandles[ "track_atTJVA_z0" ] = &track_atTJVA_z0;
      fHandles[ "track_atTJVA_phi" ] = &track_atTJVA_phi;
      fHandles[ "track_atTJVA_theta" ] = &track_atTJVA_theta;
      fHandles[ "track_atTJVA_qoverp" ] = &track_atTJVA_qoverp;
      fHandles[ "track_atTJVA_pt" ] = &track_atTJVA_pt;
      fHandles[ "track_atTJVA_eta" ] = &track_atTJVA_eta;
      fHandles[ "seedCalo_wideTrk_atTJVA_n" ] = &seedCalo_wideTrk_atTJVA_n;
      fHandles[ "seedCalo_wideTrk_atTJVA_d0" ] = &seedCalo_wideTrk_atTJVA_d0;
      fHandles[ "seedCalo_wideTrk_atTJVA_z0" ] = &seedCalo_wideTrk_atTJVA_z0;
      fHandles[ "seedCalo_wideTrk_atTJVA_phi" ] = &seedCalo_wideTrk_atTJVA_phi;
      fHandles[ "seedCalo_wideTrk_atTJVA_theta" ] = &seedCalo_wideTrk_atTJVA_theta;
      fHandles[ "seedCalo_wideTrk_atTJVA_qoverp" ] = &seedCalo_wideTrk_atTJVA_qoverp;
      fHandles[ "seedCalo_wideTrk_atTJVA_pt" ] = &seedCalo_wideTrk_atTJVA_pt;
      fHandles[ "seedCalo_wideTrk_atTJVA_eta" ] = &seedCalo_wideTrk_atTJVA_eta;
      fHandles[ "otherTrk_atTJVA_n" ] = &otherTrk_atTJVA_n;
      fHandles[ "track_n" ] = &track_n;
      fHandles[ "track_d0" ] = &track_d0;
      fHandles[ "track_z0" ] = &track_z0;
      fHandles[ "track_phi" ] = &track_phi;
      fHandles[ "track_theta" ] = &track_theta;
      fHandles[ "track_qoverp" ] = &track_qoverp;
      fHandles[ "track_pt" ] = &track_pt;
      fHandles[ "track_eta" ] = &track_eta;
      fHandles[ "track_atPV_d0" ] = &track_atPV_d0;
      fHandles[ "track_atPV_z0" ] = &track_atPV_z0;
      fHandles[ "track_atPV_phi" ] = &track_atPV_phi;
      fHandles[ "track_atPV_theta" ] = &track_atPV_theta;
      fHandles[ "track_atPV_qoverp" ] = &track_atPV_qoverp;
      fHandles[ "track_atPV_pt" ] = &track_atPV_pt;
      fHandles[ "track_atPV_eta" ] = &track_atPV_eta;
      fHandles[ "track_nBLHits" ] = &track_nBLHits;
      fHandles[ "track_nPixHits" ] = &track_nPixHits;
      fHandles[ "track_nSCTHits" ] = &track_nSCTHits;
      fHandles[ "track_nTRTHits" ] = &track_nTRTHits;
      fHandles[ "track_nTRTHighTHits" ] = &track_nTRTHighTHits;
      fHandles[ "track_nTRTXenonHits" ] = &track_nTRTXenonHits;
      fHandles[ "track_nPixHoles" ] = &track_nPixHoles;
      fHandles[ "track_nSCTHoles" ] = &track_nSCTHoles;
      fHandles[ "track_nTRTHoles" ] = &track_nTRTHoles;
      fHandles[ "track_nPixelDeadSensors" ] = &track_nPixelDeadSensors;
      fHandles[ "track_nSCTDeadSensors" ] = &track_nSCTDeadSensors;
      fHandles[ "track_nBLSharedHits" ] = &track_nBLSharedHits;
      fHandles[ "track_nPixSharedHits" ] = &track_nPixSharedHits;
      fHandles[ "track_nSCTSharedHits" ] = &track_nSCTSharedHits;
      fHandles[ "track_nBLayerSplitHits" ] = &track_nBLayerSplitHits;
      fHandles[ "track_nPixSplitHits" ] = &track_nPixSplitHits;
      fHandles[ "track_nBLayerOutliers" ] = &track_nBLayerOutliers;
      fHandles[ "track_nPixelOutliers" ] = &track_nPixelOutliers;
      fHandles[ "track_nSCTOutliers" ] = &track_nSCTOutliers;
      fHandles[ "track_nTRTOutliers" ] = &track_nTRTOutliers;
      fHandles[ "track_nTRTHighTOutliers" ] = &track_nTRTHighTOutliers;
      fHandles[ "track_nContribPixelLayers" ] = &track_nContribPixelLayers;
      fHandles[ "track_nGangedPixels" ] = &track_nGangedPixels;
      fHandles[ "track_nGangedFlaggedFakes" ] = &track_nGangedFlaggedFakes;
      fHandles[ "track_nPixelSpoiltHits" ] = &track_nPixelSpoiltHits;
      fHandles[ "track_nSCTDoubleHoles" ] = &track_nSCTDoubleHoles;
      fHandles[ "track_nSCTSpoiltHits" ] = &track_nSCTSpoiltHits;
      fHandles[ "track_expectBLayerHit" ] = &track_expectBLayerHit;
      fHandles[ "track_nHits" ] = &track_nHits;
      fHandles[ "track_TRTHighTHitsRatio" ] = &track_TRTHighTHitsRatio;
      fHandles[ "track_TRTHighTOutliersRatio" ] = &track_TRTHighTOutliersRatio;
      fHandles[ "seedCalo_track_n" ] = &seedCalo_track_n;
      fHandles[ "seedCalo_wideTrk_n" ] = &seedCalo_wideTrk_n;
      fHandles[ "seedCalo_wideTrk_nBLHits" ] = &seedCalo_wideTrk_nBLHits;
      fHandles[ "seedCalo_wideTrk_nPixHits" ] = &seedCalo_wideTrk_nPixHits;
      fHandles[ "seedCalo_wideTrk_nSCTHits" ] = &seedCalo_wideTrk_nSCTHits;
      fHandles[ "seedCalo_wideTrk_nTRTHits" ] = &seedCalo_wideTrk_nTRTHits;
      fHandles[ "seedCalo_wideTrk_nTRTHighTHits" ] = &seedCalo_wideTrk_nTRTHighTHits;
      fHandles[ "seedCalo_wideTrk_nTRTXenonHits" ] = &seedCalo_wideTrk_nTRTXenonHits;
      fHandles[ "seedCalo_wideTrk_nPixHoles" ] = &seedCalo_wideTrk_nPixHoles;
      fHandles[ "seedCalo_wideTrk_nSCTHoles" ] = &seedCalo_wideTrk_nSCTHoles;
      fHandles[ "seedCalo_wideTrk_nTRTHoles" ] = &seedCalo_wideTrk_nTRTHoles;
      fHandles[ "seedCalo_wideTrk_nPixelDeadSensors" ] = &seedCalo_wideTrk_nPixelDeadSensors;
      fHandles[ "seedCalo_wideTrk_nSCTDeadSensors" ] = &seedCalo_wideTrk_nSCTDeadSensors;
      fHandles[ "seedCalo_wideTrk_nBLSharedHits" ] = &seedCalo_wideTrk_nBLSharedHits;
      fHandles[ "seedCalo_wideTrk_nPixSharedHits" ] = &seedCalo_wideTrk_nPixSharedHits;
      fHandles[ "seedCalo_wideTrk_nSCTSharedHits" ] = &seedCalo_wideTrk_nSCTSharedHits;
      fHandles[ "seedCalo_wideTrk_nBLayerSplitHits" ] = &seedCalo_wideTrk_nBLayerSplitHits;
      fHandles[ "seedCalo_wideTrk_nPixSplitHits" ] = &seedCalo_wideTrk_nPixSplitHits;
      fHandles[ "seedCalo_wideTrk_nBLayerOutliers" ] = &seedCalo_wideTrk_nBLayerOutliers;
      fHandles[ "seedCalo_wideTrk_nPixelOutliers" ] = &seedCalo_wideTrk_nPixelOutliers;
      fHandles[ "seedCalo_wideTrk_nSCTOutliers" ] = &seedCalo_wideTrk_nSCTOutliers;
      fHandles[ "seedCalo_wideTrk_nTRTOutliers" ] = &seedCalo_wideTrk_nTRTOutliers;
      fHandles[ "seedCalo_wideTrk_nTRTHighTOutliers" ] = &seedCalo_wideTrk_nTRTHighTOutliers;
      fHandles[ "seedCalo_wideTrk_nContribPixelLayers" ] = &seedCalo_wideTrk_nContribPixelLayers;
      fHandles[ "seedCalo_wideTrk_nGangedPixels" ] = &seedCalo_wideTrk_nGangedPixels;
      fHandles[ "seedCalo_wideTrk_nGangedFlaggedFakes" ] = &seedCalo_wideTrk_nGangedFlaggedFakes;
      fHandles[ "seedCalo_wideTrk_nPixelSpoiltHits" ] = &seedCalo_wideTrk_nPixelSpoiltHits;
      fHandles[ "seedCalo_wideTrk_nSCTDoubleHoles" ] = &seedCalo_wideTrk_nSCTDoubleHoles;
      fHandles[ "seedCalo_wideTrk_nSCTSpoiltHits" ] = &seedCalo_wideTrk_nSCTSpoiltHits;
      fHandles[ "seedCalo_wideTrk_expectBLayerHit" ] = &seedCalo_wideTrk_expectBLayerHit;
      fHandles[ "seedCalo_wideTrk_nHits" ] = &seedCalo_wideTrk_nHits;
      fHandles[ "otherTrk_n" ] = &otherTrk_n;
      fHandles[ "EF_dr" ] = &EF_dr;
      fHandles[ "EF_E" ] = &EF_E;
      fHandles[ "EF_Et" ] = &EF_Et;
      fHandles[ "EF_pt" ] = &EF_pt;
      fHandles[ "EF_eta" ] = &EF_eta;
      fHandles[ "EF_phi" ] = &EF_phi;
      fHandles[ "EF_matched" ] = &EF_matched;
      fHandles[ "L2_dr" ] = &L2_dr;
      fHandles[ "L2_E" ] = &L2_E;
      fHandles[ "L2_Et" ] = &L2_Et;
      fHandles[ "L2_pt" ] = &L2_pt;
      fHandles[ "L2_eta" ] = &L2_eta;
      fHandles[ "L2_phi" ] = &L2_phi;
      fHandles[ "L2_matched" ] = &L2_matched;
      fHandles[ "L1_dr" ] = &L1_dr;
      fHandles[ "L1_Et" ] = &L1_Et;
      fHandles[ "L1_pt" ] = &L1_pt;
      fHandles[ "L1_eta" ] = &L1_eta;
      fHandles[ "L1_phi" ] = &L1_phi;
      fHandles[ "L1_matched" ] = &L1_matched;
if (!is_data) {
      fHandles[ "trueTauAssocSmall_dr" ] = &trueTauAssocSmall_dr;
      fHandles[ "trueTauAssocSmall_index" ] = &trueTauAssocSmall_index;
      fHandles[ "trueTauAssocSmall_matched" ] = &trueTauAssocSmall_matched;
} // end !is_data
      fHandles[ "MET_Egamma10LooseTau_wpx" ] = &MET_Egamma10LooseTau_wpx;
      fHandles[ "MET_Egamma10LooseTau_wpy" ] = &MET_Egamma10LooseTau_wpy;
      fHandles[ "MET_Egamma10LooseTau_wet" ] = &MET_Egamma10LooseTau_wet;
      fHandles[ "MET_Egamma10LooseTau_statusWord" ] = &MET_Egamma10LooseTau_statusWord;
      fHandles[ "MET_wpx" ] = &MET_wpx;
      fHandles[ "MET_wpy" ] = &MET_wpy;
      fHandles[ "MET_wet" ] = &MET_wet;
      fHandles[ "MET_statusWord" ] = &MET_statusWord;
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   TauD3PDObject::TauD3PDObject( const char* prefix , bool is_data )
      : TObject(),
        n( this, ::TString( prefix ) + "n", 0 ),
        Et( this, ::TString( prefix ) + "Et", 0 ),
        pt( this, ::TString( prefix ) + "pt", 0 ),
        m( this, ::TString( prefix ) + "m", 0 ),
        eta( this, ::TString( prefix ) + "eta", 0 ),
        phi( this, ::TString( prefix ) + "phi", 0 ),
        charge( this, ::TString( prefix ) + "charge", 0 ),
        BDTEleScore( this, ::TString( prefix ) + "BDTEleScore", 0 ),
        BDTJetScore( this, ::TString( prefix ) + "BDTJetScore", 0 ),
        likelihood( this, ::TString( prefix ) + "likelihood", 0 ),
        SafeLikelihood( this, ::TString( prefix ) + "SafeLikelihood", 0 ),
        electronVetoLoose( this, ::TString( prefix ) + "electronVetoLoose", 0 ),
        electronVetoMedium( this, ::TString( prefix ) + "electronVetoMedium", 0 ),
        electronVetoTight( this, ::TString( prefix ) + "electronVetoTight", 0 ),
        muonVeto( this, ::TString( prefix ) + "muonVeto", 0 ),
        tauLlhLoose( this, ::TString( prefix ) + "tauLlhLoose", 0 ),
        tauLlhMedium( this, ::TString( prefix ) + "tauLlhMedium", 0 ),
        tauLlhTight( this, ::TString( prefix ) + "tauLlhTight", 0 ),
        JetBDTSigLoose( this, ::TString( prefix ) + "JetBDTSigLoose", 0 ),
        JetBDTSigMedium( this, ::TString( prefix ) + "JetBDTSigMedium", 0 ),
        JetBDTSigTight( this, ::TString( prefix ) + "JetBDTSigTight", 0 ),
        EleBDTLoose( this, ::TString( prefix ) + "EleBDTLoose", 0 ),
        EleBDTMedium( this, ::TString( prefix ) + "EleBDTMedium", 0 ),
        EleBDTTight( this, ::TString( prefix ) + "EleBDTTight", 0 ),
        author( this, ::TString( prefix ) + "author", 0 ),
        RoIWord( this, ::TString( prefix ) + "RoIWord", 0 ),
        nProng( this, ::TString( prefix ) + "nProng", 0 ),
        numTrack( this, ::TString( prefix ) + "numTrack", 0 ),
        seedCalo_numTrack( this, ::TString( prefix ) + "seedCalo_numTrack", 0 ),
        seedCalo_nWideTrk( this, ::TString( prefix ) + "seedCalo_nWideTrk", 0 ),
        nOtherTrk( this, ::TString( prefix ) + "nOtherTrk", 0 ),
        etOverPtLeadTrk( this, ::TString( prefix ) + "etOverPtLeadTrk", 0 ),
        ipZ0SinThetaSigLeadTrk( this, ::TString( prefix ) + "ipZ0SinThetaSigLeadTrk", 0 ),
        leadTrkPt( this, ::TString( prefix ) + "leadTrkPt", 0 ),
        nLooseTrk( this, ::TString( prefix ) + "nLooseTrk", 0 ),
        nLooseConvTrk( this, ::TString( prefix ) + "nLooseConvTrk", 0 ),
        nProngLoose( this, ::TString( prefix ) + "nProngLoose", 0 ),
        ipSigLeadTrk( this, ::TString( prefix ) + "ipSigLeadTrk", 0 ),
        ipSigLeadLooseTrk( this, ::TString( prefix ) + "ipSigLeadLooseTrk", 0 ),
        etOverPtLeadLooseTrk( this, ::TString( prefix ) + "etOverPtLeadLooseTrk", 0 ),
        leadLooseTrkPt( this, ::TString( prefix ) + "leadLooseTrkPt", 0 ),
        chrgLooseTrk( this, ::TString( prefix ) + "chrgLooseTrk", 0 ),
        massTrkSys( this, ::TString( prefix ) + "massTrkSys", 0 ),
        trkWidth2( this, ::TString( prefix ) + "trkWidth2", 0 ),
        trFlightPathSig( this, ::TString( prefix ) + "trFlightPathSig", 0 ),
        etEflow( this, ::TString( prefix ) + "etEflow", 0 ),
        mEflow( this, ::TString( prefix ) + "mEflow", 0 ),
        nPi0( this, ::TString( prefix ) + "nPi0", 0 ),
        ele_E237E277( this, ::TString( prefix ) + "ele_E237E277", 0 ),
        ele_PresamplerFraction( this, ::TString( prefix ) + "ele_PresamplerFraction", 0 ),
        ele_ECALFirstFraction( this, ::TString( prefix ) + "ele_ECALFirstFraction", 0 ),
        EM_TES_scale( this, ::TString( prefix ) + "EM_TES_scale", 0 ),
        LC_TES_precalib( this, ::TString( prefix ) + "LC_TES_precalib", 0 ),
        TRTHTOverLT_LeadTrk( this, ::TString( prefix ) + "TRTHTOverLT_LeadTrk", 0 ),
        seedCalo_EMRadius( this, ::TString( prefix ) + "seedCalo_EMRadius", 0 ),
        seedCalo_hadRadius( this, ::TString( prefix ) + "seedCalo_hadRadius", 0 ),
        seedCalo_etEMAtEMScale( this, ::TString( prefix ) + "seedCalo_etEMAtEMScale", 0 ),
        seedCalo_etHadAtEMScale( this, ::TString( prefix ) + "seedCalo_etHadAtEMScale", 0 ),
        seedCalo_isolFrac( this, ::TString( prefix ) + "seedCalo_isolFrac", 0 ),
        seedCalo_centFrac( this, ::TString( prefix ) + "seedCalo_centFrac", 0 ),
        seedCalo_stripWidth2( this, ::TString( prefix ) + "seedCalo_stripWidth2", 0 ),
        seedCalo_nStrip( this, ::TString( prefix ) + "seedCalo_nStrip", 0 ),
        seedCalo_eta( this, ::TString( prefix ) + "seedCalo_eta", 0 ),
        seedCalo_phi( this, ::TString( prefix ) + "seedCalo_phi", 0 ),
        seedCalo_nIsolLooseTrk( this, ::TString( prefix ) + "seedCalo_nIsolLooseTrk", 0 ),
        seedCalo_trkAvgDist( this, ::TString( prefix ) + "seedCalo_trkAvgDist", 0 ),
        seedCalo_trkRmsDist( this, ::TString( prefix ) + "seedCalo_trkRmsDist", 0 ),
        seedCalo_caloIso( this, ::TString( prefix ) + "seedCalo_caloIso", 0 ),
        seedCalo_caloIsoCorrected( this, ::TString( prefix ) + "seedCalo_caloIsoCorrected", 0 ),
        seedCalo_dRmax( this, ::TString( prefix ) + "seedCalo_dRmax", 0 ),
        seedCalo_lead2ClusterEOverAllClusterE( this, ::TString( prefix ) + "seedCalo_lead2ClusterEOverAllClusterE", 0 ),
        seedCalo_lead3ClusterEOverAllClusterE( this, ::TString( prefix ) + "seedCalo_lead3ClusterEOverAllClusterE", 0 ),
        seedCalo_etHadCalib( this, ::TString( prefix ) + "seedCalo_etHadCalib", 0 ),
        seedCalo_etEMCalib( this, ::TString( prefix ) + "seedCalo_etEMCalib", 0 ),
        numTopoClusters( this, ::TString( prefix ) + "numTopoClusters", 0 ),
        numEffTopoClusters( this, ::TString( prefix ) + "numEffTopoClusters", 0 ),
        topoInvMass( this, ::TString( prefix ) + "topoInvMass", 0 ),
        effTopoInvMass( this, ::TString( prefix ) + "effTopoInvMass", 0 ),
        topoMeanDeltaR( this, ::TString( prefix ) + "topoMeanDeltaR", 0 ),
        effTopoMeanDeltaR( this, ::TString( prefix ) + "effTopoMeanDeltaR", 0 ),
        numCells( this, ::TString( prefix ) + "numCells", 0 ),
        seedTrk_EMRadius( this, ::TString( prefix ) + "seedTrk_EMRadius", 0 ),
        seedTrk_isolFrac( this, ::TString( prefix ) + "seedTrk_isolFrac", 0 ),
        seedTrk_etChrgHadOverSumTrkPt( this, ::TString( prefix ) + "seedTrk_etChrgHadOverSumTrkPt", 0 ),
        seedTrk_isolFracWide( this, ::TString( prefix ) + "seedTrk_isolFracWide", 0 ),
        seedTrk_etHadAtEMScale( this, ::TString( prefix ) + "seedTrk_etHadAtEMScale", 0 ),
        seedTrk_etEMAtEMScale( this, ::TString( prefix ) + "seedTrk_etEMAtEMScale", 0 ),
        seedTrk_etEMCL( this, ::TString( prefix ) + "seedTrk_etEMCL", 0 ),
        seedTrk_etChrgEM( this, ::TString( prefix ) + "seedTrk_etChrgEM", 0 ),
        seedTrk_etNeuEM( this, ::TString( prefix ) + "seedTrk_etNeuEM", 0 ),
        seedTrk_etResNeuEM( this, ::TString( prefix ) + "seedTrk_etResNeuEM", 0 ),
        seedTrk_hadLeakEt( this, ::TString( prefix ) + "seedTrk_hadLeakEt", 0 ),
        seedTrk_sumEMCellEtOverLeadTrkPt( this, ::TString( prefix ) + "seedTrk_sumEMCellEtOverLeadTrkPt", 0 ),
        seedTrk_secMaxStripEt( this, ::TString( prefix ) + "seedTrk_secMaxStripEt", 0 ),
        seedTrk_stripWidth2( this, ::TString( prefix ) + "seedTrk_stripWidth2", 0 ),
        seedTrk_nStrip( this, ::TString( prefix ) + "seedTrk_nStrip", 0 ),
        seedTrk_etChrgHad( this, ::TString( prefix ) + "seedTrk_etChrgHad", 0 ),
        seedTrk_nOtherCoreTrk( this, ::TString( prefix ) + "seedTrk_nOtherCoreTrk", 0 ),
        seedTrk_nIsolTrk( this, ::TString( prefix ) + "seedTrk_nIsolTrk", 0 ),
        seedTrk_etIsolEM( this, ::TString( prefix ) + "seedTrk_etIsolEM", 0 ),
        seedTrk_etIsolHad( this, ::TString( prefix ) + "seedTrk_etIsolHad", 0 ),
        cellBasedEnergyRing1( this, ::TString( prefix ) + "cellBasedEnergyRing1", 0 ),
        cellBasedEnergyRing2( this, ::TString( prefix ) + "cellBasedEnergyRing2", 0 ),
        cellBasedEnergyRing3( this, ::TString( prefix ) + "cellBasedEnergyRing3", 0 ),
        cellBasedEnergyRing4( this, ::TString( prefix ) + "cellBasedEnergyRing4", 0 ),
        cellBasedEnergyRing5( this, ::TString( prefix ) + "cellBasedEnergyRing5", 0 ),
        cellBasedEnergyRing6( this, ::TString( prefix ) + "cellBasedEnergyRing6", 0 ),
        cellBasedEnergyRing7( this, ::TString( prefix ) + "cellBasedEnergyRing7", 0 ),
        calcVars_etHad_EMScale_Pt3Trks( this, ::TString( prefix ) + "calcVars_etHad_EMScale_Pt3Trks", 0 ),
        calcVars_etEM_EMScale_Pt3Trks( this, ::TString( prefix ) + "calcVars_etEM_EMScale_Pt3Trks", 0 ),
        calcVars_ipSigLeadLooseTrk( this, ::TString( prefix ) + "calcVars_ipSigLeadLooseTrk", 0 ),
        calcVars_drMin( this, ::TString( prefix ) + "calcVars_drMin", 0 ),
        calcVars_calRadius( this, ::TString( prefix ) + "calcVars_calRadius", 0 ),
        calcVars_EMFractionAtEMScale( this, ::TString( prefix ) + "calcVars_EMFractionAtEMScale", 0 ),
        calcVars_trackIso( this, ::TString( prefix ) + "calcVars_trackIso", 0 ),
        calcVars_ChPiEMEOverCaloEME( this, ::TString( prefix ) + "calcVars_ChPiEMEOverCaloEME", 0 ),
        calcVars_PSSFraction( this, ::TString( prefix ) + "calcVars_PSSFraction", 0 ),
        calcVars_EMPOverTrkSysP( this, ::TString( prefix ) + "calcVars_EMPOverTrkSysP", 0 ),
        calcVars_pi0BDTPrimaryScore( this, ::TString( prefix ) + "calcVars_pi0BDTPrimaryScore", 0 ),
        calcVars_pi0BDTSecondaryScore( this, ::TString( prefix ) + "calcVars_pi0BDTSecondaryScore", 0 ),
        calcVars_corrCentFrac( this, ::TString( prefix ) + "calcVars_corrCentFrac", 0 ),
        calcVars_corrFTrk( this, ::TString( prefix ) + "calcVars_corrFTrk", 0 ),
        calcVars_interAxis_eta( this, ::TString( prefix ) + "calcVars_interAxis_eta", 0 ),
        calcVars_interAxis_phi( this, ::TString( prefix ) + "calcVars_interAxis_phi", 0 ),
        pi0_cl1_pt( this, ::TString( prefix ) + "pi0_cl1_pt", 0 ),
        pi0_cl1_eta( this, ::TString( prefix ) + "pi0_cl1_eta", 0 ),
        pi0_cl1_phi( this, ::TString( prefix ) + "pi0_cl1_phi", 0 ),
        pi0_cl2_pt( this, ::TString( prefix ) + "pi0_cl2_pt", 0 ),
        pi0_cl2_eta( this, ::TString( prefix ) + "pi0_cl2_eta", 0 ),
        pi0_cl2_phi( this, ::TString( prefix ) + "pi0_cl2_phi", 0 ),
        pi0_vistau_pt( this, ::TString( prefix ) + "pi0_vistau_pt", 0 ),
        pi0_vistau_eta( this, ::TString( prefix ) + "pi0_vistau_eta", 0 ),
        pi0_vistau_phi( this, ::TString( prefix ) + "pi0_vistau_phi", 0 ),
        pi0_vistau_m( this, ::TString( prefix ) + "pi0_vistau_m", 0 ),
        pi0_n( this, ::TString( prefix ) + "pi0_n", 0 ),
        pantau_isPanTauCandidate( this, ::TString( prefix ) + "pantau_isPanTauCandidate", 0 ),
        pantau_PanTauScore( this, ::TString( prefix ) + "pantau_PanTauScore", 0 ),
        pantau_NChargedEFO( this, ::TString( prefix ) + "pantau_NChargedEFO", 0 ),
        pantau_NChargedQualifiedEFO( this, ::TString( prefix ) + "pantau_NChargedQualifiedEFO", 0 ),
        pantau_NNeutralEFO( this, ::TString( prefix ) + "pantau_NNeutralEFO", 0 ),
        pantau_AbsSumCharge( this, ::TString( prefix ) + "pantau_AbsSumCharge", 0 ),
        pantau_EflowJetMomentDRAll( this, ::TString( prefix ) + "pantau_EflowJetMomentDRAll", 0 ),
        pantau_EflowJetMomentDRChrg( this, ::TString( prefix ) + "pantau_EflowJetMomentDRChrg", 0 ),
        pantau_EflowJetMomentDREMNeut( this, ::TString( prefix ) + "pantau_EflowJetMomentDREMNeut", 0 ),
        pantau_EflowJetMomentDRHADNeut( this, ::TString( prefix ) + "pantau_EflowJetMomentDRHADNeut", 0 ),
        pantau_EtIn01OverEtIn02InvSigm( this, ::TString( prefix ) + "pantau_EtIn01OverEtIn02InvSigm", 0 ),
        pantau_EtIn02To04OverTotalEtInvSigm( this, ::TString( prefix ) + "pantau_EtIn02To04OverTotalEtInvSigm", 0 ),
        pantau_EtIn01OverEtIn04InvSigm( this, ::TString( prefix ) + "pantau_EtIn01OverEtIn04InvSigm", 0 ),
        pantau_EtIn01OverEtIn04( this, ::TString( prefix ) + "pantau_EtIn01OverEtIn04", 0 ),
        pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents( this, ::TString( prefix ) + "pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents", 0 ),
        pantau_JetSphericity( this, ::TString( prefix ) + "pantau_JetSphericity", 0 ),
        pantau_TransImpactParamSignfTrack1( this, ::TString( prefix ) + "pantau_TransImpactParamSignfTrack1", 0 ),
        pantau_EflowAngleJetAxisLeadingChargedQualified( this, ::TString( prefix ) + "pantau_EflowAngleJetAxisLeadingChargedQualified", 0 ),
        pantau_EflowAngleChargedAxisNeutralAxis( this, ::TString( prefix ) + "pantau_EflowAngleChargedAxisNeutralAxis", 0 ),
        pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified( this, ::TString( prefix ) + "pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified", 0 ),
        pantau_EflowInvariantMassAll( this, ::TString( prefix ) + "pantau_EflowInvariantMassAll", 0 ),
        pantau_EflowStdDevEtToSumEt( this, ::TString( prefix ) + "pantau_EflowStdDevEtToSumEt", 0 ),
        pantau_EflowEtLeadingChrgQualifiedOverTotalEt( this, ::TString( prefix ) + "pantau_EflowEtLeadingChrgQualifiedOverTotalEt", 0 ),
        pantau_EflowSumEAll( this, ::TString( prefix ) + "pantau_EflowSumEAll", 0 ),
        pantau_EflowChargedSumEt( this, ::TString( prefix ) + "pantau_EflowChargedSumEt", 0 ),
        leadTrack_eta( this, ::TString( prefix ) + "leadTrack_eta", 0 ),
        leadTrack_phi( this, ::TString( prefix ) + "leadTrack_phi", 0 ),
        cluster_E( this, ::TString( prefix ) + "cluster_E", 0 ),
        cluster_eta( this, ::TString( prefix ) + "cluster_eta", 0 ),
        cluster_phi( this, ::TString( prefix ) + "cluster_phi", 0 ),
        cluster_eta_atTJVA( this, ::TString( prefix ) + "cluster_eta_atTJVA", 0 ),
        cluster_phi_atTJVA( this, ::TString( prefix ) + "cluster_phi_atTJVA", 0 ),
        cluster_PreSamplerStripF( this, ::TString( prefix ) + "cluster_PreSamplerStripF", 0 ),
        cluster_EMLayer2F( this, ::TString( prefix ) + "cluster_EMLayer2F", 0 ),
        cluster_EMLayer3F( this, ::TString( prefix ) + "cluster_EMLayer3F", 0 ),
        cluster_n( this, ::TString( prefix ) + "cluster_n", 0 ),
        Pi0Cluster_pt( this, ::TString( prefix ) + "Pi0Cluster_pt", 0 ),
        Pi0Cluster_eta( this, ::TString( prefix ) + "Pi0Cluster_eta", 0 ),
        Pi0Cluster_phi( this, ::TString( prefix ) + "Pi0Cluster_phi", 0 ),
        secvtx_x( this, ::TString( prefix ) + "secvtx_x", 0 ),
        secvtx_y( this, ::TString( prefix ) + "secvtx_y", 0 ),
        secvtx_z( this, ::TString( prefix ) + "secvtx_z", 0 ),
        secvtx_xx( this, ::TString( prefix ) + "secvtx_xx", 0 ),
        secvtx_yy( this, ::TString( prefix ) + "secvtx_yy", 0 ),
        secvtx_zz( this, ::TString( prefix ) + "secvtx_zz", 0 ),
        secvtx_xy( this, ::TString( prefix ) + "secvtx_xy", 0 ),
        secvtx_yz( this, ::TString( prefix ) + "secvtx_yz", 0 ),
        secvtx_zx( this, ::TString( prefix ) + "secvtx_zx", 0 ),
        secvtx_chiSquared( this, ::TString( prefix ) + "secvtx_chiSquared", 0 ),
        secvtx_numberDoF( this, ::TString( prefix ) + "secvtx_numberDoF", 0 ),
        privtx_x( this, ::TString( prefix ) + "privtx_x", 0 ),
        privtx_y( this, ::TString( prefix ) + "privtx_y", 0 ),
        privtx_z( this, ::TString( prefix ) + "privtx_z", 0 ),
        privtx_xx( this, ::TString( prefix ) + "privtx_xx", 0 ),
        privtx_yy( this, ::TString( prefix ) + "privtx_yy", 0 ),
        privtx_zz( this, ::TString( prefix ) + "privtx_zz", 0 ),
        privtx_xy( this, ::TString( prefix ) + "privtx_xy", 0 ),
        privtx_yz( this, ::TString( prefix ) + "privtx_yz", 0 ),
        privtx_zx( this, ::TString( prefix ) + "privtx_zx", 0 ),
        privtx_chiSquared( this, ::TString( prefix ) + "privtx_chiSquared", 0 ),
        privtx_numberDoF( this, ::TString( prefix ) + "privtx_numberDoF", 0 ),
        privtx_jvf( this, ::TString( prefix ) + "privtx_jvf", 0 ),
        jet_Et( this, ::TString( prefix ) + "jet_Et", 0 ),
        jet_pt( this, ::TString( prefix ) + "jet_pt", 0 ),
        jet_m( this, ::TString( prefix ) + "jet_m", 0 ),
        jet_eta( this, ::TString( prefix ) + "jet_eta", 0 ),
        jet_phi( this, ::TString( prefix ) + "jet_phi", 0 ),
        jet_WIDTH( this, ::TString( prefix ) + "jet_WIDTH", 0 ),
        jet_n90( this, ::TString( prefix ) + "jet_n90", 0 ),
        jet_n90constituents( this, ::TString( prefix ) + "jet_n90constituents", 0 ),
        jet_BCH_CORR_CELL( this, ::TString( prefix ) + "jet_BCH_CORR_CELL", 0 ),
        jet_BCH_CORR_JET( this, ::TString( prefix ) + "jet_BCH_CORR_JET", 0 ),
        jet_BCH_CORR_JET_FORCELL( this, ::TString( prefix ) + "jet_BCH_CORR_JET_FORCELL", 0 ),
        jet_ENG_BAD_CELLS( this, ::TString( prefix ) + "jet_ENG_BAD_CELLS", 0 ),
        jet_N_BAD_CELLS( this, ::TString( prefix ) + "jet_N_BAD_CELLS", 0 ),
        jet_N_BAD_CELLS_CORR( this, ::TString( prefix ) + "jet_N_BAD_CELLS_CORR", 0 ),
        jet_BAD_CELLS_CORR_E( this, ::TString( prefix ) + "jet_BAD_CELLS_CORR_E", 0 ),
        jet_Timing( this, ::TString( prefix ) + "jet_Timing", 0 ),
        jet_LArQuality( this, ::TString( prefix ) + "jet_LArQuality", 0 ),
        jet_nTrk( this, ::TString( prefix ) + "jet_nTrk", 0 ),
        jet_sumPtTrk( this, ::TString( prefix ) + "jet_sumPtTrk", 0 ),
        jet_OriginIndex( this, ::TString( prefix ) + "jet_OriginIndex", 0 ),
        jet_HECQuality( this, ::TString( prefix ) + "jet_HECQuality", 0 ),
        jet_NegativeE( this, ::TString( prefix ) + "jet_NegativeE", 0 ),
        jet_YFlip12( this, ::TString( prefix ) + "jet_YFlip12", 0 ),
        jet_YFlip23( this, ::TString( prefix ) + "jet_YFlip23", 0 ),
        jet_BCH_CORR_DOTX( this, ::TString( prefix ) + "jet_BCH_CORR_DOTX", 0 ),
        jet_SamplingMax( this, ::TString( prefix ) + "jet_SamplingMax", 0 ),
        jet_fracSamplingMax( this, ::TString( prefix ) + "jet_fracSamplingMax", 0 ),
        jet_hecf( this, ::TString( prefix ) + "jet_hecf", 0 ),
        jet_tgap3f( this, ::TString( prefix ) + "jet_tgap3f", 0 ),
        jet_isUgly( this, ::TString( prefix ) + "jet_isUgly", 0 ),
        jet_isBadLooseMinus( this, ::TString( prefix ) + "jet_isBadLooseMinus", 0 ),
        jet_isBadLoose( this, ::TString( prefix ) + "jet_isBadLoose", 0 ),
        jet_isBadMedium( this, ::TString( prefix ) + "jet_isBadMedium", 0 ),
        jet_isBadTight( this, ::TString( prefix ) + "jet_isBadTight", 0 ),
        jet_emfrac( this, ::TString( prefix ) + "jet_emfrac", 0 ),
        jet_GCWJES( this, ::TString( prefix ) + "jet_GCWJES", 0 ),
        jet_EMJES( this, ::TString( prefix ) + "jet_EMJES", 0 ),
        jet_emscale_E( this, ::TString( prefix ) + "jet_emscale_E", 0 ),
        jet_emscale_pt( this, ::TString( prefix ) + "jet_emscale_pt", 0 ),
        jet_emscale_m( this, ::TString( prefix ) + "jet_emscale_m", 0 ),
        jet_emscale_eta( this, ::TString( prefix ) + "jet_emscale_eta", 0 ),
        jet_emscale_phi( this, ::TString( prefix ) + "jet_emscale_phi", 0 ),
        jet_jvtx_x( this, ::TString( prefix ) + "jet_jvtx_x", 0 ),
        jet_jvtx_y( this, ::TString( prefix ) + "jet_jvtx_y", 0 ),
        jet_jvtx_z( this, ::TString( prefix ) + "jet_jvtx_z", 0 ),
        jet_jvtxf( this, ::TString( prefix ) + "jet_jvtxf", 0 ),
        jet_flavor_weight( this, ::TString( prefix ) + "jet_flavor_weight", 0 ),
        jet_flavor_weight_TrackCounting2D( this, ::TString( prefix ) + "jet_flavor_weight_TrackCounting2D", 0 ),
        jet_flavor_weight_JetProb( this, ::TString( prefix ) + "jet_flavor_weight_JetProb", 0 ),
        jet_flavor_weight_IP1D( this, ::TString( prefix ) + "jet_flavor_weight_IP1D", 0 ),
        jet_flavor_weight_IP2D( this, ::TString( prefix ) + "jet_flavor_weight_IP2D", 0 ),
        jet_flavor_weight_IP3D( this, ::TString( prefix ) + "jet_flavor_weight_IP3D", 0 ),
        jet_flavor_weight_SV0( this, ::TString( prefix ) + "jet_flavor_weight_SV0", 0 ),
        jet_flavor_weight_SV1( this, ::TString( prefix ) + "jet_flavor_weight_SV1", 0 ),
        jet_flavor_weight_SV2( this, ::TString( prefix ) + "jet_flavor_weight_SV2", 0 ),
        jet_flavor_weight_JetFitterTag( this, ::TString( prefix ) + "jet_flavor_weight_JetFitterTag", 0 ),
        jet_flavor_weight_JetFitterCOMB( this, ::TString( prefix ) + "jet_flavor_weight_JetFitterCOMB", 0 ),
        jet_flavor_weight_JetFitterTagNN( this, ::TString( prefix ) + "jet_flavor_weight_JetFitterTagNN", 0 ),
        jet_flavor_weight_JetFitterCOMBNN( this, ::TString( prefix ) + "jet_flavor_weight_JetFitterCOMBNN", 0 ),
        jet_flavor_weight_SoftMuonTag( this, ::TString( prefix ) + "jet_flavor_weight_SoftMuonTag", 0 ),
        jet_flavor_weight_SoftElectronTag( this, ::TString( prefix ) + "jet_flavor_weight_SoftElectronTag", 0 ),
        jet_flavor_weight_IP3DSV1( this, ::TString( prefix ) + "jet_flavor_weight_IP3DSV1", 0 ),
        jet_e_PreSamplerB( this, ::TString( prefix ) + "jet_e_PreSamplerB", 0 ),
        jet_e_EMB1( this, ::TString( prefix ) + "jet_e_EMB1", 0 ),
        jet_e_EMB2( this, ::TString( prefix ) + "jet_e_EMB2", 0 ),
        jet_e_EMB3( this, ::TString( prefix ) + "jet_e_EMB3", 0 ),
        jet_e_PreSamplerE( this, ::TString( prefix ) + "jet_e_PreSamplerE", 0 ),
        jet_e_EME1( this, ::TString( prefix ) + "jet_e_EME1", 0 ),
        jet_e_EME2( this, ::TString( prefix ) + "jet_e_EME2", 0 ),
        jet_e_EME3( this, ::TString( prefix ) + "jet_e_EME3", 0 ),
        jet_e_HEC0( this, ::TString( prefix ) + "jet_e_HEC0", 0 ),
        jet_e_HEC1( this, ::TString( prefix ) + "jet_e_HEC1", 0 ),
        jet_e_HEC2( this, ::TString( prefix ) + "jet_e_HEC2", 0 ),
        jet_e_HEC3( this, ::TString( prefix ) + "jet_e_HEC3", 0 ),
        jet_e_TileBar0( this, ::TString( prefix ) + "jet_e_TileBar0", 0 ),
        jet_e_TileBar1( this, ::TString( prefix ) + "jet_e_TileBar1", 0 ),
        jet_e_TileBar2( this, ::TString( prefix ) + "jet_e_TileBar2", 0 ),
        jet_e_TileGap1( this, ::TString( prefix ) + "jet_e_TileGap1", 0 ),
        jet_e_TileGap2( this, ::TString( prefix ) + "jet_e_TileGap2", 0 ),
        jet_e_TileGap3( this, ::TString( prefix ) + "jet_e_TileGap3", 0 ),
        jet_e_TileExt0( this, ::TString( prefix ) + "jet_e_TileExt0", 0 ),
        jet_e_TileExt1( this, ::TString( prefix ) + "jet_e_TileExt1", 0 ),
        jet_e_TileExt2( this, ::TString( prefix ) + "jet_e_TileExt2", 0 ),
        jet_e_FCAL0( this, ::TString( prefix ) + "jet_e_FCAL0", 0 ),
        jet_e_FCAL1( this, ::TString( prefix ) + "jet_e_FCAL1", 0 ),
        jet_e_FCAL2( this, ::TString( prefix ) + "jet_e_FCAL2", 0 ),
        jet_shapeBins( this, ::TString( prefix ) + "jet_shapeBins", 0 ),
        track_atTJVA_n( this, ::TString( prefix ) + "track_atTJVA_n", 0 ),
        track_atTJVA_d0( this, ::TString( prefix ) + "track_atTJVA_d0", 0 ),
        track_atTJVA_z0( this, ::TString( prefix ) + "track_atTJVA_z0", 0 ),
        track_atTJVA_phi( this, ::TString( prefix ) + "track_atTJVA_phi", 0 ),
        track_atTJVA_theta( this, ::TString( prefix ) + "track_atTJVA_theta", 0 ),
        track_atTJVA_qoverp( this, ::TString( prefix ) + "track_atTJVA_qoverp", 0 ),
        track_atTJVA_pt( this, ::TString( prefix ) + "track_atTJVA_pt", 0 ),
        track_atTJVA_eta( this, ::TString( prefix ) + "track_atTJVA_eta", 0 ),
        seedCalo_wideTrk_atTJVA_n( this, ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_n", 0 ),
        seedCalo_wideTrk_atTJVA_d0( this, ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_d0", 0 ),
        seedCalo_wideTrk_atTJVA_z0( this, ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_z0", 0 ),
        seedCalo_wideTrk_atTJVA_phi( this, ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_phi", 0 ),
        seedCalo_wideTrk_atTJVA_theta( this, ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_theta", 0 ),
        seedCalo_wideTrk_atTJVA_qoverp( this, ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_qoverp", 0 ),
        seedCalo_wideTrk_atTJVA_pt( this, ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_pt", 0 ),
        seedCalo_wideTrk_atTJVA_eta( this, ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_eta", 0 ),
        otherTrk_atTJVA_n( this, ::TString( prefix ) + "otherTrk_atTJVA_n", 0 ),
        track_n( this, ::TString( prefix ) + "track_n", 0 ),
        track_d0( this, ::TString( prefix ) + "track_d0", 0 ),
        track_z0( this, ::TString( prefix ) + "track_z0", 0 ),
        track_phi( this, ::TString( prefix ) + "track_phi", 0 ),
        track_theta( this, ::TString( prefix ) + "track_theta", 0 ),
        track_qoverp( this, ::TString( prefix ) + "track_qoverp", 0 ),
        track_pt( this, ::TString( prefix ) + "track_pt", 0 ),
        track_eta( this, ::TString( prefix ) + "track_eta", 0 ),
        track_atPV_d0( this, ::TString( prefix ) + "track_atPV_d0", 0 ),
        track_atPV_z0( this, ::TString( prefix ) + "track_atPV_z0", 0 ),
        track_atPV_phi( this, ::TString( prefix ) + "track_atPV_phi", 0 ),
        track_atPV_theta( this, ::TString( prefix ) + "track_atPV_theta", 0 ),
        track_atPV_qoverp( this, ::TString( prefix ) + "track_atPV_qoverp", 0 ),
        track_atPV_pt( this, ::TString( prefix ) + "track_atPV_pt", 0 ),
        track_atPV_eta( this, ::TString( prefix ) + "track_atPV_eta", 0 ),
        track_nBLHits( this, ::TString( prefix ) + "track_nBLHits", 0 ),
        track_nPixHits( this, ::TString( prefix ) + "track_nPixHits", 0 ),
        track_nSCTHits( this, ::TString( prefix ) + "track_nSCTHits", 0 ),
        track_nTRTHits( this, ::TString( prefix ) + "track_nTRTHits", 0 ),
        track_nTRTHighTHits( this, ::TString( prefix ) + "track_nTRTHighTHits", 0 ),
        track_nTRTXenonHits( this, ::TString( prefix ) + "track_nTRTXenonHits", 0 ),
        track_nPixHoles( this, ::TString( prefix ) + "track_nPixHoles", 0 ),
        track_nSCTHoles( this, ::TString( prefix ) + "track_nSCTHoles", 0 ),
        track_nTRTHoles( this, ::TString( prefix ) + "track_nTRTHoles", 0 ),
        track_nPixelDeadSensors( this, ::TString( prefix ) + "track_nPixelDeadSensors", 0 ),
        track_nSCTDeadSensors( this, ::TString( prefix ) + "track_nSCTDeadSensors", 0 ),
        track_nBLSharedHits( this, ::TString( prefix ) + "track_nBLSharedHits", 0 ),
        track_nPixSharedHits( this, ::TString( prefix ) + "track_nPixSharedHits", 0 ),
        track_nSCTSharedHits( this, ::TString( prefix ) + "track_nSCTSharedHits", 0 ),
        track_nBLayerSplitHits( this, ::TString( prefix ) + "track_nBLayerSplitHits", 0 ),
        track_nPixSplitHits( this, ::TString( prefix ) + "track_nPixSplitHits", 0 ),
        track_nBLayerOutliers( this, ::TString( prefix ) + "track_nBLayerOutliers", 0 ),
        track_nPixelOutliers( this, ::TString( prefix ) + "track_nPixelOutliers", 0 ),
        track_nSCTOutliers( this, ::TString( prefix ) + "track_nSCTOutliers", 0 ),
        track_nTRTOutliers( this, ::TString( prefix ) + "track_nTRTOutliers", 0 ),
        track_nTRTHighTOutliers( this, ::TString( prefix ) + "track_nTRTHighTOutliers", 0 ),
        track_nContribPixelLayers( this, ::TString( prefix ) + "track_nContribPixelLayers", 0 ),
        track_nGangedPixels( this, ::TString( prefix ) + "track_nGangedPixels", 0 ),
        track_nGangedFlaggedFakes( this, ::TString( prefix ) + "track_nGangedFlaggedFakes", 0 ),
        track_nPixelSpoiltHits( this, ::TString( prefix ) + "track_nPixelSpoiltHits", 0 ),
        track_nSCTDoubleHoles( this, ::TString( prefix ) + "track_nSCTDoubleHoles", 0 ),
        track_nSCTSpoiltHits( this, ::TString( prefix ) + "track_nSCTSpoiltHits", 0 ),
        track_expectBLayerHit( this, ::TString( prefix ) + "track_expectBLayerHit", 0 ),
        track_nHits( this, ::TString( prefix ) + "track_nHits", 0 ),
        track_TRTHighTHitsRatio( this, ::TString( prefix ) + "track_TRTHighTHitsRatio", 0 ),
        track_TRTHighTOutliersRatio( this, ::TString( prefix ) + "track_TRTHighTOutliersRatio", 0 ),
        seedCalo_track_n( this, ::TString( prefix ) + "seedCalo_track_n", 0 ),
        seedCalo_wideTrk_n( this, ::TString( prefix ) + "seedCalo_wideTrk_n", 0 ),
        seedCalo_wideTrk_nBLHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nBLHits", 0 ),
        seedCalo_wideTrk_nPixHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nPixHits", 0 ),
        seedCalo_wideTrk_nSCTHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nSCTHits", 0 ),
        seedCalo_wideTrk_nTRTHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nTRTHits", 0 ),
        seedCalo_wideTrk_nTRTHighTHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nTRTHighTHits", 0 ),
        seedCalo_wideTrk_nTRTXenonHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nTRTXenonHits", 0 ),
        seedCalo_wideTrk_nPixHoles( this, ::TString( prefix ) + "seedCalo_wideTrk_nPixHoles", 0 ),
        seedCalo_wideTrk_nSCTHoles( this, ::TString( prefix ) + "seedCalo_wideTrk_nSCTHoles", 0 ),
        seedCalo_wideTrk_nTRTHoles( this, ::TString( prefix ) + "seedCalo_wideTrk_nTRTHoles", 0 ),
        seedCalo_wideTrk_nPixelDeadSensors( this, ::TString( prefix ) + "seedCalo_wideTrk_nPixelDeadSensors", 0 ),
        seedCalo_wideTrk_nSCTDeadSensors( this, ::TString( prefix ) + "seedCalo_wideTrk_nSCTDeadSensors", 0 ),
        seedCalo_wideTrk_nBLSharedHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nBLSharedHits", 0 ),
        seedCalo_wideTrk_nPixSharedHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nPixSharedHits", 0 ),
        seedCalo_wideTrk_nSCTSharedHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nSCTSharedHits", 0 ),
        seedCalo_wideTrk_nBLayerSplitHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nBLayerSplitHits", 0 ),
        seedCalo_wideTrk_nPixSplitHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nPixSplitHits", 0 ),
        seedCalo_wideTrk_nBLayerOutliers( this, ::TString( prefix ) + "seedCalo_wideTrk_nBLayerOutliers", 0 ),
        seedCalo_wideTrk_nPixelOutliers( this, ::TString( prefix ) + "seedCalo_wideTrk_nPixelOutliers", 0 ),
        seedCalo_wideTrk_nSCTOutliers( this, ::TString( prefix ) + "seedCalo_wideTrk_nSCTOutliers", 0 ),
        seedCalo_wideTrk_nTRTOutliers( this, ::TString( prefix ) + "seedCalo_wideTrk_nTRTOutliers", 0 ),
        seedCalo_wideTrk_nTRTHighTOutliers( this, ::TString( prefix ) + "seedCalo_wideTrk_nTRTHighTOutliers", 0 ),
        seedCalo_wideTrk_nContribPixelLayers( this, ::TString( prefix ) + "seedCalo_wideTrk_nContribPixelLayers", 0 ),
        seedCalo_wideTrk_nGangedPixels( this, ::TString( prefix ) + "seedCalo_wideTrk_nGangedPixels", 0 ),
        seedCalo_wideTrk_nGangedFlaggedFakes( this, ::TString( prefix ) + "seedCalo_wideTrk_nGangedFlaggedFakes", 0 ),
        seedCalo_wideTrk_nPixelSpoiltHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nPixelSpoiltHits", 0 ),
        seedCalo_wideTrk_nSCTDoubleHoles( this, ::TString( prefix ) + "seedCalo_wideTrk_nSCTDoubleHoles", 0 ),
        seedCalo_wideTrk_nSCTSpoiltHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nSCTSpoiltHits", 0 ),
        seedCalo_wideTrk_expectBLayerHit( this, ::TString( prefix ) + "seedCalo_wideTrk_expectBLayerHit", 0 ),
        seedCalo_wideTrk_nHits( this, ::TString( prefix ) + "seedCalo_wideTrk_nHits", 0 ),
        otherTrk_n( this, ::TString( prefix ) + "otherTrk_n", 0 ),
        EF_dr( this, ::TString( prefix ) + "EF_dr", 0 ),
        EF_E( this, ::TString( prefix ) + "EF_E", 0 ),
        EF_Et( this, ::TString( prefix ) + "EF_Et", 0 ),
        EF_pt( this, ::TString( prefix ) + "EF_pt", 0 ),
        EF_eta( this, ::TString( prefix ) + "EF_eta", 0 ),
        EF_phi( this, ::TString( prefix ) + "EF_phi", 0 ),
        EF_matched( this, ::TString( prefix ) + "EF_matched", 0 ),
        L2_dr( this, ::TString( prefix ) + "L2_dr", 0 ),
        L2_E( this, ::TString( prefix ) + "L2_E", 0 ),
        L2_Et( this, ::TString( prefix ) + "L2_Et", 0 ),
        L2_pt( this, ::TString( prefix ) + "L2_pt", 0 ),
        L2_eta( this, ::TString( prefix ) + "L2_eta", 0 ),
        L2_phi( this, ::TString( prefix ) + "L2_phi", 0 ),
        L2_matched( this, ::TString( prefix ) + "L2_matched", 0 ),
        L1_dr( this, ::TString( prefix ) + "L1_dr", 0 ),
        L1_Et( this, ::TString( prefix ) + "L1_Et", 0 ),
        L1_pt( this, ::TString( prefix ) + "L1_pt", 0 ),
        L1_eta( this, ::TString( prefix ) + "L1_eta", 0 ),
        L1_phi( this, ::TString( prefix ) + "L1_phi", 0 ),
        L1_matched( this, ::TString( prefix ) + "L1_matched", 0 ),
// MC only
        trueTauAssocSmall_dr( this, ::TString( prefix ) + "trueTauAssocSmall_dr", 0 ),
        trueTauAssocSmall_index( this, ::TString( prefix ) + "trueTauAssocSmall_index", 0 ),
        trueTauAssocSmall_matched( this, ::TString( prefix ) + "trueTauAssocSmall_matched", 0 ),
// end MC only
        MET_Egamma10LooseTau_wpx( this, ::TString( prefix ) + "MET_Egamma10LooseTau_wpx", 0 ),
        MET_Egamma10LooseTau_wpy( this, ::TString( prefix ) + "MET_Egamma10LooseTau_wpy", 0 ),
        MET_Egamma10LooseTau_wet( this, ::TString( prefix ) + "MET_Egamma10LooseTau_wet", 0 ),
        MET_Egamma10LooseTau_statusWord( this, ::TString( prefix ) + "MET_Egamma10LooseTau_statusWord", 0 ),
        MET_wpx( this, ::TString( prefix ) + "MET_wpx", 0 ),
        MET_wpy( this, ::TString( prefix ) + "MET_wpy", 0 ),
        MET_wet( this, ::TString( prefix ) + "MET_wet", 0 ),
        MET_statusWord( this, ::TString( prefix ) + "MET_statusWord", 0 ),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "n" ] = &n;
      fHandles[ "Et" ] = &Et;
      fHandles[ "pt" ] = &pt;
      fHandles[ "m" ] = &m;
      fHandles[ "eta" ] = &eta;
      fHandles[ "phi" ] = &phi;
      fHandles[ "charge" ] = &charge;
      fHandles[ "BDTEleScore" ] = &BDTEleScore;
      fHandles[ "BDTJetScore" ] = &BDTJetScore;
      fHandles[ "likelihood" ] = &likelihood;
      fHandles[ "SafeLikelihood" ] = &SafeLikelihood;
      fHandles[ "electronVetoLoose" ] = &electronVetoLoose;
      fHandles[ "electronVetoMedium" ] = &electronVetoMedium;
      fHandles[ "electronVetoTight" ] = &electronVetoTight;
      fHandles[ "muonVeto" ] = &muonVeto;
      fHandles[ "tauLlhLoose" ] = &tauLlhLoose;
      fHandles[ "tauLlhMedium" ] = &tauLlhMedium;
      fHandles[ "tauLlhTight" ] = &tauLlhTight;
      fHandles[ "JetBDTSigLoose" ] = &JetBDTSigLoose;
      fHandles[ "JetBDTSigMedium" ] = &JetBDTSigMedium;
      fHandles[ "JetBDTSigTight" ] = &JetBDTSigTight;
      fHandles[ "EleBDTLoose" ] = &EleBDTLoose;
      fHandles[ "EleBDTMedium" ] = &EleBDTMedium;
      fHandles[ "EleBDTTight" ] = &EleBDTTight;
      fHandles[ "author" ] = &author;
      fHandles[ "RoIWord" ] = &RoIWord;
      fHandles[ "nProng" ] = &nProng;
      fHandles[ "numTrack" ] = &numTrack;
      fHandles[ "seedCalo_numTrack" ] = &seedCalo_numTrack;
      fHandles[ "seedCalo_nWideTrk" ] = &seedCalo_nWideTrk;
      fHandles[ "nOtherTrk" ] = &nOtherTrk;
      fHandles[ "etOverPtLeadTrk" ] = &etOverPtLeadTrk;
      fHandles[ "ipZ0SinThetaSigLeadTrk" ] = &ipZ0SinThetaSigLeadTrk;
      fHandles[ "leadTrkPt" ] = &leadTrkPt;
      fHandles[ "nLooseTrk" ] = &nLooseTrk;
      fHandles[ "nLooseConvTrk" ] = &nLooseConvTrk;
      fHandles[ "nProngLoose" ] = &nProngLoose;
      fHandles[ "ipSigLeadTrk" ] = &ipSigLeadTrk;
      fHandles[ "ipSigLeadLooseTrk" ] = &ipSigLeadLooseTrk;
      fHandles[ "etOverPtLeadLooseTrk" ] = &etOverPtLeadLooseTrk;
      fHandles[ "leadLooseTrkPt" ] = &leadLooseTrkPt;
      fHandles[ "chrgLooseTrk" ] = &chrgLooseTrk;
      fHandles[ "massTrkSys" ] = &massTrkSys;
      fHandles[ "trkWidth2" ] = &trkWidth2;
      fHandles[ "trFlightPathSig" ] = &trFlightPathSig;
      fHandles[ "etEflow" ] = &etEflow;
      fHandles[ "mEflow" ] = &mEflow;
      fHandles[ "nPi0" ] = &nPi0;
      fHandles[ "ele_E237E277" ] = &ele_E237E277;
      fHandles[ "ele_PresamplerFraction" ] = &ele_PresamplerFraction;
      fHandles[ "ele_ECALFirstFraction" ] = &ele_ECALFirstFraction;
      fHandles[ "EM_TES_scale" ] = &EM_TES_scale;
      fHandles[ "LC_TES_precalib" ] = &LC_TES_precalib;
      fHandles[ "TRTHTOverLT_LeadTrk" ] = &TRTHTOverLT_LeadTrk;
      fHandles[ "seedCalo_EMRadius" ] = &seedCalo_EMRadius;
      fHandles[ "seedCalo_hadRadius" ] = &seedCalo_hadRadius;
      fHandles[ "seedCalo_etEMAtEMScale" ] = &seedCalo_etEMAtEMScale;
      fHandles[ "seedCalo_etHadAtEMScale" ] = &seedCalo_etHadAtEMScale;
      fHandles[ "seedCalo_isolFrac" ] = &seedCalo_isolFrac;
      fHandles[ "seedCalo_centFrac" ] = &seedCalo_centFrac;
      fHandles[ "seedCalo_stripWidth2" ] = &seedCalo_stripWidth2;
      fHandles[ "seedCalo_nStrip" ] = &seedCalo_nStrip;
      fHandles[ "seedCalo_eta" ] = &seedCalo_eta;
      fHandles[ "seedCalo_phi" ] = &seedCalo_phi;
      fHandles[ "seedCalo_nIsolLooseTrk" ] = &seedCalo_nIsolLooseTrk;
      fHandles[ "seedCalo_trkAvgDist" ] = &seedCalo_trkAvgDist;
      fHandles[ "seedCalo_trkRmsDist" ] = &seedCalo_trkRmsDist;
      fHandles[ "seedCalo_caloIso" ] = &seedCalo_caloIso;
      fHandles[ "seedCalo_caloIsoCorrected" ] = &seedCalo_caloIsoCorrected;
      fHandles[ "seedCalo_dRmax" ] = &seedCalo_dRmax;
      fHandles[ "seedCalo_lead2ClusterEOverAllClusterE" ] = &seedCalo_lead2ClusterEOverAllClusterE;
      fHandles[ "seedCalo_lead3ClusterEOverAllClusterE" ] = &seedCalo_lead3ClusterEOverAllClusterE;
      fHandles[ "seedCalo_etHadCalib" ] = &seedCalo_etHadCalib;
      fHandles[ "seedCalo_etEMCalib" ] = &seedCalo_etEMCalib;
      fHandles[ "numTopoClusters" ] = &numTopoClusters;
      fHandles[ "numEffTopoClusters" ] = &numEffTopoClusters;
      fHandles[ "topoInvMass" ] = &topoInvMass;
      fHandles[ "effTopoInvMass" ] = &effTopoInvMass;
      fHandles[ "topoMeanDeltaR" ] = &topoMeanDeltaR;
      fHandles[ "effTopoMeanDeltaR" ] = &effTopoMeanDeltaR;
      fHandles[ "numCells" ] = &numCells;
      fHandles[ "seedTrk_EMRadius" ] = &seedTrk_EMRadius;
      fHandles[ "seedTrk_isolFrac" ] = &seedTrk_isolFrac;
      fHandles[ "seedTrk_etChrgHadOverSumTrkPt" ] = &seedTrk_etChrgHadOverSumTrkPt;
      fHandles[ "seedTrk_isolFracWide" ] = &seedTrk_isolFracWide;
      fHandles[ "seedTrk_etHadAtEMScale" ] = &seedTrk_etHadAtEMScale;
      fHandles[ "seedTrk_etEMAtEMScale" ] = &seedTrk_etEMAtEMScale;
      fHandles[ "seedTrk_etEMCL" ] = &seedTrk_etEMCL;
      fHandles[ "seedTrk_etChrgEM" ] = &seedTrk_etChrgEM;
      fHandles[ "seedTrk_etNeuEM" ] = &seedTrk_etNeuEM;
      fHandles[ "seedTrk_etResNeuEM" ] = &seedTrk_etResNeuEM;
      fHandles[ "seedTrk_hadLeakEt" ] = &seedTrk_hadLeakEt;
      fHandles[ "seedTrk_sumEMCellEtOverLeadTrkPt" ] = &seedTrk_sumEMCellEtOverLeadTrkPt;
      fHandles[ "seedTrk_secMaxStripEt" ] = &seedTrk_secMaxStripEt;
      fHandles[ "seedTrk_stripWidth2" ] = &seedTrk_stripWidth2;
      fHandles[ "seedTrk_nStrip" ] = &seedTrk_nStrip;
      fHandles[ "seedTrk_etChrgHad" ] = &seedTrk_etChrgHad;
      fHandles[ "seedTrk_nOtherCoreTrk" ] = &seedTrk_nOtherCoreTrk;
      fHandles[ "seedTrk_nIsolTrk" ] = &seedTrk_nIsolTrk;
      fHandles[ "seedTrk_etIsolEM" ] = &seedTrk_etIsolEM;
      fHandles[ "seedTrk_etIsolHad" ] = &seedTrk_etIsolHad;
      fHandles[ "cellBasedEnergyRing1" ] = &cellBasedEnergyRing1;
      fHandles[ "cellBasedEnergyRing2" ] = &cellBasedEnergyRing2;
      fHandles[ "cellBasedEnergyRing3" ] = &cellBasedEnergyRing3;
      fHandles[ "cellBasedEnergyRing4" ] = &cellBasedEnergyRing4;
      fHandles[ "cellBasedEnergyRing5" ] = &cellBasedEnergyRing5;
      fHandles[ "cellBasedEnergyRing6" ] = &cellBasedEnergyRing6;
      fHandles[ "cellBasedEnergyRing7" ] = &cellBasedEnergyRing7;
      fHandles[ "calcVars_etHad_EMScale_Pt3Trks" ] = &calcVars_etHad_EMScale_Pt3Trks;
      fHandles[ "calcVars_etEM_EMScale_Pt3Trks" ] = &calcVars_etEM_EMScale_Pt3Trks;
      fHandles[ "calcVars_ipSigLeadLooseTrk" ] = &calcVars_ipSigLeadLooseTrk;
      fHandles[ "calcVars_drMin" ] = &calcVars_drMin;
      fHandles[ "calcVars_calRadius" ] = &calcVars_calRadius;
      fHandles[ "calcVars_EMFractionAtEMScale" ] = &calcVars_EMFractionAtEMScale;
      fHandles[ "calcVars_trackIso" ] = &calcVars_trackIso;
      fHandles[ "calcVars_ChPiEMEOverCaloEME" ] = &calcVars_ChPiEMEOverCaloEME;
      fHandles[ "calcVars_PSSFraction" ] = &calcVars_PSSFraction;
      fHandles[ "calcVars_EMPOverTrkSysP" ] = &calcVars_EMPOverTrkSysP;
      fHandles[ "calcVars_pi0BDTPrimaryScore" ] = &calcVars_pi0BDTPrimaryScore;
      fHandles[ "calcVars_pi0BDTSecondaryScore" ] = &calcVars_pi0BDTSecondaryScore;
      fHandles[ "calcVars_corrCentFrac" ] = &calcVars_corrCentFrac;
      fHandles[ "calcVars_corrFTrk" ] = &calcVars_corrFTrk;
      fHandles[ "calcVars_interAxis_eta" ] = &calcVars_interAxis_eta;
      fHandles[ "calcVars_interAxis_phi" ] = &calcVars_interAxis_phi;
      fHandles[ "pi0_cl1_pt" ] = &pi0_cl1_pt;
      fHandles[ "pi0_cl1_eta" ] = &pi0_cl1_eta;
      fHandles[ "pi0_cl1_phi" ] = &pi0_cl1_phi;
      fHandles[ "pi0_cl2_pt" ] = &pi0_cl2_pt;
      fHandles[ "pi0_cl2_eta" ] = &pi0_cl2_eta;
      fHandles[ "pi0_cl2_phi" ] = &pi0_cl2_phi;
      fHandles[ "pi0_vistau_pt" ] = &pi0_vistau_pt;
      fHandles[ "pi0_vistau_eta" ] = &pi0_vistau_eta;
      fHandles[ "pi0_vistau_phi" ] = &pi0_vistau_phi;
      fHandles[ "pi0_vistau_m" ] = &pi0_vistau_m;
      fHandles[ "pi0_n" ] = &pi0_n;
      fHandles[ "pantau_isPanTauCandidate" ] = &pantau_isPanTauCandidate;
      fHandles[ "pantau_PanTauScore" ] = &pantau_PanTauScore;
      fHandles[ "pantau_NChargedEFO" ] = &pantau_NChargedEFO;
      fHandles[ "pantau_NChargedQualifiedEFO" ] = &pantau_NChargedQualifiedEFO;
      fHandles[ "pantau_NNeutralEFO" ] = &pantau_NNeutralEFO;
      fHandles[ "pantau_AbsSumCharge" ] = &pantau_AbsSumCharge;
      fHandles[ "pantau_EflowJetMomentDRAll" ] = &pantau_EflowJetMomentDRAll;
      fHandles[ "pantau_EflowJetMomentDRChrg" ] = &pantau_EflowJetMomentDRChrg;
      fHandles[ "pantau_EflowJetMomentDREMNeut" ] = &pantau_EflowJetMomentDREMNeut;
      fHandles[ "pantau_EflowJetMomentDRHADNeut" ] = &pantau_EflowJetMomentDRHADNeut;
      fHandles[ "pantau_EtIn01OverEtIn02InvSigm" ] = &pantau_EtIn01OverEtIn02InvSigm;
      fHandles[ "pantau_EtIn02To04OverTotalEtInvSigm" ] = &pantau_EtIn02To04OverTotalEtInvSigm;
      fHandles[ "pantau_EtIn01OverEtIn04InvSigm" ] = &pantau_EtIn01OverEtIn04InvSigm;
      fHandles[ "pantau_EtIn01OverEtIn04" ] = &pantau_EtIn01OverEtIn04;
      fHandles[ "pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents" ] = &pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents;
      fHandles[ "pantau_JetSphericity" ] = &pantau_JetSphericity;
      fHandles[ "pantau_TransImpactParamSignfTrack1" ] = &pantau_TransImpactParamSignfTrack1;
      fHandles[ "pantau_EflowAngleJetAxisLeadingChargedQualified" ] = &pantau_EflowAngleJetAxisLeadingChargedQualified;
      fHandles[ "pantau_EflowAngleChargedAxisNeutralAxis" ] = &pantau_EflowAngleChargedAxisNeutralAxis;
      fHandles[ "pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified" ] = &pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified;
      fHandles[ "pantau_EflowInvariantMassAll" ] = &pantau_EflowInvariantMassAll;
      fHandles[ "pantau_EflowStdDevEtToSumEt" ] = &pantau_EflowStdDevEtToSumEt;
      fHandles[ "pantau_EflowEtLeadingChrgQualifiedOverTotalEt" ] = &pantau_EflowEtLeadingChrgQualifiedOverTotalEt;
      fHandles[ "pantau_EflowSumEAll" ] = &pantau_EflowSumEAll;
      fHandles[ "pantau_EflowChargedSumEt" ] = &pantau_EflowChargedSumEt;
      fHandles[ "leadTrack_eta" ] = &leadTrack_eta;
      fHandles[ "leadTrack_phi" ] = &leadTrack_phi;
      fHandles[ "cluster_E" ] = &cluster_E;
      fHandles[ "cluster_eta" ] = &cluster_eta;
      fHandles[ "cluster_phi" ] = &cluster_phi;
      fHandles[ "cluster_eta_atTJVA" ] = &cluster_eta_atTJVA;
      fHandles[ "cluster_phi_atTJVA" ] = &cluster_phi_atTJVA;
      fHandles[ "cluster_PreSamplerStripF" ] = &cluster_PreSamplerStripF;
      fHandles[ "cluster_EMLayer2F" ] = &cluster_EMLayer2F;
      fHandles[ "cluster_EMLayer3F" ] = &cluster_EMLayer3F;
      fHandles[ "cluster_n" ] = &cluster_n;
      fHandles[ "Pi0Cluster_pt" ] = &Pi0Cluster_pt;
      fHandles[ "Pi0Cluster_eta" ] = &Pi0Cluster_eta;
      fHandles[ "Pi0Cluster_phi" ] = &Pi0Cluster_phi;
      fHandles[ "secvtx_x" ] = &secvtx_x;
      fHandles[ "secvtx_y" ] = &secvtx_y;
      fHandles[ "secvtx_z" ] = &secvtx_z;
      fHandles[ "secvtx_xx" ] = &secvtx_xx;
      fHandles[ "secvtx_yy" ] = &secvtx_yy;
      fHandles[ "secvtx_zz" ] = &secvtx_zz;
      fHandles[ "secvtx_xy" ] = &secvtx_xy;
      fHandles[ "secvtx_yz" ] = &secvtx_yz;
      fHandles[ "secvtx_zx" ] = &secvtx_zx;
      fHandles[ "secvtx_chiSquared" ] = &secvtx_chiSquared;
      fHandles[ "secvtx_numberDoF" ] = &secvtx_numberDoF;
      fHandles[ "privtx_x" ] = &privtx_x;
      fHandles[ "privtx_y" ] = &privtx_y;
      fHandles[ "privtx_z" ] = &privtx_z;
      fHandles[ "privtx_xx" ] = &privtx_xx;
      fHandles[ "privtx_yy" ] = &privtx_yy;
      fHandles[ "privtx_zz" ] = &privtx_zz;
      fHandles[ "privtx_xy" ] = &privtx_xy;
      fHandles[ "privtx_yz" ] = &privtx_yz;
      fHandles[ "privtx_zx" ] = &privtx_zx;
      fHandles[ "privtx_chiSquared" ] = &privtx_chiSquared;
      fHandles[ "privtx_numberDoF" ] = &privtx_numberDoF;
      fHandles[ "privtx_jvf" ] = &privtx_jvf;
      fHandles[ "jet_Et" ] = &jet_Et;
      fHandles[ "jet_pt" ] = &jet_pt;
      fHandles[ "jet_m" ] = &jet_m;
      fHandles[ "jet_eta" ] = &jet_eta;
      fHandles[ "jet_phi" ] = &jet_phi;
      fHandles[ "jet_WIDTH" ] = &jet_WIDTH;
      fHandles[ "jet_n90" ] = &jet_n90;
      fHandles[ "jet_n90constituents" ] = &jet_n90constituents;
      fHandles[ "jet_BCH_CORR_CELL" ] = &jet_BCH_CORR_CELL;
      fHandles[ "jet_BCH_CORR_JET" ] = &jet_BCH_CORR_JET;
      fHandles[ "jet_BCH_CORR_JET_FORCELL" ] = &jet_BCH_CORR_JET_FORCELL;
      fHandles[ "jet_ENG_BAD_CELLS" ] = &jet_ENG_BAD_CELLS;
      fHandles[ "jet_N_BAD_CELLS" ] = &jet_N_BAD_CELLS;
      fHandles[ "jet_N_BAD_CELLS_CORR" ] = &jet_N_BAD_CELLS_CORR;
      fHandles[ "jet_BAD_CELLS_CORR_E" ] = &jet_BAD_CELLS_CORR_E;
      fHandles[ "jet_Timing" ] = &jet_Timing;
      fHandles[ "jet_LArQuality" ] = &jet_LArQuality;
      fHandles[ "jet_nTrk" ] = &jet_nTrk;
      fHandles[ "jet_sumPtTrk" ] = &jet_sumPtTrk;
      fHandles[ "jet_OriginIndex" ] = &jet_OriginIndex;
      fHandles[ "jet_HECQuality" ] = &jet_HECQuality;
      fHandles[ "jet_NegativeE" ] = &jet_NegativeE;
      fHandles[ "jet_YFlip12" ] = &jet_YFlip12;
      fHandles[ "jet_YFlip23" ] = &jet_YFlip23;
      fHandles[ "jet_BCH_CORR_DOTX" ] = &jet_BCH_CORR_DOTX;
      fHandles[ "jet_SamplingMax" ] = &jet_SamplingMax;
      fHandles[ "jet_fracSamplingMax" ] = &jet_fracSamplingMax;
      fHandles[ "jet_hecf" ] = &jet_hecf;
      fHandles[ "jet_tgap3f" ] = &jet_tgap3f;
      fHandles[ "jet_isUgly" ] = &jet_isUgly;
      fHandles[ "jet_isBadLooseMinus" ] = &jet_isBadLooseMinus;
      fHandles[ "jet_isBadLoose" ] = &jet_isBadLoose;
      fHandles[ "jet_isBadMedium" ] = &jet_isBadMedium;
      fHandles[ "jet_isBadTight" ] = &jet_isBadTight;
      fHandles[ "jet_emfrac" ] = &jet_emfrac;
      fHandles[ "jet_GCWJES" ] = &jet_GCWJES;
      fHandles[ "jet_EMJES" ] = &jet_EMJES;
      fHandles[ "jet_emscale_E" ] = &jet_emscale_E;
      fHandles[ "jet_emscale_pt" ] = &jet_emscale_pt;
      fHandles[ "jet_emscale_m" ] = &jet_emscale_m;
      fHandles[ "jet_emscale_eta" ] = &jet_emscale_eta;
      fHandles[ "jet_emscale_phi" ] = &jet_emscale_phi;
      fHandles[ "jet_jvtx_x" ] = &jet_jvtx_x;
      fHandles[ "jet_jvtx_y" ] = &jet_jvtx_y;
      fHandles[ "jet_jvtx_z" ] = &jet_jvtx_z;
      fHandles[ "jet_jvtxf" ] = &jet_jvtxf;
      fHandles[ "jet_flavor_weight" ] = &jet_flavor_weight;
      fHandles[ "jet_flavor_weight_TrackCounting2D" ] = &jet_flavor_weight_TrackCounting2D;
      fHandles[ "jet_flavor_weight_JetProb" ] = &jet_flavor_weight_JetProb;
      fHandles[ "jet_flavor_weight_IP1D" ] = &jet_flavor_weight_IP1D;
      fHandles[ "jet_flavor_weight_IP2D" ] = &jet_flavor_weight_IP2D;
      fHandles[ "jet_flavor_weight_IP3D" ] = &jet_flavor_weight_IP3D;
      fHandles[ "jet_flavor_weight_SV0" ] = &jet_flavor_weight_SV0;
      fHandles[ "jet_flavor_weight_SV1" ] = &jet_flavor_weight_SV1;
      fHandles[ "jet_flavor_weight_SV2" ] = &jet_flavor_weight_SV2;
      fHandles[ "jet_flavor_weight_JetFitterTag" ] = &jet_flavor_weight_JetFitterTag;
      fHandles[ "jet_flavor_weight_JetFitterCOMB" ] = &jet_flavor_weight_JetFitterCOMB;
      fHandles[ "jet_flavor_weight_JetFitterTagNN" ] = &jet_flavor_weight_JetFitterTagNN;
      fHandles[ "jet_flavor_weight_JetFitterCOMBNN" ] = &jet_flavor_weight_JetFitterCOMBNN;
      fHandles[ "jet_flavor_weight_SoftMuonTag" ] = &jet_flavor_weight_SoftMuonTag;
      fHandles[ "jet_flavor_weight_SoftElectronTag" ] = &jet_flavor_weight_SoftElectronTag;
      fHandles[ "jet_flavor_weight_IP3DSV1" ] = &jet_flavor_weight_IP3DSV1;
      fHandles[ "jet_e_PreSamplerB" ] = &jet_e_PreSamplerB;
      fHandles[ "jet_e_EMB1" ] = &jet_e_EMB1;
      fHandles[ "jet_e_EMB2" ] = &jet_e_EMB2;
      fHandles[ "jet_e_EMB3" ] = &jet_e_EMB3;
      fHandles[ "jet_e_PreSamplerE" ] = &jet_e_PreSamplerE;
      fHandles[ "jet_e_EME1" ] = &jet_e_EME1;
      fHandles[ "jet_e_EME2" ] = &jet_e_EME2;
      fHandles[ "jet_e_EME3" ] = &jet_e_EME3;
      fHandles[ "jet_e_HEC0" ] = &jet_e_HEC0;
      fHandles[ "jet_e_HEC1" ] = &jet_e_HEC1;
      fHandles[ "jet_e_HEC2" ] = &jet_e_HEC2;
      fHandles[ "jet_e_HEC3" ] = &jet_e_HEC3;
      fHandles[ "jet_e_TileBar0" ] = &jet_e_TileBar0;
      fHandles[ "jet_e_TileBar1" ] = &jet_e_TileBar1;
      fHandles[ "jet_e_TileBar2" ] = &jet_e_TileBar2;
      fHandles[ "jet_e_TileGap1" ] = &jet_e_TileGap1;
      fHandles[ "jet_e_TileGap2" ] = &jet_e_TileGap2;
      fHandles[ "jet_e_TileGap3" ] = &jet_e_TileGap3;
      fHandles[ "jet_e_TileExt0" ] = &jet_e_TileExt0;
      fHandles[ "jet_e_TileExt1" ] = &jet_e_TileExt1;
      fHandles[ "jet_e_TileExt2" ] = &jet_e_TileExt2;
      fHandles[ "jet_e_FCAL0" ] = &jet_e_FCAL0;
      fHandles[ "jet_e_FCAL1" ] = &jet_e_FCAL1;
      fHandles[ "jet_e_FCAL2" ] = &jet_e_FCAL2;
      fHandles[ "jet_shapeBins" ] = &jet_shapeBins;
      fHandles[ "track_atTJVA_n" ] = &track_atTJVA_n;
      fHandles[ "track_atTJVA_d0" ] = &track_atTJVA_d0;
      fHandles[ "track_atTJVA_z0" ] = &track_atTJVA_z0;
      fHandles[ "track_atTJVA_phi" ] = &track_atTJVA_phi;
      fHandles[ "track_atTJVA_theta" ] = &track_atTJVA_theta;
      fHandles[ "track_atTJVA_qoverp" ] = &track_atTJVA_qoverp;
      fHandles[ "track_atTJVA_pt" ] = &track_atTJVA_pt;
      fHandles[ "track_atTJVA_eta" ] = &track_atTJVA_eta;
      fHandles[ "seedCalo_wideTrk_atTJVA_n" ] = &seedCalo_wideTrk_atTJVA_n;
      fHandles[ "seedCalo_wideTrk_atTJVA_d0" ] = &seedCalo_wideTrk_atTJVA_d0;
      fHandles[ "seedCalo_wideTrk_atTJVA_z0" ] = &seedCalo_wideTrk_atTJVA_z0;
      fHandles[ "seedCalo_wideTrk_atTJVA_phi" ] = &seedCalo_wideTrk_atTJVA_phi;
      fHandles[ "seedCalo_wideTrk_atTJVA_theta" ] = &seedCalo_wideTrk_atTJVA_theta;
      fHandles[ "seedCalo_wideTrk_atTJVA_qoverp" ] = &seedCalo_wideTrk_atTJVA_qoverp;
      fHandles[ "seedCalo_wideTrk_atTJVA_pt" ] = &seedCalo_wideTrk_atTJVA_pt;
      fHandles[ "seedCalo_wideTrk_atTJVA_eta" ] = &seedCalo_wideTrk_atTJVA_eta;
      fHandles[ "otherTrk_atTJVA_n" ] = &otherTrk_atTJVA_n;
      fHandles[ "track_n" ] = &track_n;
      fHandles[ "track_d0" ] = &track_d0;
      fHandles[ "track_z0" ] = &track_z0;
      fHandles[ "track_phi" ] = &track_phi;
      fHandles[ "track_theta" ] = &track_theta;
      fHandles[ "track_qoverp" ] = &track_qoverp;
      fHandles[ "track_pt" ] = &track_pt;
      fHandles[ "track_eta" ] = &track_eta;
      fHandles[ "track_atPV_d0" ] = &track_atPV_d0;
      fHandles[ "track_atPV_z0" ] = &track_atPV_z0;
      fHandles[ "track_atPV_phi" ] = &track_atPV_phi;
      fHandles[ "track_atPV_theta" ] = &track_atPV_theta;
      fHandles[ "track_atPV_qoverp" ] = &track_atPV_qoverp;
      fHandles[ "track_atPV_pt" ] = &track_atPV_pt;
      fHandles[ "track_atPV_eta" ] = &track_atPV_eta;
      fHandles[ "track_nBLHits" ] = &track_nBLHits;
      fHandles[ "track_nPixHits" ] = &track_nPixHits;
      fHandles[ "track_nSCTHits" ] = &track_nSCTHits;
      fHandles[ "track_nTRTHits" ] = &track_nTRTHits;
      fHandles[ "track_nTRTHighTHits" ] = &track_nTRTHighTHits;
      fHandles[ "track_nTRTXenonHits" ] = &track_nTRTXenonHits;
      fHandles[ "track_nPixHoles" ] = &track_nPixHoles;
      fHandles[ "track_nSCTHoles" ] = &track_nSCTHoles;
      fHandles[ "track_nTRTHoles" ] = &track_nTRTHoles;
      fHandles[ "track_nPixelDeadSensors" ] = &track_nPixelDeadSensors;
      fHandles[ "track_nSCTDeadSensors" ] = &track_nSCTDeadSensors;
      fHandles[ "track_nBLSharedHits" ] = &track_nBLSharedHits;
      fHandles[ "track_nPixSharedHits" ] = &track_nPixSharedHits;
      fHandles[ "track_nSCTSharedHits" ] = &track_nSCTSharedHits;
      fHandles[ "track_nBLayerSplitHits" ] = &track_nBLayerSplitHits;
      fHandles[ "track_nPixSplitHits" ] = &track_nPixSplitHits;
      fHandles[ "track_nBLayerOutliers" ] = &track_nBLayerOutliers;
      fHandles[ "track_nPixelOutliers" ] = &track_nPixelOutliers;
      fHandles[ "track_nSCTOutliers" ] = &track_nSCTOutliers;
      fHandles[ "track_nTRTOutliers" ] = &track_nTRTOutliers;
      fHandles[ "track_nTRTHighTOutliers" ] = &track_nTRTHighTOutliers;
      fHandles[ "track_nContribPixelLayers" ] = &track_nContribPixelLayers;
      fHandles[ "track_nGangedPixels" ] = &track_nGangedPixels;
      fHandles[ "track_nGangedFlaggedFakes" ] = &track_nGangedFlaggedFakes;
      fHandles[ "track_nPixelSpoiltHits" ] = &track_nPixelSpoiltHits;
      fHandles[ "track_nSCTDoubleHoles" ] = &track_nSCTDoubleHoles;
      fHandles[ "track_nSCTSpoiltHits" ] = &track_nSCTSpoiltHits;
      fHandles[ "track_expectBLayerHit" ] = &track_expectBLayerHit;
      fHandles[ "track_nHits" ] = &track_nHits;
      fHandles[ "track_TRTHighTHitsRatio" ] = &track_TRTHighTHitsRatio;
      fHandles[ "track_TRTHighTOutliersRatio" ] = &track_TRTHighTOutliersRatio;
      fHandles[ "seedCalo_track_n" ] = &seedCalo_track_n;
      fHandles[ "seedCalo_wideTrk_n" ] = &seedCalo_wideTrk_n;
      fHandles[ "seedCalo_wideTrk_nBLHits" ] = &seedCalo_wideTrk_nBLHits;
      fHandles[ "seedCalo_wideTrk_nPixHits" ] = &seedCalo_wideTrk_nPixHits;
      fHandles[ "seedCalo_wideTrk_nSCTHits" ] = &seedCalo_wideTrk_nSCTHits;
      fHandles[ "seedCalo_wideTrk_nTRTHits" ] = &seedCalo_wideTrk_nTRTHits;
      fHandles[ "seedCalo_wideTrk_nTRTHighTHits" ] = &seedCalo_wideTrk_nTRTHighTHits;
      fHandles[ "seedCalo_wideTrk_nTRTXenonHits" ] = &seedCalo_wideTrk_nTRTXenonHits;
      fHandles[ "seedCalo_wideTrk_nPixHoles" ] = &seedCalo_wideTrk_nPixHoles;
      fHandles[ "seedCalo_wideTrk_nSCTHoles" ] = &seedCalo_wideTrk_nSCTHoles;
      fHandles[ "seedCalo_wideTrk_nTRTHoles" ] = &seedCalo_wideTrk_nTRTHoles;
      fHandles[ "seedCalo_wideTrk_nPixelDeadSensors" ] = &seedCalo_wideTrk_nPixelDeadSensors;
      fHandles[ "seedCalo_wideTrk_nSCTDeadSensors" ] = &seedCalo_wideTrk_nSCTDeadSensors;
      fHandles[ "seedCalo_wideTrk_nBLSharedHits" ] = &seedCalo_wideTrk_nBLSharedHits;
      fHandles[ "seedCalo_wideTrk_nPixSharedHits" ] = &seedCalo_wideTrk_nPixSharedHits;
      fHandles[ "seedCalo_wideTrk_nSCTSharedHits" ] = &seedCalo_wideTrk_nSCTSharedHits;
      fHandles[ "seedCalo_wideTrk_nBLayerSplitHits" ] = &seedCalo_wideTrk_nBLayerSplitHits;
      fHandles[ "seedCalo_wideTrk_nPixSplitHits" ] = &seedCalo_wideTrk_nPixSplitHits;
      fHandles[ "seedCalo_wideTrk_nBLayerOutliers" ] = &seedCalo_wideTrk_nBLayerOutliers;
      fHandles[ "seedCalo_wideTrk_nPixelOutliers" ] = &seedCalo_wideTrk_nPixelOutliers;
      fHandles[ "seedCalo_wideTrk_nSCTOutliers" ] = &seedCalo_wideTrk_nSCTOutliers;
      fHandles[ "seedCalo_wideTrk_nTRTOutliers" ] = &seedCalo_wideTrk_nTRTOutliers;
      fHandles[ "seedCalo_wideTrk_nTRTHighTOutliers" ] = &seedCalo_wideTrk_nTRTHighTOutliers;
      fHandles[ "seedCalo_wideTrk_nContribPixelLayers" ] = &seedCalo_wideTrk_nContribPixelLayers;
      fHandles[ "seedCalo_wideTrk_nGangedPixels" ] = &seedCalo_wideTrk_nGangedPixels;
      fHandles[ "seedCalo_wideTrk_nGangedFlaggedFakes" ] = &seedCalo_wideTrk_nGangedFlaggedFakes;
      fHandles[ "seedCalo_wideTrk_nPixelSpoiltHits" ] = &seedCalo_wideTrk_nPixelSpoiltHits;
      fHandles[ "seedCalo_wideTrk_nSCTDoubleHoles" ] = &seedCalo_wideTrk_nSCTDoubleHoles;
      fHandles[ "seedCalo_wideTrk_nSCTSpoiltHits" ] = &seedCalo_wideTrk_nSCTSpoiltHits;
      fHandles[ "seedCalo_wideTrk_expectBLayerHit" ] = &seedCalo_wideTrk_expectBLayerHit;
      fHandles[ "seedCalo_wideTrk_nHits" ] = &seedCalo_wideTrk_nHits;
      fHandles[ "otherTrk_n" ] = &otherTrk_n;
      fHandles[ "EF_dr" ] = &EF_dr;
      fHandles[ "EF_E" ] = &EF_E;
      fHandles[ "EF_Et" ] = &EF_Et;
      fHandles[ "EF_pt" ] = &EF_pt;
      fHandles[ "EF_eta" ] = &EF_eta;
      fHandles[ "EF_phi" ] = &EF_phi;
      fHandles[ "EF_matched" ] = &EF_matched;
      fHandles[ "L2_dr" ] = &L2_dr;
      fHandles[ "L2_E" ] = &L2_E;
      fHandles[ "L2_Et" ] = &L2_Et;
      fHandles[ "L2_pt" ] = &L2_pt;
      fHandles[ "L2_eta" ] = &L2_eta;
      fHandles[ "L2_phi" ] = &L2_phi;
      fHandles[ "L2_matched" ] = &L2_matched;
      fHandles[ "L1_dr" ] = &L1_dr;
      fHandles[ "L1_Et" ] = &L1_Et;
      fHandles[ "L1_pt" ] = &L1_pt;
      fHandles[ "L1_eta" ] = &L1_eta;
      fHandles[ "L1_phi" ] = &L1_phi;
      fHandles[ "L1_matched" ] = &L1_matched;
if (!is_data) {
      fHandles[ "trueTauAssocSmall_dr" ] = &trueTauAssocSmall_dr;
      fHandles[ "trueTauAssocSmall_index" ] = &trueTauAssocSmall_index;
      fHandles[ "trueTauAssocSmall_matched" ] = &trueTauAssocSmall_matched;
} // end !is_data
      fHandles[ "MET_Egamma10LooseTau_wpx" ] = &MET_Egamma10LooseTau_wpx;
      fHandles[ "MET_Egamma10LooseTau_wpy" ] = &MET_Egamma10LooseTau_wpy;
      fHandles[ "MET_Egamma10LooseTau_wet" ] = &MET_Egamma10LooseTau_wet;
      fHandles[ "MET_Egamma10LooseTau_statusWord" ] = &MET_Egamma10LooseTau_statusWord;
      fHandles[ "MET_wpx" ] = &MET_wpx;
      fHandles[ "MET_wpy" ] = &MET_wpy;
      fHandles[ "MET_wet" ] = &MET_wet;
      fHandles[ "MET_statusWord" ] = &MET_statusWord;
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* TauD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void TauD3PDObject::SetPrefix( const char* prefix ) {

      n.SetName( ::TString( prefix ) + "n" );
      Et.SetName( ::TString( prefix ) + "Et" );
      pt.SetName( ::TString( prefix ) + "pt" );
      m.SetName( ::TString( prefix ) + "m" );
      eta.SetName( ::TString( prefix ) + "eta" );
      phi.SetName( ::TString( prefix ) + "phi" );
      charge.SetName( ::TString( prefix ) + "charge" );
      BDTEleScore.SetName( ::TString( prefix ) + "BDTEleScore" );
      BDTJetScore.SetName( ::TString( prefix ) + "BDTJetScore" );
      likelihood.SetName( ::TString( prefix ) + "likelihood" );
      SafeLikelihood.SetName( ::TString( prefix ) + "SafeLikelihood" );
      electronVetoLoose.SetName( ::TString( prefix ) + "electronVetoLoose" );
      electronVetoMedium.SetName( ::TString( prefix ) + "electronVetoMedium" );
      electronVetoTight.SetName( ::TString( prefix ) + "electronVetoTight" );
      muonVeto.SetName( ::TString( prefix ) + "muonVeto" );
      tauLlhLoose.SetName( ::TString( prefix ) + "tauLlhLoose" );
      tauLlhMedium.SetName( ::TString( prefix ) + "tauLlhMedium" );
      tauLlhTight.SetName( ::TString( prefix ) + "tauLlhTight" );
      JetBDTSigLoose.SetName( ::TString( prefix ) + "JetBDTSigLoose" );
      JetBDTSigMedium.SetName( ::TString( prefix ) + "JetBDTSigMedium" );
      JetBDTSigTight.SetName( ::TString( prefix ) + "JetBDTSigTight" );
      EleBDTLoose.SetName( ::TString( prefix ) + "EleBDTLoose" );
      EleBDTMedium.SetName( ::TString( prefix ) + "EleBDTMedium" );
      EleBDTTight.SetName( ::TString( prefix ) + "EleBDTTight" );
      author.SetName( ::TString( prefix ) + "author" );
      RoIWord.SetName( ::TString( prefix ) + "RoIWord" );
      nProng.SetName( ::TString( prefix ) + "nProng" );
      numTrack.SetName( ::TString( prefix ) + "numTrack" );
      seedCalo_numTrack.SetName( ::TString( prefix ) + "seedCalo_numTrack" );
      seedCalo_nWideTrk.SetName( ::TString( prefix ) + "seedCalo_nWideTrk" );
      nOtherTrk.SetName( ::TString( prefix ) + "nOtherTrk" );
      etOverPtLeadTrk.SetName( ::TString( prefix ) + "etOverPtLeadTrk" );
      ipZ0SinThetaSigLeadTrk.SetName( ::TString( prefix ) + "ipZ0SinThetaSigLeadTrk" );
      leadTrkPt.SetName( ::TString( prefix ) + "leadTrkPt" );
      nLooseTrk.SetName( ::TString( prefix ) + "nLooseTrk" );
      nLooseConvTrk.SetName( ::TString( prefix ) + "nLooseConvTrk" );
      nProngLoose.SetName( ::TString( prefix ) + "nProngLoose" );
      ipSigLeadTrk.SetName( ::TString( prefix ) + "ipSigLeadTrk" );
      ipSigLeadLooseTrk.SetName( ::TString( prefix ) + "ipSigLeadLooseTrk" );
      etOverPtLeadLooseTrk.SetName( ::TString( prefix ) + "etOverPtLeadLooseTrk" );
      leadLooseTrkPt.SetName( ::TString( prefix ) + "leadLooseTrkPt" );
      chrgLooseTrk.SetName( ::TString( prefix ) + "chrgLooseTrk" );
      massTrkSys.SetName( ::TString( prefix ) + "massTrkSys" );
      trkWidth2.SetName( ::TString( prefix ) + "trkWidth2" );
      trFlightPathSig.SetName( ::TString( prefix ) + "trFlightPathSig" );
      etEflow.SetName( ::TString( prefix ) + "etEflow" );
      mEflow.SetName( ::TString( prefix ) + "mEflow" );
      nPi0.SetName( ::TString( prefix ) + "nPi0" );
      ele_E237E277.SetName( ::TString( prefix ) + "ele_E237E277" );
      ele_PresamplerFraction.SetName( ::TString( prefix ) + "ele_PresamplerFraction" );
      ele_ECALFirstFraction.SetName( ::TString( prefix ) + "ele_ECALFirstFraction" );
      EM_TES_scale.SetName( ::TString( prefix ) + "EM_TES_scale" );
      LC_TES_precalib.SetName( ::TString( prefix ) + "LC_TES_precalib" );
      TRTHTOverLT_LeadTrk.SetName( ::TString( prefix ) + "TRTHTOverLT_LeadTrk" );
      seedCalo_EMRadius.SetName( ::TString( prefix ) + "seedCalo_EMRadius" );
      seedCalo_hadRadius.SetName( ::TString( prefix ) + "seedCalo_hadRadius" );
      seedCalo_etEMAtEMScale.SetName( ::TString( prefix ) + "seedCalo_etEMAtEMScale" );
      seedCalo_etHadAtEMScale.SetName( ::TString( prefix ) + "seedCalo_etHadAtEMScale" );
      seedCalo_isolFrac.SetName( ::TString( prefix ) + "seedCalo_isolFrac" );
      seedCalo_centFrac.SetName( ::TString( prefix ) + "seedCalo_centFrac" );
      seedCalo_stripWidth2.SetName( ::TString( prefix ) + "seedCalo_stripWidth2" );
      seedCalo_nStrip.SetName( ::TString( prefix ) + "seedCalo_nStrip" );
      seedCalo_eta.SetName( ::TString( prefix ) + "seedCalo_eta" );
      seedCalo_phi.SetName( ::TString( prefix ) + "seedCalo_phi" );
      seedCalo_nIsolLooseTrk.SetName( ::TString( prefix ) + "seedCalo_nIsolLooseTrk" );
      seedCalo_trkAvgDist.SetName( ::TString( prefix ) + "seedCalo_trkAvgDist" );
      seedCalo_trkRmsDist.SetName( ::TString( prefix ) + "seedCalo_trkRmsDist" );
      seedCalo_caloIso.SetName( ::TString( prefix ) + "seedCalo_caloIso" );
      seedCalo_caloIsoCorrected.SetName( ::TString( prefix ) + "seedCalo_caloIsoCorrected" );
      seedCalo_dRmax.SetName( ::TString( prefix ) + "seedCalo_dRmax" );
      seedCalo_lead2ClusterEOverAllClusterE.SetName( ::TString( prefix ) + "seedCalo_lead2ClusterEOverAllClusterE" );
      seedCalo_lead3ClusterEOverAllClusterE.SetName( ::TString( prefix ) + "seedCalo_lead3ClusterEOverAllClusterE" );
      seedCalo_etHadCalib.SetName( ::TString( prefix ) + "seedCalo_etHadCalib" );
      seedCalo_etEMCalib.SetName( ::TString( prefix ) + "seedCalo_etEMCalib" );
      numTopoClusters.SetName( ::TString( prefix ) + "numTopoClusters" );
      numEffTopoClusters.SetName( ::TString( prefix ) + "numEffTopoClusters" );
      topoInvMass.SetName( ::TString( prefix ) + "topoInvMass" );
      effTopoInvMass.SetName( ::TString( prefix ) + "effTopoInvMass" );
      topoMeanDeltaR.SetName( ::TString( prefix ) + "topoMeanDeltaR" );
      effTopoMeanDeltaR.SetName( ::TString( prefix ) + "effTopoMeanDeltaR" );
      numCells.SetName( ::TString( prefix ) + "numCells" );
      seedTrk_EMRadius.SetName( ::TString( prefix ) + "seedTrk_EMRadius" );
      seedTrk_isolFrac.SetName( ::TString( prefix ) + "seedTrk_isolFrac" );
      seedTrk_etChrgHadOverSumTrkPt.SetName( ::TString( prefix ) + "seedTrk_etChrgHadOverSumTrkPt" );
      seedTrk_isolFracWide.SetName( ::TString( prefix ) + "seedTrk_isolFracWide" );
      seedTrk_etHadAtEMScale.SetName( ::TString( prefix ) + "seedTrk_etHadAtEMScale" );
      seedTrk_etEMAtEMScale.SetName( ::TString( prefix ) + "seedTrk_etEMAtEMScale" );
      seedTrk_etEMCL.SetName( ::TString( prefix ) + "seedTrk_etEMCL" );
      seedTrk_etChrgEM.SetName( ::TString( prefix ) + "seedTrk_etChrgEM" );
      seedTrk_etNeuEM.SetName( ::TString( prefix ) + "seedTrk_etNeuEM" );
      seedTrk_etResNeuEM.SetName( ::TString( prefix ) + "seedTrk_etResNeuEM" );
      seedTrk_hadLeakEt.SetName( ::TString( prefix ) + "seedTrk_hadLeakEt" );
      seedTrk_sumEMCellEtOverLeadTrkPt.SetName( ::TString( prefix ) + "seedTrk_sumEMCellEtOverLeadTrkPt" );
      seedTrk_secMaxStripEt.SetName( ::TString( prefix ) + "seedTrk_secMaxStripEt" );
      seedTrk_stripWidth2.SetName( ::TString( prefix ) + "seedTrk_stripWidth2" );
      seedTrk_nStrip.SetName( ::TString( prefix ) + "seedTrk_nStrip" );
      seedTrk_etChrgHad.SetName( ::TString( prefix ) + "seedTrk_etChrgHad" );
      seedTrk_nOtherCoreTrk.SetName( ::TString( prefix ) + "seedTrk_nOtherCoreTrk" );
      seedTrk_nIsolTrk.SetName( ::TString( prefix ) + "seedTrk_nIsolTrk" );
      seedTrk_etIsolEM.SetName( ::TString( prefix ) + "seedTrk_etIsolEM" );
      seedTrk_etIsolHad.SetName( ::TString( prefix ) + "seedTrk_etIsolHad" );
      cellBasedEnergyRing1.SetName( ::TString( prefix ) + "cellBasedEnergyRing1" );
      cellBasedEnergyRing2.SetName( ::TString( prefix ) + "cellBasedEnergyRing2" );
      cellBasedEnergyRing3.SetName( ::TString( prefix ) + "cellBasedEnergyRing3" );
      cellBasedEnergyRing4.SetName( ::TString( prefix ) + "cellBasedEnergyRing4" );
      cellBasedEnergyRing5.SetName( ::TString( prefix ) + "cellBasedEnergyRing5" );
      cellBasedEnergyRing6.SetName( ::TString( prefix ) + "cellBasedEnergyRing6" );
      cellBasedEnergyRing7.SetName( ::TString( prefix ) + "cellBasedEnergyRing7" );
      calcVars_etHad_EMScale_Pt3Trks.SetName( ::TString( prefix ) + "calcVars_etHad_EMScale_Pt3Trks" );
      calcVars_etEM_EMScale_Pt3Trks.SetName( ::TString( prefix ) + "calcVars_etEM_EMScale_Pt3Trks" );
      calcVars_ipSigLeadLooseTrk.SetName( ::TString( prefix ) + "calcVars_ipSigLeadLooseTrk" );
      calcVars_drMin.SetName( ::TString( prefix ) + "calcVars_drMin" );
      calcVars_calRadius.SetName( ::TString( prefix ) + "calcVars_calRadius" );
      calcVars_EMFractionAtEMScale.SetName( ::TString( prefix ) + "calcVars_EMFractionAtEMScale" );
      calcVars_trackIso.SetName( ::TString( prefix ) + "calcVars_trackIso" );
      calcVars_ChPiEMEOverCaloEME.SetName( ::TString( prefix ) + "calcVars_ChPiEMEOverCaloEME" );
      calcVars_PSSFraction.SetName( ::TString( prefix ) + "calcVars_PSSFraction" );
      calcVars_EMPOverTrkSysP.SetName( ::TString( prefix ) + "calcVars_EMPOverTrkSysP" );
      calcVars_pi0BDTPrimaryScore.SetName( ::TString( prefix ) + "calcVars_pi0BDTPrimaryScore" );
      calcVars_pi0BDTSecondaryScore.SetName( ::TString( prefix ) + "calcVars_pi0BDTSecondaryScore" );
      calcVars_corrCentFrac.SetName( ::TString( prefix ) + "calcVars_corrCentFrac" );
      calcVars_corrFTrk.SetName( ::TString( prefix ) + "calcVars_corrFTrk" );
      calcVars_interAxis_eta.SetName( ::TString( prefix ) + "calcVars_interAxis_eta" );
      calcVars_interAxis_phi.SetName( ::TString( prefix ) + "calcVars_interAxis_phi" );
      pi0_cl1_pt.SetName( ::TString( prefix ) + "pi0_cl1_pt" );
      pi0_cl1_eta.SetName( ::TString( prefix ) + "pi0_cl1_eta" );
      pi0_cl1_phi.SetName( ::TString( prefix ) + "pi0_cl1_phi" );
      pi0_cl2_pt.SetName( ::TString( prefix ) + "pi0_cl2_pt" );
      pi0_cl2_eta.SetName( ::TString( prefix ) + "pi0_cl2_eta" );
      pi0_cl2_phi.SetName( ::TString( prefix ) + "pi0_cl2_phi" );
      pi0_vistau_pt.SetName( ::TString( prefix ) + "pi0_vistau_pt" );
      pi0_vistau_eta.SetName( ::TString( prefix ) + "pi0_vistau_eta" );
      pi0_vistau_phi.SetName( ::TString( prefix ) + "pi0_vistau_phi" );
      pi0_vistau_m.SetName( ::TString( prefix ) + "pi0_vistau_m" );
      pi0_n.SetName( ::TString( prefix ) + "pi0_n" );
      pantau_isPanTauCandidate.SetName( ::TString( prefix ) + "pantau_isPanTauCandidate" );
      pantau_PanTauScore.SetName( ::TString( prefix ) + "pantau_PanTauScore" );
      pantau_NChargedEFO.SetName( ::TString( prefix ) + "pantau_NChargedEFO" );
      pantau_NChargedQualifiedEFO.SetName( ::TString( prefix ) + "pantau_NChargedQualifiedEFO" );
      pantau_NNeutralEFO.SetName( ::TString( prefix ) + "pantau_NNeutralEFO" );
      pantau_AbsSumCharge.SetName( ::TString( prefix ) + "pantau_AbsSumCharge" );
      pantau_EflowJetMomentDRAll.SetName( ::TString( prefix ) + "pantau_EflowJetMomentDRAll" );
      pantau_EflowJetMomentDRChrg.SetName( ::TString( prefix ) + "pantau_EflowJetMomentDRChrg" );
      pantau_EflowJetMomentDREMNeut.SetName( ::TString( prefix ) + "pantau_EflowJetMomentDREMNeut" );
      pantau_EflowJetMomentDRHADNeut.SetName( ::TString( prefix ) + "pantau_EflowJetMomentDRHADNeut" );
      pantau_EtIn01OverEtIn02InvSigm.SetName( ::TString( prefix ) + "pantau_EtIn01OverEtIn02InvSigm" );
      pantau_EtIn02To04OverTotalEtInvSigm.SetName( ::TString( prefix ) + "pantau_EtIn02To04OverTotalEtInvSigm" );
      pantau_EtIn01OverEtIn04InvSigm.SetName( ::TString( prefix ) + "pantau_EtIn01OverEtIn04InvSigm" );
      pantau_EtIn01OverEtIn04.SetName( ::TString( prefix ) + "pantau_EtIn01OverEtIn04" );
      pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents.SetName( ::TString( prefix ) + "pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents" );
      pantau_JetSphericity.SetName( ::TString( prefix ) + "pantau_JetSphericity" );
      pantau_TransImpactParamSignfTrack1.SetName( ::TString( prefix ) + "pantau_TransImpactParamSignfTrack1" );
      pantau_EflowAngleJetAxisLeadingChargedQualified.SetName( ::TString( prefix ) + "pantau_EflowAngleJetAxisLeadingChargedQualified" );
      pantau_EflowAngleChargedAxisNeutralAxis.SetName( ::TString( prefix ) + "pantau_EflowAngleChargedAxisNeutralAxis" );
      pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified.SetName( ::TString( prefix ) + "pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified" );
      pantau_EflowInvariantMassAll.SetName( ::TString( prefix ) + "pantau_EflowInvariantMassAll" );
      pantau_EflowStdDevEtToSumEt.SetName( ::TString( prefix ) + "pantau_EflowStdDevEtToSumEt" );
      pantau_EflowEtLeadingChrgQualifiedOverTotalEt.SetName( ::TString( prefix ) + "pantau_EflowEtLeadingChrgQualifiedOverTotalEt" );
      pantau_EflowSumEAll.SetName( ::TString( prefix ) + "pantau_EflowSumEAll" );
      pantau_EflowChargedSumEt.SetName( ::TString( prefix ) + "pantau_EflowChargedSumEt" );
      leadTrack_eta.SetName( ::TString( prefix ) + "leadTrack_eta" );
      leadTrack_phi.SetName( ::TString( prefix ) + "leadTrack_phi" );
      cluster_E.SetName( ::TString( prefix ) + "cluster_E" );
      cluster_eta.SetName( ::TString( prefix ) + "cluster_eta" );
      cluster_phi.SetName( ::TString( prefix ) + "cluster_phi" );
      cluster_eta_atTJVA.SetName( ::TString( prefix ) + "cluster_eta_atTJVA" );
      cluster_phi_atTJVA.SetName( ::TString( prefix ) + "cluster_phi_atTJVA" );
      cluster_PreSamplerStripF.SetName( ::TString( prefix ) + "cluster_PreSamplerStripF" );
      cluster_EMLayer2F.SetName( ::TString( prefix ) + "cluster_EMLayer2F" );
      cluster_EMLayer3F.SetName( ::TString( prefix ) + "cluster_EMLayer3F" );
      cluster_n.SetName( ::TString( prefix ) + "cluster_n" );
      Pi0Cluster_pt.SetName( ::TString( prefix ) + "Pi0Cluster_pt" );
      Pi0Cluster_eta.SetName( ::TString( prefix ) + "Pi0Cluster_eta" );
      Pi0Cluster_phi.SetName( ::TString( prefix ) + "Pi0Cluster_phi" );
      secvtx_x.SetName( ::TString( prefix ) + "secvtx_x" );
      secvtx_y.SetName( ::TString( prefix ) + "secvtx_y" );
      secvtx_z.SetName( ::TString( prefix ) + "secvtx_z" );
      secvtx_xx.SetName( ::TString( prefix ) + "secvtx_xx" );
      secvtx_yy.SetName( ::TString( prefix ) + "secvtx_yy" );
      secvtx_zz.SetName( ::TString( prefix ) + "secvtx_zz" );
      secvtx_xy.SetName( ::TString( prefix ) + "secvtx_xy" );
      secvtx_yz.SetName( ::TString( prefix ) + "secvtx_yz" );
      secvtx_zx.SetName( ::TString( prefix ) + "secvtx_zx" );
      secvtx_chiSquared.SetName( ::TString( prefix ) + "secvtx_chiSquared" );
      secvtx_numberDoF.SetName( ::TString( prefix ) + "secvtx_numberDoF" );
      privtx_x.SetName( ::TString( prefix ) + "privtx_x" );
      privtx_y.SetName( ::TString( prefix ) + "privtx_y" );
      privtx_z.SetName( ::TString( prefix ) + "privtx_z" );
      privtx_xx.SetName( ::TString( prefix ) + "privtx_xx" );
      privtx_yy.SetName( ::TString( prefix ) + "privtx_yy" );
      privtx_zz.SetName( ::TString( prefix ) + "privtx_zz" );
      privtx_xy.SetName( ::TString( prefix ) + "privtx_xy" );
      privtx_yz.SetName( ::TString( prefix ) + "privtx_yz" );
      privtx_zx.SetName( ::TString( prefix ) + "privtx_zx" );
      privtx_chiSquared.SetName( ::TString( prefix ) + "privtx_chiSquared" );
      privtx_numberDoF.SetName( ::TString( prefix ) + "privtx_numberDoF" );
      privtx_jvf.SetName( ::TString( prefix ) + "privtx_jvf" );
      jet_Et.SetName( ::TString( prefix ) + "jet_Et" );
      jet_pt.SetName( ::TString( prefix ) + "jet_pt" );
      jet_m.SetName( ::TString( prefix ) + "jet_m" );
      jet_eta.SetName( ::TString( prefix ) + "jet_eta" );
      jet_phi.SetName( ::TString( prefix ) + "jet_phi" );
      jet_WIDTH.SetName( ::TString( prefix ) + "jet_WIDTH" );
      jet_n90.SetName( ::TString( prefix ) + "jet_n90" );
      jet_n90constituents.SetName( ::TString( prefix ) + "jet_n90constituents" );
      jet_BCH_CORR_CELL.SetName( ::TString( prefix ) + "jet_BCH_CORR_CELL" );
      jet_BCH_CORR_JET.SetName( ::TString( prefix ) + "jet_BCH_CORR_JET" );
      jet_BCH_CORR_JET_FORCELL.SetName( ::TString( prefix ) + "jet_BCH_CORR_JET_FORCELL" );
      jet_ENG_BAD_CELLS.SetName( ::TString( prefix ) + "jet_ENG_BAD_CELLS" );
      jet_N_BAD_CELLS.SetName( ::TString( prefix ) + "jet_N_BAD_CELLS" );
      jet_N_BAD_CELLS_CORR.SetName( ::TString( prefix ) + "jet_N_BAD_CELLS_CORR" );
      jet_BAD_CELLS_CORR_E.SetName( ::TString( prefix ) + "jet_BAD_CELLS_CORR_E" );
      jet_Timing.SetName( ::TString( prefix ) + "jet_Timing" );
      jet_LArQuality.SetName( ::TString( prefix ) + "jet_LArQuality" );
      jet_nTrk.SetName( ::TString( prefix ) + "jet_nTrk" );
      jet_sumPtTrk.SetName( ::TString( prefix ) + "jet_sumPtTrk" );
      jet_OriginIndex.SetName( ::TString( prefix ) + "jet_OriginIndex" );
      jet_HECQuality.SetName( ::TString( prefix ) + "jet_HECQuality" );
      jet_NegativeE.SetName( ::TString( prefix ) + "jet_NegativeE" );
      jet_YFlip12.SetName( ::TString( prefix ) + "jet_YFlip12" );
      jet_YFlip23.SetName( ::TString( prefix ) + "jet_YFlip23" );
      jet_BCH_CORR_DOTX.SetName( ::TString( prefix ) + "jet_BCH_CORR_DOTX" );
      jet_SamplingMax.SetName( ::TString( prefix ) + "jet_SamplingMax" );
      jet_fracSamplingMax.SetName( ::TString( prefix ) + "jet_fracSamplingMax" );
      jet_hecf.SetName( ::TString( prefix ) + "jet_hecf" );
      jet_tgap3f.SetName( ::TString( prefix ) + "jet_tgap3f" );
      jet_isUgly.SetName( ::TString( prefix ) + "jet_isUgly" );
      jet_isBadLooseMinus.SetName( ::TString( prefix ) + "jet_isBadLooseMinus" );
      jet_isBadLoose.SetName( ::TString( prefix ) + "jet_isBadLoose" );
      jet_isBadMedium.SetName( ::TString( prefix ) + "jet_isBadMedium" );
      jet_isBadTight.SetName( ::TString( prefix ) + "jet_isBadTight" );
      jet_emfrac.SetName( ::TString( prefix ) + "jet_emfrac" );
      jet_GCWJES.SetName( ::TString( prefix ) + "jet_GCWJES" );
      jet_EMJES.SetName( ::TString( prefix ) + "jet_EMJES" );
      jet_emscale_E.SetName( ::TString( prefix ) + "jet_emscale_E" );
      jet_emscale_pt.SetName( ::TString( prefix ) + "jet_emscale_pt" );
      jet_emscale_m.SetName( ::TString( prefix ) + "jet_emscale_m" );
      jet_emscale_eta.SetName( ::TString( prefix ) + "jet_emscale_eta" );
      jet_emscale_phi.SetName( ::TString( prefix ) + "jet_emscale_phi" );
      jet_jvtx_x.SetName( ::TString( prefix ) + "jet_jvtx_x" );
      jet_jvtx_y.SetName( ::TString( prefix ) + "jet_jvtx_y" );
      jet_jvtx_z.SetName( ::TString( prefix ) + "jet_jvtx_z" );
      jet_jvtxf.SetName( ::TString( prefix ) + "jet_jvtxf" );
      jet_flavor_weight.SetName( ::TString( prefix ) + "jet_flavor_weight" );
      jet_flavor_weight_TrackCounting2D.SetName( ::TString( prefix ) + "jet_flavor_weight_TrackCounting2D" );
      jet_flavor_weight_JetProb.SetName( ::TString( prefix ) + "jet_flavor_weight_JetProb" );
      jet_flavor_weight_IP1D.SetName( ::TString( prefix ) + "jet_flavor_weight_IP1D" );
      jet_flavor_weight_IP2D.SetName( ::TString( prefix ) + "jet_flavor_weight_IP2D" );
      jet_flavor_weight_IP3D.SetName( ::TString( prefix ) + "jet_flavor_weight_IP3D" );
      jet_flavor_weight_SV0.SetName( ::TString( prefix ) + "jet_flavor_weight_SV0" );
      jet_flavor_weight_SV1.SetName( ::TString( prefix ) + "jet_flavor_weight_SV1" );
      jet_flavor_weight_SV2.SetName( ::TString( prefix ) + "jet_flavor_weight_SV2" );
      jet_flavor_weight_JetFitterTag.SetName( ::TString( prefix ) + "jet_flavor_weight_JetFitterTag" );
      jet_flavor_weight_JetFitterCOMB.SetName( ::TString( prefix ) + "jet_flavor_weight_JetFitterCOMB" );
      jet_flavor_weight_JetFitterTagNN.SetName( ::TString( prefix ) + "jet_flavor_weight_JetFitterTagNN" );
      jet_flavor_weight_JetFitterCOMBNN.SetName( ::TString( prefix ) + "jet_flavor_weight_JetFitterCOMBNN" );
      jet_flavor_weight_SoftMuonTag.SetName( ::TString( prefix ) + "jet_flavor_weight_SoftMuonTag" );
      jet_flavor_weight_SoftElectronTag.SetName( ::TString( prefix ) + "jet_flavor_weight_SoftElectronTag" );
      jet_flavor_weight_IP3DSV1.SetName( ::TString( prefix ) + "jet_flavor_weight_IP3DSV1" );
      jet_e_PreSamplerB.SetName( ::TString( prefix ) + "jet_e_PreSamplerB" );
      jet_e_EMB1.SetName( ::TString( prefix ) + "jet_e_EMB1" );
      jet_e_EMB2.SetName( ::TString( prefix ) + "jet_e_EMB2" );
      jet_e_EMB3.SetName( ::TString( prefix ) + "jet_e_EMB3" );
      jet_e_PreSamplerE.SetName( ::TString( prefix ) + "jet_e_PreSamplerE" );
      jet_e_EME1.SetName( ::TString( prefix ) + "jet_e_EME1" );
      jet_e_EME2.SetName( ::TString( prefix ) + "jet_e_EME2" );
      jet_e_EME3.SetName( ::TString( prefix ) + "jet_e_EME3" );
      jet_e_HEC0.SetName( ::TString( prefix ) + "jet_e_HEC0" );
      jet_e_HEC1.SetName( ::TString( prefix ) + "jet_e_HEC1" );
      jet_e_HEC2.SetName( ::TString( prefix ) + "jet_e_HEC2" );
      jet_e_HEC3.SetName( ::TString( prefix ) + "jet_e_HEC3" );
      jet_e_TileBar0.SetName( ::TString( prefix ) + "jet_e_TileBar0" );
      jet_e_TileBar1.SetName( ::TString( prefix ) + "jet_e_TileBar1" );
      jet_e_TileBar2.SetName( ::TString( prefix ) + "jet_e_TileBar2" );
      jet_e_TileGap1.SetName( ::TString( prefix ) + "jet_e_TileGap1" );
      jet_e_TileGap2.SetName( ::TString( prefix ) + "jet_e_TileGap2" );
      jet_e_TileGap3.SetName( ::TString( prefix ) + "jet_e_TileGap3" );
      jet_e_TileExt0.SetName( ::TString( prefix ) + "jet_e_TileExt0" );
      jet_e_TileExt1.SetName( ::TString( prefix ) + "jet_e_TileExt1" );
      jet_e_TileExt2.SetName( ::TString( prefix ) + "jet_e_TileExt2" );
      jet_e_FCAL0.SetName( ::TString( prefix ) + "jet_e_FCAL0" );
      jet_e_FCAL1.SetName( ::TString( prefix ) + "jet_e_FCAL1" );
      jet_e_FCAL2.SetName( ::TString( prefix ) + "jet_e_FCAL2" );
      jet_shapeBins.SetName( ::TString( prefix ) + "jet_shapeBins" );
      track_atTJVA_n.SetName( ::TString( prefix ) + "track_atTJVA_n" );
      track_atTJVA_d0.SetName( ::TString( prefix ) + "track_atTJVA_d0" );
      track_atTJVA_z0.SetName( ::TString( prefix ) + "track_atTJVA_z0" );
      track_atTJVA_phi.SetName( ::TString( prefix ) + "track_atTJVA_phi" );
      track_atTJVA_theta.SetName( ::TString( prefix ) + "track_atTJVA_theta" );
      track_atTJVA_qoverp.SetName( ::TString( prefix ) + "track_atTJVA_qoverp" );
      track_atTJVA_pt.SetName( ::TString( prefix ) + "track_atTJVA_pt" );
      track_atTJVA_eta.SetName( ::TString( prefix ) + "track_atTJVA_eta" );
      seedCalo_wideTrk_atTJVA_n.SetName( ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_n" );
      seedCalo_wideTrk_atTJVA_d0.SetName( ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_d0" );
      seedCalo_wideTrk_atTJVA_z0.SetName( ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_z0" );
      seedCalo_wideTrk_atTJVA_phi.SetName( ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_phi" );
      seedCalo_wideTrk_atTJVA_theta.SetName( ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_theta" );
      seedCalo_wideTrk_atTJVA_qoverp.SetName( ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_qoverp" );
      seedCalo_wideTrk_atTJVA_pt.SetName( ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_pt" );
      seedCalo_wideTrk_atTJVA_eta.SetName( ::TString( prefix ) + "seedCalo_wideTrk_atTJVA_eta" );
      otherTrk_atTJVA_n.SetName( ::TString( prefix ) + "otherTrk_atTJVA_n" );
      track_n.SetName( ::TString( prefix ) + "track_n" );
      track_d0.SetName( ::TString( prefix ) + "track_d0" );
      track_z0.SetName( ::TString( prefix ) + "track_z0" );
      track_phi.SetName( ::TString( prefix ) + "track_phi" );
      track_theta.SetName( ::TString( prefix ) + "track_theta" );
      track_qoverp.SetName( ::TString( prefix ) + "track_qoverp" );
      track_pt.SetName( ::TString( prefix ) + "track_pt" );
      track_eta.SetName( ::TString( prefix ) + "track_eta" );
      track_atPV_d0.SetName( ::TString( prefix ) + "track_atPV_d0" );
      track_atPV_z0.SetName( ::TString( prefix ) + "track_atPV_z0" );
      track_atPV_phi.SetName( ::TString( prefix ) + "track_atPV_phi" );
      track_atPV_theta.SetName( ::TString( prefix ) + "track_atPV_theta" );
      track_atPV_qoverp.SetName( ::TString( prefix ) + "track_atPV_qoverp" );
      track_atPV_pt.SetName( ::TString( prefix ) + "track_atPV_pt" );
      track_atPV_eta.SetName( ::TString( prefix ) + "track_atPV_eta" );
      track_nBLHits.SetName( ::TString( prefix ) + "track_nBLHits" );
      track_nPixHits.SetName( ::TString( prefix ) + "track_nPixHits" );
      track_nSCTHits.SetName( ::TString( prefix ) + "track_nSCTHits" );
      track_nTRTHits.SetName( ::TString( prefix ) + "track_nTRTHits" );
      track_nTRTHighTHits.SetName( ::TString( prefix ) + "track_nTRTHighTHits" );
      track_nTRTXenonHits.SetName( ::TString( prefix ) + "track_nTRTXenonHits" );
      track_nPixHoles.SetName( ::TString( prefix ) + "track_nPixHoles" );
      track_nSCTHoles.SetName( ::TString( prefix ) + "track_nSCTHoles" );
      track_nTRTHoles.SetName( ::TString( prefix ) + "track_nTRTHoles" );
      track_nPixelDeadSensors.SetName( ::TString( prefix ) + "track_nPixelDeadSensors" );
      track_nSCTDeadSensors.SetName( ::TString( prefix ) + "track_nSCTDeadSensors" );
      track_nBLSharedHits.SetName( ::TString( prefix ) + "track_nBLSharedHits" );
      track_nPixSharedHits.SetName( ::TString( prefix ) + "track_nPixSharedHits" );
      track_nSCTSharedHits.SetName( ::TString( prefix ) + "track_nSCTSharedHits" );
      track_nBLayerSplitHits.SetName( ::TString( prefix ) + "track_nBLayerSplitHits" );
      track_nPixSplitHits.SetName( ::TString( prefix ) + "track_nPixSplitHits" );
      track_nBLayerOutliers.SetName( ::TString( prefix ) + "track_nBLayerOutliers" );
      track_nPixelOutliers.SetName( ::TString( prefix ) + "track_nPixelOutliers" );
      track_nSCTOutliers.SetName( ::TString( prefix ) + "track_nSCTOutliers" );
      track_nTRTOutliers.SetName( ::TString( prefix ) + "track_nTRTOutliers" );
      track_nTRTHighTOutliers.SetName( ::TString( prefix ) + "track_nTRTHighTOutliers" );
      track_nContribPixelLayers.SetName( ::TString( prefix ) + "track_nContribPixelLayers" );
      track_nGangedPixels.SetName( ::TString( prefix ) + "track_nGangedPixels" );
      track_nGangedFlaggedFakes.SetName( ::TString( prefix ) + "track_nGangedFlaggedFakes" );
      track_nPixelSpoiltHits.SetName( ::TString( prefix ) + "track_nPixelSpoiltHits" );
      track_nSCTDoubleHoles.SetName( ::TString( prefix ) + "track_nSCTDoubleHoles" );
      track_nSCTSpoiltHits.SetName( ::TString( prefix ) + "track_nSCTSpoiltHits" );
      track_expectBLayerHit.SetName( ::TString( prefix ) + "track_expectBLayerHit" );
      track_nHits.SetName( ::TString( prefix ) + "track_nHits" );
      track_TRTHighTHitsRatio.SetName( ::TString( prefix ) + "track_TRTHighTHitsRatio" );
      track_TRTHighTOutliersRatio.SetName( ::TString( prefix ) + "track_TRTHighTOutliersRatio" );
      seedCalo_track_n.SetName( ::TString( prefix ) + "seedCalo_track_n" );
      seedCalo_wideTrk_n.SetName( ::TString( prefix ) + "seedCalo_wideTrk_n" );
      seedCalo_wideTrk_nBLHits.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nBLHits" );
      seedCalo_wideTrk_nPixHits.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nPixHits" );
      seedCalo_wideTrk_nSCTHits.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nSCTHits" );
      seedCalo_wideTrk_nTRTHits.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nTRTHits" );
      seedCalo_wideTrk_nTRTHighTHits.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nTRTHighTHits" );
      seedCalo_wideTrk_nTRTXenonHits.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nTRTXenonHits" );
      seedCalo_wideTrk_nPixHoles.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nPixHoles" );
      seedCalo_wideTrk_nSCTHoles.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nSCTHoles" );
      seedCalo_wideTrk_nTRTHoles.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nTRTHoles" );
      seedCalo_wideTrk_nPixelDeadSensors.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nPixelDeadSensors" );
      seedCalo_wideTrk_nSCTDeadSensors.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nSCTDeadSensors" );
      seedCalo_wideTrk_nBLSharedHits.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nBLSharedHits" );
      seedCalo_wideTrk_nPixSharedHits.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nPixSharedHits" );
      seedCalo_wideTrk_nSCTSharedHits.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nSCTSharedHits" );
      seedCalo_wideTrk_nBLayerSplitHits.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nBLayerSplitHits" );
      seedCalo_wideTrk_nPixSplitHits.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nPixSplitHits" );
      seedCalo_wideTrk_nBLayerOutliers.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nBLayerOutliers" );
      seedCalo_wideTrk_nPixelOutliers.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nPixelOutliers" );
      seedCalo_wideTrk_nSCTOutliers.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nSCTOutliers" );
      seedCalo_wideTrk_nTRTOutliers.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nTRTOutliers" );
      seedCalo_wideTrk_nTRTHighTOutliers.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nTRTHighTOutliers" );
      seedCalo_wideTrk_nContribPixelLayers.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nContribPixelLayers" );
      seedCalo_wideTrk_nGangedPixels.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nGangedPixels" );
      seedCalo_wideTrk_nGangedFlaggedFakes.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nGangedFlaggedFakes" );
      seedCalo_wideTrk_nPixelSpoiltHits.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nPixelSpoiltHits" );
      seedCalo_wideTrk_nSCTDoubleHoles.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nSCTDoubleHoles" );
      seedCalo_wideTrk_nSCTSpoiltHits.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nSCTSpoiltHits" );
      seedCalo_wideTrk_expectBLayerHit.SetName( ::TString( prefix ) + "seedCalo_wideTrk_expectBLayerHit" );
      seedCalo_wideTrk_nHits.SetName( ::TString( prefix ) + "seedCalo_wideTrk_nHits" );
      otherTrk_n.SetName( ::TString( prefix ) + "otherTrk_n" );
      EF_dr.SetName( ::TString( prefix ) + "EF_dr" );
      EF_E.SetName( ::TString( prefix ) + "EF_E" );
      EF_Et.SetName( ::TString( prefix ) + "EF_Et" );
      EF_pt.SetName( ::TString( prefix ) + "EF_pt" );
      EF_eta.SetName( ::TString( prefix ) + "EF_eta" );
      EF_phi.SetName( ::TString( prefix ) + "EF_phi" );
      EF_matched.SetName( ::TString( prefix ) + "EF_matched" );
      L2_dr.SetName( ::TString( prefix ) + "L2_dr" );
      L2_E.SetName( ::TString( prefix ) + "L2_E" );
      L2_Et.SetName( ::TString( prefix ) + "L2_Et" );
      L2_pt.SetName( ::TString( prefix ) + "L2_pt" );
      L2_eta.SetName( ::TString( prefix ) + "L2_eta" );
      L2_phi.SetName( ::TString( prefix ) + "L2_phi" );
      L2_matched.SetName( ::TString( prefix ) + "L2_matched" );
      L1_dr.SetName( ::TString( prefix ) + "L1_dr" );
      L1_Et.SetName( ::TString( prefix ) + "L1_Et" );
      L1_pt.SetName( ::TString( prefix ) + "L1_pt" );
      L1_eta.SetName( ::TString( prefix ) + "L1_eta" );
      L1_phi.SetName( ::TString( prefix ) + "L1_phi" );
      L1_matched.SetName( ::TString( prefix ) + "L1_matched" );
if (!is_data) {
      trueTauAssocSmall_dr.SetName( ::TString( prefix ) + "trueTauAssocSmall_dr" );
      trueTauAssocSmall_index.SetName( ::TString( prefix ) + "trueTauAssocSmall_index" );
      trueTauAssocSmall_matched.SetName( ::TString( prefix ) + "trueTauAssocSmall_matched" );
} // end !is_data
      MET_Egamma10LooseTau_wpx.SetName( ::TString( prefix ) + "MET_Egamma10LooseTau_wpx" );
      MET_Egamma10LooseTau_wpy.SetName( ::TString( prefix ) + "MET_Egamma10LooseTau_wpy" );
      MET_Egamma10LooseTau_wet.SetName( ::TString( prefix ) + "MET_Egamma10LooseTau_wet" );
      MET_Egamma10LooseTau_statusWord.SetName( ::TString( prefix ) + "MET_Egamma10LooseTau_statusWord" );
      MET_wpx.SetName( ::TString( prefix ) + "MET_wpx" );
      MET_wpy.SetName( ::TString( prefix ) + "MET_wpy" );
      MET_wet.SetName( ::TString( prefix ) + "MET_wet" );
      MET_statusWord.SetName( ::TString( prefix ) + "MET_statusWord" );
      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void TauD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      n.ReadFrom( tree );
      Et.ReadFrom( tree );
      pt.ReadFrom( tree );
      m.ReadFrom( tree );
      eta.ReadFrom( tree );
      phi.ReadFrom( tree );
      charge.ReadFrom( tree );
      BDTEleScore.ReadFrom( tree );
      BDTJetScore.ReadFrom( tree );
      likelihood.ReadFrom( tree );
      SafeLikelihood.ReadFrom( tree );
      electronVetoLoose.ReadFrom( tree );
      electronVetoMedium.ReadFrom( tree );
      electronVetoTight.ReadFrom( tree );
      muonVeto.ReadFrom( tree );
      tauLlhLoose.ReadFrom( tree );
      tauLlhMedium.ReadFrom( tree );
      tauLlhTight.ReadFrom( tree );
      JetBDTSigLoose.ReadFrom( tree );
      JetBDTSigMedium.ReadFrom( tree );
      JetBDTSigTight.ReadFrom( tree );
      EleBDTLoose.ReadFrom( tree );
      EleBDTMedium.ReadFrom( tree );
      EleBDTTight.ReadFrom( tree );
      author.ReadFrom( tree );
      RoIWord.ReadFrom( tree );
      nProng.ReadFrom( tree );
      numTrack.ReadFrom( tree );
      seedCalo_numTrack.ReadFrom( tree );
      seedCalo_nWideTrk.ReadFrom( tree );
      nOtherTrk.ReadFrom( tree );
      etOverPtLeadTrk.ReadFrom( tree );
      ipZ0SinThetaSigLeadTrk.ReadFrom( tree );
      leadTrkPt.ReadFrom( tree );
      nLooseTrk.ReadFrom( tree );
      nLooseConvTrk.ReadFrom( tree );
      nProngLoose.ReadFrom( tree );
      ipSigLeadTrk.ReadFrom( tree );
      ipSigLeadLooseTrk.ReadFrom( tree );
      etOverPtLeadLooseTrk.ReadFrom( tree );
      leadLooseTrkPt.ReadFrom( tree );
      chrgLooseTrk.ReadFrom( tree );
      massTrkSys.ReadFrom( tree );
      trkWidth2.ReadFrom( tree );
      trFlightPathSig.ReadFrom( tree );
      etEflow.ReadFrom( tree );
      mEflow.ReadFrom( tree );
      nPi0.ReadFrom( tree );
      ele_E237E277.ReadFrom( tree );
      ele_PresamplerFraction.ReadFrom( tree );
      ele_ECALFirstFraction.ReadFrom( tree );
      EM_TES_scale.ReadFrom( tree );
      LC_TES_precalib.ReadFrom( tree );
      TRTHTOverLT_LeadTrk.ReadFrom( tree );
      seedCalo_EMRadius.ReadFrom( tree );
      seedCalo_hadRadius.ReadFrom( tree );
      seedCalo_etEMAtEMScale.ReadFrom( tree );
      seedCalo_etHadAtEMScale.ReadFrom( tree );
      seedCalo_isolFrac.ReadFrom( tree );
      seedCalo_centFrac.ReadFrom( tree );
      seedCalo_stripWidth2.ReadFrom( tree );
      seedCalo_nStrip.ReadFrom( tree );
      seedCalo_eta.ReadFrom( tree );
      seedCalo_phi.ReadFrom( tree );
      seedCalo_nIsolLooseTrk.ReadFrom( tree );
      seedCalo_trkAvgDist.ReadFrom( tree );
      seedCalo_trkRmsDist.ReadFrom( tree );
      seedCalo_caloIso.ReadFrom( tree );
      seedCalo_caloIsoCorrected.ReadFrom( tree );
      seedCalo_dRmax.ReadFrom( tree );
      seedCalo_lead2ClusterEOverAllClusterE.ReadFrom( tree );
      seedCalo_lead3ClusterEOverAllClusterE.ReadFrom( tree );
      seedCalo_etHadCalib.ReadFrom( tree );
      seedCalo_etEMCalib.ReadFrom( tree );
      numTopoClusters.ReadFrom( tree );
      numEffTopoClusters.ReadFrom( tree );
      topoInvMass.ReadFrom( tree );
      effTopoInvMass.ReadFrom( tree );
      topoMeanDeltaR.ReadFrom( tree );
      effTopoMeanDeltaR.ReadFrom( tree );
      numCells.ReadFrom( tree );
      seedTrk_EMRadius.ReadFrom( tree );
      seedTrk_isolFrac.ReadFrom( tree );
      seedTrk_etChrgHadOverSumTrkPt.ReadFrom( tree );
      seedTrk_isolFracWide.ReadFrom( tree );
      seedTrk_etHadAtEMScale.ReadFrom( tree );
      seedTrk_etEMAtEMScale.ReadFrom( tree );
      seedTrk_etEMCL.ReadFrom( tree );
      seedTrk_etChrgEM.ReadFrom( tree );
      seedTrk_etNeuEM.ReadFrom( tree );
      seedTrk_etResNeuEM.ReadFrom( tree );
      seedTrk_hadLeakEt.ReadFrom( tree );
      seedTrk_sumEMCellEtOverLeadTrkPt.ReadFrom( tree );
      seedTrk_secMaxStripEt.ReadFrom( tree );
      seedTrk_stripWidth2.ReadFrom( tree );
      seedTrk_nStrip.ReadFrom( tree );
      seedTrk_etChrgHad.ReadFrom( tree );
      seedTrk_nOtherCoreTrk.ReadFrom( tree );
      seedTrk_nIsolTrk.ReadFrom( tree );
      seedTrk_etIsolEM.ReadFrom( tree );
      seedTrk_etIsolHad.ReadFrom( tree );
      cellBasedEnergyRing1.ReadFrom( tree );
      cellBasedEnergyRing2.ReadFrom( tree );
      cellBasedEnergyRing3.ReadFrom( tree );
      cellBasedEnergyRing4.ReadFrom( tree );
      cellBasedEnergyRing5.ReadFrom( tree );
      cellBasedEnergyRing6.ReadFrom( tree );
      cellBasedEnergyRing7.ReadFrom( tree );
      calcVars_etHad_EMScale_Pt3Trks.ReadFrom( tree );
      calcVars_etEM_EMScale_Pt3Trks.ReadFrom( tree );
      calcVars_ipSigLeadLooseTrk.ReadFrom( tree );
      calcVars_drMin.ReadFrom( tree );
      calcVars_calRadius.ReadFrom( tree );
      calcVars_EMFractionAtEMScale.ReadFrom( tree );
      calcVars_trackIso.ReadFrom( tree );
      calcVars_ChPiEMEOverCaloEME.ReadFrom( tree );
      calcVars_PSSFraction.ReadFrom( tree );
      calcVars_EMPOverTrkSysP.ReadFrom( tree );
      calcVars_pi0BDTPrimaryScore.ReadFrom( tree );
      calcVars_pi0BDTSecondaryScore.ReadFrom( tree );
      calcVars_corrCentFrac.ReadFrom( tree );
      calcVars_corrFTrk.ReadFrom( tree );
      calcVars_interAxis_eta.ReadFrom( tree );
      calcVars_interAxis_phi.ReadFrom( tree );
      pi0_cl1_pt.ReadFrom( tree );
      pi0_cl1_eta.ReadFrom( tree );
      pi0_cl1_phi.ReadFrom( tree );
      pi0_cl2_pt.ReadFrom( tree );
      pi0_cl2_eta.ReadFrom( tree );
      pi0_cl2_phi.ReadFrom( tree );
      pi0_vistau_pt.ReadFrom( tree );
      pi0_vistau_eta.ReadFrom( tree );
      pi0_vistau_phi.ReadFrom( tree );
      pi0_vistau_m.ReadFrom( tree );
      pi0_n.ReadFrom( tree );
      pantau_isPanTauCandidate.ReadFrom( tree );
      pantau_PanTauScore.ReadFrom( tree );
      pantau_NChargedEFO.ReadFrom( tree );
      pantau_NChargedQualifiedEFO.ReadFrom( tree );
      pantau_NNeutralEFO.ReadFrom( tree );
      pantau_AbsSumCharge.ReadFrom( tree );
      pantau_EflowJetMomentDRAll.ReadFrom( tree );
      pantau_EflowJetMomentDRChrg.ReadFrom( tree );
      pantau_EflowJetMomentDREMNeut.ReadFrom( tree );
      pantau_EflowJetMomentDRHADNeut.ReadFrom( tree );
      pantau_EtIn01OverEtIn02InvSigm.ReadFrom( tree );
      pantau_EtIn02To04OverTotalEtInvSigm.ReadFrom( tree );
      pantau_EtIn01OverEtIn04InvSigm.ReadFrom( tree );
      pantau_EtIn01OverEtIn04.ReadFrom( tree );
      pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents.ReadFrom( tree );
      pantau_JetSphericity.ReadFrom( tree );
      pantau_TransImpactParamSignfTrack1.ReadFrom( tree );
      pantau_EflowAngleJetAxisLeadingChargedQualified.ReadFrom( tree );
      pantau_EflowAngleChargedAxisNeutralAxis.ReadFrom( tree );
      pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified.ReadFrom( tree );
      pantau_EflowInvariantMassAll.ReadFrom( tree );
      pantau_EflowStdDevEtToSumEt.ReadFrom( tree );
      pantau_EflowEtLeadingChrgQualifiedOverTotalEt.ReadFrom( tree );
      pantau_EflowSumEAll.ReadFrom( tree );
      pantau_EflowChargedSumEt.ReadFrom( tree );
      leadTrack_eta.ReadFrom( tree );
      leadTrack_phi.ReadFrom( tree );
      cluster_E.ReadFrom( tree );
      cluster_eta.ReadFrom( tree );
      cluster_phi.ReadFrom( tree );
      cluster_eta_atTJVA.ReadFrom( tree );
      cluster_phi_atTJVA.ReadFrom( tree );
      cluster_PreSamplerStripF.ReadFrom( tree );
      cluster_EMLayer2F.ReadFrom( tree );
      cluster_EMLayer3F.ReadFrom( tree );
      cluster_n.ReadFrom( tree );
      Pi0Cluster_pt.ReadFrom( tree );
      Pi0Cluster_eta.ReadFrom( tree );
      Pi0Cluster_phi.ReadFrom( tree );
      secvtx_x.ReadFrom( tree );
      secvtx_y.ReadFrom( tree );
      secvtx_z.ReadFrom( tree );
      secvtx_xx.ReadFrom( tree );
      secvtx_yy.ReadFrom( tree );
      secvtx_zz.ReadFrom( tree );
      secvtx_xy.ReadFrom( tree );
      secvtx_yz.ReadFrom( tree );
      secvtx_zx.ReadFrom( tree );
      secvtx_chiSquared.ReadFrom( tree );
      secvtx_numberDoF.ReadFrom( tree );
      privtx_x.ReadFrom( tree );
      privtx_y.ReadFrom( tree );
      privtx_z.ReadFrom( tree );
      privtx_xx.ReadFrom( tree );
      privtx_yy.ReadFrom( tree );
      privtx_zz.ReadFrom( tree );
      privtx_xy.ReadFrom( tree );
      privtx_yz.ReadFrom( tree );
      privtx_zx.ReadFrom( tree );
      privtx_chiSquared.ReadFrom( tree );
      privtx_numberDoF.ReadFrom( tree );
      privtx_jvf.ReadFrom( tree );
      jet_Et.ReadFrom( tree );
      jet_pt.ReadFrom( tree );
      jet_m.ReadFrom( tree );
      jet_eta.ReadFrom( tree );
      jet_phi.ReadFrom( tree );
      jet_WIDTH.ReadFrom( tree );
      jet_n90.ReadFrom( tree );
      jet_n90constituents.ReadFrom( tree );
      jet_BCH_CORR_CELL.ReadFrom( tree );
      jet_BCH_CORR_JET.ReadFrom( tree );
      jet_BCH_CORR_JET_FORCELL.ReadFrom( tree );
      jet_ENG_BAD_CELLS.ReadFrom( tree );
      jet_N_BAD_CELLS.ReadFrom( tree );
      jet_N_BAD_CELLS_CORR.ReadFrom( tree );
      jet_BAD_CELLS_CORR_E.ReadFrom( tree );
      jet_Timing.ReadFrom( tree );
      jet_LArQuality.ReadFrom( tree );
      jet_nTrk.ReadFrom( tree );
      jet_sumPtTrk.ReadFrom( tree );
      jet_OriginIndex.ReadFrom( tree );
      jet_HECQuality.ReadFrom( tree );
      jet_NegativeE.ReadFrom( tree );
      jet_YFlip12.ReadFrom( tree );
      jet_YFlip23.ReadFrom( tree );
      jet_BCH_CORR_DOTX.ReadFrom( tree );
      jet_SamplingMax.ReadFrom( tree );
      jet_fracSamplingMax.ReadFrom( tree );
      jet_hecf.ReadFrom( tree );
      jet_tgap3f.ReadFrom( tree );
      jet_isUgly.ReadFrom( tree );
      jet_isBadLooseMinus.ReadFrom( tree );
      jet_isBadLoose.ReadFrom( tree );
      jet_isBadMedium.ReadFrom( tree );
      jet_isBadTight.ReadFrom( tree );
      jet_emfrac.ReadFrom( tree );
      jet_GCWJES.ReadFrom( tree );
      jet_EMJES.ReadFrom( tree );
      jet_emscale_E.ReadFrom( tree );
      jet_emscale_pt.ReadFrom( tree );
      jet_emscale_m.ReadFrom( tree );
      jet_emscale_eta.ReadFrom( tree );
      jet_emscale_phi.ReadFrom( tree );
      jet_jvtx_x.ReadFrom( tree );
      jet_jvtx_y.ReadFrom( tree );
      jet_jvtx_z.ReadFrom( tree );
      jet_jvtxf.ReadFrom( tree );
      jet_flavor_weight.ReadFrom( tree );
      jet_flavor_weight_TrackCounting2D.ReadFrom( tree );
      jet_flavor_weight_JetProb.ReadFrom( tree );
      jet_flavor_weight_IP1D.ReadFrom( tree );
      jet_flavor_weight_IP2D.ReadFrom( tree );
      jet_flavor_weight_IP3D.ReadFrom( tree );
      jet_flavor_weight_SV0.ReadFrom( tree );
      jet_flavor_weight_SV1.ReadFrom( tree );
      jet_flavor_weight_SV2.ReadFrom( tree );
      jet_flavor_weight_JetFitterTag.ReadFrom( tree );
      jet_flavor_weight_JetFitterCOMB.ReadFrom( tree );
      jet_flavor_weight_JetFitterTagNN.ReadFrom( tree );
      jet_flavor_weight_JetFitterCOMBNN.ReadFrom( tree );
      jet_flavor_weight_SoftMuonTag.ReadFrom( tree );
      jet_flavor_weight_SoftElectronTag.ReadFrom( tree );
      jet_flavor_weight_IP3DSV1.ReadFrom( tree );
      jet_e_PreSamplerB.ReadFrom( tree );
      jet_e_EMB1.ReadFrom( tree );
      jet_e_EMB2.ReadFrom( tree );
      jet_e_EMB3.ReadFrom( tree );
      jet_e_PreSamplerE.ReadFrom( tree );
      jet_e_EME1.ReadFrom( tree );
      jet_e_EME2.ReadFrom( tree );
      jet_e_EME3.ReadFrom( tree );
      jet_e_HEC0.ReadFrom( tree );
      jet_e_HEC1.ReadFrom( tree );
      jet_e_HEC2.ReadFrom( tree );
      jet_e_HEC3.ReadFrom( tree );
      jet_e_TileBar0.ReadFrom( tree );
      jet_e_TileBar1.ReadFrom( tree );
      jet_e_TileBar2.ReadFrom( tree );
      jet_e_TileGap1.ReadFrom( tree );
      jet_e_TileGap2.ReadFrom( tree );
      jet_e_TileGap3.ReadFrom( tree );
      jet_e_TileExt0.ReadFrom( tree );
      jet_e_TileExt1.ReadFrom( tree );
      jet_e_TileExt2.ReadFrom( tree );
      jet_e_FCAL0.ReadFrom( tree );
      jet_e_FCAL1.ReadFrom( tree );
      jet_e_FCAL2.ReadFrom( tree );
      jet_shapeBins.ReadFrom( tree );
      track_atTJVA_n.ReadFrom( tree );
      track_atTJVA_d0.ReadFrom( tree );
      track_atTJVA_z0.ReadFrom( tree );
      track_atTJVA_phi.ReadFrom( tree );
      track_atTJVA_theta.ReadFrom( tree );
      track_atTJVA_qoverp.ReadFrom( tree );
      track_atTJVA_pt.ReadFrom( tree );
      track_atTJVA_eta.ReadFrom( tree );
      seedCalo_wideTrk_atTJVA_n.ReadFrom( tree );
      seedCalo_wideTrk_atTJVA_d0.ReadFrom( tree );
      seedCalo_wideTrk_atTJVA_z0.ReadFrom( tree );
      seedCalo_wideTrk_atTJVA_phi.ReadFrom( tree );
      seedCalo_wideTrk_atTJVA_theta.ReadFrom( tree );
      seedCalo_wideTrk_atTJVA_qoverp.ReadFrom( tree );
      seedCalo_wideTrk_atTJVA_pt.ReadFrom( tree );
      seedCalo_wideTrk_atTJVA_eta.ReadFrom( tree );
      otherTrk_atTJVA_n.ReadFrom( tree );
      track_n.ReadFrom( tree );
      track_d0.ReadFrom( tree );
      track_z0.ReadFrom( tree );
      track_phi.ReadFrom( tree );
      track_theta.ReadFrom( tree );
      track_qoverp.ReadFrom( tree );
      track_pt.ReadFrom( tree );
      track_eta.ReadFrom( tree );
      track_atPV_d0.ReadFrom( tree );
      track_atPV_z0.ReadFrom( tree );
      track_atPV_phi.ReadFrom( tree );
      track_atPV_theta.ReadFrom( tree );
      track_atPV_qoverp.ReadFrom( tree );
      track_atPV_pt.ReadFrom( tree );
      track_atPV_eta.ReadFrom( tree );
      track_nBLHits.ReadFrom( tree );
      track_nPixHits.ReadFrom( tree );
      track_nSCTHits.ReadFrom( tree );
      track_nTRTHits.ReadFrom( tree );
      track_nTRTHighTHits.ReadFrom( tree );
      track_nTRTXenonHits.ReadFrom( tree );
      track_nPixHoles.ReadFrom( tree );
      track_nSCTHoles.ReadFrom( tree );
      track_nTRTHoles.ReadFrom( tree );
      track_nPixelDeadSensors.ReadFrom( tree );
      track_nSCTDeadSensors.ReadFrom( tree );
      track_nBLSharedHits.ReadFrom( tree );
      track_nPixSharedHits.ReadFrom( tree );
      track_nSCTSharedHits.ReadFrom( tree );
      track_nBLayerSplitHits.ReadFrom( tree );
      track_nPixSplitHits.ReadFrom( tree );
      track_nBLayerOutliers.ReadFrom( tree );
      track_nPixelOutliers.ReadFrom( tree );
      track_nSCTOutliers.ReadFrom( tree );
      track_nTRTOutliers.ReadFrom( tree );
      track_nTRTHighTOutliers.ReadFrom( tree );
      track_nContribPixelLayers.ReadFrom( tree );
      track_nGangedPixels.ReadFrom( tree );
      track_nGangedFlaggedFakes.ReadFrom( tree );
      track_nPixelSpoiltHits.ReadFrom( tree );
      track_nSCTDoubleHoles.ReadFrom( tree );
      track_nSCTSpoiltHits.ReadFrom( tree );
      track_expectBLayerHit.ReadFrom( tree );
      track_nHits.ReadFrom( tree );
      track_TRTHighTHitsRatio.ReadFrom( tree );
      track_TRTHighTOutliersRatio.ReadFrom( tree );
      seedCalo_track_n.ReadFrom( tree );
      seedCalo_wideTrk_n.ReadFrom( tree );
      seedCalo_wideTrk_nBLHits.ReadFrom( tree );
      seedCalo_wideTrk_nPixHits.ReadFrom( tree );
      seedCalo_wideTrk_nSCTHits.ReadFrom( tree );
      seedCalo_wideTrk_nTRTHits.ReadFrom( tree );
      seedCalo_wideTrk_nTRTHighTHits.ReadFrom( tree );
      seedCalo_wideTrk_nTRTXenonHits.ReadFrom( tree );
      seedCalo_wideTrk_nPixHoles.ReadFrom( tree );
      seedCalo_wideTrk_nSCTHoles.ReadFrom( tree );
      seedCalo_wideTrk_nTRTHoles.ReadFrom( tree );
      seedCalo_wideTrk_nPixelDeadSensors.ReadFrom( tree );
      seedCalo_wideTrk_nSCTDeadSensors.ReadFrom( tree );
      seedCalo_wideTrk_nBLSharedHits.ReadFrom( tree );
      seedCalo_wideTrk_nPixSharedHits.ReadFrom( tree );
      seedCalo_wideTrk_nSCTSharedHits.ReadFrom( tree );
      seedCalo_wideTrk_nBLayerSplitHits.ReadFrom( tree );
      seedCalo_wideTrk_nPixSplitHits.ReadFrom( tree );
      seedCalo_wideTrk_nBLayerOutliers.ReadFrom( tree );
      seedCalo_wideTrk_nPixelOutliers.ReadFrom( tree );
      seedCalo_wideTrk_nSCTOutliers.ReadFrom( tree );
      seedCalo_wideTrk_nTRTOutliers.ReadFrom( tree );
      seedCalo_wideTrk_nTRTHighTOutliers.ReadFrom( tree );
      seedCalo_wideTrk_nContribPixelLayers.ReadFrom( tree );
      seedCalo_wideTrk_nGangedPixels.ReadFrom( tree );
      seedCalo_wideTrk_nGangedFlaggedFakes.ReadFrom( tree );
      seedCalo_wideTrk_nPixelSpoiltHits.ReadFrom( tree );
      seedCalo_wideTrk_nSCTDoubleHoles.ReadFrom( tree );
      seedCalo_wideTrk_nSCTSpoiltHits.ReadFrom( tree );
      seedCalo_wideTrk_expectBLayerHit.ReadFrom( tree );
      seedCalo_wideTrk_nHits.ReadFrom( tree );
      otherTrk_n.ReadFrom( tree );
      EF_dr.ReadFrom( tree );
      EF_E.ReadFrom( tree );
      EF_Et.ReadFrom( tree );
      EF_pt.ReadFrom( tree );
      EF_eta.ReadFrom( tree );
      EF_phi.ReadFrom( tree );
      EF_matched.ReadFrom( tree );
      L2_dr.ReadFrom( tree );
      L2_E.ReadFrom( tree );
      L2_Et.ReadFrom( tree );
      L2_pt.ReadFrom( tree );
      L2_eta.ReadFrom( tree );
      L2_phi.ReadFrom( tree );
      L2_matched.ReadFrom( tree );
      L1_dr.ReadFrom( tree );
      L1_Et.ReadFrom( tree );
      L1_pt.ReadFrom( tree );
      L1_eta.ReadFrom( tree );
      L1_phi.ReadFrom( tree );
      L1_matched.ReadFrom( tree );
if (!is_data) {
      trueTauAssocSmall_dr.ReadFrom( tree );
      trueTauAssocSmall_index.ReadFrom( tree );
      trueTauAssocSmall_matched.ReadFrom( tree );
} // end !is_data
      MET_Egamma10LooseTau_wpx.ReadFrom( tree );
      MET_Egamma10LooseTau_wpy.ReadFrom( tree );
      MET_Egamma10LooseTau_wet.ReadFrom( tree );
      MET_Egamma10LooseTau_statusWord.ReadFrom( tree );
      MET_wpx.ReadFrom( tree );
      MET_wpy.ReadFrom( tree );
      MET_wet.ReadFrom( tree );
      MET_statusWord.ReadFrom( tree );

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void TauD3PDObject::WriteTo( TTree* tree ) {

      n.WriteTo( tree );
      Et.WriteTo( tree );
      pt.WriteTo( tree );
      m.WriteTo( tree );
      eta.WriteTo( tree );
      phi.WriteTo( tree );
      charge.WriteTo( tree );
      BDTEleScore.WriteTo( tree );
      BDTJetScore.WriteTo( tree );
      likelihood.WriteTo( tree );
      SafeLikelihood.WriteTo( tree );
      electronVetoLoose.WriteTo( tree );
      electronVetoMedium.WriteTo( tree );
      electronVetoTight.WriteTo( tree );
      muonVeto.WriteTo( tree );
      tauLlhLoose.WriteTo( tree );
      tauLlhMedium.WriteTo( tree );
      tauLlhTight.WriteTo( tree );
      JetBDTSigLoose.WriteTo( tree );
      JetBDTSigMedium.WriteTo( tree );
      JetBDTSigTight.WriteTo( tree );
      EleBDTLoose.WriteTo( tree );
      EleBDTMedium.WriteTo( tree );
      EleBDTTight.WriteTo( tree );
      author.WriteTo( tree );
      RoIWord.WriteTo( tree );
      nProng.WriteTo( tree );
      numTrack.WriteTo( tree );
      seedCalo_numTrack.WriteTo( tree );
      seedCalo_nWideTrk.WriteTo( tree );
      nOtherTrk.WriteTo( tree );
      etOverPtLeadTrk.WriteTo( tree );
      ipZ0SinThetaSigLeadTrk.WriteTo( tree );
      leadTrkPt.WriteTo( tree );
      nLooseTrk.WriteTo( tree );
      nLooseConvTrk.WriteTo( tree );
      nProngLoose.WriteTo( tree );
      ipSigLeadTrk.WriteTo( tree );
      ipSigLeadLooseTrk.WriteTo( tree );
      etOverPtLeadLooseTrk.WriteTo( tree );
      leadLooseTrkPt.WriteTo( tree );
      chrgLooseTrk.WriteTo( tree );
      massTrkSys.WriteTo( tree );
      trkWidth2.WriteTo( tree );
      trFlightPathSig.WriteTo( tree );
      etEflow.WriteTo( tree );
      mEflow.WriteTo( tree );
      nPi0.WriteTo( tree );
      ele_E237E277.WriteTo( tree );
      ele_PresamplerFraction.WriteTo( tree );
      ele_ECALFirstFraction.WriteTo( tree );
      EM_TES_scale.WriteTo( tree );
      LC_TES_precalib.WriteTo( tree );
      TRTHTOverLT_LeadTrk.WriteTo( tree );
      seedCalo_EMRadius.WriteTo( tree );
      seedCalo_hadRadius.WriteTo( tree );
      seedCalo_etEMAtEMScale.WriteTo( tree );
      seedCalo_etHadAtEMScale.WriteTo( tree );
      seedCalo_isolFrac.WriteTo( tree );
      seedCalo_centFrac.WriteTo( tree );
      seedCalo_stripWidth2.WriteTo( tree );
      seedCalo_nStrip.WriteTo( tree );
      seedCalo_eta.WriteTo( tree );
      seedCalo_phi.WriteTo( tree );
      seedCalo_nIsolLooseTrk.WriteTo( tree );
      seedCalo_trkAvgDist.WriteTo( tree );
      seedCalo_trkRmsDist.WriteTo( tree );
      seedCalo_caloIso.WriteTo( tree );
      seedCalo_caloIsoCorrected.WriteTo( tree );
      seedCalo_dRmax.WriteTo( tree );
      seedCalo_lead2ClusterEOverAllClusterE.WriteTo( tree );
      seedCalo_lead3ClusterEOverAllClusterE.WriteTo( tree );
      seedCalo_etHadCalib.WriteTo( tree );
      seedCalo_etEMCalib.WriteTo( tree );
      numTopoClusters.WriteTo( tree );
      numEffTopoClusters.WriteTo( tree );
      topoInvMass.WriteTo( tree );
      effTopoInvMass.WriteTo( tree );
      topoMeanDeltaR.WriteTo( tree );
      effTopoMeanDeltaR.WriteTo( tree );
      numCells.WriteTo( tree );
      seedTrk_EMRadius.WriteTo( tree );
      seedTrk_isolFrac.WriteTo( tree );
      seedTrk_etChrgHadOverSumTrkPt.WriteTo( tree );
      seedTrk_isolFracWide.WriteTo( tree );
      seedTrk_etHadAtEMScale.WriteTo( tree );
      seedTrk_etEMAtEMScale.WriteTo( tree );
      seedTrk_etEMCL.WriteTo( tree );
      seedTrk_etChrgEM.WriteTo( tree );
      seedTrk_etNeuEM.WriteTo( tree );
      seedTrk_etResNeuEM.WriteTo( tree );
      seedTrk_hadLeakEt.WriteTo( tree );
      seedTrk_sumEMCellEtOverLeadTrkPt.WriteTo( tree );
      seedTrk_secMaxStripEt.WriteTo( tree );
      seedTrk_stripWidth2.WriteTo( tree );
      seedTrk_nStrip.WriteTo( tree );
      seedTrk_etChrgHad.WriteTo( tree );
      seedTrk_nOtherCoreTrk.WriteTo( tree );
      seedTrk_nIsolTrk.WriteTo( tree );
      seedTrk_etIsolEM.WriteTo( tree );
      seedTrk_etIsolHad.WriteTo( tree );
      cellBasedEnergyRing1.WriteTo( tree );
      cellBasedEnergyRing2.WriteTo( tree );
      cellBasedEnergyRing3.WriteTo( tree );
      cellBasedEnergyRing4.WriteTo( tree );
      cellBasedEnergyRing5.WriteTo( tree );
      cellBasedEnergyRing6.WriteTo( tree );
      cellBasedEnergyRing7.WriteTo( tree );
      calcVars_etHad_EMScale_Pt3Trks.WriteTo( tree );
      calcVars_etEM_EMScale_Pt3Trks.WriteTo( tree );
      calcVars_ipSigLeadLooseTrk.WriteTo( tree );
      calcVars_drMin.WriteTo( tree );
      calcVars_calRadius.WriteTo( tree );
      calcVars_EMFractionAtEMScale.WriteTo( tree );
      calcVars_trackIso.WriteTo( tree );
      calcVars_ChPiEMEOverCaloEME.WriteTo( tree );
      calcVars_PSSFraction.WriteTo( tree );
      calcVars_EMPOverTrkSysP.WriteTo( tree );
      calcVars_pi0BDTPrimaryScore.WriteTo( tree );
      calcVars_pi0BDTSecondaryScore.WriteTo( tree );
      calcVars_corrCentFrac.WriteTo( tree );
      calcVars_corrFTrk.WriteTo( tree );
      calcVars_interAxis_eta.WriteTo( tree );
      calcVars_interAxis_phi.WriteTo( tree );
      pi0_cl1_pt.WriteTo( tree );
      pi0_cl1_eta.WriteTo( tree );
      pi0_cl1_phi.WriteTo( tree );
      pi0_cl2_pt.WriteTo( tree );
      pi0_cl2_eta.WriteTo( tree );
      pi0_cl2_phi.WriteTo( tree );
      pi0_vistau_pt.WriteTo( tree );
      pi0_vistau_eta.WriteTo( tree );
      pi0_vistau_phi.WriteTo( tree );
      pi0_vistau_m.WriteTo( tree );
      pi0_n.WriteTo( tree );
      pantau_isPanTauCandidate.WriteTo( tree );
      pantau_PanTauScore.WriteTo( tree );
      pantau_NChargedEFO.WriteTo( tree );
      pantau_NChargedQualifiedEFO.WriteTo( tree );
      pantau_NNeutralEFO.WriteTo( tree );
      pantau_AbsSumCharge.WriteTo( tree );
      pantau_EflowJetMomentDRAll.WriteTo( tree );
      pantau_EflowJetMomentDRChrg.WriteTo( tree );
      pantau_EflowJetMomentDREMNeut.WriteTo( tree );
      pantau_EflowJetMomentDRHADNeut.WriteTo( tree );
      pantau_EtIn01OverEtIn02InvSigm.WriteTo( tree );
      pantau_EtIn02To04OverTotalEtInvSigm.WriteTo( tree );
      pantau_EtIn01OverEtIn04InvSigm.WriteTo( tree );
      pantau_EtIn01OverEtIn04.WriteTo( tree );
      pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents.WriteTo( tree );
      pantau_JetSphericity.WriteTo( tree );
      pantau_TransImpactParamSignfTrack1.WriteTo( tree );
      pantau_EflowAngleJetAxisLeadingChargedQualified.WriteTo( tree );
      pantau_EflowAngleChargedAxisNeutralAxis.WriteTo( tree );
      pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified.WriteTo( tree );
      pantau_EflowInvariantMassAll.WriteTo( tree );
      pantau_EflowStdDevEtToSumEt.WriteTo( tree );
      pantau_EflowEtLeadingChrgQualifiedOverTotalEt.WriteTo( tree );
      pantau_EflowSumEAll.WriteTo( tree );
      pantau_EflowChargedSumEt.WriteTo( tree );
      leadTrack_eta.WriteTo( tree );
      leadTrack_phi.WriteTo( tree );
      cluster_E.WriteTo( tree );
      cluster_eta.WriteTo( tree );
      cluster_phi.WriteTo( tree );
      cluster_eta_atTJVA.WriteTo( tree );
      cluster_phi_atTJVA.WriteTo( tree );
      cluster_PreSamplerStripF.WriteTo( tree );
      cluster_EMLayer2F.WriteTo( tree );
      cluster_EMLayer3F.WriteTo( tree );
      cluster_n.WriteTo( tree );
      Pi0Cluster_pt.WriteTo( tree );
      Pi0Cluster_eta.WriteTo( tree );
      Pi0Cluster_phi.WriteTo( tree );
      secvtx_x.WriteTo( tree );
      secvtx_y.WriteTo( tree );
      secvtx_z.WriteTo( tree );
      secvtx_xx.WriteTo( tree );
      secvtx_yy.WriteTo( tree );
      secvtx_zz.WriteTo( tree );
      secvtx_xy.WriteTo( tree );
      secvtx_yz.WriteTo( tree );
      secvtx_zx.WriteTo( tree );
      secvtx_chiSquared.WriteTo( tree );
      secvtx_numberDoF.WriteTo( tree );
      privtx_x.WriteTo( tree );
      privtx_y.WriteTo( tree );
      privtx_z.WriteTo( tree );
      privtx_xx.WriteTo( tree );
      privtx_yy.WriteTo( tree );
      privtx_zz.WriteTo( tree );
      privtx_xy.WriteTo( tree );
      privtx_yz.WriteTo( tree );
      privtx_zx.WriteTo( tree );
      privtx_chiSquared.WriteTo( tree );
      privtx_numberDoF.WriteTo( tree );
      privtx_jvf.WriteTo( tree );
      jet_Et.WriteTo( tree );
      jet_pt.WriteTo( tree );
      jet_m.WriteTo( tree );
      jet_eta.WriteTo( tree );
      jet_phi.WriteTo( tree );
      jet_WIDTH.WriteTo( tree );
      jet_n90.WriteTo( tree );
      jet_n90constituents.WriteTo( tree );
      jet_BCH_CORR_CELL.WriteTo( tree );
      jet_BCH_CORR_JET.WriteTo( tree );
      jet_BCH_CORR_JET_FORCELL.WriteTo( tree );
      jet_ENG_BAD_CELLS.WriteTo( tree );
      jet_N_BAD_CELLS.WriteTo( tree );
      jet_N_BAD_CELLS_CORR.WriteTo( tree );
      jet_BAD_CELLS_CORR_E.WriteTo( tree );
      jet_Timing.WriteTo( tree );
      jet_LArQuality.WriteTo( tree );
      jet_nTrk.WriteTo( tree );
      jet_sumPtTrk.WriteTo( tree );
      jet_OriginIndex.WriteTo( tree );
      jet_HECQuality.WriteTo( tree );
      jet_NegativeE.WriteTo( tree );
      jet_YFlip12.WriteTo( tree );
      jet_YFlip23.WriteTo( tree );
      jet_BCH_CORR_DOTX.WriteTo( tree );
      jet_SamplingMax.WriteTo( tree );
      jet_fracSamplingMax.WriteTo( tree );
      jet_hecf.WriteTo( tree );
      jet_tgap3f.WriteTo( tree );
      jet_isUgly.WriteTo( tree );
      jet_isBadLooseMinus.WriteTo( tree );
      jet_isBadLoose.WriteTo( tree );
      jet_isBadMedium.WriteTo( tree );
      jet_isBadTight.WriteTo( tree );
      jet_emfrac.WriteTo( tree );
      jet_GCWJES.WriteTo( tree );
      jet_EMJES.WriteTo( tree );
      jet_emscale_E.WriteTo( tree );
      jet_emscale_pt.WriteTo( tree );
      jet_emscale_m.WriteTo( tree );
      jet_emscale_eta.WriteTo( tree );
      jet_emscale_phi.WriteTo( tree );
      jet_jvtx_x.WriteTo( tree );
      jet_jvtx_y.WriteTo( tree );
      jet_jvtx_z.WriteTo( tree );
      jet_jvtxf.WriteTo( tree );
      jet_flavor_weight.WriteTo( tree );
      jet_flavor_weight_TrackCounting2D.WriteTo( tree );
      jet_flavor_weight_JetProb.WriteTo( tree );
      jet_flavor_weight_IP1D.WriteTo( tree );
      jet_flavor_weight_IP2D.WriteTo( tree );
      jet_flavor_weight_IP3D.WriteTo( tree );
      jet_flavor_weight_SV0.WriteTo( tree );
      jet_flavor_weight_SV1.WriteTo( tree );
      jet_flavor_weight_SV2.WriteTo( tree );
      jet_flavor_weight_JetFitterTag.WriteTo( tree );
      jet_flavor_weight_JetFitterCOMB.WriteTo( tree );
      jet_flavor_weight_JetFitterTagNN.WriteTo( tree );
      jet_flavor_weight_JetFitterCOMBNN.WriteTo( tree );
      jet_flavor_weight_SoftMuonTag.WriteTo( tree );
      jet_flavor_weight_SoftElectronTag.WriteTo( tree );
      jet_flavor_weight_IP3DSV1.WriteTo( tree );
      jet_e_PreSamplerB.WriteTo( tree );
      jet_e_EMB1.WriteTo( tree );
      jet_e_EMB2.WriteTo( tree );
      jet_e_EMB3.WriteTo( tree );
      jet_e_PreSamplerE.WriteTo( tree );
      jet_e_EME1.WriteTo( tree );
      jet_e_EME2.WriteTo( tree );
      jet_e_EME3.WriteTo( tree );
      jet_e_HEC0.WriteTo( tree );
      jet_e_HEC1.WriteTo( tree );
      jet_e_HEC2.WriteTo( tree );
      jet_e_HEC3.WriteTo( tree );
      jet_e_TileBar0.WriteTo( tree );
      jet_e_TileBar1.WriteTo( tree );
      jet_e_TileBar2.WriteTo( tree );
      jet_e_TileGap1.WriteTo( tree );
      jet_e_TileGap2.WriteTo( tree );
      jet_e_TileGap3.WriteTo( tree );
      jet_e_TileExt0.WriteTo( tree );
      jet_e_TileExt1.WriteTo( tree );
      jet_e_TileExt2.WriteTo( tree );
      jet_e_FCAL0.WriteTo( tree );
      jet_e_FCAL1.WriteTo( tree );
      jet_e_FCAL2.WriteTo( tree );
      jet_shapeBins.WriteTo( tree );
      track_atTJVA_n.WriteTo( tree );
      track_atTJVA_d0.WriteTo( tree );
      track_atTJVA_z0.WriteTo( tree );
      track_atTJVA_phi.WriteTo( tree );
      track_atTJVA_theta.WriteTo( tree );
      track_atTJVA_qoverp.WriteTo( tree );
      track_atTJVA_pt.WriteTo( tree );
      track_atTJVA_eta.WriteTo( tree );
      seedCalo_wideTrk_atTJVA_n.WriteTo( tree );
      seedCalo_wideTrk_atTJVA_d0.WriteTo( tree );
      seedCalo_wideTrk_atTJVA_z0.WriteTo( tree );
      seedCalo_wideTrk_atTJVA_phi.WriteTo( tree );
      seedCalo_wideTrk_atTJVA_theta.WriteTo( tree );
      seedCalo_wideTrk_atTJVA_qoverp.WriteTo( tree );
      seedCalo_wideTrk_atTJVA_pt.WriteTo( tree );
      seedCalo_wideTrk_atTJVA_eta.WriteTo( tree );
      otherTrk_atTJVA_n.WriteTo( tree );
      track_n.WriteTo( tree );
      track_d0.WriteTo( tree );
      track_z0.WriteTo( tree );
      track_phi.WriteTo( tree );
      track_theta.WriteTo( tree );
      track_qoverp.WriteTo( tree );
      track_pt.WriteTo( tree );
      track_eta.WriteTo( tree );
      track_atPV_d0.WriteTo( tree );
      track_atPV_z0.WriteTo( tree );
      track_atPV_phi.WriteTo( tree );
      track_atPV_theta.WriteTo( tree );
      track_atPV_qoverp.WriteTo( tree );
      track_atPV_pt.WriteTo( tree );
      track_atPV_eta.WriteTo( tree );
      track_nBLHits.WriteTo( tree );
      track_nPixHits.WriteTo( tree );
      track_nSCTHits.WriteTo( tree );
      track_nTRTHits.WriteTo( tree );
      track_nTRTHighTHits.WriteTo( tree );
      track_nTRTXenonHits.WriteTo( tree );
      track_nPixHoles.WriteTo( tree );
      track_nSCTHoles.WriteTo( tree );
      track_nTRTHoles.WriteTo( tree );
      track_nPixelDeadSensors.WriteTo( tree );
      track_nSCTDeadSensors.WriteTo( tree );
      track_nBLSharedHits.WriteTo( tree );
      track_nPixSharedHits.WriteTo( tree );
      track_nSCTSharedHits.WriteTo( tree );
      track_nBLayerSplitHits.WriteTo( tree );
      track_nPixSplitHits.WriteTo( tree );
      track_nBLayerOutliers.WriteTo( tree );
      track_nPixelOutliers.WriteTo( tree );
      track_nSCTOutliers.WriteTo( tree );
      track_nTRTOutliers.WriteTo( tree );
      track_nTRTHighTOutliers.WriteTo( tree );
      track_nContribPixelLayers.WriteTo( tree );
      track_nGangedPixels.WriteTo( tree );
      track_nGangedFlaggedFakes.WriteTo( tree );
      track_nPixelSpoiltHits.WriteTo( tree );
      track_nSCTDoubleHoles.WriteTo( tree );
      track_nSCTSpoiltHits.WriteTo( tree );
      track_expectBLayerHit.WriteTo( tree );
      track_nHits.WriteTo( tree );
      track_TRTHighTHitsRatio.WriteTo( tree );
      track_TRTHighTOutliersRatio.WriteTo( tree );
      seedCalo_track_n.WriteTo( tree );
      seedCalo_wideTrk_n.WriteTo( tree );
      seedCalo_wideTrk_nBLHits.WriteTo( tree );
      seedCalo_wideTrk_nPixHits.WriteTo( tree );
      seedCalo_wideTrk_nSCTHits.WriteTo( tree );
      seedCalo_wideTrk_nTRTHits.WriteTo( tree );
      seedCalo_wideTrk_nTRTHighTHits.WriteTo( tree );
      seedCalo_wideTrk_nTRTXenonHits.WriteTo( tree );
      seedCalo_wideTrk_nPixHoles.WriteTo( tree );
      seedCalo_wideTrk_nSCTHoles.WriteTo( tree );
      seedCalo_wideTrk_nTRTHoles.WriteTo( tree );
      seedCalo_wideTrk_nPixelDeadSensors.WriteTo( tree );
      seedCalo_wideTrk_nSCTDeadSensors.WriteTo( tree );
      seedCalo_wideTrk_nBLSharedHits.WriteTo( tree );
      seedCalo_wideTrk_nPixSharedHits.WriteTo( tree );
      seedCalo_wideTrk_nSCTSharedHits.WriteTo( tree );
      seedCalo_wideTrk_nBLayerSplitHits.WriteTo( tree );
      seedCalo_wideTrk_nPixSplitHits.WriteTo( tree );
      seedCalo_wideTrk_nBLayerOutliers.WriteTo( tree );
      seedCalo_wideTrk_nPixelOutliers.WriteTo( tree );
      seedCalo_wideTrk_nSCTOutliers.WriteTo( tree );
      seedCalo_wideTrk_nTRTOutliers.WriteTo( tree );
      seedCalo_wideTrk_nTRTHighTOutliers.WriteTo( tree );
      seedCalo_wideTrk_nContribPixelLayers.WriteTo( tree );
      seedCalo_wideTrk_nGangedPixels.WriteTo( tree );
      seedCalo_wideTrk_nGangedFlaggedFakes.WriteTo( tree );
      seedCalo_wideTrk_nPixelSpoiltHits.WriteTo( tree );
      seedCalo_wideTrk_nSCTDoubleHoles.WriteTo( tree );
      seedCalo_wideTrk_nSCTSpoiltHits.WriteTo( tree );
      seedCalo_wideTrk_expectBLayerHit.WriteTo( tree );
      seedCalo_wideTrk_nHits.WriteTo( tree );
      otherTrk_n.WriteTo( tree );
      EF_dr.WriteTo( tree );
      EF_E.WriteTo( tree );
      EF_Et.WriteTo( tree );
      EF_pt.WriteTo( tree );
      EF_eta.WriteTo( tree );
      EF_phi.WriteTo( tree );
      EF_matched.WriteTo( tree );
      L2_dr.WriteTo( tree );
      L2_E.WriteTo( tree );
      L2_Et.WriteTo( tree );
      L2_pt.WriteTo( tree );
      L2_eta.WriteTo( tree );
      L2_phi.WriteTo( tree );
      L2_matched.WriteTo( tree );
      L1_dr.WriteTo( tree );
      L1_Et.WriteTo( tree );
      L1_pt.WriteTo( tree );
      L1_eta.WriteTo( tree );
      L1_phi.WriteTo( tree );
      L1_matched.WriteTo( tree );
if (!is_data) {
      trueTauAssocSmall_dr.WriteTo( tree );
      trueTauAssocSmall_index.WriteTo( tree );
      trueTauAssocSmall_matched.WriteTo( tree );
} // end !is_data
      MET_Egamma10LooseTau_wpx.WriteTo( tree );
      MET_Egamma10LooseTau_wpy.WriteTo( tree );
      MET_Egamma10LooseTau_wet.WriteTo( tree );
      MET_Egamma10LooseTau_statusWord.WriteTo( tree );
      MET_wpx.WriteTo( tree );
      MET_wpy.WriteTo( tree );
      MET_wet.WriteTo( tree );
      MET_statusWord.WriteTo( tree );

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
   void TauD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void TauD3PDObject::ReadAllActive() {

      // Check if it makes sense to call this function:
      if( ! fFromInput ) {
         static ::Bool_t wPrinted = kFALSE;
         if( ! wPrinted ) {
            Warning( "ReadAllActive", "Function only meaningful when used on objects" );
            Warning( "ReadAllActive", "which are used to read information from a D3PD" );
            wPrinted = kTRUE;
         }
      }

      if( n.IsActive() ) n();
      if( Et.IsActive() ) Et();
      if( pt.IsActive() ) pt();
      if( m.IsActive() ) m();
      if( eta.IsActive() ) eta();
      if( phi.IsActive() ) phi();
      if( charge.IsActive() ) charge();
      if( BDTEleScore.IsActive() ) BDTEleScore();
      if( BDTJetScore.IsActive() ) BDTJetScore();
      if( likelihood.IsActive() ) likelihood();
      if( SafeLikelihood.IsActive() ) SafeLikelihood();
      if( electronVetoLoose.IsActive() ) electronVetoLoose();
      if( electronVetoMedium.IsActive() ) electronVetoMedium();
      if( electronVetoTight.IsActive() ) electronVetoTight();
      if( muonVeto.IsActive() ) muonVeto();
      if( tauLlhLoose.IsActive() ) tauLlhLoose();
      if( tauLlhMedium.IsActive() ) tauLlhMedium();
      if( tauLlhTight.IsActive() ) tauLlhTight();
      if( JetBDTSigLoose.IsActive() ) JetBDTSigLoose();
      if( JetBDTSigMedium.IsActive() ) JetBDTSigMedium();
      if( JetBDTSigTight.IsActive() ) JetBDTSigTight();
      if( EleBDTLoose.IsActive() ) EleBDTLoose();
      if( EleBDTMedium.IsActive() ) EleBDTMedium();
      if( EleBDTTight.IsActive() ) EleBDTTight();
      if( author.IsActive() ) author();
      if( RoIWord.IsActive() ) RoIWord();
      if( nProng.IsActive() ) nProng();
      if( numTrack.IsActive() ) numTrack();
      if( seedCalo_numTrack.IsActive() ) seedCalo_numTrack();
      if( seedCalo_nWideTrk.IsActive() ) seedCalo_nWideTrk();
      if( nOtherTrk.IsActive() ) nOtherTrk();
      if( etOverPtLeadTrk.IsActive() ) etOverPtLeadTrk();
      if( ipZ0SinThetaSigLeadTrk.IsActive() ) ipZ0SinThetaSigLeadTrk();
      if( leadTrkPt.IsActive() ) leadTrkPt();
      if( nLooseTrk.IsActive() ) nLooseTrk();
      if( nLooseConvTrk.IsActive() ) nLooseConvTrk();
      if( nProngLoose.IsActive() ) nProngLoose();
      if( ipSigLeadTrk.IsActive() ) ipSigLeadTrk();
      if( ipSigLeadLooseTrk.IsActive() ) ipSigLeadLooseTrk();
      if( etOverPtLeadLooseTrk.IsActive() ) etOverPtLeadLooseTrk();
      if( leadLooseTrkPt.IsActive() ) leadLooseTrkPt();
      if( chrgLooseTrk.IsActive() ) chrgLooseTrk();
      if( massTrkSys.IsActive() ) massTrkSys();
      if( trkWidth2.IsActive() ) trkWidth2();
      if( trFlightPathSig.IsActive() ) trFlightPathSig();
      if( etEflow.IsActive() ) etEflow();
      if( mEflow.IsActive() ) mEflow();
      if( nPi0.IsActive() ) nPi0();
      if( ele_E237E277.IsActive() ) ele_E237E277();
      if( ele_PresamplerFraction.IsActive() ) ele_PresamplerFraction();
      if( ele_ECALFirstFraction.IsActive() ) ele_ECALFirstFraction();
      if( EM_TES_scale.IsActive() ) EM_TES_scale();
      if( LC_TES_precalib.IsActive() ) LC_TES_precalib();
      if( TRTHTOverLT_LeadTrk.IsActive() ) TRTHTOverLT_LeadTrk();
      if( seedCalo_EMRadius.IsActive() ) seedCalo_EMRadius();
      if( seedCalo_hadRadius.IsActive() ) seedCalo_hadRadius();
      if( seedCalo_etEMAtEMScale.IsActive() ) seedCalo_etEMAtEMScale();
      if( seedCalo_etHadAtEMScale.IsActive() ) seedCalo_etHadAtEMScale();
      if( seedCalo_isolFrac.IsActive() ) seedCalo_isolFrac();
      if( seedCalo_centFrac.IsActive() ) seedCalo_centFrac();
      if( seedCalo_stripWidth2.IsActive() ) seedCalo_stripWidth2();
      if( seedCalo_nStrip.IsActive() ) seedCalo_nStrip();
      if( seedCalo_eta.IsActive() ) seedCalo_eta();
      if( seedCalo_phi.IsActive() ) seedCalo_phi();
      if( seedCalo_nIsolLooseTrk.IsActive() ) seedCalo_nIsolLooseTrk();
      if( seedCalo_trkAvgDist.IsActive() ) seedCalo_trkAvgDist();
      if( seedCalo_trkRmsDist.IsActive() ) seedCalo_trkRmsDist();
      if( seedCalo_caloIso.IsActive() ) seedCalo_caloIso();
      if( seedCalo_caloIsoCorrected.IsActive() ) seedCalo_caloIsoCorrected();
      if( seedCalo_dRmax.IsActive() ) seedCalo_dRmax();
      if( seedCalo_lead2ClusterEOverAllClusterE.IsActive() ) seedCalo_lead2ClusterEOverAllClusterE();
      if( seedCalo_lead3ClusterEOverAllClusterE.IsActive() ) seedCalo_lead3ClusterEOverAllClusterE();
      if( seedCalo_etHadCalib.IsActive() ) seedCalo_etHadCalib();
      if( seedCalo_etEMCalib.IsActive() ) seedCalo_etEMCalib();
      if( numTopoClusters.IsActive() ) numTopoClusters();
      if( numEffTopoClusters.IsActive() ) numEffTopoClusters();
      if( topoInvMass.IsActive() ) topoInvMass();
      if( effTopoInvMass.IsActive() ) effTopoInvMass();
      if( topoMeanDeltaR.IsActive() ) topoMeanDeltaR();
      if( effTopoMeanDeltaR.IsActive() ) effTopoMeanDeltaR();
      if( numCells.IsActive() ) numCells();
      if( seedTrk_EMRadius.IsActive() ) seedTrk_EMRadius();
      if( seedTrk_isolFrac.IsActive() ) seedTrk_isolFrac();
      if( seedTrk_etChrgHadOverSumTrkPt.IsActive() ) seedTrk_etChrgHadOverSumTrkPt();
      if( seedTrk_isolFracWide.IsActive() ) seedTrk_isolFracWide();
      if( seedTrk_etHadAtEMScale.IsActive() ) seedTrk_etHadAtEMScale();
      if( seedTrk_etEMAtEMScale.IsActive() ) seedTrk_etEMAtEMScale();
      if( seedTrk_etEMCL.IsActive() ) seedTrk_etEMCL();
      if( seedTrk_etChrgEM.IsActive() ) seedTrk_etChrgEM();
      if( seedTrk_etNeuEM.IsActive() ) seedTrk_etNeuEM();
      if( seedTrk_etResNeuEM.IsActive() ) seedTrk_etResNeuEM();
      if( seedTrk_hadLeakEt.IsActive() ) seedTrk_hadLeakEt();
      if( seedTrk_sumEMCellEtOverLeadTrkPt.IsActive() ) seedTrk_sumEMCellEtOverLeadTrkPt();
      if( seedTrk_secMaxStripEt.IsActive() ) seedTrk_secMaxStripEt();
      if( seedTrk_stripWidth2.IsActive() ) seedTrk_stripWidth2();
      if( seedTrk_nStrip.IsActive() ) seedTrk_nStrip();
      if( seedTrk_etChrgHad.IsActive() ) seedTrk_etChrgHad();
      if( seedTrk_nOtherCoreTrk.IsActive() ) seedTrk_nOtherCoreTrk();
      if( seedTrk_nIsolTrk.IsActive() ) seedTrk_nIsolTrk();
      if( seedTrk_etIsolEM.IsActive() ) seedTrk_etIsolEM();
      if( seedTrk_etIsolHad.IsActive() ) seedTrk_etIsolHad();
      if( cellBasedEnergyRing1.IsActive() ) cellBasedEnergyRing1();
      if( cellBasedEnergyRing2.IsActive() ) cellBasedEnergyRing2();
      if( cellBasedEnergyRing3.IsActive() ) cellBasedEnergyRing3();
      if( cellBasedEnergyRing4.IsActive() ) cellBasedEnergyRing4();
      if( cellBasedEnergyRing5.IsActive() ) cellBasedEnergyRing5();
      if( cellBasedEnergyRing6.IsActive() ) cellBasedEnergyRing6();
      if( cellBasedEnergyRing7.IsActive() ) cellBasedEnergyRing7();
      if( calcVars_etHad_EMScale_Pt3Trks.IsActive() ) calcVars_etHad_EMScale_Pt3Trks();
      if( calcVars_etEM_EMScale_Pt3Trks.IsActive() ) calcVars_etEM_EMScale_Pt3Trks();
      if( calcVars_ipSigLeadLooseTrk.IsActive() ) calcVars_ipSigLeadLooseTrk();
      if( calcVars_drMin.IsActive() ) calcVars_drMin();
      if( calcVars_calRadius.IsActive() ) calcVars_calRadius();
      if( calcVars_EMFractionAtEMScale.IsActive() ) calcVars_EMFractionAtEMScale();
      if( calcVars_trackIso.IsActive() ) calcVars_trackIso();
      if( calcVars_ChPiEMEOverCaloEME.IsActive() ) calcVars_ChPiEMEOverCaloEME();
      if( calcVars_PSSFraction.IsActive() ) calcVars_PSSFraction();
      if( calcVars_EMPOverTrkSysP.IsActive() ) calcVars_EMPOverTrkSysP();
      if( calcVars_pi0BDTPrimaryScore.IsActive() ) calcVars_pi0BDTPrimaryScore();
      if( calcVars_pi0BDTSecondaryScore.IsActive() ) calcVars_pi0BDTSecondaryScore();
      if( calcVars_corrCentFrac.IsActive() ) calcVars_corrCentFrac();
      if( calcVars_corrFTrk.IsActive() ) calcVars_corrFTrk();
      if( calcVars_interAxis_eta.IsActive() ) calcVars_interAxis_eta();
      if( calcVars_interAxis_phi.IsActive() ) calcVars_interAxis_phi();
      if( pi0_cl1_pt.IsActive() ) pi0_cl1_pt();
      if( pi0_cl1_eta.IsActive() ) pi0_cl1_eta();
      if( pi0_cl1_phi.IsActive() ) pi0_cl1_phi();
      if( pi0_cl2_pt.IsActive() ) pi0_cl2_pt();
      if( pi0_cl2_eta.IsActive() ) pi0_cl2_eta();
      if( pi0_cl2_phi.IsActive() ) pi0_cl2_phi();
      if( pi0_vistau_pt.IsActive() ) pi0_vistau_pt();
      if( pi0_vistau_eta.IsActive() ) pi0_vistau_eta();
      if( pi0_vistau_phi.IsActive() ) pi0_vistau_phi();
      if( pi0_vistau_m.IsActive() ) pi0_vistau_m();
      if( pi0_n.IsActive() ) pi0_n();
      if( pantau_isPanTauCandidate.IsActive() ) pantau_isPanTauCandidate();
      if( pantau_PanTauScore.IsActive() ) pantau_PanTauScore();
      if( pantau_NChargedEFO.IsActive() ) pantau_NChargedEFO();
      if( pantau_NChargedQualifiedEFO.IsActive() ) pantau_NChargedQualifiedEFO();
      if( pantau_NNeutralEFO.IsActive() ) pantau_NNeutralEFO();
      if( pantau_AbsSumCharge.IsActive() ) pantau_AbsSumCharge();
      if( pantau_EflowJetMomentDRAll.IsActive() ) pantau_EflowJetMomentDRAll();
      if( pantau_EflowJetMomentDRChrg.IsActive() ) pantau_EflowJetMomentDRChrg();
      if( pantau_EflowJetMomentDREMNeut.IsActive() ) pantau_EflowJetMomentDREMNeut();
      if( pantau_EflowJetMomentDRHADNeut.IsActive() ) pantau_EflowJetMomentDRHADNeut();
      if( pantau_EtIn01OverEtIn02InvSigm.IsActive() ) pantau_EtIn01OverEtIn02InvSigm();
      if( pantau_EtIn02To04OverTotalEtInvSigm.IsActive() ) pantau_EtIn02To04OverTotalEtInvSigm();
      if( pantau_EtIn01OverEtIn04InvSigm.IsActive() ) pantau_EtIn01OverEtIn04InvSigm();
      if( pantau_EtIn01OverEtIn04.IsActive() ) pantau_EtIn01OverEtIn04();
      if( pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents.IsActive() ) pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents();
      if( pantau_JetSphericity.IsActive() ) pantau_JetSphericity();
      if( pantau_TransImpactParamSignfTrack1.IsActive() ) pantau_TransImpactParamSignfTrack1();
      if( pantau_EflowAngleJetAxisLeadingChargedQualified.IsActive() ) pantau_EflowAngleJetAxisLeadingChargedQualified();
      if( pantau_EflowAngleChargedAxisNeutralAxis.IsActive() ) pantau_EflowAngleChargedAxisNeutralAxis();
      if( pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified.IsActive() ) pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified();
      if( pantau_EflowInvariantMassAll.IsActive() ) pantau_EflowInvariantMassAll();
      if( pantau_EflowStdDevEtToSumEt.IsActive() ) pantau_EflowStdDevEtToSumEt();
      if( pantau_EflowEtLeadingChrgQualifiedOverTotalEt.IsActive() ) pantau_EflowEtLeadingChrgQualifiedOverTotalEt();
      if( pantau_EflowSumEAll.IsActive() ) pantau_EflowSumEAll();
      if( pantau_EflowChargedSumEt.IsActive() ) pantau_EflowChargedSumEt();
      if( leadTrack_eta.IsActive() ) leadTrack_eta();
      if( leadTrack_phi.IsActive() ) leadTrack_phi();
      if( cluster_E.IsActive() ) cluster_E();
      if( cluster_eta.IsActive() ) cluster_eta();
      if( cluster_phi.IsActive() ) cluster_phi();
      if( cluster_eta_atTJVA.IsActive() ) cluster_eta_atTJVA();
      if( cluster_phi_atTJVA.IsActive() ) cluster_phi_atTJVA();
      if( cluster_PreSamplerStripF.IsActive() ) cluster_PreSamplerStripF();
      if( cluster_EMLayer2F.IsActive() ) cluster_EMLayer2F();
      if( cluster_EMLayer3F.IsActive() ) cluster_EMLayer3F();
      if( cluster_n.IsActive() ) cluster_n();
      if( Pi0Cluster_pt.IsActive() ) Pi0Cluster_pt();
      if( Pi0Cluster_eta.IsActive() ) Pi0Cluster_eta();
      if( Pi0Cluster_phi.IsActive() ) Pi0Cluster_phi();
      if( secvtx_x.IsActive() ) secvtx_x();
      if( secvtx_y.IsActive() ) secvtx_y();
      if( secvtx_z.IsActive() ) secvtx_z();
      if( secvtx_xx.IsActive() ) secvtx_xx();
      if( secvtx_yy.IsActive() ) secvtx_yy();
      if( secvtx_zz.IsActive() ) secvtx_zz();
      if( secvtx_xy.IsActive() ) secvtx_xy();
      if( secvtx_yz.IsActive() ) secvtx_yz();
      if( secvtx_zx.IsActive() ) secvtx_zx();
      if( secvtx_chiSquared.IsActive() ) secvtx_chiSquared();
      if( secvtx_numberDoF.IsActive() ) secvtx_numberDoF();
      if( privtx_x.IsActive() ) privtx_x();
      if( privtx_y.IsActive() ) privtx_y();
      if( privtx_z.IsActive() ) privtx_z();
      if( privtx_xx.IsActive() ) privtx_xx();
      if( privtx_yy.IsActive() ) privtx_yy();
      if( privtx_zz.IsActive() ) privtx_zz();
      if( privtx_xy.IsActive() ) privtx_xy();
      if( privtx_yz.IsActive() ) privtx_yz();
      if( privtx_zx.IsActive() ) privtx_zx();
      if( privtx_chiSquared.IsActive() ) privtx_chiSquared();
      if( privtx_numberDoF.IsActive() ) privtx_numberDoF();
      if( privtx_jvf.IsActive() ) privtx_jvf();
      if( jet_Et.IsActive() ) jet_Et();
      if( jet_pt.IsActive() ) jet_pt();
      if( jet_m.IsActive() ) jet_m();
      if( jet_eta.IsActive() ) jet_eta();
      if( jet_phi.IsActive() ) jet_phi();
      if( jet_WIDTH.IsActive() ) jet_WIDTH();
      if( jet_n90.IsActive() ) jet_n90();
      if( jet_n90constituents.IsActive() ) jet_n90constituents();
      if( jet_BCH_CORR_CELL.IsActive() ) jet_BCH_CORR_CELL();
      if( jet_BCH_CORR_JET.IsActive() ) jet_BCH_CORR_JET();
      if( jet_BCH_CORR_JET_FORCELL.IsActive() ) jet_BCH_CORR_JET_FORCELL();
      if( jet_ENG_BAD_CELLS.IsActive() ) jet_ENG_BAD_CELLS();
      if( jet_N_BAD_CELLS.IsActive() ) jet_N_BAD_CELLS();
      if( jet_N_BAD_CELLS_CORR.IsActive() ) jet_N_BAD_CELLS_CORR();
      if( jet_BAD_CELLS_CORR_E.IsActive() ) jet_BAD_CELLS_CORR_E();
      if( jet_Timing.IsActive() ) jet_Timing();
      if( jet_LArQuality.IsActive() ) jet_LArQuality();
      if( jet_nTrk.IsActive() ) jet_nTrk();
      if( jet_sumPtTrk.IsActive() ) jet_sumPtTrk();
      if( jet_OriginIndex.IsActive() ) jet_OriginIndex();
      if( jet_HECQuality.IsActive() ) jet_HECQuality();
      if( jet_NegativeE.IsActive() ) jet_NegativeE();
      if( jet_YFlip12.IsActive() ) jet_YFlip12();
      if( jet_YFlip23.IsActive() ) jet_YFlip23();
      if( jet_BCH_CORR_DOTX.IsActive() ) jet_BCH_CORR_DOTX();
      if( jet_SamplingMax.IsActive() ) jet_SamplingMax();
      if( jet_fracSamplingMax.IsActive() ) jet_fracSamplingMax();
      if( jet_hecf.IsActive() ) jet_hecf();
      if( jet_tgap3f.IsActive() ) jet_tgap3f();
      if( jet_isUgly.IsActive() ) jet_isUgly();
      if( jet_isBadLooseMinus.IsActive() ) jet_isBadLooseMinus();
      if( jet_isBadLoose.IsActive() ) jet_isBadLoose();
      if( jet_isBadMedium.IsActive() ) jet_isBadMedium();
      if( jet_isBadTight.IsActive() ) jet_isBadTight();
      if( jet_emfrac.IsActive() ) jet_emfrac();
      if( jet_GCWJES.IsActive() ) jet_GCWJES();
      if( jet_EMJES.IsActive() ) jet_EMJES();
      if( jet_emscale_E.IsActive() ) jet_emscale_E();
      if( jet_emscale_pt.IsActive() ) jet_emscale_pt();
      if( jet_emscale_m.IsActive() ) jet_emscale_m();
      if( jet_emscale_eta.IsActive() ) jet_emscale_eta();
      if( jet_emscale_phi.IsActive() ) jet_emscale_phi();
      if( jet_jvtx_x.IsActive() ) jet_jvtx_x();
      if( jet_jvtx_y.IsActive() ) jet_jvtx_y();
      if( jet_jvtx_z.IsActive() ) jet_jvtx_z();
      if( jet_jvtxf.IsActive() ) jet_jvtxf();
      if( jet_flavor_weight.IsActive() ) jet_flavor_weight();
      if( jet_flavor_weight_TrackCounting2D.IsActive() ) jet_flavor_weight_TrackCounting2D();
      if( jet_flavor_weight_JetProb.IsActive() ) jet_flavor_weight_JetProb();
      if( jet_flavor_weight_IP1D.IsActive() ) jet_flavor_weight_IP1D();
      if( jet_flavor_weight_IP2D.IsActive() ) jet_flavor_weight_IP2D();
      if( jet_flavor_weight_IP3D.IsActive() ) jet_flavor_weight_IP3D();
      if( jet_flavor_weight_SV0.IsActive() ) jet_flavor_weight_SV0();
      if( jet_flavor_weight_SV1.IsActive() ) jet_flavor_weight_SV1();
      if( jet_flavor_weight_SV2.IsActive() ) jet_flavor_weight_SV2();
      if( jet_flavor_weight_JetFitterTag.IsActive() ) jet_flavor_weight_JetFitterTag();
      if( jet_flavor_weight_JetFitterCOMB.IsActive() ) jet_flavor_weight_JetFitterCOMB();
      if( jet_flavor_weight_JetFitterTagNN.IsActive() ) jet_flavor_weight_JetFitterTagNN();
      if( jet_flavor_weight_JetFitterCOMBNN.IsActive() ) jet_flavor_weight_JetFitterCOMBNN();
      if( jet_flavor_weight_SoftMuonTag.IsActive() ) jet_flavor_weight_SoftMuonTag();
      if( jet_flavor_weight_SoftElectronTag.IsActive() ) jet_flavor_weight_SoftElectronTag();
      if( jet_flavor_weight_IP3DSV1.IsActive() ) jet_flavor_weight_IP3DSV1();
      if( jet_e_PreSamplerB.IsActive() ) jet_e_PreSamplerB();
      if( jet_e_EMB1.IsActive() ) jet_e_EMB1();
      if( jet_e_EMB2.IsActive() ) jet_e_EMB2();
      if( jet_e_EMB3.IsActive() ) jet_e_EMB3();
      if( jet_e_PreSamplerE.IsActive() ) jet_e_PreSamplerE();
      if( jet_e_EME1.IsActive() ) jet_e_EME1();
      if( jet_e_EME2.IsActive() ) jet_e_EME2();
      if( jet_e_EME3.IsActive() ) jet_e_EME3();
      if( jet_e_HEC0.IsActive() ) jet_e_HEC0();
      if( jet_e_HEC1.IsActive() ) jet_e_HEC1();
      if( jet_e_HEC2.IsActive() ) jet_e_HEC2();
      if( jet_e_HEC3.IsActive() ) jet_e_HEC3();
      if( jet_e_TileBar0.IsActive() ) jet_e_TileBar0();
      if( jet_e_TileBar1.IsActive() ) jet_e_TileBar1();
      if( jet_e_TileBar2.IsActive() ) jet_e_TileBar2();
      if( jet_e_TileGap1.IsActive() ) jet_e_TileGap1();
      if( jet_e_TileGap2.IsActive() ) jet_e_TileGap2();
      if( jet_e_TileGap3.IsActive() ) jet_e_TileGap3();
      if( jet_e_TileExt0.IsActive() ) jet_e_TileExt0();
      if( jet_e_TileExt1.IsActive() ) jet_e_TileExt1();
      if( jet_e_TileExt2.IsActive() ) jet_e_TileExt2();
      if( jet_e_FCAL0.IsActive() ) jet_e_FCAL0();
      if( jet_e_FCAL1.IsActive() ) jet_e_FCAL1();
      if( jet_e_FCAL2.IsActive() ) jet_e_FCAL2();
      if( jet_shapeBins.IsActive() ) jet_shapeBins();
      if( track_atTJVA_n.IsActive() ) track_atTJVA_n();
      if( track_atTJVA_d0.IsActive() ) track_atTJVA_d0();
      if( track_atTJVA_z0.IsActive() ) track_atTJVA_z0();
      if( track_atTJVA_phi.IsActive() ) track_atTJVA_phi();
      if( track_atTJVA_theta.IsActive() ) track_atTJVA_theta();
      if( track_atTJVA_qoverp.IsActive() ) track_atTJVA_qoverp();
      if( track_atTJVA_pt.IsActive() ) track_atTJVA_pt();
      if( track_atTJVA_eta.IsActive() ) track_atTJVA_eta();
      if( seedCalo_wideTrk_atTJVA_n.IsActive() ) seedCalo_wideTrk_atTJVA_n();
      if( seedCalo_wideTrk_atTJVA_d0.IsActive() ) seedCalo_wideTrk_atTJVA_d0();
      if( seedCalo_wideTrk_atTJVA_z0.IsActive() ) seedCalo_wideTrk_atTJVA_z0();
      if( seedCalo_wideTrk_atTJVA_phi.IsActive() ) seedCalo_wideTrk_atTJVA_phi();
      if( seedCalo_wideTrk_atTJVA_theta.IsActive() ) seedCalo_wideTrk_atTJVA_theta();
      if( seedCalo_wideTrk_atTJVA_qoverp.IsActive() ) seedCalo_wideTrk_atTJVA_qoverp();
      if( seedCalo_wideTrk_atTJVA_pt.IsActive() ) seedCalo_wideTrk_atTJVA_pt();
      if( seedCalo_wideTrk_atTJVA_eta.IsActive() ) seedCalo_wideTrk_atTJVA_eta();
      if( otherTrk_atTJVA_n.IsActive() ) otherTrk_atTJVA_n();
      if( track_n.IsActive() ) track_n();
      if( track_d0.IsActive() ) track_d0();
      if( track_z0.IsActive() ) track_z0();
      if( track_phi.IsActive() ) track_phi();
      if( track_theta.IsActive() ) track_theta();
      if( track_qoverp.IsActive() ) track_qoverp();
      if( track_pt.IsActive() ) track_pt();
      if( track_eta.IsActive() ) track_eta();
      if( track_atPV_d0.IsActive() ) track_atPV_d0();
      if( track_atPV_z0.IsActive() ) track_atPV_z0();
      if( track_atPV_phi.IsActive() ) track_atPV_phi();
      if( track_atPV_theta.IsActive() ) track_atPV_theta();
      if( track_atPV_qoverp.IsActive() ) track_atPV_qoverp();
      if( track_atPV_pt.IsActive() ) track_atPV_pt();
      if( track_atPV_eta.IsActive() ) track_atPV_eta();
      if( track_nBLHits.IsActive() ) track_nBLHits();
      if( track_nPixHits.IsActive() ) track_nPixHits();
      if( track_nSCTHits.IsActive() ) track_nSCTHits();
      if( track_nTRTHits.IsActive() ) track_nTRTHits();
      if( track_nTRTHighTHits.IsActive() ) track_nTRTHighTHits();
      if( track_nTRTXenonHits.IsActive() ) track_nTRTXenonHits();
      if( track_nPixHoles.IsActive() ) track_nPixHoles();
      if( track_nSCTHoles.IsActive() ) track_nSCTHoles();
      if( track_nTRTHoles.IsActive() ) track_nTRTHoles();
      if( track_nPixelDeadSensors.IsActive() ) track_nPixelDeadSensors();
      if( track_nSCTDeadSensors.IsActive() ) track_nSCTDeadSensors();
      if( track_nBLSharedHits.IsActive() ) track_nBLSharedHits();
      if( track_nPixSharedHits.IsActive() ) track_nPixSharedHits();
      if( track_nSCTSharedHits.IsActive() ) track_nSCTSharedHits();
      if( track_nBLayerSplitHits.IsActive() ) track_nBLayerSplitHits();
      if( track_nPixSplitHits.IsActive() ) track_nPixSplitHits();
      if( track_nBLayerOutliers.IsActive() ) track_nBLayerOutliers();
      if( track_nPixelOutliers.IsActive() ) track_nPixelOutliers();
      if( track_nSCTOutliers.IsActive() ) track_nSCTOutliers();
      if( track_nTRTOutliers.IsActive() ) track_nTRTOutliers();
      if( track_nTRTHighTOutliers.IsActive() ) track_nTRTHighTOutliers();
      if( track_nContribPixelLayers.IsActive() ) track_nContribPixelLayers();
      if( track_nGangedPixels.IsActive() ) track_nGangedPixels();
      if( track_nGangedFlaggedFakes.IsActive() ) track_nGangedFlaggedFakes();
      if( track_nPixelSpoiltHits.IsActive() ) track_nPixelSpoiltHits();
      if( track_nSCTDoubleHoles.IsActive() ) track_nSCTDoubleHoles();
      if( track_nSCTSpoiltHits.IsActive() ) track_nSCTSpoiltHits();
      if( track_expectBLayerHit.IsActive() ) track_expectBLayerHit();
      if( track_nHits.IsActive() ) track_nHits();
      if( track_TRTHighTHitsRatio.IsActive() ) track_TRTHighTHitsRatio();
      if( track_TRTHighTOutliersRatio.IsActive() ) track_TRTHighTOutliersRatio();
      if( seedCalo_track_n.IsActive() ) seedCalo_track_n();
      if( seedCalo_wideTrk_n.IsActive() ) seedCalo_wideTrk_n();
      if( seedCalo_wideTrk_nBLHits.IsActive() ) seedCalo_wideTrk_nBLHits();
      if( seedCalo_wideTrk_nPixHits.IsActive() ) seedCalo_wideTrk_nPixHits();
      if( seedCalo_wideTrk_nSCTHits.IsActive() ) seedCalo_wideTrk_nSCTHits();
      if( seedCalo_wideTrk_nTRTHits.IsActive() ) seedCalo_wideTrk_nTRTHits();
      if( seedCalo_wideTrk_nTRTHighTHits.IsActive() ) seedCalo_wideTrk_nTRTHighTHits();
      if( seedCalo_wideTrk_nTRTXenonHits.IsActive() ) seedCalo_wideTrk_nTRTXenonHits();
      if( seedCalo_wideTrk_nPixHoles.IsActive() ) seedCalo_wideTrk_nPixHoles();
      if( seedCalo_wideTrk_nSCTHoles.IsActive() ) seedCalo_wideTrk_nSCTHoles();
      if( seedCalo_wideTrk_nTRTHoles.IsActive() ) seedCalo_wideTrk_nTRTHoles();
      if( seedCalo_wideTrk_nPixelDeadSensors.IsActive() ) seedCalo_wideTrk_nPixelDeadSensors();
      if( seedCalo_wideTrk_nSCTDeadSensors.IsActive() ) seedCalo_wideTrk_nSCTDeadSensors();
      if( seedCalo_wideTrk_nBLSharedHits.IsActive() ) seedCalo_wideTrk_nBLSharedHits();
      if( seedCalo_wideTrk_nPixSharedHits.IsActive() ) seedCalo_wideTrk_nPixSharedHits();
      if( seedCalo_wideTrk_nSCTSharedHits.IsActive() ) seedCalo_wideTrk_nSCTSharedHits();
      if( seedCalo_wideTrk_nBLayerSplitHits.IsActive() ) seedCalo_wideTrk_nBLayerSplitHits();
      if( seedCalo_wideTrk_nPixSplitHits.IsActive() ) seedCalo_wideTrk_nPixSplitHits();
      if( seedCalo_wideTrk_nBLayerOutliers.IsActive() ) seedCalo_wideTrk_nBLayerOutliers();
      if( seedCalo_wideTrk_nPixelOutliers.IsActive() ) seedCalo_wideTrk_nPixelOutliers();
      if( seedCalo_wideTrk_nSCTOutliers.IsActive() ) seedCalo_wideTrk_nSCTOutliers();
      if( seedCalo_wideTrk_nTRTOutliers.IsActive() ) seedCalo_wideTrk_nTRTOutliers();
      if( seedCalo_wideTrk_nTRTHighTOutliers.IsActive() ) seedCalo_wideTrk_nTRTHighTOutliers();
      if( seedCalo_wideTrk_nContribPixelLayers.IsActive() ) seedCalo_wideTrk_nContribPixelLayers();
      if( seedCalo_wideTrk_nGangedPixels.IsActive() ) seedCalo_wideTrk_nGangedPixels();
      if( seedCalo_wideTrk_nGangedFlaggedFakes.IsActive() ) seedCalo_wideTrk_nGangedFlaggedFakes();
      if( seedCalo_wideTrk_nPixelSpoiltHits.IsActive() ) seedCalo_wideTrk_nPixelSpoiltHits();
      if( seedCalo_wideTrk_nSCTDoubleHoles.IsActive() ) seedCalo_wideTrk_nSCTDoubleHoles();
      if( seedCalo_wideTrk_nSCTSpoiltHits.IsActive() ) seedCalo_wideTrk_nSCTSpoiltHits();
      if( seedCalo_wideTrk_expectBLayerHit.IsActive() ) seedCalo_wideTrk_expectBLayerHit();
      if( seedCalo_wideTrk_nHits.IsActive() ) seedCalo_wideTrk_nHits();
      if( otherTrk_n.IsActive() ) otherTrk_n();
      if( EF_dr.IsActive() ) EF_dr();
      if( EF_E.IsActive() ) EF_E();
      if( EF_Et.IsActive() ) EF_Et();
      if( EF_pt.IsActive() ) EF_pt();
      if( EF_eta.IsActive() ) EF_eta();
      if( EF_phi.IsActive() ) EF_phi();
      if( EF_matched.IsActive() ) EF_matched();
      if( L2_dr.IsActive() ) L2_dr();
      if( L2_E.IsActive() ) L2_E();
      if( L2_Et.IsActive() ) L2_Et();
      if( L2_pt.IsActive() ) L2_pt();
      if( L2_eta.IsActive() ) L2_eta();
      if( L2_phi.IsActive() ) L2_phi();
      if( L2_matched.IsActive() ) L2_matched();
      if( L1_dr.IsActive() ) L1_dr();
      if( L1_Et.IsActive() ) L1_Et();
      if( L1_pt.IsActive() ) L1_pt();
      if( L1_eta.IsActive() ) L1_eta();
      if( L1_phi.IsActive() ) L1_phi();
      if( L1_matched.IsActive() ) L1_matched();
if (!is_data) {
      if( trueTauAssocSmall_dr.IsActive() ) trueTauAssocSmall_dr();
      if( trueTauAssocSmall_index.IsActive() ) trueTauAssocSmall_index();
      if( trueTauAssocSmall_matched.IsActive() ) trueTauAssocSmall_matched();
} // end !is_data
      if( MET_Egamma10LooseTau_wpx.IsActive() ) MET_Egamma10LooseTau_wpx();
      if( MET_Egamma10LooseTau_wpy.IsActive() ) MET_Egamma10LooseTau_wpy();
      if( MET_Egamma10LooseTau_wet.IsActive() ) MET_Egamma10LooseTau_wet();
      if( MET_Egamma10LooseTau_statusWord.IsActive() ) MET_Egamma10LooseTau_statusWord();
      if( MET_wpx.IsActive() ) MET_wpx();
      if( MET_wpy.IsActive() ) MET_wpy();
      if( MET_wet.IsActive() ) MET_wet();
      if( MET_statusWord.IsActive() ) MET_statusWord();

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
   void TauD3PDObject::Clear( Option_t* ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Clear", "Objects used for reading a D3PD can't be cleared!" );
         return;
      }

      n() = 0;
      Et()->clear();
      pt()->clear();
      m()->clear();
      eta()->clear();
      phi()->clear();
      charge()->clear();
      BDTEleScore()->clear();
      BDTJetScore()->clear();
      likelihood()->clear();
      SafeLikelihood()->clear();
      electronVetoLoose()->clear();
      electronVetoMedium()->clear();
      electronVetoTight()->clear();
      muonVeto()->clear();
      tauLlhLoose()->clear();
      tauLlhMedium()->clear();
      tauLlhTight()->clear();
      JetBDTSigLoose()->clear();
      JetBDTSigMedium()->clear();
      JetBDTSigTight()->clear();
      EleBDTLoose()->clear();
      EleBDTMedium()->clear();
      EleBDTTight()->clear();
      author()->clear();
      RoIWord()->clear();
      nProng()->clear();
      numTrack()->clear();
      seedCalo_numTrack()->clear();
      seedCalo_nWideTrk()->clear();
      nOtherTrk()->clear();
      etOverPtLeadTrk()->clear();
      ipZ0SinThetaSigLeadTrk()->clear();
      leadTrkPt()->clear();
      nLooseTrk()->clear();
      nLooseConvTrk()->clear();
      nProngLoose()->clear();
      ipSigLeadTrk()->clear();
      ipSigLeadLooseTrk()->clear();
      etOverPtLeadLooseTrk()->clear();
      leadLooseTrkPt()->clear();
      chrgLooseTrk()->clear();
      massTrkSys()->clear();
      trkWidth2()->clear();
      trFlightPathSig()->clear();
      etEflow()->clear();
      mEflow()->clear();
      nPi0()->clear();
      ele_E237E277()->clear();
      ele_PresamplerFraction()->clear();
      ele_ECALFirstFraction()->clear();
      EM_TES_scale()->clear();
      LC_TES_precalib()->clear();
      TRTHTOverLT_LeadTrk()->clear();
      seedCalo_EMRadius()->clear();
      seedCalo_hadRadius()->clear();
      seedCalo_etEMAtEMScale()->clear();
      seedCalo_etHadAtEMScale()->clear();
      seedCalo_isolFrac()->clear();
      seedCalo_centFrac()->clear();
      seedCalo_stripWidth2()->clear();
      seedCalo_nStrip()->clear();
      seedCalo_eta()->clear();
      seedCalo_phi()->clear();
      seedCalo_nIsolLooseTrk()->clear();
      seedCalo_trkAvgDist()->clear();
      seedCalo_trkRmsDist()->clear();
      seedCalo_caloIso()->clear();
      seedCalo_caloIsoCorrected()->clear();
      seedCalo_dRmax()->clear();
      seedCalo_lead2ClusterEOverAllClusterE()->clear();
      seedCalo_lead3ClusterEOverAllClusterE()->clear();
      seedCalo_etHadCalib()->clear();
      seedCalo_etEMCalib()->clear();
      numTopoClusters()->clear();
      numEffTopoClusters()->clear();
      topoInvMass()->clear();
      effTopoInvMass()->clear();
      topoMeanDeltaR()->clear();
      effTopoMeanDeltaR()->clear();
      numCells()->clear();
      seedTrk_EMRadius()->clear();
      seedTrk_isolFrac()->clear();
      seedTrk_etChrgHadOverSumTrkPt()->clear();
      seedTrk_isolFracWide()->clear();
      seedTrk_etHadAtEMScale()->clear();
      seedTrk_etEMAtEMScale()->clear();
      seedTrk_etEMCL()->clear();
      seedTrk_etChrgEM()->clear();
      seedTrk_etNeuEM()->clear();
      seedTrk_etResNeuEM()->clear();
      seedTrk_hadLeakEt()->clear();
      seedTrk_sumEMCellEtOverLeadTrkPt()->clear();
      seedTrk_secMaxStripEt()->clear();
      seedTrk_stripWidth2()->clear();
      seedTrk_nStrip()->clear();
      seedTrk_etChrgHad()->clear();
      seedTrk_nOtherCoreTrk()->clear();
      seedTrk_nIsolTrk()->clear();
      seedTrk_etIsolEM()->clear();
      seedTrk_etIsolHad()->clear();
      cellBasedEnergyRing1()->clear();
      cellBasedEnergyRing2()->clear();
      cellBasedEnergyRing3()->clear();
      cellBasedEnergyRing4()->clear();
      cellBasedEnergyRing5()->clear();
      cellBasedEnergyRing6()->clear();
      cellBasedEnergyRing7()->clear();
      calcVars_etHad_EMScale_Pt3Trks()->clear();
      calcVars_etEM_EMScale_Pt3Trks()->clear();
      calcVars_ipSigLeadLooseTrk()->clear();
      calcVars_drMin()->clear();
      calcVars_calRadius()->clear();
      calcVars_EMFractionAtEMScale()->clear();
      calcVars_trackIso()->clear();
      calcVars_ChPiEMEOverCaloEME()->clear();
      calcVars_PSSFraction()->clear();
      calcVars_EMPOverTrkSysP()->clear();
      calcVars_pi0BDTPrimaryScore()->clear();
      calcVars_pi0BDTSecondaryScore()->clear();
      calcVars_corrCentFrac()->clear();
      calcVars_corrFTrk()->clear();
      calcVars_interAxis_eta()->clear();
      calcVars_interAxis_phi()->clear();
      pi0_cl1_pt()->clear();
      pi0_cl1_eta()->clear();
      pi0_cl1_phi()->clear();
      pi0_cl2_pt()->clear();
      pi0_cl2_eta()->clear();
      pi0_cl2_phi()->clear();
      pi0_vistau_pt()->clear();
      pi0_vistau_eta()->clear();
      pi0_vistau_phi()->clear();
      pi0_vistau_m()->clear();
      pi0_n()->clear();
      pantau_isPanTauCandidate()->clear();
      pantau_PanTauScore()->clear();
      pantau_NChargedEFO()->clear();
      pantau_NChargedQualifiedEFO()->clear();
      pantau_NNeutralEFO()->clear();
      pantau_AbsSumCharge()->clear();
      pantau_EflowJetMomentDRAll()->clear();
      pantau_EflowJetMomentDRChrg()->clear();
      pantau_EflowJetMomentDREMNeut()->clear();
      pantau_EflowJetMomentDRHADNeut()->clear();
      pantau_EtIn01OverEtIn02InvSigm()->clear();
      pantau_EtIn02To04OverTotalEtInvSigm()->clear();
      pantau_EtIn01OverEtIn04InvSigm()->clear();
      pantau_EtIn01OverEtIn04()->clear();
      pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents()->clear();
      pantau_JetSphericity()->clear();
      pantau_TransImpactParamSignfTrack1()->clear();
      pantau_EflowAngleJetAxisLeadingChargedQualified()->clear();
      pantau_EflowAngleChargedAxisNeutralAxis()->clear();
      pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified()->clear();
      pantau_EflowInvariantMassAll()->clear();
      pantau_EflowStdDevEtToSumEt()->clear();
      pantau_EflowEtLeadingChrgQualifiedOverTotalEt()->clear();
      pantau_EflowSumEAll()->clear();
      pantau_EflowChargedSumEt()->clear();
      leadTrack_eta()->clear();
      leadTrack_phi()->clear();
      cluster_E()->clear();
      cluster_eta()->clear();
      cluster_phi()->clear();
      cluster_eta_atTJVA()->clear();
      cluster_phi_atTJVA()->clear();
      cluster_PreSamplerStripF()->clear();
      cluster_EMLayer2F()->clear();
      cluster_EMLayer3F()->clear();
      cluster_n()->clear();
      Pi0Cluster_pt()->clear();
      Pi0Cluster_eta()->clear();
      Pi0Cluster_phi()->clear();
      secvtx_x()->clear();
      secvtx_y()->clear();
      secvtx_z()->clear();
      secvtx_xx()->clear();
      secvtx_yy()->clear();
      secvtx_zz()->clear();
      secvtx_xy()->clear();
      secvtx_yz()->clear();
      secvtx_zx()->clear();
      secvtx_chiSquared()->clear();
      secvtx_numberDoF()->clear();
      privtx_x()->clear();
      privtx_y()->clear();
      privtx_z()->clear();
      privtx_xx()->clear();
      privtx_yy()->clear();
      privtx_zz()->clear();
      privtx_xy()->clear();
      privtx_yz()->clear();
      privtx_zx()->clear();
      privtx_chiSquared()->clear();
      privtx_numberDoF()->clear();
      privtx_jvf()->clear();
      jet_Et()->clear();
      jet_pt()->clear();
      jet_m()->clear();
      jet_eta()->clear();
      jet_phi()->clear();
      jet_WIDTH()->clear();
      jet_n90()->clear();
      jet_n90constituents()->clear();
      jet_BCH_CORR_CELL()->clear();
      jet_BCH_CORR_JET()->clear();
      jet_BCH_CORR_JET_FORCELL()->clear();
      jet_ENG_BAD_CELLS()->clear();
      jet_N_BAD_CELLS()->clear();
      jet_N_BAD_CELLS_CORR()->clear();
      jet_BAD_CELLS_CORR_E()->clear();
      jet_Timing()->clear();
      jet_LArQuality()->clear();
      jet_nTrk()->clear();
      jet_sumPtTrk()->clear();
      jet_OriginIndex()->clear();
      jet_HECQuality()->clear();
      jet_NegativeE()->clear();
      jet_YFlip12()->clear();
      jet_YFlip23()->clear();
      jet_BCH_CORR_DOTX()->clear();
      jet_SamplingMax()->clear();
      jet_fracSamplingMax()->clear();
      jet_hecf()->clear();
      jet_tgap3f()->clear();
      jet_isUgly()->clear();
      jet_isBadLooseMinus()->clear();
      jet_isBadLoose()->clear();
      jet_isBadMedium()->clear();
      jet_isBadTight()->clear();
      jet_emfrac()->clear();
      jet_GCWJES()->clear();
      jet_EMJES()->clear();
      jet_emscale_E()->clear();
      jet_emscale_pt()->clear();
      jet_emscale_m()->clear();
      jet_emscale_eta()->clear();
      jet_emscale_phi()->clear();
      jet_jvtx_x()->clear();
      jet_jvtx_y()->clear();
      jet_jvtx_z()->clear();
      jet_jvtxf()->clear();
      jet_flavor_weight()->clear();
      jet_flavor_weight_TrackCounting2D()->clear();
      jet_flavor_weight_JetProb()->clear();
      jet_flavor_weight_IP1D()->clear();
      jet_flavor_weight_IP2D()->clear();
      jet_flavor_weight_IP3D()->clear();
      jet_flavor_weight_SV0()->clear();
      jet_flavor_weight_SV1()->clear();
      jet_flavor_weight_SV2()->clear();
      jet_flavor_weight_JetFitterTag()->clear();
      jet_flavor_weight_JetFitterCOMB()->clear();
      jet_flavor_weight_JetFitterTagNN()->clear();
      jet_flavor_weight_JetFitterCOMBNN()->clear();
      jet_flavor_weight_SoftMuonTag()->clear();
      jet_flavor_weight_SoftElectronTag()->clear();
      jet_flavor_weight_IP3DSV1()->clear();
      jet_e_PreSamplerB()->clear();
      jet_e_EMB1()->clear();
      jet_e_EMB2()->clear();
      jet_e_EMB3()->clear();
      jet_e_PreSamplerE()->clear();
      jet_e_EME1()->clear();
      jet_e_EME2()->clear();
      jet_e_EME3()->clear();
      jet_e_HEC0()->clear();
      jet_e_HEC1()->clear();
      jet_e_HEC2()->clear();
      jet_e_HEC3()->clear();
      jet_e_TileBar0()->clear();
      jet_e_TileBar1()->clear();
      jet_e_TileBar2()->clear();
      jet_e_TileGap1()->clear();
      jet_e_TileGap2()->clear();
      jet_e_TileGap3()->clear();
      jet_e_TileExt0()->clear();
      jet_e_TileExt1()->clear();
      jet_e_TileExt2()->clear();
      jet_e_FCAL0()->clear();
      jet_e_FCAL1()->clear();
      jet_e_FCAL2()->clear();
      jet_shapeBins()->clear();
      track_atTJVA_n()->clear();
      track_atTJVA_d0()->clear();
      track_atTJVA_z0()->clear();
      track_atTJVA_phi()->clear();
      track_atTJVA_theta()->clear();
      track_atTJVA_qoverp()->clear();
      track_atTJVA_pt()->clear();
      track_atTJVA_eta()->clear();
      seedCalo_wideTrk_atTJVA_n()->clear();
      seedCalo_wideTrk_atTJVA_d0()->clear();
      seedCalo_wideTrk_atTJVA_z0()->clear();
      seedCalo_wideTrk_atTJVA_phi()->clear();
      seedCalo_wideTrk_atTJVA_theta()->clear();
      seedCalo_wideTrk_atTJVA_qoverp()->clear();
      seedCalo_wideTrk_atTJVA_pt()->clear();
      seedCalo_wideTrk_atTJVA_eta()->clear();
      otherTrk_atTJVA_n()->clear();
      track_n()->clear();
      track_d0()->clear();
      track_z0()->clear();
      track_phi()->clear();
      track_theta()->clear();
      track_qoverp()->clear();
      track_pt()->clear();
      track_eta()->clear();
      track_atPV_d0()->clear();
      track_atPV_z0()->clear();
      track_atPV_phi()->clear();
      track_atPV_theta()->clear();
      track_atPV_qoverp()->clear();
      track_atPV_pt()->clear();
      track_atPV_eta()->clear();
      track_nBLHits()->clear();
      track_nPixHits()->clear();
      track_nSCTHits()->clear();
      track_nTRTHits()->clear();
      track_nTRTHighTHits()->clear();
      track_nTRTXenonHits()->clear();
      track_nPixHoles()->clear();
      track_nSCTHoles()->clear();
      track_nTRTHoles()->clear();
      track_nPixelDeadSensors()->clear();
      track_nSCTDeadSensors()->clear();
      track_nBLSharedHits()->clear();
      track_nPixSharedHits()->clear();
      track_nSCTSharedHits()->clear();
      track_nBLayerSplitHits()->clear();
      track_nPixSplitHits()->clear();
      track_nBLayerOutliers()->clear();
      track_nPixelOutliers()->clear();
      track_nSCTOutliers()->clear();
      track_nTRTOutliers()->clear();
      track_nTRTHighTOutliers()->clear();
      track_nContribPixelLayers()->clear();
      track_nGangedPixels()->clear();
      track_nGangedFlaggedFakes()->clear();
      track_nPixelSpoiltHits()->clear();
      track_nSCTDoubleHoles()->clear();
      track_nSCTSpoiltHits()->clear();
      track_expectBLayerHit()->clear();
      track_nHits()->clear();
      track_TRTHighTHitsRatio()->clear();
      track_TRTHighTOutliersRatio()->clear();
      seedCalo_track_n()->clear();
      seedCalo_wideTrk_n()->clear();
      seedCalo_wideTrk_nBLHits()->clear();
      seedCalo_wideTrk_nPixHits()->clear();
      seedCalo_wideTrk_nSCTHits()->clear();
      seedCalo_wideTrk_nTRTHits()->clear();
      seedCalo_wideTrk_nTRTHighTHits()->clear();
      seedCalo_wideTrk_nTRTXenonHits()->clear();
      seedCalo_wideTrk_nPixHoles()->clear();
      seedCalo_wideTrk_nSCTHoles()->clear();
      seedCalo_wideTrk_nTRTHoles()->clear();
      seedCalo_wideTrk_nPixelDeadSensors()->clear();
      seedCalo_wideTrk_nSCTDeadSensors()->clear();
      seedCalo_wideTrk_nBLSharedHits()->clear();
      seedCalo_wideTrk_nPixSharedHits()->clear();
      seedCalo_wideTrk_nSCTSharedHits()->clear();
      seedCalo_wideTrk_nBLayerSplitHits()->clear();
      seedCalo_wideTrk_nPixSplitHits()->clear();
      seedCalo_wideTrk_nBLayerOutliers()->clear();
      seedCalo_wideTrk_nPixelOutliers()->clear();
      seedCalo_wideTrk_nSCTOutliers()->clear();
      seedCalo_wideTrk_nTRTOutliers()->clear();
      seedCalo_wideTrk_nTRTHighTOutliers()->clear();
      seedCalo_wideTrk_nContribPixelLayers()->clear();
      seedCalo_wideTrk_nGangedPixels()->clear();
      seedCalo_wideTrk_nGangedFlaggedFakes()->clear();
      seedCalo_wideTrk_nPixelSpoiltHits()->clear();
      seedCalo_wideTrk_nSCTDoubleHoles()->clear();
      seedCalo_wideTrk_nSCTSpoiltHits()->clear();
      seedCalo_wideTrk_expectBLayerHit()->clear();
      seedCalo_wideTrk_nHits()->clear();
      otherTrk_n()->clear();
      EF_dr()->clear();
      EF_E()->clear();
      EF_Et()->clear();
      EF_pt()->clear();
      EF_eta()->clear();
      EF_phi()->clear();
      EF_matched()->clear();
      L2_dr()->clear();
      L2_E()->clear();
      L2_Et()->clear();
      L2_pt()->clear();
      L2_eta()->clear();
      L2_phi()->clear();
      L2_matched()->clear();
      L1_dr()->clear();
      L1_Et()->clear();
      L1_pt()->clear();
      L1_eta()->clear();
      L1_phi()->clear();
      L1_matched()->clear();
if (!is_data) {
      trueTauAssocSmall_dr()->clear();
      trueTauAssocSmall_index()->clear();
      trueTauAssocSmall_matched()->clear();
} // end !is_data
      MET_Egamma10LooseTau_wpx()->clear();
      MET_Egamma10LooseTau_wpy()->clear();
      MET_Egamma10LooseTau_wet()->clear();
      MET_Egamma10LooseTau_statusWord()->clear();
      MET_wpx()->clear();
      MET_wpy()->clear();
      MET_wet()->clear();
      MET_statusWord()->clear();

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
   TauD3PDObject& TauD3PDObject::Add( const TauD3PDObjectElement& el ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Add", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      ++( n() );
      if( el.Et.IsAvailable() ) {
         Et()->push_back( el.Et() );
      } else {
         Et()->push_back( std::numeric_limits< float >::min() );
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
      if( el.charge.IsAvailable() ) {
         charge()->push_back( el.charge() );
      } else {
         charge()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.BDTEleScore.IsAvailable() ) {
         BDTEleScore()->push_back( el.BDTEleScore() );
      } else {
         BDTEleScore()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.BDTJetScore.IsAvailable() ) {
         BDTJetScore()->push_back( el.BDTJetScore() );
      } else {
         BDTJetScore()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.likelihood.IsAvailable() ) {
         likelihood()->push_back( el.likelihood() );
      } else {
         likelihood()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.SafeLikelihood.IsAvailable() ) {
         SafeLikelihood()->push_back( el.SafeLikelihood() );
      } else {
         SafeLikelihood()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.electronVetoLoose.IsAvailable() ) {
         electronVetoLoose()->push_back( el.electronVetoLoose() );
      } else {
         electronVetoLoose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.electronVetoMedium.IsAvailable() ) {
         electronVetoMedium()->push_back( el.electronVetoMedium() );
      } else {
         electronVetoMedium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.electronVetoTight.IsAvailable() ) {
         electronVetoTight()->push_back( el.electronVetoTight() );
      } else {
         electronVetoTight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.muonVeto.IsAvailable() ) {
         muonVeto()->push_back( el.muonVeto() );
      } else {
         muonVeto()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tauLlhLoose.IsAvailable() ) {
         tauLlhLoose()->push_back( el.tauLlhLoose() );
      } else {
         tauLlhLoose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tauLlhMedium.IsAvailable() ) {
         tauLlhMedium()->push_back( el.tauLlhMedium() );
      } else {
         tauLlhMedium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tauLlhTight.IsAvailable() ) {
         tauLlhTight()->push_back( el.tauLlhTight() );
      } else {
         tauLlhTight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.JetBDTSigLoose.IsAvailable() ) {
         JetBDTSigLoose()->push_back( el.JetBDTSigLoose() );
      } else {
         JetBDTSigLoose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.JetBDTSigMedium.IsAvailable() ) {
         JetBDTSigMedium()->push_back( el.JetBDTSigMedium() );
      } else {
         JetBDTSigMedium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.JetBDTSigTight.IsAvailable() ) {
         JetBDTSigTight()->push_back( el.JetBDTSigTight() );
      } else {
         JetBDTSigTight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.EleBDTLoose.IsAvailable() ) {
         EleBDTLoose()->push_back( el.EleBDTLoose() );
      } else {
         EleBDTLoose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.EleBDTMedium.IsAvailable() ) {
         EleBDTMedium()->push_back( el.EleBDTMedium() );
      } else {
         EleBDTMedium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.EleBDTTight.IsAvailable() ) {
         EleBDTTight()->push_back( el.EleBDTTight() );
      } else {
         EleBDTTight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.author.IsAvailable() ) {
         author()->push_back( el.author() );
      } else {
         author()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.RoIWord.IsAvailable() ) {
         RoIWord()->push_back( el.RoIWord() );
      } else {
         RoIWord()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nProng.IsAvailable() ) {
         nProng()->push_back( el.nProng() );
      } else {
         nProng()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.numTrack.IsAvailable() ) {
         numTrack()->push_back( el.numTrack() );
      } else {
         numTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.seedCalo_numTrack.IsAvailable() ) {
         seedCalo_numTrack()->push_back( el.seedCalo_numTrack() );
      } else {
         seedCalo_numTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.seedCalo_nWideTrk.IsAvailable() ) {
         seedCalo_nWideTrk()->push_back( el.seedCalo_nWideTrk() );
      } else {
         seedCalo_nWideTrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nOtherTrk.IsAvailable() ) {
         nOtherTrk()->push_back( el.nOtherTrk() );
      } else {
         nOtherTrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.etOverPtLeadTrk.IsAvailable() ) {
         etOverPtLeadTrk()->push_back( el.etOverPtLeadTrk() );
      } else {
         etOverPtLeadTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ipZ0SinThetaSigLeadTrk.IsAvailable() ) {
         ipZ0SinThetaSigLeadTrk()->push_back( el.ipZ0SinThetaSigLeadTrk() );
      } else {
         ipZ0SinThetaSigLeadTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.leadTrkPt.IsAvailable() ) {
         leadTrkPt()->push_back( el.leadTrkPt() );
      } else {
         leadTrkPt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nLooseTrk.IsAvailable() ) {
         nLooseTrk()->push_back( el.nLooseTrk() );
      } else {
         nLooseTrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nLooseConvTrk.IsAvailable() ) {
         nLooseConvTrk()->push_back( el.nLooseConvTrk() );
      } else {
         nLooseConvTrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nProngLoose.IsAvailable() ) {
         nProngLoose()->push_back( el.nProngLoose() );
      } else {
         nProngLoose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.ipSigLeadTrk.IsAvailable() ) {
         ipSigLeadTrk()->push_back( el.ipSigLeadTrk() );
      } else {
         ipSigLeadTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ipSigLeadLooseTrk.IsAvailable() ) {
         ipSigLeadLooseTrk()->push_back( el.ipSigLeadLooseTrk() );
      } else {
         ipSigLeadLooseTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etOverPtLeadLooseTrk.IsAvailable() ) {
         etOverPtLeadLooseTrk()->push_back( el.etOverPtLeadLooseTrk() );
      } else {
         etOverPtLeadLooseTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.leadLooseTrkPt.IsAvailable() ) {
         leadLooseTrkPt()->push_back( el.leadLooseTrkPt() );
      } else {
         leadLooseTrkPt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.chrgLooseTrk.IsAvailable() ) {
         chrgLooseTrk()->push_back( el.chrgLooseTrk() );
      } else {
         chrgLooseTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.massTrkSys.IsAvailable() ) {
         massTrkSys()->push_back( el.massTrkSys() );
      } else {
         massTrkSys()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trkWidth2.IsAvailable() ) {
         trkWidth2()->push_back( el.trkWidth2() );
      } else {
         trkWidth2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trFlightPathSig.IsAvailable() ) {
         trFlightPathSig()->push_back( el.trFlightPathSig() );
      } else {
         trFlightPathSig()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etEflow.IsAvailable() ) {
         etEflow()->push_back( el.etEflow() );
      } else {
         etEflow()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.mEflow.IsAvailable() ) {
         mEflow()->push_back( el.mEflow() );
      } else {
         mEflow()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nPi0.IsAvailable() ) {
         nPi0()->push_back( el.nPi0() );
      } else {
         nPi0()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.ele_E237E277.IsAvailable() ) {
         ele_E237E277()->push_back( el.ele_E237E277() );
      } else {
         ele_E237E277()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ele_PresamplerFraction.IsAvailable() ) {
         ele_PresamplerFraction()->push_back( el.ele_PresamplerFraction() );
      } else {
         ele_PresamplerFraction()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ele_ECALFirstFraction.IsAvailable() ) {
         ele_ECALFirstFraction()->push_back( el.ele_ECALFirstFraction() );
      } else {
         ele_ECALFirstFraction()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EM_TES_scale.IsAvailable() ) {
         EM_TES_scale()->push_back( el.EM_TES_scale() );
      } else {
         EM_TES_scale()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.LC_TES_precalib.IsAvailable() ) {
         LC_TES_precalib()->push_back( el.LC_TES_precalib() );
      } else {
         LC_TES_precalib()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.TRTHTOverLT_LeadTrk.IsAvailable() ) {
         TRTHTOverLT_LeadTrk()->push_back( el.TRTHTOverLT_LeadTrk() );
      } else {
         TRTHTOverLT_LeadTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_EMRadius.IsAvailable() ) {
         seedCalo_EMRadius()->push_back( el.seedCalo_EMRadius() );
      } else {
         seedCalo_EMRadius()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_hadRadius.IsAvailable() ) {
         seedCalo_hadRadius()->push_back( el.seedCalo_hadRadius() );
      } else {
         seedCalo_hadRadius()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_etEMAtEMScale.IsAvailable() ) {
         seedCalo_etEMAtEMScale()->push_back( el.seedCalo_etEMAtEMScale() );
      } else {
         seedCalo_etEMAtEMScale()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_etHadAtEMScale.IsAvailable() ) {
         seedCalo_etHadAtEMScale()->push_back( el.seedCalo_etHadAtEMScale() );
      } else {
         seedCalo_etHadAtEMScale()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_isolFrac.IsAvailable() ) {
         seedCalo_isolFrac()->push_back( el.seedCalo_isolFrac() );
      } else {
         seedCalo_isolFrac()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_centFrac.IsAvailable() ) {
         seedCalo_centFrac()->push_back( el.seedCalo_centFrac() );
      } else {
         seedCalo_centFrac()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_stripWidth2.IsAvailable() ) {
         seedCalo_stripWidth2()->push_back( el.seedCalo_stripWidth2() );
      } else {
         seedCalo_stripWidth2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_nStrip.IsAvailable() ) {
         seedCalo_nStrip()->push_back( el.seedCalo_nStrip() );
      } else {
         seedCalo_nStrip()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.seedCalo_eta.IsAvailable() ) {
         seedCalo_eta()->push_back( el.seedCalo_eta() );
      } else {
         seedCalo_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_phi.IsAvailable() ) {
         seedCalo_phi()->push_back( el.seedCalo_phi() );
      } else {
         seedCalo_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_nIsolLooseTrk.IsAvailable() ) {
         seedCalo_nIsolLooseTrk()->push_back( el.seedCalo_nIsolLooseTrk() );
      } else {
         seedCalo_nIsolLooseTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_trkAvgDist.IsAvailable() ) {
         seedCalo_trkAvgDist()->push_back( el.seedCalo_trkAvgDist() );
      } else {
         seedCalo_trkAvgDist()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_trkRmsDist.IsAvailable() ) {
         seedCalo_trkRmsDist()->push_back( el.seedCalo_trkRmsDist() );
      } else {
         seedCalo_trkRmsDist()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_caloIso.IsAvailable() ) {
         seedCalo_caloIso()->push_back( el.seedCalo_caloIso() );
      } else {
         seedCalo_caloIso()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_caloIsoCorrected.IsAvailable() ) {
         seedCalo_caloIsoCorrected()->push_back( el.seedCalo_caloIsoCorrected() );
      } else {
         seedCalo_caloIsoCorrected()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_dRmax.IsAvailable() ) {
         seedCalo_dRmax()->push_back( el.seedCalo_dRmax() );
      } else {
         seedCalo_dRmax()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_lead2ClusterEOverAllClusterE.IsAvailable() ) {
         seedCalo_lead2ClusterEOverAllClusterE()->push_back( el.seedCalo_lead2ClusterEOverAllClusterE() );
      } else {
         seedCalo_lead2ClusterEOverAllClusterE()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_lead3ClusterEOverAllClusterE.IsAvailable() ) {
         seedCalo_lead3ClusterEOverAllClusterE()->push_back( el.seedCalo_lead3ClusterEOverAllClusterE() );
      } else {
         seedCalo_lead3ClusterEOverAllClusterE()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_etHadCalib.IsAvailable() ) {
         seedCalo_etHadCalib()->push_back( el.seedCalo_etHadCalib() );
      } else {
         seedCalo_etHadCalib()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedCalo_etEMCalib.IsAvailable() ) {
         seedCalo_etEMCalib()->push_back( el.seedCalo_etEMCalib() );
      } else {
         seedCalo_etEMCalib()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.numTopoClusters.IsAvailable() ) {
         numTopoClusters()->push_back( el.numTopoClusters() );
      } else {
         numTopoClusters()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.numEffTopoClusters.IsAvailable() ) {
         numEffTopoClusters()->push_back( el.numEffTopoClusters() );
      } else {
         numEffTopoClusters()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoInvMass.IsAvailable() ) {
         topoInvMass()->push_back( el.topoInvMass() );
      } else {
         topoInvMass()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.effTopoInvMass.IsAvailable() ) {
         effTopoInvMass()->push_back( el.effTopoInvMass() );
      } else {
         effTopoInvMass()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoMeanDeltaR.IsAvailable() ) {
         topoMeanDeltaR()->push_back( el.topoMeanDeltaR() );
      } else {
         topoMeanDeltaR()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.effTopoMeanDeltaR.IsAvailable() ) {
         effTopoMeanDeltaR()->push_back( el.effTopoMeanDeltaR() );
      } else {
         effTopoMeanDeltaR()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.numCells.IsAvailable() ) {
         numCells()->push_back( el.numCells() );
      } else {
         numCells()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_EMRadius.IsAvailable() ) {
         seedTrk_EMRadius()->push_back( el.seedTrk_EMRadius() );
      } else {
         seedTrk_EMRadius()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_isolFrac.IsAvailable() ) {
         seedTrk_isolFrac()->push_back( el.seedTrk_isolFrac() );
      } else {
         seedTrk_isolFrac()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_etChrgHadOverSumTrkPt.IsAvailable() ) {
         seedTrk_etChrgHadOverSumTrkPt()->push_back( el.seedTrk_etChrgHadOverSumTrkPt() );
      } else {
         seedTrk_etChrgHadOverSumTrkPt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_isolFracWide.IsAvailable() ) {
         seedTrk_isolFracWide()->push_back( el.seedTrk_isolFracWide() );
      } else {
         seedTrk_isolFracWide()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_etHadAtEMScale.IsAvailable() ) {
         seedTrk_etHadAtEMScale()->push_back( el.seedTrk_etHadAtEMScale() );
      } else {
         seedTrk_etHadAtEMScale()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_etEMAtEMScale.IsAvailable() ) {
         seedTrk_etEMAtEMScale()->push_back( el.seedTrk_etEMAtEMScale() );
      } else {
         seedTrk_etEMAtEMScale()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_etEMCL.IsAvailable() ) {
         seedTrk_etEMCL()->push_back( el.seedTrk_etEMCL() );
      } else {
         seedTrk_etEMCL()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_etChrgEM.IsAvailable() ) {
         seedTrk_etChrgEM()->push_back( el.seedTrk_etChrgEM() );
      } else {
         seedTrk_etChrgEM()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_etNeuEM.IsAvailable() ) {
         seedTrk_etNeuEM()->push_back( el.seedTrk_etNeuEM() );
      } else {
         seedTrk_etNeuEM()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_etResNeuEM.IsAvailable() ) {
         seedTrk_etResNeuEM()->push_back( el.seedTrk_etResNeuEM() );
      } else {
         seedTrk_etResNeuEM()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_hadLeakEt.IsAvailable() ) {
         seedTrk_hadLeakEt()->push_back( el.seedTrk_hadLeakEt() );
      } else {
         seedTrk_hadLeakEt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_sumEMCellEtOverLeadTrkPt.IsAvailable() ) {
         seedTrk_sumEMCellEtOverLeadTrkPt()->push_back( el.seedTrk_sumEMCellEtOverLeadTrkPt() );
      } else {
         seedTrk_sumEMCellEtOverLeadTrkPt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_secMaxStripEt.IsAvailable() ) {
         seedTrk_secMaxStripEt()->push_back( el.seedTrk_secMaxStripEt() );
      } else {
         seedTrk_secMaxStripEt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_stripWidth2.IsAvailable() ) {
         seedTrk_stripWidth2()->push_back( el.seedTrk_stripWidth2() );
      } else {
         seedTrk_stripWidth2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_nStrip.IsAvailable() ) {
         seedTrk_nStrip()->push_back( el.seedTrk_nStrip() );
      } else {
         seedTrk_nStrip()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.seedTrk_etChrgHad.IsAvailable() ) {
         seedTrk_etChrgHad()->push_back( el.seedTrk_etChrgHad() );
      } else {
         seedTrk_etChrgHad()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_nOtherCoreTrk.IsAvailable() ) {
         seedTrk_nOtherCoreTrk()->push_back( el.seedTrk_nOtherCoreTrk() );
      } else {
         seedTrk_nOtherCoreTrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.seedTrk_nIsolTrk.IsAvailable() ) {
         seedTrk_nIsolTrk()->push_back( el.seedTrk_nIsolTrk() );
      } else {
         seedTrk_nIsolTrk()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.seedTrk_etIsolEM.IsAvailable() ) {
         seedTrk_etIsolEM()->push_back( el.seedTrk_etIsolEM() );
      } else {
         seedTrk_etIsolEM()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.seedTrk_etIsolHad.IsAvailable() ) {
         seedTrk_etIsolHad()->push_back( el.seedTrk_etIsolHad() );
      } else {
         seedTrk_etIsolHad()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cellBasedEnergyRing1.IsAvailable() ) {
         cellBasedEnergyRing1()->push_back( el.cellBasedEnergyRing1() );
      } else {
         cellBasedEnergyRing1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cellBasedEnergyRing2.IsAvailable() ) {
         cellBasedEnergyRing2()->push_back( el.cellBasedEnergyRing2() );
      } else {
         cellBasedEnergyRing2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cellBasedEnergyRing3.IsAvailable() ) {
         cellBasedEnergyRing3()->push_back( el.cellBasedEnergyRing3() );
      } else {
         cellBasedEnergyRing3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cellBasedEnergyRing4.IsAvailable() ) {
         cellBasedEnergyRing4()->push_back( el.cellBasedEnergyRing4() );
      } else {
         cellBasedEnergyRing4()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cellBasedEnergyRing5.IsAvailable() ) {
         cellBasedEnergyRing5()->push_back( el.cellBasedEnergyRing5() );
      } else {
         cellBasedEnergyRing5()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cellBasedEnergyRing6.IsAvailable() ) {
         cellBasedEnergyRing6()->push_back( el.cellBasedEnergyRing6() );
      } else {
         cellBasedEnergyRing6()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cellBasedEnergyRing7.IsAvailable() ) {
         cellBasedEnergyRing7()->push_back( el.cellBasedEnergyRing7() );
      } else {
         cellBasedEnergyRing7()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_etHad_EMScale_Pt3Trks.IsAvailable() ) {
         calcVars_etHad_EMScale_Pt3Trks()->push_back( el.calcVars_etHad_EMScale_Pt3Trks() );
      } else {
         calcVars_etHad_EMScale_Pt3Trks()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_etEM_EMScale_Pt3Trks.IsAvailable() ) {
         calcVars_etEM_EMScale_Pt3Trks()->push_back( el.calcVars_etEM_EMScale_Pt3Trks() );
      } else {
         calcVars_etEM_EMScale_Pt3Trks()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_ipSigLeadLooseTrk.IsAvailable() ) {
         calcVars_ipSigLeadLooseTrk()->push_back( el.calcVars_ipSigLeadLooseTrk() );
      } else {
         calcVars_ipSigLeadLooseTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_drMin.IsAvailable() ) {
         calcVars_drMin()->push_back( el.calcVars_drMin() );
      } else {
         calcVars_drMin()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_calRadius.IsAvailable() ) {
         calcVars_calRadius()->push_back( el.calcVars_calRadius() );
      } else {
         calcVars_calRadius()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_EMFractionAtEMScale.IsAvailable() ) {
         calcVars_EMFractionAtEMScale()->push_back( el.calcVars_EMFractionAtEMScale() );
      } else {
         calcVars_EMFractionAtEMScale()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_trackIso.IsAvailable() ) {
         calcVars_trackIso()->push_back( el.calcVars_trackIso() );
      } else {
         calcVars_trackIso()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_ChPiEMEOverCaloEME.IsAvailable() ) {
         calcVars_ChPiEMEOverCaloEME()->push_back( el.calcVars_ChPiEMEOverCaloEME() );
      } else {
         calcVars_ChPiEMEOverCaloEME()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_PSSFraction.IsAvailable() ) {
         calcVars_PSSFraction()->push_back( el.calcVars_PSSFraction() );
      } else {
         calcVars_PSSFraction()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_EMPOverTrkSysP.IsAvailable() ) {
         calcVars_EMPOverTrkSysP()->push_back( el.calcVars_EMPOverTrkSysP() );
      } else {
         calcVars_EMPOverTrkSysP()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_pi0BDTPrimaryScore.IsAvailable() ) {
         calcVars_pi0BDTPrimaryScore()->push_back( el.calcVars_pi0BDTPrimaryScore() );
      } else {
         calcVars_pi0BDTPrimaryScore()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_pi0BDTSecondaryScore.IsAvailable() ) {
         calcVars_pi0BDTSecondaryScore()->push_back( el.calcVars_pi0BDTSecondaryScore() );
      } else {
         calcVars_pi0BDTSecondaryScore()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_corrCentFrac.IsAvailable() ) {
         calcVars_corrCentFrac()->push_back( el.calcVars_corrCentFrac() );
      } else {
         calcVars_corrCentFrac()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_corrFTrk.IsAvailable() ) {
         calcVars_corrFTrk()->push_back( el.calcVars_corrFTrk() );
      } else {
         calcVars_corrFTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_interAxis_eta.IsAvailable() ) {
         calcVars_interAxis_eta()->push_back( el.calcVars_interAxis_eta() );
      } else {
         calcVars_interAxis_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.calcVars_interAxis_phi.IsAvailable() ) {
         calcVars_interAxis_phi()->push_back( el.calcVars_interAxis_phi() );
      } else {
         calcVars_interAxis_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pi0_cl1_pt.IsAvailable() ) {
         pi0_cl1_pt()->push_back( el.pi0_cl1_pt() );
      } else {
         pi0_cl1_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pi0_cl1_eta.IsAvailable() ) {
         pi0_cl1_eta()->push_back( el.pi0_cl1_eta() );
      } else {
         pi0_cl1_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pi0_cl1_phi.IsAvailable() ) {
         pi0_cl1_phi()->push_back( el.pi0_cl1_phi() );
      } else {
         pi0_cl1_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pi0_cl2_pt.IsAvailable() ) {
         pi0_cl2_pt()->push_back( el.pi0_cl2_pt() );
      } else {
         pi0_cl2_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pi0_cl2_eta.IsAvailable() ) {
         pi0_cl2_eta()->push_back( el.pi0_cl2_eta() );
      } else {
         pi0_cl2_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pi0_cl2_phi.IsAvailable() ) {
         pi0_cl2_phi()->push_back( el.pi0_cl2_phi() );
      } else {
         pi0_cl2_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pi0_vistau_pt.IsAvailable() ) {
         pi0_vistau_pt()->push_back( el.pi0_vistau_pt() );
      } else {
         pi0_vistau_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pi0_vistau_eta.IsAvailable() ) {
         pi0_vistau_eta()->push_back( el.pi0_vistau_eta() );
      } else {
         pi0_vistau_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pi0_vistau_phi.IsAvailable() ) {
         pi0_vistau_phi()->push_back( el.pi0_vistau_phi() );
      } else {
         pi0_vistau_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pi0_vistau_m.IsAvailable() ) {
         pi0_vistau_m()->push_back( el.pi0_vistau_m() );
      } else {
         pi0_vistau_m()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pi0_n.IsAvailable() ) {
         pi0_n()->push_back( el.pi0_n() );
      } else {
         pi0_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.pantau_isPanTauCandidate.IsAvailable() ) {
         pantau_isPanTauCandidate()->push_back( el.pantau_isPanTauCandidate() );
      } else {
         pantau_isPanTauCandidate()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.pantau_PanTauScore.IsAvailable() ) {
         pantau_PanTauScore()->push_back( el.pantau_PanTauScore() );
      } else {
         pantau_PanTauScore()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_NChargedEFO.IsAvailable() ) {
         pantau_NChargedEFO()->push_back( el.pantau_NChargedEFO() );
      } else {
         pantau_NChargedEFO()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.pantau_NChargedQualifiedEFO.IsAvailable() ) {
         pantau_NChargedQualifiedEFO()->push_back( el.pantau_NChargedQualifiedEFO() );
      } else {
         pantau_NChargedQualifiedEFO()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.pantau_NNeutralEFO.IsAvailable() ) {
         pantau_NNeutralEFO()->push_back( el.pantau_NNeutralEFO() );
      } else {
         pantau_NNeutralEFO()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.pantau_AbsSumCharge.IsAvailable() ) {
         pantau_AbsSumCharge()->push_back( el.pantau_AbsSumCharge() );
      } else {
         pantau_AbsSumCharge()->push_back( std::numeric_limits< unsigned int >::min() );
      }
      if( el.pantau_EflowJetMomentDRAll.IsAvailable() ) {
         pantau_EflowJetMomentDRAll()->push_back( el.pantau_EflowJetMomentDRAll() );
      } else {
         pantau_EflowJetMomentDRAll()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_EflowJetMomentDRChrg.IsAvailable() ) {
         pantau_EflowJetMomentDRChrg()->push_back( el.pantau_EflowJetMomentDRChrg() );
      } else {
         pantau_EflowJetMomentDRChrg()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_EflowJetMomentDREMNeut.IsAvailable() ) {
         pantau_EflowJetMomentDREMNeut()->push_back( el.pantau_EflowJetMomentDREMNeut() );
      } else {
         pantau_EflowJetMomentDREMNeut()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_EflowJetMomentDRHADNeut.IsAvailable() ) {
         pantau_EflowJetMomentDRHADNeut()->push_back( el.pantau_EflowJetMomentDRHADNeut() );
      } else {
         pantau_EflowJetMomentDRHADNeut()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_EtIn01OverEtIn02InvSigm.IsAvailable() ) {
         pantau_EtIn01OverEtIn02InvSigm()->push_back( el.pantau_EtIn01OverEtIn02InvSigm() );
      } else {
         pantau_EtIn01OverEtIn02InvSigm()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_EtIn02To04OverTotalEtInvSigm.IsAvailable() ) {
         pantau_EtIn02To04OverTotalEtInvSigm()->push_back( el.pantau_EtIn02To04OverTotalEtInvSigm() );
      } else {
         pantau_EtIn02To04OverTotalEtInvSigm()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_EtIn01OverEtIn04InvSigm.IsAvailable() ) {
         pantau_EtIn01OverEtIn04InvSigm()->push_back( el.pantau_EtIn01OverEtIn04InvSigm() );
      } else {
         pantau_EtIn01OverEtIn04InvSigm()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_EtIn01OverEtIn04.IsAvailable() ) {
         pantau_EtIn01OverEtIn04()->push_back( el.pantau_EtIn01OverEtIn04() );
      } else {
         pantau_EtIn01OverEtIn04()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents.IsAvailable() ) {
         pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents()->push_back( el.pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents() );
      } else {
         pantau_EflowMeanAngleBtwLeadingChargedQualifiedComponents()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_JetSphericity.IsAvailable() ) {
         pantau_JetSphericity()->push_back( el.pantau_JetSphericity() );
      } else {
         pantau_JetSphericity()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_TransImpactParamSignfTrack1.IsAvailable() ) {
         pantau_TransImpactParamSignfTrack1()->push_back( el.pantau_TransImpactParamSignfTrack1() );
      } else {
         pantau_TransImpactParamSignfTrack1()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_EflowAngleJetAxisLeadingChargedQualified.IsAvailable() ) {
         pantau_EflowAngleJetAxisLeadingChargedQualified()->push_back( el.pantau_EflowAngleJetAxisLeadingChargedQualified() );
      } else {
         pantau_EflowAngleJetAxisLeadingChargedQualified()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_EflowAngleChargedAxisNeutralAxis.IsAvailable() ) {
         pantau_EflowAngleChargedAxisNeutralAxis()->push_back( el.pantau_EflowAngleChargedAxisNeutralAxis() );
      } else {
         pantau_EflowAngleChargedAxisNeutralAxis()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified.IsAvailable() ) {
         pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified()->push_back( el.pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified() );
      } else {
         pantau_EflowAngleLeadingChrgQualified2ndLeadingChrgQualified()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_EflowInvariantMassAll.IsAvailable() ) {
         pantau_EflowInvariantMassAll()->push_back( el.pantau_EflowInvariantMassAll() );
      } else {
         pantau_EflowInvariantMassAll()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_EflowStdDevEtToSumEt.IsAvailable() ) {
         pantau_EflowStdDevEtToSumEt()->push_back( el.pantau_EflowStdDevEtToSumEt() );
      } else {
         pantau_EflowStdDevEtToSumEt()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_EflowEtLeadingChrgQualifiedOverTotalEt.IsAvailable() ) {
         pantau_EflowEtLeadingChrgQualifiedOverTotalEt()->push_back( el.pantau_EflowEtLeadingChrgQualifiedOverTotalEt() );
      } else {
         pantau_EflowEtLeadingChrgQualifiedOverTotalEt()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_EflowSumEAll.IsAvailable() ) {
         pantau_EflowSumEAll()->push_back( el.pantau_EflowSumEAll() );
      } else {
         pantau_EflowSumEAll()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.pantau_EflowChargedSumEt.IsAvailable() ) {
         pantau_EflowChargedSumEt()->push_back( el.pantau_EflowChargedSumEt() );
      } else {
         pantau_EflowChargedSumEt()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.leadTrack_eta.IsAvailable() ) {
         leadTrack_eta()->push_back( el.leadTrack_eta() );
      } else {
         leadTrack_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.leadTrack_phi.IsAvailable() ) {
         leadTrack_phi()->push_back( el.leadTrack_phi() );
      } else {
         leadTrack_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cluster_E.IsAvailable() ) {
         cluster_E()->push_back( el.cluster_E() );
      } else {
         cluster_E()->push_back( vector<float>() );
      }
      if( el.cluster_eta.IsAvailable() ) {
         cluster_eta()->push_back( el.cluster_eta() );
      } else {
         cluster_eta()->push_back( vector<float>() );
      }
      if( el.cluster_phi.IsAvailable() ) {
         cluster_phi()->push_back( el.cluster_phi() );
      } else {
         cluster_phi()->push_back( vector<float>() );
      }
      if( el.cluster_eta_atTJVA.IsAvailable() ) {
         cluster_eta_atTJVA()->push_back( el.cluster_eta_atTJVA() );
      } else {
         cluster_eta_atTJVA()->push_back( vector<float>() );
      }
      if( el.cluster_phi_atTJVA.IsAvailable() ) {
         cluster_phi_atTJVA()->push_back( el.cluster_phi_atTJVA() );
      } else {
         cluster_phi_atTJVA()->push_back( vector<float>() );
      }
      if( el.cluster_PreSamplerStripF.IsAvailable() ) {
         cluster_PreSamplerStripF()->push_back( el.cluster_PreSamplerStripF() );
      } else {
         cluster_PreSamplerStripF()->push_back( vector<float>() );
      }
      if( el.cluster_EMLayer2F.IsAvailable() ) {
         cluster_EMLayer2F()->push_back( el.cluster_EMLayer2F() );
      } else {
         cluster_EMLayer2F()->push_back( vector<float>() );
      }
      if( el.cluster_EMLayer3F.IsAvailable() ) {
         cluster_EMLayer3F()->push_back( el.cluster_EMLayer3F() );
      } else {
         cluster_EMLayer3F()->push_back( vector<float>() );
      }
      if( el.cluster_n.IsAvailable() ) {
         cluster_n()->push_back( el.cluster_n() );
      } else {
         cluster_n()->push_back( std::numeric_limits< unsigned int >::min() );
      }
      if( el.Pi0Cluster_pt.IsAvailable() ) {
         Pi0Cluster_pt()->push_back( el.Pi0Cluster_pt() );
      } else {
         Pi0Cluster_pt()->push_back( vector<float>() );
      }
      if( el.Pi0Cluster_eta.IsAvailable() ) {
         Pi0Cluster_eta()->push_back( el.Pi0Cluster_eta() );
      } else {
         Pi0Cluster_eta()->push_back( vector<float>() );
      }
      if( el.Pi0Cluster_phi.IsAvailable() ) {
         Pi0Cluster_phi()->push_back( el.Pi0Cluster_phi() );
      } else {
         Pi0Cluster_phi()->push_back( vector<float>() );
      }
      if( el.secvtx_x.IsAvailable() ) {
         secvtx_x()->push_back( el.secvtx_x() );
      } else {
         secvtx_x()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.secvtx_y.IsAvailable() ) {
         secvtx_y()->push_back( el.secvtx_y() );
      } else {
         secvtx_y()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.secvtx_z.IsAvailable() ) {
         secvtx_z()->push_back( el.secvtx_z() );
      } else {
         secvtx_z()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.secvtx_xx.IsAvailable() ) {
         secvtx_xx()->push_back( el.secvtx_xx() );
      } else {
         secvtx_xx()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.secvtx_yy.IsAvailable() ) {
         secvtx_yy()->push_back( el.secvtx_yy() );
      } else {
         secvtx_yy()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.secvtx_zz.IsAvailable() ) {
         secvtx_zz()->push_back( el.secvtx_zz() );
      } else {
         secvtx_zz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.secvtx_xy.IsAvailable() ) {
         secvtx_xy()->push_back( el.secvtx_xy() );
      } else {
         secvtx_xy()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.secvtx_yz.IsAvailable() ) {
         secvtx_yz()->push_back( el.secvtx_yz() );
      } else {
         secvtx_yz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.secvtx_zx.IsAvailable() ) {
         secvtx_zx()->push_back( el.secvtx_zx() );
      } else {
         secvtx_zx()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.secvtx_chiSquared.IsAvailable() ) {
         secvtx_chiSquared()->push_back( el.secvtx_chiSquared() );
      } else {
         secvtx_chiSquared()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.secvtx_numberDoF.IsAvailable() ) {
         secvtx_numberDoF()->push_back( el.secvtx_numberDoF() );
      } else {
         secvtx_numberDoF()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.privtx_x.IsAvailable() ) {
         privtx_x()->push_back( el.privtx_x() );
      } else {
         privtx_x()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.privtx_y.IsAvailable() ) {
         privtx_y()->push_back( el.privtx_y() );
      } else {
         privtx_y()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.privtx_z.IsAvailable() ) {
         privtx_z()->push_back( el.privtx_z() );
      } else {
         privtx_z()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.privtx_xx.IsAvailable() ) {
         privtx_xx()->push_back( el.privtx_xx() );
      } else {
         privtx_xx()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.privtx_yy.IsAvailable() ) {
         privtx_yy()->push_back( el.privtx_yy() );
      } else {
         privtx_yy()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.privtx_zz.IsAvailable() ) {
         privtx_zz()->push_back( el.privtx_zz() );
      } else {
         privtx_zz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.privtx_xy.IsAvailable() ) {
         privtx_xy()->push_back( el.privtx_xy() );
      } else {
         privtx_xy()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.privtx_yz.IsAvailable() ) {
         privtx_yz()->push_back( el.privtx_yz() );
      } else {
         privtx_yz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.privtx_zx.IsAvailable() ) {
         privtx_zx()->push_back( el.privtx_zx() );
      } else {
         privtx_zx()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.privtx_chiSquared.IsAvailable() ) {
         privtx_chiSquared()->push_back( el.privtx_chiSquared() );
      } else {
         privtx_chiSquared()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.privtx_numberDoF.IsAvailable() ) {
         privtx_numberDoF()->push_back( el.privtx_numberDoF() );
      } else {
         privtx_numberDoF()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.privtx_jvf.IsAvailable() ) {
         privtx_jvf()->push_back( el.privtx_jvf() );
      } else {
         privtx_jvf()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_Et.IsAvailable() ) {
         jet_Et()->push_back( el.jet_Et() );
      } else {
         jet_Et()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_pt.IsAvailable() ) {
         jet_pt()->push_back( el.jet_pt() );
      } else {
         jet_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_m.IsAvailable() ) {
         jet_m()->push_back( el.jet_m() );
      } else {
         jet_m()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_eta.IsAvailable() ) {
         jet_eta()->push_back( el.jet_eta() );
      } else {
         jet_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_phi.IsAvailable() ) {
         jet_phi()->push_back( el.jet_phi() );
      } else {
         jet_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_WIDTH.IsAvailable() ) {
         jet_WIDTH()->push_back( el.jet_WIDTH() );
      } else {
         jet_WIDTH()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_n90.IsAvailable() ) {
         jet_n90()->push_back( el.jet_n90() );
      } else {
         jet_n90()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_n90constituents.IsAvailable() ) {
         jet_n90constituents()->push_back( el.jet_n90constituents() );
      } else {
         jet_n90constituents()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_BCH_CORR_CELL.IsAvailable() ) {
         jet_BCH_CORR_CELL()->push_back( el.jet_BCH_CORR_CELL() );
      } else {
         jet_BCH_CORR_CELL()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_BCH_CORR_JET.IsAvailable() ) {
         jet_BCH_CORR_JET()->push_back( el.jet_BCH_CORR_JET() );
      } else {
         jet_BCH_CORR_JET()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_BCH_CORR_JET_FORCELL.IsAvailable() ) {
         jet_BCH_CORR_JET_FORCELL()->push_back( el.jet_BCH_CORR_JET_FORCELL() );
      } else {
         jet_BCH_CORR_JET_FORCELL()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_ENG_BAD_CELLS.IsAvailable() ) {
         jet_ENG_BAD_CELLS()->push_back( el.jet_ENG_BAD_CELLS() );
      } else {
         jet_ENG_BAD_CELLS()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_N_BAD_CELLS.IsAvailable() ) {
         jet_N_BAD_CELLS()->push_back( el.jet_N_BAD_CELLS() );
      } else {
         jet_N_BAD_CELLS()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_N_BAD_CELLS_CORR.IsAvailable() ) {
         jet_N_BAD_CELLS_CORR()->push_back( el.jet_N_BAD_CELLS_CORR() );
      } else {
         jet_N_BAD_CELLS_CORR()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_BAD_CELLS_CORR_E.IsAvailable() ) {
         jet_BAD_CELLS_CORR_E()->push_back( el.jet_BAD_CELLS_CORR_E() );
      } else {
         jet_BAD_CELLS_CORR_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_Timing.IsAvailable() ) {
         jet_Timing()->push_back( el.jet_Timing() );
      } else {
         jet_Timing()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_LArQuality.IsAvailable() ) {
         jet_LArQuality()->push_back( el.jet_LArQuality() );
      } else {
         jet_LArQuality()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_nTrk.IsAvailable() ) {
         jet_nTrk()->push_back( el.jet_nTrk() );
      } else {
         jet_nTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_sumPtTrk.IsAvailable() ) {
         jet_sumPtTrk()->push_back( el.jet_sumPtTrk() );
      } else {
         jet_sumPtTrk()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_OriginIndex.IsAvailable() ) {
         jet_OriginIndex()->push_back( el.jet_OriginIndex() );
      } else {
         jet_OriginIndex()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_HECQuality.IsAvailable() ) {
         jet_HECQuality()->push_back( el.jet_HECQuality() );
      } else {
         jet_HECQuality()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_NegativeE.IsAvailable() ) {
         jet_NegativeE()->push_back( el.jet_NegativeE() );
      } else {
         jet_NegativeE()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_YFlip12.IsAvailable() ) {
         jet_YFlip12()->push_back( el.jet_YFlip12() );
      } else {
         jet_YFlip12()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_YFlip23.IsAvailable() ) {
         jet_YFlip23()->push_back( el.jet_YFlip23() );
      } else {
         jet_YFlip23()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_BCH_CORR_DOTX.IsAvailable() ) {
         jet_BCH_CORR_DOTX()->push_back( el.jet_BCH_CORR_DOTX() );
      } else {
         jet_BCH_CORR_DOTX()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_SamplingMax.IsAvailable() ) {
         jet_SamplingMax()->push_back( el.jet_SamplingMax() );
      } else {
         jet_SamplingMax()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.jet_fracSamplingMax.IsAvailable() ) {
         jet_fracSamplingMax()->push_back( el.jet_fracSamplingMax() );
      } else {
         jet_fracSamplingMax()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_hecf.IsAvailable() ) {
         jet_hecf()->push_back( el.jet_hecf() );
      } else {
         jet_hecf()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_tgap3f.IsAvailable() ) {
         jet_tgap3f()->push_back( el.jet_tgap3f() );
      } else {
         jet_tgap3f()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_isUgly.IsAvailable() ) {
         jet_isUgly()->push_back( el.jet_isUgly() );
      } else {
         jet_isUgly()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.jet_isBadLooseMinus.IsAvailable() ) {
         jet_isBadLooseMinus()->push_back( el.jet_isBadLooseMinus() );
      } else {
         jet_isBadLooseMinus()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.jet_isBadLoose.IsAvailable() ) {
         jet_isBadLoose()->push_back( el.jet_isBadLoose() );
      } else {
         jet_isBadLoose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.jet_isBadMedium.IsAvailable() ) {
         jet_isBadMedium()->push_back( el.jet_isBadMedium() );
      } else {
         jet_isBadMedium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.jet_isBadTight.IsAvailable() ) {
         jet_isBadTight()->push_back( el.jet_isBadTight() );
      } else {
         jet_isBadTight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.jet_emfrac.IsAvailable() ) {
         jet_emfrac()->push_back( el.jet_emfrac() );
      } else {
         jet_emfrac()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_GCWJES.IsAvailable() ) {
         jet_GCWJES()->push_back( el.jet_GCWJES() );
      } else {
         jet_GCWJES()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_EMJES.IsAvailable() ) {
         jet_EMJES()->push_back( el.jet_EMJES() );
      } else {
         jet_EMJES()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_emscale_E.IsAvailable() ) {
         jet_emscale_E()->push_back( el.jet_emscale_E() );
      } else {
         jet_emscale_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_emscale_pt.IsAvailable() ) {
         jet_emscale_pt()->push_back( el.jet_emscale_pt() );
      } else {
         jet_emscale_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_emscale_m.IsAvailable() ) {
         jet_emscale_m()->push_back( el.jet_emscale_m() );
      } else {
         jet_emscale_m()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_emscale_eta.IsAvailable() ) {
         jet_emscale_eta()->push_back( el.jet_emscale_eta() );
      } else {
         jet_emscale_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_emscale_phi.IsAvailable() ) {
         jet_emscale_phi()->push_back( el.jet_emscale_phi() );
      } else {
         jet_emscale_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_jvtx_x.IsAvailable() ) {
         jet_jvtx_x()->push_back( el.jet_jvtx_x() );
      } else {
         jet_jvtx_x()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_jvtx_y.IsAvailable() ) {
         jet_jvtx_y()->push_back( el.jet_jvtx_y() );
      } else {
         jet_jvtx_y()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_jvtx_z.IsAvailable() ) {
         jet_jvtx_z()->push_back( el.jet_jvtx_z() );
      } else {
         jet_jvtx_z()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_jvtxf.IsAvailable() ) {
         jet_jvtxf()->push_back( el.jet_jvtxf() );
      } else {
         jet_jvtxf()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_flavor_weight.IsAvailable() ) {
         jet_flavor_weight()->push_back( el.jet_flavor_weight() );
      } else {
         jet_flavor_weight()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.jet_flavor_weight_TrackCounting2D.IsAvailable() ) {
         jet_flavor_weight_TrackCounting2D()->push_back( el.jet_flavor_weight_TrackCounting2D() );
      } else {
         jet_flavor_weight_TrackCounting2D()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.jet_flavor_weight_JetProb.IsAvailable() ) {
         jet_flavor_weight_JetProb()->push_back( el.jet_flavor_weight_JetProb() );
      } else {
         jet_flavor_weight_JetProb()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.jet_flavor_weight_IP1D.IsAvailable() ) {
         jet_flavor_weight_IP1D()->push_back( el.jet_flavor_weight_IP1D() );
      } else {
         jet_flavor_weight_IP1D()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.jet_flavor_weight_IP2D.IsAvailable() ) {
         jet_flavor_weight_IP2D()->push_back( el.jet_flavor_weight_IP2D() );
      } else {
         jet_flavor_weight_IP2D()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.jet_flavor_weight_IP3D.IsAvailable() ) {
         jet_flavor_weight_IP3D()->push_back( el.jet_flavor_weight_IP3D() );
      } else {
         jet_flavor_weight_IP3D()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.jet_flavor_weight_SV0.IsAvailable() ) {
         jet_flavor_weight_SV0()->push_back( el.jet_flavor_weight_SV0() );
      } else {
         jet_flavor_weight_SV0()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.jet_flavor_weight_SV1.IsAvailable() ) {
         jet_flavor_weight_SV1()->push_back( el.jet_flavor_weight_SV1() );
      } else {
         jet_flavor_weight_SV1()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.jet_flavor_weight_SV2.IsAvailable() ) {
         jet_flavor_weight_SV2()->push_back( el.jet_flavor_weight_SV2() );
      } else {
         jet_flavor_weight_SV2()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.jet_flavor_weight_JetFitterTag.IsAvailable() ) {
         jet_flavor_weight_JetFitterTag()->push_back( el.jet_flavor_weight_JetFitterTag() );
      } else {
         jet_flavor_weight_JetFitterTag()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.jet_flavor_weight_JetFitterCOMB.IsAvailable() ) {
         jet_flavor_weight_JetFitterCOMB()->push_back( el.jet_flavor_weight_JetFitterCOMB() );
      } else {
         jet_flavor_weight_JetFitterCOMB()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.jet_flavor_weight_JetFitterTagNN.IsAvailable() ) {
         jet_flavor_weight_JetFitterTagNN()->push_back( el.jet_flavor_weight_JetFitterTagNN() );
      } else {
         jet_flavor_weight_JetFitterTagNN()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.jet_flavor_weight_JetFitterCOMBNN.IsAvailable() ) {
         jet_flavor_weight_JetFitterCOMBNN()->push_back( el.jet_flavor_weight_JetFitterCOMBNN() );
      } else {
         jet_flavor_weight_JetFitterCOMBNN()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.jet_flavor_weight_SoftMuonTag.IsAvailable() ) {
         jet_flavor_weight_SoftMuonTag()->push_back( el.jet_flavor_weight_SoftMuonTag() );
      } else {
         jet_flavor_weight_SoftMuonTag()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.jet_flavor_weight_SoftElectronTag.IsAvailable() ) {
         jet_flavor_weight_SoftElectronTag()->push_back( el.jet_flavor_weight_SoftElectronTag() );
      } else {
         jet_flavor_weight_SoftElectronTag()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.jet_flavor_weight_IP3DSV1.IsAvailable() ) {
         jet_flavor_weight_IP3DSV1()->push_back( el.jet_flavor_weight_IP3DSV1() );
      } else {
         jet_flavor_weight_IP3DSV1()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.jet_e_PreSamplerB.IsAvailable() ) {
         jet_e_PreSamplerB()->push_back( el.jet_e_PreSamplerB() );
      } else {
         jet_e_PreSamplerB()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_EMB1.IsAvailable() ) {
         jet_e_EMB1()->push_back( el.jet_e_EMB1() );
      } else {
         jet_e_EMB1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_EMB2.IsAvailable() ) {
         jet_e_EMB2()->push_back( el.jet_e_EMB2() );
      } else {
         jet_e_EMB2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_EMB3.IsAvailable() ) {
         jet_e_EMB3()->push_back( el.jet_e_EMB3() );
      } else {
         jet_e_EMB3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_PreSamplerE.IsAvailable() ) {
         jet_e_PreSamplerE()->push_back( el.jet_e_PreSamplerE() );
      } else {
         jet_e_PreSamplerE()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_EME1.IsAvailable() ) {
         jet_e_EME1()->push_back( el.jet_e_EME1() );
      } else {
         jet_e_EME1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_EME2.IsAvailable() ) {
         jet_e_EME2()->push_back( el.jet_e_EME2() );
      } else {
         jet_e_EME2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_EME3.IsAvailable() ) {
         jet_e_EME3()->push_back( el.jet_e_EME3() );
      } else {
         jet_e_EME3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_HEC0.IsAvailable() ) {
         jet_e_HEC0()->push_back( el.jet_e_HEC0() );
      } else {
         jet_e_HEC0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_HEC1.IsAvailable() ) {
         jet_e_HEC1()->push_back( el.jet_e_HEC1() );
      } else {
         jet_e_HEC1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_HEC2.IsAvailable() ) {
         jet_e_HEC2()->push_back( el.jet_e_HEC2() );
      } else {
         jet_e_HEC2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_HEC3.IsAvailable() ) {
         jet_e_HEC3()->push_back( el.jet_e_HEC3() );
      } else {
         jet_e_HEC3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_TileBar0.IsAvailable() ) {
         jet_e_TileBar0()->push_back( el.jet_e_TileBar0() );
      } else {
         jet_e_TileBar0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_TileBar1.IsAvailable() ) {
         jet_e_TileBar1()->push_back( el.jet_e_TileBar1() );
      } else {
         jet_e_TileBar1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_TileBar2.IsAvailable() ) {
         jet_e_TileBar2()->push_back( el.jet_e_TileBar2() );
      } else {
         jet_e_TileBar2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_TileGap1.IsAvailable() ) {
         jet_e_TileGap1()->push_back( el.jet_e_TileGap1() );
      } else {
         jet_e_TileGap1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_TileGap2.IsAvailable() ) {
         jet_e_TileGap2()->push_back( el.jet_e_TileGap2() );
      } else {
         jet_e_TileGap2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_TileGap3.IsAvailable() ) {
         jet_e_TileGap3()->push_back( el.jet_e_TileGap3() );
      } else {
         jet_e_TileGap3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_TileExt0.IsAvailable() ) {
         jet_e_TileExt0()->push_back( el.jet_e_TileExt0() );
      } else {
         jet_e_TileExt0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_TileExt1.IsAvailable() ) {
         jet_e_TileExt1()->push_back( el.jet_e_TileExt1() );
      } else {
         jet_e_TileExt1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_TileExt2.IsAvailable() ) {
         jet_e_TileExt2()->push_back( el.jet_e_TileExt2() );
      } else {
         jet_e_TileExt2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_FCAL0.IsAvailable() ) {
         jet_e_FCAL0()->push_back( el.jet_e_FCAL0() );
      } else {
         jet_e_FCAL0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_FCAL1.IsAvailable() ) {
         jet_e_FCAL1()->push_back( el.jet_e_FCAL1() );
      } else {
         jet_e_FCAL1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_e_FCAL2.IsAvailable() ) {
         jet_e_FCAL2()->push_back( el.jet_e_FCAL2() );
      } else {
         jet_e_FCAL2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jet_shapeBins.IsAvailable() ) {
         jet_shapeBins()->push_back( el.jet_shapeBins() );
      } else {
         jet_shapeBins()->push_back( vector<float>() );
      }
      if( el.track_atTJVA_n.IsAvailable() ) {
         track_atTJVA_n()->push_back( el.track_atTJVA_n() );
      } else {
         track_atTJVA_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.track_atTJVA_d0.IsAvailable() ) {
         track_atTJVA_d0()->push_back( el.track_atTJVA_d0() );
      } else {
         track_atTJVA_d0()->push_back( vector<float>() );
      }
      if( el.track_atTJVA_z0.IsAvailable() ) {
         track_atTJVA_z0()->push_back( el.track_atTJVA_z0() );
      } else {
         track_atTJVA_z0()->push_back( vector<float>() );
      }
      if( el.track_atTJVA_phi.IsAvailable() ) {
         track_atTJVA_phi()->push_back( el.track_atTJVA_phi() );
      } else {
         track_atTJVA_phi()->push_back( vector<float>() );
      }
      if( el.track_atTJVA_theta.IsAvailable() ) {
         track_atTJVA_theta()->push_back( el.track_atTJVA_theta() );
      } else {
         track_atTJVA_theta()->push_back( vector<float>() );
      }
      if( el.track_atTJVA_qoverp.IsAvailable() ) {
         track_atTJVA_qoverp()->push_back( el.track_atTJVA_qoverp() );
      } else {
         track_atTJVA_qoverp()->push_back( vector<float>() );
      }
      if( el.track_atTJVA_pt.IsAvailable() ) {
         track_atTJVA_pt()->push_back( el.track_atTJVA_pt() );
      } else {
         track_atTJVA_pt()->push_back( vector<float>() );
      }
      if( el.track_atTJVA_eta.IsAvailable() ) {
         track_atTJVA_eta()->push_back( el.track_atTJVA_eta() );
      } else {
         track_atTJVA_eta()->push_back( vector<float>() );
      }
      if( el.seedCalo_wideTrk_atTJVA_n.IsAvailable() ) {
         seedCalo_wideTrk_atTJVA_n()->push_back( el.seedCalo_wideTrk_atTJVA_n() );
      } else {
         seedCalo_wideTrk_atTJVA_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.seedCalo_wideTrk_atTJVA_d0.IsAvailable() ) {
         seedCalo_wideTrk_atTJVA_d0()->push_back( el.seedCalo_wideTrk_atTJVA_d0() );
      } else {
         seedCalo_wideTrk_atTJVA_d0()->push_back( vector<float>() );
      }
      if( el.seedCalo_wideTrk_atTJVA_z0.IsAvailable() ) {
         seedCalo_wideTrk_atTJVA_z0()->push_back( el.seedCalo_wideTrk_atTJVA_z0() );
      } else {
         seedCalo_wideTrk_atTJVA_z0()->push_back( vector<float>() );
      }
      if( el.seedCalo_wideTrk_atTJVA_phi.IsAvailable() ) {
         seedCalo_wideTrk_atTJVA_phi()->push_back( el.seedCalo_wideTrk_atTJVA_phi() );
      } else {
         seedCalo_wideTrk_atTJVA_phi()->push_back( vector<float>() );
      }
      if( el.seedCalo_wideTrk_atTJVA_theta.IsAvailable() ) {
         seedCalo_wideTrk_atTJVA_theta()->push_back( el.seedCalo_wideTrk_atTJVA_theta() );
      } else {
         seedCalo_wideTrk_atTJVA_theta()->push_back( vector<float>() );
      }
      if( el.seedCalo_wideTrk_atTJVA_qoverp.IsAvailable() ) {
         seedCalo_wideTrk_atTJVA_qoverp()->push_back( el.seedCalo_wideTrk_atTJVA_qoverp() );
      } else {
         seedCalo_wideTrk_atTJVA_qoverp()->push_back( vector<float>() );
      }
      if( el.seedCalo_wideTrk_atTJVA_pt.IsAvailable() ) {
         seedCalo_wideTrk_atTJVA_pt()->push_back( el.seedCalo_wideTrk_atTJVA_pt() );
      } else {
         seedCalo_wideTrk_atTJVA_pt()->push_back( vector<float>() );
      }
      if( el.seedCalo_wideTrk_atTJVA_eta.IsAvailable() ) {
         seedCalo_wideTrk_atTJVA_eta()->push_back( el.seedCalo_wideTrk_atTJVA_eta() );
      } else {
         seedCalo_wideTrk_atTJVA_eta()->push_back( vector<float>() );
      }
      if( el.otherTrk_atTJVA_n.IsAvailable() ) {
         otherTrk_atTJVA_n()->push_back( el.otherTrk_atTJVA_n() );
      } else {
         otherTrk_atTJVA_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.track_n.IsAvailable() ) {
         track_n()->push_back( el.track_n() );
      } else {
         track_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.track_d0.IsAvailable() ) {
         track_d0()->push_back( el.track_d0() );
      } else {
         track_d0()->push_back( vector<float>() );
      }
      if( el.track_z0.IsAvailable() ) {
         track_z0()->push_back( el.track_z0() );
      } else {
         track_z0()->push_back( vector<float>() );
      }
      if( el.track_phi.IsAvailable() ) {
         track_phi()->push_back( el.track_phi() );
      } else {
         track_phi()->push_back( vector<float>() );
      }
      if( el.track_theta.IsAvailable() ) {
         track_theta()->push_back( el.track_theta() );
      } else {
         track_theta()->push_back( vector<float>() );
      }
      if( el.track_qoverp.IsAvailable() ) {
         track_qoverp()->push_back( el.track_qoverp() );
      } else {
         track_qoverp()->push_back( vector<float>() );
      }
      if( el.track_pt.IsAvailable() ) {
         track_pt()->push_back( el.track_pt() );
      } else {
         track_pt()->push_back( vector<float>() );
      }
      if( el.track_eta.IsAvailable() ) {
         track_eta()->push_back( el.track_eta() );
      } else {
         track_eta()->push_back( vector<float>() );
      }
      if( el.track_atPV_d0.IsAvailable() ) {
         track_atPV_d0()->push_back( el.track_atPV_d0() );
      } else {
         track_atPV_d0()->push_back( vector<float>() );
      }
      if( el.track_atPV_z0.IsAvailable() ) {
         track_atPV_z0()->push_back( el.track_atPV_z0() );
      } else {
         track_atPV_z0()->push_back( vector<float>() );
      }
      if( el.track_atPV_phi.IsAvailable() ) {
         track_atPV_phi()->push_back( el.track_atPV_phi() );
      } else {
         track_atPV_phi()->push_back( vector<float>() );
      }
      if( el.track_atPV_theta.IsAvailable() ) {
         track_atPV_theta()->push_back( el.track_atPV_theta() );
      } else {
         track_atPV_theta()->push_back( vector<float>() );
      }
      if( el.track_atPV_qoverp.IsAvailable() ) {
         track_atPV_qoverp()->push_back( el.track_atPV_qoverp() );
      } else {
         track_atPV_qoverp()->push_back( vector<float>() );
      }
      if( el.track_atPV_pt.IsAvailable() ) {
         track_atPV_pt()->push_back( el.track_atPV_pt() );
      } else {
         track_atPV_pt()->push_back( vector<float>() );
      }
      if( el.track_atPV_eta.IsAvailable() ) {
         track_atPV_eta()->push_back( el.track_atPV_eta() );
      } else {
         track_atPV_eta()->push_back( vector<float>() );
      }
      if( el.track_nBLHits.IsAvailable() ) {
         track_nBLHits()->push_back( el.track_nBLHits() );
      } else {
         track_nBLHits()->push_back( vector<int>() );
      }
      if( el.track_nPixHits.IsAvailable() ) {
         track_nPixHits()->push_back( el.track_nPixHits() );
      } else {
         track_nPixHits()->push_back( vector<int>() );
      }
      if( el.track_nSCTHits.IsAvailable() ) {
         track_nSCTHits()->push_back( el.track_nSCTHits() );
      } else {
         track_nSCTHits()->push_back( vector<int>() );
      }
      if( el.track_nTRTHits.IsAvailable() ) {
         track_nTRTHits()->push_back( el.track_nTRTHits() );
      } else {
         track_nTRTHits()->push_back( vector<int>() );
      }
      if( el.track_nTRTHighTHits.IsAvailable() ) {
         track_nTRTHighTHits()->push_back( el.track_nTRTHighTHits() );
      } else {
         track_nTRTHighTHits()->push_back( vector<int>() );
      }
      if( el.track_nTRTXenonHits.IsAvailable() ) {
         track_nTRTXenonHits()->push_back( el.track_nTRTXenonHits() );
      } else {
         track_nTRTXenonHits()->push_back( vector<int>() );
      }
      if( el.track_nPixHoles.IsAvailable() ) {
         track_nPixHoles()->push_back( el.track_nPixHoles() );
      } else {
         track_nPixHoles()->push_back( vector<int>() );
      }
      if( el.track_nSCTHoles.IsAvailable() ) {
         track_nSCTHoles()->push_back( el.track_nSCTHoles() );
      } else {
         track_nSCTHoles()->push_back( vector<int>() );
      }
      if( el.track_nTRTHoles.IsAvailable() ) {
         track_nTRTHoles()->push_back( el.track_nTRTHoles() );
      } else {
         track_nTRTHoles()->push_back( vector<int>() );
      }
      if( el.track_nPixelDeadSensors.IsAvailable() ) {
         track_nPixelDeadSensors()->push_back( el.track_nPixelDeadSensors() );
      } else {
         track_nPixelDeadSensors()->push_back( vector<int>() );
      }
      if( el.track_nSCTDeadSensors.IsAvailable() ) {
         track_nSCTDeadSensors()->push_back( el.track_nSCTDeadSensors() );
      } else {
         track_nSCTDeadSensors()->push_back( vector<int>() );
      }
      if( el.track_nBLSharedHits.IsAvailable() ) {
         track_nBLSharedHits()->push_back( el.track_nBLSharedHits() );
      } else {
         track_nBLSharedHits()->push_back( vector<int>() );
      }
      if( el.track_nPixSharedHits.IsAvailable() ) {
         track_nPixSharedHits()->push_back( el.track_nPixSharedHits() );
      } else {
         track_nPixSharedHits()->push_back( vector<int>() );
      }
      if( el.track_nSCTSharedHits.IsAvailable() ) {
         track_nSCTSharedHits()->push_back( el.track_nSCTSharedHits() );
      } else {
         track_nSCTSharedHits()->push_back( vector<int>() );
      }
      if( el.track_nBLayerSplitHits.IsAvailable() ) {
         track_nBLayerSplitHits()->push_back( el.track_nBLayerSplitHits() );
      } else {
         track_nBLayerSplitHits()->push_back( vector<int>() );
      }
      if( el.track_nPixSplitHits.IsAvailable() ) {
         track_nPixSplitHits()->push_back( el.track_nPixSplitHits() );
      } else {
         track_nPixSplitHits()->push_back( vector<int>() );
      }
      if( el.track_nBLayerOutliers.IsAvailable() ) {
         track_nBLayerOutliers()->push_back( el.track_nBLayerOutliers() );
      } else {
         track_nBLayerOutliers()->push_back( vector<int>() );
      }
      if( el.track_nPixelOutliers.IsAvailable() ) {
         track_nPixelOutliers()->push_back( el.track_nPixelOutliers() );
      } else {
         track_nPixelOutliers()->push_back( vector<int>() );
      }
      if( el.track_nSCTOutliers.IsAvailable() ) {
         track_nSCTOutliers()->push_back( el.track_nSCTOutliers() );
      } else {
         track_nSCTOutliers()->push_back( vector<int>() );
      }
      if( el.track_nTRTOutliers.IsAvailable() ) {
         track_nTRTOutliers()->push_back( el.track_nTRTOutliers() );
      } else {
         track_nTRTOutliers()->push_back( vector<int>() );
      }
      if( el.track_nTRTHighTOutliers.IsAvailable() ) {
         track_nTRTHighTOutliers()->push_back( el.track_nTRTHighTOutliers() );
      } else {
         track_nTRTHighTOutliers()->push_back( vector<int>() );
      }
      if( el.track_nContribPixelLayers.IsAvailable() ) {
         track_nContribPixelLayers()->push_back( el.track_nContribPixelLayers() );
      } else {
         track_nContribPixelLayers()->push_back( vector<int>() );
      }
      if( el.track_nGangedPixels.IsAvailable() ) {
         track_nGangedPixels()->push_back( el.track_nGangedPixels() );
      } else {
         track_nGangedPixels()->push_back( vector<int>() );
      }
      if( el.track_nGangedFlaggedFakes.IsAvailable() ) {
         track_nGangedFlaggedFakes()->push_back( el.track_nGangedFlaggedFakes() );
      } else {
         track_nGangedFlaggedFakes()->push_back( vector<int>() );
      }
      if( el.track_nPixelSpoiltHits.IsAvailable() ) {
         track_nPixelSpoiltHits()->push_back( el.track_nPixelSpoiltHits() );
      } else {
         track_nPixelSpoiltHits()->push_back( vector<int>() );
      }
      if( el.track_nSCTDoubleHoles.IsAvailable() ) {
         track_nSCTDoubleHoles()->push_back( el.track_nSCTDoubleHoles() );
      } else {
         track_nSCTDoubleHoles()->push_back( vector<int>() );
      }
      if( el.track_nSCTSpoiltHits.IsAvailable() ) {
         track_nSCTSpoiltHits()->push_back( el.track_nSCTSpoiltHits() );
      } else {
         track_nSCTSpoiltHits()->push_back( vector<int>() );
      }
      if( el.track_expectBLayerHit.IsAvailable() ) {
         track_expectBLayerHit()->push_back( el.track_expectBLayerHit() );
      } else {
         track_expectBLayerHit()->push_back( vector<int>() );
      }
      if( el.track_nHits.IsAvailable() ) {
         track_nHits()->push_back( el.track_nHits() );
      } else {
         track_nHits()->push_back( vector<int>() );
      }
      if( el.track_TRTHighTHitsRatio.IsAvailable() ) {
         track_TRTHighTHitsRatio()->push_back( el.track_TRTHighTHitsRatio() );
      } else {
         track_TRTHighTHitsRatio()->push_back( vector<float>() );
      }
      if( el.track_TRTHighTOutliersRatio.IsAvailable() ) {
         track_TRTHighTOutliersRatio()->push_back( el.track_TRTHighTOutliersRatio() );
      } else {
         track_TRTHighTOutliersRatio()->push_back( vector<float>() );
      }
      if( el.seedCalo_track_n.IsAvailable() ) {
         seedCalo_track_n()->push_back( el.seedCalo_track_n() );
      } else {
         seedCalo_track_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.seedCalo_wideTrk_n.IsAvailable() ) {
         seedCalo_wideTrk_n()->push_back( el.seedCalo_wideTrk_n() );
      } else {
         seedCalo_wideTrk_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.seedCalo_wideTrk_nBLHits.IsAvailable() ) {
         seedCalo_wideTrk_nBLHits()->push_back( el.seedCalo_wideTrk_nBLHits() );
      } else {
         seedCalo_wideTrk_nBLHits()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nPixHits.IsAvailable() ) {
         seedCalo_wideTrk_nPixHits()->push_back( el.seedCalo_wideTrk_nPixHits() );
      } else {
         seedCalo_wideTrk_nPixHits()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nSCTHits.IsAvailable() ) {
         seedCalo_wideTrk_nSCTHits()->push_back( el.seedCalo_wideTrk_nSCTHits() );
      } else {
         seedCalo_wideTrk_nSCTHits()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nTRTHits.IsAvailable() ) {
         seedCalo_wideTrk_nTRTHits()->push_back( el.seedCalo_wideTrk_nTRTHits() );
      } else {
         seedCalo_wideTrk_nTRTHits()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nTRTHighTHits.IsAvailable() ) {
         seedCalo_wideTrk_nTRTHighTHits()->push_back( el.seedCalo_wideTrk_nTRTHighTHits() );
      } else {
         seedCalo_wideTrk_nTRTHighTHits()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nTRTXenonHits.IsAvailable() ) {
         seedCalo_wideTrk_nTRTXenonHits()->push_back( el.seedCalo_wideTrk_nTRTXenonHits() );
      } else {
         seedCalo_wideTrk_nTRTXenonHits()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nPixHoles.IsAvailable() ) {
         seedCalo_wideTrk_nPixHoles()->push_back( el.seedCalo_wideTrk_nPixHoles() );
      } else {
         seedCalo_wideTrk_nPixHoles()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nSCTHoles.IsAvailable() ) {
         seedCalo_wideTrk_nSCTHoles()->push_back( el.seedCalo_wideTrk_nSCTHoles() );
      } else {
         seedCalo_wideTrk_nSCTHoles()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nTRTHoles.IsAvailable() ) {
         seedCalo_wideTrk_nTRTHoles()->push_back( el.seedCalo_wideTrk_nTRTHoles() );
      } else {
         seedCalo_wideTrk_nTRTHoles()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nPixelDeadSensors.IsAvailable() ) {
         seedCalo_wideTrk_nPixelDeadSensors()->push_back( el.seedCalo_wideTrk_nPixelDeadSensors() );
      } else {
         seedCalo_wideTrk_nPixelDeadSensors()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nSCTDeadSensors.IsAvailable() ) {
         seedCalo_wideTrk_nSCTDeadSensors()->push_back( el.seedCalo_wideTrk_nSCTDeadSensors() );
      } else {
         seedCalo_wideTrk_nSCTDeadSensors()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nBLSharedHits.IsAvailable() ) {
         seedCalo_wideTrk_nBLSharedHits()->push_back( el.seedCalo_wideTrk_nBLSharedHits() );
      } else {
         seedCalo_wideTrk_nBLSharedHits()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nPixSharedHits.IsAvailable() ) {
         seedCalo_wideTrk_nPixSharedHits()->push_back( el.seedCalo_wideTrk_nPixSharedHits() );
      } else {
         seedCalo_wideTrk_nPixSharedHits()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nSCTSharedHits.IsAvailable() ) {
         seedCalo_wideTrk_nSCTSharedHits()->push_back( el.seedCalo_wideTrk_nSCTSharedHits() );
      } else {
         seedCalo_wideTrk_nSCTSharedHits()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nBLayerSplitHits.IsAvailable() ) {
         seedCalo_wideTrk_nBLayerSplitHits()->push_back( el.seedCalo_wideTrk_nBLayerSplitHits() );
      } else {
         seedCalo_wideTrk_nBLayerSplitHits()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nPixSplitHits.IsAvailable() ) {
         seedCalo_wideTrk_nPixSplitHits()->push_back( el.seedCalo_wideTrk_nPixSplitHits() );
      } else {
         seedCalo_wideTrk_nPixSplitHits()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nBLayerOutliers.IsAvailable() ) {
         seedCalo_wideTrk_nBLayerOutliers()->push_back( el.seedCalo_wideTrk_nBLayerOutliers() );
      } else {
         seedCalo_wideTrk_nBLayerOutliers()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nPixelOutliers.IsAvailable() ) {
         seedCalo_wideTrk_nPixelOutliers()->push_back( el.seedCalo_wideTrk_nPixelOutliers() );
      } else {
         seedCalo_wideTrk_nPixelOutliers()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nSCTOutliers.IsAvailable() ) {
         seedCalo_wideTrk_nSCTOutliers()->push_back( el.seedCalo_wideTrk_nSCTOutliers() );
      } else {
         seedCalo_wideTrk_nSCTOutliers()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nTRTOutliers.IsAvailable() ) {
         seedCalo_wideTrk_nTRTOutliers()->push_back( el.seedCalo_wideTrk_nTRTOutliers() );
      } else {
         seedCalo_wideTrk_nTRTOutliers()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nTRTHighTOutliers.IsAvailable() ) {
         seedCalo_wideTrk_nTRTHighTOutliers()->push_back( el.seedCalo_wideTrk_nTRTHighTOutliers() );
      } else {
         seedCalo_wideTrk_nTRTHighTOutliers()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nContribPixelLayers.IsAvailable() ) {
         seedCalo_wideTrk_nContribPixelLayers()->push_back( el.seedCalo_wideTrk_nContribPixelLayers() );
      } else {
         seedCalo_wideTrk_nContribPixelLayers()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nGangedPixels.IsAvailable() ) {
         seedCalo_wideTrk_nGangedPixels()->push_back( el.seedCalo_wideTrk_nGangedPixels() );
      } else {
         seedCalo_wideTrk_nGangedPixels()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nGangedFlaggedFakes.IsAvailable() ) {
         seedCalo_wideTrk_nGangedFlaggedFakes()->push_back( el.seedCalo_wideTrk_nGangedFlaggedFakes() );
      } else {
         seedCalo_wideTrk_nGangedFlaggedFakes()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nPixelSpoiltHits.IsAvailable() ) {
         seedCalo_wideTrk_nPixelSpoiltHits()->push_back( el.seedCalo_wideTrk_nPixelSpoiltHits() );
      } else {
         seedCalo_wideTrk_nPixelSpoiltHits()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nSCTDoubleHoles.IsAvailable() ) {
         seedCalo_wideTrk_nSCTDoubleHoles()->push_back( el.seedCalo_wideTrk_nSCTDoubleHoles() );
      } else {
         seedCalo_wideTrk_nSCTDoubleHoles()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nSCTSpoiltHits.IsAvailable() ) {
         seedCalo_wideTrk_nSCTSpoiltHits()->push_back( el.seedCalo_wideTrk_nSCTSpoiltHits() );
      } else {
         seedCalo_wideTrk_nSCTSpoiltHits()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_expectBLayerHit.IsAvailable() ) {
         seedCalo_wideTrk_expectBLayerHit()->push_back( el.seedCalo_wideTrk_expectBLayerHit() );
      } else {
         seedCalo_wideTrk_expectBLayerHit()->push_back( vector<int>() );
      }
      if( el.seedCalo_wideTrk_nHits.IsAvailable() ) {
         seedCalo_wideTrk_nHits()->push_back( el.seedCalo_wideTrk_nHits() );
      } else {
         seedCalo_wideTrk_nHits()->push_back( vector<int>() );
      }
      if( el.otherTrk_n.IsAvailable() ) {
         otherTrk_n()->push_back( el.otherTrk_n() );
      } else {
         otherTrk_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.EF_dr.IsAvailable() ) {
         EF_dr()->push_back( el.EF_dr() );
      } else {
         EF_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_E.IsAvailable() ) {
         EF_E()->push_back( el.EF_E() );
      } else {
         EF_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_Et.IsAvailable() ) {
         EF_Et()->push_back( el.EF_Et() );
      } else {
         EF_Et()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_pt.IsAvailable() ) {
         EF_pt()->push_back( el.EF_pt() );
      } else {
         EF_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_eta.IsAvailable() ) {
         EF_eta()->push_back( el.EF_eta() );
      } else {
         EF_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_phi.IsAvailable() ) {
         EF_phi()->push_back( el.EF_phi() );
      } else {
         EF_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_matched.IsAvailable() ) {
         EF_matched()->push_back( el.EF_matched() );
      } else {
         EF_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.L2_dr.IsAvailable() ) {
         L2_dr()->push_back( el.L2_dr() );
      } else {
         L2_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2_E.IsAvailable() ) {
         L2_E()->push_back( el.L2_E() );
      } else {
         L2_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2_Et.IsAvailable() ) {
         L2_Et()->push_back( el.L2_Et() );
      } else {
         L2_Et()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2_pt.IsAvailable() ) {
         L2_pt()->push_back( el.L2_pt() );
      } else {
         L2_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2_eta.IsAvailable() ) {
         L2_eta()->push_back( el.L2_eta() );
      } else {
         L2_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2_phi.IsAvailable() ) {
         L2_phi()->push_back( el.L2_phi() );
      } else {
         L2_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L2_matched.IsAvailable() ) {
         L2_matched()->push_back( el.L2_matched() );
      } else {
         L2_matched()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.L1_dr.IsAvailable() ) {
         L1_dr()->push_back( el.L1_dr() );
      } else {
         L1_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L1_Et.IsAvailable() ) {
         L1_Et()->push_back( el.L1_Et() );
      } else {
         L1_Et()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L1_pt.IsAvailable() ) {
         L1_pt()->push_back( el.L1_pt() );
      } else {
         L1_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L1_eta.IsAvailable() ) {
         L1_eta()->push_back( el.L1_eta() );
      } else {
         L1_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L1_phi.IsAvailable() ) {
         L1_phi()->push_back( el.L1_phi() );
      } else {
         L1_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.L1_matched.IsAvailable() ) {
         L1_matched()->push_back( el.L1_matched() );
      } else {
         L1_matched()->push_back( std::numeric_limits< int >::min() );
      }
if (!is_data) {
      if( el.trueTauAssocSmall_dr.IsAvailable() ) {
         trueTauAssocSmall_dr()->push_back( el.trueTauAssocSmall_dr() );
      } else {
         trueTauAssocSmall_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trueTauAssocSmall_index.IsAvailable() ) {
         trueTauAssocSmall_index()->push_back( el.trueTauAssocSmall_index() );
      } else {
         trueTauAssocSmall_index()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trueTauAssocSmall_matched.IsAvailable() ) {
         trueTauAssocSmall_matched()->push_back( el.trueTauAssocSmall_matched() );
      } else {
         trueTauAssocSmall_matched()->push_back( std::numeric_limits< int >::min() );
      }
} // end !is_data
      if( el.MET_Egamma10LooseTau_wpx.IsAvailable() ) {
         MET_Egamma10LooseTau_wpx()->push_back( el.MET_Egamma10LooseTau_wpx() );
      } else {
         MET_Egamma10LooseTau_wpx()->push_back( vector<float>() );
      }
      if( el.MET_Egamma10LooseTau_wpy.IsAvailable() ) {
         MET_Egamma10LooseTau_wpy()->push_back( el.MET_Egamma10LooseTau_wpy() );
      } else {
         MET_Egamma10LooseTau_wpy()->push_back( vector<float>() );
      }
      if( el.MET_Egamma10LooseTau_wet.IsAvailable() ) {
         MET_Egamma10LooseTau_wet()->push_back( el.MET_Egamma10LooseTau_wet() );
      } else {
         MET_Egamma10LooseTau_wet()->push_back( vector<float>() );
      }
      if( el.MET_Egamma10LooseTau_statusWord.IsAvailable() ) {
         MET_Egamma10LooseTau_statusWord()->push_back( el.MET_Egamma10LooseTau_statusWord() );
      } else {
         MET_Egamma10LooseTau_statusWord()->push_back( vector<unsigned int>() );
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
   TauD3PDObjectElement& TauD3PDObject::operator[]( size_t index ) {

      while( fProxies.size() <= index ) {
         fProxies.push_back( TauD3PDObjectElement( fProxies.size(), *this , is_data ) );
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
   const TauD3PDObjectElement& TauD3PDObject::operator[]( size_t index ) const {

      while( fProxies.size() <= index ) {
         fProxies.push_back( TauD3PDObjectElement( fProxies.size(), *this , is_data ) );
      }
      return fProxies[ index ];
   }

   /**
    * A convenience operator for adding an 'element' to this collection.
    *
    * @see Add
    * @param el The 'element' that should be added to the collection
    */
   TauD3PDObject& TauD3PDObject::operator+=( const TauD3PDObjectElement& el ) {

      return this->Add( el );
   }

} // namespace D3PDReader
