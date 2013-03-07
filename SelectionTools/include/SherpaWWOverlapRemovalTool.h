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

    bool passOveralpRemoval();


  // ---------------------------------------------------------------------------
  private:

    bool c_do_hfor;

    ClassDef(SherpaWWOverlapRemovalTool, 0);
  };
}

#endif
