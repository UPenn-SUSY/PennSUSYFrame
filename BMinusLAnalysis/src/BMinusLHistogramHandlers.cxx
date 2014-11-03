#include "BMinusLAnalysis/include/BMinusLHistogramHandlers.h"
#include "BMinusLAnalysis/include/BMinusLUtils.h"
#include "PennSusyFrameCore/include/PennSusyFrameCore.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/Calculators.h"
#include "PennSusyFrameCore/include/TruthMatchTools.h"
#include "PennSusyFrameCore/include/EventSelectors.h"

#include "TFile.h"
#include "TDirectory.h"
#include "TH1.h"
#include "TH2.h"

// =============================================================================
static const int   num_jet_bins = 6;
static const float num_jet_min  = -0.5;
static const float num_jet_max  = num_jet_bins + num_jet_min;

static const int   pt_bins = 100;
static const float pt_min  = 0.;
static const float pt_max  = 1000.;

static const int   eta_bins = 50;
static const float eta_min = -5.;
static const float eta_max = +5.;

static const int   mbl_bins = 60;
static const float mbl_min  = 0.;
static const float mbl_max  = 1200.;

static const int   mbl_coarse_bins = 4;
static const float mbl_bin_edges[mbl_coarse_bins+1] = {0, 100, 300, 500, 1200};

static const int   ptll_bins = 60;
static const float ptll_min  = 0.;
static const float ptll_max  = 1200.;

// TODO use these variable bin widths to set mbl histogram -- need to get weights in each bin correct first
// const std::vector<float> mbl_bin_edges[mbl_bins] = generateLogBinning( mbl_min
//                                                                      , mbl_max
//                                                                      , mbl_bins
//                                                                      );

static const int   dr_bins = 60;
static const float dr_min = 0.;
static const float dr_max = 6.0;

static const int   dr_jet_quark_bins = 50;
static const float dr_jet_quark_min = 0.0;
static const float dr_jet_quark_max = 0.5;

static const int   dphi_bins = 32;
static const float dphi_min = 0.;
static const float dphi_max = 3.2;

static const int   deta_bins = 50;
static const float deta_min = 0.;
static const float deta_max = 5.0;

static const int   mbl_ratio_bins = 21;
static const float mbl_ratio_min = 0.;
static const float mbl_ratio_max = 1.05;

static const int   mbbll_bins = 75;
static const float mbbll_min  = 0.;
static const float mbbll_max  = 3000.;

static const int   ptbbll_bins = 50;
static const float ptbbll_min  = 0.;
static const float ptbbll_max  = 1000;

static const int   ht_bins = 30;
static const float ht_min  = 0;
static const float ht_max  = 3000;

static const int resolution_bins = 40;
static const float resolution_min = 0.;
static const float resolution_max = 2000.;

static const int   weight_bins = 200;
static const float weight_min  = -1.;
static const float weight_max  = 3.;

static const int   parent_id_bins = 200;
static const float parent_id_max  = parent_id_bins/2;
static const float parent_id_min  = -parent_id_max;

// =============================================================================
PennSusyFrame::BMinusLHists::BMinusLHists(std::string name_tag)
{
  TH1::SetDefaultSumw2(true);

  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize b jet multiplicity histogram
    m_h_num_b_jet.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + "__num_b_jet"
                                       + "__"
                                       + name_tag
                                       ).c_str()
                                     , ( "B Jet multiplicity - "
                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + " ; B Jet multiplicity ; Entries"
                                       ).c_str()
                                     , num_jet_bins, num_jet_min, num_jet_max
                                     )
                           );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_bl_dr_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + "__bl_dr_all"
                                       + "__"
                                       + name_tag
                                       ).c_str()
                                     , ( "#DeltaR(b,l) - "
                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + " ; #DeltaR(b,l) ; Entries"
                                       ).c_str()
                                     , dr_bins, dr_min, dr_max
                                     )
                           );
    m_h_bl_dr_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__bl_dr_0"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "#DeltaR(b,l) - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; #DeltaR(b,l) ; Entries"
                                     ).c_str()
                                   , dr_bins, dr_min, dr_max
                                   )
                         );
    m_h_bl_dr_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__bl_dr_1"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "#DeltaR(b,l) - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; #DeltaR(b,l) ; Entries"
                                     ).c_str()
                                   , dr_bins, dr_min, dr_max
                                   )
                         );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_bl_dphi_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                         + "__bl_dphi_all"
                                         + "__"
                                         + name_tag
                                         ).c_str()
                                       , ( "#DeltaR(b,l) - "
                                         + FLAVOR_CHANNEL_STRINGS[fc_it]
                                         + " ; #DeltaR(b,l) ; Entries"
                                         ).c_str()
                                       , dphi_bins, dphi_min, dphi_max
                                       )
                             );
    m_h_bl_dphi_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + "__bl_dphi_0"
                                       + "__"
                                       + name_tag
                                       ).c_str()
                                     , ( "#DeltaR(b,l) - "
                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + " ; #DeltaR(b,l) ; Entries"
                                       ).c_str()
                                     , dphi_bins, dphi_min, dphi_max
                                     )
                           );
    m_h_bl_dphi_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + "__bl_dphi_1"
                                       + "__"
                                       + name_tag
                                       ).c_str()
                                     , ( "#DeltaR(b,l) - "
                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + " ; #DeltaR(b,l) ; Entries"
                                       ).c_str()
                                     , dphi_bins, dphi_min, dphi_max
                                     )
                           );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_bl_deta_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                         + "__bl_deta_all"
                                         + "__"
                                         + name_tag
                                         ).c_str()
                                       , ( "#DeltaR(b,l) - "
                                         + FLAVOR_CHANNEL_STRINGS[fc_it]
                                         + " ; #DeltaR(b,l) ; Entries"
                                         ).c_str()
                                       , deta_bins, deta_min, deta_max
                                       )
                             );
    m_h_bl_deta_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + "__bl_deta_0"
                                       + "__"
                                       + name_tag
                                       ).c_str()
                                     , ( "#DeltaR(b,l) - "
                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + " ; #DeltaR(b,l) ; Entries"
                                       ).c_str()
                                     , deta_bins, deta_min, deta_max
                                     )
                           );
    m_h_bl_deta_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + "__bl_deta_1"
                                       + "__"
                                       + name_tag
                                       ).c_str()
                                     , ( "#DeltaR(b,l) - "
                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + " ; #DeltaR(b,l) ; Entries"
                                       ).c_str()
                                     , deta_bins, deta_min, deta_max
                                     )
                           );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize b jet pt histograms
    m_h_b_jet_pt_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + "__b_jet_pt_all"
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

    m_h_b_jet_pt_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + "__b_jet_pt_0"
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

    m_h_b_jet_pt_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + "__b_jet_pt_1"
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
    m_h_dr_bb.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                   + "__dr_bb"
                                   + "__"
                                   + name_tag
                                   ).c_str()
                                 , ( "#DeltaR(b,b) - "
                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
                                   + " ; #DeltaR(b,b) ; Entries"
                                   ).c_str()
                                 , dr_bins, dr_min, dr_max
                                 )
                       );

    m_h_dphi_bb.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__dphi_bb"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "#Delta#phi(b,b) - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; #Delta#phi(b,b) ; Entries"
                                     ).c_str()
                                   , dphi_bins, dphi_min, dphi_max
                                   )
                         );

    m_h_deta_bb.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__deta_bb"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "#Delta#eta(b,b) - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; #Delta#eta(b,b) ; Entries"
                                     ).c_str()
                                   , deta_bins, deta_min, deta_max
                                   )
                         );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize b jet eta histograms
    m_h_b_jet_eta_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                           + "__b_jet_eta_all"
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

    m_h_b_jet_eta_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                         + "__b_jet_eta_0"
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

    m_h_b_jet_eta_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                         + "__b_jet_eta_1"
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

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize mbl histograms
    m_h_mbl_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__mbl_all"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "m_{bl} - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; m_{bl} [GeV] ; Entries"
                                     ).c_str()
                                   , mbl_bins, mbl_min, mbl_max
                                   )
                         );

    m_h_mbl_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                   + "__mbl_0"
                                   + "__"
                                   + name_tag
                                   ).c_str()
                                 , ( "m_{bl}^{0} - "
                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
                                   + " ; m_{bl}^{0} [GeV] ; Entries"
                                   ).c_str()
                                 , mbl_bins, mbl_min, mbl_max
                                 )
                       );

    m_h_mbl_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                   + "__mbl_1"
                                   + "__"
                                   + name_tag
                                   ).c_str()
                                 , ( "m_{bl}^{1} - "
                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
                                   + " ; m_{bl}^{1} [GeV] ; Entries"
                                   ).c_str()
                                 , mbl_bins, mbl_min, mbl_max
                                 )
                       );

    m_h_mbl_diff.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                      + "__mbl_diff"
                                      + "__"
                                      + name_tag
                                      ).c_str()
                                    , ( "m_{bl}^{0} - m_{bl}^{1} - "
                                      + FLAVOR_CHANNEL_STRINGS[fc_it]
                                      + " ; m_{bl}^{0} - m_{bl}^{1} [GeV] ; Entries"
                                      ).c_str()
                                    , mbl_bins, mbl_min, mbl_max
                                    )
                          );

    m_h_mbl_ratio.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + "__mbl_ratio"
                                       + "__"
                                       + name_tag
                                       ).c_str()
                                     , ( "m_{bl}^{1}/m_{bl}^{0} - "
                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + " ; m_{bl}^{1}/m_{bl}^{0} ; Entries"
                                       ).c_str()
                                     , mbl_ratio_bins, mbl_ratio_min, mbl_ratio_max
                                     )
                           );

    m_h_mbl_asym.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                      + "__mbl_asym"
                                      + "__"
                                      + name_tag
                                      ).c_str()
                                    , ( "(m_{bl}^{0} - m_{bl}^{1})/(m_{bl}^{0} + m_{bl}^{1}) - "
                                      + FLAVOR_CHANNEL_STRINGS[fc_it]
                                      + " ; (m_{bl}^{0} - m_{bl}^{1})/(m_{bl}^{0} + m_{bl}^{1}) ; Entries "
                                      ).c_str()
                                    , mbl_ratio_bins, mbl_ratio_min, mbl_ratio_max
                                    )
                          );

    m_h_mbl_2d.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + "__mbl_2d"
                                    + "__"
                                    + name_tag
                                    ).c_str()
                                  , ( "m_{bl}^{1} vs m_{bl}^{0} - "
                                    + FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + " ; m_{bl}^{0} [GeV] "
                                    + " ; m_{bl}^{1} [GeV]"
                                    ).c_str()
                                  , mbl_bins, mbl_min, mbl_max
                                  , mbl_bins, mbl_min, mbl_max
                                  )
                        );

    m_h_mbl_coarse_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__mbl_coarse_all"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "m_{bl} - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; m_{bl} [GeV] ; Entries"
                                     ).c_str()
                                   , mbl_coarse_bins, mbl_bin_edges
                                   )
                         );

    m_h_mbl_coarse_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                   + "__mbl_coarse_0"
                                   + "__"
                                   + name_tag
                                   ).c_str()
                                 , ( "m_{bl}^{0} - "
                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
                                   + " ; m_{bl}^{0} [GeV] ; Entries"
                                   ).c_str()
                                 , mbl_coarse_bins, mbl_bin_edges
                                 )
                       );

    m_h_mbl_coarse_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                   + "__mbl_coarse_1"
                                   + "__"
                                   + name_tag
                                   ).c_str()
                                 , ( "m_{bl}^{1} - "
                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
                                   + " ; m_{bl}^{1} [GeV] ; Entries"
                                   ).c_str()
                                 , mbl_coarse_bins, mbl_bin_edges
                                 )
                       );

    m_h_mbl_coarse_2d.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + "__mbl_coarse_2d"
                                    + "__"
                                    + name_tag
                                    ).c_str()
                                  , ( "m_{bl}^{1} vs m_{bl}^{0} - "
                                    + FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + " ; m_{bl}^{0} [GeV] "
                                    + " ; m_{bl}^{1} [GeV]"
                                    ).c_str()
                                  , mbl_coarse_bins, mbl_bin_edges
                                  , mbl_coarse_bins, mbl_bin_edges
                                  )
                        );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize ptbl histograms
    m_h_ptbl_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                      + "__ptbl_all"
                                      + "__"
                                      + name_tag
                                      ).c_str()
                                    , ( "p_{T}^{bl} - "
                                      + FLAVOR_CHANNEL_STRINGS[fc_it]
                                      + " ; p_{T}^{bl} [GeV] ; Entries"
                                      ).c_str()
                                    , pt_bins, pt_min, pt_max
                                    )
                          );

    m_h_ptbl_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + "__ptbl_0"
                                    + "__"
                                    + name_tag
                                    ).c_str()
                                  , ( "p_{T}^{bl,0} - "
                                    + FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + " ; p_{T}^{bl,0} [GeV] ; Entries"
                                    ).c_str()
                                  , pt_bins, pt_min, pt_max
                                  )
                        );

    m_h_ptbl_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + "__ptbl_1"
                                    + "__"
                                    + name_tag
                                    ).c_str()
                                  , ( "p_{T}^{bl,1} - "
                                    + FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + " ; p_{T}^{bl,1} [GeV] ; Entries"
                                    ).c_str()
                                  , pt_bins, pt_min, pt_max
                                  )
                        );

    m_h_ptbl_diff.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + "__ptbl_diff"
                                       + "__"
                                       + name_tag
                                       ).c_str()
                                     , ( "p_{T}^{bl,0} - p_{T}^{bl,1} - "
                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + " ; p_{T}^{bl,0} - p_{T}^{bl,1} [GeV] ; Entries"
                                       ).c_str()
                                     , pt_bins, pt_min, pt_max
                                     )
                           );

    m_h_ptbl_2d.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + "__ptbl_2d"
                                     + "__"
                                     + name_tag
                                     ).c_str()
                                   , ( "p_{T}^{bl,1} vs. p_{T}^{bl,0} - "
                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                     + " ; p_{T}^{bl,0} [GeV] "
                                     + " ; p_{T}^{bl,1} [GeV] "
                                     ).c_str()
                                   , pt_bins, pt_min, pt_max
                                   , pt_bins, pt_min, pt_max
                                   )
                         );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    m_h_mbbll.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                   + "__mbbll"
                                   + "__"
                                   + name_tag
                                   ).c_str()
                                 , ( "m_{bbll} - "
                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
                                   + " ; m_{bbll} ; Entries"
                                   ).c_str()
                                 , mbbll_bins, mbbll_min, mbbll_max
                                 )
                       );

    m_h_ptbbll.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + "__ptbbll"
                                    + "__"
                                    + name_tag
                                    ).c_str()
                                  , ( "p_{T}^{bbll} - "
                                    + FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + " ; p_{T}^{bbll} ; Entries"
                                    ).c_str()
                                  , ptbbll_bins, ptbbll_min, ptbbll_max
                                  )
                        );
  }
}

