#include "AtlasSFrameUtils/include/Tau.h"

#include <cmath>
#include <iostream>
#include <vector>
#include "TLorentzVector.h"

#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "AtlasSFrameUtils/include/ParticleElement.h"
#include "AtlasSFrameUtils/include/VertexContainer.h"

#include "CommonTools/include/TLVTool.h"
#include "CommonTools/include/IsoCorrectionTool.h"

#include "D3PDObjects/include/TauD3PDObject.h"

#include "SusyAnalysisTools/include/SusyEnums.h"
#include "SusyAnalysisTools/include/TauDescription.h"

// =============================================================================
ClassImp(Tau)

// -----------------------------------------------------------------------------
Tau::Tau( const ParticleElement<D3PDReader::TauD3PDObjectElement>& p
          , CommonTools::TLVTool* tlv_tool
          , CommonTools::IsoCorrectionTool* iso_corr_tool
          , int index
          )
          : ParticleElement<D3PDReader::TauD3PDObjectElement>(p,index,false)
          , m_tlv_prepped(false)
          , m_raw_tlv_prepped(false)
          , m_tlv_tool(tlv_tool)
          , m_iso_corr_tool(iso_corr_tool)
{
  // do nothing
}

// -----------------------------------------------------------------------------
TLorentzVector Tau::getTlv() const
{
  if (!m_tlv_prepped) {
    std::cout << "WARNING!!! Tau TLV is not set "
              << "-- may produce unexpected results!\n"
              << "\tCall prepTlv() to prepare the tau TLV\n";
  }
  return m_tlv;
}

// -----------------------------------------------------------------------------
TLorentzVector Tau::getRawTlv() const
{
  if (!m_raw_tlv_prepped) {
    std::cout << "WARNING!!! Tau raw TLV is not set "
              << "-- may produce unexpected results!\n"
              << "\tCall prepRawTlv() to prepare the tau TLV\n";
  }
  return m_raw_tlv;
}

// -----------------------------------------------------------------------------
void Tau::prepTlv()
{
  if (m_tlv_prepped == false) {
    m_tlv = m_tlv_tool->tlv(this);
    m_tlv_prepped = true;
  }
}

// -----------------------------------------------------------------------------
void Tau::prepRawTlv()
{
  if (m_raw_tlv_prepped == false) {
    m_raw_tlv = m_tlv_tool->rawTlv(this);
    m_raw_tlv_prepped = true;
  }
}

// -----------------------------------------------------------------------------
float Tau::getD0Significance() const
{
  return 0;
  // float d0     = trackIPEstimate_d0_unbiasedpvunbiased();
  // float cov_d0 = trackIPEstimate_sigd0_unbiasedpvunbiased();

  // return fabs(d0)/cov_d0;
}

// -----------------------------------------------------------------------------
float Tau::getZ0SinTheta() const
{
  return 0;
  // float z0        = trackIPEstimate_z0_unbiasedpvunbiased();
  // float sin_theta = sin(getTlv().Theta());

  // return fabs(z0*sin_theta);
}

// // -----------------------------------------------------------------------------
// double Tau::getIsoCorr( ISO_TYPE iso_type
//                        , int cone_size
//                        , int num_vertex
//                        ) const
// {
//   double iso = 0;
// 
//   switch (iso_type) {
//     case REL_PTCONE         : // same as PTCONE
//     case PTCONE             : iso = ptcone(cone_size);
//                               break;
//     case REL_ETCONE         : // same as ETCONE
//     case ETCONE             : iso = etcone(cone_size);
//                               break;
//     case REL_TOPOETCONE     : // same as TOPOETCONE
//     case TOPOETCONE         : iso = 0.;
//                               break;
//     case REL_TOPOETCONE_CORR: // same as TOPOETCONE_CORR
//     case TOPOETCONE_CORR    : iso = 0.;
//                                            break;
//   }
// 
//   iso -= m_iso_corr_tool->getIsoCorrection(iso_type, cone_size, num_vertex);
// 
//   if (  iso_type == REL_PTCONE
//      || iso_type == REL_ETCONE
//      || iso_type == REL_TOPOETCONE
//      || iso_type == REL_TOPOETCONE_CORR
//      ) {
//     iso /= getTlv().Pt();
//   }
// 
//   return iso;
// }

// // -----------------------------------------------------------------------------
// double Tau::ptcone(int cone_size) const
// {
//   double iso = 0.;
// 
//   switch (cone_size) {
//     case 20: iso = ptcone20();
//              break;
//     case 30: iso = ptcone30();
//              break;
//     case 40: iso = ptcone40();
//              break;
//   };
// 
//   return iso;
// }
// 
// // -----------------------------------------------------------------------------
// double Tau::etcone(int cone_size) const
// {
//   double iso = 0.;
// 
//   switch (cone_size) {
//     case 20: iso = etcone20();
//              break;
//     case 30: iso = etcone30();
//              break;
//     case 40: iso = etcone40();
//              break;
//   };
// 
//   return iso;
// }

// -----------------------------------------------------------------------------
SusyAnalysisTools::TauDescription* Tau::getTauDesc()
{
  return &m_tau_desc;
}

// ----------------------------------------------------------------------------
void Tau::print(const VertexContainer& vertices) const
{
  TLorentzVector tlv     = getTlv();
  TLorentzVector raw_tlv = getRawTlv();

  size_t num_good_vertices = vertices.num(VERT_GOOD);

  std::cout << "\traw pt: "  << raw_tlv.Pt()
            << "\traw eta: " << raw_tlv.Eta()
            << "\traw phi: " << raw_tlv.Phi()
            << "\n"
            << "\tpt: "      << tlv.Pt()
            << "\teta: "     << tlv.Eta()
            << "\tphi: "     << tlv.Phi()
            << "\n";
}

// -----------------------------------------------------------------------------
bool Tau::eq(const Tau& tau1, const Tau& tau2)
{
  return (tau1 == tau2);
}

// -----------------------------------------------------------------------------
bool Tau::lt(const Tau& tau1, const Tau& tau2)
{
  return (tau1 < tau2);
}

// -----------------------------------------------------------------------------
bool Tau::gt(const Tau& tau1, const Tau& tau2)
{
  return (tau1 > tau2);
}

// -----------------------------------------------------------------------------
bool Tau::le(const Tau& tau1, const Tau& tau2)
{
  return (tau1 <= tau2);
}

// -----------------------------------------------------------------------------
bool Tau::ge(const Tau& tau1, const Tau& tau2)
{
  return (tau1 >= tau2);
}

// -----------------------------------------------------------------------------
bool Tau::operator==(const Tau& rhs) const
{
  return (getTlv().Pt() == rhs.getTlv().Pt());
}

// -----------------------------------------------------------------------------
bool Tau::operator<(const Tau& rhs) const
{
  return (getTlv().Pt() < rhs.getTlv().Pt());
}

// -----------------------------------------------------------------------------
bool Tau::operator>(const Tau& rhs) const
{
  return (getTlv().Pt() > rhs.getTlv().Pt());
}

// -----------------------------------------------------------------------------
bool Tau::operator<=(const Tau& rhs) const
{
  return (getTlv().Pt() <= rhs.getTlv().Pt());
}

// -----------------------------------------------------------------------------
bool Tau::operator>=(const Tau& rhs) const
{
  return (getTlv().Pt() >= rhs.getTlv().Pt());
}
