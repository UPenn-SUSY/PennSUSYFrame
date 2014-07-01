#include "BMinusLAnalysis/include/BMinusLHistogramHandlers.h"
#include "BMinusLAnalysis/include/BMinusLUtils.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/Calculators.h"

#include "TFile.h"
#include "TDirectory.h"
#include "TH1.h"
#include "TH2.h"

// =============================================================================
PennSusyFrame::BMinusLHists::BMinusLHists(std::string name_tag)
{
  TH1::SetDefaultSumw2(true);

  const int   num_jet_bins = 5;
  const float num_jet_min  = -0.5;
  const float num_jet_max  = num_jet_bins + num_jet_min;

  const int   pt_bins = 1000;
  const float pt_min  = 0.;
  const float pt_max  = 1000.;

  const int   eta_bins = 50;
  const float eta_min = -5.;
  const float eta_max = 5.;

  const int   mbl_bins = 60;
  const float mbl_min  = 0.;
  const float mbl_max  = 1200.;
  // TODO use these variable bin widths to set mbl histogram -- need to get weights in each bin correct first
  // const std::vector<float> mbl_bin_edges[mbl_bins] = generateLogBinning( mbl_min
  //                                                                      , mbl_max
  //                                                                      , mbl_bins
  //                                                                      );

  const int dr_bins = 60;
  const float dr_min = 0.;
  const float dr_max = 6.0;

  const int  dr_jet_quark_bins = 50;
  const float dr_jet_quark_min = 0.0;
  const float dr_jet_quark_max = 0.5;

  const int dphi_bins = 32;
  const float dphi_min = 0.;
  const float dphi_max = 3.2;

  const int deta_bins = 50;
  const float deta_min = 0.;
  const float deta_max = 5.0;

  const int   mbl_ratio_bins = 21;
  const float mbl_ratio_min = 0.;
  const float mbl_ratio_max = 1.05;

  const int   mbbll_bins = 150;
  const float mbbll_min  = 0.;
  const float mbbll_max  = 3000.;

  const int   ptbbll_bins = 100;
  const float ptbbll_min  = 0.;
  const float ptbbll_max  = 1000;

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

    m_h_b_jet_mult_pt_all.push_back( new TH2F ( (FLAVOR_CHANNEL_STRINGS[fc_it]
						+ "__b_jet_mult_pt_all"
						+ "__"
						+ name_tag
						).c_str()
					       ,( " p_{T}^{all} - "
						  + FLAVOR_CHANNEL_STRINGS[fc_it]
						  + "; p_{T}^{all} [GeV] ; Entries"
						  ).c_str()
					       , pt_bins, pt_min, pt_max
						, 4, 1, 5
					       )
				    );

    m_h_b_jet_mult_pt_0.push_back( new TH2F ( (FLAVOR_CHANNEL_STRINGS[fc_it]
						+ "__b_jet_mult_pt_0"
						+ "__"
						+ name_tag
						).c_str()
					       ,( " p_{T}^{0} - "
						  + FLAVOR_CHANNEL_STRINGS[fc_it]
						  +  " ; p_{T}^{0} [GeV] ; Entries"
						  ).c_str()
					       , pt_bins, pt_min, pt_max
						, 4, 1, 5
					       )
				    );

    m_h_b_jet_mult_pt_1.push_back( new TH2F ( (FLAVOR_CHANNEL_STRINGS[fc_it]
						+ "__b_jet_mult_pt_1"
						+ "__"
						+ name_tag
						).c_str()
					       ,( " p_{T}^{1} - "
						  + FLAVOR_CHANNEL_STRINGS[fc_it]
						  +  " ; p_{T}^{1} [GeV] ; Entries"
						  ).c_str()
					       , pt_bins, pt_min, pt_max
						, 4, 1, 5
					       )
				    );



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

    // initialize b jet dr histograms
    m_h_b_jet_dr_q_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                            + "__b_jet_dr_q_all"
                                            + "__"
                                            + name_tag
                                            ).c_str()
                                          , ( "#DeltaR(b jet, b quark) - "
                                            + FLAVOR_CHANNEL_STRINGS[fc_it]
                                            + " ; #DeltaR(b jet, b quark) ; Entries"
                                            ).c_str()
                                          , dr_jet_quark_bins, dr_jet_quark_min, dr_jet_quark_max
                                          )
                                );

    m_h_b_jet_dr_q_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + "__b_jet_dr_q_0"
                                          + "__"
                                          + name_tag
                                          ).c_str()
                                        , ( "#DeltaR(b jet, b quark) - "
                                          + FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + " ; #DeltaR(b jet, b quark) ; Entries"
                                          ).c_str()
                                        , dr_jet_quark_bins, dr_jet_quark_min, dr_jet_quark_max
                                        )
                              );

    m_h_b_jet_dr_q_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + "__b_jet_dr_q_1"
                                        + "__"
                                        + name_tag
                                        ).c_str()
                                      , ( "#DeltaR(b jet, b quark) - "
                                        + FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + " ; #DeltaR(b jet, b quark) ; Entries"
                                        ).c_str()
                                      , dr_jet_quark_bins, dr_jet_quark_min, dr_jet_quark_max
                                      )
                            );

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

    // initialize pt_b1vl1 histograms
    m_h_b_jet1vl1_pt.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
					    + "__b_jet1vl1_pt"
					    + "__"
					    + name_tag
					    ).c_str(),
					  ("p_{T}_b_jet1vl1 - "
					   + FLAVOR_CHANNEL_STRINGS[fc_it]
					   + " ; p_{T}^{l} ; p_{T}^{b jet}"
					   ).c_str(),
					  pt_bins/10., pt_min, pt_max,
					  pt_bins/10., pt_min, pt_max
					  )
				);
    m_h_b_jet1vl1_pt_eff.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
					    + "__b_jet1vl1_pt_eff"
					    + "__"
					    + name_tag
					    ).c_str(),
					  ("p_{T}_b_jet1vl1 - "
					   + FLAVOR_CHANNEL_STRINGS[fc_it]
					   + " ; p_{T}^{l} ; p_{T}^{b jet}"
					   ).c_str(),
					  pt_bins/10., pt_min, pt_max,
					  pt_bins/10., pt_min, pt_max
					  )
				);
    m_h_b_jet1vl1_pt_num.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
					    + "__b_jet1vl1_pt_num"
					    + "__"
					    + name_tag
					    ).c_str(),
					  ("p_{T}_b_jet1vl1 - "
					   + FLAVOR_CHANNEL_STRINGS[fc_it]
					   + " ; p_{T}^{l} ; p_{T}^{b jet}"
					   ).c_str(),
					  pt_bins/10., pt_min, pt_max,
					  pt_bins/10., pt_min, pt_max
					  )
				);

    m_h_fiducial_b_jet1vl1_pass.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
						       + "__fiducial_b_jet1vl1_pass"
						       + "__"
						       + name_tag
						       ).c_str(),
						     ("p_{T}_b_jet1vl1 - |#eta| < 2.4 - "
						      + FLAVOR_CHANNEL_STRINGS[fc_it]
						      + " ; p_{T}^{l} ; p_{T}^{b jet}"
						      ).c_str(),
						     pt_bins, pt_min, pt_max,
						     pt_bins, pt_min, pt_max
						     )
					   );
    m_h_fiducial_b_jet1vl1_fail.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
						       + "__fiducial_b_jet1vl1_fail"
						       + "__"
						       + name_tag
						       ).c_str(),
						     ("p_{T}_b_jet1vl1 - |#eta| >= 2.4 - "
						      + FLAVOR_CHANNEL_STRINGS[fc_it]
						      + " ; p_{T}^{l} ; p_{T}^{b jet}"
						      ).c_str(),
						     pt_bins, pt_min, pt_max,
						     pt_bins, pt_min, pt_max
						     )
					   );
    m_h_b_jet1vl1_raw_pt.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
					    + "__b_jet1vl1_raw_pt"
					    + "__"
					    + name_tag
					    ).c_str(),
					  ("p_{T}_b_jet1vl1 - "
					   + FLAVOR_CHANNEL_STRINGS[fc_it]
					   + " ; p_{T}^{l} ; p_{T}^{b jet}"
					   ).c_str(),
					  pt_bins/10., pt_min, pt_max,
					  pt_bins/10., pt_min, pt_max
					  )
				);
    m_h_b_jet1vl1_raw_pt_eff.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
					    + "__b_jet1vl1_raw_pt_eff"
					    + "__"
					    + name_tag
					    ).c_str(),
					  ("p_{T}_b_jet1vl1 - "
					   + FLAVOR_CHANNEL_STRINGS[fc_it]
					   + " ; p_{T}^{l} ; p_{T}^{b jet}"
					   ).c_str(),
					  pt_bins/10., pt_min, pt_max,
					  pt_bins/10., pt_min, pt_max
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
					  pt_bins/10., pt_min, pt_max,
					  pt_bins/10., pt_min, pt_max
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
					  pt_bins/10., pt_min, pt_max,
					  pt_bins/10., pt_min, pt_max
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
					  pt_bins/10., pt_min, pt_max,
					  pt_bins/10., pt_min, pt_max
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
					  pt_bins/10., pt_min, pt_max,
					  pt_bins/10., pt_min, pt_max
					  )
				);
					  
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
                                    + " ; m_{T}^{bbll} ; Entries"
                                    ).c_str()
                                  , ptbbll_bins, ptbbll_min, ptbbll_max
                                  )
                        );

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

    // m_h_same_parent_pairing_stop.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
    //                                                   + "__same_parent_pairing_stop"
    //                                                   + "__"
    //                                                   + name_tag
    //                                                   ).c_str()
    //                                                 , ( "same parent - "
    //                                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
    //                                                   + " ; same parent ; Entries"
    //                                                   ).c_str()
    //                                                 , 2, -0.5, 1.5
    //                                                 )
    //                                       );
    // m_h_same_parent_pairing_astp.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
    //                                                   + "__same_parent_pairing_astp"
    //                                                   + "__"
    //                                                   + name_tag
    //                                                   ).c_str()
    //                                                 , ( "same parent - "
    //                                                   + FLAVOR_CHANNEL_STRINGS[fc_it]
    //                                                   + " ; same parent ; Entries"
    //                                                   ).c_str()
    //                                                 , 2, -0.5, 1.5
    //                                                 )
    //                                       );

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
    // initialize event-level eta and fiducial cut histograms
    m_h_eta_event_passfail.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
						  + "__eta_event_passfail"
						  + "__"
						  + name_tag
						  ).c_str()
						, ("|#eta|=2.4 cut - "
						   + FLAVOR_CHANNEL_STRINGS[fc_it]
						   + " ; Fail (0), Pass (1) ; Entries"
						   ).c_str()
						, 2,0.,2.
						)
				      );

    // pt resolution = (pt[object] - pt[truth])/pt[truth]
    m_h_lep_pt_resolution_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
						     + "__lep_pt_resolution_all"
						     + "__"
						     +name_tag
						     ).c_str()
						   , ("p_{T} Resolution - "
						      + FLAVOR_CHANNEL_STRINGS[fc_it]
						      + " ; Resolution ; Entries (no weights)"
						      ).c_str()
						   , 100 , -50. , 50.
						   )
					 );
    m_h_lep_pt_resolution_0.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
						     + "__lep_pt_resolution_0"
						     + "__"
						     +name_tag
						     ).c_str()
						   , ("p_{T}^{1} Resolution - "
						      + FLAVOR_CHANNEL_STRINGS[fc_it]
						      + " ; Resolution ; Entries (no weights)"
						      ).c_str()
						   , 100 , -50. , 50.
						   )
					 );
    m_h_lep_pt_resolution_1.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
						     + "__lep_pt_resolution_1"
						     + "__"
						     +name_tag
						     ).c_str()
						   , ("p_{T}^{1} Resolution - "
						      + FLAVOR_CHANNEL_STRINGS[fc_it]
						      + " ; Resolution ; Entries (no weights)"
						      ).c_str()
						   , 100, -50. , 50.
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

  // lepton pt's
  float pt_l_0 = bl_0.getLepton()->getPt()/1.e3;
  float pt_l_1 = bl_1.getLepton()->getPt()/1.e3;
  if (pt_l_1 > pt_l_0) {
    float tmp = pt_l_0;
    pt_l_0 = pt_l_1;
    pt_l_1 = tmp;
  }

  float eta_l_0 = bl_0.getLepton()->getEta();
  float eta_l_1 = bl_1.getLepton()->getEta();

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
  // are the leptons from a stop?
  int num_lep_from_stop = 0;

  bool lepton_from_stop_0 = (fabs(getLeptonParentPdgId(bl_0.getLepton(), mc_truth)) > 1.e6);
  bool lepton_from_stop_1 = (fabs(getLeptonParentPdgId(bl_1.getLepton(), mc_truth)) > 1.e6);
  if (lepton_from_stop_0) ++num_lep_from_stop;
  if (lepton_from_stop_1) ++num_lep_from_stop;
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

  // // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // std::cout << "lepton 0 parent: " << getLeptonParentPdgId(bl_0.getLepton(), mc_truth) << "\n";
  // std::cout << "jet 0 parent: "    << getJetParentPdgId(bl_0.getJet(), mc_truth) << "  --  dr(j,b): " << dr_jet_q_0 << "\n";
  // int jet_0_pdgid = getJetParentPdgId(bl_0.getJet(), mc_truth);
  // if (fabs(jet_0_pdgid) < 5 || fabs(jet_0_pdgid) == 21) {
  //   std::cout << "\tjet 0 parent index: " << getJetParentIndex(bl_0.getJet(), mc_truth) << "\n";
  // }
  // std::cout << "same parent 0: " << same_parent_pair_0 << "\n";
  // std::cout << "lepton 1 parent: " << getLeptonParentPdgId(bl_1.getLepton(), mc_truth) << "\n";
  // std::cout << "jet 1 parent: "    << getJetParentPdgId(bl_1.getJet(), mc_truth) << "  --  dr(j,b): " << dr_jet_q_1 << "\n";
  // int jet_1_pdgid = getJetParentPdgId(bl_1.getJet(), mc_truth);
  // if (fabs(jet_1_pdgid) < 5 || fabs(jet_1_pdgid) == 21) {
  //   std::cout << "\tjet 1 parent index: " << getJetParentIndex(bl_1.getJet(), mc_truth) << "\n";
  // }
  // std::cout << "same parent 1: " << same_parent_pair_1 << "\n";
  // std::cout << "num same parents: " << num_same_parent_pairs << "\n";
  // std::cout << "\n";

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
      m_h_b_jet_raw_pt_all.at(fc_it)->Fill(pt_b_0);
      m_h_b_jet_raw_pt_0.at(  fc_it)->Fill(pt_b_0);

      m_h_b_jet_eta_all.at(fc_it)->Fill(eta_b_0, weight);
      m_h_b_jet_eta_0.at(  fc_it)->Fill(eta_b_0, weight);

      if (jet_from_stop_0) {
	m_h_b_jet_from_stop_pt_all.at(fc_it)->Fill(pt_b_0, weight);
	m_h_b_jet_from_stop_pt_0.at(  fc_it)->Fill(pt_b_0, weight);
      }

      if (dr_jet_q_0 >= 0) {
        m_h_b_jet_dr_q_all.at(fc_it)->Fill(dr_jet_q_0, weight);
        m_h_b_jet_dr_q_0.at(  fc_it)->Fill(dr_jet_q_0, weight);
      }
    }

    // fill sub-leading jet pt and dphi_bb histograms
    if (num_jet > 1) {
      m_h_b_jet_pt_all.at(fc_it)->Fill(pt_b_1 , weight);
      m_h_b_jet_pt_1.at(  fc_it)->Fill(pt_b_1 , weight);
      m_h_b_jet_raw_pt_all.at(fc_it)->Fill(pt_b_1);
      m_h_b_jet_raw_pt_1.at(  fc_it)->Fill(pt_b_1);
      m_h_dr_bb.at  (     fc_it)->Fill(dr_bb  , weight);
      m_h_dphi_bb.at(     fc_it)->Fill(dphi_bb, weight);
      m_h_deta_bb.at(     fc_it)->Fill(deta_bb, weight);

      m_h_b_jet_eta_all.at(fc_it)->Fill(eta_b_1, weight);
      m_h_b_jet_eta_1.at(  fc_it)->Fill(eta_b_1, weight);

      // fill jet from stop pt histograms
      if (jet_from_stop_1) {
	m_h_b_jet_from_stop_pt_all.at(fc_it)->Fill(pt_b_1, weight);
	m_h_b_jet_from_stop_pt_1.at(  fc_it)->Fill(pt_b_1, weight);
      }

      if (dr_jet_q_1 >= 0) {
        m_h_b_jet_dr_q_all.at(fc_it)->Fill(dr_jet_q_1, weight);
        m_h_b_jet_dr_q_1.at(  fc_it)->Fill(dr_jet_q_1, weight);
      }

      m_h_b_jet1vl1_pt.at(fc_it)->Fill(pt_l_1, pt_b_1, weight);
      m_h_b_jet1vl1_raw_pt.at(fc_it)->Fill(pt_l_1, pt_b_1);

      if (jet_from_stop_0 && jet_from_stop_1) {
	m_h_b_jet_both_from_stop_pt_all.at(fc_it)->Fill(pt_b_0, weight);
	m_h_b_jet_both_from_stop_pt_all.at(fc_it)->Fill(pt_b_1, weight);
	m_h_b_jet_both_from_stop_pt_0.at(  fc_it)->Fill(pt_b_0, weight);
	m_h_b_jet_both_from_stop_pt_1.at(  fc_it)->Fill(pt_b_1, weight);
	if (num_lep_from_stop >=2) m_h_b_jet1vl1_all_from_stop_pt.at(fc_it)->Fill(pt_l_1, pt_b_1, weight);
      }

    }

    // fill jet multiplicity pt plots
    if (num_jet ==2) {
      m_h_b_jet_mult_pt_all.at(fc_it)->Fill(pt_b_0, 2, weight);
      m_h_b_jet_mult_pt_all.at(fc_it)->Fill(pt_b_1, 2, weight);
      m_h_b_jet_mult_pt_0.at(  fc_it)->Fill(pt_b_0, 2, weight);
      m_h_b_jet_mult_pt_1.at(  fc_it)->Fill(pt_b_1, 2, weight);
    }
    if (num_jet ==3) {
      m_h_b_jet_mult_pt_all.at(fc_it)->Fill(pt_b_0, 3, weight);
      m_h_b_jet_mult_pt_all.at(fc_it)->Fill(pt_b_1, 3, weight);
      m_h_b_jet_mult_pt_0.at(  fc_it)->Fill(pt_b_0, 3, weight);
      m_h_b_jet_mult_pt_1.at(  fc_it)->Fill(pt_b_1, 3, weight);
    }
    if (num_jet ==4) {
      m_h_b_jet_mult_pt_all.at(fc_it)->Fill(pt_b_0, 4, weight);
      m_h_b_jet_mult_pt_all.at(fc_it)->Fill(pt_b_1, 4, weight);
      m_h_b_jet_mult_pt_0.at(  fc_it)->Fill(pt_b_0, 4, weight);
      m_h_b_jet_mult_pt_1.at(  fc_it)->Fill(pt_b_1, 4, weight);
    }

    // fill lepton from stop pt histograms
    if (lepton_from_stop_0) {
      m_h_lep_from_stop_pt_all.at(fc_it)->Fill(pt_l_0, weight);
      m_h_lep_from_stop_pt_0.at(  fc_it)->Fill(pt_l_0, weight);
    }
    if (lepton_from_stop_1) {
      m_h_lep_from_stop_pt_all.at(fc_it)->Fill(pt_l_1, weight);
      m_h_lep_from_stop_pt_1.at(  fc_it)->Fill(pt_l_1, weight);
    }
    if (lepton_from_stop_0 && lepton_from_stop_1) {
      m_h_lep_both_from_stop_pt_all.at(fc_it)->Fill(pt_l_0, weight);
      m_h_lep_both_from_stop_pt_all.at(fc_it)->Fill(pt_l_1, weight);
      m_h_lep_both_from_stop_pt_0.at(  fc_it)->Fill(pt_l_0, weight);
      m_h_lep_both_from_stop_pt_1.at(  fc_it)->Fill(pt_l_1, weight);
    }

    // fill mbl histograms
    m_h_mbl_all.at(fc_it)->Fill(mbl_0, weight);
    m_h_mbl_all.at(fc_it)->Fill(mbl_1, weight);
    m_h_mbl_0.at(  fc_it)->Fill(mbl_0, weight);
    m_h_mbl_1.at(  fc_it)->Fill(mbl_1, weight);
    m_h_mbl_diff.at(fc_it)->Fill(fabs(mbl_0 - mbl_1), weight);
    m_h_mbl_ratio.at(fc_it)->Fill(mbl_1/mbl_0, weight);

    // fill ptbl histograms
    m_h_ptbl_all.at(fc_it)->Fill(ptbl_0, weight);
    m_h_ptbl_all.at(fc_it)->Fill(ptbl_1, weight);
    m_h_ptbl_0.at(  fc_it)->Fill(ptbl_0, weight);
    m_h_ptbl_1.at(  fc_it)->Fill(ptbl_1, weight);
    m_h_ptbl_diff.at(fc_it)->Fill(fabs(ptbl_0 - ptbl_1), weight);

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

    m_h_mbbll.at( fc_it)->Fill(mbbll , weight);
    m_h_ptbbll.at(fc_it)->Fill(ptbbll, weight);

    m_h_num_leptons_from_stop.at(fc_it)->Fill(   num_lep_from_stop     , weight);
    m_h_num_jets_from_stop.at(   fc_it)->Fill(   num_jet_from_stop     , weight);
    m_h_num_jets_paired_to_quark.at(fc_it)->Fill(num_jet_paired_to_quark, weight);
    if (dr_jet_q_0 >=0)
      m_h_jet_from_stop_when_paired_to_quark.at(fc_it)->Fill(jet_from_stop_0, weight);
    if (dr_jet_q_1 >=0)
      m_h_jet_from_stop_when_paired_to_quark.at(fc_it)->Fill(jet_from_stop_1, weight);

    // fill "number of same parent pairing" histograms
    m_h_num_same_parent_pairing.at(fc_it)->Fill(num_same_parent_pairs, weight);
    m_h_same_parent_pairing_pair_0.at(fc_it)->Fill(same_parent_pair_0, weight);
    m_h_same_parent_pairing_pair_1.at(fc_it)->Fill(same_parent_pair_1, weight);
    m_h_same_parent_pairing_lep_0.at(fc_it)->Fill(same_parent_lep_0  , weight);
    m_h_same_parent_pairing_lep_1.at(fc_it)->Fill(same_parent_lep_1  , weight);
    m_h_same_parent_pairing_jet_0.at(fc_it)->Fill(same_parent_jet_0  , weight);
    m_h_same_parent_pairing_jet_1.at(fc_it)->Fill(same_parent_jet_1  , weight);
    // m_h_same_parent_pairing_stop.at(fc_it)->Fill(same_parent_stop    , weight);
    // m_h_same_parent_pairing_astp.at(fc_it)->Fill(same_parent_astp    , weight);

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

    // Fill event level eta and fiducial cut histograms
    (pass(eta_b_0, eta_b_1, eta_l_0, eta_l_1) ? m_h_eta_event_passfail.at(fc_it)->Fill(1., weight) :
     m_h_eta_event_passfail.at(fc_it)->Fill(0., weight));
    (pass(eta_b_0, eta_b_1, eta_l_0, eta_l_1) ? m_h_fiducial_b_jet1vl1_pass.at(fc_it)->Fill(pt_l_1, pt_b_1, weight) :
     m_h_fiducial_b_jet1vl1_fail.at(fc_it)->Fill(pt_l_1, pt_b_1, weight));
    
    // fill resolution histograms
    parent_index_0 = getLeptonParentIndex(bl_0.getLepton(), mc_truth);
    parent_index_1 = getLeptonParentIndex(bl_1.getLepton(), mc_truth);
    float pt_parent_0 = 0.;
    float pt_parent_1 = 0.;
    if (parent_index_0 == -1 || parent_index_1 == -1) {
      pt_parent_0 = -99999.;
      pt_parent_1 = -99999.;
    }
    else { // does this work???
      pt_parent_0 = getPt()->at(parent_index_0);
      pt_parent_1 = getPt()->at(parent_index_1);
    }

    float resolution_0 = (pt_l_0 - pt_parent_0)/pt_parent_0;
    float resolution_1 = (pt_l_1 - pt_parent_1)/pt_parent_1;

    m_h_lep_pt_resolution_all.at(fc_it)->Fill(resolution_0);
    m_h_lep_pt_resolution_all.at(fc_it)->Fill(resolution_1);
    m_h_lep_pt_resolution_0.at(fc_it)->Fill(resolution_0);
    m_h_lep_pt_resolution_1.at(fc_it)->Fill(resolution_1);
  }
}

