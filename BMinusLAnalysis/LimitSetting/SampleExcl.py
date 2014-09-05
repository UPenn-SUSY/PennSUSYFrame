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

# ----------------------------------------------------------------------------------------------
# - Some flags for overridding normal execution and telling ROOT to shut up... use with caution!
# ----------------------------------------------------------------------------------------------
#gROOT.ProcessLine("gErrorIgnoreLevel=10001;")
#configMgr.plotHistos = True

# ----------------------------------------
# - Flags to control which fit is executed
# ----------------------------------------
use_stat = True
do_validation = True

print 'Analysis configurations:'
if myFitType == FitType.Exclusion:
    print '  fit type: Exclusion'
elif myFitType == FitType.Discovery:
    print '  fit type: Discovery'
elif myFitType == FitType.Background:
    print '  fit type: Background'
else:
    print '  fit type: Undefined :('

# -----------------------------------------------------------------------
# - cannot do validation and exclusion/discovery at the same time for now
# -----------------------------------------------------------------------
if myFitType == FitType.Discovery or myFitType == FitType.Exclusion:
    print 'turning off validation for discovery or exclusion'
    do_validation = False

# --------------------------------
# - Parameters for hypothesis test
# --------------------------------
#configMgr.doHypoTest=False
configMgr.nTOYs=10000
configMgr.calculatorType=2 # use 2 for asymptotic, 0 for toys
configMgr.testStatType=3
configMgr.nPoints=10

# ---------------------------------
# - Now we start to build the model
# ---------------------------------

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
bkg_files = []
sig_files = []
if configMgr.readFromTree:
    print 'reading from trees!'
    bkg_files.append("${BASE_WORK_DIR}/HistFitterNtuples/BackgroundHistFitterTrees.root")
    if myFitType==FitType.Exclusion:
        # 1-step simplified model
        sig_files.append("${BASE_WORK_DIR}/HistFitterNtuples/SignalHistFitterTrees.root")
else:
    print 'not reading from trees -- getting input from cache!'
    bkg_files = ["data/"+configMgr.analysisName+".root"]

# ------------------------------------
# - Dictionnary of cuts for Tree->hist
# ------------------------------------
# SR
# TODO replace with my SR definitions
# base_sr_str = "( ((mbl_0-mbl_1)/(mbl_0+mbl_1) <= 0.6) && (ht_signal >= 600) && (met_et/sqrt(ht_signal) <= 7) )"
base_sr_str = "( ((mbl_0-mbl_1)/(mbl_0+mbl_1) <= 0.8) && (ht_signal >= 200) && (met_et/sqrt(ht_signal) <= 8) )"

configMgr.cutsDict["SR"] = base_sr_str

# VR
# TODO replace with my VR definitions
base_vr_str = "( (ht_signal <= 600) )"

configMgr.cutsDict["VR"] = base_vr_str

# CR
# TODO replace with my CR definitions
# base_cr_str = "( ((mbl_0-mbl_1)/(mbl_0+mbl_1) >= 0.3) && (ht_signal <= 600) && (met_et/sqrt(ht_signal) >= 7) )"
base_cr_top_str = "( ((mbl_0-mbl_1)/(mbl_0+mbl_1) >= 0.3) && (ht_signal <= 200) && (met_et/sqrt(ht_signal) >= 7) )"
# base_cr_str = "( (ht_signal <= 200) )"

configMgr.cutsDict["CR_top"] = base_cr_top_str

# CR_TMP
# TODO replace tmp CR with real CR
base_cr_tmp_str = "( (ht_signal <= 200) )"

configMgr.cutsDict["CR_tmp"] = base_cr_tmp_str

# --------------------------
# - lists of nominal weights
# --------------------------
configMgr.weights = ["weight"]

# name of nominal histogram for systematics
configMgr.nomName = "_NoSys"

# ---------------------
# - List of systematics
# ---------------------
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

# --------------------------------------------
# - List of samples and their plotting colours
# --------------------------------------------
sample_list = []

# ttbar
ttbar_sample = Sample( "ttbar" , kGreen-2 )
ttbar_sample.setNormFactor("mu_ttbar",1.,0.,5.)
ttbar_sample.setStatConfig(use_stat)
# TODO pick norm region more carefully
ttbar_sample.setNormRegions([("CR_top","mbl_0")])
sample_list.append(ttbar_sample)

