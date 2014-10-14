#!/usr/bin/env python
# ==============================================================================
# = Usage: python OptimizeCuts.py
# ==============================================================================

# ------------------------------------------------------------------------------
import sys
import time
import getopt
import shutil

import ROOT
import ReadOptimization as ro

# ------------------------------------------------------------------------------
# print usage
def usage():
    print ''
    print 'Usage: python %s [options]' % sys.argv[0]

# ------------------------------------------------------------------------------
def readTMVAOutput(weight_file, tot_sig, tot_bkg):
    pass

# ------------------------------------------------------------------------------
def getExpEntriesInTree(in_tree):
    num_events = 0.
    for event in in_tree:
        num_events += event.weight

    return num_events

# ------------------------------------------------------------------------------
def doOptimize(f_name_sig, f_name_bkg_list, tag):
    out_file_name = "TMVA_opt.%s.root" % tag

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    output_file = ROOT.TFile( out_file_name, 'RECREATE')

    factory = ROOT.TMVA.Factory( 'TMVAClassification'
                               , output_file
                               , ( "!V"
                                 + ":!Silent"
                                 + ":Color"
                                 + ":DrawProgressBar"
                                 + ":Transformations=I;D;P;G,D"
                                 + ":AnalysisType=Classification"
                                 )
                               )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # adding variables to the classifier training

    # factory.AddVariable( "mbl_0"       , "mbl_0"       , 'GeV' , 'F' , 0 , 20.e3)
    # factory.AddVariable( "mbl_1"       , "mbl_1"       , 'GeV' , 'F' , 0 , 20.e3)
    # factory.AddVariable( "mbbll"       , "mbbll"       , 'GeV' , 'F')

    factory.AddVariable( "mbl_asym := (mbl_0-mbl_1)/(mbl_0+mbl_1)" , "mbl_asym" , '' , 'F')

    # factory.AddVariable( "ptbl_0"      , "ptbl_0"      , 'GeV' , 'F')
    # factory.AddVariable( "ptbl_1"      , "ptbl_1"      , 'GeV' , 'F')
    # factory.AddVariable( "ptbbll"      , "ptbbll"      , 'GeV' , 'F')

    # factory.AddVariable( "mll"         , "mll"         , 'GeV' , 'F')
    # factory.AddVariable( "ptll"        , "ptll"        , 'GeV' , 'F')

    # factory.AddVariable( "met_et"      , "met_et"      , 'GeV' , 'F')
    # factory.AddVariable( "met_rel"     , "met_rel"     , 'GeV' , 'F')

    # factory.AddVariable( "ht_all"      , "ht_all"      , 'GeV' , 'F')
    # factory.AddVariable( "ht_baseline" , "ht_baseline" , 'GeV' , 'F')
    # factory.AddVariable( "ht_good"     , "ht_good"     , 'GeV' , 'F')
    factory.AddVariable( "ht_signal"   , "ht_signal"   , 'GeV' , 'F')

    # factory.AddVariable( "met_sig_all      := met_et/sqrt(ht_all)"      , "met_sig_all"      , 'GeV^{1/2}' , 'F')
    # factory.AddVariable( "met_sig_baseline := met_et/sqrt(ht_baseline)" , "met_sig_baseline" , 'GeV^{1/2}' , 'F')
    # factory.AddVariable( "met_sig_good     := met_et/sqrt(ht_good)"     , "met_sig_good"     , 'GeV^{1/2}' , 'F')
    factory.AddVariable( "met_sig_signal   := met_et/sqrt(ht_signal)"   , "met_sig_signal"   , 'GeV^{1/2}' , 'F')

    # factory.AddVariable( "pt_l_0"      , "pt_l_0"      , 'GeV' , 'F')
    # factory.AddVariable( "pt_l_1"      , "pt_l_1"      , 'GeV' , 'F')
    # factory.AddVariable( "pt_b_0"      , "pt_b_0"      , 'GeV' , 'F')
    # factory.AddVariable( "pt_b_1"      , "pt_b_1"      , 'GeV' , 'F')

    # factory.AddVariable( "dphi_bl_0"   , "dphi_bl_0"   , ''    , 'F')
    # factory.AddVariable( "dphi_bl_1"   , "dphi_bl_1"   , ''    , 'F')
    # factory.AddVariable( "deta_bl_0"   , "deta_bl_0"   , ''    , 'F')
    # factory.AddVariable( "deta_bl_1"   , "deta_bl_1"   , ''    , 'F')
    # factory.AddVariable( "dr_bl_0"     , "dr_bl_0"     , ''    , 'F')
    # factory.AddVariable( "dr_bl_1"     , "dr_bl_1"     , ''    , 'F')

    # factory.AddVariable( "dphi_ll"     , "dphi_ll"     , ''    , 'F')
    # factory.AddVariable( "deta_ll"     , "deta_ll"     , ''    , 'F')
    # factory.AddVariable( "dr_ll"       , "dr_ll"       , ''    , 'F')

    # factory.AddVariable( "dphi_bb"     , "dphi_bb"     , ''    , 'F')
    # factory.AddVariable( "deta_bb"     , "deta_bb"     , ''    , 'F')
    # factory.AddVariable( "dr_bb"       , "dr_bb"       , ''    , 'F')

    # in_file = ROOT.TFile(in_file_name)
    # sig_tree = in_file.Get(tree_sig_name)
    # bkg_tree = [in_file.Get(name) for i, name in enumerate(tree_bkg_name)]
    # print bkg_tree

    # set background weight branch
    factory.SetWeightExpression('weight')

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # global weights to be applied to signal and backgruond samples
    sig_weight = 21000.
    bkg_weight = 21000.

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    in_file_sig = ROOT.TFile.Open(f_name_sig)
    in_tree_sig = in_file_sig.Get('optimize')
    factory.AddSignalTree(in_tree_sig, sig_weight)

    total_sig = sig_weight*getExpEntriesInTree(in_tree_sig)

    # in_file_bkg = ROOT.TFile.Open(f_name_bkg[0])
    # in_tree_bkg = in_file_bkg.Get('optimize')
    # factory.AddBackgroundTree(in_tree_bkg, bkg_weight)

    bkg_trees = []
    total_bkg = 0
    for fnb in f_name_bkg_list:
        in_file_bkg = ROOT.TFile.Open(fnb)
        in_tree_bkg = in_file_bkg.Get('optimize')
        bkg_trees.append(in_tree_bkg)
        factory.AddBackgroundTree(in_tree_bkg, bkg_weight)
        total_bkg += bkg_weight*getExpEntriesInTree(in_tree_bkg)

    print 'total signal events: '    , total_sig
    print 'total background events: ', total_bkg

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # prepare some cuts which are unused for now
    sig_cut = ROOT.TCut( '' )
    bkg_cut = ROOT.TCut( '' )
    factory.PrepareTrainingAndTestTree( sig_cut
                                      , bkg_cut
                                      , ( "nTrain_Signal=0"
                                        + ":nTrain_Background=0"
                                        + ":SplitMode=Random"
                                        + ":NormMode=NumEvents"
                                        + ":!V"
                                        )
                                      )

    # --------------------------------------------------------------------------
    # book optimization methods
    # --------------------------------------------------------------------------
    # cuts based optimization
    factory.BookMethod( ROOT.TMVA.Types.kCuts
                      , 'Cuts'
                      , ( "!H"
                        + ":!V"
                        # + ":FitMethod=MC"
                        # + ":SampleSize=2000"
                        # + ":SampleSize=200000"
                        + ":FitMethod=GA"
                        + ":EffSel"
                        + ":VarProp=FSmart"
                        )
                      )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    factory.TrainAllMethods()
    factory.TestAllMethods()
    factory.EvaluateAllMethods()
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    output_file.Close()

    shutil.move('weights', 'weights_%s' % tag)

    return {'total_sig':total_sig, 'total_bkg':total_bkg}

