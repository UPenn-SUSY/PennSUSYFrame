#include "include/SignalRegionTool.h"

#include "AtlasSFrameUtils/include/CycleMacros.h"

// -----------------------------------------------------------------------------
SelectionTools::SignalRegionTool::SignalRegionTool(
    SCycleBase* parent, const char* name): ToolBase(parent, name)
                                         , m_top_tag_tool(NULL)
{
  DeclareProperty("z_window_mll_min", c_z_window_mll_min = 81200);
  DeclareProperty("z_window_mll_max", c_z_window_mll_max = 101200);

  DeclareProperty("sr1_min_met_rel", c_sr1_met_rel_min = 100000.);
  DeclareProperty("sr1_max_met_rel", c_sr1_met_rel_max = -1);

  DeclareProperty("sr2_min_met_rel", c_sr2_met_rel_min = 100000.);
  DeclareProperty("sr2_max_met_rel", c_sr2_met_rel_max = -1);

  DeclareProperty("sr3_min_met_rel", c_sr3_met_rel_min = 50000.);
  DeclareProperty("sr3_max_met_rel", c_sr3_met_rel_max = -1);

  DeclareProperty("sr4_min_met_rel", c_sr4_met_rel_min = 40000.);
  DeclareProperty("sr4_max_met_rel", c_sr4_met_rel_max = -1);

  DeclareProperty("sr4a_min_mt2", c_sr4a_mt2_min = 90000.);
  DeclareProperty("sr4a_max_mt2", c_sr4a_mt2_max = -1);

  DeclareProperty("sr4b_min_mt2", c_sr4b_mt2_min = 100000.);
  DeclareProperty("sr4b_max_mt2", c_sr4b_mt2_max = -1);

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
  bool pass_sr3_num_jets = (jets.num(JET_LIGHT) >= 2);
  sr_helper->setPassSR32LJet(pass_sr3_num_jets);

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

  sr_helper->setPassSR1MetRel(
      passCut(met_rel, c_sr1_met_rel_min, c_sr1_met_rel_max));

  sr_helper->setPassSR2MetRel(
      passCut(met_rel, c_sr2_met_rel_min, c_sr2_met_rel_max));

  sr_helper->setPassSR3MetRel(
      passCut(met_rel, c_sr3_met_rel_min, c_sr3_met_rel_max));

  sr_helper->setPassSR4MetRel(
      passCut(met_rel, c_sr4_met_rel_min, c_sr4_met_rel_max));

  // Check mt2 cuts
  double mt2 = event->getMt2();;
  sr_helper->setPassSR4aMt2(
      passCut(mt2, c_sr4a_mt2_min, c_sr4a_mt2_max));

  sr_helper->setPassSR4bMt2(
      passCut(mt2, c_sr4b_mt2_min, c_sr4b_mt2_max));

  // Check for signal regions
  event_desc->setSR1( passSR1( event_desc, sr_helper));
  event_desc->setSR2( passSR2( event_desc, sr_helper));
  event_desc->setSR3( passSR3( event_desc, sr_helper));
  event_desc->setSR4a(passSR4a(event_desc, sr_helper));
  event_desc->setSR4b(passSR4b(event_desc, sr_helper));
}

// -----------------------------------------------------------------------------
bool SelectionTools::SignalRegionTool::passSR1(
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
  if (sr_helper->getPassSR1MetRel() == false) return false;

  return true;
}

// -----------------------------------------------------------------------------
bool SelectionTools::SignalRegionTool::passSR2(
    SusyAnalysisTools::EventDescription* event_desc,
    SusyAnalysisTools::SRHelper* sr_helper)
{
  // require SS leptons
  if (event_desc->getSignChannel() != SIGN_SS) return false;

  // full jet veto
  if (sr_helper->getPassLJetVeto() == false) return false;
  if (sr_helper->getPassBJetVeto() == false) return false;
  if (sr_helper->getPassFJetVeto() == false) return false;

  // Z veto
  if (sr_helper->getPassZVeto() == false) return false;

  // MET-rel cut
  if (sr_helper->getPassSR2MetRel() == false) return false;

  return true;
}

// -----------------------------------------------------------------------------
bool SelectionTools::SignalRegionTool::passSR3(
    SusyAnalysisTools::EventDescription* event_desc,
    SusyAnalysisTools::SRHelper* sr_helper)
{
  // require same flavor leptons
  if (event_desc->getFlavorChannel() == FLAVOR_EM) return false;

  // require OS leptons
  if (event_desc->getSignChannel() != SIGN_OS) return false;

  // require 2 light jets
  if (sr_helper->getPassSR32LJet() == false) return false;

  // Z veto
  if (sr_helper->getPassZVeto() == false) return false;

  // b-jet veto
  if (sr_helper->getPassBJetVeto() == false) return false;

  // F-jet veto
  if (sr_helper->getPassFJetVeto() == false) return false;

  // top tag veto
  if (sr_helper->getPassTopVeto() == false) return false;

  // MET-rel cut
  if (sr_helper->getPassSR3MetRel() == false) return false;

  return false;
}

// -----------------------------------------------------------------------------
bool SelectionTools::SignalRegionTool::passSR4a(
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
  if (sr_helper->getPassSR4MetRel() == false) return false;

  // MT2 cut
  if (sr_helper->getPassSR4aMt2() == false) return false;

  return false;
}

// -----------------------------------------------------------------------------
bool SelectionTools::SignalRegionTool::passSR4b(
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
  if (sr_helper->getPassSR4MetRel() == false) return false;

  // MT2 cut
  if (sr_helper->getPassSR4bMt2() == false) return false;

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
