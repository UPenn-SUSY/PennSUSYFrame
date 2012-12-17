// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_MeffTool_H
#define CommonTools_MeffTool_H
// =============================================================================

#include "TLorentzVector.h"
#include "AtlasSFrameUtils/include/Met.h"

// =============================================================================
namespace CommonTools{

  // ===========================================================================
  class MeffTool
  {
  // ---------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    MeffTool();

    static double getMeff( FLAVOR_CHANNEL
                         , const std::vector<Electron*>&
                         , const std::vector<Muon*>&
                         , const std::vector<Jet*>&
                         );

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  };

}

// Include the implementation:
#ifndef __CINT__
#include "MeffTool.icc"
#endif // __CINT__


#endif

