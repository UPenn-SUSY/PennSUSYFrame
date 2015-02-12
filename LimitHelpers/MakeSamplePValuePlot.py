#!/usr/bin/env python

import glob
import itertools

import pandas
import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl
# mpl.rcParams['text.usetex']=True
# mpl.rcParams['text.latex.unicode']=True
import ROOT
import array

import summary_harvest_tree_description as tree_summary


ROOT.gStyle.SetOptStat(0)

# ------------------------------------------------------------------------------
def extract_branching_ratios(file_name):
    splits = file_name.split('_')
    return {'br':{'bre': int(splits[2]) / 100.,
                  'brm': int(splits[4]) / 100.,
                  'brt': int(splits[6]) / 100.},
            'sr': int(splits[11])}


# ------------------------------------------------------------------------------
def read_hypo_test_results():
    results = pandas.DataFrame(columns=('mass', 'bre', 'brm', 'brt',
                                        'sr', 'cls'))

    # TEMPORARY: only keep a selection of points for now to keep a clean
    # readable plot
    br_points = [x/100. for x in xrange(0, 101, 25)]
    allowed_points = [{'bre':e,'brm':m,'brt':(1-e-m)} for e,m in
                      itertools.product(br_points, br_points) if e+m <= 1]
    allowed_points.append({'bre':0.33, 'brm':0.33, 'brt':0.34})

    file_list = glob.glob('SampleExcl_*_harvest_list')
    for fl in file_list:
        branching_ratios = extract_branching_ratios(fl)

        # skip points that are not allowed
        if branching_ratios['br'] not in allowed_points: continue

        this_tree = tree_summary.harvesttree(fl)
        for entry in this_tree:
            # extract the mass and CLS from this entry of the tree
            this_mass = int(entry.mst)
            this_cls = entry.CLs

            # create list for this data frame entry and append to the end
            this_df_entry = [this_mass,
                             branching_ratios['br']['bre'],
                             branching_ratios['br']['brm'],
                             branching_ratios['br']['brt'],
                             branching_ratios['sr'],
                             this_cls]
            results.loc[results.shape[0]] = this_df_entry

    return results.sort('mass')


# ------------------------------------------------------------------------------
# TODO if this works, try and understand what is going on!
class MidpointNormalize(mpl.colors.Normalize):
    def __init__(self, vmin=None, vmax=None, midpoint=None, clip=False):
        self.midpoint = midpoint
        mpl.colors.Normalize.__init__(self, vmin, vmax, clip)

    def __call__(self, value, clip=None):
        x, y = [self.vmin, self.midpoint, self.vmax], [0, 0.5, 1]
        return np.ma.masked_array(np.interp(value, x, y))


# ------------------------------------------------------------------------------
def plot_cls_triangle(result_df, out_file_name):
    """
    Function takes a data frame, with branching ratios and CLs values.
    Constructs a triangle with showing the CLs for each branching ratio choice
    """
    norm = MidpointNormalize(vmin = 0., vmax = 0.10, midpoint = 0.05)

    fig = plt.figure()
    ax = fig.add_subplot(111)
    plt.plot([0,1], [1,0], color = '0.75', linestyle = '--')
    my_plot = plt.hexbin( x = result_df['bre'],
                          y = result_df['brt'],
                          C = result_df['cls'],
                          # cmap = plt.cm.BuGn_r,
                          cmap = plt.cm.RdYlBu,
                          reduce_C_function = np.max,
                          gridsize = (20, 20),
                          norm = norm)
                          # vmin = 0.,
                          # vmax = 0.10)
    plt.axis([0, 1.1, 0, 1.1])
    plt.xlabel('$Br(\\tilde{t} \\rightarrow be)$')
    plt.ylabel('$Br(\\tilde{t} \\rightarrow b\\tau)$')
    plt.grid(True)
    plt.xticks([i*0.25 for i in xrange(5)])
    plt.yticks([i*0.25 for i in xrange(5)])

    # add label with stop mass for this plot
    label_string = ''.join(('Stop mass = ',
                            str(result_df['mass'].iloc[0]),
                            ' GeV'))
    ax.text(0.65, 1.0, label_string,
            bbox={'facecolor':'white', 'alpha':0.8, 'pad':10})

    # add color bar to right side
    cb = plt.colorbar(my_plot, spacing = 'uniform', extend = 'max')
    cb.set_label('$CL_{S}$')

    # write plot to file
    plt.savefig(out_file_name, bbox_inches = 'tight')
    plt.close()


