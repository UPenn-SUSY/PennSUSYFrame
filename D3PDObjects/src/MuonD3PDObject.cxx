// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <limits>

#include <TPRegexp.h>

#include "../include/MuonD3PDObject.h"

ClassImp( D3PDReader::MuonD3PDObjectElement )
ClassImp( D3PDReader::MuonD3PDObject )

namespace D3PDReader {

   /**
    * This constructor can be used to create new proxy objects from scratch.
    * Since the constructor of such an object is quite complicated and
    * error prone, it is only visible to the parent class MuonD3PDObject.
    */
   MuonD3PDObjectElement::MuonD3PDObjectElement( size_t index, const MuonD3PDObject& parent , bool is_data )
      : E( parent.E, index, this ),
        pt( parent.pt, index, this ),
        m( parent.m, index, this ),
        eta( parent.eta, index, this ),
        phi( parent.phi, index, this ),
        px( parent.px, index, this ),
        py( parent.py, index, this ),
        pz( parent.pz, index, this ),
        charge( parent.charge, index, this ),
        allauthor( parent.allauthor, index, this ),
        author( parent.author, index, this ),
        matchchi2( parent.matchchi2, index, this ),
        matchndof( parent.matchndof, index, this ),
        etcone20( parent.etcone20, index, this ),
        etcone30( parent.etcone30, index, this ),
        etcone40( parent.etcone40, index, this ),
        nucone20( parent.nucone20, index, this ),
        nucone30( parent.nucone30, index, this ),
        nucone40( parent.nucone40, index, this ),
        ptcone20( parent.ptcone20, index, this ),
        ptcone30( parent.ptcone30, index, this ),
        ptcone40( parent.ptcone40, index, this ),
// -- slimmed --         etconeNoEm10( parent.etconeNoEm10, index, this ),
// -- slimmed --         etconeNoEm20( parent.etconeNoEm20, index, this ),
// -- slimmed --         etconeNoEm30( parent.etconeNoEm30, index, this ),
// -- slimmed --         etconeNoEm40( parent.etconeNoEm40, index, this ),
// -- slimmed --         scatteringCurvatureSignificance( parent.scatteringCurvatureSignificance, index, this ),
// -- slimmed --         scatteringNeighbourSignificance( parent.scatteringNeighbourSignificance, index, this ),
// -- slimmed --         momentumBalanceSignificance( parent.momentumBalanceSignificance, index, this ),
        energyLossPar( parent.energyLossPar, index, this ),
        energyLossErr( parent.energyLossErr, index, this ),
        etCore( parent.etCore, index, this ),
        energyLossType( parent.energyLossType, index, this ),
        caloMuonIdTag( parent.caloMuonIdTag, index, this ),
        caloLRLikelihood( parent.caloLRLikelihood, index, this ),
        bestMatch( parent.bestMatch, index, this ),
        isStandAloneMuon( parent.isStandAloneMuon, index, this ),
        isCombinedMuon( parent.isCombinedMuon, index, this ),
        isLowPtReconstructedMuon( parent.isLowPtReconstructedMuon, index, this ),
        isSegmentTaggedMuon( parent.isSegmentTaggedMuon, index, this ),
        isCaloMuonId( parent.isCaloMuonId, index, this ),
// -- slimmed --         alsoFoundByLowPt( parent.alsoFoundByLowPt, index, this ),
// -- slimmed --         alsoFoundByCaloMuonId( parent.alsoFoundByCaloMuonId, index, this ),
// -- slimmed --         isSiliconAssociatedForwardMuon( parent.isSiliconAssociatedForwardMuon, index, this ),
        loose( parent.loose, index, this ),
        medium( parent.medium, index, this ),
        tight( parent.tight, index, this ),
        d0_exPV( parent.d0_exPV, index, this ),
        z0_exPV( parent.z0_exPV, index, this ),
        phi_exPV( parent.phi_exPV, index, this ),
        theta_exPV( parent.theta_exPV, index, this ),
        qoverp_exPV( parent.qoverp_exPV, index, this ),
        cb_d0_exPV( parent.cb_d0_exPV, index, this ),
        cb_z0_exPV( parent.cb_z0_exPV, index, this ),
        cb_phi_exPV( parent.cb_phi_exPV, index, this ),
        cb_theta_exPV( parent.cb_theta_exPV, index, this ),
        cb_qoverp_exPV( parent.cb_qoverp_exPV, index, this ),
        id_d0_exPV( parent.id_d0_exPV, index, this ),
        id_z0_exPV( parent.id_z0_exPV, index, this ),
        id_phi_exPV( parent.id_phi_exPV, index, this ),
        id_theta_exPV( parent.id_theta_exPV, index, this ),
        id_qoverp_exPV( parent.id_qoverp_exPV, index, this ),
        me_d0_exPV( parent.me_d0_exPV, index, this ),
        me_z0_exPV( parent.me_z0_exPV, index, this ),
        me_phi_exPV( parent.me_phi_exPV, index, this ),
        me_theta_exPV( parent.me_theta_exPV, index, this ),
        me_qoverp_exPV( parent.me_qoverp_exPV, index, this ),
        ie_d0_exPV( parent.ie_d0_exPV, index, this ),
        ie_z0_exPV( parent.ie_z0_exPV, index, this ),
        ie_phi_exPV( parent.ie_phi_exPV, index, this ),
        ie_theta_exPV( parent.ie_theta_exPV, index, this ),
        ie_qoverp_exPV( parent.ie_qoverp_exPV, index, this ),
        cov_d0_exPV( parent.cov_d0_exPV, index, this ),
        cov_z0_exPV( parent.cov_z0_exPV, index, this ),
        cov_phi_exPV( parent.cov_phi_exPV, index, this ),
        cov_theta_exPV( parent.cov_theta_exPV, index, this ),
        cov_qoverp_exPV( parent.cov_qoverp_exPV, index, this ),
        cov_d0_z0_exPV( parent.cov_d0_z0_exPV, index, this ),
        cov_d0_phi_exPV( parent.cov_d0_phi_exPV, index, this ),
        cov_d0_theta_exPV( parent.cov_d0_theta_exPV, index, this ),
        cov_d0_qoverp_exPV( parent.cov_d0_qoverp_exPV, index, this ),
        cov_z0_phi_exPV( parent.cov_z0_phi_exPV, index, this ),
        cov_z0_theta_exPV( parent.cov_z0_theta_exPV, index, this ),
        cov_z0_qoverp_exPV( parent.cov_z0_qoverp_exPV, index, this ),
        cov_phi_theta_exPV( parent.cov_phi_theta_exPV, index, this ),
        cov_phi_qoverp_exPV( parent.cov_phi_qoverp_exPV, index, this ),
        cov_theta_qoverp_exPV( parent.cov_theta_qoverp_exPV, index, this ),
        id_cov_d0_exPV( parent.id_cov_d0_exPV, index, this ),
        id_cov_z0_exPV( parent.id_cov_z0_exPV, index, this ),
        id_cov_phi_exPV( parent.id_cov_phi_exPV, index, this ),
        id_cov_theta_exPV( parent.id_cov_theta_exPV, index, this ),
        id_cov_qoverp_exPV( parent.id_cov_qoverp_exPV, index, this ),
        id_cov_d0_z0_exPV( parent.id_cov_d0_z0_exPV, index, this ),
        id_cov_d0_phi_exPV( parent.id_cov_d0_phi_exPV, index, this ),
        id_cov_d0_theta_exPV( parent.id_cov_d0_theta_exPV, index, this ),
        id_cov_d0_qoverp_exPV( parent.id_cov_d0_qoverp_exPV, index, this ),
        id_cov_z0_phi_exPV( parent.id_cov_z0_phi_exPV, index, this ),
        id_cov_z0_theta_exPV( parent.id_cov_z0_theta_exPV, index, this ),
        id_cov_z0_qoverp_exPV( parent.id_cov_z0_qoverp_exPV, index, this ),
        id_cov_phi_theta_exPV( parent.id_cov_phi_theta_exPV, index, this ),
        id_cov_phi_qoverp_exPV( parent.id_cov_phi_qoverp_exPV, index, this ),
        id_cov_theta_qoverp_exPV( parent.id_cov_theta_qoverp_exPV, index, this ),
        me_cov_d0_exPV( parent.me_cov_d0_exPV, index, this ),
        me_cov_z0_exPV( parent.me_cov_z0_exPV, index, this ),
        me_cov_phi_exPV( parent.me_cov_phi_exPV, index, this ),
        me_cov_theta_exPV( parent.me_cov_theta_exPV, index, this ),
        me_cov_qoverp_exPV( parent.me_cov_qoverp_exPV, index, this ),
        ms_d0( parent.ms_d0, index, this ),
        ms_z0( parent.ms_z0, index, this ),
        ms_phi( parent.ms_phi, index, this ),
        ms_theta( parent.ms_theta, index, this ),
        ms_qoverp( parent.ms_qoverp, index, this ),
        id_d0( parent.id_d0, index, this ),
        id_z0( parent.id_z0, index, this ),
        id_phi( parent.id_phi, index, this ),
        id_theta( parent.id_theta, index, this ),
        id_qoverp( parent.id_qoverp, index, this ),
        me_d0( parent.me_d0, index, this ),
        me_z0( parent.me_z0, index, this ),
        me_phi( parent.me_phi, index, this ),
        me_theta( parent.me_theta, index, this ),
        me_qoverp( parent.me_qoverp, index, this ),
        ie_d0( parent.ie_d0, index, this ),
        ie_z0( parent.ie_z0, index, this ),
        ie_phi( parent.ie_phi, index, this ),
        ie_theta( parent.ie_theta, index, this ),
        ie_qoverp( parent.ie_qoverp, index, this ),
        nOutliersOnTrack( parent.nOutliersOnTrack, index, this ),
        nBLHits( parent.nBLHits, index, this ),
        nPixHits( parent.nPixHits, index, this ),
        nSCTHits( parent.nSCTHits, index, this ),
        nTRTHits( parent.nTRTHits, index, this ),
        nTRTHighTHits( parent.nTRTHighTHits, index, this ),
        nBLSharedHits( parent.nBLSharedHits, index, this ),
        nPixSharedHits( parent.nPixSharedHits, index, this ),
        nPixHoles( parent.nPixHoles, index, this ),
        nSCTSharedHits( parent.nSCTSharedHits, index, this ),
        nSCTHoles( parent.nSCTHoles, index, this ),
        nTRTOutliers( parent.nTRTOutliers, index, this ),
        nTRTHighTOutliers( parent.nTRTHighTOutliers, index, this ),
        nGangedPixels( parent.nGangedPixels, index, this ),
        nPixelDeadSensors( parent.nPixelDeadSensors, index, this ),
        nSCTDeadSensors( parent.nSCTDeadSensors, index, this ),
        nTRTDeadStraws( parent.nTRTDeadStraws, index, this ),
        expectBLayerHit( parent.expectBLayerHit, index, this ),
        nMDTHits( parent.nMDTHits, index, this ),
// -- slimmed --         nMDTHoles( parent.nMDTHoles, index, this ),
        nCSCEtaHits( parent.nCSCEtaHits, index, this ),
// -- slimmed --         nCSCEtaHoles( parent.nCSCEtaHoles, index, this ),
        nCSCUnspoiledEtaHits( parent.nCSCUnspoiledEtaHits, index, this ),
        nCSCPhiHits( parent.nCSCPhiHits, index, this ),
// -- slimmed --         nCSCPhiHoles( parent.nCSCPhiHoles, index, this ),
        nRPCEtaHits( parent.nRPCEtaHits, index, this ),
// -- slimmed --         nRPCEtaHoles( parent.nRPCEtaHoles, index, this ),
        nRPCPhiHits( parent.nRPCPhiHits, index, this ),
// -- slimmed --         nRPCPhiHoles( parent.nRPCPhiHoles, index, this ),
        nTGCEtaHits( parent.nTGCEtaHits, index, this ),
// -- slimmed --         nTGCEtaHoles( parent.nTGCEtaHoles, index, this ),
        nTGCPhiHits( parent.nTGCPhiHits, index, this ),
// -- slimmed --         nTGCPhiHoles( parent.nTGCPhiHoles, index, this ),
        nprecisionLayers( parent.nprecisionLayers, index, this ),
        nprecisionHoleLayers( parent.nprecisionHoleLayers, index, this ),
        nphiLayers( parent.nphiLayers, index, this ),
        ntrigEtaLayers( parent.ntrigEtaLayers, index, this ),
        nphiHoleLayers( parent.nphiHoleLayers, index, this ),
        ntrigEtaHoleLayers( parent.ntrigEtaHoleLayers, index, this ),
        nMDTBIHits( parent.nMDTBIHits, index, this ),
        nMDTBMHits( parent.nMDTBMHits, index, this ),
        nMDTBOHits( parent.nMDTBOHits, index, this ),
        nMDTBEEHits( parent.nMDTBEEHits, index, this ),
        nMDTBIS78Hits( parent.nMDTBIS78Hits, index, this ),
        nMDTEIHits( parent.nMDTEIHits, index, this ),
        nMDTEMHits( parent.nMDTEMHits, index, this ),
        nMDTEOHits( parent.nMDTEOHits, index, this ),
        nMDTEEHits( parent.nMDTEEHits, index, this ),
// -- slimmed --         nRPCLayer1EtaHits( parent.nRPCLayer1EtaHits, index, this ),
// -- slimmed --         nRPCLayer2EtaHits( parent.nRPCLayer2EtaHits, index, this ),
// -- slimmed --         nRPCLayer3EtaHits( parent.nRPCLayer3EtaHits, index, this ),
// -- slimmed --         nRPCLayer1PhiHits( parent.nRPCLayer1PhiHits, index, this ),
// -- slimmed --         nRPCLayer2PhiHits( parent.nRPCLayer2PhiHits, index, this ),
// -- slimmed --         nRPCLayer3PhiHits( parent.nRPCLayer3PhiHits, index, this ),
// -- slimmed --         nTGCLayer1EtaHits( parent.nTGCLayer1EtaHits, index, this ),
// -- slimmed --         nTGCLayer2EtaHits( parent.nTGCLayer2EtaHits, index, this ),
// -- slimmed --         nTGCLayer3EtaHits( parent.nTGCLayer3EtaHits, index, this ),
// -- slimmed --         nTGCLayer4EtaHits( parent.nTGCLayer4EtaHits, index, this ),
// -- slimmed --         nTGCLayer1PhiHits( parent.nTGCLayer1PhiHits, index, this ),
// -- slimmed --         nTGCLayer2PhiHits( parent.nTGCLayer2PhiHits, index, this ),
// -- slimmed --         nTGCLayer3PhiHits( parent.nTGCLayer3PhiHits, index, this ),
// -- slimmed --         nTGCLayer4PhiHits( parent.nTGCLayer4PhiHits, index, this ),
// -- slimmed --         barrelSectors( parent.barrelSectors, index, this ),
// -- slimmed --         endcapSectors( parent.endcapSectors, index, this ),
        trackd0( parent.trackd0, index, this ),
        trackz0( parent.trackz0, index, this ),
        trackphi( parent.trackphi, index, this ),
        tracktheta( parent.tracktheta, index, this ),
        trackqoverp( parent.trackqoverp, index, this ),
        trackcov_d0( parent.trackcov_d0, index, this ),
        trackcov_z0( parent.trackcov_z0, index, this ),
        trackcov_phi( parent.trackcov_phi, index, this ),
        trackcov_theta( parent.trackcov_theta, index, this ),
        trackcov_qoverp( parent.trackcov_qoverp, index, this ),
        trackcov_d0_z0( parent.trackcov_d0_z0, index, this ),
        trackcov_d0_phi( parent.trackcov_d0_phi, index, this ),
        trackcov_d0_theta( parent.trackcov_d0_theta, index, this ),
        trackcov_d0_qoverp( parent.trackcov_d0_qoverp, index, this ),
        trackcov_z0_phi( parent.trackcov_z0_phi, index, this ),
        trackcov_z0_theta( parent.trackcov_z0_theta, index, this ),
        trackcov_z0_qoverp( parent.trackcov_z0_qoverp, index, this ),
        trackcov_phi_theta( parent.trackcov_phi_theta, index, this ),
        trackcov_phi_qoverp( parent.trackcov_phi_qoverp, index, this ),
        trackcov_theta_qoverp( parent.trackcov_theta_qoverp, index, this ),
        hastrack( parent.hastrack, index, this ),
// -- slimmed --         trackIPEstimate_d0_biasedpvunbiased( parent.trackIPEstimate_d0_biasedpvunbiased, index, this ),
// -- slimmed --         trackIPEstimate_z0_biasedpvunbiased( parent.trackIPEstimate_z0_biasedpvunbiased, index, this ),
// -- slimmed --         trackIPEstimate_sigd0_biasedpvunbiased( parent.trackIPEstimate_sigd0_biasedpvunbiased, index, this ),
// -- slimmed --         trackIPEstimate_sigz0_biasedpvunbiased( parent.trackIPEstimate_sigz0_biasedpvunbiased, index, this ),
// -- slimmed --         trackIPEstimate_d0_unbiasedpvunbiased( parent.trackIPEstimate_d0_unbiasedpvunbiased, index, this ),
// -- slimmed --         trackIPEstimate_z0_unbiasedpvunbiased( parent.trackIPEstimate_z0_unbiasedpvunbiased, index, this ),
// -- slimmed --         trackIPEstimate_sigd0_unbiasedpvunbiased( parent.trackIPEstimate_sigd0_unbiasedpvunbiased, index, this ),
// -- slimmed --         trackIPEstimate_sigz0_unbiasedpvunbiased( parent.trackIPEstimate_sigz0_unbiasedpvunbiased, index, this ),
// MC only
        type( parent.type, index, this ),
        origin( parent.origin, index, this ),
        truth_dr( parent.truth_dr, index, this ),
        truth_E( parent.truth_E, index, this ),
        truth_pt( parent.truth_pt, index, this ),
        truth_eta( parent.truth_eta, index, this ),
        truth_phi( parent.truth_phi, index, this ),
        truth_type( parent.truth_type, index, this ),
        truth_status( parent.truth_status, index, this ),
        truth_barcode( parent.truth_barcode, index, this ),
        truth_mothertype( parent.truth_mothertype, index, this ),
        truth_motherbarcode( parent.truth_motherbarcode, index, this ),
        truth_matched( parent.truth_matched, index, this ),
// end MC only
        EFCB_index( parent.EFCB_index, index, this ),
        EFMG_index( parent.EFMG_index, index, this ),
        EFME_index( parent.EFME_index, index, this ),
        ptcone20_trk500MeV( parent.ptcone20_trk500MeV, index, this ),
        ptcone30_trk500MeV( parent.ptcone30_trk500MeV, index, this ),
        ptcone40_trk500MeV( parent.ptcone40_trk500MeV, index, this ),
        nucone20_trk500MeV( parent.nucone20_trk500MeV, index, this ),
        nucone30_trk500MeV( parent.nucone30_trk500MeV, index, this ),
        nucone40_trk500MeV( parent.nucone40_trk500MeV, index, this ),
        ptcone20_trkelstyle( parent.ptcone20_trkelstyle, index, this ),
        ptcone30_trkelstyle( parent.ptcone30_trkelstyle, index, this ),
        ptcone40_trkelstyle( parent.ptcone40_trkelstyle, index, this ),
        nucone20_trkelstyle( parent.nucone20_trkelstyle, index, this ),
        nucone30_trkelstyle( parent.nucone30_trkelstyle, index, this ),
        nucone40_trkelstyle( parent.nucone40_trkelstyle, index, this ),
// -- slimmed --         MET_Simplified20_wpx( parent.MET_Simplified20_wpx, index, this ),
// -- slimmed --         MET_Simplified20_wpy( parent.MET_Simplified20_wpy, index, this ),
// -- slimmed --         MET_Simplified20_wet( parent.MET_Simplified20_wet, index, this ),
// -- slimmed --         MET_Simplified20_statusWord( parent.MET_Simplified20_statusWord, index, this ),
        MET_Egamma10NoTau_wpx( parent.MET_Egamma10NoTau_wpx, index, this ),
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
// -- slimmed -- // -- slimmed --         MET_STVF_statusWord( parent.MET_STVF_statusWord, index, this ) , 
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
   MuonD3PDObjectElement::MuonD3PDObjectElement( const MuonD3PDObjectElement& parent , bool is_data )
      : TObject( parent ),
        E( parent.E ),
        pt( parent.pt ),
        m( parent.m ),
        eta( parent.eta ),
        phi( parent.phi ),
        px( parent.px ),
        py( parent.py ),
        pz( parent.pz ),
        charge( parent.charge ),
        allauthor( parent.allauthor ),
        author( parent.author ),
        matchchi2( parent.matchchi2 ),
        matchndof( parent.matchndof ),
        etcone20( parent.etcone20 ),
        etcone30( parent.etcone30 ),
        etcone40( parent.etcone40 ),
        nucone20( parent.nucone20 ),
        nucone30( parent.nucone30 ),
        nucone40( parent.nucone40 ),
        ptcone20( parent.ptcone20 ),
        ptcone30( parent.ptcone30 ),
        ptcone40( parent.ptcone40 ),
// -- slimmed --         etconeNoEm10( parent.etconeNoEm10 ),
// -- slimmed --         etconeNoEm20( parent.etconeNoEm20 ),
// -- slimmed --         etconeNoEm30( parent.etconeNoEm30 ),
// -- slimmed --         etconeNoEm40( parent.etconeNoEm40 ),
// -- slimmed --         scatteringCurvatureSignificance( parent.scatteringCurvatureSignificance ),
// -- slimmed --         scatteringNeighbourSignificance( parent.scatteringNeighbourSignificance ),
// -- slimmed --         momentumBalanceSignificance( parent.momentumBalanceSignificance ),
        energyLossPar( parent.energyLossPar ),
        energyLossErr( parent.energyLossErr ),
        etCore( parent.etCore ),
        energyLossType( parent.energyLossType ),
        caloMuonIdTag( parent.caloMuonIdTag ),
        caloLRLikelihood( parent.caloLRLikelihood ),
        bestMatch( parent.bestMatch ),
        isStandAloneMuon( parent.isStandAloneMuon ),
        isCombinedMuon( parent.isCombinedMuon ),
        isLowPtReconstructedMuon( parent.isLowPtReconstructedMuon ),
        isSegmentTaggedMuon( parent.isSegmentTaggedMuon ),
        isCaloMuonId( parent.isCaloMuonId ),
// -- slimmed --         alsoFoundByLowPt( parent.alsoFoundByLowPt ),
// -- slimmed --         alsoFoundByCaloMuonId( parent.alsoFoundByCaloMuonId ),
// -- slimmed --         isSiliconAssociatedForwardMuon( parent.isSiliconAssociatedForwardMuon ),
        loose( parent.loose ),
        medium( parent.medium ),
        tight( parent.tight ),
        d0_exPV( parent.d0_exPV ),
        z0_exPV( parent.z0_exPV ),
        phi_exPV( parent.phi_exPV ),
        theta_exPV( parent.theta_exPV ),
        qoverp_exPV( parent.qoverp_exPV ),
        cb_d0_exPV( parent.cb_d0_exPV ),
        cb_z0_exPV( parent.cb_z0_exPV ),
        cb_phi_exPV( parent.cb_phi_exPV ),
        cb_theta_exPV( parent.cb_theta_exPV ),
        cb_qoverp_exPV( parent.cb_qoverp_exPV ),
        id_d0_exPV( parent.id_d0_exPV ),
        id_z0_exPV( parent.id_z0_exPV ),
        id_phi_exPV( parent.id_phi_exPV ),
        id_theta_exPV( parent.id_theta_exPV ),
        id_qoverp_exPV( parent.id_qoverp_exPV ),
        me_d0_exPV( parent.me_d0_exPV ),
        me_z0_exPV( parent.me_z0_exPV ),
        me_phi_exPV( parent.me_phi_exPV ),
        me_theta_exPV( parent.me_theta_exPV ),
        me_qoverp_exPV( parent.me_qoverp_exPV ),
        ie_d0_exPV( parent.ie_d0_exPV ),
        ie_z0_exPV( parent.ie_z0_exPV ),
        ie_phi_exPV( parent.ie_phi_exPV ),
        ie_theta_exPV( parent.ie_theta_exPV ),
        ie_qoverp_exPV( parent.ie_qoverp_exPV ),
        cov_d0_exPV( parent.cov_d0_exPV ),
        cov_z0_exPV( parent.cov_z0_exPV ),
        cov_phi_exPV( parent.cov_phi_exPV ),
        cov_theta_exPV( parent.cov_theta_exPV ),
        cov_qoverp_exPV( parent.cov_qoverp_exPV ),
        cov_d0_z0_exPV( parent.cov_d0_z0_exPV ),
        cov_d0_phi_exPV( parent.cov_d0_phi_exPV ),
        cov_d0_theta_exPV( parent.cov_d0_theta_exPV ),
        cov_d0_qoverp_exPV( parent.cov_d0_qoverp_exPV ),
        cov_z0_phi_exPV( parent.cov_z0_phi_exPV ),
        cov_z0_theta_exPV( parent.cov_z0_theta_exPV ),
        cov_z0_qoverp_exPV( parent.cov_z0_qoverp_exPV ),
        cov_phi_theta_exPV( parent.cov_phi_theta_exPV ),
        cov_phi_qoverp_exPV( parent.cov_phi_qoverp_exPV ),
        cov_theta_qoverp_exPV( parent.cov_theta_qoverp_exPV ),
        id_cov_d0_exPV( parent.id_cov_d0_exPV ),
        id_cov_z0_exPV( parent.id_cov_z0_exPV ),
        id_cov_phi_exPV( parent.id_cov_phi_exPV ),
        id_cov_theta_exPV( parent.id_cov_theta_exPV ),
        id_cov_qoverp_exPV( parent.id_cov_qoverp_exPV ),
        id_cov_d0_z0_exPV( parent.id_cov_d0_z0_exPV ),
        id_cov_d0_phi_exPV( parent.id_cov_d0_phi_exPV ),
        id_cov_d0_theta_exPV( parent.id_cov_d0_theta_exPV ),
        id_cov_d0_qoverp_exPV( parent.id_cov_d0_qoverp_exPV ),
        id_cov_z0_phi_exPV( parent.id_cov_z0_phi_exPV ),
        id_cov_z0_theta_exPV( parent.id_cov_z0_theta_exPV ),
        id_cov_z0_qoverp_exPV( parent.id_cov_z0_qoverp_exPV ),
        id_cov_phi_theta_exPV( parent.id_cov_phi_theta_exPV ),
        id_cov_phi_qoverp_exPV( parent.id_cov_phi_qoverp_exPV ),
        id_cov_theta_qoverp_exPV( parent.id_cov_theta_qoverp_exPV ),
        me_cov_d0_exPV( parent.me_cov_d0_exPV ),
        me_cov_z0_exPV( parent.me_cov_z0_exPV ),
        me_cov_phi_exPV( parent.me_cov_phi_exPV ),
        me_cov_theta_exPV( parent.me_cov_theta_exPV ),
        me_cov_qoverp_exPV( parent.me_cov_qoverp_exPV ),
        ms_d0( parent.ms_d0 ),
        ms_z0( parent.ms_z0 ),
        ms_phi( parent.ms_phi ),
        ms_theta( parent.ms_theta ),
        ms_qoverp( parent.ms_qoverp ),
        id_d0( parent.id_d0 ),
        id_z0( parent.id_z0 ),
        id_phi( parent.id_phi ),
        id_theta( parent.id_theta ),
        id_qoverp( parent.id_qoverp ),
        me_d0( parent.me_d0 ),
        me_z0( parent.me_z0 ),
        me_phi( parent.me_phi ),
        me_theta( parent.me_theta ),
        me_qoverp( parent.me_qoverp ),
        ie_d0( parent.ie_d0 ),
        ie_z0( parent.ie_z0 ),
        ie_phi( parent.ie_phi ),
        ie_theta( parent.ie_theta ),
        ie_qoverp( parent.ie_qoverp ),
        nOutliersOnTrack( parent.nOutliersOnTrack ),
        nBLHits( parent.nBLHits ),
        nPixHits( parent.nPixHits ),
        nSCTHits( parent.nSCTHits ),
        nTRTHits( parent.nTRTHits ),
        nTRTHighTHits( parent.nTRTHighTHits ),
        nBLSharedHits( parent.nBLSharedHits ),
        nPixSharedHits( parent.nPixSharedHits ),
        nPixHoles( parent.nPixHoles ),
        nSCTSharedHits( parent.nSCTSharedHits ),
        nSCTHoles( parent.nSCTHoles ),
        nTRTOutliers( parent.nTRTOutliers ),
        nTRTHighTOutliers( parent.nTRTHighTOutliers ),
        nGangedPixels( parent.nGangedPixels ),
        nPixelDeadSensors( parent.nPixelDeadSensors ),
        nSCTDeadSensors( parent.nSCTDeadSensors ),
        nTRTDeadStraws( parent.nTRTDeadStraws ),
        expectBLayerHit( parent.expectBLayerHit ),
        nMDTHits( parent.nMDTHits ),
// -- slimmed --         nMDTHoles( parent.nMDTHoles ),
        nCSCEtaHits( parent.nCSCEtaHits ),
// -- slimmed --         nCSCEtaHoles( parent.nCSCEtaHoles ),
        nCSCUnspoiledEtaHits( parent.nCSCUnspoiledEtaHits ),
        nCSCPhiHits( parent.nCSCPhiHits ),
// -- slimmed --         nCSCPhiHoles( parent.nCSCPhiHoles ),
        nRPCEtaHits( parent.nRPCEtaHits ),
// -- slimmed --         nRPCEtaHoles( parent.nRPCEtaHoles ),
        nRPCPhiHits( parent.nRPCPhiHits ),
// -- slimmed --         nRPCPhiHoles( parent.nRPCPhiHoles ),
        nTGCEtaHits( parent.nTGCEtaHits ),
// -- slimmed --         nTGCEtaHoles( parent.nTGCEtaHoles ),
        nTGCPhiHits( parent.nTGCPhiHits ),
// -- slimmed --         nTGCPhiHoles( parent.nTGCPhiHoles ),
        nprecisionLayers( parent.nprecisionLayers ),
        nprecisionHoleLayers( parent.nprecisionHoleLayers ),
        nphiLayers( parent.nphiLayers ),
        ntrigEtaLayers( parent.ntrigEtaLayers ),
        nphiHoleLayers( parent.nphiHoleLayers ),
        ntrigEtaHoleLayers( parent.ntrigEtaHoleLayers ),
        nMDTBIHits( parent.nMDTBIHits ),
        nMDTBMHits( parent.nMDTBMHits ),
        nMDTBOHits( parent.nMDTBOHits ),
        nMDTBEEHits( parent.nMDTBEEHits ),
        nMDTBIS78Hits( parent.nMDTBIS78Hits ),
        nMDTEIHits( parent.nMDTEIHits ),
        nMDTEMHits( parent.nMDTEMHits ),
        nMDTEOHits( parent.nMDTEOHits ),
        nMDTEEHits( parent.nMDTEEHits ),
// -- slimmed --         nRPCLayer1EtaHits( parent.nRPCLayer1EtaHits ),
// -- slimmed --         nRPCLayer2EtaHits( parent.nRPCLayer2EtaHits ),
// -- slimmed --         nRPCLayer3EtaHits( parent.nRPCLayer3EtaHits ),
// -- slimmed --         nRPCLayer1PhiHits( parent.nRPCLayer1PhiHits ),
// -- slimmed --         nRPCLayer2PhiHits( parent.nRPCLayer2PhiHits ),
// -- slimmed --         nRPCLayer3PhiHits( parent.nRPCLayer3PhiHits ),
// -- slimmed --         nTGCLayer1EtaHits( parent.nTGCLayer1EtaHits ),
// -- slimmed --         nTGCLayer2EtaHits( parent.nTGCLayer2EtaHits ),
// -- slimmed --         nTGCLayer3EtaHits( parent.nTGCLayer3EtaHits ),
// -- slimmed --         nTGCLayer4EtaHits( parent.nTGCLayer4EtaHits ),
// -- slimmed --         nTGCLayer1PhiHits( parent.nTGCLayer1PhiHits ),
// -- slimmed --         nTGCLayer2PhiHits( parent.nTGCLayer2PhiHits ),
// -- slimmed --         nTGCLayer3PhiHits( parent.nTGCLayer3PhiHits ),
// -- slimmed --         nTGCLayer4PhiHits( parent.nTGCLayer4PhiHits ),
// -- slimmed --         barrelSectors( parent.barrelSectors ),
// -- slimmed --         endcapSectors( parent.endcapSectors ),
        trackd0( parent.trackd0 ),
        trackz0( parent.trackz0 ),
        trackphi( parent.trackphi ),
        tracktheta( parent.tracktheta ),
        trackqoverp( parent.trackqoverp ),
        trackcov_d0( parent.trackcov_d0 ),
        trackcov_z0( parent.trackcov_z0 ),
        trackcov_phi( parent.trackcov_phi ),
        trackcov_theta( parent.trackcov_theta ),
        trackcov_qoverp( parent.trackcov_qoverp ),
        trackcov_d0_z0( parent.trackcov_d0_z0 ),
        trackcov_d0_phi( parent.trackcov_d0_phi ),
        trackcov_d0_theta( parent.trackcov_d0_theta ),
        trackcov_d0_qoverp( parent.trackcov_d0_qoverp ),
        trackcov_z0_phi( parent.trackcov_z0_phi ),
        trackcov_z0_theta( parent.trackcov_z0_theta ),
        trackcov_z0_qoverp( parent.trackcov_z0_qoverp ),
        trackcov_phi_theta( parent.trackcov_phi_theta ),
        trackcov_phi_qoverp( parent.trackcov_phi_qoverp ),
        trackcov_theta_qoverp( parent.trackcov_theta_qoverp ),
        hastrack( parent.hastrack ),
// -- slimmed --         trackIPEstimate_d0_biasedpvunbiased( parent.trackIPEstimate_d0_biasedpvunbiased ),
// -- slimmed --         trackIPEstimate_z0_biasedpvunbiased( parent.trackIPEstimate_z0_biasedpvunbiased ),
// -- slimmed --         trackIPEstimate_sigd0_biasedpvunbiased( parent.trackIPEstimate_sigd0_biasedpvunbiased ),
// -- slimmed --         trackIPEstimate_sigz0_biasedpvunbiased( parent.trackIPEstimate_sigz0_biasedpvunbiased ),
// -- slimmed --         trackIPEstimate_d0_unbiasedpvunbiased( parent.trackIPEstimate_d0_unbiasedpvunbiased ),
// -- slimmed --         trackIPEstimate_z0_unbiasedpvunbiased( parent.trackIPEstimate_z0_unbiasedpvunbiased ),
// -- slimmed --         trackIPEstimate_sigd0_unbiasedpvunbiased( parent.trackIPEstimate_sigd0_unbiasedpvunbiased ),
// -- slimmed --         trackIPEstimate_sigz0_unbiasedpvunbiased( parent.trackIPEstimate_sigz0_unbiasedpvunbiased ),
// MC only
        type( parent.type ),
        origin( parent.origin ),
        truth_dr( parent.truth_dr ),
        truth_E( parent.truth_E ),
        truth_pt( parent.truth_pt ),
        truth_eta( parent.truth_eta ),
        truth_phi( parent.truth_phi ),
        truth_type( parent.truth_type ),
        truth_status( parent.truth_status ),
        truth_barcode( parent.truth_barcode ),
        truth_mothertype( parent.truth_mothertype ),
        truth_motherbarcode( parent.truth_motherbarcode ),
        truth_matched( parent.truth_matched ),
// end MC only
        EFCB_index( parent.EFCB_index ),
        EFMG_index( parent.EFMG_index ),
        EFME_index( parent.EFME_index ),
        ptcone20_trk500MeV( parent.ptcone20_trk500MeV ),
        ptcone30_trk500MeV( parent.ptcone30_trk500MeV ),
        ptcone40_trk500MeV( parent.ptcone40_trk500MeV ),
        nucone20_trk500MeV( parent.nucone20_trk500MeV ),
        nucone30_trk500MeV( parent.nucone30_trk500MeV ),
        nucone40_trk500MeV( parent.nucone40_trk500MeV ),
        ptcone20_trkelstyle( parent.ptcone20_trkelstyle ),
        ptcone30_trkelstyle( parent.ptcone30_trkelstyle ),
        ptcone40_trkelstyle( parent.ptcone40_trkelstyle ),
        nucone20_trkelstyle( parent.nucone20_trkelstyle ),
        nucone30_trkelstyle( parent.nucone30_trkelstyle ),
        nucone40_trkelstyle( parent.nucone40_trkelstyle ),
// -- slimmed --         MET_Simplified20_wpx( parent.MET_Simplified20_wpx ),
// -- slimmed --         MET_Simplified20_wpy( parent.MET_Simplified20_wpy ),
// -- slimmed --         MET_Simplified20_wet( parent.MET_Simplified20_wet ),
// -- slimmed --         MET_Simplified20_statusWord( parent.MET_Simplified20_statusWord ),
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
// -- slimmed -- // -- slimmed --         MET_STVF_statusWord( parent.MET_STVF_statusWord ) , 
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
   MuonD3PDObject::MuonD3PDObject( const ::Long64_t& master, const char* prefix , bool is_data )
      : TObject(),
        n( this, ::TString( prefix ) + "n", &master ),
        E( this, ::TString( prefix ) + "E", &master ),
        pt( this, ::TString( prefix ) + "pt", &master ),
        m( this, ::TString( prefix ) + "m", &master ),
        eta( this, ::TString( prefix ) + "eta", &master ),
        phi( this, ::TString( prefix ) + "phi", &master ),
        px( this, ::TString( prefix ) + "px", &master ),
        py( this, ::TString( prefix ) + "py", &master ),
        pz( this, ::TString( prefix ) + "pz", &master ),
        charge( this, ::TString( prefix ) + "charge", &master ),
        allauthor( this, ::TString( prefix ) + "allauthor", &master ),
        author( this, ::TString( prefix ) + "author", &master ),
        matchchi2( this, ::TString( prefix ) + "matchchi2", &master ),
        matchndof( this, ::TString( prefix ) + "matchndof", &master ),
        etcone20( this, ::TString( prefix ) + "etcone20", &master ),
        etcone30( this, ::TString( prefix ) + "etcone30", &master ),
        etcone40( this, ::TString( prefix ) + "etcone40", &master ),
        nucone20( this, ::TString( prefix ) + "nucone20", &master ),
        nucone30( this, ::TString( prefix ) + "nucone30", &master ),
        nucone40( this, ::TString( prefix ) + "nucone40", &master ),
        ptcone20( this, ::TString( prefix ) + "ptcone20", &master ),
        ptcone30( this, ::TString( prefix ) + "ptcone30", &master ),
        ptcone40( this, ::TString( prefix ) + "ptcone40", &master ),
// -- slimmed --         etconeNoEm10( this, ::TString( prefix ) + "etconeNoEm10", &master ),
// -- slimmed --         etconeNoEm20( this, ::TString( prefix ) + "etconeNoEm20", &master ),
// -- slimmed --         etconeNoEm30( this, ::TString( prefix ) + "etconeNoEm30", &master ),
// -- slimmed --         etconeNoEm40( this, ::TString( prefix ) + "etconeNoEm40", &master ),
// -- slimmed --         scatteringCurvatureSignificance( this, ::TString( prefix ) + "scatteringCurvatureSignificance", &master ),
// -- slimmed --         scatteringNeighbourSignificance( this, ::TString( prefix ) + "scatteringNeighbourSignificance", &master ),
// -- slimmed --         momentumBalanceSignificance( this, ::TString( prefix ) + "momentumBalanceSignificance", &master ),
        energyLossPar( this, ::TString( prefix ) + "energyLossPar", &master ),
        energyLossErr( this, ::TString( prefix ) + "energyLossErr", &master ),
        etCore( this, ::TString( prefix ) + "etCore", &master ),
        energyLossType( this, ::TString( prefix ) + "energyLossType", &master ),
        caloMuonIdTag( this, ::TString( prefix ) + "caloMuonIdTag", &master ),
        caloLRLikelihood( this, ::TString( prefix ) + "caloLRLikelihood", &master ),
        bestMatch( this, ::TString( prefix ) + "bestMatch", &master ),
        isStandAloneMuon( this, ::TString( prefix ) + "isStandAloneMuon", &master ),
        isCombinedMuon( this, ::TString( prefix ) + "isCombinedMuon", &master ),
        isLowPtReconstructedMuon( this, ::TString( prefix ) + "isLowPtReconstructedMuon", &master ),
        isSegmentTaggedMuon( this, ::TString( prefix ) + "isSegmentTaggedMuon", &master ),
        isCaloMuonId( this, ::TString( prefix ) + "isCaloMuonId", &master ),
// -- slimmed --         alsoFoundByLowPt( this, ::TString( prefix ) + "alsoFoundByLowPt", &master ),
// -- slimmed --         alsoFoundByCaloMuonId( this, ::TString( prefix ) + "alsoFoundByCaloMuonId", &master ),
// -- slimmed --         isSiliconAssociatedForwardMuon( this, ::TString( prefix ) + "isSiliconAssociatedForwardMuon", &master ),
        loose( this, ::TString( prefix ) + "loose", &master ),
        medium( this, ::TString( prefix ) + "medium", &master ),
        tight( this, ::TString( prefix ) + "tight", &master ),
        d0_exPV( this, ::TString( prefix ) + "d0_exPV", &master ),
        z0_exPV( this, ::TString( prefix ) + "z0_exPV", &master ),
        phi_exPV( this, ::TString( prefix ) + "phi_exPV", &master ),
        theta_exPV( this, ::TString( prefix ) + "theta_exPV", &master ),
        qoverp_exPV( this, ::TString( prefix ) + "qoverp_exPV", &master ),
        cb_d0_exPV( this, ::TString( prefix ) + "cb_d0_exPV", &master ),
        cb_z0_exPV( this, ::TString( prefix ) + "cb_z0_exPV", &master ),
        cb_phi_exPV( this, ::TString( prefix ) + "cb_phi_exPV", &master ),
        cb_theta_exPV( this, ::TString( prefix ) + "cb_theta_exPV", &master ),
        cb_qoverp_exPV( this, ::TString( prefix ) + "cb_qoverp_exPV", &master ),
        id_d0_exPV( this, ::TString( prefix ) + "id_d0_exPV", &master ),
        id_z0_exPV( this, ::TString( prefix ) + "id_z0_exPV", &master ),
        id_phi_exPV( this, ::TString( prefix ) + "id_phi_exPV", &master ),
        id_theta_exPV( this, ::TString( prefix ) + "id_theta_exPV", &master ),
        id_qoverp_exPV( this, ::TString( prefix ) + "id_qoverp_exPV", &master ),
        me_d0_exPV( this, ::TString( prefix ) + "me_d0_exPV", &master ),
        me_z0_exPV( this, ::TString( prefix ) + "me_z0_exPV", &master ),
        me_phi_exPV( this, ::TString( prefix ) + "me_phi_exPV", &master ),
        me_theta_exPV( this, ::TString( prefix ) + "me_theta_exPV", &master ),
        me_qoverp_exPV( this, ::TString( prefix ) + "me_qoverp_exPV", &master ),
        ie_d0_exPV( this, ::TString( prefix ) + "ie_d0_exPV", &master ),
        ie_z0_exPV( this, ::TString( prefix ) + "ie_z0_exPV", &master ),
        ie_phi_exPV( this, ::TString( prefix ) + "ie_phi_exPV", &master ),
        ie_theta_exPV( this, ::TString( prefix ) + "ie_theta_exPV", &master ),
        ie_qoverp_exPV( this, ::TString( prefix ) + "ie_qoverp_exPV", &master ),
        cov_d0_exPV( this, ::TString( prefix ) + "cov_d0_exPV", &master ),
        cov_z0_exPV( this, ::TString( prefix ) + "cov_z0_exPV", &master ),
        cov_phi_exPV( this, ::TString( prefix ) + "cov_phi_exPV", &master ),
        cov_theta_exPV( this, ::TString( prefix ) + "cov_theta_exPV", &master ),
        cov_qoverp_exPV( this, ::TString( prefix ) + "cov_qoverp_exPV", &master ),
        cov_d0_z0_exPV( this, ::TString( prefix ) + "cov_d0_z0_exPV", &master ),
        cov_d0_phi_exPV( this, ::TString( prefix ) + "cov_d0_phi_exPV", &master ),
        cov_d0_theta_exPV( this, ::TString( prefix ) + "cov_d0_theta_exPV", &master ),
        cov_d0_qoverp_exPV( this, ::TString( prefix ) + "cov_d0_qoverp_exPV", &master ),
        cov_z0_phi_exPV( this, ::TString( prefix ) + "cov_z0_phi_exPV", &master ),
        cov_z0_theta_exPV( this, ::TString( prefix ) + "cov_z0_theta_exPV", &master ),
        cov_z0_qoverp_exPV( this, ::TString( prefix ) + "cov_z0_qoverp_exPV", &master ),
        cov_phi_theta_exPV( this, ::TString( prefix ) + "cov_phi_theta_exPV", &master ),
        cov_phi_qoverp_exPV( this, ::TString( prefix ) + "cov_phi_qoverp_exPV", &master ),
        cov_theta_qoverp_exPV( this, ::TString( prefix ) + "cov_theta_qoverp_exPV", &master ),
        id_cov_d0_exPV( this, ::TString( prefix ) + "id_cov_d0_exPV", &master ),
        id_cov_z0_exPV( this, ::TString( prefix ) + "id_cov_z0_exPV", &master ),
        id_cov_phi_exPV( this, ::TString( prefix ) + "id_cov_phi_exPV", &master ),
        id_cov_theta_exPV( this, ::TString( prefix ) + "id_cov_theta_exPV", &master ),
        id_cov_qoverp_exPV( this, ::TString( prefix ) + "id_cov_qoverp_exPV", &master ),
        id_cov_d0_z0_exPV( this, ::TString( prefix ) + "id_cov_d0_z0_exPV", &master ),
        id_cov_d0_phi_exPV( this, ::TString( prefix ) + "id_cov_d0_phi_exPV", &master ),
        id_cov_d0_theta_exPV( this, ::TString( prefix ) + "id_cov_d0_theta_exPV", &master ),
        id_cov_d0_qoverp_exPV( this, ::TString( prefix ) + "id_cov_d0_qoverp_exPV", &master ),
        id_cov_z0_phi_exPV( this, ::TString( prefix ) + "id_cov_z0_phi_exPV", &master ),
        id_cov_z0_theta_exPV( this, ::TString( prefix ) + "id_cov_z0_theta_exPV", &master ),
        id_cov_z0_qoverp_exPV( this, ::TString( prefix ) + "id_cov_z0_qoverp_exPV", &master ),
        id_cov_phi_theta_exPV( this, ::TString( prefix ) + "id_cov_phi_theta_exPV", &master ),
        id_cov_phi_qoverp_exPV( this, ::TString( prefix ) + "id_cov_phi_qoverp_exPV", &master ),
        id_cov_theta_qoverp_exPV( this, ::TString( prefix ) + "id_cov_theta_qoverp_exPV", &master ),
        me_cov_d0_exPV( this, ::TString( prefix ) + "me_cov_d0_exPV", &master ),
        me_cov_z0_exPV( this, ::TString( prefix ) + "me_cov_z0_exPV", &master ),
        me_cov_phi_exPV( this, ::TString( prefix ) + "me_cov_phi_exPV", &master ),
        me_cov_theta_exPV( this, ::TString( prefix ) + "me_cov_theta_exPV", &master ),
        me_cov_qoverp_exPV( this, ::TString( prefix ) + "me_cov_qoverp_exPV", &master ),
        ms_d0( this, ::TString( prefix ) + "ms_d0", &master ),
        ms_z0( this, ::TString( prefix ) + "ms_z0", &master ),
        ms_phi( this, ::TString( prefix ) + "ms_phi", &master ),
        ms_theta( this, ::TString( prefix ) + "ms_theta", &master ),
        ms_qoverp( this, ::TString( prefix ) + "ms_qoverp", &master ),
        id_d0( this, ::TString( prefix ) + "id_d0", &master ),
        id_z0( this, ::TString( prefix ) + "id_z0", &master ),
        id_phi( this, ::TString( prefix ) + "id_phi", &master ),
        id_theta( this, ::TString( prefix ) + "id_theta", &master ),
        id_qoverp( this, ::TString( prefix ) + "id_qoverp", &master ),
        me_d0( this, ::TString( prefix ) + "me_d0", &master ),
        me_z0( this, ::TString( prefix ) + "me_z0", &master ),
        me_phi( this, ::TString( prefix ) + "me_phi", &master ),
        me_theta( this, ::TString( prefix ) + "me_theta", &master ),
        me_qoverp( this, ::TString( prefix ) + "me_qoverp", &master ),
        ie_d0( this, ::TString( prefix ) + "ie_d0", &master ),
        ie_z0( this, ::TString( prefix ) + "ie_z0", &master ),
        ie_phi( this, ::TString( prefix ) + "ie_phi", &master ),
        ie_theta( this, ::TString( prefix ) + "ie_theta", &master ),
        ie_qoverp( this, ::TString( prefix ) + "ie_qoverp", &master ),
        nOutliersOnTrack( this, ::TString( prefix ) + "nOutliersOnTrack", &master ),
        nBLHits( this, ::TString( prefix ) + "nBLHits", &master ),
        nPixHits( this, ::TString( prefix ) + "nPixHits", &master ),
        nSCTHits( this, ::TString( prefix ) + "nSCTHits", &master ),
        nTRTHits( this, ::TString( prefix ) + "nTRTHits", &master ),
        nTRTHighTHits( this, ::TString( prefix ) + "nTRTHighTHits", &master ),
        nBLSharedHits( this, ::TString( prefix ) + "nBLSharedHits", &master ),
        nPixSharedHits( this, ::TString( prefix ) + "nPixSharedHits", &master ),
        nPixHoles( this, ::TString( prefix ) + "nPixHoles", &master ),
        nSCTSharedHits( this, ::TString( prefix ) + "nSCTSharedHits", &master ),
        nSCTHoles( this, ::TString( prefix ) + "nSCTHoles", &master ),
        nTRTOutliers( this, ::TString( prefix ) + "nTRTOutliers", &master ),
        nTRTHighTOutliers( this, ::TString( prefix ) + "nTRTHighTOutliers", &master ),
        nGangedPixels( this, ::TString( prefix ) + "nGangedPixels", &master ),
        nPixelDeadSensors( this, ::TString( prefix ) + "nPixelDeadSensors", &master ),
        nSCTDeadSensors( this, ::TString( prefix ) + "nSCTDeadSensors", &master ),
        nTRTDeadStraws( this, ::TString( prefix ) + "nTRTDeadStraws", &master ),
        expectBLayerHit( this, ::TString( prefix ) + "expectBLayerHit", &master ),
        nMDTHits( this, ::TString( prefix ) + "nMDTHits", &master ),
// -- slimmed --         nMDTHoles( this, ::TString( prefix ) + "nMDTHoles", &master ),
        nCSCEtaHits( this, ::TString( prefix ) + "nCSCEtaHits", &master ),
// -- slimmed --         nCSCEtaHoles( this, ::TString( prefix ) + "nCSCEtaHoles", &master ),
        nCSCUnspoiledEtaHits( this, ::TString( prefix ) + "nCSCUnspoiledEtaHits", &master ),
        nCSCPhiHits( this, ::TString( prefix ) + "nCSCPhiHits", &master ),
// -- slimmed --         nCSCPhiHoles( this, ::TString( prefix ) + "nCSCPhiHoles", &master ),
        nRPCEtaHits( this, ::TString( prefix ) + "nRPCEtaHits", &master ),
// -- slimmed --         nRPCEtaHoles( this, ::TString( prefix ) + "nRPCEtaHoles", &master ),
        nRPCPhiHits( this, ::TString( prefix ) + "nRPCPhiHits", &master ),
// -- slimmed --         nRPCPhiHoles( this, ::TString( prefix ) + "nRPCPhiHoles", &master ),
        nTGCEtaHits( this, ::TString( prefix ) + "nTGCEtaHits", &master ),
// -- slimmed --         nTGCEtaHoles( this, ::TString( prefix ) + "nTGCEtaHoles", &master ),
        nTGCPhiHits( this, ::TString( prefix ) + "nTGCPhiHits", &master ),
// -- slimmed --         nTGCPhiHoles( this, ::TString( prefix ) + "nTGCPhiHoles", &master ),
        nprecisionLayers( this, ::TString( prefix ) + "nprecisionLayers", &master ),
        nprecisionHoleLayers( this, ::TString( prefix ) + "nprecisionHoleLayers", &master ),
        nphiLayers( this, ::TString( prefix ) + "nphiLayers", &master ),
        ntrigEtaLayers( this, ::TString( prefix ) + "ntrigEtaLayers", &master ),
        nphiHoleLayers( this, ::TString( prefix ) + "nphiHoleLayers", &master ),
        ntrigEtaHoleLayers( this, ::TString( prefix ) + "ntrigEtaHoleLayers", &master ),
        nMDTBIHits( this, ::TString( prefix ) + "nMDTBIHits", &master ),
        nMDTBMHits( this, ::TString( prefix ) + "nMDTBMHits", &master ),
        nMDTBOHits( this, ::TString( prefix ) + "nMDTBOHits", &master ),
        nMDTBEEHits( this, ::TString( prefix ) + "nMDTBEEHits", &master ),
        nMDTBIS78Hits( this, ::TString( prefix ) + "nMDTBIS78Hits", &master ),
        nMDTEIHits( this, ::TString( prefix ) + "nMDTEIHits", &master ),
        nMDTEMHits( this, ::TString( prefix ) + "nMDTEMHits", &master ),
        nMDTEOHits( this, ::TString( prefix ) + "nMDTEOHits", &master ),
        nMDTEEHits( this, ::TString( prefix ) + "nMDTEEHits", &master ),
// -- slimmed --         nRPCLayer1EtaHits( this, ::TString( prefix ) + "nRPCLayer1EtaHits", &master ),
// -- slimmed --         nRPCLayer2EtaHits( this, ::TString( prefix ) + "nRPCLayer2EtaHits", &master ),
// -- slimmed --         nRPCLayer3EtaHits( this, ::TString( prefix ) + "nRPCLayer3EtaHits", &master ),
// -- slimmed --         nRPCLayer1PhiHits( this, ::TString( prefix ) + "nRPCLayer1PhiHits", &master ),
// -- slimmed --         nRPCLayer2PhiHits( this, ::TString( prefix ) + "nRPCLayer2PhiHits", &master ),
// -- slimmed --         nRPCLayer3PhiHits( this, ::TString( prefix ) + "nRPCLayer3PhiHits", &master ),
// -- slimmed --         nTGCLayer1EtaHits( this, ::TString( prefix ) + "nTGCLayer1EtaHits", &master ),
// -- slimmed --         nTGCLayer2EtaHits( this, ::TString( prefix ) + "nTGCLayer2EtaHits", &master ),
// -- slimmed --         nTGCLayer3EtaHits( this, ::TString( prefix ) + "nTGCLayer3EtaHits", &master ),
// -- slimmed --         nTGCLayer4EtaHits( this, ::TString( prefix ) + "nTGCLayer4EtaHits", &master ),
// -- slimmed --         nTGCLayer1PhiHits( this, ::TString( prefix ) + "nTGCLayer1PhiHits", &master ),
// -- slimmed --         nTGCLayer2PhiHits( this, ::TString( prefix ) + "nTGCLayer2PhiHits", &master ),
// -- slimmed --         nTGCLayer3PhiHits( this, ::TString( prefix ) + "nTGCLayer3PhiHits", &master ),
// -- slimmed --         nTGCLayer4PhiHits( this, ::TString( prefix ) + "nTGCLayer4PhiHits", &master ),
// -- slimmed --         barrelSectors( this, ::TString( prefix ) + "barrelSectors", &master ),
// -- slimmed --         endcapSectors( this, ::TString( prefix ) + "endcapSectors", &master ),
        trackd0( this, ::TString( prefix ) + "trackd0", &master ),
        trackz0( this, ::TString( prefix ) + "trackz0", &master ),
        trackphi( this, ::TString( prefix ) + "trackphi", &master ),
        tracktheta( this, ::TString( prefix ) + "tracktheta", &master ),
        trackqoverp( this, ::TString( prefix ) + "trackqoverp", &master ),
        trackcov_d0( this, ::TString( prefix ) + "trackcov_d0", &master ),
        trackcov_z0( this, ::TString( prefix ) + "trackcov_z0", &master ),
        trackcov_phi( this, ::TString( prefix ) + "trackcov_phi", &master ),
        trackcov_theta( this, ::TString( prefix ) + "trackcov_theta", &master ),
        trackcov_qoverp( this, ::TString( prefix ) + "trackcov_qoverp", &master ),
        trackcov_d0_z0( this, ::TString( prefix ) + "trackcov_d0_z0", &master ),
        trackcov_d0_phi( this, ::TString( prefix ) + "trackcov_d0_phi", &master ),
        trackcov_d0_theta( this, ::TString( prefix ) + "trackcov_d0_theta", &master ),
        trackcov_d0_qoverp( this, ::TString( prefix ) + "trackcov_d0_qoverp", &master ),
        trackcov_z0_phi( this, ::TString( prefix ) + "trackcov_z0_phi", &master ),
        trackcov_z0_theta( this, ::TString( prefix ) + "trackcov_z0_theta", &master ),
        trackcov_z0_qoverp( this, ::TString( prefix ) + "trackcov_z0_qoverp", &master ),
        trackcov_phi_theta( this, ::TString( prefix ) + "trackcov_phi_theta", &master ),
        trackcov_phi_qoverp( this, ::TString( prefix ) + "trackcov_phi_qoverp", &master ),
        trackcov_theta_qoverp( this, ::TString( prefix ) + "trackcov_theta_qoverp", &master ),
        hastrack( this, ::TString( prefix ) + "hastrack", &master ),
// -- slimmed --         trackIPEstimate_d0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_d0_biasedpvunbiased", &master ),
// -- slimmed --         trackIPEstimate_z0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_z0_biasedpvunbiased", &master ),
// -- slimmed --         trackIPEstimate_sigd0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigd0_biasedpvunbiased", &master ),
// -- slimmed --         trackIPEstimate_sigz0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigz0_biasedpvunbiased", &master ),
// -- slimmed --         trackIPEstimate_d0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_d0_unbiasedpvunbiased", &master ),
// -- slimmed --         trackIPEstimate_z0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_z0_unbiasedpvunbiased", &master ),
// -- slimmed --         trackIPEstimate_sigd0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigd0_unbiasedpvunbiased", &master ),
// -- slimmed --         trackIPEstimate_sigz0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigz0_unbiasedpvunbiased", &master ),
// MC only
        type( this, ::TString( prefix ) + "type", &master ),
        origin( this, ::TString( prefix ) + "origin", &master ),
        truth_dr( this, ::TString( prefix ) + "truth_dr", &master ),
        truth_E( this, ::TString( prefix ) + "truth_E", &master ),
        truth_pt( this, ::TString( prefix ) + "truth_pt", &master ),
        truth_eta( this, ::TString( prefix ) + "truth_eta", &master ),
        truth_phi( this, ::TString( prefix ) + "truth_phi", &master ),
        truth_type( this, ::TString( prefix ) + "truth_type", &master ),
        truth_status( this, ::TString( prefix ) + "truth_status", &master ),
        truth_barcode( this, ::TString( prefix ) + "truth_barcode", &master ),
        truth_mothertype( this, ::TString( prefix ) + "truth_mothertype", &master ),
        truth_motherbarcode( this, ::TString( prefix ) + "truth_motherbarcode", &master ),
        truth_matched( this, ::TString( prefix ) + "truth_matched", &master ),
// end MC only
        EFCB_index( this, ::TString( prefix ) + "EFCB_index", &master ),
        EFMG_index( this, ::TString( prefix ) + "EFMG_index", &master ),
        EFME_index( this, ::TString( prefix ) + "EFME_index", &master ),
        ptcone20_trk500MeV( this, ::TString( prefix ) + "ptcone20_trk500MeV", &master ),
        ptcone30_trk500MeV( this, ::TString( prefix ) + "ptcone30_trk500MeV", &master ),
        ptcone40_trk500MeV( this, ::TString( prefix ) + "ptcone40_trk500MeV", &master ),
        nucone20_trk500MeV( this, ::TString( prefix ) + "nucone20_trk500MeV", &master ),
        nucone30_trk500MeV( this, ::TString( prefix ) + "nucone30_trk500MeV", &master ),
        nucone40_trk500MeV( this, ::TString( prefix ) + "nucone40_trk500MeV", &master ),
        ptcone20_trkelstyle( this, ::TString( prefix ) + "ptcone20_trkelstyle", &master ),
        ptcone30_trkelstyle( this, ::TString( prefix ) + "ptcone30_trkelstyle", &master ),
        ptcone40_trkelstyle( this, ::TString( prefix ) + "ptcone40_trkelstyle", &master ),
        nucone20_trkelstyle( this, ::TString( prefix ) + "nucone20_trkelstyle", &master ),
        nucone30_trkelstyle( this, ::TString( prefix ) + "nucone30_trkelstyle", &master ),
        nucone40_trkelstyle( this, ::TString( prefix ) + "nucone40_trkelstyle", &master ),
// -- slimmed --         MET_Simplified20_wpx( this, ::TString( prefix ) + "MET_Simplified20_wpx", &master ),
// -- slimmed --         MET_Simplified20_wpy( this, ::TString( prefix ) + "MET_Simplified20_wpy", &master ),
// -- slimmed --         MET_Simplified20_wet( this, ::TString( prefix ) + "MET_Simplified20_wet", &master ),
// -- slimmed --         MET_Simplified20_statusWord( this, ::TString( prefix ) + "MET_Simplified20_statusWord", &master ),
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
// -- slimmed -- // -- slimmed --         MET_STVF_statusWord( this, ::TString( prefix ) + "MET_STVF_statusWord", &master ),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "n" ] = &n;
      fHandles[ "E" ] = &E;
      fHandles[ "pt" ] = &pt;
      fHandles[ "m" ] = &m;
      fHandles[ "eta" ] = &eta;
      fHandles[ "phi" ] = &phi;
      fHandles[ "px" ] = &px;
      fHandles[ "py" ] = &py;
      fHandles[ "pz" ] = &pz;
      fHandles[ "charge" ] = &charge;
      fHandles[ "allauthor" ] = &allauthor;
      fHandles[ "author" ] = &author;
      fHandles[ "matchchi2" ] = &matchchi2;
      fHandles[ "matchndof" ] = &matchndof;
      fHandles[ "etcone20" ] = &etcone20;
      fHandles[ "etcone30" ] = &etcone30;
      fHandles[ "etcone40" ] = &etcone40;
      fHandles[ "nucone20" ] = &nucone20;
      fHandles[ "nucone30" ] = &nucone30;
      fHandles[ "nucone40" ] = &nucone40;
      fHandles[ "ptcone20" ] = &ptcone20;
      fHandles[ "ptcone30" ] = &ptcone30;
      fHandles[ "ptcone40" ] = &ptcone40;
// -- slimmed --       fHandles[ "etconeNoEm10" ] = &etconeNoEm10;
// -- slimmed --       fHandles[ "etconeNoEm20" ] = &etconeNoEm20;
// -- slimmed --       fHandles[ "etconeNoEm30" ] = &etconeNoEm30;
// -- slimmed --       fHandles[ "etconeNoEm40" ] = &etconeNoEm40;
// -- slimmed --       fHandles[ "scatteringCurvatureSignificance" ] = &scatteringCurvatureSignificance;
// -- slimmed --       fHandles[ "scatteringNeighbourSignificance" ] = &scatteringNeighbourSignificance;
// -- slimmed --       fHandles[ "momentumBalanceSignificance" ] = &momentumBalanceSignificance;
      fHandles[ "energyLossPar" ] = &energyLossPar;
      fHandles[ "energyLossErr" ] = &energyLossErr;
      fHandles[ "etCore" ] = &etCore;
      fHandles[ "energyLossType" ] = &energyLossType;
      fHandles[ "caloMuonIdTag" ] = &caloMuonIdTag;
      fHandles[ "caloLRLikelihood" ] = &caloLRLikelihood;
      fHandles[ "bestMatch" ] = &bestMatch;
      fHandles[ "isStandAloneMuon" ] = &isStandAloneMuon;
      fHandles[ "isCombinedMuon" ] = &isCombinedMuon;
      fHandles[ "isLowPtReconstructedMuon" ] = &isLowPtReconstructedMuon;
      fHandles[ "isSegmentTaggedMuon" ] = &isSegmentTaggedMuon;
      fHandles[ "isCaloMuonId" ] = &isCaloMuonId;
// -- slimmed --       fHandles[ "alsoFoundByLowPt" ] = &alsoFoundByLowPt;
// -- slimmed --       fHandles[ "alsoFoundByCaloMuonId" ] = &alsoFoundByCaloMuonId;
// -- slimmed --       fHandles[ "isSiliconAssociatedForwardMuon" ] = &isSiliconAssociatedForwardMuon;
      fHandles[ "loose" ] = &loose;
      fHandles[ "medium" ] = &medium;
      fHandles[ "tight" ] = &tight;
      fHandles[ "d0_exPV" ] = &d0_exPV;
      fHandles[ "z0_exPV" ] = &z0_exPV;
      fHandles[ "phi_exPV" ] = &phi_exPV;
      fHandles[ "theta_exPV" ] = &theta_exPV;
      fHandles[ "qoverp_exPV" ] = &qoverp_exPV;
      fHandles[ "cb_d0_exPV" ] = &cb_d0_exPV;
      fHandles[ "cb_z0_exPV" ] = &cb_z0_exPV;
      fHandles[ "cb_phi_exPV" ] = &cb_phi_exPV;
      fHandles[ "cb_theta_exPV" ] = &cb_theta_exPV;
      fHandles[ "cb_qoverp_exPV" ] = &cb_qoverp_exPV;
      fHandles[ "id_d0_exPV" ] = &id_d0_exPV;
      fHandles[ "id_z0_exPV" ] = &id_z0_exPV;
      fHandles[ "id_phi_exPV" ] = &id_phi_exPV;
      fHandles[ "id_theta_exPV" ] = &id_theta_exPV;
      fHandles[ "id_qoverp_exPV" ] = &id_qoverp_exPV;
      fHandles[ "me_d0_exPV" ] = &me_d0_exPV;
      fHandles[ "me_z0_exPV" ] = &me_z0_exPV;
      fHandles[ "me_phi_exPV" ] = &me_phi_exPV;
      fHandles[ "me_theta_exPV" ] = &me_theta_exPV;
      fHandles[ "me_qoverp_exPV" ] = &me_qoverp_exPV;
      fHandles[ "ie_d0_exPV" ] = &ie_d0_exPV;
      fHandles[ "ie_z0_exPV" ] = &ie_z0_exPV;
      fHandles[ "ie_phi_exPV" ] = &ie_phi_exPV;
      fHandles[ "ie_theta_exPV" ] = &ie_theta_exPV;
      fHandles[ "ie_qoverp_exPV" ] = &ie_qoverp_exPV;
      fHandles[ "cov_d0_exPV" ] = &cov_d0_exPV;
      fHandles[ "cov_z0_exPV" ] = &cov_z0_exPV;
      fHandles[ "cov_phi_exPV" ] = &cov_phi_exPV;
      fHandles[ "cov_theta_exPV" ] = &cov_theta_exPV;
      fHandles[ "cov_qoverp_exPV" ] = &cov_qoverp_exPV;
      fHandles[ "cov_d0_z0_exPV" ] = &cov_d0_z0_exPV;
      fHandles[ "cov_d0_phi_exPV" ] = &cov_d0_phi_exPV;
      fHandles[ "cov_d0_theta_exPV" ] = &cov_d0_theta_exPV;
      fHandles[ "cov_d0_qoverp_exPV" ] = &cov_d0_qoverp_exPV;
      fHandles[ "cov_z0_phi_exPV" ] = &cov_z0_phi_exPV;
      fHandles[ "cov_z0_theta_exPV" ] = &cov_z0_theta_exPV;
      fHandles[ "cov_z0_qoverp_exPV" ] = &cov_z0_qoverp_exPV;
      fHandles[ "cov_phi_theta_exPV" ] = &cov_phi_theta_exPV;
      fHandles[ "cov_phi_qoverp_exPV" ] = &cov_phi_qoverp_exPV;
      fHandles[ "cov_theta_qoverp_exPV" ] = &cov_theta_qoverp_exPV;
      fHandles[ "id_cov_d0_exPV" ] = &id_cov_d0_exPV;
      fHandles[ "id_cov_z0_exPV" ] = &id_cov_z0_exPV;
      fHandles[ "id_cov_phi_exPV" ] = &id_cov_phi_exPV;
      fHandles[ "id_cov_theta_exPV" ] = &id_cov_theta_exPV;
      fHandles[ "id_cov_qoverp_exPV" ] = &id_cov_qoverp_exPV;
      fHandles[ "id_cov_d0_z0_exPV" ] = &id_cov_d0_z0_exPV;
      fHandles[ "id_cov_d0_phi_exPV" ] = &id_cov_d0_phi_exPV;
      fHandles[ "id_cov_d0_theta_exPV" ] = &id_cov_d0_theta_exPV;
      fHandles[ "id_cov_d0_qoverp_exPV" ] = &id_cov_d0_qoverp_exPV;
      fHandles[ "id_cov_z0_phi_exPV" ] = &id_cov_z0_phi_exPV;
      fHandles[ "id_cov_z0_theta_exPV" ] = &id_cov_z0_theta_exPV;
      fHandles[ "id_cov_z0_qoverp_exPV" ] = &id_cov_z0_qoverp_exPV;
      fHandles[ "id_cov_phi_theta_exPV" ] = &id_cov_phi_theta_exPV;
      fHandles[ "id_cov_phi_qoverp_exPV" ] = &id_cov_phi_qoverp_exPV;
      fHandles[ "id_cov_theta_qoverp_exPV" ] = &id_cov_theta_qoverp_exPV;
      fHandles[ "me_cov_d0_exPV" ] = &me_cov_d0_exPV;
      fHandles[ "me_cov_z0_exPV" ] = &me_cov_z0_exPV;
      fHandles[ "me_cov_phi_exPV" ] = &me_cov_phi_exPV;
      fHandles[ "me_cov_theta_exPV" ] = &me_cov_theta_exPV;
      fHandles[ "me_cov_qoverp_exPV" ] = &me_cov_qoverp_exPV;
      fHandles[ "ms_d0" ] = &ms_d0;
      fHandles[ "ms_z0" ] = &ms_z0;
      fHandles[ "ms_phi" ] = &ms_phi;
      fHandles[ "ms_theta" ] = &ms_theta;
      fHandles[ "ms_qoverp" ] = &ms_qoverp;
      fHandles[ "id_d0" ] = &id_d0;
      fHandles[ "id_z0" ] = &id_z0;
      fHandles[ "id_phi" ] = &id_phi;
      fHandles[ "id_theta" ] = &id_theta;
      fHandles[ "id_qoverp" ] = &id_qoverp;
      fHandles[ "me_d0" ] = &me_d0;
      fHandles[ "me_z0" ] = &me_z0;
      fHandles[ "me_phi" ] = &me_phi;
      fHandles[ "me_theta" ] = &me_theta;
      fHandles[ "me_qoverp" ] = &me_qoverp;
      fHandles[ "ie_d0" ] = &ie_d0;
      fHandles[ "ie_z0" ] = &ie_z0;
      fHandles[ "ie_phi" ] = &ie_phi;
      fHandles[ "ie_theta" ] = &ie_theta;
      fHandles[ "ie_qoverp" ] = &ie_qoverp;
      fHandles[ "nOutliersOnTrack" ] = &nOutliersOnTrack;
      fHandles[ "nBLHits" ] = &nBLHits;
      fHandles[ "nPixHits" ] = &nPixHits;
      fHandles[ "nSCTHits" ] = &nSCTHits;
      fHandles[ "nTRTHits" ] = &nTRTHits;
      fHandles[ "nTRTHighTHits" ] = &nTRTHighTHits;
      fHandles[ "nBLSharedHits" ] = &nBLSharedHits;
      fHandles[ "nPixSharedHits" ] = &nPixSharedHits;
      fHandles[ "nPixHoles" ] = &nPixHoles;
      fHandles[ "nSCTSharedHits" ] = &nSCTSharedHits;
      fHandles[ "nSCTHoles" ] = &nSCTHoles;
      fHandles[ "nTRTOutliers" ] = &nTRTOutliers;
      fHandles[ "nTRTHighTOutliers" ] = &nTRTHighTOutliers;
      fHandles[ "nGangedPixels" ] = &nGangedPixels;
      fHandles[ "nPixelDeadSensors" ] = &nPixelDeadSensors;
      fHandles[ "nSCTDeadSensors" ] = &nSCTDeadSensors;
      fHandles[ "nTRTDeadStraws" ] = &nTRTDeadStraws;
      fHandles[ "expectBLayerHit" ] = &expectBLayerHit;
      fHandles[ "nMDTHits" ] = &nMDTHits;
// -- slimmed --       fHandles[ "nMDTHoles" ] = &nMDTHoles;
      fHandles[ "nCSCEtaHits" ] = &nCSCEtaHits;
// -- slimmed --       fHandles[ "nCSCEtaHoles" ] = &nCSCEtaHoles;
      fHandles[ "nCSCUnspoiledEtaHits" ] = &nCSCUnspoiledEtaHits;
      fHandles[ "nCSCPhiHits" ] = &nCSCPhiHits;
// -- slimmed --       fHandles[ "nCSCPhiHoles" ] = &nCSCPhiHoles;
      fHandles[ "nRPCEtaHits" ] = &nRPCEtaHits;
// -- slimmed --       fHandles[ "nRPCEtaHoles" ] = &nRPCEtaHoles;
      fHandles[ "nRPCPhiHits" ] = &nRPCPhiHits;
// -- slimmed --       fHandles[ "nRPCPhiHoles" ] = &nRPCPhiHoles;
      fHandles[ "nTGCEtaHits" ] = &nTGCEtaHits;
// -- slimmed --       fHandles[ "nTGCEtaHoles" ] = &nTGCEtaHoles;
      fHandles[ "nTGCPhiHits" ] = &nTGCPhiHits;
// -- slimmed --       fHandles[ "nTGCPhiHoles" ] = &nTGCPhiHoles;
      fHandles[ "nprecisionLayers" ] = &nprecisionLayers;
      fHandles[ "nprecisionHoleLayers" ] = &nprecisionHoleLayers;
      fHandles[ "nphiLayers" ] = &nphiLayers;
      fHandles[ "ntrigEtaLayers" ] = &ntrigEtaLayers;
      fHandles[ "nphiHoleLayers" ] = &nphiHoleLayers;
      fHandles[ "ntrigEtaHoleLayers" ] = &ntrigEtaHoleLayers;
      fHandles[ "nMDTBIHits" ] = &nMDTBIHits;
      fHandles[ "nMDTBMHits" ] = &nMDTBMHits;
      fHandles[ "nMDTBOHits" ] = &nMDTBOHits;
      fHandles[ "nMDTBEEHits" ] = &nMDTBEEHits;
      fHandles[ "nMDTBIS78Hits" ] = &nMDTBIS78Hits;
      fHandles[ "nMDTEIHits" ] = &nMDTEIHits;
      fHandles[ "nMDTEMHits" ] = &nMDTEMHits;
      fHandles[ "nMDTEOHits" ] = &nMDTEOHits;
      fHandles[ "nMDTEEHits" ] = &nMDTEEHits;
// -- slimmed --       fHandles[ "nRPCLayer1EtaHits" ] = &nRPCLayer1EtaHits;
// -- slimmed --       fHandles[ "nRPCLayer2EtaHits" ] = &nRPCLayer2EtaHits;
// -- slimmed --       fHandles[ "nRPCLayer3EtaHits" ] = &nRPCLayer3EtaHits;
// -- slimmed --       fHandles[ "nRPCLayer1PhiHits" ] = &nRPCLayer1PhiHits;
// -- slimmed --       fHandles[ "nRPCLayer2PhiHits" ] = &nRPCLayer2PhiHits;
// -- slimmed --       fHandles[ "nRPCLayer3PhiHits" ] = &nRPCLayer3PhiHits;
// -- slimmed --       fHandles[ "nTGCLayer1EtaHits" ] = &nTGCLayer1EtaHits;
// -- slimmed --       fHandles[ "nTGCLayer2EtaHits" ] = &nTGCLayer2EtaHits;
// -- slimmed --       fHandles[ "nTGCLayer3EtaHits" ] = &nTGCLayer3EtaHits;
// -- slimmed --       fHandles[ "nTGCLayer4EtaHits" ] = &nTGCLayer4EtaHits;
// -- slimmed --       fHandles[ "nTGCLayer1PhiHits" ] = &nTGCLayer1PhiHits;
// -- slimmed --       fHandles[ "nTGCLayer2PhiHits" ] = &nTGCLayer2PhiHits;
// -- slimmed --       fHandles[ "nTGCLayer3PhiHits" ] = &nTGCLayer3PhiHits;
// -- slimmed --       fHandles[ "nTGCLayer4PhiHits" ] = &nTGCLayer4PhiHits;
// -- slimmed --       fHandles[ "barrelSectors" ] = &barrelSectors;
// -- slimmed --       fHandles[ "endcapSectors" ] = &endcapSectors;
      fHandles[ "trackd0" ] = &trackd0;
      fHandles[ "trackz0" ] = &trackz0;
      fHandles[ "trackphi" ] = &trackphi;
      fHandles[ "tracktheta" ] = &tracktheta;
      fHandles[ "trackqoverp" ] = &trackqoverp;
      fHandles[ "trackcov_d0" ] = &trackcov_d0;
      fHandles[ "trackcov_z0" ] = &trackcov_z0;
      fHandles[ "trackcov_phi" ] = &trackcov_phi;
      fHandles[ "trackcov_theta" ] = &trackcov_theta;
      fHandles[ "trackcov_qoverp" ] = &trackcov_qoverp;
      fHandles[ "trackcov_d0_z0" ] = &trackcov_d0_z0;
      fHandles[ "trackcov_d0_phi" ] = &trackcov_d0_phi;
      fHandles[ "trackcov_d0_theta" ] = &trackcov_d0_theta;
      fHandles[ "trackcov_d0_qoverp" ] = &trackcov_d0_qoverp;
      fHandles[ "trackcov_z0_phi" ] = &trackcov_z0_phi;
      fHandles[ "trackcov_z0_theta" ] = &trackcov_z0_theta;
      fHandles[ "trackcov_z0_qoverp" ] = &trackcov_z0_qoverp;
      fHandles[ "trackcov_phi_theta" ] = &trackcov_phi_theta;
      fHandles[ "trackcov_phi_qoverp" ] = &trackcov_phi_qoverp;
      fHandles[ "trackcov_theta_qoverp" ] = &trackcov_theta_qoverp;
      fHandles[ "hastrack" ] = &hastrack;
// -- slimmed --       fHandles[ "trackIPEstimate_d0_biasedpvunbiased" ] = &trackIPEstimate_d0_biasedpvunbiased;
// -- slimmed --       fHandles[ "trackIPEstimate_z0_biasedpvunbiased" ] = &trackIPEstimate_z0_biasedpvunbiased;
// -- slimmed --       fHandles[ "trackIPEstimate_sigd0_biasedpvunbiased" ] = &trackIPEstimate_sigd0_biasedpvunbiased;
// -- slimmed --       fHandles[ "trackIPEstimate_sigz0_biasedpvunbiased" ] = &trackIPEstimate_sigz0_biasedpvunbiased;
// -- slimmed --       fHandles[ "trackIPEstimate_d0_unbiasedpvunbiased" ] = &trackIPEstimate_d0_unbiasedpvunbiased;
// -- slimmed --       fHandles[ "trackIPEstimate_z0_unbiasedpvunbiased" ] = &trackIPEstimate_z0_unbiasedpvunbiased;
// -- slimmed --       fHandles[ "trackIPEstimate_sigd0_unbiasedpvunbiased" ] = &trackIPEstimate_sigd0_unbiasedpvunbiased;
// -- slimmed --       fHandles[ "trackIPEstimate_sigz0_unbiasedpvunbiased" ] = &trackIPEstimate_sigz0_unbiasedpvunbiased;
if (!is_data) {
      fHandles[ "type" ] = &type;
      fHandles[ "origin" ] = &origin;
      fHandles[ "truth_dr" ] = &truth_dr;
      fHandles[ "truth_E" ] = &truth_E;
      fHandles[ "truth_pt" ] = &truth_pt;
      fHandles[ "truth_eta" ] = &truth_eta;
      fHandles[ "truth_phi" ] = &truth_phi;
      fHandles[ "truth_type" ] = &truth_type;
      fHandles[ "truth_status" ] = &truth_status;
      fHandles[ "truth_barcode" ] = &truth_barcode;
      fHandles[ "truth_mothertype" ] = &truth_mothertype;
      fHandles[ "truth_motherbarcode" ] = &truth_motherbarcode;
      fHandles[ "truth_matched" ] = &truth_matched;
} // end !is_data
      fHandles[ "EFCB_index" ] = &EFCB_index;
      fHandles[ "EFMG_index" ] = &EFMG_index;
      fHandles[ "EFME_index" ] = &EFME_index;
      fHandles[ "ptcone20_trk500MeV" ] = &ptcone20_trk500MeV;
      fHandles[ "ptcone30_trk500MeV" ] = &ptcone30_trk500MeV;
      fHandles[ "ptcone40_trk500MeV" ] = &ptcone40_trk500MeV;
      fHandles[ "nucone20_trk500MeV" ] = &nucone20_trk500MeV;
      fHandles[ "nucone30_trk500MeV" ] = &nucone30_trk500MeV;
      fHandles[ "nucone40_trk500MeV" ] = &nucone40_trk500MeV;
      fHandles[ "ptcone20_trkelstyle" ] = &ptcone20_trkelstyle;
      fHandles[ "ptcone30_trkelstyle" ] = &ptcone30_trkelstyle;
      fHandles[ "ptcone40_trkelstyle" ] = &ptcone40_trkelstyle;
      fHandles[ "nucone20_trkelstyle" ] = &nucone20_trkelstyle;
      fHandles[ "nucone30_trkelstyle" ] = &nucone30_trkelstyle;
      fHandles[ "nucone40_trkelstyle" ] = &nucone40_trkelstyle;
// -- slimmed --       fHandles[ "MET_Simplified20_wpx" ] = &MET_Simplified20_wpx;
// -- slimmed --       fHandles[ "MET_Simplified20_wpy" ] = &MET_Simplified20_wpy;
// -- slimmed --       fHandles[ "MET_Simplified20_wet" ] = &MET_Simplified20_wet;
// -- slimmed --       fHandles[ "MET_Simplified20_statusWord" ] = &MET_Simplified20_statusWord;
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
// -- slimmed -- // -- slimmed --       fHandles[ "MET_STVF_statusWord" ] = &MET_STVF_statusWord;
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   MuonD3PDObject::MuonD3PDObject( const char* prefix , bool is_data )
      : TObject(),
        n( this, ::TString( prefix ) + "n", 0 ),
        E( this, ::TString( prefix ) + "E", 0 ),
        pt( this, ::TString( prefix ) + "pt", 0 ),
        m( this, ::TString( prefix ) + "m", 0 ),
        eta( this, ::TString( prefix ) + "eta", 0 ),
        phi( this, ::TString( prefix ) + "phi", 0 ),
        px( this, ::TString( prefix ) + "px", 0 ),
        py( this, ::TString( prefix ) + "py", 0 ),
        pz( this, ::TString( prefix ) + "pz", 0 ),
        charge( this, ::TString( prefix ) + "charge", 0 ),
        allauthor( this, ::TString( prefix ) + "allauthor", 0 ),
        author( this, ::TString( prefix ) + "author", 0 ),
        matchchi2( this, ::TString( prefix ) + "matchchi2", 0 ),
        matchndof( this, ::TString( prefix ) + "matchndof", 0 ),
        etcone20( this, ::TString( prefix ) + "etcone20", 0 ),
        etcone30( this, ::TString( prefix ) + "etcone30", 0 ),
        etcone40( this, ::TString( prefix ) + "etcone40", 0 ),
        nucone20( this, ::TString( prefix ) + "nucone20", 0 ),
        nucone30( this, ::TString( prefix ) + "nucone30", 0 ),
        nucone40( this, ::TString( prefix ) + "nucone40", 0 ),
        ptcone20( this, ::TString( prefix ) + "ptcone20", 0 ),
        ptcone30( this, ::TString( prefix ) + "ptcone30", 0 ),
        ptcone40( this, ::TString( prefix ) + "ptcone40", 0 ),
// -- slimmed --         etconeNoEm10( this, ::TString( prefix ) + "etconeNoEm10", 0 ),
// -- slimmed --         etconeNoEm20( this, ::TString( prefix ) + "etconeNoEm20", 0 ),
// -- slimmed --         etconeNoEm30( this, ::TString( prefix ) + "etconeNoEm30", 0 ),
// -- slimmed --         etconeNoEm40( this, ::TString( prefix ) + "etconeNoEm40", 0 ),
// -- slimmed --         scatteringCurvatureSignificance( this, ::TString( prefix ) + "scatteringCurvatureSignificance", 0 ),
// -- slimmed --         scatteringNeighbourSignificance( this, ::TString( prefix ) + "scatteringNeighbourSignificance", 0 ),
// -- slimmed --         momentumBalanceSignificance( this, ::TString( prefix ) + "momentumBalanceSignificance", 0 ),
        energyLossPar( this, ::TString( prefix ) + "energyLossPar", 0 ),
        energyLossErr( this, ::TString( prefix ) + "energyLossErr", 0 ),
        etCore( this, ::TString( prefix ) + "etCore", 0 ),
        energyLossType( this, ::TString( prefix ) + "energyLossType", 0 ),
        caloMuonIdTag( this, ::TString( prefix ) + "caloMuonIdTag", 0 ),
        caloLRLikelihood( this, ::TString( prefix ) + "caloLRLikelihood", 0 ),
        bestMatch( this, ::TString( prefix ) + "bestMatch", 0 ),
        isStandAloneMuon( this, ::TString( prefix ) + "isStandAloneMuon", 0 ),
        isCombinedMuon( this, ::TString( prefix ) + "isCombinedMuon", 0 ),
        isLowPtReconstructedMuon( this, ::TString( prefix ) + "isLowPtReconstructedMuon", 0 ),
        isSegmentTaggedMuon( this, ::TString( prefix ) + "isSegmentTaggedMuon", 0 ),
        isCaloMuonId( this, ::TString( prefix ) + "isCaloMuonId", 0 ),
// -- slimmed --         alsoFoundByLowPt( this, ::TString( prefix ) + "alsoFoundByLowPt", 0 ),
// -- slimmed --         alsoFoundByCaloMuonId( this, ::TString( prefix ) + "alsoFoundByCaloMuonId", 0 ),
// -- slimmed --         isSiliconAssociatedForwardMuon( this, ::TString( prefix ) + "isSiliconAssociatedForwardMuon", 0 ),
        loose( this, ::TString( prefix ) + "loose", 0 ),
        medium( this, ::TString( prefix ) + "medium", 0 ),
        tight( this, ::TString( prefix ) + "tight", 0 ),
        d0_exPV( this, ::TString( prefix ) + "d0_exPV", 0 ),
        z0_exPV( this, ::TString( prefix ) + "z0_exPV", 0 ),
        phi_exPV( this, ::TString( prefix ) + "phi_exPV", 0 ),
        theta_exPV( this, ::TString( prefix ) + "theta_exPV", 0 ),
        qoverp_exPV( this, ::TString( prefix ) + "qoverp_exPV", 0 ),
        cb_d0_exPV( this, ::TString( prefix ) + "cb_d0_exPV", 0 ),
        cb_z0_exPV( this, ::TString( prefix ) + "cb_z0_exPV", 0 ),
        cb_phi_exPV( this, ::TString( prefix ) + "cb_phi_exPV", 0 ),
        cb_theta_exPV( this, ::TString( prefix ) + "cb_theta_exPV", 0 ),
        cb_qoverp_exPV( this, ::TString( prefix ) + "cb_qoverp_exPV", 0 ),
        id_d0_exPV( this, ::TString( prefix ) + "id_d0_exPV", 0 ),
        id_z0_exPV( this, ::TString( prefix ) + "id_z0_exPV", 0 ),
        id_phi_exPV( this, ::TString( prefix ) + "id_phi_exPV", 0 ),
        id_theta_exPV( this, ::TString( prefix ) + "id_theta_exPV", 0 ),
        id_qoverp_exPV( this, ::TString( prefix ) + "id_qoverp_exPV", 0 ),
        me_d0_exPV( this, ::TString( prefix ) + "me_d0_exPV", 0 ),
        me_z0_exPV( this, ::TString( prefix ) + "me_z0_exPV", 0 ),
        me_phi_exPV( this, ::TString( prefix ) + "me_phi_exPV", 0 ),
        me_theta_exPV( this, ::TString( prefix ) + "me_theta_exPV", 0 ),
        me_qoverp_exPV( this, ::TString( prefix ) + "me_qoverp_exPV", 0 ),
        ie_d0_exPV( this, ::TString( prefix ) + "ie_d0_exPV", 0 ),
        ie_z0_exPV( this, ::TString( prefix ) + "ie_z0_exPV", 0 ),
        ie_phi_exPV( this, ::TString( prefix ) + "ie_phi_exPV", 0 ),
        ie_theta_exPV( this, ::TString( prefix ) + "ie_theta_exPV", 0 ),
        ie_qoverp_exPV( this, ::TString( prefix ) + "ie_qoverp_exPV", 0 ),
        cov_d0_exPV( this, ::TString( prefix ) + "cov_d0_exPV", 0 ),
        cov_z0_exPV( this, ::TString( prefix ) + "cov_z0_exPV", 0 ),
        cov_phi_exPV( this, ::TString( prefix ) + "cov_phi_exPV", 0 ),
        cov_theta_exPV( this, ::TString( prefix ) + "cov_theta_exPV", 0 ),
        cov_qoverp_exPV( this, ::TString( prefix ) + "cov_qoverp_exPV", 0 ),
        cov_d0_z0_exPV( this, ::TString( prefix ) + "cov_d0_z0_exPV", 0 ),
        cov_d0_phi_exPV( this, ::TString( prefix ) + "cov_d0_phi_exPV", 0 ),
        cov_d0_theta_exPV( this, ::TString( prefix ) + "cov_d0_theta_exPV", 0 ),
        cov_d0_qoverp_exPV( this, ::TString( prefix ) + "cov_d0_qoverp_exPV", 0 ),
        cov_z0_phi_exPV( this, ::TString( prefix ) + "cov_z0_phi_exPV", 0 ),
        cov_z0_theta_exPV( this, ::TString( prefix ) + "cov_z0_theta_exPV", 0 ),
        cov_z0_qoverp_exPV( this, ::TString( prefix ) + "cov_z0_qoverp_exPV", 0 ),
        cov_phi_theta_exPV( this, ::TString( prefix ) + "cov_phi_theta_exPV", 0 ),
        cov_phi_qoverp_exPV( this, ::TString( prefix ) + "cov_phi_qoverp_exPV", 0 ),
        cov_theta_qoverp_exPV( this, ::TString( prefix ) + "cov_theta_qoverp_exPV", 0 ),
        id_cov_d0_exPV( this, ::TString( prefix ) + "id_cov_d0_exPV", 0 ),
        id_cov_z0_exPV( this, ::TString( prefix ) + "id_cov_z0_exPV", 0 ),
        id_cov_phi_exPV( this, ::TString( prefix ) + "id_cov_phi_exPV", 0 ),
        id_cov_theta_exPV( this, ::TString( prefix ) + "id_cov_theta_exPV", 0 ),
        id_cov_qoverp_exPV( this, ::TString( prefix ) + "id_cov_qoverp_exPV", 0 ),
        id_cov_d0_z0_exPV( this, ::TString( prefix ) + "id_cov_d0_z0_exPV", 0 ),
        id_cov_d0_phi_exPV( this, ::TString( prefix ) + "id_cov_d0_phi_exPV", 0 ),
        id_cov_d0_theta_exPV( this, ::TString( prefix ) + "id_cov_d0_theta_exPV", 0 ),
        id_cov_d0_qoverp_exPV( this, ::TString( prefix ) + "id_cov_d0_qoverp_exPV", 0 ),
        id_cov_z0_phi_exPV( this, ::TString( prefix ) + "id_cov_z0_phi_exPV", 0 ),
        id_cov_z0_theta_exPV( this, ::TString( prefix ) + "id_cov_z0_theta_exPV", 0 ),
        id_cov_z0_qoverp_exPV( this, ::TString( prefix ) + "id_cov_z0_qoverp_exPV", 0 ),
        id_cov_phi_theta_exPV( this, ::TString( prefix ) + "id_cov_phi_theta_exPV", 0 ),
        id_cov_phi_qoverp_exPV( this, ::TString( prefix ) + "id_cov_phi_qoverp_exPV", 0 ),
        id_cov_theta_qoverp_exPV( this, ::TString( prefix ) + "id_cov_theta_qoverp_exPV", 0 ),
        me_cov_d0_exPV( this, ::TString( prefix ) + "me_cov_d0_exPV", 0 ),
        me_cov_z0_exPV( this, ::TString( prefix ) + "me_cov_z0_exPV", 0 ),
        me_cov_phi_exPV( this, ::TString( prefix ) + "me_cov_phi_exPV", 0 ),
        me_cov_theta_exPV( this, ::TString( prefix ) + "me_cov_theta_exPV", 0 ),
        me_cov_qoverp_exPV( this, ::TString( prefix ) + "me_cov_qoverp_exPV", 0 ),
        ms_d0( this, ::TString( prefix ) + "ms_d0", 0 ),
        ms_z0( this, ::TString( prefix ) + "ms_z0", 0 ),
        ms_phi( this, ::TString( prefix ) + "ms_phi", 0 ),
        ms_theta( this, ::TString( prefix ) + "ms_theta", 0 ),
        ms_qoverp( this, ::TString( prefix ) + "ms_qoverp", 0 ),
        id_d0( this, ::TString( prefix ) + "id_d0", 0 ),
        id_z0( this, ::TString( prefix ) + "id_z0", 0 ),
        id_phi( this, ::TString( prefix ) + "id_phi", 0 ),
        id_theta( this, ::TString( prefix ) + "id_theta", 0 ),
        id_qoverp( this, ::TString( prefix ) + "id_qoverp", 0 ),
        me_d0( this, ::TString( prefix ) + "me_d0", 0 ),
        me_z0( this, ::TString( prefix ) + "me_z0", 0 ),
        me_phi( this, ::TString( prefix ) + "me_phi", 0 ),
        me_theta( this, ::TString( prefix ) + "me_theta", 0 ),
        me_qoverp( this, ::TString( prefix ) + "me_qoverp", 0 ),
        ie_d0( this, ::TString( prefix ) + "ie_d0", 0 ),
        ie_z0( this, ::TString( prefix ) + "ie_z0", 0 ),
        ie_phi( this, ::TString( prefix ) + "ie_phi", 0 ),
        ie_theta( this, ::TString( prefix ) + "ie_theta", 0 ),
        ie_qoverp( this, ::TString( prefix ) + "ie_qoverp", 0 ),
        nOutliersOnTrack( this, ::TString( prefix ) + "nOutliersOnTrack", 0 ),
        nBLHits( this, ::TString( prefix ) + "nBLHits", 0 ),
        nPixHits( this, ::TString( prefix ) + "nPixHits", 0 ),
        nSCTHits( this, ::TString( prefix ) + "nSCTHits", 0 ),
        nTRTHits( this, ::TString( prefix ) + "nTRTHits", 0 ),
        nTRTHighTHits( this, ::TString( prefix ) + "nTRTHighTHits", 0 ),
        nBLSharedHits( this, ::TString( prefix ) + "nBLSharedHits", 0 ),
        nPixSharedHits( this, ::TString( prefix ) + "nPixSharedHits", 0 ),
        nPixHoles( this, ::TString( prefix ) + "nPixHoles", 0 ),
        nSCTSharedHits( this, ::TString( prefix ) + "nSCTSharedHits", 0 ),
        nSCTHoles( this, ::TString( prefix ) + "nSCTHoles", 0 ),
        nTRTOutliers( this, ::TString( prefix ) + "nTRTOutliers", 0 ),
        nTRTHighTOutliers( this, ::TString( prefix ) + "nTRTHighTOutliers", 0 ),
        nGangedPixels( this, ::TString( prefix ) + "nGangedPixels", 0 ),
        nPixelDeadSensors( this, ::TString( prefix ) + "nPixelDeadSensors", 0 ),
        nSCTDeadSensors( this, ::TString( prefix ) + "nSCTDeadSensors", 0 ),
        nTRTDeadStraws( this, ::TString( prefix ) + "nTRTDeadStraws", 0 ),
        expectBLayerHit( this, ::TString( prefix ) + "expectBLayerHit", 0 ),
        nMDTHits( this, ::TString( prefix ) + "nMDTHits", 0 ),
// -- slimmed --         nMDTHoles( this, ::TString( prefix ) + "nMDTHoles", 0 ),
        nCSCEtaHits( this, ::TString( prefix ) + "nCSCEtaHits", 0 ),
// -- slimmed --         nCSCEtaHoles( this, ::TString( prefix ) + "nCSCEtaHoles", 0 ),
        nCSCUnspoiledEtaHits( this, ::TString( prefix ) + "nCSCUnspoiledEtaHits", 0 ),
        nCSCPhiHits( this, ::TString( prefix ) + "nCSCPhiHits", 0 ),
// -- slimmed --         nCSCPhiHoles( this, ::TString( prefix ) + "nCSCPhiHoles", 0 ),
        nRPCEtaHits( this, ::TString( prefix ) + "nRPCEtaHits", 0 ),
// -- slimmed --         nRPCEtaHoles( this, ::TString( prefix ) + "nRPCEtaHoles", 0 ),
        nRPCPhiHits( this, ::TString( prefix ) + "nRPCPhiHits", 0 ),
// -- slimmed --         nRPCPhiHoles( this, ::TString( prefix ) + "nRPCPhiHoles", 0 ),
        nTGCEtaHits( this, ::TString( prefix ) + "nTGCEtaHits", 0 ),
// -- slimmed --         nTGCEtaHoles( this, ::TString( prefix ) + "nTGCEtaHoles", 0 ),
        nTGCPhiHits( this, ::TString( prefix ) + "nTGCPhiHits", 0 ),
// -- slimmed --         nTGCPhiHoles( this, ::TString( prefix ) + "nTGCPhiHoles", 0 ),
        nprecisionLayers( this, ::TString( prefix ) + "nprecisionLayers", 0 ),
        nprecisionHoleLayers( this, ::TString( prefix ) + "nprecisionHoleLayers", 0 ),
        nphiLayers( this, ::TString( prefix ) + "nphiLayers", 0 ),
        ntrigEtaLayers( this, ::TString( prefix ) + "ntrigEtaLayers", 0 ),
        nphiHoleLayers( this, ::TString( prefix ) + "nphiHoleLayers", 0 ),
        ntrigEtaHoleLayers( this, ::TString( prefix ) + "ntrigEtaHoleLayers", 0 ),
        nMDTBIHits( this, ::TString( prefix ) + "nMDTBIHits", 0 ),
        nMDTBMHits( this, ::TString( prefix ) + "nMDTBMHits", 0 ),
        nMDTBOHits( this, ::TString( prefix ) + "nMDTBOHits", 0 ),
        nMDTBEEHits( this, ::TString( prefix ) + "nMDTBEEHits", 0 ),
        nMDTBIS78Hits( this, ::TString( prefix ) + "nMDTBIS78Hits", 0 ),
        nMDTEIHits( this, ::TString( prefix ) + "nMDTEIHits", 0 ),
        nMDTEMHits( this, ::TString( prefix ) + "nMDTEMHits", 0 ),
        nMDTEOHits( this, ::TString( prefix ) + "nMDTEOHits", 0 ),
        nMDTEEHits( this, ::TString( prefix ) + "nMDTEEHits", 0 ),
// -- slimmed --         nRPCLayer1EtaHits( this, ::TString( prefix ) + "nRPCLayer1EtaHits", 0 ),
// -- slimmed --         nRPCLayer2EtaHits( this, ::TString( prefix ) + "nRPCLayer2EtaHits", 0 ),
// -- slimmed --         nRPCLayer3EtaHits( this, ::TString( prefix ) + "nRPCLayer3EtaHits", 0 ),
// -- slimmed --         nRPCLayer1PhiHits( this, ::TString( prefix ) + "nRPCLayer1PhiHits", 0 ),
// -- slimmed --         nRPCLayer2PhiHits( this, ::TString( prefix ) + "nRPCLayer2PhiHits", 0 ),
// -- slimmed --         nRPCLayer3PhiHits( this, ::TString( prefix ) + "nRPCLayer3PhiHits", 0 ),
// -- slimmed --         nTGCLayer1EtaHits( this, ::TString( prefix ) + "nTGCLayer1EtaHits", 0 ),
// -- slimmed --         nTGCLayer2EtaHits( this, ::TString( prefix ) + "nTGCLayer2EtaHits", 0 ),
// -- slimmed --         nTGCLayer3EtaHits( this, ::TString( prefix ) + "nTGCLayer3EtaHits", 0 ),
// -- slimmed --         nTGCLayer4EtaHits( this, ::TString( prefix ) + "nTGCLayer4EtaHits", 0 ),
// -- slimmed --         nTGCLayer1PhiHits( this, ::TString( prefix ) + "nTGCLayer1PhiHits", 0 ),
// -- slimmed --         nTGCLayer2PhiHits( this, ::TString( prefix ) + "nTGCLayer2PhiHits", 0 ),
// -- slimmed --         nTGCLayer3PhiHits( this, ::TString( prefix ) + "nTGCLayer3PhiHits", 0 ),
// -- slimmed --         nTGCLayer4PhiHits( this, ::TString( prefix ) + "nTGCLayer4PhiHits", 0 ),
// -- slimmed --         barrelSectors( this, ::TString( prefix ) + "barrelSectors", 0 ),
// -- slimmed --         endcapSectors( this, ::TString( prefix ) + "endcapSectors", 0 ),
        trackd0( this, ::TString( prefix ) + "trackd0", 0 ),
        trackz0( this, ::TString( prefix ) + "trackz0", 0 ),
        trackphi( this, ::TString( prefix ) + "trackphi", 0 ),
        tracktheta( this, ::TString( prefix ) + "tracktheta", 0 ),
        trackqoverp( this, ::TString( prefix ) + "trackqoverp", 0 ),
        trackcov_d0( this, ::TString( prefix ) + "trackcov_d0", 0 ),
        trackcov_z0( this, ::TString( prefix ) + "trackcov_z0", 0 ),
        trackcov_phi( this, ::TString( prefix ) + "trackcov_phi", 0 ),
        trackcov_theta( this, ::TString( prefix ) + "trackcov_theta", 0 ),
        trackcov_qoverp( this, ::TString( prefix ) + "trackcov_qoverp", 0 ),
        trackcov_d0_z0( this, ::TString( prefix ) + "trackcov_d0_z0", 0 ),
        trackcov_d0_phi( this, ::TString( prefix ) + "trackcov_d0_phi", 0 ),
        trackcov_d0_theta( this, ::TString( prefix ) + "trackcov_d0_theta", 0 ),
        trackcov_d0_qoverp( this, ::TString( prefix ) + "trackcov_d0_qoverp", 0 ),
        trackcov_z0_phi( this, ::TString( prefix ) + "trackcov_z0_phi", 0 ),
        trackcov_z0_theta( this, ::TString( prefix ) + "trackcov_z0_theta", 0 ),
        trackcov_z0_qoverp( this, ::TString( prefix ) + "trackcov_z0_qoverp", 0 ),
        trackcov_phi_theta( this, ::TString( prefix ) + "trackcov_phi_theta", 0 ),
        trackcov_phi_qoverp( this, ::TString( prefix ) + "trackcov_phi_qoverp", 0 ),
        trackcov_theta_qoverp( this, ::TString( prefix ) + "trackcov_theta_qoverp", 0 ),
        hastrack( this, ::TString( prefix ) + "hastrack", 0 ),
// -- slimmed --         trackIPEstimate_d0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_d0_biasedpvunbiased", 0 ),
// -- slimmed --         trackIPEstimate_z0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_z0_biasedpvunbiased", 0 ),
// -- slimmed --         trackIPEstimate_sigd0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigd0_biasedpvunbiased", 0 ),
// -- slimmed --         trackIPEstimate_sigz0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigz0_biasedpvunbiased", 0 ),
// -- slimmed --         trackIPEstimate_d0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_d0_unbiasedpvunbiased", 0 ),
// -- slimmed --         trackIPEstimate_z0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_z0_unbiasedpvunbiased", 0 ),
// -- slimmed --         trackIPEstimate_sigd0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigd0_unbiasedpvunbiased", 0 ),
// -- slimmed --         trackIPEstimate_sigz0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigz0_unbiasedpvunbiased", 0 ),
// MC only
        type( this, ::TString( prefix ) + "type", 0 ),
        origin( this, ::TString( prefix ) + "origin", 0 ),
        truth_dr( this, ::TString( prefix ) + "truth_dr", 0 ),
        truth_E( this, ::TString( prefix ) + "truth_E", 0 ),
        truth_pt( this, ::TString( prefix ) + "truth_pt", 0 ),
        truth_eta( this, ::TString( prefix ) + "truth_eta", 0 ),
        truth_phi( this, ::TString( prefix ) + "truth_phi", 0 ),
        truth_type( this, ::TString( prefix ) + "truth_type", 0 ),
        truth_status( this, ::TString( prefix ) + "truth_status", 0 ),
        truth_barcode( this, ::TString( prefix ) + "truth_barcode", 0 ),
        truth_mothertype( this, ::TString( prefix ) + "truth_mothertype", 0 ),
        truth_motherbarcode( this, ::TString( prefix ) + "truth_motherbarcode", 0 ),
        truth_matched( this, ::TString( prefix ) + "truth_matched", 0 ),
// end MC only
        EFCB_index( this, ::TString( prefix ) + "EFCB_index", 0 ),
        EFMG_index( this, ::TString( prefix ) + "EFMG_index", 0 ),
        EFME_index( this, ::TString( prefix ) + "EFME_index", 0 ),
        ptcone20_trk500MeV( this, ::TString( prefix ) + "ptcone20_trk500MeV", 0 ),
        ptcone30_trk500MeV( this, ::TString( prefix ) + "ptcone30_trk500MeV", 0 ),
        ptcone40_trk500MeV( this, ::TString( prefix ) + "ptcone40_trk500MeV", 0 ),
        nucone20_trk500MeV( this, ::TString( prefix ) + "nucone20_trk500MeV", 0 ),
        nucone30_trk500MeV( this, ::TString( prefix ) + "nucone30_trk500MeV", 0 ),
        nucone40_trk500MeV( this, ::TString( prefix ) + "nucone40_trk500MeV", 0 ),
        ptcone20_trkelstyle( this, ::TString( prefix ) + "ptcone20_trkelstyle", 0 ),
        ptcone30_trkelstyle( this, ::TString( prefix ) + "ptcone30_trkelstyle", 0 ),
        ptcone40_trkelstyle( this, ::TString( prefix ) + "ptcone40_trkelstyle", 0 ),
        nucone20_trkelstyle( this, ::TString( prefix ) + "nucone20_trkelstyle", 0 ),
        nucone30_trkelstyle( this, ::TString( prefix ) + "nucone30_trkelstyle", 0 ),
        nucone40_trkelstyle( this, ::TString( prefix ) + "nucone40_trkelstyle", 0 ),
// -- slimmed --         MET_Simplified20_wpx( this, ::TString( prefix ) + "MET_Simplified20_wpx", 0 ),
// -- slimmed --         MET_Simplified20_wpy( this, ::TString( prefix ) + "MET_Simplified20_wpy", 0 ),
// -- slimmed --         MET_Simplified20_wet( this, ::TString( prefix ) + "MET_Simplified20_wet", 0 ),
// -- slimmed --         MET_Simplified20_statusWord( this, ::TString( prefix ) + "MET_Simplified20_statusWord", 0 ),
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
// -- slimmed -- // -- slimmed --         MET_STVF_statusWord( this, ::TString( prefix ) + "MET_STVF_statusWord", 0 ),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "n" ] = &n;
      fHandles[ "E" ] = &E;
      fHandles[ "pt" ] = &pt;
      fHandles[ "m" ] = &m;
      fHandles[ "eta" ] = &eta;
      fHandles[ "phi" ] = &phi;
      fHandles[ "px" ] = &px;
      fHandles[ "py" ] = &py;
      fHandles[ "pz" ] = &pz;
      fHandles[ "charge" ] = &charge;
      fHandles[ "allauthor" ] = &allauthor;
      fHandles[ "author" ] = &author;
      fHandles[ "matchchi2" ] = &matchchi2;
      fHandles[ "matchndof" ] = &matchndof;
      fHandles[ "etcone20" ] = &etcone20;
      fHandles[ "etcone30" ] = &etcone30;
      fHandles[ "etcone40" ] = &etcone40;
      fHandles[ "nucone20" ] = &nucone20;
      fHandles[ "nucone30" ] = &nucone30;
      fHandles[ "nucone40" ] = &nucone40;
      fHandles[ "ptcone20" ] = &ptcone20;
      fHandles[ "ptcone30" ] = &ptcone30;
      fHandles[ "ptcone40" ] = &ptcone40;
// -- slimmed --       fHandles[ "etconeNoEm10" ] = &etconeNoEm10;
// -- slimmed --       fHandles[ "etconeNoEm20" ] = &etconeNoEm20;
// -- slimmed --       fHandles[ "etconeNoEm30" ] = &etconeNoEm30;
// -- slimmed --       fHandles[ "etconeNoEm40" ] = &etconeNoEm40;
// -- slimmed --       fHandles[ "scatteringCurvatureSignificance" ] = &scatteringCurvatureSignificance;
// -- slimmed --       fHandles[ "scatteringNeighbourSignificance" ] = &scatteringNeighbourSignificance;
// -- slimmed --       fHandles[ "momentumBalanceSignificance" ] = &momentumBalanceSignificance;
      fHandles[ "energyLossPar" ] = &energyLossPar;
      fHandles[ "energyLossErr" ] = &energyLossErr;
      fHandles[ "etCore" ] = &etCore;
      fHandles[ "energyLossType" ] = &energyLossType;
      fHandles[ "caloMuonIdTag" ] = &caloMuonIdTag;
      fHandles[ "caloLRLikelihood" ] = &caloLRLikelihood;
      fHandles[ "bestMatch" ] = &bestMatch;
      fHandles[ "isStandAloneMuon" ] = &isStandAloneMuon;
      fHandles[ "isCombinedMuon" ] = &isCombinedMuon;
      fHandles[ "isLowPtReconstructedMuon" ] = &isLowPtReconstructedMuon;
      fHandles[ "isSegmentTaggedMuon" ] = &isSegmentTaggedMuon;
      fHandles[ "isCaloMuonId" ] = &isCaloMuonId;
// -- slimmed --       fHandles[ "alsoFoundByLowPt" ] = &alsoFoundByLowPt;
// -- slimmed --       fHandles[ "alsoFoundByCaloMuonId" ] = &alsoFoundByCaloMuonId;
// -- slimmed --       fHandles[ "isSiliconAssociatedForwardMuon" ] = &isSiliconAssociatedForwardMuon;
      fHandles[ "loose" ] = &loose;
      fHandles[ "medium" ] = &medium;
      fHandles[ "tight" ] = &tight;
      fHandles[ "d0_exPV" ] = &d0_exPV;
      fHandles[ "z0_exPV" ] = &z0_exPV;
      fHandles[ "phi_exPV" ] = &phi_exPV;
      fHandles[ "theta_exPV" ] = &theta_exPV;
      fHandles[ "qoverp_exPV" ] = &qoverp_exPV;
      fHandles[ "cb_d0_exPV" ] = &cb_d0_exPV;
      fHandles[ "cb_z0_exPV" ] = &cb_z0_exPV;
      fHandles[ "cb_phi_exPV" ] = &cb_phi_exPV;
      fHandles[ "cb_theta_exPV" ] = &cb_theta_exPV;
      fHandles[ "cb_qoverp_exPV" ] = &cb_qoverp_exPV;
      fHandles[ "id_d0_exPV" ] = &id_d0_exPV;
      fHandles[ "id_z0_exPV" ] = &id_z0_exPV;
      fHandles[ "id_phi_exPV" ] = &id_phi_exPV;
      fHandles[ "id_theta_exPV" ] = &id_theta_exPV;
      fHandles[ "id_qoverp_exPV" ] = &id_qoverp_exPV;
      fHandles[ "me_d0_exPV" ] = &me_d0_exPV;
      fHandles[ "me_z0_exPV" ] = &me_z0_exPV;
      fHandles[ "me_phi_exPV" ] = &me_phi_exPV;
      fHandles[ "me_theta_exPV" ] = &me_theta_exPV;
      fHandles[ "me_qoverp_exPV" ] = &me_qoverp_exPV;
      fHandles[ "ie_d0_exPV" ] = &ie_d0_exPV;
      fHandles[ "ie_z0_exPV" ] = &ie_z0_exPV;
      fHandles[ "ie_phi_exPV" ] = &ie_phi_exPV;
      fHandles[ "ie_theta_exPV" ] = &ie_theta_exPV;
      fHandles[ "ie_qoverp_exPV" ] = &ie_qoverp_exPV;
      fHandles[ "cov_d0_exPV" ] = &cov_d0_exPV;
      fHandles[ "cov_z0_exPV" ] = &cov_z0_exPV;
      fHandles[ "cov_phi_exPV" ] = &cov_phi_exPV;
      fHandles[ "cov_theta_exPV" ] = &cov_theta_exPV;
      fHandles[ "cov_qoverp_exPV" ] = &cov_qoverp_exPV;
      fHandles[ "cov_d0_z0_exPV" ] = &cov_d0_z0_exPV;
      fHandles[ "cov_d0_phi_exPV" ] = &cov_d0_phi_exPV;
      fHandles[ "cov_d0_theta_exPV" ] = &cov_d0_theta_exPV;
      fHandles[ "cov_d0_qoverp_exPV" ] = &cov_d0_qoverp_exPV;
      fHandles[ "cov_z0_phi_exPV" ] = &cov_z0_phi_exPV;
      fHandles[ "cov_z0_theta_exPV" ] = &cov_z0_theta_exPV;
      fHandles[ "cov_z0_qoverp_exPV" ] = &cov_z0_qoverp_exPV;
      fHandles[ "cov_phi_theta_exPV" ] = &cov_phi_theta_exPV;
      fHandles[ "cov_phi_qoverp_exPV" ] = &cov_phi_qoverp_exPV;
      fHandles[ "cov_theta_qoverp_exPV" ] = &cov_theta_qoverp_exPV;
      fHandles[ "id_cov_d0_exPV" ] = &id_cov_d0_exPV;
      fHandles[ "id_cov_z0_exPV" ] = &id_cov_z0_exPV;
      fHandles[ "id_cov_phi_exPV" ] = &id_cov_phi_exPV;
      fHandles[ "id_cov_theta_exPV" ] = &id_cov_theta_exPV;
      fHandles[ "id_cov_qoverp_exPV" ] = &id_cov_qoverp_exPV;
      fHandles[ "id_cov_d0_z0_exPV" ] = &id_cov_d0_z0_exPV;
      fHandles[ "id_cov_d0_phi_exPV" ] = &id_cov_d0_phi_exPV;
      fHandles[ "id_cov_d0_theta_exPV" ] = &id_cov_d0_theta_exPV;
      fHandles[ "id_cov_d0_qoverp_exPV" ] = &id_cov_d0_qoverp_exPV;
      fHandles[ "id_cov_z0_phi_exPV" ] = &id_cov_z0_phi_exPV;
      fHandles[ "id_cov_z0_theta_exPV" ] = &id_cov_z0_theta_exPV;
      fHandles[ "id_cov_z0_qoverp_exPV" ] = &id_cov_z0_qoverp_exPV;
      fHandles[ "id_cov_phi_theta_exPV" ] = &id_cov_phi_theta_exPV;
      fHandles[ "id_cov_phi_qoverp_exPV" ] = &id_cov_phi_qoverp_exPV;
      fHandles[ "id_cov_theta_qoverp_exPV" ] = &id_cov_theta_qoverp_exPV;
      fHandles[ "me_cov_d0_exPV" ] = &me_cov_d0_exPV;
      fHandles[ "me_cov_z0_exPV" ] = &me_cov_z0_exPV;
      fHandles[ "me_cov_phi_exPV" ] = &me_cov_phi_exPV;
      fHandles[ "me_cov_theta_exPV" ] = &me_cov_theta_exPV;
      fHandles[ "me_cov_qoverp_exPV" ] = &me_cov_qoverp_exPV;
      fHandles[ "ms_d0" ] = &ms_d0;
      fHandles[ "ms_z0" ] = &ms_z0;
      fHandles[ "ms_phi" ] = &ms_phi;
      fHandles[ "ms_theta" ] = &ms_theta;
      fHandles[ "ms_qoverp" ] = &ms_qoverp;
      fHandles[ "id_d0" ] = &id_d0;
      fHandles[ "id_z0" ] = &id_z0;
      fHandles[ "id_phi" ] = &id_phi;
      fHandles[ "id_theta" ] = &id_theta;
      fHandles[ "id_qoverp" ] = &id_qoverp;
      fHandles[ "me_d0" ] = &me_d0;
      fHandles[ "me_z0" ] = &me_z0;
      fHandles[ "me_phi" ] = &me_phi;
      fHandles[ "me_theta" ] = &me_theta;
      fHandles[ "me_qoverp" ] = &me_qoverp;
      fHandles[ "ie_d0" ] = &ie_d0;
      fHandles[ "ie_z0" ] = &ie_z0;
      fHandles[ "ie_phi" ] = &ie_phi;
      fHandles[ "ie_theta" ] = &ie_theta;
      fHandles[ "ie_qoverp" ] = &ie_qoverp;
      fHandles[ "nOutliersOnTrack" ] = &nOutliersOnTrack;
      fHandles[ "nBLHits" ] = &nBLHits;
      fHandles[ "nPixHits" ] = &nPixHits;
      fHandles[ "nSCTHits" ] = &nSCTHits;
      fHandles[ "nTRTHits" ] = &nTRTHits;
      fHandles[ "nTRTHighTHits" ] = &nTRTHighTHits;
      fHandles[ "nBLSharedHits" ] = &nBLSharedHits;
      fHandles[ "nPixSharedHits" ] = &nPixSharedHits;
      fHandles[ "nPixHoles" ] = &nPixHoles;
      fHandles[ "nSCTSharedHits" ] = &nSCTSharedHits;
      fHandles[ "nSCTHoles" ] = &nSCTHoles;
      fHandles[ "nTRTOutliers" ] = &nTRTOutliers;
      fHandles[ "nTRTHighTOutliers" ] = &nTRTHighTOutliers;
      fHandles[ "nGangedPixels" ] = &nGangedPixels;
      fHandles[ "nPixelDeadSensors" ] = &nPixelDeadSensors;
      fHandles[ "nSCTDeadSensors" ] = &nSCTDeadSensors;
      fHandles[ "nTRTDeadStraws" ] = &nTRTDeadStraws;
      fHandles[ "expectBLayerHit" ] = &expectBLayerHit;
      fHandles[ "nMDTHits" ] = &nMDTHits;
// -- slimmed --       fHandles[ "nMDTHoles" ] = &nMDTHoles;
      fHandles[ "nCSCEtaHits" ] = &nCSCEtaHits;
// -- slimmed --       fHandles[ "nCSCEtaHoles" ] = &nCSCEtaHoles;
      fHandles[ "nCSCUnspoiledEtaHits" ] = &nCSCUnspoiledEtaHits;
      fHandles[ "nCSCPhiHits" ] = &nCSCPhiHits;
// -- slimmed --       fHandles[ "nCSCPhiHoles" ] = &nCSCPhiHoles;
      fHandles[ "nRPCEtaHits" ] = &nRPCEtaHits;
// -- slimmed --       fHandles[ "nRPCEtaHoles" ] = &nRPCEtaHoles;
      fHandles[ "nRPCPhiHits" ] = &nRPCPhiHits;
// -- slimmed --       fHandles[ "nRPCPhiHoles" ] = &nRPCPhiHoles;
      fHandles[ "nTGCEtaHits" ] = &nTGCEtaHits;
// -- slimmed --       fHandles[ "nTGCEtaHoles" ] = &nTGCEtaHoles;
      fHandles[ "nTGCPhiHits" ] = &nTGCPhiHits;
// -- slimmed --       fHandles[ "nTGCPhiHoles" ] = &nTGCPhiHoles;
      fHandles[ "nprecisionLayers" ] = &nprecisionLayers;
      fHandles[ "nprecisionHoleLayers" ] = &nprecisionHoleLayers;
      fHandles[ "nphiLayers" ] = &nphiLayers;
      fHandles[ "ntrigEtaLayers" ] = &ntrigEtaLayers;
      fHandles[ "nphiHoleLayers" ] = &nphiHoleLayers;
      fHandles[ "ntrigEtaHoleLayers" ] = &ntrigEtaHoleLayers;
      fHandles[ "nMDTBIHits" ] = &nMDTBIHits;
      fHandles[ "nMDTBMHits" ] = &nMDTBMHits;
      fHandles[ "nMDTBOHits" ] = &nMDTBOHits;
      fHandles[ "nMDTBEEHits" ] = &nMDTBEEHits;
      fHandles[ "nMDTBIS78Hits" ] = &nMDTBIS78Hits;
      fHandles[ "nMDTEIHits" ] = &nMDTEIHits;
      fHandles[ "nMDTEMHits" ] = &nMDTEMHits;
      fHandles[ "nMDTEOHits" ] = &nMDTEOHits;
      fHandles[ "nMDTEEHits" ] = &nMDTEEHits;
// -- slimmed --       fHandles[ "nRPCLayer1EtaHits" ] = &nRPCLayer1EtaHits;
// -- slimmed --       fHandles[ "nRPCLayer2EtaHits" ] = &nRPCLayer2EtaHits;
// -- slimmed --       fHandles[ "nRPCLayer3EtaHits" ] = &nRPCLayer3EtaHits;
// -- slimmed --       fHandles[ "nRPCLayer1PhiHits" ] = &nRPCLayer1PhiHits;
// -- slimmed --       fHandles[ "nRPCLayer2PhiHits" ] = &nRPCLayer2PhiHits;
// -- slimmed --       fHandles[ "nRPCLayer3PhiHits" ] = &nRPCLayer3PhiHits;
// -- slimmed --       fHandles[ "nTGCLayer1EtaHits" ] = &nTGCLayer1EtaHits;
// -- slimmed --       fHandles[ "nTGCLayer2EtaHits" ] = &nTGCLayer2EtaHits;
// -- slimmed --       fHandles[ "nTGCLayer3EtaHits" ] = &nTGCLayer3EtaHits;
// -- slimmed --       fHandles[ "nTGCLayer4EtaHits" ] = &nTGCLayer4EtaHits;
// -- slimmed --       fHandles[ "nTGCLayer1PhiHits" ] = &nTGCLayer1PhiHits;
// -- slimmed --       fHandles[ "nTGCLayer2PhiHits" ] = &nTGCLayer2PhiHits;
// -- slimmed --       fHandles[ "nTGCLayer3PhiHits" ] = &nTGCLayer3PhiHits;
// -- slimmed --       fHandles[ "nTGCLayer4PhiHits" ] = &nTGCLayer4PhiHits;
// -- slimmed --       fHandles[ "barrelSectors" ] = &barrelSectors;
// -- slimmed --       fHandles[ "endcapSectors" ] = &endcapSectors;
      fHandles[ "trackd0" ] = &trackd0;
      fHandles[ "trackz0" ] = &trackz0;
      fHandles[ "trackphi" ] = &trackphi;
      fHandles[ "tracktheta" ] = &tracktheta;
      fHandles[ "trackqoverp" ] = &trackqoverp;
      fHandles[ "trackcov_d0" ] = &trackcov_d0;
      fHandles[ "trackcov_z0" ] = &trackcov_z0;
      fHandles[ "trackcov_phi" ] = &trackcov_phi;
      fHandles[ "trackcov_theta" ] = &trackcov_theta;
      fHandles[ "trackcov_qoverp" ] = &trackcov_qoverp;
      fHandles[ "trackcov_d0_z0" ] = &trackcov_d0_z0;
      fHandles[ "trackcov_d0_phi" ] = &trackcov_d0_phi;
      fHandles[ "trackcov_d0_theta" ] = &trackcov_d0_theta;
      fHandles[ "trackcov_d0_qoverp" ] = &trackcov_d0_qoverp;
      fHandles[ "trackcov_z0_phi" ] = &trackcov_z0_phi;
      fHandles[ "trackcov_z0_theta" ] = &trackcov_z0_theta;
      fHandles[ "trackcov_z0_qoverp" ] = &trackcov_z0_qoverp;
      fHandles[ "trackcov_phi_theta" ] = &trackcov_phi_theta;
      fHandles[ "trackcov_phi_qoverp" ] = &trackcov_phi_qoverp;
      fHandles[ "trackcov_theta_qoverp" ] = &trackcov_theta_qoverp;
      fHandles[ "hastrack" ] = &hastrack;
// -- slimmed --       fHandles[ "trackIPEstimate_d0_biasedpvunbiased" ] = &trackIPEstimate_d0_biasedpvunbiased;
// -- slimmed --       fHandles[ "trackIPEstimate_z0_biasedpvunbiased" ] = &trackIPEstimate_z0_biasedpvunbiased;
// -- slimmed --       fHandles[ "trackIPEstimate_sigd0_biasedpvunbiased" ] = &trackIPEstimate_sigd0_biasedpvunbiased;
// -- slimmed --       fHandles[ "trackIPEstimate_sigz0_biasedpvunbiased" ] = &trackIPEstimate_sigz0_biasedpvunbiased;
// -- slimmed --       fHandles[ "trackIPEstimate_d0_unbiasedpvunbiased" ] = &trackIPEstimate_d0_unbiasedpvunbiased;
// -- slimmed --       fHandles[ "trackIPEstimate_z0_unbiasedpvunbiased" ] = &trackIPEstimate_z0_unbiasedpvunbiased;
// -- slimmed --       fHandles[ "trackIPEstimate_sigd0_unbiasedpvunbiased" ] = &trackIPEstimate_sigd0_unbiasedpvunbiased;
// -- slimmed --       fHandles[ "trackIPEstimate_sigz0_unbiasedpvunbiased" ] = &trackIPEstimate_sigz0_unbiasedpvunbiased;
if (!is_data) {
      fHandles[ "type" ] = &type;
      fHandles[ "origin" ] = &origin;
      fHandles[ "truth_dr" ] = &truth_dr;
      fHandles[ "truth_E" ] = &truth_E;
      fHandles[ "truth_pt" ] = &truth_pt;
      fHandles[ "truth_eta" ] = &truth_eta;
      fHandles[ "truth_phi" ] = &truth_phi;
      fHandles[ "truth_type" ] = &truth_type;
      fHandles[ "truth_status" ] = &truth_status;
      fHandles[ "truth_barcode" ] = &truth_barcode;
      fHandles[ "truth_mothertype" ] = &truth_mothertype;
      fHandles[ "truth_motherbarcode" ] = &truth_motherbarcode;
      fHandles[ "truth_matched" ] = &truth_matched;
} // end !is_data
      fHandles[ "EFCB_index" ] = &EFCB_index;
      fHandles[ "EFMG_index" ] = &EFMG_index;
      fHandles[ "EFME_index" ] = &EFME_index;
      fHandles[ "ptcone20_trk500MeV" ] = &ptcone20_trk500MeV;
      fHandles[ "ptcone30_trk500MeV" ] = &ptcone30_trk500MeV;
      fHandles[ "ptcone40_trk500MeV" ] = &ptcone40_trk500MeV;
      fHandles[ "nucone20_trk500MeV" ] = &nucone20_trk500MeV;
      fHandles[ "nucone30_trk500MeV" ] = &nucone30_trk500MeV;
      fHandles[ "nucone40_trk500MeV" ] = &nucone40_trk500MeV;
      fHandles[ "ptcone20_trkelstyle" ] = &ptcone20_trkelstyle;
      fHandles[ "ptcone30_trkelstyle" ] = &ptcone30_trkelstyle;
      fHandles[ "ptcone40_trkelstyle" ] = &ptcone40_trkelstyle;
      fHandles[ "nucone20_trkelstyle" ] = &nucone20_trkelstyle;
      fHandles[ "nucone30_trkelstyle" ] = &nucone30_trkelstyle;
      fHandles[ "nucone40_trkelstyle" ] = &nucone40_trkelstyle;
// -- slimmed --       fHandles[ "MET_Simplified20_wpx" ] = &MET_Simplified20_wpx;
// -- slimmed --       fHandles[ "MET_Simplified20_wpy" ] = &MET_Simplified20_wpy;
// -- slimmed --       fHandles[ "MET_Simplified20_wet" ] = &MET_Simplified20_wet;
// -- slimmed --       fHandles[ "MET_Simplified20_statusWord" ] = &MET_Simplified20_statusWord;
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
// -- slimmed -- // -- slimmed --       fHandles[ "MET_STVF_statusWord" ] = &MET_STVF_statusWord;
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* MuonD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void MuonD3PDObject::SetPrefix( const char* prefix ) {

      n.SetName( ::TString( prefix ) + "n" );
      E.SetName( ::TString( prefix ) + "E" );
      pt.SetName( ::TString( prefix ) + "pt" );
      m.SetName( ::TString( prefix ) + "m" );
      eta.SetName( ::TString( prefix ) + "eta" );
      phi.SetName( ::TString( prefix ) + "phi" );
      px.SetName( ::TString( prefix ) + "px" );
      py.SetName( ::TString( prefix ) + "py" );
      pz.SetName( ::TString( prefix ) + "pz" );
      charge.SetName( ::TString( prefix ) + "charge" );
      allauthor.SetName( ::TString( prefix ) + "allauthor" );
      author.SetName( ::TString( prefix ) + "author" );
      matchchi2.SetName( ::TString( prefix ) + "matchchi2" );
      matchndof.SetName( ::TString( prefix ) + "matchndof" );
      etcone20.SetName( ::TString( prefix ) + "etcone20" );
      etcone30.SetName( ::TString( prefix ) + "etcone30" );
      etcone40.SetName( ::TString( prefix ) + "etcone40" );
      nucone20.SetName( ::TString( prefix ) + "nucone20" );
      nucone30.SetName( ::TString( prefix ) + "nucone30" );
      nucone40.SetName( ::TString( prefix ) + "nucone40" );
      ptcone20.SetName( ::TString( prefix ) + "ptcone20" );
      ptcone30.SetName( ::TString( prefix ) + "ptcone30" );
      ptcone40.SetName( ::TString( prefix ) + "ptcone40" );
// -- slimmed --       etconeNoEm10.SetName( ::TString( prefix ) + "etconeNoEm10" );
// -- slimmed --       etconeNoEm20.SetName( ::TString( prefix ) + "etconeNoEm20" );
// -- slimmed --       etconeNoEm30.SetName( ::TString( prefix ) + "etconeNoEm30" );
// -- slimmed --       etconeNoEm40.SetName( ::TString( prefix ) + "etconeNoEm40" );
// -- slimmed --       scatteringCurvatureSignificance.SetName( ::TString( prefix ) + "scatteringCurvatureSignificance" );
// -- slimmed --       scatteringNeighbourSignificance.SetName( ::TString( prefix ) + "scatteringNeighbourSignificance" );
// -- slimmed --       momentumBalanceSignificance.SetName( ::TString( prefix ) + "momentumBalanceSignificance" );
      energyLossPar.SetName( ::TString( prefix ) + "energyLossPar" );
      energyLossErr.SetName( ::TString( prefix ) + "energyLossErr" );
      etCore.SetName( ::TString( prefix ) + "etCore" );
      energyLossType.SetName( ::TString( prefix ) + "energyLossType" );
      caloMuonIdTag.SetName( ::TString( prefix ) + "caloMuonIdTag" );
      caloLRLikelihood.SetName( ::TString( prefix ) + "caloLRLikelihood" );
      bestMatch.SetName( ::TString( prefix ) + "bestMatch" );
      isStandAloneMuon.SetName( ::TString( prefix ) + "isStandAloneMuon" );
      isCombinedMuon.SetName( ::TString( prefix ) + "isCombinedMuon" );
      isLowPtReconstructedMuon.SetName( ::TString( prefix ) + "isLowPtReconstructedMuon" );
      isSegmentTaggedMuon.SetName( ::TString( prefix ) + "isSegmentTaggedMuon" );
      isCaloMuonId.SetName( ::TString( prefix ) + "isCaloMuonId" );
// -- slimmed --       alsoFoundByLowPt.SetName( ::TString( prefix ) + "alsoFoundByLowPt" );
// -- slimmed --       alsoFoundByCaloMuonId.SetName( ::TString( prefix ) + "alsoFoundByCaloMuonId" );
// -- slimmed --       isSiliconAssociatedForwardMuon.SetName( ::TString( prefix ) + "isSiliconAssociatedForwardMuon" );
      loose.SetName( ::TString( prefix ) + "loose" );
      medium.SetName( ::TString( prefix ) + "medium" );
      tight.SetName( ::TString( prefix ) + "tight" );
      d0_exPV.SetName( ::TString( prefix ) + "d0_exPV" );
      z0_exPV.SetName( ::TString( prefix ) + "z0_exPV" );
      phi_exPV.SetName( ::TString( prefix ) + "phi_exPV" );
      theta_exPV.SetName( ::TString( prefix ) + "theta_exPV" );
      qoverp_exPV.SetName( ::TString( prefix ) + "qoverp_exPV" );
      cb_d0_exPV.SetName( ::TString( prefix ) + "cb_d0_exPV" );
      cb_z0_exPV.SetName( ::TString( prefix ) + "cb_z0_exPV" );
      cb_phi_exPV.SetName( ::TString( prefix ) + "cb_phi_exPV" );
      cb_theta_exPV.SetName( ::TString( prefix ) + "cb_theta_exPV" );
      cb_qoverp_exPV.SetName( ::TString( prefix ) + "cb_qoverp_exPV" );
      id_d0_exPV.SetName( ::TString( prefix ) + "id_d0_exPV" );
      id_z0_exPV.SetName( ::TString( prefix ) + "id_z0_exPV" );
      id_phi_exPV.SetName( ::TString( prefix ) + "id_phi_exPV" );
      id_theta_exPV.SetName( ::TString( prefix ) + "id_theta_exPV" );
      id_qoverp_exPV.SetName( ::TString( prefix ) + "id_qoverp_exPV" );
      me_d0_exPV.SetName( ::TString( prefix ) + "me_d0_exPV" );
      me_z0_exPV.SetName( ::TString( prefix ) + "me_z0_exPV" );
      me_phi_exPV.SetName( ::TString( prefix ) + "me_phi_exPV" );
      me_theta_exPV.SetName( ::TString( prefix ) + "me_theta_exPV" );
      me_qoverp_exPV.SetName( ::TString( prefix ) + "me_qoverp_exPV" );
      ie_d0_exPV.SetName( ::TString( prefix ) + "ie_d0_exPV" );
      ie_z0_exPV.SetName( ::TString( prefix ) + "ie_z0_exPV" );
      ie_phi_exPV.SetName( ::TString( prefix ) + "ie_phi_exPV" );
      ie_theta_exPV.SetName( ::TString( prefix ) + "ie_theta_exPV" );
      ie_qoverp_exPV.SetName( ::TString( prefix ) + "ie_qoverp_exPV" );
      cov_d0_exPV.SetName( ::TString( prefix ) + "cov_d0_exPV" );
      cov_z0_exPV.SetName( ::TString( prefix ) + "cov_z0_exPV" );
      cov_phi_exPV.SetName( ::TString( prefix ) + "cov_phi_exPV" );
      cov_theta_exPV.SetName( ::TString( prefix ) + "cov_theta_exPV" );
      cov_qoverp_exPV.SetName( ::TString( prefix ) + "cov_qoverp_exPV" );
      cov_d0_z0_exPV.SetName( ::TString( prefix ) + "cov_d0_z0_exPV" );
      cov_d0_phi_exPV.SetName( ::TString( prefix ) + "cov_d0_phi_exPV" );
      cov_d0_theta_exPV.SetName( ::TString( prefix ) + "cov_d0_theta_exPV" );
      cov_d0_qoverp_exPV.SetName( ::TString( prefix ) + "cov_d0_qoverp_exPV" );
      cov_z0_phi_exPV.SetName( ::TString( prefix ) + "cov_z0_phi_exPV" );
      cov_z0_theta_exPV.SetName( ::TString( prefix ) + "cov_z0_theta_exPV" );
      cov_z0_qoverp_exPV.SetName( ::TString( prefix ) + "cov_z0_qoverp_exPV" );
      cov_phi_theta_exPV.SetName( ::TString( prefix ) + "cov_phi_theta_exPV" );
      cov_phi_qoverp_exPV.SetName( ::TString( prefix ) + "cov_phi_qoverp_exPV" );
      cov_theta_qoverp_exPV.SetName( ::TString( prefix ) + "cov_theta_qoverp_exPV" );
      id_cov_d0_exPV.SetName( ::TString( prefix ) + "id_cov_d0_exPV" );
      id_cov_z0_exPV.SetName( ::TString( prefix ) + "id_cov_z0_exPV" );
      id_cov_phi_exPV.SetName( ::TString( prefix ) + "id_cov_phi_exPV" );
      id_cov_theta_exPV.SetName( ::TString( prefix ) + "id_cov_theta_exPV" );
      id_cov_qoverp_exPV.SetName( ::TString( prefix ) + "id_cov_qoverp_exPV" );
      id_cov_d0_z0_exPV.SetName( ::TString( prefix ) + "id_cov_d0_z0_exPV" );
      id_cov_d0_phi_exPV.SetName( ::TString( prefix ) + "id_cov_d0_phi_exPV" );
      id_cov_d0_theta_exPV.SetName( ::TString( prefix ) + "id_cov_d0_theta_exPV" );
      id_cov_d0_qoverp_exPV.SetName( ::TString( prefix ) + "id_cov_d0_qoverp_exPV" );
      id_cov_z0_phi_exPV.SetName( ::TString( prefix ) + "id_cov_z0_phi_exPV" );
      id_cov_z0_theta_exPV.SetName( ::TString( prefix ) + "id_cov_z0_theta_exPV" );
      id_cov_z0_qoverp_exPV.SetName( ::TString( prefix ) + "id_cov_z0_qoverp_exPV" );
      id_cov_phi_theta_exPV.SetName( ::TString( prefix ) + "id_cov_phi_theta_exPV" );
      id_cov_phi_qoverp_exPV.SetName( ::TString( prefix ) + "id_cov_phi_qoverp_exPV" );
      id_cov_theta_qoverp_exPV.SetName( ::TString( prefix ) + "id_cov_theta_qoverp_exPV" );
      me_cov_d0_exPV.SetName( ::TString( prefix ) + "me_cov_d0_exPV" );
      me_cov_z0_exPV.SetName( ::TString( prefix ) + "me_cov_z0_exPV" );
      me_cov_phi_exPV.SetName( ::TString( prefix ) + "me_cov_phi_exPV" );
      me_cov_theta_exPV.SetName( ::TString( prefix ) + "me_cov_theta_exPV" );
      me_cov_qoverp_exPV.SetName( ::TString( prefix ) + "me_cov_qoverp_exPV" );
      ms_d0.SetName( ::TString( prefix ) + "ms_d0" );
      ms_z0.SetName( ::TString( prefix ) + "ms_z0" );
      ms_phi.SetName( ::TString( prefix ) + "ms_phi" );
      ms_theta.SetName( ::TString( prefix ) + "ms_theta" );
      ms_qoverp.SetName( ::TString( prefix ) + "ms_qoverp" );
      id_d0.SetName( ::TString( prefix ) + "id_d0" );
      id_z0.SetName( ::TString( prefix ) + "id_z0" );
      id_phi.SetName( ::TString( prefix ) + "id_phi" );
      id_theta.SetName( ::TString( prefix ) + "id_theta" );
      id_qoverp.SetName( ::TString( prefix ) + "id_qoverp" );
      me_d0.SetName( ::TString( prefix ) + "me_d0" );
      me_z0.SetName( ::TString( prefix ) + "me_z0" );
      me_phi.SetName( ::TString( prefix ) + "me_phi" );
      me_theta.SetName( ::TString( prefix ) + "me_theta" );
      me_qoverp.SetName( ::TString( prefix ) + "me_qoverp" );
      ie_d0.SetName( ::TString( prefix ) + "ie_d0" );
      ie_z0.SetName( ::TString( prefix ) + "ie_z0" );
      ie_phi.SetName( ::TString( prefix ) + "ie_phi" );
      ie_theta.SetName( ::TString( prefix ) + "ie_theta" );
      ie_qoverp.SetName( ::TString( prefix ) + "ie_qoverp" );
      nOutliersOnTrack.SetName( ::TString( prefix ) + "nOutliersOnTrack" );
      nBLHits.SetName( ::TString( prefix ) + "nBLHits" );
      nPixHits.SetName( ::TString( prefix ) + "nPixHits" );
      nSCTHits.SetName( ::TString( prefix ) + "nSCTHits" );
      nTRTHits.SetName( ::TString( prefix ) + "nTRTHits" );
      nTRTHighTHits.SetName( ::TString( prefix ) + "nTRTHighTHits" );
      nBLSharedHits.SetName( ::TString( prefix ) + "nBLSharedHits" );
      nPixSharedHits.SetName( ::TString( prefix ) + "nPixSharedHits" );
      nPixHoles.SetName( ::TString( prefix ) + "nPixHoles" );
      nSCTSharedHits.SetName( ::TString( prefix ) + "nSCTSharedHits" );
      nSCTHoles.SetName( ::TString( prefix ) + "nSCTHoles" );
      nTRTOutliers.SetName( ::TString( prefix ) + "nTRTOutliers" );
      nTRTHighTOutliers.SetName( ::TString( prefix ) + "nTRTHighTOutliers" );
      nGangedPixels.SetName( ::TString( prefix ) + "nGangedPixels" );
      nPixelDeadSensors.SetName( ::TString( prefix ) + "nPixelDeadSensors" );
      nSCTDeadSensors.SetName( ::TString( prefix ) + "nSCTDeadSensors" );
      nTRTDeadStraws.SetName( ::TString( prefix ) + "nTRTDeadStraws" );
      expectBLayerHit.SetName( ::TString( prefix ) + "expectBLayerHit" );
      nMDTHits.SetName( ::TString( prefix ) + "nMDTHits" );
// -- slimmed --       nMDTHoles.SetName( ::TString( prefix ) + "nMDTHoles" );
      nCSCEtaHits.SetName( ::TString( prefix ) + "nCSCEtaHits" );
// -- slimmed --       nCSCEtaHoles.SetName( ::TString( prefix ) + "nCSCEtaHoles" );
      nCSCUnspoiledEtaHits.SetName( ::TString( prefix ) + "nCSCUnspoiledEtaHits" );
      nCSCPhiHits.SetName( ::TString( prefix ) + "nCSCPhiHits" );
// -- slimmed --       nCSCPhiHoles.SetName( ::TString( prefix ) + "nCSCPhiHoles" );
      nRPCEtaHits.SetName( ::TString( prefix ) + "nRPCEtaHits" );
// -- slimmed --       nRPCEtaHoles.SetName( ::TString( prefix ) + "nRPCEtaHoles" );
      nRPCPhiHits.SetName( ::TString( prefix ) + "nRPCPhiHits" );
// -- slimmed --       nRPCPhiHoles.SetName( ::TString( prefix ) + "nRPCPhiHoles" );
      nTGCEtaHits.SetName( ::TString( prefix ) + "nTGCEtaHits" );
// -- slimmed --       nTGCEtaHoles.SetName( ::TString( prefix ) + "nTGCEtaHoles" );
      nTGCPhiHits.SetName( ::TString( prefix ) + "nTGCPhiHits" );
// -- slimmed --       nTGCPhiHoles.SetName( ::TString( prefix ) + "nTGCPhiHoles" );
      nprecisionLayers.SetName( ::TString( prefix ) + "nprecisionLayers" );
      nprecisionHoleLayers.SetName( ::TString( prefix ) + "nprecisionHoleLayers" );
      nphiLayers.SetName( ::TString( prefix ) + "nphiLayers" );
      ntrigEtaLayers.SetName( ::TString( prefix ) + "ntrigEtaLayers" );
      nphiHoleLayers.SetName( ::TString( prefix ) + "nphiHoleLayers" );
      ntrigEtaHoleLayers.SetName( ::TString( prefix ) + "ntrigEtaHoleLayers" );
      nMDTBIHits.SetName( ::TString( prefix ) + "nMDTBIHits" );
      nMDTBMHits.SetName( ::TString( prefix ) + "nMDTBMHits" );
      nMDTBOHits.SetName( ::TString( prefix ) + "nMDTBOHits" );
      nMDTBEEHits.SetName( ::TString( prefix ) + "nMDTBEEHits" );
      nMDTBIS78Hits.SetName( ::TString( prefix ) + "nMDTBIS78Hits" );
      nMDTEIHits.SetName( ::TString( prefix ) + "nMDTEIHits" );
      nMDTEMHits.SetName( ::TString( prefix ) + "nMDTEMHits" );
      nMDTEOHits.SetName( ::TString( prefix ) + "nMDTEOHits" );
      nMDTEEHits.SetName( ::TString( prefix ) + "nMDTEEHits" );
// -- slimmed --       nRPCLayer1EtaHits.SetName( ::TString( prefix ) + "nRPCLayer1EtaHits" );
// -- slimmed --       nRPCLayer2EtaHits.SetName( ::TString( prefix ) + "nRPCLayer2EtaHits" );
// -- slimmed --       nRPCLayer3EtaHits.SetName( ::TString( prefix ) + "nRPCLayer3EtaHits" );
// -- slimmed --       nRPCLayer1PhiHits.SetName( ::TString( prefix ) + "nRPCLayer1PhiHits" );
// -- slimmed --       nRPCLayer2PhiHits.SetName( ::TString( prefix ) + "nRPCLayer2PhiHits" );
// -- slimmed --       nRPCLayer3PhiHits.SetName( ::TString( prefix ) + "nRPCLayer3PhiHits" );
// -- slimmed --       nTGCLayer1EtaHits.SetName( ::TString( prefix ) + "nTGCLayer1EtaHits" );
// -- slimmed --       nTGCLayer2EtaHits.SetName( ::TString( prefix ) + "nTGCLayer2EtaHits" );
// -- slimmed --       nTGCLayer3EtaHits.SetName( ::TString( prefix ) + "nTGCLayer3EtaHits" );
// -- slimmed --       nTGCLayer4EtaHits.SetName( ::TString( prefix ) + "nTGCLayer4EtaHits" );
// -- slimmed --       nTGCLayer1PhiHits.SetName( ::TString( prefix ) + "nTGCLayer1PhiHits" );
// -- slimmed --       nTGCLayer2PhiHits.SetName( ::TString( prefix ) + "nTGCLayer2PhiHits" );
// -- slimmed --       nTGCLayer3PhiHits.SetName( ::TString( prefix ) + "nTGCLayer3PhiHits" );
// -- slimmed --       nTGCLayer4PhiHits.SetName( ::TString( prefix ) + "nTGCLayer4PhiHits" );
// -- slimmed --       barrelSectors.SetName( ::TString( prefix ) + "barrelSectors" );
// -- slimmed --       endcapSectors.SetName( ::TString( prefix ) + "endcapSectors" );
      trackd0.SetName( ::TString( prefix ) + "trackd0" );
      trackz0.SetName( ::TString( prefix ) + "trackz0" );
      trackphi.SetName( ::TString( prefix ) + "trackphi" );
      tracktheta.SetName( ::TString( prefix ) + "tracktheta" );
      trackqoverp.SetName( ::TString( prefix ) + "trackqoverp" );
      trackcov_d0.SetName( ::TString( prefix ) + "trackcov_d0" );
      trackcov_z0.SetName( ::TString( prefix ) + "trackcov_z0" );
      trackcov_phi.SetName( ::TString( prefix ) + "trackcov_phi" );
      trackcov_theta.SetName( ::TString( prefix ) + "trackcov_theta" );
      trackcov_qoverp.SetName( ::TString( prefix ) + "trackcov_qoverp" );
      trackcov_d0_z0.SetName( ::TString( prefix ) + "trackcov_d0_z0" );
      trackcov_d0_phi.SetName( ::TString( prefix ) + "trackcov_d0_phi" );
      trackcov_d0_theta.SetName( ::TString( prefix ) + "trackcov_d0_theta" );
      trackcov_d0_qoverp.SetName( ::TString( prefix ) + "trackcov_d0_qoverp" );
      trackcov_z0_phi.SetName( ::TString( prefix ) + "trackcov_z0_phi" );
      trackcov_z0_theta.SetName( ::TString( prefix ) + "trackcov_z0_theta" );
      trackcov_z0_qoverp.SetName( ::TString( prefix ) + "trackcov_z0_qoverp" );
      trackcov_phi_theta.SetName( ::TString( prefix ) + "trackcov_phi_theta" );
      trackcov_phi_qoverp.SetName( ::TString( prefix ) + "trackcov_phi_qoverp" );
      trackcov_theta_qoverp.SetName( ::TString( prefix ) + "trackcov_theta_qoverp" );
      hastrack.SetName( ::TString( prefix ) + "hastrack" );
// -- slimmed --       trackIPEstimate_d0_biasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_d0_biasedpvunbiased" );
// -- slimmed --       trackIPEstimate_z0_biasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_z0_biasedpvunbiased" );
// -- slimmed --       trackIPEstimate_sigd0_biasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_sigd0_biasedpvunbiased" );
// -- slimmed --       trackIPEstimate_sigz0_biasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_sigz0_biasedpvunbiased" );
// -- slimmed --       trackIPEstimate_d0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_d0_unbiasedpvunbiased" );
// -- slimmed --       trackIPEstimate_z0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_z0_unbiasedpvunbiased" );
// -- slimmed --       trackIPEstimate_sigd0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_sigd0_unbiasedpvunbiased" );
// -- slimmed --       trackIPEstimate_sigz0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_sigz0_unbiasedpvunbiased" );
if (!is_data) {
      type.SetName( ::TString( prefix ) + "type" );
      origin.SetName( ::TString( prefix ) + "origin" );
      truth_dr.SetName( ::TString( prefix ) + "truth_dr" );
      truth_E.SetName( ::TString( prefix ) + "truth_E" );
      truth_pt.SetName( ::TString( prefix ) + "truth_pt" );
      truth_eta.SetName( ::TString( prefix ) + "truth_eta" );
      truth_phi.SetName( ::TString( prefix ) + "truth_phi" );
      truth_type.SetName( ::TString( prefix ) + "truth_type" );
      truth_status.SetName( ::TString( prefix ) + "truth_status" );
      truth_barcode.SetName( ::TString( prefix ) + "truth_barcode" );
      truth_mothertype.SetName( ::TString( prefix ) + "truth_mothertype" );
      truth_motherbarcode.SetName( ::TString( prefix ) + "truth_motherbarcode" );
      truth_matched.SetName( ::TString( prefix ) + "truth_matched" );
} // end !is_data
      EFCB_index.SetName( ::TString( prefix ) + "EFCB_index" );
      EFMG_index.SetName( ::TString( prefix ) + "EFMG_index" );
      EFME_index.SetName( ::TString( prefix ) + "EFME_index" );
      ptcone20_trk500MeV.SetName( ::TString( prefix ) + "ptcone20_trk500MeV" );
      ptcone30_trk500MeV.SetName( ::TString( prefix ) + "ptcone30_trk500MeV" );
      ptcone40_trk500MeV.SetName( ::TString( prefix ) + "ptcone40_trk500MeV" );
      nucone20_trk500MeV.SetName( ::TString( prefix ) + "nucone20_trk500MeV" );
      nucone30_trk500MeV.SetName( ::TString( prefix ) + "nucone30_trk500MeV" );
      nucone40_trk500MeV.SetName( ::TString( prefix ) + "nucone40_trk500MeV" );
      ptcone20_trkelstyle.SetName( ::TString( prefix ) + "ptcone20_trkelstyle" );
      ptcone30_trkelstyle.SetName( ::TString( prefix ) + "ptcone30_trkelstyle" );
      ptcone40_trkelstyle.SetName( ::TString( prefix ) + "ptcone40_trkelstyle" );
      nucone20_trkelstyle.SetName( ::TString( prefix ) + "nucone20_trkelstyle" );
      nucone30_trkelstyle.SetName( ::TString( prefix ) + "nucone30_trkelstyle" );
      nucone40_trkelstyle.SetName( ::TString( prefix ) + "nucone40_trkelstyle" );
// -- slimmed --       MET_Simplified20_wpx.SetName( ::TString( prefix ) + "MET_Simplified20_wpx" );
// -- slimmed --       MET_Simplified20_wpy.SetName( ::TString( prefix ) + "MET_Simplified20_wpy" );
// -- slimmed --       MET_Simplified20_wet.SetName( ::TString( prefix ) + "MET_Simplified20_wet" );
// -- slimmed --       MET_Simplified20_statusWord.SetName( ::TString( prefix ) + "MET_Simplified20_statusWord" );
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
// -- slimmed -- // -- slimmed --       MET_STVF_statusWord.SetName( ::TString( prefix ) + "MET_STVF_statusWord" );
      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void MuonD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      n.ReadFrom( tree );
      E.ReadFrom( tree );
      pt.ReadFrom( tree );
      m.ReadFrom( tree );
      eta.ReadFrom( tree );
      phi.ReadFrom( tree );
      px.ReadFrom( tree );
      py.ReadFrom( tree );
      pz.ReadFrom( tree );
      charge.ReadFrom( tree );
      allauthor.ReadFrom( tree );
      author.ReadFrom( tree );
      matchchi2.ReadFrom( tree );
      matchndof.ReadFrom( tree );
      etcone20.ReadFrom( tree );
      etcone30.ReadFrom( tree );
      etcone40.ReadFrom( tree );
      nucone20.ReadFrom( tree );
      nucone30.ReadFrom( tree );
      nucone40.ReadFrom( tree );
      ptcone20.ReadFrom( tree );
      ptcone30.ReadFrom( tree );
      ptcone40.ReadFrom( tree );
// -- slimmed --       etconeNoEm10.ReadFrom( tree );
// -- slimmed --       etconeNoEm20.ReadFrom( tree );
// -- slimmed --       etconeNoEm30.ReadFrom( tree );
// -- slimmed --       etconeNoEm40.ReadFrom( tree );
// -- slimmed --       scatteringCurvatureSignificance.ReadFrom( tree );
// -- slimmed --       scatteringNeighbourSignificance.ReadFrom( tree );
// -- slimmed --       momentumBalanceSignificance.ReadFrom( tree );
      energyLossPar.ReadFrom( tree );
      energyLossErr.ReadFrom( tree );
      etCore.ReadFrom( tree );
      energyLossType.ReadFrom( tree );
      caloMuonIdTag.ReadFrom( tree );
      caloLRLikelihood.ReadFrom( tree );
      bestMatch.ReadFrom( tree );
      isStandAloneMuon.ReadFrom( tree );
      isCombinedMuon.ReadFrom( tree );
      isLowPtReconstructedMuon.ReadFrom( tree );
      isSegmentTaggedMuon.ReadFrom( tree );
      isCaloMuonId.ReadFrom( tree );
// -- slimmed --       alsoFoundByLowPt.ReadFrom( tree );
// -- slimmed --       alsoFoundByCaloMuonId.ReadFrom( tree );
// -- slimmed --       isSiliconAssociatedForwardMuon.ReadFrom( tree );
      loose.ReadFrom( tree );
      medium.ReadFrom( tree );
      tight.ReadFrom( tree );
      d0_exPV.ReadFrom( tree );
      z0_exPV.ReadFrom( tree );
      phi_exPV.ReadFrom( tree );
      theta_exPV.ReadFrom( tree );
      qoverp_exPV.ReadFrom( tree );
      cb_d0_exPV.ReadFrom( tree );
      cb_z0_exPV.ReadFrom( tree );
      cb_phi_exPV.ReadFrom( tree );
      cb_theta_exPV.ReadFrom( tree );
      cb_qoverp_exPV.ReadFrom( tree );
      id_d0_exPV.ReadFrom( tree );
      id_z0_exPV.ReadFrom( tree );
      id_phi_exPV.ReadFrom( tree );
      id_theta_exPV.ReadFrom( tree );
      id_qoverp_exPV.ReadFrom( tree );
      me_d0_exPV.ReadFrom( tree );
      me_z0_exPV.ReadFrom( tree );
      me_phi_exPV.ReadFrom( tree );
      me_theta_exPV.ReadFrom( tree );
      me_qoverp_exPV.ReadFrom( tree );
      ie_d0_exPV.ReadFrom( tree );
      ie_z0_exPV.ReadFrom( tree );
      ie_phi_exPV.ReadFrom( tree );
      ie_theta_exPV.ReadFrom( tree );
      ie_qoverp_exPV.ReadFrom( tree );
      cov_d0_exPV.ReadFrom( tree );
      cov_z0_exPV.ReadFrom( tree );
      cov_phi_exPV.ReadFrom( tree );
      cov_theta_exPV.ReadFrom( tree );
      cov_qoverp_exPV.ReadFrom( tree );
      cov_d0_z0_exPV.ReadFrom( tree );
      cov_d0_phi_exPV.ReadFrom( tree );
      cov_d0_theta_exPV.ReadFrom( tree );
      cov_d0_qoverp_exPV.ReadFrom( tree );
      cov_z0_phi_exPV.ReadFrom( tree );
      cov_z0_theta_exPV.ReadFrom( tree );
      cov_z0_qoverp_exPV.ReadFrom( tree );
      cov_phi_theta_exPV.ReadFrom( tree );
      cov_phi_qoverp_exPV.ReadFrom( tree );
      cov_theta_qoverp_exPV.ReadFrom( tree );
      id_cov_d0_exPV.ReadFrom( tree );
      id_cov_z0_exPV.ReadFrom( tree );
      id_cov_phi_exPV.ReadFrom( tree );
      id_cov_theta_exPV.ReadFrom( tree );
      id_cov_qoverp_exPV.ReadFrom( tree );
      id_cov_d0_z0_exPV.ReadFrom( tree );
      id_cov_d0_phi_exPV.ReadFrom( tree );
      id_cov_d0_theta_exPV.ReadFrom( tree );
      id_cov_d0_qoverp_exPV.ReadFrom( tree );
      id_cov_z0_phi_exPV.ReadFrom( tree );
      id_cov_z0_theta_exPV.ReadFrom( tree );
      id_cov_z0_qoverp_exPV.ReadFrom( tree );
      id_cov_phi_theta_exPV.ReadFrom( tree );
      id_cov_phi_qoverp_exPV.ReadFrom( tree );
      id_cov_theta_qoverp_exPV.ReadFrom( tree );
      me_cov_d0_exPV.ReadFrom( tree );
      me_cov_z0_exPV.ReadFrom( tree );
      me_cov_phi_exPV.ReadFrom( tree );
      me_cov_theta_exPV.ReadFrom( tree );
      me_cov_qoverp_exPV.ReadFrom( tree );
      ms_d0.ReadFrom( tree );
      ms_z0.ReadFrom( tree );
      ms_phi.ReadFrom( tree );
      ms_theta.ReadFrom( tree );
      ms_qoverp.ReadFrom( tree );
      id_d0.ReadFrom( tree );
      id_z0.ReadFrom( tree );
      id_phi.ReadFrom( tree );
      id_theta.ReadFrom( tree );
      id_qoverp.ReadFrom( tree );
      me_d0.ReadFrom( tree );
      me_z0.ReadFrom( tree );
      me_phi.ReadFrom( tree );
      me_theta.ReadFrom( tree );
      me_qoverp.ReadFrom( tree );
      ie_d0.ReadFrom( tree );
      ie_z0.ReadFrom( tree );
      ie_phi.ReadFrom( tree );
      ie_theta.ReadFrom( tree );
      ie_qoverp.ReadFrom( tree );
      nOutliersOnTrack.ReadFrom( tree );
      nBLHits.ReadFrom( tree );
      nPixHits.ReadFrom( tree );
      nSCTHits.ReadFrom( tree );
      nTRTHits.ReadFrom( tree );
      nTRTHighTHits.ReadFrom( tree );
      nBLSharedHits.ReadFrom( tree );
      nPixSharedHits.ReadFrom( tree );
      nPixHoles.ReadFrom( tree );
      nSCTSharedHits.ReadFrom( tree );
      nSCTHoles.ReadFrom( tree );
      nTRTOutliers.ReadFrom( tree );
      nTRTHighTOutliers.ReadFrom( tree );
      nGangedPixels.ReadFrom( tree );
      nPixelDeadSensors.ReadFrom( tree );
      nSCTDeadSensors.ReadFrom( tree );
      nTRTDeadStraws.ReadFrom( tree );
      expectBLayerHit.ReadFrom( tree );
      nMDTHits.ReadFrom( tree );
// -- slimmed --       nMDTHoles.ReadFrom( tree );
      nCSCEtaHits.ReadFrom( tree );
// -- slimmed --       nCSCEtaHoles.ReadFrom( tree );
      nCSCUnspoiledEtaHits.ReadFrom( tree );
      nCSCPhiHits.ReadFrom( tree );
// -- slimmed --       nCSCPhiHoles.ReadFrom( tree );
      nRPCEtaHits.ReadFrom( tree );
// -- slimmed --       nRPCEtaHoles.ReadFrom( tree );
      nRPCPhiHits.ReadFrom( tree );
// -- slimmed --       nRPCPhiHoles.ReadFrom( tree );
      nTGCEtaHits.ReadFrom( tree );
// -- slimmed --       nTGCEtaHoles.ReadFrom( tree );
      nTGCPhiHits.ReadFrom( tree );
// -- slimmed --       nTGCPhiHoles.ReadFrom( tree );
      nprecisionLayers.ReadFrom( tree );
      nprecisionHoleLayers.ReadFrom( tree );
      nphiLayers.ReadFrom( tree );
      ntrigEtaLayers.ReadFrom( tree );
      nphiHoleLayers.ReadFrom( tree );
      ntrigEtaHoleLayers.ReadFrom( tree );
      nMDTBIHits.ReadFrom( tree );
      nMDTBMHits.ReadFrom( tree );
      nMDTBOHits.ReadFrom( tree );
      nMDTBEEHits.ReadFrom( tree );
      nMDTBIS78Hits.ReadFrom( tree );
      nMDTEIHits.ReadFrom( tree );
      nMDTEMHits.ReadFrom( tree );
      nMDTEOHits.ReadFrom( tree );
      nMDTEEHits.ReadFrom( tree );
// -- slimmed --       nRPCLayer1EtaHits.ReadFrom( tree );
// -- slimmed --       nRPCLayer2EtaHits.ReadFrom( tree );
// -- slimmed --       nRPCLayer3EtaHits.ReadFrom( tree );
// -- slimmed --       nRPCLayer1PhiHits.ReadFrom( tree );
// -- slimmed --       nRPCLayer2PhiHits.ReadFrom( tree );
// -- slimmed --       nRPCLayer3PhiHits.ReadFrom( tree );
// -- slimmed --       nTGCLayer1EtaHits.ReadFrom( tree );
// -- slimmed --       nTGCLayer2EtaHits.ReadFrom( tree );
// -- slimmed --       nTGCLayer3EtaHits.ReadFrom( tree );
// -- slimmed --       nTGCLayer4EtaHits.ReadFrom( tree );
// -- slimmed --       nTGCLayer1PhiHits.ReadFrom( tree );
// -- slimmed --       nTGCLayer2PhiHits.ReadFrom( tree );
// -- slimmed --       nTGCLayer3PhiHits.ReadFrom( tree );
// -- slimmed --       nTGCLayer4PhiHits.ReadFrom( tree );
// -- slimmed --       barrelSectors.ReadFrom( tree );
// -- slimmed --       endcapSectors.ReadFrom( tree );
      trackd0.ReadFrom( tree );
      trackz0.ReadFrom( tree );
      trackphi.ReadFrom( tree );
      tracktheta.ReadFrom( tree );
      trackqoverp.ReadFrom( tree );
      trackcov_d0.ReadFrom( tree );
      trackcov_z0.ReadFrom( tree );
      trackcov_phi.ReadFrom( tree );
      trackcov_theta.ReadFrom( tree );
      trackcov_qoverp.ReadFrom( tree );
      trackcov_d0_z0.ReadFrom( tree );
      trackcov_d0_phi.ReadFrom( tree );
      trackcov_d0_theta.ReadFrom( tree );
      trackcov_d0_qoverp.ReadFrom( tree );
      trackcov_z0_phi.ReadFrom( tree );
      trackcov_z0_theta.ReadFrom( tree );
      trackcov_z0_qoverp.ReadFrom( tree );
      trackcov_phi_theta.ReadFrom( tree );
      trackcov_phi_qoverp.ReadFrom( tree );
      trackcov_theta_qoverp.ReadFrom( tree );
      hastrack.ReadFrom( tree );
// -- slimmed --       trackIPEstimate_d0_biasedpvunbiased.ReadFrom( tree );
// -- slimmed --       trackIPEstimate_z0_biasedpvunbiased.ReadFrom( tree );
// -- slimmed --       trackIPEstimate_sigd0_biasedpvunbiased.ReadFrom( tree );
// -- slimmed --       trackIPEstimate_sigz0_biasedpvunbiased.ReadFrom( tree );
// -- slimmed --       trackIPEstimate_d0_unbiasedpvunbiased.ReadFrom( tree );
// -- slimmed --       trackIPEstimate_z0_unbiasedpvunbiased.ReadFrom( tree );
// -- slimmed --       trackIPEstimate_sigd0_unbiasedpvunbiased.ReadFrom( tree );
// -- slimmed --       trackIPEstimate_sigz0_unbiasedpvunbiased.ReadFrom( tree );
if (!is_data) {
      type.ReadFrom( tree );
      origin.ReadFrom( tree );
      truth_dr.ReadFrom( tree );
      truth_E.ReadFrom( tree );
      truth_pt.ReadFrom( tree );
      truth_eta.ReadFrom( tree );
      truth_phi.ReadFrom( tree );
      truth_type.ReadFrom( tree );
      truth_status.ReadFrom( tree );
      truth_barcode.ReadFrom( tree );
      truth_mothertype.ReadFrom( tree );
      truth_motherbarcode.ReadFrom( tree );
      truth_matched.ReadFrom( tree );
} // end !is_data
      EFCB_index.ReadFrom( tree );
      EFMG_index.ReadFrom( tree );
      EFME_index.ReadFrom( tree );
      ptcone20_trk500MeV.ReadFrom( tree );
      ptcone30_trk500MeV.ReadFrom( tree );
      ptcone40_trk500MeV.ReadFrom( tree );
      nucone20_trk500MeV.ReadFrom( tree );
      nucone30_trk500MeV.ReadFrom( tree );
      nucone40_trk500MeV.ReadFrom( tree );
      ptcone20_trkelstyle.ReadFrom( tree );
      ptcone30_trkelstyle.ReadFrom( tree );
      ptcone40_trkelstyle.ReadFrom( tree );
      nucone20_trkelstyle.ReadFrom( tree );
      nucone30_trkelstyle.ReadFrom( tree );
      nucone40_trkelstyle.ReadFrom( tree );
// -- slimmed --       MET_Simplified20_wpx.ReadFrom( tree );
// -- slimmed --       MET_Simplified20_wpy.ReadFrom( tree );
// -- slimmed --       MET_Simplified20_wet.ReadFrom( tree );
// -- slimmed --       MET_Simplified20_statusWord.ReadFrom( tree );
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
// -- slimmed -- // -- slimmed --       MET_STVF_statusWord.ReadFrom( tree );

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void MuonD3PDObject::WriteTo( TTree* tree ) {

      n.WriteTo( tree );
      E.WriteTo( tree );
      pt.WriteTo( tree );
      m.WriteTo( tree );
      eta.WriteTo( tree );
      phi.WriteTo( tree );
      px.WriteTo( tree );
      py.WriteTo( tree );
      pz.WriteTo( tree );
      charge.WriteTo( tree );
      allauthor.WriteTo( tree );
      author.WriteTo( tree );
      matchchi2.WriteTo( tree );
      matchndof.WriteTo( tree );
      etcone20.WriteTo( tree );
      etcone30.WriteTo( tree );
      etcone40.WriteTo( tree );
      nucone20.WriteTo( tree );
      nucone30.WriteTo( tree );
      nucone40.WriteTo( tree );
      ptcone20.WriteTo( tree );
      ptcone30.WriteTo( tree );
      ptcone40.WriteTo( tree );
// -- slimmed --       etconeNoEm10.WriteTo( tree );
// -- slimmed --       etconeNoEm20.WriteTo( tree );
// -- slimmed --       etconeNoEm30.WriteTo( tree );
// -- slimmed --       etconeNoEm40.WriteTo( tree );
// -- slimmed --       scatteringCurvatureSignificance.WriteTo( tree );
// -- slimmed --       scatteringNeighbourSignificance.WriteTo( tree );
// -- slimmed --       momentumBalanceSignificance.WriteTo( tree );
      energyLossPar.WriteTo( tree );
      energyLossErr.WriteTo( tree );
      etCore.WriteTo( tree );
      energyLossType.WriteTo( tree );
      caloMuonIdTag.WriteTo( tree );
      caloLRLikelihood.WriteTo( tree );
      bestMatch.WriteTo( tree );
      isStandAloneMuon.WriteTo( tree );
      isCombinedMuon.WriteTo( tree );
      isLowPtReconstructedMuon.WriteTo( tree );
      isSegmentTaggedMuon.WriteTo( tree );
      isCaloMuonId.WriteTo( tree );
// -- slimmed --       alsoFoundByLowPt.WriteTo( tree );
// -- slimmed --       alsoFoundByCaloMuonId.WriteTo( tree );
// -- slimmed --       isSiliconAssociatedForwardMuon.WriteTo( tree );
      loose.WriteTo( tree );
      medium.WriteTo( tree );
      tight.WriteTo( tree );
      d0_exPV.WriteTo( tree );
      z0_exPV.WriteTo( tree );
      phi_exPV.WriteTo( tree );
      theta_exPV.WriteTo( tree );
      qoverp_exPV.WriteTo( tree );
      cb_d0_exPV.WriteTo( tree );
      cb_z0_exPV.WriteTo( tree );
      cb_phi_exPV.WriteTo( tree );
      cb_theta_exPV.WriteTo( tree );
      cb_qoverp_exPV.WriteTo( tree );
      id_d0_exPV.WriteTo( tree );
      id_z0_exPV.WriteTo( tree );
      id_phi_exPV.WriteTo( tree );
      id_theta_exPV.WriteTo( tree );
      id_qoverp_exPV.WriteTo( tree );
      me_d0_exPV.WriteTo( tree );
      me_z0_exPV.WriteTo( tree );
      me_phi_exPV.WriteTo( tree );
      me_theta_exPV.WriteTo( tree );
      me_qoverp_exPV.WriteTo( tree );
      ie_d0_exPV.WriteTo( tree );
      ie_z0_exPV.WriteTo( tree );
      ie_phi_exPV.WriteTo( tree );
      ie_theta_exPV.WriteTo( tree );
      ie_qoverp_exPV.WriteTo( tree );
      cov_d0_exPV.WriteTo( tree );
      cov_z0_exPV.WriteTo( tree );
      cov_phi_exPV.WriteTo( tree );
      cov_theta_exPV.WriteTo( tree );
      cov_qoverp_exPV.WriteTo( tree );
      cov_d0_z0_exPV.WriteTo( tree );
      cov_d0_phi_exPV.WriteTo( tree );
      cov_d0_theta_exPV.WriteTo( tree );
      cov_d0_qoverp_exPV.WriteTo( tree );
      cov_z0_phi_exPV.WriteTo( tree );
      cov_z0_theta_exPV.WriteTo( tree );
      cov_z0_qoverp_exPV.WriteTo( tree );
      cov_phi_theta_exPV.WriteTo( tree );
      cov_phi_qoverp_exPV.WriteTo( tree );
      cov_theta_qoverp_exPV.WriteTo( tree );
      id_cov_d0_exPV.WriteTo( tree );
      id_cov_z0_exPV.WriteTo( tree );
      id_cov_phi_exPV.WriteTo( tree );
      id_cov_theta_exPV.WriteTo( tree );
      id_cov_qoverp_exPV.WriteTo( tree );
      id_cov_d0_z0_exPV.WriteTo( tree );
      id_cov_d0_phi_exPV.WriteTo( tree );
      id_cov_d0_theta_exPV.WriteTo( tree );
      id_cov_d0_qoverp_exPV.WriteTo( tree );
      id_cov_z0_phi_exPV.WriteTo( tree );
      id_cov_z0_theta_exPV.WriteTo( tree );
      id_cov_z0_qoverp_exPV.WriteTo( tree );
      id_cov_phi_theta_exPV.WriteTo( tree );
      id_cov_phi_qoverp_exPV.WriteTo( tree );
      id_cov_theta_qoverp_exPV.WriteTo( tree );
      me_cov_d0_exPV.WriteTo( tree );
      me_cov_z0_exPV.WriteTo( tree );
      me_cov_phi_exPV.WriteTo( tree );
      me_cov_theta_exPV.WriteTo( tree );
      me_cov_qoverp_exPV.WriteTo( tree );
      ms_d0.WriteTo( tree );
      ms_z0.WriteTo( tree );
      ms_phi.WriteTo( tree );
      ms_theta.WriteTo( tree );
      ms_qoverp.WriteTo( tree );
      id_d0.WriteTo( tree );
      id_z0.WriteTo( tree );
      id_phi.WriteTo( tree );
      id_theta.WriteTo( tree );
      id_qoverp.WriteTo( tree );
      me_d0.WriteTo( tree );
      me_z0.WriteTo( tree );
      me_phi.WriteTo( tree );
      me_theta.WriteTo( tree );
      me_qoverp.WriteTo( tree );
      ie_d0.WriteTo( tree );
      ie_z0.WriteTo( tree );
      ie_phi.WriteTo( tree );
      ie_theta.WriteTo( tree );
      ie_qoverp.WriteTo( tree );
      nOutliersOnTrack.WriteTo( tree );
      nBLHits.WriteTo( tree );
      nPixHits.WriteTo( tree );
      nSCTHits.WriteTo( tree );
      nTRTHits.WriteTo( tree );
      nTRTHighTHits.WriteTo( tree );
      nBLSharedHits.WriteTo( tree );
      nPixSharedHits.WriteTo( tree );
      nPixHoles.WriteTo( tree );
      nSCTSharedHits.WriteTo( tree );
      nSCTHoles.WriteTo( tree );
      nTRTOutliers.WriteTo( tree );
      nTRTHighTOutliers.WriteTo( tree );
      nGangedPixels.WriteTo( tree );
      nPixelDeadSensors.WriteTo( tree );
      nSCTDeadSensors.WriteTo( tree );
      nTRTDeadStraws.WriteTo( tree );
      expectBLayerHit.WriteTo( tree );
      nMDTHits.WriteTo( tree );
// -- slimmed --       nMDTHoles.WriteTo( tree );
      nCSCEtaHits.WriteTo( tree );
// -- slimmed --       nCSCEtaHoles.WriteTo( tree );
      nCSCUnspoiledEtaHits.WriteTo( tree );
      nCSCPhiHits.WriteTo( tree );
// -- slimmed --       nCSCPhiHoles.WriteTo( tree );
      nRPCEtaHits.WriteTo( tree );
// -- slimmed --       nRPCEtaHoles.WriteTo( tree );
      nRPCPhiHits.WriteTo( tree );
// -- slimmed --       nRPCPhiHoles.WriteTo( tree );
      nTGCEtaHits.WriteTo( tree );
// -- slimmed --       nTGCEtaHoles.WriteTo( tree );
      nTGCPhiHits.WriteTo( tree );
// -- slimmed --       nTGCPhiHoles.WriteTo( tree );
      nprecisionLayers.WriteTo( tree );
      nprecisionHoleLayers.WriteTo( tree );
      nphiLayers.WriteTo( tree );
      ntrigEtaLayers.WriteTo( tree );
      nphiHoleLayers.WriteTo( tree );
      ntrigEtaHoleLayers.WriteTo( tree );
      nMDTBIHits.WriteTo( tree );
      nMDTBMHits.WriteTo( tree );
      nMDTBOHits.WriteTo( tree );
      nMDTBEEHits.WriteTo( tree );
      nMDTBIS78Hits.WriteTo( tree );
      nMDTEIHits.WriteTo( tree );
      nMDTEMHits.WriteTo( tree );
      nMDTEOHits.WriteTo( tree );
      nMDTEEHits.WriteTo( tree );
// -- slimmed --       nRPCLayer1EtaHits.WriteTo( tree );
// -- slimmed --       nRPCLayer2EtaHits.WriteTo( tree );
// -- slimmed --       nRPCLayer3EtaHits.WriteTo( tree );
// -- slimmed --       nRPCLayer1PhiHits.WriteTo( tree );
// -- slimmed --       nRPCLayer2PhiHits.WriteTo( tree );
// -- slimmed --       nRPCLayer3PhiHits.WriteTo( tree );
// -- slimmed --       nTGCLayer1EtaHits.WriteTo( tree );
// -- slimmed --       nTGCLayer2EtaHits.WriteTo( tree );
// -- slimmed --       nTGCLayer3EtaHits.WriteTo( tree );
// -- slimmed --       nTGCLayer4EtaHits.WriteTo( tree );
// -- slimmed --       nTGCLayer1PhiHits.WriteTo( tree );
// -- slimmed --       nTGCLayer2PhiHits.WriteTo( tree );
// -- slimmed --       nTGCLayer3PhiHits.WriteTo( tree );
// -- slimmed --       nTGCLayer4PhiHits.WriteTo( tree );
// -- slimmed --       barrelSectors.WriteTo( tree );
// -- slimmed --       endcapSectors.WriteTo( tree );
      trackd0.WriteTo( tree );
      trackz0.WriteTo( tree );
      trackphi.WriteTo( tree );
      tracktheta.WriteTo( tree );
      trackqoverp.WriteTo( tree );
      trackcov_d0.WriteTo( tree );
      trackcov_z0.WriteTo( tree );
      trackcov_phi.WriteTo( tree );
      trackcov_theta.WriteTo( tree );
      trackcov_qoverp.WriteTo( tree );
      trackcov_d0_z0.WriteTo( tree );
      trackcov_d0_phi.WriteTo( tree );
      trackcov_d0_theta.WriteTo( tree );
      trackcov_d0_qoverp.WriteTo( tree );
      trackcov_z0_phi.WriteTo( tree );
      trackcov_z0_theta.WriteTo( tree );
      trackcov_z0_qoverp.WriteTo( tree );
      trackcov_phi_theta.WriteTo( tree );
      trackcov_phi_qoverp.WriteTo( tree );
      trackcov_theta_qoverp.WriteTo( tree );
      hastrack.WriteTo( tree );
// -- slimmed --       trackIPEstimate_d0_biasedpvunbiased.WriteTo( tree );
// -- slimmed --       trackIPEstimate_z0_biasedpvunbiased.WriteTo( tree );
// -- slimmed --       trackIPEstimate_sigd0_biasedpvunbiased.WriteTo( tree );
// -- slimmed --       trackIPEstimate_sigz0_biasedpvunbiased.WriteTo( tree );
// -- slimmed --       trackIPEstimate_d0_unbiasedpvunbiased.WriteTo( tree );
// -- slimmed --       trackIPEstimate_z0_unbiasedpvunbiased.WriteTo( tree );
// -- slimmed --       trackIPEstimate_sigd0_unbiasedpvunbiased.WriteTo( tree );
// -- slimmed --       trackIPEstimate_sigz0_unbiasedpvunbiased.WriteTo( tree );
if (!is_data) {
      type.WriteTo( tree );
      origin.WriteTo( tree );
      truth_dr.WriteTo( tree );
      truth_E.WriteTo( tree );
      truth_pt.WriteTo( tree );
      truth_eta.WriteTo( tree );
      truth_phi.WriteTo( tree );
      truth_type.WriteTo( tree );
      truth_status.WriteTo( tree );
      truth_barcode.WriteTo( tree );
      truth_mothertype.WriteTo( tree );
      truth_motherbarcode.WriteTo( tree );
      truth_matched.WriteTo( tree );
} // end !is_data
      EFCB_index.WriteTo( tree );
      EFMG_index.WriteTo( tree );
      EFME_index.WriteTo( tree );
      ptcone20_trk500MeV.WriteTo( tree );
      ptcone30_trk500MeV.WriteTo( tree );
      ptcone40_trk500MeV.WriteTo( tree );
      nucone20_trk500MeV.WriteTo( tree );
      nucone30_trk500MeV.WriteTo( tree );
      nucone40_trk500MeV.WriteTo( tree );
      ptcone20_trkelstyle.WriteTo( tree );
      ptcone30_trkelstyle.WriteTo( tree );
      ptcone40_trkelstyle.WriteTo( tree );
      nucone20_trkelstyle.WriteTo( tree );
      nucone30_trkelstyle.WriteTo( tree );
      nucone40_trkelstyle.WriteTo( tree );
// -- slimmed --       MET_Simplified20_wpx.WriteTo( tree );
// -- slimmed --       MET_Simplified20_wpy.WriteTo( tree );
// -- slimmed --       MET_Simplified20_wet.WriteTo( tree );
// -- slimmed --       MET_Simplified20_statusWord.WriteTo( tree );
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
// -- slimmed -- // -- slimmed --       MET_STVF_statusWord.WriteTo( tree );

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
   void MuonD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void MuonD3PDObject::ReadAllActive() {

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
      if( E.IsActive() ) E();
      if( pt.IsActive() ) pt();
      if( m.IsActive() ) m();
      if( eta.IsActive() ) eta();
      if( phi.IsActive() ) phi();
      if( px.IsActive() ) px();
      if( py.IsActive() ) py();
      if( pz.IsActive() ) pz();
      if( charge.IsActive() ) charge();
      if( allauthor.IsActive() ) allauthor();
      if( author.IsActive() ) author();
      if( matchchi2.IsActive() ) matchchi2();
      if( matchndof.IsActive() ) matchndof();
      if( etcone20.IsActive() ) etcone20();
      if( etcone30.IsActive() ) etcone30();
      if( etcone40.IsActive() ) etcone40();
      if( nucone20.IsActive() ) nucone20();
      if( nucone30.IsActive() ) nucone30();
      if( nucone40.IsActive() ) nucone40();
      if( ptcone20.IsActive() ) ptcone20();
      if( ptcone30.IsActive() ) ptcone30();
      if( ptcone40.IsActive() ) ptcone40();
// -- slimmed --       if( etconeNoEm10.IsActive() ) etconeNoEm10();
// -- slimmed --       if( etconeNoEm20.IsActive() ) etconeNoEm20();
// -- slimmed --       if( etconeNoEm30.IsActive() ) etconeNoEm30();
// -- slimmed --       if( etconeNoEm40.IsActive() ) etconeNoEm40();
// -- slimmed --       if( scatteringCurvatureSignificance.IsActive() ) scatteringCurvatureSignificance();
// -- slimmed --       if( scatteringNeighbourSignificance.IsActive() ) scatteringNeighbourSignificance();
// -- slimmed --       if( momentumBalanceSignificance.IsActive() ) momentumBalanceSignificance();
      if( energyLossPar.IsActive() ) energyLossPar();
      if( energyLossErr.IsActive() ) energyLossErr();
      if( etCore.IsActive() ) etCore();
      if( energyLossType.IsActive() ) energyLossType();
      if( caloMuonIdTag.IsActive() ) caloMuonIdTag();
      if( caloLRLikelihood.IsActive() ) caloLRLikelihood();
      if( bestMatch.IsActive() ) bestMatch();
      if( isStandAloneMuon.IsActive() ) isStandAloneMuon();
      if( isCombinedMuon.IsActive() ) isCombinedMuon();
      if( isLowPtReconstructedMuon.IsActive() ) isLowPtReconstructedMuon();
      if( isSegmentTaggedMuon.IsActive() ) isSegmentTaggedMuon();
      if( isCaloMuonId.IsActive() ) isCaloMuonId();
// -- slimmed --       if( alsoFoundByLowPt.IsActive() ) alsoFoundByLowPt();
// -- slimmed --       if( alsoFoundByCaloMuonId.IsActive() ) alsoFoundByCaloMuonId();
// -- slimmed --       if( isSiliconAssociatedForwardMuon.IsActive() ) isSiliconAssociatedForwardMuon();
      if( loose.IsActive() ) loose();
      if( medium.IsActive() ) medium();
      if( tight.IsActive() ) tight();
      if( d0_exPV.IsActive() ) d0_exPV();
      if( z0_exPV.IsActive() ) z0_exPV();
      if( phi_exPV.IsActive() ) phi_exPV();
      if( theta_exPV.IsActive() ) theta_exPV();
      if( qoverp_exPV.IsActive() ) qoverp_exPV();
      if( cb_d0_exPV.IsActive() ) cb_d0_exPV();
      if( cb_z0_exPV.IsActive() ) cb_z0_exPV();
      if( cb_phi_exPV.IsActive() ) cb_phi_exPV();
      if( cb_theta_exPV.IsActive() ) cb_theta_exPV();
      if( cb_qoverp_exPV.IsActive() ) cb_qoverp_exPV();
      if( id_d0_exPV.IsActive() ) id_d0_exPV();
      if( id_z0_exPV.IsActive() ) id_z0_exPV();
      if( id_phi_exPV.IsActive() ) id_phi_exPV();
      if( id_theta_exPV.IsActive() ) id_theta_exPV();
      if( id_qoverp_exPV.IsActive() ) id_qoverp_exPV();
      if( me_d0_exPV.IsActive() ) me_d0_exPV();
      if( me_z0_exPV.IsActive() ) me_z0_exPV();
      if( me_phi_exPV.IsActive() ) me_phi_exPV();
      if( me_theta_exPV.IsActive() ) me_theta_exPV();
      if( me_qoverp_exPV.IsActive() ) me_qoverp_exPV();
      if( ie_d0_exPV.IsActive() ) ie_d0_exPV();
      if( ie_z0_exPV.IsActive() ) ie_z0_exPV();
      if( ie_phi_exPV.IsActive() ) ie_phi_exPV();
      if( ie_theta_exPV.IsActive() ) ie_theta_exPV();
      if( ie_qoverp_exPV.IsActive() ) ie_qoverp_exPV();
      if( cov_d0_exPV.IsActive() ) cov_d0_exPV();
      if( cov_z0_exPV.IsActive() ) cov_z0_exPV();
      if( cov_phi_exPV.IsActive() ) cov_phi_exPV();
      if( cov_theta_exPV.IsActive() ) cov_theta_exPV();
      if( cov_qoverp_exPV.IsActive() ) cov_qoverp_exPV();
      if( cov_d0_z0_exPV.IsActive() ) cov_d0_z0_exPV();
      if( cov_d0_phi_exPV.IsActive() ) cov_d0_phi_exPV();
      if( cov_d0_theta_exPV.IsActive() ) cov_d0_theta_exPV();
      if( cov_d0_qoverp_exPV.IsActive() ) cov_d0_qoverp_exPV();
      if( cov_z0_phi_exPV.IsActive() ) cov_z0_phi_exPV();
      if( cov_z0_theta_exPV.IsActive() ) cov_z0_theta_exPV();
      if( cov_z0_qoverp_exPV.IsActive() ) cov_z0_qoverp_exPV();
      if( cov_phi_theta_exPV.IsActive() ) cov_phi_theta_exPV();
      if( cov_phi_qoverp_exPV.IsActive() ) cov_phi_qoverp_exPV();
      if( cov_theta_qoverp_exPV.IsActive() ) cov_theta_qoverp_exPV();
      if( id_cov_d0_exPV.IsActive() ) id_cov_d0_exPV();
      if( id_cov_z0_exPV.IsActive() ) id_cov_z0_exPV();
      if( id_cov_phi_exPV.IsActive() ) id_cov_phi_exPV();
      if( id_cov_theta_exPV.IsActive() ) id_cov_theta_exPV();
      if( id_cov_qoverp_exPV.IsActive() ) id_cov_qoverp_exPV();
      if( id_cov_d0_z0_exPV.IsActive() ) id_cov_d0_z0_exPV();
      if( id_cov_d0_phi_exPV.IsActive() ) id_cov_d0_phi_exPV();
      if( id_cov_d0_theta_exPV.IsActive() ) id_cov_d0_theta_exPV();
      if( id_cov_d0_qoverp_exPV.IsActive() ) id_cov_d0_qoverp_exPV();
      if( id_cov_z0_phi_exPV.IsActive() ) id_cov_z0_phi_exPV();
      if( id_cov_z0_theta_exPV.IsActive() ) id_cov_z0_theta_exPV();
      if( id_cov_z0_qoverp_exPV.IsActive() ) id_cov_z0_qoverp_exPV();
      if( id_cov_phi_theta_exPV.IsActive() ) id_cov_phi_theta_exPV();
      if( id_cov_phi_qoverp_exPV.IsActive() ) id_cov_phi_qoverp_exPV();
      if( id_cov_theta_qoverp_exPV.IsActive() ) id_cov_theta_qoverp_exPV();
      if( me_cov_d0_exPV.IsActive() ) me_cov_d0_exPV();
      if( me_cov_z0_exPV.IsActive() ) me_cov_z0_exPV();
      if( me_cov_phi_exPV.IsActive() ) me_cov_phi_exPV();
      if( me_cov_theta_exPV.IsActive() ) me_cov_theta_exPV();
      if( me_cov_qoverp_exPV.IsActive() ) me_cov_qoverp_exPV();
      if( ms_d0.IsActive() ) ms_d0();
      if( ms_z0.IsActive() ) ms_z0();
      if( ms_phi.IsActive() ) ms_phi();
      if( ms_theta.IsActive() ) ms_theta();
      if( ms_qoverp.IsActive() ) ms_qoverp();
      if( id_d0.IsActive() ) id_d0();
      if( id_z0.IsActive() ) id_z0();
      if( id_phi.IsActive() ) id_phi();
      if( id_theta.IsActive() ) id_theta();
      if( id_qoverp.IsActive() ) id_qoverp();
      if( me_d0.IsActive() ) me_d0();
      if( me_z0.IsActive() ) me_z0();
      if( me_phi.IsActive() ) me_phi();
      if( me_theta.IsActive() ) me_theta();
      if( me_qoverp.IsActive() ) me_qoverp();
      if( ie_d0.IsActive() ) ie_d0();
      if( ie_z0.IsActive() ) ie_z0();
      if( ie_phi.IsActive() ) ie_phi();
      if( ie_theta.IsActive() ) ie_theta();
      if( ie_qoverp.IsActive() ) ie_qoverp();
      if( nOutliersOnTrack.IsActive() ) nOutliersOnTrack();
      if( nBLHits.IsActive() ) nBLHits();
      if( nPixHits.IsActive() ) nPixHits();
      if( nSCTHits.IsActive() ) nSCTHits();
      if( nTRTHits.IsActive() ) nTRTHits();
      if( nTRTHighTHits.IsActive() ) nTRTHighTHits();
      if( nBLSharedHits.IsActive() ) nBLSharedHits();
      if( nPixSharedHits.IsActive() ) nPixSharedHits();
      if( nPixHoles.IsActive() ) nPixHoles();
      if( nSCTSharedHits.IsActive() ) nSCTSharedHits();
      if( nSCTHoles.IsActive() ) nSCTHoles();
      if( nTRTOutliers.IsActive() ) nTRTOutliers();
      if( nTRTHighTOutliers.IsActive() ) nTRTHighTOutliers();
      if( nGangedPixels.IsActive() ) nGangedPixels();
      if( nPixelDeadSensors.IsActive() ) nPixelDeadSensors();
      if( nSCTDeadSensors.IsActive() ) nSCTDeadSensors();
      if( nTRTDeadStraws.IsActive() ) nTRTDeadStraws();
      if( expectBLayerHit.IsActive() ) expectBLayerHit();
      if( nMDTHits.IsActive() ) nMDTHits();
// -- slimmed --       if( nMDTHoles.IsActive() ) nMDTHoles();
      if( nCSCEtaHits.IsActive() ) nCSCEtaHits();
// -- slimmed --       if( nCSCEtaHoles.IsActive() ) nCSCEtaHoles();
      if( nCSCUnspoiledEtaHits.IsActive() ) nCSCUnspoiledEtaHits();
      if( nCSCPhiHits.IsActive() ) nCSCPhiHits();
// -- slimmed --       if( nCSCPhiHoles.IsActive() ) nCSCPhiHoles();
      if( nRPCEtaHits.IsActive() ) nRPCEtaHits();
// -- slimmed --       if( nRPCEtaHoles.IsActive() ) nRPCEtaHoles();
      if( nRPCPhiHits.IsActive() ) nRPCPhiHits();
// -- slimmed --       if( nRPCPhiHoles.IsActive() ) nRPCPhiHoles();
      if( nTGCEtaHits.IsActive() ) nTGCEtaHits();
// -- slimmed --       if( nTGCEtaHoles.IsActive() ) nTGCEtaHoles();
      if( nTGCPhiHits.IsActive() ) nTGCPhiHits();
// -- slimmed --       if( nTGCPhiHoles.IsActive() ) nTGCPhiHoles();
      if( nprecisionLayers.IsActive() ) nprecisionLayers();
      if( nprecisionHoleLayers.IsActive() ) nprecisionHoleLayers();
      if( nphiLayers.IsActive() ) nphiLayers();
      if( ntrigEtaLayers.IsActive() ) ntrigEtaLayers();
      if( nphiHoleLayers.IsActive() ) nphiHoleLayers();
      if( ntrigEtaHoleLayers.IsActive() ) ntrigEtaHoleLayers();
      if( nMDTBIHits.IsActive() ) nMDTBIHits();
      if( nMDTBMHits.IsActive() ) nMDTBMHits();
      if( nMDTBOHits.IsActive() ) nMDTBOHits();
      if( nMDTBEEHits.IsActive() ) nMDTBEEHits();
      if( nMDTBIS78Hits.IsActive() ) nMDTBIS78Hits();
      if( nMDTEIHits.IsActive() ) nMDTEIHits();
      if( nMDTEMHits.IsActive() ) nMDTEMHits();
      if( nMDTEOHits.IsActive() ) nMDTEOHits();
      if( nMDTEEHits.IsActive() ) nMDTEEHits();
// -- slimmed --       if( nRPCLayer1EtaHits.IsActive() ) nRPCLayer1EtaHits();
// -- slimmed --       if( nRPCLayer2EtaHits.IsActive() ) nRPCLayer2EtaHits();
// -- slimmed --       if( nRPCLayer3EtaHits.IsActive() ) nRPCLayer3EtaHits();
// -- slimmed --       if( nRPCLayer1PhiHits.IsActive() ) nRPCLayer1PhiHits();
// -- slimmed --       if( nRPCLayer2PhiHits.IsActive() ) nRPCLayer2PhiHits();
// -- slimmed --       if( nRPCLayer3PhiHits.IsActive() ) nRPCLayer3PhiHits();
// -- slimmed --       if( nTGCLayer1EtaHits.IsActive() ) nTGCLayer1EtaHits();
// -- slimmed --       if( nTGCLayer2EtaHits.IsActive() ) nTGCLayer2EtaHits();
// -- slimmed --       if( nTGCLayer3EtaHits.IsActive() ) nTGCLayer3EtaHits();
// -- slimmed --       if( nTGCLayer4EtaHits.IsActive() ) nTGCLayer4EtaHits();
// -- slimmed --       if( nTGCLayer1PhiHits.IsActive() ) nTGCLayer1PhiHits();
// -- slimmed --       if( nTGCLayer2PhiHits.IsActive() ) nTGCLayer2PhiHits();
// -- slimmed --       if( nTGCLayer3PhiHits.IsActive() ) nTGCLayer3PhiHits();
// -- slimmed --       if( nTGCLayer4PhiHits.IsActive() ) nTGCLayer4PhiHits();
// -- slimmed --       if( barrelSectors.IsActive() ) barrelSectors();
// -- slimmed --       if( endcapSectors.IsActive() ) endcapSectors();
      if( trackd0.IsActive() ) trackd0();
      if( trackz0.IsActive() ) trackz0();
      if( trackphi.IsActive() ) trackphi();
      if( tracktheta.IsActive() ) tracktheta();
      if( trackqoverp.IsActive() ) trackqoverp();
      if( trackcov_d0.IsActive() ) trackcov_d0();
      if( trackcov_z0.IsActive() ) trackcov_z0();
      if( trackcov_phi.IsActive() ) trackcov_phi();
      if( trackcov_theta.IsActive() ) trackcov_theta();
      if( trackcov_qoverp.IsActive() ) trackcov_qoverp();
      if( trackcov_d0_z0.IsActive() ) trackcov_d0_z0();
      if( trackcov_d0_phi.IsActive() ) trackcov_d0_phi();
      if( trackcov_d0_theta.IsActive() ) trackcov_d0_theta();
      if( trackcov_d0_qoverp.IsActive() ) trackcov_d0_qoverp();
      if( trackcov_z0_phi.IsActive() ) trackcov_z0_phi();
      if( trackcov_z0_theta.IsActive() ) trackcov_z0_theta();
      if( trackcov_z0_qoverp.IsActive() ) trackcov_z0_qoverp();
      if( trackcov_phi_theta.IsActive() ) trackcov_phi_theta();
      if( trackcov_phi_qoverp.IsActive() ) trackcov_phi_qoverp();
      if( trackcov_theta_qoverp.IsActive() ) trackcov_theta_qoverp();
      if( hastrack.IsActive() ) hastrack();
// -- slimmed --       if( trackIPEstimate_d0_biasedpvunbiased.IsActive() ) trackIPEstimate_d0_biasedpvunbiased();
// -- slimmed --       if( trackIPEstimate_z0_biasedpvunbiased.IsActive() ) trackIPEstimate_z0_biasedpvunbiased();
// -- slimmed --       if( trackIPEstimate_sigd0_biasedpvunbiased.IsActive() ) trackIPEstimate_sigd0_biasedpvunbiased();
// -- slimmed --       if( trackIPEstimate_sigz0_biasedpvunbiased.IsActive() ) trackIPEstimate_sigz0_biasedpvunbiased();
// -- slimmed --       if( trackIPEstimate_d0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_d0_unbiasedpvunbiased();
// -- slimmed --       if( trackIPEstimate_z0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_z0_unbiasedpvunbiased();
// -- slimmed --       if( trackIPEstimate_sigd0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_sigd0_unbiasedpvunbiased();
// -- slimmed --       if( trackIPEstimate_sigz0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_sigz0_unbiasedpvunbiased();
if (!is_data) {
      if( type.IsActive() ) type();
      if( origin.IsActive() ) origin();
      if( truth_dr.IsActive() ) truth_dr();
      if( truth_E.IsActive() ) truth_E();
      if( truth_pt.IsActive() ) truth_pt();
      if( truth_eta.IsActive() ) truth_eta();
      if( truth_phi.IsActive() ) truth_phi();
      if( truth_type.IsActive() ) truth_type();
      if( truth_status.IsActive() ) truth_status();
      if( truth_barcode.IsActive() ) truth_barcode();
      if( truth_mothertype.IsActive() ) truth_mothertype();
      if( truth_motherbarcode.IsActive() ) truth_motherbarcode();
      if( truth_matched.IsActive() ) truth_matched();
} // end !is_data
      if( EFCB_index.IsActive() ) EFCB_index();
      if( EFMG_index.IsActive() ) EFMG_index();
      if( EFME_index.IsActive() ) EFME_index();
      if( ptcone20_trk500MeV.IsActive() ) ptcone20_trk500MeV();
      if( ptcone30_trk500MeV.IsActive() ) ptcone30_trk500MeV();
      if( ptcone40_trk500MeV.IsActive() ) ptcone40_trk500MeV();
      if( nucone20_trk500MeV.IsActive() ) nucone20_trk500MeV();
      if( nucone30_trk500MeV.IsActive() ) nucone30_trk500MeV();
      if( nucone40_trk500MeV.IsActive() ) nucone40_trk500MeV();
      if( ptcone20_trkelstyle.IsActive() ) ptcone20_trkelstyle();
      if( ptcone30_trkelstyle.IsActive() ) ptcone30_trkelstyle();
      if( ptcone40_trkelstyle.IsActive() ) ptcone40_trkelstyle();
      if( nucone20_trkelstyle.IsActive() ) nucone20_trkelstyle();
      if( nucone30_trkelstyle.IsActive() ) nucone30_trkelstyle();
      if( nucone40_trkelstyle.IsActive() ) nucone40_trkelstyle();
// -- slimmed --       if( MET_Simplified20_wpx.IsActive() ) MET_Simplified20_wpx();
// -- slimmed --       if( MET_Simplified20_wpy.IsActive() ) MET_Simplified20_wpy();
// -- slimmed --       if( MET_Simplified20_wet.IsActive() ) MET_Simplified20_wet();
// -- slimmed --       if( MET_Simplified20_statusWord.IsActive() ) MET_Simplified20_statusWord();
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
// -- slimmed -- // -- slimmed --       if( MET_STVF_statusWord.IsActive() ) MET_STVF_statusWord();

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
   void MuonD3PDObject::Clear( Option_t* ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Clear", "Objects used for reading a D3PD can't be cleared!" );
         return;
      }

      n() = 0;
      E()->clear();
      pt()->clear();
      m()->clear();
      eta()->clear();
      phi()->clear();
      px()->clear();
      py()->clear();
      pz()->clear();
      charge()->clear();
      allauthor()->clear();
      author()->clear();
      matchchi2()->clear();
      matchndof()->clear();
      etcone20()->clear();
      etcone30()->clear();
      etcone40()->clear();
      nucone20()->clear();
      nucone30()->clear();
      nucone40()->clear();
      ptcone20()->clear();
      ptcone30()->clear();
      ptcone40()->clear();
// -- slimmed --       etconeNoEm10()->clear();
// -- slimmed --       etconeNoEm20()->clear();
// -- slimmed --       etconeNoEm30()->clear();
// -- slimmed --       etconeNoEm40()->clear();
// -- slimmed --       scatteringCurvatureSignificance()->clear();
// -- slimmed --       scatteringNeighbourSignificance()->clear();
// -- slimmed --       momentumBalanceSignificance()->clear();
      energyLossPar()->clear();
      energyLossErr()->clear();
      etCore()->clear();
      energyLossType()->clear();
      caloMuonIdTag()->clear();
      caloLRLikelihood()->clear();
      bestMatch()->clear();
      isStandAloneMuon()->clear();
      isCombinedMuon()->clear();
      isLowPtReconstructedMuon()->clear();
      isSegmentTaggedMuon()->clear();
      isCaloMuonId()->clear();
// -- slimmed --       alsoFoundByLowPt()->clear();
// -- slimmed --       alsoFoundByCaloMuonId()->clear();
// -- slimmed --       isSiliconAssociatedForwardMuon()->clear();
      loose()->clear();
      medium()->clear();
      tight()->clear();
      d0_exPV()->clear();
      z0_exPV()->clear();
      phi_exPV()->clear();
      theta_exPV()->clear();
      qoverp_exPV()->clear();
      cb_d0_exPV()->clear();
      cb_z0_exPV()->clear();
      cb_phi_exPV()->clear();
      cb_theta_exPV()->clear();
      cb_qoverp_exPV()->clear();
      id_d0_exPV()->clear();
      id_z0_exPV()->clear();
      id_phi_exPV()->clear();
      id_theta_exPV()->clear();
      id_qoverp_exPV()->clear();
      me_d0_exPV()->clear();
      me_z0_exPV()->clear();
      me_phi_exPV()->clear();
      me_theta_exPV()->clear();
      me_qoverp_exPV()->clear();
      ie_d0_exPV()->clear();
      ie_z0_exPV()->clear();
      ie_phi_exPV()->clear();
      ie_theta_exPV()->clear();
      ie_qoverp_exPV()->clear();
      cov_d0_exPV()->clear();
      cov_z0_exPV()->clear();
      cov_phi_exPV()->clear();
      cov_theta_exPV()->clear();
      cov_qoverp_exPV()->clear();
      cov_d0_z0_exPV()->clear();
      cov_d0_phi_exPV()->clear();
      cov_d0_theta_exPV()->clear();
      cov_d0_qoverp_exPV()->clear();
      cov_z0_phi_exPV()->clear();
      cov_z0_theta_exPV()->clear();
      cov_z0_qoverp_exPV()->clear();
      cov_phi_theta_exPV()->clear();
      cov_phi_qoverp_exPV()->clear();
      cov_theta_qoverp_exPV()->clear();
      id_cov_d0_exPV()->clear();
      id_cov_z0_exPV()->clear();
      id_cov_phi_exPV()->clear();
      id_cov_theta_exPV()->clear();
      id_cov_qoverp_exPV()->clear();
      id_cov_d0_z0_exPV()->clear();
      id_cov_d0_phi_exPV()->clear();
      id_cov_d0_theta_exPV()->clear();
      id_cov_d0_qoverp_exPV()->clear();
      id_cov_z0_phi_exPV()->clear();
      id_cov_z0_theta_exPV()->clear();
      id_cov_z0_qoverp_exPV()->clear();
      id_cov_phi_theta_exPV()->clear();
      id_cov_phi_qoverp_exPV()->clear();
      id_cov_theta_qoverp_exPV()->clear();
      me_cov_d0_exPV()->clear();
      me_cov_z0_exPV()->clear();
      me_cov_phi_exPV()->clear();
      me_cov_theta_exPV()->clear();
      me_cov_qoverp_exPV()->clear();
      ms_d0()->clear();
      ms_z0()->clear();
      ms_phi()->clear();
      ms_theta()->clear();
      ms_qoverp()->clear();
      id_d0()->clear();
      id_z0()->clear();
      id_phi()->clear();
      id_theta()->clear();
      id_qoverp()->clear();
      me_d0()->clear();
      me_z0()->clear();
      me_phi()->clear();
      me_theta()->clear();
      me_qoverp()->clear();
      ie_d0()->clear();
      ie_z0()->clear();
      ie_phi()->clear();
      ie_theta()->clear();
      ie_qoverp()->clear();
      nOutliersOnTrack()->clear();
      nBLHits()->clear();
      nPixHits()->clear();
      nSCTHits()->clear();
      nTRTHits()->clear();
      nTRTHighTHits()->clear();
      nBLSharedHits()->clear();
      nPixSharedHits()->clear();
      nPixHoles()->clear();
      nSCTSharedHits()->clear();
      nSCTHoles()->clear();
      nTRTOutliers()->clear();
      nTRTHighTOutliers()->clear();
      nGangedPixels()->clear();
      nPixelDeadSensors()->clear();
      nSCTDeadSensors()->clear();
      nTRTDeadStraws()->clear();
      expectBLayerHit()->clear();
      nMDTHits()->clear();
// -- slimmed --       nMDTHoles()->clear();
      nCSCEtaHits()->clear();
// -- slimmed --       nCSCEtaHoles()->clear();
      nCSCUnspoiledEtaHits()->clear();
      nCSCPhiHits()->clear();
// -- slimmed --       nCSCPhiHoles()->clear();
      nRPCEtaHits()->clear();
// -- slimmed --       nRPCEtaHoles()->clear();
      nRPCPhiHits()->clear();
// -- slimmed --       nRPCPhiHoles()->clear();
      nTGCEtaHits()->clear();
// -- slimmed --       nTGCEtaHoles()->clear();
      nTGCPhiHits()->clear();
// -- slimmed --       nTGCPhiHoles()->clear();
      nprecisionLayers()->clear();
      nprecisionHoleLayers()->clear();
      nphiLayers()->clear();
      ntrigEtaLayers()->clear();
      nphiHoleLayers()->clear();
      ntrigEtaHoleLayers()->clear();
      nMDTBIHits()->clear();
      nMDTBMHits()->clear();
      nMDTBOHits()->clear();
      nMDTBEEHits()->clear();
      nMDTBIS78Hits()->clear();
      nMDTEIHits()->clear();
      nMDTEMHits()->clear();
      nMDTEOHits()->clear();
      nMDTEEHits()->clear();
// -- slimmed --       nRPCLayer1EtaHits()->clear();
// -- slimmed --       nRPCLayer2EtaHits()->clear();
// -- slimmed --       nRPCLayer3EtaHits()->clear();
// -- slimmed --       nRPCLayer1PhiHits()->clear();
// -- slimmed --       nRPCLayer2PhiHits()->clear();
// -- slimmed --       nRPCLayer3PhiHits()->clear();
// -- slimmed --       nTGCLayer1EtaHits()->clear();
// -- slimmed --       nTGCLayer2EtaHits()->clear();
// -- slimmed --       nTGCLayer3EtaHits()->clear();
// -- slimmed --       nTGCLayer4EtaHits()->clear();
// -- slimmed --       nTGCLayer1PhiHits()->clear();
// -- slimmed --       nTGCLayer2PhiHits()->clear();
// -- slimmed --       nTGCLayer3PhiHits()->clear();
// -- slimmed --       nTGCLayer4PhiHits()->clear();
// -- slimmed --       barrelSectors()->clear();
// -- slimmed --       endcapSectors()->clear();
      trackd0()->clear();
      trackz0()->clear();
      trackphi()->clear();
      tracktheta()->clear();
      trackqoverp()->clear();
      trackcov_d0()->clear();
      trackcov_z0()->clear();
      trackcov_phi()->clear();
      trackcov_theta()->clear();
      trackcov_qoverp()->clear();
      trackcov_d0_z0()->clear();
      trackcov_d0_phi()->clear();
      trackcov_d0_theta()->clear();
      trackcov_d0_qoverp()->clear();
      trackcov_z0_phi()->clear();
      trackcov_z0_theta()->clear();
      trackcov_z0_qoverp()->clear();
      trackcov_phi_theta()->clear();
      trackcov_phi_qoverp()->clear();
      trackcov_theta_qoverp()->clear();
      hastrack()->clear();
// -- slimmed --       trackIPEstimate_d0_biasedpvunbiased()->clear();
// -- slimmed --       trackIPEstimate_z0_biasedpvunbiased()->clear();
// -- slimmed --       trackIPEstimate_sigd0_biasedpvunbiased()->clear();
// -- slimmed --       trackIPEstimate_sigz0_biasedpvunbiased()->clear();
// -- slimmed --       trackIPEstimate_d0_unbiasedpvunbiased()->clear();
// -- slimmed --       trackIPEstimate_z0_unbiasedpvunbiased()->clear();
// -- slimmed --       trackIPEstimate_sigd0_unbiasedpvunbiased()->clear();
// -- slimmed --       trackIPEstimate_sigz0_unbiasedpvunbiased()->clear();
if (!is_data) {
      type()->clear();
      origin()->clear();
      truth_dr()->clear();
      truth_E()->clear();
      truth_pt()->clear();
      truth_eta()->clear();
      truth_phi()->clear();
      truth_type()->clear();
      truth_status()->clear();
      truth_barcode()->clear();
      truth_mothertype()->clear();
      truth_motherbarcode()->clear();
      truth_matched()->clear();
} // end !is_data
      EFCB_index()->clear();
      EFMG_index()->clear();
      EFME_index()->clear();
      ptcone20_trk500MeV()->clear();
      ptcone30_trk500MeV()->clear();
      ptcone40_trk500MeV()->clear();
      nucone20_trk500MeV()->clear();
      nucone30_trk500MeV()->clear();
      nucone40_trk500MeV()->clear();
      ptcone20_trkelstyle()->clear();
      ptcone30_trkelstyle()->clear();
      ptcone40_trkelstyle()->clear();
      nucone20_trkelstyle()->clear();
      nucone30_trkelstyle()->clear();
      nucone40_trkelstyle()->clear();
// -- slimmed --       MET_Simplified20_wpx()->clear();
// -- slimmed --       MET_Simplified20_wpy()->clear();
// -- slimmed --       MET_Simplified20_wet()->clear();
// -- slimmed --       MET_Simplified20_statusWord()->clear();
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
// -- slimmed -- // -- slimmed --       MET_STVF_statusWord()->clear();

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
   MuonD3PDObject& MuonD3PDObject::Add( const MuonD3PDObjectElement& el ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Add", "Objects used for reading a D3PD can't be modified!" );
         return *this;
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
      if( el.px.IsAvailable() ) {
         px()->push_back( el.px() );
      } else {
         px()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.py.IsAvailable() ) {
         py()->push_back( el.py() );
      } else {
         py()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pz.IsAvailable() ) {
         pz()->push_back( el.pz() );
      } else {
         pz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.charge.IsAvailable() ) {
         charge()->push_back( el.charge() );
      } else {
         charge()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.allauthor.IsAvailable() ) {
         allauthor()->push_back( el.allauthor() );
      } else {
         allauthor()->push_back( std::numeric_limits< unsigned short >::min() );
      }
      if( el.author.IsAvailable() ) {
         author()->push_back( el.author() );
      } else {
         author()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.matchchi2.IsAvailable() ) {
         matchchi2()->push_back( el.matchchi2() );
      } else {
         matchchi2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.matchndof.IsAvailable() ) {
         matchndof()->push_back( el.matchndof() );
      } else {
         matchndof()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.etcone20.IsAvailable() ) {
         etcone20()->push_back( el.etcone20() );
      } else {
         etcone20()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etcone30.IsAvailable() ) {
         etcone30()->push_back( el.etcone30() );
      } else {
         etcone30()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etcone40.IsAvailable() ) {
         etcone40()->push_back( el.etcone40() );
      } else {
         etcone40()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nucone20.IsAvailable() ) {
         nucone20()->push_back( el.nucone20() );
      } else {
         nucone20()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nucone30.IsAvailable() ) {
         nucone30()->push_back( el.nucone30() );
      } else {
         nucone30()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nucone40.IsAvailable() ) {
         nucone40()->push_back( el.nucone40() );
      } else {
         nucone40()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ptcone20.IsAvailable() ) {
         ptcone20()->push_back( el.ptcone20() );
      } else {
         ptcone20()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ptcone30.IsAvailable() ) {
         ptcone30()->push_back( el.ptcone30() );
      } else {
         ptcone30()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ptcone40.IsAvailable() ) {
         ptcone40()->push_back( el.ptcone40() );
      } else {
         ptcone40()->push_back( std::numeric_limits< float >::min() );
      }
// -- slimmed --       if( el.etconeNoEm10.IsAvailable() ) {
// -- slimmed --          etconeNoEm10()->push_back( el.etconeNoEm10() );
// -- slimmed --       } else {
// -- slimmed --          etconeNoEm10()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.etconeNoEm20.IsAvailable() ) {
// -- slimmed --          etconeNoEm20()->push_back( el.etconeNoEm20() );
// -- slimmed --       } else {
// -- slimmed --          etconeNoEm20()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.etconeNoEm30.IsAvailable() ) {
// -- slimmed --          etconeNoEm30()->push_back( el.etconeNoEm30() );
// -- slimmed --       } else {
// -- slimmed --          etconeNoEm30()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.etconeNoEm40.IsAvailable() ) {
// -- slimmed --          etconeNoEm40()->push_back( el.etconeNoEm40() );
// -- slimmed --       } else {
// -- slimmed --          etconeNoEm40()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.scatteringCurvatureSignificance.IsAvailable() ) {
// -- slimmed --          scatteringCurvatureSignificance()->push_back( el.scatteringCurvatureSignificance() );
// -- slimmed --       } else {
// -- slimmed --          scatteringCurvatureSignificance()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.scatteringNeighbourSignificance.IsAvailable() ) {
// -- slimmed --          scatteringNeighbourSignificance()->push_back( el.scatteringNeighbourSignificance() );
// -- slimmed --       } else {
// -- slimmed --          scatteringNeighbourSignificance()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.momentumBalanceSignificance.IsAvailable() ) {
// -- slimmed --          momentumBalanceSignificance()->push_back( el.momentumBalanceSignificance() );
// -- slimmed --       } else {
// -- slimmed --          momentumBalanceSignificance()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
      if( el.energyLossPar.IsAvailable() ) {
         energyLossPar()->push_back( el.energyLossPar() );
      } else {
         energyLossPar()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.energyLossErr.IsAvailable() ) {
         energyLossErr()->push_back( el.energyLossErr() );
      } else {
         energyLossErr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etCore.IsAvailable() ) {
         etCore()->push_back( el.etCore() );
      } else {
         etCore()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.energyLossType.IsAvailable() ) {
         energyLossType()->push_back( el.energyLossType() );
      } else {
         energyLossType()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.caloMuonIdTag.IsAvailable() ) {
         caloMuonIdTag()->push_back( el.caloMuonIdTag() );
      } else {
         caloMuonIdTag()->push_back( std::numeric_limits< unsigned short >::min() );
      }
      if( el.caloLRLikelihood.IsAvailable() ) {
         caloLRLikelihood()->push_back( el.caloLRLikelihood() );
      } else {
         caloLRLikelihood()->push_back( std::numeric_limits< double >::min() );
      }
      if( el.bestMatch.IsAvailable() ) {
         bestMatch()->push_back( el.bestMatch() );
      } else {
         bestMatch()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isStandAloneMuon.IsAvailable() ) {
         isStandAloneMuon()->push_back( el.isStandAloneMuon() );
      } else {
         isStandAloneMuon()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isCombinedMuon.IsAvailable() ) {
         isCombinedMuon()->push_back( el.isCombinedMuon() );
      } else {
         isCombinedMuon()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isLowPtReconstructedMuon.IsAvailable() ) {
         isLowPtReconstructedMuon()->push_back( el.isLowPtReconstructedMuon() );
      } else {
         isLowPtReconstructedMuon()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isSegmentTaggedMuon.IsAvailable() ) {
         isSegmentTaggedMuon()->push_back( el.isSegmentTaggedMuon() );
      } else {
         isSegmentTaggedMuon()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isCaloMuonId.IsAvailable() ) {
         isCaloMuonId()->push_back( el.isCaloMuonId() );
      } else {
         isCaloMuonId()->push_back( std::numeric_limits< int >::min() );
      }
// -- slimmed --       if( el.alsoFoundByLowPt.IsAvailable() ) {
// -- slimmed --          alsoFoundByLowPt()->push_back( el.alsoFoundByLowPt() );
// -- slimmed --       } else {
// -- slimmed --          alsoFoundByLowPt()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.alsoFoundByCaloMuonId.IsAvailable() ) {
// -- slimmed --          alsoFoundByCaloMuonId()->push_back( el.alsoFoundByCaloMuonId() );
// -- slimmed --       } else {
// -- slimmed --          alsoFoundByCaloMuonId()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.isSiliconAssociatedForwardMuon.IsAvailable() ) {
// -- slimmed --          isSiliconAssociatedForwardMuon()->push_back( el.isSiliconAssociatedForwardMuon() );
// -- slimmed --       } else {
// -- slimmed --          isSiliconAssociatedForwardMuon()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
      if( el.loose.IsAvailable() ) {
         loose()->push_back( el.loose() );
      } else {
         loose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.medium.IsAvailable() ) {
         medium()->push_back( el.medium() );
      } else {
         medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tight.IsAvailable() ) {
         tight()->push_back( el.tight() );
      } else {
         tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.d0_exPV.IsAvailable() ) {
         d0_exPV()->push_back( el.d0_exPV() );
      } else {
         d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.z0_exPV.IsAvailable() ) {
         z0_exPV()->push_back( el.z0_exPV() );
      } else {
         z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.phi_exPV.IsAvailable() ) {
         phi_exPV()->push_back( el.phi_exPV() );
      } else {
         phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.theta_exPV.IsAvailable() ) {
         theta_exPV()->push_back( el.theta_exPV() );
      } else {
         theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.qoverp_exPV.IsAvailable() ) {
         qoverp_exPV()->push_back( el.qoverp_exPV() );
      } else {
         qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cb_d0_exPV.IsAvailable() ) {
         cb_d0_exPV()->push_back( el.cb_d0_exPV() );
      } else {
         cb_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cb_z0_exPV.IsAvailable() ) {
         cb_z0_exPV()->push_back( el.cb_z0_exPV() );
      } else {
         cb_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cb_phi_exPV.IsAvailable() ) {
         cb_phi_exPV()->push_back( el.cb_phi_exPV() );
      } else {
         cb_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cb_theta_exPV.IsAvailable() ) {
         cb_theta_exPV()->push_back( el.cb_theta_exPV() );
      } else {
         cb_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cb_qoverp_exPV.IsAvailable() ) {
         cb_qoverp_exPV()->push_back( el.cb_qoverp_exPV() );
      } else {
         cb_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_d0_exPV.IsAvailable() ) {
         id_d0_exPV()->push_back( el.id_d0_exPV() );
      } else {
         id_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_z0_exPV.IsAvailable() ) {
         id_z0_exPV()->push_back( el.id_z0_exPV() );
      } else {
         id_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_phi_exPV.IsAvailable() ) {
         id_phi_exPV()->push_back( el.id_phi_exPV() );
      } else {
         id_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_theta_exPV.IsAvailable() ) {
         id_theta_exPV()->push_back( el.id_theta_exPV() );
      } else {
         id_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_qoverp_exPV.IsAvailable() ) {
         id_qoverp_exPV()->push_back( el.id_qoverp_exPV() );
      } else {
         id_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_d0_exPV.IsAvailable() ) {
         me_d0_exPV()->push_back( el.me_d0_exPV() );
      } else {
         me_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_z0_exPV.IsAvailable() ) {
         me_z0_exPV()->push_back( el.me_z0_exPV() );
      } else {
         me_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_phi_exPV.IsAvailable() ) {
         me_phi_exPV()->push_back( el.me_phi_exPV() );
      } else {
         me_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_theta_exPV.IsAvailable() ) {
         me_theta_exPV()->push_back( el.me_theta_exPV() );
      } else {
         me_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_qoverp_exPV.IsAvailable() ) {
         me_qoverp_exPV()->push_back( el.me_qoverp_exPV() );
      } else {
         me_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_d0_exPV.IsAvailable() ) {
         ie_d0_exPV()->push_back( el.ie_d0_exPV() );
      } else {
         ie_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_z0_exPV.IsAvailable() ) {
         ie_z0_exPV()->push_back( el.ie_z0_exPV() );
      } else {
         ie_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_phi_exPV.IsAvailable() ) {
         ie_phi_exPV()->push_back( el.ie_phi_exPV() );
      } else {
         ie_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_theta_exPV.IsAvailable() ) {
         ie_theta_exPV()->push_back( el.ie_theta_exPV() );
      } else {
         ie_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_qoverp_exPV.IsAvailable() ) {
         ie_qoverp_exPV()->push_back( el.ie_qoverp_exPV() );
      } else {
         ie_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_d0_exPV.IsAvailable() ) {
         cov_d0_exPV()->push_back( el.cov_d0_exPV() );
      } else {
         cov_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_z0_exPV.IsAvailable() ) {
         cov_z0_exPV()->push_back( el.cov_z0_exPV() );
      } else {
         cov_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_phi_exPV.IsAvailable() ) {
         cov_phi_exPV()->push_back( el.cov_phi_exPV() );
      } else {
         cov_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_theta_exPV.IsAvailable() ) {
         cov_theta_exPV()->push_back( el.cov_theta_exPV() );
      } else {
         cov_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_qoverp_exPV.IsAvailable() ) {
         cov_qoverp_exPV()->push_back( el.cov_qoverp_exPV() );
      } else {
         cov_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_d0_z0_exPV.IsAvailable() ) {
         cov_d0_z0_exPV()->push_back( el.cov_d0_z0_exPV() );
      } else {
         cov_d0_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_d0_phi_exPV.IsAvailable() ) {
         cov_d0_phi_exPV()->push_back( el.cov_d0_phi_exPV() );
      } else {
         cov_d0_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_d0_theta_exPV.IsAvailable() ) {
         cov_d0_theta_exPV()->push_back( el.cov_d0_theta_exPV() );
      } else {
         cov_d0_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_d0_qoverp_exPV.IsAvailable() ) {
         cov_d0_qoverp_exPV()->push_back( el.cov_d0_qoverp_exPV() );
      } else {
         cov_d0_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_z0_phi_exPV.IsAvailable() ) {
         cov_z0_phi_exPV()->push_back( el.cov_z0_phi_exPV() );
      } else {
         cov_z0_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_z0_theta_exPV.IsAvailable() ) {
         cov_z0_theta_exPV()->push_back( el.cov_z0_theta_exPV() );
      } else {
         cov_z0_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_z0_qoverp_exPV.IsAvailable() ) {
         cov_z0_qoverp_exPV()->push_back( el.cov_z0_qoverp_exPV() );
      } else {
         cov_z0_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_phi_theta_exPV.IsAvailable() ) {
         cov_phi_theta_exPV()->push_back( el.cov_phi_theta_exPV() );
      } else {
         cov_phi_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_phi_qoverp_exPV.IsAvailable() ) {
         cov_phi_qoverp_exPV()->push_back( el.cov_phi_qoverp_exPV() );
      } else {
         cov_phi_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_theta_qoverp_exPV.IsAvailable() ) {
         cov_theta_qoverp_exPV()->push_back( el.cov_theta_qoverp_exPV() );
      } else {
         cov_theta_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_d0_exPV.IsAvailable() ) {
         id_cov_d0_exPV()->push_back( el.id_cov_d0_exPV() );
      } else {
         id_cov_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_z0_exPV.IsAvailable() ) {
         id_cov_z0_exPV()->push_back( el.id_cov_z0_exPV() );
      } else {
         id_cov_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_phi_exPV.IsAvailable() ) {
         id_cov_phi_exPV()->push_back( el.id_cov_phi_exPV() );
      } else {
         id_cov_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_theta_exPV.IsAvailable() ) {
         id_cov_theta_exPV()->push_back( el.id_cov_theta_exPV() );
      } else {
         id_cov_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_qoverp_exPV.IsAvailable() ) {
         id_cov_qoverp_exPV()->push_back( el.id_cov_qoverp_exPV() );
      } else {
         id_cov_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_d0_z0_exPV.IsAvailable() ) {
         id_cov_d0_z0_exPV()->push_back( el.id_cov_d0_z0_exPV() );
      } else {
         id_cov_d0_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_d0_phi_exPV.IsAvailable() ) {
         id_cov_d0_phi_exPV()->push_back( el.id_cov_d0_phi_exPV() );
      } else {
         id_cov_d0_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_d0_theta_exPV.IsAvailable() ) {
         id_cov_d0_theta_exPV()->push_back( el.id_cov_d0_theta_exPV() );
      } else {
         id_cov_d0_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_d0_qoverp_exPV.IsAvailable() ) {
         id_cov_d0_qoverp_exPV()->push_back( el.id_cov_d0_qoverp_exPV() );
      } else {
         id_cov_d0_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_z0_phi_exPV.IsAvailable() ) {
         id_cov_z0_phi_exPV()->push_back( el.id_cov_z0_phi_exPV() );
      } else {
         id_cov_z0_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_z0_theta_exPV.IsAvailable() ) {
         id_cov_z0_theta_exPV()->push_back( el.id_cov_z0_theta_exPV() );
      } else {
         id_cov_z0_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_z0_qoverp_exPV.IsAvailable() ) {
         id_cov_z0_qoverp_exPV()->push_back( el.id_cov_z0_qoverp_exPV() );
      } else {
         id_cov_z0_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_phi_theta_exPV.IsAvailable() ) {
         id_cov_phi_theta_exPV()->push_back( el.id_cov_phi_theta_exPV() );
      } else {
         id_cov_phi_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_phi_qoverp_exPV.IsAvailable() ) {
         id_cov_phi_qoverp_exPV()->push_back( el.id_cov_phi_qoverp_exPV() );
      } else {
         id_cov_phi_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_cov_theta_qoverp_exPV.IsAvailable() ) {
         id_cov_theta_qoverp_exPV()->push_back( el.id_cov_theta_qoverp_exPV() );
      } else {
         id_cov_theta_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_d0_exPV.IsAvailable() ) {
         me_cov_d0_exPV()->push_back( el.me_cov_d0_exPV() );
      } else {
         me_cov_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_z0_exPV.IsAvailable() ) {
         me_cov_z0_exPV()->push_back( el.me_cov_z0_exPV() );
      } else {
         me_cov_z0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_phi_exPV.IsAvailable() ) {
         me_cov_phi_exPV()->push_back( el.me_cov_phi_exPV() );
      } else {
         me_cov_phi_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_theta_exPV.IsAvailable() ) {
         me_cov_theta_exPV()->push_back( el.me_cov_theta_exPV() );
      } else {
         me_cov_theta_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_qoverp_exPV.IsAvailable() ) {
         me_cov_qoverp_exPV()->push_back( el.me_cov_qoverp_exPV() );
      } else {
         me_cov_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ms_d0.IsAvailable() ) {
         ms_d0()->push_back( el.ms_d0() );
      } else {
         ms_d0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ms_z0.IsAvailable() ) {
         ms_z0()->push_back( el.ms_z0() );
      } else {
         ms_z0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ms_phi.IsAvailable() ) {
         ms_phi()->push_back( el.ms_phi() );
      } else {
         ms_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ms_theta.IsAvailable() ) {
         ms_theta()->push_back( el.ms_theta() );
      } else {
         ms_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ms_qoverp.IsAvailable() ) {
         ms_qoverp()->push_back( el.ms_qoverp() );
      } else {
         ms_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_d0.IsAvailable() ) {
         id_d0()->push_back( el.id_d0() );
      } else {
         id_d0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_z0.IsAvailable() ) {
         id_z0()->push_back( el.id_z0() );
      } else {
         id_z0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_phi.IsAvailable() ) {
         id_phi()->push_back( el.id_phi() );
      } else {
         id_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_theta.IsAvailable() ) {
         id_theta()->push_back( el.id_theta() );
      } else {
         id_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.id_qoverp.IsAvailable() ) {
         id_qoverp()->push_back( el.id_qoverp() );
      } else {
         id_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_d0.IsAvailable() ) {
         me_d0()->push_back( el.me_d0() );
      } else {
         me_d0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_z0.IsAvailable() ) {
         me_z0()->push_back( el.me_z0() );
      } else {
         me_z0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_phi.IsAvailable() ) {
         me_phi()->push_back( el.me_phi() );
      } else {
         me_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_theta.IsAvailable() ) {
         me_theta()->push_back( el.me_theta() );
      } else {
         me_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_qoverp.IsAvailable() ) {
         me_qoverp()->push_back( el.me_qoverp() );
      } else {
         me_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_d0.IsAvailable() ) {
         ie_d0()->push_back( el.ie_d0() );
      } else {
         ie_d0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_z0.IsAvailable() ) {
         ie_z0()->push_back( el.ie_z0() );
      } else {
         ie_z0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_phi.IsAvailable() ) {
         ie_phi()->push_back( el.ie_phi() );
      } else {
         ie_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_theta.IsAvailable() ) {
         ie_theta()->push_back( el.ie_theta() );
      } else {
         ie_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ie_qoverp.IsAvailable() ) {
         ie_qoverp()->push_back( el.ie_qoverp() );
      } else {
         ie_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nOutliersOnTrack.IsAvailable() ) {
         nOutliersOnTrack()->push_back( el.nOutliersOnTrack() );
      } else {
         nOutliersOnTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nBLHits.IsAvailable() ) {
         nBLHits()->push_back( el.nBLHits() );
      } else {
         nBLHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixHits.IsAvailable() ) {
         nPixHits()->push_back( el.nPixHits() );
      } else {
         nPixHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTHits.IsAvailable() ) {
         nSCTHits()->push_back( el.nSCTHits() );
      } else {
         nSCTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTRTHits.IsAvailable() ) {
         nTRTHits()->push_back( el.nTRTHits() );
      } else {
         nTRTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTRTHighTHits.IsAvailable() ) {
         nTRTHighTHits()->push_back( el.nTRTHighTHits() );
      } else {
         nTRTHighTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nBLSharedHits.IsAvailable() ) {
         nBLSharedHits()->push_back( el.nBLSharedHits() );
      } else {
         nBLSharedHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixSharedHits.IsAvailable() ) {
         nPixSharedHits()->push_back( el.nPixSharedHits() );
      } else {
         nPixSharedHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixHoles.IsAvailable() ) {
         nPixHoles()->push_back( el.nPixHoles() );
      } else {
         nPixHoles()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTSharedHits.IsAvailable() ) {
         nSCTSharedHits()->push_back( el.nSCTSharedHits() );
      } else {
         nSCTSharedHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTHoles.IsAvailable() ) {
         nSCTHoles()->push_back( el.nSCTHoles() );
      } else {
         nSCTHoles()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTRTOutliers.IsAvailable() ) {
         nTRTOutliers()->push_back( el.nTRTOutliers() );
      } else {
         nTRTOutliers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTRTHighTOutliers.IsAvailable() ) {
         nTRTHighTOutliers()->push_back( el.nTRTHighTOutliers() );
      } else {
         nTRTHighTOutliers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nGangedPixels.IsAvailable() ) {
         nGangedPixels()->push_back( el.nGangedPixels() );
      } else {
         nGangedPixels()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixelDeadSensors.IsAvailable() ) {
         nPixelDeadSensors()->push_back( el.nPixelDeadSensors() );
      } else {
         nPixelDeadSensors()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTDeadSensors.IsAvailable() ) {
         nSCTDeadSensors()->push_back( el.nSCTDeadSensors() );
      } else {
         nSCTDeadSensors()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTRTDeadStraws.IsAvailable() ) {
         nTRTDeadStraws()->push_back( el.nTRTDeadStraws() );
      } else {
         nTRTDeadStraws()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.expectBLayerHit.IsAvailable() ) {
         expectBLayerHit()->push_back( el.expectBLayerHit() );
      } else {
         expectBLayerHit()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTHits.IsAvailable() ) {
         nMDTHits()->push_back( el.nMDTHits() );
      } else {
         nMDTHits()->push_back( std::numeric_limits< int >::min() );
      }
// -- slimmed --       if( el.nMDTHoles.IsAvailable() ) {
// -- slimmed --          nMDTHoles()->push_back( el.nMDTHoles() );
// -- slimmed --       } else {
// -- slimmed --          nMDTHoles()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
      if( el.nCSCEtaHits.IsAvailable() ) {
         nCSCEtaHits()->push_back( el.nCSCEtaHits() );
      } else {
         nCSCEtaHits()->push_back( std::numeric_limits< int >::min() );
      }
// -- slimmed --       if( el.nCSCEtaHoles.IsAvailable() ) {
// -- slimmed --          nCSCEtaHoles()->push_back( el.nCSCEtaHoles() );
// -- slimmed --       } else {
// -- slimmed --          nCSCEtaHoles()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
      if( el.nCSCUnspoiledEtaHits.IsAvailable() ) {
         nCSCUnspoiledEtaHits()->push_back( el.nCSCUnspoiledEtaHits() );
      } else {
         nCSCUnspoiledEtaHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nCSCPhiHits.IsAvailable() ) {
         nCSCPhiHits()->push_back( el.nCSCPhiHits() );
      } else {
         nCSCPhiHits()->push_back( std::numeric_limits< int >::min() );
      }
// -- slimmed --       if( el.nCSCPhiHoles.IsAvailable() ) {
// -- slimmed --          nCSCPhiHoles()->push_back( el.nCSCPhiHoles() );
// -- slimmed --       } else {
// -- slimmed --          nCSCPhiHoles()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
      if( el.nRPCEtaHits.IsAvailable() ) {
         nRPCEtaHits()->push_back( el.nRPCEtaHits() );
      } else {
         nRPCEtaHits()->push_back( std::numeric_limits< int >::min() );
      }
// -- slimmed --       if( el.nRPCEtaHoles.IsAvailable() ) {
// -- slimmed --          nRPCEtaHoles()->push_back( el.nRPCEtaHoles() );
// -- slimmed --       } else {
// -- slimmed --          nRPCEtaHoles()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
      if( el.nRPCPhiHits.IsAvailable() ) {
         nRPCPhiHits()->push_back( el.nRPCPhiHits() );
      } else {
         nRPCPhiHits()->push_back( std::numeric_limits< int >::min() );
      }
// -- slimmed --       if( el.nRPCPhiHoles.IsAvailable() ) {
// -- slimmed --          nRPCPhiHoles()->push_back( el.nRPCPhiHoles() );
// -- slimmed --       } else {
// -- slimmed --          nRPCPhiHoles()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
      if( el.nTGCEtaHits.IsAvailable() ) {
         nTGCEtaHits()->push_back( el.nTGCEtaHits() );
      } else {
         nTGCEtaHits()->push_back( std::numeric_limits< int >::min() );
      }
// -- slimmed --       if( el.nTGCEtaHoles.IsAvailable() ) {
// -- slimmed --          nTGCEtaHoles()->push_back( el.nTGCEtaHoles() );
// -- slimmed --       } else {
// -- slimmed --          nTGCEtaHoles()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
      if( el.nTGCPhiHits.IsAvailable() ) {
         nTGCPhiHits()->push_back( el.nTGCPhiHits() );
      } else {
         nTGCPhiHits()->push_back( std::numeric_limits< int >::min() );
      }
// -- slimmed --       if( el.nTGCPhiHoles.IsAvailable() ) {
// -- slimmed --          nTGCPhiHoles()->push_back( el.nTGCPhiHoles() );
// -- slimmed --       } else {
// -- slimmed --          nTGCPhiHoles()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
      if( el.nprecisionLayers.IsAvailable() ) {
         nprecisionLayers()->push_back( el.nprecisionLayers() );
      } else {
         nprecisionLayers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nprecisionHoleLayers.IsAvailable() ) {
         nprecisionHoleLayers()->push_back( el.nprecisionHoleLayers() );
      } else {
         nprecisionHoleLayers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nphiLayers.IsAvailable() ) {
         nphiLayers()->push_back( el.nphiLayers() );
      } else {
         nphiLayers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.ntrigEtaLayers.IsAvailable() ) {
         ntrigEtaLayers()->push_back( el.ntrigEtaLayers() );
      } else {
         ntrigEtaLayers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nphiHoleLayers.IsAvailable() ) {
         nphiHoleLayers()->push_back( el.nphiHoleLayers() );
      } else {
         nphiHoleLayers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.ntrigEtaHoleLayers.IsAvailable() ) {
         ntrigEtaHoleLayers()->push_back( el.ntrigEtaHoleLayers() );
      } else {
         ntrigEtaHoleLayers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTBIHits.IsAvailable() ) {
         nMDTBIHits()->push_back( el.nMDTBIHits() );
      } else {
         nMDTBIHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTBMHits.IsAvailable() ) {
         nMDTBMHits()->push_back( el.nMDTBMHits() );
      } else {
         nMDTBMHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTBOHits.IsAvailable() ) {
         nMDTBOHits()->push_back( el.nMDTBOHits() );
      } else {
         nMDTBOHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTBEEHits.IsAvailable() ) {
         nMDTBEEHits()->push_back( el.nMDTBEEHits() );
      } else {
         nMDTBEEHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTBIS78Hits.IsAvailable() ) {
         nMDTBIS78Hits()->push_back( el.nMDTBIS78Hits() );
      } else {
         nMDTBIS78Hits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTEIHits.IsAvailable() ) {
         nMDTEIHits()->push_back( el.nMDTEIHits() );
      } else {
         nMDTEIHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTEMHits.IsAvailable() ) {
         nMDTEMHits()->push_back( el.nMDTEMHits() );
      } else {
         nMDTEMHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTEOHits.IsAvailable() ) {
         nMDTEOHits()->push_back( el.nMDTEOHits() );
      } else {
         nMDTEOHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nMDTEEHits.IsAvailable() ) {
         nMDTEEHits()->push_back( el.nMDTEEHits() );
      } else {
         nMDTEEHits()->push_back( std::numeric_limits< int >::min() );
      }
// -- slimmed --       if( el.nRPCLayer1EtaHits.IsAvailable() ) {
// -- slimmed --          nRPCLayer1EtaHits()->push_back( el.nRPCLayer1EtaHits() );
// -- slimmed --       } else {
// -- slimmed --          nRPCLayer1EtaHits()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.nRPCLayer2EtaHits.IsAvailable() ) {
// -- slimmed --          nRPCLayer2EtaHits()->push_back( el.nRPCLayer2EtaHits() );
// -- slimmed --       } else {
// -- slimmed --          nRPCLayer2EtaHits()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.nRPCLayer3EtaHits.IsAvailable() ) {
// -- slimmed --          nRPCLayer3EtaHits()->push_back( el.nRPCLayer3EtaHits() );
// -- slimmed --       } else {
// -- slimmed --          nRPCLayer3EtaHits()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.nRPCLayer1PhiHits.IsAvailable() ) {
// -- slimmed --          nRPCLayer1PhiHits()->push_back( el.nRPCLayer1PhiHits() );
// -- slimmed --       } else {
// -- slimmed --          nRPCLayer1PhiHits()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.nRPCLayer2PhiHits.IsAvailable() ) {
// -- slimmed --          nRPCLayer2PhiHits()->push_back( el.nRPCLayer2PhiHits() );
// -- slimmed --       } else {
// -- slimmed --          nRPCLayer2PhiHits()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.nRPCLayer3PhiHits.IsAvailable() ) {
// -- slimmed --          nRPCLayer3PhiHits()->push_back( el.nRPCLayer3PhiHits() );
// -- slimmed --       } else {
// -- slimmed --          nRPCLayer3PhiHits()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.nTGCLayer1EtaHits.IsAvailable() ) {
// -- slimmed --          nTGCLayer1EtaHits()->push_back( el.nTGCLayer1EtaHits() );
// -- slimmed --       } else {
// -- slimmed --          nTGCLayer1EtaHits()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.nTGCLayer2EtaHits.IsAvailable() ) {
// -- slimmed --          nTGCLayer2EtaHits()->push_back( el.nTGCLayer2EtaHits() );
// -- slimmed --       } else {
// -- slimmed --          nTGCLayer2EtaHits()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.nTGCLayer3EtaHits.IsAvailable() ) {
// -- slimmed --          nTGCLayer3EtaHits()->push_back( el.nTGCLayer3EtaHits() );
// -- slimmed --       } else {
// -- slimmed --          nTGCLayer3EtaHits()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.nTGCLayer4EtaHits.IsAvailable() ) {
// -- slimmed --          nTGCLayer4EtaHits()->push_back( el.nTGCLayer4EtaHits() );
// -- slimmed --       } else {
// -- slimmed --          nTGCLayer4EtaHits()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.nTGCLayer1PhiHits.IsAvailable() ) {
// -- slimmed --          nTGCLayer1PhiHits()->push_back( el.nTGCLayer1PhiHits() );
// -- slimmed --       } else {
// -- slimmed --          nTGCLayer1PhiHits()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.nTGCLayer2PhiHits.IsAvailable() ) {
// -- slimmed --          nTGCLayer2PhiHits()->push_back( el.nTGCLayer2PhiHits() );
// -- slimmed --       } else {
// -- slimmed --          nTGCLayer2PhiHits()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.nTGCLayer3PhiHits.IsAvailable() ) {
// -- slimmed --          nTGCLayer3PhiHits()->push_back( el.nTGCLayer3PhiHits() );
// -- slimmed --       } else {
// -- slimmed --          nTGCLayer3PhiHits()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.nTGCLayer4PhiHits.IsAvailable() ) {
// -- slimmed --          nTGCLayer4PhiHits()->push_back( el.nTGCLayer4PhiHits() );
// -- slimmed --       } else {
// -- slimmed --          nTGCLayer4PhiHits()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.barrelSectors.IsAvailable() ) {
// -- slimmed --          barrelSectors()->push_back( el.barrelSectors() );
// -- slimmed --       } else {
// -- slimmed --          barrelSectors()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.endcapSectors.IsAvailable() ) {
// -- slimmed --          endcapSectors()->push_back( el.endcapSectors() );
// -- slimmed --       } else {
// -- slimmed --          endcapSectors()->push_back( std::numeric_limits< int >::min() );
// -- slimmed --       }
      if( el.trackd0.IsAvailable() ) {
         trackd0()->push_back( el.trackd0() );
      } else {
         trackd0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackz0.IsAvailable() ) {
         trackz0()->push_back( el.trackz0() );
      } else {
         trackz0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackphi.IsAvailable() ) {
         trackphi()->push_back( el.trackphi() );
      } else {
         trackphi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tracktheta.IsAvailable() ) {
         tracktheta()->push_back( el.tracktheta() );
      } else {
         tracktheta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackqoverp.IsAvailable() ) {
         trackqoverp()->push_back( el.trackqoverp() );
      } else {
         trackqoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_d0.IsAvailable() ) {
         trackcov_d0()->push_back( el.trackcov_d0() );
      } else {
         trackcov_d0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_z0.IsAvailable() ) {
         trackcov_z0()->push_back( el.trackcov_z0() );
      } else {
         trackcov_z0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_phi.IsAvailable() ) {
         trackcov_phi()->push_back( el.trackcov_phi() );
      } else {
         trackcov_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_theta.IsAvailable() ) {
         trackcov_theta()->push_back( el.trackcov_theta() );
      } else {
         trackcov_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_qoverp.IsAvailable() ) {
         trackcov_qoverp()->push_back( el.trackcov_qoverp() );
      } else {
         trackcov_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_d0_z0.IsAvailable() ) {
         trackcov_d0_z0()->push_back( el.trackcov_d0_z0() );
      } else {
         trackcov_d0_z0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_d0_phi.IsAvailable() ) {
         trackcov_d0_phi()->push_back( el.trackcov_d0_phi() );
      } else {
         trackcov_d0_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_d0_theta.IsAvailable() ) {
         trackcov_d0_theta()->push_back( el.trackcov_d0_theta() );
      } else {
         trackcov_d0_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_d0_qoverp.IsAvailable() ) {
         trackcov_d0_qoverp()->push_back( el.trackcov_d0_qoverp() );
      } else {
         trackcov_d0_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_z0_phi.IsAvailable() ) {
         trackcov_z0_phi()->push_back( el.trackcov_z0_phi() );
      } else {
         trackcov_z0_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_z0_theta.IsAvailable() ) {
         trackcov_z0_theta()->push_back( el.trackcov_z0_theta() );
      } else {
         trackcov_z0_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_z0_qoverp.IsAvailable() ) {
         trackcov_z0_qoverp()->push_back( el.trackcov_z0_qoverp() );
      } else {
         trackcov_z0_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_phi_theta.IsAvailable() ) {
         trackcov_phi_theta()->push_back( el.trackcov_phi_theta() );
      } else {
         trackcov_phi_theta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_phi_qoverp.IsAvailable() ) {
         trackcov_phi_qoverp()->push_back( el.trackcov_phi_qoverp() );
      } else {
         trackcov_phi_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackcov_theta_qoverp.IsAvailable() ) {
         trackcov_theta_qoverp()->push_back( el.trackcov_theta_qoverp() );
      } else {
         trackcov_theta_qoverp()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.hastrack.IsAvailable() ) {
         hastrack()->push_back( el.hastrack() );
      } else {
         hastrack()->push_back( std::numeric_limits< int >::min() );
      }
// -- slimmed --       if( el.trackIPEstimate_d0_biasedpvunbiased.IsAvailable() ) {
// -- slimmed --          trackIPEstimate_d0_biasedpvunbiased()->push_back( el.trackIPEstimate_d0_biasedpvunbiased() );
// -- slimmed --       } else {
// -- slimmed --          trackIPEstimate_d0_biasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.trackIPEstimate_z0_biasedpvunbiased.IsAvailable() ) {
// -- slimmed --          trackIPEstimate_z0_biasedpvunbiased()->push_back( el.trackIPEstimate_z0_biasedpvunbiased() );
// -- slimmed --       } else {
// -- slimmed --          trackIPEstimate_z0_biasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.trackIPEstimate_sigd0_biasedpvunbiased.IsAvailable() ) {
// -- slimmed --          trackIPEstimate_sigd0_biasedpvunbiased()->push_back( el.trackIPEstimate_sigd0_biasedpvunbiased() );
// -- slimmed --       } else {
// -- slimmed --          trackIPEstimate_sigd0_biasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.trackIPEstimate_sigz0_biasedpvunbiased.IsAvailable() ) {
// -- slimmed --          trackIPEstimate_sigz0_biasedpvunbiased()->push_back( el.trackIPEstimate_sigz0_biasedpvunbiased() );
// -- slimmed --       } else {
// -- slimmed --          trackIPEstimate_sigz0_biasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.trackIPEstimate_d0_unbiasedpvunbiased.IsAvailable() ) {
// -- slimmed --          trackIPEstimate_d0_unbiasedpvunbiased()->push_back( el.trackIPEstimate_d0_unbiasedpvunbiased() );
// -- slimmed --       } else {
// -- slimmed --          trackIPEstimate_d0_unbiasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.trackIPEstimate_z0_unbiasedpvunbiased.IsAvailable() ) {
// -- slimmed --          trackIPEstimate_z0_unbiasedpvunbiased()->push_back( el.trackIPEstimate_z0_unbiasedpvunbiased() );
// -- slimmed --       } else {
// -- slimmed --          trackIPEstimate_z0_unbiasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.trackIPEstimate_sigd0_unbiasedpvunbiased.IsAvailable() ) {
// -- slimmed --          trackIPEstimate_sigd0_unbiasedpvunbiased()->push_back( el.trackIPEstimate_sigd0_unbiasedpvunbiased() );
// -- slimmed --       } else {
// -- slimmed --          trackIPEstimate_sigd0_unbiasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
// -- slimmed --       if( el.trackIPEstimate_sigz0_unbiasedpvunbiased.IsAvailable() ) {
// -- slimmed --          trackIPEstimate_sigz0_unbiasedpvunbiased()->push_back( el.trackIPEstimate_sigz0_unbiasedpvunbiased() );
// -- slimmed --       } else {
// -- slimmed --          trackIPEstimate_sigz0_unbiasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
// -- slimmed --       }
if (!is_data) {
      if( el.type.IsAvailable() ) {
         type()->push_back( el.type() );
      } else {
         type()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.origin.IsAvailable() ) {
         origin()->push_back( el.origin() );
      } else {
         origin()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_dr.IsAvailable() ) {
         truth_dr()->push_back( el.truth_dr() );
      } else {
         truth_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_E.IsAvailable() ) {
         truth_E()->push_back( el.truth_E() );
      } else {
         truth_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_pt.IsAvailable() ) {
         truth_pt()->push_back( el.truth_pt() );
      } else {
         truth_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_eta.IsAvailable() ) {
         truth_eta()->push_back( el.truth_eta() );
      } else {
         truth_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_phi.IsAvailable() ) {
         truth_phi()->push_back( el.truth_phi() );
      } else {
         truth_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.truth_type.IsAvailable() ) {
         truth_type()->push_back( el.truth_type() );
      } else {
         truth_type()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_status.IsAvailable() ) {
         truth_status()->push_back( el.truth_status() );
      } else {
         truth_status()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_barcode.IsAvailable() ) {
         truth_barcode()->push_back( el.truth_barcode() );
      } else {
         truth_barcode()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_mothertype.IsAvailable() ) {
         truth_mothertype()->push_back( el.truth_mothertype() );
      } else {
         truth_mothertype()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_motherbarcode.IsAvailable() ) {
         truth_motherbarcode()->push_back( el.truth_motherbarcode() );
      } else {
         truth_motherbarcode()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_matched.IsAvailable() ) {
         truth_matched()->push_back( el.truth_matched() );
      } else {
         truth_matched()->push_back( std::numeric_limits< int >::min() );
      }
} // end !is_data
      if( el.EFCB_index.IsAvailable() ) {
         EFCB_index()->push_back( el.EFCB_index() );
      } else {
         EFCB_index()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.EFMG_index.IsAvailable() ) {
         EFMG_index()->push_back( el.EFMG_index() );
      } else {
         EFMG_index()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.EFME_index.IsAvailable() ) {
         EFME_index()->push_back( el.EFME_index() );
      } else {
         EFME_index()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.ptcone20_trk500MeV.IsAvailable() ) {
         ptcone20_trk500MeV()->push_back( el.ptcone20_trk500MeV() );
      } else {
         ptcone20_trk500MeV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ptcone30_trk500MeV.IsAvailable() ) {
         ptcone30_trk500MeV()->push_back( el.ptcone30_trk500MeV() );
      } else {
         ptcone30_trk500MeV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ptcone40_trk500MeV.IsAvailable() ) {
         ptcone40_trk500MeV()->push_back( el.ptcone40_trk500MeV() );
      } else {
         ptcone40_trk500MeV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nucone20_trk500MeV.IsAvailable() ) {
         nucone20_trk500MeV()->push_back( el.nucone20_trk500MeV() );
      } else {
         nucone20_trk500MeV()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nucone30_trk500MeV.IsAvailable() ) {
         nucone30_trk500MeV()->push_back( el.nucone30_trk500MeV() );
      } else {
         nucone30_trk500MeV()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nucone40_trk500MeV.IsAvailable() ) {
         nucone40_trk500MeV()->push_back( el.nucone40_trk500MeV() );
      } else {
         nucone40_trk500MeV()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.ptcone20_trkelstyle.IsAvailable() ) {
         ptcone20_trkelstyle()->push_back( el.ptcone20_trkelstyle() );
      } else {
         ptcone20_trkelstyle()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ptcone30_trkelstyle.IsAvailable() ) {
         ptcone30_trkelstyle()->push_back( el.ptcone30_trkelstyle() );
      } else {
         ptcone30_trkelstyle()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ptcone40_trkelstyle.IsAvailable() ) {
         ptcone40_trkelstyle()->push_back( el.ptcone40_trkelstyle() );
      } else {
         ptcone40_trkelstyle()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nucone20_trkelstyle.IsAvailable() ) {
         nucone20_trkelstyle()->push_back( el.nucone20_trkelstyle() );
      } else {
         nucone20_trkelstyle()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nucone30_trkelstyle.IsAvailable() ) {
         nucone30_trkelstyle()->push_back( el.nucone30_trkelstyle() );
      } else {
         nucone30_trkelstyle()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nucone40_trkelstyle.IsAvailable() ) {
         nucone40_trkelstyle()->push_back( el.nucone40_trkelstyle() );
      } else {
         nucone40_trkelstyle()->push_back( std::numeric_limits< int >::min() );
      }
// -- slimmed --       if( el.MET_Simplified20_wpx.IsAvailable() ) {
// -- slimmed --          MET_Simplified20_wpx()->push_back( el.MET_Simplified20_wpx() );
// -- slimmed --       } else {
// -- slimmed --          MET_Simplified20_wpx()->push_back( vector<float>() );
// -- slimmed --       }
// -- slimmed --       if( el.MET_Simplified20_wpy.IsAvailable() ) {
// -- slimmed --          MET_Simplified20_wpy()->push_back( el.MET_Simplified20_wpy() );
// -- slimmed --       } else {
// -- slimmed --          MET_Simplified20_wpy()->push_back( vector<float>() );
// -- slimmed --       }
// -- slimmed --       if( el.MET_Simplified20_wet.IsAvailable() ) {
// -- slimmed --          MET_Simplified20_wet()->push_back( el.MET_Simplified20_wet() );
// -- slimmed --       } else {
// -- slimmed --          MET_Simplified20_wet()->push_back( vector<float>() );
// -- slimmed --       }
// -- slimmed --       if( el.MET_Simplified20_statusWord.IsAvailable() ) {
// -- slimmed --          MET_Simplified20_statusWord()->push_back( el.MET_Simplified20_statusWord() );
// -- slimmed --       } else {
// -- slimmed --          MET_Simplified20_statusWord()->push_back( vector<unsigned int>() );
// -- slimmed --       }
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
// -- slimmed -- // -- slimmed --       if( el.MET_STVF_statusWord.IsAvailable() ) {
// -- slimmed -- // -- slimmed --          MET_STVF_statusWord()->push_back( el.MET_STVF_statusWord() );
// -- slimmed --       } else {
// -- slimmed -- // -- slimmed --          MET_STVF_statusWord()->push_back( vector<unsigned int>() );
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
   MuonD3PDObjectElement& MuonD3PDObject::operator[]( size_t index ) {

      while( fProxies.size() <= index ) {
         fProxies.push_back( MuonD3PDObjectElement( fProxies.size(), *this , is_data ) );
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
   const MuonD3PDObjectElement& MuonD3PDObject::operator[]( size_t index ) const {

      while( fProxies.size() <= index ) {
         fProxies.push_back( MuonD3PDObjectElement( fProxies.size(), *this , is_data ) );
      }
      return fProxies[ index ];
   }

   /**
    * A convenience operator for adding an 'element' to this collection.
    *
    * @see Add
    * @param el The 'element' that should be added to the collection
    */
   MuonD3PDObject& MuonD3PDObject::operator+=( const MuonD3PDObjectElement& el ) {

      return this->Add( el );
   }

} // namespace D3PDReader
