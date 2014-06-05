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
num_processes = int(sys.argv[1]) if len(sys.argv) > 1 else 1

out_dir = 'hists/isr_hists%s' % RunHelpers.getDateTimeLabel(True, False)

# ==============================================================================
if __name__ == '__main__':
    RunHelpers.safeMakeDir(out_dir)

    print 'getting file list'
    data_set_dicts = []
    data_samples = {# 'periodA_egamma':{'label':'periodA_egamma'       , 'num_jobs':10}
                   ## , 'periodB_egamma':{'label':'periodB_egamma'      , 'num_jobs':10} ##THIS ONE
                   ## , 'periodC_egamma':{'label':'periodC_egamma'      , 'num_jobs':10}
                   ## , 'periodD_egamma':{'label':'periodD_egamma'      , 'num_jobs':10} ##THIS ONE TOO
                   ## , 'periodE_egamma':{'label':'periodE_egamma'      , 'num_jobs':10}
                   ## , 'periodA_muon':{'label':'periodA_muon'          , 'num_jobs':10}
                   ## , 'periodB_muon':{'label':'periodB_muon'          , 'num_jobs':10}
                   ## , 'periodC_muon':{'label':'periodC_muon'          , 'num_jobs':10}
                   ## , 'periodD_muon':{'label':'periodD_muon'          , 'num_jobs':10}
                   ## , 'periodE_muon':{'label':'periodE_muon'          , 'num_jobs':10}
                   }

    full_sim_mc_samples = { 117650:{'label':'117650.AlpgenPythia_P2011C_ZeeNp0'       , 'num_jobs':10}
                          , 117651:{'label':'117651.AlpgenPythia_P2011C_ZeeNp1'       , 'num_jobs':10}
                          , 117652:{'label':'117652.AlpgenPythia_P2011C_ZeeNp2'       , 'num_jobs':5}
                          , 117653:{'label':'117653.AlpgenPythia_P2011C_ZeeNp3'       , 'num_jobs':1}
                          , 117654:{'label':'117654.AlpgenPythia_P2011C_ZeeNp4'       , 'num_jobs':1}
                          , 117655:{'label':'117655.AlpgenPythia_P2011C_ZeeNp5'       , 'num_jobs':1}

                          , 117660:{'label':'117660.AlpgenPythia_P2011C_ZmumuNp0'     , 'num_jobs':10}
                          , 117661:{'label':'117661.AlpgenPythia_P2011C_ZmumuNp1'     , 'num_jobs':10}
                          , 117662:{'label':'117662.AlpgenPythia_P2011C_ZmumuNp2'     , 'num_jobs':5}
                          , 117663:{'label':'117663.AlpgenPythia_P2011C_ZmumuNp3'     , 'num_jobs':1}
                          , 117664:{'label':'117664.AlpgenPythia_P2011C_ZmumuNp4'     , 'num_jobs':1}
                          , 117665:{'label':'117665.AlpgenPythia_P2011C_ZmumuNp5'     , 'num_jobs':1}

                           ## , 110805:{'label':'110805.AlpgenPythia_P2011C_ZeeccNp0'     , 'num_jobs':1}
                           ## , 110806:{'label':'110806.AlpgenPythia_P2011C_ZeeccNp1'     , 'num_jobs':1}
                           ## , 110807:{'label':'110807.AlpgenPythia_P2011C_ZeeccNp2'     , 'num_jobs':1}
                           ## , 110808:{'label':'110808.AlpgenPythia_P2011C_ZeeccNp3'     , 'num_jobs':1}
                           ##
                           ## , 110817:{'label':'110817.AlpgenPythia_P2011C_ZeebbNp0'     , 'num_jobs':1}
                           ## , 110818:{'label':'110818.AlpgenPythia_P2011C_ZeebbNp1'     , 'num_jobs':1}
                           ## , 110819:{'label':'110819.AlpgenPythia_P2011C_ZeebbNp2'     , 'num_jobs':1}
                           ## , 110820:{'label':'110820.AlpgenPythia_P2011C_ZeebbNp3'     , 'num_jobs':1}
                           ##
                           ## , 110809:{'label':'110809.AlpgenPythia_P2011C_ZmumuccNp0'   , 'num_jobs':1}
                           ## , 110810:{'label':'110810.AlpgenPythia_P2011C_ZmumuccNp1'   , 'num_jobs':1}
                           ## , 110811:{'label':'110811.AlpgenPythia_P2011C_ZmumuccNp2'   , 'num_jobs':1}
                           ## , 110812:{'label':'110812.AlpgenPythia_P2011C_ZmumuccNp3'   , 'num_jobs':1}
                           ##
                           ## , 110821:{'label':'110821.AlpgenPythia_P2011C_ZmumubbNp0'    , 'num_jobs':1}
                           ## , 110822:{'label':'110822.AlpgenPythia_P2011C_ZmumubbNp1'    , 'num_jobs':1}
                           ## , 110823:{'label':'110823.AlpgenPythia_P2011C_ZmumubbNp2'    , 'num_jobs':1}
                           ## , 110824:{'label':'110824.AlpgenPythia_P2011C_ZmumubbNp3'    , 'num_jobs':1}
                           ##
                           ##  117670:{'label':'117670.AlpgenPythia_P2011C_ZtautauNp0'     , 'num_jobs':10}
                           ## , 117671:{'label':'117671.AlpgenPythia_P2011C_ZtautauNp1'     , 'num_jobs':10}
                           ## , 117672:{'label':'117672.AlpgenPythia_P2011C_ZtautauNp2'     , 'num_jobs':5}
                           ## , 117673:{'label':'117673.AlpgenPythia_P2011C_ZtautauNp3'     , 'num_jobs':1}
                           ## , 117674:{'label':'117674.AlpgenPythia_P2011C_ZtautauNp4'     , 'num_jobs':1}
                           ## , 117675:{'label':'117675.AlpgenPythia_P2011C_ZtautauNp5'     , 'num_jobs':1}
                           ##
                           ## , 110813:{'label':'110813.AlpgenPythia_P2011C_ZtautauccNp0'   , 'num_jobs':1}
                           ## , 110814:{'label':'110814.AlpgenPythia_P2011C_ZtautauccNp1'   , 'num_jobs':1}
                           ## , 110815:{'label':'110815.AlpgenPythia_P2011C_ZtautauccNp2'   , 'num_jobs':1}
                           ## , 110816:{'label':'110816.AlpgenPythia_P2011C_ZtautauccNp3'   , 'num_jobs':1}
                           ##
                           ## , 110825:{'label':'110825.AlpgenPythia_P2011C_ZtautaubbNp0'   , 'num_jobs':1}
                           ## , 110826:{'label':'110826.AlpgenPythia_P2011C_ZtautaubbNp1'   , 'num_jobs':1}
                           ## , 110827:{'label':'110827.AlpgenPythia_P2011C_ZtautaubbNp2'   , 'num_jobs':1}
                           ## , 110828:{'label':'110828.AlpgenPythia_P2011C_ZtautaubbNp3'   , 'num_jobs':1}
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
    p.map(RunEwkAnalysis.runEwkAnalysisFun, data_set_dicts)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    RunHelpers.mergeOutputFiles(out_dir)
    RunHelpers.moveToLinkedDir(out_dir, './NextPlotDir.Ewk')
