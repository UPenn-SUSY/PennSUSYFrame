#include "HistogramHandlers/include/HistogramHandlers.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/Calculators.h"

#include "TFile.h"
#include "TDirectory.h"
#include "TH1.h"

// =============================================================================
PennSusyFrame::HistogramHandler::HistogramHandler(std::string)
{ }

// -----------------------------------------------------------------------------
PennSusyFrame::HistogramHandler::~HistogramHandler()
{ }

// -----------------------------------------------------------------------------
std::vector<float> PennSusyFrame::HistogramHandler::generateLogBinning( float min
                                                                      , float max
                                                                      , size_t n_bins
                                                                      )
{
  std::vector<float> bin_edges;
  bin_edges.reserve(n_bins+1);

  float log_min = (min > 0 ? log10(min) : min);
  float log_max = log10(max);
  float log_spacing = (log_max-log_min)/n_bins;

  for (size_t bin_it = 0; bin_it != n_bins; ++bin_it) {
    float this_bin_low_edge = min + std::pow(10, bin_it*log_spacing);
    bin_edges.push_back(this_bin_low_edge);
  }
  bin_edges.push_back(max);

  return bin_edges;
}

// -----------------------------------------------------------------------------
void PennSusyFrame::HistogramHandler::Fill( const PennSusyFrame::Event& event
                                          , const PennSusyFrame::EventLevelQuantities&
                                          , const std::vector<PennSusyFrame::Electron*>* el_list
                                          , const std::vector<PennSusyFrame::Muon*>* mu_list 
                                          , const std::vector<PennSusyFrame::Jet*>* jet_list
                                          , const PennSusyFrame::Met&
                                          , float
                                          )
{
  // do nothing

  /// ERASE THIS BEFORE COMMITTING!
  FLAVOR_CHANNEL fc = event.getFlavorChannel();
  double dr_lj00, dr_lj01, dr_lj10, dr_lj11;
  if (fc == FLAVOR_EE) {
    dr_lj00 = PennSusyFrame::getDr(el_list->at(0), jet_list->at(0));
    dr_lj01 = PennSusyFrame::getDr(el_list->at(0), jet_list->at(1));
    dr_lj10 = PennSusyFrame::getDr(el_list->at(1), jet_list->at(0));
    dr_lj11 = PennSusyFrame::getDr(el_list->at(1), jet_list->at(1));

    if (dr_lj00 < 0.4) {
      std::cout << "HI THERE! This is a low dR(e,j) event! "	\
		<< "\n\t dR(e,j) = " << dr_lj00				\
		<< "\n\t Number of leptons = " << el_list->size() \
		<< "\n\t Reco flavor channel = "  << "ee"		\
		<<  "\n";
    }
    if (dr_lj01 < 0.4) {
      std::cout << "HI THERE! This is a low dR(e,j) event! "\
		<< "\n\t dR(e,j) = " << dr_lj01 \
		<< "\n\t Number of leptons = " << el_list->size() \
		<< "\n\t Reco flavor channel = "  << "ee" \
		<<  "\n";
    }
    if (dr_lj10 < 0.4) {
      std::cout << "HI THERE! This is a low dR(e,j) event! "\
		<< "\n\t dR(e,j) = " << dr_lj10 \
		<< "\n\t Number of leptons = " << el_list->size() \
		<< "\n\t Reco flavor channel = "  << "ee" \
		<<  "\n";
    }
    if (dr_lj11 < 0.4) {
      std::cout << "HI THERE! This is a low dR(e,j) event! "\
		<< "\n\t dR(e,j) = " << dr_lj11 \
		<< "\n\t Number of leptons = " << el_list->size() \
		<< "\n\t Reco flavor channel = "  << "ee" \
		<<  "\n";
    }
  }

  else if (fc == FLAVOR_MM) {
    dr_lj00 = PennSusyFrame::getDr(mu_list->at(0), jet_list->at(0));
    dr_lj01 = PennSusyFrame::getDr(mu_list->at(0), jet_list->at(1));
    dr_lj10 = PennSusyFrame::getDr(mu_list->at(1), jet_list->at(0));
    dr_lj11 = PennSusyFrame::getDr(mu_list->at(1), jet_list->at(1));

    if (dr_lj00 < 0.4) {
      std::cout << "HI THERE! This is a low dR(m,j) event! "	\
		<< "\n\t dR(m,j) = " << dr_lj00 \
		<< "\n\t Number of leptons = " << mu_list->size() \
		<< "\n\t Reco flavor channel = "  << "mm"		\
		<<  "\n";
    }
    if (dr_lj01 < 0.4) {
      std::cout << "HI THERE! This is a low dR(m,j) event! "\
		<< "\n\t dR(m,j) = " << dr_lj01 \
		<< "\n\t Number of leptons = " << mu_list->size() \
		<< "\n\t Reco flavor channel = "  << "mm" \
		<<  "\n";
    }
    if (dr_lj10 < 0.4) {
      std::cout << "HI THERE! This is a low dR(m,j) event! "\
		<< "\n\t dR(m,j) = " << dr_lj10 \
		<< "\n\t Number of leptons = " << mu_list->size() \
		<< "\n\t Reco flavor channel = "  << "mm" \
		<<  "\n";
    }
    if (dr_lj11 < 0.4) {
      std::cout << "HI THERE! This is a low dR(m,j) event! "\
		<< "\n\t dR(m,j) = " << dr_lj11 \
		<< "\n\t Number of leptons = " << mu_list->size() \
		<< "\n\t Reco flavor channel = "  << "mm" \
		<<  "\n";
    }
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::HistogramHandler::write(TDirectory*)
{
  // do nothing
}

// =============================================================================
PennSusyFrame::EventLevelHists::EventLevelHists(std::string name_tag)
{
  TH1::SetDefaultSumw2(true);

  const int   mll_bins = 50;
  const float mll_min  = 0.;
  const float mll_max  = 1000.;

  const int   mt2_bins = 50;
  const float mt2_min  = 0.;
  const float mt2_max  = 500.;

  const int   ptll_bins = 50;
  const float ptll_min  = 0.;
  const float ptll_max  = 2000.;

  // const int   ht_bins = 100;
  const int   ht_bins = 50;
  const float ht_min  = 0;
  const float ht_max  = 5000;

  // loop over all flavor channels
  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    m_h_flavor_channel.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                            + "__flavor_channel"
                                            + "__"
                                            + name_tag
                                            ).c_str()
                                          , ( "Flavor Channel - "
                                            + FLAVOR_CHANNEL_STRINGS[fc_it]
                                            + "; Flavor Channel ; Entries"
                                            ).c_str()
                                          , FLAVOR_N, -0.5, FLAVOR_N - 0.5
                                          )
                                );
    for (int flavor_it = 0; flavor_it != FLAVOR_N; ++flavor_it) {
      m_h_flavor_channel.at(fc_it)->GetXaxis()->SetBinLabel( flavor_it+1
                                                           , FLAVOR_CHANNEL_STRINGS[flavor_it].c_str()
                                                           );
    }

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize mll histograms
    m_h_mll.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                 + "__mll"
                                 + "__"
                                 + name_tag
                                 ).c_str()
                               , ( "m_{ll} - "
                                 + FLAVOR_CHANNEL_STRINGS[fc_it]
                                 + " ; m_{ll} [GeV] ; Entries"
                                 ).c_str()
                               , mll_bins, mll_min, mll_max
                               )
                     );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize mt2 histograms
    m_h_mt2.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                 + "__mt2"
                                 + "__"
                                 + name_tag
                                 ).c_str()
                               , ( "m_{T2}^{0} - "
                                 + FLAVOR_CHANNEL_STRINGS[fc_it]
                                 + " ; m_{T2} [GeV] ; Entries"
                                 ).c_str()
                               , mt2_bins, mt2_min, mt2_max
                               )
                     );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize ptll histograms
    m_h_ptll.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                  + "__ptll"
                                  + "__"
                                  + name_tag
                                  ).c_str()
                                , ( "p_{T}^{ll} - "
                                  + FLAVOR_CHANNEL_STRINGS[fc_it]
                                  + " ; p_{T}^{ll} [GeV] ; Entries"
                                  ).c_str()
                                , ptll_bins, ptll_min, ptll_max
                                )
                      );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize ht histograms
    m_h_ht_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + "__ht_all"
                                    + "__"
                                    + name_tag
                                    ).c_str()
                                  , ( "H_{T}^{ll} - "
                                    + FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + " ; H_{T} [GeV] ; Entries"
                                    ).c_str()
                                  , ht_bins, ht_min, ht_max
                                  )
                        );

    m_h_ht_baseline.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + "__ht_baseline"
                                       + "__"
                                       + name_tag
                                       ).c_str()
                                     , ( "H_{T}^{ll} - "
                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + " ; H_{T} [GeV] ; Entries"
                                       ).c_str()
                                     , ht_bins, ht_min, ht_max
                                     )
                           );

    m_h_ht_good.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__ht_good"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "H_{T}^{ll} - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; H_{T} [GeV] ; Entries"
                                     ).c_str()
                                   , ht_bins, ht_min, ht_max
                                   )
                         );

    m_h_ht_signal.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + "__ht_signal"
                                       + "__"
                                       + name_tag
                                       ).c_str()
                                     , ( "H_{T}^{ll} - "
                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + " ; H_{T} [GeV] ; Entries"
                                       ).c_str()
                                     , ht_bins, ht_min, ht_max
                                     )
                           );
  }
}

