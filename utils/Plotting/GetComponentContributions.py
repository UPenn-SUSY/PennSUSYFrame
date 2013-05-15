#!/usr/bin/env python

import sys
import os.path
import optparse
import time

import ROOT
import rootlogon
import metaroot


f = ROOT.TFile('compare.mm_ss.loose_selection.root')

selections = [ 'mm_sr_ss__sample7.SS_loose.metrel_40.mu_pt_15'
             , 'mm_sr_ss__sample8.SS_loose.metrel_40.num_light_jet_ge_1.mu_pt_15'
             , 'mm_sr_ss__sample9.SS_loose.metrel_40.num_light_jet_eq_1.mu_pt_15'
             , 'mm_sr_ss__sample10.SS_loose.metrel_40.num_light_jet_eq_0.mu_pt_15'
             , 'mm_sr_ss__sample11.SS_loose.metrel_30.mu_pt_15'
             , 'mm_sr_ss__sample12.SS_loose.metrel_30.num_light_jet_ge_1.mu_pt_15'
             , 'mm_sr_ss__sample13.SS_loose.metrel_30.num_light_jet_eq_1.mu_pt_15'
             , 'mm_sr_ss__sample14.SS_loose.metrel_30.num_light_jet_eq_0.mu_pt_15'
             , 'mm_sr_ss__sample15.SS_loose.metrel_20.mu_pt_15'
             , 'mm_sr_ss__sample16.SS_loose.metrel_20.num_light_jet_ge_1.mu_pt_15'
             , 'mm_sr_ss__sample17.SS_loose.metrel_20.num_light_jet_eq_1.mu_pt_15'
             , 'mm_sr_ss__sample18.SS_loose.metrel_20.num_light_jet_eq_0.mu_pt_15'
             ]

# print '--------------------------------------------------------------------------------'
bar = '-'*235
print bar
printed_header = False
for s in selections:
    table_entry = '| %70s ' % s
    # print 'Selection: %s' % s
    selection_dir = f.Get(s)

    canvas = selection_dir.Get('__entries')
    if not printed_header:
        header_line = '| %70s ' % 'Selection'
        for i, lop in enumerate(canvas.GetListOfPrimitives()):
            bin_label = lop.GetXaxis().GetBinLabel(i+1)
            if '=' in bin_label: bin_label = bin_label.split('=')[1].lstrip()
            header_line += '| %20s ' % bin_label
            # header_line += '| %10s ' % lop.GetXaxis().GetBinLabel(i+1)
        header_line += '|'
        print header_line
        print bar
        printed_header = True

    for i, lop in enumerate(canvas.GetListOfPrimitives()):
        table_entry += '| %20f ' % lop.GetBinContent(i+1)
    table_entry += '|'
    print table_entry
print bar

# print '--------------------------------------------------------------------------------'
