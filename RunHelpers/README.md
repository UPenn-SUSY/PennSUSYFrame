RunHelpers
==========
This directory is full of scripts which are useful when running analysis jobs.
The primary purpose of these scripts is to divide up datasets to run in parallel and combine the results afterward.

RunHelpers.py
-------------
This file contains a set of helper functions for running a set of jbos in parallel (either using the multiprocessing module or running on the lxplus batch queue).

FinalizeOutput.py
-----------------
This script checks if all the output of a set of jobs exists and then merges the output files.
Usage:
```
./RunHelpers/FinalizeOutput.py <location of run scripts> <location of output>
```
or, within a python script:
```
FinalizeOutput.finalizeOutput(job_script_dir, output_dir)
```

CheckOutput.py
--------------
This script checks that the output from a set of jobs is comlpete, and all the files look OK (at least that they are not zombies).
Usage:
```
./RunHelpers/CheckOutput.py <location of run scripts> <location of output>
```
or, within a python script:
```
CheckOutput.checkOutput(job_script_dir, output_dir)
```

SubmitPythonToBatch.sh
----------------------
It's a bit awkward to submit a python script to the lxplus batch queue. It's much more convenient to wrap it in a bash script.
This helper script does that.
Usage:
```
./RunHelpers/SubmitPythonToBatch.sh <QUEUE NAME> <PATH TO PYTHON SCRIPT> <CALL FROM>
```

CheckForZombie.C
----------------
Simple root macro which checks if a file is a zombie. You probably don't need to call this macro explicitely.

