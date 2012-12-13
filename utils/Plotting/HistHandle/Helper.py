#!/usr/bin/env python

import sys
import os.path
import optparse
import time
import random
import string
from array import array

import ROOT
import rootlogon
import metaroot

import HistHandle

# ==============================================================================
# = Helper functions for interpretting the HistHandle objects
# ==============================================================================
# # ----------------------------------------------------------------------------
# def get_files(dict_list):
#     """
#     function to open root files listed in the dict_list
#     """
#     # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#     for d in dict_list:
#         # Get plot options from xml
#         d['plot_opt'] = metaroot.hist.PlotOptions( line_color   = int(d['line_color'])
#                                                  , fill_color   = int(d['fill_color'])
#                                                  , marker_color = int(d['fill_color'])
#                                                  , marker_style = ROOT.kFullCircle
#                                                  , line_width   = 2
#                                                  )
#
#         # Get files names from xml, and open the root files
#         for inp in d['inputs']:
#             inp['file'] = ROOT.TFile(inp['file_name'])

# ------------------------------------------------------------------------------
def get_list_of_keys(d):
    """
    get a list of keys from a TDirectory
    """
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    list_of_hists = [key.GetName() for key in d.GetListOfKeys()]
    return list_of_hists

# ------------------------------------------------------------------------------
def get_list_of_dirs(d):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    if not isinstance(d, list): d = [d]

    key_list_ref = None
    for f in d:
        print 'Checking key list in file: %s' % f.GetName()
        key_list_test = set(get_list_of_keys(f))
        if key_list_ref == None:
            key_list_ref = key_list_test
        assert key_list_test == key_list_ref
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
def getNeutralinoMass(sample_name):
    chargino_masses = { 'simplifiedModel_wA_slep_noWcascade_5':  112.5
                      , 'simplifiedModel_wA_slep_noWcascade_7':  130.0
                      , 'simplifiedModel_wA_slep_noWcascade_8':  155.0
                      , 'simplifiedModel_wA_slep_noWcascade_10': 150.0
                      , 'simplifiedModel_wA_slep_noWcascade_11': 175.0
                      , 'simplifiedModel_wA_slep_noWcascade_13': 175.0
                      , 'simplifiedModel_wA_slep_noWcascade_14': 200.0
                      , 'simplifiedModel_wA_slep_noWcascade_15': 250.0
                      , 'simplifiedModel_wA_slep_noWcascade_17': 225.0
                      , 'simplifiedModel_wA_slep_noWcascade_18': 250.0
                      , 'simplifiedModel_wA_slep_noWcascade_19': 300.0
                      , 'simplifiedModel_wA_slep_noWcascade_20': 350.0
                      , 'simplifiedModel_wA_slep_noWcascade_22': 300.0
                      , 'simplifiedModel_wA_slep_noWcascade_23': 325.0
                      , 'simplifiedModel_wA_slep_noWcascade_24': 375.0
                      , 'simplifiedModel_wA_slep_noWcascade_25': 425.0
                      , 'simplifiedModel_wA_slep_noWcascade_26': 500.0
                      , 'simplifiedModel_wA_slep_noWcascade_28': 425.0
                      , 'simplifiedModel_wA_slep_noWcascade_29': 450.0
                      , 'simplifiedModel_wA_slep_noWcascade_30': 500.0
                      , 'simplifiedModel_wA_slep_noWcascade_32': 550.0
                      , 'simplifiedModel_wA_slep_noWcascade_35': 625.0
                      , 'simplifiedModel_wA_slep_noWcascade_38': 750.0
                      , 'simplifiedModel_wA_slep_noWcascade_39': 117.5
                      , 'simplifiedModel_wA_slep_noWcascade_40': 142.5
                      , 'simplifiedModel_wA_slep_noWcascade_41': 192.5
                      , 'simplifiedModel_wA_slep_noWcascade_42': 267.5
                      , 'simplifiedModel_wA_slep_noWcascade_43': 392.5
                      , 'simplifiedModel_wA_slep_noWcascade_44': 517.5
                      , 'simplifiedModel_wA_slep_noWcascade_45': 550.0
                      , 'simplifiedModel_wA_slep_noWcascade_46': 575.0
                      , 'simplifiedModel_wA_slep_noWcascade_47': 625.0
                      , 'simplifiedModel_wA_slep_noWcascade_48': 675.0
                      , 'simplifiedModel_wA_slep_noWcascade_49': 750.0
                      , 'simplifiedModel_wA_slep_noWcascade_50': 642.5
                      , 'simplifiedModel_wA_slep_noWcascade_51': 675.0
                      , 'simplifiedModel_wA_slep_noWcascade_52': 700.0
                      , 'simplifiedModel_wA_slep_noWcascade_53': 750.0
                      }
    test = sample_name
    if '-' in test: test = test[:test.find('-')]
    assert test in chargino_masses
    return chargino_masses[test]

