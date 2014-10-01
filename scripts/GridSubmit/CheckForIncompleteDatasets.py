#!/usr/bin/env python
#===============================================================================
#= This scrip will look through the eos file lists, and verify that the "total
#= number of events" run over to produce the skim are accounted for.
#= usage:
#=   TODO add usage information
#===============================================================================

import os
import pprint

#-------------------------------------------------------------------------------
ami_data_file_name = "%s/data/ami_data12.txt" % os.environ['BASE_WORK_DIR']
ami_mc_file_name   = "%s/data/ami_mc12.txt"   % os.environ['BASE_WORK_DIR']

#-------------------------------------------------------------------------------
def processDataLine(line):
    cleaned_line = line.rstrip('\n')
    splits = cleaned_line.split()

    dataset = splits[0]

    if not dataset == 'DATASET':
        period       = splits[1]
        total_events = splits[2]
        num_files    = splits[3]
        total_size   = splits[4]

        dataset_splits = dataset.split('.')
        run_num  = dataset_splits[1]
        stream   = dataset_splits[2]
        prod_tag = dataset_splits[-1].split('_')[-1]
    else:
        period       = ""
        total_events = 0
        num_files    = 0
        total_size   = 0

        run_num  = ""
        stream   = ""
        prod_tag = ""

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
def processMCLine(line):
    cleaned_line = line.rstrip('\n')
    splits = cleaned_line.split()

    dataset = splits[0]

    if not dataset == "DATASET":
        total_events = splits[2]
        num_files    = splits[3]
        total_size   = splits[4]

        dataset_splits = dataset.split('.')
        dsid     = dataset_splits[1]
        ds_name  = dataset_splits[2]
        prod_tag = dataset_splits[-1]
    else:
        total_events = 0
        num_files    = 0
        total_size   = 0

        dsid     = ""
        ds_name  = ""
        prod_tag = ""

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
def getDatasetSizes(is_data):
    f = file(ami_data_file_name if is_data else ami_mc_file_name)

    data_size_dict = {}
    for l in f.readlines():
        processed_line = processDataLine(l) if is_data else processMCLine(l)
        if processed_line['dataset'] == 'DATASET': continue

        line_tag = 'data__' if is_data else 'mc__'

        if is_data:
            line_tag += processed_line['period'].strip('1234567890')
            line_tag += '__'
            line_tag += processed_line['stream']
        else:
            line_tag += processed_line['dsid']
            line_tag += '__'
            line_tag += processed_line['ds_name']
        line_tag += '__'
        line_tag += processed_line['prod_tag']

        if line_tag not in data_size_dict:
            data_size_dict[line_tag] = { 'total_events':0
                                       , 'num_files':0
                                       , 'total_size':0
                                       }
        data_size_dict[line_tag]['total_events'] += processed_line['total_events']
        data_size_dict[line_tag]['num_files']    += processed_line['num_files']
        data_size_dict[line_tag]['total_size']   += processed_line['total_size']

    return data_size_dict

#-------------------------------------------------------------------------------
def main():
    data_sizes = getDatasetSizes(is_data = True )
    mc_sizes   = getDatasetSizes(is_data = False)

    pp = pprint.PrettyPrinter(indent = 2)
    pp.pprint(data_sizes)
    print ''
    # pp.pprint(mc_sizes)

#===============================================================================
if __name__ == "__main__":
    main()
