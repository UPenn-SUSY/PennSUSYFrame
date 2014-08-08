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
file_list = [ "~/workdir/signal_grids/mc12_8TeV.186284.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_135_0_n1_115_0_xsl_0_95.merge.NTUP_SUSY.e2410_a220_a205_r4540_p1512_tid01374632_00/NTUP_SUSY.01374632._000001.root.1",
"~/workdir/signal_grids/mc12_8TeV.186284.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_135_0_n1_115_0_xsl_0_95.merge.NTUP_SUSY.e2410_a220_a205_r4540_p1512_tid01374632_00/NTUP_SUSY.01374632._000002.root.1",
"~/workdir/signal_grids/mc12_8TeV.186284.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_135_0_n1_115_0_xsl_0_95.merge.NTUP_SUSY.e2410_a220_a205_r4540_p1512_tid01374632_00/NTUP_SUSY.01374632._000003.root.1",
"~/workdir/signal_grids/mc12_8TeV.186284.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_135_0_n1_115_0_xsl_0_95.merge.NTUP_SUSY.e2410_a220_a205_r4540_p1512_tid01374632_00/NTUP_SUSY.01374632._000004.root.1",
"~/workdir/signal_grids/mc12_8TeV.186284.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_135_0_n1_115_0_xsl_0_95.merge.NTUP_SUSY.e2410_a220_a205_r4540_p1512_tid01374632_00/NTUP_SUSY.01374632._000005.root.1",
"~/workdir/signal_grids/mc12_8TeV.186284.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_135_0_n1_115_0_xsl_0_95.merge.NTUP_SUSY.e2410_a220_a205_r4540_p1512_tid01374632_00/NTUP_SUSY.01374632._000006.root.1",
"~/workdir/signal_grids/mc12_8TeV.186284.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_135_0_n1_115_0_xsl_0_95.merge.NTUP_SUSY.e2410_a220_a205_r4540_p1512_tid01374632_00/NTUP_SUSY.01374632._000007.root.1",
"~/workdir/signal_grids/mc12_8TeV.186284.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_135_0_n1_115_0_xsl_0_95.merge.NTUP_SUSY.e2410_a220_a205_r4540_p1512_tid01374632_00/NTUP_SUSY.01374632._000008.root.1",
"~/workdir/signal_grids/mc12_8TeV.186284.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_135_0_n1_115_0_xsl_0_95.merge.NTUP_SUSY.e2410_a220_a205_r4540_p1512_tid01374632_00/NTUP_SUSY.01374632._000009.root.1",
"~/workdir/signal_grids/mc12_8TeV.186284.Herwigpp_UEEE3_CTEQ6L1_wA_c1n2_135_0_n1_115_0_xsl_0_95.merge.NTUP_SUSY.e2410_a220_a205_r4540_p1512_tid01374632_00/NTUP_SUSY.01374632._000010.root.1"
            ]
#data
#file_list = [ "~/workdir/susyd3pd/data12_8TeV.00200982.physics_Egamma.merge.NTUP_SUSYSKIM.r4065_p1278_p1542_tid01274350_00/NTUP_SUSYSKIM.01274350._000001.root.1"
#]

t = ROOT.TChain('susy')
for fl in file_list:
    t.AddFile(fl)

# ==============================================================================
ewa = ROOT.PennSusyFrame.EwkAnalysis(t)
ewa.setPrintEventDetails(False)
ewa.setIsMC()
ewa.prepareTools()
ewa.Loop()

# ==============================================================================
print ''
print ''
