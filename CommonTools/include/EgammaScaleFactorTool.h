#ifndef CommonTools_EgammaScaleFactorTool_h
#define CommonTools_EgammaScaleFactorTool_h

#include <vector>

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "egammaAnalysisUtils/egammaSFclass.h"

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
		  , int set = 7
		  , int rel = 10
		  , int mode = 0
		  , int range = 0
		  );
    double getSFUncertainty( Electron*
			     , int set = 7
			     , int rel = 10
			     , int mode = 0
			     , int range = 0
			     );
    // ----------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool c_do_scaling;

    egammaSFclass m_eg_sf;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(EgammaScaleFactorTool, 0);
  };
} // CommonTools

#endif // CommonTools_EgammaScaleFactorTool_h

