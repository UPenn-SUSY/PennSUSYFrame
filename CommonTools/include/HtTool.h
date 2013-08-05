// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_HtTool_H
#define CommonTools_HtTool_H

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
  class HtTool
  {
  // ---------------------------------------------------------------------------
  public:
    HtTool();

    static double getHt( FLAVOR_CHANNEL
                       , const std::vector<Electron*>&
                       , const std::vector<Muon*>&
                       , const std::vector<Jet*>&
                       );
    static double getHtJets(const std::vector<Jet*>&);
    static double getHtLeptons( FLAVOR_CHANNEL
                              , const std::vector<Electron*>&
                              , const std::vector<Muon*>&
                              );

  // ---------------------------------------------------------------------------
  private:
  };

}

// Include the implementation:
#ifndef __CINT__
#include "HtTool.icc"
#endif // __CINT__


#endif

