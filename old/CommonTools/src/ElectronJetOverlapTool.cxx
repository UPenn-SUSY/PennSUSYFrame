#include "CommonTools/include/ElectronJetOverlapTool.h"

#include "TLorentzVector.h"
#include "SusyAnalysisTools/include/SusyEnums.h"
#include "AtlasSFrameUtils/include/JetContainer.h"
#include "AtlasSFrameUtils/include/Met.h"

CommonTools::ElectronJetOverlapTool::ElectronJetOverlapTool()
{
  // do nothing
}

// -----------------------------------------------------------------------------
double CommonTools::ElectronJetOverlapTool::getSumPtJets(
    const JetContainer* jets)
{
  std::vector<Jet*> all_jets = jets->getJets(JET_ALL);
  double jet_px = 0.;
  double jet_py = 0.;

  size_t num_jets = all_jets.size();
  for (size_t jet_it = 0; jet_it != num_jets; ++jet_it) {
    jet_px += all_jets.at(jet_it)->getTlv().Px();
    jet_py += all_jets.at(jet_it)->getTlv().Py();
  }

  return sqrt( jet_px*jet_px
             + jet_py*jet_py
             );
}

// -----------------------------------------------------------------------------
double CommonTools::ElectronJetOverlapTool::getOLJet(
    const Met* met, const JetContainer* jets)
{
  double met_refjet_x = met->RefJet_etx();
  double met_refjet_y = met->RefJet_ety();

  std::vector<Jet*> all_jets = jets->getJets(JET_ALL);
  double jet_px = 0.;
  double jet_py = 0.;

  size_t num_jets = all_jets.size();
  for (size_t jet_it = 0; jet_it != num_jets; ++jet_it) {
    jet_px += all_jets.at(jet_it)->getTlv().Px();
    jet_py += all_jets.at(jet_it)->getTlv().Py();
  }

  return sqrt( met_refjet_x*met_refjet_x
             + met_refjet_y*met_refjet_y
             + jet_px*jet_px
             + jet_py*jet_py
             );
}

// -----------------------------------------------------------------------------
double CommonTools::ElectronJetOverlapTool::getOLRatio(
    const Met* met, const JetContainer* jets)
{
  return getOLJet(met, jets)/met->RefEle_sumet();
}
