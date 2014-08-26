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
double PennSusyFrame::getDr(  const PennSusyFrame::Particle* p1
			    , const PennSusyFrame::Particle* p2
			    )
{ 
  double eta_1 = p1->getEta();
  double phi_1 = p1->getPhi();
  double eta_2 = p2->getEta();
  double phi_2 = p2->getPhi();

  double deta = fabs(eta_1 - eta_2);
  double dphi = calcDphi(phi_1, phi_2);
  return PennSusyFrame::calcDr(deta, dphi);
}

// -----------------------------------------------------------------------------
double PennSusyFrame::calcDr(double deta, double dphi) {
  double dr = sqrt(dphi*dphi + deta*deta);
  return dr;
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

// -----------------------------------------------------------------------------
double PennSusyFrame::calculateTtbarPtReweight(const PennSusyFrame::MCTruth& mc_truth)
{
  unsigned int dsid = mc_truth.getChannelNumber();
  if (dsid != 117050) return 1.;

  // Reweighting based on differential cross section measurement ATLAS-CONF-2013-099
  // to be applied to ttbar Powheg+P6+P2011C sample (117050)
  // used in strong 1l- and 1-tau and stop 0- and 1-lepton analyses
  // ttbarpt is the pt of the ttbar system ( = (top + antitop).Pt(), top and antitop being the appropriate 4-vectors) in MeV, obtained using tops/antitops with
  // status 3 from the mc truth record

  // look for top anti-top pair
  bool found_top  = false;
  bool found_atop = false;
  TLorentzVector tlv_top;
  TLorentzVector tlv_atop;

  // loop through objects in the truth record
  unsigned int num_mc_truth_objects = mc_truth.getN();
  for (unsigned int mc_it = 0; mc_it != num_mc_truth_objects; ++mc_it) {
    // get the pdgid of this objects -- skip if not a top or not status code 3
    int this_pdgid = mc_truth.getPdgId()->at(mc_it);
    if ( fabs(this_pdgid) != 6 ) continue;
    if (mc_truth.getStatus()->at(mc_it) != 3) continue;

    if (this_pdgid == 6) {
      found_top = true;
      tlv_top.SetPtEtaPhiM( mc_truth.getPt()->at( mc_it)
                          , mc_truth.getEta()->at(mc_it)
                          , mc_truth.getPhi()->at(mc_it)
                          , mc_truth.getM()->at(  mc_it)
                          );
    }
    else if (this_pdgid == -6) {
      found_atop = true;
      tlv_atop.SetPtEtaPhiM( mc_truth.getPt()->at( mc_it)
                           , mc_truth.getEta()->at(mc_it)
                           , mc_truth.getPhi()->at(mc_it)
                           , mc_truth.getM()->at(  mc_it)
                           );
    }
  }

  float weight = 1.;

  // if we found the top and anti-top, construct ttbar-pt and then weight
  if (found_top && found_atop) {
    float ttbar_pt = (tlv_top+tlv_atop).Pt();

    if (ttbar_pt/1000. < 40.)
      weight = (1./1.011850 + 1./0.994193)/2.;
    else if (ttbar_pt/1000. < 170.)
      weight = (1./1.095920 + 1./1.034480)/2.;
    else if (ttbar_pt/1000. < 340.)
      weight = (1./1.407280 + 1./1.319110)/2.;
    else
      weight = (1./1.799380 + 1./1.710780)/2.;
  }

  return weight;
}
