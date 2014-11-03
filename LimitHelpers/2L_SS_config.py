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
configMgr.blindSR = True

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
configMgr.analysisName = "2L_SS"
configMgr.histCacheFile = "data/"+configMgr.analysisName+".root"
configMgr.outputFileName = "results/"+configMgr.analysisName+"_Output.root"

# Scaling calculated by outputLumi / inputLumi
configMgr.inputLumi = 0.001    # Luminosity of input TTree after weighting
# configMgr.outputLumi = 13.0    # Luminosity required for output histograms
configMgr.outputLumi = 21.0    # Luminosity required for output histograms
configMgr.setLumiUnits("fb-1")


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
#isr
base_sr_str_m20_isr = "(  )"
configMgr.cutsDict["SR_m20_isr_ee"] = '(%s && is_ee)' % base_sr_str
configMgr.cutsDict["SR_m20_isr_mm"] = '(%s && is_mm)' % base_sr_str
configMgr.cutsDict["SR_m20_isr_em"] = '(%s && is_em)' % base_sr_str

base_sr_str_m35_isr = "(  )"
configMgr.cutsDict["SR_m35_isr_ee"] = '(%s && is_ee)' % base_sr_str
configMgr.cutsDict["SR_m35_isr_mm"] = '(%s && is_mm)' % base_sr_str
configMgr.cutsDict["SR_m35_isr_em"] = '(%s && is_em)' % base_sr_str

base_sr_str_m65_isr = "(  )"
configMgr.cutsDict["SR_m65_isr_ee"] = '(%s && is_ee)' % base_sr_str
configMgr.cutsDict["SR_m65_isr_mm"] = '(%s && is_mm)' % base_sr_str
configMgr.cutsDict["SR_m65_isr_em"] = '(%s && is_em)' % base_sr_str

base_sr_str_m100_isr = "(  )"
configMgr.cutsDict["SR_m100_isr_ee"] = '(%s && is_ee)' % base_sr_str
configMgr.cutsDict["SR_m100_isr_mm"] = '(%s && is_mm)' % base_sr_str
configMgr.cutsDict["SR_m100_isr_em"] = '(%s && is_em)' % base_sr_str

#no_isr
base_sr_str_m20_no_isr = "(  )"
configMgr.cutsDict["SR_m20_no_isr_ee"] = '(%s && is_ee)' % base_sr_str
configMgr.cutsDict["SR_m20_no_isr_mm"] = '(%s && is_mm)' % base_sr_str
configMgr.cutsDict["SR_m20_no_isr_em"] = '(%s && is_em)' % base_sr_str

base_sr_str_m35_no_isr = "(  )"
configMgr.cutsDict["SR_m35_no_isr_ee"] = '(%s && is_ee)' % base_sr_str
configMgr.cutsDict["SR_m35_no_isr_mm"] = '(%s && is_mm)' % base_sr_str
configMgr.cutsDict["SR_m35_no_isr_em"] = '(%s && is_em)' % base_sr_str

base_sr_str_m65_no_isr = "(  )"
configMgr.cutsDict["SR_m65_no_isr_ee"] = '(%s && is_ee)' % base_sr_str
configMgr.cutsDict["SR_m65_no_isr_mm"] = '(%s && is_mm)' % base_sr_str
configMgr.cutsDict["SR_m65_no_isr_em"] = '(%s && is_em)' % base_sr_str

base_sr_str_m100_no_isr = "(  )"
configMgr.cutsDict["SR_m100_no_isr_ee"] = '(%s && is_ee)' % base_sr_str
configMgr.cutsDict["SR_m100_no_isr_mm"] = '(%s && is_mm)' % base_sr_str
configMgr.cutsDict["SR_m100_no_isr_em"] = '(%s && is_em)' % base_sr_str


# VR

base_vr_str_m20_isr = "(  )"
configMgr.cutsDict["VR_m20_isr_ee"] = '(%s && is_ee)' % base_vr_str_m20_isr
configMgr.cutsDict["VR_m20_isr_mm"] = '(%s && is_mm)' % base_vr_str_m20_isr
configMgr.cutsDict["VR_m20_isr_em"] = '(%s && is_em)' % base_vr_str_m20_isr

base_vr_str_m35_isr = "(  )"
configMgr.cutsDict["VR_m35_isr_ee"] = '(%s && is_ee)' % base_vr_str_m35_isr
configMgr.cutsDict["VR_m35_isr_mm"] = '(%s && is_mm)' % base_vr_str_m35_isr
configMgr.cutsDict["VR_m35_isr_em"] = '(%s && is_em)' % base_vr_str_m35_isr

