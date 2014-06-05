#!/usr/bin/env python

import os
from multiprocessing import Pool
import time
import sys
import datetime

sys.path.append('%s/EwkAnalysis/RunScripts/' % os.environ['BASE_WORK_DIR'])
import RunIsrAnalysis

sys.path.append('%s/RunHelpers/' % os.environ['BASE_WORK_DIR'])
import RunHelpers

# ------------------------------------------------------------------------------
# get number of parallel processes from command line inputs
num_processes = int(sys.argv[1]) if len(sys.argv) > 1 else 1

out_dir = 'hists/isr_hists%s' % RunHelpers.getDateTimeLabel(True, False)

# ==============================================================================
if __name__ == '__main__':
    RunHelpers.safeMakeDir(out_dir)

    print 'getting file list'
    data_set_dicts = []

    data_samples = { 'periodA_egamma':{'label':'periodA_egamma'   , 'num_jobs':10}
                   , 'periodB_egamma':{'label':'periodB_egamma' , 'num_jobs':10} ##THIS ONE
                   , 'periodC_egamma':{'label':'periodC_egamma' , 'num_jobs':10}
                   , 'periodD_egamma':{'label':'periodD_egamma' , 'num_jobs':10} ##THIS ONE TOO
                   , 'periodE_egamma':{'label':'periodE_egamma' , 'num_jobs':10}
                   , 'periodA_muon':{'label':'periodA_muon'     , 'num_jobs':10}
                   , 'periodB_muon':{'label':'periodB_muon'     , 'num_jobs':10}
                   , 'periodC_muon':{'label':'periodC_muon'     , 'num_jobs':10}
                   , 'periodD_muon':{'label':'periodD_muon'     , 'num_jobs':10}
                   , 'periodE_muon':{'label':'periodE_muon'     , 'num_jobs':10}
                   }

    full_sim_mc_samples = {}

    fast_sim_mc_samples = {}


    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # add data samples
    for dsid in data_samples:
        RunHelpers.addSamplesToList( sample_dict    = data_samples[dsid]
                                   , data_set_dicts = data_set_dicts
                                   , file_list_path = 'EosFileLists/tnt_102/tnt_102.%s.txt' % data_samples[dsid]['label']
                                   , is_data        = True
                                   , is_full_sim    = False
                                   , dsid           = dsid
                                   , out_dir        = out_dir
                                   )

    # add full sim samples
    for dsid in full_sim_mc_samples:
        RunHelpers.addSamplesToList( sample_dict    = full_sim_mc_samples[dsid]
                                   , data_set_dicts = data_set_dicts
                                   , file_list_path = 'EosFileLists/tnt_102/tnt_102.%s.txt' % full_sim_mc_samples[dsid]['label']
                                   , is_data        = False
                                   , is_full_sim    = True
                                   , dsid           = dsid
                                   , out_dir        = out_dir
                                   )

    # add fast sim samples
    for dsid in fast_sim_mc_samples:
        RunHelpers.addSamplesToList( sample_dict    = fast_sim_mc_samples[dsid]
                                   , data_set_dicts = data_set_dicts
                                   , file_list_path = 'EosFileLists/tnt_102/tnt_102.%s.txt' % fast_sim_mc_samples[dsid]['label']
                                   , is_data        = False
                                   , is_full_sim    = False
                                   , dsid           = dsid
                                   , out_dir        = out_dir
                                   )

    print data_set_dicts

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    p = Pool(num_processes)
    p.map(RunIsrAnalysis.runIsrAnalysisFun, data_set_dicts)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    RunHelpers.mergeOutputFiles(out_dir)
    RunHelpers.moveToLinkedDir(out_dir, './NextPlotDir.Isr')
