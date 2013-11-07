#include "CalculateFakeRates/include/CalculateFakeRates.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

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
CalculateFakeRates::CalculateFakeRates( TTree *tree
                                      , double num_events) : NtupleHelper::NtupleLooper(tree, num_events)
                                                           , m_el_re_denom(NULL)
                                                           , m_mu_re_denom(NULL)
                                                           , m_el_fr_denom(NULL)
                                                           , m_mu_fr_denom(NULL)
                                                           , m_el_re_eta_bins_denom(NULL)
                                                           , m_mu_re_eta_bins_denom(NULL)
                                                           , m_el_fr_eta_bins_denom(NULL)
                                                           , m_mu_fr_eta_bins_denom(NULL)
{
  double pt_bins[7] = {0., 10., 20., 35., 50., 75., 100.};
  double eta_bins[5] = {0.0, 0.6, 1.2, 1.8, 2.5};

  for (unsigned int fake_style = 0; fake_style != NtupleHelper::ISO_STYLE_N; ++fake_style) {
    std::string fake_style_string = NtupleHelper::ISO_STYLE_STRINGS[fake_style];
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_el_re_numer.push_back( new TH1D( ("el_re_numer_" + fake_style_string).c_str()
                                     , ("electron re numerator (" + fake_style_string + ")").c_str()
                                     , 6, pt_bins
                                     )
                           );
    m_mu_re_numer.push_back( new TH1D( ("mu_re_numer_" + fake_style_string).c_str()
                                     , ("muon re numerator (" + fake_style_string + ")").c_str()
                                     , 6, pt_bins
                                     )
                           );
    m_el_fr_numer.push_back( new TH1D( ("el_fr_numer_" + fake_style_string).c_str()
                                     , ("electron fr numerator (" + fake_style_string + ")").c_str()
                                     , 6, pt_bins
                                     )
                           );
    m_mu_fr_numer.push_back( new TH1D( ("mu_fr_numer_" + fake_style_string).c_str()
                                     , ("muon fr numerator (" + fake_style_string + ")").c_str()
                                     , 6, pt_bins
                                     )
                           );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_el_re_eta_bins_numer.push_back( new TH2D( ( "el_re_eta_bins_numer_"
                                                + fake_style_string
                                                ).c_str()
                                              , ( "electron re numerator ("
                                                + fake_style_string
                                                + ")"
                                                ).c_str()
                                              , 6, pt_bins
                                              , 4, eta_bins
                                              )
                                    );
    m_mu_re_eta_bins_numer.push_back( new TH2D( ( "mu_re_eta_bins_numer_"
                                                + fake_style_string
                                                ).c_str()
                                              , ( "muon re numerator ("
                                                + fake_style_string + ")"
                                                ).c_str()
                                              , 6, pt_bins
                                              , 4, eta_bins
                                              )
                                    );
    m_el_fr_eta_bins_numer.push_back( new TH2D( ( "el_fr_eta_bins_numer_"
                                                + fake_style_string
                                                ).c_str()
                                              , ( "electron fr numerator ("
                                                + fake_style_string
                                                + ")"
                                                ).c_str()
                                              , 6, pt_bins
                                              , 4, eta_bins
                                              )
                                    );
    m_mu_fr_eta_bins_numer.push_back( new TH2D( ( "mu_fr_eta_bins_numer_"
                                                + fake_style_string
                                                ).c_str()
                                              , ( "muon fr numerator ("
                                                + fake_style_string
                                                + ")"
                                                ).c_str()
                                              , 6, pt_bins
                                              , 4, eta_bins
                                              )
                                    );
  }

  m_el_re_denom = new TH1D("el_re_denom", "electron re denominator", 6, pt_bins);
  m_mu_re_denom = new TH1D("mu_re_denom", "muon re denominator"    , 6, pt_bins);
  m_el_fr_denom = new TH1D("el_fr_denom", "electron fr denominator", 6, pt_bins);
  m_mu_fr_denom = new TH1D("mu_fr_denom", "muon fr denominator"    , 6, pt_bins);

  m_el_re_eta_bins_denom = new TH2D( "el_re_eta_bins_denom"
                                   , "electron re denominator"
                                   , 6, pt_bins
                                   , 4, eta_bins
                                   );
  m_mu_re_eta_bins_denom = new TH2D( "mu_re_eta_bins_denom"
                                   , "muon re denominator"
                                   , 6, pt_bins
                                   , 4, eta_bins
                                   );
  m_el_fr_eta_bins_denom = new TH2D( "el_fr_eta_bins_denom"
                                   , "electron fr denominator"
                                   , 6, pt_bins
                                   , 4, eta_bins
                                   );
  m_mu_fr_eta_bins_denom = new TH2D( "mu_fr_eta_bins_denom"
                                   , "muon fr denominator"
                                   , 6, pt_bins
                                   , 4, eta_bins
                                   );
}

