#!/usr/bin/env python

# ==============================================================================
import math
import ROOT

# ------------------------------------------------------------------------------
def passCuts(event, cut_type = ''):
    if cut_type == '800':
        # 800
        if (event.mbl_0 - event.mbl_1) / (event.mbl_0 + event.mbl_1) > 0.2715 : return False
        if event.ht_baseline < 1800: return False
        if event.met_et/math.sqrt(event.ht_baseline) > 6.5 : return False
    elif cut_type == '900':
        # 900
        if (event.mbl_0 - event.mbl_1) / (event.mbl_0 + event.mbl_1) > 0.6 : return False
        if event.ht_baseline < 1800: return False
        if event.met_et/math.sqrt(event.ht_baseline) > 6.5 : return False
    elif cut_type == '1000':
        # 1000
        if (event.mbl_0 - event.mbl_1) / (event.mbl_0 + event.mbl_1) > 0.5079 : return False
        if event.ht_baseline < 2100: return False
        if event.met_et/math.sqrt(event.ht_baseline) > 30 : return False
    elif cut_type == '1000-900':
        # 900-1000
        if (event.mbl_0 - event.mbl_1) / (event.mbl_0 + event.mbl_1) > 0.5 : return False
        if event.ht_baseline < 2000: return False
        if event.met_et/math.sqrt(event.ht_baseline) > 6.5 : return False
    elif cut_type == '1000-900_mbl':
        # 900-1000
        if (event.mbl_0 - event.mbl_1) / (event.mbl_0 + event.mbl_1) > 0.5 : return False
        # if event.ht_baseline < 2000: return False
        # if event.met_et/math.sqrt(event.ht_baseline) > 6.5 : return False
    elif cut_type == '1000-900_ht':
        # 900-1000
        # if (event.mbl_0 - event.mbl_1) / (event.mbl_0 + event.mbl_1) > 0.5 : return False
        if event.ht_baseline < 2000: return False
        # if event.met_et/math.sqrt(event.ht_baseline) > 6.5 : return False
    elif cut_type == '1000-900_met':
        # 900-1000
        # if (event.mbl_0 - event.mbl_1) / (event.mbl_0 + event.mbl_1) > 0.5 : return False
        # if event.ht_baseline < 2000: return False
        if event.met_et/math.sqrt(event.ht_baseline) > 6.5 : return False
    else:
        # bogus
        if (event.mbl_0 - event.mbl_1) / (event.mbl_0 + event.mbl_1) > 1 : return False
        if event.ht_baseline < 1000: return False
        if event.met_et/math.sqrt(event.ht_baseline) > 100 : return False

    return True

# ------------------------------------------------------------------------------
def produceMblPlots(in_file_name, tag):
    print 'getting mbl plot for ', tag

    f = ROOT.TFile.Open(in_file_name)
    t = f.Get("optimize")

    h_mbl_no_cut = ROOT.TH1D( 'mbl_no_cut__%s' % tag
                            , 'mbl_no_cut__%s ; m_{bl} [GeV] ; Entries / 10 GeV' % tag
                            , 150, 0, 1500
                            )
    h_ht_no_cut = ROOT.TH1D( 'ht_no_cut__%s' % tag
                           , 'ht_no_cut__%s ; h_{T} [GeV] ; Entries / 10 GeV' % tag
                           , 50, 0, 5000
                           )
    h_met_sig_no_cut = ROOT.TH1D( 'met_sig_no_cut__%s' % tag
                                , 'met_sig_no_cut__%s ; E_{T}^{miss}/#sqrt{h_{T}} [GeV^{1/2}] ; Entries / 10 GeV' % tag
                                , 50, 0, 50
                                )

    h_mbl_w_cut = ROOT.TH1D( 'mbl_w_cut__%s' % tag
                           , 'mbl_w_cut__%s ; m_{bl} [GeV] ; Entries / 10 GeV' % tag
                           , 150, 0, 1500
                           )
    h_ht_w_cut = ROOT.TH1D( 'ht_w_cut__%s' % tag
                          , 'ht_w_cut__%s ; h_{T} [GeV] ; Entries / 10 GeV^{1/2}' % tag
                          , 50, 0, 5000
                          )
    h_met_sig_w_cut = ROOT.TH1D( 'met_sig_w_cut__%s' % tag
                               , 'met_sig_w_cut__%s ; E_{T}^{miss}/#sqrt{h_{T}} [GeV^{1/2}] ; Entries / 10 GeV^{1/2}' % tag
                               , 50, 0, 50
                               )

    for event in t:
        weight = 21000*event.weight
        # weight = event.weight
        h_mbl_no_cut.Fill(event.mbl_0, weight)
        h_mbl_no_cut.Fill(event.mbl_1, weight)

        h_ht_no_cut.Fill(     event.ht_baseline     , weight)
        h_met_sig_no_cut.Fill(event.met_et/math.sqrt(event.ht_baseline), weight)
        # h_met_sig_no_cut.Fill(event.met_sig_baseline, weight)

        if (passCuts(event, '900-1000')):
            h_mbl_w_cut.Fill(event.mbl_0, weight)
            h_mbl_w_cut.Fill(event.mbl_1, weight)

            h_ht_w_cut.Fill(     event.ht_baseline     , weight)
            # h_met_sig_w_cut.Fill(event.met_sig_baseline, weight)
            h_met_sig_w_cut.Fill(event.met_et/math.sqrt(event.ht_baseline), weight)


    print '# entries before cut: ' , h_mbl_no_cut.GetEntries()
    print '# entries after cut:  ' , h_mbl_w_cut.GetEntries()

    print '# integral before cut: ' , h_mbl_no_cut.Integral()
    print '# integral after cut:  ' , h_mbl_w_cut.Integral()

    print ''

    return { 'mbl__no_cuts':h_mbl_no_cut
           , 'ht__no_cuts':h_ht_no_cut
           , 'met_sig__no_cuts':h_met_sig_no_cut
           , 'mbl__w_cuts':h_mbl_w_cut
           , 'ht__w_cuts':h_ht_w_cut
           , 'met_sig__w_cuts':h_met_sig_w_cut
           }

