#!/usr/bin/env python

import sys
import os
sys.path.append('%s/Plotting/' % os.environ['BASE_WORK_DIR'])

import ROOT
import HistHandle as hh
import plot_comparison as pc

# ------------------------------------------------------------------------------
def extractTemplate(input_container, hist_name, cut_level):
    # get hist merger from input container
    hist_merger = input_container.genHistMerger(cut_level, '%s__%s' % (hist_name, cut_level))

    # get template from hist merger
    template = hist_merger.hist_sum.Clone('template__%s__%s' % (hist_name, cut_level))
    template.Scale(1/(template.Integral()))

    # boring style stuff
    template.SetFillStyle(0)
    template.SetLineStyle(7)
    template.SetLineWidth(3)

    # return the fancy template
    return template

# ==============================================================================
def main():
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
                                          , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.117050.PowhegPythia_P2011C_ttbar.hists.0_of_15.root"
                                                              , "${BASE_WORK_DIR}/BMinusL.117050.PowhegPythia_P2011C_ttbar.hists.1_of_15.root"
                                                              , "${BASE_WORK_DIR}/BMinusL.117050.PowhegPythia_P2011C_ttbar.hists.2_of_15.root"
                                                              , "${BASE_WORK_DIR}/BMinusL.117050.PowhegPythia_P2011C_ttbar.hists.3_of_15.root"
                                                              , "${BASE_WORK_DIR}/BMinusL.117050.PowhegPythia_P2011C_ttbar.hists.4_of_15.root"
                                                              , "${BASE_WORK_DIR}/BMinusL.117050.PowhegPythia_P2011C_ttbar.hists.5_of_15.root"
                                                              , "${BASE_WORK_DIR}/BMinusL.117050.PowhegPythia_P2011C_ttbar.hists.6_of_15.root"
                                                              , "${BASE_WORK_DIR}/BMinusL.117050.PowhegPythia_P2011C_ttbar.hists.7_of_15.root"
                                                              # , "${BASE_WORK_DIR}/BMinusL.117050.PowhegPythia_P2011C_ttbar.hists.8_of_15.root"
                                                              # , "${BASE_WORK_DIR}/BMinusL.117050.PowhegPythia_P2011C_ttbar.hists.9_of_15.root"
                                                              # , "${BASE_WORK_DIR}/BMinusL.117050.PowhegPythia_P2011C_ttbar.hists.10_of_15.root"
                                                              # , "${BASE_WORK_DIR}/BMinusL.117050.PowhegPythia_P2011C_ttbar.hists.11_of_15.root"
                                                              # , "${BASE_WORK_DIR}/BMinusL.117050.PowhegPythia_P2011C_ttbar.hists.12_of_15.root"
                                                              # , "${BASE_WORK_DIR}/BMinusL.117050.PowhegPythia_P2011C_ttbar.hists.13_of_15.root"
                                                              # , "${BASE_WORK_DIR}/BMinusL.117050.PowhegPythia_P2011C_ttbar.hists.14_of_15.root"
                                                              ]
                                          )
    ec_Zbb = hh.Container.EntryContainer( label = 'Zbb'
                                        , fill_color = ROOT.kRed+1
                                        , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.200332.AlpgenPythia_Auto_P2011C_ZeebbNp0.hists.0_of_10.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200332.AlpgenPythia_Auto_P2011C_ZeebbNp0.hists.1_of_10.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200332.AlpgenPythia_Auto_P2011C_ZeebbNp0.hists.2_of_10.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200332.AlpgenPythia_Auto_P2011C_ZeebbNp0.hists.3_of_10.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200332.AlpgenPythia_Auto_P2011C_ZeebbNp0.hists.4_of_10.root"
                                                            # , "${BASE_WORK_DIR}/BMinusL.200332.AlpgenPythia_Auto_P2011C_ZeebbNp0.hists.5_of_10.root"
                                                            # , "${BASE_WORK_DIR}/BMinusL.200332.AlpgenPythia_Auto_P2011C_ZeebbNp0.hists.6_of_10.root"
                                                            # , "${BASE_WORK_DIR}/BMinusL.200332.AlpgenPythia_Auto_P2011C_ZeebbNp0.hists.7_of_10.root"
                                                            # , "${BASE_WORK_DIR}/BMinusL.200332.AlpgenPythia_Auto_P2011C_ZeebbNp0.hists.8_of_10.root"
                                                            # , "${BASE_WORK_DIR}/BMinusL.200332.AlpgenPythia_Auto_P2011C_ZeebbNp0.hists.9_of_10.root"

                                                            , "${BASE_WORK_DIR}/BMinusL.200333.AlpgenPythia_Auto_P2011C_ZeebbNp1.hists.0_of_5.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200333.AlpgenPythia_Auto_P2011C_ZeebbNp1.hists.1_of_5.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200333.AlpgenPythia_Auto_P2011C_ZeebbNp1.hists.2_of_5.root"
                                                            # , "${BASE_WORK_DIR}/BMinusL.200333.AlpgenPythia_Auto_P2011C_ZeebbNp1.hists.3_of_5.root"
                                                            # , "${BASE_WORK_DIR}/BMinusL.200333.AlpgenPythia_Auto_P2011C_ZeebbNp1.hists.4_of_5.root"

                                                            , "${BASE_WORK_DIR}/BMinusL.200334.AlpgenPythia_Auto_P2011C_ZeebbNp2.hists.0_of_3.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200334.AlpgenPythia_Auto_P2011C_ZeebbNp2.hists.1_of_3.root"
                                                            # , "${BASE_WORK_DIR}/BMinusL.200334.AlpgenPythia_Auto_P2011C_ZeebbNp2.hists.2_of_3.root"

                                                            , "${BASE_WORK_DIR}/BMinusL.200335.AlpgenPythia_Auto_P2011C_ZeebbNp3incl.hists.root"

                                                            , "${BASE_WORK_DIR}/BMinusL.200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0.hists.0_of_10.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0.hists.1_of_10.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0.hists.2_of_10.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0.hists.3_of_10.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0.hists.4_of_10.root"
                                                            # , "${BASE_WORK_DIR}/BMinusL.200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0.hists.5_of_10.root"
                                                            # , "${BASE_WORK_DIR}/BMinusL.200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0.hists.6_of_10.root"
                                                            # , "${BASE_WORK_DIR}/BMinusL.200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0.hists.7_of_10.root"
                                                            # , "${BASE_WORK_DIR}/BMinusL.200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0.hists.8_of_10.root"
                                                            # , "${BASE_WORK_DIR}/BMinusL.200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0.hists.9_of_10.root"

                                                            , "${BASE_WORK_DIR}/BMinusL.200341.AlpgenPythia_Auto_P2011C_ZmumubbNp1.hists.0_of_5.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200341.AlpgenPythia_Auto_P2011C_ZmumubbNp1.hists.1_of_5.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200341.AlpgenPythia_Auto_P2011C_ZmumubbNp1.hists.2_of_5.root"
                                                            # , "${BASE_WORK_DIR}/BMinusL.200341.AlpgenPythia_Auto_P2011C_ZmumubbNp1.hists.3_of_5.root"
                                                            # , "${BASE_WORK_DIR}/BMinusL.200341.AlpgenPythia_Auto_P2011C_ZmumubbNp1.hists.4_of_5.root"

                                                            , "${BASE_WORK_DIR}/BMinusL.200342.AlpgenPythia_Auto_P2011C_ZmumubbNp2.hists.0_of_3.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200342.AlpgenPythia_Auto_P2011C_ZmumubbNp2.hists.1_of_3.root"
                                                            # , "${BASE_WORK_DIR}/BMinusL.200342.AlpgenPythia_Auto_P2011C_ZmumubbNp2.hists.2_of_3.root"

                                                            , "${BASE_WORK_DIR}/BMinusL.200343.AlpgenPythia_Auto_P2011C_ZmumubbNp3incl.hists.root"

                                                            , "${BASE_WORK_DIR}/BMinusL.200348.AlpgenPythia_Auto_P2011C_ZtautaubbNp0.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200349.AlpgenPythia_Auto_P2011C_ZtautaubbNp1.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200350.AlpgenPythia_Auto_P2011C_ZtautaubbNp2.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.200351.AlpgenPythia_Auto_P2011C_ZtautaubbNp3incl.hists.root"
                                                            ]
                                        )
    ec_single_top = hh.Container.EntryContainer( label = 'Single top'
                                               , fill_color = ROOT.kGreen+2
                                               , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl.hists.0_of_10.root"
                                                                   , "${BASE_WORK_DIR}/BMinusL.108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl.hists.1_of_10.root"
                                                                   , "${BASE_WORK_DIR}/BMinusL.108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl.hists.2_of_10.root"
                                                                   , "${BASE_WORK_DIR}/BMinusL.108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl.hists.3_of_10.root"
                                                                   , "${BASE_WORK_DIR}/BMinusL.108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl.hists.4_of_10.root"
                                                                   # , "${BASE_WORK_DIR}/BMinusL.108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl.hists.5_of_10.root"
                                                                   # , "${BASE_WORK_DIR}/BMinusL.108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl.hists.6_of_10.root"
                                                                   # , "${BASE_WORK_DIR}/BMinusL.108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl.hists.7_of_10.root"
                                                                   # , "${BASE_WORK_DIR}/BMinusL.108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl.hists.8_of_10.root"
                                                                   # , "${BASE_WORK_DIR}/BMinusL.108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl.hists.9_of_10.root"
                                                                   ]
                                               )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # create HistHandle object for backgrounds
    ic_background = hh.Container.InputContainer( name = 'Background'
                                               , entry_list = [ec_ttbar, ec_Zbb, ec_single_top]
                                               , lumi_target = 1
                                               )

    # define cut level and get the hist merger for this
    cut_level = 'BMINUSL_MET'
    template__flavor_all__mbl__all = extractTemplate(ic_background, 'flavor_all__mbl_all', cut_level)

    c1 = ROOT.TCanvas()
    template__flavor_all__mbl__all.Draw('hist')
    c1.Print('merged_hist_template.pdf')

    f = ROOT.TFile('templates__0_of_2.root', 'RECREATE')
    template__flavor_all__mbl__all.Write()
    f.Close()

# ==============================================================================
if __name__ == '__main__':
    main()
