#include "SelectionTools/include/ElectronSelectionTool.h"

#include <math.h>
#include <vector>

#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/ElectronContainer.h"
#include "AtlasSFrameUtils/include/ToolBase.h"
#include "AtlasSFrameUtils/include/VertexContainer.h"

#include "egammaAnalysisUtils/IsEMPlusPlusDefs.h"
#include "egammaEvent/egammaPIDdefs.h"


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

// -----------------------------------------------------------------------------
void SelectionTools::ElectronSelectionTool::process(
    Electron* el, const VertexContainer& vertices)
{
  SusyAnalysisTools::ElectronDescription* el_desc = el->getElectronDesc();

  // check for cluster seeded electron
  bool pass_clus_seed = (!(el->author() != 1 && el->author() != 3));
  el_desc->setPassClusterSeed(pass_clus_seed);

  // check for electrons flagged as "BADCLUSELECTRON"
  bool pass_otx = (!((el->OQ() & egammaPID::BADCLUSELECTRON) > 0));
  el_desc->setPassOtx(pass_otx);

  // check for medium++ electrons
  // TODO add option to recalculate med++
  bool pass_med_pp = el->mediumPP();
  el_desc->setPassMediumPP(pass_med_pp);

  // Check for baseline pt
  double pt = el->getTlv().Pt();
  bool pass_baseline_pt = passCut(pt, c_baseline_min_pt, c_baseline_max_pt);
  el_desc->setPassBaselinePt(pass_baseline_pt);

  // Check for baseline eta
  // double eta = fabs(el->getTlv().Eta());
  double eta = fabs(el->cl_eta());
  // double eta = fabs(el->cl_etas2());
  bool pass_baseline_eta = passCut(eta, c_baseline_min_eta, c_baseline_max_eta);
  el_desc->setPassBaselineEta(pass_baseline_eta);

  // check for tight++ electrons
  // TODO add option to recalculate tight++
  bool pass_tight_pp = el->tightPP();
  el_desc->setPassTightPP(pass_tight_pp);

  // check for signal d0 significance
  double d0_sig = fabs(el->getD0Significance());
  bool pass_d0_sig = passCut(d0_sig, c_signal_min_d0_sig, c_signal_max_d0_sig);
  el_desc->setPassD0Sig(pass_d0_sig);

  // check for signal z0 sin(theta)
  double z0_sin_theta = fabs(el->getZ0SinTheta());
  bool pass_z0_sin_theta = passCut( z0_sin_theta
                                  , c_signal_min_z0_sin_theta
                                  , c_signal_max_z0_sin_theta
                                  );
  el_desc->setPassZ0SinTheta(pass_z0_sin_theta);

  // Check for signal isolation
  int num_good_vertices = vertices.num(VERT_GOOD);
  double ptcone30 = el->getIsoCorr( PTCONE
                                  , 30
                                  , num_good_vertices
                                  );
  double topoetcone30 = el->getIsoCorr( TOPOETCONE_CORR
                                      , 30
                                      , num_good_vertices
                                      );
  double ptcone_ratio = ptcone30/pt;
  double etcone_ratio = topoetcone30/pt;

  bool pass_ptcone = passCut( ptcone_ratio
                            , c_signal_min_ptcone_cut
                            , c_signal_max_ptcone_cut
                            );
  el_desc->setPassPtIso(pass_ptcone);

  bool pass_etcone = passCut( etcone_ratio
                            , c_signal_min_etcone_cut
                            , c_signal_max_etcone_cut
                            );
  el_desc->setPassCaloIso(pass_etcone);


  //Check for Crack Electrons

  bool is_in_crack = isInCrack(el);
  el_desc->setIsInCrack(is_in_crack);
}

// ----------------------------------------------------------------------------
bool SelectionTools::ElectronSelectionTool::isBaseline(Electron* el)
{
  // Check if this electron passed all baseline cuts
  SusyAnalysisTools::ElectronDescription* el_desc = el->getElectronDesc();
  bool pass_baseline = (  el_desc->getPassClusterSeed()
                       && el_desc->getPassOtx()
                       && el_desc->getPassMediumPP()
                       && el_desc->getPassBaselinePt()
                       && el_desc->getPassBaselineEta()
                       );
  el_desc->setPassBaseline(pass_baseline);

  return pass_baseline;
}

// ----------------------------------------------------------------------------
bool SelectionTools::ElectronSelectionTool::isSignal(Electron* el)
{
  // check if this electron passed all signal cuts
  SusyAnalysisTools::ElectronDescription* el_desc = el->getElectronDesc();
  bool pass_signal = (  el_desc->getPassTightPP()
                     && el_desc->getPassD0Sig()
                     && el_desc->getPassZ0SinTheta()
                     && el_desc->getPassPtIso()
                     && el_desc->getPassCaloIso()
                     );
  el_desc->setPassSignal(pass_signal);

  return pass_signal;
}

// ----------------------------------------------------------------------------
std::vector<Electron*>
    SelectionTools::ElectronSelectionTool::getBaselineElectrons(
        const ElectronContainer& electron_container)
{
  const std::vector<Electron*> all_electrons =
    electron_container.getElectrons(EL_ALL);
  return getBaselineElectrons(all_electrons);
}

// ----------------------------------------------------------------------------
std::vector<Electron*>
    SelectionTools::ElectronSelectionTool::getBaselineElectrons(
        const std::vector<Electron*>& all_electrons)
{
  size_t term = all_electrons.size();

  std::vector<Electron*> baseline_electrons;
  baseline_electrons.reserve(term);

  for (size_t el_it = 0; el_it != term; ++el_it) {
    if (isBaseline(all_electrons.at(el_it))) {
      baseline_electrons.push_back(all_electrons.at(el_it));
    }
  }

  return baseline_electrons;
}

// ----------------------------------------------------------------------------
std::vector<Electron*>
    SelectionTools::ElectronSelectionTool::getSignalElectrons(
        const ElectronContainer& electron_container)
{
  const std::vector<Electron*> good_electrons =
    electron_container.getElectrons(EL_GOOD);
  return getSignalElectrons(good_electrons);
}

// ----------------------------------------------------------------------------
std::vector<Electron*>
    SelectionTools::ElectronSelectionTool::getSignalElectrons(
        const std::vector<Electron*>& good_electrons)
{
  size_t term = good_electrons.size();

  std::vector<Electron*> signal_electrons;
  signal_electrons.reserve(term);

  for (size_t el_it = 0; el_it != term; ++el_it) {
    if (isSignal(good_electrons.at(el_it))) {
      signal_electrons.push_back(good_electrons.at(el_it));
    }
  }

  return signal_electrons;
}
// ----------------------------------------------------------------------------
bool SelectionTools::ElectronSelectionTool::isInCrack(Electron *el)
{

  double crack_eta_min = 1.37;
  double crack_eta_max = 1.52;

  return passCut(fabs(el->cl_eta()), crack_eta_min, crack_eta_min);

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
