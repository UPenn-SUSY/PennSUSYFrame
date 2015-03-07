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


# ------------------------------------------------------------------------------
text_box_style = dict(boxstyle='round', facecolor='white', alpha=0.8)
custom_cmap_band = mpl.colors.ListedColormap(['white', 'gold', 'white'])
custom_cmap_fill = mpl.colors.ListedColormap(['white', 'powderblue', 'white'])
# ------------------------------------------------------------------------------


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
def read_results_directory(dir_name, variation='Nominal'):
    """
    Read all the harvest list files in a directory, and construct a data frame
    with the mass, branching ratios, signal region, and CLs values
    :param dir_name: name of the director to search for the harvest list files
    :rtype : pandas.DataFrame
    """
    file_list = glob.glob(
        '%s/SampleExcl_*fixSigXSec%s*_harvest_list' % (dir_name, variation))

    results_list = []

    for fl in file_list:
        branching_ratios = extract_branching_ratios(fl)

        this_tree = tree_summary.harvesttree(fl)
        for entry in this_tree:
            # extract the mass and CLS from this entry of the tree
            this_mass = int(entry.mst)
            this_cls = entry.CLs

            # create list for this data frame entry and append to the end
            this_df_entry = [False,
                             this_mass,
                             branching_ratios['br']['bre'] / 100.,
                             branching_ratios['br']['brm'] / 100.,
                             branching_ratios['br']['brt'] / 100.,
                             branching_ratios['sr'],
                             this_cls]
            results_list.append(this_df_entry)

    results = pandas.DataFrame(results_list, columns=('extra', 'mass', 'bre',
                                                      'brm', 'brt', 'sr',
                                                      'cls'))
    col_names_to_float = [col for col in results.columns if col != 'sr']
    results[col_names_to_float] = results[col_names_to_float].astype(float)

    return results


# ------------------------------------------------------------------------------
def read_hypo_test_results():
    # read results from files
    """
    Read the results from the sample list files provided by HistFitter,
    and return a merged data frame with both expected and observed results

    :return: data frame with expected and observed results
    :rtype : pandas.DataFrame
    """
    results_exp = read_results_directory('SampleLists_expected')
    results_obs = read_results_directory('SampleLists_observed')
    results_obs_up = read_results_directory('SampleLists_observed',
                                            variation='Up')
    results_obs_down = read_results_directory('SampleLists_observed',
                                              variation='Down')

    # rename cls to cls_exp
    columns_exp = list(results_exp.columns)
    columns_exp[-1] = 'cls_exp'
    results_exp.columns = columns_exp

    # rename cls to cls_obs
    columns_obs = list(results_obs.columns)
    columns_obs[-1] = 'cls_obs'
    results_obs.columns = columns_obs

    # rename cls to cls_obs_up
    columns_obs_up = list(results_obs_up.columns)
    columns_obs_up[-1] = 'cls_obs_up'
    results_obs_up.columns = columns_obs_up

    # rename cls to cls_obs_down
    columns_obs_down = list(results_obs_down.columns)
    columns_obs_down[-1] = 'cls_obs_down'
    results_obs_down.columns = columns_obs_down

    # merge the two data frames
    results = pandas.merge(results_exp,
                           results_obs)
    results = results.merge(results_obs_up)
    results = results.merge(results_obs_down)

    # sort by mass and return the result
    return results.sort('mass')


# ------------------------------------------------------------------------------
class MidpointNormalize(mpl.colors.Normalize):
    """
    ...
    """
    # TODO write a docstring
    def __init__(self, vmin=None, vmax=None, midpoint=None, clip=False):
        self.midpoint = midpoint
        mpl.colors.Normalize.__init__(self, vmin, vmax, clip)

    def __call__(self, value, clip=None):
        x, y = [self.vmin, self.midpoint, self.vmax], [0, 0.5, 1]
        return np.ma.masked_array(np.interp(value, x, y))


