#include "OptimizeIsolation/include/OptimizeIsolation.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <math.h>

#include <TCanvas.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TH2.h>
#include <TROOT.h>
#include <TStyle.h>

#include "NtupleLooper/include/NtupleLooper.h"

#include "SusyAnalysisTools/include/EventDescription.h"
#include "SusyAnalysisTools/include/SRHelper.h"
#include "SusyAnalysisTools/include/SusyEnums.h"
#include "SusyAnalysisTools/include/ElectronDescription.h"
#include "SusyAnalysisTools/include/MuonDescription.h"

// -----------------------------------------------------------------------------
OptimizeIsolation::OptimizeIsolation( TTree *tree
                                    , double num_events
                                    ) : NtupleHelper::NtupleLooper(tree, num_events)
{
  double pt_bins[7] = {0., 10., 20., 35., 50., 75., 100.};
  double eta_bins[5] = {0.0, 0.6, 1.2, 1.8, 2.5};

  for (unsigned int iso_style = 0; iso_style != ISO_N; ++iso_style) {
    std::string iso_style_string = ISO_STYLE_STRINGS[iso_style];

    unsigned int x_bins = ( (ISO_STYLE_STRINGS[iso_style].find("ET") == std::string::npos)
                          ? 400
                          : 500
                          );
    float x_min         = ( (ISO_STYLE_STRINGS[iso_style].find("ET") == std::string::npos)
                          ? 0.
                          : -1.
                          );
    float x_max = 4;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // isolation for all reconstructed leptons
    m_el_iso.push_back( new TH1D( ("el_iso_" + iso_style_string).c_str()
                                , ("iso (" + iso_style_string + ")").c_str()
                                , x_bins, x_min, x_max
                                )
                      );
    m_mu_iso.push_back( new TH1D( ("mu_iso_" + iso_style_string).c_str()
                                , ("iso (" + iso_style_string + ")").c_str()
                                , x_bins, x_min, x_max
                                )
                      );

    // isolation for truth matched prompt leptons
    m_el_iso_prompt.push_back( new TH1D( ("el_iso_prompt_" + iso_style_string).c_str()
                                       , ("iso (" + iso_style_string + ")").c_str()
                                       , x_bins, x_min, x_max
                                       )
                             );
    m_mu_iso_prompt.push_back( new TH1D( ("mu_iso_prompt_" + iso_style_string).c_str()
                                       , ("iso (" + iso_style_string + ")").c_str()
                                       , x_bins, x_min, x_max
                                       )
                             );

    // isolation for anti-truth matched leptons
    m_el_iso_fake.push_back( new TH1D( ("el_iso_fake_" + iso_style_string).c_str()
                                     , ("iso (" + iso_style_string + ")").c_str()
                                     , x_bins, x_min, x_max
                                     )
                           );
    m_mu_iso_fake.push_back( new TH1D( ("mu_iso_fake_" + iso_style_string).c_str()
                                     , ("iso (" + iso_style_string + ")").c_str()
                                     , x_bins, x_min, x_max
                                     )
                           );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // isolation for all reconstructed leptons binned in pt
    m_el_iso_pt_bins.push_back( new TH2D( ("el_iso_pt_bins_" + iso_style_string).c_str()
                                        , ("iso (" + iso_style_string + ")").c_str()
                                        , x_bins, x_min, x_max
                                        , 6, pt_bins
                                        )
                              );
    m_mu_iso_pt_bins.push_back( new TH2D( ("mu_iso_pt_bins_" + iso_style_string).c_str()
                                        , ("iso (" + iso_style_string + ")").c_str()
                                        , x_bins, x_min, x_max
                                        , 6, pt_bins
                                        )
                              );

    // isolation for truth matched prompt leptons binned in pt
    m_el_iso_pt_bins_prompt.push_back( new TH2D( ("el_iso_pt_bins_prompt_" + iso_style_string).c_str()
                                               , ("iso (" + iso_style_string + ")").c_str()
                                               , x_bins, x_min, x_max
                                               , 6, pt_bins
                                               )
                                     );
    m_mu_iso_pt_bins_prompt.push_back( new TH2D( ("mu_iso_pt_bins_prompt_" + iso_style_string).c_str()
                                               , ("iso (" + iso_style_string + ")").c_str()
                                               , x_bins, x_min, x_max
                                               , 6, pt_bins
                                               )
                                     );

    // isolation for anti-truth matched leptons binned in pt
    m_el_iso_pt_bins_fake.push_back( new TH2D( ("el_iso_pt_bins_fake_" + iso_style_string).c_str()
                                             , ("iso (" + iso_style_string + ")").c_str()
                                             , x_bins, x_min, x_max
                                             , 6, pt_bins
                                             )
                                   );
    m_mu_iso_pt_bins_fake.push_back( new TH2D( ("mu_iso_pt_bins_fake_" + iso_style_string).c_str()
                                             , ("iso (" + iso_style_string + ")").c_str()
                                             , x_bins, x_min, x_max
                                             , 6, pt_bins
                                             )
                                   );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // isolation for all reconstructed leptons binned in eta
    m_el_iso_eta_bins.push_back( new TH2D( ("el_iso_eta_bins_" + iso_style_string).c_str()
                                         , ("iso (" + iso_style_string + ")").c_str()
                                         , x_bins, x_min, x_max
                                         , 4, eta_bins
                                         )
                               );
    m_mu_iso_eta_bins.push_back( new TH2D( ("mu_iso_eta_bins_" + iso_style_string).c_str()
                                         , ("iso (" + iso_style_string + ")").c_str()
                                         , x_bins, x_min, x_max
                                         , 4, eta_bins
                                         )
                               );

    // isolation for truth matched prompt leptons binned in eta
    m_el_iso_eta_bins_prompt.push_back( new TH2D( ("el_iso_eta_bins_prompt_" + iso_style_string).c_str()
                                                , ("iso (" + iso_style_string + ")").c_str()
                                                , x_bins, x_min, x_max
                                                , 4, eta_bins
                                                )
                                      );
    m_mu_iso_eta_bins_prompt.push_back( new TH2D( ("mu_iso_eta_bins_prompt_" + iso_style_string).c_str()
                                                , ("iso (" + iso_style_string + ")").c_str()
                                                , x_bins, x_min, x_max
                                                , 4, eta_bins
                                                )
                                      );

    // isolation for anti-truth matched leptons binned in eta
    m_el_iso_eta_bins_fake.push_back( new TH2D( ("el_iso_eta_bins_fake_" + iso_style_string).c_str()
                                              , ("iso (" + iso_style_string + ")").c_str()
                                              , x_bins, x_min, x_max
                                              , 4, eta_bins
                                              )
                                    );
    m_mu_iso_eta_bins_fake.push_back( new TH2D( ("mu_iso_eta_bins_fake_" + iso_style_string).c_str()
                                              , ("iso (" + iso_style_string + ")").c_str()
                                              , x_bins, x_min, x_max
                                              , 4, eta_bins
                                              )
                                    );
  }
}

