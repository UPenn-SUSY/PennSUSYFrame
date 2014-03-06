#!/usr/bin/env python

import RunBMinusLAnalysis

# ==============================================================================
if __name__ == '__main__':
    print 'getting file list'
    # file_list = RunBMinusLAnalysis.getFileListFromDir('/Users/bjackson/work/PennSusyFrame.00.03.13/Tnt.root')
    file_list = ['/Users/bjackson/work/PennSusyFrame.00.03.13/Tnt.root']
    # file_list = file_list[:1]
    print 'file list: %s' % file_list

    print 'About to run BMinusLAnalysis'
    RunBMinusLAnalysis.runBMinusLAnalysis( file_list = file_list
                                         , is_data = False
                                         , is_full_sim = True
                                         , tree_name = 'TNT'
                                         , dsid = 116600
                                         , out_file_special_name = 'ZZ4lep'
                                         )
