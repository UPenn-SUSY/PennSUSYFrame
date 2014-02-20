#!/usr/bin/env python

import sys
import os.path
import optparse
import time
import random
import string
from array import array

import ROOT

import HistHandle

# ==============================================================================
# = Helper functions for interpretting the HistHandle objects
# ==============================================================================
# ------------------------------------------------------------------------------
def get_list_of_keys(d):
    """
    get a list of keys from a TDirectory
    """
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    list_of_hists = [key.GetName() for key in d.GetListOfKeys()]
    return list_of_hists

# ------------------------------------------------------------------------------
def isGoodDir(key):
    return True

    if 'leppt' not in key: return False
    if 'jetpt' not in key: return False

    if 'leppt10'   in key: return False
    if 'leppt12.5'   in key: return False
    if 'jetpt30'   in key: return False
    if 'metrel20'  in key: return False
    if 'metrel40'  in key: return False
    if 'dphill0.6' in key: return False
    if 'dphill0.7' in key: return False
    if 'mt215'     in key: return False
    if 'mt220'     in key: return False
    if 'ptll40'    in key: return False
    if 'ptll60'    in key: return False

    return True

# ------------------------------------------------------------------------------
def removeBadDirs(key_list):
    new_key_list = sorted([kl for kl in key_list if isGoodDir(kl)])
    print 'Removed bad dirs -- old: %s  new: %s' % (len(key_list), len(new_key_list))
    return new_key_list

# ------------------------------------------------------------------------------
def get_list_of_dirs(d):
    if not isinstance(d, list): d = [d]

    key_list_ref = None
    for f in d:
        print 'Checking key list in file: %s' % f.GetName()
        key_list_test = set(get_list_of_keys(f))
        key_list_test = removeBadDirs(key_list_test)

        if key_list_ref == None:
            key_list_ref = key_list_test
        if not key_list_test == key_list_ref:
            print 'Key list in %s does not match reference' % f.GetName()
            print '    Number differences: %d:' % len( list( set(key_list_ref)
                                                           - set(key_list_test)
                                                           )
                                                     )

            print_details = confirm('print details', False)
            if print_details:
                for ref, test in zip(key_list_ref, key_list_test):
                    print 'ref: %s -- test: %s -- diff: %s' % (ref, test, (ref!=test))

            try_anyway = confirm( 'Try anyway?', False)
            if not try_anyway:
                assert False

    print '\nAll input files have the same directory structure!\n'
    return list(key_list_ref)

# ------------------------------------------------------------------------------
def get_list_of_hists(d):
    """
    get a list of histograms in a TDirectory d
    TODO update this function when directory structure gets a little more complicated
    """
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    return get_list_of_keys(d)

# ------------------------------------------------------------------------------
def check_structure(num_dicts, denom_dicts):
    """
    Check that the two input collections are compatable
    """
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    print '----------------------------------------'
    print 'check_structure()'
    ROOT.gDirectory.ls()
    # Get list of keys in a reference file
    ref_dirs = get_list_of_dirs(num_dicts[0])

    print '----------------------------------------'
    print 'after getting list of dirs'
    ROOT.gDirectory.ls()

    # assert all files have the same key structure
    for d in num_dicts:
        assert get_list_of_dirs(d) == ref_dirs

    print '----------------------------------------'
    print 'after checking num dirs'
    ROOT.gDirectory.ls()

    for d in denom_dicts:
        assert get_list_of_dirs(d) == ref_dirs
    print '----------------------------------------'
    print 'after checking denom dirs'
    ROOT.gDirectory.ls()

    # check all dirs agains ref_dir
    ref_dirs = list(ref_dirs)
    for d in ref_dirs:
        ref_hists = get_list_of_hists(num_dicts[0]['inputs'][0]['file'].GetDirectory(d))
        # print 'ref_hists: %s' % ref_hists

        # assert all files have the same histograms in this directory
        for nd in num_dicts:
            for inp in nd['inputs']:
                # assert get_list_of_hists(inp['file'].GetDirectory(d)) == ref_hists
                test_hists = get_list_of_hists(inp['file'].GetDirectory(d))
                assert test_hists == ref_hists
                # test_hists.Delete()
        for dd in denom_dicts:
            for inp in dd['inputs']:
                assert get_list_of_hists(inp['file'].GetDirectory(d)) == ref_hists

    print '----------------------------------------'
    print 'end of check_structure()'
    ROOT.gDirectory.ls()


# ------------------------------------------------------------------------------
def get_histograms( input_dict
                  , dir_name
                  , hist_name
                  , do_scale_to_lumi = False
                  , target_lumi = 1.
                  ):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    if not isinstance(input_dict, list):
        input_dict = [input_dict]

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # print "Getting histograms for %s - %s" % (dir_name, hist_name)
    hist_handle = []
    for inp_dict in input_dict:
        dict_name = inp_dict['name']
        key = '%s__%s__%s' % (dir_name, hist_name, dict_name)
        hist_handle.append( HistHandle( dir_name
                                      , hist_name
                                      , inp_dict
                                      , do_scale_to_lumi
                                      , target_lumi
                                      )
                          )
    # print '\tdone getting histograms -- %s - %s' % (dir_name, hist_name)

    return hist_handle

# ------------------------------------------------------------------------------
def flatten(l, level = 0):
    """
    takes a list of lists, and flattens into a single list
    """
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    flat_l = []
    if isinstance(l, list):
        for e in l:
            flat_l += flatten(e)
    else:
        flat_l = [l]

    return flat_l

# ------------------------------------------------------------------------------
def genLegendLabel(key):
    return key

# ------------------------------------------------------------------------------
def confirm(prompt = None, resp = False):
    if prompt is None:
        prompt = 'Confirm'

    if resp:
        prompt = '%s [%s]|%s: ' % (prompt, 'y', 'n')
    else:
        prompt = '%s [%s]|%s: ' % (prompt, 'n', 'y')

    while True:
        ans = raw_input(prompt)
        if not ans:
            return resp
        if ans not in ['y', 'Y', 'n', 'N']:
            print 'please enter y or n'
            continue
        if ans == 'y' or ans == 'Y':
            return True
        if ans == 'n' or ans == 'N':
            return False
