#!/usr/bin/env python
# ==============================================================================
# = finalize output of run
# = this includes:
# =   check if all output exists for all jobs
# =   merge output files in output directory
# = usage:
# =   ./RunHelpers/FinalizeOutput.py <location of run scripts> <location of output>
# = or (within a python script)
# =   FinalizeOutput.finalizeOutput(job_script_dir, output_dir)
# ==============================================================================

import sys
import CheckOutput
import RunHelpers

# ------------------------------------------------------------------------------
def finalizeOutput(job_script_dir, output_dir, flat_ntuples):
    # first, check the output is all there
    pass_check_output = CheckOutput.checkOutput(job_script_dir, output_dir)
    print pass_check_output

    if not pass_check_output:
        print 'did not pass output check, bailiing before merging the files'
        return False

    # next, merge the the files in output directory
    RunHelpers.mergeOutputFiles(output_dir, flat_ntuples)

# ------------------------------------------------------------------------------
def main():
    job_script_dir = sys.argv[1]
    output_dir     = sys.argv[2]
    flat_ntuples   = False if len(sys.argv) < 4 else sys.argv[3] 
    if flat_ntuples == '1' :
        flat_ntuples = True
    else:
        flat_ntuples = False

    finalizeOutput(job_script_dir, output_dir, flat_ntuples)

# ==============================================================================
if __name__ == "__main__":
    main()
