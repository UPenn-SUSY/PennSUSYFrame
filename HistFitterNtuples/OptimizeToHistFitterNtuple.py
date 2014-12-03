#!/usr/bin/env python
# ==============================================================================
# = Script to take a list of optimize ntuple and make a new TFile which can be
# = read into HistFitter
# =
# = usage: python OptimizeToHistFitterNtuple.py
# ==============================================================================
import os
import glob
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
def writeSingleSampleToTmpFile( out_file_name
                              , sample_name
                              , optimize_tree_entry
                              , cut_str = ''
                              , tree_name = 'hft'
                              ):
    out_file = ROOT.TFile('tmp__%s' % out_file_name, 'RECREATE')

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
    for i, file_name in enumerate(optimize_tree_entry):
        print 'getting file: ', file_name
        this_file = ROOT.TFile(file_name)
        this_tree = this_file.Get('optimize')
        this_tree.SetName('optimize_%s' % i)
        tmp_file_list.append(this_file)

        if cut_str != '':
            out_file.cd()
            this_tree = this_tree.CopyTree(cut_str)
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
    new_tree.SetName(tree_name)

    # more printing to make sure the trees are added correctly
    print 'new tree: ' , new_tree.GetEntries()
    print ''

    # write to file
    new_tree.Write()
    out_file.Close()

# ------------------------------------------------------------------------------
def mergeTmpTreesToOutput( out_file_name
                         , list_of_tmp_trees
                         ):
    out_file = ROOT.TFile(out_file_name, 'RECREATE')

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # ROOT is the worst...
    # We want to take the "optimize" tree from each file, and add it to a
    # TList which will ultimately be merged into a final file
    # First need to loop through the files and get and rename the trees
    # Also need to keep track of the files because root gets confused if the
    # TFiles go out of scope
    tmp_file_list = []
    tmp_tree_list = []
    for i, lott in enumerate(list_of_tmp_trees):
        # print 'getting file: ', file_name
        this_file = ROOT.TFile('tmp__%s.root' % lott)
        this_tree = this_file.Get(lott)
        tmp_file_list.append(this_file)
        tmp_tree_list.append(this_tree)

    # Now, ...
    out_file.cd()
    out_tree_list = []
    for ttl in tmp_tree_list:
        tmp_tree = ttl.CloneTree()
        out_tree_list.append(tmp_tree)
        tmp_tree.Write()

    # write to file
    # new_tree.Write()
    out_file.Close()

# ------------------------------------------------------------------------------
def writeTreesToHistFitterFile(out_file_name, optimize_tree_dict):
    out_file = ROOT.TFile(out_file_name, 'RECREATE')

    buffer_of_trees = []
    list_of_tmp_trees = []
    out_file.ls()
    for sample_name in optimize_tree_dict:
        # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        print 'adding sample: ', sample_name
        writeSingleSampleToTmpFile( '%s.root' % sample_name
                                  , sample_name
                                  , optimize_tree_dict[sample_name]
                                  , ''
                                  , sample_name
                                  )
        list_of_tmp_trees.append(sample_name)

        writeSingleSampleToTmpFile( 'ee_%s.root' % sample_name
                                  , sample_name
                                  , optimize_tree_dict[sample_name]
                                  , 'is_ee'
                                  , 'ee_' + sample_name
                                  )
        list_of_tmp_trees.append('ee_' + sample_name)

        writeSingleSampleToTmpFile( 'mm_%s.root' % sample_name
                                  , sample_name
                                  , optimize_tree_dict[sample_name]
                                  , 'is_mm'
                                  , 'mm_' + sample_name
                                  )
        list_of_tmp_trees.append('mm_' + sample_name)

        writeSingleSampleToTmpFile( 'em_%s.root' % sample_name
                                  , sample_name
                                  , optimize_tree_dict[sample_name]
                                  , 'is_em'
                                  , 'em_' + sample_name
                                  )
        list_of_tmp_trees.append('em_' + sample_name)

    mergeTmpTreesToOutput( out_file_name, list_of_tmp_trees )

# ------------------------------------------------------------------------------
def constructPathList(paths_to_glob):
    path_list = []
    for ptg in paths_to_glob:
        path_list.extend(glob.glob(ptg))
    return path_list

