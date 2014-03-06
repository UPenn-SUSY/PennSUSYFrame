from ROOT import *

file1 = TFile("./ZAlpgenMapFull2012_d0sig5.root")
file2 = TFile("./ZAlpgenMapFull2012_d0sig3.root")


hist1 = file1.Get("h_flipped")
hist2 = file2.Get("h_flipped")

hist1.SetName("datalikelihoodEtaTruthPt_d0sig5")
hist1.SetTitle("datalikelihoodEtaTruthPt_d0sig5")
hist1.GetXaxis().SetTitle("p_{T} [GeV]")
hist1.GetYaxis().SetTitle("#eta")
   
hist2.SetName("datalikelihoodEtaTruthPt_d0sig3")
hist2.SetTitle("datalikelihoodEtaTruthPt_d0sig3")
hist2.GetXaxis().SetTitle("p_{T} [GeV]")
hist2.GetYaxis().SetTitle("#eta")

outfile = TFile("out_out.root","recreate")
hist1.Write()
hist2.Write()
outfile.Close()

   
