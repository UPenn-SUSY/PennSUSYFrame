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
    config        = inputs['config']
    file_list     = inputs['files']
    out_file_name = inputs['outfile']
    optimize      = inputs['optimize']

    print '--------------------------------------------------------------------'
    print '- config'
    print '--------------------------------------------------------------------'
    print config

    print '--------------------------------------------------------------------'
    print '- optimize'
    print '--------------------------------------------------------------------'
    print optimize

    # TODO after debugging, switch back to 'create'
    # out_file = ROOT.TFile(out_file_name, 'CREATE')
    out_file = ROOT.TFile(out_file_name, 'RECREATE')

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bkg_config = config['Background']
    sig_configs = []
    for key in config:
        if 'Signal' in key:
            sig_configs.append(config[key])
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    dirs  = hh.Helper.get_list_of_dirs(file_list)
    hists = hh.Helper.get_list_of_hists(file_list[0].GetDirectory(dirs[0]))

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # TODO make these configurable
    target_lumi = 21
    prod_type = 'modeA'

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # loop through cut directories
    for d in dirs:
        print 'Making optimization plots for dir: %s' % d
    #     do_optimize = (d in optimize)
    #     if do_optimize:
    #         print '\tdo optimize'
    #         optimize_map = hh.Optimize.OptimizeMap(optimize[d])
    #     else: continue

        # made directory structure
        out_file.cd()
        out_file.mkdir(d)
        cut_dir = out_file.GetDirectory(d)

        # dictionary of OptimizeMap objects
        optimize_map = {}

        # loop through hists to be plotted
        for h in hists:
            if skipHist(d,h): continue

            do_optimize = (h in optimize)
            if do_optimize:
                print '\tdo optimize for hist: %s' % h
                optimize_map[h] = hh.Optimize.OptimizeMap(optimize[h])

            # get background HistMerger only once per hist/cut combination
            hm_bkg = bkg_config.genHistMerger(d, h)

            # loop thought signal grid points
            for sig_point in sig_configs:
                # create proper directory
                sample_dir_name = '%s-%d_%d' % ( sig_point.name
                                               , hh.Helper.getCharginoMass(
                                                   sig_point.name)
                                               , hh.Helper.getNeutralinoMass(
                                                   sig_point.name)
                                               )
                sample_dir = cut_dir.GetDirectory(sample_dir_name)
                if sample_dir == None:
                    cut_dir.mkdir(sample_dir_name)
                    sample_dir = cut_dir.GetDirectory(sample_dir_name)
                sample_dir.cd()

                # get signal HistMerger object
                hm_sig = sig_point.genHistMerger(d,h)

                # do optimization if specified
                local_optimize = None
                if do_optimize:
                # if do_optimize and optimize[d].to_optimize == h:
                    local_optimize = hh.Optimize.Optimize(
                            sig = hm_sig,
                            bkg = hm_bkg,
                            cut_direction = optimize[h].direction,
                            bkg_uncertainty = 0.20)
                            #bkg_uncertainty = 0.30)
                            #bkg_uncertainty = 0.40)

                    optimize_map[h].addGridPoint(local_optimize, sample_dir_name)

                    optimal_cut = local_optimize.getOptimalCut()

                # Draw to canvas and print to file
                painter = hh.Painter.HistPainter( num = hm_sig
                                                , denom = hm_bkg
                                                , optimal_cut = local_optimize
                                                )
                pile = painter.pile( num_type       = hh.Objects.plain_hist
                                   , denom_type     = hh.Objects.stack_hist
                                   , canvas_options = hh.canv_log_y
                                   , legend         = True
                                   , int_lumi       = target_lumi
                                   , prod_type      = prod_type
                                   )
                pile.Write(h)
                # pile.Close()

                # if we are to optimize, and this cut is specified, print
                # details to file
                if do_optimize:
                # if do_optimize and optimize[d].to_optimize == h:
                    detail_dir_name = '%s_details' % h
                    sample_dir.mkdir(detail_dir_name)
                    sample_dir.cd(detail_dir_name)

                    sig_plot = local_optimize.drawSignificanceCanvas()
                    hh.Painter.drawLabels( int_lumi = target_lumi
                                         , prod_type = prod_type
                                         )
                    sig_plot['canvas'].Write('%s_zn' % h)
                    sig_plot['canvas'].Close()

                    cut_region = local_optimize.drawCutRegionCanvas(pile)
                    cut_region['canvas'].Write('%s_w_cut_region' % h)
                    cut_region['canvas'].Close()

                    integral_plot = local_optimize.drawIntegralCavnas()
                    integral_plot['canvas'].Write('%s_int' % h)
                    integral_plot['canvas'].Close()

                pile.Close()



    #     # If we are doing optimization, print maps to file
    #     if do_optimize:
        for h in optimize_map:
            cut_dir.cd()
            cut_dir.mkdir('maps_%s' % h)
            maps_dir = cut_dir.GetDirectory('maps_%s' % h)
            maps_dir.cd()

            # do scan of all possible cuts
            if optimize[h].scan:
                print '\tScanning: %s' % optimize[h].to_optimize
                optimize_map[h].printScan( maps_dir
                                         , target_lumi = target_lumi
                                         , prod_type   = prod_type
                                         )

            # check fixed cut values
            optimize_map[h].printAllFixedPoints( maps_dir
                                               , target_lumi = target_lumi
                                               , prod_type   = prod_type
                                               )

    # Clean up out file
    out_file.Close()

# ==============================================================================
if __name__ == '__main__':
    main()
