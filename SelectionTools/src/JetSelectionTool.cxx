#include <math.h>
#include "include/JetSelectionTool.h"

// -----------------------------------------------------------------------------
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

// -----------------------------------------------------------------------------
SelectionTools::JetSelectionTool::~JetSelectionTool()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void SelectionTools::JetSelectionTool::process(Jet* jet)
{
  SusyAnalysisTools::JetDescription* jet_desc = jet->getJetDesc();

  double pt = jet->getTlv().Pt();
  double eta = fabs(jet->getTlv().Eta());

  // Check for baseline pt
  bool pass_baseline_pt = passCut(pt, c_baseline_min_pt, c_baseline_max_pt);
  jet_desc->setPassBaselinePt(pass_baseline_pt);

  // Check for baseline eta
  bool pass_baseline_eta = passCut(eta, c_baseline_min_eta, c_baseline_max_eta);
  jet_desc->setPassBaselineEta(pass_baseline_eta);

  // Check for light pt
  bool pass_l_pt = passCut(pt, c_light_min_pt, c_light_max_pt);
  jet_desc->setPassLPt(pass_l_pt);

  // Check for b pt
  bool pass_b_pt = passCut(pt, c_b_min_pt, c_b_max_pt);
  jet_desc->setPassBPt(pass_b_pt);

  // Check for forward pt
  bool pass_f_pt = passCut(pt, c_forward_min_pt, c_forward_max_pt);
  jet_desc->setPassFPt(pass_f_pt);

  // Check for central eta
  bool pass_central_eta = passCut(eta, c_light_min_eta, c_light_max_eta);
  jet_desc->setPassCentralEta(pass_central_eta);

  // Check for forward eta
  bool pass_forward_eta = passCut(eta, c_forward_min_eta, c_forward_max_eta);
  jet_desc->setPassFEta(pass_forward_eta);

  // Check for light jvf
  double jvf = jet->jvtxf();
  bool pass_jvf = passCut(jvf, c_light_min_jvf, c_light_max_jvf);
  jet_desc->setPassJvf(pass_jvf);

  // Check mv1 for b-tag
  double mv1 = jet->flavor_weight_MV1();
  bool pass_b_tag = passCut(mv1, c_b_min_mv1, c_b_max_mv1);
  jet_desc->setPassBTag(pass_b_tag);
}

// -----------------------------------------------------------------------------
bool SelectionTools::JetSelectionTool::isBaselineGood(Jet* jet)
{
  // Check if this jet passed all baseline cuts
  SusyAnalysisTools::JetDescription* jet_desc = jet->getJetDesc();
  bool pass_baseline_good = (  jet_desc->getPassBaselinePt()
                            && jet_desc->getPassBaselineEta()
                            && !isBadJet(jet)
                            );
  jet_desc->setPassBaselineGood(pass_baseline_good);

  return pass_baseline_good;
}

// -----------------------------------------------------------------------------
bool SelectionTools::JetSelectionTool::isBaselineBad(Jet* jet)
{
  // Check if this jet passed all baseline cuts
  SusyAnalysisTools::JetDescription* jet_desc = jet->getJetDesc();
  bool pass_baseline_bad = (  jet_desc->getPassBaselinePt()
                           && jet_desc->getPassBaselineEta()
                           && isBadJet(jet)
                           );
  jet_desc->setPassBaselineBad(pass_baseline_bad);

  return pass_baseline_bad;
}

// -----------------------------------------------------------------------------
bool SelectionTools::JetSelectionTool::isLJet(Jet* jet)
{
  // Check if this jet passed all light jet cuts
  SusyAnalysisTools::JetDescription* jet_desc = jet->getJetDesc();
  bool pass_light = (  jet_desc->getPassLPt()
                    && jet_desc->getPassCentralEta()
                    && jet_desc->getPassJvf()
                    && (jet_desc->getPassBTag() == false)
                    );
  jet_desc->setPassLight(pass_light);
  return pass_light;
}

