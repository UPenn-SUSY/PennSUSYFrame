#include "SelectionTools/include/EventPicker.h"

#include <fstream>
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
  DeclareProperty("event_list", c_event_list_file = "");
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

  m_logger << INFO << "Reading event list into EventPicker. Event list file: "
           << c_event_list_file << "\n" << SLogger::endmsg;
  std::ifstream in_file(c_event_list_file.c_str(), std::ifstream::in);

  unsigned event_num = 0;
  while (in_file >> event_num) {
    m_good_events.push_back(event_num);
  }
  in_file.close();

  m_logger << INFO << "number of good events to pick: "
           << m_good_events.size() << "\n" << SLogger::endmsg;
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
bool SelectionTools::EventPicker::passed( const unsigned int // run
                                        , const unsigned int event
                                        )
{
  if (!c_do_event_picker) return true;
  // TODO check if event/run is in event picker list

  size_t num_good_events = m_good_events.size();
  for (size_t it = 0; it != num_good_events; ++it) {
    if (event == m_good_events.at(it)) return true;
  }

  return false;
}

// ----------------------------------------------------------------------------
bool SelectionTools::EventPicker::passed(const Event& event)
{
  return passed(event.RunNumber(), event.EventNumber());
}