// -----------------------------------------------------------------------------
PennSusyFrame::BMinusLHists::~BMinusLHists()
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLHists::FillSpecial( const PennSusyFrame::Event& event
                                             , const std::vector<PennSusyFrame::Jet*>* b_jet_list
                                             , const PennSusyFrame::blPair& bl_0
                                             , const PennSusyFrame::blPair& bl_1
                                             , const PennSusyFrame::MCTruth& mc_truth
                                             , float weight
                                             )
{
  FLAVOR_CHANNEL fc = event.getFlavorChannel();

  // bail out if the flavor channel is not reasonable
  if (fc == FLAVOR_NONE || fc == FLAVOR_ERROR_1) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // calculate a bunch of things used in filling histograms
  size_t num_jet = b_jet_list->size();

  float pt_b_0 = ( num_jet > 0 ? b_jet_list->at(0)->getPt()/1.e3 : 0.);
  float pt_b_1 = ( num_jet > 1 ? b_jet_list->at(1)->getPt()/1.e3 : 0.);

  float phi_b_0 = ( num_jet > 0 ? b_jet_list->at(0)->getPhi() : 0.);
  float phi_b_1 = ( num_jet > 1 ? b_jet_list->at(1)->getPhi() : 0.);
  float dphi_bb = ( num_jet > 1 ? PennSusyFrame::calcDphi(phi_b_0, phi_b_1) : 0);

  float eta_b_0 = ( num_jet > 0 ? b_jet_list->at(0)->getEta() : 0.);
  float eta_b_1 = ( num_jet > 1 ? b_jet_list->at(1)->getEta() : 0.);
  float deta_bb = ( num_jet > 1 ? fabs(eta_b_0 - eta_b_1) : 0);

  float dr_bb = ( num_jet > 1 ? sqrt(dphi_bb*dphi_bb - deta_bb*deta_bb) : 0);

  // compute mbl
  float mbl_0 = bl_0.getMbl()/1.e3;
  float mbl_1 = bl_1.getMbl()/1.e3;

  // compute ptbl
  float ptbl_0 = bl_0.getPtbl()/1.e3;
  float ptbl_1 = bl_1.getPtbl()/1.e3;

  // compute mbbll and ptbbll
  float mbbll  = PennSusyFrame::calcMbbll( bl_0, bl_1)/1.e3;
  float ptbbll = PennSusyFrame::calcPtbbll(bl_0, bl_1)/1.e3;

  // compute deltaPhi between objects in bl pairs
  float dphi_bl_0 = bl_0.getDphi();
  float dphi_bl_1 = bl_1.getDphi();

  // compute deltaEta between objects in bl pairs
  float deta_bl_0 = bl_0.getDeta();
  float deta_bl_1 = bl_1.getDeta();

  // compute deltaR between objects in bl pairs
  float dr_bl_0 = bl_0.getDr();
  float dr_bl_1 = bl_1.getDr();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // loop over all flavor channels and fill histograms
  for (int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    if (fc_it == FLAVOR_ERROR_1) continue;
    if (fc_it != FLAVOR_NONE && fc_it != fc) continue;

    // fill b jet multiplicity plots
    m_h_num_b_jet.at(fc_it)->Fill(num_jet, weight);

    // fill deltaR bl plots
    m_h_bl_dr_all.at(fc_it)->Fill(dr_bl_0, weight);
    m_h_bl_dr_all.at(fc_it)->Fill(dr_bl_1, weight);
    m_h_bl_dr_0.at(fc_it)->Fill(dr_bl_0, weight);
    m_h_bl_dr_1.at(fc_it)->Fill(dr_bl_1, weight);

    // fill deltaPhi bl plots
    m_h_bl_dphi_all.at(fc_it)->Fill(dphi_bl_0, weight);
    m_h_bl_dphi_all.at(fc_it)->Fill(dphi_bl_1, weight);
    m_h_bl_dphi_0.at(fc_it)->Fill(dphi_bl_0, weight);
    m_h_bl_dphi_1.at(fc_it)->Fill(dphi_bl_1, weight);

    // fill deltaEta bl plots
    m_h_bl_deta_all.at(fc_it)->Fill(deta_bl_0, weight);
    m_h_bl_deta_all.at(fc_it)->Fill(deta_bl_1, weight);
    m_h_bl_deta_0.at(fc_it)->Fill(deta_bl_0, weight);
    m_h_bl_deta_1.at(fc_it)->Fill(deta_bl_1, weight);

    // fill leading jet pt histograms
    if (num_jet > 0) {
      m_h_b_jet_pt_all.at(fc_it)->Fill(pt_b_0, weight);
      m_h_b_jet_pt_0.at(  fc_it)->Fill(pt_b_0, weight);

      m_h_b_jet_eta_all.at(fc_it)->Fill(eta_b_0, weight);
      m_h_b_jet_eta_0.at(  fc_it)->Fill(eta_b_0, weight);

    }

    // fill sub-leading jet pt and dphi_bb histograms
    if (num_jet > 1) {
      m_h_b_jet_pt_all.at(fc_it)->Fill(pt_b_1 , weight);
      m_h_b_jet_pt_1.at(  fc_it)->Fill(pt_b_1 , weight);

      m_h_dr_bb.at  (fc_it)->Fill(dr_bb  , weight);
      m_h_dphi_bb.at(fc_it)->Fill(dphi_bb, weight);
      m_h_deta_bb.at(fc_it)->Fill(deta_bb, weight);

      m_h_b_jet_eta_all.at(fc_it)->Fill(eta_b_1, weight);
      m_h_b_jet_eta_1.at(  fc_it)->Fill(eta_b_1, weight);

    }

    // fill mbl histograms
    m_h_mbl_all.at(fc_it)->Fill(mbl_0, weight);
    m_h_mbl_all.at(fc_it)->Fill(mbl_1, weight);
    m_h_mbl_0.at(  fc_it)->Fill(mbl_0, weight);
    m_h_mbl_1.at(  fc_it)->Fill(mbl_1, weight);
    m_h_mbl_diff.at(fc_it)->Fill(fabs(mbl_0 - mbl_1), weight);
    m_h_mbl_ratio.at(fc_it)->Fill(mbl_1/mbl_0, weight);
    m_h_mbl_asym.at(fc_it)->Fill((mbl_0-mbl_1)/(mbl_0+mbl_1), weight);
    m_h_mbl_2d.at(fc_it)->Fill(mbl_0, mbl_1, weight);

    m_h_mbl_coarse_all.at(fc_it)->Fill(mbl_0, weight);
    m_h_mbl_coarse_all.at(fc_it)->Fill(mbl_1, weight);
    m_h_mbl_coarse_0.at(  fc_it)->Fill(mbl_0, weight);
    m_h_mbl_coarse_1.at(  fc_it)->Fill(mbl_1, weight);
    m_h_mbl_coarse_2d.at(fc_it)->Fill(mbl_0, mbl_1, weight);

    // fill ptbl histograms
    m_h_ptbl_all.at(fc_it)->Fill(ptbl_0, weight);
    m_h_ptbl_all.at(fc_it)->Fill(ptbl_1, weight);
    m_h_ptbl_0.at(  fc_it)->Fill(ptbl_0, weight);
    m_h_ptbl_1.at(  fc_it)->Fill(ptbl_1, weight);
    m_h_ptbl_diff.at(fc_it)->Fill(fabs(ptbl_0 - ptbl_1), weight);
    m_h_ptbl_2d.at(fc_it)->Fill(ptbl_0,  ptbl_1, weight);

    m_h_mbbll.at( fc_it)->Fill(mbbll , weight);
    m_h_ptbbll.at(fc_it)->Fill(ptbbll, weight);
  }
}