# ------------------------------------------------------------------------------
def main():
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # list of input files
    f_name_sig_list = [
                        '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202632.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_100.ntup.root'
                      , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202633.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_200.ntup.root'
                      , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202634.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_300.ntup.root'
                      , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202635.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_400.ntup.root'
                      , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202636.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_500.ntup.root'
                      , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202637.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_600.ntup.root'
                      , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202638.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_700.ntup.root'
                      , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202639.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_800.ntup.root'
                      , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202640.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_900.ntup.root'
                      , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000.ntup.root'
                      ]
    f_name_bkg_list = [ '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.117050.PowhegPythia_P2011C_ttbar.af2.ntup.root'
                      # , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.117050.PowhegPythia_P2011C_ttbar.af2.ntup.root'
                      ]

    results = []
    for i, fnsl in enumerate(f_name_sig_list):
        results.append(doOptimize( fnsl, f_name_bkg_list, i))

    print '==============================================================================='
    print '=================================== RESULTS ==================================='
    print '==============================================================================='
    print ''
    for it, r in enumerate(results):
        print '==============================================================================='
        print 'printing cut opt for sig ' , it
        print ''
        ro.readAndDisplayCutOpt( 'weights_%s/TMVAClassification_Cuts.weights.xml' % it
                               , r['total_sig']
                               , r['total_bkg']
                               , out_file_name = 'results_sig_%d.txt' % it
                               )
        print ''