base_vr_str_m65_isr = "(  )"
configMgr.cutsDict["VR_m65_isr_ee"] = '(%s && is_ee)' % base_vr_str_m65_isr
configMgr.cutsDict["VR_m65_isr_mm"] = '(%s && is_mm)' % base_vr_str_m65_isr
configMgr.cutsDict["VR_m65_isr_em"] = '(%s && is_em)' % base_vr_str_m65_isr

base_vr_str_m100_isr = "(  )"
configMgr.cutsDict["VR_m100_isr_ee"] = '(%s && is_ee)' % base_vr_str_m100_isr
configMgr.cutsDict["VR_m100_isr_mm"] = '(%s && is_mm)' % base_vr_str_m100_isr
configMgr.cutsDict["VR_m100_isr_em"] = '(%s && is_em)' % base_vr_str_m100_isr

#no_isr
base_vr_str_m20_no_isr = "(  )"
configMgr.cutsDict["VR_m20_no_isr_ee"] = '(%s && is_ee)' % base_vr_str_m20_no_isr
configMgr.cutsDict["VR_m20_no_isr_mm"] = '(%s && is_mm)' % base_vr_str_m20_no_isr
configMgr.cutsDict["VR_m20_no_isr_em"] = '(%s && is_em)' % base_vr_str_m20_no_isr

base_vr_str_m35_no_isr = "(  )"
configMgr.cutsDict["VR_m35_no_isr_ee"] = '(%s && is_ee)' % base_vr_str_m35_no_isr
configMgr.cutsDict["VR_m35_no_isr_mm"] = '(%s && is_mm)' % base_vr_str_m35_no_isr
configMgr.cutsDict["VR_m35_no_isr_em"] = '(%s && is_em)' % base_vr_str_m35_no_isr

base_vr_str_m65_no_isr = "(  )"
configMgr.cutsDict["VR_m65_no_isr_ee"] = '(%s && is_ee)' % base_vr_str_m65_no_isr
configMgr.cutsDict["VR_m65_no_isr_mm"] = '(%s && is_mm)' % base_vr_str_m65_no_isr
configMgr.cutsDict["VR_m65_no_isr_em"] = '(%s && is_em)' % base_vr_str_m65_no_isr

base_vr_str_m100_no_isr = "(  )"
configMgr.cutsDict["VR_m100_no_isr_ee"] = '(%s && is_ee)' % base_vr_str_m100_no_isr
configMgr.cutsDict["VR_m100_no_isr_mm"] = '(%s && is_mm)' % base_vr_str_m100_no_isr
configMgr.cutsDict["VR_m100_no_isr_em"] = '(%s && is_em)' % base_vr_str_m100_no_isr


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
gen_syst = Systematic( "gen_syst" , configMgr.weights , 1.0 + 0.30 , 1.0 - 0.30 , "user" , "userOverallSys" )

# JES uncertainty as shapeSys - one systematic per region (combine WR and TR), merge samples
# jes = Systematic("JES","_NoSys","_JESup","_JESdown","tree","overallNormHistoSys")

# --------------------------------------------
# - List of samples and their plotting colours
# --------------------------------------------
sample_list = []

# ttbar
# ttbar_sample = Sample( "ttbar" , kGreen-2 )
ttbar_ee_sample = Sample( "ee_ttbar" , kGreen-1 )
ttbar_mm_sample = Sample( "mm_ttbar" , kGreen-2 )
ttbar_em_sample = Sample( "em_ttbar" , kGreen-3 )

# ttbar_sample.setNormFactor("mu_ttbar",1.,0.,5.)
ttbar_ee_sample.setNormFactor("mu_ttbar_ee",1.,0.,5.)
ttbar_mm_sample.setNormFactor("mu_ttbar_mm",1.,0.,5.)
ttbar_em_sample.setNormFactor("mu_ttbar_em",1.,0.,5.)

# ttbar_sample.setStatConfig(use_stat)
ttbar_ee_sample.setStatConfig(use_stat)
ttbar_mm_sample.setStatConfig(use_stat)
ttbar_em_sample.setStatConfig(use_stat)

# sample_list.append(ttbar_sample)
sample_list.append(ttbar_ee_sample)
sample_list.append(ttbar_mm_sample)
sample_list.append(ttbar_em_sample)


