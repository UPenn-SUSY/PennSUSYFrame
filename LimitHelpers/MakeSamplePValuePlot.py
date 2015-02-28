#!/usr/bin/env python

import glob
import itertools

import sys
import pickle

import pandas
import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl

# import ROOT
import summary_harvest_tree_description as tree_summary

# ROOT.gStyle.SetOptStat(0)

# ------------------------------------------------------------------------------
def extract_branching_ratios(file_name):
    """
    Given a file, name, extract the branching ratios and the SR being tested
    :param file_name: file name to be interpreted
    :rtype : dictionary
    """
    local_file_name = file_name.split('/')[-1]
    splits = local_file_name.split('_')
    return {'br': dict(bre=int(splits[2]),
                       brm=int(splits[4]),
                       brt=int(splits[6])),
            'sr': int(splits[11])}


# ------------------------------------------------------------------------------
def read_results_directory(dir_name):
    """
    Read all the harvest list files in a directory, and construct a data frame
    with the mass, branching ratios, signal region, and CLs values
    :param dir_name: name of the director to search for the harvest list files
    :rtype : pandas.DataFrame
    """
    results = pandas.DataFrame(columns=('mass', 'bre', 'brm', 'brt',
                                        'sr', 'cls'))
    col_names_to_float = [col for col in results.columns if col != 'sr']
    results[col_names_to_float] = results[col_names_to_float].astype(float)

    file_list = glob.glob(
        '/'.join([dir_name,
                  'SampleExcl_*fixSigXSecNominal*_harvest_list']))

    for fl in file_list:
        branching_ratios = extract_branching_ratios(fl)

        this_tree = tree_summary.harvesttree(fl)
        for entry in this_tree:
            # extract the mass and CLS from this entry of the tree
            this_mass = int(entry.mst)
            this_cls = entry.CLs

            # create list for this data frame entry and append to the end
            this_df_entry = [this_mass,
                             branching_ratios['br']['bre'] / 100.,
                             branching_ratios['br']['brm'] / 100.,
                             branching_ratios['br']['brt'] / 100.,
                             branching_ratios['sr'],
                             this_cls]
            results.loc[results.shape[0]] = this_df_entry
    return results


# ------------------------------------------------------------------------------
def read_hypo_test_results():
    # read results from files
    results_exp = read_results_directory('SampleLists_expected')
    results_obs = read_results_directory('SampleLists_observed')

    # rename cls to cls_exp
    columns_exp = list(results_exp.columns)
    columns_exp[-1] = 'cls_exp'
    results_exp.columns = columns_exp

    # rename cls to cls_obs
    columns_obs = list(results_obs.columns)
    columns_obs[-1] = 'cls_obs'
    results_obs.columns = columns_obs

    # merge the two data frames
    results = pandas.merge(results_exp, results_obs)

    # sort by mass and return the result
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
def plot_styling(ax):
    # plt.axis([0.0, 1.0, 0.0, 1.0])
    ax.set_xlim((0,1))
    ax.set_ylim((0,1))

    ax.set_xlabel('$Br(\\tilde{t} \\rightarrow be)$', fontsize=14)
    ax.set_ylabel('$Br(\\tilde{t} \\rightarrow b\\tau)$', fontsize=14)

    plt.xticks([i * 0.25 for i in xrange(5)])
    plt.yticks([i * 0.25 for i in xrange(5)])
    # plt.xticks([i * 0.05 for i in xrange(21)])
    # plt.yticks([i * 0.05 for i in xrange(21)])
    plt.grid(False)
    # plt.grid(True)

    ax.plot([0.00, 1.00], [1.00, 0.00], color='0.50', linestyle='--')
    ax.plot([0.50, 0.33], [0.00, 0.33], color='0.75', linestyle=':')
    ax.plot([0.00, 0.33], [0.50, 0.33], color='0.75', linestyle=':')
    ax.plot([0.50, 0.33], [0.50, 0.33], color='0.75', linestyle=':')

    # mask off upper triangle
    mask_points = np.array([[0, 1], [1, 0], [1, 1]])
    mask = plt.Polygon(mask_points, closed=True, fc='white',
                       edgecolor='white')
    ax.add_patch(mask)


