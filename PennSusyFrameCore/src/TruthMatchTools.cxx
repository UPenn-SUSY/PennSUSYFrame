#include "PennSusyFrameCore/include/TruthMatchTools.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"

#include "RootCore/LeptonTruthTools/LeptonTruthTools/RecoTruthMatch.h"

// =============================================================================
// -----------------------------------------------------------------------------
PennSusyFrame::TruthMatchTool::TruthMatchTool() : m_truth_match(0)
{

}

// -----------------------------------------------------------------------------
PennSusyFrame::TruthMatchTool::~TruthMatchTool()
{
  clear();
}

// -----------------------------------------------------------------------------
void PennSusyFrame::TruthMatchTool::clear()
{
  if (m_truth_match) {
    delete m_truth_match;
    m_truth_match = 0;
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::TruthMatchTool::prep(const PennSusyFrame::MCTruth& mc_truth)
{
  clear();

  m_truth_match = new RecoTruthMatch( 0.1
                                    , mc_truth.getChannelNumber()
                                    , mc_truth.getN()
                                    , mc_truth.getBarcode()
                                    , mc_truth.getStatus()
                                    , mc_truth.getPdgId()
                                    , mc_truth.getParents()
                                    , mc_truth.getChildren()
                                    , mc_truth.getPt()
                                    , mc_truth.getEta()
                                    , mc_truth.getPhi()
                                    , mc_truth.getM()
                                    , 0
                                    );
}
