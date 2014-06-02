#!/usr/bin/env python

import os
from multiprocessing import Pool
import time
import sys

sys.path.append('%s/BMinusLAnalysis/RunScripts/' % os.environ['BASE_WORK_DIR'])
import RunBMinusLAnalysis

# ------------------------------------------------------------------------------
# get number of parallel processes from command line inputs
num_processes = int(sys.argv[1]) if len(sys.argv) > 1 else 1

# ------------------------------------------------------------------------------
def runBMinusLAnalysisFun(data_set_dict):
    print '================================================================================'
    print 'label: %s'       % data_set_dict['label']
    print 'file_list: %s'   % data_set_dict['file_list']
    print 'is data: %s'     % data_set_dict['is_data']
    print 'is full sim: %s' % data_set_dict['is_full_sim']
    print 'dsid: %s'        % data_set_dict['dsid']

    print 'lep_pt_cut : %s' % data_set_dict['lep_pt_cut']
    print 'jet_pt_cut : %s' % data_set_dict['jet_pt_cut']
    print 'met_cut    : %s' % data_set_dict['met_cut']

    print 'total number jobs: %s' % data_set_dict['total_num_jobs']
    print 'this job number: %s' % data_set_dict['job_num']

    print 'total num events: %s' % data_set_dict['total_num_events']
    print 'total num entries: %s' % data_set_dict['total_num_entries']

    print 'About to run BMinusLAnalysis'
    RunBMinusLAnalysis.runBMinusLAnalysis( file_list             = data_set_dict['file_list']
                                         , is_data               = data_set_dict['is_data']
                                         , is_full_sim           = data_set_dict['is_full_sim']
                                         , tree_name             = 'TNT'
                                         , dsid                  = data_set_dict['dsid']
                                         , out_file_special_name = data_set_dict['label']
                                         , is_tnt                = True
                                         , lep_pt_cut            = data_set_dict['lep_pt_cut']
                                         , jet_pt_cut            = data_set_dict['jet_pt_cut']
                                         , met_cut               = data_set_dict['met_cut']
                                         , fancy_progress_bar    = False
                                         , job_num               = data_set_dict['job_num']
                                         , total_num_jobs        = data_set_dict['total_num_jobs']
                                         , total_num_events      = data_set_dict['total_num_events']
                                         , total_num_entries     = data_set_dict['total_num_entries']
                                         )

# ------------------------------------------------------------------------------
def makeDataSetDict( label_base
                   , file_list_path
                   , is_data
                   , is_full_sim
                   , dsid
                   , lep_pt_cut
                   , jet_pt_cut
                   , met_cut
                   , job_num=0
                   , total_num_jobs = 1
                   ):
    # label = '%s.%s' % (dsid, label_base)
    label = '%s' % (label_base)
    # label += '__lep_pt_%s' % lep_pt_cut
    # label += '__jet_pt_%s' % jet_pt_cut
    # label += '__met_%s'    % met_cut

    data_set_input = RunBMinusLAnalysis.readFileList('%s/%s' % (os.environ['BASE_WORK_DIR'], file_list_path))
    file_list = data_set_input['file_list']

    return { 'label':label
           , 'file_list':file_list
           , 'is_data':is_data
           , 'is_full_sim':is_full_sim
           , 'dsid':dsid
           , 'lep_pt_cut':lep_pt_cut
           , 'jet_pt_cut':jet_pt_cut
           , 'met_cut':met_cut
           , 'job_num':job_num
           , 'total_num_jobs':total_num_jobs
           }

