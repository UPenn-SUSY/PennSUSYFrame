#!/usr/bin/env python

import sys
import os
import glob
import shutil
import datetime
from multiprocessing import Pool
import subprocess

import ROOT

sys.path.append('%s/scripts/' % os.environ['BASE_WORK_DIR'])
import AutoHadd

# ------------------------------------------------------------------------------
def getDateTimeLabel(include_date = True, include_time = True):
    today_date = datetime.datetime.now()
    datetime_label = ''
    if include_date:
        datetime_label += '__%04d_%02d_%02d'% ( today_date.year
                                              , today_date.month
                                              , today_date.day
                                              )
    if include_time:
        datetime_label += '__%02d_%02d' % ( today_date.hour
                                          , today_date.minute
                                          )

    return datetime_label

# ------------------------------------------------------------------------------
def getFileListFromDir(file_path):
    print 'getting files from dir: %s' % file_path
    file_list = glob.glob('%s/*' % file_path)
    return file_list

# ------------------------------------------------------------------------------
def readFileList(file_path):
    file_list = []
    total_num_events     = 0
    total_entries        = 0
    sum_mc_event_weights = 0.

    print 'reading file: %s' % file_path
    f = file(file_path)
    for l in f.readlines():
        l = l.strip('\n')
        splits = l.split()
        # print splits
        file_list.append( splits[0])
        total_num_events += int(splits[1])
        total_entries    += int(splits[2])

        # increment the sum of mc event weights -- if this entry is not filled
        # in the EosFileList, increment with the total number of events
        sum_mc_event_weights += float(splits[3]) if len(splits) > 3 else int(splits[1])

    return { 'file_list':file_list
           , 'total_num_events':total_num_events
           , 'total_entries':total_entries
           , 'sum_mc_event_weights':sum_mc_event_weights
           }

## # ------------------------------------------------------------------------------
## def getFileListFromFile(file_path):
##     file_list = []
##
##     f = file(file_path)
##     for l in f.readlines():
##         l = l.strip('\n')
##         splits = l.split()
##         file_list.append( { 'file_name':splits[0]
##                           , 'total_num_events':splits[1]
##                           , 'total_entries':splits[2]
##                           }
##                         )
##
##     return file_list

# ------------------------------------------------------------------------------
def getFileListFromGridInput(grid_input_string):
    file_list = grid_input_string.split(',')
    return file_list

# ------------------------------------------------------------------------------
def getTChain(file_list, tree_name):
    t = ROOT.TChain(tree_name)
    for fl in file_list:
        print 'Adding file: %s' % fl
        t.AddFile(fl)
    return t


# ------------------------------------------------------------------------------
def makeDataSetDict( label_base
                   , file_list_path
                   , is_data
                   , is_egamma_stream
                   , is_full_sim
                   , dsid
                   , job_num=0
                   , total_num_jobs = 1
                   , out_dir = './'
                   ):
    label = '%s' % (label_base)

    data_set_input = readFileList('%s/%s' % ( os.environ['BASE_WORK_DIR']
                                            , file_list_path
                                            )
                                 )
    file_list = data_set_input['file_list']

    return { 'label':label
           , 'file_list':file_list
           , 'is_data':is_data
           , 'is_egamma_stream':is_egamma_stream
           , 'is_full_sim':is_full_sim
           , 'dsid':dsid
           , 'job_num':job_num
           , 'total_num_jobs':total_num_jobs
           , 'out_dir':out_dir
           }

# ------------------------------------------------------------------------------
def makeDataSetDictList( label_base
                       , file_list_path
                       , is_data
                       , is_egamma_stream
                       , is_full_sim
                       , dsid
                       , total_num_jobs = 1
                       , out_dir = './'
                       ):
    total_num_entries = 0

    print 'getting raw events for %s' % label_base
    data_set_input       = readFileList('%s/%s' % (os.environ['BASE_WORK_DIR'], file_list_path))
    file_list            = data_set_input['file_list']
    total_num_events     = data_set_input['total_num_events']
    total_num_entries    = data_set_input['total_entries']
    sum_mc_event_weights = data_set_input['sum_mc_event_weights']

    print 'total num events: %s' % total_num_events
    print 'total entries: %s' % total_num_entries
    print 'sum mc event weights: %s' % sum_mc_event_weights

    data_set_dict_list = []
    for tnj in xrange(total_num_jobs):
        this_data_set_dict = makeDataSetDict( label_base       = label_base
                                            , file_list_path   = file_list_path
                                            , is_data          = is_data
                                            , is_egamma_stream = is_egamma_stream
                                            , is_full_sim      = is_full_sim
                                            , dsid             = dsid
                                            , job_num          = tnj
                                            , total_num_jobs   = total_num_jobs
                                            , out_dir          = out_dir
                                            )
        this_data_set_dict['total_num_events']     = total_num_events
        this_data_set_dict['total_num_entries']    = total_num_entries
        this_data_set_dict['sum_mc_event_weights'] = sum_mc_event_weights
        data_set_dict_list.append(this_data_set_dict)

    return data_set_dict_list

