#!/usr/bin/env python

import RunEwkAnalysis

# ==============================================================================
if __name__ == '__main__':
    print 'getting file list'
    file_list = RunEwkAnalysis.getFileListFromDir('/afs/cern.ch/user/b/bjackson/my_eos/data12/')
    print 'file list: %s' % file_list

    print 'About to run EwkAnalysis'
    RunEwkAnalysis.runEwkAnalysis( file_list = file_list
                                         , is_data = True
                                         , is_full_sim = False
                                         )
