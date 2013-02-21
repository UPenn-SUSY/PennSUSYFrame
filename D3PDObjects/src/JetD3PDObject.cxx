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
        E( parent.E, index, this ),
        pt( parent.pt, index, this ),
        m( parent.m, index, this ),
        eta( parent.eta, index, this ),
        phi( parent.phi, index, this ),
        LArQuality( parent.LArQuality, index, this ),
        sumPtTrk( parent.sumPtTrk, index, this ),
        HECQuality( parent.HECQuality, index, this ),
        NegativeE( parent.NegativeE, index, this ),
        AverageLArQF( parent.AverageLArQF, index, this ),
        BCH_CORR_JET( parent.BCH_CORR_JET, index, this ),
        SamplingMax( parent.SamplingMax, index, this ),
        fracSamplingMax( parent.fracSamplingMax, index, this ),
        hecf( parent.hecf, index, this ),
        emfrac( parent.emfrac, index, this ),
        emscale_eta( parent.emscale_eta, index, this ),
        ActiveArea( parent.ActiveArea, index, this ),
        ActiveAreaPx( parent.ActiveAreaPx, index, this ),
        ActiveAreaPy( parent.ActiveAreaPy, index, this ),
        ActiveAreaPz( parent.ActiveAreaPz, index, this ),
        ActiveAreaE( parent.ActiveAreaE, index, this ),
        jvtxf( parent.jvtxf, index, this ),
        constscale_E( parent.constscale_E, index, this ),
        constscale_pt( parent.constscale_pt, index, this ),
        constscale_m( parent.constscale_m, index, this ),
        constscale_eta( parent.constscale_eta, index, this ),
        constscale_phi( parent.constscale_phi, index, this ),
// MC only
        flavor_truth_label( parent.flavor_truth_label, index, this ),
// end MC only
        flavor_weight_MV1( parent.flavor_weight_MV1, index, this ) , 
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
        E( parent.E ),
        pt( parent.pt ),
        m( parent.m ),
        eta( parent.eta ),
        phi( parent.phi ),
        LArQuality( parent.LArQuality ),
        sumPtTrk( parent.sumPtTrk ),
        HECQuality( parent.HECQuality ),
        NegativeE( parent.NegativeE ),
        AverageLArQF( parent.AverageLArQF ),
        BCH_CORR_JET( parent.BCH_CORR_JET ),
        SamplingMax( parent.SamplingMax ),
        fracSamplingMax( parent.fracSamplingMax ),
        hecf( parent.hecf ),
        emfrac( parent.emfrac ),
        emscale_eta( parent.emscale_eta ),
        ActiveArea( parent.ActiveArea ),
        ActiveAreaPx( parent.ActiveAreaPx ),
        ActiveAreaPy( parent.ActiveAreaPy ),
        ActiveAreaPz( parent.ActiveAreaPz ),
        ActiveAreaE( parent.ActiveAreaE ),
        jvtxf( parent.jvtxf ),
        constscale_E( parent.constscale_E ),
        constscale_pt( parent.constscale_pt ),
        constscale_m( parent.constscale_m ),
        constscale_eta( parent.constscale_eta ),
        constscale_phi( parent.constscale_phi ),
// MC only
        flavor_truth_label( parent.flavor_truth_label ),
