{
  TFile *fileMC = new TFile("/exports/project/data_d07_3/ehines/SusyFrame/Susy/SusyDiLeptonChargeFlipCycle.MC.egamma.2012_10_11.1.SherpaZee.root");
  
  //TFile *fileMC = new TFile("/exports/project/data_d07_3/ehines/SusyFrame/Susy/Zee21Sep.total.root");
 

  gROOT->Macro("$ROOTSYS/tutorials/fit/langaus.C+");
  
  //Get the shift plot
  TH1F *hist_pt_loss=fileMC->Get("ChargeFlipEst/h_pt_shift");
  
  //  hist_pt_loss->Draw();
  
  Double_t fit_range[2];
  Double_t start_values[4], para_lim_low[4],para_lim_high[4], fit_para[4], fit_para_errors[4];
  
  Int_t ndf;
  Double_t chisqr;
  
  fit_range[0] = -0.06;
  fit_range[1] = 0.3;
  
  start_values[0] = 0.02; start_values[1] = 0.01; start_values[2] = 50000; start_values[3] = 0.04;
  para_lim_low[0] = 0.0001; para_lim_low[1] = -0.2; para_lim_low[2] = 1; para_lim_low[3] = 0.01;
  para_lim_high[0] = 0.4; para_lim_high[1] = 0.2; para_lim_high[2] = 1e+06; para_lim_high[3] = 0.8;
  
  
  TCanvas* c2 = new TCanvas("c2","c2",800,600); 
  c2->cd();
  hist_pt_loss->Draw(); 
  TF1 *fitpT = langaufit(hist_pt_loss,fit_range,start_values,para_lim_low,para_lim_high,fit_para,fit_para_errors,&chisqr, &ndf); 
  fitpT->Draw("lsame");
  
  
  //fitpT = langaufit(hist_pt_loss,

}
