#!/usr/bin/env python

import sys
import os.path
import optparse
import time

import ROOT
import rootlogon
import metaroot

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

    def getHist(self, hist_name):
        print 'getting hist: %s from file: %s' % (hist_name, self.file_name)
        h = self.file.Get(hist_name)
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
        h = fhl.getHist(hist_name)
        leg.AddEntry(    h, fhl.label)
        big_leg.AddEntry(h, fhl.label)

    return leg, big_leg

# ------------------------------------------------------------------------------
def getHistStack(file_handles, hist_name, stack_name, stack_title):
    hist_list = []
    label_list = []
    ths = ROOT.THStack(stack_name, stack_title)
    for fh in file_handles:
        if  'el_re' in hist_name and not fh.draw_el_re: continue
        if  'el_fr' in hist_name and not fh.draw_el_fr: continue
        if  'mu_re' in hist_name and not fh.draw_mu_re: continue
        if  'mu_fr' in hist_name and not fh.draw_mu_fr: continue

        h = fh.getHist(hist_name)
        ths.Add(h)
        hist_list.append(h)
        label_list.append(fh.label)

    leg, big_leg = makeLegend(hist_list, label_list)
    return ths, leg, big_leg

# ------------------------------------------------------------------------------
def getHistStack2D(file_handles, hist_name, stack_name, stack_title):
    hist_list_2d = []
    label_list = []
    ths_list = []
    num_slices = 0
    for fh in file_handles:
        if  'el_re' in hist_name and not fh.draw_el_re: continue
        if  'el_fr' in hist_name and not fh.draw_el_fr: continue
        if  'mu_re' in hist_name and not fh.draw_mu_re: continue
        if  'mu_fr' in hist_name and not fh.draw_mu_fr: continue

        h_2d = fh.getHist(hist_name)
        this_num_slices = h_2d.GetNbinsY()
        if num_slices == 0:
            print 'found 2d hist with %s slices' % this_num_slices
            print 'setting number of slices'
            num_slices = this_num_slices
            print 'constructing ths_list'
            ths_list = [ ROOT.THStack( '%s__slice_%d' % (stack_name, slice)
                                     , '%s - slice %d' % (stack_title,slice)
                                     )
                         for slice in xrange(1, num_slices+1)
                       ]
            print ths_list
        assert  this_num_slices == num_slices

        for slice in xrange(num_slices):
            print ths_list[slice]
            h_tmp = h_2d.ProjectionX( '%s_%s__slice_%d' % ( h_2d.GetName()
                                                          , fh.label
                                                          , slice
                                                          )
                                    , slice+1,slice+1
                                    )
            h_tmp.SetLineWidth(3)
            ths_list[slice].Add(h_tmp)
            print 'num entries in this slice: %s' % h_tmp.GetEntries()

        hist_list_2d.append(h_2d)
        label_list.append(fh.label)

    leg, big_leg = makeLegend(hist_list_2d, label_list)
    return ths_list, leg, big_leg

# ------------------------------------------------------------------------------
def printToCanvas( ths = None
                 , leg = None
                 , canvas_name = 'c'
                 , x_title = 'x'
                 , y_title = 'y'
                 , y_min = 0
                 , y_max = 1.1
                 ):
    c = ROOT.TCanvas(canvas_name)
    if ths is not None:
        if isinstance(ths, ROOT.THStack):
            ths.Draw('NOSTACK')
            if ths.GetXaxis():
                ths.GetXaxis().SetTitle(x_title)
            if ths.GetYaxis():
                ths.GetYaxis().SetTitle(y_title)
                ths.SetMinimum(y_min)
                ths.SetMaximum(y_max)
            ths.Draw('NOSTACK')
        else:
            if ths.GetXaxis():
                ths.GetXaxis().SetTitle(x_title)
            if ths.GetYaxis():
                ths.GetYaxis().SetTitle(y_title)
                ths.SetMinimum(y_min)
                ths.SetMaximum(y_max)
            ths.Draw()
    if leg is not None:
        leg.Draw()
    return c

