#ifndef PENNSUSYFRAME_RESCALERTOOLS_H
#define PENNSUSYFRAME_RESCALERTOOLS_H

#include <string>
#include "TLorentzVector.h"

// =============================================================================
namespace egRescaler
{
  class EnergyRescalerUpgrade;
}

namespace MuonSmear
{
  class SmearingClass;
}

// =============================================================================
namespace PennSusyFrame
{
  class Event;
  class Electron;
  class Muon;
  class Jet;
  class Vertex;
}

namespace MuonSmear
{
  class SmearingClass;
}

class JetCalibrationTool;

// =============================================================================
namespace PennSusyFrame
{
  // =============================================================================
  class ElectronRescalerTool
  {
    public:
      ElectronRescalerTool(bool is_data, bool is_af2);
      ~ElectronRescalerTool();

      void init();

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
      MuonRescalerTool(bool is_data);
      ~MuonRescalerTool();

      void init();

      double getSmearedPt(const PennSusyFrame::Muon*);

    private:
      bool m_is_data;

      std::string m_muon_momentum_dir;
      MuonSmear::SmearingClass* m_mcp_smear;

      std::string m_smearing_function;
  };

  // =============================================================================
  class JetRescalerTool
  {
    public:
      JetRescalerTool(bool is_data, bool is_af2);
      ~JetRescalerTool();

      void init();

      TLorentzVector getCalibratedTlv( const PennSusyFrame::Jet*
                                     , const PennSusyFrame::Event*
                                     , int num_vertices_ge_2_tracks
                                     );

    private:
      bool m_is_data;
      bool m_is_af2;

      JetCalibrationTool* m_jet_calibration;
  };

  // =============================================================================
  // TODO finish writing TauRescalerTool
  class TauRescalerTool
  {
    public:
      TauRescalerTool(bool is_data, bool is_af2);
      ~TauRescalerTool();

      void init();

    private:
      bool m_is_data;
      bool m_is_af2;
  };
}

#endif
