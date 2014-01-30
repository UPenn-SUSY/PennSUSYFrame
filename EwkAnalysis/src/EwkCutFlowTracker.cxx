#include "EwkAnalysis/include/EwkCutFlowTracker.h"

// =============================================================================
#include <iostream>
#include <vector>
#include "TH1D.h"

// =============================================================================
// -----------------------------------------------------------------------------
EwkCutFlowTracker::EwkCutFlowTracker()
{
  // do nothing
}


// -----------------------------------------------------------------------------
void EwkCutFlowTracker::fillHist(int channel, int bin, float weight)
{
  m_cutflow.at(channel)->Fill(bin, weight);
}

// -----------------------------------------------------------------------------
void EwkCutFlowTracker::printToScreen()
{
  // TODO print to screen
}

// -----------------------------------------------------------------------------
void EwkCutFlowTracker::initBinList()
{
  m_bin_list.clear();

  m_bin_list.push_back("ALL");
  // m_bin_list.push_back("BREAK");

  m_bin_list.push_back("GRL");
  m_bin_list.push_back("incomplete event");
  m_bin_list.push_back("LAr error");
  m_bin_list.push_back("tile error");
  m_bin_list.push_back("tile hot spot");
  m_bin_list.push_back("tile trip");
  m_bin_list.push_back("bad jet veto");
  m_bin_list.push_back("calo problem jet");
  m_bin_list.push_back("primary vertex");
  m_bin_list.push_back("bad muon");
  m_bin_list.push_back("cosmic muon veto");
  m_bin_list.push_back("HFOR");
  m_bin_list.push_back("mc overlap");
  // m_bin_list.push_back("BREAK");

  m_bin_list.push_back(">= 2 baseline leptons");
  m_bin_list.push_back("== 2 baseline leptons");
  m_bin_list.push_back("tau veto");
  m_bin_list.push_back("mll SFOS");
  m_bin_list.push_back("== 2 signal lepton");
  // m_bin_list.push_back("BREAK");

  m_bin_list.push_back("phase space");
  m_bin_list.push_back("trigger");
  m_bin_list.push_back("trigger matching");
  // m_bin_list.push_back("BREAK");

}

// -----------------------------------------------------------------------------
void EwkCutFlowTracker::initCutFlowHists()
{
  initBinList();

  m_cutflow.resize(1);

  std::string name = "cutflow";

  size_t num_bins = m_bin_list.size();
  std::cout << "setting cutflow histogram to: "
            << num_bins << ", " << -0.5 << " , " << num_bins - 0.5 << "\n";

  initCutFlowAxis(m_cutflow.at(0));
}
