# ======================
# = top level Makefile =
# ======================
DIRS = NtupleLooper Selection HistMaker CutFlowDump

all::
	@ for dir in $(DIRS); \
	do (cd $$dir ; echo "" ; echo "Building $$dir" ; echo "" ; make ); \
	done

clean::
	@ for dir in $(DIRS); \
	do (cd $$dir ; make clean ); \
	done
