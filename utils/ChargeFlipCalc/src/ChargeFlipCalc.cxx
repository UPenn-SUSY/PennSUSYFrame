#include <iostream>
#include <iomanip>
#include "include/ChargeFlipCalc.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <math.h>


double ChargeFlipCalc::lkh_events[5][5] = {{0., 0., 0., 0., 0.}, 
				       {0., 0., 0., 0., 0.}, 
				       {0., 0., 0., 0., 0.}, 
				       {0., 0., 0., 0., 0.}, 
				       {0., 0., 0., 0., 0.} };

double ChargeFlipCalc::lkh_ss[5][5] = {{0., 0., 0., 0., 0.}, 
				   {0., 0., 0., 0., 0.}, 
				   {0., 0., 0., 0., 0.}, 
				   {0., 0., 0., 0., 0.}, 
				   {0., 0., 0., 0., 0.} };

// -----------------------------------------------------------------------------
ChargeFlipCalc::ChargeFlipCalc(TTree *tree) : NtupleLooper(tree)
{

  initChargeFlipHists();

}

// -----------------------------------------------------------------------------
ChargeFlipCalc::~ChargeFlipCalc()
{
  // do nothing
}

// -----------------------------------------------------------------------------
void ChargeFlipCalc::processEvent()
{

  if (passLikelihoodSelection()) fillLikelihoodHists();
  if (passTruthSelection())      fillTruthHists();

    
}

// -----------------------------------------------------------------------------
void ChargeFlipCalc::printToFile(std::string out_file_name)
{
   std::cout << "Writing cut flow histograms to file: "
             << out_file_name << "\n";

   TFile* f = new TFile(out_file_name.c_str(), "RECREATE");

   //m_cutflow.at(WEIGHT_NONE).at(PHASE_NONE)->Write();

   m_h_flipped->Write();
   m_h_unflipped->Write();

   m_h_flipped_pt_only->Write();
   m_h_unflipped_pt_only->Write();

   m_h_flipped_eta_only->Write();
   m_h_unflipped_eta_only->Write();

   m_h_mll->Write();

   m_h_n_events->Write();
   m_h_n_ss->Write();

   f->Write();
   f->Close();
   delete f;
}
// -----------------------------------------------------------------------------
void ChargeFlipCalc::initChargeFlipHists()
{
  
  const int num_eta_bins = 5;
  float eta_bins[num_eta_bins+1] = {0,0.4,1.37,1.52,2.3,2.5};
  
  const int num_pt_bins = 4;
  float pt_bins[num_pt_bins+1] = {0.,10.,60.,80.,4000.};
  
  
  m_h_flipped = new TH2F("h_flipped","h_flipped",num_pt_bins,pt_bins,num_eta_bins,eta_bins);
  m_h_unflipped = new TH2F("h_unflipped","h_unflipped",num_pt_bins,pt_bins,num_eta_bins,eta_bins);
   
  m_h_flipped_pt_only = new TH1F("h_flipped_pt_only", "h_flipped_pt_only", num_pt_bins, pt_bins);
  m_h_unflipped_pt_only = new TH1F("h_unflipped_pt_only", "h_unflipped_pt_only", num_pt_bins, pt_bins);
  
  m_h_flipped_eta_only = new TH1F("h_flipped_eta_only", "h_flipped_eta_only", num_eta_bins, eta_bins);
  m_h_unflipped_eta_only = new TH1F("h_unflipped_eta_only", "h_unflipped_eta_only", num_eta_bins, eta_bins);
  
  //m_true_ss = new TH2F("h_true_ss","h_true_ss",num_eta_bins,eta_bins,num_eta_bins,eta_bins); //plot eta of two electorns
  
  m_h_mll = new TH1F("h_mll","h_mll:m_ll [GeV]",150,0,150);
  m_h_mll_ss = new TH1F("h_mll_ss","h_mll_ss:m_ll [GeV]",150,0,150);

  m_h_n_events = new TH2F("h_n_events","h_n_events", num_eta_bins, eta_bins, num_eta_bins, eta_bins);
  m_h_n_ss = new TH2F("h_n_ss","h_n_ss", num_eta_bins, eta_bins, num_eta_bins, eta_bins);
  
  //  m_pt_shift = Book("h_pt_shift","h_pt_shift", 600, -1., 1.);

}
// -----------------------------------------------------------------------------

