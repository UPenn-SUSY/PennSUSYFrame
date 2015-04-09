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
  struct SystematicStruct;
}

namespace MuonSmear
{
  class SmearingClass;
}
namespace JetAnalysisCalib {
  class JetCalibrationTool;
}
class JetSmearingTool;
class MultijetJESUncertaintyProvider;

// =============================================================================
namespace PennSusyFrame
{
  // =============================================================================
  class ElectronRescalerTool
  {
    public:
      ElectronRescalerTool( bool is_data
                          , bool is_af2
                          , PennSusyFrame::SystematicStruct* syst_struct = 0
                          );
      ~ElectronRescalerTool();

      void init();

      double getRescaledE( const PennSusyFrame::Electron*);
      double getRescaledEt(const PennSusyFrame::Electron*);

      double applyEES(double el_e, double eta);

    private:
      bool m_is_data;
      bool m_is_af2;

      SystematicStruct* m_syst_struct;

      egRescaler::EnergyRescalerUpgrade* m_e_rescale;
  };

  // =============================================================================
  class MuonRescalerTool
  {
    public:
      MuonRescalerTool( bool is_data
                      , PennSusyFrame::SystematicStruct* syst_struct = 0
                      );
      ~MuonRescalerTool();

      void init();

      double getSmearedPt(const PennSusyFrame::Muon*);

    private:
      bool m_is_data;

      SystematicStruct* m_syst_struct;

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
                   , PennSusyFrame::SystematicStruct* syst_struct = 0
                   );
    ~JetRescalerTool();

    void init();

    TLorentzVector getCalibratedTlv( const PennSusyFrame::Jet*
                                   , const PennSusyFrame::Event*
                                   , int num_vertices_ge_2_tracks
                                   );
    void applyJER(TLorentzVector&);
    void applyJES( TLorentzVector&
                 , int flavor_truth_label
                 , int num_vert_ge_2_trk
                 , float mu
                 );

    private:
      bool m_is_data;
      bool m_is_af2;
      bool m_is_mc12b;

      SystematicStruct* m_syst_struct;

      JetAnalysisCalib::JetCalibrationTool* m_jet_calibration;
      JetSmearingTool* m_jer_smearing;
      MultijetJESUncertaintyProvider* m_jes_tool;
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
