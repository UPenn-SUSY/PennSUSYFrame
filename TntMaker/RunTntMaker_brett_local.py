#!/usr/bin/env python

import RunTntMaker

# ==============================================================================
if __name__ == '__main__':
    file_list = [ "${BASE_WORK_DIR}/../mc12/mc12_8TeV.116600.gg2ZZJimmy_AUET2CT10_ZZ4lep.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512_tid01267663_00/NTUP_SUSY.01267663._000001.root.1"
                , "${BASE_WORK_DIR}/../mc12/mc12_8TeV.116600.gg2ZZJimmy_AUET2CT10_ZZ4lep.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512_tid01267663_00/NTUP_SUSY.01267663._000002.root.1"
                , "${BASE_WORK_DIR}/../mc12/mc12_8TeV.116600.gg2ZZJimmy_AUET2CT10_ZZ4lep.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512_tid01267663_00/NTUP_SUSY.01267663._000003.root.1"
                , "${BASE_WORK_DIR}/../mc12/mc12_8TeV.116600.gg2ZZJimmy_AUET2CT10_ZZ4lep.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512_tid01267663_00/NTUP_SUSY.01267663._000004.root.1"
                ]

    RunTntMaker.runTntMaker( file_list = file_list
                           , is_data = False
                           , is_full_sim = False
                           )
