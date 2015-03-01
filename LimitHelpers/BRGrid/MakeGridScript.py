import itertools

br_points = range(0, 101, 5)
# br_points = range(0, 101, 2)
# br_points.append(33)
sr_options = ['sr_ht_1100_mbl_400', 'sr_ht_1100_mbl_600']
blind_options = [True, False]

# print br_points

for bre, brm, sr_opt, is_blind in itertools.product(br_points,
                                                    br_points,
                                                    sr_options,
                                                    blind_options):
    brt = 100 - bre - brm
    if brt < 0: continue
    if not bre % 5 == 0 and not bre % 2 == 0: continue
    if not brt % 5 == 0 and not brt % 2 == 0: continue
    print bre, ' -- ', brm, ' -- ', brt

    blind_string = 'blind' if is_blind else 'unblind'

    file_name = ''.join(['BLStopFit',
                         '_bre_', str(bre),
                         '_brm_', str(brm),
                         '_brt_', str(brt),
                         '_', sr_opt,
                         '_', blind_string,
                         '.py'])

    with file(file_name, 'w') as f:
        f.write(''.join(['stop_br_e = ', str(bre/100.), '\n']))
        f.write(''.join(['stop_br_m = ', str(brm/100.), '\n']))
        f.write(''.join(['stop_br_t = ', str(brt/100.), '\n']))
        f.write(''.join(['test_sr = \'', sr_opt, '\'\n']))
        f.write(''.join(['is_blind = ', str(is_blind), '\n']))

        f.write("""
execfile('/'.join([os.environ['BASE_WORK_DIR'], 'LimitHelpers', 'SampleExcl.py']))
""")
