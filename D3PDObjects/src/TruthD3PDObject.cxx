// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <TPRegexp.h>

#include "../include/TruthD3PDObject.h"

ClassImp( D3PDReader::TruthD3PDObject )

namespace D3PDReader {

   /**
    * This constructor should be used when the object will be used to read
    * variables from an existing ntuple. The object will also be able to
    * output variables, but it will also need to read them from somewhere.
    *
    * @param master Reference to the variable holding the current event number
    * @param prefix Prefix of the variables in the D3PD
    */
   TruthD3PDObject::TruthD3PDObject( const ::Long64_t& master, const char* prefix )
      : TObject(),
        actualIntPerXing( this, ::TString( prefix ) + "actualIntPerXing", &master ),
        averageIntPerXing( this, ::TString( prefix ) + "averageIntPerXing", &master ),
        mc_channel_number( this, ::TString( prefix ) + "mc_channel_number", &master ),
        mc_event_number( this, ::TString( prefix ) + "mc_event_number", &master ),
        mc_event_weight( this, ::TString( prefix ) + "mc_event_weight", &master ),
        mc_n( this, ::TString( prefix ) + "mc_n", &master ),
        mc_pt( this, ::TString( prefix ) + "mc_pt", &master ),
        mc_m( this, ::TString( prefix ) + "mc_m", &master ),
        mc_eta( this, ::TString( prefix ) + "mc_eta", &master ),
        mc_phi( this, ::TString( prefix ) + "mc_phi", &master ),
        mc_status( this, ::TString( prefix ) + "mc_status", &master ),
        mc_barcode( this, ::TString( prefix ) + "mc_barcode", &master ),
        mc_pdgId( this, ::TString( prefix ) + "mc_pdgId", &master ),
        mc_charge( this, ::TString( prefix ) + "mc_charge", &master ),
        mc_parents( this, ::TString( prefix ) + "mc_parents", &master ),
        mc_children( this, ::TString( prefix ) + "mc_children", &master ),
        mc_vx_x( this, ::TString( prefix ) + "mc_vx_x", &master ),
        mc_vx_y( this, ::TString( prefix ) + "mc_vx_y", &master ),
        mc_vx_z( this, ::TString( prefix ) + "mc_vx_z", &master ),
        mc_vx_barcode( this, ::TString( prefix ) + "mc_vx_barcode", &master ),
        mc_child_index( this, ::TString( prefix ) + "mc_child_index", &master ),
        mc_parent_index( this, ::TString( prefix ) + "mc_parent_index", &master ),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) {

      fHandles[ "actualIntPerXing" ] = &actualIntPerXing;
      fHandles[ "averageIntPerXing" ] = &averageIntPerXing;
      fHandles[ "mc_channel_number" ] = &mc_channel_number;
      fHandles[ "mc_event_number" ] = &mc_event_number;
      fHandles[ "mc_event_weight" ] = &mc_event_weight;
      fHandles[ "mc_n" ] = &mc_n;
      fHandles[ "mc_pt" ] = &mc_pt;
      fHandles[ "mc_m" ] = &mc_m;
      fHandles[ "mc_eta" ] = &mc_eta;
      fHandles[ "mc_phi" ] = &mc_phi;
      fHandles[ "mc_status" ] = &mc_status;
      fHandles[ "mc_barcode" ] = &mc_barcode;
      fHandles[ "mc_pdgId" ] = &mc_pdgId;
      fHandles[ "mc_charge" ] = &mc_charge;
      fHandles[ "mc_parents" ] = &mc_parents;
      fHandles[ "mc_children" ] = &mc_children;
      fHandles[ "mc_vx_x" ] = &mc_vx_x;
      fHandles[ "mc_vx_y" ] = &mc_vx_y;
      fHandles[ "mc_vx_z" ] = &mc_vx_z;
      fHandles[ "mc_vx_barcode" ] = &mc_vx_barcode;
      fHandles[ "mc_child_index" ] = &mc_child_index;
      fHandles[ "mc_parent_index" ] = &mc_parent_index;
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   TruthD3PDObject::TruthD3PDObject( const char* prefix )
      : TObject(),
        actualIntPerXing( this, ::TString( prefix ) + "actualIntPerXing", 0 ),
        averageIntPerXing( this, ::TString( prefix ) + "averageIntPerXing", 0 ),
        mc_channel_number( this, ::TString( prefix ) + "mc_channel_number", 0 ),
        mc_event_number( this, ::TString( prefix ) + "mc_event_number", 0 ),
        mc_event_weight( this, ::TString( prefix ) + "mc_event_weight", 0 ),
        mc_n( this, ::TString( prefix ) + "mc_n", 0 ),
        mc_pt( this, ::TString( prefix ) + "mc_pt", 0 ),
        mc_m( this, ::TString( prefix ) + "mc_m", 0 ),
        mc_eta( this, ::TString( prefix ) + "mc_eta", 0 ),
        mc_phi( this, ::TString( prefix ) + "mc_phi", 0 ),
        mc_status( this, ::TString( prefix ) + "mc_status", 0 ),
        mc_barcode( this, ::TString( prefix ) + "mc_barcode", 0 ),
        mc_pdgId( this, ::TString( prefix ) + "mc_pdgId", 0 ),
        mc_charge( this, ::TString( prefix ) + "mc_charge", 0 ),
        mc_parents( this, ::TString( prefix ) + "mc_parents", 0 ),
        mc_children( this, ::TString( prefix ) + "mc_children", 0 ),
        mc_vx_x( this, ::TString( prefix ) + "mc_vx_x", 0 ),
        mc_vx_y( this, ::TString( prefix ) + "mc_vx_y", 0 ),
        mc_vx_z( this, ::TString( prefix ) + "mc_vx_z", 0 ),
        mc_vx_barcode( this, ::TString( prefix ) + "mc_vx_barcode", 0 ),
        mc_child_index( this, ::TString( prefix ) + "mc_child_index", 0 ),
        mc_parent_index( this, ::TString( prefix ) + "mc_parent_index", 0 ),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) {

      fHandles[ "actualIntPerXing" ] = &actualIntPerXing;
      fHandles[ "averageIntPerXing" ] = &averageIntPerXing;
      fHandles[ "mc_channel_number" ] = &mc_channel_number;
      fHandles[ "mc_event_number" ] = &mc_event_number;
      fHandles[ "mc_event_weight" ] = &mc_event_weight;
      fHandles[ "mc_n" ] = &mc_n;
      fHandles[ "mc_pt" ] = &mc_pt;
      fHandles[ "mc_m" ] = &mc_m;
      fHandles[ "mc_eta" ] = &mc_eta;
      fHandles[ "mc_phi" ] = &mc_phi;
      fHandles[ "mc_status" ] = &mc_status;
      fHandles[ "mc_barcode" ] = &mc_barcode;
      fHandles[ "mc_pdgId" ] = &mc_pdgId;
      fHandles[ "mc_charge" ] = &mc_charge;
      fHandles[ "mc_parents" ] = &mc_parents;
      fHandles[ "mc_children" ] = &mc_children;
      fHandles[ "mc_vx_x" ] = &mc_vx_x;
      fHandles[ "mc_vx_y" ] = &mc_vx_y;
      fHandles[ "mc_vx_z" ] = &mc_vx_z;
      fHandles[ "mc_vx_barcode" ] = &mc_vx_barcode;
      fHandles[ "mc_child_index" ] = &mc_child_index;
      fHandles[ "mc_parent_index" ] = &mc_parent_index;
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* TruthD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void TruthD3PDObject::SetPrefix( const char* prefix ) {

      actualIntPerXing.SetName( ::TString( prefix ) + "actualIntPerXing" );
      averageIntPerXing.SetName( ::TString( prefix ) + "averageIntPerXing" );
      mc_channel_number.SetName( ::TString( prefix ) + "mc_channel_number" );
      mc_event_number.SetName( ::TString( prefix ) + "mc_event_number" );
      mc_event_weight.SetName( ::TString( prefix ) + "mc_event_weight" );
      mc_n.SetName( ::TString( prefix ) + "mc_n" );
      mc_pt.SetName( ::TString( prefix ) + "mc_pt" );
      mc_m.SetName( ::TString( prefix ) + "mc_m" );
      mc_eta.SetName( ::TString( prefix ) + "mc_eta" );
      mc_phi.SetName( ::TString( prefix ) + "mc_phi" );
      mc_status.SetName( ::TString( prefix ) + "mc_status" );
      mc_barcode.SetName( ::TString( prefix ) + "mc_barcode" );
      mc_pdgId.SetName( ::TString( prefix ) + "mc_pdgId" );
      mc_charge.SetName( ::TString( prefix ) + "mc_charge" );
      mc_parents.SetName( ::TString( prefix ) + "mc_parents" );
      mc_children.SetName( ::TString( prefix ) + "mc_children" );
      mc_vx_x.SetName( ::TString( prefix ) + "mc_vx_x" );
      mc_vx_y.SetName( ::TString( prefix ) + "mc_vx_y" );
      mc_vx_z.SetName( ::TString( prefix ) + "mc_vx_z" );
      mc_vx_barcode.SetName( ::TString( prefix ) + "mc_vx_barcode" );
      mc_child_index.SetName( ::TString( prefix ) + "mc_child_index" );
      mc_parent_index.SetName( ::TString( prefix ) + "mc_parent_index" );
      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void TruthD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      actualIntPerXing.ReadFrom( tree );
      averageIntPerXing.ReadFrom( tree );
      mc_channel_number.ReadFrom( tree );
      mc_event_number.ReadFrom( tree );
      mc_event_weight.ReadFrom( tree );
      mc_n.ReadFrom( tree );
      mc_pt.ReadFrom( tree );
      mc_m.ReadFrom( tree );
      mc_eta.ReadFrom( tree );
      mc_phi.ReadFrom( tree );
      mc_status.ReadFrom( tree );
      mc_barcode.ReadFrom( tree );
      mc_pdgId.ReadFrom( tree );
      mc_charge.ReadFrom( tree );
      mc_parents.ReadFrom( tree );
      mc_children.ReadFrom( tree );
      mc_vx_x.ReadFrom( tree );
      mc_vx_y.ReadFrom( tree );
      mc_vx_z.ReadFrom( tree );
      mc_vx_barcode.ReadFrom( tree );
      mc_child_index.ReadFrom( tree );
      mc_parent_index.ReadFrom( tree );

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void TruthD3PDObject::WriteTo( TTree* tree ) {

      actualIntPerXing.WriteTo( tree );
      averageIntPerXing.WriteTo( tree );
      mc_channel_number.WriteTo( tree );
      mc_event_number.WriteTo( tree );
      mc_event_weight.WriteTo( tree );
      mc_n.WriteTo( tree );
      mc_pt.WriteTo( tree );
      mc_m.WriteTo( tree );
      mc_eta.WriteTo( tree );
      mc_phi.WriteTo( tree );
      mc_status.WriteTo( tree );
      mc_barcode.WriteTo( tree );
      mc_pdgId.WriteTo( tree );
      mc_charge.WriteTo( tree );
      mc_parents.WriteTo( tree );
      mc_children.WriteTo( tree );
      mc_vx_x.WriteTo( tree );
      mc_vx_y.WriteTo( tree );
      mc_vx_z.WriteTo( tree );
      mc_vx_barcode.WriteTo( tree );
      mc_child_index.WriteTo( tree );
      mc_parent_index.WriteTo( tree );

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
   void TruthD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void TruthD3PDObject::ReadAllActive() {

      // Check if it makes sense to call this function:
      if( ! fFromInput ) {
         static ::Bool_t wPrinted = kFALSE;
         if( ! wPrinted ) {
            Warning( "ReadAllActive", "Function only meaningful when used on objects" );
            Warning( "ReadAllActive", "which are used to read information from a D3PD" );
            wPrinted = kTRUE;
         }
      }

      if( actualIntPerXing.IsActive() ) actualIntPerXing();
      if( averageIntPerXing.IsActive() ) averageIntPerXing();
      if( mc_channel_number.IsActive() ) mc_channel_number();
      if( mc_event_number.IsActive() ) mc_event_number();
      if( mc_event_weight.IsActive() ) mc_event_weight();
      if( mc_n.IsActive() ) mc_n();
      if( mc_pt.IsActive() ) mc_pt();
      if( mc_m.IsActive() ) mc_m();
      if( mc_eta.IsActive() ) mc_eta();
      if( mc_phi.IsActive() ) mc_phi();
      if( mc_status.IsActive() ) mc_status();
      if( mc_barcode.IsActive() ) mc_barcode();
      if( mc_pdgId.IsActive() ) mc_pdgId();
      if( mc_charge.IsActive() ) mc_charge();
      if( mc_parents.IsActive() ) mc_parents();
      if( mc_children.IsActive() ) mc_children();
      if( mc_vx_x.IsActive() ) mc_vx_x();
      if( mc_vx_y.IsActive() ) mc_vx_y();
      if( mc_vx_z.IsActive() ) mc_vx_z();
      if( mc_vx_barcode.IsActive() ) mc_vx_barcode();
      if( mc_child_index.IsActive() ) mc_child_index();
      if( mc_parent_index.IsActive() ) mc_parent_index();

      return;
   }

} // namespace D3PDReader
