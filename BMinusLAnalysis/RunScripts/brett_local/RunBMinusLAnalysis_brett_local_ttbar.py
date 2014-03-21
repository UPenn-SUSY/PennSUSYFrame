#!/usr/bin/env python

import RunBMinusLAnalysis

# ==============================================================================
if __name__ == '__main__':
    print 'getting file list'
    file_list = RunBMinusLAnalysis.getFileListFromDir('/Users/bjackson/work/mc12/mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_a159_a171_r3549_p1512_tid01267512_00/')
    file_list = file_list[:1]
    print 'file list: %s' % file_list

    print 'About to run BMinusLAnalysis'
    RunBMinusLAnalysis.runBMinusLAnalysis( file_list = file_list
                                         , is_data = False
                                         , is_full_sim = True
                                         , dsid = 105200
                                         , out_file_special_name = 'ttbar'
                                         )
