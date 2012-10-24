#include "include/TLVTool.h"

#include "AtlasSFrameUtils/include/CycleMacros.h"

//_____________________________________________________________________________
CommonTools::TLVTool::TLVTool( SCycleBase* parent
                             , const char* name
                             )
                             : ToolBase(parent, name)
                             , m_egamma_energy_rescale(NULL)
{
  // do nothing
}

//_____________________________________________________________________________
CommonTools::TLVTool::~TLVTool()
{
  // do nothing
}

// ----------------------------------------------------------------------------
void CommonTools::TLVTool::init(
    CommonTools::EgammaEnergyRescaleTool* egamma_energy_rescale,
    CommonTools::MuonMomentumSmearingTool* muon_smearing,
    CommonTools::JetCalibTool*             jet_calibration)
{
  m_egamma_energy_rescale = egamma_energy_rescale;
  m_muon_smearing         = muon_smearing;
  m_jet_calib             = jet_calibration;
}

// ---------------------------------------------------------------------------
const TLorentzVector CommonTools::TLVTool::tlv(const Electron* el)
{
  double pt  = m_egamma_energy_rescale->getRescaledEt(el);
  double eta = el->getEta();
  double phi = el->getPhi();
  double E   = m_egamma_energy_rescale->getRescaledE(el);

  TLorentzVector tlv;
  tlv.SetPtEtaPhiE(pt, eta, phi, E);
  return tlv;
}

// ---------------------------------------------------------------------------
const TLorentzVector CommonTools::TLVTool::rawTlv(const Electron* el)
{
  double pt  = el->cl_pt();
  double eta = el->getEta();
  double phi = el->getPhi();
  double E   = el->cl_E();

  TLorentzVector tlv;
  tlv.SetPtEtaPhiE(pt, eta, phi, E);
  return tlv;
}

// ---------------------------------------------------------------------------
const TLorentzVector CommonTools::TLVTool::tlv(const Muon* mu)
{
  double pt  = m_muon_smearing->getSmearedPt(mu);
  // double pt  = mu->pt();
  double eta = mu->eta();
  double phi = mu->phi();

  TLorentzVector tlv;
  tlv.SetPtEtaPhiM(pt, eta, phi, 105.66);
  return tlv;
}

// ---------------------------------------------------------------------------
const TLorentzVector CommonTools::TLVTool::rawTlv(const Muon* mu)
{
  double pt  = mu->pt();
  double eta = mu->eta();
  double phi = mu->phi();

  TLorentzVector tlv;
  tlv.SetPtEtaPhiM(pt, eta, phi, 105.66);
  return tlv;
}

// ---------------------------------------------------------------------------
const TLorentzVector CommonTools::TLVTool::tlv( Jet* jet
                                              , float mu
                                              , int num_vetices_w_2_trks
                                              )
{
  return m_jet_calib->getConfiguredJet(jet, mu, num_vetices_w_2_trks);
}

// ---------------------------------------------------------------------------
const TLorentzVector CommonTools::TLVTool::rawTlv(const Jet* jet)
{
  double pt  = jet->pt();
  double eta = jet->eta();
  double phi = jet->phi();
  double E   = jet->E();

  TLorentzVector tlv;
  tlv.SetPtEtaPhiE(pt, eta, phi, E);
  return tlv;
}
