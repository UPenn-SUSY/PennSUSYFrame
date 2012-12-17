// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_EtallTool_H
#define CommonTools_EtallTool_H
// =============================================================================
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Muon.h"

#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
namespace CommonTools{
// =============================================================================
  /**
  * Helper class to check the sign channel of two objects
  */
  class EtallTool
  {
  // ---------------------------------------------------------------------------
  public:
    EtallTool();

    static double getEtall( FLAVOR_CHANNEL
                          , const std::vector<Electron*>&
                          , const std::vector<Muon*>&
                          );

  // ---------------------------------------------------------------------------
  private:
    // no private members
  };
}

#endif
