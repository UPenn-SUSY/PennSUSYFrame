################################################################
## In principle all you have to setup is defined in this file ##
################################################################
from configManager import configMgr
from ROOT import kBlack,kWhite,kGray,kRed,kPink,kMagenta,kViolet,kBlue,kAzure,kCyan,kTeal,kGreen,kSpring,kYellow,kOrange,kDashed,kSolid,kDotted
from configWriter import fitConfig,Measurement,Channel,Sample
from systematic import Systematic
from math import sqrt

# Setup for ATLAS plotting
from ROOT import gROOT, TLegend, TLegendEntry, TCanvas
gROOT.LoadMacro("./macros/AtlasStyle.C")
import ROOT
ROOT.SetAtlasStyle()

#---------------------------------------------------------------------------------------------
# Some flags for overridding normal execution and telling ROOT to shut up... use with caution!
#---------------------------------------------------------------------------------------------
#gROOT.ProcessLine("gErrorIgnoreLevel=10001;")
#configMgr.plotHistos = True

#---------------------------------------
# Flags to control which fit is executed
#---------------------------------------
useStat = True
doValidation = True

print 'Analysis configurations:'
if myFitType == FitType.Exclusion:
    print '  fit type: Exclusion'
elif myFitType == FitType.Discovery:
    print '  fit type: Discovery'
elif myFitType == FitType.Background:
    print '  fit type: Background'
else:
    print '  fit type: Undefined :('

#-------------------------------
# Parameters for hypothesis test
#-------------------------------
#configMgr.doHypoTest=False
#configMgr.nTOYs=1000
configMgr.calculatorType=2
configMgr.testStatType=3
configMgr.nPoints=20

#--------------------------------
# Now we start to build the model
#--------------------------------

# First define HistFactory attributes
configMgr.analysisName = "SampleExcl"

# Scaling calculated by outputLumi / inputLumi
configMgr.inputLumi = 0.001 # Luminosity of input TTree after weighting
configMgr.outputLumi = 20.3  # Luminosity required for output histograms
configMgr.setLumiUnits("fb-1")

configMgr.histCacheFile = "data/"+configMgr.analysisName+".root"

configMgr.outputFileName = "results/"+configMgr.analysisName+"_Output.root"

# Set the files to read from
bgdFiles = []
sigFiles = []
if configMgr.readFromTree:
    print 'reading from trees!'
    # TODO point to my files instead of default ones!!!
    bgdFiles.append("samples/tutorial/SusyFitterTree_OneSoftEle_BG_v3.root")
    bgdFiles.append("samples/tutorial/SusyFitterTree_OneSoftMuo_BG_v3.root")
    if myFitType==FitType.Exclusion:
        # 1-step simplified model
        sigFiles.append("samples/tutorial/SusyFitterTree_p832_GG-One-Step_soft_v1.root")
else:
    print 'not reading from trees -- getting input from cache!'
    bgdFiles = ["data/"+configMgr.analysisName+".root"]

