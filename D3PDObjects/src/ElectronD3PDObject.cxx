// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <limits>

#include <TPRegexp.h>

#include "../include/ElectronD3PDObject.h"

ClassImp( D3PDReader::ElectronD3PDObjectElement )
ClassImp( D3PDReader::ElectronD3PDObject )

namespace D3PDReader {

   /**
    * This constructor can be used to create new proxy objects from scratch.
    * Since the constructor of such an object is quite complicated and
    * error prone, it is only visible to the parent class ElectronD3PDObject.
    */
   ElectronD3PDObjectElement::ElectronD3PDObjectElement( size_t index, const ElectronD3PDObject& parent , bool is_data )
      : E( parent.E, index, this ),
        Et( parent.Et, index, this ),
        pt( parent.pt, index, this ),
        m( parent.m, index, this ),
        eta( parent.eta, index, this ),
        phi( parent.phi, index, this ),
        px( parent.px, index, this ),
        py( parent.py, index, this ),
        pz( parent.pz, index, this ),
        charge( parent.charge, index, this ),
        author( parent.author, index, this ),
        isEM( parent.isEM, index, this ),
        isEMLoose( parent.isEMLoose, index, this ),
        isEMMedium( parent.isEMMedium, index, this ),
        isEMTight( parent.isEMTight, index, this ),
        OQ( parent.OQ, index, this ),
        convFlag( parent.convFlag, index, this ),
        isConv( parent.isConv, index, this ),
        nConv( parent.nConv, index, this ),
        nSingleTrackConv( parent.nSingleTrackConv, index, this ),
        nDoubleTrackConv( parent.nDoubleTrackConv, index, this ),
        maxEcell_time( parent.maxEcell_time, index, this ),
        maxEcell_energy( parent.maxEcell_energy, index, this ),
        maxEcell_onlId( parent.maxEcell_onlId, index, this ),
        maxEcell_gain( parent.maxEcell_gain, index, this ),
        maxEcell_x( parent.maxEcell_x, index, this ),
        maxEcell_y( parent.maxEcell_y, index, this ),
        maxEcell_z( parent.maxEcell_z, index, this ),
// MC only
        type( parent.type, index, this ),
        origin( parent.origin, index, this ),
        typebkg( parent.typebkg, index, this ),
        originbkg( parent.originbkg, index, this ),
        truth_E( parent.truth_E, index, this ),
        truth_pt( parent.truth_pt, index, this ),
        truth_eta( parent.truth_eta, index, this ),
        truth_phi( parent.truth_phi, index, this ),
        truth_type( parent.truth_type, index, this ),
        truth_status( parent.truth_status, index, this ),
        truth_barcode( parent.truth_barcode, index, this ),
        truth_mothertype( parent.truth_mothertype, index, this ),
        truth_motherbarcode( parent.truth_motherbarcode, index, this ),
        truth_hasHardBrem( parent.truth_hasHardBrem, index, this ),
        truth_index( parent.truth_index, index, this ),
        truth_matched( parent.truth_matched, index, this ),
// end MC only
        mediumWithoutTrack( parent.mediumWithoutTrack, index, this ),
        mediumIsoWithoutTrack( parent.mediumIsoWithoutTrack, index, this ),
        tightWithoutTrack( parent.tightWithoutTrack, index, this ),
        tightIsoWithoutTrack( parent.tightIsoWithoutTrack, index, this ),
        loose( parent.loose, index, this ),
        looseIso( parent.looseIso, index, this ),
        medium( parent.medium, index, this ),
        mediumIso( parent.mediumIso, index, this ),
        tight( parent.tight, index, this ),
        tightIso( parent.tightIso, index, this ),
        loosePP( parent.loosePP, index, this ),
        loosePPIso( parent.loosePPIso, index, this ),
        mediumPP( parent.mediumPP, index, this ),
        mediumPPIso( parent.mediumPPIso, index, this ),
        tightPP( parent.tightPP, index, this ),
        tightPPIso( parent.tightPPIso, index, this ),
        goodOQ( parent.goodOQ, index, this ),
        Ethad( parent.Ethad, index, this ),
        Ethad1( parent.Ethad1, index, this ),
        f1( parent.f1, index, this ),
        f1core( parent.f1core, index, this ),
        Emins1( parent.Emins1, index, this ),
        fside( parent.fside, index, this ),
        Emax2( parent.Emax2, index, this ),
        ws3( parent.ws3, index, this ),
        wstot( parent.wstot, index, this ),
        emaxs1( parent.emaxs1, index, this ),
        deltaEs( parent.deltaEs, index, this ),
        E233( parent.E233, index, this ),
        E237( parent.E237, index, this ),
        E277( parent.E277, index, this ),
        weta2( parent.weta2, index, this ),
        f3( parent.f3, index, this ),
        f3core( parent.f3core, index, this ),
        rphiallcalo( parent.rphiallcalo, index, this ),
        Etcone45( parent.Etcone45, index, this ),
        Etcone15( parent.Etcone15, index, this ),
        Etcone20( parent.Etcone20, index, this ),
        Etcone25( parent.Etcone25, index, this ),
        Etcone30( parent.Etcone30, index, this ),
        Etcone35( parent.Etcone35, index, this ),
        Etcone40( parent.Etcone40, index, this ),
        ptcone20( parent.ptcone20, index, this ),
        ptcone30( parent.ptcone30, index, this ),
        ptcone40( parent.ptcone40, index, this ),
        nucone20( parent.nucone20, index, this ),
        nucone30( parent.nucone30, index, this ),
        nucone40( parent.nucone40, index, this ),
        convanglematch( parent.convanglematch, index, this ),
        convtrackmatch( parent.convtrackmatch, index, this ),
        hasconv( parent.hasconv, index, this ),
        convvtxx( parent.convvtxx, index, this ),
        convvtxy( parent.convvtxy, index, this ),
        convvtxz( parent.convvtxz, index, this ),
        Rconv( parent.Rconv, index, this ),
        zconv( parent.zconv, index, this ),
        convvtxchi2( parent.convvtxchi2, index, this ),
        pt1conv( parent.pt1conv, index, this ),
        convtrk1nBLHits( parent.convtrk1nBLHits, index, this ),
        convtrk1nPixHits( parent.convtrk1nPixHits, index, this ),
        convtrk1nSCTHits( parent.convtrk1nSCTHits, index, this ),
        convtrk1nTRTHits( parent.convtrk1nTRTHits, index, this ),
        pt2conv( parent.pt2conv, index, this ),
        convtrk2nBLHits( parent.convtrk2nBLHits, index, this ),
        convtrk2nPixHits( parent.convtrk2nPixHits, index, this ),
        convtrk2nSCTHits( parent.convtrk2nSCTHits, index, this ),
        convtrk2nTRTHits( parent.convtrk2nTRTHits, index, this ),
        ptconv( parent.ptconv, index, this ),
        pzconv( parent.pzconv, index, this ),
        pos7( parent.pos7, index, this ),
        etacorrmag( parent.etacorrmag, index, this ),
        deltaeta1( parent.deltaeta1, index, this ),
        deltaeta2( parent.deltaeta2, index, this ),
        deltaphi2( parent.deltaphi2, index, this ),
        deltaphiRescaled( parent.deltaphiRescaled, index, this ),
        deltaPhiFromLast( parent.deltaPhiFromLast, index, this ),
        deltaPhiRot( parent.deltaPhiRot, index, this ),
        expectHitInBLayer( parent.expectHitInBLayer, index, this ),
        trackd0_physics( parent.trackd0_physics, index, this ),
        etaSampling1( parent.etaSampling1, index, this ),
        reta( parent.reta, index, this ),
        rphi( parent.rphi, index, this ),
        topoEtcone20( parent.topoEtcone20, index, this ),
        topoEtcone30( parent.topoEtcone30, index, this ),
        topoEtcone40( parent.topoEtcone40, index, this ),
        ptcone20_zpv05( parent.ptcone20_zpv05, index, this ),
        ptcone30_zpv05( parent.ptcone30_zpv05, index, this ),
        ptcone40_zpv05( parent.ptcone40_zpv05, index, this ),
        nucone20_zpv05( parent.nucone20_zpv05, index, this ),
        nucone30_zpv05( parent.nucone30_zpv05, index, this ),
        nucone40_zpv05( parent.nucone40_zpv05, index, this ),
        zvertex( parent.zvertex, index, this ),
        errz( parent.errz, index, this ),
        etap( parent.etap, index, this ),
        depth( parent.depth, index, this ),
        refittedTrack_n( parent.refittedTrack_n, index, this ),
        Es0( parent.Es0, index, this ),
        etas0( parent.etas0, index, this ),
        phis0( parent.phis0, index, this ),
        Es1( parent.Es1, index, this ),
        etas1( parent.etas1, index, this ),
        phis1( parent.phis1, index, this ),
        Es2( parent.Es2, index, this ),
        etas2( parent.etas2, index, this ),
        phis2( parent.phis2, index, this ),
        Es3( parent.Es3, index, this ),
        etas3( parent.etas3, index, this ),
        phis3( parent.phis3, index, this ),
        cl_E( parent.cl_E, index, this ),
        cl_pt( parent.cl_pt, index, this ),
        cl_eta( parent.cl_eta, index, this ),
        cl_phi( parent.cl_phi, index, this ),
        firstEdens( parent.firstEdens, index, this ),
        cellmaxfrac( parent.cellmaxfrac, index, this ),
        longitudinal( parent.longitudinal, index, this ),
        secondlambda( parent.secondlambda, index, this ),
        lateral( parent.lateral, index, this ),
        secondR( parent.secondR, index, this ),
        centerlambda( parent.centerlambda, index, this ),
        cl_time( parent.cl_time, index, this ),
        trackd0( parent.trackd0, index, this ),
        trackz0( parent.trackz0, index, this ),
        trackphi( parent.trackphi, index, this ),
        tracktheta( parent.tracktheta, index, this ),
        trackqoverp( parent.trackqoverp, index, this ),
        trackpt( parent.trackpt, index, this ),
        tracketa( parent.tracketa, index, this ),
        nBLHits( parent.nBLHits, index, this ),
        nPixHits( parent.nPixHits, index, this ),
        nSCTHits( parent.nSCTHits, index, this ),
        nTRTHits( parent.nTRTHits, index, this ),
        nTRTHighTHits( parent.nTRTHighTHits, index, this ),
        nTRTXenonHits( parent.nTRTXenonHits, index, this ),
        nPixHoles( parent.nPixHoles, index, this ),
        nSCTHoles( parent.nSCTHoles, index, this ),
        nTRTHoles( parent.nTRTHoles, index, this ),
        nPixelDeadSensors( parent.nPixelDeadSensors, index, this ),
        nSCTDeadSensors( parent.nSCTDeadSensors, index, this ),
        nBLSharedHits( parent.nBLSharedHits, index, this ),
        nPixSharedHits( parent.nPixSharedHits, index, this ),
        nSCTSharedHits( parent.nSCTSharedHits, index, this ),
        nBLayerSplitHits( parent.nBLayerSplitHits, index, this ),
        nPixSplitHits( parent.nPixSplitHits, index, this ),
        nBLayerOutliers( parent.nBLayerOutliers, index, this ),
        nPixelOutliers( parent.nPixelOutliers, index, this ),
        nSCTOutliers( parent.nSCTOutliers, index, this ),
        nTRTOutliers( parent.nTRTOutliers, index, this ),
        nTRTHighTOutliers( parent.nTRTHighTOutliers, index, this ),
        nContribPixelLayers( parent.nContribPixelLayers, index, this ),
        nGangedPixels( parent.nGangedPixels, index, this ),
        nGangedFlaggedFakes( parent.nGangedFlaggedFakes, index, this ),
        nPixelSpoiltHits( parent.nPixelSpoiltHits, index, this ),
        nSCTDoubleHoles( parent.nSCTDoubleHoles, index, this ),
        nSCTSpoiltHits( parent.nSCTSpoiltHits, index, this ),
        expectBLayerHit( parent.expectBLayerHit, index, this ),
        nSiHits( parent.nSiHits, index, this ),
        TRTHighTHitsRatio( parent.TRTHighTHitsRatio, index, this ),
        TRTHighTOutliersRatio( parent.TRTHighTOutliersRatio, index, this ),
        pixeldEdx( parent.pixeldEdx, index, this ),
        nGoodHitsPixeldEdx( parent.nGoodHitsPixeldEdx, index, this ),
        massPixeldEdx( parent.massPixeldEdx, index, this ),
        likelihoodsPixeldEdx( parent.likelihoodsPixeldEdx, index, this ),
        vertweight( parent.vertweight, index, this ),
        trackd0pv( parent.trackd0pv, index, this ),
        trackz0pv( parent.trackz0pv, index, this ),
        tracksigd0pv( parent.tracksigd0pv, index, this ),
        tracksigz0pv( parent.tracksigz0pv, index, this ),
        trackIPEstimate_d0_biasedpvunbiased( parent.trackIPEstimate_d0_biasedpvunbiased, index, this ),
        trackIPEstimate_z0_biasedpvunbiased( parent.trackIPEstimate_z0_biasedpvunbiased, index, this ),
        trackIPEstimate_sigd0_biasedpvunbiased( parent.trackIPEstimate_sigd0_biasedpvunbiased, index, this ),
        trackIPEstimate_sigz0_biasedpvunbiased( parent.trackIPEstimate_sigz0_biasedpvunbiased, index, this ),
        trackIPEstimate_d0_unbiasedpvunbiased( parent.trackIPEstimate_d0_unbiasedpvunbiased, index, this ),
        trackIPEstimate_z0_unbiasedpvunbiased( parent.trackIPEstimate_z0_unbiasedpvunbiased, index, this ),
        trackIPEstimate_sigd0_unbiasedpvunbiased( parent.trackIPEstimate_sigd0_unbiasedpvunbiased, index, this ),
        trackIPEstimate_sigz0_unbiasedpvunbiased( parent.trackIPEstimate_sigz0_unbiasedpvunbiased, index, this ),
        hastrack( parent.hastrack, index, this ),
        Etcone40_ED_corrected( parent.Etcone40_ED_corrected, index, this ),
        Etcone40_corrected( parent.Etcone40_corrected, index, this ),
        topoEtcone20_corrected( parent.topoEtcone20_corrected, index, this ),
        topoEtcone30_corrected( parent.topoEtcone30_corrected, index, this ),
        topoEtcone40_corrected( parent.topoEtcone40_corrected, index, this ),
        ED_median( parent.ED_median, index, this ),
        ED_sigma( parent.ED_sigma, index, this ),
        ED_Njets( parent.ED_Njets, index, this ),
        EF_dr( parent.EF_dr, index, this ),
        EF_index( parent.EF_index, index, this ),
        ptcone20_trk500MeV( parent.ptcone20_trk500MeV, index, this ),
        ptcone30_trk500MeV( parent.ptcone30_trk500MeV, index, this ),
        ptcone40_trk500MeV( parent.ptcone40_trk500MeV, index, this ),
        nucone20_trk500MeV( parent.nucone20_trk500MeV, index, this ),
        nucone30_trk500MeV( parent.nucone30_trk500MeV, index, this ),
        nucone40_trk500MeV( parent.nucone40_trk500MeV, index, this ),
        MET_Simplified20_wpx( parent.MET_Simplified20_wpx, index, this ),
        MET_Simplified20_wpy( parent.MET_Simplified20_wpy, index, this ),
        MET_Simplified20_wet( parent.MET_Simplified20_wet, index, this ),
        MET_Simplified20_statusWord( parent.MET_Simplified20_statusWord, index, this ),
        MET_Egamma10NoTau_wpx( parent.MET_Egamma10NoTau_wpx, index, this ),
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
        MET_STVF_statusWord( parent.MET_STVF_statusWord, index, this ) , 
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
   ElectronD3PDObjectElement::ElectronD3PDObjectElement( const ElectronD3PDObjectElement& parent , bool is_data )
      : TObject( parent ),
        E( parent.E ),
        Et( parent.Et ),
        pt( parent.pt ),
        m( parent.m ),
        eta( parent.eta ),
        phi( parent.phi ),
        px( parent.px ),
        py( parent.py ),
        pz( parent.pz ),
        charge( parent.charge ),
        author( parent.author ),
        isEM( parent.isEM ),
        isEMLoose( parent.isEMLoose ),
        isEMMedium( parent.isEMMedium ),
        isEMTight( parent.isEMTight ),
        OQ( parent.OQ ),
        convFlag( parent.convFlag ),
        isConv( parent.isConv ),
        nConv( parent.nConv ),
        nSingleTrackConv( parent.nSingleTrackConv ),
        nDoubleTrackConv( parent.nDoubleTrackConv ),
        maxEcell_time( parent.maxEcell_time ),
        maxEcell_energy( parent.maxEcell_energy ),
        maxEcell_onlId( parent.maxEcell_onlId ),
        maxEcell_gain( parent.maxEcell_gain ),
        maxEcell_x( parent.maxEcell_x ),
        maxEcell_y( parent.maxEcell_y ),
        maxEcell_z( parent.maxEcell_z ),
// MC only
        type( parent.type ),
        origin( parent.origin ),
        typebkg( parent.typebkg ),
        originbkg( parent.originbkg ),
        truth_E( parent.truth_E ),
        truth_pt( parent.truth_pt ),
        truth_eta( parent.truth_eta ),
        truth_phi( parent.truth_phi ),
        truth_type( parent.truth_type ),
        truth_status( parent.truth_status ),
        truth_barcode( parent.truth_barcode ),
        truth_mothertype( parent.truth_mothertype ),
        truth_motherbarcode( parent.truth_motherbarcode ),
        truth_hasHardBrem( parent.truth_hasHardBrem ),
        truth_index( parent.truth_index ),
        truth_matched( parent.truth_matched ),
// end MC only
        mediumWithoutTrack( parent.mediumWithoutTrack ),
        mediumIsoWithoutTrack( parent.mediumIsoWithoutTrack ),
        tightWithoutTrack( parent.tightWithoutTrack ),
        tightIsoWithoutTrack( parent.tightIsoWithoutTrack ),
        loose( parent.loose ),
        looseIso( parent.looseIso ),
        medium( parent.medium ),
        mediumIso( parent.mediumIso ),
        tight( parent.tight ),
        tightIso( parent.tightIso ),
        loosePP( parent.loosePP ),
        loosePPIso( parent.loosePPIso ),
        mediumPP( parent.mediumPP ),
        mediumPPIso( parent.mediumPPIso ),
        tightPP( parent.tightPP ),
        tightPPIso( parent.tightPPIso ),
        goodOQ( parent.goodOQ ),
        Ethad( parent.Ethad ),
        Ethad1( parent.Ethad1 ),
        f1( parent.f1 ),
        f1core( parent.f1core ),
        Emins1( parent.Emins1 ),
        fside( parent.fside ),
        Emax2( parent.Emax2 ),
        ws3( parent.ws3 ),
        wstot( parent.wstot ),
        emaxs1( parent.emaxs1 ),
        deltaEs( parent.deltaEs ),
        E233( parent.E233 ),
        E237( parent.E237 ),
        E277( parent.E277 ),
        weta2( parent.weta2 ),
        f3( parent.f3 ),
        f3core( parent.f3core ),
        rphiallcalo( parent.rphiallcalo ),
        Etcone45( parent.Etcone45 ),
        Etcone15( parent.Etcone15 ),
        Etcone20( parent.Etcone20 ),
        Etcone25( parent.Etcone25 ),
        Etcone30( parent.Etcone30 ),
        Etcone35( parent.Etcone35 ),
        Etcone40( parent.Etcone40 ),
        ptcone20( parent.ptcone20 ),
        ptcone30( parent.ptcone30 ),
        ptcone40( parent.ptcone40 ),
        nucone20( parent.nucone20 ),
        nucone30( parent.nucone30 ),
        nucone40( parent.nucone40 ),
        convanglematch( parent.convanglematch ),
        convtrackmatch( parent.convtrackmatch ),
        hasconv( parent.hasconv ),
        convvtxx( parent.convvtxx ),
        convvtxy( parent.convvtxy ),
        convvtxz( parent.convvtxz ),
        Rconv( parent.Rconv ),
        zconv( parent.zconv ),
        convvtxchi2( parent.convvtxchi2 ),
        pt1conv( parent.pt1conv ),
        convtrk1nBLHits( parent.convtrk1nBLHits ),
        convtrk1nPixHits( parent.convtrk1nPixHits ),
        convtrk1nSCTHits( parent.convtrk1nSCTHits ),
        convtrk1nTRTHits( parent.convtrk1nTRTHits ),
        pt2conv( parent.pt2conv ),
        convtrk2nBLHits( parent.convtrk2nBLHits ),
        convtrk2nPixHits( parent.convtrk2nPixHits ),
        convtrk2nSCTHits( parent.convtrk2nSCTHits ),
        convtrk2nTRTHits( parent.convtrk2nTRTHits ),
        ptconv( parent.ptconv ),
        pzconv( parent.pzconv ),
        pos7( parent.pos7 ),
        etacorrmag( parent.etacorrmag ),
        deltaeta1( parent.deltaeta1 ),
        deltaeta2( parent.deltaeta2 ),
        deltaphi2( parent.deltaphi2 ),
        deltaphiRescaled( parent.deltaphiRescaled ),
        deltaPhiFromLast( parent.deltaPhiFromLast ),
        deltaPhiRot( parent.deltaPhiRot ),
        expectHitInBLayer( parent.expectHitInBLayer ),
        trackd0_physics( parent.trackd0_physics ),
        etaSampling1( parent.etaSampling1 ),
        reta( parent.reta ),
        rphi( parent.rphi ),
        topoEtcone20( parent.topoEtcone20 ),
        topoEtcone30( parent.topoEtcone30 ),
        topoEtcone40( parent.topoEtcone40 ),
        ptcone20_zpv05( parent.ptcone20_zpv05 ),
        ptcone30_zpv05( parent.ptcone30_zpv05 ),
        ptcone40_zpv05( parent.ptcone40_zpv05 ),
        nucone20_zpv05( parent.nucone20_zpv05 ),
        nucone30_zpv05( parent.nucone30_zpv05 ),
        nucone40_zpv05( parent.nucone40_zpv05 ),
        zvertex( parent.zvertex ),
        errz( parent.errz ),
        etap( parent.etap ),
        depth( parent.depth ),
        refittedTrack_n( parent.refittedTrack_n ),
        Es0( parent.Es0 ),
        etas0( parent.etas0 ),
        phis0( parent.phis0 ),
        Es1( parent.Es1 ),
        etas1( parent.etas1 ),
        phis1( parent.phis1 ),
        Es2( parent.Es2 ),
        etas2( parent.etas2 ),
        phis2( parent.phis2 ),
        Es3( parent.Es3 ),
        etas3( parent.etas3 ),
        phis3( parent.phis3 ),
        cl_E( parent.cl_E ),
        cl_pt( parent.cl_pt ),
        cl_eta( parent.cl_eta ),
        cl_phi( parent.cl_phi ),
        firstEdens( parent.firstEdens ),
        cellmaxfrac( parent.cellmaxfrac ),
        longitudinal( parent.longitudinal ),
        secondlambda( parent.secondlambda ),
        lateral( parent.lateral ),
        secondR( parent.secondR ),
        centerlambda( parent.centerlambda ),
        cl_time( parent.cl_time ),
        trackd0( parent.trackd0 ),
        trackz0( parent.trackz0 ),
        trackphi( parent.trackphi ),
        tracktheta( parent.tracktheta ),
        trackqoverp( parent.trackqoverp ),
        trackpt( parent.trackpt ),
        tracketa( parent.tracketa ),
        nBLHits( parent.nBLHits ),
        nPixHits( parent.nPixHits ),
        nSCTHits( parent.nSCTHits ),
        nTRTHits( parent.nTRTHits ),
        nTRTHighTHits( parent.nTRTHighTHits ),
        nTRTXenonHits( parent.nTRTXenonHits ),
        nPixHoles( parent.nPixHoles ),
        nSCTHoles( parent.nSCTHoles ),
        nTRTHoles( parent.nTRTHoles ),
        nPixelDeadSensors( parent.nPixelDeadSensors ),
        nSCTDeadSensors( parent.nSCTDeadSensors ),
        nBLSharedHits( parent.nBLSharedHits ),
        nPixSharedHits( parent.nPixSharedHits ),
        nSCTSharedHits( parent.nSCTSharedHits ),
        nBLayerSplitHits( parent.nBLayerSplitHits ),
        nPixSplitHits( parent.nPixSplitHits ),
        nBLayerOutliers( parent.nBLayerOutliers ),
        nPixelOutliers( parent.nPixelOutliers ),
        nSCTOutliers( parent.nSCTOutliers ),
        nTRTOutliers( parent.nTRTOutliers ),
        nTRTHighTOutliers( parent.nTRTHighTOutliers ),
        nContribPixelLayers( parent.nContribPixelLayers ),
        nGangedPixels( parent.nGangedPixels ),
        nGangedFlaggedFakes( parent.nGangedFlaggedFakes ),
        nPixelSpoiltHits( parent.nPixelSpoiltHits ),
        nSCTDoubleHoles( parent.nSCTDoubleHoles ),
        nSCTSpoiltHits( parent.nSCTSpoiltHits ),
        expectBLayerHit( parent.expectBLayerHit ),
        nSiHits( parent.nSiHits ),
        TRTHighTHitsRatio( parent.TRTHighTHitsRatio ),
        TRTHighTOutliersRatio( parent.TRTHighTOutliersRatio ),
        pixeldEdx( parent.pixeldEdx ),
        nGoodHitsPixeldEdx( parent.nGoodHitsPixeldEdx ),
        massPixeldEdx( parent.massPixeldEdx ),
        likelihoodsPixeldEdx( parent.likelihoodsPixeldEdx ),
        vertweight( parent.vertweight ),
        trackd0pv( parent.trackd0pv ),
        trackz0pv( parent.trackz0pv ),
        tracksigd0pv( parent.tracksigd0pv ),
        tracksigz0pv( parent.tracksigz0pv ),
        trackIPEstimate_d0_biasedpvunbiased( parent.trackIPEstimate_d0_biasedpvunbiased ),
        trackIPEstimate_z0_biasedpvunbiased( parent.trackIPEstimate_z0_biasedpvunbiased ),
        trackIPEstimate_sigd0_biasedpvunbiased( parent.trackIPEstimate_sigd0_biasedpvunbiased ),
        trackIPEstimate_sigz0_biasedpvunbiased( parent.trackIPEstimate_sigz0_biasedpvunbiased ),
        trackIPEstimate_d0_unbiasedpvunbiased( parent.trackIPEstimate_d0_unbiasedpvunbiased ),
        trackIPEstimate_z0_unbiasedpvunbiased( parent.trackIPEstimate_z0_unbiasedpvunbiased ),
        trackIPEstimate_sigd0_unbiasedpvunbiased( parent.trackIPEstimate_sigd0_unbiasedpvunbiased ),
        trackIPEstimate_sigz0_unbiasedpvunbiased( parent.trackIPEstimate_sigz0_unbiasedpvunbiased ),
        hastrack( parent.hastrack ),
        Etcone40_ED_corrected( parent.Etcone40_ED_corrected ),
        Etcone40_corrected( parent.Etcone40_corrected ),
        topoEtcone20_corrected( parent.topoEtcone20_corrected ),
        topoEtcone30_corrected( parent.topoEtcone30_corrected ),
        topoEtcone40_corrected( parent.topoEtcone40_corrected ),
        ED_median( parent.ED_median ),
        ED_sigma( parent.ED_sigma ),
        ED_Njets( parent.ED_Njets ),
        EF_dr( parent.EF_dr ),
        EF_index( parent.EF_index ),
        ptcone20_trk500MeV( parent.ptcone20_trk500MeV ),
        ptcone30_trk500MeV( parent.ptcone30_trk500MeV ),
        ptcone40_trk500MeV( parent.ptcone40_trk500MeV ),
        nucone20_trk500MeV( parent.nucone20_trk500MeV ),
        nucone30_trk500MeV( parent.nucone30_trk500MeV ),
        nucone40_trk500MeV( parent.nucone40_trk500MeV ),
        MET_Simplified20_wpx( parent.MET_Simplified20_wpx ),
        MET_Simplified20_wpy( parent.MET_Simplified20_wpy ),
        MET_Simplified20_wet( parent.MET_Simplified20_wet ),
        MET_Simplified20_statusWord( parent.MET_Simplified20_statusWord ),
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
        MET_STVF_statusWord( parent.MET_STVF_statusWord ) , 
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
   ElectronD3PDObject::ElectronD3PDObject( const ::Long64_t& master, const char* prefix , bool is_data )
      : TObject(),
        n( this, ::TString( prefix ) + "n", &master ),
        E( this, ::TString( prefix ) + "E", &master ),
        Et( this, ::TString( prefix ) + "Et", &master ),
        pt( this, ::TString( prefix ) + "pt", &master ),
        m( this, ::TString( prefix ) + "m", &master ),
        eta( this, ::TString( prefix ) + "eta", &master ),
        phi( this, ::TString( prefix ) + "phi", &master ),
        px( this, ::TString( prefix ) + "px", &master ),
        py( this, ::TString( prefix ) + "py", &master ),
        pz( this, ::TString( prefix ) + "pz", &master ),
        charge( this, ::TString( prefix ) + "charge", &master ),
        author( this, ::TString( prefix ) + "author", &master ),
        isEM( this, ::TString( prefix ) + "isEM", &master ),
        isEMLoose( this, ::TString( prefix ) + "isEMLoose", &master ),
        isEMMedium( this, ::TString( prefix ) + "isEMMedium", &master ),
        isEMTight( this, ::TString( prefix ) + "isEMTight", &master ),
        OQ( this, ::TString( prefix ) + "OQ", &master ),
        convFlag( this, ::TString( prefix ) + "convFlag", &master ),
        isConv( this, ::TString( prefix ) + "isConv", &master ),
        nConv( this, ::TString( prefix ) + "nConv", &master ),
        nSingleTrackConv( this, ::TString( prefix ) + "nSingleTrackConv", &master ),
        nDoubleTrackConv( this, ::TString( prefix ) + "nDoubleTrackConv", &master ),
        maxEcell_time( this, ::TString( prefix ) + "maxEcell_time", &master ),
        maxEcell_energy( this, ::TString( prefix ) + "maxEcell_energy", &master ),
        maxEcell_onlId( this, ::TString( prefix ) + "maxEcell_onlId", &master ),
        maxEcell_gain( this, ::TString( prefix ) + "maxEcell_gain", &master ),
        maxEcell_x( this, ::TString( prefix ) + "maxEcell_x", &master ),
        maxEcell_y( this, ::TString( prefix ) + "maxEcell_y", &master ),
        maxEcell_z( this, ::TString( prefix ) + "maxEcell_z", &master ),
// MC only
        type( this, ::TString( prefix ) + "type", &master ),
        origin( this, ::TString( prefix ) + "origin", &master ),
        typebkg( this, ::TString( prefix ) + "typebkg", &master ),
        originbkg( this, ::TString( prefix ) + "originbkg", &master ),
        truth_E( this, ::TString( prefix ) + "truth_E", &master ),
        truth_pt( this, ::TString( prefix ) + "truth_pt", &master ),
        truth_eta( this, ::TString( prefix ) + "truth_eta", &master ),
        truth_phi( this, ::TString( prefix ) + "truth_phi", &master ),
        truth_type( this, ::TString( prefix ) + "truth_type", &master ),
        truth_status( this, ::TString( prefix ) + "truth_status", &master ),
        truth_barcode( this, ::TString( prefix ) + "truth_barcode", &master ),
        truth_mothertype( this, ::TString( prefix ) + "truth_mothertype", &master ),
        truth_motherbarcode( this, ::TString( prefix ) + "truth_motherbarcode", &master ),
        truth_hasHardBrem( this, ::TString( prefix ) + "truth_hasHardBrem", &master ),
        truth_index( this, ::TString( prefix ) + "truth_index", &master ),
        truth_matched( this, ::TString( prefix ) + "truth_matched", &master ),
// end MC only
        mediumWithoutTrack( this, ::TString( prefix ) + "mediumWithoutTrack", &master ),
        mediumIsoWithoutTrack( this, ::TString( prefix ) + "mediumIsoWithoutTrack", &master ),
        tightWithoutTrack( this, ::TString( prefix ) + "tightWithoutTrack", &master ),
        tightIsoWithoutTrack( this, ::TString( prefix ) + "tightIsoWithoutTrack", &master ),
        loose( this, ::TString( prefix ) + "loose", &master ),
        looseIso( this, ::TString( prefix ) + "looseIso", &master ),
        medium( this, ::TString( prefix ) + "medium", &master ),
        mediumIso( this, ::TString( prefix ) + "mediumIso", &master ),
        tight( this, ::TString( prefix ) + "tight", &master ),
        tightIso( this, ::TString( prefix ) + "tightIso", &master ),
        loosePP( this, ::TString( prefix ) + "loosePP", &master ),
        loosePPIso( this, ::TString( prefix ) + "loosePPIso", &master ),
        mediumPP( this, ::TString( prefix ) + "mediumPP", &master ),
        mediumPPIso( this, ::TString( prefix ) + "mediumPPIso", &master ),
        tightPP( this, ::TString( prefix ) + "tightPP", &master ),
        tightPPIso( this, ::TString( prefix ) + "tightPPIso", &master ),
        goodOQ( this, ::TString( prefix ) + "goodOQ", &master ),
        Ethad( this, ::TString( prefix ) + "Ethad", &master ),
        Ethad1( this, ::TString( prefix ) + "Ethad1", &master ),
        f1( this, ::TString( prefix ) + "f1", &master ),
        f1core( this, ::TString( prefix ) + "f1core", &master ),
        Emins1( this, ::TString( prefix ) + "Emins1", &master ),
        fside( this, ::TString( prefix ) + "fside", &master ),
        Emax2( this, ::TString( prefix ) + "Emax2", &master ),
        ws3( this, ::TString( prefix ) + "ws3", &master ),
        wstot( this, ::TString( prefix ) + "wstot", &master ),
        emaxs1( this, ::TString( prefix ) + "emaxs1", &master ),
        deltaEs( this, ::TString( prefix ) + "deltaEs", &master ),
        E233( this, ::TString( prefix ) + "E233", &master ),
        E237( this, ::TString( prefix ) + "E237", &master ),
        E277( this, ::TString( prefix ) + "E277", &master ),
        weta2( this, ::TString( prefix ) + "weta2", &master ),
        f3( this, ::TString( prefix ) + "f3", &master ),
        f3core( this, ::TString( prefix ) + "f3core", &master ),
        rphiallcalo( this, ::TString( prefix ) + "rphiallcalo", &master ),
        Etcone45( this, ::TString( prefix ) + "Etcone45", &master ),
        Etcone15( this, ::TString( prefix ) + "Etcone15", &master ),
        Etcone20( this, ::TString( prefix ) + "Etcone20", &master ),
        Etcone25( this, ::TString( prefix ) + "Etcone25", &master ),
        Etcone30( this, ::TString( prefix ) + "Etcone30", &master ),
        Etcone35( this, ::TString( prefix ) + "Etcone35", &master ),
        Etcone40( this, ::TString( prefix ) + "Etcone40", &master ),
        ptcone20( this, ::TString( prefix ) + "ptcone20", &master ),
        ptcone30( this, ::TString( prefix ) + "ptcone30", &master ),
        ptcone40( this, ::TString( prefix ) + "ptcone40", &master ),
        nucone20( this, ::TString( prefix ) + "nucone20", &master ),
        nucone30( this, ::TString( prefix ) + "nucone30", &master ),
        nucone40( this, ::TString( prefix ) + "nucone40", &master ),
        convanglematch( this, ::TString( prefix ) + "convanglematch", &master ),
        convtrackmatch( this, ::TString( prefix ) + "convtrackmatch", &master ),
        hasconv( this, ::TString( prefix ) + "hasconv", &master ),
        convvtxx( this, ::TString( prefix ) + "convvtxx", &master ),
        convvtxy( this, ::TString( prefix ) + "convvtxy", &master ),
        convvtxz( this, ::TString( prefix ) + "convvtxz", &master ),
        Rconv( this, ::TString( prefix ) + "Rconv", &master ),
        zconv( this, ::TString( prefix ) + "zconv", &master ),
        convvtxchi2( this, ::TString( prefix ) + "convvtxchi2", &master ),
        pt1conv( this, ::TString( prefix ) + "pt1conv", &master ),
        convtrk1nBLHits( this, ::TString( prefix ) + "convtrk1nBLHits", &master ),
        convtrk1nPixHits( this, ::TString( prefix ) + "convtrk1nPixHits", &master ),
        convtrk1nSCTHits( this, ::TString( prefix ) + "convtrk1nSCTHits", &master ),
        convtrk1nTRTHits( this, ::TString( prefix ) + "convtrk1nTRTHits", &master ),
        pt2conv( this, ::TString( prefix ) + "pt2conv", &master ),
        convtrk2nBLHits( this, ::TString( prefix ) + "convtrk2nBLHits", &master ),
        convtrk2nPixHits( this, ::TString( prefix ) + "convtrk2nPixHits", &master ),
        convtrk2nSCTHits( this, ::TString( prefix ) + "convtrk2nSCTHits", &master ),
        convtrk2nTRTHits( this, ::TString( prefix ) + "convtrk2nTRTHits", &master ),
        ptconv( this, ::TString( prefix ) + "ptconv", &master ),
        pzconv( this, ::TString( prefix ) + "pzconv", &master ),
        pos7( this, ::TString( prefix ) + "pos7", &master ),
        etacorrmag( this, ::TString( prefix ) + "etacorrmag", &master ),
        deltaeta1( this, ::TString( prefix ) + "deltaeta1", &master ),
        deltaeta2( this, ::TString( prefix ) + "deltaeta2", &master ),
        deltaphi2( this, ::TString( prefix ) + "deltaphi2", &master ),
        deltaphiRescaled( this, ::TString( prefix ) + "deltaphiRescaled", &master ),
        deltaPhiFromLast( this, ::TString( prefix ) + "deltaPhiFromLast", &master ),
        deltaPhiRot( this, ::TString( prefix ) + "deltaPhiRot", &master ),
        expectHitInBLayer( this, ::TString( prefix ) + "expectHitInBLayer", &master ),
        trackd0_physics( this, ::TString( prefix ) + "trackd0_physics", &master ),
        etaSampling1( this, ::TString( prefix ) + "etaSampling1", &master ),
        reta( this, ::TString( prefix ) + "reta", &master ),
        rphi( this, ::TString( prefix ) + "rphi", &master ),
        topoEtcone20( this, ::TString( prefix ) + "topoEtcone20", &master ),
        topoEtcone30( this, ::TString( prefix ) + "topoEtcone30", &master ),
        topoEtcone40( this, ::TString( prefix ) + "topoEtcone40", &master ),
        ptcone20_zpv05( this, ::TString( prefix ) + "ptcone20_zpv05", &master ),
        ptcone30_zpv05( this, ::TString( prefix ) + "ptcone30_zpv05", &master ),
        ptcone40_zpv05( this, ::TString( prefix ) + "ptcone40_zpv05", &master ),
        nucone20_zpv05( this, ::TString( prefix ) + "nucone20_zpv05", &master ),
        nucone30_zpv05( this, ::TString( prefix ) + "nucone30_zpv05", &master ),
        nucone40_zpv05( this, ::TString( prefix ) + "nucone40_zpv05", &master ),
        zvertex( this, ::TString( prefix ) + "zvertex", &master ),
        errz( this, ::TString( prefix ) + "errz", &master ),
        etap( this, ::TString( prefix ) + "etap", &master ),
        depth( this, ::TString( prefix ) + "depth", &master ),
        refittedTrack_n( this, ::TString( prefix ) + "refittedTrack_n", &master ),
        Es0( this, ::TString( prefix ) + "Es0", &master ),
        etas0( this, ::TString( prefix ) + "etas0", &master ),
        phis0( this, ::TString( prefix ) + "phis0", &master ),
        Es1( this, ::TString( prefix ) + "Es1", &master ),
        etas1( this, ::TString( prefix ) + "etas1", &master ),
        phis1( this, ::TString( prefix ) + "phis1", &master ),
        Es2( this, ::TString( prefix ) + "Es2", &master ),
        etas2( this, ::TString( prefix ) + "etas2", &master ),
        phis2( this, ::TString( prefix ) + "phis2", &master ),
        Es3( this, ::TString( prefix ) + "Es3", &master ),
        etas3( this, ::TString( prefix ) + "etas3", &master ),
        phis3( this, ::TString( prefix ) + "phis3", &master ),
        cl_E( this, ::TString( prefix ) + "cl_E", &master ),
        cl_pt( this, ::TString( prefix ) + "cl_pt", &master ),
        cl_eta( this, ::TString( prefix ) + "cl_eta", &master ),
        cl_phi( this, ::TString( prefix ) + "cl_phi", &master ),
        firstEdens( this, ::TString( prefix ) + "firstEdens", &master ),
        cellmaxfrac( this, ::TString( prefix ) + "cellmaxfrac", &master ),
        longitudinal( this, ::TString( prefix ) + "longitudinal", &master ),
        secondlambda( this, ::TString( prefix ) + "secondlambda", &master ),
        lateral( this, ::TString( prefix ) + "lateral", &master ),
        secondR( this, ::TString( prefix ) + "secondR", &master ),
        centerlambda( this, ::TString( prefix ) + "centerlambda", &master ),
        cl_time( this, ::TString( prefix ) + "cl_time", &master ),
        trackd0( this, ::TString( prefix ) + "trackd0", &master ),
        trackz0( this, ::TString( prefix ) + "trackz0", &master ),
        trackphi( this, ::TString( prefix ) + "trackphi", &master ),
        tracktheta( this, ::TString( prefix ) + "tracktheta", &master ),
        trackqoverp( this, ::TString( prefix ) + "trackqoverp", &master ),
        trackpt( this, ::TString( prefix ) + "trackpt", &master ),
        tracketa( this, ::TString( prefix ) + "tracketa", &master ),
        nBLHits( this, ::TString( prefix ) + "nBLHits", &master ),
        nPixHits( this, ::TString( prefix ) + "nPixHits", &master ),
        nSCTHits( this, ::TString( prefix ) + "nSCTHits", &master ),
        nTRTHits( this, ::TString( prefix ) + "nTRTHits", &master ),
        nTRTHighTHits( this, ::TString( prefix ) + "nTRTHighTHits", &master ),
        nTRTXenonHits( this, ::TString( prefix ) + "nTRTXenonHits", &master ),
        nPixHoles( this, ::TString( prefix ) + "nPixHoles", &master ),
        nSCTHoles( this, ::TString( prefix ) + "nSCTHoles", &master ),
        nTRTHoles( this, ::TString( prefix ) + "nTRTHoles", &master ),
        nPixelDeadSensors( this, ::TString( prefix ) + "nPixelDeadSensors", &master ),
        nSCTDeadSensors( this, ::TString( prefix ) + "nSCTDeadSensors", &master ),
        nBLSharedHits( this, ::TString( prefix ) + "nBLSharedHits", &master ),
        nPixSharedHits( this, ::TString( prefix ) + "nPixSharedHits", &master ),
        nSCTSharedHits( this, ::TString( prefix ) + "nSCTSharedHits", &master ),
        nBLayerSplitHits( this, ::TString( prefix ) + "nBLayerSplitHits", &master ),
        nPixSplitHits( this, ::TString( prefix ) + "nPixSplitHits", &master ),
        nBLayerOutliers( this, ::TString( prefix ) + "nBLayerOutliers", &master ),
        nPixelOutliers( this, ::TString( prefix ) + "nPixelOutliers", &master ),
        nSCTOutliers( this, ::TString( prefix ) + "nSCTOutliers", &master ),
        nTRTOutliers( this, ::TString( prefix ) + "nTRTOutliers", &master ),
        nTRTHighTOutliers( this, ::TString( prefix ) + "nTRTHighTOutliers", &master ),
        nContribPixelLayers( this, ::TString( prefix ) + "nContribPixelLayers", &master ),
        nGangedPixels( this, ::TString( prefix ) + "nGangedPixels", &master ),
        nGangedFlaggedFakes( this, ::TString( prefix ) + "nGangedFlaggedFakes", &master ),
        nPixelSpoiltHits( this, ::TString( prefix ) + "nPixelSpoiltHits", &master ),
        nSCTDoubleHoles( this, ::TString( prefix ) + "nSCTDoubleHoles", &master ),
        nSCTSpoiltHits( this, ::TString( prefix ) + "nSCTSpoiltHits", &master ),
        expectBLayerHit( this, ::TString( prefix ) + "expectBLayerHit", &master ),
        nSiHits( this, ::TString( prefix ) + "nSiHits", &master ),
        TRTHighTHitsRatio( this, ::TString( prefix ) + "TRTHighTHitsRatio", &master ),
        TRTHighTOutliersRatio( this, ::TString( prefix ) + "TRTHighTOutliersRatio", &master ),
        pixeldEdx( this, ::TString( prefix ) + "pixeldEdx", &master ),
        nGoodHitsPixeldEdx( this, ::TString( prefix ) + "nGoodHitsPixeldEdx", &master ),
        massPixeldEdx( this, ::TString( prefix ) + "massPixeldEdx", &master ),
        likelihoodsPixeldEdx( this, ::TString( prefix ) + "likelihoodsPixeldEdx", &master ),
        vertweight( this, ::TString( prefix ) + "vertweight", &master ),
        trackd0pv( this, ::TString( prefix ) + "trackd0pv", &master ),
        trackz0pv( this, ::TString( prefix ) + "trackz0pv", &master ),
        tracksigd0pv( this, ::TString( prefix ) + "tracksigd0pv", &master ),
        tracksigz0pv( this, ::TString( prefix ) + "tracksigz0pv", &master ),
        trackIPEstimate_d0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_d0_biasedpvunbiased", &master ),
        trackIPEstimate_z0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_z0_biasedpvunbiased", &master ),
        trackIPEstimate_sigd0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigd0_biasedpvunbiased", &master ),
        trackIPEstimate_sigz0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigz0_biasedpvunbiased", &master ),
        trackIPEstimate_d0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_d0_unbiasedpvunbiased", &master ),
        trackIPEstimate_z0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_z0_unbiasedpvunbiased", &master ),
        trackIPEstimate_sigd0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigd0_unbiasedpvunbiased", &master ),
        trackIPEstimate_sigz0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigz0_unbiasedpvunbiased", &master ),
        hastrack( this, ::TString( prefix ) + "hastrack", &master ),
        Etcone40_ED_corrected( this, ::TString( prefix ) + "Etcone40_ED_corrected", &master ),
        Etcone40_corrected( this, ::TString( prefix ) + "Etcone40_corrected", &master ),
        topoEtcone20_corrected( this, ::TString( prefix ) + "topoEtcone20_corrected", &master ),
        topoEtcone30_corrected( this, ::TString( prefix ) + "topoEtcone30_corrected", &master ),
        topoEtcone40_corrected( this, ::TString( prefix ) + "topoEtcone40_corrected", &master ),
        ED_median( this, ::TString( prefix ) + "ED_median", &master ),
        ED_sigma( this, ::TString( prefix ) + "ED_sigma", &master ),
        ED_Njets( this, ::TString( prefix ) + "ED_Njets", &master ),
        EF_dr( this, ::TString( prefix ) + "EF_dr", &master ),
        EF_index( this, ::TString( prefix ) + "EF_index", &master ),
        ptcone20_trk500MeV( this, ::TString( prefix ) + "ptcone20_trk500MeV", &master ),
        ptcone30_trk500MeV( this, ::TString( prefix ) + "ptcone30_trk500MeV", &master ),
        ptcone40_trk500MeV( this, ::TString( prefix ) + "ptcone40_trk500MeV", &master ),
        nucone20_trk500MeV( this, ::TString( prefix ) + "nucone20_trk500MeV", &master ),
        nucone30_trk500MeV( this, ::TString( prefix ) + "nucone30_trk500MeV", &master ),
        nucone40_trk500MeV( this, ::TString( prefix ) + "nucone40_trk500MeV", &master ),
        MET_Simplified20_wpx( this, ::TString( prefix ) + "MET_Simplified20_wpx", &master ),
        MET_Simplified20_wpy( this, ::TString( prefix ) + "MET_Simplified20_wpy", &master ),
        MET_Simplified20_wet( this, ::TString( prefix ) + "MET_Simplified20_wet", &master ),
        MET_Simplified20_statusWord( this, ::TString( prefix ) + "MET_Simplified20_statusWord", &master ),
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
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "n" ] = &n;
      fHandles[ "E" ] = &E;
      fHandles[ "Et" ] = &Et;
      fHandles[ "pt" ] = &pt;
      fHandles[ "m" ] = &m;
      fHandles[ "eta" ] = &eta;
      fHandles[ "phi" ] = &phi;
      fHandles[ "px" ] = &px;
      fHandles[ "py" ] = &py;
      fHandles[ "pz" ] = &pz;
      fHandles[ "charge" ] = &charge;
      fHandles[ "author" ] = &author;
      fHandles[ "isEM" ] = &isEM;
      fHandles[ "isEMLoose" ] = &isEMLoose;
      fHandles[ "isEMMedium" ] = &isEMMedium;
      fHandles[ "isEMTight" ] = &isEMTight;
      fHandles[ "OQ" ] = &OQ;
      fHandles[ "convFlag" ] = &convFlag;
      fHandles[ "isConv" ] = &isConv;
      fHandles[ "nConv" ] = &nConv;
      fHandles[ "nSingleTrackConv" ] = &nSingleTrackConv;
      fHandles[ "nDoubleTrackConv" ] = &nDoubleTrackConv;
      fHandles[ "maxEcell_time" ] = &maxEcell_time;
      fHandles[ "maxEcell_energy" ] = &maxEcell_energy;
      fHandles[ "maxEcell_onlId" ] = &maxEcell_onlId;
      fHandles[ "maxEcell_gain" ] = &maxEcell_gain;
      fHandles[ "maxEcell_x" ] = &maxEcell_x;
      fHandles[ "maxEcell_y" ] = &maxEcell_y;
      fHandles[ "maxEcell_z" ] = &maxEcell_z;