# ------------------------------------------------------------------------------
def setRange(hist_list):
    global_max = 0
    for hl in hist_list:
        local_max = hl.GetMaximum()
        if local_max > global_max:
            global_max = local_max

    # global_max *= 10
    global_max *= 5

    for hl in hist_list:
        hl.SetMaximum(global_max)

# ------------------------------------------------------------------------------
def drawCompareCanvas( background_hist_dict
                     , signal_hist_dict
                     , hist_name
                     , tag
                     , out_file
                     ):
    out_file.cd()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bkg_no_cuts = background_hist_dict['%s__no_cuts' % hist_name]
    bkg_w_cuts  = background_hist_dict['%s__w_cuts'  % hist_name]

    sig_no_cuts = signal_hist_dict['%s__no_cuts' % hist_name]
    sig_w_cuts  = signal_hist_dict['%s__w_cuts'  % hist_name]

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bkg_no_cuts.SetLineColor(ROOT.kBlack)
    bkg_w_cuts.SetLineColor( ROOT.kBlack)

    bkg_no_cuts.SetLineWidth(3)
    bkg_w_cuts.SetLineWidth( 3)

    # background_hist_dict['%s__no_cuts' % hist_name].SetLineColor(ROOT.kBlack)
    # background_hist_dict['%s__w_cuts'  % hist_name].SetLineColor(ROOT.kBlack)

    # background_hist_dict['%s__no_cuts' % hist_name].SetLineWidth(3)
    # background_hist_dict['%s__w_cuts'  % hist_name].SetLineWidth(3)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    sig_no_cuts.SetLineColor(ROOT.kRed)
    sig_w_cuts.SetLineColor( ROOT.kRed)

    sig_no_cuts.SetLineWidth(3)
    sig_w_cuts.SetLineWidth( 3)

    # signal_hist_dict['%s__mbl_no_cuts' % hist_name].SetLineColor(ROOT.kRed)
    # signal_hist_dict['%s__mbl_w_cuts'  % hist_name].SetLineColor(ROOT.kRed)

    # signal_hist_dict['%s__mbl_no_cuts' % hist_name].SetLineWidth(3)
    # signal_hist_dict['%s__mbl_cuts'    % hist_name].SetLineWidth(3)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    c = ROOT.TCanvas('compare__%s__%s' % (hist_name, tag))
    c.Divide(1,2)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    c.cd(1)
    ROOT.gPad.SetLogy()

    setRange( [ bkg_no_cuts
              , sig_no_cuts
              ]
            )

    bkg_no_cuts.Draw()
    sig_no_cuts.Draw('SAME')

    # setRange( [ background_hist_dict['no_cuts']
    #           , signal_hist_dict[    'no_cuts']
    #           ]
    #         )

    # background_hist_dict['no_cuts'].Draw()
    # signal_hist_dict[    'no_cuts'].Draw('SAME')

    b_entries_no_cuts = bkg_no_cuts.GetEntries()
    s_entries_no_cuts = sig_no_cuts.GetEntries()

    b_int_no_cuts = bkg_no_cuts.Integral()
    s_int_no_cuts = sig_no_cuts.Integral()

    # b_int_no_cuts = background_hist_dict['no_cuts'].Integral()
    # s_int_no_cuts = signal_hist_dict[    'no_cuts'].Integral()

    text_no_cut_0 = ROOT.TText(0.60, 0.85, 'Only basic cleaning')
    text_no_cut_1 = ROOT.TText(0.60, 0.80, 'Background: %s (raw: %s)'   % (b_int_no_cuts, b_entries_no_cuts))
    text_no_cut_2 = ROOT.TText(0.60, 0.75, 'Signal: %s (raw: %s)'       % (s_int_no_cuts, s_entries_no_cuts))
    text_no_cut_3 = ROOT.TText(0.60, 0.70, 'S/#sqrt{S+B}: %s' % ( s_int_no_cuts/ math.sqrt( s_int_no_cuts + b_int_no_cuts ) ) )

    text_no_cut_1.SetTextColor(ROOT.kBlack)
    text_no_cut_2.SetTextColor(ROOT.kRed)

    text_no_cut_0.SetNDC()
    text_no_cut_1.SetNDC()
    text_no_cut_2.SetNDC()
    text_no_cut_3.SetNDC()

    text_no_cut_0.Draw()
    text_no_cut_1.Draw()
    text_no_cut_2.Draw()
    text_no_cut_3.Draw()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    c.cd(2)
    ROOT.gPad.SetLogy()

    setRange( [ bkg_w_cuts
              , sig_w_cuts
              ]
            )

    bkg_w_cuts.Draw()
    sig_w_cuts.Draw('SAME')

    b_entries_cuts = bkg_w_cuts.GetEntries()
    s_entries_cuts = sig_w_cuts.GetEntries()

    b_int_cuts = bkg_w_cuts.Integral()
    s_int_cuts = sig_w_cuts.Integral()

    # setRange( [ background_hist_dict['cuts']
    #           , signal_hist_dict[    'cuts']
    #           ]
    #         )

    # background_hist_dict['cuts'].Draw()
    # signal_hist_dict[    'cuts'].Draw('SAME')

    # b_int_cuts = background_hist_dict['cuts'].Integral()
    # s_int_cuts = signal_hist_dict[    'cuts'].Integral()

    text_cut_0 = ROOT.TText(0.60, 0.85, 'Full selection')
    text_cut_1 = ROOT.TText(0.60, 0.80, 'Background: %s (raw: %s)' % (b_int_cuts, b_entries_cuts))
    text_cut_2 = ROOT.TText(0.60, 0.75, 'Signal: %s (raw: %s)'     % (s_int_cuts, s_entries_cuts))
    text_cut_3 = ROOT.TText(0.60, 0.70, 'S/#sqrt{S+B}: %s' % ( s_int_cuts/ math.sqrt( s_int_cuts + b_int_cuts ) ) )

    text_cut_1.SetTextColor(ROOT.kBlack)
    text_cut_2.SetTextColor(ROOT.kRed)

    text_cut_0.SetNDC()
    text_cut_1.SetNDC()
    text_cut_2.SetNDC()
    text_cut_3.SetNDC()

    text_cut_0.Draw()
    text_cut_1.Draw()
    text_cut_2.Draw()
    text_cut_3.Draw()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    c.Write()

