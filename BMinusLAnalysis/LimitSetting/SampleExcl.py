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
# doValidation = False
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
configMgr.inputLumi = 0.001    # Luminosity of input TTree after weighting
configMgr.outputLumi = 13.0    # Luminosity required for output histograms
# configMgr.outputLumi = 21.0    # Luminosity required for output histograms
configMgr.setLumiUnits("fb-1")

configMgr.histCacheFile = "data/"+configMgr.analysisName+".root"

configMgr.outputFileName = "results/"+configMgr.analysisName+"_Output.root"

# Set the files to read from
bgdFiles = []
sigFiles = []
if configMgr.readFromTree:
    print 'reading from trees!'
    bgdFiles.append("${BASE_WORK_DIR}/HistFitterNtuples/BackgroundHistFitterTrees.root")
    if myFitType==FitType.Exclusion:
        # 1-step simplified model
        sigFiles.append("${BASE_WORK_DIR}/HistFitterNtuples/SignalHistFitterTrees.root")
else:
    print 'not reading from trees -- getting input from cache!'
    bgdFiles = ["data/"+configMgr.analysisName+".root"]

# ------------------------------------------------------------------------------
# Dictionnary of cuts for Tree->hist
# SR
# TODO replace with my SR definitions
# base_sr_str = "( ((mbl_0-mbl_1)/(mbl_0+mbl_1) <= 0.6) && (ht_signal >= 600) && (met_et/sqrt(ht_signal) <= 7) )"
# base_sr_str = "( ((mbl_0-mbl_1)/(mbl_0+mbl_1) <= 0.6) && (ht_signal >= 200) && (met_et/sqrt(ht_signal) <= 7) )"
base_sr_str = "( ((mbl_0-mbl_1)/(mbl_0+mbl_1) <= 0.8) && (ht_signal >= 200) && (met_et/sqrt(ht_signal) <= 8) )"

configMgr.cutsDict["SR"] = base_sr_str

# VR
# TODO replace with my VR definitions
base_vr_str = "( (ht_signal <= 600) )"

configMgr.cutsDict["VR"] = base_vr_str

# CR
# TODO replace with my CR definitions
# base_cr_str = "( ((mbl_0-mbl_1)/(mbl_0+mbl_1) >= 0.3) && (ht_signal <= 600) && (met_et/sqrt(ht_signal) >= 7) )"
base_cr_str = "( (ht_signal <= 200) )"

configMgr.cutsDict["CR_top"] = base_cr_str

# ------------------------------------------------------------------------------
# lists of nominal weights
configMgr.weights = ["weight"]

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
# jes = Systematic("JES","_NoSys","_JESup","_JESdown","tree","overallNormHistoSys")

# name of nominal histogram for systematics
configMgr.nomName = "_NoSys"

# List of samples and their plotting colours
ttbarSample = Sample("ttbar",kGreen-9)
ttbarSample.setNormFactor("mu_ttbar",1.,0.,5.)
ttbarSample.setStatConfig(useStat)
ttbarSample.setNormRegions([("CR_top","mbl_0")])
# ttbarSample.setNormRegions([("CR_top","ptll")])

singleTopSample = Sample("Single top",kAzure-9)
singleTopSample.setNormFactor("mu_st",1.,0.,5.)
singleTopSample.setStatConfig(useStat)
singleTopSample.setNormRegions([("CR_top","mbl_0")])
# singleTopSample.setNormRegions([("CR_top","ptll")])

zSample = Sample("Z",kRed-9)
zSample.setNormFactor("mu_z",1.,0.,5.)
zSample.setStatConfig(useStat)
zSample.setNormRegions([("CR_top","mbl_0")])
# zSample.setNormRegions([("CR_top","ptll")])

dataSample = Sample("data",kBlack)
dataSample.setData()

# set the file from which the samples should be taken
for sam in [ttbarSample, singleTopSample, zSample, dataSample]:
        sam.setFileList(bgdFiles)

#Binnings
# mbl_bin = 60
mbl_bin = 6
mbl_min = 0
mbl_max = 1200

mll_bin = 25
mll_min = 0
mll_max = 500

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
bkt.addSamples([ttbarSample, singleTopSample, zSample, dataSample])

# Systematics to be applied globally within this topLevel
bkt.getSample("ttbar").addSystematic(gen_syst)
bkt.getSample("Z"    ).addSystematic(gen_syst)

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
mbl_0_cr_top = bkt.addChannel( "mbl_0"
                           , ["CR_top"]
                           , mbl_bin
                           , mbl_min
                           , mbl_max
                           )
mbl_0_cr_top.hasB = True
mbl_0_cr_top.hasBQCD = False
mbl_0_cr_top.useOverflowBin = False
# mbl_0_cr_top.addSystematic(jes)

mbl_1_cr_top = bkt.addChannel( "mbl_1"
                           , ["CR_top"]
                           , mbl_bin
                           , mbl_min
                           , mbl_max
                           )
mbl_1_cr_top.hasB = True
mbl_1_cr_top.hasBQCD = False
mbl_1_cr_top.useOverflowBin = False
# mbl_1_cr_top.addSystematic(jes)

mll_cr_top = bkt.addChannel( "mll"
                           , ["CR_top"]
                           , mll_bin
                           , mll_min
                           , mll_max
                           )
