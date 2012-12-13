#!/usr/bin/env python

import ROOT
import HistHandle as hh
import metaroot

# ------------------------------------------------------------------------------
# fixed_cut_values
fixed_met_rel = [0, 5, 10, 15, 20, 30, 40, 50]

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
  # if not dir_name == 'mm_sig_lep': return True
  # if not hist_name == 'met_rel': return True
  return False

# ==============================================================================
def main():
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # root stuff
    ROOT.TH1.SetDefaultSumw2()
    ROOT.gROOT.SetBatch()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    inputs = hh.parse.parseInputs()
    config = inputs['config']
    file_list = inputs['files']
    out_file_name = inputs['outfile']
    optimize = inputs['optimize']

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

    # loop through cut directories
    for d in dirs:
        print 'dir: %s' % d
        do_optimize = (d in optimize)
        if do_optimize:
            print '\tdo optimize'
            optimize_map = hh.Optimize.OptimizeMap(optimize[d])
        else: continue

        # made directory structure
        out_file.cd()
        out_file.mkdir(d)
        cut_dir = out_file.GetDirectory(d)

        # loop through hists to be plotted
        for h in hists:
            if skipHist(d,h): continue

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
                if do_optimize and optimize[d].to_optimize == h:
                    local_optimize = hh.Optimize.Optimize(
                            sig = hm_sig,
                            bkg = hm_bkg,
                            cut_direction = optimize[d].direction,
                            bkg_uncertainty = 0.20)
                            #bkg_uncertainty = 0.30)
                            #bkg_uncertainty = 0.40)

                    optimize_map.addGridPoint(local_optimize, sample_dir_name)

                    optimal_cut = local_optimize.getOptimalCut()
#                     if optimal_cut is not none:
#                         print 'adding cut to map'
#                         map_entries.append( { 'point_name':sample_dir_name
#                                             , 'significance':optimal_cut['sig']
#                                             , 'cut_value':optimal_cut['cut']
#                                             } )
#                     else:
#                         print 'adding just the point to map'
#                         map_entries.append( { 'point_name':sample_dir_name
#                                             , 'significance':-1
#                                             , 'cut_value':-1
#                                             } )

                # Draw to canvas and print to file
                painter = hh.Painter.HistPainter( num = hm_sig
                                                , denom = hm_bkg
                                                , optimal_cut = local_optimize
                                                )
                pile = painter.pile( num_type       = hh.Objects.plain_hist
                                   , denom_type     = hh.Objects.stack_hist
                                   , canvas_options = hh.canv_log_y
                                   , legend         = True
                                   )
                pile.Write(h)
                pile.Close()

                # if cut specified, print details to file
                # if cut_to_scan == h:
                if do_optimize and optimize[d].to_optimize == h:
                    detail_dir_name = '%s_details' % h
                    sample_dir.mkdir(detail_dir_name)
                    sample_dir.cd(detail_dir_name)

                    sig_plot = local_optimize.drawSignificanceCanvas()
                    sig_plot['canvas'].Write('%s_zn' % h)
                    sig_plot['canvas'].Close()

        if do_optimize:
            cut_dir.cd()
            cut_dir.mkdir('maps')
            maps_dir = cut_dir.GetDirectory('maps')
            maps_dir.cd()

            if optimize[d].scan:
                print 'scanning'
                optimize_map.printScan(maps_dir)

            optimize_map.printAllFixedPoints(maps_dir)
            # optimize_map.printFixedPoint(maps_dir, 50)

            # cut_dir.cd('maps/scan')
            # print 'writing maps to file'
            # maps = hh.Painter.draw2DMaps(map_entries)
            # maps['c_sig'].Write()
            # maps['c_cut'].Write()
            # maps['c_sig'].Close()
            # maps['c_cut'].Close()

    out_file.Close()

# ==============================================================================
if __name__ == '__main__':
    main()
