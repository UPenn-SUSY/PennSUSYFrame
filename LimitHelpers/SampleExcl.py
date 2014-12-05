# =============================================================
# = In principle all you have to setup is defined in this file
# =============================================================
from configManager import configMgr
from ROOT import kBlack,kWhite,kGray,kRed,kPink,kMagenta,kViolet,kBlue,kAzure,kCyan,kTeal,kGreen,kSpring,kYellow,kOrange,kDashed,kSolid,kDotted
from configWriter import fitConfig,Measurement,Channel,Sample
from systematic import Systematic
from math import sqrt
import itertools

# Setup for ATLAS plotting
from ROOT import gROOT, TLegend, TLegendEntry, TCanvas
gROOT.LoadMacro("./macros/AtlasStyle.C")
import ROOT
ROOT.SetAtlasStyle()


# ------------------------------------------------------------------------------
# import functions to do scaling
import os
import sys
sys.path.append('%s/LimitHelpers/' % os.environ['BASE_WORK_DIR'])
import FlavorChannelScaling as scaling
import SampleExclBinning as binning


# ------------------------------------------------------------------------------
# Some flags for overridding normal execution and telling ROOT to shut up...
# - use with caution!
#gROOT.ProcessLine("gErrorIgnoreLevel=10001;")
#configMgr.plotHistos = True
configMgr.blindSR = True


# ------------------------------------------------------------------------------
# Flags to tune the stop branching ratios
if 'stop_br_e' not in vars(): stop_br_e = 0.5
if 'stop_br_m' not in vars(): stop_br_m = 0.5
if 'stop_br_t' not in vars(): stop_br_t = 0.0

print 'stop br e: ', stop_br_e
print 'stop br m: ', stop_br_m
print 'stop br t: ', stop_br_t

# ------------------------------------------------------------------------------
# Flags to control which fit is executed
use_stat = True
do_validation = False

print 'Analysis configurations:'
if myFitType == FitType.Exclusion:
    print '  fit type: Exclusion'
elif myFitType == FitType.Discovery:
    print '  fit type: Discovery'
elif myFitType == FitType.Background:
    print '  fit type: Background'
else:
    print '  fit type: Undefined :('


# ------------------------------------------------------------------------------
# cannot do validation and exclusion/discovery at the same time for now
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


# ------------------------------------------------------------------------------
# First, define HistFactory attributes
configMgr.analysisName = '_'.join(["SampleExcl",
                                   'bre', str(int(100*stop_br_e)),
                                   'brm', str(int(100*stop_br_m)),
                                   'brt', str(int(100*stop_br_t))])
configMgr.histCacheFile = "data/"+configMgr.analysisName+".root"
configMgr.outputFileName = "results/"+configMgr.analysisName+"_Output.root"

# Scaling calculated by outputLumi / inputLumi
configMgr.inputLumi = 0.001    # Luminosity of input TTree after weighting
configMgr.outputLumi = 21.0    # Luminosity required for output histograms
configMgr.setLumiUnits("fb-1")

# Set the files to read from
data_files = []
bkg_files = []
sig_files = []
if configMgr.readFromTree:
    print 'reading from trees!'
    data_files.append("${BASE_WORK_DIR}/HistFitterNtuples/BackgroundHistFitterTrees.root")
    # data_files.append("${BASE_WORK_DIR}/HistFitterNtuples/ArtificialData.ttbar_1.ZGamma_1.root")
    # data_files.append("${BASE_WORK_DIR}/HistFitterNtuples/ArtificialData.ttbar_5.ZGamma_1.root")
    bkg_files.append("${BASE_WORK_DIR}/HistFitterNtuples/BackgroundHistFitterTrees.root")
    if myFitType==FitType.Exclusion:
        sig_files.append("${BASE_WORK_DIR}/HistFitterNtuples/SignalHistFitterTrees.root")
else:
    print 'not reading from trees -- getting input from cache!'
    bkg_files = ["data/"+configMgr.analysisName+".root"]


