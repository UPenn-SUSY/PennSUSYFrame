CutOptimize
===========
Package to do cut optimization for b-l stop analysis.

OptimizeCuts.py
---------------
This script does most of the work.
This script will step through all the signal samples, and run TMVA cut optimization for each sample.
For now, only ttbar is considered for the background samples.
This should be OK since it is our largest background.
Usage:

```
time python OptimizeCuts.py
```

ReadOptimization.py
-------------------
Helper script called by OptimizeCuts to read the TMVA output files. You can probably ignore this.

ResultsFileToLatexTable.py
--------------------------
Take the output from OptimizeCuts.py, and create a tex document containing a table of the optimization results.
```
python ResultsFileToLatexTable.py
pdflatex results_table.tex
```

TestCuts.py
-----------
This script tests the results from OptimizeCuts.py.
It's a little crummy right now, but it does the job.
Once, you get the cut values you would like to test, input them into the cut value lists in this script.
When you run this script, a bunch of plots will be made to show signal vs background in the candidate signal regions.
Usage:
```
time python TestCuts.py
```
