#include "SelectionTools/include/TauSelectionTool.h"

#include <vector>
#include <math.h>

#include <TH2.h>
#include <TFile.h>

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Tau.h"
#include "AtlasSFrameUtils/include/TauContainer.h"
#include "AtlasSFrameUtils/include/VertexContainer.h"

// -----------------------------------------------------------------------------
SelectionTools::TauSelectionTool::TauSelectionTool(
    SCycleBase* parent, const char* name): ToolBase(parent, name)
                                         , m_baseline_jet_bdt_level(TAU_JET_BDT_NONE)
                                         , m_baseline_ele_bdt_level(TAU_ELE_BDT_NONE)
                                         , m_baseline_muon_veto_level(TAU_MU_NONE)
                                         , m_signal_jet_bdt_level(TAU_JET_BDT_NONE)
                                         , m_signal_ele_bdt_level(TAU_ELE_BDT_NONE)
                                         , m_signal_muon_veto_level(TAU_MU_NONE)
                                         , m_tau_ele_corr(NULL)
{
  DeclareProperty("baseline_min_pt", c_baseline_min_pt = 10e3);
  DeclareProperty("baseline_max_pt", c_baseline_max_pt = -1);

  DeclareProperty("baseline_min_eta", c_baseline_min_eta = -1);
  DeclareProperty("baseline_max_eta", c_baseline_max_eta = 2.5);

  DeclareProperty("baseline_jet_bdt_level",   c_baseline_jet_bdt_level_int   = 0);
  DeclareProperty("baseline_ele_bdt_level",   c_baseline_ele_bdt_level_int   = 0);
  DeclareProperty("baseline_muon_veto_level", c_baseline_muon_veto_level_int = 0);

  DeclareProperty("signal_jet_bdt_level",   c_signal_jet_bdt_level_int   = 0);
  DeclareProperty("signal_ele_bdt_level",   c_signal_ele_bdt_level_int   = 0);
  DeclareProperty("signal_muon_veto_level", c_signal_muon_veto_level_int = 0);

  DeclareProperty("ele_corr_file",   c_tau_ele_corr_file   = "");
}

// -----------------------------------------------------------------------------
SelectionTools::TauSelectionTool::~TauSelectionTool()
{
  // do nothing
}

// // -----------------------------------------------------------------------------
// void SelectionTools::TauSelectionTool::BeginInputFile(const SInputData&)
// {
//   configure();
// }

// -----------------------------------------------------------------------------
void SelectionTools::TauSelectionTool::configure()
{
  // set jet bdt level
  setJetBDTLevel(m_baseline_jet_bdt_level, c_baseline_jet_bdt_level_int);
  setJetBDTLevel(m_signal_jet_bdt_level  , c_signal_jet_bdt_level_int  );

  // set ele bdt level
  setEleBDTLevel(m_baseline_ele_bdt_level, c_baseline_ele_bdt_level_int);
  setEleBDTLevel(m_signal_ele_bdt_level  , c_signal_ele_bdt_level_int  );

  // set muon level
  setMuLevel(m_baseline_muon_veto_level, c_baseline_muon_veto_level_int);
  setMuLevel(m_signal_muon_veto_level  , c_signal_muon_veto_level_int  );
}

// -----------------------------------------------------------------------------
void SelectionTools::TauSelectionTool::process( Tau* tau
                                              , const VertexContainer& vertices
                                              )
{
  configure();

  SusyAnalysisTools::TauDescription* tau_desc = tau->getTauDesc();

  double pt  = tau->getTlv().Pt();
  double eta = fabs(tau->getTlv().Eta());

  // Check for baseline pt
  bool pass_baseline_pt = passCut(pt, c_baseline_min_pt, c_baseline_max_pt);
  tau_desc->setPassBaselinePt(pass_baseline_pt);

  // Check for baseline eta
  bool pass_baseline_eta = (  passCut(eta, c_baseline_min_eta, c_baseline_max_eta)
                           && passCut( tau->leadTrack_eta()
                                     , c_baseline_min_eta
                                     , c_baseline_max_eta
                                     )
                           );
  tau_desc->setPassBaselineEta(pass_baseline_eta);

  // Check for baseline number of tracks
  bool pass_baseline_num_tracks = ((tau->numTrack() == 1) || (tau->numTrack() == 3));
  tau_desc->setPassBaselineNumTracks(pass_baseline_num_tracks);

  // Check the charge of the tau
  bool pass_baseline_charge = (fabs(tau->charge()) == 1);
  tau_desc->setPassBaselineCharge(pass_baseline_charge);

  // Check jet bdt level
  bool pass_baseline_jet_bdt_level = checkJetBDTLevel(tau, m_baseline_jet_bdt_level);
  bool pass_signal_jet_bdt_level   = checkJetBDTLevel(tau, m_signal_jet_bdt_level);

  tau_desc->setPassBaselineJetBDTLevel(pass_baseline_jet_bdt_level);
  tau_desc->setPassSignalJetBDTLevel(pass_signal_jet_bdt_level);

  // Check ele bdt level
  bool pass_baseline_ele_bdt_level = checkEleBDTLevel(tau, m_baseline_ele_bdt_level);
  bool pass_signal_ele_bdt_level   = checkEleBDTLevel(tau, m_signal_ele_bdt_level);

  tau_desc->setPassBaselineEleBDTLevel(pass_baseline_ele_bdt_level);
  tau_desc->setPassSignalEleBDTLevel(pass_signal_ele_bdt_level);

  // Check muon veto
  bool pass_baseline_mu_veto = checkMuLevel(tau, m_baseline_muon_veto_level);
  bool pass_signal_mu_veto   = checkMuLevel(tau, m_signal_muon_veto_level  );

  tau_desc->setPassBaselineMuVeto(pass_baseline_mu_veto);
  tau_desc->setPassSignalMuVeto(  pass_signal_mu_veto  );
}

