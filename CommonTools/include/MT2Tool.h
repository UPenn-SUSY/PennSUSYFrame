// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_MT2Tool_H
#define CommonTools_MT2Tool_H
// =============================================================================

#include "TLorentzVector.h"
#include "AtlasSFrameUtils/include/Met.h"

#include "mt2_bisect.h"

// =============================================================================
namespace CommonTools{

  // ===========================================================================
  class MT2Tool
  {
  // ---------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    MT2Tool();

    static double getMt2( FLAVOR_CHANNEL
                        , const Met*
                        , const std::vector<Electron*>&
                        , const std::vector<Muon*>&
                        , double minv = 0
                        );

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    template <class T1, class T2>
      static double calcMt2(const T1*, const T2*, const Met*, double minv = 0);
  };

}

// Include the implementation:
#ifndef __CINT__
#include "MT2Tool.icc"
#endif // __CINT__


#endif

