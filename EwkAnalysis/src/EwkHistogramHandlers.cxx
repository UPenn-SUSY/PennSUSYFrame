#include "EwkAnalysis/include/EwkHistogramHandlers.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"

#include "TFile.h"
#include "TDirectory.h"
#include "TH1.h"

// =============================================================================
PennSusyFrame::EwkHists::EwkHists(std::string name_tag)
{

  TH1::SetDefaultSumw2(true);

  const int   num_jet_bins = 4;
  const float num_jet_min  = -0.5;
  const float num_jet_max  = num_jet_bins - num_jet_min;

  const int   pt_bins = 50;
  const float pt_min  = 0.;
  const float pt_max  = 500.;

  const int   mbl_bins = 50;
  const float mbl_min  = 0.;
  const float mbl_max  = 500.;

  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize pt histograms
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
    
  }
}

// -----------------------------------------------------------------------------
PennSusyFrame::EwkHists::~EwkHists()
{}


// -----------------------------------------------------------------------------
void PennSusyFrame::EwkHists::write(TDirectory* d)
{
  d->cd();

  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize pt histograms
    m_h_num_b_jet.at(   fc_it)->Write();

    m_h_b_jet_pt_all.at(fc_it)->Write();
    m_h_b_jet_pt_0.at(  fc_it)->Write();
    m_h_b_jet_pt_1.at(  fc_it)->Write();

    m_h_mbl_all.at(fc_it)->Write();
    m_h_mbl_0.at(fc_it)->Write();
    m_h_mbl_1.at(fc_it)->Write();
  }
}
