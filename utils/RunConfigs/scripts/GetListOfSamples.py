#!/usr/bin/env python
# ==============================================================================
"""

Usage:
    TODO put sample usage
"""

import sys
import os.path
import optparse
import time

import glob
import subprocess

# ------------------------------------------------------------------------------
def getListOfSamples(master_directory, grep_for = ""):
    print 'getting list from %s/*%s*' % (master_directory, grep_for)
    samples = {}

    # Get and loop through list of directories in master directory
    # list_of_dirs = glob.glob(master_directory)
    list_of_dirs = glob.glob('%s/*%s*' % (master_directory, grep_for))
    # list_of_dirs = glob.glob('%s/*%s*' % (os.path.abspath(master_directory), grep_for))
    for i, dir in enumerate(list_of_dirs):
        # parse out sample name from the directory
        sample_name = getSampleName(dir)

        # If sample name is not included in samples, add it
        if not sample_name in samples:
            samples[sample_name] = []

        # Loop over files in directory dir, and add them to the list of samples
        for file in glob.glob('%s/*root' % dir):
            # /afs/cern.ch/user/b/bjackson/my_eos
            # samples[sample_name].append(file)
            samples[sample_name].append(file.replace(
                # '/afs/cern.ch/user/b/bjackson/my_eos',
                '%s/my_eos' % os.path.expandvars('${HOME}'),
                'root://eosatlas//eos/atlas/user/b/bjackson/') )
    return samples

# ------------------------------------------------------------------------------
def getSamplesForJobs(master_directory, grep_for = "", max_files_per_job = 1):
    master_directory = os.path.expandvars(master_directory)
    print '-------------------------------------------------------------------'
    print 'Getting samples for jobs:'
    print '\tMaster directory: %s' % master_directory
    print '\tMax files per job: %d' % max_files_per_job

    sample_list = getListOfSamples(master_directory, grep_for)
    sample_list_for_jobs = {}

    # print 'getSamplesForJobs -- sample_list: %s' % sample_list
    for sample_name in sample_list:
        # print '  getSamplesForJobs -- sample_name: %s' % sample_name
        # chunks( sample_list[sample_name]
        #       , max_files_per_job
        #       )
        sample_list_for_jobs[sample_name] = chunks( sample_list[sample_name]
                                                  , max_files_per_job
                                                  )

    return sample_list_for_jobs

# ------------------------------------------------------------------------------
def getSampleName(dir_name):
    sample_name = dir_name[dir_name.find("TeV")+4:dir_name.find(".tnt")]
    return sample_name

# ------------------------------------------------------------------------------
def chunks(master_list, max_size):
    # print 'chunks()'
    # num_chunks = int( (len(master_list) + max_size - 1)/max_size )
    # print 'len(master_list): %d -- max_size: %d -- num_chunks: %d' % (len(master_list), max_size, num_chunks)
    chunks = []
    for i in xrange(0, len(master_list), max_size):
        chunks.append( master_list[i:i+max_size] )
        # yield master_list[i:i+max_size]
    return chunks

# ------------------------------------------------------------------------------
def main():
    # print getListOfSamples('/afs/cern.ch/user/b/bjackson/my_eos/tnt.006/*')
    # print getSamplesForJobs('/afs/cern.ch/user/b/bjackson/my_eos/tnt.006/*', 1)
    sample_chunks = getSamplesForJobs( '/afs/cern.ch/user/b/bjackson/my_eos/tnt.006/'
                                     # , grep_for = ''
                                     , grep_for = '*Egamma.period*'
                                     , max_files_per_job = 3
                                     )

    for sample_name in sample_chunks:
        print 'sample name: %s' % sample_name
        for i, chunk in enumerate(sample_chunks[sample_name]):
            print '    chunk #: %s' % i
            for file in chunk:
                print '        -- file: %s' % (file)

# ==============================================================================
if __name__ == '__main__':
    main()
