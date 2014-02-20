#!/usr/bin/env python

import sys
import os.path
import optparse
import time

import ROOT
import rootlogon

import HistHandle as hh

# ==============================================================================
# useful objects for classification
plain_hist = object()
piled_hist = object()
stack_hist = object()

# --------------------------------------------------------------------------
def typeToString(hist_type):
    if hist_type == plain_hist: return 'sum'
    if hist_type == piled_hist: return 'pile'
    if hist_type == stack_hist: return'stack'
    return ''

# ==============================================================================
class HistInfo(object):
    """
    docstring
    """
    # --------------------------------------------------------------------------
    def __init__( self
                , name
                , fill_color = 1
                , line_color = 1
                , line_width = 1
                , line_style = 1
                , marker_style = 20
                ):
        self.name = name
        self.fill_color = fill_color
        self.line_color = line_color
        self.line_width = line_width
        self.line_style = line_style
        self.marker_style = marker_style

    def setHistStyle(self, hist):
        hist.SetFillColor(  self.fill_color)
        hist.SetLineColor(  self.line_color)
        hist.SetLineWidth(  self.line_width)
        hist.SetLineStyle(  self.line_style)
        hist.SetMarkerColor(self.fill_color)
        hist.SetMarkerStyle(self.marker_style)

# ==============================================================================
class CanvasInfo(object):
    """
    docstring
    """
    # --------------------------------------------------------------------------
    def __init__( self
                , width = 600
                , height = 600
                , left_margin = 0.15
                , right_margin = 0.15
                , top_margin = 0.15
                , bottom_margin = 0.15
                , log_x = False
                , log_y = False
                , log_z = False
                ):
        self.width = width
        self.height = height
        self.left_margin   = left_margin
        self.right_margin  = right_margin
        self.top_margin    = top_margin
        self.bottom_margin = bottom_margin
        self.log_x = log_x
        self.log_y = log_y
        self.log_z = log_z

    # --------------------------------------------------------------------------
    def configure(self, c):
        c.UseCurrentStyle()
        c.SetLogx(self.log_x)
        c.SetLogy(self.log_y)
        c.SetLogz(self.log_z)

        if not self.left_margin is hh.default:
            c.SetLeftMargin(self.left_margin)
        if not self.right_margin is hh.default:
            c.SetRightMargin(self.right_margin)
        if not self.top_margin is hh.default:
            c.SetTopMargin(self.top_margin)
        if not self.bottom_margin is hh.default:
            c.SetBottomMargin(self.bottom_margin)

        c.SetBorderSize(0)
        c.SetBorderMode(0)
        c.Update()

    # --------------------------------------------------------------------------
    def create(self, name, title = hh.default):
        if title is hh.default:
            title = name
        c = ROOT.TCanvas(name, title, self.width, self.height)
        self.configure(c)
        return c

# ==============================================================================
canv_linear = CanvasInfo( width  = 600
                        , height = 600
                        )
canv_log_y = CanvasInfo( width  = 600
                       , height = 600
                       )
canv_2d = CanvasInfo( width  = 600
                    , height = 600
                    , right_margin = 0.15
                    )
canv_2d_log_z = CanvasInfo( width  = 600
                          , height = 600
                          , right_margin = 0.15
                          , log_z = True
                          )
