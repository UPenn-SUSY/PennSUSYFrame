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
        OQ( parent.OQ, index, this ),
        convFlag( parent.convFlag, index, this ),
        nConv( parent.nConv, index, this ),
// MC only
        type( parent.type, index, this ),
        origin( parent.origin, index, this ),
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
        loosePP( parent.loosePP, index, this ),
        loosePPIso( parent.loosePPIso, index, this ),
        mediumPP( parent.mediumPP, index, this ),
        mediumPPIso( parent.mediumPPIso, index, this ),
        tightPP( parent.tightPP, index, this ),
        tightPPIso( parent.tightPPIso, index, this ),
        Ethad( parent.Ethad, index, this ),
        Ethad1( parent.Ethad1, index, this ),
        f1( parent.f1, index, this ),
        fside( parent.fside, index, this ),
        wstot( parent.wstot, index, this ),
        emaxs1( parent.emaxs1, index, this ),
        weta2( parent.weta2, index, this ),
        f3( parent.f3, index, this ),
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
        deltaeta1( parent.deltaeta1, index, this ),
        deltaeta2( parent.deltaeta2, index, this ),
        deltaphi2( parent.deltaphi2, index, this ),
        expectHitInBLayer( parent.expectHitInBLayer, index, this ),
        trackd0_physics( parent.trackd0_physics, index, this ),
        etaSampling1( parent.etaSampling1, index, this ),
        reta( parent.reta, index, this ),
        topoEtcone20( parent.topoEtcone20, index, this ),
        topoEtcone30( parent.topoEtcone30, index, this ),
        topoEtcone40( parent.topoEtcone40, index, this ),
        nucone20_zpv05( parent.nucone20_zpv05, index, this ),
        nucone30_zpv05( parent.nucone30_zpv05, index, this ),
        nucone40_zpv05( parent.nucone40_zpv05, index, this ),
        cl_E( parent.cl_E, index, this ),
        cl_pt( parent.cl_pt, index, this ),
        cl_eta( parent.cl_eta, index, this ),
        cl_phi( parent.cl_phi, index, this ),
        etas0( parent.etas0, index, this ),
        etas1( parent.etas1, index, this ),
        etas2( parent.etas2, index, this ),
        etas3( parent.etas3, index, this ),
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
        nBLayerOutliers( parent.nBLayerOutliers, index, this ),
        nPixelOutliers( parent.nPixelOutliers, index, this ),
        nSCTOutliers( parent.nSCTOutliers, index, this ),
        nTRTOutliers( parent.nTRTOutliers, index, this ),
        nTRTHighTOutliers( parent.nTRTHighTOutliers, index, this ),
        nContribPixelLayers( parent.nContribPixelLayers, index, this ),
        expectBLayerHit( parent.expectBLayerHit, index, this ),
        nSiHits( parent.nSiHits, index, this ),
        TRTHighTHitsRatio( parent.TRTHighTHitsRatio, index, this ),
        TRTHighTOutliersRatio( parent.TRTHighTOutliersRatio, index, this ),
        trackd0pv( parent.trackd0pv, index, this ),
        trackz0pv( parent.trackz0pv, index, this ),
        tracksigd0pv( parent.tracksigd0pv, index, this ),
        tracksigz0pv( parent.tracksigz0pv, index, this ),
        trackIPEstimate_d0_unbiasedpvunbiased( parent.trackIPEstimate_d0_unbiasedpvunbiased, index, this ),
        trackIPEstimate_z0_unbiasedpvunbiased( parent.trackIPEstimate_z0_unbiasedpvunbiased, index, this ),
        trackIPEstimate_sigd0_unbiasedpvunbiased( parent.trackIPEstimate_sigd0_unbiasedpvunbiased, index, this ),
        trackIPEstimate_sigz0_unbiasedpvunbiased( parent.trackIPEstimate_sigz0_unbiasedpvunbiased, index, this ),
        nucone20_trk500MeV( parent.nucone20_trk500MeV, index, this ),
        nucone30_trk500MeV( parent.nucone30_trk500MeV, index, this ),
        nucone40_trk500MeV( parent.nucone40_trk500MeV, index, this ),
        Etcone40_ED_corrected( parent.Etcone40_ED_corrected, index, this ),
        Etcone40_corrected( parent.Etcone40_corrected, index, this ),
        topoEtcone20_corrected( parent.topoEtcone20_corrected, index, this ),
        topoEtcone30_corrected( parent.topoEtcone30_corrected, index, this ),
        topoEtcone40_corrected( parent.topoEtcone40_corrected, index, this ),
        MET_Egamma10NoTau_wpx( parent.MET_Egamma10NoTau_wpx, index, this ),
        MET_Egamma10NoTau_wpy( parent.MET_Egamma10NoTau_wpy, index, this ),
        MET_Egamma10NoTau_wet( parent.MET_Egamma10NoTau_wet, index, this ),
        MET_Egamma10NoTau_statusWord( parent.MET_Egamma10NoTau_statusWord, index, this ), 
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
        OQ( parent.OQ ),
        convFlag( parent.convFlag ),
        nConv( parent.nConv ),
