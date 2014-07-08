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
def finalizeOutput(job_script_dir, output_dir):
    # first, check the output is all there
    pass_check_output = CheckOutput.checkOutput(job_script_dir, output_dir)

    if not pass_check_output:
        return False

    # next, merge the the files in output directory
    RunHelpers.mergeOutputFiles(output_dir, False)

# ------------------------------------------------------------------------------
def main():
    job_script_dir = sys.argv[1]
    output_dir     = sys.argv[2]

    finalizeOutput(job_script_dir, output_dir)

# ==============================================================================
if __name__ == "__main__":
    main()
