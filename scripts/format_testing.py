#!/usr/bin/env python
# ==============================================================================
# = Script to do basic tests regarding formatting rules.  These include:
# =     1: No Tabs! (accetpable in certain file types)
# =     2: No Bad Spaces
# =     3: # characters/line <= 80
# =     4: Divider lines span full line (TODO)
# =     5: ...
# ==============================================================================


import sys
import os.path
import optparse
import time

# ------------------------------------------------------------------------------
def chompNewLines(line):
    line = line.rstrip('\n')
    return line

# ------------------------------------------------------------------------------
def findTabs(f_name):
    print '--------------------------------------------------------------------'
    print "Searching for tabs in: %s\n" % f_name
    num_tab_lines = 0

    f = file(f_name, 'r')
    for i, l in enumerate(f):
        if not l.find('\t') == -1:
            num_tab_lines += 1
            print 'Found tab! Line: %d' % (i+1)
            print l
            print ''

    print 'Found %d lines with tabs\n' % num_tab_lines

# ------------------------------------------------------------------------------
def findBadSpaces(f_name):
    print '--------------------------------------------------------------------'
    print "Searching for bad spaces in: %s\n" % f_name
    num_bad_space_lines = 0

    f = file(f_name, 'r')
    for i, l in enumerate(f):
        l = chompNewLines(l)
        if len(l) == 0: continue
        if (l[-1] == ' ' or l[-1] == '\t'):
            num_bad_space_lines += 1
            print 'Found bad space! Line: %d' % (i+1)
            print l
            print ''

    print 'Found %d lines with bad spaces\n' % num_bad_space_lines

# ------------------------------------------------------------------------------
def findLongLines(f_name, max_len = 80):
    print '--------------------------------------------------------------------'
    print "Searching for long lines in: %s\n" % f_name
    num_long_lines = 0

    f = file(f_name, 'r')
    for i, l in enumerate(f):
        l = chompNewLines(l)
        if len(l) > max_len:
            num_long_lines += 1
            print 'Found long line! Line: %d (%d chars)' % ((i+1), len(l))
            print l
            print ''

    print 'Found %d long lines!\n' % num_long_lines

# ------------------------------------------------------------------------------
def main():
    f_name = sys.argv[1]
    findTabs(f_name)
    findBadSpaces(f_name)
    findLongLines(f_name)

# ==============================================================================
if __name__ == '__main__':
    main()
