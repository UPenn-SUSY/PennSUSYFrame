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
    # TODO parse these inputs in more reasonable way!
    ec_dummy = hh.Container.EntryContainer( label = 'dummy'
                                          , fill_color = ROOT.kBlack
                                          , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.dummy_hists.root"
                                                              ]
                                          )
    ec_ttbar = hh.Container.EntryContainer( label = 'ttbar'
                                          , fill_color = ROOT.kAzure+8
                                          , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.105200.ttbar.hists.root"
                                                              ]
                                          )
    ec_Zbb = hh.Container.EntryContainer( label = 'Zbb'
                                        , fill_color = ROOT.kRed+1
                                        , input_file_list = [ "${BASE_WORK_DIR}/BMinusL.110817.ZeebbNp0.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110818.ZeebbNp1.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110819.ZeebbNp2.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110820.ZeebbNp3.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110821.ZmumubbNp0.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110822.ZmumubbNp1.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110823.ZmumubbNp2.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110824.ZmumubbNp3.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110825.ZtautaubbNp0.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110826.ZtautaubbNp1.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110827.ZtautaubbNp2.hists.root"
                                                            , "${BASE_WORK_DIR}/BMinusL.110828.ZtautaubbNp3.hists.root"
                                                            ]
                                        )
    ic_numerator = hh.Container.InputContainer( name = 'dummy'
                                              , entry_list = [ec_dummy]
                                              , lumi_target = 0.
                                              )
    ic_denominator = hh.Container.InputContainer( name = 'Background'
                                                , entry_list = [ec_ttbar, ec_Zbb]
                                                , lumi_target = 21000
                                                )

    out_file_name = 'compare_plots.b_minus_l.root'

    pc.plotComparisons( ic_numerator   = ic_numerator
                      , ic_denominator = ic_denominator
                      , ic_other       = None
                      , out_file_name  = out_file_name
                      )

# ==============================================================================
if __name__ == '__main__':
    main()