// end MC only
        flavor_weight_MV1( parent.flavor_weight_MV1 ) , 
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
        n( this, ::TString( prefix ) + "n", &master ),
        E( this, ::TString( prefix ) + "E", &master ),
        pt( this, ::TString( prefix ) + "pt", &master ),
        m( this, ::TString( prefix ) + "m", &master ),
        eta( this, ::TString( prefix ) + "eta", &master ),
        phi( this, ::TString( prefix ) + "phi", &master ),
        LArQuality( this, ::TString( prefix ) + "LArQuality", &master ),
        sumPtTrk( this, ::TString( prefix ) + "sumPtTrk", &master ),
        HECQuality( this, ::TString( prefix ) + "HECQuality", &master ),
        NegativeE( this, ::TString( prefix ) + "NegativeE", &master ),
        AverageLArQF( this, ::TString( prefix ) + "AverageLArQF", &master ),
        BCH_CORR_JET( this, ::TString( prefix ) + "BCH_CORR_JET", &master ),
        SamplingMax( this, ::TString( prefix ) + "SamplingMax", &master ),
        fracSamplingMax( this, ::TString( prefix ) + "fracSamplingMax", &master ),
        hecf( this, ::TString( prefix ) + "hecf", &master ),
        emfrac( this, ::TString( prefix ) + "emfrac", &master ),
        emscale_eta( this, ::TString( prefix ) + "emscale_eta", &master ),
        ActiveArea( this, ::TString( prefix ) + "ActiveArea", &master ),
        ActiveAreaPx( this, ::TString( prefix ) + "ActiveAreaPx", &master ),
        ActiveAreaPy( this, ::TString( prefix ) + "ActiveAreaPy", &master ),
        ActiveAreaPz( this, ::TString( prefix ) + "ActiveAreaPz", &master ),
        ActiveAreaE( this, ::TString( prefix ) + "ActiveAreaE", &master ),
        jvtxf( this, ::TString( prefix ) + "jvtxf", &master ),
        constscale_E( this, ::TString( prefix ) + "constscale_E", &master ),
        constscale_pt( this, ::TString( prefix ) + "constscale_pt", &master ),
        constscale_m( this, ::TString( prefix ) + "constscale_m", &master ),
        constscale_eta( this, ::TString( prefix ) + "constscale_eta", &master ),
        constscale_phi( this, ::TString( prefix ) + "constscale_phi", &master ),
// MC only
        flavor_truth_label( this, ::TString( prefix ) + "flavor_truth_label", &master ),
// end MC only
        flavor_weight_MV1( this, ::TString( prefix ) + "flavor_weight_MV1", &master ),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "MET_Egamma10NoTau_wpx" ] = &MET_Egamma10NoTau_wpx;
      fHandles[ "MET_Egamma10NoTau_wpy" ] = &MET_Egamma10NoTau_wpy;
      fHandles[ "MET_Egamma10NoTau_wet" ] = &MET_Egamma10NoTau_wet;
      fHandles[ "MET_Egamma10NoTau_statusWord" ] = &MET_Egamma10NoTau_statusWord;
      fHandles[ "n" ] = &n;
      fHandles[ "E" ] = &E;
      fHandles[ "pt" ] = &pt;
      fHandles[ "m" ] = &m;
      fHandles[ "eta" ] = &eta;
      fHandles[ "phi" ] = &phi;
      fHandles[ "LArQuality" ] = &LArQuality;
      fHandles[ "sumPtTrk" ] = &sumPtTrk;
      fHandles[ "HECQuality" ] = &HECQuality;
      fHandles[ "NegativeE" ] = &NegativeE;
      fHandles[ "AverageLArQF" ] = &AverageLArQF;
      fHandles[ "BCH_CORR_JET" ] = &BCH_CORR_JET;
      fHandles[ "SamplingMax" ] = &SamplingMax;
      fHandles[ "fracSamplingMax" ] = &fracSamplingMax;
      fHandles[ "hecf" ] = &hecf;
      fHandles[ "emfrac" ] = &emfrac;
      fHandles[ "emscale_eta" ] = &emscale_eta;
      fHandles[ "ActiveArea" ] = &ActiveArea;
      fHandles[ "ActiveAreaPx" ] = &ActiveAreaPx;
      fHandles[ "ActiveAreaPy" ] = &ActiveAreaPy;
      fHandles[ "ActiveAreaPz" ] = &ActiveAreaPz;
      fHandles[ "ActiveAreaE" ] = &ActiveAreaE;
      fHandles[ "jvtxf" ] = &jvtxf;
      fHandles[ "constscale_E" ] = &constscale_E;
      fHandles[ "constscale_pt" ] = &constscale_pt;
      fHandles[ "constscale_m" ] = &constscale_m;
      fHandles[ "constscale_eta" ] = &constscale_eta;
      fHandles[ "constscale_phi" ] = &constscale_phi;
