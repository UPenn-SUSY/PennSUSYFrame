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
def runEwkAnalysis(file_list, is_data, is_full_sim):
    # ==============================================================================
    print 'loading packages'
    ROOT.gROOT.ProcessLine(".x ${ROOTCOREDIR}/scripts/load_packages.C")
    print 'loading libraries'
    ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libProgressBar.so')
    ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libCutFlowTracker.so')
    ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libPennSusyFrameCore.so')
    ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libEwkAnalysis.so')

    # ==============================================================================
    print "Adding files to TNT maker"
    t = ROOT.TChain("susy")
    # t = ROOT.TChain("TNT")
    for fl in file_list:
        print 'Adding file: %s' % fl
        t.AddFile(fl)

    # ==============================================================================
    ewa = ROOT.PennSusyFrame.EwkAnalysis(t)
    if is_data:
        ewa.setIsData()
    else:
        ewa.setIsMC()

    if is_full_sim:
        ewa.setFullSim()
    ewa.prepareTools()
    ewa.Loop()

    # ==============================================================================
    print ''
    print ''
