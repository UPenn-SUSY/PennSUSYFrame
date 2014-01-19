#ifndef PennSusyFrame_Calculators_h
#define PennSusyFrame_Calculators_h

#include <vector>
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"

// =============================================================================
namespace PennSusyFrame
{
  class Electron;
  class Muon;
  class Met;
}

// =============================================================================
namespace PennSusyFrame
{
  // -----------------------------------------------------------------------------
  // mt2 calculator
  double getMt2( FLAVOR_CHANNEL
               , const PennSusyFrame::Met*
               , const std::vector<PennSusyFrame::Electron*>*
               , const std::vector<PennSusyFrame::Muon*>*
               , double minv = 0
               );

  template <class T1, class T2>
    double calcMt2(const T1*, const T2*, const Met*, double minv = 0);
}

// Include the implementation:
#ifndef __CINT__
#include "Calculators.icc"
#endif // __CINT__

#endif
