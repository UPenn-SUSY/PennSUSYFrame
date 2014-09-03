#!/usr/bin/env python

# ==============================================================================
import math
import sys
import ROOT
import array

# ------------------------------------------------------------------------------
cut_level = sys.argv[1] if len(sys.argv) > 1 else ''
print 'cut level: "%s"' % cut_level

# ------------------------------------------------------------------------------
mbl_bins = [0, 50, 100, 200, 300, 450, 600, 1500]

# ------------------------------------------------------------------------------
def recoverOverflow(h):
    print 'recoverOverflow()'

    # get the total number of bins and entries
    total_bins = h.GetNbinsX()
    total_entries = h.GetEntries()
    print '\ttotal bins: %s' % total_bins
    print '\ttotal entries: %s' % total_entries

    # find the bin edges
    x_bins = [h.GetBinLowEdge(i+1) for i in xrange(total_bins)]
    print '\tx bins: %s' % x_bins

    # get the number of entries from the overflow bin
    overflow = h.GetBinContent(total_bins+1)
    print '\toverflow: %s' % overflow

    # move the overflow bin to the last bin in the plot
    print '\tsetting overflow (bin %s) to 0' % (total_bins+1)
    h.SetBinContent(total_bins+1, 0)
    print '\tfilling last bin (%s, x=%s) with the overflow (%s)' % (total_bins-1, x_bins[total_bins-1], overflow)
    h.Fill(x_bins[total_bins-1], overflow)


    # fix the number of entries
    h.SetEntries(total_entries)

# ------------------------------------------------------------------------------
def prepareForPlotting(h_dict, syst_frac_unc):
    h_raw     = h_dict['raw']
    h_weights = h_dict['weights']

    recoverOverflow(h_raw    )
    recoverOverflow(h_weights)

    num_bins = h_weights.GetNbinsX()
    for x_bin in xrange(1,num_bins+1):
        x_val = h_weights.GetXaxis().GetBinLowEdge(x_bin)

        num_raw    = h_raw.GetBinContent(    x_bin)
        num_weight = h_weights.GetBinContent(x_bin)

        stat_unc = num_weight/math.sqrt(num_raw) if num_raw > 0 else 0
        syst_unc = syst_frac_unc*num_weight

        total_unc = math.sqrt(stat_unc**2 + syst_unc**2)
        h_weights.SetBinError(x_bin, total_unc)

    uncert_graph =  ROOT.TGraphErrors(h_weights)
    uncert_graph.SetFillColor(ROOT.kAzure)
    uncert_graph.SetFillStyle(3001)
    return uncert_graph

