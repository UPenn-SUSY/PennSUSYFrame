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
        assert(type(input_file) == ROOT.TFile)

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
            print 'key: %s' % key
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
        for key in self.hist_handles:
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

        # self.error_band = metaroot.plot.plot_graph_errors('%s_error_band' % self.unique_name
        #                                                  , x
        #                                                  , y
        #                                                  , ex
        #                                                  , ey
        #                                                  )
        self.error_band.SetFillStyle(fill_style)
        self.error_band.SetFillColor(fill_color)

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


    c_handles = ROOT.TCanvas('c_handles', 'handles')
    hh_mc1.hist.Draw()
    hh_mc23.hist.Draw('SAME')
    hh_data.hist.Draw('SAME')

    hm_data = HistMerger('ee_sig_lep', 'mll', {'data':hh_data}, hi_data)
    hm_mc  = HistMerger('ee_sig_lep', 'mll', { 'mc1':hh_mc1
                                             , 'mc23':hh_mc23
                                             }
                       , hi_mc
                       )

    hm_data.genMergedHist()
    hm_mc.genMergedHist()

    c_merger_sums = ROOT.TCanvas('c_merger_sums', 'merger_sums')
    hm_mc.hist_sum.Draw()
    hm_data.hist_sum.Draw('SAME')

    c_merger_stack = ROOT.TCanvas('c_merger_stack', 'merger_stack')
    hm_mc.hist_stack.Draw('HIST')
    hm_mc.error_band.Draw('E2')
    hm_data.hist_sum.Draw('SAME')
