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
    # construct EntryContainer objects
    ec_dummy = hh.Container.EntryContainer( label = 'dummy'
                                          , fill_color = ROOT.kBlack
                                          , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.dummy_hists.root"
                                                              ]
                                          )
    # ec_ttbar = hh.Container.EntryContainer( label = 'ttbar'
    #                                       , fill_color = ROOT.kAzure+8
    #                                       , input_file_list = [ "${BASE_WORK_DIR{/BMinusL.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.hists.root"
    #                                                           ]
    #                                       )
    ec_ttbar = hh.Container.EntryContainer( label = 'ttbar'
                                          # , fill_color = ROOT.kAzure+8
                                          , fill_color = ROOT.kGreen+2
                                          , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.117050.PowhegPythia_P2011C_ttbar.hists.root"
                                                              ]
                                          )

    # ec_Zbb = hh.Container.EntryContainer( label = 'Zbb'
    #                                     , fill_color = ROOT.kRed+1
    #                                     , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.110817.AlpgenPythia_P2011C_ZeebbNp0.hists.root"
    #                                     , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.110817.AlpgenPythia_P2011C_ZeebbNp0.hists.root"
    #                                                         , "${BASE_WORK_DIR}/BMinusL.110818.AlpgenPythia_P2011C_ZeebbNp1.hists.root"
    #                                                         , "${BASE_WORK_DIR}/BMinusL.110819.AlpgenPythia_P2011C_ZeebbNp2.hists.root"
    #                                                         , "${BASE_WORK_DIR}/BMinusL.110820.AlpgenPythia_P2011C_ZeebbNp3.hists.root"
    #                                                         , "${BASE_WORK_DIR}/BMinusL.110821.AlpgenPythia_P2011C_ZmumubbNp0.hists.root"
    #                                                         , "${BASE_WORK_DIR}/BMinusL.110822.AlpgenPythia_P2011C_ZmumubbNp1.hists.root"
    #                                                         , "${BASE_WORK_DIR}/BMinusL.110823.AlpgenPythia_P2011C_ZmumubbNp2.hists.root"
    #                                                         , "${BASE_WORK_DIR}/BMinusL.110824.AlpgenPythia_P2011C_ZmumubbNp3.hists.root"
    #                                                         , "${BASE_WORK_DIR}/BMinusL.110825.AlpgenPythia_P2011C_ZtautaubbNp0.hists.root"
    #                                                         , "${BASE_WORK_DIR}/BMinusL.110826.AlpgenPythia_P2011C_ZtautaubbNp1.hists.root"
    #                                                         , "${BASE_WORK_DIR}/BMinusL.110827.AlpgenPythia_P2011C_ZtautaubbNp2.hists.root"
    #                                                         , "${BASE_WORK_DIR}/BMinusL.110828.AlpgenPythia_P2011C_ZtautaubbNp3.hists.root"
    #                                                         ]
    #                                     )
    ec_Zbb = hh.Container.EntryContainer( label = 'Zbb'
                                        , fill_color = ROOT.kRed+1
                                        , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.200332.AlpgenPythia_Auto_P2011C_ZeebbNp0.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200333.AlpgenPythia_Auto_P2011C_ZeebbNp1.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200334.AlpgenPythia_Auto_P2011C_ZeebbNp2.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200335.AlpgenPythia_Auto_P2011C_ZeebbNp3incl.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200341.AlpgenPythia_Auto_P2011C_ZmumubbNp1.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200342.AlpgenPythia_Auto_P2011C_ZmumubbNp2.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200343.AlpgenPythia_Auto_P2011C_ZmumubbNp3incl.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200348.AlpgenPythia_Auto_P2011C_ZtautaubbNp0.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200349.AlpgenPythia_Auto_P2011C_ZtautaubbNp1.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200350.AlpgenPythia_Auto_P2011C_ZtautaubbNp2.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200351.AlpgenPythia_Auto_P2011C_ZtautaubbNp3incl.hists.root"
                                                            ]
                                        )
    ec_single_top = hh.Container.EntryContainer( label = 'Single top'
                                               , fill_color = ROOT.kGreen-1
                                               , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl.hists.root"
                                                                   ]
                                               )

    ec_bl_100 = hh.Container.EntryContainer( label = 'B-L stop (100 GeV)'
                                           , line_color = ROOT.kMagenta
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.202632.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_100.hists.root"
                                                               ]
                                           )
    ec_bl_200 = hh.Container.EntryContainer( label = 'B-L stop (200 GeV)'
                                           , line_color = ROOT.kGreen+2
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.202633.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_200.hists.root"
                                                               ]
                                           )
    ec_bl_300 = hh.Container.EntryContainer( label = 'B-L stop (300 GeV)'
                                           , line_color = ROOT.kGreen+2
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.202634.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_300.hists.root"
                                                               ]
                                           )
    ec_bl_400 = hh.Container.EntryContainer( label = 'B-L stop (400 GeV)'
                                           , line_color = ROOT.kGreen+2
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.202635.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_400.hists.root"
                                                               ]
                                           )
    ec_bl_500 = hh.Container.EntryContainer( label = 'B-L stop (500 GeV)'
                                           , line_color = ROOT.kBlue+2
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.202636.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_500.hists.root"
                                                               ]
                                           )
    ec_bl_600 = hh.Container.EntryContainer( label = 'B-L stop (600 GeV)'
                                           , line_color = ROOT.kGreen+2
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.202637.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_600.hists.root"
                                                               ]
                                           )
    ec_bl_700 = hh.Container.EntryContainer( label = 'B-L stop (700 GeV)'
                                           , line_color = ROOT.kGreen+2
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.202638.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_700.hists.root"
                                                               ]
                                           )
    ec_bl_800 = hh.Container.EntryContainer( label = 'B-L stop (800 GeV)'
                                           , line_color = ROOT.kMagenta
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.202639.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_800.hists.root"
                                                               ]
                                           )
    ec_bl_900 = hh.Container.EntryContainer( label = 'B-L stop (900 GeV)'
                                           , line_color = ROOT.kGreen+2
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.202640.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_900.hists.root"
                                                               ]
                                           )
    ec_bl_1000 = hh.Container.EntryContainer( label = 'B-L stop (1000 GeV)'
                                           , line_color = ROOT.kCyan+2
                                           , line_width = 4
                                           # , line_style = 4
                                           , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000.hists.root"
                                                               ]
                                           )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # Collect EntryContainer into InputContainers
    ic_numerator = hh.Container.InputContainer( name = 'dummy'
                                              , entry_list = [ec_dummy]
                                              , lumi_target = 0.
                                              )
    ic_denominator = hh.Container.InputContainer( name = 'Background'
                                                , entry_list = [ec_ttbar, ec_Zbb, ec_single_top]
                                                , lumi_target = 21000
                                                )
    ic_signal = hh.Container.InputContainer( name = 'Signal'
                                           , entry_list = [ec_bl_500, ec_bl_800, ec_bl_1000]
                                           , lumi_target = 21000
                                           )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # Actually plot comparisons
    out_file_name = 'compare_plots.b_minus_l.root'
    pc.plotComparisons( ic_numerator   = ic_numerator
                      , ic_denominator = ic_denominator
                      , ic_other       = ic_signal
                      , out_file_name  = out_file_name
                      )

# ==============================================================================
if __name__ == '__main__':
    main()
