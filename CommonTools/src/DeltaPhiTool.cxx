#include "CommonTools/include/DeltaPhiTool.h"

#include <vector>

#include "CommonTools/include/PhillTool.h"

#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/Jet.h"
#include "AtlasSFrameUtils/include/Met.h"

//_____________________________________________________________________________
CommonTools::DeltaPhiTool::DeltaPhiTool()
{
  // do nothing
}

// -----------------------------------------------------------------------------
double CommonTools::DeltaPhiTool::getDeltaPhi( FLAVOR_CHANNEL flavor_channel
                                             , const std::vector<Electron*>& el
                                             , const std::vector<Muon*>& mu
                                             , const Jet* jet
                                             )
{
  double ll_phi = PhillTool::getPhill(flavor_channel, el, mu);
  double dphi = jet->getTlv().Phi();
  dphi = fabs(TVector2::Phi_mpi_pi(dphi));

  return dphi;
}

// -----------------------------------------------------------------------------
double CommonTools::DeltaPhiTool::getDeltaPhi( FLAVOR_CHANNEL flavor_channel
                                             , const std::vector<Electron*>& el
                                             , const std::vector<Muon*>& mu
                                             , const Met* met
                                             )
{
  double ll_phi = PhillTool::getPhill(flavor_channel, el, mu);
  double dphi = met->getMetRefFinalPhi();
  dphi = fabs(TVector2::Phi_mpi_pi(dphi));

  return dphi;
}
