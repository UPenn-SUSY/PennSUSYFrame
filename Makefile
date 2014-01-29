# ======================
# = top level Makefile =
# ======================
DIRS = ProgressBar CutFlowTracker TinyTlv \
	   PennSusyFrameCore EwkAnalysis BMinusLAnalysis

all::
	@ for dir in $(DIRS); \
	do (cd $$dir ; echo "" ; echo "Building $$dir" ; echo "" ; make ); \
	done

clean::
	@ for dir in $(DIRS); \
	do (cd $$dir ; make clean ); \
	done

distclean::
	@ for dir in $(DIRS); \
	do (cd $$dir ; make distclean ); \
	done