// MC only
        type( parent.type ),
        origin( parent.origin ),
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
        loosePP( parent.loosePP ),
        loosePPIso( parent.loosePPIso ),
        mediumPP( parent.mediumPP ),
        mediumPPIso( parent.mediumPPIso ),
        tightPP( parent.tightPP ),
        tightPPIso( parent.tightPPIso ),
        Ethad( parent.Ethad ),
        Ethad1( parent.Ethad1 ),
        f1( parent.f1 ),
        fside( parent.fside ),
        wstot( parent.wstot ),
        emaxs1( parent.emaxs1 ),
        weta2( parent.weta2 ),
        f3( parent.f3 ),
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
        deltaeta1( parent.deltaeta1 ),
        deltaeta2( parent.deltaeta2 ),
        deltaphi2( parent.deltaphi2 ),
        expectHitInBLayer( parent.expectHitInBLayer ),
        trackd0_physics( parent.trackd0_physics ),
        etaSampling1( parent.etaSampling1 ),
        reta( parent.reta ),
        topoEtcone20( parent.topoEtcone20 ),
        topoEtcone30( parent.topoEtcone30 ),
        topoEtcone40( parent.topoEtcone40 ),
        nucone20_zpv05( parent.nucone20_zpv05 ),
        nucone30_zpv05( parent.nucone30_zpv05 ),
        nucone40_zpv05( parent.nucone40_zpv05 ),
        cl_E( parent.cl_E ),
        cl_pt( parent.cl_pt ),
        cl_eta( parent.cl_eta ),
        cl_phi( parent.cl_phi ),
        etas0( parent.etas0 ),
        etas1( parent.etas1 ),
        etas2( parent.etas2 ),
        etas3( parent.etas3 ),
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
        nBLayerOutliers( parent.nBLayerOutliers ),
        nPixelOutliers( parent.nPixelOutliers ),
        nSCTOutliers( parent.nSCTOutliers ),
        nTRTOutliers( parent.nTRTOutliers ),
        nTRTHighTOutliers( parent.nTRTHighTOutliers ),
        nContribPixelLayers( parent.nContribPixelLayers ),
        expectBLayerHit( parent.expectBLayerHit ),
        nSiHits( parent.nSiHits ),
        TRTHighTHitsRatio( parent.TRTHighTHitsRatio ),
        TRTHighTOutliersRatio( parent.TRTHighTOutliersRatio ),
        trackd0pv( parent.trackd0pv ),
        trackz0pv( parent.trackz0pv ),
        tracksigd0pv( parent.tracksigd0pv ),
        tracksigz0pv( parent.tracksigz0pv ),
        trackIPEstimate_d0_unbiasedpvunbiased( parent.trackIPEstimate_d0_unbiasedpvunbiased ),
        trackIPEstimate_z0_unbiasedpvunbiased( parent.trackIPEstimate_z0_unbiasedpvunbiased ),
        trackIPEstimate_sigd0_unbiasedpvunbiased( parent.trackIPEstimate_sigd0_unbiasedpvunbiased ),
        trackIPEstimate_sigz0_unbiasedpvunbiased( parent.trackIPEstimate_sigz0_unbiasedpvunbiased ),
        nucone20_trk500MeV( parent.nucone20_trk500MeV ),
        nucone30_trk500MeV( parent.nucone30_trk500MeV ),
        nucone40_trk500MeV( parent.nucone40_trk500MeV ),
        Etcone40_ED_corrected( parent.Etcone40_ED_corrected ),
        Etcone40_corrected( parent.Etcone40_corrected ),
        topoEtcone20_corrected( parent.topoEtcone20_corrected ),
        topoEtcone30_corrected( parent.topoEtcone30_corrected ),
        topoEtcone40_corrected( parent.topoEtcone40_corrected ),
        MET_Egamma10NoTau_wpx( parent.MET_Egamma10NoTau_wpx ),
        MET_Egamma10NoTau_wpy( parent.MET_Egamma10NoTau_wpy ),
        MET_Egamma10NoTau_wet( parent.MET_Egamma10NoTau_wet ),
        MET_Egamma10NoTau_statusWord( parent.MET_Egamma10NoTau_statusWord ), 
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
        OQ( this, ::TString( prefix ) + "OQ", &master ),
        convFlag( this, ::TString( prefix ) + "convFlag", &master ),
        nConv( this, ::TString( prefix ) + "nConv", &master ),
// MC only
        type( this, ::TString( prefix ) + "type", &master ),
        origin( this, ::TString( prefix ) + "origin", &master ),
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
        loosePP( this, ::TString( prefix ) + "loosePP", &master ),
        loosePPIso( this, ::TString( prefix ) + "loosePPIso", &master ),
        mediumPP( this, ::TString( prefix ) + "mediumPP", &master ),
        mediumPPIso( this, ::TString( prefix ) + "mediumPPIso", &master ),
        tightPP( this, ::TString( prefix ) + "tightPP", &master ),
        tightPPIso( this, ::TString( prefix ) + "tightPPIso", &master ),
        Ethad( this, ::TString( prefix ) + "Ethad", &master ),
        Ethad1( this, ::TString( prefix ) + "Ethad1", &master ),
        f1( this, ::TString( prefix ) + "f1", &master ),
        fside( this, ::TString( prefix ) + "fside", &master ),
        wstot( this, ::TString( prefix ) + "wstot", &master ),
        emaxs1( this, ::TString( prefix ) + "emaxs1", &master ),
        weta2( this, ::TString( prefix ) + "weta2", &master ),
        f3( this, ::TString( prefix ) + "f3", &master ),
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
        deltaeta1( this, ::TString( prefix ) + "deltaeta1", &master ),
        deltaeta2( this, ::TString( prefix ) + "deltaeta2", &master ),
        deltaphi2( this, ::TString( prefix ) + "deltaphi2", &master ),
        expectHitInBLayer( this, ::TString( prefix ) + "expectHitInBLayer", &master ),
        trackd0_physics( this, ::TString( prefix ) + "trackd0_physics", &master ),
        etaSampling1( this, ::TString( prefix ) + "etaSampling1", &master ),
        reta( this, ::TString( prefix ) + "reta", &master ),
        topoEtcone20( this, ::TString( prefix ) + "topoEtcone20", &master ),
        topoEtcone30( this, ::TString( prefix ) + "topoEtcone30", &master ),
        topoEtcone40( this, ::TString( prefix ) + "topoEtcone40", &master ),
        nucone20_zpv05( this, ::TString( prefix ) + "nucone20_zpv05", &master ),
        nucone30_zpv05( this, ::TString( prefix ) + "nucone30_zpv05", &master ),
        nucone40_zpv05( this, ::TString( prefix ) + "nucone40_zpv05", &master ),
        cl_E( this, ::TString( prefix ) + "cl_E", &master ),
        cl_pt( this, ::TString( prefix ) + "cl_pt", &master ),
        cl_eta( this, ::TString( prefix ) + "cl_eta", &master ),
        cl_phi( this, ::TString( prefix ) + "cl_phi", &master ),
        etas0( this, ::TString( prefix ) + "etas0", &master ),
        etas1( this, ::TString( prefix ) + "etas1", &master ),
        etas2( this, ::TString( prefix ) + "etas2", &master ),
        etas3( this, ::TString( prefix ) + "etas3", &master ),
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
        nBLayerOutliers( this, ::TString( prefix ) + "nBLayerOutliers", &master ),
        nPixelOutliers( this, ::TString( prefix ) + "nPixelOutliers", &master ),
        nSCTOutliers( this, ::TString( prefix ) + "nSCTOutliers", &master ),
        nTRTOutliers( this, ::TString( prefix ) + "nTRTOutliers", &master ),
        nTRTHighTOutliers( this, ::TString( prefix ) + "nTRTHighTOutliers", &master ),
        nContribPixelLayers( this, ::TString( prefix ) + "nContribPixelLayers", &master ),
        expectBLayerHit( this, ::TString( prefix ) + "expectBLayerHit", &master ),
        nSiHits( this, ::TString( prefix ) + "nSiHits", &master ),
        TRTHighTHitsRatio( this, ::TString( prefix ) + "TRTHighTHitsRatio", &master ),
        TRTHighTOutliersRatio( this, ::TString( prefix ) + "TRTHighTOutliersRatio", &master ),
        trackd0pv( this, ::TString( prefix ) + "trackd0pv", &master ),
        trackz0pv( this, ::TString( prefix ) + "trackz0pv", &master ),
        tracksigd0pv( this, ::TString( prefix ) + "tracksigd0pv", &master ),
        tracksigz0pv( this, ::TString( prefix ) + "tracksigz0pv", &master ),
        trackIPEstimate_d0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_d0_unbiasedpvunbiased", &master ),
        trackIPEstimate_z0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_z0_unbiasedpvunbiased", &master ),
        trackIPEstimate_sigd0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigd0_unbiasedpvunbiased", &master ),
        trackIPEstimate_sigz0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigz0_unbiasedpvunbiased", &master ),
        nucone20_trk500MeV( this, ::TString( prefix ) + "nucone20_trk500MeV", &master ),
        nucone30_trk500MeV( this, ::TString( prefix ) + "nucone30_trk500MeV", &master ),
        nucone40_trk500MeV( this, ::TString( prefix ) + "nucone40_trk500MeV", &master ),
        Etcone40_ED_corrected( this, ::TString( prefix ) + "Etcone40_ED_corrected", &master ),
        Etcone40_corrected( this, ::TString( prefix ) + "Etcone40_corrected", &master ),
        topoEtcone20_corrected( this, ::TString( prefix ) + "topoEtcone20_corrected", &master ),
        topoEtcone30_corrected( this, ::TString( prefix ) + "topoEtcone30_corrected", &master ),
        topoEtcone40_corrected( this, ::TString( prefix ) + "topoEtcone40_corrected", &master ),
        MET_Egamma10NoTau_wpx( this, ::TString( prefix ) + "MET_Egamma10NoTau_wpx", &master ),
        MET_Egamma10NoTau_wpy( this, ::TString( prefix ) + "MET_Egamma10NoTau_wpy", &master ),
        MET_Egamma10NoTau_wet( this, ::TString( prefix ) + "MET_Egamma10NoTau_wet", &master ),
        MET_Egamma10NoTau_statusWord( this, ::TString( prefix ) + "MET_Egamma10NoTau_statusWord", &master ),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ), 
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
      fHandles[ "OQ" ] = &OQ;
      fHandles[ "convFlag" ] = &convFlag;
      fHandles[ "nConv" ] = &nConv;
