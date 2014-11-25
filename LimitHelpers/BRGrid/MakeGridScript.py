import itertools

br_points = range(0,101, 25)
br_points.append(33)

# print br_points

for bre, brm in itertools.product(br_points, br_points):
    brt = 100 - bre - brm
    if brt < 0: continue
    print bre, ' -- ', brm, ' -- ', brt

    file_name = ''.join(['BLStopFit',
                         '_bre_', str(bre),
                         '_brm_', str(brm),
                         '_brt_', str(brt),
                         '.py'])

    with file(file_name, 'w') as f:
        f.write(''.join(['stop_br_e = ', str(bre/100.), '\n']))
        f.write(''.join(['stop_br_m = ', str(brm/100.), '\n']))
        f.write(''.join(['stop_br_t = ', str(brt/100.), '\n']))

        f.write("""
execfile('/'.join([os.environ['BASE_WORK_DIR'], 'LimitHelpers', 'SampleExcl.py']))
""")
