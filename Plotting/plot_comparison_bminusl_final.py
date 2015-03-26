#!/usr/bin/env python

import ROOT
import HistHandle as hh
import sys


# -----------------------------------------------------------------------------
def skipHist(dir_name, hist_name):
    """
    hack way to avoid plotting nonsense histograms
    eg. muon pt for ee events
    TODO update for new naming schemes
    """
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # skip lepton flavors that don't match with the flavor channel
    if 'ee' in dir_name and 'mu_' in hist_name:
        return True
    if 'mm' in dir_name and 'el_' in hist_name:
        return True
    if 'em' in dir_name:
        if 'el_1' in hist_name or 'mu_1' in hist_name:
            return True

    if 'flavor_error' in hist_name:
        return True

    if 'mbl_0' not in hist_name:
        return True

    return False


# ------------------------------------------------------------------------------
def makeFinalPlot(dir_name,
                  hist,
                  ic_numerator,
                  ic_denominator,
                  ic_other,
                  out_file,
                  y_max_lin,
                  y_max_log,
                  y_min_log=None,
                  do_ratio=False):
    out_file.cd()
    out_file.mkdir(dir_name)
    out_file.cd(dir_name)

    full_hist_name = '__'.join([hist, dir_name])
    print 'dir: ', dir_name
    print 'full hist name: ', full_hist_name

    hm_num = (None if ic_numerator is None or ic_numerator.lumi_target <= 0
              else ic_numerator.genHistMerger(dir_name, full_hist_name))
    hm_denom = (None if ic_denominator is None or
                        ic_denominator.lumi_target <= 0
                else ic_denominator.genHistMerger(dir_name, full_hist_name))
    hm_other = (None if ic_other is None else
                ic_other.genHistMerger(dir_name, full_hist_name))

    print hm_denom.hist_stack
    print hm_denom.hist_sum

    for y_scale in ['lin', 'log']:
        # create the canvas for drawing
        canvas_options = (hh.Objects.canv_log_y if y_scale == 'log'
                          else hh.Objects.canv_linear)
        canvas_name = '__'.join([full_hist_name, y_scale])
        c = canvas_options.create(canvas_name)

        # flag to say if anything has been drawn yet
        first_drawn = False

        hist_list = []
        label_list = []
        draw_opt_list = []

        # simple function to prepare the fist plot
        def prepareFirstHist(hist):
            if y_scale == 'log':
                hist.SetMaximum(y_max_log)
                if y_min_log is not None:
                    hist.SetMinimum(y_min_log)
            else:
                hist.SetMaximum(y_max_lin)

            axis = hist.GetXaxis()
            bin_size = (axis.GetXmax() - axis.GetXmin())/axis.GetNbins()

            if bin_size > 0.049 and bin_size < 0.051:
                bin_size = 0.05
            if bin_size >= 1 and bin_size % 1 == 0:
                bin_size = int(bin_size)

            print 'bin size: ' , bin_size
            hist_name = hist.GetName()
            unit = 'GeV' if 'asym' not in hist_name.lower() else ''
            y_axis_title = 'Entries/%s %s' % (bin_size, unit)
            hist.GetYaxis().SetTitle(y_axis_title)

        # step through the denominator hist mergers and draw them
        if hm_denom is not None:
            option = 'HIST'

            if first_drawn:
                option += 'SAME'
            else:
                prepareFirstHist(hm_denom.hist_sum)

            hm_denom.hist_sum.SetLineWidth(3)
            hm_denom.hist_sum.SetLineColor(ROOT.kBlue-7)
            hm_denom.hist_sum.Draw(option)

            hist_list.append(hm_denom.hist_sum)
            label_list.append('Total background')
            draw_opt_list.append('L')

            # set line width of sub-histograms in stack and add to list for
            # legend making
            for key, hm in zip(hm_denom.hist_handles_keys, hm_denom.hist_list):
                hm.SetLineWidth(0)

                hist_list.append(hm)
                label_list.append(hh.Helper.genLegendLabel(key))
                draw_opt_list.append('F')

            option = 'HISTSAME'
            hm_denom.hist_stack.Draw(option)

            # draw again so it's on top
            hm_denom.hist_sum.Draw(option)
            hm_denom.error_band.Draw('E2SAME')

            first_drawn = True

        # step through the other hist mergers, and draw them
        if hm_other is not None:
            for key, hm in zip(hm_other.hist_handles_keys, hm_other.hist_list):
                hm.SetLineStyle(ROOT.kDashed)
                option = 'HIST'

                if first_drawn:
                    option += 'SAME'
                else:
                    prepareFirstHist(hm)

                hm.Draw(option)

                hist_list.append(hm)
                label_list.append(hh.Helper.genLegendLabel(key))
                draw_opt_list.append('L')

                first_drawn = True

        # make and draw a legend
        leg = hh.Helper.makeLegend(hist_list, label_list, draw_opt_list,
                                   width=0.35, height=0.03, y2=0.93)
        leg.Draw()

        # add ATLAS boilerplate
        label_x = 0.2
        label_y = 0.87
        delta_y = 0.09
        # if 'mbl_asym' in hist.lower():
        #     label_x = 0.25

        hh.AtlasLabels.ATLASLabel(label_x, label_y, 1, 'Simulation Preliminary')
        hh.AtlasLabels.myText(label_x, label_y - delta_y, 1,
                              '#sqrt{s} = 8 TeV, 20.3 fb^{-1}')
        # hh.AtlasLabels.myText(label_x, label_y-1.9*delta_y, 1,
        #                       '#intLdt = 20.3 fb^{-1}')

        # add lines for cuts if it is appropriate
        def draw_arrow(height, length, cut_value, color, line_size_top,
                       line_min=0):
            arrow_size = 0.01
            arrow_line_width = 3

            arrow = ROOT.TArrow(cut_value, height,
                                cut_value+length, height,
                                arrow_size, '>')
            arrow.SetLineStyle(1)
            arrow.SetLineWidth(arrow_line_width)
            arrow.SetLineColor(color)
            arrow.Draw("SAME>")

            # line = ROOT.TLine(cut_value, (1-line_size)*height,
            line = ROOT.TLine(cut_value, line_min,
                              cut_value, (1+line_size_top)*height)
            line.SetLineStyle(1)
            line.SetLineWidth(arrow_line_width)
            line.SetLineColor(color)
            line.Draw("SAME")

            return (arrow, line)

        if '_minus_ht' in dir_name.lower() and 'ht_signal' in hist.lower():
            arrow = draw_arrow(height=200, length=100, cut_value=1100,
                               color=ROOT.kBlue+3, line_size_top=0.5)

        if '_minus_mbl' in dir_name.lower() and 'mbl_0' in hist.lower():
            arrow = draw_arrow(height=13, length=40, cut_value=400,
                               color=ROOT.kBlue+3, line_size_top=0.3)
            arrow2 = draw_arrow(height=13, length=40, cut_value=600,
                                color=ROOT.kRed+3, line_size_top=0.3)

        if '_minus_mbl_asym' in dir_name.lower() and 'mbl_asym' in hist.lower():
            arrow = draw_arrow(height=15, length=-0.04, cut_value=0.20,
                               color=ROOT.kBlue+3, line_size_top=0.2)

        # write to file
        c.Write(canvas_name)
        c.Close()

