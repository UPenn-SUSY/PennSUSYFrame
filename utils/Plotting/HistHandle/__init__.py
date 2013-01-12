#!/usr/bin/env python

#------------------------------------------------------------------------------
# module metadata
#------------------------------------------------------------------------------
__author__ = 'Brett Jackson'
__email__ = 'brett.david.jackson@cern.ch'
__copyright__ = 'Copyright 2008-2012 Ryan D. Reece'
__license__ = 'GPL http://www.gnu.org/licenses/gpl.html'

import metaroot

default = object()
ignore_zeros = object()

left  = object()
right = object()
equal = object()

canv_linear = metaroot.hist.CanvasOptions(width=800, height=600)
canv_log_y  = metaroot.hist.CanvasOptions(width=800, height=600, log_y=True)
canv_opt_2d = metaroot.hist.CanvasOptions( width=800
                                         , height=600
                                         # , right_margin=10
                                         , right_margin=30
                                         )
canv_opt_2d_log_y = metaroot.hist.CanvasOptions( width=800
                                               , height=600
                                               # , right_margin=10
                                               , right_margin=30
                                               , log_z=True
                                               )

import Handle, Merger, Objects, Painter, parse, Helper, Optimize