# Dictionnary of cuts for Tree->hist
#CR
# TODO replace with my SR definitions
configMgr.cutsDict["SR_ee"] = "(lep1Pt >= 40 && lep2Pt >= 40 && n&& met>180 && met<250 && mt>40 && mt<80 && nB2Jet==0 && jet1Pt>130 && jet2Pt>25  && AnalysisType==7) || (lep1Pt < 25 && lep2Pt<10 && met>180 && met<250 && mt>40 && mt<80 && nB2Jet==0 && jet1Pt>130 && jet2Pt>25  && AnalysisType==6)"
configMgr.cutsDict["SR_mm"] = "(lep1Pt >= 40 && lep2Pt >= 40 && n&& met>180 && met<250 && mt>40 && mt<80 && nB2Jet>0 && jet1Pt>130 && jet2Pt>25 && AnalysisType==6)   || (lep1Pt < 20 && lep2Pt<10 && met>180 && met<250 && mt>40 && mt<80 && nB2Jet>0 && jet1Pt>130 && jet2Pt>25 && AnalysisType==7)"
configMgr.cutsDict["SR_em"] = "(lep1Pt >= 40 && lep2Pt >= 40 && n&& met>180 && met<250 && mt>40 && mt<80 && nB2Jet>0 && jet1Pt>130 && jet2Pt>25 && AnalysisType==6)   || (lep1Pt < 20 && lep2Pt<10 && met>180 && met<250 && mt>40 && mt<80 && nB2Jet>0 && jet1Pt>130 && jet2Pt>25 && AnalysisType==7)"
#VR
# TODO replace with my VR definitions
configMgr.cutsDict["VR_ee"] = "(lep1Pt < 25 && lep2Pt<10 && met>180 && met<250 && mt>80 && mt<100 && jet1Pt>130 && jet2Pt>25 && AnalysisType==6) || (lep1Pt < 20 && lep2Pt<10 && met>180 && met<250 && mt>80 && mt<100 && jet1Pt>130 && jet2Pt>25 && AnalysisType==7)"
configMgr.cutsDict["VR_mm"] = "(lep1Pt < 25 && lep2Pt<10 && met>180 && met<250 && mt>80 && mt<100 && jet1Pt>130 && jet2Pt>25 && AnalysisType==6) || (lep1Pt < 20 && lep2Pt<10 && met>180 && met<250 && mt>80 && mt<100 && jet1Pt>130 && jet2Pt>25 && AnalysisType==7)"
configMgr.cutsDict["VR_em"] = "(lep1Pt < 25 && lep2Pt<10 && met>180 && met<250 && mt>80 && mt<100 && jet1Pt>130 && jet2Pt>25 && AnalysisType==6) || (lep1Pt < 20 && lep2Pt<10 && met>180 && met<250 && mt>80 && mt<100 && jet1Pt>130 && jet2Pt>25 && AnalysisType==7)"
#SR
# TODO replace with my CR definitions
configMgr.cutsDict["CR_top"] = "((lep1Pt < 20 && lep2Pt<10 && met>250 && mt>100 && jet1Pt>130 && jet2Pt>25 && AnalysisType==7) || (lep1Pt < 25 && lep2Pt<10 && met>250 && mt>100 && jet1Pt>130 && jet2Pt>25 && AnalysisType==6))"


# Tuples of nominal weights without and with b-jet selection
configMgr.weights = ("genWeight","eventWeight","leptonWeight","triggerWeight","truthWptWeight","bTagWeight2Jet")
# configMgr.weights = ("weight")

ktScaleWHighWeights = ("genWeight","eventWeight","ktfacUpWeightW","bTagWeight2Jet")
ktScaleWLowWeights  = ("genWeight","eventWeight","ktfacDownWeightW","bTagWeight2Jet")

ktScaleTopHighWeights = ("genWeight","eventWeight","ktfacUpWeightTop","bTagWeight2Jet")
ktScaleTopLowWeights = ("genWeight","eventWeight","ktfacDownWeightTop","bTagWeight2Jet")

# QCD weights without and with b-jet selection
configMgr.weightsQCD = "qcdWeight"
configMgr.weightsQCDWithB = "qcdBWeight"

#--------------------
# List of systematics
#--------------------
# generic systematic -- placeholder for now
gen_syst = Systematic( "gen_syst"
                     , configMgr.weights
                     , 1.0 + 0.30
                     , 1.0 - 0.30
                     , "user"
                     , "userOverallSys"
                     )

# JES uncertainty as shapeSys - one systematic per region (combine WR and TR), merge samples
jes = Systematic("JES","_NoSys","_JESup","_JESdown","tree","overallNormHistoSys")

# statWRwz  = Systematic("SLWR_wz", "_NoSys","","","tree","shapeStat")
# statWRtop = Systematic("SLWR_top","_NoSys","","","tree","shapeStat")

# name of nominal histogram for systematics
configMgr.nomName = "_NoSys"

# List of samples and their plotting colours
topSample = Sample("Top",kGreen-9)
topSample.setNormFactor("mu_Top",1.,0.,5.)
topSample.setStatConfig(useStat)
topSample.setNormRegions([("CR_top","nJet")])

wzSample = Sample("WZ",kAzure+1)
wzSample.setNormFactor("mu_WZ",1.,0.,5.)
wzSample.setStatConfig(useStat)
wzSample.setNormRegions([("CR_top","nJet")])