# ------------------------------------------------------------------------------
def plot_styling(ax, color_bar=True, axis_fontsize=16, forbidden_x=0.21,
                 forbidden_y=0.80):
    """
    Apply default styling to axis
    :param ax: axis to apply styling
    :return: None
    """
    ax.set_xlim((0, 1))
    ax.set_ylim((0, 1))

    ax.set_xlabel('$Br(\\tilde{t} \\rightarrow be)$',
                  fontsize=axis_fontsize, x=1, ha='right')
    ax.set_ylabel('$Br(\\tilde{t} \\rightarrow b\\tau)$',
                  fontsize=axis_fontsize, y=1, ha='right')

    plt.xticks([i * 0.2 for i in xrange(6)])
    plt.yticks([i * 0.2 for i in xrange(6)])
    plt.grid(False)

    ax.plot([0.00, 1.00], [1.00, 0.00], color='0.25', linestyle='--')
    ax.plot([0.50, 0.33], [0.00, 0.33], color='0.50', linestyle=':')
    ax.plot([0.00, 0.33], [0.50, 0.33], color='0.50', linestyle=':')
    ax.plot([0.50, 0.33], [0.50, 0.33], color='0.50', linestyle=':')

    # mask off upper triangle
    mask_points = np.array([[0, 1], [1, 0], [1, 1]])
    mask = plt.Polygon(mask_points, closed=True, fc='white',
                       edgecolor='white')
    ax.add_patch(mask)

    plt.text(forbidden_x, forbidden_y, 'Forbidden', fontsize=18,
             rotation=-41 if color_bar else -37)


# ------------------------------------------------------------------------------
def add_atlas_labels(upper_coordinate=0.91,
                     right_coordinate=0.80,
                     fontsize=16,
                     atlas_offset=0.13,
                     line_spacing=0.05,
                     left_margin=0.1,
                     right_margin=0.99,
                     top_margin=0.92,
                     bottom_margin=0.1):
    """
    Add label with ATLAS boilerplate
    :return: None
    """
    # update the plot margins
    plt.subplots_adjust(left=left_margin, right=right_margin, top=top_margin,
                        bottom=bottom_margin)

    plt.figtext(right_coordinate-atlas_offset, upper_coordinate,
                'ATLAS', fontsize=fontsize, fontweight='bold', style='italic',
                verticalalignment='top', horizontalalignment='right')
    plt.figtext(right_coordinate, upper_coordinate, 'Internal',
                fontsize=fontsize, verticalalignment='top',
                horizontalalignment='right')

    lumi_text = '$\\int\\,\\mathrm{L dt} = 20.3 \\, \\mathrm{fb}^{-1}$'
    lumi_text += ' $\\sqrt{s} = 8$ TeV'
    plt.figtext(right_coordinate, upper_coordinate-line_spacing,
                lumi_text, fontsize=fontsize-2, verticalalignment='top',
                horizontalalignment='right')

    production_text = '$\\tilde{t}_1 \\tilde{t}_1}$ production, '
    production_text += '$\\tilde{t}_1 \\rightarrow b\ell$'
    plt.figtext(left_margin+0.01, top_margin+0.01, production_text,
                fontsize=fontsize-2, verticalalignment='bottom',
                horizontalalignment='left')


# ------------------------------------------------------------------------------
def fill_in_missing_rows(df, extra_rows=True):
    """
    Step through a data frame and look for rows which appear to be missing.

    :param df: data frame to fill in missing rows
    :return: filled in data frame
    """
    print 'filling in missing rows'

    # get list of mass, bre, brt, sr values in the data frame
    mass_values = df['mass'].unique()
    bre_values = df['bre'].unique()
    brt_values = df['brt'].unique()
    sr_values = df['sr'].unique()

    # list to keep track of rows in data frame
    rows_to_append = []

    # loop over each combination of variables, and check that a row
    #  corresponding to this combination exists
    for mass, bre, brt, sr in itertools.product(mass_values,
                                                bre_values,
                                                brt_values,
                                                sr_values):
        # don't add rows for forbidden branching ratios
        if bre+brt > 1:
            continue

        if df[(df['mass'] == mass) & (df['sr'] == sr) &
                (df['bre'] == bre) & (df['brt'] == brt)].empty:
            rows_to_append.append([extra_rows, mass, bre, (1-bre-brt), brt,
                                   sr, np.nan, np.nan, np.nan, np.nan])

    # add new rows to data frame
    if len(rows_to_append) > 0:
        df = df.append(pandas.DataFrame(rows_to_append, columns=df.columns),
                       ignore_index=True)

    return df


# ------------------------------------------------------------------------------
def generate_mesh(df, column_name):
    """
    Generate mesh of points from a data frame - this mesh is used for plotting
    The rows and columns are made from the bre/brt columns, and the values
    are taken from a column that is specified.

    :param df: data frame to convert to mesh grid
    :param column_name: Column used to fill the values in the mesh grid
    :return: Dictionary containing the bre, brt, and values mesh grids
    """
    grid_to_mesh = df.pivot('brt', 'bre', column_name)
    bre_values = grid_to_mesh.columns.values
    brt_values = grid_to_mesh.index.values
    values = grid_to_mesh.values

    bre, brt = np.meshgrid(bre_values, brt_values)

    forbidden = bre+brt > 1
    values[forbidden] = 999

    return dict(bre=bre, brt=brt, values=values)


