#!/usr/bin/env python

import os
from multiprocessing import Pool
import time
import sys
import datetime

import ROOT

sys.path.append('%s/EwkAnalysis/RunScripts/' % os.environ['BASE_WORK_DIR'])
import RunEwkNtupleMaker
import CrossSectionReader

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

# ------------------------------------------------------------------------------
# get number of parallel processes from command line inputs
#num_processes = int(sys.argv[1]) if len(sys.argv) > 1 else 1
#out_dir = 'hists/my_hists%s' % RunHelpers.getDateTimeLabel(True, False)

# ==============================================================================
if __name__ == '__main__':
    RunHelpers.safeMakeDir(out_dir)

    print 'getting file list'
    data_set_dicts = []
    data_samples = { ## 'periodA_egamma':{'label':'periodA_egamma'       , 'num_jobs':10}
                    ## ,'periodB_egamma':{'label':'periodB_egamma'      , 'num_jobs':4} ##THIS ONE
                    ## ,'periodC_egamma':{'label':'periodC_egamma'      , 'num_jobs':10}
                    ## ,'periodD_egamma':{'label':'periodD_egamma'      , 'num_jobs':4} ##THIS ONE TOO
                    ## , 'periodE_egamma':{'label':'periodE_egamma'      , 'num_jobs':4}
                    # 'periodA_muon':{'label':'periodA_muon'          , 'num_jobs':5}
                   # ,'periodB_muon':{'label':'periodB_muon'          , 'num_jobs':2}
                   # 'periodC_muon':{'label':'periodC_muon'          , 'num_jobs':2} #error
                   # ,'periodD_muon':{'label':'periodD_muon'          , 'num_jobs':5}
                   # ,'periodE_muon':{'label':'periodE_muon'          , 'num_jobs':2}
                   }

    full_sim_mc_samples = {#Z+jets
                          # 117650:{'label':'117650.AlpgenPythia_P2011C_ZeeNp0'                                  , 'num_jobs':10}
                          # , 117651:{'label':'117651.AlpgenPythia_P2011C_ZeeNp1'                                  , 'num_jobs':10}
                          # , 117652:{'label':'117652.AlpgenPythia_P2011C_ZeeNp2'                                  , 'num_jobs':5}
                          # , 117653:{'label':'117653.AlpgenPythia_P2011C_ZeeNp3'                                  , 'num_jobs':1}
                          # , 117654:{'label':'117654.AlpgenPythia_P2011C_ZeeNp4'                                  , 'num_jobs':1}
                          # , 117655:{'label':'117655.AlpgenPythia_P2011C_ZeeNp5'                                  , 'num_jobs':1}
                          # , 117660:{'label':'117660.AlpgenPythia_P2011C_ZmumuNp0'                                , 'num_jobs':10}
                          # , 117661:{'label':'117661.AlpgenPythia_P2011C_ZmumuNp1'                                , 'num_jobs':10}
                          # , 117662:{'label':'117662.AlpgenPythia_P2011C_ZmumuNp2'                                , 'num_jobs':5}
                          # , 117663:{'label':'117663.AlpgenPythia_P2011C_ZmumuNp3'                                , 'num_jobs':1}
                          # , 117664:{'label':'117664.AlpgenPythia_P2011C_ZmumuNp4'                                , 'num_jobs':1}
                          # , 117665:{'label':'117665.AlpgenPythia_P2011C_ZmumuNp5'                                , 'num_jobs':1}
                          # , 110805:{'label':'110805.AlpgenPythia_P2011C_ZeeccNp0'                                , 'num_jobs':1}
                          # , 110806:{'label':'110806.AlpgenPythia_P2011C_ZeeccNp1'                                , 'num_jobs':1}
                          # , 110807:{'label':'110807.AlpgenPythia_P2011C_ZeeccNp2'                                , 'num_jobs':1}
                          # , 110808:{'label':'110808.AlpgenPythia_P2011C_ZeeccNp3'                                , 'num_jobs':1}
                          # , 110817:{'label':'110817.AlpgenPythia_P2011C_ZeebbNp0'                                , 'num_jobs':1}
                          # , 110818:{'label':'110818.AlpgenPythia_P2011C_ZeebbNp1'                                , 'num_jobs':1}
                          # , 110819:{'label':'110819.AlpgenPythia_P2011C_ZeebbNp2'                                , 'num_jobs':1}
                          # , 110820:{'label':'110820.AlpgenPythia_P2011C_ZeebbNp3'                                , 'num_jobs':1}
                          # , 110809:{'label':'110809.AlpgenPythia_P2011C_ZmumuccNp0'                              , 'num_jobs':1}
                          # , 110810:{'label':'110810.AlpgenPythia_P2011C_ZmumuccNp1'                              , 'num_jobs':1}
                          # , 110811:{'label':'110811.AlpgenPythia_P2011C_ZmumuccNp2'                              , 'num_jobs':1}
                          # , 110812:{'label':'110812.AlpgenPythia_P2011C_ZmumuccNp3'                              , 'num_jobs':1}
                          ##, 110821:{'label':'110821.AlpgenPythia_P2011C_ZmumubbNp0'                              , 'num_jobs':1}#missing
                          # , 110822:{'label':'110822.AlpgenPythia_P2011C_ZmumubbNp1'                              , 'num_jobs':1}
                          # , 110823:{'label':'110823.AlpgenPythia_P2011C_ZmumubbNp2'                              , 'num_jobs':1}
                          # , 110824:{'label':'110824.AlpgenPythia_P2011C_ZmumubbNp3'                              , 'num_jobs':1}
                          # , 117670:{'label':'117670.AlpgenPythia_P2011C_ZtautauNp0'                              , 'num_jobs':10}
                          # , 117671:{'label':'117671.AlpgenPythia_P2011C_ZtautauNp1'                              , 'num_jobs':10}
                          # , 117672:{'label':'117672.AlpgenPythia_P2011C_ZtautauNp2'                              , 'num_jobs':5}
                          # , 117673:{'label':'117673.AlpgenPythia_P2011C_ZtautauNp3'                              , 'num_jobs':1}
                          # , 117674:{'label':'117674.AlpgenPythia_P2011C_ZtautauNp4'                              , 'num_jobs':1}
                          # , 117675:{'label':'117675.AlpgenPythia_P2011C_ZtautauNp5'                              , 'num_jobs':1}
                          # , 110813:{'label':'110813.AlpgenPythia_P2011C_ZtautauccNp0'                            , 'num_jobs':1}
                          # , 110814:{'label':'110814.AlpgenPythia_P2011C_ZtautauccNp1'                            , 'num_jobs':1}
                          # , 110815:{'label':'110815.AlpgenPythia_P2011C_ZtautauccNp2'                            , 'num_jobs':1}
                          # , 110816:{'label':'110816.AlpgenPythia_P2011C_ZtautauccNp3'                            , 'num_jobs':1}
                          # , 110825:{'label':'110825.AlpgenPythia_P2011C_ZtautaubbNp0'                            , 'num_jobs':1}
                           # , 110826:{'label':'110826.AlpgenPythia_P2011C_ZtautaubbNp1'                            , 'num_jobs':1}
                           # , 110827:{'label':'110827.AlpgenPythia_P2011C_ZtautaubbNp2'                            , 'num_jobs':1}
                           # , 110828:{'label':'110828.AlpgenPythia_P2011C_ZtautaubbNp3'                            , 'num_jobs':1}
                          ##, 126892:{'label':'126892.Sherpa_CT10_llnunu_WW'                                       , 'num_jobs':10}#not needed


 

                          #WW
                           # 126928:{'label':'126928.PowhegPythia8_AU2CT10_WpWm_ee'                               , 'num_jobs':1}
                          # , 126929:{'label':'126929.PowhegPythia8_AU2CT10_WpWm_me'                               , 'num_jobs':1}
                          # , 126930:{'label':'126930.PowhegPythia8_AU2CT10_WpWm_te'                               , 'num_jobs':1}
                          # , 126931:{'label':'126931.PowhegPythia8_AU2CT10_WpWm_em'                               , 'num_jobs':1}
                          # , 126932:{'label':'126932.PowhegPythia8_AU2CT10_WpWm_mm'                               , 'num_jobs':1}
                          # , 126933:{'label':'126933.PowhegPythia8_AU2CT10_WpWm_tm'                               , 'num_jobs':1}
                          # , 126934:{'label':'126934.PowhegPythia8_AU2CT10_WpWm_et'                               , 'num_jobs':1}
                          # , 126935:{'label':'126935.PowhegPythia8_AU2CT10_WpWm_mt'                               , 'num_jobs':1}
                          # , 126936:{'label':'126936.PowhegPythia8_AU2CT10_WpWm_tt'                               , 'num_jobs':1}
                          # , 126988:{'label':'126988.Sherpa_CT10_llnunu_SS_EW6'                                   , 'num_jobs':1}
                          # , 126989:{'label':'126989.Sherpa_CT10_llnunujj_SS'                                     , 'num_jobs':1}
                          # , 169471:{'label':'169471.gg2wwJimmy_AUET2CT10_WpWmenuenu'                             , 'num_jobs':1}
                          # , 169472:{'label':'169472.gg2wwJimmy_AUET2CT10_WpWmenumunu'                            , 'num_jobs':1}
                          # , 169473:{'label':'169473.gg2wwJimmy_AUET2CT10_WpWmenutaunu'                           , 'num_jobs':1}
                          # , 169474:{'label':'169474.gg2wwJimmy_AUET2CT10_WpWmmunumunu'                           , 'num_jobs':1}
                          # , 169475:{'label':'169475.gg2wwJimmy_AUET2CT10_WpWmmunuenu'                            , 'num_jobs':1}
                          # , 169476:{'label':'169476.gg2wwJimmy_AUET2CT10_WpWmmunutaunu'                          , 'num_jobs':1}
                          # , 169477:{'label':'169477.gg2wwJimmy_AUET2CT10_WpWmtaunutaunu'                         , 'num_jobs':1}
                          # , 169478:{'label':'169478.gg2wwJimmy_AUET2CT10_WpWmtaunuenu'                           , 'num_jobs':1} 
                          # , 169479:{'label':'169479.gg2wwJimmy_AUET2CT10_WpWmtaunumunu'                          , 'num_jobs':1}
                          #WZ #INCOMPLETE
                           # 129477:{'label':'129477.PowhegPythia8_AU2CT10_WZ_Wm11Z11_mll0p250d0_2LeptonFilter5'  , 'num_jobs':1}
                          # , 129478:{'label':'129478.PowhegPythia8_AU2CT10_WZ_Wm11Z13_mll0p4614d0_2LeptonFilter5' , 'num_jobs':1}
                          # , 129479:{'label':'129479.PowhegPythia8_AU2CT10_WZ_Wm11Z15_mll3p804d0_2LeptonFilter5'  , 'num_jobs':1}
                          # , 129480:{'label':'129480.PowhegPythia8_AU2CT10_WZ_Wm13Z11_mll0p250d0_2LeptonFilter5'  , 'num_jobs':1}
                          # , 129481:{'label':'129481.PowhegPythia8_AU2CT10_WZ_Wm13Z13_mll0p4614d0_2LeptonFilter5' , 'num_jobs':1}
                          # , 129482:{'label':'129482.PowhegPythia8_AU2CT10_WZ_Wm13Z15_mll3p804d0_2LeptonFilter5'  , 'num_jobs':1}
                          # , 129483:{'label':'129483.PowhegPythia8_AU2CT10_WZ_Wm15Z11_mll0p250d0_2LeptonFilter5'  , 'num_jobs':1}
                          # , 129484:{'label':'129484.PowhegPythia8_AU2CT10_WZ_Wm15Z13_mll0p4614d0_2LeptonFilter5' , 'num_jobs':1}
                          # , 129485:{'label':'129485.PowhegPythia8_AU2CT10_WZ_Wm15Z15_mll3p804d0_2LeptonFilter5'  , 'num_jobs':1}
                          # , 129486:{'label':'129486.PowhegPythia8_AU2CT10_WZ_W11Z11_mll0p250d0_2LeptonFilter5'   , 'num_jobs':1}
                          # , 129487:{'label':'129487.PowhegPythia8_AU2CT10_WZ_W11Z13_mll0p4614d0_2LeptonFilter5'  , 'num_jobs':1}
                          # , 129488:{'label':'129488.PowhegPythia8_AU2CT10_WZ_W11Z15_mll3p804d0_2LeptonFilter5'   , 'num_jobs':1}
                          # , 129489:{'label':'129489.PowhegPythia8_AU2CT10_WZ_W13Z11_mll0p250d0_2LeptonFilter5'   , 'num_jobs':1}
                          # , 129490:{'label':'129490.PowhegPythia8_AU2CT10_WZ_W13Z13_mll0p4614d0_2LeptonFilter5'  , 'num_jobs':1}
                          # , 129491:{'label':'129491.PowhegPythia8_AU2CT10_WZ_W13Z15_mll3p804d0_2LeptonFilter5'   , 'num_jobs':1}
                          # , 129492:{'label':'129492.PowhegPythia8_AU2CT10_WZ_W15Z11_mll0p250d0_2LeptonFilter5'   , 'num_jobs':1}
                          # , 129493:{'label':'129493.PowhegPythia8_AU2CT10_WZ_W15Z13_mll0p4614d0_2LeptonFilter5'  , 'num_jobs':1}
                          # , 129494:{'label':'129494.PowhegPythia8_AU2CT10_WZ_W15Z15_mll3p804d0_2LeptonFilter5'   , 'num_jobs':1}
						  # , 147194:{'label':'147194.Sherpa_CT10_lllnjj_WZjj_EW6'   , 'num_jobs':1}
						  # , 147195:{'label':'147195.Sherpa_CT10_llnnjj_ZZjj_EW6'   , 'num_jobs':1}
						  # , 147196:{'label':'147196.Sherpa_CT10_lllljj_ZZjj_EW6'   , 'num_jobs':1}

                          #Drell Yan
                           # 146832:{'label':'146832.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp2Excl_Mll10to60'          , 'num_jobs':1}      
                          # , 146831:{'label':'146831.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp1Excl_Mll10to60'          , 'num_jobs':1}
                          # , 146834:{'label':'146834.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp4Excl_Mll10to60'          , 'num_jobs':1}
                          # , 146830:{'label':'146830.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp0Excl_Mll10to60'          , 'num_jobs':1}
                          # , 146833:{'label':'146833.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp3Excl_Mll10to60'          , 'num_jobs':1}
                          # , 146835:{'label':'146835.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp5Incl_Mll10to60'          , 'num_jobs':1}
                          # , 146842:{'label':'146842.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp2Excl_Mll10to60'        , 'num_jobs':1}
                          # , 146840:{'label':'146840.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp0Excl_Mll10to60'        , 'num_jobs':1}
                          # , 146844:{'label':'146844.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp4Excl_Mll10to60'        , 'num_jobs':1}
                          # , 146841:{'label':'146841.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp1Excl_Mll10to60'        , 'num_jobs':1}
                          # , 146845:{'label':'146845.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp5Incl_Mll10to60'        , 'num_jobs':1}
                          # , 146843:{'label':'146843.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp3Excl_Mll10to60'        , 'num_jobs':1}
                          # , 146850:{'label':'146850.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp0Excl_Mll10to60'      , 'num_jobs':1}
                          # , 146851:{'label':'146851.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp1Excl_Mll10to60'      , 'num_jobs':1}
                          # , 146852:{'label':'146852.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp2Excl_Mll10to60'      , 'num_jobs':1}
                          # , 146853:{'label':'146853.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp3Excl_Mll10to60'      , 'num_jobs':1}
                          # , 146854:{'label':'146854.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp4Excl_Mll10to60'      , 'num_jobs':1}
                          #, 146854:{'label':'146854.AlpgenJimmy_Auto_AUE2CTEQ6L1_ZtautauNp4Excl_Mll10to60'      , 'num_jobs':1} #missing
                          # , 146855:{'label':'146855.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp5Incl_Mll10to60'      , 'num_jobs':1}

                          #ZZ
                          # 116600:{'label':'116600.gg2ZZJimmy_AUET2CT10_ZZ4lep'                                 , 'num_jobs':1}
                          # , 116601:{'label':'116601.gg2ZZJimmy_AUET2CT10_ZZ4e'                                   , 'num_jobs':1}
                          # , 116602:{'label':'116602.gg2ZZJimmy_AUET2CT10_ZZ4mu'                                  , 'num_jobs':1}
                          # , 116603:{'label':'116603.gg2ZZJimmy_AUET2CT10_ZZ2e2mu'                                , 'num_jobs':1}
                          # , 126937:{'label':'126937.PowhegPythia8_AU2CT10_ZZ_4e_mll4_2pt5'                       , 'num_jobs':1}
                          # , 126938:{'label':'126938.PowhegPythia8_AU2CT10_ZZ_2e2mu_mll4_2pt5'                    , 'num_jobs':1}
                          # , 126939:{'label':'126939.PowhegPythia8_AU2CT10_ZZ_2e2tau_mll4_2pt5'                   , 'num_jobs':1}
                          # , 126940:{'label':'126940.PowhegPythia8_AU2CT10_ZZ_4mu_mll4_2pt5'                      , 'num_jobs':1}
                          # , 126941:{'label':'126941.PowhegPythia8_AU2CT10_ZZ_2mu2tau_mll4_2pt5'                  , 'num_jobs':1}
                          # , 126942:{'label':'126942.PowhegPythia8_AU2CT10_ZZ_4tau_mll4_2pt5'                     , 'num_jobs':1}
                          # , 126949:{'label':'126949.PowhegPythia8_AU2CT10_ZZllnunu_ee_mll4'                      , 'num_jobs':1}
                          # , 126950:{'label':'126950.PowhegPythia8_AU2CT10_ZZllnunu_mm_mll4'                      , 'num_jobs':1}
                          # , 126951:{'label':'126951.PowhegPythia8_AU2CT10_ZZllnunu_tt_mll4'                      , 'num_jobs':1}
                          # , 157814:{'label':'157814.Sherpa_CT10_VVtoeeqq'                                        , 'num_jobs':1}
                          # , 157815:{'label':'157815.Sherpa_CT10_VVtomumuqq'                                      , 'num_jobs':1}
                          # , 157816:{'label':'157816.Sherpa_CT10_VVtotautauqq'                                    , 'num_jobs':1}
                          # , 157817:{'label':'157817.Sherpa_CT10_VVtoenuqq'                                       , 'num_jobs':1}
                          # , 157818:{'label':'157818.Sherpa_CT10_VVtomunuqq'                                      , 'num_jobs':1}
                          # , 157819:{'label':'157819.Sherpa_CT10_VVtotaunuqq'                                     , 'num_jobs':1}
        
                          #ttbar
                          # 105200:{'label':'105200.McAtNloJimmy_CT10_ttbar_LeptonFilter'                      , 'num_jobs':5}
                          # , 119353:{'label':'119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW'                             , 'num_jobs':5}
                          # , 119354:{'label':'119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj'                            , 'num_jobs':5}
                          # , 119355:{'label':'119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ'                             , 'num_jobs':5}
                          # , 119356:{'label':'119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj'                            , 'num_jobs':5}
                          # , 119583:{'label':'119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW'                           , 'num_jobs':5}

                          #st #INCOMPLETE
						   # 108343:{'label':'108343.McAtNloJimmy_AUET2CT10_SingleTopSChanWenu'                      , 'num_jobs':2}
						  # ,108344:{'label':'108344.McAtNloJimmy_AUET2CT10_SingleTopSChanWmunu'                     , 'num_jobs':2}
						  # ,108345:{'label':'108345.McAtNloJimmy_AUET2CT10_SingleTopSChanWtaunu'                    , 'num_jobs':2}
						  # ,117360:{'label':'117360.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_e'                   , 'num_jobs':2} #missing
						  # ,117361:{'label':'117361.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_mu'                  , 'num_jobs':2}
						  # ,117362:{'label':'117362.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_tau'                 , 'num_jobs':2}
        
                          #Higgs
                           # 160155:{'label':'160155.PowhegPythia8_AU2CT10_ggH125_ZZ4lep'                         , 'num_jobs':1}
                          # , 160205:{'label':'160205.PowhegPythia8_AU2CT10_VBFH125_ZZ4lep'                        , 'num_jobs':1}
                          # , 160255:{'label':'160255.Pythia8_AU2CTEQ6L1_WH125_ZZ4lep'                             , 'num_jobs':1}
                          # , 160305:{'label':'160305.Pythia8_AU2CTEQ6L1_ZH125_ZZ4lep'                             , 'num_jobs':1}
                          # , 160655:{'label':'160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu'                       , 'num_jobs':1}
                          # , 160705:{'label':'160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu'                      , 'num_jobs':1}
                          # , 160755:{'label':'160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu'                           , 'num_jobs':1}
                          # , 160805:{'label':'160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu'                           , 'num_jobs':1}
                          # , 161005:{'label':'161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5'                 , 'num_jobs':1}
                          # , 161055:{'label':'161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5'                , 'num_jobs':1}
                          # , 161105:{'label':'161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep'                             , 'num_jobs':1}
                          # , 161155:{'label':'161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep'                             , 'num_jobs':1}

                          #triboson #incomplete
                          # , 167006:{'label':'167006.MadGraphPythia_AUET2BCTEQ6L1_WWWStar_lnulnulnu'           , 'num_jobs':1} 
                          # , 167007:{'label':'167007.MadGraphPythia_AUET2BCTEQ6L1_ZWWStar_lllnulnu'            , 'num_jobs':1}
                          # , 167008:{'label':'167008.MadGraphPythia_AUET2BCTEQ6L1_ZZZStar_nunullll'            , 'num_jobs':1}

        #signal
         186283:{'label':'186283.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_117_5_n1_82_5_xsl_0_95'  , 'num_jobs':1}
    , 186284:{'label':'186284.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_135_0_n1_115_0_xsl_0_95'  , 'num_jobs':1}
    , 186285:{'label':'186285.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_142_5_n1_107_5_xsl_0_95'  , 'num_jobs':1}
    , 186287:{'label':'186287.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_192_5_n1_157_5_xsl_0_95'  , 'num_jobs':1}
    , 186288:{'label':'186288.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_260_0_n1_240_0_xsl_0_95'  , 'num_jobs':1}
    , 186289:{'label':'186289.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_110_0_n1_90_0_xsl_0_95'  , 'num_jobs':1}
    , 186290:{'label':'186290.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_112_5_n1_12_5_xsl_0_95'  , 'num_jobs':1}
    , 186291:{'label':'186291.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_112_5_n1_47_5_xsl_0_95'  , 'num_jobs':1}
    , 186292:{'label':'186292.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_130_0_n1_30_0_xsl_0_95'  , 'num_jobs':1}
    , 186293:{'label':'186293.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_132_5_n1_67_5_xsl_0_95'  , 'num_jobs':1}
    , 186294:{'label':'186294.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_150_0_n1_50_0_xsl_0_95'  , 'num_jobs':1}
    , 186295:{'label':'186295.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_155_0_n1_5_0_xsl_0_95'  , 'num_jobs':1}
    , 186296:{'label':'186296.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_157_5_n1_92_5_xsl_0_95'  , 'num_jobs':1}
    , 186297:{'label':'186297.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_175_0_n1_25_0_xsl_0_95'  , 'num_jobs':1}
    , 186298:{'label':'186298.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_175_0_n1_75_0_xsl_0_95'  , 'num_jobs':1}
    , 186299:{'label':'186299.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_200_0_n1_50_0_xsl_0_95'  , 'num_jobs':1}
    , 186300:{'label':'186300.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_207_5_n1_142_5_xsl_0_95'  , 'num_jobs':1}
    , 186301:{'label':'186301.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_225_0_n1_125_0_xsl_0_95'  , 'num_jobs':1}
    , 186302:{'label':'186302.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_250_0_n1_0_0_xsl_0_95'  , 'num_jobs':1}
    , 186303:{'label':'186303.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_250_0_n1_100_0_xsl_0_95'  , 'num_jobs':1}
    , 186304:{'label':'186304.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_267_5_n1_232_5_xsl_0_95'  , 'num_jobs':1}
    , 186305:{'label':'186305.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_282_5_n1_217_5_xsl_0_95'  , 'num_jobs':1}
    , 186306:{'label':'186306.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_300_0_n1_200_0_xsl_0_95'  , 'num_jobs':1}
    , 186307:{'label':'186307.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_300_0_n1_50_0_xsl_0_95'  , 'num_jobs':1}
    , 186308:{'label':'186308.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_325_0_n1_175_0_xsl_0_95'  , 'num_jobs':1}
    , 186309:{'label':'186309.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_350_0_n1_0_0_xsl_0_95'  , 'num_jobs':1}
    , 186310:{'label':'186310.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_375_0_n1_125_0_xsl_0_95'  , 'num_jobs':1}
    , 186311:{'label':'186311.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_392_5_n1_357_5_xsl_0_95'  , 'num_jobs':1}
    , 186312:{'label':'186312.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_407_5_n1_342_5_xsl_0_95'  , 'num_jobs':1}
    , 186313:{'label':'186313.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_425_0_n1_325_0_xsl_0_95'  , 'num_jobs':1}
    , 186314:{'label':'186314.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_425_0_n1_75_0_xsl_0_95'  , 'num_jobs':1}
    , 186315:{'label':'186315.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_450_0_n1_300_0_xsl_0_95'  , 'num_jobs':1}
    , 186316:{'label':'186316.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_455_0_n1_420_0_xsl_0_95'  , 'num_jobs':1}
    , 186317:{'label':'186317.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_470_0_n1_405_0_xsl_0_95'  , 'num_jobs':1}
    , 186318:{'label':'186318.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_487_5_n1_387_5_xsl_0_95'  , 'num_jobs':1}
    , 186319:{'label':'186319.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_500_0_n1_0_0_xsl_0_95'  , 'num_jobs':1}
    , 186320:{'label':'186320.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_500_0_n1_250_0_xsl_0_95'  , 'num_jobs':1}
    , 186321:{'label':'186321.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_512_5_n1_362_5_xsl_0_95'  , 'num_jobs':1}
    , 186322:{'label':'186322.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_517_5_n1_482_5_xsl_0_95'  , 'num_jobs':1}
    , 186323:{'label':'186323.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_532_5_n1_467_5_xsl_0_95'  , 'num_jobs':1}
    , 186324:{'label':'186324.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_550_0_n1_200_0_xsl_0_95'  , 'num_jobs':1}
    , 186325:{'label':'186325.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_550_0_n1_450_0_xsl_0_95'  , 'num_jobs':1}
    , 186326:{'label':'186326.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_562_5_n1_312_5_xsl_0_95'  , 'num_jobs':1}
    , 186327:{'label':'186327.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_575_0_n1_425_0_xsl_0_95'  , 'num_jobs':1}
    , 186328:{'label':'186328.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_612_5_n1_262_5_xsl_0_95'  , 'num_jobs':1}
    , 186329:{'label':'186329.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_625_0_n1_0_0_xsl_0_95'  , 'num_jobs':1}
    , 186330:{'label':'186330.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_625_0_n1_125_0_xsl_0_95'  , 'num_jobs':1}
    , 186331:{'label':'186331.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_625_0_n1_375_0_xsl_0_95'  , 'num_jobs':1}
    , 186332:{'label':'186332.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_642_5_n1_607_5_xsl_0_95'  , 'num_jobs':1}
    , 186333:{'label':'186333.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_675_0_n1_325_0_xsl_0_95'  , 'num_jobs':1}
    , 186334:{'label':'186334.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_675_0_n1_575_0_xsl_0_95'  , 'num_jobs':1}
    , 186335:{'label':'186335.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_687_5_n1_187_5_xsl_0_95'  , 'num_jobs':1}
    , 186336:{'label':'186336.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_687_5_n1_62_5_xsl_0_95'  , 'num_jobs':1}
    , 186338:{'label':'186338.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_750_0_n1_0_0_xsl_0_95'  , 'num_jobs':1}
    , 186339:{'label':'186339.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_750_0_n1_125_0_xsl_0_95'  , 'num_jobs':1}
    , 186340:{'label':'186340.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_750_0_n1_250_0_xsl_0_95'  , 'num_jobs':1}
    , 186341:{'label':'186341.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_750_0_n1_500_0_xsl_0_95'  , 'num_jobs':1}
    , 186342:{'label':'186342.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_800_0_n1_450_0_xsl_0_95'  , 'num_jobs':1}
    , 186343:{'label':'186343.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_812_5_n1_187_5_xsl_0_95'  , 'num_jobs':1}
    , 186344:{'label':'186344.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_812_5_n1_62_5_xsl_0_95'  , 'num_jobs':1}
    , 186345:{'label':'186345.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_875_0_n1_0_0_xsl_0_95'  , 'num_jobs':1}
        , 186346:{'label':'186346.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_875_0_n1_125_0_xsl_0_95'  , 'num_jobs':1}
        , 186347:{'label':'186347.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_875_0_n1_375_0_xsl_0_95'  , 'num_jobs':1}

                          }
    fast_sim_mc_samples = {
                          }

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # add samples
    data_set_dicts = RunHelpers.addAllSamplesToList( data_samples = data_samples
                                                   , full_sim_mc_samples = full_sim_mc_samples
                                                   , fast_sim_mc_samples = fast_sim_mc_samples
                                                   , file_list_path_base = 'EosFileLists/tnt_103/tnt_103_v2'
                                                   , out_dir = out_dir
                                                   )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    if run_local:
        RunHelpers.runLocalMultiprocess( run_analysis_fun = RunEwkNtupleMaker.runEwkNtupleFun
                                       , data_set_dicts   = data_set_dicts
                                       , num_processes    = num_processes
                                       , out_dir          = out_dir
                                       , flat_ntuples     = False
                                       , sym_link_name    = './NextPlotDir.Ewk'
                                       , do_merge = False
                                       )
    else:
        RunHelpers.runLxBatchMultiProcess( run_analysis_fun      = RunEwkNtupleMaker.runEwkNtupleFun
                                         , run_analysis_fun_loc  = '%s/EwkAnalysis/RunScripts/' % os.environ['BASE_WORK_DIR']
                                         , run_analysis_fun_file = 'RunEwkNtupleMaker'
                                         , data_set_dicts        = data_set_dicts
                                         , out_dir               = out_dir
                                         , queue                 = '1nh'
                                         , sym_link_name         = './NextPlotDir.Ewk'
                                         )

