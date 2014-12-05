# ------------------------------------------------------------------------------
def getEgammaDataSamples(job_multiplier = 1, test_subset = False):
    """
    Get dictionary of egamma data samples
    job_multiplier: Multiplier for splitting the samples into fewer jobs
    test_subset: Only return a dcitionary with a single test sample
    """
    samples = {'periodA_egamma':{'label':'periodA_egamma', 'num_jobs':1*job_multiplier}}

    if not test_subset:
        samples['periodB_egamma'] = {'label':'periodB_egamma', 'num_jobs':1*job_multiplier}
        samples['periodC_egamma'] = {'label':'periodC_egamma', 'num_jobs':1*job_multiplier}
        samples['periodD_egamma'] = {'label':'periodD_egamma', 'num_jobs':1*job_multiplier}
        samples['periodE_egamma'] = {'label':'periodE_egamma', 'num_jobs':1*job_multiplier}
        samples['periodG_egamma'] = {'label':'periodG_egamma', 'num_jobs':1*job_multiplier}
        samples['periodH_egamma'] = {'label':'periodH_egamma', 'num_jobs':1*job_multiplier}
        samples['periodI_egamma'] = {'label':'periodI_egamma', 'num_jobs':1*job_multiplier}
        samples['periodJ_egamma'] = {'label':'periodJ_egamma', 'num_jobs':1*job_multiplier}
        samples['periodL_egamma'] = {'label':'periodL_egamma', 'num_jobs':1*job_multiplier}

    return samples

# ------------------------------------------------------------------------------
def getMuonDataSamples(job_multiplier = 1, test_subset = False):
    """
    Get dictionary of muon data samples
    job_multiplier: Multiplier for splitting the samples into fewer jobs
    test_subset: Only return a dcitionary with a single test sample
    """
    samples = {'periodA_muon':{'label':'periodA_muon', 'num_jobs':1*job_multiplier}}

    if not test_subset:
        samples['periodB_muon'] = {'label':'periodB_muon', 'num_jobs':1*job_multiplier}
        samples['periodC_muon'] = {'label':'periodC_muon', 'num_jobs':1*job_multiplier}
        samples['periodD_muon'] = {'label':'periodD_muon', 'num_jobs':1*job_multiplier}
        samples['periodE_muon'] = {'label':'periodE_muon', 'num_jobs':1*job_multiplier}
        samples['periodG_muon'] = {'label':'periodG_muon', 'num_jobs':1*job_multiplier}
        samples['periodH_muon'] = {'label':'periodH_muon', 'num_jobs':1*job_multiplier}
        samples['periodI_muon'] = {'label':'periodI_muon', 'num_jobs':1*job_multiplier}
        samples['periodJ_muon'] = {'label':'periodJ_muon', 'num_jobs':1*job_multiplier}
        samples['periodL_muon'] = {'label':'periodL_muon', 'num_jobs':1*job_multiplier}

    return samples

