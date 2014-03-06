// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <limits>

#include <TPRegexp.h>

#include "../include/TriggerVecD3PDObject.h"

ClassImp( D3PDReader::TriggerVecD3PDObjectElement )
ClassImp( D3PDReader::TriggerVecD3PDObject )

namespace D3PDReader {

   /**
    * This constructor can be used to create new proxy objects from scratch.
    * Since the constructor of such an object is quite complicated and
    * error prone, it is only visible to the parent class TriggerVecD3PDObject.
    */
   TriggerVecD3PDObjectElement::TriggerVecD3PDObjectElement( size_t index, const TriggerVecD3PDObject& parent , bool is_data )
      : trig_EF_el_EF_e12Tvh_loose1( parent.trig_EF_el_EF_e12Tvh_loose1, index, this ),
        trig_EF_el_EF_e12Tvh_medium1( parent.trig_EF_el_EF_e12Tvh_medium1, index, this ),
        trig_EF_el_EF_e24vh_medium1( parent.trig_EF_el_EF_e24vh_medium1, index, this ),
        trig_EF_el_EF_e24vh_medium1_e7_medium1( parent.trig_EF_el_EF_e24vh_medium1_e7_medium1, index, this ),
        trig_EF_el_EF_e7T_medium1( parent.trig_EF_el_EF_e7T_medium1, index, this ),
        trig_EF_trigmuonef_EF_mu13( parent.trig_EF_trigmuonef_EF_mu13, index, this ),
        trig_EF_trigmuonef_EF_mu18_tight( parent.trig_EF_trigmuonef_EF_mu18_tight, index, this ),
        trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS( parent.trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS, index, this ),
        trig_EF_trigmuonef_EF_mu8( parent.trig_EF_trigmuonef_EF_mu8, index, this ),
        trig_EF_el_E( parent.trig_EF_el_E, index, this ),
        trig_EF_el_px( parent.trig_EF_el_px, index, this ),
        trig_EF_el_py( parent.trig_EF_el_py, index, this ),
        trig_EF_el_pz( parent.trig_EF_el_pz, index, this ),
        trig_EF_trigmuonef_track_CB_pt( parent.trig_EF_trigmuonef_track_CB_pt, index, this ),
        trig_EF_trigmuonef_track_CB_eta( parent.trig_EF_trigmuonef_track_CB_eta, index, this ),
        trig_EF_trigmuonef_track_CB_phi( parent.trig_EF_trigmuonef_track_CB_phi, index, this ),
        trig_EF_trigmuonef_track_CB_hasCB( parent.trig_EF_trigmuonef_track_CB_hasCB, index, this ), 
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
   TriggerVecD3PDObjectElement::TriggerVecD3PDObjectElement( const TriggerVecD3PDObjectElement& parent , bool is_data )
      : TObject( parent ),
        trig_EF_el_EF_e12Tvh_loose1( parent.trig_EF_el_EF_e12Tvh_loose1 ),
        trig_EF_el_EF_e12Tvh_medium1( parent.trig_EF_el_EF_e12Tvh_medium1 ),
        trig_EF_el_EF_e24vh_medium1( parent.trig_EF_el_EF_e24vh_medium1 ),
        trig_EF_el_EF_e24vh_medium1_e7_medium1( parent.trig_EF_el_EF_e24vh_medium1_e7_medium1 ),
        trig_EF_el_EF_e7T_medium1( parent.trig_EF_el_EF_e7T_medium1 ),
        trig_EF_trigmuonef_EF_mu13( parent.trig_EF_trigmuonef_EF_mu13 ),
        trig_EF_trigmuonef_EF_mu18_tight( parent.trig_EF_trigmuonef_EF_mu18_tight ),
        trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS( parent.trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS ),
        trig_EF_trigmuonef_EF_mu8( parent.trig_EF_trigmuonef_EF_mu8 ),
        trig_EF_el_E( parent.trig_EF_el_E ),
        trig_EF_el_px( parent.trig_EF_el_px ),
        trig_EF_el_py( parent.trig_EF_el_py ),
        trig_EF_el_pz( parent.trig_EF_el_pz ),
        trig_EF_trigmuonef_track_CB_pt( parent.trig_EF_trigmuonef_track_CB_pt ),
        trig_EF_trigmuonef_track_CB_eta( parent.trig_EF_trigmuonef_track_CB_eta ),
        trig_EF_trigmuonef_track_CB_phi( parent.trig_EF_trigmuonef_track_CB_phi ),
        trig_EF_trigmuonef_track_CB_hasCB( parent.trig_EF_trigmuonef_track_CB_hasCB ), 
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
   TriggerVecD3PDObject::TriggerVecD3PDObject( const ::Long64_t& master, const char* prefix , bool is_data )
      : TObject(),
        trig_EF_el_EF_e12Tvh_loose1( this, ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_loose1", &master ),
        trig_EF_el_EF_e12Tvh_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_medium1", &master ),
        trig_EF_el_EF_e24vh_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1", &master ),
        trig_EF_el_EF_e24vh_medium1_e7_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_e7_medium1", &master ),
        trig_EF_el_EF_e7T_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e7T_medium1", &master ),
        trig_EF_trigmuonef_EF_mu13( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu13", &master ),
        trig_EF_trigmuonef_EF_mu18_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_tight", &master ),
        trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS", &master ),
        trig_EF_trigmuonef_EF_mu8( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu8", &master ),
        trig_EF_el_E( this, ::TString( prefix ) + "trig_EF_el_E", &master ),
        trig_EF_el_px( this, ::TString( prefix ) + "trig_EF_el_px", &master ),
        trig_EF_el_py( this, ::TString( prefix ) + "trig_EF_el_py", &master ),
        trig_EF_el_pz( this, ::TString( prefix ) + "trig_EF_el_pz", &master ),
        trig_EF_trigmuonef_track_CB_pt( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_pt", &master ),
        trig_EF_trigmuonef_track_CB_eta( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_eta", &master ),
        trig_EF_trigmuonef_track_CB_phi( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_phi", &master ),
        trig_EF_trigmuonef_track_CB_hasCB( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_hasCB", &master ),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ), 
is_data(is_data) {

      fHandles[ "trig_EF_el_EF_e12Tvh_loose1" ] = &trig_EF_el_EF_e12Tvh_loose1;
      fHandles[ "trig_EF_el_EF_e12Tvh_medium1" ] = &trig_EF_el_EF_e12Tvh_medium1;
      fHandles[ "trig_EF_el_EF_e24vh_medium1" ] = &trig_EF_el_EF_e24vh_medium1;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_e7_medium1" ] = &trig_EF_el_EF_e24vh_medium1_e7_medium1;
      fHandles[ "trig_EF_el_EF_e7T_medium1" ] = &trig_EF_el_EF_e7T_medium1;
      fHandles[ "trig_EF_trigmuonef_EF_mu13" ] = &trig_EF_trigmuonef_EF_mu13;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_tight" ] = &trig_EF_trigmuonef_EF_mu18_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS" ] = &trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS;
      fHandles[ "trig_EF_trigmuonef_EF_mu8" ] = &trig_EF_trigmuonef_EF_mu8;
      fHandles[ "trig_EF_el_E" ] = &trig_EF_el_E;
      fHandles[ "trig_EF_el_px" ] = &trig_EF_el_px;
      fHandles[ "trig_EF_el_py" ] = &trig_EF_el_py;
      fHandles[ "trig_EF_el_pz" ] = &trig_EF_el_pz;
      fHandles[ "trig_EF_trigmuonef_track_CB_pt" ] = &trig_EF_trigmuonef_track_CB_pt;
      fHandles[ "trig_EF_trigmuonef_track_CB_eta" ] = &trig_EF_trigmuonef_track_CB_eta;
      fHandles[ "trig_EF_trigmuonef_track_CB_phi" ] = &trig_EF_trigmuonef_track_CB_phi;
      fHandles[ "trig_EF_trigmuonef_track_CB_hasCB" ] = &trig_EF_trigmuonef_track_CB_hasCB;
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   TriggerVecD3PDObject::TriggerVecD3PDObject( const char* prefix , bool is_data )
      : TObject(),
        trig_EF_el_EF_e12Tvh_loose1( this, ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_loose1", 0 ),
        trig_EF_el_EF_e12Tvh_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_medium1", 0 ),
        trig_EF_el_EF_e24vh_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1", 0 ),
        trig_EF_el_EF_e24vh_medium1_e7_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_e7_medium1", 0 ),
        trig_EF_el_EF_e7T_medium1( this, ::TString( prefix ) + "trig_EF_el_EF_e7T_medium1", 0 ),
        trig_EF_trigmuonef_EF_mu13( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu13", 0 ),
        trig_EF_trigmuonef_EF_mu18_tight( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_tight", 0 ),
        trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS", 0 ),
        trig_EF_trigmuonef_EF_mu8( this, ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu8", 0 ),
        trig_EF_el_E( this, ::TString( prefix ) + "trig_EF_el_E", 0 ),
        trig_EF_el_px( this, ::TString( prefix ) + "trig_EF_el_px", 0 ),
        trig_EF_el_py( this, ::TString( prefix ) + "trig_EF_el_py", 0 ),
        trig_EF_el_pz( this, ::TString( prefix ) + "trig_EF_el_pz", 0 ),
        trig_EF_trigmuonef_track_CB_pt( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_pt", 0 ),
        trig_EF_trigmuonef_track_CB_eta( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_eta", 0 ),
        trig_EF_trigmuonef_track_CB_phi( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_phi", 0 ),
        trig_EF_trigmuonef_track_CB_hasCB( this, ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_hasCB", 0 ),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ), 
is_data(is_data) {

      fHandles[ "trig_EF_el_EF_e12Tvh_loose1" ] = &trig_EF_el_EF_e12Tvh_loose1;
      fHandles[ "trig_EF_el_EF_e12Tvh_medium1" ] = &trig_EF_el_EF_e12Tvh_medium1;
      fHandles[ "trig_EF_el_EF_e24vh_medium1" ] = &trig_EF_el_EF_e24vh_medium1;
      fHandles[ "trig_EF_el_EF_e24vh_medium1_e7_medium1" ] = &trig_EF_el_EF_e24vh_medium1_e7_medium1;
      fHandles[ "trig_EF_el_EF_e7T_medium1" ] = &trig_EF_el_EF_e7T_medium1;
      fHandles[ "trig_EF_trigmuonef_EF_mu13" ] = &trig_EF_trigmuonef_EF_mu13;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_tight" ] = &trig_EF_trigmuonef_EF_mu18_tight;
      fHandles[ "trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS" ] = &trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS;
      fHandles[ "trig_EF_trigmuonef_EF_mu8" ] = &trig_EF_trigmuonef_EF_mu8;
      fHandles[ "trig_EF_el_E" ] = &trig_EF_el_E;
      fHandles[ "trig_EF_el_px" ] = &trig_EF_el_px;
      fHandles[ "trig_EF_el_py" ] = &trig_EF_el_py;
      fHandles[ "trig_EF_el_pz" ] = &trig_EF_el_pz;
      fHandles[ "trig_EF_trigmuonef_track_CB_pt" ] = &trig_EF_trigmuonef_track_CB_pt;
      fHandles[ "trig_EF_trigmuonef_track_CB_eta" ] = &trig_EF_trigmuonef_track_CB_eta;
      fHandles[ "trig_EF_trigmuonef_track_CB_phi" ] = &trig_EF_trigmuonef_track_CB_phi;
      fHandles[ "trig_EF_trigmuonef_track_CB_hasCB" ] = &trig_EF_trigmuonef_track_CB_hasCB;
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* TriggerVecD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void TriggerVecD3PDObject::SetPrefix( const char* prefix ) {

      trig_EF_el_EF_e12Tvh_loose1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_loose1" );
      trig_EF_el_EF_e12Tvh_medium1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e12Tvh_medium1" );
      trig_EF_el_EF_e24vh_medium1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1" );
      trig_EF_el_EF_e24vh_medium1_e7_medium1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e24vh_medium1_e7_medium1" );
      trig_EF_el_EF_e7T_medium1.SetName( ::TString( prefix ) + "trig_EF_el_EF_e7T_medium1" );
      trig_EF_trigmuonef_EF_mu13.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu13" );
      trig_EF_trigmuonef_EF_mu18_tight.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_tight" );
      trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS" );
      trig_EF_trigmuonef_EF_mu8.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_EF_mu8" );
      trig_EF_el_E.SetName( ::TString( prefix ) + "trig_EF_el_E" );
      trig_EF_el_px.SetName( ::TString( prefix ) + "trig_EF_el_px" );
      trig_EF_el_py.SetName( ::TString( prefix ) + "trig_EF_el_py" );
      trig_EF_el_pz.SetName( ::TString( prefix ) + "trig_EF_el_pz" );
      trig_EF_trigmuonef_track_CB_pt.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_pt" );
      trig_EF_trigmuonef_track_CB_eta.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_eta" );
      trig_EF_trigmuonef_track_CB_phi.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_phi" );
      trig_EF_trigmuonef_track_CB_hasCB.SetName( ::TString( prefix ) + "trig_EF_trigmuonef_track_CB_hasCB" );
      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void TriggerVecD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      trig_EF_el_EF_e12Tvh_loose1.ReadFrom( tree );
      trig_EF_el_EF_e12Tvh_medium1.ReadFrom( tree );
      trig_EF_el_EF_e24vh_medium1.ReadFrom( tree );
      trig_EF_el_EF_e24vh_medium1_e7_medium1.ReadFrom( tree );
      trig_EF_el_EF_e7T_medium1.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu13.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu18_tight.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS.ReadFrom( tree );
      trig_EF_trigmuonef_EF_mu8.ReadFrom( tree );
      trig_EF_el_E.ReadFrom( tree );
      trig_EF_el_px.ReadFrom( tree );
      trig_EF_el_py.ReadFrom( tree );
      trig_EF_el_pz.ReadFrom( tree );
      trig_EF_trigmuonef_track_CB_pt.ReadFrom( tree );
      trig_EF_trigmuonef_track_CB_eta.ReadFrom( tree );
      trig_EF_trigmuonef_track_CB_phi.ReadFrom( tree );
      trig_EF_trigmuonef_track_CB_hasCB.ReadFrom( tree );

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void TriggerVecD3PDObject::WriteTo( TTree* tree ) {

      trig_EF_el_EF_e12Tvh_loose1.WriteTo( tree );
      trig_EF_el_EF_e12Tvh_medium1.WriteTo( tree );
      trig_EF_el_EF_e24vh_medium1.WriteTo( tree );
      trig_EF_el_EF_e24vh_medium1_e7_medium1.WriteTo( tree );
      trig_EF_el_EF_e7T_medium1.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu13.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu18_tight.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS.WriteTo( tree );
      trig_EF_trigmuonef_EF_mu8.WriteTo( tree );
      trig_EF_el_E.WriteTo( tree );
      trig_EF_el_px.WriteTo( tree );
      trig_EF_el_py.WriteTo( tree );
      trig_EF_el_pz.WriteTo( tree );
      trig_EF_trigmuonef_track_CB_pt.WriteTo( tree );
      trig_EF_trigmuonef_track_CB_eta.WriteTo( tree );
      trig_EF_trigmuonef_track_CB_phi.WriteTo( tree );
      trig_EF_trigmuonef_track_CB_hasCB.WriteTo( tree );

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
   void TriggerVecD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void TriggerVecD3PDObject::ReadAllActive() {

      // Check if it makes sense to call this function:
      if( ! fFromInput ) {
         static ::Bool_t wPrinted = kFALSE;
         if( ! wPrinted ) {
            Warning( "ReadAllActive", "Function only meaningful when used on objects" );
            Warning( "ReadAllActive", "which are used to read information from a D3PD" );
            wPrinted = kTRUE;
         }
      }

      if( trig_EF_el_EF_e12Tvh_loose1.IsActive() ) trig_EF_el_EF_e12Tvh_loose1();
      if( trig_EF_el_EF_e12Tvh_medium1.IsActive() ) trig_EF_el_EF_e12Tvh_medium1();
      if( trig_EF_el_EF_e24vh_medium1.IsActive() ) trig_EF_el_EF_e24vh_medium1();
      if( trig_EF_el_EF_e24vh_medium1_e7_medium1.IsActive() ) trig_EF_el_EF_e24vh_medium1_e7_medium1();
      if( trig_EF_el_EF_e7T_medium1.IsActive() ) trig_EF_el_EF_e7T_medium1();
      if( trig_EF_trigmuonef_EF_mu13.IsActive() ) trig_EF_trigmuonef_EF_mu13();
      if( trig_EF_trigmuonef_EF_mu18_tight.IsActive() ) trig_EF_trigmuonef_EF_mu18_tight();
      if( trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS.IsActive() ) trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS();
      if( trig_EF_trigmuonef_EF_mu8.IsActive() ) trig_EF_trigmuonef_EF_mu8();
      if( trig_EF_el_E.IsActive() ) trig_EF_el_E();
      if( trig_EF_el_px.IsActive() ) trig_EF_el_px();
      if( trig_EF_el_py.IsActive() ) trig_EF_el_py();
      if( trig_EF_el_pz.IsActive() ) trig_EF_el_pz();
      if( trig_EF_trigmuonef_track_CB_pt.IsActive() ) trig_EF_trigmuonef_track_CB_pt();
      if( trig_EF_trigmuonef_track_CB_eta.IsActive() ) trig_EF_trigmuonef_track_CB_eta();
      if( trig_EF_trigmuonef_track_CB_phi.IsActive() ) trig_EF_trigmuonef_track_CB_phi();
      if( trig_EF_trigmuonef_track_CB_hasCB.IsActive() ) trig_EF_trigmuonef_track_CB_hasCB();

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
   void TriggerVecD3PDObject::Clear( Option_t* ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Clear", "Objects used for reading a D3PD can't be cleared!" );
         return;
      }

      trig_EF_el_EF_e12Tvh_loose1()->clear();
      trig_EF_el_EF_e12Tvh_medium1()->clear();
      trig_EF_el_EF_e24vh_medium1()->clear();
      trig_EF_el_EF_e24vh_medium1_e7_medium1()->clear();
      trig_EF_el_EF_e7T_medium1()->clear();
      trig_EF_trigmuonef_EF_mu13()->clear();
      trig_EF_trigmuonef_EF_mu18_tight()->clear();
      trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS()->clear();
      trig_EF_trigmuonef_EF_mu8()->clear();
      trig_EF_el_E()->clear();
      trig_EF_el_px()->clear();
      trig_EF_el_py()->clear();
      trig_EF_el_pz()->clear();
      trig_EF_trigmuonef_track_CB_pt()->clear();
      trig_EF_trigmuonef_track_CB_eta()->clear();
      trig_EF_trigmuonef_track_CB_phi()->clear();
      trig_EF_trigmuonef_track_CB_hasCB()->clear();

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
   TriggerVecD3PDObject& TriggerVecD3PDObject::Add( const TriggerVecD3PDObjectElement& el ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Add", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      if( el.trig_EF_el_EF_e12Tvh_loose1.IsAvailable() ) {
         trig_EF_el_EF_e12Tvh_loose1()->push_back( el.trig_EF_el_EF_e12Tvh_loose1() );
      } else {
         trig_EF_el_EF_e12Tvh_loose1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e12Tvh_medium1.IsAvailable() ) {
         trig_EF_el_EF_e12Tvh_medium1()->push_back( el.trig_EF_el_EF_e12Tvh_medium1() );
      } else {
         trig_EF_el_EF_e12Tvh_medium1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_medium1.IsAvailable() ) {
         trig_EF_el_EF_e24vh_medium1()->push_back( el.trig_EF_el_EF_e24vh_medium1() );
      } else {
         trig_EF_el_EF_e24vh_medium1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e24vh_medium1_e7_medium1.IsAvailable() ) {
         trig_EF_el_EF_e24vh_medium1_e7_medium1()->push_back( el.trig_EF_el_EF_e24vh_medium1_e7_medium1() );
      } else {
         trig_EF_el_EF_e24vh_medium1_e7_medium1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_EF_e7T_medium1.IsAvailable() ) {
         trig_EF_el_EF_e7T_medium1()->push_back( el.trig_EF_el_EF_e7T_medium1() );
      } else {
         trig_EF_el_EF_e7T_medium1()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu13.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu13()->push_back( el.trig_EF_trigmuonef_EF_mu13() );
      } else {
         trig_EF_trigmuonef_EF_mu13()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu18_tight.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu18_tight()->push_back( el.trig_EF_trigmuonef_EF_mu18_tight() );
      } else {
         trig_EF_trigmuonef_EF_mu18_tight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS()->push_back( el.trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS() );
      } else {
         trig_EF_trigmuonef_EF_mu18_tight_mu8_EFFS()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_trigmuonef_EF_mu8.IsAvailable() ) {
         trig_EF_trigmuonef_EF_mu8()->push_back( el.trig_EF_trigmuonef_EF_mu8() );
      } else {
         trig_EF_trigmuonef_EF_mu8()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.trig_EF_el_E.IsAvailable() ) {
         trig_EF_el_E()->push_back( el.trig_EF_el_E() );
      } else {
         trig_EF_el_E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_el_px.IsAvailable() ) {
         trig_EF_el_px()->push_back( el.trig_EF_el_px() );
      } else {
         trig_EF_el_px()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_el_py.IsAvailable() ) {
         trig_EF_el_py()->push_back( el.trig_EF_el_py() );
      } else {
         trig_EF_el_py()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_el_pz.IsAvailable() ) {
         trig_EF_el_pz()->push_back( el.trig_EF_el_pz() );
      } else {
         trig_EF_el_pz()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.trig_EF_trigmuonef_track_CB_pt.IsAvailable() ) {
         trig_EF_trigmuonef_track_CB_pt()->push_back( el.trig_EF_trigmuonef_track_CB_pt() );
      } else {
         trig_EF_trigmuonef_track_CB_pt()->push_back( vector<float>() );
      }
      if( el.trig_EF_trigmuonef_track_CB_eta.IsAvailable() ) {
         trig_EF_trigmuonef_track_CB_eta()->push_back( el.trig_EF_trigmuonef_track_CB_eta() );
      } else {
         trig_EF_trigmuonef_track_CB_eta()->push_back( vector<float>() );
      }
      if( el.trig_EF_trigmuonef_track_CB_phi.IsAvailable() ) {
         trig_EF_trigmuonef_track_CB_phi()->push_back( el.trig_EF_trigmuonef_track_CB_phi() );
      } else {
         trig_EF_trigmuonef_track_CB_phi()->push_back( vector<float>() );
      }
      if( el.trig_EF_trigmuonef_track_CB_hasCB.IsAvailable() ) {
         trig_EF_trigmuonef_track_CB_hasCB()->push_back( el.trig_EF_trigmuonef_track_CB_hasCB() );
      } else {
         trig_EF_trigmuonef_track_CB_hasCB()->push_back( vector<int>() );
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
   TriggerVecD3PDObjectElement& TriggerVecD3PDObject::operator[]( size_t index ) {

      while( fProxies.size() <= index ) {
         fProxies.push_back( TriggerVecD3PDObjectElement( fProxies.size(), *this , is_data ) );
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
   const TriggerVecD3PDObjectElement& TriggerVecD3PDObject::operator[]( size_t index ) const {

      while( fProxies.size() <= index ) {
         fProxies.push_back( TriggerVecD3PDObjectElement( fProxies.size(), *this , is_data ) );
      }
      return fProxies[ index ];
   }

   /**
    * A convenience operator for adding an 'element' to this collection.
    *
    * @see Add
    * @param el The 'element' that should be added to the collection
    */
   TriggerVecD3PDObject& TriggerVecD3PDObject::operator+=( const TriggerVecD3PDObjectElement& el ) {

      return this->Add( el );
   }

} // namespace D3PDReader