// -----------------------------------------------------------------------------
OptimizeIsolation::~OptimizeIsolation()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void OptimizeIsolation::processEvent()
{
  SusyAnalysisTools::EventDescription evt_desc  = m_event_desc;
  double weight = 1.;

  // apply mc event weight
  weight *= m_mc_event_weight;

  // GRL
  if (evt_desc.getPassGrl() == false) return;

  // incomplete event
  if (evt_desc.getPassIncompleteEvent() == false) return;

  // lar error
  if (evt_desc.getPassLarError() == false) return;

  // tile error
  if (evt_desc.getPassTileError() == false) return;

  // tile hot spot
  if (evt_desc.getPassTileHotSpot() == false) return;

  // tile trip
  if (evt_desc.getPassTileTrip() == false) return;

  // bad jets
  if (evt_desc.getPassBadJets() == false) return;

  // calo problem jets
  if (evt_desc.getPassCaloProblemJets() == false) return;

  // primary vertex
  if (evt_desc.getPassPrimaryVertex() == false) return;

  // bad muons
  if (evt_desc.getPassBadMuons() == false) return;

  // cosmic muons
  if (evt_desc.getPassCosmicMuons() == false) return;

  // HFOR
  if (evt_desc.getPassHFOR() == false) return;


  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  double event_weight = m_pile_up_weight * m_lepton_weight;

  size_t num_el = m_el_desc->size();
  size_t num_mu = m_mu_desc->size();

  for (size_t el_it = 0; el_it != num_el; ++el_it) {
    SusyAnalysisTools::ElectronDescription el_desc(m_el_desc->at(el_it));
    bool is_truth_matched = el_desc.getPassPromptLepton();

    // get electron kinematic variables
    double el_eta = fabs(m_el_eta->at(el_it));
    double el_pt  = m_el_pt->at(el_it)/1000.;

    // special versions of pT which are allowed to be no greater than some maximum value
    double el_pt_for_2d = std::min(el_pt, 99.);
    double el_pt_capped = std::min(el_pt, 60.);

    // get isolation variables
    double el_ptcone30 = getElIsoCorr(el_it, NtupleHelper::ISO_TYPE_PTCONE    , NtupleHelper::CONE_30)/1000.;
    double el_etcone30 = getElIsoCorr(el_it, NtupleHelper::ISO_TYPE_TOPOETCONE, NtupleHelper::CONE_30)/1000.;
    double el_ptcone20 = getElIsoCorr(el_it, NtupleHelper::ISO_TYPE_PTCONE    , NtupleHelper::CONE_20)/1000.;
    double el_etcone20 = getElIsoCorr(el_it, NtupleHelper::ISO_TYPE_TOPOETCONE, NtupleHelper::CONE_20)/1000.;

    // fill basic isolation histograms
    m_el_iso.at(ISO_PTCONE30       )->Fill(el_ptcone30/el_pt       , event_weight);
    m_el_iso.at(ISO_ETCONE30       )->Fill(el_etcone30/el_pt       , event_weight);
    m_el_iso.at(ISO_PTCONE20       )->Fill(el_ptcone20/el_pt       , event_weight);
    m_el_iso.at(ISO_ETCONE20       )->Fill(el_etcone20/el_pt       , event_weight);
    m_el_iso.at(ISO_PTCONE30_CAPPED)->Fill(el_ptcone30/el_pt_capped, event_weight);
    m_el_iso.at(ISO_ETCONE30_CAPPED)->Fill(el_etcone30/el_pt_capped, event_weight);
    m_el_iso.at(ISO_PTCONE20_CAPPED)->Fill(el_ptcone20/el_pt_capped, event_weight);
    m_el_iso.at(ISO_ETCONE20_CAPPED)->Fill(el_etcone20/el_pt_capped, event_weight);

    // fill pt-binned isolation histograms
    m_el_iso_pt_bins.at(ISO_PTCONE30       )->Fill(el_ptcone30/el_pt       , el_pt_for_2d, event_weight);
    m_el_iso_pt_bins.at(ISO_ETCONE30       )->Fill(el_etcone30/el_pt       , el_pt_for_2d, event_weight);
    m_el_iso_pt_bins.at(ISO_PTCONE20       )->Fill(el_ptcone20/el_pt       , el_pt_for_2d, event_weight);
    m_el_iso_pt_bins.at(ISO_ETCONE20       )->Fill(el_etcone20/el_pt       , el_pt_for_2d, event_weight);
    m_el_iso_pt_bins.at(ISO_PTCONE30_CAPPED)->Fill(el_ptcone30/el_pt_capped, el_pt_for_2d, event_weight);
    m_el_iso_pt_bins.at(ISO_ETCONE30_CAPPED)->Fill(el_etcone30/el_pt_capped, el_pt_for_2d, event_weight);
    m_el_iso_pt_bins.at(ISO_PTCONE20_CAPPED)->Fill(el_ptcone20/el_pt_capped, el_pt_for_2d, event_weight);
    m_el_iso_pt_bins.at(ISO_ETCONE20_CAPPED)->Fill(el_etcone20/el_pt_capped, el_pt_for_2d, event_weight);

    // fill eta-binned isolation histograms
    m_el_iso_eta_bins.at(ISO_PTCONE30       )->Fill(el_ptcone30/el_pt       , el_eta, event_weight);
    m_el_iso_eta_bins.at(ISO_ETCONE30       )->Fill(el_etcone30/el_pt       , el_eta, event_weight);
    m_el_iso_eta_bins.at(ISO_PTCONE20       )->Fill(el_ptcone20/el_pt       , el_eta, event_weight);
    m_el_iso_eta_bins.at(ISO_ETCONE20       )->Fill(el_etcone20/el_pt       , el_eta, event_weight);
    m_el_iso_eta_bins.at(ISO_PTCONE30_CAPPED)->Fill(el_ptcone30/el_pt_capped, el_eta, event_weight);
    m_el_iso_eta_bins.at(ISO_ETCONE30_CAPPED)->Fill(el_etcone30/el_pt_capped, el_eta, event_weight);
    m_el_iso_eta_bins.at(ISO_PTCONE20_CAPPED)->Fill(el_ptcone20/el_pt_capped, el_eta, event_weight);
    m_el_iso_eta_bins.at(ISO_ETCONE20_CAPPED)->Fill(el_etcone20/el_pt_capped, el_eta, event_weight);

    if (is_truth_matched) {
      // fill basic isolation histograms
      m_el_iso_prompt.at(ISO_PTCONE30       )->Fill(el_ptcone30/el_pt       , event_weight);
      m_el_iso_prompt.at(ISO_ETCONE30       )->Fill(el_etcone30/el_pt       , event_weight);
      m_el_iso_prompt.at(ISO_PTCONE20       )->Fill(el_ptcone20/el_pt       , event_weight);
      m_el_iso_prompt.at(ISO_ETCONE20       )->Fill(el_etcone20/el_pt       , event_weight);
      m_el_iso_prompt.at(ISO_PTCONE30_CAPPED)->Fill(el_ptcone30/el_pt_capped, event_weight);
      m_el_iso_prompt.at(ISO_ETCONE30_CAPPED)->Fill(el_etcone30/el_pt_capped, event_weight);
      m_el_iso_prompt.at(ISO_PTCONE20_CAPPED)->Fill(el_ptcone20/el_pt_capped, event_weight);
      m_el_iso_prompt.at(ISO_ETCONE20_CAPPED)->Fill(el_etcone20/el_pt_capped, event_weight);

      // fill pt-binned isolation histograms
      m_el_iso_pt_bins_prompt.at(ISO_PTCONE30       )->Fill(el_ptcone30/el_pt       , el_pt_for_2d, event_weight);
      m_el_iso_pt_bins_prompt.at(ISO_ETCONE30       )->Fill(el_etcone30/el_pt       , el_pt_for_2d, event_weight);
      m_el_iso_pt_bins_prompt.at(ISO_PTCONE20       )->Fill(el_ptcone20/el_pt       , el_pt_for_2d, event_weight);
      m_el_iso_pt_bins_prompt.at(ISO_ETCONE20       )->Fill(el_etcone20/el_pt       , el_pt_for_2d, event_weight);
      m_el_iso_pt_bins_prompt.at(ISO_PTCONE30_CAPPED)->Fill(el_ptcone30/el_pt_capped, el_pt_for_2d, event_weight);
      m_el_iso_pt_bins_prompt.at(ISO_ETCONE30_CAPPED)->Fill(el_etcone30/el_pt_capped, el_pt_for_2d, event_weight);
      m_el_iso_pt_bins_prompt.at(ISO_PTCONE20_CAPPED)->Fill(el_ptcone20/el_pt_capped, el_pt_for_2d, event_weight);
      m_el_iso_pt_bins_prompt.at(ISO_ETCONE20_CAPPED)->Fill(el_etcone20/el_pt_capped, el_pt_for_2d, event_weight);

      // fill eta-binned isolation histograms
      m_el_iso_eta_bins_prompt.at(ISO_PTCONE30       )->Fill(el_ptcone30/el_pt       , el_eta, event_weight);
      m_el_iso_eta_bins_prompt.at(ISO_ETCONE30       )->Fill(el_etcone30/el_pt       , el_eta, event_weight);
      m_el_iso_eta_bins_prompt.at(ISO_PTCONE20       )->Fill(el_ptcone20/el_pt       , el_eta, event_weight);
      m_el_iso_eta_bins_prompt.at(ISO_ETCONE20       )->Fill(el_etcone20/el_pt       , el_eta, event_weight);
      m_el_iso_eta_bins_prompt.at(ISO_PTCONE30_CAPPED)->Fill(el_ptcone30/el_pt_capped, el_eta, event_weight);
      m_el_iso_eta_bins_prompt.at(ISO_ETCONE30_CAPPED)->Fill(el_etcone30/el_pt_capped, el_eta, event_weight);
      m_el_iso_eta_bins_prompt.at(ISO_PTCONE20_CAPPED)->Fill(el_ptcone20/el_pt_capped, el_eta, event_weight);
      m_el_iso_eta_bins_prompt.at(ISO_ETCONE20_CAPPED)->Fill(el_etcone20/el_pt_capped, el_eta, event_weight);
    }
    else {
      // fill basic isolation histograms
      m_el_iso_fake.at(ISO_PTCONE30       )->Fill(el_ptcone30/el_pt       , event_weight);
      m_el_iso_fake.at(ISO_ETCONE30       )->Fill(el_etcone30/el_pt       , event_weight);
      m_el_iso_fake.at(ISO_PTCONE20       )->Fill(el_ptcone20/el_pt       , event_weight);
      m_el_iso_fake.at(ISO_ETCONE20       )->Fill(el_etcone20/el_pt       , event_weight);
      m_el_iso_fake.at(ISO_PTCONE30_CAPPED)->Fill(el_ptcone30/el_pt_capped, event_weight);
      m_el_iso_fake.at(ISO_ETCONE30_CAPPED)->Fill(el_etcone30/el_pt_capped, event_weight);
      m_el_iso_fake.at(ISO_PTCONE20_CAPPED)->Fill(el_ptcone20/el_pt_capped, event_weight);
      m_el_iso_fake.at(ISO_ETCONE20_CAPPED)->Fill(el_etcone20/el_pt_capped, event_weight);

      // fill pt-binned isolation histograms
      m_el_iso_pt_bins_fake.at(ISO_PTCONE30       )->Fill(el_ptcone30/el_pt       , el_pt_for_2d, event_weight);
      m_el_iso_pt_bins_fake.at(ISO_ETCONE30       )->Fill(el_etcone30/el_pt       , el_pt_for_2d, event_weight);
      m_el_iso_pt_bins_fake.at(ISO_PTCONE20       )->Fill(el_ptcone20/el_pt       , el_pt_for_2d, event_weight);
      m_el_iso_pt_bins_fake.at(ISO_ETCONE20       )->Fill(el_etcone20/el_pt       , el_pt_for_2d, event_weight);
      m_el_iso_pt_bins_fake.at(ISO_PTCONE30_CAPPED)->Fill(el_ptcone30/el_pt_capped, el_pt_for_2d, event_weight);
      m_el_iso_pt_bins_fake.at(ISO_ETCONE30_CAPPED)->Fill(el_etcone30/el_pt_capped, el_pt_for_2d, event_weight);
      m_el_iso_pt_bins_fake.at(ISO_PTCONE20_CAPPED)->Fill(el_ptcone20/el_pt_capped, el_pt_for_2d, event_weight);
      m_el_iso_pt_bins_fake.at(ISO_ETCONE20_CAPPED)->Fill(el_etcone20/el_pt_capped, el_pt_for_2d, event_weight);

      // fill eta-binned isolation histograms
      m_el_iso_eta_bins_fake.at(ISO_PTCONE30       )->Fill(el_ptcone30/el_pt       , el_eta, event_weight);
      m_el_iso_eta_bins_fake.at(ISO_ETCONE30       )->Fill(el_etcone30/el_pt       , el_eta, event_weight);
      m_el_iso_eta_bins_fake.at(ISO_PTCONE20       )->Fill(el_ptcone20/el_pt       , el_eta, event_weight);
      m_el_iso_eta_bins_fake.at(ISO_ETCONE20       )->Fill(el_etcone20/el_pt       , el_eta, event_weight);
      m_el_iso_eta_bins_fake.at(ISO_PTCONE30_CAPPED)->Fill(el_ptcone30/el_pt_capped, el_eta, event_weight);
      m_el_iso_eta_bins_fake.at(ISO_ETCONE30_CAPPED)->Fill(el_etcone30/el_pt_capped, el_eta, event_weight);
      m_el_iso_eta_bins_fake.at(ISO_PTCONE20_CAPPED)->Fill(el_ptcone20/el_pt_capped, el_eta, event_weight);
      m_el_iso_eta_bins_fake.at(ISO_ETCONE20_CAPPED)->Fill(el_etcone20/el_pt_capped, el_eta, event_weight);
    }
  }

  for (size_t mu_it = 0; mu_it != num_mu; ++mu_it) {
    SusyAnalysisTools::MuonDescription mu_desc(m_mu_desc->at(mu_it));
    bool is_truth_matched = mu_desc.getPassPromptLepton();

    // get muon kinematic variables
    double mu_eta = fabs(m_mu_eta->at(mu_it));
    double mu_pt  = m_mu_pt->at(mu_it)/1000.;

    // additional eta cut for "fake candidate baseline" muons
    if (mu_eta > 2.4) continue;

    // special versions of pT which are allowed to be no greater than some maximum value
    double mu_pt_for_2d = std::min(mu_pt, 99.);
    double mu_pt_capped = std::min(mu_pt, 60.);

    // get isolation variables
    double mu_ptcone30 = getMuIsoCorr(mu_it, NtupleHelper::ISO_TYPE_PTCONE, NtupleHelper::CONE_30)/1000.;
    double mu_etcone30 = getMuIsoCorr(mu_it, NtupleHelper::ISO_TYPE_ETCONE, NtupleHelper::CONE_30)/1000.;
    double mu_ptcone20 = getMuIsoCorr(mu_it, NtupleHelper::ISO_TYPE_PTCONE, NtupleHelper::CONE_20)/1000.;
    double mu_etcone20 = getMuIsoCorr(mu_it, NtupleHelper::ISO_TYPE_ETCONE, NtupleHelper::CONE_20)/1000.;

    // fill basic isolation histograms
    m_mu_iso.at(ISO_PTCONE30       )->Fill(mu_ptcone30/mu_pt       , event_weight);
    m_mu_iso.at(ISO_ETCONE30       )->Fill(mu_etcone30/mu_pt       , event_weight);
    m_mu_iso.at(ISO_PTCONE20       )->Fill(mu_ptcone20/mu_pt       , event_weight);
    m_mu_iso.at(ISO_ETCONE20       )->Fill(mu_etcone20/mu_pt       , event_weight);
    m_mu_iso.at(ISO_PTCONE30_CAPPED)->Fill(mu_ptcone30/mu_pt_capped, event_weight);
    m_mu_iso.at(ISO_ETCONE30_CAPPED)->Fill(mu_etcone30/mu_pt_capped, event_weight);
    m_mu_iso.at(ISO_PTCONE20_CAPPED)->Fill(mu_ptcone20/mu_pt_capped, event_weight);
    m_mu_iso.at(ISO_ETCONE20_CAPPED)->Fill(mu_etcone20/mu_pt_capped, event_weight);

    // fill pt-binned isolation histograms
    m_mu_iso_pt_bins.at(ISO_PTCONE30       )->Fill(mu_ptcone30/mu_pt       , mu_pt_for_2d, event_weight);
    m_mu_iso_pt_bins.at(ISO_ETCONE30       )->Fill(mu_etcone30/mu_pt       , mu_pt_for_2d, event_weight);
    m_mu_iso_pt_bins.at(ISO_PTCONE20       )->Fill(mu_ptcone20/mu_pt       , mu_pt_for_2d, event_weight);
    m_mu_iso_pt_bins.at(ISO_ETCONE20       )->Fill(mu_etcone20/mu_pt       , mu_pt_for_2d, event_weight);
    m_mu_iso_pt_bins.at(ISO_PTCONE30_CAPPED)->Fill(mu_ptcone30/mu_pt_capped, mu_pt_for_2d, event_weight);
    m_mu_iso_pt_bins.at(ISO_ETCONE30_CAPPED)->Fill(mu_etcone30/mu_pt_capped, mu_pt_for_2d, event_weight);
    m_mu_iso_pt_bins.at(ISO_PTCONE20_CAPPED)->Fill(mu_ptcone20/mu_pt_capped, mu_pt_for_2d, event_weight);
    m_mu_iso_pt_bins.at(ISO_ETCONE20_CAPPED)->Fill(mu_etcone20/mu_pt_capped, mu_pt_for_2d, event_weight);

    // fill eta-binned isolation histograms
    m_mu_iso_eta_bins.at(ISO_PTCONE30       )->Fill(mu_ptcone30/mu_pt       , mu_eta, event_weight);
    m_mu_iso_eta_bins.at(ISO_ETCONE30       )->Fill(mu_etcone30/mu_pt       , mu_eta, event_weight);
    m_mu_iso_eta_bins.at(ISO_PTCONE20       )->Fill(mu_ptcone20/mu_pt       , mu_eta, event_weight);
    m_mu_iso_eta_bins.at(ISO_ETCONE20       )->Fill(mu_etcone20/mu_pt       , mu_eta, event_weight);
    m_mu_iso_eta_bins.at(ISO_PTCONE30_CAPPED)->Fill(mu_ptcone30/mu_pt_capped, mu_eta, event_weight);
    m_mu_iso_eta_bins.at(ISO_ETCONE30_CAPPED)->Fill(mu_etcone30/mu_pt_capped, mu_eta, event_weight);
    m_mu_iso_eta_bins.at(ISO_PTCONE20_CAPPED)->Fill(mu_ptcone20/mu_pt_capped, mu_eta, event_weight);
    m_mu_iso_eta_bins.at(ISO_ETCONE20_CAPPED)->Fill(mu_etcone20/mu_pt_capped, mu_eta, event_weight);

    if (is_truth_matched) {
      // fill basic isolation histograms
      m_mu_iso_prompt.at(ISO_PTCONE30       )->Fill(mu_ptcone30/mu_pt       , event_weight);
      m_mu_iso_prompt.at(ISO_ETCONE30       )->Fill(mu_etcone30/mu_pt       , event_weight);
      m_mu_iso_prompt.at(ISO_PTCONE20       )->Fill(mu_ptcone20/mu_pt       , event_weight);
      m_mu_iso_prompt.at(ISO_ETCONE20       )->Fill(mu_etcone20/mu_pt       , event_weight);
      m_mu_iso_prompt.at(ISO_PTCONE30_CAPPED)->Fill(mu_ptcone30/mu_pt_capped, event_weight);
      m_mu_iso_prompt.at(ISO_ETCONE30_CAPPED)->Fill(mu_etcone30/mu_pt_capped, event_weight);
      m_mu_iso_prompt.at(ISO_PTCONE20_CAPPED)->Fill(mu_ptcone20/mu_pt_capped, event_weight);
      m_mu_iso_prompt.at(ISO_ETCONE20_CAPPED)->Fill(mu_etcone20/mu_pt_capped, event_weight);

      // fill pt-binned isolation histograms
      m_mu_iso_pt_bins_prompt.at(ISO_PTCONE30       )->Fill(mu_ptcone30/mu_pt       , mu_pt_for_2d, event_weight);
      m_mu_iso_pt_bins_prompt.at(ISO_ETCONE30       )->Fill(mu_etcone30/mu_pt       , mu_pt_for_2d, event_weight);
      m_mu_iso_pt_bins_prompt.at(ISO_PTCONE20       )->Fill(mu_ptcone20/mu_pt       , mu_pt_for_2d, event_weight);
      m_mu_iso_pt_bins_prompt.at(ISO_ETCONE20       )->Fill(mu_etcone20/mu_pt       , mu_pt_for_2d, event_weight);
      m_mu_iso_pt_bins_prompt.at(ISO_PTCONE30_CAPPED)->Fill(mu_ptcone30/mu_pt_capped, mu_pt_for_2d, event_weight);
      m_mu_iso_pt_bins_prompt.at(ISO_ETCONE30_CAPPED)->Fill(mu_etcone30/mu_pt_capped, mu_pt_for_2d, event_weight);
      m_mu_iso_pt_bins_prompt.at(ISO_PTCONE20_CAPPED)->Fill(mu_ptcone20/mu_pt_capped, mu_pt_for_2d, event_weight);
      m_mu_iso_pt_bins_prompt.at(ISO_ETCONE20_CAPPED)->Fill(mu_etcone20/mu_pt_capped, mu_pt_for_2d, event_weight);

      // fill eta-binned isolation histograms
      m_mu_iso_eta_bins_prompt.at(ISO_PTCONE30       )->Fill(mu_ptcone30/mu_pt       , mu_eta, event_weight);
      m_mu_iso_eta_bins_prompt.at(ISO_ETCONE30       )->Fill(mu_etcone30/mu_pt       , mu_eta, event_weight);
      m_mu_iso_eta_bins_prompt.at(ISO_PTCONE20       )->Fill(mu_ptcone20/mu_pt       , mu_eta, event_weight);
      m_mu_iso_eta_bins_prompt.at(ISO_ETCONE20       )->Fill(mu_etcone20/mu_pt       , mu_eta, event_weight);
      m_mu_iso_eta_bins_prompt.at(ISO_PTCONE30_CAPPED)->Fill(mu_ptcone30/mu_pt_capped, mu_eta, event_weight);
      m_mu_iso_eta_bins_prompt.at(ISO_ETCONE30_CAPPED)->Fill(mu_etcone30/mu_pt_capped, mu_eta, event_weight);
      m_mu_iso_eta_bins_prompt.at(ISO_PTCONE20_CAPPED)->Fill(mu_ptcone20/mu_pt_capped, mu_eta, event_weight);
      m_mu_iso_eta_bins_prompt.at(ISO_ETCONE20_CAPPED)->Fill(mu_etcone20/mu_pt_capped, mu_eta, event_weight);
    }
    else {
      // fill basic isolation histograms
      m_mu_iso_fake.at(ISO_PTCONE30       )->Fill(mu_ptcone30/mu_pt       , event_weight);
      m_mu_iso_fake.at(ISO_ETCONE30       )->Fill(mu_etcone30/mu_pt       , event_weight);
      m_mu_iso_fake.at(ISO_PTCONE20       )->Fill(mu_ptcone20/mu_pt       , event_weight);
      m_mu_iso_fake.at(ISO_ETCONE20       )->Fill(mu_etcone20/mu_pt       , event_weight);
      m_mu_iso_fake.at(ISO_PTCONE30_CAPPED)->Fill(mu_ptcone30/mu_pt_capped, event_weight);
      m_mu_iso_fake.at(ISO_ETCONE30_CAPPED)->Fill(mu_etcone30/mu_pt_capped, event_weight);
      m_mu_iso_fake.at(ISO_PTCONE20_CAPPED)->Fill(mu_ptcone20/mu_pt_capped, event_weight);
      m_mu_iso_fake.at(ISO_ETCONE20_CAPPED)->Fill(mu_etcone20/mu_pt_capped, event_weight);

      // fill pt-binned isolation histograms
      m_mu_iso_pt_bins_fake.at(ISO_PTCONE30       )->Fill(mu_ptcone30/mu_pt       , mu_pt_for_2d, event_weight);
      m_mu_iso_pt_bins_fake.at(ISO_ETCONE30       )->Fill(mu_etcone30/mu_pt       , mu_pt_for_2d, event_weight);
      m_mu_iso_pt_bins_fake.at(ISO_PTCONE20       )->Fill(mu_ptcone20/mu_pt       , mu_pt_for_2d, event_weight);
      m_mu_iso_pt_bins_fake.at(ISO_ETCONE20       )->Fill(mu_etcone20/mu_pt       , mu_pt_for_2d, event_weight);
      m_mu_iso_pt_bins_fake.at(ISO_PTCONE30_CAPPED)->Fill(mu_ptcone30/mu_pt_capped, mu_pt_for_2d, event_weight);
      m_mu_iso_pt_bins_fake.at(ISO_ETCONE30_CAPPED)->Fill(mu_etcone30/mu_pt_capped, mu_pt_for_2d, event_weight);
      m_mu_iso_pt_bins_fake.at(ISO_PTCONE20_CAPPED)->Fill(mu_ptcone20/mu_pt_capped, mu_pt_for_2d, event_weight);
      m_mu_iso_pt_bins_fake.at(ISO_ETCONE20_CAPPED)->Fill(mu_etcone20/mu_pt_capped, mu_pt_for_2d, event_weight);

      // fill eta-binned isolation histograms
      m_mu_iso_eta_bins_fake.at(ISO_PTCONE30       )->Fill(mu_ptcone30/mu_pt       , mu_eta, event_weight);
      m_mu_iso_eta_bins_fake.at(ISO_ETCONE30       )->Fill(mu_etcone30/mu_pt       , mu_eta, event_weight);
      m_mu_iso_eta_bins_fake.at(ISO_PTCONE20       )->Fill(mu_ptcone20/mu_pt       , mu_eta, event_weight);
      m_mu_iso_eta_bins_fake.at(ISO_ETCONE20       )->Fill(mu_etcone20/mu_pt       , mu_eta, event_weight);
      m_mu_iso_eta_bins_fake.at(ISO_PTCONE30_CAPPED)->Fill(mu_ptcone30/mu_pt_capped, mu_eta, event_weight);
      m_mu_iso_eta_bins_fake.at(ISO_ETCONE30_CAPPED)->Fill(mu_etcone30/mu_pt_capped, mu_eta, event_weight);
      m_mu_iso_eta_bins_fake.at(ISO_PTCONE20_CAPPED)->Fill(mu_ptcone20/mu_pt_capped, mu_eta, event_weight);
      m_mu_iso_eta_bins_fake.at(ISO_ETCONE20_CAPPED)->Fill(mu_etcone20/mu_pt_capped, mu_eta, event_weight);
    }
  }
}

