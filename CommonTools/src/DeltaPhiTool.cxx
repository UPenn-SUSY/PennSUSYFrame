#include "include/DeltaPhiTool.h"

//_____________________________________________________________________________
CommonTools::DeltaPhiTool::DeltaPhiTool()
{
  // do nothing
}

// -----------------------------------------------------------------------------
double CommonTools::DeltaPhiTool::getDeltaPhi( FLAVOR_CHANNEL flavor_channel
                                             , const std::vector<Electron*>& el
                                             , const std::vector<Muon*>& mu
                                             , const Jet* jet
                                             )
{
  double ll_phi = 0;
  if (flavor_channel == FLAVOR_EE) {
    ll_phi = ( el.at(0)->getTlv()
             + el.at(1)->getTlv()
             ).Phi();
  }
  else if (flavor_channel == FLAVOR_MM) {
    ll_phi = ( mu.at(0)->getTlv()
             + mu.at(1)->getTlv()
             ).Phi();
  }
  else if (flavor_channel == FLAVOR_EM) {
    ll_phi = ( el.at(0)->getTlv()
             + mu.at(0)->getTlv()
             ).Phi();
  }
  else {
    return -999;
  }

  double dphi = jet->getTlv().Phi();
  dphi = fabs(TVector2::Phi_mpi_pi(dphi));

  return dphi;
}
