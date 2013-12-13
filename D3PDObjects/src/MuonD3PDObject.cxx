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
        etcone20( parent.etcone20, index, this ),
        etcone30( parent.etcone30, index, this ),
        etcone40( parent.etcone40, index, this ),
        ptcone20( parent.ptcone20, index, this ),
        ptcone30( parent.ptcone30, index, this ),
        ptcone40( parent.ptcone40, index, this ),
        isCombinedMuon( parent.isCombinedMuon, index, this ),
        isSegmentTaggedMuon( parent.isSegmentTaggedMuon, index, this ),
        loose( parent.loose, index, this ),
        d0_exPV( parent.d0_exPV, index, this ),
        z0_exPV( parent.z0_exPV, index, this ),
        qoverp_exPV( parent.qoverp_exPV, index, this ),
        id_theta_exPV( parent.id_theta_exPV, index, this ),
        id_qoverp_exPV( parent.id_qoverp_exPV, index, this ),
        me_theta_exPV( parent.me_theta_exPV, index, this ),
        me_qoverp_exPV( parent.me_qoverp_exPV, index, this ),
        cov_d0_exPV( parent.cov_d0_exPV, index, this ),
        cov_qoverp_exPV( parent.cov_qoverp_exPV, index, this ),
        cov_z0_qoverp_exPV( parent.cov_z0_qoverp_exPV, index, this ),
        me_cov_qoverp_exPV( parent.me_cov_qoverp_exPV, index, this ),
        ms_phi( parent.ms_phi, index, this ),
        ms_theta( parent.ms_theta, index, this ),
        ms_qoverp( parent.ms_qoverp, index, this ),
        id_theta( parent.id_theta, index, this ),
        nBLHits( parent.nBLHits, index, this ),
        nPixHits( parent.nPixHits, index, this ),
        nSCTHits( parent.nSCTHits, index, this ),
        nTRTHits( parent.nTRTHits, index, this ),
        nPixHoles( parent.nPixHoles, index, this ),
        nSCTHoles( parent.nSCTHoles, index, this ),
        nTRTOutliers( parent.nTRTOutliers, index, this ),
        nTRTHighTOutliers( parent.nTRTHighTOutliers, index, this ),
        nPixelDeadSensors( parent.nPixelDeadSensors, index, this ),
        nSCTDeadSensors( parent.nSCTDeadSensors, index, this ),
        expectBLayerHit( parent.expectBLayerHit, index, this ),
        nMDTHits( parent.nMDTHits, index, this ),
        nCSCEtaHits( parent.nCSCEtaHits, index, this ),
        nMDTBIHits( parent.nMDTBIHits, index, this ),
        nMDTBMHits( parent.nMDTBMHits, index, this ),
        nMDTBOHits( parent.nMDTBOHits, index, this ),
        nMDTEIHits( parent.nMDTEIHits, index, this ),
        nMDTEMHits( parent.nMDTEMHits, index, this ),
        nMDTEOHits( parent.nMDTEOHits, index, this ),
        nMDTEEHits( parent.nMDTEEHits, index, this ),
        trackIPEstimate_d0_unbiasedpvunbiased( parent.trackIPEstimate_d0_unbiasedpvunbiased, index, this ),
        trackIPEstimate_z0_unbiasedpvunbiased( parent.trackIPEstimate_z0_unbiasedpvunbiased, index, this ),
        trackIPEstimate_sigd0_unbiasedpvunbiased( parent.trackIPEstimate_sigd0_unbiasedpvunbiased, index, this ),
// MC only
        type( parent.type, index, this ),
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
        ptcone20_trkelstyle( parent.ptcone20_trkelstyle, index, this ),
        ptcone30_trkelstyle( parent.ptcone30_trkelstyle, index, this ),
        ptcone40_trkelstyle( parent.ptcone40_trkelstyle, index, this ),
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
        etcone20( parent.etcone20 ),
        etcone30( parent.etcone30 ),
        etcone40( parent.etcone40 ),
        ptcone20( parent.ptcone20 ),
        ptcone30( parent.ptcone30 ),
        ptcone40( parent.ptcone40 ),
        isCombinedMuon( parent.isCombinedMuon ),
        isSegmentTaggedMuon( parent.isSegmentTaggedMuon ),
        loose( parent.loose ),
        d0_exPV( parent.d0_exPV ),
        z0_exPV( parent.z0_exPV ),
        qoverp_exPV( parent.qoverp_exPV ),
        id_theta_exPV( parent.id_theta_exPV ),
        id_qoverp_exPV( parent.id_qoverp_exPV ),
        me_theta_exPV( parent.me_theta_exPV ),
        me_qoverp_exPV( parent.me_qoverp_exPV ),
        cov_d0_exPV( parent.cov_d0_exPV ),
        cov_qoverp_exPV( parent.cov_qoverp_exPV ),
        cov_z0_qoverp_exPV( parent.cov_z0_qoverp_exPV ),
        me_cov_qoverp_exPV( parent.me_cov_qoverp_exPV ),
        ms_phi( parent.ms_phi ),
        ms_theta( parent.ms_theta ),
        ms_qoverp( parent.ms_qoverp ),
        id_theta( parent.id_theta ),
        nBLHits( parent.nBLHits ),
        nPixHits( parent.nPixHits ),
        nSCTHits( parent.nSCTHits ),
        nTRTHits( parent.nTRTHits ),
        nPixHoles( parent.nPixHoles ),
        nSCTHoles( parent.nSCTHoles ),
        nTRTOutliers( parent.nTRTOutliers ),
        nTRTHighTOutliers( parent.nTRTHighTOutliers ),
        nPixelDeadSensors( parent.nPixelDeadSensors ),
        nSCTDeadSensors( parent.nSCTDeadSensors ),
        expectBLayerHit( parent.expectBLayerHit ),
        nMDTHits( parent.nMDTHits ),
        nCSCEtaHits( parent.nCSCEtaHits ),
        nMDTBIHits( parent.nMDTBIHits ),
        nMDTBMHits( parent.nMDTBMHits ),
        nMDTBOHits( parent.nMDTBOHits ),
        nMDTEIHits( parent.nMDTEIHits ),
        nMDTEMHits( parent.nMDTEMHits ),
        nMDTEOHits( parent.nMDTEOHits ),
        nMDTEEHits( parent.nMDTEEHits ),
        trackIPEstimate_d0_unbiasedpvunbiased( parent.trackIPEstimate_d0_unbiasedpvunbiased ),
        trackIPEstimate_z0_unbiasedpvunbiased( parent.trackIPEstimate_z0_unbiasedpvunbiased ),
        trackIPEstimate_sigd0_unbiasedpvunbiased( parent.trackIPEstimate_sigd0_unbiasedpvunbiased ),
