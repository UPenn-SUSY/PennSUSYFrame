#ifndef EwkCutFlowTracker_h
#define EwkCutFlowTracker_h

// =============================================================================
#include "CutFlowTracker/include/CutFlowTracker.h"
#include <vector>
#include "TH1D.h"

// =============================================================================
class EwkCutFlowTracker : public CutFlowTracker
{
  // ---------------------------------------------------------------------------
  public:
    EwkCutFlowTracker();

    virtual void fillHist(int channel, int bin, float weight);

    virtual void printToScreen();
    // virtual void printToFile(std::string out_file_name);

  // ---------------------------------------------------------------------------
  protected:
    virtual void initBinList();
    virtual void initCutFlowHists();

  // -----------------------------------------------------------------------------
  private:
};

#endif
