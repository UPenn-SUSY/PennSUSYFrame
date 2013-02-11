#include "AtlasSFrameUtils/include/Muon.h"

#include <cmath>
#include <iostream>
#include <vector>
#include "TLorentzVector.h"

#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "AtlasSFrameUtils/include/ParticleElement.h"
#include "AtlasSFrameUtils/include/VertexContainer.h"

#include "CommonTools/include/TLVTool.h"
#include "CommonTools/include/IsoCorrectionTool.h"

#include "D3PDObjects/include/MuonD3PDObject.h"

#include "SusyAnalysisTools/include/SusyEnums.h"
#include "SusyAnalysisTools/include/MuonDescription.h"

// =============================================================================
ClassImp(Muon)

// -----------------------------------------------------------------------------
Muon::Muon( const ParticleElement<D3PDReader::MuonD3PDObjectElement>& p
          , CommonTools::TLVTool* tlv_tool
          , CommonTools::IsoCorrectionTool* iso_corr_tool
          , int index
          )
          : ParticleElement<D3PDReader::MuonD3PDObjectElement>(p,index,false)
          , m_tlv_prepped(false)
          , m_raw_tlv_prepped(false)
          , m_tlv_tool(tlv_tool)
          , m_iso_corr_tool(iso_corr_tool)
{
  // do nothing
}

// -----------------------------------------------------------------------------
TLorentzVector Muon::getTlv() const
{
  if (!m_tlv_prepped) {
    std::cout << "WARNING!!! Muon TLV is not set "
              << "-- may produce unexpected results!\n"
              << "\tCall prepTlv() to prepare the muon TLV\n";
  }
  return m_tlv;
}

// -----------------------------------------------------------------------------
TLorentzVector Muon::getRawTlv() const
{
  if (!m_raw_tlv_prepped) {
    std::cout << "WARNING!!! Muon raw TLV is not set "
              << "-- may produce unexpected results!\n"
              << "\tCall prepRawTlv() to prepare the muon TLV\n";
  }
  return m_raw_tlv;
}

// -----------------------------------------------------------------------------
void Muon::prepTlv()
{
  if (m_tlv_prepped == false) {
    m_tlv = m_tlv_tool->tlv(this);
    m_tlv_prepped = true;
  }
}

// -----------------------------------------------------------------------------
void Muon::prepRawTlv()
{
  if (m_raw_tlv_prepped == false) {
    m_raw_tlv = m_tlv_tool->rawTlv(this);
    m_raw_tlv_prepped = true;
  }
}

// -----------------------------------------------------------------------------
float Muon::getD0Significance() const
{
  float d0     = trackIPEstimate_d0_unbiasedpvunbiased();
  float cov_d0 = trackIPEstimate_sigd0_unbiasedpvunbiased();

  return fabs(d0)/cov_d0;
}

// -----------------------------------------------------------------------------
float Muon::getZ0SinTheta() const
{
  float z0        = trackIPEstimate_z0_unbiasedpvunbiased();
  float sin_theta = sin(getTlv().Theta());

  return fabs(z0*sin_theta);
}

// -----------------------------------------------------------------------------
int Muon::getNMuonStations() const
{
  int nStations = 0;

  if (nMDTBIHits()  >= 3) ++nStations;
  if (nMDTBMHits()  >= 3) ++nStations;
  if (nMDTBOHits()  >= 3) ++nStations;
  if (nMDTEIHits()  >= 3) ++nStations;
  if (nCSCEtaHits() >= 3) ++nStations;
  if (nMDTEMHits()  >= 3) ++nStations;
  if (nMDTEOHits()  >= 3) ++nStations;

  return nStations;
}

// -----------------------------------------------------------------------------
double Muon::getIsoCorr( ISO_TYPE iso_type
                       , int cone_size
                       , int num_vertex
                       ) const
{
  double iso = 0;

  switch (iso_type) {
    case REL_PTCONE         : // same as PTCONE
    case PTCONE             : iso = ptcone(cone_size);
                              break;
    case REL_ETCONE         : // same as ETCONE
    case ETCONE             : iso = etcone(cone_size);
                              break;
    case REL_TOPOETCONE     : // same as TOPOETCONE
    case TOPOETCONE         : iso = 0.;
                              break;
    case REL_TOPOETCONE_CORR: // same as TOPOETCONE_CORR
    case TOPOETCONE_CORR    : iso = 0.;
                                           break;
  }

  iso -= m_iso_corr_tool->getIsoCorrection(iso_type, cone_size, num_vertex);

  if (  iso_type == REL_PTCONE
     || iso_type == REL_ETCONE
     || iso_type == REL_TOPOETCONE
     || iso_type == REL_TOPOETCONE_CORR
     ) {
    iso /= getTlv().Pt();
  }

  return iso;
}

