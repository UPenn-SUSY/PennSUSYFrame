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

    HIST_DIR = "${BASE_WORK_DIR}/EwkAnalysis/May22/"

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # TODO parse these inputs in more reasonable way!
    ec_data = hh.Container.EntryContainer( label = 'Data'
                                          , fill_color = ROOT.kBlack
                                          , input_file_list = [ HIST_DIR+ "Isr.periodA_egamma.hists.root"
                                                                , HIST_DIR + "Isr.periodB_egamma.hists.root"
                                                                , HIST_DIR + "Isr.periodC_egamma.hists.root"
                                                                , HIST_DIR + "Isr.periodD_egamma.hists.root"
                                                                , HIST_DIR + "Isr.periodE_egamma.hists.root"
                                                                           
                                                                , HIST_DIR + "Isr.periodA_muon.hists.root"
                                                                , HIST_DIR + "Isr.periodB_muon.hists.root"
                                                                , HIST_DIR + "Isr.periodC_muon.hists.root"
                                                                , HIST_DIR + "Isr.periodD_muon.hists.root"
                                                                , HIST_DIR + "Isr.periodE_muon.hists.root"

                                                              ]
                                          )
  
    ec_zjets = hh.Container.EntryContainer( label = 'Z+jets'
                                        , fill_color = ROOT.kRed+1
                                        , input_file_list = [ HIST_DIR + "Isr.117650.AlpgenPythia_P2011C_ZeeNp0.hists.root"
                                                            , HIST_DIR + "Isr.117651.AlpgenPythia_P2011C_ZeeNp1.hists.root"
                                                            , HIST_DIR + "Isr.117652.AlpgenPythia_P2011C_ZeeNp2.hists.root"
                                                            , HIST_DIR + "Isr.117653.AlpgenPythia_P2011C_ZeeNp3.hists.root"
                                                            , HIST_DIR + "Isr.117654.AlpgenPythia_P2011C_ZeeNp4.hists.root"
                                                            , HIST_DIR + "Isr.117655.AlpgenPythia_P2011C_ZeeNp5.hists.root"
                                                             
                                                            , HIST_DIR + "Isr.110805.AlpgenPythia_P2011C_ZeeccNp0.hists.root"
                                                            , HIST_DIR + "Isr.110806.AlpgenPythia_P2011C_ZeeccNp1.hists.root"
                                                            , HIST_DIR + "Isr.110807.AlpgenPythia_P2011C_ZeeccNp2.hists.root"
                                                            , HIST_DIR + "Isr.110808.AlpgenPythia_P2011C_ZeeccNp3.hists.root"
                                                             
                                                            , HIST_DIR + "Isr.110817.AlpgenPythia_P2011C_ZeebbNp0.hists.root"
                                                            , HIST_DIR + "Isr.110818.AlpgenPythia_P2011C_ZeebbNp1.hists.root"
                                                            , HIST_DIR + "Isr.110819.AlpgenPythia_P2011C_ZeebbNp2.hists.root"
                                                            , HIST_DIR + "Isr.110820.AlpgenPythia_P2011C_ZeebbNp3.hists.root"
                                                             
                                                            , HIST_DIR + "Isr.117660.AlpgenPythia_P2011C_ZmumuNp0.hists.root"
                                                            , HIST_DIR + "Isr.117661.AlpgenPythia_P2011C_ZmumuNp1.hists.root"
                                                            , HIST_DIR + "Isr.117662.AlpgenPythia_P2011C_ZmumuNp2.hists.root"
                                                            , HIST_DIR + "Isr.117663.AlpgenPythia_P2011C_ZmumuNp3.hists.root"
                                                            , HIST_DIR + "Isr.117664.AlpgenPythia_P2011C_ZmumuNp4.hists.root"
                                                            , HIST_DIR + "Isr.117665.AlpgenPythia_P2011C_ZmumuNp5.hists.root"
                                                             
                                                            , HIST_DIR + "Isr.110809.AlpgenPythia_P2011C_ZmumuccNp0.hists.root"
                                                            , HIST_DIR + "Isr.110810.AlpgenPythia_P2011C_ZmumuccNp1.hists.root"
                                                            , HIST_DIR + "Isr.110811.AlpgenPythia_P2011C_ZmumuccNp2.hists.root"
                                                            , HIST_DIR + "Isr.110812.AlpgenPythia_P2011C_ZmumuccNp3.hists.root"
                                                             
                                                            , HIST_DIR + "Isr.110821.AlpgenPythia_P2011C_ZmumubbNp0.hists.root"
                                                            , HIST_DIR + "Isr.110822.AlpgenPythia_P2011C_ZmumubbNp1.hists.root"
                                                            , HIST_DIR + "Isr.110823.AlpgenPythia_P2011C_ZmumubbNp2.hists.root"
                                                            , HIST_DIR + "Isr.110824.AlpgenPythia_P2011C_ZmumubbNp3.hists.root"
                                                           
                                                            , HIST_DIR + "Isr.117670.AlpgenPythia_P2011C_ZtautauNp0.hists.root"
                                                            , HIST_DIR + "Isr.117671.AlpgenPythia_P2011C_ZtautauNp1.hists.root"
                                                            , HIST_DIR + "Isr.117672.AlpgenPythia_P2011C_ZtautauNp2.hists.root"
                                                            , HIST_DIR + "Isr.117673.AlpgenPythia_P2011C_ZtautauNp3.hists.root"
                                                            , HIST_DIR + "Isr.117674.AlpgenPythia_P2011C_ZtautauNp4.hists.root"
                                                            , HIST_DIR + "Isr.117675.AlpgenPythia_P2011C_ZtautauNp5.hists.root"

##need tautau cc +bb
                                                            ]
                                            )

    ec_dy = hh.Container.EntryContainer( label = 'DY'
                                         , fill_color = ROOT.kOrange+8
                                         , input_file_list = [
            
            ]
                                         )

    ec_diboson = hh.Container.EntryContainer( label = 'Diboson'
                                              , fill_color = ROOT.kBlue
                                              , input_file_list = [ HIST_DIR + "Isr.126892.Sherpa_CT10_llnunu_WW.hists.root"
                                                                   , HIST_DIR + "Isr.126951.PowhegPythia8_AU2CT10_ZZllnunu_tt_mll4.hists.root"
                                                                    ]
                                              )

    ec_ttbar = hh.Container.EntryContainer( label = 'Ttbar'
                                              , fill_color = ROOT.kGreen+2
                                              , input_file_list = [ HIST_DIR + "Isr.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.hists.root"
                                                                    # single top
                                                                    #117360
                                                                    #117361
                                                                    #117362
                                                                    #108343
                                                                    #108344
                                                                    #108345
                                                                    ]
                                              )

    ec_ttbarboson = hh.Container.EntryContainer( label = "Ttbar + Boson"
                                                 , fill_color = ROOT.kBlue-6
                                                 , input_file_list = [HIST_DIR + "Isr.119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW.hists.root"
                                                                    ,HIST_DIR + "Isr.119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj.hists.root"
                                                                    ,HIST_DIR + "Isr.119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ.hists.root"
                                                                    ,HIST_DIR + "Isr.119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj.hists.root"
                                                                    ,HIST_DIR + "Isr.119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW.hists.root"
                                                                      ]
                                                 )

    ec_higgs = hh.Container.EntryContainer( label = 'Higgs'
                                            , fill_color = ROOT.kCyan
                                            , input_file_list = [HIST_DIR + "Isr.161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5.hists.root"
                                                                 , HIST_DIR + "Isr.161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5.hists.root"
                                                                 , HIST_DIR + "Isr.161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep.hists.root"
                                                                 , HIST_DIR + "Isr.161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep.hists.root"
                                                                 #, HIST_DIR + "Isr.161305.hists.root" #ttH
                                                                 , HIST_DIR + "Isr.160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu.hists.root"
                                                                 , HIST_DIR + "Isr.160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu.hists.root"
                                                                 , HIST_DIR + "Isr.160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu.hists.root"
                                                                 , HIST_DIR + "Isr.160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu.hists.root"
                                                                 , HIST_DIR + "Isr.160155.PowhegPythia8_AU2CT10_ggH125_ZZ4lep.hists.root"
                                                                 , HIST_DIR + "Isr.160205.PowhegPythia8_AU2CT10_VBFH125_ZZ4lep.hists.root"
                                                                 , HIST_DIR + "Isr.160255.Pythia8_AU2CTEQ6L1_WH125_ZZ4lep.hists.root"
                                                                 , HIST_DIR + "Isr.160305.Pythia8_AU2CTEQ6L1_ZH125_ZZ4lep.hists.root"
                                                                 ]
                                            )

    ec_triboson = hh.Container.EntryContainer( label = 'Triboson'
                                            , fill_color = ROOT.kViolet
                                            , input_file_list = [ HIST_DIR + "Isr.167006.MadGraphPythia_AUET2BCTEQ6L1_WWWStar_lnulnulnu.hists.root"
                                                                  , HIST_DIR + "Isr.167007.MadGraphPythia_AUET2BCTEQ6L1_ZWWStar_lllnulnu.hists.root"
                                                                  , HIST_DIR + "Isr.167008.MadGraphPythia_AUET2BCTEQ6L1_ZZZStar_nunullll.hists.root"
                                                                  # 147191
                                                                  # 147193
                                                                  # 147194
                                                                  # 147195
                                                                  # 147196
                                                                  ]
                                            )




    ic_numerator = hh.Container.InputContainer( name = 'Data'
                                              , entry_list = [ec_data]
                                              #,lumi_target = 13000
                                                )
    ic_denominator = hh.Container.InputContainer( name = 'Background'
                                                , entry_list = [ec_zjets, ec_dy, ec_diboson, ec_ttbar, ec_higgs, ec_triboson, ec_ttbarboson]
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
