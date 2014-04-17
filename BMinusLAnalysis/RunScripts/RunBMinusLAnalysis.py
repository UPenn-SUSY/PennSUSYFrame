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
        # file_list.append(l)
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
    t = ROOT.TChain(tree_name)
    for fl in file_list:
        print 'Adding file: %s' % fl
        t.AddFile(fl)
    return t

# # ------------------------------------------------------------------------------
# def getTotalNumEvents(file_list, is_tnt):
#     if not is_tnt:
#         return 0
# 
#     total_num_events = 0
#     # for fl in file_list:
#     #     print 'Getting number of events in file: %s' % fl
#     #     this_file = ROOT.TFile.Open(fl)
#     #     print 'type(file): %s' % type(this_file)
#     #     print this_file.Get('TotalNumEvents')
#     #     print int(this_file.Get('TotalNumEvents')[0])
#     #     print '\tNumber events in %s: %s' % (fl, int(this_file.Get('TotalNumEvents')[0]))
#     #     total_num_events += int(this_file.Get('TotalNumEvents')[0])
#     #     print '\ttotal number of events: %s' % total_num_events
#     #     this_file.Close()
#     print total_num_events
#     return total_num_events
# 
# # ------------------------------------------------------------------------------
# def getTotalNumEntries(file_list, is_tnt):
#     total_num_entries = 0
#     # for fl in file_list:
#     #     print 'Getting number of events in file: %s' % fl
#     #     this_file = ROOT.TFile.Open(fl)
#     #     this_tree = this_file.Get('TNT' if is_tnt else 'susy')
#     #     total_num_entries += this_tree.GetEntries()
#     #     this_file.Close()
#     print total_num_entries
#     return total_num_entries

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
    t = getTChain(file_list, tree_name)

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

        bmla.setTotalNumEntries( total_num_entries )
        bmla.setNumGeneratedEvents( total_num_events )

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
    out_hist_file_name = 'BMinusL.'
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
    bmla.setCritCut2Lepton(        1)
    bmla.setCritCut2SignalLepton(  1)
    bmla.setCritCut2BJets(         1)
    bmla.setCritCutBadJetVeto(     1)
    bmla.setCritCutBLPairing(      1)

    # Set cut values
    print 'set cuts'
    bmla.setElPtCut(  lep_pt_cut, -1     )
    bmla.setMuPtCut(  lep_pt_cut, -1     )
    bmla.setBJetPtCut(jet_pt_cut, -1     )
    bmla.setMetCut(   -1        , met_cut)

    # prepare tools and run analysis loop
    print 'preparing tools'
    bmla.prepareTools()
    print 'looping -- %s' % out_file_special_name
    bmla.Loop()
    print 'done looping -- %s' % out_file_special_name

    # ==============================================================================
    print ''
    print ''
