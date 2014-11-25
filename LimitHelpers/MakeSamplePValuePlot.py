#!/usr/bin/env python

import glob
import itertools

import pandas
import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl
mpl.rcParams['text.usetex']=True
mpl.rcParams['text.latex.unicode']=True
import ROOT

import summary_harvest_tree_description as tree_summary


ROOT.gStyle.SetOptStat(0)

# ------------------------------------------------------------------------------
def extract_branching_ratios(file_name):
    splits = file_name.split('_')
    return {'bre': int(splits[2]) / 100.,
            'brm': int(splits[4]) / 100.,
            'brt': int(splits[6]) / 100.}


# ------------------------------------------------------------------------------
def read_hypo_test_results():
    results = pandas.DataFrame(columns=('mass', 'bre', 'brm', 'brt', 'cls'))

    file_list = glob.glob('SampleExcl_*_harvest_list')
    for fl in file_list:
        branching_ratios = extract_branching_ratios(fl)

        this_tree = tree_summary.harvesttree(fl)
        for entry in this_tree:
            # extract the mass and CLS from this entry of the tree
            this_mass = int(entry.mst)
            this_cls = entry.CLs

            # create list for this data frame entry and append to the end
            this_df_entry = [this_mass,
                             branching_ratios['bre'],
                             branching_ratios['brm'],
                             branching_ratios['brt'],
                             this_cls]
            results.loc[results.shape[0]] = this_df_entry

    return results.sort('mass')


# ------------------------------------------------------------------------------
def get_min_max(val_list, limit_min_to_zero=True):
    min_val = min(val_list)
    max_val = max(val_list)
    delta = max_val - min_val

    min_val -= 0.1 * delta
    max_val += 0.1 * delta

    if limit_min_to_zero:
        min_val = max(0., min_val)

    return (min_val, max_val)


# ------------------------------------------------------------------------------
def plot_cls_triangle(result_df, out_file_name):
    """
    Function takes a data frame, with branching ratios and CLs values.
    Constructs a triangle with showing the CLs for each branching ratio choice
    """
    fig = plt.figure()
    ax = fig.add_subplot(111)
    plt.plot([0,1], [1,0], color = '0.75', linestyle = '--')
    my_plot = plt.hexbin( x = result_df['bre'],
                          y = result_df['brt'],
                          C = result_df['cls'],
                          cmap = plt.cm.BuGn_r,
                          reduce_C_function = np.max,
                          gridsize = (25,5),
                          vmin = 0.,
                          vmax = 0.10)
    plt.axis([0, 1.1, 0, 1.1])
    plt.xlabel('Br(\\tilde{t} \\rightarrow be)')
    plt.ylabel('Br(\\tilde{t} \\rightarrow b\\tau)')
    plt.grid(True)

    # add label with stop mass for this plot
    label_string = ''.join(('Stop mass = ',
                            str(result_df['mass'].iloc[0]),
                            ' GeV'))
    ax.text(0.65, 1.0, label_string,
            bbox={'facecolor':'white', 'alpha':0.5, 'pad':10})

    # add color bar to right side
    cb = plt.colorbar(my_plot,spacing='uniform',extend='max')
    cb.set_label('CL_{S}')

    # write plot to file
    plt.savefig(out_file_name)


# ------------------------------------------------------------------------------
def plot_mass_limit_triangle(result_df, out_file_name):
    """
    Function takes a data frame, with branching ratios, masses, and CLs values.
    Constructs a triangle with showing the maximum mass which is excluded at
    each point in the branching ratio triangle.
    """
    # extract the rows of the data frame which are excluded using the cls metric
    limit_df = result_df[result_df['cls'] < 0.05]

    # Construct plot
    fig = plt.figure()
    ax = fig.add_subplot(111)
    plt.plot([0,1], [1,0], color = '0.75', linestyle = '--')
    my_plot = plt.hexbin( x = limit_df['bre'],
                          y = limit_df['brt'],
                          C = limit_df['mass'],
                          cmap = plt.cm.BuGn,
                          reduce_C_function = np.max,
                          gridsize = (25,5),
                          vmin = 0.,
                          vmax = 1050)
    plt.axis([0, 1.1, 0, 1.1])
    plt.xlabel('Br(\\tilde{t} \\rightarrow be)')
    plt.ylabel('Br(\\tilde{t} \\rightarrow b\\tau)')
    plt.grid(True)

    # add color bar to right side
    cb = plt.colorbar(my_plot,spacing='uniform',extend='max')
    cb.set_label('Stop mass [GeV]')

    # write plot to file
    plt.savefig(out_file_name)


# ------------------------------------------------------------------------------
def plot_br_triangle_root(result_df, out_file_name):
    """
    Function takes a data frame, with branching ratios and CLs values.
    Constructs a triangle with showing the CLs for each branching ratio choice
    """
    # get the x,y,z value
    x_value , y_values, z_values = (result_df['bre'],
                                    result_df['brt'],
                                    result_df['cls'])

    # the_graph =
    result_df.plot(kind = 'hexbin',
                   x = 'bre',
                   y = 'brt',
                   C = 'cls',
                   cmap = plt.cm.BuGn_r,
                   reduce_C_function = np.max,
                   gridsize = (25,5),
                   vmax = 0.25)
    plt.axis([0, 1.1, 0, 1.1])
    plt.xlabel('Br(\\tilde{t} \\rightarrow be)')
    plt.ylabel('Br(\\tilde{t} \\rightarrow b\\tau)')
    plt.savefig(out_file_name)


# ------------------------------------------------------------------------------
def plot_single_cls_plot(result_df, out_file_name):
    """
    Function takes a data frame, with masses and CLs values.
    Constructs a plot of the CLs value vs mass.
    """
    # skip if data frame has no entries
    if len(result_df) == 0: return

    # extract mass and cls values from data frame
    x_values = result_df['mass']
    y_values = result_df['cls']

    # plot the figure and save to file
    plt.figure()
    plt.xlabel('Stop mass [GeV]')
    plt.ylabel('CL_{S}')
    plt.plot(x_values, y_values)
    plt.axhline(0.05, color = 'r', linestyle = '--')
    plt.savefig(out_file_name, bbox_inches = 'tight')


# ------------------------------------------------------------------------------
def make_p_value_plots():
    # get results from hypothesis test
    results = read_hypo_test_results()

    # make triangle plot for each stop mass
    for mass in results['mass'].unique():
        file_name = ''.join(('cls_vs_br',
                             '_m_', str(mass),
                             '.pdf'))
        plot_cls_triangle(results[results['mass'] == mass], file_name)

    # make plot of mass limit in branching ratio triangle
    plot_mass_limit_triangle(results, 'mass_limit.pdf')

    # make cls vs mass plot for each choice of branching ratios
    for br_e, br_t, br_m in itertools.product(results['bre'].unique(),
                                              results['brt'].unique(),
                                              results['brm'].unique()):
        file_name = ''.join(['cls_vs_m',
                             '_br_e_', str(int(br_e*100)),
                             '_br_m_', str(int(br_m*100)),
                             '_br_t_', str(int(br_t*100)),
                             '.pdf'])
        plot_single_cls_plot(results[(results['bre'] == br_e) &
                                     (results['brm'] == br_m) &
                                     (results['brt'] == br_t)],
                             file_name)


# ==============================================================================
if __name__ == "__main__":
    make_p_value_plots()
