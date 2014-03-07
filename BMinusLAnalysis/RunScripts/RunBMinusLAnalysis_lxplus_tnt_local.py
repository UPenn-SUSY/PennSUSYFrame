#!/usr/bin/env python

import RunBMinusLAnalysis
import os

# ==============================================================================
if __name__ == '__main__':
    print 'getting file list'

    # file_list = RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.105200.ttbar.txt' % os.environ['BASE_WORK_DIR'])
    # file_list = file_list[:1]
    # file_list = file_list[15:16]

    # print 'file list: %s' % file_list

    # print ''
    # print 'About to run BMinusLAnalysis'
    # RunBMinusLAnalysis.runBMinusLAnalysis( file_list = file_list
    #                                      , is_data = False
    #                                      # , is_full_sim = True
    #                                      , is_full_sim = False
    #                                      , tree_name = 'TNT'
    #                                      , dsid = 105200
    #                                      , out_file_special_name = '105200.ttbar'
    #                                      , is_tnt = True
    #                                      )

    data_set_dicts = {}
    data_set_dicts['105200.ttbar']        = { 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.105200.ttbar.txt'        % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':False , 'dsid':105200 }
    # data_set_dicts['110817.ZeebbNp0']     = { 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110817.ZeebbNp0.txt'     % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110817 }
    # data_set_dicts['110818.ZeebbNp1']     = { 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110818.ZeebbNp1.txt'     % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110818 }
    # data_set_dicts['110819.ZeebbNp2']     = { 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110819.ZeebbNp2.txt'     % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110819 }
    # data_set_dicts['110820.ZeebbNp3']     = { 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110820.ZeebbNp3.txt'     % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110820 }
    # data_set_dicts['110821.ZmumubbNp0']   = { 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110821.ZmumubbNp0.txt'   % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110821 }
    # data_set_dicts['110822.ZmumubbNp1']   = { 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110822.ZmumubbNp1.txt'   % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110822 }
    # data_set_dicts['110823.ZmumubbNp2']   = { 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110823.ZmumubbNp2.txt'   % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110823 }
    # data_set_dicts['110824.ZmumubbNp3']   = { 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110824.ZmumubbNp3.txt'   % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110824 }
    # data_set_dicts['110825.ZtautaubbNp0'] = { 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110825.ZtautaubbNp0.txt' % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110825 }
    # data_set_dicts['110826.ZtautaubbNp1'] = { 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110826.ZtautaubbNp1.txt' % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110826 }
    # data_set_dicts['110827.ZtautaubbNp2'] = { 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110827.ZtautaubbNp2.txt' % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110827 }
    # data_set_dicts['110828.ZtautaubbNp3'] = { 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110828.ZtautaubbNp3.txt' % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110828 }

    for dsd in data_set_dicts:
        print 'tag: %s' % dsd
        print 'file list: %s' % data_set_dicts[dsd]['file_list']
        print ''
        print 'About to run BMinusLAnalysis'
        RunBMinusLAnalysis.runBMinusLAnalysis( file_list            = data_set_dicts[dsd]['file_list']
                                            , is_data               = data_set_dicts[dsd]['is_data']
                                            , is_full_sim           = data_set_dicts[dsd]['is_full_sim']
                                            , tree_name             = 'TNT'
                                            , dsid                  = data_set_dicts[dsd]['dsid']
                                            , out_file_special_name = dsd
                                            , is_tnt                = True
                                            )

