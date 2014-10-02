#!/usr/bin/env python
#===============================================================================
#= This script will look through the eos file lists, and verify that the "total
#= number of events" run over to produce the skim are accounted for.
#= usage:
#=   TODO add usage information
#===============================================================================

import os
import pprint
import glob

#-------------------------------------------------------------------------------
tnt_dir = '%s/EosFileLists/tnt_106' % os.environ['BASE_WORK_DIR']

ami_data_file_name = "%s/data/ami_data12.txt" % os.environ['BASE_WORK_DIR']
ami_mc_file_name   = "%s/data/ami_mc12.txt"   % os.environ['BASE_WORK_DIR']

#-------------------------------------------------------------------------------
# read a line from the ami data file
def processDataLine(line):
    # clean and split lines
    cleaned_line = line.rstrip('\n')
    splits = cleaned_line.split()

    # get the dataset name
    dataset = splits[0]

    # if valid line, deconstruct the pieces
    if not dataset == 'DATASET':
        period       = splits[1]
        total_events = splits[2]
        num_files    = splits[3]
        total_size   = splits[4]

        dataset_splits = dataset.split('.')
        run_num  = dataset_splits[1]
        stream   = dataset_splits[2]
        prod_tag = dataset_splits[-1].split('_')[-1]
    # skip header line
    else:
        period       = ""
        total_events = 0
        num_files    = 0
        total_size   = 0

        run_num  = ""
        stream   = ""
        prod_tag = ""

    # return a dictionary with the result
    return { 'dataset':dataset
           , 'period':period
           , 'total_events':int(total_events)
           , 'num_files':int(num_files)
           , 'total_size':float(total_size)
           , 'run_num':run_num
           , 'stream':stream
           , 'prod_tag':prod_tag
           }

#-------------------------------------------------------------------------------
# read a line from the ami mc file
def processMCLine(line):
    # clean and split lines
    cleaned_line = line.rstrip('\n')
    splits = cleaned_line.split()

    # get the dataset name
    dataset = splits[0]

    # if valid line, deconstruct the pieces
    if not dataset == "DATASET":
        total_events = splits[2]
        num_files    = splits[3]
        total_size   = splits[4]

        dataset_splits = dataset.split('.')
        dsid     = dataset_splits[1]
        ds_name  = dataset_splits[2]
        prod_tag = dataset_splits[-1]
    # skip header line
    else:
        total_events = 0
        num_files    = 0
        total_size   = 0

        dsid     = ""
        ds_name  = ""
        prod_tag = ""

    # return a dictionary with the result
    return { 'dataset':dataset
           , 'period':'MC'
           , 'total_events':int(total_events)
           , 'num_files':int(num_files)
           , 'total_size':float(total_size)
           , 'dsid':dsid
           , 'ds_name':ds_name
           , 'prod_tag':prod_tag
           }

#-------------------------------------------------------------------------------
# read the full ami file (data or mc) and extract all the dataset sizes
def getDatasetSizes(is_data):
    f = file(ami_data_file_name if is_data else ami_mc_file_name)

    data_size_dict = {}
    for l in f.readlines():
        # read this line
        processed_line = processDataLine(l) if is_data else processMCLine(l)
        # skip the header line
        if processed_line['dataset'] == 'DATASET': continue

        # construct line tag
        line_tag = 'data__' if is_data else 'mc__'
        if is_data:
            line_tag += processed_line['period'].strip('1234567890')
            line_tag += '__'
            line_tag += processed_line['stream'].lower()
        else:
            line_tag += processed_line['dsid']
            line_tag += '__'
            line_tag += processed_line['ds_name']
        line_tag += '__'
        line_tag += processed_line['prod_tag']

        # if this is the first time we see this line tag, add a new entry to the
        # dictionary
        if line_tag not in data_size_dict:
            data_size_dict[line_tag] = { 'total_events':0
                                       , 'num_files':0
                                       , 'total_size':0
                                       }

        # add to the number of events, number of files and total size
        data_size_dict[line_tag]['total_events'] += processed_line['total_events']
        data_size_dict[line_tag]['num_files']    += processed_line['num_files']
        data_size_dict[line_tag]['total_size']   += processed_line['total_size']

    return data_size_dict