if (!is_data) {
      fHandles[ "type" ] = &type;
      fHandles[ "origin" ] = &origin;
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
      fHandles[ "loosePP" ] = &loosePP;
      fHandles[ "loosePPIso" ] = &loosePPIso;
      fHandles[ "mediumPP" ] = &mediumPP;
      fHandles[ "mediumPPIso" ] = &mediumPPIso;
      fHandles[ "tightPP" ] = &tightPP;
      fHandles[ "tightPPIso" ] = &tightPPIso;
      fHandles[ "Ethad" ] = &Ethad;
      fHandles[ "Ethad1" ] = &Ethad1;
      fHandles[ "f1" ] = &f1;
      fHandles[ "fside" ] = &fside;
      fHandles[ "wstot" ] = &wstot;
      fHandles[ "emaxs1" ] = &emaxs1;
      fHandles[ "weta2" ] = &weta2;
      fHandles[ "f3" ] = &f3;
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
      fHandles[ "deltaeta1" ] = &deltaeta1;
      fHandles[ "deltaeta2" ] = &deltaeta2;
      fHandles[ "deltaphi2" ] = &deltaphi2;
      fHandles[ "expectHitInBLayer" ] = &expectHitInBLayer;
      fHandles[ "trackd0_physics" ] = &trackd0_physics;
      fHandles[ "etaSampling1" ] = &etaSampling1;
      fHandles[ "reta" ] = &reta;
      fHandles[ "topoEtcone20" ] = &topoEtcone20;
      fHandles[ "topoEtcone30" ] = &topoEtcone30;
      fHandles[ "topoEtcone40" ] = &topoEtcone40;
      fHandles[ "nucone20_zpv05" ] = &nucone20_zpv05;
      fHandles[ "nucone30_zpv05" ] = &nucone30_zpv05;
      fHandles[ "nucone40_zpv05" ] = &nucone40_zpv05;
      fHandles[ "cl_E" ] = &cl_E;
      fHandles[ "cl_pt" ] = &cl_pt;
      fHandles[ "cl_eta" ] = &cl_eta;
      fHandles[ "cl_phi" ] = &cl_phi;
      fHandles[ "etas0" ] = &etas0;
      fHandles[ "etas1" ] = &etas1;
      fHandles[ "etas2" ] = &etas2;
      fHandles[ "etas3" ] = &etas3;
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
      fHandles[ "nBLayerOutliers" ] = &nBLayerOutliers;
      fHandles[ "nPixelOutliers" ] = &nPixelOutliers;
      fHandles[ "nSCTOutliers" ] = &nSCTOutliers;
      fHandles[ "nTRTOutliers" ] = &nTRTOutliers;
      fHandles[ "nTRTHighTOutliers" ] = &nTRTHighTOutliers;
      fHandles[ "nContribPixelLayers" ] = &nContribPixelLayers;
      fHandles[ "expectBLayerHit" ] = &expectBLayerHit;
      fHandles[ "nSiHits" ] = &nSiHits;
      fHandles[ "TRTHighTHitsRatio" ] = &TRTHighTHitsRatio;
      fHandles[ "TRTHighTOutliersRatio" ] = &TRTHighTOutliersRatio;
      fHandles[ "trackd0pv" ] = &trackd0pv;
      fHandles[ "trackz0pv" ] = &trackz0pv;
      fHandles[ "tracksigd0pv" ] = &tracksigd0pv;
      fHandles[ "tracksigz0pv" ] = &tracksigz0pv;
      fHandles[ "trackIPEstimate_d0_unbiasedpvunbiased" ] = &trackIPEstimate_d0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_z0_unbiasedpvunbiased" ] = &trackIPEstimate_z0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_sigd0_unbiasedpvunbiased" ] = &trackIPEstimate_sigd0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_sigz0_unbiasedpvunbiased" ] = &trackIPEstimate_sigz0_unbiasedpvunbiased;
      fHandles[ "nucone20_trk500MeV" ] = &nucone20_trk500MeV;
      fHandles[ "nucone30_trk500MeV" ] = &nucone30_trk500MeV;
      fHandles[ "nucone40_trk500MeV" ] = &nucone40_trk500MeV;
      fHandles[ "Etcone40_ED_corrected" ] = &Etcone40_ED_corrected;
      fHandles[ "Etcone40_corrected" ] = &Etcone40_corrected;
      fHandles[ "topoEtcone20_corrected" ] = &topoEtcone20_corrected;
      fHandles[ "topoEtcone30_corrected" ] = &topoEtcone30_corrected;
      fHandles[ "topoEtcone40_corrected" ] = &topoEtcone40_corrected;
      fHandles[ "MET_Egamma10NoTau_wpx" ] = &MET_Egamma10NoTau_wpx;
      fHandles[ "MET_Egamma10NoTau_wpy" ] = &MET_Egamma10NoTau_wpy;
      fHandles[ "MET_Egamma10NoTau_wet" ] = &MET_Egamma10NoTau_wet;
      fHandles[ "MET_Egamma10NoTau_statusWord" ] = &MET_Egamma10NoTau_statusWord;
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
        OQ( this, ::TString( prefix ) + "OQ", 0 ),
        convFlag( this, ::TString( prefix ) + "convFlag", 0 ),
        nConv( this, ::TString( prefix ) + "nConv", 0 ),
