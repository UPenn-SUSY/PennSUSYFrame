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
# ntuple tree name
input_tree_name = 'TNT'
lep_pt_cut = 40.e3
jet_pt_cut = 40.e3

# 90% working point
# btag_working_point = 0.0617
# 80% working point
btag_working_point = 0.3511
# 70% working point
# btag_working_point = 0.7892

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
    print 'label: ', data_set_dict['label']
    print 'dsid: ', data_set_dict['dsid']

    print 'is data: ', data_set_dict['is_data']

    if data_set_dict['is_data']:
        print 'is egamma stream: ', data_set_dict['is_egamma_stream']
    else:
        print 'is full sim: ', data_set_dict['is_full_sim']

    print 'total number jobs: ', data_set_dict['total_num_jobs']
    print 'this job number: ', data_set_dict['job_num']

    print 'total num events: ', data_set_dict['total_num_events']
    print 'total num entries: ', data_set_dict['total_num_entries']
    print 'sum of event weights: ', data_set_dict['sum_mc_event_weights']

    print 'About to run BMinusLOptimizeNtupleMaker'
    runBMinusLOptimizeNtupleMaker( file_list             = data_set_dict['file_list']
                                 , is_data               = data_set_dict['is_data']
                                 , is_egamma_stream      = data_set_dict['is_egamma_stream']
                                 , is_full_sim           = data_set_dict['is_full_sim']
                                 , syst_struct           = data_set_dict['syst_struct']
                                 , tree_name             = input_tree_name
                                 , dsid                  = data_set_dict['dsid']
                                 , out_file_special_name = data_set_dict['label']
                                 , is_tnt                = True
                                 , fancy_progress_bar    = False
                                 , job_num               = data_set_dict['job_num']
                                 , total_num_jobs        = data_set_dict['total_num_jobs']
                                 , total_num_events      = data_set_dict['total_num_events']
                                 , total_num_entries     = data_set_dict['total_num_entries']
                                 , sum_mc_event_weights  = data_set_dict['sum_mc_event_weights']
                                 , out_dir               = data_set_dict['out_dir']
                                 )

# ------------------------------------------------------------------------------
def runBMinusLOptimizeNtupleMaker( file_list
                                 , is_data
                                 , is_egamma_stream
                                 , is_full_sim
                                 , syst_struct           = None
                                 , tree_name             = 'susy'
                                 , dsid                  = 1
                                 , out_file_special_name = None
                                 , is_tnt                = False
                                 , fancy_progress_bar    = True
                                 , job_num               = 0
                                 , total_num_jobs        = 1
                                 , total_num_events      = 0
                                 , total_num_entries     = 0
                                 , sum_mc_event_weights  = 0
                                 , out_dir               = './'
                                 ):
    # ==============================================================================
    # If the num events are not set and we are running over TNTs, get the total
    #   NumEvents
    print 'total num events: ', total_num_events
    if total_num_events == 0 and is_tnt:
        print 'Getting total num unskimmed events'
        print '  -- this is slow. you should do this once per data set - not for each stream!'
        total_num_events = getTotalNumEvents(file_list, is_tnt)

    print "Adding files to TChain"
    print '  Tree name: ' , tree_name
    t = RunHelpers.getTChain(file_list, tree_name)

    # ==============================================================================
    print 'Creating BMinusLOptimizeNtupleMaker object'
    bmlonm = ROOT.PennSusyFrame.BMinusLOptimizeNtupleMaker(t)

    print 'configuring BMinusLOptimizeNtupleMaker object'
    if out_file_special_name is not None:
        process_label = ''.join( [ out_file_special_name
                                 , '__'
                                 , str(job_num)
                                 , '_of_'
                                 , str(total_num_jobs)
                                 ]
                               )
        bmlonm.setProcessLabel(process_label)

    bmlonm.setFancyProgressBar(False)

    # set is data or MC
    #   if MC, we need to set various other things like cross section, k-factor, ...
    if is_data:
        bmlonm.setIsData()

        if is_egamma_stream:
            bmlonm.setIsEgammaStream()
        else:
            bmlonm.setIsMuonStream()
    else:
        bmlonm.setIsMC()

        xsec_dict = CrossSectionReader.getCrossSection(dsid)
        if xsec_dict is None:
            return
        bmlonm.setCrossSection(xsec_dict['xsec'])
        bmlonm.setKFactor(     xsec_dict['kfac'])
        bmlonm.setFilterEff(   xsec_dict['eff'])

        bmlonm.setTotalNumEntries(    total_num_entries    )
        bmlonm.setNumGeneratedEvents( total_num_events     )
        bmlonm.setSumMCEventWeights(  sum_mc_event_weights )

    # set is full sim/fast sim
    if is_full_sim:
        bmlonm.setFullSim()

    # set unblind!
    bmlonm.setIsBlind(False)

    # turn on systematics
    syst_tag = ''
    if syst_struct:
        print 'turning on systematics'
        syst_struct.configureAnalysisObject(bmlonm)

        syst_tag = ''.join([syst_struct.getRunName(), '.'])

    # set start entry and max number events
    if total_num_jobs > 1:
        print 'total num jobs (', total_num_jobs, ') > 1'
        this_job_events = int( math.ceil( float(total_num_entries)
                                        / total_num_jobs
                                        )
                             )
        this_job_start = job_num*this_job_events

        print 'total num entries: ', total_num_entries
        print 'setting max num events: ', this_job_events
        print type(this_job_events)
        bmlonm.setMaxNumEvents(this_job_events)
        print 'setting start entry: ', this_job_start
        bmlonm.setStartEntry(this_job_start)

    # set out ntuple file name
    # base name
    out_ntup_file_name = [out_dir, '/', 'BMinusL.', syst_tag]

    # append any special tags
    if out_file_special_name is not None:
        out_ntup_file_name.extend([out_file_special_name, '.'])

    # append 'ntup' tag
    out_ntup_file_name.append('ntup')

    # append job number
    if total_num_jobs > 1:
        out_ntup_file_name.extend( ['.'
                                   , str(job_num)
                                   , '_of_'
                                   , str(total_num_jobs)
                                   ]
                                 )

    # this is a root file
    out_ntup_file_name.append('.root')

    # set output file name in analyzer
    bmlonm.setOutNtupleFileName(''.join(out_ntup_file_name))

    # Set critical cuts
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
    bmlonm.setElPtCut(  lep_pt_cut, -1 )
    bmlonm.setMuPtCut(  lep_pt_cut, -1 )
    bmlonm.setBJetPtCut(jet_pt_cut, -1 )
    bmlonm.setMV1Cut(btag_working_point)

    # Turn on/off Z fudge factor
    # bmlonm.setDoZKFactor(True)
    bmlonm.setDoZKFactor(False)

    # prepare tools and run analysis loop
    print 'preparing tools'
    bmlonm.prepareTools()
    print 'looping -- ', out_file_special_name
    bmlonm.Loop()
    print 'done looping -- ', out_file_special_name

    # ==============================================================================
    print ''
    print ''