// -----------------------------------------------------------------------------
bool SelectionTools::JetSelectionTool::isBJet(Jet* jet)
{
  // Check if this jet passed all b jet cuts
  SusyAnalysisTools::JetDescription* jet_desc = jet->getJetDesc();
  bool pass_b = (  jet_desc->getPassBPt()
                && jet_desc->getPassCentralEta()
                && jet_desc->getPassBTag()
                );
  jet_desc->setPassB(pass_b);
  return pass_b;
}

// -----------------------------------------------------------------------------
bool SelectionTools::JetSelectionTool::isFJet(Jet* jet)
{
  // Check if this jet passed all forward jet cuts
  SusyAnalysisTools::JetDescription* jet_desc = jet->getJetDesc();
  bool pass_forward = (  jet_desc->getPassFPt()
                      && jet_desc->getPassFEta()
                      );
  jet_desc->setPassForward(pass_forward);
  return pass_forward;
}

// -----------------------------------------------------------------------------
bool SelectionTools::JetSelectionTool::isBadJet(Jet* jet)
{
  double emf  = jet->emfrac();
  double eta  = jet->emscale_eta();
  double chf  = jet->sumPtTrk()/jet->getTlv().Pt();
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

// -----------------------------------------------------------------------------
std::vector<Jet*> SelectionTools::JetSelectionTool::getBaselineGoodJets(
    const JetContainer& jet_container)
{
  const std::vector<Jet*> all_jets = jet_container.getJets(JET_ALL);
  return getBaselineGoodJets(all_jets);
}

// -----------------------------------------------------------------------------
std::vector<Jet*> SelectionTools::JetSelectionTool::getBaselineGoodJets(
    const std::vector<Jet*>& all_jets)
{
  size_t term = all_jets.size();

  std::vector<Jet*> baseline_jets;
  baseline_jets.reserve(term);

  for (size_t jet_it = 0; jet_it != term; ++jet_it) {
    if (isBaselineGood(all_jets.at(jet_it))) {
      baseline_jets.push_back(all_jets.at(jet_it));
    }
  }

  return baseline_jets;
}

// -----------------------------------------------------------------------------
std::vector<Jet*> SelectionTools::JetSelectionTool::getBaselineBadJets(
    const JetContainer& jet_container)
{
  const std::vector<Jet*> all_jets = jet_container.getJets(JET_ALL);
  return getBaselineBadJets(all_jets);
}

// -----------------------------------------------------------------------------
std::vector<Jet*> SelectionTools::JetSelectionTool::getBaselineBadJets(
    const std::vector<Jet*>& all_jets)
{
  size_t term = all_jets.size();

  std::vector<Jet*> baseline_jets;
  baseline_jets.reserve(term);

  for (size_t jet_it = 0; jet_it != term; ++jet_it) {
    if (isBaselineBad(all_jets.at(jet_it))) {
      baseline_jets.push_back(all_jets.at(jet_it));
    }
  }

  return baseline_jets;
}

// -----------------------------------------------------------------------------
std::vector<Jet*> SelectionTools::JetSelectionTool::getLJets(
    const JetContainer& jet_container)
{
  const std::vector<Jet*> good_jets = jet_container.getJets(JET_GOOD);
  return getLJets(good_jets);
}

// -----------------------------------------------------------------------------
std::vector<Jet*> SelectionTools::JetSelectionTool::getLJets(
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

// -----------------------------------------------------------------------------
std::vector<Jet*> SelectionTools::JetSelectionTool::getBJets(
    const JetContainer& jet_container)
{
  const std::vector<Jet*> good_jets =
    jet_container.getJets(JET_GOOD);
  return getBJets(good_jets);
}

// -----------------------------------------------------------------------------
std::vector<Jet*> SelectionTools::JetSelectionTool::getBJets(
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

// -----------------------------------------------------------------------------
std::vector<Jet*> SelectionTools::JetSelectionTool::getFJets(
    const JetContainer& jet_container)
{
  const std::vector<Jet*> good_jets =
    jet_container.getJets(JET_GOOD);
  return getFJets(good_jets);
}

// -----------------------------------------------------------------------------
std::vector<Jet*> SelectionTools::JetSelectionTool::getFJets(
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

// -----------------------------------------------------------------------------
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