# ------------------------------------------------------------------------------
def plotComparisons( ic_numerator
                   , ic_denominator
                   , ic_other
                   , out_file_name
                   , do_ratio=True
                   ):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # root stuff
    ROOT.TH1.SetDefaultSumw2()
    ROOT.gROOT.SetBatch()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    file_list = hh.Container.getListOfFiles([ic_numerator, ic_denominator])

    # TODO after debugging, switch back to 'create'
    # out_file = ROOT.TFile(out_file_name, 'CREATE')
    out_file = ROOT.TFile(out_file_name, 'RECREATE')

    makeFinalPlot(dir_name='BMINUSL_SR_HT_1100_MINUS_MBL',
                  hist='flavor_all__mbl_0',
                  ic_numerator=ic_numerator,
                  ic_denominator=ic_denominator,
                  ic_other=ic_other,
                  out_file=out_file,
                  y_max_lin=60,
                  y_max_log=3000,
                  y_min_log=0.01,
                  do_ratio=do_ratio)

    makeFinalPlot(dir_name='BMINUSL_SR_HT_1100_MBL_400_MINUS_HT',
                  hist='flavor_all__ht_signal',
                  ic_numerator=ic_numerator,
                  ic_denominator=ic_denominator,
                  ic_other=ic_other,
                  out_file=out_file,
                  y_max_lin=600,
                  y_max_log=1000000,
                  y_min_log=0.01,
                  do_ratio=do_ratio)

    makeFinalPlot(dir_name='BMINUSL_SR_HT_1100_MBL_400_MINUS_MBL_ASYM',
                  hist='flavor_all__mbl_asym',
                  ic_numerator=ic_numerator,
                  ic_denominator=ic_denominator,
                  ic_other=ic_other,
                  out_file=out_file,
                  y_max_lin=100,
                  y_max_log=8000,
                  do_ratio=do_ratio)

    # # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # dirs = hh.Helper.getListOfDirs(file_list)
    # num_dirs = len(dirs)
    # for d_it, d in enumerate(dirs):
    #     # skip directories with the string "_TRIG" in their name
    #     if '_TRIG' in d:
    #         print 'skipping directory: ', d
    #         continue
    #     if '_minus_' not in d.lower():
    #         print 'skipping directory: ', d
    #         continue
    #
    #     print 'Printing histograms for cut dir: %s (%d of %d)' % (d, d_it, num_dirs)
    #     out_file.cd()
    #     out_file.mkdir(d)
    #     out_file.cd(d)
    #
    #     these_hists = hh.Helper.getListOfHists(file_list[0].GetDirectory(d))
    #
    #     legend_canvas_drawn  = False
    #     raw_entries_canvas_drawn = False
    #     entries_canvas_drawn = False
    #     for it, h in enumerate(these_hists):
    #         if skipHist(d,h):
    #             continue
    #
    #         out_file.cd(d)
    #
    #         hm_num = (None if ic_numerator is None else
    #                   ic_numerator.genHistMerger(d,h))
    #         hm_denom = (None if ic_denominator is None else
    #                     ic_denominator.genHistMerger(d,h))
    #         hm_other = None if ic_other is None else ic_other.genHistMerger(d,h)
    #
    #         # if this is a 1D histogram, draw as stack with ratio
    #         print 'drawing hist!'
    #         hist_painter = hh.Painter.HistPainter( num   = hm_num
    #                                              , denom = hm_denom
    #                                              , other = hm_other
    #                                              )
    #
    #         if do_ratio:
    #             pile_test_stack = hist_painter.pileAndRatio(
    #                     num_type       = hh.Objects.plain_hist,
    #                     denom_type     = hh.Objects.stack_hist,
    #                     canvas_options = hh.Objects.canv_log_y,
    #                     legend         = True)
    #         else:
    #             pile_test_stack = hist_painter.pile(
    #                     num_type       = hh.Objects.plain_hist,
    #                     denom_type     = hh.Objects.stack_hist,
    #                     canvas_options = hh.Objects.canv_log_y,
    #                     legend         = True)
    #
    #         pile_test_stack.Write('%s__log' % h)
    #         pile_test_stack.Close()
    #
    #         if do_ratio:
    #             pile_test_stack = hist_painter.pileAndRatio(
    #                     num_type       = hh.Objects.plain_hist,
    #                     denom_type     = hh.Objects.stack_hist,
    #                     canvas_options = hh.Objects.canv_linear,
    #                     legend         = True)
    #         else:
    #             pile_test_stack = hist_painter.pile(
    #                     num_type       = hh.Objects.plain_hist,
    #                     denom_type     = hh.Objects.stack_hist,
    #                     canvas_options = hh.Objects.canv_linear,
    #                     legend         = True)
    #
    #         pile_test_stack.Write('%s__lin' % h)
    #         pile_test_stack.Close()
    #
    #         # draw legend canvas if not done yet
    #         if not legend_canvas_drawn:
    #             legend_canvas = hist_painter.genLegendCanvas()
    #             legend_canvas.Write('__legend')
    #             legend_canvas.Close()
    #             legend_canvas_drawn = True
    #
    #         if not raw_entries_canvas_drawn:
    #             raw_entries_canvas = hist_painter.genRawEntriesCanvas()
    #             raw_entries_canvas['canv'].Write('__raw_entries')
    #             raw_entries_canvas['canv'].Close()
    #             raw_entries_canvas_drawn = True
    #
    #         if not entries_canvas_drawn:
    #             entries_canvas = hist_painter.genEntriesCanvas()
    #             entries_canvas['canv'].Write('__entries')
    #             entries_canvas['canv'].Close()
    #             entries_canvas_drawn = True

    out_file.Close()

