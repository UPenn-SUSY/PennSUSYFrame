// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_DeltaPhiTool_H
#define CommonTools_DeltaPhiTool_H

// ============================================================================
#include <vector>
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class Electron;
class Muon;
class Jet;
class Met;

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

    static double getDeltaPhi( FLAVOR_CHANNEL
                             , const std::vector<Electron*>&
                             , const std::vector<Muon*>&
                             );
    static double getDeltaPhi( FLAVOR_CHANNEL
                             , const std::vector<Electron*>&
                             , const std::vector<Muon*>&
                             , const Jet*
                             );

    static double getDeltaPhi( FLAVOR_CHANNEL
                             , const std::vector<Electron*>&
                             , const std::vector<Muon*>&
                             , const Met*
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
