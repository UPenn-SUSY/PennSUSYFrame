#!/usr/bin/env python

import os
from multiprocessing import Pool
import time
import sys
import datetime

sys.path.append('%s/BMinusLAnalysis/RunScripts/' % os.environ['BASE_WORK_DIR'])
import RunBMinusLOptimizeNtupleMaker

sys.path.append('%s/RunHelpers/' % os.environ['BASE_WORK_DIR'])
import RunHelpers

# ------------------------------------------------------------------------------
# get number of parallel processes from command line inputs
user_input = sys.argv[1] if len(sys.argv) > 1 else 1
num_processes = 1
queue = '1nh'
if "nm" in user_input or "nh" in user_input or "nd" in user_input:
    queue = user_input
    run_local = False
else:
    num_processes = int(user_input)
    run_local = True

today_date = datetime.datetime.now()
out_dir = '%s/hists/bminusl_opt_ntup_%04d_%02d_%02d__%02d_%02d' % ( os.environ['PWD']
                                                                  , today_date.year
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

    data_samples = {
                   #   'periodA_egamma':{'label':'periodA_egamma'   , 'num_jobs':10}
                   # , 'periodB_egamma':{'label':'periodB_egamma' , 'num_jobs':10} ##THIS ONE
                   # , 'periodC_egamma':{'label':'periodC_egamma' , 'num_jobs':10}
                   # , 'periodD_egamma':{'label':'periodD_egamma' , 'num_jobs':10} ##THIS ONE TOO
                   # , 'periodE_egamma':{'label':'periodE_egamma' , 'num_jobs':10}
                   # , 'periodA_muon':{'label':'periodA_muon'     , 'num_jobs':10}
                   # , 'periodB_muon':{'label':'periodB_muon'     , 'num_jobs':10}
                   # , 'periodC_muon':{'label':'periodC_muon'     , 'num_jobs':10}
                   # , 'periodD_muon':{'label':'periodD_muon'     , 'num_jobs':10}
                   # , 'periodE_muon':{'label':'periodE_muon'     , 'num_jobs':10}
                   }
    full_sim_mc_samples = {
                          }
    fast_sim_mc_samples = {
                            117050:{'label':'117050.PowhegPythia_P2011C_ttbar.af2_v2'                  , 'num_jobs':50}
                          , 110141:{'label':'110141.PowhegPythia_P2011C_st_Wtchan_dilepton_DR'         , 'num_jobs':30}
                          , 167749:{'label':'167749.Sherpa_CT10_ZeeMassiveCBPt0_BFilter'               , 'num_jobs':30}
                          , 167752:{'label':'167752.Sherpa_CT10_ZmumuMassiveCBPt0_BFilter'             , 'num_jobs':30}
                          , 167755:{'label':'167755.Sherpa_CT10_ZtautauMassiveCBPt0_BFilter'           , 'num_jobs':5}
                          , 167797:{'label':'167797.Sherpa_CT10_ZeeMassiveCBPt70_140_BFilter'          , 'num_jobs':20}
                          , 167800:{'label':'167800.Sherpa_CT10_ZmumuMassiveCBPt70_140_BFilter'        , 'num_jobs':20}
                          , 167803:{'label':'167803.Sherpa_CT10_ZtautauMassiveCBPt70_140_BFilter'      , 'num_jobs':5}
                          , 167809:{'label':'167809.Sherpa_CT10_ZeeMassiveCBPt140_280_BFilter'         , 'num_jobs':10}
                          , 167812:{'label':'167812.Sherpa_CT10_ZmumuMassiveCBPt140_280_BFilter'       , 'num_jobs':10}
                          , 167815:{'label':'167815.Sherpa_CT10_ZtautauMassiveCBPt140_280_BFilter'     , 'num_jobs':5}
                          , 167821:{'label':'167821.Sherpa_CT10_ZeeMassiveCBPt280_500_BFilter'         , 'num_jobs':10}
                          , 167824:{'label':'167824.Sherpa_CT10_ZmumuMassiveCBPt280_500_BFilter'       , 'num_jobs':10}
                          , 167827:{'label':'167827.Sherpa_CT10_ZtautauMassiveCBPt280_500_BFilter'     , 'num_jobs':5}
                          , 167833:{'label':'167833.Sherpa_CT10_ZeeMassiveCBPt500_BFilter'             , 'num_jobs':10}
                          , 167836:{'label':'167836.Sherpa_CT10_ZmumuMassiveCBPt500_BFilter'           , 'num_jobs':10}
                          , 167839:{'label':'167839.Sherpa_CT10_ZtautauMassiveCBPt500_BFilter'         , 'num_jobs':5}
                          , 180543:{'label':'180543.Sherpa_CT10_ZeeMassiveCBPt40_70_BFilter'           , 'num_jobs':10}
                          , 180546:{'label':'180546.Sherpa_CT10_ZmumuMassiveCBPt40_70_BFilter'         , 'num_jobs':10}
                          , 180549:{'label':'180549.Sherpa_CT10_ZtautauMassiveCBPt40_70_BFilter'       , 'num_jobs':5}
                          , 202632:{'label':'202632.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_100'  , 'num_jobs':1}
                          , 202633:{'label':'202633.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_200'  , 'num_jobs':1}
                          , 202634:{'label':'202634.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_300'  , 'num_jobs':1}
                          , 202635:{'label':'202635.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_400'  , 'num_jobs':1}
                          , 202636:{'label':'202636.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_500'  , 'num_jobs':1}
                          , 202637:{'label':'202637.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_600'  , 'num_jobs':1}
                          , 202638:{'label':'202638.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_700'  , 'num_jobs':1}
                          , 202639:{'label':'202639.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_800'  , 'num_jobs':1}
                          , 202640:{'label':'202640.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_900'  , 'num_jobs':1}
                          , 202641:{'label':'202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000' , 'num_jobs':1}
                          }

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # add data samples
    data_set_dicts = RunHelpers.addAllSamplesToList( data_samples = data_samples
                                                   , full_sim_mc_samples = full_sim_mc_samples
                                                   , fast_sim_mc_samples = fast_sim_mc_samples
                                                   , file_list_path_base = 'EosFileLists/tnt_103/tnt_103'
                                                   , out_dir = out_dir
                                                   )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    if run_local:
        RunHelpers.runLocalMultiprocess( run_analysis_fun = RunBMinusLOptimizeNtupleMaker.runBMinusLOptimizeNtupleMakerFun
                                       , data_set_dicts   = data_set_dicts
                                       , num_processes    = num_processes
                                       , out_dir          = out_dir
                                       , flat_ntuples     = False
                                       , sym_link_name    = './NextOptNtupDir.BMinusL'
                                       )
    else:
        RunHelpers.runLxBatchMultiProcess( run_analysis_fun      = RunBMinusLOptimizeNtupleMaker.runBMinusLOptimizeNtupleMakerFun
                                        , run_analysis_fun_loc  = '%s/BMinusLAnalysis/RunScripts/' % os.environ['BASE_WORK_DIR']
                                        , run_analysis_fun_file = 'RunBMinusLOptimizeNtupleMaker'
                                        , data_set_dicts        = data_set_dicts
                                        , out_dir               = out_dir
                                        , queue                 = '1nh'
                                        , sym_link_name         = './NextOptNtupDir.BMinusL'
                                        )
