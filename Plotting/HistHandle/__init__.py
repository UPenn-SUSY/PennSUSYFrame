#!/usr/bin/env python

from ROOT import gStyle, TColor
from array import array

#------------------------------------------------------------------------------
# module metadata
#------------------------------------------------------------------------------
__author__ = 'Brett Jackson'
__email__ = 'brett.david.jackson@cern.ch'

default      = object()
ignore_zeros = object()

left  = object()
right = object()
equal = object()

HIST_1D = object()
HIST_2D = object()

# default margins
default_canv_width        = 600
default_canv_height       = 800

default_ratio_pad_size = 0.25

default_pad_left_margin   = 0.16
default_pad_right_margin  = 0.09
default_pad_top_margin    = 0.05
default_pad_bottom_margin = 0.16

default_label_size = 0.04
default_title_size = 0.05

#------------------------------------------------------------------------------
# import modules
#------------------------------------------------------------------------------
# import Handle, Merger, Objects, Painter, parse, Helper, Optimize, AtlasLabels
import Handle, Merger, Objects, Painter, Container, Helper, AtlasLabels

#------------------------------------------------------------------------------
# style stuff
#------------------------------------------------------------------------------
# whitening
gStyle.SetStatColor(0)
gStyle.SetCanvasColor(0)
gStyle.SetFrameFillColor(0)
gStyle.SetPadColor(0)
gStyle.SetPadBorderMode(0)
gStyle.SetCanvasBorderMode(0)
gStyle.SetFrameBorderMode(0)

# stat box
gStyle.SetOptStat(0)

# title
gStyle.SetOptTitle(0)
gStyle.SetTitleFillColor(0)
gStyle.SetTitleStyle(0)
gStyle.SetTitleBorderSize(0)
gStyle.SetTitleY(1.)
gStyle.SetTitleX(.1)

# pad ticks
#gStyle.SetPadTickX(1)
#gStyle.SetPadTickY(1)

# grid lines
# gStyle.SetPadGridX(1);
gStyle.SetPadGridY(1);

## set times fonts
font = 42 # Helvetica
# font = 72 # Helvetica italics
# font = 22 # Times new roman
gStyle.SetLabelFont(font, 'xyz')
gStyle.SetTitleFont(font, 'xyzt')
gStyle.SetTitleFont(font, 't')
gStyle.SetStatFont(font)
gStyle.SetTextFont(font)

# gStyle.SetPaintTextFormat('5.3f')
# set font sizes
gStyle.SetLabelSize(default_label_size, 'xyz')
gStyle.SetTitleSize(default_label_size, 'xyz')
gStyle.SetTitleSize(default_title_size, 't')

# title offset
gStyle.SetTitleOffset(1.2, 'x')
gStyle.SetTitleOffset(1.5, 'y')
gStyle.SetTitleOffset(0.8, 'z')

# 2d color palettes
def set_palette(name='default', ncontours=200):
    """Set a color palette from a given RGB list
    stops, red, green and blue should all be lists of the same length
    see set_decent_colors for an example"""

    if name == 'gray' or name == 'grayscale':
        stops = [0.00, 0.34, 0.61, 0.84, 1.00]
        red   = [1.00, 0.84, 0.61, 0.34, 0.00]
        green = [1.00, 0.84, 0.61, 0.34, 0.00]
        blue  = [1.00, 0.84, 0.61, 0.34, 0.00]
    # elif name == "whatever":
        # (define more palettes)
    elif name == 'brett':
        # brett palette
        print 'Setting palette to "Brett"'
        stops = [0.00, 0.05, 0.10, 0.20, 0.30, 0.40, 0.50, 0.60, 0.70, 0.80,  0.90, 0.95, 1.00]
        red   = [0.00, 0.00, 0.05, 0.05, 0.10, 0.15, 0.70, 0.90, 1.00, 1.00,  1.00, 1.00, 0.51]
        green = [0.00, 0.00, 0.50, 0.50, 1.00, 0.90, 0.90, 0.90, 0.80, 0.60,  0.60, 0.00, 0.00]
        blue  = [0.51, 1.00, 1.00, 0.60, 0.50, 0.30, 0.20, 0.15, 0.10, 0.05,  0.05, 0.00, 0.00]

    else:
        # default palette, looks cool
        stops = [0.00, 0.34, 0.61, 0.84, 1.00]
        red   = [0.00, 0.00, 0.87, 1.00, 0.51]
        green = [0.00, 0.81, 1.00, 0.20, 0.00]
        blue  = [0.51, 1.00, 0.12, 0.00, 0.00]

    s = array('d', stops)
    r = array('d', red)
    g = array('d', green)
    b = array('d', blue)

    npoints = len(s)
    TColor.CreateGradientColorTable(npoints, s, r, g, b, ncontours)
    gStyle.SetNumberContours(ncontours)

# set_palette()
set_palette('brett')

## force style
from ROOT import gROOT
gROOT.ForceStyle()