bgSample = Sample("BG",kYellow-3)
bgSample.setNormFactor("mu_BG",1.,0.,5.)
bgSample.setStatConfig(useStat)
bgSample.setNormRegions([("CR_top","nJet")])

qcdSample = Sample("QCD",kGray+1)
qcdSample.setQCD(True,"histoSys")
qcdSample.setStatConfig(useStat)

dataSample = Sample("Data",kBlack)
dataSample.setData()

# set the file from which the samples should be taken
for sam in [topSample, wzSample, bgSample, qcdSample, dataSample]:
        sam.setFileList(bgdFiles)

#Binnings
nJetBinLowHard = 3
nJetBinLowSoft = 2
nJetBinHighTR = 10
nJetBinHighWR = 10

nBJetBinLow = 0
nBJetBinHigh = 4

meffNBins = 6
meffBinLow = 400.
meffBinHigh = 1600.

meffNBinsSR4 = 4
meffBinLowSR4 = 800.
meffBinHighSR4 = 1600.

lepPtNBins = 6
lepPtLow = 20.
lepPtHigh = 600.

srNBins = 1
srBinLow = 0.5
srBinHigh = 1.5

#************
#Bkg only fit
#************
bkt = configMgr.addFitConfig("BkgOnly")
if useStat:
    bkt.statErrThreshold=0.05
else:
    bkt.statErrThreshold=None
bkt.addSamples([topSample,wzSample,qcdSample,bgSample,dataSample])

# Systematics to be applied globally within this topLevel
bkt.getSample("Top").addSystematic(gen_syst)
bkt.getSample("WZ").addSystematic(gen_syst)

meas = bkt.addMeasurement( name = "NormalMeasurement"
                         , lumi = 1.0
                         , lumiErr = 0.039
                         )
meas.addPOI("mu_SIG")
meas.addParamSetting( "mu_BG"
                    , True
                    , 1
                    )

#-------------------------------------------------
# Constraining regions - statistically independent
#-------------------------------------------------
# Add Top CR for background
n_jet_cr_top = bkt.addChannel( "nJet"
                             , ["CR_top"]
                             , nJetBinHighWR-nJetBinLowSoft
                             , nJetBinLowSoft
                             , nJetBinHighWR
                             )
n_jet_cr_top.hasB = True
n_jet_cr_top.hasBQCD = False
n_jet_cr_top.useOverflowBin = False
n_jet_cr_top.addSystematic(jes)

bkt.setBkgConstrainChannels([n_jet_cr_top])

###############################
#                             #
#    Example new cosmetics    #
#                             #
###############################
# Set global plotting colors/styles
bkt.dataColor = dataSample.color
bkt.totalPdfColor = kBlue
bkt.errorFillColor = kBlue-5
bkt.errorFillStyle = 3004
bkt.errorLineStyle = kDashed
bkt.errorLineColor = kBlue-5

# Set Channel titleX, titleY, minY, maxY, logY
n_jet_cr_top.minY = 0.5
n_jet_cr_top.maxY = 5000
n_jet_cr_top.titleX = "n jets"
n_jet_cr_top.titleY = "Entries"
n_jet_cr_top.logY = True
n_jet_cr_top.ATLASLabelX = 0.25
n_jet_cr_top.ATLASLabelY = 0.85
n_jet_cr_top.ATLASLabelText = "Work in progress"

#--------------------------------------------------------------
# Validation regions - not necessarily statistically independent
#--------------------------------------------------------------
if doValidation:
    print 'Setting up validation regions!'
    # VR
    # additional VRs if using soft lep CRs
    n_jet_vr_ee = bkt.addChannel( "nJet"
                                , ["VR_ee"]
                                , nJetBinHighTR-nJetBinLowSoft
                                , nJetBinLowSoft
                                , nJetBinHighTR
                                )
    n_jet_vr_mm = bkt.addChannel( "nJet"
                                , ["VR_mm"]
                                , nJetBinHighTR-nJetBinLowSoft
                                , nJetBinLowSoft
                                , nJetBinHighTR
                                )
    n_jet_vr_em = bkt.addChannel( "nJet"
                                , ["VR_em"]
                                , nJetBinHighTR-nJetBinLowSoft
                                , nJetBinLowSoft
                                , nJetBinHighTR
                                )
    n_jet_vr_ee.addSystematic(jes)
    n_jet_vr_mm.addSystematic(jes)
    n_jet_vr_em.addSystematic(jes)

    bkt.setValidationChannels( [ n_jet_vr_ee
                               , n_jet_vr_mm
                               , n_jet_vr_em
                               ]
                             )

