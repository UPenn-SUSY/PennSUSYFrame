// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_MTTool_H
#define CommonTools_MTTool_H
// =============================================================================

#include "TLorentzVector.h"
#include "AtlasSFrameUtils/include/Met.h"

// =============================================================================
namespace CommonTools{

  // ===========================================================================
  class MTTool
  {
  // ---------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    MTTool();

    static double getMt( FLAVOR_CHANNEL
                       , const Met*
                       , const std::vector<Electron*>&
                       , const std::vector<Muon*>&
                       );

    static double getMt( const Electron*
                       , const Met*
                       );

    static double getMt( const Muon*
                       , const Met*
                       );

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    static double calcMt(const TLorentzVector, const TVector2);

    // template <class T1, class T2>
    //   static double calcMt(const T1*, const T2*, const Met*);
  };

}

// Include the implementation:
#ifndef __CINT__
#include "MTTool.icc"
#endif // __CINT__


#endif