// -----------------------------------------------------------------------------
PennSusyFrame::EventLevelHists::~EventLevelHists()
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::EventLevelHists::Fill( const PennSusyFrame::Event& event
                                         , const PennSusyFrame::EventLevelQuantities& event_level_quantities
                                         , const std::vector<PennSusyFrame::Electron*>*
                                         , const std::vector<PennSusyFrame::Muon*>*
                                         , const std::vector<PennSusyFrame::Jet*>*
                                         , const PennSusyFrame::Met&
                                         , float weight
                                         )
{
  FLAVOR_CHANNEL fc = event.getFlavorChannel();

  if (fc == FLAVOR_NONE) return;

  float mll = event_level_quantities.getMll()/1.e3;
  float mt2 = event_level_quantities.getMt2()/1.e3;

  float ptll = event_level_quantities.getPtll()/1.e3;

  float ht_all      = event_level_quantities.getHtAll()/1.e3;
  float ht_baseline = event_level_quantities.getHtBaseline()/1.e3;
  float ht_good     = event_level_quantities.getHtGood()/1.e3;
  float ht_signal   = event_level_quantities.getHtSignal()/1.e3;

  // loop over all flavor channels
  for (int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    if (fc_it != FLAVOR_NONE && fc_it != fc) continue;

    m_h_flavor_channel.at(fc_it)->Fill(fc);

    m_h_mll.at(fc_it)->Fill(mll, weight);
    m_h_mt2.at(fc_it)->Fill(mt2, weight);
    m_h_ptll.at(fc_it)->Fill(ptll, weight);
    m_h_ht_all.at(fc_it)->Fill(     ht_all     , weight);
    m_h_ht_baseline.at(fc_it)->Fill(ht_baseline, weight);
    m_h_ht_good.at(fc_it)->Fill(    ht_good    , weight);
    m_h_ht_signal.at(fc_it)->Fill(  ht_signal  , weight);
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::EventLevelHists::write(TDirectory* d)
{
  d->cd();

  // loop over all flavor channels
  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_flavor_channel.at(fc_it)->Write();

    // write mll histograms
    m_h_mll.at(fc_it)->Write();

    // write mt2 histograms
    m_h_mt2.at(fc_it)->Write();

    //write ptll histograms
    m_h_ptll.at(fc_it)->Write();

    //write ht histograms
    m_h_ht_all.at(fc_it)->Write();
    m_h_ht_baseline.at(fc_it)->Write();
    m_h_ht_good.at(fc_it)->Write();
    m_h_ht_signal.at(fc_it)->Write();
  }
}

// =============================================================================
PennSusyFrame::LeptonKinematicsHists::LeptonKinematicsHists(std::string name_tag)
{
  TH1::SetDefaultSumw2(true);

  const int   pt_bins = 2000;
  const float pt_min  = 0.;
  const float pt_max  = 2000.;

  const int   eta_bins = 50;
  const float eta_min = -5.;
  const float eta_max = +5.;

  const int   ptiso_bins = 30;
  const float ptiso_min  = 0.;
  const float ptiso_max  = 3.;

  const int   etiso_bins = 40;
  const float etiso_min  = -1.;
  const float etiso_max  = 3.;

  const int dr_bins = 60;
  const float dr_min = 0.;
  const float dr_max = 6.0;

  const int dphi_bins = 32;
  const float dphi_min = 0.;
  const float dphi_max = 3.2;

  const int deta_bins = 50;
  const float deta_min = 0.;
  const float deta_max = 5.0;

  // loop over all flavor channels
  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize pt histograms
    m_h_pt_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + "__lep_pt_all"
                                    + "__"
                                    + name_tag
                                    ).c_str()
                                  , ( "p_{T} - "
                                    + FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + " ; p_{T} [GeV] ; Entries"
                                    ).c_str()
                                  , pt_bins, pt_min, pt_max
                                  )
                        );

    m_h_pt_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                  + "__lep_pt_0"
                                  + "__"
                                  + name_tag
                                  ).c_str()
                                , ( "p_{T}^{0} - "
                                  + FLAVOR_CHANNEL_STRINGS[fc_it]
                                  + " ; p_{T}^{0} [GeV] ; Entries"
                                  ).c_str()
                                , pt_bins, pt_min, pt_max
                                )
                      );

    m_h_pt_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                  + "__lep_pt_1"
                                  + "__"
                                  + name_tag
                                  ).c_str()
                                , ( "p_{T}^{1} - "
                                  + FLAVOR_CHANNEL_STRINGS[fc_it]
                                  + " ; p_{T}^{1} [GeV] ; Entries"
                                  ).c_str()
                                , pt_bins, pt_min, pt_max
                                )
                      );
    m_h_raw_pt_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + "__lep_raw_pt_all"
                                    + "__"
                                    + name_tag
                                    ).c_str()
                                  , ( "p_{T} - "
                                    + FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + " ; p_{T} [GeV] ; Entries"
                                    ).c_str()
                                  , pt_bins, pt_min, pt_max
                                  )
                        );

    m_h_raw_pt_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                  + "__lep_raw_pt_0"
                                 + "__"
                                 + name_tag
                                  ).c_str()
                                , ( "p_{T}^{0} - "
                                  + FLAVOR_CHANNEL_STRINGS[fc_it]
                                  + " ; p_{T}^{0} [GeV] ; Entries"
                                  ).c_str()
                                , pt_bins, pt_min, pt_max
                                )
                      );

    m_h_raw_pt_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                  + "__lep_raw_pt_1"
                                  + "__"
                                  + name_tag
                                  ).c_str()
                                , ( "p_{T}^{1} - "
                                  + FLAVOR_CHANNEL_STRINGS[fc_it]
                                  + " ; p_{T}^{1} [GeV] ; Entries"
                                  ).c_str()
                                , pt_bins, pt_min, pt_max
                                )
                      );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize eta histograms
    m_h_eta_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + "__lep_eta_all"
                                    + "__"
                                    + name_tag
                                    ).c_str()
                                  , ( "#eta - "
                                    + FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + " ; #eta ; Entries"
                                    ).c_str()
                                  , eta_bins, eta_min, eta_max
                                  )
                        );

    m_h_eta_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                  + "__lep_eta_0"
                                 + "__"
                                 + name_tag
                                  ).c_str()
                                , ( "#eta^{0} - "
                                  + FLAVOR_CHANNEL_STRINGS[fc_it]
                                  + " ; #eta^{0} [GeV] ; Entries"
                                  ).c_str()
                                , eta_bins, eta_min, eta_max
                                )
                      );

    m_h_eta_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                  + "__lep_eta_1"
                                  + "__"
                                  + name_tag
                                  ).c_str()
                                , ( "#eta^{1} - "
                                  + FLAVOR_CHANNEL_STRINGS[fc_it]
                                  + " ; #eta^{1} [GeV] ; Entries"
                                  ).c_str()
                                , eta_bins, eta_min, eta_max
                                )
                      );
    m_h_eta_event_passfail.push_back( new TH1F( (FLAVOR_CHANNEL_STRINGS[fc_it]
						     +   "__lep_eta_event_passfail"
						     + "__"
						     + name_tag
						     ).c_str()
						    ,("|#eta| < 2.4 cut - "
						      + FLAVOR_CHANNEL_STRINGS[fc_it]
						      + " ; Fail (0), Pass(1) ; Entries"
						      ).c_str()
						    , 2, 0.,2.
						    )
					  );


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize pt iso histograms
    m_h_ptiso_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + "__lep_ptiso_all"
                                       + "__"
                                       + name_tag
                                       ).c_str()
                                     , ( "p_{T}^{cone30}/p_{T} - "
                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + " ; p_{T}^{cone30}/p_{T} ; Entries"
                                       ).c_str()
                                     , ptiso_bins, ptiso_min, ptiso_max
                                     )
                           );

    m_h_ptiso_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__lep_ptiso_0"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "p_{T}^{cone30,0}/p_{T} - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; p_{T}^{cone30,0}/p_{T} ; Entries"
                                     ).c_str()
                                   , ptiso_bins, ptiso_min, ptiso_max
                                   )
                         );

    m_h_ptiso_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__lep_ptiso_1"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "p_{T}^{cone30,1}/p_{T} - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; p_{T}^{cone30,1}/p_{T} ; Entries"
                                     ).c_str()
                                   , ptiso_bins, ptiso_min, ptiso_max
                                   )
                         );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize et iso histograms
    m_h_etiso_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + "__lep_etiso_all"
                                       + "__"
                                       + name_tag
                                       ).c_str()
                                     , ( "E_{T}^{cone30}/p_{T} - "
                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + " ; E_{T}^{cone30}/p_{T} ; Entries"
                                       ).c_str()
                                     , etiso_bins, etiso_min, etiso_max
                                     )
                           );

    m_h_etiso_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__lep_etiso_0"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "E_{T}^{cone30,0}/p_{T} - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; E_{T}^{cone30,0}/p_{T} ; Entries"
                                     ).c_str()
                                   , etiso_bins, etiso_min, etiso_max
                                   )
                         );

    m_h_etiso_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__lep_etiso_1"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "E_{T}^{cone30,1}/p_{T} - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; E_{T}^{cone30,1}/p_{T} ; Entries"
                                     ).c_str()
                                   , etiso_bins, etiso_min, etiso_max
                                   )
                         );


    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_dr_ll.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                   + "__lep_dr_ll"
                                   + "__"
                                   + name_tag
                                   ).c_str()
                                 , ( "#deltaR(l,l) - "
                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
                                   + " ; #deltaR(l,l) ; Entries"
                                   ).c_str()
                                 , dr_bins, dr_min, dr_max
                                 )
                       );

    m_h_dphi_ll.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__lep_dphi_ll"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "#delta#phi(l,l) - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; #delta#phi(l,l) ; Entries"
                                     ).c_str()
                                   , dphi_bins, dphi_min, dphi_max
                                   )
                         );

    m_h_deta_ll.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__lep_deta_ll"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "#delta#eta(l,l) - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; #delta#eta(l,l) ; Entries"
                                     ).c_str()
                                   , deta_bins, deta_min, deta_max
                                   )
                         );


    // -------------------------------------------------------------------------
    // initialize fiducial pass,fail histos
    m_h_fiducial_single_pass.push_back( new TH1F( (FLAVOR_CHANNEL_STRINGS[fc_it]
						   + "__lep_fiducial_single_pass"
						   + "__"
						   + name_tag
						   ).c_str()
						  ,("p_{T}_lep_all - |#eta| < 2.4 - "
						    + FLAVOR_CHANNEL_STRINGS[fc_it]
						    + " ; p_{T} [GeV] ; Entries"
						    ).c_str()
						  ,pt_bins, pt_min, pt_max
						  )
					);
    m_h_fiducial_single_fail.push_back( new TH1F( (FLAVOR_CHANNEL_STRINGS[fc_it]
						   + "__lep_fiducial_single_fail"
						   + "__"
						   + name_tag
						   ).c_str()
						  ,("p_{T}_lep_all - |#eta| >= 2.4 - "
						    + FLAVOR_CHANNEL_STRINGS[fc_it]
						    + " ; p_{T} [GeV] ; Entries"
						    ).c_str()
						  ,pt_bins, pt_min, pt_max
						  )
					);

    m_h_fiducial_event_pass.push_back( new TH1F( (FLAVOR_CHANNEL_STRINGS[fc_it]
						  + "__lep_fiducial_event_pass"
						  + "__"
						  + name_tag
						  ).c_str()
						 ,("p_{T}_lep_1 - |#eta| < 2.4 - "
						   + FLAVOR_CHANNEL_STRINGS[fc_it]
						   + " ; p_{T} [GeV] ; Entries"
						   ).c_str()
						 ,pt_bins, pt_min, pt_max
						 )
				       );
    m_h_fiducial_event_fail.push_back( new TH1F( (FLAVOR_CHANNEL_STRINGS[fc_it]
						  + "__lep_fiducial_event_fail"
						  + "__"
						  + name_tag
						  ).c_str()
						 ,("p_{T}_lep_1 - |#eta| >= 2.4 - "
						   + FLAVOR_CHANNEL_STRINGS[fc_it]
						   + " ; p_{T} [GeV] ; Entries"
						   ).c_str()
						 ,pt_bins, pt_min, pt_max
						 )
				       );
  }
}

