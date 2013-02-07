#include "SelectionTools/include/EventPicker.h"

#include <math.h>

#include "AtlasSFrameUtils/include/Event.h"
#include "AtlasSFrameUtils/include/ToolBase.h"

// ----------------------------------------------------------------------------
SelectionTools::EventPicker::EventPicker( SCycleBase* parent
                                                  , const char* name
                                                  )
                                                  : ToolBase(parent, name)
{
  DeclareProperty("do_event_picker", c_do_event_picker = false);
  DeclareProperty("event_list", c_event_list = "");
}

// ----------------------------------------------------------------------------
SelectionTools::EventPicker::~EventPicker()
{
  // do nothing
}

// ----------------------------------------------------------------------------
void SelectionTools::EventPicker::BeginCycle()
{
  m_logger << DEBUG
           << "EventPicker::BeginCycle"
           << SLogger::endmsg;

  if (!c_do_event_picker) return;
  // TODO read run/event list and store them
}

// ----------------------------------------------------------------------------
void SelectionTools::EventPicker::BeginInputData(const SInputData&)
{
  m_logger << DEBUG
           << "EventPicker::BeginInputData"
           << SLogger::endmsg;

  // do nothing
}

// ----------------------------------------------------------------------------
bool SelectionTools::EventPicker::passed( const unsigned int run
                                        , const unsigned int event
                                        )
{
  if (!c_do_event_picker) return true;
  // TODO check if event/run is in event picker list

  return false;
}

// ----------------------------------------------------------------------------
bool SelectionTools::EventPicker::passed(const Event& event)
{
  return passed(event.RunNumber(), event.EventNumber());
}
