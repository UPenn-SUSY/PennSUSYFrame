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
def doSystematics(f_name):
    f = ROOT.TFile(f_name)

    combined_ee = getCombinedSyst(f, 'ee')
    combined_mm = getCombinedSyst(f, 'mm')
    combined_em = getCombinedSyst(f, 'em')

def getCombinedSyst(f, channel):

    # Get plots from file
    h = {}
    for sys in systematics:
        if sys == 'UP' or sys == 'DOWN': continue
        h[sys] = f.Get('%s_mll_%s' % (channel, sys))

    # Get "combined up" plot for ee
    syst_up =  getRelativeTotalShiftUp(h)
    # Get "combined down" plot for ee
    syst_down = getRelativeTotalShiftDown(h)

    # Combine systematics into single number
    combined_syst = 0.5*(syst_up + syst_down)

    print 'syst up (%s): %f'           % (channel, syst_up)
    print 'syst down (%s): %f'         % (channel, syst_down)
    print 'Overal systematic (%s): %f' % (channel, combined_syst)
    print ''

    return combined_syst


def getRelativeTotalShiftUp(hists):
    h_nominal = hists['NONE']

    nominal = h_nominal.Integral()
    syst_up = 0

    # For each systematic weight, check if it is ABOVE the nominal.
    # If yes, add in quadrature to get "combined up" weight
    for sys in hists:
        if sys == 'NONE': continue

        weight = hists[sys].Integral()

        if weight > nominal:
            syst_up += (nominal - weight)**2
    syst_up = math.sqrt(syst_up)

    return abs(syst_up/nominal)

def getRelativeTotalShiftDown(hists):
    h_nominal = hists['NONE']

    nominal = h_nominal.Integral()
    syst_down = 0.

    # For each systematic weight, check if it is ABOVE the nominal.
    # If yes, add in quadrature to get "combined up" weight
    for sys in hists:
        if sys == 'NONE': continue

        weight = hists[sys].Integral()

        if weight < nominal:
            syst_down += (nominal - weight)**2
    syst_down = math.sqrt(syst_down)

    return abs(syst_down/nominal)

if __name__ == '__main__':
    doSystematics('output.root')
