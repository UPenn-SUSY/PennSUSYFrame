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
import math
from collections import OrderedDict
import argparse

from ROOT import RooStats

# ------------------------------------------------------------------------------
def createTableFromRegionContributions(region_df, regions_dict=None,
                                       do_zn_sig=False, do_s_sqrt_b=False,
                                       for_slides=False, **kwargs):
    # get the region names from the data frame, and sort based on regions_dict
    region_names = region_df['region'].unique()
    region_names = helpers.sortRegionName(region_names, regions_dict)

    # get sample names
    bkg_sample_names = region_df[
        -region_df['sample'].str.contains('stop')]['sample'].unique()
    sig_sample_names = region_df[
        region_df['sample'].str.contains('stop')]['sample'].unique()

    bkg_sample_names = helpers.sortSampleNames(bkg_sample_names)
    sig_sample_names = helpers.sortSampleNames(sig_sample_names)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # print latex table header or start of slide
    if for_slides:
        slide_title = kwargs['title'] if 'title' in kwargs else '...'
        print '\\begin{frame}'
        print ''.join(['\\frametitle{',slide_title,'}'])
        print '\\resizebox{\\linewidth}{!}{'
        print '\\begin{tikzpicture}'
        print '\\node[anchor=south west, inner sep=0] (image) at (0,0) {'
    else:
        print '\\begin{table}'
        print '\\centering{'
    print '\\begin{tabular}{c|%s}' % ('c'*len(region_names))

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # print title line
    print '\\toprule'
    title_string = []
    for region in region_names:
        title_string.append(' & ')
        title_string.append(helpers.getRegionTitle(region, regions_dict))
    title_string.append(' \\\\')
    print ''.join(title_string)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # print individual bkg sample contributions
    print '\\midrule'
    for sample in bkg_sample_names:
        sample_cont_string = [helpers.getSampleTitle(sample)]

        sample_subset = region_df[region_df.sample == sample]
        subset_regions = sample_subset.region.unique()
        for region in region_names:
            region_entries = 0
            region_raw_entries = 0
            if region in subset_regions:
                region_entries = sample_subset[sample_subset.region ==
                                               region].iloc[0]['count']
            sample_cont_string.append(' & ')
            sample_cont_string.append(helpers.getNumString(region_entries, 1))

        sample_cont_string.append(' \\\\')
        print ''.join(sample_cont_string)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # get the total region contributions and the uncertainty - to be used later
    region_contributions = helpers.getTotalRegionContribution(region_df,
                                                              bkg_sample_names,
                                                              region_names)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # print total background contributions
    print '\\midrule'
    bkg_total_string = ['Total']
    bkg_uncert_string = ['background']
    for region in region_names:
        # if region in subset_regions:
        if region in region_names:
            bkg_total_string.append(' & ')
            bkg_total_string.append(
                helpers.getNumString(region_contributions[
                                         region_contributions.region ==
                                            region].iloc[0]['total'], 1))

            bkg_uncert_string.append(' & ($\\pm$ ')
            bkg_uncert_string.append(
                helpers.getNumString(region_contributions[
                                         region_contributions.region ==
                                            region].iloc[0]['uncertainty'], 1))
            bkg_uncert_string.append(')')
    bkg_total_string.append(' \\\\')
    bkg_uncert_string.append(' \\\\')
    print ''.join(bkg_total_string)
    print ''.join(bkg_uncert_string)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # print signal contributions
    print '\\midrule'
    for sample in sig_sample_names:
        signal_cont_string = ['\multirow{2}{*}{', sample, '}']
        signal_rel_cont_string = ['']
        signal_zn_string = ['{\color{green}$Z_N$}']
        signal_s_sqrt_b_string = ['{\color{blue}$s/\\sqrt{b + \Delta b}$}']

        sample_subset = region_df[region_df.sample == sample]
        subset_regions = sample_subset.region.unique()
        for region in region_names:
            this_value = 0
            if region in subset_regions:
                this_value = sample_subset[
                    sample_subset.region == region].iloc[0]['count']
            signal_cont_string.append(' & ')
            signal_rel_cont_string.append(' & ')
            signal_zn_string.append(' & ')
            signal_s_sqrt_b_string.append(' & ')

            # append the number of signal events to the signal count string
            signal_cont_string.append(helpers.getNumString(this_value, 1))

            bkg_total = region_contributions[region_contributions.region ==
                                                region].iloc[0]['total']
            bkg_uncert = region_contributions[region_contributions.region ==
                                                region].iloc[0]['uncertainty']

            # append the signal/backround ratio to the rel content string
            signal_rel_cont_string.append(' (')
            signal_rel_cont_string.append(helpers.getNumString(
                ( this_value/bkg_total), 1))
            signal_rel_cont_string.append(')')

            # append the zn value to the zn string
            if 'SR' in region:
                zn = RooStats.NumberCountingUtils.BinomialExpZ(this_value,
                                                               bkg_total,
                                                               (bkg_uncert/
                                                                bkg_total))
                signal_zn_string.append(''.join(['{\color{green}',
                                                 helpers.getNumString(zn, 1),
                                                 '}']))
            else:
                signal_zn_string.append('-')

            # append the s/sqrt(b + uncertainty) to the s/sqrt(b) string
            if 'SR' in region:
                s_over_sqrt_b = this_value/math.sqrt(bkg_total + bkg_uncert)
                signal_s_sqrt_b_string.append(
                    ''.join(['{\color{blue}',
                             helpers.getNumString(s_over_sqrt_b, 1),
                             '}']))
            else:
                signal_s_sqrt_b_string.append('-')

        # Print signal contribution and significance lines
        print ''.join(signal_cont_string)
        print '\\\\'
        print ''.join(signal_rel_cont_string)
        if do_s_sqrt_b:
            print '\\\\'
            print ''.join(signal_s_sqrt_b_string)
        if do_zn_sig:
            print '\\\\'
            print ''.join(signal_zn_string)
        print '\\vspace{1ex} \\\\'

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # print end of table
    print '\\bottomrule'
    print '\\end{tabular}'
    if for_slides:
        print '};'
        print '% \\begin{scope}[x={(image.south east)}, y={(image.north west)}]'
        print '%   \\draw[red, ultra thick, rounded corners] (0.78, 0.00) rectangle (1.00, 0.48);'
        print
        print '%   % \\draw[help lines,xstep=.1,ystep=.1] (0,0) grid (1,1);'
        print '%   % \\foreach \\x in {0,1,...,9} { \\node [anchor=north] at (\\x/10,0) {0.\\x}; }'
        print '%   % \\foreach \\y in {0,1,...,9} { \\node [anchor=east] at (0,\\y/10) {0.\\y}; }'
        print
        print '% \\end{scope}'
        print '\\end{tikzpicture}'
        print '}'
        print
        print '\\begin{itemize}'
        print '\\item ...'
        print '\\end{itemize}'
        print
        print '\\end{frame}'
    else:
        print '}'
        print '\\caption{TODO add caption here!}'
        print '\\label{tab:XXX}'
        print '\\end{table}'

