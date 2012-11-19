#include "include/PtllTool.h"

//_____________________________________________________________________________
CommonTools::PtllTool::PtllTool()
{
  // do nothing
}

// ----------------------------------------------------------------------------
double CommonTools::PtllTool::getPtll( FLAVOR_CHANNEL flavor_channel
                                   , const std::vector<Electron*>& el
                                   , const std::vector<Muon*>& mu
                                   )
{
  double ptll = 0;

  if (flavor_channel == FLAVOR_EE) {
    TLorentzVector tlv_0 = el.at(0)->getTlv();
    TLorentzVector tlv_1 = el.at(1)->getTlv();
    ptll = (tlv_0 + tlv_1).Pt();
  }
  else if (flavor_channel == FLAVOR_MM) {
    TLorentzVector tlv_0 = mu.at(0)->getTlv();
    TLorentzVector tlv_1 = mu.at(1)->getTlv();
    ptll = (tlv_0 + tlv_1).Pt();
  }
  else if (flavor_channel == FLAVOR_EM) {
    TLorentzVector tlv_0 = el.at(0)->getTlv();
    TLorentzVector tlv_1 = mu.at(0)->getTlv();
    ptll = (tlv_0 + tlv_1).Pt();
  }

  return ptll;
}
