#include "CommonTools/include/SignChannel.h"

#include <vector>

#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

//_____________________________________________________________________________
CommonTools::SignChannel::SignChannel()
{
  // do nothing
}

// ----------------------------------------------------------------------------
SIGN_CHANNEL CommonTools::SignChannel::getSignChannel(
    FLAVOR_CHANNEL flavor_channel,
    const std::vector<Electron*>& el,
    const std::vector<Muon*>& mu)
{
  float charge_0 = 0;
  float charge_1 = 0;

  switch (flavor_channel) {
    case FLAVOR_EE: charge_0 = el.at(0)->charge();
                    charge_1 = el.at(1)->charge();
                    break;
    case FLAVOR_MM: charge_0 = mu.at(0)->charge();
                    charge_1 = mu.at(1)->charge();
                    break;
    case FLAVOR_EM: charge_0 = el.at(0)->charge();
                    charge_1 = mu.at(0)->charge();
                    break;
    default       : charge_0 = 0;
                    charge_1 = 0;
  }

  float charge_product = charge_0*charge_1;

  if (charge_product < 0.) return SIGN_OS;
  if (charge_product > 0.) return SIGN_SS;
  return SIGN_NONE;
}
