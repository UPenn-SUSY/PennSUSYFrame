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
