#!/usr/bin/env python

import sys
import os.path
import optparse
import time

import ROOT
import rootlogon
import metaroot

# ==============================================================================
ROOT.gROOT.ProcessLine(".x ${ROOTCOREDIR}/scripts/load_packages.C")
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libProgressBar.so')
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libCutFlowTracker.so')
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libPennSusyFrameCore.so')
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libEwkAnalysis.so')

# ==============================================================================
file_list = [ "/Users/bjackson/work/data12/NTUP_SUSYSKIM.01274851._000071.root.1"
            ]

t = ROOT.TChain('susy')
for fl in file_list:
    t.AddFile(fl)

# ==============================================================================
ewa = ROOT.PennSusyFrame.EwkAnalysis(t)
ewa.setIsData()
ewa.prepareTools()
ewa.Loop()

# ==============================================================================
print ''
print ''
