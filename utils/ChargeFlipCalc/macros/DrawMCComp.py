from ROOT import *

##fileData = TFile("out_data.root")
fileMC  = TFile("../zjets1.root")

#HistData = fileData.Get("h_charge_flip")
HistMC = fileMC.Get("h_lklh_rate")
HistMCTruth = fileMC.Get("h_truth_rate_eta_only")


HistMC.SetMarkerStyle(22)
HistMC.SetMarkerColor(kBlue)

HistData.SetMarkerStyle(20)

HistMCTruth.SetMarkerStyle(23)
HistMCTruth.SetMarkerColor(kRed)

c1=TCanvas("c1","c1",800,600)
c1.cd()
c1.SetLogy()
HistData.GetYaxis().SetRangeUser(0.000001,0.055)
#HistData.Draw()
HistMC.Draw("same")
HistMCTruth.Draw("E")

l1 = TLegend(0.225,0.415,0.425,0.55)
l1.SetBorderSize(0)
l1.SetFillColor(0)
l1.SetTextSize(0.038)
l1.AddEntry(HistMC,"MC, likelihood","P")
l1.AddEntry(HistMCTruth, "MC, truth", "P")
#l1.AddEntry(HistData,"Data","P")
l1.Draw("same")

##Hist_ratio = HistData.Clone()
##
##for i in range(1,HistData.GetNbinsX()+1):
##    bin_ratio = HistData.GetBinContent(i)/HistMC.GetBinContent(i)
##    Hist_ratio.SetBinContent(i,bin_ratio)
##    error = bin_ratio*sqrt((HistData.GetBinError(i)/HistData.GetBinContent(i))*(HistData.GetBinError(i)/HistData.GetBinContent(i)) + (HistMC.GetBinError(i)/HistMC.GetBinContent(i))*(HistMC.GetBinError(i)/HistMC.GetBinContent(i)))
##    Hist_ratio.SetBinError(i,error)
##
##
##Hist_ratio.SetMarkerStyle(20)
##Hist_ratio.GetYaxis().SetRangeUser(0.6,1.4)
##c2=TCanvas("c2","c2",800,600)
##c2.cd()
##Hist_ratio.Draw()
