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

import AtlasLabels

import HistHandle as hh

# ==============================================================================
# canv_default = metaroot.hist.CanvasOptions(width=800, height=600)
# canv_log_y   = metaroot.hist.CanvasOptions(width=800, height=600, log_y=True)

# ==============================================================================
prod_labels = { 'modeA':'#tilde{#chi}_{1}^{#pm}#tilde{#chi}_{2}^{0} production'
              , 'modeC':'#tilde{#chi}_{1}^{0}#tilde{#chi}_{1}^{0} production'
              , 'pmssm':'pMSSM - TO UPDATE!!!'
              }

# ==============================================================================
class HistPainter(object):
    """
    docstring
    """
    # --------------------------------------------------------------------------
    def __init__( self
                , num
                , denom = None
                , other = None
                , name  = None
                , optimal_cut = None
                , num_draw_option   = 'PE'
                , denom_draw_option = 'PE'
                , other_draw_option = 'HIST'
                ):
        """
        construtor
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        assert isinstance(num, hh.Merger.HistMerger)
        assert denom == None or isinstance(denom, hh.Merger.HistMerger)
        assert other == None or isinstance(other, hh.Merger.HistMerger)
        assert optimal_cut == None or isinstance( optimal_cut
                                                , hh.Optimize.Optimize
                                                )
        self.num_merger   = num
        self.denom_merger = denom
        self.other_merger = other
        self.optimal_cut  = optimal_cut

        self.name = name
        if self.name == None:
            self.name = num.hist_name

        self.canvas = None
        self.ratio_canvas = None

        self.num_draw_option   = num_draw_option
        self.denom_draw_option = denom_draw_option
        self.other_draw_option = other_draw_option

    # --------------------------------------------------------------------------
    def __del__(self):
        if not self.canvas is None:
            self.canvas.Close()
        if not self.ratio_canvas is None:
            self.ratio_canvas.Close()

    # --------------------------------------------------------------------------
    def genLegend( self, name = 'leg', full_canvas = False):
        """
        Generates a legend based on a list of HistMerger objects
        """
        # TODO add variables for the placement of the legend
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        # get list of histograms and labels from the HistMergers passed as
        # inputs
        hist_list = []
        label_list = []
        draw_opt_list = []
        # add numerator
        for key in self.num_merger.hist_handles:
            hist_list.append(self.num_merger.hist_handles[key].hist)
            label_list.append(hh.Helper.genLegendLabel(key))
            print 'adding numerator option to legend: %s' % self.num_draw_option
            draw_opt_list.append(self.num_draw_option)
        # add denominator
        for key in self.denom_merger.hist_handles:
            hist_list.append(self.denom_merger.hist_handles[key].hist)
            label_list.append(hh.Helper.genLegendLabel(key))
            draw_opt_list.append('HIST')
        # if there are others to add, add them now
        if self.other_merger is not None:
            for key in self.other_merger.hist_handles:
                hist_list.append(self.other_merger.hist_handles[key].hist)
                label_list.append(hh.Helper.genLegendLabel(key))
                draw_opt_list.append('HIST')

        # build legend and return
        leg = metaroot.hist.make_legend( hist_list
                                       , label_list
                                       , draw_opt_list
                                       , width=0.40 if not full_canvas else 0.90
                                       , y2 = 0.90
                                       )

        return leg

    # ------------------------------------------------------------------------------
    def genEntriesHists(self):
        """
        Generate histogram with the number of entries per component
        """
        label_list  = []
        num_entries = []
        fill_colors = []
        line_colors = []
        line_widths = []
        line_styles = []

        # get entries for numerator
        self.findHistEntries( self.num_merger
                            , label_list
                            , num_entries
                            , fill_colors
                            , line_colors
                            , line_widths
                            , line_styles
                            );
        # get entries for denominator
        self.findHistEntries( self.denom_merger
                            , label_list
                            , num_entries
                            , fill_colors
                            , line_colors
                            , line_widths
                            , line_styles
                            );
        # get entries for other
        if self.other_merger is not None:
            self.findHistEntries( self.other_merger
                                , label_list
                                , num_entries
                                , fill_colors
                                , line_colors
                                , line_widths
                                , line_styles
                                );

        num_handles = len(label_list)
        print 'Number of handles to add to entry histogram: %s' % num_handles

        entry_hists = []
        for it in xrange(num_handles):
            tmp_hist = ROOT.TH1D( 'entry_hist'
                                , 'num_entries'
                                , num_handles + 2
                                , -0.5
                                , num_handles + 1.5
                                )
            tmp_hist.SetFillColor(fill_colors[it])
            tmp_hist.SetLineColor(line_colors[it])
            tmp_hist.SetLineWidth(line_widths[it])
            tmp_hist.SetLineStyle(line_styles[it])

            tmp_hist.Fill(it, num_entries[it])

            for bin_it in xrange(num_handles):
                print 'bin: %s' % bin_it
                print '  label:   %s' % label_list[bin_it]
                print '  entries: %s' % num_entries[bin_it]
                tmp_hist.GetXaxis().SetBinLabel(bin_it+1, label_list[bin_it])

            entry_hists.append(tmp_hist)

        return entry_hists

    # ------------------------------------------------------------------------------
    # TODO move out of class definition
    def findHistEntries( self
                       , merger
                       , label_list
                       , num_entries
                       , fill_colors
                       , line_colors
                       , line_widths
                       , line_styles
                       ):
        for key in merger.hist_handles:
            label_list.append(hh.Helper.genLegendLabel(key))
            num_entries.append(merger.hist_handles[key].hist.Integral())
            fill_colors.append(merger.hist_handles[key].hist_info.fill_color)
            line_colors.append(merger.hist_handles[key].hist_info.line_color)
            line_widths.append(merger.hist_handles[key].hist_info.line_width)
            line_styles.append(merger.hist_handles[key].hist_info.line_style)

    # ------------------------------------------------------------------------------
    def genLegendCanvas(self):
        leg_canvas = ROOT.TCanvas('legend')
        leg = self.genLegend('leg_canvas', full_canvas=True)
        leg.Draw()
        return leg_canvas

    # ------------------------------------------------------------------------------
    def genEntriesCanvas(self):
        entries_canvas = ROOT.TCanvas('entries')
        entries_hists = self.genEntriesHists()
        for i, eh in enumerate(entries_hists):
            if i == 0:
                eh.Draw('HIST')
            else:
                eh.Draw('HISTSAME')

        # entries_hist.Draw('HIST')
        return {'canv':entries_canvas, 'hists':entries_hists}

    # --------------------------------------------------------------------------
    def pile( self
            , num_type         = hh.Objects.plain_hist
            , denom_type       = hh.Objects.plain_hist
            , other_type       = hh.Objects.piled_hist
            , normalize        = False
            , canvas_options   = hh.canv_linear
            , legend           = False
            , int_lumi         = 0
            , prod_type        = ''
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
                    draw_opt_list.append(self.denom_draw_option)
            elif denom_type == hh.Objects.plain_hist:
                hist_list.append(self.denom_merger.hist_sum)
                draw_opt_list.append(self.denom_draw_option)
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
                draw_opt_list.append(self.num_draw_option)
        elif num_type == hh.Objects.plain_hist:
            hist_list.append(self.num_merger.hist_sum)
            draw_opt_list.append(self.num_draw_option)
        elif num_type == hh.Objects.stack_hist:
            # for stacked histograms, we want to add the sum also to get the
            # min/max right
            hist_list.append(self.num_merger.hist_sum)
            draw_opt_list.append('HIST')
            hist_list.append(self.num_merger.hist_stack)
            draw_opt_list.append('HIST')

        # get other hists
        if other_type == hh.Objects.piled_hist and self.other_merger is not None:
            for hl in self.other_merger.hist_list:
                hist_list.append(hl)
                # draw_opt_list.append('P')
                draw_opt_list.append(self.other_draw_option)
        elif other_type == hh.Objects.plain_hist:
            hist_list.append(self.other_merger.hist_sum)
            # draw_opt_list.append('P')
            draw_opt_list.append(self.other_draw_option)
        elif other_type == hh.Objects.stack_hist:
            # for stacked histograms, we want to add the sum also to get the
            # min/max right
            hist_list.append(self.other_merger.hist_sum)
            draw_opt_list.append('HIST')
            hist_list.append(self.other_merger.hist_stack)
            draw_opt_list.append('HIST')


        self.canvas = pileHists( hist_list
                               , tag
                               , draw_opt_list  = draw_opt_list
                               , canvas_options = canvas_options
                               )

        # # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        # if self.optimal_cut is not None:
        #     print 'Found optimal cut'
        #     self.cut_region = self.optimal_cut.genCutRegion(hist_list[0])
        #     if not self.cut_region is None:
        #         self.cut_region.Draw('F')

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        if legend:
            self.legend = self.genLegend()
            self.legend.Draw()
        drawLabels(int_lumi = int_lumi, prod_type = prod_type)

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        return self.canvas

    # --------------------------------------------------------------------------
    def pileAndRatio( self
                    , num_type         = hh.Objects.plain_hist
                    , denom_type       = hh.Objects.plain_hist
                    , other_type       = hh.Objects.piled_hist
                    , normalize        = False
                    , canvas_options   = hh.canv_linear
                    , legend           = False
                    , int_lumi         = 0
                    , prod_type        = ''
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
                 , other_type
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
        drawLabels(int_lumi = int_lumi, prod_type = prod_type)

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        return self.canvas

    # --------------------------------------------------------------------------
    def plotOnSeparateCanvases(self):
        labels = []
        hists  = []

        labels.append('num_sum')
        hists.append(self.num_merger.hist_sum)

        labels.append('denom_sum')
        hists.append(self.denom_merger.hist_sum)

        for ohh in self.other_merger.hist_handles:
            labels.append('%s_sum' % ohh)
            hists.append(self.other_merger.hist_handles[ohh].hist)

        setMin(hists, False)
        setMax(hists, False)

        canv_dict = {}
        for l, h in zip(labels, hists):
            canv_dict[l] = hh.canv_opt_2d.create(l)
            h.Draw('COLZ')

        # canv_dict['num_sum'] = hh.canv_opt_2d.create('num_sum')
        # self.num_merger.hist_sum.Draw('COLZ')

        # canv_dict['denom_sum'] = hh.canv_opt_2d.create('denom_sum')
        # self.denom_merger.hist_sum.Draw('COLZ')

        # for ohh in self.other_merger.hist_handles:
        #     label = '%s_sum' % ohh
        #     canv_dict[label] = hh.canv_opt_2d.create(label)
        #     self.other_merger.hist_handles[ohh].hist.Draw('COLZ')

        return canv_dict


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
        canvas_options = hh.canv_linear
    c = canvas_options.create(name)

    print 'about to set min/max:'
    print 'hist list:'
    for hl in hist_list:
        print '      %s -- %s' % (hl, hl.GetName())
    setMin(hist_list, canvas_options.log_y, y_min)
    setMax(hist_list, canvas_options.log_y, y_max)

    # actually draw plots
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
    # print 'calcMin()'
    if len(hist_list) == 0: return 0.
    # print hist_list

    # TODO come up with better algorithm
    extremes = getExtrema(hist_list, log_y)
    y_min = min(extremes)
    y_max = max(extremes)

    # add in a buffer on top and bottom
    # if log_y and y_min > 0 and y_max > 0:
    if log_y:
        if y_min > 0 and y_max > 0:
            y_min = math.pow( 10
                            , ( math.log(y_min, 10)
                              - (math.log(y_max, 10) - math.log(y_min, 10))*0.20
                              )
                            )
        else:
            y_min = 2e-3

        # HACK - update to handle proper min when dealing with a stack plot
        y_min = min(2e-3, y_min)
    else:
        y_min -= (y_max - y_min)*0.20
        y_min = max(y_min, 0.)

    # return value for min
    return y_min

# ------------------------------------------------------------------------------
def calcMax(hist_list, log_y = True):
    print '-----------------------------------------'
    print 'calcMax(log_y = %s)' % log_y
    print '- - - - - - - - - - - - - - - - - - - - -'
    if len(hist_list) == 0: return 0.

    # TODO come up with better algorithm
    extremes = getExtrema(hist_list, log_y)
    y_min = min(extremes)
    y_max = max(extremes)

    print 'extremes: %s' % extremes
    print 'y_min: %s' % y_min
    print 'y_max: %s' % y_max

    # add in a buffer on top and bottom
    # if log_y and y_min > 0 and y_max > 0:
    if log_y:
        print 'set y_max for log'
        if y_min > 0 and y_max > 0:
            y_max = math.pow( 10
                            , ( math.log(y_max, 10)
                              + (math.log(y_max, 10) - math.log(y_min, 10))*0.80
                              )
                            )
        else:
            y_max = 1
    else:
        print 'set y_max for linear'
        y_max += (y_max - y_min)*0.20
        y_max = max(y_max, 0.)

    # return value for max
    print 'new y_max: %s' % y_max
    print '========================================='
    return y_max

# ------------------------------------------------------------------------------
def getExtrema(hist_list, log_y = True):
    """docstring"""
    if len(hist_list) == 0: return 0.

    # TODO come up with better algorithm
    extrema = []
    for h in hist_list:
        local_min = None
        local_max = None

        h_tmp = h
        print '----------------------------------'
        print type(h)
        print type(h_tmp)
        if isinstance(h_tmp, ROOT.THStack): continue
        if isinstance(h_tmp, ROOT.TGraph):  continue
        if isinstance(h_tmp, ROOT.TGraphErrors): continue

        # print type(h_tmp)
        # num_bins = h_tmp.GetXaxis().GetNbins()
        num_bins = h_tmp.GetXaxis().GetNbins() + 2
        if isinstance(h_tmp, ROOT.TH2D) or isinstance(h_tmp, ROOT.TH2F):
            num_bins *= (h_tmp.GetYaxis().GetNbins()+2)

        print 'got number of bins:'
        print '  x: %s' % h_tmp.GetXaxis().GetNbins()
        print '  y: %s' % h_tmp.GetYaxis().GetNbins()
        print '  tot: %s' % num_bins
        # for b in xrange(1, num_bins+1):
        for b in xrange(0, num_bins):
            bin_content = h_tmp.GetBinContent(b)
            bin_content_up   = bin_content + h_tmp.GetBinError(b)
            bin_content_down = bin_content - h_tmp.GetBinError(b)

            # check if this bin is a minimum
            if local_min is None or bin_content_down < local_min:
                # if bin_content_down > 0 or not log_y:
                if bin_content_down > 0:
                    local_min = bin_content_down

            # check if this bin is a maxiumum
            if local_max is None or bin_content > local_max:
                # if bin_content_up > 0 or not log_y:
                if bin_content_up > 0:
                    local_max = bin_content_up

        if not local_min is None:
            extrema.append(local_min)
        if not local_max is None:
            extrema.append(local_max)

    if len(extrema) == 0:
        extrema = [0.01, 0.1] if log_y else [0., 1.]
    return extrema

# ------------------------------------------------------------------------------
def draw2DMaps( map_array
              , contour_levels = [1.64]
              , lumi           = None
              , prod_type      = ''
              ):
    # structure of elemets in map array are: # {'point_name':str, 'significance':float, 'cut_value':float}
    x_grid_points = []
    y_grid_points = []
    x_points      = []
    y_points      = []
    significance  = []
    cut_values    = []
    num_sig       = []

    for ma in map_array:
        x_grid_points.append(hh.Helper.getCharginoMass(  ma['point_name']))
        y_grid_points.append(hh.Helper.getNeutralinoMass(ma['point_name']))

        if ma['significance'] is not None:
            x_points.append(hh.Helper.getCharginoMass(  ma['point_name']))
            y_points.append(hh.Helper.getNeutralinoMass(ma['point_name']))
            significance.append(ma['significance'])
            cut_values.append(ma['cut_value'])
            num_sig.append(ma['num_sig'])

    # set axis titles
    # x_axis        = 'm_{#tilde{#chi}_{1}^{#pm}} [GeV]'
    x_axis        = 'm_{#tilde{#chi}_{1}^{#pm},#tilde{#chi}_{2}^{0}} [GeV]'
    y_axis        = 'm_{#tilde{#chi}_{1}^{0}} [GeV]'
    sig_title     = 'significance ; %s ; %s'      % (x_axis, y_axis)
    cut_title     = 'cut value ; %s ; %s'         % (x_axis, y_axis)
    num_sig_title = 'Num signal events ; %s ; %s' % (x_axis, y_axis)

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

    sig_graph.SetMinimum(0)
    sig_graph.SetMaximum(6.)
    cut_graph.SetMinimum(0)
    num_sig_graph.SetMinimum(0)

    # get contour lines frokm significance map
    contour_lines = getContourLines( sig_graph
                                   , contour_levels
                                   , [2]*len(contour_levels)
                                   )

    c_sig = hh.canv_opt_2d.create('c_sig_map')
    sig_graph.Draw('COLZ')
    grid_points.Draw('PSAME')
    for cl in contour_lines:
        cl.Draw('SAME')
    drawLabels(int_lumi = lumi, prod_type = prod_type)

    c_cut = hh.canv_opt_2d.create('c_cut_map')
    cut_graph.Draw('COLZ')
    grid_points.Draw('PSAME')
    for cl in contour_lines:
        cl.Draw('SAME')
    drawLabels(int_lumi = lumi, prod_type = prod_type)

    c_num_sig = hh.canv_opt_2d_log_y.create('c_num_sig_map')
    num_sig_graph.Draw('COLZ')
    grid_points.Draw('PSAME')
    for cl in contour_lines:
        cl.Draw('SAME')
    drawLabels(int_lumi = lumi, prod_type = prod_type)

    return { 'h_sig':sig_graph
           , 'h_cut':cut_graph
           , 'h_num_sig':num_sig_graph
           , 'c_sig':c_sig
           , 'c_cut':c_cut
           , 'c_num_sig':c_num_sig
           , 'contour':contour_lines
           , 'grid':grid_points
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

# ------------------------------------------------------------------------------
def drawLabels( int_lumi = 0
              , prod_type = ''
              ):
    """
    docstring
    """
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    AtlasLabels.ATLASLabel(0.20, 0.87, 1, 'Internal')
    if int_lumi is not None and int_lumi > 0:
        AtlasLabels.myText(0.20, 0.78, 1, '#intLdt = %s fb^{-1}' % int_lumi)
    if prod_type in prod_labels:
        AtlasLabels.myText(0.20, 0.70, 1, prod_labels[prod_type])


# ------------------------------------------------------------------------------
def draw2DHist(h, label):
    c = hh.canv_opt_2d.create(label)
    h.Draw('COLZ')
    return c
