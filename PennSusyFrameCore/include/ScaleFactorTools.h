#ifndef PennSusyFrameCore_ScaleFactorTools_h
#define PennSusyFrameCore_ScaleFactorTools_h

#include "RootCore/ElectronEfficiencyCorrection/ElectronEfficiencyCorrection/TElectronEfficiencyCorrectionTool.h"
#include "RootCore/MuonEfficiencyCorrections/MuonEfficiencyCorrections/AnalysisMuonConfigurableScaleFactors.h"

#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"

// =============================================================================
namespace PennSusyFrame{
  class Event;
  class Electron;
  class Muon;
  class Jet;
  class MCTruth;
  class Vertex;
  class Met;
}

namespace Root
{
  class TPileupReweighting;
}

class BTagCalib;
class triggerReweight2Lep;

// =============================================================================
namespace PennSusyFrame
{
  // ===========================================================================
  class PileUpScaleFactorTool
  {
    // -------------------------------------------------------------------------
    public:
      PileUpScaleFactorTool();
      ~PileUpScaleFactorTool();

      double getPileupScaleFactor( const PennSusyFrame::Event&
                                 , const PennSusyFrame::MCTruth&
                                 );
      int getRandomRunNumber( int, double);
      int getRandomLumiBlockNumber( int );
      void setRandomSeed(int);
    // -------------------------------------------------------------------------
    private:
      std::string m_data_hist_name;
      std::string m_mc_hist_name;
      std::string m_pile_up_data_file;
      std::string m_pile_up_mc_file;

      Root::TPileupReweighting* m_pile_up_reweight;
  };

  // ===========================================================================
  class EgammaScaleFactorTool
  {
    // -------------------------------------------------------------------------
    public:
      EgammaScaleFactorTool();
      void init();

      // TODO move accessors to cxx file
      void setFullSim() { m_is_af2 = false; }
      void setAf2()     { m_is_af2 = true; }

      void setTightPP()  { m_is_tightpp = true;  }
      void setMediumPP() { m_is_tightpp = false; }

      void clear();
      void   prep( const PennSusyFrame::Event&
                 , const PennSusyFrame::Electron*
                 );
      double getSF( const PennSusyFrame::Event&
                  , const PennSusyFrame::Electron*
                  , bool  do_reco = true
                  , bool  do_id   = true
                  );
      double getUncert( const PennSusyFrame::Event&
                      , const PennSusyFrame::Electron*
                      , bool  do_reco = true
                      , bool  do_id   = true
                      );

    // -------------------------------------------------------------------------
    private:
      bool m_is_af2;
      bool m_is_tightpp;

      bool m_is_prepped;

      std::string m_egamma_sf_dir;
      std::string m_reco_file_name;
      std::string m_tight_file_name;
      std::string m_medium_file_name;
      // std::string m_trigger_file_name;

      Root::TElectronEfficiencyCorrectionTool m_eg_reco_sf;
      Root::TElectronEfficiencyCorrectionTool m_eg_id_sf;
      // Root::TElectronEfficiencyCorrectionTool m_eg_trigger_sf;

      PATCore::ParticleDataType::DataType m_data_type;

      Root::TResult m_result_reco;
      Root::TResult m_result_id;
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

  // =============================================================================
  class TriggerWeightTool
  {
    // -----------------------------------------------------------------------------
    public:
      TriggerWeightTool();
      ~TriggerWeightTool();

      double getWeight( FLAVOR_CHANNEL
                      , const std::vector<PennSusyFrame::Electron*>*
                      , const std::vector<PennSusyFrame::Muon*>*
                      , const std::vector<PennSusyFrame::Jet*>*
                      , const PennSusyFrame::Met&
                      , const std::vector<PennSusyFrame::Vertex*>*
                      );

    // -----------------------------------------------------------------------------
    private:
      triggerReweight2Lep* m_trigger_reweight;

      std::string m_reweight_directory;
      std::string m_reweight_period;
  };

  // =============================================================================
  class BTagScaleFactorTool
  {
    // -----------------------------------------------------------------------------
    public:
      BTagScaleFactorTool();
      ~BTagScaleFactorTool();

      void init(float mv1_cut_value = 0.3511);

      double getSF(const std::vector<PennSusyFrame::Jet*>*);

    // -----------------------------------------------------------------------------
    private:
      std::string m_calibration_file;
      std::string m_calibration_folder;

      BTagCalib* m_b_tag_calibration;
  };
}

#endif
