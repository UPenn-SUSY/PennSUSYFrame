// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_VertexOutputTool_h
#define CommonTools_VertexOutputTool_h

// =============================================================================
#include "AtlasSFrameUtils/include/ToolBase.h"

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
  class VertexOutputTool : public ToolBase
  {
  // ---------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    VertexOutputTool(SCycleBase* parent, const char* name = "OutputTool");
    virtual ~VertexOutputTool();

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
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool c_do_detailed_output;
    std::string c_vertex_output_collection;

    //Variables to always output
    unsigned int              m_vtx_n;
    std::vector<float>        m_vtx_x;
    std::vector<float>        m_vtx_y;
    std::vector<float>        m_vtx_z;
    std::vector<unsigned int> m_vtx_n_tracks;
    std::vector<float>        m_vtx_sum_pt;

    // Detailed Variables to output only if configured to

    ClassDef(VertexOutputTool, 0);
  };
}

#endif
