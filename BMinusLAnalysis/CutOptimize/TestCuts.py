#!/usr/bin/env python

# ==============================================================================
import math
import ROOT

# ------------------------------------------------------------------------------
def passCuts(event):
    if (event.mbl_0 - event.mbl_1) / (event.mbl_0 + event.mbl_1) > 10 : return False
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

    h_mbl_w_cut = ROOT.TH1D( 'mbl_w_cut__%s' % tag
                           , 'mbl_w_cut__%s ; m_{bl} [GeV] ; Entries / 10 GeV' % tag
                           , 150, 0, 1500
                           )

    for event in t:
        weight = 21000*event.weight
        h_mbl_no_cut.Fill(event.mbl_0, weight)
        h_mbl_no_cut.Fill(event.mbl_1, weight)

        if (passCuts(event)):
            h_mbl_w_cut.Fill(event.mbl_0, weight)
            h_mbl_w_cut.Fill(event.mbl_1, weight)

    print '# entries before cut: ' , h_mbl_no_cut.GetEntries()
    print '# entries after cut:  ' , h_mbl_w_cut.GetEntries()

    print '# integral before cut: ' , h_mbl_no_cut.Integral()
    print '# integral after cut:  ' , h_mbl_w_cut.Integral()

    return { 'no_cuts':h_mbl_no_cut
           , 'cuts':h_mbl_w_cut
           }

# ------------------------------------------------------------------------------
def setRange(hist_list):
    global_max = 0
    for hl in hist_list:
        local_max = hl.GetMaximum()
        if local_max > global_max:
            global_max = local_max

    global_max *= 10

    for hl in hist_list:
        hl.SetMaximum(global_max)

# ------------------------------------------------------------------------------
def drawCompareCanvas(background_hist_dict, signal_hist_dict, tag, out_file):
    out_file.cd()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    background_hist_dict['no_cuts'].SetLineColor(ROOT.kRed)
    background_hist_dict['cuts'   ].SetLineColor(ROOT.kRed)
    background_hist_dict['no_cuts'].SetLineWidth(3)
    background_hist_dict['cuts'   ].SetLineWidth(3)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    signal_hist_dict['no_cuts'].SetLineColor(ROOT.kBlack)
    signal_hist_dict['cuts'   ].SetLineColor(ROOT.kBlack)
    signal_hist_dict['no_cuts'].SetLineWidth(3)
    signal_hist_dict['cuts'   ].SetLineWidth(3)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    c = ROOT.TCanvas('compare__%s' % tag)
    c.Divide(1,2)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    c.cd(1)
    ROOT.gPad.SetLogy()

    setRange( [ background_hist_dict['no_cuts']
              , signal_hist_dict[    'no_cuts']
              ]
            )

    background_hist_dict['no_cuts'].Draw()
    signal_hist_dict[    'no_cuts'].Draw('SAME')

    text_no_cut_0 = ROOT.TText(0.60, 0.85, 'Only basic cleaning')
    text_no_cut_1 = ROOT.TText(0.60, 0.80, 'Background: %s'   % background_hist_dict['no_cuts'].Integral())
    text_no_cut_2 = ROOT.TText(0.60, 0.75, 'Signal: %s'       % signal_hist_dict[    'no_cuts'].Integral())
    # text_no_cut_3 = ROOT.TText(0.60, 0.70, 'S/#sqrt{S+B}: %s' % signal_hist_dict[    'no_cuts'].Integral())

    text_no_cut_0.SetNDC()
    text_no_cut_1.SetNDC()
    text_no_cut_2.SetNDC()

    text_no_cut_0.Draw()
    text_no_cut_1.Draw()
    text_no_cut_2.Draw()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    c.cd(2)
    ROOT.gPad.SetLogy()

    setRange( [ background_hist_dict['cuts']
              , signal_hist_dict[    'cuts']
              ]
            )

    background_hist_dict['cuts'].Draw()
    signal_hist_dict[    'cuts'].Draw('SAME')

    text_cut_0 = ROOT.TText(0.60, 0.85, 'Full selection')
    text_cut_1 = ROOT.TText(0.60, 0.80, 'Background: %s' % background_hist_dict['cuts'].Integral())
    text_cut_2 = ROOT.TText(0.60, 0.75, 'Signal: %s'     % signal_hist_dict[    'cuts'].Integral())

    text_cut_0.SetNDC()
    text_cut_1.SetNDC()
    text_cut_2.SetNDC()

    text_cut_0.Draw()
    text_cut_1.Draw()
    text_cut_2.Draw()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    c.Write()

# ------------------------------------------------------------------------------
def main():
    ROOT.gStyle.SetOptStat(0)

    # base_path = '${BASE_WORK_DIR}/hists/bminusl_opt_ntup_2014_06_18__19_33/'
    base_path = '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/'
    ttbar       = produceMblPlots('%s/BMinusL.117050.PowhegPythia_P2011C_ttbar.ntup.root'                         % base_path, 'ttbar')
    signal_100  = produceMblPlots('%s/BMinusL.202632.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_100.ntup.root'  % base_path, 'signal_100' )
    signal_200  = produceMblPlots('%s/BMinusL.202633.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_200.ntup.root'  % base_path, 'signal_200' )
    signal_300  = produceMblPlots('%s/BMinusL.202634.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_300.ntup.root'  % base_path, 'signal_300' )
    signal_400  = produceMblPlots('%s/BMinusL.202635.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_400.ntup.root'  % base_path, 'signal_400' )
    signal_500  = produceMblPlots('%s/BMinusL.202636.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_500.ntup.root'  % base_path, 'signal_500' )
    signal_600  = produceMblPlots('%s/BMinusL.202637.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_600.ntup.root'  % base_path, 'signal_600' )
    signal_700  = produceMblPlots('%s/BMinusL.202638.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_700.ntup.root'  % base_path, 'signal_700' )
    signal_800  = produceMblPlots('%s/BMinusL.202639.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_800.ntup.root'  % base_path, 'signal_800' )
    signal_900  = produceMblPlots('%s/BMinusL.202640.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_900.ntup.root'  % base_path, 'signal_900' )
    signal_1000 = produceMblPlots('%s/BMinusL.202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000.ntup.root' % base_path, 'signal_1000')

    out_file = ROOT.TFile.Open('out.root', 'recreate')

    drawCompareCanvas(ttbar, signal_100 , 'ttbar_T100' , out_file)
    drawCompareCanvas(ttbar, signal_200 , 'ttbar_T200' , out_file)
    drawCompareCanvas(ttbar, signal_300 , 'ttbar_T300' , out_file)
    drawCompareCanvas(ttbar, signal_400 , 'ttbar_T400' , out_file)
    drawCompareCanvas(ttbar, signal_500 , 'ttbar_T500' , out_file)
    drawCompareCanvas(ttbar, signal_600 , 'ttbar_T600' , out_file)
    drawCompareCanvas(ttbar, signal_700 , 'ttbar_T700' , out_file)
    drawCompareCanvas(ttbar, signal_800 , 'ttbar_T800' , out_file)
    drawCompareCanvas(ttbar, signal_900 , 'ttbar_T900' , out_file)
    drawCompareCanvas(ttbar, signal_1000, 'ttbar_T1000', out_file)

    out_file.Close()

# ==============================================================================
if __name__ == "__main__":
    main()
