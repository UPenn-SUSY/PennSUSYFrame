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
import rootlogon
import metaroot

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
