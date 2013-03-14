#include "CommonTools/include/EventCounterTool.h"

#include <iostream>
#include <math.h>

#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "AtlasSFrameUtils/include/Event.h"
#include "AtlasSFrameUtils/include/ToolBase.h"

// ----------------------------------------------------------------------------
CommonTools::EventCounterTool::EventCounterTool( SCycleBase* parent
                                               , const char* name
                                               )
                                               : ToolBase(parent, name)
                                               , m_event_weights(NULL)
{
  m_event_weights = new TH1D("event_weights", "event_weights", 1, -0.5, 0.5);
}
// -----------------------------------------------------------------------------
CommonTools::EventCounterTool::~EventCounterTool()
{
  // do nothing
}
// -----------------------------------------------------------------------------
void CommonTools::EventCounterTool::BeginInputData( const SInputData& )
{
  Book(*m_event_weights);
}
// -----------------------------------------------------------------------------
void CommonTools::EventCounterTool::BeginExecuteEvent( const SInputData&, Double_t )
{
  // do nothing
}

void CommonTools::EventCounterTool::countEvent(const Event* event)
{
  std::cout << "counting event with weight " << event->getMCEventWeight() << "\n";
  m_event_weights->Fill(0., event->getMCEventWeight());
}
