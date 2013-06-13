// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_TauSelectionTool_h
#define SelectionTools_TauSelectionTool_h

// =============================================================================
#include <vector>
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

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

    TAU_JET_BDT_LEVEL c_jet_bdt_level;
    TAU_ELE_BDT_LEVEL c_ele_bdt_level;
    TAU_MU_LEVEL c_muon_veto_level;

    // // signal cut values

    bool getCorrectedEleBDTFlag(const Tau*, TAU_ELE_BDT_LEVEL, bool do_correction = false);

    bool passCut(double test, double min, double max);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(TauSelectionTool, 0);
  };
}

#endif
