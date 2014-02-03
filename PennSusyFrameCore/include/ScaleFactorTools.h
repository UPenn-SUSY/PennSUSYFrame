#ifndef PennSusyFrameCore_ScaleFactorTools_h
#define PennSusyFrameCore_ScaleFactorTools_h

#include "RootCore/ElectronEfficiencyCorrection/ElectronEfficiencyCorrection/TElectronEfficiencyCorrectionTool.h"
#include "RootCore/MuonEfficiencyCorrections/MuonEfficiencyCorrections/AnalysisMuonConfigurableScaleFactors.h"

// =============================================================================
namespace PennSusyFrame{
  class Event;
  class Electron;
  class Muon;
}

// =============================================================================
namespace PennSusyFrame
{
  // =============================================================================
  class EgammaScaleFactorTool
  {
    // -----------------------------------------------------------------------------
    public:
      EgammaScaleFactorTool();

      double getSF( const PennSusyFrame::Event&
                  , const PennSusyFrame::Electron*
                  );

    // -----------------------------------------------------------------------------
    private:
      bool m_is_af2;

      std::string m_egamma_sf_dir;
      std::string m_reco_file_name;
      std::string m_tight_file_name;
      // std::string m_trigger_file_name;

      Root::TElectronEfficiencyCorrectionTool m_eg_reco_sf;
      Root::TElectronEfficiencyCorrectionTool m_eg_tight_sf;
      // Root::TElectronEfficiencyCorrectionTool m_eg_trigger_sf;
  };

  // =============================================================================
  class MuonScaleFactorTool
  {
    // -----------------------------------------------------------------------------
    public:
      MuonScaleFactorTool();
      ~MuonScaleFactorTool();

      double getSF(const PennSusyFrame::Muon*);

    // -----------------------------------------------------------------------------
    private:
      std::string m_muon_sf_dir;
      std::string m_muon_type;
      std::string m_unit;
      std::string m_file_name;

      // std::vector<double> m_muon_sf_int_lum;
      Analysis::AnalysisMuonConfigurableScaleFactors::Configuration m_configuration;
      Analysis::AnalysisMuonConfigurableScaleFactors* m_muon_sf;
  };
}

#endif