// MC only
        type( this, ::TString( prefix ) + "type", 0 ),
        origin( this, ::TString( prefix ) + "origin", 0 ),
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
        loosePP( this, ::TString( prefix ) + "loosePP", 0 ),
        loosePPIso( this, ::TString( prefix ) + "loosePPIso", 0 ),
        mediumPP( this, ::TString( prefix ) + "mediumPP", 0 ),
        mediumPPIso( this, ::TString( prefix ) + "mediumPPIso", 0 ),
        tightPP( this, ::TString( prefix ) + "tightPP", 0 ),
        tightPPIso( this, ::TString( prefix ) + "tightPPIso", 0 ),
        Ethad( this, ::TString( prefix ) + "Ethad", 0 ),
        Ethad1( this, ::TString( prefix ) + "Ethad1", 0 ),
        f1( this, ::TString( prefix ) + "f1", 0 ),
        fside( this, ::TString( prefix ) + "fside", 0 ),
        wstot( this, ::TString( prefix ) + "wstot", 0 ),
        emaxs1( this, ::TString( prefix ) + "emaxs1", 0 ),
        weta2( this, ::TString( prefix ) + "weta2", 0 ),
        f3( this, ::TString( prefix ) + "f3", 0 ),
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
        deltaeta1( this, ::TString( prefix ) + "deltaeta1", 0 ),
        deltaeta2( this, ::TString( prefix ) + "deltaeta2", 0 ),
        deltaphi2( this, ::TString( prefix ) + "deltaphi2", 0 ),
        expectHitInBLayer( this, ::TString( prefix ) + "expectHitInBLayer", 0 ),
        trackd0_physics( this, ::TString( prefix ) + "trackd0_physics", 0 ),
        etaSampling1( this, ::TString( prefix ) + "etaSampling1", 0 ),
        reta( this, ::TString( prefix ) + "reta", 0 ),
        topoEtcone20( this, ::TString( prefix ) + "topoEtcone20", 0 ),
        topoEtcone30( this, ::TString( prefix ) + "topoEtcone30", 0 ),
        topoEtcone40( this, ::TString( prefix ) + "topoEtcone40", 0 ),
        nucone20_zpv05( this, ::TString( prefix ) + "nucone20_zpv05", 0 ),
        nucone30_zpv05( this, ::TString( prefix ) + "nucone30_zpv05", 0 ),
        nucone40_zpv05( this, ::TString( prefix ) + "nucone40_zpv05", 0 ),
        cl_E( this, ::TString( prefix ) + "cl_E", 0 ),
        cl_pt( this, ::TString( prefix ) + "cl_pt", 0 ),
        cl_eta( this, ::TString( prefix ) + "cl_eta", 0 ),
        cl_phi( this, ::TString( prefix ) + "cl_phi", 0 ),
        etas0( this, ::TString( prefix ) + "etas0", 0 ),
        etas1( this, ::TString( prefix ) + "etas1", 0 ),
        etas2( this, ::TString( prefix ) + "etas2", 0 ),
        etas3( this, ::TString( prefix ) + "etas3", 0 ),
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
        nBLayerOutliers( this, ::TString( prefix ) + "nBLayerOutliers", 0 ),
        nPixelOutliers( this, ::TString( prefix ) + "nPixelOutliers", 0 ),
        nSCTOutliers( this, ::TString( prefix ) + "nSCTOutliers", 0 ),
        nTRTOutliers( this, ::TString( prefix ) + "nTRTOutliers", 0 ),
        nTRTHighTOutliers( this, ::TString( prefix ) + "nTRTHighTOutliers", 0 ),
        nContribPixelLayers( this, ::TString( prefix ) + "nContribPixelLayers", 0 ),
        expectBLayerHit( this, ::TString( prefix ) + "expectBLayerHit", 0 ),
        nSiHits( this, ::TString( prefix ) + "nSiHits", 0 ),
        TRTHighTHitsRatio( this, ::TString( prefix ) + "TRTHighTHitsRatio", 0 ),
        TRTHighTOutliersRatio( this, ::TString( prefix ) + "TRTHighTOutliersRatio", 0 ),
        trackd0pv( this, ::TString( prefix ) + "trackd0pv", 0 ),
        trackz0pv( this, ::TString( prefix ) + "trackz0pv", 0 ),
        tracksigd0pv( this, ::TString( prefix ) + "tracksigd0pv", 0 ),
        tracksigz0pv( this, ::TString( prefix ) + "tracksigz0pv", 0 ),
        trackIPEstimate_d0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_d0_unbiasedpvunbiased", 0 ),
        trackIPEstimate_z0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_z0_unbiasedpvunbiased", 0 ),
        trackIPEstimate_sigd0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigd0_unbiasedpvunbiased", 0 ),
        trackIPEstimate_sigz0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigz0_unbiasedpvunbiased", 0 ),
        nucone20_trk500MeV( this, ::TString( prefix ) + "nucone20_trk500MeV", 0 ),
        nucone30_trk500MeV( this, ::TString( prefix ) + "nucone30_trk500MeV", 0 ),
        nucone40_trk500MeV( this, ::TString( prefix ) + "nucone40_trk500MeV", 0 ),
        Etcone40_ED_corrected( this, ::TString( prefix ) + "Etcone40_ED_corrected", 0 ),
        Etcone40_corrected( this, ::TString( prefix ) + "Etcone40_corrected", 0 ),
        topoEtcone20_corrected( this, ::TString( prefix ) + "topoEtcone20_corrected", 0 ),
        topoEtcone30_corrected( this, ::TString( prefix ) + "topoEtcone30_corrected", 0 ),
        topoEtcone40_corrected( this, ::TString( prefix ) + "topoEtcone40_corrected", 0 ),
        MET_Egamma10NoTau_wpx( this, ::TString( prefix ) + "MET_Egamma10NoTau_wpx", 0 ),
        MET_Egamma10NoTau_wpy( this, ::TString( prefix ) + "MET_Egamma10NoTau_wpy", 0 ),
        MET_Egamma10NoTau_wet( this, ::TString( prefix ) + "MET_Egamma10NoTau_wet", 0 ),
        MET_Egamma10NoTau_statusWord( this, ::TString( prefix ) + "MET_Egamma10NoTau_statusWord", 0 ),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ), 
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
      fHandles[ "OQ" ] = &OQ;
      fHandles[ "convFlag" ] = &convFlag;
      fHandles[ "nConv" ] = &nConv;
