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
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libEwkAnalysis.so')
print 'done loading libraries'

# ------------------------------------------------------------------------------
def getFileListFromDir(file_path):
    print 'getting files from dir: %s' % file_path
    file_list = glob.glob('%s/*' % file_path)
    return file_list

# ------------------------------------------------------------------------------
def readFileList(file_path):
    file_list = []
    total_num_events = 0
    total_entries = 0

    print 'reading file: %s' % file_path
    f = file(file_path)
    for l in f.readlines():
        l = l.strip('\n')
        # file_list.append(l)
        splits = l.split()
        print splits
        file_list.append( splits[0])
        total_num_events += int(splits[1])
        total_entries    += int(splits[2])

    return { 'file_list':file_list
           , 'total_num_events':total_num_events
           , 'total_entries':total_entries
           }

# ------------------------------------------------------------------------------
def getFileListFromFile(file_path):
    file_list = []

    f = file(file_path)
    for l in f.readlines():
        l = l.strip('\n')
        splits = l.split()
        file_list.append( { 'file_name':splits[0]
                          , 'total_num_events':splits[1]
                          , 'total_entries':splits[2]
                          }
                        )

    return file_list

# ------------------------------------------------------------------------------
def getFileListFromGridInput(grid_input_string):
    file_list = grid_input_string.split(',')
    return file_list

# ------------------------------------------------------------------------------
def getTChain(file_list, tree_name):
    print 'getTChain()'
    t = ROOT.TChain(tree_name)
    for fl in file_list:
        print 'Adding file: %s' % fl
        t.AddFile(fl)
    return t

# ------------------------------------------------------------------------------
def runIsrAnalysis( file_list
                  , is_data
                  , is_full_sim
                  , tree_name = 'susy'
                  , dsid = 1
                  , out_file_special_name = None
                  , is_tnt = False
                  , fancy_progress_bar = True
                  , job_num = 0
                  , total_num_jobs = 1
                  , total_num_events = 0
                  , total_num_entries = 0
                  ):
    # ==============================================================================
    # If the num events are not set and we are running over TNTs, get the total NumEvents
    print 'total num events: %s' % total_num_events
    if total_num_events == 0 and is_tnt:
        print 'Getting total num unskimmed events -- this is slow. you should do this once per data set - not for each stream!'
        total_num_events = getTotalNumEvents(file_list, is_tnt)

    print "Adding files to TChain"
    print 'file_list: %s' % file_list
    t = getTChain(file_list, tree_name)

    # ==============================================================================
    print 'Creating IsrAnalysis object'
    isra = ROOT.PennSusyFrame.IsrAnalysis(t)

    print 'configuring IsrAnalysis object'
    if out_file_special_name is not None:
        isra.setProcessLabel(out_file_special_name)
    isra.setFancyProgressBar(False)

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

        isra.setTotalNumEntries( total_num_entries )
        isra.setNumGeneratedEvents( total_num_events )

    # set is full sim/fast sim
    if is_full_sim:
        isra.setFullSim()

    # set start entry and max number events
    if total_num_jobs > 1:
        print 'total num jobs (%s) > 1' % total_num_jobs
        this_job_events = int(math.ceil( float(total_num_entries) / total_num_jobs ))
        this_job_start = job_num*this_job_events

        print 'total num entries; %s' % total_num_entries
        print 'setting max num events: %s' % this_job_events
        print type(this_job_events)
        isra.setMaxNumEvents(this_job_events)
        print 'setting start entry: %s' % this_job_start
        isra.setStartEntry(this_job_start)

    # set out histogram file name
    print 'setting histogram names'
    out_hist_file_name = 'Isr.'
    if out_file_special_name is not None:
        out_hist_file_name += '%s.' % out_file_special_name
    out_hist_file_name += 'hists'
    if total_num_jobs > 1:
        out_hist_file_name += '.%d_of_%d' % (job_num, total_num_jobs)
    out_hist_file_name += '.root'
    isra.setOutHistFileName(out_hist_file_name)

    # Set critical cuts
    print 'setting critical cuts'
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
    print 'preparing tools'
    isra.prepareTools()
    print 'looping -- %s' % out_file_special_name
    isra.Loop()
    print 'done looping -- %s' % out_file_special_name

    # ==============================================================================
    print ''
    print ''
