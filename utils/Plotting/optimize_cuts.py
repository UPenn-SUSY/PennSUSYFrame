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
    dirs = hh.Helper.get_list_of_dirs(file_list)
    # hists = ['mll', 'el_0_pt', 'el_1_pt', 'mu_0_pt', 'mu_1_pt']
    hists = hh.Helper.get_list_of_hists(file_list[0].GetDirectory(dirs[0]))
    for d in dirs:
        out_file.cd()
        out_file.mkdir(d)
        out_file.cd(d)
        for h in hists:
            if skipHist(d,h): continue

            hm_sig = config['Signal'    ].genHistMerger(d, h)
            hm_bkg = config['Background'].genHistMerger(d, h)

            optimize = hh.Optimize.Optimize( sig = hm_sig
                                           , bkg = hm_bkg
                                           #, cut_direction = hh.right
                                           , cut_direction = hh.left
                                           )
            print optimize.getOptimalCut()

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
