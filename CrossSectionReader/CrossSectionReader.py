#!/usr/bin/env python

import os

# ------------------------------------------------------------------------------
def getCrossSection( target_dsid
                   , xsec_file_name = '%s/data/susy_crosssections_8TeV.txt' % os.environ['BASE_WORK_DIR']
                   ):
    xsec_file = file(xsec_file_name, 'r')

    for i, l in enumerate(xsec_file.readlines()):
        if i == 0: continue
        if l[0] == '#': continue

        splits = l.split()
        print splits
        dsid = int(splits[0])

        if dsid == target_dsid:
            name = splits[1]
            xsec = float(splits[2])
            kfac = float(splits[3])
            eff  = float(splits[4])

            return {'dsid':dsid, 'name':name, 'xsec':xsec, 'kfac':kfac, 'eff':eff}

    print "ERROR! did not find DSID in cross section file!"
    return None

if __name__ == '__main__':
    print getCrossSection(1)
    print getCrossSection(105200)
