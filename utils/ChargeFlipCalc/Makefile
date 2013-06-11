LIBRARY := ChargeFlipCalc
OBJDIR  := $(PWD)/obj
SRCDIR  := $(PWD)/src
INCDIR  := $(PWD)/include
EXECUTABLE := $(PWD)/ChargeFlipCalc
BONUS_LIB_PATH := $(SFRAME_LIB_PATH)/libSusyAnalysisTools.so

LOCAL_LIBS_PATH = $(SH_LIB_PATH)/libNtupleLooper.so
LOCAL_LIBS_PATH += $(SH_LIB_PATH)/libParser.so
LOCAL_LIBS_PATH += $(SH_LIB_PATH)/libHistMaker.so
LOCAL_LIBS_PATH += $(SH_LIB_PATH)/libSelection.so
LOCAL_LIBS_PATH += $(SH_LIB_PATH)/libProgressBar.so
LOCAL_LIBS_PATH += $(SH_LIB_PATH)/libHelpers.so

INCLUDES += -I../
INCLUDES += -I./
INCLUDES += -I../../

include $(PWD)/../Makefile.common
