#!/usr/bin/env python

import sys
import os.path
import optparse
import time

import ROOT
#import rootlogon
#import metaroot

sys.path.append('%s/CrossSectionReader/' % os.environ['BASE_WORK_DIR'])
import CrossSectionReader

# ==============================================================================
print 'loading packages'
ROOT.gROOT.ProcessLine(".x ${ROOTCOREDIR}/scripts/load_packages.C")
print 'loading libraries'
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libProgressBar.so')
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libCutFlowTracker.so')
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libHistogramHandlers.so')
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libPennSusyFrameCore.so')
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libEwkAnalysis.so')

# ==============================================================================
#mc
file_list = [ "~/workdir/susyd3pd/mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_s1499_s1504_r3945_r3549_p1512_tid01267519_00/NTUP_SUSY.01267519._000001.root.1"
            ]
#data
#file_list = [ "~/workdir/susyd3pd/data12_8TeV.00200982.physics_Egamma.merge.NTUP_SUSYSKIM.r4065_p1278_p1542_tid01274350_00/NTUP_SUSYSKIM.01274350._000001.root.1"
#]

t = ROOT.TChain('susy')
for fl in file_list:
    t.AddFile(fl)

# ==============================================================================
ewa = ROOT.PennSusyFrame.EwkAnalysis(t)
ewa.setPrintEventDetails(True)
#ewa.setMaxNumEvents(10)
ewa.setIsMC()
ewa.prepareTools()
ewa.Loop()

# ==============================================================================
print ''
print ''
