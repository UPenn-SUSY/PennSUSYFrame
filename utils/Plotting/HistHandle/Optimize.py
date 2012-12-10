#!/usr/bin/env python

import sys
import os.path
import optparse
import time
import random
import string
import math

import ROOT
import rootlogon
import metaroot

import HistHandle as hh

# ==============================================================================
class Optimize(object):
    """
    docstring
    """
    # --------------------------------------------------------------------------
    def __init__( self
                , sig
                , bkg
                , name          = None
                , cut_direction = hh.left
                , bkg_uncertainty = None
                ):
        """
        construtor
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        assert isinstance(sig, hh.Merger.HistMerger)
        assert isinstance(bkg, hh.Merger.HistMerger)

        self.sig_merger = sig
        self.bkg_merger = bkg

        self.cut_direction = cut_direction
        self.bkg_uncertainty = bkg_uncertainty

        self.name = name
        if self.name == None:
            self.name = sig.hist_name

        self.sig_hist = self.sig_merger.hist_sum
        self.bkg_hist = self.bkg_merger.hist_sum

        self.sig_integral = self.genIntegralCurve(self.sig_hist)
        self.bkg_integral = self.genIntegralCurve(self.bkg_hist)

        self.sig_acceptance = self.genAcceptanceCurve( self.sig_hist
                                                     , self.sig_integral
                                                     )
        self.bkg_acceptance = self.genAcceptanceCurve( self.bkg_hist
                                                     , self.bkg_integral
                                                     )

        self.sig_roc = self.genRocCurve(self.sig_acceptance)
        self.bkg_roc = self.genRocCurve(self.bkg_acceptance)

        self.genSignificanceCurves()

    # --------------------------------------------------------------------------
    def genIntegralCurve(self, h):
        assert isinstance(h, ROOT.TH1)

        x_bin = h.GetNbinsX()
        x_min = h.GetXaxis().GetXmin()
        x_max = h.GetXaxis().GetXmax()
        bin_width = (x_max - x_min)/x_bin
        x_min -= bin_width/2.
        x_max -= bin_width/2.
        integral = ROOT.TH1F( 'h_%s_int' % h.GetName()
                            , '%s -- integral' % h.GetName()
                            , x_bin, x_min, x_max
                            )
        for i in xrange(x_bin):
            x = h.GetXaxis().GetBinLowEdge(i+1)
            y = 0
            if self.cut_direction == hh.left:
                y = h.Integral(1,i+1)
            elif self.cut_direction == hh.right:
                y = h.Integral(i+1, x_bin+1)
            integral.Fill(x,y)
            integral.SetBinError(i+1, 1e-6)
        return integral
    
    # --------------------------------------------------------------------------
    def genAcceptanceCurve(self, h, integral):
        scale = 1/(h.Integral() + h.GetBinContent(h.GetNbinsX()+1))
        acc = integral.Clone('h_%s_acc' % h.GetName())
        acc.Scale(scale)
        return acc
    
    # --------------------------------------------------------------------------
    def genRocCurve(self, h):
        pass
    
    # --------------------------------------------------------------------------
    def getCutSignificance(self, cut_bin):
        s = self.sig_integral.GetBinContent(cut_bin)
        b = self.bkg_integral.GetBinContent(cut_bin)

        value = 0
        if s > 0. and b > 0.:
            frac_b_unc = self.bkg_uncertainty
            if frac_b_unc == None:
                frac_b_unc = 1/math.sqrt(b)
            value = ROOT.RooStats.NumberCountingUtils.BinomialExpZ( s
                                                                  , b
                                                                  , frac_b_unc
                                                                  )
        if value > 1000: value = 1000
        return value

    # --------------------------------------------------------------------------
    def genSignificanceCurves(self):
        self.significance = self.sig_integral.Clone('h_significance')
        for i in xrange(self.significance.GetNbinsX()+2):
            sig = self.getCutSignificance(i)
            self.significance.SetBinContent(i, sig)

    # --------------------------------------------------------------------------
    def __del__(self):
        pass
