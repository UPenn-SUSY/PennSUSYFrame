from ROOT import *



fileZee = TFile("/exports/project/data_d07_3/ehines/SusyFrame/Susy/SusyDiLeptonChargeFlipCycle.MC.egamma.2012_10_11.1.SherpaZee.root")

fileTTbar = TFile("/exports/project/data_d07_3/ehines/SusyFrame/Susy/SusyDiLeptonChargeFlipCycle.MC.egamma.2012_10_12.1.SherpaTtbar.root")

flippedHist = fileZee.Get("ChargeFlipEst/h_flipped")
unflippedHist = fileZee.Get("ChargeFlipEst/h_unflipped")


flippedHistTTbar = fileTTbar.Get("ChargeFlipEst/h_flipped")
unflippedHistTTbar = fileTTbar.Get("ChargeFlipEst/h_unflipped")

numBinsX = flippedHist.GetNbinsX()
numBinsY = flippedHist.GetNbinsY()
HistRatio = flippedHist.Clone()
HistTTbarRatio = flippedHist.Clone()
    
for i in range(1,numBinsX+1):
    for j in range(1,numBinsY+1):
        ratio = 0
        total = unflippedHist.GetBinContent(i,j)+flippedHist.GetBinContent(i,j)

        ratioTTbar = 0
        totalTTbar = unflippedHistTTbar.GetBinContent(i,j)+flippedHistTTbar.GetBinContent(i,j)
        if(total > 0):
            ratio = flippedHist.GetBinContent(i,j)/total
            error = sqrt(ratio*(1-ratio)/total)
            HistRatio.SetBinContent(i,j,ratio)
            HistRatio.SetBinError(i,j,error)
        if(totalTTbar > 0):
            ratioTTbar= flippedHistTTbar.GetBinContent(i,j)/totalTTbar
            errorTTbar = sqrt(ratioTTbar*(1-ratioTTbar)/totalTTbar)
            HistTTbarRatio.SetBinContent(i,j,ratioTTbar)
            HistTTbarRatio.SetBinError(i,j,errorTTbar)

       


HistRatio.GetYaxis().SetTitle("|#eta|")
HistRatio.GetXaxis().SetTitle("p_{T}")

HistTTbarRatio.GetYaxis().SetTitle("|#eta|")
HistTTbarRatio.GetXaxis().SetTitle("p_{T}")


#HistRatio.GetZaxis().SetRangeUser(0,0.2)
#HistTTbarRatio.GetZaxis.SetRangeUser(0,0.2)


c1=TCanvas("c1","c1",800,600)
c1.cd()
c1.SetLogx()
HistRatio.Draw("coletext")
#HistTTbarRatio.Draw("same")
c2=TCanvas("c2","c2",800,600)
c2.cd()
c2.SetLogx()
HistTTbarRatio.Draw("coletext")

##l1 = TLegend(0.225,0.7,0.425,0.84)
##l1.SetBorderSize(0)
##l1.SetFillColor(0)
##l1.SetTextSize(0.038)
##l1.AddEntry(HistRatio,"MC Zee","P")
##l1.AddEntry(HistTTbarRatio, "MC Ttbar", "P")
##l1.Draw("same")

outfile = TFile("ttbar_map.root","recreate")
HistTTbarRatio.Write()
outfile.Close()

outfile2 = TFile("Zee_MC_map.root","recreate")
HistRatio.Write()
outfile2.Close()
