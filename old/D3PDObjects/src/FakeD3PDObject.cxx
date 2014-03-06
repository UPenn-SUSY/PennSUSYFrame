// Dear emacs, this is -*- c++ -*-
// -------------------------------------------------------------
//             Code produced by D3PDMakerReader
//
//  author: Attila Krasznahorkay <Attila.Krasznahorkay@cern.ch>
// -------------------------------------------------------------

#include <TPRegexp.h>

#include "../include/FakeD3PDObject.h"

ClassImp( D3PDReader::FakeD3PDObject )

namespace D3PDReader {

   /**
    * This constructor should be used when the object will be used to read
    * variables from an existing ntuple. The object will also be able to
    * output variables, but it will also need to read them from somewhere.
    *
    * @param master Reference to the variable holding the current event number
    * @param prefix Prefix of the variables in the D3PD
    */
   FakeD3PDObject::FakeD3PDObject( const ::Long64_t& master, const char* prefix )
      : TObject(),
        EventNumber( this, ::TString( prefix ) + "EventNumber", &master ),
        LepId( this, ::TString( prefix ) + "LepId", &master ),
        LepTight( this, ::TString( prefix ) + "LepTight", &master ),
        lepN( this, ::TString( prefix ) + "lepN", &master ),
        lepPx( this, ::TString( prefix ) + "lepPx", &master ),
        lepPy( this, ::TString( prefix ) + "lepPy", &master ),
        lepPz( this, ::TString( prefix ) + "lepPz", &master ),
        lepPt( this, ::TString( prefix ) + "lepPt", &master ),
        lepE( this, ::TString( prefix ) + "lepE", &master ),
        jetN( this, ::TString( prefix ) + "jetN", &master ),
        jetPx( this, ::TString( prefix ) + "jetPx", &master ),
        jetPy( this, ::TString( prefix ) + "jetPy", &master ),
        jetPz( this, ::TString( prefix ) + "jetPz", &master ),
        jetPt( this, ::TString( prefix ) + "jetPt", &master ),
        jetE( this, ::TString( prefix ) + "jetE", &master ),
        jetJVF( this, ::TString( prefix ) + "jetJVF", &master ),
        JetFitterCOMBNN( this, ::TString( prefix ) + "JetFitterCOMBNN", &master ),
        thisMETx( this, ::TString( prefix ) + "thisMETx", &master ),
        thisMETy( this, ::TString( prefix ) + "thisMETy", &master ),
        missingET_rel( this, ::TString( prefix ) + "missingET_rel", &master ),
        mt2( this, ::TString( prefix ) + "mt2", &master ),
        mll( this, ::TString( prefix ) + "mll", &master ),
        OS( this, ::TString( prefix ) + "OS", &master ),
        SS( this, ::TString( prefix ) + "SS", &master ),
        EE( this, ::TString( prefix ) + "EE", &master ),
        EM( this, ::TString( prefix ) + "EM", &master ),
        ME( this, ::TString( prefix ) + "ME", &master ),
        MM( this, ::TString( prefix ) + "MM", &master ),
        TT( this, ::TString( prefix ) + "TT", &master ),
        Tl( this, ::TString( prefix ) + "Tl", &master ),
        lT( this, ::TString( prefix ) + "lT", &master ),
        ll( this, ::TString( prefix ) + "ll", &master ),
        wgts_rr_nom( this, ::TString( prefix ) + "wgts_rr_nom", &master ),
        wgts_rf_nom( this, ::TString( prefix ) + "wgts_rf_nom", &master ),
        wgts_fr_nom( this, ::TString( prefix ) + "wgts_fr_nom", &master ),
        wgts_ff_nom( this, ::TString( prefix ) + "wgts_ff_nom", &master ),
        wgts_rr_max( this, ::TString( prefix ) + "wgts_rr_max", &master ),
        wgts_rf_max( this, ::TString( prefix ) + "wgts_rf_max", &master ),
        wgts_fr_max( this, ::TString( prefix ) + "wgts_fr_max", &master ),
        wgts_ff_max( this, ::TString( prefix ) + "wgts_ff_max", &master ),
        wgts_rr_min( this, ::TString( prefix ) + "wgts_rr_min", &master ),
        wgts_rf_min( this, ::TString( prefix ) + "wgts_rf_min", &master ),
        wgts_fr_min( this, ::TString( prefix ) + "wgts_fr_min", &master ),
        wgts_ff_min( this, ::TString( prefix ) + "wgts_ff_min", &master ),
        wgts_rr_syst_nom( this, ::TString( prefix ) + "wgts_rr_syst_nom", &master ),
        wgts_rf_syst_nom( this, ::TString( prefix ) + "wgts_rf_syst_nom", &master ),
        wgts_fr_syst_nom( this, ::TString( prefix ) + "wgts_fr_syst_nom", &master ),
        wgts_ff_syst_nom( this, ::TString( prefix ) + "wgts_ff_syst_nom", &master ),
        wgts_rr_syst_max( this, ::TString( prefix ) + "wgts_rr_syst_max", &master ),
        wgts_rf_syst_max( this, ::TString( prefix ) + "wgts_rf_syst_max", &master ),
        wgts_fr_syst_max( this, ::TString( prefix ) + "wgts_fr_syst_max", &master ),
        wgts_ff_syst_max( this, ::TString( prefix ) + "wgts_ff_syst_max", &master ),
        wgts_rr_syst_min( this, ::TString( prefix ) + "wgts_rr_syst_min", &master ),
        wgts_rf_syst_min( this, ::TString( prefix ) + "wgts_rf_syst_min", &master ),
        wgts_fr_syst_min( this, ::TString( prefix ) + "wgts_fr_syst_min", &master ),
        wgts_ff_syst_min( this, ::TString( prefix ) + "wgts_ff_syst_min", &master ),
        region( this, ::TString( prefix ) + "region", &master ),
        region_SIGT( this, ::TString( prefix ) + "region_SIGT", &master ),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) {

      fHandles[ "EventNumber" ] = &EventNumber;
      fHandles[ "LepId" ] = &LepId;
      fHandles[ "LepTight" ] = &LepTight;
      fHandles[ "lepN" ] = &lepN;
      fHandles[ "lepPx" ] = &lepPx;
      fHandles[ "lepPy" ] = &lepPy;
      fHandles[ "lepPz" ] = &lepPz;
      fHandles[ "lepPt" ] = &lepPt;
      fHandles[ "lepE" ] = &lepE;
      fHandles[ "jetN" ] = &jetN;
      fHandles[ "jetPx" ] = &jetPx;
      fHandles[ "jetPy" ] = &jetPy;
      fHandles[ "jetPz" ] = &jetPz;
      fHandles[ "jetPt" ] = &jetPt;
      fHandles[ "jetE" ] = &jetE;
      fHandles[ "jetJVF" ] = &jetJVF;
      fHandles[ "JetFitterCOMBNN" ] = &JetFitterCOMBNN;
      fHandles[ "thisMETx" ] = &thisMETx;
      fHandles[ "thisMETy" ] = &thisMETy;
      fHandles[ "missingET_rel" ] = &missingET_rel;
      fHandles[ "mt2" ] = &mt2;
      fHandles[ "mll" ] = &mll;
      fHandles[ "OS" ] = &OS;
      fHandles[ "SS" ] = &SS;
      fHandles[ "EE" ] = &EE;
      fHandles[ "EM" ] = &EM;
      fHandles[ "ME" ] = &ME;
      fHandles[ "MM" ] = &MM;
      fHandles[ "TT" ] = &TT;
      fHandles[ "Tl" ] = &Tl;
      fHandles[ "lT" ] = &lT;
      fHandles[ "ll" ] = &ll;
      fHandles[ "wgts_rr_nom" ] = &wgts_rr_nom;
      fHandles[ "wgts_rf_nom" ] = &wgts_rf_nom;
      fHandles[ "wgts_fr_nom" ] = &wgts_fr_nom;
      fHandles[ "wgts_ff_nom" ] = &wgts_ff_nom;
      fHandles[ "wgts_rr_max" ] = &wgts_rr_max;
      fHandles[ "wgts_rf_max" ] = &wgts_rf_max;
      fHandles[ "wgts_fr_max" ] = &wgts_fr_max;
      fHandles[ "wgts_ff_max" ] = &wgts_ff_max;
      fHandles[ "wgts_rr_min" ] = &wgts_rr_min;
      fHandles[ "wgts_rf_min" ] = &wgts_rf_min;
      fHandles[ "wgts_fr_min" ] = &wgts_fr_min;
      fHandles[ "wgts_ff_min" ] = &wgts_ff_min;
      fHandles[ "wgts_rr_syst_nom" ] = &wgts_rr_syst_nom;
      fHandles[ "wgts_rf_syst_nom" ] = &wgts_rf_syst_nom;
      fHandles[ "wgts_fr_syst_nom" ] = &wgts_fr_syst_nom;
      fHandles[ "wgts_ff_syst_nom" ] = &wgts_ff_syst_nom;
      fHandles[ "wgts_rr_syst_max" ] = &wgts_rr_syst_max;
      fHandles[ "wgts_rf_syst_max" ] = &wgts_rf_syst_max;
      fHandles[ "wgts_fr_syst_max" ] = &wgts_fr_syst_max;
      fHandles[ "wgts_ff_syst_max" ] = &wgts_ff_syst_max;
      fHandles[ "wgts_rr_syst_min" ] = &wgts_rr_syst_min;
      fHandles[ "wgts_rf_syst_min" ] = &wgts_rf_syst_min;
      fHandles[ "wgts_fr_syst_min" ] = &wgts_fr_syst_min;
      fHandles[ "wgts_ff_syst_min" ] = &wgts_ff_syst_min;
      fHandles[ "region" ] = &region;
      fHandles[ "region_SIGT" ] = &region_SIGT;
   }

   /**
    * This constructor can be used when the object will only have to output
    * (and temporarily store) new information into an output ntuple. For
    * instance when one wants to create a selected/modified list of information.
    *
    * @param prefix Prefix of the variables in the D3PD
    */
   FakeD3PDObject::FakeD3PDObject( const char* prefix )
      : TObject(),
        EventNumber( this, ::TString( prefix ) + "EventNumber", 0 ),
        LepId( this, ::TString( prefix ) + "LepId", 0 ),
        LepTight( this, ::TString( prefix ) + "LepTight", 0 ),
        lepN( this, ::TString( prefix ) + "lepN", 0 ),
        lepPx( this, ::TString( prefix ) + "lepPx", 0 ),
        lepPy( this, ::TString( prefix ) + "lepPy", 0 ),
        lepPz( this, ::TString( prefix ) + "lepPz", 0 ),
        lepPt( this, ::TString( prefix ) + "lepPt", 0 ),
        lepE( this, ::TString( prefix ) + "lepE", 0 ),
        jetN( this, ::TString( prefix ) + "jetN", 0 ),
        jetPx( this, ::TString( prefix ) + "jetPx", 0 ),
        jetPy( this, ::TString( prefix ) + "jetPy", 0 ),
        jetPz( this, ::TString( prefix ) + "jetPz", 0 ),
        jetPt( this, ::TString( prefix ) + "jetPt", 0 ),
        jetE( this, ::TString( prefix ) + "jetE", 0 ),
        jetJVF( this, ::TString( prefix ) + "jetJVF", 0 ),
        JetFitterCOMBNN( this, ::TString( prefix ) + "JetFitterCOMBNN", 0 ),
        thisMETx( this, ::TString( prefix ) + "thisMETx", 0 ),
        thisMETy( this, ::TString( prefix ) + "thisMETy", 0 ),
        missingET_rel( this, ::TString( prefix ) + "missingET_rel", 0 ),
        mt2( this, ::TString( prefix ) + "mt2", 0 ),
        mll( this, ::TString( prefix ) + "mll", 0 ),
        OS( this, ::TString( prefix ) + "OS", 0 ),
        SS( this, ::TString( prefix ) + "SS", 0 ),
        EE( this, ::TString( prefix ) + "EE", 0 ),
        EM( this, ::TString( prefix ) + "EM", 0 ),
        ME( this, ::TString( prefix ) + "ME", 0 ),
        MM( this, ::TString( prefix ) + "MM", 0 ),
        TT( this, ::TString( prefix ) + "TT", 0 ),
        Tl( this, ::TString( prefix ) + "Tl", 0 ),
        lT( this, ::TString( prefix ) + "lT", 0 ),
        ll( this, ::TString( prefix ) + "ll", 0 ),
        wgts_rr_nom( this, ::TString( prefix ) + "wgts_rr_nom", 0 ),
        wgts_rf_nom( this, ::TString( prefix ) + "wgts_rf_nom", 0 ),
        wgts_fr_nom( this, ::TString( prefix ) + "wgts_fr_nom", 0 ),
        wgts_ff_nom( this, ::TString( prefix ) + "wgts_ff_nom", 0 ),
        wgts_rr_max( this, ::TString( prefix ) + "wgts_rr_max", 0 ),
        wgts_rf_max( this, ::TString( prefix ) + "wgts_rf_max", 0 ),
        wgts_fr_max( this, ::TString( prefix ) + "wgts_fr_max", 0 ),
        wgts_ff_max( this, ::TString( prefix ) + "wgts_ff_max", 0 ),
        wgts_rr_min( this, ::TString( prefix ) + "wgts_rr_min", 0 ),
        wgts_rf_min( this, ::TString( prefix ) + "wgts_rf_min", 0 ),
        wgts_fr_min( this, ::TString( prefix ) + "wgts_fr_min", 0 ),
        wgts_ff_min( this, ::TString( prefix ) + "wgts_ff_min", 0 ),
        wgts_rr_syst_nom( this, ::TString( prefix ) + "wgts_rr_syst_nom", 0 ),
        wgts_rf_syst_nom( this, ::TString( prefix ) + "wgts_rf_syst_nom", 0 ),
        wgts_fr_syst_nom( this, ::TString( prefix ) + "wgts_fr_syst_nom", 0 ),
        wgts_ff_syst_nom( this, ::TString( prefix ) + "wgts_ff_syst_nom", 0 ),
        wgts_rr_syst_max( this, ::TString( prefix ) + "wgts_rr_syst_max", 0 ),
        wgts_rf_syst_max( this, ::TString( prefix ) + "wgts_rf_syst_max", 0 ),
        wgts_fr_syst_max( this, ::TString( prefix ) + "wgts_fr_syst_max", 0 ),
        wgts_ff_syst_max( this, ::TString( prefix ) + "wgts_ff_syst_max", 0 ),
        wgts_rr_syst_min( this, ::TString( prefix ) + "wgts_rr_syst_min", 0 ),
        wgts_rf_syst_min( this, ::TString( prefix ) + "wgts_rf_syst_min", 0 ),
        wgts_fr_syst_min( this, ::TString( prefix ) + "wgts_fr_syst_min", 0 ),
        wgts_ff_syst_min( this, ::TString( prefix ) + "wgts_ff_syst_min", 0 ),
        region( this, ::TString( prefix ) + "region", 0 ),
        region_SIGT( this, ::TString( prefix ) + "region_SIGT", 0 ),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) {

      fHandles[ "EventNumber" ] = &EventNumber;
      fHandles[ "LepId" ] = &LepId;
      fHandles[ "LepTight" ] = &LepTight;
      fHandles[ "lepN" ] = &lepN;
      fHandles[ "lepPx" ] = &lepPx;
      fHandles[ "lepPy" ] = &lepPy;
      fHandles[ "lepPz" ] = &lepPz;
      fHandles[ "lepPt" ] = &lepPt;
      fHandles[ "lepE" ] = &lepE;
      fHandles[ "jetN" ] = &jetN;
      fHandles[ "jetPx" ] = &jetPx;
      fHandles[ "jetPy" ] = &jetPy;
      fHandles[ "jetPz" ] = &jetPz;
      fHandles[ "jetPt" ] = &jetPt;
      fHandles[ "jetE" ] = &jetE;
      fHandles[ "jetJVF" ] = &jetJVF;
      fHandles[ "JetFitterCOMBNN" ] = &JetFitterCOMBNN;
      fHandles[ "thisMETx" ] = &thisMETx;
      fHandles[ "thisMETy" ] = &thisMETy;
      fHandles[ "missingET_rel" ] = &missingET_rel;
      fHandles[ "mt2" ] = &mt2;
      fHandles[ "mll" ] = &mll;
      fHandles[ "OS" ] = &OS;
      fHandles[ "SS" ] = &SS;
      fHandles[ "EE" ] = &EE;
      fHandles[ "EM" ] = &EM;
      fHandles[ "ME" ] = &ME;
      fHandles[ "MM" ] = &MM;
      fHandles[ "TT" ] = &TT;
      fHandles[ "Tl" ] = &Tl;
      fHandles[ "lT" ] = &lT;
      fHandles[ "ll" ] = &ll;
      fHandles[ "wgts_rr_nom" ] = &wgts_rr_nom;
      fHandles[ "wgts_rf_nom" ] = &wgts_rf_nom;
      fHandles[ "wgts_fr_nom" ] = &wgts_fr_nom;
      fHandles[ "wgts_ff_nom" ] = &wgts_ff_nom;
      fHandles[ "wgts_rr_max" ] = &wgts_rr_max;
      fHandles[ "wgts_rf_max" ] = &wgts_rf_max;
      fHandles[ "wgts_fr_max" ] = &wgts_fr_max;
      fHandles[ "wgts_ff_max" ] = &wgts_ff_max;
      fHandles[ "wgts_rr_min" ] = &wgts_rr_min;
      fHandles[ "wgts_rf_min" ] = &wgts_rf_min;
      fHandles[ "wgts_fr_min" ] = &wgts_fr_min;
      fHandles[ "wgts_ff_min" ] = &wgts_ff_min;
      fHandles[ "wgts_rr_syst_nom" ] = &wgts_rr_syst_nom;
      fHandles[ "wgts_rf_syst_nom" ] = &wgts_rf_syst_nom;
      fHandles[ "wgts_fr_syst_nom" ] = &wgts_fr_syst_nom;
      fHandles[ "wgts_ff_syst_nom" ] = &wgts_ff_syst_nom;
      fHandles[ "wgts_rr_syst_max" ] = &wgts_rr_syst_max;
      fHandles[ "wgts_rf_syst_max" ] = &wgts_rf_syst_max;
      fHandles[ "wgts_fr_syst_max" ] = &wgts_fr_syst_max;
      fHandles[ "wgts_ff_syst_max" ] = &wgts_ff_syst_max;
      fHandles[ "wgts_rr_syst_min" ] = &wgts_rr_syst_min;
      fHandles[ "wgts_rf_syst_min" ] = &wgts_rf_syst_min;
      fHandles[ "wgts_fr_syst_min" ] = &wgts_fr_syst_min;
      fHandles[ "wgts_ff_syst_min" ] = &wgts_ff_syst_min;
      fHandles[ "region" ] = &region;
      fHandles[ "region_SIGT" ] = &region_SIGT;
   }

   /**
    * @returns The branch name prefix used by the object
    */
   const char* FakeD3PDObject::GetPrefix() const {

      return fPrefix;
   }

   /**
    * @param prefix The prefix that should be used for the variables
    */
   void FakeD3PDObject::SetPrefix( const char* prefix ) {

      EventNumber.SetName( ::TString( prefix ) + "EventNumber" );
      LepId.SetName( ::TString( prefix ) + "LepId" );
      LepTight.SetName( ::TString( prefix ) + "LepTight" );
      lepN.SetName( ::TString( prefix ) + "lepN" );
      lepPx.SetName( ::TString( prefix ) + "lepPx" );
      lepPy.SetName( ::TString( prefix ) + "lepPy" );
      lepPz.SetName( ::TString( prefix ) + "lepPz" );
      lepPt.SetName( ::TString( prefix ) + "lepPt" );
      lepE.SetName( ::TString( prefix ) + "lepE" );
      jetN.SetName( ::TString( prefix ) + "jetN" );
      jetPx.SetName( ::TString( prefix ) + "jetPx" );
      jetPy.SetName( ::TString( prefix ) + "jetPy" );
      jetPz.SetName( ::TString( prefix ) + "jetPz" );
      jetPt.SetName( ::TString( prefix ) + "jetPt" );
      jetE.SetName( ::TString( prefix ) + "jetE" );
      jetJVF.SetName( ::TString( prefix ) + "jetJVF" );
      JetFitterCOMBNN.SetName( ::TString( prefix ) + "JetFitterCOMBNN" );
      thisMETx.SetName( ::TString( prefix ) + "thisMETx" );
      thisMETy.SetName( ::TString( prefix ) + "thisMETy" );
      missingET_rel.SetName( ::TString( prefix ) + "missingET_rel" );
      mt2.SetName( ::TString( prefix ) + "mt2" );
      mll.SetName( ::TString( prefix ) + "mll" );
      OS.SetName( ::TString( prefix ) + "OS" );
      SS.SetName( ::TString( prefix ) + "SS" );
      EE.SetName( ::TString( prefix ) + "EE" );
      EM.SetName( ::TString( prefix ) + "EM" );
      ME.SetName( ::TString( prefix ) + "ME" );
      MM.SetName( ::TString( prefix ) + "MM" );
      TT.SetName( ::TString( prefix ) + "TT" );
      Tl.SetName( ::TString( prefix ) + "Tl" );
      lT.SetName( ::TString( prefix ) + "lT" );
      ll.SetName( ::TString( prefix ) + "ll" );
      wgts_rr_nom.SetName( ::TString( prefix ) + "wgts_rr_nom" );
      wgts_rf_nom.SetName( ::TString( prefix ) + "wgts_rf_nom" );
      wgts_fr_nom.SetName( ::TString( prefix ) + "wgts_fr_nom" );
      wgts_ff_nom.SetName( ::TString( prefix ) + "wgts_ff_nom" );
      wgts_rr_max.SetName( ::TString( prefix ) + "wgts_rr_max" );
      wgts_rf_max.SetName( ::TString( prefix ) + "wgts_rf_max" );
      wgts_fr_max.SetName( ::TString( prefix ) + "wgts_fr_max" );
      wgts_ff_max.SetName( ::TString( prefix ) + "wgts_ff_max" );
      wgts_rr_min.SetName( ::TString( prefix ) + "wgts_rr_min" );
      wgts_rf_min.SetName( ::TString( prefix ) + "wgts_rf_min" );
      wgts_fr_min.SetName( ::TString( prefix ) + "wgts_fr_min" );
      wgts_ff_min.SetName( ::TString( prefix ) + "wgts_ff_min" );
      wgts_rr_syst_nom.SetName( ::TString( prefix ) + "wgts_rr_syst_nom" );
      wgts_rf_syst_nom.SetName( ::TString( prefix ) + "wgts_rf_syst_nom" );
      wgts_fr_syst_nom.SetName( ::TString( prefix ) + "wgts_fr_syst_nom" );
      wgts_ff_syst_nom.SetName( ::TString( prefix ) + "wgts_ff_syst_nom" );
      wgts_rr_syst_max.SetName( ::TString( prefix ) + "wgts_rr_syst_max" );
      wgts_rf_syst_max.SetName( ::TString( prefix ) + "wgts_rf_syst_max" );
      wgts_fr_syst_max.SetName( ::TString( prefix ) + "wgts_fr_syst_max" );
      wgts_ff_syst_max.SetName( ::TString( prefix ) + "wgts_ff_syst_max" );
      wgts_rr_syst_min.SetName( ::TString( prefix ) + "wgts_rr_syst_min" );
      wgts_rf_syst_min.SetName( ::TString( prefix ) + "wgts_rf_syst_min" );
      wgts_fr_syst_min.SetName( ::TString( prefix ) + "wgts_fr_syst_min" );
      wgts_ff_syst_min.SetName( ::TString( prefix ) + "wgts_ff_syst_min" );
      region.SetName( ::TString( prefix ) + "region" );
      region_SIGT.SetName( ::TString( prefix ) + "region_SIGT" );
      return;
   }

   /**
    * This function should be called every time a new TFile is opened
    * by your analysis code.
    *
    * @param tree Pointer to the TTree with the variables
    */
   void FakeD3PDObject::ReadFrom( TTree* tree ) {

      // Check if the object will be able to read from the TTree:
      if( ! fFromInput ) {
         Error( "ReadFrom", "The object was not created with the correct" );
         Error( "ReadFrom", "constructor to read data from a D3PD!" );
         return;
      }

      EventNumber.ReadFrom( tree );
      LepId.ReadFrom( tree );
      LepTight.ReadFrom( tree );
      lepN.ReadFrom( tree );
      lepPx.ReadFrom( tree );
      lepPy.ReadFrom( tree );
      lepPz.ReadFrom( tree );
      lepPt.ReadFrom( tree );
      lepE.ReadFrom( tree );
      jetN.ReadFrom( tree );
      jetPx.ReadFrom( tree );
      jetPy.ReadFrom( tree );
      jetPz.ReadFrom( tree );
      jetPt.ReadFrom( tree );
      jetE.ReadFrom( tree );
      jetJVF.ReadFrom( tree );
      JetFitterCOMBNN.ReadFrom( tree );
      thisMETx.ReadFrom( tree );
      thisMETy.ReadFrom( tree );
      missingET_rel.ReadFrom( tree );
      mt2.ReadFrom( tree );
      mll.ReadFrom( tree );
      OS.ReadFrom( tree );
      SS.ReadFrom( tree );
      EE.ReadFrom( tree );
      EM.ReadFrom( tree );
      ME.ReadFrom( tree );
      MM.ReadFrom( tree );
      TT.ReadFrom( tree );
      Tl.ReadFrom( tree );
      lT.ReadFrom( tree );
      ll.ReadFrom( tree );
      wgts_rr_nom.ReadFrom( tree );
      wgts_rf_nom.ReadFrom( tree );
      wgts_fr_nom.ReadFrom( tree );
      wgts_ff_nom.ReadFrom( tree );
      wgts_rr_max.ReadFrom( tree );
      wgts_rf_max.ReadFrom( tree );
      wgts_fr_max.ReadFrom( tree );
      wgts_ff_max.ReadFrom( tree );
      wgts_rr_min.ReadFrom( tree );
      wgts_rf_min.ReadFrom( tree );
      wgts_fr_min.ReadFrom( tree );
      wgts_ff_min.ReadFrom( tree );
      wgts_rr_syst_nom.ReadFrom( tree );
      wgts_rf_syst_nom.ReadFrom( tree );
      wgts_fr_syst_nom.ReadFrom( tree );
      wgts_ff_syst_nom.ReadFrom( tree );
      wgts_rr_syst_max.ReadFrom( tree );
      wgts_rf_syst_max.ReadFrom( tree );
      wgts_fr_syst_max.ReadFrom( tree );
      wgts_ff_syst_max.ReadFrom( tree );
      wgts_rr_syst_min.ReadFrom( tree );
      wgts_rf_syst_min.ReadFrom( tree );
      wgts_fr_syst_min.ReadFrom( tree );
      wgts_ff_syst_min.ReadFrom( tree );
      region.ReadFrom( tree );
      region_SIGT.ReadFrom( tree );

      return;
   }

   /**
    * This function can be called to connect the active variables of the object
    * to an output TTree. It can be called multiple times, then the variables
    * will be written to multiple TTrees.
    *
    * @param tree Pointer to the TTree where the variables should be written
    */
   void FakeD3PDObject::WriteTo( TTree* tree ) {

      EventNumber.WriteTo( tree );
      LepId.WriteTo( tree );
      LepTight.WriteTo( tree );
      lepN.WriteTo( tree );
      lepPx.WriteTo( tree );
      lepPy.WriteTo( tree );
      lepPz.WriteTo( tree );
      lepPt.WriteTo( tree );
      lepE.WriteTo( tree );
      jetN.WriteTo( tree );
      jetPx.WriteTo( tree );
      jetPy.WriteTo( tree );
      jetPz.WriteTo( tree );
      jetPt.WriteTo( tree );
      jetE.WriteTo( tree );
      jetJVF.WriteTo( tree );
      JetFitterCOMBNN.WriteTo( tree );
      thisMETx.WriteTo( tree );
      thisMETy.WriteTo( tree );
      missingET_rel.WriteTo( tree );
      mt2.WriteTo( tree );
      mll.WriteTo( tree );
      OS.WriteTo( tree );
      SS.WriteTo( tree );
      EE.WriteTo( tree );
      EM.WriteTo( tree );
      ME.WriteTo( tree );
      MM.WriteTo( tree );
      TT.WriteTo( tree );
      Tl.WriteTo( tree );
      lT.WriteTo( tree );
      ll.WriteTo( tree );
      wgts_rr_nom.WriteTo( tree );
      wgts_rf_nom.WriteTo( tree );
      wgts_fr_nom.WriteTo( tree );
      wgts_ff_nom.WriteTo( tree );
      wgts_rr_max.WriteTo( tree );
      wgts_rf_max.WriteTo( tree );
      wgts_fr_max.WriteTo( tree );
      wgts_ff_max.WriteTo( tree );
      wgts_rr_min.WriteTo( tree );
      wgts_rf_min.WriteTo( tree );
      wgts_fr_min.WriteTo( tree );
      wgts_ff_min.WriteTo( tree );
      wgts_rr_syst_nom.WriteTo( tree );
      wgts_rf_syst_nom.WriteTo( tree );
      wgts_fr_syst_nom.WriteTo( tree );
      wgts_ff_syst_nom.WriteTo( tree );
      wgts_rr_syst_max.WriteTo( tree );
      wgts_rf_syst_max.WriteTo( tree );
      wgts_fr_syst_max.WriteTo( tree );
      wgts_ff_syst_max.WriteTo( tree );
      wgts_rr_syst_min.WriteTo( tree );
      wgts_rf_syst_min.WriteTo( tree );
      wgts_fr_syst_min.WriteTo( tree );
      wgts_ff_syst_min.WriteTo( tree );
      region.WriteTo( tree );
      region_SIGT.WriteTo( tree );

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
   void FakeD3PDObject::SetActive( ::Bool_t active, const ::TString& pattern ) {

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
   void FakeD3PDObject::ReadAllActive() {

      // Check if it makes sense to call this function:
      if( ! fFromInput ) {
         static ::Bool_t wPrinted = kFALSE;
         if( ! wPrinted ) {
            Warning( "ReadAllActive", "Function only meaningful when used on objects" );
            Warning( "ReadAllActive", "which are used to read information from a D3PD" );
            wPrinted = kTRUE;
         }
      }

      if( EventNumber.IsActive() ) EventNumber();
      if( LepId.IsActive() ) LepId();
      if( LepTight.IsActive() ) LepTight();
      if( lepN.IsActive() ) lepN();
      if( lepPx.IsActive() ) lepPx();
      if( lepPy.IsActive() ) lepPy();
      if( lepPz.IsActive() ) lepPz();
      if( lepPt.IsActive() ) lepPt();
      if( lepE.IsActive() ) lepE();
      if( jetN.IsActive() ) jetN();
      if( jetPx.IsActive() ) jetPx();
      if( jetPy.IsActive() ) jetPy();
      if( jetPz.IsActive() ) jetPz();
      if( jetPt.IsActive() ) jetPt();
      if( jetE.IsActive() ) jetE();
      if( jetJVF.IsActive() ) jetJVF();
      if( JetFitterCOMBNN.IsActive() ) JetFitterCOMBNN();
      if( thisMETx.IsActive() ) thisMETx();
      if( thisMETy.IsActive() ) thisMETy();
      if( missingET_rel.IsActive() ) missingET_rel();
      if( mt2.IsActive() ) mt2();
      if( mll.IsActive() ) mll();
      if( OS.IsActive() ) OS();
      if( SS.IsActive() ) SS();
      if( EE.IsActive() ) EE();
      if( EM.IsActive() ) EM();
      if( ME.IsActive() ) ME();
      if( MM.IsActive() ) MM();
      if( TT.IsActive() ) TT();
      if( Tl.IsActive() ) Tl();
      if( lT.IsActive() ) lT();
      if( ll.IsActive() ) ll();
      if( wgts_rr_nom.IsActive() ) wgts_rr_nom();
      if( wgts_rf_nom.IsActive() ) wgts_rf_nom();
      if( wgts_fr_nom.IsActive() ) wgts_fr_nom();
      if( wgts_ff_nom.IsActive() ) wgts_ff_nom();
      if( wgts_rr_max.IsActive() ) wgts_rr_max();
      if( wgts_rf_max.IsActive() ) wgts_rf_max();
      if( wgts_fr_max.IsActive() ) wgts_fr_max();
      if( wgts_ff_max.IsActive() ) wgts_ff_max();
      if( wgts_rr_min.IsActive() ) wgts_rr_min();
      if( wgts_rf_min.IsActive() ) wgts_rf_min();
      if( wgts_fr_min.IsActive() ) wgts_fr_min();
      if( wgts_ff_min.IsActive() ) wgts_ff_min();
      if( wgts_rr_syst_nom.IsActive() ) wgts_rr_syst_nom();
      if( wgts_rf_syst_nom.IsActive() ) wgts_rf_syst_nom();
      if( wgts_fr_syst_nom.IsActive() ) wgts_fr_syst_nom();
      if( wgts_ff_syst_nom.IsActive() ) wgts_ff_syst_nom();
      if( wgts_rr_syst_max.IsActive() ) wgts_rr_syst_max();
      if( wgts_rf_syst_max.IsActive() ) wgts_rf_syst_max();
      if( wgts_fr_syst_max.IsActive() ) wgts_fr_syst_max();
      if( wgts_ff_syst_max.IsActive() ) wgts_ff_syst_max();
      if( wgts_rr_syst_min.IsActive() ) wgts_rr_syst_min();
      if( wgts_rf_syst_min.IsActive() ) wgts_rf_syst_min();
      if( wgts_fr_syst_min.IsActive() ) wgts_fr_syst_min();
      if( wgts_ff_syst_min.IsActive() ) wgts_ff_syst_min();
      if( region.IsActive() ) region();
      if( region_SIGT.IsActive() ) region_SIGT();

      return;
   }

} // namespace D3PDReader
