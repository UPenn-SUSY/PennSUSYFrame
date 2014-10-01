#!/usr/bin/env python
#===============================================================================
#= script to extract the total number of unskimmed event from a TNT file. If
#= called from the command line, this script will create a text file
#= containing the number of unskimmed events
#= usage:
#=   python GetNumberUnskimmedEvents.py <path to file>
#===============================================================================

import sys
import ROOT

#-------------------------------------------------------------------------------
def getUnskimmedEvents(in_file_name):
    f = ROOT.TFile.Open(in_file_name)
    total_num_unskimmed_events_vector = f.Get('TotalNumEvents')

    total_num_unskimmed_events = 0
    if total_num_unskimmed_events_vector:
        total_num_unskimmed_events = int(total_num_unskimmed_events_vector[0])
    else:
        print "ERROR!!! Invalid TotalNumEvents"
    f.Close()

    return total_num_unskimmed_events

#-------------------------------------------------------------------------------
def main():
    in_file_name = sys.argv[1]
    total_num_unskimmed_events = getUnskimmedEvents(in_file_name)

    out_file=file('tmp_events.txt', 'w')
    if total_num_unskimmed_events > 0:
        out_file.write('%d' % total_num_unskimmed_events)
    else:
        out_file.write('ERROR')
    out_file.close()

#===============================================================================
if __name__ == "__main__":
    main()
