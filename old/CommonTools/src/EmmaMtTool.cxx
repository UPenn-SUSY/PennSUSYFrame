#include "CommonTools/include/EmmaMtTool.h"

#include "TLorentzVector.h"
#include "SusyAnalysisTools/include/SusyEnums.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Muon.h"

CommonTools::EmmaMtTool::EmmaMtTool()
{
  // do nothing
}

// -----------------------------------------------------------------------------
double CommonTools::EmmaMtTool::getEmmaMt( FLAVOR_CHANNEL flavor_channel
                                         , const std::vector<Electron*>& el
                                         , const std::vector<Muon*>& mu
                                         )
{
  double emma_mt = 0.;

  if (flavor_channel == FLAVOR_EE) {
    TLorentzVector tlv = ( el.at(0)->getTlv()
                         + el.at(1)->getTlv()
                         );
    emma_mt = calcEmmaMt(tlv);
  }
  else if (flavor_channel == FLAVOR_MM) {
    TLorentzVector tlv = ( mu.at(0)->getTlv()
                         + mu.at(1)->getTlv()
                         );
    emma_mt = calcEmmaMt(tlv);
  }
  else if (flavor_channel == FLAVOR_EM) {
    TLorentzVector tlv = ( el.at(0)->getTlv()
                         + mu.at(0)->getTlv()
                         );
    emma_mt = calcEmmaMt(tlv);
  }

  return emma_mt;
}

// -----------------------------------------------------------------------------
double CommonTools::EmmaMtTool::calcEmmaMt( const TLorentzVector& tlv)
{
  return std::sqrt(std::pow(tlv.M(),2) + std::pow(tlv.Pt(),2));
}
