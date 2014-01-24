# ======================
# = top level Makefile =
# ======================
# DIRS = SFrame AtlasSFrameUtils CommonTools D3PDObjects SelectionTools \
# 	   SusyAnalysisTools SusyDiLepton
DIRS = ProgressBar TinyTlv PennSusyFrameCore EwkAnalysis BMinusLAnalysis

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