// -----------------------------------------------------------------------------
CalculateFakeRates::~CalculateFakeRates()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void CalculateFakeRates::processEvent()
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

  // loop over electrons in event
  size_t num_el = m_el_desc->size();
  for (size_t el_it = 0; el_it != num_el; ++el_it) {
    // from electron description, determine if the electron is truth matched
    // prompt and if it is at least baseline
    SusyAnalysisTools::ElectronDescription el_desc(m_el_desc->at(el_it));
    bool is_truth_matched = el_desc.getPassPromptLepton();
    bool is_baseline      = el_desc.getPassGood();

    // Check all out signal lepton definitions based on the different isolation
    // styles
    bool is_signal[NtupleHelper::ISO_STYLE_N];
    for ( unsigned int iso_style = 0
        ; iso_style != NtupleHelper::ISO_STYLE_N
        ; ++iso_style
        ) {
      is_signal[iso_style] = isSignalElectron( el_it
                                             , el_desc
                                             , false
                                             , NtupleHelper::ISO_STYLE(iso_style)
                                             );
    }

    // get electron pT & eta (allow this to be no greater than 99)
    float el_pt = m_el_pt->at(el_it)/1000.;
    if (el_pt >= 100.) el_pt = 99.;
    float el_eta = fabs(m_el_eta->at(el_it));

    // if truth matched, this goes into the real factor calculation
    if (is_truth_matched) {
      if (is_baseline) {
        // all baseline electrons at this stage go into the denominator
        m_el_re_denom->Fill(el_pt, event_weight);
        m_el_re_eta_bins_denom->Fill(el_pt, el_eta, event_weight);

        // fill the correct numerator histograms based on which signal electron
        // style are passsed
        for ( unsigned int iso_style = 0
            ; iso_style != NtupleHelper::ISO_STYLE_N
            ; ++iso_style
            ) {
          if (is_signal[iso_style])
            m_el_re_numer.at(iso_style)->Fill(el_pt, event_weight);
            m_el_re_eta_bins_numer.at(iso_style)->Fill(el_pt, el_eta, event_weight);
        }
      }
    }
    // if not truth prompt, this goes into the fake factor calculation
    else {
      if (is_baseline) {
        // all baseline electrons at this stage go into the denominator
        m_el_fr_denom->Fill(el_pt, event_weight);
        m_el_fr_eta_bins_denom->Fill(el_pt, el_eta, event_weight);

        // fill the correct numerator histograms based on which signal electron
        // style are passsed
        for ( unsigned int iso_style = 0
            ; iso_style != NtupleHelper::ISO_STYLE_N
            ; ++iso_style
            ) {
          if (is_signal[iso_style])
            m_el_fr_numer.at(iso_style)->Fill(el_pt, event_weight);
            m_el_fr_eta_bins_numer.at(iso_style)->Fill(el_pt, el_eta, event_weight);
        }
      }
    }
  }

  // loop over all muons in event
  size_t num_mu = m_mu_desc->size();
  for (size_t mu_it = 0; mu_it != num_mu; ++mu_it) {
    // from muon description, determine if the muon is truth matched
    // prompt and if it is at least baseline
    SusyAnalysisTools::MuonDescription mu_desc(m_mu_desc->at(mu_it));
    bool is_truth_matched = mu_desc.getPassPromptLepton();
    bool is_baseline      = mu_desc.getPassGood();

    // Check all out signal lepton definitions based on the different isolation
    // styles
    bool is_signal[NtupleHelper::ISO_STYLE_N];
    for ( unsigned int iso_style = 0
        ; iso_style != NtupleHelper::ISO_STYLE_N
        ; ++iso_style
        ) {
      is_signal[iso_style] = isSignalMuon( mu_it
                                         , mu_desc
                                         , false
                                         , NtupleHelper::ISO_STYLE(iso_style)
                                         );
    }

    // get muon pT (allow this to be no greater than 99)
    float mu_pt = m_mu_pt->at(mu_it)/1000.;
    if (mu_pt >= 100.) mu_pt = 99.;
    float mu_eta = fabs(m_mu_eta->at(mu_it));

    // if truth matched, this goes into the real factor calculation
    if (is_truth_matched) {
      if (is_baseline) {
        // all baseline muons at this stage go into the denominator
        m_mu_re_denom->Fill(mu_pt, event_weight);
        m_mu_re_eta_bins_denom->Fill(mu_pt, mu_eta, event_weight);

        // fill the correct numerator histograms based on which signal muon
        // style are passsed
        for ( unsigned int iso_style = 0
            ; iso_style != NtupleHelper::ISO_STYLE_N
            ; ++iso_style
            ) {
          if (is_signal[iso_style])
            m_mu_re_numer.at(iso_style)->Fill(mu_pt, event_weight);
            m_mu_re_eta_bins_numer.at(iso_style)->Fill(mu_pt, mu_eta, event_weight);
        }
      }
    }
    // if not truth prompt, this goes into the fake factor calculation
    else {
      if (is_baseline) {
        // all baseline muons at this stage go into the denominator
        m_mu_fr_denom->Fill(mu_pt, event_weight);
        m_mu_fr_eta_bins_denom->Fill(mu_pt, mu_eta, event_weight);

        // fill the correct numerator histograms based on which signal muon
        // style are passsed
        for ( unsigned int iso_style = 0
            ; iso_style != NtupleHelper::ISO_STYLE_N
            ; ++iso_style
            ) {
          if (is_signal[iso_style])
            m_mu_fr_numer.at(iso_style)->Fill(mu_pt, event_weight);
            m_mu_fr_eta_bins_numer.at(iso_style)->Fill(mu_pt, mu_eta, event_weight);
        }
      }
    }
  }
}

