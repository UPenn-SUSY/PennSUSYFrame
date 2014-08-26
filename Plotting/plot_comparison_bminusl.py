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

    ec_data = hh.Container.EntryContainer( label = 'data (13 fb^{-1} scaled to 21 fb^{-1})'
                                         , fill_color = ROOT.kBlack
                                         , input_file_list = [ '%s/BMinusL.periodA_egamma.hists.root' % hist_dir
                                                             , '%s/BMinusL.periodB_egamma.hists.root' % hist_dir
                                                             , '%s/BMinusL.periodC_egamma.hists.root' % hist_dir
                                                             , '%s/BMinusL.periodD_egamma.hists.root' % hist_dir
                                                             , '%s/BMinusL.periodE_egamma.hists.root' % hist_dir
                                                             , '%s/BMinusL.periodA_muon.hists.root' % hist_dir
                                                             , '%s/BMinusL.periodB_muon.hists.root' % hist_dir
                                                             , '%s/BMinusL.periodC_muon.hists.root' % hist_dir
                                                             , '%s/BMinusL.periodD_muon.hists.root' % hist_dir
                                                             , '%s/BMinusL.periodE_muon.hists.root' % hist_dir
                                                             ]
                                         )

    # ec_ttbar = hh.Container.EntryContainer(  label = 'ttbar'
    #                                       # , fill_color = ROOT.kAzure+8
    #                                       , fill_color = ROOT.kGreen+2
    #                                       , input_file_list = [ "%s/BMinusL.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.hists.root" % hist_dir
    #                                                           ]
    #                                       )
    # ec_ttbar = hh.Container.EntryContainer( label = 'ttbar'
    #                                       # , fill_color = ROOT.kAzure+8
    #                                       , fill_color = ROOT.kGreen+2
    #                                       , input_file_list = [ # "%s/BMinusL.117050.PowhegPythia_P2011C_ttbar.hists.root" % hist_dir
    #                                                           ]
    #                                       )
    ec_ttbar = hh.Container.EntryContainer( label = 'ttbar'
                                          # , fill_color = ROOT.kAzure+8
                                          , fill_color = ROOT.kGreen+2
                                          , input_file_list = [ "%s/BMinusL.117050.PowhegPythia_P2011C_ttbar.af2_v2.hists.root" % hist_dir
                                                              ]
                                          )

    ec_ttv = hh.Container.EntryContainer( label = 'ttV'
                                        , fill_color = ROOT.kAzure+8
                                        , input_file_list = [ '%s/BMinusL.119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW.hists.root'   % hist_dir
                                                            , '%s/BMinusL.119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj.hists.root'  % hist_dir
                                                            , '%s/BMinusL.119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ.hists.root'   % hist_dir
                                                            , '%s/BMinusL.119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj.hists.root'  % hist_dir
                                                            , '%s/BMinusL.119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW.hists.root' % hist_dir
                                                            ]
                                        )


    # ec_Zbb = hh.Container.EntryContainer( label = 'Zbb'
    #                                     , fill_color = ROOT.kRed+1
    #                                     , input_file_list = [ "%s/BMinusL.110817.AlpgenPythia_P2011C_ZeebbNp0.hists.root" % hist_dir
    #                                     , input_file_list = [ "%s/BMinusL.110817.AlpgenPythia_P2011C_ZeebbNp0.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.110818.AlpgenPythia_P2011C_ZeebbNp1.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.110819.AlpgenPythia_P2011C_ZeebbNp2.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.110820.AlpgenPythia_P2011C_ZeebbNp3.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.110821.AlpgenPythia_P2011C_ZmumubbNp0.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.110822.AlpgenPythia_P2011C_ZmumubbNp1.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.110823.AlpgenPythia_P2011C_ZmumubbNp2.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.110824.AlpgenPythia_P2011C_ZmumubbNp3.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.110825.AlpgenPythia_P2011C_ZtautaubbNp0.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.110826.AlpgenPythia_P2011C_ZtautaubbNp1.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.110827.AlpgenPythia_P2011C_ZtautaubbNp2.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.110828.AlpgenPythia_P2011C_ZtautaubbNp3.hists.root" % hist_dir
    #                                                         ]
    #                                     )
    # ec_Zbb = hh.Container.EntryContainer( label = 'Zbb'
    #                                     , fill_color = ROOT.kRed+1
    #                                     , input_file_list = [ "%s/BMinusL.200332.AlpgenPythia_Auto_P2011C_ZeebbNp0.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.200333.AlpgenPythia_Auto_P2011C_ZeebbNp1.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.200334.AlpgenPythia_Auto_P2011C_ZeebbNp2.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.200335.AlpgenPythia_Auto_P2011C_ZeebbNp3incl.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.200341.AlpgenPythia_Auto_P2011C_ZmumubbNp1.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.200342.AlpgenPythia_Auto_P2011C_ZmumubbNp2.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.200343.AlpgenPythia_Auto_P2011C_ZmumubbNp3incl.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.200348.AlpgenPythia_Auto_P2011C_ZtautaubbNp0.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.200349.AlpgenPythia_Auto_P2011C_ZtautaubbNp1.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.200350.AlpgenPythia_Auto_P2011C_ZtautaubbNp2.hists.root" % hist_dir
    #                                                         , "%s/BMinusL.200351.AlpgenPythia_Auto_P2011C_ZtautaubbNp3incl.hists.root" % hist_dir
    #                                                         ]
    #                                     )
    ec_Zbb = hh.Container.EntryContainer( label = 'Z/#gamma^{*}'
                                        , fill_color = ROOT.kRed+1
                                        , input_file_list = [
                                                            # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                                                              '%s/BMinusL.167749.Sherpa_CT10_ZeeMassiveCBPt0_BFilter.hists.root'                % hist_dir
                                                            , '%s/BMinusL.180543.Sherpa_CT10_ZeeMassiveCBPt40_70_BFilter.hists.root'            % hist_dir
                                                            , '%s/BMinusL.167809.Sherpa_CT10_ZeeMassiveCBPt140_280_BFilter.hists.root'          % hist_dir
                                                            , '%s/BMinusL.167797.Sherpa_CT10_ZeeMassiveCBPt70_140_BFilter.hists.root'           % hist_dir
                                                            , '%s/BMinusL.167821.Sherpa_CT10_ZeeMassiveCBPt280_500_BFilter.hists.root'          % hist_dir
                                                            , '%s/BMinusL.167833.Sherpa_CT10_ZeeMassiveCBPt500_BFilter.hists.root'              % hist_dir

                                                            , '%s/BMinusL.167752.Sherpa_CT10_ZmumuMassiveCBPt0_BFilter.hists.root'              % hist_dir
                                                            , '%s/BMinusL.180546.Sherpa_CT10_ZmumuMassiveCBPt40_70_BFilter.hists.root'          % hist_dir
                                                            , '%s/BMinusL.167800.Sherpa_CT10_ZmumuMassiveCBPt70_140_BFilter.hists.root'         % hist_dir
                                                            , '%s/BMinusL.167812.Sherpa_CT10_ZmumuMassiveCBPt140_280_BFilter.hists.root'        % hist_dir
                                                            , '%s/BMinusL.167824.Sherpa_CT10_ZmumuMassiveCBPt280_500_BFilter.hists.root'        % hist_dir
                                                            , '%s/BMinusL.167836.Sherpa_CT10_ZmumuMassiveCBPt500_BFilter.hists.root'            % hist_dir

                                                            # , '%s/BMinusL.167755.Sherpa_CT10_ZtautauMassiveCBPt0_BFilter.hists.root'            % hist_dir
                                                            # , '%s/BMinusL.180549.Sherpa_CT10_ZtautauMassiveCBPt40_70_BFilter.hists.root'        % hist_dir
                                                            # , '%s/BMinusL.167803.Sherpa_CT10_ZtautauMassiveCBPt70_140_BFilter.hists.root'       % hist_dir
                                                            # , '%s/BMinusL.167815.Sherpa_CT10_ZtautauMassiveCBPt140_280_BFilter.hists.root'      % hist_dir
                                                            # , '%s/BMinusL.167827.Sherpa_CT10_ZtautauMassiveCBPt280_500_BFilter.hists.root'      % hist_dir
                                                            # , '%s/BMinusL.167839.Sherpa_CT10_ZtautauMassiveCBPt500_BFilter.hists.root'          % hist_dir

                                                            # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                                                            , '%s/BMinusL.167750.Sherpa_CT10_ZeeMassiveCBPt0_CFilterBVeto.hists.root'           % hist_dir
                                                            , '%s/BMinusL.180544.Sherpa_CT10_ZeeMassiveCBPt40_70_CFilterBVeto.hists.root'       % hist_dir
                                                            , '%s/BMinusL.167798.Sherpa_CT10_ZeeMassiveCBPt70_140_CFilterBVeto.hists.root'      % hist_dir
                                                            , '%s/BMinusL.167810.Sherpa_CT10_ZeeMassiveCBPt140_280_CFilterBVeto.hists.root'     % hist_dir
                                                            , '%s/BMinusL.167822.Sherpa_CT10_ZeeMassiveCBPt280_500_CFilterBVeto.hists.root'     % hist_dir
                                                            , '%s/BMinusL.167834.Sherpa_CT10_ZeeMassiveCBPt500_CFilterBVeto.hists.root'         % hist_dir

                                                            , '%s/BMinusL.167753.Sherpa_CT10_ZmumuMassiveCBPt0_CFilterBVeto.hists.root'         % hist_dir
                                                            , '%s/BMinusL.180547.Sherpa_CT10_ZmumuMassiveCBPt40_70_CFilterBVeto.hists.root'     % hist_dir
                                                            , '%s/BMinusL.167801.Sherpa_CT10_ZmumuMassiveCBPt70_140_CFilterBVeto.hists.root'    % hist_dir
                                                            , '%s/BMinusL.167813.Sherpa_CT10_ZmumuMassiveCBPt140_280_CFilterBVeto.hists.root'   % hist_dir
                                                            , '%s/BMinusL.167825.Sherpa_CT10_ZmumuMassiveCBPt280_500_CFilterBVeto.hists.root'   % hist_dir
                                                            , '%s/BMinusL.167837.Sherpa_CT10_ZmumuMassiveCBPt500_CFilterBVeto.hists.root'       % hist_dir

                                                            # , '%s/BMinusL.167756.Sherpa_CT10_ZtautauMassiveCBPt0_CFilterBVeto.hists.root'       % hist_dir
                                                            # , '%s/BMinusL.180550.Sherpa_CT10_ZtautauMassiveCBPt40_70_CFilterBVeto.hists.root'   % hist_dir
                                                            # , '%s/BMinusL.167804.Sherpa_CT10_ZtautauMassiveCBPt70_140_CFilterBVeto.hists.root'  % hist_dir
                                                            # , '%s/BMinusL.167816.Sherpa_CT10_ZtautauMassiveCBPt140_280_CFilterBVeto.hists.root' % hist_dir
                                                            # , '%s/BMinusL.167828.Sherpa_CT10_ZtautauMassiveCBPt280_500_CFilterBVeto.hists.root' % hist_dir
                                                            # , '%s/BMinusL.167840.Sherpa_CT10_ZtautauMassiveCBPt500_CFilterBVeto.hists.root'     % hist_dir

                                                            # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                                                            , '%s/BMinusL.167751.Sherpa_CT10_ZeeMassiveCBPt0_CVetoBVeto.hists.root'             % hist_dir
                                                            , '%s/BMinusL.180545.Sherpa_CT10_ZeeMassiveCBPt40_70_CVetoBVeto.hists.root'         % hist_dir
                                                            , '%s/BMinusL.167799.Sherpa_CT10_ZeeMassiveCBPt70_140_CVetoBVeto.hists.root'        % hist_dir
                                                            , '%s/BMinusL.167811.Sherpa_CT10_ZeeMassiveCBPt140_280_CVetoBVeto.hists.root'       % hist_dir
                                                            , '%s/BMinusL.167823.Sherpa_CT10_ZeeMassiveCBPt280_500_CVetoBVeto.hists.root'       % hist_dir
                                                            , '%s/BMinusL.167835.Sherpa_CT10_ZeeMassiveCBPt500_CVetoBVeto.hists.root'           % hist_dir

                                                            , '%s/BMinusL.167754.Sherpa_CT10_ZmumuMassiveCBPt0_CVetoBVeto.hists.root'           % hist_dir
                                                            , '%s/BMinusL.180548.Sherpa_CT10_ZmumuMassiveCBPt40_70_CVetoBVeto.hists.root'       % hist_dir
                                                            , '%s/BMinusL.167802.Sherpa_CT10_ZmumuMassiveCBPt70_140_CVetoBVeto.hists.root'      % hist_dir
                                                            , '%s/BMinusL.167814.Sherpa_CT10_ZmumuMassiveCBPt140_280_CVetoBVeto.hists.root'     % hist_dir
                                                            , '%s/BMinusL.167826.Sherpa_CT10_ZmumuMassiveCBPt280_500_CVetoBVeto.hists.root'     % hist_dir
                                                            , '%s/BMinusL.167838.Sherpa_CT10_ZmumuMassiveCBPt500_CVetoBVeto.hists.root'         % hist_dir

                                                            # , '%s/BMinusL.167757.Sherpa_CT10_ZtautauMassiveCBPt0_CVetoBVeto.hists.root'         % hist_dir
                                                            # , '%s/BMinusL.180551.Sherpa_CT10_ZtautauMassiveCBPt40_70_CVetoBVeto.hists.root'     % hist_dir
                                                            # , '%s/BMinusL.167805.Sherpa_CT10_ZtautauMassiveCBPt70_140_CVetoBVeto.hists.root'    % hist_dir
                                                            # , '%s/BMinusL.167817.Sherpa_CT10_ZtautauMassiveCBPt140_280_CVetoBVeto.hists.root'   % hist_dir
                                                            # , '%s/BMinusL.167829.Sherpa_CT10_ZtautauMassiveCBPt280_500_CVetoBVeto.hists.root'   % hist_dir
                                                            # , '%s/BMinusL.167841.Sherpa_CT10_ZtautauMassiveCBPt500_CVetoBVeto.hists.root'       % hist_dir

                                                            # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                                                            , '%s/BMinusL.173041.Sherpa_CT10_DYeeM08to15.hists.root'                            % hist_dir
                                                            , '%s/BMinusL.173042.Sherpa_CT10_DYeeM15to40.hists.root'                            % hist_dir

                                                            , '%s/BMinusL.173043.Sherpa_CT10_DYmumuM08to15.hists.root'                          % hist_dir
                                                            , '%s/BMinusL.173044.Sherpa_CT10_DYmumuM15to40.hists.root'                          % hist_dir

                                                            , '%s/BMinusL.173045.Sherpa_CT10_DYtautauM08to15.hists.root'                        % hist_dir
                                                            , '%s/BMinusL.173046.Sherpa_CT10_DYtautauM15to40.hists.root'                        % hist_dir
                                                            ]
                                        )
    # ec_single_top = hh.Container.EntryContainer( label = 'Single top'
    #                                            , fill_color = ROOT.kGreen-1
    #                                            , input_file_list = [ "%s/BMinusL.108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl.hists.root" % hist_dir
    #                                                                ]
    #                                            )
    ec_single_top = hh.Container.EntryContainer( label = 'Single top'
                                               , fill_color = ROOT.kGreen-1
                                               , input_file_list = [ "%s/BMinusL.110141.PowhegPythia_P2011C_st_Wtchan_dilepton_DR.hists.root" % hist_dir
                                                                   ]
                                               )

    ec_higgs = hh.Container.EntryContainer( label = 'higgs'
                                          , fill_color = ROOT.kOrange-5
                                          , input_file_list = [ '%s/BMinusL.160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu.hists.root'        % hist_dir
                                                              , '%s/BMinusL.160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu.hists.root'       % hist_dir
                                                              , '%s/BMinusL.160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu.hists.root'            % hist_dir
                                                              , '%s/BMinusL.160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu.hists.root'            % hist_dir
                                                              , '%s/BMinusL.161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5.hists.root'  % hist_dir
                                                              , '%s/BMinusL.161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5.hists.root' % hist_dir
                                                              , '%s/BMinusL.161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep.hists.root'              % hist_dir
                                                              , '%s/BMinusL.161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep.hists.root'              % hist_dir
                                                              , '%s/BMinusL.161305.Pythia8_AU2CTEQ6L1_ttH125_WWinclusive.hists.root'        % hist_dir
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
                                           , line_color = ROOT.kGreen+2
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
                                           , line_color = ROOT.kGreen+2
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
    # ic_numerator = hh.Container.InputContainer( name = 'dummy'
    ic_numerator = hh.Container.InputContainer( name = 'data'
                                              , entry_list = [ec_data]
                                              , lumi_target = 21/13.
                                              # , lumi_target = 0
                                              )
    ic_denominator = hh.Container.InputContainer( name = 'Background'
                                                , entry_list = [ec_ttbar, ec_single_top, ec_Zbb, ec_ttv, ec_higgs]
                                                # , entry_list = [ec_ttbar, ec_single_top, ec_Zbb]
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


