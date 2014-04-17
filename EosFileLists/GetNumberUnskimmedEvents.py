#!/usr/bin/env python

import sys
import ROOT

in_file = sys.argv[1]

f = ROOT.TFile.Open(in_file)
total_num_unskimmed_events = int(f.Get('TotalNumEvents')[0])

out_file=file('tmp_events.txt', 'w')
out_file.write('%d' % total_num_unskimmed_events)
out_file.close()
f.Close()

print total_num_unskimmed_events
# return total_num_unskimmed_events
