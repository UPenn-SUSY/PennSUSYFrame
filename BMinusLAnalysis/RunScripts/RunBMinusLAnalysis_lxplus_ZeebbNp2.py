#!/usr/bin/env python

import RunBMinusLAnalysis

# ==============================================================================
if __name__ == '__main__':
    print 'getting file list'
    file_list = RunBMinusLAnalysis.getFileListFromFile("%s/EosFileLists/d3pd.110819.ZeebbNp2.txt" % os.environ["BASE_WORK_DIR"]) 
    # file_list = file_list[:10]

    print 'file list: %s' % file_list

    print ''
    print 'About to run BMinusLAnalysis'
    RunBMinusLAnalysis.runBMinusLAnalysis( file_list = file_list
                                         , is_data = False
                                         , is_full_sim = True
                                         , tree_name = 'susy'
                                         , dsid = 110819
                                         , out_file_special_name = '110819.ZeebbNp2'
                                         )
