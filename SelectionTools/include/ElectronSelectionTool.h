// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_ElectronSelectionTool_h
#define SelectionTools_ElectronSelectionTool_h

#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/ElectronContainer.h"
#include "AtlasSFrameUtils/include/ToolBase.h"

#include "egammaAnalysisUtils/IsEMPlusPlusDefs.h"
#include "egammaEvent/egammaPIDdefs.h"

// ============================================================================
namespace SelectionTools
{
  // ==========================================================================
  class ElectronSelectionTool : public ToolBase
  {
  // --------------------------------------------------------------------------
  public:
    ElectronSelectionTool(SCycleBase* parent, const char* name = "CutTool");
    virtual ~ElectronSelectionTool();

    bool isBaseline(Electron*);
    bool isSignal(Electron*);

    std::vector<Electron*> getBaselineElectrons(const ElectronContainer&);
    std::vector<Electron*> getBaselineElectrons(
        const std::vector<Electron*>& all_electrons);

    std::vector<Electron*> getSignalElectrons(const ElectronContainer&);
    std::vector<Electron*> getSignalElectrons(
        const std::vector<Electron*>& good_electrons);

  // --------------------------------------------------------------------------
  private:
    // = user configurables =
    // baseline cut values
    double c_baseline_min_pt;
    double c_baseline_max_pt;

    double c_baseline_min_eta;
    double c_baseline_max_eta;

    // signal cut values
    double c_signal_min_d0_sig;
    double c_signal_max_d0_sig;

    double c_signal_min_z0_sin_theta;
    double c_signal_max_z0_sin_theta;

    double c_signal_min_ptcone_cut;
    double c_signal_max_ptcone_cut;

    double c_signal_min_etcone_cut;
    double c_signal_max_etcone_cut;

    // TODO Add flag to recalculate med++, tight++

    bool passCut(double test, double min, double max);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(ElectronSelectionTool, 0);
  };
}

#endif
