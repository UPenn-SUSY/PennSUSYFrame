#!/usr/bin/env python

import sys
import os.path
import optparse
import time

import ROOT
import rootlogon
import metaroot

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
                , line_color = 1
                , fill_color = 1
                , marker_style = 20
                ):
        self.name = name
        self.line_color = line_color
        self.fill_color = fill_color
        self.marker_style = marker_style

    def setHistStyle(self, hist):
        hist.SetLineColor(  self.line_color)
        hist.SetFillColor(  self.fill_color)
        hist.SetMarkerColor(self.fill_color)
        hist.SetMarkerStyle(self.marker_style)

