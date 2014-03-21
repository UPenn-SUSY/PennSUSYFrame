#!/usr/bin/env python

import sys
import os.path
import optparse
import time
import math

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
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libBMinusLAnalysis.so')
print 'done loading libraries'

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
def runBMinusLAnalysis( file_list
                      , is_data
                      , is_full_sim
                      , tree_name = 'susy'
                      , dsid = 1
                      , out_file_special_name = None
                      , is_tnt = False
                      # TODO make these cuts more maintainable
                      , lep_pt_cut = 40.e3
                      , jet_pt_cut = 40.e3
                      , met_cut    = 50.e3
                      , fancy_progress_bar = True
                      , job_num = 0
                      , total_num_jobs = 1
                      ):
    # ==============================================================================
    print "Adding files to TChain"
    t = ROOT.TChain(tree_name)
    total_num_events = 0
    for fl in file_list:
        print 'Adding file: %s' % fl
        t.AddFile(fl)

        if is_tnt:
            print 'getting number events in file: %s' % fl
            this_file = ROOT.TFile.Open(fl)
            total_num_events += int(this_file.Get('TotalNumEvents')[0])
            this_file.Close()
    total_raw_events = t.GetEntries()

    # ==============================================================================
    bmla = ROOT.PennSusyFrame.BMinusLAnalysis(t)

    if out_file_special_name is not None:
        bmla.setProcessLabel(out_file_special_name)
    bmla.setFancyProgressBar(False)

    # set is data or MC
    if is_data:
        bmla.setIsData()
    else:
        bmla.setIsMC()

        xsec_dict = CrossSectionReader.getCrossSection(dsid)
        if xsec_dict is None:
            return
        bmla.setCrossSection(xsec_dict['xsec'])
        bmla.setKFactor(     xsec_dict['kfac'])
        bmla.setFilterEff(   xsec_dict['eff'])

        bmla.setNumGeneratedEvents( total_num_events )

    # set is full sim/fast sim
    if is_full_sim:
        bmla.setFullSim()

    # set start entry and max number events
    if total_num_jobs > 1:
        this_job_events = int(math.ceil( float(total_raw_events) / total_num_jobs ))
        this_job_start = job_num*this_job_events

        print 'total raw num events; %s' % total_raw_events
        print 'setting max num events: %s' % this_job_events
        print type(this_job_events)
        bmla.setMaxNumEvents(this_job_events)
        print 'setting start entry: %s' % this_job_start
        bmla.setStartEntry(this_job_start)

    # set out histogram file name
    out_hist_file_name = 'BMinusL.'
    if out_file_special_name is not None:
        out_hist_file_name += '%s.' % out_file_special_name
    out_hist_file_name += 'hists'
    if total_num_jobs > 1:
        out_hist_file_name += '.%d_of_%d' % (job_num, total_num_jobs)
    out_hist_file_name += '.root'
    bmla.setOutHistFileName(out_hist_file_name)

    # Set critical cuts
    bmla.setCritCutGrl(            1)
    bmla.setCritCutIncompleteEvent(1)
    bmla.setCritCutLarError(       1)
    bmla.setCritCutTileError(      1)
    bmla.setCritCutTileHotSpot(    1)
    bmla.setCritCutTileTrip(       1)
    bmla.setCritCutBadJetVeto(     1)
    bmla.setCritCutCaloProblemJet( 1)
    bmla.setCritCutPrimaryVertex(  1)
    bmla.setCritCutBadMuonVeto(    1)
    bmla.setCritCutCosmicMuonVeto( 1)
    bmla.setCritCutHFOR(           1)
    bmla.setCritCutMcOverlap(      1)
    bmla.setCritCutGe2Lepton(      1)
    bmla.setCritCut2Lepton(        1)
    bmla.setCritCut2SignalLepton(  1)
    bmla.setCritCut2BJets(         1)
    bmla.setCritCutBadJetVeto(     1)
    bmla.setCritCutBLPairing(      1)

    # Set cut values
    bmla.setElPtCut(  lep_pt_cut, -1     )
    bmla.setMuPtCut(  lep_pt_cut, -1     )
    bmla.setBJetPtCut(jet_pt_cut, -1     )
    bmla.setMetCut(   -1        , met_cut)

    # prepare tools and run analysis loop
    bmla.prepareTools()
    bmla.Loop()

    # ==============================================================================
    print ''
    print ''
