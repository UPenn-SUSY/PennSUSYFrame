#!/usr/bin/env python

import sys
import os.path
import argparse
import time

import ROOT
# import rootlogon
import metaroot

# ------------------------------------------------------------------------------
def getFileFromInputs():
    parser = argparse.ArgumentParser(description='DESCRIPTION')
    parser.add_argument('--file', dest = 'in_file', action = 'store', default = 'file')
    args = vars(parser.parse_args())
    if not os.path.isfile(args['in_file']):
        return None
    f = ROOT.TFile.Open(args['in_file'])
    return f

# ------------------------------------------------------------------------------
def help():
    print 'usage:'
    print '  ./GetNumRawEvents.py --file <PATH_TO_PTNT_FILE>'

# ------------------------------------------------------------------------------
def getListOfTrees(in_file):
    list_of_trees = {}
    for element in in_file.GetListOfKeys():
        name = element.GetName()
        if name == 'num_events': continue
        list_of_trees[name] = in_file.Get(name)
    return list_of_trees

# ------------------------------------------------------------------------------
def findNumberEvents(list_of_trees):
    for lot in list_of_trees:
        print 'selection: %s --- num events: %s' % (lot, list_of_trees[lot].GetEntries())

# ------------------------------------------------------------------------------
def main():
    in_file = getFileFromInputs()
    if in_file == None:
        help()
        return

    list_of_trees = getListOfTrees(in_file)
    print 'Total number events in dataset: %s' % in_file.Get('num_events').Integral()
    findNumberEvents(list_of_trees)

# ==============================================================================
if __name__ == '__main__':
    main()