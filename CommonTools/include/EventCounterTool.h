// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_EventCounterTool_h
#define CommonTools_EventCounterTool_h

// =============================================================================
#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// =============================================================================
class Event;
class TH1D;

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
    virtual void EndInputData( const SInputData& );

    void countEvent(const Event*);
  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    TH1D* m_event_weights;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(EventCounterTool, 0);
  };
}

#endif
