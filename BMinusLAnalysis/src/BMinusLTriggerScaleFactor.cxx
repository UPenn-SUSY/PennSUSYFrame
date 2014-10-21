#include "BMinusLAnalysis/include/BMinusLTriggerScaleFactor.h"
#include "TrigMuonEfficiency/TrigMuonEfficiency/LeptonTriggerSF.h"

// -----------------------------------------------------------------------------
BMinusLTriggerScaleFactor::BMinusLTriggerScaleFactor() : m_lepton_trig_sf_tool(0)
{
}

// -----------------------------------------------------------------------------
void BMinusLTriggerScaleFactor::init()
{
  m_egamma_dir = "$ROOTCOREDIR/../ElectronEfficiencyCorrection/data/";
  m_muon_dir   = "$ROOTCOREDIR/../TrigMuonEfficiency/share/";

  m_lepton_trig_sf_tool = new LeptonTriggerSF( 2012
                                             , m_muon_dir
                                             , "muon_trigger_sf.root"
                                             , m_egamma_dir
                                             , "rel17p2.v02"
                                             );
}

// -----------------------------------------------------------------------------
BMinusLTriggerScaleFactor::~BMinusLTriggerScaleFactor()
{
  if (m_lepton_trig_sf_tool)
    delete m_lepton_trig_sf_tool;
}

// -----------------------------------------------------------------------------
double BMinusLTriggerScaleFactor::getSF( std::vector<PennSusyFrame::Electron*>*
                                       , std::vector<PennSusyFrame::Muon*>*
                                       )
{
  double sf = 1.;

  return sf;
}
