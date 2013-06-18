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

class TH2;

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

    // virtual void BeginInputFile(const SInputData&) throw(SError);
    void configure();
    void process(Tau*, const VertexContainer&);
    bool isBaseline(Tau*);
    bool isSignal(Tau*);

    std::vector<Tau*> getBaselineTaus( const TauContainer&);
    std::vector<Tau*> getBaselineTaus( const std::vector<Tau*>& all_taus);

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

    std::string c_tau_ele_corr_file;
    int c_jet_bdt_level_int;
    int c_ele_bdt_level_int;
    int c_muon_veto_level_int;

    bool m_jet_bdt_level_configured;
    bool m_ele_bdt_level_configured;
    bool m_muon_veto_level_configured;

    TAU_JET_BDT_LEVEL m_jet_bdt_level;
    TAU_ELE_BDT_LEVEL m_ele_bdt_level;
    TAU_MU_LEVEL      m_muon_veto_level;

    TH2* m_tau_ele_corr;

    // // signal cut values

    bool getCorrectedEleBDTFlag(const Tau*);

    bool passCut(double test, double min, double max);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(TauSelectionTool, 0);
  };
}

#endif
