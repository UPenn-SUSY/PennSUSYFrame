# =============================================================
# = In principle all you have to setup is defined in this file
# =============================================================
from configManager import configMgr
from ROOT import kBlack,kWhite,kGray,kRed,kPink,kMagenta,kViolet,kBlue,kAzure,kCyan,kTeal,kGreen,kSpring,kYellow,kOrange,kDashed,kSolid,kDotted
from configWriter import fitConfig,Measurement,Channel,Sample
from systematic import Systematic
from math import sqrt
import itertools
import sys

from BLStop_theoryUncertainties import *

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
if 'is_blind' not in vars(): is_blind = False
configMgr.blindSR = is_blind

# ------------------------------------------------------------------------------
# Flags to tune the stop branching ratios
if 'test_sr' not in vars(): test_sr = 'sr_ht_1100_mbl_400'
# if 'test_sr' not in vars(): test_sr = 'sr_ht_1100_mbl_600'
if 'flavor_channel' not in vars(): flavor_channel = 'all'

print 'signal region: ', test_sr
print 'is blind: ', is_blind

# ------------------------------------------------------------------------------
# Flags to control which fit is executed
use_stat = True
do_validation = True

print 'Analysis configurations:'
if myFitType == FitType.Exclusion:
    print '  fit type: Exclusion'
else:
    print '  Switching to Exclusion'
    myFitType = FitType.Exclusion

# ------------------------------------------------------------------------------
# cannot do validation and exclusion/discovery at the same time for now
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
# construct the analysis name
analysis_name = ['ModelIndependentExcl']
analysis_name.append(test_sr)
analysis_name.append(flavor_channel)
analysis_name.append('blind' if is_blind else 'unblind')

# Define HistFactory attributes
configMgr.analysisName = '_'.join(analysis_name)
configMgr.histCacheFile = "data/"+configMgr.analysisName+".root"
configMgr.outputFileName = "results/"+configMgr.analysisName+"_Output.root"

# Scaling calculated by outputLumi / inputLumi
configMgr.inputLumi = 0.001    # Luminosity of input TTree after weighting
configMgr.outputLumi = 20.3    # Luminosity required for output histograms
configMgr.setLumiUnits("fb-1")

# Set the files to read from
data_files = []
bkg_files = []
sig_files = []
print 'reading from trees!'
data_files.append("${BASE_WORK_DIR}/HistFitterNtuples/BackgroundHistFitterTrees.root")
bkg_files.append("${BASE_WORK_DIR}/HistFitterNtuples/BackgroundHistFitterTrees.root")
sig_files.append("${BASE_WORK_DIR}/HistFitterNtuples/FakeSignal.root")


# ------------------------------------
# - Dictionary of cuts for Tree->hist
# ------------------------------------
# SR
base_sr_str = '_'.join(["is", test_sr])
if flavor_channel == 'ee':
    configMgr.cutsDict["SR"]  = '(%s && is_ee)' % base_sr_str
elif flavor_channel == 'mm':
    configMgr.cutsDict["SR"]  = '(%s && is_mm)' % base_sr_str
elif flavor_channel == 'em':
    configMgr.cutsDict["SR"]  = '(%s && is_em)' % base_sr_str
else:
    configMgr.cutsDict["SR"] = '(%s)' %base_sr_str

# CR_top
base_cr_top_str = "is_cr_top_mbl_200"
configMgr.cutsDict["CR_top_all"] = base_cr_top_str

# CR_Z
base_cr_z_str = "is_cr_z_mbl_200"
configMgr.cutsDict["CR_Z_all"] = base_cr_z_str

print '-'*80
print 'configMgr.cutDict:'
print configMgr.cutsDict

# ------------------------------------------------------------------------------
# Lists of nominal weights
nominal_weight_bkg = 'weight'

# apply nominal weight to all samples
configMgr.weights = [nominal_weight_bkg]

# name of nominal histogram for systematics
configMgr.nomName = "_NoSys"

# ------------------------------------------------------------------------------
# List of systematics
jes_uncert_names = ['EFFECTIVE_NP_1',
                    'EFFECTIVE_NP_2',
                    'EFFECTIVE_NP_3',
                    'EFFECTIVE_NP_4',
                    'EFFECTIVE_NP_5',
                    'EFFECTIVE_NP_6',
                    'ETA_INTERCALIBRATION_MODELLING',
                    'ETA_INTERCALIBRATION_STATAND_METHOD',
                    'SINGLE_PARTICLE_HIGH_PT',
                    'PILE_UP_OFFSET_TERM_MU',
                    'PILE_UP_OFFSET_TERM_NPV',
                    'PILE_UP_PT_TERM',
                    'PILE_UP_RHO_TOPOLOGY',
                    'FLAVOR_COMP_UNCERT',
                    'FLAVOR_RESPONSE_UNCERT',
                    'BJES']

jes_uncert_list = [Systematic(name = syst,
                              nominal = '_NoSys',
                              high = ''.join(['_', syst, '_UP']),
                              low = ''.join(['_', syst, '_DOWN']),
                              type = 'tree',
                              method = 'overallSys') for syst in jes_uncert_names]

jer_uncert = Systematic(name = 'JER',
                        nominal = '_NoSys',
                        high = '_JER',
                        low = '_JER',
                        type = 'tree',
                        method = 'normHistoSysOneSide')

