#!/usr/bin/env python

import sys
import os.path
import optparse
import time

import ROOT
import rootlogon
import metaroot

# ==============================================================================
color_list = [ ROOT.kBlue
             , ROOT.kGreen
             , ROOT.kRed
             , ROOT.kCyan
             , ROOT.kMagenta
             , ROOT.kOrange
             , ROOT.kPink-4
             ]

# ------------------------------------------------------------------------------
def normalizeHist(h):
    if h.Integral() > 0: h.Scale( 1./h.Integral())

# ------------------------------------------------------------------------------
def truncateXaxis(h, new_x_min = None, new_x_max = None):
    total_bins = h.GetNbinsX()
    underflow = h.GetBinContent(0)
    overflow  = h.GetBinContent(total_bins+1)

    if new_x_min is None: new_x_min = h.GetXaxis().GetXmin()
    if new_x_max is None: new_x_max = h.GetXaxis().GetXmax()
    h.GetXaxis().SetRangeUser(new_x_min, new_x_max)
    moveOverflowToLastBin(h, new_x_min, new_x_max)

# ------------------------------------------------------------------------------
def moveOverflowToLastBin(h, x_min, x_max):
    total_bins = h.GetNbinsX()
    total_entries = h.GetEntries()
    x_bins = []
    for i in xrange(total_bins):
        x_bins.append(h.GetBinLowEdge(i+1))

    # find total underflow
    underflow = h.GetBinContent(0)
    min_bin = 1
    for i, x in enumerate(x_bins):
        if x < x_min:
            underflow += h.GetBinContent(i+1)
        else:
            min_bin = i+1
            break

    # move underflow to min_bin:
    for uf_bin in xrange(min_bin):
        h.SetBinContent(uf_bin, 0.)
    h.Fill(x_bins[min_bin-1], underflow)

    # find total overflow
    overflow = h.GetBinContent(total_bins+1)
    max_bin = 1
    for i, x in enumerate(x_bins):
        if x < x_max:
            max_bin = i+1
            continue
        overflow += h.GetBinContent(i+1)

    # move overflow to max_bin:
    for of_bin in xrange(max_bin+1, total_bins+2):
        h.SetBinContent(of_bin, 0.)
    h.Fill(x_bins[max_bin-1], overflow)

    h.SetEntries(total_entries)

# ------------------------------------------------------------------------------
class FileHandle(object):
    def __init__( self
                , file_name
                , label
                , color
                , draw_el_re=True
                , draw_el_fr=True
                , draw_mu_re=True
                , draw_mu_fr=True
                ):
        self.file_name = file_name
        self.file = ROOT.TFile.Open(file_name)
        self.label = label
        self.color = color
        self.draw_el_re = draw_el_re
        self.draw_el_fr = draw_el_fr
        self.draw_mu_re = draw_mu_re
        self.draw_mu_fr = draw_mu_fr

    def getHist(self, hist_name, normalize):
        print 'getting hist: %s from file: %s' % (hist_name, self.file_name)
        h = self.file.Get(hist_name)
        if normalize:
            normalizeHist(h)
        h.SetLineColor(self.color)
        h.SetLineWidth(3)
        return h

# ------------------------------------------------------------------------------
def safeMakeDir(f, d):
    f.cd()
    for k in f.GetListOfKeys():
        if d == k.GetName():
            f.cd(d)
            return
    f.mkdir(d)
    f.cd(d)

# ------------------------------------------------------------------------------
def formatHist(h, color, x_title = 'p_{T} [GeV]', y_title = 'rate'):
    h.SetLineColor(color)
    h.SetLineWidth(3)
    h.GetXaxis().SetTitle(x_title)
    h.GetYaxis().SetTitle(y_title)

# ------------------------------------------------------------------------------
def makeLegend(hist_list, label_list):
    leg_x1 = 0.80
    leg_x2 = 0.98
    leg_y1 = 0.98
    leg_y2 = leg_y1-(0.06*len(hist_list))
    if leg_y2 < 0.20: leg_y2 = 0.20

    big_leg_x1 = 0.05
    big_leg_x2 = 0.95
    big_leg_y1 = 0.98
    big_leg_y2 = leg_y1-(0.08*len(hist_list))
    if big_leg_y2 < 0.05: big_leg_y2 = 0.05

    leg     = ROOT.TLegend(leg_x1, leg_y1, leg_x2, leg_y2)
    big_leg = ROOT.TLegend(big_leg_x1, big_leg_y1, big_leg_x2, big_leg_y2)

    leg.SetFillColor(0)
    big_leg.SetFillColor(0)

    for h, l in zip(hist_list, label_list):
        this_label = '%s' % l
        leg.AddEntry(    h, this_label)
        big_leg.AddEntry(h, this_label)

    return leg, big_leg

