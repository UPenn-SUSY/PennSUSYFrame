# =============================================================
# = In principle all you have to setup is defined in this file
# =============================================================
from configManager import configMgr
from ROOT import kBlack,kWhite,kGray,kRed,kPink,kMagenta,kViolet,kBlue,kAzure,kCyan,kTeal,kGreen,kSpring,kYellow,kOrange,kDashed,kSolid,kDotted
from configWriter import fitConfig,Measurement,Channel,Sample
from systematic import Systematic
from math import sqrt
import itertools

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
if 'stop_br_e' not in vars(): stop_br_e = 0.5
if 'stop_br_m' not in vars(): stop_br_m = 0.5
if 'stop_br_t' not in vars(): stop_br_t = 0.0
if 'test_sr' not in vars(): test_sr = 'sr_ht_1100_mbl_400'
# if 'sig_xsec_variation' not in vars(): sig_xsec_variation = 'nominal'

print 'stop br e: ', stop_br_e
print 'stop br m: ', stop_br_m
print 'stop br t: ', stop_br_t
print 'signal region: ', test_sr
print 'is blind: ', is_blind

# ------------------------------------------------------------------------------
# Flags to control which fit is executed
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

# ------------------------------------------------------------------------------
# cannot do validation and exclusion/discovery at the same time for now
if myFitType == FitType.Discovery or myFitType == FitType.Exclusion:
    print 'turning off validation for discovery or exclusion'
    do_validation = False

# ------------------------------------------------------------------------------
# if this is a background only fit, force binned SR
if myFitType == FitType.Background:
    binning.single_bin_signal = False

# --------------------------------
# - Parameters for hypothesis test
# --------------------------------
#configMgr.doHypoTest=False
configMgr.nTOYs=10000
configMgr.calculatorType=2 # use 2 for asymptotic, 0 for toys
configMgr.testStatType=3
configMgr.nPoints=10

# do we scale the signal cross section up/down
configMgr.fixSigXSec = True  # fix SigXSec: 0, +/-1sigma
if myFitType == FitType.Background:
    configMgr.fixSigXSec = False

# ------------------------------------------------------------------------------
# construct the analysis name
analysis_name = []
if myFitType == FitType.Background:
    analysis_name.append('SampleBkg')
elif myFitType == FitType.Exclusion:
    analysis_name.append("SampleExcl")
elif myFitType == FitType.Discovery:
    analysis_name.append("SampleDisc")

analysis_name.extend(['bre', str(int(100*stop_br_e)),
                      'brm', str(int(100*stop_br_m)),
                      'brt', str(int(100*stop_br_t))])
if myFitType == FitType.Exclusion:
    analysis_name.append(test_sr)
analysis_name.append('blind' if is_blind else 'unblind')

# Define HistFactory attributes
configMgr.analysisName = '_'.join(analysis_name)
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
    # the below samples are artificial data for validation purposes
    # data_files.append("${BASE_WORK_DIR}/HistFitterNtuples/ArtificialData.ttbar_1.ZGamma_1.root")
    # data_files.append("${BASE_WORK_DIR}/HistFitterNtuples/ArtificialData.ttbar_5.ZGamma_1.root")
    bkg_files.append("${BASE_WORK_DIR}/HistFitterNtuples/BackgroundHistFitterTrees.root")
    if myFitType == FitType.Exclusion:
        sig_files.append("${BASE_WORK_DIR}/HistFitterNtuples/SignalHistFitterTrees.root")
else:
    print 'not reading from trees -- getting input from cache!'
    bkg_files = ["data/"+configMgr.analysisName+".root"]


# ------------------------------------
# - Dictionnary of cuts for Tree->hist
# ------------------------------------
if myFitType == FitType.Background:
    for sr_label in ['ht_1100_mbl_400', 'ht_1100_mbl_600']:
        base_sr_str = '_'.join(['is_sr', sr_label])
        configMgr.cutsDict['_'.join(["SR", sr_label, "all"])] = '(%s)' % base_sr_str
        configMgr.cutsDict['_'.join(["SR", sr_label, "ee"])]  = '(%s && is_ee)' % base_sr_str
        configMgr.cutsDict['_'.join(["SR", sr_label, "mm"])]  = '(%s && is_mm)' % base_sr_str
        configMgr.cutsDict['_'.join(["SR", sr_label, "em"])]  = '(%s && is_em)' % base_sr_str

