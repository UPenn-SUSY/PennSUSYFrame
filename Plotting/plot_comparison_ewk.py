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
    ec_data = hh.Container.EntryContainer( label = 'Data'
                                          , fill_color = ROOT.kBlack
                                          , input_file_list = [ "${BASE_WORK_DIR}/EwkAnalysis/May20/Isr.AllData.root"
                                                              
                                                              ]
                                          )
  
    ec_zjets = hh.Container.EntryContainer( label = 'Z+jets'
                                        , fill_color = ROOT.kRed+1
                                        , input_file_list = [ "${BASE_WORK_DIR}/EwkAnalysis/Isr.117650.ZeeNp0.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/Isr.117651.ZeeNp1.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/Isr.117652.ZeeNp2.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/Isr.117653.ZeeNp3.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/Isr.117654.ZeeNp4.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/Isr.117655.ZeeNp5.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/Isr.117660.ZmumuNp0.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/Isr.117661.ZmumuNp1.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/Isr.117662.ZmumuNp2.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/Isr.117663.ZmumuNp3.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/Isr.117664.ZmumuNp4.hists.root"
                                                            , "${BASE_WORK_DIR}/EwkAnalysis/Isr.117665.ZmumuNp5.hists.root"


                                                            ]
                                        )
    ic_numerator = hh.Container.InputContainer( name = 'Data'
                                              , entry_list = [ec_data]
                                              #,lumi_target = 13000
                                                )
    ic_denominator = hh.Container.InputContainer( name = 'Background'
                                                , entry_list = [ec_zjets]
                                                , lumi_target = 13000
                                                )

    out_file_name = 'compare_plots.ewk.root'

    pc.plotComparisons( ic_numerator   = ic_numerator
                      , ic_denominator = ic_denominator
                      , ic_other       = None
                      , out_file_name  = out_file_name
                      )

# ==============================================================================
if __name__ == '__main__':
    main()
