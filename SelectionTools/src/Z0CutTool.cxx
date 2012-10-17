/*
#include <math.h>
#include "include/Z0CutTool.h"

// ----------------------------------------------------------------------------
SelectionTools::Z0CutTool::Z0CutTool( SCycleBase* parent
                                    , const char* name
                                    )
                                    : ToolBase(parent, name)
{
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  DeclareProperty("min_z0", c_min_z0 = -1);
  DeclareProperty("max_z0", c_max_z0 = -1);
  DeclareProperty("min_z0sintheta", c_min_z0_sin_theta = -1);
  DeclareProperty("max_z0sintheta", c_max_z0_sin_theta = -1);
}

// ----------------------------------------------------------------------------
SelectionTools::Z0CutTool::~Z0CutTool()
{
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // do nothing
}

// ----------------------------------------------------------------------------
bool SelectionTools::Z0CutTool::passedZ0(Electron* el)
{
  float z0 = fabs(el->trackz0pv());
  return passedZ0(z0);
}

// ----------------------------------------------------------------------------
bool SelectionTools::Z0CutTool::passedZ0(Muon* mu)
{
  float z0 = fabs(mu->z0_exPV());
  return passedZ0(z0);
}

// ----------------------------------------------------------------------------
bool SelectionTools::Z0CutTool::passedZ0SinTheta(Electron* el)
{
  float z0_sin_theta = fabs(el->getZ0SinTheta());
  return passedZ0(z0_sin_theta);
}

// ----------------------------------------------------------------------------
bool SelectionTools::Z0CutTool::passedZ0SinTheta(Muon* mu)
{
  float z0 = mu->z0_exPV();
  float sin_theta = sin(mu->getTlv().Theta());
  float z0_sin_theta = fabs(z0*sin_theta);
  return passedZ0(z0_sin_theta);
}

// ----------------------------------------------------------------------------
bool SelectionTools::Z0CutTool::passedZ0(float z0)
{
  // = if no test, then return true =
  if (c_min_z0 < 0 && c_max_z0 < 0) return true;

  if (c_min_z0 >= 0 && z0 < c_min_z0) return false;
  if (c_max_z0 >= 0 && z0 > c_max_z0) return false;

  // passed z0 cut
  return true;

}

// ----------------------------------------------------------------------------
bool SelectionTools::Z0CutTool::passedZ0SinTheta(float z0_sin_theta)
{
  // = if no test, then return true =
  if (c_min_z0_sin_theta < 0 && c_max_z0_sin_theta < 0) return true;

  if (c_min_z0_sin_theta >= 0 && z0_sin_theta < c_min_z0_sin_theta)
    return false;
  if (c_max_z0_sin_theta >= 0 && z0_sin_theta > c_max_z0_sin_theta)
    return false;

  // passed z0 cut
  return true;
}
*/
