#ifndef CutFlowTracker_h
#define CutFlowTracker_h

// =============================================================================
#include <vector>
#include "TH1D.h"

// =============================================================================
class CutFlowTracker
{
  // ---------------------------------------------------------------------------
  public:
    CutFlowTracker();

    virtual void fillHist(int channel, int bin, float weight);

    virtual void printToScreen();
    // virtual void printToFile(std::string out_file_name);

  // ---------------------------------------------------------------------------
  protected:
    virtual void initBinList();
    virtual void initCutFlowHists();
    virtual void initCutFlowAxis(TH1*);

    std::vector<TH1D*> m_cutflow;

    // bool m_axis_initialized;
    std::vector<std::string> m_bin_list;

  // -----------------------------------------------------------------------------
  private:
};

#endif
