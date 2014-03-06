#!/usr/bin/env python

import sys
import os.path
import optparse
import time
import random
import string
from array import array

import ROOT

import HistHandle as hh
ho = hh.Objects
hp = hh.Painter

# ==============================================================================
if __name__ == '__main__':
    f_data = ROOT.TFile('${BASE_WORK_DIR}/BMinusL.105200.ttbar.hists.root')
    f_mc1  = ROOT.TFile('${BASE_WORK_DIR}/BMinusL.105200.ttbar.hists.root')
    f_mc2  = ROOT.TFile('${BASE_WORK_DIR}/BMinusL.105200.ttbar.hists.root')
    f_mc3  = ROOT.TFile('${BASE_WORK_DIR}/BMinusL.105200.ttbar.hists.root')

    hi_data = ho.HistInfo( name = 'data', fill_color = 1, line_color = 1, marker_style = 20)
    hi_mc   = ho.HistInfo( name = 'mc1' , fill_color = 2, line_color = 2, marker_style = ROOT.kOpenCircle)
    hi_mc1  = ho.HistInfo( name = 'mc1' , fill_color = 3, line_color = 3, marker_style = ROOT.kOpenSquare)
    hi_mc23 = ho.HistInfo( name = 'mc23', fill_color = 4, line_color = 4, marker_style = ROOT.kOpenTriangleUp)

    hh_data = hh.Handle.HistHandle( directory = 'hists'
                                  , hist_name = 'flavor_none__mbl_all'
                                  , hist_info = hi_data
                                  , input_files = [f_data]
                                  )

    hh_mc1 = hh.Handle.HistHandle( directory = 'hists'
                                 , hist_name = 'flavor_none__mbl_all'
                                 , hist_info = hi_mc1
                                 , input_files = f_mc1
                                 )

    hh_mc23 = hh.Handle.HistHandle( directory = 'hists'
                                  , hist_name = 'flavor_none__mbl_all'
                                  , hist_info = hi_mc23
                                  , input_files = [f_mc2, f_mc3]
                                  )


    hm_data = hh.Merger.HistMerger( directory = 'hists'
                                  , hist_name = 'flavor_none__mbl_all'
                                  , hist_handle_dict = {'data':hh_data}
                                  , hist_info = hi_data
                                  )
    hm_mc   = hh.Merger.HistMerger( directory = 'hists'
                                  , hist_name = 'flavor_none__mbl_all'
                                  , hist_handle_dict = { 'mc1':hh_mc1
                                                       , 'mc23':hh_mc23
                                                       }
                                  , hist_info = hi_mc
                                  )

    hm_data.genMergedHist()
    hm_mc.genMergedHist()


    hist_painter = hp.HistPainter( num   = hm_data
                                 , denom = hm_mc
                                 )

    canv_default = ho.CanvasInfo(width=800, height=600)
    canv_log_y   = ho.CanvasInfo(width=800, height=600, log_y=True)

    out_file = ROOT.TFile('out_hists.root', "RECREATE")

    print 'Linear'
    pile_test_stack = hist_painter.pile( num_type       = ho.plain_hist
                                       , denom_type     = ho.stack_hist
                                       , canvas_options = canv_default
                                       , legend         = True
                                       )
    # TODO add ratio back in
    # pile_test_stack = hist_painter.pileAndRatio( num_type       = ho.plain_hist
    #                                            , denom_type     = ho.stack_hist
    #                                            , canvas_options = canv_default
    #                                            , legend         = True
    #                                            # , ratio_axis_title = 'Data/MC'
    #                                            )
    leg = hist_painter.genLegend()
    # TODO draw legend again
    leg.Draw()
    pile_test_stack.Print('test_linear.png')
    pile_test_stack.Write('test_linear')
    pile_test_stack.Close()

    print 'Log'
    pile_test_stack = hist_painter.pile( num_type       = ho.plain_hist
                                       , denom_type     = ho.stack_hist
                                       , canvas_options = canv_log_y
                                       , legend         = True
                                       )
    # TODO add ratio back in
    # pile_test_stack = hist_painter.pileAndRatio( num_type       = ho.plain_hist
    #                                            , denom_type     = ho.stack_hist
    #                                            , canvas_options = canv_log_y
    #                                            , legend         = True
    #                                            )
    # TODO draw legend again
    leg.Draw()
    pile_test_stack.Print('test_log.png')
    pile_test_stack.Write('test_log')
    pile_test_stack.Close()

    out_file.Close()
