#!/usr/bin/env python

import sys
import os
import os.path
import optparse
import time
import math
import glob

import ROOT

sys.path.append('%s/CrossSectionReader/' % os.environ['BASE_WORK_DIR'])
import CrossSectionReader

sys.path.append('%s/RunHelpers/' % os.environ['BASE_WORK_DIR'])
import RunHelpers

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
def runBMinusLOptimizeNtupleMakerFun(data_set_dict):
    print '================================================================================'
    print 'label: %s'       % data_set_dict['label']
    print 'file_list: %s'   % data_set_dict['file_list']
    print 'is data: %s'     % data_set_dict['is_data']
    print 'is full sim: %s' % data_set_dict['is_full_sim']
    print 'dsid: %s'        % data_set_dict['dsid']

    print 'total number jobs: %s' % data_set_dict['total_num_jobs']
    print 'this job number: %s' % data_set_dict['job_num']

    print 'total num events: %s' % data_set_dict['total_num_events']
    print 'total num entries: %s' % data_set_dict['total_num_entries']

    print 'About to run BMinusLOptimizeNtupleMaker'
    runBMinusLOptimizeNtupleMaker( file_list             = data_set_dict['file_list']
                                 , is_data               = data_set_dict['is_data']
                                 , is_full_sim           = data_set_dict['is_full_sim']
                                 , tree_name             = 'TNT'
                                 , dsid                  = data_set_dict['dsid']
                                 , out_file_special_name = data_set_dict['label']
                                 , is_tnt                = True
                                 , fancy_progress_bar    = False
                                 , job_num               = data_set_dict['job_num']
                                 , total_num_jobs        = data_set_dict['total_num_jobs']
                                 , total_num_events      = data_set_dict['total_num_events']
                                 , total_num_entries     = data_set_dict['total_num_entries']
                                 , out_dir               = data_set_dict['out_dir']
                                 )

# ------------------------------------------------------------------------------
def runBMinusLOptimizeNtupleMaker( file_list
                                 , is_data
                                 , is_full_sim
                                 , tree_name             = 'susy'
                                 , dsid                  = 1
                                 , out_file_special_name = None
                                 , is_tnt                = False
                                 , fancy_progress_bar    = True
                                 , job_num               = 0
                                 , total_num_jobs        = 1
                                 , total_num_events      = 0
                                 , total_num_entries     = 0
                                 , out_dir               = './'
                                 ):
    # ==============================================================================
    # If the num events are not set and we are running over TNTs, get the total NumEvents
    print 'total num events: %s' % total_num_events
    if total_num_events == 0 and is_tnt:
        print 'Getting total num unskimmed events'
        print '  -- this is slow. you should do this once per data set - not for each stream!'
        total_num_events = getTotalNumEvents(file_list, is_tnt)

    print "Adding files to TChain"
    t = RunHelpers.getTChain(file_list, tree_name)

    # ==============================================================================
    print 'Creating BMinusLOptimizeNtupleMaker object'
    bmlonm = ROOT.PennSusyFrame.BMinusLOptimizeNtupleMaker(t)

    print 'configuring BMinusLOptimizeNtupleMaker object'
    if out_file_special_name is not None:
        bmlonm.setProcessLabel(out_file_special_name)
    bmlonm.setFancyProgressBar(False)

    # set is data or MC
    if is_data:
        bmlonm.setIsData()
    else:
        bmlonm.setIsMC()

        xsec_dict = CrossSectionReader.getCrossSection(dsid)
        if xsec_dict is None:
            return
        bmlonm.setCrossSection(xsec_dict['xsec'])
        bmlonm.setKFactor(     xsec_dict['kfac'])
        bmlonm.setFilterEff(   xsec_dict['eff'])

        bmlonm.setTotalNumEntries(    total_num_entries )
        bmlonm.setNumGeneratedEvents( total_num_events  )

    # set is full sim/fast sim
    if is_full_sim:
        bmlonm.setFullSim()

    # set start entry and max number events
    if total_num_jobs > 1:
        print 'total num jobs (%s) > 1' % total_num_jobs
        this_job_events = int(math.ceil( float(total_num_entries) / total_num_jobs ))
        this_job_start = job_num*this_job_events

        print 'total num entries; %s' % total_num_entries
        print 'setting max num events: %s' % this_job_events
        print type(this_job_events)
        bmlonm.setMaxNumEvents(this_job_events)
        print 'setting start entry: %s' % this_job_start
        bmlonm.setStartEntry(this_job_start)

    # set out histogram file name
    print 'setting histogram names'
    out_ntup_file_name = '%s/BMinusL.' % out_dir
    if out_file_special_name is not None:
        out_ntup_file_name += '%s.' % out_file_special_name
    out_ntup_file_name += 'ntup'
    if total_num_jobs > 1:
        out_ntup_file_name += '.%d_of_%d' % (job_num, total_num_jobs)
    out_ntup_file_name += '.root'
    bmlonm.setOutNtupleFileName(out_ntup_file_name)

    # Set critical cuts
    print 'setting critical cuts'
    bmlonm.setCritCutGrl(            1)
    bmlonm.setCritCutIncompleteEvent(1)
    bmlonm.setCritCutLarError(       1)
    bmlonm.setCritCutTileError(      1)
    bmlonm.setCritCutTileHotSpot(    1)
    bmlonm.setCritCutTileTrip(       1)
    bmlonm.setCritCutBadJetVeto(     1)
    bmlonm.setCritCutCaloProblemJet( 1)
    bmlonm.setCritCutPrimaryVertex(  1)
    bmlonm.setCritCutBadMuonVeto(    1)
    bmlonm.setCritCutCosmicMuonVeto( 1)
    bmlonm.setCritCutHFOR(           1)
    bmlonm.setCritCutMcOverlap(      1)
    bmlonm.setCritCutGe2Lepton(      1)
    bmlonm.setCritCut2Lepton(        0)
    bmlonm.setCritCut2SignalLepton(  0)
    bmlonm.setCritCut2BJets(         0)
    bmlonm.setCritCutBadJetVeto(     1)
    bmlonm.setCritCutBLPairing(      0)

    # Set cut values
    print 'set cuts'
    # lep_pt_cut = 40.e3
    # jet_pt_cut = 40.e3
    lep_pt_cut = 10.e3
    jet_pt_cut = 10.e3
    bmlonm.setElPtCut(  lep_pt_cut, -1     )
    bmlonm.setMuPtCut(  lep_pt_cut, -1     )
    bmlonm.setBJetPtCut(jet_pt_cut, -1     )
    # 80% working point
    bmlonm.setMV1Cut(0.3511)
    # 70% working point
    # bmlonm.setMV1Cut(0.7892)

    # prepare tools and run analysis loop
    print 'preparing tools'
    bmlonm.prepareTools()
    print 'looping -- %s' % out_file_special_name
    bmlonm.Loop()
    print 'done looping -- %s' % out_file_special_name

    # ==============================================================================
    print ''
    print ''
