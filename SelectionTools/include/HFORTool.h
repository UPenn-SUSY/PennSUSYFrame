// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_HFORTool_h
#define SelectionTools_HFORTool_h

// =============================================================================
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "SUSYTools/HforToolD3PD.h"

// =============================================================================
namespace D3PDReader
{
  class TruthD3PDObject;
}
class Event;

// =============================================================================
namespace SelectionTools
{
  // ===========================================================================
  class HFORTool : public ToolBase
  {
    // ---------------------------------------------------------------------------
  public:
    HFORTool( SCycleBase* parent
            , const char* name = "EventCleaning"
	    );

    virtual ~HFORTool();

    bool passHFOR(const D3PDReader::TruthD3PDObject*);
    bool passSherpaWWOveralpRemoval(const Event*, const D3PDReader::TruthD3PDObject* );


  // ---------------------------------------------------------------------------
  private:

    bool c_do_hfor;

    HforToolD3PD m_hforTool;

    ClassDef(HFORTool, 0);

  };

}

#endif
