#include <math.h>
#include "include/MuonSelectionTool.h"

// ----------------------------------------------------------------------------
SelectionTools::MuonSelectionTool::MuonSelectionTool(
    SCycleBase* parent, const char* name): ToolBase(parent, name)
{
  DeclareProperty("baseline_min_pt", c_baseline_min_pt = 10e3);
  DeclareProperty("baseline_max_pt", c_baseline_max_pt = -1);

  DeclareProperty("baseline_min_eta", c_baseline_min_eta = -1);
  DeclareProperty("baseline_max_eta", c_baseline_max_eta = 2.4);

  DeclareProperty("signal_min_d0_sig", c_signal_min_d0_sig = -1);
  DeclareProperty("signal_max_d0_sig", c_signal_max_d0_sig = 3.);

  DeclareProperty("signal_min_z0_sin_theta", c_signal_min_z0_sin_theta = -1);
  DeclareProperty("signal_max_z0_sin_theta", c_signal_max_z0_sin_theta = 1.);

  DeclareProperty("signal_min_ptcone_cut", c_signal_min_ptcone_cut = -1);
  DeclareProperty("signal_max_ptcone_cut", c_signal_max_ptcone_cut = 0.12);

  DeclareProperty("cosmic_min_d0", c_cosmic_min_d0= 0.2);
  DeclareProperty("cosmic_max_d0", c_cosmic_max_d0= -1);

  DeclareProperty("cosmic_min_z0", c_cosmic_min_z0= 1.);
  DeclareProperty("cosmic_max_z0", c_cosmic_max_z0= -1);

  DeclareProperty("bad_min_qoverp_ratio", c_bad_min_qoverp_ratio= 0.2);
  DeclareProperty("bad_max_qoverp_ratio", c_bad_max_qoverp_ratio= -1);
}

// ----------------------------------------------------------------------------
SelectionTools::MuonSelectionTool::~MuonSelectionTool()
{
  // do nothing
}

// ----------------------------------------------------------------------------
bool SelectionTools::MuonSelectionTool::isBaseline(Muon* mu)
{
  // Check for baseline pt
  double pt = mu->getTlv().Pt();
  if (!passCut(pt, c_baseline_min_pt, c_baseline_max_pt))
    return false;

  // Check for baseline eta
  double eta = fabs(mu->getTlv().Eta());
  if (!passCut(eta, c_baseline_min_eta, c_baseline_max_eta))
    return false;

  // Passed all cuts. This is a baseline muon
  return true;
}

// ----------------------------------------------------------------------------
bool SelectionTools::MuonSelectionTool::isSignal(Muon* mu)
{
  // check for signal d0 significance
  double d0_sig = fabs(mu->getD0Significance());
  if (!passCut(d0_sig, c_signal_min_d0_sig, c_signal_max_d0_sig))
    return false;

  // check for signal z0 sin(theta)
  double z0_sin_theta = fabs(mu->getZ0SinTheta());
  if (!passCut( z0_sin_theta
              , c_signal_min_z0_sin_theta
              , c_signal_max_z0_sin_theta
              ) )
    return false;

  // Check for signal isolation
  // TODO get proper value for num good vertices
  int num_good_vertices = 0;
  double ptcone30 = mu->getIsoCorr( CommonTools::PTCONE
                                  , 30
                                  , num_good_vertices
                                  );
  double pt = mu->getTlv().Pt();
  double ptcone_ratio = ptcone30/pt;

  if (!passCut(ptcone_ratio, c_signal_min_ptcone_cut, c_signal_max_ptcone_cut))
      return false;

  // Passed all cuts. This is a signal muo1n
  return true;
}

// ----------------------------------------------------------------------------
bool SelectionTools::MuonSelectionTool::isCosmic(Muon* mu)
{
  // check for signal d0 significance
  float d0 = mu->d0_exPV();
  if (!passCut(d0, c_cosmic_min_d0, c_cosmic_max_d0))
    return false;

  // check for signal z0 sin(theta)
  float z0 = fabs(mu->z0_exPV());
  if (!passCut(z0, c_cosmic_min_z0, c_cosmic_max_z0))
    return false;

  // Passed all cuts. This is a signal muo1n
  return true;
}

// ----------------------------------------------------------------------------
bool SelectionTools::MuonSelectionTool::isBad(Muon* mu)
{
  // check for signal d0 significance
  float cov_qoverp = mu->cov_qoverp_exPV();
  float qoverp     = mu->qoverp_exPV();
  float ratio = fabs(sqrt(cov_qoverp)/qoverp);
  if (!passCut(ratio, c_bad_min_qoverp_ratio, c_bad_max_qoverp_ratio))
    return false;

  // Passed all cuts. This is a signal muo1n
  return true;
}

// ----------------------------------------------------------------------------
bool SelectionTools::MuonSelectionTool::passCut( double test
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
