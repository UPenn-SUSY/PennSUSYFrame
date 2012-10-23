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
  // Check that jet is not bad
  if (isBadJet(jet))
    return false;

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
std::vector<Jet*>
    SelectionTools::JetSelectionTool::getBaselineJets(
        const JetContainer& jet_container)
{
  const std::vector<Jet*> all_jets =
    jet_container.getJets(JET_ALL);
  return getBaselineJets(all_jets);
}

// ----------------------------------------------------------------------------
std::vector<Jet*>
    SelectionTools::JetSelectionTool::getBaselineJets(
        const std::vector<Jet*>& all_jets)
{
  size_t term = all_jets.size();

  std::vector<Jet*> baseline_jets;
  baseline_jets.reserve(term);

  for (size_t jet_it = 0; jet_it != term; ++jet_it) {
    if (isBaseline(all_jets.at(jet_it))) {
      baseline_jets.push_back(all_jets.at(jet_it));
    }
  }

  return baseline_jets;
}

// ----------------------------------------------------------------------------
std::vector<Jet*>
    SelectionTools::JetSelectionTool::getLJets(
        const JetContainer& jet_container)
{
  const std::vector<Jet*> good_jets =
    jet_container.getJets(JET_GOOD);
  return getLJets(good_jets);
}

// ----------------------------------------------------------------------------
std::vector<Jet*>
    SelectionTools::JetSelectionTool::getLJets(
        const std::vector<Jet*>& good_jets)
{
  size_t term = good_jets.size();

  std::vector<Jet*> l_jets;
  l_jets.reserve(term);

  for (size_t jet_it = 0; jet_it != term; ++jet_it) {
    if (isLJet(good_jets.at(jet_it))) {
      l_jets.push_back(good_jets.at(jet_it));
    }
  }

  return l_jets;
}

// ----------------------------------------------------------------------------
std::vector<Jet*>
    SelectionTools::JetSelectionTool::getBJets(
        const JetContainer& jet_container)
{
  const std::vector<Jet*> good_jets =
    jet_container.getJets(JET_GOOD);
  return getBJets(good_jets);
}

// ----------------------------------------------------------------------------
std::vector<Jet*>
    SelectionTools::JetSelectionTool::getBJets(
        const std::vector<Jet*>& good_jets)
{
  size_t term = good_jets.size();

  std::vector<Jet*> b_jets;
  b_jets.reserve(term);

  for (size_t jet_it = 0; jet_it != term; ++jet_it) {
    if (isBJet(good_jets.at(jet_it))) {
      b_jets.push_back(good_jets.at(jet_it));
    }
  }

  return b_jets;
}

// ----------------------------------------------------------------------------
std::vector<Jet*>
    SelectionTools::JetSelectionTool::getFJets(
        const JetContainer& jet_container)
{
  const std::vector<Jet*> good_jets =
    jet_container.getJets(JET_GOOD);
  return getFJets(good_jets);
}

// ----------------------------------------------------------------------------
std::vector<Jet*>
    SelectionTools::JetSelectionTool::getFJets(
        const std::vector<Jet*>& good_jets)
{
  size_t term = good_jets.size();

  std::vector<Jet*> f_jets;
  f_jets.reserve(term);

  for (size_t jet_it = 0; jet_it != term; ++jet_it) {
    if (isFJet(good_jets.at(jet_it))) {
      f_jets.push_back(good_jets.at(jet_it));
    }
  }

  return f_jets;
}

// ----------------------------------------------------------------------------
std::vector<Jet*>
    SelectionTools::JetSelectionTool::getBadJets(
        const JetContainer& jet_container)
{
  const std::vector<Jet*> all_jets =
    jet_container.getJets(JET_ALL);
  return getBadJets(all_jets);
}

// ----------------------------------------------------------------------------
std::vector<Jet*>
    SelectionTools::JetSelectionTool::getBadJets(
        const std::vector<Jet*>& all_jets)
{
  size_t term = all_jets.size();

  std::vector<Jet*> bad_jets;
  bad_jets.reserve(term);

  for (size_t jet_it = 0; jet_it != term; ++jet_it) {
    if (isBadJet(all_jets.at(jet_it))) {
      bad_jets.push_back(all_jets.at(jet_it));
    }
  }

  return bad_jets;
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
