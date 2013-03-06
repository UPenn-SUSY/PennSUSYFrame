from ROOT import *

#gROOT.LoadMacro("~/root/AtlasStyle.C")
#SetAtlasStyle()

fileData = TFile("/exports/project/data_d07_3/ehines/SusyFrame/Susy_presel_12Feb/utils/ChargeFlipCalc/data_out_full_range.root")

fileMixedMap = TFile("/exports/project/data_d07_3/ehines/SusyFrame/Susy_presel_12Feb/utils/ChargeFlipCalc/data_mixed_map_out_full_range.root")
fileTruthOnlyMap = TFile("/exports/project/data_d07_3/ehines/SusyFrame/Susy_presel_12Feb/utils/ChargeFlipCalc/data_truth_map_out_full_range.root")

hist_SS_data = fileData.Get("h_mll_ss")


###
hist_truth_map_total  = fileTruthOnlyMap.Get("h_mll")
hist_mixed_map_total = fileMixedMap.Get("h_mll")

hist_truth_map_ss = fileTruthOnlyMap.Get("h_mll_ss")
hist_mixed_map_ss = fileMixedMap.Get("h_mll_ss")
###

hist_truth_map = hist_truth_map_ss.Clone()
hist_mixed_map = hist_mixed_map_ss.Clone()

numBins = hist_truth_map_ss.GetNbinsX()

for i in range (1,numBins+1):
    hist_truth_map.SetBinContent(i,(hist_truth_map_total.GetBinContent(i) - hist_truth_map_ss.GetBinContent(i)))
    hist_mixed_map.SetBinContent(i,(hist_mixed_map_total.GetBinContent(i) - hist_mixed_map_ss.GetBinContent(i)))

hist_SS_data.SetMarkerStyle(kFullCircle)
hist_SS_data.SetMarkerColor(kBlack)

hist_truth_map.SetMarkerStyle(kOpenCircle)
hist_truth_map.SetMarkerColor(kRed)

hist_mixed_map.SetMarkerStyle(kOpenDiamond)
hist_mixed_map.SetMarkerColor(kGreen)

hist_truth_map.GetYaxis().SetRangeUser(0,10000)
hist_truth_map.GetYaxis().SetTitle("events/ 1 GeV")
hist_truth_map.GetXaxis().SetRangeUser(70,112)
hist_truth_map.GetXaxis().SetTitle("m_{ll} [GeV]")

c1 = TCanvas ("c1","c1",800,600)
c1.cd()
hist_truth_map.Draw("P")
hist_SS_data.Draw("P same")
hist_mixed_map.Draw("P same")


l1 = TLegend(0.66,0.56,0.80,0.72)
l1.SetBorderSize(0)
l1.SetFillColor(0);
l1.SetTextSize(0.035)
l1.AddEntry(hist_SS_data,"SS Data","P")
l1.AddEntry(hist_truth_map, "OS  FQ^{truth,truth}(p_{T},|#eta|)","P")
l1.AddEntry(hist_mixed_map, "OS  FQ^{truth,data}(p_{T},|#eta|)","P")
l1.Draw()        


text = TLatex()
text.SetNDC()
text.SetTextColor(kBlack)
text.SetTextSize(0.035)
text.DrawLatex(0.2,0.85," #int Ldt = 20.7 fb^{-1} 2012 data (#sqrt{s}=8TeV)")
