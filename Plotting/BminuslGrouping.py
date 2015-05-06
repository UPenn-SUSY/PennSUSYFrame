import itertools
import ROOT
import HistHandle as hh

# ------------------------------------------------------------------------------
def constructFileList(hist_dir, sample_list, syst_tag):
    leader = [hist_dir, '/BMinusL.']
    tail = []
    if syst_tag and syst_tag != '':
        leader.extend([syst_tag, '.'])
        tail.extend(['__', syst_tag])
    # temporary hack to get file name right
    tail.append('.hist.root' if 'dummy' not in sample_list[0] else '.root')

    return [''.join(itertools.chain(leader, [sample], tail))
            for sample in sample_list]

# ------------------------------------------------------------------------------
def generateEntryContainers( syst_tag = 'NOMINAL'
                           , hist_dir_mc   = None
                           , hist_dir_data = None
                           ):
    # construct histogram dir
    if hist_dir_mc is None:
        hist_dir_mc = ''.join(['${BASE_WORK_DIR}/NextPlotDir.BMinusL.', syst_tag])
    if hist_dir_data is None:
        hist_dir_data = ''.join(['${BASE_WORK_DIR}/NextPlotDir.BMinusL.', syst_tag])

    # dummy container
    ec_dummy = hh.Container.EntryContainer( label = 'dummy'
                                          , fill_color = ROOT.kBlack
                                          , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                               , syst_tag = None
                                                                               , sample_list = ['dummy_hists']
                                                                               )
                                          )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # data
    ec_data = hh.Container.EntryContainer( label = 'Data'
                                         , fill_color = ROOT.kBlack
                                         , input_file_list = constructFileList( hist_dir = hist_dir_data
                                                                              , syst_tag = 'NOMINAL' # always use nominal for data
                                                                              , sample_list = [ 'periodA_egamma'
                                                                                              , 'periodA_muon'
                                                                                              , 'periodB_egamma'
                                                                                              , 'periodB_muon'
                                                                                              , 'periodC_egamma'
                                                                                              , 'periodC_muon'
                                                                                              , 'periodD_egamma'
                                                                                              , 'periodD_muon'
                                                                                              , 'periodE_egamma'
                                                                                              , 'periodE_muon'
                                                                                              , 'periodG_egamma'
                                                                                              , 'periodG_muon'
                                                                                              , 'periodH_egamma'
                                                                                              , 'periodH_muon'
                                                                                              , 'periodI_egamma'
                                                                                              , 'periodI_muon'
                                                                                              , 'periodJ_egamma'
                                                                                              , 'periodJ_muon'
                                                                                              , 'periodL_egamma'
                                                                                              , 'periodL_muon'
                                                                                              ]
                                                                              )
                                         )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # ttbar
    # ec_ttbar_mcatnlo = hh.Container.EntryContainer(  label = 'ttbar'
    #                                               , fill_color = ROOT.kGreen+2
    #                                               , input_file_list = constructFileList( hist_dir = hist_dir_mc
    #                                                                                    , syst_tag = syst_tag
    #                                                                                    , sample_list = ['105200.McAtNloJimmy_CT10_ttbar_LeptonFilter']
    #                                                                                    )
    #                                               )
    ec_ttbar_powheg = hh.Container.EntryContainer( label = 'ttbar'
                                                 , fill_color = ROOT.kGreen+2
                                                 , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                                      , syst_tag = syst_tag
                                                                                      , sample_list = ["117050.PowhegPythia_P2011C_ttbar.af2"]
                                                                                      )
                                                 )


    # # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # # zbb
    # ec_Zbb_alpgen = hh.Container.EntryContainer( label = 'Zbb'
    #                                            , fill_color = ROOT.kRed+1
    #                                            , input_file_list = constructFileList( hist_dir = hist_dir_mc
    #                                                                                 , syst_tag = syst_tag
    #                                                                                 , sample_list = [ "200332.AlpgenPythia_Auto_P2011C_ZeebbNp0"
    #                                                                                                 , "200333.AlpgenPythia_Auto_P2011C_ZeebbNp1"
    #                                                                                                 , "200334.AlpgenPythia_Auto_P2011C_ZeebbNp2"
    #                                                                                                 , "200335.AlpgenPythia_Auto_P2011C_ZeebbNp3incl"
    #                                                                                                 , "200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0"
    #                                                                                                 , "200341.AlpgenPythia_Auto_P2011C_ZmumubbNp1"
    #                                                                                                 , "200342.AlpgenPythia_Auto_P2011C_ZmumubbNp2"
    #                                                                                                 , "200343.AlpgenPythia_Auto_P2011C_ZmumubbNp3incl"
    #                                                                                                 , "200348.AlpgenPythia_Auto_P2011C_ZtautaubbNp0"
    #                                                                                                 , "200349.AlpgenPythia_Auto_P2011C_ZtautaubbNp1"
    #                                                                                                 , "200350.AlpgenPythia_Auto_P2011C_ZtautaubbNp2"
    #                                                                                                 , "200351.AlpgenPythia_Auto_P2011C_ZtautaubbNp3incl"
    #                                                                                                 ]
    #                                                                                 )
    #                                            )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # Zgamma
    ec_Zgamma_sherpa = hh.Container.EntryContainer( label = 'Z/#gamma^{*}'
                                                  , fill_color = ROOT.kRed+1
                                                  , input_file_list =  constructFileList( hist_dir = hist_dir_mc
                                                                                        , syst_tag = syst_tag
                                                                                        , sample_list = [
                                                                                                        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                                                                                                          '167749.Sherpa_CT10_ZeeMassiveCBPt0_BFilter'
                                                                                                        , '180543.Sherpa_CT10_ZeeMassiveCBPt40_70_BFilter'
                                                                                                        , '167809.Sherpa_CT10_ZeeMassiveCBPt140_280_BFilter'
                                                                                                        , '167797.Sherpa_CT10_ZeeMassiveCBPt70_140_BFilter'
                                                                                                        , '167821.Sherpa_CT10_ZeeMassiveCBPt280_500_BFilter'
                                                                                                        , '167833.Sherpa_CT10_ZeeMassiveCBPt500_BFilter'

                                                                                                        , '167752.Sherpa_CT10_ZmumuMassiveCBPt0_BFilter'
                                                                                                        , '180546.Sherpa_CT10_ZmumuMassiveCBPt40_70_BFilter'
                                                                                                        , '167800.Sherpa_CT10_ZmumuMassiveCBPt70_140_BFilter'
                                                                                                        , '167812.Sherpa_CT10_ZmumuMassiveCBPt140_280_BFilter'
                                                                                                        , '167824.Sherpa_CT10_ZmumuMassiveCBPt280_500_BFilter'
                                                                                                        , '167836.Sherpa_CT10_ZmumuMassiveCBPt500_BFilter'

                                                                                                        , '167755.Sherpa_CT10_ZtautauMassiveCBPt0_BFilter'
                                                                                                        , '180549.Sherpa_CT10_ZtautauMassiveCBPt40_70_BFilter'
                                                                                                        , '167803.Sherpa_CT10_ZtautauMassiveCBPt70_140_BFilter'
                                                                                                        , '167815.Sherpa_CT10_ZtautauMassiveCBPt140_280_BFilter'
                                                                                                        , '167827.Sherpa_CT10_ZtautauMassiveCBPt280_500_BFilter'
                                                                                                        , '167839.Sherpa_CT10_ZtautauMassiveCBPt500_BFilter'

                                                                                                        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                                                                                                        , '167750.Sherpa_CT10_ZeeMassiveCBPt0_CFilterBVeto'
                                                                                                        , '180544.Sherpa_CT10_ZeeMassiveCBPt40_70_CFilterBVeto'
                                                                                                        , '167798.Sherpa_CT10_ZeeMassiveCBPt70_140_CFilterBVeto'
                                                                                                        , '167810.Sherpa_CT10_ZeeMassiveCBPt140_280_CFilterBVeto'
                                                                                                        , '167822.Sherpa_CT10_ZeeMassiveCBPt280_500_CFilterBVeto'
                                                                                                        , '167834.Sherpa_CT10_ZeeMassiveCBPt500_CFilterBVeto'

                                                                                                        , '167753.Sherpa_CT10_ZmumuMassiveCBPt0_CFilterBVeto'
                                                                                                        , '180547.Sherpa_CT10_ZmumuMassiveCBPt40_70_CFilterBVeto'
                                                                                                        , '167801.Sherpa_CT10_ZmumuMassiveCBPt70_140_CFilterBVeto'
                                                                                                        , '167813.Sherpa_CT10_ZmumuMassiveCBPt140_280_CFilterBVeto'
                                                                                                        , '167825.Sherpa_CT10_ZmumuMassiveCBPt280_500_CFilterBVeto'
                                                                                                        , '167837.Sherpa_CT10_ZmumuMassiveCBPt500_CFilterBVeto'

                                                                                                        , '167756.Sherpa_CT10_ZtautauMassiveCBPt0_CFilterBVeto'
                                                                                                        , '180550.Sherpa_CT10_ZtautauMassiveCBPt40_70_CFilterBVeto'
                                                                                                        , '167804.Sherpa_CT10_ZtautauMassiveCBPt70_140_CFilterBVeto'
                                                                                                        , '167816.Sherpa_CT10_ZtautauMassiveCBPt140_280_CFilterBVeto'
                                                                                                        , '167828.Sherpa_CT10_ZtautauMassiveCBPt280_500_CFilterBVeto'
                                                                                                        , '167840.Sherpa_CT10_ZtautauMassiveCBPt500_CFilterBVeto'

                                                                                                        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                                                                                                        , '167751.Sherpa_CT10_ZeeMassiveCBPt0_CVetoBVeto'
                                                                                                        , '180545.Sherpa_CT10_ZeeMassiveCBPt40_70_CVetoBVeto'
                                                                                                        , '167799.Sherpa_CT10_ZeeMassiveCBPt70_140_CVetoBVeto'
                                                                                                        , '167811.Sherpa_CT10_ZeeMassiveCBPt140_280_CVetoBVeto'
                                                                                                        , '167823.Sherpa_CT10_ZeeMassiveCBPt280_500_CVetoBVeto'
                                                                                                        , '167835.Sherpa_CT10_ZeeMassiveCBPt500_CVetoBVeto'

                                                                                                        , '167754.Sherpa_CT10_ZmumuMassiveCBPt0_CVetoBVeto'
                                                                                                        , '180548.Sherpa_CT10_ZmumuMassiveCBPt40_70_CVetoBVeto'
                                                                                                        , '167802.Sherpa_CT10_ZmumuMassiveCBPt70_140_CVetoBVeto'
                                                                                                        , '167814.Sherpa_CT10_ZmumuMassiveCBPt140_280_CVetoBVeto'
                                                                                                        , '167826.Sherpa_CT10_ZmumuMassiveCBPt280_500_CVetoBVeto'
                                                                                                        , '167838.Sherpa_CT10_ZmumuMassiveCBPt500_CVetoBVeto'

                                                                                                        , '167757.Sherpa_CT10_ZtautauMassiveCBPt0_CVetoBVeto'
                                                                                                        , '180551.Sherpa_CT10_ZtautauMassiveCBPt40_70_CVetoBVeto'
                                                                                                        , '167805.Sherpa_CT10_ZtautauMassiveCBPt70_140_CVetoBVeto'
                                                                                                        , '167817.Sherpa_CT10_ZtautauMassiveCBPt140_280_CVetoBVeto'
                                                                                                        , '167829.Sherpa_CT10_ZtautauMassiveCBPt280_500_CVetoBVeto'
                                                                                                        , '167841.Sherpa_CT10_ZtautauMassiveCBPt500_CVetoBVeto'

                                                                                                        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                                                                                                        , '173041.Sherpa_CT10_DYeeM08to15'
                                                                                                        , '173042.Sherpa_CT10_DYeeM15to40'

                                                                                                        , '173043.Sherpa_CT10_DYmumuM08to15'
                                                                                                        , '173044.Sherpa_CT10_DYmumuM15to40'

                                                                                                        , '173045.Sherpa_CT10_DYtautauM08to15'
                                                                                                        , '173046.Sherpa_CT10_DYtautauM15to40'
                                                                                                        ]
                                                                                        )
                                                  )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # Zgamma
    ec_Zgamma_sherpa_no_k_factor = hh.Container.EntryContainer( label = 'Z/#gamma^{*}'
                                                              , fill_color = ROOT.kRed+1
                                                              , container_weight = 1/1.3855
                                                              , input_file_list =  constructFileList( hist_dir = hist_dir_mc
                                                                                                    , syst_tag = syst_tag
                                                                                                    , sample_list = [
                                                                                                                    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                                                                                                                      '167749.Sherpa_CT10_ZeeMassiveCBPt0_BFilter'
                                                                                                                    , '180543.Sherpa_CT10_ZeeMassiveCBPt40_70_BFilter'
                                                                                                                    , '167809.Sherpa_CT10_ZeeMassiveCBPt140_280_BFilter'
                                                                                                                    , '167797.Sherpa_CT10_ZeeMassiveCBPt70_140_BFilter'
                                                                                                                    , '167821.Sherpa_CT10_ZeeMassiveCBPt280_500_BFilter'
                                                                                                                    , '167833.Sherpa_CT10_ZeeMassiveCBPt500_BFilter'

                                                                                                                    , '167752.Sherpa_CT10_ZmumuMassiveCBPt0_BFilter'
                                                                                                                    , '180546.Sherpa_CT10_ZmumuMassiveCBPt40_70_BFilter'
                                                                                                                    , '167800.Sherpa_CT10_ZmumuMassiveCBPt70_140_BFilter'
                                                                                                                    , '167812.Sherpa_CT10_ZmumuMassiveCBPt140_280_BFilter'
                                                                                                                    , '167824.Sherpa_CT10_ZmumuMassiveCBPt280_500_BFilter'
                                                                                                                    , '167836.Sherpa_CT10_ZmumuMassiveCBPt500_BFilter'

                                                                                                                    , '167755.Sherpa_CT10_ZtautauMassiveCBPt0_BFilter'
                                                                                                                    , '180549.Sherpa_CT10_ZtautauMassiveCBPt40_70_BFilter'
                                                                                                                    , '167803.Sherpa_CT10_ZtautauMassiveCBPt70_140_BFilter'
                                                                                                                    , '167815.Sherpa_CT10_ZtautauMassiveCBPt140_280_BFilter'
                                                                                                                    , '167827.Sherpa_CT10_ZtautauMassiveCBPt280_500_BFilter'
                                                                                                                    , '167839.Sherpa_CT10_ZtautauMassiveCBPt500_BFilter'

                                                                                                                    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                                                                                                                    , '167750.Sherpa_CT10_ZeeMassiveCBPt0_CFilterBVeto'
                                                                                                                    , '180544.Sherpa_CT10_ZeeMassiveCBPt40_70_CFilterBVeto'
                                                                                                                    , '167798.Sherpa_CT10_ZeeMassiveCBPt70_140_CFilterBVeto'
                                                                                                                    , '167810.Sherpa_CT10_ZeeMassiveCBPt140_280_CFilterBVeto'
                                                                                                                    , '167822.Sherpa_CT10_ZeeMassiveCBPt280_500_CFilterBVeto'
                                                                                                                    , '167834.Sherpa_CT10_ZeeMassiveCBPt500_CFilterBVeto'

                                                                                                                    , '167753.Sherpa_CT10_ZmumuMassiveCBPt0_CFilterBVeto'
                                                                                                                    , '180547.Sherpa_CT10_ZmumuMassiveCBPt40_70_CFilterBVeto'
                                                                                                                    , '167801.Sherpa_CT10_ZmumuMassiveCBPt70_140_CFilterBVeto'
                                                                                                                    , '167813.Sherpa_CT10_ZmumuMassiveCBPt140_280_CFilterBVeto'
                                                                                                                    , '167825.Sherpa_CT10_ZmumuMassiveCBPt280_500_CFilterBVeto'
                                                                                                                    , '167837.Sherpa_CT10_ZmumuMassiveCBPt500_CFilterBVeto'

                                                                                                                    , '167756.Sherpa_CT10_ZtautauMassiveCBPt0_CFilterBVeto'
                                                                                                                    , '180550.Sherpa_CT10_ZtautauMassiveCBPt40_70_CFilterBVeto'
                                                                                                                    , '167804.Sherpa_CT10_ZtautauMassiveCBPt70_140_CFilterBVeto'
                                                                                                                    , '167816.Sherpa_CT10_ZtautauMassiveCBPt140_280_CFilterBVeto'
                                                                                                                    , '167828.Sherpa_CT10_ZtautauMassiveCBPt280_500_CFilterBVeto'
                                                                                                                    , '167840.Sherpa_CT10_ZtautauMassiveCBPt500_CFilterBVeto'

                                                                                                                    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                                                                                                                    , '167751.Sherpa_CT10_ZeeMassiveCBPt0_CVetoBVeto'
                                                                                                                    , '180545.Sherpa_CT10_ZeeMassiveCBPt40_70_CVetoBVeto'
                                                                                                                    , '167799.Sherpa_CT10_ZeeMassiveCBPt70_140_CVetoBVeto'
                                                                                                                    , '167811.Sherpa_CT10_ZeeMassiveCBPt140_280_CVetoBVeto'
                                                                                                                    , '167823.Sherpa_CT10_ZeeMassiveCBPt280_500_CVetoBVeto'
                                                                                                                    , '167835.Sherpa_CT10_ZeeMassiveCBPt500_CVetoBVeto'

                                                                                                                    , '167754.Sherpa_CT10_ZmumuMassiveCBPt0_CVetoBVeto'
                                                                                                                    , '180548.Sherpa_CT10_ZmumuMassiveCBPt40_70_CVetoBVeto'
                                                                                                                    , '167802.Sherpa_CT10_ZmumuMassiveCBPt70_140_CVetoBVeto'
                                                                                                                    , '167814.Sherpa_CT10_ZmumuMassiveCBPt140_280_CVetoBVeto'
                                                                                                                    , '167826.Sherpa_CT10_ZmumuMassiveCBPt280_500_CVetoBVeto'
                                                                                                                    , '167838.Sherpa_CT10_ZmumuMassiveCBPt500_CVetoBVeto'

                                                                                                                    , '167757.Sherpa_CT10_ZtautauMassiveCBPt0_CVetoBVeto'
                                                                                                                    , '180551.Sherpa_CT10_ZtautauMassiveCBPt40_70_CVetoBVeto'
                                                                                                                    , '167805.Sherpa_CT10_ZtautauMassiveCBPt70_140_CVetoBVeto'
                                                                                                                    , '167817.Sherpa_CT10_ZtautauMassiveCBPt140_280_CVetoBVeto'
                                                                                                                    , '167829.Sherpa_CT10_ZtautauMassiveCBPt280_500_CVetoBVeto'
                                                                                                                    , '167841.Sherpa_CT10_ZtautauMassiveCBPt500_CVetoBVeto'

                                                                                                                    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                                                                                                                    , '173041.Sherpa_CT10_DYeeM08to15'
                                                                                                                    , '173042.Sherpa_CT10_DYeeM15to40'

                                                                                                                    , '173043.Sherpa_CT10_DYmumuM08to15'
                                                                                                                    , '173044.Sherpa_CT10_DYmumuM15to40'

                                                                                                                    , '173045.Sherpa_CT10_DYtautauM08to15'
                                                                                                                    , '173046.Sherpa_CT10_DYtautauM15to40'
                                                                                                                    ]
                                                                                                    )
                                                              )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # single top
    ec_single_top_all_channels = hh.Container.EntryContainer( label = 'Single top'
                                                            , fill_color = ROOT.kGreen-1
                                                            , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                                                 , syst_tag = syst_tag
                                                                                                 , sample_list = [ "110141.PowhegPythia_P2011C_st_Wtchan_dilepton_DR"
                                                                                                                 , "110119.PowhegPythia_P2011C_st_schan_lep"
                                                                                                                 , "110101.AcerMCPythia_P2011CCTEQ6L1_singletop_tchan_l"
                                                                                                                 ]
                                                                                                 )
                                                            )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # other
    ec_other = hh.Container.EntryContainer( label = 'Other'
                                          , fill_color = ROOT.kAzure+8
                                          , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                               , syst_tag = syst_tag
                                                                               , sample_list = [ '119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW'
                                                                                               , '119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj'
                                                                                               , '119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ'
                                                                                               , '119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj'
                                                                                               , '119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW'

                                                                                               , "177997.Sherpa_CT10_llnunu_WW_MassiveCB"
                                                                                               , "177999.Sherpa_CT10_llnunu_ZZ_MassiveCB"
                                                                                               , "179974.Sherpa_CT10_lllnu_WZ_MassiveCB"
                                                                                               , "179975.Sherpa_CT10_lnununu_WZ_MassiveCB"

                                                                                               , "183585.Sherpa_CT10_ZWtoeeqq_MassiveCB"
                                                                                               , "183586.Sherpa_CT10_ZZtoeeqq_MassiveCB"
                                                                                               , "183587.Sherpa_CT10_ZWtomumuqq_MassiveCB"
                                                                                               , "183588.Sherpa_CT10_ZZtomumuqq_MassiveCB"
                                                                                               , "183589.Sherpa_CT10_ZWtotautauqq_MassiveCB"
                                                                                               , "183590.Sherpa_CT10_ZZtotautauqq_MassiveCB"
                                                                                               , "183591.Sherpa_CT10_ZWtonunuqq_MassiveCB"
                                                                                               , "183592.Sherpa_CT10_ZZtonunuqq_MassiveCB"
                                                                                               , "183734.Sherpa_CT10_WWtoenuqq_MassiveCB"
                                                                                               , "183735.Sherpa_CT10_WZtoenuqq_MassiveCB"
                                                                                               , "183736.Sherpa_CT10_WWtomunuqq_MassiveCB"
                                                                                               , "183737.Sherpa_CT10_WZtomunuqq_MassiveCB"
                                                                                               , "183738.Sherpa_CT10_WWtotaunuqq_MassiveCB"
                                                                                               , "183739.Sherpa_CT10_WZtotaunuqq_MassiveCB"

                                                                                               , '160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu'
                                                                                               , '160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu'
                                                                                               , '160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu'
                                                                                               , '160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu'
                                                                                               , '161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5'
                                                                                               , '161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5'
                                                                                               , '161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep'
                                                                                               , '161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep'
                                                                                               , '161305.Pythia8_AU2CTEQ6L1_ttH125_WWinclusive'

                                                                                               , '167740.Sherpa_CT10_WenuMassiveCBPt0_BFilter'
                                                                                               , '167741.Sherpa_CT10_WenuMassiveCBPt0_CJetFilterBVeto'
                                                                                               , '167742.Sherpa_CT10_WenuMassiveCBPt0_CJetVetoBVeto'

                                                                                               , '167743.Sherpa_CT10_WmunuMassiveCBPt0_BFilter'
                                                                                               , '167744.Sherpa_CT10_WmunuMassiveCBPt0_CJetFilterBVeto'
                                                                                               , '167745.Sherpa_CT10_WmunuMassiveCBPt0_CJetVetoBVeto'

                                                                                               , '167746.Sherpa_CT10_WtaunuMassiveCBPt0_BFilter'
                                                                                               , '167747.Sherpa_CT10_WtaunuMassiveCBPt0_CJetFilterBVeto'
                                                                                               , '167748.Sherpa_CT10_WtaunuMassiveCBPt0_CJetVetoBVeto'

                                                                                               , '167761.Sherpa_CT10_WenuMassiveCBPt70_140_BFilter'
                                                                                               , '167762.Sherpa_CT10_WenuMassiveCBPt70_140_CJetFilterBVeto'
                                                                                               , '167763.Sherpa_CT10_WenuMassiveCBPt70_140_CJetVetoBVeto'

                                                                                               , '167764.Sherpa_CT10_WmunuMassiveCBPt70_140_BFilter'
                                                                                               , '167765.Sherpa_CT10_WmunuMassiveCBPt70_140_CJetFilterBVeto'
                                                                                               , '167766.Sherpa_CT10_WmunuMassiveCBPt70_140_CJetVetoBVeto'

                                                                                               , '167767.Sherpa_CT10_WtaunuMassiveCBPt70_140_BFilter'
                                                                                               , '167768.Sherpa_CT10_WtaunuMassiveCBPt70_140_CJetFilterBVeto'
                                                                                               , '167769.Sherpa_CT10_WtaunuMassiveCBPt70_140_CJetVetoBVeto'

                                                                                               , '167770.Sherpa_CT10_WenuMassiveCBPt140_280_BFilter'
                                                                                               , '167771.Sherpa_CT10_WenuMassiveCBPt140_280_CJetFilterBVeto'
                                                                                               , '167772.Sherpa_CT10_WenuMassiveCBPt140_280_CJetVetoBVeto'

                                                                                               , '167773.Sherpa_CT10_WmunuMassiveCBPt140_280_BFilter'
                                                                                               , '167774.Sherpa_CT10_WmunuMassiveCBPt140_280_CJetFilterBVeto'
                                                                                               , '167775.Sherpa_CT10_WmunuMassiveCBPt140_280_CJetVetoBVeto'

                                                                                               , '167776.Sherpa_CT10_WtaunuMassiveCBPt140_280_BFilter'
                                                                                               , '167777.Sherpa_CT10_WtaunuMassiveCBPt140_280_CJetFilterBVeto'
                                                                                               , '167778.Sherpa_CT10_WtaunuMassiveCBPt140_280_CJetVetoBVeto'

                                                                                               , '167779.Sherpa_CT10_WenuMassiveCBPt280_500_BFilter'
                                                                                               , '167780.Sherpa_CT10_WenuMassiveCBPt280_500_CJetFilterBVeto'
                                                                                               , '167781.Sherpa_CT10_WenuMassiveCBPt280_500_CJetVetoBVeto'

                                                                                               , '167782.Sherpa_CT10_WmunuMassiveCBPt280_500_BFilter'
                                                                                               , '167783.Sherpa_CT10_WmunuMassiveCBPt280_500_CJetFilterBVeto'
                                                                                               , '167784.Sherpa_CT10_WmunuMassiveCBPt280_500_CJetVetoBVeto'

                                                                                               , '167785.Sherpa_CT10_WtaunuMassiveCBPt280_500_BFilter'
                                                                                               , '167786.Sherpa_CT10_WtaunuMassiveCBPt280_500_CJetFilterBVeto'
                                                                                               , '167787.Sherpa_CT10_WtaunuMassiveCBPt280_500_CJetVetoBVeto'

                                                                                               , '167788.Sherpa_CT10_WenuMassiveCBPt500_BFilter'
                                                                                               , '167789.Sherpa_CT10_WenuMassiveCBPt500_CJetFilterBVeto'
                                                                                               , '167790.Sherpa_CT10_WenuMassiveCBPt500_CJetVetoBVeto'

                                                                                               , '167791.Sherpa_CT10_WmunuMassiveCBPt500_BFilter'
                                                                                               , '167792.Sherpa_CT10_WmunuMassiveCBPt500_CJetFilterBVeto'
                                                                                               , '167793.Sherpa_CT10_WmunuMassiveCBPt500_CJetVetoBVeto'

                                                                                               , '167794.Sherpa_CT10_WtaunuMassiveCBPt500_BFilter'
                                                                                               , '167795.Sherpa_CT10_WtaunuMassiveCBPt500_CJetFilterBVeto'
                                                                                               , '167796.Sherpa_CT10_WtaunuMassiveCBPt500_CJetVetoBVeto'

                                                                                               , '180534.Sherpa_CT10_WenuMassiveCBPt40_70_BFilter'
                                                                                               , '180535.Sherpa_CT10_WenuMassiveCBPt40_70_CJetFilterBVeto'
                                                                                               , '180536.Sherpa_CT10_WenuMassiveCBPt40_70_CJetVetoBVeto'

                                                                                               , '180537.Sherpa_CT10_WmunuMassiveCBPt40_70_BFilter'
                                                                                               , '180538.Sherpa_CT10_WmunuMassiveCBPt40_70_CJetFilterBVeto'
                                                                                               , '180539.Sherpa_CT10_WmunuMassiveCBPt40_70_CJetVetoBVeto'

                                                                                               , '180540.Sherpa_CT10_WtaunuMassiveCBPt40_70_BFilter'
                                                                                               , '180541.Sherpa_CT10_WtaunuMassiveCBPt40_70_CJetFilterBVeto'
                                                                                               , '180542.Sherpa_CT10_WtaunuMassiveCBPt40_70_CJetVetoBVeto'
                                                                                               ]
                                                                               )
                                          )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # other
    ec_ZZ = hh.Container.EntryContainer( label = 'ZZ'
                                       , fill_color = ROOT.kMagenta
                                       , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                            , syst_tag = syst_tag
                                                                            , sample_list = [ "177999.Sherpa_CT10_llnunu_ZZ_MassiveCB"

                                                                                            , "183586.Sherpa_CT10_ZZtoeeqq_MassiveCB"
                                                                                            , "183588.Sherpa_CT10_ZZtomumuqq_MassiveCB"
                                                                                            , "183590.Sherpa_CT10_ZZtotautauqq_MassiveCB"
                                                                                            , "183592.Sherpa_CT10_ZZtonunuqq_MassiveCB"
                                                                                            ]
                                                                            )
                                       )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # ttV
    ec_ttv = hh.Container.EntryContainer( label = 'ttV'
                                        , fill_color = ROOT.kAzure+8
                                        , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                             , syst_tag = syst_tag
                                                                             , sample_list = [ '119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW'
                                                                                             , '119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj'
                                                                                             , '119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ'
                                                                                             , '119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj'
                                                                                             , '119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW'
                                                                                             ]
                                                                             )
                                        )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # diboson
    ec_diboson = hh.Container.EntryContainer( label = 'Diboson'
                                            , fill_color = ROOT.kSpring-4
                                            , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                                 , syst_tag = syst_tag
                                                                                 , sample_list = [ "177997.Sherpa_CT10_llnunu_WW_MassiveCB"
                                                                                                 , "177999.Sherpa_CT10_llnunu_ZZ_MassiveCB"
                                                                                                 , "179974.Sherpa_CT10_lllnu_WZ_MassiveCB"
                                                                                                 , "179975.Sherpa_CT10_lnununu_WZ_MassiveCB"
                                                                                                 , "183585.Sherpa_CT10_ZWtoeeqq_MassiveCB"
                                                                                                 , "183586.Sherpa_CT10_ZZtoeeqq_MassiveCB"
                                                                                                 , "183587.Sherpa_CT10_ZWtomumuqq_MassiveCB"
                                                                                                 , "183588.Sherpa_CT10_ZZtomumuqq_MassiveCB"
                                                                                                 , "183589.Sherpa_CT10_ZWtotautauqq_MassiveCB"
                                                                                                 , "183590.Sherpa_CT10_ZZtotautauqq_MassiveCB"
                                                                                                 , "183591.Sherpa_CT10_ZWtonunuqq_MassiveCB"
                                                                                                 , "183592.Sherpa_CT10_ZZtonunuqq_MassiveCB"
                                                                                                 , "183734.Sherpa_CT10_WWtoenuqq_MassiveCB"
                                                                                                 , "183735.Sherpa_CT10_WZtoenuqq_MassiveCB"
                                                                                                 , "183736.Sherpa_CT10_WWtomunuqq_MassiveCB"
                                                                                                 , "183737.Sherpa_CT10_WZtomunuqq_MassiveCB"
                                                                                                 , "183738.Sherpa_CT10_WWtotaunuqq_MassiveCB"
                                                                                                 , "183739.Sherpa_CT10_WZtotaunuqq_MassiveCB"
                                                                                                 ]
                                                                                 )
                                            )


    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # other
    ec_other_no_ZZ = hh.Container.EntryContainer( label = 'Other'
                                                , fill_color = ROOT.kAzure+8
                                                , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                                     , syst_tag = syst_tag
                                                                                     , sample_list = [ '119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW'
                                                                                                     , '119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj'
                                                                                                     , '119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ'
                                                                                                     , '119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj'
                                                                                                     , '119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW'

                                                                                                     , "177997.Sherpa_CT10_llnunu_WW_MassiveCB"
                                                                                                     , "179974.Sherpa_CT10_lllnu_WZ_MassiveCB"
                                                                                                     , "179975.Sherpa_CT10_lnununu_WZ_MassiveCB"

                                                                                                     , "183585.Sherpa_CT10_ZWtoeeqq_MassiveCB"
                                                                                                     , "183587.Sherpa_CT10_ZWtomumuqq_MassiveCB"
                                                                                                     , "183589.Sherpa_CT10_ZWtotautauqq_MassiveCB"
                                                                                                     , "183591.Sherpa_CT10_ZWtonunuqq_MassiveCB"
                                                                                                     , "183592.Sherpa_CT10_ZZtonunuqq_MassiveCB"
                                                                                                     , "183734.Sherpa_CT10_WWtoenuqq_MassiveCB"
                                                                                                     , "183735.Sherpa_CT10_WZtoenuqq_MassiveCB"
                                                                                                     , "183736.Sherpa_CT10_WWtomunuqq_MassiveCB"
                                                                                                     , "183737.Sherpa_CT10_WZtomunuqq_MassiveCB"
                                                                                                     , "183738.Sherpa_CT10_WWtotaunuqq_MassiveCB"
                                                                                                     , "183739.Sherpa_CT10_WZtotaunuqq_MassiveCB"

                                                                                                     , '160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu'
                                                                                                     , '160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu'
                                                                                                     , '160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu'
                                                                                                     , '160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu'
                                                                                                     , '161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5'
                                                                                                     , '161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5'
                                                                                                     , '161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep'
                                                                                                     , '161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep'
                                                                                                     , '161305.Pythia8_AU2CTEQ6L1_ttH125_WWinclusive'

                                                                                                     , '167740.Sherpa_CT10_WenuMassiveCBPt0_BFilter'
                                                                                                     , '167741.Sherpa_CT10_WenuMassiveCBPt0_CJetFilterBVeto'
                                                                                                     , '167742.Sherpa_CT10_WenuMassiveCBPt0_CJetVetoBVeto'

                                                                                                     , '167743.Sherpa_CT10_WmunuMassiveCBPt0_BFilter'
                                                                                                     , '167744.Sherpa_CT10_WmunuMassiveCBPt0_CJetFilterBVeto'
                                                                                                     , '167745.Sherpa_CT10_WmunuMassiveCBPt0_CJetVetoBVeto'

                                                                                                     , '167746.Sherpa_CT10_WtaunuMassiveCBPt0_BFilter'
                                                                                                     , '167747.Sherpa_CT10_WtaunuMassiveCBPt0_CJetFilterBVeto'
                                                                                                     , '167748.Sherpa_CT10_WtaunuMassiveCBPt0_CJetVetoBVeto'

                                                                                                     , '167761.Sherpa_CT10_WenuMassiveCBPt70_140_BFilter'
                                                                                                     , '167762.Sherpa_CT10_WenuMassiveCBPt70_140_CJetFilterBVeto'
                                                                                                     , '167763.Sherpa_CT10_WenuMassiveCBPt70_140_CJetVetoBVeto'

                                                                                                     , '167764.Sherpa_CT10_WmunuMassiveCBPt70_140_BFilter'
                                                                                                     , '167765.Sherpa_CT10_WmunuMassiveCBPt70_140_CJetFilterBVeto'
                                                                                                     , '167766.Sherpa_CT10_WmunuMassiveCBPt70_140_CJetVetoBVeto'

                                                                                                     , '167767.Sherpa_CT10_WtaunuMassiveCBPt70_140_BFilter'
                                                                                                     , '167768.Sherpa_CT10_WtaunuMassiveCBPt70_140_CJetFilterBVeto'
                                                                                                     , '167769.Sherpa_CT10_WtaunuMassiveCBPt70_140_CJetVetoBVeto'

                                                                                                     , '167770.Sherpa_CT10_WenuMassiveCBPt140_280_BFilter'
                                                                                                     , '167771.Sherpa_CT10_WenuMassiveCBPt140_280_CJetFilterBVeto'
                                                                                                     , '167772.Sherpa_CT10_WenuMassiveCBPt140_280_CJetVetoBVeto'

                                                                                                     , '167773.Sherpa_CT10_WmunuMassiveCBPt140_280_BFilter'
                                                                                                     , '167774.Sherpa_CT10_WmunuMassiveCBPt140_280_CJetFilterBVeto'
                                                                                                     , '167775.Sherpa_CT10_WmunuMassiveCBPt140_280_CJetVetoBVeto'

                                                                                                     , '167776.Sherpa_CT10_WtaunuMassiveCBPt140_280_BFilter'
                                                                                                     , '167777.Sherpa_CT10_WtaunuMassiveCBPt140_280_CJetFilterBVeto'
                                                                                                     , '167778.Sherpa_CT10_WtaunuMassiveCBPt140_280_CJetVetoBVeto'

                                                                                                     , '167779.Sherpa_CT10_WenuMassiveCBPt280_500_BFilter'
                                                                                                     , '167780.Sherpa_CT10_WenuMassiveCBPt280_500_CJetFilterBVeto'
                                                                                                     , '167781.Sherpa_CT10_WenuMassiveCBPt280_500_CJetVetoBVeto'

                                                                                                     , '167782.Sherpa_CT10_WmunuMassiveCBPt280_500_BFilter'
                                                                                                     , '167783.Sherpa_CT10_WmunuMassiveCBPt280_500_CJetFilterBVeto'
                                                                                                     , '167784.Sherpa_CT10_WmunuMassiveCBPt280_500_CJetVetoBVeto'

                                                                                                     , '167785.Sherpa_CT10_WtaunuMassiveCBPt280_500_BFilter'
                                                                                                     , '167786.Sherpa_CT10_WtaunuMassiveCBPt280_500_CJetFilterBVeto'
                                                                                                     , '167787.Sherpa_CT10_WtaunuMassiveCBPt280_500_CJetVetoBVeto'

                                                                                                     , '167788.Sherpa_CT10_WenuMassiveCBPt500_BFilter'
                                                                                                     , '167789.Sherpa_CT10_WenuMassiveCBPt500_CJetFilterBVeto'
                                                                                                     , '167790.Sherpa_CT10_WenuMassiveCBPt500_CJetVetoBVeto'

                                                                                                     , '167791.Sherpa_CT10_WmunuMassiveCBPt500_BFilter'
                                                                                                     , '167792.Sherpa_CT10_WmunuMassiveCBPt500_CJetFilterBVeto'
                                                                                                     , '167793.Sherpa_CT10_WmunuMassiveCBPt500_CJetVetoBVeto'

                                                                                                     , '167794.Sherpa_CT10_WtaunuMassiveCBPt500_BFilter'
                                                                                                     , '167795.Sherpa_CT10_WtaunuMassiveCBPt500_CJetFilterBVeto'
                                                                                                     , '167796.Sherpa_CT10_WtaunuMassiveCBPt500_CJetVetoBVeto'

                                                                                                     , '180534.Sherpa_CT10_WenuMassiveCBPt40_70_BFilter'
                                                                                                     , '180535.Sherpa_CT10_WenuMassiveCBPt40_70_CJetFilterBVeto'
                                                                                                     , '180536.Sherpa_CT10_WenuMassiveCBPt40_70_CJetVetoBVeto'

                                                                                                     , '180537.Sherpa_CT10_WmunuMassiveCBPt40_70_BFilter'
                                                                                                     , '180538.Sherpa_CT10_WmunuMassiveCBPt40_70_CJetFilterBVeto'
                                                                                                     , '180539.Sherpa_CT10_WmunuMassiveCBPt40_70_CJetVetoBVeto'

                                                                                                     , '180540.Sherpa_CT10_WtaunuMassiveCBPt40_70_BFilter'
                                                                                                     , '180541.Sherpa_CT10_WtaunuMassiveCBPt40_70_CJetFilterBVeto'
                                                                                                     , '180542.Sherpa_CT10_WtaunuMassiveCBPt40_70_CJetVetoBVeto'
                                                                                                     ]
                                                                                     )
                                                )



    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # higgs
    ec_higgs = hh.Container.EntryContainer( label = 'higgs'
                                          , fill_color = ROOT.kOrange-5
                                          , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                               , syst_tag = syst_tag
                                                                               , sample_list = [ '160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu'
                                                                                               , '160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu'
                                                                                               , '160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu'
                                                                                               , '160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu'
                                                                                               , '161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5'
                                                                                               , '161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5'
                                                                                               , '161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep'
                                                                                               , '161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep'
                                                                                               , '161305.Pythia8_AU2CTEQ6L1_ttH125_WWinclusive'
                                                                                               ]
                                                                               )
                                          )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # signal
    ec_bl_100 = hh.Container.EntryContainer( label = 'B-L stop (100 GeV)'
                                           , line_color = ROOT.kMagenta
                                           , line_width = 4
                                           , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                                , syst_tag = syst_tag
                                                                                , sample_list = [ "202632.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_100"
                                                                                                ]
                                                                                )
                                           )
    ec_bl_200 = hh.Container.EntryContainer( label = 'B-L stop (200 GeV)'
                                           , line_color = ROOT.kGreen+2
                                           , line_width = 4
                                           , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                                , syst_tag = syst_tag
                                                                                , sample_list = [ "202633.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_200"
                                                                                                ]
                                                                                )
                                           )
    ec_bl_300 = hh.Container.EntryContainer( label = 'B-L stop (300 GeV)'
                                           , line_color = ROOT.kGreen+2
                                           , line_width = 4
                                           , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                                , syst_tag = syst_tag
                                                                                , sample_list = [ "202634.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_300"
                                                                                                ]
                                                                                )
                                           )
    ec_bl_400 = hh.Container.EntryContainer( label = 'B-L stop (400 GeV)'
                                           , line_color = ROOT.kTeal-2
                                           , line_width = 4
                                           , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                                , syst_tag = syst_tag
                                                                                , sample_list = [ "202635.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_400"
                                                                                                ]
                                                                                )
                                           )
    ec_bl_500 = hh.Container.EntryContainer( label = 'B-L stop (500 GeV)'
                                           , line_color = ROOT.kBlue+2
                                           , line_width = 4
                                           , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                                , syst_tag = syst_tag
                                                                                , sample_list = [ "202636.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_500"
                                                                                                ]
                                                                                )
                                           )
    ec_bl_600 = hh.Container.EntryContainer( label = 'B-L stop (600 GeV)'
                                           , line_color = ROOT.kOrange-3
                                           , line_width = 4
                                           , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                                , syst_tag = syst_tag
                                                                                , sample_list = [ "202637.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_600"
                                                                                                ]
                                                                                )
                                           )
    ec_bl_700 = hh.Container.EntryContainer( label = 'B-L stop (700 GeV)'
                                           , line_color = ROOT.kYellow-2
                                           , line_width = 4
                                           , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                                , syst_tag = syst_tag
                                                                                , sample_list = [ "202638.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_700"
                                                                                                ]
                                                                                )
                                           )
    ec_bl_800 = hh.Container.EntryContainer( label = 'B-L stop (800 GeV)'
                                           , line_color = ROOT.kMagenta
                                           , line_width = 4
                                           , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                                , syst_tag = syst_tag
                                                                                , sample_list = [ "202639.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_800"
                                                                                                ]
                                                                                )
                                           )
    ec_bl_900 = hh.Container.EntryContainer( label = 'B-L stop (900 GeV)'
                                           , line_color = ROOT.kMagenta+4
                                           , line_width = 4
                                           , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                                , syst_tag = syst_tag
                                                                                , sample_list = [ "202640.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_900"
                                                                                                ]
                                                                                )
                                           )
    ec_bl_1000 = hh.Container.EntryContainer( label = 'B-L stop (1000 GeV)'
                                           , line_color = ROOT.kCyan+2
                                           , line_width = 4
                                           , input_file_list = constructFileList( hist_dir = hist_dir_mc
                                                                                , syst_tag = syst_tag
                                                                                , sample_list = [ "202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000"
                                                                                                ]
                                                                                )
                                           )

    return locals()