# ------------------------------------------------------------------------------
def getFullSimSamples(job_multiplier = 1, test_subset = False):
    """
    Get dictionary of full sim samples
    job_multiplier: Multiplier for splitting the samples into fewer jobs
    test_subset: Only return a dcitionary with a single test sample
    """
    samples = {119353:{'label':'119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW'   , 'num_jobs':1}}

    if not test_subset:
        samples[119354] = {'label':'119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj'  , 'num_jobs':1}
        samples[119355] = {'label':'119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ'   , 'num_jobs':1}
        samples[119356] = {'label':'119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj'  , 'num_jobs':1}
        samples[119583] = {'label':'119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW' , 'num_jobs':1}

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        samples[173045] = {'label':'173045.Sherpa_CT10_DYtautauM08to15' , 'num_jobs':1}
        samples[173046] = {'label':'173046.Sherpa_CT10_DYtautauM15to40' , 'num_jobs':1}

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        samplpe[160655] = {'label':'160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu'        , 'num_jobs':1}
        samplpe[160705] = {'label':'160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu'       , 'num_jobs':1}
        samplpe[160755] = {'label':'160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu'            , 'num_jobs':1}
        samplpe[160805] = {'label':'160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu'            , 'num_jobs':1}
        samplpe[161005] = {'label':'161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5'  , 'num_jobs':1}
        samplpe[161055] = {'label':'161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5' , 'num_jobs':1}
        samplpe[161105] = {'label':'161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep'              , 'num_jobs':1}
        samplpe[161155] = {'label':'161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep'              , 'num_jobs':1}
        samplpe[161305] = {'label':'161305.Pythia8_AU2CTEQ6L1_ttH125_WWinclusive'        , 'num_jobs':1}

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ## samples[105200] = {'label':'105200.McAtNloJimmy_CT10_ttbar_LeptonFilter' , 'num_jobs':2*job_multiplier}

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        samples[177997] = {'label':'177997.Sherpa_CT10_llnunu_WW_MassiveCB'      , 'num_jobs':1*job_multiplier}
        samples[177999] = {'label':'177999.Sherpa_CT10_llnunu_ZZ_MassiveCB'      , 'num_jobs':1*job_multiplier}
        samples[179974] = {'label':'179974.Sherpa_CT10_lllnu_WZ_MassiveCB'       , 'num_jobs':1*job_multiplier}
        samples[179975] = {'label':'179975.Sherpa_CT10_lnununu_WZ_MassiveCB'     , 'num_jobs':1*job_multiplier}

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        samples[183589] = {'label':'183589.Sherpa_CT10_ZWtotautauqq_MassiveCB' , 'num_jobs':1*job_multiplier}
        samples[183590] = {'label':'183590.Sherpa_CT10_ZZtotautauqq_MassiveCB' , 'num_jobs':1*job_multiplier}
        samples[183591] = {'label':'183591.Sherpa_CT10_ZWtonunuqq_MassiveCB'   , 'num_jobs':1*job_multiplier}
        samples[183592] = {'label':'183592.Sherpa_CT10_ZZtonunuqq_MassiveCB'   , 'num_jobs':1*job_multiplier}

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        ## samples[200332] = {'label':'200332.AlpgenPythia_Auto_P2011C_ZeebbNp0'         , 'num_jobs':1*job_multiplier}
        ## samples[200333] = {'label':'200333.AlpgenPythia_Auto_P2011C_ZeebbNp1'         , 'num_jobs':1*job_multiplier}
        ## samples[200334] = {'label':'200334.AlpgenPythia_Auto_P2011C_ZeebbNp2'         , 'num_jobs':1*job_multiplier}
        ## samples[200335] = {'label':'200335.AlpgenPythia_Auto_P2011C_ZeebbNp3incl'     , 'num_jobs':1*job_multiplier}
        ## samples[200340] = {'label':'200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0'       , 'num_jobs':1*job_multiplier}
        ## samples[200341] = {'label':'200341.AlpgenPythia_Auto_P2011C_ZmumubbNp1'       , 'num_jobs':1*job_multiplier}
        ## samples[200342] = {'label':'200342.AlpgenPythia_Auto_P2011C_ZmumubbNp2'       , 'num_jobs':1*job_multiplier}
        ## samples[200343] = {'label':'200343.AlpgenPythia_Auto_P2011C_ZmumubbNp3incl'   , 'num_jobs':1*job_multiplier}
        ## samples[200348] = {'label':'200348.AlpgenPythia_Auto_P2011C_ZtautaubbNp0'     , 'num_jobs':1*job_multiplier}
        ## samples[200349] = {'label':'200349.AlpgenPythia_Auto_P2011C_ZtautaubbNp1'     , 'num_jobs':1*job_multiplier}
        ## samples[200350] = {'label':'200350.AlpgenPythia_Auto_P2011C_ZtautaubbNp2'     , 'num_jobs':1*job_multiplier}
        ## samples[200351] = {'label':'200351.AlpgenPythia_Auto_P2011C_ZtautaubbNp3incl' , 'num_jobs':1*job_multiplier}

    return sample

