#include "HistogramHandlers/include/HistogramHandlers.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"

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
void PennSusyFrame::HistogramHandler::Fill( const PennSusyFrame::Event&
                                          , const PennSusyFrame::EventLevelQuantities&
                                          , const std::vector<PennSusyFrame::Electron*>*
                                          , const std::vector<PennSusyFrame::Muon*>*
                                          , const std::vector<PennSusyFrame::Jet*>*
                                          , const PennSusyFrame::Met&
                                          , float
                                          )
{
  // do nothing
}

// -----------------------------------------------------------------------------
void PennSusyFrame::HistogramHandler::write(TDirectory*)
{
  // do nothing
}

// =============================================================================
PennSusyFrame::EventLevelHists::EventLevelHists(std::string name_tag)
{
  const int   mll_bins = 50;
  const float mll_min  = 0.;
  const float mll_max  = 500.;

  const int   mt2_bins = 50;
  const float mt2_min  = 0.;
  const float mt2_max  = 500.;

  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
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

  if (fc == FLAVOR_NONE) {
    return;
  }

  float mll = event_level_quantities.getMll()/1.e3;
  float mt2 = event_level_quantities.getMt2()/1.e3;

  m_h_mll.at(fc)->Fill(mll, weight);
  m_h_mt2.at(fc)->Fill(mt2, weight);

  m_h_mll.at(FLAVOR_NONE)->Fill(mll, weight);
  m_h_mt2.at(FLAVOR_NONE)->Fill(mt2, weight);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::EventLevelHists::write(TDirectory* d)
{
  d->cd();

  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // write mll histograms
    m_h_mll.at(fc_it)->Write();

    // write mt2 histograms
    m_h_mt2.at(fc_it)->Write();
  }
}

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// =============================================================================
PennSusyFrame::LeptonKinematicsHists::LeptonKinematicsHists(std::string name_tag)
{
  const int   pt_bins = 50;
  const float pt_min  = 0.;
  const float pt_max  = 500.;

  const int   ptiso_bins = 30;
  const float ptiso_min  = 0.;
  const float ptiso_max  = 3.;

  const int   etiso_bins = 40;
  const float etiso_min  = -1.;
  const float etiso_max  = 3.;

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

  if (fc == FLAVOR_NONE) {
    return;
  }

  float pt_0 = 0.;
  float pt_1 = 0.;

  float ptiso_0 = 0.;
  float ptiso_1 = 0.;

  float etiso_0 = 0.;
  float etiso_1 = 0.;

  if (fc == FLAVOR_EE) {
    pt_0 = el_list->at(0)->getPt()/1.e3;
    pt_1 = el_list->at(1)->getPt()/1.e3;

    ptiso_0 = el_list->at(0)->getPtIsoRatio();
    ptiso_1 = el_list->at(1)->getPtIsoRatio();

    etiso_0 = el_list->at(0)->getEtIsoRatio();
    etiso_1 = el_list->at(1)->getEtIsoRatio();

    m_h_pt_all.at(FLAVOR_EE)->Fill(pt_0, weight);
    m_h_pt_all.at(FLAVOR_EE)->Fill(pt_1, weight);
    m_h_pt_0.at(  FLAVOR_EE)->Fill(pt_0, weight);
    m_h_pt_1.at(  FLAVOR_EE)->Fill(pt_1, weight);

    m_h_ptiso_all.at(FLAVOR_EE)->Fill(ptiso_0, weight);
    m_h_ptiso_all.at(FLAVOR_EE)->Fill(ptiso_1, weight);
    m_h_ptiso_0.at(  FLAVOR_EE)->Fill(ptiso_0, weight);
    m_h_ptiso_1.at(  FLAVOR_EE)->Fill(ptiso_1, weight);

    m_h_etiso_all.at(FLAVOR_EE)->Fill(etiso_0, weight);
    m_h_etiso_all.at(FLAVOR_EE)->Fill(etiso_1, weight);
    m_h_etiso_0.at(  FLAVOR_EE)->Fill(etiso_0, weight);
    m_h_etiso_1.at(  FLAVOR_EE)->Fill(etiso_1, weight);
  }
  else if (fc == FLAVOR_MM) {
    pt_0 = mu_list->at(0)->getPt()/1.e3;
    pt_1 = mu_list->at(1)->getPt()/1.e3;

    ptiso_0 = mu_list->at(0)->getPtIsoRatio();
    ptiso_1 = mu_list->at(1)->getPtIsoRatio();

    etiso_0 = mu_list->at(0)->getEtIsoRatio();
    etiso_1 = mu_list->at(1)->getEtIsoRatio();

    m_h_pt_all.at(FLAVOR_MM)->Fill(pt_0, weight);
    m_h_pt_all.at(FLAVOR_MM)->Fill(pt_1, weight);
    m_h_pt_0.at(  FLAVOR_MM)->Fill(pt_0, weight);
    m_h_pt_1.at(  FLAVOR_MM)->Fill(pt_1, weight);

    m_h_ptiso_all.at(FLAVOR_MM)->Fill(ptiso_0, weight);
    m_h_ptiso_all.at(FLAVOR_MM)->Fill(ptiso_1, weight);
    m_h_ptiso_0.at(  FLAVOR_MM)->Fill(ptiso_0, weight);
    m_h_ptiso_1.at(  FLAVOR_MM)->Fill(ptiso_1, weight);

    m_h_etiso_all.at(FLAVOR_MM)->Fill(etiso_0, weight);
    m_h_etiso_all.at(FLAVOR_MM)->Fill(etiso_1, weight);
    m_h_etiso_0.at(  FLAVOR_MM)->Fill(etiso_0, weight);
    m_h_etiso_1.at(  FLAVOR_MM)->Fill(etiso_1, weight);
  }
  else {
    pt_0 = el_list->at(0)->getPt()/1.e3;
    pt_1 = mu_list->at(0)->getPt()/1.e3;

    ptiso_0 = el_list->at(0)->getPtIsoRatio();
    ptiso_1 = mu_list->at(0)->getPtIsoRatio();

    etiso_0 = el_list->at(0)->getEtIsoRatio();
    etiso_1 = mu_list->at(0)->getEtIsoRatio();

    m_h_pt_all.at(FLAVOR_EM)->Fill(pt_0, weight);
    m_h_pt_all.at(FLAVOR_EM)->Fill(pt_1, weight);
    m_h_pt_0.at(  FLAVOR_EM)->Fill(pt_0, weight);
    m_h_pt_1.at(  FLAVOR_EM)->Fill(pt_1, weight);

    m_h_ptiso_all.at(FLAVOR_EM)->Fill(ptiso_0, weight);
    m_h_ptiso_all.at(FLAVOR_EM)->Fill(ptiso_1, weight);
    m_h_ptiso_0.at(  FLAVOR_EM)->Fill(ptiso_0, weight);
    m_h_ptiso_1.at(  FLAVOR_EM)->Fill(ptiso_1, weight);

    m_h_etiso_all.at(FLAVOR_EM)->Fill(etiso_0, weight);
    m_h_etiso_all.at(FLAVOR_EM)->Fill(etiso_1, weight);
    m_h_etiso_0.at(  FLAVOR_EM)->Fill(etiso_0, weight);
    m_h_etiso_1.at(  FLAVOR_EM)->Fill(etiso_1, weight);
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

  m_h_pt_all.at(FLAVOR_NONE)->Fill(pt_0, weight);
  m_h_pt_all.at(FLAVOR_NONE)->Fill(pt_1, weight);
  m_h_pt_0.at(  FLAVOR_NONE)->Fill(pt_0, weight);
  m_h_pt_1.at(  FLAVOR_NONE)->Fill(pt_1, weight);

  m_h_ptiso_all.at(FLAVOR_NONE)->Fill(ptiso_0, weight);
  m_h_ptiso_all.at(FLAVOR_NONE)->Fill(ptiso_1, weight);
  m_h_ptiso_0.at(  FLAVOR_NONE)->Fill(ptiso_0, weight);
  m_h_ptiso_1.at(  FLAVOR_NONE)->Fill(ptiso_1, weight);

  m_h_etiso_all.at(FLAVOR_NONE)->Fill(etiso_0, weight);
  m_h_etiso_all.at(FLAVOR_NONE)->Fill(etiso_1, weight);
  m_h_etiso_0.at(  FLAVOR_NONE)->Fill(etiso_0, weight);
  m_h_etiso_1.at(  FLAVOR_NONE)->Fill(etiso_1, weight);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::LeptonKinematicsHists::write(TDirectory* d)
{
  d->cd();

  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // write pt histograms
    m_h_pt_all.at(fc_it)->Write();
    m_h_pt_0.at(  fc_it)->Write();
    m_h_pt_1.at(  fc_it)->Write();

    // write ptiso histograms
    m_h_ptiso_all.at(fc_it)->Write();
    m_h_ptiso_0.at(  fc_it)->Write();
    m_h_ptiso_1.at(  fc_it)->Write();

    // write etiso histograms
    m_h_etiso_all.at(fc_it)->Write();
    m_h_etiso_0.at(  fc_it)->Write();
    m_h_etiso_1.at(  fc_it)->Write();
  }
}

// =============================================================================
PennSusyFrame::JetKinematicsHists::JetKinematicsHists(std::string name_tag)
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

  if (fc == FLAVOR_NONE) {
    return;
  }

  size_t num_jet = jet_list->size();

  float pt_0 = ( num_jet > 0 ? jet_list->at(0)->getPt()/1.e3 : 0.);
  float pt_1 = ( num_jet > 1 ? jet_list->at(1)->getPt()/1.e3 : 0.);

  m_h_num_jet.at(fc)->Fill(num_jet, weight);
  m_h_pt_all.at(fc )->Fill(pt_0, weight);
  m_h_pt_all.at(fc )->Fill(pt_1, weight);
  m_h_pt_0.at(fc   )->Fill(pt_0, weight);
  m_h_pt_1.at(fc   )->Fill(pt_1, weight);

  m_h_num_jet.at(FLAVOR_NONE)->Fill(num_jet, weight);
  m_h_pt_all.at(FLAVOR_NONE )->Fill(pt_0, weight);
  m_h_pt_all.at(FLAVOR_NONE )->Fill(pt_1, weight);
  m_h_pt_0.at(FLAVOR_NONE   )->Fill(pt_0, weight);
  m_h_pt_1.at(FLAVOR_NONE   )->Fill(pt_1, weight);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::JetKinematicsHists::write(TDirectory* d)
{
  d->cd();

  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize pt histograms
    m_h_num_jet.at(fc_it)->Write();
    m_h_pt_all.at( fc_it)->Write();
    m_h_pt_0.at(   fc_it)->Write();
    m_h_pt_1.at(   fc_it)->Write();
  }
}