// MC only
        type( parent.type ),
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
        ptcone20_trkelstyle( parent.ptcone20_trkelstyle ),
        ptcone30_trkelstyle( parent.ptcone30_trkelstyle ),
        ptcone40_trkelstyle( parent.ptcone40_trkelstyle ),
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
        etcone20( this, ::TString( prefix ) + "etcone20", &master ),
        etcone30( this, ::TString( prefix ) + "etcone30", &master ),
        etcone40( this, ::TString( prefix ) + "etcone40", &master ),
        ptcone20( this, ::TString( prefix ) + "ptcone20", &master ),
        ptcone30( this, ::TString( prefix ) + "ptcone30", &master ),
        ptcone40( this, ::TString( prefix ) + "ptcone40", &master ),
        isCombinedMuon( this, ::TString( prefix ) + "isCombinedMuon", &master ),
        isSegmentTaggedMuon( this, ::TString( prefix ) + "isSegmentTaggedMuon", &master ),
        loose( this, ::TString( prefix ) + "loose", &master ),
        d0_exPV( this, ::TString( prefix ) + "d0_exPV", &master ),
        z0_exPV( this, ::TString( prefix ) + "z0_exPV", &master ),
        qoverp_exPV( this, ::TString( prefix ) + "qoverp_exPV", &master ),
        id_theta_exPV( this, ::TString( prefix ) + "id_theta_exPV", &master ),
        id_qoverp_exPV( this, ::TString( prefix ) + "id_qoverp_exPV", &master ),
        me_theta_exPV( this, ::TString( prefix ) + "me_theta_exPV", &master ),
        me_qoverp_exPV( this, ::TString( prefix ) + "me_qoverp_exPV", &master ),
        cov_d0_exPV( this, ::TString( prefix ) + "cov_d0_exPV", &master ),
        cov_qoverp_exPV( this, ::TString( prefix ) + "cov_qoverp_exPV", &master ),
        cov_z0_qoverp_exPV( this, ::TString( prefix ) + "cov_z0_qoverp_exPV", &master ),
        me_cov_qoverp_exPV( this, ::TString( prefix ) + "me_cov_qoverp_exPV", &master ),
        ms_phi( this, ::TString( prefix ) + "ms_phi", &master ),
        ms_theta( this, ::TString( prefix ) + "ms_theta", &master ),
        ms_qoverp( this, ::TString( prefix ) + "ms_qoverp", &master ),
        id_theta( this, ::TString( prefix ) + "id_theta", &master ),
        nBLHits( this, ::TString( prefix ) + "nBLHits", &master ),
        nPixHits( this, ::TString( prefix ) + "nPixHits", &master ),
        nSCTHits( this, ::TString( prefix ) + "nSCTHits", &master ),
        nTRTHits( this, ::TString( prefix ) + "nTRTHits", &master ),
        nPixHoles( this, ::TString( prefix ) + "nPixHoles", &master ),
        nSCTHoles( this, ::TString( prefix ) + "nSCTHoles", &master ),
        nTRTOutliers( this, ::TString( prefix ) + "nTRTOutliers", &master ),
        nTRTHighTOutliers( this, ::TString( prefix ) + "nTRTHighTOutliers", &master ),
        nPixelDeadSensors( this, ::TString( prefix ) + "nPixelDeadSensors", &master ),
        nSCTDeadSensors( this, ::TString( prefix ) + "nSCTDeadSensors", &master ),
        expectBLayerHit( this, ::TString( prefix ) + "expectBLayerHit", &master ),
        nMDTHits( this, ::TString( prefix ) + "nMDTHits", &master ),
        nCSCEtaHits( this, ::TString( prefix ) + "nCSCEtaHits", &master ),
        nMDTBIHits( this, ::TString( prefix ) + "nMDTBIHits", &master ),
        nMDTBMHits( this, ::TString( prefix ) + "nMDTBMHits", &master ),
        nMDTBOHits( this, ::TString( prefix ) + "nMDTBOHits", &master ),
        nMDTEIHits( this, ::TString( prefix ) + "nMDTEIHits", &master ),
        nMDTEMHits( this, ::TString( prefix ) + "nMDTEMHits", &master ),
        nMDTEOHits( this, ::TString( prefix ) + "nMDTEOHits", &master ),
        nMDTEEHits( this, ::TString( prefix ) + "nMDTEEHits", &master ),
        trackIPEstimate_d0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_d0_unbiasedpvunbiased", &master ),
        trackIPEstimate_z0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_z0_unbiasedpvunbiased", &master ),
        trackIPEstimate_sigd0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigd0_unbiasedpvunbiased", &master ),
