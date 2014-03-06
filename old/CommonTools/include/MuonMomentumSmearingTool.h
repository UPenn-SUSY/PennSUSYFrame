#ifndef CommonTools_MuonMomentumSmearingTool_h
#define CommonTools_MuonMomentumSmearingTool_h

// =============================================================================
#include <vector>
#include "AtlasSFrameUtils/include/ToolBase.h"

// ============================================================================
class Muon;

namespace MuonSmear
{
  class SmearingClass;
}

// ============================================================================
namespace CommonTools
{
  // ==========================================================================
  class MuonMomentumSmearingTool : public ToolBase
  {
  // --------------------------------------------------------------------------
  public:
    MuonMomentumSmearingTool(SCycleBase* parent, const char* name);
    ~MuonMomentumSmearingTool();

    void init();

    void BeginInputData( const SInputData& id );
    void EndInputData( const SInputData& id );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    double getSmearedPt(const Muon*);

  // --------------------------------------------------------------------------
  private:
    std::string m_muon_momentum_dir;
    MuonSmear::SmearingClass* m_mcp_smear;

    std::string c_smearing_function;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(MuonMomentumSmearingTool, 0);
  };
} // CommonTools

#endif // CommonTools_MuonMomentumSmearingTool_h
