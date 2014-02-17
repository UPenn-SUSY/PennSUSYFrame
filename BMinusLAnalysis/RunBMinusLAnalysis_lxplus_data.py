#!/usr/bin/env python

import RunBMinusLAnalysis

# ==============================================================================
if __name__ == '__main__':
    print 'getting file list'
    file_list = RunBMinusLAnalysis.getFileListFromDir('/afs/cern.ch/user/b/bjackson/my_eos/data12/')
    print 'file list: %s' % file_list

    print 'About to run BMinusLAnalysis'
    RunBMinusLAnalysis.runBMinusLAnalysis( file_list = file_list
                                         , is_data = True
                                         , is_full_sim = False
                                         )

