#enter name of our code library and the program files
ILIBNAME=run_systs #Enter name of your library here
#enclose multiple programs in quotes
PROGRAMS='$(subst .C,, $(shell cd ./; ls *.C 2>/dev/null))'
SRCS = $(shell ls *.C 2>/dev/null)
OBJ= $(foreach PP, $(PROGRAMS), $(PP).o)

LD=g++

INCLUDEFLAGS = #-I./

LD_FLAGS = #-L./ -lmycode

ROOTLIBS = `root-config --libs`
ROOTCFLAGS = $(shell root-config --cflags)
ROOTGLIBS = $(shell root-config --glibs)

.cxx.o:
	$(CXX) $(CXXFLAGS) $(ROOTCFLAGS) $(INCLUDEFLAGS) -c $<

all: $(PROGS)
	$(CXX) run_systs.C $(CXXFLAGS) $(ROOTCFLAGS) $(INCLUDEFLAGS) -c $<
	$(LD) -o run_systs run_systs.o  $(ROOTLIBS) -m64
