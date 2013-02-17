#include "SelectionTools/include/SignalRegionTool.h"

#include "AtlasSFrameUtils/include/CycleMacros.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/ElectronContainer.h"
#include "AtlasSFrameUtils/include/Event.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/JetContainer.h"
#include "AtlasSFrameUtils/include/Met.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/MuonContainer.h"
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "CommonTools/include/TopTagTool.h"

// -----------------------------------------------------------------------------
SelectionTools::SignalRegionTool::SignalRegionTool(
    SCycleBase* parent, const char* name): ToolBase(parent, name)
                                         , m_top_tag_tool(NULL)
{
  DeclareProperty("z_window_mll_min", c_z_window_mll_min = 81200);
  DeclareProperty("z_window_mll_max", c_z_window_mll_max = 101200);

  DeclareProperty("sr_osjveto_min_met_rel", c_sr_osjveto_met_rel_min = 100e3);
  DeclareProperty("sr_osjveto_max_met_rel", c_sr_osjveto_met_rel_max = -1);

  DeclareProperty("sr_osjveto_min_mt2", c_sr_osjveto_mt2_min = -1);
  DeclareProperty("sr_osjveto_max_mt2", c_sr_osjveto_mt2_max = 90e3);

  DeclareProperty(
      "sr_ssjets_ee_min_met_rel", c_sr_ssjets_ee_met_rel_min = 70e3);
  DeclareProperty(
      "sr_ssjets_ee_max_met_rel", c_sr_ssjets_ee_met_rel_max = -1);

  DeclareProperty(
      "sr_ssjets_mm_min_met_rel", c_sr_ssjets_mm_met_rel_min = 50e3);
  DeclareProperty(
      "sr_ssjets_mm_max_met_rel", c_sr_ssjets_mm_met_rel_max = -1);

  DeclareProperty(
      "sr_ssjets_em_min_met_rel", c_sr_ssjets_em_met_rel_min = 50e3);
  DeclareProperty(
      "sr_ssjets_em_max_met_rel", c_sr_ssjets_em_met_rel_max = -1);

  DeclareProperty("sr_ssjets_ee_min_mt", c_sr_ssjets_ee_mt_min = -1);
  DeclareProperty("sr_ssjets_ee_max_mt", c_sr_ssjets_ee_mt_max = 70e3);

  DeclareProperty("sr_ssjets_mm_min_mt", c_sr_ssjets_mm_mt_min = -1);
  DeclareProperty("sr_ssjets_mm_max_mt", c_sr_ssjets_mm_mt_max = 50e3);

  DeclareProperty("sr_ssjets_em_min_mt", c_sr_ssjets_em_mt_min = -1);
  DeclareProperty("sr_ssjets_em_max_mt", c_sr_ssjets_em_mt_max = 50e3);

  DeclareProperty("sr_2jets_min_met_rel", c_sr_2jets_met_rel_min = 50e3);
  DeclareProperty("sr_2jets_max_met_rel", c_sr_2jets_met_rel_max = -1);

  DeclareProperty("sr_mt2_min_met_rel", c_sr_mt2_met_rel_min = 40e3);
  DeclareProperty("sr_mt2_max_met_rel", c_sr_mt2_met_rel_max = -1);

  DeclareProperty("sr_mt2a_min_mt2", c_sr_mt2a_mt2_min = 90e3);
  DeclareProperty("sr_mt2a_max_mt2", c_sr_mt2a_mt2_max = -1);

  DeclareProperty("sr_mt2b_min_mt2", c_sr_mt2b_mt2_min = 100e3);
  DeclareProperty("sr_mt2b_max_mt2", c_sr_mt2b_mt2_max = -1);
}

// -----------------------------------------------------------------------------
SelectionTools::SignalRegionTool::~SignalRegionTool()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void SelectionTools::SignalRegionTool::BeginInputData(const SInputData&)
{
  GET_TOOL( top_tag_tool
          , CommonTools::TopTagTool
          , "Top_Tag"
          );
  m_top_tag_tool = top_tag_tool;
}

// -----------------------------------------------------------------------------
void SelectionTools::SignalRegionTool::EndInputData(const SInputData&)
{
  // do nothing
}

