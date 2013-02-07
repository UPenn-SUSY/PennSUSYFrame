#ifndef CommonTools_JetCalib_h
#define CommonTools_JetCalib_h

// =============================================================================
#include "TLorentzVector.h"

#include "AtlasSFrameUtils/include/ToolBase.h"

#include "ApplyJetCalibration/ApplyJetCalibration.h"
#include "JetUncertainties/MultijetJESUncertaintyProvider.h"

// ============================================================================
class Event;
class Jet;

// ============================================================================
namespace CommonTools
{
  // ==========================================================================
  class JetCalibTool : public ToolBase
  {
  // --------------------------------------------------------------------------
  public:
    JetCalibTool(SCycleBase* parent, const char* name);
    ~JetCalibTool();

    void BeginInputData(const SInputData& id);
    void EndInputData(  const SInputData& id);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    TLorentzVector getConfiguredJet( Jet* jet
                                   , const Event* event
                                   , int num_vertices_w_2_trks
                                   );

  // --------------------------------------------------------------------------
  private:
    bool c_is_af2;
    JetCalibrationTool* m_jet_calibration;
    MultijetJESUncertaintyProvider* m_jes_uncertainty;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(JetCalibTool, 0);
  };
} // CommonTools

#endif // CommonTools_JetCalibTool_h
