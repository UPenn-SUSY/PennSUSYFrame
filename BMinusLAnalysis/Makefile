# Package information
LIBRARY = BMinusLAnalysis
OBJDIR  = obj
DEPDIR  = $(OBJDIR)/dep
SRCDIR  = src
INCDIR  = include
EXECUTABLE := $(PWD)/BMinusLAnalysis

LOCAL_LIBS_PATH =  $(SH_LIB_PATH)/libProgressBar.so
LOCAL_LIBS_PATH += $(ROOTCOREDIR)/lib/libegammaAnalysisUtils.so
LOCAL_LIBS_PATH += $(ROOTCOREDIR)/lib/libMuonMomentumCorrections.so
LOCAL_LIBS_PATH += ${ROOTCOREDIR}/lib/libApplyJetCalibration.so
LOCAL_LIBS_PATH += ${ROOTCOREDIR}/lib/libMissingETUtility.so
LOCAL_LIBS_PATH += ${ROOTCOREDIR}/lib/libMt2.so
LOCAL_LIBS_PATH += ${ROOTCOREDIR}/lib/libGoodRunsLists.so
LOCAL_LIBS_PATH +=  $(SH_LIB_PATH)/libPennSusyFrameCore.so
# BONUS_LIB_PATH = 

INCLUDES += -I../
INCLUDES += -I./
INCLUDES += -I../../
INCLUDES += -I${ROOTCOREDIR}/../
INCLUDES += -I${ROOTCOREDIR}/../GoodRunsLists/
INCLUDES += -I${ROOTCOREDIR}/../PATCore/

# Include the generic compilation rules
include $(PWD)/../Makefile.common
