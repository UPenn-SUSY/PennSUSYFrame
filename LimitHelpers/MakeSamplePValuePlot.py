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
import array

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

    # TEMPORARY: only keep a selection of points for now to keep a clean
    # readable plot
    br_points = [x/100. for x in xrange(0, 101, 25)]
    allowed_points = [{'bre':e,'brm':m,'brt':(1-e-m)} for e,m in
                      itertools.product(br_points, br_points) if e+m <= 1]
    allowed_points.append({'bre':0.33, 'brm':0.33, 'brt':0.34})

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
            if (branching_ratios in allowed_points):
                results.loc[results.shape[0]] = this_df_entry

    return results.sort('mass')


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
                          gridsize = (20, 20),
                          vmin = 0.,
                          vmax = 0.10)
    plt.axis([0, 1.1, 0, 1.1])
    plt.xlabel('Br(\\tilde{t} \\rightarrow be)')
    plt.ylabel('Br(\\tilde{t} \\rightarrow b\\tau)')
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
    cb.set_label('CL_{S}')

    # write plot to file
    plt.savefig(out_file_name, bbox_inches = 'tight')
    plt.close()


# ------------------------------------------------------------------------------
# TODO if this works, try and understand what is going on!
class MidpointNormalize(mpl.colors.Normalize):
    def __init__(self, vmin=None, vmax=None, midpoint=None, clip=False):
        self.midpoint = midpoint
        mpl.colors.Normalize.__init__(self, vmin, vmax, clip)

    def __call__(self, value, clip=None):
        # I'm ignoring masked values and all kinds of edge cases to make a
        # simple example...
        x, y = [self.vmin, self.midpoint, self.vmax], [0, 0.5, 1]
        return np.ma.masked_array(np.interp(value, x, y))


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
    plt.xlabel('Br(\\tilde{t} \\rightarrow be)')
    plt.ylabel('Br(\\tilde{t} \\rightarrow b\\tau)')
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
def plot_cls_triangle_root(result_df, out_file_name):
    """
    Function takes a data frame, with branching ratios and CLs values.
    Constructs a triangle with showing the CLs for each branching ratio choice
    """
    # get the x,y,z value
    x_values , y_values, z_values = (result_df['bre'],
                                     result_df['brt'],
                                     result_df['cls'])

    c = ROOT.TCanvas('c')
    cls = ROOT.TH2F('cls',
                    ';'.join(('',
                              'Br(#tilde{t} #rightarrow be)',
                              'Br(#tilde{t} #rightarrow b#tau)')),
                    110, 0, 1.1,
                    110, 0, 1.1)

    for x, y, z in zip(x_values, y_values, z_values):
        cls.Fill(x, y, z)

    # Draw and print to file
    cls.Draw('TEXT')
    c.Print(out_file_name)


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

    # plot the figure
    fig = plt.figure()
    ax = fig.add_subplot(111)
    plt.xlabel('Stop mass [GeV]')
    plt.ylabel('CL_{S}')
    plt.plot(x_values, y_values)

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
            bbox={'facecolor':'white', 'alpha':0.8, 'pad':10},
            verticalalignment = 'top',
            transform=ax.transAxes)

    # write plot to file
    plt.savefig(out_file_name, bbox_inches = 'tight')
    plt.close()


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

    # make triangle plot for each stop mass
    for mass in results['mass'].unique():
        file_name = ''.join(('cls_vs_br_text',
                             '_m_', str(mass),
                             '.pdf'))
        plot_cls_triangle_root(results[results['mass'] == mass], file_name)

    # make mass plot - reasonable options for color map:
    #   - hot_r, gist_heat_r, afmhot_r, GnBu,
    plot_mass_limit_triangle(results,
                             ''.join(['mass_limit.pdf']),
                             'hot_r')

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

    print 'All done! Exiting!'


# ==============================================================================
if __name__ == "__main__":
    make_p_value_plots()
