#!/usr/bin/env python

import sys
import ROOT

in_file = sys.argv[1]

f = ROOT.TFile.Open(in_file)
total_num_unskimmed_events_vector = f.Get('TotalNumEvents')
# total_num_unskimmed_events = int(f.Get('TotalNumEvents')[0])
total_num_unskimmed = 0
if total_num_unskimmed_events_vector:
    total_num_unskimmed_events = int(total_num_unskimmed_events_vector[0])
else:
    print "ERROR!!! invalid TotalNumEvents"

out_file=file('tmp_events.txt', 'w')
if total_num_unskimmed_events > 0:
    out_file.write('%d' % total_num_unskimmed_events)
else:
    out_file.write('error')
out_file.close()
f.Close()

# print total_num_unskimmed_events
# return total_num_unskimmed_events