# ------------------------------------------------------------------------------
def main(bkg_name, sig_name):
    print "bkg name: ", bkg_name
    print "sig name: ", sig_name

    bkg_region_df = helpers.extractRegionContributionsSystematicTree(bkg_name)
    sig_region_df = helpers.extractRegionContributionsSystematicTree(sig_name)

    print '-'*80
    print 'bkg region df'
    print bkg_region_df
    print
    print '-'*80
    print 'sig region df'
    print sig_region_df

    return

    # print '% ============================================================'
    # print '% = Original regions'
    # print '% ============================================================'
    # regions_dict = OrderedDict([('CR TOP', 'Top CR'),
    #                             ('CR Z', 'Z CR'),
    #                             ('VR TOP 1', 'Top VR 1'),
    #                             ('VR TOP 2', 'Top VR 2'),
    #                             ('VR TOP 3', 'Top VR 3'),
    #                             ('VR TOP 4', 'Top VR 4'),
    #                             ('VR Z', 'Z VR'),
    #                             ('SR 1', 'SR')
    #                             ])
    # createTableFromRegionContributions(region_df, regions_dict,
    #                                    do_s_sqrt_b=True, do_zn_sig=True,
    #                                    for_slides=True,
    #                                    title='Original regions')

    def printTableHtSlice(ht):
        print
        print '% ============================================================'
        print '% = ht ', ht
        print '% ============================================================'
        regions_dict = OrderedDict([('CR TOP MBL 200', 'Top CR'),
                                    ('CR Z MBL 200', 'Z CR'),
                                    ('VR TOP 1 MBL 200', 'Top VR 1'),
                                    ('VR TOP 2 MBL 200', 'Top VR 2'),
                                    ('VR TOP 3 MBL 200', 'Top VR 3'),
                                    ('VR Z MBL 200', 'Z VR'),
                                    (' '.join(['SR HT', str(ht), 'MBL 200']), 'SR 200'),
                                    (' '.join(['SR HT', str(ht), 'MBL 400']), 'SR 400'),
                                    (' '.join(['SR HT', str(ht), 'MBL 600']), 'SR 600'),
                                    (' '.join(['SR HT', str(ht), 'MBL 800']), 'SR 800'),
                                    ])
        this_title=''.join(['$\\Mbl\\ge 200$ GeV and $h_\\mathrm{T} \\ge ',
                            str(ht), '$ GeV'])
        createTableFromRegionContributions(region_df, regions_dict,
                                           do_s_sqrt_b=False, do_zn_sig=True,
                                           for_slides=True,
                                           title=this_title)

    printTableHtSlice(1100)
    # printTableHtSlice(1000)
    # printTableHtSlice(900)
    # printTableHtSlice(800)
    # printTableHtSlice(700)
    # printTableHtSlice(600)
    # printTableHtSlice(500)

# ==============================================================================
if __name__ == '__main__':
    # get input sample name
    parser = argparse.ArgumentParser()
    parser.add_argument('--bkg', action='store', type=str)
    parser.add_argument('--sig', action='store', type=str)

    args = parser.parse_args()

    print args

    # bkg_sample_name = (sys.argv[1] if len(sys.argv) > 1
    #         else '${BASE_WORK_DIR}/compare_plots.b_minus_l.root')
    main(args.bkg, args.sig)