# ------------------------------------------------------------------------------
def safeMakeDir(dir_name):
    # If output directory does not exist, create it
    if not os.path.exists(dir_name):
        os.makedirs(dir_name)

# ------------------------------------------------------------------------------
def safeRemoveDir(dir_name):
    # If output directory does not exist, create it
    if os.path.exists(dir_name):
        rm_dir = None
        while not rm_dir in ['y', 'Y', 'n', 'N']:
            rm_dir = raw_input('actually remove %s? [y,n]: ' % dir_name)
        if rm_dir:
            if os.path.islink(dir_name):
                os.remove(dir_name)
            else:
                shutil.rmtree(dir_name)

# ------------------------------------------------------------------------------
def addSamplesToList( sample_dict
                    , data_set_dicts
                    , file_list_path
                    , is_data
                    , is_egamma_stream
                    , is_full_sim
                    , dsid
                    , out_dir
                    ):
    these_data_set_dicts = makeDataSetDictList( label_base       = sample_dict['label']
                                              , file_list_path   = file_list_path
                                              , is_data          = is_data
                                              , is_egamma_stream = is_egamma_stream
                                              , is_full_sim      = is_full_sim
                                              , dsid             = dsid
                                              , total_num_jobs   = sample_dict['num_jobs']
                                              , out_dir          = out_dir
                                              )
    for tdsd in these_data_set_dicts:
        data_set_dicts.append(tdsd)

# ------------------------------------------------------------------------------
def addAllSamplesToList( egamma_data_samples
                       , muon_data_samples
                       , full_sim_mc_samples
                       , fast_sim_mc_samples
                       , file_list_path_base
                       , out_dir
                       ):
    data_set_dicts = []

    # add egamma stream data samples
    for dsid in egamma_data_samples:
        addSamplesToList( sample_dict      = egamma_data_samples[dsid]
                        , data_set_dicts   = data_set_dicts
                        , file_list_path   = '%s.%s.txt' % ( file_list_path_base
                                                           , egamma_data_samples[dsid]['label']
                                                           )
                        , is_data          = True
                        , is_egamma_stream = True
                        , is_full_sim      = False
                        , dsid             = dsid
                        , out_dir          = out_dir
                        )

    # add muon stream data samples
    for dsid in muon_data_samples:
        addSamplesToList( sample_dict      = muon_data_samples[dsid]
                        , data_set_dicts   = data_set_dicts
                        , file_list_path   = '%s.%s.txt' % ( file_list_path_base
                                                           , muon_data_samples[dsid]['label']
                                                           )
                        , is_data          = True
                        , is_egamma_stream = False
                        , is_full_sim      = False
                        , dsid             = dsid
                        , out_dir          = out_dir
                        )

    # add full sim samples
    for dsid in full_sim_mc_samples:
        addSamplesToList( sample_dict      = full_sim_mc_samples[dsid]
                        , data_set_dicts   = data_set_dicts
                        , file_list_path   = '%s.%s.txt' % ( file_list_path_base
                                                           , full_sim_mc_samples[dsid]['label']
                                                           )
                        , is_data          = False
                        , is_egamma_stream = False
                        , is_full_sim      = True
                        , dsid             = dsid
                        , out_dir          = out_dir
                        )

    # add fast sim samples
    for dsid in fast_sim_mc_samples:
        addSamplesToList( sample_dict      = fast_sim_mc_samples[dsid]
                        , data_set_dicts   = data_set_dicts
                        , file_list_path   = '%s.%s.txt' % ( file_list_path_base
                                                           , fast_sim_mc_samples[dsid]['label']
                                                           )
                        , is_data          = False
                        , is_egamma_stream = False
                        , is_full_sim      = False
                        , dsid             = dsid
                        , out_dir          = out_dir
                        )

    # return the list of data set dictionaries
    return data_set_dicts

# ------------------------------------------------------------------------------
def mergeOutputFiles(out_dir, flat_files):
    abs_path = os.path.abspath(out_dir)
    AutoHadd.runAutoHaddOnDir(abs_path, flat_files)

    # make symbolic link for dummy hist file -- only if does not already exist
    dummy_file_name = '%s/BMinusL.dummy_hists.root' % abs_path
    if os.path.exists(dummy_file_name): return

    all_files_in_out_dir = glob.glob('%s/*.root' % abs_path)
    all_files_in_out_dir = glob.glob('%s/*.root' % abs_path)
    # print all_files_in_out_dir[0]
    # print dummy_file_name
    os.symlink(all_files_in_out_dir[0], dummy_file_name)