// -----------------------------------------------------------------------------
void SelectionTools::SignalRegionTool::processSignalRegions( Event* event,
    ElectronContainer& electrons,
    MuonContainer& muons,
    JetContainer& jets,
    Met* met)
{
  SusyAnalysisTools::EventDescription* event_desc = event->getEventDesc();
  SusyAnalysisTools::SRHelper*         sr_helper  = event->getSRHelper();

  // Check light jet veto
  bool pass_l_jet_veto = (jets.num(JET_LIGHT) == 0);
  sr_helper->setPassLJetVeto(pass_l_jet_veto);

  // Check b jet veto
  bool pass_b_jet_veto = (jets.num(JET_B) == 0);
  sr_helper->setPassBJetVeto(pass_b_jet_veto);

  // Check forward jet veto
  bool pass_f_jet_veto = (jets.num(JET_FORWARD) == 0);
  sr_helper->setPassFJetVeto(pass_f_jet_veto);

  // check num light jets
  bool pass_sr_2jets_num_jets = (jets.num(JET_LIGHT) >= 2);
  sr_helper->setPassSR2JetsNumLJet(pass_sr_2jets_num_jets);

  // Check z veto
  double mll = event->getMll();
  bool in_z_window = passCut(mll, c_z_window_mll_min, c_z_window_mll_max);
  sr_helper->setPassZVeto(!in_z_window);

  // Check top tag veto
  bool is_top_tagged = m_top_tag_tool->isTopTagged(
      event_desc->getFlavorChannel(),
      met,
      electrons.getElectrons(EL_GOOD),
      muons.getMuons(MU_GOOD),
      jets.getJets(JET_ALL_SIGNAL) );
  sr_helper->setPassTopVeto(!is_top_tagged);

  // Check MET-rel cuts
  double met_rel = event->getMetRel();;

  // check Met-rel for each SR
  sr_helper->setPassSROSJVetoMetRel(
      passCut(met_rel, c_sr_osjveto_met_rel_min, c_sr_osjveto_met_rel_max));

  if (event->getFlavorChannel() == FLAVOR_EE) {
    sr_helper->setPassSRSSJetsMetRel( passCut( met_rel
                                             , c_sr_ssjets_ee_met_rel_min
                                             , c_sr_ssjets_ee_met_rel_max
                                             )
                                    );
  }
  else if (event->getFlavorChannel() == FLAVOR_MM) {
    sr_helper->setPassSRSSJetsMetRel( passCut( met_rel
                                             , c_sr_ssjets_mm_met_rel_min
                                             , c_sr_ssjets_mm_met_rel_max
                                             )
                                    );
  }
  else if (event->getFlavorChannel() == FLAVOR_EM) {
    sr_helper->setPassSRSSJetsMetRel( passCut( met_rel
                                             , c_sr_ssjets_em_met_rel_min
                                             , c_sr_ssjets_em_met_rel_max
                                             )
                                    );
  }

  sr_helper->setPassSR2JetsMetRel(
      passCut(met_rel, c_sr_2jets_met_rel_min, c_sr_2jets_met_rel_max));

  sr_helper->setPassSRMT2MetRel(
      passCut(met_rel, c_sr_mt2_met_rel_min, c_sr_mt2_met_rel_max));

  // Check mt cuts
  double mt = event->getMt();
  if (event->getFlavorChannel() == FLAVOR_EE) {
    sr_helper->setPassSRSSJetsMt(
        passCut(mt, c_sr_ssjets_ee_mt_min, c_sr_ssjets_ee_mt_max));
  }
  else if (event->getFlavorChannel() == FLAVOR_MM) {
    sr_helper->setPassSRSSJetsMt(
        passCut(mt, c_sr_ssjets_mm_mt_min, c_sr_ssjets_mm_mt_max));
  }
  else if (event->getFlavorChannel() == FLAVOR_EM) {
    sr_helper->setPassSRSSJetsMt(
        passCut(mt, c_sr_ssjets_em_mt_min, c_sr_ssjets_em_mt_max));
  }

  // Check mt2 cuts
  double mt2 = event->getMt2();

  sr_helper->setPassSROSJVetoMt2(
      passCut(mt2, c_sr_osjveto_mt2_min, c_sr_osjveto_mt2_max));

  sr_helper->setPassSRMT2aMt2(
      passCut(mt2, c_sr_mt2a_mt2_min, c_sr_mt2a_mt2_max));

  sr_helper->setPassSRMT2bMt2(
      passCut(mt2, c_sr_mt2b_mt2_min, c_sr_mt2b_mt2_max));

  // Check for signal regions
  event_desc->setSROSJVeto(passSROSJVeto(event_desc, sr_helper));
  event_desc->setSRSSJets( passSRSSJets( event_desc, sr_helper));
  event_desc->setSR2Jets(  passSR2Jets(  event_desc, sr_helper));
  event_desc->setSRMT2a(   passSRMT2a(   event_desc, sr_helper));
  event_desc->setSRMT2b(   passSRMT2b(   event_desc, sr_helper));
}

