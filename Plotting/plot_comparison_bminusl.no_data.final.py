#!/usr/bin/env python

import ROOT
import HistHandle as hh
import plot_comparison_bminusl_final as pc
import BminuslGrouping as grouping

# ------------------------------------------------------------------------------
def plotComparisonsConfNote( ic_numerator
                           , ic_denominator
                           , ic_other
                           , out_file_name
                           , do_ratio=True
                           , atlas_label='Preliminary'
                           ):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # root stuff
    ROOT.TH1.SetDefaultSumw2()
    ROOT.gROOT.SetBatch()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    out_file = ROOT.TFile(out_file_name, 'RECREATE')

    pc.makeFinalPlot(dir_name='BMINUSL_SR_HT_1100_MINUS_MBL',
                     hist='flavor_all__mbl_0',
                     ic_numerator=ic_numerator,
                     ic_denominator=ic_denominator,
                     ic_other=ic_other,
                     out_file=out_file,
                     y_max_lin=60,
                     y_max_log=3000,
                     y_min_log=0.01,
                     atlas_label=atlas_label)

    pc.makeFinalPlot(dir_name='BMINUSL_SR_HT_1100_MBL_400_MINUS_HT',
                     hist='flavor_all__ht_signal',
                     ic_numerator=ic_numerator,
                     ic_denominator=ic_denominator,
                     ic_other=ic_other,
                     out_file=out_file,
                     y_max_lin=600,
                     y_max_log=1000000,
                     y_min_log=0.01,
                     do_ratio=do_ratio,
                     atlas_label=atlas_label)

    pc.makeFinalPlot(dir_name='BMINUSL_SR_HT_1100_MBL_400_MINUS_MBL_ASYM',
                     hist='flavor_all__mbl_asym',
                     ic_numerator=ic_numerator,
                     ic_denominator=ic_denominator,
                     ic_other=ic_other,
                     out_file=out_file,
                     y_max_lin=100,
                     y_max_log=8000,
                     do_ratio=do_ratio,
                     atlas_label=atlas_label)

    out_file.Close()

# ------------------------------------------------------------------------------
def plotComparisonsSupportNote( ic_numerator
                              , ic_denominator
                              , ic_other
                              , out_file_name
                              , do_ratio=True
                              , atlas_label='Internal'
                              ):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # root stuff
    ROOT.TH1.SetDefaultSumw2()
    ROOT.gROOT.SetBatch()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    out_file = ROOT.TFile(out_file_name, 'RECREATE')

    pc.makeFinalPlot(dir_name='BMINUSL_CR_TOP_MBL_200',
                     hist='flavor_all__mbl_0',
                     ic_numerator=ic_numerator,
                     ic_denominator=ic_denominator,
                     ic_other=ic_other,
                     out_file=out_file,
                     y_max_lin=60,
                     y_max_log=2e3,
                     y_min_log=0.01,
                     do_ratio=True,
                     atlas_label=atlas_label)

    # pc.makeFinalPlot(dir_name='BMINUSL_SR_HT_1100_MBL_400_MINUS_HT',
    #                  hist='flavor_all__ht_signal',
    #                  ic_numerator=ic_numerator_blind,
    #                  ic_denominator=ic_denominator,
    #                  ic_other=ic_other,
    #                  out_file=out_file,
    #                  y_max_lin=600,
    #                  y_max_log=1000000,
    #                  y_min_log=0.01,
    #                  do_ratio=do_ratio,
    #                  atlas_label='Simulation %s' % atlas_label)

    # pc.makeFinalPlot(dir_name='BMINUSL_SR_HT_1100_MBL_400_MINUS_MBL_ASYM',
    #                  hist='flavor_all__mbl_asym',
    #                  ic_numerator=ic_numerator_blind,
    #                  ic_denominator=ic_denominator,
    #                  ic_other=ic_other,
    #                  out_file=out_file,
    #                  y_max_lin=100,
    #                  y_max_log=8000,
    #                  do_ratio=do_ratio,
    #                  atlas_label='Simulation %s' % atlas_label)

    out_file.Close()

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
                                              , lumi_target = 1
                                              , line_width=2
                                              )
    ic_numerator_blind = hh.Container.InputContainer( name = 'Data'
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
    # TODO undo z scaling
    ic_denominator_unscaled = hh.Container.InputContainer( name = 'Bkg'
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
    out_file_name = 'compare_plots.b_minus_l.conf_note.root'
    plotComparisonsConfNote( ic_numerator   = ic_numerator_blind
                           , ic_denominator = ic_denominator
                           , ic_other       = ic_signal
                           , out_file_name  = out_file_name
                           , do_ratio       = False
                           , atlas_label    = 'Preliminary Simulation'
                           )

    out_file_name = 'compare_plots.b_minus_l.support_note.root'
    plotComparisonsSupportNote( ic_numerator   = ic_numerator
                              , ic_denominator = ic_denominator
                              , ic_other       = ic_signal
                              , out_file_name  = out_file_name
                              , do_ratio       = False
                              , atlas_label    = 'Internal'
                              )

# ==============================================================================
if __name__ == '__main__':
    main()
