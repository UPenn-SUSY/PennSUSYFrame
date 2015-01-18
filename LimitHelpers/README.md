Setting up and using limit setting tools
========================================

Download and install HistFitter
-------------------------------

- First, we need to download HistFitter

```
source SetupHistFitter.sh
```

Make link of relevant scripts in the appropriate places
-------------------------------------------------------
```
ln -s ${PWD}/../LimitHelpers/ .
```

Create HistFitterTree input files
---------------------------------
TODO write how to do this

Do a hypothesis test
--------------------
Next, we will perform a hypothesis test using the above HistFitterTree input files

```
HistFitter.py -p -t -w -f -F excl -D 'before,after' LimitHelpers/SampleExcl.py
```

This will run a hypothesis test on several signal model, testing if the mu=1
hypothesis is consistent with the data. Currently, this sample configuration
is set to blind the data in the signal region. The data in the signal region
is set to be equal to the combined background prediction in the signal region.
Then, the fit is performed by allowing both the signal and background
normalizations to float independently in order to acheive the best
data/prediciton agreement in all regions (both control and singal regions).

The command line options are the following:

- -p: Perform hypothesis test
- -t: Read input from tree
- -w: Create workspace
- -f: Peform fit
- -F: What fit to perform. excl = exclussion fit
- -D: Draw plots. Currently set to draw distributions in SR/CR before and after fit. Options include ['allPlots', 'before', 'after', 'corrMatrix', 'sepComponents', 'likelihood'].

```
for each in LimitHelpers/BRGrid/BLStopFit_*py ; do echo $each ; echo HistFitter.py -p -t -w -f -F excl -D 'before,after' $each ; echo '' ; done
```

This takes a couple of minutes, but  when it  completes, the output will be
located in the results directory with the prefix "SampleExcl." 

TODO write more about the output here

Draw Limit contours
-------------------
Next, we want to draw limit contours! First, we need to take our output
workspace from the fit, extract the p values, and place them into a test file.

```
python LimitHelpers/MakeSampleListFiles.py
```

This creates a text file called `SampleExcl_Output_hypotest__1_harvest_list`,
and a helper script called ```summary_harvest_tree_description.py```. 

Now, we can make a sample CLs plot! This script will read the output from the
previous step, and plot the CLs value for each mass.
```
python  LimitHelpers/MakeSamplePValuePlot.py
evince SamplePValue.pdf
```

Create Yield table and pull distributions
-----------------------------------------
We can make some yield tables from a background only fit using the
`MakeYieldTable.sh` script:
```
./LimitHelpers/MakeYieldTable.sh
```
This creates three latex tables of the yields in each of our regions.

Using these tables, we can create pull distributions showing the pull on the
fit from each of our CR/VRs
```
python LimitHelpers/MakePullDist.py
```

