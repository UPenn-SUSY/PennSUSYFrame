#include <math.h>
#include "include/JetSelectionTool.h"

// ----------------------------------------------------------------------------
SelectionTools::JetSelectionTool::JetSelectionTool(
    SCycleBase* parent, const char* name): ToolBase(parent, name)
{
  DeclareProperty("baseline_min_pt", c_baseline_min_pt = 20e3);
  DeclareProperty("baseline_max_pt", c_baseline_max_pt = -1);

  DeclareProperty("baseline_min_eta", c_baseline_min_eta = -1);
  DeclareProperty("baseline_max_eta", c_baseline_max_eta = 4.9);

  DeclareProperty("c_light_min_pt", c_light_min_pt = 25e3);
  DeclareProperty("c_light_max_pt", c_light_max_pt = -1);

  DeclareProperty("c_light_min_eta", c_light_min_eta = -1);
  DeclareProperty("c_light_max_eta", c_light_max_eta = 2.5);

  DeclareProperty("c_light_min_jvf", c_light_min_jvf = 0.2);
  DeclareProperty("c_light_max_jvf", c_light_max_jvf = -1);

  DeclareProperty("c_light_min_mv1", c_light_min_mv1 = -1);
  DeclareProperty("c_light_max_mv1", c_light_max_mv1 = 0.122);

  DeclareProperty("c_b_min_pt", c_b_min_pt = 20e3);
  DeclareProperty("c_b_max_pt", c_b_max_pt = -1);

  DeclareProperty("c_b_min_eta", c_b_min_eta = -1);
  DeclareProperty("c_b_max_eta", c_b_max_eta = 2.5);

  DeclareProperty("c_b_min_mv1", c_b_min_mv1 = 0.122);
  DeclareProperty("c_b_max_mv1", c_b_max_mv1 = -1);

  DeclareProperty("c_forward_min_pt", c_forward_min_pt = 30e3);
  DeclareProperty("c_forward_max_pt", c_forward_max_pt = -1);

  DeclareProperty("c_forward_min_eta", c_forward_min_eta = 2.5);
  DeclareProperty("c_forward_max_eta", c_forward_max_eta = 4.9);
}

// ----------------------------------------------------------------------------
SelectionTools::JetSelectionTool::~JetSelectionTool()
{
  // do nothing
}

// ----------------------------------------------------------------------------
bool SelectionTools::JetSelectionTool::isBaseline(Jet* jet)
{
  // Check for baseline pt
  double pt = jet->getTlv().Pt();
  if (!passCut(pt, c_baseline_min_pt, c_baseline_max_pt))
    return false;

  // Check for baseline eta
  double eta = fabs(jet->getTlv().Eta());
  if (!passCut(eta, c_baseline_min_eta, c_baseline_max_eta))
    return false;

  // Passed all cuts. This is a baseline jet
  return true;
}

// ----------------------------------------------------------------------------
bool SelectionTools::JetSelectionTool::isLJet(Jet* jet)
{
  // Check for light pt
  double pt = jet->getTlv().Pt();
  if (!passCut(pt, c_light_min_pt, c_light_max_pt))
    return false;

  // Check for light eta
  double eta = fabs(jet->getTlv().Eta());
  if (!passCut(eta, c_light_min_eta, c_light_max_eta))
    return false;

  // Check for light jvf
  double jvf = jet->jvtxf();
  if (!passCut(jvf, c_light_min_jvf, c_light_max_jvf))
    return false;

  // Check for light mv1
  double mv1 = jet->flavor_weight_MV1();
  if (!passCut(mv1, c_light_min_mv1, c_light_max_mv1))
    return false;

  // Passed all cuts. This is a light-central jet
  return true;
}

// ----------------------------------------------------------------------------
bool SelectionTools::JetSelectionTool::isBJet(Jet* jet)
{
  // Check for b pt
  double pt = jet->getTlv().Pt();
  if (!passCut(pt, c_b_min_pt, c_b_max_pt))
    return false;

  // Check for b eta
  double eta = fabs(jet->getTlv().Eta());
  if (!passCut(eta, c_b_min_eta, c_b_max_eta))
    return false;

  // Check for b mv1
  double mv1 = jet->flavor_weight_MV1();
  if (!passCut(mv1, c_b_min_mv1, c_b_max_mv1))
    return false;

  // Passed all cuts. This is a b-jet
  return true;
}

// ----------------------------------------------------------------------------
bool SelectionTools::JetSelectionTool::isFJet(Jet* jet)
{
  // Check for forward pt
  double pt = jet->getTlv().Pt();
  if (!passCut(pt, c_forward_min_pt, c_forward_max_pt))
    return false;

  // Check for forward eta
  double eta = fabs(jet->getTlv().Eta());
  if (!passCut(eta, c_forward_min_eta, c_forward_max_eta))
    return false;

  // Passed all cuts. This is a forward jet
  return true;
}

// ----------------------------------------------------------------------------
bool SelectionTools::JetSelectionTool::isBadJet(Jet* jet)
{
  double emf = jet->emfrac();
  double eta = jet->emscale_eta();
  double chf = jet->sumPtTrk()/jet->getTlv().Pt();
  double fmax = jet->fracSamplingMax();

  // non-collision background & cosmics
  if (emf  < 0.05 && fabs(eta) >= 2)               return true;
  if (fmax > 0.99 && fabs(eta) <  2)               return true;
  if (emf  < 0.05 && fabs(eta) <  2 && chf < 0.05) return true;

  // HEC spikes
  if (fabs(jet->NegativeE()) > 60000) return true;
  if (  jet->hecf() > 0.5
     && fabs(jet->HECQuality()) > 0.5
     && jet->AverageLArQF()/65535. >= 0.8
     )
    return true;

  // EM coherent noise
  if (  emf > 0.95
     && fabs(jet->LArQuality()) > 0.8
     && fabs(eta) < 2.8
     && jet->AverageLArQF()/65535. >= 0.8
     )
    return true;

  // do not flag this as a bad jet
  return false;
}

// ----------------------------------------------------------------------------
bool SelectionTools::JetSelectionTool::passCut( double test
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
