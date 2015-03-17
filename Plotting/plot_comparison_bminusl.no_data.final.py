#!/usr/bin/env python

import ROOT
import HistHandle as hh
import plot_comparison_bminusl_final as pc
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
    # ic_numerator = None
    ic_numerator = hh.Container.InputContainer( name = 'Data'
                                              , entry_list = [entry_containers['ec_data']]
                                              , lumi_target = 0
                                              , line_width=2
                                              )
    ic_denominator = hh.Container.InputContainer( name = 'Bkg'
                                                , entry_list = [ entry_containers['ec_ttbar_powheg']
                                                               , entry_containers['ec_Zgamma_sherpa']
                                                               , entry_containers['ec_single_top_all_channels']
                                                               , entry_containers['ec_other']
                                                               ]
                                                , lumi_target = 20300
                                                , line_width=2
                                                )
    ic_signal = hh.Container.InputContainer( name = 'Signal'
                                           , entry_list = [ entry_containers['ec_bl_500']
                                                          , entry_containers['ec_bl_800']
                                                          , entry_containers['ec_bl_1000']
                                                          ]
                                           , lumi_target = 20300
                                           , line_width=2
                                           )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # Actually plot comparisons
    out_file_name = 'compare_plots.b_minus_l.no_data.root'
    pc.plotComparisons( ic_numerator   = ic_numerator
                      , ic_denominator = ic_denominator
                      , ic_other       = ic_signal
                      , out_file_name  = out_file_name
                      , do_ratio=False
                      )

# ==============================================================================
if __name__ == '__main__':
    main()