btag_sf_uncert_names = ['btag_sf_b', 'btag_sf_c', 'btag_sf_l']
btag_sf_uncert_bkg_list = [Systematic(name = '_'.join([syst, 'bkg']),
                                      nominal = nominal_weight_bkg,
                                      high = [nominal_weight_bkg, '_'.join([syst, 'up', 'frac'])],
                                      low = [nominal_weight_bkg, '_'.join([syst, 'down', 'frac'])],
                                      type = 'weight',
                                      method = 'overallSys')
                           for syst in btag_sf_uncert_names]

# --------------------------------------------
# - Cross section systematics to apply
# --------------------------------------------
ttbar_xsec_uncert = Systematic(name = 'ttbar_xsec_uncert',
                               nominal = nominal_weight_bkg,
                               high = [nominal_weight_bkg, str((1+15.30/252.89))],
                               low  = [nominal_weight_bkg, str((1-16.12/252.89))],
                               type = 'weight',
                               method = 'overallSys')

single_top_xsec_uncert = Systematic(name = 'single_top_xsec_uncert',
                                    nominal = nominal_weight_bkg,
                                    high = [nominal_weight_bkg, str((1+1.52/22.37))],
                                    low  = [nominal_weight_bkg, str((1-1.52/22.37))],
                                    type = 'weight',
                                    method = 'overallSys')

# --------------------------------------------
# - Theory systematics to apply
# --------------------------------------------
theory_uncert_adder = uncertaintyAdder(configMgr.weights)

# --------------------------------------------
# - Additional systematics to apply
# --------------------------------------------
ht_extrapolation_uncert = Systematic(name = 'ht_etrapolation',
                                     nominal = nominal_weight_bkg,
                                     high = [nominal_weight_bkg, '(1+0.5*(ht_signal>500))'],
                                     low  = [nominal_weight_bkg, '(1-0.5*(ht_signal>500))'],
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
              (btag_sf_uncert_bkg_list +
               jes_uncert_list +
               [jer_uncert]))
               # [jer_uncert, ht_extrapolation_uncert]))
addSystematic([z_sample], ([ht_extrapolation_uncert]))
addSystematic([ttbar_sample], ([ttbar_xsec_uncert]))
addSystematic([single_top_sample], ([single_top_xsec_uncert]))

theory_uncert = {}
theory_uncert['CR_top'] = theory_uncert_adder.getUncertainties('CR_TOP')
theory_uncert['CR_Z']   = theory_uncert_adder.getUncertainties('CR_Z')

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
def addChannel(config, expression, name, the_binning):
    """
    Helper function to add a channel to the fit config - this is just a wrapper
    around the HistFitter addChannel function
    """
    return config.addChannel(expression,
                             [name],
                             the_binning['bin'],
                             the_binning['min'],
                             the_binning['max'])


# ------------------------------------------------------------------------------
# - Constraining regions - statistically independent
cr_list = []
# Add Top CR for background
for cr_name in ['CR_top_', 'CR_Z_']:
    flavor_channel = 'all'
    this_name = ''.join([cr_name, flavor_channel])
    cr_list.append(addChannel(background_config,
                                '0.5',
                                this_name,
                                binning.get_binning('default',
                                                    single_bin=binning.single_bin_regions)))

    # add theory systematics!
    # this is pretty ugly :-(
    if   'CR_top' in cr_name: syst_region = 'CR_top'
    elif 'CR_Z' in cr_name:   syst_region = 'CR_Z'
    else:                     continue

    this_theort_uncert_dict = theory_uncert[syst_region]
    for sample in this_theort_uncert_dict:
        if   sample == 'Top': this_sample = 'ttbar'
        elif sample == 'ST':  this_sample = 'SingleTop'
        elif sample == 'ZX':  this_sample = 'ZGamma'
        else:                 continue

        for systematic in this_theort_uncert_dict[sample]:
            cr_list[-1].getSample(this_sample).addSystematic(systematic)

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
    crl.logY = False
    crl.showLumi = True
    crl.ATLASLabelX = 0.25
    crl.ATLASLabelY = 0.85
    crl.ATLASLabelText = "Internal"

# ------------------------------------------------------------------------------
# set up SRs
sr_list = []
for region_name in configMgr.cutsDict.keys():
    if 'SR' not in region_name:
        continue

    print 'this sr name: ', region_name
    sr_list.append(addChannel(background_config,
                              "0.5",
                              region_name,
                              binning.get_binning('default',
                                                  single_bin=binning.single_bin_regions)))
background_config.setSignalChannels(sr_list)

# ------------------------------------------------------------------------------
# Configure exclusion fits
print 'Setting up exclusion fit!'

exclusion_sr_config = configMgr.addFitConfigClone(background_config, "Sig_excl")
for region_name in configMgr.cutsDict.keys():
    if 'SR' not in region_name:
        continue

    print 'this sr name: ', region_name

    sig_sample = Sample('fake_signal', kViolet+5)
    sig_sample.setNormFactor('mu_SIG', 1, 0, 10)

    sig_sample.buildHisto([1], region_name, '0.5')

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

# If exclusion mode, add signal entry
entry = leg.AddEntry("", "signal", "lf")
entry.SetLineColor(kViolet+5)
entry.SetFillColor(kViolet+5)
entry.SetFillStyle(compFillStyle)

# Set legend for fitConfig
background_config.tLegend = leg
# exclusion_sr_config.tLegend = leg
c.Close()

print 'done with my stuff'
print '--------------------------------------------------------------------------------'
print ''

