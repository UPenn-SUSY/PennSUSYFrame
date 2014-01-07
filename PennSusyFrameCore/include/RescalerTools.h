#ifndef PENNSUSYFRAME_RESCALERTOOLS_H
#define PENNSUSYFRAME_RESCALERTOOLS_H

// =============================================================================
#include "RootCore/egammaAnalysisUtils/egammaAnalysisUtils/EnergyRescalerUpgrade.h"

// =============================================================================
namespace PennSusyFrame
{
  class Electron;
}

// =============================================================================
namespace PennSusyFrame
{
  // =============================================================================
  class ElectronRescalerTool
  {
    public:
      ElectronRescalerTool();
      ~ElectronRescalerTool();

      double getRescaledE( const PennSusyFrame::Electron*);
      double getRescaledEt(const PennSusyFrame::Electron*);

    private:
      bool m_is_data;
      bool m_is_af2;

      // Use configurable flag c_apply_systematics to set:
      // - 0 (nominal)
      // - 1 (down)
      // - 2 (up)
      int m_systematics;

      egRescaler::EnergyRescalerUpgrade* m_e_rescale;
  };

  // =============================================================================
  class MuonRescalerTool
  {
    public:
      MuonRescalerTool();

    private:

  };

  // =============================================================================
  class JetRescalerTool
  {
    public:
      JetRescalerTool();

    private:

  };

}

#endif
