from ROOT import *

fileData = TFile("../egammaE.root")

fileMC = TFile("../zjets1.root")

likelihoodHist = fileMC.Get("h_lklh_rate")
dataHist = fileData.Get("h_lklh_rate")

likelihoodHist.SetMarkerStyle(22)
likelihoodHist.SetMarkerColor(kBlue)

dataHist.SetMarkerStyle(23)
dataHist.SetMarkerColor(kRed)



likelihoodHist.GetYaxis().SetRangeUser(0,0.055)
c1=TCanvas("c1","c1",800,600)
c1.cd()
#c1.SetLogy()
#HistRatio.Draw()
likelihoodHist.Draw()
dataHist.Draw("same")

l1 = TLegend(0.225,0.7,0.425,0.84)
l1.SetBorderSize(0)
l1.SetFillColor(0)
l1.SetTextSize(0.038)
#l1.AddEntry(HistRatio,"MC from Truth","P")
l1.AddEntry(likelihoodHist, "MC from Likelihood", "P")
l1.AddEntry(dataHist, "Data", "P")
l1.Draw("same")
