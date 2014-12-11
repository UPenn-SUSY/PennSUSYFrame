#!/usr/bin/env python
"""
This file is full of helper functions for extracting the contributions in each
region, and helpers functions for displaying this data

Note: This package requires pandas be installed! I have not gotten this working
on lxplus, but haven't really tried very hard. I simply copy the root file to my
laptop and run from there.
"""

import ROOT
import pandas
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
def getRegionTitle(region_name):
    this_region_string = region_name.replace('BMINUSL_', '')
    this_region_string = this_region_string.replace('_', ' ')
    if this_region_string == 'CR TOP':
        this_region_string = 'Top CR'
    if this_region_string == 'CR Z':
        this_region_string = 'Z CR'
    if this_region_string == 'VR 3':
        this_region_string = 'Top VR'
    if this_region_string == 'VR 5':
        this_region_string = 'Z VR'
    return this_region_string


# ------------------------------------------------------------------------------
def getSampleTitle(sample_name):
    if sample_name == 'Z/#gamma^{*}':
        return '$Z/\\gamma^{*}$'
    if sample_name == 'ttbar':
        return '$t\\bar{t}$'
    return sample_name

