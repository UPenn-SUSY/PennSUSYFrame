import subprocess
import os
import argparse
# ------------------------------------------------------------------------------
"""
It is necessary to set up an eos mount point and set up a voms-proxy
"""

# ------------------------------------------------------------------------------
def get_inputs():
    parser = argparse.ArgumentParser()
    parser.add_argument('--infile', action='store', dest='in_file')
    parser.add_argument('--eospath',
                        action='store',
                        dest='eos_path',
                        default=None)

    arguments = vars(parser.parse_args())
    if arguments['eos_path'] is None:
        user_name = os.environ['USER']
        user_initial = user_name[0:1]
        arguments['eos_path']='/'.join(['/tmp',
                                        user_name,
                                        'eos/atlas/user',
                                        user_initial,
                                        user_name,
                                        'tnt_107'])

    return arguments

# ------------------------------------------------------------------------------
def get_dataset_list(in_file):
    dataset_list = []

    with open(in_file) as f:
        for l in f.readlines():
            container_name = l.strip().rstrip()
            if 'Tnt' not in container_name: continue
            print 'Getting datasets for container: ', container_name

            p = subprocess.Popen(['dq2-list-datasets-container',
                                  container_name],
                                 stdout=subprocess.PIPE)
            this_dataset_list = p.communicate()[0].rstrip().split('\n')
            dataset_list.extend(this_dataset_list)

            # break

    for i, ds in enumerate(dataset_list):
        if ':' in ds:
            dataset_list[i] = ds.split(':')[1]
    return dataset_list

# ------------------------------------------------------------------------------
def get_dataset_files(dataset_name):
    p = subprocess.Popen(['dq2-list-files',
        dataset_name],
        stdout=subprocess.PIPE)
    file_list = [file_name for file_name in
                 p.communicate()[0].split() if 'root' in file_name]
    return file_list

# ------------------------------------------------------------------------------
def check_complete_dataset(dataset_name, eos_path):
    file_list = get_dataset_files(dataset_name)
    missing_file_list = []
    for file_name in file_list:
        full_path = '/'.join([eos_path, file_name])
        file_exists = os.path.exists(full_path)
        print 'file: ', full_path, ' - ', 'exists' if file_exists else 'missing'
        if not file_exists:
            missing_file_list.append(file_name)

    return {'num_files':len(file_list), 'missing':missing_file_list}

# ------------------------------------------------------------------------------
def check_for_missing_files(dataset_list, eos_path):
    dataset_summary = {}
    for ds in dataset_list:
        full_path = '/'.join([eos_path, ds])
        summary = check_complete_dataset(ds, full_path)
        dataset_summary[ds] = summary

    print
    print '-'*80
    print

    num_datasets = len(dataset_summary)
    empty_datasets = 0
    complete_datasets = 0

    for ds, summary in dataset_summary.items():
        num_files = summary['num_files']
        num_missing = len(summary['missing'])

        missing_str = (''.join(['num_missing: ',
                                str(num_missing),
                                ' of ',
                                str(num_files)]) if num_missing > 0
                                else 'COMPLETE')
        print ''.join([ds, ' - ', missing_str])
        if num_missing == 0:
            complete_datasets += 1
        elif num_missing == num_files:
            empty_datasets += 1
        else:
            for missing_file in summary['missing']:
                print '    ', missing_file

    print
    print '-'*80
    print

    print 'Total number datasets: ', num_datasets
    print 'Complete datasets: ', complete_datasets
    print 'Empty datasets: ', empty_datasets

# ------------------------------------------------------------------------------
if __name__ == '__main__':
    inputs = get_inputs()
    dataset_list = get_dataset_list(inputs['in_file'])
    eos_path = inputs['eos_path']

    check_for_missing_files(dataset_list, eos_path)

