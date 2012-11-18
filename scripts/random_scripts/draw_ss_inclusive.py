#!/usr/bin/env python

import math
import ROOT
import rootlogon

# -----------------------------------------------------------------------------
systematics = [ 'NONE'
              , "UP"
              , "DOWN"
              , "EL_RE_UP"
              , "EL_RE_DOWN"
              , "EL_FR_UP"
              , "EL_FR_DOWN"
              , "MU_RE_UP"
              , "MU_RE_DOWN"
              , "MU_FR_UP"
              , "MU_FR_DOWN"
              ]
colors = { "NONE":ROOT.kBlack
         , "UP":ROOT.kAzure
         , "DOWN":ROOT.kAzure
         , "EL_RE_UP":ROOT.kGreen
         , "EL_RE_DOWN":ROOT.kGreen
         , "EL_FR_UP":ROOT.kViolet
         , "EL_FR_DOWN":ROOT.kViolet
         , "MU_RE_UP":ROOT.kMagenta
         , "MU_RE_DOWN":ROOT.kMagenta
         , "MU_FR_UP":ROOT.kCyan
         , "MU_FR_DOWN":ROOT.kCyan
         }

# -----------------------------------------------------------------------------
def printStuff(f_name):
    f = ROOT.TFile(f_name)

    ee = drawChannel(f, 'ee')
    mm = drawChannel(f, 'mm')
    em = drawChannel(f, 'em')

    return (f, ee, mm, em)

def drawChannel(f, channel):

    # Get plots from file
    h = {}
    for sys in systematics:
        if sys == 'UP' or sys == 'DOWN': continue
        h[sys] = f.Get('%s_mll_%s' % (channel, sys))

    # Get "combined up" plot for ee
    h["UP"] = getTotalShiftUp( h
                             , '%s_mll_UP' % channel
                             )
    # Get "combined down" plot for ee
    h['DOWN'] = getTotalShiftDown( h
                                 , '%s_mll_DOWN' % channel
                                 )


    # boring formatting stuff
    h['NONE'].SetMarkerStyle(20)

    h['UP'].SetLineWidth(  3)
    h['DOWN'].SetLineWidth(3)

    for sys in systematics:
        h[sys].SetLineColor(colors[sys])

    # Draw ee to canvas
    c = ROOT.TCanvas('c_%s' % channel, channel)
    # c.SetLogy()

    h['NONE'].Draw('P')
    for sys in systematics:
        h[sys].Draw('SAME')
    h['NONE'].Draw('PSAME')

    leg = ROOT.TLegend(0.7, 0.9, 0.9, 0.6)
    leg.SetFillColor(0)
    leg.SetBorderSize(0)
    for sys in systematics:
        leg.AddEntry(h[sys], sys)
    leg.Draw()

    c.Print('%s_mll.eps' % channel)
    c.Print('%s_mll.png' % channel)


    # return all objects so they are persistent in interactive mode
    stuff = { 'canvas':c
            , 'hists':h
            , 'leg':leg
            }

    return stuff


def getTotalShiftUp(hists, hist_name = 'shift_up'):
    h_nominal = hists['NONE']

    # get histogram parameters
    x_min    = h_nominal.GetXaxis().GetXmin()
    x_max    = h_nominal.GetXaxis().GetXmax()
    num_bins = h_nominal.GetNbinsX()
    h_title  = h_nominal.GetXaxis().GetTitle()
    x_title  = h_nominal.GetXaxis().GetTitle()
    y_title  = h_nominal.GetYaxis().GetTitle()

    # create up histogram
    h_up = ROOT.TH1F( hist_name
                    , '%s:%s:%s' % (h_title, x_title, y_title)
                    , num_bins
                    , x_min
                    , x_max
                    )

    # For each bin, get the nominal weight and the systematic weights
    # For each systematic weight, check if it is ABOVE the nominal.
    # If yes, add in quadrature to get "combined up" weight
    for bin in xrange(1,num_bins+1):
        nominal = h_nominal.GetBinContent(bin)
        syst_up = 0.

        for sys in hists:
            if sys == 'NONE': continue

            weight = hists[sys].GetBinContent(bin)

            if weight > nominal:
                syst_up += (nominal - weight)**2
        syst_up = nominal + math.sqrt(syst_up)
        h_up.SetBinContent(bin, syst_up)

    return h_up

def getTotalShiftDown(hists, hist_name = 'shift_down'):
    h_nominal = hists['NONE']

    # get histogram parameters
    x_min    = h_nominal.GetXaxis().GetXmin()
    x_max    = h_nominal.GetXaxis().GetXmax()
    num_bins = h_nominal.GetNbinsX()
    h_title  = h_nominal.GetXaxis().GetTitle()
    x_title  = h_nominal.GetXaxis().GetTitle()
    y_title  = h_nominal.GetYaxis().GetTitle()

    # create up histogram
    h_down = ROOT.TH1F( hist_name
                    , '%s:%s:%s' % (h_title, x_title, y_title)
                    , num_bins
                    , x_min
                    , x_max
                    )

    # For each bin, get the nominal weight and the systematic weights
    # For each systematic weight, check if it is ABOVE the nominal.
    # If yes, add in quadrature to get "combined up" weight
    for bin in xrange(1,num_bins+1):
        nominal = h_nominal.GetBinContent(bin)
        syst_down = 0.

        for sys in hists:
            if sys == 'NONE': continue

            weight = hists[sys].GetBinContent(bin)

            if weight < nominal:
                syst_down += (nominal - weight)**2
        syst_down = nominal - math.sqrt(syst_down)
        h_down.SetBinContent(bin, syst_down)

    return h_down

if __name__ == '__main__':
    (f, ee, mm, em) = printStuff('output.root')
