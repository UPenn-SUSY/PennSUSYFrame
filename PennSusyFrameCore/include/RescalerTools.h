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
namespace JetAnalysisCalib {
  class JetCalibrationTool;
}
class JetSmearingTool;

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
    JetRescalerTool( bool is_data
                   , bool is_af2
                   , bool is_mc12b
                   , bool do_jer      = false
                   , bool do_jes_up   = false
                   , bool do_jes_down = false
                   );
    ~JetRescalerTool();

    void init();

    TLorentzVector getCalibratedTlv( const PennSusyFrame::Jet*
                                     , const PennSusyFrame::Event*
                                     , int num_vertices_ge_2_tracks
                                     );
    // void applyJER(PennSusyFrame::Jet*, bool is_af2);
    void applyJER(TLorentzVector&, bool is_af2);

    private:
      bool m_is_data;
      bool m_is_af2;
      bool m_is_mc12b;
      bool m_do_jer;
      bool m_do_jes_up;
      bool m_do_jes_down;
      JetAnalysisCalib::JetCalibrationTool* m_jet_calibration;
      JetSmearingTool* m_jer_smearing;
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
