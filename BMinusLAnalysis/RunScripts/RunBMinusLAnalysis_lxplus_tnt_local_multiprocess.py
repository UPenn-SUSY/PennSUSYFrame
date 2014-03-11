#!/usr/bin/env python

import RunBMinusLAnalysis
import os
from multiprocessing import Pool
import time
import sys

lep_pt_cut = int(sys.argv[1])*1000
jet_pt_cut = int(sys.argv[2])*1000
met_cut    = int(sys.argv[3])*1000


def testfun(data_set_dict):
    print 'label: %s'       % data_set_dict['label']
    print 'file_list: %s'   % data_set_dict['label']
    print 'is data: %s'     % data_set_dict['is_data']
    print 'is full sim: %s' % data_set_dict['is_full_sim']
    print 'dsid: %s'        % data_set_dict['dsid']

    print 'lep_pt_cut : %s' % lep_pt_cut
    print 'jet_pt_cut : %s' % jet_pt_cut
    print 'met_cut    : %s' % met_cut


    print 'About to run BMinusLAnalysis'
    RunBMinusLAnalysis.runBMinusLAnalysis( file_list             = data_set_dict['file_list']
                                         , is_data               = data_set_dict['is_data']
                                         , is_full_sim           = data_set_dict['is_full_sim']
                                         , tree_name             = 'TNT'
                                         , dsid                  = data_set_dict['dsid']
                                         , out_file_special_name = data_set_dict['label']
                                         , is_tnt                = True
                                         , lep_pt_cut = lep_pt_cut
                                         , jet_pt_cut = jet_pt_cut
                                         , met_cut    = met_cut
                                         )

# ==============================================================================
if __name__ == '__main__':
    print 'getting file list'

    print sys.argv

    data_set_dicts = []
    data_set_dicts.append( { 'label':'105200.ttbar'        , 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.105200.ttbar.txt'        % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':False , 'dsid':105200 } )
    data_set_dicts.append( { 'label':'110817.ZeebbNp0'     , 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110817.ZeebbNp0.txt'     % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110817 } )
    data_set_dicts.append( { 'label':'110818.ZeebbNp1'     , 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110818.ZeebbNp1.txt'     % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110818 } )
    data_set_dicts.append( { 'label':'110819.ZeebbNp2'     , 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110819.ZeebbNp2.txt'     % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110819 } )
    data_set_dicts.append( { 'label':'110820.ZeebbNp3'     , 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110820.ZeebbNp3.txt'     % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110820 } )
    data_set_dicts.append( { 'label':'110821.ZmumubbNp0'   , 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110821.ZmumubbNp0.txt'   % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110821 } )
    data_set_dicts.append( { 'label':'110822.ZmumubbNp1'   , 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110822.ZmumubbNp1.txt'   % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110822 } )
    data_set_dicts.append( { 'label':'110823.ZmumubbNp2'   , 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110823.ZmumubbNp2.txt'   % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110823 } )
    data_set_dicts.append( { 'label':'110824.ZmumubbNp3'   , 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110824.ZmumubbNp3.txt'   % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110824 } )
    data_set_dicts.append( { 'label':'110825.ZtautaubbNp0' , 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110825.ZtautaubbNp0.txt' % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110825 } )
    data_set_dicts.append( { 'label':'110826.ZtautaubbNp1' , 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110826.ZtautaubbNp1.txt' % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110826 } )
    data_set_dicts.append( { 'label':'110827.ZtautaubbNp2' , 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110827.ZtautaubbNp2.txt' % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110827 } )
    data_set_dicts.append( { 'label':'110828.ZtautaubbNp3' , 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/EosFileLists/tnt_local.110828.ZtautaubbNp3.txt' % os.environ['BASE_WORK_DIR']) , 'is_data':False , 'is_full_sim':True  , 'dsid':110828 } )

    p = Pool(10)
    p.map(testfun, data_set_dicts)

