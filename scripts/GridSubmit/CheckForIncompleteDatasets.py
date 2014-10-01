#!/usr/bin/env python
#===============================================================================
#= This scrip will look through the eos file lists, and verify that the "total
#= number of events" run over to produce the skim are accounted for.
#= usage:
#=   TODO add usage information
#===============================================================================

import os

#-------------------------------------------------------------------------------
ami_data_file_name = "%s/data/ami_data12.txt" % os.environ['BASE_WORK_DIR']
ami_data_file_name = "%s/data/ami_mc12.txt"   % os.environ['BASE_WORK_DIR']

#-------------------------------------------------------------------------------
def processDataLine(line):
    cleaned_line = line.rstrip('\n')
    splits = cleaned_line.split()

    dataset = splits[0]
    period  = splits[1]
    total_events = splits[2]
    num_files    = splits[3]
    total_size   = splits[4]

    dataset_splits = dataset.split('.')
    run_num = dataset_splits[1]
    stream  = dataset_splits[2]
    tag     = dataset_splits[-1]

    return { 'dataset':dataset
           , 'period':period
           , 'total_events':total_events
           , 'num_files':num_files
           , 'total_size':total_size
           , 'run_num':run_num
           , 'stream':stream
           , 'tag':tag
           }

#-------------------------------------------------------------------------------
def processMCLine(line):
    cleaned_line = line.rstrip('\n')
    splits = cleaned_line.split()

    dataset = splits[0]
    total_events = splits[2]
    num_files    = splits[3]
    total_size   = splits[4]

    dataset_splits = dataset.split('.')
    dsid    = dataset_splits[1]
    ds_name = dataset_splits[2]
    tag     = dataset_splits[-1]

    return { 'dataset':dataset
           , 'period':period
           , 'total_events':total_events
           , 'num_files':num_files
           , 'total_size':total_size
           , 'dsid':dsid
           , 'ds_name':ds_name
           , 'tag':tag
           }

#-------------------------------------------------------------------------------
def main():
    pass

#===============================================================================
if __name__ == "__main__":
    main()
