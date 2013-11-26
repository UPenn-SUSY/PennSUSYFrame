#!/usr/bin/env python

import ROOT
import rootlogon
import metaroot

file_names = [ '../../small_fake_test/SusyDiLeptonCutFlowCycle.mc.ver_1.cut_flow.117650.ZeeNp0.2013_11_19.root'
             , '../../small_fake_test/SusyDiLeptonCutFlowCycle.mc.ver_1.cut_flow.117651.ZeeNp1.2013_11_19.root'
             , '../../small_fake_test/SusyDiLeptonCutFlowCycle.mc.ver_1.cut_flow.117652.ZeeNp2.2013_11_19.root'
             , '../../small_fake_test/SusyDiLeptonCutFlowCycle.mc.ver_1.cut_flow.117653.ZeeNp3.2013_11_19.root'
             , '../../small_fake_test/SusyDiLeptonCutFlowCycle.mc.ver_1.cut_flow.117654.ZeeNp4.2013_11_19.root'
             , '../../small_fake_test/SusyDiLeptonCutFlowCycle.mc.ver_1.cut_flow.117655.ZeeNp5.2013_11_19.root'
             , '../../small_fake_test/SusyDiLeptonCutFlowCycle.mc.ver_1.cut_flow.117660.ZmumuNp0.2013_11_19.root'
             , '../../small_fake_test/SusyDiLeptonCutFlowCycle.mc.ver_1.cut_flow.117661.ZmumuNp1.2013_11_19.root'
             , '../../small_fake_test/SusyDiLeptonCutFlowCycle.mc.ver_1.cut_flow.117662.ZmumuNp2.2013_11_19.root'
             , '../../small_fake_test/SusyDiLeptonCutFlowCycle.mc.ver_1.cut_flow.117663.ZmumuNp3.2013_11_19.root'
             , '../../small_fake_test/SusyDiLeptonCutFlowCycle.mc.ver_1.cut_flow.117664.ZmumuNp4.2013_11_19.root'
             , '../../small_fake_test/SusyDiLeptonCutFlowCycle.mc.ver_1.cut_flow.117665.ZmumuNp5.2013_11_19.root'
             ]

for fn in file_names:
    f = ROOT.TFile(fn)
    print '------------------------------------------------------------'
    print 'file: %s' % fn
    print 'num events: %s' % f.Get('N_all_events').GetVal()

