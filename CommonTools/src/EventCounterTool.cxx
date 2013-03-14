#include "CommonTools/include/EventCounterTool.h"

#include <math.h>

#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "AtlasSFrameUtils/include/Event.h"
#include "AtlasSFrameUtils/include/ToolBase.h"

// ----------------------------------------------------------------------------
CommonTools::EventCounterTool::EventCounterTool( SCycleBase* parent
                                               , const char* name
                                               )
                                               : ToolBase(parent, name)
                                               , m_raw_events(0.)
                                               , m_weighted_events(0.)
{
  // do nothing
}
// -----------------------------------------------------------------------------
CommonTools::EventCounterTool::~EventCounterTool()
{
  // do nothing
}
// -----------------------------------------------------------------------------
void CommonTools::EventCounterTool::BeginInputData( const SInputData& )
{
  // do nothing
}
// -----------------------------------------------------------------------------
void CommonTools::EventCounterTool::BeginExecuteEvent( const SInputData&, Double_t )
{
  // do nothing
}

void CommonTools::EventCounterTool::countEvent(const Event* event)
{
  ++m_raw_events;
  m_weighted_events += event->getMCEventWeight();
}
