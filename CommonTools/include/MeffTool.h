// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_MeffTool_H
#define CommonTools_MeffTool_H

// =============================================================================
#include <vector>

#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class Electron;
class Muon;
class Jet;

// =============================================================================
namespace CommonTools{

  // ===========================================================================
  class MeffTool
  {
  // ---------------------------------------------------------------------------
  public:
    MeffTool();

    static double getMeff( FLAVOR_CHANNEL
                         , const std::vector<Electron*>&
                         , const std::vector<Muon*>&
                         , const std::vector<Jet*>&
                         );
    static double getMeffJets(const std::vector<Jet*>&);
    static double getMeffLeptons( FLAVOR_CHANNEL
                                , const std::vector<Electron*>&
                                , const std::vector<Muon*>&
                                );

  // ---------------------------------------------------------------------------
  private:
  };

}

// Include the implementation:
#ifndef __CINT__
#include "MeffTool.icc"
#endif // __CINT__


#endif

