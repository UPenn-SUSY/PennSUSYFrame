#!/usr/bin/env python

import os
import ROOT

# ------------------------------------------------------------------------------
def getListOfFilesOnEos(input_eos_file):
    in_file = file(input_eos_file)

    list_of_input_files = []

    for line in in_file:
        splits = line.split()
        print splits
        list_of_input_files.append({'file_name':splits[0], 'num_gen':int(splits[1]), 'num_entries':int(splits[2])})
    return list_of_input_files

# ------------------------------------------------------------------------------
def computeSumOfWeights(list_of_input_files):
    sum_of_event_weights = 0.
    for loif in list_of_input_files:
        print loif
        print 'file_name: ' , loif['file_name']
        print 'num_entries: ' , loif['num_entries']
        print 'num_gen: ' , loif['num_gen']
        this_sum_of_event_weights = computeSumOfWeightsSingleFile(loif['file_name'])
        sum_of_event_weights += this_sum_of_event_weights

        skim_ratio = float(loif['num_entries'])/loif['num_gen']
        print 'skim_ratio: ' , skim_ratio
        estimated_sum_of_event_weights = this_sum_of_event_weights/skim_ratio
        print 'this_sum_of_event_weights: ' , this_sum_of_event_weights , ' -- estimated_sum_of_event_weights: ' , estimated_sum_of_event_weights

        loif['sum_of_weights'] = estimated_sum_of_event_weights
    return  list_of_input_files

# ------------------------------------------------------------------------------
def computeSumOfWeightsSingleFile(file_name, tree_name = 'TNT'):
    # return 1629.60002401

    sum_of_event_weights = 0.
    found_non_unity_weight = False

    in_file = ROOT.TFile.Open(file_name)
    in_tree = in_file.Get(tree_name)
    for i, event in enumerate(in_tree):
        # check if event weight == 1
        if event.mc_event_weight != 1.:
            found_non_unity_weight = True

        # if we have not seen a non-unity event weight in 100 events, assume
        # they are all unity, and get out!
        if i == 100 and not found_non_unity_weight:
            print 'found only unity weights in first 100 event -- bailing now!'
            sum_of_event_weights = in_tree.GetEntries()
            break

        sum_of_event_weights += event.mc_event_weight
    return sum_of_event_weights

# ------------------------------------------------------------------------------
def writeNewEosFile(list_of_input_files, out_file_name):
    f = file(out_file_name, 'w')

    for loif in list_of_input_files:
        f.write('%s    %s    %s    %s\n' % (loif['file_name'], loif['num_gen'], loif['num_entries'], loif['sum_of_weights']))

    f.close()

# ------------------------------------------------------------------------------
def main():
    input_eos_file = os.sys.argv[1]
    output_eos_file = os.sys.argv[2]
    print 'getting sum of event weights for samples in ' , input_eos_file

    list_of_input_files = getListOfFilesOnEos(input_eos_file)
    computeSumOfWeights(list_of_input_files)
    print list_of_input_files
    writeNewEosFile(list_of_input_files, output_eos_file)

# ==============================================================================
if __name__ == '__main__':
    main()
