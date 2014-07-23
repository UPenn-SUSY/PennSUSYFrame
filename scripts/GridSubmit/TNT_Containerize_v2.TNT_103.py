#!/usr/bin/env python

import os
import stat
import subprocess

# ------------------------------------------------------------------------------
def containerize(output_container, input_container_list):
    print 'Registering the container ', output_container
    temp_register = subprocess.Popen( 'dq2-register-container %s' % output_container
                                    , shell=True
                                    , stdout=subprocess.PIPE
                                    , stderr=subprocess.STDOUT
                                    )
    print temp_register.stdout.readlines()

    for icl in input_container_list:
        print 'adding datasets from input container (%s) to output container: %s' % (icl, output_container)

        temp_get_list = subprocess.Popen( 'dq2-list-datasets-container %s' % icl
                                        , shell=True
                                        , stdout=subprocess.PIPE
                                        , stderr=subprocess.STDOUT
                                        )
        for line in temp_get_list.stdout.readlines():
            print line
            temp_add_data_set = subprocess.Popen( 'dq2-register-datasets-container %s %s' % (output_container, line)
                                                , shell=True
                                                , stdout=subprocess.PIPE
                                                , stderr=subprocess.STDOUT
                                                )
            print temp_add_data_set.stdout.readlines()

# ------------------------------------------------------------------------------
def main():
    # ------------------------------------------------------------------------------
    output_container_name_brett = 'user.bjackson.tnt_103.merge_brett/'
    output_container_name_liz   = 'user.bjackson.tnt_103.merge_liz/'
    output_container_name_leigh = 'user.bjackson.tnt_103.merge_leigh/'
    output_container_name_emma  = 'user.bjackson.tnt_103.merge_emma/'
    input_container_list_brett = [ ]
    input_container_list_liz   = [ ]
    input_container_list_leigh = [ ]
    input_container_list_emma  = [ ]

    dataset_file = file('dataset_distribution.tnt_103.cvs')
    for line in dataset_file.readlines():
        splits = line.split(',')
        if len(splits) < 9: continue
        # print line
        # print splits
        if splits[0] == '1':
            print 'add to brett: ' , splits[10]
            input_container_list_brett.append(splits[10])
        if splits[1] == '1':
            print 'add to liz: ' , splits[10]
            input_container_list_liz.append(splits[10])
        if splits[2] == '1':
            print 'add to leigh: ' , splits[10]
            input_container_list_leigh.append(splits[10])
        if splits[3] == '1':
            print 'add to emma: ' , splits[10]
            input_container_list_emma.append(splits[10])

    containerize(output_container_name_brett , input_container_list_brett)
    containerize(output_container_name_liz   , input_container_list_liz)
    containerize(output_container_name_leigh , input_container_list_leigh)
    containerize(output_container_name_emma  , input_container_list_emma)

# ==============================================================================
if __name__ == "__main__":
    main()
