#include "SelectionTools/include/ControlRegionTool.h"

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

/*

// -----------------------------------------------------------------------------
SelectionTools::ControlRegionTool::ControlRegionTool(
    SCycleBase* parent, const char* name): ToolBase(parent, name)
                                         , m_top_tag_tool(NULL)
{
  DeclareProperty("z_window_mll_min", c_z_window_mll_min = 81200);
  DeclareProperty("z_window_mll_max", c_z_window_mll_max = 101200);

  // SR osjveto cut values
  DeclareProperty("sr_osjveto_min_met_rel", c_sr_osjveto_met_rel_min = 100e3);
  DeclareProperty("sr_osjveto_max_met_rel", c_sr_osjveto_met_rel_max = -1);

  DeclareProperty("sr_osjveto_min_mt2", c_sr_osjveto_mt2_min = -1);
  DeclareProperty("sr_osjveto_max_mt2", c_sr_osjveto_mt2_max = 90e3);

  // SR ssjets cut values
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

  // SR 2jets cut values
  DeclareProperty("sr_2jets_min_met_rel", c_sr_2jets_met_rel_min = 50e3);
  DeclareProperty("sr_2jets_max_met_rel", c_sr_2jets_met_rel_max = -1);

  // SR mt2 cut values
  DeclareProperty("sr_mt2_min_met_rel", c_sr_mt2_met_rel_min = 40e3);
  DeclareProperty("sr_mt2_max_met_rel", c_sr_mt2_met_rel_max = -1);

  DeclareProperty("sr_mt2a_min_mt2", c_sr_mt2a_mt2_min = 90e3);
  DeclareProperty("sr_mt2a_max_mt2", c_sr_mt2a_mt2_max = -1);

  DeclareProperty("sr_mt2b_min_mt2", c_sr_mt2b_mt2_min = 100e3);
  DeclareProperty("sr_mt2b_max_mt2", c_sr_mt2b_mt2_max = -1);

  // SR ww cut values
  DeclareProperty("sr_ww_min_lep1_pt", c_sr_ww_lep1_pt_min = 35e3);
  DeclareProperty("sr_ww_max_lep1_pt", c_sr_ww_lep1_pt_max = -1);

  DeclareProperty("sr_ww_min_lep2_pt", c_sr_ww_lep2_pt_min = 20e3);
  DeclareProperty("sr_ww_max_lep2_pt", c_sr_ww_lep2_pt_max = -1);

  DeclareProperty("sr_wwa_min_met_rel", c_sr_wwa_met_rel_min = 70e3);
  DeclareProperty("sr_wwa_max_met_rel", c_sr_wwa_met_rel_max = -1);

  DeclareProperty("sr_wwa_min_mll", c_sr_wwa_mll_min = -1);
  DeclareProperty("sr_wwa_max_mll", c_sr_wwa_mll_max = 80e3);

  DeclareProperty("sr_wwa_min_ptll", c_sr_wwa_ptll_min = -1);
  DeclareProperty("sr_wwa_max_ptll", c_sr_wwa_ptll_max = -1);

  DeclareProperty("sr_wwb_min_mt2", c_sr_wwb_mt2_min = 90e3);
  DeclareProperty("sr_wwb_max_mt2", c_sr_wwb_mt2_max = -1);

  DeclareProperty("sr_wwb_min_mll", c_sr_wwb_mll_min = -1);
  DeclareProperty("sr_wwb_max_mll", c_sr_wwb_mll_max = 130e3);

  DeclareProperty("sr_wwb_min_ptll", c_sr_wwb_ptll_min = -1);
  DeclareProperty("sr_wwb_max_ptll", c_sr_wwb_ptll_max = 170e3);

  DeclareProperty("sr_wwc_min_ptll", c_sr_wwc_ptll_min = -1);
  DeclareProperty("sr_wwc_max_ptll", c_sr_wwc_ptll_max = 190e3);

  DeclareProperty("sr_wwc_min_mt2", c_sr_wwc_mt2_min = 100e3);
  DeclareProperty("sr_wwc_max_mt2", c_sr_wwc_mt2_max = -1);

  // SR zjets cut values
  DeclareProperty("sr_zjets_min_num_jets", c_sr_zjets_num_jets_min = 2);
  DeclareProperty("sr_zjets_max_num_jets", c_sr_zjets_num_jets_max = -1);

  DeclareProperty("sr_zjets_min_met_rel", c_sr_zjets_met_rel_min = 40e3);
  DeclareProperty("sr_zjets_max_met_rel", c_sr_zjets_met_rel_max = -1);

  DeclareProperty("sr_zjets_min_jet1_pt", c_sr_zjets_jet1_pt_min = 40e3);
  DeclareProperty("sr_zjets_max_jet1_pt", c_sr_zjets_jet1_pt_max = -1);

  DeclareProperty("sr_zjets_min_jet2_pt", c_sr_zjets_jet2_pt_min = 40e3);
  DeclareProperty("sr_zjets_max_jet2_pt", c_sr_zjets_jet2_pt_max = -1);

  DeclareProperty("sr_zjets_min_mjj", c_sr_zjets_mjj_min = 50e3);
  DeclareProperty("sr_zjets_max_mjj", c_sr_zjets_mjj_max = 100e3);

  DeclareProperty("sr_zjets_min_mt2", c_sr_zjets_mt2_min = 55e3);
  DeclareProperty("sr_zjets_max_mt2", c_sr_zjets_mt2_max = -1);
}

// -----------------------------------------------------------------------------
SelectionTools::ControlRegionTool::~ControlRegionTool()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void SelectionTools::ControlRegionTool::BeginInputData(const SInputData&)
{
  GET_TOOL( top_tag_tool
          , CommonTools::TopTagTool
          , "Top_Tag"
          );
  m_top_tag_tool = top_tag_tool;
}

// -----------------------------------------------------------------------------
void SelectionTools::ControlRegionTool::EndInputData(const SInputData&)
{
  // do nothing
}

// -----------------------------------------------------------------------------
void SelectionTools::ControlRegionTool::processControlRegions( Event* event,
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

  sr_helper->setPassSRWWaMetRel(
      passCut(met_rel, c_sr_wwa_met_rel_min, c_sr_wwa_met_rel_max));

  sr_helper->setPassSRZJetsMetRel(
      passCut(met_rel, c_sr_zjets_met_rel_min, c_sr_zjets_met_rel_max));

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

  sr_helper->setPassSRWWbMt2(
      passCut(met_rel, c_sr_wwb_mt2_min, c_sr_wwb_mt2_max));

  sr_helper->setPassSRWWcMt2(
      passCut(met_rel, c_sr_wwc_mt2_min, c_sr_wwc_mt2_max));

  // Check for signal regions
  event_desc->setSROSJVeto(passSROSJVeto(event_desc, sr_helper));
  event_desc->setSRSSJets( passSRSSJets( event_desc, sr_helper));
  event_desc->setSR2Jets(  passSR2Jets(  event_desc, sr_helper));
  event_desc->setSRMT2a(   passSRMT2a(   event_desc, sr_helper));
  event_desc->setSRMT2b(   passSRMT2b(   event_desc, sr_helper));
  event_desc->setSRWWa(    passSRWWa(    event_desc, sr_helper));
  event_desc->setSRWWb(    passSRWWb(    event_desc, sr_helper));
  event_desc->setSRWWc(    passSRWWc(    event_desc, sr_helper));
  event_desc->setSRZjets(  passSRZJets(  event_desc, sr_helper));
}

// -----------------------------------------------------------------------------
bool SelectionTools::ControlRegionTool::passSROSJVeto(
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
bool SelectionTools::ControlRegionTool::passSRSSJets(
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
bool SelectionTools::ControlRegionTool::passSR2Jets(
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
bool SelectionTools::ControlRegionTool::passSRMT2a(
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
bool SelectionTools::ControlRegionTool::passSRMT2b(
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
bool SelectionTools::ControlRegionTool::passSRWWa(
    SusyAnalysisTools::EventDescription* event_desc,
    SusyAnalysisTools::SRHelper* sr_helper)
{
  // require emu events
  if (event_desc->getFlavorChannel() != FLAVOR_EM) return false;
  // require OS leptons
  if (event_desc->getSignChannel() != SIGN_OS) return false;

  // full jet veto
  if (sr_helper->getPassLJetVeto() == false) return false;
  if (sr_helper->getPassBJetVeto() == false) return false;
  if (sr_helper->getPassFJetVeto() == false) return false;

  // check pT of leptons
  if (sr_helper->getPassSRWWLep1Pt() == false) return false;
  if (sr_helper->getPassSRWWLep2Pt() == false) return false;

  // check if event passes met-rel cut
  if (sr_helper->getPassSRWWaMetRel() == false) return false;

  // check if event passes mll cut
  if (sr_helper->getPassSRWWaMll() == false) return false;

  // check if event passes ptll cut
  if (sr_helper->getPassSRWWaPtll() == false) return false;

  return true;
}

// -----------------------------------------------------------------------------
bool SelectionTools::ControlRegionTool::passSRWWb(
    SusyAnalysisTools::EventDescription* event_desc,
    SusyAnalysisTools::SRHelper* sr_helper)
{
  // require emu events
  if (event_desc->getFlavorChannel() != FLAVOR_EM) return false;
  // require OS leptons
  if (event_desc->getSignChannel() != SIGN_OS) return false;

  // full jet veto
  if (sr_helper->getPassLJetVeto() == false) return false;
  if (sr_helper->getPassBJetVeto() == false) return false;
  if (sr_helper->getPassFJetVeto() == false) return false;

  // check pT of leptons
  if (sr_helper->getPassSRWWLep1Pt() == false) return false;
  if (sr_helper->getPassSRWWLep2Pt() == false) return false;

  // check if event passes mt2 cut
  if (sr_helper->getPassSRWWbMt2() == false) return false;

  // check if event passes mll cut
  if (sr_helper->getPassSRWWbMll() == false) return false;

  // check if event passes ptll cut
  if (sr_helper->getPassSRWWbPtll() == false) return false;

  return true;
}

// -----------------------------------------------------------------------------
bool SelectionTools::ControlRegionTool::passSRWWc(
    SusyAnalysisTools::EventDescription* event_desc,
    SusyAnalysisTools::SRHelper* sr_helper)
{
  // require emu events
  if (event_desc->getFlavorChannel() != FLAVOR_EM) return false;
  // require OS leptons
  if (event_desc->getSignChannel() != SIGN_OS) return false;

  // full jet veto
  if (sr_helper->getPassLJetVeto() == false) return false;
  if (sr_helper->getPassBJetVeto() == false) return false;
  if (sr_helper->getPassFJetVeto() == false) return false;

  // check pT of leptons
  if (sr_helper->getPassSRWWLep1Pt() == false) return false;
  if (sr_helper->getPassSRWWLep2Pt() == false) return false;

  // check if event passes mt2 cut
  if (sr_helper->getPassSRWWcMt2() == false) return false;

  // check if event passes ptll cut
  if (sr_helper->getPassSRWWcPtll() == false) return false;

  return true;
}

// -----------------------------------------------------------------------------
bool SelectionTools::ControlRegionTool::passSRZJets(
    SusyAnalysisTools::EventDescription* event_desc,
    SusyAnalysisTools::SRHelper* sr_helper)
{
  // require ee/mm events
  if (event_desc->getFlavorChannel() == FLAVOR_EM) return false;

  // require OS leptons
  if (event_desc->getSignChannel() != SIGN_OS) return false;

  // require event be in z-window
  if (sr_helper->getPassZVeto() == true) return false;

  // veto b/f jets
  if (sr_helper->getPassBJetVeto() == false) return false;
  if (sr_helper->getPassFJetVeto() == false) return false;

  // require the correct number of light central jets
  if (sr_helper->getPassSRZJetsNumLJets() == false) return false;

  // check if event passes top veto
  if (sr_helper->getPassTopVeto() == false) return false;

  // check if event passes met-rel cut
  if (sr_helper->getPassSRZJetsMetRel() == false) return false;

  // check pT of leptons
  if (sr_helper->getPassSRZJetsJet1Pt() == false) return false;
  if (sr_helper->getPassSRZJetsJet2Pt() == false) return false;

  // check if event passes Mjj cut
  if (sr_helper->getPassSRZJetsMjj() == false) return false;

  // check if event passes MT2 cut
  if (sr_helper->getPassSRZJetsMt2() == false) return false;

  return true;
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
bool SelectionTools::ControlRegionTool::passFullJetVeto(const JetContainer* jets)
{
  size_t num_jets = jets->num(JET_ALL_SIGNAL);
  return (num_jets == 0);
}

// ----------------------------------------------------------------------------
bool SelectionTools::ControlRegionTool::passCut( double test
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
*/