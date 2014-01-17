#!/usr/bin/env python

#------------------------------------------------------------------------------
# module metadata
#------------------------------------------------------------------------------
__author__ = 'Brett Jackson'
__email__ = 'brett.david.jackson@cern.ch'

import metaroot

default = object()
ignore_zeros = object()

left  = object()
right = object()
equal = object()

HIST_1D = object()
HIST_2D = object()

canv_linear = metaroot.hist.CanvasOptions(width=600, height=600)
canv_log_y  = metaroot.hist.CanvasOptions(width=600, height=600, log_y=True)
canv_opt_2d = metaroot.hist.CanvasOptions( width=600
                                         , height=600
                                         # , right_margin=10
                                         # , right_margin=50
                                         , right_margin=0.15
                                         )
canv_opt_2d_log_y = metaroot.hist.CanvasOptions( width=600
                                               , height=600
                                               # , right_margin=10
                                               # , right_margin=50
                                               , right_margin=0.15
                                               , log_z=True
                                               )

import Handle, Merger, Objects, Painter, parse, Helper, Optimize, AtlasLabels