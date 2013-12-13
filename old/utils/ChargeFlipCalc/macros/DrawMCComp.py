from ROOT import *

##fileData = TFile("out_data.root")
fileMC  = TFile("../mc_out.root")

#HistData = fileData.Get("h_charge_flip")
HistLikelihood = fileMC.Get("h_lklh_rate")
HistMCTruth = fileMC.Get("h_truth_rate_eta_only")


HistLikelihood.SetMarkerStyle(22)
HistLikelihood.SetMarkerColor(kBlue)
HistLikelihood.SetLineColor(kBlue)

HistMCTruth.SetMarkerStyle(23)
HistMCTruth.SetMarkerColor(kRed)
HistMCTruth.SetLineColor(kRed)

HistLikelihood.GetYaxis().SetTitle("Charge mis-id rate")
HistLikelihood.GetYaxis().SetTitleOffset(1.4)

c1=TCanvas("c1","c1",800,600)
c1.cd()
#c1.SetLogy()
HistLikelihood.GetYaxis().SetRangeUser(0.000001,0.055)
HistLikelihood.Draw()
HistMCTruth.Draw("same")

l1 = TLegend(0.225,0.415,0.425,0.55)
l1.SetBorderSize(0)
l1.SetFillColor(0)
l1.SetTextSize(0.038)
l1.AddEntry(HistLikelihood,"MC, likelihood","P")
l1.AddEntry(HistMCTruth, "MC, truth", "P")
#l1.AddEntry(HistData,"Data","P")
l1.Draw("same")

