#!/usr/bin/env python

import sys
import os.path
import argparse
import time

import ROOT
import rootlogon
import metaroot

parser = argparse.ArgumentParser(description='get fraction of events with crack electrons')
parser.add_argument('--file', dest = 'in_file', action = 'store', default = 'file')
parser.add_argument('--tree', dest = 'in_tree', action = 'store', default = 'tree')
args = vars(parser.parse_args())
print 'file: %s' % args['in_file']
print 'tree: %s' % args['in_tree']

f = ROOT.TFile.Open(args['in_file'])
t = f.Get(args['in_tree'])

print 'tree: %s' % t
f_in_crack = ROOT.TFile('tmp.root', 'RECREATE')
t_in_crack = t.CopyTree('(el_eta>1.37) && (el_eta<1.52)')

total_num_events = t.GetEntries()
crack_num_events = t_in_crack.GetEntries()

print 'Total number events: %d' % total_num_events
print 'Crack number events: %d' % crack_num_events
print 'Fraction of events with crack electron: %s' % (float(crack_num_events)/total_num_events)
