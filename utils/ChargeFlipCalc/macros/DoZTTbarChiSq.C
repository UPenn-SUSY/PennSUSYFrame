{
// @file DrawZandTMapsAndCompare.C 
//    @brief A script to draw the truth-based flip rate maps and compare 
//    @author Brokk Toggerson - brokk.koen.toggerson@cern.ch 
//    @author University of California, Irvine 
//    @date First Written: 13 September 2011
//    @date Last Modified: 13 September 2011
//


  gStyle->SetPaintTextFormat("5.4f");

  gStyle->SetOptStat(0);

  //  TH1::AddDirectory(kFALSE); 
  
  TFile* fZ = new TFile("./Zee_MC_map.root"); 
  TFile* fT = new TFile("./ttbar_map.root"); 

  fZ->cd(); 

  TH2F* hZ = (TH2F*) fZ->Get("h_flipped"); 
  TH2F* hT = (TH2F*) fT->Get("h_flipped"); 

  cout<<endl;
  cout<<"Global chi2: "<<endl;
  cout<<"\t"; 
  hZ->Chi2Test(hT, "WWP"); 
  cout<<endl;

  TH1D* pZ = 0x0; 
  TH1D* pT = 0x0; 

  cout<<""<<endl;
  cout<<""<<endl;

  //Do chi2 test for each eta bin:
for(int y=1; y <= hZ->GetYaxis()->GetNbins(); y++){
    cout<<"For "<< hZ->GetYaxis()->GetBinLowEdge(y) <<" < |eta| < "<< hZ->GetYaxis()->GetBinLowEdge(y+1) <<" : "<<endl;
    cout<<"\t ";
    pZ = hZ->ProjectionX("pZ", y, y);
    pT = hT->ProjectionX("pT", y, y);
    pZ->Chi2Test(pT, "WWP"); 
  }//End chi2 test for each eta bin

  int NpTBins = 4; 
  double pTBins[NpTBins+1];
  pTBins[0] = 0.;
  pTBins[1] = 10.; 
  pTBins[2] = 60.; 
  pTBins[3] = 80.;
  pTBins[4] = 100.;
   
  int NetaBins = 5;
  double etaBins[NetaBins+1];
  etaBins[0] = 0.;
  etaBins[1] = 0.4; 
  etaBins[2] = 1.37; 
  etaBins[3] = 1.52;
  etaBins[4] = 2.3;
  etaBins[5] = 2.5; 
    
  TH2F drawhZ("ZeeNp map", 
	      "ZeeNp map", 
	      NpTBins, pTBins,
	      NetaBins, etaBins); 
  drawhZ.GetYaxis()->SetTitle("|#eta|"); 
  drawhZ.GetXaxis()->SetTitle("p_{T} [GeV]");  

  TH2F drawhT("ttbar map", 
	      "ttbar map", 
	      NpTBins, pTBins,
	      NetaBins, etaBins); 
  drawhT.GetYaxis()->SetTitle("|#eta|"); 
  drawhT.GetXaxis()->SetTitle("p_{T} [GeV]");  

  string xlabels[] = { "0 - 20", 
		       "10 - 60", 
		       "60 - 80", 
		       "80+" }

  string ylabels[] = { "0 - 0.4", 
		       "0.4 - 1.37", 
		       "1.37 - 1.52", 
		       "1.52 - 2.3", 
		       "2.3 - 2.5" };
  
  for(int x=1; x <= hZ->GetXaxis()->GetNbins(); x++){//Loop through x
    
    for(int y=1; y <= hZ->GetYaxis()->GetNbins(); y++){//Loop through y

      drawhZ.Fill( xlabels[x-1].c_str(), 
		   ylabels[y-1].c_str(), 
		   hZ->GetBinContent(x, y) ); 
      drawhZ.SetBinError(x, y, hZ->GetBinError(x,y) ); 

      drawhT.Fill( xlabels[x-1].c_str(), 
		   ylabels[y-1].c_str(),
		   hT->GetBinContent(x, y) ); 
      drawhT.SetBinError(x, y, hT->GetBinError(x,y) ); 
		   

    }//End y loop
  }//End x loop
 
  drawhT.GetYaxis()->SetTitleOffset(1.6); 
  drawhZ.GetYaxis()->SetTitleOffset(1.6); 
 
  drawhT.GetZaxis()->SetRangeUser(0., 0.09); 
  drawhZ.GetZaxis()->SetRangeUser(0., 0.09); 
 
  drawhT.GetXaxis()->SetRange(2, -1); 
  drawhZ.GetXaxis()->SetRange(2, -1); 

  drawhT.SetMarkerSize(1.8); 
  drawhZ.SetMarkerSize(1.8); 

  TCanvas* cT = new TCanvas("cT","cT",800,600); 
  drawhT.Draw("coletext"); 
  //myText(0.159, 0.954, 1, "t#bar{t} MC"); 

  TCanvas* cZ = new TCanvas("cZ","cZ",800,600); 
  drawhZ.Draw("coletext"); 
  //myText(0.159, 0.954, 1, "Z#rightarrowee + NpX MC");   

}
