// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_DeltaPhiTool_H
#define CommonTools_DeltaPhiTool_H
// ============================================================================
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/Met.h"

#include "SusyAnalysisTools/include/SusyEnums.h"

// ============================================================================
namespace CommonTools{
// ============================================================================
  /**
  * Helper class to check the sign channel of two objects
  */
  class DeltaPhiTool
  {
  // --------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    DeltaPhiTool();

    template <class T>
      static double getDeltaPhi(const T*, const Met*);

    // static double getDeltaPhi(const Electron*, const Met*);
    // static double getDeltaPhi(const Muon*    , const Met*);
    // static double getDeltaPhi(const Jet*     , const Met*);

    static double getDeltaPhi( FLAVOR_CHANNEL
                             , const std::vector<Electron*>&
                             , const std::vector<Muon*>&
                             , const Jet*
                             );

  // --------------------------------------------------------------------------
  private:
    // no private members
  };
}

// Include the implementation:
#ifndef __CINT__
#include "DeltaPhiTool.icc"
#endif // __CINT__

#endif
