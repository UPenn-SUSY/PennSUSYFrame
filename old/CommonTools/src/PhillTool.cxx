#include "CommonTools/include/PhillTool.h"

#include <vector>

#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// -----------------------------------------------------------------------------
CommonTools::PhillTool::PhillTool()
{
  // do nothing
}

// ----------------------------------------------------------------------------
double CommonTools::PhillTool::getPhill( FLAVOR_CHANNEL flavor_channel
                                       , const std::vector<Electron*>& el
                                       , const std::vector<Muon*>& mu
                                       )
{
  double phill = 0;

  if (flavor_channel == FLAVOR_EE) {
    TLorentzVector tlv_0 = el.at(0)->getTlv();
    TLorentzVector tlv_1 = el.at(1)->getTlv();
    phill = (tlv_0 + tlv_1).Phi();
  }
  else if (flavor_channel == FLAVOR_MM) {
    TLorentzVector tlv_0 = mu.at(0)->getTlv();
    TLorentzVector tlv_1 = mu.at(1)->getTlv();
    phill = (tlv_0 + tlv_1).Phi();
  }
  else if (flavor_channel == FLAVOR_EM) {
    TLorentzVector tlv_0 = el.at(0)->getTlv();
    TLorentzVector tlv_1 = mu.at(0)->getTlv();
    phill = (tlv_0 + tlv_1).Phi();
  }

  return phill;
}