# ------------------------------------------------------------------------------
def fill_in_missing_values_in_grid(values, minimum_neighbors=3):
    """
    Smooth the contents of a np array to get rid of NANs. This smoothing
     function simply replaces the NAN with the average of the neighbors

    :param values: 2D ndarray of the CLs values to be smoothed
    :param minimum_neighbors: Minimum number of valid neighbors needed
     to smooth this point
    :return: smoothed 2D ndarray
    """
    # print 'smooth limit values - min neighbors: ', minimum_neighbors
    # print values
    num_rows = len(values)
    num_cols = len(values[0])

    # find the nan values in the ndarray
    nan_value = np.isnan(values)
    if sum(sum(nan_value)) == 0:
        return values

    # helper local function to check if a neighbor is valid
    def neighbor_valid(row, col):
        if row <= 0:
            return False
        if col <= 0:
            return False
        if row >= num_rows:
            return False
        if col >= num_cols:
            return False

        if np.isnan(values[row, col]):
            return False
        if values[row, col] > 2:
            return False

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

        running_sum = 0.
        num_neighbors = 0.
        if valid_l:
            running_sum += values[row_nan-1][col_nan]
            num_neighbors += 1
        if valid_r:
            running_sum += values[row_nan+1][col_nan]
            num_neighbors += 1
        if valid_u:
            running_sum += 0.5*values[row_nan][col_nan+1]
            num_neighbors += 0.5
        if valid_d:
            running_sum += 0.5*values[row_nan][col_nan-1]
            num_neighbors += 0.5

        if valid_lu:
            running_sum += 0.25*values[row_nan-1][col_nan+1]
            num_neighbors += 0.25
        if valid_ld:
            running_sum += 0.25*values[row_nan-1][col_nan-1]
            num_neighbors += 0.25
        if valid_ru:
            running_sum += 0.25*values[row_nan+1][col_nan+1]
            num_neighbors += 0.25
        if valid_rd:
            running_sum += 0.25*values[row_nan+1][col_nan-1]
            num_neighbors += 0.25

        # num_neighbors = (valid_l + valid_r + valid_u + valid_u +
        #                  valid_lu + valid_ld + valid_ru + valid_rd)
        if num_neighbors >= minimum_neighbors:
            if num_neighbors == 0:
                print 'num_neighbors = 0'
                print '  min neighbors: ', minimum_neighbors
                print '  row_nan: ', row_nan, ' - col_nan: ', col_nan
                print '  num_rows: ', num_rows, ' - num_cols: ', num_cols
                print values[row_nan, col_nan]
                print values[row_nan+1, col_nan+1]
                print values[row_nan+2, col_nan+2]
                print values
            values[row_nan, col_nan] = running_sum/num_neighbors
            num_replaced += 1

    # print '    replaced ', num_replaced, ' NANs'

    if num_replaced == 0:
        minimum_neighbors -= 1
    return fill_in_missing_values_in_grid(values,
                                          minimum_neighbors=minimum_neighbors)


# ------------------------------------------------------------------------------
def fill_in_missing_values_in_df(df, column_name, minimum_neighbors=3):
    """
    Function to take a data frame df and find/fill in any missing values

    :param df: data frame which may or may not have missing values
    :param column_name: column within df to check
    :return: filled in data frame
    """
    print 'Filling in missing values for column ', column_name

    # get list of rows with NAN values
    nan_rows = np.isnan(df[column_name])

    # if the data frame provided has zero NAN values in the column of interest
    #   return the data frame as is
    if sum(nan_rows) == 0:
        return df

    # step through missing values and repair
    filtered_df = df[nan_rows]

    missing_mass_sr = list(set(zip(filtered_df['mass'], filtered_df['sr'])))

    print 'stepping through rows with missing values'
    for mass, sr in missing_mass_sr:
        grid_to_smooth = generate_mesh(df[(df['mass'] == mass) &
                                          (df['sr'] == sr)], column_name)

        # get the indices of the NANs before mutating the grid of values
        nan_indices = np.where(np.isnan(grid_to_smooth['values']))

        # fill in missing values in the grid
        grid_to_smooth['values'] = fill_in_missing_values_in_grid(
            grid_to_smooth['values'], minimum_neighbors=minimum_neighbors)

        # step through the indices of missing (previously) missing values to
        #  replace the NAN in the data frame
        for row_nan, col_nan in zip(np.nditer(nan_indices[0]),
                                    np.nditer(nan_indices[1])):
            this_bre = grid_to_smooth['bre'][row_nan, col_nan]
            this_brt = grid_to_smooth['brt'][row_nan, col_nan]
            this_value = grid_to_smooth['values'][row_nan, col_nan]

            df.loc[(df['mass'] == mass) &
                   (df['sr'] == sr) &
                   (df['bre'] == this_bre) &
                   (df['brt'] == this_brt), column_name] = this_value

    return df


