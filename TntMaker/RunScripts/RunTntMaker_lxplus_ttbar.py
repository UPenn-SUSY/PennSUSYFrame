#!/usr/bin/env python

import os
import sys
sys.path.append('%s/TntMaker/' % os.environ['BASE_WORK_DIR'])
import RunTntMaker

# ==============================================================================
if __name__ == '__main__':
    base_work_dir = os.environ['BASE_WORK_DIR']
    print 'getting file list'
    file_list = RunTntMaker.getFileListFromFile('%s/EosFileLists/d3pd.105200.ttbar.txt' % os.environ['BASE_WORK_DIR'])
    file_list = file_list[:1]

    print 'file list: %s' % file_list

    print ''
    print 'About to run TntMaker'
    RunTntMaker.runTntMaker( file_list = file_list
                           , is_data = False
                           # , is_full_sim = True
                           , is_full_sim = False
                           # , tree_name = 'susy'
                           # , dsid = 105200
                           # , out_file_special_name = '105200.ttbar'
                           )