# single top
# single_top_sample    = Sample( "SingleTop" , kGreen-1 )
single_top_ee_sample = Sample( "ee_SingleTop" , kCyan-1 )
single_top_mm_sample = Sample( "mm_SingleTop" , kCyan-2 )
single_top_em_sample = Sample( "em_SingleTop" , kCyan-3 )

# single_top_sample.setStatConfig(   use_stat)
single_top_ee_sample.setStatConfig(use_stat)
single_top_mm_sample.setStatConfig(use_stat)
single_top_em_sample.setStatConfig(use_stat)

# single_top_sample.setNormByTheory()
single_top_ee_sample.setNormByTheory()
single_top_mm_sample.setNormByTheory()
single_top_em_sample.setNormByTheory()

# sample_list.append(single_top_sample)
sample_list.append(single_top_ee_sample)
sample_list.append(single_top_mm_sample)
sample_list.append(single_top_em_sample)

# Z/gamma*
# z_sample = Sample( "Z" , kRed+1 )
z_ee_sample = Sample( "ee_Z" , kRed+1 )
z_mm_sample = Sample( "mm_Z" , kRed+2 )
z_em_sample = Sample( "em_Z" , kRed+3 )

# z_sample.setNormFactor("mu_z",1.,0.,5.)
z_ee_sample.setNormFactor("mu_z_ee",1.,0.,5.)
z_mm_sample.setNormFactor("mu_z_mm",1.,0.,5.)
# z_em_sample.setNormFactor("mu_z_em",1.,0.,5.)
z_em_sample.setNormByTheory()

# z_sample.setStatConfig(use_stat)
z_ee_sample.setStatConfig(use_stat)
z_mm_sample.setStatConfig(use_stat)
z_em_sample.setStatConfig(use_stat)

# sample_list.append(z_sample)
sample_list.append(z_ee_sample)
sample_list.append(z_mm_sample)
sample_list.append(z_em_sample)

# data
data_sample = Sample("data",kBlack)
data_sample.setData()
sample_list.append(data_sample)

# set the file from which the samples should be taken
for sl in sample_list:
    sl.setFileList(bkg_files)

# ----------
# - Binnings
# ----------
# TODO reset the binning and add more histograms

### pt binning
##pt_bin = 10
##pt_min = 0
##pt_max = 500
##
### mbbll binning
##mbbll_bin = 6
##mbbll_min = 0
##mbbll_max = 1200
##
### mbl binning
##mbl_bin = 6
##mbl_min = 0
##mbl_max = 1200
##
### ptbl binning
##ptbl_bin = 6
##ptbl_min = 0
##ptbl_max = 600
##
### ptll binning
##ptll_bin = 6
##ptll_min = 0
##ptll_max = 600
##
### ptbbll binning
##ptbbll_bin = 6
##ptbbll_min = 0
##ptbbll_max = 600
##
### mll binning
##mll_bin = 10
##mll_min = 0
##mll_max = 500
##
##mll_inz_bin = 6
##mll_inz_min = 75
##mll_inz_max = 105
##
### ht binning
### ht_bin = 20
### ht_min = 0
### ht_max = 1000
##ht_bin = 6
##ht_min = 0
##ht_max = 600
##
### mbl asym binning
##mbl_asym_bin = 5
##mbl_asym_min = 0
##mbl_asym_max = 1.
##
### met significance binning
##met_sig_bin = 10
##met_sig_min = 0
##met_sig_max = 500
##
### met et binning
##met_et_bin = 5
##met_et_min = 0
##met_et_max = 100
##
### dphi binning
##dphi_bin = 8
##dphi_min = 0
##dphi_max = 3.2
##
### deta binning
##deta_bin = 4
##deta_min = 0
##deta_max = 4
##
### dr binning
##dr_bin = 4
##dr_min = 0
##dr_max = 4
##

# SR binning (this is just a single bin cut and count binning)
srNBins = 1
srBinLow = 0.5
srBinHigh = 1.5

# **************
# * Bkg only fit
# **************
background_config = configMgr.addFitConfig("BkgOnly")
if use_stat:
    background_config.statErrThreshold = 0.05
else:
    background_config.statErrThreshold = None
background_config.addSamples(sample_list)

