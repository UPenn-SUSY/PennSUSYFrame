// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_D0CutTool_h
#define SelectionTools_D0CutTool_h

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/Muon.h"

// ============================================================================
namespace SelectionTools
{
  // ==========================================================================
  class D0CutTool : public ToolBase
  {
  // --------------------------------------------------------------------------
  public:
    D0CutTool(SCycleBase* parent, const char* name = "CutTool");
    virtual ~D0CutTool();

    template <class T> bool passed(const T*);

    bool passedD0(const Electron*);
    bool passedD0(const Muon*);
    bool passedD0Sig(const Electron*);
    bool passedD0Sig(const Muon*);

    bool passedD0(float d0);
    bool passedD0Sig(float d0_sig);

  // --------------------------------------------------------------------------
  private:
    // = user configurables =
    double c_min_d0;
    double c_max_d0;
    double c_min_d0_sig;
    double c_max_d0_sig;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(D0CutTool, 0);
  };
}

// Include the implementation:
#ifndef __CINT__
#include "D0CutTool.icc"
#endif // __CINT__

#endif
