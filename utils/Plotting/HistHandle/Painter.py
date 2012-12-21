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
canv_default = metaroot.hist.CanvasOptions(width=800, height=600)
canv_log_y   = metaroot.hist.CanvasOptions(width=800, height=600, log_y=True)

# ==============================================================================
class HistPainter(object):
    """
    docstring
    """
    # --------------------------------------------------------------------------
    def __init__( self
                , num
                , denom = None
                , name  = None
                , optimal_cut = None
                ):
        """
        construtor
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        assert isinstance(num, hh.Merger.HistMerger)
        assert denom == None or isinstance(denom, hh.Merger.HistMerger)
        assert optimal_cut == None or isinstance( optimal_cut
                                                , hh.Optimize.Optimize
                                                )
        self.num_merger   = num
        self.denom_merger = denom
        self.optimal_cut  = optimal_cut

        self.name = name
        if self.name == None:
            self.name = num.hist_name

        self.canvas = None
        self.ratio_canvas = None

    # --------------------------------------------------------------------------
    def __del__(self):
        if not self.canvas is None:
            self.canvas.Close()
        if not self.ratio_canvas is None:
            self.ratio_canvas.Close()

    # --------------------------------------------------------------------------
    def genLegend( self, name = 'leg'):
        """
        Generates a legend based on a list of HistMerger objects
        """
        # TODO add variables for the placement of the legend
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        # get list of histograms and labels from the HistMergers passed as
        # inputs
        hist_list = []
        label_list = []
        for key in self.num_merger.hist_handles:
            hist_list.append(self.num_merger.hist_handles[key].hist)
            label_list.append(key)
        for key in self.denom_merger.hist_handles:
            hist_list.append(self.denom_merger.hist_handles[key].hist)
            label_list.append(key)

        # get the draw options to be used for the legend
        draw_opt_list = ['HIST']*len(hist_list)

        # build legend and return
        leg = metaroot.hist.make_legend( hist_list
                                       , label_list
                                       , draw_opt_list
                                       )

        return leg

    # --------------------------------------------------------------------------
    def pile( self
            , num_type         = hh.Objects.plain_hist
            , denom_type       = hh.Objects.plain_hist
            , normalize        = False
            , canvas_options   = canv_default
            , legend           = False
            ):
        """
        docstring
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        if normalize:
            assert num_type   == hh.Objects.plain_hist
            assert denom_type == hh.Objects.plain_hist

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        # create canvas
        tag = '%s_pile_%s' % (self.name, getTag( num_type
                                               , denom_type
                                               , normalize
                                               )
                             )

        hist_list = []
        draw_opt_list = []
        # get denominator hists
        if not self.denom_merger == None:
            if denom_type == hh.Objects.piled_hist:
                for hl in self.denom_merger.hist_list:
                    hist_list.append(hl)
                    draw_opt_list.append('P')
            elif denom_type == hh.Objects.plain_hist:
                hist_list.append(self.denom_merger.hist_sum)
                draw_opt_list.append('P')
            elif denom_type == hh.Objects.stack_hist:
                # for stacked histograms, we want to add the sum also to get the
                # min/max right
                hist_list.append(self.denom_merger.hist_sum)
                draw_opt_list.append('HIST')
                hist_list.append(self.denom_merger.hist_stack)
                draw_opt_list.append('HIST')
                hist_list.append(self.denom_merger.error_band)
                draw_opt_list.append('E2')

        # get numerator hists
        if num_type == hh.Objects.piled_hist:
            for hl in self.num_merger.hist_list:
                hist_list.append(hl)
                draw_opt_list.append('P')
        elif num_type == hh.Objects.plain_hist:
            hist_list.append(self.num_merger.hist_sum)
            draw_opt_list.append('P')
        elif num_type == hh.Objects.stack_hist:
            # for stacked histograms, we want to add the sum also to get the
            # min/max right
            hist_list.append(self.num_merger.hist_sum)
            draw_opt_list.append('HIST')
            hist_list.append(self.num_merger.hist_stack)
            draw_opt_list.append('HIST')


        self.canvas = pileHists( hist_list
                               , tag
                               , draw_opt_list = draw_opt_list
                               , canvas_options = canvas_options
                               )

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        if self.optimal_cut is not None:
            print 'Found optimal cut'
            self.cut_region = self.optimal_cut.genCutRegion(hist_list[0])
            if not self.cut_region is None:
                self.cut_region.Draw('F')

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        if legend:
            self.legend = self.genLegend()
            self.legend.Draw()

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        return self.canvas

    # --------------------------------------------------------------------------
    def pileAndRatio( self
                    , num_type         = hh.Objects.plain_hist
                    , denom_type       = hh.Objects.plain_hist
                    , normalize        = False
                    , canvas_options   = canv_default
                    , legend           = False
                    ):
        """
        docstring
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        assert not num_type   == hh.Objects.piled_hist
        assert not denom_type == hh.Objects.piled_hist

        if normalize:
            assert num_type   == hh.Objects.plain_hist
            assert denom_type == hh.Objects.plain_hist

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        self.pile( num_type
                 , denom_type
                 , normalize
                 , canvas_options
                 )

        ratio_axis_title = '%s/%s' % ( self.num_merger.hist_info.name
                                     , self.denom_merger.hist_info.name
                                     )
        # make ratio histogram
        self.ratio = self.num_merger.hist_sum.Clone('%s_ratio' % self.name)
        self.ratio.Divide(self.denom_merger.hist_sum)
        self.ratio.GetYaxis().SetTitle(ratio_axis_title)

        tag = '%s_ratio_%s' % (self.name, getTag( num_type
                                                , denom_type
                                                , normalize
                                                )
                              )

        ratio_canvas_options = hh.canv_linear
        ratio_canvas_options.log_y = False
        ratio_canvas = pileHists( [self.ratio]
                                , tag
                                , ['PE']
                                , canvas_options = ratio_canvas_options
                                , y_min = 0.5
                                , y_max = 1.5
                                )
        line = ROOT.TLine()
        line.SetLineStyle(2)
        a = self.ratio.GetXaxis()
        line.DrawLine(a.GetXmin(), 1., a.GetXmax(), 1.)

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        shared_name = '%s_w_ratio' % self.canvas.GetName()
        shared=metaroot.plot.plot_shared_axis( self.canvas
                                             , ratio_canvas
                                             , name=shared_name+"_with_ratio"
                                             , canvas_options=canvas_options
                                             , split=0.3
                                             , axissep=0.04
                                             , ndivs=[505,503]
                                             )
        self.ratio_stuff = { 'top_pad':shared['top_pad']
                           , 'bottom_pad':shared['bottom_pad']
                           }

        self.canvas = shared['canvas']

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        if legend:
            self.ratio_stuff['top_pad'].cd()
            self.legend = self.genLegend()
            self.legend.Draw()

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        return self.canvas

# ------------------------------------------------------------------------------
def getTag( num_type   = hh.Objects.plain_hist
          , denom_type = hh.Objects.plain_hist
          , normalize  = False
          ):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    tag = '_%s' % hh.Objects.typeToString(num_type)

    if not denom_type == None:
        tag += '_%s' % hh.Objects.typeToString(denom_type)

    if normalize:
        tag += '_norm'

    return tag


# ------------------------------------------------------------------------------
def pileHists( hist_list
             , name
             , draw_opt_list = metaroot.default
             , title = None
             , canvas_options = metaroot.default
             , y_min = metaroot.default
             , y_max = metaroot.default
             ):
    """
    docstring
    """
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    if not isinstance(hist_list, list):
        hist_list = [hist_list]
    if draw_opt_list == metaroot.default:
        print 'setting the default draw options'
        draw_opt_list = ['P']*len(hist_list)

    # create canvas
    if canvas_options == metaroot.default:
        canvas_options = canv_default
    c = canvas_options.create(name)

    setMin(hist_list, canvas_options.log_y, y_min)
    setMax(hist_list, canvas_options.log_y, y_max)

    # actuall draw plots
    drawn_first = False
    for i, h in enumerate(hist_list):
        draw_opt = draw_opt_list[i]
        if not drawn_first:
            if isinstance(h, ROOT.TGraph) or isinstance(h, ROOT.TGraphAsymmErrors):
                draw_opt += 'A'
        else:
            draw_opt += 'SAME'
        h.Draw(draw_opt)
        drawn_first = True

    return c


# ------------------------------------------------------------------------------
def setMin(hist_list, log_y = False, y_min = metaroot.default):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    if y_min == metaroot.default:
        y_min = calcMin(hist_list, log_y)

    for h in hist_list:
        h.SetMinimum(y_min)

    return y_min

# ------------------------------------------------------------------------------
def setMax(hist_list, log_y = False, y_max = metaroot.default):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    if y_max == metaroot.default:
        y_max = calcMax(hist_list, log_y)

    for h in hist_list:
        h.SetMaximum(y_max)

    return y_max

# ------------------------------------------------------------------------------
def calcMin(hist_list, log_y = True):
    if len(hist_list) == 0: return 0.

    # TODO come up with better algorithm
    extremes = getExtrema(hist_list, log_y)
    y_min = min(extremes)
    y_max = max(extremes)

    # add in a buffer on top and bottom
    if log_y and y_min > 0 and y_max > 0:
        y_min = math.pow( 10
                        , ( math.log(y_min, 10)
                          - ( math.log(y_max, 10)
                            - math.log(y_min, 10)
                            ) * 0.20
                          )
                        )
    else:
        y_min -= (y_max - y_min)*0.20

    # return value for min
    return y_min

# ------------------------------------------------------------------------------
def calcMax(hist_list, log_y = True):
    if len(hist_list) == 0: return 0.

    # TODO come up with better algorithm
    extremes = getExtrema(hist_list, log_y)
    y_min = min(extremes)
    y_max = max(extremes)

    # add in a buffer on top and bottom
    if log_y and y_min > 0 and y_max > 0:
        y_max = math.pow( 10
                        , ( math.log(y_max, 10)
                          + ( math.log(y_max, 10)
                            - math.log(y_min, 10)
                            ) * 0.20
                          )
                        )
    else:
        y_max += (y_max - y_min)*0.20

    # return value for max
    return y_max

# ------------------------------------------------------------------------------
def getExtrema(hist_list, log_y = True):
    if len(hist_list) == 0: return 0.

    # TODO come up with better algorithm
    extrema = []
    for h in hist_list:
        local_min = None
        local_max = None

        h_tmp = h
        if isinstance(h_tmp, ROOT.THStack): continue
        if isinstance(h_tmp, ROOT.TGraph):  continue
        if isinstance(h_tmp, ROOT.TGraphErrors): continue

        num_bins = h_tmp.GetXaxis().GetNbins()
        for b in xrange(num_bins):
            bin_content = h_tmp.GetBinContent(b)
            bin_content_up   = bin_content + h_tmp.GetBinError(b)
            bin_content_down = bin_content - h_tmp.GetBinError(b)

            # check if this bin is a minimum
            if local_min is None or bin_content_down < local_min:
                if bin_content_down > 0 or not log_y:
                    local_min = bin_content_down

            # check if this bin is a maxiumum
            if local_max is None or bin_content > local_max:
                if bin_content_up > 0 or not log_y:
                    local_max = bin_content_up

        if not local_min is None:
            extrema.append(local_min)
        if not local_max is None:
            extrema.append(local_max)

    if len(extrema) == 0:
        extrema = [0.01, 0.1]
    return extrema

# ------------------------------------------------------------------------------
def draw2DMaps(map_array, contour_levels = [1.64], lumi = None):
    # structure of elemets in map array are: # {'point_name':str, 'significance':float, 'cut_value':float}
    x_grid_points = []
    y_grid_points = []
    x_points      = []
    y_points      = []
    significance  = []
    cut_values    = []
    num_sig       = []
    num_bkg       = []

    for ma in map_array:
        x_grid_points.append(hh.Helper.getCharginoMass(  ma['point_name']))
        y_grid_points.append(hh.Helper.getNeutralinoMass(ma['point_name']))

        if ma['significance'] is not None:
            x_points.append(hh.Helper.getCharginoMass(  ma['point_name']))
            y_points.append(hh.Helper.getNeutralinoMass(ma['point_name']))
            significance.append(ma['significance'])
            cut_values.append(ma['cut_value'])
            num_sig.append(ma['num_sig'])
            num_bkg.append(ma['num_bkg'])

    # set axis titles
    x_axis = 'm_{#tilde{#chi}_{1}^{#pm}} [GeV]'
    y_axis = 'm_{#tilde{#chi}_{1}^{0}} [GeV]'
    sig_title = 'significance ; %s ; %s' % (x_axis, y_axis)
    cut_title = 'cut value ; %s ; %s' % (x_axis, y_axis)
    num_sig_title = 'Num signal events ; %s ; %s' % (x_axis, y_axis)
    num_bkg_title = 'Num background events ; %s ; %s' % (x_axis, y_axis)

    grid_points = ROOT.TGraph( len(map_array)
                             , array.array('d', x_grid_points)
                             , array.array('d', y_grid_points)
                             )
    grid_points.SetMarkerStyle(20)
    sig_graph = ROOT.TGraph2D( 'h_sig_map'
                             , '%s; Z_{n}' % sig_title
                             , len(x_points)
                             , array.array('d', x_points)
                             , array.array('d', y_points)
                             , array.array('d', significance)
                             )

    cut_graph = ROOT.TGraph2D( 'h_cut_map'
                             , '%s; Cut Values' % cut_title
                             , len(x_points)
                             , array.array('d', x_points)
                             , array.array('d', y_points)
                             , array.array('d', cut_values)
                             )

    num_sig_graph = ROOT.TGraph2D( 'h_num_sig_map'
                                 , '%s; Expected Signal Events' % num_sig_title
                                 , len(x_points)
                                 , array.array('d', x_points)
                                 , array.array('d', y_points)
                                 , array.array('d', num_sig)
                                 )

    num_bkg_graph = ROOT.TGraph2D( 'h_num_bkg_map'
                                 , '%s; Expected Background Events' % num_sig_title
                                 , len(x_points)
                                 , array.array('d', x_points)
                                 , array.array('d', y_points)
                                 , array.array('d', num_bkg)
                                 )

    sig_graph.SetMinimum(0)
    cut_graph.SetMinimum(0)
    num_sig_graph.SetMinimum(0)
    num_bkg_graph.SetMinimum(0)

    # get contour lines frokm significance map
    contour_lines = getContourLines( sig_graph
                                   , contour_levels
                                   , [2]*len(contour_levels)
                                   )

    l_lumi   = ROOT.TLatex(0.20, 0.75, '#int L dt = 21 fb^{-1}')
    l_sample = ROOT.TLatex(0.20, 0.67, '#tilde{#chi}_{1}^{#pm}#tilde{#chi}_{1}^{0} production')
    l_lumi.SetNDC()
    l_sample.SetNDC()
    l_lumi.SetTextSize(0.05)
    l_sample.SetTextSize(0.05)

    c_sig = hh.canv_opt_2d.create('c_sig_map')
    sig_graph.Draw('COLZ')
    grid_points.Draw('PSAME')
    for cl in contour_lines:
        cl.Draw('SAME')
    l_lumi.Draw()
    l_sample.Draw()

    c_cut = hh.canv_opt_2d.create('c_cut_map')
    cut_graph.Draw('COLZ')
    grid_points.Draw('PSAME')
    for cl in contour_lines:
        cl.Draw('SAME')
    l_lumi.Draw()
    l_sample.Draw()

    c_num_sig = hh.canv_opt_2d_log_y.create('c_num_sig_map')
    num_sig_graph.Draw('COLZ')
    grid_points.Draw('PSAME')
    for cl in contour_lines:
        cl.Draw('SAME')
    l_lumi.Draw()
    l_sample.Draw()

    c_num_bkg = hh.canv_opt_2d_log_y.create('c_num_bkg_map')
    num_bkg_graph.Draw('COLZ')
    grid_points.Draw('PSAME')
    for cl in contour_lines:
        cl.Draw('SAME')
    l_lumi.Draw()
    l_sample.Draw()

    return { 'h_sig':sig_graph
           , 'h_cut':cut_graph
           , 'h_num_sig':num_sig_graph
           , 'h_num_bkg':num_bkg_graph
           , 'c_sig':c_sig
           , 'c_cut':c_cut
           , 'c_num_sig':c_num_sig
           , 'c_num_bkg':c_num_bkg
           , 'contour':contour_lines
           , 'grid':grid_points
           , 'l_lumi':l_lumi
           , 'l_sample':l_sample
           }

# -----------------------------------------------------------------------------
def getContourLines( plot
                   , contour_levels = [0.05]
                   , contour_colors = [1]
                   ):
    """
    docstring
    """
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # check type of plot and get temp histogram
    if isinstance(plot, ROOT.TH2):
        h = plot.Clone('hist_temp')
    elif isinstance(plot, ROOT.TGraph2D):
        h = plot.GetHistogram()

    # add contour levels to temp histogram
    h.SetContour(len(contour_levels), array.array('d', contour_levels))

    # draw temp histogram to canvas and update to get contours
    c = ROOT.TCanvas('c_temp')
    h.Draw('CONT Z LIST')
    c.Update()

    # list to store the contour graphs which are created and will be returned
    list_of_contour_graphs = []
    contours = ROOT.gROOT.GetListOfSpecials().FindObject('contours')
    for i in xrange(contours.GetSize()):
        this_contour = contours.At(i)
        for j in xrange(this_contour.GetSize()):
            curve = this_contour.At(j)
            cv = curve.Clone('%s_cv_%d_%d' % (plot.GetName(),i,j))

            cv.SetLineColor(contour_colors[i])
            cv.SetLineWidth(3)

            list_of_contour_graphs.append(cv)
    c.Close()
    return list_of_contour_graphs


