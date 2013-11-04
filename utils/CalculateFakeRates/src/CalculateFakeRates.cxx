#include "CalculateFakeRates/include/CalculateFakeRates.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

#include <TCanvas.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1D.h>
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
{
  // double pt_bins[7] = {0., 15., 30., 45., 55., 75., 100.};
  double pt_bins[7] = {0., 10., 20., 35., 50., 75., 100.};

  for (unsigned int fake_style = 0; fake_style != FAKE_N; ++fake_style) {
    std::string fake_style_string = FAKE_STYLE_STRINGS[fake_style];
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
  }

  m_el_re_denom        = new TH1D("el_re_denom"       , "electron re denominator"       , 6, pt_bins);
  m_mu_re_denom        = new TH1D("mu_re_denom"       , "muon re denominator"       , 6, pt_bins);
  m_el_fr_denom        = new TH1D("el_fr_denom"       , "electron fr denominator"       , 6, pt_bins);
  m_mu_fr_denom        = new TH1D("mu_fr_denom"       , "muon fr denominator"       , 6, pt_bins);
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

  size_t num_el = m_el_desc->size();
  size_t num_mu = m_mu_desc->size();

  for (size_t el_it = 0; el_it != num_el; ++el_it) {
    SusyAnalysisTools::ElectronDescription el_desc(m_el_desc->at(el_it));
    bool is_truth_matched = el_desc.getPassPromptLepton();
    bool is_baseline      = el_desc.getPassGood();

    bool is_signal_EWK       = isSignalElectron(el_it, el_desc, false, NtupleHelper::EWK_STYLE);
    bool is_signal_HIGGS     = isSignalElectron(el_it, el_desc, false, NtupleHelper::EWK_HIGGS_STYLE);
    bool is_signal_STRONG    = isSignalElectron(el_it, el_desc, false, NtupleHelper::STRONG_STYLE);
    bool is_signal_STRONG_30 = isSignalElectron(el_it, el_desc, false, NtupleHelper::STRONG_STYLE_CONE_30);

    float el_pt           = m_el_pt->at(el_it)/1000.;

    if (el_pt >= 100.) el_pt = 99.;

    if (is_truth_matched) {
      if (is_baseline) {
        m_el_re_denom->Fill(el_pt, event_weight);
      }
      if (is_baseline && is_signal_EWK) {
        m_el_re_numer.at(FAKE_EWK)->Fill(el_pt, event_weight);
      }
      if (is_baseline && is_signal_HIGGS) {
        m_el_re_numer.at(FAKE_HIGGS)->Fill(el_pt, event_weight);
      }
      if (is_baseline && is_signal_STRONG) {
        m_el_re_numer.at(FAKE_STRONG)->Fill(el_pt, event_weight);
      }
      if (is_baseline && is_signal_STRONG_30) {
        m_el_re_numer.at(FAKE_STRONG_30)->Fill(el_pt, event_weight);
      }
    }
    else {
      if (is_baseline) {
        m_el_fr_denom->Fill(el_pt, event_weight);
      }
      if (is_baseline && is_signal_EWK) {
        m_el_fr_numer.at(FAKE_EWK)->Fill(el_pt, event_weight);
      }
      if (is_baseline && is_signal_HIGGS) {
        m_el_fr_numer.at(FAKE_HIGGS)->Fill(el_pt, event_weight);
      }
      if (is_baseline && is_signal_STRONG) {
        m_el_fr_numer.at(FAKE_STRONG)->Fill(el_pt, event_weight);
      }
      if (is_baseline && is_signal_STRONG_30) {
        m_el_fr_numer.at(FAKE_STRONG_30)->Fill(el_pt, event_weight);
      }
    }
  }

  for (size_t mu_it = 0; mu_it != num_mu; ++mu_it) {
    SusyAnalysisTools::MuonDescription mu_desc(m_mu_desc->at(mu_it));
    bool is_truth_matched = mu_desc.getPassPromptLepton();
    bool is_baseline      = mu_desc.getPassGood();
    bool is_signal_EWK    = isSignalMuon(mu_it, mu_desc, false, NtupleHelper::EWK_STYLE);
    bool is_signal_HIGGS  = isSignalMuon(mu_it, mu_desc, false, NtupleHelper::EWK_HIGGS_STYLE);
    bool is_signal_STRONG = isSignalMuon(mu_it, mu_desc, false, NtupleHelper::STRONG_STYLE);
    bool is_signal_STRONG_30 = isSignalMuon(mu_it, mu_desc, false, NtupleHelper::STRONG_STYLE_CONE_30);
    float mu_pt           = m_mu_pt->at(mu_it)/1000.;


    if (mu_pt >= 100.) mu_pt = 99.;

    if (is_truth_matched) {
      if (is_baseline) {
        m_mu_re_denom->Fill(mu_pt, event_weight);
      }
      if (is_baseline && is_signal_EWK) {
        m_mu_re_numer.at(FAKE_EWK)->Fill(mu_pt, event_weight);
      }
      if (is_baseline && is_signal_HIGGS) {
        m_mu_re_numer.at(FAKE_HIGGS)->Fill(mu_pt, event_weight);
      }
      if (is_baseline && is_signal_STRONG) {
        m_mu_re_numer.at(FAKE_STRONG)->Fill(mu_pt, event_weight);
      }
      if (is_baseline && is_signal_STRONG_30) {
        m_mu_re_numer.at(FAKE_STRONG_30)->Fill(mu_pt, event_weight);
      }
    }
    else {
      if (is_baseline) {
        m_mu_fr_denom->Fill(mu_pt, event_weight);
      }
      if (is_baseline && is_signal_EWK) {
        m_mu_fr_numer.at(FAKE_EWK)->Fill(mu_pt, event_weight);
      }
      if (is_baseline && is_signal_HIGGS) {
        m_mu_fr_numer.at(FAKE_HIGGS)->Fill(mu_pt, event_weight);
      }
      if (is_baseline && is_signal_STRONG) {
        m_mu_fr_numer.at(FAKE_STRONG)->Fill(mu_pt, event_weight);
      }
      if (is_baseline && is_signal_STRONG_30) {
        m_mu_fr_numer.at(FAKE_STRONG_30)->Fill(mu_pt, event_weight);
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
  for (unsigned int fake_style = 0; fake_style != FAKE_N; ++fake_style) {
    std::string fake_style_string = FAKE_STYLE_STRINGS[fake_style];

    TH1D * h_tmp_el_re = static_cast<TH1D*>(m_el_re_numer.at(fake_style)->Clone(("el_re_" + fake_style_string).c_str()));
    h_tmp_el_re->Sumw2();
    h_tmp_el_re->Divide(m_el_re_denom);
    m_el_re.push_back(h_tmp_el_re);

    TH1D * h_tmp_mu_re = static_cast<TH1D*>(m_mu_re_numer.at(fake_style)->Clone(("mu_re_" + fake_style_string).c_str()));
    h_tmp_mu_re->Sumw2();
    h_tmp_mu_re->Divide(m_mu_re_denom);
    m_mu_re.push_back(h_tmp_mu_re);

    TH1D * h_tmp_el_fr = static_cast<TH1D*>(m_el_fr_numer.at(fake_style)->Clone(("el_fr_" + fake_style_string).c_str()));
    h_tmp_el_fr->Sumw2();
    h_tmp_el_fr->Divide(m_el_fr_denom);
    m_el_fr.push_back(h_tmp_el_fr);

    TH1D * h_tmp_mu_fr = static_cast<TH1D*>(m_mu_fr_numer.at(fake_style)->Clone(("mu_fr_" + fake_style_string).c_str()));
    h_tmp_mu_fr->Sumw2();
    h_tmp_mu_fr->Divide(m_mu_fr_denom);
    m_mu_fr.push_back(h_tmp_mu_fr);
  }
}

// -----------------------------------------------------------------------------
void CalculateFakeRates::printToFile(std::string out_file_name)
{
  TFile f(out_file_name.c_str(), "RECREATE");
  f.cd();

  for (unsigned int fake_style = 0; fake_style != FAKE_N; ++fake_style) {
    m_el_re.at(fake_style)->Write();
    m_mu_re.at(fake_style)->Write();
    m_el_fr.at(fake_style)->Write();
    m_mu_fr.at(fake_style)->Write();

    m_el_re_numer.at(fake_style)->Write();
    m_mu_re_numer.at(fake_style)->Write();
    m_el_fr_numer.at(fake_style)->Write();
    m_mu_fr_numer.at(fake_style)->Write();
  }
  m_el_re_denom->Write();
  m_mu_re_denom->Write();
  m_el_fr_denom->Write();
  m_mu_fr_denom->Write();
}
