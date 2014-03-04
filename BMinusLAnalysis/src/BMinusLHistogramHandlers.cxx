#include "BMinusLAnalysis/include/BMinusLHistogramHandlers.h"
#include "BMinusLAnalysis/include/BMinusLUtils.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/Calculators.h"

#include "TFile.h"
#include "TDirectory.h"
#include "TH1.h"

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

  const int   mbl_bins = 60;
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

  if (fc == FLAVOR_NONE) return;

  size_t num_jet = b_jet_list->size();

  float pt_0 = ( num_jet > 0 ? b_jet_list->at(0)->getPt()/1.e3 : 0.);
  float pt_1 = ( num_jet > 1 ? b_jet_list->at(1)->getPt()/1.e3 : 0.);

  m_h_num_b_jet.at(         fc)->Fill(num_jet, weight);
  m_h_num_b_jet.at(FLAVOR_NONE)->Fill(num_jet, weight);

  if (num_jet > 0) {
    m_h_b_jet_pt_all.at(fc)->Fill(pt_0, weight);
    m_h_b_jet_pt_0.at(  fc)->Fill(pt_0, weight);
    m_h_b_jet_pt_all.at(FLAVOR_NONE)->Fill(pt_0, weight);
    m_h_b_jet_pt_0.at(  FLAVOR_NONE)->Fill(pt_0, weight);
  }

  if (num_jet > 1) {
    m_h_b_jet_pt_all.at(fc)->Fill(pt_1, weight);
    m_h_b_jet_pt_1.at(  fc)->Fill(pt_1, weight);

    m_h_b_jet_pt_all.at(FLAVOR_NONE)->Fill(pt_1, weight);
    m_h_b_jet_pt_1.at(  FLAVOR_NONE)->Fill(pt_1, weight);
  }

  // fill mbl plots
  float mbl_0 = bl_0.getMbl()/1.e3;
  float mbl_1 = bl_1.getMbl()/1.e3;

  m_h_mbl_all.at(FLAVOR_NONE)->Fill(mbl_0, weight);
  m_h_mbl_all.at(FLAVOR_NONE)->Fill(mbl_1, weight);
  m_h_mbl_0.at(  FLAVOR_NONE)->Fill(mbl_0, weight);
  m_h_mbl_1.at(  FLAVOR_NONE)->Fill(mbl_1, weight);

  m_h_mbl_all.at(fc)->Fill(mbl_0, weight);
  m_h_mbl_all.at(fc)->Fill(mbl_1, weight);
  m_h_mbl_0.at(  fc)->Fill(mbl_0, weight);
  m_h_mbl_1.at(  fc)->Fill(mbl_1, weight);

  // fill ptbl plots
  float ptbl_0 = bl_0.getPtbl()/1.e3;
  float ptbl_1 = bl_1.getPtbl()/1.e3;

  m_h_ptbl_all.at(FLAVOR_NONE)->Fill(ptbl_0, weight);
  m_h_ptbl_all.at(FLAVOR_NONE)->Fill(ptbl_1, weight);
  m_h_ptbl_0.at(  FLAVOR_NONE)->Fill(ptbl_0, weight);
  m_h_ptbl_1.at(  FLAVOR_NONE)->Fill(ptbl_1, weight);

  m_h_ptbl_all.at(fc)->Fill(ptbl_0, weight);
  m_h_ptbl_all.at(fc)->Fill(ptbl_1, weight);
  m_h_ptbl_0.at(  fc)->Fill(ptbl_0, weight);
  m_h_ptbl_1.at(  fc)->Fill(ptbl_1, weight);

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

  m_h_mbl_anti_pairing_all.at(FLAVOR_NONE)->Fill(mbl_anti_pair_0, weight);
  m_h_mbl_anti_pairing_all.at(FLAVOR_NONE)->Fill(mbl_anti_pair_1, weight);
  m_h_mbl_anti_pairing_0.at(  FLAVOR_NONE)->Fill(mbl_anti_pair_0, weight);
  m_h_mbl_anti_pairing_1.at(  FLAVOR_NONE)->Fill(mbl_anti_pair_1, weight);

  m_h_mbl_anti_pairing_all.at(fc)->Fill(mbl_anti_pair_0, weight);
  m_h_mbl_anti_pairing_all.at(fc)->Fill(mbl_anti_pair_1, weight);
  m_h_mbl_anti_pairing_0.at(  fc)->Fill(mbl_anti_pair_0, weight);
  m_h_mbl_anti_pairing_1.at(  fc)->Fill(mbl_anti_pair_1, weight);

  // check if b and l from each pair are from the same parent
  // std::cout << "\n--------------------------------------------------------------------------------\n";
  // std::cout << "checking same parent for 00\n";
  bool same_parent_pair_0 = PennSusyFrame::sameParent( event
                                                     , bl_0.getLepton()
                                                     , bl_0.getJet()
                                                     , mc_truth
                                                     );
  // std::cout << "checking same parent for 11\n";
  bool same_parent_pair_1 = PennSusyFrame::sameParent( event
                                                     , bl_1.getLepton()
                                                     , bl_1.getJet()
                                                     , mc_truth
                                                     );
  int num_same_parent_pairs = 0;
  if (same_parent_pair_0) ++num_same_parent_pairs;
  if (same_parent_pair_1) ++num_same_parent_pairs;
  m_h_num_same_parent_pairing.at(FLAVOR_NONE)->Fill(num_same_parent_pairs, weight);
  m_h_num_same_parent_pairing.at(fc         )->Fill(num_same_parent_pairs, weight);

  // std::cout << "checking same parent for 01\n";
  bool same_parent_anti_pair_0 = PennSusyFrame::sameParent( event
                                                          , bl_anti_pair_0.getLepton()
                                                          , bl_anti_pair_0.getJet()
                                                          , mc_truth
                                                          );
  // std::cout << "checking same parent for 10\n";
  bool same_parent_anti_pair_1 = PennSusyFrame::sameParent( event
                                                          , bl_anti_pair_1.getLepton()
                                                          , bl_anti_pair_1.getJet()
                                                          , mc_truth
                                                          );

  // look at possible pairs, compute mbl for objects coming from same pairs
  if (same_parent_pair_0) {
    m_h_mbl_same_parent_pairing.at(FLAVOR_NONE)->Fill(mbl_0);
    m_h_mbl_same_parent_pairing.at(fc         )->Fill(mbl_0);
  }
  else {
    m_h_mbl_diff_parent_pairing.at(FLAVOR_NONE)->Fill(mbl_0);
    m_h_mbl_diff_parent_pairing.at(fc         )->Fill(mbl_0);
  }

  if (same_parent_pair_1) {
    m_h_mbl_same_parent_pairing.at(FLAVOR_NONE)->Fill(mbl_1);
    m_h_mbl_same_parent_pairing.at(fc         )->Fill(mbl_1);
  }
  else {
    m_h_mbl_diff_parent_pairing.at(FLAVOR_NONE)->Fill(mbl_1);
    m_h_mbl_diff_parent_pairing.at(fc         )->Fill(mbl_1);
  }

  // if (l_0 && b_1 from same parent) {
  if (same_parent_anti_pair_0) {
    m_h_mbl_same_parent_pairing.at(FLAVOR_NONE)->Fill(mbl_anti_pair_0);
    m_h_mbl_same_parent_pairing.at(fc         )->Fill(mbl_anti_pair_0);
  }
  else {
    m_h_mbl_diff_parent_pairing.at(FLAVOR_NONE)->Fill(mbl_anti_pair_0);
    m_h_mbl_diff_parent_pairing.at(fc         )->Fill(mbl_anti_pair_0);
  }

  // if (l_1 && b_0 from same parent) {
  if (same_parent_anti_pair_1) {
    m_h_mbl_same_parent_pairing.at(FLAVOR_NONE)->Fill(mbl_anti_pair_1);
    m_h_mbl_same_parent_pairing.at(fc         )->Fill(mbl_anti_pair_1);
  }
  else {
    m_h_mbl_diff_parent_pairing.at(FLAVOR_NONE)->Fill(mbl_anti_pair_1);
    m_h_mbl_diff_parent_pairing.at(fc         )->Fill(mbl_anti_pair_1);
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLHists::write(TDirectory* d)
{
  d->cd();

  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    if (FLAVOR_CHANNEL_STRINGS[fc_it] == "flavor_error") continue;

    m_h_num_b_jet.at(fc_it)->Write();

    m_h_b_jet_pt_all.at(fc_it)->Write();
    m_h_b_jet_pt_0.at(  fc_it)->Write();
    m_h_b_jet_pt_1.at(  fc_it)->Write();

    m_h_mbl_all.at(fc_it)->Write();
    m_h_mbl_0.at(  fc_it)->Write();
    m_h_mbl_1.at(  fc_it)->Write();

    m_h_ptbl_all.at(fc_it)->Write();
    m_h_ptbl_0.at(  fc_it)->Write();
    m_h_ptbl_1.at(  fc_it)->Write();

    m_h_mbl_anti_pairing_all.at(fc_it)->Write();
    m_h_mbl_anti_pairing_0.at(  fc_it)->Write();
    m_h_mbl_anti_pairing_1.at(  fc_it)->Write();

    m_h_num_same_parent_pairing.at(fc_it)->Write();

    m_h_mbl_same_parent_pairing.at(fc_it)->Write();
    m_h_mbl_diff_parent_pairing.at(fc_it)->Write();
  }
}
