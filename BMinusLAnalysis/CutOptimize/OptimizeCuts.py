#!/usr/bin/env python

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
    factory.AddVariable( "ht_baseline" , "ht_baseline" , 'GeV' , 'F')
    # factory.AddVariable( "ht_good"     , "ht_good"     , 'GeV' , 'F')
    # factory.AddVariable( "ht_signal"   , "ht_signal"   , 'GeV' , 'F')

    # factory.AddVariable( "met_sig_all      := met_et/sqrt(ht_all)"      , "met_sig_all"      , '' , 'F')
    factory.AddVariable( "met_sig_baseline := met_et/sqrt(ht_baseline)" , "met_sig_baseline" , '' , 'F')
    # factory.AddVariable( "met_sig_good     := met_et/sqrt(ht_good)"     , "met_sig_good"     , '' , 'F')
    # factory.AddVariable( "met_sig_signal   := met_et/sqrt(ht_signal)"   , "met_sig_signal"   , '' , 'F')

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
    f_name_bkg_list = [ '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.117050.PowhegPythia_P2011C_ttbar.ntup.root' ]

    results = []
    for i, fnsl in enumerate(f_name_sig_list):
        # results.append(doOptimize( f_name_sig_list[0], f_name_bkg_list, i))
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
                               )
        print ''

# ==============================================================================
if __name__ == '__main__':
    main()
