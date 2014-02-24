#!/usr/bin/env python

import RunEwkAnalysis

# ==============================================================================
if __name__ == '__main__':
    print 'getting file list'
    file_list = RunEwkAnalysis.getFileListFromFile("%s/EosFileLists/d3pd.110820.ZeebbNp3.txt" % os.environ["BASE_WORK_DIR"]) 
    # file_list = file_list[:10]

    print 'file list: %s' % file_list

    print ''
    print 'About to run EwkAnalysis'
    RunEwkAnalysis.runEwkAnalysis( file_list = file_list
                                         , is_data = False
                                         , is_full_sim = True
                                         , tree_name = 'susy'
                                         , dsid = 110820
                                         , out_file_special_name = '110820.ZeebbNp3'
                                         )
