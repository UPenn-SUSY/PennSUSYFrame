#!/bin/sh
# ==============================================================================
# = This is a helper script to take a python file and submit it to the lxbatch
# = queue
# = Strictly, this isn't necessary if you are insensitive to the version of
# = python, root, and gcc, but in addition to calling your script, this will
# = set up the environment as if you were logging into an interactive session
# =
# = usage:
# =   ./RunHelpers/SubmitPythonToBatch.sh <QUEUE NAME> <PATH TO PYTHON SCRIPT> <CALL FROM>
# ==============================================================================

batch_queue=$1
script_path=$2
call_from=$3

echo "submitting $script_path to the queue $batch_queue"

# setup env
submit_command="source ~/.bashrc"

# move to directory if specified in user inputs
if [[ ! $call_from == "" ]] ; then
  submit_command="${submit_command} ; cd ${call_from}"
fi

# submit job to batch
submit_command="${submit_command} ; ${script_path}"

# submit to lxbatch queue
bsub -q $batch_queue "${submit_command}"
