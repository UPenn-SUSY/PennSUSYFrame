#!/usr/bin/env python

import sys
import os
import glob
import shutil
import datetime
from multiprocessing import Pool
import subprocess
import pickle

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

# ------------------------------------------------------------------------------
def getFileListFromGridInput(grid_input_string):
    file_list = grid_input_string.split(',')
    return file_list

# ------------------------------------------------------------------------------
def getTChain(file_list, tree_name):
    t = ROOT.TChain(tree_name)
    for fl in file_list:
        # print 'Adding file: %s' % fl
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
                       , syst_struct = None
                       ):
    total_num_entries = 0

    print 'getting raw events for %s' % label_base
    data_set_input       = readFileList('%s/%s' % (os.environ['BASE_WORK_DIR'], file_list_path))
    file_list            = data_set_input['file_list']
    total_num_events     = data_set_input['total_num_events']
    total_num_entries    = data_set_input['total_entries']
    sum_mc_event_weights = data_set_input['sum_mc_event_weights']

    print '  total num events: %s' % total_num_events
    print '  total entries: %s' % total_num_entries
    print '  sum mc event weights: %s' % sum_mc_event_weights

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
        this_data_set_dict['syst_struct']          = syst_struct
        data_set_dict_list.append(this_data_set_dict)

        if syst_struct.do_jer:
            this_data_set_dict['label'] += '__JER'
        if syst_struct.do_jes_up:
            this_data_set_dict['label'] += '__JES_UP'
        if syst_struct.do_jes_down:
            this_data_set_dict['label'] += '__JES_DOWN'

    print ''
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
        if rm_dir.lower() == 'y':
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
                    , syst_struct = None
                    ):
    these_data_set_dicts = makeDataSetDictList( label_base       = sample_dict['label']
                                              , file_list_path   = file_list_path
                                              , is_data          = is_data
                                              , is_egamma_stream = is_egamma_stream
                                              , is_full_sim      = is_full_sim
                                              , dsid             = dsid
                                              , total_num_jobs   = sample_dict['num_jobs']
                                              , out_dir          = out_dir
                                              , syst_struct      = syst_struct
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
                       , syst_struct = None
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
                        , syst_struct      = syst_struct
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
                        , syst_struct      = syst_struct
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
                        , syst_struct      = syst_struct
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
                        , syst_struct      = syst_struct
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
    os.symlink(all_files_in_out_dir[0], dummy_file_name)

# ------------------------------------------------------------------------------
def moveToLinkedDir(out_dir, pointer_dir):
    abs_path_out     = os.path.abspath(out_dir)
    abs_path_pointer = os.path.abspath(pointer_dir)

    safeRemoveDir(abs_path_pointer)
    if not os.path.exists(abs_path_pointer):
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
    # make output directory
    safeMakeDir(out_dir)

    p = Pool(num_processes)
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
    # copy data_set_dict so we can modify it
    this_data_set_dict = data_set_dict

    job_py_name = '%s/lx_batch_job.%s.%d_of_%d.py' % ( job_dir
                                                     , this_data_set_dict['label']
                                                     , this_data_set_dict['job_num']
                                                     , this_data_set_dict['total_num_jobs']
                                                     )
    job_py_file = file(job_py_name, 'w')
    job_py_file.write('#!/usr/bin/env python\n')
    job_py_file.write('\n')
    job_py_file.write('import subprocess\n')
    job_py_file.write('import os\n')
    job_py_file.write('import sys\n')
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

    # more ugly stuff to handle the systematics structure
    if this_data_set_dict['syst_struct'] is not None:
        # pickle systematic struct object for later reading
        syst_struct_pickle = '%s/syst_pickle.%s.%d_of_%d.p' % ( job_dir
                                                              , this_data_set_dict['label']
                                                              , this_data_set_dict['job_num']
                                                              , this_data_set_dict['total_num_jobs']
                                                              )
        pickleSystStruct(this_data_set_dict['syst_struct'], syst_struct_pickle)

        # modify the syst_struct element in the dictionary
        this_data_set_dict['syst_struct'] = 'this_syst_struct'
        job_py_file.write('\n')

        # read the pickled syst struct
        job_py_file.write('import pickle\n')
        job_py_file.write('sys.path.append("%s/RunHelpers/" % os.environ["BASE_WORK_DIR"])\n')
        job_py_file.write('import RunHelpers\n')
        job_py_file.write('this_syst_struct = pickle.load(file("%s", "rb"))\n' % syst_struct_pickle)
        job_py_file.write('print "this_syst_struct"\n')
        job_py_file.write('print this_syst_struct\n')
        job_py_file.write('this_syst_struct.printInfo()\n')
    # /more ugly stuff

    # import the py file with function
    job_py_file.write('\n')
    job_py_file.write('sys.path.append("%s")\n' % run_analysis_fun_loc)
    job_py_file.write('import %s\n' % run_analysis_fun_file)
    job_py_file.write('\n')
    job_py_file.write( 'print "running %s on the dataset %s (%d of %d)"' % ( run_analysis_fun.__name__
                                                                           , this_data_set_dict['label']
                                                                           , this_data_set_dict['job_num']
                                                                           , this_data_set_dict['total_num_jobs']
                                                                           )
                     )
    job_py_file.write('\n')

    # call the run analysis function
    job_py_file.write('%s.%s(\n' % ( run_analysis_fun_file
                                   , run_analysis_fun.__name__
                                   )
                     )
    for i, tdsd in enumerate(this_data_set_dict):
        leader = ' ' if i == 0 else ','
        value = this_data_set_dict[tdsd]
        if isinstance(value, str) and not tdsd == 'syst_struct':
            value = '"%s"' % value
        job_py_file.write("    %s '%s':%s\n" % (leader, tdsd, value)
                         )
    job_py_file.write(')\n\n')

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
    safeRemoveDir(job_dir)
    safeMakeDir(job_dir)

    # make output directory
    safeMakeDir(out_dir)

    # write script for each lxbatch job
    for dsd in data_set_dicts:
        this_job_file_name = writeLxBatchScript( run_analysis_fun
                                               , run_analysis_fun_loc
                                               , run_analysis_fun_file
                                               , dsd
                                               , job_dir
                                               )

        # submit this job to lxbatch!
        batch_submit_command = [ '%s/RunHelpers/SubmitPythonToBatch.sh' % os.environ['PWD']
                               , queue
                               , '%s/%s' % (os.environ['PWD'], this_job_file_name)
                               , os.environ['PWD']
                               ]

        print '-----------------------------------------'
        print 'batch submit command:'
        print batch_submit_command
        print ''

        subprocess.call(batch_submit_command)

    # make sym link to output dir
    if not sym_link_name == '':
        moveToLinkedDir(out_dir, sym_link_name)

# ------------------------------------------------------------------------------
class SystematicStruct(object):
    def __init__( self
                , do_jer
                , do_jes_up
                , do_jes_down
                ):
        self.do_jer      = do_jer
        self.do_jes_up   = do_jes_up
        self.do_jes_down = do_jes_down

    def configureAnalysisObject(self, analysis_obj):
        analysis_obj.setDoJer(    self.do_jer)
        analysis_obj.setDoJesUp(  self.do_jes_up)
        analysis_obj.setDoJesDown(self.do_jes_down)

    def printInfo(self):
        print 'Do JER: ', self.do_jer
        print 'Do JES_UP: ', self.do_jes_up
        print 'Do JES_DOWN: ', self.do_jes_down

# ------------------------------------------------------------------------------
def pickleSystStruct(this_struct, out_file_name):
    pickle.dump(this_struct, file(out_file_name, 'wb'))