# ------------------------------------------------------------------------------
def passCuts(event, cut_type = ''):
    mbl_asym = (event.mbl_0 - event.mbl_1) / (event.mbl_0 + event.mbl_1)
    ht = event.ht_signal
    met_sig = event.met_et/math.sqrt(ht)

    mbl_cut_600  = 0.5913
    mbl_cut_700  = 0.6863
    mbl_cut_800  = 0.5540
    mbl_cut_900  = 0.6770
    mbl_cut_1000 = 0.6567
    mbl_cut_test = 0.3

    mbl_cut_cand_sr = 0.6

    ht_cut_600  = 433.1818
    ht_cut_700  = 527.3617
    ht_cut_800  = 589.8870
    ht_cut_900  = 683.0847
    ht_cut_1000 = 882.0773
    ht_cut_test = 100

    ht_cut_cand_sr_100 = 100
    ht_cut_cand_sr_200 = 200
    ht_cut_cand_sr_300 = 300
    ht_cut_cand_sr_400 = 400
    ht_cut_cand_sr_500 = 500
    ht_cut_cand_sr_600 = 600
    ht_cut_cand_sr_700 = 700

    met_cut_600  = 20.5685
    met_cut_700  = 33.1530
    met_cut_800  = 44.1847
    met_cut_900  = 65.3685
    met_cut_1000 = 36.9973
    met_cut_test = 10

    met_cut_cand_sr = 7.

    if cut_type == '600':
        # 600
        if mbl_asym > mbl_cut_600 : return False
        if ht       < ht_cut_600  : return False
        if met_sig  > met_cut_600 : return False
        return True
    if cut_type == '600_mbl':
        if mbl_asym > mbl_cut_600 : return False
        return True
    if cut_type == '600_ht':
        if ht       < ht_cut_600  : return False
        return True
    if cut_type == '600_met':
        if met_sig  > met_cut_600 : return False
        return True

    if cut_type == '700':
        # 700
        if mbl_asym > mbl_cut_700 : return False
        if ht       < ht_cut_700  : return False
        if met_sig  > met_cut_700 : return False
        return True
    if cut_type == '700_mbl':
        if mbl_asym > mbl_cut_700 : return False
        return True
    if cut_type == '700_ht':
        if ht       < ht_cut_700  : return False
        return True
    if cut_type == '700_met':
        if met_sig  > met_cut_700 : return False
        return True

    if cut_type == '800':
        # 800
        if mbl_asym > mbl_cut_800 : return False
        if ht       < ht_cut_800  : return False
        if met_sig  > met_cut_800 : return False
        return True
    if cut_type == '800_mbl':
        if mbl_asym > mbl_cut_800 : return False
        return True
    if cut_type == '800_ht':
        if ht       < ht_cut_800  : return False
        return True
    if cut_type == '800_met':
        if met_sig  > met_cut_800 : return False
        return True

    if cut_type == '900':
        # 900
        if mbl_asym > mbl_cut_900 : return False
        if ht       < ht_cut_900  : return False
        if met_sig  > met_cut_900 : return False
        return True
    if cut_type == '900_mbl':
        if mbl_asym > mbl_cut_900 : return False
        return True
    if cut_type == '900_ht':
        if ht       < ht_cut_900  : return False
        return True
    if cut_type == '900_met':
        if met_sig  > met_cut_900 : return False
        return True

    if cut_type == '1000':
        # 1000
        if mbl_asym > mbl_cut_1000 : return False
        if ht       < ht_cut_1000  : return False
        if met_sig  > met_cut_1000 : return False
        return True
    if cut_type == '1000_mbl':
        if mbl_asym > mbl_cut_1000 : return False
        return True
    if cut_type == '1000_ht':
        if ht       < ht_cut_1000  : return False
        return True
    if cut_type == '1000_met':
        if met_sig  > met_cut_1000 : return False
        return True

    if cut_type == 'cand_sr_100':
        # sr_cand_100
        if mbl_asym > mbl_cut_cand_sr    : return False
        if ht       < ht_cut_cand_sr_100 : return False
        if met_sig  > met_cut_cand_sr    : return False
        return True
    if cut_type == 'cand_sr_100_mbl':
        if mbl_asym > mbl_cut_cand_sr : return False
        return True
    if cut_type == 'cand_sr_100_ht':
        if ht       < ht_cut_cand_sr_100  : return False
        return True
    if cut_type == 'cand_sr_100_met':
        if met_sig  > met_cut_cand_sr : return False
        return True

    if cut_type == 'cand_sr_200':
        # sr_cand_200
        if mbl_asym > mbl_cut_cand_sr    : return False
        if ht       < ht_cut_cand_sr_200 : return False
        if met_sig  > met_cut_cand_sr    : return False
        return True
    if cut_type == 'cand_sr_200_mbl':
        if mbl_asym > mbl_cut_cand_sr : return False
        return True
    if cut_type == 'cand_sr_200_ht':
        if ht       < ht_cut_cand_sr_200  : return False
        return True
    if cut_type == 'cand_sr_200_met':
        if met_sig  > met_cut_cand_sr : return False
        return True

    if cut_type == 'cand_sr_300':
        # sr_cand_300
        if mbl_asym > mbl_cut_cand_sr    : return False
        if ht       < ht_cut_cand_sr_300 : return False
        if met_sig  > met_cut_cand_sr    : return False
        return True
    if cut_type == 'cand_sr_300_mbl':
        if mbl_asym > mbl_cut_cand_sr : return False
        return True
    if cut_type == 'cand_sr_300_ht':
        if ht       < ht_cut_cand_sr_300  : return False
        return True
    if cut_type == 'cand_sr_300_met':
        if met_sig  > met_cut_cand_sr : return False
        return True

    if cut_type == 'cand_sr_400':
        # sr_cand_400
        if mbl_asym > mbl_cut_cand_sr    : return False
        if ht       < ht_cut_cand_sr_400 : return False
        if met_sig  > met_cut_cand_sr    : return False
        return True
    if cut_type == 'cand_sr_400_mbl':
        if mbl_asym > mbl_cut_cand_sr : return False
        return True
    if cut_type == 'cand_sr_400_ht':
        if ht       < ht_cut_cand_sr_400  : return False
        return True
    if cut_type == 'cand_sr_400_met':
        if met_sig  > met_cut_cand_sr : return False
        return True

    if cut_type == 'cand_sr_500':
        # sr_cand_500
        if mbl_asym > mbl_cut_cand_sr    : return False
        if ht       < ht_cut_cand_sr_500 : return False
        if met_sig  > met_cut_cand_sr    : return False
        return True
    if cut_type == 'cand_sr_500_mbl':
        if mbl_asym > mbl_cut_cand_sr : return False
        return True
    if cut_type == 'cand_sr_500_ht':
        if ht       < ht_cut_cand_sr_500  : return False
        return True
    if cut_type == 'cand_sr_500_met':
        if met_sig  > met_cut_cand_sr : return False
        return True

    if cut_type == 'cand_sr_600':
        # sr_cand_600
        if mbl_asym > mbl_cut_cand_sr    : return False
        if ht       < ht_cut_cand_sr_600 : return False
        if met_sig  > met_cut_cand_sr    : return False
        return True
    if cut_type == 'cand_sr_600_mbl':
        if mbl_asym > mbl_cut_cand_sr : return False
        return True
    if cut_type == 'cand_sr_600_ht':
        if ht       < ht_cut_cand_sr_600  : return False
        return True
    if cut_type == 'cand_sr_600_met':
        if met_sig  > met_cut_cand_sr : return False
        return True

    if cut_type == 'cand_sr_700':
        # sr_cand_700
        if mbl_asym > mbl_cut_cand_sr    : return False
        if ht       < ht_cut_cand_sr_700 : return False
        if met_sig  > met_cut_cand_sr    : return False
        return True
    if cut_type == 'cand_sr_700_mbl':
        if mbl_asym > mbl_cut_cand_sr : return False
        return True
    if cut_type == 'cand_sr_700_ht':
        if ht       < ht_cut_cand_sr_700  : return False
        return True
    if cut_type == 'cand_sr_700_met':
        if met_sig  > met_cut_cand_sr : return False
        return True

    if cut_type == 'test':
        # test
        if mbl_asym > mbl_cut_test : return False
        if ht       < ht_cut_test  : return False
        if met_sig  > met_cut_test : return False
        return True
    if cut_type == 'test_mbl':
        if mbl_asym > mbl_cut_test : return False
        return True
    if cut_type == 'test_ht':
        if ht       < ht_cut_test  : return False
        return True
    if cut_type == 'test_met':
        if met_sig  > met_cut_test : return False
        return True

    print 'bogus'
    # bogus
    if (event.mbl_0 - event.mbl_1) / (event.mbl_0 + event.mbl_1) > 1 : return False
    if event.ht_signal < 1000: return False
    if event.met_et/math.sqrt(event.ht_signal) > 100 : return False
    return True

