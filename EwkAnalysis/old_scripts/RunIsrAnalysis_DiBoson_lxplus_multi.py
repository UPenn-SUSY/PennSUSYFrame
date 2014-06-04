#!/usr/bin/env python

import RunIsrAnalysis
import os
from multiprocessing import Pool
import time
import sys

# ------------------------------------------------------------------------------
# get number of parallel processes from command line inputs
num_processes = int(sys.argv[1]) if len(sys.argv) > 1 else 1

# ------------------------------------------------------------------------------
def runIsrAnalysisFun(data_set_dict):
    print '================================================================================'
    print 'label: %s'       % data_set_dict['label']
    print 'file_list: %s'   % data_set_dict['file_list']
    print 'is data: %s'     % data_set_dict['is_data']
    print 'is full sim: %s' % data_set_dict['is_full_sim']
    print 'dsid: %s'        % data_set_dict['dsid']

    print 'total number jobs: %s' % data_set_dict['total_num_jobs']
    print 'this job number: %s' % data_set_dict['job_num']

    print 'total num events: %s' % data_set_dict['total_num_events']
    print 'total num entries: %s' % data_set_dict['total_num_entries']

    print 'About to run IsrAnalysis'
    RunIsrAnalysis.runIsrAnalysis( file_list             = data_set_dict['file_list']
                                 , is_data               = data_set_dict['is_data']
                                 , is_full_sim           = data_set_dict['is_full_sim']
                                 , tree_name             = 'TNT'
                                 # , tree_name             = 'susy'
                                 , dsid                  = data_set_dict['dsid']
                                 , out_file_special_name = data_set_dict['label']
                                 , is_tnt                = False
                                 , fancy_progress_bar    = False
                                 , job_num               = data_set_dict['job_num']
                                 , total_num_jobs        = data_set_dict['total_num_jobs']
                                 , total_num_events      = data_set_dict['total_num_events']
                                 , total_num_entries     = data_set_dict['total_num_entries']
                                 )

#------------------------------------------------------------------------------
def makeDataSetDict( label_base
                   , file_list_path
                   , is_data
                   , is_full_sim
                   , dsid
                   , job_num=0
                   , total_num_jobs = 1
                   ):

##    if(is_data == True):
##        label = '%s' % label_base
##    else:
##        label = '%s.%s' % (dsid, label_base)
##

    label = '%s' % label_base

    data_set_input = RunIsrAnalysis.readFileList('%s/%s' % (os.environ['BASE_WORK_DIR'], file_list_path))
    file_list = data_set_input['file_list']

    return { 'label':label
           # , 'file_list':RunIsrAnalysis.getFileListFromDir(file_list_path)
           , 'file_list':file_list
           , 'is_data':is_data
           , 'is_full_sim':is_full_sim
           , 'dsid':dsid
           , 'job_num':job_num
           , 'total_num_jobs':total_num_jobs
           }

# ------------------------------------------------------------------------------
def makeDataSetDictList( label_base
                       , file_list_path
                       , is_data
                       , is_full_sim
                       , dsid
                       , total_num_jobs = 1
                       ):
    total_num_entries = 0

    print 'getting raw events for %s' % label_base
    data_set_input = RunIsrAnalysis.readFileList('%s/%s' % (os.environ['BASE_WORK_DIR'], file_list_path))
    file_list         = data_set_input['file_list']
    total_num_events  = data_set_input['total_num_events']
    total_num_entries = data_set_input['total_entries']

    print 'total num events: %s' % total_num_events
    print 'total entries: %s' % total_num_entries

    data_set_dict_list = []
    for tnj in xrange(total_num_jobs):
        this_data_set_dict = makeDataSetDict( label_base     = label_base
                                            , file_list_path = file_list_path
                                            , is_data        = is_data
                                            , is_full_sim    = is_full_sim
                                            , dsid           = dsid
                                            , job_num        = tnj
                                            , total_num_jobs = total_num_jobs
                                            )
        this_data_set_dict['total_num_events']  = total_num_events
        this_data_set_dict['total_num_entries'] = total_num_entries
        data_set_dict_list.append(this_data_set_dict)

    return data_set_dict_list


# ==============================================================================
if __name__ == '__main__':
    print 'getting file list'

    eos_base_path = '/afs/cern.ch/user/e/ehines/eos_mount/atlas/user/b/bjackson/mc12/'

    data_set_dicts = []

    data_samples = {}
    
    #full_sim_mc_samples = { 117655:{'label':'117655.AlpgenPythia_P2011C_ZeeNp5'       , 'num_jobs':1}
    full_sim_mc_samples = {126892:{'label':'126892.Sherpa_CT10_llnunu_WW', 'num_jobs':10}
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
    fast_sim_mc_samples = {}


    for dsid in data_samples:
        
        these_data_set_dicts = makeDataSetDictList( label_base=data_samples[dsid]['label']
                                                    , file_list_path = 'EosFileLists/tnt_102/tnt_102.%s.txt' % data_samples[dsid]['label']
                                                    , is_data = True
                                                    , is_full_sim = False
                                                    , dsid = 1
                                                    , total_num_jobs = data_samples[dsid]['num_jobs']
                                                    )
        for tdsd in these_data_set_dicts:
            data_set_dicts.append(tdsd)
                                                    
        # TODO add stuff for data samples!

    for dsid in full_sim_mc_samples:
        these_data_set_dicts = makeDataSetDictList( label_base=full_sim_mc_samples[dsid]['label']
                                                  , file_list_path = 'EosFileLists/tnt_102/tnt_102.%s.txt' % full_sim_mc_samples[dsid]['label']
                                                  , is_data = False
                                                  , is_full_sim = True
                                                  , dsid = dsid
                                                  , total_num_jobs = full_sim_mc_samples[dsid]['num_jobs']
                                                  )

        for tdsd in these_data_set_dicts:
            data_set_dicts.append(tdsd)

    for dsid in fast_sim_mc_samples:
        these_data_set_dicts = makeDataSetDictList( label_base=fast_sim_mc_samples[dsid]['label']
                                                  , file_list_path = 'EosFileLists/tnt_102/tnt_102.%s.txt' % fast_sim_mc_samples[dsid]['label']
                                                  , is_data = False
                                                  , is_full_sim = False
                                                  , dsid = dsid
                                                  , total_num_jobs = fast_sim_mc_samples[dsid]['num_jobs']
                                                  )

        for tdsd in these_data_set_dicts:
            data_set_dicts.append(tdsd)

    print data_set_dicts

    p = Pool(num_processes)
    p.map(runIsrAnalysisFun, data_set_dicts)

