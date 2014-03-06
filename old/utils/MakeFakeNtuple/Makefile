LIBRARY := MakeFakeNtuple
OBJDIR  := $(PWD)/obj
SRCDIR  := $(PWD)/src
INCDIR  := $(PWD)/include
EXECUTABLE := $(PWD)/MakeFakeNtuple

LOCAL_LIBS_PATH =  $(SH_LIB_PATH)/libParser.so
LOCAL_LIBS_PATH += $(SH_LIB_PATH)/libHelpers.so
LOCAL_LIBS_PATH += $(SH_LIB_PATH)/libNtupleLooper.so
LOCAL_LIBS_PATH += $(SH_LIB_PATH)/libHistMaker.so
LOCAL_LIBS_PATH += $(SH_LIB_PATH)/libProgressBar.so
LOCAL_LIBS_PATH += $(SH_LIB_PATH)/libSelection.so
BONUS_LIB_PATH =  $(SFRAME_LIB_PATH)/libSusyAnalysisTools.so
BONUS_LIB_PATH += $(ROOTCOREDIR)/lib/libSusyMatrixMethod.so
BONUS_LIB_PATH += $(ROOTCOREDIR)/lib/libHistFitterTree.so

INCLUDES += -I../
INCLUDES += -I./
INCLUDES += -I../../
INCLUDES += -I$(ROOTCOREDIR)/../SusyMatrixMethod

include $(PWD)/../Makefile.common