# ------------------------------------------------------------------------------
def pick_best_expected_sensitivity(df):
    """

    :param df:
    :return:
    :rtype:
    """
    cls_value = 'cls_exp'

    # pick the region with the best **expected** sensitivity
    bre_list = df['bre'].unique()
    brt_list = df['brt'].unique()
    mass_list = df['mass'].unique()
    for bre, brt, mass in itertools.product(bre_list, brt_list, mass_list):
        if bre + brt > 1: continue

        # subset for this choice of mass, bre, brt
        subset = df[(df['bre'] == bre) &
                    (df['brt'] == brt) &
                    (df['mass'] == mass)]
        num_rows = len(subset)
        if num_rows == 0: continue

        # find the minimum cls value and flag the remaining SRs for removal
        min_cls = subset[cls_value].min()
        drop_sr = subset[subset[cls_value] != min_cls]['sr']

        if len(drop_sr) >= num_rows:
            print 'ERROR!'
            print 'Want to drop ', len(drop_sr), ' of ', num_rows, ' rows'
            sys.exit()

        count = 0
        while num_rows - len(drop_sr) > 1:
            if count > 10:
                print 'iterated too many times... bailing :-('
                break
            count += 1

            drop_sr = drop_sr.append(pandas.Series(subset.iloc[-1]['sr']))

        df = df[~((df['bre'] == bre) &
                  (df['brt'] == brt) &
                  (df['mass'] == mass) &
                  (df['sr'].isin(drop_sr)))]

        subset = df[(df['bre'] == bre) &
                    (df['brt'] == brt) &
                    (df['mass'] == mass)]

        if len(subset) > 1:
            print 'ERROR we have selected more than one row :-('
            print subset
            print
            sys.exit()

    return df


# ------------------------------------------------------------------------------
def pick_highest_excluded_mass(df, confidence_level):
    bre_list = df['bre'].unique()
    brt_list = df['brt'].unique()

    df = pick_best_expected_sensitivity(df)
    df = df[df['cls'] <= confidence_level]

    for bre, brt in itertools.product(bre_list, brt_list):
        mass_list = df[(df['bre'] == bre) & (df['brt'] == brt)]['mass'].unique()
        if len(mass_list) == 0: continue
        max_mass = max(mass_list)
        drop_mass = [m for m in mass_list if m != max_mass]

        df = df[~((df['bre'] == bre) &
                  (df['brt'] == brt) &
                  (df['mass'].isin(drop_mass)))]

    return df


# ------------------------------------------------------------------------------
def plot_cls_triangle(result_df, out_file_name, draw_obs=True):
    """
    Function takes a data frame, with branching ratios and CLs values.
    Constructs a triangle with showing the CLs for each branching ratio choice
    """
    norm = MidpointNormalize(vmin=0., vmax=0.10, midpoint=0.05)

    cls_val = 'cls_obs' if draw_obs else 'cls_exp'

    fig = plt.figure()
    ax = fig.add_subplot(111)
    my_plot = plt.hexbin(x=result_df['bre'],
                         y=result_df['brt'],
                         C=result_df[cls_val],
                         cmap=plt.cm.RdYlBu,
                         reduce_C_function=np.min,
                         gridsize=10,
                         norm=norm)

    # Add label with stop mass for this plot
    label_string = 'Stop mass = %d GeV\n' % result_df['mass'].iloc[0]
    label_string += 'Observed' if draw_obs else 'Expected'
    ax.text(0.65, 0.85, label_string, fontsize=16, verticalalignment='center',
            horizontalalignment='center', multialignment='center',
            bbox={'boxstyle': 'round', 'facecolor': 'white', 'alpha': 0.8})

    # add color bar to right side
    cb = plt.colorbar(my_plot, spacing='uniform', extend='max')
    cb.set_label('Observed $CL_{S}$' if draw_obs else 'Expected $CL_{S}$')

    # default plot styling
    plot_styling(ax)

    # write plot to file
    full_out_file_name = '%s_%s.pdf' % (out_file_name,
                                        'obs' if draw_obs else 'exp')
    plt.savefig(full_out_file_name, bbox_inches='tight')
    plt.close()