if (!is_data) {
      fHandles[ "type" ] = &type;
      fHandles[ "origin" ] = &origin;
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
      fHandles[ "loosePP" ] = &loosePP;
      fHandles[ "loosePPIso" ] = &loosePPIso;
      fHandles[ "mediumPP" ] = &mediumPP;
      fHandles[ "mediumPPIso" ] = &mediumPPIso;
      fHandles[ "tightPP" ] = &tightPP;
      fHandles[ "tightPPIso" ] = &tightPPIso;
      fHandles[ "Ethad" ] = &Ethad;
      fHandles[ "Ethad1" ] = &Ethad1;
      fHandles[ "f1" ] = &f1;
      fHandles[ "fside" ] = &fside;
      fHandles[ "wstot" ] = &wstot;
      fHandles[ "emaxs1" ] = &emaxs1;
      fHandles[ "weta2" ] = &weta2;
      fHandles[ "f3" ] = &f3;
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
      fHandles[ "deltaeta1" ] = &deltaeta1;
      fHandles[ "deltaeta2" ] = &deltaeta2;
      fHandles[ "deltaphi2" ] = &deltaphi2;
      fHandles[ "expectHitInBLayer" ] = &expectHitInBLayer;
      fHandles[ "trackd0_physics" ] = &trackd0_physics;
      fHandles[ "etaSampling1" ] = &etaSampling1;
      fHandles[ "reta" ] = &reta;
      fHandles[ "topoEtcone20" ] = &topoEtcone20;
      fHandles[ "topoEtcone30" ] = &topoEtcone30;
      fHandles[ "topoEtcone40" ] = &topoEtcone40;
      fHandles[ "nucone20_zpv05" ] = &nucone20_zpv05;
      fHandles[ "nucone30_zpv05" ] = &nucone30_zpv05;
      fHandles[ "nucone40_zpv05" ] = &nucone40_zpv05;
      fHandles[ "cl_E" ] = &cl_E;
      fHandles[ "cl_pt" ] = &cl_pt;
      fHandles[ "cl_eta" ] = &cl_eta;
      fHandles[ "cl_phi" ] = &cl_phi;
      fHandles[ "etas0" ] = &etas0;
      fHandles[ "etas1" ] = &etas1;
      fHandles[ "etas2" ] = &etas2;
      fHandles[ "etas3" ] = &etas3;
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
      fHandles[ "nBLayerOutliers" ] = &nBLayerOutliers;
      fHandles[ "nPixelOutliers" ] = &nPixelOutliers;
      fHandles[ "nSCTOutliers" ] = &nSCTOutliers;
      fHandles[ "nTRTOutliers" ] = &nTRTOutliers;
      fHandles[ "nTRTHighTOutliers" ] = &nTRTHighTOutliers;
      fHandles[ "nContribPixelLayers" ] = &nContribPixelLayers;
      fHandles[ "expectBLayerHit" ] = &expectBLayerHit;
      fHandles[ "nSiHits" ] = &nSiHits;
      fHandles[ "TRTHighTHitsRatio" ] = &TRTHighTHitsRatio;
      fHandles[ "TRTHighTOutliersRatio" ] = &TRTHighTOutliersRatio;
      fHandles[ "trackd0pv" ] = &trackd0pv;
      fHandles[ "trackz0pv" ] = &trackz0pv;
      fHandles[ "tracksigd0pv" ] = &tracksigd0pv;
      fHandles[ "tracksigz0pv" ] = &tracksigz0pv;
      fHandles[ "trackIPEstimate_d0_unbiasedpvunbiased" ] = &trackIPEstimate_d0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_z0_unbiasedpvunbiased" ] = &trackIPEstimate_z0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_sigd0_unbiasedpvunbiased" ] = &trackIPEstimate_sigd0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_sigz0_unbiasedpvunbiased" ] = &trackIPEstimate_sigz0_unbiasedpvunbiased;
      fHandles[ "nucone20_trk500MeV" ] = &nucone20_trk500MeV;
      fHandles[ "nucone30_trk500MeV" ] = &nucone30_trk500MeV;
      fHandles[ "nucone40_trk500MeV" ] = &nucone40_trk500MeV;
      fHandles[ "Etcone40_ED_corrected" ] = &Etcone40_ED_corrected;
      fHandles[ "Etcone40_corrected" ] = &Etcone40_corrected;
      fHandles[ "topoEtcone20_corrected" ] = &topoEtcone20_corrected;
      fHandles[ "topoEtcone30_corrected" ] = &topoEtcone30_corrected;
      fHandles[ "topoEtcone40_corrected" ] = &topoEtcone40_corrected;
      fHandles[ "MET_Egamma10NoTau_wpx" ] = &MET_Egamma10NoTau_wpx;
      fHandles[ "MET_Egamma10NoTau_wpy" ] = &MET_Egamma10NoTau_wpy;
      fHandles[ "MET_Egamma10NoTau_wet" ] = &MET_Egamma10NoTau_wet;
      fHandles[ "MET_Egamma10NoTau_statusWord" ] = &MET_Egamma10NoTau_statusWord;
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
      OQ.SetName( ::TString( prefix ) + "OQ" );
      convFlag.SetName( ::TString( prefix ) + "convFlag" );
      nConv.SetName( ::TString( prefix ) + "nConv" );
