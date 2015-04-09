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
import itertools
import math
import pickle
import pandas
import sys

from TheoryUncertainties import *

# ------------------------------------------------------------------------------
systematic_grouping = dict(jes=['bjes',
                                'effective_np_1',
                                'effective_np_2',
                                'effective_np_3',
                                'effective_np_4',
                                'effective_np_5',
                                'effective_np_6',
                                'eta_intercalibration_modelling',
                                'eta_intercalibration_statand_method',
                                'flavor_comp_uncert',
                                'flavor_response_uncert',
                                'pile_up_offset_term_mu',
                                'pile_up_offset_term_npv',
                                'pile_up_pt_term',
                                'pile_up_rho_topology',
                                'single_particle_high_pt'],
                           jer=['jer'],
                           btag=['btag_sf_b',
                                 'btag_sf_c',
                                 'btag_sf_l'])


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

    print ' & '.join(table_line) ,  '\\\\'


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
    print ' & '.join(header_line) ,  '\\\\'
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
def create_grouped_table(region_df, is_signal=False):
    sample_names = region_df['sample'].unique()
    if is_signal:
        sample_names = helpers.sortSampleNames(sample_names)

    # create nominal and systematic subsets
    nominal_df = region_df[region_df['systematic'].str.contains('NoSys')]
    systematic_df = region_df[~region_df['systematic'].str.contains('NoSys')]

    # step though systematic df and add the group and deviation as a column
    nominal_list = [0]*len(systematic_df)
    systematic_diff_list = [0]*len(systematic_df)
    systematic_group_list = ['other']*len(systematic_df)
    for it in xrange(len(systematic_df)):
        this_entry = systematic_df.iloc[it]
        this_sample = this_entry['sample']

        nominal_yield = nominal_df[
            (nominal_df['sample'] == this_sample)].iloc[0]['count']
        nominal_list[it] = nominal_yield
        systematic_diff_list[it] = this_entry['count'] - nominal_yield

        this_systematic = this_entry['systematic'].lower()
        for group, components in systematic_grouping.items():
            for test_syst in components:
                if test_syst in this_systematic:
                    systematic_group_list[it] = group

                    if ('_up' in this_systematic.lower() or
                            '_down' in this_systematic.lower()):
                        if systematic_diff_list[it] > 0:
                            systematic_group_list[it] += '_up'
                        else:
                            systematic_group_list[it] += '_down'
                    break

    systematic_df['nominal'] = nominal_list
    systematic_df['diff'] = systematic_diff_list
    systematic_df['group'] = systematic_group_list
    systematic_df['diff_sq'] = [diff**2 for diff in systematic_df['diff']]

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # compress systematics into groups
    grouped_sample_df_columns = ['group', 'sample', 'count', 'diff_sq', 'diff',
                                 'fractional']
    grouped_sample_df_entries = []
    group_names = systematic_df['group'].unique()
    for group, sample in itertools.product(group_names, sample_names):
        subset = systematic_df[(systematic_df['group'] ==  group) &
                               (systematic_df['sample'] == sample)]

        count = sum(subset['count'])
        diff_sq = sum(subset['diff_sq'])
        diff = math.sqrt(diff_sq)

        nominal = sum(nominal_df[nominal_df['sample'] == sample]['count'])
        fractional = diff/nominal if nominal > 0 else 0

        grouped_sample_df_entries.append([group, sample, count, diff_sq, diff,
                                          fractional])

    grouped_sample_df = pandas.DataFrame(grouped_sample_df_entries,
                                         columns=grouped_sample_df_columns)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # compress again grouping samples
    grouped_df_columns = ['group', 'count', 'diff', 'fractional']
    grouped_df_entries = []
    for group in group_names:
        subset = grouped_sample_df[grouped_sample_df['group'] == group]

        count = sum(subset['count'])
        diff = sum(subset['diff'])

        nominal = sum(nominal_df['count'])
        fractional = diff/nominal if nominal > 0 else 0

        grouped_df_entries.append([group, count, diff, fractional])

    grouped_df = pandas.DataFrame(grouped_df_entries,
                                  columns=grouped_df_columns)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # print table
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
    header_line.extend(['\\multirow{2}{*}{%s}' % helpers.getSampleTitle(sn) for
                        sn in sample_names])
    if not is_signal:
        header_line.extend(['Total'])
    print ' & '.join(header_line) , '\\\\'
    print 'Uncertainty (\\%)' ,  '\\\\'
    print '\\midrule'

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # print detector related systematics
    for group in group_names:
        this_group_name = group.replace('_up', '').replace('_down', '')
        if 'jes' in this_group_name or 'jer' in this_group_name.lower():
            this_group_name = this_group_name.upper()
        if 'btag' in this_group_name:
            this_group_name = '$b$-tagging'
        table_line = [this_group_name.replace('_', '\\_')]
        for sample in sample_names:
            this_uncertainty = (100*grouped_sample_df[
                (grouped_sample_df['group'] == group) &
                (grouped_sample_df['sample'] == sample)
                ].iloc[0]['fractional'])
            if 'up' in group:
                this_uncertainty = '+%d/' % this_uncertainty
            elif 'down' in group:
                this_uncertainty = '-%d' % this_uncertainty
            else:
                this_uncertainty = '%d' % this_uncertainty
            table_line.append(this_uncertainty)

        table_line.append('%d' %
                          (100*grouped_df[
                              grouped_df['group'] == group
                          ].iloc[0]['fractional']))

        print ' & '.join(table_line), '\\\\'

    print '\\midrule'

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # print theory systematics
    this_region = region_df['region'].iloc[0]
    this_region_label = this_region.upper().replace(' ', '_')

    for systematic, uncertainties in theory_uncertainties.items():
        total_nominal = 0
        total_up = 0
        total_down = 0

        systematic_label = systematic
        if systematic_label == '_PartonShower':
            systematic_label = 'Parton shower'
        elif systematic_label == '_Envelope':
            systematic_label = 'Envelope'
        elif systematic_label == '_multiParton':
            systematic_label = 'Multi-parton'
        elif systematic_label == '_RScales':
            systematic_label = 'Renormalization Scale'
        elif systematic_label == '_FScales':
            systematic_label = 'Factorization Scale'
        elif systematic_label == '_DiagramSubtr':
            systematic_label = 'Interference with $t\\bar{t}$'
        elif systematic_label == '_ISRFSR':
            systematic_label = 'ISR/FSR'
        elif systematic_label == '_HtExtrapolation':
            systematic_label = '\\Ht\\ extrapolation'
        elif systematic_label == '_TtbarCrossSection':
            systematic_label = '$t\\bar{t}$ cross section'
        elif systematic_label == '_SingleTopCrossSection':
            systematic_label = '$Wt$ cross section'
        elif systematic_label == '_Lumi':
            systematic_label = 'Luminosity'
        elif systematic_label == '_MCStat':
            systematic_label = 'MC Statistical'
        elif systematic_label == '_CRStat':
            systematic_label = 'CR Statistical'

        # step through the systematics and construct each line of the table
        table_line = [systematic_label]
        for sample in sample_names:
            nominal_yield = nominal_df[
                (nominal_df['sample'] == sample)].iloc[0]['count']
            total_nominal += nominal_yield

            sample_label = sample
            if sample_label == 'ttbar':
                sample_label = 'Top'
            elif sample_label == 'ZGamma':
                sample_label = 'ZX'
            elif sample_label == 'SingleTop':
                sample_label = 'ST'

            if sample_label in uncertainties:
                up_down = uncertainties[sample_label][this_region_label]

                average_uncertainty = 0.5*sum([abs(1-u[0]) for u in up_down])

                total_up += nominal_yield*up_down[0][0]
                total_down += nominal_yield*up_down[1][0]

                table_line.append('%d' % (100*average_uncertainty))
            else:
                table_line.append('-')

                total_up += nominal_yield
                total_down += nominal_yield

        average_uncertainty = 0.5*(abs(total_nominal-total_up) +
                                   abs(total_nominal-total_down))
        average_uncertainty /= total_nominal
        table_line.append('%d' % (100*average_uncertainty))
        print ' & '.join(table_line),  '\\\\'

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


