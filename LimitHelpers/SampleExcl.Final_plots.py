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
    analysis_name.append('SampleBkgFinal')
elif myFitType == FitType.Exclusion:
    analysis_name.append("SampleExclFinal")
elif myFitType == FitType.Discovery:
    analysis_name.append("SampleDiscFinal")

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
configMgr.outputLumi = 20.3    # Luminosity required for output histograms
configMgr.setLumiUnits("fb-1")

# configMgr.plotRatio="none"

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

    base_sr_minus_ht_str = '((mbl_0 > 400) && (mbl_asym < 0.2))'
    base_sr_minus_mbl_asym_str = '((mbl_0 > 400) && (ht_signal > 1100))'
    base_sr_minus_mbl_str = '((ht_signal > 1100) && (mbl_asym < 0.2))'
    z_veto_str = '(abs(mll-91) < 10)'
    configMgr.cutsDict['SR_minus_ht'] = '((%s && %s && is_ee) + (%s && %s && is_mm) + (%s && is_em))' % (base_sr_minus_ht_str, z_veto_str,
                                                                                                         base_sr_minus_ht_str, z_veto_str,
                                                                                                         base_sr_minus_ht_str)
    configMgr.cutsDict['SR_minus_mbl_asym'] = '((%s && %s && is_ee) + (%s && %s && is_mm) + (%s && is_em))' % (base_sr_minus_mbl_asym_str, z_veto_str,
                                                                                                               base_sr_minus_mbl_asym_str, z_veto_str,
                                                                                                               base_sr_minus_mbl_asym_str)
    configMgr.cutsDict['SR_minus_mbl'] = '((%s && %s && is_ee) + (%s && %s && is_mm) + (%s && is_em))' % (base_sr_minus_mbl_str, z_veto_str,
                                                                                                          base_sr_minus_mbl_str, z_veto_str,
                                                                                                          base_sr_minus_mbl_str)

# CR_top
# base_cr_top_str = "is_cr_top"
base_cr_top_str = "is_cr_top_mbl_200"
configMgr.cutsDict["CR_top_all"] = base_cr_top_str

# CR_Z
base_cr_z_str = "is_cr_z_mbl_200"
configMgr.cutsDict["CR_Z_all"] = base_cr_z_str

# VR top 1
base_vr_top_1_str = "is_vr_top_mbl_200_1"
configMgr.cutsDict["VR_top_1_all"] = base_vr_top_1_str

print '-'*80
print 'configMgr.cutDict:'
print configMgr.cutsDict

# VR top 2
base_vr_top_2_str = "is_vr_top_mbl_200_2"
configMgr.cutsDict["VR_top_2_all"] = base_vr_top_2_str

# VR top 3
base_vr_top_3_str = "is_vr_top_mbl_200_3"
configMgr.cutsDict["VR_top_3_all"] = base_vr_top_3_str

# VR Z
base_vr_z_str = "is_vr_z_mbl_200"
configMgr.cutsDict["VR_Z_all"] = base_vr_z_str

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
        if cr_name  == 'CR_Z_' and flavor_channel == 'em': continue

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

