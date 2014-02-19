#include "BMinusLAnalysis/include/BMinusLHistogramHandlers.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"

#include "TFile.h"
#include "TDirectory.h"
#include "TH1.h"

// =============================================================================
PennSusyFrame::BMinusLHists::BMinusLHists()
{
  const int   num_jet_bins = 4;
  const float num_jet_min  = -0.5;
  const float num_jet_max  = num_jet_bins - num_jet_min;

  const int   pt_bins = 50;
  const float pt_min  = 0.;
  const float pt_max  = 500.;

  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize pt histograms
    m_h_num_b_jet.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + "__num_b_jet"
                                       ).c_str()
                                     , ( "B Jet multiplicity - "
                                       + FLAVOR_CHANNEL_STRINGS[fc_it]
                                       + " ; B Jet multiplicity ; Entries"
                                       ).c_str()
                                     , num_jet_bins, num_jet_min, num_jet_max
                                     )
                           );

    m_h_b_jet_pt_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                          + "__b_jet_pt_all"
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
                                        ).c_str()
                                      , ( "p_{T}^{1} - "
                                        + FLAVOR_CHANNEL_STRINGS[fc_it]
                                        + " ; p_{T}^{1} [GeV] ; Entries"
                                        ).c_str()
                                      , pt_bins, pt_min, pt_max
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
                                             , float weight
                                             )
{
  FLAVOR_CHANNEL fc = event.getFlavorChannel();

  if (fc == FLAVOR_NONE) {
    return;
  }

  size_t num_jet = b_jet_list->size();

  float pt_0 = ( num_jet > 0 ? b_jet_list->at(0)->getPt()/1.e3 : 0.);
  float pt_1 = ( num_jet > 1 ? b_jet_list->at(1)->getPt()/1.e3 : 0.);

  m_h_num_b_jet.at(fc         )->Fill(num_jet, weight);
  m_h_num_b_jet.at(FLAVOR_NONE)->Fill(num_jet, weight);

  if (num_jet > 0) {
    m_h_b_jet_pt_all.at(fc)->Fill(pt_0, weight);
    m_h_b_jet_pt_0.at(fc  )->Fill(pt_0, weight);
    m_h_b_jet_pt_all.at(FLAVOR_NONE)->Fill(pt_0, weight);
    m_h_b_jet_pt_0.at(FLAVOR_NONE  )->Fill(pt_0, weight);
  }

  if (num_jet > 1) {
    m_h_b_jet_pt_all.at(fc)->Fill(pt_1, weight);
    m_h_b_jet_pt_1.at(fc  )->Fill(pt_1, weight);

    m_h_b_jet_pt_all.at(FLAVOR_NONE)->Fill(pt_1, weight);
    m_h_b_jet_pt_1.at(FLAVOR_NONE  )->Fill(pt_1, weight);
  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::BMinusLHists::write(TDirectory* d)
{
  d->cd();

  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize pt histograms
    m_h_num_b_jet.at(   fc_it)->Write();
    m_h_b_jet_pt_all.at(fc_it)->Write();
    m_h_b_jet_pt_0.at(  fc_it)->Write();
    m_h_b_jet_pt_1.at(  fc_it)->Write();
  }
}