if (!is_data) {
      fHandles[ "flavor_truth_label" ] = &flavor_truth_label;
} // end !is_data
      fHandles[ "flavor_weight_MV1" ] = &flavor_weight_MV1;
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
        n( this, ::TString( prefix ) + "n", 0 ),
        E( this, ::TString( prefix ) + "E", 0 ),
        pt( this, ::TString( prefix ) + "pt", 0 ),
        m( this, ::TString( prefix ) + "m", 0 ),
        eta( this, ::TString( prefix ) + "eta", 0 ),
        phi( this, ::TString( prefix ) + "phi", 0 ),
        LArQuality( this, ::TString( prefix ) + "LArQuality", 0 ),
        sumPtTrk( this, ::TString( prefix ) + "sumPtTrk", 0 ),
        HECQuality( this, ::TString( prefix ) + "HECQuality", 0 ),
        NegativeE( this, ::TString( prefix ) + "NegativeE", 0 ),
        AverageLArQF( this, ::TString( prefix ) + "AverageLArQF", 0 ),
        BCH_CORR_JET( this, ::TString( prefix ) + "BCH_CORR_JET", 0 ),
        SamplingMax( this, ::TString( prefix ) + "SamplingMax", 0 ),
        fracSamplingMax( this, ::TString( prefix ) + "fracSamplingMax", 0 ),
        hecf( this, ::TString( prefix ) + "hecf", 0 ),
        emfrac( this, ::TString( prefix ) + "emfrac", 0 ),
        emscale_eta( this, ::TString( prefix ) + "emscale_eta", 0 ),
        ActiveArea( this, ::TString( prefix ) + "ActiveArea", 0 ),
        ActiveAreaPx( this, ::TString( prefix ) + "ActiveAreaPx", 0 ),
        ActiveAreaPy( this, ::TString( prefix ) + "ActiveAreaPy", 0 ),
        ActiveAreaPz( this, ::TString( prefix ) + "ActiveAreaPz", 0 ),
        ActiveAreaE( this, ::TString( prefix ) + "ActiveAreaE", 0 ),
        jvtxf( this, ::TString( prefix ) + "jvtxf", 0 ),
        constscale_E( this, ::TString( prefix ) + "constscale_E", 0 ),
        constscale_pt( this, ::TString( prefix ) + "constscale_pt", 0 ),
        constscale_m( this, ::TString( prefix ) + "constscale_m", 0 ),
        constscale_eta( this, ::TString( prefix ) + "constscale_eta", 0 ),
        constscale_phi( this, ::TString( prefix ) + "constscale_phi", 0 ),
// MC only
        flavor_truth_label( this, ::TString( prefix ) + "flavor_truth_label", 0 ),
