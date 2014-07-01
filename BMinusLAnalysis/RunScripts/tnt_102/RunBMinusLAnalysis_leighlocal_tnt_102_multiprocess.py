#!/usr/bin/env python

import os
from multiprocessing import Pool
import time
import sys
import datetime

sys.path.append('%s/BMinusLAnalysis/RunScripts/' % os.environ['BASE_WORK_DIR'])
import RunBMinusLAnalysis

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
    data_samples = {
                   }
    # full_sim_mc_samples = { # 110820:{'label':'110820.AlpgenPythia_P2011C_ZeebbNp3'    , 'num_jobs':1}
    #                         # 200334:{'label':'200334.AlpgenPythia_Auto_P2011C_ZeebbNp2'         , 'num_jobs':3}
    #                       }
    # fast_sim_mc_samples = { 202641:{'label':'202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000', 'num_jobs':1}
    #                       }
    full_sim_mc_samples = { }

    fast_sim_mc_samples = { # 105200:{'label':'105200.McAtNloJimmy_CT10_ttbar_LeptonFilter', 'num_jobs':15}
                             202632:{'label':'202632.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_100' , 'num_jobs':1}
                           , 202633:{'label':'202633.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_200' , 'num_jobs':1}
                           , 202634:{'label':'202634.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_300' , 'num_jobs':1}
                           , 202635:{'label':'202635.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_400' , 'num_jobs':1}
                           , 202636:{'label':'202636.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_500' , 'num_jobs':1}
                           , 202637:{'label':'202637.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_600' , 'num_jobs':1}
                           , 202638:{'label':'202638.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_700' , 'num_jobs':1}
                           , 202639:{'label':'202639.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_800' , 'num_jobs':1}
                           , 202640:{'label':'202640.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_900' , 'num_jobs':1}
                           , 202641:{'label':'202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000', 'num_jobs':1}
                          }

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # add data samples
    for dsid in data_samples:
        RunHelpers.addSamplesToList( sample_dict    = data_samples[dsid]
                                   , data_set_dicts = data_set_dicts
                                   , file_list_path = 'EosFileLists/local_leigh/tnt_102.%s.txt' % data_samples[dsid]['label']
                                   , is_data        = True
                                   , is_full_sim    = False
                                   , dsid           = dsid
                                   , out_dir        = out_dir
                                   )

    # add full sim samples
    for dsid in full_sim_mc_samples:
        RunHelpers.addSamplesToList( sample_dict    = full_sim_mc_samples[dsid]
                                   , data_set_dicts = data_set_dicts
                                   , file_list_path = 'EosFileLists/local_leigh/tnt_102.%s.txt' % full_sim_mc_samples[dsid]['label']
                                   , is_data        = False
                                   , is_full_sim    = True
                                   , dsid           = dsid
                                   , out_dir        = out_dir
                                   )

    # add fast sim samples
    for dsid in fast_sim_mc_samples:
        RunHelpers.addSamplesToList( sample_dict    = fast_sim_mc_samples[dsid]
                                   , data_set_dicts = data_set_dicts
                                   , file_list_path = 'EosFileLists/local_leigh/tnt_102.%s.txt' % fast_sim_mc_samples[dsid]['label']
                                   , is_data        = False
                                   , is_full_sim    = False
                                   , dsid           = dsid
                                   , out_dir        = out_dir
                                   )

    print data_set_dicts

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    p = Pool(num_processes)
    p.map(RunBMinusLAnalysis.runBMinusLAnalysisFun, data_set_dicts)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    RunHelpers.mergeOutputFiles(out_dir)
    RunHelpers.moveToLinkedDir(out_dir, './NextPlotDir.BMinusL')
