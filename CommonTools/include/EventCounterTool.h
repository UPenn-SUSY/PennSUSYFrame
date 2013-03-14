// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_EventCounterTool_h
#define CommonTools_EventCounterTool_h

// =============================================================================
#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class Event;

// =============================================================================
namespace CommonTools
{
// =============================================================================
  class EventCounterTool : public ToolBase
  {
  // ---------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    EventCounterTool(SCycleBase* parent, const char* name = "OutputTool");
    virtual ~EventCounterTool();

    virtual void BeginInputData( const SInputData& );
    virtual void BeginExecuteEvent( const SInputData&, Double_t );

    void countEvent(const Event*);
  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    unsigned int m_raw_events;
    double m_weighted_events;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(EventCounterTool, 0);
  };
}

#endif
