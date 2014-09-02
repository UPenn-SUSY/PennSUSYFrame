#!/usr/bin/env python
# ==============================================================================
# = Script to take a list of optimize ntuple and make a new TFile which can be
# = read into HistFitter
# =
# = usage: python OptimizeToHistFitterNtuple.py
# ==============================================================================
import ROOT

# ------------------------------------------------------------------------------
def putTreeInFile(out_file, in_tree, sample_name):
    out_file.cd()
    print 'in tree: ' , in_tree
    new_tree = in_tree.Clone(sample_name)
    print 'new tree: ' , new_tree
    new_tree.Write()
    return new_tree

# ------------------------------------------------------------------------------
def writeTreesToHistFitterFile(out_file_name, optimize_tree_dict):
    out_file = ROOT.TFile(out_file_name, 'RECREATE')

    buffer_of_trees = []
    out_file.ls()
    for sample_name in optimize_tree_dict:
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        print 'adding sample: ', sample_name

        tree_list = ROOT.TList()
        for file_name in optimize_tree_dict[sample_name]:
            this_file = ROOT.TFile(file_name)
            this_tree = this_file.Get('optimize')
            tree_list.Add(this_tree)

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        out_file.cd()

        # new_tree = this_tree.CloneTree()
        new_tree = ROOT.TTree.MergeTrees(tree_list)
        new_tree.SetName(sample_name)
        new_tree.Write()

    out_file.Close()

# ------------------------------------------------------------------------------
def main():
    bkg_optimize_tree_dict = { 'ttbar_NoSys'     : [ '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.117050.PowhegPythia_P2011C_ttbar.af2_v2.ntup.root' ]
                             , 'SingleTop_NoSys' : [ '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.110141.PowhegPythia_P2011C_st_Wtchan_dilepton_DR.ntup.root' ]
                             , 'Z_NoSys'         : [ '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167749.Sherpa_CT10_ZeeMassiveCBPt0_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167752.Sherpa_CT10_ZmumuMassiveCBPt0_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167797.Sherpa_CT10_ZeeMassiveCBPt70_140_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167800.Sherpa_CT10_ZmumuMassiveCBPt70_140_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167809.Sherpa_CT10_ZeeMassiveCBPt140_280_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167812.Sherpa_CT10_ZmumuMassiveCBPt140_280_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167821.Sherpa_CT10_ZeeMassiveCBPt280_500_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167824.Sherpa_CT10_ZmumuMassiveCBPt280_500_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167833.Sherpa_CT10_ZeeMassiveCBPt500_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167836.Sherpa_CT10_ZmumuMassiveCBPt500_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.180543.Sherpa_CT10_ZeeMassiveCBPt40_70_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.180546.Sherpa_CT10_ZmumuMassiveCBPt40_70_BFilter.ntup.root'
                                                   ]
                             , 'data'            : [ '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodA_egamma.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodA_muon.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodB_egamma.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodB_muon.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodC_egamma.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodC_muon.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodD_egamma.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodD_muon.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodE_egamma.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodE_muon.ntup.root'
                                                   ]
                             }

    sig_optimize_tree_dict = { 'sig_100_NoSys' :['${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202632.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_100.ntup.root' ]
                             , 'sig_200_NoSys' :['${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202633.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_200.ntup.root' ]
                             , 'sig_300_NoSys' :['${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202634.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_300.ntup.root' ]
                             , 'sig_400_NoSys' :['${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202635.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_400.ntup.root' ]
                             , 'sig_500_NoSys' :['${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202636.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_500.ntup.root' ]
                             , 'sig_600_NoSys' :['${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202637.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_600.ntup.root' ]
                             , 'sig_700_NoSys' :['${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202638.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_700.ntup.root' ]
                             , 'sig_800_NoSys' :['${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202639.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_800.ntup.root' ]
                             , 'sig_900_NoSys' :['${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202640.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_900.ntup.root' ]
                             , 'sig_1000_NoSys':['${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000.ntup.root']
                             }

    writeTreesToHistFitterFile('BackgroundHistFitterTrees.root', bkg_optimize_tree_dict)
    writeTreesToHistFitterFile('SignalHistFitterTrees.root'    , sig_optimize_tree_dict)

# ==============================================================================
if __name__ == "__main__":
    main()

