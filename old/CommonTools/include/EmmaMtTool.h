// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_EmmaMtTool_H
#define CommonTools_EmmaMtTool_H
// =============================================================================
#include <vector>
#include "TLorentzVector.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class Electron;
class Muon;

// =============================================================================
namespace CommonTools{

  // ===========================================================================
  class EmmaMtTool
  {
  // ---------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    EmmaMtTool();

    static double getEmmaMt( FLAVOR_CHANNEL
                           , const std::vector<Electron*>&
                           , const std::vector<Muon*>&
                           );

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    static double calcEmmaMt(const TLorentzVector&);
  };
}

// Include the implementation:
#ifndef __CINT__
#include "EmmaMtTool.icc"
#endif // __CINT__


#endif