// end MC only
        flavor_weight_MV1( this, ::TString( prefix ) + "flavor_weight_MV1", 0 ),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "MET_Egamma10NoTau_wpx" ] = &MET_Egamma10NoTau_wpx;
      fHandles[ "MET_Egamma10NoTau_wpy" ] = &MET_Egamma10NoTau_wpy;
      fHandles[ "MET_Egamma10NoTau_wet" ] = &MET_Egamma10NoTau_wet;
      fHandles[ "MET_Egamma10NoTau_statusWord" ] = &MET_Egamma10NoTau_statusWord;
      fHandles[ "n" ] = &n;
      fHandles[ "E" ] = &E;
      fHandles[ "pt" ] = &pt;
      fHandles[ "m" ] = &m;
      fHandles[ "eta" ] = &eta;
      fHandles[ "phi" ] = &phi;
      fHandles[ "LArQuality" ] = &LArQuality;
      fHandles[ "sumPtTrk" ] = &sumPtTrk;
      fHandles[ "HECQuality" ] = &HECQuality;
      fHandles[ "NegativeE" ] = &NegativeE;
      fHandles[ "AverageLArQF" ] = &AverageLArQF;
      fHandles[ "BCH_CORR_JET" ] = &BCH_CORR_JET;
      fHandles[ "SamplingMax" ] = &SamplingMax;
      fHandles[ "fracSamplingMax" ] = &fracSamplingMax;
      fHandles[ "hecf" ] = &hecf;
      fHandles[ "emfrac" ] = &emfrac;
      fHandles[ "emscale_eta" ] = &emscale_eta;
      fHandles[ "ActiveArea" ] = &ActiveArea;
      fHandles[ "ActiveAreaPx" ] = &ActiveAreaPx;
      fHandles[ "ActiveAreaPy" ] = &ActiveAreaPy;
      fHandles[ "ActiveAreaPz" ] = &ActiveAreaPz;
      fHandles[ "ActiveAreaE" ] = &ActiveAreaE;
      fHandles[ "jvtxf" ] = &jvtxf;
      fHandles[ "constscale_E" ] = &constscale_E;
      fHandles[ "constscale_pt" ] = &constscale_pt;
      fHandles[ "constscale_m" ] = &constscale_m;
      fHandles[ "constscale_eta" ] = &constscale_eta;
      fHandles[ "constscale_phi" ] = &constscale_phi;
if (!is_data) {
      fHandles[ "flavor_truth_label" ] = &flavor_truth_label;
} // end !is_data
      fHandles[ "flavor_weight_MV1" ] = &flavor_weight_MV1;
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
      n.SetName( ::TString( prefix ) + "n" );
      E.SetName( ::TString( prefix ) + "E" );
      pt.SetName( ::TString( prefix ) + "pt" );
      m.SetName( ::TString( prefix ) + "m" );
      eta.SetName( ::TString( prefix ) + "eta" );
      phi.SetName( ::TString( prefix ) + "phi" );
      LArQuality.SetName( ::TString( prefix ) + "LArQuality" );
      sumPtTrk.SetName( ::TString( prefix ) + "sumPtTrk" );
      HECQuality.SetName( ::TString( prefix ) + "HECQuality" );
      NegativeE.SetName( ::TString( prefix ) + "NegativeE" );
      AverageLArQF.SetName( ::TString( prefix ) + "AverageLArQF" );
      BCH_CORR_JET.SetName( ::TString( prefix ) + "BCH_CORR_JET" );
      SamplingMax.SetName( ::TString( prefix ) + "SamplingMax" );
      fracSamplingMax.SetName( ::TString( prefix ) + "fracSamplingMax" );
      hecf.SetName( ::TString( prefix ) + "hecf" );
      emfrac.SetName( ::TString( prefix ) + "emfrac" );
      emscale_eta.SetName( ::TString( prefix ) + "emscale_eta" );
      ActiveArea.SetName( ::TString( prefix ) + "ActiveArea" );
      ActiveAreaPx.SetName( ::TString( prefix ) + "ActiveAreaPx" );
      ActiveAreaPy.SetName( ::TString( prefix ) + "ActiveAreaPy" );
      ActiveAreaPz.SetName( ::TString( prefix ) + "ActiveAreaPz" );
      ActiveAreaE.SetName( ::TString( prefix ) + "ActiveAreaE" );
      jvtxf.SetName( ::TString( prefix ) + "jvtxf" );
      constscale_E.SetName( ::TString( prefix ) + "constscale_E" );
      constscale_pt.SetName( ::TString( prefix ) + "constscale_pt" );
      constscale_m.SetName( ::TString( prefix ) + "constscale_m" );
      constscale_eta.SetName( ::TString( prefix ) + "constscale_eta" );
      constscale_phi.SetName( ::TString( prefix ) + "constscale_phi" );
