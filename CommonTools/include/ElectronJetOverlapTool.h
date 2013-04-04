// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_ElectronJetOverlapTool_H
#define CommonTools_ElectronJetOverlapTool_H
// =============================================================================
#include <vector>
#include "TLorentzVector.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class JetContainer;
class Met;

// =============================================================================
namespace CommonTools{

  // ===========================================================================
  class ElectronJetOverlapTool
  {
  // ---------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ElectronJetOverlapTool();

    static double getSumPtJets(const JetContainer*);
    static double getOLJet(const Met*, const JetContainer*);
    static double getOLRatio(const Met*, const JetContainer*);

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  };
}

#endif

