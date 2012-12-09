#!/usr/bin/env python

import HistHandle as hh
import metaroot

# ==============================================================================
if __name__ == '__main__':
    config = hh.parse.parseInputs()

    hm_num   = config['Numerator'  ].genHistMerger( 'ee_sig_lep', 'mll')
    hm_denom = config['Denominator'].genHistMerger( 'ee_sig_lep', 'mll')

    hist_painter = hh.Painter.HistPainter( num   = hm_num
                                         , denom = hm_denom
                                         )

    canv_default = metaroot.hist.CanvasOptions(width=800, height=600)
    canv_log_y   = metaroot.hist.CanvasOptions(width=800, height=600, log_y=True)

    print 'Log'
    pile_test_stack = hist_painter.pileAndRatio( num_type       = hh.Objects.plain_hist
                                               , denom_type     = hh.Objects.stack_hist
                                               , canvas_options = canv_log_y
                                               , legend         = True
                                               )
    # pile_test_stack.Print('~/Desktop/test_log.png')
    pile_test_stack.Print('test_log.png')
    pile_test_stack.Close()
