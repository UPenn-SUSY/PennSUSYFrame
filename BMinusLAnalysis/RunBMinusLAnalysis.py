#!/usr/bin/env python

import sys
import os.path
import optparse
import time

import glob

import ROOT

# ------------------------------------------------------------------------------
def getFileListFromDir(file_path):
    print 'getting files from dir: %s' % file_path
    file_list = glob.glob('%s/*' % file_path)
    return file_list

# ------------------------------------------------------------------------------
def getFileListFromGridInput(grid_input_string):
    file_list = grid_input_string.split(',')
    return file_list

# ------------------------------------------------------------------------------
def runBMinusLAnalysis(file_list, is_data, is_full_sim, tree_name = 'susy'):
    # ==============================================================================
    print 'loading packages'
    ROOT.gROOT.ProcessLine(".x ${ROOTCOREDIR}/scripts/load_packages.C")
    print 'loading libraries'
    ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libProgressBar.so')
    ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libCutFlowTracker.so')
    ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libHistogramHandlers.so')
    ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libPennSusyFrameCore.so')
    ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libBMinusLAnalysis.so')

    # ==============================================================================
    print "Adding files to TNT maker"
    t = ROOT.TChain(tree_name)
    # t = ROOT.TChain("TNT")
    for fl in file_list:
        print 'Adding file: %s' % fl
        t.AddFile(fl)

    # ==============================================================================
    bmla = ROOT.PennSusyFrame.BMinusLAnalysis(t)
    if is_data:
        bmla.setIsData()
    else:
        bmla.setIsMC()

    if is_full_sim:
        bmla.setFullSim()
    bmla.prepareTools()
    bmla.Loop()

    # ==============================================================================
    print ''
    print ''

