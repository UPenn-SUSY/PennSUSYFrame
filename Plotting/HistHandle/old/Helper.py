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
def getCharginoMass(sample_name):
    chargino_masses = {
                        'simplifiedModel_wA_slep_noWcascade_10' : 150.0,
                        'simplifiedModel_wA_slep_noWcascade_11' : 175.0,
                        'simplifiedModel_wA_slep_noWcascade_13' : 175.0,
                        'simplifiedModel_wA_slep_noWcascade_14' : 200.0,
                        'simplifiedModel_wA_slep_noWcascade_15' : 250.0,
                        'simplifiedModel_wA_slep_noWcascade_17' : 225.0,
                        'simplifiedModel_wA_slep_noWcascade_18' : 250.0,
                        'simplifiedModel_wA_slep_noWcascade_19' : 300.0,
                        'simplifiedModel_wA_slep_noWcascade_20' : 350.0,
                        'simplifiedModel_wA_slep_noWcascade_22' : 300.0,
                        'simplifiedModel_wA_slep_noWcascade_23' : 325.0,
                        'simplifiedModel_wA_slep_noWcascade_24' : 375.0,
                        'simplifiedModel_wA_slep_noWcascade_25' : 425.0,
                        'simplifiedModel_wA_slep_noWcascade_26' : 500.0,
                        'simplifiedModel_wA_slep_noWcascade_28' : 425.0,
                        'simplifiedModel_wA_slep_noWcascade_29' : 450.0,
                        'simplifiedModel_wA_slep_noWcascade_30' : 500.0,
                        'simplifiedModel_wA_slep_noWcascade_32' : 550.0,
                        'simplifiedModel_wA_slep_noWcascade_35' : 625.0,
                        'simplifiedModel_wA_slep_noWcascade_38' : 750.0,
                        'simplifiedModel_wA_slep_noWcascade_39' : 117.5,
                        'simplifiedModel_wA_slep_noWcascade_40' : 142.5,
                        'simplifiedModel_wA_slep_noWcascade_41' : 192.5,
                        'simplifiedModel_wA_slep_noWcascade_42' : 267.5,
                        'simplifiedModel_wA_slep_noWcascade_43' : 392.5,
                        'simplifiedModel_wA_slep_noWcascade_44' : 517.5,
                        'simplifiedModel_wA_slep_noWcascade_45' : 550.0,
                        'simplifiedModel_wA_slep_noWcascade_46' : 575.0,
                        'simplifiedModel_wA_slep_noWcascade_47' : 625.0,
                        'simplifiedModel_wA_slep_noWcascade_48' : 675.0,
                        'simplifiedModel_wA_slep_noWcascade_49' : 750.0,
                        'simplifiedModel_wA_slep_noWcascade_5'  : 112.5,
                        'simplifiedModel_wA_slep_noWcascade_50' : 642.5,
                        'simplifiedModel_wA_slep_noWcascade_51' : 675.0,
                        'simplifiedModel_wA_slep_noWcascade_52' : 700.0,
                        'simplifiedModel_wA_slep_noWcascade_53' : 750.0,
                        'simplifiedModel_wA_slep_noWcascade_53' : 750.0,
                        'simplifiedModel_wA_slep_noWcascade_7'  : 130.0,
                        'simplifiedModel_wA_slep_noWcascade_8'  : 155.0,
                        'simplifiedModel_wA_slep_noWcasc_54'    : 110.0,
                        'simplifiedModel_wA_slep_noWcasc_55'    : 135.0,
                        'simplifiedModel_wA_slep_noWcasc_56'    : 185.0,
                        'simplifiedModel_wA_slep_noWcasc_57'    : 260.0,
                        'simplifiedModel_wA_slep_noWcasc_58'    : 455.0,
                        'simplifiedModel_wA_slep_noWcasc_59'    : 112.5,
                        'simplifiedModel_wA_slep_noWcasc_60'    : 132.5,
                        'simplifiedModel_wA_slep_noWcasc_61'    : 157.5,
                        'simplifiedModel_wA_slep_noWcasc_62'    : 207.5,
                        'simplifiedModel_wA_slep_noWcasc_63'    : 282.5,
                        'simplifiedModel_wA_slep_noWcasc_64'    : 407.5,
                        'simplifiedModel_wA_slep_noWcasc_65'    : 470.0,
                        'simplifiedModel_wA_slep_noWcasc_66'    : 532.5,
                        'simplifiedModel_wA_slep_noWcasc_67'    : 562.5,
                        'simplifiedModel_wA_slep_noWcasc_68'    : 487.5,
                        'simplifiedModel_wA_slep_noWcasc_69'    : 512.5,
                        'simplifiedModel_wA_slep_noWcasc_70'    : 612.5,
                        'simplifiedModel_wA_slep_noWcasc_71'    : 800.0,
                        'simplifiedModel_wA_slep_noWcasc_72'    : 687.5,
                        'simplifiedModel_wA_slep_noWcasc_73'    : 875.0,
                        'simplifiedModel_wA_slep_noWcasc_74'    : 625.0,
                        'simplifiedModel_wA_slep_noWcasc_75'    : 687.5,
                        'simplifiedModel_wA_slep_noWcasc_76'    : 750.0,
                        'simplifiedModel_wA_slep_noWcasc_77'    : 812.5,
                        'simplifiedModel_wA_slep_noWcasc_78'    : 812.5,
                        'simplifiedModel_wA_slep_noWcasc_79'    : 875.0,
                        'simplifiedModel_wA_slep_noWcasc_80'    : 875.0,
                        'simplifiedModel_wA_noslep_lepW_1'      : 100.0,
                        'simplifiedModel_wA_noslep_lepW_2'      : 100.0,
                        'simplifiedModel_wA_noslep_lepW_3'      : 150.0,
                        'simplifiedModel_wA_noslep_lepW_4'      : 150.0,
                        'simplifiedModel_wA_noslep_lepW_5'      : 150.0,
                        'simplifiedModel_wA_noslep_lepW_6'      : 200.0,
                        'simplifiedModel_wA_noslep_lepW_7'      : 200.0,
                        'simplifiedModel_wA_noslep_lepW_8'      : 200.0,
                        'simplifiedModel_wA_noslep_lepW_9'      : 200.0,
                        'simplifiedModel_wA_noslep_lepW_10'     : 250.0,
                        'simplifiedModel_wA_noslep_lepW_11'     : 250.0,
                        'simplifiedModel_wA_noslep_lepW_12'     : 250.0,
                        'simplifiedModel_wA_noslep_lepW_13'     : 250.0,
                        'simplifiedModel_wA_noslep_lepW_14'     : 250.0,
                        'simplifiedModel_wA_noslep_lepW_15'     : 300.0,
                        'simplifiedModel_wA_noslep_lepW_16'     : 300.0,
                        'simplifiedModel_wA_noslep_lepW_17'     : 300.0,
                        'simplifiedModel_wA_noslep_lepW_18'     : 300.0,
                        'simplifiedModel_wA_noslep_lepW_19'     : 300.0,
                        'simplifiedModel_wA_noslep_lepW_20'     : 300.0,
                        'simplifiedModel_wA_noslep_lepW_21'     : 350.0,
                        'simplifiedModel_wA_noslep_lepW_22'     : 350.0,
                        'simplifiedModel_wA_noslep_lepW_23'     : 350.0,
                        'simplifiedModel_wA_noslep_lepW_24'     : 350.0,
                        'simplifiedModel_wA_noslep_lepW_25'     : 350.0,
                        'simplifiedModel_wA_noslep_lepW_26'     : 350.0,
                        'simplifiedModel_wA_noslep_lepW_27'     : 350.0,
                        'simplifiedModel_wA_noslep_lepW_28'     : 400.0,
                        'simplifiedModel_wA_noslep_lepW_29'     : 400.0,
                        'simplifiedModel_wA_noslep_lepW_30'     : 400.0,
                        'simplifiedModel_wA_noslep_lepW_31'     : 400.0,
                        'simplifiedModel_wA_noslep_lepW_32'     : 400.0,
                        'simplifiedModel_wA_noslep_lepW_33'     : 400.0,
                        'simplifiedModel_wA_noslep_lepW_34'     : 400.0,
                        'simplifiedModel_wA_noslep_lepW_35'     : 400.0,
                        'simplifiedModel_wA_noslep_lepW_36'     : 450.0,
                        'simplifiedModel_wA_noslep_lepW_37'     : 450.0,
                        'simplifiedModel_wA_noslep_lepW_38'     : 450.0,
                        'simplifiedModel_wA_noslep_lepW_39'     : 450.0,
                        'simplifiedModel_wA_noslep_lepW_40'     : 450.0,
                        'simplifiedModel_wA_noslep_lepW_41'     : 450.0,
                        'simplifiedModel_wA_noslep_lepW_42'     : 450.0,
                        'simplifiedModel_wA_noslep_lepW_43'     : 450.0,
                        'simplifiedModel_wA_noslep_lepW_44'     : 450.0,
                        'simplifiedModel_wA_noslep_lepW_45'     : 500.0,
                        'simplifiedModel_wA_noslep_lepW_46'     : 500.0,
                        'simplifiedModel_wA_noslep_lepW_47'     : 500.0,
                        'simplifiedModel_wA_noslep_lepW_48'     : 500.0,
                        'simplifiedModel_wA_noslep_lepW_49'     : 500.0,
                        'simplifiedModel_wA_noslep_lepW_50'     : 500.0,
                        'simplifiedModel_wA_noslep_lepW_51'     : 125.0,
                        'simplifiedModel_wA_noslep_lepW_52'     : 175.0,
                        'simplifiedModel_wA_noslep_lepW_53'     : 100.0,
                        'simplifiedModel_wA_noslep_lepW_54'     : 125.0,
                        'simplifiedModel_wA_noslep_lepW_55'     : 150.0,
                        'simplifiedModel_wA_noslep_lepW_56'     : 175.0,
                        'simplifiedModel_wA_noslep_lepW_57'     : 200.0,
                        'simplifiedModel_wA_noslep_lepW_58'     : 150.0,
                        'simplifiedModel_wA_noslep_lepW_59'     : 112.5,
                        'simplifiedModel_wA_noslep_lepW_60'     : 125.0,
                        'simplifiedModel_wA_noslep_lepW_61'     : 137.5,
                        'simplifiedModel_wA_noslep_lepW_62'     : 162.5,
                        'simplifiedModel_wA_noslep_lepW_63'     : 175.0,
                        'simplifiedModel_wA_noslep_lepW_64'     : 187.5,
                        'simplifiedModel_wA_noslep_lepW_65'     : 150.0,
                        'simplifiedModel_wA_noslep_lepW_66'     : 100.0,
                        'simplifiedModel_wA_noslep_lepW_67'     : 125.0,
                        'simplifiedModel_wA_noslep_lepW_68'     : 150.0,
                        'simplifiedModel_wA_noslep_lepW_69'     : 175.0,
                        'simplifiedModel_wA_noslep_lepW_70'     : 200.0,
                        'simplifiedModel_wA_noslep_lepW_71'     : 125.0,
                        'simplifiedModel_wA_noslep_lepW_72'     : 175.0,
                        'sM_wA_slep_C1N2_117_5_N1_82_5_2L'      : 117.5,
                        'sM_wA_slep_C1N2_135_0_N1_115_0_2L'     : 135.0,
                        'sM_wA_slep_C1N2_142_5_N1_107_5_2L'     : 142.5,
                        'sM_wA_slep_C1N2_185_0_N1_165_0_2L'     : 185.0,
                        'sM_wA_slep_C1N2_192_5_N1_157_5_2L'     : 192.5,
                        'sM_wA_slep_C1N2_260_0_N1_240_0_2L'     : 260.0,
                        '~TERM' : 0
                      }

    test = sample_name
    if '-' in test: test = test[:test.find('-')]
    # print 'test sample name: %s' % test
    assert test in chargino_masses
    return chargino_masses[test]