// ----------------------------------------------------------------------------- 
bool PennSusyFrame::BMinusLHists::pass(float eta_b_0, float eta_b_1, float eta_l_0, float eta_l_1)
{
  if (  abs(eta_b_0) < 2.4
     && abs(eta_b_1) < 2.4
     && abs(eta_l_0) < 2.4
     && abs(eta_l_1) < 2.4) {
    return 1;
  }
  else {
    return 0;
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLHists::write(TDirectory* d)
{
  d->cd();

  // loop over all flavor channels
  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    if (FLAVOR_CHANNEL_STRINGS[fc_it] == "flavor_error") continue;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_num_b_jet.at(fc_it)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_bl_dr_all.at(fc_it)->Write();
    m_h_bl_dr_0.at(fc_it)->Write();
    m_h_bl_dr_1.at(fc_it)->Write();

    m_h_bl_dphi_all.at(fc_it)->Write();
    m_h_bl_dphi_0.at(fc_it)->Write();
    m_h_bl_dphi_1.at(fc_it)->Write();

    m_h_bl_deta_all.at(fc_it)->Write();
    m_h_bl_deta_0.at(fc_it)->Write();
    m_h_bl_deta_1.at(fc_it)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_b_jet_pt_all.at(fc_it)->Write();
    m_h_b_jet_pt_0.at(  fc_it)->Write();
    m_h_b_jet_pt_1.at(  fc_it)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_dr_bb.at(fc_it)->Write();
    m_h_dphi_bb.at(fc_it)->Write();
    m_h_deta_bb.at(fc_it)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_b_jet_eta_all.at(fc_it)->Write();
    m_h_b_jet_eta_0.at(  fc_it)->Write();
    m_h_b_jet_eta_1.at(  fc_it)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_mbl_all.at(fc_it)->Write();
    m_h_mbl_0.at(  fc_it)->Write();
    m_h_mbl_1.at(  fc_it)->Write();
    m_h_mbl_diff.at(fc_it)->Write();
    m_h_mbl_ratio.at(fc_it)->Write();
    m_h_mbl_asym.at(fc_it)->Write();
    m_h_mbl_2d.at(fc_it)->Write();

    m_h_mbl_coarse_all.at(fc_it)->Write();
    m_h_mbl_coarse_0.at(  fc_it)->Write();
    m_h_mbl_coarse_1.at(  fc_it)->Write();
    m_h_mbl_coarse_2d.at(fc_it)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_ptbl_all.at(fc_it)->Write();
    m_h_ptbl_0.at(  fc_it)->Write();
    m_h_ptbl_1.at(  fc_it)->Write();
    m_h_ptbl_diff.at(fc_it)->Write();
    m_h_ptbl_2d.at(fc_it)->Write();

    m_h_mbbll.at(fc_it)->Write();
    m_h_ptbbll.at(fc_it)->Write();
  }
}

// =============================================================================
PennSusyFrame::BMinusLDetailedHists::BMinusLDetailedHists(std::string name_tag)
{
  TH1::SetDefaultSumw2(true);

  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_b_jet_raw_pt_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + "__b_jet_raw_pt_all"
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

    m_h_b_jet_raw_pt_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + "__b_jet_raw_pt_0"
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

    m_h_b_jet_raw_pt_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + "__b_jet_raw_pt_1"
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
    m_h_b_jet_from_stop_pt_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + "__b_jet_from_stop_pt_all"
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

    m_h_b_jet_from_stop_pt_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + "__b_jet_from_stop_pt_0"
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

    m_h_b_jet_from_stop_pt_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + "__b_jet_from_stop_pt_1"
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

    m_h_b_jet_from_stop_raw_pt_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                        + "__b_jet_from_stop_raw_pt_all"
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

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_b_jet_both_from_stop_pt_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + "__b_jet_both_from_stop_pt_all"
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

    m_h_b_jet_both_from_stop_pt_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + "__b_jet_both_from_stop_pt_0"
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

    m_h_b_jet_both_from_stop_pt_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                       + "__b_jet_both_from_stop_pt_1"
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

    m_h_b_jet_both_from_stop_raw_pt_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + "__b_jet_both_from_stop_raw_pt_all"
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

    m_h_b_jet_both_from_stop_raw_pt_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + "__b_jet_both_from_stop_raw_pt_1"
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
    // initialize lepton from stop pt histograms
    m_h_lep_from_stop_pt_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + "__lep_from_stop_pt_all"
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

    m_h_lep_from_stop_pt_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + "__lep_from_stop_pt_0"
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

    m_h_lep_from_stop_pt_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                + "__lep_from_stop_pt_1"
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
    m_h_lep_from_stop_raw_pt_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + "__lep_from_stop_raw_pt_all"
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

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_lep_both_from_stop_pt_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                       + "__lep_both_from_stop_pt_all"
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

    m_h_lep_both_from_stop_pt_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                     + "__lep_both_from_stop_pt_0"
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

    m_h_lep_both_from_stop_pt_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                     + "__lep_both_from_stop_pt_1"
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

    m_h_lep_both_from_stop_raw_pt_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + "__lep_both_from_stop_raw_pt_all"
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

    m_h_lep_both_from_stop_raw_pt_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + "__lep_both_from_stop_raw_pt_1"
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
    m_h_b_jet_mult_pt_all.push_back( new TH2F ( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                + "__b_jet_mult_pt_all"
                                                + "__"
                                                + name_tag
                                                ).c_str()
                                              , ( " p_{T}^{all} - "
                                                + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                + "; p_{T}^{all} [GeV] ; Entries"
                                                ).c_str()
                                              , pt_bins, pt_min, pt_max
                                              , 4, 1, 5
                                              )
                                   );

    m_h_b_jet_mult_pt_0.push_back( new TH2F ( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + "__b_jet_mult_pt_0"
                                              + "__"
                                              + name_tag
                                              ).c_str()
                                            , ( " p_{T}^{0} - "
                                              + FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + " ; p_{T}^{0} [GeV] ; Entries"
                                              ).c_str()
                                            , pt_bins, pt_min, pt_max
                                            , 4, 1, 5
                                            )
                                          );

    m_h_b_jet_mult_pt_1.push_back( new TH2F ( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + "__b_jet_mult_pt_1"
                                              + "__"
                                              + name_tag
                                              ).c_str()
                                            ,( " p_{T}^{1} - "
                                              + FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + " ; p_{T}^{1} [GeV] ; Entries"
                                              ).c_str()
                                            , pt_bins, pt_min, pt_max
                                            , 4, 1, 5
                                            )
                                          );

    m_h_b_jet_mult_raw_pt_all.push_back( new TH2F ( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                    + "__b_jet_mult_raw_pt_all"
                                                    + "__"
                                                    + name_tag
                                                    ).c_str()
                                                  , ( " p_{T}^{all} - "
                                                    + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                    + "; p_{T}^{all} [GeV] ; Entries"
                                                    ).c_str()
                                                  , pt_bins, pt_min, pt_max
                                                  , 4, 1, 5
                                                  )
                                       );

    m_h_b_jet_mult_raw_pt_1.push_back( new TH2F ( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                  + "__b_jet_mult_raw_pt_1"
                                                  + "__"
                                                  + name_tag
                                                  ).c_str()
                                                , ( " p_{T}^{1} - "
                                                  + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                  +  " ; p_{T}^{1} [GeV] ; Entries"
                                                  ).c_str()
                                                , pt_bins, pt_min, pt_max
                                                , 4, 1, 5
                                                )
                                     );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // mbl vs ht plots
    m_h_mbl_vs_ht_all.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                           + "__mbl_vs_ht_all"
                                           + "__"
                                           + name_tag
                                           ).c_str()
                                         , ( "m_{bl} - "
                                           + FLAVOR_CHANNEL_STRINGS[fc_it]
                                           + " ; h_{T} [GeV] "
                                           + " ; m_{bl} [GeV]"
                                           ).c_str()
                                         , ht_bins, ht_min, ht_max
                                         , mbl_bins, mbl_min, mbl_max
                                         )
                               );

    m_h_mbl_vs_ht_0.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                         + "__mbl_vs_ht_0"
                                         + "__"
                                         + name_tag
                                         ).c_str()
                                       , ( "m_{bl}^{0} - "
                                         + FLAVOR_CHANNEL_STRINGS[fc_it]
                                         + " ; h_{T} [GeV]"
                                         + " ; m_{bl}^{0} [GeV]"
                                         ).c_str()
                                       , ht_bins, ht_min, ht_max
                                       , mbl_bins, mbl_min, mbl_max
                                       )
                             );

    m_h_mbl_vs_ht_1.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                         + "__mbl_vs_ht_1"
                                         + "__"
                                         + name_tag
                                         ).c_str()
                                       , ( "m_{bl}^{1} - "
                                         + FLAVOR_CHANNEL_STRINGS[fc_it]
                                         + " ; h_{T} [GeV]"
                                         + " ; m_{bl}^{1} [GeV]"
                                         ).c_str()
                                       , ht_bins, ht_min, ht_max
                                       , mbl_bins, mbl_min, mbl_max
                                       )
                             );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize pt_b1vl1 histograms
    m_h_b_jet1vl1_pt.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + "__b_jet1vl1_pt"
                                          + "__"
                                          + name_tag
                                          ).c_str()
                                        , ( "p_{T}_b_jet1vl1 - "
                                          + FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + " ; p_{T}^{l} ; p_{T}^{b jet}"
                                          ).c_str()
                                        , pt_bins, pt_min, pt_max
                                        , pt_bins, pt_min, pt_max
                                        )
                                    );

    m_h_b_jet1vl1_pt_eff.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + "__b_jet1vl1_pt_eff"
                                              + "__"
                                              + name_tag
                                              ).c_str()
                                            , ( "p_{T}_b_jet1vl1 - "
                                              + FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + " ; p_{T}^{l} ; p_{T}^{b jet}"
                                              ).c_str()
                                            , pt_bins, pt_min, pt_max
                                            , pt_bins, pt_min, pt_max
                                            )
                                  );

    m_h_b_jet1vl1_pt_num.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + "__b_jet1vl1_pt_num"
                                              + "__"
                                              + name_tag
                                              ).c_str()
                                            , ( "p_{T}_b_jet1vl1 - "
                                              + FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + " ; p_{T}^{l} ; p_{T}^{b jet}"
                                              ).c_str()
                                            , pt_bins, pt_min, pt_max
                                            , pt_bins, pt_min, pt_max
                                            )
                                  )  ;

    m_h_b_jet1vl1_raw_pt.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + "__b_jet1vl1_raw_pt"
                                              + "__"
                                              + name_tag
                                              ).c_str()
                                            , ( "p_{T}_b_jet1vl1 - "
                                              + FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + " ; p_{T}^{l} ; p_{T}^{b jet}"
                                            ).c_str()
                                            , pt_bins, pt_min, pt_max
                                            , pt_bins, pt_min, pt_max
                                            )
                                  );

    m_h_b_jet1vl1_raw_pt_eff.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                  + "__b_jet1vl1_raw_pt_eff"
                                                  + "__"
                                                  + name_tag
                                                  ).c_str()
                                                , ( "p_{T}_b_jet1vl1 - "
                                                  + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                  + " ; p_{T}^{l} ; p_{T}^{b jet}"
                                                  ).c_str()
                                                , pt_bins, pt_min, pt_max
                                                , pt_bins, pt_min, pt_max
                                                )
                                      );

    m_h_b_jet1vl1_raw_pt_num.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
            + "__b_jet1vl1_raw_pt_num"
            + "__"
            + name_tag
            ).c_str(),
          ("p_{T}_b_jet1vl1 - "
           + FLAVOR_CHANNEL_STRINGS[fc_it]
           + " ; p_{T}^{l} ; p_{T}^{b jet}"
          ).c_str(),
          pt_bins, pt_min, pt_max,
          pt_bins, pt_min, pt_max
          )
        );

    m_h_b_jet1vl1_all_from_stop_pt.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
            + "__b_jet1vl1_all_from_stop_pt"
            + "__"
            + name_tag
            ).c_str(),
          ("p_{T}_b_jet1vl1 - "
           + FLAVOR_CHANNEL_STRINGS[fc_it]
           + " ; p_{T}^{l} ; p_{T}^{b jet}"
          ).c_str(),
          pt_bins, pt_min, pt_max,
          pt_bins, pt_min, pt_max
          )
        );

    m_h_b_jet1vl1_all_from_stop_pt_eff.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
            + "__b_jet1vl1_all_from_stop_pt_eff"
            + "__"
            + name_tag
            ).c_str(),
          ("p_{T}_b_jet1vl1 - "
           + FLAVOR_CHANNEL_STRINGS[fc_it]
           + " ; p_{T}^{l} ; p_{T}^{b jet}"
          ).c_str(),
          pt_bins, pt_min, pt_max,
          pt_bins, pt_min, pt_max
          )
        );

    m_h_b_jet1vl1_all_from_stop_pt_num.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
            + "__b_jet1vl1_all_from_stop_pt_num"
            + "__"
            + name_tag
            ).c_str(),
          ("p_{T}_b_jet1vl1 - "
           + FLAVOR_CHANNEL_STRINGS[fc_it]
           + " ; p_{T}^{l} ; p_{T}^{b jet}"
          ).c_str(),
          pt_bins, pt_min, pt_max,
          pt_bins, pt_min, pt_max
          )
        );

    m_h_b_jet1vl1_all_from_stop_raw_pt.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                            + "__b_jet1vl1_all_from_stop_raw_pt"
                                                            + "__"
                                                            + name_tag
                                                            ).c_str()
                                                          , ( "p_{T}_b_jet1vl1 - "
                                                            + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                            + " ; p_{T}^{l} ; p_{T}^{b jet}"
                                                            ).c_str()
                                                          , pt_bins, pt_min, pt_max
                                                          , pt_bins, pt_min, pt_max
                                                          )
                                                );

    m_h_b_jet1vl1_all_from_stop_raw_pt_eff.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                                + "__b_jet1vl1_all_from_stop_raw_pt_eff"
                                                                + "__"
                                                                + name_tag
                                                                ).c_str()
                                                              , ( "p_{T}_b_jet1vl1 - "
                                                                + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                                + " ; p_{T}^{l} ; p_{T}^{b jet}"
                                                                ).c_str()
                                                              , pt_bins, pt_min, pt_max
                                                              , pt_bins, pt_min, pt_max
                                                              )
                                                    );

    m_h_b_jet1vl1_all_from_stop_raw_pt_num.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                                + "__b_jet1vl1_all_from_stop_raw_pt_num"
                                                                + "__"
                                                                + name_tag
                                                                ).c_str()
                                                              , ( "p_{T}_b_jet1vl1 - "
                                                                + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                                + " ; p_{T}^{l} ; p_{T}^{b jet}"
                                                                ).c_str()
                                                              , pt_bins, pt_min, pt_max
                                                              , pt_bins, pt_min, pt_max
                                                              )
                                                    );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize mbl anti-pairing histograms
    m_h_mbl_anti_pairing_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                  + "__mbl_anti_pairing_all"
                                                  + "__"
                                                  + name_tag
                                                  ).c_str()
                                                , ( "m_{bl} - "
                                                  + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                  + " ; m_{bl} [GeV] ; Entries"
                                                  ).c_str()
                                                , mbl_bins, mbl_min, mbl_max
                                                )
                                      );

    m_h_mbl_anti_pairing_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                + "__mbl_anti_pairing_0"
                                                + "__"
                                                + name_tag
                                                ).c_str()
                                              , ( "m_{bl}^{0} - "
                                                + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                + " ; m_{bl}^{0} [GeV] ; Entries"
                                                ).c_str()
                                              , mbl_bins, mbl_min, mbl_max
                                              )
                                    );

    m_h_mbl_anti_pairing_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                + "__mbl_anti_pairing_1"
                                                + "__"
                                                + name_tag
                                                ).c_str()
                                              , ( "m_{bl}^{1} - "
                                                + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                + " ; m_{bl}^{1} [GeV] ; Entries"
                                                ).c_str()
                                              , mbl_bins, mbl_min, mbl_max
                                              )
                                    );

    m_h_mbl_anti_pairing_diff.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                   + "__mbl_anti_pairing_diff"
                                                   + "__"
                                                   + name_tag
                                                   ).c_str()
                                                 , ( "m_{bl}^{0} - m_{bl}^{1} - "
                                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                   + " ; m_{bl}^{0} - m_{bl}^{1} [GeV] ; Entries"
                                                   ).c_str()
                                                 , mbl_bins, mbl_min, mbl_max
                                                 )
                                       );

    m_h_mbl_anti_pairing_ratio.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                    + "__mbl_anti_pairing_ratio"
                                                    + "__"
                                                    + name_tag
                                                    ).c_str()
                                                  , ( "m_{bl}^{1}/m_{bl}^{0} - "
                                                    + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                    + " ; m_{bl}^{1}/m_{bl}^{0} ; Entries"
                                                    ).c_str()
                                                  , mbl_ratio_bins, mbl_ratio_min, mbl_ratio_max
                                                  )
                                        );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize same parent pairing
    m_h_num_leptons_from_stop.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                   + "__num_leptons_from_stop"
                                                   + "__"
                                                   + name_tag
                                                   ).c_str()
                                                 , ( "leptons from stop - "
                                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                   + " ; leptons from stop ; Entries"
                                                   ).c_str()
                                                 , 3, -0.5, 2.5
                                                 )
                                       );
    m_h_num_jets_from_stop.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                + "__num_jets_from_stop"
                                                + "__"
                                                + name_tag
                                                ).c_str()
                                              , ( "jets from stop - "
                                                + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                + " ; jets from stop ; Entries"
                                                ).c_str()
                                              , 3, -0.5, 2.5
                                              )
                                    );
    m_h_num_jets_paired_to_quark.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                      + "__num_b_jets_paired_to_quark"
                                                      + "__"
                                                      + name_tag
                                                      ).c_str()
                                                    , ( "b jets paired to quarks - "
                                                      + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                      + " ; b jets paired to quarks ; Entries"
                                                      ).c_str()
                                                    , 3, -0.5, 2.5
                                                    )
                                          );

    m_h_jet_from_stop_when_paired_to_quark.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                + "__jet_from_stop_when_paired_to_quark"
                                                + "__"
                                                + name_tag
                                                ).c_str()
                                              , ( "jet from stop (paired to quark) - "
                                                + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                + " ; jet from stop (paired to quark) ; Entries"
                                                ).c_str()
                                              , 2, -0.5, 1.5
                                              )
                                    );

    m_h_num_same_parent_pairing.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                     + "__num_same_parent_pairing"
                                                     + "__"
                                                     + name_tag
                                                     ).c_str()
                                                   , ( "same parent - "
                                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                     + " ; same parent ; Entries"
                                                     ).c_str()
                                                   , 3, -0.5, 2.5
                                                   )
                                         );
    m_h_same_parent_pairing_pair_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                        + "__same_parent_pairing_pair_0"
                                                        + "__"
                                                        + name_tag
                                                        ).c_str()
                                                      , ( "same parent - "
                                                        + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                        + " ; same parent ; Entries"
                                                        ).c_str()
                                                      , 2, -0.5, 1.5
                                                      )
                                            );
    m_h_same_parent_pairing_pair_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                        + "__same_parent_pairing_pair_1"
                                                        + "__"
                                                        + name_tag
                                                        ).c_str()
                                                      , ( "same parent - "
                                                        + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                        + " ; same parent ; Entries"
                                                        ).c_str()
                                                      , 2, -0.5, 1.5
                                                      )
                                            );

    m_h_same_parent_pairing_lep_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                       + "__same_parent_pairing_lep_0"
                                                       + "__"
                                                       + name_tag
                                                       ).c_str()
                                                     , ( "same parent - "
                                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                       + " ; same parent ; Entries"
                                                       ).c_str()
                                                     , 2, -0.5, 1.5
                                                     )
                                           );
    m_h_same_parent_pairing_lep_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                       + "__same_parent_pairing_lep_1"
                                                       + "__"
                                                       + name_tag
                                                       ).c_str()
                                                     , ( "same parent - "
                                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                       + " ; same parent ; Entries"
                                                       ).c_str()
                                                     , 2, -0.5, 1.5
                                                     )
                                           );

    m_h_same_parent_pairing_jet_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                       + "__same_parent_pairing_jet_0"
                                                       + "__"
                                                       + name_tag
                                                       ).c_str()
                                                     , ( "same parent - "
                                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                       + " ; same parent ; Entries"
                                                       ).c_str()
                                                     , 2, -0.5, 1.5
                                                     )
                                           );
    m_h_same_parent_pairing_jet_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                       + "__same_parent_pairing_jet_1"
                                                       + "__"
                                                       + name_tag
                                                       ).c_str()
                                                     , ( "same parent - "
                                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                       + " ; same parent ; Entries"
                                                       ).c_str()
                                                     , 2, -0.5, 1.5
                                                     )
                                           );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_b_jet_E_resolution_all.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                   + "__b_jet_E_resolution_all"
                                                   + "__"
                                                   +name_tag
                                                   ).c_str()
                                                 , ("Energy Resolution - "
                                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                     + " ; Resolution ; E^{truth}"
                                                     ).c_str()
                                                 , 100 , -1. , 1.
                                                 , resolution_bins, resolution_min, resolution_max
                                                 )
                                             );

    m_h_b_jet_E_resolution_0.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + "__b_jet_E_resolution_0"
                                                 + "__"
                                                 +name_tag
                                                 ).c_str()
                                               , ("E^{0} Resolution - "
                                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                   + " ; Resolution ; E^{truth}"
                                                   ).c_str()
                                               , 100 , -1. , 1.
                                               , resolution_bins, resolution_min, resolution_max
                                               )
                                           );

    m_h_b_jet_E_resolution_1.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + "__b_jet_E_resolution_1"
                                                 + "__"
                                                 +name_tag
                                                 ).c_str()
                                               , ("E^{1} Resolution - "
                                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                   + " ; Resolution ; E^{truth}"
                                                   ).c_str()
                                               , 100, -1. , 1.
                                               , resolution_bins, resolution_min, resolution_max
                                               )
                                           );
    m_h_electron_E_resolution_all.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                   + "__electron_E_resolution_all"
                                                   + "__"
                                                   +name_tag
                                                   ).c_str()
                                                 , ("Energy Resolution - "
                                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                     + " ; Resolution ; E^{truth}"
                                                     ).c_str()
                                                 , 100 , -1. , 1.
                                                 , resolution_bins, resolution_min, resolution_max
                                                 )
                                             );

    m_h_electron_E_resolution_0.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + "__electron_E_resolution_0"
                                                 + "__"
                                                 +name_tag
                                                 ).c_str()
                                               , ("E^{0} Resolution - "
                                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                   + " ; Resolution ; E^{truth}"
                                                   ).c_str()
                                               , 100 , -1. , 1.
                                               , resolution_bins, resolution_min, resolution_max
                                               )
                                           );

    m_h_electron_E_resolution_1.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + "__electron_E_resolution_1"
                                                 + "__"
                                                 +name_tag
                                                 ).c_str()
                                               , ("E^{1} Resolution - "
                                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                   + " ; Resolution ; E^{truth}"
                                                   ).c_str()
                                               , 100, -1. , 1.
                                               , resolution_bins, resolution_min, resolution_max
                                               )
                                           );

    m_h_muon_inverse_pt_resolution_all.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                   + "__muon_inverse_pt_resolution_all"
                                                   + "__"
                                                   +name_tag
                                                   ).c_str()
                                                 , ("(p_{T})^{-1} Resolution - "
                                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                     + " ; Resolution ; (p_{T}^{truth})^{-1}"
                                                     ).c_str()
                                                 , 100 , -1. , 1.
                                                 , resolution_bins, resolution_min, resolution_max
                                                 )
                                             );

    m_h_muon_inverse_pt_resolution_0.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + "__muon_inverse_pt_resolution_0"
                                                 + "__"
                                                 +name_tag
                                                 ).c_str()
                                               , ("(p_{T}^{0})^{-1} Resolution - "
                                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                   + " ; Resolution ; (p_{T}^{truth})^{-1}"
                                                   ).c_str()
                                               , 100 , -1. , 1.
                                               , resolution_bins, resolution_min, resolution_max
                                               )
                                           );

    m_h_muon_inverse_pt_resolution_1.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + "__muon_inverse_pt_resolution_1"
                                                 + "__"
                                                 +name_tag
                                                 ).c_str()
                                               , ("(p_{T}^{1})^{-1} Resolution - "
                                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                   + " ; Resolution ; (p_{T}^{truth})^{-1}"
                                                   ).c_str()
                                               , 100, -1. , 1.
                                               , resolution_bins, resolution_min, resolution_max
                                               )
                                           );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize mbl for same/diff parent pairing histograms
    m_h_mbl_same_parent_pairing.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                     + "__mbl__same_parent_pairing"
                                                     + "__"
                                                     + name_tag
                                                     ).c_str()
                                                   , ( "m_{bl} - "
                                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                     + " ; m_{bl} [GeV] ; Entries"
                                                     ).c_str()
                                                   , mbl_bins, mbl_min, mbl_max
                                                   )
                                         );
    m_h_mbl_diff_parent_pairing.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                     + "__mbl__diff_parent_pairing"
                                                     + "__"
                                                     + name_tag
                                                     ).c_str()
                                                   , ( "m_{bl} - "
                                                     + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                     + " ; m_{bl} [GeV] ; Entries"
                                                     ).c_str()
                                                   , mbl_bins, mbl_min, mbl_max
                                                   )
                                         );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize mbl ratio for same/diff parent pairing histograms
    m_h_mbl_ratio_same_parent_pairing.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                           + "__mbl_ratio__same_parent_pairing"
                                                           + "__"
                                                           + name_tag
                                                           ).c_str()
                                                         , ( "m_{bl}^{1}/m_{bl}^{0} - "
                                                           + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                           + " ; m_{bl}^{1}/m_{bl}^{0} ; Entries"
                                                           ).c_str()
                                                         , mbl_ratio_bins, mbl_ratio_min, mbl_ratio_max
                                                         )
                                               );
    m_h_mbl_ratio_diff_parent_pairing.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                           + "__mbl_ratio__diff_parent_pairing"
                                                           + "__"
                                                           + name_tag
                                                           ).c_str()
                                                         , ( "m_{bl}^{1}/m_{bl}^{0} - "
                                                           + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                           + " ; m_{bl}^{1}/m_{bl}^{0} ; Entries"
                                                           ).c_str()
                                                         , mbl_ratio_bins, mbl_ratio_min, mbl_ratio_max
                                                         )
                                               );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_bl_dr_same_parent_pairing.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                       + "__bl_dr__same_parent_pairing"
                                                       + "__"
                                                       + name_tag
                                                       ).c_str()
                                                     , ( "#DeltaR(b,l) - "
                                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                       + " ; #DeltaR(b,l) ; Entries"
                                                       ).c_str()
                                                     , dr_bins, dr_min, dr_max
                                                     )
                                           );
    m_h_bl_dr_diff_parent_pairing.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                       + "__bl_dr__diff_parent_pairing"
                                                       + "__"
                                                       + name_tag
                                                       ).c_str()
                                                     , ( "#DeltaR(b,l) - "
                                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                       + " ; #DeltaR(b,l) ; Entries"
                                                       ).c_str()
                                                     , dr_bins, dr_min, dr_max
                                                     )
                                           );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_bl_dphi_same_parent_pairing.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                         + "__bl_dphi__same_parent_pairing"
                                                         + "__"
                                                         + name_tag
                                                         ).c_str()
                                                       , ( "#Delta#phi(b,l) - "
                                                         + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                         + " ; #Delta#phi(b,l) ; Entries"
                                                         ).c_str()
                                                       , dphi_bins, dphi_min, dphi_max
                                                       )
                                             );
    m_h_bl_dphi_diff_parent_pairing.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                         + "__bl_dphi__diff_parent_pairing"
                                                         + "__"
                                                         + name_tag
                                                         ).c_str()
                                                       , ( "#Delta#phi(b,l) - "
                                                         + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                         + " ; #Delta#eta(b,l) ; Entries"
                                                         ).c_str()
                                                       , dphi_bins, dphi_min, dphi_max
                                                       )
                                             );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_bl_deta_same_parent_pairing.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                         + "__bl_deta__same_parent_pairing"
                                                         + "__"
                                                         + name_tag
                                                         ).c_str()
                                                       , ( "#Delta$eta(b,l) - "
                                                         + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                         + " ; #Delta$eta(b,l) ; Entries"
                                                         ).c_str()
                                                       , deta_bins, deta_min, deta_max
                                                       )
                                             );
    m_h_bl_deta_diff_parent_pairing.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                         + "__bl_deta__diff_parent_pairing"
                                                         + "__"
                                                         + name_tag
                                                         ).c_str()
                                                       , ( "#Delta#eta(b,l) - "
                                                         + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                         + " ; #Delta#eta(b,l) ; Entries"
                                                         ).c_str()
                                                       , deta_bins, deta_min, deta_max
                                                       )
                                             );
  }
}

