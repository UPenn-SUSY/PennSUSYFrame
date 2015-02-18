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
import math

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
            ~df['region'].str.contains('PARTIAL') &
            ~df['region'].str.contains('CRACK') &
            ~df['region'].str.contains('PAIRING') &
            ~df['region'].str.contains('OBJECTS') &
            ~df['region'].str.contains('ZVETO') &
            ~df['region'].str.contains('WEIGHTS') ]

    return df


# ------------------------------------------------------------------------------
def extractRegionContributions(sample_file_name):
    print 'extracting region contributions from file: ', sample_file_name
    # get region list from this sample file
    sample_file = ROOT.TFile.Open(sample_file_name)
    region_list = [k.GetName() for k in sample_file.GetListOfKeys()]

    # construct region contributions data frame
    cont_df = pandas.DataFrame(columns = ('region', 'sample', 'count', 'raw'))

    # for each region in the list, extract the number of expected events
    for rl in region_list:
        this_tree = sample_file.Get(rl)
        this_entries_canvas = this_tree.Get('__entries')
        this_raw_entries_canvas = this_tree.Get('__raw_entries')

        # local function to extract the entries from a canvas
        def extract_entries(canvas, column = 'Count'):
            # one primitive histogram for each process
            primitives = canvas.GetListOfPrimitives()
            for p in primitives:
                # loop over each bin to find the non-empty one
                num_bins = p.GetNbinsX()
                for bin_it in xrange(1,num_bins+1):
                    bin_label = p.GetXaxis().GetBinLabel(bin_it)

                    # We don't want data events in this data frame
                    if 'Data' in bin_label: continue
                    bin_content = p.GetBinContent(bin_it)

                    # add non-empty bin to data frame
                    if not bin_content == 0:
                        # If this combination of region and sample is not in
                        # the data frame, add a default row
                        if cont_df[cont_df['region'] == rl][cont_df['sample'] == bin_label].empty:
                            this_df_entry = [rl, bin_label, 0, 0]
                            cont_df.loc[cont_df.shape[0]] = this_df_entry

                        # update the entry with this bin content
                        cont_df.loc[(cont_df['region'] == rl) &
                                    (cont_df['sample'] == bin_label),
                                    column.lower()] = bin_content

        extract_entries(this_entries_canvas, 'count')
        extract_entries(this_raw_entries_canvas, 'raw')

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
def getRegionTitle(region_name, region_titles=None):
    this_region_string = region_name.replace('BMINUSL_', '')
    this_region_string = this_region_string.replace('_', ' ')

    # if region titles is not provided, use the default titles
    if region_titles is None:
        region_titles = {"CR TOP":"Top CR", "CR Z":"Z CR",
                         "VR TOP 1":"Top VR 1", "VR TOP 2":"Top VR 2",
                         "VR TOP 3":"Top VR 3", "VR Z":"Z VR"}

    if this_region_string in region_titles:
        this_region_string = region_titles[this_region_string]

    return this_region_string


# ------------------------------------------------------------------------------
def getSampleTitle(sample_name):
    if sample_name == 'Z/#gamma^{*}':
        return '$Z/\\gamma^{*}$'
    if sample_name == 'ttbar':
        return '$t\\bar{t}$'
    return sample_name


# ------------------------------------------------------------------------------
def sortRegionName(region_names_list, region_dict=None):
    if region_dict is None:
        region_names_list.sort()
    else:
        region_names_list = [r for r in region_dict if r in region_names_list]

    return region_names_list

# ------------------------------------------------------------------------------
def sortSampleNames(sample_name_list):
    convert = lambda text: int(text) if text.isdigit() else text
    alphanum_key = lambda key: [convert(c) for c in re.split('([0-9]+)', key)]
    return sorted(sample_name_list, key = alphanum_key)

# ------------------------------------------------------------------------------
def getTotalRegionContribution(cont_df, sample_names, region_names):
    # region_totals = {rn:0 for rn in region_names}
    # region_uncert = {rn:0 for rn in region_names}

    # create data frame to hold the totals and uncertainties
    totals_df = pandas.DataFrame(columns = ('region', 'total', 'uncertainty'))

    # loop over the regions to get the totals
    for region in region_names:
        total = 0
        uncert_sq = 0

        # loop over samples in the region
        for sample in sample_names:
            sub = cont_df[(cont_df.region == region) &
                          (cont_df.sample == sample)]

            # if this sample has any events in this region, add to the count
            # total and the uncertainty
            if not sub.empty:
                count = cont_df[(cont_df.region == region) &
                                (cont_df.sample == sample)].iloc[0]['count']
                raw = cont_df[(cont_df.region == region) &
                              (cont_df.sample == sample)].iloc[0]['raw']

                this_uncert_sq = (1/raw if raw != 0 else 0)
                this_uncert_sq += 0.30**2
                this_uncert_sq *= count**2

                total += count
                uncert_sq += this_uncert_sq

        # append the totals for this region
        totals_df.loc[totals_df.shape[0]] = [region, total, math.sqrt(uncert_sq)]

    return totals_df
