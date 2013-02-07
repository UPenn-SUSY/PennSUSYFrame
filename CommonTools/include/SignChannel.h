// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_SignChannel_H
#define CommonTools_SignChannel_H

// ============================================================================
#include <vector>
#include "SusyAnalysisTools/include/SusyEnums.h"

#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Muon.h"

// =============================================================================
class Electron;
class Muon;

// ============================================================================
namespace CommonTools{
// ============================================================================
  /**
  * Helper class to check the sign channel of two objects
  */
  class SignChannel
  {
  // --------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    SignChannel();

    static SIGN_CHANNEL getSignChannel( FLAVOR_CHANNEL
                                      , const std::vector<Electron*>&
                                      , const std::vector<Muon*>&
                                      );

  // --------------------------------------------------------------------------
  private:
    // no private members
  };
}

#endif
