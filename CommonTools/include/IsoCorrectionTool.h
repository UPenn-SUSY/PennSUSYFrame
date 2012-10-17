
// Dear emacs, this is -*- c++ -*-
#ifndef IsoCorrectionTool_H
#define IsoCorrectionTool_H
// ============================================================================
#include <map>
#include "TLorentzVector.h"

#include "AtlasSFrameUtils/include/ToolBase.h"

// ============================================================================
namespace CommonTools{
// ============================================================================
  enum ISO_TYPE { PTCONE
                , ETCONE
                , TOPOETCONE
                , TOPOETCONE_CORR
                , REL_PTCONE
                , REL_ETCONE
                , REL_TOPOETCONE
                , REL_TOPOETCONE_CORR
                };
  /**
  * helper class to correct isolation for pileup
  */
  class IsoCorrectionTool : public ToolBase
  {
  // ----------------------------------------------------------------------------
  public:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    IsoCorrectionTool(SCycleBase* parent, const char* name = "CutTool");
    virtual ~IsoCorrectionTool();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    double getIsoCorrection(ISO_TYPE, int cone_size, int num_vertex = 0);

  // ----------------------------------------------------------------------------
  private:
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    std::map<ISO_TYPE, std::map<int, double> > c_p1;
    std::map<ISO_TYPE, std::map<int, double> > c_p2;

    ClassDef(IsoCorrectionTool, 0);
  };
}

#endif