#-------------------------------------------------------------------------------
# read an eos file list and get the event data
def getEventDataFromEosFileList(file_name):
    f = file(file_name)
    total_events = 0
    num_entries = 0
    sum_mc_event_weight = 0.

    for l in f.readlines():
        splits = l.rstrip('\n').split()
        total_events        += int(splits[1])
        num_entries         += int(splits[2])
        sum_mc_event_weight += float(splits[3])
    
    f.close()

    return { 'total_events':total_events
           , 'entries':num_entries
           , 'sum_mc_event_weight':sum_mc_event_weight
           }

#-------------------------------------------------------------------------------
# 
def constructMismatchMessage(ds_name, total_events_eos, total_events_container):
    diff = total_events_container - total_events_eos
    percent_diff = 100*diff/float(total_events_container) if total_events_container else 0
    # message = 'sample: %s -- container: %d : eos: %d -- diff: %d (%0.2f)\%' % ( ds_name
    #                                                                           , total_events_container
    #                                                                           , total_events_eos
    #                                                                           , diff
    #                                                                           , percent_diff
    #                                                                           )
    message = 'sample: %s'          % ds_name
    message += ' -- container: %d'  % total_events_container
    message += ' : eos: %d'         % total_events_eos
    message += ' -- diff: %d'       % diff
    message += ' (%0.2f %%)'        % percent_diff

    return message

#-------------------------------------------------------------------------------
# for all the eos files in a directory, compare the total number of events to
# the number expected from ami
def checkEosFilesInDirectory(dir_path):
    # read ami files
    data_sizes = getDatasetSizes(is_data = True )
    mc_sizes   = getDatasetSizes(is_data = False)

    # list to store message for missing samples
    mismatch_message_list = []

    # get list of eos files and loop over them
    file_list = glob.glob('%s/*' % dir_path)
    for fl in file_list:
        # extract the sample name from the file name
        sample_name = fl.replace('%s/' %dir_path, '')
        sample_name = sample_name.replace('.txt', '')
        sample_splits = sample_name.split('.')

        # get the dsid and dataset name from the sample name
        dsid    = sample_splits[1]
        ds_name = sample_splits[2] if 'period' not in dsid else dsid

        # if this is data, we compare to the data list
        if 'period' in ds_name:
            period_letter = ds_name.split('_')[0].replace('period', '')
            stream = ds_name.split('_')[1]
            if stream == 'muon':
                stream = 'muons'

            num_events_eos  = getEventDataFromEosFileList(fl)['total_events']
            num_events_cont = data_sizes['data__%s__physics_%s__p1542' % (period_letter, stream)]['total_events']

            if num_events_eos != num_events_cont:
                mismatch_message_list.append( constructMismatchMessage( ds_name
                                                                      , num_events_eos
                                                                      , num_events_cont
                                                                      )
                                            )

        # if this is mc, we compare to the mc list
        else:
            # get number events from eos file -- this is only done once
            num_events_eos = getEventDataFromEosFileList(fl)['total_events']

            # look for key match between eos list and ami list
            found_match = False
            min_diff = 9.e20
            best_match = ''
            num_events_best_match = 0
            for mc_sizes_key in mc_sizes.keys():
                if dsid in mc_sizes_key:
                    found_match = True

                    # check the number of events in the container from the ami file
                    num_events_cont = mc_sizes[mc_sizes_key]['total_events']

                    this_diff = abs(num_events_cont - num_events_eos)
                    if this_diff < min_diff:
                        min_diff = this_diff
                        best_match = '%s.%s' % (dsid, ds_name)
                        num_events_best_match = num_events_cont

            if num_events_eos != num_events_best_match:
                mismatch_message_list.append( constructMismatchMessage( best_match
                                                                      , num_events_eos
                                                                      , num_events_cont
                                                                      )
                                            )

            # did not find a match -- something is wrong!!!
            if not found_match:
                print 'matching key not found'

    # Print any mismatches
    print ''
    print 'Number of mismatches: ', len(mismatch_message_list)
    for mml in sorted(mismatch_message_list):
        print mml

#-------------------------------------------------------------------------------
def main():
    checkEosFilesInDirectory(tnt_dir)

#===============================================================================
if __name__ == "__main__":
    main()
