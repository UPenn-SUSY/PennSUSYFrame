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

If you would like to add the ATLAS labels to the pull distributions, add the
following to the `HistFitter/python/pullPlotUtils.py` file toward the end of
the `MakeHistPullPlot` function, just before the canvases are printed:

```
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    upperPad.cd()

    font_size = 0.08
    atlas_label_x = 0.2
    lumi_label_x = 0.5
    label_y = 0.75
    del_x = 0.13*696*gPad.GetWh()/(474*gPad.GetWw())
    del_y = 0.18*696*gPad.GetWh()/(474*gPad.GetWw())

    atlas_label = ROOT.TLatex()
    atlas_label.SetNDC()
    atlas_label.SetTextFont(72)
    atlas_label.SetTextSize(font_size)
    atlas_label.DrawLatex(atlas_label_x, label_y, "ATLAS")

    atlas_label_2 = ROOT.TLatex()
    atlas_label_2.SetNDC()
    atlas_label_2.SetTextFont(42)
    atlas_label_2.SetTextSize(font_size)
    atlas_label_2.DrawLatex(atlas_label_x+del_x, label_y, "Internal")

    lumi_label = ROOT.TLatex()
    lumi_label.SetNDC()
    lumi_label.SetTextFont(42)
    lumi_label.SetTextSize(0.9*font_size)
    lumi_label.DrawLatex(lumi_label_x, label_y,
                         "#int Ldt = 20.3 fb^{-1}")

    com_energy_label = ROOT.TLatex()
    com_energy_label.SetNDC()
    com_energy_label.SetTextFont(42)
    com_energy_label.SetTextSize(0.9*font_size)
    com_energy_label.DrawLatex(lumi_label_x+2*del_x, label_y,
                               "#sqrt{s} = 8 TeV")
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
```

I know this is pretty gross :-(