// -----------------------------------------------------------------------------
PennSusyFrame::BMinusLDetailedHists::~BMinusLDetailedHists()
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLDetailedHists::FillSpecial( const PennSusyFrame::Event& event
                                                     , const PennSusyFrame::EventLevelQuantities& event_level_quantities
                                                     , const std::vector<PennSusyFrame::Jet*>* b_jet_list
                                                     , const PennSusyFrame::blPair& bl_0
                                                     , const PennSusyFrame::blPair& bl_1
                                                     , const PennSusyFrame::MCTruth& mc_truth
                                                     , PennSusyFrame::TruthMatchTool& truth_match_tool
                                                     , float weight
                                                     )
{
  FLAVOR_CHANNEL fc = event.getFlavorChannel();

  // bail out if the flavor channel is not reasonable
  if (fc == FLAVOR_NONE || fc == FLAVOR_ERROR_1) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // calculate a bunch of things used in filling histograms
  size_t num_jet = b_jet_list->size();

  float pt_b_0 = ( num_jet > 0 ? b_jet_list->at(0)->getPt()/1.e3 : 0.);
  float pt_b_1 = ( num_jet > 1 ? b_jet_list->at(1)->getPt()/1.e3 : 0.);

  // lepton pt's
  float pt_l_0 = bl_0.getLepton()->getPt()/1.e3;
  float pt_l_1 = bl_1.getLepton()->getPt()/1.e3;
  if (pt_l_1 > pt_l_0) {
    float tmp = pt_l_0;
    pt_l_0 = pt_l_1;
    pt_l_1 = tmp;
  }

  // get ht
  float ht_baseline = event_level_quantities.getHtBaseline()/1.e3;

  // compute mbl
  float mbl_0 = bl_0.getMbl()/1.e3;
  float mbl_1 = bl_1.getMbl()/1.e3;

  // compute deltaPhi between objects in bl pairs
  float dphi_bl_0 = bl_0.getDphi();
  float dphi_bl_1 = bl_1.getDphi();

  // compute deltaEta between objects in bl pairs
  float deta_bl_0 = bl_0.getDeta();
  float deta_bl_1 = bl_1.getDeta();

  // compute deltaR between objects in bl pairs
  float dr_bl_0 = bl_0.getDr();
  float dr_bl_1 = bl_1.getDr();

  // get lepton and pt from bl pairs
  float pt_lep_bl_0 = bl_0.getLepton()->getPt()/1.e3;
  float pt_lep_bl_1 = bl_1.getLepton()->getPt()/1.e3;
  float pt_b_bl_0   = bl_0.getJet()->getPt()/1.e3;
  float pt_b_bl_1   = bl_1.getJet()->getPt()/1.e3;

  // get b-l pairs for the anti-pairing
  PennSusyFrame::blPair bl_anti_pair_0(bl_0.getJet(), bl_1.getLepton());
  PennSusyFrame::blPair bl_anti_pair_1(bl_1.getJet(), bl_0.getLepton());

  if (bl_anti_pair_1.getMbl() > bl_anti_pair_0.getMbl()) {
    PennSusyFrame::blPair tmp = bl_anti_pair_0;
    bl_anti_pair_0 = bl_anti_pair_1;
    bl_anti_pair_1 = tmp;
  }

  // get mbl for anti-pairing
  float mbl_anti_pair_0 = bl_anti_pair_0.getMbl()/1.e3;
  float mbl_anti_pair_1 = bl_anti_pair_1.getMbl()/1.e3;

  // compute deltaPhi between objects in anti bl pairs
  float dphi_bl_anti_pair_0 = bl_anti_pair_0.getDphi();
  float dphi_bl_anti_pair_1 = bl_anti_pair_1.getDphi();

  // compute deltaEta between objects in anti bl pairs
  float deta_bl_anti_pair_0 = bl_anti_pair_0.getDeta();
  float deta_bl_anti_pair_1 = bl_anti_pair_1.getDeta();

  // compute deltaR between objects in anti bl pairs
  float dr_bl_anti_pair_0 = bl_anti_pair_0.getDr();
  float dr_bl_anti_pair_1 = bl_anti_pair_1.getDr();

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // are the pairs from the same parent?
  bool same_parent_pair_0 = PennSusyFrame::sameParent( event
                                                     , bl_0.getLepton()
                                                     , bl_0.getJet()
                                                     , mc_truth
                                                     );
  bool same_parent_pair_1 = PennSusyFrame::sameParent( event
                                                     , bl_1.getLepton()
                                                     , bl_1.getJet()
                                                     , mc_truth
                                                     );
  int num_same_parent_pairs = 0;
  if (same_parent_pair_0) ++num_same_parent_pairs;
  if (same_parent_pair_1) ++num_same_parent_pairs;

  bool same_parent_anti_pair_0 = PennSusyFrame::sameParent( event
                                                          , bl_anti_pair_0.getLepton()
                                                          , bl_anti_pair_0.getJet()
                                                          , mc_truth
                                                          );
  bool same_parent_anti_pair_1 = PennSusyFrame::sameParent( event
                                                          , bl_anti_pair_1.getLepton()
                                                          , bl_anti_pair_1.getJet()
                                                          , mc_truth
                                                          );

  bool same_parent_lep_0, same_parent_lep_1;
  if (pt_lep_bl_0 >= pt_lep_bl_1) {
    same_parent_lep_0 = same_parent_pair_0;
    same_parent_lep_1 = same_parent_pair_1;
  }
  else {
    same_parent_lep_0 = same_parent_pair_1;
    same_parent_lep_1 = same_parent_pair_0;
  }

  bool same_parent_jet_0, same_parent_jet_1;
  if (pt_b_bl_0 >= pt_b_bl_1) {
    same_parent_jet_0 = same_parent_pair_0;
    same_parent_jet_1 = same_parent_pair_1;
  }
  else {
    same_parent_jet_0 = same_parent_pair_1;
    same_parent_jet_1 = same_parent_pair_0;
  }


  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // are the jets from a stop?
  int num_jet_from_stop = 0;
  float dr_jet_q_0 = -1;
  float dr_jet_q_1 = -1;

  bool jet_from_stop_0 = (fabs(getJetParentPdgId(bl_0.getJet(), mc_truth, dr_jet_q_0)) > 1.e6);
  bool jet_from_stop_1 = (fabs(getJetParentPdgId(bl_1.getJet(), mc_truth, dr_jet_q_1)) > 1.e6);
  if (jet_from_stop_0) ++num_jet_from_stop;
  if (jet_from_stop_1) ++num_jet_from_stop;

  int num_jet_paired_to_quark = 0;
  if (dr_jet_q_0 >=0) ++num_jet_paired_to_quark;
  if (dr_jet_q_1 >=0) ++num_jet_paired_to_quark;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // are the leptons from a stop?
  int num_lep_from_stop = 0;
  //  bool jet_from_stop_0 = (fabs(getJetParentPdgId(bl_0.getJet(), mc_truth, dr_jet_q_0)) > 1.e6);
  //  bool jet_from_stop_1 = (fabs(getJetParentPdgId(bl_1.getJet(), mc_truth, dr_jet_q_1)) > 1.e6);

  bool lepton_from_stop_0 = (fabs(getLeptonParentPdgId(bl_0.getLepton(), mc_truth)) > 1.e6);
  bool lepton_from_stop_1 = (fabs(getLeptonParentPdgId(bl_1.getLepton(), mc_truth)) > 1.e6);
  if (lepton_from_stop_0) ++num_lep_from_stop;
  if (lepton_from_stop_1) ++num_lep_from_stop;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // for resolution histos
  const TLorentzVector* tlv_l_0= bl_0.getLepton()->getTlv();
  const TLorentzVector* tlv_l_1= bl_1.getLepton()->getTlv();

  int truth_index_l_0 = truth_match_tool.getIndex(tlv_l_0);
  int truth_index_l_1 = truth_match_tool.getIndex(tlv_l_1);

  int truth_index_b_0 = PennSusyFrame::getJetParentIndex(bl_0.getJet(), mc_truth);
  int truth_index_b_1 = PennSusyFrame::getJetParentIndex(bl_1.getJet(), mc_truth);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // loop over all flavor channels and fill histograms
  for (int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    if (fc_it == FLAVOR_ERROR_1) continue;
    if (fc_it != FLAVOR_NONE && fc_it != fc) continue;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // fill leading jet pt histograms
    if (num_jet > 0) {
      m_h_b_jet_raw_pt_all.at(fc_it)->Fill(pt_b_0);
      m_h_b_jet_raw_pt_0.at(  fc_it)->Fill(pt_b_0);

      if (jet_from_stop_0) {
        m_h_b_jet_from_stop_pt_all.at(fc_it)->Fill(pt_b_0, weight);
        m_h_b_jet_from_stop_pt_0.at(  fc_it)->Fill(pt_b_0, weight);
        m_h_b_jet_from_stop_raw_pt_all.at(fc_it)->Fill(pt_b_0);
      }
    }

    // fill sub-leading jet pt and dphi_bb histograms
    if (num_jet > 1) {
      m_h_b_jet_raw_pt_all.at(fc_it)->Fill(pt_b_1);
      m_h_b_jet_raw_pt_1.at(  fc_it)->Fill(pt_b_1);

      // fill jet from stop pt histograms
      if (jet_from_stop_1) {
        m_h_b_jet_from_stop_pt_all.at(fc_it)->Fill(pt_b_1, weight);
        m_h_b_jet_from_stop_pt_1.at(  fc_it)->Fill(pt_b_1, weight);
        m_h_b_jet_from_stop_raw_pt_all.at(fc_it)->Fill(pt_b_1);
      }

      m_h_b_jet1vl1_pt.at(fc_it)->Fill(pt_l_1, pt_b_1, weight);
      m_h_b_jet1vl1_raw_pt.at(fc_it)->Fill(pt_l_1, pt_b_1);

      if (jet_from_stop_0 && jet_from_stop_1) {
        m_h_b_jet_both_from_stop_pt_all.at(fc_it)->Fill(pt_b_0, weight);
        m_h_b_jet_both_from_stop_pt_all.at(fc_it)->Fill(pt_b_1, weight);
        m_h_b_jet_both_from_stop_pt_0.at(  fc_it)->Fill(pt_b_0, weight);
        m_h_b_jet_both_from_stop_pt_1.at(  fc_it)->Fill(pt_b_1, weight);
        m_h_b_jet_both_from_stop_raw_pt_all.at(fc_it)->Fill(pt_b_0);
        m_h_b_jet_both_from_stop_raw_pt_all.at(fc_it)->Fill(pt_b_1);
        m_h_b_jet_both_from_stop_raw_pt_1.at(  fc_it)->Fill(pt_b_1);
        if (num_lep_from_stop >=2)
          m_h_b_jet1vl1_all_from_stop_pt.at(fc_it)->Fill(pt_l_1, pt_b_1, weight);
          m_h_b_jet1vl1_all_from_stop_raw_pt.at(fc_it)->Fill(pt_l_1, pt_b_1);
      }
    }

    // fill lepton from stop pt histograms
    if (lepton_from_stop_0) {
      m_h_lep_from_stop_pt_all.at(fc_it)->Fill(pt_l_0, weight);
      m_h_lep_from_stop_pt_0.at(  fc_it)->Fill(pt_l_0, weight);
      m_h_lep_from_stop_raw_pt_all.at(fc_it)->Fill(pt_l_0);
    }
    if (lepton_from_stop_1) {
      m_h_lep_from_stop_pt_all.at(fc_it)->Fill(pt_l_1, weight);
      m_h_lep_from_stop_pt_1.at(  fc_it)->Fill(pt_l_1, weight);
      m_h_lep_from_stop_raw_pt_all.at(fc_it)->Fill(pt_l_1);
    }
    if (lepton_from_stop_0 && lepton_from_stop_1) {
      m_h_lep_both_from_stop_pt_all.at(fc_it)->Fill(pt_l_0, weight);
      m_h_lep_both_from_stop_pt_all.at(fc_it)->Fill(pt_l_1, weight);
      m_h_lep_both_from_stop_pt_0.at(  fc_it)->Fill(pt_l_0, weight);
      m_h_lep_both_from_stop_pt_1.at(  fc_it)->Fill(pt_l_1, weight);
      m_h_lep_both_from_stop_raw_pt_all.at(fc_it)->Fill(pt_l_0);
      m_h_lep_both_from_stop_raw_pt_all.at(fc_it)->Fill(pt_l_1);
      m_h_lep_both_from_stop_raw_pt_1.at(  fc_it)->Fill(pt_l_1);
    }

    // fill jet multiplicity pt plots
    if (num_jet ==2) {
      m_h_b_jet_mult_pt_all.at(fc_it)->Fill(pt_b_0, 2, weight);
      m_h_b_jet_mult_pt_all.at(fc_it)->Fill(pt_b_1, 2, weight);
      m_h_b_jet_mult_pt_0.at(  fc_it)->Fill(pt_b_0, 2, weight);
      m_h_b_jet_mult_pt_1.at(  fc_it)->Fill(pt_b_1, 2, weight);
      m_h_b_jet_mult_raw_pt_all.at(fc_it)->Fill(pt_b_0, 2);
      m_h_b_jet_mult_raw_pt_all.at(fc_it)->Fill(pt_b_1, 2);
      m_h_b_jet_mult_raw_pt_1.at(  fc_it)->Fill(pt_b_1, 2);
    }
    if (num_jet ==3) {
      m_h_b_jet_mult_pt_all.at(fc_it)->Fill(pt_b_0, 3, weight);
      m_h_b_jet_mult_pt_all.at(fc_it)->Fill(pt_b_1, 3, weight);
      m_h_b_jet_mult_pt_0.at(  fc_it)->Fill(pt_b_0, 3, weight);
      m_h_b_jet_mult_pt_1.at(  fc_it)->Fill(pt_b_1, 3, weight);
      m_h_b_jet_mult_raw_pt_all.at(fc_it)->Fill(pt_b_0, 3);
      m_h_b_jet_mult_raw_pt_all.at(fc_it)->Fill(pt_b_1, 3);
      m_h_b_jet_mult_raw_pt_1.at(  fc_it)->Fill(pt_b_1, 3);
    }
    if (num_jet ==4) {
      m_h_b_jet_mult_pt_all.at(fc_it)->Fill(pt_b_0, 4, weight);
      m_h_b_jet_mult_pt_all.at(fc_it)->Fill(pt_b_1, 4, weight);
      m_h_b_jet_mult_pt_0.at(  fc_it)->Fill(pt_b_0, 4, weight);
      m_h_b_jet_mult_pt_1.at(  fc_it)->Fill(pt_b_1, 4, weight);
      m_h_b_jet_mult_raw_pt_all.at(fc_it)->Fill(pt_b_0, 4);
      m_h_b_jet_mult_raw_pt_all.at(fc_it)->Fill(pt_b_1, 4);
      m_h_b_jet_mult_raw_pt_1.at(  fc_it)->Fill(pt_b_1, 4);
    }

    // fill mbl histograms
    m_h_mbl_vs_ht_all.at(fc_it)->Fill(ht_baseline, mbl_0, weight);
    m_h_mbl_vs_ht_all.at(fc_it)->Fill(ht_baseline, mbl_1, weight);
    m_h_mbl_vs_ht_0.at(  fc_it)->Fill(ht_baseline, mbl_0, weight);
    m_h_mbl_vs_ht_1.at(  fc_it)->Fill(ht_baseline, mbl_1, weight);

    // fill mbl for anti-pairs histograms
    m_h_mbl_anti_pairing_all.at(fc_it)->Fill(mbl_anti_pair_0, weight);
    m_h_mbl_anti_pairing_all.at(fc_it)->Fill(mbl_anti_pair_1, weight);
    m_h_mbl_anti_pairing_0.at(  fc_it)->Fill(mbl_anti_pair_0, weight);
    m_h_mbl_anti_pairing_1.at(  fc_it)->Fill(mbl_anti_pair_1, weight);
    m_h_mbl_anti_pairing_diff.at(fc_it)->Fill( fabs(mbl_anti_pair_0 - mbl_anti_pair_1)
                                             , weight
                                             );
    m_h_mbl_anti_pairing_ratio.at(fc_it)->Fill( mbl_anti_pair_1/mbl_anti_pair_0
                                              , weight
                                              );

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_num_leptons_from_stop.at(fc_it)->Fill(   num_lep_from_stop     , weight);
    m_h_num_jets_from_stop.at(   fc_it)->Fill(   num_jet_from_stop     , weight);
    m_h_num_jets_paired_to_quark.at(fc_it)->Fill(num_jet_paired_to_quark, weight);
    if (dr_jet_q_0 >=0)
      m_h_jet_from_stop_when_paired_to_quark.at(fc_it)->Fill(jet_from_stop_0, weight);
    if (dr_jet_q_1 >=0)
      m_h_jet_from_stop_when_paired_to_quark.at(fc_it)->Fill(jet_from_stop_1, weight);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // fill "number of same parent pairing" histograms
    m_h_num_same_parent_pairing.at(fc_it)->Fill(   num_same_parent_pairs, weight);
    m_h_same_parent_pairing_pair_0.at(fc_it)->Fill(same_parent_pair_0   , weight);
    m_h_same_parent_pairing_pair_1.at(fc_it)->Fill(same_parent_pair_1   , weight);
    m_h_same_parent_pairing_lep_0.at(fc_it)->Fill( same_parent_lep_0    , weight);
    m_h_same_parent_pairing_lep_1.at(fc_it)->Fill( same_parent_lep_1    , weight);
    m_h_same_parent_pairing_jet_0.at(fc_it)->Fill( same_parent_jet_0    , weight);
    m_h_same_parent_pairing_jet_1.at(fc_it)->Fill( same_parent_jet_1    , weight);
    // m_h_same_parent_pairing_stop.at(fc_it)->Fill(same_parent_stop    , weight);
    // m_h_same_parent_pairing_astp.at(fc_it)->Fill(same_parent_astp    , weight);

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // look at possible pairs, compute mbl for objects coming from same pairs
    if (same_parent_pair_0) {
      m_h_mbl_same_parent_pairing.at(fc_it)->Fill(mbl_0, weight);
      m_h_bl_dr_same_parent_pairing.at(  fc_it)->Fill(dr_bl_0  , weight);
      m_h_bl_dphi_same_parent_pairing.at(fc_it)->Fill(dphi_bl_0, weight);
      m_h_bl_deta_same_parent_pairing.at(fc_it)->Fill(deta_bl_0, weight);
    }
    else {
      m_h_mbl_diff_parent_pairing.at(fc_it)->Fill(mbl_0, weight);
      m_h_bl_dr_diff_parent_pairing.at(  fc_it)->Fill(dr_bl_0  , weight);
      m_h_bl_dphi_diff_parent_pairing.at(fc_it)->Fill(dphi_bl_0, weight);
      m_h_bl_deta_diff_parent_pairing.at(fc_it)->Fill(deta_bl_0, weight);
    }

    if (same_parent_pair_1) {
      m_h_mbl_same_parent_pairing.at(fc_it)->Fill(mbl_1, weight);
      m_h_bl_dr_same_parent_pairing.at(  fc_it)->Fill(dr_bl_1  , weight);
      m_h_bl_dphi_same_parent_pairing.at(fc_it)->Fill(dphi_bl_1, weight);
      m_h_bl_deta_same_parent_pairing.at(fc_it)->Fill(deta_bl_1, weight);
    }
    else {
      m_h_mbl_diff_parent_pairing.at(fc_it)->Fill(mbl_1, weight);
      m_h_bl_dr_diff_parent_pairing.at(  fc_it)->Fill(dr_bl_1  , weight);
      m_h_bl_dphi_diff_parent_pairing.at(fc_it)->Fill(dphi_bl_1, weight);
      m_h_bl_deta_diff_parent_pairing.at(fc_it)->Fill(deta_bl_1, weight);
    }

    if (same_parent_anti_pair_0) {
      m_h_mbl_same_parent_pairing.at(fc_it)->Fill(mbl_anti_pair_0, weight);
      m_h_bl_dr_same_parent_pairing.at(  fc_it)->Fill(dr_bl_anti_pair_0  , weight);
      m_h_bl_dphi_same_parent_pairing.at(fc_it)->Fill(dphi_bl_anti_pair_0, weight);
      m_h_bl_deta_same_parent_pairing.at(fc_it)->Fill(deta_bl_anti_pair_0, weight);
    }
    else {
      m_h_mbl_diff_parent_pairing.at(fc_it)->Fill(mbl_anti_pair_0, weight);
      m_h_bl_dr_diff_parent_pairing.at(  fc_it)->Fill(dr_bl_anti_pair_0  , weight);
      m_h_bl_dphi_diff_parent_pairing.at(fc_it)->Fill(dphi_bl_anti_pair_0, weight);
      m_h_bl_deta_diff_parent_pairing.at(fc_it)->Fill(deta_bl_anti_pair_0, weight);
    }

    if (same_parent_anti_pair_1) {
      m_h_mbl_same_parent_pairing.at(fc_it)->Fill(mbl_anti_pair_1, weight);
      m_h_bl_dr_same_parent_pairing.at(  fc_it)->Fill(dr_bl_anti_pair_1  , weight);
      m_h_bl_dphi_same_parent_pairing.at(fc_it)->Fill(dphi_bl_anti_pair_1, weight);
      m_h_bl_deta_same_parent_pairing.at(fc_it)->Fill(deta_bl_anti_pair_1, weight);
    }
    else {
      m_h_mbl_diff_parent_pairing.at(fc_it)->Fill(mbl_anti_pair_1, weight);
      m_h_bl_dr_diff_parent_pairing.at(  fc_it)->Fill(dr_bl_anti_pair_1  , weight);
      m_h_bl_dphi_diff_parent_pairing.at(fc_it)->Fill(dphi_bl_anti_pair_1, weight);
      m_h_bl_deta_diff_parent_pairing.at(fc_it)->Fill(deta_bl_anti_pair_1, weight);
    }

    if (same_parent_pair_0 && same_parent_pair_1) {
      m_h_mbl_ratio_same_parent_pairing.at(fc_it)->Fill(mbl_1/mbl_0, weight);
    }
    if (same_parent_anti_pair_0 && same_parent_anti_pair_1) {
      m_h_mbl_ratio_same_parent_pairing.at(fc_it)->Fill(mbl_anti_pair_1/mbl_anti_pair_0, weight);
    }

    if (!same_parent_pair_0 && !same_parent_pair_1) {
      m_h_mbl_ratio_diff_parent_pairing.at(fc_it)->Fill(mbl_1/mbl_0, weight);
    }
    if (!same_parent_anti_pair_0 && !same_parent_anti_pair_1) {
      m_h_mbl_ratio_diff_parent_pairing.at(fc_it)->Fill(mbl_anti_pair_1/mbl_anti_pair_0, weight);
    }

    // -----------------------------------------------------------------------------
    // fill resolution histograms
    //  -- for jets:
    if (truth_index_b_0 != -1 && truth_index_b_1 != -1) {
      float E_b_reco_0 = bl_0.getJet()->getE()/1.e3;
      float E_b_reco_1 = bl_1.getJet()->getE()/1.e3;

      // set truth E's
      TLorentzVector tlv_b_truth_0;
      TLorentzVector tlv_b_truth_1;
      tlv_b_truth_0.SetPtEtaPhiM( mc_truth.getPt()->at(truth_index_b_0)
                                , mc_truth.getEta()->at(truth_index_b_0)
                                , mc_truth.getPhi()->at(truth_index_b_0)
                                , mc_truth.getM()->at(truth_index_b_0)
                                );
      tlv_b_truth_1.SetPtEtaPhiM( mc_truth.getPt()->at(truth_index_b_1)
                                , mc_truth.getEta()->at(truth_index_b_1)
                                , mc_truth.getPhi()->at(truth_index_b_1)
                                , mc_truth.getM()->at(truth_index_b_1)
                                );
      float E_b_truth_0 = tlv_b_truth_0.E()/1.e3;
      float E_b_truth_1 = tlv_b_truth_1.E()/1.e3;

      float resolution_b_0 = (E_b_reco_0 - E_b_truth_0)/E_b_truth_0;
      float resolution_b_1 = (E_b_reco_1 - E_b_truth_1)/E_b_truth_1;

      m_h_b_jet_E_resolution_all.at(fc_it)->Fill(resolution_b_0, E_b_truth_0, weight);
      m_h_b_jet_E_resolution_all.at(fc_it)->Fill(resolution_b_1, E_b_truth_1, weight);
      m_h_b_jet_E_resolution_0.at(  fc_it)->Fill(resolution_b_0, E_b_truth_0, weight);
      m_h_b_jet_E_resolution_1.at(  fc_it)->Fill(resolution_b_1, E_b_truth_1, weight);
    }

    // -- for leptons:
    if (truth_index_l_0 != -1 && truth_index_l_1 != -1) {
      TLorentzVector tlv_l_truth_0;
      TLorentzVector tlv_l_truth_1;
      tlv_l_truth_0.SetPtEtaPhiM( mc_truth.getPt()->at(truth_index_l_0)
                                , mc_truth.getEta()->at(truth_index_l_0)
                                , mc_truth.getPhi()->at(truth_index_l_0)
                                , mc_truth.getM()->at(truth_index_l_0)
                                );
      tlv_l_truth_1.SetPtEtaPhiM( mc_truth.getPt()->at(truth_index_l_1)
                                , mc_truth.getEta()->at(truth_index_l_1)
                                , mc_truth.getPhi()->at(truth_index_l_1)
                                , mc_truth.getM()->at(truth_index_l_1)
                                );
      //  -- for electrons:
      if (fc == FLAVOR_EE) {
        float E_l_truth_0 = tlv_l_truth_0.E()/1.e3;
        float E_l_truth_1 = tlv_l_truth_1.E()/1.e3;
        float E_l_reco_0 = bl_0.getLepton()->getE()/1.e3;
        float E_l_reco_1 = bl_1.getLepton()->getE()/1.e3;

        float resolution_l_0 = (E_l_reco_0 - E_l_truth_0)/E_l_truth_0;
        float resolution_l_1 = (E_l_reco_1 - E_l_truth_1)/E_l_truth_1;

        m_h_electron_E_resolution_all.at(fc_it)->Fill(resolution_l_0, E_l_truth_0, weight);
        m_h_electron_E_resolution_all.at(fc_it)->Fill(resolution_l_1, E_l_truth_1, weight);
        m_h_electron_E_resolution_0.at(  fc_it)->Fill(resolution_l_0, E_l_truth_0, weight);
        m_h_electron_E_resolution_1.at(  fc_it)->Fill(resolution_l_1, E_l_truth_1, weight);
      }
      // -- for muons:
      else if (fc == FLAVOR_MM) {
        float pt_l_truth_0 = mc_truth.getPt()->at(truth_index_l_0)/1.e3;
        float pt_l_truth_1 = mc_truth.getPt()->at(truth_index_l_1)/1.e3;
        float pt_l_reco_0 = bl_0.getLepton()->getPt()/1.e3;
        float pt_l_reco_1 = bl_1.getLepton()->getPt()/1.e3;

        float resolution_l_0 = (1./pt_l_reco_0 - 1./pt_l_truth_0)*pt_l_truth_0;
        float resolution_l_1 = (1./pt_l_reco_1 - 1./pt_l_truth_1)*pt_l_truth_1;

        m_h_muon_inverse_pt_resolution_all.at(fc_it)->Fill(resolution_l_0, pt_l_truth_0, weight);
        m_h_muon_inverse_pt_resolution_all.at(fc_it)->Fill(resolution_l_1, pt_l_truth_1, weight);
        m_h_muon_inverse_pt_resolution_0.at(  fc_it)->Fill(resolution_l_0, pt_l_truth_0, weight);
        m_h_muon_inverse_pt_resolution_1.at(  fc_it)->Fill(resolution_l_1, pt_l_truth_1, weight);
      }
      // -- for e,mu events:
      else {
        float E_e_truth,  pt_m_truth, E_e_reco, pt_m_reco;
        // find out which is el, which is mu
        if (mc_truth.getPdgId()->at(truth_index_l_0) == 11) {
          E_e_truth  = tlv_l_truth_0.E()/1.e3;
          E_e_reco   = bl_0.getLepton()->getE()/1.e3;
          pt_m_truth = mc_truth.getPt()->at(truth_index_l_1)/1.e3;
          pt_m_reco  = bl_1.getLepton()->getPt()/1.e3;
        }
        else {
          E_e_truth  = tlv_l_truth_1.E()/1.e3;
          E_e_reco   = bl_1.getLepton()->getE()/1.e3;
          pt_m_truth = mc_truth.getPt()->at(truth_index_l_0)/1.e3;
          pt_m_reco  = bl_0.getLepton()->getPt()/1.e3;
        }

        float resolution_e = (E_e_reco - E_e_truth)/E_e_truth;
        float resolution_m = (1./pt_m_reco - 1./pt_m_truth)*pt_m_truth;

        m_h_electron_E_resolution_all.at(fc_it)->Fill(resolution_e, E_e_truth, weight);
        m_h_muon_inverse_pt_resolution_all.at(fc_it)->Fill(resolution_m, pt_m_truth, weight);
      }
    }
  }
}

