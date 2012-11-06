// Dear emacs, this is -*- c++ -*-
#ifndef CommonTools_MT2Tool_H
#define CommonTools_MT2Tool_H
// =============================================================================

#include "TLorentzVector.h"
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Met.h"

#include "mt2_bisect.h"

// =============================================================================
namespace CommonTools{

  // ===========================================================================
  class MT2Tool : public ToolBase
  {
  // ---------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    MT2Tool(SCycleBase* parent, const char* name = "CutTool");
    virtual ~MT2Tool();

    double getMT2();
    void setMT2(double);

  // ---------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    double m_MT2;

    template<class T1, class T2>
    float calculateMT2(T1*, T2*, Met*, double minv =0);
  };

}
// Include the implementation:
#ifndef __CINT__
#include "MT2Tool.icc"
#endif // __CINT__


#endif

