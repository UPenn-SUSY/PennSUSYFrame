// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <limits>

#include <TPRegexp.h>

#include "../include/VertexD3PDObject.h"

ClassImp( D3PDReader::VertexD3PDObjectElement )
ClassImp( D3PDReader::VertexD3PDObject )

namespace D3PDReader {

   /**
    * This constructor can be used to create new proxy objects from scratch.
    * Since the constructor of such an object is quite complicated and
    * error prone, it is only visible to the parent class VertexD3PDObject.
    */
   VertexD3PDObjectElement::VertexD3PDObjectElement( size_t index, const VertexD3PDObject& parent , bool is_data )
      : x( parent.x, index, this ),
        y( parent.y, index, this ),
        z( parent.z, index, this ),
        px( parent.px, index, this ),
        py( parent.py, index, this ),
        pz( parent.pz, index, this ),
        E( parent.E, index, this ),
        m( parent.m, index, this ),
        nTracks( parent.nTracks, index, this ),
        sumPt( parent.sumPt, index, this ) , 
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
   VertexD3PDObjectElement::VertexD3PDObjectElement( const VertexD3PDObjectElement& parent , bool is_data )
      : TObject( parent ),
        x( parent.x ),
        y( parent.y ),
        z( parent.z ),
        px( parent.px ),
        py( parent.py ),
        pz( parent.pz ),
        E( parent.E ),
        m( parent.m ),
        nTracks( parent.nTracks ),
        sumPt( parent.sumPt ) , 
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
   VertexD3PDObject::VertexD3PDObject( const ::Long64_t& master, const char* prefix , bool is_data )
      : TObject(),
        n( this, ::TString( prefix ) + "n", &master ),
        x( this, ::TString( prefix ) + "x", &master ),
        y( this, ::TString( prefix ) + "y", &master ),
        z( this, ::TString( prefix ) + "z", &master ),
        px( this, ::TString( prefix ) + "px", &master ),
        py( this, ::TString( prefix ) + "py", &master ),
        pz( this, ::TString( prefix ) + "pz", &master ),
        E( this, ::TString( prefix ) + "E", &master ),
        m( this, ::TString( prefix ) + "m", &master ),
        nTracks( this, ::TString( prefix ) + "nTracks", &master ),
        sumPt( this, ::TString( prefix ) + "sumPt", &master ),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "n" ] = &n;
      fHandles[ "x" ] = &x;
      fHandles[ "y" ] = &y;
      fHandles[ "z" ] = &z;
      fHandles[ "px" ] = &px;
      fHandles[ "py" ] = &py;
      fHandles[ "pz" ] = &pz;
      fHandles[ "E" ] = &E;
      fHandles[ "m" ] = &m;
      fHandles[ "nTracks" ] = &nTracks;
      fHandles[ "sumPt" ] = &sumPt;
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   VertexD3PDObject::VertexD3PDObject( const char* prefix , bool is_data )
      : TObject(),
        n( this, ::TString( prefix ) + "n", 0 ),
        x( this, ::TString( prefix ) + "x", 0 ),
        y( this, ::TString( prefix ) + "y", 0 ),
        z( this, ::TString( prefix ) + "z", 0 ),
        px( this, ::TString( prefix ) + "px", 0 ),
        py( this, ::TString( prefix ) + "py", 0 ),
        pz( this, ::TString( prefix ) + "pz", 0 ),
        E( this, ::TString( prefix ) + "E", 0 ),
        m( this, ::TString( prefix ) + "m", 0 ),
        nTracks( this, ::TString( prefix ) + "nTracks", 0 ),
        sumPt( this, ::TString( prefix ) + "sumPt", 0 ),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "n" ] = &n;
      fHandles[ "x" ] = &x;
      fHandles[ "y" ] = &y;
      fHandles[ "z" ] = &z;
      fHandles[ "px" ] = &px;
      fHandles[ "py" ] = &py;
      fHandles[ "pz" ] = &pz;
      fHandles[ "E" ] = &E;
      fHandles[ "m" ] = &m;
      fHandles[ "nTracks" ] = &nTracks;
      fHandles[ "sumPt" ] = &sumPt;
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* VertexD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void VertexD3PDObject::SetPrefix( const char* prefix ) {

      n.SetName( ::TString( prefix ) + "n" );
      x.SetName( ::TString( prefix ) + "x" );
      y.SetName( ::TString( prefix ) + "y" );
      z.SetName( ::TString( prefix ) + "z" );
      px.SetName( ::TString( prefix ) + "px" );
      py.SetName( ::TString( prefix ) + "py" );
      pz.SetName( ::TString( prefix ) + "pz" );
      E.SetName( ::TString( prefix ) + "E" );
      m.SetName( ::TString( prefix ) + "m" );
      nTracks.SetName( ::TString( prefix ) + "nTracks" );
      sumPt.SetName( ::TString( prefix ) + "sumPt" );
      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void VertexD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      n.ReadFrom( tree );
      x.ReadFrom( tree );
      y.ReadFrom( tree );
      z.ReadFrom( tree );
      px.ReadFrom( tree );
      py.ReadFrom( tree );
      pz.ReadFrom( tree );
      E.ReadFrom( tree );
      m.ReadFrom( tree );
      nTracks.ReadFrom( tree );
      sumPt.ReadFrom( tree );

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void VertexD3PDObject::WriteTo( TTree* tree ) {

      n.WriteTo( tree );
      x.WriteTo( tree );
      y.WriteTo( tree );
      z.WriteTo( tree );
      px.WriteTo( tree );
      py.WriteTo( tree );
      pz.WriteTo( tree );
      E.WriteTo( tree );
      m.WriteTo( tree );
      nTracks.WriteTo( tree );
      sumPt.WriteTo( tree );

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
   void VertexD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void VertexD3PDObject::ReadAllActive() {

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
      if( x.IsActive() ) x();
      if( y.IsActive() ) y();
      if( z.IsActive() ) z();
      if( px.IsActive() ) px();
      if( py.IsActive() ) py();
      if( pz.IsActive() ) pz();
      if( E.IsActive() ) E();
      if( m.IsActive() ) m();
      if( nTracks.IsActive() ) nTracks();
      if( sumPt.IsActive() ) sumPt();

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
   void VertexD3PDObject::Clear( Option_t* ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Clear", "Objects used for reading a D3PD can't be cleared!" );
         return;
      }

      n() = 0;
      x()->clear();
      y()->clear();
      z()->clear();
      px()->clear();
      py()->clear();
      pz()->clear();
      E()->clear();
      m()->clear();
      nTracks()->clear();
      sumPt()->clear();

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
   VertexD3PDObject& VertexD3PDObject::Add( const VertexD3PDObjectElement& el ) {

      // Check if this function can be used on the object:
      if( fFromInput ) {
         Error( "Add", "Objects used for reading a D3PD can't be modified!" );
         return *this;
      }

      ++( n() );
      if( el.x.IsAvailable() ) {
         x()->push_back( el.x() );
      } else {
         x()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.y.IsAvailable() ) {
         y()->push_back( el.y() );
      } else {
         y()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.z.IsAvailable() ) {
         z()->push_back( el.z() );
      } else {
         z()->push_back( std::numeric_limits< float >::min() );
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
      if( el.E.IsAvailable() ) {
         E()->push_back( el.E() );
      } else {
         E()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.m.IsAvailable() ) {
         m()->push_back( el.m() );
      } else {
         m()->push_back( std::numeric_limits< float >::min() );
      }
      if( el.nTracks.IsAvailable() ) {
         nTracks()->push_back( el.nTracks() );
      } else {
         nTracks()->push_back( std::numeric_limits< int >::min() );
      }
      if( el.sumPt.IsAvailable() ) {
         sumPt()->push_back( el.sumPt() );
      } else {
         sumPt()->push_back( std::numeric_limits< float >::min() );
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
   VertexD3PDObjectElement& VertexD3PDObject::operator[]( size_t index ) {

      while( fProxies.size() <= index ) {
         fProxies.push_back( VertexD3PDObjectElement( fProxies.size(), *this , is_data ) );
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
   const VertexD3PDObjectElement& VertexD3PDObject::operator[]( size_t index ) const {

      while( fProxies.size() <= index ) {
         fProxies.push_back( VertexD3PDObjectElement( fProxies.size(), *this , is_data ) );
      }
      return fProxies[ index ];
   }

   /**
    * A convenience operator for adding an 'element' to this collection.
    *
    * @see Add
    * @param el The 'element' that should be added to the collection
    */
   VertexD3PDObject& VertexD3PDObject::operator+=( const VertexD3PDObjectElement& el ) {

      return this->Add( el );
   }

} // namespace D3PDReader