# ------------------------------------------------------------------------------
def getCharginoMass(sample_name):
    neutralino_masses = { 'simplifiedModel_wA_slep_noWcascade_5':   12.5
                        , 'simplifiedModel_wA_slep_noWcascade_7':   30.0
                        , 'simplifiedModel_wA_slep_noWcascade_8':    5.0
                        , 'simplifiedModel_wA_slep_noWcascade_10':  50.0
                        , 'simplifiedModel_wA_slep_noWcascade_11':  25.0
                        , 'simplifiedModel_wA_slep_noWcascade_13':  75.0
                        , 'simplifiedModel_wA_slep_noWcascade_14':  50.0
                        , 'simplifiedModel_wA_slep_noWcascade_15':   0.0
                        , 'simplifiedModel_wA_slep_noWcascade_17': 125.0
                        , 'simplifiedModel_wA_slep_noWcascade_18': 100.0
                        , 'simplifiedModel_wA_slep_noWcascade_19':  50.0
                        , 'simplifiedModel_wA_slep_noWcascade_20':   0.0
                        , 'simplifiedModel_wA_slep_noWcascade_22': 200.0
                        , 'simplifiedModel_wA_slep_noWcascade_23': 175.0
                        , 'simplifiedModel_wA_slep_noWcascade_24': 125.0
                        , 'simplifiedModel_wA_slep_noWcascade_25':  75.0
                        , 'simplifiedModel_wA_slep_noWcascade_26':   0.0
                        , 'simplifiedModel_wA_slep_noWcascade_28': 325.0
                        , 'simplifiedModel_wA_slep_noWcascade_29': 300.0
                        , 'simplifiedModel_wA_slep_noWcascade_30': 250.0
                        , 'simplifiedModel_wA_slep_noWcascade_32': 200.0
                        , 'simplifiedModel_wA_slep_noWcascade_35': 125.0
                        , 'simplifiedModel_wA_slep_noWcascade_38':   0.0
                        , 'simplifiedModel_wA_slep_noWcascade_39':  82.5
                        , 'simplifiedModel_wA_slep_noWcascade_40': 107.5
                        , 'simplifiedModel_wA_slep_noWcascade_41': 157.5
                        , 'simplifiedModel_wA_slep_noWcascade_42': 232.5
                        , 'simplifiedModel_wA_slep_noWcascade_43': 357.5
                        , 'simplifiedModel_wA_slep_noWcascade_44': 482.5
                        , 'simplifiedModel_wA_slep_noWcascade_45': 450.0
                        , 'simplifiedModel_wA_slep_noWcascade_46': 425.0
                        , 'simplifiedModel_wA_slep_noWcascade_47': 375.0
                        , 'simplifiedModel_wA_slep_noWcascade_48': 325.0
                        , 'simplifiedModel_wA_slep_noWcascade_49': 250.0
                        , 'simplifiedModel_wA_slep_noWcascade_50': 607.5
                        , 'simplifiedModel_wA_slep_noWcascade_51': 575.0
                        , 'simplifiedModel_wA_slep_noWcascade_52': 550.0
                        , 'simplifiedModel_wA_slep_noWcascade_53': 500.0
                        }
    test = sample_name
    if '-' in test: test = test[:test.find('-')]
    assert test in neutralino_masses
    return neutralino_masses[test]

