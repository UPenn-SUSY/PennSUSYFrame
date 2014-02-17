#include "HistogramHandlers/include/HistogramHandlers.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"

#include "TFile.h"
#include "TH1.h"

// =============================================================================
PennSusyFrame::HistogramHandler::HistogramHandler()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void PennSusyFrame::HistogramHandler::Fill( const PennSusyFrame::Event&
                                          , const std::vector<PennSusyFrame::Electron*>*
                                          , const std::vector<PennSusyFrame::Muon*>*
                                          , const std::vector<PennSusyFrame::Jet*>*
                                          , float
                                          )
{
  // do nothing
}

// -----------------------------------------------------------------------------
void PennSusyFrame::HistogramHandler::write(TFile*)
{
  // do nothing
}

// =============================================================================
PennSusyFrame::LeptonKinematicsHists::LeptonKinematicsHists()
{
  const int   pt_bins = 150;
  const float pt_min  = 0.;
  const float pt_max  = 1500.;

  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize pt histograms
    m_h_pt_all.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                    + "__lep_pt_all"
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
void PennSusyFrame::LeptonKinematicsHists::Fill( const PennSusyFrame::Event& event
                                               , const std::vector<PennSusyFrame::Electron*>* el_list
                                               , const std::vector<PennSusyFrame::Muon*>* mu_list
                                               , const std::vector<PennSusyFrame::Jet*>*
                                               , float weight
                                               )
{
  FLAVOR_CHANNEL fc = event.getFlavorChannel();

  if (fc == FLAVOR_NONE) return;

  float pt_0 = 0.;
  float pt_1 = 0.;

  if (fc == FLAVOR_EE) {
    pt_0 = el_list->at(0)->getPt();
    pt_1 = el_list->at(1)->getPt();

    m_h_pt_all.at(FLAVOR_EE)->Fill(pt_0, weight);
    m_h_pt_all.at(FLAVOR_EE)->Fill(pt_1, weight);
    m_h_pt_0.at(FLAVOR_EE  )->Fill(pt_0, weight);
    m_h_pt_1.at(FLAVOR_EE  )->Fill(pt_1, weight);
  }
  else if (fc == FLAVOR_MM) {
    pt_0 = mu_list->at(0)->getPt();
    pt_1 = mu_list->at(1)->getPt();

    m_h_pt_all.at(FLAVOR_MM)->Fill(pt_0, weight);
    m_h_pt_all.at(FLAVOR_MM)->Fill(pt_1, weight);
    m_h_pt_0.at(FLAVOR_MM  )->Fill(pt_0, weight);
    m_h_pt_1.at(FLAVOR_MM  )->Fill(pt_1, weight);
  }
  else {
    pt_0 = el_list->at(0)->getPt();
    pt_1 = mu_list->at(0)->getPt();

    m_h_pt_all.at(FLAVOR_MM)->Fill(pt_0, weight);
    m_h_pt_all.at(FLAVOR_MM)->Fill(pt_1, weight);
    m_h_pt_0.at(FLAVOR_MM  )->Fill(pt_0, weight);
    m_h_pt_1.at(FLAVOR_MM  )->Fill(pt_1, weight);
  }

  if (pt_1 > pt_0) {
    float pt_tmp = pt_0;
    pt_0 = pt_1;
    pt_1 = pt_tmp;
  }

  m_h_pt_all.at(FLAVOR_NONE)->Fill(pt_0, weight);
  m_h_pt_all.at(FLAVOR_NONE)->Fill(pt_1, weight);
  m_h_pt_0.at(FLAVOR_NONE  )->Fill(pt_0, weight);
  m_h_pt_1.at(FLAVOR_NONE  )->Fill(pt_1, weight);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::LeptonKinematicsHists::write(TFile* f)
{
  f->cd();

  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize pt histograms
    m_h_pt_all.at(fc_it)->Write();
    m_h_pt_0.at(  fc_it)->Write();
    m_h_pt_1.at(  fc_it)->Write();
  }

}
