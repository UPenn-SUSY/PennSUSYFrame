#!/usr/bin/env python

import sys
import os.path
import optparse
import time
import random
import string

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
            self.hist.SetLineColor(  self.hist_info.line_color)
            self.hist.SetFillColor(  self.hist_info.fill_color)
            self.hist.SetMarkerColor(self.hist_info.fill_color)
            self.hist.SetMarkerStyle(self.hist_info.marker_style)
        else:
            self.hist.Add(h)

        # manually delete hist because ROOT is dumb and holds on to these
        h.Delete()

    # -----------------------------------------------------------------------------
    def scale(self, sf):
        """
        scale this hist handle by sf
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        print 'Scaling %s: %f' % (self.unique_name, sf)
        self.hist.Scale(sf)

    # -----------------------------------------------------------------------------
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
if __name__ == '__main__':
    f_data = ROOT.TFile('/Users/bjackson/work/Susy.00-01-08/utils/HistMaker/data.root')
    f_mc1 = ROOT.TFile('/Users/bjackson/work/Susy.00-01-08/utils/HistMaker/mc_1.root')
    f_mc2 = ROOT.TFile('/Users/bjackson/work/Susy.00-01-08/utils/HistMaker/mc_2.root')
    f_mc3 = ROOT.TFile('/Users/bjackson/work/Susy.00-01-08/utils/HistMaker/mc_3.root')

    hi_data = ho.HistInfo('data', 1, 1, 20)
    hi_mc1  = ho.HistInfo('mc1' , 2, 2, ROOT.kOpenCircle)
    hi_mc23 = ho.HistInfo('mc23', 3, 3, 22)

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


    c_data = ROOT.TCanvas('c_data')
    hh_data.hist.Draw()
    hh_mc1.hist.Draw('SAME')
    hh_mc23.hist.Draw('SAME')
