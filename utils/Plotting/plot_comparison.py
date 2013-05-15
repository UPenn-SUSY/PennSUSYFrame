#!/usr/bin/env python

import ROOT
import HistHandle as hh
import metaroot

# -----------------------------------------------------------------------------
def skipHist(dir_name, hist_name):
  """
  hack way to avoid plotting nonsense histograms
  eg. muon pt for ee events
  TODO update for new naming schemes
  """
  # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  if 'ee' in dir_name and 'mu_' in hist_name:
    return True
  if 'mm' in dir_name and 'el_' in hist_name:
    return True
  if 'em' in dir_name:
    if 'el_1' in hist_name or 'mu_1' in hist_name:
      return True
  return False

# ==============================================================================
def main():
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # root stuff
    ROOT.TH1.SetDefaultSumw2()
    ROOT.gROOT.SetBatch()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    inputs = hh.parse.parseInputs()
    if inputs == None:
        return 0
    config = inputs['config']
    file_list = inputs['files']
    out_file_name = inputs['outfile']

    # TODO after debugging, switch back to 'create'
    # out_file = ROOT.TFile(out_file_name, 'CREATE')
    out_file = ROOT.TFile(out_file_name, 'RECREATE')

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    dirs = hh.Helper.get_list_of_dirs(file_list)
    hists = hh.Helper.get_list_of_hists(file_list[0].GetDirectory(dirs[0]))
    print hists
    for d in dirs:
        out_file.cd()
        out_file.mkdir(d)
        out_file.cd(d)

        legend_canvas_drawn  = False
        entries_canvas_drawn = False
        for it, h in enumerate(hists):
            if skipHist(d,h): continue

            out_file.cd(d)

            hm_num   = config['Numerator'  ].genHistMerger(d, h)
            hm_denom = config['Denominator'].genHistMerger(d, h)
            hm_other = config['Other'].genHistMerger(d,h) if 'Other' in config else None

            # if this is a 1D histogram, draw as stack with ratio
            if hm_num.hist_type is hh.HIST_1D:
                hist_painter = hh.Painter.HistPainter( num   = hm_num
                                                     , denom = hm_denom
                                                     , other = hm_other
                                                     )

                print 'Log'
                pile_test_stack = hist_painter.pileAndRatio(
                        num_type       = hh.Objects.plain_hist,
                        denom_type     = hh.Objects.stack_hist,
                        canvas_options = hh.canv_log_y,
                        legend         = True)

                pile_test_stack.Write('%s__log' % h)
                pile_test_stack.Close()

                print 'Linear'
                pile_test_stack = hist_painter.pileAndRatio(
                        num_type       = hh.Objects.plain_hist,
                        denom_type     = hh.Objects.stack_hist,
                        canvas_options = hh.canv_linear,
                        legend         = True)

                pile_test_stack.Write('%s__lin' % h)
                pile_test_stack.Close()

                # draw legend canvas if not done yet
                if not legend_canvas_drawn:
                    legend_canvas = hist_painter.genLegendCanvas()
                    legend_canvas.Write('__legend')
                    legend_canvas.Close()
                    legend_canvas_drawn = True

                if not entries_canvas_drawn:
                    entries_canvas = hist_painter.genEntriesCanvas()
                    entries_canvas['canv'].Write('__entries')
                    entries_canvas['canv'].Close()
                    entries_canvas_drawn = True

            # If this is a 2D histogram, draw as colz plots in separate directory
            if hm_num.hist_type  is hh.HIST_2D:
                print 'making directory: %s/%s' % (d,h)
                local_dir = out_file.Get(d)
                local_dir.mkdir(h)
                out_file.cd('%s/%s' % (d,h))

                hist_painter = hh.Painter.HistPainter( num   = hm_num
                                                     , denom = hm_denom
                                                     , other = hm_other
                                                     , num_draw_option   = 'COLZ'
                                                     , denom_draw_option = 'COLZ'
                                                     , other_draw_option = 'COLZ'
                                                     )

                canv_dict = hist_painter.plotOnSeparateCanvases()

                for cd in canv_dict:
                    canv_dict[cd].Write('h_%s' % cd)
                    canv_dict[cd].Close()

                # num_canv = hh.Painter.draw2DHist(hm_num.hist_sum, hm_num.hist_name)
                # num_canv.Write('%s__num' % hm_num.hist_name)
                # num_canv.Close()

                # denom_canv = hh.Painter.draw2DHist(hm_denom.hist_sum, hm_denom.hist_name)
                # denom_canv.Write('%s__denom' % hm_denom.hist_name)
                # denom_canv.Close()



    out_file.Close()

# ==============================================================================
if __name__ == '__main__':
    main()
