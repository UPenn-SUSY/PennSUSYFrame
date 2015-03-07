import itertools
import glob

def extract_run_conditions_from_file_name(f_name):
    splits = f_name.split('_')
    return dict(bre=int(splits[2]), brm=int(splits[4]), brt=int(splits[6]),
                sr=splits[11], blinded=splits[12])

def construct_grid(spacing=5):
    valid_points=range(0, 101, spacing)
    return {bre:{brt:False for brt in valid_points if bre+brt <= 100}
            for bre in valid_points}

def check_grid_points(run_info_dict, sr, blinded):
    valid = construct_grid()
    for run in run_info_dict:
        valid[run['bre']][run['brt']] = True

    for bre in valid:
        for brt in valid[bre]:
            if not valid[bre][brt]:
                print 'missing -- bre: ', bre, ' - brt: ', brt
                print 'BLStopFit_bre_%s_brm_%s_brt_%s_sr_ht_1100_mbl_%s_%s.py' % (bre,
                                                                                  (100-bre-brt),
                                                                                  brt,
                                                                                  sr,
                                                                                  blinded)

def check_output(sr=400, variation='Nominal', blinded='unblind'):
    print 'Checking SR ', sr, ' - ', variation, ' - ', blinded
    glob_string = 'results/SampleExcl_*_mbl_%s_%s_Output_fixSigXSec%s_hypotest.root' % (sr, blinded, variation)

    file_list = glob.glob(glob_string)
    run_info = [extract_run_conditions_from_file_name(f) for f in file_list]

    check_grid_points(run_info, sr, blinded)
    print

for sr, variation, blinded in itertools.product([400, 600],
                                                ['Nominal', 'Up', 'Down'],
                                                ['unblind', 'blind']):
    check_output(sr=sr, variation=variation, blinded=blinded)
