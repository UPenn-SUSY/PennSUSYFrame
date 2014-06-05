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

  const int   num_jet_bins = 4;
  const float num_jet_min  = -0.5;
  const float num_jet_max  = num_jet_bins - num_jet_min;

  const int   pt_bins = 50;
  const float pt_min  = 0.;
  const float pt_max  = 500.;

  const int   eta_bins = 50;
  const float eta_min = -5.;
  const float eta_max = 5.;

  const int   mbl_bins = 120;
  const float mbl_min  = 0.;
  const float mbl_max  = 1200.;

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
                                  , ( "p_{bl,0} - "
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

    // initialize pt_b1vl1 histograms
    m_h_pt_b_jet1vl1.push_back( new TH2F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
					    + "__pt_b_jet1vl1"
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


    // initialize same parent pairing
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

    // initialize mbl for same parent pairing histograms
    m_h_mbl_same_parent_pairing.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                     + "__mbl_same_parent_pairing"
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

    // initialize mbl for different parent pairing histograms
    m_h_mbl_diff_parent_pairing.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                                     + "__mbl_diff_parent_pairing"
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

  if (fc == FLAVOR_NONE || fc == FLAVOR_ERROR_1) return;

  size_t num_jet = b_jet_list->size();
  
  // b jet pt's
  float pt_0 = ( num_jet > 0 ? b_jet_list->at(0)->getPt()/1.e3 : 0.);
  float pt_1 = ( num_jet > 1 ? b_jet_list->at(1)->getPt()/1.e3 : 0.);

  // lepton pt's
  float pt_0_l = bl_0.getLepton()->getPt()/1.e3;
  float pt_1_l = bl_1.getLepton()->getPt()/1.e3;
  if (pt_1_l > pt_0_l) {
    float tmp = pt_0_l;
    pt_0_l = pt_1_l;
    pt_1_l = tmp;
  }

  float eta_0 = ( num_jet > 0 ? b_jet_list->at(0)->getEta() : 0.);
  float eta_1 = ( num_jet > 1 ? b_jet_list->at(1)->getEta() : 0.);
  float eta_0_l = bl_0.getLepton()->getEta();
  float eta_1_l = bl_1.getLepton()->getEta();

  // fill mbl plots
  float mbl_0 = bl_0.getMbl()/1.e3;
  float mbl_1 = bl_1.getMbl()/1.e3;

  // fill ptbl plots
  float ptbl_0 = bl_0.getPtbl()/1.e3;
  float ptbl_1 = bl_1.getPtbl()/1.e3;

  // get b-l pairs for the anti-pairing
  PennSusyFrame::blPair bl_anti_pair_0(bl_0.getJet(), bl_1.getLepton());
  PennSusyFrame::blPair bl_anti_pair_1(bl_1.getJet(), bl_0.getLepton());

  if (bl_anti_pair_1.getMbl() > bl_anti_pair_0.getMbl()) {
    PennSusyFrame::blPair tmp = bl_anti_pair_0;
    bl_anti_pair_0 = bl_anti_pair_1;
    bl_anti_pair_1 = tmp;
  }

  // fill mbl plots for anti-pairing
  float mbl_anti_pair_0 = bl_anti_pair_0.getMbl()/1.e3;
  float mbl_anti_pair_1 = bl_anti_pair_1.getMbl()/1.e3;

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

  // loop over all flavor channels
  for (int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    if (fc_it == FLAVOR_ERROR_1) continue;
    if (fc_it != FLAVOR_NONE && fc_it != fc) continue;

    // fill b jet multiplicity plots
    m_h_num_b_jet.at(fc_it)->Fill(num_jet, weight);

    // fill leading jet pt,eta histograms
    if (num_jet > 0) {
      m_h_b_jet_pt_all.at(fc_it)->Fill(pt_0, weight);
      m_h_b_jet_pt_0.at(  fc_it)->Fill(pt_0, weight);

      m_h_b_jet_eta_all.at(fc_it)->Fill(eta_0, weight);
      m_h_b_jet_eta_0.at(  fc_it)->Fill(eta_0, weight);
    }

    // fill sub-leading jet pt,eta histograms
    if (num_jet > 1) {
      m_h_b_jet_pt_all.at(fc_it)->Fill(pt_1, weight);
      m_h_b_jet_pt_1.at(  fc_it)->Fill(pt_1, weight);

      m_h_b_jet_eta_all.at(fc_it)->Fill(eta_1, weight);
      m_h_b_jet_eta_1.at(  fc_it)->Fill(eta_1, weight);

      m_h_pt_b_jet1vl1.at(fc_it)->Fill(pt_1_l, pt_1, weight);

    }

    // fill mbl histograms
    m_h_mbl_all.at(fc_it)->Fill(mbl_0, weight);
    m_h_mbl_all.at(fc_it)->Fill(mbl_1, weight);
    m_h_mbl_0.at(  fc_it)->Fill(mbl_0, weight); 
   m_h_mbl_1.at(  fc_it)->Fill(mbl_1, weight);

    // fill ptbl histograms
    m_h_ptbl_all.at(fc_it)->Fill(ptbl_0, weight);
    m_h_ptbl_all.at(fc_it)->Fill(ptbl_1, weight);
    m_h_ptbl_0.at(  fc_it)->Fill(ptbl_0, weight);
    m_h_ptbl_1.at(  fc_it)->Fill(ptbl_1, weight);

    // fill mbl for anti-pairs histograms
    m_h_mbl_anti_pairing_all.at(fc_it)->Fill(mbl_anti_pair_0, weight);
    m_h_mbl_anti_pairing_all.at(fc_it)->Fill(mbl_anti_pair_1, weight);
    m_h_mbl_anti_pairing_0.at(  fc_it)->Fill(mbl_anti_pair_0, weight);
    m_h_mbl_anti_pairing_1.at(  fc_it)->Fill(mbl_anti_pair_1, weight);

    // fill "number of same parent pairing" histograms
    m_h_num_same_parent_pairing.at(fc_it)->Fill(num_same_parent_pairs, weight);

    // look at possible pairs, compute mbl for objects coming from same pairs
    if (same_parent_pair_0) {
      m_h_mbl_same_parent_pairing.at(fc_it)->Fill(mbl_0, weight);
    }
    else {
      m_h_mbl_diff_parent_pairing.at(fc_it)->Fill(mbl_0, weight);
    }

    if (same_parent_pair_1) {
      m_h_mbl_same_parent_pairing.at(fc_it)->Fill(mbl_1, weight);
    }
    else {
      m_h_mbl_diff_parent_pairing.at(fc_it)->Fill(mbl_1, weight);
    }

    if (same_parent_anti_pair_0) {
      m_h_mbl_same_parent_pairing.at(fc_it)->Fill(mbl_anti_pair_0, weight);
    }
    else {
      m_h_mbl_diff_parent_pairing.at(fc_it)->Fill(mbl_anti_pair_0, weight);
    }

    if (same_parent_anti_pair_1) {
      m_h_mbl_same_parent_pairing.at(fc_it)->Fill(mbl_anti_pair_1, weight);
    }
    else {
      m_h_mbl_diff_parent_pairing.at(fc_it)->Fill(mbl_anti_pair_1, weight);
    }

    // Fill event level eta and fiducial cut histograms
    (pass(eta_0, eta_1, eta_0_l, eta_1_l) ? m_h_eta_event_passfail.at(fc_it)->Fill(1., weight) :
     m_h_eta_event_passfail.at(fc_it)->Fill(0., weight));
    (pass(eta_0, eta_1, eta_0_l, eta_1_l) ? m_h_fiducial_b_jet1vl1_pass.at(fc_it)->Fill(pt_1_l, pt_1, weight) :
     m_h_fiducial_b_jet1vl1_fail.at(fc_it)->Fill(pt_1_l, pt_1, weight));
  }
}

// ----------------------------------------------------------------------------- 
bool PennSusyFrame::BMinusLHists::pass(float eta_0, float eta_1, float eta_0_l, float eta_1_l)
{
  if (   abs(eta_0  ) < 2.4 
      && abs(eta_1  ) < 2.4 
      && abs(eta_0_l) < 2.4 
      && abs(eta_1_l) < 2.4) {
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

    m_h_b_jet_pt_all.at(fc_it)->Write();
    m_h_b_jet_pt_0.at(  fc_it)->Write();
    m_h_b_jet_pt_1.at(  fc_it)->Write();

    m_h_b_jet_eta_all.at(fc_it)->Write();
    m_h_b_jet_eta_0.at(  fc_it)->Write();
    m_h_b_jet_eta_1.at(  fc_it)->Write();

    m_h_mbl_all.at(fc_it)->Write();
    m_h_mbl_0.at(  fc_it)->Write();
    m_h_mbl_1.at(  fc_it)->Write();

    m_h_ptbl_all.at(fc_it)->Write();
    m_h_ptbl_0.at(  fc_it)->Write();
    m_h_ptbl_1.at(  fc_it)->Write();

    m_h_pt_b_jet1vl1.at(fc_it)->Write();
    m_h_fiducial_b_jet1vl1_pass.at(fc_it)->Write();
    m_h_fiducial_b_jet1vl1_fail.at(fc_it)->Write();

    m_h_mbl_anti_pairing_all.at(fc_it)->Write();
    m_h_mbl_anti_pairing_0.at(  fc_it)->Write();
    m_h_mbl_anti_pairing_1.at(  fc_it)->Write();

    m_h_num_same_parent_pairing.at(fc_it)->Write();

    m_h_mbl_same_parent_pairing.at(fc_it)->Write();
    m_h_mbl_diff_parent_pairing.at(fc_it)->Write();

    m_h_eta_event_passfail.at(fc_it)->Write();
  }
}
