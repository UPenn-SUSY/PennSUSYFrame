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
    label = '%s.%s' % (dsid, label_base)

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
    # full_sim_mc_samples = { 117650:{'label':'117650.AlpgenPythia_P2011C_ZeeNp0'       , 'num_jobs':10}
    full_sim_mc_samples = { 117650:{'label':'117650.AlpgenPythia_P2011C_ZeeNp0'       , 'num_jobs':1}
                          # , 117651:{'label':'117651.AlpgenPythia_P2011C_ZeeNp1'       , 'num_jobs':10}
                          # , 117652:{'label':'117652.AlpgenPythia_P2011C_ZeeNp2'       , 'num_jobs':5}
                          # , 117653:{'label':'117653.AlpgenPythia_P2011C_ZeeNp3'       , 'num_jobs':1}
                          # , 117654:{'label':'117654.AlpgenPythia_P2011C_ZeeNp4'       , 'num_jobs':1}
                          # , 117655:{'label':'117655.AlpgenPythia_P2011C_ZeeNp5'       , 'num_jobs':1}
                          # , 117660:{'label':'117660.AlpgenPythia_P2011C_ZmumuNp0'     , 'num_jobs':10}
                          # , 117661:{'label':'117661.AlpgenPythia_P2011C_ZmumuNp1'     , 'num_jobs':10}
                          # , 117662:{'label':'117662.AlpgenPythia_P2011C_ZmumuNp2'     , 'num_jobs':5}
                          # , 117663:{'label':'117663.AlpgenPythia_P2011C_ZmumuNp3'     , 'num_jobs':1}
                          # , 117664:{'label':'117664.AlpgenPythia_P2011C_ZmumuNp4'     , 'num_jobs':1}
                          # , 117665:{'label':'117665.AlpgenPythia_P2011C_ZmumuNp5'     , 'num_jobs':1}
                          }
    fast_sim_mc_samples = {}


    for dsid in data_samples:
        print dsid
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
    p.map(runIsrAnalysisFun, data_set_dicts)





    # data_set_dicts.append( makeDataSetDict(label_base='ZeeNp0'     , file_list_path = eos_base_path + 'mc12_8TeV.117650.AlpgenPythia_P2011C_ZeeNp0*/', is_data = False , is_full_sim = True , dsid = 117650 ) )
    # data_set_dicts.append( makeDataSetDict(label_base='ZeeNp1'     , file_list_path = eos_base_path + 'mc12_8TeV.117651.AlpgenPythia_P2011C_ZeeNp1*/', is_data = False , is_full_sim = True , dsid = 117651 ) )
    # data_set_dicts.append( makeDataSetDict(label_base='ZeeNp2'     , file_list_path = eos_base_path + 'mc12_8TeV.117652.AlpgenPythia_P2011C_ZeeNp2*/', is_data = False , is_full_sim = True , dsid = 117652 ) )
    # data_set_dicts.append( makeDataSetDict(label_base='ZeeNp3'     , file_list_path = eos_base_path + 'mc12_8TeV.117653.AlpgenPythia_P2011C_ZeeNp3*/', is_data = False , is_full_sim = True , dsid = 117653 ) )
    # data_set_dicts.append( makeDataSetDict(label_base='ZeeNp4'     , file_list_path = eos_base_path + 'mc12_8TeV.117654.AlpgenPythia_P2011C_ZeeNp4*/', is_data = False , is_full_sim = True , dsid = 117654 ) )
    # data_set_dicts.append( makeDataSetDict(label_base='ZeeNp5'     , file_list_path = eos_base_path + 'mc12_8TeV.117655.AlpgenPythia_P2011C_ZeeNp5*/', is_data = False , is_full_sim = True , dsid = 117655 ) )
   
    # data_set_dicts.append( makeDataSetDict(label_base='ZmumuNp0'     , file_list_path = eos_base_path + 'mc12_8TeV.117660.AlpgenPythia_P2011C_ZmumuNp0*/', is_data = False , is_full_sim = True , dsid = 117660 ) )
    # data_set_dicts.append( makeDataSetDict(label_base='ZmumuNp1'     , file_list_path = eos_base_path + 'mc12_8TeV.117661.AlpgenPythia_P2011C_ZmumuNp1*/', is_data = False , is_full_sim = True , dsid = 117661 ) )
    # data_set_dicts.append( makeDataSetDict(label_base='ZmumuNp2'     , file_list_path = eos_base_path + 'mc12_8TeV.117662.AlpgenPythia_P2011C_ZmumuNp2*/', is_data = False , is_full_sim = True , dsid = 117662 ) )
    # data_set_dicts.append( makeDataSetDict(label_base='ZmumuNp3'     , file_list_path = eos_base_path + 'mc12_8TeV.117663.AlpgenPythia_P2011C_ZmumuNp3*/', is_data = False , is_full_sim = True , dsid = 117663 ) )
    # data_set_dicts.append( makeDataSetDict(label_base='ZmumuNp4'     , file_list_path = eos_base_path + 'mc12_8TeV.117664.AlpgenPythia_P2011C_ZmumuNp4*/', is_data = False , is_full_sim = True , dsid = 117664 ) )
    # data_set_dicts.append( makeDataSetDict(label_base='ZmumuNp5'     , file_list_path = eos_base_path + 'mc12_8TeV.117665.AlpgenPythia_P2011C_ZmumuNp5*/', is_data = False , is_full_sim = True , dsid = 117665 ) )

    # p = Pool(num_processes)
    # p.map(runIsrAnalysisFun, data_set_dicts)

