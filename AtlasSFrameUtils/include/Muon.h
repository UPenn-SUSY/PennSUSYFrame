// file:        Muon.h
// author:      Brett Jackson       <brett.david.jackson@cern.ch>
// created:     January 2012
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_Muon_h
#define AtlasSFrameUtils_Muon_h

#include <iostream>
#include <vector>
#include "TLorentzVector.h"
#include "ParticleElement.h"

#include "VertexContainer.h"

#include "CommonTools/include/TLVTool.h"
#include "CommonTools/include/IsoCorrectionTool.h"

#include "D3PDObjects/include/MuonD3PDObject.h"

// ============================================================================
namespace CommonTools
{
  class TLVTool;
}
class VertexContainer;

// ============================================================================
class Muon : public ParticleElement<D3PDReader::MuonD3PDObjectElement>
{
public:
  Muon( const ParticleElement<D3PDReader::MuonD3PDObjectElement>& p
      , CommonTools::TLVTool* tlv_tool
      , CommonTools::IsoCorrectionTool* iso_corr_tool
      , int index = -1
      );

  TLorentzVector getTlv() const;
  TLorentzVector getRawTlv() const;

  void prepTlv();
  void prepRawTlv();

  float getD0Significance() const;
  float getZ0SinTheta() const;

  int getNMuonStations() const;

  double getIsoCorr(
      CommonTools::ISO_TYPE, int cone_size, int num_vertex) const;

  void print(const VertexContainer&) const;

  static bool eq(const Muon& mu1, const Muon& mu2);
  static bool lt(const Muon& mu1, const Muon& mu2);
  static bool gt(const Muon& mu1, const Muon& mu2);
  static bool le(const Muon& mu1, const Muon& mu2);
  static bool ge(const Muon& mu1, const Muon& mu2);

  bool operator==(const Muon& rhs) const;
  bool operator<( const Muon& rhs) const;
  bool operator>( const Muon& rhs) const;
  bool operator<=(const Muon& rhs) const;
  bool operator>=(const Muon& rhs) const;

private:
  TLorentzVector m_tlv;
  TLorentzVector m_raw_tlv;

  bool m_tlv_prepped;
  bool m_raw_tlv_prepped;

  CommonTools::TLVTool* m_tlv_tool;
  CommonTools::IsoCorrectionTool* m_iso_corr_tool;

  double ptcone(int cone_size) const;
  double etcone(int cone_size) const;

  ClassDef(Muon, 1);
};

#endif // AtlasSFrameUtils_Muon_h
