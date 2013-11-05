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

    def getHist(self, hist_name, normalize):
        h = self.file.Get(hist_name)
        if normalize:
            h.Scale( 1/h.Integral() )
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
        h = fhl.getHist(hist_name, True)
        leg.AddEntry(    h, fhl.label)
        big_leg.AddEntry(h, fhl.label)

    return leg, big_leg

# ------------------------------------------------------------------------------
def getHistStack(file_handles, hist_name, stack_name, stack_title):
    hist_list = []
    label_list = []
    ths = ROOT.THStack(stack_name, stack_title)
    for fh in file_handles:
        h = fh.getHist(hist_name, True)
        findTargetCut(h, 0.90)
        findTargetCut(h, 0.95)
        h.Rebin(10)

        ths.Add(h)
        hist_list.append(h)
        label_list.append(fh.label)

    leg, big_leg = makeLegend(hist_list, label_list)

    return ths, leg, big_leg

# ------------------------------------------------------------------------------
def getCutValues(file_handles, hist_name, target_eff):
    print 'getCutValues()'

    cut_values = []
    for fh in file_handles:
        h = fh.getHist(hist_name, True)
        chosen_cut = findTargetCut(h, target_eff)
        cut_values.append({'label':fh.label, 'cut':chosen_cut, 'color':fh.color})
    return cut_values

# ------------------------------------------------------------------------------
def findTargetCut(h, target_eff):
    denom = h.Integral()
    numer = 0
    chosen_cut_bin = 0
    for bin in xrange(1, h.GetNbinsX()):
        numer += h.GetBinContent(bin)

        if numer/denom > target_eff:
            chosen_cut_bin = bin+1
            break
    chosen_cut = h.GetXaxis().GetBinLowEdge(chosen_cut_bin)
    print '-- Found %s efficient cut for %s: %s (bin %s) - actual eff: %s' % (target_eff, h.GetName(), chosen_cut, chosen_cut_bin, numer/denom)
    return chosen_cut

# ------------------------------------------------------------------------------
def printToCanvas( ths = None
                 , leg = None
                 , canvas_name = 'c'
                 , labels = None
                 , x_title = 'x'
                 , y_title = 'y'
                 , y_min = 1.e-6
                 , y_max = 5.
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
    if labels is not None:
        for lol in labels:
            lol.Draw()
    return c

# ------------------------------------------------------------------------------
def getCutValueLabels(chosen_cut_values):
    x_start = 0.4
    y_start = 0.9
    label_list = []
    for eff in chosen_cut_values:
        for entry in chosen_cut_values[eff]:
            print entry
            text_for_label = 'eff %s (%s): %0.2f' % (eff, entry['label'], entry['cut'])
            l = ROOT.TText()
            l.SetNDC()
            l.SetText(x_start, y_start, text_for_label)
            l.SetTextColor(entry['color'])
            y_start -= 0.05
            label_list.append(l)

            if 'signal' in entry['label']:
                line = ROOT.TLine(entry['cut'], 1.e-6, entry['cut'], 5)
                line.SetLineWidth(3)
                line.SetLineColor(ROOT.kGreen+3)
                label_list.append(line)

    return label_list

# ------------------------------------------------------------------------------
def plotRates(file_handles, out_file, lep_flavor = 'el', rates_suffix = ''):
    chosen_cut_values = { '0.90':getCutValues( file_handles
                                             , '%s_iso%s' % (lep_flavor, rates_suffix)
                                             , 0.90
                                             )
                        , '0.95':getCutValues( file_handles
                                             , '%s_iso%s' % (lep_flavor, rates_suffix)
                                             , 0.95
                                             )
                        }
    cut_value_labels = getCutValueLabels(chosen_cut_values)

    ths_iso, leg_iso, big_leg_iso = getHistStack( file_handles
                                                , '%s_iso%s' % (lep_flavor, rates_suffix)
                                                , 'ths_%s_iso%s' % (lep_flavor, rates_suffix)
                                                , '%s iso' % lep_flavor
                                                )

    c_iso = printToCanvas( ths=ths_iso
                         , leg=leg_iso
                         , canvas_name='c_%s_iso%s' % (lep_flavor, rates_suffix)
                         , labels = cut_value_labels
                         , x_title='isolation'
                         , y_title='normailzed units'
                         , y_min = 1.e-6
                         , y_max = 5.
                         )

    c_big_leg_iso = printToCanvas( leg=big_leg_iso
                                 , canvas_name='c_leg_%s_iso%s' % (lep_flavor, rates_suffix)
                                 )

    # make directory for isolation
    safeMakeDir(out_file, '%s_iso' % lep_flavor)

    # print isolation
    c_iso.SetLogy()
    c_iso.Write('%s_iso%s' % (lep_flavor, rates_suffix))
    c_big_leg_iso.Write('leg_%s_iso%s' % (lep_flavor, rates_suffix))
    c_iso.Close()
    c_big_leg_iso.Close()

# ==============================================================================
if __name__ == '__main__':
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    ROOT.gROOT.SetBatch()

    # fh = []
    file_handles = []
    this_color = 1

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

    plotRates(file_handles, out_file, 'el', '_PTCONE30'       )
    plotRates(file_handles, out_file, 'el', '_ETCONE30'       )
    plotRates(file_handles, out_file, 'el', '_PTCONE20'       )
    plotRates(file_handles, out_file, 'el', '_ETCONE20'       )
    plotRates(file_handles, out_file, 'el', '_PTCONE30_CAPPED')
    plotRates(file_handles, out_file, 'el', '_ETCONE30_CAPPED')
    plotRates(file_handles, out_file, 'el', '_PTCONE20_CAPPED')
    plotRates(file_handles, out_file, 'el', '_ETCONE20_CAPPED')

    plotRates(file_handles, out_file, 'mu', '_PTCONE30'       )
    plotRates(file_handles, out_file, 'mu', '_ETCONE30'       )
    plotRates(file_handles, out_file, 'mu', '_PTCONE20'       )
    plotRates(file_handles, out_file, 'mu', '_ETCONE20'       )
    plotRates(file_handles, out_file, 'mu', '_PTCONE30_CAPPED')
    plotRates(file_handles, out_file, 'mu', '_ETCONE30_CAPPED')
    plotRates(file_handles, out_file, 'mu', '_PTCONE20_CAPPED')
    plotRates(file_handles, out_file, 'mu', '_ETCONE20_CAPPED')

    out_file.Close()

