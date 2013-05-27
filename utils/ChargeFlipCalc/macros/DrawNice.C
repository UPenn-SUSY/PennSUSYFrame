{

/** @file DrawMapNice.C 
    @brief This is a simple script that will draw the map in a way that 
    looks nice
    @author Brokk Toggerson - brokk.koen.toggerson@cern.ch 
    @author University of California, Irvine 
    @date First Written: 12 October 2012
    @date Last Modified: 12 October 2012
*/

  #include <string>

  /** Get rid of stupid stats box */
  gStyle->SetOptStat(0);

  /** A good number of decimals */
  gStyle->SetPaintTextFormat("5.4f");

  /** The name of the file containing the map*/
  //TFile* fin = new TFile("./ZAlpgenMap.root"); 
  //  TFile* fin = new TFile("../mc_out.root"); 

  TFile* fin = new TFile("./ZAlpgenMapFull2012_d0sig3.root"); 

  /** The name of the histogram in the file */
  string histname = "h_flipped"; 
  //string histname = "h_truth_rate";
  
  /** Goes at the top of the plot */
  string label = "#epsilon (|#eta|^{Z#rightarrow ee data}, p_{T}^{Z#rightarrow ee MC truth})";
  //  string label = "#epsilon (|#eta|^{Z#rightarrow ee MC truth}, p_{T}^{Z#rightarrow ee MC truth})";
  //string label = "#epsilon (|#eta|^{TTbar MC truth}, p_{T}^{TTbar MC truth})";

  //-------------------------------------------------------------------------//
  //                      SHOULD NOT HAVE TO CHANGE BELOW HERE               //
  //                           UNLESS MAP BINNING CHANGES                    //
  //-------------------------------------------------------------------------//

  TH2D* hRaw = fin->Get( histname.c_str() ); 
  
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
    
  string xlabels[] = { "0 - 20", 
		       "10 - 60", 
		       "60 - 80", 
		       "80+" }

  string ylabels[] = { "0 - 0.4", 
		       "0.4 - 1.37", 
		       "1.37 - 1.52", 
		       "1.52 - 2.3", 
		       "2.3 - 2.5" };

  TH2F hDraw("nice map", 
	     "nice map", 
	     NpTBins, pTBins,
	     NetaBins, etaBins); 
  hDraw.GetYaxis()->SetTitle("|#eta|"); 
  hDraw.GetXaxis()->SetTitle("p_{T} [GeV]");  

  for(int x=1; x <= hRaw->GetXaxis()->GetNbins(); x++){//Loop through x
    
    for(int y=1; y <= hRaw->GetYaxis()->GetNbins(); y++){//Loop through y

      hDraw.Fill( xlabels[x-1].c_str(), 
		   ylabels[y-1].c_str(), 
		   hRaw->GetBinContent(x, y) ); 
      hDraw.SetBinError(x, y, hRaw->GetBinError(x,y) ); 
   
    }//End y loop
  }//End x loop

  hDraw.GetYaxis()->SetTitleOffset(1.6); 
  hDraw.GetZaxis()->SetRangeUser(0., 0.09); 
  hDraw.GetXaxis()->SetRange(2, -1); 
  hDraw.SetMarkerSize(1.8); 

  TCanvas* cNiceMap = new TCanvas("cNiceMap","cNiceMap",0.,0.,800,600);
  cNiceMap->SetTopMargin(0.072);
  cNiceMap->ToggleEventStatus();
  hDraw.Draw("coletext");
  TLatex l; 
  l.SetNDC();
  l.SetTextColor(1);
  l.DrawLatex(0.159, 0.945, label.c_str());

}