// -----------------------------------------------------------------------------
PennSusyFrame::LeptonKinematicsHists::~LeptonKinematicsHists()
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::LeptonKinematicsHists::Fill( const PennSusyFrame::Event& event
                                               , const PennSusyFrame::EventLevelQuantities&
                                               , const std::vector<PennSusyFrame::Electron*>* el_list
                                               , const std::vector<PennSusyFrame::Muon*>* mu_list
                                               , const std::vector<PennSusyFrame::Jet*>*
                                               , const PennSusyFrame::Met&
                                               , float weight
                                               )
{
  FLAVOR_CHANNEL fc = event.getFlavorChannel();

  if (fc == FLAVOR_NONE) return;

  float pt_0 = 0.;
  float pt_1 = 0.;

  float ptiso_0 = 0.;
  float ptiso_1 = 0.;

  float etiso_0 = 0.;
  float etiso_1 = 0.;

  float phi_0 = 0.;
  float phi_1 = 0.;
  float dphi  = 0.;

  float eta_0 = 0.;
  float eta_1 = 0.;
  float deta  = 0.;

  float dr  = 0.;


  // TODO fill these histograms in cleaner way!

  if (fc == FLAVOR_EE) {
    pt_0 = el_list->at(0)->getPt()/1.e3;
    pt_1 = el_list->at(1)->getPt()/1.e3;

    eta_0 = el_list->at(0)->getEta();
    eta_1 = el_list->at(1)->getEta();

    ptiso_0 = el_list->at(0)->getPtIsoRatio();
    ptiso_1 = el_list->at(1)->getPtIsoRatio();

    etiso_0 = el_list->at(0)->getEtIsoRatio();
    etiso_1 = el_list->at(1)->getEtIsoRatio();

    phi_0 = el_list->at(0)->getPhi();
    phi_1 = el_list->at(1)->getPhi();
    dphi = PennSusyFrame::calcDphi(phi_0, phi_1);

    eta_0 = el_list->at(0)->getEta();
    eta_1 = el_list->at(1)->getEta();
    deta = fabs(eta_0 - eta_1);

    dr = sqrt(dphi*dphi + deta*deta);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_pt_all.at(FLAVOR_EE)->Fill(pt_0, weight);
    m_h_pt_all.at(FLAVOR_EE)->Fill(pt_1, weight);
    m_h_pt_0.at(  FLAVOR_EE)->Fill(pt_0, weight);
    m_h_pt_1.at(  FLAVOR_EE)->Fill(pt_1, weight);

    m_h_raw_pt_all.at(FLAVOR_EE)->Fill(pt_0);
    m_h_raw_pt_all.at(FLAVOR_EE)->Fill(pt_1);
    m_h_raw_pt_0.at(  FLAVOR_EE)->Fill(pt_0);
    m_h_raw_pt_1.at(  FLAVOR_EE)->Fill(pt_1);

    m_h_eta_all.at(FLAVOR_EE)->Fill(eta_0, weight);
    m_h_eta_all.at(FLAVOR_EE)->Fill(eta_1, weight);
    m_h_eta_0.at(  FLAVOR_EE)->Fill(eta_0, weight);
    m_h_eta_1.at(  FLAVOR_EE)->Fill(eta_1, weight);
    (pass(eta_0, eta_1) ? m_h_eta_event_passfail.at(FLAVOR_EE)->Fill(1., weight) :
                          m_h_eta_event_passfail.at(FLAVOR_EE)->Fill(0., weight));

    m_h_ptiso_all.at(FLAVOR_EE)->Fill(ptiso_0, weight);
    m_h_ptiso_all.at(FLAVOR_EE)->Fill(ptiso_1, weight);
    m_h_ptiso_0.at(  FLAVOR_EE)->Fill(ptiso_0, weight);
    m_h_ptiso_1.at(  FLAVOR_EE)->Fill(ptiso_1, weight);

    m_h_etiso_all.at(FLAVOR_EE)->Fill(etiso_0, weight);
    m_h_etiso_all.at(FLAVOR_EE)->Fill(etiso_1, weight);
    m_h_etiso_0.at(  FLAVOR_EE)->Fill(etiso_0, weight);
    m_h_etiso_1.at(  FLAVOR_EE)->Fill(etiso_1, weight);

    m_h_dr_ll.at(FLAVOR_EE)->Fill(dr, weight);
    m_h_dphi_ll.at(FLAVOR_EE)->Fill(dphi, weight);
    m_h_deta_ll.at(FLAVOR_EE)->Fill(deta, weight);

    (abs(eta_0) < 2.4 ? m_h_fiducial_single_pass.at(FLAVOR_EE)->Fill(pt_0, weight) :
                        m_h_fiducial_single_fail.at(FLAVOR_EE)->Fill(pt_0, weight));
    (abs(eta_1) < 2.4 ? m_h_fiducial_single_pass.at(FLAVOR_EE)->Fill(pt_1, weight) :
                        m_h_fiducial_single_fail.at(FLAVOR_EE)->Fill(pt_1, weight));
    (pass(eta_0, eta_1) ? m_h_fiducial_event_pass.at(FLAVOR_EE)->Fill(pt_1, weight) :
                          m_h_fiducial_event_fail.at(FLAVOR_EE)->Fill(pt_1, weight));
  }

  else if (fc == FLAVOR_MM) {
    pt_0 = mu_list->at(0)->getPt()/1.e3;
    pt_1 = mu_list->at(1)->getPt()/1.e3;

    eta_0 = mu_list->at(0)->getEta();
    eta_1 = mu_list->at(1)->getEta();

    ptiso_0 = mu_list->at(0)->getPtIsoRatio();
    ptiso_1 = mu_list->at(1)->getPtIsoRatio();

    etiso_0 = mu_list->at(0)->getEtIsoRatio();
    etiso_1 = mu_list->at(1)->getEtIsoRatio();

    phi_0 = mu_list->at(0)->getPhi();
    phi_1 = mu_list->at(1)->getPhi();
    dphi = PennSusyFrame::calcDphi(phi_0, phi_1);

    eta_0 = mu_list->at(0)->getEta();
    eta_1 = mu_list->at(1)->getEta();
    deta = fabs(eta_0 - eta_1);

    dr = sqrt(dphi*dphi + deta*deta);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_pt_all.at(FLAVOR_MM)->Fill(pt_0, weight);
    m_h_pt_all.at(FLAVOR_MM)->Fill(pt_1, weight);
    m_h_pt_0.at(  FLAVOR_MM)->Fill(pt_0, weight);
    m_h_pt_1.at(  FLAVOR_MM)->Fill(pt_1, weight);

    m_h_raw_pt_all.at(FLAVOR_MM)->Fill(pt_0);
    m_h_raw_pt_all.at(FLAVOR_MM)->Fill(pt_1);
    m_h_raw_pt_0.at(  FLAVOR_MM)->Fill(pt_0);
    m_h_raw_pt_1.at(  FLAVOR_MM)->Fill(pt_1);

    m_h_eta_all.at(FLAVOR_MM)->Fill(eta_0, weight);
    m_h_eta_all.at(FLAVOR_MM)->Fill(eta_1, weight);
    m_h_eta_0.at(  FLAVOR_MM)->Fill(eta_0, weight);
    m_h_eta_1.at(  FLAVOR_MM)->Fill(eta_1, weight);

    (pass(eta_0, eta_1) ? m_h_eta_event_passfail.at(FLAVOR_MM)->Fill(1., weight) :
                          m_h_eta_event_passfail.at(FLAVOR_MM)->Fill(0., weight));

    m_h_ptiso_all.at(FLAVOR_MM)->Fill(ptiso_0, weight);
    m_h_ptiso_all.at(FLAVOR_MM)->Fill(ptiso_1, weight);
    m_h_ptiso_0.at(  FLAVOR_MM)->Fill(ptiso_0, weight);
    m_h_ptiso_1.at(  FLAVOR_MM)->Fill(ptiso_1, weight);

    m_h_etiso_all.at(FLAVOR_MM)->Fill(etiso_0, weight);
    m_h_etiso_all.at(FLAVOR_MM)->Fill(etiso_1, weight);
    m_h_etiso_0.at(  FLAVOR_MM)->Fill(etiso_0, weight);
    m_h_etiso_1.at(  FLAVOR_MM)->Fill(etiso_1, weight);

    m_h_dr_ll.at(FLAVOR_MM)->Fill(dr, weight);
    m_h_dphi_ll.at(FLAVOR_MM)->Fill(dphi, weight);
    m_h_deta_ll.at(FLAVOR_MM)->Fill(deta, weight);

    (abs(eta_0) < 2.4 ? m_h_fiducial_single_pass.at(FLAVOR_MM)->Fill(pt_0, weight) :
                        m_h_fiducial_single_fail.at(FLAVOR_MM)->Fill(pt_0, weight));
    (abs(eta_1) < 2.4 ? m_h_fiducial_single_pass.at(FLAVOR_MM)->Fill(pt_1, weight) :
                        m_h_fiducial_single_fail.at(FLAVOR_MM)->Fill(pt_1, weight));
    (pass(eta_0, eta_1) ? m_h_fiducial_event_pass.at(FLAVOR_MM)->Fill(pt_1, weight) :
                          m_h_fiducial_event_fail.at(FLAVOR_MM)->Fill(pt_1, weight));

  }
  else {
    pt_0 = el_list->at(0)->getPt()/1.e3;
    pt_1 = mu_list->at(0)->getPt()/1.e3;

    if (pt_0 < pt_1) {
      float tmp = pt_0;
      pt_0 = pt_1;
      pt_1 = tmp;
    }

    eta_0 = el_list->at(0)->getEta();
    eta_1 = mu_list->at(0)->getEta();

    ptiso_0 = el_list->at(0)->getPtIsoRatio();
    ptiso_1 = mu_list->at(0)->getPtIsoRatio();

    etiso_0 = el_list->at(0)->getEtIsoRatio();
    etiso_1 = mu_list->at(0)->getEtIsoRatio();

    phi_0 = el_list->at(0)->getPhi();
    phi_1 = mu_list->at(0)->getPhi();
    dphi = PennSusyFrame::calcDphi(phi_0, phi_1);

    eta_0 = el_list->at(0)->getEta();
    eta_1 = mu_list->at(0)->getEta();
    deta = fabs(eta_0 - eta_1);

    dr = sqrt(dphi*dphi + deta*deta);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_pt_all.at(FLAVOR_EM)->Fill(pt_0, weight);
    m_h_pt_all.at(FLAVOR_EM)->Fill(pt_1, weight);
    m_h_pt_0.at(  FLAVOR_EM)->Fill(pt_0, weight);
    m_h_pt_1.at(  FLAVOR_EM)->Fill(pt_1, weight);

    m_h_raw_pt_all.at(FLAVOR_EM)->Fill(pt_0);
    m_h_raw_pt_all.at(FLAVOR_EM)->Fill(pt_1);
    m_h_raw_pt_0.at(  FLAVOR_EM)->Fill(pt_0);
    m_h_raw_pt_1.at(  FLAVOR_EM)->Fill(pt_1);

    m_h_eta_all.at(FLAVOR_EM)->Fill(eta_0, weight);
    m_h_eta_all.at(FLAVOR_EM)->Fill(eta_1, weight);
    m_h_eta_0.at(  FLAVOR_EM)->Fill(eta_0, weight);
    m_h_eta_1.at(  FLAVOR_EM)->Fill(eta_1, weight);
    
    (pass(eta_0, eta_1) ? m_h_eta_event_passfail.at(FLAVOR_EM)->Fill(1., weight) :
     m_h_eta_event_passfail.at(FLAVOR_EM)->Fill(0., weight));

    m_h_ptiso_all.at(FLAVOR_EM)->Fill(ptiso_0, weight);
    m_h_ptiso_all.at(FLAVOR_EM)->Fill(ptiso_1, weight);
    m_h_ptiso_0.at(  FLAVOR_EM)->Fill(ptiso_0, weight);
    m_h_ptiso_1.at(  FLAVOR_EM)->Fill(ptiso_1, weight);

    m_h_etiso_all.at(FLAVOR_EM)->Fill(etiso_0, weight);
    m_h_etiso_all.at(FLAVOR_EM)->Fill(etiso_1, weight);
    m_h_etiso_0.at(  FLAVOR_EM)->Fill(etiso_0, weight);
    m_h_etiso_1.at(  FLAVOR_EM)->Fill(etiso_1, weight);

    m_h_dr_ll.at(FLAVOR_MM)->Fill(dr, weight);
    m_h_dphi_ll.at(FLAVOR_MM)->Fill(dphi, weight);
    m_h_deta_ll.at(FLAVOR_MM)->Fill(deta, weight);

    (abs(eta_0) < 2.4 ? m_h_fiducial_single_pass.at(FLAVOR_EM)->Fill(pt_0, weight) :
                        m_h_fiducial_single_fail.at(FLAVOR_EM)->Fill(pt_0, weight));
    (abs(eta_1) < 2.4 ? m_h_fiducial_single_pass.at(FLAVOR_EM)->Fill(pt_1, weight) :
                        m_h_fiducial_single_fail.at(FLAVOR_EM)->Fill(pt_1, weight));
    (pass(eta_0, eta_1) ? m_h_fiducial_event_pass.at(FLAVOR_EM)->Fill(pt_1, weight) :
                          m_h_fiducial_event_fail.at(FLAVOR_EM)->Fill(pt_1, weight));

  }

  if (pt_1 > pt_0) {
    float pt_tmp = pt_0;
    pt_0 = pt_1;
    pt_1 = pt_tmp;

    float ptiso_tmp = ptiso_0;
    ptiso_0 = ptiso_1;
    ptiso_1 = ptiso_tmp;

    float etiso_tmp = etiso_0;
    etiso_0 = etiso_1;
    etiso_1 = etiso_tmp;
  }

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  m_h_pt_all.at(FLAVOR_NONE)->Fill(pt_0, weight);
  m_h_pt_all.at(FLAVOR_NONE)->Fill(pt_1, weight);
  m_h_pt_0.at(  FLAVOR_NONE)->Fill(pt_0, weight);
  m_h_pt_1.at(  FLAVOR_NONE)->Fill(pt_1, weight);

  m_h_raw_pt_all.at(FLAVOR_NONE)->Fill(pt_0);
  m_h_raw_pt_all.at(FLAVOR_NONE)->Fill(pt_1);
  m_h_raw_pt_0.at(  FLAVOR_NONE)->Fill(pt_0);
  m_h_raw_pt_1.at(  FLAVOR_NONE)->Fill(pt_1);

  m_h_eta_all.at(FLAVOR_NONE)->Fill(eta_0, weight);
  m_h_eta_all.at(FLAVOR_NONE)->Fill(eta_1, weight);
  m_h_eta_0.at(  FLAVOR_NONE)->Fill(eta_0, weight);
  m_h_eta_1.at(  FLAVOR_NONE)->Fill(eta_1, weight);

  (pass(eta_0, eta_1) ? m_h_eta_event_passfail.at(FLAVOR_NONE)->Fill(1., weight) :
   m_h_eta_event_passfail.at(FLAVOR_NONE)->Fill(0., weight));
  
  m_h_ptiso_all.at(FLAVOR_NONE)->Fill(ptiso_0, weight);
  m_h_ptiso_all.at(FLAVOR_NONE)->Fill(ptiso_1, weight);
  m_h_ptiso_0.at(  FLAVOR_NONE)->Fill(ptiso_0, weight);
  m_h_ptiso_1.at(  FLAVOR_NONE)->Fill(ptiso_1, weight);

  m_h_etiso_all.at(FLAVOR_NONE)->Fill(etiso_0, weight);
  m_h_etiso_all.at(FLAVOR_NONE)->Fill(etiso_1, weight);
  m_h_etiso_0.at(  FLAVOR_NONE)->Fill(etiso_0, weight);
  m_h_etiso_1.at(  FLAVOR_NONE)->Fill(etiso_1, weight);

  m_h_dr_ll.at(FLAVOR_NONE)->Fill(dr, weight);
  m_h_dphi_ll.at(FLAVOR_NONE)->Fill(dphi, weight);
  m_h_deta_ll.at(FLAVOR_NONE)->Fill(deta, weight);

  (abs(eta_0) < 2.4 ? m_h_fiducial_single_pass.at(FLAVOR_NONE)->Fill(pt_0, weight) :
                      m_h_fiducial_single_fail.at(FLAVOR_NONE)->Fill(pt_0, weight));
  (abs(eta_1) < 2.4 ? m_h_fiducial_single_pass.at(FLAVOR_NONE)->Fill(pt_1, weight) :
                      m_h_fiducial_single_fail.at(FLAVOR_NONE)->Fill(pt_1, weight));
  (pass(eta_0, eta_1) ? m_h_fiducial_event_pass.at(FLAVOR_NONE)->Fill(pt_1, weight) :
                        m_h_fiducial_event_fail.at(FLAVOR_NONE)->Fill(pt_1, weight));

}

