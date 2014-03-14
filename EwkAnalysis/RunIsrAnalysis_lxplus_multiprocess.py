#!/usr/bin/env python

import RunIsrAnalysis
import os
from multiprocessing import Pool
import time
import sys

# ------------------------------------------------------------------------------
# get number of parallel processes from command line inputs
num_processes = int(sys.argv[1]) if len(sys.argv) > 1 else 1

def runIsrAnalysisFun(data_set_dict):
    print 'label: %s'       % data_set_dict['label']
    print 'file_list: %s'   % data_set_dict['label']
    print 'is data: %s'     % data_set_dict['is_data']
    print 'is full sim: %s' % data_set_dict['is_full_sim']
    print 'dsid: %s'        % data_set_dict['dsid']

    print 'About to run IsrAnalysis'
    RunIsrAnalysis.runIsrAnalysis( file_list             = data_set_dict['file_list']
                                         , is_data               = data_set_dict['is_data']
                                         , is_full_sim           = data_set_dict['is_full_sim']
                                         , tree_name             = 'susy'
                                         , dsid                  = data_set_dict['dsid']
                                         , out_file_special_name = data_set_dict['label']
                                         , is_tnt                = False
                                         , fancy_progress_bar    = False
                                         )
#------------------------------------------------------------------------------
def makeDataSetDict(label_base, file_list_path, is_data, is_full_sim, dsid):
    label = '%s.%s' % (dsid, label_base)


    return { 'label':label
           , 'file_list':RunIsrAnalysis.getFileListFromDir(file_list_path)
           , 'is_data':is_data
           , 'is_full_sim':is_full_sim
           , 'dsid':dsid
           }

# ==============================================================================
if __name__ == '__main__':
    print 'getting file list'

    eos_base_path = '/afs/cern.ch/user/e/ehines/eos_mount/atlas/user/b/bjackson/mc12/'

    data_set_dicts = []

    data_set_dicts.append( makeDataSetDict(label_base='ZeeNp0'     , file_list_path = eos_base_path + 'mc12_8TeV.117650.AlpgenPythia_P2011C_ZeeNp0*/', is_data = False , is_full_sim = True , dsid = 117650 ) )
    data_set_dicts.append( makeDataSetDict(label_base='ZeeNp1'     , file_list_path = eos_base_path + 'mc12_8TeV.117651.AlpgenPythia_P2011C_ZeeNp1*/', is_data = False , is_full_sim = True , dsid = 117651 ) )
    ##data_set_dicts.append( makeDataSetDict(label_base='ZeeNp2'     , file_list_path = eos_base_path + 'mc12_8TeV.117652.AlpgenPythia_P2011C_ZeeNp2*/', is_data = False , is_full_sim = True , dsid = 117652 ) )
    ##data_set_dicts.append( makeDataSetDict(label_base='ZeeNp3'     , file_list_path = eos_base_path + 'mc12_8TeV.117653.AlpgenPythia_P2011C_ZeeNp3*/', is_data = False , is_full_sim = True , dsid = 117653 ) )
    ##data_set_dicts.append( makeDataSetDict(label_base='ZeeNp4'     , file_list_path = eos_base_path + 'mc12_8TeV.117654.AlpgenPythia_P2011C_ZeeNp4*/', is_data = False , is_full_sim = True , dsid = 117654 ) )
    ##data_set_dicts.append( makeDataSetDict(label_base='ZeeNp5'     , file_list_path = eos_base_path + 'mc12_8TeV.117655.AlpgenPythia_P2011C_ZeeNp5*/', is_data = False , is_full_sim = True , dsid = 117655 ) )
    ##
    ##data_set_dicts.append( makeDataSetDict(label_base='ZmumuNp0'     , file_list_path = eos_base_path + 'mc12_8TeV.117660.AlpgenPythia_P2011C_ZmumuNp0*/', is_data = False , is_full_sim = True , dsid = 117660 ) )
    ##data_set_dicts.append( makeDataSetDict(label_base='ZmumuNp1'     , file_list_path = eos_base_path + 'mc12_8TeV.117661.AlpgenPythia_P2011C_ZmumuNp1*/', is_data = False , is_full_sim = True , dsid = 117661 ) )
    ##data_set_dicts.append( makeDataSetDict(label_base='ZmumuNp2'     , file_list_path = eos_base_path + 'mc12_8TeV.117662.AlpgenPythia_P2011C_ZmumuNp2*/', is_data = False , is_full_sim = True , dsid = 117662 ) )
    ##data_set_dicts.append( makeDataSetDict(label_base='ZmumuNp3'     , file_list_path = eos_base_path + 'mc12_8TeV.117663.AlpgenPythia_P2011C_ZmumuNp3*/', is_data = False , is_full_sim = True , dsid = 117663 ) )
    ##data_set_dicts.append( makeDataSetDict(label_base='ZmumuNp4'     , file_list_path = eos_base_path + 'mc12_8TeV.117664.AlpgenPythia_P2011C_ZmumuNp4*/', is_data = False , is_full_sim = True , dsid = 117664 ) )
    ##data_set_dicts.append( makeDataSetDict(label_base='ZmumuNp5'     , file_list_path = eos_base_path + 'mc12_8TeV.117665.AlpgenPythia_P2011C_ZmumuNp5*/', is_data = False , is_full_sim = True , dsid = 117665 ) )

    p = Pool(num_processes)
    p.map(runIsrAnalysisFun, data_set_dicts)