void ChargeFlipCalc::fillTruthHists()
{

  
  

  std::vector<float>*  el_eta = m_el_eta;
  std::vector<float>*  el_pt  = m_el_pt;
  std::vector<short>*  el_charge = m_el_charge;
  std::vector<float>*  el_truth_charge = m_el_truth_charge;
  
  

  size_t num_el = el_eta->size();
    
  for (size_t el_it=0; el_it<num_el; el_it++)
    {

      SusyAnalysisTools::ElectronDescription el_desc = m_el_desc->at(el_it);

      bool pass = true;
      //      pass = pass && el_desc.getPassSignal();

      if (pass)
	{
	  float eta = fabs(el_eta->at(el_it));
	  float pt = el_pt->at(el_it)/1000.;
	  
	  m_h_unflipped_eta_only->Fill(eta);
	  m_h_unflipped_pt_only->Fill(pt);
	  m_h_unflipped->Fill(pt,eta);
	  
	  if (el_truth_charge->at(el_it)*el_charge->at(el_it) < 0)
	    {
	      
	      //std::cout<<"flipped"<<std::endl;
	      m_h_flipped_eta_only->Fill(eta);
	      m_h_flipped_pt_only->Fill(pt);
	      m_h_flipped->Fill(pt,eta);	  
	    }
	}
    }
  
}
// -----------------------------------------------------------------------------

void ChargeFlipCalc::fillLikelihoodHists()
{

  SusyAnalysisTools::EventDescription evt_desc  = m_event_desc;
  std::vector<float>*  el_eta = m_el_eta;
  //std::vector<float>*  el_pt  = m_el_pt;



  float el_eta_lead = el_eta->at(0);
  float el_eta_sub_lead = el_eta->at(1);
  
  m_h_n_events->Fill(el_eta_lead, el_eta_sub_lead);
  if (evt_desc.getSignChannel()==SIGN_SS) m_h_n_ss->Fill(el_eta_lead, el_eta_sub_lead);
  
}
// -----------------------------------------------------------------------------

bool ChargeFlipCalc::passLikelihoodSelection()
{

  SusyAnalysisTools::EventDescription evt_desc  = m_event_desc;

  bool pass = true;
  
  if (evt_desc.getFlavorChannel() != FLAVOR_EE) return false;

  pass = pass && evt_desc.getPassGrl();
  pass = pass && evt_desc.getPassIncompleteEvent();
  pass = pass && evt_desc.getPassLarError();
  pass = pass && evt_desc.getPassTileError();
  pass = pass && evt_desc.getPassTileHotSpot();
  pass = pass && evt_desc.getPassBadJets();
  pass = pass && evt_desc.getPassPrimaryVertex();
  pass = pass && evt_desc.getPassBadMuons();
  pass = pass && evt_desc.getPassCosmicMuons();
  pass = pass && evt_desc.getPassHFOR();
  pass = pass && evt_desc.getPass2GoodLeptons();

  pass = pass && evt_desc.isEETrigger();
  pass = pass && evt_desc.getPassTriggerMatch();
  pass = pass && evt_desc.getTruthPrompt();
  pass = pass && evt_desc.getPass2SignalLeptons();
 

  return pass;

}
// -----------------------------------------------------------------------------

