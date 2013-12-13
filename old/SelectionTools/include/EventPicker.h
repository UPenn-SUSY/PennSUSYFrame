// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_EventPicker_h
#define SelectionTools_EventPicker_h

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "GoodRunsLists/TGoodRunsList.h"

// =============================================================================
class Event;

// ============================================================================
namespace SelectionTools
{
  // ==========================================================================
  class EventPicker : public ToolBase
  {
  // --------------------------------------------------------------------------
  public:
    EventPicker(SCycleBase* parent, const char* name = "CutTool");
    virtual ~EventPicker();

    void BeginCycle();
    void BeginInputData(const SInputData&);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool passed(const Event&);
    bool passed(const unsigned int run, const unsigned int event);
    //
  // --------------------------------------------------------------------------
  private:
    // = user configurables =
    bool c_do_event_picker;
    std::string c_event_list_file;

    std::vector<unsigned int> m_good_events;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(EventPicker, 0);
  };
}

#endif