def plot_cls_triangle_with_contour(result_df, out_file_name):
    """
    Function takes a data frame, with branching ratios and CLs values.
    Constructs a triangle with showing the CLs for each branching ratio choice
    """
    norm = MidpointNormalize(vmin=0., vmax=0.10, midpoint=0.05)

    limit_df = result_df

    levels_for_contour_lines = [-1, 0.05, 10]
    levels = [x / 100. for x in range(0, 100)]

    limit_df = limit_df.pivot('brt', 'bre', 'cls')

    bre_values = limit_df.columns.values
    brt_values = limit_df.index.values
    cls_values = limit_df.values

    # replace NAN values with 1
    nan_values = np.isnan(cls_values)
    cls_values[nan_values] = 1

    bre, brt = np.meshgrid(bre_values, brt_values)

    # Construct plot
    fig = plt.figure()
    ax = fig.add_subplot(111)
    my_cont = plt.pcolor(bre, brt, cls_values, cmap=plt.cm.RdYlBu,
                         norm=norm)
    cset2 = plt.contour(bre, brt, cls_values, levels_for_contour_lines,
                        colors='k', linewidths=2,
                        hold='on')

    # add label with stop mass for this plot
    label_string = ''.join(('Stop mass = ',
                            str(result_df['mass'].iloc[0]),
                            ' GeV'))
    ax.text(0.55, 0.90, label_string,
            bbox={'boxstyle': 'round', 'facecolor': 'white', 'alpha': 0.8})

    # add color bar to right side
    cb = plt.colorbar(my_cont, spacing='uniform', extend='max')
    cb.set_label('$CL_{S}$')

    # default plot styling
    plot_styling(ax)

    # write plot to file
    plt.savefig(out_file_name, bbox_inches='tight')
    plt.close()


# ------------------------------------------------------------------------------
def smooth_limit_values(values, minimum_neighbors=4):
    """
    Smooth the contents of a np array to get rid of NANs. This smoothing
     function simply replaces the NAN with the average of the neighbors
    :param values: 2D ndarray of the CLs values to be smoothed
    :param minimum_neighbors: Minimum number of valid neighbors needed
     to smooth this point
    :return: smoothed 2D ndarray
    """
    print 'smooth limit values - min neighbors: ', minimum_neighbors
    num_rows = len(values)
    num_cols = len(values[0])

    # find the nan values in the ndarray
    nan_value = np.isnan(values)
    if sum(sum(nan_value)) == 0:
        return values

    # helper local function to check if a neighbor is valid
    def neighbor_valid(row, col):
        if row <= 0: return False
        if col <= 0: return False
        if row >= num_rows: return False
        if col >= num_cols: return False

        if np.isnan(values[row, col]): return False
        if values[row, col] > 2: return False

        return True

    # get the locations of the NANs and loop over them
    nan_indices = np.where(nan_value)
    num_replaced = 0
    for row_nan, col_nan in zip(np.nditer(nan_indices[0]),
                                np.nditer(nan_indices[1])):
        valid_l = neighbor_valid(row_nan-1, col_nan)
        valid_r = neighbor_valid(row_nan+1, col_nan)
        valid_u = neighbor_valid(row_nan, col_nan+1)
        valid_d = neighbor_valid(row_nan, col_nan-1)

        valid_lu = neighbor_valid(row_nan-1, col_nan+1)
        valid_ld = neighbor_valid(row_nan-1, col_nan-1)
        valid_ru = neighbor_valid(row_nan+1, col_nan+1)
        valid_rd = neighbor_valid(row_nan+1, col_nan-1)

        running_sum = 0
        if valid_l: running_sum += values[row_nan-1][col_nan]
        if valid_r: running_sum += values[row_nan+1][col_nan]
        if valid_u: running_sum += values[row_nan][col_nan+1]
        if valid_d: running_sum += values[row_nan][col_nan-1]

        if valid_lu: running_sum += values[row_nan-1][col_nan+1]
        if valid_ld: running_sum += values[row_nan-1][col_nan-1]
        if valid_ru: running_sum += values[row_nan+1][col_nan+1]
        if valid_rd: running_sum += values[row_nan+1][col_nan-1]

        num_neighbors = (valid_l  + valid_r  + valid_u  + valid_u +
                         valid_lu + valid_ld + valid_ru + valid_rd)
        if num_neighbors >= minimum_neighbors:
            values[row_nan, col_nan] = running_sum/num_neighbors
            num_replaced += 1

    print '    replaced ', num_replaced, ' NANs'

    if num_replaced == 0:
        minimum_neighbors -= 1
    return smooth_limit_values(values,
                               minimum_neighbors=minimum_neighbors)


