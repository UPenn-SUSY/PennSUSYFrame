// Dear emacs, this is -*- c++ -*-
#ifndef SelectionTools_GoodRunsListTool_h
#define SelectionTools_GoodRunsListTool_h

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Event.h"

#include "GoodRunsLists/TGoodRunsList.h"
#include "GoodRunsLists/TGoodRunsListReader.h"

// ============================================================================
namespace SelectionTools
{
  // ==========================================================================
  class GoodRunsListTool : public ToolBase
  {
  // --------------------------------------------------------------------------
  public:
    GoodRunsListTool(SCycleBase* parent, const char* name = "CutTool");
    virtual ~GoodRunsListTool();

    void BeginCycle();
    void BeginInputData(const SInputData&);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool passed(const Event&);
    bool passed(const unsigned int run, const unsigned int lb);
    //
  // --------------------------------------------------------------------------
  private:
    // = user configurables =
    bool c_do_grl;
    std::string c_grl_xml;
    Root::TGoodRunsList m_grl;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ClassDef(GoodRunsListTool, 0);
  };
}

#endif
