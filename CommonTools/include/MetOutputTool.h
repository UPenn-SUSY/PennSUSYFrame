// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_MetOutputTool_h
#define CommonTools_MetOutputTool_h

#include "AtlasSFrameUtils/include/ToolBase.h"

#include "AtlasSFrameUtils/include/Event.h"
#include "AtlasSFrameUtils/include/ElectronContainer.h"
#include "AtlasSFrameUtils/include/MuonContainer.h"
#include "AtlasSFrameUtils/include/JetContainer.h"
#include "AtlasSFrameUtils/include/Met.h"
#include "AtlasSFrameUtils/include/VertexContainer.h"

#include "SusyAnalysisTools/include/SusyEnums.h"

// ============================================================================
// Forward declare SusyDiLeptonCutFlowCycle
class SusyDiLeptonCutFlowCycle;
class SusyDiLeptonChargeFlipCycle;
// ============================================================================
namespace CommonTools
{
// ============================================================================
  class MetOutputTool : public ToolBase
  {
  // ----------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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

  // ----------------------------------------------------------------------------
  private:

    bool c_do_detailed_output;
    std::string c_electron_output_collection;
    std::string c_muon_output_collection;
    std::string c_jet_output_collection;


    //Variables to always output


    double m_met_et;
    double m_met_rel_et;
    double m_met_rel_delta_phi;
    double m_met_phi;
    double m_met_sumet;


    // Detailed Variables to output only if configured to



    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(MetOutputTool, 0);
  };
}

#endif