# ------------------------------------------------------------------------------
def plot_limit_contours(result_df, out_file_name):
    """
    Function takes a data frame, with branching ratios and CLs values.
    Constructs a triangle with showing the CLs for each branching ratio choice
    """
    print 'plotting limit contours!'

    result_df = result_df[result_df['mass'] >= 400]

    # drop all but the most sensitive row for each mass/br combination
    limit_df = pick_best_expected_sensitivity(result_df)

    # levels to draw - this is a little ugly, but I want a particular order
    exp_levels = [(1 - 0.99), (1 - 0.95), (1 - 0.68)]
    obs_levels = [-1, (1 - 0.95)]

    cont_styles = [':', '--', '-.']

    cont_labels = ['exp. limit 99% CL',
                   'exp. limit 95% CL',
                   'exp. limit 68% CL']

    mass_list = sorted(limit_df['mass'].unique())
    print 'mass list: ', mass_list

    x_panels, y_panels = (3,3)
    fig = plt.figure(figsize=(20,15))

    for panel, mass in enumerate(mass_list):
        panel += 1
        if panel >= x_panels: panel += 1

        # subset this mass and reshape to make useful for plotting
        mass_subset = limit_df[limit_df['mass'] == mass]
        mass_subset = dict(exp=mass_subset.pivot('brt', 'bre', 'cls_exp'),
                           obs=mass_subset.pivot('brt', 'bre', 'cls_obs'))

        # extract grids of values
        bre_values = mass_subset['exp'].columns.values
        brt_values = mass_subset['exp'].index.values
        cls_values = {key: subset.values for key, subset in mass_subset.items()}

        bre, brt = np.meshgrid(bre_values, brt_values)

        forbidden = bre+brt > 1
        # replace forbidden values with 999
        for values in cls_values.values():
            values[forbidden] = 999

        # apply smoothing for additional NANs
        for values in cls_values.values():
            values = smooth_limit_values(values, minimum_neighbors=6)

        # Construct plot
        sp = plt.subplot(y_panels, x_panels, panel)

        exp_cont = plt.contour(bre, brt, cls_values['exp'], exp_levels,
                               colors='blue', linewidths=2,
                               linestyles=cont_styles, hold='on')
        obs_cont = plt.contour(bre, brt, cls_values['obs'], obs_levels,
                               colors='red', linewidths=2,
                               linestyles='-', hold='on')

        # add label with stop mass for this plot
        label_string = 'Stop mass = %d GeV' % mass
        sp.text(0.25, 0.85, label_string, fontsize=14,
                bbox=dict(boxstyle='round', facecolor='white', alpha=0.8))

        # default styling
        plot_styling(sp)

        # For the first plot, draw the legend in the top right
        if panel == 1:
            legend_sp = plt.subplot(y_panels, x_panels, x_panels)
            legend_sp.axis('off')

            # label plot objects and  draw legend
            for it, label in enumerate(cont_labels):
                exp_cont.collections[it].set_label(label)
            obs_cont.collections[0].set_label('Observed')

            legend_label_order = [
                'Observed limit ($\pm 1 \sigma_\mathrm{theory}^\mathrm{SUSY}$)']
            legend_label_order.extend(cont_labels[1:])
            legend_label_order.extend(cont_labels[:1])

            legend_object_order = exp_cont.collections
            legend_object_order = legend_object_order[1:] + legend_object_order[:1]
            legend_object_order.extend(obs_cont.collections)
            legend_object_order = legend_object_order[-1:] + legend_object_order[:-1]

            plt.legend(legend_object_order, legend_label_order, frameon=False,
                       fontsize=16, loc='upper center')

    plt.savefig('limit_contour.pdf')
    plt.close()


