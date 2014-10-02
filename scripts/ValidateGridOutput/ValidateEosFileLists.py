#!/usr/bin/env python

import os
import glob

#-------------------------------------------------------------------------------
def cleanLine(line_string):
    # clean line to remove \n and any comment at the front of the line
    cleaned_line = line_string.rstrip('\n').replace('#','')
    return cleaned_line

#-------------------------------------------------------------------------------
def checkEntry(line_string):
    # check that this line has the correct number of entries
    cleaned_line = cleanLine(line_string)
    splits = cleaned_line.split()
    if len(splits) != 4:
        print 'ERROR: Line has ' , len(splits) , ' entries'
        print '    line: ' , cleaned_line
        return False
    for s in splits:
        if 'error' in s.lower():
            print 'ERROR: Line has an error in one of the entries'
            print '    line: ' , cleaned_line
            return False
    return True

#-------------------------------------------------------------------------------
def checkFile(file_name):
    f = file(file_name)

    # list to track bad lines
    bad_lines = []

    # loop through lines in file, and check for corrupt entries
    for line in f.readlines():
        entry_ok = checkEntry(line)
        if not entry_ok:
            bad_lines.append(cleanLine(line))

    print 'number of bad entries: ' , len(bad_lines)
    if len(bad_lines) > 0:
        return False

    return True

#-------------------------------------------------------------------------------
def main():
    eos_file_list_dir = '%s/EosFileLists/tnt_106/' % os.environ['BASE_WORK_DIR']
    file_list = glob.glob('%s/*.txt' % eos_file_list_dir)
    bad_files = []
    for f in file_list:
        print 'Checking file: ' , f
        file_ok = checkFile(f)
        if not file_ok:
            bad_files.append(f)
        print ''

    print 'number of bad files: ' , len(bad_files) , ' out of ' , len(file_list)
    for bf in bad_files:
        print '    ' , bf

#===============================================================================
if __name__ == '__main__':
    main()