# ------------------------------------------------------------------------------
def produceMblPlots(in_file_name, tag):
    print 'getting mbl plot for ', tag

    f = ROOT.TFile.Open(in_file_name)
    t = f.Get("optimize")

    h_mbl_no_cut = ROOT.TH1D( 'mbl_no_cut__%s' % tag
                            , 'mbl_no_cut__%s ; m_{bl} [GeV] ; bl pairs' % tag
                            , len(mbl_bins)-1, array.array('d', mbl_bins)
                            )
    h_ht_no_cut = ROOT.TH1D( 'ht_no_cut__%s' % tag
                           , 'ht_no_cut__%s ; h_{T} [GeV] ; Entries / 10 GeV' % tag
                           , 50, 0, 5000
                           # , 50, 0, 50
                           )
    h_met_sig_no_cut = ROOT.TH1D( 'met_sig_no_cut__%s' % tag
                                , 'met_sig_no_cut__%s ; E_{T}^{miss}/#sqrt{h_{T}} [GeV^{1/2}] ; Entries / 10 GeV' % tag
                                , 50, 0, 50
                                )

    h_raw_mbl_no_cut = ROOT.TH1D( 'raw_mbl_no_cut__%s' % tag
                                , 'raw_mbl_no_cut__%s ; m_{bl} [GeV] ; bl pairs' % tag
                                , len(mbl_bins)-1, array.array('d', mbl_bins)
                                )
    h_raw_ht_no_cut = ROOT.TH1D( 'raw_ht_no_cut__%s' % tag
                               , 'raw_ht_no_cut__%s ; h_{T} [GeV] ; Entries / 10 GeV' % tag
                               , 50, 0, 5000
                               # , 50, 0, 50
                               )
    h_raw_met_sig_no_cut = ROOT.TH1D( 'raw_met_sig_no_cut__%s' % tag
                                    , 'raw_met_sig_no_cut__%s ; E_{T}^{miss}/#sqrt{h_{T}} [GeV^{1/2}] ; Entries / 10 GeV' % tag
                                    , 50, 0, 50
                                    )

    h_mbl_w_cut = ROOT.TH1D( 'mbl_w_cut__%s' % tag
                           , 'mbl_w_cut__%s ; m_{bl} [GeV] ; bl pairs' % tag
                           , len(mbl_bins)-1, array.array('d', mbl_bins)
                           )
    h_ht_w_cut = ROOT.TH1D( 'ht_w_cut__%s' % tag
                          , 'ht_w_cut__%s ; h_{T} [GeV] ; Entries / 10 GeV^{1/2}' % tag
                          , 50, 0, 5000
                          # , 50, 0, 50
                          )
    h_met_sig_w_cut = ROOT.TH1D( 'met_sig_w_cut__%s' % tag
                               , 'met_sig_w_cut__%s ; E_{T}^{miss}/#sqrt{h_{T}} [GeV^{1/2}] ; Entries / 10 GeV^{1/2}' % tag
                               , 50, 0, 50
                               )

    h_raw_mbl_w_cut = ROOT.TH1D( 'raw_mbl_w_cut__%s' % tag
                               , 'raw_mbl_w_cut__%s ; m_{bl} [GeV] ; bl pairs' % tag
                               , len(mbl_bins)-1, array.array('d', mbl_bins)
                               )
    h_raw_ht_w_cut = ROOT.TH1D( 'raw_ht_w_cut__%s' % tag
                              , 'raw_ht_w_cut__%s ; h_{T} [GeV] ; Entries / 10 GeV^{1/2}' % tag
                              , 50, 0, 5000
                              # , 50, 0, 50
                              )
    h_raw_met_sig_w_cut = ROOT.TH1D( 'raw_met_sig_w_cut__%s' % tag
                                   , 'raw_met_sig_w_cut__%s ; E_{T}^{miss}/#sqrt{h_{T}} [GeV^{1/2}] ; Entries / 10 GeV^{1/2}' % tag
                                   , 50, 0, 50
                                   )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    event_counter = 0
    for event in t:
        event_counter+=1
        # if event_counter == 1000: break

        weight = 21000*event.weight
        # weight = event.weight
        h_raw_mbl_no_cut.Fill(    event.mbl_0                            )
        h_raw_mbl_no_cut.Fill(    event.mbl_1                            )
        h_raw_ht_no_cut.Fill(     event.ht_signal                        )
        h_raw_met_sig_no_cut.Fill(event.met_et/math.sqrt(event.ht_signal))

        h_mbl_no_cut.Fill(    event.mbl_0                            , weight)
        h_mbl_no_cut.Fill(    event.mbl_1                            , weight)
        h_ht_no_cut.Fill(     event.ht_signal                        , weight)
        h_met_sig_no_cut.Fill(event.met_et/math.sqrt(event.ht_signal), weight)

        if (passCuts(event, cut_level)):
            h_raw_mbl_w_cut.Fill(    event.mbl_0                            )
            h_raw_mbl_w_cut.Fill(    event.mbl_1                            )
            h_raw_ht_w_cut.Fill(     event.ht_signal                        )
            h_raw_met_sig_w_cut.Fill(event.met_et/math.sqrt(event.ht_signal))

            h_mbl_w_cut.Fill(    event.mbl_0                            , weight)
            h_mbl_w_cut.Fill(    event.mbl_1                            , weight)
            h_ht_w_cut.Fill(     event.ht_signal                        , weight)
            h_met_sig_w_cut.Fill(event.met_et/math.sqrt(event.ht_signal), weight)

    print '# entries before cut: ' , h_mbl_no_cut.GetEntries()
    print '# entries after cut:  ' , h_mbl_w_cut.GetEntries()

    print '# integral before cut: ' , h_mbl_no_cut.Integral()
    print '# integral after cut:  ' , h_mbl_w_cut.Integral()

    print ''

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    return { 'mbl__no_cuts':{    'weights':h_mbl_no_cut    , 'raw':h_raw_mbl_no_cut}
           , 'ht__no_cuts':{     'weights':h_ht_no_cut     , 'raw':h_ht_no_cut     }
           , 'met_sig__no_cuts':{'weights':h_met_sig_no_cut, 'raw':h_met_sig_no_cut}
           , 'mbl__w_cuts':{     'weights':h_mbl_w_cut     , 'raw':h_mbl_w_cut     }
           , 'ht__w_cuts':{      'weights':h_ht_w_cut      , 'raw':h_ht_w_cut      }
           , 'met_sig__w_cuts':{ 'weights':h_met_sig_w_cut , 'raw':h_met_sig_w_cut }
           }

