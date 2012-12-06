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

import HistObjects as ho
import HistPainter as hp

# ==============================================================================
class HistHandle(object):
    """
    docstring
    """
    # --------------------------------------------------------------------------
    def __init__( self
                , directory
                , hist_name
                , hist_info
                , input_files
                ):
        """
        construtor
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        self.directory = directory
        self.name = hist_name
        self.hist_name = '%s__%s' % (hist_name, directory)
        self.hist_info = hist_info

        # create random string to be used as a unique tag
        unique_tag = ''.join(random.choice(string.ascii_lowercase) \
                for x in xrange(5))
        self.unique_name = '%s__%s__%s__%s' % ( hist_info.name
                                              , directory
                                              , hist_name
                                              , unique_tag
                                              )

        self.hist = None

        if not isinstance(input_files, list):
            input_files = [input_files]
        for inp in input_files:
            self.addInputFile(inp)

    def __del__(self):
        """
        destructor
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        if not self.hist == None:
            self.hist.Delete()

    # --------------------------------------------------------------------------
    def addInputFile(self, input_file):
        """
        docstring
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        assert type(input_file) == ROOT.TFile

        # get hist from file
        print 'Getting hist: %s from directory: %s' % ( self.hist_name
                                                      , self.directory
                                                      )
        d = input_file.GetDirectory(self.directory)
        h = d.Get(self.hist_name)
        h.Sumw2()

        # add hist to HistHandle internal histogram
        if self.hist == None:
            self.hist = h.Clone(self.unique_name)
            self.hist_info.setHistStyle(self.hist)
        else:
            self.hist.Add(h)

        # manually delete hist because ROOT is dumb and holds on to these
        h.Delete()

    # --------------------------------------------------------------------------
    def scale(self, sf):
        """
        scale this hist handle by sf
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        print 'Scaling %s: %f' % (self.unique_name, sf)
        self.hist.Scale(sf)

    # --------------------------------------------------------------------------
    def scaleTo(self, target):
        """
        scale this hist handle such that the integral is equal to target
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        print 'Scaling %s to target: %f' % (self.unique_name, target)
        old_int = self.hist.Integral()
        sf = target/old_int
        self.hist.Scale(sf)

# ==============================================================================
class HistMerger(object):
    """
    docstring
    """
    # --------------------------------------------------------------------------
    def __init__( self
                , directory
                , hist_name
                # , hist_type
                , hist_handle_dict
                , hist_info
                ):
        """
        construtor
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        self.directory = directory
        self.hist_name = hist_name

        # create random string to be used as a unique tag
        unique_tag = ''.join(random.choice(string.ascii_lowercase) \
                for x in xrange(5))
        self.unique_name = '%s__%s__%s' % ( directory
                                          , hist_name
                                          , unique_tag
                                          )
        self.hist_info = hist_info

        self.hist_handles  = {}
        self.hist_list  = []
        self.hist_sum   = None
        self.hist_stack = None
        self.error_band = None

        if not isinstance (hist_handle_dict, dict):
            sys.exit('hist_handle_dict is not of type dictionary')
        for key in hist_handle_dict:
            self.addHistHandle(hist_handle_dict[key], key)

    # --------------------------------------------------------------------------
    def __del__(self):
        """
        destructor
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        if not self.hist_sum == None:
            self.hist_sum.Delete()
        if not self.hist_stack == None:
            self.hist_stack.Delete()
        if not self.error_band == None:
            # TODO check this is the correct format
            self.error_band.Delete()

    # --------------------------------------------------------------------------
    def addHistHandle(self, hist_handle, label):
        """
        docstring
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        assert isinstance(hist_handle, HistHandle)
        self.hist_handles[label] = hist_handle

    # --------------------------------------------------------------------------
    def genMergedHist(self):
        """
        docstring
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        # clean up old histograms before making new ones
        # TODO check this doesn't cause memory leak
        # for h in self.hist_list:
        #     h.Delete()
        self.hist_list = []

        if not self.hist_sum == None:
            self.hist_sum.Delete()
        if not self.hist_stack == None:
            self.hist_stack.Delete()

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        # generate hist list
        for key in self.hist_handles:
            hh = self.hist_handles[key]
            self.hist_list.append(hh.hist)

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        # generate sum hist
        for key in self.hist_handles:
            hh = self.hist_handles[key]

            if self.hist_sum == None:
                self.hist_sum = hh.hist.Clone('%s_sum' % self.unique_name)
                self.hist_info.setHistStyle(self.hist_sum)
            else:
                self.hist_sum.Add(hh.hist)

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        # generate stacked hist
        self.hist_stack = ROOT.THStack('%s_stack' % self.unique_name
                                      , 'stack'
                                      )
        key_list = []
        for key in self.hist_handles:
            key_list.append(key)

        for key in reversed(key_list):
            hh = self.hist_handles[key]
            self.hist_stack.Add(hh.hist)

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        # generate error band
        self.genErrorBand(3004, 1)

    # -------------------------------------------------------------------------
    def genErrorBand(self, fill_style, fill_color):
        """
        docstring
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        x = []
        y = []
        ex = []
        ey = []

        num_bins = self.hist_sum.GetXaxis().GetNbins()
        for x_itr in xrange(1, num_bins+1):
            x.append( self.hist_sum.GetXaxis().GetBinCenter(x_itr) )
            y.append( self.hist_sum.GetBinContent(x_itr) )

            ex.append( self.hist_sum.GetBinWidth(x_itr)/2 )
            ey.append( self.hist_sum.GetBinError(x_itr) )

        self.error_band = ROOT.TGraphErrors( num_bins
                                           , array('f', x)
                                           , array('f', y)
                                           , array('f', ex)
                                           , array('f', ey)
                                           )

        self.error_band.SetFillStyle(fill_style)
        self.error_band.SetFillColor(fill_color)

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

    # get key list for each element of d
    key_list_ref = None
    for el in d:
        # print 'Checking keys in %s samples' % el['name']
        for inp in el['inputs']:
            # print "Checking key list in file: %s" % inp['file_name']
            key_list_test = set(get_list_of_keys(inp['file']))
            if key_list_ref == None:
                # print 'getting ref key list'
                key_list_ref = key_list_test
            # print 'key_list_test: %s' % key_list_test
            # print 'key_list_ref: %s' % key_list_ref
            assert key_list_test == key_list_ref
            # print '\tKey list is OK'
        # print '\tAll files in %s are OK' % el['name']

    # print 'All input files have the same structure!'

    # since all the key lists are the same, we can simply return the first key
    # list
    return key_list_ref

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


