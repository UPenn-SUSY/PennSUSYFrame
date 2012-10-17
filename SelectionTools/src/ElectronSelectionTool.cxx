#include <math.h>
#include "include/ElectronSelectionTool.h"

// ----------------------------------------------------------------------------
SelectionTools::ElectronSelectionTool::ElectronSelectionTool(
    SCycleBase* parent, const char* name): ToolBase(parent, name)
{
  DeclareProperty("baseline_min_pt", c_baseline_min_pt = 10e3);
  DeclareProperty("baseline_max_pt", c_baseline_max_pt = -1);

  DeclareProperty("baseline_min_eta", c_baseline_min_eta = -1);
  DeclareProperty("baseline_max_eta", c_baseline_max_eta = 2.47);

  DeclareProperty("signal_min_d0_sig", c_signal_min_d0_sig = -1);
  DeclareProperty("signal_max_d0_sig", c_signal_max_d0_sig = 5.);

  DeclareProperty("signal_min_z0_sin_theta", c_signal_min_z0_sin_theta = -1);
  DeclareProperty("signal_max_z0_sin_theta", c_signal_max_z0_sin_theta = 0.4);

  DeclareProperty("signal_min_ptcone_cut", c_signal_min_ptcone_cut = -1);
  DeclareProperty("signal_max_ptcone_cut", c_signal_max_ptcone_cut = 0.16);

  DeclareProperty("signal_min_etcone_cut", c_signal_min_etcone_cut = -1);
  DeclareProperty("signal_max_etcone_cut", c_signal_max_etcone_cut = 0.18);

  // TODO Add flag to recalculate med++, tight++
}

// ----------------------------------------------------------------------------
SelectionTools::ElectronSelectionTool::~ElectronSelectionTool()
{
  // do nothing
}

// ----------------------------------------------------------------------------
bool SelectionTools::ElectronSelectionTool::isBaseline(Electron* el)
{
  // check for cluster seeded electron
  if (el->author() != 1 && el->author() != 3)
    return false;

  // check for electrons flagged as "BADCLUSELECTRON"
  if ((el->OQ() & egammaPID::BADCLUSELECTRON) > 0)
    return false;

  // check for medium++ electrons
  // TODO add option to recalculate med++
  if (!el->mediumPP())
    return false;

  // Check for baseline pt
  double pt = el->getTlv().Pt();
  if (!passCut(pt, c_baseline_min_pt, c_baseline_max_pt))
    return false;

  // Check for baseline eta
  double eta = fabs(el->getTlv().Eta());
  if (!passCut(eta, c_baseline_min_eta, c_baseline_max_eta))
    return false;

  // Passed all cuts. This is a baseline eleectron
  return true;
}

// ----------------------------------------------------------------------------
bool SelectionTools::ElectronSelectionTool::isSignal(Electron* el)
{
  // check for tight++ electrons
  // TODO add option to recalculate tight++
  if (!el->tightPP())
    return false;

  // check for signal d0 significance
  double d0_sig = fabs(el->getD0Significance());
  if (!passCut(d0_sig, c_signal_min_d0_sig, c_signal_max_d0_sig))
    return false;

  // check for signal z0 sin(theta)
  double z0_sin_theta = fabs(el->getZ0SinTheta());
  if (!passCut( z0_sin_theta
              , c_signal_min_z0_sin_theta
              , c_signal_max_z0_sin_theta
              ) )
    return false;

  // Check for signal isolation
  // TODO get proper value for num good vertices
  int num_good_vertices = 0;
  double ptcone30 = el->getIsoCorr( CommonTools::PTCONE
                                  , 30
                                  , num_good_vertices
                                  );
  double topoetcone30 = el->getIsoCorr( CommonTools::TOPOETCONE_CORR
                                      , 30
                                      , num_good_vertices
                                      );
  double pt = el->getTlv().Pt();
  double ptcone_ratio = ptcone30/pt;
  double etcone_ratio = topoetcone30/pt;

  if (!passCut(ptcone_ratio, c_signal_min_ptcone_cut, c_signal_max_ptcone_cut))
      return false;
  if (!passCut(etcone_ratio, c_signal_min_etcone_cut, c_signal_max_etcone_cut))
      return false;

  // Passed all cuts. This is a signal eleectron
  return true;
}

// ----------------------------------------------------------------------------
bool SelectionTools::ElectronSelectionTool::passCut( double test
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