# ------------------------------------------------------------------------------
def makeLegendFHL(file_handle_list, hist_name):
    leg_x1 = 0.80
    leg_x2 = 0.98
    leg_y1 = 0.98
    leg_y2 = leg_y1-(0.06*len(file_handle_list))

    big_leg_x1 = 0.05
    big_leg_x2 = 0.95
    big_leg_y1 = 0.98
    big_leg_y2 = leg_y1-(0.08*len(file_handle_list))

    leg     = ROOT.TLegend(leg_x1, leg_y1, leg_x2, leg_y2)
    big_leg = ROOT.TLegend(big_leg_x1, big_leg_y1, big_leg_x2, big_leg_y2)

    for fhl in file_handle_list:
        h = fhl.getHist(hist_name, False)
        leg.AddEntry(    h, fhl.label)
        big_leg.AddEntry(h, fhl.label)

    return leg, big_leg

# ------------------------------------------------------------------------------
def getHistStack( file_handles
                , hist_name
                , stack_name
                , stack_title
                ):
    hist_list = []
    label_list = []
    ths = ROOT.THStack(stack_name, stack_title)
    for fh in file_handles:
        if  'el_re' in hist_name and not fh.draw_el_re: continue
        if  'el_fr' in hist_name and not fh.draw_el_fr: continue
        if  'mu_re' in hist_name and not fh.draw_mu_re: continue
        if  'mu_fr' in hist_name and not fh.draw_mu_fr: continue

        h = fh.getHist(hist_name, False)
        ths.Add(h)
        hist_list.append(h)
        label_list.append(fh.label)

    leg, big_leg = makeLegend(hist_list, label_list)

    return ths, leg, big_leg

# ------------------------------------------------------------------------------
def getHistStack2D( file_handles
                  , hist_name
                  , stack_name
                  , stack_title
                  ):
    hist_list_2d = []
    label_list = []
    ths_list = []
    num_slices = 0
    for fh in file_handles:
        if  'el_re' in hist_name and not fh.draw_el_re: continue
        if  'el_fr' in hist_name and not fh.draw_el_fr: continue
        if  'mu_re' in hist_name and not fh.draw_mu_re: continue
        if  'mu_fr' in hist_name and not fh.draw_mu_fr: continue

        h_2d = fh.getHist(hist_name, False)
        this_num_slices = h_2d.GetNbinsY()
        if num_slices == 0:
            num_slices = this_num_slices
            ths_list = [ ROOT.THStack( '%s__slice_%d' % (stack_name, slice)
                                     , '%s - slice %d' % (stack_title,slice)
                                     )
                         for slice in xrange(1, num_slices+1)
                       ]
        assert  this_num_slices == num_slices

        for slice in xrange(num_slices):
            h_tmp = h_2d.ProjectionX( '%s_%s__slice_%d' % ( h_2d.GetName()
                                                          , fh.label
                                                          , slice
                                                          )
                                    , slice+1,slice+1
                                    )
            h_tmp.SetLineWidth(3)
            ths_list[slice].Add(h_tmp)

        hist_list_2d.append(h_2d)
        label_list.append(fh.label)

    leg, big_leg = makeLegend(hist_list_2d, label_list)
    return ths_list, leg, big_leg

# ------------------------------------------------------------------------------
def getHistStack2DSingleSample( file_handles
                              , hist_name
                              , stack_name
                              , stack_title
                              , slice_variable_name = None
                              ):
    ths_list = []
    leg_list = []
    big_leg_list = []
    for fh in file_handles:
        hist_list = []
        label_list = []

        h_2d = fh.getHist(hist_name, True)
        this_num_slices = h_2d.GetNbinsY()
        tmp_ths = ROOT.THStack( '%s__%s' % (stack_name, fh.label)
                              , '%s - %s' % (stack_title, fh.label)
                              )

        for slice in xrange(this_num_slices):
            h_tmp = h_2d.ProjectionX( '%s_%s__ss__slice_%d' % ( h_2d.GetName()
                                                              , fh.label
                                                              , slice
                                                              )
                                    , slice+1,slice+1
                                    )
            normalizeHist(h_tmp)
            h_tmp.SetLineWidth(3)
            h_tmp.SetLineColor(color_list[slice])

            tmp_ths.Add(h_tmp)
            hist_list.append(h_tmp)
            if slice_variable_name is None:
                label_list.append('slice %d' % slice)
            else:
                low_edge = h_2d.GetYaxis().GetBinLowEdge(slice+1)
                up_edge = h_2d.GetYaxis().GetBinUpEdge(slice+1)
                label_list.append('%s < %s < %s' % (low_edge, slice_variable_name, up_edge))

        tmp_leg, tmp_big_leg = makeLegend(hist_list, label_list)
        ths_list.append(tmp_ths)
        leg_list.append(tmp_leg)
        big_leg_list.append(tmp_big_leg)

    return ths_list, leg_list, big_leg_list