# ------------------------------------------------------------------------------
def main():
    opt_ntup_dir_list = glob.glob('%s/NextOptNtupDir.BMinusL.*' % os.environ['BASE_WORK_DIR'])

    bkg_optimize_tree_dict = {}
    sig_optimize_tree_dict = {}
    for opt_ntup_dir in opt_ntup_dir_list:
        print '--------------------------------------------'
        print 'opt ntup dir: ', opt_ntup_dir

        syst_tag = opt_ntup_dir.split('.')[-1]
        if syst_tag == 'NOMINAL': syst_tag = 'NoSys'
        print 'syst tag: ', syst_tag

        bkg_optimize_tree_dict['ttbar_%s' % syst_tag] = constructPathList(['%s/BMinusL.*117050.PowhegPythia_P2011C_ttbar.af2*.ntup.root' % opt_ntup_dir])

        bkg_optimize_tree_dict['ttV_%s' % syst_tag] = constructPathList( [ '%s/BMinusL.*119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW*.ntup.root' % opt_ntup_dir
                                                                         , '%s/BMinusL.*119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj*.ntup.root' % opt_ntup_dir
                                                                         , '%s/BMinusL.*119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ*.ntup.root' % opt_ntup_dir
                                                                         , '%s/BMinusL.*119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj*.ntup.root' % opt_ntup_dir
                                                                         , '%s/BMinusL.*119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW*.ntup.root' % opt_ntup_dir
                                                                         ]
                                                                       )
        bkg_optimize_tree_dict['SingleTop_%s' % syst_tag] = constructPathList( [ '%s/BMinusL.*110101.AcerMCPythia_P2011CCTEQ6L1_singletop_tchan_l*.ntup.root' % opt_ntup_dir
                                                                               , '%s/BMinusL.*110119.PowhegPythia_P2011C_st_schan_lep*.ntup.root' % opt_ntup_dir
                                                                               , '%s/BMinusL.*110141.PowhegPythia_P2011C_st_Wtchan_dilepton_DR*.ntup.root' % opt_ntup_dir
                                                                               ]
                                                                             )
        bkg_optimize_tree_dict['ZGamma_%s' % syst_tag] = constructPathList( [ '%s/BMinusL.*167749.Sherpa_CT10_ZeeMassiveCBPt0_BFilter*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167750.Sherpa_CT10_ZeeMassiveCBPt0_CFilterBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167751.Sherpa_CT10_ZeeMassiveCBPt0_CVetoBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167752.Sherpa_CT10_ZmumuMassiveCBPt0_BFilter*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167753.Sherpa_CT10_ZmumuMassiveCBPt0_CFilterBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167754.Sherpa_CT10_ZmumuMassiveCBPt0_CVetoBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167755.Sherpa_CT10_ZtautauMassiveCBPt0_BFilter*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167797.Sherpa_CT10_ZeeMassiveCBPt70_140_BFilter*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167798.Sherpa_CT10_ZeeMassiveCBPt70_140_CFilterBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167799.Sherpa_CT10_ZeeMassiveCBPt70_140_CVetoBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167800.Sherpa_CT10_ZmumuMassiveCBPt70_140_BFilter*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167801.Sherpa_CT10_ZmumuMassiveCBPt70_140_CFilterBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167802.Sherpa_CT10_ZmumuMassiveCBPt70_140_CVetoBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167803.Sherpa_CT10_ZtautauMassiveCBPt70_140_BFilter*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167809.Sherpa_CT10_ZeeMassiveCBPt140_280_BFilter*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167810.Sherpa_CT10_ZeeMassiveCBPt140_280_CFilterBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167811.Sherpa_CT10_ZeeMassiveCBPt140_280_CVetoBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167812.Sherpa_CT10_ZmumuMassiveCBPt140_280_BFilter*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167813.Sherpa_CT10_ZmumuMassiveCBPt140_280_CFilterBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167814.Sherpa_CT10_ZmumuMassiveCBPt140_280_CVetoBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167815.Sherpa_CT10_ZtautauMassiveCBPt140_280_BFilter*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167821.Sherpa_CT10_ZeeMassiveCBPt280_500_BFilter*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167822.Sherpa_CT10_ZeeMassiveCBPt280_500_CFilterBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167823.Sherpa_CT10_ZeeMassiveCBPt280_500_CVetoBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167824.Sherpa_CT10_ZmumuMassiveCBPt280_500_BFilter*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167825.Sherpa_CT10_ZmumuMassiveCBPt280_500_CFilterBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167826.Sherpa_CT10_ZmumuMassiveCBPt280_500_CVetoBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167827.Sherpa_CT10_ZtautauMassiveCBPt280_500_BFilter*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167833.Sherpa_CT10_ZeeMassiveCBPt500_BFilter*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167834.Sherpa_CT10_ZeeMassiveCBPt500_CFilterBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167835.Sherpa_CT10_ZeeMassiveCBPt500_CVetoBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167836.Sherpa_CT10_ZmumuMassiveCBPt500_BFilter*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167837.Sherpa_CT10_ZmumuMassiveCBPt500_CFilterBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167838.Sherpa_CT10_ZmumuMassiveCBPt500_CVetoBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*167839.Sherpa_CT10_ZtautauMassiveCBPt500_BFilter*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*173041.Sherpa_CT10_DYeeM08to15*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*173042.Sherpa_CT10_DYeeM15to40*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*173043.Sherpa_CT10_DYmumuM08to15*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*173044.Sherpa_CT10_DYmumuM15to40*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*173045.Sherpa_CT10_DYtautauM08to15*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*173046.Sherpa_CT10_DYtautauM15to40*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*180543.Sherpa_CT10_ZeeMassiveCBPt40_70_BFilter*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*180544.Sherpa_CT10_ZeeMassiveCBPt40_70_CFilterBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*180545.Sherpa_CT10_ZeeMassiveCBPt40_70_CVetoBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*180546.Sherpa_CT10_ZmumuMassiveCBPt40_70_BFilter*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*180547.Sherpa_CT10_ZmumuMassiveCBPt40_70_CFilterBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*180548.Sherpa_CT10_ZmumuMassiveCBPt40_70_CVetoBVeto*.ntup.root' % opt_ntup_dir
                                                                            , '%s/BMinusL.*180549.Sherpa_CT10_ZtautauMassiveCBPt40_70_BFilter*.ntup.root' % opt_ntup_dir
                                                                            ]
                                                                          )
        bkg_optimize_tree_dict['Diboson_%s' % syst_tag] = constructPathList( [ "%s/BMinusL.*177997.Sherpa_CT10_llnunu_WW_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                             , "%s/BMinusL.*177999.Sherpa_CT10_llnunu_ZZ_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                             , "%s/BMinusL.*179974.Sherpa_CT10_lllnu_WZ_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                             , "%s/BMinusL.*179975.Sherpa_CT10_lnununu_WZ_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                             , "%s/BMinusL.*183585.Sherpa_CT10_ZWtoeeqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                             , "%s/BMinusL.*183586.Sherpa_CT10_ZZtoeeqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                             , "%s/BMinusL.*183587.Sherpa_CT10_ZWtomumuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                             , "%s/BMinusL.*183588.Sherpa_CT10_ZZtomumuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                             , "%s/BMinusL.*183589.Sherpa_CT10_ZWtotautauqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                             , "%s/BMinusL.*183590.Sherpa_CT10_ZZtotautauqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                             , "%s/BMinusL.*183591.Sherpa_CT10_ZWtonunuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                             , "%s/BMinusL.*183592.Sherpa_CT10_ZZtonunuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                             , "%s/BMinusL.*183734.Sherpa_CT10_WWtoenuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                             , "%s/BMinusL.*183735.Sherpa_CT10_WZtoenuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                             , "%s/BMinusL.*183736.Sherpa_CT10_WWtomunuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                             , "%s/BMinusL.*183737.Sherpa_CT10_WZtomunuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                             , "%s/BMinusL.*183738.Sherpa_CT10_WWtotaunuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                             , "%s/BMinusL.*183739.Sherpa_CT10_WZtotaunuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                             ]
                                                                           )
        bkg_optimize_tree_dict['Higgs_%s' % syst_tag] = constructPathList( [ '%s/BMinusL.*160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*161305.Pythia8_AU2CTEQ6L1_ttH125_WWinclusive*.ntup.root' % opt_ntup_dir
                                                                           ]
                                                                         )

        bkg_optimize_tree_dict['Other_%s' % syst_tag] = constructPathList( [ '%s/BMinusL.*119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*110101.AcerMCPythia_P2011CCTEQ6L1_singletop_tchan_l*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*110119.PowhegPythia_P2011C_st_schan_lep*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*110141.PowhegPythia_P2011C_st_Wtchan_dilepton_DR*.ntup.root' % opt_ntup_dir
                                                                           , "%s/BMinusL.*177997.Sherpa_CT10_llnunu_WW_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                           , "%s/BMinusL.*177999.Sherpa_CT10_llnunu_ZZ_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                           , "%s/BMinusL.*179974.Sherpa_CT10_lllnu_WZ_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                           , "%s/BMinusL.*179975.Sherpa_CT10_lnununu_WZ_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                           , "%s/BMinusL.*183585.Sherpa_CT10_ZWtoeeqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                           , "%s/BMinusL.*183586.Sherpa_CT10_ZZtoeeqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                           , "%s/BMinusL.*183587.Sherpa_CT10_ZWtomumuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                           , "%s/BMinusL.*183588.Sherpa_CT10_ZZtomumuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                           , "%s/BMinusL.*183589.Sherpa_CT10_ZWtotautauqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                           , "%s/BMinusL.*183590.Sherpa_CT10_ZZtotautauqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                           , "%s/BMinusL.*183591.Sherpa_CT10_ZWtonunuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                           , "%s/BMinusL.*183592.Sherpa_CT10_ZZtonunuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                           , "%s/BMinusL.*183734.Sherpa_CT10_WWtoenuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                           , "%s/BMinusL.*183735.Sherpa_CT10_WZtoenuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                           , "%s/BMinusL.*183736.Sherpa_CT10_WWtomunuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                           , "%s/BMinusL.*183737.Sherpa_CT10_WZtomunuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                           , "%s/BMinusL.*183738.Sherpa_CT10_WWtotaunuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                           , "%s/BMinusL.*183739.Sherpa_CT10_WZtotaunuqq_MassiveCB*.ntup.root" % opt_ntup_dir
                                                                           , '%s/BMinusL.*160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep*.ntup.root' % opt_ntup_dir
                                                                           , '%s/BMinusL.*161305.Pythia8_AU2CTEQ6L1_ttH125_WWinclusive*.ntup.root' % opt_ntup_dir
                                                                           ]
                                                                         )

        if syst_tag == 'NoSys':
            bkg_optimize_tree_dict['data'] = constructPathList( [ '%s/BMinusL.periodA_egamma.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodA_muon.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodB_egamma.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodB_muon.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodC_egamma.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodC_muon.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodD_egamma.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodD_muon.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodE_egamma.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodE_muon.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodG_egamma.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodG_muon.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodH_egamma.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodH_muon.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodI_egamma.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodI_muon.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodJ_egamma.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodJ_muon.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodL_egamma.ntup.root' % opt_ntup_dir
                                                                , '%s/BMinusL.periodL_muon.ntup.root' % opt_ntup_dir
                                                                ]
                                                              )

        sig_optimize_tree_dict['sig_100_%s'  % syst_tag] = constructPathList(['%s/BMinusL.*202632.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_100*.ntup.root'  % opt_ntup_dir])
        sig_optimize_tree_dict['sig_200_%s'  % syst_tag] = constructPathList(['%s/BMinusL.*202633.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_200*.ntup.root'  % opt_ntup_dir])
        sig_optimize_tree_dict['sig_300_%s'  % syst_tag] = constructPathList(['%s/BMinusL.*202634.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_300*.ntup.root'  % opt_ntup_dir])
        sig_optimize_tree_dict['sig_400_%s'  % syst_tag] = constructPathList(['%s/BMinusL.*202635.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_400*.ntup.root'  % opt_ntup_dir])
        sig_optimize_tree_dict['sig_500_%s'  % syst_tag] = constructPathList(['%s/BMinusL.*202636.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_500*.ntup.root'  % opt_ntup_dir])
        sig_optimize_tree_dict['sig_600_%s'  % syst_tag] = constructPathList(['%s/BMinusL.*202637.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_600*.ntup.root'  % opt_ntup_dir])
        sig_optimize_tree_dict['sig_700_%s'  % syst_tag] = constructPathList(['%s/BMinusL.*202638.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_700*.ntup.root'  % opt_ntup_dir])
        sig_optimize_tree_dict['sig_800_%s'  % syst_tag] = constructPathList(['%s/BMinusL.*202639.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_800*.ntup.root'  % opt_ntup_dir])
        sig_optimize_tree_dict['sig_900_%s'  % syst_tag] = constructPathList(['%s/BMinusL.*202640.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_900*.ntup.root'  % opt_ntup_dir])
        sig_optimize_tree_dict['sig_1000_%s' % syst_tag] = constructPathList(['%s/BMinusL.*202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000*.ntup.root' % opt_ntup_dir])

    writeTreesToHistFitterFile('BackgroundHistFitterTrees.root', bkg_optimize_tree_dict)
    writeTreesToHistFitterFile('SignalHistFitterTrees.root'    , sig_optimize_tree_dict)

# ==============================================================================
if __name__ == "__main__":
    main()
