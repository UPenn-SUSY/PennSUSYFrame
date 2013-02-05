#ifndef CommonTools_EgammaScaleFactorTool_h
#define CommonTools_EgammaScaleFactorTool_h

#include <vector>

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Event.h"
//#include "egammaAnalysisUtils/egammaSFclass.h"
//#include "ElectronEfficiencyCorretion/TElectronEfficiencyCorrectionTool.h"
#include "ElectronEfficiencyCorrection/TElectronEfficiencyCorrectionTool.h"
#include "PATCore/TResult.h"

// ============================================================================
namespace CommonTools
{
  // ============================================================================
  class EgammaScaleFactorTool : public ToolBase
  {
    // ----------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    EgammaScaleFactorTool(SCycleBase* parent, const char* name);
    // ~EgammaScaleFactorTool();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    void BeginInputData( const SInputData& id );
    void EndInputData( const SInputData& id );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // TODO tune rel based on FullSim vs FastSim
    // "HCP 2012 recommendations" G4 FullSim MC (rel=10)
    // "HCP 2012 recommendations" AFII MC (rel=11)
    double getSF( Electron*
		, Event* );
    double getSFUncertainty( Electron*,
			     Event* );
    // ----------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool c_do_scaling;
    std::string c_egamma_sf_dir;

    std::string m_reco_file_name;
    std::string m_tight_file_name;
    std::string m_trigger_file_name;

    Root::TElectronEfficiencyCorrectionTool m_eg_reco_sf;
    Root::TElectronEfficiencyCorrectionTool m_eg_tight_sf;
    Root::TElectronEfficiencyCorrectionTool m_eg_trigger_sf;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(EgammaScaleFactorTool, 0);
  };
} // CommonTools

#endif // CommonTools_EgammaScaleFactorTool_h

