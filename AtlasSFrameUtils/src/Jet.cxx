#include "AtlasSFrameUtils/include/Jet.h"

#include <cmath>
#include <iostream>
#include <vector>
#include "TLorentzVector.h"

#include "AtlasSFrameUtils/include/Event.h"
#include "AtlasSFrameUtils/include/ParticleElement.h"

#include "CommonTools/include/TLVTool.h"

#include "D3PDObjects/include/EventInfoD3PDObject.h"
#include "D3PDObjects/include/JetD3PDObject.h"
#include "D3PDObjects/include/VertexD3PDObject.h"

#include "SusyAnalysisTools/include/SusyEnums.h"
#include "SusyAnalysisTools/include/JetDescription.h"

// =============================================================================
ClassImp(Jet)

// ----------------------------------------------------------------------------
Jet::Jet( const ParticleElement<D3PDReader::JetD3PDObjectElement>& p
        , CommonTools::TLVTool* tlv_tool
        , int index
        )
        : ParticleElement<D3PDReader::JetD3PDObjectElement>(p,index,false)
        , m_tlv_prepped(false)
        , m_raw_tlv_prepped(false)
        , m_tlv_tool(tlv_tool)
{
  // do nothing
}

// ----------------------------------------------------------------------------
TLorentzVector Jet::getTlv() const
{
  if (!m_tlv_prepped) {
    std::cout << "WARNING!!! Jet TLV is not set "
              << "-- may produce unexpected results!\n"
              << "\tCall prepTlv() to prepare the jet TLV\n";
  }
  return m_tlv;
}

// ----------------------------------------------------------------------------
TLorentzVector Jet::getRawTlv() const
{
  if (!m_raw_tlv_prepped) {
    std::cout << "WARNING!!! Jet raw TLV is not set "
              << "-- may produce unexpected results!\n"
              << "\tCall prepRawTlv() to prepare the jet TLV\n";
  }
  return m_raw_tlv;
}

// ----------------------------------------------------------------------------
void Jet::prepTlv( const Event* event
                 , int num_vertices_2_trk
                 )
{
  if (m_tlv_prepped == false) {
    m_tlv = m_tlv_tool->tlv(this, event, num_vertices_2_trk);
    m_tlv_prepped = true;
  }
}

// ----------------------------------------------------------------------------
void Jet::prepRawTlv()
{
  if (m_raw_tlv_prepped == false) {
    m_raw_tlv = m_tlv_tool->rawTlv(this);
    m_raw_tlv_prepped = true;
  }
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::JetDescription* Jet::getJetDesc()
{
  return &m_jet_desc;
}

// ----------------------------------------------------------------------------
void Jet::print() const
{
  TLorentzVector tlv     = getTlv();
  TLorentzVector raw_tlv = getRawTlv();

  std::cout << "\traw pt:  " << raw_tlv.Pt()
            << "\traw eta: " << raw_tlv.Eta()
            << "\traw phi: " << raw_tlv.Phi()
            << "\n"
            << "\tpt:  " << tlv.Pt()
            << "\teta: " << tlv.Eta()
            << "\tphi: " << tlv.Phi()
            << "\n"
            << "\tjvf: " << jvtxf()
            << "\tmv1: " << flavor_weight_MV1()
            << "\n";
}

// ----------------------------------------------------------------------------
bool Jet::eq(const Jet& jet1, const Jet& jet2)
{
  return (jet1 == jet2);
}

// ----------------------------------------------------------------------------
bool Jet::lt(const Jet& jet1, const Jet& jet2)
{
  return (jet1 < jet2);
}

// ----------------------------------------------------------------------------
bool Jet::gt(const Jet& jet1, const Jet& jet2)
{
  return (jet1 > jet2);
}

// ----------------------------------------------------------------------------
bool Jet::le(const Jet& jet1, const Jet& jet2)
{
  return (jet1 <= jet2);
}

// ----------------------------------------------------------------------------
bool Jet::ge(const Jet& jet1, const Jet& jet2)
{
  return (jet1 >= jet2);
}

// ----------------------------------------------------------------------------
bool Jet::operator==(const Jet& rhs) const
{
  return (getTlv().Pt() == rhs.getTlv().Pt());
}

// ----------------------------------------------------------------------------
bool Jet::operator<(const Jet& rhs) const
{
  return (getTlv().Pt() < rhs.getTlv().Pt());
}

// ----------------------------------------------------------------------------
bool Jet::operator>(const Jet& rhs) const
{
  return (getTlv().Pt() > rhs.getTlv().Pt());
}

// ----------------------------------------------------------------------------
bool Jet::operator<=(const Jet& rhs) const
{
  return (getTlv().Pt() <= rhs.getTlv().Pt());
}

// ----------------------------------------------------------------------------
bool Jet::operator>=(const Jet& rhs) const
{
  return (getTlv().Pt() >= rhs.getTlv().Pt());
}