# ------------------------------------------------------------------------------
def double_density(df):
    """
    Function which takes a dta frame, and increases the density of points in
    the branching ratio plane. The points are then filled in by interpolating
    between the existing points

    :param df: data frame which is to be extended
    :return: extended data frame
    """
    print 'Doubling the point density and interpolating'
    bre_list = sorted(df['bre'].unique())
    brt_list = sorted(df['brt'].unique())
    mass_list = sorted(df['mass'].unique())
    sr_list = sorted(df['sr'].unique())

    # adding intermediate points to the branding ratio lists
    bre_list.extend([(a+b)/2. for a, b in zip(bre_list[:-1], bre_list[1:])])
    brt_list.extend([(a+b)/2. for a, b in zip(brt_list[:-1], brt_list[1:])])

    bre_list = sorted(bre_list)
    brt_list = sorted(brt_list)

    # step through all combinations and add row for each combination which is
    #  missing
    rows_to_append = []
    for bre, brt, mass, sr in itertools.product(bre_list, brt_list,
                                                mass_list, sr_list):
        if bre+brt > 1:
            continue

        if df[(df['bre'] == bre) & (df['brt'] == brt) &
              (df['mass'] == mass) & (df['sr'] == sr)].empty:
            rows_to_append.append([True, mass, bre, (1-bre-brt), brt, sr,
                                   np.nan, np.nan, np.nan, np.nan])

    # append new rows to data frame
    if len(rows_to_append) > 0:
        df = df.append(pandas.DataFrame(rows_to_append, columns=df.columns),
                       ignore_index=True)

    # fill in missing rows and values
    df = fill_in_missing_rows(df, extra_rows=True)
    df = fill_in_missing_values_in_df(df, 'cls_exp', minimum_neighbors=2)
    df = fill_in_missing_values_in_df(df, 'cls_obs', minimum_neighbors=2)

    # return the new data frame with higher density
    return df


# ------------------------------------------------------------------------------
def pick_best_expected_sensitivity(df):
    """
    Step through a data frame, and for each mass/branching ratio combination,
    choose the signal region that gives the best expected sensitivity. The
    expected sensitivity is determined by taking the region with the
    minimum expected CLs
    :param df: data frame to process, and search for minimum CLs
    :return: data frame with only the best sensitivity values included
    :rtype: pandas.DataFrame
    """
    cls_value = 'cls_exp'

    # pick the region with the best **expected** sensitivity
    bre_list = df['bre'].unique()
    brt_list = df['brt'].unique()
    mass_list = df['mass'].unique()

    drop_index_list = []

    for bre, brt, mass in itertools.product(bre_list, brt_list, mass_list):
        if bre + brt > 1:
            continue

        # subset for this choice of mass, bre, brt
        subset = df[(df['bre'] == bre) &
                    (df['brt'] == brt) &
                    (df['mass'] == mass)]
        num_rows = len(subset)
        if num_rows < 2:
            continue

        # find the minimum cls value and flag the remaining SRs for removal
        min_cls = subset[cls_value].min()
        this_drop_index_list = list(subset[subset[cls_value] != min_cls].index)

        if len(this_drop_index_list) >= num_rows:
            print 'ERROR!'
            print 'Want to drop %d of %d rows' % (len(this_drop_index_list),
                                                  num_rows)
            sys.exit()

        count = 0
        while num_rows - len(this_drop_index_list) > 1:
            if count > 10:
                print 'iterated too many times... bailing :-('
                break
            count += 1

            this_drop_index_list.append(subset.index[-1])

        drop_index_list.extend(this_drop_index_list)
        if num_rows - len(this_drop_index_list) > 1:
            print 'ERROR we have selected more than one row :-('
            print subset
            print
            sys.exit()

    df = df.drop(drop_index_list)

    return df


