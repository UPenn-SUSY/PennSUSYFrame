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
#include "CommonTools/include/DeltaPhiTool.h"

// -----------------------------------------------------------------------------
SelectionTools::SignalRegionTool::SignalRegionTool(
    SCycleBase* parent, const char* name): ToolBase(parent, name)
                                         , m_top_tag_tool(NULL)
{
  DeclareProperty("z_window_mll_min", c_z_window_mll_min = 81200);
  DeclareProperty("z_window_mll_max", c_z_window_mll_max = 101200);

  // SR SS cut values
  DeclareProperty("sr_ss_ee_min_mll_veto", c_sr_ss_mll_veto_min = 90e3);
  DeclareProperty("sr_ss_ee_max_mll_veto", c_sr_ss_mll_veto_max = 120e3);

  DeclareProperty("sr_ss_ee_min_met_rel", c_sr_ss_ee_met_rel_min = 70e3);
  DeclareProperty("sr_ss_ee_max_met_rel", c_sr_ss_ee_met_rel_max = -1);

  DeclareProperty("sr_ss_mm_min_met_rel", c_sr_ss_mm_met_rel_min = 50e3);
  DeclareProperty("sr_ss_mm_max_met_rel", c_sr_ss_mm_met_rel_max = -1);

  DeclareProperty("sr_ss_em_min_met_rel", c_sr_ss_em_met_rel_min = 50e3);
  DeclareProperty("sr_ss_em_max_met_rel", c_sr_ss_em_met_rel_max = -1);

  DeclareProperty("sr_ss_ee_min_emma_mt", c_sr_ss_ee_emma_mt_min = -1);
  DeclareProperty("sr_ss_ee_max_emma_mt", c_sr_ss_ee_emma_mt_max = 70e3);

  DeclareProperty("sr_ss_mm_min_emma_mt", c_sr_ss_mm_emma_mt_min = -1);
  DeclareProperty("sr_ss_mm_max_emma_mt", c_sr_ss_mm_emma_mt_max = 50e3);

  DeclareProperty("sr_ss_em_min_emma_mt", c_sr_ss_em_emma_mt_min = -1);
  DeclareProperty("sr_ss_em_max_emma_mt", c_sr_ss_em_emma_mt_max = 50e3);

  DeclareProperty("sr_ss_dphi_ll_min", c_sr_ss_dphi_ll_min = 1.3);
  DeclareProperty("sr_ss_dphi_ll_max", c_sr_ss_dphi_ll_max = -1);

  DeclareProperty("sr_ss_num_l_jets_min", c_sr_ss_num_l_jets_min = 1);
  DeclareProperty("sr_ss_num_l_jets_max", c_sr_ss_num_l_jets_max = -1);
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

  std::pair<float, float> lep_pts = getLeadingLeptonPts(event, electrons, muons);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  // Check light jet veto
  bool pass_l_jet_veto = (jets.num(JET_LIGHT) == 0);
  sr_helper->setPassLJetVeto(pass_l_jet_veto);

  // Check b jet veto
  bool pass_b_jet_veto = (jets.num(JET_B) == 0);
  sr_helper->setPassBJetVeto(pass_b_jet_veto);

  // Check forward jet veto
  bool pass_f_jet_veto = (jets.num(JET_FORWARD) == 0);
  sr_helper->setPassFJetVeto(pass_f_jet_veto);

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

  // get MET-rel value
  double met_rel = event->getMetRel();

  // get ptll value
  double ptll = event->getPtll();

  // get delta phi value
  double dphi_ll = event->getDeltaPhill();

  // get emma mT value
  double emma_mt = event->getEmmaMt();

  // get mT value
  double mt = event->getMt();

  // get mT2 value
  double mt2 = event->getMt2();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // check SR SS cuts
  // check metrel and emma mt
  if (event->getFlavorChannel() == FLAVOR_EE) {
    sr_helper->setPassSRSSMllVeto(true);
    sr_helper->setPassSRSSMetRel( passCut( met_rel
                                         , c_sr_ss_ee_met_rel_min
                                         , c_sr_ss_ee_met_rel_max
                                         )
                                );
    sr_helper->setPassSRSSEmmaMt( passCut( emma_mt
                                         , c_sr_ss_ee_emma_mt_min
                                         , c_sr_ss_ee_emma_mt_max
                                         )
                                );
  }
  else if (event->getFlavorChannel() == FLAVOR_MM) {
    sr_helper->setPassSRSSMllVeto( !passCut( mll
                                            , c_sr_ss_mll_veto_min
                                            , c_sr_ss_mll_veto_max
                                            )
                                 );
    sr_helper->setPassSRSSMetRel( passCut( met_rel
                                         , c_sr_ss_mm_met_rel_min
                                         , c_sr_ss_mm_met_rel_max
                                         )
                                );
    sr_helper->setPassSRSSEmmaMt( passCut( emma_mt
                                         , c_sr_ss_mm_emma_mt_min
                                         , c_sr_ss_mm_emma_mt_max
                                         )
                                );
  }
  else if (event->getFlavorChannel() == FLAVOR_EM) {
    sr_helper->setPassSRSSMllVeto(true);
    sr_helper->setPassSRSSMetRel( passCut( met_rel
                                         , c_sr_ss_em_met_rel_min
                                         , c_sr_ss_em_met_rel_max
                                         )
                                );
    sr_helper->setPassSRSSEmmaMt( passCut( emma_mt
                                         , c_sr_ss_em_emma_mt_min
                                         , c_sr_ss_em_emma_mt_max
                                         )
                                );
  }

  // check dphi_ll
  // double dphi_ll = CommonTools::DeltaPhiTool::getDeltaPhi( event->getFlavorChannel()
  //                                                        , electrons.getElectrons(EL_GOOD)
  //                                                        , muons.getMuons(MU_GOOD)
  //                                                        );
  sr_helper->setPassSRSSDphill( passCut( dphi_ll
                                       , c_sr_ss_dphi_ll_min
                                       , c_sr_ss_dphi_ll_max
                                       )
                              );

  // check number of l jets
  int num_l_jets = jets.num(JET_LIGHT);
  sr_helper->setPassSRSSNumLJets( passCut( num_l_jets
                                         , c_sr_ss_num_l_jets_min
                                         , c_sr_ss_num_l_jets_max
                                         )
                                );

  // Check for signal regions
  event_desc->setSRSS( passSRSS(event_desc, sr_helper));
}

