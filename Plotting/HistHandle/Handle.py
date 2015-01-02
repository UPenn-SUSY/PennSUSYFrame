#!/usr/bin/env python

import sys
import os.path
import inspect
import optparse
import time
import random
import string
from array import array

import ROOT

import HistHandle as hh

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
                , lumi_modeled_in_file = 1.
                , target_lumi = 1.
                ):
        """
        construtor
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        self.directory = directory
        self.name = hist_name
        self.hist_name = hist_name
        self.hist_info = hist_info

        self.lumi_modeled_in_file = float(lumi_modeled_in_file)
        self.target_lumi = float(target_lumi)
        self.scaled_to_lumi = (lumi_modeled_in_file == target_lumi)

        # create random string to be used as a unique tag
        unique_tag = ''.join(random.choice(string.ascii_lowercase) \
                for x in xrange(5))
        self.unique_name = '%s__%s__%s__%s' % ( hist_info.name
                                              , directory
                                              , hist_name
                                              , unique_tag
                                              )

        self.hist = None
        self.hist_type = None

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
        # print 'Getting hist: %s from directory: %s/%s' % ( self.hist_name
        #                                                  , input_file.GetName()
        #                                                  , self.directory
        #                                                  )
        d = input_file.GetDirectory(self.directory)
        h = d.Get(self.hist_name)
        # print '    type(d): %s' % type(d)
        # print '    type(h): %s' % type(h)
        # print '    num_entries: %s -- integral: %s' % (h.GetEntries(), h.Integral())
        h.Sumw2()

        # if 1D hist, recover overflow bin!
        if isinstance(h, ROOT.TH1F) or isinstance(h, ROOT.TH1D):
            hh.Helper.recoverOverflow(h)

        # add hist to HistHandle internal histogram
        if self.hist == None:
            self.hist = h.Clone(self.unique_name)
            self.hist_info.setHistStyle(self.hist)
            if isinstance(self.hist, ROOT.TH1F) or isinstance(self.hist, ROOT.TH1D):
                self.hist_type = hh.HIST_1D
            if isinstance(self.hist, ROOT.TH2F) or isinstance(self.hist, ROOT.TH2D):
                self.hist_type = hh.HIST_2D
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
        # print 'Scaling %s: %f' % (self.unique_name, sf)
        self.hist.Scale(sf)

    # --------------------------------------------------------------------------
    def scaleTo(self, target):
        """
        scale this hist handle such that the integral is equal to target
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        # print 'Scaling %s to target: %f' % (self.unique_name, target)
        old_int = self.hist.Integral()
        sf = target/old_int
        self.hist.Scale(sf)

    # --------------------------------------------------------------------------
    def scaleToLumi(self):
        if not self.scaled_to_lumi:
            lumi_scale = self.target_lumi/self.lumi_modeled_in_file
            # print 'scaling to lumi: modeled: %s - target: %s - sf: %s' % (self.lumi_modeled_in_file, self.target_lumi, lumi_scale)
            self.scale(lumi_scale)
            self.scaled_to_lumi = True
