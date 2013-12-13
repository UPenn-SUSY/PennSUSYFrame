#include "CommonTools/include/MTTool.h"

#include "TLorentzVector.h"
#include "SusyAnalysisTools/include/SusyEnums.h"
#include "AtlasSFrameUtils/include/Electron.h"
#include "AtlasSFrameUtils/include/Muon.h"
#include "AtlasSFrameUtils/include/Met.h"

CommonTools::MTTool::MTTool()
{
  // do nothing
}

// ---------------------------------------------------------------------------
double CommonTools::MTTool::getMt(const Electron* el, const Met* met)
{
  return calcMt(el->getTlv(), met->getMetRefFinalVec());
}

// ---------------------------------------------------------------------------
double CommonTools::MTTool::getMt(const Muon* mu, const Met* met)
{
  return calcMt(mu->getTlv(), met->getMetRefFinalVec());
}

// -----------------------------------------------------------------------------
double CommonTools::MTTool::getMt( FLAVOR_CHANNEL flavor_channel
                                 , const Met* met
                                 , const std::vector<Electron*>& el
                                 , const std::vector<Muon*>& mu
                                 )
{
  double mt = 0.;

  if (flavor_channel == FLAVOR_EE) {
    TLorentzVector tlv = ( el.at(0)->getTlv()
                         + el.at(1)->getTlv()
                         );
    mt = calcMt( tlv
               , met->getMetRefFinalVec()
               );
  }
  else if (flavor_channel == FLAVOR_MM) {
    TLorentzVector tlv = ( mu.at(0)->getTlv()
                         + mu.at(1)->getTlv()
                         );
    mt = calcMt( tlv
               , met->getMetRefFinalVec()
               );
  }
  else if (flavor_channel == FLAVOR_EM) {
    TLorentzVector tlv = ( el.at(0)->getTlv()
                         + mu.at(0)->getTlv()
                         );
    mt = calcMt( tlv
               , met->getMetRefFinalVec()
               );
  }

  return mt;
}

// -----------------------------------------------------------------------------
double CommonTools::MTTool::calcMt( const TLorentzVector tlv
                                  , const TVector2 met_vec
                                  )
{
  float delta_phi = TVector2::Phi_mpi_pi(met_vec.Phi() - tlv.Phi());
  double mt = sqrt( 2*tlv.Pt()*met_vec.Mod()*(1-cos( delta_phi)));
  return mt;
}
