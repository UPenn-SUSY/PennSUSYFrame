#!/usr/bin/env python

import ROOT
import HistHandle as hh
import plot_comparison as pc
import BminuslGrouping as grouping

# ==============================================================================
def main():
    # root stuff
    ROOT.TH1.SetDefaultSumw2()
    ROOT.gROOT.SetBatch()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    syst_tag = 'NOMINAL'
    entry_containers = grouping.generateEntryContainers(syst_tag)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # Collect EntryContainer into InputContainers
    ic_numerator = hh.Container.InputContainer( name = 'Data'
                                              , entry_list = [entry_containers['ec_data']]
                                              , lumi_target = 1
                                              )
    ic_denominator = hh.Container.InputContainer( name = 'Bkg'
                                                , entry_list = [ entry_containers['ec_ttbar_powheg']
                                                               , entry_containers['ec_Zgamma_sherpa']
                                                               , entry_containers['ec_single_top_all_channels']
                                                               , entry_containers['ec_other']
                                                               # , entry_containers['ec_ZZ']
                                                               # , entry_containers['ec_other_no_ZZ']
                                                               ]
                                                , lumi_target = 21000
                                                )
    ic_signal = hh.Container.InputContainer( name = 'Signal'
                                           , entry_list = [ entry_containers['ec_bl_500']
                                                          , entry_containers['ec_bl_600']
                                                          , entry_containers['ec_bl_700']
                                                          , entry_containers['ec_bl_800']
                                                          , entry_containers['ec_bl_900']
                                                          , entry_containers['ec_bl_1000']
                                                          ]
                                           , lumi_target = 21000
                                           )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # Actually plot comparisons
    out_file_name = 'compare_plots.b_minus_l.root'
    pc.plotComparisons( ic_numerator   = ic_numerator
                      , ic_denominator = ic_denominator
                      , ic_other       = ic_signal
                      , out_file_name  = out_file_name
                      )

# ==============================================================================
if __name__ == '__main__':
    main()
