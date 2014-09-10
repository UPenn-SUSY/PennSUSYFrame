#!/usr/bin/env python

import ROOT
ROOT.gSystem.Load("libSusyFitter.so")

# ------------------------------------------------------------------------------
def makeSampleListFiles(input_file_name):
    format = 'hypo_sig_%f'
    interpretation = 'mst'
    cut_str = '1'

    out_file = ROOT.CollectAndWriteHypoTestResults( input_file_name
                                                  , format
                                                  , interpretation
                                                  , cut_str
                                                  )

# ------------------------------------------------------------------------------
def main():
    input_file_name = "results/SampleExcl_Output_hypotest.root"
    makeSampleListFiles(input_file_name)

# ==============================================================================
if __name__ == "__main__":
    main()
