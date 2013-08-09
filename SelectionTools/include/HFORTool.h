// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_HFORTool_h
#define SelectionTools_HFORTool_h

// =============================================================================
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "SUSYTools/HforToolD3PD.h"
#include "CommonTools/include/TruthMatchTool.h"
// =============================================================================
namespace D3PDReader
{
  class TruthD3PDObject;
}
class Event;

namespace CommonTools
{
  class TruthMatchTool;
}

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
    bool passZOverlapRemoval(const D3PDReader::TruthD3PDObject*, CommonTools::TruthMatchTool*);

  // ---------------------------------------------------------------------------
  private:

    bool c_do_hfor;

    HforToolD3PD m_hforTool;

    ClassDef(HFORTool, 0);

  };

}

#endif
