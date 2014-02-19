#!/usr/bin/env python

import sys
import os
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
def runTntMaker(file_list, is_data = False, is_full_sim = False):
    # ==============================================================================
    if is_data == '0': is_data = False
    elif is_data == '1': is_data = True

    if is_full_sim == '0': is_full_sim = False
    elif is_full_sim == '1': is_full_sim = True

    # ==============================================================================
    root_core_dir = os.environ['ROOTCOREDIR']
    base_work_dir = os.environ['BASE_WORK_DIR']
    print 'loading packages'
    ROOT.gROOT.ProcessLine(".x %s/scripts/load_packages.C" % root_core_dir)
    print 'loading libraries'
    ROOT.gSystem.Load('%s/lib/libProgressBar.so' % base_work_dir)
    ROOT.gSystem.Load('%s/lib/libCutFlowTracker.so' % base_work_dir)
    ROOT.gSystem.Load('%s/lib/libPennSusyFrameCore.so' % base_work_dir)
    ROOT.gSystem.Load('%s/lib/libTntMaker.so' % base_work_dir)

    # ==============================================================================
    print "Adding files to TNT maker"
    t = ROOT.TChain('susy')
    for fl in file_list:
        print 'Adding file: %s' % fl
        t.AddFile(fl)

    # ==============================================================================
    tntm = ROOT.PennSusyFrame.TntMaker(t)
    if is_data:
        print 'setting as data'
        tntm.setIsData()
    else:
        print 'setting as mc'
        tntm.setIsMC()

    if is_full_sim:
        print 'mc is full sim'
        tntm.setFullSim()

    tntm.setCritCutIncompleteEvent(1)
    tntm.setCritCutLarError(       1)
    tntm.setCritCutTileError(      1)
    tntm.setCritCutTileHotSpot(    1)
    tntm.setCritCutTileTrip(       1)
    tntm.setCritCutBadJetVeto(     1)
    tntm.setCritCutCaloProblemJet( 1)
    tntm.setCritCutPrimaryVertex(  1)
    tntm.setCritCutBadMuonVeto(    1)
    tntm.setCritCutCosmicMuonVeto( 1)
    tntm.setCritCutHFOR(           1)
    tntm.setCritCutMcOverlap(      1)
    tntm.setCritCutGe2Lepton(      1)
    tntm.setCritCut2Lepton(        0)

    tntm.prepareTools()
    tntm.Loop()

    # ==============================================================================
    print ''
    print ''

# ------------------------------------------------------------------------------
def main():
    is_data = sys.argv[1]
    is_full_sim = sys.argv[2]
    input_list = sys.argv[3]

    print 'is_data: %s' % is_data
    print 'is_full_sim: %s' % is_full_sim
    print 'input_list: %s' % input_list

    file_list = getFileListFromGridInput(input_list)

    print 'file_list: %s' % file_list

    runTntMaker( file_list
               , is_data = is_data
               , is_full_sim = is_full_sim
               )

# ==============================================================================
if __name__ == '__main__':
    main()
