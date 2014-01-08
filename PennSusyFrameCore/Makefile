# Package information
LIBRARY = PennSusyFrameCore
OBJDIR  = obj
DEPDIR  = $(OBJDIR)/dep
SRCDIR  = src
INCDIR  = include
EXECUTABLE := $(PWD)/PennSusyFrameCore

LOCAL_LIBS_PATH =  $(SH_LIB_PATH)/libProgressBar.so
LOCAL_LIBS_PATH += $(ROOTCOREDIR)/lib/libegammaAnalysisUtils.so
LOCAL_LIBS_PATH += $(ROOTCOREDIR)/lib/libMuonMomentumCorrections.so
# BONUS_LIB_PATH = 

INCLUDES += -I../
INCLUDES += -I./
INCLUDES += -I../../
# INCLUDES += -I${ROOTCOREDIR}/../

# Include the generic compilation rules
include $(PWD)/../Makefile.common
