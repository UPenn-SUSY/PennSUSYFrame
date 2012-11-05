// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_MT2Tool_H
#define CommonTools_MT2Tool_H
// ============================================================================

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/Jet.h"


// ============================================================================
namespace CommonTools{
// ============================================================================

  class MT2Tool : public ToolBase
  {
  public:
    MT2Tool(SCycleBase* parent, const char* name = "CutTool");
    virtual ~MT2Tool();

    double getMT2();
    double setMT2();

  private:

    double m_MT2;


  };

}


#endif