# ------------------------------------------------------------------------------
def makeDataSetDictList( label_base
                       , file_list_path
                       , is_data
                       , is_full_sim
                       , dsid
                       , lep_pt_cut
                       , jet_pt_cut
                       , met_cut
                       , total_num_jobs = 1
                       ):
    total_num_entries = 0

    print 'getting raw events for %s' % label_base
    data_set_input = RunBMinusLAnalysis.readFileList('%s/%s' % (os.environ['BASE_WORK_DIR'], file_list_path))
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
                                            , lep_pt_cut     = lep_pt_cut
                                            , jet_pt_cut     = jet_pt_cut
                                            , met_cut        = met_cut
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

    met_cut    = 50.e3

    data_set_dicts = []
    # for lep_pt in [20.e3, 30.e3, 40.e3]:
    #     for jet_pt in [20.e3, 30.e3, 40.e3]:
    for lep_pt in [40.e3]:
        for jet_pt in [40.e3]:
            data_samples = {}
            full_sim_mc_samples = { # 110817:{'label':'110817.AlpgenPythia_P2011C_ZeebbNp0'    , 'num_jobs':1}
                                  }
            fast_sim_mc_samples = { 202641:{'label':'202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000', 'num_jobs':1}
                                  }
            # full_sim_mc_samples = { 117050:{'label':'117050.PowhegPythia_P2011C_ttbar'                 , 'num_jobs':15}
            #                       , 200332:{'label':'200332.AlpgenPythia_Auto_P2011C_ZeebbNp0'         , 'num_jobs':10}
            #                       , 200333:{'label':'200333.AlpgenPythia_Auto_P2011C_ZeebbNp1'         , 'num_jobs':5}
            #                       , 200334:{'label':'200334.AlpgenPythia_Auto_P2011C_ZeebbNp2'         , 'num_jobs':3}
            #                       , 200335:{'label':'200335.AlpgenPythia_Auto_P2011C_ZeebbNp3incl'     , 'num_jobs':1}
            #                       , 200340:{'label':'200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0'       , 'num_jobs':10}
            #                       , 200341:{'label':'200341.AlpgenPythia_Auto_P2011C_ZmumubbNp1'       , 'num_jobs':5}
            #                       , 200342:{'label':'200342.AlpgenPythia_Auto_P2011C_ZmumubbNp2'       , 'num_jobs':3}
            #                       , 200343:{'label':'200343.AlpgenPythia_Auto_P2011C_ZmumubbNp3incl'   , 'num_jobs':1}
            #                       , 200348:{'label':'200348.AlpgenPythia_Auto_P2011C_ZtautaubbNp0'     , 'num_jobs':1}
            #                       , 200349:{'label':'200349.AlpgenPythia_Auto_P2011C_ZtautaubbNp1'     , 'num_jobs':1}
            #                       , 200350:{'label':'200350.AlpgenPythia_Auto_P2011C_ZtautaubbNp2'     , 'num_jobs':1}
            #                       , 200351:{'label':'200351.AlpgenPythia_Auto_P2011C_ZtautaubbNp3incl' , 'num_jobs':1}
            #                       , 108346:{'label':'108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl', 'num_jobs':10}
            #                       , 110817:{'label':'110817.AlpgenPythia_P2011C_ZeebbNp0'    , 'num_jobs':1}
            #                       , 110818:{'label':'110818.AlpgenPythia_P2011C_ZeebbNp1'    , 'num_jobs':1}
            #                       , 110819:{'label':'110819.AlpgenPythia_P2011C_ZeebbNp2'    , 'num_jobs':1}
            #                       , 110820:{'label':'110820.AlpgenPythia_P2011C_ZeebbNp3'    , 'num_jobs':1}
            #                       , 110821:{'label':'110821.AlpgenPythia_P2011C_ZmumubbNp0'  , 'num_jobs':1}
            #                       , 110822:{'label':'110822.AlpgenPythia_P2011C_ZmumubbNp1'  , 'num_jobs':1}
            #                       , 110823:{'label':'110823.AlpgenPythia_P2011C_ZmumubbNp2'  , 'num_jobs':1}
            #                       , 110824:{'label':'110824.AlpgenPythia_P2011C_ZmumubbNp3'  , 'num_jobs':1}
            #                       , 110825:{'label':'110825.AlpgenPythia_P2011C_ZtautaubbNp0', 'num_jobs':1}
            #                       , 110826:{'label':'110826.AlpgenPythia_P2011C_ZtautaubbNp1', 'num_jobs':1}
            #                       , 110827:{'label':'110827.AlpgenPythia_P2011C_ZtautaubbNp2', 'num_jobs':1}
            #                       , 110828:{'label':'110828.AlpgenPythia_P2011C_ZtautaubbNp3', 'num_jobs':1}
            #                       }
            # fast_sim_mc_samples = { 105200:{'label':'105200.McAtNloJimmy_CT10_ttbar_LeptonFilter', 'num_jobs':15}
            #                       , 202632:{'label':'202632.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_100' , 'num_jobs':1}
            #                       , 202633:{'label':'202633.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_200' , 'num_jobs':1}
            #                       , 202634:{'label':'202634.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_300' , 'num_jobs':1}
            #                       , 202635:{'label':'202635.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_400' , 'num_jobs':1}
            #                       , 202636:{'label':'202636.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_500' , 'num_jobs':1}
            #                       , 202637:{'label':'202637.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_600' , 'num_jobs':1}
            #                       , 202638:{'label':'202638.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_700' , 'num_jobs':1}
            #                       , 202639:{'label':'202639.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_800' , 'num_jobs':1}
            #                       , 202640:{'label':'202640.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_900' , 'num_jobs':1}
            #                       , 202641:{'label':'202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000', 'num_jobs':1}
            #                       }

            for dsid in data_samples:
                print dsid

            for dsid in full_sim_mc_samples:
                these_data_set_dicts = makeDataSetDictList( label_base=full_sim_mc_samples[dsid]['label']
                                                          , file_list_path = 'EosFileLists/tnt_102/tnt_102.%s.txt' % full_sim_mc_samples[dsid]['label']
                                                          , is_data = False
                                                          , is_full_sim = True
                                                          , dsid = dsid
                                                          , lep_pt_cut = lep_pt
                                                          , jet_pt_cut = jet_pt
                                                          , met_cut = met_cut
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
                                                          , lep_pt_cut = lep_pt
                                                          , jet_pt_cut = jet_pt
                                                          , met_cut = met_cut
                                                          , total_num_jobs = fast_sim_mc_samples[dsid]['num_jobs']
                                                          )

                for tdsd in these_data_set_dicts:
                    data_set_dicts.append(tdsd)

    print data_set_dicts

    p = Pool(num_processes)
    p.map(runBMinusLAnalysisFun, data_set_dicts)
