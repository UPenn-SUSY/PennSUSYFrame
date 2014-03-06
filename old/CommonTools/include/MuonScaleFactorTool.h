#ifndef CommonTools_MuonScaleFactorTool_h
#define CommonTools_MuonScaleFactorTool_h

// ============================================================================
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "CommonTools/include/PileUpScaleFactorTool.h"
#include "MuonEfficiencyCorrections/AnalysisMuonConfigurableScaleFactors.h"

// =============================================================================
class Muon;

// =============================================================================
namespace CommonTools
{
  // ============================================================================
  class MuonScaleFactorTool : public ToolBase
  {
  // ----------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    MuonScaleFactorTool(SCycleBase* parent, const char* name);
    ~MuonScaleFactorTool();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    void BeginInputData( const SInputData& id );
    void EndInputData( const SInputData& id );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    double getSF(Muon*);
    double getSFUncertainty(Muon*);
    double getSFSystematic(Muon*);

  // ----------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool c_do_scaling;
    std::string c_muon_sf_dir;
    std::string c_muon_type;
    std::string c_unit;

    std::string m_file_name;
    // std::string m_sf_dir;
    Analysis::AnalysisMuonConfigurableScaleFactors::Configuration m_configuration;

    std::vector<double> m_muon_sf_int_lum;
    // Analysis::AnalysisMuonEfficiencyScaleFactors* m_muon_sf;
    Analysis::AnalysisMuonConfigurableScaleFactors* m_muon_sf;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(MuonScaleFactorTool, 0);
  };
} // CommonTools

#endif // CommonTools_MuonScaleFactorTool_h