# ------------------------------------------------------------------------------
def setRange(hist_list):
    global_min = 999
    global_max = 0
    x_bins = hist_list[0].GetXaxis().GetNbins()
    for hl in hist_list:
        local_min = 999
        local_max = 0
        for i in xrange(1, x_bins+1):
            this_entry = hl.GetBinContent(i)
            if this_entry < local_min and this_entry > 0: local_min = this_entry
            if this_entry > local_max: local_max = this_entry
        if local_min < global_min: global_min = local_min
        if local_max > global_max: global_max = local_max

    x_min = hist_list[0].GetXaxis().GetXmin()
    x_max = hist_list[0].GetXaxis().GetXmax()

    y_min_for_plot = math.pow(10, ( math.log(global_min, 10) - (math.log(global_max, 10) - math.log(global_min, 10))*0.20))
    y_max_for_plot = math.pow(10, ( math.log(global_min, 10) + (math.log(global_max, 10) - math.log(global_min, 10))*1.20))

    name = 'frame__%s' %  hist_list[0].GetName()
    title = hist_list[0].GetTitle()
    x_label = hist_list[0].GetXaxis().GetTitle()
    y_label = hist_list[0].GetYaxis().GetTitle()
    frame = ROOT.TH1I( name
                     , '%s ; %s ; %s' % (title, x_label, y_label)
                     , 1
                     , x_min
                     , x_max
                     )
    frame.GetYaxis().SetRangeUser(y_min_for_plot, y_max_for_plot)
    # frame.SetMaximum(global_max)

    return frame

