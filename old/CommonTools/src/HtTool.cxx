#include "CommonTools/include/HtTool.h"

#include <vector>
#include "TLorentzVector.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// -----------------------------------------------------------------------------
CommonTools::HtTool::HtTool()
{
  // do nothing
}

// -----------------------------------------------------------------------------
double CommonTools::HtTool::getHt( FLAVOR_CHANNEL flavor_channel
                                 , const std::vector<Electron*>& el
                                 , const std::vector<Muon*>& mu
                                 , const std::vector<Jet*>& jets
                                 )
{
  return (getHtJets(jets) + getHtLeptons(flavor_channel, el, mu));
}

// -----------------------------------------------------------------------------
double CommonTools::HtTool::getHtJets(const std::vector<Jet*>& jets)
{
  double ht = 0.;

  std::vector<Jet*>::const_iterator jet_it = jets.begin();
  std::vector<Jet*>::const_iterator jet_term = jets.end();
  for (; jet_it != jet_term; ++jet_it) {
    ht += (*jet_it)->getTlv().Mag();
  }

  return ht;
}

// -----------------------------------------------------------------------------
double CommonTools::HtTool::getHtLeptons( FLAVOR_CHANNEL flavor_channel
                                        , const std::vector<Electron*>& el
                                        , const std::vector<Muon*>& mu
                                        )
{
  double ht = 0.;

  if (flavor_channel == FLAVOR_EE) {
    ht += el.at(0)->getTlv().Mag();
    ht += el.at(1)->getTlv().Mag();
  }
  else if (flavor_channel == FLAVOR_MM) {
    ht += mu.at(0)->getTlv().Mag();
    ht += mu.at(1)->getTlv().Mag();
  }
  else if (flavor_channel == FLAVOR_EM) {
    ht += el.at(0)->getTlv().Mag();
    ht += mu.at(0)->getTlv().Mag();
  }

  return ht;
}
