#!/usr/bin/env python

import sys
import os.path
import optparse
import time
import random
import string
import math
import array

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

        self.significance = None
        self.genSignificanceCurves()

        self.optimal_cut = None
        self.getOptimalCut()

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
                            , '%s -- integral;%s;%s' % ( h.GetName()
                                                       , h.GetXaxis().GetTitle()
                                                       , h.GetYaxis().GetTitle()
                                                       )
                            , x_bin, x_min, x_max
                            )
        for i in xrange(x_bin):
            x = h.GetXaxis().GetBinLowEdge(i+1)
            y = 0
            if self.cut_direction == hh.left:
                y = h.Integral(1,i+1)
            elif self.cut_direction == hh.right:
                y = h.Integral(i+1, x_bin+1)
            else:
                assert false

            integral.Fill(x,y)
            integral.SetBinError(i+1, 1e-6)
        return integral

    # --------------------------------------------------------------------------
    def genAcceptanceCurve(self, h, integral):
        scale = h.Integral() + h.GetBinContent(h.GetNbinsX()+1)
        if not scale == 0:
            scale = 1/scale

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
    def getOptimalCut(self):
        if self.optimal_cut is None:
            max_sig = 0
            cut = None
            for i in xrange(self.significance.GetXaxis().GetNbins()+2):
                sig = self.significance.GetBinContent(i)
                if sig > max_sig:
                    max_sig = sig
                    cut = self.significance.GetXaxis().GetBinCenter(i)
            if cut is not None:
                self.optimal_cut = {'cut':cut, 'sig':max_sig}
        return self.optimal_cut

    # --------------------------------------------------------------------------
    def genCutRegion(self, h):
        if self.optimal_cut == None:
            self.optimal_cut = self.getOptimalCut()
        if self.optimal_cut == None: return None

        x1 = self.optimal_cut['cut']
        x2 = h.GetXaxis().GetXmin()
        if self.cut_direction == hh.left:
            x2 = h.GetXaxis().GetXmax()

        y_min = h.GetMinimum()
        y_max = h.GetMaximum()

        x = [x1, x1, x2, x2]
        y = [y_min, y_max, y_max, y_min]

        region = ROOT.TPolyLine( 4
                               , array.array('d', x)
                               , array.array('d', y)
                               )
        region.SetFillColor(ROOT.kGreen+2)
        region.SetFillStyle(3199)
        return region

    # --------------------------------------------------------------------------
    def genMarker(self, h, x, y):
        x_range = abs(h.GetXaxis().GetXmax() - h.GetXaxis().GetXmin())
        y_range = abs(h.GetYaxis().GetXmax() - h.GetYaxis().GetXmin())

        mark = ROOT.TEllipse(x, y, 0.015*x_range, 0.08*y_range)
        mark.SetFillColor(ROOT.kGreen+2)
        mark.SetFillStyle(3199)

        return mark

    # --------------------------------------------------------------------------
    def drawSignificanceCanvas(self):
        sig_canvas = hh.Painter.pileHists( [self.significance]
                                         , '%s_zn' % self.name
                                         )
        highlight_point = None
        if self.optimal_cut is not None:
            x_position = self.optimal_cut['cut']
            cut_bin = self.significance.GetXaxis().FindBin(x_position)
            y_position = self.significance.GetBinContent(cut_bin)
            highlight_point = self.genMarker( self.significance
                                            , x_position
                                            , y_position
                                            )
            highlight_point.Draw()

        return {'canvas':sig_canvas, 'mark':highlight_point}

    # ------------------------------------------------------------------------------
    def drawCutRegionCanvas(self, pile_canv):
        cut_canvas = pile_canv.Clone('%s_w_cut_region' % pile_canv.GetName())

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        cut_region = None
        if self.optimal_cut is not None:
            pass
            # TODO draw cut region -- need to get bounds of pad
            # cut_region = self.genCutRegion(painter.hist_list[0])
        if not cut_region is None:
            cut_region.Draw('F')

        return {'canvas':cut_canvas}

    # --------------------------------------------------------------------------
    def __del__(self):
        pass

