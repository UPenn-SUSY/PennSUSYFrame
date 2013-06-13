#include "SelectionTools/include/TauSelectionTool.h"

#include <vector>
#include <math.h>

#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/Tau.h"
#include "AtlasSFrameUtils/include/TauContainer.h"
#include "AtlasSFrameUtils/include/VertexContainer.h"

// -----------------------------------------------------------------------------
SelectionTools::TauSelectionTool::TauSelectionTool(
    SCycleBase* parent, const char* name): ToolBase(parent, name)
{
  DeclareProperty("baseline_min_pt", c_baseline_min_pt = 10e3);
  DeclareProperty("baseline_max_pt", c_baseline_max_pt = -1);

  DeclareProperty("baseline_min_eta", c_baseline_min_eta = -1);
  DeclareProperty("baseline_max_eta", c_baseline_max_eta = 2.5);
}

// -----------------------------------------------------------------------------
SelectionTools::TauSelectionTool::~TauSelectionTool()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void SelectionTools::TauSelectionTool::process(
    Tau* tau, const VertexContainer& vertices)
{
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
  bool pass_jet_bdt_level = (  (  c_jet_bdt_level == TAU_JET_BDT_LOOSE
                               && tau->JetBDTSigLoose() == true
                               )
                            || (  c_jet_bdt_level == TAU_JET_BDT_MEDIUM
                               && tau->JetBDTSigMedium() == true
                               )
                            || (  c_jet_bdt_level == TAU_JET_BDT_TIGHT
                               && tau->JetBDTSigTight() == true
                               )
                            );
  tau_desc->setPassBaselineJetBDTLevel(pass_jet_bdt_level);

  // Check ele bdt level
  bool pass_ele_bdt_level = (  (  c_ele_bdt_level == TAU_ELE_BDT_LOOSE
                               && ( tau->EleBDTLoose() == true
                                  || tau->numTrack() == 3
                                  )
                               )
                            || (  c_ele_bdt_level == TAU_ELE_BDT_MEDIUM
                               && ( tau->EleBDTMedium() == true
                                  || tau->numTrack() == 3
                                  )
                               )
                            || (  c_ele_bdt_level == TAU_ELE_BDT_TIGHT
                               && ( tau->EleBDTTight() == true
                                  || tau->numTrack() == 3
                                  )
                               )
                            );
  tau_desc->setPassBaselineEleBDTLevel(pass_ele_bdt_level);

  // Check muon veto
  bool pass_muon_veto = (  (  c_muon_veto_level == TAU_MU_LOOSE
                           && tau->muonVeto() == false
                           )
                        || (  c_muon_veto_level == TAU_MU_TIGHT
                           && tau->muonVeto() == false
                           )
                        );
  tau_desc->setPassBaselineMuVeto(pass_ele_bdt_level);
}

// -----------------------------------------------------------------------------
bool SelectionTools::TauSelectionTool::isBaseline(Tau* tau)
{
  // Check if this tau passed all baseline cuts
  SusyAnalysisTools::TauDescription* tau_desc = tau->getTauDesc();
  bool pass_baseline = true;
  // bool pass_baseline = (  tau_desc->getPassBaselinePt()
  //                      && tau_desc->getPassBaselineEta()
  //                      );
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
bool SelectionTools::TauSelectionTool::getCorrectedEleBDTFlag( const Tau* tau
    , TAU_ELE_BDT_LEVEL tau_ele_bdt_level
    , bool do_correction
    )
{
  bool old_bdt_flag = (  (  c_ele_bdt_level == TAU_ELE_BDT_LOOSE
                         && tau->EleBDTLoose()
                         )
                      || (  c_ele_bdt_level == TAU_ELE_BDT_MEDIUM
                         && tau->EleBDTMedium()
                         )
                      || (  c_ele_bdt_level == TAU_ELE_BDT_TIGHT
                         && tau->EleBDTTight()
                         )
                      );
  if (!do_correction || tau->numTrack() != 1 || tau->pt() < 80e3 )
    return old_bdt_flag;

  double pt = tau->pt()/1e3;
  double eta = tau->eta();
  double cut_val = 0.;

  if (tau_ele_bdt_level == TAU_ELE_BDT_LOOSE) {
    if (pt <= 800 && eta <= 3.0) {
    }
    else if (pt <= 800 && eta > 3.0) {
    }
    else if (pt > 800 && eta <= 3.0) {
    }
    else {
    }
  }

  else if (tau_ele_bdt_level == TAU_ELE_BDT_MEDIUM) {
    if (pt <= 800 && eta <= 3.0) {
    }
    else if (pt <= 800 && eta > 3.0) {
    }
    else if (pt > 800 && eta <= 3.0) {
    }
    else {
    }
  }

  else if (tau_ele_bdt_level == TAU_ELE_BDT_TIGHT) {
    if (pt <= 800 && eta <= 3.0) {
    }
    else if (pt <= 800 && eta > 3.0) {
    }
    else if (pt > 800 && eta <= 3.0) {
    }
    else {
    }
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
