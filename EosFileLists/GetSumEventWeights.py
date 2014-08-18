#!/usr/bin/env python

import sys
import ROOT

in_file = sys.argv[1]

f = ROOT.TFile.Open(in_file)
sum_event_weights_vector = f.Get('SumMCEventWeights')
sum_event_weights = 0
if sum_event_weights_vector:
    sum_event_weights = int(sum_event_weights_vector[0])
else:
    print "ERROR!!! invalid SumMCEventWeights"

out_file=file('tmp_weights.txt', 'w')
if sum_event_weights > 0:
    out_file.write('%d' % sum_event_weights)
else:
    out_file.write('error')
out_file.close()
f.Close()