# ------------------------------------
# - Dictionnary of cuts for Tree->hist
# ------------------------------------
# SR
base_sr_str = "is_sr"
configMgr.cutsDict["SR_ee"] = '(%s && is_ee)' % base_sr_str
configMgr.cutsDict["SR_mm"] = '(%s && is_mm)' % base_sr_str
configMgr.cutsDict["SR_em"] = '(%s && is_em)' % base_sr_str

# CR_top
base_cr_top_str = "is_cr_top"
configMgr.cutsDict["CR_top_all"] = base_cr_top_str
configMgr.cutsDict["CR_top_ee"] = '(%s && is_ee)' % base_cr_top_str
configMgr.cutsDict["CR_top_mm"] = '(%s && is_mm)' % base_cr_top_str
configMgr.cutsDict["CR_top_em"] = '(%s && is_em)' % base_cr_top_str

# CR_Z
# base_cr_z_str = "is_cr_z"
base_cr_z_str = "is_cr_z && (met_sig_signal <= 3)"
configMgr.cutsDict["CR_Z_all"] = base_cr_z_str
configMgr.cutsDict["CR_Z_ee"] = '(%s && is_ee)' % base_cr_z_str
configMgr.cutsDict["CR_Z_mm"] = '(%s && is_mm)' % base_cr_z_str

# VR 3
base_vr_3_str = "is_vr_3"
configMgr.cutsDict["VR_3_all"] = base_vr_3_str
configMgr.cutsDict["VR_3_ee"] = '(%s && is_ee)' % base_vr_3_str
configMgr.cutsDict["VR_3_mm"] = '(%s && is_mm)' % base_vr_3_str
configMgr.cutsDict["VR_3_em"] = '(%s && is_em)' % base_vr_3_str

# VR 5
base_vr_5_str = "is_vr_5"
configMgr.cutsDict["VR_5_all"] = base_vr_5_str
configMgr.cutsDict["VR_5_ee"] = '(%s && is_ee)' % base_vr_5_str
configMgr.cutsDict["VR_5_mm"] = '(%s && is_mm)' % base_vr_5_str


# ------------------------------------------------------------------------------
# Lists of nominal weights
flavor_scale_factors = scaling.getFlavorScaleFactorsFromBR(br_e=stop_br_e,
                                                           br_m=stop_br_m,
                                                           br_t=stop_br_t)
nominal_weight_bkg = 'weight'
nominal_weight_sig = ''.join([nominal_weight_bkg,
                              '*(  (is_ee*', str(flavor_scale_factors['ee']),
                              ') + (is_mm*', str(flavor_scale_factors['mm']),
                              ') + (is_em*', str(flavor_scale_factors['em']),
                              ') )'])

# apply nominal weight to all samples
configMgr.weights = [nominal_weight_bkg]

# name of nominal histogram for systematics
configMgr.nomName = "_NoSys"


# ------------------------------------------------------------------------------
# List of systematics
jes_uncert = Systematic(name = "JES",
                        nominal = '_NoSys',
                        high = '_JES_UP',
                        low = '_JES_DOWN',
                        type = 'tree',
                        method = 'overallSys')
jer_uncert = Systematic(name = 'JER',
                        nominal = '_NoSys',
                        high = '_JER',
                        low = '_JER',
                        type = 'tree',
                        method = 'normHistoSysOneSide')

btag_sf_uncert_bkg = Systematic(name = 'btag_sf_bkg',
                                nominal = nominal_weight_bkg,
                                high = [nominal_weight_bkg, 'btag_sf_down_frac'],
                                low = [nominal_weight_bkg, 'btag_sf_up_frac'],
                                type = 'weight',
                                method = 'overallSys')
btag_sf_uncert_sig = Systematic(name = 'btag_sf_sig',
                                nominal = nominal_weight_sig,
                                high = [nominal_weight_sig, 'btag_sf_down_frac'],
                                low = [nominal_weight_sig, 'btag_sf_up_frac'],
                                type = 'weight',
                                method = 'overallSys')