# ------------------------------------------------------------------------------
def plotAndPrint( file_handles
                , out_file
                , short_name
                , suffix
                , title
                , x_title
                , y_title
                , y_min
                , y_max
                ):
    ths, leg, big_leg = getHistStack( file_handles
                                    , '%s%s' % (short_name, suffix)
                                    , 'ths_%s%s' % (short_name, suffix)
                                    , title
                                    )
    c_rate = printToCanvas( ths=ths
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
    safeMakeDir(out_file, short_name)
    c_rate.Write('%s%s' % (short_name, suffix))
    c_big_leg.Write('leg_%s%s' % (short_name, suffix))
    c_rate.Close()
    c_big_leg.Close()

# ------------------------------------------------------------------------------
def plotAndPrint2D( file_handles
                  , out_file
                  , short_name
                  , suffix
                  , title
                  , x_title
                  , y_title
                  , y_min
                  , y_max
                  ):
    ths_list, leg, big_leg = getHistStack2D( file_handles
                                           , '%s%s' % (short_name, suffix)
                                           , 'ths_%s%s' % (short_name, suffix)
                                           , title
                                           )
    for i, ths in enumerate(ths_list):
        print '%s -- %s' % (i, ths)
        c_rate = printToCanvas( ths=ths
                              , leg=leg
                              , canvas_name='c_%s%s__slice_%d' % (short_name, suffix, i)
                              , x_title=x_title
                              , y_title=y_title
                              , y_min = y_min
                              , y_max = y_max
                              )
        safeMakeDir(out_file, short_name)
        c_rate.Write('%s%s_slice_%d' % (short_name, suffix, i))
        c_rate.Close()
    c_big_leg = printToCanvas( leg=big_leg
                             , canvas_name='c_leg_%s%s' % (short_name, suffix)
                             )
    c_big_leg.Write('leg_%s%s' % (short_name, suffix))
    c_big_leg.Close()

# ------------------------------------------------------------------------------
def plotRates(file_handles, out_file, rates_suffix = ''):
    print 'rate suffix: %s' % rates_suffix

    plotAndPrint( file_handles = file_handles
                , out_file = out_file
                , short_name = 'mu_re'
                , suffix = rates_suffix
                , title = 'Muon RE'
                , x_title = 'p_{T} [GeV]'
                , y_title = 'r'
                , y_min = 0.
                , y_max = 1.1
                )
    plotAndPrint( file_handles = file_handles
                , out_file = out_file
                , short_name = 'mu_fr'
                , suffix = rates_suffix
                , title = 'Muon FR'
                , x_title = 'p_{T} [GeV]'
                , y_title = 'f'
                , y_min = 0.
                , y_max = 0.2
                )
    plotAndPrint( file_handles = file_handles
                , out_file = out_file
                , short_name = 'el_re'
                , suffix = rates_suffix
                , title = 'Electron RE'
                , x_title = 'p_{T} [GeV]'
                , y_title = 'r'
                , y_min = 0.
                , y_max = 1.1
                )
    plotAndPrint( file_handles = file_handles
                , out_file = out_file
                , short_name = 'el_fr'
                , suffix = rates_suffix
                , title = 'Electron FR'
                , x_title = 'p_{T} [GeV]'
                , y_title = 'f'
                , y_min = 0.
                , y_max = 0.2
                )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    plotAndPrint2D( file_handles = file_handles
                  , out_file = out_file
                  , short_name = 'el_re_eta_bins'
                  , suffix = rates_suffix
                  , title = 'Electron RE - eta bins'
                  , x_title = 'p_{T} [GeV]'
                  , y_title = 'r'
                  , y_min = 0.
                  , y_max = 1.1
                  )
    plotAndPrint2D( file_handles = file_handles
                  , out_file = out_file
                  , short_name = 'el_fr_eta_bins'
                  , suffix = rates_suffix
                  , title = 'Electron FR - eta bins'
                  , x_title = 'p_{T} [GeV]'
                  , y_title = 'f'
                  , y_min = 0.
                  , y_max = 0.2
                  )
    plotAndPrint2D( file_handles = file_handles
                  , out_file = out_file
                  , short_name = 'mu_re_eta_bins'
                  , suffix = rates_suffix
                  , title = 'Muon RE - eta bins'
                  , x_title = 'p_{T} [GeV]'
                  , y_title = 'r'
                  , y_min = 0.
                  , y_max = 1.1
                  )
    plotAndPrint2D( file_handles = file_handles
                  , out_file = out_file
                  , short_name = 'mu_fr_eta_bins'
                  , suffix = rates_suffix
                  , title = 'Muon FR - eta bins'
                  , x_title = 'p_{T} [GeV]'
                  , y_title = 'f'
                  , y_min = 0.
                  , y_max = 0.2
                  )

# ==============================================================================
if __name__ == '__main__':
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ROOT.gROOT.SetBatch()

    # fh = []
    file_handles = []
    this_color = 1

    # # add Zmumu samples
    # this_color = ROOT.kGreen
    # for it in xrange(6):
    #     file_handles.append(FileHandle( 'rates.ZmumuNp%d.root' % it
    #                                   , 'Z#rightarrow#mu#mu : Np%d' % it
    #                                   , this_color
    #                                   , draw_el_re=False
    #                                   , draw_el_fr=True
    #                                   , draw_mu_re=True
    #                                   , draw_mu_fr=False
    #                                   )
    #                        )
    #     this_color -=1

    # # add Zee samples
    # this_color = ROOT.kRed
    # for it in xrange(6):
    #     file_handles.append(FileHandle( 'rates.ZeeNp%d.root' % it
    #                                   , 'Z#rightarrowee : Np%d' % it
    #                                   , this_color
    #                                   , draw_el_re=True
    #                                   , draw_el_fr=False
    #                                   , draw_mu_re=False
    #                                   , draw_mu_fr=False
    #                                   )
    #                        )
    #     this_color -=1

    # # add Wmunu samples
    # this_color = ROOT.kBlue
    # for it in xrange(6):
    #     file_handles.append(FileHandle( 'rates.WmunuNp%d.root' % it
    #                                   , 'W#rightarrow#mu#nu : Np%d' % it
    #                                   , this_color
    #                                   , draw_el_re=False
    #                                   , draw_el_fr=True
    #                                   , draw_mu_re=True
    #                                   , draw_mu_fr=True
    #                                   )
    #                        )
    #     this_color -=1

    # # add Wenu samples
    # this_color = ROOT.kMagenta
    # for it in xrange(6):
    #     file_handles.append(FileHandle( 'rates.WenuNp%d.root' % it
    #                                   , 'W#rightarrowe#nu : Np%d' % it
    #                                   , this_color
    #                                   , draw_el_re=True
    #                                   , draw_el_fr=True
    #                                   , draw_mu_re=False
    #                                   , draw_mu_fr=True
    #                                   )
    #                        )
    #     this_color -=1

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

    # # add ZZ to 4lep
    # this_color = ROOT.kOrange
    # file_handles.append(FileHandle( 'rates.116600.ZZ4lep.root'
    #                               , 'ZZ4lep'
    #                               , this_color
    #                               , draw_el_re=True
    #                               , draw_el_fr=True
    #                               , draw_mu_re=True
    #                               , draw_mu_fr=True
    #                               )
    #                    )
    # this_color += 1

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
    plotRates(file_handles, out_file, '_EWK_PP'   )
    plotRates(file_handles, out_file, '_HIGGS_PP' )
    plotRates(file_handles, out_file, '_STRONG_PP')
    plotRates(file_handles, out_file, '_STRONG_30_PP')

    out_file.Close()

