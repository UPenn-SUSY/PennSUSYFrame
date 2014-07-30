#!/usr/bin/env python

import sys
import os.path
import optparse
import time
import random
import string
from array import array

import ROOT

import HistHandle as hh

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
    if 'TotalNumEvents' in list_of_hists:
        list_of_hists.remove('TotalNumEvents')
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
def getListOfDirs(d):
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
def getListOfHists(d):
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
        hist_handle.append( hh.Handle.HistHandle( dir_name
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

# ------------------------------------------------------------------------------
class MetaLegend(ROOT.TLegend):
    """
    A better TLegend class that increases in height as you call AddEntry.
    -- stolen from Ryan Reece
    """
#______________________________________________________________________________
    def __init__( self
                , width=0.10
                , height=0.04
                , x1=None
                , y1=None
                , x2=None
                , y2=None
                , border=0
                , fill_color=0
                , fill_style=0
                ):
#        assert (x1 == y1 == None) or (x2 == y2 == None)
#        assert (x1 != None and y1 != None) or (x2 != None and y2 != None)

        if x1 == x2 == None:
            x2 = 0.93
            x1 = x2 - width
        elif x1 == None:
            x1 = x2 - width
        elif x2 == None:
            x2 = x1 + width

        if y1 == y2 == None:
            y2 = 0.93
            y1 = y2 - width
        elif y1 == None:
            y1 = y2 - width
        elif y2 == None:
            y2 = y1 + width

        ROOT.TLegend.__init__(self, x1, y1, x2, y2)
        self.SetBorderSize(border)
        self.SetFillColor(fill_color)
        self.SetFillStyle(fill_style)
        self.width = width
        self.height = height # per entry
        self._nentries = 0
        self._has_drawn = False
#______________________________________________________________________________
    def AddEntry(self, obj, label='', option='P'):
        self._nentries += 1
        self.resize()
        ROOT.TLegend.AddEntry(self, obj, label, option)
#______________________________________________________________________________
    def Draw(self):
        self.resize()
        ROOT.TLegend.Draw(self)
        self._has_drawn = True
#______________________________________________________________________________
    def resize(self):
        if self._has_drawn:
            y2 = self.GetY2NDC()
            self.SetY1NDC(y2 - (self.height*self._nentries) - 0.01)
        else:
            y2 = self.GetY2()
            self.SetY1(y2 - (self.height*self._nentries) - 0.01)

# ------------------------------------------------------------------------------
def makeLegend( hist_list
              , label_list
              , draw_options = hh.default
              , width = 0.15
              , height = 0.05
              , x1 = None
              , x2 = None
              , y1 = None
              , y2 = None
              ):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    if draw_options is hh.default:
        draw_options = ['P']*len(hist_list)
    if not isinstance(draw_options, list):
        draw_options = [draw_options]*len(hist_list)
    assert len(hist_list) == len(label_list) == len(draw_options)
    leg = MetaLegend(width=width, height=height, x1=x1, y1=y1, x2=x2, y2=y2)
    for h, lab, opt in zip(hist_list, label_list, draw_options):
        if not opt in ('P', 'F', 'L'):
            ## assume opt is of the same format as draw_options used with Draw
            if opt.count('P'):
                if opt.count('E'):
                    opt = 'PL'
                else:
                    opt = 'P'
            else: # '', 'HIST', etc.
                opt = 'F'
        leg.AddEntry(h, label=lab, option=opt)
    return leg

# ------------------------------------------------------------------------------
def recoverOverflow(h):
    # get the total number of bins and entries
    total_bins = h.GetNbinsX()
    total_entries = h.GetEntries()

    # find the bin edges
    x_bins = [h.GetBinLowEdge(i+1) for i in xrange(total_bins)]

    # get the number of entries from the overflow bin
    overflow = h.GetBinContent(total_bins+1)

    # move the overflow bin to the last bin in the plot
    h.SetBinContent(total_bins+1, 0)
    h.Fill(x_bins[total_bins-1], overflow)

    # fix the number of entries
    h.SetEntries(total_entries)

