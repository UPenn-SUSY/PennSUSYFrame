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

import HistObjects as ho
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
                ):
        """
        construtor
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        self.num_merger   = num
        self.denom_merger = denom

        self.name = name
        if self.name == None:
            self.name = num.hist_name

    # --------------------------------------------------------------------------
    # def gen_legend( self, hist_merger_list = [], name = 'leg', draw_opt = [] ):
    def gen_legend( self, name = 'leg'):
        """
        Generates a legend based on a list of HistMerger objects
        """
        # TODO add variables for the placement of the legend
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        # get list of histograms and labels from the HistMergers passed as inputs
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
            , num_type         = ho.plain_hist
            , denom_type       = ho.plain_hist
            , normalize        = False
            , canvas_options   = canv_default
            ):
        """
        docstring
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        if normalize:
            assert num_type   == ho.plain_hist
            assert denom_type == ho.plain_hist

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
            if denom_type == ho.piled_hist:
                for hl in self.denom_merger.hist_list:
                    hist_list.append(hl)
                    draw_opt_list.append('P')
            elif denom_type == ho.plain_hist:
                hist_list.append(self.denom_merger.hist_sum)
                draw_opt_list.append('P')
            elif denom_type == ho.stack_hist:
                # for stacked histograms, we want to add the sum also to get the
                # min/max right
                hist_list.append(self.denom_merger.hist_sum)
                draw_opt_list.append('HIST')
                hist_list.append(self.denom_merger.hist_stack)
                draw_opt_list.append('HIST')
                hist_list.append(self.denom_merger.error_band)
                draw_opt_list.append('E2')

        # get numerator hists
        if num_type == ho.piled_hist:
            for hl in self.num_merger.hist_list:
                hist_list.append(hl)
                draw_opt_list.append('P')
        elif num_type == ho.plain_hist:
            hist_list.append(self.num_merger.hist_sum)
            draw_opt_list.append('P')
        elif num_type == ho.stack_hist:
            # for stacked histograms, we want to add the sum also to get the
            # min/max right
            hist_list.append(self.num_merger.hist_sum)
            draw_opt_list.append('HIST')
            hist_list.append(self.num_merger.hist_stack)
            draw_opt_list.append('HIST')


        pile = pileHists( hist_list
                        , tag
                        , draw_opt_list = draw_opt_list
                        , canvas_options = canvas_options
                        )

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        return pile

    # --------------------------------------------------------------------------
    def pile_and_ratio( num_type         = ho.plain_hist
                      , denom_type       = ho.plain_hist
                      , normalize        = False
                      , ratio_axis_title = 'ratio'
                      ):
        """
        docstring
        """
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        assert not num_type   == ho.pile_hists
        assert not denom_type == ho.pile_hists

        if normalize:
            assert num_type   == ho.plain_hist
            assert denom_type == ho.plain_hist

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# ------------------------------------------------------------------------------
def flatten(l, level = 0):
    """
    takes a list of lists, and flattens into a single list
    """
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    flat_l = []
    if isinstance(l, list):
        for e in l:
            flat_l += flatten(e)
    else:
        flat_l = [l]

    return flat_l

# --------------------------------------------------------------------------
def getTag( num_type   = ho.plain_hist
          , denom_type = ho.plain_hist
          , normalize  = False
          ):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    tag = '_%s' % ho.typeToString(num_type)

    if not denom_type == None:
        tag += '_%s' % ho.typeToString(denom_type)

    if normalize:
        tag += '_norm'

    return tag


# ------------------------------------------------------------------------------
def pileHists( hist_list
             , name
             , draw_opt_list = metaroot.default
             , title = None
             , canvas_options = metaroot.default
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

    y_min = setMin(hist_list, canvas_options.log_y)
    y_max = setMax(hist_list, canvas_options.log_y)

    # actuall draw plots
    drawn_first = False
    for i, h in enumerate(hist_list):
        draw_opt = draw_opt_list[i]
        if not drawn_first:
            if isinstance(h, ROOT.TGraph) or isinstance(h, ROOT.TGraphAsymmErrors):
                draw_opt += 'A'
        else:
            draw_opt += 'SAME'
        print 'draw option: %s' % draw_opt
        h.Draw(draw_opt)
        drawn_first = True

    return c


# ------------------------------------------------------------------------------
def setMin(hist_list, log_y = False):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    y_min = calcMin(hist_list, log_y)

    for h in hist_list:
        h.SetMinimum(y_min)

    return y_min

# ------------------------------------------------------------------------------
def setMax(hist_list, log_y = False):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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

            # if bin_content <= 0 and log_y: continue
            # if bin_content <= 0 and log_y: continue

            if local_min is None or bin_content_down < local_min:
                if bin_content_down > 0 or not log_y:
                    local_min = bin_content_down

            if local_max is None or bin_content > local_max:
                if bin_content_up > 0 or not log_y:
                    local_max = bin_content_up

        if not local_min is None:
            extrema.append(local_min)
        if not local_max is None:
            extrema.append(local_max)

    return extrema
