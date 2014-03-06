# ======================
# = top level Makefile =
# ======================
DIRS = Helpers ProgressBar Selection Parser NtupleLooper HistMaker \
	   PlotNtupleMaker CutFlowDump EventNumberDump ChannelFractions \
	   CalculateFakeRates OptimizeIsolation

all::build link

build::
	@ for dir in $(DIRS); \
	do (cd $$dir ; echo "" ; echo "Building $$dir" ; echo "" ; make shlib ); \
	done
link::
	@ for dir in $(DIRS); \
	do (cd $$dir ; echo "" ; echo "Linking $$dir" ; echo "" ; make executable ); \
	done

clean::
	@ for dir in $(DIRS); \
	do (cd $$dir ; make clean ); \
	done
