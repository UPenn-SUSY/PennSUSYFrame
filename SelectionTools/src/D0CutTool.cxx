/*
#include <math.h>
#include "include/D0CutTool.h"

// ----------------------------------------------------------------------------
SelectionTools::D0CutTool::D0CutTool( SCycleBase* parent
                                    , const char* name
                                    )
                                    : ToolBase(parent, name)
{
  DeclareProperty("min_d0", c_min_d0 = -1);
  DeclareProperty("max_d0", c_max_d0 = -1);
  DeclareProperty("min_d0sig", c_min_d0_sig = -1);
  DeclareProperty("max_d0sig", c_max_d0_sig = -1);
}

// ----------------------------------------------------------------------------
SelectionTools::D0CutTool::~D0CutTool()
{
  // do nothing
}

// ----------------------------------------------------------------------------
bool SelectionTools::D0CutTool::passedD0(const Electron* el)
{
  float d0 = fabs(el->trackd0pv());
  return passedD0(d0);
}

// ----------------------------------------------------------------------------
bool SelectionTools::D0CutTool::passedD0Sig(const Electron* el)
{
  float d0_sig = fabs(el->trackd0pv()/el->trackd0pv());
  return passedD0Sig(d0_sig);
}

// ----------------------------------------------------------------------------
bool SelectionTools::D0CutTool::passedD0(float d0)
{
  // = if no test, then return true =
  if (c_min_d0 < 0 && c_max_d0 < 0) return true;

  if (c_min_d0 >= 0 && d0 < c_min_d0) return false;
  if (c_max_d0 >= 0 && d0 > c_max_d0) return false;

  // passed d0 cut
  return true;
}

// ----------------------------------------------------------------------------
bool SelectionTools::D0CutTool::passedD0Sig(float d0_sig)
{
  // = if no test, then return true =
  if (c_min_d0_sig < 0 && c_max_d0_sig < 0) return true;

  if (c_min_d0_sig >= 0 && d0_sig < c_min_d0_sig) return false;
  if (c_max_d0_sig >= 0 && d0_sig > c_max_d0_sig) return false;

  // passed d0 significance cut
  return true;
}
*/
