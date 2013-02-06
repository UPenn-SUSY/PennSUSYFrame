// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <TPRegexp.h>

#include "../include/EventInfoD3PDObject.h"

ClassImp( D3PDReader::EventInfoD3PDObject )

namespace D3PDReader {

   /**
    * This constructor should be used when the object will be used to read
    * variables from an existing ntuple. The object will also be able to
    * output variables, but it will also need to read them from somewhere.
    *
    * @param master Reference to the variable holding the current event number
    * @param prefix Prefix of the variables in the D3PD
    */
   EventInfoD3PDObject::EventInfoD3PDObject( const ::Long64_t& master, const char* prefix , bool is_data )
      : TObject(),
        RunNumber( this, ::TString( prefix ) + "RunNumber", &master ),
        EventNumber( this, ::TString( prefix ) + "EventNumber", &master ),
        timestamp( this, ::TString( prefix ) + "timestamp", &master ),
        timestamp_ns( this, ::TString( prefix ) + "timestamp_ns", &master ),
        lbn( this, ::TString( prefix ) + "lbn", &master ),
        bcid( this, ::TString( prefix ) + "bcid", &master ),
        detmask0( this, ::TString( prefix ) + "detmask0", &master ),
        detmask1( this, ::TString( prefix ) + "detmask1", &master ),
        actualIntPerXing( this, ::TString( prefix ) + "actualIntPerXing", &master ),
        averageIntPerXing( this, ::TString( prefix ) + "averageIntPerXing", &master ),
        pixelFlags( this, ::TString( prefix ) + "pixelFlags", &master ),
        sctFlags( this, ::TString( prefix ) + "sctFlags", &master ),
        trtFlags( this, ::TString( prefix ) + "trtFlags", &master ),
        larFlags( this, ::TString( prefix ) + "larFlags", &master ),
        tileFlags( this, ::TString( prefix ) + "tileFlags", &master ),
        muonFlags( this, ::TString( prefix ) + "muonFlags", &master ),
        fwdFlags( this, ::TString( prefix ) + "fwdFlags", &master ),
        coreFlags( this, ::TString( prefix ) + "coreFlags", &master ),
        pixelError( this, ::TString( prefix ) + "pixelError", &master ),
        sctError( this, ::TString( prefix ) + "sctError", &master ),
        trtError( this, ::TString( prefix ) + "trtError", &master ),
        larError( this, ::TString( prefix ) + "larError", &master ),
        tileError( this, ::TString( prefix ) + "tileError", &master ),
        muonError( this, ::TString( prefix ) + "muonError", &master ),
        fwdError( this, ::TString( prefix ) + "fwdError", &master ),
        coreError( this, ::TString( prefix ) + "coreError", &master ),
        Eventshape_rhoKt3EM( this, ::TString( prefix ) + "Eventshape_rhoKt3EM", &master ),
        Eventshape_rhoKt4EM( this, ::TString( prefix ) + "Eventshape_rhoKt4EM", &master ),
        Eventshape_rhoKt3LC( this, ::TString( prefix ) + "Eventshape_rhoKt3LC", &master ),
        Eventshape_rhoKt4LC( this, ::TString( prefix ) + "Eventshape_rhoKt4LC", &master ),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "RunNumber" ] = &RunNumber;
      fHandles[ "EventNumber" ] = &EventNumber;
      fHandles[ "timestamp" ] = &timestamp;
      fHandles[ "timestamp_ns" ] = &timestamp_ns;
      fHandles[ "lbn" ] = &lbn;
      fHandles[ "bcid" ] = &bcid;
      fHandles[ "detmask0" ] = &detmask0;
      fHandles[ "detmask1" ] = &detmask1;
      fHandles[ "actualIntPerXing" ] = &actualIntPerXing;
      fHandles[ "averageIntPerXing" ] = &averageIntPerXing;
      fHandles[ "pixelFlags" ] = &pixelFlags;
      fHandles[ "sctFlags" ] = &sctFlags;
      fHandles[ "trtFlags" ] = &trtFlags;
      fHandles[ "larFlags" ] = &larFlags;
      fHandles[ "tileFlags" ] = &tileFlags;
      fHandles[ "muonFlags" ] = &muonFlags;
      fHandles[ "fwdFlags" ] = &fwdFlags;
      fHandles[ "coreFlags" ] = &coreFlags;
      fHandles[ "pixelError" ] = &pixelError;
      fHandles[ "sctError" ] = &sctError;
      fHandles[ "trtError" ] = &trtError;
      fHandles[ "larError" ] = &larError;
      fHandles[ "tileError" ] = &tileError;
      fHandles[ "muonError" ] = &muonError;
      fHandles[ "fwdError" ] = &fwdError;
      fHandles[ "coreError" ] = &coreError;
      fHandles[ "Eventshape_rhoKt3EM" ] = &Eventshape_rhoKt3EM;
      fHandles[ "Eventshape_rhoKt4EM" ] = &Eventshape_rhoKt4EM;
      fHandles[ "Eventshape_rhoKt3LC" ] = &Eventshape_rhoKt3LC;
      fHandles[ "Eventshape_rhoKt4LC" ] = &Eventshape_rhoKt4LC;
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   EventInfoD3PDObject::EventInfoD3PDObject( const char* prefix , bool is_data )
      : TObject(),
        RunNumber( this, ::TString( prefix ) + "RunNumber", 0 ),
        EventNumber( this, ::TString( prefix ) + "EventNumber", 0 ),
        timestamp( this, ::TString( prefix ) + "timestamp", 0 ),
        timestamp_ns( this, ::TString( prefix ) + "timestamp_ns", 0 ),
        lbn( this, ::TString( prefix ) + "lbn", 0 ),
        bcid( this, ::TString( prefix ) + "bcid", 0 ),
        detmask0( this, ::TString( prefix ) + "detmask0", 0 ),
        detmask1( this, ::TString( prefix ) + "detmask1", 0 ),
        actualIntPerXing( this, ::TString( prefix ) + "actualIntPerXing", 0 ),
        averageIntPerXing( this, ::TString( prefix ) + "averageIntPerXing", 0 ),
        pixelFlags( this, ::TString( prefix ) + "pixelFlags", 0 ),
        sctFlags( this, ::TString( prefix ) + "sctFlags", 0 ),
        trtFlags( this, ::TString( prefix ) + "trtFlags", 0 ),
        larFlags( this, ::TString( prefix ) + "larFlags", 0 ),
        tileFlags( this, ::TString( prefix ) + "tileFlags", 0 ),
        muonFlags( this, ::TString( prefix ) + "muonFlags", 0 ),
        fwdFlags( this, ::TString( prefix ) + "fwdFlags", 0 ),
        coreFlags( this, ::TString( prefix ) + "coreFlags", 0 ),
        pixelError( this, ::TString( prefix ) + "pixelError", 0 ),
        sctError( this, ::TString( prefix ) + "sctError", 0 ),
        trtError( this, ::TString( prefix ) + "trtError", 0 ),
        larError( this, ::TString( prefix ) + "larError", 0 ),
        tileError( this, ::TString( prefix ) + "tileError", 0 ),
        muonError( this, ::TString( prefix ) + "muonError", 0 ),
        fwdError( this, ::TString( prefix ) + "fwdError", 0 ),
        coreError( this, ::TString( prefix ) + "coreError", 0 ),
        Eventshape_rhoKt3EM( this, ::TString( prefix ) + "Eventshape_rhoKt3EM", 0 ),
        Eventshape_rhoKt4EM( this, ::TString( prefix ) + "Eventshape_rhoKt4EM", 0 ),
        Eventshape_rhoKt3LC( this, ::TString( prefix ) + "Eventshape_rhoKt3LC", 0 ),
        Eventshape_rhoKt4LC( this, ::TString( prefix ) + "Eventshape_rhoKt4LC", 0 ),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "RunNumber" ] = &RunNumber;
      fHandles[ "EventNumber" ] = &EventNumber;
      fHandles[ "timestamp" ] = &timestamp;
      fHandles[ "timestamp_ns" ] = &timestamp_ns;
      fHandles[ "lbn" ] = &lbn;
      fHandles[ "bcid" ] = &bcid;
      fHandles[ "detmask0" ] = &detmask0;
      fHandles[ "detmask1" ] = &detmask1;
      fHandles[ "actualIntPerXing" ] = &actualIntPerXing;
      fHandles[ "averageIntPerXing" ] = &averageIntPerXing;
      fHandles[ "pixelFlags" ] = &pixelFlags;
      fHandles[ "sctFlags" ] = &sctFlags;
      fHandles[ "trtFlags" ] = &trtFlags;
      fHandles[ "larFlags" ] = &larFlags;
      fHandles[ "tileFlags" ] = &tileFlags;
      fHandles[ "muonFlags" ] = &muonFlags;
      fHandles[ "fwdFlags" ] = &fwdFlags;
      fHandles[ "coreFlags" ] = &coreFlags;
      fHandles[ "pixelError" ] = &pixelError;
      fHandles[ "sctError" ] = &sctError;
      fHandles[ "trtError" ] = &trtError;
      fHandles[ "larError" ] = &larError;
      fHandles[ "tileError" ] = &tileError;
      fHandles[ "muonError" ] = &muonError;
      fHandles[ "fwdError" ] = &fwdError;
      fHandles[ "coreError" ] = &coreError;
      fHandles[ "Eventshape_rhoKt3EM" ] = &Eventshape_rhoKt3EM;
      fHandles[ "Eventshape_rhoKt4EM" ] = &Eventshape_rhoKt4EM;
      fHandles[ "Eventshape_rhoKt3LC" ] = &Eventshape_rhoKt3LC;
      fHandles[ "Eventshape_rhoKt4LC" ] = &Eventshape_rhoKt4LC;
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* EventInfoD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void EventInfoD3PDObject::SetPrefix( const char* prefix ) {

      RunNumber.SetName( ::TString( prefix ) + "RunNumber" );
      EventNumber.SetName( ::TString( prefix ) + "EventNumber" );
      timestamp.SetName( ::TString( prefix ) + "timestamp" );
      timestamp_ns.SetName( ::TString( prefix ) + "timestamp_ns" );
      lbn.SetName( ::TString( prefix ) + "lbn" );
      bcid.SetName( ::TString( prefix ) + "bcid" );
      detmask0.SetName( ::TString( prefix ) + "detmask0" );
      detmask1.SetName( ::TString( prefix ) + "detmask1" );
      actualIntPerXing.SetName( ::TString( prefix ) + "actualIntPerXing" );
      averageIntPerXing.SetName( ::TString( prefix ) + "averageIntPerXing" );
      pixelFlags.SetName( ::TString( prefix ) + "pixelFlags" );
      sctFlags.SetName( ::TString( prefix ) + "sctFlags" );
      trtFlags.SetName( ::TString( prefix ) + "trtFlags" );
      larFlags.SetName( ::TString( prefix ) + "larFlags" );
      tileFlags.SetName( ::TString( prefix ) + "tileFlags" );
      muonFlags.SetName( ::TString( prefix ) + "muonFlags" );
      fwdFlags.SetName( ::TString( prefix ) + "fwdFlags" );
      coreFlags.SetName( ::TString( prefix ) + "coreFlags" );
      pixelError.SetName( ::TString( prefix ) + "pixelError" );
      sctError.SetName( ::TString( prefix ) + "sctError" );
      trtError.SetName( ::TString( prefix ) + "trtError" );
      larError.SetName( ::TString( prefix ) + "larError" );
      tileError.SetName( ::TString( prefix ) + "tileError" );
      muonError.SetName( ::TString( prefix ) + "muonError" );
      fwdError.SetName( ::TString( prefix ) + "fwdError" );
      coreError.SetName( ::TString( prefix ) + "coreError" );
      Eventshape_rhoKt3EM.SetName( ::TString( prefix ) + "Eventshape_rhoKt3EM" );
      Eventshape_rhoKt4EM.SetName( ::TString( prefix ) + "Eventshape_rhoKt4EM" );
      Eventshape_rhoKt3LC.SetName( ::TString( prefix ) + "Eventshape_rhoKt3LC" );
      Eventshape_rhoKt4LC.SetName( ::TString( prefix ) + "Eventshape_rhoKt4LC" );
      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void EventInfoD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      RunNumber.ReadFrom( tree );
      EventNumber.ReadFrom( tree );
      timestamp.ReadFrom( tree );
      timestamp_ns.ReadFrom( tree );
      lbn.ReadFrom( tree );
      bcid.ReadFrom( tree );
      detmask0.ReadFrom( tree );
      detmask1.ReadFrom( tree );
      actualIntPerXing.ReadFrom( tree );
      averageIntPerXing.ReadFrom( tree );
      pixelFlags.ReadFrom( tree );
      sctFlags.ReadFrom( tree );
      trtFlags.ReadFrom( tree );
      larFlags.ReadFrom( tree );
      tileFlags.ReadFrom( tree );
      muonFlags.ReadFrom( tree );
      fwdFlags.ReadFrom( tree );
      coreFlags.ReadFrom( tree );
      pixelError.ReadFrom( tree );
      sctError.ReadFrom( tree );
      trtError.ReadFrom( tree );
      larError.ReadFrom( tree );
      tileError.ReadFrom( tree );
      muonError.ReadFrom( tree );
      fwdError.ReadFrom( tree );
      coreError.ReadFrom( tree );
      Eventshape_rhoKt3EM.ReadFrom( tree );
      Eventshape_rhoKt4EM.ReadFrom( tree );
      Eventshape_rhoKt3LC.ReadFrom( tree );
      Eventshape_rhoKt4LC.ReadFrom( tree );

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void EventInfoD3PDObject::WriteTo( TTree* tree ) {

      RunNumber.WriteTo( tree );
      EventNumber.WriteTo( tree );
      timestamp.WriteTo( tree );
      timestamp_ns.WriteTo( tree );
      lbn.WriteTo( tree );
      bcid.WriteTo( tree );
      detmask0.WriteTo( tree );
      detmask1.WriteTo( tree );
      actualIntPerXing.WriteTo( tree );
      averageIntPerXing.WriteTo( tree );
      pixelFlags.WriteTo( tree );
      sctFlags.WriteTo( tree );
      trtFlags.WriteTo( tree );
      larFlags.WriteTo( tree );
      tileFlags.WriteTo( tree );
      muonFlags.WriteTo( tree );
      fwdFlags.WriteTo( tree );
      coreFlags.WriteTo( tree );
      pixelError.WriteTo( tree );
      sctError.WriteTo( tree );
      trtError.WriteTo( tree );
      larError.WriteTo( tree );
      tileError.WriteTo( tree );
      muonError.WriteTo( tree );
      fwdError.WriteTo( tree );
      coreError.WriteTo( tree );
      Eventshape_rhoKt3EM.WriteTo( tree );
      Eventshape_rhoKt4EM.WriteTo( tree );
      Eventshape_rhoKt3LC.WriteTo( tree );
      Eventshape_rhoKt4LC.WriteTo( tree );

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
   void EventInfoD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void EventInfoD3PDObject::ReadAllActive() {

      // Check if it makes sense to call this function:
      if( ! fFromInput ) {
         static ::Bool_t wPrinted = kFALSE;
         if( ! wPrinted ) {
            Warning( "ReadAllActive", "Function only meaningful when used on objects" );
            Warning( "ReadAllActive", "which are used to read information from a D3PD" );
            wPrinted = kTRUE;
         }
      }

      if( RunNumber.IsActive() ) RunNumber();
      if( EventNumber.IsActive() ) EventNumber();
      if( timestamp.IsActive() ) timestamp();
      if( timestamp_ns.IsActive() ) timestamp_ns();
      if( lbn.IsActive() ) lbn();
      if( bcid.IsActive() ) bcid();
      if( detmask0.IsActive() ) detmask0();
      if( detmask1.IsActive() ) detmask1();
      if( actualIntPerXing.IsActive() ) actualIntPerXing();
      if( averageIntPerXing.IsActive() ) averageIntPerXing();
      if( pixelFlags.IsActive() ) pixelFlags();
      if( sctFlags.IsActive() ) sctFlags();
      if( trtFlags.IsActive() ) trtFlags();
      if( larFlags.IsActive() ) larFlags();
      if( tileFlags.IsActive() ) tileFlags();
      if( muonFlags.IsActive() ) muonFlags();
      if( fwdFlags.IsActive() ) fwdFlags();
      if( coreFlags.IsActive() ) coreFlags();
      if( pixelError.IsActive() ) pixelError();
      if( sctError.IsActive() ) sctError();
      if( trtError.IsActive() ) trtError();
      if( larError.IsActive() ) larError();
      if( tileError.IsActive() ) tileError();
      if( muonError.IsActive() ) muonError();
      if( fwdError.IsActive() ) fwdError();
      if( coreError.IsActive() ) coreError();
      if( Eventshape_rhoKt3EM.IsActive() ) Eventshape_rhoKt3EM();
      if( Eventshape_rhoKt4EM.IsActive() ) Eventshape_rhoKt4EM();
      if( Eventshape_rhoKt3LC.IsActive() ) Eventshape_rhoKt3LC();
      if( Eventshape_rhoKt4LC.IsActive() ) Eventshape_rhoKt4LC();

      return;
   }

} // namespace D3PDReader
