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

import ContributionsHelpers as helpers
from collections import OrderedDict
import argparse
import pickle


# ------------------------------------------------------------------------------
def write_single_table_line(df, systematic, sample_list, write_total):
    # first subset the DF to include only the systematic of interest and the
    # nominal runs
    subset = df[df['systematic'].isin([systematic, 'NoSys'])]

    # Start creating the table line with the systematic name
    table_line = [systematic.replace('_', '\_').lower()]

    # counters for totals
    total = 0.
    nominal_total = 0.

    # step through the samples in the sample list
    for sample in sample_list:
        count = subset[(subset['systematic'] == systematic) &
                       (subset['sample'] == sample)].iloc[0]['count']
        nominal_count = subset[(subset['systematic'] == 'NoSys') &
                               (subset['sample'] == sample)].iloc[0]['count']
        total += count
        nominal_total += nominal_count

        if systematic == 'NoSys':
            table_line.append(helpers.getNumString(count, 2))
        else:
            count = (count - nominal_count)
            table_line.append(helpers.getNumString(count, 2, force_sign=True))

    if write_total:
        if systematic == 'NoSys':
            table_line.append(helpers.getNumString(total, 2))
        else:
            total = (total - nominal_total)
            table_line.append(helpers.getNumString(total, 2, force_sign=True))

    print ' & '.join(table_line)
    print '\\\\'

# ------------------------------------------------------------------------------
def create_systematic_table(region_df, is_signal=False):
    # extract the samples names from the signal and background data frames
    sample_names = region_df['sample'].unique()
    if is_signal:
        sample_names = helpers.sortSampleNames(sample_names)

    systematic_names = region_df['systematic'].unique()
    systematic_names = helpers.sortSystematicNames(systematic_names)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # print latex table header
    print '\\begin{table}[h]'
    print '\\centering{'
    if is_signal:
        print '\\begin{tabular}{c|%s}' % ('c'*len(sample_names))
    else:
        print '\\begin{tabular}{c|%s|c}' % ('c'*len(sample_names))
    print '\\toprule'

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # print header line
    header_line = ['Systematic']
    header_line.extend([helpers.getSampleTitle(sn) for sn in sample_names])
    if not is_signal:
        header_line.extend(['Bkg total'])
    print ' & '.join(header_line)
    print '\\\\'
    print '\\midrule'

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # print body of table
    for systematic in systematic_names:
        write_single_table_line(df=region_df, systematic=systematic,
                                sample_list=sample_names,
                                write_total=not is_signal)
        if systematic == 'NoSys':
            print '\\midrule'

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # print end of table
    print '\\bottomrule'
    print '\\end{tabular}'
    print '}'
    print '\\end{table}'
    print '\n'*2

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # float barrier to make pdf pretty :-)
    print '\\FloatBarrier'
    print '\\pagebreak'
    print
    print

# ------------------------------------------------------------------------------
def main(bkg_name, sig_name, read_from_pickle=False):
    print "bkg name: ", bkg_name
    print "sig name: ", sig_name

    if read_from_pickle:
        with open('bkg_df.pickle', 'rb') as bkg_handle:
            bkg_region_df = pickle.load(bkg_handle)
        with open('sig_df.pickle', 'rb') as sig_handle:
            sig_region_df = pickle.load(sig_handle)
    else:
        # extract data frames for each region/sample
        bkg_region_df = helpers.extractRegionContributionsSystematicTree(bkg_name)
        sig_region_df = helpers.extractRegionContributionsSystematicTree(sig_name)

        with open('bkg_df.pickle', 'wb') as bkg_handle:
            pickle.dump(bkg_region_df, bkg_handle)
        with open('sig_df.pickle', 'wb') as sig_handle:
            pickle.dump(sig_region_df, sig_handle)

    sample_drop_list = ['_'.join(['sig', str(drop_mass)]) for drop_mass
                        in range(100, 401, 100)]
    sample_drop_list.append('data')
    sample_drop_list.extend(['sig_600', 'sig_700'])

    systematic_drop_list = ['JES_UP', 'JES_DOWN']

    bkg_region_df = bkg_region_df[
        ~bkg_region_df['sample'].isin(sample_drop_list)]
    sig_region_df = sig_region_df[
        ~sig_region_df['sample'].isin(sample_drop_list)]

    bkg_region_df = bkg_region_df[
        ~bkg_region_df['systematic'].isin(systematic_drop_list)]
    sig_region_df = sig_region_df[
        ~sig_region_df['systematic'].isin(systematic_drop_list)]

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    regions_dict = OrderedDict([('CR Top', 'Top CR'),
                                ('CR Z', 'Z CR'),
                                ('VR Top 1', 'Top VR 1'),
                                ('VR Top 2', 'Top VR 2'),
                                ('VR Top 3', 'Top VR 3'),
                                ('VR Z', 'Z VR'),
                                ('SR 400', 'SR 400'),
                                ('SR 600', 'SR 600')])

    for region_key, region_name in regions_dict.items():
        print '\\section{', region_name, '}'
        this_bkg_region_df = bkg_region_df[
            bkg_region_df['region'] == region_key]
        this_sig_region_df = sig_region_df[
            sig_region_df['region'] == region_key]

        create_systematic_table(region_df=this_bkg_region_df, is_signal=False)
        if 'SR' in region_key:
            create_systematic_table(region_df=this_sig_region_df,
                                    is_signal=True)

# ==============================================================================
if __name__ == '__main__':
    # get input sample name
    parser = argparse.ArgumentParser()
    parser.add_argument('--bkg', action='store', type=str)
    parser.add_argument('--sig', action='store', type=str)

    args = parser.parse_args()

    main(args.bkg, args.sig, read_from_pickle=True)

