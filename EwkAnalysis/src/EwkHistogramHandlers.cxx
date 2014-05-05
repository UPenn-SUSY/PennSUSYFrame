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
void PennSusyFrame::EwkHists::write(TDirectory* d)
{
  d->cd();

  for (unsigned int fc_it = 0; fc_it != FLAVOR_N; ++fc_it) 
    {

      m_h_jet_sum_pt.at(fc_it)->Write();
    }
  

}
