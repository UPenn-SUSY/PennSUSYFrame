import itertools
import os

# number of branching ratio points and options to loop over
br_points = range(0, 101, 2)
sr_options = ['sr_ht_1100_mbl_400', 'sr_ht_1100_mbl_600']
blind_options = [True, False]

# number of files per group
group_size = 4

# counters to keep track of grouping
group_number = 0
files_in_group = 0
group_file = file('BLStopFitGroup_%d.txt' % group_number, 'w')

# loop through branching ratios and options
for bre, brm, sr_opt, is_blind in itertools.product(br_points,
                                                    br_points,
                                                    sr_options,
                                                    blind_options):
    # skip if branching ratio combination is forbidden
    brt = 100 - bre - brm
    if brt < 0: continue
    print bre, ' -- ', brm, ' -- ', brt

    # construct file name
    blind_string = 'blind' if is_blind else 'unblind'
    file_name = ''.join(['BLStopFit',
                         '_bre_', str(bre),
                         '_brm_', str(brm),
                         '_brt_', str(brt),
                         '_', sr_opt,
                         '_', blind_string,
                         '.py'])

    # open file and write config header
    with file(file_name, 'w') as f:
        f.write(''.join(['stop_br_e = ', str(bre/100.), '\n']))
        f.write(''.join(['stop_br_m = ', str(brm/100.), '\n']))
        f.write(''.join(['stop_br_t = ', str(brt/100.), '\n']))
        f.write(''.join(['test_sr = \'', sr_opt, '\'\n']))
        f.write(''.join(['is_blind = ', str(is_blind), '\n']))

        f.write("""
execfile('/'.join([os.environ['BASE_WORK_DIR'], 'LimitHelpers', 'SampleExcl.py']))
""")

    # write to group file
    group_file.write('%s/%s\n' % (os.environ['PWD'], file_name))

    # increment the number of files in this group and check if a new group
    #  needs to be started
    files_in_group += 1
    if files_in_group == group_size:
        files_in_group = 0
        group_number += 1

        group_file.close()
        group_file = file('BLStopFitGroup_%d.txt' % group_number, 'w')

group_file.close()
