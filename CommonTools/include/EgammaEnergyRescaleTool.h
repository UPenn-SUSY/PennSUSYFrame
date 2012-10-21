#ifndef CommonTools_EgammaEnergyRescaleTool_h
#define CommonTools_EgammaEnergyRescaleTool_h

#include <vector>

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "egammaAnalysisUtils/EnergyRescalerUpgrade.h"

// ============================================================================
class Electron;

// ============================================================================
namespace CommonTools
{
  // ==========================================================================
  class EgammaEnergyRescaleTool : public ToolBase
  {
  // --------------------------------------------------------------------------
  public:
    EgammaEnergyRescaleTool(SCycleBase* parent, const char* name);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    void BeginInputData(const SInputData& id);
    void EndInputData(const SInputData& id);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // electrons
    double getRescaledE( const Electron*);
    double getRescaledEt(const Electron*);

  // --------------------------------------------------------------------------
  private:
    egRescaler::EnergyRescalerUpgrade m_eRescale;

    // Use configurable flag c_apply_systematics to set:
    // - 0 (nominal)
    // - 1 (down)
    // - 2 (up)
    int c_apply_systematics;

    // apply an additional energy correction for ATLFast 2 samples
    bool c_is_af2;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(EgammaEnergyRescaleTool, 0);
  };
} // CommonTools

#endif // EgammaTools_EgammaEnergyRescaleTool_h
