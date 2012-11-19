// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_VertexOutputTool_h
#define CommonTools_VertexOutputTool_h

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
  class VertexOutputTool : public ToolBase
  {
  // ----------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    VertexOutputTool(SCycleBase* parent, const char* name = "OutputTool");
    virtual ~VertexOutputTool();

    virtual void BeginInputData( const SInputData& );
    virtual void BeginExecuteEvent( const SInputData&, Double_t );


    void fillOutput(Event*, ElectronContainer, MuonContainer, JetContainer, Met*, VertexContainer );

  // ----------------------------------------------------------------------------
  private:

    bool c_do_detailed_output;
    std::string c_vertex_output_collection;

    //Variables to always output

    unsigned int              m_vtx_n;
    std::vector<double>       m_vtx_x;
    std::vector<double>       m_vtx_y;
    std::vector<double>       m_vtx_z;
    std::vector<unsigned int> m_vtx_n_tracks;
    std::vector<double>       m_vtx_sum_pt;

 
    // Detailed Variables to output only if configured to 



    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(VertexOutputTool, 0);
  };
}

#endif