# --------------------------------------------
# - List of samples and their plotting colours
# --------------------------------------------
sample_list_bkg  = []
sample_list_data = []
sample_list_sig  = []

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# Other
other_sample = Sample("Other", kAzure+8)
other_sample.setStatConfig(use_stat)
other_sample.setNormByTheory()
sample_list_bkg.append(other_sample)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# single top
single_top_sample = Sample("SingleTop", kGreen-1)

single_top_sample.setStatConfig(use_stat)
single_top_sample.setNormByTheory()
sample_list_bkg.append(single_top_sample)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# Z/gamma*
z_sample = Sample("ZGamma", kRed+1 )

z_sample.setNormFactor("mu_z", 1, 0, 100)
z_sample.setStatConfig(use_stat)
sample_list_bkg.append(z_sample)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# ttbar
ttbar_sample = Sample("ttbar", kGreen+2)

ttbar_sample.setNormFactor("mu_ttbar", 1, 0, 100)
ttbar_sample.setStatConfig(use_stat)
sample_list_bkg.append(ttbar_sample)

### # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
### # ttV
### ttv_sample = Sample("ttV", kAzure+8)
### 
### ttv_sample.setStatConfig(use_stat)
### ttv_sample.setNormByTheory()
### sample_list_bkg.append(ttv_sample)
### 
### # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
### # diboson
### diboson_sample = Sample("Diboson", kSpring-4)
### 
### diboson_sample.setStatConfig(use_stat)
### diboson_sample.setNormByTheory()
### sample_list_bkg.append(diboson_sample)
### 
### # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
### # higgs
### higgs_sample = Sample("Higgs", kOrange-5)
### 
### higgs_sample.setStatConfig(use_stat)
### higgs_sample.setNormByTheory()
### sample_list_bkg.append(higgs_sample)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# data
data_sample = Sample("data",kBlack)
data_sample.setData()
sample_list_data.append(data_sample)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# set the file from which the samples should be taken
# for sl in itertools.chain(sample_list_bkg, sample_list_data):
for sl in sample_list_bkg:
    sl.setFileList(bkg_files)

for sl in sample_list_data:
    sl.setFileList(data_files)


# ------------------------------------------------------------------------------
# add systematics to each of the samples
def addSystematic(sample_list, syst_list):
    for sample in sample_list:
        for syst in syst_list:
            sample.addSystematic(syst)

# background systematics
addSystematic(sample_list_bkg,
              [btag_sf_uncert_bkg,
               jes_uncert,
               jer_uncert])


# ------------------------------------------------------------------------------
# Configure the background only fit
background_config = configMgr.addFitConfig("BkgOnly")
if use_stat:
    background_config.statErrThreshold = 0.05
else:
    background_config.statErrThreshold = None
background_config.addSamples(sample_list_bkg)
background_config.addSamples(sample_list_data)

meas = background_config.addMeasurement(name = "NormalMeasurement",
                                        lumi = 1.0,
                                        lumiErr = 0.039)
meas.addPOI("mu_SIG")


# ------------------------------------------------------------------------------
def addChannel(config, expression, name, binning):
    """
    Helper function to add a channel to the fit config - this is just a wrapper
    around the HistFitter addChannel function
    """
    return config.addChannel(expression,
                             [name],
                             binning['bin'],
                             binning['min'],
                             binning['max'])


# ------------------------------------------------------------------------------
# - Constraining regions - statistically independent
cr_list = []
# Add Top CR for background
for cr_name in ['CR_top_', 'CR_Z_']:
    for flavor_channel in ['all']:
    # for flavor_channel in ['ee', 'mm', 'em']:
        if cr_name  == 'CR_Z_' and flavor_channel == 'em': continue

        this_name = ''.join([cr_name, flavor_channel])

        cr_list.append(addChannel(background_config,
                                  'mbl_0',
                                  this_name,
                                  binning.mbl))

background_config.setBkgConstrainChannels(cr_list)


# ------------------------------------------------------------------------------
# Background only fit cosmetics
# Global plotting colors/styles
background_config.dataColor      = data_sample.color
background_config.totalPdfColor  = kBlue
background_config.errorFillColor = kBlue-5
background_config.errorFillStyle = 3004
background_config.errorLineStyle = kDashed
background_config.errorLineColor = kBlue-5

