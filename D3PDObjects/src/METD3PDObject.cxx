// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <TPRegexp.h>

#include "../include/METD3PDObject.h"

ClassImp( D3PDReader::METD3PDObject )

namespace D3PDReader {

   /**
    * This constructor should be used when the object will be used to read
    * variables from an existing ntuple. The object will also be able to
    * output variables, but it will also need to read them from somewhere.
    *
    * @param master Reference to the variable holding the current event number
    * @param prefix Prefix of the variables in the D3PD
    */
   METD3PDObject::METD3PDObject( const ::Long64_t& master, const char* prefix , bool is_data )
      : TObject(),
        RefGamma_etx( this, ::TString( prefix ) + "RefGamma_etx", &master ),
        RefGamma_ety( this, ::TString( prefix ) + "RefGamma_ety", &master ),
        RefGamma_sumet( this, ::TString( prefix ) + "RefGamma_sumet", &master ),
        RefJet_etx( this, ::TString( prefix ) + "RefJet_etx", &master ),
        RefJet_ety( this, ::TString( prefix ) + "RefJet_ety", &master ),
        RefJet_sumet( this, ::TString( prefix ) + "RefJet_sumet", &master ),
        RefEle_etx( this, ::TString( prefix ) + "RefEle_etx", &master ),
        RefEle_ety( this, ::TString( prefix ) + "RefEle_ety", &master ),
        RefEle_sumet( this, ::TString( prefix ) + "RefEle_sumet", &master ),
        CellOut_etx( this, ::TString( prefix ) + "CellOut_etx", &master ),
        CellOut_ety( this, ::TString( prefix ) + "CellOut_ety", &master ),
        CellOut_sumet( this, ::TString( prefix ) + "CellOut_sumet", &master ),
        Track_etx( this, ::TString( prefix ) + "Track_etx", &master ),
        Track_ety( this, ::TString( prefix ) + "Track_ety", &master ),
        Track_sumet( this, ::TString( prefix ) + "Track_sumet", &master ),
        SoftJets_etx( this, ::TString( prefix ) + "SoftJets_etx", &master ),
        SoftJets_ety( this, ::TString( prefix ) + "SoftJets_ety", &master ),
        SoftJets_sumet( this, ::TString( prefix ) + "SoftJets_sumet", &master ),
        RefMuon_etx( this, ::TString( prefix ) + "RefMuon_etx", &master ),
        RefMuon_ety( this, ::TString( prefix ) + "RefMuon_ety", &master ),
        RefMuon_sumet( this, ::TString( prefix ) + "RefMuon_sumet", &master ),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ), 
is_data(is_data) {

      fHandles[ "RefGamma_etx" ] = &RefGamma_etx;
      fHandles[ "RefGamma_ety" ] = &RefGamma_ety;
      fHandles[ "RefGamma_sumet" ] = &RefGamma_sumet;
      fHandles[ "RefJet_etx" ] = &RefJet_etx;
      fHandles[ "RefJet_ety" ] = &RefJet_ety;
      fHandles[ "RefJet_sumet" ] = &RefJet_sumet;
      fHandles[ "RefEle_etx" ] = &RefEle_etx;
      fHandles[ "RefEle_ety" ] = &RefEle_ety;
      fHandles[ "RefEle_sumet" ] = &RefEle_sumet;
      fHandles[ "CellOut_etx" ] = &CellOut_etx;
      fHandles[ "CellOut_ety" ] = &CellOut_ety;
      fHandles[ "CellOut_sumet" ] = &CellOut_sumet;
      fHandles[ "Track_etx" ] = &Track_etx;
      fHandles[ "Track_ety" ] = &Track_ety;
      fHandles[ "Track_sumet" ] = &Track_sumet;
      fHandles[ "SoftJets_etx" ] = &SoftJets_etx;
      fHandles[ "SoftJets_ety" ] = &SoftJets_ety;
      fHandles[ "SoftJets_sumet" ] = &SoftJets_sumet;
      fHandles[ "RefMuon_etx" ] = &RefMuon_etx;
      fHandles[ "RefMuon_ety" ] = &RefMuon_ety;
      fHandles[ "RefMuon_sumet" ] = &RefMuon_sumet;
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   METD3PDObject::METD3PDObject( const char* prefix , bool is_data )
      : TObject(),
        RefGamma_etx( this, ::TString( prefix ) + "RefGamma_etx", 0 ),
        RefGamma_ety( this, ::TString( prefix ) + "RefGamma_ety", 0 ),
        RefGamma_sumet( this, ::TString( prefix ) + "RefGamma_sumet", 0 ),
        RefJet_etx( this, ::TString( prefix ) + "RefJet_etx", 0 ),
        RefJet_ety( this, ::TString( prefix ) + "RefJet_ety", 0 ),
        RefJet_sumet( this, ::TString( prefix ) + "RefJet_sumet", 0 ),
        RefEle_etx( this, ::TString( prefix ) + "RefEle_etx", 0 ),
        RefEle_ety( this, ::TString( prefix ) + "RefEle_ety", 0 ),
        RefEle_sumet( this, ::TString( prefix ) + "RefEle_sumet", 0 ),
        CellOut_etx( this, ::TString( prefix ) + "CellOut_etx", 0 ),
        CellOut_ety( this, ::TString( prefix ) + "CellOut_ety", 0 ),
        CellOut_sumet( this, ::TString( prefix ) + "CellOut_sumet", 0 ),
        Track_etx( this, ::TString( prefix ) + "Track_etx", 0 ),
        Track_ety( this, ::TString( prefix ) + "Track_ety", 0 ),
        Track_sumet( this, ::TString( prefix ) + "Track_sumet", 0 ),
        SoftJets_etx( this, ::TString( prefix ) + "SoftJets_etx", 0 ),
        SoftJets_ety( this, ::TString( prefix ) + "SoftJets_ety", 0 ),
        SoftJets_sumet( this, ::TString( prefix ) + "SoftJets_sumet", 0 ),
        RefMuon_etx( this, ::TString( prefix ) + "RefMuon_etx", 0 ),
        RefMuon_ety( this, ::TString( prefix ) + "RefMuon_ety", 0 ),
        RefMuon_sumet( this, ::TString( prefix ) + "RefMuon_sumet", 0 ),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ), 