# ------------------------------------------------------------------------------
def main():
    ROOT.gStyle.SetOptStat(0)

    # base_path = '${BASE_WORK_DIR}/hists/bminusl_opt_ntup_2014_06_18__19_33/'
    base_path = '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/'
    ttbar       = produceMblPlots('%s/BMinusL.117050.PowhegPythia_P2011C_ttbar.af2_v2.ntup.root'                         % base_path, 'ttbar')
    # signal_100  = produceMblPlots('%s/BMinusL.202632.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_100.ntup.root'  % base_path, 'signal_100' )
    # signal_200  = produceMblPlots('%s/BMinusL.202633.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_200.ntup.root'  % base_path, 'signal_200' )
    # signal_300  = produceMblPlots('%s/BMinusL.202634.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_300.ntup.root'  % base_path, 'signal_300' )
    # signal_400  = produceMblPlots('%s/BMinusL.202635.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_400.ntup.root'  % base_path, 'signal_400' )
    # signal_500  = produceMblPlots('%s/BMinusL.202636.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_500.ntup.root'  % base_path, 'signal_500' )
    # signal_600  = produceMblPlots('%s/BMinusL.202637.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_600.ntup.root'  % base_path, 'signal_600' )
    # signal_700  = produceMblPlots('%s/BMinusL.202638.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_700.ntup.root'  % base_path, 'signal_700' )
    # signal_800  = produceMblPlots('%s/BMinusL.202639.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_800.ntup.root'  % base_path, 'signal_800' )
    # signal_900  = produceMblPlots('%s/BMinusL.202640.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_900.ntup.root'  % base_path, 'signal_900' )
    signal_1000 = produceMblPlots('%s/BMinusL.202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000.ntup.root' % base_path, 'signal_1000')

    out_file = ROOT.TFile.Open('out.root', 'recreate')

    # drawCompareCanvas(ttbar, signal_100 , 'mbl', 'ttbar_T100' , out_file)
    # drawCompareCanvas(ttbar, signal_200 , 'mbl', 'ttbar_T200' , out_file)
    # drawCompareCanvas(ttbar, signal_300 , 'mbl', 'ttbar_T300' , out_file)
    # drawCompareCanvas(ttbar, signal_400 , 'mbl', 'ttbar_T400' , out_file)
    # drawCompareCanvas(ttbar, signal_500 , 'mbl', 'ttbar_T500' , out_file)
    # drawCompareCanvas(ttbar, signal_600 , 'mbl', 'ttbar_T600' , out_file)
    # drawCompareCanvas(ttbar, signal_700 , 'mbl', 'ttbar_T700' , out_file)
    # drawCompareCanvas(ttbar, signal_800 , 'mbl', 'ttbar_T800' , out_file)
    # drawCompareCanvas(ttbar, signal_900 , 'mbl', 'ttbar_T900' , out_file)
    drawCompareCanvas(ttbar, signal_1000, 'mbl', 'ttbar_T1000', out_file)

    # drawCompareCanvas(ttbar, signal_100 , 'ht', 'ttbar_T100' , out_file)
    # drawCompareCanvas(ttbar, signal_200 , 'ht', 'ttbar_T200' , out_file)
    # drawCompareCanvas(ttbar, signal_300 , 'ht', 'ttbar_T300' , out_file)
    # drawCompareCanvas(ttbar, signal_400 , 'ht', 'ttbar_T400' , out_file)
    # drawCompareCanvas(ttbar, signal_500 , 'ht', 'ttbar_T500' , out_file)
    # drawCompareCanvas(ttbar, signal_600 , 'ht', 'ttbar_T600' , out_file)
    # drawCompareCanvas(ttbar, signal_700 , 'ht', 'ttbar_T700' , out_file)
    # drawCompareCanvas(ttbar, signal_800 , 'ht', 'ttbar_T800' , out_file)
    # drawCompareCanvas(ttbar, signal_900 , 'ht', 'ttbar_T900' , out_file)
    drawCompareCanvas(ttbar, signal_1000, 'ht', 'ttbar_T1000', out_file)

    # drawCompareCanvas(ttbar, signal_100 , 'met_sig', 'ttbar_T100' , out_file)
    # drawCompareCanvas(ttbar, signal_200 , 'met_sig', 'ttbar_T200' , out_file)
    # drawCompareCanvas(ttbar, signal_300 , 'met_sig', 'ttbar_T300' , out_file)
    # drawCompareCanvas(ttbar, signal_400 , 'met_sig', 'ttbar_T400' , out_file)
    # drawCompareCanvas(ttbar, signal_500 , 'met_sig', 'ttbar_T500' , out_file)
    # drawCompareCanvas(ttbar, signal_600 , 'met_sig', 'ttbar_T600' , out_file)
    # drawCompareCanvas(ttbar, signal_700 , 'met_sig', 'ttbar_T700' , out_file)
    # drawCompareCanvas(ttbar, signal_800 , 'met_sig', 'ttbar_T800' , out_file)
    # drawCompareCanvas(ttbar, signal_900 , 'met_sig', 'ttbar_T900' , out_file)
    drawCompareCanvas(ttbar, signal_1000, 'met_sig', 'ttbar_T1000', out_file)

    out_file.Close()

# ==============================================================================
if __name__ == "__main__":
    main()
