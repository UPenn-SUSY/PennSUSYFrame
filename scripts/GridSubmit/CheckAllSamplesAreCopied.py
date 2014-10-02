#!/usr/bin/env python
"""
This is a script to check that all the samples which were to be submitted to the
grid are actually accounted for in the eos file lists. It should be noted that
this only checks that an eos file list exists for this sample, not that the eos
file list represents the whole input.
Usage:
    python CheckAllSamplesAreCopied.py
"""

import os
import glob
import pprint
import GenerateGridSubmitScripts as GridSubmit

#-------------------------------------------------------------------------------
def checkSamplesAreCopied(eos_file_list_dir):
    # get list of samples which were should have been submitted to grid
    sample_list   = GridSubmit.generateDSDictList()
    # get list of eos file lists
    eos_file_list = glob.glob('%s/*.txt' % eos_file_list_dir)

    # Construct dictionary. one entry for each sample submitted to grid - value
    # is a list of eos files corresponding to this sample
    samples_copied = {sl['tag']:[] for sl in sample_list}

    # loop over samples submitted to grid
    for  sl in sample_list:
        # loop over eos file lists looking for matches
        for efl in eos_file_list:
            # if there is a match - append to the list
            if sl['tag'] in efl:
                samples_copied[sl['tag']].append(efl)

    # first, count the number of samples which appear to be OK
    num_ok_samples = 0
    for sc in sorted(samples_copied):
        if len(samples_copied[sc]) == 1:
            num_ok_samples += 1
    print 'Num samples which appear OK: ' , num_ok_samples , ' of ' , len(samples_copied)
    print ''

    # Next, look for samples with no eos file list
    print "Samples with 0 eos files:"
    for sc in sorted(samples_copied):
        if len(samples_copied[sc]) == 0:
            print '  ' , sc
    print ''

    # Finally, look for samples with multiple eos file lists
    print "Samples with > 1 eos files:"
    for sc in sorted(samples_copied):
        if len(samples_copied[sc]) > 1:
            print '  ' , sc
            for eos_file in samples_copied[sc]:
                print '    ', eos_file
    print ''

#-------------------------------------------------------------------------------
def main():
    eos_file_list_dir = '%s/EosFileLists/tnt_106/' % os.environ['BASE_WORK_DIR']
    checkSamplesAreCopied(eos_file_list_dir)

#===============================================================================
if __name__ == "__main__":
    main()
