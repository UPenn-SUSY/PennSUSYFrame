# Package information
LIBRARY = PennSusyFrameCore
OBJDIR  = obj
DEPDIR  = $(OBJDIR)/dep
SRCDIR  = src
INCDIR  = include
# EXECUTABLE := $(PWD)/PennSusyFrameCore

LOCAL_LIBS_PATH =  $(SH_LIB_PATH)/libProgressBar.so
include ${PWD}/../Makefile.RootCore
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
INCLUDES += -I${ROOTCOREDIR}/../BCHCleaningTool/
INCLUDES += -I${ROOTCOREDIR}/../TileTripReader/
INCLUDES += -I${ROOTCOREDIR}/../JetResolution/
INCLUDES += -I${ROOTCOREDIR}/../JetUncertainties/

# Include the generic compilation rules
include $(PWD)/../Makefile.common

