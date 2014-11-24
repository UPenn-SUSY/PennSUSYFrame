#!/usr/bin/env python

import glob
import re

import ROOT
ROOT.gSystem.Load("libSusyFitter.so")

# ------------------------------------------------------------------------------
def constructPrefix(file_name):
    print file_name
    tag = re.search('(bre.*)_Output', file_name).group(1)
    prefix = '.'.join(['SampleList', tag])
    return prefix
    # splits = file_name.split('_')
    # return {'bre':int(splits[2])/100.,
    #         'brm':int(splits[4])/100.,
    #         'brt':int(splits[6])/100.}

# ------------------------------------------------------------------------------
def makeSampleListFiles(input_file_name):
    format = 'hypo_sig_%f'
    interpretation = 'mst'
    cut_str = '1'

    prefix = constructPrefix(input_file_name)

    # out_file = ROOT.CollectAndWriteHypoTestResults(input_file_name, format, interpretation, cut_str)
    out_file = ROOT.CollectAndWriteHypoTestResults(input_file_name,
                                                   format,
                                                   interpretation,
                                                   cut_str)

# ------------------------------------------------------------------------------
def main():
    input_file_list = glob.glob('results/*hypotest.root')
    print input_file_list
    # input_file_name = "results/SampleExcl_Output_hypotest.root"
    for ifl in input_file_list:
        makeSampleListFiles(ifl)
        print ''

# ==============================================================================
if __name__ == "__main__":
    main()
