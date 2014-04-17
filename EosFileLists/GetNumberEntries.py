#!/usr/bin/env python

import sys
import ROOT

in_file = sys.argv[1]

f = ROOT.TFile.Open(in_file)
t = f.Get('TNT')
total_num_entries = t.GetEntries()
f.Close()

out_file=file('tmp_entries.txt', 'w')
out_file.write('%d' % total_num_entries)
out_file.close()

print total_num_entries
# return total_num_entries
