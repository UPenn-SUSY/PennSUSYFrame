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

        # ROOT is the worst...
        # We want to take the "optimize" tree from each file, and add it to a
        # TList which will ultimately be merged into a final file
        # First need to loop through the files and get and rename the trees
        # Also need to keep track of the files because root gets confused if the
        # TFiles go out of scope
        tmp_file_list = []
        tmp_tree_list = []
        for i, file_name in enumerate(optimize_tree_dict[sample_name]):
            print 'getting file: ', file_name
            this_file = ROOT.TFile(file_name)
            this_tree = this_file.Get('optimize')
            this_tree.SetName('optimize_%s' % i)
            tmp_file_list.append(this_file)
            tmp_tree_list.append(this_tree)

        # Now, loop over the trees, and add them to our TList
        final_tree_list = ROOT.TList()
        for ttl in tmp_tree_list:
            final_tree_list.Add(ttl)

        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        out_file.cd()

        # Print the number of entries per tree to make sure trees are being
        # added correctly
        print 'tree sizes!'
        for ftl in final_tree_list:
            print ftl.GetName() , ' -- entries: ' , ftl.GetEntries()

        # finally merge trees
        new_tree = ROOT.TTree.MergeTrees(final_tree_list)
        new_tree.SetName(sample_name)

        # more printing to make sure the trees are added correctly
        print 'new tree: ' , new_tree.GetEntries()
        print ''

        # write to file
        new_tree.Write()

    out_file.Close()

# ------------------------------------------------------------------------------
def main():
    bkg_optimize_tree_dict = { 'ttbar_NoSys'     : [ '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.117050.PowhegPythia_P2011C_ttbar.af2_v2.ntup.root' ]
                             , 'SingleTop_NoSys' : [ '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.110101.AcerMCPythia_P2011CCTEQ6L1_singletop_tchan_l.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.110119.PowhegPythia_P2011C_st_schan_lep.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.110141.PowhegPythia_P2011C_st_Wtchan_dilepton_DR.ntup.root'
                                                   ]
                             , 'Z_NoSys'         : [ '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167749.Sherpa_CT10_ZeeMassiveCBPt0_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167750.Sherpa_CT10_ZeeMassiveCBPt0_CFilterBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167751.Sherpa_CT10_ZeeMassiveCBPt0_CVetoBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167752.Sherpa_CT10_ZmumuMassiveCBPt0_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167753.Sherpa_CT10_ZmumuMassiveCBPt0_CFilterBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167754.Sherpa_CT10_ZmumuMassiveCBPt0_CVetoBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167797.Sherpa_CT10_ZeeMassiveCBPt70_140_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167798.Sherpa_CT10_ZeeMassiveCBPt70_140_CFilterBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167799.Sherpa_CT10_ZeeMassiveCBPt70_140_CVetoBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167800.Sherpa_CT10_ZmumuMassiveCBPt70_140_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167801.Sherpa_CT10_ZmumuMassiveCBPt70_140_CFilterBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167802.Sherpa_CT10_ZmumuMassiveCBPt70_140_CVetoBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167809.Sherpa_CT10_ZeeMassiveCBPt140_280_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167810.Sherpa_CT10_ZeeMassiveCBPt140_280_CFilterBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167811.Sherpa_CT10_ZeeMassiveCBPt140_280_CVetoBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167812.Sherpa_CT10_ZmumuMassiveCBPt140_280_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167813.Sherpa_CT10_ZmumuMassiveCBPt140_280_CFilterBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167814.Sherpa_CT10_ZmumuMassiveCBPt140_280_CVetoBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167821.Sherpa_CT10_ZeeMassiveCBPt280_500_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167822.Sherpa_CT10_ZeeMassiveCBPt280_500_CFilterBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167823.Sherpa_CT10_ZeeMassiveCBPt280_500_CVetoBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167824.Sherpa_CT10_ZmumuMassiveCBPt280_500_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167825.Sherpa_CT10_ZmumuMassiveCBPt280_500_CFilterBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167826.Sherpa_CT10_ZmumuMassiveCBPt280_500_CVetoBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167833.Sherpa_CT10_ZeeMassiveCBPt500_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167834.Sherpa_CT10_ZeeMassiveCBPt500_CFilterBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167835.Sherpa_CT10_ZeeMassiveCBPt500_CVetoBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167836.Sherpa_CT10_ZmumuMassiveCBPt500_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167837.Sherpa_CT10_ZmumuMassiveCBPt500_CFilterBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.167838.Sherpa_CT10_ZmumuMassiveCBPt500_CVetoBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.180543.Sherpa_CT10_ZeeMassiveCBPt40_70_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.180544.Sherpa_CT10_ZeeMassiveCBPt40_70_CFilterBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.180545.Sherpa_CT10_ZeeMassiveCBPt40_70_CVetoBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.180546.Sherpa_CT10_ZmumuMassiveCBPt40_70_BFilter.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.180547.Sherpa_CT10_ZmumuMassiveCBPt40_70_CFilterBVeto.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.180548.Sherpa_CT10_ZmumuMassiveCBPt40_70_CVetoBVeto.ntup.root'
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
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodG_egamma.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodG_muon.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodH_egamma.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodH_muon.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodI_egamma.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodI_muon.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodJ_egamma.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodJ_muon.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodL_egamma.ntup.root'
                                                   , '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/BMinusL.periodL_muon.ntup.root'
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

# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.161305.Pythia8_AU2CTEQ6L1_ttH125_WWinclusive.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.173041.Sherpa_CT10_DYeeM08to15.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.173042.Sherpa_CT10_DYeeM15to40.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.173043.Sherpa_CT10_DYmumuM08to15.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.173044.Sherpa_CT10_DYmumuM15to40.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.173045.Sherpa_CT10_DYtautauM08to15.ntup.root
# ${BASE_WORK_DIR}//NextOptNtupDir.BMinusL/BMinusL.173046.Sherpa_CT10_DYtautauM15to40.ntup.root
# 
