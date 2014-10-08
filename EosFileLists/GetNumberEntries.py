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
def getTotalNumEntries(in_file_name, tree_name = 'TNT'):
    f = ROOT.TFile.Open(in_file_name)
    t = f.Get(tree_name)

    total_num_entries = None
    if t:
        total_num_entries = t.GetEntries()
    else:
        print "ERROR!!! Invalid TTree"
    f.Close()

    return total_num_entries

#-------------------------------------------------------------------------------
def main():
    in_file_name = sys.argv[1]
    tree_name = 'TNT'
    if len(sys.argv) > 2:
        tree_name = sys.argv[2]

    total_num_entries = getTotalNumEntries(in_file_name, tree_name)

    out_file=file('tmp_entries.txt', 'w')
    if total_num_entries is not None:
        out_file.write('%d' % total_num_entries)
    else:
        out_file.write('ERROR')
    out_file.close()

#===============================================================================
if __name__ == "__main__":
    main()
