#!/usr/bin/env python

import os
import sys

sys.path.append('%s/TntMaker/' % os.environ['BASE_WORK_DIR'])
import RunTntMaker

sys.path.append('%s/RunHelpers/' % os.environ['BASE_WORK_DIR'])
import RunHelpers

# ==============================================================================
if __name__ == '__main__':
    base_work_dir = os.environ['BASE_WORK_DIR']
    print 'getting file list'

    data_set_dicts = []
    RunHelpers.addSamplesToList( sample_dict = {'label':'202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000' , 'num_jobs':1}
                               , data_set_dicts = data_set_dicts
                               # , file_list_path = '%s/EosFileLists/local/raw_d3pd.202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000.txt' % os.environ['BASE_WORK_DIR']
                               , file_list_path = 'EosFileLists/local/raw_d3pd.202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000.txt'
                               , is_data = False
                               , is_egamma_stream = False
                               , is_full_sim = False
                               , dsid = 202641
                               , out_dir = 'local_tnt'
                               )

    print ''
    print data_set_dicts
    print ''
    RunTntMaker.runTntMaker( file_list = data_set_dicts[0]['file_list']
                           , is_data = False
                           , is_full_sim = False
                           )

    # # file_list = RunTntMaker.getFileListFromFile('%s/EosFileLists/local/raw_d3pd.202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000.txt' % os.environ['BASE_WORK_DIR'])
    # # file_list = file_list[:1]

    # print 'file list: %s' % file_list

    # print ''
    # print 'About to run TntMaker'
    # RunTntMaker.runTntMaker( file_list = file_list
    #                        , is_data = False
    #                        # , is_full_sim = True
    #                        , is_full_sim = False
    #                        # , tree_name = 'susy'
    #                        # , dsid = 105200
    #                        # , out_file_special_name = '105200.ttbar'
    #                        )