is_data(is_data) {

      fHandles[ "RefGamma_etx" ] = &RefGamma_etx;
      fHandles[ "RefGamma_ety" ] = &RefGamma_ety;
      fHandles[ "RefGamma_sumet" ] = &RefGamma_sumet;
      fHandles[ "RefJet_etx" ] = &RefJet_etx;
      fHandles[ "RefJet_ety" ] = &RefJet_ety;
      fHandles[ "RefJet_sumet" ] = &RefJet_sumet;
      fHandles[ "RefEle_etx" ] = &RefEle_etx;
      fHandles[ "RefEle_ety" ] = &RefEle_ety;
      fHandles[ "RefEle_sumet" ] = &RefEle_sumet;
      fHandles[ "CellOut_etx" ] = &CellOut_etx;
      fHandles[ "CellOut_ety" ] = &CellOut_ety;
      fHandles[ "CellOut_sumet" ] = &CellOut_sumet;
      fHandles[ "Track_etx" ] = &Track_etx;
      fHandles[ "Track_ety" ] = &Track_ety;
      fHandles[ "Track_sumet" ] = &Track_sumet;
      fHandles[ "SoftJets_etx" ] = &SoftJets_etx;
      fHandles[ "SoftJets_ety" ] = &SoftJets_ety;
      fHandles[ "SoftJets_sumet" ] = &SoftJets_sumet;
      fHandles[ "RefMuon_etx" ] = &RefMuon_etx;
      fHandles[ "RefMuon_ety" ] = &RefMuon_ety;
      fHandles[ "RefMuon_sumet" ] = &RefMuon_sumet;
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* METD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void METD3PDObject::SetPrefix( const char* prefix ) {

      RefGamma_etx.SetName( ::TString( prefix ) + "RefGamma_etx" );
      RefGamma_ety.SetName( ::TString( prefix ) + "RefGamma_ety" );
      RefGamma_sumet.SetName( ::TString( prefix ) + "RefGamma_sumet" );
      RefJet_etx.SetName( ::TString( prefix ) + "RefJet_etx" );
      RefJet_ety.SetName( ::TString( prefix ) + "RefJet_ety" );
      RefJet_sumet.SetName( ::TString( prefix ) + "RefJet_sumet" );
      RefEle_etx.SetName( ::TString( prefix ) + "RefEle_etx" );
      RefEle_ety.SetName( ::TString( prefix ) + "RefEle_ety" );
      RefEle_sumet.SetName( ::TString( prefix ) + "RefEle_sumet" );
      CellOut_etx.SetName( ::TString( prefix ) + "CellOut_etx" );
      CellOut_ety.SetName( ::TString( prefix ) + "CellOut_ety" );
      CellOut_sumet.SetName( ::TString( prefix ) + "CellOut_sumet" );
      Track_etx.SetName( ::TString( prefix ) + "Track_etx" );
      Track_ety.SetName( ::TString( prefix ) + "Track_ety" );
      Track_sumet.SetName( ::TString( prefix ) + "Track_sumet" );
      SoftJets_etx.SetName( ::TString( prefix ) + "SoftJets_etx" );
      SoftJets_ety.SetName( ::TString( prefix ) + "SoftJets_ety" );
      SoftJets_sumet.SetName( ::TString( prefix ) + "SoftJets_sumet" );
      RefMuon_etx.SetName( ::TString( prefix ) + "RefMuon_etx" );
      RefMuon_ety.SetName( ::TString( prefix ) + "RefMuon_ety" );
      RefMuon_sumet.SetName( ::TString( prefix ) + "RefMuon_sumet" );
      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void METD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      RefGamma_etx.ReadFrom( tree );
      RefGamma_ety.ReadFrom( tree );
      RefGamma_sumet.ReadFrom( tree );
      RefJet_etx.ReadFrom( tree );
      RefJet_ety.ReadFrom( tree );
      RefJet_sumet.ReadFrom( tree );
      RefEle_etx.ReadFrom( tree );
      RefEle_ety.ReadFrom( tree );
      RefEle_sumet.ReadFrom( tree );
      CellOut_etx.ReadFrom( tree );
      CellOut_ety.ReadFrom( tree );
      CellOut_sumet.ReadFrom( tree );
      Track_etx.ReadFrom( tree );
      Track_ety.ReadFrom( tree );
      Track_sumet.ReadFrom( tree );
      SoftJets_etx.ReadFrom( tree );
      SoftJets_ety.ReadFrom( tree );
      SoftJets_sumet.ReadFrom( tree );
      RefMuon_etx.ReadFrom( tree );
      RefMuon_ety.ReadFrom( tree );
      RefMuon_sumet.ReadFrom( tree );

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void METD3PDObject::WriteTo( TTree* tree ) {

      RefGamma_etx.WriteTo( tree );
      RefGamma_ety.WriteTo( tree );
      RefGamma_sumet.WriteTo( tree );
      RefJet_etx.WriteTo( tree );
      RefJet_ety.WriteTo( tree );
      RefJet_sumet.WriteTo( tree );
      RefEle_etx.WriteTo( tree );
      RefEle_ety.WriteTo( tree );
      RefEle_sumet.WriteTo( tree );
      CellOut_etx.WriteTo( tree );
      CellOut_ety.WriteTo( tree );
      CellOut_sumet.WriteTo( tree );
      Track_etx.WriteTo( tree );
      Track_ety.WriteTo( tree );
      Track_sumet.WriteTo( tree );
      SoftJets_etx.WriteTo( tree );
      SoftJets_ety.WriteTo( tree );
      SoftJets_sumet.WriteTo( tree );
      RefMuon_etx.WriteTo( tree );
      RefMuon_ety.WriteTo( tree );
      RefMuon_sumet.WriteTo( tree );

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
   void METD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void METD3PDObject::ReadAllActive() {

      // Check if it makes sense to call this function:
      if( ! fFromInput ) {
         static ::Bool_t wPrinted = kFALSE;
         if( ! wPrinted ) {
            Warning( "ReadAllActive", "Function only meaningful when used on objects" );
            Warning( "ReadAllActive", "which are used to read information from a D3PD" );
            wPrinted = kTRUE;
         }
      }

      if( RefGamma_etx.IsActive() ) RefGamma_etx();
      if( RefGamma_ety.IsActive() ) RefGamma_ety();
      if( RefGamma_sumet.IsActive() ) RefGamma_sumet();
      if( RefJet_etx.IsActive() ) RefJet_etx();
      if( RefJet_ety.IsActive() ) RefJet_ety();
      if( RefJet_sumet.IsActive() ) RefJet_sumet();
      if( RefEle_etx.IsActive() ) RefEle_etx();
      if( RefEle_ety.IsActive() ) RefEle_ety();
      if( RefEle_sumet.IsActive() ) RefEle_sumet();
      if( CellOut_etx.IsActive() ) CellOut_etx();
      if( CellOut_ety.IsActive() ) CellOut_ety();
      if( CellOut_sumet.IsActive() ) CellOut_sumet();
      if( Track_etx.IsActive() ) Track_etx();
      if( Track_ety.IsActive() ) Track_ety();
      if( Track_sumet.IsActive() ) Track_sumet();
      if( SoftJets_etx.IsActive() ) SoftJets_etx();
      if( SoftJets_ety.IsActive() ) SoftJets_ety();
      if( SoftJets_sumet.IsActive() ) SoftJets_sumet();
      if( RefMuon_etx.IsActive() ) RefMuon_etx();
      if( RefMuon_ety.IsActive() ) RefMuon_ety();
      if( RefMuon_sumet.IsActive() ) RefMuon_sumet();

      return;
   }

} // namespace D3PDReader
