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
out_dir = '%s/hists/bminusl_hists_%04d_%02d_%02d__%02d_%02d' % ( os.environ['PWD']
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
                   }
    full_sim_mc_samples = {
                            117050:{'label':'117050.PowhegPythia_P2011C_ttbar'                 , 'num_jobs':30}
                          , 105200:{'label':'105200.McAtNloJimmy_CT10_ttbar_LeptonFilter'      , 'num_jobs':30}
                          , 200332:{'label':'200332.AlpgenPythia_Auto_P2011C_ZeebbNp0'         , 'num_jobs':20}
                          , 200333:{'label':'200333.AlpgenPythia_Auto_P2011C_ZeebbNp1'         , 'num_jobs':10}
                          , 200334:{'label':'200334.AlpgenPythia_Auto_P2011C_ZeebbNp2'         , 'num_jobs':3}
                          , 200335:{'label':'200335.AlpgenPythia_Auto_P2011C_ZeebbNp3incl'     , 'num_jobs':1}
                          , 200340:{'label':'200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0'       , 'num_jobs':20}
                          , 200341:{'label':'200341.AlpgenPythia_Auto_P2011C_ZmumubbNp1'       , 'num_jobs':10}
                          , 200342:{'label':'200342.AlpgenPythia_Auto_P2011C_ZmumubbNp2'       , 'num_jobs':3}
                          , 200343:{'label':'200343.AlpgenPythia_Auto_P2011C_ZmumubbNp3incl'   , 'num_jobs':1}
                          , 200348:{'label':'200348.AlpgenPythia_Auto_P2011C_ZtautaubbNp0'     , 'num_jobs':1}
                          , 200349:{'label':'200349.AlpgenPythia_Auto_P2011C_ZtautaubbNp1'     , 'num_jobs':1}
                          , 200350:{'label':'200350.AlpgenPythia_Auto_P2011C_ZtautaubbNp2'     , 'num_jobs':1}
                          , 200351:{'label':'200351.AlpgenPythia_Auto_P2011C_ZtautaubbNp3incl' , 'num_jobs':1}
                          , 108346:{'label':'108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl', 'num_jobs':20}
                          # , 110817:{'label':'110817.AlpgenPythia_P2011C_ZeebbNp0'    , 'num_jobs':1}
                          # , 110818:{'label':'110818.AlpgenPythia_P2011C_ZeebbNp1'    , 'num_jobs':1}
                          # , 110819:{'label':'110819.AlpgenPythia_P2011C_ZeebbNp2'    , 'num_jobs':1}
                          # , 110820:{'label':'110820.AlpgenPythia_P2011C_ZeebbNp3'    , 'num_jobs':1}
                          # , 110821:{'label':'110821.AlpgenPythia_P2011C_ZmumubbNp0'  , 'num_jobs':1}
                          # , 110822:{'label':'110822.AlpgenPythia_P2011C_ZmumubbNp1'  , 'num_jobs':1}
                          # , 110823:{'label':'110823.AlpgenPythia_P2011C_ZmumubbNp2'  , 'num_jobs':1}
                          # , 110824:{'label':'110824.AlpgenPythia_P2011C_ZmumubbNp3'  , 'num_jobs':1}
                          # , 110825:{'label':'110825.AlpgenPythia_P2011C_ZtautaubbNp0', 'num_jobs':1}
                          # , 110826:{'label':'110826.AlpgenPythia_P2011C_ZtautaubbNp1', 'num_jobs':1}
                          # , 110827:{'label':'110827.AlpgenPythia_P2011C_ZtautaubbNp2', 'num_jobs':1}
                          # , 110828:{'label':'110828.AlpgenPythia_P2011C_ZtautaubbNp3', 'num_jobs':1}
                          }
    fast_sim_mc_samples = {
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

                          #   202641:{'label':'202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000' , 'num_jobs':1}
                          # , 202636:{'label':'202636.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_500' , 'num_jobs':1}
                          # , 202639:{'label':'202639.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_800' , 'num_jobs':1}
                          }

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # add data samples
    data_set_dicts = RunHelpers.addAllSamplesToList( data_samples = data_samples
                                                   , full_sim_mc_samples = full_sim_mc_samples
                                                   , fast_sim_mc_samples = fast_sim_mc_samples
                                                   , file_list_path_base = 'EosFileLists/tnt_102/tnt_102'
                                                   , out_dir = out_dir
                                                   )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    if run_local:
        RunHelpers.runLocalMultiprocess( run_analysis_fun = RunBMinusLAnalysis.runBMinusLAnalysisFun
                                       , data_set_dicts   = data_set_dicts
                                       , num_processes    = num_processes
                                       , out_dir          = out_dir
                                       , flat_ntuples     = False
                                       , sym_link_name    = './NextPlotDir.BMinusL'
                                       )
    else:
        RunHelpers.runLxBatchMultiProcess( run_analysis_fun      = RunBMinusLAnalysis.runBMinusLAnalysisFun
                                        , run_analysis_fun_loc  = '%s/BMinusLAnalysis/RunScripts/' % os.environ['BASE_WORK_DIR']
                                        , run_analysis_fun_file = 'RunBMinusLAnalysis'
                                        , data_set_dicts        = data_set_dicts
                                        , out_dir               = out_dir
                                        , queue                 = '1nh'
                                        , sym_link_name         = './NextPlotDir.BMinusL'
                                        )

sys.path.append('%s/BMinusLAnalysis/RunScripts/' % os.environ['BASE_WORK_DIR'])
import RunBMinusLAnalysis
