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
def getHistStack(file_handles, hist_name, stack_name, stack_title, y_min, y_max):
    hist_list = []
    label_list = []
    ths = ROOT.THStack(stack_name, stack_title)
    for fh in file_handles:
        if  'el_re' in hist_name and not fh.draw_el_re: continue
        if  'el_fr' in hist_name and not fh.draw_el_fr: continue
        if  'mu_re' in hist_name and not fh.draw_mu_re: continue
        if  'mu_fr' in hist_name and not fh.draw_mu_fr: continue

        h = fh.getHist(hist_name)
        h.GetYaxis().SetRangeUser(y_min, y_max)
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
                ths.GetYaxis().SetRangeUser(y_min, y_max)
            ths.Draw('NOSTACK')
        else:
            if ths.GetXaxis():
                ths.GetXaxis().SetTitle(x_title)
            if ths.GetYaxis():
                ths.GetYaxis().SetTitle(y_title)
                ths.GetYaxis().SetRangeUser(y_min, y_max)
            ths.Draw()
    if leg is not None:
        leg.Draw()
    return c

# ------------------------------------------------------------------------------
def plotRates(file_handles, out_file, rates_suffix = ''):
    ths_mu_iso, leg_mu_iso, big_leg_mu_iso = getHistStack(file_handles, 'mu_iso%s' % rates_suffix, 'ths_mu_iso%s' % rates_suffix, 'Muon iso'    )
    ths_el_iso, leg_el_iso, big_leg_el_iso = getHistStack(file_handles, 'el_iso%s' % rates_suffix, 'ths_el_iso%s' % rates_suffix, 'Electron iso')

    c_mu_iso = printToCanvas( ths=ths_mu_iso, leg=leg_mu_iso, canvas_name='c_mu_iso%s' % rates_suffix, x_title='p_{T} [GeV]', y_title='r')
    c_el_iso = printToCanvas( ths=ths_el_iso, leg=leg_el_iso, canvas_name='c_el_iso%s' % rates_suffix, x_title='p_{T} [GeV]', y_title='r')

    c_big_leg_mu_iso = printToCanvas( leg=big_leg_mu_iso, canvas_name='c_leg_mu_iso%s' % rates_suffix)
    c_big_leg_el_iso = printToCanvas( leg=big_leg_el_iso, canvas_name='c_leg_el_iso%s' % rates_suffix)

    c_mu_iso_comp = []
    c_el_iso_comp = []
    for fh in file_handles:
        temp_hist_mu_iso = fh.getHist('mu_iso%s' % rates_suffix)
        temp_hist_el_iso = fh.getHist('el_iso%s' % rates_suffix)

        c_mu_iso_comp.append(printToCanvas( ths=temp_hist_mu_re, leg=None, canvas_name='c_mu_re_comp_%s_%s' % (rates_suffix, fh.label), x_title='p_{T} [GeV]', y_title='r', y_min = 0., y_max = 1.1))
        c_el_iso_comp.append(printToCanvas( ths=temp_hist_el_re, leg=None, canvas_name='c_el_re_comp_%s_%s' % (rates_suffix, fh.label), x_title='p_{T} [GeV]', y_title='r', y_min = 0., y_max = 1.1))

    out_file.cd()
    out_file.mkdir('mu_re')
    out_file.cd('mu_re')
    c_mu_re.Write('mu_re%s' % rates_suffix)
    c_big_leg_mu_re.Write('leg_mu_re%s' % rates_suffix)
    for cmrc in c_mu_re_comp:
        cmrc.Write()
        cmrc.Close()
    c_mu_re.Close()
    c_big_leg_mu_re.Close()

    out_file.cd()
    out_file.mkdir('mu_fr')
    out_file.cd('mu_fr')
    c_mu_fr.Write('mu_fr%s' % rates_suffix)
    c_big_leg_mu_fr.Write('leg_mu_fr%s' % rates_suffix)
    for cmfc in c_mu_fr_comp:
        cmfc.Write()
        cmfc.Close()
    c_mu_fr.Close()
    c_big_leg_mu_fr.Close()

    out_file.cd()
    out_file.mkdir('el_re')
    out_file.cd('el_re')
    c_el_re.Write('el_re%s' % rates_suffix)
    c_big_leg_el_re.Write('leg_el_re%s' % rates_suffix)
    for cerc in c_el_re_comp:
        cerc.Write()
        cerc.Close()
    c_el_re.Close()
    c_big_leg_el_re.Close()

    out_file.cd()
    out_file.mkdir('el_fr')
    out_file.cd('el_fr')
    c_el_fr.Write('el_fr%s' % rates_suffix)
    c_big_leg_el_fr.Write('leg_el_fr%s' % rates_suffix)
    for cefc in c_el_fr_comp:
        cefc.Write()
        cefc.Close()
    c_el_fr.Close()
    c_big_leg_el_fr.Close()

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
    this_color = ROOT.kCyan
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

    # add signal
    # rates.127994.signal.root
    # rates.127995.signal.root
    # rates.127996.signal.root
    this_color = ROOT.kRed
    file_handles.append(FileHandle( 'rates.127994.signal.root'
                                  , 'signal 127994'
                                  , this_color
                                  , draw_el_re=True
                                  , draw_el_fr=True
                                  , draw_mu_re=True
                                  , draw_mu_fr=True
                                  )
                       )
    this_color += 1


    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    out_file = ROOT.TFile('rates.canv.root', 'RECREATE')

    plotRates(file_handles, out_file, '_PTCONE30'   )

    out_file.Close()

