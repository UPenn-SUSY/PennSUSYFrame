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
  // tau_desc->setPassBaselinePt(pass_baseline_pt);

  // Check for baseline eta
  bool pass_baseline_eta = passCut(eta, c_baseline_min_eta, c_baseline_max_eta);
  // tau_desc->setPassBaselineEta(pass_baseline_eta);
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
