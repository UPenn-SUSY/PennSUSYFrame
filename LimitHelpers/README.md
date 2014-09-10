Setting up and using limit setting tools
========================================

Download and install HistFitter
-------------------------------

- First, we need to download HistFitter

```bash
source SetupHistFitter.sh
```

Make link of relevant scripts in the appropriate places
-------------------------------------------------------
```bash
ln -s ${PWD}/../LimitHelpers/ .
```

Create HistFitterTree input files
---------------------------------
TODO write how to do this

Do a hypothesis test
--------------------
Next, we will perform a hypothesis test using the above HistFitterTree input files

```bash
time HistFitter.py -p -t -w -f -F excl -D 'before,after' LimitHelpers/SampleExcl.py
```

This will run a hypothesis test on several signal model, testing if the $\mu$=1 hypothesis is consistent with the data.

TODO write more about the output here
