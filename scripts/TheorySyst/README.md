Run Theory Systematics
======================

Create NTUP_TRUTH ntuples from EVNT files
-----------------------------------------
First, create a set of NTUP_TRUTH ntuples from EVNT files on the grid.
To make the files, make a file called `data_sets.txt` which contains
a list of the EVNT file datasets needed to run the systematic variations.
```
setupATLAS
localSetupDQ2Client
voms-proxy-init -voms atlas --valid 168:00
source $AtlasSetup/scripts/asetup.sh 17.2.14.5,slc5,gcc43
localocalSetupPandaClient
source make_NTUP_TRUTH.sh
```
This goes reasonably quickly. The output files can stay on the grid.

Get a lits of output datasets
```
dq2-ls user.bjackson.\*v0_150220_EXT0/ | sort > data_sets.NTUP_SUSY.txt
```

Run the truth level study and get histograms
--------------------------------------------
Run a truht level study on the NTUP_TRUTH files from the previous
step. Modify the run_systs.C file to perform the desired selection,
and fill histograms for each region.

Set up athena and build the ROOT macro to be run on the grid.
Note, this must be done in a fresh environment because apparently
dq2 and athena don't play nice together.
```
source $AtlasSetup/scripts/asetup.sh 17.2.14.5,slc5,gcc43
source setup.sh
make
```

Now, just to be safe, start a fresh session to submit. I don't
think this is necessary
```
source setup.sh
voms-proxy-init -voms atlas --valid 168:00
time python sub.py data_sets.NTUP_SUSY.txt
```

Copy the files from the grid
----------------------------
```
user.bjackson.*plots_150220_v1*root/
```

Merge them using
```
python move_datasets.py
```

Extract systematic variations
-----------------------------
```
python comparison_systs_v2.py
```

