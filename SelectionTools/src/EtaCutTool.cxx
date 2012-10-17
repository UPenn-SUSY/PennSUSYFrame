/*
#include <math.h>
#include "include/EtaCutTool.h"

// ----------------------------------------------------------------------------
SelectionTools::EtaCutTool::EtaCutTool( SCycleBase* parent
                                      , const char* name
                                      )
                                      : ToolBase(parent, name)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  DeclareProperty("min_eta", c_min_eta = -1);
  DeclareProperty("max_eta", c_max_eta = -1);
}

// ----------------------------------------------------------------------------
SelectionTools::EtaCutTool::~EtaCutTool()
{
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}

// ----------------------------------------------------------------------------
bool SelectionTools::EtaCutTool::passed(float eta)
{
  // = if no test, then return true =
  if (c_min_eta < 0 && c_max_eta < 0) return true;

  if (c_min_eta >= 0 && eta < c_min_eta) return false;
  if (c_max_eta >= 0 && eta > c_max_eta) return false;

  // passed eta cut
  return true;

}
*/