# SR
if myFitType == FitType.Exclusion:
    base_sr_str = '_'.join(["is", test_sr])
    # configMgr.cutsDict["SR_all"] = '(%s)' % base_sr_str
    configMgr.cutsDict["SR_ee"] = '(%s && is_ee)' % base_sr_str
    configMgr.cutsDict["SR_mm"] = '(%s && is_mm)' % base_sr_str
    configMgr.cutsDict["SR_em"] = '(%s && is_em)' % base_sr_str

# CR_top
# base_cr_top_str = "is_cr_top"
base_cr_top_str = "is_cr_top_mbl_200"
configMgr.cutsDict["CR_top_all"] = base_cr_top_str
configMgr.cutsDict["CR_top_ee"] = '(%s && is_ee)' % base_cr_top_str
configMgr.cutsDict["CR_top_mm"] = '(%s && is_mm)' % base_cr_top_str
configMgr.cutsDict["CR_top_em"] = '(%s && is_em)' % base_cr_top_str

# CR_Z
# base_cr_z_str = "is_cr_z"
base_cr_z_str = "is_cr_z_mbl_200"
# base_cr_z_str = "is_cr_z && (met_sig_signal <= 3)"
configMgr.cutsDict["CR_Z_all"] = base_cr_z_str
configMgr.cutsDict["CR_Z_ee"] = '(%s && is_ee)' % base_cr_z_str
configMgr.cutsDict["CR_Z_mm"] = '(%s && is_mm)' % base_cr_z_str

# VR top 1
# base_vr_top_1_str = "is_vr_top_1"
base_vr_top_1_str = "is_vr_top_mbl_200_1"
configMgr.cutsDict["VR_top_1_all"] = base_vr_top_1_str
configMgr.cutsDict["VR_top_1_ee"] = '(%s && is_ee)' % base_vr_top_1_str
configMgr.cutsDict["VR_top_1_mm"] = '(%s && is_mm)' % base_vr_top_1_str
configMgr.cutsDict["VR_top_1_em"] = '(%s && is_em)' % base_vr_top_1_str

print '-'*80
print 'configMgr.cutDict:'
print configMgr.cutsDict

# VR top 2
# base_vr_top_2_str = "is_vr_top_2"
base_vr_top_2_str = "is_vr_top_mbl_200_2"
configMgr.cutsDict["VR_top_2_all"] = base_vr_top_2_str
configMgr.cutsDict["VR_top_2_ee"] = '(%s && is_ee)' % base_vr_top_2_str
configMgr.cutsDict["VR_top_2_mm"] = '(%s && is_mm)' % base_vr_top_2_str
configMgr.cutsDict["VR_top_2_em"] = '(%s && is_em)' % base_vr_top_2_str

# VR top 3
# base_vr_top_3_str = "is_vr_top_3"
base_vr_top_3_str = "is_vr_top_mbl_200_3"
configMgr.cutsDict["VR_top_3_all"] = base_vr_top_3_str
configMgr.cutsDict["VR_top_3_ee"] = '(%s && is_ee)' % base_vr_top_3_str
configMgr.cutsDict["VR_top_3_mm"] = '(%s && is_mm)' % base_vr_top_3_str
configMgr.cutsDict["VR_top_3_em"] = '(%s && is_em)' % base_vr_top_3_str

# VR Z
# base_vr_z_str = "is_vr_z"
base_vr_z_str = "is_vr_z_mbl_200"
configMgr.cutsDict["VR_Z_all"] = base_vr_z_str
configMgr.cutsDict["VR_Z_ee"] = '(%s && is_ee)' % base_vr_z_str
configMgr.cutsDict["VR_Z_mm"] = '(%s && is_mm)' % base_vr_z_str


# ------------------------------------------------------------------------------
# Lists of nominal weights
flavor_scale_factors = scaling.getFlavorScaleFactorsFromBR(br_e=stop_br_e,
                                                           br_m=stop_br_m,
                                                           br_t=stop_br_t)
