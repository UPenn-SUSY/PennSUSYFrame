#include "include/EtallTool.h"

//_____________________________________________________________________________
CommonTools::EtallTool::EtallTool()
{
  // do nothing
}

// ----------------------------------------------------------------------------
double CommonTools::EtallTool::getEtall( FLAVOR_CHANNEL flavor_channel
                                       , const std::vector<Electron*>& el
                                       , const std::vector<Muon*>& mu
                                       )
{
  double etall = 0;

  if (flavor_channel == FLAVOR_EE) {
    TLorentzVector tlv_0 = el.at(0)->getTlv();
    TLorentzVector tlv_1 = el.at(1)->getTlv();
    etall = (tlv_0 + tlv_1).Eta();
  }
  else if (flavor_channel == FLAVOR_MM) {
    TLorentzVector tlv_0 = mu.at(0)->getTlv();
    TLorentzVector tlv_1 = mu.at(1)->getTlv();
    etall = (tlv_0 + tlv_1).Eta();
  }
  else if (flavor_channel == FLAVOR_EM) {
    TLorentzVector tlv_0 = el.at(0)->getTlv();
    TLorentzVector tlv_1 = mu.at(0)->getTlv();
    etall = (tlv_0 + tlv_1).Eta();
  }

  return etall;
}