// -----------------------------------------------------------------------------
bool PennSusyFrame::BMinusLDetailedHists::pass(float eta_b_0, float eta_b_1, float eta_l_0, float eta_l_1)
{
  if (  abs(eta_b_0) < 2.4
     && abs(eta_b_1) < 2.4
     && abs(eta_l_0) < 2.4
     && abs(eta_l_1) < 2.4) {
    return 1;
  }
  else {
    return 0;
  }
}
//
// ------------------------------------------------------------
void PennSusyFrame::BMinusLDetailedHists::calcEff2d( TH2F* pt_2d
                                                   , TH2F* pt_2d_eff
                                                   , TH2F* pt_2d_num
                                                   , bool raw
                                                   )
{
  float denom = pt_2d->Integral();

  for (int ix=0; ix < pt_2d->GetXaxis()->GetNbins(); ix++) {
    for (int iy=0; iy < pt_2d->GetYaxis()->GetNbins(); iy++) {
      float cutx = pt_2d->GetXaxis()->GetBinLowEdge(ix+1);
      float cuty = pt_2d->GetYaxis()->GetBinLowEdge(iy+1);
      float numer = pt_2d->Integral(ix+1, pt_2d->GetNbinsX(), iy+1, pt_2d->GetNbinsY());
      float eff = numer/denom;
      if (raw) {
        pt_2d_num->Fill(cutx,cuty,numer);
      }
      else {
        pt_2d_num->Fill(cutx,cuty,numer*21000);
      }
      pt_2d_eff->Fill(cutx,cuty,eff);
    }
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLDetailedHists::write(TDirectory* d)
{
  d->cd();

  // loop over all flavor channels
  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    if (FLAVOR_CHANNEL_STRINGS[fc_it] == "flavor_error") continue;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_b_jet_raw_pt_all.at(fc_it)->Write();
    m_h_b_jet_raw_pt_0.at(  fc_it)->Write();
    m_h_b_jet_raw_pt_1.at(  fc_it)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_b_jet_from_stop_pt_all.at(fc_it)->Write();
    m_h_b_jet_from_stop_pt_0.at(  fc_it)->Write();
    m_h_b_jet_from_stop_pt_1.at(  fc_it)->Write();
    m_h_b_jet_from_stop_raw_pt_all.at(fc_it)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_b_jet_both_from_stop_pt_all.at(fc_it)->Write();
    m_h_b_jet_both_from_stop_pt_0.at(  fc_it)->Write();
    m_h_b_jet_both_from_stop_pt_1.at(  fc_it)->Write();
    m_h_b_jet_both_from_stop_raw_pt_all.at(fc_it)->Write();
    m_h_b_jet_both_from_stop_raw_pt_1.at(  fc_it)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_lep_from_stop_pt_all.at(fc_it)->Write();
    m_h_lep_from_stop_pt_0.at(  fc_it)->Write();
    m_h_lep_from_stop_pt_1.at(  fc_it)->Write();
    m_h_lep_from_stop_raw_pt_all.at(fc_it)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_lep_both_from_stop_pt_all.at(fc_it)->Write();
    m_h_lep_both_from_stop_pt_0.at(  fc_it)->Write();
    m_h_lep_both_from_stop_pt_1.at(  fc_it)->Write();
    m_h_lep_both_from_stop_raw_pt_all.at(fc_it)->Write();
    m_h_lep_both_from_stop_raw_pt_1.at(  fc_it)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_b_jet_mult_pt_all.at(fc_it)->Write();
    m_h_b_jet_mult_pt_0.at(  fc_it)->Write();
    m_h_b_jet_mult_pt_1.at(  fc_it)->Write();
    m_h_b_jet_mult_raw_pt_all.at(fc_it)->Write();
    m_h_b_jet_mult_raw_pt_1.at(  fc_it)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_mbl_vs_ht_all.at(fc_it)->Write();
    m_h_mbl_vs_ht_0.at(  fc_it)->Write();
    m_h_mbl_vs_ht_1.at(  fc_it)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bool raw = 0;
    m_h_b_jet1vl1_pt.at(fc_it)->Write();
    calcEff2d( m_h_b_jet1vl1_pt.at(fc_it)
             , m_h_b_jet1vl1_pt_eff.at(fc_it)
             , m_h_b_jet1vl1_pt_num.at(fc_it)
             , raw
             );
    m_h_b_jet1vl1_pt_eff.at(fc_it)->Write();
    m_h_b_jet1vl1_pt_num.at(fc_it)->Write();

    m_h_b_jet1vl1_all_from_stop_pt.at(fc_it)->Write();
    calcEff2d( m_h_b_jet1vl1_all_from_stop_pt.at(fc_it)
             , m_h_b_jet1vl1_all_from_stop_pt_eff.at(fc_it)
             , m_h_b_jet1vl1_all_from_stop_pt_num.at(fc_it)
             , raw
             );
    m_h_b_jet1vl1_all_from_stop_pt_eff.at(fc_it)->Write();
    m_h_b_jet1vl1_all_from_stop_pt_num.at(fc_it)->Write();

    raw = 1;
    m_h_b_jet1vl1_raw_pt.at(fc_it)->Write();
    calcEff2d( m_h_b_jet1vl1_raw_pt.at(fc_it)
             , m_h_b_jet1vl1_raw_pt_eff.at(fc_it)
             , m_h_b_jet1vl1_raw_pt_num.at(fc_it)
             , raw
             );
    m_h_b_jet1vl1_raw_pt_eff.at(fc_it)->Write();
    m_h_b_jet1vl1_raw_pt_num.at(fc_it)->Write();

    m_h_b_jet1vl1_all_from_stop_raw_pt.at(fc_it)->Write();
    calcEff2d( m_h_b_jet1vl1_all_from_stop_raw_pt.at(fc_it)
             , m_h_b_jet1vl1_all_from_stop_raw_pt_eff.at(fc_it)
             , m_h_b_jet1vl1_all_from_stop_raw_pt_num.at(fc_it)
             , raw
             );
    m_h_b_jet1vl1_all_from_stop_raw_pt_eff.at(fc_it)->Write();
    m_h_b_jet1vl1_all_from_stop_raw_pt_num.at(fc_it)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_mbl_anti_pairing_all.at(fc_it)->Write();
    m_h_mbl_anti_pairing_0.at(  fc_it)->Write();
    m_h_mbl_anti_pairing_1.at(  fc_it)->Write();
    m_h_mbl_anti_pairing_diff.at(fc_it)->Write();
    m_h_mbl_anti_pairing_ratio.at(fc_it)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_num_leptons_from_stop.at(   fc_it)->Write();
    m_h_num_jets_from_stop.at(      fc_it)->Write();
    m_h_num_jets_paired_to_quark.at(fc_it)->Write();
    m_h_jet_from_stop_when_paired_to_quark.at(fc_it)->Write();

    m_h_num_same_parent_pairing.at(fc_it)->Write();
    m_h_same_parent_pairing_pair_0.at(fc_it)->Write();
    m_h_same_parent_pairing_pair_1.at(fc_it)->Write();
    m_h_same_parent_pairing_lep_0.at(fc_it)->Write();
    m_h_same_parent_pairing_lep_1.at(fc_it)->Write();
    m_h_same_parent_pairing_jet_0.at(fc_it)->Write();
    m_h_same_parent_pairing_jet_1.at(fc_it)->Write();
    // m_h_same_parent_pairing_stop.at(fc_it)->Write();
    // m_h_same_parent_pairing_astp.at(fc_it)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_b_jet_E_resolution_all.at(fc_it)->Write();
    m_h_b_jet_E_resolution_0.at(  fc_it)->Write();
    m_h_b_jet_E_resolution_1.at(  fc_it)->Write();

    m_h_electron_E_resolution_all.at(fc_it)->Write();
    m_h_electron_E_resolution_0.at(  fc_it)->Write();
    m_h_electron_E_resolution_1.at(  fc_it)->Write();

    m_h_muon_inverse_pt_resolution_all.at(fc_it)->Write();
    m_h_muon_inverse_pt_resolution_0.at(  fc_it)->Write();
    m_h_muon_inverse_pt_resolution_1.at(  fc_it)->Write();

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_mbl_same_parent_pairing.at(fc_it)->Write();
    m_h_mbl_diff_parent_pairing.at(fc_it)->Write();

    m_h_mbl_ratio_same_parent_pairing.at(fc_it)->Write();
    m_h_mbl_ratio_diff_parent_pairing.at(fc_it)->Write();

    m_h_bl_dr_same_parent_pairing.at(fc_it)->Write();
    m_h_bl_dr_diff_parent_pairing.at(fc_it)->Write();

    m_h_bl_dphi_same_parent_pairing.at(fc_it)->Write();
    m_h_bl_dphi_diff_parent_pairing.at(fc_it)->Write();

    m_h_bl_deta_same_parent_pairing.at(fc_it)->Write();
    m_h_bl_deta_diff_parent_pairing.at(fc_it)->Write();
  }
}

// =============================================================================
PennSusyFrame::WeightHists::WeightHists(std::string name_tag)
{
  TH1::SetDefaultSumw2(true);

  // loop over all flavor channels
  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize histograms
    m_h_cross_section_weight.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                  + "__weights__cross_section_weight"
                                                  + "__"
                                                  + name_tag
                                                  ).c_str()
                                                , ( "cross_section_weight - "
                                                  + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                  + " ; weight ; Entries"
                                                  ).c_str()
                                                , weight_bins, weight_min, weight_max
                                                )
                                      );
    m_h_mc_event_weight.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + "__weights__mc_event_weight"
                                             + "__"
                                             + name_tag
                                             ).c_str()
                                           , ( "mc_event_weight - "
                                             + FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + " ; weight ; Entries"
                                             ).c_str()
                                           , weight_bins, weight_min, weight_max
                                           )
                                 );
    m_h_pile_up_weight.push_back(  new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + "__weights__pile_up_weight"
                                             + "__"
                                             + name_tag
                                             ).c_str()
                                           , ( "pile_up_weight - "
                                             + FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + " ; weight ; Entries"
                                             ).c_str()
                                           , weight_bins, weight_min, weight_max
                                           )
                                 );
    m_h_lep_sf.push_back(          new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + "__weights__lep_sf"
                                             + "__"
                                             + name_tag
                                             ).c_str()
                                           , ( "lep_sf - "
                                             + FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + " ; weight ; Entries"
                                             ).c_str()
                                           , weight_bins, weight_min, weight_max
                                           )
                                 );
    m_h_btag_sf.push_back(         new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + "__weights__btag_sf"
                                             + "__"
                                             + name_tag
                                             ).c_str()
                                           , ( "btag_sf - "
                                             + FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + " ; weight ; Entries"
                                             ).c_str()
                                           , weight_bins, weight_min, weight_max
                                           )
                                 );
    m_h_ttbar_pt_weight.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + "__weights__ttbar_weight"
                                             + "__"
                                             + name_tag
                                             ).c_str()
                                           , ( "ttbar weight - "
                                             + FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + " ; weight ; Entries"
                                             ).c_str()
                                           , weight_bins, weight_min, weight_max
                                           )
                                 );
    m_h_total_weight.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + "__weights__total_weight"
                                          + "__"
                                          + name_tag
                                          ).c_str()
                                        , ( "total weight - "
                                          + FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + " ; weight ; Entries"
                                          ).c_str()
                                        , weight_bins, weight_min, weight_max
                                        )
                              );
    m_h_all_but_cross_section_weight.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                          + "__weights__all_but_cross_section_weight"
                                                          + "__"
                                                          + name_tag
                                                          ).c_str()
                                                        , ( "all weight but cross section - "
                                                          + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                          + " ; weight ; Entries"
                                                          ).c_str()
                                                        , weight_bins, weight_min, weight_max
                                                        )
                                              );

    m_h_lep_sf_egamma_up.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + "__weights__lep_sf_egamma_up"
                                              + "__"
                                              + name_tag
                                              ).c_str()
                                            , ( "lep_sf - "
                                              + FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + " ; weight ; Entries"
                                              ).c_str()
                                            , weight_bins, weight_min, weight_max
                                            )
                                  );
    m_h_lep_sf_egamma_down.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                + "__weights__lep_sf_egamma_down"
                                                + "__"
                                                + name_tag
                                                ).c_str()
                                              , ( "lep_sf - "
                                                + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                + " ; weight ; Entries"
                                                ).c_str()
                                              , weight_bins, weight_min, weight_max
                                              )
                                    );

    m_h_lep_sf_muon_up.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                            + "__weights__lep_sf_muon_up"
                                            + "__"
                                            + name_tag
                                            ).c_str()
                                          , ( "lep_sf - "
                                            + FLAVOR_CHANNEL_STRINGS[fc_it]
                                            + " ; weight ; Entries"
                                            ).c_str()
                                          , weight_bins, weight_min, weight_max
                                          )
                                );
    m_h_lep_sf_muon_down.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + "__weights__lep_sf_muon_down"
                                              + "__"
                                              + name_tag
                                              ).c_str()
                                            , ( "lep_sf - "
                                              + FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + " ; weight ; Entries"
                                              ).c_str()
                                            , weight_bins, weight_min, weight_max
                                            )
                                  );


    m_h_lep_sf_ratio_egamma_up.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + "__weights__lep_sf_ratio_egamma_up"
                                              + "__"
                                              + name_tag
                                              ).c_str()
                                            , ( "lep_sf - "
                                              + FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + " ; ratio ; Entries"
                                              ).c_str()
                                            , weight_bins, weight_min, weight_max
                                            )
                                  );
    m_h_lep_sf_ratio_egamma_down.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                + "__weights__lep_sf_ratio_egamma_down"
                                                + "__"
                                                + name_tag
                                                ).c_str()
                                              , ( "lep_sf - "
                                                + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                + " ; ratio ; Entries"
                                                ).c_str()
                                              , weight_bins, weight_min, weight_max
                                              )
                                    );

    m_h_lep_sf_ratio_muon_up.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                            + "__weights__lep_sf_ratio_muon_up"
                                            + "__"
                                            + name_tag
                                            ).c_str()
                                          , ( "lep_sf - "
                                            + FLAVOR_CHANNEL_STRINGS[fc_it]
                                            + " ; ratio ; Entries"
                                            ).c_str()
                                          , weight_bins, weight_min, weight_max
                                          )
                                );
    m_h_lep_sf_ratio_muon_down.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + "__weights__lep_sf_ratio_muon_down"
                                              + "__"
                                              + name_tag
                                              ).c_str()
                                            , ( "lep_sf - "
                                              + FLAVOR_CHANNEL_STRINGS[fc_it]
                                              + " ; ratio ; Entries"
                                              ).c_str()
                                            , weight_bins, weight_min, weight_max
                                            )
                                  );

    m_h_btag_sf_up.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + "__weights__btag_sf_up"
                                        + "__"
                                        + name_tag
                                        ).c_str()
                                      , ( "btag_sf - "
                                        + FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + " ; weight ; Entries"
                                        ).c_str()
                                      , weight_bins, weight_min, weight_max
                                      )
                            );

    m_h_btag_sf_down.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + "__weights__btag_sf_down"
                                          + "__"
                                          + name_tag
                                          ).c_str()
                                        , ( "btag_sf - "
                                          + FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + " ; weight ; Entries"
                                          ).c_str()
                                        , weight_bins, weight_min, weight_max
                                        )
                              );

    m_h_btag_sf_ratio_up.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + "__weights__btag_sf_ratio_up"
                                        + "__"
                                        + name_tag
                                        ).c_str()
                                      , ( "btag_sf - "
                                        + FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + " ; ratio ; Entries"
                                        ).c_str()
                                      , weight_bins, weight_min, weight_max
                                      )
                            );

    m_h_btag_sf_ratio_down.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + "__weights__btag_sf_ratio_down"
                                          + "__"
                                          + name_tag
                                          ).c_str()
                                        , ( "btag_sf - "
                                          + FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + " ; ratio ; Entries"
                                          ).c_str()
                                        , weight_bins, weight_min, weight_max
                                        )
                              );
  }
}

