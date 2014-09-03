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

        this_file = ROOT.TFile(optimize_tree_dict[sample_name])
        this_tree = this_file.Get('optimize')

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        out_file.cd()

        new_tree = this_tree.CloneTree()
        new_tree.SetName(sample_name)
        new_tree.Write()

    out_file.Close()

# ------------------------------------------------------------------------------
def main():
    optimize_tree_dict = { 'ttbar_NoSys'                     : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.117050.PowhegPythia_P2011C_ttbar.af2_v2.ntup.root'
                         , 'SingleTop_NoSys'                 : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.110141.PowhegPythia_P2011C_st_Wtchan_dilepton_DR.ntup.root'
                         , 'ZeeMassiveCBPt0_NoSys'           : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167749.Sherpa_CT10_ZeeMassiveCBPt0_BFilter.ntup.root'
                         , 'ZmumuMassiveCBPt0_NoSys'         : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167752.Sherpa_CT10_ZmumuMassiveCBPt0_BFilter.ntup.root'
                         , 'ZtautauMassiveCBPt0_NoSys'       : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167755.Sherpa_CT10_ZtautauMassiveCBPt0_BFilter.ntup.root'
                         , 'ZeeMassiveCBPt70_140_NoSys'      : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167797.Sherpa_CT10_ZeeMassiveCBPt70_140_BFilter.ntup.root'
                         , 'ZmumuMassiveCBPt70_140_NoSys'    : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167800.Sherpa_CT10_ZmumuMassiveCBPt70_140_BFilter.ntup.root'
                         , 'ZtautauMassiveCBPt70_140_NoSys'  : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167803.Sherpa_CT10_ZtautauMassiveCBPt70_140_BFilter.ntup.root'
                         , 'ZeeMassiveCBPt140_280_NoSys'     : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167809.Sherpa_CT10_ZeeMassiveCBPt140_280_BFilter.ntup.root'
                         , 'ZmumuMassiveCBPt140_280_NoSys'   : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167812.Sherpa_CT10_ZmumuMassiveCBPt140_280_BFilter.ntup.root'
                         , 'ZtautauMassiveCBPt140_280_NoSys' : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167815.Sherpa_CT10_ZtautauMassiveCBPt140_280_BFilter.ntup.root'
                         , 'ZeeMassiveCBPt280_500_NoSys'     : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167821.Sherpa_CT10_ZeeMassiveCBPt280_500_BFilter.ntup.root'
                         , 'ZmumuMassiveCBPt280_500_NoSys'   : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167824.Sherpa_CT10_ZmumuMassiveCBPt280_500_BFilter.ntup.root'
                         , 'ZtautauMassiveCBPt280_NoSys'     : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167827.Sherpa_CT10_ZtautauMassiveCBPt280_500_BFilter.ntup.root'
                         , 'ZeeMassiveCBPt500_NoSys'         : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167833.Sherpa_CT10_ZeeMassiveCBPt500_BFilter.ntup.root'
                         , 'ZmumuMassiveCBPt500_NoSys'       : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167836.Sherpa_CT10_ZmumuMassiveCBPt500_BFilter.ntup.root'
                         , 'ZtautauMassiveCBPt500_NoSys'     : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167839.Sherpa_CT10_ZtautauMassiveCBPt500_BFilter.ntup.root'
                         , 'ZeeMassiveCBPt40_70_NoSys'       : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.180543.Sherpa_CT10_ZeeMassiveCBPt40_70_BFilter.ntup.root'
                         , 'ZmumuMassiveCBPt40_70_NoSys'     : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.180546.Sherpa_CT10_ZmumuMassiveCBPt40_70_BFilter.ntup.root'
                         , 'ZtautauMassiveCBPt40_70_NoSys'   : '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.180549.Sherpa_CT10_ZtautauMassiveCBPt40_70_BFilter.ntup.root'

                         # , ' _NoSys':'${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202632.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_100.ntup.root'
                         # , ' _NoSys':'${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202633.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_200.ntup.root'
                         # , ' _NoSys':'${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202634.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_300.ntup.root'
                         # , ' _NoSys':'${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202635.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_400.ntup.root'
                         # , ' _NoSys':'${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202636.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_500.ntup.root'
                         # , ' _NoSys':'${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202637.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_600.ntup.root'
                         # , ' _NoSys':'${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202638.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_700.ntup.root'
                         # , ' _NoSys':'${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202639.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_800.ntup.root'
                         # , ' _NoSys':'${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202640.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_900.ntup.root'
                         # , ' _NoSys':'${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000.ntup.root'
                         }
    writeTreesToHistFitterFile('BackgroundHistFitterTrees.root', optimize_tree_dict)

# ==============================================================================
if __name__ == "__main__":
    main()