#**************
# Discovery fit
#**************
if myFitType==FitType.Discovery:
    print 'Setting up discovery fit!'
    discovery = configMgr.addFitConfigClone(bkt,"Discovery")

    # s1l2jT = signal region/channel
    ssChannel = discovery.addChannel("cuts",["SS"],srNBins,srBinLow,srBinHigh)
    ssChannel.addSystematic(jes)
    ssChannel.addDiscoverySamples(["SS"],[1.],[0.],[100.],[kMagenta])
    discovery.setSignalChannels([ssChannel])

#-----------------------------
# Exclusion fits (1-step simplified model in this case)
#-----------------------------
if myFitType==FitType.Exclusion:
    print 'Setting up exclusion fit!'
    sigSamples=["SM_GG_onestepCC_425_385_345"]
    for sig in sigSamples:
        myTopLvl = configMgr.addFitConfigClone(bkt,"Sig_%s"%sig)

        sigSample = Sample(sig,kPink)
        sigSample.setFileList(sigFiles)
        sigSample.setNormByTheory()
        sigSample.setStatConfig(useStat)
        sigSample.setNormFactor("mu_SIG",1.,0.,5.)
        myTopLvl.addSamples(sigSample)
        myTopLvl.setSignalSample(sigSample)

        # s1l2j using met/meff
        if doValidation:
            mm2J = myTopLvl.getChannel("met/meff2Jet",["SS"])
            iPop=myTopLvl.validationChannels.index("SS_metmeff2Jet")
            myTopLvl.validationChannels.pop(iPop)
        else:
            mm2J = myTopLvl.addChannel("met/meff2Jet",["SS"],5,0.2,0.7)
            mm2J.useOverflowBin=True
            mm2J.addSystematic(jes)
            pass
        myTopLvl.setSignalChannels([mm2J])

# Create TLegend (AK: TCanvas is needed for that, but it gets deleted afterwards)
c = TCanvas()
compFillStyle = 1001 # see ROOT for Fill styles
leg = TLegend(0.6,0.475,0.9,0.925,"")
leg.SetFillStyle(0)
leg.SetFillColor(0)
leg.SetBorderSize(0)
#
entry = TLegendEntry()
entry = leg.AddEntry("","Data 2011 (#sqrt{s}=7 TeV)","p")
entry.SetMarkerColor(bkt.dataColor)
entry.SetMarkerStyle(20)
#
entry = leg.AddEntry("","Total pdf","lf")
entry.SetLineColor(bkt.totalPdfColor)
entry.SetLineWidth(2)
entry.SetFillColor(bkt.errorFillColor)
entry.SetFillStyle(bkt.errorFillStyle)
#
entry = leg.AddEntry("","t#bar{t}","lf")
entry.SetLineColor(topSample.color)
entry.SetFillColor(topSample.color)
entry.SetFillStyle(compFillStyle)
#
entry = leg.AddEntry("","WZ","lf")
entry.SetLineColor(wzSample.color)
entry.SetFillColor(wzSample.color)
entry.SetFillStyle(compFillStyle)
#
entry = leg.AddEntry("","multijets (data estimate)","lf")
entry.SetLineColor(qcdSample.color)
entry.SetFillColor(qcdSample.color)
entry.SetFillStyle(compFillStyle)
#
entry = leg.AddEntry("","single top & diboson","lf")
entry.SetLineColor(bgSample.color)
entry.SetFillColor(bgSample.color)
entry.SetFillStyle(compFillStyle)
#
if myFitType==FitType.Exclusion:
    entry = leg.AddEntry("","signal","lf")
    entry.SetLineColor(kPink)
    entry.SetFillColor(kPink)
    entry.SetFillStyle(compFillStyle)


# Set legend for fitConfig
bkt.tLegend = leg
if myFitType==FitType.Exclusion:
    myTopLvl.tLegend = leg
c.Close()

print 'done with my stuff'
print '--------------------------------------------------------------------------------'
print ''