nominal_weight_bkg = 'weight'
nominal_weight_sig = '{:s}*( (is_ee*{:f}) + (is_mm*{:f}) +(is_em*{:f}) )'
nominal_weight_sig = nominal_weight_sig.format(nominal_weight_bkg,
                                               flavor_scale_factors['ee'],
                                               flavor_scale_factors['mm'],
                                               flavor_scale_factors['em'])

# apply nominal weight to all samples
configMgr.weights = [nominal_weight_bkg]

# name of nominal histogram for systematics
configMgr.nomName = "_NoSys"


# ------------------------------------------------------------------------------
# List of systematics
# jes_uncert_names = ['JES']
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
btag_sf_uncert_sig_list = [Systematic(name = '_'.join([syst, 'sig']),
                                      nominal = nominal_weight_sig,
                                      high = [nominal_weight_sig, '_'.join([syst, 'up', 'frac'])],
                                      low = [nominal_weight_sig, '_'.join([syst, 'down', 'frac'])],
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
# - Signal cross section uncertainty
# --------------------------------------------
signal_xsec_rel_uncert = {'sig_100':0.161085,
                          'sig_200':0.149147,
                          'sig_300':0.146905,
                          'sig_400':0.142848,
                          'sig_500':0.149611,
                          'sig_600':0.166406,
                          'sig_700':0.184146,
                          'sig_800':0.20516,
                          'sig_900':0.239439,
                          'sig_1000':0.276595,
                          'sig_1100':0.318291}
# signal_xsec_uncert = {sig_name:Systematic(name = '_'.join(['signal_xsec',sig_name]),
#                                           nominal=nominal_weight_sig,
#                                           high=[nominal_weight_sig,
#                                                 ''.join(['(1+',
#                                                          str(signal_xsec_rel_uncert[sig_name]),
#                                                          ')'])],
#                                           low=[nominal_weight_sig,
#                                                ''.join(['(1-',
#                                                         str(signal_xsec_rel_uncert[sig_name]),
#                                                         ')'])],
#                                           type='weight',
#                                           method='overallSys')
#                       for sig_name in signal_xsec_rel_uncert.keys()}

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
              (btag_sf_uncert_bkg_list +
               jes_uncert_list +
               [jer_uncert]))
               # [jer_uncert, ht_extrapolation_uncert]))
addSystematic([z_sample], ([ht_extrapolation_uncert]))
addSystematic([ttbar_sample], ([ttbar_xsec_uncert]))
addSystematic([single_top_sample], ([single_top_xsec_uncert]))

theory_uncert = {}
theory_uncert['CR_top']   = theory_uncert_adder.getUncertainties('CR_TOP')
theory_uncert['CR_Z']     = theory_uncert_adder.getUncertainties('CR_Z')
theory_uncert['VR_top_1'] = theory_uncert_adder.getUncertainties('VR_TOP_1')
theory_uncert['VR_top_2'] = theory_uncert_adder.getUncertainties('VR_TOP_2')
theory_uncert['VR_top_3'] = theory_uncert_adder.getUncertainties('VR_TOP_3')
theory_uncert['VR_Z']     = theory_uncert_adder.getUncertainties('VR_Z')
theory_uncert['SR_400']   = theory_uncert_adder.getUncertainties('SR_400')
theory_uncert['SR_600']   = theory_uncert_adder.getUncertainties('SR_600')

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
    for flavor_channel in ['all']:
    # for flavor_channel in ['ee', 'mm', 'em']:
        if cr_name  == 'CR_Z_' and flavor_channel == 'em': continue

        this_name = ''.join([cr_name, flavor_channel])

        cr_list.append(addChannel(background_config,
                                  'mbl_0',
                                  this_name,
                                  binning.get_binning('mbl',
                                                      single_bin=binning.single_bin_regions)))
        cr_list[-1].titleX = 'm_{bl}^{0} [GeV]'
        cr_list[-1].logY = False

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
    crl.ATLASLabelX = 0.25
    crl.ATLASLabelY = 0.85
    crl.ATLASLabelText = "Work in progress"

# ______________________________________________________________________________
# Construct Validation regions
vr_list = []
if do_validation:
    print 'Setting up validation regions!'

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    for vr_name in ['VR_top_1', 'VR_top_2', 'VR_top_3', 'VR_Z']:
        for flavor_channel in ['_all', '_ee', '_mm', '_em']:
            if vr_name  == 'VR_Z' and flavor_channel == '_em': continue

            # unique name for this VR/flavor channel combination
            this_vr_name = ''.join([vr_name, flavor_channel])

            # add VR plots
            if flavor_channel == '_all':
                vr_list.append(addChannel(background_config,
                                          'flavor_channel',
                                          this_vr_name,
                                          binning.get_binning('flavor_channel',
                                                              single_bin=False)))
                vr_list[-1].titleX = 'Flavor Channel'

            vr_list.append(addChannel(background_config,
                                      'mbl_0',
                                      this_vr_name,
                                      binning.get_binning('mbl',
                                                          single_bin=False)))
            vr_list[-1].titleX = 'm_{bl}^{0} [GeV]'

            vr_list.append(addChannel(background_config,
                                      'mbl_1',
                                      this_vr_name,
                                      binning.get_binning('mbl',
                                                          single_bin=False)))
            vr_list[-1].titleX = 'm_{bl}^{1} [GeV]'

            vr_list.append(addChannel(background_config,
                                      'ht_signal',
                                      this_vr_name,
                                      binning.get_binning('ht', single_bin=False)))
            vr_list[-1].titleX = 'H_{T} [GeV]'


            # add theory systematics!
            # this is pretty ugly :-(
            if   'VR_top_1' in cr_name: syst_region = 'VR_top_1'
            elif 'VR_top_2' in cr_name: syst_region = 'VR_top_2'
            elif 'VR_top_3' in cr_name: syst_region = 'VR_top_3'
            elif 'VR_Z' in cr_name:     syst_region = 'VR_Z'
            else:
                continue

            this_theort_uncert_dict = theory_uncert[syst_region]
            for sample in this_theort_uncert_dict:
                if   sample == 'Top': this_sample = 'ttbar'
                elif sample == 'ST':  this_sample = 'SingleTop'
                elif sample == 'ZX':  this_sample = 'ZGamma'
                else:                 continue

                for systematic in this_theort_uncert_dict[sample]:
                    vr_list[-1].getSample(this_sample).addSystematic(systematic)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    for cr_name in ['CR_top', 'CR_Z']:
        # for flavor_channel in ['_all']:
        for flavor_channel in ['_all', '_ee', '_mm', '_em']:
            if cr_name  == 'CR_Z' and flavor_channel == '_em': continue

            # unique name for this CR/flavor channel combination
            this_cr_name = ''.join([cr_name, flavor_channel])

            # add CR plots
            if flavor_channel == '_all':
                vr_list.append(addChannel(background_config,
                                          'flavor_channel',
                                          this_cr_name,
                                          binning.get_binning('flavor_channel',
                                                              single_bin=False)))
                vr_list[-1].titleX = 'Flavor Channel'
            else:
                vr_list.append(addChannel(background_config,
                                        'mbl_0',
                                        this_cr_name,
                                        binning.get_binning('mbl',
                                                            single_bin=False)))
                vr_list[-1].titleX = 'm_{bl}^{0} [GeV]'

            vr_list.append(addChannel(background_config,
                                      'mbl_1',
                                      this_cr_name,
                                      binning.get_binning('mbl',
                                                          single_bin=False)))
            vr_list[-1].titleX = 'm_{bl}^{1} [GeV]'

            vr_list.append(addChannel(background_config,
                                      'ht_signal',
                                      this_cr_name,
                                      binning.get_binning('ht',
                                                          single_bin=False)))
            vr_list[-1].titleX = 'H_{T} [GeV]'



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
                    vr_list[-1].getSample(this_sample).addSystematic(systematic)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # turn on overflow bin for all VR plots
    for vr in vr_list:
        vr.useOverflowBin = True
        vr.logY = False

    background_config.setValidationChannels(vr_list)


# ------------------------------------------------------------------------------
# set up SRs
if not myFitType == FitType.Discovery:
    sr_list = []
    for region_name in configMgr.cutsDict.keys():
        if 'SR' not in region_name: continue

        print 'this sr name: ', region_name
        sr_list.append(addChannel(background_config,
                                  "mbl_0",
                                  region_name,
                                  binning.get_binning('mbl',
                                                      single_bin=binning.single_bin_signal)))
        sr_list[-1].titleX = 'm_{bl}^{0} [GeV]'

        if myFitType == FitType.Background:
            sr_list.append(addChannel(background_config,
                                      "mbl_1",
                                      region_name,
                                      binning.get_binning('mbl',
                                                          single_bin=binning.single_bin_signal)))
            sr_list[-1].titleX = 'm_{bl}^{1} [GeV]'

            sr_list.append(addChannel(background_config,
                                      "mbl_asym",
                                      region_name,
                                      binning.get_binning('mbl_asym',
                                                          single_bin=binning.single_bin_signal)))
            sr_list[-1].titleX = 'm_{bl} asymmetry'

            sr_list.append(addChannel(background_config,
                                      "ht_signal",
                                      region_name,
                                      binning.get_binning('ht_sr',
                                                          single_bin=binning.single_bin_signal)))
            sr_list[-1].titleX = 'H_{T} [GeV]'

            sr_list.append(addChannel(background_config,
                                      "met_sig_signal",
                                      region_name,
                                      binning.get_binning('met_sig',
                                                          single_bin=binning.single_bin_signal)))
            sr_list[-1].titleX = 'E_{T}^{miss} significance [GeV^{1/2}]'

            sr_list.append(addChannel(background_config,
                                      "mll",
                                      region_name,
                                      binning.get_binning('mll',
                                                          single_bin=binning.single_bin_signal)))
            sr_list[-1].titleX = 'm_{ll} [GeV]'

        # add theory systematics!
        # this is pretty ugly :-(
        if   'mbl_400' in region_name: syst_region = 'SR_400'
        elif 'mbl_600' in region_name: syst_region = 'SR_600'
        elif 'mbl_400' in test_sr:     syst_region = 'SR_400'
        elif 'mbl_600' in test_sr:     syst_region = 'SR_600'
        else:                          continue

        this_theort_uncert_dict = theory_uncert[syst_region]
        for sample in this_theort_uncert_dict:
            if   sample == 'Top': this_sample = 'ttbar'
            elif sample == 'ST':  this_sample = 'SingleTop'
            elif sample == 'ZX':  this_sample = 'ZGamma'
            else:                 continue

            for systematic in this_theort_uncert_dict[sample]:
                sr_list[-1].getSample(this_sample).addSystematic(systematic)

    for sr in sr_list:
        sr.useUnderflowBin = True
        sr.useOverflowBin  = True
        sr.titleY = "Entries"
        sr.logY = True
        sr.maxY = 5
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
    # sig_sample_list=['sig_900']

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

        # add baseline systematics to signal samples
        addSystematic([sig_sample],
                      (btag_sf_uncert_sig_list +
                      jes_uncert_list +
                      [jer_uncert]))

        # apply the correct cross section systematic to the signal
        # sample if it is available
        if sig in signal_xsec_rel_uncert:
            this_signal_xsec_uncert = Systematic(
                    name='SigXSec',
                    nominal=nominal_weight_sig,
                    high=(1+signal_xsec_rel_uncert[sig]),
                    low=(1-signal_xsec_rel_uncert[sig]),
                    type='user',
                    method='overallSys')
            sig_sample.addSystematic(this_signal_xsec_uncert)

        # add samples to configuration
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
if myFitType == FitType.Exclusion:
    entry = leg.AddEntry("", "signal", "lf")
    entry.SetLineColor(kViolet+5)
    entry.SetFillColor(kViolet+5)
    entry.SetFillStyle(compFillStyle)

# Set legend for fitConfig
background_config.tLegend = leg
if myFitType == FitType.Exclusion:
    exclusion_sr_config.tLegend = leg
c.Close()

print 'done with my stuff'
print '--------------------------------------------------------------------------------'
print ''