# ------------------------------------------------------------------------------
def plot_mass_limit_triangle(result_df,
                             out_file_name,
                             cmap_string,
                             vmin = 0,
                             vmax = 1000,
                             midpoint = 800):
    """
    Function takes a data frame, with branching ratios, masses, and CLs values.
    Constructs a triangle with showing the maximum mass which is excluded at
    each point in the branching ratio triangle.
    """
    # extract the rows of the data frame which are excluded using the cls metric
    limit_df = result_df[result_df['cls'] < 0.05]

    norm = MidpointNormalize(vmin = vmin, vmax = vmax, midpoint = midpoint)

    # Construct plot
    fig = plt.figure()
    ax = fig.add_subplot(111)
    plt.plot([0,1], [1,0], color = '0.75', linestyle = '--')
    my_plot = plt.hexbin(x = limit_df['bre'],
                         y = limit_df['brt'],
                         C = limit_df['mass'],
                         cmap = plt.get_cmap(cmap_string),
                         reduce_C_function = np.max,
                         gridsize = (20, 20),
                         norm = norm)
    plt.axis([0, 1.1, 0, 1.1])
    plt.xlabel('$Br(\\tilde{t} \\rightarrow be)$')
    plt.ylabel('$Br(\\tilde{t} \\rightarrow b\\tau)$')
    plt.grid(True)
    plt.xticks([i*0.25 for i in xrange(5)])
    plt.yticks([i*0.25 for i in xrange(5)])

    # add color bar to right side
    cb = plt.colorbar(my_plot, spacing = 'uniform')
    cb.set_ticks(range(vmin, vmax+1, 100))
    cb.set_label('Stop mass [GeV]')

    # write plot to file
    plt.savefig(out_file_name, bbox_inches = 'tight')
    plt.close()


# ------------------------------------------------------------------------------
def plot_region_choice_triangle(result_df,
                                out_file_name):
    """
    TODO update this docstring
    Function takes a data frame, with branching ratios, masses, and CLs values.
    Constructs a triangle with showing the maximum mass which is excluded at
    each point in the branching ratio triangle.
    """
    values_to_plot = []
    for bre, brt in itertools.product(result_df['bre'].unique(),
                                      result_df['brt'].unique()):
        subset = result_df[(result_df['bre'] == bre) &
                           (result_df['brt'] == brt)]
        if subset.empty: continue

        region = subset.sort(columns='cls').iloc[0]['sr']

        values_to_plot.append({'bre':bre, 'brt':brt, 'region':region})

    # Construct plot
    fig = plt.figure()
    ax = fig.add_subplot(111)
    plt.plot([-0.05,1.05], [1.05,-0.05], color = '0.75', linestyle = '--')

    plt.axis([-.05, 1.1, -.05, 1.1])
    plt.xlabel('$Br(\\tilde{t} \\rightarrow be)$')
    plt.ylabel('$Br(\\tilde{t} \\rightarrow b\\tau)$')
    plt.grid(True)
    plt.xticks([i*0.25 for i in xrange(5)])
    plt.yticks([i*0.25 for i in xrange(5)])

    # draw region
    for value in values_to_plot:
        ax.text(value['bre'], value['brt'], value['region'],
                horizontalalignment='center',
                verticalalignment='center',
                bbox={'facecolor':'white', 'alpha':0.5,
                      'boxstyle':'round'})

    # write plot to file
    plt.savefig(out_file_name, bbox_inches = 'tight')
    plt.close()


