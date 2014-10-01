#!/usr/bin/env python
#===============================================================================
#= script to extract the sum of event weightse from a TNT file. If called from
#= the command line, this script will create a text file containing the sum of
#= event weights
#= usage:
#=   python GetSumEventWeights.py <path to file>
#===============================================================================

import sys
import ROOT

#-------------------------------------------------------------------------------
def getSumEventWeights(in_file_name):
    f = ROOT.TFile.Open(in_file_name)
    sum_event_weights_vector = f.Get('SumMCEventWeights')

    sum_event_weights = 0
    if sum_event_weights_vector:
        sum_event_weights = int(sum_event_weights_vector[0])
    else:
        print "ERROR!!! Invalid SumMCEventWeights"
    f.Close()

    return sum_event_weights

#-------------------------------------------------------------------------------
def main():
    in_file_name = sys.argv[1]
    sum_event_weights = getSumEventWeights(in_file_name)

    out_file=file('tmp_weights.txt', 'w')
    if sum_event_weights > 0:
        out_file.write('%d' % sum_event_weights)
    else:
        out_file.write('ERROR')
    out_file.close()

#===============================================================================
if __name__ == "__main__":
    main()
