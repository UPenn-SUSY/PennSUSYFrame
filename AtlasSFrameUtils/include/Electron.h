// file:        Electron.h
// author:      Brett Jackson       <brett.david.jackson@cern.ch>
// created:     October 2012
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_Electron_h
#define AtlasSFrameUtils_Electron_h

#include <iostream>
#include <vector>
#include "TLorentzVector.h"
#include "ParticleElement.h"

#include "VertexContainer.h"

#include "CommonTools/include/TLVTool.h"
#include "CommonTools/include/IsoCorrectionTool.h"

#include "D3PDObjects/include/ElectronD3PDObject.h"

#include "SusyAnalysisTools/include/SusyEnums.h"
#include "SusyAnalysisTools/include/ElectronDescription.h"

// ============================================================================
// namespace SelectionTools
namespace CommonTools
{
  class TLVTool;
}
class VertexContainer;

// ============================================================================
class Electron : public ParticleElement<D3PDReader::ElectronD3PDObjectElement>
{
public:
  Electron( const ParticleElement<D3PDReader::ElectronD3PDObjectElement>& p
          , CommonTools::TLVTool* tlv_tool
          , CommonTools::IsoCorrectionTool* iso_corr_tool
          , int index = -1
          );

  TLorentzVector getTlv() const;
  TLorentzVector getRawTlv() const;

  void prepTlv();
  void prepRawTlv();

  void setTruthCharge(float);


  float getEta() const;
  float getPhi() const;
  float getTruthCharge(); 

  float getD0Significance() const;
  float getZ0SinTheta() const;

  double getIsoCorr(ISO_TYPE, int cone_size, int num_vertex) const;

  SusyAnalysisTools::ElectronDescription* getElectronDesc();

  void print(const VertexContainer&) const;

  static bool eq(const Electron& el1, const Electron& el2);
  static bool lt(const Electron& el1, const Electron& el2);
  static bool gt(const Electron& el1, const Electron& el2);
  static bool le(const Electron& el1, const Electron& el2);
  static bool ge(const Electron& el1, const Electron& el2);

  bool operator==(const Electron& rhs) const;
  bool operator<( const Electron& rhs) const;
  bool operator>( const Electron& rhs) const;
  bool operator<=(const Electron& rhs) const;
  bool operator>=(const Electron& rhs) const;

private:
  TLorentzVector m_tlv;
  TLorentzVector m_raw_tlv;

  bool m_tlv_prepped;
  bool m_raw_tlv_prepped;

  float m_truth_charge;

  CommonTools::TLVTool* m_tlv_tool;
  CommonTools::IsoCorrectionTool* m_iso_corr_tool;

  double ptcone(int cone_size) const;
  double etcone(int cone_size) const;
  double topoetcone(int cone_size) const;
  double topoetcone_corrected(int cone_size) const;

  

  // electron description
  SusyAnalysisTools::ElectronDescription m_el_desc;

  ClassDef(Electron, 1);
};


#endif // AtlasSFrameUtils_Electron_h
