#!/usr/bin/env python

import os
import sys
sys.path.append('%s/HistFitter/python' % os.environ['BASE_WORK_DIR'])
import pullPlotUtils
import ROOT
import shutil
import glob

# ------------------------------------------------------------------------------
# define function to get sample colors
def myGetSampleColor(sample):
    if sample == "ttbar":     return ROOT.kGreen+2
    if sample == "SingleTop": return ROOT.kGreen-1
    if sample == "ZGamma":    return ROOT.kRed+1
    if sample == "ttV":       return ROOT.kAzure+8
    if sample == "Diboson":   return ROOT.kSpring-4
    if sample == "Higgs":     return ROOT.kOrange-5
    return ROOT.kBlack
pullPlotUtils.getSampleColor = myGetSampleColor

# ------------------------------------------------------------------------------
# define function to get region colors
def myGetRegionColor(region):
    if 'CR_top' in region or 'CR Top' in region: return ROOT.kGreen-7
    if 'CR_Z' in region or 'CR Z' in region:     return ROOT.kRed-7
    if 'VR_3' in region or 'VR Top' in region:   return ROOT.kGreen-9
    if 'VR_5' in region or 'VR Z' in region:     return ROOT.kRed-9
    return ROOT.kBlack
pullPlotUtils.getRegionColor = myGetRegionColor

# ------------------------------------------------------------------------------
rename_dict = { 'CR_top_all_mbl_0':'CR Top'
              , 'CR_top_ee_mbl_0':'CR Top (ee)'
              , 'CR_top_mm_mbl_0':'CR Top (mm)'
              , 'CR_top_em_mbl_0':'CR Top (em)'
              , 'CR_Z_all_mbl_0':'CR Z'
              , 'CR_Z_ee_mbl_0':'CR Z (ee)'
              , 'CR_Z_mm_mbl_0':'CR Z (mm)'
              , 'VR_3_all_mbl_0':'VR Top'
              , 'VR_3_ee_mbl_0':'VR Top (ee)'
              , 'VR_3_mm_mbl_0':'VR Top (mm)'
              , 'VR_3_em_mbl_0':'VR Top (em)'
              , 'VR_5_all_mbl_0':'VR Z'
              , 'VR_5_ee_mbl_0':'VR Z (ee)'
              , 'VR_5_mm_mbl_0':'VR Z (mm)'
              }

# ------------------------------------------------------------------------------
sample_string = 'ttbar,ZGamma,SingleTop,ttV,Diboson,Higgs'

# ------------------------------------------------------------------------------
def renamePulls(tag):
    for extension in ['png', 'eps', 'pdf']:
        shutil.move( 'histpull_.%s' % extension
                   , 'histpull_%s.%s' % (tag, extension)
                   )

# ------------------------------------------------------------------------------
# make the basic pull plot!
print 'making basic pull plot'
pullPlotUtils.makePullPlot( pickleFilename = 'YieldTable/MyYieldTable.CR_VR.pickle'
                           , regionList = [ 'CR_top_all_mbl_0'
                                          , 'CR_Z_all_mbl_0'
                                          , 'VR_3_all_mbl_0'
                                          , 'VR_5_all_mbl_0'
                                          ]
                           , samples = sample_string
                           , renamedRegions = rename_dict
                           , outputPrefix = ''
                           , doBlind = True
                           )

renamePulls('CR_VR')

# ------------------------------------------------------------------------------
# make the CR detailed pull plot!
print 'making detailed CR pull plot'
pullPlotUtils.makePullPlot( pickleFilename = 'YieldTable/MyYieldTable.CR_detail.pickle'
                           , regionList = [ 'CR_top_all_mbl_0'
                                          , 'CR_top_ee_mbl_0'
                                          , 'CR_top_mm_mbl_0'
                                          , 'CR_top_em_mbl_0'
                                          , 'CR_Z_all_mbl_0'
                                          , 'CR_Z_ee_mbl_0'
                                          , 'CR_Z_mm_mbl_0'
                                          ]
                           , samples = sample_string
                           , renamedRegions = rename_dict
                           , outputPrefix = ''
                           , doBlind = True
                           )
renamePulls('CR_detailed')

# ------------------------------------------------------------------------------
# make the VR detailed pull plot!
print 'making detailed VR pull plot'
pullPlotUtils.makePullPlot( pickleFilename = 'YieldTable/MyYieldTable.VR_detail.pickle'
                           , regionList = [ 'VR_3_all_mbl_0'
                                          , 'VR_3_ee_mbl_0'
                                          , 'VR_3_mm_mbl_0'
                                          , 'VR_3_em_mbl_0'
                                          , 'VR_5_all_mbl_0'
                                          , 'VR_5_ee_mbl_0'
                                          , 'VR_5_mm_mbl_0'
                                          ]
                           , samples = sample_string
                           , renamedRegions = rename_dict
                           , outputPrefix = ''
                           , doBlind = True
                           )
renamePulls('VR_detailed')