// -----------------------------------------------------------------------------
bool PennSusyFrame::LeptonKinematicsHists::pass(float eta_0, float eta_1)
{
  if (abs(eta_0) < 2.4 && abs(eta_1) < 2.4) {
    return 1;
  }
  else {
    return 0;
  }
}
// -----------------------------------------------------------------------------
void PennSusyFrame::LeptonKinematicsHists::write(TDirectory* d)
{
  d->cd();

  // loop over all flavor channels
  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // write pt histograms
    m_h_pt_all.at(fc_it)->Write();
    m_h_pt_0.at(  fc_it)->Write();
    m_h_pt_1.at(  fc_it)->Write();

    m_h_raw_pt_all.at(fc_it)->Write();
    m_h_raw_pt_0.at(  fc_it)->Write();
    m_h_raw_pt_1.at(  fc_it)->Write();

    // write eta histograms
    m_h_eta_all.at(fc_it)->Write();
    m_h_eta_0.at(  fc_it)->Write();
    m_h_eta_1.at(  fc_it)->Write();
    m_h_eta_event_passfail.at(fc_it)->Write();

    // write ptiso histograms
    m_h_ptiso_all.at(fc_it)->Write();
    m_h_ptiso_0.at(  fc_it)->Write();
    m_h_ptiso_1.at(  fc_it)->Write();

    // write etiso histograms
    m_h_etiso_all.at(fc_it)->Write();
    m_h_etiso_0.at(  fc_it)->Write();
    m_h_etiso_1.at(  fc_it)->Write();

    // write dr_ll/dphi_ll/deta_ll histograms
    m_h_dr_ll.at(fc_it)->Write();
    m_h_dphi_ll.at(fc_it)->Write();
    m_h_deta_ll.at(fc_it)->Write();

    // write fiducial histograms
    m_h_fiducial_single_pass.at(fc_it)->Write();
    m_h_fiducial_single_fail.at(fc_it)->Write();
    m_h_fiducial_event_pass.at(fc_it)->Write();
    m_h_fiducial_event_fail.at(fc_it)->Write();
  }
}

