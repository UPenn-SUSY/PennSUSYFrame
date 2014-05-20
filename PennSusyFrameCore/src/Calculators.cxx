#include "PennSusyFrameCore/include/Calculators.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"

#include <vector>

// =============================================================================
static const double PI = 3.14159265359;

// -----------------------------------------------------------------------------
// mll calculator
double PennSusyFrame::getMll( FLAVOR_CHANNEL flavor_channel
                            , const std::vector<PennSusyFrame::Electron*>* el
                            , const std::vector<PennSusyFrame::Muon*>* mu
                            )
{
  double mll = 0.;

  if (flavor_channel == FLAVOR_EE) {
    mll = calcMll(el->at(0), el->at(1));
  }
  else if (flavor_channel == FLAVOR_MM) {
    mll = calcMll(mu->at(0), mu->at(1));
  }
  else if (flavor_channel == FLAVOR_EM) {
    mll = calcMll(el->at(0), mu->at(0));
  }

  return mll;
}

// -----------------------------------------------------------------------------
// ptll calculator
double PennSusyFrame::getPtll( FLAVOR_CHANNEL flavor_channel
                             , const std::vector<PennSusyFrame::Electron*>* el
                             , const std::vector<PennSusyFrame::Muon*>* mu
                             )
{
  double ptll = 0.;

  if (flavor_channel == FLAVOR_EE) {
    ptll = calcPtll(el->at(0), el->at(1));
  }
  else if (flavor_channel == FLAVOR_MM) {
    ptll = calcPtll(mu->at(0), mu->at(1));
  }
  else if (flavor_channel == FLAVOR_EM) {
    ptll = calcPtll(el->at(0), mu->at(0));
  }

  return ptll;
}

// -----------------------------------------------------------------------------
// mt2 calculator
double PennSusyFrame::getMt2( FLAVOR_CHANNEL flavor_channel
                            , const PennSusyFrame::Met* met
                            , const std::vector<PennSusyFrame::Electron*>* el
                            , const std::vector<PennSusyFrame::Muon*>* mu
                            , double minv
                            )
{
  double mt2 = 0.;

  if (flavor_channel == FLAVOR_EE) {
    mt2 = calcMt2( el->at(0)
                 , el->at(1)
                 , met
                 , minv
                 );
  }
  else if (flavor_channel == FLAVOR_MM) {
    mt2 = calcMt2( mu->at(0)
                 , mu->at(1)
                 , met
                 , minv
                 );
  }
  else if (flavor_channel == FLAVOR_EM) {
    mt2 = calcMt2( el->at(0)
                 , mu->at(0)
                 , met
                 , minv
                 );
  }

  return mt2;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::getDphill( FLAVOR_CHANNEL flavor_channel
                               , const std::vector<PennSusyFrame::Electron*>* el
                               , const std::vector<PennSusyFrame::Muon*>* mu
                               )
{
  if (flavor_channel == FLAVOR_NONE)
    return 0.;

  if (flavor_channel == FLAVOR_EE) {
    return PennSusyFrame::calcDphi( el->at(0)->getPhi()
                                  , el->at(1)->getPhi()
                                  );
  }
  else if (flavor_channel == FLAVOR_MM) {
    return PennSusyFrame::calcDphi( mu->at(0)->getPhi()
                                  , mu->at(1)->getPhi()
                                  );
  }
  else if (flavor_channel == FLAVOR_EM) {
    return PennSusyFrame::calcDphi( el->at(0)->getPhi()
                                  , mu->at(0)->getPhi()
                                  );
  }

  return 0;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::calcDphi(double phi_0, double phi_1) {
  phi_0 = TVector2::Phi_0_2pi(phi_0);
  phi_1 = TVector2::Phi_0_2pi(phi_1);

  double dphi = fabs(TVector2::Phi_mpi_pi(phi_0 - phi_1));

  return dphi;
}

// -----------------------------------------------------------------------------
double PennSusyFrame::getEmmaMt( FLAVOR_CHANNEL flavor_channel
                               , const std::vector<PennSusyFrame::Electron*>* el
                               , const std::vector<PennSusyFrame::Muon*>* mu
                               )
{
  if (flavor_channel == FLAVOR_NONE)
    return 0.;

  return ( std::sqrt( std::pow(getMll( flavor_channel, el, mu), 2)
                    + std::pow(getPtll(flavor_channel, el, mu), 2)
                    )
         );
}

// ------------------------------------------------------------------------------
double PennSusyFrame::getHt( const std::vector<PennSusyFrame::Electron*>* el_list
                           , const std::vector<PennSusyFrame::Muon*>* mu_list
                           , const std::vector<PennSusyFrame::Jet*>* jet_list
                           )
{
  double ht = 0;

  size_t num_el = el_list->size();
  for (size_t el_it = 0; el_it != num_el; ++el_it) {
    ht += el_list->at(el_it)->getPt();
  }

  size_t num_mu = mu_list->size();
  for (size_t mu_it = 0; mu_it != num_mu; ++mu_it) {
    ht += mu_list->at(mu_it)->getPt();
  }

  size_t num_jet = jet_list->size();
  for (size_t jet_it = 0; jet_it != num_jet; ++jet_it) {
    ht += jet_list->at(jet_it)->getPt();
  }

  return ht;
}
