/*
// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_PtCutTool_h
#define SelectionTools_PtCutTool_h

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/Muon.h"

// ============================================================================
namespace SelectionTools
{
  // ==========================================================================
  class PtCutTool : public ToolBase
  {
  // --------------------------------------------------------------------------
  public:
    PtCutTool(SCycleBase* parent, const char* name = "CutTool");
    virtual ~PtCutTool();

    template<class T> bool passed(T*);

    template<class T1, class T2> bool passedScalarSum(T1*, T2*);

    bool passed(float pt);

  // --------------------------------------------------------------------------
  private:
    // = user configurables =
    double c_min_pt;
    double c_max_pt;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(PtCutTool, 0);
  };
}

// Include the implementation:
#ifndef __CINT__
#include "PtCutTool.icc"
#endif // __CINT__

#endif
*/