# ------------------------------------------------------------------------------
def plot_single_cls_plot(result_df, out_file_name):
    """
    Function takes a data frame, with masses and CLs values.
    Constructs a plot of the CLs value vs mass.
    """
    # skip if data frame has no entries
    if len(result_df) == 0: return

    col_names = ['mass']
    sr_names = [str(sr) for sr in sorted(result_df['sr'].unique())]
    col_names.extend(sr_names)
    df_to_draw = pandas.DataFrame(columns=col_names)

    for mass in result_df['mass'].unique():
        cls_values = [result_df[(result_df['mass'] == mass) &
                                (result_df['sr'] == int(sr))].iloc[0]['cls']
                      for sr in sr_names]

        this_entry = [mass]
        this_entry.extend(cls_values)
        df_to_draw.loc[df_to_draw.shape[0]] = this_entry


    df_to_draw = df_to_draw.set_index('mass').sort()

    # plot the figure
    ax = df_to_draw.plot()

    plt.xlabel('Stop mass [GeV]')
    plt.ylabel('$CL_{S}$')

    # add line at 0.05, where we place our limit
    plt.axhline(0.05, color = 'r', linestyle = '--')

    # add label with stop mass for this plot
    label_string = ''.join(('$Br(\\tilde{t} \\rightarrow be) = $',
                            str(result_df['bre'].iloc[0]), '\n',
                            '$Br(\\tilde{t} \\rightarrow b\\mu) = $',
                            str(result_df['brm'].iloc[0]), '\n',
                            '$Br(\\tilde{t} \\rightarrow b\\tau) = $',
                            str(result_df['brt'].iloc[0])))
    ax.text(0.1, 0.9, label_string,
            bbox={'facecolor':'white', 'alpha':0.8,
                  'boxstyle':'round'},
            verticalalignment = 'top',
            transform=ax.transAxes)

    # ax.set_yscale('log')
    ax.legend(loc='upper right', fancybox=True, framealpha=0.8)

    # write plot to file
    plt.savefig(out_file_name, bbox_inches = 'tight')
    plt.close()


# ------------------------------------------------------------------------------
def make_p_value_plots():
    # get results from hypothesis test
    results = read_hypo_test_results()

    # make triangle plot for each stop mass
    for mass, sr in itertools.product(results['mass'].unique(),
                                      results['sr'].unique()):
        print 'mass:', mass, ' -- sr: ', sr
        file_name = ''.join(('cls_vs_br',
                             '_m_', str(mass),
                             '_sr_', str(sr),
                             '.pdf'))
        plot_cls_triangle(results[(results['mass'] == mass) &
                                  (results['sr'] == sr)],
                          file_name)

    # make mass plot - reasonable options for color map:
    #   - hot_r, gist_heat_r, afmhot_r, GnBu,
    plot_mass_limit_triangle(results,
                             'mass_limit.pdf',
                             'hot_r')

    # make plot of region choice for each mass
    for mass in results['mass'].unique():
        print 'mass:', mass
        file_name = ''.join(('region_choice_vs_br',
                             '_m_', str(mass),
                             '.pdf'))
        plot_region_choice_triangle(results[results['mass'] == mass], file_name)

    # make cls vs mass plot for each choice of branching ratios
    for br_e, br_t, br_m in itertools.product(results['bre'].unique(),
                                              results['brt'].unique(),
                                              results['brm'].unique()):
        print 'bre: ', br_e, ' - brm: ', br_m, ' - brt: ', br_t
        file_name = ''.join(['cls_vs_m',
                         '_br_e_', str(int(br_e*100)),
                         '_br_m_', str(int(br_m*100)),
                         '_br_t_', str(int(br_t*100)),
                         '.pdf'])
        plot_single_cls_plot(results[(results['bre'] == br_e) &
                                     (results['brm'] == br_m) &
                                     (results['brt'] == br_t)],
                             file_name)

    print 'All done! Exiting!'


# ==============================================================================
if __name__ == "__main__":
    make_p_value_plots()
