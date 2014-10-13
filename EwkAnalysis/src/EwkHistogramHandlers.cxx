#include "EwkAnalysis/include/EwkHistogramHandlers.h"
#include "PennSusyFrameCore/include/PennSusyFrameEnums.h"
#include "PennSusyFrameCore/include/ObjectDefs.h"
#include "PennSusyFrameCore/include/Calculators.h"

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

  const int bdt_bins = 100;
  const float bdt_min = -1;
  const float bdt_max = 1;

  static const int   dphi_bins = 32;
  static const float dphi_min = 0.;
  static const float dphi_max = 3.2;


  static const int ratio_bins = 200;
  static const float ratio_min = 0;
  static const float ratio_max = 10;

//  const int   mbl_bins = 50;
//  const float mbl_min  = 0.;
//  const float mbl_max  = 500.;
//

   
  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    // initialize pt histograms

    m_h_jet_sum_pt.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
					  + "__jet_sum_pt"
					  + "__"
					  + name_tag 
					  ).c_str()
					, ( "#Sigma p_{T} - "
					    + FLAVOR_CHANNEL_STRINGS[fc_it]
					    + " ; #Sigma p_{T} [GeV] ; Entries"
					    ).c_str()
					, pt_bins, pt_min, pt_max
					)
			      );

    m_h_bdt_score.push_back( new TH1F( ( FLAVOR_CHANNEL_STRINGS[fc_it]
                                         + "__bdt_score"
                                         + "__"
                                         + name_tag
                                         ).c_str()
                                       , ( "BDT Score "
                                           + FLAVOR_CHANNEL_STRINGS[fc_it]
                                           + " ; BDT Score ; Entries"
                                           ).c_str()
                                       , bdt_bins, bdt_min, bdt_max
                                       )
                             );


    m_h_mtr1.push_back( new TH1F( (FLAVOR_CHANNEL_STRINGS[fc_it]
                                         + "__mtr1"
                                         + "__"
                                         + name_tag
                                         ).c_str()
                                       , ( "MTr 1 "
                                           + FLAVOR_CHANNEL_STRINGS[fc_it]
                                           + " ; MTr 1 ; Entries"
                                           ).c_str()
				  , pt_bins, pt_min, pt_max
				  )
			);

    m_h_mtr2.push_back( new TH1F( (FLAVOR_CHANNEL_STRINGS[fc_it]
                                         + "__mtr2"
                                         + "__"
                                         + name_tag
                                         ).c_str()
                                       , ( "MTr 2 "
                                           + FLAVOR_CHANNEL_STRINGS[fc_it]
                                           + " ; MTr 2 ; Entries"
                                           ).c_str()
				  , pt_bins, pt_min, pt_max
				  )
			);

    m_h_ratio_met_jet.push_back(new TH1F( (FLAVOR_CHANNEL_STRINGS[fc_it]
                                         + "__ratio_met_jet" 
                                         + "__"
                                         + name_tag
                                         ).c_str()
                                       , ( "MET/PT Jet"
                                           + FLAVOR_CHANNEL_STRINGS[fc_it]
                                           + " ; MET/PT Jet ; Entries"
                                           ).c_str()
				  , ratio_bins, ratio_min, ratio_max
				  )
				);

    m_h_ratio_lep_jet.push_back(new TH1F( (FLAVOR_CHANNEL_STRINGS[fc_it]
                                         + "__ratio_lep_jet"
                                         + "__"
                                         + name_tag
                                         ).c_str()
                                       , ( "Ratio Pt Lep/ Pt Jet "
                                           + FLAVOR_CHANNEL_STRINGS[fc_it]
                                           + " ; Pt Lep/ Pt Jet ; Entries"
                                           ).c_str()
				  , ratio_bins, ratio_min, ratio_max
				  )
				);

    m_h_dphi_met_jet.push_back(new TH1F( (FLAVOR_CHANNEL_STRINGS[fc_it]
                                         + "__dphi_met_jet"
                                         + "__"
                                         + name_tag
                                         ).c_str()
                                       , ( "dphi met jet "
                                           + FLAVOR_CHANNEL_STRINGS[fc_it]
                                           + " ; dphi met jet ; Entries"
                                           ).c_str()
					 , dphi_bins, dphi_min, dphi_max
					 )
			       );

    
  }

}

