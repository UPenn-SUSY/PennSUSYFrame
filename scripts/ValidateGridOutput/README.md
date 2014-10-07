ValidateGridOutput
==================

This directory is full of scripts to validate the output from the grid. This includes checking all the samples we would like to run over are accounted for, checking that there are no errors in the EosFileLists, and finally, checking that the number of events accounted for in our skims match with the numbers we expect based on ami.

ValidateEosFileLists.py
-----------------------
This script looks at each of the eos file lists, and checks that there are no bad entries. A bad entry includes a line with too few or too many entries, or an entry which is flagged as an "error." If there are any eos files with bad entries, the offending line is printed to the screen. As the script finishes running, the total number of "bad files" is displayed on the screen.

Usage:
```
python ValidateEosFileLists.py
```

CheckAllSamplesAreCopied.py
---------------------------
This script looks at the list of samples which were supposed to be submitted to the grid, and the corresponding eos file lists.
It then, checks that there is exactly one eos file list for each sample which was submitted to the grid. If any of the samples are missing, or there are multiple eos file lists for any sample, this will be displayed on the screen.

Usage:
```
python CheckAllSamplesAreCopied.py
```

CheckForIncompleteDataSets.py
------------------------------
This script looks at each of the eos file lists, and counts up the total number of events corresponding to the input dataset. The script then compares this number to the number of events in the dataset according to ami. If these numbers differ for any dataset, the incomplete datasets are listed along with the difference in number events and the percent missing.

Usage:
```
python CheckForIncompleteDataSets.py
```
