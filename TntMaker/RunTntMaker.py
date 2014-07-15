#!/usr/bin/env python

import sys
import os.path
import optparse
import time

import glob

import ROOT

sys.path.append('%s/RunHelpers/' % os.environ['BASE_WORK_DIR'])
import RunHelpers

# ------------------------------------------------------------------------------
def runTntMaker(file_list, is_data = False, is_full_sim = False):
    # ==============================================================================
    print 'loading packages'
    ROOT.gROOT.ProcessLine(".x ${ROOTCOREDIR}/scripts/load_packages.C")
    print 'loading libraries'
    ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libProgressBar.so')
    ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libCutFlowTracker.so')
    ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libPennSusyFrameCore.so')
    ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libTntMaker.so')

    # ==============================================================================
    print "Adding files to TNT maker"
    t = ROOT.TChain('susy')
    for fl in file_list:
        print 'Adding file: %s' % fl
        t.AddFile(fl)

    # ==============================================================================
    tntm = ROOT.PennSusyFrame.TntMaker(t)
    if is_data:
        tntm.setIsData()
    else:
        tntm.setIsMC()

    if is_full_sim:
        tntm.setFullSim()

    print 'setting critical cuts!'
    tntm.setCritCutIncompleteEvent(1)
    tntm.setCritCutLarError(       1)
    tntm.setCritCutTileError(      1)
    tntm.setCritCutTileHotSpot(    1)
    tntm.setCritCutTileTrip(       1)
    tntm.setCritCutBadJetVeto(     0)
    tntm.setCritCutCaloProblemJet( 0)
    tntm.setCritCutPrimaryVertex(  1)
    tntm.setCritCutBadMuonVeto(    0)
    tntm.setCritCutCosmicMuonVeto( 0)
    tntm.setCritCutHFOR(           1)
    tntm.setCritCutMcOverlap(      1)
    tntm.setCritCutGe2Lepton(      1)
    tntm.setCritCut2Lepton(        0)

    print 'preparing tools!'
    tntm.prepareTools()
    print 'looping'
    tntm.Loop()

    # ==============================================================================
    print ''
    print ''
