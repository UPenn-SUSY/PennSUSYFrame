#!/usr/bin/env python

import RunIsrAnalysis
import os
from multiprocessing import Pool
import time
import sys

# ------------------------------------------------------------------------------
# get number of parallel processes from command line inputs
num_processes = int(sys.argv[1]) if len(sys.argv) > 1 else 1

# ------------------------------------------------------------------------------
def runIsrAnalysisFun(data_set_dict):
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

    print 'About to run IsrAnalysis'
    RunIsrAnalysis.runIsrAnalysis( file_list             = data_set_dict['file_list']
                                 , is_data               = data_set_dict['is_data']
                                 , is_full_sim           = data_set_dict['is_full_sim']
                                 , tree_name             = 'TNT'
                                 # , tree_name             = 'susy'
                                 , dsid                  = data_set_dict['dsid']
                                 , out_file_special_name = data_set_dict['label']
                                 , is_tnt                = False
                                 , fancy_progress_bar    = False
                                 , job_num               = data_set_dict['job_num']
                                 , total_num_jobs        = data_set_dict['total_num_jobs']
                                 , total_num_events      = data_set_dict['total_num_events']
                                 , total_num_entries     = data_set_dict['total_num_entries']
                                 )

#------------------------------------------------------------------------------
def makeDataSetDict( label_base
                   , file_list_path
                   , is_data
                   , is_full_sim
                   , dsid
                   , job_num=0
                   , total_num_jobs = 1
                   ):

##    if(is_data == True):
##        label = '%s' % label_base
##    else:
##        label = '%s.%s' % (dsid, label_base)
##

    label = '%s' % label_base

    data_set_input = RunIsrAnalysis.readFileList('%s/%s' % (os.environ['BASE_WORK_DIR'], file_list_path))
    file_list = data_set_input['file_list']

    return { 'label':label
           # , 'file_list':RunIsrAnalysis.getFileListFromDir(file_list_path)
           , 'file_list':file_list
           , 'is_data':is_data
           , 'is_full_sim':is_full_sim
           , 'dsid':dsid
           , 'job_num':job_num
           , 'total_num_jobs':total_num_jobs
           }

# ------------------------------------------------------------------------------
def makeDataSetDictList( label_base
                       , file_list_path
                       , is_data
                       , is_full_sim
                       , dsid
                       , total_num_jobs = 1
                       ):
    total_num_entries = 0

    print 'getting raw events for %s' % label_base
    data_set_input = RunIsrAnalysis.readFileList('%s/%s' % (os.environ['BASE_WORK_DIR'], file_list_path))
    file_list         = data_set_input['file_list']
    total_num_events  = data_set_input['total_num_events']
    total_num_entries = data_set_input['total_entries']

    print 'total num events: %s' % total_num_events
    print 'total entries: %s' % total_num_entries

    data_set_dict_list = []
    for tnj in xrange(total_num_jobs):
        this_data_set_dict = makeDataSetDict( label_base     = label_base
                                            , file_list_path = file_list_path
                                            , is_data        = is_data
                                            , is_full_sim    = is_full_sim
                                            , dsid           = dsid
                                            , job_num        = tnj
                                            , total_num_jobs = total_num_jobs
                                            )
        this_data_set_dict['total_num_events']  = total_num_events
        this_data_set_dict['total_num_entries'] = total_num_entries
        data_set_dict_list.append(this_data_set_dict)

    return data_set_dict_list


# ==============================================================================
if __name__ == '__main__':
    print 'getting file list'

    eos_base_path = '/afs/cern.ch/user/e/ehines/eos_mount/atlas/user/b/bjackson/mc12/'

    data_set_dicts = []

    data_samples = {}
    
    #full_sim_mc_samples = { 117655:{'label':'117655.AlpgenPythia_P2011C_ZeeNp5'       , 'num_jobs':1}
    full_sim_mc_samples = {160155:{'label':'160155.PowhegPythia8_AU2CT10_ggH125_ZZ4lep'          , 'num_jobs':1}
        , 160205:{'label':'160205.PowhegPythia8_AU2CT10_VBFH125_ZZ4lep'         , 'num_jobs':1}
        , 160255:{'label':'160255.Pythia8_AU2CTEQ6L1_WH125_ZZ4lep'              , 'num_jobs':1}
        , 160305:{'label':'160305.Pythia8_AU2CTEQ6L1_ZH125_ZZ4lep'              , 'num_jobs':1}
        , 160655:{'label':'160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu'        , 'num_jobs':1}
        , 160705:{'label':'160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu'       , 'num_jobs':1}
        , 160755:{'label':'160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu'            , 'num_jobs':1}
        , 160805:{'label':'160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu'            , 'num_jobs':1}
        , 161005:{'label':'161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5'  , 'num_jobs':1}
        , 161055:{'label':'161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5' , 'num_jobs':1}
        , 161105:{'label':'161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep'              , 'num_jobs':1}
        , 161155:{'label':'161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep'              , 'num_jobs':1}
                           }

    fast_sim_mc_samples = {}


    for dsid in data_samples:
        
        these_data_set_dicts = makeDataSetDictList( label_base=data_samples[dsid]['label']
                                                    , file_list_path = 'EosFileLists/tnt_102/tnt_102.%s.txt' % data_samples[dsid]['label']
                                                    , is_data = True
                                                    , is_full_sim = False
                                                    , dsid = 1
                                                    , total_num_jobs = data_samples[dsid]['num_jobs']
                                                    )
        for tdsd in these_data_set_dicts:
            data_set_dicts.append(tdsd)
                                                    
        # TODO add stuff for data samples!

    for dsid in full_sim_mc_samples:
        these_data_set_dicts = makeDataSetDictList( label_base=full_sim_mc_samples[dsid]['label']
                                                  , file_list_path = 'EosFileLists/tnt_102/tnt_102.%s.txt' % full_sim_mc_samples[dsid]['label']
                                                  , is_data = False
                                                  , is_full_sim = True
                                                  , dsid = dsid
                                                  , total_num_jobs = full_sim_mc_samples[dsid]['num_jobs']
                                                  )

        for tdsd in these_data_set_dicts:
            data_set_dicts.append(tdsd)

    for dsid in fast_sim_mc_samples:
        these_data_set_dicts = makeDataSetDictList( label_base=fast_sim_mc_samples[dsid]['label']
                                                  , file_list_path = 'EosFileLists/tnt_102/tnt_102.%s.txt' % fast_sim_mc_samples[dsid]['label']
                                                  , is_data = False
                                                  , is_full_sim = False
                                                  , dsid = dsid
                                                  , total_num_jobs = fast_sim_mc_samples[dsid]['num_jobs']
                                                  )

        for tdsd in these_data_set_dicts:
            data_set_dicts.append(tdsd)

    print data_set_dicts

    p = Pool(num_processes)
    print 'BOB'
    p.map(runIsrAnalysisFun, data_set_dicts)
    print 'Done'
