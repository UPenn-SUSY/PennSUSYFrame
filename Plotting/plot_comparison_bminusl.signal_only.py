#!/usr/bin/env python

import ROOT
import HistHandle as hh
import plot_comparison as pc

# ==============================================================================
def main():
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # root stuff
    ROOT.TH1.SetDefaultSumw2()
    ROOT.gROOT.SetBatch()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    hist_dir = '${BASE_WORK_DIR}/NextPlotDir.BMinusL'

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # construct EntryContainer objects
    ec_dummy = hh.Container.EntryContainer( label = 'dummy'
                                          , fill_color = ROOT.kBlack
                                          , input_file_list = [ "%s/BMinusL.dummy_hists.root" % hist_dir
                                                              ]
                                          )

    ec_bl_100 = hh.Container.EntryContainer( label = 'B-L stop (100 GeV)'
                                           , line_color = ROOT.kMagenta
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "%s/BMinusL.202632.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_100.hists.root" % hist_dir
                                                               ]
                                           )
    ec_bl_200 = hh.Container.EntryContainer( label = 'B-L stop (200 GeV)'
                                           , line_color = ROOT.kGreen+2
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "%s/BMinusL.202633.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_200.hists.root" % hist_dir
                                                               ]
                                           )
    ec_bl_300 = hh.Container.EntryContainer( label = 'B-L stop (300 GeV)'
                                           , line_color = ROOT.kGreen+2
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "%s/BMinusL.202634.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_300.hists.root" % hist_dir
                                                               ]
                                           )
    ec_bl_400 = hh.Container.EntryContainer( label = 'B-L stop (400 GeV)'
                                           , line_color = ROOT.kGreen+2
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "%s/BMinusL.202635.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_400.hists.root" % hist_dir
                                                               ]
                                           )
    ec_bl_500 = hh.Container.EntryContainer( label = 'B-L stop (500 GeV)'
                                           , line_color = ROOT.kBlue+2
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "%s/BMinusL.202636.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_500.hists.root" % hist_dir
                                                               ]
                                           )
    ec_bl_600 = hh.Container.EntryContainer( label = 'B-L stop (600 GeV)'
                                           , line_color = ROOT.kGreen+2
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "%s/BMinusL.202637.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_600.hists.root" % hist_dir
                                                               ]
                                           )
    ec_bl_700 = hh.Container.EntryContainer( label = 'B-L stop (700 GeV)'
                                           , line_color = ROOT.kRed+1
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "%s/BMinusL.202638.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_700.hists.root" % hist_dir
                                                               ]
                                           )
    ec_bl_800 = hh.Container.EntryContainer( label = 'B-L stop (800 GeV)'
                                           , line_color = ROOT.kMagenta
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "%s/BMinusL.202639.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_800.hists.root" % hist_dir
                                                               ]
                                           )
    ec_bl_900 = hh.Container.EntryContainer( label = 'B-L stop (900 GeV)'
                                           , line_color = ROOT.kTeal+4
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "%s/BMinusL.202640.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_900.hists.root" % hist_dir
                                                               ]
                                           )
    ec_bl_1000 = hh.Container.EntryContainer( label = 'B-L stop (1000 GeV)'
                                           , line_color = ROOT.kCyan+2
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "%s/BMinusL.202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000.hists.root" % hist_dir
                                                               ]
                                           )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # Collect EntryContainer into InputContainers
    ic_numerator = hh.Container.InputContainer( name = 'dummy'
                                              , entry_list = [ec_dummy]
                                              , lumi_target = 0.
                                              )
    ic_denominator = hh.Container.InputContainer( name = 'Background'
                                                , entry_list = [ec_dummy]
                                                , lumi_target = 0
                                                )
    ic_signal = hh.Container.InputContainer( name = 'Signal'
                                           , entry_list = [ ec_bl_500
                                                          , ec_bl_600
                                                          , ec_bl_700
                                                          , ec_bl_800
                                                          , ec_bl_900
                                                          , ec_bl_1000
                                                          ]
                                           , lumi_target = 21000
                                           )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # Actually plot comparisons
    out_file_name = 'compare_plots.b_minus_l.signal.root'
    pc.plotComparisons( ic_numerator   = ic_numerator
                      , ic_denominator = ic_denominator
                      , ic_other       = ic_signal
                      , out_file_name  = out_file_name
                      )

# ==============================================================================
if __name__ == '__main__':
    main()
