/*
#include <math.h>
#include "include/PtCutTool.h"

// ----------------------------------------------------------------------------
SelectionTools::PtCutTool::PtCutTool( SCycleBase* parent
                                    , const char* name
                                    )
                                    : ToolBase(parent, name)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  DeclareProperty("min_pt", c_min_pt = -1);
  DeclareProperty("max_pt", c_max_pt = -1);
}

// ----------------------------------------------------------------------------
SelectionTools::PtCutTool::~PtCutTool()
{
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}

// ----------------------------------------------------------------------------
bool SelectionTools::PtCutTool::passed(float pt)
{
  // = if no test, then return true =
  if (c_min_pt < 0 && c_max_pt < 0) return true;

  if (c_min_pt >= 0 && pt < c_min_pt) return false;
  if (c_max_pt >= 0 && pt > c_max_pt) return false;

  // passed pt cut
  return true;

}
*/