# Systematics to be applied globally within this topLevel
# background_config.getSample("ttbar"    ).addSystematic(gen_syst)
background_config.getSample("ee_ttbar" ).addSystematic(gen_syst)
background_config.getSample("mm_ttbar" ).addSystematic(gen_syst)
background_config.getSample("em_ttbar" ).addSystematic(gen_syst)
# background_config.getSample("SingleTop").addSystematic(gen_syst)
background_config.getSample("ee_SingleTop").addSystematic(gen_syst)
background_config.getSample("mm_SingleTop").addSystematic(gen_syst)
background_config.getSample("em_SingleTop").addSystematic(gen_syst)
# background_config.getSample("Z"        ).addSystematic(gen_syst)
background_config.getSample("ee_Z"        ).addSystematic(gen_syst)
background_config.getSample("mm_Z"        ).addSystematic(gen_syst)
background_config.getSample("em_Z"        ).addSystematic(gen_syst)

meas = background_config.addMeasurement(name = "NormalMeasurement", lumi = 1.0, lumiErr = 0.039 )
meas.addPOI("mu_SIG")

# --------------------------------------------------
# - Constraining regions - statistically independent
# --------------------------------------------------
cr_list = []
# Add Top CR for background
for cr_name in ['CR_top_', 'CR_Z_']:
    for flavor_channel in ['ee', 'mm', 'em']:
        if cr_name  == 'CR_Z_' and flavor_channel == 'em': continue

        cr_list.append( background_config.addChannel( "mbl_0"                         , ['%s%s' % (cr_name, flavor_channel)] , mbl_bin      , mbl_min      , mbl_max      ) )
        cr_list.append( background_config.addChannel( "mbl_1"                         , ['%s%s' % (cr_name, flavor_channel)] , mbl_bin      , mbl_min      , mbl_max      ) )
        if cr_name == 'CR_Z_':
            cr_list.append( background_config.addChannel( "mll"                       , ['%s%s' % (cr_name, flavor_channel)] , mll_inz_bin  , mll_inz_min  , mll_inz_max  ) )
        else:
            cr_list.append( background_config.addChannel( "mll"                       , ['%s%s' % (cr_name, flavor_channel)] , mll_bin      , mll_min      , mll_max      ) )
        cr_list.append( background_config.addChannel( "ht_signal"                     , ['%s%s' % (cr_name, flavor_channel)] , ht_bin       , ht_min       , ht_max       ) )
        # cr_list.append( background_config.addChannel( '((mbl_0-mbl_1)/(mbl_0+mbl_1))' , ['%s%s' % (cr_name, flavor_channel)] , mbl_asym_bin , mbl_asym_min , mbl_asym_max ) )
        # cr_list.append( background_config.addChannel( '(met_et/sqrt(ht_signal))'      , ['%s%s' % (cr_name, flavor_channel)] , met_sig_bin  , met_sig_min  , met_sig_max  ) )

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
    crl.useOverflowBin = True
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
    for vr_name in ['VR_w_Z', 'VR_no_Z', 'VR_llbb']:
        for flavor_channel in ['', '_ee', '_mm', '_em']:
            if vr_name  == 'VR_w_Z' and flavor_channel == '_em': continue

            vr_list.append( background_config.addChannel( 'mbl_0'    , ['%s%s' % (vr_name, flavor_channel)], mbl_bin   , mbl_min   , mbl_max    ) )
            vr_list.append( background_config.addChannel( 'mbl_1'    , ['%s%s' % (vr_name, flavor_channel)], mbl_bin   , mbl_min   , mbl_max    ) )
            # vr_list.append( background_config.addChannel( 'mbbll'    , ['%s%s' % (vr_name, flavor_channel)], mbbll_bin , mbbll_min , mbbll_max  ) )
            # vr_list.append( background_config.addChannel( 'ptbl_0'   , ['%s%s' % (vr_name, flavor_channel)], ptbl_bin  , ptbl_min  , ptbl_max   ) )
            # vr_list.append( background_config.addChannel( 'ptbl_1'   , ['%s%s' % (vr_name, flavor_channel)], ptbl_bin  , ptbl_min  , ptbl_max   ) )
            # vr_list.append( background_config.addChannel( 'ptbbll'   , ['%s%s' % (vr_name, flavor_channel)], ptbbll_bin, ptbbll_min, ptbbll_max ) )
            if vr_name == 'VR_w_Z':
                vr_list.append( background_config.addChannel( 'mll'      , ['%s%s' % (vr_name, flavor_channel)], mll_inz_bin , mll_inz_min , mll_inz_max ) )
            else:
                vr_list.append( background_config.addChannel( 'mll'      , ['%s%s' % (vr_name, flavor_channel)], mll_bin     , mll_min     , mll_max     ) )
            # vr_list.append( background_config.addChannel( 'ptll'     , ['%s%s' % (vr_name, flavor_channel)], ptll_bin  , ptll_min  , ptll_max   ) )
            vr_list.append( background_config.addChannel( 'met_et'   , ['%s%s' % (vr_name, flavor_channel)], met_et_bin, met_et_min, met_et_max ) )
            vr_list.append( background_config.addChannel( 'ht_signal', ['%s%s' % (vr_name, flavor_channel)], ht_bin    , ht_min    , ht_max     ) )
            vr_list.append( background_config.addChannel( 'pt_l_0'   , ['%s%s' % (vr_name, flavor_channel)], pt_bin    , pt_min    , pt_max     ) )
            vr_list.append( background_config.addChannel( 'pt_l_1'   , ['%s%s' % (vr_name, flavor_channel)], pt_bin    , pt_min    , pt_max     ) )
            vr_list.append( background_config.addChannel( 'pt_b_0'   , ['%s%s' % (vr_name, flavor_channel)], pt_bin    , pt_min    , pt_max     ) )
            vr_list.append( background_config.addChannel( 'pt_b_1'   , ['%s%s' % (vr_name, flavor_channel)], pt_bin    , pt_min    , pt_max     ) )
            # vr_list.append( background_config.addChannel( 'dphi_bl_0', ['%s%s' % (vr_name, flavor_channel)], dphi_bin  , dphi_min  , dphi_max   ) )
            # vr_list.append( background_config.addChannel( 'dphi_bl_1', ['%s%s' % (vr_name, flavor_channel)], dphi_bin  , dphi_min  , dphi_max   ) )
            # vr_list.append( background_config.addChannel( 'deta_bl_0', ['%s%s' % (vr_name, flavor_channel)], deta_bin  , deta_min  , deta_max   ) )
            # vr_list.append( background_config.addChannel( 'deta_bl_1', ['%s%s' % (vr_name, flavor_channel)], deta_bin  , deta_min  , deta_max   ) )
            # vr_list.append( background_config.addChannel( 'dr_bl_0'  , ['%s%s' % (vr_name, flavor_channel)], dr_bin    , dr_min    , dr_max     ) )
            # vr_list.append( background_config.addChannel( 'dr_bl_1'  , ['%s%s' % (vr_name, flavor_channel)], dr_bin    , dr_min    , dr_max     ) )
            # vr_list.append( background_config.addChannel( 'dphi_ll'  , ['%s%s' % (vr_name, flavor_channel)], dphi_bin  , dphi_min  , dphi_max   ) )
            # vr_list.append( background_config.addChannel( 'deta_ll'  , ['%s%s' % (vr_name, flavor_channel)], deta_bin  , deta_min  , deta_max   ) )
            # vr_list.append( background_config.addChannel( 'dr_ll'    , ['%s%s' % (vr_name, flavor_channel)], dr_bin    , dr_min    , dr_max     ) )
            # vr_list.append( background_config.addChannel( 'dphi_bb'  , ['%s%s' % (vr_name, flavor_channel)], dphi_bin  , dphi_min  , dphi_max   ) )
            # vr_list.append( background_config.addChannel( 'deta_bb'  , ['%s%s' % (vr_name, flavor_channel)], deta_bin  , deta_min  , deta_max   ) )
            # vr_list.append( background_config.addChannel( 'dr_bb'    , ['%s%s' % (vr_name, flavor_channel)], dr_bin    , dr_min    , dr_max     ) )

    for vr in vr_list:
        vr.useOverflowBin = True

    background_config.setValidationChannels( vr_list )

