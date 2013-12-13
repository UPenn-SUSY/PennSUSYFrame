#ifndef CommonTools_TriggerReweightTool_h
#define CommonTools_TriggerReweightTool_h

// =============================================================================
#include <vector>
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class Electron;
class Muon;
class Jet;
class Met;
class VertexContainer;
class triggerReweight2Lep;

// =============================================================================
namespace CommonTools
{
  // ===========================================================================
  class TriggerReweightTool : public ToolBase
  {
  // ---------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    TriggerReweightTool(SCycleBase* parent, const char* name);
    ~TriggerReweightTool();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    void BeginInputData( const SInputData& id );
    void EndInputData( const SInputData& id );
    void BeginCycle();

    void clear();
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    double getTriggerWeight( FLAVOR_CHANNEL flavor_channel
                           , const std::vector<Electron*>& el
                           , const std::vector<Muon*>& mu
                           , const std::vector<Jet*>& jet
                           , Met*
                           , VertexContainer&
                           );

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool c_do_trigger_sf;

    triggerReweight2Lep* m_trigger_reweight;

    std::string c_reweight_directory;
    std::string c_reweight_period;

    double m_trigger_weight;
    bool   m_is_cached;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(TriggerReweightTool, 0);
  };
} // CommonTools

#endif // CommonTools_TriggerReweightTool_h
