// $Id$

int SETUP() {

   /// Add all the additional libraries here that this package
   /// depends on. (With the same command that loads this package's library...)

  if( gSystem->Load( "libTree" ) == -1 ) return -1;
  if( gSystem->Load( "libHist" ) == -1 ) return -1;
  if( gSystem->Load( "libGraf" ) == -1 ) return -1;
  if( gSystem->Load( "libPhysics" ) == -1 ) return -1;

   if( gSystem->Load( "libD3PDObjects" ) == -1 ) return -1;

   return 0;
}
