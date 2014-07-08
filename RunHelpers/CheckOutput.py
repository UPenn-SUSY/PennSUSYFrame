#!/usr/bin/env python
# ==============================================================================
# = check output directory to ensure all files are there
# = usage:
# =   ./RunHelpers/CheckOutput.py <location of run scripts> <location of output>
# = or (within a python script)
# =   CheckOutput.checkOutput(job_script_dir, output_dir)
# ==============================================================================

import glob
import sys
import re

# ------------------------------------------------------------------------------
def getListOfRunJobs(job_script_dir):
    # get list of job scripts
    list_of_job_scripts = glob.glob('%s/*py' % job_script_dir)

    list_of_samples_with_num_jobs = {}

    # loop through all run scripts, and extract the sample names and number of jobs
    for i, lojs in enumerate(list_of_job_scripts):
        # first extract the job label from the full path
        lojs = lojs.split('/')[-1]
        lojs = lojs.split('lx_batch_job.')[-1]
        lojs = lojs.split('.py')[0]

        # find the job number
        job_num_tag = re.search('([0-9]_of_[0-9])', lojs).group(1)
        this_job_num = job_num_tag.split('_of_')[0]
        num_jobs     = job_num_tag.split('_of_')[1]
        lojs = lojs.split('.%s' % job_num_tag)[0]

        # if this job is not in list_of_samples_with_num_jobs, add it
        if lojs not in list_of_samples_with_num_jobs:
            list_of_samples_with_num_jobs[lojs] = int(num_jobs)

    return list_of_samples_with_num_jobs

# ------------------------------------------------------------------------------
def checkForOutput(output_dir, list_of_samples_with_num_jobs):
    list_of_output_files = glob.glob('%s/*' % output_dir)
    cleaned_list_of_output_file = []

    for loof in list_of_output_files:
        # extract the leading part of the path from the file name
        loof = loof.split('/')[-1]
        cleaned_list_of_output_file.append(loof)

    # list to store missing output files
    list_of_missing_output = []

    # for each sample in the list of samples, check if there is output
    for sample_name in list_of_samples_with_num_jobs:
        num_jobs = list_of_samples_with_num_jobs[sample_name]

        # loop over each job for this sample
        for this_job in xrange(num_jobs):
            for cloof in cleaned_list_of_output_file:
                # does the file name contain the sample name?
                if sample_name in cloof:
                    # if yes, does it also have the correct job number?
                    if num_jobs == 1 or '%d_of_%d' in cloof:
                        # output is found :-)
                        print 'Found output for %s -- job %d of %d' % ( sample_name
                                                                      , this_job
                                                                      , num_jobs
                                                                      )
                    else:
                        # output not found :-(
                        print 'Missing output for %s -- job %d of %d' % ( sample_name
                                                                        , this_job
                                                                        , num_jobs
                                                                        )
                        list_of_missing_output.append('%s.%d_of_%d' % sample_name)

    print ''
    if len(list_of_missing_output) > 0:
        print 'Missing output for the following samples:'
        for lomo in list_of_missing_output:
            print '  ' , lomo
        return False

    print 'All output is found!'
    return True

# ------------------------------------------------------------------------------
def checkOutput(job_script_dir, output_dir):
    list_of_samples_with_num_jobs = getListOfRunJobs(job_script_dir)
    return checkForOutput(output_dir, list_of_samples_with_num_jobs)

# ------------------------------------------------------------------------------
def main():
    job_script_dir = sys.argv[1]
    output_dir     = sys.argv[2]

    checkOutput(job_script_dir, output_dir)

# ==============================================================================
if __name__ == "__main__":
    main()