# ------------------------------------------------------------------------------
# - set up SRs
# ------------------------------------------------------------------------------
if not myFitType == FitType.Discovery:
# if myFitType == FitType.Exclusion:
    sr_list = []
    for flavor_channel in ['ee', 'mm', 'em']:
        sr_list.append( background_config.addChannel( "mbl_0", ["SR_%s" % flavor_channel], mbl_bin, mbl_min, mbl_max ) )
        sr_list.append( background_config.addChannel( "mbl_1", ["SR_%s" % flavor_channel], mbl_bin, mbl_min, mbl_max ) )

    for sr in sr_list:
        sr.useUnderflowBin = True
        sr.useOverflowBin  = True
        sr.titleY = "Entries"
        sr.logY = True
        sr.ATLASLabelX = 0.25
        sr.ATLASLabelY = 0.85
        sr.ATLASLabelText = "Work in progress"

    background_config.setSignalChannels(sr_list)

# ---------------
# - Discovery fit
# ---------------
if myFitType == FitType.Discovery:
    print 'ERROR!!! DISCOVERY FIT IS NOT YET CONFIGURED!!!'

# -------------------------------------------------------
# - Exclusion fits (1-step simplified model in this case)
# -------------------------------------------------------
if myFitType == FitType.Exclusion:
    print 'Setting up exclusion fit!'
    sig_sample_list=['sig_500', 'sig_600', 'sig_700', 'sig_800', 'sig_900', 'sig_1000']
    # sig_sample_list=['sig_500']
    sig_samples = []
    for sig in sig_sample_list:
        print 'setting up signal sample: ' , sig
        exclusion_sr_config = configMgr.addFitConfigClone( background_config , "Sig_excl_%s" % sig )
        # exclusion_sr_config = configMgr.addFitConfigClone( background_config , "Exclusion_%s" % sig )

        sig_sample = Sample(sig, kViolet+5)
        sig_sample.setStatConfig(use_stat)
        sig_sample.setFileList(sig_files)
        sig_sample.setNormByTheory()
        sig_sample.setNormFactor("mu_SIG", 1., 0., 5.)

        exclusion_sr_config.addSamples(sig_sample)
        exclusion_sr_config.setSignalSample(sig_sample)
        exclusion_sr_config.setSignalChannels(sr_list)

