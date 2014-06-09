#!/usr/bin/env python
# ------------------------------------------------------------------------------
# - usage:
# -      ./scripts/AutoHadd.py <path_to_dir_to_hadd>
# ------------------------------------------------------------------------------

import sys
import os
import glob
import re
import subprocess
import ROOT

# ------------------------------------------------------------------------------
def displayHelp():
    print "Usage:"
    print "  ./AutoHadd.py <path_to_file>"
    print ""

# ------------------------------------------------------------------------------
def getListOfTagsToHadd(dir):
    print "Getting list of tags in directory: %s" % dir
    list_of_files = glob.glob("%s/*_of_*.root" % dir)

    list_of_tags = []
    for lof in list_of_files:
        this_tag = lof.lstrip('%s/' % dir)
        this_tag = re.sub('\.[0-9]*_of_[0-9]*\.root', '', this_tag)

        if not this_tag in list_of_tags:
            list_of_tags.append(this_tag)
    return list_of_tags

# ------------------------------------------------------------------------------
def getNumEventsFromFile(root_file):
    print 'getting num events from file: %s' % root_file
    f = ROOT.TFile(root_file)
    tne = f.Get('TotalNumEvents')[0]
    f.Close()
    return tne

# ------------------------------------------------------------------------------
def copyDir(source_file, target_file, dir_name):
    # mkdir in target file
    target_file.cd()
    target_dir = target_file.mkdir(dir_name)
    target_dir.cd()

    # get source directory and list of keys
    source_dir = source_file.Get(dir_name)
    list_of_keys = [el.GetName() for el in source_dir.GetListOfKeys()]

    # loop over keys, and write all elements to target directory in target file
    for key in list_of_keys:
        obj = source_dir.Get(key)
        target_dir.cd()
        obj.Write()

# ------------------------------------------------------------------------------
def makeNewCleanFile(messy_file_name, new_file_name, total_num_events):
    # get messy file
    messy_file = ROOT.TFile(messy_file_name)
    messy_file.ReadAll()

    # make new file
    new_file = ROOT.TFile(new_file_name, 'recreate')

    # loop over all elements in messy file
    for element in messy_file.GetListOfKeys():
        # skip TotalNumEvents elements -- we will write this by hand
        element_name = element.GetName()
        if element_name == "TotalNumEvents": continue
        print 'element name: ', element_name

        # else this is a directory -- copy it!
        copyDir(messy_file, new_file, element_name)

    # write the TotalNumEvents object to new file
    new_file.cd('/')
    total_num_events_object = ROOT.TVectorF(1)
    total_num_events_object[0] = total_num_events
    total_num_events_object.Write('TotalNumEvents')

    # clean up
    new_file.Close()
    messy_file.Close()

# ------------------------------------------------------------------------------
def haddFilesMatchingTag(dir, list_of_tags):
    print 'auto hadding files in directory: %s' % dir

    for lot in list_of_tags:
        print 'tag: %s' % lot
        messy_file_name = '%s/%s.messy_version.root' % (dir, lot)
        new_file_name = '%s/%s.root' % (dir, lot)

        # Create messy version of file using hadd
        command_list = ['hadd', messy_file_name]
        this_file_list = glob.glob('%s/%s.*_of_*.root' % (dir, lot))
        command_list.extend(this_file_list)
        subprocess.call(command_list)

        # get the total number of events from list of files
        total_num_events = 0
        for tfl in this_file_list:
            total_num_events += getNumEventsFromFile(tfl)
            print '  ', total_num_events

        # make a new clean file with one TotalNumEvents entry
        makeNewCleanFile(messy_file_name, new_file_name, total_num_events)

# ------------------------------------------------------------------------------
def runAutoHaddOnDir(target_dir):
    # check that directory exists
    if not os.path.isdir(target_dir):
        print '%s is not a real directory' % target_dir
        displayHelp()
        return

    # get list of tags
    list_of_tags = getListOfTagsToHadd(target_dir)
    print list_of_tags

    # auto-hadd files in directory (matching tags in list_of_tags)
    if len(list_of_tags) > 0:
        haddFilesMatchingTag(target_dir, list_of_tags)

# ------------------------------------------------------------------------------
def main():
    # ensure input is provided
    if len(sys.argv) == 1:
        displayHelp()
        return

    # get directory path from user input
    target_dir = sys.argv[1]

    runAutoHaddOnDir(target_dir)

# ==============================================================================
if __name__ == "__main__":
    main()