from ROOT import *

#gROOT.LoadMacro("~/root/AtlasStyle.C")
#SetAtlasStyle()

#fileNom = TFile("/exports/project/data_d07_3/ehines/SusyFrame/Susy/plot_dev/charge_flip/18OctData.root")

fileMCMap = TFile("/exports/project/data_d07_3/ehines/SusyFrame/Susy/plot_dev/charge_flip/AllMCMapWeightOut.root")

fileMixedMap = TFile("/exports/project/data_d07_3/ehines/SusyFrame/Susy/plot_dev/charge_flip/MixedMapWeightOut.root")


hist_SS_data = fileMCMap.Get("h_mll_ss")
hist_MCMap  = fileMCMap.Get("h_mll_os")
hist_MCMixedMap = fileMixedMap.Get("h_mll_os");


hist_SS_data.SetMarkerStyle(kFullCircle)
hist_SS_data.SetMarkerColor(kBlack)

hist_MCMap.SetMarkerStyle(kOpenCircle)
hist_MCMap.SetMarkerColor(kRed)

hist_MCMixedMap.SetMarkerStyle(kOpenDiamond)
hist_MCMixedMap.SetMarkerColor(kGreen)

hist_MCMap.GetYaxis().SetRangeUser(0,10000)
hist_MCMap.GetYaxis().SetTitle("events/ 2 GeV")
hist_MCMap.GetXaxis().SetRangeUser(80,102)
hist_MCMap.GetXaxis().SetTitle("m_{ll} [GeV]")

c1 = TCanvas ("c1","c1",800,600)
c1.cd()
hist_MCMap.Draw("P")
hist_SS_data.Draw("P same")
hist_MCMixedMap.Draw("P same")


l1 = TLegend(0.66,0.56,0.80,0.72)
l1.SetBorderSize(0)
l1.SetFillColor(0);
l1.SetTextSize(0.035)
l1.AddEntry(hist_SS_data,"SS Data","P")
l1.AddEntry(hist_MCMap, "OS  FQ^{truth,truth}(p_{T},|#eta|)","P")
l1.AddEntry(hist_MCMixedMap, "OS  FQ^{truth,data}(p_{T},|#eta|)","P")
l1.Draw()        


text = TLatex()
text.SetNDC()
text.SetTextColor(kBlack)
text.SetTextSize(0.035)
text.DrawLatex(0.2,0.85," #int Ldt = 13 fb^{-1} 2012 data (#sqrt{s}=8TeV)")
