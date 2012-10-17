# file: 	Makefile
# author:	Ryan Reece  <ryan.reece@cern.ch>
# author: Brett Jackson <brett.david.jackson@cern.ch
# created: 	February 2010
# modified: November 2011
#------------------------------------------------------------------------------

# Package information
LIBRARY = AtlasSFrameUtils
OBJDIR  = obj
DEPDIR  = $(OBJDIR)/dep
SRCDIR  = src
INCDIR  = include

# additional include paths
D3PDObjects_DIR = ../D3PDObjects

INCLUDES += -I./
INCLUDES += -I../
INCLUDES += -I$(D3PDObjects_DIR)/include
INCLUDES += -I{PWD}/include/
INCLUDES += -I../RootCore/egammaAnalysisUtils
INCLUDES += -I../RootCore/egammaEvent/
#INCLUDES += -I../RootCore/JetResolution
#INCLUDES += -I../RootCore/MuonMomentumCorrections
#INCLUDES += -I../RootCore/ApplyJetCalibration/

# Include the generic compilation rules
include $(SFRAME_DIR)/Makefile.common
