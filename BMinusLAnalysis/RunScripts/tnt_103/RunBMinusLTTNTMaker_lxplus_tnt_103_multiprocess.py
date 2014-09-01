#!/usr/bin/env python

import os
from multiprocessing import Pool
import time
import sys
import datetime

sys.path.append('%s/BMinusLAnalysis/RunScripts/' % os.environ['BASE_WORK_DIR'])
import RunBMinusLTTNTMaker

sys.path.append('%s/RunHelpers/' % os.environ['BASE_WORK_DIR'])
import RunHelpers

# ------------------------------------------------------------------------------
RunBMinusLAnalysis.input_tree_name = "TNT"
RunBMinusLAnalysis.lep_pt_cut = 20.e3
RunBMinusLAnalysis.jet_pt_cut = 20.e3

# 90% working point
# RunBMinusLAnalysis.btag_working_point = 0.0617
# 80% working point
RunBMinusLAnalysis.btag_working_point = 0.3511
# 70% working point
# RunBMinusLAnalysis.btag_working_point = 0.7892

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
out_dir = '%s/hists/bminusl_ttnt_%04d_%02d_%02d__%02d_%02d' % ( os.environ['PWD']
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

    egamma_data_samples = {
                            'periodA_egamma':{'label':'periodA_egamma', 'num_jobs':5}
                          , 'periodB_egamma':{'label':'periodB_egamma', 'num_jobs':5}
                          , 'periodC_egamma':{'label':'periodC_egamma', 'num_jobs':5}
                          , 'periodD_egamma':{'label':'periodD_egamma', 'num_jobs':5}
                          , 'periodE_egamma':{'label':'periodE_egamma', 'num_jobs':5}
                          , 'periodG_egamma':{'label':'periodG_egamma', 'num_jobs':5}
                          , 'periodH_egamma':{'label':'periodH_egamma', 'num_jobs':5}
                          , 'periodI_egamma':{'label':'periodI_egamma', 'num_jobs':5}
                          , 'periodJ_egamma':{'label':'periodJ_egamma', 'num_jobs':5}
                          , 'periodL_egamma':{'label':'periodL_egamma', 'num_jobs':5}
                          }
    muon_data_samples = {
                          'periodA_muon':{'label':'periodA_muon', 'num_jobs':5}
                        , 'periodB_muon':{'label':'periodB_muon', 'num_jobs':5}
                        , 'periodC_muon':{'label':'periodC_muon', 'num_jobs':5}
                        , 'periodD_muon':{'label':'periodD_muon', 'num_jobs':5}
                        , 'periodE_muon':{'label':'periodE_muon', 'num_jobs':5}
                        , 'periodG_muon':{'label':'periodG_muon', 'num_jobs':5}
                        , 'periodH_muon':{'label':'periodH_muon', 'num_jobs':5}
                        , 'periodI_muon':{'label':'periodI_muon', 'num_jobs':5}
                        , 'periodJ_muon':{'label':'periodJ_muon', 'num_jobs':5}
                        , 'periodL_muon':{'label':'periodL_muon', 'num_jobs':5}
                        }
    full_sim_mc_samples = {
                          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                            173045:{'label':'173045.Sherpa_CT10_DYtautauM08to15' , 'num_jobs':1}
                          , 173046:{'label':'173046.Sherpa_CT10_DYtautauM15to40' , 'num_jobs':1}
                          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                          , 119353:{'label':'119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW'   , 'num_jobs':1}
                          , 119354:{'label':'119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj'  , 'num_jobs':1}
                          , 119355:{'label':'119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ'   , 'num_jobs':1}
                          , 119356:{'label':'119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj'  , 'num_jobs':1}
                          , 119583:{'label':'119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW' , 'num_jobs':1}
                          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                          , 160655:{'label':'160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu'        , 'num_jobs':1}
                          , 160705:{'label':'160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu'       , 'num_jobs':1}
                          , 160755:{'label':'160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu'            , 'num_jobs':1}
                          , 160805:{'label':'160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu'            , 'num_jobs':1}
                          , 161005:{'label':'161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5'  , 'num_jobs':1}
                          , 161055:{'label':'161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5' , 'num_jobs':1}
                          , 161105:{'label':'161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep'              , 'num_jobs':1}
                          , 161155:{'label':'161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep'              , 'num_jobs':1}
                          , 161305:{'label':'161305.Pythia8_AU2CTEQ6L1_ttH125_WWinclusive'        , 'num_jobs':1}
                          }
    fast_sim_mc_samples = {
                          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                            117050:{'label':'117050.PowhegPythia_P2011C_ttbar.af2_v2', 'num_jobs':50}

                          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                          , 110141:{'label':'110141.PowhegPythia_P2011C_st_Wtchan_dilepton_DR', 'num_jobs':15}

                          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                          , 167749:{'label':'167749.Sherpa_CT10_ZeeMassiveCBPt0_BFilter'                , 'num_jobs':20}
                          , 167750:{'label':'167750.Sherpa_CT10_ZeeMassiveCBPt0_CFilterBVeto'           , 'num_jobs':20}
                          , 167751:{'label':'167751.Sherpa_CT10_ZeeMassiveCBPt0_CVetoBVeto'             , 'num_jobs':20}

                          , 167752:{'label':'167752.Sherpa_CT10_ZmumuMassiveCBPt0_BFilter'              , 'num_jobs':20}
                          , 167753:{'label':'167753.Sherpa_CT10_ZmumuMassiveCBPt0_CFilterBVeto'         , 'num_jobs':20}
                          , 167754:{'label':'167754.Sherpa_CT10_ZmumuMassiveCBPt0_CVetoBVeto'           , 'num_jobs':20}

                          , 167755:{'label':'167755.Sherpa_CT10_ZtautauMassiveCBPt0_BFilter'            , 'num_jobs':1}
                          , 167756:{'label':'167756.Sherpa_CT10_ZtautauMassiveCBPt0_CFilterBVeto'       , 'num_jobs':1}
                          , 167757:{'label':'167757.Sherpa_CT10_ZtautauMassiveCBPt0_CVetoBVeto'         , 'num_jobs':1}

                          , 167797:{'label':'167797.Sherpa_CT10_ZeeMassiveCBPt70_140_BFilter'           , 'num_jobs':10}
                          , 167798:{'label':'167798.Sherpa_CT10_ZeeMassiveCBPt70_140_CFilterBVeto'      , 'num_jobs':10}
                          , 167799:{'label':'167799.Sherpa_CT10_ZeeMassiveCBPt70_140_CVetoBVeto'        , 'num_jobs':10}

                          , 167800:{'label':'167800.Sherpa_CT10_ZmumuMassiveCBPt70_140_BFilter'         , 'num_jobs':10}
                          , 167801:{'label':'167801.Sherpa_CT10_ZmumuMassiveCBPt70_140_CFilterBVeto'    , 'num_jobs':10}
                          , 167802:{'label':'167802.Sherpa_CT10_ZmumuMassiveCBPt70_140_CVetoBVeto'      , 'num_jobs':10}

                          , 167803:{'label':'167803.Sherpa_CT10_ZtautauMassiveCBPt70_140_BFilter'       , 'num_jobs':1}
                          , 167804:{'label':'167804.Sherpa_CT10_ZtautauMassiveCBPt70_140_CFilterBVeto'  , 'num_jobs':1}
                          , 167805:{'label':'167805.Sherpa_CT10_ZtautauMassiveCBPt70_140_CVetoBVeto'    , 'num_jobs':1}

                          , 167809:{'label':'167809.Sherpa_CT10_ZeeMassiveCBPt140_280_BFilter'          , 'num_jobs':5}
                          , 167810:{'label':'167810.Sherpa_CT10_ZeeMassiveCBPt140_280_CFilterBVeto'     , 'num_jobs':5}
                          , 167811:{'label':'167811.Sherpa_CT10_ZeeMassiveCBPt140_280_CVetoBVeto'       , 'num_jobs':5}

                          , 167812:{'label':'167812.Sherpa_CT10_ZmumuMassiveCBPt140_280_BFilter'        , 'num_jobs':5}
                          , 167813:{'label':'167813.Sherpa_CT10_ZmumuMassiveCBPt140_280_CFilterBVeto'   , 'num_jobs':5}
                          , 167814:{'label':'167814.Sherpa_CT10_ZmumuMassiveCBPt140_280_CVetoBVeto'     , 'num_jobs':5}

                          , 167815:{'label':'167815.Sherpa_CT10_ZtautauMassiveCBPt140_280_BFilter'      , 'num_jobs':1}
                          , 167816:{'label':'167816.Sherpa_CT10_ZtautauMassiveCBPt140_280_CFilterBVeto' , 'num_jobs':1}
                          , 167817:{'label':'167817.Sherpa_CT10_ZtautauMassiveCBPt140_280_CVetoBVeto'   , 'num_jobs':1}

                          , 167821:{'label':'167821.Sherpa_CT10_ZeeMassiveCBPt280_500_BFilter'          , 'num_jobs':5}
                          , 167822:{'label':'167822.Sherpa_CT10_ZeeMassiveCBPt280_500_CFilterBVeto'     , 'num_jobs':5}
                          , 167823:{'label':'167823.Sherpa_CT10_ZeeMassiveCBPt280_500_CVetoBVeto'       , 'num_jobs':5}

                          , 167824:{'label':'167824.Sherpa_CT10_ZmumuMassiveCBPt280_500_BFilter'        , 'num_jobs':5}
                          , 167825:{'label':'167825.Sherpa_CT10_ZmumuMassiveCBPt280_500_CFilterBVeto'   , 'num_jobs':5}
                          , 167826:{'label':'167826.Sherpa_CT10_ZmumuMassiveCBPt280_500_CVetoBVeto'     , 'num_jobs':5}

                          , 167827:{'label':'167827.Sherpa_CT10_ZtautauMassiveCBPt280_500_BFilter'      , 'num_jobs':1}
                          , 167828:{'label':'167828.Sherpa_CT10_ZtautauMassiveCBPt280_500_CFilterBVeto' , 'num_jobs':1}
                          , 167829:{'label':'167829.Sherpa_CT10_ZtautauMassiveCBPt280_500_CVetoBVeto'   , 'num_jobs':1}

                          , 167833:{'label':'167833.Sherpa_CT10_ZeeMassiveCBPt500_BFilter'              , 'num_jobs':3}
                          , 167834:{'label':'167834.Sherpa_CT10_ZeeMassiveCBPt500_CFilterBVeto'         , 'num_jobs':3}
                          , 167835:{'label':'167835.Sherpa_CT10_ZeeMassiveCBPt500_CVetoBVeto'           , 'num_jobs':3}

                          , 167836:{'label':'167836.Sherpa_CT10_ZmumuMassiveCBPt500_BFilter'            , 'num_jobs':3}
                          , 167837:{'label':'167837.Sherpa_CT10_ZmumuMassiveCBPt500_CFilterBVeto'       , 'num_jobs':3}
                          , 167838:{'label':'167838.Sherpa_CT10_ZmumuMassiveCBPt500_CVetoBVeto'         , 'num_jobs':3}

                          , 167839:{'label':'167839.Sherpa_CT10_ZtautauMassiveCBPt500_BFilter'          , 'num_jobs':1}
                          , 167840:{'label':'167840.Sherpa_CT10_ZtautauMassiveCBPt500_CFilterBVeto'     , 'num_jobs':1}
                          , 167841:{'label':'167841.Sherpa_CT10_ZtautauMassiveCBPt500_CVetoBVeto'       , 'num_jobs':1}

                          , 180543:{'label':'180543.Sherpa_CT10_ZeeMassiveCBPt40_70_BFilter'            , 'num_jobs':10}
                          , 180544:{'label':'180544.Sherpa_CT10_ZeeMassiveCBPt40_70_CFilterBVeto'       , 'num_jobs':10}
                          , 180545:{'label':'180545.Sherpa_CT10_ZeeMassiveCBPt40_70_CVetoBVeto'         , 'num_jobs':10}

                          , 180546:{'label':'180546.Sherpa_CT10_ZmumuMassiveCBPt40_70_BFilter'          , 'num_jobs':10}
                          , 180547:{'label':'180547.Sherpa_CT10_ZmumuMassiveCBPt40_70_CFilterBVeto'     , 'num_jobs':10}
                          , 180548:{'label':'180548.Sherpa_CT10_ZmumuMassiveCBPt40_70_CVetoBVeto'       , 'num_jobs':10}

                          , 180549:{'label':'180549.Sherpa_CT10_ZtautauMassiveCBPt40_70_BFilter'        , 'num_jobs':1}
                          , 180550:{'label':'180550.Sherpa_CT10_ZtautauMassiveCBPt40_70_CFilterBVeto'   , 'num_jobs':1}
                          , 180551:{'label':'180551.Sherpa_CT10_ZtautauMassiveCBPt40_70_CVetoBVeto'     , 'num_jobs':1}

                          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                          , 173041:{'label':'173041.Sherpa_CT10_DYeeM08to15'     , 'num_jobs':5}
                          , 173042:{'label':'173042.Sherpa_CT10_DYeeM15to40'     , 'num_jobs':5}

                          , 173043:{'label':'173043.Sherpa_CT10_DYmumuM08to15'   , 'num_jobs':5}
                          , 173044:{'label':'173044.Sherpa_CT10_DYmumuM15to40'   , 'num_jobs':5}

                          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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

                          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                          # 202632:{'label':'202632.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_100' , 'num_jobs':1}
                          # 202633:{'label':'202633.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_200' , 'num_jobs':1}
                          # 202634:{'label':'202634.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_300' , 'num_jobs':1}
                          # 202635:{'label':'202635.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_400' , 'num_jobs':1}
                          # 202636:{'label':'202636.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_500' , 'num_jobs':1}
                          # 202637:{'label':'202637.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_600' , 'num_jobs':1}
                          # 202638:{'label':'202638.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_700' , 'num_jobs':1}
                          # 202639:{'label':'202639.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_800' , 'num_jobs':1}
                          # 202640:{'label':'202640.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_900' , 'num_jobs':1}
                          # 202641:{'label':'202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000', 'num_jobs':1}
                          }

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # add data samples
    data_set_dicts = RunHelpers.addAllSamplesToList( egamma_data_samples = egamma_data_samples
                                                   , muon_data_samples   = muon_data_samples
                                                   , full_sim_mc_samples = full_sim_mc_samples
                                                   , fast_sim_mc_samples = fast_sim_mc_samples
                                                   # , file_list_path_base = 'EosFileLists/tnt_103/tnt_103'
                                                   , file_list_path_base = 'EosFileLists/tnt_103_w_weights/tnt_103'
                                                   , out_dir = out_dir
                                                   )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    if run_local:
        RunHelpers.runLocalMultiprocess( run_analysis_fun = RunBMinusLTTNTMaker.runBMinusLTTNTMakerFun
                                       , data_set_dicts   = data_set_dicts
                                       , num_processes    = num_processes
                                       , out_dir          = out_dir
                                       , flat_ntuples     = False
                                       , sym_link_name    = './NextPlotDir.BMinusL'
                                       )
    else:
        RunHelpers.runLxBatchMultiProcess( run_analysis_fun      = RunBMinusLTTNTMaker.runBMinusLTTNTMakerFun
                                         , run_analysis_fun_loc  = '%s/BMinusLAnalysis/RunScripts/' % os.environ['BASE_WORK_DIR']
                                         , run_analysis_fun_file = 'RunBMinusLTTNTMaker'
                                         , data_set_dicts        = data_set_dicts
                                         , out_dir               = out_dir
                                         , queue                 = '1nh'
                                         , sym_link_name         = './NextTTNTDir.BMinusL'
                                         , job_dir               = 'LatestRunDir_bminuslttntmaker'
                                         )
