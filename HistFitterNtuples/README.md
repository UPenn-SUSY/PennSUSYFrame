HistFitterNtuples
=================

This directory is a place to store HistFitter ntuples which are the inputs to HistFitter, and are used to perform fits of the background shapes to the data.
There is also a script to convert a list of optimization ntuples into a HistFitter ntuple.

OptimizeToHistFitterNtuple.py
-----------------------------
This is a script that takes a list of optimization ntuples and makes a new file which can be read by HistFitter.
Currently, the paths for the B-L optimization ntuple are hard coded into the script.
This should be changed, and made more general.

Usage:
```
python OptimizeToHistFitterNtuple.py
```
