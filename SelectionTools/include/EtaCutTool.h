/*
// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_EtaCutTool_h
#define SelectionTools_EtaCutTool_h

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/Muon.h"

// ============================================================================
namespace SelectionTools
{
  // ============================================================================
  class EtaCutTool : public ToolBase
  {
  // ----------------------------------------------------------------------------
  public:
    EtaCutTool(SCycleBase* parent, const char* name = "CutTool");
    virtual ~EtaCutTool();

    template<class T> bool passed(T*);

    bool passed(float eta);

  // ----------------------------------------------------------------------------
  private:
    // = user configurables =
    double c_min_eta;
    double c_max_eta;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(EtaCutTool, 0);
  };
}

// Include the implementation:
#ifndef __CINT__
#include "EtaCutTool.icc"
#endif // __CINT__

#endif
*/
