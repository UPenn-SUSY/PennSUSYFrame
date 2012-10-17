/*
// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_Z0CutTool_h
#define SelectionTools_Z0CutTool_h

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/Muon.h"

// ============================================================================
namespace SelectionTools
{
  // ============================================================================
  class Z0CutTool : public ToolBase
  {
  // ----------------------------------------------------------------------------
  public:
    Z0CutTool(SCycleBase* parent, const char* name = "CutTool");
    virtual ~Z0CutTool();

    template<class T> bool passed(T*);

    bool passedZ0(Electron*);
    bool passedZ0(Muon*);
    bool passedZ0SinTheta(Electron*);
    bool passedZ0SinTheta(Muon*);

    bool passedZ0(float z0);
    bool passedZ0SinTheta(float z0_sin_theta);

  // ----------------------------------------------------------------------------
  private:
    // = user configurables =
    double c_min_z0;
    double c_max_z0;
    double c_min_z0_sin_theta;
    double c_max_z0_sin_theta;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(Z0CutTool, 0);
  };
}

// Include the implementation:
#ifndef __CINT__
#include "Z0CutTool.icc"
#endif // __CINT__

#endif
*/
