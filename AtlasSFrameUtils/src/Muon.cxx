#include <cmath>

#include "include/Muon.h"
#include "AtlasSFrameUtils/include/CycleMacros.h"

ClassImp(Muon)

// ----------------------------------------------------------------------------
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

// ----------------------------------------------------------------------------
TLorentzVector Muon::getTlv() const
{
  if (!m_tlv_prepped) {
    std::cout << "WARNING!!! Muon TLV is not set "
              << "-- may produce unexpected results!\n"
              << "\tCall prepTlv() to prepare the muon TLV\n";
  }
  return m_tlv;
}

// ----------------------------------------------------------------------------
TLorentzVector Muon::getRawTlv() const
{
  if (!m_raw_tlv_prepped) {
    std::cout << "WARNING!!! Muon raw TLV is not set "
              << "-- may produce unexpected results!\n"
              << "\tCall prepRawTlv() to prepare the muon TLV\n";
  }
  return m_raw_tlv;
}

// ----------------------------------------------------------------------------
void Muon::prepTlv()
{
  if (m_tlv_prepped == false) {
    m_tlv = m_tlv_tool->tlv(*this);
    m_tlv_prepped = true;
  }
}

// ----------------------------------------------------------------------------
void Muon::prepRawTlv()
{
  if (m_raw_tlv_prepped == false) {
    m_raw_tlv = m_tlv_tool->rawTlv(*this);
    m_raw_tlv_prepped = true;
  }
}

// ----------------------------------------------------------------------------
float Muon::getD0Significance() const
{
  float d0     = d0_exPV();
  float cov_d0 = cov_d0_exPV();

  return d0/sqrt(cov_d0);
}

// ----------------------------------------------------------------------------
float Muon::getZ0SinTheta() const
{
  float z0        = z0_exPV();
  float sin_theta = sin(getTlv().Theta());

  return z0*sin_theta;
}

// ----------------------------------------------------------------------------
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
double Muon::getIsoCorr( CommonTools::ISO_TYPE iso_type
                       , int cone_size
                       , int num_vertex
                       ) const
{
  double iso = 0;

  switch (iso_type) {
    case CommonTools::REL_PTCONE         : // same as PTCONE
    case CommonTools::PTCONE             : iso = ptcone(cone_size);
                                           break;
    case CommonTools::REL_ETCONE         : // same as ETCONE
    case CommonTools::ETCONE             : iso = etcone(cone_size);
                                           break;
    case CommonTools::REL_TOPOETCONE     : // same as TOPOETCONE
    case CommonTools::TOPOETCONE         : iso = 0.;
                                           break;
    case CommonTools::REL_TOPOETCONE_CORR: // same as TOPOETCONE_CORR
    case CommonTools::TOPOETCONE_CORR    : iso = 0.;
                                           break;
  }

  iso -= m_iso_corr_tool->getIsoCorrection(iso_type, cone_size, num_vertex);

  if (  iso_type == CommonTools::REL_PTCONE
     || iso_type == CommonTools::REL_ETCONE
     || iso_type == CommonTools::REL_TOPOETCONE
     || iso_type == CommonTools::REL_TOPOETCONE_CORR
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

// ----------------------------------------------------------------------------
void Muon::print() const
{
  TLorentzVector tlv = getTlv();

  std::cout << "\tpt: "  << tlv.Pt()
            << "\teta: " << tlv.Eta()
            << "\tphi: " << tlv.Phi()
            // TODO Get proper number vertices for isolation
            << "\tptcone30/pt: " << getIsoCorr(
                CommonTools::REL_PTCONE, 30, 0)
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