# ______________________________________________________________________________
# Construct Validation regions
vr_list = []
if do_validation:
    print 'Setting up validation regions!'

    vr_list.append(addChannel(background_config,
                              'ht_signal',
                              'SR_minus_ht',
                              binning.get_binning('ht_full',
                                                  single_bin=False)))
    vr_list[-1].titleX = 'H_{T} [GeV]'
    vr_list[-1].maxY = 30

    vr_list.append(addChannel(background_config,
                              'mbl_asym',
                              'SR_minus_mbl_asym',
                              binning.get_binning('mbl_asym',
                                                  single_bin=False)))
    vr_list[-1].titleX = 'm_{bl} asymmetry'
    # vr_list[-1].maxY = 30

    vr_list.append(addChannel(background_config,
                              'mbl_0',
                              'SR_minus_mbl',
                              binning.get_binning('mbl',
                                                  single_bin=False)))
    vr_list[-1].titleX = 'm_{bl}^{0} [GeV]'
    vr_list[-1].maxY = 4


    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    for vr_name in ['VR_top_1', 'VR_top_2', 'VR_top_3', 'VR_Z']:
        for flavor_channel in ['_all']:
            if vr_name  == 'VR_Z' and flavor_channel == '_em':
                continue

            # unique name for this VR/flavor channel combination
            this_vr_name = ''.join([vr_name, flavor_channel])

            vr_list.append(addChannel(background_config,
                                      'mbl_0',
                                      this_vr_name,
                                      binning.get_binning('mbl',
                                                          single_bin=False)))
            vr_list[-1].titleX = 'm_{bl}^{0} [GeV]'
            if vr_name in ['VR_top_3']:
                vr_list[-1].maxY = 50

            if vr_name in ['VR_top_3', 'VR_Z']:
                vr_list.append(addChannel(background_config,
                                        'ht_signal',
                                        this_vr_name,
                                        binning.get_binning('ht_mid', single_bin=False)))
            else:
                vr_list.append(addChannel(background_config,
                                        'ht_signal',
                                        this_vr_name,
                                        binning.get_binning('ht_low', single_bin=False)))
            vr_list[-1].titleX = 'H_{T} [GeV]'
            if vr_name in ['VR_top_1', 'VR_top_2']:
                vr_list[-1].maxY = 300

            # add theory systematics!
            # this is pretty ugly :-(
            if 'VR_top_1' in cr_name:
                syst_region = 'VR_top_1'
            elif 'VR_top_2' in cr_name:
                syst_region = 'VR_top_2'
            elif 'VR_top_3' in cr_name:
                syst_region = 'VR_top_3'
            elif 'VR_Z' in cr_name:
                syst_region = 'VR_Z'
            else:
                continue

            this_theort_uncert_dict = theory_uncert[syst_region]
            for sample in this_theort_uncert_dict:
                if sample == 'Top':
                    this_sample = 'ttbar'
                elif sample == 'ST':
                    this_sample = 'SingleTop'
                elif sample == 'ZX':
                    this_sample = 'ZGamma'
                else:
                    continue

                for systematic in this_theort_uncert_dict[sample]:
                    vr_list[-1].getSample(this_sample).addSystematic(systematic)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    for cr_name in ['CR_top', 'CR_Z']:
        for flavor_channel in ['_all']:
            if cr_name  == 'CR_Z' and flavor_channel == '_em': continue

            # unique name for this CR/flavor channel combination
            this_cr_name = ''.join([cr_name, flavor_channel])

            vr_list.append(addChannel(background_config,
                                    'mbl_0',
                                    this_cr_name,
                                    binning.get_binning('mbl',
                                                        single_bin=False)))
            vr_list[-1].titleX = 'm_{bl}^{0} [GeV]'

            vr_list.append(addChannel(background_config,
                                      'ht_signal',
                                      this_cr_name,
                                      binning.get_binning('ht_low',
                                                          single_bin=False)))
            vr_list[-1].titleX = 'H_{T} [GeV]'
            if cr_name in ['CR_top']:
                vr_list[-1].maxY = 160
            if cr_name in ['CR_Z']:
                vr_list[-1].maxY = 140

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
        vr.showLumi = True
        vr.ATLASLabelX = 0.32
        vr.ATLASLabelY = 0.88
        vr.ATLASLabelText = 'Internal'

    background_config.setValidationChannels(vr_list)

# ------------------------------------------------------------------------------
# Configure discovery fit
if myFitType == FitType.Discovery:
    print 'ERROR!!! DISCOVERY FIT IS NOT YET CONFIGURED!!!'


# ------------------------------------------------------------------------------
# Configure exclusion fits
if myFitType == FitType.Exclusion:
    print 'Setting up exclusion fit!'
    sig_sample_list=['sig_500', 'sig_800']
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