// -----------------------------------------------------------------------------
PennSusyFrame::WeightHists::~WeightHists()
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::WeightHists::FillSpecial( const PennSusyFrame::Event& event
                                            , const PennSusyFrame::EventLevelQuantities& event_quantities
                                            , float cross_section_weight
                                            , float ttbar_pt_weight
                                            )
{
  FLAVOR_CHANNEL fc = event.getFlavorChannel();

  if (fc == FLAVOR_NONE) {
    return;
  }

  // loop over all flavor channels
  for (int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    if (fc_it != FLAVOR_NONE && fc_it != fc) continue;

    m_h_cross_section_weight.at(fc_it)->Fill(cross_section_weight                );
    m_h_mc_event_weight.at(     fc_it)->Fill(event_quantities.getMcEventWeight() );
    m_h_pile_up_weight.at(      fc_it)->Fill(event_quantities.getPileUpSF()      );
    m_h_lep_sf.at(              fc_it)->Fill(event_quantities.getLeptonSF()      );
    m_h_btag_sf.at(             fc_it)->Fill(event_quantities.getBTagSF()        );
    m_h_ttbar_pt_weight.at(     fc_it)->Fill(ttbar_pt_weight                     );
    m_h_total_weight.at(fc_it)->Fill( ( event_quantities.getMcEventWeight()
                                      * event_quantities.getPileUpSF()
                                      * event_quantities.getLeptonSF()
                                      * event_quantities.getBTagSF()
                                      * ttbar_pt_weight
                                      * cross_section_weight
                                      )
                                    );
    m_h_all_but_cross_section_weight.at(fc_it)->Fill( ( event_quantities.getMcEventWeight()
                                                      * event_quantities.getPileUpSF()
                                                      * event_quantities.getLeptonSF()
                                                      * event_quantities.getBTagSF()
                                                      * ttbar_pt_weight
                                                      )
                                                    );

    m_h_lep_sf_egamma_up.at(  fc_it)->Fill(event_quantities.getLeptonSFEgammaUp()  );
    m_h_lep_sf_egamma_down.at(fc_it)->Fill(event_quantities.getLeptonSFEgammaDown());
    m_h_lep_sf_muon_up.at(    fc_it)->Fill(event_quantities.getLeptonSFMuonUp()    );
    m_h_lep_sf_muon_down.at(  fc_it)->Fill(event_quantities.getLeptonSFMuonDown()  );

    m_h_lep_sf_ratio_egamma_up.at(  fc_it)->Fill(event_quantities.getLeptonSFEgammaUp()   / event_quantities.getLeptonSF());
    m_h_lep_sf_ratio_egamma_down.at(fc_it)->Fill(event_quantities.getLeptonSFEgammaDown() / event_quantities.getLeptonSF());
    m_h_lep_sf_ratio_muon_up.at(    fc_it)->Fill(event_quantities.getLeptonSFMuonUp()     / event_quantities.getLeptonSF());
    m_h_lep_sf_ratio_muon_down.at(  fc_it)->Fill(event_quantities.getLeptonSFMuonDown()   / event_quantities.getLeptonSF());

    m_h_btag_sf_up.at(  fc_it)->Fill(event_quantities.getBTagSFUp()  );
    m_h_btag_sf_down.at(fc_it)->Fill(event_quantities.getBTagSFDown());

    m_h_btag_sf_ratio_up.at(  fc_it)->Fill(event_quantities.getBTagSFUp()   / event_quantities.getBTagSF());
    m_h_btag_sf_ratio_down.at(fc_it)->Fill(event_quantities.getBTagSFDown() / event_quantities.getBTagSF());
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::WeightHists::write(TDirectory* d)
{
  d->cd();

  // loop over all flavor channels
  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // write histograms
    m_h_cross_section_weight.at(fc_it)->Write();
    m_h_mc_event_weight.at(     fc_it)->Write();
    m_h_pile_up_weight.at(      fc_it)->Write();
    m_h_lep_sf.at(              fc_it)->Write();
    m_h_btag_sf.at(             fc_it)->Write();
    m_h_ttbar_pt_weight.at(     fc_it)->Write();
    m_h_total_weight.at(        fc_it)->Write();
    m_h_all_but_cross_section_weight.at(fc_it)->Write();

    m_h_lep_sf_egamma_up.at(  fc_it)->Write();
    m_h_lep_sf_egamma_down.at(fc_it)->Write();
    m_h_lep_sf_muon_up.at(    fc_it)->Write();
    m_h_lep_sf_muon_down.at(  fc_it)->Write();

    m_h_lep_sf_ratio_egamma_up.at(  fc_it)->Write();
    m_h_lep_sf_ratio_egamma_down.at(fc_it)->Write();
    m_h_lep_sf_ratio_muon_up.at(    fc_it)->Write();
    m_h_lep_sf_ratio_muon_down.at(  fc_it)->Write();

    m_h_btag_sf_up.at(  fc_it)->Write();
    m_h_btag_sf_down.at(fc_it)->Write();

    m_h_btag_sf_ratio_up.at(  fc_it)->Write();
    m_h_btag_sf_ratio_down.at(fc_it)->Write();
  }
}

// =============================================================================
PennSusyFrame::ParentHists::ParentHists(std::string name_tag)
{
  TH1::SetDefaultSumw2(true);

  // loop over all flavor channels
  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize histograms
    m_h_parentid_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + "__lep_parent_pdgid_all"
                                          + "__"
                                          + name_tag
                                          ).c_str()
                                        , ( "lepton parent pdgid - "
                                          + FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + " ; lepton parent pdgid ; Entries"
                                          ).c_str()
                                        , parent_id_bins, parent_id_min, parent_id_max
                                        )
                              );

    m_h_parentid_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + "__lep_parent_pdgid_0"
                                          + "__"
                                          + name_tag
                                          ).c_str()
                                        , ( "lepton parent pdgid - "
                                          + FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + " ; lepton 0 parent pdgid ; Entries"
                                          ).c_str()
                                        , parent_id_bins, parent_id_min, parent_id_max
                                        )
                              );

    m_h_parentid_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + "__lep_parent_pdgid_1"
                                          + "__"
                                          + name_tag
                                          ).c_str()
                                        , ( "lepton parent pdgid - "
                                          + FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + " ; lepton 1 parent pdgid ; Entries"
                                          ).c_str()
                                        , parent_id_bins, parent_id_min, parent_id_max
                                        )
                              );

    m_h_ptz_truth.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + "__ptz_truth"
                                       + "__"
                                       + name_tag
                                       ).c_str()
                                     , ( "truth ptz - "
                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + " ; truth ptz [GeV] ; Entries"
                                       ).c_str()
                                     , ptll_bins, ptll_min, ptll_max
                                     )
                           );
  }
}

