# ContributionTable

Package to help making tables of the number of events in each region.

## ContributionsHelpers.py
Helper functions!

## CutFlowTable.ipynb
Make tables of number of events for each selection en route to the SR

Usage: Use IPython

## MakeContributionTable.py
Make table of contributions of each sample in each region.

Usage:
```
python BMinusLAnalysis/ContributionTable/MakeContributionTable.py compare_plots.b_minus_l.w_data.k_factor.root
```

## MakeSystematicTable
Make a table of the breakdown of each systematic

Usage:
```
python MakeSystematicTable.py --bkg ~/Desktop/scratch/HistFitterNtuples/BackgroundHistFitterTrees.root --sig ~/Desktop/scratch/HistFitterNtuples/SignalHistFitterTrees.root
```