# ------------------------------------------------------------------------------
def pick_highest_excluded_mass(df, confidence_level):
    """
    step through a data frame, and for each branching ratio combination,
     select the highest mass that is excluded to a given confidence level

    :param df: data frame to search
    :param confidence_level: confidence level to determine the exclusion
    :return: data frame with only the maximum mass included for each branching
     ratio
    """
    bre_list = df['bre'].unique()
    brt_list = df['brt'].unique()

    df = pick_best_expected_sensitivity(df)
    df = df[df['cls'] <= confidence_level]

    for bre, brt in itertools.product(bre_list, brt_list):
        mass_list = df[(df['bre'] == bre) & (df['brt'] == brt)]['mass'].unique()
        if len(mass_list) == 0:
            continue

        max_mass = max(mass_list)
        drop_mass = [m for m in mass_list if m != max_mass]

        df = df[~((df['bre'] == bre) &
                  (df['brt'] == brt) &
                  (df['mass'].isin(drop_mass)))]

    return df


# ------------------------------------------------------------------------------
def plot_cls_triangle(result_df, out_file_name, draw_obs=True, gridsize=25):
    """
    Function takes a data frame, with branching ratios and CLs values.
    Constructs a triangle with showing the CLs for each branching ratio choice

    :param result_df: data frame to plot from
    :param out_file_name: Output file name
    :param draw_obs: True if observed. False if expected
    :param gridsize: grid size for the hexbin plot
    :return: None
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
                         gridsize=gridsize,
                         norm=norm)

    # Add label with stop mass for this plot
    mass_label_string = 'Stop mass = %d GeV' % result_df['mass'].iloc[0]
    ax.text(0.98, 0.82, mass_label_string, fontsize=14, verticalalignment='top',
            horizontalalignment='right')

    sr_label_string = 'SR %s: ' % result_df['sr'].iloc[0]
    sr_label_string += 'Observed' if draw_obs else 'Expected'
    sr_label_string += ' $CL_{S}$'
    ax.text(0.98, 0.77, sr_label_string, fontsize=14, verticalalignment='top',
            horizontalalignment='right')

    # add color bar to right side
    cb = plt.colorbar(my_plot, spacing='uniform', extend='max')
    cb.set_label('Observed $CL_{S}$' if draw_obs else 'Expected $CL_{S}$')

    # default plot styling
    plot_styling(ax)
    add_atlas_labels(upper_coordinate=0.90, right_coordinate=0.80,
                     fontsize=16)

    # write plot to file
    full_out_file_name = '%s_%s.pdf' % (out_file_name,
                                        'obs' if draw_obs else 'exp')
    plt.savefig(full_out_file_name)
    plt.close()


# ------------------------------------------------------------------------------
def plot_limit_contours(result_df, out_file_name):
    """
    Function takes a data frame, with branching ratios and CLs values.
    Constructs a triangle with showing the CLs for each branching ratio choice

    :param result_df: data frame used to make the plots
    :param out_file_name: output file name
    :return: None
    """
    print 'plotting limit contours!'

    result_df = result_df[(result_df['mass'] >= 400)]

    # drop all but the most sensitive row for each mass/br combination
    limit_df = pick_best_expected_sensitivity(result_df)
    # limit_df = result_df

    # levels to draw - this is a little ugly, but I want a particular order
    # exp_levels = [(1 - 0.99), (1 - 0.95), (1 - 0.68)]
    exp_levels = [-1, (1 - 0.95)]
    exp_band_levels = [(1 - 0.99), (1 - 0.68)]
    obs_levels = [-1, (1 - 0.95)]

    mass_list = sorted(limit_df['mass'].unique())

    x_panels, y_panels = (3, 3)
    fig = plt.figure(figsize=(20, 15))

    for panel, mass in enumerate(mass_list):
        panel += 1
        if panel >= x_panels:
            panel += 1

        # subset this mass and reshape to make useful for plotting
        mass_subset = limit_df[limit_df['mass'] == mass]
        mesh_exp = generate_mesh(mass_subset, 'cls_exp')
        mesh_obs = generate_mesh(mass_subset, 'cls_obs')
        mesh_obs_up = generate_mesh(mass_subset, 'cls_obs_up')
        mesh_obs_down = generate_mesh(mass_subset, 'cls_obs_down')

        # extract grids of values
        bre, brt = mesh_exp['bre'], mesh_exp['brt']
        cls_values = dict(exp=mesh_exp['values'],
                          obs=mesh_obs['values'],
                          obs_up=mesh_obs_up['values'],
                          obs_down=mesh_obs_down['values'])

        # Construct plot
        sp = plt.subplot(y_panels, x_panels, panel)

        # expected contour lines
        exp_cont = plt.contour(bre, brt, cls_values['exp'], exp_levels,
                               colors='blue', linewidths=2,
                               linestyles='--', hold='on')
        # observed contour line
        obs_cont = plt.contour(bre, brt, cls_values['obs'], obs_levels,
                               colors='red', linewidths=2,
                               linestyles='-', hold='on')
        # fill area under observed contour
        plt.contourf(bre, brt, cls_values['obs'], obs_levels,
                     cmap=custom_cmap_fill, hold='on')
        # expected error bands
        plt.contourf(bre, brt, cls_values['exp'], exp_band_levels,
                     cmap=custom_cmap_band, hold='on')
        # +1 sigma observed limit
        plt.contour(bre, brt, cls_values['obs_up'], obs_levels,
                    colors='red', linewidths=2,
                    linestyles=':', hold='on')
        # -1 sigma observed limit
        plt.contour(bre, brt, cls_values['obs_down'],
                    obs_levels, colors='red', linewidths=2,
                    linestyles=':', hold='on')

        # add label with stop mass for this plot
        label_string = 'Stop mass = %d GeV' % mass
        sp.text(0.95, 0.95, label_string, fontsize=20, bbox=text_box_style,
                horizontalalignment='right', verticalalignment='top')

        # default styling
        plot_styling(sp, color_bar=False, axis_fontsize=26)

        # For the first plot, draw the legend in the top right
        if panel == 1:
            legend_sp = plt.subplot(y_panels, x_panels, x_panels)
            legend_sp.set_xlim((0, 1))
            legend_sp.set_ylim((0, 1))
            legend_sp.axis('off')

            # label plot objects and  draw legend
            label_order = [
                'Observed limit ($\pm 1 \sigma_\mathrm{theory}^\mathrm{SUSY}$)',
                'Expected limit ($\pm 1 \sigma_\mathrm{exp}$)', '...']

            # magic to get set up the legend
            legend_x = 0.45
            legend_y = 0.50
            object_order = [obs_cont.collections[0], exp_cont.collections[0]]
            plt.legend(object_order, label_order, frameon=False, fontsize=20,
                       loc='center', bbox_to_anchor=[legend_x, legend_y])

            add_atlas_labels(upper_coordinate=0.95, right_coordinate=0.96,
                             fontsize=30, atlas_offset=0.10, line_spacing=0.05,
                             left_margin=0.05, right_margin=0.97,
                             top_margin=0.95, bottom_margin=0.05)

            # Ugly hack to get the error bands on the legend
            overlay_x1 = legend_x - 0.384
            overlay_x2 = legend_x - 0.305
            overlap_obs_center = legend_y + 0.065
            overlap_exp_center = legend_y - 0.054
            overlay_delta_y = 0.035

            plt.plot([overlay_x1, overlay_x2],
                     [overlap_obs_center+overlay_delta_y]*2,
                     'r:', lw=2)
            plt.plot([overlay_x1, overlay_x2],
                     [overlap_obs_center-overlay_delta_y]*2,
                     'r:', lw=2)

            error_band_points = [[overlay_x1,
                                  overlap_exp_center+overlay_delta_y],
                                 [overlay_x2,
                                  overlap_exp_center+overlay_delta_y],
                                 [overlay_x2,
                                  overlap_exp_center-overlay_delta_y],
                                 [overlay_x1,
                                  overlap_exp_center-overlay_delta_y]]
            error_band = plt.Polygon(error_band_points, facecolor='gold', lw=0)
            plt.gca().add_patch(error_band)

    plt.savefig(out_file_name)
    plt.close()


# ------------------------------------------------------------------------------
def plot_mass_limit_triangle(result_df,
                             out_file_name,
                             # draw_obs=True,
                             cmap_string='hot_r',
                             vmin=0,
                             vmax=1000,
                             midpoint=800,
                             gridsize=25):
    """
    Function takes a data frame, with branching ratios, masses, and CLs values.
    Constructs a triangle with showing the maximum mass which is excluded at
    each point in the branching ratio triangle.

    :param result_df: data frame holding data for the plot
    :param out_file_name: output file name
    :param draw_obs: True for observed limit. False for expected limit
    :param cmap_string: color map
    :param vmin: minimum of color bar
    :param vmax: maximum of color bar
    :param midpoint: midpoint of color bar
    :param gridsize: gridsize for the hexplot
    :return: None
    """
    # extract the rows of the data frame which are excluded using the cls metric
    print 'Picking region with best expected sensitivity'
    limit_df = pick_best_expected_sensitivity(result_df)

    for draw_obs in [True, False]:
        # get the correct cls column name
        cls_val = 'cls_obs' if draw_obs else 'cls_exp'

        print 'Dropping all rows which are not excluded'
        this_limit_df = limit_df[limit_df[cls_val] < 0.05]

        norm = MidpointNormalize(vmin=vmin, vmax=vmax, midpoint=midpoint)

        # Construct plot
        fig = plt.figure()
        ax = fig.add_subplot(111)
        my_plot = plt.hexbin(x=this_limit_df['bre'],
                             y=this_limit_df['brt'],
                             C=this_limit_df['mass'],
                             cmap=plt.get_cmap(cmap_string),
                             reduce_C_function=np.max,
                             gridsize=gridsize,
                             norm=norm)

        # add color bar to right side
        cb = plt.colorbar(my_plot, spacing='uniform')
        cb.set_ticks(range(vmin, vmax+1, 100))
        cb.set_label('Stop mass [GeV]')

        # default plot styling
        plot_styling(ax, axis_fontsize=20)
        add_atlas_labels(upper_coordinate=0.90, right_coordinate=0.80,
                         fontsize=16)

        # draw label for observed/expected
        label_string = "Observed" if draw_obs else "Expected"
        label_string += ' mass limit'
        ax.text(0.98, 0.82, label_string, fontsize=14, verticalalignment='top',
                horizontalalignment='right')

        # write plot to file
        full_out_file_name = '%s_%s.pdf' % (out_file_name,
                                            'obs' if draw_obs else 'exp')
        plt.savefig(full_out_file_name, bbox_inches='tight')
        plt.close()


# ------------------------------------------------------------------------------
def plot_region_choice_triangle(result_df, out_file_name, mass=None):
    """
    Function takes a data frame, with branching ratios, masses, and CLs values.
    Constructs a triangle with showing the maximum mass which is excluded at
    each point in the branching ratio triangle.

    :param result_df: data frame holding data for plot
    :param out_file_name: output file name
    :param mass: Mass for this plot. Only used in the label
    :return: None
    """
    region_colors = {400: 'green', 600: 'blue'}
    values_to_plot = []
    for bre, brt in itertools.product(result_df['bre'].unique(),
                                      result_df['brt'].unique()):
        if 100*bre % 10 != 0 or 100*brt % 10 != 0:
            continue

        subset = result_df[(result_df['bre'] == bre) &
                           (result_df['brt'] == brt)]
        if subset.empty:
            continue

        region = subset.sort(columns='cls_exp').iloc[0]['sr']
        color = region_colors[region] if region in region_colors else 'white'

        values_to_plot.append({'bre': bre, 'brt': brt, 'region': region,
                               'color': color})

    # Construct plot
    fig = plt.figure()
    ax = fig.add_subplot(111)

    # slightly modified plot styling
    plot_styling(ax, color_bar=False, forbidden_x=0.27)
    plt.axis([-.05, 1.1, -.05, 1.1])
    add_atlas_labels(upper_coordinate=0.9,
                     right_coordinate=0.95)

    # draw region
    for value in values_to_plot:
        ax.text(value['bre'], value['brt'], value['region'],
                horizontalalignment='center', verticalalignment='center',
                bbox=dict(facecolor=value['color'], alpha=0.5,
                          boxstyle='round'))

    # Add label with stop mass for this plot
    if mass is not None:
        label_string = 'Stop mass = %d GeV' % result_df['mass'].iloc[0]
        ax.text(1.05, 0.85, label_string, fontsize=16,
                verticalalignment='top', horizontalalignment='right',
                bbox=text_box_style)

    # write plot to file
    plt.savefig(out_file_name, bbox_inches='tight')
    plt.close()


# ------------------------------------------------------------------------------
def plot_single_cls_plot(result_df, out_file_name):
    """
    Function takes a data frame, with masses and CLs values.
    Constructs a plot of the CLs value vs mass.

    :param result_df: data frame containing data for plot
    :param out_file_name: output file name
    :return: None
    """
    # skip if data frame has no entries
    if len(result_df) == 0:
        return

    col_names = ['mass']
    sr_names = [str(sr) for sr in sorted(result_df['sr'].unique())]
    col_names.extend([' - '.join(['SR %s' % sr, exp_obs]) for sr, exp_obs in
                      itertools.product(sr_names, ['Obs', 'Exp'])])
    df_to_draw = pandas.DataFrame(columns=col_names)

    for mass in result_df['mass'].unique():
        this_entry = [mass]
        for sr, exp_obs in itertools.product(sr_names, ['cls_obs', 'cls_exp']):
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
    ax.text(0.1, 0.95, label_string, bbox=text_box_style,
            verticalalignment='top', transform=ax.transAxes, fontsize=16)

    ax.legend(loc='upper right', fancybox=True, framealpha=0.8)

    # write plot to file
    plt.savefig(out_file_name, bbox_inches='tight')
    plt.close()


# ------------------------------------------------------------------------------
def make_p_value_plots(read_from_cache=False,
                       update_cache=True,
                       cache_file_name='results.pickle'):
    """
    Master function that runs the main flow of the script. This calls other
    functions which read in data, and draw various plots

    :param read_from_cache: Read from a cached pickle or from the sample
     list files
    :param update_cache: update the cached pickle file with the new pickle
    :param cache_file_name: file name for the pickle
    :return: None
    """
    # get results from hypothesis test
    if read_from_cache:
        print 'Reading results from cache'
        # with open('results.pickle', 'rb') as results_file:
        with open(cache_file_name, 'rb') as results_file:
            results = pickle.load(results_file)
    else:
        print 'reading results from list files'
        results = read_hypo_test_results()

        # fill in missing rows in the results data frame
        results = fill_in_missing_rows(results, extra_rows=False)
        print 'done filling in missing rows'

        # fill in missing values
        results = fill_in_missing_values_in_df(df=results,
                                               column_name='cls_exp')
        results = fill_in_missing_values_in_df(df=results,
                                               column_name='cls_obs')
        results = fill_in_missing_values_in_df(df=results,
                                               column_name='cls_obs_up')
        results = fill_in_missing_values_in_df(df=results,
                                               column_name='cls_obs_down')

        # double the density of points ... twice!!!
        results = double_density(results)
        results = double_density(results)

        # pickle up result for quicker access later
        if update_cache:
            # with open('results.pickle', 'wb') as results_file:
            with open(cache_file_name, 'wb') as results_file:
                pickle.dump(results, results_file)

    # subset only points which are not flagged as extra
    results_no_extras = results[(results['extra'] == False)]

    # # Make CLs triangle plot for each stop mass
    # for mass, sr, draw_obs in itertools.product(results['mass'].unique(),
    #                                             results['sr'].unique(),
    #                                             [True, False]):
    #     # skip low masses
    #     if mass < 400:
    #         continue
    #
    #     print ' '.join(['Making', 'Observed' if draw_obs else 'Expected',
    #                     'Cls triangle for mass: ', str(mass),
    #                     '-- sr: ', str(sr)])
    #
    #     file_name = 'cls_vs_br_m_%d_sr_%d' % (int(mass), sr)
    #     plot_cls_triangle(results[(results['mass'] == mass) &
    #                               (results['sr'] == sr)],
    #                       out_file_name=file_name,
    #                       draw_obs=draw_obs,
    #                       gridsize=60)
    #
    # make mass plot - reasonable options for color map:
    #   - hot_r, gist_heat_r, afmhot_r, GnBu,
    plot_mass_limit_triangle(results,
                             out_file_name='mass_limit',
                             # draw_obs=draw_obs,
                             cmap_string='hot_r',
                             gridsize=35)
    plot_mass_limit_triangle(results_no_extras,
                             out_file_name='mass_limit_no_extras',
                             # draw_obs=draw_obs,
                             cmap_string='hot_r',
                             gridsize=10)

    # # make plot of region choice for each mass
    # for mass in results_no_extras['mass'].unique():
    #     print 'Making region choice for mass:', mass
    #     file_name = ''.join(('region_choice_vs_br',
    #                          '_m_', str(int(mass)),
    #                          '.pdf'))
    #     plot_region_choice_triangle(
    #         results_no_extras[results_no_extras['mass'] == mass],
    #         file_name, mass)
    #
    # # make cls vs mass plot for each choice of branching ratios
    # for br_e, br_t, br_m in itertools.product(
    #         results_no_extras['bre'].unique(),
    #         results_no_extras['brt'].unique(),
    #         results_no_extras['brm'].unique()):
    #     print 'Making CLs plot for bre: %s, brm: %s, brt: %s' % (br_e,
    #                                                              br_m,
    #                                                              br_t)
    #     file_name = ''.join(['cls_vs_m',
    #                          '_br_e_', str(int(br_e*100)),
    #                          '_br_m_', str(int(br_m*100)),
    #                          '_br_t_', str(int(br_t*100)),
    #                          '.pdf'])
    #     plot_single_cls_plot(
    #         results_no_extras[(results_no_extras['bre'] == br_e) &
    #                           (results_no_extras['brm'] == br_m) &
    #                           (results_no_extras['brt'] == br_t)], file_name)
    #
    # # print 'Making limit contours!'
    plot_limit_contours(results_no_extras, 'limit_contours.pdf')
    # plot_limit_contours(results, 'limit_contours_with_extras.pdf')

    print 'All done! Exiting!'


# ==============================================================================
if __name__ == "__main__":
    make_p_value_plots(read_from_cache=True,
                       update_cache=True,
                       cache_file_name='results.pickle')
