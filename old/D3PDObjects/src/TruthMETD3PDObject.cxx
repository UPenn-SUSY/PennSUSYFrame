// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <TPRegexp.h>

#include "../include/TruthMETD3PDObject.h"

ClassImp( D3PDReader::TruthMETD3PDObject )

namespace D3PDReader {

   /**
    * This constructor should be used when the object will be used to read
    * variables from an existing ntuple. The object will also be able to
    * output variables, but it will also need to read them from somewhere.
    *
    * @param master Reference to the variable holding the current event number
    * @param prefix Prefix of the variables in the D3PD
    */
   TruthMETD3PDObject::TruthMETD3PDObject( const ::Long64_t& master, const char* prefix )
      : TObject(),
        NonInt_etx( this, ::TString( prefix ) + "NonInt_etx", &master ),
        NonInt_ety( this, ::TString( prefix ) + "NonInt_ety", &master ),
        NonInt_sumet( this, ::TString( prefix ) + "NonInt_sumet", &master ),
        Int_etx( this, ::TString( prefix ) + "Int_etx", &master ),
        Int_ety( this, ::TString( prefix ) + "Int_ety", &master ),
        IntCentral_etx( this, ::TString( prefix ) + "IntCentral_etx", &master ),
        IntCentral_ety( this, ::TString( prefix ) + "IntCentral_ety", &master ),
        IntFwd_etx( this, ::TString( prefix ) + "IntFwd_etx", &master ),
        IntFwd_ety( this, ::TString( prefix ) + "IntFwd_ety", &master ),
        IntOutCover_etx( this, ::TString( prefix ) + "IntOutCover_etx", &master ),
        IntOutCover_ety( this, ::TString( prefix ) + "IntOutCover_ety", &master ),
        IntMuons_etx( this, ::TString( prefix ) + "IntMuons_etx", &master ),
        IntMuons_ety( this, ::TString( prefix ) + "IntMuons_ety", &master ),
        Int_sumet( this, ::TString( prefix ) + "Int_sumet", &master ),
        IntCentral_sumet( this, ::TString( prefix ) + "IntCentral_sumet", &master ),
        IntFwd_sumet( this, ::TString( prefix ) + "IntFwd_sumet", &master ),
        IntOutCover_sumet( this, ::TString( prefix ) + "IntOutCover_sumet", &master ),
        IntMuons_sumet( this, ::TString( prefix ) + "IntMuons_sumet", &master ),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) {

      fHandles[ "NonInt_etx" ] = &NonInt_etx;
      fHandles[ "NonInt_ety" ] = &NonInt_ety;
      fHandles[ "NonInt_sumet" ] = &NonInt_sumet;
      fHandles[ "Int_etx" ] = &Int_etx;
      fHandles[ "Int_ety" ] = &Int_ety;
      fHandles[ "IntCentral_etx" ] = &IntCentral_etx;
      fHandles[ "IntCentral_ety" ] = &IntCentral_ety;
      fHandles[ "IntFwd_etx" ] = &IntFwd_etx;
      fHandles[ "IntFwd_ety" ] = &IntFwd_ety;
      fHandles[ "IntOutCover_etx" ] = &IntOutCover_etx;
      fHandles[ "IntOutCover_ety" ] = &IntOutCover_ety;
      fHandles[ "IntMuons_etx" ] = &IntMuons_etx;
      fHandles[ "IntMuons_ety" ] = &IntMuons_ety;
      fHandles[ "Int_sumet" ] = &Int_sumet;
      fHandles[ "IntCentral_sumet" ] = &IntCentral_sumet;
      fHandles[ "IntFwd_sumet" ] = &IntFwd_sumet;
      fHandles[ "IntOutCover_sumet" ] = &IntOutCover_sumet;
      fHandles[ "IntMuons_sumet" ] = &IntMuons_sumet;
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   TruthMETD3PDObject::TruthMETD3PDObject( const char* prefix )
      : TObject(),
        NonInt_etx( this, ::TString( prefix ) + "NonInt_etx", 0 ),
        NonInt_ety( this, ::TString( prefix ) + "NonInt_ety", 0 ),
        NonInt_sumet( this, ::TString( prefix ) + "NonInt_sumet", 0 ),
        Int_etx( this, ::TString( prefix ) + "Int_etx", 0 ),
        Int_ety( this, ::TString( prefix ) + "Int_ety", 0 ),
        IntCentral_etx( this, ::TString( prefix ) + "IntCentral_etx", 0 ),
        IntCentral_ety( this, ::TString( prefix ) + "IntCentral_ety", 0 ),
        IntFwd_etx( this, ::TString( prefix ) + "IntFwd_etx", 0 ),
        IntFwd_ety( this, ::TString( prefix ) + "IntFwd_ety", 0 ),
        IntOutCover_etx( this, ::TString( prefix ) + "IntOutCover_etx", 0 ),
        IntOutCover_ety( this, ::TString( prefix ) + "IntOutCover_ety", 0 ),
        IntMuons_etx( this, ::TString( prefix ) + "IntMuons_etx", 0 ),
        IntMuons_ety( this, ::TString( prefix ) + "IntMuons_ety", 0 ),
        Int_sumet( this, ::TString( prefix ) + "Int_sumet", 0 ),
        IntCentral_sumet( this, ::TString( prefix ) + "IntCentral_sumet", 0 ),
        IntFwd_sumet( this, ::TString( prefix ) + "IntFwd_sumet", 0 ),
        IntOutCover_sumet( this, ::TString( prefix ) + "IntOutCover_sumet", 0 ),
        IntMuons_sumet( this, ::TString( prefix ) + "IntMuons_sumet", 0 ),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) {

      fHandles[ "NonInt_etx" ] = &NonInt_etx;
      fHandles[ "NonInt_ety" ] = &NonInt_ety;
      fHandles[ "NonInt_sumet" ] = &NonInt_sumet;
      fHandles[ "Int_etx" ] = &Int_etx;
      fHandles[ "Int_ety" ] = &Int_ety;
      fHandles[ "IntCentral_etx" ] = &IntCentral_etx;
      fHandles[ "IntCentral_ety" ] = &IntCentral_ety;
      fHandles[ "IntFwd_etx" ] = &IntFwd_etx;
      fHandles[ "IntFwd_ety" ] = &IntFwd_ety;
      fHandles[ "IntOutCover_etx" ] = &IntOutCover_etx;
      fHandles[ "IntOutCover_ety" ] = &IntOutCover_ety;
      fHandles[ "IntMuons_etx" ] = &IntMuons_etx;
      fHandles[ "IntMuons_ety" ] = &IntMuons_ety;
      fHandles[ "Int_sumet" ] = &Int_sumet;
      fHandles[ "IntCentral_sumet" ] = &IntCentral_sumet;
      fHandles[ "IntFwd_sumet" ] = &IntFwd_sumet;
      fHandles[ "IntOutCover_sumet" ] = &IntOutCover_sumet;
      fHandles[ "IntMuons_sumet" ] = &IntMuons_sumet;
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* TruthMETD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void TruthMETD3PDObject::SetPrefix( const char* prefix ) {

      NonInt_etx.SetName( ::TString( prefix ) + "NonInt_etx" );
      NonInt_ety.SetName( ::TString( prefix ) + "NonInt_ety" );
      NonInt_sumet.SetName( ::TString( prefix ) + "NonInt_sumet" );
      Int_etx.SetName( ::TString( prefix ) + "Int_etx" );
      Int_ety.SetName( ::TString( prefix ) + "Int_ety" );
      IntCentral_etx.SetName( ::TString( prefix ) + "IntCentral_etx" );
      IntCentral_ety.SetName( ::TString( prefix ) + "IntCentral_ety" );
      IntFwd_etx.SetName( ::TString( prefix ) + "IntFwd_etx" );
      IntFwd_ety.SetName( ::TString( prefix ) + "IntFwd_ety" );
      IntOutCover_etx.SetName( ::TString( prefix ) + "IntOutCover_etx" );
      IntOutCover_ety.SetName( ::TString( prefix ) + "IntOutCover_ety" );
      IntMuons_etx.SetName( ::TString( prefix ) + "IntMuons_etx" );
      IntMuons_ety.SetName( ::TString( prefix ) + "IntMuons_ety" );
      Int_sumet.SetName( ::TString( prefix ) + "Int_sumet" );
      IntCentral_sumet.SetName( ::TString( prefix ) + "IntCentral_sumet" );
      IntFwd_sumet.SetName( ::TString( prefix ) + "IntFwd_sumet" );
      IntOutCover_sumet.SetName( ::TString( prefix ) + "IntOutCover_sumet" );
      IntMuons_sumet.SetName( ::TString( prefix ) + "IntMuons_sumet" );
      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void TruthMETD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      NonInt_etx.ReadFrom( tree );
      NonInt_ety.ReadFrom( tree );
      NonInt_sumet.ReadFrom( tree );
      Int_etx.ReadFrom( tree );
      Int_ety.ReadFrom( tree );
      IntCentral_etx.ReadFrom( tree );
      IntCentral_ety.ReadFrom( tree );
      IntFwd_etx.ReadFrom( tree );
      IntFwd_ety.ReadFrom( tree );
      IntOutCover_etx.ReadFrom( tree );
      IntOutCover_ety.ReadFrom( tree );
      IntMuons_etx.ReadFrom( tree );
      IntMuons_ety.ReadFrom( tree );
      Int_sumet.ReadFrom( tree );
      IntCentral_sumet.ReadFrom( tree );
      IntFwd_sumet.ReadFrom( tree );
      IntOutCover_sumet.ReadFrom( tree );
      IntMuons_sumet.ReadFrom( tree );

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void TruthMETD3PDObject::WriteTo( TTree* tree ) {

      NonInt_etx.WriteTo( tree );
      NonInt_ety.WriteTo( tree );
      NonInt_sumet.WriteTo( tree );
      Int_etx.WriteTo( tree );
      Int_ety.WriteTo( tree );
      IntCentral_etx.WriteTo( tree );
      IntCentral_ety.WriteTo( tree );
      IntFwd_etx.WriteTo( tree );
      IntFwd_ety.WriteTo( tree );
      IntOutCover_etx.WriteTo( tree );
      IntOutCover_ety.WriteTo( tree );
      IntMuons_etx.WriteTo( tree );
      IntMuons_ety.WriteTo( tree );
      Int_sumet.WriteTo( tree );
      IntCentral_sumet.WriteTo( tree );
      IntFwd_sumet.WriteTo( tree );
      IntOutCover_sumet.WriteTo( tree );
      IntMuons_sumet.WriteTo( tree );

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
   void TruthMETD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void TruthMETD3PDObject::ReadAllActive() {

      // Check if it makes sense to call this function:
      if( ! fFromInput ) {
         static ::Bool_t wPrinted = kFALSE;
         if( ! wPrinted ) {
            Warning( "ReadAllActive", "Function only meaningful when used on objects" );
            Warning( "ReadAllActive", "which are used to read information from a D3PD" );
            wPrinted = kTRUE;
         }
      }

      if( NonInt_etx.IsActive() ) NonInt_etx();
      if( NonInt_ety.IsActive() ) NonInt_ety();
      if( NonInt_sumet.IsActive() ) NonInt_sumet();
      if( Int_etx.IsActive() ) Int_etx();
      if( Int_ety.IsActive() ) Int_ety();
      if( IntCentral_etx.IsActive() ) IntCentral_etx();
      if( IntCentral_ety.IsActive() ) IntCentral_ety();
      if( IntFwd_etx.IsActive() ) IntFwd_etx();
      if( IntFwd_ety.IsActive() ) IntFwd_ety();
      if( IntOutCover_etx.IsActive() ) IntOutCover_etx();
      if( IntOutCover_ety.IsActive() ) IntOutCover_ety();
      if( IntMuons_etx.IsActive() ) IntMuons_etx();
      if( IntMuons_ety.IsActive() ) IntMuons_ety();
      if( Int_sumet.IsActive() ) Int_sumet();
      if( IntCentral_sumet.IsActive() ) IntCentral_sumet();
      if( IntFwd_sumet.IsActive() ) IntFwd_sumet();
      if( IntOutCover_sumet.IsActive() ) IntOutCover_sumet();
      if( IntMuons_sumet.IsActive() ) IntMuons_sumet();

      return;
   }

} // namespace D3PDReader