// -----------------------------------------------------------------------------
double Muon::ptcone(int cone_size) const
{
  double iso = 0.;

  switch (cone_size) {
    case 20: iso = ptcone20();
             break;
    case 30: iso = ptcone30();
             break;
    case 40: iso = ptcone40();
             break;
  };

  return iso;
}

// -----------------------------------------------------------------------------
double Muon::etcone(int cone_size) const
{
  double iso = 0.;

  switch (cone_size) {
    case 20: iso = etcone20();
             break;
    case 30: iso = etcone30();
             break;
    case 40: iso = etcone40();
             break;
  };

  return iso;
}

// -----------------------------------------------------------------------------
SusyAnalysisTools::MuonDescription* Muon::getMuonDesc()
{
  return &m_muon_desc;
}

// ----------------------------------------------------------------------------
void Muon::print(const VertexContainer& vertices) const
{
  TLorentzVector tlv     = getTlv();
  TLorentzVector raw_tlv = getRawTlv();

  size_t num_good_vertices = vertices.num(VERT_GOOD);

  float trt_ol_ratio = 0;
  if (nTRTHits()) trt_ol_ratio = nTRTOutliers()/nTRTHits();
  std::cout << "\traw pt: "  << raw_tlv.Pt()
            << "\traw eta: " << raw_tlv.Eta()
            << "\traw phi: " << raw_tlv.Phi()
            << "\n"
            << "\tpt: "      << tlv.Pt()
            << "\teta: "     << tlv.Eta()
            << "\tphi: "     << tlv.Phi()
            << "\n"
            << "\tptcone30/pt (no correction): " << getIsoCorr(
                REL_PTCONE, 30, 0)
            << "\tptcone30/pt: " << getIsoCorr(
                REL_PTCONE, 30, num_good_vertices)
            << "\n"
            << "\td0: "      << d0_exPV()
            << "\tz0: "      << z0_exPV()
            << "\n"
            << "\tfabs(sqrt(cov_qoverp)/qoverp): "
            << fabs(sqrt(cov_qoverp_exPV())/qoverp_exPV())
            << "\n"
            << "\t# b-layer hits: " << nBLHits()
            << "\texpect b-layer: " << expectBLayerHit()
            << "\n"
            << "\t# pixel hits: " << nPixHits()
            << "\t# SCT hits: " << nSCTHits()
            << "\t# pixel holes: " << nPixHoles()
            << "\t# SCT holes: " << nSCTHoles()
            << "\n"
            << "\t# TRT hits: " << nTRTHits()
            << "\t# TRT outliers: " << nTRTOutliers()
            << "\tTRT outlier ratio: " << trt_ol_ratio
            << "\n";
}

// -----------------------------------------------------------------------------
bool Muon::eq(const Muon& mu1, const Muon& mu2)
{
  return (mu1 == mu2);
}

// -----------------------------------------------------------------------------
bool Muon::lt(const Muon& mu1, const Muon& mu2)
{
  return (mu1 < mu2);
}

// -----------------------------------------------------------------------------
bool Muon::gt(const Muon& mu1, const Muon& mu2)
{
  return (mu1 > mu2);
}

// -----------------------------------------------------------------------------
bool Muon::le(const Muon& mu1, const Muon& mu2)
{
  return (mu1 <= mu2);
}

// -----------------------------------------------------------------------------
bool Muon::ge(const Muon& mu1, const Muon& mu2)
{
  return (mu1 >= mu2);
}

// -----------------------------------------------------------------------------
bool Muon::operator==(const Muon& rhs) const
{
  return (getTlv().Pt() == rhs.getTlv().Pt());
}

// -----------------------------------------------------------------------------
bool Muon::operator<(const Muon& rhs) const
{
  return (getTlv().Pt() < rhs.getTlv().Pt());
}

// -----------------------------------------------------------------------------
bool Muon::operator>(const Muon& rhs) const
{
  return (getTlv().Pt() > rhs.getTlv().Pt());
}

// -----------------------------------------------------------------------------
bool Muon::operator<=(const Muon& rhs) const
{
  return (getTlv().Pt() <= rhs.getTlv().Pt());
}

// -----------------------------------------------------------------------------
bool Muon::operator>=(const Muon& rhs) const
{
  return (getTlv().Pt() >= rhs.getTlv().Pt());
}