// MC only
        type( this, ::TString( prefix ) + "type", &master ),
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
        ptcone20_trkelstyle( this, ::TString( prefix ) + "ptcone20_trkelstyle", &master ),
        ptcone30_trkelstyle( this, ::TString( prefix ) + "ptcone30_trkelstyle", &master ),
        ptcone40_trkelstyle( this, ::TString( prefix ) + "ptcone40_trkelstyle", &master ),
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
      fHandles[ "pt" ] = &pt;
      fHandles[ "m" ] = &m;
      fHandles[ "eta" ] = &eta;
      fHandles[ "phi" ] = &phi;
      fHandles[ "px" ] = &px;
      fHandles[ "py" ] = &py;
      fHandles[ "pz" ] = &pz;
      fHandles[ "charge" ] = &charge;
      fHandles[ "etcone20" ] = &etcone20;
      fHandles[ "etcone30" ] = &etcone30;
      fHandles[ "etcone40" ] = &etcone40;
      fHandles[ "ptcone20" ] = &ptcone20;
      fHandles[ "ptcone30" ] = &ptcone30;
      fHandles[ "ptcone40" ] = &ptcone40;
      fHandles[ "isCombinedMuon" ] = &isCombinedMuon;
      fHandles[ "isSegmentTaggedMuon" ] = &isSegmentTaggedMuon;
      fHandles[ "loose" ] = &loose;
      fHandles[ "d0_exPV" ] = &d0_exPV;
      fHandles[ "z0_exPV" ] = &z0_exPV;
      fHandles[ "qoverp_exPV" ] = &qoverp_exPV;
      fHandles[ "id_theta_exPV" ] = &id_theta_exPV;
      fHandles[ "id_qoverp_exPV" ] = &id_qoverp_exPV;
      fHandles[ "me_theta_exPV" ] = &me_theta_exPV;
      fHandles[ "me_qoverp_exPV" ] = &me_qoverp_exPV;
      fHandles[ "cov_d0_exPV" ] = &cov_d0_exPV;
      fHandles[ "cov_qoverp_exPV" ] = &cov_qoverp_exPV;
      fHandles[ "cov_z0_qoverp_exPV" ] = &cov_z0_qoverp_exPV;
      fHandles[ "me_cov_qoverp_exPV" ] = &me_cov_qoverp_exPV;
      fHandles[ "ms_phi" ] = &ms_phi;
      fHandles[ "ms_theta" ] = &ms_theta;
      fHandles[ "ms_qoverp" ] = &ms_qoverp;
      fHandles[ "id_theta" ] = &id_theta;
      fHandles[ "nBLHits" ] = &nBLHits;
      fHandles[ "nPixHits" ] = &nPixHits;
      fHandles[ "nSCTHits" ] = &nSCTHits;
      fHandles[ "nTRTHits" ] = &nTRTHits;
      fHandles[ "nPixHoles" ] = &nPixHoles;
      fHandles[ "nSCTHoles" ] = &nSCTHoles;
      fHandles[ "nTRTOutliers" ] = &nTRTOutliers;
      fHandles[ "nTRTHighTOutliers" ] = &nTRTHighTOutliers;
      fHandles[ "nPixelDeadSensors" ] = &nPixelDeadSensors;
      fHandles[ "nSCTDeadSensors" ] = &nSCTDeadSensors;
      fHandles[ "expectBLayerHit" ] = &expectBLayerHit;
      fHandles[ "nMDTHits" ] = &nMDTHits;
      fHandles[ "nCSCEtaHits" ] = &nCSCEtaHits;
      fHandles[ "nMDTBIHits" ] = &nMDTBIHits;
      fHandles[ "nMDTBMHits" ] = &nMDTBMHits;
      fHandles[ "nMDTBOHits" ] = &nMDTBOHits;
      fHandles[ "nMDTEIHits" ] = &nMDTEIHits;
      fHandles[ "nMDTEMHits" ] = &nMDTEMHits;
      fHandles[ "nMDTEOHits" ] = &nMDTEOHits;
      fHandles[ "nMDTEEHits" ] = &nMDTEEHits;
      fHandles[ "trackIPEstimate_d0_unbiasedpvunbiased" ] = &trackIPEstimate_d0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_z0_unbiasedpvunbiased" ] = &trackIPEstimate_z0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_sigd0_unbiasedpvunbiased" ] = &trackIPEstimate_sigd0_unbiasedpvunbiased;
