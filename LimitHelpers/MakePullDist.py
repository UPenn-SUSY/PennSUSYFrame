#!/usr/bin/env python

import os
import sys
sys.path.append('%s/HistFitter/python' % os.environ['BASE_WORK_DIR'])
import pullPlotUtils
import ROOT

# ------------------------------------------------------------------------------
# define function to get sample colors
def myGetSampleColor(sample):
    if sample == "ttbar":     return ROOT.kGreen+2
    if sample == "SingleTop": return ROOT.kGreen-1
    if sample == "Z":         return ROOT.kRed+1
    if sample == "ttV":       return ROOT.kAzure+8
    if sample == "Diboson":   return ROOT.kSpring-4
    if sample == "Higgs":     return ROOT.kOrange-5
    return kBlack
pullPlotUtils.getSampleColor = myGetSampleColor

# ------------------------------------------------------------------------------
# define function to get region colors
def myGetRegionColor(region):
    if 'CR_top' in region or 'CR Top' in region: return ROOT.kGreen-7
    if 'CR_Z' in region or 'CR Z' in region:     return ROOT.kRed-7
    if 'VR_3' in region or 'VR Top' in region:   return ROOT.kGreen-9
    if 'VR_5' in region or 'VR Z' in region:     return ROOT.kRed-9
    return kBlack
pullPlotUtils.getRegionColor = myGetRegionColor

# ------------------------------------------------------------------------------
# make the pull plot!
pullPlotUtils.makePullPlot( pickleFilename = 'YieldTable/MyYieldTable.pickle'
                           , regionList = [ 'CR_top_all_mbl_0'
                                          , 'CR_Z_all_mbl_0'
                                          , 'VR_3_all_mbl_0'
                                          , 'VR_5_all_mbl_0'
                                          ]
                           , samples = 'ttbar,Z,SingleTop,ttV,Diboson,Higgs'
                           , renamedRegions = { 'CR_top_all_mbl_0':'CR Top'
                                              , 'CR_Z_all_mbl_0':'CR Z'
                                              , 'VR_3_all_mbl_0':'VR Top'
                                              , 'VR_5_all_mbl_0':'VR Z'
                                              }
                           , outputPrefix = ''
                           # , doBlind = False
                           )