# ------------------------------------------------------------------------------
def printToCanvas( ths = None
                 , leg = None
                 , canvas_name = 'c'
                 , labels = None
                 , x_title = 'x'
                 , y_title = 'y'
                 , y_min = None
                 , y_max = None
                 ):
    c = ROOT.TCanvas(canvas_name)
    if ths is not None:
        if isinstance(ths, ROOT.THStack):
            ths.Draw('NOSTACK')
            if ths.GetXaxis():
                ths.GetXaxis().SetTitle(x_title)
            if ths.GetYaxis():
                ths.GetYaxis().SetTitle(y_title)
            if y_min is not None: ths.SetMinimum(y_min)
            if y_max is not None: ths.SetMaximum(y_max)
            ths.Draw('NOSTACK')
        else:
            if ths.GetXaxis():
                ths.GetXaxis().SetTitle(x_title)
            if ths.GetYaxis():
                ths.GetYaxis().SetTitle(y_title)
            if y_min is not None: ths.SetMinimum(y_min)
            if y_max is not None: ths.SetMaximum(y_max)
            ths.Draw()
    if leg is not None:
        leg.Draw()
    if labels is not None:
        for lol in labels:
            lol.Draw()
    return c

# ------------------------------------------------------------------------------
def plotAndPrint( file_handles
                , out_file
                , short_name
                , suffix
                , title
                , y_min
                , y_max
                , x_title
                , y_title
                ):
    # get stack and legend
    ths, leg, big_leg = getHistStack( file_handles
                                    , '%s%s' % (short_name, suffix)
                                    , 'ths_%s%s' % (short_name, suffix)
                                    , title
                                    )
    # print stack and legend to canvas
    c = printToCanvas( ths=ths
                     , leg=leg
                     , canvas_name='c_%s%s' % (short_name, suffix)
                     , x_title=x_title
                     , y_title=y_title
                     , y_min = y_min
                     , y_max = y_max
                     )
    c_big_leg = printToCanvas( leg=big_leg
                             , canvas_name='c_leg_%s%s' % (short_name, suffix)
                             )

    # make directory for rates
    safeMakeDir(out_file, short_name)

    # print rates to file
    c.Write('%s%s' % (short_name, suffix))
    c_big_leg.Write('leg_%s%s' % (short_name, suffix))
    c.Close()
    c_big_leg.Close()

# ------------------------------------------------------------------------------
def plotAndPrint2D( file_handles
                  , out_file
                  , short_name
                  , suffix
                  , title
                  , y_min
                  , y_max
                  , slice_variable_name
                  , x_title
                  , y_title
                  ):
    # get stack and legend
    ths_list, leg, big_leg = getHistStack2D( file_handles
                                           , '%s%s' % (short_name, suffix)
                                           , 'ths_%s%s' % (short_name, suffix)
                                           , title
                                           )

    # get stacks for one sample ata time
    ths_ss_list, leg_ss_list, big_leg_ss_list = getHistStack2DSingleSample( file_handles
                                                                          , '%s%s' % (short_name, suffix)
                                                                          , 'ths_%s%s' % (short_name, suffix)
                                                                          , '%s' % short_name
                                                                          , slice_variable_name
                                                                          )

    # print sliced stacks canvas
    for i, ths in enumerate(ths_list):
        c = printToCanvas( ths=ths
                         , leg=leg
                         , canvas_name='c_%s%s__slice_%d' % (short_name, suffix, i)
                         , x_title=x_title
                         , y_title=y_title
                         , y_min = y_min
                         , y_max = y_max
                         )
        # print isolation
        safeMakeDir(out_file, short_name)
        c.Write('%s%s__slice_%d' % (short_name, suffix, i))
        c.Close()

    # print single sample sliced stacks canvas
    for i, ths in enumerate(ths_ss_list):
        label = file_handles[i].label
        c = printToCanvas( ths=ths
                         , leg=leg_ss_list[i]
                         , canvas_name='c_%s%s__%s' % (short_name, suffix, label)
                         , x_title=x_title
                         , y_title=y_title
                         , y_min = y_min
                         , y_max = y_max
                         )
        safeMakeDir(out_file, short_name)
        c.Write('%s%s__%s' % (short_name, suffix, label))
        c.Close()

    # print big legend
    c_big_leg = printToCanvas( leg=big_leg
                             , canvas_name='c_leg_%s%s' % (short_name, suffix)
                             )
    safeMakeDir(out_file, short_name)
    c_big_leg.Write('leg_%s%s' % (short_name, suffix))
    c_big_leg.Close()