def get_stat_uncertainties(df):
    subset = df[df['systematic'] == 'NoSys']
    raw_counts = subset['raw']
    stat_uncertainty = [1/math.sqrt(r) if r > 0 else 0 for r in raw_counts]
    print stat_uncertainty

    subset['stat'] = stat_uncertainty
    print subset

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

    # get_stat_uncertainties(bkg_region_df)
    # sys.exit()

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
    # regions_dict = OrderedDict([('SR 400', 'SR 400'),
    #                             ('SR 600', 'SR 600')])

    for region_key, region_name in regions_dict.items():
        print '\\section{', region_name, '}'
        this_bkg_region_df = bkg_region_df[
            bkg_region_df['region'] == region_key]
        this_sig_region_df = sig_region_df[
            sig_region_df['region'] == region_key]

        # create_systematic_table(region_df=this_bkg_region_df, is_signal=False)
        # if 'SR' in region_key:
        #     create_systematic_table(region_df=this_sig_region_df,
        #                             is_signal=True)

        create_grouped_table(region_df=this_bkg_region_df, is_signal=False)
        create_grouped_table(region_df=this_sig_region_df, is_signal=True)

# ==============================================================================
if __name__ == '__main__':
    # get input sample name
    parser = argparse.ArgumentParser()
    parser.add_argument('--bkg', action='store', type=str)
    parser.add_argument('--sig', action='store', type=str)

    args = parser.parse_args()

    main(args.bkg, args.sig, read_from_pickle=True)