if (!is_data) {
      fHandles[ "type" ] = &type;
      fHandles[ "origin" ] = &origin;
      fHandles[ "typebkg" ] = &typebkg;
      fHandles[ "originbkg" ] = &originbkg;
      fHandles[ "truth_E" ] = &truth_E;
      fHandles[ "truth_pt" ] = &truth_pt;
      fHandles[ "truth_eta" ] = &truth_eta;
      fHandles[ "truth_phi" ] = &truth_phi;
      fHandles[ "truth_type" ] = &truth_type;
      fHandles[ "truth_status" ] = &truth_status;
      fHandles[ "truth_barcode" ] = &truth_barcode;
      fHandles[ "truth_mothertype" ] = &truth_mothertype;
      fHandles[ "truth_motherbarcode" ] = &truth_motherbarcode;
      fHandles[ "truth_hasHardBrem" ] = &truth_hasHardBrem;
      fHandles[ "truth_index" ] = &truth_index;
      fHandles[ "truth_matched" ] = &truth_matched;
} // end !is_data
      fHandles[ "mediumWithoutTrack" ] = &mediumWithoutTrack;
      fHandles[ "mediumIsoWithoutTrack" ] = &mediumIsoWithoutTrack;
      fHandles[ "tightWithoutTrack" ] = &tightWithoutTrack;
      fHandles[ "tightIsoWithoutTrack" ] = &tightIsoWithoutTrack;
      fHandles[ "loose" ] = &loose;
      fHandles[ "looseIso" ] = &looseIso;
      fHandles[ "medium" ] = &medium;
      fHandles[ "mediumIso" ] = &mediumIso;
      fHandles[ "tight" ] = &tight;
      fHandles[ "tightIso" ] = &tightIso;
      fHandles[ "loosePP" ] = &loosePP;
      fHandles[ "loosePPIso" ] = &loosePPIso;
      fHandles[ "mediumPP" ] = &mediumPP;
      fHandles[ "mediumPPIso" ] = &mediumPPIso;
      fHandles[ "tightPP" ] = &tightPP;
      fHandles[ "tightPPIso" ] = &tightPPIso;
      fHandles[ "goodOQ" ] = &goodOQ;
      fHandles[ "Ethad" ] = &Ethad;
      fHandles[ "Ethad1" ] = &Ethad1;
      fHandles[ "f1" ] = &f1;
      fHandles[ "f1core" ] = &f1core;
      fHandles[ "Emins1" ] = &Emins1;
      fHandles[ "fside" ] = &fside;
      fHandles[ "Emax2" ] = &Emax2;
      fHandles[ "ws3" ] = &ws3;
      fHandles[ "wstot" ] = &wstot;
      fHandles[ "emaxs1" ] = &emaxs1;
      fHandles[ "deltaEs" ] = &deltaEs;
      fHandles[ "E233" ] = &E233;
      fHandles[ "E237" ] = &E237;
      fHandles[ "E277" ] = &E277;
      fHandles[ "weta2" ] = &weta2;
      fHandles[ "f3" ] = &f3;
      fHandles[ "f3core" ] = &f3core;
      fHandles[ "rphiallcalo" ] = &rphiallcalo;
      fHandles[ "Etcone45" ] = &Etcone45;
      fHandles[ "Etcone15" ] = &Etcone15;
      fHandles[ "Etcone20" ] = &Etcone20;
      fHandles[ "Etcone25" ] = &Etcone25;
      fHandles[ "Etcone30" ] = &Etcone30;
      fHandles[ "Etcone35" ] = &Etcone35;
      fHandles[ "Etcone40" ] = &Etcone40;
      fHandles[ "ptcone20" ] = &ptcone20;
      fHandles[ "ptcone30" ] = &ptcone30;
      fHandles[ "ptcone40" ] = &ptcone40;
      fHandles[ "nucone20" ] = &nucone20;
      fHandles[ "nucone30" ] = &nucone30;
      fHandles[ "nucone40" ] = &nucone40;
      fHandles[ "convanglematch" ] = &convanglematch;
      fHandles[ "convtrackmatch" ] = &convtrackmatch;
      fHandles[ "hasconv" ] = &hasconv;
      fHandles[ "convvtxx" ] = &convvtxx;
      fHandles[ "convvtxy" ] = &convvtxy;
      fHandles[ "convvtxz" ] = &convvtxz;
      fHandles[ "Rconv" ] = &Rconv;
      fHandles[ "zconv" ] = &zconv;
      fHandles[ "convvtxchi2" ] = &convvtxchi2;
      fHandles[ "pt1conv" ] = &pt1conv;
      fHandles[ "convtrk1nBLHits" ] = &convtrk1nBLHits;
      fHandles[ "convtrk1nPixHits" ] = &convtrk1nPixHits;
      fHandles[ "convtrk1nSCTHits" ] = &convtrk1nSCTHits;
      fHandles[ "convtrk1nTRTHits" ] = &convtrk1nTRTHits;
      fHandles[ "pt2conv" ] = &pt2conv;
      fHandles[ "convtrk2nBLHits" ] = &convtrk2nBLHits;
      fHandles[ "convtrk2nPixHits" ] = &convtrk2nPixHits;
      fHandles[ "convtrk2nSCTHits" ] = &convtrk2nSCTHits;
      fHandles[ "convtrk2nTRTHits" ] = &convtrk2nTRTHits;
      fHandles[ "ptconv" ] = &ptconv;
      fHandles[ "pzconv" ] = &pzconv;
      fHandles[ "pos7" ] = &pos7;
      fHandles[ "etacorrmag" ] = &etacorrmag;
      fHandles[ "deltaeta1" ] = &deltaeta1;
      fHandles[ "deltaeta2" ] = &deltaeta2;
      fHandles[ "deltaphi2" ] = &deltaphi2;
      fHandles[ "deltaphiRescaled" ] = &deltaphiRescaled;
      fHandles[ "deltaPhiFromLast" ] = &deltaPhiFromLast;
      fHandles[ "deltaPhiRot" ] = &deltaPhiRot;
      fHandles[ "expectHitInBLayer" ] = &expectHitInBLayer;
      fHandles[ "trackd0_physics" ] = &trackd0_physics;
      fHandles[ "etaSampling1" ] = &etaSampling1;
      fHandles[ "reta" ] = &reta;
      fHandles[ "rphi" ] = &rphi;
      fHandles[ "topoEtcone20" ] = &topoEtcone20;
      fHandles[ "topoEtcone30" ] = &topoEtcone30;
      fHandles[ "topoEtcone40" ] = &topoEtcone40;
      fHandles[ "ptcone20_zpv05" ] = &ptcone20_zpv05;
      fHandles[ "ptcone30_zpv05" ] = &ptcone30_zpv05;
      fHandles[ "ptcone40_zpv05" ] = &ptcone40_zpv05;
      fHandles[ "nucone20_zpv05" ] = &nucone20_zpv05;
      fHandles[ "nucone30_zpv05" ] = &nucone30_zpv05;
      fHandles[ "nucone40_zpv05" ] = &nucone40_zpv05;
      fHandles[ "zvertex" ] = &zvertex;
      fHandles[ "errz" ] = &errz;
      fHandles[ "etap" ] = &etap;
      fHandles[ "depth" ] = &depth;
      fHandles[ "refittedTrack_n" ] = &refittedTrack_n;
      fHandles[ "Es0" ] = &Es0;
      fHandles[ "etas0" ] = &etas0;
      fHandles[ "phis0" ] = &phis0;
      fHandles[ "Es1" ] = &Es1;
      fHandles[ "etas1" ] = &etas1;
      fHandles[ "phis1" ] = &phis1;
      fHandles[ "Es2" ] = &Es2;
      fHandles[ "etas2" ] = &etas2;
      fHandles[ "phis2" ] = &phis2;
      fHandles[ "Es3" ] = &Es3;
      fHandles[ "etas3" ] = &etas3;
      fHandles[ "phis3" ] = &phis3;
      fHandles[ "cl_E" ] = &cl_E;
      fHandles[ "cl_pt" ] = &cl_pt;
      fHandles[ "cl_eta" ] = &cl_eta;
      fHandles[ "cl_phi" ] = &cl_phi;
      fHandles[ "firstEdens" ] = &firstEdens;
      fHandles[ "cellmaxfrac" ] = &cellmaxfrac;
      fHandles[ "longitudinal" ] = &longitudinal;
      fHandles[ "secondlambda" ] = &secondlambda;
      fHandles[ "lateral" ] = &lateral;
      fHandles[ "secondR" ] = &secondR;
      fHandles[ "centerlambda" ] = &centerlambda;
      fHandles[ "cl_time" ] = &cl_time;
      fHandles[ "trackd0" ] = &trackd0;
      fHandles[ "trackz0" ] = &trackz0;
      fHandles[ "trackphi" ] = &trackphi;
      fHandles[ "tracktheta" ] = &tracktheta;
      fHandles[ "trackqoverp" ] = &trackqoverp;
      fHandles[ "trackpt" ] = &trackpt;
      fHandles[ "tracketa" ] = &tracketa;
      fHandles[ "nBLHits" ] = &nBLHits;
      fHandles[ "nPixHits" ] = &nPixHits;
      fHandles[ "nSCTHits" ] = &nSCTHits;
      fHandles[ "nTRTHits" ] = &nTRTHits;
      fHandles[ "nTRTHighTHits" ] = &nTRTHighTHits;
      fHandles[ "nTRTXenonHits" ] = &nTRTXenonHits;
      fHandles[ "nPixHoles" ] = &nPixHoles;
      fHandles[ "nSCTHoles" ] = &nSCTHoles;
      fHandles[ "nTRTHoles" ] = &nTRTHoles;
      fHandles[ "nPixelDeadSensors" ] = &nPixelDeadSensors;
      fHandles[ "nSCTDeadSensors" ] = &nSCTDeadSensors;
      fHandles[ "nBLSharedHits" ] = &nBLSharedHits;
      fHandles[ "nPixSharedHits" ] = &nPixSharedHits;
      fHandles[ "nSCTSharedHits" ] = &nSCTSharedHits;
      fHandles[ "nBLayerSplitHits" ] = &nBLayerSplitHits;
      fHandles[ "nPixSplitHits" ] = &nPixSplitHits;
      fHandles[ "nBLayerOutliers" ] = &nBLayerOutliers;
      fHandles[ "nPixelOutliers" ] = &nPixelOutliers;
      fHandles[ "nSCTOutliers" ] = &nSCTOutliers;
      fHandles[ "nTRTOutliers" ] = &nTRTOutliers;
      fHandles[ "nTRTHighTOutliers" ] = &nTRTHighTOutliers;
      fHandles[ "nContribPixelLayers" ] = &nContribPixelLayers;
      fHandles[ "nGangedPixels" ] = &nGangedPixels;
      fHandles[ "nGangedFlaggedFakes" ] = &nGangedFlaggedFakes;
      fHandles[ "nPixelSpoiltHits" ] = &nPixelSpoiltHits;
      fHandles[ "nSCTDoubleHoles" ] = &nSCTDoubleHoles;
      fHandles[ "nSCTSpoiltHits" ] = &nSCTSpoiltHits;
      fHandles[ "expectBLayerHit" ] = &expectBLayerHit;
      fHandles[ "nSiHits" ] = &nSiHits;
      fHandles[ "TRTHighTHitsRatio" ] = &TRTHighTHitsRatio;
      fHandles[ "TRTHighTOutliersRatio" ] = &TRTHighTOutliersRatio;
      fHandles[ "pixeldEdx" ] = &pixeldEdx;
      fHandles[ "nGoodHitsPixeldEdx" ] = &nGoodHitsPixeldEdx;
      fHandles[ "massPixeldEdx" ] = &massPixeldEdx;
      fHandles[ "likelihoodsPixeldEdx" ] = &likelihoodsPixeldEdx;
      fHandles[ "vertweight" ] = &vertweight;
      fHandles[ "trackd0pv" ] = &trackd0pv;
      fHandles[ "trackz0pv" ] = &trackz0pv;
      fHandles[ "tracksigd0pv" ] = &tracksigd0pv;
      fHandles[ "tracksigz0pv" ] = &tracksigz0pv;
      fHandles[ "trackIPEstimate_d0_biasedpvunbiased" ] = &trackIPEstimate_d0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_z0_biasedpvunbiased" ] = &trackIPEstimate_z0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_sigd0_biasedpvunbiased" ] = &trackIPEstimate_sigd0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_sigz0_biasedpvunbiased" ] = &trackIPEstimate_sigz0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_d0_unbiasedpvunbiased" ] = &trackIPEstimate_d0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_z0_unbiasedpvunbiased" ] = &trackIPEstimate_z0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_sigd0_unbiasedpvunbiased" ] = &trackIPEstimate_sigd0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_sigz0_unbiasedpvunbiased" ] = &trackIPEstimate_sigz0_unbiasedpvunbiased;
      fHandles[ "hastrack" ] = &hastrack;
      fHandles[ "Etcone40_ED_corrected" ] = &Etcone40_ED_corrected;
      fHandles[ "Etcone40_corrected" ] = &Etcone40_corrected;
      fHandles[ "topoEtcone20_corrected" ] = &topoEtcone20_corrected;
      fHandles[ "topoEtcone30_corrected" ] = &topoEtcone30_corrected;
      fHandles[ "topoEtcone40_corrected" ] = &topoEtcone40_corrected;
      fHandles[ "ED_median" ] = &ED_median;
      fHandles[ "ED_sigma" ] = &ED_sigma;
      fHandles[ "ED_Njets" ] = &ED_Njets;
      fHandles[ "EF_dr" ] = &EF_dr;
      fHandles[ "EF_index" ] = &EF_index;
      fHandles[ "ptcone20_trk500MeV" ] = &ptcone20_trk500MeV;
      fHandles[ "ptcone30_trk500MeV" ] = &ptcone30_trk500MeV;
      fHandles[ "ptcone40_trk500MeV" ] = &ptcone40_trk500MeV;
      fHandles[ "nucone20_trk500MeV" ] = &nucone20_trk500MeV;
      fHandles[ "nucone30_trk500MeV" ] = &nucone30_trk500MeV;
      fHandles[ "nucone40_trk500MeV" ] = &nucone40_trk500MeV;
      fHandles[ "MET_Simplified20_wpx" ] = &MET_Simplified20_wpx;
      fHandles[ "MET_Simplified20_wpy" ] = &MET_Simplified20_wpy;
      fHandles[ "MET_Simplified20_wet" ] = &MET_Simplified20_wet;
      fHandles[ "MET_Simplified20_statusWord" ] = &MET_Simplified20_statusWord;
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
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   ElectronD3PDObject::ElectronD3PDObject( const char* prefix , bool is_data )
      : TObject(),
        n( this, ::TString( prefix ) + "n", 0 ),
        E( this, ::TString( prefix ) + "E", 0 ),
        Et( this, ::TString( prefix ) + "Et", 0 ),
        pt( this, ::TString( prefix ) + "pt", 0 ),
        m( this, ::TString( prefix ) + "m", 0 ),
        eta( this, ::TString( prefix ) + "eta", 0 ),
        phi( this, ::TString( prefix ) + "phi", 0 ),
        px( this, ::TString( prefix ) + "px", 0 ),
        py( this, ::TString( prefix ) + "py", 0 ),
        pz( this, ::TString( prefix ) + "pz", 0 ),
        charge( this, ::TString( prefix ) + "charge", 0 ),
        author( this, ::TString( prefix ) + "author", 0 ),
        isEM( this, ::TString( prefix ) + "isEM", 0 ),
        isEMLoose( this, ::TString( prefix ) + "isEMLoose", 0 ),
        isEMMedium( this, ::TString( prefix ) + "isEMMedium", 0 ),
        isEMTight( this, ::TString( prefix ) + "isEMTight", 0 ),
        OQ( this, ::TString( prefix ) + "OQ", 0 ),
        convFlag( this, ::TString( prefix ) + "convFlag", 0 ),
        isConv( this, ::TString( prefix ) + "isConv", 0 ),
        nConv( this, ::TString( prefix ) + "nConv", 0 ),
        nSingleTrackConv( this, ::TString( prefix ) + "nSingleTrackConv", 0 ),
        nDoubleTrackConv( this, ::TString( prefix ) + "nDoubleTrackConv", 0 ),
        maxEcell_time( this, ::TString( prefix ) + "maxEcell_time", 0 ),
        maxEcell_energy( this, ::TString( prefix ) + "maxEcell_energy", 0 ),
        maxEcell_onlId( this, ::TString( prefix ) + "maxEcell_onlId", 0 ),
        maxEcell_gain( this, ::TString( prefix ) + "maxEcell_gain", 0 ),
        maxEcell_x( this, ::TString( prefix ) + "maxEcell_x", 0 ),
        maxEcell_y( this, ::TString( prefix ) + "maxEcell_y", 0 ),
        maxEcell_z( this, ::TString( prefix ) + "maxEcell_z", 0 ),
