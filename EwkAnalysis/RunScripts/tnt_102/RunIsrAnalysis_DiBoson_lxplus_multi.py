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

    full_sim_mc_samples = { 126892:{'label':'126892.Sherpa_CT10_llnunu_WW', 'num_jobs':10}
                          , 126988:{'label':'126988.Sherpa_CT10_llnunu_SS_EW6'  , 'num_jobs':1}
                          , 126989:{'label':'126989.Sherpa_CT10_llnunujj_SS'  , 'num_jobs':1}

                          , 157814:{'label':'157814.Sherpa_CT10_VVtoeeqq'  , 'num_jobs':1}
                          , 157815:{'label':'157815.Sherpa_CT10_VVtomumuqq'  , 'num_jobs':1}
                          , 157816:{'label':'157816.Sherpa_CT10_VVtotautauqq'  , 'num_jobs':1}
                          , 157817:{'label':'157817.Sherpa_CT10_VVtoenuqq'  , 'num_jobs':1}
                          , 157818:{'label':'157818.Sherpa_CT10_VVtomunuqq'  , 'num_jobs':1}
                          , 157819:{'label':'157819.Sherpa_CT10_VVtotaunuqq'  , 'num_jobs':1}

                          , 126928:{'label':'126928.PowhegPythia8_AU2CT10_WpWm_ee'  , 'num_jobs':1}
                          , 126929:{'label':'126929.PowhegPythia8_AU2CT10_WpWm_me'  , 'num_jobs':1}
                          , 126930:{'label':'126930.PowhegPythia8_AU2CT10_WpWm_te'  , 'num_jobs':1}
                          , 126931:{'label':'126931.PowhegPythia8_AU2CT10_WpWm_em'  , 'num_jobs':1}
                          , 126932:{'label':'126932.PowhegPythia8_AU2CT10_WpWm_mm'  , 'num_jobs':1}
                          , 126933:{'label':'126933.PowhegPythia8_AU2CT10_WpWm_tm'  , 'num_jobs':1}
                          , 126934:{'label':'126934.PowhegPythia8_AU2CT10_WpWm_et'  , 'num_jobs':1}
                          , 126935:{'label':'126935.PowhegPythia8_AU2CT10_WpWm_mt'  , 'num_jobs':1}
                          , 126936:{'label':'126936.PowhegPythia8_AU2CT10_WpWm_tt'  , 'num_jobs':1}

                          , 129477:{'label':'129477.PowhegPythia8_AU2CT10_WZ_Wm11Z11_mll0p250d0_2LeptonFilter5'  , 'num_jobs':1}
                          , 129478:{'label':'129478.PowhegPythia8_AU2CT10_WZ_Wm11Z13_mll0p4614d0_2LeptonFilter5' , 'num_jobs':1}
                          , 129479:{'label':'129479.PowhegPythia8_AU2CT10_WZ_Wm11Z15_mll3p804d0_2LeptonFilter5'  , 'num_jobs':1}
                          , 129480:{'label':'129480.PowhegPythia8_AU2CT10_WZ_Wm13Z11_mll0p250d0_2LeptonFilter5'  , 'num_jobs':1}
                          , 129481:{'label':'129481.PowhegPythia8_AU2CT10_WZ_Wm13Z13_mll0p4614d0_2LeptonFilter5' , 'num_jobs':1}
                          , 129482:{'label':'129482.PowhegPythia8_AU2CT10_WZ_Wm13Z15_mll3p804d0_2LeptonFilter5'  , 'num_jobs':1}
                          , 129483:{'label':'129483.PowhegPythia8_AU2CT10_WZ_Wm15Z11_mll0p250d0_2LeptonFilter5'  , 'num_jobs':1}
                          , 129484:{'label':'129484.PowhegPythia8_AU2CT10_WZ_Wm15Z13_mll0p4614d0_2LeptonFilter5' , 'num_jobs':1}
                          , 129485:{'label':'129485.PowhegPythia8_AU2CT10_WZ_Wm15Z15_mll3p804d0_2LeptonFilter5'  , 'num_jobs':1}
                          , 129486:{'label':'129486.PowhegPythia8_AU2CT10_WZ_W11Z11_mll0p250d0_2LeptonFilter5'   , 'num_jobs':1}
                          , 129487:{'label':'129487.PowhegPythia8_AU2CT10_WZ_W11Z13_mll0p4614d0_2LeptonFilter5'  , 'num_jobs':1}
                          , 129488:{'label':'129488.PowhegPythia8_AU2CT10_WZ_W11Z15_mll3p804d0_2LeptonFilter5'   , 'num_jobs':1}
                          , 129489:{'label':'129489.PowhegPythia8_AU2CT10_WZ_W13Z11_mll0p250d0_2LeptonFilter5'   , 'num_jobs':1}
                          , 129490:{'label':'129490.PowhegPythia8_AU2CT10_WZ_W13Z13_mll0p4614d0_2LeptonFilter5'  , 'num_jobs':1}
                          , 129491:{'label':'129491.PowhegPythia8_AU2CT10_WZ_W13Z15_mll3p804d0_2LeptonFilter5'   , 'num_jobs':1}
                          , 129492:{'label':'129492.PowhegPythia8_AU2CT10_WZ_W15Z11_mll0p250d0_2LeptonFilter5'   , 'num_jobs':1}
                          , 129493:{'label':'129493.PowhegPythia8_AU2CT10_WZ_W15Z13_mll0p4614d0_2LeptonFilter5'  , 'num_jobs':1}
                          , 129494:{'label':'129494.PowhegPythia8_AU2CT10_WZ_W15Z15_mll3p804d0_2LeptonFilter5'   , 'num_jobs':1}

                          , 116600:{'label':'116600.gg2ZZJimmy_AUET2CT10_ZZ4lep'  , 'num_jobs':1}
                          , 116601:{'label':'116601.gg2ZZJimmy_AUET2CT10_ZZ4e'  , 'num_jobs':1}
                          , 116602:{'label':'116602.gg2ZZJimmy_AUET2CT10_ZZ4mu'  , 'num_jobs':1}
                          , 116603:{'label':'116603.gg2ZZJimmy_AUET2CT10_ZZ2e2mu'  , 'num_jobs':1}
                          , 126937:{'label':'126937.PowhegPythia8_AU2CT10_ZZ_4e_mll4_2pt5'  , 'num_jobs':1}
                          , 126938:{'label':'126938.PowhegPythia8_AU2CT10_ZZ_2e2mu_mll4_2pt5'  , 'num_jobs':1}
                          , 126939:{'label':'126939.PowhegPythia8_AU2CT10_ZZ_2e2tau_mll4_2pt5'  , 'num_jobs':1}
                          , 126940:{'label':'126940.PowhegPythia8_AU2CT10_ZZ_4mu_mll4_2pt5'  , 'num_jobs':1}
                          , 126941:{'label':'126941.PowhegPythia8_AU2CT10_ZZ_2mu2tau_mll4_2pt5'  , 'num_jobs':1}
                          , 126942:{'label':'126942.PowhegPythia8_AU2CT10_ZZ_4tau_mll4_2pt5'  , 'num_jobs':1}
                          , 126949:{'label':'126949.PowhegPythia8_AU2CT10_ZZllnunu_ee_mll4'  , 'num_jobs':1}
                          , 126950:{'label':'126950.PowhegPythia8_AU2CT10_ZZllnunu_mm_mll4'  , 'num_jobs':1}
                          , 126951:{'label':'126951.PowhegPythia8_AU2CT10_ZZllnunu_tt_mll4'  , 'num_jobs':1}
                          }

    fast_sim_mc_samples = {
                          }

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