# ------------------------------------------------------------------------------
def drawCompareCanvas( background_hist_dict
                     , signal_hist_dict
                     , hist_name
                     , tag
                     , out_file
                     ):
    out_file.cd()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bkg_no_cuts = background_hist_dict['%s__no_cuts' % hist_name]['weights']
    bkg_w_cuts  = background_hist_dict['%s__w_cuts'  % hist_name]['weights']

    sig_no_cuts = signal_hist_dict['%s__no_cuts' % hist_name]['weights']
    sig_w_cuts  = signal_hist_dict['%s__w_cuts'  % hist_name]['weights']

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bkg_no_cuts_uncert = prepareForPlotting(background_hist_dict['%s__no_cuts' % hist_name], 0.30)
    bkg_w_cuts_uncert  = prepareForPlotting(background_hist_dict['%s__w_cuts'  % hist_name], 0.30)

    sig_no_cuts_uncert = prepareForPlotting(signal_hist_dict['%s__no_cuts' % hist_name], 0.0)
    sig_w_cuts_uncert  = prepareForPlotting(signal_hist_dict['%s__w_cuts'  % hist_name], 0.0)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    bkg_no_cuts.SetLineColor(ROOT.kBlue)
    bkg_w_cuts.SetLineColor( ROOT.kBlue)

    bkg_no_cuts.SetLineWidth(3)
    bkg_w_cuts.SetLineWidth( 3)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    sig_no_cuts.SetLineColor(ROOT.kRed)
    sig_w_cuts.SetLineColor( ROOT.kRed)

    sig_no_cuts.SetLineWidth(3)
    sig_w_cuts.SetLineWidth( 3)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    c = ROOT.TCanvas('compare__%s__%s' % (hist_name, tag))
    c.Divide(1,2)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    c.cd(1)
    ROOT.gPad.SetLogy()

    frame = setRange( [ bkg_no_cuts
                      , sig_no_cuts
                      ]
                    )

    frame.Draw()
    bkg_no_cuts.Draw('histSAME')
    sig_no_cuts.Draw('histSAME')
    bkg_no_cuts_uncert.Draw('2')
    # sig_no_cuts_uncert.Draw('a2SAME')

    b_entries_no_cuts = bkg_no_cuts.GetEntries()
    s_entries_no_cuts = sig_no_cuts.GetEntries()

    b_int_no_cuts = bkg_no_cuts.Integral()
    s_int_no_cuts = sig_no_cuts.Integral()

    bkg_stat_uncert_no_cuts = 1/math.sqrt(b_entries_no_cuts)
    bkg_syst_uncert_no_cuts = 0.30
    bkg_total_uncert_no_cuts = math.sqrt(bkg_stat_uncert_no_cuts**2 + bkg_syst_uncert_no_cuts**2)
    zn_no_cuts = 0

    text_no_cut_0 = ROOT.TText(0.60, 0.85, 'Only basic cleaning')
    text_no_cut_1 = ROOT.TText(0.60, 0.80, 'Background: %0.2f (raw: %d)'   % (b_int_no_cuts, b_entries_no_cuts))
    text_no_cut_2 = ROOT.TText(0.60, 0.75, 'Signal: %0.2f (raw: %d)'       % (s_int_no_cuts, s_entries_no_cuts))
    text_no_cut_3 = ROOT.TText(0.60, 0.70, 'S/#sqrt{S+B}: %0.2f' % \
            ( s_int_no_cuts/ math.sqrt( s_int_no_cuts + b_int_no_cuts ) ) if (s_int_no_cuts + b_int_no_cuts) > 0 else 0 )
    text_no_cut_4 = ROOT.TText(0.60, 0.65, 'Zn: %0.2f' % zn_no_cuts)

    text_no_cut_1.SetTextColor(ROOT.kBlue)
    text_no_cut_2.SetTextColor(ROOT.kRed)

    text_no_cut_0.SetNDC()
    text_no_cut_1.SetNDC()
    text_no_cut_2.SetNDC()
    text_no_cut_3.SetNDC()
    text_no_cut_4.SetNDC()

    text_no_cut_0.Draw()
    text_no_cut_1.Draw()
    text_no_cut_2.Draw()
    text_no_cut_3.Draw()
    text_no_cut_4.Draw()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    c.cd(2)
    ROOT.gPad.SetLogy()

    setRange( [ bkg_w_cuts
              , sig_w_cuts
              ]
            )

    frame.Draw()
    bkg_w_cuts.Draw('histSAME')
    sig_w_cuts.Draw('histSAME')
    bkg_w_cuts_uncert.Draw('2')

    b_entries_cuts = bkg_w_cuts.GetEntries()
    s_entries_cuts = sig_w_cuts.GetEntries()

    b_int_cuts = bkg_w_cuts.Integral()
    s_int_cuts = sig_w_cuts.Integral()

    bkg_stat_uncert_cuts = 1/math.sqrt(b_entries_cuts)
    bkg_syst_uncert_cuts = 0.30
    bkg_total_uncert_cuts = math.sqrt(bkg_stat_uncert_cuts**2 + bkg_syst_uncert_cuts**2)
    zn_cuts = 0


    text_cut_0 = ROOT.TText(0.60, 0.85, 'Full selection')
    text_cut_1 = ROOT.TText(0.60, 0.80, 'Background: %0.2f (raw: %d)' % (b_int_cuts, b_entries_cuts))
    text_cut_2 = ROOT.TText(0.60, 0.75, 'Signal: %0.2f (raw: %d)'     % (s_int_cuts, s_entries_cuts))
    text_cut_3 = ROOT.TText(0.60, 0.70, 'S/#sqrt{S+B}: %0.2f' % \
            ( s_int_cuts/ math.sqrt( s_int_cuts + b_int_cuts ) ) if (s_int_cuts + b_int_cuts) > 0 else 0 )
    text_cut_4 = ROOT.TText(0.60, 0.65, 'Zn: %0.2f' % zn_cuts)

    text_cut_1.SetTextColor(ROOT.kBlue)
    text_cut_2.SetTextColor(ROOT.kRed)

    text_cut_0.SetNDC()
    text_cut_1.SetNDC()
    text_cut_2.SetNDC()
    text_cut_3.SetNDC()
    text_cut_4.SetNDC()

    text_cut_0.Draw()
    text_cut_1.Draw()
    text_cut_2.Draw()
    text_cut_3.Draw()
    text_cut_4.Draw()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    c.Write()

