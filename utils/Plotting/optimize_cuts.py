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
    dirs = hh.Helper.get_list_of_dirs(file_list)
    hists = hh.Helper.get_list_of_hists(file_list[0].GetDirectory(dirs[0]))
    
    # loop through cut directories
    for d in dirs:
        out_file.cd()
        out_file.mkdir(d)
        cut_dir = out_file.GetDirectory(d)

        # loop through hists to be plotted
        for h in hists:
            if skipHist(d,h): continue

            hm_bkg = bkg_config.genHistMerger(d, h)

            # loop thought signal grid points
            for sig_point in sig_configs:
                # create proper directory
                sample_dir_name = '%s' % sig_point.name
                sample_dir = cut_dir.GetDirectory(sample_dir_name)
                if sample_dir == None:
                    cut_dir.mkdir(sample_dir_name)
                    sample_dir = cut_dir.GetDirectory(sample_dir_name)
                sample_dir.cd()

                # get signal HistMerger object
                hm_sig = sig_point.genHistMerger(d,h)

                # do optimization
                optimize = hh.Optimize.Optimize( sig = hm_sig
                                               , bkg = hm_bkg
                                               #, cut_direction = hh.right
                                               , cut_direction = hh.left
                                               )
                # print optimize.getOptimalCut()

                painter = hh.Painter.HistPainter( num = hm_sig
                                                , denom = hm_bkg
                                                , optimal_cut = optimize
                                                )
                print 'Log'
                pile = painter.pile( num_type       = hh.Objects.plain_hist
                                , denom_type     = hh.Objects.stack_hist
                                , canvas_options = hh.canv_log_y
                                , legend         = True
                                )
                pile.Write(h)
                pile.Close()

    out_file.Close()

# ==============================================================================
if __name__ == '__main__':
    main()
