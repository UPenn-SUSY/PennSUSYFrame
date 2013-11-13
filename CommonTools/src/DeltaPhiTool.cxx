#include "CommonTools/include/DeltaPhiTool.h"

#include <vector>

#include "CommonTools/include/PhillTool.h"

#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/Met.h"

//_____________________________________________________________________________
CommonTools::DeltaPhiTool::DeltaPhiTool()
{
  // do nothing
}

// -----------------------------------------------------------------------------
double CommonTools::DeltaPhiTool::getDeltaPhi( FLAVOR_CHANNEL flavor_channel
                                             , const std::vector<Electron*>& el
                                             , const std::vector<Muon*>& mu
                                             )
{
  double dphi = -999;
  if (flavor_channel == FLAVOR_EE) {
    dphi = el.at(0)->getTlv().Phi() - el.at(1)->getTlv().Phi();
  }
  else if (flavor_channel == FLAVOR_MM) {
    dphi = mu.at(0)->getTlv().Phi() - mu.at(1)->getTlv().Phi();
  }
  else if (flavor_channel == FLAVOR_EM) {
    dphi = el.at(0)->getTlv().Phi() - mu.at(0)->getTlv().Phi();
  }
  else {
    return dphi;
  }
  dphi = fabs(TVector2::Phi_mpi_pi(dphi));

  return dphi;
}

// -----------------------------------------------------------------------------
double CommonTools::DeltaPhiTool::getDeltaPhi( FLAVOR_CHANNEL flavor_channel
                                             , const std::vector<Electron*>& el
                                             , const std::vector<Muon*>& mu
                                             , const Jet* jet
                                             )
{
  double ll_phi = PhillTool::getPhill(flavor_channel, el, mu);
  double jet_phi = jet->getTlv().Phi();
  double dphi = fabs(TVector2::Phi_mpi_pi(ll_phi - jet_phi));

  return dphi;
}

// -----------------------------------------------------------------------------
double CommonTools::DeltaPhiTool::getDeltaPhi( FLAVOR_CHANNEL flavor_channel
                                             , const std::vector<Electron*>& el
                                             , const std::vector<Muon*>& mu
                                             , const Met* met
                                             )
{
  double ll_phi  = PhillTool::getPhill(flavor_channel, el, mu);
  double met_phi = met->getMetRefFinalPhi();
  double dphi = fabs(TVector2::Phi_mpi_pi(ll_phi - met_phi));

  return dphi;
}