// =============================================================================
PennSusyFrame::JetKinematicsHists::JetKinematicsHists(std::string name_tag)
{
  TH1::SetDefaultSumw2(true);

  const int   num_jet_bins = 10;
  const float num_jet_min  = -0.5;
  const float num_jet_max  = num_jet_bins + num_jet_min;

  const int   pt_bins = 2000;
  const float pt_min  = 0.;
  const float pt_max  = 2000.;

  const int dr_bins = 60;
  const float dr_min = 0.;
  const float dr_max = 6.0;

  const int dphi_bins = 32;
  const float dphi_min = 0.;
  const float dphi_max = 3.2;

  const int deta_bins = 50;
  const float deta_min = 0.;
  const float deta_max = 5.0;

  const int   eta_bins = 50;
  const float eta_min = -5.;
  const float eta_max = -5.;

  // loop over all flavor channels
  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize pt histograms
    m_h_num_jet.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__num_jet"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "Jet multiplicity - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; Jet multiplicity ; Entries"
                                     ).c_str()
                                   , num_jet_bins, num_jet_min, num_jet_max
                                   )
                         );

    m_h_pt_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + "__jet_pt_all"
                                    + "__"
                                    + name_tag
                                    ).c_str()
                                  , ( "p_{T} - "
                                    + FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + " ; p_{T} [GeV] ; Entries"
                                    ).c_str()
                                  , pt_bins, pt_min, pt_max
                                  )
                        );

    m_h_pt_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                  + "__jet_pt_0"
                                  + "__"
                                  + name_tag
                                  ).c_str()
                                , ( "p_{T}^{0} - "
                                  + FLAVOR_CHANNEL_STRINGS[fc_it]
                                  + " ; p_{T}^{0} [GeV] ; Entries"
                                  ).c_str()
                                , pt_bins, pt_min, pt_max
                                )
                      );

    m_h_pt_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                  + "__jet_pt_1"
                                  + "__"
                                  + name_tag
                                  ).c_str()
                                , ( "p_{T}^{1} - "
                                  + FLAVOR_CHANNEL_STRINGS[fc_it]
                                  + " ; p_{T}^{1} [GeV] ; Entries"
                                  ).c_str()
                                , pt_bins, pt_min, pt_max
                                )
                      );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_dr_jj.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__jet_dr_jj"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "#delta#R(j,j) - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; #delta#R(j,j) ; Entries"
                                     ).c_str()
                                   , dr_bins, dr_min, dr_max
                                   )
                         );
    m_h_dphi_jj.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__jet_dphi_jj"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "#delta#phi(j,j) - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; #delta#phi(j,j) ; Entries"
                                     ).c_str()
                                   , dphi_bins, dphi_min, dphi_max
                                   )
                         );
    m_h_deta_jj.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__jet_deta_jj"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "#delta#eta(j,j) - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; #delta#eta(j,j) ; Entries"
                                     ).c_str()
                                   , deta_bins, deta_min, deta_max
                                   )
                         );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize eta histograms
    m_h_eta_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__jet_eta_all"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "#eta - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; #eta ; Entries"
                                     ).c_str()
                                   , eta_bins, eta_min, eta_max
                                   )
                         );

    m_h_eta_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                   + "__jet_eta_0"
                                   + "__"
                                   + name_tag
                                   ).c_str()
                                 , ( "#eta^{0} - "
                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
                                   + " ; #eta^{0} [GeV] ; Entries"
                                   ).c_str()
                                 , eta_bins, eta_min, eta_max
                                 )
                       );

    m_h_eta_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                   + "__jet_eta_1"
                                   + "__"
                                   + name_tag
                                   ).c_str()
                                 , ( "#eta^{1} - "
                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
                                   + " ; #eta^{1} [GeV] ; Entries"
                                   ).c_str()
                                 , eta_bins, eta_min, eta_max
                                 )
                      );
    m_h_eta_event_passfail.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                +   "__jet_eta_event_passfail"
                                                + "__"
                                                + name_tag
                                                ).c_str()
                                              , ( "|#eta| < 2.4 cut - "
                                                + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                + " ; Fail (0), Pass(1) ; Entries"
                                                ).c_str()
                                              , 2, 0.,2.
                                              )
                                    );
    // -------------------------------------------------------------------------
    // initialize fiducial pass,fail histos
    m_h_fiducial_single_pass.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                  + "__jet_fiducial_single_pass"
                                                  + "__"
                                                  + name_tag
                                                  ).c_str()
                                                , ( "p_{T}_jet_all - |#eta| < 2.4 - "
                                                  + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                  + " ; p_{T} [GeV] ; Entries"
                                                  ).c_str()
                                                , pt_bins, pt_min, pt_max
                                                )
                                      );
    m_h_fiducial_single_fail.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                  + "__jet_fiducial_single_fail"
                                                  + "__"
                                                  + name_tag
                                                  ).c_str()
                                                , ( "p_{T}_jet_all - |#eta| >= 2.4 - "
                                                  + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                  + " ; p_{T} [GeV] ; Entries"
                                                  ).c_str()
                                                , pt_bins, pt_min, pt_max
                                                )
                                      );
    m_h_fiducial_event_pass.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + "__jet_fiducial_event_pass"
                                                 + "__"
                                                 + name_tag
                                                 ).c_str()
                                               , ( "p_{T}_lep_1 - |#eta| < 2.4 - "
                                                 + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + " ; p_{T} [GeV] ; Entries"
                                                 ).c_str()
                                               ,pt_bins, pt_min, pt_max
                                               )
                                     );
    m_h_fiducial_event_fail.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + "__jet_fiducial_event_fail"
                                                 + "__"
                                                 + name_tag
                                                 ).c_str()
                                               , ( "p_{T}_lep_1 - |#eta| >= 2.4 - "
                                                 + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + " ; p_{T} [GeV] ; Entries"
                                                 ).c_str()
                                               , pt_bins, pt_min, pt_max
                                               )
                                     );
  }
}

