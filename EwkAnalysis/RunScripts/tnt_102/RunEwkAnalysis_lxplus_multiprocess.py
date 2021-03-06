#!/usr/bin/env python

import os
from multiprocessing import Pool
import time
import sys
import datetime

sys.path.append('%s/EwkAnalysis/RunScripts/' % os.environ['BASE_WORK_DIR'])
import RunEwkAnalysis

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
out_dir = '%s/hists/ewk_hists_%04d_%02d_%02d' % ( os.environ['PWD']
                                                , today_date.year
                                                , today_date.month
                                                , today_date.day
                                                )
print out_dir

# ==============================================================================
if __name__ == '__main__':
    RunHelpers.safeMakeDir(out_dir)

    print 'getting file list'
    data_set_dicts = []
    data_samples = {# 'periodA_egamma':{'label':'periodA_egamma'       , 'num_jobs':10}
                    # 'periodB_egamma':{'label':'periodB_egamma'      , 'num_jobs':5} ##THIS ONE
                    #, 'periodC_egamma':{'label':'periodC_egamma'      , 'num_jobs':5}
                   ## , 'periodD_egamma':{'label':'periodD_egamma'      , 'num_jobs':10} ##THIS ONE TOO
                   ## , 'periodE_egamma':{'label':'periodE_egamma'      , 'num_jobs':10}
                    'periodA_muon':{'label':'periodA_muon'          , 'num_jobs':10}
                   ## , 'periodB_muon':{'label':'periodB_muon'          , 'num_jobs':10}
                   ## , 'periodC_muon':{'label':'periodC_muon'          , 'num_jobs':10}
                   ## , 'periodD_muon':{'label':'periodD_muon'          , 'num_jobs':10}
                   ## , 'periodE_muon':{'label':'periodE_muon'          , 'num_jobs':10}
                   }

    full_sim_mc_samples = {
                          ##   117650:{'label':'117650.AlpgenPythia_P2011C_ZeeNp0'                                  , 'num_jobs':20}
                          ## , 117651:{'label':'117651.AlpgenPythia_P2011C_ZeeNp1'                                  , 'num_jobs':20}
                          ## , 117652:{'label':'117652.AlpgenPythia_P2011C_ZeeNp2'                                  , 'num_jobs':10}
                          ## , 117653:{'label':'117653.AlpgenPythia_P2011C_ZeeNp3'                                  , 'num_jobs':1}
                          ## , 117654:{'label':'117654.AlpgenPythia_P2011C_ZeeNp4'                                  , 'num_jobs':1}
                          ## , 117655:{'label':'117655.AlpgenPythia_P2011C_ZeeNp5'                                  , 'num_jobs':1}

                          ## , 117660:{'label':'117660.AlpgenPythia_P2011C_ZmumuNp0'                                , 'num_jobs':20}
                          ## , 117661:{'label':'117661.AlpgenPythia_P2011C_ZmumuNp1'                                , 'num_jobs':20}
                          ## , 117662:{'label':'117662.AlpgenPythia_P2011C_ZmumuNp2'                                , 'num_jobs':10}
                          ## , 117663:{'label':'117663.AlpgenPythia_P2011C_ZmumuNp3'                                , 'num_jobs':1}
                          ## , 117664:{'label':'117664.AlpgenPythia_P2011C_ZmumuNp4'                                , 'num_jobs':1}
                          ## , 117665:{'label':'117665.AlpgenPythia_P2011C_ZmumuNp5'                                , 'num_jobs':1}

                          ## , 117670:{'label':'117670.AlpgenPythia_P2011C_ZtautauNp0'                              , 'num_jobs':20}
                          ## , 117671:{'label':'117671.AlpgenPythia_P2011C_ZtautauNp1'                              , 'num_jobs':20}
                          ## , 117672:{'label':'117672.AlpgenPythia_P2011C_ZtautauNp2'                              , 'num_jobs':10}
                          ## , 117673:{'label':'117673.AlpgenPythia_P2011C_ZtautauNp3'                              , 'num_jobs':1}
                          ## , 117674:{'label':'117674.AlpgenPythia_P2011C_ZtautauNp4'                              , 'num_jobs':1}
                          ## , 117675:{'label':'117675.AlpgenPythia_P2011C_ZtautauNp5'                              , 'num_jobs':1}

                          ## , 110805:{'label':'110805.AlpgenPythia_P2011C_ZeeccNp0'                                , 'num_jobs':1}
                          ## , 110806:{'label':'110806.AlpgenPythia_P2011C_ZeeccNp1'                                , 'num_jobs':1}
                          ## , 110807:{'label':'110807.AlpgenPythia_P2011C_ZeeccNp2'                                , 'num_jobs':1}
                          ## , 110808:{'label':'110808.AlpgenPythia_P2011C_ZeeccNp3'                                , 'num_jobs':1}

                          ## , 110817:{'label':'110817.AlpgenPythia_P2011C_ZeebbNp0'                                , 'num_jobs':1}
                          ## , 110818:{'label':'110818.AlpgenPythia_P2011C_ZeebbNp1'                                , 'num_jobs':1}
                          ## , 110819:{'label':'110819.AlpgenPythia_P2011C_ZeebbNp2'                                , 'num_jobs':1}
                          ## , 110820:{'label':'110820.AlpgenPythia_P2011C_ZeebbNp3'                                , 'num_jobs':1}

                          ## , 110809:{'label':'110809.AlpgenPythia_P2011C_ZmumuccNp0'                              , 'num_jobs':1}
                          ## , 110810:{'label':'110810.AlpgenPythia_P2011C_ZmumuccNp1'                              , 'num_jobs':1}
                          ## , 110811:{'label':'110811.AlpgenPythia_P2011C_ZmumuccNp2'                              , 'num_jobs':1}
                          ## , 110812:{'label':'110812.AlpgenPythia_P2011C_ZmumuccNp3'                              , 'num_jobs':1}

                          ## , 110821:{'label':'110821.AlpgenPythia_P2011C_ZmumubbNp0'                              , 'num_jobs':1}
                          ## , 110822:{'label':'110822.AlpgenPythia_P2011C_ZmumubbNp1'                              , 'num_jobs':1}
                          ## , 110823:{'label':'110823.AlpgenPythia_P2011C_ZmumubbNp2'                              , 'num_jobs':1}
                          ## , 110824:{'label':'110824.AlpgenPythia_P2011C_ZmumubbNp3'                              , 'num_jobs':1}

                          ## , 110813:{'label':'110813.AlpgenPythia_P2011C_ZtautauccNp0'                            , 'num_jobs':1}
                          ## , 110814:{'label':'110814.AlpgenPythia_P2011C_ZtautauccNp1'                            , 'num_jobs':1}
                          ## , 110815:{'label':'110815.AlpgenPythia_P2011C_ZtautauccNp2'                            , 'num_jobs':1}
                          ## , 110816:{'label':'110816.AlpgenPythia_P2011C_ZtautauccNp3'                            , 'num_jobs':1}

                          ## , 110825:{'label':'110825.AlpgenPythia_P2011C_ZtautaubbNp0'                            , 'num_jobs':1}
                          ## , 110826:{'label':'110826.AlpgenPythia_P2011C_ZtautaubbNp1'                            , 'num_jobs':1}
                          ## , 110827:{'label':'110827.AlpgenPythia_P2011C_ZtautaubbNp2'                            , 'num_jobs':1}
                          ## , 110828:{'label':'110828.AlpgenPythia_P2011C_ZtautaubbNp3'                            , 'num_jobs':1}

                          ## , 126892:{'label':'126892.Sherpa_CT10_llnunu_WW'                                       , 'num_jobs':20}
                          ## , 126988:{'label':'126988.Sherpa_CT10_llnunu_SS_EW6'                                   , 'num_jobs':1}
                          ## , 126989:{'label':'126989.Sherpa_CT10_llnunujj_SS'                                     , 'num_jobs':1}

                          ## , 157814:{'label':'157814.Sherpa_CT10_VVtoeeqq'                                        , 'num_jobs':1}
                          ## , 157815:{'label':'157815.Sherpa_CT10_VVtomumuqq'                                      , 'num_jobs':1}
                          ## , 157816:{'label':'157816.Sherpa_CT10_VVtotautauqq'                                    , 'num_jobs':1}
                          ## , 157817:{'label':'157817.Sherpa_CT10_VVtoenuqq'                                       , 'num_jobs':1}
                          ## , 157818:{'label':'157818.Sherpa_CT10_VVtomunuqq'                                      , 'num_jobs':1}
                          ## , 157819:{'label':'157819.Sherpa_CT10_VVtotaunuqq'                                     , 'num_jobs':1}

                          ## , 126928:{'label':'126928.PowhegPythia8_AU2CT10_WpWm_ee'                               , 'num_jobs':1}
                          ## , 126929:{'label':'126929.PowhegPythia8_AU2CT10_WpWm_me'                               , 'num_jobs':1}
                          ## , 126930:{'label':'126930.PowhegPythia8_AU2CT10_WpWm_te'                               , 'num_jobs':1}
                          ## , 126931:{'label':'126931.PowhegPythia8_AU2CT10_WpWm_em'                               , 'num_jobs':1}
                          ## , 126932:{'label':'126932.PowhegPythia8_AU2CT10_WpWm_mm'                               , 'num_jobs':1}
                          ## , 126933:{'label':'126933.PowhegPythia8_AU2CT10_WpWm_tm'                               , 'num_jobs':1}
                          ## , 126934:{'label':'126934.PowhegPythia8_AU2CT10_WpWm_et'                               , 'num_jobs':1}
                          ## , 126935:{'label':'126935.PowhegPythia8_AU2CT10_WpWm_mt'                               , 'num_jobs':1}
                          ## , 126936:{'label':'126936.PowhegPythia8_AU2CT10_WpWm_tt'                               , 'num_jobs':1}

                          ## , 129477:{'label':'129477.PowhegPythia8_AU2CT10_WZ_Wm11Z11_mll0p250d0_2LeptonFilter5'  , 'num_jobs':1}
                          ## , 129478:{'label':'129478.PowhegPythia8_AU2CT10_WZ_Wm11Z13_mll0p4614d0_2LeptonFilter5' , 'num_jobs':1}
                          ## , 129479:{'label':'129479.PowhegPythia8_AU2CT10_WZ_Wm11Z15_mll3p804d0_2LeptonFilter5'  , 'num_jobs':1}
                          ## , 129480:{'label':'129480.PowhegPythia8_AU2CT10_WZ_Wm13Z11_mll0p250d0_2LeptonFilter5'  , 'num_jobs':1}
                          ## , 129481:{'label':'129481.PowhegPythia8_AU2CT10_WZ_Wm13Z13_mll0p4614d0_2LeptonFilter5' , 'num_jobs':1}
                          ## , 129482:{'label':'129482.PowhegPythia8_AU2CT10_WZ_Wm13Z15_mll3p804d0_2LeptonFilter5'  , 'num_jobs':1}
                          ## , 129483:{'label':'129483.PowhegPythia8_AU2CT10_WZ_Wm15Z11_mll0p250d0_2LeptonFilter5'  , 'num_jobs':1}
                          ## , 129484:{'label':'129484.PowhegPythia8_AU2CT10_WZ_Wm15Z13_mll0p4614d0_2LeptonFilter5' , 'num_jobs':1}
                          ## , 129485:{'label':'129485.PowhegPythia8_AU2CT10_WZ_Wm15Z15_mll3p804d0_2LeptonFilter5'  , 'num_jobs':1}
                          ## , 129486:{'label':'129486.PowhegPythia8_AU2CT10_WZ_W11Z11_mll0p250d0_2LeptonFilter5'   , 'num_jobs':1}
                          ## , 129487:{'label':'129487.PowhegPythia8_AU2CT10_WZ_W11Z13_mll0p4614d0_2LeptonFilter5'  , 'num_jobs':1}
                          ## , 129488:{'label':'129488.PowhegPythia8_AU2CT10_WZ_W11Z15_mll3p804d0_2LeptonFilter5'   , 'num_jobs':1}
                          ## , 129489:{'label':'129489.PowhegPythia8_AU2CT10_WZ_W13Z11_mll0p250d0_2LeptonFilter5'   , 'num_jobs':1}
                          ## , 129490:{'label':'129490.PowhegPythia8_AU2CT10_WZ_W13Z13_mll0p4614d0_2LeptonFilter5'  , 'num_jobs':1}
                          ## , 129491:{'label':'129491.PowhegPythia8_AU2CT10_WZ_W13Z15_mll3p804d0_2LeptonFilter5'   , 'num_jobs':1}
                          ## , 129492:{'label':'129492.PowhegPythia8_AU2CT10_WZ_W15Z11_mll0p250d0_2LeptonFilter5'   , 'num_jobs':1}
                          ## , 129493:{'label':'129493.PowhegPythia8_AU2CT10_WZ_W15Z13_mll0p4614d0_2LeptonFilter5'  , 'num_jobs':1}
                          ## , 129494:{'label':'129494.PowhegPythia8_AU2CT10_WZ_W15Z15_mll3p804d0_2LeptonFilter5'   , 'num_jobs':1}

                          ## , 116600:{'label':'116600.gg2ZZJimmy_AUET2CT10_ZZ4lep'                                 , 'num_jobs':1}
                          ## , 116601:{'label':'116601.gg2ZZJimmy_AUET2CT10_ZZ4e'                                   , 'num_jobs':1}
                          ## , 116602:{'label':'116602.gg2ZZJimmy_AUET2CT10_ZZ4mu'                                  , 'num_jobs':1}
                          ## , 116603:{'label':'116603.gg2ZZJimmy_AUET2CT10_ZZ2e2mu'                                , 'num_jobs':1}
                          ## , 126937:{'label':'126937.PowhegPythia8_AU2CT10_ZZ_4e_mll4_2pt5'                       , 'num_jobs':1}
                          ## , 126938:{'label':'126938.PowhegPythia8_AU2CT10_ZZ_2e2mu_mll4_2pt5'                    , 'num_jobs':1}
                          ## , 126939:{'label':'126939.PowhegPythia8_AU2CT10_ZZ_2e2tau_mll4_2pt5'                   , 'num_jobs':1}
                          ## , 126940:{'label':'126940.PowhegPythia8_AU2CT10_ZZ_4mu_mll4_2pt5'                      , 'num_jobs':1}
                          ## , 126941:{'label':'126941.PowhegPythia8_AU2CT10_ZZ_2mu2tau_mll4_2pt5'                  , 'num_jobs':1}
                          ## , 126942:{'label':'126942.PowhegPythia8_AU2CT10_ZZ_4tau_mll4_2pt5'                     , 'num_jobs':1}
                          ## , 126949:{'label':'126949.PowhegPythia8_AU2CT10_ZZllnunu_ee_mll4'                      , 'num_jobs':1}
                          ## , 126950:{'label':'126950.PowhegPythia8_AU2CT10_ZZllnunu_mm_mll4'                      , 'num_jobs':1}
                          ## , 126951:{'label':'126951.PowhegPythia8_AU2CT10_ZZllnunu_tt_mll4'                      , 'num_jobs':1}

                          ## , 160155:{'label':'160155.PowhegPythia8_AU2CT10_ggH125_ZZ4lep'                         , 'num_jobs':1}
                          ## , 160205:{'label':'160205.PowhegPythia8_AU2CT10_VBFH125_ZZ4lep'                        , 'num_jobs':1}
                          ## , 160255:{'label':'160255.Pythia8_AU2CTEQ6L1_WH125_ZZ4lep'                             , 'num_jobs':1}
                          ## , 160305:{'label':'160305.Pythia8_AU2CTEQ6L1_ZH125_ZZ4lep'                             , 'num_jobs':1}
                          ## , 160655:{'label':'160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu'                       , 'num_jobs':1}
                          ## , 160705:{'label':'160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu'                      , 'num_jobs':1}
                          ## , 160755:{'label':'160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu'                           , 'num_jobs':1}
                          ## , 160805:{'label':'160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu'                           , 'num_jobs':1}
                          ## , 161005:{'label':'161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5'                 , 'num_jobs':1}
                          ## , 161055:{'label':'161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5'                , 'num_jobs':1}
                          ## , 161105:{'label':'161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep'                             , 'num_jobs':1}
                          ## , 161155:{'label':'161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep'                             , 'num_jobs':1}
                          }
    fast_sim_mc_samples = {
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
        RunHelpers.runLocalMultiprocess( run_analysis_fun = RunEwkAnalysis.runEwkAnalysisFun
                                       , data_set_dicts   = data_set_dicts
                                       , num_processes    = num_processes
                                       , out_dir          = out_dir
                                       , flat_ntuples     = False
                                       , sym_link_name    = './NextPlotDir.Ewk'
                                       )
    else:
        RunHelpers.runLxBatchMultiProcess( run_analysis_fun      = RunEwkAnalysis.runEwkAnalysisFun
                                         , run_analysis_fun_loc  = '%s/EwkAnalysis/RunScripts/' % os.environ['BASE_WORK_DIR']
                                         , run_analysis_fun_file = 'RunEwkAnalysis'
                                         , data_set_dicts        = data_set_dicts
                                         , out_dir               = out_dir
                                         , queue                 = '1nh'
                                         , sym_link_name         = './NextPlotDir.Ewk'
                                         )