if (!is_data) {
      flavor_truth_label.SetName( ::TString( prefix ) + "flavor_truth_label" );
} // end !is_data
      flavor_weight_MV1.SetName( ::TString( prefix ) + "flavor_weight_MV1" );
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
      n.ReadFrom( tree );
      E.ReadFrom( tree );
      pt.ReadFrom( tree );
      m.ReadFrom( tree );
      eta.ReadFrom( tree );
      phi.ReadFrom( tree );
      LArQuality.ReadFrom( tree );
      sumPtTrk.ReadFrom( tree );
      HECQuality.ReadFrom( tree );
      NegativeE.ReadFrom( tree );
      AverageLArQF.ReadFrom( tree );
      BCH_CORR_JET.ReadFrom( tree );
      SamplingMax.ReadFrom( tree );
      fracSamplingMax.ReadFrom( tree );
      hecf.ReadFrom( tree );
      emfrac.ReadFrom( tree );
      emscale_eta.ReadFrom( tree );
      ActiveArea.ReadFrom( tree );
      ActiveAreaPx.ReadFrom( tree );
      ActiveAreaPy.ReadFrom( tree );
      ActiveAreaPz.ReadFrom( tree );
      ActiveAreaE.ReadFrom( tree );
      jvtxf.ReadFrom( tree );
      constscale_E.ReadFrom( tree );
      constscale_pt.ReadFrom( tree );
      constscale_m.ReadFrom( tree );
      constscale_eta.ReadFrom( tree );
      constscale_phi.ReadFrom( tree );
if (!is_data) {
      flavor_truth_label.ReadFrom( tree );
} // end !is_data
      flavor_weight_MV1.ReadFrom( tree );

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
      n.WriteTo( tree );
      E.WriteTo( tree );
      pt.WriteTo( tree );
      m.WriteTo( tree );
      eta.WriteTo( tree );
      phi.WriteTo( tree );
      LArQuality.WriteTo( tree );
      sumPtTrk.WriteTo( tree );
      HECQuality.WriteTo( tree );
      NegativeE.WriteTo( tree );
      AverageLArQF.WriteTo( tree );
      BCH_CORR_JET.WriteTo( tree );
      SamplingMax.WriteTo( tree );
      fracSamplingMax.WriteTo( tree );
      hecf.WriteTo( tree );
      emfrac.WriteTo( tree );
      emscale_eta.WriteTo( tree );
      ActiveArea.WriteTo( tree );
      ActiveAreaPx.WriteTo( tree );
      ActiveAreaPy.WriteTo( tree );
      ActiveAreaPz.WriteTo( tree );
      ActiveAreaE.WriteTo( tree );
      jvtxf.WriteTo( tree );
      constscale_E.WriteTo( tree );
      constscale_pt.WriteTo( tree );
      constscale_m.WriteTo( tree );
      constscale_eta.WriteTo( tree );
      constscale_phi.WriteTo( tree );
if (!is_data) {
      flavor_truth_label.WriteTo( tree );
} // end !is_data
      flavor_weight_MV1.WriteTo( tree );

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
      if( n.IsActive() ) n();
      if( E.IsActive() ) E();
      if( pt.IsActive() ) pt();
      if( m.IsActive() ) m();
      if( eta.IsActive() ) eta();
      if( phi.IsActive() ) phi();
      if( LArQuality.IsActive() ) LArQuality();
      if( sumPtTrk.IsActive() ) sumPtTrk();
      if( HECQuality.IsActive() ) HECQuality();
      if( NegativeE.IsActive() ) NegativeE();
      if( AverageLArQF.IsActive() ) AverageLArQF();
      if( BCH_CORR_JET.IsActive() ) BCH_CORR_JET();
      if( SamplingMax.IsActive() ) SamplingMax();
      if( fracSamplingMax.IsActive() ) fracSamplingMax();
      if( hecf.IsActive() ) hecf();
      if( emfrac.IsActive() ) emfrac();
      if( emscale_eta.IsActive() ) emscale_eta();
      if( ActiveArea.IsActive() ) ActiveArea();
      if( ActiveAreaPx.IsActive() ) ActiveAreaPx();
      if( ActiveAreaPy.IsActive() ) ActiveAreaPy();
      if( ActiveAreaPz.IsActive() ) ActiveAreaPz();
      if( ActiveAreaE.IsActive() ) ActiveAreaE();
      if( jvtxf.IsActive() ) jvtxf();
      if( constscale_E.IsActive() ) constscale_E();
      if( constscale_pt.IsActive() ) constscale_pt();
      if( constscale_m.IsActive() ) constscale_m();
      if( constscale_eta.IsActive() ) constscale_eta();
      if( constscale_phi.IsActive() ) constscale_phi();
