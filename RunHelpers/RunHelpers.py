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

        if syst_struct is not None:
            this_data_set_dict['label'] += ''.join( [ '__'
                                                    , syst_struct.getRunName()
                                                    ]
                                                  )

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
    print 'runLocalMultiprocess()'
    print 'num_processes: ', num_processes
    print 'run_analysis_fun: ', run_analysis_fun
    print 'data_set_dicts  : ', data_set_dicts
    print 'out_dir         : ', out_dir
    print 'sym_link_name   : ', sym_link_name
    # make output directory
    safeMakeDir(out_dir)

    print 'creating pool object'
    p = Pool(num_processes)
    print 'calling p.map'
    print 'data set dicts: ', data_set_dicts
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
        leader = '{' if i == 0 else ','
        value = this_data_set_dict[tdsd]
        if isinstance(value, str) and not tdsd == 'syst_struct':
            value = '"%s"' % value
        job_py_file.write("    %s '%s':%s\n" % (leader, tdsd, value)
                         )
    job_py_file.write("    }\n")
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
        batch_submit_command = [ ''.join( [ os.environ['PWD']
                                          , '/RunHelpers/SubmitPythonToBatch.sh'
                                          ]
                                        )
                               , queue
                               , '/'.join( [ os.environ['PWD']
                                           , this_job_file_name
                                           ]
                                         )
                               , os.environ['PWD']
                               ]

        print '-----------------------------------------'
        print 'batch submit command:'
        print batch_submit_command
        print ''

        # subprocess.call(batch_submit_command)

    # make sym link to output dir
    if not sym_link_name == '':
        moveToLinkedDir(out_dir, sym_link_name)

# ------------------------------------------------------------------------------
syst_list = { 'do_jer':'JER'
            , 'do_jes_up':'JES_UP'
            , 'do_jes_down':'JES_DOWN'
            , 'do_effective_np_1_up':'EFFECTIVE_NP_1_UP'
            , 'do_effective_np_1_down':'EFFECTIVE_NP_1_DOWN'
            , 'do_effective_np_2_up':'EFFECTIVE_NP_2_UP'
            , 'do_effective_np_2_down':'EFFECTIVE_NP_2_DOWN'
            , 'do_effective_np_3_up':'EFFECTIVE_NP_3_UP'
            , 'do_effective_np_3_down':'EFFECTIVE_NP_3_DOWN'
            , 'do_effective_np_4_up':'EFFECTIVE_NP_4_UP'
            , 'do_effective_np_4_down':'EFFECTIVE_NP_4_DOWN'
            , 'do_effective_np_5_up':'EFFECTIVE_NP_5_UP'
            , 'do_effective_np_5_down':'EFFECTIVE_NP_5_DOWN'
            , 'do_effective_np_6_up':'EFFECTIVE_NP_6_UP'
            , 'do_effective_np_6_down':'EFFECTIVE_NP_6_DOWN'
            , 'do_eta_intercalibration_modelling_up':'ETA_INTERCALIBRATION_MODELLING_UP'
            , 'do_eta_intercalibration_modelling_down':'ETA_INTERCALIBRATION_MODELLING_DOWN'
            , 'do_eta_intercalibration_statand_method_up':'ETA_INTERCALIBRATION_STATAND_METHOD_UP'
            , 'do_eta_intercalibration_statand_method_down':'ETA_INTERCALIBRATION_STATAND_METHOD_DOWN'
            , 'do_single_particle_high_pt_up':'SINGLE_PARTICLE_HIGH_PT_UP'
            , 'do_single_particle_high_pt_down':'SINGLE_PARTICLE_HIGH_PT_DOWN'
            , 'do_relative_non_closure_pythia8_up':'RELATIVE_NON_CLOSURE_PYTHIA8_UP'
            , 'do_relative_non_closure_pythia8_down':'RELATIVE_NON_CLOSURE_PYTHIA8_DOWN'
            , 'do_pile_up_offset_term_mu_up':'PILE_UP_OFFSET_TERM_MU_UP'
            , 'do_pile_up_offset_term_mu_down':'PILE_UP_OFFSET_TERM_MU_DOWN'
            , 'do_pile_up_offset_term_npv_up':'PILE_UP_OFFSET_TERM_NPV_UP'
            , 'do_pile_up_offset_term_npv_down':'PILE_UP_OFFSET_TERM_NPV_DOWN'
            , 'do_pile_up_pt_term_up':'PILE_UP_PT_TERM_UP'
            , 'do_pile_up_pt_term_down':'PILE_UP_PT_TERM_DOWN'
            , 'do_pile_up_rho_topology_up':'PILE_UP_RHO_TOPOLOGY_UP'
            , 'do_pile_up_rho_topology_down':'PILE_UP_RHO_TOPOLOGY_DOWN'
            , 'do_closeby_up':'CLOSEBY_UP'
            , 'do_closeby_down':'CLOSEBY_DOWN'
            , 'do_flavor_comp_uncert_up':'FLAVOR_COMP_UNCERT_UP'
            , 'do_flavor_comp_uncert_down':'FLAVOR_COMP_UNCERT_DOWN'
            , 'do_flavor_response_uncert_up':'FLAVOR_RESPONSE_UNCERT_UP'
            , 'do_flavor_response_uncert_down':'FLAVOR_RESPONSE_UNCERT_DOWN'
            , 'do_bjes_up':'BJES_UP'
            , 'do_bjes_down':'BJES_DOWN'
            }

# ------------------------------------------------------------------------------
class SystematicStruct(object):
    def __init__(self):
        self.syst_list = {syst:False for syst in syst_list.keys()}

    def setSyst(self, syst, val):
        if not syst in syst_list:
            print syst, ' is not a registered systematic!'
            return
        self.syst_list[syst] = val

    def configureAnalysisObject(self, analysis_obj):
        # extract systematic(C++) struct from analysis object
        analysis_syst_struct = analysis_obj.getSystematicStruct()

        # turn on each systematic flagged as true
        for syst in [k for k, v in self.syst_list.items() if v]:
            analysis_syst_struct.setSyst(syst, 1)

    def printInfo(self):
        for syst_name, syst_value in self.syst_list.items():
            print ': '.join([syst_list[syst_name], str(syst_value)])

    def getRunName(self):
        name = '.'.join([syst_list[syst_name] for syst_name, syst_value in
            self.syst_list.items() if syst_value])
        if name == '':
            name = 'NOMINAL'
        return name

# ------------------------------------------------------------------------------
def pickleSystStruct(this_struct, out_file_name):
    pickle.dump(this_struct, file(out_file_name, 'wb'))

