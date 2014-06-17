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
def runBMinusLAnalysisFun(data_set_dict):
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

    print 'About to run BMinusLAnalysis'
    runBMinusLAnalysis( file_list             = data_set_dict['file_list']
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
def runBMinusLAnalysis( file_list
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
    print 'Creating BMinusLAnalysis object'
    bmla = ROOT.PennSusyFrame.BMinusLAnalysis(t)

    print 'configuring BMinusLAnalysis object'
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

        bmla.setTotalNumEntries(    total_num_entries )
        bmla.setNumGeneratedEvents( total_num_events  )

    # set is full sim/fast sim
    if is_full_sim:
        bmla.setFullSim()

    # set start entry and max number events
    if total_num_jobs > 1:
        print 'total num jobs (%s) > 1' % total_num_jobs
        this_job_events = int(math.ceil( float(total_num_entries) / total_num_jobs ))
        this_job_start = job_num*this_job_events

        print 'total num entries; %s' % total_num_entries
        print 'setting max num events: %s' % this_job_events
        print type(this_job_events)
        bmla.setMaxNumEvents(this_job_events)
        print 'setting start entry: %s' % this_job_start
        bmla.setStartEntry(this_job_start)

    # set out histogram file name
    print 'setting histogram names'
    out_hist_file_name = '%s/BMinusL.' % out_dir
    if out_file_special_name is not None:
        out_hist_file_name += '%s.' % out_file_special_name
    out_hist_file_name += 'hists'
    if total_num_jobs > 1:
        out_hist_file_name += '.%d_of_%d' % (job_num, total_num_jobs)
    out_hist_file_name += '.root'
    bmla.setOutHistFileName(out_hist_file_name)

    # Set critical cuts
    print 'setting critical cuts'
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
    bmla.setCritCut2Lepton(        0)
    bmla.setCritCut2SignalLepton(  0)
    bmla.setCritCut2BJets(         0)
    bmla.setCritCutBadJetVeto(     1)
    bmla.setCritCutBLPairing(      0)

    # Set cut values
    print 'set cuts'
    lep_pt_cut = 40.e3
    jet_pt_cut = 40.e3
    # lep_pt_cut = 10.e3
    # jet_pt_cut = 10.e3
    met_cut    = 50.e3
    bmla.setElPtCut(  lep_pt_cut, -1     )
    bmla.setMuPtCut(  lep_pt_cut, -1     )
    bmla.setBJetPtCut(jet_pt_cut, -1     )
    bmla.setMetCut(   -1        , met_cut)
    # 90% working point
    # bmla.setMV1Cut(0.0617)
    # 80% working point
    bmla.setMV1Cut(0.3511)
    # 70% working point
    # bmla.setMV1Cut(0.7892)

    # prepare tools and run analysis loop
    print 'preparing tools'
    bmla.prepareTools()
    print 'looping -- %s' % out_file_special_name
    bmla.Loop()
    print 'done looping -- %s' % out_file_special_name

    # ==============================================================================
    print ''
    print ''
