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
file_list = [ "${BASE_WORK_DIR}/../mc12/mc12_8TeV.116600.gg2ZZJimmy_AUET2CT10_ZZ4lep.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512_tid01267663_00/NTUP_SUSY.01267663._000001.root.1"
            , "${BASE_WORK_DIR}/../mc12/mc12_8TeV.116600.gg2ZZJimmy_AUET2CT10_ZZ4lep.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512_tid01267663_00/NTUP_SUSY.01267663._000002.root.1"
            , "${BASE_WORK_DIR}/../mc12/mc12_8TeV.116600.gg2ZZJimmy_AUET2CT10_ZZ4lep.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512_tid01267663_00/NTUP_SUSY.01267663._000003.root.1"
            , "${BASE_WORK_DIR}/../mc12/mc12_8TeV.116600.gg2ZZJimmy_AUET2CT10_ZZ4lep.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512_tid01267663_00/NTUP_SUSY.01267663._000004.root.1"
            ]

t = ROOT.TChain('susy')
for fl in file_list:
    t.AddFile(fl)

# ==============================================================================
ewa = ROOT.PennSusyFrame.EwkAnalysis(t)
ewa.setIsMC()
ewa.setFullSim()
ewa.prepareTools()
ewa.Loop()

# ==============================================================================
print ''
print ''
