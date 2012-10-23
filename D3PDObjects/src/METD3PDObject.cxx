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
        RefGamma_etx_CentralReg( this, ::TString( prefix ) + "RefGamma_etx_CentralReg", &master ),
        RefGamma_ety_CentralReg( this, ::TString( prefix ) + "RefGamma_ety_CentralReg", &master ),
        RefGamma_sumet_CentralReg( this, ::TString( prefix ) + "RefGamma_sumet_CentralReg", &master ),
        RefGamma_phi_CentralReg( this, ::TString( prefix ) + "RefGamma_phi_CentralReg", &master ),
        RefGamma_etx_EndcapRegion( this, ::TString( prefix ) + "RefGamma_etx_EndcapRegion", &master ),
        RefGamma_ety_EndcapRegion( this, ::TString( prefix ) + "RefGamma_ety_EndcapRegion", &master ),
        RefGamma_sumet_EndcapRegion( this, ::TString( prefix ) + "RefGamma_sumet_EndcapRegion", &master ),
        RefGamma_phi_EndcapRegion( this, ::TString( prefix ) + "RefGamma_phi_EndcapRegion", &master ),
        RefGamma_etx_ForwardReg( this, ::TString( prefix ) + "RefGamma_etx_ForwardReg", &master ),
        RefGamma_ety_ForwardReg( this, ::TString( prefix ) + "RefGamma_ety_ForwardReg", &master ),
        RefGamma_sumet_ForwardReg( this, ::TString( prefix ) + "RefGamma_sumet_ForwardReg", &master ),
        RefGamma_phi_ForwardReg( this, ::TString( prefix ) + "RefGamma_phi_ForwardReg", &master ),
        STVF_RefGamma_etx( this, ::TString( prefix ) + "STVF_RefGamma_etx", &master ),
        STVF_RefGamma_ety( this, ::TString( prefix ) + "STVF_RefGamma_ety", &master ),
        STVF_RefGamma_sumet( this, ::TString( prefix ) + "STVF_RefGamma_sumet", &master ),
        STVF_RefGamma_etx_CentralReg( this, ::TString( prefix ) + "STVF_RefGamma_etx_CentralReg", &master ),
        STVF_RefGamma_ety_CentralReg( this, ::TString( prefix ) + "STVF_RefGamma_ety_CentralReg", &master ),
        STVF_RefGamma_sumet_CentralReg( this, ::TString( prefix ) + "STVF_RefGamma_sumet_CentralReg", &master ),
        STVF_RefGamma_phi_CentralReg( this, ::TString( prefix ) + "STVF_RefGamma_phi_CentralReg", &master ),
        STVF_RefGamma_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_RefGamma_etx_EndcapRegion", &master ),
        STVF_RefGamma_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_RefGamma_ety_EndcapRegion", &master ),
        STVF_RefGamma_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_RefGamma_sumet_EndcapRegion", &master ),
        STVF_RefGamma_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_RefGamma_phi_EndcapRegion", &master ),
        STVF_RefGamma_etx_ForwardReg( this, ::TString( prefix ) + "STVF_RefGamma_etx_ForwardReg", &master ),
        STVF_RefGamma_ety_ForwardReg( this, ::TString( prefix ) + "STVF_RefGamma_ety_ForwardReg", &master ),
        STVF_RefGamma_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_RefGamma_sumet_ForwardReg", &master ),
        STVF_RefGamma_phi_ForwardReg( this, ::TString( prefix ) + "STVF_RefGamma_phi_ForwardReg", &master ),
        RefFinal_etx( this, ::TString( prefix ) + "RefFinal_etx", &master ),
        RefFinal_ety( this, ::TString( prefix ) + "RefFinal_ety", &master ),
        RefFinal_sumet( this, ::TString( prefix ) + "RefFinal_sumet", &master ),
        RefFinal_etx_CentralReg( this, ::TString( prefix ) + "RefFinal_etx_CentralReg", &master ),
        RefFinal_ety_CentralReg( this, ::TString( prefix ) + "RefFinal_ety_CentralReg", &master ),
        RefFinal_sumet_CentralReg( this, ::TString( prefix ) + "RefFinal_sumet_CentralReg", &master ),
        RefFinal_phi_CentralReg( this, ::TString( prefix ) + "RefFinal_phi_CentralReg", &master ),
        RefFinal_etx_EndcapRegion( this, ::TString( prefix ) + "RefFinal_etx_EndcapRegion", &master ),
        RefFinal_ety_EndcapRegion( this, ::TString( prefix ) + "RefFinal_ety_EndcapRegion", &master ),
        RefFinal_sumet_EndcapRegion( this, ::TString( prefix ) + "RefFinal_sumet_EndcapRegion", &master ),
        RefFinal_phi_EndcapRegion( this, ::TString( prefix ) + "RefFinal_phi_EndcapRegion", &master ),
        RefFinal_etx_ForwardReg( this, ::TString( prefix ) + "RefFinal_etx_ForwardReg", &master ),
        RefFinal_ety_ForwardReg( this, ::TString( prefix ) + "RefFinal_ety_ForwardReg", &master ),
        RefFinal_sumet_ForwardReg( this, ::TString( prefix ) + "RefFinal_sumet_ForwardReg", &master ),
        RefFinal_phi_ForwardReg( this, ::TString( prefix ) + "RefFinal_phi_ForwardReg", &master ),
        STVF_RefFinal_etx( this, ::TString( prefix ) + "STVF_RefFinal_etx", &master ),
        STVF_RefFinal_ety( this, ::TString( prefix ) + "STVF_RefFinal_ety", &master ),
        STVF_RefFinal_sumet( this, ::TString( prefix ) + "STVF_RefFinal_sumet", &master ),
        STVF_RefFinal_etx_CentralReg( this, ::TString( prefix ) + "STVF_RefFinal_etx_CentralReg", &master ),
        STVF_RefFinal_ety_CentralReg( this, ::TString( prefix ) + "STVF_RefFinal_ety_CentralReg", &master ),
        STVF_RefFinal_sumet_CentralReg( this, ::TString( prefix ) + "STVF_RefFinal_sumet_CentralReg", &master ),
        STVF_RefFinal_phi_CentralReg( this, ::TString( prefix ) + "STVF_RefFinal_phi_CentralReg", &master ),
        STVF_RefFinal_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_RefFinal_etx_EndcapRegion", &master ),
        STVF_RefFinal_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_RefFinal_ety_EndcapRegion", &master ),
        STVF_RefFinal_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_RefFinal_sumet_EndcapRegion", &master ),
        STVF_RefFinal_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_RefFinal_phi_EndcapRegion", &master ),
        STVF_RefFinal_etx_ForwardReg( this, ::TString( prefix ) + "STVF_RefFinal_etx_ForwardReg", &master ),
        STVF_RefFinal_ety_ForwardReg( this, ::TString( prefix ) + "STVF_RefFinal_ety_ForwardReg", &master ),
        STVF_RefFinal_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_RefFinal_sumet_ForwardReg", &master ),
        STVF_RefFinal_phi_ForwardReg( this, ::TString( prefix ) + "STVF_RefFinal_phi_ForwardReg", &master ),
        RefJet_etx( this, ::TString( prefix ) + "RefJet_etx", &master ),
        RefJet_ety( this, ::TString( prefix ) + "RefJet_ety", &master ),
        RefJet_sumet( this, ::TString( prefix ) + "RefJet_sumet", &master ),
        RefJet_etx_CentralReg( this, ::TString( prefix ) + "RefJet_etx_CentralReg", &master ),
        RefJet_ety_CentralReg( this, ::TString( prefix ) + "RefJet_ety_CentralReg", &master ),
        RefJet_sumet_CentralReg( this, ::TString( prefix ) + "RefJet_sumet_CentralReg", &master ),
        RefJet_phi_CentralReg( this, ::TString( prefix ) + "RefJet_phi_CentralReg", &master ),
        RefJet_etx_EndcapRegion( this, ::TString( prefix ) + "RefJet_etx_EndcapRegion", &master ),
        RefJet_ety_EndcapRegion( this, ::TString( prefix ) + "RefJet_ety_EndcapRegion", &master ),
        RefJet_sumet_EndcapRegion( this, ::TString( prefix ) + "RefJet_sumet_EndcapRegion", &master ),
        RefJet_phi_EndcapRegion( this, ::TString( prefix ) + "RefJet_phi_EndcapRegion", &master ),
        RefJet_etx_ForwardReg( this, ::TString( prefix ) + "RefJet_etx_ForwardReg", &master ),
        RefJet_ety_ForwardReg( this, ::TString( prefix ) + "RefJet_ety_ForwardReg", &master ),
        RefJet_sumet_ForwardReg( this, ::TString( prefix ) + "RefJet_sumet_ForwardReg", &master ),
        RefJet_phi_ForwardReg( this, ::TString( prefix ) + "RefJet_phi_ForwardReg", &master ),
        STVF_RefJet_etx( this, ::TString( prefix ) + "STVF_RefJet_etx", &master ),
        STVF_RefJet_ety( this, ::TString( prefix ) + "STVF_RefJet_ety", &master ),
        STVF_RefJet_sumet( this, ::TString( prefix ) + "STVF_RefJet_sumet", &master ),
        STVF_RefJet_etx_CentralReg( this, ::TString( prefix ) + "STVF_RefJet_etx_CentralReg", &master ),
        STVF_RefJet_ety_CentralReg( this, ::TString( prefix ) + "STVF_RefJet_ety_CentralReg", &master ),
        STVF_RefJet_sumet_CentralReg( this, ::TString( prefix ) + "STVF_RefJet_sumet_CentralReg", &master ),
        STVF_RefJet_phi_CentralReg( this, ::TString( prefix ) + "STVF_RefJet_phi_CentralReg", &master ),
        STVF_RefJet_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_RefJet_etx_EndcapRegion", &master ),
        STVF_RefJet_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_RefJet_ety_EndcapRegion", &master ),
        STVF_RefJet_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_RefJet_sumet_EndcapRegion", &master ),
        STVF_RefJet_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_RefJet_phi_EndcapRegion", &master ),
        STVF_RefJet_etx_ForwardReg( this, ::TString( prefix ) + "STVF_RefJet_etx_ForwardReg", &master ),
        STVF_RefJet_ety_ForwardReg( this, ::TString( prefix ) + "STVF_RefJet_ety_ForwardReg", &master ),
        STVF_RefJet_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_RefJet_sumet_ForwardReg", &master ),
        STVF_RefJet_phi_ForwardReg( this, ::TString( prefix ) + "STVF_RefJet_phi_ForwardReg", &master ),
        RefEle_etx( this, ::TString( prefix ) + "RefEle_etx", &master ),
        RefEle_ety( this, ::TString( prefix ) + "RefEle_ety", &master ),
        RefEle_sumet( this, ::TString( prefix ) + "RefEle_sumet", &master ),
        RefEle_etx_CentralReg( this, ::TString( prefix ) + "RefEle_etx_CentralReg", &master ),
        RefEle_ety_CentralReg( this, ::TString( prefix ) + "RefEle_ety_CentralReg", &master ),
        RefEle_sumet_CentralReg( this, ::TString( prefix ) + "RefEle_sumet_CentralReg", &master ),
        RefEle_phi_CentralReg( this, ::TString( prefix ) + "RefEle_phi_CentralReg", &master ),
        RefEle_etx_EndcapRegion( this, ::TString( prefix ) + "RefEle_etx_EndcapRegion", &master ),
        RefEle_ety_EndcapRegion( this, ::TString( prefix ) + "RefEle_ety_EndcapRegion", &master ),
        RefEle_sumet_EndcapRegion( this, ::TString( prefix ) + "RefEle_sumet_EndcapRegion", &master ),
        RefEle_phi_EndcapRegion( this, ::TString( prefix ) + "RefEle_phi_EndcapRegion", &master ),
        RefEle_etx_ForwardReg( this, ::TString( prefix ) + "RefEle_etx_ForwardReg", &master ),
        RefEle_ety_ForwardReg( this, ::TString( prefix ) + "RefEle_ety_ForwardReg", &master ),
        RefEle_sumet_ForwardReg( this, ::TString( prefix ) + "RefEle_sumet_ForwardReg", &master ),
        RefEle_phi_ForwardReg( this, ::TString( prefix ) + "RefEle_phi_ForwardReg", &master ),
        STVF_RefEle_etx( this, ::TString( prefix ) + "STVF_RefEle_etx", &master ),
        STVF_RefEle_ety( this, ::TString( prefix ) + "STVF_RefEle_ety", &master ),
        STVF_RefEle_sumet( this, ::TString( prefix ) + "STVF_RefEle_sumet", &master ),
        STVF_RefEle_etx_CentralReg( this, ::TString( prefix ) + "STVF_RefEle_etx_CentralReg", &master ),
        STVF_RefEle_ety_CentralReg( this, ::TString( prefix ) + "STVF_RefEle_ety_CentralReg", &master ),
        STVF_RefEle_sumet_CentralReg( this, ::TString( prefix ) + "STVF_RefEle_sumet_CentralReg", &master ),
        STVF_RefEle_phi_CentralReg( this, ::TString( prefix ) + "STVF_RefEle_phi_CentralReg", &master ),
        STVF_RefEle_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_RefEle_etx_EndcapRegion", &master ),
        STVF_RefEle_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_RefEle_ety_EndcapRegion", &master ),
        STVF_RefEle_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_RefEle_sumet_EndcapRegion", &master ),
        STVF_RefEle_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_RefEle_phi_EndcapRegion", &master ),
        STVF_RefEle_etx_ForwardReg( this, ::TString( prefix ) + "STVF_RefEle_etx_ForwardReg", &master ),
        STVF_RefEle_ety_ForwardReg( this, ::TString( prefix ) + "STVF_RefEle_ety_ForwardReg", &master ),
        STVF_RefEle_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_RefEle_sumet_ForwardReg", &master ),
        STVF_RefEle_phi_ForwardReg( this, ::TString( prefix ) + "STVF_RefEle_phi_ForwardReg", &master ),
        Muon_Total_Staco_etx( this, ::TString( prefix ) + "Muon_Total_Staco_etx", &master ),
        Muon_Total_Staco_ety( this, ::TString( prefix ) + "Muon_Total_Staco_ety", &master ),
        Muon_Total_Staco_sumet( this, ::TString( prefix ) + "Muon_Total_Staco_sumet", &master ),
        Muon_Total_Staco_etx_CentralReg( this, ::TString( prefix ) + "Muon_Total_Staco_etx_CentralReg", &master ),
        Muon_Total_Staco_ety_CentralReg( this, ::TString( prefix ) + "Muon_Total_Staco_ety_CentralReg", &master ),
        Muon_Total_Staco_sumet_CentralReg( this, ::TString( prefix ) + "Muon_Total_Staco_sumet_CentralReg", &master ),
        Muon_Total_Staco_phi_CentralReg( this, ::TString( prefix ) + "Muon_Total_Staco_phi_CentralReg", &master ),
        Muon_Total_Staco_etx_EndcapRegion( this, ::TString( prefix ) + "Muon_Total_Staco_etx_EndcapRegion", &master ),
        Muon_Total_Staco_ety_EndcapRegion( this, ::TString( prefix ) + "Muon_Total_Staco_ety_EndcapRegion", &master ),
        Muon_Total_Staco_sumet_EndcapRegion( this, ::TString( prefix ) + "Muon_Total_Staco_sumet_EndcapRegion", &master ),
        Muon_Total_Staco_phi_EndcapRegion( this, ::TString( prefix ) + "Muon_Total_Staco_phi_EndcapRegion", &master ),
        Muon_Total_Staco_etx_ForwardReg( this, ::TString( prefix ) + "Muon_Total_Staco_etx_ForwardReg", &master ),
        Muon_Total_Staco_ety_ForwardReg( this, ::TString( prefix ) + "Muon_Total_Staco_ety_ForwardReg", &master ),
        Muon_Total_Staco_sumet_ForwardReg( this, ::TString( prefix ) + "Muon_Total_Staco_sumet_ForwardReg", &master ),
        Muon_Total_Staco_phi_ForwardReg( this, ::TString( prefix ) + "Muon_Total_Staco_phi_ForwardReg", &master ),
        STVF_Muon_Total_Staco_etx( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_etx", &master ),
        STVF_Muon_Total_Staco_ety( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_ety", &master ),
        STVF_Muon_Total_Staco_sumet( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_sumet", &master ),
        STVF_Muon_Total_Staco_etx_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_etx_CentralReg", &master ),
        STVF_Muon_Total_Staco_ety_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_ety_CentralReg", &master ),
        STVF_Muon_Total_Staco_sumet_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_sumet_CentralReg", &master ),
        STVF_Muon_Total_Staco_phi_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_phi_CentralReg", &master ),
        STVF_Muon_Total_Staco_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_etx_EndcapRegion", &master ),
        STVF_Muon_Total_Staco_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_ety_EndcapRegion", &master ),
        STVF_Muon_Total_Staco_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_sumet_EndcapRegion", &master ),
        STVF_Muon_Total_Staco_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_phi_EndcapRegion", &master ),
        STVF_Muon_Total_Staco_etx_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_etx_ForwardReg", &master ),
        STVF_Muon_Total_Staco_ety_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_ety_ForwardReg", &master ),
        STVF_Muon_Total_Staco_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_sumet_ForwardReg", &master ),
        STVF_Muon_Total_Staco_phi_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_phi_ForwardReg", &master ),
        Muon_Isol_Staco_etx( this, ::TString( prefix ) + "Muon_Isol_Staco_etx", &master ),
        Muon_Isol_Staco_ety( this, ::TString( prefix ) + "Muon_Isol_Staco_ety", &master ),
        Muon_Isol_Staco_sumet( this, ::TString( prefix ) + "Muon_Isol_Staco_sumet", &master ),
        Muon_Isol_Staco_etx_CentralReg( this, ::TString( prefix ) + "Muon_Isol_Staco_etx_CentralReg", &master ),
        Muon_Isol_Staco_ety_CentralReg( this, ::TString( prefix ) + "Muon_Isol_Staco_ety_CentralReg", &master ),
        Muon_Isol_Staco_sumet_CentralReg( this, ::TString( prefix ) + "Muon_Isol_Staco_sumet_CentralReg", &master ),
        Muon_Isol_Staco_phi_CentralReg( this, ::TString( prefix ) + "Muon_Isol_Staco_phi_CentralReg", &master ),
        Muon_Isol_Staco_etx_EndcapRegion( this, ::TString( prefix ) + "Muon_Isol_Staco_etx_EndcapRegion", &master ),
        Muon_Isol_Staco_ety_EndcapRegion( this, ::TString( prefix ) + "Muon_Isol_Staco_ety_EndcapRegion", &master ),
        Muon_Isol_Staco_sumet_EndcapRegion( this, ::TString( prefix ) + "Muon_Isol_Staco_sumet_EndcapRegion", &master ),
        Muon_Isol_Staco_phi_EndcapRegion( this, ::TString( prefix ) + "Muon_Isol_Staco_phi_EndcapRegion", &master ),
        Muon_Isol_Staco_etx_ForwardReg( this, ::TString( prefix ) + "Muon_Isol_Staco_etx_ForwardReg", &master ),
        Muon_Isol_Staco_ety_ForwardReg( this, ::TString( prefix ) + "Muon_Isol_Staco_ety_ForwardReg", &master ),
        Muon_Isol_Staco_sumet_ForwardReg( this, ::TString( prefix ) + "Muon_Isol_Staco_sumet_ForwardReg", &master ),
        Muon_Isol_Staco_phi_ForwardReg( this, ::TString( prefix ) + "Muon_Isol_Staco_phi_ForwardReg", &master ),
        STVF_Muon_Isol_Staco_etx( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_etx", &master ),
        STVF_Muon_Isol_Staco_ety( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_ety", &master ),
        STVF_Muon_Isol_Staco_sumet( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_sumet", &master ),
        STVF_Muon_Isol_Staco_etx_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_etx_CentralReg", &master ),
        STVF_Muon_Isol_Staco_ety_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_ety_CentralReg", &master ),
        STVF_Muon_Isol_Staco_sumet_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_sumet_CentralReg", &master ),
        STVF_Muon_Isol_Staco_phi_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_phi_CentralReg", &master ),
        STVF_Muon_Isol_Staco_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_etx_EndcapRegion", &master ),
        STVF_Muon_Isol_Staco_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_ety_EndcapRegion", &master ),
        STVF_Muon_Isol_Staco_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_sumet_EndcapRegion", &master ),
        STVF_Muon_Isol_Staco_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_phi_EndcapRegion", &master ),
        STVF_Muon_Isol_Staco_etx_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_etx_ForwardReg", &master ),
        STVF_Muon_Isol_Staco_ety_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_ety_ForwardReg", &master ),
        STVF_Muon_Isol_Staco_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_sumet_ForwardReg", &master ),
        STVF_Muon_Isol_Staco_phi_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_phi_ForwardReg", &master ),
        Muon_NonIsol_Staco_etx( this, ::TString( prefix ) + "Muon_NonIsol_Staco_etx", &master ),
        Muon_NonIsol_Staco_ety( this, ::TString( prefix ) + "Muon_NonIsol_Staco_ety", &master ),
        Muon_NonIsol_Staco_sumet( this, ::TString( prefix ) + "Muon_NonIsol_Staco_sumet", &master ),
        Muon_NonIsol_Staco_etx_CentralReg( this, ::TString( prefix ) + "Muon_NonIsol_Staco_etx_CentralReg", &master ),
        Muon_NonIsol_Staco_ety_CentralReg( this, ::TString( prefix ) + "Muon_NonIsol_Staco_ety_CentralReg", &master ),
        Muon_NonIsol_Staco_sumet_CentralReg( this, ::TString( prefix ) + "Muon_NonIsol_Staco_sumet_CentralReg", &master ),
        Muon_NonIsol_Staco_phi_CentralReg( this, ::TString( prefix ) + "Muon_NonIsol_Staco_phi_CentralReg", &master ),
        Muon_NonIsol_Staco_etx_EndcapRegion( this, ::TString( prefix ) + "Muon_NonIsol_Staco_etx_EndcapRegion", &master ),
        Muon_NonIsol_Staco_ety_EndcapRegion( this, ::TString( prefix ) + "Muon_NonIsol_Staco_ety_EndcapRegion", &master ),
        Muon_NonIsol_Staco_sumet_EndcapRegion( this, ::TString( prefix ) + "Muon_NonIsol_Staco_sumet_EndcapRegion", &master ),
        Muon_NonIsol_Staco_phi_EndcapRegion( this, ::TString( prefix ) + "Muon_NonIsol_Staco_phi_EndcapRegion", &master ),
        Muon_NonIsol_Staco_etx_ForwardReg( this, ::TString( prefix ) + "Muon_NonIsol_Staco_etx_ForwardReg", &master ),
        Muon_NonIsol_Staco_ety_ForwardReg( this, ::TString( prefix ) + "Muon_NonIsol_Staco_ety_ForwardReg", &master ),
        Muon_NonIsol_Staco_sumet_ForwardReg( this, ::TString( prefix ) + "Muon_NonIsol_Staco_sumet_ForwardReg", &master ),
        Muon_NonIsol_Staco_phi_ForwardReg( this, ::TString( prefix ) + "Muon_NonIsol_Staco_phi_ForwardReg", &master ),
        STVF_Muon_NonIsol_Staco_etx( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_etx", &master ),
        STVF_Muon_NonIsol_Staco_ety( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_ety", &master ),
        STVF_Muon_NonIsol_Staco_sumet( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_sumet", &master ),
        STVF_Muon_NonIsol_Staco_etx_CentralReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_etx_CentralReg", &master ),
        STVF_Muon_NonIsol_Staco_ety_CentralReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_ety_CentralReg", &master ),
        STVF_Muon_NonIsol_Staco_sumet_CentralReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_sumet_CentralReg", &master ),
        STVF_Muon_NonIsol_Staco_phi_CentralReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_phi_CentralReg", &master ),
        STVF_Muon_NonIsol_Staco_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_etx_EndcapRegion", &master ),
        STVF_Muon_NonIsol_Staco_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_ety_EndcapRegion", &master ),
        STVF_Muon_NonIsol_Staco_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_sumet_EndcapRegion", &master ),
        STVF_Muon_NonIsol_Staco_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_phi_EndcapRegion", &master ),
        STVF_Muon_NonIsol_Staco_etx_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_etx_ForwardReg", &master ),
        STVF_Muon_NonIsol_Staco_ety_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_ety_ForwardReg", &master ),
        STVF_Muon_NonIsol_Staco_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_sumet_ForwardReg", &master ),
        STVF_Muon_NonIsol_Staco_phi_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_phi_ForwardReg", &master ),
        CellOut_etx( this, ::TString( prefix ) + "CellOut_etx", &master ),
        CellOut_ety( this, ::TString( prefix ) + "CellOut_ety", &master ),
        CellOut_sumet( this, ::TString( prefix ) + "CellOut_sumet", &master ),
        CellOut_etx_CentralReg( this, ::TString( prefix ) + "CellOut_etx_CentralReg", &master ),
        CellOut_ety_CentralReg( this, ::TString( prefix ) + "CellOut_ety_CentralReg", &master ),
        CellOut_sumet_CentralReg( this, ::TString( prefix ) + "CellOut_sumet_CentralReg", &master ),
        CellOut_phi_CentralReg( this, ::TString( prefix ) + "CellOut_phi_CentralReg", &master ),
        CellOut_etx_EndcapRegion( this, ::TString( prefix ) + "CellOut_etx_EndcapRegion", &master ),
        CellOut_ety_EndcapRegion( this, ::TString( prefix ) + "CellOut_ety_EndcapRegion", &master ),
        CellOut_sumet_EndcapRegion( this, ::TString( prefix ) + "CellOut_sumet_EndcapRegion", &master ),
        CellOut_phi_EndcapRegion( this, ::TString( prefix ) + "CellOut_phi_EndcapRegion", &master ),
        CellOut_etx_ForwardReg( this, ::TString( prefix ) + "CellOut_etx_ForwardReg", &master ),
        CellOut_ety_ForwardReg( this, ::TString( prefix ) + "CellOut_ety_ForwardReg", &master ),
        CellOut_sumet_ForwardReg( this, ::TString( prefix ) + "CellOut_sumet_ForwardReg", &master ),
        CellOut_phi_ForwardReg( this, ::TString( prefix ) + "CellOut_phi_ForwardReg", &master ),
        STVF_CellOut_etx( this, ::TString( prefix ) + "STVF_CellOut_etx", &master ),
        STVF_CellOut_ety( this, ::TString( prefix ) + "STVF_CellOut_ety", &master ),
        STVF_CellOut_sumet( this, ::TString( prefix ) + "STVF_CellOut_sumet", &master ),
        STVF_CellOut_etx_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_etx_CentralReg", &master ),
        STVF_CellOut_ety_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_ety_CentralReg", &master ),
        STVF_CellOut_sumet_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_sumet_CentralReg", &master ),
        STVF_CellOut_phi_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_phi_CentralReg", &master ),
        STVF_CellOut_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_etx_EndcapRegion", &master ),
        STVF_CellOut_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_ety_EndcapRegion", &master ),
        STVF_CellOut_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_sumet_EndcapRegion", &master ),
        STVF_CellOut_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_phi_EndcapRegion", &master ),
        STVF_CellOut_etx_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_etx_ForwardReg", &master ),
        STVF_CellOut_ety_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_ety_ForwardReg", &master ),
        STVF_CellOut_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_sumet_ForwardReg", &master ),
        STVF_CellOut_phi_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_phi_ForwardReg", &master ),
        Muon_Isol_Muid_etx( this, ::TString( prefix ) + "Muon_Isol_Muid_etx", &master ),
        Muon_Isol_Muid_ety( this, ::TString( prefix ) + "Muon_Isol_Muid_ety", &master ),
        Muon_Isol_Muid_sumet( this, ::TString( prefix ) + "Muon_Isol_Muid_sumet", &master ),
        Muon_Isol_Muid_etx_CentralReg( this, ::TString( prefix ) + "Muon_Isol_Muid_etx_CentralReg", &master ),
        Muon_Isol_Muid_ety_CentralReg( this, ::TString( prefix ) + "Muon_Isol_Muid_ety_CentralReg", &master ),
        Muon_Isol_Muid_sumet_CentralReg( this, ::TString( prefix ) + "Muon_Isol_Muid_sumet_CentralReg", &master ),
        Muon_Isol_Muid_phi_CentralReg( this, ::TString( prefix ) + "Muon_Isol_Muid_phi_CentralReg", &master ),
        Muon_Isol_Muid_etx_EndcapRegion( this, ::TString( prefix ) + "Muon_Isol_Muid_etx_EndcapRegion", &master ),
        Muon_Isol_Muid_ety_EndcapRegion( this, ::TString( prefix ) + "Muon_Isol_Muid_ety_EndcapRegion", &master ),
        Muon_Isol_Muid_sumet_EndcapRegion( this, ::TString( prefix ) + "Muon_Isol_Muid_sumet_EndcapRegion", &master ),
        Muon_Isol_Muid_phi_EndcapRegion( this, ::TString( prefix ) + "Muon_Isol_Muid_phi_EndcapRegion", &master ),
        Muon_Isol_Muid_etx_ForwardReg( this, ::TString( prefix ) + "Muon_Isol_Muid_etx_ForwardReg", &master ),
        Muon_Isol_Muid_ety_ForwardReg( this, ::TString( prefix ) + "Muon_Isol_Muid_ety_ForwardReg", &master ),
        Muon_Isol_Muid_sumet_ForwardReg( this, ::TString( prefix ) + "Muon_Isol_Muid_sumet_ForwardReg", &master ),
        Muon_Isol_Muid_phi_ForwardReg( this, ::TString( prefix ) + "Muon_Isol_Muid_phi_ForwardReg", &master ),
        STVF_Muon_Isol_Muid_etx( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_etx", &master ),
        STVF_Muon_Isol_Muid_ety( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_ety", &master ),
        STVF_Muon_Isol_Muid_sumet( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_sumet", &master ),
        STVF_Muon_Isol_Muid_etx_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_etx_CentralReg", &master ),
        STVF_Muon_Isol_Muid_ety_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_ety_CentralReg", &master ),
        STVF_Muon_Isol_Muid_sumet_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_sumet_CentralReg", &master ),
        STVF_Muon_Isol_Muid_phi_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_phi_CentralReg", &master ),
        STVF_Muon_Isol_Muid_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_etx_EndcapRegion", &master ),
        STVF_Muon_Isol_Muid_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_ety_EndcapRegion", &master ),
        STVF_Muon_Isol_Muid_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_sumet_EndcapRegion", &master ),
        STVF_Muon_Isol_Muid_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_phi_EndcapRegion", &master ),
        STVF_Muon_Isol_Muid_etx_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_etx_ForwardReg", &master ),
        STVF_Muon_Isol_Muid_ety_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_ety_ForwardReg", &master ),
        STVF_Muon_Isol_Muid_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_sumet_ForwardReg", &master ),
        STVF_Muon_Isol_Muid_phi_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_phi_ForwardReg", &master ),
        Muon_NonIsol_Muid_etx( this, ::TString( prefix ) + "Muon_NonIsol_Muid_etx", &master ),
        Muon_NonIsol_Muid_ety( this, ::TString( prefix ) + "Muon_NonIsol_Muid_ety", &master ),
        Muon_NonIsol_Muid_sumet( this, ::TString( prefix ) + "Muon_NonIsol_Muid_sumet", &master ),
        Muon_NonIsol_Muid_etx_CentralReg( this, ::TString( prefix ) + "Muon_NonIsol_Muid_etx_CentralReg", &master ),
        Muon_NonIsol_Muid_ety_CentralReg( this, ::TString( prefix ) + "Muon_NonIsol_Muid_ety_CentralReg", &master ),
        Muon_NonIsol_Muid_sumet_CentralReg( this, ::TString( prefix ) + "Muon_NonIsol_Muid_sumet_CentralReg", &master ),
        Muon_NonIsol_Muid_phi_CentralReg( this, ::TString( prefix ) + "Muon_NonIsol_Muid_phi_CentralReg", &master ),
        Muon_NonIsol_Muid_etx_EndcapRegion( this, ::TString( prefix ) + "Muon_NonIsol_Muid_etx_EndcapRegion", &master ),
        Muon_NonIsol_Muid_ety_EndcapRegion( this, ::TString( prefix ) + "Muon_NonIsol_Muid_ety_EndcapRegion", &master ),
        Muon_NonIsol_Muid_sumet_EndcapRegion( this, ::TString( prefix ) + "Muon_NonIsol_Muid_sumet_EndcapRegion", &master ),
        Muon_NonIsol_Muid_phi_EndcapRegion( this, ::TString( prefix ) + "Muon_NonIsol_Muid_phi_EndcapRegion", &master ),
        Muon_NonIsol_Muid_etx_ForwardReg( this, ::TString( prefix ) + "Muon_NonIsol_Muid_etx_ForwardReg", &master ),
        Muon_NonIsol_Muid_ety_ForwardReg( this, ::TString( prefix ) + "Muon_NonIsol_Muid_ety_ForwardReg", &master ),
        Muon_NonIsol_Muid_sumet_ForwardReg( this, ::TString( prefix ) + "Muon_NonIsol_Muid_sumet_ForwardReg", &master ),
        Muon_NonIsol_Muid_phi_ForwardReg( this, ::TString( prefix ) + "Muon_NonIsol_Muid_phi_ForwardReg", &master ),
        STVF_Muon_NonIsol_Muid_etx( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_etx", &master ),
        STVF_Muon_NonIsol_Muid_ety( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_ety", &master ),
        STVF_Muon_NonIsol_Muid_sumet( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_sumet", &master ),
        STVF_Muon_NonIsol_Muid_etx_CentralReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_etx_CentralReg", &master ),
        STVF_Muon_NonIsol_Muid_ety_CentralReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_ety_CentralReg", &master ),
        STVF_Muon_NonIsol_Muid_sumet_CentralReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_sumet_CentralReg", &master ),
        STVF_Muon_NonIsol_Muid_phi_CentralReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_phi_CentralReg", &master ),
        STVF_Muon_NonIsol_Muid_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_etx_EndcapRegion", &master ),
        STVF_Muon_NonIsol_Muid_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_ety_EndcapRegion", &master ),
        STVF_Muon_NonIsol_Muid_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_sumet_EndcapRegion", &master ),
        STVF_Muon_NonIsol_Muid_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_phi_EndcapRegion", &master ),
        STVF_Muon_NonIsol_Muid_etx_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_etx_ForwardReg", &master ),
        STVF_Muon_NonIsol_Muid_ety_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_ety_ForwardReg", &master ),
        STVF_Muon_NonIsol_Muid_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_sumet_ForwardReg", &master ),
        STVF_Muon_NonIsol_Muid_phi_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_phi_ForwardReg", &master ),
        Muon_Total_Muid_etx( this, ::TString( prefix ) + "Muon_Total_Muid_etx", &master ),
        Muon_Total_Muid_ety( this, ::TString( prefix ) + "Muon_Total_Muid_ety", &master ),
        Muon_Total_Muid_sumet( this, ::TString( prefix ) + "Muon_Total_Muid_sumet", &master ),
        Muon_Total_Muid_etx_CentralReg( this, ::TString( prefix ) + "Muon_Total_Muid_etx_CentralReg", &master ),
        Muon_Total_Muid_ety_CentralReg( this, ::TString( prefix ) + "Muon_Total_Muid_ety_CentralReg", &master ),
        Muon_Total_Muid_sumet_CentralReg( this, ::TString( prefix ) + "Muon_Total_Muid_sumet_CentralReg", &master ),
        Muon_Total_Muid_phi_CentralReg( this, ::TString( prefix ) + "Muon_Total_Muid_phi_CentralReg", &master ),
        Muon_Total_Muid_etx_EndcapRegion( this, ::TString( prefix ) + "Muon_Total_Muid_etx_EndcapRegion", &master ),
        Muon_Total_Muid_ety_EndcapRegion( this, ::TString( prefix ) + "Muon_Total_Muid_ety_EndcapRegion", &master ),
        Muon_Total_Muid_sumet_EndcapRegion( this, ::TString( prefix ) + "Muon_Total_Muid_sumet_EndcapRegion", &master ),
        Muon_Total_Muid_phi_EndcapRegion( this, ::TString( prefix ) + "Muon_Total_Muid_phi_EndcapRegion", &master ),
        Muon_Total_Muid_etx_ForwardReg( this, ::TString( prefix ) + "Muon_Total_Muid_etx_ForwardReg", &master ),
        Muon_Total_Muid_ety_ForwardReg( this, ::TString( prefix ) + "Muon_Total_Muid_ety_ForwardReg", &master ),
        Muon_Total_Muid_sumet_ForwardReg( this, ::TString( prefix ) + "Muon_Total_Muid_sumet_ForwardReg", &master ),
        Muon_Total_Muid_phi_ForwardReg( this, ::TString( prefix ) + "Muon_Total_Muid_phi_ForwardReg", &master ),
        STVF_Muon_Total_Muid_etx( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_etx", &master ),
        STVF_Muon_Total_Muid_ety( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_ety", &master ),
        STVF_Muon_Total_Muid_sumet( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_sumet", &master ),
        STVF_Muon_Total_Muid_etx_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_etx_CentralReg", &master ),
        STVF_Muon_Total_Muid_ety_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_ety_CentralReg", &master ),
        STVF_Muon_Total_Muid_sumet_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_sumet_CentralReg", &master ),
        STVF_Muon_Total_Muid_phi_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_phi_CentralReg", &master ),
        STVF_Muon_Total_Muid_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_etx_EndcapRegion", &master ),
        STVF_Muon_Total_Muid_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_ety_EndcapRegion", &master ),
        STVF_Muon_Total_Muid_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_sumet_EndcapRegion", &master ),
        STVF_Muon_Total_Muid_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_phi_EndcapRegion", &master ),
        STVF_Muon_Total_Muid_etx_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_etx_ForwardReg", &master ),
        STVF_Muon_Total_Muid_ety_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_ety_ForwardReg", &master ),
        STVF_Muon_Total_Muid_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_sumet_ForwardReg", &master ),
        STVF_Muon_Total_Muid_phi_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_phi_ForwardReg", &master ),
        Track_etx( this, ::TString( prefix ) + "Track_etx", &master ),
        Track_ety( this, ::TString( prefix ) + "Track_ety", &master ),
        Track_sumet( this, ::TString( prefix ) + "Track_sumet", &master ),
        Track_etx_CentralReg( this, ::TString( prefix ) + "Track_etx_CentralReg", &master ),
        Track_ety_CentralReg( this, ::TString( prefix ) + "Track_ety_CentralReg", &master ),
        Track_sumet_CentralReg( this, ::TString( prefix ) + "Track_sumet_CentralReg", &master ),
        Track_phi_CentralReg( this, ::TString( prefix ) + "Track_phi_CentralReg", &master ),
        Track_etx_EndcapRegion( this, ::TString( prefix ) + "Track_etx_EndcapRegion", &master ),
        Track_ety_EndcapRegion( this, ::TString( prefix ) + "Track_ety_EndcapRegion", &master ),
        Track_sumet_EndcapRegion( this, ::TString( prefix ) + "Track_sumet_EndcapRegion", &master ),
        Track_phi_EndcapRegion( this, ::TString( prefix ) + "Track_phi_EndcapRegion", &master ),
        Track_etx_ForwardReg( this, ::TString( prefix ) + "Track_etx_ForwardReg", &master ),
        Track_ety_ForwardReg( this, ::TString( prefix ) + "Track_ety_ForwardReg", &master ),
        Track_sumet_ForwardReg( this, ::TString( prefix ) + "Track_sumet_ForwardReg", &master ),
        Track_phi_ForwardReg( this, ::TString( prefix ) + "Track_phi_ForwardReg", &master ),
        STVF_Track_etx( this, ::TString( prefix ) + "STVF_Track_etx", &master ),
        STVF_Track_ety( this, ::TString( prefix ) + "STVF_Track_ety", &master ),
        STVF_Track_sumet( this, ::TString( prefix ) + "STVF_Track_sumet", &master ),
        STVF_Track_etx_CentralReg( this, ::TString( prefix ) + "STVF_Track_etx_CentralReg", &master ),
        STVF_Track_ety_CentralReg( this, ::TString( prefix ) + "STVF_Track_ety_CentralReg", &master ),
        STVF_Track_sumet_CentralReg( this, ::TString( prefix ) + "STVF_Track_sumet_CentralReg", &master ),
        STVF_Track_phi_CentralReg( this, ::TString( prefix ) + "STVF_Track_phi_CentralReg", &master ),
        STVF_Track_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_Track_etx_EndcapRegion", &master ),
        STVF_Track_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_Track_ety_EndcapRegion", &master ),
        STVF_Track_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_Track_sumet_EndcapRegion", &master ),
        STVF_Track_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_Track_phi_EndcapRegion", &master ),
        STVF_Track_etx_ForwardReg( this, ::TString( prefix ) + "STVF_Track_etx_ForwardReg", &master ),
        STVF_Track_ety_ForwardReg( this, ::TString( prefix ) + "STVF_Track_ety_ForwardReg", &master ),
        STVF_Track_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_Track_sumet_ForwardReg", &master ),
        STVF_Track_phi_ForwardReg( this, ::TString( prefix ) + "STVF_Track_phi_ForwardReg", &master ),
        SoftJets_etx( this, ::TString( prefix ) + "SoftJets_etx", &master ),
        SoftJets_ety( this, ::TString( prefix ) + "SoftJets_ety", &master ),
        SoftJets_sumet( this, ::TString( prefix ) + "SoftJets_sumet", &master ),
        SoftJets_etx_CentralReg( this, ::TString( prefix ) + "SoftJets_etx_CentralReg", &master ),
        SoftJets_ety_CentralReg( this, ::TString( prefix ) + "SoftJets_ety_CentralReg", &master ),
        SoftJets_sumet_CentralReg( this, ::TString( prefix ) + "SoftJets_sumet_CentralReg", &master ),
        SoftJets_phi_CentralReg( this, ::TString( prefix ) + "SoftJets_phi_CentralReg", &master ),
        SoftJets_etx_EndcapRegion( this, ::TString( prefix ) + "SoftJets_etx_EndcapRegion", &master ),
        SoftJets_ety_EndcapRegion( this, ::TString( prefix ) + "SoftJets_ety_EndcapRegion", &master ),
        SoftJets_sumet_EndcapRegion( this, ::TString( prefix ) + "SoftJets_sumet_EndcapRegion", &master ),
        SoftJets_phi_EndcapRegion( this, ::TString( prefix ) + "SoftJets_phi_EndcapRegion", &master ),
        SoftJets_etx_ForwardReg( this, ::TString( prefix ) + "SoftJets_etx_ForwardReg", &master ),
        SoftJets_ety_ForwardReg( this, ::TString( prefix ) + "SoftJets_ety_ForwardReg", &master ),
        SoftJets_sumet_ForwardReg( this, ::TString( prefix ) + "SoftJets_sumet_ForwardReg", &master ),
        SoftJets_phi_ForwardReg( this, ::TString( prefix ) + "SoftJets_phi_ForwardReg", &master ),
        STVF_SoftJets_etx( this, ::TString( prefix ) + "STVF_SoftJets_etx", &master ),
        STVF_SoftJets_ety( this, ::TString( prefix ) + "STVF_SoftJets_ety", &master ),
        STVF_SoftJets_sumet( this, ::TString( prefix ) + "STVF_SoftJets_sumet", &master ),
        STVF_SoftJets_etx_CentralReg( this, ::TString( prefix ) + "STVF_SoftJets_etx_CentralReg", &master ),
        STVF_SoftJets_ety_CentralReg( this, ::TString( prefix ) + "STVF_SoftJets_ety_CentralReg", &master ),
        STVF_SoftJets_sumet_CentralReg( this, ::TString( prefix ) + "STVF_SoftJets_sumet_CentralReg", &master ),
        STVF_SoftJets_phi_CentralReg( this, ::TString( prefix ) + "STVF_SoftJets_phi_CentralReg", &master ),
        STVF_SoftJets_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_SoftJets_etx_EndcapRegion", &master ),
        STVF_SoftJets_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_SoftJets_ety_EndcapRegion", &master ),
        STVF_SoftJets_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_SoftJets_sumet_EndcapRegion", &master ),
        STVF_SoftJets_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_SoftJets_phi_EndcapRegion", &master ),
        STVF_SoftJets_etx_ForwardReg( this, ::TString( prefix ) + "STVF_SoftJets_etx_ForwardReg", &master ),
        STVF_SoftJets_ety_ForwardReg( this, ::TString( prefix ) + "STVF_SoftJets_ety_ForwardReg", &master ),
        STVF_SoftJets_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_SoftJets_sumet_ForwardReg", &master ),
        STVF_SoftJets_phi_ForwardReg( this, ::TString( prefix ) + "STVF_SoftJets_phi_ForwardReg", &master ),
        RefMuon_etx( this, ::TString( prefix ) + "RefMuon_etx", &master ),
        RefMuon_ety( this, ::TString( prefix ) + "RefMuon_ety", &master ),
        RefMuon_sumet( this, ::TString( prefix ) + "RefMuon_sumet", &master ),
        RefMuon_etx_CentralReg( this, ::TString( prefix ) + "RefMuon_etx_CentralReg", &master ),
        RefMuon_ety_CentralReg( this, ::TString( prefix ) + "RefMuon_ety_CentralReg", &master ),
        RefMuon_sumet_CentralReg( this, ::TString( prefix ) + "RefMuon_sumet_CentralReg", &master ),
        RefMuon_phi_CentralReg( this, ::TString( prefix ) + "RefMuon_phi_CentralReg", &master ),
        RefMuon_etx_EndcapRegion( this, ::TString( prefix ) + "RefMuon_etx_EndcapRegion", &master ),
        RefMuon_ety_EndcapRegion( this, ::TString( prefix ) + "RefMuon_ety_EndcapRegion", &master ),
        RefMuon_sumet_EndcapRegion( this, ::TString( prefix ) + "RefMuon_sumet_EndcapRegion", &master ),
        RefMuon_phi_EndcapRegion( this, ::TString( prefix ) + "RefMuon_phi_EndcapRegion", &master ),
        RefMuon_etx_ForwardReg( this, ::TString( prefix ) + "RefMuon_etx_ForwardReg", &master ),
        RefMuon_ety_ForwardReg( this, ::TString( prefix ) + "RefMuon_ety_ForwardReg", &master ),
        RefMuon_sumet_ForwardReg( this, ::TString( prefix ) + "RefMuon_sumet_ForwardReg", &master ),
        RefMuon_phi_ForwardReg( this, ::TString( prefix ) + "RefMuon_phi_ForwardReg", &master ),
        STVF_RefMuon_etx( this, ::TString( prefix ) + "STVF_RefMuon_etx", &master ),
        STVF_RefMuon_ety( this, ::TString( prefix ) + "STVF_RefMuon_ety", &master ),
        STVF_RefMuon_sumet( this, ::TString( prefix ) + "STVF_RefMuon_sumet", &master ),
        STVF_RefMuon_etx_CentralReg( this, ::TString( prefix ) + "STVF_RefMuon_etx_CentralReg", &master ),
        STVF_RefMuon_ety_CentralReg( this, ::TString( prefix ) + "STVF_RefMuon_ety_CentralReg", &master ),
        STVF_RefMuon_sumet_CentralReg( this, ::TString( prefix ) + "STVF_RefMuon_sumet_CentralReg", &master ),
        STVF_RefMuon_phi_CentralReg( this, ::TString( prefix ) + "STVF_RefMuon_phi_CentralReg", &master ),
        STVF_RefMuon_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_RefMuon_etx_EndcapRegion", &master ),
        STVF_RefMuon_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_RefMuon_ety_EndcapRegion", &master ),
        STVF_RefMuon_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_RefMuon_sumet_EndcapRegion", &master ),
        STVF_RefMuon_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_RefMuon_phi_EndcapRegion", &master ),
        STVF_RefMuon_etx_ForwardReg( this, ::TString( prefix ) + "STVF_RefMuon_etx_ForwardReg", &master ),
        STVF_RefMuon_ety_ForwardReg( this, ::TString( prefix ) + "STVF_RefMuon_ety_ForwardReg", &master ),
        STVF_RefMuon_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_RefMuon_sumet_ForwardReg", &master ),
        STVF_RefMuon_phi_ForwardReg( this, ::TString( prefix ) + "STVF_RefMuon_phi_ForwardReg", &master ),
        MuonBoy_etx( this, ::TString( prefix ) + "MuonBoy_etx", &master ),
        MuonBoy_ety( this, ::TString( prefix ) + "MuonBoy_ety", &master ),
        MuonBoy_sumet( this, ::TString( prefix ) + "MuonBoy_sumet", &master ),
        MuonBoy_etx_CentralReg( this, ::TString( prefix ) + "MuonBoy_etx_CentralReg", &master ),
        MuonBoy_ety_CentralReg( this, ::TString( prefix ) + "MuonBoy_ety_CentralReg", &master ),
        MuonBoy_sumet_CentralReg( this, ::TString( prefix ) + "MuonBoy_sumet_CentralReg", &master ),
        MuonBoy_phi_CentralReg( this, ::TString( prefix ) + "MuonBoy_phi_CentralReg", &master ),
        MuonBoy_etx_EndcapRegion( this, ::TString( prefix ) + "MuonBoy_etx_EndcapRegion", &master ),
        MuonBoy_ety_EndcapRegion( this, ::TString( prefix ) + "MuonBoy_ety_EndcapRegion", &master ),
        MuonBoy_sumet_EndcapRegion( this, ::TString( prefix ) + "MuonBoy_sumet_EndcapRegion", &master ),
        MuonBoy_phi_EndcapRegion( this, ::TString( prefix ) + "MuonBoy_phi_EndcapRegion", &master ),
        MuonBoy_etx_ForwardReg( this, ::TString( prefix ) + "MuonBoy_etx_ForwardReg", &master ),
        MuonBoy_ety_ForwardReg( this, ::TString( prefix ) + "MuonBoy_ety_ForwardReg", &master ),
        MuonBoy_sumet_ForwardReg( this, ::TString( prefix ) + "MuonBoy_sumet_ForwardReg", &master ),
        MuonBoy_phi_ForwardReg( this, ::TString( prefix ) + "MuonBoy_phi_ForwardReg", &master ),
        STVF_MuonBoy_etx( this, ::TString( prefix ) + "STVF_MuonBoy_etx", &master ),
        STVF_MuonBoy_ety( this, ::TString( prefix ) + "STVF_MuonBoy_ety", &master ),
        STVF_MuonBoy_sumet( this, ::TString( prefix ) + "STVF_MuonBoy_sumet", &master ),
        STVF_MuonBoy_etx_CentralReg( this, ::TString( prefix ) + "STVF_MuonBoy_etx_CentralReg", &master ),
        STVF_MuonBoy_ety_CentralReg( this, ::TString( prefix ) + "STVF_MuonBoy_ety_CentralReg", &master ),
        STVF_MuonBoy_sumet_CentralReg( this, ::TString( prefix ) + "STVF_MuonBoy_sumet_CentralReg", &master ),
        STVF_MuonBoy_phi_CentralReg( this, ::TString( prefix ) + "STVF_MuonBoy_phi_CentralReg", &master ),
        STVF_MuonBoy_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_MuonBoy_etx_EndcapRegion", &master ),
        STVF_MuonBoy_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_MuonBoy_ety_EndcapRegion", &master ),
        STVF_MuonBoy_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_MuonBoy_sumet_EndcapRegion", &master ),
        STVF_MuonBoy_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_MuonBoy_phi_EndcapRegion", &master ),
        STVF_MuonBoy_etx_ForwardReg( this, ::TString( prefix ) + "STVF_MuonBoy_etx_ForwardReg", &master ),
        STVF_MuonBoy_ety_ForwardReg( this, ::TString( prefix ) + "STVF_MuonBoy_ety_ForwardReg", &master ),
        STVF_MuonBoy_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_MuonBoy_sumet_ForwardReg", &master ),
        STVF_MuonBoy_phi_ForwardReg( this, ::TString( prefix ) + "STVF_MuonBoy_phi_ForwardReg", &master ),
        STVF_CellOut_Track_etx( this, ::TString( prefix ) + "STVF_CellOut_Track_etx", &master ),
        STVF_CellOut_Track_ety( this, ::TString( prefix ) + "STVF_CellOut_Track_ety", &master ),
        STVF_CellOut_Track_sumet( this, ::TString( prefix ) + "STVF_CellOut_Track_sumet", &master ),
        STVF_CellOut_Track_etx_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_Track_etx_CentralReg", &master ),
        STVF_CellOut_Track_ety_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_Track_ety_CentralReg", &master ),
        STVF_CellOut_Track_sumet_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_Track_sumet_CentralReg", &master ),
        STVF_CellOut_Track_phi_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_Track_phi_CentralReg", &master ),
        STVF_CellOut_Track_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_Track_etx_EndcapRegion", &master ),
        STVF_CellOut_Track_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_Track_ety_EndcapRegion", &master ),
        STVF_CellOut_Track_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_Track_sumet_EndcapRegion", &master ),
        STVF_CellOut_Track_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_Track_phi_EndcapRegion", &master ),
        STVF_CellOut_Track_etx_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_Track_etx_ForwardReg", &master ),
        STVF_CellOut_Track_ety_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_Track_ety_ForwardReg", &master ),
        STVF_CellOut_Track_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_Track_sumet_ForwardReg", &master ),
        STVF_CellOut_Track_phi_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_Track_phi_ForwardReg", &master ),
        STVF_CellOut_TrackPV_etx( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_etx", &master ),
        STVF_CellOut_TrackPV_ety( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_ety", &master ),
        STVF_CellOut_TrackPV_sumet( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_sumet", &master ),
        STVF_CellOut_TrackPV_etx_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_etx_CentralReg", &master ),
        STVF_CellOut_TrackPV_ety_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_ety_CentralReg", &master ),
        STVF_CellOut_TrackPV_sumet_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_sumet_CentralReg", &master ),
        STVF_CellOut_TrackPV_phi_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_phi_CentralReg", &master ),
        STVF_CellOut_TrackPV_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_etx_EndcapRegion", &master ),
        STVF_CellOut_TrackPV_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_ety_EndcapRegion", &master ),
        STVF_CellOut_TrackPV_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_sumet_EndcapRegion", &master ),
        STVF_CellOut_TrackPV_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_phi_EndcapRegion", &master ),
        STVF_CellOut_TrackPV_etx_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_etx_ForwardReg", &master ),
        STVF_CellOut_TrackPV_ety_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_ety_ForwardReg", &master ),
        STVF_CellOut_TrackPV_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_sumet_ForwardReg", &master ),
        STVF_CellOut_TrackPV_phi_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_phi_ForwardReg", &master ),
        STVF_CellOutCorr_etx( this, ::TString( prefix ) + "STVF_CellOutCorr_etx", &master ),
        STVF_CellOutCorr_ety( this, ::TString( prefix ) + "STVF_CellOutCorr_ety", &master ),
        STVF_CellOutCorr_sumet( this, ::TString( prefix ) + "STVF_CellOutCorr_sumet", &master ),
        STVF_CellOutCorr_etx_CentralReg( this, ::TString( prefix ) + "STVF_CellOutCorr_etx_CentralReg", &master ),
        STVF_CellOutCorr_ety_CentralReg( this, ::TString( prefix ) + "STVF_CellOutCorr_ety_CentralReg", &master ),
        STVF_CellOutCorr_sumet_CentralReg( this, ::TString( prefix ) + "STVF_CellOutCorr_sumet_CentralReg", &master ),
        STVF_CellOutCorr_phi_CentralReg( this, ::TString( prefix ) + "STVF_CellOutCorr_phi_CentralReg", &master ),
        STVF_CellOutCorr_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOutCorr_etx_EndcapRegion", &master ),
        STVF_CellOutCorr_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOutCorr_ety_EndcapRegion", &master ),
        STVF_CellOutCorr_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOutCorr_sumet_EndcapRegion", &master ),
        STVF_CellOutCorr_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOutCorr_phi_EndcapRegion", &master ),
        STVF_CellOutCorr_etx_ForwardReg( this, ::TString( prefix ) + "STVF_CellOutCorr_etx_ForwardReg", &master ),
        STVF_CellOutCorr_ety_ForwardReg( this, ::TString( prefix ) + "STVF_CellOutCorr_ety_ForwardReg", &master ),
        STVF_CellOutCorr_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_CellOutCorr_sumet_ForwardReg", &master ),
        STVF_CellOutCorr_phi_ForwardReg( this, ::TString( prefix ) + "STVF_CellOutCorr_phi_ForwardReg", &master ),
        fHandles(),
        fFromInput( kTRUE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "RefGamma_etx" ] = &RefGamma_etx;
      fHandles[ "RefGamma_ety" ] = &RefGamma_ety;
      fHandles[ "RefGamma_sumet" ] = &RefGamma_sumet;
      fHandles[ "RefGamma_etx_CentralReg" ] = &RefGamma_etx_CentralReg;
      fHandles[ "RefGamma_ety_CentralReg" ] = &RefGamma_ety_CentralReg;
      fHandles[ "RefGamma_sumet_CentralReg" ] = &RefGamma_sumet_CentralReg;
      fHandles[ "RefGamma_phi_CentralReg" ] = &RefGamma_phi_CentralReg;
      fHandles[ "RefGamma_etx_EndcapRegion" ] = &RefGamma_etx_EndcapRegion;
      fHandles[ "RefGamma_ety_EndcapRegion" ] = &RefGamma_ety_EndcapRegion;
      fHandles[ "RefGamma_sumet_EndcapRegion" ] = &RefGamma_sumet_EndcapRegion;
      fHandles[ "RefGamma_phi_EndcapRegion" ] = &RefGamma_phi_EndcapRegion;
      fHandles[ "RefGamma_etx_ForwardReg" ] = &RefGamma_etx_ForwardReg;
      fHandles[ "RefGamma_ety_ForwardReg" ] = &RefGamma_ety_ForwardReg;
      fHandles[ "RefGamma_sumet_ForwardReg" ] = &RefGamma_sumet_ForwardReg;
      fHandles[ "RefGamma_phi_ForwardReg" ] = &RefGamma_phi_ForwardReg;
      fHandles[ "STVF_RefGamma_etx" ] = &STVF_RefGamma_etx;
      fHandles[ "STVF_RefGamma_ety" ] = &STVF_RefGamma_ety;
      fHandles[ "STVF_RefGamma_sumet" ] = &STVF_RefGamma_sumet;
      fHandles[ "STVF_RefGamma_etx_CentralReg" ] = &STVF_RefGamma_etx_CentralReg;
      fHandles[ "STVF_RefGamma_ety_CentralReg" ] = &STVF_RefGamma_ety_CentralReg;
      fHandles[ "STVF_RefGamma_sumet_CentralReg" ] = &STVF_RefGamma_sumet_CentralReg;
      fHandles[ "STVF_RefGamma_phi_CentralReg" ] = &STVF_RefGamma_phi_CentralReg;
      fHandles[ "STVF_RefGamma_etx_EndcapRegion" ] = &STVF_RefGamma_etx_EndcapRegion;
      fHandles[ "STVF_RefGamma_ety_EndcapRegion" ] = &STVF_RefGamma_ety_EndcapRegion;
      fHandles[ "STVF_RefGamma_sumet_EndcapRegion" ] = &STVF_RefGamma_sumet_EndcapRegion;
      fHandles[ "STVF_RefGamma_phi_EndcapRegion" ] = &STVF_RefGamma_phi_EndcapRegion;
      fHandles[ "STVF_RefGamma_etx_ForwardReg" ] = &STVF_RefGamma_etx_ForwardReg;
      fHandles[ "STVF_RefGamma_ety_ForwardReg" ] = &STVF_RefGamma_ety_ForwardReg;
      fHandles[ "STVF_RefGamma_sumet_ForwardReg" ] = &STVF_RefGamma_sumet_ForwardReg;
      fHandles[ "STVF_RefGamma_phi_ForwardReg" ] = &STVF_RefGamma_phi_ForwardReg;
      fHandles[ "RefFinal_etx" ] = &RefFinal_etx;
      fHandles[ "RefFinal_ety" ] = &RefFinal_ety;
      fHandles[ "RefFinal_sumet" ] = &RefFinal_sumet;
      fHandles[ "RefFinal_etx_CentralReg" ] = &RefFinal_etx_CentralReg;
      fHandles[ "RefFinal_ety_CentralReg" ] = &RefFinal_ety_CentralReg;
      fHandles[ "RefFinal_sumet_CentralReg" ] = &RefFinal_sumet_CentralReg;
      fHandles[ "RefFinal_phi_CentralReg" ] = &RefFinal_phi_CentralReg;
      fHandles[ "RefFinal_etx_EndcapRegion" ] = &RefFinal_etx_EndcapRegion;
      fHandles[ "RefFinal_ety_EndcapRegion" ] = &RefFinal_ety_EndcapRegion;
      fHandles[ "RefFinal_sumet_EndcapRegion" ] = &RefFinal_sumet_EndcapRegion;
      fHandles[ "RefFinal_phi_EndcapRegion" ] = &RefFinal_phi_EndcapRegion;
      fHandles[ "RefFinal_etx_ForwardReg" ] = &RefFinal_etx_ForwardReg;
      fHandles[ "RefFinal_ety_ForwardReg" ] = &RefFinal_ety_ForwardReg;
      fHandles[ "RefFinal_sumet_ForwardReg" ] = &RefFinal_sumet_ForwardReg;
      fHandles[ "RefFinal_phi_ForwardReg" ] = &RefFinal_phi_ForwardReg;
      fHandles[ "STVF_RefFinal_etx" ] = &STVF_RefFinal_etx;
      fHandles[ "STVF_RefFinal_ety" ] = &STVF_RefFinal_ety;
      fHandles[ "STVF_RefFinal_sumet" ] = &STVF_RefFinal_sumet;
      fHandles[ "STVF_RefFinal_etx_CentralReg" ] = &STVF_RefFinal_etx_CentralReg;
      fHandles[ "STVF_RefFinal_ety_CentralReg" ] = &STVF_RefFinal_ety_CentralReg;
      fHandles[ "STVF_RefFinal_sumet_CentralReg" ] = &STVF_RefFinal_sumet_CentralReg;
      fHandles[ "STVF_RefFinal_phi_CentralReg" ] = &STVF_RefFinal_phi_CentralReg;
      fHandles[ "STVF_RefFinal_etx_EndcapRegion" ] = &STVF_RefFinal_etx_EndcapRegion;
      fHandles[ "STVF_RefFinal_ety_EndcapRegion" ] = &STVF_RefFinal_ety_EndcapRegion;
      fHandles[ "STVF_RefFinal_sumet_EndcapRegion" ] = &STVF_RefFinal_sumet_EndcapRegion;
      fHandles[ "STVF_RefFinal_phi_EndcapRegion" ] = &STVF_RefFinal_phi_EndcapRegion;
      fHandles[ "STVF_RefFinal_etx_ForwardReg" ] = &STVF_RefFinal_etx_ForwardReg;
      fHandles[ "STVF_RefFinal_ety_ForwardReg" ] = &STVF_RefFinal_ety_ForwardReg;
      fHandles[ "STVF_RefFinal_sumet_ForwardReg" ] = &STVF_RefFinal_sumet_ForwardReg;
      fHandles[ "STVF_RefFinal_phi_ForwardReg" ] = &STVF_RefFinal_phi_ForwardReg;
      fHandles[ "RefJet_etx" ] = &RefJet_etx;
      fHandles[ "RefJet_ety" ] = &RefJet_ety;
      fHandles[ "RefJet_sumet" ] = &RefJet_sumet;
      fHandles[ "RefJet_etx_CentralReg" ] = &RefJet_etx_CentralReg;
      fHandles[ "RefJet_ety_CentralReg" ] = &RefJet_ety_CentralReg;
      fHandles[ "RefJet_sumet_CentralReg" ] = &RefJet_sumet_CentralReg;
      fHandles[ "RefJet_phi_CentralReg" ] = &RefJet_phi_CentralReg;
      fHandles[ "RefJet_etx_EndcapRegion" ] = &RefJet_etx_EndcapRegion;
      fHandles[ "RefJet_ety_EndcapRegion" ] = &RefJet_ety_EndcapRegion;
      fHandles[ "RefJet_sumet_EndcapRegion" ] = &RefJet_sumet_EndcapRegion;
      fHandles[ "RefJet_phi_EndcapRegion" ] = &RefJet_phi_EndcapRegion;
      fHandles[ "RefJet_etx_ForwardReg" ] = &RefJet_etx_ForwardReg;
      fHandles[ "RefJet_ety_ForwardReg" ] = &RefJet_ety_ForwardReg;
      fHandles[ "RefJet_sumet_ForwardReg" ] = &RefJet_sumet_ForwardReg;
      fHandles[ "RefJet_phi_ForwardReg" ] = &RefJet_phi_ForwardReg;
      fHandles[ "STVF_RefJet_etx" ] = &STVF_RefJet_etx;
      fHandles[ "STVF_RefJet_ety" ] = &STVF_RefJet_ety;
      fHandles[ "STVF_RefJet_sumet" ] = &STVF_RefJet_sumet;
      fHandles[ "STVF_RefJet_etx_CentralReg" ] = &STVF_RefJet_etx_CentralReg;
      fHandles[ "STVF_RefJet_ety_CentralReg" ] = &STVF_RefJet_ety_CentralReg;
      fHandles[ "STVF_RefJet_sumet_CentralReg" ] = &STVF_RefJet_sumet_CentralReg;
      fHandles[ "STVF_RefJet_phi_CentralReg" ] = &STVF_RefJet_phi_CentralReg;
      fHandles[ "STVF_RefJet_etx_EndcapRegion" ] = &STVF_RefJet_etx_EndcapRegion;
      fHandles[ "STVF_RefJet_ety_EndcapRegion" ] = &STVF_RefJet_ety_EndcapRegion;
      fHandles[ "STVF_RefJet_sumet_EndcapRegion" ] = &STVF_RefJet_sumet_EndcapRegion;
      fHandles[ "STVF_RefJet_phi_EndcapRegion" ] = &STVF_RefJet_phi_EndcapRegion;
      fHandles[ "STVF_RefJet_etx_ForwardReg" ] = &STVF_RefJet_etx_ForwardReg;
      fHandles[ "STVF_RefJet_ety_ForwardReg" ] = &STVF_RefJet_ety_ForwardReg;
      fHandles[ "STVF_RefJet_sumet_ForwardReg" ] = &STVF_RefJet_sumet_ForwardReg;
      fHandles[ "STVF_RefJet_phi_ForwardReg" ] = &STVF_RefJet_phi_ForwardReg;
      fHandles[ "RefEle_etx" ] = &RefEle_etx;
      fHandles[ "RefEle_ety" ] = &RefEle_ety;
      fHandles[ "RefEle_sumet" ] = &RefEle_sumet;
      fHandles[ "RefEle_etx_CentralReg" ] = &RefEle_etx_CentralReg;
      fHandles[ "RefEle_ety_CentralReg" ] = &RefEle_ety_CentralReg;
      fHandles[ "RefEle_sumet_CentralReg" ] = &RefEle_sumet_CentralReg;
      fHandles[ "RefEle_phi_CentralReg" ] = &RefEle_phi_CentralReg;
      fHandles[ "RefEle_etx_EndcapRegion" ] = &RefEle_etx_EndcapRegion;
      fHandles[ "RefEle_ety_EndcapRegion" ] = &RefEle_ety_EndcapRegion;
      fHandles[ "RefEle_sumet_EndcapRegion" ] = &RefEle_sumet_EndcapRegion;
      fHandles[ "RefEle_phi_EndcapRegion" ] = &RefEle_phi_EndcapRegion;
      fHandles[ "RefEle_etx_ForwardReg" ] = &RefEle_etx_ForwardReg;
      fHandles[ "RefEle_ety_ForwardReg" ] = &RefEle_ety_ForwardReg;
      fHandles[ "RefEle_sumet_ForwardReg" ] = &RefEle_sumet_ForwardReg;
      fHandles[ "RefEle_phi_ForwardReg" ] = &RefEle_phi_ForwardReg;
      fHandles[ "STVF_RefEle_etx" ] = &STVF_RefEle_etx;
      fHandles[ "STVF_RefEle_ety" ] = &STVF_RefEle_ety;
      fHandles[ "STVF_RefEle_sumet" ] = &STVF_RefEle_sumet;
      fHandles[ "STVF_RefEle_etx_CentralReg" ] = &STVF_RefEle_etx_CentralReg;
      fHandles[ "STVF_RefEle_ety_CentralReg" ] = &STVF_RefEle_ety_CentralReg;
      fHandles[ "STVF_RefEle_sumet_CentralReg" ] = &STVF_RefEle_sumet_CentralReg;
      fHandles[ "STVF_RefEle_phi_CentralReg" ] = &STVF_RefEle_phi_CentralReg;
      fHandles[ "STVF_RefEle_etx_EndcapRegion" ] = &STVF_RefEle_etx_EndcapRegion;
      fHandles[ "STVF_RefEle_ety_EndcapRegion" ] = &STVF_RefEle_ety_EndcapRegion;
      fHandles[ "STVF_RefEle_sumet_EndcapRegion" ] = &STVF_RefEle_sumet_EndcapRegion;
      fHandles[ "STVF_RefEle_phi_EndcapRegion" ] = &STVF_RefEle_phi_EndcapRegion;
      fHandles[ "STVF_RefEle_etx_ForwardReg" ] = &STVF_RefEle_etx_ForwardReg;
      fHandles[ "STVF_RefEle_ety_ForwardReg" ] = &STVF_RefEle_ety_ForwardReg;
      fHandles[ "STVF_RefEle_sumet_ForwardReg" ] = &STVF_RefEle_sumet_ForwardReg;
      fHandles[ "STVF_RefEle_phi_ForwardReg" ] = &STVF_RefEle_phi_ForwardReg;
      fHandles[ "Muon_Total_Staco_etx" ] = &Muon_Total_Staco_etx;
      fHandles[ "Muon_Total_Staco_ety" ] = &Muon_Total_Staco_ety;
      fHandles[ "Muon_Total_Staco_sumet" ] = &Muon_Total_Staco_sumet;
      fHandles[ "Muon_Total_Staco_etx_CentralReg" ] = &Muon_Total_Staco_etx_CentralReg;
      fHandles[ "Muon_Total_Staco_ety_CentralReg" ] = &Muon_Total_Staco_ety_CentralReg;
      fHandles[ "Muon_Total_Staco_sumet_CentralReg" ] = &Muon_Total_Staco_sumet_CentralReg;
      fHandles[ "Muon_Total_Staco_phi_CentralReg" ] = &Muon_Total_Staco_phi_CentralReg;
      fHandles[ "Muon_Total_Staco_etx_EndcapRegion" ] = &Muon_Total_Staco_etx_EndcapRegion;
      fHandles[ "Muon_Total_Staco_ety_EndcapRegion" ] = &Muon_Total_Staco_ety_EndcapRegion;
      fHandles[ "Muon_Total_Staco_sumet_EndcapRegion" ] = &Muon_Total_Staco_sumet_EndcapRegion;
      fHandles[ "Muon_Total_Staco_phi_EndcapRegion" ] = &Muon_Total_Staco_phi_EndcapRegion;
      fHandles[ "Muon_Total_Staco_etx_ForwardReg" ] = &Muon_Total_Staco_etx_ForwardReg;
      fHandles[ "Muon_Total_Staco_ety_ForwardReg" ] = &Muon_Total_Staco_ety_ForwardReg;
      fHandles[ "Muon_Total_Staco_sumet_ForwardReg" ] = &Muon_Total_Staco_sumet_ForwardReg;
      fHandles[ "Muon_Total_Staco_phi_ForwardReg" ] = &Muon_Total_Staco_phi_ForwardReg;
      fHandles[ "STVF_Muon_Total_Staco_etx" ] = &STVF_Muon_Total_Staco_etx;
      fHandles[ "STVF_Muon_Total_Staco_ety" ] = &STVF_Muon_Total_Staco_ety;
      fHandles[ "STVF_Muon_Total_Staco_sumet" ] = &STVF_Muon_Total_Staco_sumet;
      fHandles[ "STVF_Muon_Total_Staco_etx_CentralReg" ] = &STVF_Muon_Total_Staco_etx_CentralReg;
      fHandles[ "STVF_Muon_Total_Staco_ety_CentralReg" ] = &STVF_Muon_Total_Staco_ety_CentralReg;
      fHandles[ "STVF_Muon_Total_Staco_sumet_CentralReg" ] = &STVF_Muon_Total_Staco_sumet_CentralReg;
      fHandles[ "STVF_Muon_Total_Staco_phi_CentralReg" ] = &STVF_Muon_Total_Staco_phi_CentralReg;
      fHandles[ "STVF_Muon_Total_Staco_etx_EndcapRegion" ] = &STVF_Muon_Total_Staco_etx_EndcapRegion;
      fHandles[ "STVF_Muon_Total_Staco_ety_EndcapRegion" ] = &STVF_Muon_Total_Staco_ety_EndcapRegion;
      fHandles[ "STVF_Muon_Total_Staco_sumet_EndcapRegion" ] = &STVF_Muon_Total_Staco_sumet_EndcapRegion;
      fHandles[ "STVF_Muon_Total_Staco_phi_EndcapRegion" ] = &STVF_Muon_Total_Staco_phi_EndcapRegion;
      fHandles[ "STVF_Muon_Total_Staco_etx_ForwardReg" ] = &STVF_Muon_Total_Staco_etx_ForwardReg;
      fHandles[ "STVF_Muon_Total_Staco_ety_ForwardReg" ] = &STVF_Muon_Total_Staco_ety_ForwardReg;
      fHandles[ "STVF_Muon_Total_Staco_sumet_ForwardReg" ] = &STVF_Muon_Total_Staco_sumet_ForwardReg;
      fHandles[ "STVF_Muon_Total_Staco_phi_ForwardReg" ] = &STVF_Muon_Total_Staco_phi_ForwardReg;
      fHandles[ "Muon_Isol_Staco_etx" ] = &Muon_Isol_Staco_etx;
      fHandles[ "Muon_Isol_Staco_ety" ] = &Muon_Isol_Staco_ety;
      fHandles[ "Muon_Isol_Staco_sumet" ] = &Muon_Isol_Staco_sumet;
      fHandles[ "Muon_Isol_Staco_etx_CentralReg" ] = &Muon_Isol_Staco_etx_CentralReg;
      fHandles[ "Muon_Isol_Staco_ety_CentralReg" ] = &Muon_Isol_Staco_ety_CentralReg;
      fHandles[ "Muon_Isol_Staco_sumet_CentralReg" ] = &Muon_Isol_Staco_sumet_CentralReg;
      fHandles[ "Muon_Isol_Staco_phi_CentralReg" ] = &Muon_Isol_Staco_phi_CentralReg;
      fHandles[ "Muon_Isol_Staco_etx_EndcapRegion" ] = &Muon_Isol_Staco_etx_EndcapRegion;
      fHandles[ "Muon_Isol_Staco_ety_EndcapRegion" ] = &Muon_Isol_Staco_ety_EndcapRegion;
      fHandles[ "Muon_Isol_Staco_sumet_EndcapRegion" ] = &Muon_Isol_Staco_sumet_EndcapRegion;
      fHandles[ "Muon_Isol_Staco_phi_EndcapRegion" ] = &Muon_Isol_Staco_phi_EndcapRegion;
      fHandles[ "Muon_Isol_Staco_etx_ForwardReg" ] = &Muon_Isol_Staco_etx_ForwardReg;
      fHandles[ "Muon_Isol_Staco_ety_ForwardReg" ] = &Muon_Isol_Staco_ety_ForwardReg;
      fHandles[ "Muon_Isol_Staco_sumet_ForwardReg" ] = &Muon_Isol_Staco_sumet_ForwardReg;
      fHandles[ "Muon_Isol_Staco_phi_ForwardReg" ] = &Muon_Isol_Staco_phi_ForwardReg;
      fHandles[ "STVF_Muon_Isol_Staco_etx" ] = &STVF_Muon_Isol_Staco_etx;
      fHandles[ "STVF_Muon_Isol_Staco_ety" ] = &STVF_Muon_Isol_Staco_ety;
      fHandles[ "STVF_Muon_Isol_Staco_sumet" ] = &STVF_Muon_Isol_Staco_sumet;
      fHandles[ "STVF_Muon_Isol_Staco_etx_CentralReg" ] = &STVF_Muon_Isol_Staco_etx_CentralReg;
      fHandles[ "STVF_Muon_Isol_Staco_ety_CentralReg" ] = &STVF_Muon_Isol_Staco_ety_CentralReg;
      fHandles[ "STVF_Muon_Isol_Staco_sumet_CentralReg" ] = &STVF_Muon_Isol_Staco_sumet_CentralReg;
      fHandles[ "STVF_Muon_Isol_Staco_phi_CentralReg" ] = &STVF_Muon_Isol_Staco_phi_CentralReg;
      fHandles[ "STVF_Muon_Isol_Staco_etx_EndcapRegion" ] = &STVF_Muon_Isol_Staco_etx_EndcapRegion;
      fHandles[ "STVF_Muon_Isol_Staco_ety_EndcapRegion" ] = &STVF_Muon_Isol_Staco_ety_EndcapRegion;
      fHandles[ "STVF_Muon_Isol_Staco_sumet_EndcapRegion" ] = &STVF_Muon_Isol_Staco_sumet_EndcapRegion;
      fHandles[ "STVF_Muon_Isol_Staco_phi_EndcapRegion" ] = &STVF_Muon_Isol_Staco_phi_EndcapRegion;
      fHandles[ "STVF_Muon_Isol_Staco_etx_ForwardReg" ] = &STVF_Muon_Isol_Staco_etx_ForwardReg;
      fHandles[ "STVF_Muon_Isol_Staco_ety_ForwardReg" ] = &STVF_Muon_Isol_Staco_ety_ForwardReg;
      fHandles[ "STVF_Muon_Isol_Staco_sumet_ForwardReg" ] = &STVF_Muon_Isol_Staco_sumet_ForwardReg;
      fHandles[ "STVF_Muon_Isol_Staco_phi_ForwardReg" ] = &STVF_Muon_Isol_Staco_phi_ForwardReg;
      fHandles[ "Muon_NonIsol_Staco_etx" ] = &Muon_NonIsol_Staco_etx;
      fHandles[ "Muon_NonIsol_Staco_ety" ] = &Muon_NonIsol_Staco_ety;
      fHandles[ "Muon_NonIsol_Staco_sumet" ] = &Muon_NonIsol_Staco_sumet;
      fHandles[ "Muon_NonIsol_Staco_etx_CentralReg" ] = &Muon_NonIsol_Staco_etx_CentralReg;
      fHandles[ "Muon_NonIsol_Staco_ety_CentralReg" ] = &Muon_NonIsol_Staco_ety_CentralReg;
      fHandles[ "Muon_NonIsol_Staco_sumet_CentralReg" ] = &Muon_NonIsol_Staco_sumet_CentralReg;
      fHandles[ "Muon_NonIsol_Staco_phi_CentralReg" ] = &Muon_NonIsol_Staco_phi_CentralReg;
      fHandles[ "Muon_NonIsol_Staco_etx_EndcapRegion" ] = &Muon_NonIsol_Staco_etx_EndcapRegion;
      fHandles[ "Muon_NonIsol_Staco_ety_EndcapRegion" ] = &Muon_NonIsol_Staco_ety_EndcapRegion;
      fHandles[ "Muon_NonIsol_Staco_sumet_EndcapRegion" ] = &Muon_NonIsol_Staco_sumet_EndcapRegion;
      fHandles[ "Muon_NonIsol_Staco_phi_EndcapRegion" ] = &Muon_NonIsol_Staco_phi_EndcapRegion;
      fHandles[ "Muon_NonIsol_Staco_etx_ForwardReg" ] = &Muon_NonIsol_Staco_etx_ForwardReg;
      fHandles[ "Muon_NonIsol_Staco_ety_ForwardReg" ] = &Muon_NonIsol_Staco_ety_ForwardReg;
      fHandles[ "Muon_NonIsol_Staco_sumet_ForwardReg" ] = &Muon_NonIsol_Staco_sumet_ForwardReg;
      fHandles[ "Muon_NonIsol_Staco_phi_ForwardReg" ] = &Muon_NonIsol_Staco_phi_ForwardReg;
      fHandles[ "STVF_Muon_NonIsol_Staco_etx" ] = &STVF_Muon_NonIsol_Staco_etx;
      fHandles[ "STVF_Muon_NonIsol_Staco_ety" ] = &STVF_Muon_NonIsol_Staco_ety;
      fHandles[ "STVF_Muon_NonIsol_Staco_sumet" ] = &STVF_Muon_NonIsol_Staco_sumet;
      fHandles[ "STVF_Muon_NonIsol_Staco_etx_CentralReg" ] = &STVF_Muon_NonIsol_Staco_etx_CentralReg;
      fHandles[ "STVF_Muon_NonIsol_Staco_ety_CentralReg" ] = &STVF_Muon_NonIsol_Staco_ety_CentralReg;
      fHandles[ "STVF_Muon_NonIsol_Staco_sumet_CentralReg" ] = &STVF_Muon_NonIsol_Staco_sumet_CentralReg;
      fHandles[ "STVF_Muon_NonIsol_Staco_phi_CentralReg" ] = &STVF_Muon_NonIsol_Staco_phi_CentralReg;
      fHandles[ "STVF_Muon_NonIsol_Staco_etx_EndcapRegion" ] = &STVF_Muon_NonIsol_Staco_etx_EndcapRegion;
      fHandles[ "STVF_Muon_NonIsol_Staco_ety_EndcapRegion" ] = &STVF_Muon_NonIsol_Staco_ety_EndcapRegion;
      fHandles[ "STVF_Muon_NonIsol_Staco_sumet_EndcapRegion" ] = &STVF_Muon_NonIsol_Staco_sumet_EndcapRegion;
      fHandles[ "STVF_Muon_NonIsol_Staco_phi_EndcapRegion" ] = &STVF_Muon_NonIsol_Staco_phi_EndcapRegion;
      fHandles[ "STVF_Muon_NonIsol_Staco_etx_ForwardReg" ] = &STVF_Muon_NonIsol_Staco_etx_ForwardReg;
      fHandles[ "STVF_Muon_NonIsol_Staco_ety_ForwardReg" ] = &STVF_Muon_NonIsol_Staco_ety_ForwardReg;
      fHandles[ "STVF_Muon_NonIsol_Staco_sumet_ForwardReg" ] = &STVF_Muon_NonIsol_Staco_sumet_ForwardReg;
      fHandles[ "STVF_Muon_NonIsol_Staco_phi_ForwardReg" ] = &STVF_Muon_NonIsol_Staco_phi_ForwardReg;
      fHandles[ "CellOut_etx" ] = &CellOut_etx;
      fHandles[ "CellOut_ety" ] = &CellOut_ety;
      fHandles[ "CellOut_sumet" ] = &CellOut_sumet;
      fHandles[ "CellOut_etx_CentralReg" ] = &CellOut_etx_CentralReg;
      fHandles[ "CellOut_ety_CentralReg" ] = &CellOut_ety_CentralReg;
      fHandles[ "CellOut_sumet_CentralReg" ] = &CellOut_sumet_CentralReg;
      fHandles[ "CellOut_phi_CentralReg" ] = &CellOut_phi_CentralReg;
      fHandles[ "CellOut_etx_EndcapRegion" ] = &CellOut_etx_EndcapRegion;
      fHandles[ "CellOut_ety_EndcapRegion" ] = &CellOut_ety_EndcapRegion;
      fHandles[ "CellOut_sumet_EndcapRegion" ] = &CellOut_sumet_EndcapRegion;
      fHandles[ "CellOut_phi_EndcapRegion" ] = &CellOut_phi_EndcapRegion;
      fHandles[ "CellOut_etx_ForwardReg" ] = &CellOut_etx_ForwardReg;
      fHandles[ "CellOut_ety_ForwardReg" ] = &CellOut_ety_ForwardReg;
      fHandles[ "CellOut_sumet_ForwardReg" ] = &CellOut_sumet_ForwardReg;
      fHandles[ "CellOut_phi_ForwardReg" ] = &CellOut_phi_ForwardReg;
      fHandles[ "STVF_CellOut_etx" ] = &STVF_CellOut_etx;
      fHandles[ "STVF_CellOut_ety" ] = &STVF_CellOut_ety;
      fHandles[ "STVF_CellOut_sumet" ] = &STVF_CellOut_sumet;
      fHandles[ "STVF_CellOut_etx_CentralReg" ] = &STVF_CellOut_etx_CentralReg;
      fHandles[ "STVF_CellOut_ety_CentralReg" ] = &STVF_CellOut_ety_CentralReg;
      fHandles[ "STVF_CellOut_sumet_CentralReg" ] = &STVF_CellOut_sumet_CentralReg;
      fHandles[ "STVF_CellOut_phi_CentralReg" ] = &STVF_CellOut_phi_CentralReg;
      fHandles[ "STVF_CellOut_etx_EndcapRegion" ] = &STVF_CellOut_etx_EndcapRegion;
      fHandles[ "STVF_CellOut_ety_EndcapRegion" ] = &STVF_CellOut_ety_EndcapRegion;
      fHandles[ "STVF_CellOut_sumet_EndcapRegion" ] = &STVF_CellOut_sumet_EndcapRegion;
      fHandles[ "STVF_CellOut_phi_EndcapRegion" ] = &STVF_CellOut_phi_EndcapRegion;
      fHandles[ "STVF_CellOut_etx_ForwardReg" ] = &STVF_CellOut_etx_ForwardReg;
      fHandles[ "STVF_CellOut_ety_ForwardReg" ] = &STVF_CellOut_ety_ForwardReg;
      fHandles[ "STVF_CellOut_sumet_ForwardReg" ] = &STVF_CellOut_sumet_ForwardReg;
      fHandles[ "STVF_CellOut_phi_ForwardReg" ] = &STVF_CellOut_phi_ForwardReg;
      fHandles[ "Muon_Isol_Muid_etx" ] = &Muon_Isol_Muid_etx;
      fHandles[ "Muon_Isol_Muid_ety" ] = &Muon_Isol_Muid_ety;
      fHandles[ "Muon_Isol_Muid_sumet" ] = &Muon_Isol_Muid_sumet;
      fHandles[ "Muon_Isol_Muid_etx_CentralReg" ] = &Muon_Isol_Muid_etx_CentralReg;
      fHandles[ "Muon_Isol_Muid_ety_CentralReg" ] = &Muon_Isol_Muid_ety_CentralReg;
      fHandles[ "Muon_Isol_Muid_sumet_CentralReg" ] = &Muon_Isol_Muid_sumet_CentralReg;
      fHandles[ "Muon_Isol_Muid_phi_CentralReg" ] = &Muon_Isol_Muid_phi_CentralReg;
      fHandles[ "Muon_Isol_Muid_etx_EndcapRegion" ] = &Muon_Isol_Muid_etx_EndcapRegion;
      fHandles[ "Muon_Isol_Muid_ety_EndcapRegion" ] = &Muon_Isol_Muid_ety_EndcapRegion;
      fHandles[ "Muon_Isol_Muid_sumet_EndcapRegion" ] = &Muon_Isol_Muid_sumet_EndcapRegion;
      fHandles[ "Muon_Isol_Muid_phi_EndcapRegion" ] = &Muon_Isol_Muid_phi_EndcapRegion;
      fHandles[ "Muon_Isol_Muid_etx_ForwardReg" ] = &Muon_Isol_Muid_etx_ForwardReg;
      fHandles[ "Muon_Isol_Muid_ety_ForwardReg" ] = &Muon_Isol_Muid_ety_ForwardReg;
      fHandles[ "Muon_Isol_Muid_sumet_ForwardReg" ] = &Muon_Isol_Muid_sumet_ForwardReg;
      fHandles[ "Muon_Isol_Muid_phi_ForwardReg" ] = &Muon_Isol_Muid_phi_ForwardReg;
      fHandles[ "STVF_Muon_Isol_Muid_etx" ] = &STVF_Muon_Isol_Muid_etx;
      fHandles[ "STVF_Muon_Isol_Muid_ety" ] = &STVF_Muon_Isol_Muid_ety;
      fHandles[ "STVF_Muon_Isol_Muid_sumet" ] = &STVF_Muon_Isol_Muid_sumet;
      fHandles[ "STVF_Muon_Isol_Muid_etx_CentralReg" ] = &STVF_Muon_Isol_Muid_etx_CentralReg;
      fHandles[ "STVF_Muon_Isol_Muid_ety_CentralReg" ] = &STVF_Muon_Isol_Muid_ety_CentralReg;
      fHandles[ "STVF_Muon_Isol_Muid_sumet_CentralReg" ] = &STVF_Muon_Isol_Muid_sumet_CentralReg;
      fHandles[ "STVF_Muon_Isol_Muid_phi_CentralReg" ] = &STVF_Muon_Isol_Muid_phi_CentralReg;
      fHandles[ "STVF_Muon_Isol_Muid_etx_EndcapRegion" ] = &STVF_Muon_Isol_Muid_etx_EndcapRegion;
      fHandles[ "STVF_Muon_Isol_Muid_ety_EndcapRegion" ] = &STVF_Muon_Isol_Muid_ety_EndcapRegion;
      fHandles[ "STVF_Muon_Isol_Muid_sumet_EndcapRegion" ] = &STVF_Muon_Isol_Muid_sumet_EndcapRegion;
      fHandles[ "STVF_Muon_Isol_Muid_phi_EndcapRegion" ] = &STVF_Muon_Isol_Muid_phi_EndcapRegion;
      fHandles[ "STVF_Muon_Isol_Muid_etx_ForwardReg" ] = &STVF_Muon_Isol_Muid_etx_ForwardReg;
      fHandles[ "STVF_Muon_Isol_Muid_ety_ForwardReg" ] = &STVF_Muon_Isol_Muid_ety_ForwardReg;
      fHandles[ "STVF_Muon_Isol_Muid_sumet_ForwardReg" ] = &STVF_Muon_Isol_Muid_sumet_ForwardReg;
      fHandles[ "STVF_Muon_Isol_Muid_phi_ForwardReg" ] = &STVF_Muon_Isol_Muid_phi_ForwardReg;
      fHandles[ "Muon_NonIsol_Muid_etx" ] = &Muon_NonIsol_Muid_etx;
      fHandles[ "Muon_NonIsol_Muid_ety" ] = &Muon_NonIsol_Muid_ety;
      fHandles[ "Muon_NonIsol_Muid_sumet" ] = &Muon_NonIsol_Muid_sumet;
      fHandles[ "Muon_NonIsol_Muid_etx_CentralReg" ] = &Muon_NonIsol_Muid_etx_CentralReg;
      fHandles[ "Muon_NonIsol_Muid_ety_CentralReg" ] = &Muon_NonIsol_Muid_ety_CentralReg;
      fHandles[ "Muon_NonIsol_Muid_sumet_CentralReg" ] = &Muon_NonIsol_Muid_sumet_CentralReg;
      fHandles[ "Muon_NonIsol_Muid_phi_CentralReg" ] = &Muon_NonIsol_Muid_phi_CentralReg;
      fHandles[ "Muon_NonIsol_Muid_etx_EndcapRegion" ] = &Muon_NonIsol_Muid_etx_EndcapRegion;
      fHandles[ "Muon_NonIsol_Muid_ety_EndcapRegion" ] = &Muon_NonIsol_Muid_ety_EndcapRegion;
      fHandles[ "Muon_NonIsol_Muid_sumet_EndcapRegion" ] = &Muon_NonIsol_Muid_sumet_EndcapRegion;
      fHandles[ "Muon_NonIsol_Muid_phi_EndcapRegion" ] = &Muon_NonIsol_Muid_phi_EndcapRegion;
      fHandles[ "Muon_NonIsol_Muid_etx_ForwardReg" ] = &Muon_NonIsol_Muid_etx_ForwardReg;
      fHandles[ "Muon_NonIsol_Muid_ety_ForwardReg" ] = &Muon_NonIsol_Muid_ety_ForwardReg;
      fHandles[ "Muon_NonIsol_Muid_sumet_ForwardReg" ] = &Muon_NonIsol_Muid_sumet_ForwardReg;
      fHandles[ "Muon_NonIsol_Muid_phi_ForwardReg" ] = &Muon_NonIsol_Muid_phi_ForwardReg;
      fHandles[ "STVF_Muon_NonIsol_Muid_etx" ] = &STVF_Muon_NonIsol_Muid_etx;
      fHandles[ "STVF_Muon_NonIsol_Muid_ety" ] = &STVF_Muon_NonIsol_Muid_ety;
      fHandles[ "STVF_Muon_NonIsol_Muid_sumet" ] = &STVF_Muon_NonIsol_Muid_sumet;
      fHandles[ "STVF_Muon_NonIsol_Muid_etx_CentralReg" ] = &STVF_Muon_NonIsol_Muid_etx_CentralReg;
      fHandles[ "STVF_Muon_NonIsol_Muid_ety_CentralReg" ] = &STVF_Muon_NonIsol_Muid_ety_CentralReg;
      fHandles[ "STVF_Muon_NonIsol_Muid_sumet_CentralReg" ] = &STVF_Muon_NonIsol_Muid_sumet_CentralReg;
      fHandles[ "STVF_Muon_NonIsol_Muid_phi_CentralReg" ] = &STVF_Muon_NonIsol_Muid_phi_CentralReg;
      fHandles[ "STVF_Muon_NonIsol_Muid_etx_EndcapRegion" ] = &STVF_Muon_NonIsol_Muid_etx_EndcapRegion;
      fHandles[ "STVF_Muon_NonIsol_Muid_ety_EndcapRegion" ] = &STVF_Muon_NonIsol_Muid_ety_EndcapRegion;
      fHandles[ "STVF_Muon_NonIsol_Muid_sumet_EndcapRegion" ] = &STVF_Muon_NonIsol_Muid_sumet_EndcapRegion;
      fHandles[ "STVF_Muon_NonIsol_Muid_phi_EndcapRegion" ] = &STVF_Muon_NonIsol_Muid_phi_EndcapRegion;
      fHandles[ "STVF_Muon_NonIsol_Muid_etx_ForwardReg" ] = &STVF_Muon_NonIsol_Muid_etx_ForwardReg;
      fHandles[ "STVF_Muon_NonIsol_Muid_ety_ForwardReg" ] = &STVF_Muon_NonIsol_Muid_ety_ForwardReg;
      fHandles[ "STVF_Muon_NonIsol_Muid_sumet_ForwardReg" ] = &STVF_Muon_NonIsol_Muid_sumet_ForwardReg;
      fHandles[ "STVF_Muon_NonIsol_Muid_phi_ForwardReg" ] = &STVF_Muon_NonIsol_Muid_phi_ForwardReg;
      fHandles[ "Muon_Total_Muid_etx" ] = &Muon_Total_Muid_etx;
      fHandles[ "Muon_Total_Muid_ety" ] = &Muon_Total_Muid_ety;
      fHandles[ "Muon_Total_Muid_sumet" ] = &Muon_Total_Muid_sumet;
      fHandles[ "Muon_Total_Muid_etx_CentralReg" ] = &Muon_Total_Muid_etx_CentralReg;
      fHandles[ "Muon_Total_Muid_ety_CentralReg" ] = &Muon_Total_Muid_ety_CentralReg;
      fHandles[ "Muon_Total_Muid_sumet_CentralReg" ] = &Muon_Total_Muid_sumet_CentralReg;
      fHandles[ "Muon_Total_Muid_phi_CentralReg" ] = &Muon_Total_Muid_phi_CentralReg;
      fHandles[ "Muon_Total_Muid_etx_EndcapRegion" ] = &Muon_Total_Muid_etx_EndcapRegion;
      fHandles[ "Muon_Total_Muid_ety_EndcapRegion" ] = &Muon_Total_Muid_ety_EndcapRegion;
      fHandles[ "Muon_Total_Muid_sumet_EndcapRegion" ] = &Muon_Total_Muid_sumet_EndcapRegion;
      fHandles[ "Muon_Total_Muid_phi_EndcapRegion" ] = &Muon_Total_Muid_phi_EndcapRegion;
      fHandles[ "Muon_Total_Muid_etx_ForwardReg" ] = &Muon_Total_Muid_etx_ForwardReg;
      fHandles[ "Muon_Total_Muid_ety_ForwardReg" ] = &Muon_Total_Muid_ety_ForwardReg;
      fHandles[ "Muon_Total_Muid_sumet_ForwardReg" ] = &Muon_Total_Muid_sumet_ForwardReg;
      fHandles[ "Muon_Total_Muid_phi_ForwardReg" ] = &Muon_Total_Muid_phi_ForwardReg;
      fHandles[ "STVF_Muon_Total_Muid_etx" ] = &STVF_Muon_Total_Muid_etx;
      fHandles[ "STVF_Muon_Total_Muid_ety" ] = &STVF_Muon_Total_Muid_ety;
      fHandles[ "STVF_Muon_Total_Muid_sumet" ] = &STVF_Muon_Total_Muid_sumet;
      fHandles[ "STVF_Muon_Total_Muid_etx_CentralReg" ] = &STVF_Muon_Total_Muid_etx_CentralReg;
      fHandles[ "STVF_Muon_Total_Muid_ety_CentralReg" ] = &STVF_Muon_Total_Muid_ety_CentralReg;
      fHandles[ "STVF_Muon_Total_Muid_sumet_CentralReg" ] = &STVF_Muon_Total_Muid_sumet_CentralReg;
      fHandles[ "STVF_Muon_Total_Muid_phi_CentralReg" ] = &STVF_Muon_Total_Muid_phi_CentralReg;
      fHandles[ "STVF_Muon_Total_Muid_etx_EndcapRegion" ] = &STVF_Muon_Total_Muid_etx_EndcapRegion;
      fHandles[ "STVF_Muon_Total_Muid_ety_EndcapRegion" ] = &STVF_Muon_Total_Muid_ety_EndcapRegion;
      fHandles[ "STVF_Muon_Total_Muid_sumet_EndcapRegion" ] = &STVF_Muon_Total_Muid_sumet_EndcapRegion;
      fHandles[ "STVF_Muon_Total_Muid_phi_EndcapRegion" ] = &STVF_Muon_Total_Muid_phi_EndcapRegion;
      fHandles[ "STVF_Muon_Total_Muid_etx_ForwardReg" ] = &STVF_Muon_Total_Muid_etx_ForwardReg;
      fHandles[ "STVF_Muon_Total_Muid_ety_ForwardReg" ] = &STVF_Muon_Total_Muid_ety_ForwardReg;
      fHandles[ "STVF_Muon_Total_Muid_sumet_ForwardReg" ] = &STVF_Muon_Total_Muid_sumet_ForwardReg;
      fHandles[ "STVF_Muon_Total_Muid_phi_ForwardReg" ] = &STVF_Muon_Total_Muid_phi_ForwardReg;
      fHandles[ "Track_etx" ] = &Track_etx;
      fHandles[ "Track_ety" ] = &Track_ety;
      fHandles[ "Track_sumet" ] = &Track_sumet;
      fHandles[ "Track_etx_CentralReg" ] = &Track_etx_CentralReg;
      fHandles[ "Track_ety_CentralReg" ] = &Track_ety_CentralReg;
      fHandles[ "Track_sumet_CentralReg" ] = &Track_sumet_CentralReg;
      fHandles[ "Track_phi_CentralReg" ] = &Track_phi_CentralReg;
      fHandles[ "Track_etx_EndcapRegion" ] = &Track_etx_EndcapRegion;
      fHandles[ "Track_ety_EndcapRegion" ] = &Track_ety_EndcapRegion;
      fHandles[ "Track_sumet_EndcapRegion" ] = &Track_sumet_EndcapRegion;
      fHandles[ "Track_phi_EndcapRegion" ] = &Track_phi_EndcapRegion;
      fHandles[ "Track_etx_ForwardReg" ] = &Track_etx_ForwardReg;
      fHandles[ "Track_ety_ForwardReg" ] = &Track_ety_ForwardReg;
      fHandles[ "Track_sumet_ForwardReg" ] = &Track_sumet_ForwardReg;
      fHandles[ "Track_phi_ForwardReg" ] = &Track_phi_ForwardReg;
      fHandles[ "STVF_Track_etx" ] = &STVF_Track_etx;
      fHandles[ "STVF_Track_ety" ] = &STVF_Track_ety;
      fHandles[ "STVF_Track_sumet" ] = &STVF_Track_sumet;
      fHandles[ "STVF_Track_etx_CentralReg" ] = &STVF_Track_etx_CentralReg;
      fHandles[ "STVF_Track_ety_CentralReg" ] = &STVF_Track_ety_CentralReg;
      fHandles[ "STVF_Track_sumet_CentralReg" ] = &STVF_Track_sumet_CentralReg;
      fHandles[ "STVF_Track_phi_CentralReg" ] = &STVF_Track_phi_CentralReg;
      fHandles[ "STVF_Track_etx_EndcapRegion" ] = &STVF_Track_etx_EndcapRegion;
      fHandles[ "STVF_Track_ety_EndcapRegion" ] = &STVF_Track_ety_EndcapRegion;
      fHandles[ "STVF_Track_sumet_EndcapRegion" ] = &STVF_Track_sumet_EndcapRegion;
      fHandles[ "STVF_Track_phi_EndcapRegion" ] = &STVF_Track_phi_EndcapRegion;
      fHandles[ "STVF_Track_etx_ForwardReg" ] = &STVF_Track_etx_ForwardReg;
      fHandles[ "STVF_Track_ety_ForwardReg" ] = &STVF_Track_ety_ForwardReg;
      fHandles[ "STVF_Track_sumet_ForwardReg" ] = &STVF_Track_sumet_ForwardReg;
      fHandles[ "STVF_Track_phi_ForwardReg" ] = &STVF_Track_phi_ForwardReg;
      fHandles[ "SoftJets_etx" ] = &SoftJets_etx;
      fHandles[ "SoftJets_ety" ] = &SoftJets_ety;
      fHandles[ "SoftJets_sumet" ] = &SoftJets_sumet;
      fHandles[ "SoftJets_etx_CentralReg" ] = &SoftJets_etx_CentralReg;
      fHandles[ "SoftJets_ety_CentralReg" ] = &SoftJets_ety_CentralReg;
      fHandles[ "SoftJets_sumet_CentralReg" ] = &SoftJets_sumet_CentralReg;
      fHandles[ "SoftJets_phi_CentralReg" ] = &SoftJets_phi_CentralReg;
      fHandles[ "SoftJets_etx_EndcapRegion" ] = &SoftJets_etx_EndcapRegion;
      fHandles[ "SoftJets_ety_EndcapRegion" ] = &SoftJets_ety_EndcapRegion;
      fHandles[ "SoftJets_sumet_EndcapRegion" ] = &SoftJets_sumet_EndcapRegion;
      fHandles[ "SoftJets_phi_EndcapRegion" ] = &SoftJets_phi_EndcapRegion;
      fHandles[ "SoftJets_etx_ForwardReg" ] = &SoftJets_etx_ForwardReg;
      fHandles[ "SoftJets_ety_ForwardReg" ] = &SoftJets_ety_ForwardReg;
      fHandles[ "SoftJets_sumet_ForwardReg" ] = &SoftJets_sumet_ForwardReg;
      fHandles[ "SoftJets_phi_ForwardReg" ] = &SoftJets_phi_ForwardReg;
      fHandles[ "STVF_SoftJets_etx" ] = &STVF_SoftJets_etx;
      fHandles[ "STVF_SoftJets_ety" ] = &STVF_SoftJets_ety;
      fHandles[ "STVF_SoftJets_sumet" ] = &STVF_SoftJets_sumet;
      fHandles[ "STVF_SoftJets_etx_CentralReg" ] = &STVF_SoftJets_etx_CentralReg;
      fHandles[ "STVF_SoftJets_ety_CentralReg" ] = &STVF_SoftJets_ety_CentralReg;
      fHandles[ "STVF_SoftJets_sumet_CentralReg" ] = &STVF_SoftJets_sumet_CentralReg;
      fHandles[ "STVF_SoftJets_phi_CentralReg" ] = &STVF_SoftJets_phi_CentralReg;
      fHandles[ "STVF_SoftJets_etx_EndcapRegion" ] = &STVF_SoftJets_etx_EndcapRegion;
      fHandles[ "STVF_SoftJets_ety_EndcapRegion" ] = &STVF_SoftJets_ety_EndcapRegion;
      fHandles[ "STVF_SoftJets_sumet_EndcapRegion" ] = &STVF_SoftJets_sumet_EndcapRegion;
      fHandles[ "STVF_SoftJets_phi_EndcapRegion" ] = &STVF_SoftJets_phi_EndcapRegion;
      fHandles[ "STVF_SoftJets_etx_ForwardReg" ] = &STVF_SoftJets_etx_ForwardReg;
      fHandles[ "STVF_SoftJets_ety_ForwardReg" ] = &STVF_SoftJets_ety_ForwardReg;
      fHandles[ "STVF_SoftJets_sumet_ForwardReg" ] = &STVF_SoftJets_sumet_ForwardReg;
      fHandles[ "STVF_SoftJets_phi_ForwardReg" ] = &STVF_SoftJets_phi_ForwardReg;
      fHandles[ "RefMuon_etx" ] = &RefMuon_etx;
      fHandles[ "RefMuon_ety" ] = &RefMuon_ety;
      fHandles[ "RefMuon_sumet" ] = &RefMuon_sumet;
      fHandles[ "RefMuon_etx_CentralReg" ] = &RefMuon_etx_CentralReg;
      fHandles[ "RefMuon_ety_CentralReg" ] = &RefMuon_ety_CentralReg;
      fHandles[ "RefMuon_sumet_CentralReg" ] = &RefMuon_sumet_CentralReg;
      fHandles[ "RefMuon_phi_CentralReg" ] = &RefMuon_phi_CentralReg;
      fHandles[ "RefMuon_etx_EndcapRegion" ] = &RefMuon_etx_EndcapRegion;
      fHandles[ "RefMuon_ety_EndcapRegion" ] = &RefMuon_ety_EndcapRegion;
      fHandles[ "RefMuon_sumet_EndcapRegion" ] = &RefMuon_sumet_EndcapRegion;
      fHandles[ "RefMuon_phi_EndcapRegion" ] = &RefMuon_phi_EndcapRegion;
      fHandles[ "RefMuon_etx_ForwardReg" ] = &RefMuon_etx_ForwardReg;
      fHandles[ "RefMuon_ety_ForwardReg" ] = &RefMuon_ety_ForwardReg;
      fHandles[ "RefMuon_sumet_ForwardReg" ] = &RefMuon_sumet_ForwardReg;
      fHandles[ "RefMuon_phi_ForwardReg" ] = &RefMuon_phi_ForwardReg;
      fHandles[ "STVF_RefMuon_etx" ] = &STVF_RefMuon_etx;
      fHandles[ "STVF_RefMuon_ety" ] = &STVF_RefMuon_ety;
      fHandles[ "STVF_RefMuon_sumet" ] = &STVF_RefMuon_sumet;
      fHandles[ "STVF_RefMuon_etx_CentralReg" ] = &STVF_RefMuon_etx_CentralReg;
      fHandles[ "STVF_RefMuon_ety_CentralReg" ] = &STVF_RefMuon_ety_CentralReg;
      fHandles[ "STVF_RefMuon_sumet_CentralReg" ] = &STVF_RefMuon_sumet_CentralReg;
      fHandles[ "STVF_RefMuon_phi_CentralReg" ] = &STVF_RefMuon_phi_CentralReg;
      fHandles[ "STVF_RefMuon_etx_EndcapRegion" ] = &STVF_RefMuon_etx_EndcapRegion;
      fHandles[ "STVF_RefMuon_ety_EndcapRegion" ] = &STVF_RefMuon_ety_EndcapRegion;
      fHandles[ "STVF_RefMuon_sumet_EndcapRegion" ] = &STVF_RefMuon_sumet_EndcapRegion;
      fHandles[ "STVF_RefMuon_phi_EndcapRegion" ] = &STVF_RefMuon_phi_EndcapRegion;
      fHandles[ "STVF_RefMuon_etx_ForwardReg" ] = &STVF_RefMuon_etx_ForwardReg;
      fHandles[ "STVF_RefMuon_ety_ForwardReg" ] = &STVF_RefMuon_ety_ForwardReg;
      fHandles[ "STVF_RefMuon_sumet_ForwardReg" ] = &STVF_RefMuon_sumet_ForwardReg;
      fHandles[ "STVF_RefMuon_phi_ForwardReg" ] = &STVF_RefMuon_phi_ForwardReg;
      fHandles[ "MuonBoy_etx" ] = &MuonBoy_etx;
      fHandles[ "MuonBoy_ety" ] = &MuonBoy_ety;
      fHandles[ "MuonBoy_sumet" ] = &MuonBoy_sumet;
      fHandles[ "MuonBoy_etx_CentralReg" ] = &MuonBoy_etx_CentralReg;
      fHandles[ "MuonBoy_ety_CentralReg" ] = &MuonBoy_ety_CentralReg;
      fHandles[ "MuonBoy_sumet_CentralReg" ] = &MuonBoy_sumet_CentralReg;
      fHandles[ "MuonBoy_phi_CentralReg" ] = &MuonBoy_phi_CentralReg;
      fHandles[ "MuonBoy_etx_EndcapRegion" ] = &MuonBoy_etx_EndcapRegion;
      fHandles[ "MuonBoy_ety_EndcapRegion" ] = &MuonBoy_ety_EndcapRegion;
      fHandles[ "MuonBoy_sumet_EndcapRegion" ] = &MuonBoy_sumet_EndcapRegion;
      fHandles[ "MuonBoy_phi_EndcapRegion" ] = &MuonBoy_phi_EndcapRegion;
      fHandles[ "MuonBoy_etx_ForwardReg" ] = &MuonBoy_etx_ForwardReg;
      fHandles[ "MuonBoy_ety_ForwardReg" ] = &MuonBoy_ety_ForwardReg;
      fHandles[ "MuonBoy_sumet_ForwardReg" ] = &MuonBoy_sumet_ForwardReg;
      fHandles[ "MuonBoy_phi_ForwardReg" ] = &MuonBoy_phi_ForwardReg;
      fHandles[ "STVF_MuonBoy_etx" ] = &STVF_MuonBoy_etx;
      fHandles[ "STVF_MuonBoy_ety" ] = &STVF_MuonBoy_ety;
      fHandles[ "STVF_MuonBoy_sumet" ] = &STVF_MuonBoy_sumet;
      fHandles[ "STVF_MuonBoy_etx_CentralReg" ] = &STVF_MuonBoy_etx_CentralReg;
      fHandles[ "STVF_MuonBoy_ety_CentralReg" ] = &STVF_MuonBoy_ety_CentralReg;
      fHandles[ "STVF_MuonBoy_sumet_CentralReg" ] = &STVF_MuonBoy_sumet_CentralReg;
      fHandles[ "STVF_MuonBoy_phi_CentralReg" ] = &STVF_MuonBoy_phi_CentralReg;
      fHandles[ "STVF_MuonBoy_etx_EndcapRegion" ] = &STVF_MuonBoy_etx_EndcapRegion;
      fHandles[ "STVF_MuonBoy_ety_EndcapRegion" ] = &STVF_MuonBoy_ety_EndcapRegion;
      fHandles[ "STVF_MuonBoy_sumet_EndcapRegion" ] = &STVF_MuonBoy_sumet_EndcapRegion;
      fHandles[ "STVF_MuonBoy_phi_EndcapRegion" ] = &STVF_MuonBoy_phi_EndcapRegion;
      fHandles[ "STVF_MuonBoy_etx_ForwardReg" ] = &STVF_MuonBoy_etx_ForwardReg;
      fHandles[ "STVF_MuonBoy_ety_ForwardReg" ] = &STVF_MuonBoy_ety_ForwardReg;
      fHandles[ "STVF_MuonBoy_sumet_ForwardReg" ] = &STVF_MuonBoy_sumet_ForwardReg;
      fHandles[ "STVF_MuonBoy_phi_ForwardReg" ] = &STVF_MuonBoy_phi_ForwardReg;
      fHandles[ "STVF_CellOut_Track_etx" ] = &STVF_CellOut_Track_etx;
      fHandles[ "STVF_CellOut_Track_ety" ] = &STVF_CellOut_Track_ety;
      fHandles[ "STVF_CellOut_Track_sumet" ] = &STVF_CellOut_Track_sumet;
      fHandles[ "STVF_CellOut_Track_etx_CentralReg" ] = &STVF_CellOut_Track_etx_CentralReg;
      fHandles[ "STVF_CellOut_Track_ety_CentralReg" ] = &STVF_CellOut_Track_ety_CentralReg;
      fHandles[ "STVF_CellOut_Track_sumet_CentralReg" ] = &STVF_CellOut_Track_sumet_CentralReg;
      fHandles[ "STVF_CellOut_Track_phi_CentralReg" ] = &STVF_CellOut_Track_phi_CentralReg;
      fHandles[ "STVF_CellOut_Track_etx_EndcapRegion" ] = &STVF_CellOut_Track_etx_EndcapRegion;
      fHandles[ "STVF_CellOut_Track_ety_EndcapRegion" ] = &STVF_CellOut_Track_ety_EndcapRegion;
      fHandles[ "STVF_CellOut_Track_sumet_EndcapRegion" ] = &STVF_CellOut_Track_sumet_EndcapRegion;
      fHandles[ "STVF_CellOut_Track_phi_EndcapRegion" ] = &STVF_CellOut_Track_phi_EndcapRegion;
      fHandles[ "STVF_CellOut_Track_etx_ForwardReg" ] = &STVF_CellOut_Track_etx_ForwardReg;
      fHandles[ "STVF_CellOut_Track_ety_ForwardReg" ] = &STVF_CellOut_Track_ety_ForwardReg;
      fHandles[ "STVF_CellOut_Track_sumet_ForwardReg" ] = &STVF_CellOut_Track_sumet_ForwardReg;
      fHandles[ "STVF_CellOut_Track_phi_ForwardReg" ] = &STVF_CellOut_Track_phi_ForwardReg;
      fHandles[ "STVF_CellOut_TrackPV_etx" ] = &STVF_CellOut_TrackPV_etx;
      fHandles[ "STVF_CellOut_TrackPV_ety" ] = &STVF_CellOut_TrackPV_ety;
      fHandles[ "STVF_CellOut_TrackPV_sumet" ] = &STVF_CellOut_TrackPV_sumet;
      fHandles[ "STVF_CellOut_TrackPV_etx_CentralReg" ] = &STVF_CellOut_TrackPV_etx_CentralReg;
      fHandles[ "STVF_CellOut_TrackPV_ety_CentralReg" ] = &STVF_CellOut_TrackPV_ety_CentralReg;
      fHandles[ "STVF_CellOut_TrackPV_sumet_CentralReg" ] = &STVF_CellOut_TrackPV_sumet_CentralReg;
      fHandles[ "STVF_CellOut_TrackPV_phi_CentralReg" ] = &STVF_CellOut_TrackPV_phi_CentralReg;
      fHandles[ "STVF_CellOut_TrackPV_etx_EndcapRegion" ] = &STVF_CellOut_TrackPV_etx_EndcapRegion;
      fHandles[ "STVF_CellOut_TrackPV_ety_EndcapRegion" ] = &STVF_CellOut_TrackPV_ety_EndcapRegion;
      fHandles[ "STVF_CellOut_TrackPV_sumet_EndcapRegion" ] = &STVF_CellOut_TrackPV_sumet_EndcapRegion;
      fHandles[ "STVF_CellOut_TrackPV_phi_EndcapRegion" ] = &STVF_CellOut_TrackPV_phi_EndcapRegion;
      fHandles[ "STVF_CellOut_TrackPV_etx_ForwardReg" ] = &STVF_CellOut_TrackPV_etx_ForwardReg;
      fHandles[ "STVF_CellOut_TrackPV_ety_ForwardReg" ] = &STVF_CellOut_TrackPV_ety_ForwardReg;
      fHandles[ "STVF_CellOut_TrackPV_sumet_ForwardReg" ] = &STVF_CellOut_TrackPV_sumet_ForwardReg;
      fHandles[ "STVF_CellOut_TrackPV_phi_ForwardReg" ] = &STVF_CellOut_TrackPV_phi_ForwardReg;
      fHandles[ "STVF_CellOutCorr_etx" ] = &STVF_CellOutCorr_etx;
      fHandles[ "STVF_CellOutCorr_ety" ] = &STVF_CellOutCorr_ety;
      fHandles[ "STVF_CellOutCorr_sumet" ] = &STVF_CellOutCorr_sumet;
      fHandles[ "STVF_CellOutCorr_etx_CentralReg" ] = &STVF_CellOutCorr_etx_CentralReg;
      fHandles[ "STVF_CellOutCorr_ety_CentralReg" ] = &STVF_CellOutCorr_ety_CentralReg;
      fHandles[ "STVF_CellOutCorr_sumet_CentralReg" ] = &STVF_CellOutCorr_sumet_CentralReg;
      fHandles[ "STVF_CellOutCorr_phi_CentralReg" ] = &STVF_CellOutCorr_phi_CentralReg;
      fHandles[ "STVF_CellOutCorr_etx_EndcapRegion" ] = &STVF_CellOutCorr_etx_EndcapRegion;
      fHandles[ "STVF_CellOutCorr_ety_EndcapRegion" ] = &STVF_CellOutCorr_ety_EndcapRegion;
      fHandles[ "STVF_CellOutCorr_sumet_EndcapRegion" ] = &STVF_CellOutCorr_sumet_EndcapRegion;
      fHandles[ "STVF_CellOutCorr_phi_EndcapRegion" ] = &STVF_CellOutCorr_phi_EndcapRegion;
      fHandles[ "STVF_CellOutCorr_etx_ForwardReg" ] = &STVF_CellOutCorr_etx_ForwardReg;
      fHandles[ "STVF_CellOutCorr_ety_ForwardReg" ] = &STVF_CellOutCorr_ety_ForwardReg;
      fHandles[ "STVF_CellOutCorr_sumet_ForwardReg" ] = &STVF_CellOutCorr_sumet_ForwardReg;
      fHandles[ "STVF_CellOutCorr_phi_ForwardReg" ] = &STVF_CellOutCorr_phi_ForwardReg;
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
        RefGamma_etx_CentralReg( this, ::TString( prefix ) + "RefGamma_etx_CentralReg", 0 ),
        RefGamma_ety_CentralReg( this, ::TString( prefix ) + "RefGamma_ety_CentralReg", 0 ),
        RefGamma_sumet_CentralReg( this, ::TString( prefix ) + "RefGamma_sumet_CentralReg", 0 ),
        RefGamma_phi_CentralReg( this, ::TString( prefix ) + "RefGamma_phi_CentralReg", 0 ),
        RefGamma_etx_EndcapRegion( this, ::TString( prefix ) + "RefGamma_etx_EndcapRegion", 0 ),
        RefGamma_ety_EndcapRegion( this, ::TString( prefix ) + "RefGamma_ety_EndcapRegion", 0 ),
        RefGamma_sumet_EndcapRegion( this, ::TString( prefix ) + "RefGamma_sumet_EndcapRegion", 0 ),
        RefGamma_phi_EndcapRegion( this, ::TString( prefix ) + "RefGamma_phi_EndcapRegion", 0 ),
        RefGamma_etx_ForwardReg( this, ::TString( prefix ) + "RefGamma_etx_ForwardReg", 0 ),
        RefGamma_ety_ForwardReg( this, ::TString( prefix ) + "RefGamma_ety_ForwardReg", 0 ),
        RefGamma_sumet_ForwardReg( this, ::TString( prefix ) + "RefGamma_sumet_ForwardReg", 0 ),
        RefGamma_phi_ForwardReg( this, ::TString( prefix ) + "RefGamma_phi_ForwardReg", 0 ),
        STVF_RefGamma_etx( this, ::TString( prefix ) + "STVF_RefGamma_etx", 0 ),
        STVF_RefGamma_ety( this, ::TString( prefix ) + "STVF_RefGamma_ety", 0 ),
        STVF_RefGamma_sumet( this, ::TString( prefix ) + "STVF_RefGamma_sumet", 0 ),
        STVF_RefGamma_etx_CentralReg( this, ::TString( prefix ) + "STVF_RefGamma_etx_CentralReg", 0 ),
        STVF_RefGamma_ety_CentralReg( this, ::TString( prefix ) + "STVF_RefGamma_ety_CentralReg", 0 ),
        STVF_RefGamma_sumet_CentralReg( this, ::TString( prefix ) + "STVF_RefGamma_sumet_CentralReg", 0 ),
        STVF_RefGamma_phi_CentralReg( this, ::TString( prefix ) + "STVF_RefGamma_phi_CentralReg", 0 ),
        STVF_RefGamma_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_RefGamma_etx_EndcapRegion", 0 ),
        STVF_RefGamma_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_RefGamma_ety_EndcapRegion", 0 ),
        STVF_RefGamma_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_RefGamma_sumet_EndcapRegion", 0 ),
        STVF_RefGamma_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_RefGamma_phi_EndcapRegion", 0 ),
        STVF_RefGamma_etx_ForwardReg( this, ::TString( prefix ) + "STVF_RefGamma_etx_ForwardReg", 0 ),
        STVF_RefGamma_ety_ForwardReg( this, ::TString( prefix ) + "STVF_RefGamma_ety_ForwardReg", 0 ),
        STVF_RefGamma_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_RefGamma_sumet_ForwardReg", 0 ),
        STVF_RefGamma_phi_ForwardReg( this, ::TString( prefix ) + "STVF_RefGamma_phi_ForwardReg", 0 ),
        RefFinal_etx( this, ::TString( prefix ) + "RefFinal_etx", 0 ),
        RefFinal_ety( this, ::TString( prefix ) + "RefFinal_ety", 0 ),
        RefFinal_sumet( this, ::TString( prefix ) + "RefFinal_sumet", 0 ),
        RefFinal_etx_CentralReg( this, ::TString( prefix ) + "RefFinal_etx_CentralReg", 0 ),
        RefFinal_ety_CentralReg( this, ::TString( prefix ) + "RefFinal_ety_CentralReg", 0 ),
        RefFinal_sumet_CentralReg( this, ::TString( prefix ) + "RefFinal_sumet_CentralReg", 0 ),
        RefFinal_phi_CentralReg( this, ::TString( prefix ) + "RefFinal_phi_CentralReg", 0 ),
        RefFinal_etx_EndcapRegion( this, ::TString( prefix ) + "RefFinal_etx_EndcapRegion", 0 ),
        RefFinal_ety_EndcapRegion( this, ::TString( prefix ) + "RefFinal_ety_EndcapRegion", 0 ),
        RefFinal_sumet_EndcapRegion( this, ::TString( prefix ) + "RefFinal_sumet_EndcapRegion", 0 ),
        RefFinal_phi_EndcapRegion( this, ::TString( prefix ) + "RefFinal_phi_EndcapRegion", 0 ),
        RefFinal_etx_ForwardReg( this, ::TString( prefix ) + "RefFinal_etx_ForwardReg", 0 ),
        RefFinal_ety_ForwardReg( this, ::TString( prefix ) + "RefFinal_ety_ForwardReg", 0 ),
        RefFinal_sumet_ForwardReg( this, ::TString( prefix ) + "RefFinal_sumet_ForwardReg", 0 ),
        RefFinal_phi_ForwardReg( this, ::TString( prefix ) + "RefFinal_phi_ForwardReg", 0 ),
        STVF_RefFinal_etx( this, ::TString( prefix ) + "STVF_RefFinal_etx", 0 ),
        STVF_RefFinal_ety( this, ::TString( prefix ) + "STVF_RefFinal_ety", 0 ),
        STVF_RefFinal_sumet( this, ::TString( prefix ) + "STVF_RefFinal_sumet", 0 ),
        STVF_RefFinal_etx_CentralReg( this, ::TString( prefix ) + "STVF_RefFinal_etx_CentralReg", 0 ),
        STVF_RefFinal_ety_CentralReg( this, ::TString( prefix ) + "STVF_RefFinal_ety_CentralReg", 0 ),
        STVF_RefFinal_sumet_CentralReg( this, ::TString( prefix ) + "STVF_RefFinal_sumet_CentralReg", 0 ),
        STVF_RefFinal_phi_CentralReg( this, ::TString( prefix ) + "STVF_RefFinal_phi_CentralReg", 0 ),
        STVF_RefFinal_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_RefFinal_etx_EndcapRegion", 0 ),
        STVF_RefFinal_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_RefFinal_ety_EndcapRegion", 0 ),
        STVF_RefFinal_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_RefFinal_sumet_EndcapRegion", 0 ),
        STVF_RefFinal_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_RefFinal_phi_EndcapRegion", 0 ),
        STVF_RefFinal_etx_ForwardReg( this, ::TString( prefix ) + "STVF_RefFinal_etx_ForwardReg", 0 ),
        STVF_RefFinal_ety_ForwardReg( this, ::TString( prefix ) + "STVF_RefFinal_ety_ForwardReg", 0 ),
        STVF_RefFinal_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_RefFinal_sumet_ForwardReg", 0 ),
        STVF_RefFinal_phi_ForwardReg( this, ::TString( prefix ) + "STVF_RefFinal_phi_ForwardReg", 0 ),
        RefJet_etx( this, ::TString( prefix ) + "RefJet_etx", 0 ),
        RefJet_ety( this, ::TString( prefix ) + "RefJet_ety", 0 ),
        RefJet_sumet( this, ::TString( prefix ) + "RefJet_sumet", 0 ),
        RefJet_etx_CentralReg( this, ::TString( prefix ) + "RefJet_etx_CentralReg", 0 ),
        RefJet_ety_CentralReg( this, ::TString( prefix ) + "RefJet_ety_CentralReg", 0 ),
        RefJet_sumet_CentralReg( this, ::TString( prefix ) + "RefJet_sumet_CentralReg", 0 ),
        RefJet_phi_CentralReg( this, ::TString( prefix ) + "RefJet_phi_CentralReg", 0 ),
        RefJet_etx_EndcapRegion( this, ::TString( prefix ) + "RefJet_etx_EndcapRegion", 0 ),
        RefJet_ety_EndcapRegion( this, ::TString( prefix ) + "RefJet_ety_EndcapRegion", 0 ),
        RefJet_sumet_EndcapRegion( this, ::TString( prefix ) + "RefJet_sumet_EndcapRegion", 0 ),
        RefJet_phi_EndcapRegion( this, ::TString( prefix ) + "RefJet_phi_EndcapRegion", 0 ),
        RefJet_etx_ForwardReg( this, ::TString( prefix ) + "RefJet_etx_ForwardReg", 0 ),
        RefJet_ety_ForwardReg( this, ::TString( prefix ) + "RefJet_ety_ForwardReg", 0 ),
        RefJet_sumet_ForwardReg( this, ::TString( prefix ) + "RefJet_sumet_ForwardReg", 0 ),
        RefJet_phi_ForwardReg( this, ::TString( prefix ) + "RefJet_phi_ForwardReg", 0 ),
        STVF_RefJet_etx( this, ::TString( prefix ) + "STVF_RefJet_etx", 0 ),
        STVF_RefJet_ety( this, ::TString( prefix ) + "STVF_RefJet_ety", 0 ),
        STVF_RefJet_sumet( this, ::TString( prefix ) + "STVF_RefJet_sumet", 0 ),
        STVF_RefJet_etx_CentralReg( this, ::TString( prefix ) + "STVF_RefJet_etx_CentralReg", 0 ),
        STVF_RefJet_ety_CentralReg( this, ::TString( prefix ) + "STVF_RefJet_ety_CentralReg", 0 ),
        STVF_RefJet_sumet_CentralReg( this, ::TString( prefix ) + "STVF_RefJet_sumet_CentralReg", 0 ),
        STVF_RefJet_phi_CentralReg( this, ::TString( prefix ) + "STVF_RefJet_phi_CentralReg", 0 ),
        STVF_RefJet_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_RefJet_etx_EndcapRegion", 0 ),
        STVF_RefJet_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_RefJet_ety_EndcapRegion", 0 ),
        STVF_RefJet_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_RefJet_sumet_EndcapRegion", 0 ),
        STVF_RefJet_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_RefJet_phi_EndcapRegion", 0 ),
        STVF_RefJet_etx_ForwardReg( this, ::TString( prefix ) + "STVF_RefJet_etx_ForwardReg", 0 ),
        STVF_RefJet_ety_ForwardReg( this, ::TString( prefix ) + "STVF_RefJet_ety_ForwardReg", 0 ),
        STVF_RefJet_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_RefJet_sumet_ForwardReg", 0 ),
        STVF_RefJet_phi_ForwardReg( this, ::TString( prefix ) + "STVF_RefJet_phi_ForwardReg", 0 ),
        RefEle_etx( this, ::TString( prefix ) + "RefEle_etx", 0 ),
        RefEle_ety( this, ::TString( prefix ) + "RefEle_ety", 0 ),
        RefEle_sumet( this, ::TString( prefix ) + "RefEle_sumet", 0 ),
        RefEle_etx_CentralReg( this, ::TString( prefix ) + "RefEle_etx_CentralReg", 0 ),
        RefEle_ety_CentralReg( this, ::TString( prefix ) + "RefEle_ety_CentralReg", 0 ),
        RefEle_sumet_CentralReg( this, ::TString( prefix ) + "RefEle_sumet_CentralReg", 0 ),
        RefEle_phi_CentralReg( this, ::TString( prefix ) + "RefEle_phi_CentralReg", 0 ),
        RefEle_etx_EndcapRegion( this, ::TString( prefix ) + "RefEle_etx_EndcapRegion", 0 ),
        RefEle_ety_EndcapRegion( this, ::TString( prefix ) + "RefEle_ety_EndcapRegion", 0 ),
        RefEle_sumet_EndcapRegion( this, ::TString( prefix ) + "RefEle_sumet_EndcapRegion", 0 ),
        RefEle_phi_EndcapRegion( this, ::TString( prefix ) + "RefEle_phi_EndcapRegion", 0 ),
        RefEle_etx_ForwardReg( this, ::TString( prefix ) + "RefEle_etx_ForwardReg", 0 ),
        RefEle_ety_ForwardReg( this, ::TString( prefix ) + "RefEle_ety_ForwardReg", 0 ),
        RefEle_sumet_ForwardReg( this, ::TString( prefix ) + "RefEle_sumet_ForwardReg", 0 ),
        RefEle_phi_ForwardReg( this, ::TString( prefix ) + "RefEle_phi_ForwardReg", 0 ),
        STVF_RefEle_etx( this, ::TString( prefix ) + "STVF_RefEle_etx", 0 ),
        STVF_RefEle_ety( this, ::TString( prefix ) + "STVF_RefEle_ety", 0 ),
        STVF_RefEle_sumet( this, ::TString( prefix ) + "STVF_RefEle_sumet", 0 ),
        STVF_RefEle_etx_CentralReg( this, ::TString( prefix ) + "STVF_RefEle_etx_CentralReg", 0 ),
        STVF_RefEle_ety_CentralReg( this, ::TString( prefix ) + "STVF_RefEle_ety_CentralReg", 0 ),
        STVF_RefEle_sumet_CentralReg( this, ::TString( prefix ) + "STVF_RefEle_sumet_CentralReg", 0 ),
        STVF_RefEle_phi_CentralReg( this, ::TString( prefix ) + "STVF_RefEle_phi_CentralReg", 0 ),
        STVF_RefEle_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_RefEle_etx_EndcapRegion", 0 ),
        STVF_RefEle_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_RefEle_ety_EndcapRegion", 0 ),
        STVF_RefEle_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_RefEle_sumet_EndcapRegion", 0 ),
        STVF_RefEle_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_RefEle_phi_EndcapRegion", 0 ),
        STVF_RefEle_etx_ForwardReg( this, ::TString( prefix ) + "STVF_RefEle_etx_ForwardReg", 0 ),
        STVF_RefEle_ety_ForwardReg( this, ::TString( prefix ) + "STVF_RefEle_ety_ForwardReg", 0 ),
        STVF_RefEle_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_RefEle_sumet_ForwardReg", 0 ),
        STVF_RefEle_phi_ForwardReg( this, ::TString( prefix ) + "STVF_RefEle_phi_ForwardReg", 0 ),
        Muon_Total_Staco_etx( this, ::TString( prefix ) + "Muon_Total_Staco_etx", 0 ),
        Muon_Total_Staco_ety( this, ::TString( prefix ) + "Muon_Total_Staco_ety", 0 ),
        Muon_Total_Staco_sumet( this, ::TString( prefix ) + "Muon_Total_Staco_sumet", 0 ),
        Muon_Total_Staco_etx_CentralReg( this, ::TString( prefix ) + "Muon_Total_Staco_etx_CentralReg", 0 ),
        Muon_Total_Staco_ety_CentralReg( this, ::TString( prefix ) + "Muon_Total_Staco_ety_CentralReg", 0 ),
        Muon_Total_Staco_sumet_CentralReg( this, ::TString( prefix ) + "Muon_Total_Staco_sumet_CentralReg", 0 ),
        Muon_Total_Staco_phi_CentralReg( this, ::TString( prefix ) + "Muon_Total_Staco_phi_CentralReg", 0 ),
        Muon_Total_Staco_etx_EndcapRegion( this, ::TString( prefix ) + "Muon_Total_Staco_etx_EndcapRegion", 0 ),
        Muon_Total_Staco_ety_EndcapRegion( this, ::TString( prefix ) + "Muon_Total_Staco_ety_EndcapRegion", 0 ),
        Muon_Total_Staco_sumet_EndcapRegion( this, ::TString( prefix ) + "Muon_Total_Staco_sumet_EndcapRegion", 0 ),
        Muon_Total_Staco_phi_EndcapRegion( this, ::TString( prefix ) + "Muon_Total_Staco_phi_EndcapRegion", 0 ),
        Muon_Total_Staco_etx_ForwardReg( this, ::TString( prefix ) + "Muon_Total_Staco_etx_ForwardReg", 0 ),
        Muon_Total_Staco_ety_ForwardReg( this, ::TString( prefix ) + "Muon_Total_Staco_ety_ForwardReg", 0 ),
        Muon_Total_Staco_sumet_ForwardReg( this, ::TString( prefix ) + "Muon_Total_Staco_sumet_ForwardReg", 0 ),
        Muon_Total_Staco_phi_ForwardReg( this, ::TString( prefix ) + "Muon_Total_Staco_phi_ForwardReg", 0 ),
        STVF_Muon_Total_Staco_etx( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_etx", 0 ),
        STVF_Muon_Total_Staco_ety( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_ety", 0 ),
        STVF_Muon_Total_Staco_sumet( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_sumet", 0 ),
        STVF_Muon_Total_Staco_etx_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_etx_CentralReg", 0 ),
        STVF_Muon_Total_Staco_ety_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_ety_CentralReg", 0 ),
        STVF_Muon_Total_Staco_sumet_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_sumet_CentralReg", 0 ),
        STVF_Muon_Total_Staco_phi_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_phi_CentralReg", 0 ),
        STVF_Muon_Total_Staco_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_etx_EndcapRegion", 0 ),
        STVF_Muon_Total_Staco_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_ety_EndcapRegion", 0 ),
        STVF_Muon_Total_Staco_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_sumet_EndcapRegion", 0 ),
        STVF_Muon_Total_Staco_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_phi_EndcapRegion", 0 ),
        STVF_Muon_Total_Staco_etx_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_etx_ForwardReg", 0 ),
        STVF_Muon_Total_Staco_ety_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_ety_ForwardReg", 0 ),
        STVF_Muon_Total_Staco_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_sumet_ForwardReg", 0 ),
        STVF_Muon_Total_Staco_phi_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Total_Staco_phi_ForwardReg", 0 ),
        Muon_Isol_Staco_etx( this, ::TString( prefix ) + "Muon_Isol_Staco_etx", 0 ),
        Muon_Isol_Staco_ety( this, ::TString( prefix ) + "Muon_Isol_Staco_ety", 0 ),
        Muon_Isol_Staco_sumet( this, ::TString( prefix ) + "Muon_Isol_Staco_sumet", 0 ),
        Muon_Isol_Staco_etx_CentralReg( this, ::TString( prefix ) + "Muon_Isol_Staco_etx_CentralReg", 0 ),
        Muon_Isol_Staco_ety_CentralReg( this, ::TString( prefix ) + "Muon_Isol_Staco_ety_CentralReg", 0 ),
        Muon_Isol_Staco_sumet_CentralReg( this, ::TString( prefix ) + "Muon_Isol_Staco_sumet_CentralReg", 0 ),
        Muon_Isol_Staco_phi_CentralReg( this, ::TString( prefix ) + "Muon_Isol_Staco_phi_CentralReg", 0 ),
        Muon_Isol_Staco_etx_EndcapRegion( this, ::TString( prefix ) + "Muon_Isol_Staco_etx_EndcapRegion", 0 ),
        Muon_Isol_Staco_ety_EndcapRegion( this, ::TString( prefix ) + "Muon_Isol_Staco_ety_EndcapRegion", 0 ),
        Muon_Isol_Staco_sumet_EndcapRegion( this, ::TString( prefix ) + "Muon_Isol_Staco_sumet_EndcapRegion", 0 ),
        Muon_Isol_Staco_phi_EndcapRegion( this, ::TString( prefix ) + "Muon_Isol_Staco_phi_EndcapRegion", 0 ),
        Muon_Isol_Staco_etx_ForwardReg( this, ::TString( prefix ) + "Muon_Isol_Staco_etx_ForwardReg", 0 ),
        Muon_Isol_Staco_ety_ForwardReg( this, ::TString( prefix ) + "Muon_Isol_Staco_ety_ForwardReg", 0 ),
        Muon_Isol_Staco_sumet_ForwardReg( this, ::TString( prefix ) + "Muon_Isol_Staco_sumet_ForwardReg", 0 ),
        Muon_Isol_Staco_phi_ForwardReg( this, ::TString( prefix ) + "Muon_Isol_Staco_phi_ForwardReg", 0 ),
        STVF_Muon_Isol_Staco_etx( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_etx", 0 ),
        STVF_Muon_Isol_Staco_ety( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_ety", 0 ),
        STVF_Muon_Isol_Staco_sumet( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_sumet", 0 ),
        STVF_Muon_Isol_Staco_etx_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_etx_CentralReg", 0 ),
        STVF_Muon_Isol_Staco_ety_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_ety_CentralReg", 0 ),
        STVF_Muon_Isol_Staco_sumet_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_sumet_CentralReg", 0 ),
        STVF_Muon_Isol_Staco_phi_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_phi_CentralReg", 0 ),
        STVF_Muon_Isol_Staco_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_etx_EndcapRegion", 0 ),
        STVF_Muon_Isol_Staco_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_ety_EndcapRegion", 0 ),
        STVF_Muon_Isol_Staco_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_sumet_EndcapRegion", 0 ),
        STVF_Muon_Isol_Staco_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_phi_EndcapRegion", 0 ),
        STVF_Muon_Isol_Staco_etx_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_etx_ForwardReg", 0 ),
        STVF_Muon_Isol_Staco_ety_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_ety_ForwardReg", 0 ),
        STVF_Muon_Isol_Staco_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_sumet_ForwardReg", 0 ),
        STVF_Muon_Isol_Staco_phi_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Staco_phi_ForwardReg", 0 ),
        Muon_NonIsol_Staco_etx( this, ::TString( prefix ) + "Muon_NonIsol_Staco_etx", 0 ),
        Muon_NonIsol_Staco_ety( this, ::TString( prefix ) + "Muon_NonIsol_Staco_ety", 0 ),
        Muon_NonIsol_Staco_sumet( this, ::TString( prefix ) + "Muon_NonIsol_Staco_sumet", 0 ),
        Muon_NonIsol_Staco_etx_CentralReg( this, ::TString( prefix ) + "Muon_NonIsol_Staco_etx_CentralReg", 0 ),
        Muon_NonIsol_Staco_ety_CentralReg( this, ::TString( prefix ) + "Muon_NonIsol_Staco_ety_CentralReg", 0 ),
        Muon_NonIsol_Staco_sumet_CentralReg( this, ::TString( prefix ) + "Muon_NonIsol_Staco_sumet_CentralReg", 0 ),
        Muon_NonIsol_Staco_phi_CentralReg( this, ::TString( prefix ) + "Muon_NonIsol_Staco_phi_CentralReg", 0 ),
        Muon_NonIsol_Staco_etx_EndcapRegion( this, ::TString( prefix ) + "Muon_NonIsol_Staco_etx_EndcapRegion", 0 ),
        Muon_NonIsol_Staco_ety_EndcapRegion( this, ::TString( prefix ) + "Muon_NonIsol_Staco_ety_EndcapRegion", 0 ),
        Muon_NonIsol_Staco_sumet_EndcapRegion( this, ::TString( prefix ) + "Muon_NonIsol_Staco_sumet_EndcapRegion", 0 ),
        Muon_NonIsol_Staco_phi_EndcapRegion( this, ::TString( prefix ) + "Muon_NonIsol_Staco_phi_EndcapRegion", 0 ),
        Muon_NonIsol_Staco_etx_ForwardReg( this, ::TString( prefix ) + "Muon_NonIsol_Staco_etx_ForwardReg", 0 ),
        Muon_NonIsol_Staco_ety_ForwardReg( this, ::TString( prefix ) + "Muon_NonIsol_Staco_ety_ForwardReg", 0 ),
        Muon_NonIsol_Staco_sumet_ForwardReg( this, ::TString( prefix ) + "Muon_NonIsol_Staco_sumet_ForwardReg", 0 ),
        Muon_NonIsol_Staco_phi_ForwardReg( this, ::TString( prefix ) + "Muon_NonIsol_Staco_phi_ForwardReg", 0 ),
        STVF_Muon_NonIsol_Staco_etx( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_etx", 0 ),
        STVF_Muon_NonIsol_Staco_ety( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_ety", 0 ),
        STVF_Muon_NonIsol_Staco_sumet( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_sumet", 0 ),
        STVF_Muon_NonIsol_Staco_etx_CentralReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_etx_CentralReg", 0 ),
        STVF_Muon_NonIsol_Staco_ety_CentralReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_ety_CentralReg", 0 ),
        STVF_Muon_NonIsol_Staco_sumet_CentralReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_sumet_CentralReg", 0 ),
        STVF_Muon_NonIsol_Staco_phi_CentralReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_phi_CentralReg", 0 ),
        STVF_Muon_NonIsol_Staco_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_etx_EndcapRegion", 0 ),
        STVF_Muon_NonIsol_Staco_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_ety_EndcapRegion", 0 ),
        STVF_Muon_NonIsol_Staco_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_sumet_EndcapRegion", 0 ),
        STVF_Muon_NonIsol_Staco_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_phi_EndcapRegion", 0 ),
        STVF_Muon_NonIsol_Staco_etx_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_etx_ForwardReg", 0 ),
        STVF_Muon_NonIsol_Staco_ety_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_ety_ForwardReg", 0 ),
        STVF_Muon_NonIsol_Staco_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_sumet_ForwardReg", 0 ),
        STVF_Muon_NonIsol_Staco_phi_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_phi_ForwardReg", 0 ),
        CellOut_etx( this, ::TString( prefix ) + "CellOut_etx", 0 ),
        CellOut_ety( this, ::TString( prefix ) + "CellOut_ety", 0 ),
        CellOut_sumet( this, ::TString( prefix ) + "CellOut_sumet", 0 ),
        CellOut_etx_CentralReg( this, ::TString( prefix ) + "CellOut_etx_CentralReg", 0 ),
        CellOut_ety_CentralReg( this, ::TString( prefix ) + "CellOut_ety_CentralReg", 0 ),
        CellOut_sumet_CentralReg( this, ::TString( prefix ) + "CellOut_sumet_CentralReg", 0 ),
        CellOut_phi_CentralReg( this, ::TString( prefix ) + "CellOut_phi_CentralReg", 0 ),
        CellOut_etx_EndcapRegion( this, ::TString( prefix ) + "CellOut_etx_EndcapRegion", 0 ),
        CellOut_ety_EndcapRegion( this, ::TString( prefix ) + "CellOut_ety_EndcapRegion", 0 ),
        CellOut_sumet_EndcapRegion( this, ::TString( prefix ) + "CellOut_sumet_EndcapRegion", 0 ),
        CellOut_phi_EndcapRegion( this, ::TString( prefix ) + "CellOut_phi_EndcapRegion", 0 ),
        CellOut_etx_ForwardReg( this, ::TString( prefix ) + "CellOut_etx_ForwardReg", 0 ),
        CellOut_ety_ForwardReg( this, ::TString( prefix ) + "CellOut_ety_ForwardReg", 0 ),
        CellOut_sumet_ForwardReg( this, ::TString( prefix ) + "CellOut_sumet_ForwardReg", 0 ),
        CellOut_phi_ForwardReg( this, ::TString( prefix ) + "CellOut_phi_ForwardReg", 0 ),
        STVF_CellOut_etx( this, ::TString( prefix ) + "STVF_CellOut_etx", 0 ),
        STVF_CellOut_ety( this, ::TString( prefix ) + "STVF_CellOut_ety", 0 ),
        STVF_CellOut_sumet( this, ::TString( prefix ) + "STVF_CellOut_sumet", 0 ),
        STVF_CellOut_etx_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_etx_CentralReg", 0 ),
        STVF_CellOut_ety_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_ety_CentralReg", 0 ),
        STVF_CellOut_sumet_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_sumet_CentralReg", 0 ),
        STVF_CellOut_phi_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_phi_CentralReg", 0 ),
        STVF_CellOut_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_etx_EndcapRegion", 0 ),
        STVF_CellOut_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_ety_EndcapRegion", 0 ),
        STVF_CellOut_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_sumet_EndcapRegion", 0 ),
        STVF_CellOut_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_phi_EndcapRegion", 0 ),
        STVF_CellOut_etx_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_etx_ForwardReg", 0 ),
        STVF_CellOut_ety_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_ety_ForwardReg", 0 ),
        STVF_CellOut_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_sumet_ForwardReg", 0 ),
        STVF_CellOut_phi_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_phi_ForwardReg", 0 ),
        Muon_Isol_Muid_etx( this, ::TString( prefix ) + "Muon_Isol_Muid_etx", 0 ),
        Muon_Isol_Muid_ety( this, ::TString( prefix ) + "Muon_Isol_Muid_ety", 0 ),
        Muon_Isol_Muid_sumet( this, ::TString( prefix ) + "Muon_Isol_Muid_sumet", 0 ),
        Muon_Isol_Muid_etx_CentralReg( this, ::TString( prefix ) + "Muon_Isol_Muid_etx_CentralReg", 0 ),
        Muon_Isol_Muid_ety_CentralReg( this, ::TString( prefix ) + "Muon_Isol_Muid_ety_CentralReg", 0 ),
        Muon_Isol_Muid_sumet_CentralReg( this, ::TString( prefix ) + "Muon_Isol_Muid_sumet_CentralReg", 0 ),
        Muon_Isol_Muid_phi_CentralReg( this, ::TString( prefix ) + "Muon_Isol_Muid_phi_CentralReg", 0 ),
        Muon_Isol_Muid_etx_EndcapRegion( this, ::TString( prefix ) + "Muon_Isol_Muid_etx_EndcapRegion", 0 ),
        Muon_Isol_Muid_ety_EndcapRegion( this, ::TString( prefix ) + "Muon_Isol_Muid_ety_EndcapRegion", 0 ),
        Muon_Isol_Muid_sumet_EndcapRegion( this, ::TString( prefix ) + "Muon_Isol_Muid_sumet_EndcapRegion", 0 ),
        Muon_Isol_Muid_phi_EndcapRegion( this, ::TString( prefix ) + "Muon_Isol_Muid_phi_EndcapRegion", 0 ),
        Muon_Isol_Muid_etx_ForwardReg( this, ::TString( prefix ) + "Muon_Isol_Muid_etx_ForwardReg", 0 ),
        Muon_Isol_Muid_ety_ForwardReg( this, ::TString( prefix ) + "Muon_Isol_Muid_ety_ForwardReg", 0 ),
        Muon_Isol_Muid_sumet_ForwardReg( this, ::TString( prefix ) + "Muon_Isol_Muid_sumet_ForwardReg", 0 ),
        Muon_Isol_Muid_phi_ForwardReg( this, ::TString( prefix ) + "Muon_Isol_Muid_phi_ForwardReg", 0 ),
        STVF_Muon_Isol_Muid_etx( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_etx", 0 ),
        STVF_Muon_Isol_Muid_ety( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_ety", 0 ),
        STVF_Muon_Isol_Muid_sumet( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_sumet", 0 ),
        STVF_Muon_Isol_Muid_etx_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_etx_CentralReg", 0 ),
        STVF_Muon_Isol_Muid_ety_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_ety_CentralReg", 0 ),
        STVF_Muon_Isol_Muid_sumet_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_sumet_CentralReg", 0 ),
        STVF_Muon_Isol_Muid_phi_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_phi_CentralReg", 0 ),
        STVF_Muon_Isol_Muid_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_etx_EndcapRegion", 0 ),
        STVF_Muon_Isol_Muid_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_ety_EndcapRegion", 0 ),
        STVF_Muon_Isol_Muid_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_sumet_EndcapRegion", 0 ),
        STVF_Muon_Isol_Muid_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_phi_EndcapRegion", 0 ),
        STVF_Muon_Isol_Muid_etx_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_etx_ForwardReg", 0 ),
        STVF_Muon_Isol_Muid_ety_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_ety_ForwardReg", 0 ),
        STVF_Muon_Isol_Muid_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_sumet_ForwardReg", 0 ),
        STVF_Muon_Isol_Muid_phi_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Isol_Muid_phi_ForwardReg", 0 ),
        Muon_NonIsol_Muid_etx( this, ::TString( prefix ) + "Muon_NonIsol_Muid_etx", 0 ),
        Muon_NonIsol_Muid_ety( this, ::TString( prefix ) + "Muon_NonIsol_Muid_ety", 0 ),
        Muon_NonIsol_Muid_sumet( this, ::TString( prefix ) + "Muon_NonIsol_Muid_sumet", 0 ),
        Muon_NonIsol_Muid_etx_CentralReg( this, ::TString( prefix ) + "Muon_NonIsol_Muid_etx_CentralReg", 0 ),
        Muon_NonIsol_Muid_ety_CentralReg( this, ::TString( prefix ) + "Muon_NonIsol_Muid_ety_CentralReg", 0 ),
        Muon_NonIsol_Muid_sumet_CentralReg( this, ::TString( prefix ) + "Muon_NonIsol_Muid_sumet_CentralReg", 0 ),
        Muon_NonIsol_Muid_phi_CentralReg( this, ::TString( prefix ) + "Muon_NonIsol_Muid_phi_CentralReg", 0 ),
        Muon_NonIsol_Muid_etx_EndcapRegion( this, ::TString( prefix ) + "Muon_NonIsol_Muid_etx_EndcapRegion", 0 ),
        Muon_NonIsol_Muid_ety_EndcapRegion( this, ::TString( prefix ) + "Muon_NonIsol_Muid_ety_EndcapRegion", 0 ),
        Muon_NonIsol_Muid_sumet_EndcapRegion( this, ::TString( prefix ) + "Muon_NonIsol_Muid_sumet_EndcapRegion", 0 ),
        Muon_NonIsol_Muid_phi_EndcapRegion( this, ::TString( prefix ) + "Muon_NonIsol_Muid_phi_EndcapRegion", 0 ),
        Muon_NonIsol_Muid_etx_ForwardReg( this, ::TString( prefix ) + "Muon_NonIsol_Muid_etx_ForwardReg", 0 ),
        Muon_NonIsol_Muid_ety_ForwardReg( this, ::TString( prefix ) + "Muon_NonIsol_Muid_ety_ForwardReg", 0 ),
        Muon_NonIsol_Muid_sumet_ForwardReg( this, ::TString( prefix ) + "Muon_NonIsol_Muid_sumet_ForwardReg", 0 ),
        Muon_NonIsol_Muid_phi_ForwardReg( this, ::TString( prefix ) + "Muon_NonIsol_Muid_phi_ForwardReg", 0 ),
        STVF_Muon_NonIsol_Muid_etx( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_etx", 0 ),
        STVF_Muon_NonIsol_Muid_ety( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_ety", 0 ),
        STVF_Muon_NonIsol_Muid_sumet( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_sumet", 0 ),
        STVF_Muon_NonIsol_Muid_etx_CentralReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_etx_CentralReg", 0 ),
        STVF_Muon_NonIsol_Muid_ety_CentralReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_ety_CentralReg", 0 ),
        STVF_Muon_NonIsol_Muid_sumet_CentralReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_sumet_CentralReg", 0 ),
        STVF_Muon_NonIsol_Muid_phi_CentralReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_phi_CentralReg", 0 ),
        STVF_Muon_NonIsol_Muid_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_etx_EndcapRegion", 0 ),
        STVF_Muon_NonIsol_Muid_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_ety_EndcapRegion", 0 ),
        STVF_Muon_NonIsol_Muid_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_sumet_EndcapRegion", 0 ),
        STVF_Muon_NonIsol_Muid_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_phi_EndcapRegion", 0 ),
        STVF_Muon_NonIsol_Muid_etx_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_etx_ForwardReg", 0 ),
        STVF_Muon_NonIsol_Muid_ety_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_ety_ForwardReg", 0 ),
        STVF_Muon_NonIsol_Muid_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_sumet_ForwardReg", 0 ),
        STVF_Muon_NonIsol_Muid_phi_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_phi_ForwardReg", 0 ),
        Muon_Total_Muid_etx( this, ::TString( prefix ) + "Muon_Total_Muid_etx", 0 ),
        Muon_Total_Muid_ety( this, ::TString( prefix ) + "Muon_Total_Muid_ety", 0 ),
        Muon_Total_Muid_sumet( this, ::TString( prefix ) + "Muon_Total_Muid_sumet", 0 ),
        Muon_Total_Muid_etx_CentralReg( this, ::TString( prefix ) + "Muon_Total_Muid_etx_CentralReg", 0 ),
        Muon_Total_Muid_ety_CentralReg( this, ::TString( prefix ) + "Muon_Total_Muid_ety_CentralReg", 0 ),
        Muon_Total_Muid_sumet_CentralReg( this, ::TString( prefix ) + "Muon_Total_Muid_sumet_CentralReg", 0 ),
        Muon_Total_Muid_phi_CentralReg( this, ::TString( prefix ) + "Muon_Total_Muid_phi_CentralReg", 0 ),
        Muon_Total_Muid_etx_EndcapRegion( this, ::TString( prefix ) + "Muon_Total_Muid_etx_EndcapRegion", 0 ),
        Muon_Total_Muid_ety_EndcapRegion( this, ::TString( prefix ) + "Muon_Total_Muid_ety_EndcapRegion", 0 ),
        Muon_Total_Muid_sumet_EndcapRegion( this, ::TString( prefix ) + "Muon_Total_Muid_sumet_EndcapRegion", 0 ),
        Muon_Total_Muid_phi_EndcapRegion( this, ::TString( prefix ) + "Muon_Total_Muid_phi_EndcapRegion", 0 ),
        Muon_Total_Muid_etx_ForwardReg( this, ::TString( prefix ) + "Muon_Total_Muid_etx_ForwardReg", 0 ),
        Muon_Total_Muid_ety_ForwardReg( this, ::TString( prefix ) + "Muon_Total_Muid_ety_ForwardReg", 0 ),
        Muon_Total_Muid_sumet_ForwardReg( this, ::TString( prefix ) + "Muon_Total_Muid_sumet_ForwardReg", 0 ),
        Muon_Total_Muid_phi_ForwardReg( this, ::TString( prefix ) + "Muon_Total_Muid_phi_ForwardReg", 0 ),
        STVF_Muon_Total_Muid_etx( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_etx", 0 ),
        STVF_Muon_Total_Muid_ety( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_ety", 0 ),
        STVF_Muon_Total_Muid_sumet( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_sumet", 0 ),
        STVF_Muon_Total_Muid_etx_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_etx_CentralReg", 0 ),
        STVF_Muon_Total_Muid_ety_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_ety_CentralReg", 0 ),
        STVF_Muon_Total_Muid_sumet_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_sumet_CentralReg", 0 ),
        STVF_Muon_Total_Muid_phi_CentralReg( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_phi_CentralReg", 0 ),
        STVF_Muon_Total_Muid_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_etx_EndcapRegion", 0 ),
        STVF_Muon_Total_Muid_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_ety_EndcapRegion", 0 ),
        STVF_Muon_Total_Muid_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_sumet_EndcapRegion", 0 ),
        STVF_Muon_Total_Muid_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_phi_EndcapRegion", 0 ),
        STVF_Muon_Total_Muid_etx_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_etx_ForwardReg", 0 ),
        STVF_Muon_Total_Muid_ety_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_ety_ForwardReg", 0 ),
        STVF_Muon_Total_Muid_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_sumet_ForwardReg", 0 ),
        STVF_Muon_Total_Muid_phi_ForwardReg( this, ::TString( prefix ) + "STVF_Muon_Total_Muid_phi_ForwardReg", 0 ),
        Track_etx( this, ::TString( prefix ) + "Track_etx", 0 ),
        Track_ety( this, ::TString( prefix ) + "Track_ety", 0 ),
        Track_sumet( this, ::TString( prefix ) + "Track_sumet", 0 ),
        Track_etx_CentralReg( this, ::TString( prefix ) + "Track_etx_CentralReg", 0 ),
        Track_ety_CentralReg( this, ::TString( prefix ) + "Track_ety_CentralReg", 0 ),
        Track_sumet_CentralReg( this, ::TString( prefix ) + "Track_sumet_CentralReg", 0 ),
        Track_phi_CentralReg( this, ::TString( prefix ) + "Track_phi_CentralReg", 0 ),
        Track_etx_EndcapRegion( this, ::TString( prefix ) + "Track_etx_EndcapRegion", 0 ),
        Track_ety_EndcapRegion( this, ::TString( prefix ) + "Track_ety_EndcapRegion", 0 ),
        Track_sumet_EndcapRegion( this, ::TString( prefix ) + "Track_sumet_EndcapRegion", 0 ),
        Track_phi_EndcapRegion( this, ::TString( prefix ) + "Track_phi_EndcapRegion", 0 ),
        Track_etx_ForwardReg( this, ::TString( prefix ) + "Track_etx_ForwardReg", 0 ),
        Track_ety_ForwardReg( this, ::TString( prefix ) + "Track_ety_ForwardReg", 0 ),
        Track_sumet_ForwardReg( this, ::TString( prefix ) + "Track_sumet_ForwardReg", 0 ),
        Track_phi_ForwardReg( this, ::TString( prefix ) + "Track_phi_ForwardReg", 0 ),
        STVF_Track_etx( this, ::TString( prefix ) + "STVF_Track_etx", 0 ),
        STVF_Track_ety( this, ::TString( prefix ) + "STVF_Track_ety", 0 ),
        STVF_Track_sumet( this, ::TString( prefix ) + "STVF_Track_sumet", 0 ),
        STVF_Track_etx_CentralReg( this, ::TString( prefix ) + "STVF_Track_etx_CentralReg", 0 ),
        STVF_Track_ety_CentralReg( this, ::TString( prefix ) + "STVF_Track_ety_CentralReg", 0 ),
        STVF_Track_sumet_CentralReg( this, ::TString( prefix ) + "STVF_Track_sumet_CentralReg", 0 ),
        STVF_Track_phi_CentralReg( this, ::TString( prefix ) + "STVF_Track_phi_CentralReg", 0 ),
        STVF_Track_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_Track_etx_EndcapRegion", 0 ),
        STVF_Track_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_Track_ety_EndcapRegion", 0 ),
        STVF_Track_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_Track_sumet_EndcapRegion", 0 ),
        STVF_Track_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_Track_phi_EndcapRegion", 0 ),
        STVF_Track_etx_ForwardReg( this, ::TString( prefix ) + "STVF_Track_etx_ForwardReg", 0 ),
        STVF_Track_ety_ForwardReg( this, ::TString( prefix ) + "STVF_Track_ety_ForwardReg", 0 ),
        STVF_Track_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_Track_sumet_ForwardReg", 0 ),
        STVF_Track_phi_ForwardReg( this, ::TString( prefix ) + "STVF_Track_phi_ForwardReg", 0 ),
        SoftJets_etx( this, ::TString( prefix ) + "SoftJets_etx", 0 ),
        SoftJets_ety( this, ::TString( prefix ) + "SoftJets_ety", 0 ),
        SoftJets_sumet( this, ::TString( prefix ) + "SoftJets_sumet", 0 ),
        SoftJets_etx_CentralReg( this, ::TString( prefix ) + "SoftJets_etx_CentralReg", 0 ),
        SoftJets_ety_CentralReg( this, ::TString( prefix ) + "SoftJets_ety_CentralReg", 0 ),
        SoftJets_sumet_CentralReg( this, ::TString( prefix ) + "SoftJets_sumet_CentralReg", 0 ),
        SoftJets_phi_CentralReg( this, ::TString( prefix ) + "SoftJets_phi_CentralReg", 0 ),
        SoftJets_etx_EndcapRegion( this, ::TString( prefix ) + "SoftJets_etx_EndcapRegion", 0 ),
        SoftJets_ety_EndcapRegion( this, ::TString( prefix ) + "SoftJets_ety_EndcapRegion", 0 ),
        SoftJets_sumet_EndcapRegion( this, ::TString( prefix ) + "SoftJets_sumet_EndcapRegion", 0 ),
        SoftJets_phi_EndcapRegion( this, ::TString( prefix ) + "SoftJets_phi_EndcapRegion", 0 ),
        SoftJets_etx_ForwardReg( this, ::TString( prefix ) + "SoftJets_etx_ForwardReg", 0 ),
        SoftJets_ety_ForwardReg( this, ::TString( prefix ) + "SoftJets_ety_ForwardReg", 0 ),
        SoftJets_sumet_ForwardReg( this, ::TString( prefix ) + "SoftJets_sumet_ForwardReg", 0 ),
        SoftJets_phi_ForwardReg( this, ::TString( prefix ) + "SoftJets_phi_ForwardReg", 0 ),
        STVF_SoftJets_etx( this, ::TString( prefix ) + "STVF_SoftJets_etx", 0 ),
        STVF_SoftJets_ety( this, ::TString( prefix ) + "STVF_SoftJets_ety", 0 ),
        STVF_SoftJets_sumet( this, ::TString( prefix ) + "STVF_SoftJets_sumet", 0 ),
        STVF_SoftJets_etx_CentralReg( this, ::TString( prefix ) + "STVF_SoftJets_etx_CentralReg", 0 ),
        STVF_SoftJets_ety_CentralReg( this, ::TString( prefix ) + "STVF_SoftJets_ety_CentralReg", 0 ),
        STVF_SoftJets_sumet_CentralReg( this, ::TString( prefix ) + "STVF_SoftJets_sumet_CentralReg", 0 ),
        STVF_SoftJets_phi_CentralReg( this, ::TString( prefix ) + "STVF_SoftJets_phi_CentralReg", 0 ),
        STVF_SoftJets_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_SoftJets_etx_EndcapRegion", 0 ),
        STVF_SoftJets_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_SoftJets_ety_EndcapRegion", 0 ),
        STVF_SoftJets_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_SoftJets_sumet_EndcapRegion", 0 ),
        STVF_SoftJets_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_SoftJets_phi_EndcapRegion", 0 ),
        STVF_SoftJets_etx_ForwardReg( this, ::TString( prefix ) + "STVF_SoftJets_etx_ForwardReg", 0 ),
        STVF_SoftJets_ety_ForwardReg( this, ::TString( prefix ) + "STVF_SoftJets_ety_ForwardReg", 0 ),
        STVF_SoftJets_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_SoftJets_sumet_ForwardReg", 0 ),
        STVF_SoftJets_phi_ForwardReg( this, ::TString( prefix ) + "STVF_SoftJets_phi_ForwardReg", 0 ),
        RefMuon_etx( this, ::TString( prefix ) + "RefMuon_etx", 0 ),
        RefMuon_ety( this, ::TString( prefix ) + "RefMuon_ety", 0 ),
        RefMuon_sumet( this, ::TString( prefix ) + "RefMuon_sumet", 0 ),
        RefMuon_etx_CentralReg( this, ::TString( prefix ) + "RefMuon_etx_CentralReg", 0 ),
        RefMuon_ety_CentralReg( this, ::TString( prefix ) + "RefMuon_ety_CentralReg", 0 ),
        RefMuon_sumet_CentralReg( this, ::TString( prefix ) + "RefMuon_sumet_CentralReg", 0 ),
        RefMuon_phi_CentralReg( this, ::TString( prefix ) + "RefMuon_phi_CentralReg", 0 ),
        RefMuon_etx_EndcapRegion( this, ::TString( prefix ) + "RefMuon_etx_EndcapRegion", 0 ),
        RefMuon_ety_EndcapRegion( this, ::TString( prefix ) + "RefMuon_ety_EndcapRegion", 0 ),
        RefMuon_sumet_EndcapRegion( this, ::TString( prefix ) + "RefMuon_sumet_EndcapRegion", 0 ),
        RefMuon_phi_EndcapRegion( this, ::TString( prefix ) + "RefMuon_phi_EndcapRegion", 0 ),
        RefMuon_etx_ForwardReg( this, ::TString( prefix ) + "RefMuon_etx_ForwardReg", 0 ),
        RefMuon_ety_ForwardReg( this, ::TString( prefix ) + "RefMuon_ety_ForwardReg", 0 ),
        RefMuon_sumet_ForwardReg( this, ::TString( prefix ) + "RefMuon_sumet_ForwardReg", 0 ),
        RefMuon_phi_ForwardReg( this, ::TString( prefix ) + "RefMuon_phi_ForwardReg", 0 ),
        STVF_RefMuon_etx( this, ::TString( prefix ) + "STVF_RefMuon_etx", 0 ),
        STVF_RefMuon_ety( this, ::TString( prefix ) + "STVF_RefMuon_ety", 0 ),
        STVF_RefMuon_sumet( this, ::TString( prefix ) + "STVF_RefMuon_sumet", 0 ),
        STVF_RefMuon_etx_CentralReg( this, ::TString( prefix ) + "STVF_RefMuon_etx_CentralReg", 0 ),
        STVF_RefMuon_ety_CentralReg( this, ::TString( prefix ) + "STVF_RefMuon_ety_CentralReg", 0 ),
        STVF_RefMuon_sumet_CentralReg( this, ::TString( prefix ) + "STVF_RefMuon_sumet_CentralReg", 0 ),
        STVF_RefMuon_phi_CentralReg( this, ::TString( prefix ) + "STVF_RefMuon_phi_CentralReg", 0 ),
        STVF_RefMuon_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_RefMuon_etx_EndcapRegion", 0 ),
        STVF_RefMuon_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_RefMuon_ety_EndcapRegion", 0 ),
        STVF_RefMuon_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_RefMuon_sumet_EndcapRegion", 0 ),
        STVF_RefMuon_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_RefMuon_phi_EndcapRegion", 0 ),
        STVF_RefMuon_etx_ForwardReg( this, ::TString( prefix ) + "STVF_RefMuon_etx_ForwardReg", 0 ),
        STVF_RefMuon_ety_ForwardReg( this, ::TString( prefix ) + "STVF_RefMuon_ety_ForwardReg", 0 ),
        STVF_RefMuon_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_RefMuon_sumet_ForwardReg", 0 ),
        STVF_RefMuon_phi_ForwardReg( this, ::TString( prefix ) + "STVF_RefMuon_phi_ForwardReg", 0 ),
        MuonBoy_etx( this, ::TString( prefix ) + "MuonBoy_etx", 0 ),
        MuonBoy_ety( this, ::TString( prefix ) + "MuonBoy_ety", 0 ),
        MuonBoy_sumet( this, ::TString( prefix ) + "MuonBoy_sumet", 0 ),
        MuonBoy_etx_CentralReg( this, ::TString( prefix ) + "MuonBoy_etx_CentralReg", 0 ),
        MuonBoy_ety_CentralReg( this, ::TString( prefix ) + "MuonBoy_ety_CentralReg", 0 ),
        MuonBoy_sumet_CentralReg( this, ::TString( prefix ) + "MuonBoy_sumet_CentralReg", 0 ),
        MuonBoy_phi_CentralReg( this, ::TString( prefix ) + "MuonBoy_phi_CentralReg", 0 ),
        MuonBoy_etx_EndcapRegion( this, ::TString( prefix ) + "MuonBoy_etx_EndcapRegion", 0 ),
        MuonBoy_ety_EndcapRegion( this, ::TString( prefix ) + "MuonBoy_ety_EndcapRegion", 0 ),
        MuonBoy_sumet_EndcapRegion( this, ::TString( prefix ) + "MuonBoy_sumet_EndcapRegion", 0 ),
        MuonBoy_phi_EndcapRegion( this, ::TString( prefix ) + "MuonBoy_phi_EndcapRegion", 0 ),
        MuonBoy_etx_ForwardReg( this, ::TString( prefix ) + "MuonBoy_etx_ForwardReg", 0 ),
        MuonBoy_ety_ForwardReg( this, ::TString( prefix ) + "MuonBoy_ety_ForwardReg", 0 ),
        MuonBoy_sumet_ForwardReg( this, ::TString( prefix ) + "MuonBoy_sumet_ForwardReg", 0 ),
        MuonBoy_phi_ForwardReg( this, ::TString( prefix ) + "MuonBoy_phi_ForwardReg", 0 ),
        STVF_MuonBoy_etx( this, ::TString( prefix ) + "STVF_MuonBoy_etx", 0 ),
        STVF_MuonBoy_ety( this, ::TString( prefix ) + "STVF_MuonBoy_ety", 0 ),
        STVF_MuonBoy_sumet( this, ::TString( prefix ) + "STVF_MuonBoy_sumet", 0 ),
        STVF_MuonBoy_etx_CentralReg( this, ::TString( prefix ) + "STVF_MuonBoy_etx_CentralReg", 0 ),
        STVF_MuonBoy_ety_CentralReg( this, ::TString( prefix ) + "STVF_MuonBoy_ety_CentralReg", 0 ),
        STVF_MuonBoy_sumet_CentralReg( this, ::TString( prefix ) + "STVF_MuonBoy_sumet_CentralReg", 0 ),
        STVF_MuonBoy_phi_CentralReg( this, ::TString( prefix ) + "STVF_MuonBoy_phi_CentralReg", 0 ),
        STVF_MuonBoy_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_MuonBoy_etx_EndcapRegion", 0 ),
        STVF_MuonBoy_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_MuonBoy_ety_EndcapRegion", 0 ),
        STVF_MuonBoy_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_MuonBoy_sumet_EndcapRegion", 0 ),
        STVF_MuonBoy_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_MuonBoy_phi_EndcapRegion", 0 ),
        STVF_MuonBoy_etx_ForwardReg( this, ::TString( prefix ) + "STVF_MuonBoy_etx_ForwardReg", 0 ),
        STVF_MuonBoy_ety_ForwardReg( this, ::TString( prefix ) + "STVF_MuonBoy_ety_ForwardReg", 0 ),
        STVF_MuonBoy_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_MuonBoy_sumet_ForwardReg", 0 ),
        STVF_MuonBoy_phi_ForwardReg( this, ::TString( prefix ) + "STVF_MuonBoy_phi_ForwardReg", 0 ),
        STVF_CellOut_Track_etx( this, ::TString( prefix ) + "STVF_CellOut_Track_etx", 0 ),
        STVF_CellOut_Track_ety( this, ::TString( prefix ) + "STVF_CellOut_Track_ety", 0 ),
        STVF_CellOut_Track_sumet( this, ::TString( prefix ) + "STVF_CellOut_Track_sumet", 0 ),
        STVF_CellOut_Track_etx_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_Track_etx_CentralReg", 0 ),
        STVF_CellOut_Track_ety_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_Track_ety_CentralReg", 0 ),
        STVF_CellOut_Track_sumet_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_Track_sumet_CentralReg", 0 ),
        STVF_CellOut_Track_phi_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_Track_phi_CentralReg", 0 ),
        STVF_CellOut_Track_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_Track_etx_EndcapRegion", 0 ),
        STVF_CellOut_Track_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_Track_ety_EndcapRegion", 0 ),
        STVF_CellOut_Track_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_Track_sumet_EndcapRegion", 0 ),
        STVF_CellOut_Track_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_Track_phi_EndcapRegion", 0 ),
        STVF_CellOut_Track_etx_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_Track_etx_ForwardReg", 0 ),
        STVF_CellOut_Track_ety_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_Track_ety_ForwardReg", 0 ),
        STVF_CellOut_Track_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_Track_sumet_ForwardReg", 0 ),
        STVF_CellOut_Track_phi_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_Track_phi_ForwardReg", 0 ),
        STVF_CellOut_TrackPV_etx( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_etx", 0 ),
        STVF_CellOut_TrackPV_ety( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_ety", 0 ),
        STVF_CellOut_TrackPV_sumet( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_sumet", 0 ),
        STVF_CellOut_TrackPV_etx_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_etx_CentralReg", 0 ),
        STVF_CellOut_TrackPV_ety_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_ety_CentralReg", 0 ),
        STVF_CellOut_TrackPV_sumet_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_sumet_CentralReg", 0 ),
        STVF_CellOut_TrackPV_phi_CentralReg( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_phi_CentralReg", 0 ),
        STVF_CellOut_TrackPV_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_etx_EndcapRegion", 0 ),
        STVF_CellOut_TrackPV_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_ety_EndcapRegion", 0 ),
        STVF_CellOut_TrackPV_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_sumet_EndcapRegion", 0 ),
        STVF_CellOut_TrackPV_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_phi_EndcapRegion", 0 ),
        STVF_CellOut_TrackPV_etx_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_etx_ForwardReg", 0 ),
        STVF_CellOut_TrackPV_ety_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_ety_ForwardReg", 0 ),
        STVF_CellOut_TrackPV_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_sumet_ForwardReg", 0 ),
        STVF_CellOut_TrackPV_phi_ForwardReg( this, ::TString( prefix ) + "STVF_CellOut_TrackPV_phi_ForwardReg", 0 ),
        STVF_CellOutCorr_etx( this, ::TString( prefix ) + "STVF_CellOutCorr_etx", 0 ),
        STVF_CellOutCorr_ety( this, ::TString( prefix ) + "STVF_CellOutCorr_ety", 0 ),
        STVF_CellOutCorr_sumet( this, ::TString( prefix ) + "STVF_CellOutCorr_sumet", 0 ),
        STVF_CellOutCorr_etx_CentralReg( this, ::TString( prefix ) + "STVF_CellOutCorr_etx_CentralReg", 0 ),
        STVF_CellOutCorr_ety_CentralReg( this, ::TString( prefix ) + "STVF_CellOutCorr_ety_CentralReg", 0 ),
        STVF_CellOutCorr_sumet_CentralReg( this, ::TString( prefix ) + "STVF_CellOutCorr_sumet_CentralReg", 0 ),
        STVF_CellOutCorr_phi_CentralReg( this, ::TString( prefix ) + "STVF_CellOutCorr_phi_CentralReg", 0 ),
        STVF_CellOutCorr_etx_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOutCorr_etx_EndcapRegion", 0 ),
        STVF_CellOutCorr_ety_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOutCorr_ety_EndcapRegion", 0 ),
        STVF_CellOutCorr_sumet_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOutCorr_sumet_EndcapRegion", 0 ),
        STVF_CellOutCorr_phi_EndcapRegion( this, ::TString( prefix ) + "STVF_CellOutCorr_phi_EndcapRegion", 0 ),
        STVF_CellOutCorr_etx_ForwardReg( this, ::TString( prefix ) + "STVF_CellOutCorr_etx_ForwardReg", 0 ),
        STVF_CellOutCorr_ety_ForwardReg( this, ::TString( prefix ) + "STVF_CellOutCorr_ety_ForwardReg", 0 ),
        STVF_CellOutCorr_sumet_ForwardReg( this, ::TString( prefix ) + "STVF_CellOutCorr_sumet_ForwardReg", 0 ),
        STVF_CellOutCorr_phi_ForwardReg( this, ::TString( prefix ) + "STVF_CellOutCorr_phi_ForwardReg", 0 ),
        fHandles(),
        fFromInput( kFALSE ),
        fPrefix( prefix ) , 
is_data(is_data) {

      fHandles[ "RefGamma_etx" ] = &RefGamma_etx;
      fHandles[ "RefGamma_ety" ] = &RefGamma_ety;
      fHandles[ "RefGamma_sumet" ] = &RefGamma_sumet;
      fHandles[ "RefGamma_etx_CentralReg" ] = &RefGamma_etx_CentralReg;
      fHandles[ "RefGamma_ety_CentralReg" ] = &RefGamma_ety_CentralReg;
      fHandles[ "RefGamma_sumet_CentralReg" ] = &RefGamma_sumet_CentralReg;
      fHandles[ "RefGamma_phi_CentralReg" ] = &RefGamma_phi_CentralReg;
      fHandles[ "RefGamma_etx_EndcapRegion" ] = &RefGamma_etx_EndcapRegion;
      fHandles[ "RefGamma_ety_EndcapRegion" ] = &RefGamma_ety_EndcapRegion;
      fHandles[ "RefGamma_sumet_EndcapRegion" ] = &RefGamma_sumet_EndcapRegion;
      fHandles[ "RefGamma_phi_EndcapRegion" ] = &RefGamma_phi_EndcapRegion;
      fHandles[ "RefGamma_etx_ForwardReg" ] = &RefGamma_etx_ForwardReg;
      fHandles[ "RefGamma_ety_ForwardReg" ] = &RefGamma_ety_ForwardReg;
      fHandles[ "RefGamma_sumet_ForwardReg" ] = &RefGamma_sumet_ForwardReg;
      fHandles[ "RefGamma_phi_ForwardReg" ] = &RefGamma_phi_ForwardReg;
      fHandles[ "STVF_RefGamma_etx" ] = &STVF_RefGamma_etx;
      fHandles[ "STVF_RefGamma_ety" ] = &STVF_RefGamma_ety;
      fHandles[ "STVF_RefGamma_sumet" ] = &STVF_RefGamma_sumet;
      fHandles[ "STVF_RefGamma_etx_CentralReg" ] = &STVF_RefGamma_etx_CentralReg;
      fHandles[ "STVF_RefGamma_ety_CentralReg" ] = &STVF_RefGamma_ety_CentralReg;
      fHandles[ "STVF_RefGamma_sumet_CentralReg" ] = &STVF_RefGamma_sumet_CentralReg;
      fHandles[ "STVF_RefGamma_phi_CentralReg" ] = &STVF_RefGamma_phi_CentralReg;
      fHandles[ "STVF_RefGamma_etx_EndcapRegion" ] = &STVF_RefGamma_etx_EndcapRegion;
      fHandles[ "STVF_RefGamma_ety_EndcapRegion" ] = &STVF_RefGamma_ety_EndcapRegion;
      fHandles[ "STVF_RefGamma_sumet_EndcapRegion" ] = &STVF_RefGamma_sumet_EndcapRegion;
      fHandles[ "STVF_RefGamma_phi_EndcapRegion" ] = &STVF_RefGamma_phi_EndcapRegion;
      fHandles[ "STVF_RefGamma_etx_ForwardReg" ] = &STVF_RefGamma_etx_ForwardReg;
      fHandles[ "STVF_RefGamma_ety_ForwardReg" ] = &STVF_RefGamma_ety_ForwardReg;
      fHandles[ "STVF_RefGamma_sumet_ForwardReg" ] = &STVF_RefGamma_sumet_ForwardReg;
      fHandles[ "STVF_RefGamma_phi_ForwardReg" ] = &STVF_RefGamma_phi_ForwardReg;
      fHandles[ "RefFinal_etx" ] = &RefFinal_etx;
      fHandles[ "RefFinal_ety" ] = &RefFinal_ety;
      fHandles[ "RefFinal_sumet" ] = &RefFinal_sumet;
      fHandles[ "RefFinal_etx_CentralReg" ] = &RefFinal_etx_CentralReg;
      fHandles[ "RefFinal_ety_CentralReg" ] = &RefFinal_ety_CentralReg;
      fHandles[ "RefFinal_sumet_CentralReg" ] = &RefFinal_sumet_CentralReg;
      fHandles[ "RefFinal_phi_CentralReg" ] = &RefFinal_phi_CentralReg;
      fHandles[ "RefFinal_etx_EndcapRegion" ] = &RefFinal_etx_EndcapRegion;
      fHandles[ "RefFinal_ety_EndcapRegion" ] = &RefFinal_ety_EndcapRegion;
      fHandles[ "RefFinal_sumet_EndcapRegion" ] = &RefFinal_sumet_EndcapRegion;
      fHandles[ "RefFinal_phi_EndcapRegion" ] = &RefFinal_phi_EndcapRegion;
      fHandles[ "RefFinal_etx_ForwardReg" ] = &RefFinal_etx_ForwardReg;
      fHandles[ "RefFinal_ety_ForwardReg" ] = &RefFinal_ety_ForwardReg;
      fHandles[ "RefFinal_sumet_ForwardReg" ] = &RefFinal_sumet_ForwardReg;
      fHandles[ "RefFinal_phi_ForwardReg" ] = &RefFinal_phi_ForwardReg;
      fHandles[ "STVF_RefFinal_etx" ] = &STVF_RefFinal_etx;
      fHandles[ "STVF_RefFinal_ety" ] = &STVF_RefFinal_ety;
      fHandles[ "STVF_RefFinal_sumet" ] = &STVF_RefFinal_sumet;
      fHandles[ "STVF_RefFinal_etx_CentralReg" ] = &STVF_RefFinal_etx_CentralReg;
      fHandles[ "STVF_RefFinal_ety_CentralReg" ] = &STVF_RefFinal_ety_CentralReg;
      fHandles[ "STVF_RefFinal_sumet_CentralReg" ] = &STVF_RefFinal_sumet_CentralReg;
      fHandles[ "STVF_RefFinal_phi_CentralReg" ] = &STVF_RefFinal_phi_CentralReg;
      fHandles[ "STVF_RefFinal_etx_EndcapRegion" ] = &STVF_RefFinal_etx_EndcapRegion;
      fHandles[ "STVF_RefFinal_ety_EndcapRegion" ] = &STVF_RefFinal_ety_EndcapRegion;
      fHandles[ "STVF_RefFinal_sumet_EndcapRegion" ] = &STVF_RefFinal_sumet_EndcapRegion;
      fHandles[ "STVF_RefFinal_phi_EndcapRegion" ] = &STVF_RefFinal_phi_EndcapRegion;
      fHandles[ "STVF_RefFinal_etx_ForwardReg" ] = &STVF_RefFinal_etx_ForwardReg;
      fHandles[ "STVF_RefFinal_ety_ForwardReg" ] = &STVF_RefFinal_ety_ForwardReg;
      fHandles[ "STVF_RefFinal_sumet_ForwardReg" ] = &STVF_RefFinal_sumet_ForwardReg;
      fHandles[ "STVF_RefFinal_phi_ForwardReg" ] = &STVF_RefFinal_phi_ForwardReg;
      fHandles[ "RefJet_etx" ] = &RefJet_etx;
      fHandles[ "RefJet_ety" ] = &RefJet_ety;
      fHandles[ "RefJet_sumet" ] = &RefJet_sumet;
      fHandles[ "RefJet_etx_CentralReg" ] = &RefJet_etx_CentralReg;
      fHandles[ "RefJet_ety_CentralReg" ] = &RefJet_ety_CentralReg;
      fHandles[ "RefJet_sumet_CentralReg" ] = &RefJet_sumet_CentralReg;
      fHandles[ "RefJet_phi_CentralReg" ] = &RefJet_phi_CentralReg;
      fHandles[ "RefJet_etx_EndcapRegion" ] = &RefJet_etx_EndcapRegion;
      fHandles[ "RefJet_ety_EndcapRegion" ] = &RefJet_ety_EndcapRegion;
      fHandles[ "RefJet_sumet_EndcapRegion" ] = &RefJet_sumet_EndcapRegion;
      fHandles[ "RefJet_phi_EndcapRegion" ] = &RefJet_phi_EndcapRegion;
      fHandles[ "RefJet_etx_ForwardReg" ] = &RefJet_etx_ForwardReg;
      fHandles[ "RefJet_ety_ForwardReg" ] = &RefJet_ety_ForwardReg;
      fHandles[ "RefJet_sumet_ForwardReg" ] = &RefJet_sumet_ForwardReg;
      fHandles[ "RefJet_phi_ForwardReg" ] = &RefJet_phi_ForwardReg;
      fHandles[ "STVF_RefJet_etx" ] = &STVF_RefJet_etx;
      fHandles[ "STVF_RefJet_ety" ] = &STVF_RefJet_ety;
      fHandles[ "STVF_RefJet_sumet" ] = &STVF_RefJet_sumet;
      fHandles[ "STVF_RefJet_etx_CentralReg" ] = &STVF_RefJet_etx_CentralReg;
      fHandles[ "STVF_RefJet_ety_CentralReg" ] = &STVF_RefJet_ety_CentralReg;
      fHandles[ "STVF_RefJet_sumet_CentralReg" ] = &STVF_RefJet_sumet_CentralReg;
      fHandles[ "STVF_RefJet_phi_CentralReg" ] = &STVF_RefJet_phi_CentralReg;
      fHandles[ "STVF_RefJet_etx_EndcapRegion" ] = &STVF_RefJet_etx_EndcapRegion;
      fHandles[ "STVF_RefJet_ety_EndcapRegion" ] = &STVF_RefJet_ety_EndcapRegion;
      fHandles[ "STVF_RefJet_sumet_EndcapRegion" ] = &STVF_RefJet_sumet_EndcapRegion;
      fHandles[ "STVF_RefJet_phi_EndcapRegion" ] = &STVF_RefJet_phi_EndcapRegion;
      fHandles[ "STVF_RefJet_etx_ForwardReg" ] = &STVF_RefJet_etx_ForwardReg;
      fHandles[ "STVF_RefJet_ety_ForwardReg" ] = &STVF_RefJet_ety_ForwardReg;
      fHandles[ "STVF_RefJet_sumet_ForwardReg" ] = &STVF_RefJet_sumet_ForwardReg;
      fHandles[ "STVF_RefJet_phi_ForwardReg" ] = &STVF_RefJet_phi_ForwardReg;
      fHandles[ "RefEle_etx" ] = &RefEle_etx;
      fHandles[ "RefEle_ety" ] = &RefEle_ety;
      fHandles[ "RefEle_sumet" ] = &RefEle_sumet;
      fHandles[ "RefEle_etx_CentralReg" ] = &RefEle_etx_CentralReg;
      fHandles[ "RefEle_ety_CentralReg" ] = &RefEle_ety_CentralReg;
      fHandles[ "RefEle_sumet_CentralReg" ] = &RefEle_sumet_CentralReg;
      fHandles[ "RefEle_phi_CentralReg" ] = &RefEle_phi_CentralReg;
      fHandles[ "RefEle_etx_EndcapRegion" ] = &RefEle_etx_EndcapRegion;
      fHandles[ "RefEle_ety_EndcapRegion" ] = &RefEle_ety_EndcapRegion;
      fHandles[ "RefEle_sumet_EndcapRegion" ] = &RefEle_sumet_EndcapRegion;
      fHandles[ "RefEle_phi_EndcapRegion" ] = &RefEle_phi_EndcapRegion;
      fHandles[ "RefEle_etx_ForwardReg" ] = &RefEle_etx_ForwardReg;
      fHandles[ "RefEle_ety_ForwardReg" ] = &RefEle_ety_ForwardReg;
      fHandles[ "RefEle_sumet_ForwardReg" ] = &RefEle_sumet_ForwardReg;
      fHandles[ "RefEle_phi_ForwardReg" ] = &RefEle_phi_ForwardReg;
      fHandles[ "STVF_RefEle_etx" ] = &STVF_RefEle_etx;
      fHandles[ "STVF_RefEle_ety" ] = &STVF_RefEle_ety;
      fHandles[ "STVF_RefEle_sumet" ] = &STVF_RefEle_sumet;
      fHandles[ "STVF_RefEle_etx_CentralReg" ] = &STVF_RefEle_etx_CentralReg;
      fHandles[ "STVF_RefEle_ety_CentralReg" ] = &STVF_RefEle_ety_CentralReg;
      fHandles[ "STVF_RefEle_sumet_CentralReg" ] = &STVF_RefEle_sumet_CentralReg;
      fHandles[ "STVF_RefEle_phi_CentralReg" ] = &STVF_RefEle_phi_CentralReg;
      fHandles[ "STVF_RefEle_etx_EndcapRegion" ] = &STVF_RefEle_etx_EndcapRegion;
      fHandles[ "STVF_RefEle_ety_EndcapRegion" ] = &STVF_RefEle_ety_EndcapRegion;
      fHandles[ "STVF_RefEle_sumet_EndcapRegion" ] = &STVF_RefEle_sumet_EndcapRegion;
      fHandles[ "STVF_RefEle_phi_EndcapRegion" ] = &STVF_RefEle_phi_EndcapRegion;
      fHandles[ "STVF_RefEle_etx_ForwardReg" ] = &STVF_RefEle_etx_ForwardReg;
      fHandles[ "STVF_RefEle_ety_ForwardReg" ] = &STVF_RefEle_ety_ForwardReg;
      fHandles[ "STVF_RefEle_sumet_ForwardReg" ] = &STVF_RefEle_sumet_ForwardReg;
      fHandles[ "STVF_RefEle_phi_ForwardReg" ] = &STVF_RefEle_phi_ForwardReg;
      fHandles[ "Muon_Total_Staco_etx" ] = &Muon_Total_Staco_etx;
      fHandles[ "Muon_Total_Staco_ety" ] = &Muon_Total_Staco_ety;
      fHandles[ "Muon_Total_Staco_sumet" ] = &Muon_Total_Staco_sumet;
      fHandles[ "Muon_Total_Staco_etx_CentralReg" ] = &Muon_Total_Staco_etx_CentralReg;
      fHandles[ "Muon_Total_Staco_ety_CentralReg" ] = &Muon_Total_Staco_ety_CentralReg;
      fHandles[ "Muon_Total_Staco_sumet_CentralReg" ] = &Muon_Total_Staco_sumet_CentralReg;
      fHandles[ "Muon_Total_Staco_phi_CentralReg" ] = &Muon_Total_Staco_phi_CentralReg;
      fHandles[ "Muon_Total_Staco_etx_EndcapRegion" ] = &Muon_Total_Staco_etx_EndcapRegion;
      fHandles[ "Muon_Total_Staco_ety_EndcapRegion" ] = &Muon_Total_Staco_ety_EndcapRegion;
      fHandles[ "Muon_Total_Staco_sumet_EndcapRegion" ] = &Muon_Total_Staco_sumet_EndcapRegion;
      fHandles[ "Muon_Total_Staco_phi_EndcapRegion" ] = &Muon_Total_Staco_phi_EndcapRegion;
      fHandles[ "Muon_Total_Staco_etx_ForwardReg" ] = &Muon_Total_Staco_etx_ForwardReg;
      fHandles[ "Muon_Total_Staco_ety_ForwardReg" ] = &Muon_Total_Staco_ety_ForwardReg;
      fHandles[ "Muon_Total_Staco_sumet_ForwardReg" ] = &Muon_Total_Staco_sumet_ForwardReg;
      fHandles[ "Muon_Total_Staco_phi_ForwardReg" ] = &Muon_Total_Staco_phi_ForwardReg;
      fHandles[ "STVF_Muon_Total_Staco_etx" ] = &STVF_Muon_Total_Staco_etx;
      fHandles[ "STVF_Muon_Total_Staco_ety" ] = &STVF_Muon_Total_Staco_ety;
      fHandles[ "STVF_Muon_Total_Staco_sumet" ] = &STVF_Muon_Total_Staco_sumet;
      fHandles[ "STVF_Muon_Total_Staco_etx_CentralReg" ] = &STVF_Muon_Total_Staco_etx_CentralReg;
      fHandles[ "STVF_Muon_Total_Staco_ety_CentralReg" ] = &STVF_Muon_Total_Staco_ety_CentralReg;
      fHandles[ "STVF_Muon_Total_Staco_sumet_CentralReg" ] = &STVF_Muon_Total_Staco_sumet_CentralReg;
      fHandles[ "STVF_Muon_Total_Staco_phi_CentralReg" ] = &STVF_Muon_Total_Staco_phi_CentralReg;
      fHandles[ "STVF_Muon_Total_Staco_etx_EndcapRegion" ] = &STVF_Muon_Total_Staco_etx_EndcapRegion;
      fHandles[ "STVF_Muon_Total_Staco_ety_EndcapRegion" ] = &STVF_Muon_Total_Staco_ety_EndcapRegion;
      fHandles[ "STVF_Muon_Total_Staco_sumet_EndcapRegion" ] = &STVF_Muon_Total_Staco_sumet_EndcapRegion;
      fHandles[ "STVF_Muon_Total_Staco_phi_EndcapRegion" ] = &STVF_Muon_Total_Staco_phi_EndcapRegion;
      fHandles[ "STVF_Muon_Total_Staco_etx_ForwardReg" ] = &STVF_Muon_Total_Staco_etx_ForwardReg;
      fHandles[ "STVF_Muon_Total_Staco_ety_ForwardReg" ] = &STVF_Muon_Total_Staco_ety_ForwardReg;
      fHandles[ "STVF_Muon_Total_Staco_sumet_ForwardReg" ] = &STVF_Muon_Total_Staco_sumet_ForwardReg;
      fHandles[ "STVF_Muon_Total_Staco_phi_ForwardReg" ] = &STVF_Muon_Total_Staco_phi_ForwardReg;
      fHandles[ "Muon_Isol_Staco_etx" ] = &Muon_Isol_Staco_etx;
      fHandles[ "Muon_Isol_Staco_ety" ] = &Muon_Isol_Staco_ety;
      fHandles[ "Muon_Isol_Staco_sumet" ] = &Muon_Isol_Staco_sumet;
      fHandles[ "Muon_Isol_Staco_etx_CentralReg" ] = &Muon_Isol_Staco_etx_CentralReg;
      fHandles[ "Muon_Isol_Staco_ety_CentralReg" ] = &Muon_Isol_Staco_ety_CentralReg;
      fHandles[ "Muon_Isol_Staco_sumet_CentralReg" ] = &Muon_Isol_Staco_sumet_CentralReg;
      fHandles[ "Muon_Isol_Staco_phi_CentralReg" ] = &Muon_Isol_Staco_phi_CentralReg;
      fHandles[ "Muon_Isol_Staco_etx_EndcapRegion" ] = &Muon_Isol_Staco_etx_EndcapRegion;
      fHandles[ "Muon_Isol_Staco_ety_EndcapRegion" ] = &Muon_Isol_Staco_ety_EndcapRegion;
      fHandles[ "Muon_Isol_Staco_sumet_EndcapRegion" ] = &Muon_Isol_Staco_sumet_EndcapRegion;
      fHandles[ "Muon_Isol_Staco_phi_EndcapRegion" ] = &Muon_Isol_Staco_phi_EndcapRegion;
      fHandles[ "Muon_Isol_Staco_etx_ForwardReg" ] = &Muon_Isol_Staco_etx_ForwardReg;
      fHandles[ "Muon_Isol_Staco_ety_ForwardReg" ] = &Muon_Isol_Staco_ety_ForwardReg;
      fHandles[ "Muon_Isol_Staco_sumet_ForwardReg" ] = &Muon_Isol_Staco_sumet_ForwardReg;
      fHandles[ "Muon_Isol_Staco_phi_ForwardReg" ] = &Muon_Isol_Staco_phi_ForwardReg;
      fHandles[ "STVF_Muon_Isol_Staco_etx" ] = &STVF_Muon_Isol_Staco_etx;
      fHandles[ "STVF_Muon_Isol_Staco_ety" ] = &STVF_Muon_Isol_Staco_ety;
      fHandles[ "STVF_Muon_Isol_Staco_sumet" ] = &STVF_Muon_Isol_Staco_sumet;
      fHandles[ "STVF_Muon_Isol_Staco_etx_CentralReg" ] = &STVF_Muon_Isol_Staco_etx_CentralReg;
      fHandles[ "STVF_Muon_Isol_Staco_ety_CentralReg" ] = &STVF_Muon_Isol_Staco_ety_CentralReg;
      fHandles[ "STVF_Muon_Isol_Staco_sumet_CentralReg" ] = &STVF_Muon_Isol_Staco_sumet_CentralReg;
      fHandles[ "STVF_Muon_Isol_Staco_phi_CentralReg" ] = &STVF_Muon_Isol_Staco_phi_CentralReg;
      fHandles[ "STVF_Muon_Isol_Staco_etx_EndcapRegion" ] = &STVF_Muon_Isol_Staco_etx_EndcapRegion;
      fHandles[ "STVF_Muon_Isol_Staco_ety_EndcapRegion" ] = &STVF_Muon_Isol_Staco_ety_EndcapRegion;
      fHandles[ "STVF_Muon_Isol_Staco_sumet_EndcapRegion" ] = &STVF_Muon_Isol_Staco_sumet_EndcapRegion;
      fHandles[ "STVF_Muon_Isol_Staco_phi_EndcapRegion" ] = &STVF_Muon_Isol_Staco_phi_EndcapRegion;
      fHandles[ "STVF_Muon_Isol_Staco_etx_ForwardReg" ] = &STVF_Muon_Isol_Staco_etx_ForwardReg;
      fHandles[ "STVF_Muon_Isol_Staco_ety_ForwardReg" ] = &STVF_Muon_Isol_Staco_ety_ForwardReg;
      fHandles[ "STVF_Muon_Isol_Staco_sumet_ForwardReg" ] = &STVF_Muon_Isol_Staco_sumet_ForwardReg;
      fHandles[ "STVF_Muon_Isol_Staco_phi_ForwardReg" ] = &STVF_Muon_Isol_Staco_phi_ForwardReg;
      fHandles[ "Muon_NonIsol_Staco_etx" ] = &Muon_NonIsol_Staco_etx;
      fHandles[ "Muon_NonIsol_Staco_ety" ] = &Muon_NonIsol_Staco_ety;
      fHandles[ "Muon_NonIsol_Staco_sumet" ] = &Muon_NonIsol_Staco_sumet;
      fHandles[ "Muon_NonIsol_Staco_etx_CentralReg" ] = &Muon_NonIsol_Staco_etx_CentralReg;
      fHandles[ "Muon_NonIsol_Staco_ety_CentralReg" ] = &Muon_NonIsol_Staco_ety_CentralReg;
      fHandles[ "Muon_NonIsol_Staco_sumet_CentralReg" ] = &Muon_NonIsol_Staco_sumet_CentralReg;
      fHandles[ "Muon_NonIsol_Staco_phi_CentralReg" ] = &Muon_NonIsol_Staco_phi_CentralReg;
      fHandles[ "Muon_NonIsol_Staco_etx_EndcapRegion" ] = &Muon_NonIsol_Staco_etx_EndcapRegion;
      fHandles[ "Muon_NonIsol_Staco_ety_EndcapRegion" ] = &Muon_NonIsol_Staco_ety_EndcapRegion;
      fHandles[ "Muon_NonIsol_Staco_sumet_EndcapRegion" ] = &Muon_NonIsol_Staco_sumet_EndcapRegion;
      fHandles[ "Muon_NonIsol_Staco_phi_EndcapRegion" ] = &Muon_NonIsol_Staco_phi_EndcapRegion;
      fHandles[ "Muon_NonIsol_Staco_etx_ForwardReg" ] = &Muon_NonIsol_Staco_etx_ForwardReg;
      fHandles[ "Muon_NonIsol_Staco_ety_ForwardReg" ] = &Muon_NonIsol_Staco_ety_ForwardReg;
      fHandles[ "Muon_NonIsol_Staco_sumet_ForwardReg" ] = &Muon_NonIsol_Staco_sumet_ForwardReg;
      fHandles[ "Muon_NonIsol_Staco_phi_ForwardReg" ] = &Muon_NonIsol_Staco_phi_ForwardReg;
      fHandles[ "STVF_Muon_NonIsol_Staco_etx" ] = &STVF_Muon_NonIsol_Staco_etx;
      fHandles[ "STVF_Muon_NonIsol_Staco_ety" ] = &STVF_Muon_NonIsol_Staco_ety;
      fHandles[ "STVF_Muon_NonIsol_Staco_sumet" ] = &STVF_Muon_NonIsol_Staco_sumet;
      fHandles[ "STVF_Muon_NonIsol_Staco_etx_CentralReg" ] = &STVF_Muon_NonIsol_Staco_etx_CentralReg;
      fHandles[ "STVF_Muon_NonIsol_Staco_ety_CentralReg" ] = &STVF_Muon_NonIsol_Staco_ety_CentralReg;
      fHandles[ "STVF_Muon_NonIsol_Staco_sumet_CentralReg" ] = &STVF_Muon_NonIsol_Staco_sumet_CentralReg;
      fHandles[ "STVF_Muon_NonIsol_Staco_phi_CentralReg" ] = &STVF_Muon_NonIsol_Staco_phi_CentralReg;
      fHandles[ "STVF_Muon_NonIsol_Staco_etx_EndcapRegion" ] = &STVF_Muon_NonIsol_Staco_etx_EndcapRegion;
      fHandles[ "STVF_Muon_NonIsol_Staco_ety_EndcapRegion" ] = &STVF_Muon_NonIsol_Staco_ety_EndcapRegion;
      fHandles[ "STVF_Muon_NonIsol_Staco_sumet_EndcapRegion" ] = &STVF_Muon_NonIsol_Staco_sumet_EndcapRegion;
      fHandles[ "STVF_Muon_NonIsol_Staco_phi_EndcapRegion" ] = &STVF_Muon_NonIsol_Staco_phi_EndcapRegion;
      fHandles[ "STVF_Muon_NonIsol_Staco_etx_ForwardReg" ] = &STVF_Muon_NonIsol_Staco_etx_ForwardReg;
      fHandles[ "STVF_Muon_NonIsol_Staco_ety_ForwardReg" ] = &STVF_Muon_NonIsol_Staco_ety_ForwardReg;
      fHandles[ "STVF_Muon_NonIsol_Staco_sumet_ForwardReg" ] = &STVF_Muon_NonIsol_Staco_sumet_ForwardReg;
      fHandles[ "STVF_Muon_NonIsol_Staco_phi_ForwardReg" ] = &STVF_Muon_NonIsol_Staco_phi_ForwardReg;
      fHandles[ "CellOut_etx" ] = &CellOut_etx;
      fHandles[ "CellOut_ety" ] = &CellOut_ety;
      fHandles[ "CellOut_sumet" ] = &CellOut_sumet;
      fHandles[ "CellOut_etx_CentralReg" ] = &CellOut_etx_CentralReg;
      fHandles[ "CellOut_ety_CentralReg" ] = &CellOut_ety_CentralReg;
      fHandles[ "CellOut_sumet_CentralReg" ] = &CellOut_sumet_CentralReg;
      fHandles[ "CellOut_phi_CentralReg" ] = &CellOut_phi_CentralReg;
      fHandles[ "CellOut_etx_EndcapRegion" ] = &CellOut_etx_EndcapRegion;
      fHandles[ "CellOut_ety_EndcapRegion" ] = &CellOut_ety_EndcapRegion;
      fHandles[ "CellOut_sumet_EndcapRegion" ] = &CellOut_sumet_EndcapRegion;
      fHandles[ "CellOut_phi_EndcapRegion" ] = &CellOut_phi_EndcapRegion;
      fHandles[ "CellOut_etx_ForwardReg" ] = &CellOut_etx_ForwardReg;
      fHandles[ "CellOut_ety_ForwardReg" ] = &CellOut_ety_ForwardReg;
      fHandles[ "CellOut_sumet_ForwardReg" ] = &CellOut_sumet_ForwardReg;
      fHandles[ "CellOut_phi_ForwardReg" ] = &CellOut_phi_ForwardReg;
      fHandles[ "STVF_CellOut_etx" ] = &STVF_CellOut_etx;
      fHandles[ "STVF_CellOut_ety" ] = &STVF_CellOut_ety;
      fHandles[ "STVF_CellOut_sumet" ] = &STVF_CellOut_sumet;
      fHandles[ "STVF_CellOut_etx_CentralReg" ] = &STVF_CellOut_etx_CentralReg;
      fHandles[ "STVF_CellOut_ety_CentralReg" ] = &STVF_CellOut_ety_CentralReg;
      fHandles[ "STVF_CellOut_sumet_CentralReg" ] = &STVF_CellOut_sumet_CentralReg;
      fHandles[ "STVF_CellOut_phi_CentralReg" ] = &STVF_CellOut_phi_CentralReg;
      fHandles[ "STVF_CellOut_etx_EndcapRegion" ] = &STVF_CellOut_etx_EndcapRegion;
      fHandles[ "STVF_CellOut_ety_EndcapRegion" ] = &STVF_CellOut_ety_EndcapRegion;
      fHandles[ "STVF_CellOut_sumet_EndcapRegion" ] = &STVF_CellOut_sumet_EndcapRegion;
      fHandles[ "STVF_CellOut_phi_EndcapRegion" ] = &STVF_CellOut_phi_EndcapRegion;
      fHandles[ "STVF_CellOut_etx_ForwardReg" ] = &STVF_CellOut_etx_ForwardReg;
      fHandles[ "STVF_CellOut_ety_ForwardReg" ] = &STVF_CellOut_ety_ForwardReg;
      fHandles[ "STVF_CellOut_sumet_ForwardReg" ] = &STVF_CellOut_sumet_ForwardReg;
      fHandles[ "STVF_CellOut_phi_ForwardReg" ] = &STVF_CellOut_phi_ForwardReg;
      fHandles[ "Muon_Isol_Muid_etx" ] = &Muon_Isol_Muid_etx;
      fHandles[ "Muon_Isol_Muid_ety" ] = &Muon_Isol_Muid_ety;
      fHandles[ "Muon_Isol_Muid_sumet" ] = &Muon_Isol_Muid_sumet;
      fHandles[ "Muon_Isol_Muid_etx_CentralReg" ] = &Muon_Isol_Muid_etx_CentralReg;
      fHandles[ "Muon_Isol_Muid_ety_CentralReg" ] = &Muon_Isol_Muid_ety_CentralReg;
      fHandles[ "Muon_Isol_Muid_sumet_CentralReg" ] = &Muon_Isol_Muid_sumet_CentralReg;
      fHandles[ "Muon_Isol_Muid_phi_CentralReg" ] = &Muon_Isol_Muid_phi_CentralReg;
      fHandles[ "Muon_Isol_Muid_etx_EndcapRegion" ] = &Muon_Isol_Muid_etx_EndcapRegion;
      fHandles[ "Muon_Isol_Muid_ety_EndcapRegion" ] = &Muon_Isol_Muid_ety_EndcapRegion;
      fHandles[ "Muon_Isol_Muid_sumet_EndcapRegion" ] = &Muon_Isol_Muid_sumet_EndcapRegion;
      fHandles[ "Muon_Isol_Muid_phi_EndcapRegion" ] = &Muon_Isol_Muid_phi_EndcapRegion;
      fHandles[ "Muon_Isol_Muid_etx_ForwardReg" ] = &Muon_Isol_Muid_etx_ForwardReg;
      fHandles[ "Muon_Isol_Muid_ety_ForwardReg" ] = &Muon_Isol_Muid_ety_ForwardReg;
      fHandles[ "Muon_Isol_Muid_sumet_ForwardReg" ] = &Muon_Isol_Muid_sumet_ForwardReg;
      fHandles[ "Muon_Isol_Muid_phi_ForwardReg" ] = &Muon_Isol_Muid_phi_ForwardReg;
      fHandles[ "STVF_Muon_Isol_Muid_etx" ] = &STVF_Muon_Isol_Muid_etx;
      fHandles[ "STVF_Muon_Isol_Muid_ety" ] = &STVF_Muon_Isol_Muid_ety;
      fHandles[ "STVF_Muon_Isol_Muid_sumet" ] = &STVF_Muon_Isol_Muid_sumet;
      fHandles[ "STVF_Muon_Isol_Muid_etx_CentralReg" ] = &STVF_Muon_Isol_Muid_etx_CentralReg;
      fHandles[ "STVF_Muon_Isol_Muid_ety_CentralReg" ] = &STVF_Muon_Isol_Muid_ety_CentralReg;
      fHandles[ "STVF_Muon_Isol_Muid_sumet_CentralReg" ] = &STVF_Muon_Isol_Muid_sumet_CentralReg;
      fHandles[ "STVF_Muon_Isol_Muid_phi_CentralReg" ] = &STVF_Muon_Isol_Muid_phi_CentralReg;
      fHandles[ "STVF_Muon_Isol_Muid_etx_EndcapRegion" ] = &STVF_Muon_Isol_Muid_etx_EndcapRegion;
      fHandles[ "STVF_Muon_Isol_Muid_ety_EndcapRegion" ] = &STVF_Muon_Isol_Muid_ety_EndcapRegion;
      fHandles[ "STVF_Muon_Isol_Muid_sumet_EndcapRegion" ] = &STVF_Muon_Isol_Muid_sumet_EndcapRegion;
      fHandles[ "STVF_Muon_Isol_Muid_phi_EndcapRegion" ] = &STVF_Muon_Isol_Muid_phi_EndcapRegion;
      fHandles[ "STVF_Muon_Isol_Muid_etx_ForwardReg" ] = &STVF_Muon_Isol_Muid_etx_ForwardReg;
      fHandles[ "STVF_Muon_Isol_Muid_ety_ForwardReg" ] = &STVF_Muon_Isol_Muid_ety_ForwardReg;
      fHandles[ "STVF_Muon_Isol_Muid_sumet_ForwardReg" ] = &STVF_Muon_Isol_Muid_sumet_ForwardReg;
      fHandles[ "STVF_Muon_Isol_Muid_phi_ForwardReg" ] = &STVF_Muon_Isol_Muid_phi_ForwardReg;
      fHandles[ "Muon_NonIsol_Muid_etx" ] = &Muon_NonIsol_Muid_etx;
      fHandles[ "Muon_NonIsol_Muid_ety" ] = &Muon_NonIsol_Muid_ety;
      fHandles[ "Muon_NonIsol_Muid_sumet" ] = &Muon_NonIsol_Muid_sumet;
      fHandles[ "Muon_NonIsol_Muid_etx_CentralReg" ] = &Muon_NonIsol_Muid_etx_CentralReg;
      fHandles[ "Muon_NonIsol_Muid_ety_CentralReg" ] = &Muon_NonIsol_Muid_ety_CentralReg;
      fHandles[ "Muon_NonIsol_Muid_sumet_CentralReg" ] = &Muon_NonIsol_Muid_sumet_CentralReg;
      fHandles[ "Muon_NonIsol_Muid_phi_CentralReg" ] = &Muon_NonIsol_Muid_phi_CentralReg;
      fHandles[ "Muon_NonIsol_Muid_etx_EndcapRegion" ] = &Muon_NonIsol_Muid_etx_EndcapRegion;
      fHandles[ "Muon_NonIsol_Muid_ety_EndcapRegion" ] = &Muon_NonIsol_Muid_ety_EndcapRegion;
      fHandles[ "Muon_NonIsol_Muid_sumet_EndcapRegion" ] = &Muon_NonIsol_Muid_sumet_EndcapRegion;
      fHandles[ "Muon_NonIsol_Muid_phi_EndcapRegion" ] = &Muon_NonIsol_Muid_phi_EndcapRegion;
      fHandles[ "Muon_NonIsol_Muid_etx_ForwardReg" ] = &Muon_NonIsol_Muid_etx_ForwardReg;
      fHandles[ "Muon_NonIsol_Muid_ety_ForwardReg" ] = &Muon_NonIsol_Muid_ety_ForwardReg;
      fHandles[ "Muon_NonIsol_Muid_sumet_ForwardReg" ] = &Muon_NonIsol_Muid_sumet_ForwardReg;
      fHandles[ "Muon_NonIsol_Muid_phi_ForwardReg" ] = &Muon_NonIsol_Muid_phi_ForwardReg;
      fHandles[ "STVF_Muon_NonIsol_Muid_etx" ] = &STVF_Muon_NonIsol_Muid_etx;
      fHandles[ "STVF_Muon_NonIsol_Muid_ety" ] = &STVF_Muon_NonIsol_Muid_ety;
      fHandles[ "STVF_Muon_NonIsol_Muid_sumet" ] = &STVF_Muon_NonIsol_Muid_sumet;
      fHandles[ "STVF_Muon_NonIsol_Muid_etx_CentralReg" ] = &STVF_Muon_NonIsol_Muid_etx_CentralReg;
      fHandles[ "STVF_Muon_NonIsol_Muid_ety_CentralReg" ] = &STVF_Muon_NonIsol_Muid_ety_CentralReg;
      fHandles[ "STVF_Muon_NonIsol_Muid_sumet_CentralReg" ] = &STVF_Muon_NonIsol_Muid_sumet_CentralReg;
      fHandles[ "STVF_Muon_NonIsol_Muid_phi_CentralReg" ] = &STVF_Muon_NonIsol_Muid_phi_CentralReg;
      fHandles[ "STVF_Muon_NonIsol_Muid_etx_EndcapRegion" ] = &STVF_Muon_NonIsol_Muid_etx_EndcapRegion;
      fHandles[ "STVF_Muon_NonIsol_Muid_ety_EndcapRegion" ] = &STVF_Muon_NonIsol_Muid_ety_EndcapRegion;
      fHandles[ "STVF_Muon_NonIsol_Muid_sumet_EndcapRegion" ] = &STVF_Muon_NonIsol_Muid_sumet_EndcapRegion;
      fHandles[ "STVF_Muon_NonIsol_Muid_phi_EndcapRegion" ] = &STVF_Muon_NonIsol_Muid_phi_EndcapRegion;
      fHandles[ "STVF_Muon_NonIsol_Muid_etx_ForwardReg" ] = &STVF_Muon_NonIsol_Muid_etx_ForwardReg;
      fHandles[ "STVF_Muon_NonIsol_Muid_ety_ForwardReg" ] = &STVF_Muon_NonIsol_Muid_ety_ForwardReg;
      fHandles[ "STVF_Muon_NonIsol_Muid_sumet_ForwardReg" ] = &STVF_Muon_NonIsol_Muid_sumet_ForwardReg;
      fHandles[ "STVF_Muon_NonIsol_Muid_phi_ForwardReg" ] = &STVF_Muon_NonIsol_Muid_phi_ForwardReg;
      fHandles[ "Muon_Total_Muid_etx" ] = &Muon_Total_Muid_etx;
      fHandles[ "Muon_Total_Muid_ety" ] = &Muon_Total_Muid_ety;
      fHandles[ "Muon_Total_Muid_sumet" ] = &Muon_Total_Muid_sumet;
      fHandles[ "Muon_Total_Muid_etx_CentralReg" ] = &Muon_Total_Muid_etx_CentralReg;
      fHandles[ "Muon_Total_Muid_ety_CentralReg" ] = &Muon_Total_Muid_ety_CentralReg;
      fHandles[ "Muon_Total_Muid_sumet_CentralReg" ] = &Muon_Total_Muid_sumet_CentralReg;
      fHandles[ "Muon_Total_Muid_phi_CentralReg" ] = &Muon_Total_Muid_phi_CentralReg;
      fHandles[ "Muon_Total_Muid_etx_EndcapRegion" ] = &Muon_Total_Muid_etx_EndcapRegion;
      fHandles[ "Muon_Total_Muid_ety_EndcapRegion" ] = &Muon_Total_Muid_ety_EndcapRegion;
      fHandles[ "Muon_Total_Muid_sumet_EndcapRegion" ] = &Muon_Total_Muid_sumet_EndcapRegion;
      fHandles[ "Muon_Total_Muid_phi_EndcapRegion" ] = &Muon_Total_Muid_phi_EndcapRegion;
      fHandles[ "Muon_Total_Muid_etx_ForwardReg" ] = &Muon_Total_Muid_etx_ForwardReg;
      fHandles[ "Muon_Total_Muid_ety_ForwardReg" ] = &Muon_Total_Muid_ety_ForwardReg;
      fHandles[ "Muon_Total_Muid_sumet_ForwardReg" ] = &Muon_Total_Muid_sumet_ForwardReg;
      fHandles[ "Muon_Total_Muid_phi_ForwardReg" ] = &Muon_Total_Muid_phi_ForwardReg;
      fHandles[ "STVF_Muon_Total_Muid_etx" ] = &STVF_Muon_Total_Muid_etx;
      fHandles[ "STVF_Muon_Total_Muid_ety" ] = &STVF_Muon_Total_Muid_ety;
      fHandles[ "STVF_Muon_Total_Muid_sumet" ] = &STVF_Muon_Total_Muid_sumet;
      fHandles[ "STVF_Muon_Total_Muid_etx_CentralReg" ] = &STVF_Muon_Total_Muid_etx_CentralReg;
      fHandles[ "STVF_Muon_Total_Muid_ety_CentralReg" ] = &STVF_Muon_Total_Muid_ety_CentralReg;
      fHandles[ "STVF_Muon_Total_Muid_sumet_CentralReg" ] = &STVF_Muon_Total_Muid_sumet_CentralReg;
      fHandles[ "STVF_Muon_Total_Muid_phi_CentralReg" ] = &STVF_Muon_Total_Muid_phi_CentralReg;
      fHandles[ "STVF_Muon_Total_Muid_etx_EndcapRegion" ] = &STVF_Muon_Total_Muid_etx_EndcapRegion;
      fHandles[ "STVF_Muon_Total_Muid_ety_EndcapRegion" ] = &STVF_Muon_Total_Muid_ety_EndcapRegion;
      fHandles[ "STVF_Muon_Total_Muid_sumet_EndcapRegion" ] = &STVF_Muon_Total_Muid_sumet_EndcapRegion;
      fHandles[ "STVF_Muon_Total_Muid_phi_EndcapRegion" ] = &STVF_Muon_Total_Muid_phi_EndcapRegion;
      fHandles[ "STVF_Muon_Total_Muid_etx_ForwardReg" ] = &STVF_Muon_Total_Muid_etx_ForwardReg;
      fHandles[ "STVF_Muon_Total_Muid_ety_ForwardReg" ] = &STVF_Muon_Total_Muid_ety_ForwardReg;
      fHandles[ "STVF_Muon_Total_Muid_sumet_ForwardReg" ] = &STVF_Muon_Total_Muid_sumet_ForwardReg;
      fHandles[ "STVF_Muon_Total_Muid_phi_ForwardReg" ] = &STVF_Muon_Total_Muid_phi_ForwardReg;
      fHandles[ "Track_etx" ] = &Track_etx;
      fHandles[ "Track_ety" ] = &Track_ety;
      fHandles[ "Track_sumet" ] = &Track_sumet;
      fHandles[ "Track_etx_CentralReg" ] = &Track_etx_CentralReg;
      fHandles[ "Track_ety_CentralReg" ] = &Track_ety_CentralReg;
      fHandles[ "Track_sumet_CentralReg" ] = &Track_sumet_CentralReg;
      fHandles[ "Track_phi_CentralReg" ] = &Track_phi_CentralReg;
      fHandles[ "Track_etx_EndcapRegion" ] = &Track_etx_EndcapRegion;
      fHandles[ "Track_ety_EndcapRegion" ] = &Track_ety_EndcapRegion;
      fHandles[ "Track_sumet_EndcapRegion" ] = &Track_sumet_EndcapRegion;
      fHandles[ "Track_phi_EndcapRegion" ] = &Track_phi_EndcapRegion;
      fHandles[ "Track_etx_ForwardReg" ] = &Track_etx_ForwardReg;
      fHandles[ "Track_ety_ForwardReg" ] = &Track_ety_ForwardReg;
      fHandles[ "Track_sumet_ForwardReg" ] = &Track_sumet_ForwardReg;
      fHandles[ "Track_phi_ForwardReg" ] = &Track_phi_ForwardReg;
      fHandles[ "STVF_Track_etx" ] = &STVF_Track_etx;
      fHandles[ "STVF_Track_ety" ] = &STVF_Track_ety;
      fHandles[ "STVF_Track_sumet" ] = &STVF_Track_sumet;
      fHandles[ "STVF_Track_etx_CentralReg" ] = &STVF_Track_etx_CentralReg;
      fHandles[ "STVF_Track_ety_CentralReg" ] = &STVF_Track_ety_CentralReg;
      fHandles[ "STVF_Track_sumet_CentralReg" ] = &STVF_Track_sumet_CentralReg;
      fHandles[ "STVF_Track_phi_CentralReg" ] = &STVF_Track_phi_CentralReg;
      fHandles[ "STVF_Track_etx_EndcapRegion" ] = &STVF_Track_etx_EndcapRegion;
      fHandles[ "STVF_Track_ety_EndcapRegion" ] = &STVF_Track_ety_EndcapRegion;
      fHandles[ "STVF_Track_sumet_EndcapRegion" ] = &STVF_Track_sumet_EndcapRegion;
      fHandles[ "STVF_Track_phi_EndcapRegion" ] = &STVF_Track_phi_EndcapRegion;
      fHandles[ "STVF_Track_etx_ForwardReg" ] = &STVF_Track_etx_ForwardReg;
      fHandles[ "STVF_Track_ety_ForwardReg" ] = &STVF_Track_ety_ForwardReg;
      fHandles[ "STVF_Track_sumet_ForwardReg" ] = &STVF_Track_sumet_ForwardReg;
      fHandles[ "STVF_Track_phi_ForwardReg" ] = &STVF_Track_phi_ForwardReg;
      fHandles[ "SoftJets_etx" ] = &SoftJets_etx;
      fHandles[ "SoftJets_ety" ] = &SoftJets_ety;
      fHandles[ "SoftJets_sumet" ] = &SoftJets_sumet;
      fHandles[ "SoftJets_etx_CentralReg" ] = &SoftJets_etx_CentralReg;
      fHandles[ "SoftJets_ety_CentralReg" ] = &SoftJets_ety_CentralReg;
      fHandles[ "SoftJets_sumet_CentralReg" ] = &SoftJets_sumet_CentralReg;
      fHandles[ "SoftJets_phi_CentralReg" ] = &SoftJets_phi_CentralReg;
      fHandles[ "SoftJets_etx_EndcapRegion" ] = &SoftJets_etx_EndcapRegion;
      fHandles[ "SoftJets_ety_EndcapRegion" ] = &SoftJets_ety_EndcapRegion;
      fHandles[ "SoftJets_sumet_EndcapRegion" ] = &SoftJets_sumet_EndcapRegion;
      fHandles[ "SoftJets_phi_EndcapRegion" ] = &SoftJets_phi_EndcapRegion;
      fHandles[ "SoftJets_etx_ForwardReg" ] = &SoftJets_etx_ForwardReg;
      fHandles[ "SoftJets_ety_ForwardReg" ] = &SoftJets_ety_ForwardReg;
      fHandles[ "SoftJets_sumet_ForwardReg" ] = &SoftJets_sumet_ForwardReg;
      fHandles[ "SoftJets_phi_ForwardReg" ] = &SoftJets_phi_ForwardReg;
      fHandles[ "STVF_SoftJets_etx" ] = &STVF_SoftJets_etx;
      fHandles[ "STVF_SoftJets_ety" ] = &STVF_SoftJets_ety;
      fHandles[ "STVF_SoftJets_sumet" ] = &STVF_SoftJets_sumet;
      fHandles[ "STVF_SoftJets_etx_CentralReg" ] = &STVF_SoftJets_etx_CentralReg;
      fHandles[ "STVF_SoftJets_ety_CentralReg" ] = &STVF_SoftJets_ety_CentralReg;
      fHandles[ "STVF_SoftJets_sumet_CentralReg" ] = &STVF_SoftJets_sumet_CentralReg;
      fHandles[ "STVF_SoftJets_phi_CentralReg" ] = &STVF_SoftJets_phi_CentralReg;
      fHandles[ "STVF_SoftJets_etx_EndcapRegion" ] = &STVF_SoftJets_etx_EndcapRegion;
      fHandles[ "STVF_SoftJets_ety_EndcapRegion" ] = &STVF_SoftJets_ety_EndcapRegion;
      fHandles[ "STVF_SoftJets_sumet_EndcapRegion" ] = &STVF_SoftJets_sumet_EndcapRegion;
      fHandles[ "STVF_SoftJets_phi_EndcapRegion" ] = &STVF_SoftJets_phi_EndcapRegion;
      fHandles[ "STVF_SoftJets_etx_ForwardReg" ] = &STVF_SoftJets_etx_ForwardReg;
      fHandles[ "STVF_SoftJets_ety_ForwardReg" ] = &STVF_SoftJets_ety_ForwardReg;
      fHandles[ "STVF_SoftJets_sumet_ForwardReg" ] = &STVF_SoftJets_sumet_ForwardReg;
      fHandles[ "STVF_SoftJets_phi_ForwardReg" ] = &STVF_SoftJets_phi_ForwardReg;
      fHandles[ "RefMuon_etx" ] = &RefMuon_etx;
      fHandles[ "RefMuon_ety" ] = &RefMuon_ety;
      fHandles[ "RefMuon_sumet" ] = &RefMuon_sumet;
      fHandles[ "RefMuon_etx_CentralReg" ] = &RefMuon_etx_CentralReg;
      fHandles[ "RefMuon_ety_CentralReg" ] = &RefMuon_ety_CentralReg;
      fHandles[ "RefMuon_sumet_CentralReg" ] = &RefMuon_sumet_CentralReg;
      fHandles[ "RefMuon_phi_CentralReg" ] = &RefMuon_phi_CentralReg;
      fHandles[ "RefMuon_etx_EndcapRegion" ] = &RefMuon_etx_EndcapRegion;
      fHandles[ "RefMuon_ety_EndcapRegion" ] = &RefMuon_ety_EndcapRegion;
      fHandles[ "RefMuon_sumet_EndcapRegion" ] = &RefMuon_sumet_EndcapRegion;
      fHandles[ "RefMuon_phi_EndcapRegion" ] = &RefMuon_phi_EndcapRegion;
      fHandles[ "RefMuon_etx_ForwardReg" ] = &RefMuon_etx_ForwardReg;
      fHandles[ "RefMuon_ety_ForwardReg" ] = &RefMuon_ety_ForwardReg;
      fHandles[ "RefMuon_sumet_ForwardReg" ] = &RefMuon_sumet_ForwardReg;
      fHandles[ "RefMuon_phi_ForwardReg" ] = &RefMuon_phi_ForwardReg;
      fHandles[ "STVF_RefMuon_etx" ] = &STVF_RefMuon_etx;
      fHandles[ "STVF_RefMuon_ety" ] = &STVF_RefMuon_ety;
      fHandles[ "STVF_RefMuon_sumet" ] = &STVF_RefMuon_sumet;
      fHandles[ "STVF_RefMuon_etx_CentralReg" ] = &STVF_RefMuon_etx_CentralReg;
      fHandles[ "STVF_RefMuon_ety_CentralReg" ] = &STVF_RefMuon_ety_CentralReg;
      fHandles[ "STVF_RefMuon_sumet_CentralReg" ] = &STVF_RefMuon_sumet_CentralReg;
      fHandles[ "STVF_RefMuon_phi_CentralReg" ] = &STVF_RefMuon_phi_CentralReg;
      fHandles[ "STVF_RefMuon_etx_EndcapRegion" ] = &STVF_RefMuon_etx_EndcapRegion;
      fHandles[ "STVF_RefMuon_ety_EndcapRegion" ] = &STVF_RefMuon_ety_EndcapRegion;
      fHandles[ "STVF_RefMuon_sumet_EndcapRegion" ] = &STVF_RefMuon_sumet_EndcapRegion;
      fHandles[ "STVF_RefMuon_phi_EndcapRegion" ] = &STVF_RefMuon_phi_EndcapRegion;
      fHandles[ "STVF_RefMuon_etx_ForwardReg" ] = &STVF_RefMuon_etx_ForwardReg;
      fHandles[ "STVF_RefMuon_ety_ForwardReg" ] = &STVF_RefMuon_ety_ForwardReg;
      fHandles[ "STVF_RefMuon_sumet_ForwardReg" ] = &STVF_RefMuon_sumet_ForwardReg;
      fHandles[ "STVF_RefMuon_phi_ForwardReg" ] = &STVF_RefMuon_phi_ForwardReg;
      fHandles[ "MuonBoy_etx" ] = &MuonBoy_etx;
      fHandles[ "MuonBoy_ety" ] = &MuonBoy_ety;
      fHandles[ "MuonBoy_sumet" ] = &MuonBoy_sumet;
      fHandles[ "MuonBoy_etx_CentralReg" ] = &MuonBoy_etx_CentralReg;
      fHandles[ "MuonBoy_ety_CentralReg" ] = &MuonBoy_ety_CentralReg;
      fHandles[ "MuonBoy_sumet_CentralReg" ] = &MuonBoy_sumet_CentralReg;
      fHandles[ "MuonBoy_phi_CentralReg" ] = &MuonBoy_phi_CentralReg;
      fHandles[ "MuonBoy_etx_EndcapRegion" ] = &MuonBoy_etx_EndcapRegion;
      fHandles[ "MuonBoy_ety_EndcapRegion" ] = &MuonBoy_ety_EndcapRegion;
      fHandles[ "MuonBoy_sumet_EndcapRegion" ] = &MuonBoy_sumet_EndcapRegion;
      fHandles[ "MuonBoy_phi_EndcapRegion" ] = &MuonBoy_phi_EndcapRegion;
      fHandles[ "MuonBoy_etx_ForwardReg" ] = &MuonBoy_etx_ForwardReg;
      fHandles[ "MuonBoy_ety_ForwardReg" ] = &MuonBoy_ety_ForwardReg;
      fHandles[ "MuonBoy_sumet_ForwardReg" ] = &MuonBoy_sumet_ForwardReg;
      fHandles[ "MuonBoy_phi_ForwardReg" ] = &MuonBoy_phi_ForwardReg;
      fHandles[ "STVF_MuonBoy_etx" ] = &STVF_MuonBoy_etx;
      fHandles[ "STVF_MuonBoy_ety" ] = &STVF_MuonBoy_ety;
      fHandles[ "STVF_MuonBoy_sumet" ] = &STVF_MuonBoy_sumet;
      fHandles[ "STVF_MuonBoy_etx_CentralReg" ] = &STVF_MuonBoy_etx_CentralReg;
      fHandles[ "STVF_MuonBoy_ety_CentralReg" ] = &STVF_MuonBoy_ety_CentralReg;
      fHandles[ "STVF_MuonBoy_sumet_CentralReg" ] = &STVF_MuonBoy_sumet_CentralReg;
      fHandles[ "STVF_MuonBoy_phi_CentralReg" ] = &STVF_MuonBoy_phi_CentralReg;
      fHandles[ "STVF_MuonBoy_etx_EndcapRegion" ] = &STVF_MuonBoy_etx_EndcapRegion;
      fHandles[ "STVF_MuonBoy_ety_EndcapRegion" ] = &STVF_MuonBoy_ety_EndcapRegion;
      fHandles[ "STVF_MuonBoy_sumet_EndcapRegion" ] = &STVF_MuonBoy_sumet_EndcapRegion;
      fHandles[ "STVF_MuonBoy_phi_EndcapRegion" ] = &STVF_MuonBoy_phi_EndcapRegion;
      fHandles[ "STVF_MuonBoy_etx_ForwardReg" ] = &STVF_MuonBoy_etx_ForwardReg;
      fHandles[ "STVF_MuonBoy_ety_ForwardReg" ] = &STVF_MuonBoy_ety_ForwardReg;
      fHandles[ "STVF_MuonBoy_sumet_ForwardReg" ] = &STVF_MuonBoy_sumet_ForwardReg;
      fHandles[ "STVF_MuonBoy_phi_ForwardReg" ] = &STVF_MuonBoy_phi_ForwardReg;
      fHandles[ "STVF_CellOut_Track_etx" ] = &STVF_CellOut_Track_etx;
      fHandles[ "STVF_CellOut_Track_ety" ] = &STVF_CellOut_Track_ety;
      fHandles[ "STVF_CellOut_Track_sumet" ] = &STVF_CellOut_Track_sumet;
      fHandles[ "STVF_CellOut_Track_etx_CentralReg" ] = &STVF_CellOut_Track_etx_CentralReg;
      fHandles[ "STVF_CellOut_Track_ety_CentralReg" ] = &STVF_CellOut_Track_ety_CentralReg;
      fHandles[ "STVF_CellOut_Track_sumet_CentralReg" ] = &STVF_CellOut_Track_sumet_CentralReg;
      fHandles[ "STVF_CellOut_Track_phi_CentralReg" ] = &STVF_CellOut_Track_phi_CentralReg;
      fHandles[ "STVF_CellOut_Track_etx_EndcapRegion" ] = &STVF_CellOut_Track_etx_EndcapRegion;
      fHandles[ "STVF_CellOut_Track_ety_EndcapRegion" ] = &STVF_CellOut_Track_ety_EndcapRegion;
      fHandles[ "STVF_CellOut_Track_sumet_EndcapRegion" ] = &STVF_CellOut_Track_sumet_EndcapRegion;
      fHandles[ "STVF_CellOut_Track_phi_EndcapRegion" ] = &STVF_CellOut_Track_phi_EndcapRegion;
      fHandles[ "STVF_CellOut_Track_etx_ForwardReg" ] = &STVF_CellOut_Track_etx_ForwardReg;
      fHandles[ "STVF_CellOut_Track_ety_ForwardReg" ] = &STVF_CellOut_Track_ety_ForwardReg;
      fHandles[ "STVF_CellOut_Track_sumet_ForwardReg" ] = &STVF_CellOut_Track_sumet_ForwardReg;
      fHandles[ "STVF_CellOut_Track_phi_ForwardReg" ] = &STVF_CellOut_Track_phi_ForwardReg;
      fHandles[ "STVF_CellOut_TrackPV_etx" ] = &STVF_CellOut_TrackPV_etx;
      fHandles[ "STVF_CellOut_TrackPV_ety" ] = &STVF_CellOut_TrackPV_ety;
      fHandles[ "STVF_CellOut_TrackPV_sumet" ] = &STVF_CellOut_TrackPV_sumet;
      fHandles[ "STVF_CellOut_TrackPV_etx_CentralReg" ] = &STVF_CellOut_TrackPV_etx_CentralReg;
      fHandles[ "STVF_CellOut_TrackPV_ety_CentralReg" ] = &STVF_CellOut_TrackPV_ety_CentralReg;
      fHandles[ "STVF_CellOut_TrackPV_sumet_CentralReg" ] = &STVF_CellOut_TrackPV_sumet_CentralReg;
      fHandles[ "STVF_CellOut_TrackPV_phi_CentralReg" ] = &STVF_CellOut_TrackPV_phi_CentralReg;
      fHandles[ "STVF_CellOut_TrackPV_etx_EndcapRegion" ] = &STVF_CellOut_TrackPV_etx_EndcapRegion;
      fHandles[ "STVF_CellOut_TrackPV_ety_EndcapRegion" ] = &STVF_CellOut_TrackPV_ety_EndcapRegion;
      fHandles[ "STVF_CellOut_TrackPV_sumet_EndcapRegion" ] = &STVF_CellOut_TrackPV_sumet_EndcapRegion;
      fHandles[ "STVF_CellOut_TrackPV_phi_EndcapRegion" ] = &STVF_CellOut_TrackPV_phi_EndcapRegion;
      fHandles[ "STVF_CellOut_TrackPV_etx_ForwardReg" ] = &STVF_CellOut_TrackPV_etx_ForwardReg;
      fHandles[ "STVF_CellOut_TrackPV_ety_ForwardReg" ] = &STVF_CellOut_TrackPV_ety_ForwardReg;
      fHandles[ "STVF_CellOut_TrackPV_sumet_ForwardReg" ] = &STVF_CellOut_TrackPV_sumet_ForwardReg;
      fHandles[ "STVF_CellOut_TrackPV_phi_ForwardReg" ] = &STVF_CellOut_TrackPV_phi_ForwardReg;
      fHandles[ "STVF_CellOutCorr_etx" ] = &STVF_CellOutCorr_etx;
      fHandles[ "STVF_CellOutCorr_ety" ] = &STVF_CellOutCorr_ety;
      fHandles[ "STVF_CellOutCorr_sumet" ] = &STVF_CellOutCorr_sumet;
      fHandles[ "STVF_CellOutCorr_etx_CentralReg" ] = &STVF_CellOutCorr_etx_CentralReg;
      fHandles[ "STVF_CellOutCorr_ety_CentralReg" ] = &STVF_CellOutCorr_ety_CentralReg;
      fHandles[ "STVF_CellOutCorr_sumet_CentralReg" ] = &STVF_CellOutCorr_sumet_CentralReg;
      fHandles[ "STVF_CellOutCorr_phi_CentralReg" ] = &STVF_CellOutCorr_phi_CentralReg;
      fHandles[ "STVF_CellOutCorr_etx_EndcapRegion" ] = &STVF_CellOutCorr_etx_EndcapRegion;
      fHandles[ "STVF_CellOutCorr_ety_EndcapRegion" ] = &STVF_CellOutCorr_ety_EndcapRegion;
      fHandles[ "STVF_CellOutCorr_sumet_EndcapRegion" ] = &STVF_CellOutCorr_sumet_EndcapRegion;
      fHandles[ "STVF_CellOutCorr_phi_EndcapRegion" ] = &STVF_CellOutCorr_phi_EndcapRegion;
      fHandles[ "STVF_CellOutCorr_etx_ForwardReg" ] = &STVF_CellOutCorr_etx_ForwardReg;
      fHandles[ "STVF_CellOutCorr_ety_ForwardReg" ] = &STVF_CellOutCorr_ety_ForwardReg;
      fHandles[ "STVF_CellOutCorr_sumet_ForwardReg" ] = &STVF_CellOutCorr_sumet_ForwardReg;
      fHandles[ "STVF_CellOutCorr_phi_ForwardReg" ] = &STVF_CellOutCorr_phi_ForwardReg;
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
      RefGamma_etx_CentralReg.SetName( ::TString( prefix ) + "RefGamma_etx_CentralReg" );
      RefGamma_ety_CentralReg.SetName( ::TString( prefix ) + "RefGamma_ety_CentralReg" );
      RefGamma_sumet_CentralReg.SetName( ::TString( prefix ) + "RefGamma_sumet_CentralReg" );
      RefGamma_phi_CentralReg.SetName( ::TString( prefix ) + "RefGamma_phi_CentralReg" );
      RefGamma_etx_EndcapRegion.SetName( ::TString( prefix ) + "RefGamma_etx_EndcapRegion" );
      RefGamma_ety_EndcapRegion.SetName( ::TString( prefix ) + "RefGamma_ety_EndcapRegion" );
      RefGamma_sumet_EndcapRegion.SetName( ::TString( prefix ) + "RefGamma_sumet_EndcapRegion" );
      RefGamma_phi_EndcapRegion.SetName( ::TString( prefix ) + "RefGamma_phi_EndcapRegion" );
      RefGamma_etx_ForwardReg.SetName( ::TString( prefix ) + "RefGamma_etx_ForwardReg" );
      RefGamma_ety_ForwardReg.SetName( ::TString( prefix ) + "RefGamma_ety_ForwardReg" );
      RefGamma_sumet_ForwardReg.SetName( ::TString( prefix ) + "RefGamma_sumet_ForwardReg" );
      RefGamma_phi_ForwardReg.SetName( ::TString( prefix ) + "RefGamma_phi_ForwardReg" );
      STVF_RefGamma_etx.SetName( ::TString( prefix ) + "STVF_RefGamma_etx" );
      STVF_RefGamma_ety.SetName( ::TString( prefix ) + "STVF_RefGamma_ety" );
      STVF_RefGamma_sumet.SetName( ::TString( prefix ) + "STVF_RefGamma_sumet" );
      STVF_RefGamma_etx_CentralReg.SetName( ::TString( prefix ) + "STVF_RefGamma_etx_CentralReg" );
      STVF_RefGamma_ety_CentralReg.SetName( ::TString( prefix ) + "STVF_RefGamma_ety_CentralReg" );
      STVF_RefGamma_sumet_CentralReg.SetName( ::TString( prefix ) + "STVF_RefGamma_sumet_CentralReg" );
      STVF_RefGamma_phi_CentralReg.SetName( ::TString( prefix ) + "STVF_RefGamma_phi_CentralReg" );
      STVF_RefGamma_etx_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefGamma_etx_EndcapRegion" );
      STVF_RefGamma_ety_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefGamma_ety_EndcapRegion" );
      STVF_RefGamma_sumet_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefGamma_sumet_EndcapRegion" );
      STVF_RefGamma_phi_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefGamma_phi_EndcapRegion" );
      STVF_RefGamma_etx_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefGamma_etx_ForwardReg" );
      STVF_RefGamma_ety_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefGamma_ety_ForwardReg" );
      STVF_RefGamma_sumet_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefGamma_sumet_ForwardReg" );
      STVF_RefGamma_phi_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefGamma_phi_ForwardReg" );
      RefFinal_etx.SetName( ::TString( prefix ) + "RefFinal_etx" );
      RefFinal_ety.SetName( ::TString( prefix ) + "RefFinal_ety" );
      RefFinal_sumet.SetName( ::TString( prefix ) + "RefFinal_sumet" );
      RefFinal_etx_CentralReg.SetName( ::TString( prefix ) + "RefFinal_etx_CentralReg" );
      RefFinal_ety_CentralReg.SetName( ::TString( prefix ) + "RefFinal_ety_CentralReg" );
      RefFinal_sumet_CentralReg.SetName( ::TString( prefix ) + "RefFinal_sumet_CentralReg" );
      RefFinal_phi_CentralReg.SetName( ::TString( prefix ) + "RefFinal_phi_CentralReg" );
      RefFinal_etx_EndcapRegion.SetName( ::TString( prefix ) + "RefFinal_etx_EndcapRegion" );
      RefFinal_ety_EndcapRegion.SetName( ::TString( prefix ) + "RefFinal_ety_EndcapRegion" );
      RefFinal_sumet_EndcapRegion.SetName( ::TString( prefix ) + "RefFinal_sumet_EndcapRegion" );
      RefFinal_phi_EndcapRegion.SetName( ::TString( prefix ) + "RefFinal_phi_EndcapRegion" );
      RefFinal_etx_ForwardReg.SetName( ::TString( prefix ) + "RefFinal_etx_ForwardReg" );
      RefFinal_ety_ForwardReg.SetName( ::TString( prefix ) + "RefFinal_ety_ForwardReg" );
      RefFinal_sumet_ForwardReg.SetName( ::TString( prefix ) + "RefFinal_sumet_ForwardReg" );
      RefFinal_phi_ForwardReg.SetName( ::TString( prefix ) + "RefFinal_phi_ForwardReg" );
      STVF_RefFinal_etx.SetName( ::TString( prefix ) + "STVF_RefFinal_etx" );
      STVF_RefFinal_ety.SetName( ::TString( prefix ) + "STVF_RefFinal_ety" );
      STVF_RefFinal_sumet.SetName( ::TString( prefix ) + "STVF_RefFinal_sumet" );
      STVF_RefFinal_etx_CentralReg.SetName( ::TString( prefix ) + "STVF_RefFinal_etx_CentralReg" );
      STVF_RefFinal_ety_CentralReg.SetName( ::TString( prefix ) + "STVF_RefFinal_ety_CentralReg" );
      STVF_RefFinal_sumet_CentralReg.SetName( ::TString( prefix ) + "STVF_RefFinal_sumet_CentralReg" );
      STVF_RefFinal_phi_CentralReg.SetName( ::TString( prefix ) + "STVF_RefFinal_phi_CentralReg" );
      STVF_RefFinal_etx_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefFinal_etx_EndcapRegion" );
      STVF_RefFinal_ety_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefFinal_ety_EndcapRegion" );
      STVF_RefFinal_sumet_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefFinal_sumet_EndcapRegion" );
      STVF_RefFinal_phi_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefFinal_phi_EndcapRegion" );
      STVF_RefFinal_etx_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefFinal_etx_ForwardReg" );
      STVF_RefFinal_ety_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefFinal_ety_ForwardReg" );
      STVF_RefFinal_sumet_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefFinal_sumet_ForwardReg" );
      STVF_RefFinal_phi_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefFinal_phi_ForwardReg" );
      RefJet_etx.SetName( ::TString( prefix ) + "RefJet_etx" );
      RefJet_ety.SetName( ::TString( prefix ) + "RefJet_ety" );
      RefJet_sumet.SetName( ::TString( prefix ) + "RefJet_sumet" );
      RefJet_etx_CentralReg.SetName( ::TString( prefix ) + "RefJet_etx_CentralReg" );
      RefJet_ety_CentralReg.SetName( ::TString( prefix ) + "RefJet_ety_CentralReg" );
      RefJet_sumet_CentralReg.SetName( ::TString( prefix ) + "RefJet_sumet_CentralReg" );
      RefJet_phi_CentralReg.SetName( ::TString( prefix ) + "RefJet_phi_CentralReg" );
      RefJet_etx_EndcapRegion.SetName( ::TString( prefix ) + "RefJet_etx_EndcapRegion" );
      RefJet_ety_EndcapRegion.SetName( ::TString( prefix ) + "RefJet_ety_EndcapRegion" );
      RefJet_sumet_EndcapRegion.SetName( ::TString( prefix ) + "RefJet_sumet_EndcapRegion" );
      RefJet_phi_EndcapRegion.SetName( ::TString( prefix ) + "RefJet_phi_EndcapRegion" );
      RefJet_etx_ForwardReg.SetName( ::TString( prefix ) + "RefJet_etx_ForwardReg" );
      RefJet_ety_ForwardReg.SetName( ::TString( prefix ) + "RefJet_ety_ForwardReg" );
      RefJet_sumet_ForwardReg.SetName( ::TString( prefix ) + "RefJet_sumet_ForwardReg" );
      RefJet_phi_ForwardReg.SetName( ::TString( prefix ) + "RefJet_phi_ForwardReg" );
      STVF_RefJet_etx.SetName( ::TString( prefix ) + "STVF_RefJet_etx" );
      STVF_RefJet_ety.SetName( ::TString( prefix ) + "STVF_RefJet_ety" );
      STVF_RefJet_sumet.SetName( ::TString( prefix ) + "STVF_RefJet_sumet" );
      STVF_RefJet_etx_CentralReg.SetName( ::TString( prefix ) + "STVF_RefJet_etx_CentralReg" );
      STVF_RefJet_ety_CentralReg.SetName( ::TString( prefix ) + "STVF_RefJet_ety_CentralReg" );
      STVF_RefJet_sumet_CentralReg.SetName( ::TString( prefix ) + "STVF_RefJet_sumet_CentralReg" );
      STVF_RefJet_phi_CentralReg.SetName( ::TString( prefix ) + "STVF_RefJet_phi_CentralReg" );
      STVF_RefJet_etx_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefJet_etx_EndcapRegion" );
      STVF_RefJet_ety_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefJet_ety_EndcapRegion" );
      STVF_RefJet_sumet_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefJet_sumet_EndcapRegion" );
      STVF_RefJet_phi_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefJet_phi_EndcapRegion" );
      STVF_RefJet_etx_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefJet_etx_ForwardReg" );
      STVF_RefJet_ety_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefJet_ety_ForwardReg" );
      STVF_RefJet_sumet_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefJet_sumet_ForwardReg" );
      STVF_RefJet_phi_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefJet_phi_ForwardReg" );
      RefEle_etx.SetName( ::TString( prefix ) + "RefEle_etx" );
      RefEle_ety.SetName( ::TString( prefix ) + "RefEle_ety" );
      RefEle_sumet.SetName( ::TString( prefix ) + "RefEle_sumet" );
      RefEle_etx_CentralReg.SetName( ::TString( prefix ) + "RefEle_etx_CentralReg" );
      RefEle_ety_CentralReg.SetName( ::TString( prefix ) + "RefEle_ety_CentralReg" );
      RefEle_sumet_CentralReg.SetName( ::TString( prefix ) + "RefEle_sumet_CentralReg" );
      RefEle_phi_CentralReg.SetName( ::TString( prefix ) + "RefEle_phi_CentralReg" );
      RefEle_etx_EndcapRegion.SetName( ::TString( prefix ) + "RefEle_etx_EndcapRegion" );
      RefEle_ety_EndcapRegion.SetName( ::TString( prefix ) + "RefEle_ety_EndcapRegion" );
      RefEle_sumet_EndcapRegion.SetName( ::TString( prefix ) + "RefEle_sumet_EndcapRegion" );
      RefEle_phi_EndcapRegion.SetName( ::TString( prefix ) + "RefEle_phi_EndcapRegion" );
      RefEle_etx_ForwardReg.SetName( ::TString( prefix ) + "RefEle_etx_ForwardReg" );
      RefEle_ety_ForwardReg.SetName( ::TString( prefix ) + "RefEle_ety_ForwardReg" );
      RefEle_sumet_ForwardReg.SetName( ::TString( prefix ) + "RefEle_sumet_ForwardReg" );
      RefEle_phi_ForwardReg.SetName( ::TString( prefix ) + "RefEle_phi_ForwardReg" );
      STVF_RefEle_etx.SetName( ::TString( prefix ) + "STVF_RefEle_etx" );
      STVF_RefEle_ety.SetName( ::TString( prefix ) + "STVF_RefEle_ety" );
      STVF_RefEle_sumet.SetName( ::TString( prefix ) + "STVF_RefEle_sumet" );
      STVF_RefEle_etx_CentralReg.SetName( ::TString( prefix ) + "STVF_RefEle_etx_CentralReg" );
      STVF_RefEle_ety_CentralReg.SetName( ::TString( prefix ) + "STVF_RefEle_ety_CentralReg" );
      STVF_RefEle_sumet_CentralReg.SetName( ::TString( prefix ) + "STVF_RefEle_sumet_CentralReg" );
      STVF_RefEle_phi_CentralReg.SetName( ::TString( prefix ) + "STVF_RefEle_phi_CentralReg" );
      STVF_RefEle_etx_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefEle_etx_EndcapRegion" );
      STVF_RefEle_ety_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefEle_ety_EndcapRegion" );
      STVF_RefEle_sumet_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefEle_sumet_EndcapRegion" );
      STVF_RefEle_phi_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefEle_phi_EndcapRegion" );
      STVF_RefEle_etx_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefEle_etx_ForwardReg" );
      STVF_RefEle_ety_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefEle_ety_ForwardReg" );
      STVF_RefEle_sumet_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefEle_sumet_ForwardReg" );
      STVF_RefEle_phi_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefEle_phi_ForwardReg" );
      Muon_Total_Staco_etx.SetName( ::TString( prefix ) + "Muon_Total_Staco_etx" );
      Muon_Total_Staco_ety.SetName( ::TString( prefix ) + "Muon_Total_Staco_ety" );
      Muon_Total_Staco_sumet.SetName( ::TString( prefix ) + "Muon_Total_Staco_sumet" );
      Muon_Total_Staco_etx_CentralReg.SetName( ::TString( prefix ) + "Muon_Total_Staco_etx_CentralReg" );
      Muon_Total_Staco_ety_CentralReg.SetName( ::TString( prefix ) + "Muon_Total_Staco_ety_CentralReg" );
      Muon_Total_Staco_sumet_CentralReg.SetName( ::TString( prefix ) + "Muon_Total_Staco_sumet_CentralReg" );
      Muon_Total_Staco_phi_CentralReg.SetName( ::TString( prefix ) + "Muon_Total_Staco_phi_CentralReg" );
      Muon_Total_Staco_etx_EndcapRegion.SetName( ::TString( prefix ) + "Muon_Total_Staco_etx_EndcapRegion" );
      Muon_Total_Staco_ety_EndcapRegion.SetName( ::TString( prefix ) + "Muon_Total_Staco_ety_EndcapRegion" );
      Muon_Total_Staco_sumet_EndcapRegion.SetName( ::TString( prefix ) + "Muon_Total_Staco_sumet_EndcapRegion" );
      Muon_Total_Staco_phi_EndcapRegion.SetName( ::TString( prefix ) + "Muon_Total_Staco_phi_EndcapRegion" );
      Muon_Total_Staco_etx_ForwardReg.SetName( ::TString( prefix ) + "Muon_Total_Staco_etx_ForwardReg" );
      Muon_Total_Staco_ety_ForwardReg.SetName( ::TString( prefix ) + "Muon_Total_Staco_ety_ForwardReg" );
      Muon_Total_Staco_sumet_ForwardReg.SetName( ::TString( prefix ) + "Muon_Total_Staco_sumet_ForwardReg" );
      Muon_Total_Staco_phi_ForwardReg.SetName( ::TString( prefix ) + "Muon_Total_Staco_phi_ForwardReg" );
      STVF_Muon_Total_Staco_etx.SetName( ::TString( prefix ) + "STVF_Muon_Total_Staco_etx" );
      STVF_Muon_Total_Staco_ety.SetName( ::TString( prefix ) + "STVF_Muon_Total_Staco_ety" );
      STVF_Muon_Total_Staco_sumet.SetName( ::TString( prefix ) + "STVF_Muon_Total_Staco_sumet" );
      STVF_Muon_Total_Staco_etx_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_Total_Staco_etx_CentralReg" );
      STVF_Muon_Total_Staco_ety_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_Total_Staco_ety_CentralReg" );
      STVF_Muon_Total_Staco_sumet_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_Total_Staco_sumet_CentralReg" );
      STVF_Muon_Total_Staco_phi_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_Total_Staco_phi_CentralReg" );
      STVF_Muon_Total_Staco_etx_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_Total_Staco_etx_EndcapRegion" );
      STVF_Muon_Total_Staco_ety_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_Total_Staco_ety_EndcapRegion" );
      STVF_Muon_Total_Staco_sumet_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_Total_Staco_sumet_EndcapRegion" );
      STVF_Muon_Total_Staco_phi_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_Total_Staco_phi_EndcapRegion" );
      STVF_Muon_Total_Staco_etx_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_Total_Staco_etx_ForwardReg" );
      STVF_Muon_Total_Staco_ety_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_Total_Staco_ety_ForwardReg" );
      STVF_Muon_Total_Staco_sumet_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_Total_Staco_sumet_ForwardReg" );
      STVF_Muon_Total_Staco_phi_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_Total_Staco_phi_ForwardReg" );
      Muon_Isol_Staco_etx.SetName( ::TString( prefix ) + "Muon_Isol_Staco_etx" );
      Muon_Isol_Staco_ety.SetName( ::TString( prefix ) + "Muon_Isol_Staco_ety" );
      Muon_Isol_Staco_sumet.SetName( ::TString( prefix ) + "Muon_Isol_Staco_sumet" );
      Muon_Isol_Staco_etx_CentralReg.SetName( ::TString( prefix ) + "Muon_Isol_Staco_etx_CentralReg" );
      Muon_Isol_Staco_ety_CentralReg.SetName( ::TString( prefix ) + "Muon_Isol_Staco_ety_CentralReg" );
      Muon_Isol_Staco_sumet_CentralReg.SetName( ::TString( prefix ) + "Muon_Isol_Staco_sumet_CentralReg" );
      Muon_Isol_Staco_phi_CentralReg.SetName( ::TString( prefix ) + "Muon_Isol_Staco_phi_CentralReg" );
      Muon_Isol_Staco_etx_EndcapRegion.SetName( ::TString( prefix ) + "Muon_Isol_Staco_etx_EndcapRegion" );
      Muon_Isol_Staco_ety_EndcapRegion.SetName( ::TString( prefix ) + "Muon_Isol_Staco_ety_EndcapRegion" );
      Muon_Isol_Staco_sumet_EndcapRegion.SetName( ::TString( prefix ) + "Muon_Isol_Staco_sumet_EndcapRegion" );
      Muon_Isol_Staco_phi_EndcapRegion.SetName( ::TString( prefix ) + "Muon_Isol_Staco_phi_EndcapRegion" );
      Muon_Isol_Staco_etx_ForwardReg.SetName( ::TString( prefix ) + "Muon_Isol_Staco_etx_ForwardReg" );
      Muon_Isol_Staco_ety_ForwardReg.SetName( ::TString( prefix ) + "Muon_Isol_Staco_ety_ForwardReg" );
      Muon_Isol_Staco_sumet_ForwardReg.SetName( ::TString( prefix ) + "Muon_Isol_Staco_sumet_ForwardReg" );
      Muon_Isol_Staco_phi_ForwardReg.SetName( ::TString( prefix ) + "Muon_Isol_Staco_phi_ForwardReg" );
      STVF_Muon_Isol_Staco_etx.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Staco_etx" );
      STVF_Muon_Isol_Staco_ety.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Staco_ety" );
      STVF_Muon_Isol_Staco_sumet.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Staco_sumet" );
      STVF_Muon_Isol_Staco_etx_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Staco_etx_CentralReg" );
      STVF_Muon_Isol_Staco_ety_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Staco_ety_CentralReg" );
      STVF_Muon_Isol_Staco_sumet_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Staco_sumet_CentralReg" );
      STVF_Muon_Isol_Staco_phi_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Staco_phi_CentralReg" );
      STVF_Muon_Isol_Staco_etx_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Staco_etx_EndcapRegion" );
      STVF_Muon_Isol_Staco_ety_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Staco_ety_EndcapRegion" );
      STVF_Muon_Isol_Staco_sumet_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Staco_sumet_EndcapRegion" );
      STVF_Muon_Isol_Staco_phi_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Staco_phi_EndcapRegion" );
      STVF_Muon_Isol_Staco_etx_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Staco_etx_ForwardReg" );
      STVF_Muon_Isol_Staco_ety_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Staco_ety_ForwardReg" );
      STVF_Muon_Isol_Staco_sumet_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Staco_sumet_ForwardReg" );
      STVF_Muon_Isol_Staco_phi_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Staco_phi_ForwardReg" );
      Muon_NonIsol_Staco_etx.SetName( ::TString( prefix ) + "Muon_NonIsol_Staco_etx" );
      Muon_NonIsol_Staco_ety.SetName( ::TString( prefix ) + "Muon_NonIsol_Staco_ety" );
      Muon_NonIsol_Staco_sumet.SetName( ::TString( prefix ) + "Muon_NonIsol_Staco_sumet" );
      Muon_NonIsol_Staco_etx_CentralReg.SetName( ::TString( prefix ) + "Muon_NonIsol_Staco_etx_CentralReg" );
      Muon_NonIsol_Staco_ety_CentralReg.SetName( ::TString( prefix ) + "Muon_NonIsol_Staco_ety_CentralReg" );
      Muon_NonIsol_Staco_sumet_CentralReg.SetName( ::TString( prefix ) + "Muon_NonIsol_Staco_sumet_CentralReg" );
      Muon_NonIsol_Staco_phi_CentralReg.SetName( ::TString( prefix ) + "Muon_NonIsol_Staco_phi_CentralReg" );
      Muon_NonIsol_Staco_etx_EndcapRegion.SetName( ::TString( prefix ) + "Muon_NonIsol_Staco_etx_EndcapRegion" );
      Muon_NonIsol_Staco_ety_EndcapRegion.SetName( ::TString( prefix ) + "Muon_NonIsol_Staco_ety_EndcapRegion" );
      Muon_NonIsol_Staco_sumet_EndcapRegion.SetName( ::TString( prefix ) + "Muon_NonIsol_Staco_sumet_EndcapRegion" );
      Muon_NonIsol_Staco_phi_EndcapRegion.SetName( ::TString( prefix ) + "Muon_NonIsol_Staco_phi_EndcapRegion" );
      Muon_NonIsol_Staco_etx_ForwardReg.SetName( ::TString( prefix ) + "Muon_NonIsol_Staco_etx_ForwardReg" );
      Muon_NonIsol_Staco_ety_ForwardReg.SetName( ::TString( prefix ) + "Muon_NonIsol_Staco_ety_ForwardReg" );
      Muon_NonIsol_Staco_sumet_ForwardReg.SetName( ::TString( prefix ) + "Muon_NonIsol_Staco_sumet_ForwardReg" );
      Muon_NonIsol_Staco_phi_ForwardReg.SetName( ::TString( prefix ) + "Muon_NonIsol_Staco_phi_ForwardReg" );
      STVF_Muon_NonIsol_Staco_etx.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_etx" );
      STVF_Muon_NonIsol_Staco_ety.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_ety" );
      STVF_Muon_NonIsol_Staco_sumet.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_sumet" );
      STVF_Muon_NonIsol_Staco_etx_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_etx_CentralReg" );
      STVF_Muon_NonIsol_Staco_ety_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_ety_CentralReg" );
      STVF_Muon_NonIsol_Staco_sumet_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_sumet_CentralReg" );
      STVF_Muon_NonIsol_Staco_phi_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_phi_CentralReg" );
      STVF_Muon_NonIsol_Staco_etx_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_etx_EndcapRegion" );
      STVF_Muon_NonIsol_Staco_ety_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_ety_EndcapRegion" );
      STVF_Muon_NonIsol_Staco_sumet_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_sumet_EndcapRegion" );
      STVF_Muon_NonIsol_Staco_phi_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_phi_EndcapRegion" );
      STVF_Muon_NonIsol_Staco_etx_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_etx_ForwardReg" );
      STVF_Muon_NonIsol_Staco_ety_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_ety_ForwardReg" );
      STVF_Muon_NonIsol_Staco_sumet_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_sumet_ForwardReg" );
      STVF_Muon_NonIsol_Staco_phi_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Staco_phi_ForwardReg" );
      CellOut_etx.SetName( ::TString( prefix ) + "CellOut_etx" );
      CellOut_ety.SetName( ::TString( prefix ) + "CellOut_ety" );
      CellOut_sumet.SetName( ::TString( prefix ) + "CellOut_sumet" );
      CellOut_etx_CentralReg.SetName( ::TString( prefix ) + "CellOut_etx_CentralReg" );
      CellOut_ety_CentralReg.SetName( ::TString( prefix ) + "CellOut_ety_CentralReg" );
      CellOut_sumet_CentralReg.SetName( ::TString( prefix ) + "CellOut_sumet_CentralReg" );
      CellOut_phi_CentralReg.SetName( ::TString( prefix ) + "CellOut_phi_CentralReg" );
      CellOut_etx_EndcapRegion.SetName( ::TString( prefix ) + "CellOut_etx_EndcapRegion" );
      CellOut_ety_EndcapRegion.SetName( ::TString( prefix ) + "CellOut_ety_EndcapRegion" );
      CellOut_sumet_EndcapRegion.SetName( ::TString( prefix ) + "CellOut_sumet_EndcapRegion" );
      CellOut_phi_EndcapRegion.SetName( ::TString( prefix ) + "CellOut_phi_EndcapRegion" );
      CellOut_etx_ForwardReg.SetName( ::TString( prefix ) + "CellOut_etx_ForwardReg" );
      CellOut_ety_ForwardReg.SetName( ::TString( prefix ) + "CellOut_ety_ForwardReg" );
      CellOut_sumet_ForwardReg.SetName( ::TString( prefix ) + "CellOut_sumet_ForwardReg" );
      CellOut_phi_ForwardReg.SetName( ::TString( prefix ) + "CellOut_phi_ForwardReg" );
      STVF_CellOut_etx.SetName( ::TString( prefix ) + "STVF_CellOut_etx" );
      STVF_CellOut_ety.SetName( ::TString( prefix ) + "STVF_CellOut_ety" );
      STVF_CellOut_sumet.SetName( ::TString( prefix ) + "STVF_CellOut_sumet" );
      STVF_CellOut_etx_CentralReg.SetName( ::TString( prefix ) + "STVF_CellOut_etx_CentralReg" );
      STVF_CellOut_ety_CentralReg.SetName( ::TString( prefix ) + "STVF_CellOut_ety_CentralReg" );
      STVF_CellOut_sumet_CentralReg.SetName( ::TString( prefix ) + "STVF_CellOut_sumet_CentralReg" );
      STVF_CellOut_phi_CentralReg.SetName( ::TString( prefix ) + "STVF_CellOut_phi_CentralReg" );
      STVF_CellOut_etx_EndcapRegion.SetName( ::TString( prefix ) + "STVF_CellOut_etx_EndcapRegion" );
      STVF_CellOut_ety_EndcapRegion.SetName( ::TString( prefix ) + "STVF_CellOut_ety_EndcapRegion" );
      STVF_CellOut_sumet_EndcapRegion.SetName( ::TString( prefix ) + "STVF_CellOut_sumet_EndcapRegion" );
      STVF_CellOut_phi_EndcapRegion.SetName( ::TString( prefix ) + "STVF_CellOut_phi_EndcapRegion" );
      STVF_CellOut_etx_ForwardReg.SetName( ::TString( prefix ) + "STVF_CellOut_etx_ForwardReg" );
      STVF_CellOut_ety_ForwardReg.SetName( ::TString( prefix ) + "STVF_CellOut_ety_ForwardReg" );
      STVF_CellOut_sumet_ForwardReg.SetName( ::TString( prefix ) + "STVF_CellOut_sumet_ForwardReg" );
      STVF_CellOut_phi_ForwardReg.SetName( ::TString( prefix ) + "STVF_CellOut_phi_ForwardReg" );
      Muon_Isol_Muid_etx.SetName( ::TString( prefix ) + "Muon_Isol_Muid_etx" );
      Muon_Isol_Muid_ety.SetName( ::TString( prefix ) + "Muon_Isol_Muid_ety" );
      Muon_Isol_Muid_sumet.SetName( ::TString( prefix ) + "Muon_Isol_Muid_sumet" );
      Muon_Isol_Muid_etx_CentralReg.SetName( ::TString( prefix ) + "Muon_Isol_Muid_etx_CentralReg" );
      Muon_Isol_Muid_ety_CentralReg.SetName( ::TString( prefix ) + "Muon_Isol_Muid_ety_CentralReg" );
      Muon_Isol_Muid_sumet_CentralReg.SetName( ::TString( prefix ) + "Muon_Isol_Muid_sumet_CentralReg" );
      Muon_Isol_Muid_phi_CentralReg.SetName( ::TString( prefix ) + "Muon_Isol_Muid_phi_CentralReg" );
      Muon_Isol_Muid_etx_EndcapRegion.SetName( ::TString( prefix ) + "Muon_Isol_Muid_etx_EndcapRegion" );
      Muon_Isol_Muid_ety_EndcapRegion.SetName( ::TString( prefix ) + "Muon_Isol_Muid_ety_EndcapRegion" );
      Muon_Isol_Muid_sumet_EndcapRegion.SetName( ::TString( prefix ) + "Muon_Isol_Muid_sumet_EndcapRegion" );
      Muon_Isol_Muid_phi_EndcapRegion.SetName( ::TString( prefix ) + "Muon_Isol_Muid_phi_EndcapRegion" );
      Muon_Isol_Muid_etx_ForwardReg.SetName( ::TString( prefix ) + "Muon_Isol_Muid_etx_ForwardReg" );
      Muon_Isol_Muid_ety_ForwardReg.SetName( ::TString( prefix ) + "Muon_Isol_Muid_ety_ForwardReg" );
      Muon_Isol_Muid_sumet_ForwardReg.SetName( ::TString( prefix ) + "Muon_Isol_Muid_sumet_ForwardReg" );
      Muon_Isol_Muid_phi_ForwardReg.SetName( ::TString( prefix ) + "Muon_Isol_Muid_phi_ForwardReg" );
      STVF_Muon_Isol_Muid_etx.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Muid_etx" );
      STVF_Muon_Isol_Muid_ety.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Muid_ety" );
      STVF_Muon_Isol_Muid_sumet.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Muid_sumet" );
      STVF_Muon_Isol_Muid_etx_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Muid_etx_CentralReg" );
      STVF_Muon_Isol_Muid_ety_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Muid_ety_CentralReg" );
      STVF_Muon_Isol_Muid_sumet_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Muid_sumet_CentralReg" );
      STVF_Muon_Isol_Muid_phi_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Muid_phi_CentralReg" );
      STVF_Muon_Isol_Muid_etx_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Muid_etx_EndcapRegion" );
      STVF_Muon_Isol_Muid_ety_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Muid_ety_EndcapRegion" );
      STVF_Muon_Isol_Muid_sumet_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Muid_sumet_EndcapRegion" );
      STVF_Muon_Isol_Muid_phi_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Muid_phi_EndcapRegion" );
      STVF_Muon_Isol_Muid_etx_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Muid_etx_ForwardReg" );
      STVF_Muon_Isol_Muid_ety_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Muid_ety_ForwardReg" );
      STVF_Muon_Isol_Muid_sumet_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Muid_sumet_ForwardReg" );
      STVF_Muon_Isol_Muid_phi_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_Isol_Muid_phi_ForwardReg" );
      Muon_NonIsol_Muid_etx.SetName( ::TString( prefix ) + "Muon_NonIsol_Muid_etx" );
      Muon_NonIsol_Muid_ety.SetName( ::TString( prefix ) + "Muon_NonIsol_Muid_ety" );
      Muon_NonIsol_Muid_sumet.SetName( ::TString( prefix ) + "Muon_NonIsol_Muid_sumet" );
      Muon_NonIsol_Muid_etx_CentralReg.SetName( ::TString( prefix ) + "Muon_NonIsol_Muid_etx_CentralReg" );
      Muon_NonIsol_Muid_ety_CentralReg.SetName( ::TString( prefix ) + "Muon_NonIsol_Muid_ety_CentralReg" );
      Muon_NonIsol_Muid_sumet_CentralReg.SetName( ::TString( prefix ) + "Muon_NonIsol_Muid_sumet_CentralReg" );
      Muon_NonIsol_Muid_phi_CentralReg.SetName( ::TString( prefix ) + "Muon_NonIsol_Muid_phi_CentralReg" );
      Muon_NonIsol_Muid_etx_EndcapRegion.SetName( ::TString( prefix ) + "Muon_NonIsol_Muid_etx_EndcapRegion" );
      Muon_NonIsol_Muid_ety_EndcapRegion.SetName( ::TString( prefix ) + "Muon_NonIsol_Muid_ety_EndcapRegion" );
      Muon_NonIsol_Muid_sumet_EndcapRegion.SetName( ::TString( prefix ) + "Muon_NonIsol_Muid_sumet_EndcapRegion" );
      Muon_NonIsol_Muid_phi_EndcapRegion.SetName( ::TString( prefix ) + "Muon_NonIsol_Muid_phi_EndcapRegion" );
      Muon_NonIsol_Muid_etx_ForwardReg.SetName( ::TString( prefix ) + "Muon_NonIsol_Muid_etx_ForwardReg" );
      Muon_NonIsol_Muid_ety_ForwardReg.SetName( ::TString( prefix ) + "Muon_NonIsol_Muid_ety_ForwardReg" );
      Muon_NonIsol_Muid_sumet_ForwardReg.SetName( ::TString( prefix ) + "Muon_NonIsol_Muid_sumet_ForwardReg" );
      Muon_NonIsol_Muid_phi_ForwardReg.SetName( ::TString( prefix ) + "Muon_NonIsol_Muid_phi_ForwardReg" );
      STVF_Muon_NonIsol_Muid_etx.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_etx" );
      STVF_Muon_NonIsol_Muid_ety.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_ety" );
      STVF_Muon_NonIsol_Muid_sumet.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_sumet" );
      STVF_Muon_NonIsol_Muid_etx_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_etx_CentralReg" );
      STVF_Muon_NonIsol_Muid_ety_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_ety_CentralReg" );
      STVF_Muon_NonIsol_Muid_sumet_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_sumet_CentralReg" );
      STVF_Muon_NonIsol_Muid_phi_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_phi_CentralReg" );
      STVF_Muon_NonIsol_Muid_etx_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_etx_EndcapRegion" );
      STVF_Muon_NonIsol_Muid_ety_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_ety_EndcapRegion" );
      STVF_Muon_NonIsol_Muid_sumet_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_sumet_EndcapRegion" );
      STVF_Muon_NonIsol_Muid_phi_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_phi_EndcapRegion" );
      STVF_Muon_NonIsol_Muid_etx_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_etx_ForwardReg" );
      STVF_Muon_NonIsol_Muid_ety_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_ety_ForwardReg" );
      STVF_Muon_NonIsol_Muid_sumet_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_sumet_ForwardReg" );
      STVF_Muon_NonIsol_Muid_phi_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_NonIsol_Muid_phi_ForwardReg" );
      Muon_Total_Muid_etx.SetName( ::TString( prefix ) + "Muon_Total_Muid_etx" );
      Muon_Total_Muid_ety.SetName( ::TString( prefix ) + "Muon_Total_Muid_ety" );
      Muon_Total_Muid_sumet.SetName( ::TString( prefix ) + "Muon_Total_Muid_sumet" );
      Muon_Total_Muid_etx_CentralReg.SetName( ::TString( prefix ) + "Muon_Total_Muid_etx_CentralReg" );
      Muon_Total_Muid_ety_CentralReg.SetName( ::TString( prefix ) + "Muon_Total_Muid_ety_CentralReg" );
      Muon_Total_Muid_sumet_CentralReg.SetName( ::TString( prefix ) + "Muon_Total_Muid_sumet_CentralReg" );
      Muon_Total_Muid_phi_CentralReg.SetName( ::TString( prefix ) + "Muon_Total_Muid_phi_CentralReg" );
      Muon_Total_Muid_etx_EndcapRegion.SetName( ::TString( prefix ) + "Muon_Total_Muid_etx_EndcapRegion" );
      Muon_Total_Muid_ety_EndcapRegion.SetName( ::TString( prefix ) + "Muon_Total_Muid_ety_EndcapRegion" );
      Muon_Total_Muid_sumet_EndcapRegion.SetName( ::TString( prefix ) + "Muon_Total_Muid_sumet_EndcapRegion" );
      Muon_Total_Muid_phi_EndcapRegion.SetName( ::TString( prefix ) + "Muon_Total_Muid_phi_EndcapRegion" );
      Muon_Total_Muid_etx_ForwardReg.SetName( ::TString( prefix ) + "Muon_Total_Muid_etx_ForwardReg" );
      Muon_Total_Muid_ety_ForwardReg.SetName( ::TString( prefix ) + "Muon_Total_Muid_ety_ForwardReg" );
      Muon_Total_Muid_sumet_ForwardReg.SetName( ::TString( prefix ) + "Muon_Total_Muid_sumet_ForwardReg" );
      Muon_Total_Muid_phi_ForwardReg.SetName( ::TString( prefix ) + "Muon_Total_Muid_phi_ForwardReg" );
      STVF_Muon_Total_Muid_etx.SetName( ::TString( prefix ) + "STVF_Muon_Total_Muid_etx" );
      STVF_Muon_Total_Muid_ety.SetName( ::TString( prefix ) + "STVF_Muon_Total_Muid_ety" );
      STVF_Muon_Total_Muid_sumet.SetName( ::TString( prefix ) + "STVF_Muon_Total_Muid_sumet" );
      STVF_Muon_Total_Muid_etx_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_Total_Muid_etx_CentralReg" );
      STVF_Muon_Total_Muid_ety_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_Total_Muid_ety_CentralReg" );
      STVF_Muon_Total_Muid_sumet_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_Total_Muid_sumet_CentralReg" );
      STVF_Muon_Total_Muid_phi_CentralReg.SetName( ::TString( prefix ) + "STVF_Muon_Total_Muid_phi_CentralReg" );
      STVF_Muon_Total_Muid_etx_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_Total_Muid_etx_EndcapRegion" );
      STVF_Muon_Total_Muid_ety_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_Total_Muid_ety_EndcapRegion" );
      STVF_Muon_Total_Muid_sumet_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_Total_Muid_sumet_EndcapRegion" );
      STVF_Muon_Total_Muid_phi_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Muon_Total_Muid_phi_EndcapRegion" );
      STVF_Muon_Total_Muid_etx_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_Total_Muid_etx_ForwardReg" );
      STVF_Muon_Total_Muid_ety_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_Total_Muid_ety_ForwardReg" );
      STVF_Muon_Total_Muid_sumet_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_Total_Muid_sumet_ForwardReg" );
      STVF_Muon_Total_Muid_phi_ForwardReg.SetName( ::TString( prefix ) + "STVF_Muon_Total_Muid_phi_ForwardReg" );
      Track_etx.SetName( ::TString( prefix ) + "Track_etx" );
      Track_ety.SetName( ::TString( prefix ) + "Track_ety" );
      Track_sumet.SetName( ::TString( prefix ) + "Track_sumet" );
      Track_etx_CentralReg.SetName( ::TString( prefix ) + "Track_etx_CentralReg" );
      Track_ety_CentralReg.SetName( ::TString( prefix ) + "Track_ety_CentralReg" );
      Track_sumet_CentralReg.SetName( ::TString( prefix ) + "Track_sumet_CentralReg" );
      Track_phi_CentralReg.SetName( ::TString( prefix ) + "Track_phi_CentralReg" );
      Track_etx_EndcapRegion.SetName( ::TString( prefix ) + "Track_etx_EndcapRegion" );
      Track_ety_EndcapRegion.SetName( ::TString( prefix ) + "Track_ety_EndcapRegion" );
      Track_sumet_EndcapRegion.SetName( ::TString( prefix ) + "Track_sumet_EndcapRegion" );
      Track_phi_EndcapRegion.SetName( ::TString( prefix ) + "Track_phi_EndcapRegion" );
      Track_etx_ForwardReg.SetName( ::TString( prefix ) + "Track_etx_ForwardReg" );
      Track_ety_ForwardReg.SetName( ::TString( prefix ) + "Track_ety_ForwardReg" );
      Track_sumet_ForwardReg.SetName( ::TString( prefix ) + "Track_sumet_ForwardReg" );
      Track_phi_ForwardReg.SetName( ::TString( prefix ) + "Track_phi_ForwardReg" );
      STVF_Track_etx.SetName( ::TString( prefix ) + "STVF_Track_etx" );
      STVF_Track_ety.SetName( ::TString( prefix ) + "STVF_Track_ety" );
      STVF_Track_sumet.SetName( ::TString( prefix ) + "STVF_Track_sumet" );
      STVF_Track_etx_CentralReg.SetName( ::TString( prefix ) + "STVF_Track_etx_CentralReg" );
      STVF_Track_ety_CentralReg.SetName( ::TString( prefix ) + "STVF_Track_ety_CentralReg" );
      STVF_Track_sumet_CentralReg.SetName( ::TString( prefix ) + "STVF_Track_sumet_CentralReg" );
      STVF_Track_phi_CentralReg.SetName( ::TString( prefix ) + "STVF_Track_phi_CentralReg" );
      STVF_Track_etx_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Track_etx_EndcapRegion" );
      STVF_Track_ety_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Track_ety_EndcapRegion" );
      STVF_Track_sumet_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Track_sumet_EndcapRegion" );
      STVF_Track_phi_EndcapRegion.SetName( ::TString( prefix ) + "STVF_Track_phi_EndcapRegion" );
      STVF_Track_etx_ForwardReg.SetName( ::TString( prefix ) + "STVF_Track_etx_ForwardReg" );
      STVF_Track_ety_ForwardReg.SetName( ::TString( prefix ) + "STVF_Track_ety_ForwardReg" );
      STVF_Track_sumet_ForwardReg.SetName( ::TString( prefix ) + "STVF_Track_sumet_ForwardReg" );
      STVF_Track_phi_ForwardReg.SetName( ::TString( prefix ) + "STVF_Track_phi_ForwardReg" );
      SoftJets_etx.SetName( ::TString( prefix ) + "SoftJets_etx" );
      SoftJets_ety.SetName( ::TString( prefix ) + "SoftJets_ety" );
      SoftJets_sumet.SetName( ::TString( prefix ) + "SoftJets_sumet" );
      SoftJets_etx_CentralReg.SetName( ::TString( prefix ) + "SoftJets_etx_CentralReg" );
      SoftJets_ety_CentralReg.SetName( ::TString( prefix ) + "SoftJets_ety_CentralReg" );
      SoftJets_sumet_CentralReg.SetName( ::TString( prefix ) + "SoftJets_sumet_CentralReg" );
      SoftJets_phi_CentralReg.SetName( ::TString( prefix ) + "SoftJets_phi_CentralReg" );
      SoftJets_etx_EndcapRegion.SetName( ::TString( prefix ) + "SoftJets_etx_EndcapRegion" );
      SoftJets_ety_EndcapRegion.SetName( ::TString( prefix ) + "SoftJets_ety_EndcapRegion" );
      SoftJets_sumet_EndcapRegion.SetName( ::TString( prefix ) + "SoftJets_sumet_EndcapRegion" );
      SoftJets_phi_EndcapRegion.SetName( ::TString( prefix ) + "SoftJets_phi_EndcapRegion" );
      SoftJets_etx_ForwardReg.SetName( ::TString( prefix ) + "SoftJets_etx_ForwardReg" );
      SoftJets_ety_ForwardReg.SetName( ::TString( prefix ) + "SoftJets_ety_ForwardReg" );
      SoftJets_sumet_ForwardReg.SetName( ::TString( prefix ) + "SoftJets_sumet_ForwardReg" );
      SoftJets_phi_ForwardReg.SetName( ::TString( prefix ) + "SoftJets_phi_ForwardReg" );
      STVF_SoftJets_etx.SetName( ::TString( prefix ) + "STVF_SoftJets_etx" );
      STVF_SoftJets_ety.SetName( ::TString( prefix ) + "STVF_SoftJets_ety" );
      STVF_SoftJets_sumet.SetName( ::TString( prefix ) + "STVF_SoftJets_sumet" );
      STVF_SoftJets_etx_CentralReg.SetName( ::TString( prefix ) + "STVF_SoftJets_etx_CentralReg" );
      STVF_SoftJets_ety_CentralReg.SetName( ::TString( prefix ) + "STVF_SoftJets_ety_CentralReg" );
      STVF_SoftJets_sumet_CentralReg.SetName( ::TString( prefix ) + "STVF_SoftJets_sumet_CentralReg" );
      STVF_SoftJets_phi_CentralReg.SetName( ::TString( prefix ) + "STVF_SoftJets_phi_CentralReg" );
      STVF_SoftJets_etx_EndcapRegion.SetName( ::TString( prefix ) + "STVF_SoftJets_etx_EndcapRegion" );
      STVF_SoftJets_ety_EndcapRegion.SetName( ::TString( prefix ) + "STVF_SoftJets_ety_EndcapRegion" );
      STVF_SoftJets_sumet_EndcapRegion.SetName( ::TString( prefix ) + "STVF_SoftJets_sumet_EndcapRegion" );
      STVF_SoftJets_phi_EndcapRegion.SetName( ::TString( prefix ) + "STVF_SoftJets_phi_EndcapRegion" );
      STVF_SoftJets_etx_ForwardReg.SetName( ::TString( prefix ) + "STVF_SoftJets_etx_ForwardReg" );
      STVF_SoftJets_ety_ForwardReg.SetName( ::TString( prefix ) + "STVF_SoftJets_ety_ForwardReg" );
      STVF_SoftJets_sumet_ForwardReg.SetName( ::TString( prefix ) + "STVF_SoftJets_sumet_ForwardReg" );
      STVF_SoftJets_phi_ForwardReg.SetName( ::TString( prefix ) + "STVF_SoftJets_phi_ForwardReg" );
      RefMuon_etx.SetName( ::TString( prefix ) + "RefMuon_etx" );
      RefMuon_ety.SetName( ::TString( prefix ) + "RefMuon_ety" );
      RefMuon_sumet.SetName( ::TString( prefix ) + "RefMuon_sumet" );
      RefMuon_etx_CentralReg.SetName( ::TString( prefix ) + "RefMuon_etx_CentralReg" );
      RefMuon_ety_CentralReg.SetName( ::TString( prefix ) + "RefMuon_ety_CentralReg" );
      RefMuon_sumet_CentralReg.SetName( ::TString( prefix ) + "RefMuon_sumet_CentralReg" );
      RefMuon_phi_CentralReg.SetName( ::TString( prefix ) + "RefMuon_phi_CentralReg" );
      RefMuon_etx_EndcapRegion.SetName( ::TString( prefix ) + "RefMuon_etx_EndcapRegion" );
      RefMuon_ety_EndcapRegion.SetName( ::TString( prefix ) + "RefMuon_ety_EndcapRegion" );
      RefMuon_sumet_EndcapRegion.SetName( ::TString( prefix ) + "RefMuon_sumet_EndcapRegion" );
      RefMuon_phi_EndcapRegion.SetName( ::TString( prefix ) + "RefMuon_phi_EndcapRegion" );
      RefMuon_etx_ForwardReg.SetName( ::TString( prefix ) + "RefMuon_etx_ForwardReg" );
      RefMuon_ety_ForwardReg.SetName( ::TString( prefix ) + "RefMuon_ety_ForwardReg" );
      RefMuon_sumet_ForwardReg.SetName( ::TString( prefix ) + "RefMuon_sumet_ForwardReg" );
      RefMuon_phi_ForwardReg.SetName( ::TString( prefix ) + "RefMuon_phi_ForwardReg" );
      STVF_RefMuon_etx.SetName( ::TString( prefix ) + "STVF_RefMuon_etx" );
      STVF_RefMuon_ety.SetName( ::TString( prefix ) + "STVF_RefMuon_ety" );
      STVF_RefMuon_sumet.SetName( ::TString( prefix ) + "STVF_RefMuon_sumet" );
      STVF_RefMuon_etx_CentralReg.SetName( ::TString( prefix ) + "STVF_RefMuon_etx_CentralReg" );
      STVF_RefMuon_ety_CentralReg.SetName( ::TString( prefix ) + "STVF_RefMuon_ety_CentralReg" );
      STVF_RefMuon_sumet_CentralReg.SetName( ::TString( prefix ) + "STVF_RefMuon_sumet_CentralReg" );
      STVF_RefMuon_phi_CentralReg.SetName( ::TString( prefix ) + "STVF_RefMuon_phi_CentralReg" );
      STVF_RefMuon_etx_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefMuon_etx_EndcapRegion" );
      STVF_RefMuon_ety_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefMuon_ety_EndcapRegion" );
      STVF_RefMuon_sumet_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefMuon_sumet_EndcapRegion" );
      STVF_RefMuon_phi_EndcapRegion.SetName( ::TString( prefix ) + "STVF_RefMuon_phi_EndcapRegion" );
      STVF_RefMuon_etx_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefMuon_etx_ForwardReg" );
      STVF_RefMuon_ety_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefMuon_ety_ForwardReg" );
      STVF_RefMuon_sumet_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefMuon_sumet_ForwardReg" );
      STVF_RefMuon_phi_ForwardReg.SetName( ::TString( prefix ) + "STVF_RefMuon_phi_ForwardReg" );
      MuonBoy_etx.SetName( ::TString( prefix ) + "MuonBoy_etx" );
      MuonBoy_ety.SetName( ::TString( prefix ) + "MuonBoy_ety" );
      MuonBoy_sumet.SetName( ::TString( prefix ) + "MuonBoy_sumet" );
      MuonBoy_etx_CentralReg.SetName( ::TString( prefix ) + "MuonBoy_etx_CentralReg" );
      MuonBoy_ety_CentralReg.SetName( ::TString( prefix ) + "MuonBoy_ety_CentralReg" );
      MuonBoy_sumet_CentralReg.SetName( ::TString( prefix ) + "MuonBoy_sumet_CentralReg" );
      MuonBoy_phi_CentralReg.SetName( ::TString( prefix ) + "MuonBoy_phi_CentralReg" );
      MuonBoy_etx_EndcapRegion.SetName( ::TString( prefix ) + "MuonBoy_etx_EndcapRegion" );
      MuonBoy_ety_EndcapRegion.SetName( ::TString( prefix ) + "MuonBoy_ety_EndcapRegion" );
      MuonBoy_sumet_EndcapRegion.SetName( ::TString( prefix ) + "MuonBoy_sumet_EndcapRegion" );
      MuonBoy_phi_EndcapRegion.SetName( ::TString( prefix ) + "MuonBoy_phi_EndcapRegion" );
      MuonBoy_etx_ForwardReg.SetName( ::TString( prefix ) + "MuonBoy_etx_ForwardReg" );
      MuonBoy_ety_ForwardReg.SetName( ::TString( prefix ) + "MuonBoy_ety_ForwardReg" );
      MuonBoy_sumet_ForwardReg.SetName( ::TString( prefix ) + "MuonBoy_sumet_ForwardReg" );
      MuonBoy_phi_ForwardReg.SetName( ::TString( prefix ) + "MuonBoy_phi_ForwardReg" );
      STVF_MuonBoy_etx.SetName( ::TString( prefix ) + "STVF_MuonBoy_etx" );
      STVF_MuonBoy_ety.SetName( ::TString( prefix ) + "STVF_MuonBoy_ety" );
      STVF_MuonBoy_sumet.SetName( ::TString( prefix ) + "STVF_MuonBoy_sumet" );
      STVF_MuonBoy_etx_CentralReg.SetName( ::TString( prefix ) + "STVF_MuonBoy_etx_CentralReg" );
      STVF_MuonBoy_ety_CentralReg.SetName( ::TString( prefix ) + "STVF_MuonBoy_ety_CentralReg" );
      STVF_MuonBoy_sumet_CentralReg.SetName( ::TString( prefix ) + "STVF_MuonBoy_sumet_CentralReg" );
      STVF_MuonBoy_phi_CentralReg.SetName( ::TString( prefix ) + "STVF_MuonBoy_phi_CentralReg" );
      STVF_MuonBoy_etx_EndcapRegion.SetName( ::TString( prefix ) + "STVF_MuonBoy_etx_EndcapRegion" );
      STVF_MuonBoy_ety_EndcapRegion.SetName( ::TString( prefix ) + "STVF_MuonBoy_ety_EndcapRegion" );
      STVF_MuonBoy_sumet_EndcapRegion.SetName( ::TString( prefix ) + "STVF_MuonBoy_sumet_EndcapRegion" );
      STVF_MuonBoy_phi_EndcapRegion.SetName( ::TString( prefix ) + "STVF_MuonBoy_phi_EndcapRegion" );
      STVF_MuonBoy_etx_ForwardReg.SetName( ::TString( prefix ) + "STVF_MuonBoy_etx_ForwardReg" );
      STVF_MuonBoy_ety_ForwardReg.SetName( ::TString( prefix ) + "STVF_MuonBoy_ety_ForwardReg" );
      STVF_MuonBoy_sumet_ForwardReg.SetName( ::TString( prefix ) + "STVF_MuonBoy_sumet_ForwardReg" );
      STVF_MuonBoy_phi_ForwardReg.SetName( ::TString( prefix ) + "STVF_MuonBoy_phi_ForwardReg" );
      STVF_CellOut_Track_etx.SetName( ::TString( prefix ) + "STVF_CellOut_Track_etx" );
      STVF_CellOut_Track_ety.SetName( ::TString( prefix ) + "STVF_CellOut_Track_ety" );
      STVF_CellOut_Track_sumet.SetName( ::TString( prefix ) + "STVF_CellOut_Track_sumet" );
      STVF_CellOut_Track_etx_CentralReg.SetName( ::TString( prefix ) + "STVF_CellOut_Track_etx_CentralReg" );
      STVF_CellOut_Track_ety_CentralReg.SetName( ::TString( prefix ) + "STVF_CellOut_Track_ety_CentralReg" );
      STVF_CellOut_Track_sumet_CentralReg.SetName( ::TString( prefix ) + "STVF_CellOut_Track_sumet_CentralReg" );
      STVF_CellOut_Track_phi_CentralReg.SetName( ::TString( prefix ) + "STVF_CellOut_Track_phi_CentralReg" );
      STVF_CellOut_Track_etx_EndcapRegion.SetName( ::TString( prefix ) + "STVF_CellOut_Track_etx_EndcapRegion" );
      STVF_CellOut_Track_ety_EndcapRegion.SetName( ::TString( prefix ) + "STVF_CellOut_Track_ety_EndcapRegion" );
      STVF_CellOut_Track_sumet_EndcapRegion.SetName( ::TString( prefix ) + "STVF_CellOut_Track_sumet_EndcapRegion" );
      STVF_CellOut_Track_phi_EndcapRegion.SetName( ::TString( prefix ) + "STVF_CellOut_Track_phi_EndcapRegion" );
      STVF_CellOut_Track_etx_ForwardReg.SetName( ::TString( prefix ) + "STVF_CellOut_Track_etx_ForwardReg" );
      STVF_CellOut_Track_ety_ForwardReg.SetName( ::TString( prefix ) + "STVF_CellOut_Track_ety_ForwardReg" );
      STVF_CellOut_Track_sumet_ForwardReg.SetName( ::TString( prefix ) + "STVF_CellOut_Track_sumet_ForwardReg" );
      STVF_CellOut_Track_phi_ForwardReg.SetName( ::TString( prefix ) + "STVF_CellOut_Track_phi_ForwardReg" );
      STVF_CellOut_TrackPV_etx.SetName( ::TString( prefix ) + "STVF_CellOut_TrackPV_etx" );
      STVF_CellOut_TrackPV_ety.SetName( ::TString( prefix ) + "STVF_CellOut_TrackPV_ety" );
      STVF_CellOut_TrackPV_sumet.SetName( ::TString( prefix ) + "STVF_CellOut_TrackPV_sumet" );
      STVF_CellOut_TrackPV_etx_CentralReg.SetName( ::TString( prefix ) + "STVF_CellOut_TrackPV_etx_CentralReg" );
      STVF_CellOut_TrackPV_ety_CentralReg.SetName( ::TString( prefix ) + "STVF_CellOut_TrackPV_ety_CentralReg" );
      STVF_CellOut_TrackPV_sumet_CentralReg.SetName( ::TString( prefix ) + "STVF_CellOut_TrackPV_sumet_CentralReg" );
      STVF_CellOut_TrackPV_phi_CentralReg.SetName( ::TString( prefix ) + "STVF_CellOut_TrackPV_phi_CentralReg" );
      STVF_CellOut_TrackPV_etx_EndcapRegion.SetName( ::TString( prefix ) + "STVF_CellOut_TrackPV_etx_EndcapRegion" );
      STVF_CellOut_TrackPV_ety_EndcapRegion.SetName( ::TString( prefix ) + "STVF_CellOut_TrackPV_ety_EndcapRegion" );
      STVF_CellOut_TrackPV_sumet_EndcapRegion.SetName( ::TString( prefix ) + "STVF_CellOut_TrackPV_sumet_EndcapRegion" );
      STVF_CellOut_TrackPV_phi_EndcapRegion.SetName( ::TString( prefix ) + "STVF_CellOut_TrackPV_phi_EndcapRegion" );
      STVF_CellOut_TrackPV_etx_ForwardReg.SetName( ::TString( prefix ) + "STVF_CellOut_TrackPV_etx_ForwardReg" );
      STVF_CellOut_TrackPV_ety_ForwardReg.SetName( ::TString( prefix ) + "STVF_CellOut_TrackPV_ety_ForwardReg" );
      STVF_CellOut_TrackPV_sumet_ForwardReg.SetName( ::TString( prefix ) + "STVF_CellOut_TrackPV_sumet_ForwardReg" );
      STVF_CellOut_TrackPV_phi_ForwardReg.SetName( ::TString( prefix ) + "STVF_CellOut_TrackPV_phi_ForwardReg" );
      STVF_CellOutCorr_etx.SetName( ::TString( prefix ) + "STVF_CellOutCorr_etx" );
      STVF_CellOutCorr_ety.SetName( ::TString( prefix ) + "STVF_CellOutCorr_ety" );
      STVF_CellOutCorr_sumet.SetName( ::TString( prefix ) + "STVF_CellOutCorr_sumet" );
      STVF_CellOutCorr_etx_CentralReg.SetName( ::TString( prefix ) + "STVF_CellOutCorr_etx_CentralReg" );
      STVF_CellOutCorr_ety_CentralReg.SetName( ::TString( prefix ) + "STVF_CellOutCorr_ety_CentralReg" );
      STVF_CellOutCorr_sumet_CentralReg.SetName( ::TString( prefix ) + "STVF_CellOutCorr_sumet_CentralReg" );
      STVF_CellOutCorr_phi_CentralReg.SetName( ::TString( prefix ) + "STVF_CellOutCorr_phi_CentralReg" );
      STVF_CellOutCorr_etx_EndcapRegion.SetName( ::TString( prefix ) + "STVF_CellOutCorr_etx_EndcapRegion" );
      STVF_CellOutCorr_ety_EndcapRegion.SetName( ::TString( prefix ) + "STVF_CellOutCorr_ety_EndcapRegion" );
      STVF_CellOutCorr_sumet_EndcapRegion.SetName( ::TString( prefix ) + "STVF_CellOutCorr_sumet_EndcapRegion" );
      STVF_CellOutCorr_phi_EndcapRegion.SetName( ::TString( prefix ) + "STVF_CellOutCorr_phi_EndcapRegion" );
      STVF_CellOutCorr_etx_ForwardReg.SetName( ::TString( prefix ) + "STVF_CellOutCorr_etx_ForwardReg" );
      STVF_CellOutCorr_ety_ForwardReg.SetName( ::TString( prefix ) + "STVF_CellOutCorr_ety_ForwardReg" );
      STVF_CellOutCorr_sumet_ForwardReg.SetName( ::TString( prefix ) + "STVF_CellOutCorr_sumet_ForwardReg" );
      STVF_CellOutCorr_phi_ForwardReg.SetName( ::TString( prefix ) + "STVF_CellOutCorr_phi_ForwardReg" );
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
      RefGamma_etx_CentralReg.ReadFrom( tree );
      RefGamma_ety_CentralReg.ReadFrom( tree );
      RefGamma_sumet_CentralReg.ReadFrom( tree );
      RefGamma_phi_CentralReg.ReadFrom( tree );
      RefGamma_etx_EndcapRegion.ReadFrom( tree );
      RefGamma_ety_EndcapRegion.ReadFrom( tree );
      RefGamma_sumet_EndcapRegion.ReadFrom( tree );
      RefGamma_phi_EndcapRegion.ReadFrom( tree );
      RefGamma_etx_ForwardReg.ReadFrom( tree );
      RefGamma_ety_ForwardReg.ReadFrom( tree );
      RefGamma_sumet_ForwardReg.ReadFrom( tree );
      RefGamma_phi_ForwardReg.ReadFrom( tree );
      STVF_RefGamma_etx.ReadFrom( tree );
      STVF_RefGamma_ety.ReadFrom( tree );
      STVF_RefGamma_sumet.ReadFrom( tree );
      STVF_RefGamma_etx_CentralReg.ReadFrom( tree );
      STVF_RefGamma_ety_CentralReg.ReadFrom( tree );
      STVF_RefGamma_sumet_CentralReg.ReadFrom( tree );
      STVF_RefGamma_phi_CentralReg.ReadFrom( tree );
      STVF_RefGamma_etx_EndcapRegion.ReadFrom( tree );
      STVF_RefGamma_ety_EndcapRegion.ReadFrom( tree );
      STVF_RefGamma_sumet_EndcapRegion.ReadFrom( tree );
      STVF_RefGamma_phi_EndcapRegion.ReadFrom( tree );
      STVF_RefGamma_etx_ForwardReg.ReadFrom( tree );
      STVF_RefGamma_ety_ForwardReg.ReadFrom( tree );
      STVF_RefGamma_sumet_ForwardReg.ReadFrom( tree );
      STVF_RefGamma_phi_ForwardReg.ReadFrom( tree );
      RefFinal_etx.ReadFrom( tree );
      RefFinal_ety.ReadFrom( tree );
      RefFinal_sumet.ReadFrom( tree );
      RefFinal_etx_CentralReg.ReadFrom( tree );
      RefFinal_ety_CentralReg.ReadFrom( tree );
      RefFinal_sumet_CentralReg.ReadFrom( tree );
      RefFinal_phi_CentralReg.ReadFrom( tree );
      RefFinal_etx_EndcapRegion.ReadFrom( tree );
      RefFinal_ety_EndcapRegion.ReadFrom( tree );
      RefFinal_sumet_EndcapRegion.ReadFrom( tree );
      RefFinal_phi_EndcapRegion.ReadFrom( tree );
      RefFinal_etx_ForwardReg.ReadFrom( tree );
      RefFinal_ety_ForwardReg.ReadFrom( tree );
      RefFinal_sumet_ForwardReg.ReadFrom( tree );
      RefFinal_phi_ForwardReg.ReadFrom( tree );
      STVF_RefFinal_etx.ReadFrom( tree );
      STVF_RefFinal_ety.ReadFrom( tree );
      STVF_RefFinal_sumet.ReadFrom( tree );
      STVF_RefFinal_etx_CentralReg.ReadFrom( tree );
      STVF_RefFinal_ety_CentralReg.ReadFrom( tree );
      STVF_RefFinal_sumet_CentralReg.ReadFrom( tree );
      STVF_RefFinal_phi_CentralReg.ReadFrom( tree );
      STVF_RefFinal_etx_EndcapRegion.ReadFrom( tree );
      STVF_RefFinal_ety_EndcapRegion.ReadFrom( tree );
      STVF_RefFinal_sumet_EndcapRegion.ReadFrom( tree );
      STVF_RefFinal_phi_EndcapRegion.ReadFrom( tree );
      STVF_RefFinal_etx_ForwardReg.ReadFrom( tree );
      STVF_RefFinal_ety_ForwardReg.ReadFrom( tree );
      STVF_RefFinal_sumet_ForwardReg.ReadFrom( tree );
      STVF_RefFinal_phi_ForwardReg.ReadFrom( tree );
      RefJet_etx.ReadFrom( tree );
      RefJet_ety.ReadFrom( tree );
      RefJet_sumet.ReadFrom( tree );
      RefJet_etx_CentralReg.ReadFrom( tree );
      RefJet_ety_CentralReg.ReadFrom( tree );
      RefJet_sumet_CentralReg.ReadFrom( tree );
      RefJet_phi_CentralReg.ReadFrom( tree );
      RefJet_etx_EndcapRegion.ReadFrom( tree );
      RefJet_ety_EndcapRegion.ReadFrom( tree );
      RefJet_sumet_EndcapRegion.ReadFrom( tree );
      RefJet_phi_EndcapRegion.ReadFrom( tree );
      RefJet_etx_ForwardReg.ReadFrom( tree );
      RefJet_ety_ForwardReg.ReadFrom( tree );
      RefJet_sumet_ForwardReg.ReadFrom( tree );
      RefJet_phi_ForwardReg.ReadFrom( tree );
      STVF_RefJet_etx.ReadFrom( tree );
      STVF_RefJet_ety.ReadFrom( tree );
      STVF_RefJet_sumet.ReadFrom( tree );
      STVF_RefJet_etx_CentralReg.ReadFrom( tree );
      STVF_RefJet_ety_CentralReg.ReadFrom( tree );
      STVF_RefJet_sumet_CentralReg.ReadFrom( tree );
      STVF_RefJet_phi_CentralReg.ReadFrom( tree );
      STVF_RefJet_etx_EndcapRegion.ReadFrom( tree );
      STVF_RefJet_ety_EndcapRegion.ReadFrom( tree );
      STVF_RefJet_sumet_EndcapRegion.ReadFrom( tree );
      STVF_RefJet_phi_EndcapRegion.ReadFrom( tree );
      STVF_RefJet_etx_ForwardReg.ReadFrom( tree );
      STVF_RefJet_ety_ForwardReg.ReadFrom( tree );
      STVF_RefJet_sumet_ForwardReg.ReadFrom( tree );
      STVF_RefJet_phi_ForwardReg.ReadFrom( tree );
      RefEle_etx.ReadFrom( tree );
      RefEle_ety.ReadFrom( tree );
      RefEle_sumet.ReadFrom( tree );
      RefEle_etx_CentralReg.ReadFrom( tree );
      RefEle_ety_CentralReg.ReadFrom( tree );
      RefEle_sumet_CentralReg.ReadFrom( tree );
      RefEle_phi_CentralReg.ReadFrom( tree );
      RefEle_etx_EndcapRegion.ReadFrom( tree );
      RefEle_ety_EndcapRegion.ReadFrom( tree );
      RefEle_sumet_EndcapRegion.ReadFrom( tree );
      RefEle_phi_EndcapRegion.ReadFrom( tree );
      RefEle_etx_ForwardReg.ReadFrom( tree );
      RefEle_ety_ForwardReg.ReadFrom( tree );
      RefEle_sumet_ForwardReg.ReadFrom( tree );
      RefEle_phi_ForwardReg.ReadFrom( tree );
      STVF_RefEle_etx.ReadFrom( tree );
      STVF_RefEle_ety.ReadFrom( tree );
      STVF_RefEle_sumet.ReadFrom( tree );
      STVF_RefEle_etx_CentralReg.ReadFrom( tree );
      STVF_RefEle_ety_CentralReg.ReadFrom( tree );
      STVF_RefEle_sumet_CentralReg.ReadFrom( tree );
      STVF_RefEle_phi_CentralReg.ReadFrom( tree );
      STVF_RefEle_etx_EndcapRegion.ReadFrom( tree );
      STVF_RefEle_ety_EndcapRegion.ReadFrom( tree );
      STVF_RefEle_sumet_EndcapRegion.ReadFrom( tree );
      STVF_RefEle_phi_EndcapRegion.ReadFrom( tree );
      STVF_RefEle_etx_ForwardReg.ReadFrom( tree );
      STVF_RefEle_ety_ForwardReg.ReadFrom( tree );
      STVF_RefEle_sumet_ForwardReg.ReadFrom( tree );
      STVF_RefEle_phi_ForwardReg.ReadFrom( tree );
      Muon_Total_Staco_etx.ReadFrom( tree );
      Muon_Total_Staco_ety.ReadFrom( tree );
      Muon_Total_Staco_sumet.ReadFrom( tree );
      Muon_Total_Staco_etx_CentralReg.ReadFrom( tree );
      Muon_Total_Staco_ety_CentralReg.ReadFrom( tree );
      Muon_Total_Staco_sumet_CentralReg.ReadFrom( tree );
      Muon_Total_Staco_phi_CentralReg.ReadFrom( tree );
      Muon_Total_Staco_etx_EndcapRegion.ReadFrom( tree );
      Muon_Total_Staco_ety_EndcapRegion.ReadFrom( tree );
      Muon_Total_Staco_sumet_EndcapRegion.ReadFrom( tree );
      Muon_Total_Staco_phi_EndcapRegion.ReadFrom( tree );
      Muon_Total_Staco_etx_ForwardReg.ReadFrom( tree );
      Muon_Total_Staco_ety_ForwardReg.ReadFrom( tree );
      Muon_Total_Staco_sumet_ForwardReg.ReadFrom( tree );
      Muon_Total_Staco_phi_ForwardReg.ReadFrom( tree );
      STVF_Muon_Total_Staco_etx.ReadFrom( tree );
      STVF_Muon_Total_Staco_ety.ReadFrom( tree );
      STVF_Muon_Total_Staco_sumet.ReadFrom( tree );
      STVF_Muon_Total_Staco_etx_CentralReg.ReadFrom( tree );
      STVF_Muon_Total_Staco_ety_CentralReg.ReadFrom( tree );
      STVF_Muon_Total_Staco_sumet_CentralReg.ReadFrom( tree );
      STVF_Muon_Total_Staco_phi_CentralReg.ReadFrom( tree );
      STVF_Muon_Total_Staco_etx_EndcapRegion.ReadFrom( tree );
      STVF_Muon_Total_Staco_ety_EndcapRegion.ReadFrom( tree );
      STVF_Muon_Total_Staco_sumet_EndcapRegion.ReadFrom( tree );
      STVF_Muon_Total_Staco_phi_EndcapRegion.ReadFrom( tree );
      STVF_Muon_Total_Staco_etx_ForwardReg.ReadFrom( tree );
      STVF_Muon_Total_Staco_ety_ForwardReg.ReadFrom( tree );
      STVF_Muon_Total_Staco_sumet_ForwardReg.ReadFrom( tree );
      STVF_Muon_Total_Staco_phi_ForwardReg.ReadFrom( tree );
      Muon_Isol_Staco_etx.ReadFrom( tree );
      Muon_Isol_Staco_ety.ReadFrom( tree );
      Muon_Isol_Staco_sumet.ReadFrom( tree );
      Muon_Isol_Staco_etx_CentralReg.ReadFrom( tree );
      Muon_Isol_Staco_ety_CentralReg.ReadFrom( tree );
      Muon_Isol_Staco_sumet_CentralReg.ReadFrom( tree );
      Muon_Isol_Staco_phi_CentralReg.ReadFrom( tree );
      Muon_Isol_Staco_etx_EndcapRegion.ReadFrom( tree );
      Muon_Isol_Staco_ety_EndcapRegion.ReadFrom( tree );
      Muon_Isol_Staco_sumet_EndcapRegion.ReadFrom( tree );
      Muon_Isol_Staco_phi_EndcapRegion.ReadFrom( tree );
      Muon_Isol_Staco_etx_ForwardReg.ReadFrom( tree );
      Muon_Isol_Staco_ety_ForwardReg.ReadFrom( tree );
      Muon_Isol_Staco_sumet_ForwardReg.ReadFrom( tree );
      Muon_Isol_Staco_phi_ForwardReg.ReadFrom( tree );
      STVF_Muon_Isol_Staco_etx.ReadFrom( tree );
      STVF_Muon_Isol_Staco_ety.ReadFrom( tree );
      STVF_Muon_Isol_Staco_sumet.ReadFrom( tree );
      STVF_Muon_Isol_Staco_etx_CentralReg.ReadFrom( tree );
      STVF_Muon_Isol_Staco_ety_CentralReg.ReadFrom( tree );
      STVF_Muon_Isol_Staco_sumet_CentralReg.ReadFrom( tree );
      STVF_Muon_Isol_Staco_phi_CentralReg.ReadFrom( tree );
      STVF_Muon_Isol_Staco_etx_EndcapRegion.ReadFrom( tree );
      STVF_Muon_Isol_Staco_ety_EndcapRegion.ReadFrom( tree );
      STVF_Muon_Isol_Staco_sumet_EndcapRegion.ReadFrom( tree );
      STVF_Muon_Isol_Staco_phi_EndcapRegion.ReadFrom( tree );
      STVF_Muon_Isol_Staco_etx_ForwardReg.ReadFrom( tree );
      STVF_Muon_Isol_Staco_ety_ForwardReg.ReadFrom( tree );
      STVF_Muon_Isol_Staco_sumet_ForwardReg.ReadFrom( tree );
      STVF_Muon_Isol_Staco_phi_ForwardReg.ReadFrom( tree );
      Muon_NonIsol_Staco_etx.ReadFrom( tree );
      Muon_NonIsol_Staco_ety.ReadFrom( tree );
      Muon_NonIsol_Staco_sumet.ReadFrom( tree );
      Muon_NonIsol_Staco_etx_CentralReg.ReadFrom( tree );
      Muon_NonIsol_Staco_ety_CentralReg.ReadFrom( tree );
      Muon_NonIsol_Staco_sumet_CentralReg.ReadFrom( tree );
      Muon_NonIsol_Staco_phi_CentralReg.ReadFrom( tree );
      Muon_NonIsol_Staco_etx_EndcapRegion.ReadFrom( tree );
      Muon_NonIsol_Staco_ety_EndcapRegion.ReadFrom( tree );
      Muon_NonIsol_Staco_sumet_EndcapRegion.ReadFrom( tree );
      Muon_NonIsol_Staco_phi_EndcapRegion.ReadFrom( tree );
      Muon_NonIsol_Staco_etx_ForwardReg.ReadFrom( tree );
      Muon_NonIsol_Staco_ety_ForwardReg.ReadFrom( tree );
      Muon_NonIsol_Staco_sumet_ForwardReg.ReadFrom( tree );
      Muon_NonIsol_Staco_phi_ForwardReg.ReadFrom( tree );
      STVF_Muon_NonIsol_Staco_etx.ReadFrom( tree );
      STVF_Muon_NonIsol_Staco_ety.ReadFrom( tree );
      STVF_Muon_NonIsol_Staco_sumet.ReadFrom( tree );
      STVF_Muon_NonIsol_Staco_etx_CentralReg.ReadFrom( tree );
      STVF_Muon_NonIsol_Staco_ety_CentralReg.ReadFrom( tree );
      STVF_Muon_NonIsol_Staco_sumet_CentralReg.ReadFrom( tree );
      STVF_Muon_NonIsol_Staco_phi_CentralReg.ReadFrom( tree );
      STVF_Muon_NonIsol_Staco_etx_EndcapRegion.ReadFrom( tree );
      STVF_Muon_NonIsol_Staco_ety_EndcapRegion.ReadFrom( tree );
      STVF_Muon_NonIsol_Staco_sumet_EndcapRegion.ReadFrom( tree );
      STVF_Muon_NonIsol_Staco_phi_EndcapRegion.ReadFrom( tree );
      STVF_Muon_NonIsol_Staco_etx_ForwardReg.ReadFrom( tree );
      STVF_Muon_NonIsol_Staco_ety_ForwardReg.ReadFrom( tree );
      STVF_Muon_NonIsol_Staco_sumet_ForwardReg.ReadFrom( tree );
      STVF_Muon_NonIsol_Staco_phi_ForwardReg.ReadFrom( tree );
      CellOut_etx.ReadFrom( tree );
      CellOut_ety.ReadFrom( tree );
      CellOut_sumet.ReadFrom( tree );
      CellOut_etx_CentralReg.ReadFrom( tree );
      CellOut_ety_CentralReg.ReadFrom( tree );
      CellOut_sumet_CentralReg.ReadFrom( tree );
      CellOut_phi_CentralReg.ReadFrom( tree );
      CellOut_etx_EndcapRegion.ReadFrom( tree );
      CellOut_ety_EndcapRegion.ReadFrom( tree );
      CellOut_sumet_EndcapRegion.ReadFrom( tree );
      CellOut_phi_EndcapRegion.ReadFrom( tree );
      CellOut_etx_ForwardReg.ReadFrom( tree );
      CellOut_ety_ForwardReg.ReadFrom( tree );
      CellOut_sumet_ForwardReg.ReadFrom( tree );
      CellOut_phi_ForwardReg.ReadFrom( tree );
      STVF_CellOut_etx.ReadFrom( tree );
      STVF_CellOut_ety.ReadFrom( tree );
      STVF_CellOut_sumet.ReadFrom( tree );
      STVF_CellOut_etx_CentralReg.ReadFrom( tree );
      STVF_CellOut_ety_CentralReg.ReadFrom( tree );
      STVF_CellOut_sumet_CentralReg.ReadFrom( tree );
      STVF_CellOut_phi_CentralReg.ReadFrom( tree );
      STVF_CellOut_etx_EndcapRegion.ReadFrom( tree );
      STVF_CellOut_ety_EndcapRegion.ReadFrom( tree );
      STVF_CellOut_sumet_EndcapRegion.ReadFrom( tree );
      STVF_CellOut_phi_EndcapRegion.ReadFrom( tree );
      STVF_CellOut_etx_ForwardReg.ReadFrom( tree );
      STVF_CellOut_ety_ForwardReg.ReadFrom( tree );
      STVF_CellOut_sumet_ForwardReg.ReadFrom( tree );
      STVF_CellOut_phi_ForwardReg.ReadFrom( tree );
      Muon_Isol_Muid_etx.ReadFrom( tree );
      Muon_Isol_Muid_ety.ReadFrom( tree );
      Muon_Isol_Muid_sumet.ReadFrom( tree );
      Muon_Isol_Muid_etx_CentralReg.ReadFrom( tree );
      Muon_Isol_Muid_ety_CentralReg.ReadFrom( tree );
      Muon_Isol_Muid_sumet_CentralReg.ReadFrom( tree );
      Muon_Isol_Muid_phi_CentralReg.ReadFrom( tree );
      Muon_Isol_Muid_etx_EndcapRegion.ReadFrom( tree );
      Muon_Isol_Muid_ety_EndcapRegion.ReadFrom( tree );
      Muon_Isol_Muid_sumet_EndcapRegion.ReadFrom( tree );
      Muon_Isol_Muid_phi_EndcapRegion.ReadFrom( tree );
      Muon_Isol_Muid_etx_ForwardReg.ReadFrom( tree );
      Muon_Isol_Muid_ety_ForwardReg.ReadFrom( tree );
      Muon_Isol_Muid_sumet_ForwardReg.ReadFrom( tree );
      Muon_Isol_Muid_phi_ForwardReg.ReadFrom( tree );
      STVF_Muon_Isol_Muid_etx.ReadFrom( tree );
      STVF_Muon_Isol_Muid_ety.ReadFrom( tree );
      STVF_Muon_Isol_Muid_sumet.ReadFrom( tree );
      STVF_Muon_Isol_Muid_etx_CentralReg.ReadFrom( tree );
      STVF_Muon_Isol_Muid_ety_CentralReg.ReadFrom( tree );
      STVF_Muon_Isol_Muid_sumet_CentralReg.ReadFrom( tree );
      STVF_Muon_Isol_Muid_phi_CentralReg.ReadFrom( tree );
      STVF_Muon_Isol_Muid_etx_EndcapRegion.ReadFrom( tree );
      STVF_Muon_Isol_Muid_ety_EndcapRegion.ReadFrom( tree );
      STVF_Muon_Isol_Muid_sumet_EndcapRegion.ReadFrom( tree );
      STVF_Muon_Isol_Muid_phi_EndcapRegion.ReadFrom( tree );
      STVF_Muon_Isol_Muid_etx_ForwardReg.ReadFrom( tree );
      STVF_Muon_Isol_Muid_ety_ForwardReg.ReadFrom( tree );
      STVF_Muon_Isol_Muid_sumet_ForwardReg.ReadFrom( tree );
      STVF_Muon_Isol_Muid_phi_ForwardReg.ReadFrom( tree );
      Muon_NonIsol_Muid_etx.ReadFrom( tree );
      Muon_NonIsol_Muid_ety.ReadFrom( tree );
      Muon_NonIsol_Muid_sumet.ReadFrom( tree );
      Muon_NonIsol_Muid_etx_CentralReg.ReadFrom( tree );
      Muon_NonIsol_Muid_ety_CentralReg.ReadFrom( tree );
      Muon_NonIsol_Muid_sumet_CentralReg.ReadFrom( tree );
      Muon_NonIsol_Muid_phi_CentralReg.ReadFrom( tree );
      Muon_NonIsol_Muid_etx_EndcapRegion.ReadFrom( tree );
      Muon_NonIsol_Muid_ety_EndcapRegion.ReadFrom( tree );
      Muon_NonIsol_Muid_sumet_EndcapRegion.ReadFrom( tree );
      Muon_NonIsol_Muid_phi_EndcapRegion.ReadFrom( tree );
      Muon_NonIsol_Muid_etx_ForwardReg.ReadFrom( tree );
      Muon_NonIsol_Muid_ety_ForwardReg.ReadFrom( tree );
      Muon_NonIsol_Muid_sumet_ForwardReg.ReadFrom( tree );
      Muon_NonIsol_Muid_phi_ForwardReg.ReadFrom( tree );
      STVF_Muon_NonIsol_Muid_etx.ReadFrom( tree );
      STVF_Muon_NonIsol_Muid_ety.ReadFrom( tree );
      STVF_Muon_NonIsol_Muid_sumet.ReadFrom( tree );
      STVF_Muon_NonIsol_Muid_etx_CentralReg.ReadFrom( tree );
      STVF_Muon_NonIsol_Muid_ety_CentralReg.ReadFrom( tree );
      STVF_Muon_NonIsol_Muid_sumet_CentralReg.ReadFrom( tree );
      STVF_Muon_NonIsol_Muid_phi_CentralReg.ReadFrom( tree );
      STVF_Muon_NonIsol_Muid_etx_EndcapRegion.ReadFrom( tree );
      STVF_Muon_NonIsol_Muid_ety_EndcapRegion.ReadFrom( tree );
      STVF_Muon_NonIsol_Muid_sumet_EndcapRegion.ReadFrom( tree );
      STVF_Muon_NonIsol_Muid_phi_EndcapRegion.ReadFrom( tree );
      STVF_Muon_NonIsol_Muid_etx_ForwardReg.ReadFrom( tree );
      STVF_Muon_NonIsol_Muid_ety_ForwardReg.ReadFrom( tree );
      STVF_Muon_NonIsol_Muid_sumet_ForwardReg.ReadFrom( tree );
      STVF_Muon_NonIsol_Muid_phi_ForwardReg.ReadFrom( tree );
      Muon_Total_Muid_etx.ReadFrom( tree );
      Muon_Total_Muid_ety.ReadFrom( tree );
      Muon_Total_Muid_sumet.ReadFrom( tree );
      Muon_Total_Muid_etx_CentralReg.ReadFrom( tree );
      Muon_Total_Muid_ety_CentralReg.ReadFrom( tree );
      Muon_Total_Muid_sumet_CentralReg.ReadFrom( tree );
      Muon_Total_Muid_phi_CentralReg.ReadFrom( tree );
      Muon_Total_Muid_etx_EndcapRegion.ReadFrom( tree );
      Muon_Total_Muid_ety_EndcapRegion.ReadFrom( tree );
      Muon_Total_Muid_sumet_EndcapRegion.ReadFrom( tree );
      Muon_Total_Muid_phi_EndcapRegion.ReadFrom( tree );
      Muon_Total_Muid_etx_ForwardReg.ReadFrom( tree );
      Muon_Total_Muid_ety_ForwardReg.ReadFrom( tree );
      Muon_Total_Muid_sumet_ForwardReg.ReadFrom( tree );
      Muon_Total_Muid_phi_ForwardReg.ReadFrom( tree );
      STVF_Muon_Total_Muid_etx.ReadFrom( tree );
      STVF_Muon_Total_Muid_ety.ReadFrom( tree );
      STVF_Muon_Total_Muid_sumet.ReadFrom( tree );
      STVF_Muon_Total_Muid_etx_CentralReg.ReadFrom( tree );
      STVF_Muon_Total_Muid_ety_CentralReg.ReadFrom( tree );
      STVF_Muon_Total_Muid_sumet_CentralReg.ReadFrom( tree );
      STVF_Muon_Total_Muid_phi_CentralReg.ReadFrom( tree );
      STVF_Muon_Total_Muid_etx_EndcapRegion.ReadFrom( tree );
      STVF_Muon_Total_Muid_ety_EndcapRegion.ReadFrom( tree );
      STVF_Muon_Total_Muid_sumet_EndcapRegion.ReadFrom( tree );
      STVF_Muon_Total_Muid_phi_EndcapRegion.ReadFrom( tree );
      STVF_Muon_Total_Muid_etx_ForwardReg.ReadFrom( tree );
      STVF_Muon_Total_Muid_ety_ForwardReg.ReadFrom( tree );
      STVF_Muon_Total_Muid_sumet_ForwardReg.ReadFrom( tree );
      STVF_Muon_Total_Muid_phi_ForwardReg.ReadFrom( tree );
      Track_etx.ReadFrom( tree );
      Track_ety.ReadFrom( tree );
      Track_sumet.ReadFrom( tree );
      Track_etx_CentralReg.ReadFrom( tree );
      Track_ety_CentralReg.ReadFrom( tree );
      Track_sumet_CentralReg.ReadFrom( tree );
      Track_phi_CentralReg.ReadFrom( tree );
      Track_etx_EndcapRegion.ReadFrom( tree );
      Track_ety_EndcapRegion.ReadFrom( tree );
      Track_sumet_EndcapRegion.ReadFrom( tree );
      Track_phi_EndcapRegion.ReadFrom( tree );
      Track_etx_ForwardReg.ReadFrom( tree );
      Track_ety_ForwardReg.ReadFrom( tree );
      Track_sumet_ForwardReg.ReadFrom( tree );
      Track_phi_ForwardReg.ReadFrom( tree );
      STVF_Track_etx.ReadFrom( tree );
      STVF_Track_ety.ReadFrom( tree );
      STVF_Track_sumet.ReadFrom( tree );
      STVF_Track_etx_CentralReg.ReadFrom( tree );
      STVF_Track_ety_CentralReg.ReadFrom( tree );
      STVF_Track_sumet_CentralReg.ReadFrom( tree );
      STVF_Track_phi_CentralReg.ReadFrom( tree );
      STVF_Track_etx_EndcapRegion.ReadFrom( tree );
      STVF_Track_ety_EndcapRegion.ReadFrom( tree );
      STVF_Track_sumet_EndcapRegion.ReadFrom( tree );
      STVF_Track_phi_EndcapRegion.ReadFrom( tree );
      STVF_Track_etx_ForwardReg.ReadFrom( tree );
      STVF_Track_ety_ForwardReg.ReadFrom( tree );
      STVF_Track_sumet_ForwardReg.ReadFrom( tree );
      STVF_Track_phi_ForwardReg.ReadFrom( tree );
      SoftJets_etx.ReadFrom( tree );
      SoftJets_ety.ReadFrom( tree );
      SoftJets_sumet.ReadFrom( tree );
      SoftJets_etx_CentralReg.ReadFrom( tree );
      SoftJets_ety_CentralReg.ReadFrom( tree );
      SoftJets_sumet_CentralReg.ReadFrom( tree );
      SoftJets_phi_CentralReg.ReadFrom( tree );
      SoftJets_etx_EndcapRegion.ReadFrom( tree );
      SoftJets_ety_EndcapRegion.ReadFrom( tree );
      SoftJets_sumet_EndcapRegion.ReadFrom( tree );
      SoftJets_phi_EndcapRegion.ReadFrom( tree );
      SoftJets_etx_ForwardReg.ReadFrom( tree );
      SoftJets_ety_ForwardReg.ReadFrom( tree );
      SoftJets_sumet_ForwardReg.ReadFrom( tree );
      SoftJets_phi_ForwardReg.ReadFrom( tree );
      STVF_SoftJets_etx.ReadFrom( tree );
      STVF_SoftJets_ety.ReadFrom( tree );
      STVF_SoftJets_sumet.ReadFrom( tree );
      STVF_SoftJets_etx_CentralReg.ReadFrom( tree );
      STVF_SoftJets_ety_CentralReg.ReadFrom( tree );
      STVF_SoftJets_sumet_CentralReg.ReadFrom( tree );
      STVF_SoftJets_phi_CentralReg.ReadFrom( tree );
      STVF_SoftJets_etx_EndcapRegion.ReadFrom( tree );
      STVF_SoftJets_ety_EndcapRegion.ReadFrom( tree );
      STVF_SoftJets_sumet_EndcapRegion.ReadFrom( tree );
      STVF_SoftJets_phi_EndcapRegion.ReadFrom( tree );
      STVF_SoftJets_etx_ForwardReg.ReadFrom( tree );
      STVF_SoftJets_ety_ForwardReg.ReadFrom( tree );
      STVF_SoftJets_sumet_ForwardReg.ReadFrom( tree );
      STVF_SoftJets_phi_ForwardReg.ReadFrom( tree );
      RefMuon_etx.ReadFrom( tree );
      RefMuon_ety.ReadFrom( tree );
      RefMuon_sumet.ReadFrom( tree );
      RefMuon_etx_CentralReg.ReadFrom( tree );
      RefMuon_ety_CentralReg.ReadFrom( tree );
      RefMuon_sumet_CentralReg.ReadFrom( tree );
      RefMuon_phi_CentralReg.ReadFrom( tree );
      RefMuon_etx_EndcapRegion.ReadFrom( tree );
      RefMuon_ety_EndcapRegion.ReadFrom( tree );
      RefMuon_sumet_EndcapRegion.ReadFrom( tree );
      RefMuon_phi_EndcapRegion.ReadFrom( tree );
      RefMuon_etx_ForwardReg.ReadFrom( tree );
      RefMuon_ety_ForwardReg.ReadFrom( tree );
      RefMuon_sumet_ForwardReg.ReadFrom( tree );
      RefMuon_phi_ForwardReg.ReadFrom( tree );
      STVF_RefMuon_etx.ReadFrom( tree );
      STVF_RefMuon_ety.ReadFrom( tree );
      STVF_RefMuon_sumet.ReadFrom( tree );
      STVF_RefMuon_etx_CentralReg.ReadFrom( tree );
      STVF_RefMuon_ety_CentralReg.ReadFrom( tree );
      STVF_RefMuon_sumet_CentralReg.ReadFrom( tree );
      STVF_RefMuon_phi_CentralReg.ReadFrom( tree );
      STVF_RefMuon_etx_EndcapRegion.ReadFrom( tree );
      STVF_RefMuon_ety_EndcapRegion.ReadFrom( tree );
      STVF_RefMuon_sumet_EndcapRegion.ReadFrom( tree );
      STVF_RefMuon_phi_EndcapRegion.ReadFrom( tree );
      STVF_RefMuon_etx_ForwardReg.ReadFrom( tree );
      STVF_RefMuon_ety_ForwardReg.ReadFrom( tree );
      STVF_RefMuon_sumet_ForwardReg.ReadFrom( tree );
      STVF_RefMuon_phi_ForwardReg.ReadFrom( tree );
      MuonBoy_etx.ReadFrom( tree );
      MuonBoy_ety.ReadFrom( tree );
      MuonBoy_sumet.ReadFrom( tree );
      MuonBoy_etx_CentralReg.ReadFrom( tree );
      MuonBoy_ety_CentralReg.ReadFrom( tree );
      MuonBoy_sumet_CentralReg.ReadFrom( tree );
      MuonBoy_phi_CentralReg.ReadFrom( tree );
      MuonBoy_etx_EndcapRegion.ReadFrom( tree );
      MuonBoy_ety_EndcapRegion.ReadFrom( tree );
      MuonBoy_sumet_EndcapRegion.ReadFrom( tree );
      MuonBoy_phi_EndcapRegion.ReadFrom( tree );
      MuonBoy_etx_ForwardReg.ReadFrom( tree );
      MuonBoy_ety_ForwardReg.ReadFrom( tree );
      MuonBoy_sumet_ForwardReg.ReadFrom( tree );
      MuonBoy_phi_ForwardReg.ReadFrom( tree );
      STVF_MuonBoy_etx.ReadFrom( tree );
      STVF_MuonBoy_ety.ReadFrom( tree );
      STVF_MuonBoy_sumet.ReadFrom( tree );
      STVF_MuonBoy_etx_CentralReg.ReadFrom( tree );
      STVF_MuonBoy_ety_CentralReg.ReadFrom( tree );
      STVF_MuonBoy_sumet_CentralReg.ReadFrom( tree );
      STVF_MuonBoy_phi_CentralReg.ReadFrom( tree );
      STVF_MuonBoy_etx_EndcapRegion.ReadFrom( tree );
      STVF_MuonBoy_ety_EndcapRegion.ReadFrom( tree );
      STVF_MuonBoy_sumet_EndcapRegion.ReadFrom( tree );
      STVF_MuonBoy_phi_EndcapRegion.ReadFrom( tree );
      STVF_MuonBoy_etx_ForwardReg.ReadFrom( tree );
      STVF_MuonBoy_ety_ForwardReg.ReadFrom( tree );
      STVF_MuonBoy_sumet_ForwardReg.ReadFrom( tree );
      STVF_MuonBoy_phi_ForwardReg.ReadFrom( tree );
      STVF_CellOut_Track_etx.ReadFrom( tree );
      STVF_CellOut_Track_ety.ReadFrom( tree );
      STVF_CellOut_Track_sumet.ReadFrom( tree );
      STVF_CellOut_Track_etx_CentralReg.ReadFrom( tree );
      STVF_CellOut_Track_ety_CentralReg.ReadFrom( tree );
      STVF_CellOut_Track_sumet_CentralReg.ReadFrom( tree );
      STVF_CellOut_Track_phi_CentralReg.ReadFrom( tree );
      STVF_CellOut_Track_etx_EndcapRegion.ReadFrom( tree );
      STVF_CellOut_Track_ety_EndcapRegion.ReadFrom( tree );
      STVF_CellOut_Track_sumet_EndcapRegion.ReadFrom( tree );
      STVF_CellOut_Track_phi_EndcapRegion.ReadFrom( tree );
      STVF_CellOut_Track_etx_ForwardReg.ReadFrom( tree );
      STVF_CellOut_Track_ety_ForwardReg.ReadFrom( tree );
      STVF_CellOut_Track_sumet_ForwardReg.ReadFrom( tree );
      STVF_CellOut_Track_phi_ForwardReg.ReadFrom( tree );
      STVF_CellOut_TrackPV_etx.ReadFrom( tree );
      STVF_CellOut_TrackPV_ety.ReadFrom( tree );
      STVF_CellOut_TrackPV_sumet.ReadFrom( tree );
      STVF_CellOut_TrackPV_etx_CentralReg.ReadFrom( tree );
      STVF_CellOut_TrackPV_ety_CentralReg.ReadFrom( tree );
      STVF_CellOut_TrackPV_sumet_CentralReg.ReadFrom( tree );
      STVF_CellOut_TrackPV_phi_CentralReg.ReadFrom( tree );
      STVF_CellOut_TrackPV_etx_EndcapRegion.ReadFrom( tree );
      STVF_CellOut_TrackPV_ety_EndcapRegion.ReadFrom( tree );
      STVF_CellOut_TrackPV_sumet_EndcapRegion.ReadFrom( tree );
      STVF_CellOut_TrackPV_phi_EndcapRegion.ReadFrom( tree );
      STVF_CellOut_TrackPV_etx_ForwardReg.ReadFrom( tree );
      STVF_CellOut_TrackPV_ety_ForwardReg.ReadFrom( tree );
      STVF_CellOut_TrackPV_sumet_ForwardReg.ReadFrom( tree );
      STVF_CellOut_TrackPV_phi_ForwardReg.ReadFrom( tree );
      STVF_CellOutCorr_etx.ReadFrom( tree );
      STVF_CellOutCorr_ety.ReadFrom( tree );
      STVF_CellOutCorr_sumet.ReadFrom( tree );
      STVF_CellOutCorr_etx_CentralReg.ReadFrom( tree );
      STVF_CellOutCorr_ety_CentralReg.ReadFrom( tree );
      STVF_CellOutCorr_sumet_CentralReg.ReadFrom( tree );
      STVF_CellOutCorr_phi_CentralReg.ReadFrom( tree );
      STVF_CellOutCorr_etx_EndcapRegion.ReadFrom( tree );
      STVF_CellOutCorr_ety_EndcapRegion.ReadFrom( tree );
      STVF_CellOutCorr_sumet_EndcapRegion.ReadFrom( tree );
      STVF_CellOutCorr_phi_EndcapRegion.ReadFrom( tree );
      STVF_CellOutCorr_etx_ForwardReg.ReadFrom( tree );
      STVF_CellOutCorr_ety_ForwardReg.ReadFrom( tree );
      STVF_CellOutCorr_sumet_ForwardReg.ReadFrom( tree );
      STVF_CellOutCorr_phi_ForwardReg.ReadFrom( tree );

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
      RefGamma_etx_CentralReg.WriteTo( tree );
      RefGamma_ety_CentralReg.WriteTo( tree );
      RefGamma_sumet_CentralReg.WriteTo( tree );
      RefGamma_phi_CentralReg.WriteTo( tree );
      RefGamma_etx_EndcapRegion.WriteTo( tree );
      RefGamma_ety_EndcapRegion.WriteTo( tree );
      RefGamma_sumet_EndcapRegion.WriteTo( tree );
      RefGamma_phi_EndcapRegion.WriteTo( tree );
      RefGamma_etx_ForwardReg.WriteTo( tree );
      RefGamma_ety_ForwardReg.WriteTo( tree );
      RefGamma_sumet_ForwardReg.WriteTo( tree );
      RefGamma_phi_ForwardReg.WriteTo( tree );
      STVF_RefGamma_etx.WriteTo( tree );
      STVF_RefGamma_ety.WriteTo( tree );
      STVF_RefGamma_sumet.WriteTo( tree );
      STVF_RefGamma_etx_CentralReg.WriteTo( tree );
      STVF_RefGamma_ety_CentralReg.WriteTo( tree );
      STVF_RefGamma_sumet_CentralReg.WriteTo( tree );
      STVF_RefGamma_phi_CentralReg.WriteTo( tree );
      STVF_RefGamma_etx_EndcapRegion.WriteTo( tree );
      STVF_RefGamma_ety_EndcapRegion.WriteTo( tree );
      STVF_RefGamma_sumet_EndcapRegion.WriteTo( tree );
      STVF_RefGamma_phi_EndcapRegion.WriteTo( tree );
      STVF_RefGamma_etx_ForwardReg.WriteTo( tree );
      STVF_RefGamma_ety_ForwardReg.WriteTo( tree );
      STVF_RefGamma_sumet_ForwardReg.WriteTo( tree );
      STVF_RefGamma_phi_ForwardReg.WriteTo( tree );
      RefFinal_etx.WriteTo( tree );
      RefFinal_ety.WriteTo( tree );
      RefFinal_sumet.WriteTo( tree );
      RefFinal_etx_CentralReg.WriteTo( tree );
      RefFinal_ety_CentralReg.WriteTo( tree );
      RefFinal_sumet_CentralReg.WriteTo( tree );
      RefFinal_phi_CentralReg.WriteTo( tree );
      RefFinal_etx_EndcapRegion.WriteTo( tree );
      RefFinal_ety_EndcapRegion.WriteTo( tree );
      RefFinal_sumet_EndcapRegion.WriteTo( tree );
      RefFinal_phi_EndcapRegion.WriteTo( tree );
      RefFinal_etx_ForwardReg.WriteTo( tree );
      RefFinal_ety_ForwardReg.WriteTo( tree );
      RefFinal_sumet_ForwardReg.WriteTo( tree );
      RefFinal_phi_ForwardReg.WriteTo( tree );
      STVF_RefFinal_etx.WriteTo( tree );
      STVF_RefFinal_ety.WriteTo( tree );
      STVF_RefFinal_sumet.WriteTo( tree );
      STVF_RefFinal_etx_CentralReg.WriteTo( tree );
      STVF_RefFinal_ety_CentralReg.WriteTo( tree );
      STVF_RefFinal_sumet_CentralReg.WriteTo( tree );
      STVF_RefFinal_phi_CentralReg.WriteTo( tree );
      STVF_RefFinal_etx_EndcapRegion.WriteTo( tree );
      STVF_RefFinal_ety_EndcapRegion.WriteTo( tree );
      STVF_RefFinal_sumet_EndcapRegion.WriteTo( tree );
      STVF_RefFinal_phi_EndcapRegion.WriteTo( tree );
      STVF_RefFinal_etx_ForwardReg.WriteTo( tree );
      STVF_RefFinal_ety_ForwardReg.WriteTo( tree );
      STVF_RefFinal_sumet_ForwardReg.WriteTo( tree );
      STVF_RefFinal_phi_ForwardReg.WriteTo( tree );
      RefJet_etx.WriteTo( tree );
      RefJet_ety.WriteTo( tree );
      RefJet_sumet.WriteTo( tree );
      RefJet_etx_CentralReg.WriteTo( tree );
      RefJet_ety_CentralReg.WriteTo( tree );
      RefJet_sumet_CentralReg.WriteTo( tree );
      RefJet_phi_CentralReg.WriteTo( tree );
      RefJet_etx_EndcapRegion.WriteTo( tree );
      RefJet_ety_EndcapRegion.WriteTo( tree );
      RefJet_sumet_EndcapRegion.WriteTo( tree );
      RefJet_phi_EndcapRegion.WriteTo( tree );
      RefJet_etx_ForwardReg.WriteTo( tree );
      RefJet_ety_ForwardReg.WriteTo( tree );
      RefJet_sumet_ForwardReg.WriteTo( tree );
      RefJet_phi_ForwardReg.WriteTo( tree );
      STVF_RefJet_etx.WriteTo( tree );
      STVF_RefJet_ety.WriteTo( tree );
      STVF_RefJet_sumet.WriteTo( tree );
      STVF_RefJet_etx_CentralReg.WriteTo( tree );
      STVF_RefJet_ety_CentralReg.WriteTo( tree );
      STVF_RefJet_sumet_CentralReg.WriteTo( tree );
      STVF_RefJet_phi_CentralReg.WriteTo( tree );
      STVF_RefJet_etx_EndcapRegion.WriteTo( tree );
      STVF_RefJet_ety_EndcapRegion.WriteTo( tree );
      STVF_RefJet_sumet_EndcapRegion.WriteTo( tree );
      STVF_RefJet_phi_EndcapRegion.WriteTo( tree );
      STVF_RefJet_etx_ForwardReg.WriteTo( tree );
      STVF_RefJet_ety_ForwardReg.WriteTo( tree );
      STVF_RefJet_sumet_ForwardReg.WriteTo( tree );
      STVF_RefJet_phi_ForwardReg.WriteTo( tree );
      RefEle_etx.WriteTo( tree );
      RefEle_ety.WriteTo( tree );
      RefEle_sumet.WriteTo( tree );
      RefEle_etx_CentralReg.WriteTo( tree );
      RefEle_ety_CentralReg.WriteTo( tree );
      RefEle_sumet_CentralReg.WriteTo( tree );
      RefEle_phi_CentralReg.WriteTo( tree );
      RefEle_etx_EndcapRegion.WriteTo( tree );
      RefEle_ety_EndcapRegion.WriteTo( tree );
      RefEle_sumet_EndcapRegion.WriteTo( tree );
      RefEle_phi_EndcapRegion.WriteTo( tree );
      RefEle_etx_ForwardReg.WriteTo( tree );
      RefEle_ety_ForwardReg.WriteTo( tree );
      RefEle_sumet_ForwardReg.WriteTo( tree );
      RefEle_phi_ForwardReg.WriteTo( tree );
      STVF_RefEle_etx.WriteTo( tree );
      STVF_RefEle_ety.WriteTo( tree );
      STVF_RefEle_sumet.WriteTo( tree );
      STVF_RefEle_etx_CentralReg.WriteTo( tree );
      STVF_RefEle_ety_CentralReg.WriteTo( tree );
      STVF_RefEle_sumet_CentralReg.WriteTo( tree );
      STVF_RefEle_phi_CentralReg.WriteTo( tree );
      STVF_RefEle_etx_EndcapRegion.WriteTo( tree );
      STVF_RefEle_ety_EndcapRegion.WriteTo( tree );
      STVF_RefEle_sumet_EndcapRegion.WriteTo( tree );
      STVF_RefEle_phi_EndcapRegion.WriteTo( tree );
      STVF_RefEle_etx_ForwardReg.WriteTo( tree );
      STVF_RefEle_ety_ForwardReg.WriteTo( tree );
      STVF_RefEle_sumet_ForwardReg.WriteTo( tree );
      STVF_RefEle_phi_ForwardReg.WriteTo( tree );
      Muon_Total_Staco_etx.WriteTo( tree );
      Muon_Total_Staco_ety.WriteTo( tree );
      Muon_Total_Staco_sumet.WriteTo( tree );
      Muon_Total_Staco_etx_CentralReg.WriteTo( tree );
      Muon_Total_Staco_ety_CentralReg.WriteTo( tree );
      Muon_Total_Staco_sumet_CentralReg.WriteTo( tree );
      Muon_Total_Staco_phi_CentralReg.WriteTo( tree );
      Muon_Total_Staco_etx_EndcapRegion.WriteTo( tree );
      Muon_Total_Staco_ety_EndcapRegion.WriteTo( tree );
      Muon_Total_Staco_sumet_EndcapRegion.WriteTo( tree );
      Muon_Total_Staco_phi_EndcapRegion.WriteTo( tree );
      Muon_Total_Staco_etx_ForwardReg.WriteTo( tree );
      Muon_Total_Staco_ety_ForwardReg.WriteTo( tree );
      Muon_Total_Staco_sumet_ForwardReg.WriteTo( tree );
      Muon_Total_Staco_phi_ForwardReg.WriteTo( tree );
      STVF_Muon_Total_Staco_etx.WriteTo( tree );
      STVF_Muon_Total_Staco_ety.WriteTo( tree );
      STVF_Muon_Total_Staco_sumet.WriteTo( tree );
      STVF_Muon_Total_Staco_etx_CentralReg.WriteTo( tree );
      STVF_Muon_Total_Staco_ety_CentralReg.WriteTo( tree );
      STVF_Muon_Total_Staco_sumet_CentralReg.WriteTo( tree );
      STVF_Muon_Total_Staco_phi_CentralReg.WriteTo( tree );
      STVF_Muon_Total_Staco_etx_EndcapRegion.WriteTo( tree );
      STVF_Muon_Total_Staco_ety_EndcapRegion.WriteTo( tree );
      STVF_Muon_Total_Staco_sumet_EndcapRegion.WriteTo( tree );
      STVF_Muon_Total_Staco_phi_EndcapRegion.WriteTo( tree );
      STVF_Muon_Total_Staco_etx_ForwardReg.WriteTo( tree );
      STVF_Muon_Total_Staco_ety_ForwardReg.WriteTo( tree );
      STVF_Muon_Total_Staco_sumet_ForwardReg.WriteTo( tree );
      STVF_Muon_Total_Staco_phi_ForwardReg.WriteTo( tree );
      Muon_Isol_Staco_etx.WriteTo( tree );
      Muon_Isol_Staco_ety.WriteTo( tree );
      Muon_Isol_Staco_sumet.WriteTo( tree );
      Muon_Isol_Staco_etx_CentralReg.WriteTo( tree );
      Muon_Isol_Staco_ety_CentralReg.WriteTo( tree );
      Muon_Isol_Staco_sumet_CentralReg.WriteTo( tree );
      Muon_Isol_Staco_phi_CentralReg.WriteTo( tree );
      Muon_Isol_Staco_etx_EndcapRegion.WriteTo( tree );
      Muon_Isol_Staco_ety_EndcapRegion.WriteTo( tree );
      Muon_Isol_Staco_sumet_EndcapRegion.WriteTo( tree );
      Muon_Isol_Staco_phi_EndcapRegion.WriteTo( tree );
      Muon_Isol_Staco_etx_ForwardReg.WriteTo( tree );
      Muon_Isol_Staco_ety_ForwardReg.WriteTo( tree );
      Muon_Isol_Staco_sumet_ForwardReg.WriteTo( tree );
      Muon_Isol_Staco_phi_ForwardReg.WriteTo( tree );
      STVF_Muon_Isol_Staco_etx.WriteTo( tree );
      STVF_Muon_Isol_Staco_ety.WriteTo( tree );
      STVF_Muon_Isol_Staco_sumet.WriteTo( tree );
      STVF_Muon_Isol_Staco_etx_CentralReg.WriteTo( tree );
      STVF_Muon_Isol_Staco_ety_CentralReg.WriteTo( tree );
      STVF_Muon_Isol_Staco_sumet_CentralReg.WriteTo( tree );
      STVF_Muon_Isol_Staco_phi_CentralReg.WriteTo( tree );
      STVF_Muon_Isol_Staco_etx_EndcapRegion.WriteTo( tree );
      STVF_Muon_Isol_Staco_ety_EndcapRegion.WriteTo( tree );
      STVF_Muon_Isol_Staco_sumet_EndcapRegion.WriteTo( tree );
      STVF_Muon_Isol_Staco_phi_EndcapRegion.WriteTo( tree );
      STVF_Muon_Isol_Staco_etx_ForwardReg.WriteTo( tree );
      STVF_Muon_Isol_Staco_ety_ForwardReg.WriteTo( tree );
      STVF_Muon_Isol_Staco_sumet_ForwardReg.WriteTo( tree );
      STVF_Muon_Isol_Staco_phi_ForwardReg.WriteTo( tree );
      Muon_NonIsol_Staco_etx.WriteTo( tree );
      Muon_NonIsol_Staco_ety.WriteTo( tree );
      Muon_NonIsol_Staco_sumet.WriteTo( tree );
      Muon_NonIsol_Staco_etx_CentralReg.WriteTo( tree );
      Muon_NonIsol_Staco_ety_CentralReg.WriteTo( tree );
      Muon_NonIsol_Staco_sumet_CentralReg.WriteTo( tree );
      Muon_NonIsol_Staco_phi_CentralReg.WriteTo( tree );
      Muon_NonIsol_Staco_etx_EndcapRegion.WriteTo( tree );
      Muon_NonIsol_Staco_ety_EndcapRegion.WriteTo( tree );
      Muon_NonIsol_Staco_sumet_EndcapRegion.WriteTo( tree );
      Muon_NonIsol_Staco_phi_EndcapRegion.WriteTo( tree );
      Muon_NonIsol_Staco_etx_ForwardReg.WriteTo( tree );
      Muon_NonIsol_Staco_ety_ForwardReg.WriteTo( tree );
      Muon_NonIsol_Staco_sumet_ForwardReg.WriteTo( tree );
      Muon_NonIsol_Staco_phi_ForwardReg.WriteTo( tree );
      STVF_Muon_NonIsol_Staco_etx.WriteTo( tree );
      STVF_Muon_NonIsol_Staco_ety.WriteTo( tree );
      STVF_Muon_NonIsol_Staco_sumet.WriteTo( tree );
      STVF_Muon_NonIsol_Staco_etx_CentralReg.WriteTo( tree );
      STVF_Muon_NonIsol_Staco_ety_CentralReg.WriteTo( tree );
      STVF_Muon_NonIsol_Staco_sumet_CentralReg.WriteTo( tree );
      STVF_Muon_NonIsol_Staco_phi_CentralReg.WriteTo( tree );
      STVF_Muon_NonIsol_Staco_etx_EndcapRegion.WriteTo( tree );
      STVF_Muon_NonIsol_Staco_ety_EndcapRegion.WriteTo( tree );
      STVF_Muon_NonIsol_Staco_sumet_EndcapRegion.WriteTo( tree );
      STVF_Muon_NonIsol_Staco_phi_EndcapRegion.WriteTo( tree );
      STVF_Muon_NonIsol_Staco_etx_ForwardReg.WriteTo( tree );
      STVF_Muon_NonIsol_Staco_ety_ForwardReg.WriteTo( tree );
      STVF_Muon_NonIsol_Staco_sumet_ForwardReg.WriteTo( tree );
      STVF_Muon_NonIsol_Staco_phi_ForwardReg.WriteTo( tree );
      CellOut_etx.WriteTo( tree );
      CellOut_ety.WriteTo( tree );
      CellOut_sumet.WriteTo( tree );
      CellOut_etx_CentralReg.WriteTo( tree );
      CellOut_ety_CentralReg.WriteTo( tree );
      CellOut_sumet_CentralReg.WriteTo( tree );
      CellOut_phi_CentralReg.WriteTo( tree );
      CellOut_etx_EndcapRegion.WriteTo( tree );
      CellOut_ety_EndcapRegion.WriteTo( tree );
      CellOut_sumet_EndcapRegion.WriteTo( tree );
      CellOut_phi_EndcapRegion.WriteTo( tree );
      CellOut_etx_ForwardReg.WriteTo( tree );
      CellOut_ety_ForwardReg.WriteTo( tree );
      CellOut_sumet_ForwardReg.WriteTo( tree );
      CellOut_phi_ForwardReg.WriteTo( tree );
      STVF_CellOut_etx.WriteTo( tree );
      STVF_CellOut_ety.WriteTo( tree );
      STVF_CellOut_sumet.WriteTo( tree );
      STVF_CellOut_etx_CentralReg.WriteTo( tree );
      STVF_CellOut_ety_CentralReg.WriteTo( tree );
      STVF_CellOut_sumet_CentralReg.WriteTo( tree );
      STVF_CellOut_phi_CentralReg.WriteTo( tree );
      STVF_CellOut_etx_EndcapRegion.WriteTo( tree );
      STVF_CellOut_ety_EndcapRegion.WriteTo( tree );
      STVF_CellOut_sumet_EndcapRegion.WriteTo( tree );
      STVF_CellOut_phi_EndcapRegion.WriteTo( tree );
      STVF_CellOut_etx_ForwardReg.WriteTo( tree );
      STVF_CellOut_ety_ForwardReg.WriteTo( tree );
      STVF_CellOut_sumet_ForwardReg.WriteTo( tree );
      STVF_CellOut_phi_ForwardReg.WriteTo( tree );
      Muon_Isol_Muid_etx.WriteTo( tree );
      Muon_Isol_Muid_ety.WriteTo( tree );
      Muon_Isol_Muid_sumet.WriteTo( tree );
      Muon_Isol_Muid_etx_CentralReg.WriteTo( tree );
      Muon_Isol_Muid_ety_CentralReg.WriteTo( tree );
      Muon_Isol_Muid_sumet_CentralReg.WriteTo( tree );
      Muon_Isol_Muid_phi_CentralReg.WriteTo( tree );
      Muon_Isol_Muid_etx_EndcapRegion.WriteTo( tree );
      Muon_Isol_Muid_ety_EndcapRegion.WriteTo( tree );
      Muon_Isol_Muid_sumet_EndcapRegion.WriteTo( tree );
      Muon_Isol_Muid_phi_EndcapRegion.WriteTo( tree );
      Muon_Isol_Muid_etx_ForwardReg.WriteTo( tree );
      Muon_Isol_Muid_ety_ForwardReg.WriteTo( tree );
      Muon_Isol_Muid_sumet_ForwardReg.WriteTo( tree );
      Muon_Isol_Muid_phi_ForwardReg.WriteTo( tree );
      STVF_Muon_Isol_Muid_etx.WriteTo( tree );
      STVF_Muon_Isol_Muid_ety.WriteTo( tree );
      STVF_Muon_Isol_Muid_sumet.WriteTo( tree );
      STVF_Muon_Isol_Muid_etx_CentralReg.WriteTo( tree );
      STVF_Muon_Isol_Muid_ety_CentralReg.WriteTo( tree );
      STVF_Muon_Isol_Muid_sumet_CentralReg.WriteTo( tree );
      STVF_Muon_Isol_Muid_phi_CentralReg.WriteTo( tree );
      STVF_Muon_Isol_Muid_etx_EndcapRegion.WriteTo( tree );
      STVF_Muon_Isol_Muid_ety_EndcapRegion.WriteTo( tree );
      STVF_Muon_Isol_Muid_sumet_EndcapRegion.WriteTo( tree );
      STVF_Muon_Isol_Muid_phi_EndcapRegion.WriteTo( tree );
      STVF_Muon_Isol_Muid_etx_ForwardReg.WriteTo( tree );
      STVF_Muon_Isol_Muid_ety_ForwardReg.WriteTo( tree );
      STVF_Muon_Isol_Muid_sumet_ForwardReg.WriteTo( tree );
      STVF_Muon_Isol_Muid_phi_ForwardReg.WriteTo( tree );
      Muon_NonIsol_Muid_etx.WriteTo( tree );
      Muon_NonIsol_Muid_ety.WriteTo( tree );
      Muon_NonIsol_Muid_sumet.WriteTo( tree );
      Muon_NonIsol_Muid_etx_CentralReg.WriteTo( tree );
      Muon_NonIsol_Muid_ety_CentralReg.WriteTo( tree );
      Muon_NonIsol_Muid_sumet_CentralReg.WriteTo( tree );
      Muon_NonIsol_Muid_phi_CentralReg.WriteTo( tree );
      Muon_NonIsol_Muid_etx_EndcapRegion.WriteTo( tree );
      Muon_NonIsol_Muid_ety_EndcapRegion.WriteTo( tree );
      Muon_NonIsol_Muid_sumet_EndcapRegion.WriteTo( tree );
      Muon_NonIsol_Muid_phi_EndcapRegion.WriteTo( tree );
      Muon_NonIsol_Muid_etx_ForwardReg.WriteTo( tree );
      Muon_NonIsol_Muid_ety_ForwardReg.WriteTo( tree );
      Muon_NonIsol_Muid_sumet_ForwardReg.WriteTo( tree );
      Muon_NonIsol_Muid_phi_ForwardReg.WriteTo( tree );
      STVF_Muon_NonIsol_Muid_etx.WriteTo( tree );
      STVF_Muon_NonIsol_Muid_ety.WriteTo( tree );
      STVF_Muon_NonIsol_Muid_sumet.WriteTo( tree );
      STVF_Muon_NonIsol_Muid_etx_CentralReg.WriteTo( tree );
      STVF_Muon_NonIsol_Muid_ety_CentralReg.WriteTo( tree );
      STVF_Muon_NonIsol_Muid_sumet_CentralReg.WriteTo( tree );
      STVF_Muon_NonIsol_Muid_phi_CentralReg.WriteTo( tree );
      STVF_Muon_NonIsol_Muid_etx_EndcapRegion.WriteTo( tree );
      STVF_Muon_NonIsol_Muid_ety_EndcapRegion.WriteTo( tree );
      STVF_Muon_NonIsol_Muid_sumet_EndcapRegion.WriteTo( tree );
      STVF_Muon_NonIsol_Muid_phi_EndcapRegion.WriteTo( tree );
      STVF_Muon_NonIsol_Muid_etx_ForwardReg.WriteTo( tree );
      STVF_Muon_NonIsol_Muid_ety_ForwardReg.WriteTo( tree );
      STVF_Muon_NonIsol_Muid_sumet_ForwardReg.WriteTo( tree );
      STVF_Muon_NonIsol_Muid_phi_ForwardReg.WriteTo( tree );
      Muon_Total_Muid_etx.WriteTo( tree );
      Muon_Total_Muid_ety.WriteTo( tree );
      Muon_Total_Muid_sumet.WriteTo( tree );
      Muon_Total_Muid_etx_CentralReg.WriteTo( tree );
      Muon_Total_Muid_ety_CentralReg.WriteTo( tree );
      Muon_Total_Muid_sumet_CentralReg.WriteTo( tree );
      Muon_Total_Muid_phi_CentralReg.WriteTo( tree );
      Muon_Total_Muid_etx_EndcapRegion.WriteTo( tree );
      Muon_Total_Muid_ety_EndcapRegion.WriteTo( tree );
      Muon_Total_Muid_sumet_EndcapRegion.WriteTo( tree );
      Muon_Total_Muid_phi_EndcapRegion.WriteTo( tree );
      Muon_Total_Muid_etx_ForwardReg.WriteTo( tree );
      Muon_Total_Muid_ety_ForwardReg.WriteTo( tree );
      Muon_Total_Muid_sumet_ForwardReg.WriteTo( tree );
      Muon_Total_Muid_phi_ForwardReg.WriteTo( tree );
      STVF_Muon_Total_Muid_etx.WriteTo( tree );
      STVF_Muon_Total_Muid_ety.WriteTo( tree );
      STVF_Muon_Total_Muid_sumet.WriteTo( tree );
      STVF_Muon_Total_Muid_etx_CentralReg.WriteTo( tree );
      STVF_Muon_Total_Muid_ety_CentralReg.WriteTo( tree );
      STVF_Muon_Total_Muid_sumet_CentralReg.WriteTo( tree );
      STVF_Muon_Total_Muid_phi_CentralReg.WriteTo( tree );
      STVF_Muon_Total_Muid_etx_EndcapRegion.WriteTo( tree );
      STVF_Muon_Total_Muid_ety_EndcapRegion.WriteTo( tree );
      STVF_Muon_Total_Muid_sumet_EndcapRegion.WriteTo( tree );
      STVF_Muon_Total_Muid_phi_EndcapRegion.WriteTo( tree );
      STVF_Muon_Total_Muid_etx_ForwardReg.WriteTo( tree );
      STVF_Muon_Total_Muid_ety_ForwardReg.WriteTo( tree );
      STVF_Muon_Total_Muid_sumet_ForwardReg.WriteTo( tree );
      STVF_Muon_Total_Muid_phi_ForwardReg.WriteTo( tree );
      Track_etx.WriteTo( tree );
      Track_ety.WriteTo( tree );
      Track_sumet.WriteTo( tree );
      Track_etx_CentralReg.WriteTo( tree );
      Track_ety_CentralReg.WriteTo( tree );
      Track_sumet_CentralReg.WriteTo( tree );
      Track_phi_CentralReg.WriteTo( tree );
      Track_etx_EndcapRegion.WriteTo( tree );
      Track_ety_EndcapRegion.WriteTo( tree );
      Track_sumet_EndcapRegion.WriteTo( tree );
      Track_phi_EndcapRegion.WriteTo( tree );
      Track_etx_ForwardReg.WriteTo( tree );
      Track_ety_ForwardReg.WriteTo( tree );
      Track_sumet_ForwardReg.WriteTo( tree );
      Track_phi_ForwardReg.WriteTo( tree );
      STVF_Track_etx.WriteTo( tree );
      STVF_Track_ety.WriteTo( tree );
      STVF_Track_sumet.WriteTo( tree );
      STVF_Track_etx_CentralReg.WriteTo( tree );
      STVF_Track_ety_CentralReg.WriteTo( tree );
      STVF_Track_sumet_CentralReg.WriteTo( tree );
      STVF_Track_phi_CentralReg.WriteTo( tree );
      STVF_Track_etx_EndcapRegion.WriteTo( tree );
      STVF_Track_ety_EndcapRegion.WriteTo( tree );
      STVF_Track_sumet_EndcapRegion.WriteTo( tree );
      STVF_Track_phi_EndcapRegion.WriteTo( tree );
      STVF_Track_etx_ForwardReg.WriteTo( tree );
      STVF_Track_ety_ForwardReg.WriteTo( tree );
      STVF_Track_sumet_ForwardReg.WriteTo( tree );
      STVF_Track_phi_ForwardReg.WriteTo( tree );
      SoftJets_etx.WriteTo( tree );
      SoftJets_ety.WriteTo( tree );
      SoftJets_sumet.WriteTo( tree );
      SoftJets_etx_CentralReg.WriteTo( tree );
      SoftJets_ety_CentralReg.WriteTo( tree );
      SoftJets_sumet_CentralReg.WriteTo( tree );
      SoftJets_phi_CentralReg.WriteTo( tree );
      SoftJets_etx_EndcapRegion.WriteTo( tree );
      SoftJets_ety_EndcapRegion.WriteTo( tree );
      SoftJets_sumet_EndcapRegion.WriteTo( tree );
      SoftJets_phi_EndcapRegion.WriteTo( tree );
      SoftJets_etx_ForwardReg.WriteTo( tree );
      SoftJets_ety_ForwardReg.WriteTo( tree );
      SoftJets_sumet_ForwardReg.WriteTo( tree );
      SoftJets_phi_ForwardReg.WriteTo( tree );
      STVF_SoftJets_etx.WriteTo( tree );
      STVF_SoftJets_ety.WriteTo( tree );
      STVF_SoftJets_sumet.WriteTo( tree );
      STVF_SoftJets_etx_CentralReg.WriteTo( tree );
      STVF_SoftJets_ety_CentralReg.WriteTo( tree );
      STVF_SoftJets_sumet_CentralReg.WriteTo( tree );
      STVF_SoftJets_phi_CentralReg.WriteTo( tree );
      STVF_SoftJets_etx_EndcapRegion.WriteTo( tree );
      STVF_SoftJets_ety_EndcapRegion.WriteTo( tree );
      STVF_SoftJets_sumet_EndcapRegion.WriteTo( tree );
      STVF_SoftJets_phi_EndcapRegion.WriteTo( tree );
      STVF_SoftJets_etx_ForwardReg.WriteTo( tree );
      STVF_SoftJets_ety_ForwardReg.WriteTo( tree );
      STVF_SoftJets_sumet_ForwardReg.WriteTo( tree );
      STVF_SoftJets_phi_ForwardReg.WriteTo( tree );
      RefMuon_etx.WriteTo( tree );
      RefMuon_ety.WriteTo( tree );
      RefMuon_sumet.WriteTo( tree );
      RefMuon_etx_CentralReg.WriteTo( tree );
      RefMuon_ety_CentralReg.WriteTo( tree );
      RefMuon_sumet_CentralReg.WriteTo( tree );
      RefMuon_phi_CentralReg.WriteTo( tree );
      RefMuon_etx_EndcapRegion.WriteTo( tree );
      RefMuon_ety_EndcapRegion.WriteTo( tree );
      RefMuon_sumet_EndcapRegion.WriteTo( tree );
      RefMuon_phi_EndcapRegion.WriteTo( tree );
      RefMuon_etx_ForwardReg.WriteTo( tree );
      RefMuon_ety_ForwardReg.WriteTo( tree );
      RefMuon_sumet_ForwardReg.WriteTo( tree );
      RefMuon_phi_ForwardReg.WriteTo( tree );
      STVF_RefMuon_etx.WriteTo( tree );
      STVF_RefMuon_ety.WriteTo( tree );
      STVF_RefMuon_sumet.WriteTo( tree );
      STVF_RefMuon_etx_CentralReg.WriteTo( tree );
      STVF_RefMuon_ety_CentralReg.WriteTo( tree );
      STVF_RefMuon_sumet_CentralReg.WriteTo( tree );
      STVF_RefMuon_phi_CentralReg.WriteTo( tree );
      STVF_RefMuon_etx_EndcapRegion.WriteTo( tree );
      STVF_RefMuon_ety_EndcapRegion.WriteTo( tree );
      STVF_RefMuon_sumet_EndcapRegion.WriteTo( tree );
      STVF_RefMuon_phi_EndcapRegion.WriteTo( tree );
      STVF_RefMuon_etx_ForwardReg.WriteTo( tree );
      STVF_RefMuon_ety_ForwardReg.WriteTo( tree );
      STVF_RefMuon_sumet_ForwardReg.WriteTo( tree );
      STVF_RefMuon_phi_ForwardReg.WriteTo( tree );
      MuonBoy_etx.WriteTo( tree );
      MuonBoy_ety.WriteTo( tree );
      MuonBoy_sumet.WriteTo( tree );
      MuonBoy_etx_CentralReg.WriteTo( tree );
      MuonBoy_ety_CentralReg.WriteTo( tree );
      MuonBoy_sumet_CentralReg.WriteTo( tree );
      MuonBoy_phi_CentralReg.WriteTo( tree );
      MuonBoy_etx_EndcapRegion.WriteTo( tree );
      MuonBoy_ety_EndcapRegion.WriteTo( tree );
      MuonBoy_sumet_EndcapRegion.WriteTo( tree );
      MuonBoy_phi_EndcapRegion.WriteTo( tree );
      MuonBoy_etx_ForwardReg.WriteTo( tree );
      MuonBoy_ety_ForwardReg.WriteTo( tree );
      MuonBoy_sumet_ForwardReg.WriteTo( tree );
      MuonBoy_phi_ForwardReg.WriteTo( tree );
      STVF_MuonBoy_etx.WriteTo( tree );
      STVF_MuonBoy_ety.WriteTo( tree );
      STVF_MuonBoy_sumet.WriteTo( tree );
      STVF_MuonBoy_etx_CentralReg.WriteTo( tree );
      STVF_MuonBoy_ety_CentralReg.WriteTo( tree );
      STVF_MuonBoy_sumet_CentralReg.WriteTo( tree );
      STVF_MuonBoy_phi_CentralReg.WriteTo( tree );
      STVF_MuonBoy_etx_EndcapRegion.WriteTo( tree );
      STVF_MuonBoy_ety_EndcapRegion.WriteTo( tree );
      STVF_MuonBoy_sumet_EndcapRegion.WriteTo( tree );
      STVF_MuonBoy_phi_EndcapRegion.WriteTo( tree );
      STVF_MuonBoy_etx_ForwardReg.WriteTo( tree );
      STVF_MuonBoy_ety_ForwardReg.WriteTo( tree );
      STVF_MuonBoy_sumet_ForwardReg.WriteTo( tree );
      STVF_MuonBoy_phi_ForwardReg.WriteTo( tree );
      STVF_CellOut_Track_etx.WriteTo( tree );
      STVF_CellOut_Track_ety.WriteTo( tree );
      STVF_CellOut_Track_sumet.WriteTo( tree );
      STVF_CellOut_Track_etx_CentralReg.WriteTo( tree );
      STVF_CellOut_Track_ety_CentralReg.WriteTo( tree );
      STVF_CellOut_Track_sumet_CentralReg.WriteTo( tree );
      STVF_CellOut_Track_phi_CentralReg.WriteTo( tree );
      STVF_CellOut_Track_etx_EndcapRegion.WriteTo( tree );
      STVF_CellOut_Track_ety_EndcapRegion.WriteTo( tree );
      STVF_CellOut_Track_sumet_EndcapRegion.WriteTo( tree );
      STVF_CellOut_Track_phi_EndcapRegion.WriteTo( tree );
      STVF_CellOut_Track_etx_ForwardReg.WriteTo( tree );
      STVF_CellOut_Track_ety_ForwardReg.WriteTo( tree );
      STVF_CellOut_Track_sumet_ForwardReg.WriteTo( tree );
      STVF_CellOut_Track_phi_ForwardReg.WriteTo( tree );
      STVF_CellOut_TrackPV_etx.WriteTo( tree );
      STVF_CellOut_TrackPV_ety.WriteTo( tree );
      STVF_CellOut_TrackPV_sumet.WriteTo( tree );
      STVF_CellOut_TrackPV_etx_CentralReg.WriteTo( tree );
      STVF_CellOut_TrackPV_ety_CentralReg.WriteTo( tree );
      STVF_CellOut_TrackPV_sumet_CentralReg.WriteTo( tree );
      STVF_CellOut_TrackPV_phi_CentralReg.WriteTo( tree );
      STVF_CellOut_TrackPV_etx_EndcapRegion.WriteTo( tree );
      STVF_CellOut_TrackPV_ety_EndcapRegion.WriteTo( tree );
      STVF_CellOut_TrackPV_sumet_EndcapRegion.WriteTo( tree );
      STVF_CellOut_TrackPV_phi_EndcapRegion.WriteTo( tree );
      STVF_CellOut_TrackPV_etx_ForwardReg.WriteTo( tree );
      STVF_CellOut_TrackPV_ety_ForwardReg.WriteTo( tree );
      STVF_CellOut_TrackPV_sumet_ForwardReg.WriteTo( tree );
      STVF_CellOut_TrackPV_phi_ForwardReg.WriteTo( tree );
      STVF_CellOutCorr_etx.WriteTo( tree );
      STVF_CellOutCorr_ety.WriteTo( tree );
      STVF_CellOutCorr_sumet.WriteTo( tree );
      STVF_CellOutCorr_etx_CentralReg.WriteTo( tree );
      STVF_CellOutCorr_ety_CentralReg.WriteTo( tree );
      STVF_CellOutCorr_sumet_CentralReg.WriteTo( tree );
      STVF_CellOutCorr_phi_CentralReg.WriteTo( tree );
      STVF_CellOutCorr_etx_EndcapRegion.WriteTo( tree );
      STVF_CellOutCorr_ety_EndcapRegion.WriteTo( tree );
      STVF_CellOutCorr_sumet_EndcapRegion.WriteTo( tree );
      STVF_CellOutCorr_phi_EndcapRegion.WriteTo( tree );
      STVF_CellOutCorr_etx_ForwardReg.WriteTo( tree );
      STVF_CellOutCorr_ety_ForwardReg.WriteTo( tree );
      STVF_CellOutCorr_sumet_ForwardReg.WriteTo( tree );
      STVF_CellOutCorr_phi_ForwardReg.WriteTo( tree );

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
      if( RefGamma_etx_CentralReg.IsActive() ) RefGamma_etx_CentralReg();
      if( RefGamma_ety_CentralReg.IsActive() ) RefGamma_ety_CentralReg();
      if( RefGamma_sumet_CentralReg.IsActive() ) RefGamma_sumet_CentralReg();
      if( RefGamma_phi_CentralReg.IsActive() ) RefGamma_phi_CentralReg();
      if( RefGamma_etx_EndcapRegion.IsActive() ) RefGamma_etx_EndcapRegion();
      if( RefGamma_ety_EndcapRegion.IsActive() ) RefGamma_ety_EndcapRegion();
      if( RefGamma_sumet_EndcapRegion.IsActive() ) RefGamma_sumet_EndcapRegion();
      if( RefGamma_phi_EndcapRegion.IsActive() ) RefGamma_phi_EndcapRegion();
      if( RefGamma_etx_ForwardReg.IsActive() ) RefGamma_etx_ForwardReg();
      if( RefGamma_ety_ForwardReg.IsActive() ) RefGamma_ety_ForwardReg();
      if( RefGamma_sumet_ForwardReg.IsActive() ) RefGamma_sumet_ForwardReg();
      if( RefGamma_phi_ForwardReg.IsActive() ) RefGamma_phi_ForwardReg();
      if( STVF_RefGamma_etx.IsActive() ) STVF_RefGamma_etx();
      if( STVF_RefGamma_ety.IsActive() ) STVF_RefGamma_ety();
      if( STVF_RefGamma_sumet.IsActive() ) STVF_RefGamma_sumet();
      if( STVF_RefGamma_etx_CentralReg.IsActive() ) STVF_RefGamma_etx_CentralReg();
      if( STVF_RefGamma_ety_CentralReg.IsActive() ) STVF_RefGamma_ety_CentralReg();
      if( STVF_RefGamma_sumet_CentralReg.IsActive() ) STVF_RefGamma_sumet_CentralReg();
      if( STVF_RefGamma_phi_CentralReg.IsActive() ) STVF_RefGamma_phi_CentralReg();
      if( STVF_RefGamma_etx_EndcapRegion.IsActive() ) STVF_RefGamma_etx_EndcapRegion();
      if( STVF_RefGamma_ety_EndcapRegion.IsActive() ) STVF_RefGamma_ety_EndcapRegion();
      if( STVF_RefGamma_sumet_EndcapRegion.IsActive() ) STVF_RefGamma_sumet_EndcapRegion();
      if( STVF_RefGamma_phi_EndcapRegion.IsActive() ) STVF_RefGamma_phi_EndcapRegion();
      if( STVF_RefGamma_etx_ForwardReg.IsActive() ) STVF_RefGamma_etx_ForwardReg();
      if( STVF_RefGamma_ety_ForwardReg.IsActive() ) STVF_RefGamma_ety_ForwardReg();
      if( STVF_RefGamma_sumet_ForwardReg.IsActive() ) STVF_RefGamma_sumet_ForwardReg();
      if( STVF_RefGamma_phi_ForwardReg.IsActive() ) STVF_RefGamma_phi_ForwardReg();
      if( RefFinal_etx.IsActive() ) RefFinal_etx();
      if( RefFinal_ety.IsActive() ) RefFinal_ety();
      if( RefFinal_sumet.IsActive() ) RefFinal_sumet();
      if( RefFinal_etx_CentralReg.IsActive() ) RefFinal_etx_CentralReg();
      if( RefFinal_ety_CentralReg.IsActive() ) RefFinal_ety_CentralReg();
      if( RefFinal_sumet_CentralReg.IsActive() ) RefFinal_sumet_CentralReg();
      if( RefFinal_phi_CentralReg.IsActive() ) RefFinal_phi_CentralReg();
      if( RefFinal_etx_EndcapRegion.IsActive() ) RefFinal_etx_EndcapRegion();
      if( RefFinal_ety_EndcapRegion.IsActive() ) RefFinal_ety_EndcapRegion();
      if( RefFinal_sumet_EndcapRegion.IsActive() ) RefFinal_sumet_EndcapRegion();
      if( RefFinal_phi_EndcapRegion.IsActive() ) RefFinal_phi_EndcapRegion();
      if( RefFinal_etx_ForwardReg.IsActive() ) RefFinal_etx_ForwardReg();
      if( RefFinal_ety_ForwardReg.IsActive() ) RefFinal_ety_ForwardReg();
      if( RefFinal_sumet_ForwardReg.IsActive() ) RefFinal_sumet_ForwardReg();
      if( RefFinal_phi_ForwardReg.IsActive() ) RefFinal_phi_ForwardReg();
      if( STVF_RefFinal_etx.IsActive() ) STVF_RefFinal_etx();
      if( STVF_RefFinal_ety.IsActive() ) STVF_RefFinal_ety();
      if( STVF_RefFinal_sumet.IsActive() ) STVF_RefFinal_sumet();
      if( STVF_RefFinal_etx_CentralReg.IsActive() ) STVF_RefFinal_etx_CentralReg();
      if( STVF_RefFinal_ety_CentralReg.IsActive() ) STVF_RefFinal_ety_CentralReg();
      if( STVF_RefFinal_sumet_CentralReg.IsActive() ) STVF_RefFinal_sumet_CentralReg();
      if( STVF_RefFinal_phi_CentralReg.IsActive() ) STVF_RefFinal_phi_CentralReg();
      if( STVF_RefFinal_etx_EndcapRegion.IsActive() ) STVF_RefFinal_etx_EndcapRegion();
      if( STVF_RefFinal_ety_EndcapRegion.IsActive() ) STVF_RefFinal_ety_EndcapRegion();
      if( STVF_RefFinal_sumet_EndcapRegion.IsActive() ) STVF_RefFinal_sumet_EndcapRegion();
      if( STVF_RefFinal_phi_EndcapRegion.IsActive() ) STVF_RefFinal_phi_EndcapRegion();
      if( STVF_RefFinal_etx_ForwardReg.IsActive() ) STVF_RefFinal_etx_ForwardReg();
      if( STVF_RefFinal_ety_ForwardReg.IsActive() ) STVF_RefFinal_ety_ForwardReg();
      if( STVF_RefFinal_sumet_ForwardReg.IsActive() ) STVF_RefFinal_sumet_ForwardReg();
      if( STVF_RefFinal_phi_ForwardReg.IsActive() ) STVF_RefFinal_phi_ForwardReg();
      if( RefJet_etx.IsActive() ) RefJet_etx();
      if( RefJet_ety.IsActive() ) RefJet_ety();
      if( RefJet_sumet.IsActive() ) RefJet_sumet();
      if( RefJet_etx_CentralReg.IsActive() ) RefJet_etx_CentralReg();
      if( RefJet_ety_CentralReg.IsActive() ) RefJet_ety_CentralReg();
      if( RefJet_sumet_CentralReg.IsActive() ) RefJet_sumet_CentralReg();
      if( RefJet_phi_CentralReg.IsActive() ) RefJet_phi_CentralReg();
      if( RefJet_etx_EndcapRegion.IsActive() ) RefJet_etx_EndcapRegion();
      if( RefJet_ety_EndcapRegion.IsActive() ) RefJet_ety_EndcapRegion();
      if( RefJet_sumet_EndcapRegion.IsActive() ) RefJet_sumet_EndcapRegion();
      if( RefJet_phi_EndcapRegion.IsActive() ) RefJet_phi_EndcapRegion();
      if( RefJet_etx_ForwardReg.IsActive() ) RefJet_etx_ForwardReg();
      if( RefJet_ety_ForwardReg.IsActive() ) RefJet_ety_ForwardReg();
      if( RefJet_sumet_ForwardReg.IsActive() ) RefJet_sumet_ForwardReg();
      if( RefJet_phi_ForwardReg.IsActive() ) RefJet_phi_ForwardReg();
      if( STVF_RefJet_etx.IsActive() ) STVF_RefJet_etx();
      if( STVF_RefJet_ety.IsActive() ) STVF_RefJet_ety();
      if( STVF_RefJet_sumet.IsActive() ) STVF_RefJet_sumet();
      if( STVF_RefJet_etx_CentralReg.IsActive() ) STVF_RefJet_etx_CentralReg();
      if( STVF_RefJet_ety_CentralReg.IsActive() ) STVF_RefJet_ety_CentralReg();
      if( STVF_RefJet_sumet_CentralReg.IsActive() ) STVF_RefJet_sumet_CentralReg();
      if( STVF_RefJet_phi_CentralReg.IsActive() ) STVF_RefJet_phi_CentralReg();
      if( STVF_RefJet_etx_EndcapRegion.IsActive() ) STVF_RefJet_etx_EndcapRegion();
      if( STVF_RefJet_ety_EndcapRegion.IsActive() ) STVF_RefJet_ety_EndcapRegion();
      if( STVF_RefJet_sumet_EndcapRegion.IsActive() ) STVF_RefJet_sumet_EndcapRegion();
      if( STVF_RefJet_phi_EndcapRegion.IsActive() ) STVF_RefJet_phi_EndcapRegion();
      if( STVF_RefJet_etx_ForwardReg.IsActive() ) STVF_RefJet_etx_ForwardReg();
      if( STVF_RefJet_ety_ForwardReg.IsActive() ) STVF_RefJet_ety_ForwardReg();
      if( STVF_RefJet_sumet_ForwardReg.IsActive() ) STVF_RefJet_sumet_ForwardReg();
      if( STVF_RefJet_phi_ForwardReg.IsActive() ) STVF_RefJet_phi_ForwardReg();
      if( RefEle_etx.IsActive() ) RefEle_etx();
      if( RefEle_ety.IsActive() ) RefEle_ety();
      if( RefEle_sumet.IsActive() ) RefEle_sumet();
      if( RefEle_etx_CentralReg.IsActive() ) RefEle_etx_CentralReg();
      if( RefEle_ety_CentralReg.IsActive() ) RefEle_ety_CentralReg();
      if( RefEle_sumet_CentralReg.IsActive() ) RefEle_sumet_CentralReg();
      if( RefEle_phi_CentralReg.IsActive() ) RefEle_phi_CentralReg();
      if( RefEle_etx_EndcapRegion.IsActive() ) RefEle_etx_EndcapRegion();
      if( RefEle_ety_EndcapRegion.IsActive() ) RefEle_ety_EndcapRegion();
      if( RefEle_sumet_EndcapRegion.IsActive() ) RefEle_sumet_EndcapRegion();
      if( RefEle_phi_EndcapRegion.IsActive() ) RefEle_phi_EndcapRegion();
      if( RefEle_etx_ForwardReg.IsActive() ) RefEle_etx_ForwardReg();
      if( RefEle_ety_ForwardReg.IsActive() ) RefEle_ety_ForwardReg();
      if( RefEle_sumet_ForwardReg.IsActive() ) RefEle_sumet_ForwardReg();
      if( RefEle_phi_ForwardReg.IsActive() ) RefEle_phi_ForwardReg();
      if( STVF_RefEle_etx.IsActive() ) STVF_RefEle_etx();
      if( STVF_RefEle_ety.IsActive() ) STVF_RefEle_ety();
      if( STVF_RefEle_sumet.IsActive() ) STVF_RefEle_sumet();
      if( STVF_RefEle_etx_CentralReg.IsActive() ) STVF_RefEle_etx_CentralReg();
      if( STVF_RefEle_ety_CentralReg.IsActive() ) STVF_RefEle_ety_CentralReg();
      if( STVF_RefEle_sumet_CentralReg.IsActive() ) STVF_RefEle_sumet_CentralReg();
      if( STVF_RefEle_phi_CentralReg.IsActive() ) STVF_RefEle_phi_CentralReg();
      if( STVF_RefEle_etx_EndcapRegion.IsActive() ) STVF_RefEle_etx_EndcapRegion();
      if( STVF_RefEle_ety_EndcapRegion.IsActive() ) STVF_RefEle_ety_EndcapRegion();
      if( STVF_RefEle_sumet_EndcapRegion.IsActive() ) STVF_RefEle_sumet_EndcapRegion();
      if( STVF_RefEle_phi_EndcapRegion.IsActive() ) STVF_RefEle_phi_EndcapRegion();
      if( STVF_RefEle_etx_ForwardReg.IsActive() ) STVF_RefEle_etx_ForwardReg();
      if( STVF_RefEle_ety_ForwardReg.IsActive() ) STVF_RefEle_ety_ForwardReg();
      if( STVF_RefEle_sumet_ForwardReg.IsActive() ) STVF_RefEle_sumet_ForwardReg();
      if( STVF_RefEle_phi_ForwardReg.IsActive() ) STVF_RefEle_phi_ForwardReg();
      if( Muon_Total_Staco_etx.IsActive() ) Muon_Total_Staco_etx();
      if( Muon_Total_Staco_ety.IsActive() ) Muon_Total_Staco_ety();
      if( Muon_Total_Staco_sumet.IsActive() ) Muon_Total_Staco_sumet();
      if( Muon_Total_Staco_etx_CentralReg.IsActive() ) Muon_Total_Staco_etx_CentralReg();
      if( Muon_Total_Staco_ety_CentralReg.IsActive() ) Muon_Total_Staco_ety_CentralReg();
      if( Muon_Total_Staco_sumet_CentralReg.IsActive() ) Muon_Total_Staco_sumet_CentralReg();
      if( Muon_Total_Staco_phi_CentralReg.IsActive() ) Muon_Total_Staco_phi_CentralReg();
      if( Muon_Total_Staco_etx_EndcapRegion.IsActive() ) Muon_Total_Staco_etx_EndcapRegion();
      if( Muon_Total_Staco_ety_EndcapRegion.IsActive() ) Muon_Total_Staco_ety_EndcapRegion();
      if( Muon_Total_Staco_sumet_EndcapRegion.IsActive() ) Muon_Total_Staco_sumet_EndcapRegion();
      if( Muon_Total_Staco_phi_EndcapRegion.IsActive() ) Muon_Total_Staco_phi_EndcapRegion();
      if( Muon_Total_Staco_etx_ForwardReg.IsActive() ) Muon_Total_Staco_etx_ForwardReg();
      if( Muon_Total_Staco_ety_ForwardReg.IsActive() ) Muon_Total_Staco_ety_ForwardReg();
      if( Muon_Total_Staco_sumet_ForwardReg.IsActive() ) Muon_Total_Staco_sumet_ForwardReg();
      if( Muon_Total_Staco_phi_ForwardReg.IsActive() ) Muon_Total_Staco_phi_ForwardReg();
      if( STVF_Muon_Total_Staco_etx.IsActive() ) STVF_Muon_Total_Staco_etx();
      if( STVF_Muon_Total_Staco_ety.IsActive() ) STVF_Muon_Total_Staco_ety();
      if( STVF_Muon_Total_Staco_sumet.IsActive() ) STVF_Muon_Total_Staco_sumet();
      if( STVF_Muon_Total_Staco_etx_CentralReg.IsActive() ) STVF_Muon_Total_Staco_etx_CentralReg();
      if( STVF_Muon_Total_Staco_ety_CentralReg.IsActive() ) STVF_Muon_Total_Staco_ety_CentralReg();
      if( STVF_Muon_Total_Staco_sumet_CentralReg.IsActive() ) STVF_Muon_Total_Staco_sumet_CentralReg();
      if( STVF_Muon_Total_Staco_phi_CentralReg.IsActive() ) STVF_Muon_Total_Staco_phi_CentralReg();
      if( STVF_Muon_Total_Staco_etx_EndcapRegion.IsActive() ) STVF_Muon_Total_Staco_etx_EndcapRegion();
      if( STVF_Muon_Total_Staco_ety_EndcapRegion.IsActive() ) STVF_Muon_Total_Staco_ety_EndcapRegion();
      if( STVF_Muon_Total_Staco_sumet_EndcapRegion.IsActive() ) STVF_Muon_Total_Staco_sumet_EndcapRegion();
      if( STVF_Muon_Total_Staco_phi_EndcapRegion.IsActive() ) STVF_Muon_Total_Staco_phi_EndcapRegion();
      if( STVF_Muon_Total_Staco_etx_ForwardReg.IsActive() ) STVF_Muon_Total_Staco_etx_ForwardReg();
      if( STVF_Muon_Total_Staco_ety_ForwardReg.IsActive() ) STVF_Muon_Total_Staco_ety_ForwardReg();
      if( STVF_Muon_Total_Staco_sumet_ForwardReg.IsActive() ) STVF_Muon_Total_Staco_sumet_ForwardReg();
      if( STVF_Muon_Total_Staco_phi_ForwardReg.IsActive() ) STVF_Muon_Total_Staco_phi_ForwardReg();
      if( Muon_Isol_Staco_etx.IsActive() ) Muon_Isol_Staco_etx();
      if( Muon_Isol_Staco_ety.IsActive() ) Muon_Isol_Staco_ety();
      if( Muon_Isol_Staco_sumet.IsActive() ) Muon_Isol_Staco_sumet();
      if( Muon_Isol_Staco_etx_CentralReg.IsActive() ) Muon_Isol_Staco_etx_CentralReg();
      if( Muon_Isol_Staco_ety_CentralReg.IsActive() ) Muon_Isol_Staco_ety_CentralReg();
      if( Muon_Isol_Staco_sumet_CentralReg.IsActive() ) Muon_Isol_Staco_sumet_CentralReg();
      if( Muon_Isol_Staco_phi_CentralReg.IsActive() ) Muon_Isol_Staco_phi_CentralReg();
      if( Muon_Isol_Staco_etx_EndcapRegion.IsActive() ) Muon_Isol_Staco_etx_EndcapRegion();
      if( Muon_Isol_Staco_ety_EndcapRegion.IsActive() ) Muon_Isol_Staco_ety_EndcapRegion();
      if( Muon_Isol_Staco_sumet_EndcapRegion.IsActive() ) Muon_Isol_Staco_sumet_EndcapRegion();
      if( Muon_Isol_Staco_phi_EndcapRegion.IsActive() ) Muon_Isol_Staco_phi_EndcapRegion();
      if( Muon_Isol_Staco_etx_ForwardReg.IsActive() ) Muon_Isol_Staco_etx_ForwardReg();
      if( Muon_Isol_Staco_ety_ForwardReg.IsActive() ) Muon_Isol_Staco_ety_ForwardReg();
      if( Muon_Isol_Staco_sumet_ForwardReg.IsActive() ) Muon_Isol_Staco_sumet_ForwardReg();
      if( Muon_Isol_Staco_phi_ForwardReg.IsActive() ) Muon_Isol_Staco_phi_ForwardReg();
      if( STVF_Muon_Isol_Staco_etx.IsActive() ) STVF_Muon_Isol_Staco_etx();
      if( STVF_Muon_Isol_Staco_ety.IsActive() ) STVF_Muon_Isol_Staco_ety();
      if( STVF_Muon_Isol_Staco_sumet.IsActive() ) STVF_Muon_Isol_Staco_sumet();
      if( STVF_Muon_Isol_Staco_etx_CentralReg.IsActive() ) STVF_Muon_Isol_Staco_etx_CentralReg();
      if( STVF_Muon_Isol_Staco_ety_CentralReg.IsActive() ) STVF_Muon_Isol_Staco_ety_CentralReg();
      if( STVF_Muon_Isol_Staco_sumet_CentralReg.IsActive() ) STVF_Muon_Isol_Staco_sumet_CentralReg();
      if( STVF_Muon_Isol_Staco_phi_CentralReg.IsActive() ) STVF_Muon_Isol_Staco_phi_CentralReg();
      if( STVF_Muon_Isol_Staco_etx_EndcapRegion.IsActive() ) STVF_Muon_Isol_Staco_etx_EndcapRegion();
      if( STVF_Muon_Isol_Staco_ety_EndcapRegion.IsActive() ) STVF_Muon_Isol_Staco_ety_EndcapRegion();
      if( STVF_Muon_Isol_Staco_sumet_EndcapRegion.IsActive() ) STVF_Muon_Isol_Staco_sumet_EndcapRegion();
      if( STVF_Muon_Isol_Staco_phi_EndcapRegion.IsActive() ) STVF_Muon_Isol_Staco_phi_EndcapRegion();
      if( STVF_Muon_Isol_Staco_etx_ForwardReg.IsActive() ) STVF_Muon_Isol_Staco_etx_ForwardReg();
      if( STVF_Muon_Isol_Staco_ety_ForwardReg.IsActive() ) STVF_Muon_Isol_Staco_ety_ForwardReg();
      if( STVF_Muon_Isol_Staco_sumet_ForwardReg.IsActive() ) STVF_Muon_Isol_Staco_sumet_ForwardReg();
      if( STVF_Muon_Isol_Staco_phi_ForwardReg.IsActive() ) STVF_Muon_Isol_Staco_phi_ForwardReg();
      if( Muon_NonIsol_Staco_etx.IsActive() ) Muon_NonIsol_Staco_etx();
      if( Muon_NonIsol_Staco_ety.IsActive() ) Muon_NonIsol_Staco_ety();
      if( Muon_NonIsol_Staco_sumet.IsActive() ) Muon_NonIsol_Staco_sumet();
      if( Muon_NonIsol_Staco_etx_CentralReg.IsActive() ) Muon_NonIsol_Staco_etx_CentralReg();
      if( Muon_NonIsol_Staco_ety_CentralReg.IsActive() ) Muon_NonIsol_Staco_ety_CentralReg();
      if( Muon_NonIsol_Staco_sumet_CentralReg.IsActive() ) Muon_NonIsol_Staco_sumet_CentralReg();
      if( Muon_NonIsol_Staco_phi_CentralReg.IsActive() ) Muon_NonIsol_Staco_phi_CentralReg();
      if( Muon_NonIsol_Staco_etx_EndcapRegion.IsActive() ) Muon_NonIsol_Staco_etx_EndcapRegion();
      if( Muon_NonIsol_Staco_ety_EndcapRegion.IsActive() ) Muon_NonIsol_Staco_ety_EndcapRegion();
      if( Muon_NonIsol_Staco_sumet_EndcapRegion.IsActive() ) Muon_NonIsol_Staco_sumet_EndcapRegion();
      if( Muon_NonIsol_Staco_phi_EndcapRegion.IsActive() ) Muon_NonIsol_Staco_phi_EndcapRegion();
      if( Muon_NonIsol_Staco_etx_ForwardReg.IsActive() ) Muon_NonIsol_Staco_etx_ForwardReg();
      if( Muon_NonIsol_Staco_ety_ForwardReg.IsActive() ) Muon_NonIsol_Staco_ety_ForwardReg();
      if( Muon_NonIsol_Staco_sumet_ForwardReg.IsActive() ) Muon_NonIsol_Staco_sumet_ForwardReg();
      if( Muon_NonIsol_Staco_phi_ForwardReg.IsActive() ) Muon_NonIsol_Staco_phi_ForwardReg();
      if( STVF_Muon_NonIsol_Staco_etx.IsActive() ) STVF_Muon_NonIsol_Staco_etx();
      if( STVF_Muon_NonIsol_Staco_ety.IsActive() ) STVF_Muon_NonIsol_Staco_ety();
      if( STVF_Muon_NonIsol_Staco_sumet.IsActive() ) STVF_Muon_NonIsol_Staco_sumet();
      if( STVF_Muon_NonIsol_Staco_etx_CentralReg.IsActive() ) STVF_Muon_NonIsol_Staco_etx_CentralReg();
      if( STVF_Muon_NonIsol_Staco_ety_CentralReg.IsActive() ) STVF_Muon_NonIsol_Staco_ety_CentralReg();
      if( STVF_Muon_NonIsol_Staco_sumet_CentralReg.IsActive() ) STVF_Muon_NonIsol_Staco_sumet_CentralReg();
      if( STVF_Muon_NonIsol_Staco_phi_CentralReg.IsActive() ) STVF_Muon_NonIsol_Staco_phi_CentralReg();
      if( STVF_Muon_NonIsol_Staco_etx_EndcapRegion.IsActive() ) STVF_Muon_NonIsol_Staco_etx_EndcapRegion();
      if( STVF_Muon_NonIsol_Staco_ety_EndcapRegion.IsActive() ) STVF_Muon_NonIsol_Staco_ety_EndcapRegion();
      if( STVF_Muon_NonIsol_Staco_sumet_EndcapRegion.IsActive() ) STVF_Muon_NonIsol_Staco_sumet_EndcapRegion();
      if( STVF_Muon_NonIsol_Staco_phi_EndcapRegion.IsActive() ) STVF_Muon_NonIsol_Staco_phi_EndcapRegion();
      if( STVF_Muon_NonIsol_Staco_etx_ForwardReg.IsActive() ) STVF_Muon_NonIsol_Staco_etx_ForwardReg();
      if( STVF_Muon_NonIsol_Staco_ety_ForwardReg.IsActive() ) STVF_Muon_NonIsol_Staco_ety_ForwardReg();
      if( STVF_Muon_NonIsol_Staco_sumet_ForwardReg.IsActive() ) STVF_Muon_NonIsol_Staco_sumet_ForwardReg();
      if( STVF_Muon_NonIsol_Staco_phi_ForwardReg.IsActive() ) STVF_Muon_NonIsol_Staco_phi_ForwardReg();
      if( CellOut_etx.IsActive() ) CellOut_etx();
      if( CellOut_ety.IsActive() ) CellOut_ety();
      if( CellOut_sumet.IsActive() ) CellOut_sumet();
      if( CellOut_etx_CentralReg.IsActive() ) CellOut_etx_CentralReg();
      if( CellOut_ety_CentralReg.IsActive() ) CellOut_ety_CentralReg();
      if( CellOut_sumet_CentralReg.IsActive() ) CellOut_sumet_CentralReg();
      if( CellOut_phi_CentralReg.IsActive() ) CellOut_phi_CentralReg();
      if( CellOut_etx_EndcapRegion.IsActive() ) CellOut_etx_EndcapRegion();
      if( CellOut_ety_EndcapRegion.IsActive() ) CellOut_ety_EndcapRegion();
      if( CellOut_sumet_EndcapRegion.IsActive() ) CellOut_sumet_EndcapRegion();
      if( CellOut_phi_EndcapRegion.IsActive() ) CellOut_phi_EndcapRegion();
      if( CellOut_etx_ForwardReg.IsActive() ) CellOut_etx_ForwardReg();
      if( CellOut_ety_ForwardReg.IsActive() ) CellOut_ety_ForwardReg();
      if( CellOut_sumet_ForwardReg.IsActive() ) CellOut_sumet_ForwardReg();
      if( CellOut_phi_ForwardReg.IsActive() ) CellOut_phi_ForwardReg();
      if( STVF_CellOut_etx.IsActive() ) STVF_CellOut_etx();
      if( STVF_CellOut_ety.IsActive() ) STVF_CellOut_ety();
      if( STVF_CellOut_sumet.IsActive() ) STVF_CellOut_sumet();
      if( STVF_CellOut_etx_CentralReg.IsActive() ) STVF_CellOut_etx_CentralReg();
      if( STVF_CellOut_ety_CentralReg.IsActive() ) STVF_CellOut_ety_CentralReg();
      if( STVF_CellOut_sumet_CentralReg.IsActive() ) STVF_CellOut_sumet_CentralReg();
      if( STVF_CellOut_phi_CentralReg.IsActive() ) STVF_CellOut_phi_CentralReg();
      if( STVF_CellOut_etx_EndcapRegion.IsActive() ) STVF_CellOut_etx_EndcapRegion();
      if( STVF_CellOut_ety_EndcapRegion.IsActive() ) STVF_CellOut_ety_EndcapRegion();
      if( STVF_CellOut_sumet_EndcapRegion.IsActive() ) STVF_CellOut_sumet_EndcapRegion();
      if( STVF_CellOut_phi_EndcapRegion.IsActive() ) STVF_CellOut_phi_EndcapRegion();
      if( STVF_CellOut_etx_ForwardReg.IsActive() ) STVF_CellOut_etx_ForwardReg();
      if( STVF_CellOut_ety_ForwardReg.IsActive() ) STVF_CellOut_ety_ForwardReg();
      if( STVF_CellOut_sumet_ForwardReg.IsActive() ) STVF_CellOut_sumet_ForwardReg();
      if( STVF_CellOut_phi_ForwardReg.IsActive() ) STVF_CellOut_phi_ForwardReg();
      if( Muon_Isol_Muid_etx.IsActive() ) Muon_Isol_Muid_etx();
      if( Muon_Isol_Muid_ety.IsActive() ) Muon_Isol_Muid_ety();
      if( Muon_Isol_Muid_sumet.IsActive() ) Muon_Isol_Muid_sumet();
      if( Muon_Isol_Muid_etx_CentralReg.IsActive() ) Muon_Isol_Muid_etx_CentralReg();
      if( Muon_Isol_Muid_ety_CentralReg.IsActive() ) Muon_Isol_Muid_ety_CentralReg();
      if( Muon_Isol_Muid_sumet_CentralReg.IsActive() ) Muon_Isol_Muid_sumet_CentralReg();
      if( Muon_Isol_Muid_phi_CentralReg.IsActive() ) Muon_Isol_Muid_phi_CentralReg();
      if( Muon_Isol_Muid_etx_EndcapRegion.IsActive() ) Muon_Isol_Muid_etx_EndcapRegion();
      if( Muon_Isol_Muid_ety_EndcapRegion.IsActive() ) Muon_Isol_Muid_ety_EndcapRegion();
      if( Muon_Isol_Muid_sumet_EndcapRegion.IsActive() ) Muon_Isol_Muid_sumet_EndcapRegion();
      if( Muon_Isol_Muid_phi_EndcapRegion.IsActive() ) Muon_Isol_Muid_phi_EndcapRegion();
      if( Muon_Isol_Muid_etx_ForwardReg.IsActive() ) Muon_Isol_Muid_etx_ForwardReg();
      if( Muon_Isol_Muid_ety_ForwardReg.IsActive() ) Muon_Isol_Muid_ety_ForwardReg();
      if( Muon_Isol_Muid_sumet_ForwardReg.IsActive() ) Muon_Isol_Muid_sumet_ForwardReg();
      if( Muon_Isol_Muid_phi_ForwardReg.IsActive() ) Muon_Isol_Muid_phi_ForwardReg();
      if( STVF_Muon_Isol_Muid_etx.IsActive() ) STVF_Muon_Isol_Muid_etx();
      if( STVF_Muon_Isol_Muid_ety.IsActive() ) STVF_Muon_Isol_Muid_ety();
      if( STVF_Muon_Isol_Muid_sumet.IsActive() ) STVF_Muon_Isol_Muid_sumet();
      if( STVF_Muon_Isol_Muid_etx_CentralReg.IsActive() ) STVF_Muon_Isol_Muid_etx_CentralReg();
      if( STVF_Muon_Isol_Muid_ety_CentralReg.IsActive() ) STVF_Muon_Isol_Muid_ety_CentralReg();
      if( STVF_Muon_Isol_Muid_sumet_CentralReg.IsActive() ) STVF_Muon_Isol_Muid_sumet_CentralReg();
      if( STVF_Muon_Isol_Muid_phi_CentralReg.IsActive() ) STVF_Muon_Isol_Muid_phi_CentralReg();
      if( STVF_Muon_Isol_Muid_etx_EndcapRegion.IsActive() ) STVF_Muon_Isol_Muid_etx_EndcapRegion();
      if( STVF_Muon_Isol_Muid_ety_EndcapRegion.IsActive() ) STVF_Muon_Isol_Muid_ety_EndcapRegion();
      if( STVF_Muon_Isol_Muid_sumet_EndcapRegion.IsActive() ) STVF_Muon_Isol_Muid_sumet_EndcapRegion();
      if( STVF_Muon_Isol_Muid_phi_EndcapRegion.IsActive() ) STVF_Muon_Isol_Muid_phi_EndcapRegion();
      if( STVF_Muon_Isol_Muid_etx_ForwardReg.IsActive() ) STVF_Muon_Isol_Muid_etx_ForwardReg();
      if( STVF_Muon_Isol_Muid_ety_ForwardReg.IsActive() ) STVF_Muon_Isol_Muid_ety_ForwardReg();
      if( STVF_Muon_Isol_Muid_sumet_ForwardReg.IsActive() ) STVF_Muon_Isol_Muid_sumet_ForwardReg();
      if( STVF_Muon_Isol_Muid_phi_ForwardReg.IsActive() ) STVF_Muon_Isol_Muid_phi_ForwardReg();
      if( Muon_NonIsol_Muid_etx.IsActive() ) Muon_NonIsol_Muid_etx();
      if( Muon_NonIsol_Muid_ety.IsActive() ) Muon_NonIsol_Muid_ety();
      if( Muon_NonIsol_Muid_sumet.IsActive() ) Muon_NonIsol_Muid_sumet();
      if( Muon_NonIsol_Muid_etx_CentralReg.IsActive() ) Muon_NonIsol_Muid_etx_CentralReg();
      if( Muon_NonIsol_Muid_ety_CentralReg.IsActive() ) Muon_NonIsol_Muid_ety_CentralReg();
      if( Muon_NonIsol_Muid_sumet_CentralReg.IsActive() ) Muon_NonIsol_Muid_sumet_CentralReg();
      if( Muon_NonIsol_Muid_phi_CentralReg.IsActive() ) Muon_NonIsol_Muid_phi_CentralReg();
      if( Muon_NonIsol_Muid_etx_EndcapRegion.IsActive() ) Muon_NonIsol_Muid_etx_EndcapRegion();
      if( Muon_NonIsol_Muid_ety_EndcapRegion.IsActive() ) Muon_NonIsol_Muid_ety_EndcapRegion();
      if( Muon_NonIsol_Muid_sumet_EndcapRegion.IsActive() ) Muon_NonIsol_Muid_sumet_EndcapRegion();
      if( Muon_NonIsol_Muid_phi_EndcapRegion.IsActive() ) Muon_NonIsol_Muid_phi_EndcapRegion();
      if( Muon_NonIsol_Muid_etx_ForwardReg.IsActive() ) Muon_NonIsol_Muid_etx_ForwardReg();
      if( Muon_NonIsol_Muid_ety_ForwardReg.IsActive() ) Muon_NonIsol_Muid_ety_ForwardReg();
      if( Muon_NonIsol_Muid_sumet_ForwardReg.IsActive() ) Muon_NonIsol_Muid_sumet_ForwardReg();
      if( Muon_NonIsol_Muid_phi_ForwardReg.IsActive() ) Muon_NonIsol_Muid_phi_ForwardReg();
      if( STVF_Muon_NonIsol_Muid_etx.IsActive() ) STVF_Muon_NonIsol_Muid_etx();
      if( STVF_Muon_NonIsol_Muid_ety.IsActive() ) STVF_Muon_NonIsol_Muid_ety();
      if( STVF_Muon_NonIsol_Muid_sumet.IsActive() ) STVF_Muon_NonIsol_Muid_sumet();
      if( STVF_Muon_NonIsol_Muid_etx_CentralReg.IsActive() ) STVF_Muon_NonIsol_Muid_etx_CentralReg();
      if( STVF_Muon_NonIsol_Muid_ety_CentralReg.IsActive() ) STVF_Muon_NonIsol_Muid_ety_CentralReg();
      if( STVF_Muon_NonIsol_Muid_sumet_CentralReg.IsActive() ) STVF_Muon_NonIsol_Muid_sumet_CentralReg();
      if( STVF_Muon_NonIsol_Muid_phi_CentralReg.IsActive() ) STVF_Muon_NonIsol_Muid_phi_CentralReg();
      if( STVF_Muon_NonIsol_Muid_etx_EndcapRegion.IsActive() ) STVF_Muon_NonIsol_Muid_etx_EndcapRegion();
      if( STVF_Muon_NonIsol_Muid_ety_EndcapRegion.IsActive() ) STVF_Muon_NonIsol_Muid_ety_EndcapRegion();
      if( STVF_Muon_NonIsol_Muid_sumet_EndcapRegion.IsActive() ) STVF_Muon_NonIsol_Muid_sumet_EndcapRegion();
      if( STVF_Muon_NonIsol_Muid_phi_EndcapRegion.IsActive() ) STVF_Muon_NonIsol_Muid_phi_EndcapRegion();
      if( STVF_Muon_NonIsol_Muid_etx_ForwardReg.IsActive() ) STVF_Muon_NonIsol_Muid_etx_ForwardReg();
      if( STVF_Muon_NonIsol_Muid_ety_ForwardReg.IsActive() ) STVF_Muon_NonIsol_Muid_ety_ForwardReg();
      if( STVF_Muon_NonIsol_Muid_sumet_ForwardReg.IsActive() ) STVF_Muon_NonIsol_Muid_sumet_ForwardReg();
      if( STVF_Muon_NonIsol_Muid_phi_ForwardReg.IsActive() ) STVF_Muon_NonIsol_Muid_phi_ForwardReg();
      if( Muon_Total_Muid_etx.IsActive() ) Muon_Total_Muid_etx();
      if( Muon_Total_Muid_ety.IsActive() ) Muon_Total_Muid_ety();
      if( Muon_Total_Muid_sumet.IsActive() ) Muon_Total_Muid_sumet();
      if( Muon_Total_Muid_etx_CentralReg.IsActive() ) Muon_Total_Muid_etx_CentralReg();
      if( Muon_Total_Muid_ety_CentralReg.IsActive() ) Muon_Total_Muid_ety_CentralReg();
      if( Muon_Total_Muid_sumet_CentralReg.IsActive() ) Muon_Total_Muid_sumet_CentralReg();
      if( Muon_Total_Muid_phi_CentralReg.IsActive() ) Muon_Total_Muid_phi_CentralReg();
      if( Muon_Total_Muid_etx_EndcapRegion.IsActive() ) Muon_Total_Muid_etx_EndcapRegion();
      if( Muon_Total_Muid_ety_EndcapRegion.IsActive() ) Muon_Total_Muid_ety_EndcapRegion();
      if( Muon_Total_Muid_sumet_EndcapRegion.IsActive() ) Muon_Total_Muid_sumet_EndcapRegion();
      if( Muon_Total_Muid_phi_EndcapRegion.IsActive() ) Muon_Total_Muid_phi_EndcapRegion();
      if( Muon_Total_Muid_etx_ForwardReg.IsActive() ) Muon_Total_Muid_etx_ForwardReg();
      if( Muon_Total_Muid_ety_ForwardReg.IsActive() ) Muon_Total_Muid_ety_ForwardReg();
      if( Muon_Total_Muid_sumet_ForwardReg.IsActive() ) Muon_Total_Muid_sumet_ForwardReg();
      if( Muon_Total_Muid_phi_ForwardReg.IsActive() ) Muon_Total_Muid_phi_ForwardReg();
      if( STVF_Muon_Total_Muid_etx.IsActive() ) STVF_Muon_Total_Muid_etx();
      if( STVF_Muon_Total_Muid_ety.IsActive() ) STVF_Muon_Total_Muid_ety();
      if( STVF_Muon_Total_Muid_sumet.IsActive() ) STVF_Muon_Total_Muid_sumet();
      if( STVF_Muon_Total_Muid_etx_CentralReg.IsActive() ) STVF_Muon_Total_Muid_etx_CentralReg();
      if( STVF_Muon_Total_Muid_ety_CentralReg.IsActive() ) STVF_Muon_Total_Muid_ety_CentralReg();
      if( STVF_Muon_Total_Muid_sumet_CentralReg.IsActive() ) STVF_Muon_Total_Muid_sumet_CentralReg();
      if( STVF_Muon_Total_Muid_phi_CentralReg.IsActive() ) STVF_Muon_Total_Muid_phi_CentralReg();
      if( STVF_Muon_Total_Muid_etx_EndcapRegion.IsActive() ) STVF_Muon_Total_Muid_etx_EndcapRegion();
      if( STVF_Muon_Total_Muid_ety_EndcapRegion.IsActive() ) STVF_Muon_Total_Muid_ety_EndcapRegion();
      if( STVF_Muon_Total_Muid_sumet_EndcapRegion.IsActive() ) STVF_Muon_Total_Muid_sumet_EndcapRegion();
      if( STVF_Muon_Total_Muid_phi_EndcapRegion.IsActive() ) STVF_Muon_Total_Muid_phi_EndcapRegion();
      if( STVF_Muon_Total_Muid_etx_ForwardReg.IsActive() ) STVF_Muon_Total_Muid_etx_ForwardReg();
      if( STVF_Muon_Total_Muid_ety_ForwardReg.IsActive() ) STVF_Muon_Total_Muid_ety_ForwardReg();
      if( STVF_Muon_Total_Muid_sumet_ForwardReg.IsActive() ) STVF_Muon_Total_Muid_sumet_ForwardReg();
      if( STVF_Muon_Total_Muid_phi_ForwardReg.IsActive() ) STVF_Muon_Total_Muid_phi_ForwardReg();
      if( Track_etx.IsActive() ) Track_etx();
      if( Track_ety.IsActive() ) Track_ety();
      if( Track_sumet.IsActive() ) Track_sumet();
      if( Track_etx_CentralReg.IsActive() ) Track_etx_CentralReg();
      if( Track_ety_CentralReg.IsActive() ) Track_ety_CentralReg();
      if( Track_sumet_CentralReg.IsActive() ) Track_sumet_CentralReg();
      if( Track_phi_CentralReg.IsActive() ) Track_phi_CentralReg();
      if( Track_etx_EndcapRegion.IsActive() ) Track_etx_EndcapRegion();
      if( Track_ety_EndcapRegion.IsActive() ) Track_ety_EndcapRegion();
      if( Track_sumet_EndcapRegion.IsActive() ) Track_sumet_EndcapRegion();
      if( Track_phi_EndcapRegion.IsActive() ) Track_phi_EndcapRegion();
      if( Track_etx_ForwardReg.IsActive() ) Track_etx_ForwardReg();
      if( Track_ety_ForwardReg.IsActive() ) Track_ety_ForwardReg();
      if( Track_sumet_ForwardReg.IsActive() ) Track_sumet_ForwardReg();
      if( Track_phi_ForwardReg.IsActive() ) Track_phi_ForwardReg();
      if( STVF_Track_etx.IsActive() ) STVF_Track_etx();
      if( STVF_Track_ety.IsActive() ) STVF_Track_ety();
      if( STVF_Track_sumet.IsActive() ) STVF_Track_sumet();
      if( STVF_Track_etx_CentralReg.IsActive() ) STVF_Track_etx_CentralReg();
      if( STVF_Track_ety_CentralReg.IsActive() ) STVF_Track_ety_CentralReg();
      if( STVF_Track_sumet_CentralReg.IsActive() ) STVF_Track_sumet_CentralReg();
      if( STVF_Track_phi_CentralReg.IsActive() ) STVF_Track_phi_CentralReg();
      if( STVF_Track_etx_EndcapRegion.IsActive() ) STVF_Track_etx_EndcapRegion();
      if( STVF_Track_ety_EndcapRegion.IsActive() ) STVF_Track_ety_EndcapRegion();
      if( STVF_Track_sumet_EndcapRegion.IsActive() ) STVF_Track_sumet_EndcapRegion();
      if( STVF_Track_phi_EndcapRegion.IsActive() ) STVF_Track_phi_EndcapRegion();
      if( STVF_Track_etx_ForwardReg.IsActive() ) STVF_Track_etx_ForwardReg();
      if( STVF_Track_ety_ForwardReg.IsActive() ) STVF_Track_ety_ForwardReg();
      if( STVF_Track_sumet_ForwardReg.IsActive() ) STVF_Track_sumet_ForwardReg();
      if( STVF_Track_phi_ForwardReg.IsActive() ) STVF_Track_phi_ForwardReg();
      if( SoftJets_etx.IsActive() ) SoftJets_etx();
      if( SoftJets_ety.IsActive() ) SoftJets_ety();
      if( SoftJets_sumet.IsActive() ) SoftJets_sumet();
      if( SoftJets_etx_CentralReg.IsActive() ) SoftJets_etx_CentralReg();
      if( SoftJets_ety_CentralReg.IsActive() ) SoftJets_ety_CentralReg();
      if( SoftJets_sumet_CentralReg.IsActive() ) SoftJets_sumet_CentralReg();
      if( SoftJets_phi_CentralReg.IsActive() ) SoftJets_phi_CentralReg();
      if( SoftJets_etx_EndcapRegion.IsActive() ) SoftJets_etx_EndcapRegion();
      if( SoftJets_ety_EndcapRegion.IsActive() ) SoftJets_ety_EndcapRegion();
      if( SoftJets_sumet_EndcapRegion.IsActive() ) SoftJets_sumet_EndcapRegion();
      if( SoftJets_phi_EndcapRegion.IsActive() ) SoftJets_phi_EndcapRegion();
      if( SoftJets_etx_ForwardReg.IsActive() ) SoftJets_etx_ForwardReg();
      if( SoftJets_ety_ForwardReg.IsActive() ) SoftJets_ety_ForwardReg();
      if( SoftJets_sumet_ForwardReg.IsActive() ) SoftJets_sumet_ForwardReg();
      if( SoftJets_phi_ForwardReg.IsActive() ) SoftJets_phi_ForwardReg();
      if( STVF_SoftJets_etx.IsActive() ) STVF_SoftJets_etx();
      if( STVF_SoftJets_ety.IsActive() ) STVF_SoftJets_ety();
      if( STVF_SoftJets_sumet.IsActive() ) STVF_SoftJets_sumet();
      if( STVF_SoftJets_etx_CentralReg.IsActive() ) STVF_SoftJets_etx_CentralReg();
      if( STVF_SoftJets_ety_CentralReg.IsActive() ) STVF_SoftJets_ety_CentralReg();
      if( STVF_SoftJets_sumet_CentralReg.IsActive() ) STVF_SoftJets_sumet_CentralReg();
      if( STVF_SoftJets_phi_CentralReg.IsActive() ) STVF_SoftJets_phi_CentralReg();
      if( STVF_SoftJets_etx_EndcapRegion.IsActive() ) STVF_SoftJets_etx_EndcapRegion();
      if( STVF_SoftJets_ety_EndcapRegion.IsActive() ) STVF_SoftJets_ety_EndcapRegion();
      if( STVF_SoftJets_sumet_EndcapRegion.IsActive() ) STVF_SoftJets_sumet_EndcapRegion();
      if( STVF_SoftJets_phi_EndcapRegion.IsActive() ) STVF_SoftJets_phi_EndcapRegion();
      if( STVF_SoftJets_etx_ForwardReg.IsActive() ) STVF_SoftJets_etx_ForwardReg();
      if( STVF_SoftJets_ety_ForwardReg.IsActive() ) STVF_SoftJets_ety_ForwardReg();
      if( STVF_SoftJets_sumet_ForwardReg.IsActive() ) STVF_SoftJets_sumet_ForwardReg();
      if( STVF_SoftJets_phi_ForwardReg.IsActive() ) STVF_SoftJets_phi_ForwardReg();
      if( RefMuon_etx.IsActive() ) RefMuon_etx();
      if( RefMuon_ety.IsActive() ) RefMuon_ety();
      if( RefMuon_sumet.IsActive() ) RefMuon_sumet();
      if( RefMuon_etx_CentralReg.IsActive() ) RefMuon_etx_CentralReg();
      if( RefMuon_ety_CentralReg.IsActive() ) RefMuon_ety_CentralReg();
      if( RefMuon_sumet_CentralReg.IsActive() ) RefMuon_sumet_CentralReg();
      if( RefMuon_phi_CentralReg.IsActive() ) RefMuon_phi_CentralReg();
      if( RefMuon_etx_EndcapRegion.IsActive() ) RefMuon_etx_EndcapRegion();
      if( RefMuon_ety_EndcapRegion.IsActive() ) RefMuon_ety_EndcapRegion();
      if( RefMuon_sumet_EndcapRegion.IsActive() ) RefMuon_sumet_EndcapRegion();
      if( RefMuon_phi_EndcapRegion.IsActive() ) RefMuon_phi_EndcapRegion();
      if( RefMuon_etx_ForwardReg.IsActive() ) RefMuon_etx_ForwardReg();
      if( RefMuon_ety_ForwardReg.IsActive() ) RefMuon_ety_ForwardReg();
      if( RefMuon_sumet_ForwardReg.IsActive() ) RefMuon_sumet_ForwardReg();
      if( RefMuon_phi_ForwardReg.IsActive() ) RefMuon_phi_ForwardReg();
      if( STVF_RefMuon_etx.IsActive() ) STVF_RefMuon_etx();
      if( STVF_RefMuon_ety.IsActive() ) STVF_RefMuon_ety();
      if( STVF_RefMuon_sumet.IsActive() ) STVF_RefMuon_sumet();
      if( STVF_RefMuon_etx_CentralReg.IsActive() ) STVF_RefMuon_etx_CentralReg();
      if( STVF_RefMuon_ety_CentralReg.IsActive() ) STVF_RefMuon_ety_CentralReg();
      if( STVF_RefMuon_sumet_CentralReg.IsActive() ) STVF_RefMuon_sumet_CentralReg();
      if( STVF_RefMuon_phi_CentralReg.IsActive() ) STVF_RefMuon_phi_CentralReg();
      if( STVF_RefMuon_etx_EndcapRegion.IsActive() ) STVF_RefMuon_etx_EndcapRegion();
      if( STVF_RefMuon_ety_EndcapRegion.IsActive() ) STVF_RefMuon_ety_EndcapRegion();
      if( STVF_RefMuon_sumet_EndcapRegion.IsActive() ) STVF_RefMuon_sumet_EndcapRegion();
      if( STVF_RefMuon_phi_EndcapRegion.IsActive() ) STVF_RefMuon_phi_EndcapRegion();
      if( STVF_RefMuon_etx_ForwardReg.IsActive() ) STVF_RefMuon_etx_ForwardReg();
      if( STVF_RefMuon_ety_ForwardReg.IsActive() ) STVF_RefMuon_ety_ForwardReg();
      if( STVF_RefMuon_sumet_ForwardReg.IsActive() ) STVF_RefMuon_sumet_ForwardReg();
      if( STVF_RefMuon_phi_ForwardReg.IsActive() ) STVF_RefMuon_phi_ForwardReg();
      if( MuonBoy_etx.IsActive() ) MuonBoy_etx();
      if( MuonBoy_ety.IsActive() ) MuonBoy_ety();
      if( MuonBoy_sumet.IsActive() ) MuonBoy_sumet();
      if( MuonBoy_etx_CentralReg.IsActive() ) MuonBoy_etx_CentralReg();
      if( MuonBoy_ety_CentralReg.IsActive() ) MuonBoy_ety_CentralReg();
      if( MuonBoy_sumet_CentralReg.IsActive() ) MuonBoy_sumet_CentralReg();
      if( MuonBoy_phi_CentralReg.IsActive() ) MuonBoy_phi_CentralReg();
      if( MuonBoy_etx_EndcapRegion.IsActive() ) MuonBoy_etx_EndcapRegion();
      if( MuonBoy_ety_EndcapRegion.IsActive() ) MuonBoy_ety_EndcapRegion();
      if( MuonBoy_sumet_EndcapRegion.IsActive() ) MuonBoy_sumet_EndcapRegion();
      if( MuonBoy_phi_EndcapRegion.IsActive() ) MuonBoy_phi_EndcapRegion();
      if( MuonBoy_etx_ForwardReg.IsActive() ) MuonBoy_etx_ForwardReg();
      if( MuonBoy_ety_ForwardReg.IsActive() ) MuonBoy_ety_ForwardReg();
      if( MuonBoy_sumet_ForwardReg.IsActive() ) MuonBoy_sumet_ForwardReg();
      if( MuonBoy_phi_ForwardReg.IsActive() ) MuonBoy_phi_ForwardReg();
      if( STVF_MuonBoy_etx.IsActive() ) STVF_MuonBoy_etx();
      if( STVF_MuonBoy_ety.IsActive() ) STVF_MuonBoy_ety();
      if( STVF_MuonBoy_sumet.IsActive() ) STVF_MuonBoy_sumet();
      if( STVF_MuonBoy_etx_CentralReg.IsActive() ) STVF_MuonBoy_etx_CentralReg();
      if( STVF_MuonBoy_ety_CentralReg.IsActive() ) STVF_MuonBoy_ety_CentralReg();
      if( STVF_MuonBoy_sumet_CentralReg.IsActive() ) STVF_MuonBoy_sumet_CentralReg();
      if( STVF_MuonBoy_phi_CentralReg.IsActive() ) STVF_MuonBoy_phi_CentralReg();
      if( STVF_MuonBoy_etx_EndcapRegion.IsActive() ) STVF_MuonBoy_etx_EndcapRegion();
      if( STVF_MuonBoy_ety_EndcapRegion.IsActive() ) STVF_MuonBoy_ety_EndcapRegion();
      if( STVF_MuonBoy_sumet_EndcapRegion.IsActive() ) STVF_MuonBoy_sumet_EndcapRegion();
      if( STVF_MuonBoy_phi_EndcapRegion.IsActive() ) STVF_MuonBoy_phi_EndcapRegion();
      if( STVF_MuonBoy_etx_ForwardReg.IsActive() ) STVF_MuonBoy_etx_ForwardReg();
      if( STVF_MuonBoy_ety_ForwardReg.IsActive() ) STVF_MuonBoy_ety_ForwardReg();
      if( STVF_MuonBoy_sumet_ForwardReg.IsActive() ) STVF_MuonBoy_sumet_ForwardReg();
      if( STVF_MuonBoy_phi_ForwardReg.IsActive() ) STVF_MuonBoy_phi_ForwardReg();
      if( STVF_CellOut_Track_etx.IsActive() ) STVF_CellOut_Track_etx();
      if( STVF_CellOut_Track_ety.IsActive() ) STVF_CellOut_Track_ety();
      if( STVF_CellOut_Track_sumet.IsActive() ) STVF_CellOut_Track_sumet();
      if( STVF_CellOut_Track_etx_CentralReg.IsActive() ) STVF_CellOut_Track_etx_CentralReg();
      if( STVF_CellOut_Track_ety_CentralReg.IsActive() ) STVF_CellOut_Track_ety_CentralReg();
      if( STVF_CellOut_Track_sumet_CentralReg.IsActive() ) STVF_CellOut_Track_sumet_CentralReg();
      if( STVF_CellOut_Track_phi_CentralReg.IsActive() ) STVF_CellOut_Track_phi_CentralReg();
      if( STVF_CellOut_Track_etx_EndcapRegion.IsActive() ) STVF_CellOut_Track_etx_EndcapRegion();
      if( STVF_CellOut_Track_ety_EndcapRegion.IsActive() ) STVF_CellOut_Track_ety_EndcapRegion();
      if( STVF_CellOut_Track_sumet_EndcapRegion.IsActive() ) STVF_CellOut_Track_sumet_EndcapRegion();
      if( STVF_CellOut_Track_phi_EndcapRegion.IsActive() ) STVF_CellOut_Track_phi_EndcapRegion();
      if( STVF_CellOut_Track_etx_ForwardReg.IsActive() ) STVF_CellOut_Track_etx_ForwardReg();
      if( STVF_CellOut_Track_ety_ForwardReg.IsActive() ) STVF_CellOut_Track_ety_ForwardReg();
      if( STVF_CellOut_Track_sumet_ForwardReg.IsActive() ) STVF_CellOut_Track_sumet_ForwardReg();
      if( STVF_CellOut_Track_phi_ForwardReg.IsActive() ) STVF_CellOut_Track_phi_ForwardReg();
      if( STVF_CellOut_TrackPV_etx.IsActive() ) STVF_CellOut_TrackPV_etx();
      if( STVF_CellOut_TrackPV_ety.IsActive() ) STVF_CellOut_TrackPV_ety();
      if( STVF_CellOut_TrackPV_sumet.IsActive() ) STVF_CellOut_TrackPV_sumet();
      if( STVF_CellOut_TrackPV_etx_CentralReg.IsActive() ) STVF_CellOut_TrackPV_etx_CentralReg();
      if( STVF_CellOut_TrackPV_ety_CentralReg.IsActive() ) STVF_CellOut_TrackPV_ety_CentralReg();
      if( STVF_CellOut_TrackPV_sumet_CentralReg.IsActive() ) STVF_CellOut_TrackPV_sumet_CentralReg();
      if( STVF_CellOut_TrackPV_phi_CentralReg.IsActive() ) STVF_CellOut_TrackPV_phi_CentralReg();
      if( STVF_CellOut_TrackPV_etx_EndcapRegion.IsActive() ) STVF_CellOut_TrackPV_etx_EndcapRegion();
      if( STVF_CellOut_TrackPV_ety_EndcapRegion.IsActive() ) STVF_CellOut_TrackPV_ety_EndcapRegion();
      if( STVF_CellOut_TrackPV_sumet_EndcapRegion.IsActive() ) STVF_CellOut_TrackPV_sumet_EndcapRegion();
      if( STVF_CellOut_TrackPV_phi_EndcapRegion.IsActive() ) STVF_CellOut_TrackPV_phi_EndcapRegion();
      if( STVF_CellOut_TrackPV_etx_ForwardReg.IsActive() ) STVF_CellOut_TrackPV_etx_ForwardReg();
      if( STVF_CellOut_TrackPV_ety_ForwardReg.IsActive() ) STVF_CellOut_TrackPV_ety_ForwardReg();
      if( STVF_CellOut_TrackPV_sumet_ForwardReg.IsActive() ) STVF_CellOut_TrackPV_sumet_ForwardReg();
      if( STVF_CellOut_TrackPV_phi_ForwardReg.IsActive() ) STVF_CellOut_TrackPV_phi_ForwardReg();
      if( STVF_CellOutCorr_etx.IsActive() ) STVF_CellOutCorr_etx();
      if( STVF_CellOutCorr_ety.IsActive() ) STVF_CellOutCorr_ety();
      if( STVF_CellOutCorr_sumet.IsActive() ) STVF_CellOutCorr_sumet();
      if( STVF_CellOutCorr_etx_CentralReg.IsActive() ) STVF_CellOutCorr_etx_CentralReg();
      if( STVF_CellOutCorr_ety_CentralReg.IsActive() ) STVF_CellOutCorr_ety_CentralReg();
      if( STVF_CellOutCorr_sumet_CentralReg.IsActive() ) STVF_CellOutCorr_sumet_CentralReg();
      if( STVF_CellOutCorr_phi_CentralReg.IsActive() ) STVF_CellOutCorr_phi_CentralReg();
      if( STVF_CellOutCorr_etx_EndcapRegion.IsActive() ) STVF_CellOutCorr_etx_EndcapRegion();
      if( STVF_CellOutCorr_ety_EndcapRegion.IsActive() ) STVF_CellOutCorr_ety_EndcapRegion();
      if( STVF_CellOutCorr_sumet_EndcapRegion.IsActive() ) STVF_CellOutCorr_sumet_EndcapRegion();
      if( STVF_CellOutCorr_phi_EndcapRegion.IsActive() ) STVF_CellOutCorr_phi_EndcapRegion();
      if( STVF_CellOutCorr_etx_ForwardReg.IsActive() ) STVF_CellOutCorr_etx_ForwardReg();
      if( STVF_CellOutCorr_ety_ForwardReg.IsActive() ) STVF_CellOutCorr_ety_ForwardReg();
      if( STVF_CellOutCorr_sumet_ForwardReg.IsActive() ) STVF_CellOutCorr_sumet_ForwardReg();
      if( STVF_CellOutCorr_phi_ForwardReg.IsActive() ) STVF_CellOutCorr_phi_ForwardReg();

      return;
   }

} // namespace D3PDReader
