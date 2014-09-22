#!/usr/bin/env python

import os
import stat
import subprocess

# ------------------------------------------------------------------------------
def containerize(output_container, input_container_list):
    print 'Registering the container ', output_container
    print 'input_container_list: ' , input_container_list

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
def getDistributionTag(file_name):
    tag = file_name.replace('files.','').replace('.txt', '')
    return tag

# ------------------------------------------------------------------------------
def getDistributionlist(file_name):
    f = file(file_name)
    container_list = []
    for l in f.readlines():
        cleaned_line = l.rstrip('\n').strip()
        if not '/' in cleaned_line: continue
        container_list.append(cleaned_line)
    return container_list

# ------------------------------------------------------------------------------
def main():
    # ------------------------------------------------------------------------------
    distribution_file_names = [ 'files.brett_part2.txt'
                              #   files.brett_part1.txt
                              # , files.brett_part2.txt
                              # , files.emma_part1.txt
                              # , files.emma_part2.txt
                              # , files.evelyn.txt
                              # , files.leigh_part1.txt
                              # , files.leigh_part2.txt
                              # , files.liz_part1.txt
                              # , files.liz_part2.txt
                              ]

    container_dist_dict = { getDistributionTag(fn):getDistributionlist(fn) for fn in distribution_file_names}

    for tag in container_dist_dict:
        containerize('user.bjackson.tnt_106.%s/' % tag, container_dist_dict[tag])

# ==============================================================================
if __name__ == "__main__":
    main()
