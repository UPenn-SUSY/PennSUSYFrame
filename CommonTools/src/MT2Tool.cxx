#include "include/MT2Tool.h"

CommonTools::MT2Tool::MT2Tool()
{
  // do nothing
}

// -----------------------------------------------------------------------------
double CommonTools::MT2Tool::getMt2( FLAVOR_CHANNEL flavor_channel
                                   , const Met* met
                                   , const std::vector<Electron*>& el
                                   , const std::vector<Muon*>& mu
                                   , double minv
                                   )
{
  double mt2 = 0.;

  if (flavor_channel == FLAVOR_EE) {
    mt2 = calcMt2( el.at(0)
                 , el.at(1)
                 , met
                 , minv
                 );
  }
  else if (flavor_channel == FLAVOR_MM) {
    mt2 = calcMt2( mu.at(0)
                 , mu.at(1)
                 , met
                 , minv
                 );
  }
  else if (flavor_channel == FLAVOR_EM) {
    mt2 = calcMt2( el.at(0)
                 , mu.at(0)
                 , met
                 , minv
                 );
  }

  return mt2;
}
