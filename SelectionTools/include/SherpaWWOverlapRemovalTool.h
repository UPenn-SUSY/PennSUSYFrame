// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_SherpaWWOverlapRemovalTool_h
#define SelectionTools_SherpaWWOverlapRemovalTool_h

// =============================================================================
#include "AtlasSFrameUtils/include/ToolBase.h"

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
  class SherpaWWOverlapRemovalTool : public ToolBase
  {
    // ---------------------------------------------------------------------------
  public:
    SherpaWWOverlapRemovalTool( SCycleBase* parent
            , const char* name = "EventCleaning"
	    );

    virtual ~SherpaWWOverlapRemovalTool();

    bool passOveralpRemoval(const Event*, const D3PDReader::TruthD3PDObject* );


  // ---------------------------------------------------------------------------
  private:

    bool c_do_hfor;

    ClassDef(SherpaWWOverlapRemovalTool, 0);
  };
}

#endif
