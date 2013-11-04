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
def formatHist(h, color, x_title = 'p_{T} [GeV]', y_title = 'rate'):
    h.SetLineColor(color)
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
        # this_label = '%s (%d entries)' % (l, h.GetEntries())
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
def printToCanvas( ths = None
                 , leg = None
                 , canvas_name = 'c'
                 , x_title = 'x'
                 , y_title = 'y'
                 ):
    c = ROOT.TCanvas(canvas_name)
    if ths is not None:
        if isinstance(ths, ROOT.THStack):
            ths.Draw('NOSTACK')
            if ths.GetXaxis():
                ths.GetXaxis().SetTitle(x_title)
            if ths.GetYaxis():
                ths.GetYaxis().SetTitle(y_title)
                ths.GetYaxis().SetRangeUser(0., 1.1)
            ths.Draw('NOSTACK')
        else:
            if ths.GetXaxis():
                ths.GetXaxis().SetTitle(x_title)
            if ths.GetYaxis():
                ths.GetYaxis().SetTitle(y_title)
                ths.GetYaxis().SetRangeUser(0., 1.1)
            ths.Draw()
    if leg is not None:
        leg.Draw()
    return c

# ------------------------------------------------------------------------------
def plotRates(file_handles, out_file, rates_suffix = ''):
    ths_mu_re, leg_mu_re, big_leg_mu_re = getHistStack(file_handles, 'mu_re%s' % rates_suffix, 'ths_mu_re%s' % rates_suffix, 'Muon RE')
    ths_mu_fr, leg_mu_fr, big_leg_mu_fr = getHistStack(file_handles, 'mu_fr%s' % rates_suffix, 'ths_mu_fr%s' % rates_suffix, 'Muon FR')
    ths_el_re, leg_el_re, big_leg_el_re = getHistStack(file_handles, 'el_re%s' % rates_suffix, 'ths_el_re%s' % rates_suffix, 'Electron RE')
    ths_el_fr, leg_el_fr, big_leg_el_fr = getHistStack(file_handles, 'el_fr%s' % rates_suffix, 'ths_el_fr%s' % rates_suffix, 'Electron FR')

    ths_mu_re, leg_mu_re, big_leg_mu_re = getHistStack(file_handles, 'mu_re%s' % rates_suffix, 'ths_mu_re%s' % rates_suffix, 'Muon RE')
    ths_mu_fr, leg_mu_fr, big_leg_mu_fr = getHistStack(file_handles, 'mu_fr%s' % rates_suffix, 'ths_mu_fr%s' % rates_suffix, 'Muon FR')
    ths_el_re, leg_el_re, big_leg_el_re = getHistStack(file_handles, 'el_re%s' % rates_suffix, 'ths_el_re%s' % rates_suffix, 'Electron RE')
    ths_el_fr, leg_el_fr, big_leg_el_fr = getHistStack(file_handles, 'el_fr%s' % rates_suffix, 'ths_el_fr%s' % rates_suffix, 'Electron FR')

    # c_leg = printToCanvas( leg=big_leg, canvas_name='c_leg')
    # c_mu_re = printToCanvas( ths=ths_mu_re, leg=leg, canvas_name='c_mu_re', x_title='p_{T} [GeV]', y_title='r')
    # c_mu_fr = printToCanvas( ths=ths_mu_fr, leg=leg, canvas_name='c_mu_fr', x_title='p_{T} [GeV]', y_title='f')
    # c_el_re = printToCanvas( ths=ths_el_re, leg=leg, canvas_name='c_el_re', x_title='p_{T} [GeV]', y_title='r')
    # c_el_fr = printToCanvas( ths=ths_el_fr, leg=leg, canvas_name='c_el_fr', x_title='p_{T} [GeV]', y_title='f')

    c_mu_re = printToCanvas( ths=ths_mu_re, leg=leg_mu_re, canvas_name='c_mu_re%s' % rates_suffix, x_title='p_{T} [GeV]', y_title='r')
    c_mu_fr = printToCanvas( ths=ths_mu_fr, leg=leg_mu_fr, canvas_name='c_mu_fr%s' % rates_suffix, x_title='p_{T} [GeV]', y_title='f')
    c_el_re = printToCanvas( ths=ths_el_re, leg=leg_el_re, canvas_name='c_el_re%s' % rates_suffix, x_title='p_{T} [GeV]', y_title='r')
    c_el_fr = printToCanvas( ths=ths_el_fr, leg=leg_el_fr, canvas_name='c_el_fr%s' % rates_suffix, x_title='p_{T} [GeV]', y_title='f')

    c_big_leg_mu_re = printToCanvas( leg=big_leg_mu_re, canvas_name='c_leg_mu_re%s' % rates_suffix)
    c_big_leg_mu_fr = printToCanvas( leg=big_leg_mu_fr, canvas_name='c_leg_mu_fr%s' % rates_suffix)
    c_big_leg_el_re = printToCanvas( leg=big_leg_el_re, canvas_name='c_leg_el_re%s' % rates_suffix)
    c_big_leg_el_fr = printToCanvas( leg=big_leg_el_fr, canvas_name='c_leg_el_fr%s' % rates_suffix)

    c_mu_re_comp = []
    c_mu_fr_comp = []
    c_el_re_comp = []
    c_el_fr_comp = []
    for fh in file_handles:
        temp_hist_mu_re = fh.getHist('mu_re%s' % rates_suffix)
        temp_hist_mu_fr = fh.getHist('mu_fr%s' % rates_suffix)
        temp_hist_el_re = fh.getHist('el_re%s' % rates_suffix)
        temp_hist_el_fr = fh.getHist('el_fr%s' % rates_suffix)

        c_mu_re_comp.append(printToCanvas( ths=temp_hist_mu_re, leg=None, canvas_name='c_mu_re_comp_%s_%s' % (rates_suffix, fh.label), x_title='p_{T} [GeV]', y_title='r'))
        c_mu_fr_comp.append(printToCanvas( ths=temp_hist_mu_fr, leg=None, canvas_name='c_mu_fr_comp_%s_%s' % (rates_suffix, fh.label), x_title='p_{T} [GeV]', y_title='f'))
        c_el_re_comp.append(printToCanvas( ths=temp_hist_el_re, leg=None, canvas_name='c_el_re_comp_%s_%s' % (rates_suffix, fh.label), x_title='p_{T} [GeV]', y_title='r'))
        c_el_fr_comp.append(printToCanvas( ths=temp_hist_el_fr, leg=None, canvas_name='c_el_fr_comp_%s_%s' % (rates_suffix, fh.label), x_title='p_{T} [GeV]', y_title='f'))

    out_file.cd()
    out_file.mkdir('mu_re')
    out_file.cd('mu_re')
    c_mu_re.Write('mu_re%s' % rates_suffix)
    c_big_leg_mu_re.Write('leg_mu_re%s' % rates_suffix)
    for cmrc in c_mu_re_comp:
        cmrc.Write()

    out_file.cd()
    out_file.mkdir('mu_fr')
    out_file.cd('mu_fr')
    c_mu_fr.Write('mu_fr%s' % rates_suffix)
    c_big_leg_mu_fr.Write('leg_mu_fr%s' % rates_suffix)
    for cmfc in c_mu_fr_comp:
        cmfc.Write()

    out_file.cd()
    out_file.mkdir('el_re')
    out_file.cd('el_re')
    c_el_re.Write('el_re%s' % rates_suffix)
    c_big_leg_el_re.Write('leg_el_re%s' % rates_suffix)
    for cerc in c_el_re_comp:
        cerc.Write()

    out_file.cd()
    out_file.mkdir('el_fr')
    out_file.cd('el_fr')
    c_el_fr.Write('el_fr%s' % rates_suffix)
    c_big_leg_el_fr.Write('leg_el_fr%s' % rates_suffix)
    for cefc in c_el_fr_comp:
        cefc.Write()

# ==============================================================================
if __name__ == '__main__':
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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
    this_color = ROOT.kCyan
    file_handles.append(FileHandle( 'rates.ttbar.root'
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
    # fh.append(FileHandle( 'rates.ZZ4lep.root'
    #                     , 'ZZ4lep'
    #                     , this_color
    #                     , draw_el_re=True
    #                     , draw_el_fr=False
    #                     , draw_mu_re=True
    #                     , draw_mu_fr=False
    #                     )
    #          )
    # this_color += 1

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    out_file = ROOT.TFile('rates.canv.root', 'RECREATE')

    plotRates(file_handles, out_file, '_EWK'   )
    plotRates(file_handles, out_file, '_HIGGS' )
    plotRates(file_handles, out_file, '_STRONG')
    plotRates(file_handles, out_file, '_STRONG_30')

    out_file.Close()