for crl in cr_list:
    crl.useOverflowBin = True
    crl.titleY = "Entries"
    crl.logY = True
    crl.ATLASLabelX = 0.25
    crl.ATLASLabelY = 0.85
    crl.ATLASLabelText = "Work in progress"


# ______________________________________________________________________________
# Construct Validation regions
vr_list = []
if do_validation:
    print 'Setting up validation regions!'
    for vr_name in ['VR_3', 'VR_5']:
        for flavor_channel in ['_all', '_ee', '_mm', '_em']:
            if not vr_name == 'VR_llbb' and flavor_channel == '': continue
            if vr_name  == 'VR_5' and flavor_channel == '_em': continue

            # unique name for this VR/flavor channel combination
            this_vr_name = ''.join([vr_name, flavor_channel])

            # add VR plots
            if flavor_channel == '_all':
                vr_list.append(addChannel(background_config,
                                          'flavor_channel',
                                          this_vr_name,
                                          binning.flavor_channel))

            vr_list.append(addChannel(background_config,
                                      'mbl_0',
                                      this_vr_name,
                                      binning.mbl))
            vr_list.append(addChannel(background_config,
                                      'mbl_1',
                                      this_vr_name,
                                      binning.mbl))
            vr_list.append(addChannel(background_config,
                                      'ht_signal',
                                      this_vr_name,
                                      binning.ht))

    for vr_name in ['CR_top_', 'CR_Z_']:
        for flavor_channel in ['all', 'ee', 'mm', 'em']:
            if vr_name  == 'CR_Z_' and flavor_channel == 'em': continue

            # unique name for this VR/flavor channel combination
            this_vr_name = ''.join([vr_name, flavor_channel])

            # add VR plots
            if flavor_channel == 'all':
                vr_list.append(addChannel(background_config,
                                          'flavor_channel',
                                          this_vr_name,
                                          binning.flavor_channel))

            if not flavor_channel == 'all':
            # if flavor_channel == 'all':
                vr_list.append(addChannel(background_config,
                                          'mbl_0',
                                          this_vr_name,
                                          binning.mbl))
            vr_list.append(addChannel(background_config,
                                      'mbl_1',
                                      this_vr_name,
                                      binning.mbl))
            vr_list.append(addChannel(background_config,
                                      'ht_signal',
                                      this_vr_name,
                                      binning.ht))

    # turn on overflow bin for all VR plots
    for vr in vr_list:
        vr.useOverflowBin = True

    background_config.setValidationChannels(vr_list)


# ------------------------------------------------------------------------------
# set up SRs
if not myFitType == FitType.Discovery:
    sr_list = []
    for flavor_channel in ['ee', 'mm', 'em']:
        this_sr_name = ''.join(("SR_", flavor_channel))
        print 'this sr name: ', this_sr_name
        sr_list.append(addChannel(background_config,
                                  "mbl_0",
                                  this_sr_name,
                                  binning.mbl))

    for sr in sr_list:
        sr.useUnderflowBin = True
        sr.useOverflowBin  = True
        sr.titleY = "Entries"
        sr.logY = True
        sr.ATLASLabelX = 0.25
        sr.ATLASLabelY = 0.85
        sr.ATLASLabelText = "Work in progress"

    if myFitType == FitType.Exclusion:
        background_config.setSignalChannels(sr_list)
    else:
        background_config.setValidationChannels(sr_list)


# ------------------------------------------------------------------------------
# Configure discovery fit
if myFitType == FitType.Discovery:
    print 'ERROR!!! DISCOVERY FIT IS NOT YET CONFIGURED!!!'