// -----------------------------------------------------------------------------
PennSusyFrame::JetKinematicsHists::~JetKinematicsHists()
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::JetKinematicsHists::Fill( const PennSusyFrame::Event& event
                                            , const PennSusyFrame::EventLevelQuantities&
                                            , const std::vector<PennSusyFrame::Electron*>*
                                            , const std::vector<PennSusyFrame::Muon*>*
                                            , const std::vector<PennSusyFrame::Jet*>* jet_list
                                            , const PennSusyFrame::Met&
                                            , float weight
                                            )
{
  FLAVOR_CHANNEL fc = event.getFlavorChannel();

  if (fc == FLAVOR_NONE) return;

  size_t num_jet = jet_list->size();

  float pt_0 = 0.;
  float pt_1 = 0.;

  float phi_0 = 0.;
  float phi_1 = 0.;
  float dphi = 0.;

  float eta_0 = 0.;
  float eta_1 = 0.;
  float deta = 0.;

  float dr = 0.;

  if (num_jet > 0) {
    pt_0 = jet_list->at(0)->getPt()/1.e3;
    phi_0 = jet_list->at(0)->getPhi();
    eta_0 = jet_list->at(0)->getEta();
  }
  if (num_jet > 1) {
    pt_1 = jet_list->at(1)->getPt()/1.e3;
    phi_1 = jet_list->at(1)->getPhi();
    eta_1 = jet_list->at(1)->getEta();
    dphi = PennSusyFrame::calcDphi(phi_0, phi_1);
    deta = fabs(eta_0 - eta_1);
    dr = sqrt(dphi*dphi + deta*deta);
  }

  eta_0 = ( num_jet > 0 ? jet_list->at(0)->getEta() : 0.);
  eta_1 = ( num_jet > 1 ? jet_list->at(1)->getEta() : 0.);

  // loop over all flavor channels
  for (int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    if (fc_it != FLAVOR_NONE && fc_it != fc) continue;

    m_h_num_jet.at(fc_it)->Fill(num_jet, weight);

    //
    for (size_t jet_it = 0; jet_it != num_jet; ++jet_it) {
      m_h_pt_all.at(fc_it)->Fill(jet_list->at(jet_it)->getPt()/1.e3, weight);
    }
    // m_h_pt_all.at( fc_it)->Fill(pt_0, weight);
    // m_h_pt_all.at( fc_it)->Fill(pt_1, weight);

    if (num_jet > 0) {
      m_h_pt_0.at(fc_it)->Fill(pt_0, weight);
    }
    if (num_jet > 1) {
      m_h_pt_1.at(fc_it)->Fill(pt_1, weight);
      m_h_dr_jj.at(fc_it)->Fill(dr, weight);
      m_h_dphi_jj.at(fc_it)->Fill(dphi, weight);
      m_h_deta_jj.at(fc_it)->Fill(deta, weight);
    }

    m_h_pt_all.at( fc_it)->Fill(pt_0, weight);
    m_h_pt_all.at( fc_it)->Fill(pt_1, weight);
    m_h_pt_0.at(   fc_it)->Fill(pt_0, weight);
    m_h_pt_1.at(   fc_it)->Fill(pt_1, weight);

    m_h_eta_all.at(fc_it)->Fill(eta_0, weight);
    m_h_eta_all.at(fc_it)->Fill(eta_1, weight);
    m_h_eta_0.at(  fc_it)->Fill(eta_0, weight);
    m_h_eta_1.at(  fc_it)->Fill(eta_1, weight);

    (pass(eta_0, eta_1) ? (m_h_eta_event_passfail.at(fc_it)->Fill(1., weight)) :
     (m_h_eta_event_passfail.at(fc_it)->Fill(0., weight)));

    (abs(eta_0) < 2.4 ? (m_h_fiducial_single_pass.at(fc_it)->Fill(pt_0, weight)) :
     (m_h_fiducial_single_fail.at(fc_it)->Fill(pt_0, weight)));

    (abs(eta_1) < 2.4 ? (m_h_fiducial_single_pass.at(fc_it)->Fill(pt_1, weight)) :
     (m_h_fiducial_single_fail.at(fc_it)->Fill(pt_1, weight)));

    (pass(eta_0, eta_1) ? m_h_fiducial_event_pass.at(fc_it)->Fill(pt_1, weight) :
     m_h_fiducial_event_fail.at(fc_it)->Fill(pt_1, weight));
  }
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::JetKinematicsHists::pass(float eta_0, float eta_1)
{
  if (abs(eta_0) < 2.4 && abs(eta_1) < 2.4) {
    return 1;
  }
  else {
    return 0;
  }
}
// -----------------------------------------------------------------------------
void PennSusyFrame::JetKinematicsHists::write(TDirectory* d)
{
  d->cd();

  // loop over all flavor channels
  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // write pt histograms
    m_h_num_jet.at(fc_it)->Write();
    m_h_pt_all.at( fc_it)->Write();
    m_h_pt_0.at(   fc_it)->Write();
    m_h_pt_1.at(   fc_it)->Write();

    m_h_dr_jj.at(fc_it)->Write();
    m_h_dphi_jj.at(fc_it)->Write();
    m_h_deta_jj.at(fc_it)->Write();

    m_h_eta_all.at(fc_it)->Write();
    m_h_eta_0.at(  fc_it)->Write();
    m_h_eta_1.at(  fc_it)->Write();
    m_h_eta_event_passfail.at(fc_it)->Write();
    m_h_fiducial_single_pass.at(fc_it)->Write();
    m_h_fiducial_single_fail.at(fc_it)->Write();
    m_h_fiducial_event_pass.at(fc_it)->Write();
    m_h_fiducial_event_fail.at(fc_it)->Write();
  }
}
// =============================================================================
PennSusyFrame::MetHists::MetHists(std::string name_tag)
{
  TH1::SetDefaultSumw2(true);

  const int   met_et_bins = 100;
  const float met_et_min  = 0.;
  const float met_et_max  = 500.;

  const int dphi_bins = 32;
  const float dphi_min = 0.;
  const float dphi_max = 3.2;

  const int   met_sig_bins = 50;
  const float met_sig_min  = 0;
  const float met_sig_max  = 500;

  // loop over all flavor channels
  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize pt histograms
    m_h_met_et.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + "__met_et"
                                    + "__"
                                    + name_tag
                                    ).c_str()
                                  , ( "E_{T}^{miss} - "
                                    + FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + " ; E_{T}^{miss} [GeV] ; Entries"
                                    ).c_str()
                                  , met_et_bins, met_et_min, met_et_max
                                  )
                        );

    m_h_met_rel.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__met_rel"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "E_{T}^{miss,rel} - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; E_{T}^{miss,rel} [GeV] ; Entries"
                                     ).c_str()
                                   , met_et_bins, met_et_min, met_et_max
                                   )
                         );

    m_h_met_sig_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                         + "__met_sig_all"
                                         + "__"
                                         + name_tag
                                         ).c_str()
                                       , ( "E_{T}^{miss}/#sqrt{H_{T}} - "
                                         + FLAVOR_CHANNEL_STRINGS[fc_it]
                                         + " ; E_{T}^{miss}/#sqrt{H_{T}} ; Entries"
                                         ).c_str()
                                       , met_sig_bins, met_sig_min, met_sig_max
                                       )
                             );
    m_h_met_sig_baseline.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + "__met_sig_baseline"
                                              + "__"
                                              + name_tag
                                              ).c_str()
                                            , ( "E_{T}^{miss}/#sqrt{H_{T}} - "
                                              + FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + " ; E_{T}^{miss}/#sqrt{H_{T}} ; Entries"
                                              ).c_str()
                                            , met_sig_bins, met_sig_min, met_sig_max
                                            )
                                  );
    m_h_met_sig_good.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + "__met_sig_good"
                                          + "__"
                                          + name_tag
                                          ).c_str()
                                        , ( "E_{T}^{miss}/#sqrt{H_{T}} - "
                                          + FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + " ; E_{T}^{miss}/#sqrt{H_{T}} ; Entries"
                                          ).c_str()
                                        , met_sig_bins, met_sig_min, met_sig_max
                                        )
                              );
    m_h_met_sig_signal.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                            + "__met_sig_signal"
                                            + "__"
                                            + name_tag
                                            ).c_str()
                                          , ( "E_{T}^{miss}/#sqrt{H_{T}} - "
                                            + FLAVOR_CHANNEL_STRINGS[fc_it]
                                            + " ; E_{T}^{miss}/#sqrt{H_{T}} ; Entries"
                                            ).c_str()
                                          , met_sig_bins, met_sig_min, met_sig_max
                                          )
                                );

    m_h_dphi_nearest_object.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + "__met_dphi_nearest_object"
                                                 + "__"
                                                 + name_tag
                                                 ).c_str()
                                               , ( "#delta#phi(E_{T}^{miss}, obj) - "
                                                 + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + " ; #delta#phi(E_{T}^{miss},nearest object) ; Entries"
                                                 ).c_str()
                                               , dphi_bins, dphi_min, dphi_max
                                               )
                                     );

    m_h_dphi_jet_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + "__met_dphi_jet_0"
                                        + "__"
                                        + name_tag
                                        ).c_str()
                                      , ( "#delta#phi(E_{T}^{miss}, nearest jet) - "
                                        + FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + " ; #delta#phi(E_{T}^{miss},nearest jet) ; Entries"
                                        ).c_str()
                                      , dphi_bins, dphi_min, dphi_max
                                      )
                            );

    m_h_dphi_jet_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + "__met_dphi_jet_1"
                                        + "__"
                                        + name_tag
                                        ).c_str()
                                      , ( "#delta#phi(E_{T}^{miss}, next-to-nearest jet) - "
                                        + FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + " ; #delta#phi(E_{T}^{miss},next-to-nearest jet) ; Entries"
                                        ).c_str()
                                      , dphi_bins, dphi_min, dphi_max
                                      )
                            );

    m_h_dphi_lep_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + "__met_dphi_lep_0"
                                        + "__"
                                        + name_tag
                                        ).c_str()
                                      , ( "#delta#phi(E_{T}^{miss}, nearest lepton) - "
                                        + FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + " ; #delta#phi(E_{T}^{miss},nearest lepton) ; Entries"
                                        ).c_str()
                                      , dphi_bins, dphi_min, dphi_max
                                      )
                            );

    m_h_dphi_lep_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + "__met_dphi_lep_1"
                                        + "__"
                                        + name_tag
                                        ).c_str()
                                      , ( "#delta#phi(E_{T}^{miss}, next-to-nearest lepton) - "
                                        + FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + " ; #delta#phi(E_{T}^{miss},next-to-nearest lepton) ; Entries"
                                        ).c_str()
                                      , dphi_bins, dphi_min, dphi_max
                                      )
                            );
  }
}