// MC only
        type( this, ::TString( prefix ) + "type", 0 ),
        origin( this, ::TString( prefix ) + "origin", 0 ),
        typebkg( this, ::TString( prefix ) + "typebkg", 0 ),
        originbkg( this, ::TString( prefix ) + "originbkg", 0 ),
        truth_E( this, ::TString( prefix ) + "truth_E", 0 ),
        truth_pt( this, ::TString( prefix ) + "truth_pt", 0 ),
        truth_eta( this, ::TString( prefix ) + "truth_eta", 0 ),
        truth_phi( this, ::TString( prefix ) + "truth_phi", 0 ),
        truth_type( this, ::TString( prefix ) + "truth_type", 0 ),
        truth_status( this, ::TString( prefix ) + "truth_status", 0 ),
        truth_barcode( this, ::TString( prefix ) + "truth_barcode", 0 ),
        truth_mothertype( this, ::TString( prefix ) + "truth_mothertype", 0 ),
        truth_motherbarcode( this, ::TString( prefix ) + "truth_motherbarcode", 0 ),
        truth_hasHardBrem( this, ::TString( prefix ) + "truth_hasHardBrem", 0 ),
        truth_index( this, ::TString( prefix ) + "truth_index", 0 ),
        truth_matched( this, ::TString( prefix ) + "truth_matched", 0 ),
