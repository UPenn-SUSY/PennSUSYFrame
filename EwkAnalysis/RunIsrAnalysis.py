#!/usr/bin/env python

import sys
import os.path
import optparse
import time

import glob

import ROOT

import os
sys.path.append('%s/CrossSectionReader/' % os.environ['BASE_WORK_DIR'])
import CrossSectionReader

# ==============================================================================
print 'loading packages'
ROOT.gROOT.ProcessLine(".x ${ROOTCOREDIR}/scripts/load_packages.C")
print 'loading libraries'
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libProgressBar.so')
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libCutFlowTracker.so')
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libHistogramHandlers.so')
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libPennSusyFrameCore.so')
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libEwkAnalysis.so')

# ------------------------------------------------------------------------------
def getFileListFromDir(file_path):
    print 'getting files from dir: %s' % file_path
    file_list = glob.glob('%s/*' % file_path)
    return file_list

# ------------------------------------------------------------------------------
def getFileListFromFile(file_path):
    file_list = []

    f = file(file_path)
    for l in f.readlines():
        l = l.strip('\n')
        file_list.append(l)

    return file_list

# ------------------------------------------------------------------------------
def getFileListFromGridInput(grid_input_string):
    file_list = grid_input_string.split(',')
    return file_list

# ------------------------------------------------------------------------------
def runIsrAnalysis( file_list
                  , is_data
                  , is_full_sim
                  , tree_name = 'susy'
                  , dsid = 1
                  , out_file_special_name = None
                  , is_tnt = False
                  , fancy_progress_bar = True  
                  ):
    # ==============================================================================
    print "Adding files to TChain"
    t = ROOT.TChain(tree_name)
    # t = ROOT.TChain("TNT")
    total_num_events = 0;
    for fl in file_list:
        print 'Adding file: %s' % fl
        t.AddFile(fl)

        if is_tnt:
            this_file = ROOT.TFile.Open(fl)
            this_file.ls()
            total_num_events += int(this_file.Get('TotalNumEvents')[0])
            this_file.Close()

    # ==============================================================================
    isra = ROOT.PennSusyFrame.IsrAnalysis(t)

    # set is data or MC
    if is_data:
        isra.setIsData()
    else:
        isra.setIsMC()

        xsec_dict = CrossSectionReader.getCrossSection(dsid)
        if xsec_dict is None:
            return
        isra.setCrossSection(xsec_dict['xsec'])
        isra.setKFactor(     xsec_dict['kfac'])
        isra.setFilterEff(   xsec_dict['eff'])

        isra.setNumGeneratedEvents( total_num_events )

    # set is full sim/fast sim
    if is_full_sim:
        isra.setFullSim()

    # set out histogram file name
    out_hist_file_name = 'Isr.'
    if out_file_special_name is not None:
        out_hist_file_name += '%s.' % out_file_special_name
    out_hist_file_name += 'hists.root'
    isra.setOutHistFileName(out_hist_file_name)

    # isra.setCritCutGrl(            1)
    # isra.setCritCutIncompleteEvent(1)
    # isra.setCritCutLarError(       1)
    # isra.setCritCutTileError(      1)
    # isra.setCritCutTileHotSpot(    1)
    # isra.setCritCutTileTrip(       1)
    # isra.setCritCutBadJetVeto(     1)
    # isra.setCritCutCaloProblemJet( 1)
    # isra.setCritCutPrimaryVertex(  1)
    # isra.setCritCutBadMuonVeto(    1)
    # isra.setCritCutCosmicMuonVeto( 1)
    # isra.setCritCutHFOR(           1)
    # isra.setCritCutMcOverlap(      1)
    # isra.setCritCutGe2Lepton(      1)
    # isra.setCritCut2Lepton(        1)
    # isra.setCritCut2SignalLepton(  1)

    # prepare tools and run analysis loop
    isra.prepareTools()
    isra.Loop()

    # ==============================================================================
    print ''
    print ''