mll_cr_top.hasB = True
mll_cr_top.hasBQCD = False
mll_cr_top.useOverflowBin = False
# mll_cr_top.addSystematic(jes)

bkt.setBkgConstrainChannels([mbl_0_cr_top, mbl_1_cr_top, mll_cr_top])

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
mbl_0_cr_top.minY = 0.5
# mbl_0_cr_top.maxY = 50000
mbl_0_cr_top.titleX = "mbl^{0} [GeV]"
mbl_0_cr_top.titleY = "Entries"
mbl_0_cr_top.logY = True
mbl_0_cr_top.ATLASLabelX = 0.25
mbl_0_cr_top.ATLASLabelY = 0.85
mbl_0_cr_top.ATLASLabelText = "Work in progress"

mbl_1_cr_top.minY = 0.5
# mbl_1_cr_top.maxY = 50000
mbl_1_cr_top.titleX = "mbl^{1} [GeV]"
mbl_1_cr_top.titleY = "Entries"
mbl_1_cr_top.logY = True
mbl_1_cr_top.ATLASLabelX = 0.25
mbl_1_cr_top.ATLASLabelY = 0.85
mbl_1_cr_top.ATLASLabelText = "Work in progress"

mll_cr_top.minY = 0.5
# mll_cr_top.maxY = 50000
mll_cr_top.titleX = "mll [GeV]"
mll_cr_top.titleY = "Entries"
mll_cr_top.logY = True
mll_cr_top.ATLASLabelX = 0.25
mll_cr_top.ATLASLabelY = 0.85
mll_cr_top.ATLASLabelText = "Work in progress"

#--------------------------------------------------------------
# Validation regions - not necessarily statistically independent
#--------------------------------------------------------------
if doValidation:
    print 'Setting up validation regions!'
    # VR
    mbl_0_vr = bkt.addChannel( "mbl_0"
                             , ["VR"]
                             , mbl_bin
                             , mbl_min
                             , mbl_max
                             )
    mbl_1_vr = bkt.addChannel( "mbl_1"
                             , ["VR"]
                             , mbl_bin
                             , mbl_min
                             , mbl_max
                             )
    mll_vr = bkt.addChannel( "mll_1"
                           , ["VR"]
                           , mll_bin
                           , mll_min
                           , mll_max
                           )
    # mbl_vr.addSystematic(jes)

    bkt.setValidationChannels( [ mbl_0_vr
                               , mbl_1_vr
                               , mll_vr
                               ]
                             )

#**************
# Discovery fit
#**************
if myFitType==FitType.Discovery:
    print 'ERROR!!! DISCOVERY FIT IS NOT YET CONFIGURED!!!'

    print 'Setting up discovery fit!'
    discovery = configMgr.addFitConfigClone(bkt,"Discovery")

    # s1l2jT = signal region/channel
    ssChannel = discovery.addChannel("cuts",["SR"],srNBins,srBinLow,srBinHigh)
    # ssChannel.addSystematic(jes)
    ssChannel.addDiscoverySamples(["SR"],[1.],[0.],[100.],[kMagenta])
    discovery.setSignalChannels([ssChannel])

#-----------------------------
# Exclusion fits (1-step simplified model in this case)
#-----------------------------
if myFitType==FitType.Exclusion:
    print 'Setting up exclusion fit!'
    sigSamples=["sig_500"]
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
            print 'do validation plots for exclusion'
            mbl_0_sr = myTopLvl.getChannel("mbl_0",["SR"])
            iPop=myTopLvl.validationChannels.index("SR_mbl")
            myTopLvl.validationChannels.pop(iPop)
        else:
            print "don't do validation plots for exclusion"
            mbl_0_sr = myTopLvl.addChannel( "mbl_0"
                                          , ["SR"]
                                          , mbl_bin
                                          , mbl_min
                                          , mbl_max
                                          )
            mbl_1_sr = myTopLvl.addChannel( "mbl_1"
                                          , ["SR"]
                                          , mbl_bin
                                          , mbl_min
                                          , mbl_max
                                          )
            mbl_0_sr.useOverflowBin=True
            # mbl.addSystematic(jes)
        myTopLvl.setSignalChannels([mbl_0_sr, mbl_1_sr])

# Create TLegend (AK: TCanvas is needed for that, but it gets deleted afterwards)
c = TCanvas()
compFillStyle = 1001 # see ROOT for Fill styles
leg = TLegend(0.6,0.475,0.9,0.925,"")
leg.SetFillStyle(0)
leg.SetFillColor(0)
leg.SetBorderSize(0)
#
entry = TLegendEntry()
entry = leg.AddEntry("","Data 2012 (#sqrt{s}=8 TeV)","p")
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
entry.SetLineColor(ttbarSample.color)
entry.SetFillColor(ttbarSample.color)
entry.SetFillStyle(compFillStyle)
#
entry = leg.AddEntry("","Single top","lf")
entry.SetLineColor(singleTopSample.color)
entry.SetFillColor(singleTopSample.color)
entry.SetFillStyle(compFillStyle)
#
entry = leg.AddEntry("","Z/#gamma*","lf")
entry.SetLineColor(zSample.color)
entry.SetFillColor(zSample.color)
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
