#!/usr/bin/env python

import RunBMinusLAnalysis

# ==============================================================================
if __name__ == '__main__':
    print 'getting file list'
    file_list = RunBMinusLAnalysis.getFileListFromDir('/afs/cern.ch/user/b/bjackson/my_eos/mc12/mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_a159_a171_r3549_p1512_*/')
    file_list = file_list[:10]

    print 'file list: %s' % file_list

    print ''
    print 'About to run BMinusLAnalysis'
    RunBMinusLAnalysis.runBMinusLAnalysis( file_list = file_list
                                         , is_data = False
                                         # , is_full_sim = True
                                         , is_full_sim = False
                                         , tree_name = 'susy'
                                         , dsid = 105200
                                         )

