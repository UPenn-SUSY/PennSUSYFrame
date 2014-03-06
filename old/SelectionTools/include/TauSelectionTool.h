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
    int c_baseline_jet_bdt_level_int;
    int c_baseline_ele_bdt_level_int;
    int c_baseline_muon_veto_level_int;

    TAU_JET_BDT_LEVEL m_baseline_jet_bdt_level;
    TAU_ELE_BDT_LEVEL m_baseline_ele_bdt_level;
    TAU_MU_LEVEL      m_baseline_muon_veto_level;

    // signal cut values
    int c_signal_jet_bdt_level_int;
    int c_signal_ele_bdt_level_int;
    int c_signal_muon_veto_level_int;

    TAU_JET_BDT_LEVEL m_signal_jet_bdt_level;
    TAU_ELE_BDT_LEVEL m_signal_ele_bdt_level;
    TAU_MU_LEVEL      m_signal_muon_veto_level;

    TH2* m_tau_ele_corr;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    void setJetBDTLevel(TAU_JET_BDT_LEVEL&, int);
    void setEleBDTLevel(TAU_ELE_BDT_LEVEL&, int);
    void setMuLevel(    TAU_MU_LEVEL&     , int);

    bool checkJetBDTLevel(const Tau*, TAU_JET_BDT_LEVEL);
    bool checkEleBDTLevel(const Tau*, TAU_ELE_BDT_LEVEL);
    bool checkMuLevel(    const Tau*, TAU_MU_LEVEL     );

    // bool getCorrectedEleBDTFlag(const Tau*);

    bool passCut(double test, double min, double max);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(TauSelectionTool, 0);
  };
}

#endif
