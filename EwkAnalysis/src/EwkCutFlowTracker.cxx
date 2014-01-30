#include "EwkAnalysis/include/EwkCutFlowTracker.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"

// =============================================================================
#include <iostream>
#include <vector>
#include "TH1D.h"

// =============================================================================
// -----------------------------------------------------------------------------
EwkCutFlowTracker::EwkCutFlowTracker()
{
  initCutFlowHists();
}


// -----------------------------------------------------------------------------
void EwkCutFlowTracker::fillHist(int channel, int bin, float weight)
{
  m_cutflow.at(channel)->Fill(bin, weight);
}

// // -----------------------------------------------------------------------------
// void EwkCutFlowTracker::printToScreen()
// {
// }

// -----------------------------------------------------------------------------
void EwkCutFlowTracker::initBinList()
{
  m_bin_list.clear();

  for (int cut_it = 0; cut_it != EWK_CUT_N; ++cut_it) {
    m_bin_list.push_back(EWK_CUT_STRINGS[cut_it]);
  }
}

// -----------------------------------------------------------------------------
void EwkCutFlowTracker::initCutFlowHists()
{
  initBinList();

  m_cutflow.resize(PHASE_N);

  std::string name = "cutflow";

  size_t num_bins = m_bin_list.size();
  std::cout << "setting cutflow histogram to: "
            << num_bins << ", " << -0.5 << " , " << num_bins - 0.5 << "\n";

  std::string name_base = "cutflow_";
  for (size_t channel_it = 0; channel_it != PHASE_N; ++channel_it) {
    std::string this_name = name_base;
    if (     channel_it == static_cast<size_t>(PHASE_NONE)) this_name += "none";
    else if (channel_it == static_cast<size_t>(PHASE_EE  )) this_name += "ee";
    else if (channel_it == static_cast<size_t>(PHASE_MM  )) this_name += "mm";
    else if (channel_it == static_cast<size_t>(PHASE_EM  )) this_name += "em";
    else if (channel_it == static_cast<size_t>(PHASE_ME  )) this_name += "me";
    else continue;

    std::cout << "channel it: " << channel_it << " this_name: " << this_name << "\n";

    m_cutflow.at(channel_it) = new TH1D( this_name.c_str()
                                       , this_name.c_str()
                                       , EWK_CUT_N
                                       , -0.5
                                       , EWK_CUT_N - 0.5
                                       );
    initCutFlowAxis(m_cutflow.at(channel_it));
  }
}