# ------------------------------------------------------------------------------
def getFastSimSamples( job_multiplier = 1
                     , test_subset = False
                     , signal_only = False
                     ):
    """
    Get dictionary of fast sim samples
    job_multiplier: Multiplier for splitting the samples into fewer jobs
    test_subset: Only return a dcitionary with a single test sample
    signal_only: Return a dictionary only containing signal samples
    """
    sample = {202641:{'label':'202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000' , 'num_jobs':1}}

    if not test_subset:
            samples[202632] = {'label':'202632.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_100'  , 'num_jobs':1}
            samples[202633] = {'label':'202633.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_200'  , 'num_jobs':1}
            samples[202634] = {'label':'202634.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_300'  , 'num_jobs':1}
            samples[202635] = {'label':'202635.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_400'  , 'num_jobs':1}
            samples[202636] = {'label':'202636.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_500'  , 'num_jobs':1}
            samples[202637] = {'label':'202637.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_600'  , 'num_jobs':1}
            samples[202638] = {'label':'202638.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_700'  , 'num_jobs':1}
            samples[202639] = {'label':'202639.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_800'  , 'num_jobs':1}
            samples[202640] = {'label':'202640.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_900'  , 'num_jobs':1}

    if not test_subset and not signal_only:
        samples[117050] = {'label':'117050.PowhegPythia_P2011C_ttbar.af2', 'num_jobs':10*job_multiplier}

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        samples[110141] = {'label':'110141.PowhegPythia_P2011C_st_Wtchan_dilepton_DR'          , 'num_jobs':2*job_multiplier}
        samples[110101] = {'label':'110101.AcerMCPythia_P2011CCTEQ6L1_singletop_tchan_l'       , 'num_jobs':1*job_multiplier}
        samples[110119] = {'label':'110119.PowhegPythia_P2011C_st_schan_lep'                   , 'num_jobs':1*job_multiplier}

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        samples[167749] = {'label':'167749.Sherpa_CT10_ZeeMassiveCBPt0_BFilter'                , 'num_jobs':4*job_multiplier}
        samples[167750] = {'label':'167750.Sherpa_CT10_ZeeMassiveCBPt0_CFilterBVeto'           , 'num_jobs':4*job_multiplier}
        samples[167751] = {'label':'167751.Sherpa_CT10_ZeeMassiveCBPt0_CVetoBVeto'             , 'num_jobs':4*job_multiplier}

        samples[167752] = {'label':'167752.Sherpa_CT10_ZmumuMassiveCBPt0_BFilter'              , 'num_jobs':4*job_multiplier}
        samples[167753] = {'label':'167753.Sherpa_CT10_ZmumuMassiveCBPt0_CFilterBVeto'         , 'num_jobs':4*job_multiplier}
        samples[167754] = {'label':'167754.Sherpa_CT10_ZmumuMassiveCBPt0_CVetoBVeto'           , 'num_jobs':4*job_multiplier}

        samples[167755] = {'label':'167755.Sherpa_CT10_ZtautauMassiveCBPt0_BFilter'            , 'num_jobs':1}
        samples[167756] = {'label':'167756.Sherpa_CT10_ZtautauMassiveCBPt0_CFilterBVeto'       , 'num_jobs':1}
        samples[167757] = {'label':'167757.Sherpa_CT10_ZtautauMassiveCBPt0_CVetoBVeto'         , 'num_jobs':1}

        samples[167797] = {'label':'167797.Sherpa_CT10_ZeeMassiveCBPt70_140_BFilter'           , 'num_jobs':2*job_multiplier}
        samples[167798] = {'label':'167798.Sherpa_CT10_ZeeMassiveCBPt70_140_CFilterBVeto'      , 'num_jobs':2*job_multiplier}
        samples[167799] = {'label':'167799.Sherpa_CT10_ZeeMassiveCBPt70_140_CVetoBVeto'        , 'num_jobs':2*job_multiplier}

        samples[167800] = {'label':'167800.Sherpa_CT10_ZmumuMassiveCBPt70_140_BFilter'         , 'num_jobs':2*job_multiplier}
        samples[167801] = {'label':'167801.Sherpa_CT10_ZmumuMassiveCBPt70_140_CFilterBVeto'    , 'num_jobs':2*job_multiplier}
        samples[167802] = {'label':'167802.Sherpa_CT10_ZmumuMassiveCBPt70_140_CVetoBVeto'      , 'num_jobs':2*job_multiplier}

        samples[167803] = {'label':'167803.Sherpa_CT10_ZtautauMassiveCBPt70_140_BFilter'       , 'num_jobs':1}
        samples[167804] = {'label':'167804.Sherpa_CT10_ZtautauMassiveCBPt70_140_CFilterBVeto'  , 'num_jobs':1}
        samples[167805] = {'label':'167805.Sherpa_CT10_ZtautauMassiveCBPt70_140_CVetoBVeto'    , 'num_jobs':1}

        samples[167809] = {'label':'167809.Sherpa_CT10_ZeeMassiveCBPt140_280_BFilter'          , 'num_jobs':1*job_multiplier
        samples[167810] = {'label':'167810.Sherpa_CT10_ZeeMassiveCBPt140_280_CFilterBVeto'     , 'num_jobs':1*job_multiplier
        samples[167811] = {'label':'167811.Sherpa_CT10_ZeeMassiveCBPt140_280_CVetoBVeto'       , 'num_jobs':1*job_multiplier

        samples[167812] = {'label':'167812.Sherpa_CT10_ZmumuMassiveCBPt140_280_BFilter'        , 'num_jobs':1*job_multiplier}
        samples[167813] = {'label':'167813.Sherpa_CT10_ZmumuMassiveCBPt140_280_CFilterBVeto'   , 'num_jobs':1*job_multiplier}
        samples[167814] = {'label':'167814.Sherpa_CT10_ZmumuMassiveCBPt140_280_CVetoBVeto'     , 'num_jobs':1*job_multiplier}

        samples[167815] = {'label':'167815.Sherpa_CT10_ZtautauMassiveCBPt140_280_BFilter'      , 'num_jobs':1}
        samples[167816] = {'label':'167816.Sherpa_CT10_ZtautauMassiveCBPt140_280_CFilterBVeto' , 'num_jobs':1}
        samples[167817] = {'label':'167817.Sherpa_CT10_ZtautauMassiveCBPt140_280_CVetoBVeto'   , 'num_jobs':1}

        samples[167821] = {'label':'167821.Sherpa_CT10_ZeeMassiveCBPt280_500_BFilter'          , 'num_jobs':1*job_multiplier}
        samples[167822] = {'label':'167822.Sherpa_CT10_ZeeMassiveCBPt280_500_CFilterBVeto'     , 'num_jobs':1*job_multiplier}
        samples[167823] = {'label':'167823.Sherpa_CT10_ZeeMassiveCBPt280_500_CVetoBVeto'       , 'num_jobs':1*job_multiplier}

        samples[167824] = {'label':'167824.Sherpa_CT10_ZmumuMassiveCBPt280_500_BFilter'        , 'num_jobs':1*job_multiplier}
        samples[167825] = {'label':'167825.Sherpa_CT10_ZmumuMassiveCBPt280_500_CFilterBVeto'   , 'num_jobs':1*job_multiplier}
        samples[167826] = {'label':'167826.Sherpa_CT10_ZmumuMassiveCBPt280_500_CVetoBVeto'     , 'num_jobs':1*job_multiplier}

        samples[167827] = {'label':'167827.Sherpa_CT10_ZtautauMassiveCBPt280_500_BFilter'      , 'num_jobs':1}
        samples[167828] = {'label':'167828.Sherpa_CT10_ZtautauMassiveCBPt280_500_CFilterBVeto' , 'num_jobs':1}
        samples[167829] = {'label':'167829.Sherpa_CT10_ZtautauMassiveCBPt280_500_CVetoBVeto'   , 'num_jobs':1}

        samples[167833] = {'label':'167833.Sherpa_CT10_ZeeMassiveCBPt500_BFilter'              , 'num_jobs':3}
        samples[167834] = {'label':'167834.Sherpa_CT10_ZeeMassiveCBPt500_CFilterBVeto'         , 'num_jobs':3}
        samples[167835] = {'label':'167835.Sherpa_CT10_ZeeMassiveCBPt500_CVetoBVeto'           , 'num_jobs':3}

        samples[167836] = {'label':'167836.Sherpa_CT10_ZmumuMassiveCBPt500_BFilter'            , 'num_jobs':1*job_multiplier}
        samples[167837] = {'label':'167837.Sherpa_CT10_ZmumuMassiveCBPt500_CFilterBVeto'       , 'num_jobs':1*job_multiplier}
        samples[167838] = {'label':'167838.Sherpa_CT10_ZmumuMassiveCBPt500_CVetoBVeto'         , 'num_jobs':1*job_multiplier}

        samples[167839] = {'label':'167839.Sherpa_CT10_ZtautauMassiveCBPt500_BFilter'          , 'num_jobs':1}
        samples[167840] = {'label':'167840.Sherpa_CT10_ZtautauMassiveCBPt500_CFilterBVeto'     , 'num_jobs':1}
        samples[167841] = {'label':'167841.Sherpa_CT10_ZtautauMassiveCBPt500_CVetoBVeto'       , 'num_jobs':1}

        samples[180543] = {'label':'180543.Sherpa_CT10_ZeeMassiveCBPt40_70_BFilter'            , 'num_jobs':2*job_multiplier}
        samples[180544] = {'label':'180544.Sherpa_CT10_ZeeMassiveCBPt40_70_CFilterBVeto'       , 'num_jobs':2*job_multiplier}
        samples[180545] = {'label':'180545.Sherpa_CT10_ZeeMassiveCBPt40_70_CVetoBVeto'         , 'num_jobs':2*job_multiplier}

        samples[180546] = {'label':'180546.Sherpa_CT10_ZmumuMassiveCBPt40_70_BFilter'          , 'num_jobs':2*job_multiplier}
        samples[180547] = {'label':'180547.Sherpa_CT10_ZmumuMassiveCBPt40_70_CFilterBVeto'     , 'num_jobs':2*job_multiplier}
        samples[180548] = {'label':'180548.Sherpa_CT10_ZmumuMassiveCBPt40_70_CVetoBVeto'       , 'num_jobs':2*job_multiplier}

        samples[180549] = {'label':'180549.Sherpa_CT10_ZtautauMassiveCBPt40_70_BFilter'        , 'num_jobs':1}
        samples[180550] = {'label':'180550.Sherpa_CT10_ZtautauMassiveCBPt40_70_CFilterBVeto'   , 'num_jobs':1}
        samples[180551] = {'label':'180551.Sherpa_CT10_ZtautauMassiveCBPt40_70_CVetoBVeto'     , 'num_jobs':1}

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        samples[173041] = {'label':'173041.Sherpa_CT10_DYeeM08to15'     , 'num_jobs':1*job_multiplier}
        samples[173042] = {'label':'173042.Sherpa_CT10_DYeeM15to40'     , 'num_jobs':1*job_multiplier}

        samples[173043] = {'label':'173043.Sherpa_CT10_DYmumuM08to15'   , 'num_jobs':1*job_multiplier}
        samples[173044] = {'label':'173044.Sherpa_CT10_DYmumuM15to40'   , 'num_jobs':1*job_multiplier}

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        samples[183585] = {'label':'183585.Sherpa_CT10_ZWtoeeqq_MassiveCB'    , 'num_jobs':1}
        samples[183586] = {'label':'183586.Sherpa_CT10_ZZtoeeqq_MassiveCB'    , 'num_jobs':1}
        samples[183587] = {'label':'183587.Sherpa_CT10_ZWtomumuqq_MassiveCB'  , 'num_jobs':1}
        samples[183588] = {'label':'183588.Sherpa_CT10_ZZtomumuqq_MassiveCB'  , 'num_jobs':1}
        samples[183734] = {'label':'183734.Sherpa_CT10_WWtoenuqq_MassiveCB'   , 'num_jobs':1}
        samples[183735] = {'label':'183735.Sherpa_CT10_WZtoenuqq_MassiveCB'   , 'num_jobs':1}
        samples[183736] = {'label':'183736.Sherpa_CT10_WWtomunuqq_MassiveCB'  , 'num_jobs':1}
        samples[183737] = {'label':'183737.Sherpa_CT10_WZtomunuqq_MassiveCB'  , 'num_jobs':1}
        samples[183738] = {'label':'183738.Sherpa_CT10_WWtotaunuqq_MassiveCB' , 'num_jobs':1}
        samples[183739] = {'label':'183739.Sherpa_CT10_WZtotaunuqq_MassiveCB' , 'num_jobs':1}

    return sample
