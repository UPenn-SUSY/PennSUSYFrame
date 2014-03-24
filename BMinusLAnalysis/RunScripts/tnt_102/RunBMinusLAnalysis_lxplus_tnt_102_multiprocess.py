#!/usr/bin/env python

import os
from multiprocessing import Pool
import time
import sys

sys.path.append('%s/BMinusLAnalysis/RunScripts/' % os.environ['BASE_WORK_DIR'])
import RunBMinusLAnalysis

# ------------------------------------------------------------------------------
# get number of parallel processes from command line inputs
num_processes = int(sys.argv[1]) if len(sys.argv) > 1 else 1

# ------------------------------------------------------------------------------
def runBMinusLAnalysisFun(data_set_dict):
    print 'label: %s'       % data_set_dict['label']
    print 'file_list: %s'   % data_set_dict['file_list']
    print 'is data: %s'     % data_set_dict['is_data']
    print 'is full sim: %s' % data_set_dict['is_full_sim']
    print 'dsid: %s'        % data_set_dict['dsid']

    print 'lep_pt_cut : %s' % data_set_dict['lep_pt_cut']
    print 'jet_pt_cut : %s' % data_set_dict['jet_pt_cut']
    print 'met_cut    : %s' % data_set_dict['met_cut']

    print 'total number jobs: %s' % data_set_dict['total_num_jobs']
    print 'this job number: %s' % data_set_dict['job_num']

    print 'About to run BMinusLAnalysis'
    RunBMinusLAnalysis.runBMinusLAnalysis( file_list             = data_set_dict['file_list']
                                         , is_data               = data_set_dict['is_data']
                                         , is_full_sim           = data_set_dict['is_full_sim']
                                         , tree_name             = 'TNT'
                                         , dsid                  = data_set_dict['dsid']
                                         , out_file_special_name = data_set_dict['label']
                                         , is_tnt                = True
                                         , lep_pt_cut            = data_set_dict['lep_pt_cut']
                                         , jet_pt_cut            = data_set_dict['jet_pt_cut']
                                         , met_cut               = data_set_dict['met_cut']
                                         , fancy_progress_bar    = False
                                         # , job_num = 0
                                         # , total_num_jobs = 2
                                         , job_num               = data_set_dict['job_num']
                                         , total_num_jobs        = data_set_dict['total_num_jobs']
                                         )

# ------------------------------------------------------------------------------
def makeDataSetDict( label_base
                   , file_list_path
                   , is_data
                   , is_full_sim
                   , dsid
                   , lep_pt_cut
                   , jet_pt_cut
                   , met_cut
                   , job_num=0
                   , total_num_jobs = 1
                   ):
    # label = '%s.%s' % (dsid, label_base)
    label = '%s' % (label_base)
    label += '__lep_pt_%s' % lep_pt_cut
    label += '__jet_pt_%s' % jet_pt_cut
    label += '__met_%s'    % met_cut

    return { 'label':label
           , 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/%s' % (os.environ['BASE_WORK_DIR'], file_list_path))
           , 'is_data':is_data
           , 'is_full_sim':is_full_sim
           , 'dsid':dsid
           , 'lep_pt_cut':lep_pt_cut
           , 'jet_pt_cut':jet_pt_cut
           , 'met_cut':met_cut
           , 'job_num':job_num
           , 'total_num_jobs':total_num_jobs
           }

# ==============================================================================
if __name__ == '__main__':
    print 'getting file list'

    met_cut    = 50.e3

    data_set_dicts = []
    # for lep_pt in [20.e3, 30.e3]:
    #     for jet_pt in [20.e3, 30.e3]:
    for lep_pt in [40.e3]:
        for jet_pt in [40.e3]:
            data_samples = {}
            full_sim_mc_samples = { # 110817:{'label':'110817.AlpgenPythia_P2011C_ZeebbNp0', 'num_jobs':1}
                                  # , 110818:{'label':'110818.AlpgenPythia_P2011C_ZeebbNp1', 'num_jobs':1}
                                  # , 110819:{'label':'110819.AlpgenPythia_P2011C_ZeebbNp2', 'num_jobs':1}
                                  # , 110820:{'label':'110820.AlpgenPythia_P2011C_ZeebbNp3', 'num_jobs':1}
                                  # , 110821:{'label':'110821.AlpgenPythia_P2011C_ZmumubbNp0', 'num_jobs':1}
                                  # , 110822:{'label':'110822.AlpgenPythia_P2011C_ZmumubbNp1', 'num_jobs':1}
                                  # , 110823:{'label':'110823.AlpgenPythia_P2011C_ZmumubbNp2', 'num_jobs':1}
                                  # , 110824:{'label':'110824.AlpgenPythia_P2011C_ZmumubbNp3', 'num_jobs':1}
                                  # , 110825:{'label':'110825.AlpgenPythia_P2011C_ZtautaubbNp0', 'num_jobs':1}
                                  # , 110826:{'label':'110826.AlpgenPythia_P2011C_ZtautaubbNp1', 'num_jobs':1}
                                  # , 110827:{'label':'110827.AlpgenPythia_P2011C_ZtautaubbNp2', 'num_jobs':1}
                                  # , 110828:{'label':'110828.AlpgenPythia_P2011C_ZtautaubbNp3', 'num_jobs':1}
                                  }
            fast_sim_mc_samples = { 105200:{'label':'105200.McAtNloJimmy_CT10_ttbar_LeptonFilter', 'num_jobs':4}
                                  }

            for dsid in data_samples:
                print dsid

            for dsid in full_sim_mc_samples:
                for jn in xrange(full_sim_mc_samples[dsid]['num_jobs']):
                    data_set_dicts.append( makeDataSetDict( label_base=full_sim_mc_samples[dsid]['label']
                                                        , file_list_path = 'EosFileLists/tnt_102/tnt_102.%s.txt' % full_sim_mc_samples[dsid]['label']
                                                        , is_data = False
                                                        , is_full_sim = True
                                                        , dsid = dsid
                                                        , lep_pt_cut = lep_pt
                                                        , jet_pt_cut = jet_pt
                                                        , met_cut = met_cut
                                                        , job_num = jn
                                                        , total_num_jobs = full_sim_mc_samples[dsid]['num_jobs']
                                                        )
                                        )

            for dsid in fast_sim_mc_samples:
                for jn in xrange(fast_sim_mc_samples[dsid]['num_jobs']):
                    data_set_dicts.append( makeDataSetDict( label_base=fast_sim_mc_samples[dsid]['label']
                                                        , file_list_path = 'EosFileLists/tnt_102/tnt_102.%s.txt' % fast_sim_mc_samples[dsid]['label']
                                                        , is_data = False
                                                        , is_full_sim = True
                                                        , dsid = dsid
                                                        , lep_pt_cut = lep_pt
                                                        , jet_pt_cut = jet_pt
                                                        , met_cut = met_cut
                                                        , job_num = jn
                                                        , total_num_jobs = fast_sim_mc_samples[dsid]['num_jobs']
                                                        )
                                        )

    p = Pool(num_processes)
    p.map(runBMinusLAnalysisFun, data_set_dicts)