// -----------------------------------------------------------------------------
PennSusyFrame::MetHists::~MetHists()
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::MetHists::Fill( const PennSusyFrame::Event& event
                                  , const PennSusyFrame::EventLevelQuantities&
                                  , const std::vector<PennSusyFrame::Electron*>* el_list
                                  , const std::vector<PennSusyFrame::Muon*>* mu_list
                                  , const std::vector<PennSusyFrame::Jet*>* jet_list
                                  , const PennSusyFrame::Met& met
                                  , float weight
                                  )
{
  FLAVOR_CHANNEL fc = event.getFlavorChannel();

  if (fc == FLAVOR_NONE) {
    return;
  }

  float met_et  = met.getMetEt() /1.e3;
  float met_rel = met.getMetRel()/1.e3;
  float met_sig_all      = met.getMetSigAll();
  float met_sig_baseline = met.getMetSigBaseline();
  float met_sig_good     = met.getMetSigGood();
  float met_sig_signal   = met.getMetSigSignal();

  float met_min_dphi_nearest_obj = met.getMinDPhiObj();
  float met_min_dphi_jet_0 = 999;
  float met_min_dphi_jet_1 = 999;
  float met_min_dphi_lep_0 = 999;
  float met_min_dphi_lep_1 = 999;

  float this_dphi = 999;

  // loop over jets looking for two closest jets to the met vector
  size_t num_jet = jet_list->size();
  for (size_t jet_it = 0; jet_it != num_jet; ++jet_it) {
    this_dphi = met.getDPhi(jet_list->at(jet_it));
    if (this_dphi < met_min_dphi_jet_1) {
      met_min_dphi_jet_1 = this_dphi;
      if (met_min_dphi_jet_1 < met_min_dphi_jet_0) {
        std::swap(met_min_dphi_jet_0, met_min_dphi_jet_1);
      }
    }
  }

  // loop over electrons looking for two closest leptons to the met vector
  size_t num_el = el_list->size();
  for (size_t el_it = 0; el_it != num_el; ++el_it) {
    this_dphi = met.getDPhi(el_list->at(el_it));
    if (this_dphi < met_min_dphi_lep_1) {
      met_min_dphi_lep_1 = this_dphi;
      if (met_min_dphi_lep_1 < met_min_dphi_lep_0) {
        std::swap(met_min_dphi_lep_0, met_min_dphi_lep_1);
      }
    }
  }

  // loop over muons looking for two closest leptons to the met vector
  size_t num_mu = mu_list->size();
  for (size_t mu_it = 0; mu_it != num_mu; ++mu_it) {
    this_dphi = met.getDPhi(mu_list->at(mu_it));
    if (this_dphi < met_min_dphi_lep_1) {
      met_min_dphi_lep_1 = this_dphi;
      if (met_min_dphi_lep_1 < met_min_dphi_lep_0) {
        std::swap(met_min_dphi_lep_0, met_min_dphi_lep_1);
      }
    }
  }

  // loop over all flavor channels
  for (int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    if (fc_it != FLAVOR_NONE && fc_it != fc) continue;

    m_h_met_et.at( fc_it)->Fill(met_et , weight);
    m_h_met_rel.at(fc_it)->Fill(met_rel, weight);
    m_h_met_sig_all.at(     fc_it)->Fill(met_sig_all     , weight);
    m_h_met_sig_baseline.at(fc_it)->Fill(met_sig_baseline, weight);
    m_h_met_sig_good.at(    fc_it)->Fill(met_sig_good    , weight);
    m_h_met_sig_signal.at(  fc_it)->Fill(met_sig_signal  , weight);

    if (met_min_dphi_nearest_obj != 999) m_h_dphi_nearest_object.at(fc_it)->Fill(met_min_dphi_nearest_obj, weight);
    if (met_min_dphi_jet_0       != 999) m_h_dphi_jet_0.at(         fc_it)->Fill(met_min_dphi_jet_0      , weight);
    if (met_min_dphi_jet_1       != 999) m_h_dphi_jet_1.at(         fc_it)->Fill(met_min_dphi_jet_1      , weight);
    if (met_min_dphi_lep_0       != 999) m_h_dphi_lep_0.at(         fc_it)->Fill(met_min_dphi_lep_0      , weight);
    if (met_min_dphi_lep_1       != 999) m_h_dphi_lep_1.at(         fc_it)->Fill(met_min_dphi_lep_1      , weight);
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::MetHists::write(TDirectory* d)
{
  d->cd();

  // loop over all flavor channels
  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize pt histograms
    m_h_met_et.at( fc_it)->Write();
    m_h_met_rel.at(fc_it)->Write();
    m_h_met_sig_all.at(fc_it)->Write();
    m_h_met_sig_baseline.at(fc_it)->Write();
    m_h_met_sig_good.at(fc_it)->Write();
    m_h_met_sig_signal.at(fc_it)->Write();

    m_h_dphi_nearest_object.at(fc_it)->Write();
    m_h_dphi_jet_0.at(fc_it)->Write();
    m_h_dphi_jet_1.at(fc_it)->Write();
    m_h_dphi_lep_0.at(fc_it)->Write();
    m_h_dphi_lep_1.at(fc_it)->Write();
  }

}