// ----------------------------------------------------------------------------- 
bool PennSusyFrame::BMinusLHists::pass(float eta_b_0, float eta_b_1, float eta_l_0, float eta_l_1)
{
  if (   abs(eta_b_0  ) < 2.4 
      && abs(eta_b_1  ) < 2.4 
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

    m_h_num_b_jet.at(fc_it)->Write();

    m_h_bl_dr_all.at(fc_it)->Write();
    m_h_bl_dr_0.at(fc_it)->Write();
    m_h_bl_dr_1.at(fc_it)->Write();

    m_h_bl_dphi_all.at(fc_it)->Write();
    m_h_bl_dphi_0.at(fc_it)->Write();
    m_h_bl_dphi_1.at(fc_it)->Write();

    m_h_bl_deta_all.at(fc_it)->Write();
    m_h_bl_deta_0.at(fc_it)->Write();
    m_h_bl_deta_1.at(fc_it)->Write();

    m_h_b_jet_pt_all.at(fc_it)->Write();
    m_h_b_jet_pt_0.at(  fc_it)->Write();
    m_h_b_jet_pt_1.at(  fc_it)->Write();

    m_h_b_jet_raw_pt_all.at(fc_it)->Write();
    m_h_b_jet_raw_pt_0.at(  fc_it)->Write();
    m_h_b_jet_raw_pt_1.at(  fc_it)->Write();

    m_h_b_jet_from_stop_pt_all.at(fc_it)->Write();
    m_h_b_jet_from_stop_pt_0.at(  fc_it)->Write();
    m_h_b_jet_from_stop_pt_1.at(  fc_it)->Write();

    m_h_b_jet_both_from_stop_pt_all.at(fc_it)->Write();
    m_h_b_jet_both_from_stop_pt_0.at(  fc_it)->Write();
    m_h_b_jet_both_from_stop_pt_1.at(  fc_it)->Write();

    m_h_b_jet_mult_pt_all.at(fc_it)->Write();
    m_h_b_jet_mult_pt_0.at(  fc_it)->Write();
    m_h_b_jet_mult_pt_1.at(  fc_it)->Write();

    m_h_lep_from_stop_pt_all.at(fc_it)->Write();
    m_h_lep_from_stop_pt_0.at(  fc_it)->Write();
    m_h_lep_from_stop_pt_1.at(  fc_it)->Write();

    m_h_lep_both_from_stop_pt_all.at(fc_it)->Write();
    m_h_lep_both_from_stop_pt_0.at(  fc_it)->Write();
    m_h_lep_both_from_stop_pt_1.at(  fc_it)->Write();

    m_h_b_jet_dr_q_all.at(fc_it)->Write();
    m_h_b_jet_dr_q_0.at(  fc_it)->Write();
    m_h_b_jet_dr_q_1.at(  fc_it)->Write();

    m_h_dr_bb.at(fc_it)->Write();
    m_h_dphi_bb.at(fc_it)->Write();
    m_h_deta_bb.at(fc_it)->Write();

    m_h_b_jet_eta_all.at(fc_it)->Write();
    m_h_b_jet_eta_0.at(  fc_it)->Write();
    m_h_b_jet_eta_1.at(  fc_it)->Write();

    m_h_mbl_all.at(fc_it)->Write();
    m_h_mbl_0.at(  fc_it)->Write();
    m_h_mbl_1.at(  fc_it)->Write();
    m_h_mbl_diff.at(fc_it)->Write();
    m_h_mbl_ratio.at(fc_it)->Write();

    m_h_ptbl_all.at(fc_it)->Write();
    m_h_ptbl_0.at(  fc_it)->Write();
    m_h_ptbl_1.at(  fc_it)->Write();
    m_h_ptbl_diff.at(fc_it)->Write();

    bool raw = 0;
    m_h_b_jet1vl1_pt.at(fc_it)->Write();
    calcEff2d(m_h_b_jet1vl1_pt.at(fc_it),m_h_b_jet1vl1_pt_eff.at(fc_it),m_h_b_jet1vl1_pt_num.at(fc_it), raw);
    m_h_b_jet1vl1_pt_eff.at(fc_it)->Write();
    m_h_b_jet1vl1_pt_num.at(fc_it)->Write();

    raw = 1;
    m_h_b_jet1vl1_raw_pt.at(fc_it)->Write();
    calcEff2d(m_h_b_jet1vl1_raw_pt.at(fc_it),m_h_b_jet1vl1_raw_pt_eff.at(fc_it),m_h_b_jet1vl1_raw_pt_num.at(fc_it), raw);
    m_h_b_jet1vl1_raw_pt_num.at(fc_it)->Write();

    raw = 0;
    m_h_b_jet1vl1_all_from_stop_pt.at(fc_it)->Write();
    calcEff2d(m_h_b_jet1vl1_all_from_stop_pt.at(fc_it),m_h_b_jet1vl1_all_from_stop_pt_eff.at(fc_it),m_h_b_jet1vl1_all_from_stop_pt_num.at(fc_it), raw);
    m_h_b_jet1vl1_all_from_stop_pt_eff.at(fc_it)->Write();
    m_h_b_jet1vl1_all_from_stop_pt_num.at(fc_it)->Write();

    m_h_fiducial_b_jet1vl1_pass.at(fc_it)->Write();
    m_h_fiducial_b_jet1vl1_fail.at(fc_it)->Write();

    m_h_mbl_anti_pairing_all.at(fc_it)->Write();
    m_h_mbl_anti_pairing_0.at(  fc_it)->Write();
    m_h_mbl_anti_pairing_1.at(  fc_it)->Write();
    m_h_mbl_anti_pairing_diff.at(fc_it)->Write();
    m_h_mbl_anti_pairing_ratio.at(fc_it)->Write();

    m_h_mbbll.at(fc_it)->Write();
    m_h_ptbbll.at(fc_it)->Write();

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

    m_h_eta_event_passfail.at(fc_it)->Write();
    
    m_h_lep_pt_resolution_all.at(fc_it)->Write();
    m_h_lep_pt_resolution_0.at(fc_it)->Write();
    m_h_lep_pt_resolution_1.at(fc_it)->Write();
  }
}

// ------------------------------------------------------------

void PennSusyFrame::BMinusLHists::calcEff2d(TH2F* pt_2d, TH2F* pt_2d_eff, TH2F* pt_2d_num, bool raw) {
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
