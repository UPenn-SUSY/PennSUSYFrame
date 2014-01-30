#include "CutFlowTracker/include/CutFlowTracker.h"

// =============================================================================
#include <iostream>
#include <vector>
#include "TH1D.h"

// =============================================================================
// -----------------------------------------------------------------------------
CutFlowTracker::CutFlowTracker()
{
  // do nothing
}


// -----------------------------------------------------------------------------
void CutFlowTracker::fillHist(int channel, int bin, float weight)
{
  m_cutflow.at(channel)->Fill(bin, weight);
}

// -----------------------------------------------------------------------------
void CutFlowTracker::printToScreen()
{
  // TODO print to screen
}

// -----------------------------------------------------------------------------
void CutFlowTracker::initBinList()
{
  m_bin_list.clear();

  m_bin_list.push_back("ALL");
}

// -----------------------------------------------------------------------------
void CutFlowTracker::initCutFlowHists()
{
  initBinList();

  m_cutflow.resize(1);

  std::string name = "cutflow";

  initCutFlowAxis(m_cutflow.at(0));
}

// -----------------------------------------------------------------------------
void CutFlowTracker::initCutFlowAxis(TH1* h)
{
  size_t num_bins = m_bin_list.size();
  TAxis* axis = h->GetXaxis();
  for (size_t bin_it = 0; bin_it != num_bins; ++bin_it) {
    axis->SetBinLabel(bin_it+1, m_bin_list.at(bin_it).c_str());
  }
}