// -----------------------------------------------------------------------------
void CalculateFakeRates::printToScreen()
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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // for (unsigned int fake_style = 0; fake_style != FAKE_N; ++fake_style) {
  //   std::string fake_style_string = FAKE_STYLE_STRINGS[fake_style];
  for (unsigned int fake_style = 0; fake_style != NtupleHelper::ISO_STYLE_N; ++fake_style) {
    std::string fake_style_string = NtupleHelper::ISO_STYLE_STRINGS[fake_style];

    m_el_re.push_back( computeFactorHistogram( m_el_re_numer.at(fake_style)
                                             , m_el_re_denom
                                             , ("el_re_" + fake_style_string)
                                             )
                       
                     );

    m_mu_re.push_back( computeFactorHistogram( m_mu_re_numer.at(fake_style)
                                             , m_mu_re_denom
                                             , ("mu_re_" + fake_style_string)
                                             )
                       
                     );

    m_el_fr.push_back( computeFactorHistogram( m_el_fr_numer.at(fake_style)
                                             , m_el_fr_denom
                                             , ("el_fr_" + fake_style_string)
                                             )
                       
                     );

    m_mu_fr.push_back( computeFactorHistogram( m_mu_fr_numer.at(fake_style)
                                             , m_mu_fr_denom
                                             , ("mu_fr_" + fake_style_string)
                                             )
                       
                     );

    m_el_re_eta_bins.push_back( computeFactorHistogram( m_el_re_eta_bins_numer.at(fake_style)
                                                      , m_el_re_eta_bins_denom
                                                      , ("el_re_eta_bins_" + fake_style_string)
                                                      )
                                
                              );

    m_mu_re_eta_bins.push_back( computeFactorHistogram( m_mu_re_eta_bins_numer.at(fake_style)
                                                      , m_mu_re_eta_bins_denom
                                                      , ("mu_re_eta_bins_" + fake_style_string)
                                                      )
                                
                              );

    m_el_fr_eta_bins.push_back( computeFactorHistogram( m_el_fr_eta_bins_numer.at(fake_style)
                                                      , m_el_fr_eta_bins_denom
                                                      , ("el_fr_eta_bins_" + fake_style_string)
                                                      )
                                
                              );

    m_mu_fr_eta_bins.push_back( computeFactorHistogram( m_mu_fr_eta_bins_numer.at(fake_style)
                                                      , m_mu_fr_eta_bins_denom
                                                      , ("mu_fr_eta_bins_" + fake_style_string)
                                                      )
                                
                              );

  }
}

// -----------------------------------------------------------------------------
void CalculateFakeRates::printToFile(std::string out_file_name)
{
  TFile f(out_file_name.c_str(), "RECREATE");
  f.cd();

  for (unsigned int fake_style = 0; fake_style != NtupleHelper::ISO_STYLE_N; ++fake_style) {
    m_el_re.at(fake_style)->Write();
    m_mu_re.at(fake_style)->Write();
    m_el_fr.at(fake_style)->Write();
    m_mu_fr.at(fake_style)->Write();

    m_el_re_numer.at(fake_style)->Write();
    m_mu_re_numer.at(fake_style)->Write();
    m_el_fr_numer.at(fake_style)->Write();
    m_mu_fr_numer.at(fake_style)->Write();

    m_el_re_eta_bins.at(fake_style)->Write();
    m_mu_re_eta_bins.at(fake_style)->Write();
    m_el_fr_eta_bins.at(fake_style)->Write();
    m_mu_fr_eta_bins.at(fake_style)->Write();

    m_el_re_eta_bins_numer.at(fake_style)->Write();
    m_mu_re_eta_bins_numer.at(fake_style)->Write();
    m_el_fr_eta_bins_numer.at(fake_style)->Write();
    m_mu_fr_eta_bins_numer.at(fake_style)->Write();
  }
  m_el_re_denom->Write();
  m_mu_re_denom->Write();
  m_el_fr_denom->Write();
  m_mu_fr_denom->Write();

  m_el_re_eta_bins_denom->Write();
  m_mu_re_eta_bins_denom->Write();
  m_el_fr_eta_bins_denom->Write();
  m_mu_fr_eta_bins_denom->Write();
}
