EosFileLists
============
This directory contains the file lists required for running our analysis code. The format of these scripts is:

```
<path_to_file>  <total_number_of_events>  <number_events_in_skim> <sum_of_event_weights>
```

There should be one file for each sample.

GenerateEosList.sh
------------------
This script is used to create eos file lists for all the datasets in a given directory on eos.
The output files will be placed in the present working directory.
In order to not clutter this director, and general organization, it is recomended to create a sub-directory, and call the script from there.
The syntax for running this script is:
```
source ../GenerateEosList.sh <tag for this production> <path on eos for these datasets>
```
An example is shown here:
```
source ../GenerateEosList.sh tnt_106 /eos/atlas/user/b/bjackson/tnt_106
```

GenerateLocalList.sh
--------------------
This is very similar to GenerateEosList.sh, except it will create file lists for local files (not on eos).
The syntax is:
```
source ../GenerateLocalList.sh <tag for this production> <path on local disk for these datasets>
```
An example is shown here:
```
source ../GenerateLocalList.sh ttnt_106 /afs/cern.ch/user/b/bjackson/work/public/PennSUSYFrame.00.03.21/SafeTTNTDir/
```

GetAllNumbersFromTnt.py
-------------------
Script to get the number of entries, total number of unskimmed events, and the sum of event weights in the TNT tree. This will output three text files called tmp_entries.txt, tmp_events.txt, and tmp_weights.txt.
The syntax is:
```
python GetAllNumbersFromTnt.py <path to file>
```


GetNumberEntries.py
-------------------
Script to get the number of entries in the TNT tree. This will output a text file called tmp_entries.txt.
The syntax is:
```
python GetNumberEntries.py <path to file>
```

GetNumberUnskimmedEvents.py
---------------------------
Script to get the number of unskimmed events which were run over to produce this TNT. This will output a text file called tmp_events.txt.
The syntax is:
```
python GetNumberUnskimmedEvents.py <path to file>
```

GetSumEventWeights.py
---------------------
Script to get the sum of event weights for the events which were run over to produce this TNT. This will output a text file called tmp_weights.txt.
The syntax is:
```
python GetSumEventWeights.py <path to file>
```

EstimateMCEventWeights.py
-------------------------
This script was used for an older round of TNTs where the sum of event weights was not included as an entry in the TNT.
This script was used to estimate the total sum of event weights from the events included in the skim.
This is probably not needed any more.

How to go from grid output to eos file lists
--------------------------------------------
TODO fill this in