// -----------------------------------------------------------------------------
PennSusyFrame::ParentHists::~ParentHists()
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::ParentHists::FillSpecial( const PennSusyFrame::Event& event
                                            , const PennSusyFrame::blPair& bl_0
                                            , const PennSusyFrame::blPair& bl_1
                                            , const PennSusyFrame::MCTruth& mc_truth
                                            , float weight
                                            )
{
  FLAVOR_CHANNEL fc = event.getFlavorChannel();

  if (fc == FLAVOR_NONE) {
    return;
  }

  PennSusyFrame::Lepton* lep_0 = bl_0.getLepton();
  PennSusyFrame::Lepton* lep_1 = bl_1.getLepton();

  if (lep_0 == NULL || lep_1 == NULL) return;

  int lep_parent_index_0 = getLeptonParentIndex(lep_0, mc_truth);
  int lep_parent_index_1 = getLeptonParentIndex(lep_1, mc_truth);
  if (lep_parent_index_0 < 0 || lep_parent_index_1 < 0) return;

  int lep_parent_pdgid_0 = mc_truth.getPdgId()->at(lep_parent_index_0);
  int lep_parent_pdgid_1 = mc_truth.getPdgId()->at(lep_parent_index_1);

  float truth_ptz = PennSusyFrame::findTruthLevelZPt(mc_truth)/1000.;

  // loop over all flavor channels
  for (int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    if (fc_it != FLAVOR_NONE && fc_it != fc) continue;

    m_h_parentid_all.at(fc_it)->Fill(lep_parent_pdgid_0, weight);
    m_h_parentid_all.at(fc_it)->Fill(lep_parent_pdgid_1, weight);
    m_h_parentid_0.at(  fc_it)->Fill(lep_parent_pdgid_0, weight);
    m_h_parentid_1.at(  fc_it)->Fill(lep_parent_pdgid_1, weight);
    m_h_ptz_truth.at(   fc_it)->Fill(truth_ptz         , weight);
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::ParentHists::write(TDirectory* d)
{
  d->cd();

  // loop over all flavor channels
  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // write histograms
    m_h_parentid_all.at(fc_it)->Write();
    m_h_parentid_0.at(fc_it)->Write();
    m_h_parentid_1.at(fc_it)->Write();
    m_h_ptz_truth.at( fc_it)->Write();
  }
}

// -----------------------------------------------------------------------------
PennSusyFrame::DRHists::DRHists(std::string name_tag)
{
  TH1::SetDefaultSumw2(true);

  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize dr histograms
    m_h_dr_leadinglep_closest_fc_match.push_back( new TH1D( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                            + "__dr_leadinglep_closest_fc_match"
                                                            + "__"
                                                            + name_tag
                                                            ).c_str()
                                                          , ("#DeltaR(l0,closest object) - "
                                                            + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                            + " ; #DeltaR(lep0,closest) ; Entries"
                                                            ).c_str()
                                                          , dr_bins, dr_min, dr_max
                                                          )
                                                );
    m_h_dr_leadinglep_closest_fc_mismatch.push_back( new TH1D( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                               + "__dr_leadinglep_closest_fc_mismatch"
                                                               + "__"
                                                               + name_tag
                                                               ).c_str()
                                                             , ("#DeltaR(l0,closest object) - "
                                                               + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                               + " ; #DeltaR(lep0,closest) ; Entries"
                                                               ).c_str()
                                                             , dr_bins, dr_min, dr_max
                                                             )
                                                   );
    m_h_dr_subleadinglep_closest_fc_match.push_back( new TH1D( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                               + "__dr_subleadinglep_closest_fc_match"
                                                               + "__"
                                                               + name_tag
                                                               ).c_str()
                                                             , ("#DeltaR(l1,closest object) - "
                                                               + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                               + " ; #DeltaR(lep1,closest) ; Entries"
                                                               ).c_str()
                                                             , dr_bins, dr_min, dr_max
                                                             )
                                                   );
    m_h_dr_subleadinglep_closest_fc_mismatch.push_back( new TH1D( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                                  + "__dr_subleadinglep_closest_fc_mismatch"
                                                                  + "__"
                                                                  + name_tag
                                                                  ).c_str()
                                                                , ("#DeltaR(l1,closest object) - "
                                                                  + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                                  + " ; #DeltaR(lep1,closest) ; Entries"
                                                                  ).c_str()
                                                                , dr_bins, dr_min, dr_max
                                                                )
                                                      );
    m_h_dr_ee_from_stop.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + "___dr_ee_from_stop"
                                             + "__"
                                             + name_tag
                                             ).c_str()
                                           , ( "#DeltaR(e,e) - "
                                             + FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + " ; #DeltaR(e,e) ; Entries"
                                             ).c_str()
                                           , dr_bins, dr_min, dr_max
                                           )
                                 );
    m_h_dr_mm_from_stop.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + "___dr_mm_from_stop"
                                             + "__"
                                             + name_tag
                                             ).c_str()
                                           , ( "#DeltaR(m,m) - "
                                             + FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + " ; #DeltaR(m,m) ; Entries"
                                             ).c_str()
                                           , dr_bins, dr_min, dr_max
                                           )
                                 );
    m_h_dr_em_from_stop.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + "___dr_em_from_stop"
                                             + "__"
                                             + name_tag
                                             ).c_str()
                                           , ( "#DeltaR(e,m) - "
                                             + FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + " ; #DeltaR(e,m) ; Entries"
                                             ).c_str()
                                           , dr_bins, dr_min, dr_max
                                           )
                                 );
    m_h_dr_ej_from_stop.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + "___dr_ej_from_stop"
                                             + "__"
                                             + name_tag
                                             ).c_str()
                                           , ( "#DeltaR(e,j) - "
                                             + FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + " ; #DeltaR(e,j) ; Entries"
                                             ).c_str()
                                           , dr_bins, dr_min, dr_max
                                           )
                                 );
    m_h_dr_mj_from_stop.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + "___dr_mj_from_stop"
                                             + "__"
                                             + name_tag
                                             ).c_str()
                                           , ( "#DeltaR(m,j) - "
                                             + FLAVOR_CHANNEL_STRINGS[fc_it]
                                             + " ; #DeltaR(m,j) ; Entries"
                                             ).c_str()
                                           , dr_bins, dr_min, dr_max
                                           )
                                 );

    m_h_dr_ee_not_from_stop.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + "___dr_ee_not_from_stop"
                                                 + "__"
                                                 + name_tag
                                                 ).c_str()
                                               , ( "#DeltaR(e,e) - "
                                                 + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + " ; #DeltaR(e,e) ; Entries"
                                                 ).c_str()
                                               , dr_bins, dr_min, dr_max
                                               )
                                     );
    m_h_dr_mm_not_from_stop.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + "___dr_mm_not_from_stop"
                                                 + "__"
                                                 + name_tag
                                                 ).c_str()
                                               , ( "#DeltaR(m,m) - "
                                                 + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + " ; #DeltaR(m,m) ; Entries"
                                                 ).c_str()
                                               , dr_bins, dr_min, dr_max
                                               )
                                     );
    m_h_dr_em_not_from_stop.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + "___dr_em_not_from_stop"
                                                 + "__"
                                                 + name_tag
                                                 ).c_str()
                                               , ( "#DeltaR(e,m) - "
                                                 + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + " ; #DeltaR(e,m) ; Entries"
                                                 ).c_str()
                                               , dr_bins, dr_min, dr_max
                                               )
                                     );
    m_h_dr_ej_not_from_stop.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + "___dr_ej_not_from_stop"
                                                 + "__"
                                                 + name_tag
                                                 ).c_str()
                                               , ( "#DeltaR(e,j) - "
                                                 + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + " ; #DeltaR(e,j) ; Entries"
                                                 ).c_str()
                                               , dr_bins, dr_min, dr_max
                                               )
                                     );
    m_h_dr_mj_not_from_stop.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + "___dr_mj_not_from_stop"
                                                 + "__"
                                                 + name_tag
                                                 ).c_str()
                                               , ( "#DeltaR(m,j) - "
                                                 + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                 + " ; #DeltaR(m,j) ; Entries"
                                                 ).c_str()
                                               , dr_bins, dr_min, dr_max
                                               )
                                     );
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_flavor_channel_tvr.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                + "__flavor_channel_tvr"
                                                + "__"
                                                + name_tag
                                                ).c_str()
                                              , ( "Flavor Channel - "
                                                + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                + "; Reco Flavor Channel ; Truth Flavor Channel"
                                                ).c_str()
                                              , FLAVOR_N, -0.5, FLAVOR_N - 0.5
                                              , FLAVOR_N, -0.5, FLAVOR_N - 0.5
                                              )
                                    );
    m_h_flavor_channel_tvr_lepfromstop.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                            + "__flavor_channel_tvr_lepfromstop"
                                                            + "__"
                                                            + name_tag
                                                            ).c_str()
                                                          , ( "Flavor Channel - "
                                                            + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                            + "; Reco Flavor Channel ; Truth Flavor Channel"
                                                            ).c_str()
                                                          , FLAVOR_N, -0.5, FLAVOR_N - 0.5
                                                          , FLAVOR_N, -0.5, FLAVOR_N - 0.5
                                                          )
                                                );
    m_h_flavor_channel_tvr_lepnotfromstop.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                               + "__flavor_channel_tvr_lepnotfromstop"
                                                               + "__"
                                                               + name_tag
                                                               ).c_str()
                                                             , ( "Flavor Channel - "
                                                               + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                               + "; Reco Flavor Channel ; Truth Flavor Channel"
                                                               ).c_str()
                                                             , FLAVOR_N, -0.5, FLAVOR_N - 0.5
                                                             , FLAVOR_N, -0.5, FLAVOR_N - 0.5
                                                             )
                                                   );
    m_h_flavor_channel_tvr_jetfromstop.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                            + "__flavor_channel_tvr_jetfromstop"
                                                            + "__"
                                                            + name_tag
                                                            ).c_str()
                                                          , ( "Flavor Channel - "
                                                            + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                            + "; Reco Flavor Channel ; Truth Flavor Channel"
                                                            ).c_str()
                                                          , FLAVOR_N, -0.5, FLAVOR_N - 0.5
                                                          , FLAVOR_N, -0.5, FLAVOR_N - 0.5
                                                          )
                                                );
    m_h_flavor_channel_tvr_jetnotfromstop.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                               + "__flavor_channel_tvr_jetnotfromstop"
                                                               + "__"
                                                               + name_tag
                                                               ).c_str()
                                                             , ( "Flavor Channel - "
                                                               + FLAVOR_CHANNEL_STRINGS[fc_it]
                                                               + "; Reco Flavor Channel ; Truth Flavor Channel"
                                                               ).c_str()
                                                             , FLAVOR_N, -0.5, FLAVOR_N - 0.5
                                                             , FLAVOR_N, -0.5, FLAVOR_N - 0.5
                                                             )
                                                   );

    for (int flavor_it = 0; flavor_it != FLAVOR_N; ++flavor_it) {
      m_h_flavor_channel_tvr.at(fc_it)->GetXaxis()->SetBinLabel( flavor_it+1
                                                               , FLAVOR_CHANNEL_STRINGS[flavor_it].c_str()
                                                               );
      m_h_flavor_channel_tvr.at(fc_it)->GetYaxis()->SetBinLabel( flavor_it+1
                                                               , FLAVOR_CHANNEL_STRINGS[flavor_it].c_str()
                                                               );
      m_h_flavor_channel_tvr_lepfromstop.at(fc_it)->GetXaxis()->SetBinLabel( flavor_it+1
                                                                           , FLAVOR_CHANNEL_STRINGS[flavor_it].c_str()
                                                                           );
      m_h_flavor_channel_tvr_lepfromstop.at(fc_it)->GetYaxis()->SetBinLabel( flavor_it+1
                                                                           , FLAVOR_CHANNEL_STRINGS[flavor_it].c_str()
                                                                           );
      m_h_flavor_channel_tvr_lepnotfromstop.at(fc_it)->GetXaxis()->SetBinLabel( flavor_it+1
                                                                              , FLAVOR_CHANNEL_STRINGS[flavor_it].c_str()
                                                                              );
      m_h_flavor_channel_tvr_lepnotfromstop.at(fc_it)->GetYaxis()->SetBinLabel( flavor_it+1
                                                                              , FLAVOR_CHANNEL_STRINGS[flavor_it].c_str()
                                                                              );
      m_h_flavor_channel_tvr_jetfromstop.at(fc_it)->GetXaxis()->SetBinLabel( flavor_it+1
                                                                           , FLAVOR_CHANNEL_STRINGS[flavor_it].c_str()
                                                                           );
      m_h_flavor_channel_tvr_jetfromstop.at(fc_it)->GetYaxis()->SetBinLabel( flavor_it+1
                                                                           , FLAVOR_CHANNEL_STRINGS[flavor_it].c_str()
                                                                           );
      m_h_flavor_channel_tvr_jetnotfromstop.at(fc_it)->GetXaxis()->SetBinLabel( flavor_it+1
                                                                              , FLAVOR_CHANNEL_STRINGS[flavor_it].c_str()
                                                                              );
      m_h_flavor_channel_tvr_jetnotfromstop.at(fc_it)->GetYaxis()->SetBinLabel( flavor_it+1
                                                                              , FLAVOR_CHANNEL_STRINGS[flavor_it].c_str()
                                                                              );
    }

  }
}

