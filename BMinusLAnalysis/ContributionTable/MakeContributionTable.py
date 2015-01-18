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

import sys
import ContributionsHelpers as helpers


# ------------------------------------------------------------------------------
def createTableFromRegionContributions(region_df):
    # get region names
    region_names = region_df['Region'][ -region_df['Region'].str.contains('_MINUS_')
                                      & ( region_df['Region'].str.contains('_CR_')
                                        | region_df['Region'].str.contains('_VR_')
                                        | region_df['Region'].str.contains('_SR')
                                        )
                                      # remove VR 1 for now
                                      & ~region_df['Region'].str.contains('_VR_1')
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
    title_string = []
    for region in region_names:
        title_string.append(' & ')
        title_string.append(helpers.getRegionTitle(region))
    title_string.append(' \\\\')
    print ''.join(title_string)

    # print individual bgk sample contributions
    print '\\midrule'
    for sample in bkg_sample_names:
        sample_cont_string = [helpers.getSampleTitle(sample)]

        sample_subset = region_df[region_df.Sample == sample]
        subset_regions = sample_subset.Region.unique()
        for region in region_names:
            this_value = 0
            if region in subset_regions:
                this_value = sample_subset[sample_subset.Region ==
                                           region].iloc[0]['Count']
            sample_cont_string.append(' & ')
            sample_cont_string.append(helpers.getNumString(this_value, 1))
            region_bkg_totals[region] += this_value
        sample_cont_string.append(' \\\\')
        print ''.join(sample_cont_string)

    # print total background contributions
    print '\\midrule'
    total_bkg_string = ['Total']
    for region in region_names:
        if region in subset_regions:
            total_bkg_string.append(' & ')
            total_bkg_string.append('\multirow{2}{*}{')
            total_bkg_string.append(helpers.getNumString(region_bkg_totals[region], 1))
            total_bkg_string.append('}')
    total_bkg_string.append(' \\\\')
    print ''.join(total_bkg_string)
    print 'background \\\\'

    # print signal contributions
    print '\\midrule'
    for sample in sig_sample_names:
        signal_cont_string = ['\multirow{2}{*}{', sample, '}']
        signal_rel_cont_string = ['']

        sample_subset = region_df[region_df.Sample == sample]
        subset_regions = sample_subset.Region.unique()
        for region in region_names:
            this_value = 0
            if region in subset_regions:
                this_value = sample_subset[sample_subset.Region == region].iloc[0]['Count']
            signal_cont_string.append(' & ')
            signal_rel_cont_string.append(' & ')

            signal_cont_string.append(helpers.getNumString(this_value, 1))

            signal_rel_cont_string.append(' (')
            signal_rel_cont_string.append(helpers.getNumString((
                this_value/region_bkg_totals[region]), 1))
            signal_rel_cont_string.append(')')

        signal_cont_string.append(' \\\\')
        signal_rel_cont_string.append(' \\vspace{1ex} \\\\')

        print ''.join(signal_cont_string)
        print ''.join(signal_rel_cont_string)

    print '\\bottomrule'

    print '\\end{tabular}'
    print '}'
    print '\\caption{TODO add caption here!}'
    print '\\label{tab:XXX}'
    print '\\end{table}'


# ------------------------------------------------------------------------------
def main(sample_name):
    region_df = helpers.extractRegionContributions(test_sample_name)
    createTableFromRegionContributions(region_df)

# ==============================================================================
if __name__ == '__main__':
    # get input sample name
    test_sample_name = sys.argv[1] if len(sys.argv) > 1 else '${BASE_WORK_DIR}/compare_plots.b_minus_l.root'
    main(test_sample_name)