# single top
single_top_sample = Sample( "SingleTop" , kGreen-1 )
single_top_sample.setNormFactor("mu_st",1.,0.,5.)
single_top_sample.setStatConfig(use_stat)
# TODO pick norm region more carefully
single_top_sample.setNormRegions([("CR_top","mbl_0")])
sample_list.append(single_top_sample)

# Z/gamma*
z_sample = Sample( "Z" , kRed+1 )
z_sample.setNormFactor("mu_z",1.,0.,5.)
z_sample.setStatConfig(use_stat)
# TODO pick norm region more carefully
z_sample.setNormRegions([("CR_top","mbl_0")])
sample_list.append(z_sample)

# data
data_sample = Sample("data",kBlack)
data_sample.setData()
sample_list.append(data_sample)

# set the file from which the samples should be taken
# for sam in [ ttbarSample, singleTopSample, zSample, dataSample]:
for sam in sample_list:
    sam.setFileList(bkg_files)

# ----------
# - Binnings
# ----------
# TODO reset the binning and add more histograms

# mbl binning
# mbl_bin = 60
mbl_bin = 6
mbl_min = 0
mbl_max = 1200

# mll binning
# mll_bin = 25
mll_bin = 5
mll_min = 0
mll_max = 500

# SR binning (this is just a single bin cut and count binning)
srNBins = 1
srBinLow = 0.5
srBinHigh = 1.5

# **************
# * Bkg only fit
# **************
background_config = configMgr.addFitConfig("BkgOnly")
if use_stat:
    background_config.statErrThreshold=0.05
else:
    background_config.statErrThreshold=None
background_config.addSamples(sample_list)

# Systematics to be applied globally within this topLevel
background_config.getSample("ttbar"    ).addSystematic(gen_syst)
background_config.getSample("SingleTop").addSystematic(gen_syst)
background_config.getSample("Z"        ).addSystematic(gen_syst)

meas = background_config.addMeasurement(name = "NormalMeasurement", lumi = 1.0, lumiErr = 0.039 )
meas.addPOI("mu_SIG")

# --------------------------------------------------
# - Constraining regions - statistically independent
# --------------------------------------------------
cr_list = []
# Add Top CR for background
cr_list.append( background_config.addChannel( "mbl_0" , ["CR_top"] , mbl_bin , mbl_min , mbl_max ) )
# cr_list.append( background_config.addChannel( "mbl_1" , ["CR_top"] , mbl_bin , mbl_min , mbl_max ) )
# cr_list.append( background_config.addChannel( "mll"   , ["CR_top"] , mll_bin , mll_min , mll_max ) )
#
# cr_list.append( background_config.addChannel( "mbl_0" , ["CR_tmp"] , mbl_bin , mbl_min , mbl_max ) )
# cr_list.append( background_config.addChannel( "mbl_1" , ["CR_tmp"] , mbl_bin , mbl_min , mbl_max ) )
# cr_list.append( background_config.addChannel( "mll"   , ["CR_tmp"] , mll_bin , mll_min , mll_max ) )

background_config.setBkgConstrainChannels(cr_list)

###############################
#                             #
#    Example new cosmetics    #
#                             #
###############################
# Set global plotting colors/styles
background_config.dataColor      = data_sample.color
background_config.totalPdfColor  = kBlue
background_config.errorFillColor = kBlue-5
background_config.errorFillStyle = 3004
background_config.errorLineStyle = kDashed
background_config.errorLineColor = kBlue-5

for crl in cr_list:
    crl.titleY = "Entries"
    crl.logY = True
    crl.ATLASLabelX = 0.25
    crl.ATLASLabelY = 0.85
    crl.ATLASLabelText = "Work in progress"

