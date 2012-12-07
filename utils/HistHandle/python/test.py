#!/usr/bin/env python

import sys
import os.path
import optparse
import time
import random
import string
from array import array

import ROOT
import rootlogon
import metaroot

import HistHandle as hh
import HistObjects as ho
import HistPainter as hp

# ==============================================================================
if __name__ == '__main__':
    f_data = ROOT.TFile('/Users/bjackson/work/Susy.00-01-08/utils/HistMaker/data.root')
    f_mc1 = ROOT.TFile('/Users/bjackson/work/Susy.00-01-08/utils/HistMaker/mc_1.root')
    f_mc2 = ROOT.TFile('/Users/bjackson/work/Susy.00-01-08/utils/HistMaker/mc_2.root')
    f_mc3 = ROOT.TFile('/Users/bjackson/work/Susy.00-01-08/utils/HistMaker/mc_3.root')

    hi_data = ho.HistInfo('data', 1, 1, 20)
    hi_mc   = ho.HistInfo('mc1' , 2, 2, ROOT.kOpenCircle)
    hi_mc1  = ho.HistInfo('mc1' , 3, 3, ROOT.kOpenSquare)
    hi_mc23 = ho.HistInfo('mc23', 4, 4, ROOT.kOpenTriangleUp)

    hh_data = hh.HistHandle( 'ee_sig_lep'
                           , 'mll'
                           , hi_data
                           , [f_data]
                           )

    hh_mc1 = hh.HistHandle( 'ee_sig_lep'
                          , 'mll'
                          , hi_mc1
                          , f_mc1
                          )

    hh_mc23 = hh.HistHandle( 'ee_sig_lep'
                           , 'mll'
                           , hi_mc23
                           , [f_mc2, f_mc3]
                           )


    hm_data = hh.HistMerger('ee_sig_lep', 'mll', {'data':hh_data}, hi_data)
    hm_mc   = hh.HistMerger( 'ee_sig_lep', 'mll', { 'mc1':hh_mc1
                                                  , 'mc23':hh_mc23
                                                  }
                           , hi_mc
                           )

    hm_data.genMergedHist()
    hm_mc.genMergedHist()


    hist_painter = hp.HistPainter( num   = hm_data
                                 , denom = hm_mc
                                 )

    canv_default = metaroot.hist.CanvasOptions(width=800, height=600)
    canv_log_y   = metaroot.hist.CanvasOptions(width=800, height=600, log_y=True)


    print 'Linear'
    pile_test_stack = hist_painter.pileAndRatio( num_type       = ho.plain_hist
                                               , denom_type     = ho.stack_hist
                                               , canvas_options = canv_default
                                               , legend         = True
                                               )
    leg = hist_painter.genLegend()
    leg.Draw()
    pile_test_stack.Print('~/Desktop/test_linear.png')
    pile_test_stack.Close()

    print 'Log'
    pile_test_stack = hist_painter.pileAndRatio( num_type       = ho.plain_hist
                                               , denom_type     = ho.stack_hist
                                               , canvas_options = canv_log_y
                                               , legend         = True
                                               )
    leg.Draw()
    pile_test_stack.Print('~/Desktop/test_log.png')
    pile_test_stack.Close()