if (!is_data) {
      if( flavor_truth_label.IsActive() ) flavor_truth_label();
} // end !is_data
      if( flavor_weight_MV1.IsActive() ) flavor_weight_MV1();

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
      n() = 0;
      E()->clear();
      pt()->clear();
      m()->clear();
      eta()->clear();
      phi()->clear();
      LArQuality()->clear();
      sumPtTrk()->clear();
      HECQuality()->clear();
      NegativeE()->clear();
      AverageLArQF()->clear();
      BCH_CORR_JET()->clear();
      SamplingMax()->clear();
      fracSamplingMax()->clear();
      hecf()->clear();
      emfrac()->clear();
      emscale_eta()->clear();
      ActiveArea()->clear();
      ActiveAreaPx()->clear();
      ActiveAreaPy()->clear();
      ActiveAreaPz()->clear();
      ActiveAreaE()->clear();
      jvtxf()->clear();
      constscale_E()->clear();
      constscale_pt()->clear();
      constscale_m()->clear();
      constscale_eta()->clear();
      constscale_phi()->clear();
if (!is_data) {
      flavor_truth_label()->clear();
} // end !is_data
      flavor_weight_MV1()->clear();

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
      if( el.LArQuality.IsAvailable() ) {
         LArQuality()->push_back( el.LArQuality() );
      } else {
         LArQuality()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.sumPtTrk.IsAvailable() ) {
         sumPtTrk()->push_back( el.sumPtTrk() );
      } else {
         sumPtTrk()->push_back( std::numeric_limits< float >::min() );
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
      if( el.BCH_CORR_JET.IsAvailable() ) {
         BCH_CORR_JET()->push_back( el.BCH_CORR_JET() );
      } else {
         BCH_CORR_JET()->push_back( std::numeric_limits< float >::min() );
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
      if( el.emfrac.IsAvailable() ) {
         emfrac()->push_back( el.emfrac() );
      } else {
         emfrac()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.emscale_eta.IsAvailable() ) {
         emscale_eta()->push_back( el.emscale_eta() );
      } else {
         emscale_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ActiveArea.IsAvailable() ) {
         ActiveArea()->push_back( el.ActiveArea() );
      } else {
         ActiveArea()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ActiveAreaPx.IsAvailable() ) {
         ActiveAreaPx()->push_back( el.ActiveAreaPx() );
      } else {
         ActiveAreaPx()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ActiveAreaPy.IsAvailable() ) {
         ActiveAreaPy()->push_back( el.ActiveAreaPy() );
      } else {
         ActiveAreaPy()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ActiveAreaPz.IsAvailable() ) {
         ActiveAreaPz()->push_back( el.ActiveAreaPz() );
      } else {
         ActiveAreaPz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.ActiveAreaE.IsAvailable() ) {
         ActiveAreaE()->push_back( el.ActiveAreaE() );
      } else {
         ActiveAreaE()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.jvtxf.IsAvailable() ) {
         jvtxf()->push_back( el.jvtxf() );
      } else {
         jvtxf()->push_back( std::numeric_limits< float >::min() );
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
if (!is_data) {
      if( el.flavor_truth_label.IsAvailable() ) {
         flavor_truth_label()->push_back( el.flavor_truth_label() );
      } else {
         flavor_truth_label()->push_back( std::numeric_limits< int >::min() );
      }
} // end !is_data
      if( el.flavor_weight_MV1.IsAvailable() ) {
         flavor_weight_MV1()->push_back( el.flavor_weight_MV1() );
      } else {
         flavor_weight_MV1()->push_back( std::numeric_limits< float >::min() );
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
