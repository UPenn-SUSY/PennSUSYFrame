#include "include/MllTool.h"

//_____________________________________________________________________________
CommonTools::MllTool::MllTool()
{
  // do nothing
}

// ----------------------------------------------------------------------------
double CommonTools::MllTool::getMll( FLAVOR_CHANNEL flavor_channel
                                   , const std::vector<Electron*>& el
                                   , const std::vector<Muon*>& mu
                                   )
{
  double mll = 0;

  if (flavor_channel == FLAVOR_EE) {
    TLorentzVector tlv_0 = el.at(0)->getTlv();
    TLorentzVector tlv_1 = el.at(1)->getTlv();
    mll = (tlv_0 + tlv_1).Mag();
  }
  else if (flavor_channel == FLAVOR_MM) {
    TLorentzVector tlv_0 = mu.at(0)->getTlv();
    TLorentzVector tlv_1 = mu.at(1)->getTlv();
    mll = (tlv_0 + tlv_1).Mag();
  }
  else if (flavor_channel == FLAVOR_EM) {
    TLorentzVector tlv_0 = el.at(0)->getTlv();
    TLorentzVector tlv_1 = mu.at(0)->getTlv();
    mll = (tlv_0 + tlv_1).Mag();
  }

  return mll;
}
