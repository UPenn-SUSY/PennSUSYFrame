#include "PennSusyFrameCore/include/Calculators.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"

#include <vector>

// -----------------------------------------------------------------------------
// mll calculator
double PennSusyFrame::getMll( FLAVOR_CHANNEL flavor_channel
                            , const std::vector<PennSusyFrame::Electron*>* el
                            , const std::vector<PennSusyFrame::Muon*>* mu
                            )
{
  double mll = 0.;

  if (flavor_channel == FLAVOR_EE) {
    mll = calcMll(el->at(0), el->at(1));
  }
  else if (flavor_channel == FLAVOR_MM) {
    mll = calcMll(mu->at(0), mu->at(1));
  }
  else if (flavor_channel == FLAVOR_MM) {
    mll = calcMll(el->at(0), mu->at(0));
  }

  return mll;
}

// -----------------------------------------------------------------------------
// mt2 calculator
double PennSusyFrame::getMt2( FLAVOR_CHANNEL flavor_channel
                            , const PennSusyFrame::Met* met
                            , const std::vector<PennSusyFrame::Electron*>* el
                            , const std::vector<PennSusyFrame::Muon*>* mu
                            , double minv
                            )
{
  double mt2 = 0.;

  if (flavor_channel == FLAVOR_EE) {
    mt2 = calcMt2( el->at(0)
                 , el->at(1)
                 , met
                 , minv
                 );
  }
  else if (flavor_channel == FLAVOR_MM) {
    mt2 = calcMt2( mu->at(0)
                 , mu->at(1)
                 , met
                 , minv
                 );
  }
  else if (flavor_channel == FLAVOR_EM) {
    mt2 = calcMt2( el->at(0)
                 , mu->at(0)
                 , met
                 , minv
                 );
  }

  return mt2;
}