# ------------------------------------------------------------------------------
def moveToLinkedDir(out_dir, pointer_dir):
    abs_path_out     = os.path.abspath(out_dir)
    abs_path_pointer = os.path.abspath(pointer_dir)

    safeRemoveDir(abs_path_pointer)
    os.symlink(abs_path_out, abs_path_pointer)

# ------------------------------------------------------------------------------
def runLocalMultiprocess( run_analysis_fun
                        , data_set_dicts
                        , num_processes
                        , out_dir
                        , flat_ntuples
                        , sym_link_name
                        , do_merge = True
                        ):
    p = Pool(num_processes)
    # print run_analysis_fun
    # print data_set_dicts
    p.map(run_analysis_fun, data_set_dicts)

    mergeOutputFiles(out_dir, flat_ntuples)
    moveToLinkedDir(out_dir , sym_link_name)

# ------------------------------------------------------------------------------
def writeLxBatchScript( run_analysis_fun
                      , run_analysis_fun_loc
                      , run_analysis_fun_file
                      , data_set_dict
                      , job_dir
                      ):
    # print 'writeLxBatchScript()'
    # print run_analysis_fun
    # print run_analysis_fun.__name__

    job_py_name = '%s/lx_batch_job.%s.%d_of_%d.py' % ( job_dir
                                                     , data_set_dict['label']
                                                     , data_set_dict['job_num']
                                                     , data_set_dict['total_num_jobs']
                                                     )
    job_py_file = file(job_py_name, 'w')
    job_py_file.write('#!/usr/bin/env python\n')
    job_py_file.write('\n')
    job_py_file.write('import subprocess\n')
    job_py_file.write('import os\n')
    job_py_file.write('\n')

    # ugly stuff to set the environment correctly
    job_py_file.write('os.chdir("%s")\n' % os.environ['BASE_WORK_DIR'] )
    job_py_file.write('setup_command = ["bash", "-c", "source SetupEnvironment.sh && env"]\n')
    job_py_file.write('proc = subprocess.Popen(setup_command, stdout = subprocess.PIPE)\n')
    job_py_file.write('for line in proc.stdout:\n')
    job_py_file.write('    (key, _, value) = line.rstrip("\\n").partition("=")\n')
    job_py_file.write('    os.environ[key] = value\n')
    job_py_file.write('proc.communicate()\n')
    # /ugly stuff

    # import the py file with function
    job_py_file.write('\n')
    job_py_file.write('import sys\n')
    job_py_file.write('sys.path.append("%s")\n' % run_analysis_fun_loc)
    job_py_file.write('import %s\n' % run_analysis_fun_file)
    job_py_file.write('\n')
    job_py_file.write( 'print "running %s on the dataset %s (%d of %d)"' % ( run_analysis_fun.__name__
                                                                           , data_set_dict['label']
                                                                           , data_set_dict['job_num']
                                                                           , data_set_dict['total_num_jobs']
                                                                           )
                     )
    job_py_file.write('\n')

    # call the run analysis function
    job_py_file.write('%s.%s(%s)\n' % ( run_analysis_fun_file
                                      , run_analysis_fun.__name__
                                      , data_set_dict
                                      )
                  )
    job_py_file.write('\n')

    # close file
    job_py_file.close()

    # make script executable
    subprocess.call(['chmod', '+x', job_py_name])

    return job_py_name

# ------------------------------------------------------------------------------
def runLxBatchMultiProcess( run_analysis_fun
                          , run_analysis_fun_loc
                          , run_analysis_fun_file
                          , data_set_dicts
                          , out_dir
                          , queue         = '1nh'
                          , sym_link_name = ''
                          , job_dir       = 'LatestRunDir'
                          ):
    print 'runLxBatchMultiProcess()'
    print '  out dir: ' , out_dir

    # create directory for new run scripts
    # job_dir = 'LatestRunDir'
    safeRemoveDir(job_dir)
    safeMakeDir(job_dir)

    # write script for each lxbatch job
    for dsd in data_set_dicts:
        print 'dsd: ' , dsd
        this_job_file_name = writeLxBatchScript( run_analysis_fun
                                               , run_analysis_fun_loc
                                               , run_analysis_fun_file
                                               , dsd
                                               , job_dir
                                               )
        print ''

        # submit this job to lxbatch!
        batch_submit_command = [ '%s/RunHelpers/SubmitPythonToBatch.sh' % os.environ['PWD']
                               , queue
                               , '%s/%s' % (os.environ['PWD'], this_job_file_name)
                               , os.environ['PWD']
                               ]
        print batch_submit_command
        subprocess.call(batch_submit_command)

    # make sym link to output dir
    if not sym_link_name == '':
        moveToLinkedDir(out_dir, sym_link_name)
