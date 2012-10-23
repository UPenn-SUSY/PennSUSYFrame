// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <TPRegexp.h>

#include "../include/MCEvtD3PDObject.h"

ClassImp( D3PDReader::MCEvtD3PDObject )

namespace D3PDReader {

   /**
    * This constructor should be used when the object will be used to read
    * variables from an existing ntuple. The object will also be able to
    * output variables, but it will also need to read them from somewhere.
    *
    * @param master Reference to the variable holding the current event number
    * @param prefix Prefix of the variables in the D3PD
    */
   MCEvtD3PDObject::MCEvtD3PDObject( const ::Long64_t& master, const char* prefix )
      : TObject(),
        n( this, ::TString( prefix ) + "n", &master ),
        signal_process_id( this, ::TString( prefix ) + "signal_process_id", &master ),
        event_number( this, ::TString( prefix ) + "event_number", &master ),
        event_scale( this, ::TString( prefix ) + "event_scale", &master ),
        alphaQCD( this, ::TString( prefix ) + "alphaQCD", &master ),
        alphaQED( this, ::TString( prefix ) + "alphaQED", &master ),
        pdf_id1( this, ::TString( prefix ) + "pdf_id1", &master ),
        pdf_id2( this, ::TString( prefix ) + "pdf_id2", &master ),
        pdf_x1( this, ::TString( prefix ) + "pdf_x1", &master ),
        pdf_x2( this, ::TString( prefix ) + "pdf_x2", &master ),
        pdf_scale( this, ::TString( prefix ) + "pdf_scale", &master ),
        pdf1( this, ::TString( prefix ) + "pdf1", &master ),
        pdf2( this, ::TString( prefix ) + "pdf2", &master ),
        weight( this, ::TString( prefix ) + "weight", &master ),
        nparticle( this, ::TString( prefix ) + "nparticle", &master ),
        pileUpType( this, ::TString( prefix ) + "pileUpType", &master ),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) {

      fHandles[ "n" ] = &n;
      fHandles[ "signal_process_id" ] = &signal_process_id;
      fHandles[ "event_number" ] = &event_number;
      fHandles[ "event_scale" ] = &event_scale;
      fHandles[ "alphaQCD" ] = &alphaQCD;
      fHandles[ "alphaQED" ] = &alphaQED;
      fHandles[ "pdf_id1" ] = &pdf_id1;
      fHandles[ "pdf_id2" ] = &pdf_id2;
      fHandles[ "pdf_x1" ] = &pdf_x1;
      fHandles[ "pdf_x2" ] = &pdf_x2;
      fHandles[ "pdf_scale" ] = &pdf_scale;
      fHandles[ "pdf1" ] = &pdf1;
      fHandles[ "pdf2" ] = &pdf2;
      fHandles[ "weight" ] = &weight;
      fHandles[ "nparticle" ] = &nparticle;
      fHandles[ "pileUpType" ] = &pileUpType;
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   MCEvtD3PDObject::MCEvtD3PDObject( const char* prefix )
      : TObject(),
        n( this, ::TString( prefix ) + "n", 0 ),
        signal_process_id( this, ::TString( prefix ) + "signal_process_id", 0 ),
        event_number( this, ::TString( prefix ) + "event_number", 0 ),
        event_scale( this, ::TString( prefix ) + "event_scale", 0 ),
        alphaQCD( this, ::TString( prefix ) + "alphaQCD", 0 ),
        alphaQED( this, ::TString( prefix ) + "alphaQED", 0 ),
        pdf_id1( this, ::TString( prefix ) + "pdf_id1", 0 ),
        pdf_id2( this, ::TString( prefix ) + "pdf_id2", 0 ),
        pdf_x1( this, ::TString( prefix ) + "pdf_x1", 0 ),
        pdf_x2( this, ::TString( prefix ) + "pdf_x2", 0 ),
        pdf_scale( this, ::TString( prefix ) + "pdf_scale", 0 ),
        pdf1( this, ::TString( prefix ) + "pdf1", 0 ),
        pdf2( this, ::TString( prefix ) + "pdf2", 0 ),
        weight( this, ::TString( prefix ) + "weight", 0 ),
        nparticle( this, ::TString( prefix ) + "nparticle", 0 ),
        pileUpType( this, ::TString( prefix ) + "pileUpType", 0 ),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) {

      fHandles[ "n" ] = &n;
      fHandles[ "signal_process_id" ] = &signal_process_id;
      fHandles[ "event_number" ] = &event_number;
      fHandles[ "event_scale" ] = &event_scale;
      fHandles[ "alphaQCD" ] = &alphaQCD;
      fHandles[ "alphaQED" ] = &alphaQED;
      fHandles[ "pdf_id1" ] = &pdf_id1;
      fHandles[ "pdf_id2" ] = &pdf_id2;
      fHandles[ "pdf_x1" ] = &pdf_x1;
      fHandles[ "pdf_x2" ] = &pdf_x2;
      fHandles[ "pdf_scale" ] = &pdf_scale;
      fHandles[ "pdf1" ] = &pdf1;
      fHandles[ "pdf2" ] = &pdf2;
      fHandles[ "weight" ] = &weight;
      fHandles[ "nparticle" ] = &nparticle;
      fHandles[ "pileUpType" ] = &pileUpType;
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* MCEvtD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void MCEvtD3PDObject::SetPrefix( const char* prefix ) {

      n.SetName( ::TString( prefix ) + "n" );
      signal_process_id.SetName( ::TString( prefix ) + "signal_process_id" );
      event_number.SetName( ::TString( prefix ) + "event_number" );
      event_scale.SetName( ::TString( prefix ) + "event_scale" );
      alphaQCD.SetName( ::TString( prefix ) + "alphaQCD" );
      alphaQED.SetName( ::TString( prefix ) + "alphaQED" );
      pdf_id1.SetName( ::TString( prefix ) + "pdf_id1" );
      pdf_id2.SetName( ::TString( prefix ) + "pdf_id2" );
      pdf_x1.SetName( ::TString( prefix ) + "pdf_x1" );
      pdf_x2.SetName( ::TString( prefix ) + "pdf_x2" );
      pdf_scale.SetName( ::TString( prefix ) + "pdf_scale" );
      pdf1.SetName( ::TString( prefix ) + "pdf1" );
      pdf2.SetName( ::TString( prefix ) + "pdf2" );
      weight.SetName( ::TString( prefix ) + "weight" );
      nparticle.SetName( ::TString( prefix ) + "nparticle" );
      pileUpType.SetName( ::TString( prefix ) + "pileUpType" );
      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void MCEvtD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      n.ReadFrom( tree );
      signal_process_id.ReadFrom( tree );
      event_number.ReadFrom( tree );
      event_scale.ReadFrom( tree );
      alphaQCD.ReadFrom( tree );
      alphaQED.ReadFrom( tree );
      pdf_id1.ReadFrom( tree );
      pdf_id2.ReadFrom( tree );
      pdf_x1.ReadFrom( tree );
      pdf_x2.ReadFrom( tree );
      pdf_scale.ReadFrom( tree );
      pdf1.ReadFrom( tree );
      pdf2.ReadFrom( tree );
      weight.ReadFrom( tree );
      nparticle.ReadFrom( tree );
      pileUpType.ReadFrom( tree );

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void MCEvtD3PDObject::WriteTo( TTree* tree ) {

      n.WriteTo( tree );
      signal_process_id.WriteTo( tree );
      event_number.WriteTo( tree );
      event_scale.WriteTo( tree );
      alphaQCD.WriteTo( tree );
      alphaQED.WriteTo( tree );
      pdf_id1.WriteTo( tree );
      pdf_id2.WriteTo( tree );
      pdf_x1.WriteTo( tree );
      pdf_x2.WriteTo( tree );
      pdf_scale.WriteTo( tree );
      pdf1.WriteTo( tree );
      pdf2.WriteTo( tree );
      weight.WriteTo( tree );
      nparticle.WriteTo( tree );
      pileUpType.WriteTo( tree );

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
   void MCEvtD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void MCEvtD3PDObject::ReadAllActive() {

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
      if( signal_process_id.IsActive() ) signal_process_id();
      if( event_number.IsActive() ) event_number();
      if( event_scale.IsActive() ) event_scale();
      if( alphaQCD.IsActive() ) alphaQCD();
      if( alphaQED.IsActive() ) alphaQED();
      if( pdf_id1.IsActive() ) pdf_id1();
      if( pdf_id2.IsActive() ) pdf_id2();
      if( pdf_x1.IsActive() ) pdf_x1();
      if( pdf_x2.IsActive() ) pdf_x2();
      if( pdf_scale.IsActive() ) pdf_scale();
      if( pdf1.IsActive() ) pdf1();
      if( pdf2.IsActive() ) pdf2();
      if( weight.IsActive() ) weight();
      if( nparticle.IsActive() ) nparticle();
      if( pileUpType.IsActive() ) pileUpType();

      return;
   }

} // namespace D3PDReader
