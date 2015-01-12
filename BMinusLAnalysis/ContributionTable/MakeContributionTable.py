#!/usr/bin/env python
"""
This script is used to generate a latex table showing the contribution of each
process in each region. This script runs on a root file containing canvases
created using the Plotting package. Specifically, it takes advantage of the
__entries canvas which show the number of expected entries in each region.

usage:
    python scripts/ContributionTable/MakeContributionTable.py compare_plots.b_minus_l.root

Note: This package requires pandas be installed! I have not gotten this working
on lxplus, but haven't really tried very hard. I simply copy the root file to my
laptop and run from there.
"""

import ROOT
import pandas
import sys

# ------------------------------------------------------------------------------
def extractRegionContributions(sample_file_name):
    print 'extracting region contributions from file: ', sample_file_name
    # get region list from this sample file
    sample_file = ROOT.TFile.Open(sample_file_name)
    region_list = [k.GetName() for k in sample_file.GetListOfKeys()]

    # construct region contributions data frame
    cont_df = pandas.DataFrame(columns = ('Region', 'Sample', 'Count'))

    # for each region in the list, extract the number of expected events
    for rl in region_list:
        this_tree = sample_file.Get(rl)
        this_entries_canv = this_tree.Get('__entries')

        # one primitive histogram for each process
        primitives = this_entries_canv.GetListOfPrimitives()
        for p in primitives:
            # loop over each bin to find the non-empty one
            num_bins = p.GetNbinsX()
            for bin_it in xrange(1,num_bins+1):
                bin_label = p.GetXaxis().GetBinLabel(bin_it)
                if 'Data' in bin_label: continue
                bin_content = p.GetBinContent(bin_it)

                # add non-empty bin to data frame
                if not bin_content == 0:
                    this_df_entry = [rl, bin_label, bin_content]
                    cont_df.loc[cont_df.shape[0]] = this_df_entry
    return cont_df

# ------------------------------------------------------------------------------
def createTableFromRegionContributions(region_df):
    # get region names
    region_names = region_df['Region'][ -region_df['Region'].str.contains('_MINUS_')
                                      & ( region_df['Region'].str.contains('_CR_')
                                        | region_df['Region'].str.contains('_VR_')
                                        | region_df['Region'].str.contains('_SR')
                                        )
                                      ].unique()

    # get sample names
    bkg_sample_names = region_df['Sample'][-region_df['Sample'].str.contains('stop')].unique()
    sig_sample_names = region_df['Sample'][region_df['Sample'].str.contains('stop')].unique()

    bkg_sample_names.sort()
    sig_sample_names.sort()

    # create sums of background contributions
    region_bkg_totals = {rn:0 for rn in region_names}

    # print latex table header
    print '\\begin{table}'
    print '\\centering{'
    print '\\begin{tabular}{c|%s}' % ('c'*len(region_names))


    # print title line
    print '\\toprule'
    title_string = ''
    for region in region_names:
        this_region_string = region.replace('BMINUSL_', '')
        this_region_string = this_region_string.replace('_', ' ')
        title_string += ' & %s' % this_region_string
    title_string += ' \\\\'
    print title_string

    # print individual bgk sample contributions
    print '\\midrule'
    for sample in bkg_sample_names:
        sample_cont_string = sample

        sample_subset = region_df[region_df.Sample == sample]
        subset_regions = sample_subset.Region.unique()
        for region in region_names:
            this_value = 0
            if region in subset_regions:
                this_value = sample_subset[sample_subset.Region == region].iloc[0]['Count']
            sample_cont_string += ' & %.1f' % this_value
            region_bkg_totals[region] += this_value
        sample_cont_string += ' \\\\'
        print sample_cont_string

    # print total background contributions
    print '\\midrule'
    total_bkg_string = 'Total'
    for region in region_names:
        if region in subset_regions:
            total_bkg_string += ' & \multirow{2}{*}{%.1f}' % region_bkg_totals[region]
    total_bkg_string += ' \\\\'
    print total_bkg_string
    print 'background \\\\'

    # print signal contributions
    print '\\midrule'
    for sample in sig_sample_names:
        sample_cont_string = sample

        sample_subset = region_df[region_df.Sample == sample]
        subset_regions = sample_subset.Region.unique()
        for region in region_names:
            this_value = 0
            if region in subset_regions:
                this_value = sample_subset.Count[sample_subset.Region == region]
            sample_cont_string += ' & %.1f (%.1f)' % (this_value, (this_value/region_bkg_totals[region]))
        sample_cont_string += ' \\\\'
        print sample_cont_string
    print '\\bottomrule'

    print '\\end{tabular}'
    print '}'
    print '\\caption{TODO add caption here!}'
    print '\\label{tab:XXX}'
    print '\\end{table}'


# ------------------------------------------------------------------------------
def main(sample_name):
    region_df = extractRegionContributions(test_sample_name)
    createTableFromRegionContributions(region_df)

# ==============================================================================
if __name__ == '__main__':
    # get input sample name
    test_sample_name = sys.argv[1] if len(sys.argv) > 1 else '${BASE_WORK_DIR}/compare_plots.b_minus_l.root'
    main(test_sample_name)