// -----------------------------------------------------------------------------
bool SelectionTools::SignalRegionTool::passSROSJVeto(
    SusyAnalysisTools::EventDescription* event_desc,
    SusyAnalysisTools::SRHelper* sr_helper)
{
  // require OS leptons
  if (event_desc->getSignChannel() != SIGN_OS) return false;

  // full jet veto
  if (sr_helper->getPassLJetVeto() == false) return false;
  if (sr_helper->getPassBJetVeto() == false) return false;
  if (sr_helper->getPassFJetVeto() == false) return false;

  // Z veto
  if (sr_helper->getPassZVeto() == false) return false;

  // MET-rel cut
  if (sr_helper->getPassSROSJVetoMetRel() == false) return false;

  return true;
}

// -----------------------------------------------------------------------------
bool SelectionTools::SignalRegionTool::passSRSSJets(
    SusyAnalysisTools::EventDescription* event_desc,
    SusyAnalysisTools::SRHelper* sr_helper)
{
  // require SS leptons
  if (event_desc->getSignChannel() != SIGN_SS) return false;

  // full jet veto
  if (sr_helper->getPassLJetVeto() == true ) return false;
  if (sr_helper->getPassBJetVeto() == false) return false;
  if (sr_helper->getPassFJetVeto() == false) return false;

  // Z veto
  if (sr_helper->getPassZVeto() == false) return false;

  // MET-rel cut
  if (sr_helper->getPassSRSSJetsMetRel() == false) return false;

  // mt cut
  if (sr_helper->getPassSRSSJetsMt() == false) return false;

  return true;
}

// -----------------------------------------------------------------------------
bool SelectionTools::SignalRegionTool::passSR2Jets(
    SusyAnalysisTools::EventDescription* event_desc,
    SusyAnalysisTools::SRHelper* sr_helper)
{
  // require same flavor leptons
  if (event_desc->getFlavorChannel() == FLAVOR_EM) return false;

  // require OS leptons
  if (event_desc->getSignChannel() != SIGN_OS) return false;

  // require 2 light jets
  if (sr_helper->getPassSR2JetsNumLJet() == false) return false;

  // Z veto
  if (sr_helper->getPassZVeto() == false) return false;

  // b-jet veto
  if (sr_helper->getPassBJetVeto() == false) return false;

  // F-jet veto
  if (sr_helper->getPassFJetVeto() == false) return false;

  // top tag veto
  if (sr_helper->getPassTopVeto() == false) return false;

  // MET-rel cut
  if (sr_helper->getPassSR2JetsMetRel() == false) return false;

  return false;
}

// -----------------------------------------------------------------------------
bool SelectionTools::SignalRegionTool::passSRMT2a(
    SusyAnalysisTools::EventDescription* event_desc,
    SusyAnalysisTools::SRHelper* sr_helper)
{
  // require OS leptons
  if (event_desc->getSignChannel() != SIGN_OS) return false;

  // full jet veto
  if (sr_helper->getPassLJetVeto() == false) return false;
  if (sr_helper->getPassBJetVeto() == false) return false;
  if (sr_helper->getPassFJetVeto() == false) return false;

  // Z veto
  if (sr_helper->getPassZVeto() == false) return false;

  // MET-rel cut
  if (sr_helper->getPassSRMT2MetRel() == false) return false;

  // MT2 cut
  if (sr_helper->getPassSRMT2aMt2() == false) return false;

  return false;
}

// -----------------------------------------------------------------------------
bool SelectionTools::SignalRegionTool::passSRMT2b(
    SusyAnalysisTools::EventDescription* event_desc,
    SusyAnalysisTools::SRHelper* sr_helper)
{
  // require OS leptons
  if (event_desc->getSignChannel() != SIGN_OS) return false;

  // full jet veto
  if (sr_helper->getPassLJetVeto() == false) return false;
  if (sr_helper->getPassBJetVeto() == false) return false;
  if (sr_helper->getPassFJetVeto() == false) return false;

  // Z veto
  if (sr_helper->getPassZVeto() == false) return false;

  // MET-rel cut
  if (sr_helper->getPassSRMT2MetRel() == false) return false;

  // MT2 cut
  if (sr_helper->getPassSRMT2bMt2() == false) return false;

  return false;
}

// -----------------------------------------------------------------------------
bool SelectionTools::SignalRegionTool::passFullJetVeto(const JetContainer* jets)
{
  size_t num_jets = jets->num(JET_ALL_SIGNAL);
  return (num_jets == 0);
}

// ----------------------------------------------------------------------------
bool SelectionTools::SignalRegionTool::passCut( double test
                                              , double min
                                              , double max
                                              )
{
  // if no test, return true
  if (min < 0 && max < 0) return true;

  if (min >= 0 && test < min) return false;
  if (max >= 0 && test > max) return false;

  // passed test
  return true;
}
