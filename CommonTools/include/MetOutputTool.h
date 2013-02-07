// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_MetOutputTool_h
#define CommonTools_MetOutputTool_h

// =============================================================================
#include "TLorentzVector.h"

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class Event;
class ElectronContainer;
class MuonContainer;
class JetContainer;
class Met;
class VertexContainer;

class SusyDiLeptonCutFlowCycle;
class SusyDiLeptonChargeFlipCycle;

// =============================================================================
namespace CommonTools
{
// =============================================================================
  class MetOutputTool : public ToolBase
  {
  // ---------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    MetOutputTool(SCycleBase* parent, const char* name = "OutputTool");
    virtual ~MetOutputTool();

    virtual void BeginInputData( const SInputData& );
    virtual void BeginExecuteEvent( const SInputData&, Double_t );

    void fillOutput( Event*
                   , ElectronContainer&
                   , MuonContainer&
                   , JetContainer&
                   , Met*
                   , VertexContainer&
                   );

  // ---------------------------------------------------------------------------
  private:

    bool c_do_detailed_output;

    //Variables to always output
    float m_met_et;
    float m_met_rel_et;
    float m_met_rel_delta_phi;
    float m_met_phi;
    float m_met_sumet;
    float m_dphi_met_ll;

    TVector2 m_met_vec;

    // Detailed Variables to output only if configured to

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(MetOutputTool, 0);
  };
}

#endif