# ------------------------------------------------------------------------------
def plot_mass_limit_triangle(result_df,
                             out_file_name,
                             draw_obs=True,
                             cmap_string='hot_r',
                             vmin=0,
                             vmax=1000,
                             midpoint=800):
    """
    Function takes a data frame, with branching ratios, masses, and CLs values.
    Constructs a triangle with showing the maximum mass which is excluded at
    each point in the branching ratio triangle.
    :param result_df:
    :param out_file_name:
    :param draw_obs:
    :param cmap_string:
    :param vmin:
    :param vmax:
    :param midpoint:
    """
    # get the correct cls column name
    cls_val = 'cls_obs' if draw_obs else 'cls_exp'

    # extract the rows of the data frame which are excluded using the cls metric
    limit_df = pick_best_expected_sensitivity(result_df)
    limit_df = limit_df[limit_df[cls_val] < 0.05]

    norm = MidpointNormalize(vmin=vmin, vmax=vmax, midpoint=midpoint)

    # Construct plot
    fig = plt.figure()
    ax = fig.add_subplot(111)
    my_plot = plt.hexbin(x=limit_df['bre'],
                         y=limit_df['brt'],
                         C=limit_df['mass'],
                         cmap=plt.get_cmap(cmap_string),
                         reduce_C_function=np.max,
                         gridsize=10,
                         norm=norm)

    # add color bar to right side
    cb = plt.colorbar(my_plot, spacing='uniform')
    cb.set_ticks(range(vmin, vmax + 1, 100))
    cb.set_label('Stop mass [GeV]')

    # default plot styling
    plot_styling(ax)

    # draw label for observed/expected
    obs_exp_label_string = "Observed" if draw_obs else "Expected"
    ax.text(0.65, 0.85, obs_exp_label_string, fontsize=16,
            verticalalignment='center', horizontalalignment='center',
            bbox={'boxstyle': 'round', 'facecolor': 'white', 'alpha': 0.8}, )

    # write plot to file
    full_out_file_name = '%s_%s.pdf' % (out_file_name,
                                        'obs' if draw_obs else 'exp')
    plt.savefig(full_out_file_name, bbox_inches='tight')
    plt.close()


# ------------------------------------------------------------------------------
def plot_mass_limit_triangle_with_contours(result_df,
                                           out_file_name,
                                           cmap_string,
                                           vmin=0,
                                           vmax=1000,
                                           midpoint=800):
    """
    Function takes a data frame, with branching ratios, masses, and CLs values.
    Constructs a triangle with showing the maximum mass which is excluded at
    each point in the branching ratio triangle.
    """
    # extract the rows of the data frame which are excluded using the cls metric
    limit_df = pick_highest_excluded_mass(result_df, 0.05)

    # Prepare the levels and the cmap for plotting
    norm = MidpointNormalize(vmin=vmin, vmax=vmax, midpoint=midpoint)

    # levels to draw on plot
    levels = range(0, 1001, 100)

    # reshape data frame for plotting
    limit_df = limit_df.pivot('brt', 'bre', 'mass')

    bre_values = limit_df.columns.values
    brt_values = limit_df.index.values
    mass_values = limit_df.values

    # replace NAN values with 1
    nan_values = np.isnan(mass_values)
    mass_values[nan_values] = 0

    # Construct plot
    bre, brt = np.meshgrid(bre_values, brt_values)

    fig = plt.figure()
    ax = fig.add_subplot(111)
    my_color = plt.pcolor(bre, brt, mass_values,
                          cmap=plt.cm.get_cmap(cmap_string), norm=norm)
    my_cont = plt.contour(bre, brt, mass_values, levels, colors='b',
                          linewidths=2, hold='on')

    # add color bar to right side
    cb = plt.colorbar(my_color, spacing='uniform')
    cb.set_ticks(range(vmin, vmax + 1, 100))
    cb.set_label('Stop mass [GeV]')

    # default plot styling
    plot_styling(ax)

    # write plot to file
    plt.savefig(out_file_name, bbox_inches='tight')
    plt.close()


