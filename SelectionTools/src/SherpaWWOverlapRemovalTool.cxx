#include "SelectionTools/include/SherpaWWOverlapRemovalTool.h"

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "D3PDObjects/include/TruthD3PDObject.h"

// -----------------------------------------------------------------------------
SelectionTools::SherpaWWOverlapRemovalTool::SherpaWWOverlapRemovalTool(
    SCycleBase* parent, const char* name): ToolBase(parent, name)
{
  // do nothing
}

// -----------------------------------------------------------------------------
SelectionTools::SherpaWWOverlapRemovalTool::~SherpaWWOverlapRemovalTool()
{
  //do nothing
}

// -----------------------------------------------------------------------------
bool SelectionTools::SherpaWWOverlapRemovalTool::passOveralpRemoval()
{
  if (is_data()) {
    // TODO do stuff here
  }

  return true;
}
