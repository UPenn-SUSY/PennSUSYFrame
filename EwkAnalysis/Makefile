# Package information
LIBRARY = EwkAnalysis
OBJDIR  = obj
DEPDIR  = $(OBJDIR)/dep
SRCDIR  = src
INCDIR  = include
EXECUTABLE := $(PWD)/EwkAnalysis

LOCAL_LIBS_PATH =  $(SH_LIB_PATH)/libProgressBar.so
LOCAL_LIBS_PATH +=  $(SH_LIB_PATH)/libPennSusyFrameCore.so
LOCAL_LIBS_PATH += $(ROOTCOREDIR)/lib/libegammaAnalysisUtils.so
LOCAL_LIBS_PATH += $(ROOTCOREDIR)/lib/libMuonMomentumCorrections.so
LOCAL_LIBS_PATH += ${ROOTCOREDIR}/lib/libApplyJetCalibration.so
LOCAL_LIBS_PATH += ${ROOTCOREDIR}/lib/libMissingETUtility.so
LOCAL_LIBS_PATH += ${ROOTCOREDIR}/lib/libMt2.so
# BONUS_LIB_PATH = 

INCLUDES += -I../
INCLUDES += -I./
INCLUDES += -I../../
# INCLUDES += -I${ROOTCOREDIR}/../

# Include the generic compilation rules
include $(PWD)/../Makefile.common
