#include "BMinusLAnalysis/include/BMinusLTriggerScaleFactor.h"
#include "TrigMuonEfficiency/TrigMuonEfficiency/LeptonTriggerSF.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/ScaleFactorTools.h"

#include "TLorentzVector.h"

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
                                             , "muon_trigger_sf_2012_AtoL.p1328.root"
                                             , m_egamma_dir
                                             , "rel17p2.v07"
                                             );

  // TODO set is_AF2
}

// -----------------------------------------------------------------------------
BMinusLTriggerScaleFactor::~BMinusLTriggerScaleFactor()
{
  if (m_lepton_trig_sf_tool)
    delete m_lepton_trig_sf_tool;
}

// -----------------------------------------------------------------------------
double BMinusLTriggerScaleFactor::getSF( const PennSusyFrame::Event                   event
                                       , PennSusyFrame::PileUpScaleFactorTool&        pu_tool
                                       , const std::vector<PennSusyFrame::Electron*>* el_list
                                       , const std::vector<PennSusyFrame::Muon*>*     mu_list
                                       )
{
  std::pair<double, double> sf;

  // collect TLorentzVectors for all electrons and muons in event;
  size_t num_el = el_list->size();
  std::vector<TLorentzVector> el_tlv_list;
  el_tlv_list.reserve(num_el);
  for (size_t el_it = 0; el_it != num_el; ++el_it) {
    el_tlv_list.push_back(*(el_list->at(el_it)->getTlv()));
  }

  size_t num_mu = mu_list->size();
  std::vector<TLorentzVector> mu_tlv_list;
  mu_tlv_list.reserve(num_mu);
  for (size_t mu_it = 0; mu_it != num_mu; ++mu_it) {
    mu_tlv_list.push_back(*(mu_list->at(mu_it)->getTlv()));
  }

  // get trigger SF
  int random_run_number = 0;
  int gen_count = 0;
  while (++gen_count < 5 && random_run_number < 200804) {
    random_run_number =  pu_tool.getRandomRunNumber( event.getRunNumber()
                                                   , event.getAverageIntPerXing()
                                                   );
  }

  // This is a bit of a hack to prevent the trigger SF tool from freaking out.
  // If the random run number is < 200804 (out of range for 2012), return 1
  if (random_run_number < 200804) return 1.;

  // otherwise, get the trigger SF
  sf = m_lepton_trig_sf_tool->GetTriggerSF( random_run_number
                                          , false
                                          , mu_tlv_list
                                          , muon_quality(loose)
                                          , el_tlv_list
                                          , electron_quality(mediumpp)
                                          );

  // return the nominal SF
  return sf.first;
}
