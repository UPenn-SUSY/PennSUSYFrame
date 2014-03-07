#!/usr/bin/env python

import os
import sys
sys.path.append('%s/TntMaker/' % os.environ['BASE_WORK_DIR'])
import RunTntMaker

# ==============================================================================
if __name__ == '__main__':
    print 'getting file list'
    file_list = RunTntMaker.getFileListFromFile("%s/EosFileLists/d3pd.110828.ZtautaubbNp3.txt" % os.environ["BASE_WORK_DIR"])
    # file_list = file_list[:10]

    print 'file list: %s' % file_list

    print ''
    print 'About to run TntMaker'
    RunTntMaker.runTntMaker( file_list = file_list
                           , is_data = False
                           , is_full_sim = True
                           # , tree_name = 'susy'
                           # , dsid = 110828
                           # , out_file_special_name = '110828.ZtautaubbNp3'
                           )
