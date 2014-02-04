# Package information
LIBRARY = BMinusLAnalysis
OBJDIR  = obj
DEPDIR  = $(OBJDIR)/dep
SRCDIR  = src
INCDIR  = include
EXECUTABLE := $(PWD)/BMinusLAnalysis

LOCAL_LIBS_PATH =  $(SH_LIB_PATH)/libProgressBar.so
include ${PWD}/../Makefile.RootCore
LOCAL_LIBS_PATH +=  $(SH_LIB_PATH)/libPennSusyFrameCore.so
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
