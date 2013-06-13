// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <limits>

#include <TPRegexp.h>

#include "../include/TauD3PDObject.h"

ClassImp( D3PDReader::TauD3PDObjectElement )
ClassImp( D3PDReader::TauD3PDObject )

namespace D3PDReader {

   /**
    * This constructor can be used to create new proxy objects from scratch.
    * Since the constructor of such an object is quite complicated and
    * error prone, it is only visible to the parent class TauD3PDObject.
    */
   TauD3PDObjectElement::TauD3PDObjectElement( size_t index, const TauD3PDObject& parent , bool is_data )
      : pt( parent.pt, index, this ),
        m( parent.m, index, this ),
        eta( parent.eta, index, this ),
        phi( parent.phi, index, this ),
        charge( parent.charge, index, this ),
        BDTEleScore( parent.BDTEleScore, index, this ),
        BDTJetScore( parent.BDTJetScore, index, this ),
        muonVeto( parent.muonVeto, index, this ),
        JetBDTSigLoose( parent.JetBDTSigLoose, index, this ),
        JetBDTSigMedium( parent.JetBDTSigMedium, index, this ),
        JetBDTSigTight( parent.JetBDTSigTight, index, this ),
        EleBDTLoose( parent.EleBDTLoose, index, this ),
        EleBDTMedium( parent.EleBDTMedium, index, this ),
        EleBDTTight( parent.EleBDTTight, index, this ),
        numTrack( parent.numTrack, index, this ),
        leadTrkPt( parent.leadTrkPt, index, this ),
        leadTrack_eta( parent.leadTrack_eta, index, this ),
        leadTrack_phi( parent.leadTrack_phi, index, this ) , 
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
   TauD3PDObjectElement::TauD3PDObjectElement( const TauD3PDObjectElement& parent , bool is_data )
      : TObject( parent ),
        pt( parent.pt ),
        m( parent.m ),
        eta( parent.eta ),
        phi( parent.phi ),
        charge( parent.charge ),
        BDTEleScore( parent.BDTEleScore ),
        BDTJetScore( parent.BDTJetScore ),
        muonVeto( parent.muonVeto ),
        JetBDTSigLoose( parent.JetBDTSigLoose ),
        JetBDTSigMedium( parent.JetBDTSigMedium ),
        JetBDTSigTight( parent.JetBDTSigTight ),
        EleBDTLoose( parent.EleBDTLoose ),
        EleBDTMedium( parent.EleBDTMedium ),
        EleBDTTight( parent.EleBDTTight ),
        numTrack( parent.numTrack ),
        leadTrkPt( parent.leadTrkPt ),
        leadTrack_eta( parent.leadTrack_eta ),
        leadTrack_phi( parent.leadTrack_phi ) , 
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
   TauD3PDObject::TauD3PDObject( const ::Long64_t& master, const char* prefix , bool is_data )
      : TObject(),
        n( this, ::TString( prefix ) + "n", &master ),
        pt( this, ::TString( prefix ) + "pt", &master ),
        m( this, ::TString( prefix ) + "m", &master ),
        eta( this, ::TString( prefix ) + "eta", &master ),
        phi( this, ::TString( prefix ) + "phi", &master ),
        charge( this, ::TString( prefix ) + "charge", &master ),
        BDTEleScore( this, ::TString( prefix ) + "BDTEleScore", &master ),
        BDTJetScore( this, ::TString( prefix ) + "BDTJetScore", &master ),
        muonVeto( this, ::TString( prefix ) + "muonVeto", &master ),
        JetBDTSigLoose( this, ::TString( prefix ) + "JetBDTSigLoose", &master ),
        JetBDTSigMedium( this, ::TString( prefix ) + "JetBDTSigMedium", &master ),
        JetBDTSigTight( this, ::TString( prefix ) + "JetBDTSigTight", &master ),
        EleBDTLoose( this, ::TString( prefix ) + "EleBDTLoose", &master ),
        EleBDTMedium( this, ::TString( prefix ) + "EleBDTMedium", &master ),
        EleBDTTight( this, ::TString( prefix ) + "EleBDTTight", &master ),
        numTrack( this, ::TString( prefix ) + "numTrack", &master ),
        leadTrkPt( this, ::TString( prefix ) + "leadTrkPt", &master ),
        leadTrack_eta( this, ::TString( prefix ) + "leadTrack_eta", &master ),
        leadTrack_phi( this, ::TString( prefix ) + "leadTrack_phi", &master ),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "n" ] = &n;
      fHandles[ "pt" ] = &pt;
      fHandles[ "m" ] = &m;
      fHandles[ "eta" ] = &eta;
      fHandles[ "phi" ] = &phi;
      fHandles[ "charge" ] = &charge;
      fHandles[ "BDTEleScore" ] = &BDTEleScore;
      fHandles[ "BDTJetScore" ] = &BDTJetScore;
      fHandles[ "muonVeto" ] = &muonVeto;
      fHandles[ "JetBDTSigLoose" ] = &JetBDTSigLoose;
      fHandles[ "JetBDTSigMedium" ] = &JetBDTSigMedium;
      fHandles[ "JetBDTSigTight" ] = &JetBDTSigTight;
      fHandles[ "EleBDTLoose" ] = &EleBDTLoose;
      fHandles[ "EleBDTMedium" ] = &EleBDTMedium;
      fHandles[ "EleBDTTight" ] = &EleBDTTight;
      fHandles[ "numTrack" ] = &numTrack;
      fHandles[ "leadTrkPt" ] = &leadTrkPt;
      fHandles[ "leadTrack_eta" ] = &leadTrack_eta;
      fHandles[ "leadTrack_phi" ] = &leadTrack_phi;
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   TauD3PDObject::TauD3PDObject( const char* prefix , bool is_data )
      : TObject(),
        n( this, ::TString( prefix ) + "n", 0 ),
        pt( this, ::TString( prefix ) + "pt", 0 ),
        m( this, ::TString( prefix ) + "m", 0 ),
        eta( this, ::TString( prefix ) + "eta", 0 ),
        phi( this, ::TString( prefix ) + "phi", 0 ),
        charge( this, ::TString( prefix ) + "charge", 0 ),
        BDTEleScore( this, ::TString( prefix ) + "BDTEleScore", 0 ),
        BDTJetScore( this, ::TString( prefix ) + "BDTJetScore", 0 ),
        muonVeto( this, ::TString( prefix ) + "muonVeto", 0 ),
        JetBDTSigLoose( this, ::TString( prefix ) + "JetBDTSigLoose", 0 ),
        JetBDTSigMedium( this, ::TString( prefix ) + "JetBDTSigMedium", 0 ),
        JetBDTSigTight( this, ::TString( prefix ) + "JetBDTSigTight", 0 ),
        EleBDTLoose( this, ::TString( prefix ) + "EleBDTLoose", 0 ),
        EleBDTMedium( this, ::TString( prefix ) + "EleBDTMedium", 0 ),
        EleBDTTight( this, ::TString( prefix ) + "EleBDTTight", 0 ),
        numTrack( this, ::TString( prefix ) + "numTrack", 0 ),
        leadTrkPt( this, ::TString( prefix ) + "leadTrkPt", 0 ),
        leadTrack_eta( this, ::TString( prefix ) + "leadTrack_eta", 0 ),
        leadTrack_phi( this, ::TString( prefix ) + "leadTrack_phi", 0 ),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "n" ] = &n;
      fHandles[ "pt" ] = &pt;
      fHandles[ "m" ] = &m;
      fHandles[ "eta" ] = &eta;
      fHandles[ "phi" ] = &phi;
      fHandles[ "charge" ] = &charge;
      fHandles[ "BDTEleScore" ] = &BDTEleScore;
      fHandles[ "BDTJetScore" ] = &BDTJetScore;
      fHandles[ "muonVeto" ] = &muonVeto;
      fHandles[ "JetBDTSigLoose" ] = &JetBDTSigLoose;
      fHandles[ "JetBDTSigMedium" ] = &JetBDTSigMedium;
      fHandles[ "JetBDTSigTight" ] = &JetBDTSigTight;
      fHandles[ "EleBDTLoose" ] = &EleBDTLoose;
      fHandles[ "EleBDTMedium" ] = &EleBDTMedium;
      fHandles[ "EleBDTTight" ] = &EleBDTTight;
      fHandles[ "numTrack" ] = &numTrack;
      fHandles[ "leadTrkPt" ] = &leadTrkPt;
      fHandles[ "leadTrack_eta" ] = &leadTrack_eta;
      fHandles[ "leadTrack_phi" ] = &leadTrack_phi;
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* TauD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void TauD3PDObject::SetPrefix( const char* prefix ) {

      n.SetName( ::TString( prefix ) + "n" );
      pt.SetName( ::TString( prefix ) + "pt" );
      m.SetName( ::TString( prefix ) + "m" );
      eta.SetName( ::TString( prefix ) + "eta" );
      phi.SetName( ::TString( prefix ) + "phi" );
      charge.SetName( ::TString( prefix ) + "charge" );
      BDTEleScore.SetName( ::TString( prefix ) + "BDTEleScore" );
      BDTJetScore.SetName( ::TString( prefix ) + "BDTJetScore" );
      muonVeto.SetName( ::TString( prefix ) + "muonVeto" );
      JetBDTSigLoose.SetName( ::TString( prefix ) + "JetBDTSigLoose" );
      JetBDTSigMedium.SetName( ::TString( prefix ) + "JetBDTSigMedium" );
      JetBDTSigTight.SetName( ::TString( prefix ) + "JetBDTSigTight" );
      EleBDTLoose.SetName( ::TString( prefix ) + "EleBDTLoose" );
      EleBDTMedium.SetName( ::TString( prefix ) + "EleBDTMedium" );
      EleBDTTight.SetName( ::TString( prefix ) + "EleBDTTight" );
      numTrack.SetName( ::TString( prefix ) + "numTrack" );
      leadTrkPt.SetName( ::TString( prefix ) + "leadTrkPt" );
      leadTrack_eta.SetName( ::TString( prefix ) + "leadTrack_eta" );
      leadTrack_phi.SetName( ::TString( prefix ) + "leadTrack_phi" );
      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void TauD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      n.ReadFrom( tree );
      pt.ReadFrom( tree );
      m.ReadFrom( tree );
      eta.ReadFrom( tree );
      phi.ReadFrom( tree );
      charge.ReadFrom( tree );
      BDTEleScore.ReadFrom( tree );
      BDTJetScore.ReadFrom( tree );
      muonVeto.ReadFrom( tree );
      JetBDTSigLoose.ReadFrom( tree );
      JetBDTSigMedium.ReadFrom( tree );
      JetBDTSigTight.ReadFrom( tree );
      EleBDTLoose.ReadFrom( tree );
      EleBDTMedium.ReadFrom( tree );
      EleBDTTight.ReadFrom( tree );
      numTrack.ReadFrom( tree );
      leadTrkPt.ReadFrom( tree );
      leadTrack_eta.ReadFrom( tree );
      leadTrack_phi.ReadFrom( tree );

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void TauD3PDObject::WriteTo( TTree* tree ) {

      n.WriteTo( tree );
      pt.WriteTo( tree );
      m.WriteTo( tree );
      eta.WriteTo( tree );
      phi.WriteTo( tree );
      charge.WriteTo( tree );
      BDTEleScore.WriteTo( tree );
      BDTJetScore.WriteTo( tree );
      muonVeto.WriteTo( tree );
      JetBDTSigLoose.WriteTo( tree );
      JetBDTSigMedium.WriteTo( tree );
      JetBDTSigTight.WriteTo( tree );
      EleBDTLoose.WriteTo( tree );
      EleBDTMedium.WriteTo( tree );
      EleBDTTight.WriteTo( tree );
      numTrack.WriteTo( tree );
      leadTrkPt.WriteTo( tree );
      leadTrack_eta.WriteTo( tree );
      leadTrack_phi.WriteTo( tree );

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
   void TauD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void TauD3PDObject::ReadAllActive() {

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
      if( pt.IsActive() ) pt();
      if( m.IsActive() ) m();
      if( eta.IsActive() ) eta();
      if( phi.IsActive() ) phi();
      if( charge.IsActive() ) charge();
      if( BDTEleScore.IsActive() ) BDTEleScore();
      if( BDTJetScore.IsActive() ) BDTJetScore();
      if( muonVeto.IsActive() ) muonVeto();
      if( JetBDTSigLoose.IsActive() ) JetBDTSigLoose();
      if( JetBDTSigMedium.IsActive() ) JetBDTSigMedium();
      if( JetBDTSigTight.IsActive() ) JetBDTSigTight();
      if( EleBDTLoose.IsActive() ) EleBDTLoose();
      if( EleBDTMedium.IsActive() ) EleBDTMedium();
      if( EleBDTTight.IsActive() ) EleBDTTight();
      if( numTrack.IsActive() ) numTrack();
      if( leadTrkPt.IsActive() ) leadTrkPt();
      if( leadTrack_eta.IsActive() ) leadTrack_eta();
      if( leadTrack_phi.IsActive() ) leadTrack_phi();

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
   void TauD3PDObject::Clear( Option_t* ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Clear", "Objects used for reading a D3PD can't be cleared!" );
         return;
      }

      n() = 0;
      pt()->clear();
      m()->clear();
      eta()->clear();
      phi()->clear();
      charge()->clear();
      BDTEleScore()->clear();
      BDTJetScore()->clear();
      muonVeto()->clear();
      JetBDTSigLoose()->clear();
      JetBDTSigMedium()->clear();
      JetBDTSigTight()->clear();
      EleBDTLoose()->clear();
      EleBDTMedium()->clear();
      EleBDTTight()->clear();
      numTrack()->clear();
      leadTrkPt()->clear();
      leadTrack_eta()->clear();
      leadTrack_phi()->clear();

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
   TauD3PDObject& TauD3PDObject::Add( const TauD3PDObjectElement& el ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Add", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      ++( n() );
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
      if( el.charge.IsAvailable() ) {
         charge()->push_back( el.charge() );
      } else {
         charge()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.BDTEleScore.IsAvailable() ) {
         BDTEleScore()->push_back( el.BDTEleScore() );
      } else {
         BDTEleScore()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.BDTJetScore.IsAvailable() ) {
         BDTJetScore()->push_back( el.BDTJetScore() );
      } else {
         BDTJetScore()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.muonVeto.IsAvailable() ) {
         muonVeto()->push_back( el.muonVeto() );
      } else {
         muonVeto()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.JetBDTSigLoose.IsAvailable() ) {
         JetBDTSigLoose()->push_back( el.JetBDTSigLoose() );
      } else {
         JetBDTSigLoose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.JetBDTSigMedium.IsAvailable() ) {
         JetBDTSigMedium()->push_back( el.JetBDTSigMedium() );
      } else {
         JetBDTSigMedium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.JetBDTSigTight.IsAvailable() ) {
         JetBDTSigTight()->push_back( el.JetBDTSigTight() );
      } else {
         JetBDTSigTight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.EleBDTLoose.IsAvailable() ) {
         EleBDTLoose()->push_back( el.EleBDTLoose() );
      } else {
         EleBDTLoose()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.EleBDTMedium.IsAvailable() ) {
         EleBDTMedium()->push_back( el.EleBDTMedium() );
      } else {
         EleBDTMedium()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.EleBDTTight.IsAvailable() ) {
         EleBDTTight()->push_back( el.EleBDTTight() );
      } else {
         EleBDTTight()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.numTrack.IsAvailable() ) {
         numTrack()->push_back( el.numTrack() );
      } else {
         numTrack()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.leadTrkPt.IsAvailable() ) {
         leadTrkPt()->push_back( el.leadTrkPt() );
      } else {
         leadTrkPt()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.leadTrack_eta.IsAvailable() ) {
         leadTrack_eta()->push_back( el.leadTrack_eta() );
      } else {
         leadTrack_eta()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.leadTrack_phi.IsAvailable() ) {
         leadTrack_phi()->push_back( el.leadTrack_phi() );
      } else {
         leadTrack_phi()->push_back( std::numeric_limits< float >::min() );
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
   TauD3PDObjectElement& TauD3PDObject::operator[]( size_t index ) {

      while( fProxies.size() <= index ) {
         fProxies.push_back( TauD3PDObjectElement( fProxies.size(), *this , is_data ) );
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
   const TauD3PDObjectElement& TauD3PDObject::operator[]( size_t index ) const {

      while( fProxies.size() <= index ) {
         fProxies.push_back( TauD3PDObjectElement( fProxies.size(), *this , is_data ) );
      }
      return fProxies[ index ];
   }

   /**
    * A convenience operator for adding an 'element' to this collection.
    *
    * @see Add
    * @param el The 'element' that should be added to the collection
    */
   TauD3PDObject& TauD3PDObject::operator+=( const TauD3PDObjectElement& el ) {

      return this->Add( el );
   }

} // namespace D3PDReader
