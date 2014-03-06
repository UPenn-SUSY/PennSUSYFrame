// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_MllTool_H
#define CommonTools_MllTool_H
// ============================================================================
#include <vector>
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class Electron;
class Muon;

// ============================================================================
namespace CommonTools{
// ============================================================================
  /**
  * Helper class to check the sign channel of two objects
  */
  class MllTool
  {
  // --------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    MllTool();

    static double getMll( FLAVOR_CHANNEL
                        , const std::vector<Electron*>&
                        , const std::vector<Muon*>&
                        );

  // --------------------------------------------------------------------------
  private:
    // no private members
  };
}

#endif
