#include "include/TLVTool.h"

#include "AtlasSFrameUtils/include/CycleMacros.h"

//_____________________________________________________________________________
CommonTools::TLVTool::TLVTool( SCycleBase* parent
                             , const char* name
                             )
                             : ToolBase(parent, name)
{
  // do nothing
}

//_____________________________________________________________________________
CommonTools::TLVTool::~TLVTool()
{
  // do nothing
}

// ---------------------------------------------------------------------------
const TLorentzVector CommonTools::TLVTool::tlv(const Electron& el)
{
  // TODO Currently only getting raw TLV. Get rescaled TLV when EgammaEnergyRescaleTool is finished
  //GET_TOOL( energy_rescale
  //        , CommonTools::EgammaEnergyRescaleTool
  //        , "EgammaEnergyRescale"
  //        );
  //double pt  = energy_rescale->getRescaledEt(el);
  double pt  = el.cl_pt();
  double eta = el.getEta();
  double phi = el.getPhi();
  //double E   = energy_rescale->getRescaledE(el);
  double E   = el.cl_E();

  TLorentzVector tlv;
  tlv.SetPtEtaPhiE(pt, eta, phi, E);
  return tlv;
}

// ---------------------------------------------------------------------------
const TLorentzVector CommonTools::TLVTool::rawTlv(const Electron& el)
{
  double pt  = el.cl_pt();
  double eta = el.getEta();
  double phi = el.getPhi();
  double E   = el.cl_E();

  TLorentzVector tlv;
  tlv.SetPtEtaPhiE(pt, eta, phi, E);
  return tlv;
}

// ---------------------------------------------------------------------------
const TLorentzVector CommonTools::TLVTool::tlv(const Muon& mu)
{
  // TODO Currently only getting raw TLV. Get smeared TLV when MuonMomentumSmearingTool is finished
  //GET_TOOL( mu_pt_smearing
  //        , CommonTools::MuonMomentumSmearingTool
  //        , "MuonMomentumSmearing"
  //        );
  //double pt  = mu_pt_smearing->getSmearedPt(mu);
  double pt  = mu.pt();
  double eta = mu.eta();
  double phi = mu.phi();

  TLorentzVector tlv;
  tlv.SetPtEtaPhiM(pt, eta, phi, 105.66);
  return tlv;
}

// ---------------------------------------------------------------------------
const TLorentzVector CommonTools::TLVTool::rawTlv(const Muon& mu)
{
  double pt  = mu.pt();
  double eta = mu.eta();
  double phi = mu.phi();

  TLorentzVector tlv;
  tlv.SetPtEtaPhiM(pt, eta, phi, 105.66);
  return tlv;
}

// ---------------------------------------------------------------------------
const TLorentzVector CommonTools::TLVTool::tlv( Jet& jet
                                              , float mu
                                              , int num_vetices_w_2_trks
                                              )
{
  // TODO Currently getting raw TLV. Get calibrated TLV when JetCalibTool is finished
  // GET_TOOL( jet_calibration
  //         , CommonTools::JetCalibTool
  //         , "JetCalib"
  //         );
  // return jet_calibration->getConfiguredJet(jet, mu, num_vetices_w_2_trks);
  return rawTlv(jet);
}

// ---------------------------------------------------------------------------
const TLorentzVector CommonTools::TLVTool::rawTlv(const Jet& jet)
{
  double pt  = jet.pt();
  double eta = jet.eta();
  double phi = jet.phi();
  double E   = jet.E();

  TLorentzVector tlv;
  tlv.SetPtEtaPhiE(pt, eta, phi, E);
  return tlv;
}