if (!is_data) {
      type.SetName( ::TString( prefix ) + "type" );
      origin.SetName( ::TString( prefix ) + "origin" );
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
      loosePP.SetName( ::TString( prefix ) + "loosePP" );
      loosePPIso.SetName( ::TString( prefix ) + "loosePPIso" );
      mediumPP.SetName( ::TString( prefix ) + "mediumPP" );
      mediumPPIso.SetName( ::TString( prefix ) + "mediumPPIso" );
      tightPP.SetName( ::TString( prefix ) + "tightPP" );
      tightPPIso.SetName( ::TString( prefix ) + "tightPPIso" );
      Ethad.SetName( ::TString( prefix ) + "Ethad" );
      Ethad1.SetName( ::TString( prefix ) + "Ethad1" );
      f1.SetName( ::TString( prefix ) + "f1" );
      fside.SetName( ::TString( prefix ) + "fside" );
      wstot.SetName( ::TString( prefix ) + "wstot" );
      emaxs1.SetName( ::TString( prefix ) + "emaxs1" );
      weta2.SetName( ::TString( prefix ) + "weta2" );
      f3.SetName( ::TString( prefix ) + "f3" );
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
      deltaeta1.SetName( ::TString( prefix ) + "deltaeta1" );
      deltaeta2.SetName( ::TString( prefix ) + "deltaeta2" );
      deltaphi2.SetName( ::TString( prefix ) + "deltaphi2" );
      expectHitInBLayer.SetName( ::TString( prefix ) + "expectHitInBLayer" );
      trackd0_physics.SetName( ::TString( prefix ) + "trackd0_physics" );
      etaSampling1.SetName( ::TString( prefix ) + "etaSampling1" );
      reta.SetName( ::TString( prefix ) + "reta" );
      topoEtcone20.SetName( ::TString( prefix ) + "topoEtcone20" );
      topoEtcone30.SetName( ::TString( prefix ) + "topoEtcone30" );
      topoEtcone40.SetName( ::TString( prefix ) + "topoEtcone40" );
      nucone20_zpv05.SetName( ::TString( prefix ) + "nucone20_zpv05" );
      nucone30_zpv05.SetName( ::TString( prefix ) + "nucone30_zpv05" );
      nucone40_zpv05.SetName( ::TString( prefix ) + "nucone40_zpv05" );
      cl_E.SetName( ::TString( prefix ) + "cl_E" );
      cl_pt.SetName( ::TString( prefix ) + "cl_pt" );
      cl_eta.SetName( ::TString( prefix ) + "cl_eta" );
      cl_phi.SetName( ::TString( prefix ) + "cl_phi" );
      etas0.SetName( ::TString( prefix ) + "etas0" );
      etas1.SetName( ::TString( prefix ) + "etas1" );
      etas2.SetName( ::TString( prefix ) + "etas2" );
      etas3.SetName( ::TString( prefix ) + "etas3" );
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
      nBLayerOutliers.SetName( ::TString( prefix ) + "nBLayerOutliers" );
      nPixelOutliers.SetName( ::TString( prefix ) + "nPixelOutliers" );
      nSCTOutliers.SetName( ::TString( prefix ) + "nSCTOutliers" );
      nTRTOutliers.SetName( ::TString( prefix ) + "nTRTOutliers" );
      nTRTHighTOutliers.SetName( ::TString( prefix ) + "nTRTHighTOutliers" );
      nContribPixelLayers.SetName( ::TString( prefix ) + "nContribPixelLayers" );
      expectBLayerHit.SetName( ::TString( prefix ) + "expectBLayerHit" );
      nSiHits.SetName( ::TString( prefix ) + "nSiHits" );
      TRTHighTHitsRatio.SetName( ::TString( prefix ) + "TRTHighTHitsRatio" );
      TRTHighTOutliersRatio.SetName( ::TString( prefix ) + "TRTHighTOutliersRatio" );
      trackd0pv.SetName( ::TString( prefix ) + "trackd0pv" );
      trackz0pv.SetName( ::TString( prefix ) + "trackz0pv" );
      tracksigd0pv.SetName( ::TString( prefix ) + "tracksigd0pv" );
      tracksigz0pv.SetName( ::TString( prefix ) + "tracksigz0pv" );
      trackIPEstimate_d0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_d0_unbiasedpvunbiased" );
      trackIPEstimate_z0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_z0_unbiasedpvunbiased" );
      trackIPEstimate_sigd0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_sigd0_unbiasedpvunbiased" );
      trackIPEstimate_sigz0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_sigz0_unbiasedpvunbiased" );
      nucone20_trk500MeV.SetName( ::TString( prefix ) + "nucone20_trk500MeV" );
      nucone30_trk500MeV.SetName( ::TString( prefix ) + "nucone30_trk500MeV" );
      nucone40_trk500MeV.SetName( ::TString( prefix ) + "nucone40_trk500MeV" );
      Etcone40_ED_corrected.SetName( ::TString( prefix ) + "Etcone40_ED_corrected" );
      Etcone40_corrected.SetName( ::TString( prefix ) + "Etcone40_corrected" );
      topoEtcone20_corrected.SetName( ::TString( prefix ) + "topoEtcone20_corrected" );
      topoEtcone30_corrected.SetName( ::TString( prefix ) + "topoEtcone30_corrected" );
      topoEtcone40_corrected.SetName( ::TString( prefix ) + "topoEtcone40_corrected" );
      MET_Egamma10NoTau_wpx.SetName( ::TString( prefix ) + "MET_Egamma10NoTau_wpx" );
      MET_Egamma10NoTau_wpy.SetName( ::TString( prefix ) + "MET_Egamma10NoTau_wpy" );
      MET_Egamma10NoTau_wet.SetName( ::TString( prefix ) + "MET_Egamma10NoTau_wet" );
      MET_Egamma10NoTau_statusWord.SetName( ::TString( prefix ) + "MET_Egamma10NoTau_statusWord" );
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
      OQ.ReadFrom( tree );
      convFlag.ReadFrom( tree );
      nConv.ReadFrom( tree );
if (!is_data) {
      type.ReadFrom( tree );
      origin.ReadFrom( tree );
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
      loosePP.ReadFrom( tree );
      loosePPIso.ReadFrom( tree );
      mediumPP.ReadFrom( tree );
      mediumPPIso.ReadFrom( tree );
      tightPP.ReadFrom( tree );
      tightPPIso.ReadFrom( tree );
      Ethad.ReadFrom( tree );
      Ethad1.ReadFrom( tree );
      f1.ReadFrom( tree );
      fside.ReadFrom( tree );
      wstot.ReadFrom( tree );
      emaxs1.ReadFrom( tree );
      weta2.ReadFrom( tree );
      f3.ReadFrom( tree );
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
      deltaeta1.ReadFrom( tree );
      deltaeta2.ReadFrom( tree );
      deltaphi2.ReadFrom( tree );
      expectHitInBLayer.ReadFrom( tree );
      trackd0_physics.ReadFrom( tree );
      etaSampling1.ReadFrom( tree );
      reta.ReadFrom( tree );
      topoEtcone20.ReadFrom( tree );
      topoEtcone30.ReadFrom( tree );
      topoEtcone40.ReadFrom( tree );
      nucone20_zpv05.ReadFrom( tree );
      nucone30_zpv05.ReadFrom( tree );
      nucone40_zpv05.ReadFrom( tree );
      cl_E.ReadFrom( tree );
      cl_pt.ReadFrom( tree );
      cl_eta.ReadFrom( tree );
      cl_phi.ReadFrom( tree );
      etas0.ReadFrom( tree );
      etas1.ReadFrom( tree );
      etas2.ReadFrom( tree );
      etas3.ReadFrom( tree );
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
      nBLayerOutliers.ReadFrom( tree );
      nPixelOutliers.ReadFrom( tree );
      nSCTOutliers.ReadFrom( tree );
      nTRTOutliers.ReadFrom( tree );
      nTRTHighTOutliers.ReadFrom( tree );
      nContribPixelLayers.ReadFrom( tree );
      expectBLayerHit.ReadFrom( tree );
      nSiHits.ReadFrom( tree );
      TRTHighTHitsRatio.ReadFrom( tree );
      TRTHighTOutliersRatio.ReadFrom( tree );
      trackd0pv.ReadFrom( tree );
      trackz0pv.ReadFrom( tree );
      tracksigd0pv.ReadFrom( tree );
      tracksigz0pv.ReadFrom( tree );
      trackIPEstimate_d0_unbiasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_z0_unbiasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_sigd0_unbiasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_sigz0_unbiasedpvunbiased.ReadFrom( tree );
      nucone20_trk500MeV.ReadFrom( tree );
      nucone30_trk500MeV.ReadFrom( tree );
      nucone40_trk500MeV.ReadFrom( tree );
      Etcone40_ED_corrected.ReadFrom( tree );
      Etcone40_corrected.ReadFrom( tree );
      topoEtcone20_corrected.ReadFrom( tree );
      topoEtcone30_corrected.ReadFrom( tree );
      topoEtcone40_corrected.ReadFrom( tree );
      MET_Egamma10NoTau_wpx.ReadFrom( tree );
      MET_Egamma10NoTau_wpy.ReadFrom( tree );
      MET_Egamma10NoTau_wet.ReadFrom( tree );
      MET_Egamma10NoTau_statusWord.ReadFrom( tree );

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
      OQ.WriteTo( tree );
      convFlag.WriteTo( tree );
      nConv.WriteTo( tree );
if (!is_data) {
      type.WriteTo( tree );
      origin.WriteTo( tree );
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
      loosePP.WriteTo( tree );
      loosePPIso.WriteTo( tree );
      mediumPP.WriteTo( tree );
      mediumPPIso.WriteTo( tree );
      tightPP.WriteTo( tree );
      tightPPIso.WriteTo( tree );
      Ethad.WriteTo( tree );
      Ethad1.WriteTo( tree );
      f1.WriteTo( tree );
      fside.WriteTo( tree );
      wstot.WriteTo( tree );
      emaxs1.WriteTo( tree );
      weta2.WriteTo( tree );
      f3.WriteTo( tree );
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
      deltaeta1.WriteTo( tree );
      deltaeta2.WriteTo( tree );
      deltaphi2.WriteTo( tree );
      expectHitInBLayer.WriteTo( tree );
      trackd0_physics.WriteTo( tree );
      etaSampling1.WriteTo( tree );
      reta.WriteTo( tree );
      topoEtcone20.WriteTo( tree );
      topoEtcone30.WriteTo( tree );
      topoEtcone40.WriteTo( tree );
      nucone20_zpv05.WriteTo( tree );
      nucone30_zpv05.WriteTo( tree );
      nucone40_zpv05.WriteTo( tree );
      cl_E.WriteTo( tree );
      cl_pt.WriteTo( tree );
      cl_eta.WriteTo( tree );
      cl_phi.WriteTo( tree );
      etas0.WriteTo( tree );
      etas1.WriteTo( tree );
      etas2.WriteTo( tree );
      etas3.WriteTo( tree );
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
      nBLayerOutliers.WriteTo( tree );
      nPixelOutliers.WriteTo( tree );
      nSCTOutliers.WriteTo( tree );
      nTRTOutliers.WriteTo( tree );
      nTRTHighTOutliers.WriteTo( tree );
      nContribPixelLayers.WriteTo( tree );
      expectBLayerHit.WriteTo( tree );
      nSiHits.WriteTo( tree );
      TRTHighTHitsRatio.WriteTo( tree );
      TRTHighTOutliersRatio.WriteTo( tree );
      trackd0pv.WriteTo( tree );
      trackz0pv.WriteTo( tree );
      tracksigd0pv.WriteTo( tree );
      tracksigz0pv.WriteTo( tree );
      trackIPEstimate_d0_unbiasedpvunbiased.WriteTo( tree );
      trackIPEstimate_z0_unbiasedpvunbiased.WriteTo( tree );
      trackIPEstimate_sigd0_unbiasedpvunbiased.WriteTo( tree );
      trackIPEstimate_sigz0_unbiasedpvunbiased.WriteTo( tree );
      nucone20_trk500MeV.WriteTo( tree );
      nucone30_trk500MeV.WriteTo( tree );
      nucone40_trk500MeV.WriteTo( tree );
      Etcone40_ED_corrected.WriteTo( tree );
      Etcone40_corrected.WriteTo( tree );
      topoEtcone20_corrected.WriteTo( tree );
      topoEtcone30_corrected.WriteTo( tree );
      topoEtcone40_corrected.WriteTo( tree );
      MET_Egamma10NoTau_wpx.WriteTo( tree );
      MET_Egamma10NoTau_wpy.WriteTo( tree );
      MET_Egamma10NoTau_wet.WriteTo( tree );
      MET_Egamma10NoTau_statusWord.WriteTo( tree );

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
      if( OQ.IsActive() ) OQ();
      if( convFlag.IsActive() ) convFlag();
      if( nConv.IsActive() ) nConv();
if (!is_data) {
      if( type.IsActive() ) type();
      if( origin.IsActive() ) origin();
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
      if( loosePP.IsActive() ) loosePP();
      if( loosePPIso.IsActive() ) loosePPIso();
      if( mediumPP.IsActive() ) mediumPP();
      if( mediumPPIso.IsActive() ) mediumPPIso();
      if( tightPP.IsActive() ) tightPP();
      if( tightPPIso.IsActive() ) tightPPIso();
      if( Ethad.IsActive() ) Ethad();
      if( Ethad1.IsActive() ) Ethad1();
      if( f1.IsActive() ) f1();
      if( fside.IsActive() ) fside();
      if( wstot.IsActive() ) wstot();
      if( emaxs1.IsActive() ) emaxs1();
      if( weta2.IsActive() ) weta2();
      if( f3.IsActive() ) f3();
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
      if( deltaeta1.IsActive() ) deltaeta1();
      if( deltaeta2.IsActive() ) deltaeta2();
      if( deltaphi2.IsActive() ) deltaphi2();
      if( expectHitInBLayer.IsActive() ) expectHitInBLayer();
      if( trackd0_physics.IsActive() ) trackd0_physics();
      if( etaSampling1.IsActive() ) etaSampling1();
      if( reta.IsActive() ) reta();
      if( topoEtcone20.IsActive() ) topoEtcone20();
      if( topoEtcone30.IsActive() ) topoEtcone30();
      if( topoEtcone40.IsActive() ) topoEtcone40();
      if( nucone20_zpv05.IsActive() ) nucone20_zpv05();
      if( nucone30_zpv05.IsActive() ) nucone30_zpv05();
      if( nucone40_zpv05.IsActive() ) nucone40_zpv05();
      if( cl_E.IsActive() ) cl_E();
      if( cl_pt.IsActive() ) cl_pt();
      if( cl_eta.IsActive() ) cl_eta();
      if( cl_phi.IsActive() ) cl_phi();
      if( etas0.IsActive() ) etas0();
      if( etas1.IsActive() ) etas1();
      if( etas2.IsActive() ) etas2();
      if( etas3.IsActive() ) etas3();
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
      if( nBLayerOutliers.IsActive() ) nBLayerOutliers();
      if( nPixelOutliers.IsActive() ) nPixelOutliers();
      if( nSCTOutliers.IsActive() ) nSCTOutliers();
      if( nTRTOutliers.IsActive() ) nTRTOutliers();
      if( nTRTHighTOutliers.IsActive() ) nTRTHighTOutliers();
      if( nContribPixelLayers.IsActive() ) nContribPixelLayers();
      if( expectBLayerHit.IsActive() ) expectBLayerHit();
      if( nSiHits.IsActive() ) nSiHits();
      if( TRTHighTHitsRatio.IsActive() ) TRTHighTHitsRatio();
      if( TRTHighTOutliersRatio.IsActive() ) TRTHighTOutliersRatio();
      if( trackd0pv.IsActive() ) trackd0pv();
      if( trackz0pv.IsActive() ) trackz0pv();
      if( tracksigd0pv.IsActive() ) tracksigd0pv();
      if( tracksigz0pv.IsActive() ) tracksigz0pv();
      if( trackIPEstimate_d0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_d0_unbiasedpvunbiased();
      if( trackIPEstimate_z0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_z0_unbiasedpvunbiased();
      if( trackIPEstimate_sigd0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_sigd0_unbiasedpvunbiased();
      if( trackIPEstimate_sigz0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_sigz0_unbiasedpvunbiased();
      if( nucone20_trk500MeV.IsActive() ) nucone20_trk500MeV();
      if( nucone30_trk500MeV.IsActive() ) nucone30_trk500MeV();
      if( nucone40_trk500MeV.IsActive() ) nucone40_trk500MeV();
      if( Etcone40_ED_corrected.IsActive() ) Etcone40_ED_corrected();
      if( Etcone40_corrected.IsActive() ) Etcone40_corrected();
      if( topoEtcone20_corrected.IsActive() ) topoEtcone20_corrected();
      if( topoEtcone30_corrected.IsActive() ) topoEtcone30_corrected();
      if( topoEtcone40_corrected.IsActive() ) topoEtcone40_corrected();
      if( MET_Egamma10NoTau_wpx.IsActive() ) MET_Egamma10NoTau_wpx();
      if( MET_Egamma10NoTau_wpy.IsActive() ) MET_Egamma10NoTau_wpy();
      if( MET_Egamma10NoTau_wet.IsActive() ) MET_Egamma10NoTau_wet();
      if( MET_Egamma10NoTau_statusWord.IsActive() ) MET_Egamma10NoTau_statusWord();

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
      OQ()->clear();
      convFlag()->clear();
      nConv()->clear();
if (!is_data) {
      type()->clear();
      origin()->clear();
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
      loosePP()->clear();
      loosePPIso()->clear();
      mediumPP()->clear();
      mediumPPIso()->clear();
      tightPP()->clear();
      tightPPIso()->clear();
      Ethad()->clear();
      Ethad1()->clear();
      f1()->clear();
      fside()->clear();
      wstot()->clear();
      emaxs1()->clear();
      weta2()->clear();
      f3()->clear();
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
      deltaeta1()->clear();
      deltaeta2()->clear();
      deltaphi2()->clear();
      expectHitInBLayer()->clear();
      trackd0_physics()->clear();
      etaSampling1()->clear();
      reta()->clear();
      topoEtcone20()->clear();
      topoEtcone30()->clear();
      topoEtcone40()->clear();
      nucone20_zpv05()->clear();
      nucone30_zpv05()->clear();
      nucone40_zpv05()->clear();
      cl_E()->clear();
      cl_pt()->clear();
      cl_eta()->clear();
      cl_phi()->clear();
      etas0()->clear();
      etas1()->clear();
      etas2()->clear();
      etas3()->clear();
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
      nBLayerOutliers()->clear();
      nPixelOutliers()->clear();
      nSCTOutliers()->clear();
      nTRTOutliers()->clear();
      nTRTHighTOutliers()->clear();
      nContribPixelLayers()->clear();
      expectBLayerHit()->clear();
      nSiHits()->clear();
      TRTHighTHitsRatio()->clear();
      TRTHighTOutliersRatio()->clear();
      trackd0pv()->clear();
      trackz0pv()->clear();
      tracksigd0pv()->clear();
      tracksigz0pv()->clear();
      trackIPEstimate_d0_unbiasedpvunbiased()->clear();
      trackIPEstimate_z0_unbiasedpvunbiased()->clear();
      trackIPEstimate_sigd0_unbiasedpvunbiased()->clear();
      trackIPEstimate_sigz0_unbiasedpvunbiased()->clear();
      nucone20_trk500MeV()->clear();
      nucone30_trk500MeV()->clear();
      nucone40_trk500MeV()->clear();
      Etcone40_ED_corrected()->clear();
      Etcone40_corrected()->clear();
      topoEtcone20_corrected()->clear();
      topoEtcone30_corrected()->clear();
      topoEtcone40_corrected()->clear();
      MET_Egamma10NoTau_wpx()->clear();
      MET_Egamma10NoTau_wpy()->clear();
      MET_Egamma10NoTau_wet()->clear();
      MET_Egamma10NoTau_statusWord()->clear();

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
      if( el.nConv.IsAvailable() ) {
         nConv()->push_back( el.nConv() );
      } else {
         nConv()->push_back( std::numeric_limits< int >::min() );
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
      if( el.fside.IsAvailable() ) {
         fside()->push_back( el.fside() );
      } else {
         fside()->push_back( std::numeric_limits< float >::min() );
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
      if( el.etas0.IsAvailable() ) {
         etas0()->push_back( el.etas0() );
      } else {
         etas0()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etas1.IsAvailable() ) {
         etas1()->push_back( el.etas1() );
      } else {
         etas1()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etas2.IsAvailable() ) {
         etas2()->push_back( el.etas2() );
      } else {
         etas2()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.etas3.IsAvailable() ) {
         etas3()->push_back( el.etas3() );
      } else {
         etas3()->push_back( std::numeric_limits< float >::min() );
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