# ==============================================================================
if __name__ == '__main__':
    main()

## ../../NextOptNtupDir.BMinusL/BMinusL.110101.AcerMCPythia_P2011CCTEQ6L1_singletop_tchan_l.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.110119.PowhegPythia_P2011C_st_schan_lep.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.110141.PowhegPythia_P2011C_st_Wtchan_dilepton_DR.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.161305.Pythia8_AU2CTEQ6L1_ttH125_WWinclusive.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167749.Sherpa_CT10_ZeeMassiveCBPt0_BFilter.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167750.Sherpa_CT10_ZeeMassiveCBPt0_CFilterBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167751.Sherpa_CT10_ZeeMassiveCBPt0_CVetoBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167752.Sherpa_CT10_ZmumuMassiveCBPt0_BFilter.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167753.Sherpa_CT10_ZmumuMassiveCBPt0_CFilterBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167754.Sherpa_CT10_ZmumuMassiveCBPt0_CVetoBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167755.Sherpa_CT10_ZtautauMassiveCBPt0_BFilter.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167756.Sherpa_CT10_ZtautauMassiveCBPt0_CFilterBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167757.Sherpa_CT10_ZtautauMassiveCBPt0_CVetoBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167797.Sherpa_CT10_ZeeMassiveCBPt70_140_BFilter.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167798.Sherpa_CT10_ZeeMassiveCBPt70_140_CFilterBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167799.Sherpa_CT10_ZeeMassiveCBPt70_140_CVetoBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167800.Sherpa_CT10_ZmumuMassiveCBPt70_140_BFilter.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167801.Sherpa_CT10_ZmumuMassiveCBPt70_140_CFilterBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167802.Sherpa_CT10_ZmumuMassiveCBPt70_140_CVetoBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167803.Sherpa_CT10_ZtautauMassiveCBPt70_140_BFilter.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167804.Sherpa_CT10_ZtautauMassiveCBPt70_140_CFilterBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167805.Sherpa_CT10_ZtautauMassiveCBPt70_140_CVetoBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167809.Sherpa_CT10_ZeeMassiveCBPt140_280_BFilter.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167810.Sherpa_CT10_ZeeMassiveCBPt140_280_CFilterBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167811.Sherpa_CT10_ZeeMassiveCBPt140_280_CVetoBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167812.Sherpa_CT10_ZmumuMassiveCBPt140_280_BFilter.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167813.Sherpa_CT10_ZmumuMassiveCBPt140_280_CFilterBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167814.Sherpa_CT10_ZmumuMassiveCBPt140_280_CVetoBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167815.Sherpa_CT10_ZtautauMassiveCBPt140_280_BFilter.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167816.Sherpa_CT10_ZtautauMassiveCBPt140_280_CFilterBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167817.Sherpa_CT10_ZtautauMassiveCBPt140_280_CVetoBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167821.Sherpa_CT10_ZeeMassiveCBPt280_500_BFilter.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167822.Sherpa_CT10_ZeeMassiveCBPt280_500_CFilterBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167823.Sherpa_CT10_ZeeMassiveCBPt280_500_CVetoBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167824.Sherpa_CT10_ZmumuMassiveCBPt280_500_BFilter.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167825.Sherpa_CT10_ZmumuMassiveCBPt280_500_CFilterBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167826.Sherpa_CT10_ZmumuMassiveCBPt280_500_CVetoBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167827.Sherpa_CT10_ZtautauMassiveCBPt280_500_BFilter.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167828.Sherpa_CT10_ZtautauMassiveCBPt280_500_CFilterBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167829.Sherpa_CT10_ZtautauMassiveCBPt280_500_CVetoBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167833.Sherpa_CT10_ZeeMassiveCBPt500_BFilter.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167834.Sherpa_CT10_ZeeMassiveCBPt500_CFilterBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167835.Sherpa_CT10_ZeeMassiveCBPt500_CVetoBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167836.Sherpa_CT10_ZmumuMassiveCBPt500_BFilter.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167837.Sherpa_CT10_ZmumuMassiveCBPt500_CFilterBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167838.Sherpa_CT10_ZmumuMassiveCBPt500_CVetoBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167839.Sherpa_CT10_ZtautauMassiveCBPt500_BFilter.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167840.Sherpa_CT10_ZtautauMassiveCBPt500_CFilterBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.167841.Sherpa_CT10_ZtautauMassiveCBPt500_CVetoBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.173041.Sherpa_CT10_DYeeM08to15.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.173042.Sherpa_CT10_DYeeM15to40.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.173043.Sherpa_CT10_DYmumuM08to15.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.173044.Sherpa_CT10_DYmumuM15to40.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.173045.Sherpa_CT10_DYtautauM08to15.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.173046.Sherpa_CT10_DYtautauM15to40.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.177997.Sherpa_CT10_llnunu_WW_MassiveCB.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.177999.Sherpa_CT10_llnunu_ZZ_MassiveCB.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.179974.Sherpa_CT10_lllnu_WZ_MassiveCB.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.179975.Sherpa_CT10_lnununu_WZ_MassiveCB.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.180543.Sherpa_CT10_ZeeMassiveCBPt40_70_BFilter.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.180544.Sherpa_CT10_ZeeMassiveCBPt40_70_CFilterBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.180545.Sherpa_CT10_ZeeMassiveCBPt40_70_CVetoBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.180546.Sherpa_CT10_ZmumuMassiveCBPt40_70_BFilter.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.180547.Sherpa_CT10_ZmumuMassiveCBPt40_70_CFilterBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.180548.Sherpa_CT10_ZmumuMassiveCBPt40_70_CVetoBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.180549.Sherpa_CT10_ZtautauMassiveCBPt40_70_BFilter.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.180550.Sherpa_CT10_ZtautauMassiveCBPt40_70_CFilterBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.180551.Sherpa_CT10_ZtautauMassiveCBPt40_70_CVetoBVeto.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.183585.Sherpa_CT10_ZWtoeeqq_MassiveCB.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.183586.Sherpa_CT10_ZZtoeeqq_MassiveCB.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.183587.Sherpa_CT10_ZWtomumuqq_MassiveCB.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.183588.Sherpa_CT10_ZZtomumuqq_MassiveCB.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.183589.Sherpa_CT10_ZWtotautauqq_MassiveCB.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.183590.Sherpa_CT10_ZZtotautauqq_MassiveCB.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.183591.Sherpa_CT10_ZWtonunuqq_MassiveCB.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.183592.Sherpa_CT10_ZZtonunuqq_MassiveCB.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.183734.Sherpa_CT10_WWtoenuqq_MassiveCB.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.183735.Sherpa_CT10_WZtoenuqq_MassiveCB.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.183736.Sherpa_CT10_WWtomunuqq_MassiveCB.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.183737.Sherpa_CT10_WZtomunuqq_MassiveCB.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.183738.Sherpa_CT10_WWtotaunuqq_MassiveCB.ntup.root
## ../../NextOptNtupDir.BMinusL/BMinusL.183739.Sherpa_CT10_WZtotaunuqq_MassiveCB.ntup.root
