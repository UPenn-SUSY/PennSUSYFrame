#!/usr/bin/env python
#===============================================================================
#= script to extract the total number of entries from a TNT file. If called from
#= the command line, this script will create a text file containing the number
#= of entries
#= usage:
#=   python GetNumberEntries.py <path to file>
#===============================================================================

import sys
import ROOT

#-------------------------------------------------------------------------------
def getTotalNumEntriesFromFile(f, tree_name = 'TNT'):
    t = f.Get(tree_name)

    total_num_entries = None
    if t:
        total_num_entries = t.GetEntries()
    else:
        print "ERROR!!! Invalid TTree"

    return total_num_entries

#-------------------------------------------------------------------------------
def getUnskimmedEventsFromFile(f):
    total_num_unskimmed_events_vector = f.Get('TotalNumEvents')

    total_num_unskimmed_events = None
    if total_num_unskimmed_events_vector:
        total_num_unskimmed_events = int(total_num_unskimmed_events_vector[0])
    else:
        print "ERROR!!! Invalid TotalNumEvents"

    return total_num_unskimmed_events

#-------------------------------------------------------------------------------
def getSumEventWeightsFromFile(f):
    sum_event_weights_vector = f.Get('SumMCEventWeights')

    sum_event_weights = None
    if sum_event_weights_vector:
        sum_event_weights = int(sum_event_weights_vector[0])
    else:
        print "ERROR!!! Invalid SumMCEventWeights"

    return sum_event_weights

#-------------------------------------------------------------------------------
def getTotalNumEntries(in_file_name, tree_name = 'TNT'):
    f = ROOT.TFile.Open(in_file_name)
    total_num_entries = getTotalNumEntriesFromFile(f, tree_name)
    f.Close()
    return total_num_entries

#-------------------------------------------------------------------------------
def getUnskimmedEvents(in_file_name):
    f = ROOT.TFile.Open(in_file_name)
    total_num_unskimmed_events = getUnskimmedEventsFromFile(f)
    f.Close()
    return total_num_unskimmed_events

#-------------------------------------------------------------------------------
def getSumEventWeights(in_file_name):
    f = ROOT.TFile.Open(in_file_name)
    sum_event_weights = getSumEventWeightsFromFile(f)
    f.Close()
    return sum_event_weights

#-------------------------------------------------------------------------------
def main():
    # get file name and open root file
    in_file_name = sys.argv[1]
    tree_name = 'TNT'
    if len(sys.argv) > 2:
        tree_name = sys.argv[2]

    f = ROOT.TFile.Open(in_file_name)

    # get numbers from file
    total_num_entries          = getTotalNumEntriesFromFile(f, tree_name)
    total_num_unskimmed_events = getUnskimmedEventsFromFile(f)
    sum_event_weights          = getSumEventWeightsFromFile(f)

    # write num entries to tmp file
    entries_out_file = file('tmp_entries.txt', 'w')
    if total_num_entries is not None:
        entries_out_file.write('%d' % total_num_entries)
    else:
        entries_out_file.write('ERROR')
    entries_out_file.close()

    # write number unskimmed events to tmp file
    events_out_file = file('tmp_events.txt', 'w')
    if total_num_unskimmed_events is not None:
        events_out_file.write('%d' % total_num_unskimmed_events)
    else:
        events_out_file.write('ERROR')
    events_out_file.close()

    # write sum of event weights to tmp file
    weights_out_file=file('tmp_weights.txt', 'w')
    if sum_event_weights is not None:
        weights_out_file.write('%d' % sum_event_weights)
    else:
        weights_out_file.write('ERROR')

    # close root file
    f.Close()

#===============================================================================
if __name__ == "__main__":
    main()