# ------------------------------------------------------------------------------
def getNeutralinoMass(sample_name):
    neutralino_masses = {
                          'simplifiedModel_wA_slep_noWcascade_5'  : 12.5,
                          'simplifiedModel_wA_slep_noWcascade_7'  : 30.0,
                          'simplifiedModel_wA_slep_noWcascade_8'  : 5.0,
                          'simplifiedModel_wA_slep_noWcascade_10' : 50.0,
                          'simplifiedModel_wA_slep_noWcascade_11' : 25.0,
                          'simplifiedModel_wA_slep_noWcascade_13' : 75.0,
                          'simplifiedModel_wA_slep_noWcascade_14' : 50.0,
                          'simplifiedModel_wA_slep_noWcascade_15' : 0.0,
                          'simplifiedModel_wA_slep_noWcascade_17' : 125.0,
                          'simplifiedModel_wA_slep_noWcascade_18' : 100.0,
                          'simplifiedModel_wA_slep_noWcascade_19' : 50.0,
                          'simplifiedModel_wA_slep_noWcascade_20' : 0.0,
                          'simplifiedModel_wA_slep_noWcascade_22' : 200.0,
                          'simplifiedModel_wA_slep_noWcascade_23' : 175.0,
                          'simplifiedModel_wA_slep_noWcascade_24' : 125.0,
                          'simplifiedModel_wA_slep_noWcascade_25' : 75.0,
                          'simplifiedModel_wA_slep_noWcascade_26' : 0.0,
                          'simplifiedModel_wA_slep_noWcascade_28' : 325.0,
                          'simplifiedModel_wA_slep_noWcascade_29' : 300.0,
                          'simplifiedModel_wA_slep_noWcascade_30' : 250.0,
                          'simplifiedModel_wA_slep_noWcascade_32' : 200.0,
                          'simplifiedModel_wA_slep_noWcascade_35' : 125.0,
                          'simplifiedModel_wA_slep_noWcascade_38' : 0.0,
                          'simplifiedModel_wA_slep_noWcascade_39' : 82.5,
                          'simplifiedModel_wA_slep_noWcascade_40' : 107.5,
                          'simplifiedModel_wA_slep_noWcascade_41' : 157.5,
                          'simplifiedModel_wA_slep_noWcascade_42' : 232.5,
                          'simplifiedModel_wA_slep_noWcascade_43' : 357.5,
                          'simplifiedModel_wA_slep_noWcascade_44' : 482.5,
                          'simplifiedModel_wA_slep_noWcascade_45' : 450.0,
                          'simplifiedModel_wA_slep_noWcascade_46' : 425.0,
                          'simplifiedModel_wA_slep_noWcascade_47' : 375.0,
                          'simplifiedModel_wA_slep_noWcascade_48' : 325.0,
                          'simplifiedModel_wA_slep_noWcascade_49' : 250.0,
                          'simplifiedModel_wA_slep_noWcascade_50' : 607.5,
                          'simplifiedModel_wA_slep_noWcascade_51' : 575.0,
                          'simplifiedModel_wA_slep_noWcascade_52' : 550.0,
                          'simplifiedModel_wA_slep_noWcascade_53' : 500.0,
                          'simplifiedModel_wA_slep_noWcasc_54'    : 90.0,
                          'simplifiedModel_wA_slep_noWcasc_55'    : 115.0,
                          'simplifiedModel_wA_slep_noWcasc_56'    : 165.0,
                          'simplifiedModel_wA_slep_noWcasc_57'    : 240.0,
                          'simplifiedModel_wA_slep_noWcasc_58'    : 420.0,
                          'simplifiedModel_wA_slep_noWcasc_59'    : 47.5,
                          'simplifiedModel_wA_slep_noWcasc_60'    : 67.5,
                          'simplifiedModel_wA_slep_noWcasc_61'    : 92.5,
                          'simplifiedModel_wA_slep_noWcasc_62'    : 142.5,
                          'simplifiedModel_wA_slep_noWcasc_63'    : 217.5,
                          'simplifiedModel_wA_slep_noWcasc_64'    : 342.5,
                          'simplifiedModel_wA_slep_noWcasc_65'    : 405.0,
                          'simplifiedModel_wA_slep_noWcasc_66'    : 467.5,
                          'simplifiedModel_wA_slep_noWcasc_67'    : 312.5,
                          'simplifiedModel_wA_slep_noWcasc_68'    : 387.5,
                          'simplifiedModel_wA_slep_noWcasc_69'    : 362.5,
                          'simplifiedModel_wA_slep_noWcasc_70'    : 262.5,
                          'simplifiedModel_wA_slep_noWcasc_71'    : 450.0,
                          'simplifiedModel_wA_slep_noWcasc_72'    : 187.5,
                          'simplifiedModel_wA_slep_noWcasc_73'    : 375.0,
                          'simplifiedModel_wA_slep_noWcasc_74'    : 0.0,
                          'simplifiedModel_wA_slep_noWcasc_75'    : 62.5,
                          'simplifiedModel_wA_slep_noWcasc_76'    : 125.0,
                          'simplifiedModel_wA_slep_noWcasc_77'    : 187.5,
                          'simplifiedModel_wA_slep_noWcasc_78'    : 62.5,
                          'simplifiedModel_wA_slep_noWcasc_79'    : 125.0,
                          'simplifiedModel_wA_slep_noWcasc_80'    : 0.0,
                          'simplifiedModel_wA_noslep_lepW_1'      : 0.0,
                          'simplifiedModel_wA_noslep_lepW_2'      : 50.0,
                          'simplifiedModel_wA_noslep_lepW_3'      : 0.0,
                          'simplifiedModel_wA_noslep_lepW_4'      : 50.0,
                          'simplifiedModel_wA_noslep_lepW_5'      : 100.0,
                          'simplifiedModel_wA_noslep_lepW_6'      : 0.0,
                          'simplifiedModel_wA_noslep_lepW_7'      : 50.0,
                          'simplifiedModel_wA_noslep_lepW_8'      : 100.0,
                          'simplifiedModel_wA_noslep_lepW_9'      : 150.0,
                          'simplifiedModel_wA_noslep_lepW_10'     : 0.0,
                          'simplifiedModel_wA_noslep_lepW_11'     : 50.0,
                          'simplifiedModel_wA_noslep_lepW_12'     : 100.0,
                          'simplifiedModel_wA_noslep_lepW_13'     : 150.0,
                          'simplifiedModel_wA_noslep_lepW_14'     : 200.0,
                          'simplifiedModel_wA_noslep_lepW_15'     : 0.0,
                          'simplifiedModel_wA_noslep_lepW_16'     : 50.0,
                          'simplifiedModel_wA_noslep_lepW_17'     : 100.0,
                          'simplifiedModel_wA_noslep_lepW_18'     : 150.0,
                          'simplifiedModel_wA_noslep_lepW_19'     : 200.0,
                          'simplifiedModel_wA_noslep_lepW_20'     : 250.0,
                          'simplifiedModel_wA_noslep_lepW_21'     : 0.0,
                          'simplifiedModel_wA_noslep_lepW_22'     : 50.0,
                          'simplifiedModel_wA_noslep_lepW_23'     : 100.0,
                          'simplifiedModel_wA_noslep_lepW_24'     : 150.0,
                          'simplifiedModel_wA_noslep_lepW_25'     : 200.0,
                          'simplifiedModel_wA_noslep_lepW_26'     : 250.0,
                          'simplifiedModel_wA_noslep_lepW_27'     : 300.0,
                          'simplifiedModel_wA_noslep_lepW_28'     : 0.0,
                          'simplifiedModel_wA_noslep_lepW_29'     : 50.0,
                          'simplifiedModel_wA_noslep_lepW_30'     : 100.0,
                          'simplifiedModel_wA_noslep_lepW_31'     : 150.0,
                          'simplifiedModel_wA_noslep_lepW_32'     : 200.0,
                          'simplifiedModel_wA_noslep_lepW_33'     : 250.0,
                          'simplifiedModel_wA_noslep_lepW_34'     : 300.0,
                          'simplifiedModel_wA_noslep_lepW_35'     : 350.0,
                          'simplifiedModel_wA_noslep_lepW_36'     : 0.0,
                          'simplifiedModel_wA_noslep_lepW_37'     : 50.0,
                          'simplifiedModel_wA_noslep_lepW_38'     : 100.0,
                          'simplifiedModel_wA_noslep_lepW_39'     : 150.0,
                          'simplifiedModel_wA_noslep_lepW_40'     : 200.0,
                          'simplifiedModel_wA_noslep_lepW_41'     : 250.0,
                          'simplifiedModel_wA_noslep_lepW_42'     : 300.0,
                          'simplifiedModel_wA_noslep_lepW_43'     : 350.0,
                          'simplifiedModel_wA_noslep_lepW_44'     : 400.0,
                          'simplifiedModel_wA_noslep_lepW_45'     : 0.0,
                          'simplifiedModel_wA_noslep_lepW_46'     : 100.0,
                          'simplifiedModel_wA_noslep_lepW_47'     : 200.0,
                          'simplifiedModel_wA_noslep_lepW_48'     : 300.0,
                          'simplifiedModel_wA_noslep_lepW_49'     : 400.0,
                          'simplifiedModel_wA_noslep_lepW_50'     : 450.0,
                          'simplifiedModel_wA_noslep_lepW_51'     : 0.0,
                          'simplifiedModel_wA_noslep_lepW_52'     : 0.0,
                          'simplifiedModel_wA_noslep_lepW_53'     : 25.0,
                          'simplifiedModel_wA_noslep_lepW_54'     : 25.0,
                          'simplifiedModel_wA_noslep_lepW_55'     : 25.0,
                          'simplifiedModel_wA_noslep_lepW_56'     : 25.0,
                          'simplifiedModel_wA_noslep_lepW_57'     : 25.0,
                          'simplifiedModel_wA_noslep_lepW_58'     : 37.5,
                          'simplifiedModel_wA_noslep_lepW_59'     : 50.0,
                          'simplifiedModel_wA_noslep_lepW_60'     : 50.0,
                          'simplifiedModel_wA_noslep_lepW_61'     : 50.0,
                          'simplifiedModel_wA_noslep_lepW_62'     : 50.0,
                          'simplifiedModel_wA_noslep_lepW_63'     : 50.0,
                          'simplifiedModel_wA_noslep_lepW_64'     : 50.0,
                          'simplifiedModel_wA_noslep_lepW_65'     : 62.5,
                          'simplifiedModel_wA_noslep_lepW_66'     : 75.0,
                          'simplifiedModel_wA_noslep_lepW_67'     : 75.0,
                          'simplifiedModel_wA_noslep_lepW_68'     : 75.0,
                          'simplifiedModel_wA_noslep_lepW_69'     : 75.0,
                          'simplifiedModel_wA_noslep_lepW_70'     : 75.0,
                          'simplifiedModel_wA_noslep_lepW_71'     : 100.0,
                          'simplifiedModel_wA_noslep_lepW_72'     : 100.0,
                          'sM_wA_slep_C1N2_117_5_N1_82_5_2L'      : 82.5,
                          'sM_wA_slep_C1N2_135_0_N1_115_0_2L'     : 115.0,
                          'sM_wA_slep_C1N2_142_5_N1_107_5_2L'     : 107.5,
                          'sM_wA_slep_C1N2_185_0_N1_165_0_2L'     : 165.0,
                          'sM_wA_slep_C1N2_192_5_N1_157_5_2L'     : 157.5,
                          'sM_wA_slep_C1N2_260_0_N1_240_0_2L'     : 240.0,
                          '~TERM'                                 : 0
                        }

    test = sample_name
    if '-' in test: test = test[:test.find('-')]
    assert test in neutralino_masses
    return neutralino_masses[test]

# ------------------------------------------------------------------------------
def genLegendLabel(key):
    if 'simplifiedModel_wA' in key or 'sM_wA_slep_C1N2' in key:
        sample_name = key.split('.')[1]
        return 'm(#chi_{2}^{0}/#chi_{1}^{#pm}, #chi_{1}^{0}) = %s, %s GeV' \
                % ( getCharginoMass(sample_name)
                  , getNeutralinoMass(sample_name)
                  )

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