// =============================================================================
PennSusyFrame::MetHists::MetHists(std::string name_tag)
{
  const int   met_et_bins = 50;
  const float met_et_min  = 0.;
  const float met_et_max  = 500.;

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
  }
}

// -----------------------------------------------------------------------------
PennSusyFrame::MetHists::~MetHists()
{}

// -----------------------------------------------------------------------------
void PennSusyFrame::MetHists::Fill( const PennSusyFrame::Event& event
                                  , const PennSusyFrame::EventLevelQuantities&
                                  , const std::vector<PennSusyFrame::Electron*>*
                                  , const std::vector<PennSusyFrame::Muon*>*
                                  , const std::vector<PennSusyFrame::Jet*>*
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

  m_h_met_et.at( fc)->Fill(met_et , weight);
  m_h_met_rel.at(fc)->Fill(met_rel, weight);

  m_h_met_et.at( FLAVOR_NONE)->Fill(met_et , weight);
  m_h_met_rel.at(FLAVOR_NONE)->Fill(met_rel, weight);
}

// -----------------------------------------------------------------------------
void PennSusyFrame::MetHists::write(TDirectory* d)
{
  d->cd();

  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize pt histograms
    m_h_met_et.at( fc_it)->Write();
    m_h_met_rel.at(fc_it)->Write();
  }

}
