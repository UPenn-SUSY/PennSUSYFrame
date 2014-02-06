#!/usr/bin/env python

import RunTntMaker
import os

# ==============================================================================
if __name__ == '__main__':
    base_work_dir = os.environ['BASE_WORK_DIR']
    file_list = RunTntMaker.getFileListFromDir('%s/../mc12/mc12_8TeV.116600.gg2ZZJimmy_AUET2CT10_ZZ4lep.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512_tid01267663_00/' % base_work_dir)
    print file_list

    RunTntMaker.runTntMaker( file_list = file_list
                           , is_data = False
                           , is_full_sim = False
                           )
