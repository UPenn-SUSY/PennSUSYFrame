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
def runEwkAnalysis( file_list
                  , is_data
                  , is_full_sim
                  , tree_name = 'susy'
                  , dsid = 1
                  , out_file_special_name = None
                  , is_tnt = False
                  ):
    # ==============================================================================
    print 'loading packages'
    ROOT.gROOT.ProcessLine(".x ${ROOTCOREDIR}/scripts/load_packages.C")
    print 'loading libraries'
    ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libProgressBar.so')
    ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libCutFlowTracker.so')
    ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libHistogramHandlers.so')
    ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libPennSusyFrameCore.so')
    ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libEwkAnalysis.so')

    # ==============================================================================
    print "Adding files to TChain"
    t = ROOT.TChain(tree_name)
    total_num_events = 0
    for fl in file_list:
        print 'Adding file: %s' % fl
        t.AddFile(fl)

        if is_tnt:
            this_file = ROOT.TFile(fl)
            total_num_events += int(this_file.Get('TotalNumEvents')[0])
            this_file.Close()

    # ==============================================================================
    ewa = ROOT.PennSusyFrame.EwkAnalysis(t)

    # set is data or MC
    if is_data:
        ewa.setIsData()
    else:
        ewa.setIsMC()

        xsec_dict = CrossSectionReader.getCrossSection(dsid)
        if xsec_dict is None:
            return
        ewk.setCrossSection(xsec_dict['xsec'])
        ewk.setKFactor(     xsec_dict['kfac'])
        ewk.setFilterEff(   xsec_dict['eff'])

        ewk.setNumGeneratedEvents( total_num_events )

    # set is full sim/fast sim
    if is_full_sim:
        ewa.setFullSim()

    # set out histogram file name
    out_hist_file_name = 'Ewk.'
    if out_file_special_name is not None:
        out_hist_file_name += '%s.' % out_file_special_name
    out_hist_file_name += 'hists.root'
    bmla.setOutHistFileName(out_hist_file_name)

    # Set critical cuts
    ewa.setCritCutGrl(            1)
    ewa.setCritCutIncompleteEvent(1)
    ewa.setCritCutLarError(       1)
    ewa.setCritCutTileError(      1)
    ewa.setCritCutTileHotSpot(    1)
    ewa.setCritCutTileTrip(       1)
    ewa.setCritCutBadJetVeto(     1)
    ewa.setCritCutCaloProblemJet( 1)
    ewa.setCritCutPrimaryVertex(  1)
    ewa.setCritCutBadMuonVeto(    1)
    ewa.setCritCutCosmicMuonVeto( 1)
    ewa.setCritCutHFOR(           1)
    ewa.setCritCutMcOverlap(      1)
    ewa.setCritCutGe2Lepton(      1)
    ewa.setCritCut2Lepton(        1)
    ewa.setCritCut2SignalLepton(  1)

    # prepare tools and run analysis loop
    ewa.prepareTools()
    ewa.Loop()

    # ==============================================================================
    print ''
    print ''