if (!is_data) {
      fHandles[ "type" ] = &type;
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
      fHandles[ "ptcone20_trkelstyle" ] = &ptcone20_trkelstyle;
      fHandles[ "ptcone30_trkelstyle" ] = &ptcone30_trkelstyle;
      fHandles[ "ptcone40_trkelstyle" ] = &ptcone40_trkelstyle;
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
        etcone20( this, ::TString( prefix ) + "etcone20", 0 ),
        etcone30( this, ::TString( prefix ) + "etcone30", 0 ),
        etcone40( this, ::TString( prefix ) + "etcone40", 0 ),
        ptcone20( this, ::TString( prefix ) + "ptcone20", 0 ),
        ptcone30( this, ::TString( prefix ) + "ptcone30", 0 ),
        ptcone40( this, ::TString( prefix ) + "ptcone40", 0 ),
        isCombinedMuon( this, ::TString( prefix ) + "isCombinedMuon", 0 ),
        isSegmentTaggedMuon( this, ::TString( prefix ) + "isSegmentTaggedMuon", 0 ),
        loose( this, ::TString( prefix ) + "loose", 0 ),
        d0_exPV( this, ::TString( prefix ) + "d0_exPV", 0 ),
        z0_exPV( this, ::TString( prefix ) + "z0_exPV", 0 ),
        qoverp_exPV( this, ::TString( prefix ) + "qoverp_exPV", 0 ),
        id_theta_exPV( this, ::TString( prefix ) + "id_theta_exPV", 0 ),
        id_qoverp_exPV( this, ::TString( prefix ) + "id_qoverp_exPV", 0 ),
        me_theta_exPV( this, ::TString( prefix ) + "me_theta_exPV", 0 ),
        me_qoverp_exPV( this, ::TString( prefix ) + "me_qoverp_exPV", 0 ),
        cov_d0_exPV( this, ::TString( prefix ) + "cov_d0_exPV", 0 ),
        cov_qoverp_exPV( this, ::TString( prefix ) + "cov_qoverp_exPV", 0 ),
        cov_z0_qoverp_exPV( this, ::TString( prefix ) + "cov_z0_qoverp_exPV", 0 ),
        me_cov_qoverp_exPV( this, ::TString( prefix ) + "me_cov_qoverp_exPV", 0 ),
        ms_phi( this, ::TString( prefix ) + "ms_phi", 0 ),
        ms_theta( this, ::TString( prefix ) + "ms_theta", 0 ),
        ms_qoverp( this, ::TString( prefix ) + "ms_qoverp", 0 ),
        id_theta( this, ::TString( prefix ) + "id_theta", 0 ),
        nBLHits( this, ::TString( prefix ) + "nBLHits", 0 ),
        nPixHits( this, ::TString( prefix ) + "nPixHits", 0 ),
        nSCTHits( this, ::TString( prefix ) + "nSCTHits", 0 ),
        nTRTHits( this, ::TString( prefix ) + "nTRTHits", 0 ),
        nPixHoles( this, ::TString( prefix ) + "nPixHoles", 0 ),
        nSCTHoles( this, ::TString( prefix ) + "nSCTHoles", 0 ),
        nTRTOutliers( this, ::TString( prefix ) + "nTRTOutliers", 0 ),
        nTRTHighTOutliers( this, ::TString( prefix ) + "nTRTHighTOutliers", 0 ),
        nPixelDeadSensors( this, ::TString( prefix ) + "nPixelDeadSensors", 0 ),
        nSCTDeadSensors( this, ::TString( prefix ) + "nSCTDeadSensors", 0 ),
        expectBLayerHit( this, ::TString( prefix ) + "expectBLayerHit", 0 ),
        nMDTHits( this, ::TString( prefix ) + "nMDTHits", 0 ),
        nCSCEtaHits( this, ::TString( prefix ) + "nCSCEtaHits", 0 ),
        nMDTBIHits( this, ::TString( prefix ) + "nMDTBIHits", 0 ),
        nMDTBMHits( this, ::TString( prefix ) + "nMDTBMHits", 0 ),
        nMDTBOHits( this, ::TString( prefix ) + "nMDTBOHits", 0 ),
        nMDTEIHits( this, ::TString( prefix ) + "nMDTEIHits", 0 ),
        nMDTEMHits( this, ::TString( prefix ) + "nMDTEMHits", 0 ),
        nMDTEOHits( this, ::TString( prefix ) + "nMDTEOHits", 0 ),
        nMDTEEHits( this, ::TString( prefix ) + "nMDTEEHits", 0 ),
        trackIPEstimate_d0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_d0_unbiasedpvunbiased", 0 ),
        trackIPEstimate_z0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_z0_unbiasedpvunbiased", 0 ),
        trackIPEstimate_sigd0_unbiasedpvunbiased( this, ::TString( prefix ) + "trackIPEstimate_sigd0_unbiasedpvunbiased", 0 ),
// MC only
        type( this, ::TString( prefix ) + "type", 0 ),
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
        ptcone20_trkelstyle( this, ::TString( prefix ) + "ptcone20_trkelstyle", 0 ),
        ptcone30_trkelstyle( this, ::TString( prefix ) + "ptcone30_trkelstyle", 0 ),
        ptcone40_trkelstyle( this, ::TString( prefix ) + "ptcone40_trkelstyle", 0 ),
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
      fHandles[ "pt" ] = &pt;
      fHandles[ "m" ] = &m;
      fHandles[ "eta" ] = &eta;
      fHandles[ "phi" ] = &phi;
      fHandles[ "px" ] = &px;
      fHandles[ "py" ] = &py;
      fHandles[ "pz" ] = &pz;
      fHandles[ "charge" ] = &charge;
      fHandles[ "etcone20" ] = &etcone20;
      fHandles[ "etcone30" ] = &etcone30;
      fHandles[ "etcone40" ] = &etcone40;
      fHandles[ "ptcone20" ] = &ptcone20;
      fHandles[ "ptcone30" ] = &ptcone30;
      fHandles[ "ptcone40" ] = &ptcone40;
      fHandles[ "isCombinedMuon" ] = &isCombinedMuon;
      fHandles[ "isSegmentTaggedMuon" ] = &isSegmentTaggedMuon;
      fHandles[ "loose" ] = &loose;
      fHandles[ "d0_exPV" ] = &d0_exPV;
      fHandles[ "z0_exPV" ] = &z0_exPV;
      fHandles[ "qoverp_exPV" ] = &qoverp_exPV;
      fHandles[ "id_theta_exPV" ] = &id_theta_exPV;
      fHandles[ "id_qoverp_exPV" ] = &id_qoverp_exPV;
      fHandles[ "me_theta_exPV" ] = &me_theta_exPV;
      fHandles[ "me_qoverp_exPV" ] = &me_qoverp_exPV;
      fHandles[ "cov_d0_exPV" ] = &cov_d0_exPV;
      fHandles[ "cov_qoverp_exPV" ] = &cov_qoverp_exPV;
      fHandles[ "cov_z0_qoverp_exPV" ] = &cov_z0_qoverp_exPV;
      fHandles[ "me_cov_qoverp_exPV" ] = &me_cov_qoverp_exPV;
      fHandles[ "ms_phi" ] = &ms_phi;
      fHandles[ "ms_theta" ] = &ms_theta;
      fHandles[ "ms_qoverp" ] = &ms_qoverp;
      fHandles[ "id_theta" ] = &id_theta;
      fHandles[ "nBLHits" ] = &nBLHits;
      fHandles[ "nPixHits" ] = &nPixHits;
      fHandles[ "nSCTHits" ] = &nSCTHits;
      fHandles[ "nTRTHits" ] = &nTRTHits;
      fHandles[ "nPixHoles" ] = &nPixHoles;
      fHandles[ "nSCTHoles" ] = &nSCTHoles;
      fHandles[ "nTRTOutliers" ] = &nTRTOutliers;
      fHandles[ "nTRTHighTOutliers" ] = &nTRTHighTOutliers;
      fHandles[ "nPixelDeadSensors" ] = &nPixelDeadSensors;
      fHandles[ "nSCTDeadSensors" ] = &nSCTDeadSensors;
      fHandles[ "expectBLayerHit" ] = &expectBLayerHit;
      fHandles[ "nMDTHits" ] = &nMDTHits;
      fHandles[ "nCSCEtaHits" ] = &nCSCEtaHits;
      fHandles[ "nMDTBIHits" ] = &nMDTBIHits;
      fHandles[ "nMDTBMHits" ] = &nMDTBMHits;
      fHandles[ "nMDTBOHits" ] = &nMDTBOHits;
      fHandles[ "nMDTEIHits" ] = &nMDTEIHits;
      fHandles[ "nMDTEMHits" ] = &nMDTEMHits;
      fHandles[ "nMDTEOHits" ] = &nMDTEOHits;
      fHandles[ "nMDTEEHits" ] = &nMDTEEHits;
      fHandles[ "trackIPEstimate_d0_unbiasedpvunbiased" ] = &trackIPEstimate_d0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_z0_unbiasedpvunbiased" ] = &trackIPEstimate_z0_unbiasedpvunbiased;
      fHandles[ "trackIPEstimate_sigd0_unbiasedpvunbiased" ] = &trackIPEstimate_sigd0_unbiasedpvunbiased;
if (!is_data) {
      fHandles[ "type" ] = &type;
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
      fHandles[ "ptcone20_trkelstyle" ] = &ptcone20_trkelstyle;
      fHandles[ "ptcone30_trkelstyle" ] = &ptcone30_trkelstyle;
      fHandles[ "ptcone40_trkelstyle" ] = &ptcone40_trkelstyle;
      fHandles[ "MET_Egamma10NoTau_wpx" ] = &MET_Egamma10NoTau_wpx;
      fHandles[ "MET_Egamma10NoTau_wpy" ] = &MET_Egamma10NoTau_wpy;
      fHandles[ "MET_Egamma10NoTau_wet" ] = &MET_Egamma10NoTau_wet;
      fHandles[ "MET_Egamma10NoTau_statusWord" ] = &MET_Egamma10NoTau_statusWord;
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
      etcone20.SetName( ::TString( prefix ) + "etcone20" );
      etcone30.SetName( ::TString( prefix ) + "etcone30" );
      etcone40.SetName( ::TString( prefix ) + "etcone40" );
      ptcone20.SetName( ::TString( prefix ) + "ptcone20" );
      ptcone30.SetName( ::TString( prefix ) + "ptcone30" );
      ptcone40.SetName( ::TString( prefix ) + "ptcone40" );
      isCombinedMuon.SetName( ::TString( prefix ) + "isCombinedMuon" );
      isSegmentTaggedMuon.SetName( ::TString( prefix ) + "isSegmentTaggedMuon" );
      loose.SetName( ::TString( prefix ) + "loose" );
      d0_exPV.SetName( ::TString( prefix ) + "d0_exPV" );
      z0_exPV.SetName( ::TString( prefix ) + "z0_exPV" );
      qoverp_exPV.SetName( ::TString( prefix ) + "qoverp_exPV" );
      id_theta_exPV.SetName( ::TString( prefix ) + "id_theta_exPV" );
      id_qoverp_exPV.SetName( ::TString( prefix ) + "id_qoverp_exPV" );
      me_theta_exPV.SetName( ::TString( prefix ) + "me_theta_exPV" );
      me_qoverp_exPV.SetName( ::TString( prefix ) + "me_qoverp_exPV" );
      cov_d0_exPV.SetName( ::TString( prefix ) + "cov_d0_exPV" );
      cov_qoverp_exPV.SetName( ::TString( prefix ) + "cov_qoverp_exPV" );
      cov_z0_qoverp_exPV.SetName( ::TString( prefix ) + "cov_z0_qoverp_exPV" );
      me_cov_qoverp_exPV.SetName( ::TString( prefix ) + "me_cov_qoverp_exPV" );
      ms_phi.SetName( ::TString( prefix ) + "ms_phi" );
      ms_theta.SetName( ::TString( prefix ) + "ms_theta" );
      ms_qoverp.SetName( ::TString( prefix ) + "ms_qoverp" );
      id_theta.SetName( ::TString( prefix ) + "id_theta" );
      nBLHits.SetName( ::TString( prefix ) + "nBLHits" );
      nPixHits.SetName( ::TString( prefix ) + "nPixHits" );
      nSCTHits.SetName( ::TString( prefix ) + "nSCTHits" );
      nTRTHits.SetName( ::TString( prefix ) + "nTRTHits" );
      nPixHoles.SetName( ::TString( prefix ) + "nPixHoles" );
      nSCTHoles.SetName( ::TString( prefix ) + "nSCTHoles" );
      nTRTOutliers.SetName( ::TString( prefix ) + "nTRTOutliers" );
      nTRTHighTOutliers.SetName( ::TString( prefix ) + "nTRTHighTOutliers" );
      nPixelDeadSensors.SetName( ::TString( prefix ) + "nPixelDeadSensors" );
      nSCTDeadSensors.SetName( ::TString( prefix ) + "nSCTDeadSensors" );
      expectBLayerHit.SetName( ::TString( prefix ) + "expectBLayerHit" );
      nMDTHits.SetName( ::TString( prefix ) + "nMDTHits" );
      nCSCEtaHits.SetName( ::TString( prefix ) + "nCSCEtaHits" );
      nMDTBIHits.SetName( ::TString( prefix ) + "nMDTBIHits" );
      nMDTBMHits.SetName( ::TString( prefix ) + "nMDTBMHits" );
      nMDTBOHits.SetName( ::TString( prefix ) + "nMDTBOHits" );
      nMDTEIHits.SetName( ::TString( prefix ) + "nMDTEIHits" );
      nMDTEMHits.SetName( ::TString( prefix ) + "nMDTEMHits" );
      nMDTEOHits.SetName( ::TString( prefix ) + "nMDTEOHits" );
      nMDTEEHits.SetName( ::TString( prefix ) + "nMDTEEHits" );
      trackIPEstimate_d0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_d0_unbiasedpvunbiased" );
      trackIPEstimate_z0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_z0_unbiasedpvunbiased" );
      trackIPEstimate_sigd0_unbiasedpvunbiased.SetName( ::TString( prefix ) + "trackIPEstimate_sigd0_unbiasedpvunbiased" );
if (!is_data) {
      type.SetName( ::TString( prefix ) + "type" );
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
      ptcone20_trkelstyle.SetName( ::TString( prefix ) + "ptcone20_trkelstyle" );
      ptcone30_trkelstyle.SetName( ::TString( prefix ) + "ptcone30_trkelstyle" );
      ptcone40_trkelstyle.SetName( ::TString( prefix ) + "ptcone40_trkelstyle" );
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
      etcone20.ReadFrom( tree );
      etcone30.ReadFrom( tree );
      etcone40.ReadFrom( tree );
      ptcone20.ReadFrom( tree );
      ptcone30.ReadFrom( tree );
      ptcone40.ReadFrom( tree );
      isCombinedMuon.ReadFrom( tree );
      isSegmentTaggedMuon.ReadFrom( tree );
      loose.ReadFrom( tree );
      d0_exPV.ReadFrom( tree );
      z0_exPV.ReadFrom( tree );
      qoverp_exPV.ReadFrom( tree );
      id_theta_exPV.ReadFrom( tree );
      id_qoverp_exPV.ReadFrom( tree );
      me_theta_exPV.ReadFrom( tree );
      me_qoverp_exPV.ReadFrom( tree );
      cov_d0_exPV.ReadFrom( tree );
      cov_qoverp_exPV.ReadFrom( tree );
      cov_z0_qoverp_exPV.ReadFrom( tree );
      me_cov_qoverp_exPV.ReadFrom( tree );
      ms_phi.ReadFrom( tree );
      ms_theta.ReadFrom( tree );
      ms_qoverp.ReadFrom( tree );
      id_theta.ReadFrom( tree );
      nBLHits.ReadFrom( tree );
      nPixHits.ReadFrom( tree );
      nSCTHits.ReadFrom( tree );
      nTRTHits.ReadFrom( tree );
      nPixHoles.ReadFrom( tree );
      nSCTHoles.ReadFrom( tree );
      nTRTOutliers.ReadFrom( tree );
      nTRTHighTOutliers.ReadFrom( tree );
      nPixelDeadSensors.ReadFrom( tree );
      nSCTDeadSensors.ReadFrom( tree );
      expectBLayerHit.ReadFrom( tree );
      nMDTHits.ReadFrom( tree );
      nCSCEtaHits.ReadFrom( tree );
      nMDTBIHits.ReadFrom( tree );
      nMDTBMHits.ReadFrom( tree );
      nMDTBOHits.ReadFrom( tree );
      nMDTEIHits.ReadFrom( tree );
      nMDTEMHits.ReadFrom( tree );
      nMDTEOHits.ReadFrom( tree );
      nMDTEEHits.ReadFrom( tree );
      trackIPEstimate_d0_unbiasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_z0_unbiasedpvunbiased.ReadFrom( tree );
      trackIPEstimate_sigd0_unbiasedpvunbiased.ReadFrom( tree );
if (!is_data) {
      type.ReadFrom( tree );
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
      ptcone20_trkelstyle.ReadFrom( tree );
      ptcone30_trkelstyle.ReadFrom( tree );
      ptcone40_trkelstyle.ReadFrom( tree );
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
      etcone20.WriteTo( tree );
      etcone30.WriteTo( tree );
      etcone40.WriteTo( tree );
      ptcone20.WriteTo( tree );
      ptcone30.WriteTo( tree );
      ptcone40.WriteTo( tree );
      isCombinedMuon.WriteTo( tree );
      isSegmentTaggedMuon.WriteTo( tree );
      loose.WriteTo( tree );
      d0_exPV.WriteTo( tree );
      z0_exPV.WriteTo( tree );
      qoverp_exPV.WriteTo( tree );
      id_theta_exPV.WriteTo( tree );
      id_qoverp_exPV.WriteTo( tree );
      me_theta_exPV.WriteTo( tree );
      me_qoverp_exPV.WriteTo( tree );
      cov_d0_exPV.WriteTo( tree );
      cov_qoverp_exPV.WriteTo( tree );
      cov_z0_qoverp_exPV.WriteTo( tree );
      me_cov_qoverp_exPV.WriteTo( tree );
      ms_phi.WriteTo( tree );
      ms_theta.WriteTo( tree );
      ms_qoverp.WriteTo( tree );
      id_theta.WriteTo( tree );
      nBLHits.WriteTo( tree );
      nPixHits.WriteTo( tree );
      nSCTHits.WriteTo( tree );
      nTRTHits.WriteTo( tree );
      nPixHoles.WriteTo( tree );
      nSCTHoles.WriteTo( tree );
      nTRTOutliers.WriteTo( tree );
      nTRTHighTOutliers.WriteTo( tree );
      nPixelDeadSensors.WriteTo( tree );
      nSCTDeadSensors.WriteTo( tree );
      expectBLayerHit.WriteTo( tree );
      nMDTHits.WriteTo( tree );
      nCSCEtaHits.WriteTo( tree );
      nMDTBIHits.WriteTo( tree );
      nMDTBMHits.WriteTo( tree );
      nMDTBOHits.WriteTo( tree );
      nMDTEIHits.WriteTo( tree );
      nMDTEMHits.WriteTo( tree );
      nMDTEOHits.WriteTo( tree );
      nMDTEEHits.WriteTo( tree );
      trackIPEstimate_d0_unbiasedpvunbiased.WriteTo( tree );
      trackIPEstimate_z0_unbiasedpvunbiased.WriteTo( tree );
      trackIPEstimate_sigd0_unbiasedpvunbiased.WriteTo( tree );
if (!is_data) {
      type.WriteTo( tree );
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
      ptcone20_trkelstyle.WriteTo( tree );
      ptcone30_trkelstyle.WriteTo( tree );
      ptcone40_trkelstyle.WriteTo( tree );
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
      if( etcone20.IsActive() ) etcone20();
      if( etcone30.IsActive() ) etcone30();
      if( etcone40.IsActive() ) etcone40();
      if( ptcone20.IsActive() ) ptcone20();
      if( ptcone30.IsActive() ) ptcone30();
      if( ptcone40.IsActive() ) ptcone40();
      if( isCombinedMuon.IsActive() ) isCombinedMuon();
      if( isSegmentTaggedMuon.IsActive() ) isSegmentTaggedMuon();
      if( loose.IsActive() ) loose();
      if( d0_exPV.IsActive() ) d0_exPV();
      if( z0_exPV.IsActive() ) z0_exPV();
      if( qoverp_exPV.IsActive() ) qoverp_exPV();
      if( id_theta_exPV.IsActive() ) id_theta_exPV();
      if( id_qoverp_exPV.IsActive() ) id_qoverp_exPV();
      if( me_theta_exPV.IsActive() ) me_theta_exPV();
      if( me_qoverp_exPV.IsActive() ) me_qoverp_exPV();
      if( cov_d0_exPV.IsActive() ) cov_d0_exPV();
      if( cov_qoverp_exPV.IsActive() ) cov_qoverp_exPV();
      if( cov_z0_qoverp_exPV.IsActive() ) cov_z0_qoverp_exPV();
      if( me_cov_qoverp_exPV.IsActive() ) me_cov_qoverp_exPV();
      if( ms_phi.IsActive() ) ms_phi();
      if( ms_theta.IsActive() ) ms_theta();
      if( ms_qoverp.IsActive() ) ms_qoverp();
      if( id_theta.IsActive() ) id_theta();
      if( nBLHits.IsActive() ) nBLHits();
      if( nPixHits.IsActive() ) nPixHits();
      if( nSCTHits.IsActive() ) nSCTHits();
      if( nTRTHits.IsActive() ) nTRTHits();
      if( nPixHoles.IsActive() ) nPixHoles();
      if( nSCTHoles.IsActive() ) nSCTHoles();
      if( nTRTOutliers.IsActive() ) nTRTOutliers();
      if( nTRTHighTOutliers.IsActive() ) nTRTHighTOutliers();
      if( nPixelDeadSensors.IsActive() ) nPixelDeadSensors();
      if( nSCTDeadSensors.IsActive() ) nSCTDeadSensors();
      if( expectBLayerHit.IsActive() ) expectBLayerHit();
      if( nMDTHits.IsActive() ) nMDTHits();
      if( nCSCEtaHits.IsActive() ) nCSCEtaHits();
      if( nMDTBIHits.IsActive() ) nMDTBIHits();
      if( nMDTBMHits.IsActive() ) nMDTBMHits();
      if( nMDTBOHits.IsActive() ) nMDTBOHits();
      if( nMDTEIHits.IsActive() ) nMDTEIHits();
      if( nMDTEMHits.IsActive() ) nMDTEMHits();
      if( nMDTEOHits.IsActive() ) nMDTEOHits();
      if( nMDTEEHits.IsActive() ) nMDTEEHits();
      if( trackIPEstimate_d0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_d0_unbiasedpvunbiased();
      if( trackIPEstimate_z0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_z0_unbiasedpvunbiased();
      if( trackIPEstimate_sigd0_unbiasedpvunbiased.IsActive() ) trackIPEstimate_sigd0_unbiasedpvunbiased();
if (!is_data) {
      if( type.IsActive() ) type();
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
      if( ptcone20_trkelstyle.IsActive() ) ptcone20_trkelstyle();
      if( ptcone30_trkelstyle.IsActive() ) ptcone30_trkelstyle();
      if( ptcone40_trkelstyle.IsActive() ) ptcone40_trkelstyle();
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
      etcone20()->clear();
      etcone30()->clear();
      etcone40()->clear();
      ptcone20()->clear();
      ptcone30()->clear();
      ptcone40()->clear();
      isCombinedMuon()->clear();
      isSegmentTaggedMuon()->clear();
      loose()->clear();
      d0_exPV()->clear();
      z0_exPV()->clear();
      qoverp_exPV()->clear();
      id_theta_exPV()->clear();
      id_qoverp_exPV()->clear();
      me_theta_exPV()->clear();
      me_qoverp_exPV()->clear();
      cov_d0_exPV()->clear();
      cov_qoverp_exPV()->clear();
      cov_z0_qoverp_exPV()->clear();
      me_cov_qoverp_exPV()->clear();
      ms_phi()->clear();
      ms_theta()->clear();
      ms_qoverp()->clear();
      id_theta()->clear();
      nBLHits()->clear();
      nPixHits()->clear();
      nSCTHits()->clear();
      nTRTHits()->clear();
      nPixHoles()->clear();
      nSCTHoles()->clear();
      nTRTOutliers()->clear();
      nTRTHighTOutliers()->clear();
      nPixelDeadSensors()->clear();
      nSCTDeadSensors()->clear();
      expectBLayerHit()->clear();
      nMDTHits()->clear();
      nCSCEtaHits()->clear();
      nMDTBIHits()->clear();
      nMDTBMHits()->clear();
      nMDTBOHits()->clear();
      nMDTEIHits()->clear();
      nMDTEMHits()->clear();
      nMDTEOHits()->clear();
      nMDTEEHits()->clear();
      trackIPEstimate_d0_unbiasedpvunbiased()->clear();
      trackIPEstimate_z0_unbiasedpvunbiased()->clear();
      trackIPEstimate_sigd0_unbiasedpvunbiased()->clear();
if (!is_data) {
      type()->clear();
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
      ptcone20_trkelstyle()->clear();
      ptcone30_trkelstyle()->clear();
      ptcone40_trkelstyle()->clear();
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
      if( el.isCombinedMuon.IsAvailable() ) {
         isCombinedMuon()->push_back( el.isCombinedMuon() );
      } else {
         isCombinedMuon()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.isSegmentTaggedMuon.IsAvailable() ) {
         isSegmentTaggedMuon()->push_back( el.isSegmentTaggedMuon() );
      } else {
         isSegmentTaggedMuon()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.loose.IsAvailable() ) {
         loose()->push_back( el.loose() );
      } else {
         loose()->push_back( std::numeric_limits< int >::min() );
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
      if( el.qoverp_exPV.IsAvailable() ) {
         qoverp_exPV()->push_back( el.qoverp_exPV() );
      } else {
         qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
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
      if( el.cov_d0_exPV.IsAvailable() ) {
         cov_d0_exPV()->push_back( el.cov_d0_exPV() );
      } else {
         cov_d0_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_qoverp_exPV.IsAvailable() ) {
         cov_qoverp_exPV()->push_back( el.cov_qoverp_exPV() );
      } else {
         cov_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.cov_z0_qoverp_exPV.IsAvailable() ) {
         cov_z0_qoverp_exPV()->push_back( el.cov_z0_qoverp_exPV() );
      } else {
         cov_z0_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.me_cov_qoverp_exPV.IsAvailable() ) {
         me_cov_qoverp_exPV()->push_back( el.me_cov_qoverp_exPV() );
      } else {
         me_cov_qoverp_exPV()->push_back( std::numeric_limits< float >::min() );
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
      if( el.id_theta.IsAvailable() ) {
         id_theta()->push_back( el.id_theta() );
      } else {
         id_theta()->push_back( std::numeric_limits< float >::min() );
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
      if( el.nCSCEtaHits.IsAvailable() ) {
         nCSCEtaHits()->push_back( el.nCSCEtaHits() );
      } else {
         nCSCEtaHits()->push_back( std::numeric_limits< int >::min() );
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
if (!is_data) {
      if( el.type.IsAvailable() ) {
         type()->push_back( el.type() );
      } else {
         type()->push_back( std::numeric_limits< int >::min() );
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
