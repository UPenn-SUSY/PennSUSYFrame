// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <TPRegexp.h>

#include "../include/TriggerD3PDObject.h"

ClassImp( D3PDReader::TriggerD3PDObject )

namespace D3PDReader {

   /**
    * This constructor should be used when the object will be used to read
    * variables from an existing ntuple. The object will also be able to
    * output variables, but it will also need to read them from somewhere.
    *
    * @param master Reference to the variable holding the current event number
    * @param prefix Prefix of the variables in the D3PD
    */
   TriggerD3PDObject::TriggerD3PDObject( const ::Long64_t& master, const char* prefix , bool is_data )
      : TObject(),
        EF_2e12Tvh_loose1( this, ::TString( prefix ) + "EF_2e12Tvh_loose1", &master ),
        EF_2mu13( this, ::TString( prefix ) + "EF_2mu13", &master ),
        EF_e12Tvh_medium1_mu8( this, ::TString( prefix ) + "EF_e12Tvh_medium1_mu8", &master ),
        EF_e24vh_medium1_e7_medium1( this, ::TString( prefix ) + "EF_e24vh_medium1_e7_medium1", &master ),
        EF_mu18_tight_e7_medium1( this, ::TString( prefix ) + "EF_mu18_tight_e7_medium1", &master ),
        EF_mu18_tight_mu8_EFFS( this, ::TString( prefix ) + "EF_mu18_tight_mu8_EFFS", &master ),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "EF_2e12Tvh_loose1" ] = &EF_2e12Tvh_loose1;
      fHandles[ "EF_2mu13" ] = &EF_2mu13;
      fHandles[ "EF_e12Tvh_medium1_mu8" ] = &EF_e12Tvh_medium1_mu8;
      fHandles[ "EF_e24vh_medium1_e7_medium1" ] = &EF_e24vh_medium1_e7_medium1;
      fHandles[ "EF_mu18_tight_e7_medium1" ] = &EF_mu18_tight_e7_medium1;
      fHandles[ "EF_mu18_tight_mu8_EFFS" ] = &EF_mu18_tight_mu8_EFFS;
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   TriggerD3PDObject::TriggerD3PDObject( const char* prefix , bool is_data )
      : TObject(),
        EF_2e12Tvh_loose1( this, ::TString( prefix ) + "EF_2e12Tvh_loose1", 0 ),
        EF_2mu13( this, ::TString( prefix ) + "EF_2mu13", 0 ),
        EF_e12Tvh_medium1_mu8( this, ::TString( prefix ) + "EF_e12Tvh_medium1_mu8", 0 ),
        EF_e24vh_medium1_e7_medium1( this, ::TString( prefix ) + "EF_e24vh_medium1_e7_medium1", 0 ),
        EF_mu18_tight_e7_medium1( this, ::TString( prefix ) + "EF_mu18_tight_e7_medium1", 0 ),
        EF_mu18_tight_mu8_EFFS( this, ::TString( prefix ) + "EF_mu18_tight_mu8_EFFS", 0 ),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "EF_2e12Tvh_loose1" ] = &EF_2e12Tvh_loose1;
      fHandles[ "EF_2mu13" ] = &EF_2mu13;
      fHandles[ "EF_e12Tvh_medium1_mu8" ] = &EF_e12Tvh_medium1_mu8;
      fHandles[ "EF_e24vh_medium1_e7_medium1" ] = &EF_e24vh_medium1_e7_medium1;
      fHandles[ "EF_mu18_tight_e7_medium1" ] = &EF_mu18_tight_e7_medium1;
      fHandles[ "EF_mu18_tight_mu8_EFFS" ] = &EF_mu18_tight_mu8_EFFS;
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* TriggerD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void TriggerD3PDObject::SetPrefix( const char* prefix ) {

      EF_2e12Tvh_loose1.SetName( ::TString( prefix ) + "EF_2e12Tvh_loose1" );
      EF_2mu13.SetName( ::TString( prefix ) + "EF_2mu13" );
      EF_e12Tvh_medium1_mu8.SetName( ::TString( prefix ) + "EF_e12Tvh_medium1_mu8" );
      EF_e24vh_medium1_e7_medium1.SetName( ::TString( prefix ) + "EF_e24vh_medium1_e7_medium1" );
      EF_mu18_tight_e7_medium1.SetName( ::TString( prefix ) + "EF_mu18_tight_e7_medium1" );
      EF_mu18_tight_mu8_EFFS.SetName( ::TString( prefix ) + "EF_mu18_tight_mu8_EFFS" );
      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void TriggerD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      EF_2e12Tvh_loose1.ReadFrom( tree );
      EF_2mu13.ReadFrom( tree );
      EF_e12Tvh_medium1_mu8.ReadFrom( tree );
      EF_e24vh_medium1_e7_medium1.ReadFrom( tree );
      EF_mu18_tight_e7_medium1.ReadFrom( tree );
      EF_mu18_tight_mu8_EFFS.ReadFrom( tree );

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void TriggerD3PDObject::WriteTo( TTree* tree ) {

      EF_2e12Tvh_loose1.WriteTo( tree );
      EF_2mu13.WriteTo( tree );
      EF_e12Tvh_medium1_mu8.WriteTo( tree );
      EF_e24vh_medium1_e7_medium1.WriteTo( tree );
      EF_mu18_tight_e7_medium1.WriteTo( tree );
      EF_mu18_tight_mu8_EFFS.WriteTo( tree );

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
   void TriggerD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void TriggerD3PDObject::ReadAllActive() {

      // Check if it makes sense to call this function:
      if( ! fFromInput ) {
         static ::Bool_t wPrinted = kFALSE;
         if( ! wPrinted ) {
            Warning( "ReadAllActive", "Function only meaningful when used on objects" );
            Warning( "ReadAllActive", "which are used to read information from a D3PD" );
            wPrinted = kTRUE;
         }
      }

      if( EF_2e12Tvh_loose1.IsActive() ) EF_2e12Tvh_loose1();
      if( EF_2mu13.IsActive() ) EF_2mu13();
      if( EF_e12Tvh_medium1_mu8.IsActive() ) EF_e12Tvh_medium1_mu8();
      if( EF_e24vh_medium1_e7_medium1.IsActive() ) EF_e24vh_medium1_e7_medium1();
      if( EF_mu18_tight_e7_medium1.IsActive() ) EF_mu18_tight_e7_medium1();
      if( EF_mu18_tight_mu8_EFFS.IsActive() ) EF_mu18_tight_mu8_EFFS();

      return;
   }

} // namespace D3PDReader
