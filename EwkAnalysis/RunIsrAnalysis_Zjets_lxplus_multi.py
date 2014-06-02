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
    full_sim_mc_samples = {##117650:{'label':'117650.AlpgenPythia_P2011C_ZeeNp0'         , 'num_jobs':10}
                           ##, 117651:{'label':'117651.AlpgenPythia_P2011C_ZeeNp1'       , 'num_jobs':10}
                           ##, 117652:{'label':'117652.AlpgenPythia_P2011C_ZeeNp2'       , 'num_jobs':5}
                           ##, 117653:{'label':'117653.AlpgenPythia_P2011C_ZeeNp3'       , 'num_jobs':1}
                           ##, 117654:{'label':'117654.AlpgenPythia_P2011C_ZeeNp4'       , 'num_jobs':1}
                           ##, 117655:{'label':'117655.AlpgenPythia_P2011C_ZeeNp5'       , 'num_jobs':1}
                           ##
                           ##, 117660:{'label':'117660.AlpgenPythia_P2011C_ZmumuNp0'     , 'num_jobs':10}
                           ##, 117661:{'label':'117661.AlpgenPythia_P2011C_ZmumuNp1'     , 'num_jobs':10}
                           ##, 117662:{'label':'117662.AlpgenPythia_P2011C_ZmumuNp2'     , 'num_jobs':5}
                           ##, 117663:{'label':'117663.AlpgenPythia_P2011C_ZmumuNp3'     , 'num_jobs':1}
                           ##, 117664:{'label':'117664.AlpgenPythia_P2011C_ZmumuNp4'     , 'num_jobs':1}
                           ##, 117665:{'label':'117665.AlpgenPythia_P2011C_ZmumuNp5'     , 'num_jobs':1}



                        ##     , 110805:{'label':'110805.AlpgenPythia_P2011C_ZeeccNp0'     , 'num_jobs':1}
                        ##     , 110806:{'label':'110806.AlpgenPythia_P2011C_ZeeccNp1'     , 'num_jobs':1}
                        ##     , 110807:{'label':'110807.AlpgenPythia_P2011C_ZeeccNp2'     , 'num_jobs':1}
                        ##     , 110808:{'label':'110808.AlpgenPythia_P2011C_ZeeccNp3'     , 'num_jobs':1}
                        ##     
                        ##     , 110817:{'label':'110817.AlpgenPythia_P2011C_ZeebbNp0'     , 'num_jobs':1}
                        ##     , 110818:{'label':'110818.AlpgenPythia_P2011C_ZeebbNp1'     , 'num_jobs':1}
                        ##     , 110819:{'label':'110819.AlpgenPythia_P2011C_ZeebbNp2'     , 'num_jobs':1}
                        ##     , 110820:{'label':'110820.AlpgenPythia_P2011C_ZeebbNp3'     , 'num_jobs':1}
                        ##     
                        ##     , 110809:{'label':'110809.AlpgenPythia_P2011C_ZmumuccNp0'   , 'num_jobs':1}
                        ##     , 110810:{'label':'110810.AlpgenPythia_P2011C_ZmumuccNp1'   , 'num_jobs':1}
                        ##     , 110811:{'label':'110811.AlpgenPythia_P2011C_ZmumuccNp2'   , 'num_jobs':1}
                        ##     , 110812:{'label':'110812.AlpgenPythia_P2011C_ZmumuccNp3'   , 'num_jobs':1}
                        ##  
                        ##     , 110821:{'label':'110821.AlpgenPythia_P2011C_ZmumubbNp0'    , 'num_jobs':1}                               
                        ##     , 110822:{'label':'110822.AlpgenPythia_P2011C_ZmumubbNp1'    , 'num_jobs':1}                               
                        ##     , 110823:{'label':'110823.AlpgenPythia_P2011C_ZmumubbNp2'    , 'num_jobs':1}                               
                        ##     , 110824:{'label':'110824.AlpgenPythia_P2011C_ZmumubbNp3'    , 'num_jobs':1} 

                             117670:{'label':'117670.AlpgenPythia_P2011C_ZtautauNp0'     , 'num_jobs':10}  
                            , 117671:{'label':'117671.AlpgenPythia_P2011C_ZtautauNp1'     , 'num_jobs':10}  
                            , 117672:{'label':'117672.AlpgenPythia_P2011C_ZtautauNp2'     , 'num_jobs':5}  
                            , 117673:{'label':'117673.AlpgenPythia_P2011C_ZtautauNp3'     , 'num_jobs':1}  
                            , 117674:{'label':'117674.AlpgenPythia_P2011C_ZtautauNp4'     , 'num_jobs':1}
                            , 117675:{'label':'117675.AlpgenPythia_P2011C_ZtautauNp5'     , 'num_jobs':1}
                         
                            , 110813:{'label':'110813.AlpgenPythia_P2011C_ZtautauccNp0'   , 'num_jobs':1}  
                            , 110814:{'label':'110814.AlpgenPythia_P2011C_ZtautauccNp1'   , 'num_jobs':1}
                            , 110815:{'label':'110815.AlpgenPythia_P2011C_ZtautauccNp2'   , 'num_jobs':1}
                            , 110816:{'label':'110816.AlpgenPythia_P2011C_ZtautauccNp3'   , 'num_jobs':1}
                         
                            , 110825:{'label':'110825.AlpgenPythia_P2011C_ZtautaubbNp0'   , 'num_jobs':1}
                            , 110826:{'label':'110826.AlpgenPythia_P2011C_ZtautaubbNp1'   , 'num_jobs':1}
                            , 110827:{'label':'110827.AlpgenPythia_P2011C_ZtautaubbNp2'   , 'num_jobs':1}
                            , 110828:{'label':'110828.AlpgenPythia_P2011C_ZtautaubbNp3'   , 'num_jobs':1}


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
    p.map(runIsrAnalysisFun, data_set_dicts)

