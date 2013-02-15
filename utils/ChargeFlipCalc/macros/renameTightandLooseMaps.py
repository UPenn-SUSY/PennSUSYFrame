from ROOT import *

file1 = TFile("/exports/project/data_d07_3/ehines/SusyFrame/Susy/plot_dev/charge_flip/macros/SherpaMap.root")

file2 = TFile("/exports/project/data_d07_3/ehines/SusyFrame/Susy/plot_dev/charge_flip/chargeFlip2012ExLoose.root")

hist1 = file1.Get("h_flipped")
hist2 = file2.Get("h_flipped")

hist1.SetName("datalikelihoodEtaTruthPt")
hist1.SetTitle("datalikelihoodEtaTruthPt")
hist1.GetXaxis().SetTitle("p_{T} [GeV]")
hist1.GetYaxis().SetTitle("#eta")
   
hist2.SetName("datalikelihoodEtaTruthPt_Exloose")
hist2.SetTitle("datalikelihoodEtaTruthPt_Exloose")
hist2.GetXaxis().SetTitle("p_{T} [GeV]")
hist2.GetYaxis().SetTitle("#eta")


outfile = TFile("out_out.root","recreate")
hist1.Write()
hist2.Write()
outfile.Close()

   