// end MC only
        mediumWithoutTrack( this, ::TString( prefix ) + "mediumWithoutTrack", 0 ),
        mediumIsoWithoutTrack( this, ::TString( prefix ) + "mediumIsoWithoutTrack", 0 ),
        tightWithoutTrack( this, ::TString( prefix ) + "tightWithoutTrack", 0 ),
        tightIsoWithoutTrack( this, ::TString( prefix ) + "tightIsoWithoutTrack", 0 ),
        loose( this, ::TString( prefix ) + "loose", 0 ),
        looseIso( this, ::TString( prefix ) + "looseIso", 0 ),
        medium( this, ::TString( prefix ) + "medium", 0 ),
        mediumIso( this, ::TString( prefix ) + "mediumIso", 0 ),
        tight( this, ::TString( prefix ) + "tight", 0 ),
        tightIso( this, ::TString( prefix ) + "tightIso", 0 ),
        loosePP( this, ::TString( prefix ) + "loosePP", 0 ),
        loosePPIso( this, ::TString( prefix ) + "loosePPIso", 0 ),
        mediumPP( this, ::TString( prefix ) + "mediumPP", 0 ),
        mediumPPIso( this, ::TString( prefix ) + "mediumPPIso", 0 ),
        tightPP( this, ::TString( prefix ) + "tightPP", 0 ),
        tightPPIso( this, ::TString( prefix ) + "tightPPIso", 0 ),
        goodOQ( this, ::TString( prefix ) + "goodOQ", 0 ),
        Ethad( this, ::TString( prefix ) + "Ethad", 0 ),
        Ethad1( this, ::TString( prefix ) + "Ethad1", 0 ),
        f1( this, ::TString( prefix ) + "f1", 0 ),
        f1core( this, ::TString( prefix ) + "f1core", 0 ),
        Emins1( this, ::TString( prefix ) + "Emins1", 0 ),
        fside( this, ::TString( prefix ) + "fside", 0 ),
        Emax2( this, ::TString( prefix ) + "Emax2", 0 ),
        ws3( this, ::TString( prefix ) + "ws3", 0 ),
        wstot( this, ::TString( prefix ) + "wstot", 0 ),
        emaxs1( this, ::TString( prefix ) + "emaxs1", 0 ),
        deltaEs( this, ::TString( prefix ) + "deltaEs", 0 ),
        E233( this, ::TString( prefix ) + "E233", 0 ),
        E237( this, ::TString( prefix ) + "E237", 0 ),
        E277( this, ::TString( prefix ) + "E277", 0 ),
        weta2( this, ::TString( prefix ) + "weta2", 0 ),
        f3( this, ::TString( prefix ) + "f3", 0 ),
        f3core( this, ::TString( prefix ) + "f3core", 0 ),
        rphiallcalo( this, ::TString( prefix ) + "rphiallcalo", 0 ),
        Etcone45( this, ::TString( prefix ) + "Etcone45", 0 ),
        Etcone15( this, ::TString( prefix ) + "Etcone15", 0 ),
        Etcone20( this, ::TString( prefix ) + "Etcone20", 0 ),
        Etcone25( this, ::TString( prefix ) + "Etcone25", 0 ),
        Etcone30( this, ::TString( prefix ) + "Etcone30", 0 ),
        Etcone35( this, ::TString( prefix ) + "Etcone35", 0 ),
        Etcone40( this, ::TString( prefix ) + "Etcone40", 0 ),
        ptcone20( this, ::TString( prefix ) + "ptcone20", 0 ),
        ptcone30( this, ::TString( prefix ) + "ptcone30", 0 ),
        ptcone40( this, ::TString( prefix ) + "ptcone40", 0 ),
        nucone20( this, ::TString( prefix ) + "nucone20", 0 ),
        nucone30( this, ::TString( prefix ) + "nucone30", 0 ),
        nucone40( this, ::TString( prefix ) + "nucone40", 0 ),
        convanglematch( this, ::TString( prefix ) + "convanglematch", 0 ),
        convtrackmatch( this, ::TString( prefix ) + "convtrackmatch", 0 ),
        hasconv( this, ::TString( prefix ) + "hasconv", 0 ),
        convvtxx( this, ::TString( prefix ) + "convvtxx", 0 ),
        convvtxy( this, ::TString( prefix ) + "convvtxy", 0 ),
        convvtxz( this, ::TString( prefix ) + "convvtxz", 0 ),
        Rconv( this, ::TString( prefix ) + "Rconv", 0 ),
        zconv( this, ::TString( prefix ) + "zconv", 0 ),
        convvtxchi2( this, ::TString( prefix ) + "convvtxchi2", 0 ),
        pt1conv( this, ::TString( prefix ) + "pt1conv", 0 ),
        convtrk1nBLHits( this, ::TString( prefix ) + "convtrk1nBLHits", 0 ),
        convtrk1nPixHits( this, ::TString( prefix ) + "convtrk1nPixHits", 0 ),
        convtrk1nSCTHits( this, ::TString( prefix ) + "convtrk1nSCTHits", 0 ),
        convtrk1nTRTHits( this, ::TString( prefix ) + "convtrk1nTRTHits", 0 ),
        pt2conv( this, ::TString( prefix ) + "pt2conv", 0 ),
        convtrk2nBLHits( this, ::TString( prefix ) + "convtrk2nBLHits", 0 ),
        convtrk2nPixHits( this, ::TString( prefix ) + "convtrk2nPixHits", 0 ),
        convtrk2nSCTHits( this, ::TString( prefix ) + "convtrk2nSCTHits", 0 ),
        convtrk2nTRTHits( this, ::TString( prefix ) + "convtrk2nTRTHits", 0 ),
        ptconv( this, ::TString( prefix ) + "ptconv", 0 ),
        pzconv( this, ::TString( prefix ) + "pzconv", 0 ),
        pos7( this, ::TString( prefix ) + "pos7", 0 ),
        etacorrmag( this, ::TString( prefix ) + "etacorrmag", 0 ),
        deltaeta1( this, ::TString( prefix ) + "deltaeta1", 0 ),
        deltaeta2( this, ::TString( prefix ) + "deltaeta2", 0 ),
        deltaphi2( this, ::TString( prefix ) + "deltaphi2", 0 ),
        deltaphiRescaled( this, ::TString( prefix ) + "deltaphiRescaled", 0 ),
        deltaPhiFromLast( this, ::TString( prefix ) + "deltaPhiFromLast", 0 ),
        deltaPhiRot( this, ::TString( prefix ) + "deltaPhiRot", 0 ),
        expectHitInBLayer( this, ::TString( prefix ) + "expectHitInBLayer", 0 ),
        trackd0_physics( this, ::TString( prefix ) + "trackd0_physics", 0 ),
        etaSampling1( this, ::TString( prefix ) + "etaSampling1", 0 ),
        reta( this, ::TString( prefix ) + "reta", 0 ),
        rphi( this, ::TString( prefix ) + "rphi", 0 ),
        topoEtcone20( this, ::TString( prefix ) + "topoEtcone20", 0 ),
        topoEtcone30( this, ::TString( prefix ) + "topoEtcone30", 0 ),
        topoEtcone40( this, ::TString( prefix ) + "topoEtcone40", 0 ),
        ptcone20_zpv05( this, ::TString( prefix ) + "ptcone20_zpv05", 0 ),
        ptcone30_zpv05( this, ::TString( prefix ) + "ptcone30_zpv05", 0 ),
        ptcone40_zpv05( this, ::TString( prefix ) + "ptcone40_zpv05", 0 ),
        nucone20_zpv05( this, ::TString( prefix ) + "nucone20_zpv05", 0 ),
        nucone30_zpv05( this, ::TString( prefix ) + "nucone30_zpv05", 0 ),
        nucone40_zpv05( this, ::TString( prefix ) + "nucone40_zpv05", 0 ),
        zvertex( this, ::TString( prefix ) + "zvertex", 0 ),
        errz( this, ::TString( prefix ) + "errz", 0 ),
        etap( this, ::TString( prefix ) + "etap", 0 ),
        depth( this, ::TString( prefix ) + "depth", 0 ),
        refittedTrack_n( this, ::TString( prefix ) + "refittedTrack_n", 0 ),
        Es0( this, ::TString( prefix ) + "Es0", 0 ),
        etas0( this, ::TString( prefix ) + "etas0", 0 ),
        phis0( this, ::TString( prefix ) + "phis0", 0 ),
        Es1( this, ::TString( prefix ) + "Es1", 0 ),
        etas1( this, ::TString( prefix ) + "etas1", 0 ),
        phis1( this, ::TString( prefix ) + "phis1", 0 ),
        Es2( this, ::TString( prefix ) + "Es2", 0 ),
        etas2( this, ::TString( prefix ) + "etas2", 0 ),
        phis2( this, ::TString( prefix ) + "phis2", 0 ),
        Es3( this, ::TString( prefix ) + "Es3", 0 ),
        etas3( this, ::TString( prefix ) + "etas3", 0 ),
        phis3( this, ::TString( prefix ) + "phis3", 0 ),
        cl_E( this, ::TString( prefix ) + "cl_E", 0 ),
        cl_pt( this, ::TString( prefix ) + "cl_pt", 0 ),
        cl_eta( this, ::TString( prefix ) + "cl_eta", 0 ),
        cl_phi( this, ::TString( prefix ) + "cl_phi", 0 ),
        firstEdens( this, ::TString( prefix ) + "firstEdens", 0 ),
        cellmaxfrac( this, ::TString( prefix ) + "cellmaxfrac", 0 ),
        longitudinal( this, ::TString( prefix ) + "longitudinal", 0 ),
        secondlambda( this, ::TString( prefix ) + "secondlambda", 0 ),
        lateral( this, ::TString( prefix ) + "lateral", 0 ),
        secondR( this, ::TString( prefix ) + "secondR", 0 ),
        centerlambda( this, ::TString( prefix ) + "centerlambda", 0 ),
        cl_time( this, ::TString( prefix ) + "cl_time", 0 ),
        trackd0( this, ::TString( prefix ) + "trackd0", 0 ),
        trackz0( this, ::TString( prefix ) + "trackz0", 0 ),
        trackphi( this, ::TString( prefix ) + "trackphi", 0 ),
        tracktheta( this, ::TString( prefix ) + "tracktheta", 0 ),
        trackqoverp( this, ::TString( prefix ) + "trackqoverp", 0 ),
        trackpt( this, ::TString( prefix ) + "trackpt", 0 ),
        tracketa( this, ::TString( prefix ) + "tracketa", 0 ),
        nBLHits( this, ::TString( prefix ) + "nBLHits", 0 ),
        nPixHits( this, ::TString( prefix ) + "nPixHits", 0 ),
        nSCTHits( this, ::TString( prefix ) + "nSCTHits", 0 ),
        nTRTHits( this, ::TString( prefix ) + "nTRTHits", 0 ),
        nTRTHighTHits( this, ::TString( prefix ) + "nTRTHighTHits", 0 ),
        nTRTXenonHits( this, ::TString( prefix ) + "nTRTXenonHits", 0 ),
        nPixHoles( this, ::TString( prefix ) + "nPixHoles", 0 ),
        nSCTHoles( this, ::TString( prefix ) + "nSCTHoles", 0 ),
        nTRTHoles( this, ::TString( prefix ) + "nTRTHoles", 0 ),
        nPixelDeadSensors( this, ::TString( prefix ) + "nPixelDeadSensors", 0 ),
        nSCTDeadSensors( this, ::TString( prefix ) + "nSCTDeadSensors", 0 ),
        nBLSharedHits( this, ::TString( prefix ) + "nBLSharedHits", 0 ),
        nPixSharedHits( this, ::TString( prefix ) + "nPixSharedHits", 0 ),
        nSCTSharedHits( this, ::TString( prefix ) + "nSCTSharedHits", 0 ),
        nBLayerSplitHits( this, ::TString( prefix ) + "nBLayerSplitHits", 0 ),
        nPixSplitHits( this, ::TString( prefix ) + "nPixSplitHits", 0 ),
        nBLayerOutliers( this, ::TString( prefix ) + "nBLayerOutliers", 0 ),
        nPixelOutliers( this, ::TString( prefix ) + "nPixelOutliers", 0 ),
        nSCTOutliers( this, ::TString( prefix ) + "nSCTOutliers", 0 ),
        nTRTOutliers( this, ::TString( prefix ) + "nTRTOutliers", 0 ),
        nTRTHighTOutliers( this, ::TString( prefix ) + "nTRTHighTOutliers", 0 ),
        nContribPixelLayers( this, ::TString( prefix ) + "nContribPixelLayers", 0 ),
        nGangedPixels( this, ::TString( prefix ) + "nGangedPixels", 0 ),
        nGangedFlaggedFakes( this, ::TString( prefix ) + "nGangedFlaggedFakes", 0 ),
        nPixelSpoiltHits( this, ::TString( prefix ) + "nPixelSpoiltHits", 0 ),
        nSCTDoubleHoles( this, ::TString( prefix ) + "nSCTDoubleHoles", 0 ),
        nSCTSpoiltHits( this, ::TString( prefix ) + "nSCTSpoiltHits", 0 ),
        expectBLayerHit( this, ::TString( prefix ) + "expectBLayerHit", 0 ),
        nSiHits( this, ::TString( prefix ) + "nSiHits", 0 ),
        TRTHighTHitsRatio( this, ::TString( prefix ) + "TRTHighTHitsRatio", 0 ),
        TRTHighTOutliersRatio( this, ::TString( prefix ) + "TRTHighTOutliersRatio", 0 ),
        pixeldEdx( this, ::TString( prefix ) + "pixeldEdx", 0 ),
        nGoodHitsPixeldEdx( this, ::TString( prefix ) + "nGoodHitsPixeldEdx", 0 ),
        massPixeldEdx( this, ::TString( prefix ) + "massPixeldEdx", 0 ),
        likelihoodsPixeldEdx( this, ::TString( prefix ) + "likelihoodsPixeldEdx", 0 ),
        vertweight( this, ::TString( prefix ) + "vertweight", 0 ),
        trackd0pv( this, ::TString( prefix ) + "trackd0pv", 0 ),
        trackz0pv( this, ::TString( prefix ) + "trackz0pv", 0 ),
        tracksigd0pv( this, ::TString( prefix ) + "tracksigd0pv", 0 ),
        tracksigz0pv( this, ::TString( prefix ) + "tracksigz0pv", 0 ),
        trackIPEstimate_d0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_d0_biasedpvunbiased", 0 ),
        trackIPEstimate_z0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_z0_biasedpvunbiased", 0 ),
        trackIPEstimate_sigd0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigd0_biasedpvunbiased", 0 ),
        trackIPEstimate_sigz0_biasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigz0_biasedpvunbiased", 0 ),
        trackIPEstimate_d0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_d0_unbiasedpvunbiased", 0 ),
        trackIPEstimate_z0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_z0_unbiasedpvunbiased", 0 ),
        trackIPEstimate_sigd0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigd0_unbiasedpvunbiased", 0 ),
        trackIPEstimate_sigz0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigz0_unbiasedpvunbiased", 0 ),
        hastrack( this, ::TString( prefix ) + "hastrack", 0 ),
        Etcone40_ED_corrected( this, ::TString( prefix ) + "Etcone40_ED_corrected", 0 ),
        Etcone40_corrected( this, ::TString( prefix ) + "Etcone40_corrected", 0 ),
        topoEtcone20_corrected( this, ::TString( prefix ) + "topoEtcone20_corrected", 0 ),
        topoEtcone30_corrected( this, ::TString( prefix ) + "topoEtcone30_corrected", 0 ),
        topoEtcone40_corrected( this, ::TString( prefix ) + "topoEtcone40_corrected", 0 ),
        ED_median( this, ::TString( prefix ) + "ED_median", 0 ),
        ED_sigma( this, ::TString( prefix ) + "ED_sigma", 0 ),
        ED_Njets( this, ::TString( prefix ) + "ED_Njets", 0 ),
        EF_dr( this, ::TString( prefix ) + "EF_dr", 0 ),
        EF_index( this, ::TString( prefix ) + "EF_index", 0 ),
        ptcone20_trk500MeV( this, ::TString( prefix ) + "ptcone20_trk500MeV", 0 ),
        ptcone30_trk500MeV( this, ::TString( prefix ) + "ptcone30_trk500MeV", 0 ),
        ptcone40_trk500MeV( this, ::TString( prefix ) + "ptcone40_trk500MeV", 0 ),
        nucone20_trk500MeV( this, ::TString( prefix ) + "nucone20_trk500MeV", 0 ),
        nucone30_trk500MeV( this, ::TString( prefix ) + "nucone30_trk500MeV", 0 ),
        nucone40_trk500MeV( this, ::TString( prefix ) + "nucone40_trk500MeV", 0 ),
        MET_Simplified20_wpx( this, ::TString( prefix ) + "MET_Simplified20_wpx", 0 ),
        MET_Simplified20_wpy( this, ::TString( prefix ) + "MET_Simplified20_wpy", 0 ),
        MET_Simplified20_wet( this, ::TString( prefix ) + "MET_Simplified20_wet", 0 ),
        MET_Simplified20_statusWord( this, ::TString( prefix ) + "MET_Simplified20_statusWord", 0 ),
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
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "n" ] = &n;
      fHandles[ "E" ] = &E;
      fHandles[ "Et" ] = &Et;
      fHandles[ "pt" ] = &pt;
      fHandles[ "m" ] = &m;
      fHandles[ "eta" ] = &eta;
      fHandles[ "phi" ] = &phi;
      fHandles[ "px" ] = &px;
      fHandles[ "py" ] = &py;
      fHandles[ "pz" ] = &pz;
      fHandles[ "charge" ] = &charge;
      fHandles[ "author" ] = &author;
      fHandles[ "isEM" ] = &isEM;
      fHandles[ "isEMLoose" ] = &isEMLoose;
      fHandles[ "isEMMedium" ] = &isEMMedium;
      fHandles[ "isEMTight" ] = &isEMTight;
      fHandles[ "OQ" ] = &OQ;
      fHandles[ "convFlag" ] = &convFlag;
      fHandles[ "isConv" ] = &isConv;
      fHandles[ "nConv" ] = &nConv;
      fHandles[ "nSingleTrackConv" ] = &nSingleTrackConv;
      fHandles[ "nDoubleTrackConv" ] = &nDoubleTrackConv;
      fHandles[ "maxEcell_time" ] = &maxEcell_time;
      fHandles[ "maxEcell_energy" ] = &maxEcell_energy;
      fHandles[ "maxEcell_onlId" ] = &maxEcell_onlId;
      fHandles[ "maxEcell_gain" ] = &maxEcell_gain;
      fHandles[ "maxEcell_x" ] = &maxEcell_x;
      fHandles[ "maxEcell_y" ] = &maxEcell_y;
      fHandles[ "maxEcell_z" ] = &maxEcell_z;
