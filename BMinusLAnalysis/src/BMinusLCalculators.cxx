#include "BMinusLAnalysis/include/BMinusLCalculators.h"

#include "PennSusyFrameCore/include/ObjectDefs.h"

// -----------------------------------------------------------------------------
PennSusyFrame::blPair::blPair()
{ }

// -----------------------------------------------------------------------------
PennSusyFrame::blPair::blPair( PennSusyFrame::Jet* jet, PennSusyFrame::Lepton* lep)
{
  m_jet = jet;
  m_lep = lep;
}
