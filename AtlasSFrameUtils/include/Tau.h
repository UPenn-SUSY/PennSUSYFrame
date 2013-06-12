// file:        Tau.h
// author:      Brett Jackson       <brett.david.jackson@cern.ch>
// created:     January 2012
//------------------------------------------------------------------------------
#ifndef AtlasSFrameUtils_Tau_h
#define AtlasSFrameUtils_Tau_h

// =============================================================================
#include "TLorentzVector.h"
#include "AtlasSFrameUtils/include/ParticleElement.h"
#include "D3PDObjects/include/TauD3PDObject.h"
#include "SusyAnalysisTools/include/TauDescription.h"

#include "SusyAnalysisTools/include/SusyEnums.h"

// ============================================================================
class VertexContainer;
namespace CommonTools
{
  class TLVTool;
  class IsoCorrectionTool;
}

// ============================================================================
class Tau : public ParticleElement<D3PDReader::TauD3PDObjectElement>
{
public:
  Tau( const ParticleElement<D3PDReader::TauD3PDObjectElement>& p
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

  // double getIsoCorr(ISO_TYPE, int cone_size, int num_vertex) const;

  SusyAnalysisTools::TauDescription* getTauDesc();

  void print(const VertexContainer&) const;

  static bool eq(const Tau& tau1, const Tau& tau2);
  static bool lt(const Tau& tau1, const Tau& tau2);
  static bool gt(const Tau& tau1, const Tau& tau2);
  static bool le(const Tau& tau1, const Tau& tau2);
  static bool ge(const Tau& tau1, const Tau& tau2);

  bool operator==(const Tau& rhs) const;
  bool operator<( const Tau& rhs) const;
  bool operator>( const Tau& rhs) const;
  bool operator<=(const Tau& rhs) const;
  bool operator>=(const Tau& rhs) const;

private:
  TLorentzVector m_tlv;
  TLorentzVector m_raw_tlv;

  bool m_tlv_prepped;
  bool m_raw_tlv_prepped;

  CommonTools::TLVTool* m_tlv_tool;
  CommonTools::IsoCorrectionTool* m_iso_corr_tool;

  double ptcone(int cone_size) const;
  double etcone(int cone_size) const;

  // tau description
  SusyAnalysisTools::TauDescription m_tau_desc;

  ClassDef(Tau, 1);
};

#endif // AtlasSFrameUtils_Tau_h
