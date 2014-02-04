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
    virtual ~CutFlowTracker();

    virtual void fillHist(int channel, int bin, float weight = 1.);

    virtual void printToScreen();
    virtual void printLine(int bin);
    // virtual void printToFile(std::string out_file_name);

  // ---------------------------------------------------------------------------
  protected:
    virtual void initBinList();
    virtual void initCutFlowHists();
    virtual void initCutFlowAxis(TH1*);

    std::vector<TH1D*> m_cutflow;

    // bool m_axis_initialized;
    std::vector<std::string> m_bin_list;

    unsigned int m_line_width;
    unsigned int m_label_field;
    unsigned int m_weight_field;
    unsigned int m_precision;
    std::string m_break_label;
    std::string m_break_weight;
    std::string m_single_line;

  // -----------------------------------------------------------------------------
  private:
};

#endif