# ------------------------------------------------------------------------------
def plot_region_choice_triangle(result_df, out_file_name, mass=None):
    """
    TODO update this docstring
    Function takes a data frame, with branching ratios, masses, and CLs values.
    Constructs a triangle with showing the maximum mass which is excluded at
    each point in the branching ratio triangle.
    """
    region_colors = {400: 'green', 600: 'blue'}
    values_to_plot = []
    for bre, brt in itertools.product(result_df['bre'].unique(),
                                      result_df['brt'].unique()):
        if bre % 0.1 != 0: continue
        if brt % 0.1 != 0: continue

        subset = result_df[(result_df['bre'] == bre) &
                           (result_df['brt'] == brt)]
        if subset.empty: continue

        region = subset.sort(columns='cls_exp').iloc[0]['sr']
        color = region_colors[region] if region in region_colors else 'white'

        values_to_plot.append({'bre': bre, 'brt': brt, 'region': region,
                               'color': color})

    # Construct plot
    fig = plt.figure()
    ax = fig.add_subplot(111)

    # slightly modified plot styling
    plot_styling(ax)
    plt.axis([-.05, 1.1, -.05, 1.1])
    plt.grid(True)

    # draw region
    for value in values_to_plot:
        ax.text(value['bre'], value['brt'], value['region'],
                horizontalalignment='center',
                verticalalignment='center',
                bbox={'facecolor': value['color'], 'alpha': 0.5,
                      'boxstyle': 'round'})

    # Add label with stop mass for this plot
    if mass is not None:
        label_string = 'Stop mass = %d GeV' % result_df['mass'].iloc[0]
        ax.text(0.65, 0.85, label_string, fontsize=16,
                verticalalignment='center', horizontalalignment='center',
                bbox={'boxstyle': 'round', 'facecolor': 'white', 'alpha': 0.8})

    # write plot to file
    plt.savefig(out_file_name, bbox_inches='tight')
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
    col_names.extend([' - '.join(['SR %s' % sr, exp_obs]) for sr, exp_obs in
                      itertools.product(sr_names, ['Obs', 'Exp'])])
    df_to_draw = pandas.DataFrame(columns=col_names)

    for mass in result_df['mass'].unique():
        this_entry = [mass]
        for sr, exp_obs in itertools.product(sr_names, ['cls_obs', 'cls_exp']):
            # cls_value = result_df[(result_df['mass'] == mass) &
            #                       (result_df['sr'] == int(sr))].iloc[0][exp_obs]
            cls_value = result_df[(result_df['mass'] == mass) &
                                  (result_df['sr'] == int(sr))][exp_obs]
            if len(cls_value) > 0:
                cls_value = cls_value.iloc[0]
                this_entry.append(cls_value)
            else:
                this_entry.append(np.NaN)

        df_to_draw.loc[df_to_draw.shape[0]] = this_entry

    df_to_draw = df_to_draw.set_index('mass').sort()

    # plot the figure
    fig, ax = plt.subplots()
    styles = ['-', '--'] * 2
    colors = ['green', 'green', 'blue', 'blue']
    for col, style, color in zip(df_to_draw, styles, colors):
        df_to_draw[col].plot(style=style, color=color)

    plt.xlabel('Stop mass [GeV]')
    plt.ylabel('$CL_{S}$')
    plt.grid(False)

    # add line at 0.05, where we place our limit
    plt.axhline(0.05, color='r', linestyle='--')

    # add label with stop mass for this plot
    bre = result_df['bre'].iloc[0]
    brm = result_df['brm'].iloc[0]
    brt = result_df['brt'].iloc[0]
    label_string = '$Br(\\tilde{t} \\rightarrow be) = %s$\n' % bre
    label_string += '$Br(\\tilde{t} \\rightarrow b\\mu) = %s$\n' % brm
    label_string += '$Br(\\tilde{t} \\rightarrow b\\tau) = %s$' % brt
    ax.text(0.1, 0.95, label_string,
            bbox={'facecolor': 'white', 'alpha': 0.8,
                  'boxstyle': 'round'},
            verticalalignment='top',
            transform=ax.transAxes,
            fontsize=16)

    ax.legend(loc='upper right', fancybox=True, framealpha=0.8)

    # write plot to file
    plt.savefig(out_file_name, bbox_inches='tight')
    plt.close()


