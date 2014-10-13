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

    #HIST_DIR = "${BASE_WORK_DIR}/hist"

    HIST_DIR = "/afs/cern.ch/user/e/ehines/workdir/PennSUSYFrame/hists/9Oct/"

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # TODO parse these inputs in more reasonable way!


    ec_diboson = hh.Container.EntryContainer( label = 'Diboson'
                                              , fill_color = ROOT.kBlue
                                              , input_file_list = [  HIST_DIR + "allWZ.root"
                                                                   , HIST_DIR + "restMC.root"

            ##HIST_DIR + "Ewk.129477.PowhegPythia8_AU2CT10_WZ_Wm11Z11_mll0p250d0_2LeptonFilter5.hists.root"
                                                                     ##, HIST_DIR + "Ewk.129478.PowhegPythia8_AU2CT10_WZ_Wm11Z13_mll0p4614d0_2LeptonFilter5.hists.root"
                                                                     ##, HIST_DIR + "Ewk.129479.PowhegPythia8_AU2CT10_WZ_Wm11Z15_mll3p804d0_2LeptonFilter5.hists.root"
                                                                     ##, HIST_DIR + "Ewk.129480.PowhegPythia8_AU2CT10_WZ_Wm13Z11_mll0p250d0_2LeptonFilter5.hists.root"
                                                                     ##, HIST_DIR + "Ewk.129481.PowhegPythia8_AU2CT10_WZ_Wm13Z13_mll0p4614d0_2LeptonFilter5.hists.root"
                                                                     ##, HIST_DIR + "Ewk.129482.PowhegPythia8_AU2CT10_WZ_Wm13Z15_mll3p804d0_2LeptonFilter5.hists.root"
                                                                     ##, HIST_DIR + "Ewk.129483.PowhegPythia8_AU2CT10_WZ_Wm15Z11_mll0p250d0_2LeptonFilter5.hists.root"
                                                                     ##, HIST_DIR + "Ewk.129484.PowhegPythia8_AU2CT10_WZ_Wm15Z13_mll0p4614d0_2LeptonFilter5.hists.root"
                                                                     ##, HIST_DIR + "Ewk.129485.PowhegPythia8_AU2CT10_WZ_Wm15Z15_mll3p804d0_2LeptonFilter5.hists.root"
                                                                     ##, HIST_DIR + "Ewk.129486.PowhegPythia8_AU2CT10_WZ_W11Z11_mll0p250d0_2LeptonFilter5.hists.root"
                                                                     ##, HIST_DIR + "Ewk.129487.PowhegPythia8_AU2CT10_WZ_W11Z13_mll0p4614d0_2LeptonFilter5.hists.root"
                                                                     ##, HIST_DIR + "Ewk.129488.PowhegPythia8_AU2CT10_WZ_W11Z15_mll3p804d0_2LeptonFilter5.hists.root"
                                                                     ##, HIST_DIR + "Ewk.129489.PowhegPythia8_AU2CT10_WZ_W13Z11_mll0p250d0_2LeptonFilter5.hists.root"
                                                                     ##, HIST_DIR + "Ewk.129490.PowhegPythia8_AU2CT10_WZ_W13Z13_mll0p4614d0_2LeptonFilter5.hists.root"
                                                                     ##, HIST_DIR + "Ewk.129491.PowhegPythia8_AU2CT10_WZ_W13Z15_mll3p804d0_2LeptonFilter5.hists.root"
                                                                     ##, HIST_DIR + "Ewk.129492.PowhegPythia8_AU2CT10_WZ_W15Z11_mll0p250d0_2LeptonFilter5.hists.root"
                                                                     ##, HIST_DIR + "Ewk.129493.PowhegPythia8_AU2CT10_WZ_W15Z13_mll0p4614d0_2LeptonFilter5.hists.root"
                                                                     ##, HIST_DIR + "Ewk.129494.PowhegPythia8_AU2CT10_WZ_W15Z15_mll3p804d0_2LeptonFilter5.hists.root"
                                                                     ##, HIST_DIR + "Ewk.147194.Sherpa_CT10_lllnjj_WZjj_EW6.hists.root"
                                                                     ##, HIST_DIR + "Ewk.147195.Sherpa_CT10_llnnjj_ZZjj_EW6.hists.root"
                                                                     ##, HIST_DIR + "Ewk.147196.Sherpa_CT10_lllljj_ZZjj_EW6.hists.root"
                                                                    ]
                                             , lumi_modeled = 1 
                                             , lumi_target = 20281.4
                                              )


    ec_data = hh.Container.EntryContainer( label = 'Data'
                                          , fill_color = ROOT.kBlack
                                          , input_file_list = [ HIST_DIR+ "Ewk.periodA_egamma.hists.root"
                                                                , HIST_DIR + "Ewk.periodB_egamma.hists.root"
                                                                , HIST_DIR + "Ewk.periodC_egamma.hists.root"
                                                                , HIST_DIR + "Ewk.periodD_egamma.hists.root"
                                                                , HIST_DIR + "Ewk.periodE_egamma.hists.root"
                                                                , HIST_DIR + "Ewk.periodG_egamma.hists.root"
                                                                , HIST_DIR + "Ewk.periodH_egamma.hists.root"
                                                                , HIST_DIR + "Ewk.periodI_egamma.hists.root"
                                                                , HIST_DIR + "Ewk.periodJ_egamma.hists.root"
                                                                , HIST_DIR + "Ewk.periodL_egamma.hists.root"
                                                                           
                                                                , HIST_DIR + "Ewk.periodA_muon.hists.root"
                                                                , HIST_DIR + "Ewk.periodB_muon.hists.root"
                                                                , HIST_DIR + "Ewk.periodC_muon.hists.root"
                                                                , HIST_DIR + "Ewk.periodD_muon.hists.root"
                                                                , HIST_DIR + "Ewk.periodE_muon.hists.root"
                                                                , HIST_DIR + "Ewk.periodG_muon.hists.root"
                                                                , HIST_DIR + "Ewk.periodH_muon.hists.root"
                                                                , HIST_DIR + "Ewk.periodI_muon.hists.root"
                                                                , HIST_DIR + "Ewk.periodJ_muon.hists.root"
                                                                , HIST_DIR + "Ewk.periodL_muon.hists.root"

                                                              ]
                                          )
  
    ec_zjets = hh.Container.EntryContainer( label = 'Z+jets'
                                        , fill_color = ROOT.kRed+1
                                        , input_file_list = [ ##HIST_DIR + "Ewk.117650.AlpgenPythia_P2011C_ZeeNp0.hists.root"
                                                            ##, HIST_DIR + "Ewk.117651.AlpgenPythia_P2011C_ZeeNp1.hists.root"
                                                            ##, HIST_DIR + "Ewk.117652.AlpgenPythia_P2011C_ZeeNp2.hists.root"
                                                            ##, HIST_DIR + "Ewk.117653.AlpgenPythia_P2011C_ZeeNp3.hists.root"
                                                            ##, HIST_DIR + "Ewk.117654.AlpgenPythia_P2011C_ZeeNp4.hists.root"
                                                            ##, HIST_DIR + "Ewk.117655.AlpgenPythia_P2011C_ZeeNp5.hists.root"
                                                            ## 
                                                            ##, HIST_DIR + "Ewk.110805.AlpgenPythia_P2011C_ZeeccNp0.hists.root"
                                                            ##, HIST_DIR + "Ewk.110806.AlpgenPythia_P2011C_ZeeccNp1.hists.root"
                                                            ##, HIST_DIR + "Ewk.110807.AlpgenPythia_P2011C_ZeeccNp2.hists.root"
                                                            ##, HIST_DIR + "Ewk.110808.AlpgenPythia_P2011C_ZeeccNp3.hists.root"
                                                            ## 
                                                            ##, HIST_DIR + "Ewk.110817.AlpgenPythia_P2011C_ZeebbNp0.hists.root"
                                                            ##, HIST_DIR + "Ewk.110818.AlpgenPythia_P2011C_ZeebbNp1.hists.root"
                                                            ##, HIST_DIR + "Ewk.110819.AlpgenPythia_P2011C_ZeebbNp2.hists.root"
                                                            ##, HIST_DIR + "Ewk.110820.AlpgenPythia_P2011C_ZeebbNp3.hists.root"
                                                            ## 
                                                            ##, HIST_DIR + "Ewk.117660.AlpgenPythia_P2011C_ZmumuNp0.hists.root"
                                                            ##, HIST_DIR + "Ewk.117661.AlpgenPythia_P2011C_ZmumuNp1.hists.root"
                                                            ##, HIST_DIR + "Ewk.117662.AlpgenPythia_P2011C_ZmumuNp2.hists.root"
                                                            ##, HIST_DIR + "Ewk.117663.AlpgenPythia_P2011C_ZmumuNp3.hists.root"
                                                            ##, HIST_DIR + "Ewk.117664.AlpgenPythia_P2011C_ZmumuNp4.hists.root"
                                                            ##, HIST_DIR + "Ewk.117665.AlpgenPythia_P2011C_ZmumuNp5.hists.root"
                                                            ## 
                                                            ##, HIST_DIR + "Ewk.110809.AlpgenPythia_P2011C_ZmumuccNp0.hists.root"
                                                            ##, HIST_DIR + "Ewk.110810.AlpgenPythia_P2011C_ZmumuccNp1.hists.root"
                                                            ##, HIST_DIR + "Ewk.110811.AlpgenPythia_P2011C_ZmumuccNp2.hists.root"
                                                            ##, HIST_DIR + "Ewk.110812.AlpgenPythia_P2011C_ZmumuccNp3.hists.root"
                                                            ## 
                                                            ##, HIST_DIR + "Ewk.110821.AlpgenPythia_P2011C_ZmumubbNp0.hists.root"
                                                            ##, HIST_DIR + "Ewk.110822.AlpgenPythia_P2011C_ZmumubbNp1.hists.root"
                                                            ##, HIST_DIR + "Ewk.110823.AlpgenPythia_P2011C_ZmumubbNp2.hists.root"
                                                            ##, HIST_DIR + "Ewk.110824.AlpgenPythia_P2011C_ZmumubbNp3.hists.root"
                                                            ##
                                                            ##, HIST_DIR + "Ewk.117670.AlpgenPythia_P2011C_ZtautauNp0.hists.root"
                                                            ##, HIST_DIR + "Ewk.117671.AlpgenPythia_P2011C_ZtautauNp1.hists.root"
                                                            ##, HIST_DIR + "Ewk.117672.AlpgenPythia_P2011C_ZtautauNp2.hists.root"
                                                            ##, HIST_DIR + "Ewk.117673.AlpgenPythia_P2011C_ZtautauNp3.hists.root"
                                                            ##, HIST_DIR + "Ewk.117674.AlpgenPythia_P2011C_ZtautauNp4.hists.root"
                                                            ##, HIST_DIR + "Ewk.117675.AlpgenPythia_P2011C_ZtautauNp5.hists.root"

##need tautau cc +bb
                                                            ]
                                            )

    ec_dy = hh.Container.EntryContainer( label = 'DY'
                                         , fill_color = ROOT.kOrange+8
                                         , input_file_list = [
            
            ]
                                         )

    ec_ttbar = hh.Container.EntryContainer( label = 'Ttbar'
                                              , fill_color = ROOT.kGreen+2
                                              , input_file_list = [ #HIST_DIR + "Ewk.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.hists.root"
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
                                                 , input_file_list = [#HIST_DIR + "Ewk.119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW.hists.root"
                                                                    #,HIST_DIR + "Ewk.119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj.hists.root"
                                                                    #,HIST_DIR + "Ewk.119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ.hists.root"
                                                                    #,HIST_DIR + "Ewk.119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj.hists.root"
                                                                    #,HIST_DIR + "Ewk.119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW.hists.root"
                                                                      ]
                                                 )

    ec_higgs = hh.Container.EntryContainer( label = 'Higgs'
                                            , fill_color = ROOT.kCyan
                                            , input_file_list = [##HIST_DIR + "Ewk.161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5.hists.root"
                                                                 ##, HIST_DIR + "Ewk.161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5.hists.root"
                                                                 ##, HIST_DIR + "Ewk.161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep.hists.root"
                                                                 ##, HIST_DIR + "Ewk.161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep.hists.root"
                                                                 ###, HIST_DIR + "Ewk.161305.hists.root" #ttH
                                                                 ##, HIST_DIR + "Ewk.160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu.hists.root"
                                                                 ##, HIST_DIR + "Ewk.160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu.hists.root"
                                                                 ##, HIST_DIR + "Ewk.160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu.hists.root"
                                                                 ##, HIST_DIR + "Ewk.160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu.hists.root"
                                                                 ##, HIST_DIR + "Ewk.160155.PowhegPythia8_AU2CT10_ggH125_ZZ4lep.hists.root"
                                                                 ##, HIST_DIR + "Ewk.160205.PowhegPythia8_AU2CT10_VBFH125_ZZ4lep.hists.root"
                                                                 ##, HIST_DIR + "Ewk.160255.Pythia8_AU2CTEQ6L1_WH125_ZZ4lep.hists.root"
                                                                 ##, HIST_DIR + "Ewk.160305.Pythia8_AU2CTEQ6L1_ZH125_ZZ4lep.hists.root"
                                                                 ]
                                            )

    ec_triboson = hh.Container.EntryContainer( label = 'Triboson'
                                            , fill_color = ROOT.kViolet
                                            , input_file_list = [ #HIST_DIR + "Ewk.167006.MadGraphPythia_AUET2BCTEQ6L1_WWWStar_lnulnulnu.hists.root"
                                                                  #, HIST_DIR + "Ewk.167007.MadGraphPythia_AUET2BCTEQ6L1_ZWWStar_lllnulnu.hists.root"
                                                                  #, HIST_DIR + "Ewk.167008.MadGraphPythia_AUET2BCTEQ6L1_ZZZStar_nunullll.hists.root"
                                                                  # 147191
                                                                  # 147193
                                                                  # 147194
                                                                  # 147195
                                                                  # 147196
                                                                  ]
                                            )

    ec_fakes = hh.Container.EntryContainer( label = 'Fakes'
                                            , fill_color = ROOT.kPink+7
                                            , input_file_list = [  HIST_DIR+ "Ewk.periodA_egamma.hists.fake.root"
                                                                , HIST_DIR + "Ewk.periodB_egamma.hists.fake.root"
                                                                , HIST_DIR + "Ewk.periodC_egamma.hists.fake.root"
                                                                , HIST_DIR + "Ewk.periodD_egamma.hists.fake.root"
                                                                , HIST_DIR + "Ewk.periodE_egamma.hists.fake.root"
                                                                , HIST_DIR + "Ewk.periodG_egamma.hists.fake.root"
                                                                , HIST_DIR + "Ewk.periodH_egamma.hists.fake.root"
                                                                , HIST_DIR + "Ewk.periodI_egamma.hists.fake.root"
                                                                , HIST_DIR + "Ewk.periodJ_egamma.hists.fake.root"
                                                                , HIST_DIR + "Ewk.periodL_egamma.hists.fake.root"
                                                                           
                                                                , HIST_DIR + "Ewk.periodA_muon.hists.fake.root"
                                                                , HIST_DIR + "Ewk.periodB_muon.hists.fake.root"
                                                                , HIST_DIR + "Ewk.periodC_muon.hists.fake.root"
                                                                , HIST_DIR + "Ewk.periodD_muon.hists.fake.root"
                                                                , HIST_DIR + "Ewk.periodE_muon.hists.fake.root"
                                                                , HIST_DIR + "Ewk.periodG_muon.hists.fake.root"
                                                                , HIST_DIR + "Ewk.periodH_muon.hists.fake.root"
                                                                , HIST_DIR + "Ewk.periodI_muon.hists.fake.root"
                                                                , HIST_DIR + "Ewk.periodJ_muon.hists.fake.root"
                                                                , HIST_DIR + "Ewk.periodL_muon.hists.fake.root"

            ]
                                            , lumi_modeled = 20281.4
                                            , lumi_target = 20281.4
                                            )
    ec_flip = hh.Container.EntryContainer( label = 'Charge MisID'
                                           , fill_color = ROOT.kGreen+3
                                           , input_file_list = [HIST_DIR+ "Ewk.periodA_egamma.hists.cf.root"
                                                                , HIST_DIR + "Ewk.periodB_egamma.hists.cf.root"
                                                                , HIST_DIR + "Ewk.periodC_egamma.hists.cf.root"
                                                                , HIST_DIR + "Ewk.periodD_egamma.hists.cf.root"
                                                                , HIST_DIR + "Ewk.periodE_egamma.hists.cf.root"
                                                                , HIST_DIR + "Ewk.periodG_egamma.hists.cf.root"
                                                                , HIST_DIR + "Ewk.periodH_egamma.hists.cf.root"
                                                                , HIST_DIR + "Ewk.periodI_egamma.hists.cf.root"
                                                                , HIST_DIR + "Ewk.periodJ_egamma.hists.cf.root"
                                                                , HIST_DIR + "Ewk.periodL_egamma.hists.cf.root"
                                                                           
                                                                , HIST_DIR + "Ewk.periodA_muon.hists.cf.root"
                                                                , HIST_DIR + "Ewk.periodB_muon.hists.cf.root"
                                                                , HIST_DIR + "Ewk.periodC_muon.hists.cf.root"
                                                                , HIST_DIR + "Ewk.periodD_muon.hists.cf.root"
                                                                , HIST_DIR + "Ewk.periodE_muon.hists.cf.root"
                                                                , HIST_DIR + "Ewk.periodG_muon.hists.cf.root"
                                                                , HIST_DIR + "Ewk.periodH_muon.hists.cf.root"
                                                                , HIST_DIR + "Ewk.periodI_muon.hists.cf.root"
                                                                , HIST_DIR + "Ewk.periodJ_muon.hists.cf.root"
                                                                , HIST_DIR + "Ewk.periodL_muon.hists.cf.root"

                                                                ] 
                                           , lumi_modeled = 20281.4
                                           , lumi_target = 20281.4
                                           )



    ic_numerator = hh.Container.InputContainer( name = 'Data'
                                              , entry_list = [ec_data]
                                              #,lumi_target = 13000
                                                )
    ic_denominator = hh.Container.InputContainer( name = 'Background'
                                                #, entry_list = [ec_zjets, ec_dy, ec_diboson, ec_ttbar, ec_higgs, ec_triboson, ec_ttbarboson, ec_fakes, ec_flip]
                                                 , entry_list = [ ec_diboson, ec_fakes, ec_flip]
                                                  #, lumi_target = 20281.4
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
