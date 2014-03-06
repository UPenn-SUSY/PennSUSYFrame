#!/usr/bin/env python

import RunTntMaker
import os

# ==============================================================================
if __name__ == '__main__':
    base_work_dir = os.environ['BASE_WORK_DIR']
    file_list = RunTntMaker.getFileListFromDir('%s/../data12/' % base_work_dir)
    print file_list

    RunTntMaker.runTntMaker( file_list = file_list
                           , is_data = True
                           # , is_full_sim = False
                           )