// -----------------------------------------------------------------------------
PennSusyFrame::EwkHists::~EwkHists()
{}



// -----------------------------------------------------------------------------
void PennSusyFrame::EwkHists::FillSpecial( const PennSusyFrame::Event& event
					   , const std::vector<PennSusyFrame::Jet*>* jet_list
					   , float weight
					   )
{

  FLAVOR_CHANNEL fc = event.getFlavorChannel();

  if (fc == FLAVOR_NONE || fc == FLAVOR_ERROR_1) return;

  //Fill sum pt histogram

  //make a tlorentz vector of the jet system

  TLorentzVector jet_sum;

  jet_sum.SetPxPyPzE(0,0,0,0);

  unsigned int jet_size = jet_list->size();

  for (unsigned int jet = 0; jet != jet_size; ++jet)
    {
      const TLorentzVector *tmp_jet = jet_list->at(jet)->getTlv();

      jet_sum = jet_sum + (*tmp_jet);

      //  std::cout<<"Running pt is: "<< jet_sum.Pt()<<std::endl;

    }
  
  for (int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    if (fc_it == FLAVOR_ERROR_1) continue;
    if (fc_it != FLAVOR_NONE && fc_it != fc) continue;

    m_h_jet_sum_pt.at(fc_it)->Fill(jet_sum.Pt()/1000., weight);

  }
}
// -----------------------------------------------------------------------------
void PennSusyFrame::EwkHists::FillIsr(const PennSusyFrame::Event& event
                                         , const PennSusyFrame::EventLevelQuantities& event_level_quantities
                                         , const std::vector<PennSusyFrame::Electron*>* electrons
                                         , const std::vector<PennSusyFrame::Muon*>* muons
                                         , const std::vector<PennSusyFrame::Jet*>* jets
                                         , const PennSusyFrame::Met& met
                                         , float weight
				      )
{
  
  FLAVOR_CHANNEL fc = event.getFlavorChannel();
  
  if (fc == FLAVOR_NONE || fc == FLAVOR_ERROR_1) return;

  if (jets->size() == 0) return;

  float  ratio_met_pt_jet = met.getMetEt()/(jets->at(0)->getPt());
  float  ratio_lep_jet = PennSusyFrame::getPtRatioLepJet(fc
							 , electrons
							 , muons
							 , jets
							 );
  float dphi_met_jet = met.getDPhi(jets->at(0));
 

  
  for (int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    if (fc_it == FLAVOR_ERROR_1) continue;
    if (fc_it != FLAVOR_NONE && fc_it != fc) continue;
    
    m_h_ratio_met_jet.at(fc_it)->Fill(ratio_met_pt_jet, weight);
    m_h_ratio_lep_jet.at(fc_it)->Fill(ratio_lep_jet, weight);
    m_h_dphi_met_jet.at(fc_it)->Fill(dphi_met_jet);

  } 

}
// -----------------------------------------------------------------------------
void PennSusyFrame::EwkHists::FillBDT( const PennSusyFrame::Event& event
                                       , float bdt_score
                                       , float weight
                                       )
{
  FLAVOR_CHANNEL fc = event.getFlavorChannel(); 
  for (int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) {
    if (fc_it == FLAVOR_ERROR_1) continue;
    if (fc_it != FLAVOR_NONE && fc_it != fc) continue;
    
    m_h_bdt_score.at(fc_it)->Fill(bdt_score, weight);

  }
}

// -----------------------------------------------------------------------------
void PennSusyFrame::EwkHists::write(TDirectory* d)
{
  d->cd();

  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) 
    {

      m_h_jet_sum_pt.at(fc_it)->Write();
      m_h_bdt_score.at(fc_it)->Write();

      m_h_ratio_met_jet.at(fc_it)->Write();
      m_h_ratio_lep_jet.at(fc_it)->Write();
      m_h_dphi_met_jet.at(fc_it)->Write();
      
    }
  

}