# ----------------
# - Create TLegend
# ----------------
# TCanvas is needed for that, but it gets deleted afterwards
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
# entry = leg.AddEntry("", "t#bar{t}", "lf")
# entry.SetLineColor(ttbar_sample.color)
# entry.SetFillColor(ttbar_sample.color)
# entry.SetFillStyle(compFillStyle)

entry = leg.AddEntry("", "t#bar{t} ee", "lf")
entry.SetLineColor(ttbar_ee_sample.color)
entry.SetFillColor(ttbar_ee_sample.color)
entry.SetFillStyle(compFillStyle)

entry = leg.AddEntry("", "t#bar{t} mm", "lf")
entry.SetLineColor(ttbar_mm_sample.color)
entry.SetFillColor(ttbar_mm_sample.color)
entry.SetFillStyle(compFillStyle)

entry = leg.AddEntry("", "t#bar{t} em", "lf")
entry.SetLineColor(ttbar_em_sample.color)
entry.SetFillColor(ttbar_em_sample.color)
entry.SetFillStyle(compFillStyle)

# Single top entry
# entry = leg.AddEntry("", "Single top", "lf")
# entry.SetLineColor(single_top_sample.color)
# entry.SetFillColor(single_top_sample.color)
# entry.SetFillStyle(compFillStyle)

entry = leg.AddEntry("", "Single top (ee)", "lf")
entry.SetLineColor(single_top_ee_sample.color)
entry.SetFillColor(single_top_ee_sample.color)
entry.SetFillStyle(compFillStyle)

entry = leg.AddEntry("", "Single top (mm)", "lf")
entry.SetLineColor(single_top_mm_sample.color)
entry.SetFillColor(single_top_mm_sample.color)
entry.SetFillStyle(compFillStyle)

entry = leg.AddEntry("", "Single top (em)", "lf")
entry.SetLineColor(single_top_em_sample.color)
entry.SetFillColor(single_top_em_sample.color)
entry.SetFillStyle(compFillStyle)

# Z/gamma* entry
# entry = leg.AddEntry("", "Z/#gamma*", "lf")
# entry.SetLineColor(z_sample.color)
# entry.SetFillColor(z_sample.color)
# entry.SetFillStyle(compFillStyle)

entry = leg.AddEntry("", "Z/#gamma* (ee)", "lf")
entry.SetLineColor(z_ee_sample.color)
entry.SetFillColor(z_ee_sample.color)
entry.SetFillStyle(compFillStyle)

entry = leg.AddEntry("", "Z/#gamma* (mm)", "lf")
entry.SetLineColor(z_mm_sample.color)
entry.SetFillColor(z_mm_sample.color)
entry.SetFillStyle(compFillStyle)

entry = leg.AddEntry("", "Z/#gamma* (em)", "lf")
entry.SetLineColor(z_em_sample.color)
entry.SetFillColor(z_em_sample.color)
entry.SetFillStyle(compFillStyle)

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
