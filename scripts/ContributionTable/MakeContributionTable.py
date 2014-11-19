#!/usr/bin/env python

import ROOT

# ------------------------------------------------------------------------------
def extractRegionContributions(sample_file_name):
    # get region list from this sample file
    sample_file = ROOT.TFile.Open(sample_file_name)
    region_list = [k.GetName() for k in sample_file.GetListOfKeys()]

    # for each region in the list, extract the number of expected events
    for rl in region_list:
        print '- ', rl

        this_tree = sample_file.Get(rl)
        this_entries_canv = this_tree.Get('__entries')

        primitives = this_entries_canv.GetListOfPrimitives()
        for p in primitives:
            print '  - primitive name: ', p.GetName()
            print '    - num entries: ', p.GetEntries()
            print '    - num integral: ', p.Integral()
            print '    - num num bins: ', p.GetNbinsX()
            num_bins = p.GetNbinsX()
            for bin_it in xrange(1,num_bins+1):
                print '      bin ', bin_it, ': ', p.GetXaxis().GetBinLabel(bin_it)

        # num_bins = this_entries_hist.GetNbins()
        # print '  - num bins: ', num_bins

        print ''

# ==============================================================================
if __name__ == '__main__':
    # test_sample_name = '../../NextPlotDir.BMinusL/BMinusL.202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000.hists.root'
    test_sample_name = '${BASE_WORK_DIR}/compare_plots.b_minus_l.root'
    extractRegionContributions(test_sample_name)
