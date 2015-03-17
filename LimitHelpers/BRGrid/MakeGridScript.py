import itertools
import os

# number of branching ratio points and options to loop over
br_points = range(0, 101, 2)
sr_options = ['sr_ht_1100_mbl_400', 'sr_ht_1100_mbl_600']
blind_options = [True, False]

# number of files per group
sub_group_size = 20
master_group_size = 5

# counters to keep track of grouping
sub_group_number = 0
files_in_sub_group = 0
sub_group_file_name = 'BLStopFitGroup_%d.txt' % sub_group_number
sub_group_file = file(sub_group_file_name, 'w')

master_group_number = 0
files_in_master_group = 0
master_group_file_name = 'master_group_set_%d.txt' % master_group_number
master_group_file = file(master_group_file_name, 'w')

master_group_file.write(sub_group_file_name)
master_group_file.write('\n')

total_num_jobs = 0

# loop through branching ratios and options
for bre, brm, sr_opt, is_blind in itertools.product(br_points,
                                                    br_points,
                                                    sr_options,
                                                    blind_options):
    # skip if branching ratio combination is forbidden
    brt = 100 - bre - brm
    if brt < 0:
        continue
    print bre, ' -- ', brm, ' -- ', brt

    total_num_jobs += 1

    this_job_command = 'python %s/RunGridPoint.py' % os.environ['PWD']
    this_job_command += ' --bre=%d ' % bre
    this_job_command += ' --brt=%d ' % brt
    this_job_command += ' --sr=%s' % sr_opt
    this_job_command += ' --blind=%d' % (1 if is_blind else 0)
    this_job_command += '\n'

    sub_group_file.write(this_job_command)

    # increment the number of files in this group and check if a new group
    #  needs to be started
    files_in_sub_group += 1
    if files_in_sub_group == sub_group_size:
        files_in_sub_group = 0
        sub_group_number += 1

        sub_group_file.close()
        sub_group_file_name = 'BLStopFitGroup_%d.txt' % sub_group_number
        sub_group_file = file(sub_group_file_name, 'w')

        master_group_file.write(sub_group_file_name)
        master_group_file.write('\n')

        files_in_master_group += 1
        if files_in_master_group == master_group_size:
            files_in_master_group = 0
            master_group_number += 1

            master_group_file.close()
            master_group_file_name = 'master_group_set_%d.txt' % master_group_number
            master_group_file = file(master_group_file_name, 'w')

sub_group_file.close()
master_group_file.close()

print 'total number of jobs: ', total_num_jobs
print 'sub groups: ', sub_group_number + 1
print 'master groups: ', master_group_number + 1
