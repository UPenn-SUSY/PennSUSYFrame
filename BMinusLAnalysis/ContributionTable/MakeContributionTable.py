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
import math
import re

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

# ______________________________________________________________________________
def getNumString(number, num_digits):
    """
    Function to take a number and number of digits to display after
    the decimal, and convert to a string of the correct length. If
    the number is too small, return a string in scientific notation
    """
    if number == 0:
        return '0'

    cutoff = 10**(-num_digits)
    if number >= cutoff:
        return ''.join(['{:.', str(num_digits), 'f}']).format(number)
    # do scientific notation
    sci_number = ''.join(['{:.', str(num_digits), 'E}']).format(number)

    # replace E notation with \cdot 10^... notation
    sci_number = re.sub(r'E0+', 'E', sci_number)
    sci_number = re.sub(r'E-0+', 'E-', sci_number)

    # replace E notation with \cdot 10^... notation
    sci_number = re.sub(r'E(.*)', r' \\cdot 10^{\1}', sci_number)

    # add $'s around the number
    sci_number = ''.join(['$', sci_number, '$'])

    return sci_number

# ------------------------------------------------------------------------------
def createTableFromRegionContributions(region_df):
    # get region names
    region_names = region_df['Region'][ -region_df['Region'].str.contains('_MINUS_')
                                      & ( region_df['Region'].str.contains('_CR_')
                                        | region_df['Region'].str.contains('_VR_')
                                        | region_df['Region'].str.contains('_SR')
                                        )
                                      # remobe VR 1 for now
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
    title_string = ''
    for region in region_names:
        this_region_string = region.replace('BMINUSL_', '')
        this_region_string = this_region_string.replace('_', ' ')
        if this_region_string == 'CR TOP':
            this_region_string = 'Top CR'
        if this_region_string == 'CR Z':
            this_region_string = 'Z CR'
        if this_region_string == 'VR 3':
            this_region_string = 'Top VR'
        if this_region_string == 'VR 5':
            this_region_string = 'Z VR'
        title_string += ' & %s' % this_region_string
    title_string += ' \\\\'
    print title_string

    # print individual bgk sample contributions
    print '\\midrule'
    for sample in bkg_sample_names:
        this_sample = sample
        if this_sample == 'Z/#gamma^{*}':
            this_sample = '$Z/\\gamma^{*}$'
        if this_sample == 'ttbar':
            this_sample = '$t\\bar{t}$'

        sample_cont_string = [this_sample]

        sample_subset = region_df[region_df.Sample == sample]
        subset_regions = sample_subset.Region.unique()
        for region in region_names:
            this_value = 0
            if region in subset_regions:
                this_value = sample_subset[sample_subset.Region ==
                                           region].iloc[0]['Count']
            sample_cont_string.append(' & ')
            sample_cont_string.append(getNumString(this_value, 1))
            region_bkg_totals[region] += this_value
        sample_cont_string.append(' \\\\')
        # print sample_cont_string
        print ''.join(sample_cont_string)

    # print total background contributions
    print '\\midrule'
    # total_bkg_string = 'Total'
    total_bkg_string = ['Total']
    for region in region_names:
        if region in subset_regions:
            total_bkg_string.append(' & ')
            total_bkg_string.append('\multirow{2}{*}{')
            total_bkg_string.append(getNumString(region_bkg_totals[region], 1))
            total_bkg_string.append('}')
    # total_bkg_string += ' \\\\'
    total_bkg_string.append(' \\\\')
    # print total_bkg_string
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

            signal_cont_string.append(getNumString(this_value, 1))

            signal_rel_cont_string.append(' (')
            signal_rel_cont_string.append(getNumString((this_value/region_bkg_totals[region]), 1))
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
    region_df = extractRegionContributions(test_sample_name)
    createTableFromRegionContributions(region_df)

# ==============================================================================
if __name__ == '__main__':
    # get input sample name
    test_sample_name = sys.argv[1] if len(sys.argv) > 1 else '${BASE_WORK_DIR}/compare_plots.b_minus_l.root'
    main(test_sample_name)

    # for i in xrange(10):
    #     print i, getNumString(3.1234567890, i), ' -- ', getNumString(0.00123456789, i)

