#!/usr/bin/env python

import sys
import os.path
import optparse
import time
import random
import string
from array import array

import ROOT
# import rootlogon

import HistHandle as hh

# ==============================================================================
class HistMerger(object):
    """
    docstring
    """
    # --------------------------------------------------------------------------
    def __init__( self
                , directory
                , hist_name
                , hist_handle_dict
                , hist_handle_key_list
                , hist_info
                ):
        """
        constructor
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        self.directory = directory
        self.hist_name = hist_name

        # create random string to be used as a unique tag
        unique_tag = ''.join(random.choice(string.ascii_lowercase)
                             for x in xrange(5))
        self.unique_name = '%s__%s__%s' % ( directory
                                          , hist_name
                                          , unique_tag
                                          )
        self.hist_info = hist_info
        self.hist_type = None

        self.hist_handles  = {}
        self.hist_handles_keys = []
        self.hist_list  = []
        self.hist_sum   = None
        self.hist_stack = None
        self.error_band = None

        # adding hist handles
        if not isinstance (hist_handle_dict, dict):
            sys.exit('hist_handle_dict is not of type dictionary')
        for i, key in enumerate(hist_handle_key_list):
            self.addHistHandle(hist_handle_dict[key], key)
            if i == 0:
                self.hist_type = hist_handle_dict[key].hist_type

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
        # if self.int_stack is not None:
        #     self.int_stack.Delete()

    # --------------------------------------------------------------------------
    def addHistHandle(self, hist_handle, label):
        """
        docstring
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        assert isinstance(hist_handle, hh.Handle.HistHandle)
        hist_handle.scaleToLumi()
        self.hist_handles_keys.append(label)
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
        for key in self.hist_handles_keys:
            h = self.hist_handles[key]
            self.hist_list.append(h.hist)

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        # generate sum hist
        for key in self.hist_handles_keys:
            h = self.hist_handles[key]

            if self.hist_sum == None:
                self.hist_sum = h.hist.Clone('%s_sum' % self.unique_name)
                self.hist_info.setHistStyle(self.hist_sum)
            else:
                self.hist_sum.Add(h.hist)

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        # generate stacked hist
        self.hist_stack = ROOT.THStack('%s_stack' % self.unique_name
                                      , 'stack'
                                      )
        key_list = []
        for key in self.hist_handles_keys:
            key_list.append(key)

        for key in reversed(key_list):
            h = self.hist_handles[key]
            self.hist_stack.Add(h.hist)

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        # generate error band
        self.genErrorBand(3004, 1)

    # --------------------------------------------------------------------------
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