if (!is_data) {
      fHandles[ "type" ] = &type;
      fHandles[ "origin" ] = &origin;
      fHandles[ "typebkg" ] = &typebkg;
      fHandles[ "originbkg" ] = &originbkg;
      fHandles[ "truth_E" ] = &truth_E;
      fHandles[ "truth_pt" ] = &truth_pt;
      fHandles[ "truth_eta" ] = &truth_eta;
      fHandles[ "truth_phi" ] = &truth_phi;
      fHandles[ "truth_type" ] = &truth_type;
      fHandles[ "truth_status" ] = &truth_status;
      fHandles[ "truth_barcode" ] = &truth_barcode;
      fHandles[ "truth_mothertype" ] = &truth_mothertype;
      fHandles[ "truth_motherbarcode" ] = &truth_motherbarcode;
      fHandles[ "truth_hasHardBrem" ] = &truth_hasHardBrem;
      fHandles[ "truth_index" ] = &truth_index;
      fHandles[ "truth_matched" ] = &truth_matched;
} // end !is_data
      fHandles[ "mediumWithoutTrack" ] = &mediumWithoutTrack;
      fHandles[ "mediumIsoWithoutTrack" ] = &mediumIsoWithoutTrack;
      fHandles[ "tightWithoutTrack" ] = &tightWithoutTrack;
      fHandles[ "tightIsoWithoutTrack" ] = &tightIsoWithoutTrack;
      fHandles[ "loose" ] = &loose;
      fHandles[ "looseIso" ] = &looseIso;
      fHandles[ "medium" ] = &medium;
      fHandles[ "mediumIso" ] = &mediumIso;
      fHandles[ "tight" ] = &tight;
      fHandles[ "tightIso" ] = &tightIso;
      fHandles[ "loosePP" ] = &loosePP;
      fHandles[ "loosePPIso" ] = &loosePPIso;
      fHandles[ "mediumPP" ] = &mediumPP;
      fHandles[ "mediumPPIso" ] = &mediumPPIso;
      fHandles[ "tightPP" ] = &tightPP;
      fHandles[ "tightPPIso" ] = &tightPPIso;
      fHandles[ "goodOQ" ] = &goodOQ;
      fHandles[ "Ethad" ] = &Ethad;
      fHandles[ "Ethad1" ] = &Ethad1;
      fHandles[ "f1" ] = &f1;
      fHandles[ "f1core" ] = &f1core;
      fHandles[ "Emins1" ] = &Emins1;
      fHandles[ "fside" ] = &fside;
      fHandles[ "Emax2" ] = &Emax2;
      fHandles[ "ws3" ] = &ws3;
      fHandles[ "wstot" ] = &wstot;
      fHandles[ "emaxs1" ] = &emaxs1;
      fHandles[ "deltaEs" ] = &deltaEs;
      fHandles[ "E233" ] = &E233;
      fHandles[ "E237" ] = &E237;
      fHandles[ "E277" ] = &E277;
      fHandles[ "weta2" ] = &weta2;
      fHandles[ "f3" ] = &f3;
      fHandles[ "f3core" ] = &f3core;
      fHandles[ "rphiallcalo" ] = &rphiallcalo;
      fHandles[ "Etcone45" ] = &Etcone45;
      fHandles[ "Etcone15" ] = &Etcone15;
      fHandles[ "Etcone20" ] = &Etcone20;
      fHandles[ "Etcone25" ] = &Etcone25;
      fHandles[ "Etcone30" ] = &Etcone30;
      fHandles[ "Etcone35" ] = &Etcone35;
      fHandles[ "Etcone40" ] = &Etcone40;
      fHandles[ "ptcone20" ] = &ptcone20;
      fHandles[ "ptcone30" ] = &ptcone30;
      fHandles[ "ptcone40" ] = &ptcone40;
      fHandles[ "nucone20" ] = &nucone20;
      fHandles[ "nucone30" ] = &nucone30;
      fHandles[ "nucone40" ] = &nucone40;
      fHandles[ "convanglematch" ] = &convanglematch;
      fHandles[ "convtrackmatch" ] = &convtrackmatch;
      fHandles[ "hasconv" ] = &hasconv;
      fHandles[ "convvtxx" ] = &convvtxx;
      fHandles[ "convvtxy" ] = &convvtxy;
      fHandles[ "convvtxz" ] = &convvtxz;
      fHandles[ "Rconv" ] = &Rconv;
      fHandles[ "zconv" ] = &zconv;
      fHandles[ "convvtxchi2" ] = &convvtxchi2;
      fHandles[ "pt1conv" ] = &pt1conv;
      fHandles[ "convtrk1nBLHits" ] = &convtrk1nBLHits;
      fHandles[ "convtrk1nPixHits" ] = &convtrk1nPixHits;
      fHandles[ "convtrk1nSCTHits" ] = &convtrk1nSCTHits;
      fHandles[ "convtrk1nTRTHits" ] = &convtrk1nTRTHits;
      fHandles[ "pt2conv" ] = &pt2conv;
      fHandles[ "convtrk2nBLHits" ] = &convtrk2nBLHits;
      fHandles[ "convtrk2nPixHits" ] = &convtrk2nPixHits;
      fHandles[ "convtrk2nSCTHits" ] = &convtrk2nSCTHits;
      fHandles[ "convtrk2nTRTHits" ] = &convtrk2nTRTHits;
      fHandles[ "ptconv" ] = &ptconv;
      fHandles[ "pzconv" ] = &pzconv;
      fHandles[ "pos7" ] = &pos7;
      fHandles[ "etacorrmag" ] = &etacorrmag;
      fHandles[ "deltaeta1" ] = &deltaeta1;
      fHandles[ "deltaeta2" ] = &deltaeta2;
      fHandles[ "deltaphi2" ] = &deltaphi2;
      fHandles[ "deltaphiRescaled" ] = &deltaphiRescaled;
      fHandles[ "deltaPhiFromLast" ] = &deltaPhiFromLast;
      fHandles[ "deltaPhiRot" ] = &deltaPhiRot;
      fHandles[ "expectHitInBLayer" ] = &expectHitInBLayer;
      fHandles[ "trackd0_physics" ] = &trackd0_physics;
      fHandles[ "etaSampling1" ] = &etaSampling1;
      fHandles[ "reta" ] = &reta;
      fHandles[ "rphi" ] = &rphi;
      fHandles[ "topoEtcone20" ] = &topoEtcone20;
      fHandles[ "topoEtcone30" ] = &topoEtcone30;
      fHandles[ "topoEtcone40" ] = &topoEtcone40;
      fHandles[ "ptcone20_zpv05" ] = &ptcone20_zpv05;
      fHandles[ "ptcone30_zpv05" ] = &ptcone30_zpv05;
      fHandles[ "ptcone40_zpv05" ] = &ptcone40_zpv05;
      fHandles[ "nucone20_zpv05" ] = &nucone20_zpv05;
      fHandles[ "nucone30_zpv05" ] = &nucone30_zpv05;
      fHandles[ "nucone40_zpv05" ] = &nucone40_zpv05;
      fHandles[ "zvertex" ] = &zvertex;
      fHandles[ "errz" ] = &errz;
      fHandles[ "etap" ] = &etap;
      fHandles[ "depth" ] = &depth;
      fHandles[ "refittedTrack_n" ] = &refittedTrack_n;
      fHandles[ "Es0" ] = &Es0;
      fHandles[ "etas0" ] = &etas0;
      fHandles[ "phis0" ] = &phis0;
      fHandles[ "Es1" ] = &Es1;
      fHandles[ "etas1" ] = &etas1;
      fHandles[ "phis1" ] = &phis1;
      fHandles[ "Es2" ] = &Es2;
      fHandles[ "etas2" ] = &etas2;
      fHandles[ "phis2" ] = &phis2;
      fHandles[ "Es3" ] = &Es3;
      fHandles[ "etas3" ] = &etas3;
      fHandles[ "phis3" ] = &phis3;
      fHandles[ "cl_E" ] = &cl_E;
      fHandles[ "cl_pt" ] = &cl_pt;
      fHandles[ "cl_eta" ] = &cl_eta;
      fHandles[ "cl_phi" ] = &cl_phi;
      fHandles[ "firstEdens" ] = &firstEdens;
      fHandles[ "cellmaxfrac" ] = &cellmaxfrac;
      fHandles[ "longitudinal" ] = &longitudinal;
      fHandles[ "secondlambda" ] = &secondlambda;
      fHandles[ "lateral" ] = &lateral;
      fHandles[ "secondR" ] = &secondR;
      fHandles[ "centerlambda" ] = &centerlambda;
      fHandles[ "cl_time" ] = &cl_time;
      fHandles[ "trackd0" ] = &trackd0;
      fHandles[ "trackz0" ] = &trackz0;
      fHandles[ "trackphi" ] = &trackphi;
      fHandles[ "tracktheta" ] = &tracktheta;
      fHandles[ "trackqoverp" ] = &trackqoverp;
      fHandles[ "trackpt" ] = &trackpt;
      fHandles[ "tracketa" ] = &tracketa;
      fHandles[ "nBLHits" ] = &nBLHits;
      fHandles[ "nPixHits" ] = &nPixHits;
      fHandles[ "nSCTHits" ] = &nSCTHits;
      fHandles[ "nTRTHits" ] = &nTRTHits;
      fHandles[ "nTRTHighTHits" ] = &nTRTHighTHits;
      fHandles[ "nTRTXenonHits" ] = &nTRTXenonHits;
      fHandles[ "nPixHoles" ] = &nPixHoles;
      fHandles[ "nSCTHoles" ] = &nSCTHoles;
      fHandles[ "nTRTHoles" ] = &nTRTHoles;
      fHandles[ "nPixelDeadSensors" ] = &nPixelDeadSensors;
      fHandles[ "nSCTDeadSensors" ] = &nSCTDeadSensors;
      fHandles[ "nBLSharedHits" ] = &nBLSharedHits;
      fHandles[ "nPixSharedHits" ] = &nPixSharedHits;
      fHandles[ "nSCTSharedHits" ] = &nSCTSharedHits;
      fHandles[ "nBLayerSplitHits" ] = &nBLayerSplitHits;
      fHandles[ "nPixSplitHits" ] = &nPixSplitHits;
      fHandles[ "nBLayerOutliers" ] = &nBLayerOutliers;
      fHandles[ "nPixelOutliers" ] = &nPixelOutliers;
      fHandles[ "nSCTOutliers" ] = &nSCTOutliers;
      fHandles[ "nTRTOutliers" ] = &nTRTOutliers;
      fHandles[ "nTRTHighTOutliers" ] = &nTRTHighTOutliers;
      fHandles[ "nContribPixelLayers" ] = &nContribPixelLayers;
      fHandles[ "nGangedPixels" ] = &nGangedPixels;
      fHandles[ "nGangedFlaggedFakes" ] = &nGangedFlaggedFakes;
      fHandles[ "nPixelSpoiltHits" ] = &nPixelSpoiltHits;
      fHandles[ "nSCTDoubleHoles" ] = &nSCTDoubleHoles;
      fHandles[ "nSCTSpoiltHits" ] = &nSCTSpoiltHits;
      fHandles[ "expectBLayerHit" ] = &expectBLayerHit;
      fHandles[ "nSiHits" ] = &nSiHits;
      fHandles[ "TRTHighTHitsRatio" ] = &TRTHighTHitsRatio;
      fHandles[ "TRTHighTOutliersRatio" ] = &TRTHighTOutliersRatio;
      fHandles[ "pixeldEdx" ] = &pixeldEdx;
      fHandles[ "nGoodHitsPixeldEdx" ] = &nGoodHitsPixeldEdx;
      fHandles[ "massPixeldEdx" ] = &massPixeldEdx;
      fHandles[ "likelihoodsPixeldEdx" ] = &likelihoodsPixeldEdx;
      fHandles[ "vertweight" ] = &vertweight;
      fHandles[ "trackd0pv" ] = &trackd0pv;
      fHandles[ "trackz0pv" ] = &trackz0pv;
      fHandles[ "tracksigd0pv" ] = &tracksigd0pv;
      fHandles[ "tracksigz0pv" ] = &tracksigz0pv;
      fHandles[ "trackIPEstimate_d0_biasedpvunbiased" ] = &trackIPEstimate_d0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_z0_biasedpvunbiased" ] = &trackIPEstimate_z0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_sigd0_biasedpvunbiased" ] = &trackIPEstimate_sigd0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_sigz0_biasedpvunbiased" ] = &trackIPEstimate_sigz0_biasedpvunbiased;
      fHandles[ "trackIPEstimate_d0_unbiasedpvunbiased" ] = &trackIPEstimate_d0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_z0_unbiasedpvunbiased" ] = &trackIPEstimate_z0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_sigd0_unbiasedpvunbiased" ] = &trackIPEstimate_sigd0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_sigz0_unbiasedpvunbiased" ] = &trackIPEstimate_sigz0_unbiasedpvunbiased;
      fHandles[ "hastrack" ] = &hastrack;
      fHandles[ "Etcone40_ED_corrected" ] = &Etcone40_ED_corrected;
      fHandles[ "Etcone40_corrected" ] = &Etcone40_corrected;
      fHandles[ "topoEtcone20_corrected" ] = &topoEtcone20_corrected;
      fHandles[ "topoEtcone30_corrected" ] = &topoEtcone30_corrected;
      fHandles[ "topoEtcone40_corrected" ] = &topoEtcone40_corrected;
      fHandles[ "ED_median" ] = &ED_median;
      fHandles[ "ED_sigma" ] = &ED_sigma;
      fHandles[ "ED_Njets" ] = &ED_Njets;
      fHandles[ "EF_dr" ] = &EF_dr;
      fHandles[ "EF_index" ] = &EF_index;
      fHandles[ "ptcone20_trk500MeV" ] = &ptcone20_trk500MeV;
      fHandles[ "ptcone30_trk500MeV" ] = &ptcone30_trk500MeV;
      fHandles[ "ptcone40_trk500MeV" ] = &ptcone40_trk500MeV;
      fHandles[ "nucone20_trk500MeV" ] = &nucone20_trk500MeV;
      fHandles[ "nucone30_trk500MeV" ] = &nucone30_trk500MeV;
      fHandles[ "nucone40_trk500MeV" ] = &nucone40_trk500MeV;
      fHandles[ "MET_Simplified20_wpx" ] = &MET_Simplified20_wpx;
      fHandles[ "MET_Simplified20_wpy" ] = &MET_Simplified20_wpy;
      fHandles[ "MET_Simplified20_wet" ] = &MET_Simplified20_wet;
      fHandles[ "MET_Simplified20_statusWord" ] = &MET_Simplified20_statusWord;
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
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* ElectronD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void ElectronD3PDObject::SetPrefix( const char* prefix ) {

      n.SetName( ::TString( prefix ) + "n" );
      E.SetName( ::TString( prefix ) + "E" );
      Et.SetName( ::TString( prefix ) + "Et" );
      pt.SetName( ::TString( prefix ) + "pt" );
      m.SetName( ::TString( prefix ) + "m" );
      eta.SetName( ::TString( prefix ) + "eta" );
      phi.SetName( ::TString( prefix ) + "phi" );
      px.SetName( ::TString( prefix ) + "px" );
      py.SetName( ::TString( prefix ) + "py" );
      pz.SetName( ::TString( prefix ) + "pz" );
      charge.SetName( ::TString( prefix ) + "charge" );
      author.SetName( ::TString( prefix ) + "author" );
      isEM.SetName( ::TString( prefix ) + "isEM" );
      isEMLoose.SetName( ::TString( prefix ) + "isEMLoose" );
      isEMMedium.SetName( ::TString( prefix ) + "isEMMedium" );
      isEMTight.SetName( ::TString( prefix ) + "isEMTight" );
      OQ.SetName( ::TString( prefix ) + "OQ" );
      convFlag.SetName( ::TString( prefix ) + "convFlag" );
      isConv.SetName( ::TString( prefix ) + "isConv" );
      nConv.SetName( ::TString( prefix ) + "nConv" );
      nSingleTrackConv.SetName( ::TString( prefix ) + "nSingleTrackConv" );
      nDoubleTrackConv.SetName( ::TString( prefix ) + "nDoubleTrackConv" );
      maxEcell_time.SetName( ::TString( prefix ) + "maxEcell_time" );
      maxEcell_energy.SetName( ::TString( prefix ) + "maxEcell_energy" );
      maxEcell_onlId.SetName( ::TString( prefix ) + "maxEcell_onlId" );
      maxEcell_gain.SetName( ::TString( prefix ) + "maxEcell_gain" );
      maxEcell_x.SetName( ::TString( prefix ) + "maxEcell_x" );
      maxEcell_y.SetName( ::TString( prefix ) + "maxEcell_y" );
      maxEcell_z.SetName( ::TString( prefix ) + "maxEcell_z" );
if (!is_data) {
      type.SetName( ::TString( prefix ) + "type" );
      origin.SetName( ::TString( prefix ) + "origin" );
      typebkg.SetName( ::TString( prefix ) + "typebkg" );
      originbkg.SetName( ::TString( prefix ) + "originbkg" );
      truth_E.SetName( ::TString( prefix ) + "truth_E" );
      truth_pt.SetName( ::TString( prefix ) + "truth_pt" );
      truth_eta.SetName( ::TString( prefix ) + "truth_eta" );
      truth_phi.SetName( ::TString( prefix ) + "truth_phi" );
      truth_type.SetName( ::TString( prefix ) + "truth_type" );
      truth_status.SetName( ::TString( prefix ) + "truth_status" );
      truth_barcode.SetName( ::TString( prefix ) + "truth_barcode" );
      truth_mothertype.SetName( ::TString( prefix ) + "truth_mothertype" );
      truth_motherbarcode.SetName( ::TString( prefix ) + "truth_motherbarcode" );
      truth_hasHardBrem.SetName( ::TString( prefix ) + "truth_hasHardBrem" );
      truth_index.SetName( ::TString( prefix ) + "truth_index" );
      truth_matched.SetName( ::TString( prefix ) + "truth_matched" );
} // end !is_data
      mediumWithoutTrack.SetName( ::TString( prefix ) + "mediumWithoutTrack" );
      mediumIsoWithoutTrack.SetName( ::TString( prefix ) + "mediumIsoWithoutTrack" );
      tightWithoutTrack.SetName( ::TString( prefix ) + "tightWithoutTrack" );
      tightIsoWithoutTrack.SetName( ::TString( prefix ) + "tightIsoWithoutTrack" );
      loose.SetName( ::TString( prefix ) + "loose" );
      looseIso.SetName( ::TString( prefix ) + "looseIso" );
      medium.SetName( ::TString( prefix ) + "medium" );
      mediumIso.SetName( ::TString( prefix ) + "mediumIso" );
      tight.SetName( ::TString( prefix ) + "tight" );
      tightIso.SetName( ::TString( prefix ) + "tightIso" );
      loosePP.SetName( ::TString( prefix ) + "loosePP" );
      loosePPIso.SetName( ::TString( prefix ) + "loosePPIso" );
      mediumPP.SetName( ::TString( prefix ) + "mediumPP" );
      mediumPPIso.SetName( ::TString( prefix ) + "mediumPPIso" );
      tightPP.SetName( ::TString( prefix ) + "tightPP" );
      tightPPIso.SetName( ::TString( prefix ) + "tightPPIso" );
      goodOQ.SetName( ::TString( prefix ) + "goodOQ" );
      Ethad.SetName( ::TString( prefix ) + "Ethad" );
      Ethad1.SetName( ::TString( prefix ) + "Ethad1" );
      f1.SetName( ::TString( prefix ) + "f1" );
      f1core.SetName( ::TString( prefix ) + "f1core" );
      Emins1.SetName( ::TString( prefix ) + "Emins1" );
      fside.SetName( ::TString( prefix ) + "fside" );
      Emax2.SetName( ::TString( prefix ) + "Emax2" );
      ws3.SetName( ::TString( prefix ) + "ws3" );
      wstot.SetName( ::TString( prefix ) + "wstot" );
      emaxs1.SetName( ::TString( prefix ) + "emaxs1" );
      deltaEs.SetName( ::TString( prefix ) + "deltaEs" );
      E233.SetName( ::TString( prefix ) + "E233" );
      E237.SetName( ::TString( prefix ) + "E237" );
      E277.SetName( ::TString( prefix ) + "E277" );
      weta2.SetName( ::TString( prefix ) + "weta2" );
      f3.SetName( ::TString( prefix ) + "f3" );
      f3core.SetName( ::TString( prefix ) + "f3core" );
      rphiallcalo.SetName( ::TString( prefix ) + "rphiallcalo" );
      Etcone45.SetName( ::TString( prefix ) + "Etcone45" );
      Etcone15.SetName( ::TString( prefix ) + "Etcone15" );
      Etcone20.SetName( ::TString( prefix ) + "Etcone20" );
      Etcone25.SetName( ::TString( prefix ) + "Etcone25" );
      Etcone30.SetName( ::TString( prefix ) + "Etcone30" );
      Etcone35.SetName( ::TString( prefix ) + "Etcone35" );
      Etcone40.SetName( ::TString( prefix ) + "Etcone40" );
      ptcone20.SetName( ::TString( prefix ) + "ptcone20" );
      ptcone30.SetName( ::TString( prefix ) + "ptcone30" );
      ptcone40.SetName( ::TString( prefix ) + "ptcone40" );
      nucone20.SetName( ::TString( prefix ) + "nucone20" );
      nucone30.SetName( ::TString( prefix ) + "nucone30" );
      nucone40.SetName( ::TString( prefix ) + "nucone40" );
      convanglematch.SetName( ::TString( prefix ) + "convanglematch" );
      convtrackmatch.SetName( ::TString( prefix ) + "convtrackmatch" );
      hasconv.SetName( ::TString( prefix ) + "hasconv" );
      convvtxx.SetName( ::TString( prefix ) + "convvtxx" );
      convvtxy.SetName( ::TString( prefix ) + "convvtxy" );
      convvtxz.SetName( ::TString( prefix ) + "convvtxz" );
      Rconv.SetName( ::TString( prefix ) + "Rconv" );
      zconv.SetName( ::TString( prefix ) + "zconv" );
      convvtxchi2.SetName( ::TString( prefix ) + "convvtxchi2" );
      pt1conv.SetName( ::TString( prefix ) + "pt1conv" );
      convtrk1nBLHits.SetName( ::TString( prefix ) + "convtrk1nBLHits" );
      convtrk1nPixHits.SetName( ::TString( prefix ) + "convtrk1nPixHits" );
      convtrk1nSCTHits.SetName( ::TString( prefix ) + "convtrk1nSCTHits" );
      convtrk1nTRTHits.SetName( ::TString( prefix ) + "convtrk1nTRTHits" );
      pt2conv.SetName( ::TString( prefix ) + "pt2conv" );
      convtrk2nBLHits.SetName( ::TString( prefix ) + "convtrk2nBLHits" );
      convtrk2nPixHits.SetName( ::TString( prefix ) + "convtrk2nPixHits" );
      convtrk2nSCTHits.SetName( ::TString( prefix ) + "convtrk2nSCTHits" );
      convtrk2nTRTHits.SetName( ::TString( prefix ) + "convtrk2nTRTHits" );
      ptconv.SetName( ::TString( prefix ) + "ptconv" );
      pzconv.SetName( ::TString( prefix ) + "pzconv" );
      pos7.SetName( ::TString( prefix ) + "pos7" );
      etacorrmag.SetName( ::TString( prefix ) + "etacorrmag" );
      deltaeta1.SetName( ::TString( prefix ) + "deltaeta1" );
      deltaeta2.SetName( ::TString( prefix ) + "deltaeta2" );
      deltaphi2.SetName( ::TString( prefix ) + "deltaphi2" );
      deltaphiRescaled.SetName( ::TString( prefix ) + "deltaphiRescaled" );
      deltaPhiFromLast.SetName( ::TString( prefix ) + "deltaPhiFromLast" );
      deltaPhiRot.SetName( ::TString( prefix ) + "deltaPhiRot" );
      expectHitInBLayer.SetName( ::TString( prefix ) + "expectHitInBLayer" );
      trackd0_physics.SetName( ::TString( prefix ) + "trackd0_physics" );
      etaSampling1.SetName( ::TString( prefix ) + "etaSampling1" );
      reta.SetName( ::TString( prefix ) + "reta" );
      rphi.SetName( ::TString( prefix ) + "rphi" );
      topoEtcone20.SetName( ::TString( prefix ) + "topoEtcone20" );
      topoEtcone30.SetName( ::TString( prefix ) + "topoEtcone30" );
      topoEtcone40.SetName( ::TString( prefix ) + "topoEtcone40" );
      ptcone20_zpv05.SetName( ::TString( prefix ) + "ptcone20_zpv05" );
      ptcone30_zpv05.SetName( ::TString( prefix ) + "ptcone30_zpv05" );
      ptcone40_zpv05.SetName( ::TString( prefix ) + "ptcone40_zpv05" );
      nucone20_zpv05.SetName( ::TString( prefix ) + "nucone20_zpv05" );
      nucone30_zpv05.SetName( ::TString( prefix ) + "nucone30_zpv05" );
      nucone40_zpv05.SetName( ::TString( prefix ) + "nucone40_zpv05" );
      zvertex.SetName( ::TString( prefix ) + "zvertex" );
      errz.SetName( ::TString( prefix ) + "errz" );
      etap.SetName( ::TString( prefix ) + "etap" );
      depth.SetName( ::TString( prefix ) + "depth" );
      refittedTrack_n.SetName( ::TString( prefix ) + "refittedTrack_n" );
      Es0.SetName( ::TString( prefix ) + "Es0" );
      etas0.SetName( ::TString( prefix ) + "etas0" );
      phis0.SetName( ::TString( prefix ) + "phis0" );
      Es1.SetName( ::TString( prefix ) + "Es1" );
      etas1.SetName( ::TString( prefix ) + "etas1" );
      phis1.SetName( ::TString( prefix ) + "phis1" );
      Es2.SetName( ::TString( prefix ) + "Es2" );
      etas2.SetName( ::TString( prefix ) + "etas2" );
      phis2.SetName( ::TString( prefix ) + "phis2" );
      Es3.SetName( ::TString( prefix ) + "Es3" );
      etas3.SetName( ::TString( prefix ) + "etas3" );
      phis3.SetName( ::TString( prefix ) + "phis3" );
      cl_E.SetName( ::TString( prefix ) + "cl_E" );
      cl_pt.SetName( ::TString( prefix ) + "cl_pt" );
      cl_eta.SetName( ::TString( prefix ) + "cl_eta" );
      cl_phi.SetName( ::TString( prefix ) + "cl_phi" );
      firstEdens.SetName( ::TString( prefix ) + "firstEdens" );
      cellmaxfrac.SetName( ::TString( prefix ) + "cellmaxfrac" );
      longitudinal.SetName( ::TString( prefix ) + "longitudinal" );
      secondlambda.SetName( ::TString( prefix ) + "secondlambda" );
      lateral.SetName( ::TString( prefix ) + "lateral" );
      secondR.SetName( ::TString( prefix ) + "secondR" );
      centerlambda.SetName( ::TString( prefix ) + "centerlambda" );
      cl_time.SetName( ::TString( prefix ) + "cl_time" );
      trackd0.SetName( ::TString( prefix ) + "trackd0" );
      trackz0.SetName( ::TString( prefix ) + "trackz0" );
      trackphi.SetName( ::TString( prefix ) + "trackphi" );
      tracktheta.SetName( ::TString( prefix ) + "tracktheta" );
      trackqoverp.SetName( ::TString( prefix ) + "trackqoverp" );
      trackpt.SetName( ::TString( prefix ) + "trackpt" );
      tracketa.SetName( ::TString( prefix ) + "tracketa" );
      nBLHits.SetName( ::TString( prefix ) + "nBLHits" );
      nPixHits.SetName( ::TString( prefix ) + "nPixHits" );
      nSCTHits.SetName( ::TString( prefix ) + "nSCTHits" );
      nTRTHits.SetName( ::TString( prefix ) + "nTRTHits" );
      nTRTHighTHits.SetName( ::TString( prefix ) + "nTRTHighTHits" );
      nTRTXenonHits.SetName( ::TString( prefix ) + "nTRTXenonHits" );
      nPixHoles.SetName( ::TString( prefix ) + "nPixHoles" );
      nSCTHoles.SetName( ::TString( prefix ) + "nSCTHoles" );
      nTRTHoles.SetName( ::TString( prefix ) + "nTRTHoles" );
      nPixelDeadSensors.SetName( ::TString( prefix ) + "nPixelDeadSensors" );
      nSCTDeadSensors.SetName( ::TString( prefix ) + "nSCTDeadSensors" );
      nBLSharedHits.SetName( ::TString( prefix ) + "nBLSharedHits" );
      nPixSharedHits.SetName( ::TString( prefix ) + "nPixSharedHits" );
      nSCTSharedHits.SetName( ::TString( prefix ) + "nSCTSharedHits" );
      nBLayerSplitHits.SetName( ::TString( prefix ) + "nBLayerSplitHits" );
      nPixSplitHits.SetName( ::TString( prefix ) + "nPixSplitHits" );
      nBLayerOutliers.SetName( ::TString( prefix ) + "nBLayerOutliers" );
      nPixelOutliers.SetName( ::TString( prefix ) + "nPixelOutliers" );
      nSCTOutliers.SetName( ::TString( prefix ) + "nSCTOutliers" );
      nTRTOutliers.SetName( ::TString( prefix ) + "nTRTOutliers" );
      nTRTHighTOutliers.SetName( ::TString( prefix ) + "nTRTHighTOutliers" );
      nContribPixelLayers.SetName( ::TString( prefix ) + "nContribPixelLayers" );
      nGangedPixels.SetName( ::TString( prefix ) + "nGangedPixels" );
      nGangedFlaggedFakes.SetName( ::TString( prefix ) + "nGangedFlaggedFakes" );
      nPixelSpoiltHits.SetName( ::TString( prefix ) + "nPixelSpoiltHits" );
      nSCTDoubleHoles.SetName( ::TString( prefix ) + "nSCTDoubleHoles" );
      nSCTSpoiltHits.SetName( ::TString( prefix ) + "nSCTSpoiltHits" );
      expectBLayerHit.SetName( ::TString( prefix ) + "expectBLayerHit" );
      nSiHits.SetName( ::TString( prefix ) + "nSiHits" );
      TRTHighTHitsRatio.SetName( ::TString( prefix ) + "TRTHighTHitsRatio" );
      TRTHighTOutliersRatio.SetName( ::TString( prefix ) + "TRTHighTOutliersRatio" );
      pixeldEdx.SetName( ::TString( prefix ) + "pixeldEdx" );
      nGoodHitsPixeldEdx.SetName( ::TString( prefix ) + "nGoodHitsPixeldEdx" );
      massPixeldEdx.SetName( ::TString( prefix ) + "massPixeldEdx" );
      likelihoodsPixeldEdx.SetName( ::TString( prefix ) + "likelihoodsPixeldEdx" );
      vertweight.SetName( ::TString( prefix ) + "vertweight" );
      trackd0pv.SetName( ::TString( prefix ) + "trackd0pv" );
      trackz0pv.SetName( ::TString( prefix ) + "trackz0pv" );
      tracksigd0pv.SetName( ::TString( prefix ) + "tracksigd0pv" );
      tracksigz0pv.SetName( ::TString( prefix ) + "tracksigz0pv" );
      trackIPEstimate_d0_biasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_d0_biasedpvunbiased" );
      trackIPEstimate_z0_biasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_z0_biasedpvunbiased" );
      trackIPEstimate_sigd0_biasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_sigd0_biasedpvunbiased" );
      trackIPEstimate_sigz0_biasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_sigz0_biasedpvunbiased" );
      trackIPEstimate_d0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_d0_unbiasedpvunbiased" );
      trackIPEstimate_z0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_z0_unbiasedpvunbiased" );
      trackIPEstimate_sigd0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_sigd0_unbiasedpvunbiased" );
      trackIPEstimate_sigz0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_sigz0_unbiasedpvunbiased" );
      hastrack.SetName( ::TString( prefix ) + "hastrack" );
      Etcone40_ED_corrected.SetName( ::TString( prefix ) + "Etcone40_ED_corrected" );
      Etcone40_corrected.SetName( ::TString( prefix ) + "Etcone40_corrected" );
      topoEtcone20_corrected.SetName( ::TString( prefix ) + "topoEtcone20_corrected" );
      topoEtcone30_corrected.SetName( ::TString( prefix ) + "topoEtcone30_corrected" );
      topoEtcone40_corrected.SetName( ::TString( prefix ) + "topoEtcone40_corrected" );
      ED_median.SetName( ::TString( prefix ) + "ED_median" );
      ED_sigma.SetName( ::TString( prefix ) + "ED_sigma" );
      ED_Njets.SetName( ::TString( prefix ) + "ED_Njets" );
      EF_dr.SetName( ::TString( prefix ) + "EF_dr" );
      EF_index.SetName( ::TString( prefix ) + "EF_index" );
      ptcone20_trk500MeV.SetName( ::TString( prefix ) + "ptcone20_trk500MeV" );
      ptcone30_trk500MeV.SetName( ::TString( prefix ) + "ptcone30_trk500MeV" );
      ptcone40_trk500MeV.SetName( ::TString( prefix ) + "ptcone40_trk500MeV" );
      nucone20_trk500MeV.SetName( ::TString( prefix ) + "nucone20_trk500MeV" );
      nucone30_trk500MeV.SetName( ::TString( prefix ) + "nucone30_trk500MeV" );
      nucone40_trk500MeV.SetName( ::TString( prefix ) + "nucone40_trk500MeV" );
      MET_Simplified20_wpx.SetName( ::TString( prefix ) + "MET_Simplified20_wpx" );
      MET_Simplified20_wpy.SetName( ::TString( prefix ) + "MET_Simplified20_wpy" );
      MET_Simplified20_wet.SetName( ::TString( prefix ) + "MET_Simplified20_wet" );
      MET_Simplified20_statusWord.SetName( ::TString( prefix ) + "MET_Simplified20_statusWord" );
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
      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void ElectronD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      n.ReadFrom( tree );
      E.ReadFrom( tree );
      Et.ReadFrom( tree );
      pt.ReadFrom( tree );
      m.ReadFrom( tree );
      eta.ReadFrom( tree );
      phi.ReadFrom( tree );
      px.ReadFrom( tree );
      py.ReadFrom( tree );
      pz.ReadFrom( tree );
      charge.ReadFrom( tree );
      author.ReadFrom( tree );
      isEM.ReadFrom( tree );
      isEMLoose.ReadFrom( tree );
      isEMMedium.ReadFrom( tree );
      isEMTight.ReadFrom( tree );
      OQ.ReadFrom( tree );
      convFlag.ReadFrom( tree );
      isConv.ReadFrom( tree );
      nConv.ReadFrom( tree );
      nSingleTrackConv.ReadFrom( tree );
      nDoubleTrackConv.ReadFrom( tree );
      maxEcell_time.ReadFrom( tree );
      maxEcell_energy.ReadFrom( tree );
      maxEcell_onlId.ReadFrom( tree );
      maxEcell_gain.ReadFrom( tree );
      maxEcell_x.ReadFrom( tree );
      maxEcell_y.ReadFrom( tree );
      maxEcell_z.ReadFrom( tree );
if (!is_data) {
      type.ReadFrom( tree );
      origin.ReadFrom( tree );
      typebkg.ReadFrom( tree );
      originbkg.ReadFrom( tree );
      truth_E.ReadFrom( tree );
      truth_pt.ReadFrom( tree );
      truth_eta.ReadFrom( tree );
      truth_phi.ReadFrom( tree );
      truth_type.ReadFrom( tree );
      truth_status.ReadFrom( tree );
      truth_barcode.ReadFrom( tree );
      truth_mothertype.ReadFrom( tree );
      truth_motherbarcode.ReadFrom( tree );
      truth_hasHardBrem.ReadFrom( tree );
      truth_index.ReadFrom( tree );
      truth_matched.ReadFrom( tree );
} // end !is_data
      mediumWithoutTrack.ReadFrom( tree );
      mediumIsoWithoutTrack.ReadFrom( tree );
      tightWithoutTrack.ReadFrom( tree );
      tightIsoWithoutTrack.ReadFrom( tree );
      loose.ReadFrom( tree );
      looseIso.ReadFrom( tree );
      medium.ReadFrom( tree );
      mediumIso.ReadFrom( tree );
      tight.ReadFrom( tree );
      tightIso.ReadFrom( tree );
      loosePP.ReadFrom( tree );
      loosePPIso.ReadFrom( tree );
      mediumPP.ReadFrom( tree );
      mediumPPIso.ReadFrom( tree );
      tightPP.ReadFrom( tree );
      tightPPIso.ReadFrom( tree );
      goodOQ.ReadFrom( tree );
      Ethad.ReadFrom( tree );
      Ethad1.ReadFrom( tree );
      f1.ReadFrom( tree );
      f1core.ReadFrom( tree );
      Emins1.ReadFrom( tree );
      fside.ReadFrom( tree );
      Emax2.ReadFrom( tree );
      ws3.ReadFrom( tree );
      wstot.ReadFrom( tree );
      emaxs1.ReadFrom( tree );
      deltaEs.ReadFrom( tree );
      E233.ReadFrom( tree );
      E237.ReadFrom( tree );
      E277.ReadFrom( tree );
      weta2.ReadFrom( tree );
      f3.ReadFrom( tree );
      f3core.ReadFrom( tree );
      rphiallcalo.ReadFrom( tree );
      Etcone45.ReadFrom( tree );
      Etcone15.ReadFrom( tree );
      Etcone20.ReadFrom( tree );
      Etcone25.ReadFrom( tree );
      Etcone30.ReadFrom( tree );
      Etcone35.ReadFrom( tree );
      Etcone40.ReadFrom( tree );
      ptcone20.ReadFrom( tree );
      ptcone30.ReadFrom( tree );
      ptcone40.ReadFrom( tree );
      nucone20.ReadFrom( tree );
      nucone30.ReadFrom( tree );
      nucone40.ReadFrom( tree );
      convanglematch.ReadFrom( tree );
      convtrackmatch.ReadFrom( tree );
      hasconv.ReadFrom( tree );
      convvtxx.ReadFrom( tree );
      convvtxy.ReadFrom( tree );
      convvtxz.ReadFrom( tree );
      Rconv.ReadFrom( tree );
      zconv.ReadFrom( tree );
      convvtxchi2.ReadFrom( tree );
      pt1conv.ReadFrom( tree );
      convtrk1nBLHits.ReadFrom( tree );
      convtrk1nPixHits.ReadFrom( tree );
      convtrk1nSCTHits.ReadFrom( tree );
      convtrk1nTRTHits.ReadFrom( tree );
      pt2conv.ReadFrom( tree );
      convtrk2nBLHits.ReadFrom( tree );
      convtrk2nPixHits.ReadFrom( tree );
      convtrk2nSCTHits.ReadFrom( tree );
      convtrk2nTRTHits.ReadFrom( tree );
      ptconv.ReadFrom( tree );
      pzconv.ReadFrom( tree );
      pos7.ReadFrom( tree );
      etacorrmag.ReadFrom( tree );
      deltaeta1.ReadFrom( tree );
      deltaeta2.ReadFrom( tree );
      deltaphi2.ReadFrom( tree );
      deltaphiRescaled.ReadFrom( tree );
      deltaPhiFromLast.ReadFrom( tree );
      deltaPhiRot.ReadFrom( tree );
      expectHitInBLayer.ReadFrom( tree );
      trackd0_physics.ReadFrom( tree );
      etaSampling1.ReadFrom( tree );
      reta.ReadFrom( tree );
      rphi.ReadFrom( tree );
      topoEtcone20.ReadFrom( tree );
      topoEtcone30.ReadFrom( tree );
      topoEtcone40.ReadFrom( tree );
      ptcone20_zpv05.ReadFrom( tree );
      ptcone30_zpv05.ReadFrom( tree );
      ptcone40_zpv05.ReadFrom( tree );
      nucone20_zpv05.ReadFrom( tree );
      nucone30_zpv05.ReadFrom( tree );
      nucone40_zpv05.ReadFrom( tree );
      zvertex.ReadFrom( tree );
      errz.ReadFrom( tree );
      etap.ReadFrom( tree );
      depth.ReadFrom( tree );
      refittedTrack_n.ReadFrom( tree );
      Es0.ReadFrom( tree );
      etas0.ReadFrom( tree );
      phis0.ReadFrom( tree );
      Es1.ReadFrom( tree );
      etas1.ReadFrom( tree );
      phis1.ReadFrom( tree );
      Es2.ReadFrom( tree );
      etas2.ReadFrom( tree );
      phis2.ReadFrom( tree );
      Es3.ReadFrom( tree );
      etas3.ReadFrom( tree );
      phis3.ReadFrom( tree );
      cl_E.ReadFrom( tree );
      cl_pt.ReadFrom( tree );
      cl_eta.ReadFrom( tree );
      cl_phi.ReadFrom( tree );
      firstEdens.ReadFrom( tree );
      cellmaxfrac.ReadFrom( tree );
      longitudinal.ReadFrom( tree );
      secondlambda.ReadFrom( tree );
      lateral.ReadFrom( tree );
      secondR.ReadFrom( tree );
      centerlambda.ReadFrom( tree );
      cl_time.ReadFrom( tree );
      trackd0.ReadFrom( tree );
      trackz0.ReadFrom( tree );
      trackphi.ReadFrom( tree );
      tracktheta.ReadFrom( tree );
      trackqoverp.ReadFrom( tree );
      trackpt.ReadFrom( tree );
      tracketa.ReadFrom( tree );
      nBLHits.ReadFrom( tree );
      nPixHits.ReadFrom( tree );
      nSCTHits.ReadFrom( tree );
      nTRTHits.ReadFrom( tree );
      nTRTHighTHits.ReadFrom( tree );
      nTRTXenonHits.ReadFrom( tree );
      nPixHoles.ReadFrom( tree );
      nSCTHoles.ReadFrom( tree );
      nTRTHoles.ReadFrom( tree );
      nPixelDeadSensors.ReadFrom( tree );
      nSCTDeadSensors.ReadFrom( tree );
      nBLSharedHits.ReadFrom( tree );
      nPixSharedHits.ReadFrom( tree );
      nSCTSharedHits.ReadFrom( tree );
      nBLayerSplitHits.ReadFrom( tree );
      nPixSplitHits.ReadFrom( tree );
      nBLayerOutliers.ReadFrom( tree );
      nPixelOutliers.ReadFrom( tree );
      nSCTOutliers.ReadFrom( tree );
      nTRTOutliers.ReadFrom( tree );
      nTRTHighTOutliers.ReadFrom( tree );
      nContribPixelLayers.ReadFrom( tree );
      nGangedPixels.ReadFrom( tree );
      nGangedFlaggedFakes.ReadFrom( tree );
      nPixelSpoiltHits.ReadFrom( tree );
      nSCTDoubleHoles.ReadFrom( tree );
      nSCTSpoiltHits.ReadFrom( tree );
      expectBLayerHit.ReadFrom( tree );
      nSiHits.ReadFrom( tree );
      TRTHighTHitsRatio.ReadFrom( tree );
      TRTHighTOutliersRatio.ReadFrom( tree );
      pixeldEdx.ReadFrom( tree );
      nGoodHitsPixeldEdx.ReadFrom( tree );
      massPixeldEdx.ReadFrom( tree );
      likelihoodsPixeldEdx.ReadFrom( tree );
      vertweight.ReadFrom( tree );
      trackd0pv.ReadFrom( tree );
      trackz0pv.ReadFrom( tree );
      tracksigd0pv.ReadFrom( tree );
      tracksigz0pv.ReadFrom( tree );
      trackIPEstimate_d0_biasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_z0_biasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_sigd0_biasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_sigz0_biasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_d0_unbiasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_z0_unbiasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_sigd0_unbiasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_sigz0_unbiasedpvunbiased.ReadFrom( tree );
      hastrack.ReadFrom( tree );
      Etcone40_ED_corrected.ReadFrom( tree );
      Etcone40_corrected.ReadFrom( tree );
      topoEtcone20_corrected.ReadFrom( tree );
      topoEtcone30_corrected.ReadFrom( tree );
      topoEtcone40_corrected.ReadFrom( tree );
      ED_median.ReadFrom( tree );
      ED_sigma.ReadFrom( tree );
      ED_Njets.ReadFrom( tree );
      EF_dr.ReadFrom( tree );
      EF_index.ReadFrom( tree );
      ptcone20_trk500MeV.ReadFrom( tree );
      ptcone30_trk500MeV.ReadFrom( tree );
      ptcone40_trk500MeV.ReadFrom( tree );
      nucone20_trk500MeV.ReadFrom( tree );
      nucone30_trk500MeV.ReadFrom( tree );
      nucone40_trk500MeV.ReadFrom( tree );
      MET_Simplified20_wpx.ReadFrom( tree );
      MET_Simplified20_wpy.ReadFrom( tree );
      MET_Simplified20_wet.ReadFrom( tree );
      MET_Simplified20_statusWord.ReadFrom( tree );
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

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void ElectronD3PDObject::WriteTo( TTree* tree ) {

      n.WriteTo( tree );
      E.WriteTo( tree );
      Et.WriteTo( tree );
      pt.WriteTo( tree );
      m.WriteTo( tree );
      eta.WriteTo( tree );
      phi.WriteTo( tree );
      px.WriteTo( tree );
      py.WriteTo( tree );
      pz.WriteTo( tree );
      charge.WriteTo( tree );
      author.WriteTo( tree );
      isEM.WriteTo( tree );
      isEMLoose.WriteTo( tree );
      isEMMedium.WriteTo( tree );
      isEMTight.WriteTo( tree );
      OQ.WriteTo( tree );
      convFlag.WriteTo( tree );
      isConv.WriteTo( tree );
      nConv.WriteTo( tree );
      nSingleTrackConv.WriteTo( tree );
      nDoubleTrackConv.WriteTo( tree );
      maxEcell_time.WriteTo( tree );
      maxEcell_energy.WriteTo( tree );
      maxEcell_onlId.WriteTo( tree );
      maxEcell_gain.WriteTo( tree );
      maxEcell_x.WriteTo( tree );
      maxEcell_y.WriteTo( tree );
      maxEcell_z.WriteTo( tree );
if (!is_data) {
      type.WriteTo( tree );
      origin.WriteTo( tree );
      typebkg.WriteTo( tree );
      originbkg.WriteTo( tree );
      truth_E.WriteTo( tree );
      truth_pt.WriteTo( tree );
      truth_eta.WriteTo( tree );
      truth_phi.WriteTo( tree );
      truth_type.WriteTo( tree );
      truth_status.WriteTo( tree );
      truth_barcode.WriteTo( tree );
      truth_mothertype.WriteTo( tree );
      truth_motherbarcode.WriteTo( tree );
      truth_hasHardBrem.WriteTo( tree );
      truth_index.WriteTo( tree );
      truth_matched.WriteTo( tree );
} // end !is_data
      mediumWithoutTrack.WriteTo( tree );
      mediumIsoWithoutTrack.WriteTo( tree );
      tightWithoutTrack.WriteTo( tree );
      tightIsoWithoutTrack.WriteTo( tree );
      loose.WriteTo( tree );
      looseIso.WriteTo( tree );
      medium.WriteTo( tree );
      mediumIso.WriteTo( tree );
      tight.WriteTo( tree );
      tightIso.WriteTo( tree );
      loosePP.WriteTo( tree );
      loosePPIso.WriteTo( tree );
      mediumPP.WriteTo( tree );
      mediumPPIso.WriteTo( tree );
      tightPP.WriteTo( tree );
      tightPPIso.WriteTo( tree );
      goodOQ.WriteTo( tree );
      Ethad.WriteTo( tree );
      Ethad1.WriteTo( tree );
      f1.WriteTo( tree );
      f1core.WriteTo( tree );
      Emins1.WriteTo( tree );
      fside.WriteTo( tree );
      Emax2.WriteTo( tree );
      ws3.WriteTo( tree );
      wstot.WriteTo( tree );
      emaxs1.WriteTo( tree );
      deltaEs.WriteTo( tree );
      E233.WriteTo( tree );
      E237.WriteTo( tree );
      E277.WriteTo( tree );
      weta2.WriteTo( tree );
      f3.WriteTo( tree );
      f3core.WriteTo( tree );
      rphiallcalo.WriteTo( tree );
      Etcone45.WriteTo( tree );
      Etcone15.WriteTo( tree );
      Etcone20.WriteTo( tree );
      Etcone25.WriteTo( tree );
      Etcone30.WriteTo( tree );
      Etcone35.WriteTo( tree );
      Etcone40.WriteTo( tree );
      ptcone20.WriteTo( tree );
      ptcone30.WriteTo( tree );
      ptcone40.WriteTo( tree );
      nucone20.WriteTo( tree );
      nucone30.WriteTo( tree );
      nucone40.WriteTo( tree );
      convanglematch.WriteTo( tree );
      convtrackmatch.WriteTo( tree );
      hasconv.WriteTo( tree );
      convvtxx.WriteTo( tree );
      convvtxy.WriteTo( tree );
      convvtxz.WriteTo( tree );
      Rconv.WriteTo( tree );
      zconv.WriteTo( tree );
      convvtxchi2.WriteTo( tree );
      pt1conv.WriteTo( tree );
      convtrk1nBLHits.WriteTo( tree );
      convtrk1nPixHits.WriteTo( tree );
      convtrk1nSCTHits.WriteTo( tree );
      convtrk1nTRTHits.WriteTo( tree );
      pt2conv.WriteTo( tree );
      convtrk2nBLHits.WriteTo( tree );
      convtrk2nPixHits.WriteTo( tree );
      convtrk2nSCTHits.WriteTo( tree );
      convtrk2nTRTHits.WriteTo( tree );
      ptconv.WriteTo( tree );
      pzconv.WriteTo( tree );
      pos7.WriteTo( tree );
      etacorrmag.WriteTo( tree );
      deltaeta1.WriteTo( tree );
      deltaeta2.WriteTo( tree );
      deltaphi2.WriteTo( tree );
      deltaphiRescaled.WriteTo( tree );
      deltaPhiFromLast.WriteTo( tree );
      deltaPhiRot.WriteTo( tree );
      expectHitInBLayer.WriteTo( tree );
      trackd0_physics.WriteTo( tree );
      etaSampling1.WriteTo( tree );
      reta.WriteTo( tree );
      rphi.WriteTo( tree );
      topoEtcone20.WriteTo( tree );
      topoEtcone30.WriteTo( tree );
      topoEtcone40.WriteTo( tree );
      ptcone20_zpv05.WriteTo( tree );
      ptcone30_zpv05.WriteTo( tree );
      ptcone40_zpv05.WriteTo( tree );
      nucone20_zpv05.WriteTo( tree );
      nucone30_zpv05.WriteTo( tree );
      nucone40_zpv05.WriteTo( tree );
      zvertex.WriteTo( tree );
      errz.WriteTo( tree );
      etap.WriteTo( tree );
      depth.WriteTo( tree );
      refittedTrack_n.WriteTo( tree );
      Es0.WriteTo( tree );
      etas0.WriteTo( tree );
      phis0.WriteTo( tree );
      Es1.WriteTo( tree );
      etas1.WriteTo( tree );
      phis1.WriteTo( tree );
      Es2.WriteTo( tree );
      etas2.WriteTo( tree );
      phis2.WriteTo( tree );
      Es3.WriteTo( tree );
      etas3.WriteTo( tree );
      phis3.WriteTo( tree );
      cl_E.WriteTo( tree );
      cl_pt.WriteTo( tree );
      cl_eta.WriteTo( tree );
      cl_phi.WriteTo( tree );
      firstEdens.WriteTo( tree );
      cellmaxfrac.WriteTo( tree );
      longitudinal.WriteTo( tree );
      secondlambda.WriteTo( tree );
      lateral.WriteTo( tree );
      secondR.WriteTo( tree );
      centerlambda.WriteTo( tree );
      cl_time.WriteTo( tree );
      trackd0.WriteTo( tree );
      trackz0.WriteTo( tree );
      trackphi.WriteTo( tree );
      tracktheta.WriteTo( tree );
      trackqoverp.WriteTo( tree );
      trackpt.WriteTo( tree );
      tracketa.WriteTo( tree );
      nBLHits.WriteTo( tree );
      nPixHits.WriteTo( tree );
      nSCTHits.WriteTo( tree );
      nTRTHits.WriteTo( tree );
      nTRTHighTHits.WriteTo( tree );
      nTRTXenonHits.WriteTo( tree );
      nPixHoles.WriteTo( tree );
      nSCTHoles.WriteTo( tree );
      nTRTHoles.WriteTo( tree );
      nPixelDeadSensors.WriteTo( tree );
      nSCTDeadSensors.WriteTo( tree );
      nBLSharedHits.WriteTo( tree );
      nPixSharedHits.WriteTo( tree );
      nSCTSharedHits.WriteTo( tree );
      nBLayerSplitHits.WriteTo( tree );
      nPixSplitHits.WriteTo( tree );
      nBLayerOutliers.WriteTo( tree );
      nPixelOutliers.WriteTo( tree );
      nSCTOutliers.WriteTo( tree );
      nTRTOutliers.WriteTo( tree );
      nTRTHighTOutliers.WriteTo( tree );
      nContribPixelLayers.WriteTo( tree );
      nGangedPixels.WriteTo( tree );
      nGangedFlaggedFakes.WriteTo( tree );
      nPixelSpoiltHits.WriteTo( tree );
      nSCTDoubleHoles.WriteTo( tree );
      nSCTSpoiltHits.WriteTo( tree );
      expectBLayerHit.WriteTo( tree );
      nSiHits.WriteTo( tree );
      TRTHighTHitsRatio.WriteTo( tree );
      TRTHighTOutliersRatio.WriteTo( tree );
      pixeldEdx.WriteTo( tree );
      nGoodHitsPixeldEdx.WriteTo( tree );
      massPixeldEdx.WriteTo( tree );
      likelihoodsPixeldEdx.WriteTo( tree );
      vertweight.WriteTo( tree );
      trackd0pv.WriteTo( tree );
      trackz0pv.WriteTo( tree );
      tracksigd0pv.WriteTo( tree );
      tracksigz0pv.WriteTo( tree );
      trackIPEstimate_d0_biasedpvunbiased.WriteTo( tree );
      trackIPEstimate_z0_biasedpvunbiased.WriteTo( tree );
      trackIPEstimate_sigd0_biasedpvunbiased.WriteTo( tree );
      trackIPEstimate_sigz0_biasedpvunbiased.WriteTo( tree );
      trackIPEstimate_d0_unbiasedpvunbiased.WriteTo( tree );
      trackIPEstimate_z0_unbiasedpvunbiased.WriteTo( tree );
      trackIPEstimate_sigd0_unbiasedpvunbiased.WriteTo( tree );
      trackIPEstimate_sigz0_unbiasedpvunbiased.WriteTo( tree );
      hastrack.WriteTo( tree );
      Etcone40_ED_corrected.WriteTo( tree );
      Etcone40_corrected.WriteTo( tree );
      topoEtcone20_corrected.WriteTo( tree );
      topoEtcone30_corrected.WriteTo( tree );
      topoEtcone40_corrected.WriteTo( tree );
      ED_median.WriteTo( tree );
      ED_sigma.WriteTo( tree );
      ED_Njets.WriteTo( tree );
      EF_dr.WriteTo( tree );
      EF_index.WriteTo( tree );
      ptcone20_trk500MeV.WriteTo( tree );
      ptcone30_trk500MeV.WriteTo( tree );
      ptcone40_trk500MeV.WriteTo( tree );
      nucone20_trk500MeV.WriteTo( tree );
      nucone30_trk500MeV.WriteTo( tree );
      nucone40_trk500MeV.WriteTo( tree );
      MET_Simplified20_wpx.WriteTo( tree );
      MET_Simplified20_wpy.WriteTo( tree );
      MET_Simplified20_wet.WriteTo( tree );
      MET_Simplified20_statusWord.WriteTo( tree );
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
   void ElectronD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void ElectronD3PDObject::ReadAllActive() {

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
      if( Et.IsActive() ) Et();
      if( pt.IsActive() ) pt();
      if( m.IsActive() ) m();
      if( eta.IsActive() ) eta();
      if( phi.IsActive() ) phi();
      if( px.IsActive() ) px();
      if( py.IsActive() ) py();
      if( pz.IsActive() ) pz();
      if( charge.IsActive() ) charge();
      if( author.IsActive() ) author();
      if( isEM.IsActive() ) isEM();
      if( isEMLoose.IsActive() ) isEMLoose();
      if( isEMMedium.IsActive() ) isEMMedium();
      if( isEMTight.IsActive() ) isEMTight();
      if( OQ.IsActive() ) OQ();
      if( convFlag.IsActive() ) convFlag();
      if( isConv.IsActive() ) isConv();
      if( nConv.IsActive() ) nConv();
      if( nSingleTrackConv.IsActive() ) nSingleTrackConv();
      if( nDoubleTrackConv.IsActive() ) nDoubleTrackConv();
      if( maxEcell_time.IsActive() ) maxEcell_time();
      if( maxEcell_energy.IsActive() ) maxEcell_energy();
      if( maxEcell_onlId.IsActive() ) maxEcell_onlId();
      if( maxEcell_gain.IsActive() ) maxEcell_gain();
      if( maxEcell_x.IsActive() ) maxEcell_x();
      if( maxEcell_y.IsActive() ) maxEcell_y();
      if( maxEcell_z.IsActive() ) maxEcell_z();
if (!is_data) {
      if( type.IsActive() ) type();
      if( origin.IsActive() ) origin();
      if( typebkg.IsActive() ) typebkg();
      if( originbkg.IsActive() ) originbkg();
      if( truth_E.IsActive() ) truth_E();
      if( truth_pt.IsActive() ) truth_pt();
      if( truth_eta.IsActive() ) truth_eta();
      if( truth_phi.IsActive() ) truth_phi();
      if( truth_type.IsActive() ) truth_type();
      if( truth_status.IsActive() ) truth_status();
      if( truth_barcode.IsActive() ) truth_barcode();
      if( truth_mothertype.IsActive() ) truth_mothertype();
      if( truth_motherbarcode.IsActive() ) truth_motherbarcode();
      if( truth_hasHardBrem.IsActive() ) truth_hasHardBrem();
      if( truth_index.IsActive() ) truth_index();
      if( truth_matched.IsActive() ) truth_matched();
} // end !is_data
      if( mediumWithoutTrack.IsActive() ) mediumWithoutTrack();
      if( mediumIsoWithoutTrack.IsActive() ) mediumIsoWithoutTrack();
      if( tightWithoutTrack.IsActive() ) tightWithoutTrack();
      if( tightIsoWithoutTrack.IsActive() ) tightIsoWithoutTrack();
      if( loose.IsActive() ) loose();
      if( looseIso.IsActive() ) looseIso();
      if( medium.IsActive() ) medium();
      if( mediumIso.IsActive() ) mediumIso();
      if( tight.IsActive() ) tight();
      if( tightIso.IsActive() ) tightIso();
      if( loosePP.IsActive() ) loosePP();
      if( loosePPIso.IsActive() ) loosePPIso();
      if( mediumPP.IsActive() ) mediumPP();
      if( mediumPPIso.IsActive() ) mediumPPIso();
      if( tightPP.IsActive() ) tightPP();
      if( tightPPIso.IsActive() ) tightPPIso();
      if( goodOQ.IsActive() ) goodOQ();
      if( Ethad.IsActive() ) Ethad();
      if( Ethad1.IsActive() ) Ethad1();
      if( f1.IsActive() ) f1();
      if( f1core.IsActive() ) f1core();
      if( Emins1.IsActive() ) Emins1();
      if( fside.IsActive() ) fside();
      if( Emax2.IsActive() ) Emax2();
      if( ws3.IsActive() ) ws3();
      if( wstot.IsActive() ) wstot();
      if( emaxs1.IsActive() ) emaxs1();
      if( deltaEs.IsActive() ) deltaEs();
      if( E233.IsActive() ) E233();
      if( E237.IsActive() ) E237();
      if( E277.IsActive() ) E277();
      if( weta2.IsActive() ) weta2();
      if( f3.IsActive() ) f3();
      if( f3core.IsActive() ) f3core();
      if( rphiallcalo.IsActive() ) rphiallcalo();
      if( Etcone45.IsActive() ) Etcone45();
      if( Etcone15.IsActive() ) Etcone15();
      if( Etcone20.IsActive() ) Etcone20();
      if( Etcone25.IsActive() ) Etcone25();
      if( Etcone30.IsActive() ) Etcone30();
      if( Etcone35.IsActive() ) Etcone35();
      if( Etcone40.IsActive() ) Etcone40();
      if( ptcone20.IsActive() ) ptcone20();
      if( ptcone30.IsActive() ) ptcone30();
      if( ptcone40.IsActive() ) ptcone40();
      if( nucone20.IsActive() ) nucone20();
      if( nucone30.IsActive() ) nucone30();
      if( nucone40.IsActive() ) nucone40();
      if( convanglematch.IsActive() ) convanglematch();
      if( convtrackmatch.IsActive() ) convtrackmatch();
      if( hasconv.IsActive() ) hasconv();
      if( convvtxx.IsActive() ) convvtxx();
      if( convvtxy.IsActive() ) convvtxy();
      if( convvtxz.IsActive() ) convvtxz();
      if( Rconv.IsActive() ) Rconv();
      if( zconv.IsActive() ) zconv();
      if( convvtxchi2.IsActive() ) convvtxchi2();
      if( pt1conv.IsActive() ) pt1conv();
      if( convtrk1nBLHits.IsActive() ) convtrk1nBLHits();
      if( convtrk1nPixHits.IsActive() ) convtrk1nPixHits();
      if( convtrk1nSCTHits.IsActive() ) convtrk1nSCTHits();
      if( convtrk1nTRTHits.IsActive() ) convtrk1nTRTHits();
      if( pt2conv.IsActive() ) pt2conv();
      if( convtrk2nBLHits.IsActive() ) convtrk2nBLHits();
      if( convtrk2nPixHits.IsActive() ) convtrk2nPixHits();
      if( convtrk2nSCTHits.IsActive() ) convtrk2nSCTHits();
      if( convtrk2nTRTHits.IsActive() ) convtrk2nTRTHits();
      if( ptconv.IsActive() ) ptconv();
      if( pzconv.IsActive() ) pzconv();
      if( pos7.IsActive() ) pos7();
      if( etacorrmag.IsActive() ) etacorrmag();
      if( deltaeta1.IsActive() ) deltaeta1();
      if( deltaeta2.IsActive() ) deltaeta2();
      if( deltaphi2.IsActive() ) deltaphi2();
      if( deltaphiRescaled.IsActive() ) deltaphiRescaled();
      if( deltaPhiFromLast.IsActive() ) deltaPhiFromLast();
      if( deltaPhiRot.IsActive() ) deltaPhiRot();
      if( expectHitInBLayer.IsActive() ) expectHitInBLayer();
      if( trackd0_physics.IsActive() ) trackd0_physics();
      if( etaSampling1.IsActive() ) etaSampling1();
      if( reta.IsActive() ) reta();
      if( rphi.IsActive() ) rphi();
      if( topoEtcone20.IsActive() ) topoEtcone20();
      if( topoEtcone30.IsActive() ) topoEtcone30();
      if( topoEtcone40.IsActive() ) topoEtcone40();
      if( ptcone20_zpv05.IsActive() ) ptcone20_zpv05();
      if( ptcone30_zpv05.IsActive() ) ptcone30_zpv05();
      if( ptcone40_zpv05.IsActive() ) ptcone40_zpv05();
      if( nucone20_zpv05.IsActive() ) nucone20_zpv05();
      if( nucone30_zpv05.IsActive() ) nucone30_zpv05();
      if( nucone40_zpv05.IsActive() ) nucone40_zpv05();
      if( zvertex.IsActive() ) zvertex();
      if( errz.IsActive() ) errz();
      if( etap.IsActive() ) etap();
      if( depth.IsActive() ) depth();
      if( refittedTrack_n.IsActive() ) refittedTrack_n();
      if( Es0.IsActive() ) Es0();
      if( etas0.IsActive() ) etas0();
      if( phis0.IsActive() ) phis0();
      if( Es1.IsActive() ) Es1();
      if( etas1.IsActive() ) etas1();
      if( phis1.IsActive() ) phis1();
      if( Es2.IsActive() ) Es2();
      if( etas2.IsActive() ) etas2();
      if( phis2.IsActive() ) phis2();
      if( Es3.IsActive() ) Es3();
      if( etas3.IsActive() ) etas3();
      if( phis3.IsActive() ) phis3();
      if( cl_E.IsActive() ) cl_E();
      if( cl_pt.IsActive() ) cl_pt();
      if( cl_eta.IsActive() ) cl_eta();
      if( cl_phi.IsActive() ) cl_phi();
      if( firstEdens.IsActive() ) firstEdens();
      if( cellmaxfrac.IsActive() ) cellmaxfrac();
      if( longitudinal.IsActive() ) longitudinal();
      if( secondlambda.IsActive() ) secondlambda();
      if( lateral.IsActive() ) lateral();
      if( secondR.IsActive() ) secondR();
      if( centerlambda.IsActive() ) centerlambda();
      if( cl_time.IsActive() ) cl_time();
      if( trackd0.IsActive() ) trackd0();
      if( trackz0.IsActive() ) trackz0();
      if( trackphi.IsActive() ) trackphi();
      if( tracktheta.IsActive() ) tracktheta();
      if( trackqoverp.IsActive() ) trackqoverp();
      if( trackpt.IsActive() ) trackpt();
      if( tracketa.IsActive() ) tracketa();
      if( nBLHits.IsActive() ) nBLHits();
      if( nPixHits.IsActive() ) nPixHits();
      if( nSCTHits.IsActive() ) nSCTHits();
      if( nTRTHits.IsActive() ) nTRTHits();
      if( nTRTHighTHits.IsActive() ) nTRTHighTHits();
      if( nTRTXenonHits.IsActive() ) nTRTXenonHits();
      if( nPixHoles.IsActive() ) nPixHoles();
      if( nSCTHoles.IsActive() ) nSCTHoles();
      if( nTRTHoles.IsActive() ) nTRTHoles();
      if( nPixelDeadSensors.IsActive() ) nPixelDeadSensors();
      if( nSCTDeadSensors.IsActive() ) nSCTDeadSensors();
      if( nBLSharedHits.IsActive() ) nBLSharedHits();
      if( nPixSharedHits.IsActive() ) nPixSharedHits();
      if( nSCTSharedHits.IsActive() ) nSCTSharedHits();
      if( nBLayerSplitHits.IsActive() ) nBLayerSplitHits();
      if( nPixSplitHits.IsActive() ) nPixSplitHits();
      if( nBLayerOutliers.IsActive() ) nBLayerOutliers();
      if( nPixelOutliers.IsActive() ) nPixelOutliers();
      if( nSCTOutliers.IsActive() ) nSCTOutliers();
      if( nTRTOutliers.IsActive() ) nTRTOutliers();
      if( nTRTHighTOutliers.IsActive() ) nTRTHighTOutliers();
      if( nContribPixelLayers.IsActive() ) nContribPixelLayers();
      if( nGangedPixels.IsActive() ) nGangedPixels();
      if( nGangedFlaggedFakes.IsActive() ) nGangedFlaggedFakes();
      if( nPixelSpoiltHits.IsActive() ) nPixelSpoiltHits();
      if( nSCTDoubleHoles.IsActive() ) nSCTDoubleHoles();
      if( nSCTSpoiltHits.IsActive() ) nSCTSpoiltHits();
      if( expectBLayerHit.IsActive() ) expectBLayerHit();
      if( nSiHits.IsActive() ) nSiHits();
      if( TRTHighTHitsRatio.IsActive() ) TRTHighTHitsRatio();
      if( TRTHighTOutliersRatio.IsActive() ) TRTHighTOutliersRatio();
      if( pixeldEdx.IsActive() ) pixeldEdx();
      if( nGoodHitsPixeldEdx.IsActive() ) nGoodHitsPixeldEdx();
      if( massPixeldEdx.IsActive() ) massPixeldEdx();
      if( likelihoodsPixeldEdx.IsActive() ) likelihoodsPixeldEdx();
      if( vertweight.IsActive() ) vertweight();
      if( trackd0pv.IsActive() ) trackd0pv();
      if( trackz0pv.IsActive() ) trackz0pv();
      if( tracksigd0pv.IsActive() ) tracksigd0pv();
      if( tracksigz0pv.IsActive() ) tracksigz0pv();
      if( trackIPEstimate_d0_biasedpvunbiased.IsActive() ) trackIPEstimate_d0_biasedpvunbiased();
      if( trackIPEstimate_z0_biasedpvunbiased.IsActive() ) trackIPEstimate_z0_biasedpvunbiased();
      if( trackIPEstimate_sigd0_biasedpvunbiased.IsActive() ) trackIPEstimate_sigd0_biasedpvunbiased();
      if( trackIPEstimate_sigz0_biasedpvunbiased.IsActive() ) trackIPEstimate_sigz0_biasedpvunbiased();
      if( trackIPEstimate_d0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_d0_unbiasedpvunbiased();
      if( trackIPEstimate_z0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_z0_unbiasedpvunbiased();
      if( trackIPEstimate_sigd0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_sigd0_unbiasedpvunbiased();
      if( trackIPEstimate_sigz0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_sigz0_unbiasedpvunbiased();
      if( hastrack.IsActive() ) hastrack();
      if( Etcone40_ED_corrected.IsActive() ) Etcone40_ED_corrected();
      if( Etcone40_corrected.IsActive() ) Etcone40_corrected();
      if( topoEtcone20_corrected.IsActive() ) topoEtcone20_corrected();
      if( topoEtcone30_corrected.IsActive() ) topoEtcone30_corrected();
      if( topoEtcone40_corrected.IsActive() ) topoEtcone40_corrected();
      if( ED_median.IsActive() ) ED_median();
      if( ED_sigma.IsActive() ) ED_sigma();
      if( ED_Njets.IsActive() ) ED_Njets();
      if( EF_dr.IsActive() ) EF_dr();
      if( EF_index.IsActive() ) EF_index();
      if( ptcone20_trk500MeV.IsActive() ) ptcone20_trk500MeV();
      if( ptcone30_trk500MeV.IsActive() ) ptcone30_trk500MeV();
      if( ptcone40_trk500MeV.IsActive() ) ptcone40_trk500MeV();
      if( nucone20_trk500MeV.IsActive() ) nucone20_trk500MeV();
      if( nucone30_trk500MeV.IsActive() ) nucone30_trk500MeV();
      if( nucone40_trk500MeV.IsActive() ) nucone40_trk500MeV();
      if( MET_Simplified20_wpx.IsActive() ) MET_Simplified20_wpx();
      if( MET_Simplified20_wpy.IsActive() ) MET_Simplified20_wpy();
      if( MET_Simplified20_wet.IsActive() ) MET_Simplified20_wet();
      if( MET_Simplified20_statusWord.IsActive() ) MET_Simplified20_statusWord();
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
   void ElectronD3PDObject::Clear( Option_t* ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Clear", "Objects used for reading a D3PD can't be cleared!" );
         return;
      }

      n() = 0;
      E()->clear();
      Et()->clear();
      pt()->clear();
      m()->clear();
      eta()->clear();
      phi()->clear();
      px()->clear();
      py()->clear();
      pz()->clear();
      charge()->clear();
      author()->clear();
      isEM()->clear();
      isEMLoose()->clear();
      isEMMedium()->clear();
      isEMTight()->clear();
      OQ()->clear();
      convFlag()->clear();
      isConv()->clear();
      nConv()->clear();
      nSingleTrackConv()->clear();
      nDoubleTrackConv()->clear();
      maxEcell_time()->clear();
      maxEcell_energy()->clear();
      maxEcell_onlId()->clear();
      maxEcell_gain()->clear();
      maxEcell_x()->clear();
      maxEcell_y()->clear();
      maxEcell_z()->clear();
if (!is_data) {
      type()->clear();
      origin()->clear();
      typebkg()->clear();
      originbkg()->clear();
      truth_E()->clear();
      truth_pt()->clear();
      truth_eta()->clear();
      truth_phi()->clear();
      truth_type()->clear();
      truth_status()->clear();
      truth_barcode()->clear();
      truth_mothertype()->clear();
      truth_motherbarcode()->clear();
      truth_hasHardBrem()->clear();
      truth_index()->clear();
      truth_matched()->clear();
} // end !is_data
      mediumWithoutTrack()->clear();
      mediumIsoWithoutTrack()->clear();
      tightWithoutTrack()->clear();
      tightIsoWithoutTrack()->clear();
      loose()->clear();
      looseIso()->clear();
      medium()->clear();
      mediumIso()->clear();
      tight()->clear();
      tightIso()->clear();
      loosePP()->clear();
      loosePPIso()->clear();
      mediumPP()->clear();
      mediumPPIso()->clear();
      tightPP()->clear();
      tightPPIso()->clear();
      goodOQ()->clear();
      Ethad()->clear();
      Ethad1()->clear();
      f1()->clear();
      f1core()->clear();
      Emins1()->clear();
      fside()->clear();
      Emax2()->clear();
      ws3()->clear();
      wstot()->clear();
      emaxs1()->clear();
      deltaEs()->clear();
      E233()->clear();
      E237()->clear();
      E277()->clear();
      weta2()->clear();
      f3()->clear();
      f3core()->clear();
      rphiallcalo()->clear();
      Etcone45()->clear();
      Etcone15()->clear();
      Etcone20()->clear();
      Etcone25()->clear();
      Etcone30()->clear();
      Etcone35()->clear();
      Etcone40()->clear();
      ptcone20()->clear();
      ptcone30()->clear();
      ptcone40()->clear();
      nucone20()->clear();
      nucone30()->clear();
      nucone40()->clear();
      convanglematch()->clear();
      convtrackmatch()->clear();
      hasconv()->clear();
      convvtxx()->clear();
      convvtxy()->clear();
      convvtxz()->clear();
      Rconv()->clear();
      zconv()->clear();
      convvtxchi2()->clear();
      pt1conv()->clear();
      convtrk1nBLHits()->clear();
      convtrk1nPixHits()->clear();
      convtrk1nSCTHits()->clear();
      convtrk1nTRTHits()->clear();
      pt2conv()->clear();
      convtrk2nBLHits()->clear();
      convtrk2nPixHits()->clear();
      convtrk2nSCTHits()->clear();
      convtrk2nTRTHits()->clear();
      ptconv()->clear();
      pzconv()->clear();
      pos7()->clear();
      etacorrmag()->clear();
      deltaeta1()->clear();
      deltaeta2()->clear();
      deltaphi2()->clear();
      deltaphiRescaled()->clear();
      deltaPhiFromLast()->clear();
      deltaPhiRot()->clear();
      expectHitInBLayer()->clear();
      trackd0_physics()->clear();
      etaSampling1()->clear();
      reta()->clear();
      rphi()->clear();
      topoEtcone20()->clear();
      topoEtcone30()->clear();
      topoEtcone40()->clear();
      ptcone20_zpv05()->clear();
      ptcone30_zpv05()->clear();
      ptcone40_zpv05()->clear();
      nucone20_zpv05()->clear();
      nucone30_zpv05()->clear();
      nucone40_zpv05()->clear();
      zvertex()->clear();
      errz()->clear();
      etap()->clear();
      depth()->clear();
      refittedTrack_n()->clear();
      Es0()->clear();
      etas0()->clear();
      phis0()->clear();
      Es1()->clear();
      etas1()->clear();
      phis1()->clear();
      Es2()->clear();
      etas2()->clear();
      phis2()->clear();
      Es3()->clear();
      etas3()->clear();
      phis3()->clear();
      cl_E()->clear();
      cl_pt()->clear();
      cl_eta()->clear();
      cl_phi()->clear();
      firstEdens()->clear();
      cellmaxfrac()->clear();
      longitudinal()->clear();
      secondlambda()->clear();
      lateral()->clear();
      secondR()->clear();
      centerlambda()->clear();
      cl_time()->clear();
      trackd0()->clear();
      trackz0()->clear();
      trackphi()->clear();
      tracktheta()->clear();
      trackqoverp()->clear();
      trackpt()->clear();
      tracketa()->clear();
      nBLHits()->clear();
      nPixHits()->clear();
      nSCTHits()->clear();
      nTRTHits()->clear();
      nTRTHighTHits()->clear();
      nTRTXenonHits()->clear();
      nPixHoles()->clear();
      nSCTHoles()->clear();
      nTRTHoles()->clear();
      nPixelDeadSensors()->clear();
      nSCTDeadSensors()->clear();
      nBLSharedHits()->clear();
      nPixSharedHits()->clear();
      nSCTSharedHits()->clear();
      nBLayerSplitHits()->clear();
      nPixSplitHits()->clear();
      nBLayerOutliers()->clear();
      nPixelOutliers()->clear();
      nSCTOutliers()->clear();
      nTRTOutliers()->clear();
      nTRTHighTOutliers()->clear();
      nContribPixelLayers()->clear();
      nGangedPixels()->clear();
      nGangedFlaggedFakes()->clear();
      nPixelSpoiltHits()->clear();
      nSCTDoubleHoles()->clear();
      nSCTSpoiltHits()->clear();
      expectBLayerHit()->clear();
      nSiHits()->clear();
      TRTHighTHitsRatio()->clear();
      TRTHighTOutliersRatio()->clear();
      pixeldEdx()->clear();
      nGoodHitsPixeldEdx()->clear();
      massPixeldEdx()->clear();
      likelihoodsPixeldEdx()->clear();
      vertweight()->clear();
      trackd0pv()->clear();
      trackz0pv()->clear();
      tracksigd0pv()->clear();
      tracksigz0pv()->clear();
      trackIPEstimate_d0_biasedpvunbiased()->clear();
      trackIPEstimate_z0_biasedpvunbiased()->clear();
      trackIPEstimate_sigd0_biasedpvunbiased()->clear();
      trackIPEstimate_sigz0_biasedpvunbiased()->clear();
      trackIPEstimate_d0_unbiasedpvunbiased()->clear();
      trackIPEstimate_z0_unbiasedpvunbiased()->clear();
      trackIPEstimate_sigd0_unbiasedpvunbiased()->clear();
      trackIPEstimate_sigz0_unbiasedpvunbiased()->clear();
      hastrack()->clear();
      Etcone40_ED_corrected()->clear();
      Etcone40_corrected()->clear();
      topoEtcone20_corrected()->clear();
      topoEtcone30_corrected()->clear();
      topoEtcone40_corrected()->clear();
      ED_median()->clear();
      ED_sigma()->clear();
      ED_Njets()->clear();
      EF_dr()->clear();
      EF_index()->clear();
      ptcone20_trk500MeV()->clear();
      ptcone30_trk500MeV()->clear();
      ptcone40_trk500MeV()->clear();
      nucone20_trk500MeV()->clear();
      nucone30_trk500MeV()->clear();
      nucone40_trk500MeV()->clear();
      MET_Simplified20_wpx()->clear();
      MET_Simplified20_wpy()->clear();
      MET_Simplified20_wet()->clear();
      MET_Simplified20_statusWord()->clear();
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
   ElectronD3PDObject& ElectronD3PDObject::Add( const ElectronD3PDObjectElement& el ) {

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
      if( el.author.IsAvailable() ) {
         author()->push_back( el.author() );
      } else {
         author()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isEM.IsAvailable() ) {
         isEM()->push_back( el.isEM() );
      } else {
         isEM()->push_back( std::numeric_limits< unsigned int >::min() );
      }
      if( el.isEMLoose.IsAvailable() ) {
         isEMLoose()->push_back( el.isEMLoose() );
      } else {
         isEMLoose()->push_back( std::numeric_limits< unsigned int >::min() );
      }
      if( el.isEMMedium.IsAvailable() ) {
         isEMMedium()->push_back( el.isEMMedium() );
      } else {
         isEMMedium()->push_back( std::numeric_limits< unsigned int >::min() );
      }
      if( el.isEMTight.IsAvailable() ) {
         isEMTight()->push_back( el.isEMTight() );
      } else {
         isEMTight()->push_back( std::numeric_limits< unsigned int >::min() );
      }
      if( el.OQ.IsAvailable() ) {
         OQ()->push_back( el.OQ() );
      } else {
         OQ()->push_back( std::numeric_limits< unsigned int >::min() );
      }
      if( el.convFlag.IsAvailable() ) {
         convFlag()->push_back( el.convFlag() );
      } else {
         convFlag()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isConv.IsAvailable() ) {
         isConv()->push_back( el.isConv() );
      } else {
         isConv()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nConv.IsAvailable() ) {
         nConv()->push_back( el.nConv() );
      } else {
         nConv()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSingleTrackConv.IsAvailable() ) {
         nSingleTrackConv()->push_back( el.nSingleTrackConv() );
      } else {
         nSingleTrackConv()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nDoubleTrackConv.IsAvailable() ) {
         nDoubleTrackConv()->push_back( el.nDoubleTrackConv() );
      } else {
         nDoubleTrackConv()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.maxEcell_time.IsAvailable() ) {
         maxEcell_time()->push_back( el.maxEcell_time() );
      } else {
         maxEcell_time()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.maxEcell_energy.IsAvailable() ) {
         maxEcell_energy()->push_back( el.maxEcell_energy() );
      } else {
         maxEcell_energy()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.maxEcell_onlId.IsAvailable() ) {
         maxEcell_onlId()->push_back( el.maxEcell_onlId() );
      } else {
         maxEcell_onlId()->push_back( std::numeric_limits< unsigned int >::min() );
      }
      if( el.maxEcell_gain.IsAvailable() ) {
         maxEcell_gain()->push_back( el.maxEcell_gain() );
      } else {
         maxEcell_gain()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.maxEcell_x.IsAvailable() ) {
         maxEcell_x()->push_back( el.maxEcell_x() );
      } else {
         maxEcell_x()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.maxEcell_y.IsAvailable() ) {
         maxEcell_y()->push_back( el.maxEcell_y() );
      } else {
         maxEcell_y()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.maxEcell_z.IsAvailable() ) {
         maxEcell_z()->push_back( el.maxEcell_z() );
      } else {
         maxEcell_z()->push_back( std::numeric_limits< float >::min() );
      }
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
      if( el.typebkg.IsAvailable() ) {
         typebkg()->push_back( el.typebkg() );
      } else {
         typebkg()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.originbkg.IsAvailable() ) {
         originbkg()->push_back( el.originbkg() );
      } else {
         originbkg()->push_back( std::numeric_limits< int >::min() );
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
      if( el.truth_hasHardBrem.IsAvailable() ) {
         truth_hasHardBrem()->push_back( el.truth_hasHardBrem() );
      } else {
         truth_hasHardBrem()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_index.IsAvailable() ) {
         truth_index()->push_back( el.truth_index() );
      } else {
         truth_index()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.truth_matched.IsAvailable() ) {
         truth_matched()->push_back( el.truth_matched() );
      } else {
         truth_matched()->push_back( std::numeric_limits< int >::min() );
      }
} // end !is_data
      if( el.mediumWithoutTrack.IsAvailable() ) {
         mediumWithoutTrack()->push_back( el.mediumWithoutTrack() );
      } else {
         mediumWithoutTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.mediumIsoWithoutTrack.IsAvailable() ) {
         mediumIsoWithoutTrack()->push_back( el.mediumIsoWithoutTrack() );
      } else {
         mediumIsoWithoutTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tightWithoutTrack.IsAvailable() ) {
         tightWithoutTrack()->push_back( el.tightWithoutTrack() );
      } else {
         tightWithoutTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tightIsoWithoutTrack.IsAvailable() ) {
         tightIsoWithoutTrack()->push_back( el.tightIsoWithoutTrack() );
      } else {
         tightIsoWithoutTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.loose.IsAvailable() ) {
         loose()->push_back( el.loose() );
      } else {
         loose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.looseIso.IsAvailable() ) {
         looseIso()->push_back( el.looseIso() );
      } else {
         looseIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.medium.IsAvailable() ) {
         medium()->push_back( el.medium() );
      } else {
         medium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.mediumIso.IsAvailable() ) {
         mediumIso()->push_back( el.mediumIso() );
      } else {
         mediumIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tight.IsAvailable() ) {
         tight()->push_back( el.tight() );
      } else {
         tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tightIso.IsAvailable() ) {
         tightIso()->push_back( el.tightIso() );
      } else {
         tightIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.loosePP.IsAvailable() ) {
         loosePP()->push_back( el.loosePP() );
      } else {
         loosePP()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.loosePPIso.IsAvailable() ) {
         loosePPIso()->push_back( el.loosePPIso() );
      } else {
         loosePPIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.mediumPP.IsAvailable() ) {
         mediumPP()->push_back( el.mediumPP() );
      } else {
         mediumPP()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.mediumPPIso.IsAvailable() ) {
         mediumPPIso()->push_back( el.mediumPPIso() );
      } else {
         mediumPPIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tightPP.IsAvailable() ) {
         tightPP()->push_back( el.tightPP() );
      } else {
         tightPP()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.tightPPIso.IsAvailable() ) {
         tightPPIso()->push_back( el.tightPPIso() );
      } else {
         tightPPIso()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.goodOQ.IsAvailable() ) {
         goodOQ()->push_back( el.goodOQ() );
      } else {
         goodOQ()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.Ethad.IsAvailable() ) {
         Ethad()->push_back( el.Ethad() );
      } else {
         Ethad()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Ethad1.IsAvailable() ) {
         Ethad1()->push_back( el.Ethad1() );
      } else {
         Ethad1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.f1.IsAvailable() ) {
         f1()->push_back( el.f1() );
      } else {
         f1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.f1core.IsAvailable() ) {
         f1core()->push_back( el.f1core() );
      } else {
         f1core()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Emins1.IsAvailable() ) {
         Emins1()->push_back( el.Emins1() );
      } else {
         Emins1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.fside.IsAvailable() ) {
         fside()->push_back( el.fside() );
      } else {
         fside()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Emax2.IsAvailable() ) {
         Emax2()->push_back( el.Emax2() );
      } else {
         Emax2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ws3.IsAvailable() ) {
         ws3()->push_back( el.ws3() );
      } else {
         ws3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.wstot.IsAvailable() ) {
         wstot()->push_back( el.wstot() );
      } else {
         wstot()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.emaxs1.IsAvailable() ) {
         emaxs1()->push_back( el.emaxs1() );
      } else {
         emaxs1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.deltaEs.IsAvailable() ) {
         deltaEs()->push_back( el.deltaEs() );
      } else {
         deltaEs()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E233.IsAvailable() ) {
         E233()->push_back( el.E233() );
      } else {
         E233()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E237.IsAvailable() ) {
         E237()->push_back( el.E237() );
      } else {
         E237()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.E277.IsAvailable() ) {
         E277()->push_back( el.E277() );
      } else {
         E277()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.weta2.IsAvailable() ) {
         weta2()->push_back( el.weta2() );
      } else {
         weta2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.f3.IsAvailable() ) {
         f3()->push_back( el.f3() );
      } else {
         f3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.f3core.IsAvailable() ) {
         f3core()->push_back( el.f3core() );
      } else {
         f3core()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rphiallcalo.IsAvailable() ) {
         rphiallcalo()->push_back( el.rphiallcalo() );
      } else {
         rphiallcalo()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone45.IsAvailable() ) {
         Etcone45()->push_back( el.Etcone45() );
      } else {
         Etcone45()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone15.IsAvailable() ) {
         Etcone15()->push_back( el.Etcone15() );
      } else {
         Etcone15()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone20.IsAvailable() ) {
         Etcone20()->push_back( el.Etcone20() );
      } else {
         Etcone20()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone25.IsAvailable() ) {
         Etcone25()->push_back( el.Etcone25() );
      } else {
         Etcone25()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone30.IsAvailable() ) {
         Etcone30()->push_back( el.Etcone30() );
      } else {
         Etcone30()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone35.IsAvailable() ) {
         Etcone35()->push_back( el.Etcone35() );
      } else {
         Etcone35()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone40.IsAvailable() ) {
         Etcone40()->push_back( el.Etcone40() );
      } else {
         Etcone40()->push_back( std::numeric_limits< float >::min() );
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
      if( el.convanglematch.IsAvailable() ) {
         convanglematch()->push_back( el.convanglematch() );
      } else {
         convanglematch()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.convtrackmatch.IsAvailable() ) {
         convtrackmatch()->push_back( el.convtrackmatch() );
      } else {
         convtrackmatch()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.hasconv.IsAvailable() ) {
         hasconv()->push_back( el.hasconv() );
      } else {
         hasconv()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.convvtxx.IsAvailable() ) {
         convvtxx()->push_back( el.convvtxx() );
      } else {
         convvtxx()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.convvtxy.IsAvailable() ) {
         convvtxy()->push_back( el.convvtxy() );
      } else {
         convvtxy()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.convvtxz.IsAvailable() ) {
         convvtxz()->push_back( el.convvtxz() );
      } else {
         convvtxz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Rconv.IsAvailable() ) {
         Rconv()->push_back( el.Rconv() );
      } else {
         Rconv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.zconv.IsAvailable() ) {
         zconv()->push_back( el.zconv() );
      } else {
         zconv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.convvtxchi2.IsAvailable() ) {
         convvtxchi2()->push_back( el.convvtxchi2() );
      } else {
         convvtxchi2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pt1conv.IsAvailable() ) {
         pt1conv()->push_back( el.pt1conv() );
      } else {
         pt1conv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.convtrk1nBLHits.IsAvailable() ) {
         convtrk1nBLHits()->push_back( el.convtrk1nBLHits() );
      } else {
         convtrk1nBLHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.convtrk1nPixHits.IsAvailable() ) {
         convtrk1nPixHits()->push_back( el.convtrk1nPixHits() );
      } else {
         convtrk1nPixHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.convtrk1nSCTHits.IsAvailable() ) {
         convtrk1nSCTHits()->push_back( el.convtrk1nSCTHits() );
      } else {
         convtrk1nSCTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.convtrk1nTRTHits.IsAvailable() ) {
         convtrk1nTRTHits()->push_back( el.convtrk1nTRTHits() );
      } else {
         convtrk1nTRTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.pt2conv.IsAvailable() ) {
         pt2conv()->push_back( el.pt2conv() );
      } else {
         pt2conv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.convtrk2nBLHits.IsAvailable() ) {
         convtrk2nBLHits()->push_back( el.convtrk2nBLHits() );
      } else {
         convtrk2nBLHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.convtrk2nPixHits.IsAvailable() ) {
         convtrk2nPixHits()->push_back( el.convtrk2nPixHits() );
      } else {
         convtrk2nPixHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.convtrk2nSCTHits.IsAvailable() ) {
         convtrk2nSCTHits()->push_back( el.convtrk2nSCTHits() );
      } else {
         convtrk2nSCTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.convtrk2nTRTHits.IsAvailable() ) {
         convtrk2nTRTHits()->push_back( el.convtrk2nTRTHits() );
      } else {
         convtrk2nTRTHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.ptconv.IsAvailable() ) {
         ptconv()->push_back( el.ptconv() );
      } else {
         ptconv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pzconv.IsAvailable() ) {
         pzconv()->push_back( el.pzconv() );
      } else {
         pzconv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pos7.IsAvailable() ) {
         pos7()->push_back( el.pos7() );
      } else {
         pos7()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etacorrmag.IsAvailable() ) {
         etacorrmag()->push_back( el.etacorrmag() );
      } else {
         etacorrmag()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.deltaeta1.IsAvailable() ) {
         deltaeta1()->push_back( el.deltaeta1() );
      } else {
         deltaeta1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.deltaeta2.IsAvailable() ) {
         deltaeta2()->push_back( el.deltaeta2() );
      } else {
         deltaeta2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.deltaphi2.IsAvailable() ) {
         deltaphi2()->push_back( el.deltaphi2() );
      } else {
         deltaphi2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.deltaphiRescaled.IsAvailable() ) {
         deltaphiRescaled()->push_back( el.deltaphiRescaled() );
      } else {
         deltaphiRescaled()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.deltaPhiFromLast.IsAvailable() ) {
         deltaPhiFromLast()->push_back( el.deltaPhiFromLast() );
      } else {
         deltaPhiFromLast()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.deltaPhiRot.IsAvailable() ) {
         deltaPhiRot()->push_back( el.deltaPhiRot() );
      } else {
         deltaPhiRot()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.expectHitInBLayer.IsAvailable() ) {
         expectHitInBLayer()->push_back( el.expectHitInBLayer() );
      } else {
         expectHitInBLayer()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackd0_physics.IsAvailable() ) {
         trackd0_physics()->push_back( el.trackd0_physics() );
      } else {
         trackd0_physics()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etaSampling1.IsAvailable() ) {
         etaSampling1()->push_back( el.etaSampling1() );
      } else {
         etaSampling1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.reta.IsAvailable() ) {
         reta()->push_back( el.reta() );
      } else {
         reta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.rphi.IsAvailable() ) {
         rphi()->push_back( el.rphi() );
      } else {
         rphi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoEtcone20.IsAvailable() ) {
         topoEtcone20()->push_back( el.topoEtcone20() );
      } else {
         topoEtcone20()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoEtcone30.IsAvailable() ) {
         topoEtcone30()->push_back( el.topoEtcone30() );
      } else {
         topoEtcone30()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoEtcone40.IsAvailable() ) {
         topoEtcone40()->push_back( el.topoEtcone40() );
      } else {
         topoEtcone40()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ptcone20_zpv05.IsAvailable() ) {
         ptcone20_zpv05()->push_back( el.ptcone20_zpv05() );
      } else {
         ptcone20_zpv05()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ptcone30_zpv05.IsAvailable() ) {
         ptcone30_zpv05()->push_back( el.ptcone30_zpv05() );
      } else {
         ptcone30_zpv05()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ptcone40_zpv05.IsAvailable() ) {
         ptcone40_zpv05()->push_back( el.ptcone40_zpv05() );
      } else {
         ptcone40_zpv05()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nucone20_zpv05.IsAvailable() ) {
         nucone20_zpv05()->push_back( el.nucone20_zpv05() );
      } else {
         nucone20_zpv05()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nucone30_zpv05.IsAvailable() ) {
         nucone30_zpv05()->push_back( el.nucone30_zpv05() );
      } else {
         nucone30_zpv05()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nucone40_zpv05.IsAvailable() ) {
         nucone40_zpv05()->push_back( el.nucone40_zpv05() );
      } else {
         nucone40_zpv05()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.zvertex.IsAvailable() ) {
         zvertex()->push_back( el.zvertex() );
      } else {
         zvertex()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.errz.IsAvailable() ) {
         errz()->push_back( el.errz() );
      } else {
         errz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etap.IsAvailable() ) {
         etap()->push_back( el.etap() );
      } else {
         etap()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.depth.IsAvailable() ) {
         depth()->push_back( el.depth() );
      } else {
         depth()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.refittedTrack_n.IsAvailable() ) {
         refittedTrack_n()->push_back( el.refittedTrack_n() );
      } else {
         refittedTrack_n()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.Es0.IsAvailable() ) {
         Es0()->push_back( el.Es0() );
      } else {
         Es0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etas0.IsAvailable() ) {
         etas0()->push_back( el.etas0() );
      } else {
         etas0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.phis0.IsAvailable() ) {
         phis0()->push_back( el.phis0() );
      } else {
         phis0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Es1.IsAvailable() ) {
         Es1()->push_back( el.Es1() );
      } else {
         Es1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etas1.IsAvailable() ) {
         etas1()->push_back( el.etas1() );
      } else {
         etas1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.phis1.IsAvailable() ) {
         phis1()->push_back( el.phis1() );
      } else {
         phis1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Es2.IsAvailable() ) {
         Es2()->push_back( el.Es2() );
      } else {
         Es2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etas2.IsAvailable() ) {
         etas2()->push_back( el.etas2() );
      } else {
         etas2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.phis2.IsAvailable() ) {
         phis2()->push_back( el.phis2() );
      } else {
         phis2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Es3.IsAvailable() ) {
         Es3()->push_back( el.Es3() );
      } else {
         Es3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etas3.IsAvailable() ) {
         etas3()->push_back( el.etas3() );
      } else {
         etas3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.phis3.IsAvailable() ) {
         phis3()->push_back( el.phis3() );
      } else {
         phis3()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cl_E.IsAvailable() ) {
         cl_E()->push_back( el.cl_E() );
      } else {
         cl_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cl_pt.IsAvailable() ) {
         cl_pt()->push_back( el.cl_pt() );
      } else {
         cl_pt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cl_eta.IsAvailable() ) {
         cl_eta()->push_back( el.cl_eta() );
      } else {
         cl_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cl_phi.IsAvailable() ) {
         cl_phi()->push_back( el.cl_phi() );
      } else {
         cl_phi()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.firstEdens.IsAvailable() ) {
         firstEdens()->push_back( el.firstEdens() );
      } else {
         firstEdens()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cellmaxfrac.IsAvailable() ) {
         cellmaxfrac()->push_back( el.cellmaxfrac() );
      } else {
         cellmaxfrac()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.longitudinal.IsAvailable() ) {
         longitudinal()->push_back( el.longitudinal() );
      } else {
         longitudinal()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.secondlambda.IsAvailable() ) {
         secondlambda()->push_back( el.secondlambda() );
      } else {
         secondlambda()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.lateral.IsAvailable() ) {
         lateral()->push_back( el.lateral() );
      } else {
         lateral()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.secondR.IsAvailable() ) {
         secondR()->push_back( el.secondR() );
      } else {
         secondR()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.centerlambda.IsAvailable() ) {
         centerlambda()->push_back( el.centerlambda() );
      } else {
         centerlambda()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cl_time.IsAvailable() ) {
         cl_time()->push_back( el.cl_time() );
      } else {
         cl_time()->push_back( std::numeric_limits< float >::min() );
      }
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
      if( el.trackpt.IsAvailable() ) {
         trackpt()->push_back( el.trackpt() );
      } else {
         trackpt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tracketa.IsAvailable() ) {
         tracketa()->push_back( el.tracketa() );
      } else {
         tracketa()->push_back( std::numeric_limits< float >::min() );
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
      if( el.nTRTXenonHits.IsAvailable() ) {
         nTRTXenonHits()->push_back( el.nTRTXenonHits() );
      } else {
         nTRTXenonHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixHoles.IsAvailable() ) {
         nPixHoles()->push_back( el.nPixHoles() );
      } else {
         nPixHoles()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTHoles.IsAvailable() ) {
         nSCTHoles()->push_back( el.nSCTHoles() );
      } else {
         nSCTHoles()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nTRTHoles.IsAvailable() ) {
         nTRTHoles()->push_back( el.nTRTHoles() );
      } else {
         nTRTHoles()->push_back( std::numeric_limits< int >::min() );
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
      if( el.nSCTSharedHits.IsAvailable() ) {
         nSCTSharedHits()->push_back( el.nSCTSharedHits() );
      } else {
         nSCTSharedHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nBLayerSplitHits.IsAvailable() ) {
         nBLayerSplitHits()->push_back( el.nBLayerSplitHits() );
      } else {
         nBLayerSplitHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixSplitHits.IsAvailable() ) {
         nPixSplitHits()->push_back( el.nPixSplitHits() );
      } else {
         nPixSplitHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nBLayerOutliers.IsAvailable() ) {
         nBLayerOutliers()->push_back( el.nBLayerOutliers() );
      } else {
         nBLayerOutliers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixelOutliers.IsAvailable() ) {
         nPixelOutliers()->push_back( el.nPixelOutliers() );
      } else {
         nPixelOutliers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTOutliers.IsAvailable() ) {
         nSCTOutliers()->push_back( el.nSCTOutliers() );
      } else {
         nSCTOutliers()->push_back( std::numeric_limits< int >::min() );
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
      if( el.nContribPixelLayers.IsAvailable() ) {
         nContribPixelLayers()->push_back( el.nContribPixelLayers() );
      } else {
         nContribPixelLayers()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nGangedPixels.IsAvailable() ) {
         nGangedPixels()->push_back( el.nGangedPixels() );
      } else {
         nGangedPixels()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nGangedFlaggedFakes.IsAvailable() ) {
         nGangedFlaggedFakes()->push_back( el.nGangedFlaggedFakes() );
      } else {
         nGangedFlaggedFakes()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nPixelSpoiltHits.IsAvailable() ) {
         nPixelSpoiltHits()->push_back( el.nPixelSpoiltHits() );
      } else {
         nPixelSpoiltHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTDoubleHoles.IsAvailable() ) {
         nSCTDoubleHoles()->push_back( el.nSCTDoubleHoles() );
      } else {
         nSCTDoubleHoles()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSCTSpoiltHits.IsAvailable() ) {
         nSCTSpoiltHits()->push_back( el.nSCTSpoiltHits() );
      } else {
         nSCTSpoiltHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.expectBLayerHit.IsAvailable() ) {
         expectBLayerHit()->push_back( el.expectBLayerHit() );
      } else {
         expectBLayerHit()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.nSiHits.IsAvailable() ) {
         nSiHits()->push_back( el.nSiHits() );
      } else {
         nSiHits()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.TRTHighTHitsRatio.IsAvailable() ) {
         TRTHighTHitsRatio()->push_back( el.TRTHighTHitsRatio() );
      } else {
         TRTHighTHitsRatio()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.TRTHighTOutliersRatio.IsAvailable() ) {
         TRTHighTOutliersRatio()->push_back( el.TRTHighTOutliersRatio() );
      } else {
         TRTHighTOutliersRatio()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.pixeldEdx.IsAvailable() ) {
         pixeldEdx()->push_back( el.pixeldEdx() );
      } else {
         pixeldEdx()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nGoodHitsPixeldEdx.IsAvailable() ) {
         nGoodHitsPixeldEdx()->push_back( el.nGoodHitsPixeldEdx() );
      } else {
         nGoodHitsPixeldEdx()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.massPixeldEdx.IsAvailable() ) {
         massPixeldEdx()->push_back( el.massPixeldEdx() );
      } else {
         massPixeldEdx()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.likelihoodsPixeldEdx.IsAvailable() ) {
         likelihoodsPixeldEdx()->push_back( el.likelihoodsPixeldEdx() );
      } else {
         likelihoodsPixeldEdx()->push_back( vector<float>() );
      }
      if( el.vertweight.IsAvailable() ) {
         vertweight()->push_back( el.vertweight() );
      } else {
         vertweight()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackd0pv.IsAvailable() ) {
         trackd0pv()->push_back( el.trackd0pv() );
      } else {
         trackd0pv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackz0pv.IsAvailable() ) {
         trackz0pv()->push_back( el.trackz0pv() );
      } else {
         trackz0pv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tracksigd0pv.IsAvailable() ) {
         tracksigd0pv()->push_back( el.tracksigd0pv() );
      } else {
         tracksigd0pv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.tracksigz0pv.IsAvailable() ) {
         tracksigz0pv()->push_back( el.tracksigz0pv() );
      } else {
         tracksigz0pv()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_d0_biasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_d0_biasedpvunbiased()->push_back( el.trackIPEstimate_d0_biasedpvunbiased() );
      } else {
         trackIPEstimate_d0_biasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_z0_biasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_z0_biasedpvunbiased()->push_back( el.trackIPEstimate_z0_biasedpvunbiased() );
      } else {
         trackIPEstimate_z0_biasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_sigd0_biasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_sigd0_biasedpvunbiased()->push_back( el.trackIPEstimate_sigd0_biasedpvunbiased() );
      } else {
         trackIPEstimate_sigd0_biasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_sigz0_biasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_sigz0_biasedpvunbiased()->push_back( el.trackIPEstimate_sigz0_biasedpvunbiased() );
      } else {
         trackIPEstimate_sigz0_biasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_d0_unbiasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_d0_unbiasedpvunbiased()->push_back( el.trackIPEstimate_d0_unbiasedpvunbiased() );
      } else {
         trackIPEstimate_d0_unbiasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_z0_unbiasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_z0_unbiasedpvunbiased()->push_back( el.trackIPEstimate_z0_unbiasedpvunbiased() );
      } else {
         trackIPEstimate_z0_unbiasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_sigd0_unbiasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_sigd0_unbiasedpvunbiased()->push_back( el.trackIPEstimate_sigd0_unbiasedpvunbiased() );
      } else {
         trackIPEstimate_sigd0_unbiasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trackIPEstimate_sigz0_unbiasedpvunbiased.IsAvailable() ) {
         trackIPEstimate_sigz0_unbiasedpvunbiased()->push_back( el.trackIPEstimate_sigz0_unbiasedpvunbiased() );
      } else {
         trackIPEstimate_sigz0_unbiasedpvunbiased()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.hastrack.IsAvailable() ) {
         hastrack()->push_back( el.hastrack() );
      } else {
         hastrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.Etcone40_ED_corrected.IsAvailable() ) {
         Etcone40_ED_corrected()->push_back( el.Etcone40_ED_corrected() );
      } else {
         Etcone40_ED_corrected()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.Etcone40_corrected.IsAvailable() ) {
         Etcone40_corrected()->push_back( el.Etcone40_corrected() );
      } else {
         Etcone40_corrected()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoEtcone20_corrected.IsAvailable() ) {
         topoEtcone20_corrected()->push_back( el.topoEtcone20_corrected() );
      } else {
         topoEtcone20_corrected()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoEtcone30_corrected.IsAvailable() ) {
         topoEtcone30_corrected()->push_back( el.topoEtcone30_corrected() );
      } else {
         topoEtcone30_corrected()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.topoEtcone40_corrected.IsAvailable() ) {
         topoEtcone40_corrected()->push_back( el.topoEtcone40_corrected() );
      } else {
         topoEtcone40_corrected()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ED_median.IsAvailable() ) {
         ED_median()->push_back( el.ED_median() );
      } else {
         ED_median()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ED_sigma.IsAvailable() ) {
         ED_sigma()->push_back( el.ED_sigma() );
      } else {
         ED_sigma()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ED_Njets.IsAvailable() ) {
         ED_Njets()->push_back( el.ED_Njets() );
      } else {
         ED_Njets()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_dr.IsAvailable() ) {
         EF_dr()->push_back( el.EF_dr() );
      } else {
         EF_dr()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.EF_index.IsAvailable() ) {
         EF_index()->push_back( el.EF_index() );
      } else {
         EF_index()->push_back( std::numeric_limits< int >::min() );
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
      if( el.MET_Simplified20_wpx.IsAvailable() ) {
         MET_Simplified20_wpx()->push_back( el.MET_Simplified20_wpx() );
      } else {
         MET_Simplified20_wpx()->push_back( vector<float>() );
      }
      if( el.MET_Simplified20_wpy.IsAvailable() ) {
         MET_Simplified20_wpy()->push_back( el.MET_Simplified20_wpy() );
      } else {
         MET_Simplified20_wpy()->push_back( vector<float>() );
      }
      if( el.MET_Simplified20_wet.IsAvailable() ) {
         MET_Simplified20_wet()->push_back( el.MET_Simplified20_wet() );
      } else {
         MET_Simplified20_wet()->push_back( vector<float>() );
      }
      if( el.MET_Simplified20_statusWord.IsAvailable() ) {
         MET_Simplified20_statusWord()->push_back( el.MET_Simplified20_statusWord() );
      } else {
         MET_Simplified20_statusWord()->push_back( vector<unsigned int>() );
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
   ElectronD3PDObjectElement& ElectronD3PDObject::operator[]( size_t index ) {

      while( fProxies.size() <= index ) {
         fProxies.push_back( ElectronD3PDObjectElement( fProxies.size(), *this , is_data ) );
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
   const ElectronD3PDObjectElement& ElectronD3PDObject::operator[]( size_t index ) const {

      while( fProxies.size() <= index ) {
         fProxies.push_back( ElectronD3PDObjectElement( fProxies.size(), *this , is_data ) );
      }
      return fProxies[ index ];
   }

   /**
    * A convenience operator for adding an 'element' to this collection.
    *
    * @see Add
    * @param el The 'element' that should be added to the collection
    */
   ElectronD3PDObject& ElectronD3PDObject::operator+=( const ElectronD3PDObjectElement& el ) {

      return this->Add( el );
   }

} // namespace D3PDReader
