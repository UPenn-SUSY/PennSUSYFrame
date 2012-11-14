// file:        Jet.h
// author:      Brett Jackson       <brett.david.jackson@cern.ch>
// created:     January 2012
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_Jet_h
#define AtlasSFrameUtils_Jet_h

#include <iostream>
#include <vector>
#include "TLorentzVector.h"
#include "ParticleElement.h"

#include "CommonTools/include/TLVTool.h"

#include "D3PDObjects/include/JetD3PDObject.h"
#include "D3PDObjects/include/EventInfoD3PDObject.h"
#include "D3PDObjects/include/VertexD3PDObject.h"

#include "SusyAnalysisTools/include/SusyEnums.h"
#include "SusyAnalysisTools/include/JetDescription.h"

// ============================================================================
namespace CommonTools
{
  class TLVTool;
}

// ============================================================================
class Jet : public ParticleElement<D3PDReader::JetD3PDObjectElement>
{
public:
  Jet( const ParticleElement<D3PDReader::JetD3PDObjectElement>& p
           , CommonTools::TLVTool* tlv_tool
           , int index = -1
           );

  TLorentzVector getTlv() const;
  TLorentzVector getRawTlv() const;

  void prepTlv( float mu
              , int num_vertices_2_trk
              );
  void prepRawTlv();

  SusyAnalysisTools::JetDescription* getJetDesc();

  void print() const;

  static bool eq(const Jet& jet1, const Jet& jet2);
  static bool lt(const Jet& jet1, const Jet& jet2);
  static bool gt(const Jet& jet1, const Jet& jet2);
  static bool le(const Jet& jet1, const Jet& jet2);
  static bool ge(const Jet& jet1, const Jet& jet2);

  bool operator==(const Jet& rhs) const;
  bool operator<( const Jet& rhs) const;
  bool operator>( const Jet& rhs) const;
  bool operator<=(const Jet& rhs) const;
  bool operator>=(const Jet& rhs) const;

private:
  TLorentzVector m_tlv;
  TLorentzVector m_raw_tlv;

  bool m_tlv_prepped;
  bool m_raw_tlv_prepped;

  CommonTools::TLVTool* m_tlv_tool;

  // jet description
  SusyAnalysisTools::JetDescription m_jet_desc;

  ClassDef(Jet, 1);
};

#endif // AtlasSFrameUtils_Jet_h