# ------------------------------------------------------------------------------
def main():
    ROOT.gStyle.SetOptStat(0)

    base_path = '${BASE_WORK_DIR}/NextOptNtupDir.BMinusL/'

    ttbar       = produceMblPlots('%s/BMinusL.117050.PowhegPythia_P2011C_ttbar.af2_v2.ntup.root'                  % base_path, 'ttbar')
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

    drawCompareCanvas(ttbar, signal_100 , 'mbl', 'ttbar_T100' , out_file)
    drawCompareCanvas(ttbar, signal_200 , 'mbl', 'ttbar_T200' , out_file)
    drawCompareCanvas(ttbar, signal_300 , 'mbl', 'ttbar_T300' , out_file)
    drawCompareCanvas(ttbar, signal_400 , 'mbl', 'ttbar_T400' , out_file)
    drawCompareCanvas(ttbar, signal_500 , 'mbl', 'ttbar_T500' , out_file)
    drawCompareCanvas(ttbar, signal_600 , 'mbl', 'ttbar_T600' , out_file)
    drawCompareCanvas(ttbar, signal_700 , 'mbl', 'ttbar_T700' , out_file)
    drawCompareCanvas(ttbar, signal_800 , 'mbl', 'ttbar_T800' , out_file)
    drawCompareCanvas(ttbar, signal_900 , 'mbl', 'ttbar_T900' , out_file)
    drawCompareCanvas(ttbar, signal_1000, 'mbl', 'ttbar_T1000', out_file)

    drawCompareCanvas(ttbar, signal_100 , 'ht', 'ttbar_T100' , out_file)
    drawCompareCanvas(ttbar, signal_200 , 'ht', 'ttbar_T200' , out_file)
    drawCompareCanvas(ttbar, signal_300 , 'ht', 'ttbar_T300' , out_file)
    drawCompareCanvas(ttbar, signal_400 , 'ht', 'ttbar_T400' , out_file)
    drawCompareCanvas(ttbar, signal_500 , 'ht', 'ttbar_T500' , out_file)
    drawCompareCanvas(ttbar, signal_600 , 'ht', 'ttbar_T600' , out_file)
    drawCompareCanvas(ttbar, signal_700 , 'ht', 'ttbar_T700' , out_file)
    drawCompareCanvas(ttbar, signal_800 , 'ht', 'ttbar_T800' , out_file)
    drawCompareCanvas(ttbar, signal_900 , 'ht', 'ttbar_T900' , out_file)
    drawCompareCanvas(ttbar, signal_1000, 'ht', 'ttbar_T1000', out_file)

    drawCompareCanvas(ttbar, signal_100 , 'met_sig', 'ttbar_T100' , out_file)
    drawCompareCanvas(ttbar, signal_200 , 'met_sig', 'ttbar_T200' , out_file)
    drawCompareCanvas(ttbar, signal_300 , 'met_sig', 'ttbar_T300' , out_file)
    drawCompareCanvas(ttbar, signal_400 , 'met_sig', 'ttbar_T400' , out_file)
    drawCompareCanvas(ttbar, signal_500 , 'met_sig', 'ttbar_T500' , out_file)
    drawCompareCanvas(ttbar, signal_600 , 'met_sig', 'ttbar_T600' , out_file)
    drawCompareCanvas(ttbar, signal_700 , 'met_sig', 'ttbar_T700' , out_file)
    drawCompareCanvas(ttbar, signal_800 , 'met_sig', 'ttbar_T800' , out_file)
    drawCompareCanvas(ttbar, signal_900 , 'met_sig', 'ttbar_T900' , out_file)
    drawCompareCanvas(ttbar, signal_1000, 'met_sig', 'ttbar_T1000', out_file)

    out_file.Close()

# ==============================================================================
if __name__ == "__main__":
    main()