// -----------------------------------------------------------------------------
void OptimizeIsolation::printToScreen()
{
  unsigned int line_width   = 100;
  unsigned int label_field  = 30;
  unsigned int weight_field = (line_width - label_field - 4 - 2*3 )/2;
  // unsigned int precision    = weight_field-2;
  if (4+label_field+2*weight_field != line_width) {
    label_field += (line_width - label_field - 4 - 2*3 )%2;
  }
  std::string break_label = "";
  std::string break_weight = "";
  for (unsigned int i = 0; i != label_field ; ++i) break_label  += "-";
  for (unsigned int i = 0; i != weight_field; ++i) break_weight += "-";

  std::string single_line;
  for (unsigned int i = 0; i != line_width; ++i) single_line += '=';
  single_line = single_line + "\n";
}

// -----------------------------------------------------------------------------
void OptimizeIsolation::printToFile(std::string out_file_name)
{
  TFile f(out_file_name.c_str(), "RECREATE");
  f.cd();

  for (unsigned int iso_style = 0; iso_style != ISO_N; ++iso_style) {
    m_el_iso.at(iso_style)->Write();
    m_mu_iso.at(iso_style)->Write();

    m_el_iso_prompt.at(iso_style)->Write();
    m_mu_iso_prompt.at(iso_style)->Write();

    m_el_iso_fake.at(iso_style)->Write();
    m_mu_iso_fake.at(iso_style)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_el_iso_pt_bins.at(iso_style)->Write();
    m_mu_iso_pt_bins.at(iso_style)->Write();

    m_el_iso_pt_bins_prompt.at(iso_style)->Write();
    m_mu_iso_pt_bins_prompt.at(iso_style)->Write();

    m_el_iso_pt_bins_fake.at(iso_style)->Write();
    m_mu_iso_pt_bins_fake.at(iso_style)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_el_iso_eta_bins.at(iso_style)->Write();
    m_mu_iso_eta_bins.at(iso_style)->Write();

    m_el_iso_eta_bins_prompt.at(iso_style)->Write();
    m_mu_iso_eta_bins_prompt.at(iso_style)->Write();

    m_el_iso_eta_bins_fake.at(iso_style)->Write();
    m_mu_iso_eta_bins_fake.at(iso_style)->Write();
  }
}
