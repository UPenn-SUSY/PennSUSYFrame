#!/usr/bin/env python

import ROOT
import HistHandle as hh

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

    return False

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

    # # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    dirs = hh.Helper.getListOfDirs(file_list)
    num_dirs = len(dirs)
    for d_it, d in enumerate(dirs):
        # skip directories with the string "_TRIG" in their name
        if '_TRIG' in d:
            print 'skipping directory: ', d
            continue

        print 'Printing histograms for cut dir: %s (%d of %d)' % (d, d_it, num_dirs)
        out_file.cd()
        out_file.mkdir(d)
        out_file.cd(d)

        these_hists = hh.Helper.getListOfHists(file_list[0].GetDirectory(d))

        legend_canvas_drawn  = False
        raw_entries_canvas_drawn = False
        entries_canvas_drawn = False
        for it, h in enumerate(these_hists):
            if skipHist(d,h):
                continue

            out_file.cd(d)

            hm_num   = ic_numerator.genHistMerger(d,h)
            hm_denom = ic_denominator.genHistMerger(d,h)
            # hm_other = None
            hm_other = None if ic_other is None else ic_other.genHistMerger(d,h)

            # If this is a 2D histogram, draw as colz plots in separate directory
            if hm_num.hist_type  is hh.HIST_2D:
                print 'Not set up to do merged 2D hists for now ... skipping :-('
                continue

            # if this is a 1D histogram, draw as stack with ratio
            if hm_num.hist_type is hh.HIST_1D:
                hist_painter = hh.Painter.HistPainter( num   = hm_num
                                                     , denom = hm_denom
                                                     , other = hm_other
                                                     )

                if do_ratio:
                    pile_test_stack = hist_painter.pileAndRatio(
                            num_type       = hh.Objects.plain_hist,
                            denom_type     = hh.Objects.stack_hist,
                            canvas_options = hh.Objects.canv_log_y,
                            legend         = True)
                else:
                    pile_test_stack = hist_painter.pile(
                            num_type       = hh.Objects.plain_hist,
                            denom_type     = hh.Objects.stack_hist,
                            canvas_options = hh.Objects.canv_log_y,
                            legend         = True)

                pile_test_stack.Write('%s__log' % h)
                pile_test_stack.Close()

                if do_ratio:
                    pile_test_stack = hist_painter.pileAndRatio(
                            num_type       = hh.Objects.plain_hist,
                            denom_type     = hh.Objects.stack_hist,
                            canvas_options = hh.Objects.canv_linear,
                            legend         = True)
                else:
                    pile_test_stack = hist_painter.pile(
                            num_type       = hh.Objects.plain_hist,
                            denom_type     = hh.Objects.stack_hist,
                            canvas_options = hh.Objects.canv_linear,
                            legend         = True)

                pile_test_stack.Write('%s__lin' % h)
                pile_test_stack.Close()

                # draw legend canvas if not done yet
                if not legend_canvas_drawn:
                    legend_canvas = hist_painter.genLegendCanvas()
                    legend_canvas.Write('__legend')
                    legend_canvas.Close()
                    legend_canvas_drawn = True

                if not raw_entries_canvas_drawn:
                    raw_entries_canvas = hist_painter.genRawEntriesCanvas()
                    raw_entries_canvas['canv'].Write('__raw_entries')
                    raw_entries_canvas['canv'].Close()
                    raw_entries_canvas_drawn = True

                if not entries_canvas_drawn:
                    entries_canvas = hist_painter.genEntriesCanvas()
                    entries_canvas['canv'].Write('__entries')
                    entries_canvas['canv'].Close()
                    entries_canvas_drawn = True

            # # If this is a 2D histogram, draw as colz plots in separate directory
            # if hm_num.hist_type  is hh.HIST_2D:
            #     print 'making directory: %s/%s' % (d,h)
            #     local_dir = out_file.Get(d)
            #     local_dir.mkdir(h)
            #     out_file.cd('%s/%s' % (d,h))

            #     hist_painter = hh.Painter.HistPainter( num   = hm_num
            #                                          , denom = hm_denom
            #                                          , other = hm_other
            #                                          , num_draw_option   = 'COLZ'
            #                                          , denom_draw_option = 'COLZ'
            #                                          , other_draw_option = 'COLZ'
            #                                          )

            #     canv_dict = hist_painter.plotOnSeparateCanvases()

            #     for cd in canv_dict:
            #         canv_dict[cd].Write('h_%s' % cd)
            #         canv_dict[cd].Close()

            #     # num_canv = hh.Painter.draw2DHist(hm_num.hist_sum, hm_num.hist_name)
            #     # num_canv.Write('%s__num' % hm_num.hist_name)
            #     # num_canv.Close()

            #     # denom_canv = hh.Painter.draw2DHist(hm_denom.hist_sum, hm_denom.hist_name)
            #     # denom_canv.Write('%s__denom' % hm_denom.hist_name)
            #     # denom_canv.Close()

    out_file.Close()


# ==============================================================================
def main():
    """
    test main for plot_comparison
    """
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # root stuff
    ROOT.TH1.SetDefaultSumw2()
    ROOT.gROOT.SetBatch()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ec_dummy = hh.Container.EntryContainer( label = 'dummy'
                                          , fill_color = ROOT.kBlack
                                          , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.dummy_hists.root"
                                                              ]
                                          )
    ec_ttbar = hh.Container.EntryContainer( label = 'ttbar'
                                          , fill_color = ROOT.kAzure+8
                                          , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.105200.ttbar.hists.root"
                                                              ]
                                          )
    ec_Zbb = hh.Container.EntryContainer( label = 'Zbb'
                                        , fill_color = ROOT.kRed+1
                                        , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.110817.ZeebbNp0.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110818.ZeebbNp1.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110819.ZeebbNp2.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110820.ZeebbNp3.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110821.ZmumubbNp0.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110822.ZmumubbNp1.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110823.ZmumubbNp2.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110824.ZmumubbNp3.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110825.ZtautaubbNp0.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110826.ZtautaubbNp1.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110827.ZtautaubbNp2.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110828.ZtautaubbNp3.hists.root"
                                                            ]
                                        )
    ic_numerator = hh.Container.InputContainer( name = 'dummy'
                                              , entry_list = [ec_dummy]
                                              , lumi_target = 0.
                                              )
    ic_denominator = hh.Container.InputContainer( name = 'Background'
                                                , entry_list = [ec_ttbar, ec_Zbb]
                                                , lumi_target = 20300
                                                )

    out_file_name = 'compare_plots.test.root'

    plotComparisons( ic_numerator   = ic_numerator
                   , ic_denominator = ic_denominator
                   , ic_other       = None
                   , out_file_name  = out_file_name
                   )

# ==============================================================================
if __name__ == '__main__':
    main()
