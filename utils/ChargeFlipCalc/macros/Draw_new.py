from ROOT import *

#fileData = TFile("/exports/project/data_d07_4/ehines/output/SusyDiLeptonChargeFlipCycle.MC.egamma.2012_09_12.1.ZeeNp1.root")

fileMC = TFile("/exports/project/data_d07_3/ehines/SusyFrame/Susy/Zee21Sep.total.root")

fileLikelihood= TFile("/exports/project/data_d07_3/ehines/SusyFrame/Susy/plot_dev/charge_flip/14Sep.root")

fileData = TFile("/exports/project/data_d07_3/ehines/SusyFrame/Susy/plot_dev/charge_flip/out_data.root")

flippedHist = fileMC.Get("ChargeFlipEst/h_flipped_eta_only")
unflippedHist = fileMC.Get("ChargeFlipEst/h_unflipped_eta_only")

flippedHist_pt = fileMC.Get("ChargeFlipEst/h_flipped_pt_only")
unflippedHist_pt = fileMC.Get("ChargeFlipEst/h_unflipped_pt_only")

likelihoodHist = fileLikelihood.Get("h_charge_flip")
dataHist = fileData.Get("h_charge_flip")

numBins_pt = flippedHist_pt.GetNbinsX()
HistRatio_pt =flippedHist_pt.Clone()

numBins = flippedHist.GetNbinsX()
HistRatio = flippedHist.Clone()

Hist2D_flipped = fileMC.Get("ChargeFlipEst/h_flipped")
Hist2D_unflipped = fileMC.Get("ChargeFlipEst/h_unflipped")


Hist2D_unflipped.Add(Hist2D_flipped)

Hist2D_flipped.Divide(Hist2D_unflipped)

    
for i in range(1,numBins+1):
    ratio = 0
    total = unflippedHist.GetBinContent(i)+flippedHist.GetBinContent(i)
    if(total > 0):
        ratio = flippedHist.GetBinContent(i)/total
        error = sqrt(ratio*(1-ratio)/total)
        HistRatio.SetBinContent(i,ratio)
        HistRatio.SetBinError(i,error)

for i in range(1,numBins_pt+1):
    ratio = 0
    total = unflippedHist_pt.GetBinContent(i)+flippedHist_pt.GetBinContent(i)
    if(total > 0):
        ratio = flippedHist_pt.GetBinContent(i)/total
        error = sqrt(ratio*(1-ratio)/total)
        HistRatio_pt.SetBinContent(i,ratio)
        HistRatio_pt.SetBinError(i,error)        
        

HistRatio.SetMarkerStyle(20)
HistRatio.GetYaxis().SetRangeUser(0.0001,1)
HistRatio.GetYaxis().SetTitle("Charge Flip Rate")
HistRatio.GetXaxis().SetTitle("|#eta|")

HistRatio.GetYaxis().SetRangeUser(0.0001,1)

likelihoodHist.SetMarkerStyle(22)
likelihoodHist.SetMarkerColor(kBlue)

dataHist.SetMarkerStyle(23)
dataHist.SetMarkerColor(kRed)

Hist2D_flipped.GetYaxis().SetRangeUser(10,4000)

HistRatio.GetYaxis().SetRangeUser(0,0.055)
c1=TCanvas("c1","c1",800,600)
c1.cd()
#c1.SetLogy()
HistRatio.Draw()
#likelihoodHist.Draw("same")
dataHist.Draw("same")

l1 = TLegend(0.225,0.7,0.425,0.84)
l1.SetBorderSize(0)
l1.SetFillColor(0)
l1.SetTextSize(0.038)
l1.AddEntry(HistRatio,"MC from Truth","P")
#l1.AddEntry(likelihoodHist, "MC from Likelihood", "P")
l1.AddEntry(dataHist, "Data", "P")
l1.Draw("same")

c2=TCanvas("c2","c2",800,600)
c2.cd()
c2.SetLogy()
c2.SetLogx()
HistRatio_pt.Draw()


c3=TCanvas("c3","c3",800,600)
c3.cd()
c3.SetLogx()
#c3.SetLogz()
Hist2D_flipped.Draw("colz text")



