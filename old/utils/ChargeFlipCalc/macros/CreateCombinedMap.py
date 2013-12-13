from ROOT import *


fileMC = TFile("../MC/cf30.root")

fileData= TFile("../Data/cf30.root")


# Get the estimate from Truth
Hist2D_flipped = fileMC.Get("h_flipped")
Hist2D_total = fileMC.Get("h_total")

total_eta = Hist2D_total.ProjectionY()
flipped_eta = Hist2D_flipped.ProjectionY()

mc_ratio_eta= total_eta.Clone()
mc_ratio_eta.Divide(flipped_eta,total_eta,1,1,"b")

#mc_ratio_eta.Draw()


#Get the estimate from Likelihood
likelihood_Hist=fileData.Get("h_lklh_rate")


xs = total_eta.Clone()

numEtaBins = Hist2D_flipped.GetNbinsY()
numPtBins = Hist2D_flipped.GetNbinsX()

    
for i in range(1,numEtaBins+1):

    likelihoodValue = likelihood_Hist.GetBinContent(i)
    truthValue = mc_ratio_eta.GetBinContent(i)

    print "Likelihood",likelihoodValue
    print "truth", truthValue
    
    if (truthValue != 0 and likelihoodValue!=0):
        d_likelihoodError = likelihood_Hist.GetBinError(i)/likelihoodValue
        d_truthError = mc_ratio_eta.GetBinError(i)/truthValue


        error = sqrt(d_likelihoodError*d_likelihoodError+d_truthError*d_truthError)*(likelihoodValue/truthValue)
        
        xs.SetBinContent(i,likelihoodValue/truthValue)
        xs.SetBinError(i,error)
    else:
        xs.SetBinContent(i,0)
        xs.SetBinError(i,0)


#Mulitply numerator by xs

for eta in range(1,numEtaBins+1):
    x = xs.GetBinContent(eta)
    ex = xs.GetBinError(eta)

    print ""
    print x


    for pT in range(1,numPtBins+1):
        old_flipped = Hist2D_flipped.GetBinContent(pT,eta)
        new_flipped = x*old_flipped

        denom = Hist2D_total.GetBinContent(pT,eta)
        print old_flipped,new_flipped,denom
        Hist2D_flipped.SetBinContent(pT,eta,new_flipped)
        #print pT,eta,Hist2D_flipped.GetBinContent(pT,eta),Hist2D_total.GetBinContent(pT,eta)
        
        old_error = Hist2D_flipped.GetBinError(pT,eta)

        new_error = sqrt(old_error*old_error+ex*ex)

        Hist2D_flipped.SetBinError(pT,eta,new_error)
        
    

combMap = Hist2D_flipped.Clone()
combMap.Divide(Hist2D_flipped, Hist2D_total, 1., 1., "B")


combMap.GetYaxis().SetRangeUser(10,200)

c1 = TCanvas ("c1","c1",800,600)
c1.cd()
c1.SetLogx()
combMap.GetYaxis().SetTitle("|#eta|")
combMap.GetXaxis().SetTitle("p_{T} [GeV]")
combMap.Draw("COL TEXT")



out_file = TFile("ZAlpgenMapFull2012_d0sig3.root","recreate")

combMap.Write()
out_file.Close()
