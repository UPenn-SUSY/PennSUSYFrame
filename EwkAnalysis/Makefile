# Package information
LIBRARY = EwkAnalysis
OBJDIR  = obj
DEPDIR  = $(OBJDIR)/dep
SRCDIR  = src
INCDIR  = include
EXECUTABLE := $(PWD)/EwkAnalysis

LOCAL_LIBS_PATH =  $(SH_LIB_PATH)/libProgressBar.so
include ${PWD}/../Makefile.RootCore
LOCAL_LIBS_PATH +=  $(SH_LIB_PATH)/libHistogramHandlers.so
LOCAL_LIBS_PATH += $(SH_LIB_PATH)/libPennSusyFrameCore.so
LOCAL_LIBS_PATH += ${SH_LIB_PATH}/libCutFlowTracker.so
# BONUS_LIB_PATH = 

INCLUDES += -I../
INCLUDES += -I./
INCLUDES += -I../../
INCLUDES += -I${ROOTCOREDIR}/../
INCLUDES += -I${ROOTCOREDIR}/../GoodRunsLists/
INCLUDES += -I${ROOTCOREDIR}/../PATCore/
INCLUDES += -I${ROOTCOREDIR}/../MuonEfficiencyCorrections/
INCLUDES += -I${ROOTCOREDIR}/../DGTriggerReweight/
INCLUDES += -I${ROOTCOREDIR}/../ReweightUtils/

# Include the generic compilation rules
include $(PWD)/../Makefile.common
