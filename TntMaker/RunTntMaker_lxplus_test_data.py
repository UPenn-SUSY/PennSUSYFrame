#!/usr/bin/env python

import RunTntMaker

# ==============================================================================
if __name__ == '__main__':
    print 'getting file list'
    file_list = RunTntMaker.getFileListFromDir('/afs/cern.ch/user/b/bjackson/my_eos/data12/')
    print 'file list: %s' % file_list

    print 'About to run TNT maker'
    RunTntMaker.runTntMaker( file_list = file_list
                           , is_data = True
                           , is_full_sim = False
                           )