bool ChargeFlipCalc::passTruthSelection()
{

  SusyAnalysisTools::EventDescription evt_desc  = m_event_desc;

  if (evt_desc.getIsData()) return false;
  if (!(evt_desc.getFlavorChannel() == FLAVOR_EE 
	|| evt_desc.getFlavorChannel() ==FLAVOR_EM)) return false;
  
  bool pass = true;
  
  pass = pass && evt_desc.getPassGrl();
  pass = pass && evt_desc.getPassIncompleteEvent();
  pass = pass && evt_desc.getPassLarError();
  pass = pass && evt_desc.getPassTileError();
  pass = pass && evt_desc.getPassTileHotSpot();
  pass = pass && evt_desc.getPassBadJets();
  pass = pass && evt_desc.getPassPrimaryVertex();
  pass = pass && evt_desc.getPassBadMuons();
  pass = pass && evt_desc.getPassCosmicMuons();
  pass = pass && evt_desc.getPassHFOR();

  return pass;
}
// -----------------------------------------------------------------------------

void ChargeFlipCalc::flipLikelihood(Int_t &npar, 
				    Double_t *gin, 
				    Double_t &f, 
				    Double_t *par, 
				    Int_t iflag)
{
  
  f = 0; 
   
  Double_t loglkhsum = 0.;

  const int num_eta_bins = 5;
  
  for (int lead_eta_bin=0; lead_eta_bin<num_eta_bins; lead_eta_bin++) // loop over the table, max N of HT hits is N all hits
    {
      for(int sublead_eta_bin=0; sublead_eta_bin<num_eta_bins; sublead_eta_bin++)
        {
	  
	  int num_events = lkh_events[lead_eta_bin][sublead_eta_bin];
	  int num_ss = lkh_ss[lead_eta_bin][sublead_eta_bin];
	  
	  double loglkh = logLikelihood(par, num_events, num_ss, lead_eta_bin, sublead_eta_bin);
          
	  
          loglkhsum += loglkh;

        }
    }
  
  f = -2. * loglkhsum;
  
  return;
  
}

//*****************************************************************************************//
// likelihood function used by the fit
//*****************************************************************************************//

double ChargeFlipCalc::logLikelihood(double eff_array[], int num_total, int num_ss, int lead_eta_bin, int sublead_eta_bin) {
  //eff for charge flip in different eta bins,  N, h_N_ss is number in bin i,j for the 2 electrons
  
  double logfactor = 0.;
  
  logfactor = (log(num_total*(eff_array[lead_eta_bin]+eff_array[sublead_eta_bin]))*num_ss) - (num_total*(eff_array[lead_eta_bin]+eff_array[sublead_eta_bin]));
  
  return logfactor;

}
// -----------------------------------------------------------------------------

void ChargeFlipCalc::prepLikelihood()
{
  const int num_eta_bins = 5;
  
  for (int lead_eta_bin=0; lead_eta_bin<num_eta_bins; lead_eta_bin++) // loop over the table, max N of HT hits is N all hits
    {
      for(int sublead_eta_bin=0; sublead_eta_bin<num_eta_bins; sublead_eta_bin++)
	{
	  lkh_events[lead_eta_bin][sublead_eta_bin] = m_h_n_events->GetBinContent(lead_eta_bin+1, sublead_eta_bin+1);
	  lkh_ss[lead_eta_bin][sublead_eta_bin] = m_h_n_ss->GetBinContent(lead_eta_bin+1, sublead_eta_bin+1);
	}
    }
}
// -----------------------------------------------------------------------------
void ChargeFlipCalc::calcLikelihood()
{

  const int num_eta_bins = 5;

  TMinuit* gMinuit = new TMinuit(num_eta_bins);

  gMinuit->SetFCN(flipLikelihood);

  double start = 0.03;
  double step = 0.0001;
  
  gMinuit->DefineParameter(0, "eff_eta0", start, step , 0., 1.);
  gMinuit->DefineParameter(1, "eff_eta1", start, step , 0., 1.);
  gMinuit->DefineParameter(2, "eff_eta2", start, step , 0., 1.);
  gMinuit->DefineParameter(3, "eff_eta3", start, step , 0., 1.);
  gMinuit->DefineParameter(4, "eff_eta4", start, step , 0., 1.);

  gMinuit->Migrad();

}