# ------------------------------------------------------------------------------
# Configure exclusion fits
if myFitType == FitType.Exclusion:
    print 'Setting up exclusion fit!'
    sig_sample_list=['sig_100', 'sig_200', 'sig_300', 'sig_400', 'sig_500',
                     'sig_600', 'sig_700', 'sig_800', 'sig_900', 'sig_1000']
    # sig_sample_list=['sig_1000']
    sig_samples = []
    for sig in sig_sample_list:
        print 'setting up signal sample: ', sig
        exclusion_sr_config = configMgr.addFitConfigClone(background_config,
                                                          "Sig_excl_%s" % sig)

        sig_sample = Sample(sig, kViolet+5)
        sig_sample.setStatConfig(use_stat)
        sig_sample.setFileList(sig_files)
        sig_sample.setNormByTheory()
        sig_sample.setNormFactor("mu_SIG", 1., 0., 5.)

        sig_sample.weights = [nominal_weight_sig]

        addSystematic([sig_sample],
                      [btag_sf_uncert_sig,
                       jes_uncert,
                       jer_uncert])

        exclusion_sr_config.addSamples(sig_sample)
        exclusion_sr_config.setSignalSample(sig_sample)


# ------------------------------------------------------------------------------
# Create TLegend for our plots
# TCanvas is needed for this, but it gets deleted afterwards
c = TCanvas()
compFillStyle = 1001 # see ROOT for Fill styles
leg = TLegend(0.6, 0.475, 0.9, 0.925, "")
leg.SetFillStyle(0)
leg.SetFillColor(0)
leg.SetBorderSize(0)

# Data entry
entry = TLegendEntry()
entry = leg.AddEntry("", "Data 2012 (#sqrt{s}=8 TeV)", "p")
entry.SetMarkerColor(background_config.dataColor)
entry.SetMarkerStyle(20)

# Total PDF
entry = leg.AddEntry("", "Total pdf", "lf")
entry.SetLineColor(background_config.totalPdfColor)
entry.SetLineWidth(2)
entry.SetFillColor(background_config.errorFillColor)
entry.SetFillStyle(background_config.errorFillStyle)

# ttbar entry
entry = leg.AddEntry("", "t#bar{t}", "lf")
entry.SetLineColor(ttbar_sample.color)
entry.SetFillColor(ttbar_sample.color)
entry.SetFillStyle(compFillStyle)

# Z/gamma* entry
entry = leg.AddEntry("", "Z/#gamma*", "lf")
entry.SetLineColor(z_sample.color)
entry.SetFillColor(z_sample.color)
entry.SetFillStyle(compFillStyle)

# Single top entry
entry = leg.AddEntry("", "Single top", "lf")
entry.SetLineColor(single_top_sample.color)
entry.SetFillColor(single_top_sample.color)
entry.SetFillStyle(compFillStyle)

# Other background entry
entry = leg.AddEntry("", "Other", "lf")
entry.SetLineColor(other_sample.color)
entry.SetFillColor(other_sample.color)
entry.SetFillStyle(compFillStyle)

### # ttV entry
### entry = leg.AddEntry("", "ttV", "lf")
### entry.SetLineColor(ttv_sample.color)
### entry.SetFillColor(ttv_sample.color)
### entry.SetFillStyle(compFillStyle)
###
### # Diboson entry
### entry = leg.AddEntry("", "Diboson", "lf")
### entry.SetLineColor(diboson_sample.color)
### entry.SetFillColor(diboson_sample.color)
### entry.SetFillStyle(compFillStyle)
###
### # Higgs entry
### entry = leg.AddEntry("", "Higgs", "lf")
### entry.SetLineColor(higgs_sample.color)
### entry.SetFillColor(higgs_sample.color)
### entry.SetFillStyle(compFillStyle)

# If exclusion mode, add signal entry
if myFitType==FitType.Exclusion:
    entry = leg.AddEntry("", "signal", "lf")
    entry.SetLineColor(kViolet+5)
    entry.SetFillColor(kViolet+5)
    entry.SetFillStyle(compFillStyle)

# Set legend for fitConfig
background_config.tLegend = leg
if myFitType==FitType.Exclusion:
    exclusion_sr_config.tLegend = leg
c.Close()

print 'done with my stuff'
print '--------------------------------------------------------------------------------'
print ''
