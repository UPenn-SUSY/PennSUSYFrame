# ======================
# = top level Makefile =
# ======================
# DIRS = Selection NtupleLooper HistMaker Parser CutFlowDump
DIRS = Selection Parser NtupleLooper HistMaker CutFlowDump

all::
	# @ for dir in $(DIRS); \
	# do (cd $$dir ; echo "" ; echo "Building $$dir" ; echo "" ; make ); \
	# done
	@ for dir in $(DIRS); \
	do (cd $$dir ; echo "" ; echo "Building $$dir" ; echo "" ; make shlib ); \
	done
	@ for dir in $(DIRS); \
	do (cd $$dir ; echo "" ; echo "Building $$dir" ; echo "" ; make executable ); \
	done

clean::
	@ for dir in $(DIRS); \
	do (cd $$dir ; make clean ); \
	done