# ---------------------------------------------------------------
# - Validation regions - not necessarily statistically independent
# ---------------------------------------------------------------
vr_list = []
if do_validation:
    print 'Setting up validation regions!'
    vr_list.append( background_config.addChannel( 'mbl_0', ['VR'], mbl_bin, mbl_min, mbl_max ) )
    # vr_list.append( background_config.addChannel( 'mbl_1', ['VR'], mbl_bin, mbl_min, mbl_max ) )
    # vr_list.append( background_config.addChannel( 'mll'  , ['VR'], mll_bin, mll_min, mll_max ) )

    background_config.setValidationChannels( vr_list )

# ***************
# * Discovery fit
# ***************
if myFitType==FitType.Discovery:
    print 'ERROR!!! DISCOVERY FIT IS NOT YET CONFIGURED!!!'

    print 'Setting up discovery fit!'
    discovery_config = configMgr.addFitConfigClone(background_config,"Discovery")

    # s1l2jT = signal region/channel
    ssChannel = discovery_config.addChannel("cuts",["SR"],srNBins,srBinLow,srBinHigh)
    # ssChannel.addSystematic(jes)
    ssChannel.addDiscoverySamples(["SR"],[1.],[0.],[100.],[kMagenta])
    discovery_config.setSignalChannels([ssChannel])

# -------------------------------------------------------
# - Exclusion fits (1-step simplified model in this case)
# -------------------------------------------------------
if myFitType==FitType.Exclusion:
    print 'Setting up exclusion fit!'
    sigSamples=["sig_500"]
    sr_list = []
    for sig in sigSamples:
        exclusion_config = configMgr.addFitConfigClone(background_config,"Sig_%s"%sig)

        sigSample = Sample(sig,kViolet+5)
        sigSample.setFileList(sig_files)
        sigSample.setNormByTheory()
        sigSample.setStatConfig(use_stat)
        sigSample.setNormFactor("mu_SIG",1.,0.,5.)
        exclusion_config.addSamples(sigSample)
        exclusion_config.setSignalSample(sigSample)

        sr_list.append( exclusion_config.addChannel( "mbl_0", ["SR"], mbl_bin, mbl_min, mbl_max ) )
        # sr_list.append( exclusion_config.addChannel( "mbl_1", ["SR"], mbl_bin, mbl_min, mbl_max ) )

        exclusion_config.setSignalChannels(sr_list)

# ----------------
# - Create TLegend
# ----------------
# TCanvas is needed for that, but it gets deleted afterwards
c = TCanvas()
compFillStyle = 1001 # see ROOT for Fill styles
leg = TLegend(0.6,0.475,0.9,0.925,"")
leg.SetFillStyle(0)
leg.SetFillColor(0)
leg.SetBorderSize(0)

# Data entry
entry = TLegendEntry()
entry = leg.AddEntry("","Data 2012 (#sqrt{s}=8 TeV)","p")
entry.SetMarkerColor(background_config.dataColor)
entry.SetMarkerStyle(20)

# Total PDF
entry = leg.AddEntry("","Total pdf","lf")
entry.SetLineColor(background_config.totalPdfColor)
entry.SetLineWidth(2)
entry.SetFillColor(background_config.errorFillColor)
entry.SetFillStyle(background_config.errorFillStyle)

# ttbar entry
entry = leg.AddEntry("","t#bar{t}","lf")
entry.SetLineColor(ttbar_sample.color)
entry.SetFillColor(ttbar_sample.color)
entry.SetFillStyle(compFillStyle)

# Single top entry
entry = leg.AddEntry("","Single top","lf")
entry.SetLineColor(single_top_sample.color)
entry.SetFillColor(single_top_sample.color)
entry.SetFillStyle(compFillStyle)

# Z/gamma* entry
entry = leg.AddEntry("","Z/#gamma*","lf")
entry.SetLineColor(z_sample.color)
entry.SetFillColor(z_sample.color)
entry.SetFillStyle(compFillStyle)

# If exclusion mode, add signal entry
if myFitType==FitType.Exclusion:
    entry = leg.AddEntry("","signal","lf")
    entry.SetLineColor(kViolet+5)
    entry.SetFillColor(kViolet+5)
    entry.SetFillStyle(compFillStyle)

# Set legend for fitConfig
background_config.tLegend = leg
if myFitType==FitType.Exclusion:
    exclusion_config.tLegend = leg
c.Close()

print 'done with my stuff'
print '--------------------------------------------------------------------------------'
print ''