# ==============================================================================
class OptimizeMap(object):
    # --------------------------------------------------------------------------
    def __init__(self, optimize_container):
        assert isinstance(optimize_container, hh.parse.OptimizeContainer)
        self.optimize_container = optimize_container

        self.optimize_grid_points = {}
        self.sample_bkg_integral = None

    # --------------------------------------------------------------------------
    def addGridPoint(self, grid_point_optimize, point_name):
        assert isinstance(grid_point_optimize, Optimize)
        self.optimize_grid_points[point_name] = grid_point_optimize
        if self.sample_bkg_integral is None:
            self.sample_bkg_integral = grid_point_optimize.bkg_integral

    # --------------------------------------------------------------------------
    def printScan(self, maps_dir, target_lumi, prod_type = ''):
        dir_name = 'scan_%s' % self.optimize_container.to_optimize
        maps_dir.mkdir(dir_name)
        maps_dir.cd(dir_name)

        map_entries = []
        for gp in self.optimize_grid_points:
            optimal_cut = self.optimize_grid_points[gp].getOptimalCut()
            sig = optimal_cut['sig'] if optimal_cut is not None else -1
            cut = optimal_cut['cut'] if optimal_cut is not None else -1

            cut_bin = self.optimize_grid_points[gp].significance.GetXaxis().FindBin(cut)
            num_sig = self.optimize_grid_points[gp].sig_integral.GetBinContent(cut_bin)

            map_entries.append( { 'point_name':gp
                                , 'significance':sig
                                , 'cut_value':cut
                                , 'num_sig':num_sig
                                } )
        maps = hh.Painter.draw2DMaps( map_entries
                                    , lumi = target_lumi
                                    , prod_type = prod_type
                                    )
        maps['c_sig'].Write()
        maps['c_cut'].Write()
        maps['c_num_sig'].Write()
        maps['c_sig'].Close()
        maps['c_cut'].Close()
        maps['c_num_sig'].Close()

    # --------------------------------------------------------------------------
    def printFixedPoint(self, maps_dir, cut_value, target_lumi, prod_type = ''):
        dir_name = '%s_%s' % ( self.optimize_container.to_optimize
                             , cut_value
                             )
        maps_dir.mkdir(dir_name)
        maps_dir.cd(dir_name)

        map_entries = []
        for gp in self.optimize_grid_points:
            cut_bin = self.optimize_grid_points[gp].significance.GetXaxis().FindBin(float(cut_value))
            sig = self.optimize_grid_points[gp].significance.GetBinContent(cut_bin)
            num_sig = self.optimize_grid_points[gp].sig_integral.GetBinContent(cut_bin)

            map_entries.append( { 'point_name':gp
                                , 'significance':sig
                                , 'cut_value':cut_value
                                , 'num_sig':num_sig
                                } )
        maps = hh.Painter.draw2DMaps( map_entries
                                    , lumi = target_lumi
                                    , prod_type = prod_type
                                    )
        maps['c_sig'].Write()
        maps['c_cut'].Write()
        maps['c_num_sig'].Write()
        maps['c_sig'].Close()
        maps['c_cut'].Close()
        maps['c_num_sig'].Close()

    # ------------------------------------------------------------------------------
    def printAllFixedPoints(self, maps_dir, target_lumi, prod_type = ''):
        maps_dir.cd()

        c_num_bkg = hh.Painter.pileHists( [self.sample_bkg_integral]
                                        , 'num_bkg'
                                        , canvas_options = hh.canv_log_y
                                        )

        hh.Painter.drawLabels( int_lumi = target_lumi
                             , prod_type = prod_type
                             )
        c_num_bkg.Write()
        c_num_bkg.Close()

        for cut_value in self.optimize_container.fixed_points:
            self.printFixedPoint( maps_dir
                                , cut_value
                                , target_lumi=target_lumi
                                , prod_type=prod_type
                                )
