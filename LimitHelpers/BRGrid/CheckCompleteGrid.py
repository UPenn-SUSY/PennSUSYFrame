import itertools
import glob

def extract_run_conditions_from_file_name(f_name):
    splits = f_name.split('_')
    # bre=int(splits[5])
    # brm=int(splits[7])
    # brt=int(splits[9])
    bre = None
    brm = None
    brt = None
    sr = None
    blinded = None

    for i, s in enumerate(splits):
        if s == 'bre':
            bre = int(splits[i+1])
            continue
        if s == 'brm':
            brm = int(splits[i+1])
            continue
        if s == 'brt':
            brt = int(splits[i+1])
            continue
        if s == 'mbl':
            sr = splits[i+1]
        if 'blind' in s:
            blinded = s

    if bre == 57:
        bre += 1
    if brm == 57:
        brm += 1
    if brt == 57:
        brt += 1

    return dict(bre=bre, brm=brm, brt=brt, sr=sr, blinded=blinded)


def construct_grid(spacing=2):
    valid_points=range(0, 101, spacing)
    return {bre:{brt:False for brt in valid_points if bre+brt <= 100}
            for bre in valid_points}


def check_grid_points(run_info_dict, sr, blinded):
    valid = construct_grid()
    for run in run_info_dict:
        valid[run['bre']][run['brt']] = True

    num_found = 0
    for bre in valid:
        for brt in valid[bre]:
            if not valid[bre][brt]:
                print 'missing -- bre: ', bre, ' - brt: ', brt
                print 'BLStopFit_bre_%s_brm_%s_brt_%s_sr_ht_1100_mbl_%s_%s.py' % (bre,
                                                                                  (100-bre-brt),
                                                                                  brt,
                                                                                  sr,
                                                                                  blinded)
            else:
                num_found += 1

    print
    print 'Found ', num_found, ' valid list files'


def check_output(sr=400, variation='Nominal', blinded='unblind'):
    print 'Checking SR ', sr, ' - ', variation, ' - ', blinded
    # glob_string = 'results/SampleExcl_*_mbl_%s_%s_Output_fixSigXSec%s_hypotest.root' % (sr, blinded, variation)
    glob_string = 'sample_lists_from_batch_sr_*/SampleExcl_*_mbl_%s_%s_Output_fixSigXSec%s_hypotest__1_harvest_list' % (sr, blinded, variation)

    file_list = glob.glob(glob_string)
    run_info = [extract_run_conditions_from_file_name(f) for f in file_list]

    check_grid_points(run_info, sr, blinded)
    print


for sr, variation, blinded in itertools.product([400, 600],
                                                ['Nominal', 'Up', 'Down'],
                                                ['unblind', 'blind']):
    check_output(sr=sr, variation=variation, blinded=blinded)
