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
    # TODO parse these inputs in more reasonable way!
    ec_data = hh.Container.EntryContainer( label = 'Data'
                                          , fill_color = ROOT.kBlack
                                          , input_file_list = [ "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.periodA_egamma.hists.root"
                                                                , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.periodB_egamma.hists.root"
                                                                , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.periodC_egamma.hists.root"
                                                                , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.periodD_egamma.hists.root"
                                                                , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.periodE_egamma.hists.root"
                                                                 
                                                                , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.periodA_muon.hists.root"
                                                                , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.periodB_muon.hists.root"
                                                                , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.periodC_muon.hists.root"
                                                                , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.periodD_muon.hists.root"
                                                                , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.periodE_muon.hists.root"

                                                              ]
                                          )
  
    ec_zjets = hh.Container.EntryContainer( label = 'Z+jets'
                                        , fill_color = ROOT.kRed+1
                                        , input_file_list = [ "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.117650.AlpgenPythia_P2011C_ZeeNp0.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.117651.AlpgenPythia_P2011C_ZeeNp1.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.117652.AlpgenPythia_P2011C_ZeeNp2.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.117653.AlpgenPythia_P2011C_ZeeNp3.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.117654.AlpgenPythia_P2011C_ZeeNp4.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.117655.AlpgenPythia_P2011C_ZeeNp5.hists.root"

                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.110805.AlpgenPythia_P2011C_ZeeccNp0.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.110806.AlpgenPythia_P2011C_ZeeccNp1.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.110807.AlpgenPythia_P2011C_ZeeccNp2.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.110808.AlpgenPythia_P2011C_ZeeccNp3.hists.root"

                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.110817.AlpgenPythia_P2011C_ZeebbNp0.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.110818.AlpgenPythia_P2011C_ZeebbNp1.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.110819.AlpgenPythia_P2011C_ZeebbNp2.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.110820.AlpgenPythia_P2011C_ZeebbNp3.hists.root"

                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.117660.AlpgenPythia_P2011C_ZmumuNp0.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.117661.AlpgenPythia_P2011C_ZmumuNp1.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.117662.AlpgenPythia_P2011C_ZmumuNp2.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.117663.AlpgenPythia_P2011C_ZmumuNp3.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.117664.AlpgenPythia_P2011C_ZmumuNp4.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.117665.AlpgenPythia_P2011C_ZmumuNp5.hists.root"

                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.110809.AlpgenPythia_P2011C_ZmumuccNp0.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.110810.AlpgenPythia_P2011C_ZmumuccNp1.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.110811.AlpgenPythia_P2011C_ZmumuccNp2.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.110812.AlpgenPythia_P2011C_ZmumuccNp3.hists.root"

                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.110821.AlpgenPythia_P2011C_ZmumubbNp0.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.110822.AlpgenPythia_P2011C_ZmumubbNp1.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.110823.AlpgenPythia_P2011C_ZmumubbNp2.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.110824.AlpgenPythia_P2011C_ZmumubbNp3.hists.root"
##
##                                                            , "${BASE_WORK_DIR/EwkAnalysis/May22/Isr.117670.AlpgenPythia_P2011C_ZtautauNp0.hists.root"
##                                                            , "${BASE_WORK_DIR/EwkAnalysis/May22/Isr.117671.AlpgenPythia_P2011C_ZtautauNp1.hists.root"
##                                                            , "${BASE_WORK_DIR/EwkAnalysis/May22/Isr.117672.AlpgenPythia_P2011C_ZtautauNp2.hists.root"
##                                                            , "${BASE_WORK_DIR/EwkAnalysis/May22/Isr.117673.AlpgenPythia_P2011C_ZtautauNp3.hists.root"
##                                                            , "${BASE_WORK_DIR/EwkAnalysis/May22/Isr.117674.AlpgenPythia_P2011C_ZtautauNp4.hists.root"
##                                                            , "${BASE_WORK_DIR/EwkAnalysis/May22/Isr.117675.AlpgenPythia_P2011C_ZtautauNp5.hists.root"
                                                            ]
                                            )

    ec_diboson = hh.Container.EntryContainer( label = 'Diboson'
                                              , fill_color = ROOT.kBlue
                                              , input_file_list = [ "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.126892.Sherpa_CT10_llnunu_WW.hists.root"
                                                                    ,"${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.126951.PowhegPythia8_AU2CT10_ZZllnunu_tt_mll4.hists.root"
                                                                    ]
                                              )

    ec_ttbar = hh.Container.EntryContainer( label = 'Ttbar'
                                              , fill_color = ROOT.kGreen+2
                                              , input_file_list = [ "${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.117050.PowhegPythia_P2011C_ttbar.hists.root"
                                                                    ,"${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW.hists.root"
                                                                    ,"${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj.hists.root"
                                                                    ,"${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ.hists.root"
                                                                    ,"${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj.hists.root"
                                                                    ,"${BASE_WORK_DIR}/EwkAnalysis/May22/Isr.119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW.hists.root"
                                                                    ]
                                              )


    ic_numerator = hh.Container.InputContainer( name = 'Data'
                                              , entry_list = [ec_data]
                                              #,lumi_target = 13000
                                                )
    ic_denominator = hh.Container.InputContainer( name = 'Background'
                                                , entry_list = [ec_zjets, ec_diboson, ec_ttbar]
                                                , lumi_target = 13000
                                                )

    out_file_name = 'compare_plots.ewk.root'

    pc.plotComparisons( ic_numerator   = ic_numerator
                      , ic_denominator = ic_denominator
                      , ic_other       = None
                      , out_file_name  = out_file_name
                      )

# ==============================================================================
if __name__ == '__main__':
    main()
