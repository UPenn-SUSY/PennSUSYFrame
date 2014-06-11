#!/usr/bin/env python

import sys
import os
import glob
import shutil
import datetime

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
    total_num_events = 0
    total_entries = 0

    print 'reading file: %s' % file_path
    f = file(file_path)
    for l in f.readlines():
        l = l.strip('\n')
        splits = l.split()
        print splits
        file_list.append( splits[0])
        total_num_events += int(splits[1])
        total_entries    += int(splits[2])

    return { 'file_list':file_list
           , 'total_num_events':total_num_events
           , 'total_entries':total_entries
           }

# ------------------------------------------------------------------------------
def getFileListFromFile(file_path):
    file_list = []

    f = file(file_path)
    for l in f.readlines():
        l = l.strip('\n')
        splits = l.split()
        file_list.append( { 'file_name':splits[0]
                          , 'total_num_events':splits[1]
                          , 'total_entries':splits[2]
                          }
                        )

    return file_list

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
                       , is_full_sim
                       , dsid
                       , total_num_jobs = 1
                       , out_dir = './'
                       ):
    total_num_entries = 0

    print 'getting raw events for %s' % label_base
    data_set_input    = readFileList('%s/%s' % (os.environ['BASE_WORK_DIR'], file_list_path))
    file_list         = data_set_input['file_list']
    total_num_events  = data_set_input['total_num_events']
    total_num_entries = data_set_input['total_entries']

    print 'total num events: %s' % total_num_events
    print 'total entries: %s' % total_num_entries

    data_set_dict_list = []
    for tnj in xrange(total_num_jobs):
        this_data_set_dict = makeDataSetDict( label_base     = label_base
                                            , file_list_path = file_list_path
                                            , is_data        = is_data
                                            , is_full_sim    = is_full_sim
                                            , dsid           = dsid
                                            , job_num        = tnj
                                            , total_num_jobs = total_num_jobs
                                            , out_dir        = out_dir
                                            )
        this_data_set_dict['total_num_events']  = total_num_events
        this_data_set_dict['total_num_entries'] = total_num_entries
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
                    , is_full_sim
                    , dsid
                    , out_dir
                    ):
    these_data_set_dicts = makeDataSetDictList( label_base     = sample_dict['label']
                                              , file_list_path = file_list_path
                                              , is_data        = is_data
                                              , is_full_sim    = is_full_sim
                                              , dsid           = dsid
                                              , total_num_jobs = sample_dict['num_jobs']
                                              , out_dir        = out_dir
                                              )
    for tdsd in these_data_set_dicts:
        data_set_dicts.append(tdsd)

# ------------------------------------------------------------------------------
def mergeOutputFiles(out_dir, flat_files):
    abs_path = os.path.abspath(out_dir)
    AutoHadd.runAutoHaddOnDir(abs_path, flat_files)

    # make symbolic link for dummy hist file -- only if does not already exist
    dummy_file_name = '%s/BMinusL.dummy_hists.root' % abs_path
    if os.path.exists(dummy_file_name): return

    all_files_in_out_dir = glob.glob('%s/*.root' % abs_path)
    all_files_in_out_dir = glob.glob('%s/*.root' % abs_path)
    print all_files_in_out_dir[0]
    print dummy_file_name
    os.symlink(all_files_in_out_dir[0], dummy_file_name)

# ------------------------------------------------------------------------------
def moveToLinkedDir(out_dir, pointer_dir):
    abs_path_out     = os.path.abspath(out_dir)
    abs_path_pointer = os.path.abspath(pointer_dir)

    safeRemoveDir(abs_path_pointer)
    os.symlink(abs_path_out, abs_path_pointer)