// -----------------------------------------------------------------------------
bool SelectionTools::SignalRegionTool::passSRSS(
    SusyAnalysisTools::EventDescription* event_desc,
    SusyAnalysisTools::SRHelper* sr_helper)
{
  // require SS leptons
  if (event_desc->getSignChannel() != SIGN_SS) return false;

  // check for mll  veto
  if (sr_helper->getPassSRSSMllVeto() == false) return false;

  // veto on b jets and f jets
  if (sr_helper->getPassBJetVeto() == false) return false;
  // if (sr_helper->getPassFJetVeto() == false) return false;

  // require we have L jets
  if (sr_helper->getPassSRSSNumLJets() == false) return false;

  // Z veto
  if (  event_desc->getFlavorChannel() == FLAVOR_EE
     && sr_helper->getPassZVeto() == false
     ) {
    return false;
  }
  // if (sr_helper->getPassZVeto() == false) return false;

  // MET-rel cut
  if (sr_helper->getPassSRSSMetRel() == false) return false;

  // emma_mt cut
  if (sr_helper->getPassSRSSEmmaMt() == false) return false;

  // dphi cut
  if (sr_helper->getPassSRSSDphill() == false) return false;

  return true;
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

// -----------------------------------------------------------------------------
std::pair<float, float> SelectionTools::SignalRegionTool::getLeadingLeptonPts(
    const Event* event, const ElectronContainer& electrons, const MuonContainer& muons)
{
  std::pair<float, float> lep_pts(0,0);

  if (event->getFlavorChannel() == FLAVOR_EE) {
    std::vector<Electron*> el_list = electrons.getElectrons(EL_GOOD);
    lep_pts.first  = el_list.at(0)->getTlv().Pt();
    lep_pts.second = el_list.at(1)->getTlv().Pt();
  }
  else if (event->getFlavorChannel() == FLAVOR_MM) {
    std::vector<Muon*> mu_list = muons.getMuons(MU_GOOD);
    lep_pts.first  = mu_list.at(0)->getTlv().Pt();
    lep_pts.second = mu_list.at(1)->getTlv().Pt();
  }
  else if (event->getFlavorChannel() == FLAVOR_EM) {
    std::vector<Electron*> el_list = electrons.getElectrons(EL_GOOD);
    std::vector<Muon*>     mu_list = muons.getMuons(        MU_GOOD);
    lep_pts.first  = el_list.at(0)->getTlv().Pt();
    lep_pts.second = mu_list.at(0)->getTlv().Pt();
  }

  // ensure first >= second
  if (lep_pts.first < lep_pts.second) {
    float tmp = lep_pts.first;
    lep_pts.first = lep_pts.second;
    lep_pts.second = tmp;
  }

  return lep_pts;
}
