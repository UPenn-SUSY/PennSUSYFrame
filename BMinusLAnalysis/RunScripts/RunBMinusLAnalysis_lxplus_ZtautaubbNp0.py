#!/usr/bin/env python

import RunBMinusLAnalysis
import os

# ==============================================================================
if __name__ == '__main__':
    print 'getting file list'
    file_list = RunBMinusLAnalysis.getFileListFromFile("%s/EosFileLists/d3pd.110825.ZtautaubbNp0.txt" % os.environ["BASE_WORK_DIR"])
    # file_list = file_list[:10]

    print 'file list: %s' % file_list

    print ''
    print 'About to run BMinusLAnalysis'
    RunBMinusLAnalysis.runBMinusLAnalysis( file_list = file_list
                                         , is_data = False
                                         # , is_full_sim = True
                                         , is_full_sim = False
                                         , tree_name = 'susy'
                                         , dsid = 110825
                                         , out_file_special_name = '110825.ZtautaubbNp0'
                                         )