# ==============================================================================
if __name__ == '__main__':
    f_data = ROOT.TFile('/Users/bjackson/work/Susy.00-01-08/utils/HistMaker/data.root')
    f_mc1 = ROOT.TFile('/Users/bjackson/work/Susy.00-01-08/utils/HistMaker/mc_1.root')
    f_mc2 = ROOT.TFile('/Users/bjackson/work/Susy.00-01-08/utils/HistMaker/mc_2.root')
    f_mc3 = ROOT.TFile('/Users/bjackson/work/Susy.00-01-08/utils/HistMaker/mc_3.root')

    hi_data = ho.HistInfo('data', 1, 1, 20)
    hi_mc   = ho.HistInfo('mc1' , 2, 2, ROOT.kOpenCircle)
    hi_mc1  = ho.HistInfo('mc1' , 3, 3, ROOT.kOpenSquare)
    hi_mc23 = ho.HistInfo('mc23', 4, 4, ROOT.kOpenTriangleUp)

    hh_data = HistHandle( 'ee_sig_lep'
                        , 'mll'
                        , hi_data
                        , [f_data]
                        )

    hh_mc1 = HistHandle( 'ee_sig_lep'
                       , 'mll'
                       , hi_mc1
                       , f_mc1
                       )

    hh_mc23 = HistHandle( 'ee_sig_lep'
                        , 'mll'
                        , hi_mc23
                        , [f_mc2, f_mc3]
                        )


    # c_handles = ROOT.TCanvas('c_handles', 'handles')
    # hh_mc1.hist.Draw()
    # hh_mc23.hist.Draw('SAME')
    # hh_data.hist.Draw('SAME')

    hm_data = HistMerger('ee_sig_lep', 'mll', {'data':hh_data}, hi_data)
    hm_mc  = HistMerger( 'ee_sig_lep', 'mll', { 'mc1':hh_mc1
                                              , 'mc23':hh_mc23
                                              }
                       , hi_mc
                       )

    hm_data.genMergedHist()
    hm_mc.genMergedHist()

    # c_merger_sums = ROOT.TCanvas('c_merger_sums', 'merger_sums')
    # hm_mc.hist_sum.Draw()
    # hm_data.hist_sum.Draw('SAME')

    # c_merger_stack = ROOT.TCanvas('c_merger_stack', 'merger_stack')
    # hm_mc.hist_stack.Draw('HIST')
    # hm_mc.error_band.Draw('E2')
    # hm_data.hist_sum.Draw('SAME')


    hist_painter = hp.HistPainter( num   = hm_data
                                 , denom = hm_mc
                                 )

    canv_default = metaroot.hist.CanvasOptions(width=800, height=600)
    canv_log_y   = metaroot.hist.CanvasOptions(width=800, height=600, log_y=True)


    print 'Linear'
    pile_test_stack = hist_painter.pileAndRatio( num_type       = ho.plain_hist
                                               , denom_type     = ho.stack_hist
                                               , canvas_options = canv_default
                                               , legend         = True
                                               )
    leg = hist_painter.genLegend()
    leg.Draw()
    pile_test_stack.Print('~/Desktop/test_linear.png')
    pile_test_stack.Close()

    print 'Log'
    pile_test_stack = hist_painter.pileAndRatio( num_type       = ho.plain_hist
                                               , denom_type     = ho.stack_hist
                                               , canvas_options = canv_log_y
                                               , legend         = True
                                               )
    leg.Draw()
    pile_test_stack.Print('~/Desktop/test_log.png')
    pile_test_stack.Close()