# ------------------------------------------------------------------------------
def make_p_value_plots(read_from_cache=False):
    # get results from hypothesis test
    if read_from_cache:
        print 'Reading results from cache'
        with open('results.pickle', 'rb') as results_file:
            results = pickle.load(results_file)
    else:
        print 'reading results from list files'
        results = read_hypo_test_results()
        with open('results.pickle', 'wb') as results_file:
            pickle.dump(results, results_file)

    # # make triangle plot for each stop mass
    # for mass, sr, draw_obs in itertools.product(results['mass'].unique(),
    #                                             results['sr'].unique(),
    #                                             [True, False]):
    #
    #     print ' '.join(['Making', 'Observed' if draw_obs else 'Expected',
    #                     'Cls triangle for mass: ', str(mass),
    #                     '-- sr: ', str(sr)])
    #     # print 'Making CLs triangle for mass:', mass, ' -- sr: ', sr
    #     file_name = 'cls_vs_br_m_%d_sr_%d' % (int(mass), sr)
    #     plot_cls_triangle(results[(results['mass'] == mass) &
    #                               (results['sr'] == sr)],
    #                       out_file_name=file_name,
    #                       draw_obs=draw_obs)
    #     # file_name = 'cls_vs_br_m_%d_sr_%d_contour' % (int(mass), sr)
    #     # plot_cls_triangle_with_contour(results[(results['mass'] == mass) &
    #     #                                        (results['sr'] == sr)],
    #     #                                file_name)
    #
    # # make mass plot - reasonable options for color map:
    # #   - hot_r, gist_heat_r, afmhot_r, GnBu,
    # for draw_obs in [True, False]:
    #     print ' '.join(['Making', 'Observed' if draw_obs else 'Expected',
    #                     ' mass limit triangle'])
    #     plot_mass_limit_triangle(results,
    #                              out_file_name='mass_limit',
    #                              draw_obs=draw_obs,
    #                              cmap_string='hot_r')
    #
    # # plot_mass_limit_triangle_with_contours(results,
    # #                          'mass_limit_contour.pdf',
    # #                          'hot_r')
    #
    # # make plot of region choice for each mass
    # for mass in results['mass'].unique():
    #     print 'Making region choice for mass:', mass
    #     file_name = ''.join(('region_choice_vs_br',
    #                          '_m_', str(int(mass)),
    #                          '.pdf'))
    #     plot_region_choice_triangle(results[results['mass'] == mass],
    #                                 file_name, mass)
    #
    # # make cls vs mass plot for each choice of branching ratios
    # for br_e, br_t, br_m in itertools.product(results['bre'].unique(),
    #                                           results['brt'].unique(),
    #                                           results['brm'].unique()):
    #     print 'Making CLs plot for bre: ', br_e, ' brm: ', br_m, ' brt: ', br_t
    #     file_name = ''.join(['cls_vs_m',
    #                          '_br_e_', str(int(br_e*100)),
    #                          '_br_m_', str(int(br_m*100)),
    #                          '_br_t_', str(int(br_t*100)),
    #                          '.pdf'])
    #     plot_single_cls_plot(results[(results['bre'] == br_e) &
    #                                  (results['brm'] == br_m) &
    #                                  (results['brt'] == br_t)], file_name)

    print 'Making limit contours!'
    plot_limit_contours(results, 'limit_contours.pdf')

    print 'All done! Exiting!'


# ==============================================================================
if __name__ == "__main__":
    make_p_value_plots(read_from_cache=True)