// -----------------------------------------------------------------------------
PennSusyFrame::DRHists::~DRHists()
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::DRHists::FilldR( const PennSusyFrame::Event& event
                                   , const std::vector<PennSusyFrame::Electron*>& el_list
                                   , const std::vector<PennSusyFrame::Muon*>& mu_list
                                   , const std::vector<PennSusyFrame::Jet*>& b_jet_list
                                   , const PennSusyFrame::MCTruth& mc_truth
                                   )
{
  FLAVOR_CHANNEL fc = event.getFlavorChannel();

  // bail out if the flavor channel is not reasonable
  if (fc == FLAVOR_NONE || fc == FLAVOR_ERROR_1) return;
  if (el_list.size() + mu_list.size() <2 ) return;
  if (b_jet_list.size() < 2) return;

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // calculate a bunch of things used in filling histograms
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  PennSusyFrame::Lepton* lep_0;
  PennSusyFrame::Lepton* lep_1;
  const PennSusyFrame::Jet* jet_0 = b_jet_list.at(0);
  const PennSusyFrame::Jet* jet_1 = b_jet_list.at(1);

  if (jet_0->getPt() < jet_1->getPt()){
    jet_0 = b_jet_list.at(1);
    jet_1 = b_jet_list.at(0);
  }

  if (fc == FLAVOR_EE) {
    lep_0 = el_list.at(0);
    lep_1 = el_list.at(1);
    if (lep_0->getPt() < lep_1->getPt()) {
      lep_0 = el_list.at(1);
      lep_1 = el_list.at(0);
    }
  }
  else if (fc == FLAVOR_MM) {
    lep_0 = mu_list.at(0);
    lep_1 = mu_list.at(1);
    if (lep_0->getPt() < lep_1->getPt()) {
      lep_0 = mu_list.at(1);
      lep_1 = mu_list.at(0);
    }
  }
  else if (fc == FLAVOR_EM) {
      lep_0 = el_list.at(0);
      lep_1 = mu_list.at(0);
    if (lep_0->getPt() < lep_1->getPt()) {
      lep_0 = mu_list.at(0);
      lep_1 = el_list.at(0);
    }
  }
  else {
    return;
  }
  double  dr_ll, dr_lj00, dr_lj01, dr_lj10, dr_lj11;

  dr_ll   = PennSusyFrame::getDr(lep_0, lep_1);
  dr_lj00 = PennSusyFrame::getDr(lep_0, jet_0);
  dr_lj01 = PennSusyFrame::getDr(lep_0, jet_1);
  dr_lj10 = PennSusyFrame::getDr(lep_1, jet_0);
  dr_lj11 = PennSusyFrame::getDr(lep_1, jet_1);

  float dr_jet_q_0 = -1;
  float dr_jet_q_1 = -1;
  bool jet_from_stop_0 = (fabs(getJetParentPdgId(jet_0, mc_truth, dr_jet_q_0)) > 1.e6);
  bool jet_from_stop_1 = (fabs(getJetParentPdgId(jet_1, mc_truth, dr_jet_q_1)) > 1.e6);
  bool lepton_from_stop_0 = (fabs(getLeptonParentPdgId(lep_0, mc_truth)) > 1.e6);
  bool lepton_from_stop_1 = (fabs(getLeptonParentPdgId(lep_1, mc_truth)) > 1.e6);

  float weight = 1.;
  // find truth flavor channel
  FLAVOR_CHANNEL truth_fc = PennSusyFrame::getTruthFC(mc_truth);

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // loop over all flavor channels and fill histograms
  for (int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    if (fc_it == FLAVOR_ERROR_1) continue;
    if (fc_it != FLAVOR_NONE && fc_it != fc) continue;

    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // fill dr histograms

    // fill dr(leading lep, closest object) histograms
    double dr_leadinglep_jclosest    = 100.;
    double dr_subleadinglep_jclosest = 100.;
    for (unsigned int jet_it =0 ; jet_it != b_jet_list.size() ; ++jet_it) {
      if (PennSusyFrame::getDr(lep_0 , b_jet_list.at(jet_it) ) < dr_leadinglep_jclosest) {
        dr_leadinglep_jclosest = PennSusyFrame::getDr(lep_0, b_jet_list.at(jet_it));
      }
      if (PennSusyFrame::getDr(lep_1 , b_jet_list.at(jet_it) ) < dr_subleadinglep_jclosest) {
        dr_subleadinglep_jclosest = PennSusyFrame::getDr(lep_1, b_jet_list.at(jet_it));
      }
    }
    double  dr_leadinglep_closest = std::min( dr_leadinglep_jclosest
        ,dr_ll
        );
    double dr_subleadinglep_closest = std::min( dr_subleadinglep_jclosest
        ,dr_ll
        );
    if (fc_it == truth_fc)  {
      m_h_dr_leadinglep_closest_fc_match.at(   fc_it)->Fill(   dr_leadinglep_closest, weight);
      m_h_dr_subleadinglep_closest_fc_match.at(fc_it)->Fill(dr_subleadinglep_closest, weight);
    }
    else {
      m_h_dr_leadinglep_closest_fc_mismatch.at(   fc_it)->Fill(   dr_leadinglep_closest, weight);
      m_h_dr_subleadinglep_closest_fc_mismatch.at(fc_it)->Fill(dr_subleadinglep_closest, weight);
    }
    // fill dr from_stop and not_from_stop histograms
    if (fc == FLAVOR_EE) {
      if (lepton_from_stop_0 && lepton_from_stop_1) m_h_dr_ee_from_stop.at(fc_it)->Fill(dr_ll, weight);
      else m_h_dr_ee_not_from_stop.at(fc_it)->Fill(dr_ll, weight);
      // find closest jet to electron 0 and see if lepton is from stop
      if (dr_lj00 == std::min(dr_lj00, dr_lj01) ) {
        if (lepton_from_stop_0) m_h_dr_ej_from_stop.at(fc_it)->Fill(dr_lj00, weight);
        else   m_h_dr_ej_not_from_stop.at(fc_it)->Fill(dr_lj00, weight);
      }
      else { // aka, if dr_lj01 is min
        if (lepton_from_stop_0) m_h_dr_ej_from_stop.at(fc_it)->Fill(dr_lj01, weight);
        else   m_h_dr_ej_not_from_stop.at(fc_it)->Fill(dr_lj01, weight);
      }
      // find closest jet to electron 1 and see if lepton is from stop
      if (dr_lj10 == std::min(dr_lj10, dr_lj11) ) {
        if (lepton_from_stop_1) m_h_dr_ej_from_stop.at(fc_it)->Fill(dr_lj10, weight);
        else   m_h_dr_ej_not_from_stop.at(fc_it)->Fill(dr_lj10, weight);
      }
      else { // aka, if dr_lj11 is min
        if (lepton_from_stop_1) m_h_dr_ej_from_stop.at(fc_it)->Fill(dr_lj11, weight);
        else   m_h_dr_ej_not_from_stop.at(fc_it)->Fill(dr_lj11, weight);
      }
    }

    else if (fc == FLAVOR_MM) {
      if (lepton_from_stop_0 && lepton_from_stop_1) m_h_dr_mm_from_stop.at(fc_it)->Fill(dr_ll, weight);
      else m_h_dr_mm_not_from_stop.at(fc_it)->Fill(dr_ll, weight);
      // find closest jet to muon 0 and see if lepton is from stop
      if (dr_lj00 == std::min(dr_lj00, dr_lj01) ) {
        if (lepton_from_stop_0) m_h_dr_mj_from_stop.at(fc_it)->Fill(dr_lj00, weight);
        else   m_h_dr_mj_not_from_stop.at(fc_it)->Fill(dr_lj00, weight);
      }
      else { // aka, if dr_lj01 is min
        if (lepton_from_stop_0) m_h_dr_mj_from_stop.at(fc_it)->Fill(dr_lj01, weight);
        else   m_h_dr_mj_not_from_stop.at(fc_it)->Fill(dr_lj01, weight);
      }
      // find closest jet to muon 1 and see if lepton is from stop
      if (dr_lj10 == std::min(dr_lj10, dr_lj11) ) {
        if (lepton_from_stop_1) m_h_dr_mj_from_stop.at(fc_it)->Fill(dr_lj10, weight);
        else   m_h_dr_mj_not_from_stop.at(fc_it)->Fill(dr_lj10, weight);
      }
      else { // aka, if dr_lj11 is min
        if (lepton_from_stop_1) m_h_dr_mj_from_stop.at(fc_it)->Fill(dr_lj11, weight);
        else   m_h_dr_mj_not_from_stop.at(fc_it)->Fill(dr_lj11, weight);
      }
    }

    else { // FLAVORCHANNEL EM
      if (lepton_from_stop_0 && lepton_from_stop_1) m_h_dr_em_from_stop.at(fc_it)->Fill(dr_ll, weight);
      else m_h_dr_em_not_from_stop.at(fc_it)->Fill(dr_ll, weight);
      // find closest jet to lep_0 and see if lepton is from stop -- see if lep is e or m
      if (dr_lj00 == std::min(dr_lj00, dr_lj01) ) {
        if (lepton_from_stop_0) {
          if (lep_0->isElectron()) m_h_dr_ej_from_stop.at(fc_it)->Fill(dr_lj00, weight);
          else m_h_dr_mj_from_stop.at(fc_it)->Fill(dr_lj00, weight);
        }
        else {
          if (lep_0->isElectron()) m_h_dr_ej_not_from_stop.at(fc_it)->Fill(dr_lj00, weight);
          else m_h_dr_mj_not_from_stop.at(fc_it)->Fill(dr_lj00, weight);
        }
      }
      else { // aka, if dr_lj01 is min
        if (lepton_from_stop_0) {
          if (lep_0->isElectron()) m_h_dr_ej_from_stop.at(fc_it)->Fill(dr_lj01, weight);
          else m_h_dr_mj_from_stop.at(fc_it)->Fill(dr_lj01, weight);
        }
        else {
          if (lep_0->isElectron()) m_h_dr_ej_not_from_stop.at(fc_it)->Fill(dr_lj01, weight);
          else m_h_dr_mj_not_from_stop.at(fc_it)->Fill(dr_lj01, weight);
        }
      }
      // find closest jet to lep_1 and see if lepton is from stop -- see if lep is e or m
      if (dr_lj10 == std::min(dr_lj10, dr_lj11) ) {
        if (lepton_from_stop_1) {
          if (lep_1->isElectron()) m_h_dr_ej_from_stop.at(fc_it)->Fill(dr_lj10, weight);
          else m_h_dr_mj_from_stop.at(fc_it)->Fill(dr_lj10, weight);
        }
        else {
          if (lep_1->isElectron()) m_h_dr_ej_not_from_stop.at(fc_it)->Fill(dr_lj10, weight);
          else m_h_dr_mj_not_from_stop.at(fc_it)->Fill(dr_lj10, weight);
        }
      }
      else { // aka, if dr_lj11 is min
        if (lepton_from_stop_1) {
          if (lep_1->isElectron()) m_h_dr_ej_from_stop.at(fc_it)->Fill(dr_lj11, weight);
          else m_h_dr_mj_from_stop.at(fc_it)->Fill(dr_lj11, weight);
        }
        else {
          if (lep_1->isElectron()) m_h_dr_ej_not_from_stop.at(fc_it)->Fill(dr_lj11, weight);
          else m_h_dr_mj_not_from_stop.at(fc_it)->Fill(dr_lj11, weight);
        }
      }
    }

    // -----------------------------------------------------------------------------
    // fill truth v. reco flavor channel histos.
    m_h_flavor_channel_tvr.at(fc_it)->Fill(fc, truth_fc);
    if (lepton_from_stop_0 && lepton_from_stop_1) m_h_flavor_channel_tvr_lepfromstop.at(fc_it)->Fill(fc, truth_fc);
    else m_h_flavor_channel_tvr_lepnotfromstop.at(fc_it)->Fill(fc, truth_fc);
    if (jet_from_stop_0 && jet_from_stop_1) m_h_flavor_channel_tvr_jetfromstop.at(fc_it)->Fill(fc,truth_fc);
    else  m_h_flavor_channel_tvr_jetnotfromstop.at(fc_it)->Fill(fc,truth_fc);
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::DRHists::write(TDirectory* d)
{
  d->cd();

  // loop over all flavor channels
  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    if (FLAVOR_CHANNEL_STRINGS[fc_it] == "flavor_error") continue;
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    m_h_dr_leadinglep_closest_fc_match.at(   fc_it)->Write();
    m_h_dr_leadinglep_closest_fc_mismatch.at(fc_it)->Write();
    m_h_dr_subleadinglep_closest_fc_match.at(   fc_it)->Write();
    m_h_dr_subleadinglep_closest_fc_mismatch.at(fc_it)->Write();

    m_h_dr_ee_from_stop.at(fc_it)->Write();
    m_h_dr_mm_from_stop.at(fc_it)->Write();
    m_h_dr_em_from_stop.at(fc_it)->Write();
    m_h_dr_ej_from_stop.at(fc_it)->Write();
    m_h_dr_mj_from_stop.at(fc_it)->Write();

    m_h_dr_ee_not_from_stop.at(fc_it)->Write();
    m_h_dr_mm_not_from_stop.at(fc_it)->Write();
    m_h_dr_em_not_from_stop.at(fc_it)->Write();
    m_h_dr_ej_not_from_stop.at(fc_it)->Write();
    m_h_dr_mj_not_from_stop.at(fc_it)->Write();

    m_h_flavor_channel_tvr.at(fc_it)->Write();
    m_h_flavor_channel_tvr_lepfromstop.at(fc_it)->Write();
    m_h_flavor_channel_tvr_lepnotfromstop.at(fc_it)->Write();
    m_h_flavor_channel_tvr_jetfromstop.at(fc_it)->Write();
    m_h_flavor_channel_tvr_jetnotfromstop.at(fc_it)->Write();
  }
}
