// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_PhillTool_H
#define CommonTools_PhillTool_H

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
  class PhillTool
  {
  // --------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    PhillTool();

    static double getPhill( FLAVOR_CHANNEL
                          , const std::vector<Electron*>&
                          , const std::vector<Muon*>&
                          );

  // --------------------------------------------------------------------------
  private:
    // no private members
  };
}

#endif
