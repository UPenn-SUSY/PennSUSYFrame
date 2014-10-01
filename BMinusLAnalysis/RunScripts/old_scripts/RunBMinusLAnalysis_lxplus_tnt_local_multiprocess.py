#!/usr/bin/env python

import RunBMinusLAnalysis
import os
from multiprocessing import Pool
import time
import sys

# ------------------------------------------------------------------------------
# get number of parallel processes from command line inputs
num_processes = int(sys.argv[1]) if len(sys.argv) > 1 else 1

def runBMinusLAnalysisFun(data_set_dict):
    print 'label: %s'       % data_set_dict['label']
    print 'file_list: %s'   % data_set_dict['label']
    print 'is data: %s'     % data_set_dict['is_data']
    print 'is full sim: %s' % data_set_dict['is_full_sim']
    print 'dsid: %s'        % data_set_dict['dsid']

    print 'lep_pt_cut : %s' % data_set_dict['lep_pt_cut']
    print 'jet_pt_cut : %s' % data_set_dict['jet_pt_cut']
    print 'met_cut    : %s' % data_set_dict['met_cut']


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
                                         )

# ------------------------------------------------------------------------------
def makeDataSetDict(label_base, file_list_path, is_data, is_full_sim, dsid, lep_pt_cut, jet_pt_cut, met_cut):
    label = '%s.%s' % (dsid, label_base)
    label += '__lep_pt_%s' % lep_pt_cut
    label += '__jet_pt_%s' % jet_pt_cut
    label += '__met_%s'    % met_cut

    return { 'label':label
           , 'file_list':RunBMinusLAnalysis.getFileListFromFile('%s/%s' % (os.environ['BASE_WORK_DIR'], file_list_path))
           , 'is_data':is_data
           , 'is_full_sim':is_full_sim
           , 'dsid':dsid
           , 'lep_pt_cut':lep_pt_cut
           , 'jet_pt_cut':jet_pt_cut
           , 'met_cut':met_cut
           }

# ==============================================================================
if __name__ == '__main__':
    print 'getting file list'

    met_cut    = 50.e3

    data_set_dicts = []
    for lep_pt in [20.e3, 30.e3, 40.e3]:
        for jet_pt in [20.e3, 30.e3, 40.e3]:
            data_set_dicts.append( makeDataSetDict(label_base='ttbar'        , file_list_path = 'EosFileLists/tnt_local.105200.ttbar.txt'        , is_data = False , is_full_sim = False , dsid = 105200 , lep_pt_cut = lep_pt , jet_pt_cut = jet_pt , met_cut = met_cut ) )
            data_set_dicts.append( makeDataSetDict(label_base='ZeebbNp0'     , file_list_path = 'EosFileLists/tnt_local.110817.ZeebbNp0.txt'     , is_data = False , is_full_sim = True  , dsid = 110817 , lep_pt_cut = lep_pt , jet_pt_cut = jet_pt , met_cut = met_cut ) )
            data_set_dicts.append( makeDataSetDict(label_base='ZeebbNp1'     , file_list_path = 'EosFileLists/tnt_local.110818.ZeebbNp1.txt'     , is_data = False , is_full_sim = True  , dsid = 110818 , lep_pt_cut = lep_pt , jet_pt_cut = jet_pt , met_cut = met_cut ) )
            data_set_dicts.append( makeDataSetDict(label_base='ZeebbNp2'     , file_list_path = 'EosFileLists/tnt_local.110819.ZeebbNp2.txt'     , is_data = False , is_full_sim = True  , dsid = 110819 , lep_pt_cut = lep_pt , jet_pt_cut = jet_pt , met_cut = met_cut ) )
            data_set_dicts.append( makeDataSetDict(label_base='ZeebbNp3'     , file_list_path = 'EosFileLists/tnt_local.110820.ZeebbNp3.txt'     , is_data = False , is_full_sim = True  , dsid = 110820 , lep_pt_cut = lep_pt , jet_pt_cut = jet_pt , met_cut = met_cut ) )
            data_set_dicts.append( makeDataSetDict(label_base='ZmumubbNp0'   , file_list_path = 'EosFileLists/tnt_local.110821.ZmumubbNp0.txt'   , is_data = False , is_full_sim = True  , dsid = 110821 , lep_pt_cut = lep_pt , jet_pt_cut = jet_pt , met_cut = met_cut ) )
            data_set_dicts.append( makeDataSetDict(label_base='ZmumubbNp1'   , file_list_path = 'EosFileLists/tnt_local.110822.ZmumubbNp1.txt'   , is_data = False , is_full_sim = True  , dsid = 110822 , lep_pt_cut = lep_pt , jet_pt_cut = jet_pt , met_cut = met_cut ) )
            data_set_dicts.append( makeDataSetDict(label_base='ZmumubbNp2'   , file_list_path = 'EosFileLists/tnt_local.110823.ZmumubbNp2.txt'   , is_data = False , is_full_sim = True  , dsid = 110823 , lep_pt_cut = lep_pt , jet_pt_cut = jet_pt , met_cut = met_cut ) )
            data_set_dicts.append( makeDataSetDict(label_base='ZmumubbNp3'   , file_list_path = 'EosFileLists/tnt_local.110824.ZmumubbNp3.txt'   , is_data = False , is_full_sim = True  , dsid = 110824 , lep_pt_cut = lep_pt , jet_pt_cut = jet_pt , met_cut = met_cut ) )
            data_set_dicts.append( makeDataSetDict(label_base='ZtautaubbNp0' , file_list_path = 'EosFileLists/tnt_local.110825.ZtautaubbNp0.txt' , is_data = False , is_full_sim = True  , dsid = 110825 , lep_pt_cut = lep_pt , jet_pt_cut = jet_pt , met_cut = met_cut ) )
            data_set_dicts.append( makeDataSetDict(label_base='ZtautaubbNp1' , file_list_path = 'EosFileLists/tnt_local.110826.ZtautaubbNp1.txt' , is_data = False , is_full_sim = True  , dsid = 110826 , lep_pt_cut = lep_pt , jet_pt_cut = jet_pt , met_cut = met_cut ) )
            data_set_dicts.append( makeDataSetDict(label_base='ZtautaubbNp2' , file_list_path = 'EosFileLists/tnt_local.110827.ZtautaubbNp2.txt' , is_data = False , is_full_sim = True  , dsid = 110827 , lep_pt_cut = lep_pt , jet_pt_cut = jet_pt , met_cut = met_cut ) )
            data_set_dicts.append( makeDataSetDict(label_base='ZtautaubbNp3' , file_list_path = 'EosFileLists/tnt_local.110828.ZtautaubbNp3.txt' , is_data = False , is_full_sim = True  , dsid = 110828 , lep_pt_cut = lep_pt , jet_pt_cut = jet_pt , met_cut = met_cut ) )

    p = Pool(num_processes)
    p.map(runBMinusLAnalysisFun, data_set_dicts)

