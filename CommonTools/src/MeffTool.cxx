#include "CommonTools/include/MeffTool.h"

#include <vector>
#include "TLorentzVector.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "SusyAnalysisTools/include/SusyEnums.h"

// -----------------------------------------------------------------------------
CommonTools::MeffTool::MeffTool()
{
  // do nothing
}

// -----------------------------------------------------------------------------
double CommonTools::MeffTool::getMeff( FLAVOR_CHANNEL flavor_channel
                                     , const std::vector<Electron*>& el
                                     , const std::vector<Muon*>& mu
                                     , const std::vector<Jet*>& jets
                                     )
{
  TLorentzVector full_reco;

  std::vector<Jet*>::const_iterator jet_it = jets.begin();
  std::vector<Jet*>::const_iterator jet_term = jets.end();
  for (; jet_it != jet_term; ++jet_it) {
    full_reco += (*jet_it)->getTlv();
  }

  if (flavor_channel == FLAVOR_EE) {
    full_reco += el.at(0)->getTlv();
    full_reco += el.at(1)->getTlv();
  }
  else if (flavor_channel == FLAVOR_MM) {
    full_reco += mu.at(0)->getTlv();
    full_reco += mu.at(1)->getTlv();
  }
  else if (flavor_channel == FLAVOR_EM) {
    full_reco += el.at(0)->getTlv();
    full_reco += mu.at(0)->getTlv();
  }

  return full_reco.Mag();
}

// -----------------------------------------------------------------------------
double CommonTools::MeffTool::getMeffJets( FLAVOR_CHANNEL flavor_channel
                                         , const std::vector<Jet*>& jets
                                         )
{
  TLorentzVector full_reco;

  std::vector<Jet*>::const_iterator jet_it = jets.begin();
  std::vector<Jet*>::const_iterator jet_term = jets.end();
  for (; jet_it != jet_term; ++jet_it) {
    full_reco += (*jet_it)->getTlv();
  }

  return full_reco.Mag();
}

// -----------------------------------------------------------------------------
double CommonTools::MeffTool::getMeffLeptons( FLAVOR_CHANNEL flavor_channel
                                            , const std::vector<Electron*>& el
                                            , const std::vector<Muon*>& mu
                                            )
{
  TLorentzVector full_reco;

  if (flavor_channel == FLAVOR_EE) {
    full_reco += el.at(0)->getTlv();
    full_reco += el.at(1)->getTlv();
  }
  else if (flavor_channel == FLAVOR_MM) {
    full_reco += mu.at(0)->getTlv();
    full_reco += mu.at(1)->getTlv();
  }
  else if (flavor_channel == FLAVOR_EM) {
    full_reco += el.at(0)->getTlv();
    full_reco += mu.at(0)->getTlv();
  }

  return full_reco.Mag();
}
