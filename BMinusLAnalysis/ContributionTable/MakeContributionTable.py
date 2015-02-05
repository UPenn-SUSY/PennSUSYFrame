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
from collections import OrderedDict

# ------------------------------------------------------------------------------
def sortRegionName(region_names_list, region_dict=None):
    if region_dict is None:
        region_names_list.sort()
    else:
        region_names_list = [r for r in region_dict if r in region_names_list]

    return region_names_list

# ------------------------------------------------------------------------------
def sortSampleNames(sample_name_list):
    # TODO come up with automated sorting (not just alphabetical)
    return sample_name_list

# ------------------------------------------------------------------------------
def createTableFromRegionContributions(region_df, regions_dict=None):
    region_names = region_df['region'].unique()
    # print region_names
    region_names = sortRegionName(region_names, regions_dict)
    # print region_names

    # get sample names
    bkg_sample_names = region_df[
        -region_df['sample'].str.contains('stop')]['sample'].unique()
    sig_sample_names = region_df[
        region_df['sample'].str.contains('stop')]['sample'].unique()

    sortSampleNames(bkg_sample_names)
    sortSampleNames(sig_sample_names)

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
        title_string.append(helpers.getRegionTitle(region, regions_dict))
    title_string.append(' \\\\')
    print ''.join(title_string)

    # print individual bgk sample contributions
    print '\\midrule'
    for sample in bkg_sample_names:
        sample_cont_string = [helpers.getSampleTitle(sample)]

        sample_subset = region_df[region_df.sample == sample]
        subset_regions = sample_subset.region.unique()
        for region in region_names:
            this_value = 0
            if region in subset_regions:
                this_value = sample_subset[sample_subset.region ==
                                           region].iloc[0]['count']
            sample_cont_string.append(' & ')
            sample_cont_string.append(helpers.getNumString(this_value, 1))
            region_bkg_totals[region] += this_value
        sample_cont_string.append(' \\\\')
        print ''.join(sample_cont_string)

    # print total background contributions
    print '\\midrule'
    total_bkg_string = ['Total']
    for region in region_names:
        # if region in subset_regions:
        if region in region_names:
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

        sample_subset = region_df[region_df.sample == sample]
        subset_regions = sample_subset.region.unique()
        for region in region_names:
            this_value = 0
            if region in subset_regions:
                this_value = sample_subset[sample_subset.region == region].iloc[0]['count']
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
def cleanDataFrame(df):
    """
    Clean the data frame by removing extraneous pieces of the region names, and
    dropping the regions we don't care about
    :param df: data frame to be cleaned
    :return: cleaned data frame
    """
    df.loc[:,'region'] = df['region'].str.replace('BMINUSL_', '')
    df.loc[:,'region'] = df['region'].str.replace('_', ' ')

    df = df[~df['region'].str.contains('MINUS') &
            ~df['region'].str.contains('CRACK') &
            ~df['region'].str.contains('PAIRING') &
            ~df['region'].str.contains('OBJECTS') &
            ~df['region'].str.contains('ZVETO') &
            ~df['region'].str.contains('WEIGHTS') ]

    return df

# ------------------------------------------------------------------------------
def main(sample_name):
    region_df = helpers.extractRegionContributions(test_sample_name)

    region_df = helpers.extractRegionContributions(test_sample_name)
    region_df = cleanDataFrame(region_df)

    print '============================================================'
    print 'Original regions'
    print '============================================================'
    regions_dict = OrderedDict([('CR TOP', 'Top CR'),
                                ('CR Z', 'Z CR'),
                                ('VR TOP 1', 'Top VR 1'),
                                ('VR TOP 2', 'Top VR 2'),
                                ('VR TOP 3', 'Top VR 3'),
                                ('VR TOP 4', 'Top VR 4'),
                                ('VR Z', 'Z VR'),
                                ('SR 1', 'SR')
                                ])
    print
    print '============================================================'
    print 'v2 regions'
    print '============================================================'
    regions_dict = OrderedDict([('CR TOP v2', 'Top CR'),
                                ('CR Z v2', 'Z CR'),
                                ('VR TOP 1 v2', 'Top VR 1'),
                                ('VR TOP 2 v2', 'Top VR 2'),
                                ('VR TOP 3 v2', 'Top VR 3'),
                                ('VR TOP 4 v2', 'Top VR 4'),
                                ('VR Z v2', 'Z VR'),
                                ('SR v2 1', 'SR 200'),
                                ('SR v2 2', 'SR 400'),
                                ('SR v2 3', 'SR 800'),
                                ])
    createTableFromRegionContributions(region_df, regions_dict)

# ==============================================================================
if __name__ == '__main__':
    # get input sample name
    test_sample_name = (sys.argv[1] if len(sys.argv) > 1
            else '${BASE_WORK_DIR}/compare_plots.b_minus_l.root')
    main(test_sample_name)