# ------------------------------------------------------------------------------
def plotRates( file_handles
             , out_file
             , rates_suffix = ''
             ):
    print 'rate suffix: %s' % rates_suffix

    plotAndPrint( file_handles = file_handles
                , out_file = out_file
                , short_name = 'mu_re'
                , suffix = rates_suffix
                , title = 'Muon RE'
                , y_min = 0.
                , y_max = 1.1
                , x_title = 'p_{T} [GeV]'
                , y_title = 'r'
                )
    plotAndPrint( file_handles = file_handles
                , out_file = out_file
                , short_name = 'mu_fr'
                , suffix = rates_suffix
                , title = 'Muon FR'
                , y_min = 0.
                , y_max = 0.2
                , x_title = 'p_{T} [GeV]'
                , y_title = 'f'
                )
    plotAndPrint( file_handles = file_handles
                , out_file = out_file
                , short_name = 'el_re'
                , suffix = rates_suffix
                , title = 'Electron RE'
                , y_min = 0.
                , y_max = 1.1
                , x_title = 'p_{T} [GeV]'
                , y_title = 'r'
                )
    plotAndPrint( file_handles = file_handles
                , out_file = out_file
                , short_name = 'el_fr'
                , suffix = rates_suffix
                , title = 'Electron FR'
                , y_min = 0.
                , y_max = 0.2
                , x_title = 'p_{T} [GeV]'
                , y_title = 'f'
                )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    plotAndPrint2D( file_handles = file_handles
                  , out_file = out_file
                  , short_name = 'el_re_eta_bins'
                  , suffix = rates_suffix
                  , title = 'Electron RE - eta bins'
                  , y_min = 0.
                  , y_max = 1.1
                  , x_title = 'p_{T} [GeV]'
                  , y_title = 'r'
                  , slice_variable_name = '#eta'
                  )
    plotAndPrint2D( file_handles = file_handles
                  , out_file = out_file
                  , short_name = 'el_fr_eta_bins'
                  , suffix = rates_suffix
                  , title = 'Electron FR - eta bins'
                  , y_min = 0.
                  , y_max = 0.2
                  , x_title = 'p_{T} [GeV]'
                  , y_title = 'f'
                  , slice_variable_name = '#eta'
                  )
    plotAndPrint2D( file_handles = file_handles
                  , out_file = out_file
                  , short_name = 'mu_re_eta_bins'
                  , suffix = rates_suffix
                  , title = 'Muon RE - eta bins'
                  , y_min = 0.
                  , y_max = 1.1
                  , x_title = 'p_{T} [GeV]'
                  , y_title = 'r'
                  , slice_variable_name = '#eta'
                  )
    plotAndPrint2D( file_handles = file_handles
                  , out_file = out_file
                  , short_name = 'mu_fr_eta_bins'
                  , suffix = rates_suffix
                  , title = 'Muon FR - eta bins'
                  , y_min = 0.
                  , y_max = 0.2
                  , x_title = 'p_{T} [GeV]'
                  , y_title = 'f'
                  , slice_variable_name = '#eta'
                  )

# ==============================================================================
if __name__ == '__main__':
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ROOT.gROOT.SetBatch()

    # fh = []
    file_handles = []
    this_color = 1

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # add ttbar
    this_color = ROOT.kBlue
    file_handles.append(FileHandle( 'rates.105200.ttbar.root'
                                  , 'ttbar'
                                  , this_color
                                  , draw_el_re=True
                                  , draw_el_fr=True
                                  , draw_mu_re=True
                                  , draw_mu_fr=True
                                  )
                       )
    this_color += 1

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # add signal
    # rates.127994.signal.root
    # rates.127995.signal.root
    # rates.127996.signal.root
    this_color = ROOT.kRed
    file_handles.append(FileHandle( 'rates.127995.signal.root'
                                  , 'signal 127995'
                                  , this_color
                                  , draw_el_re=True
                                  , draw_el_fr=False
                                  , draw_mu_re=True
                                  , draw_mu_fr=False
                                  )
                       )
    this_color += 1


    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    out_file = ROOT.TFile('rates.canv.root', 'RECREATE')

    plotRates(file_handles, out_file, '_EWK'   )
    plotRates(file_handles, out_file, '_HIGGS' )
    plotRates(file_handles, out_file, '_STRONG')
    plotRates(file_handles, out_file, '_STRONG_30')

    plotRates(file_handles, out_file, '_EWK_95'   )
    plotRates(file_handles, out_file, '_HIGGS_95' )
    plotRates(file_handles, out_file, '_STRONG_20_95')
    plotRates(file_handles, out_file, '_STRONG_30_95')

    plotRates(file_handles, out_file, '_EWK_90'   )
    plotRates(file_handles, out_file, '_HIGGS_90' )
    plotRates(file_handles, out_file, '_STRONG_20_90')
    plotRates(file_handles, out_file, '_STRONG_30_90')

    out_file.Close()