// -----------------------------------------------------------------------------
bool SelectionTools::TauSelectionTool::isBaseline(Tau* tau)
{
  // Check if this tau passed all baseline cuts
  SusyAnalysisTools::TauDescription* tau_desc = tau->getTauDesc();
  bool pass_baseline = (  tau_desc->getPassBaselinePt()
                       && tau_desc->getPassBaselineEta()
                       && tau_desc->getPassBaselineNumTracks()
                       && tau_desc->getPassBaselineCharge()
                       && tau_desc->getPassBaselineJetBDTLevel()
                       && tau_desc->getPassBaselineEleBDTLevel()
                       && tau_desc->getPassBaselineMuVeto()
                       );
  tau_desc->setPassBaseline(pass_baseline);

  return pass_baseline;
}

// -----------------------------------------------------------------------------
bool SelectionTools::TauSelectionTool::isSignal(Tau* tau)
{
  // Check if this tau passed all signal cuts
  SusyAnalysisTools::TauDescription* tau_desc = tau->getTauDesc();
  bool pass_signal = (  tau_desc->getPassSignalJetBDTLevel()
                     && tau_desc->getPassSignalEleBDTLevel()
                     && tau_desc->getPassSignalMuVeto()
                     );
  tau_desc->setPassSignal(pass_signal);

  return pass_signal;
}

// -----------------------------------------------------------------------------
std::vector<Tau*> SelectionTools::TauSelectionTool::getBaselineTaus(
    const TauContainer& tau_container)
{
  const std::vector<Tau*> all_taus = tau_container.getTaus(TAU_ALL);
  return getBaselineTaus(all_taus);
}

// -----------------------------------------------------------------------------
std::vector<Tau*> SelectionTools::TauSelectionTool::getBaselineTaus(
    const std::vector<Tau*>& all_taus)
{
  size_t term = all_taus.size();

  std::vector<Tau*> baseline_taus;
  baseline_taus.reserve(term);

  for (size_t tau_it = 0; tau_it != term; ++tau_it) {
    if (isBaseline(all_taus.at(tau_it))) {
      baseline_taus.push_back(all_taus.at(tau_it));
    }
  }

  return baseline_taus;
}

// -----------------------------------------------------------------------------
std::vector<Tau*> SelectionTools::TauSelectionTool::getSignalTaus(
    const TauContainer& tau_container)
{
  const std::vector<Tau*> good_taus =
    tau_container.getTaus(TAU_GOOD);
  return getSignalTaus(good_taus);
}

// -----------------------------------------------------------------------------
std::vector<Tau*> SelectionTools::TauSelectionTool::getSignalTaus(
    const std::vector<Tau*>& good_taus)
{
  size_t term = good_taus.size();

  std::vector<Tau*> signal_taus;
  signal_taus.reserve(term);

  for (size_t tau_it = 0; tau_it != term; ++tau_it) {
    if (isSignal(good_taus.at(tau_it))) {
      signal_taus.push_back(good_taus.at(tau_it));
    }
  }

  return signal_taus;
}

// -----------------------------------------------------------------------------
void SelectionTools::TauSelectionTool::setJetBDTLevel(TAU_JET_BDT_LEVEL& level, int level_int)
{
  switch (level_int) {
    case 1:  level = TAU_JET_BDT_LOOSE;
              break;
    case 2:  level = TAU_JET_BDT_MEDIUM;
              break;
    case 3:  level = TAU_JET_BDT_TIGHT;
              break;
    case 0:
    default: level = TAU_JET_BDT_NONE;
              break;
  }
}

// -----------------------------------------------------------------------------
void SelectionTools::TauSelectionTool::setEleBDTLevel(TAU_ELE_BDT_LEVEL& level, int level_int)
{
  switch (level_int) {
    case 1:  level = TAU_ELE_BDT_LOOSE;
             break;
    case 2:  level = TAU_ELE_BDT_MEDIUM;
             break;
    case 3:  level = TAU_ELE_BDT_TIGHT;
             break;
    case 0:
    default: level = TAU_ELE_BDT_NONE;
             break;
  }
}

