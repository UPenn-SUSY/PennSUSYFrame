#include "SelectionTools/include/TauSelectionTool.h"

#include <vector>
#include <math.h>

#include <TH2.h>

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Tau.h"
#include "AtlasSFrameUtils/include/TauContainer.h"
#include "AtlasSFrameUtils/include/VertexContainer.h"

// -----------------------------------------------------------------------------
SelectionTools::TauSelectionTool::TauSelectionTool(
    SCycleBase* parent, const char* name): ToolBase(parent, name)
                                         , m_jet_bdt_level_configured(false)
                                         , m_ele_bdt_level_configured(false)
                                         , m_muon_veto_level_configured(false)
                                         , m_jet_bdt_level(TAU_JET_BDT_NONE)
                                         , m_ele_bdt_level(TAU_ELE_BDT_NONE)
                                         , m_muon_veto_level(TAU_MU_NONE)
                                         , m_tau_ele_corr(NULL)
{
  DeclareProperty("baseline_min_pt", c_baseline_min_pt = 10e3);
  DeclareProperty("baseline_max_pt", c_baseline_max_pt = -1);

  DeclareProperty("baseline_min_eta", c_baseline_min_eta = -1);
  DeclareProperty("baseline_max_eta", c_baseline_max_eta = 2.5);

  DeclareProperty("ele_corr_file",   c_tau_ele_corr_file   = "");
  DeclareProperty("jet_bdt_level",   c_jet_bdt_level_int   = 0);
  DeclareProperty("ele_bdt_level",   c_ele_bdt_level_int   = 0);
  DeclareProperty("muon_veto_level", c_muon_veto_level_int = 0);
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
  if (!m_jet_bdt_level_configured) {
    switch (c_jet_bdt_level_int) {
      case 1:  m_jet_bdt_level = TAU_JET_BDT_LOOSE;
               break;
      case 2:  m_jet_bdt_level = TAU_JET_BDT_MEDIUM;
               break;
      case 3:  m_jet_bdt_level = TAU_JET_BDT_TIGHT;
               break;
      case 0:
      default: m_jet_bdt_level = TAU_JET_BDT_NONE;
               break;
    }
    m_jet_bdt_level_configured = true;
  }

  // set ele bdt level
  if (!m_ele_bdt_level_configured) {
    switch (c_ele_bdt_level_int) {
      case 1:  m_ele_bdt_level = TAU_ELE_BDT_LOOSE;
               break;
      case 2:  m_ele_bdt_level = TAU_ELE_BDT_MEDIUM;
               break;
      case 3:  m_ele_bdt_level = TAU_ELE_BDT_TIGHT;
               break;
      case 0:
      default: m_ele_bdt_level = TAU_ELE_BDT_NONE;
               break;
    }
    if (m_ele_bdt_level != TAU_ELE_BDT_NONE) {
      if (c_tau_ele_corr_file == "") {
        std::string maindir = "";
        char *tmparea=getenv("ROOTCOREDIR");
        if (tmparea != NULL) {
          maindir = tmparea;
          maindir = maindir + "/";
        }
        c_tau_ele_corr_file =
          maindir + "/../SUSYTools/data/ParametrizedEleBDTSelection.root";
      }
      TFile* tau_ele_correction_file = new TFile(c_tau_ele_corr_file.c_str());

      switch (m_ele_bdt_level) {
        case TAU_ELE_BDT_LOOSE:
          m_tau_ele_corr = dynamic_cast<TH2*>(
              tau_ele_correction_file->Get("h2_BDTEleDecision_pteta_loose"));
          break;
        case TAU_ELE_BDT_MEDIUM:
          m_tau_ele_corr = dynamic_cast<TH2*>(
              tau_ele_correction_file->Get("h2_BDTEleDecision_pteta_medium"));
          break;
        case TAU_ELE_BDT_TIGHT:
          m_tau_ele_corr = dynamic_cast<TH2*>(
              tau_ele_correction_file->Get("h2_BDTEleDecision_pteta_tight"));
          break;
        case TAU_ELE_BDT_NONE:
        default:
          m_tau_ele_corr = NULL;
          break;
      }
      m_ele_bdt_level_configured = true;
    }
  }

  // set muon level
  if (!m_muon_veto_level_configured) {
    switch (c_muon_veto_level_int) {
      case 1:  m_muon_veto_level = TAU_MU_LOOSE;
               break;
      case 2:  m_muon_veto_level = TAU_MU_TIGHT;
               break;
      case 0:
      default: m_muon_veto_level = TAU_MU_NONE;
               break;
    }
    m_muon_veto_level_configured = true;
  }
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
  bool pass_baseline_eta = passCut(eta, c_baseline_min_eta, c_baseline_max_eta);
  tau_desc->setPassBaselineEta(pass_baseline_eta);

  // Check for baseline number of tracks
  bool pass_baseline_num_tracks = ((tau->numTrack() == 1) || (tau->numTrack() == 3));
  tau_desc->setPassBaselineNumTracks(pass_baseline_num_tracks);

  // Check the charge of the tau
  bool pass_baseline_charge = (fabs(tau->charge()) == 1);
  tau_desc->setPassBaselineCharge(pass_baseline_charge);

  // Check jet bdt level
  bool pass_jet_bdt_level = (  (  m_jet_bdt_level == TAU_JET_BDT_LOOSE
                               && tau->JetBDTSigLoose() == true
                               )
                            || (  m_jet_bdt_level == TAU_JET_BDT_MEDIUM
                               && tau->JetBDTSigMedium() == true
                               )
                            || (  m_jet_bdt_level == TAU_JET_BDT_TIGHT
                               && tau->JetBDTSigTight() == true
                               )
                            );
  tau_desc->setPassBaselineJetBDTLevel(pass_jet_bdt_level);

  // Check ele bdt level
  bool pass_ele_bdt_level = (  getCorrectedEleBDTFlag(tau) == false
                            || tau->numTrack() != 1
                            );
  tau_desc->setPassBaselineEleBDTLevel(pass_ele_bdt_level);

  // Check muon veto
  bool pass_muon_veto = (  (  m_muon_veto_level == TAU_MU_NONE )
                        || (  m_muon_veto_level == TAU_MU_LOOSE )
                        || (  m_muon_veto_level == TAU_MU_TIGHT
                           && tau->muonVeto() == false
                           )
                        );
  tau_desc->setPassBaselineMuVeto(pass_muon_veto);
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
  bool pass_signal = true;
  // bool pass_signal = (  tau_desc->getPassD0Sig()
  //                    && tau_desc->getPassZ0SinTheta()
  //                    && tau_desc->getPassPtIso()
  //                    );
  // tau_desc->setPassSignal(pass_signal);

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
bool SelectionTools::TauSelectionTool::getCorrectedEleBDTFlag(const Tau* tau)
{
  bool old_bdt_flag = (  (  m_ele_bdt_level == TAU_ELE_BDT_LOOSE
                         && tau->EleBDTLoose()
                         )
                      || (  m_ele_bdt_level == TAU_ELE_BDT_MEDIUM
                         && tau->EleBDTMedium()
                         )
                      || (  m_ele_bdt_level == TAU_ELE_BDT_TIGHT
                         && tau->EleBDTTight()
                         )
                      );
  if (  m_ele_bdt_level == TAU_ELE_BDT_NONE
     || tau->numTrack() != 1
     || tau->pt() < 80e3
     ) {
    return old_bdt_flag;
  }

  double pt = tau->pt()/1e3;
  // double eta = tau->eta();
  double eta = tau->leadTrack_eta();
  double cut_val = 0.;

  if (pt <= 800 && eta <= 3.0) {
    cut_val = m_tau_ele_corr->GetBinContent(m_tau_ele_corr->FindBin(pt, eta));
  }
  else if (pt <= 800 && eta > 3.0) {
    cut_val = m_tau_ele_corr->GetBinContent(m_tau_ele_corr->FindBin(pt, 2.9));
  }
  else if (pt > 800 && eta <= 3.0) {
    cut_val = m_tau_ele_corr->GetBinContent(m_tau_ele_corr->FindBin(799, eta));
  }
  else {
    cut_val = m_tau_ele_corr->GetBinContent(m_tau_ele_corr->FindBin(799, 2.9));
  }

  return (tau->BDTEleScore() > cut_val);
}

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
