#!/usr/bin/env python

import glob
import re
import sys

import ROOT
ROOT.gSystem.Load("libSusyFitter.so")

# ------------------------------------------------------------------------------
def constructPrefix(file_name):
    print file_name
    tag = re.search('(bre.*)_Output', file_name).group(1)
    prefix = '.'.join(['SampleList', tag])
    return prefix

# ------------------------------------------------------------------------------
def makeSampleListFiles(input_file_name):
    format = 'hypo_sig_%f'
    interpretation = 'mst'
    cut_str = '1'

    prefix = constructPrefix(input_file_name)
    print 'prefix: ', prefix

    out_file = ROOT.CollectAndWriteHypoTestResults(input_file_name,
                                                   format,
                                                   interpretation,
                                                   cut_str)

# ------------------------------------------------------------------------------
def main():
    if len(sys.argv) > 1:
        variation = sys.argv[1]
    else:
        variation = 'Nominal'

    input_file_list = glob.glob(
            'results/excl/*fixSigXSec%s*hypotest.root' % variation)
    # input_file_list = glob.glob('results/excl/*fixSigXSecNominal*hypotest.root')
    # input_file_list = glob.glob('results/excl/*fixSigXSecDown*hypotest.root')
    # input_file_list = glob.glob('results/excl/*fixSigXSecUp*hypotest.root')
    for ifl in input_file_list:
        print '-'*80
        print 'Making sample list files for ', ifl
        makeSampleListFiles(ifl)
        print ''

# ==============================================================================
if __name__ == "__main__":
    main()