// -----------------------------------------------------------------------------
void SelectionTools::TauSelectionTool::setMuLevel(TAU_MU_LEVEL& level, int level_int)
{
  switch (level_int) {
    case 1:  level = TAU_MU_LOOSE;
             break;
    case 2:  level = TAU_MU_TIGHT;
             break;
    case 0:
    default: level = TAU_MU_NONE;
             break;
  }
}

// -----------------------------------------------------------------------------
bool SelectionTools::TauSelectionTool::checkJetBDTLevel(const Tau* tau, TAU_JET_BDT_LEVEL level)
{
  if (level == TAU_JET_BDT_LOOSE)  return tau->JetBDTSigLoose();
  if (level == TAU_JET_BDT_MEDIUM) return tau->JetBDTSigMedium();
  if (level == TAU_JET_BDT_TIGHT)  return tau->JetBDTSigTight();

  return true;
}

// -----------------------------------------------------------------------------
bool SelectionTools::TauSelectionTool::checkEleBDTLevel(const Tau* tau, TAU_ELE_BDT_LEVEL level)
{
  if (tau->numTrack() != 1) return true;
  if (level == TAU_ELE_BDT_LOOSE)  return (tau->EleBDTLoose()  == false);
  if (level == TAU_ELE_BDT_MEDIUM) return (tau->EleBDTMedium() == false);
  if (level == TAU_ELE_BDT_TIGHT)  return (tau->EleBDTTight()  == false);
  return true;
}

// -----------------------------------------------------------------------------
bool SelectionTools::TauSelectionTool::checkMuLevel(const Tau* tau, TAU_MU_LEVEL level)
{
  if (level == TAU_MU_TIGHT) return (tau->muonVeto() == false);
  return true;
}

// // -----------------------------------------------------------------------------
// bool SelectionTools::TauSelectionTool::getCorrectedEleBDTFlag(const Tau* tau)
// {
//   bool old_bdt_flag = (  (  m_ele_bdt_level == TAU_ELE_BDT_LOOSE
//                          && tau->EleBDTLoose()
//                          )
//                       || (  m_ele_bdt_level == TAU_ELE_BDT_MEDIUM
//                          && tau->EleBDTMedium()
//                          )
//                       || (  m_ele_bdt_level == TAU_ELE_BDT_TIGHT
//                          && tau->EleBDTTight()
//                          )
//                       );
//   std::cout << "getCorrectedEleBDTFlag(): \n";
//   std::cout << "\tpt: " << tau->getTlv().Pt() << "\n"
//             << "\tele_bdt_level: " << m_ele_bdt_level << "\n"
//             << "\tEleBDTLoose: "   << tau->EleBDTLoose()
//             << "\tEleBDTMedium: "  << tau->EleBDTMedium()
//             << "\tEleBDTTight: "   << tau->EleBDTTight()
//             << "\told bdt flag: "  << old_bdt_flag
//             << "\n";
// 
//   return old_bdt_flag;
// 
//   /*
//   if (  m_ele_bdt_level == TAU_ELE_BDT_NONE
//      || tau->numTrack() != 1
//      || tau->pt() < 80e3
//      ) {
//     return old_bdt_flag;
//   }
// 
// 
//   double pt = tau->pt()/1e3;
//   // double eta = tau->eta();
//   double eta = tau->leadTrack_eta();
//   double cut_val = 0.;
// 
//   if (pt <= 800 && eta <= 3.0) {
//     cut_val = m_tau_ele_corr->GetBinContent(m_tau_ele_corr->FindBin(pt, eta));
//   }
//   else if (pt <= 800 && eta > 3.0) {
//     cut_val = m_tau_ele_corr->GetBinContent(m_tau_ele_corr->FindBin(pt, 2.9));
//   }
//   else if (pt > 800 && eta <= 3.0) {
//     cut_val = m_tau_ele_corr->GetBinContent(m_tau_ele_corr->FindBin(799, eta));
//   }
//   else {
//     cut_val = m_tau_ele_corr->GetBinContent(m_tau_ele_corr->FindBin(799, 2.9));
//   }
// 
//   // std::cout << "\ttau pT: " << pt << " GeV"
//   //           << "\ttau BDT ele score: " << tau->BDTEleScore()
//   //           << "\tcut value: " << cut_val
//   //           << "\ttau EleBDTFlag: " << (tau->BDTEleScore() > cut_val)
//   //           << "\n";
// 
//   // return (tau->BDTEleScore() > cut_val);
//   return (tau->BDTEleScore() <= cut_val);
//   */
// }

// -----------------------------------------------------------------------------
bool SelectionTools::TauSelectionTool::passCut( double test
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
