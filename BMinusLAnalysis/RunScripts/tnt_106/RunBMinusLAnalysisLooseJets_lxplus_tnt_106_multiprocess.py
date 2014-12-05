#!/usr/bin/env python

import os
from multiprocessing import Pool
import time
import sys
import datetime
import itertools

sys.path.append('%s/BMinusLAnalysis/RunScripts/' % os.environ['BASE_WORK_DIR'])
import RunBMinusLAnalysisLooseJets

sys.path.append('%s/RunHelpers/' % os.environ['BASE_WORK_DIR'])
import RunHelpers

# ------------------------------------------------------------------------------
# get number of parallel processes from command line inputs
user_input = sys.argv[1] if len(sys.argv) > 1 else "1"
num_processes = 1
queue = '1nh'
if "nm" in user_input or "nh" in user_input or "nd" in user_input:
    queue = user_input
    run_local = False
else:
    num_processes = int(user_input)
    run_local = True

today_date = datetime.datetime.now()
out_dir = '%s/hists/bminusl_loose_jets_hists_%04d_%02d_%02d__%02d_%02d' % ( os.environ['PWD']
                                                                          , today_date.year
                                                                          , today_date.month
                                                                          , today_date.day
                                                                          , today_date.hour
                                                                          , today_date.minute
                                                                          )
print out_dir

# ==============================================================================
if __name__ == '__main__':
    print 'getting file list'

    egamma_data_samples = SampleDicts.getEgammaDataSamples(job_multiplier = 5)
    muon_data_samples = SampleDicts.getMuonDataSamples(job_multiplier = 5)
    full_sim_mc_samples = SampleDicts.getFullSimSamples(job_multiplier = 5)
    fast_sim_mc_samples = SampleDicts.getFastSimSamples(job_multiplier = 5)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # Define what systematics to include in this run and construct dictionary
    data_set_dicts = {}

    systematic_runs = [None]
    for syst in systematic_runs:
        syst_struct = RunHelpers.SystematicStruct()
        if syst is not None:
            syst_struct.setSyst(syst, True)
        syst_tag = syst_struct.getRunName()

        syst_struct.printInfo()
        print syst_tag


        data_set_dicts[syst_tag] = RunHelpers.addAllSamplesToList(
                egamma_data_samples = egamma_data_samples,
                muon_data_samples   = muon_data_samples,
                full_sim_mc_samples = full_sim_mc_samples,
                fast_sim_mc_samples = fast_sim_mc_samples,
                file_list_path_base = 'EosFileLists/tnt_106/tnt_106',
                out_dir             = '__'.join([out_dir, syst_tag]),
                syst_struct         = syst_struct)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    for syst, the_dicts in data_set_dicts.items():
        print syst, ' -- ', the_dicts

        this_out_dir = '__'.join([out_dir, syst])
        this_sym_link_name = ''.join(['./NextPlotDir.BMinusL.', syst])
        print 'this sym link name: ', this_sym_link_name

        this_run_analysis_fun = RunBMinusLAnalysisLooseJets.runBMinusLAnalysisLooseJetsFun

        if run_local:
            RunHelpers.runLocalMultiprocess( run_analysis_fun = this_run_analysis_fun
                                           , data_set_dicts   = the_dicts
                                           , num_processes    = num_processes
                                           , out_dir          = this_out_dir
                                           , flat_ntuples     = False
                                           , sym_link_name    = this_sym_link_name
                                           )

        else:
            run_analysis_fun_loc  = '/'.join( [ os.environ['BASE_WORK_DIR']
                                              , 'BMinusLAnalysis'
                                              , 'RunScripts/'
                                              ]
                                            )
            this_job_dir = '.'.join( [ 'LatestRunDir_bminuslanalysis'
                                     , syst
                                     ]
                                   )

            RunHelpers.runLxBatchMultiProcess( run_analysis_fun      = this_run_analysis_fun
                                             , run_analysis_fun_loc  = run_analysis_fun_loc
                                             , run_analysis_fun_file = 'RunBMinusLAnalysisLooseJets'
                                             , data_set_dicts        = the_dicts
                                             , out_dir               = this_out_dir
                                             , queue                 = queue
                                             , sym_link_name         = this_sym_link_name
                                             , job_dir               = this_job_dir
                                             )
