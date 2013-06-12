// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_TauSelectionTool_h
#define SelectionTools_TauSelectionTool_h

// =============================================================================
#include <vector>
#include "AtlasSFrameUtils/include/ToolBase.h"

// =============================================================================
class Tau;
class TauContainer;
class VertexContainer;

// ============================================================================
namespace SelectionTools
{
  // ==========================================================================
  class TauSelectionTool : public ToolBase
  {
  // --------------------------------------------------------------------------
  public:
    TauSelectionTool(SCycleBase* parent, const char* name = "CutTool");
    virtual ~TauSelectionTool();

    void process(Tau*, const VertexContainer&);
    bool isBaseline(Tau*);
    bool isSignal(Tau*);

    std::vector<Tau*> getBaselineTaus(const TauContainer&);
    std::vector<Tau*> getBaselineTaus(
        const std::vector<Tau*>& all_taus);

    std::vector<Tau*> getSignalTaus( const TauContainer&);
    std::vector<Tau*> getSignalTaus( const std::vector<Tau*>& good_taus);

  // --------------------------------------------------------------------------
  private:
    // = user configurables =
    // baseline cut values
    double c_baseline_min_pt;
    double c_baseline_max_pt;

    double c_baseline_min_eta;
    double c_baseline_max_eta;

    // // signal cut values

    bool passCut(double test, double min, double max);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(TauSelectionTool, 0);
  };
}

#endif
