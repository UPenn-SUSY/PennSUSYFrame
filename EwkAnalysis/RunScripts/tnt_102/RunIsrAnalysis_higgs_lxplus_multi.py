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

today_date = datetime.datetime.now()
out_dir = 'hists/bminusl_hists_%04d_%02d_%02d__%02d_%02d' % ( today_date.year
                                                            , today_date.month
                                                            , today_date.day
                                                            , today_date.hour
                                                            , today_date.minute
                                                            )
print out_dir

# ==============================================================================
if __name__ == '__main__':
    RunHelpers.safeMakeDir(out_dir)

    print 'getting file list'
    data_set_dicts = []

    data_samples = {}

    full_sim_mc_samples = { 160155:{'label':'160155.PowhegPythia8_AU2CT10_ggH125_ZZ4lep'          , 'num_jobs':1}
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
