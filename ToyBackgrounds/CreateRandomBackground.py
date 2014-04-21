#!/usr/bin/env python

import sys
import ROOT

# ------------------------------------------------------------------------------
def getDictOfTemplates(f):
    template_dict = {}

    key_list = f.GetListOfKeys()
    for kl in key_list:
        print kl
        print kl.ReadObj()
        print kl.GetName()
        label = kl.GetName().strip("template__")

        template_dict[label] = kl.ReadObj()

    return template_dict

# ------------------------------------------------------------------------------
def makeSingleToyDist(template_hist, label, num_events):
    print type(template_hist)
    n_bins = template_hist.GetXaxis().GetNbins()
    x_min = template_hist.GetXaxis().GetXmin()
    x_max = template_hist.GetXaxis().GetXmax()
    print 'n_bins: %s' % n_bins
    print 'x_min: %s' % x_min
    print 'x_max: %s' % x_max

    toy = ROOT.TH1F('toy__%s' % label, label, n_bins, x_min, x_max)
    toy.FillRandom(template_hist, num_events)
    return toy

# ------------------------------------------------------------------------------
def makeToyDists(template_dict, target_events):
    toy_dict = {}
    for td in template_dict:
        toy = makeSingleToyDist(template_dict[td], td, target_events)
        toy_dict[td] = toy

    return toy_dict

# ==============================================================================
def main():
    input_file_name = sys.argv[1]
    target_events = int(sys.argv[2])

    print 'input file name: %s' % input_file_name
    print 'target events: %f' % target_events

    in_file = ROOT.TFile.Open(input_file_name)
    template_dict = getDictOfTemplates(in_file)

    toy_dict = makeToyDists(template_dict, target_events)

    out_file = ROOT.TFile.Open('Toys.root', 'RECREATE')
    for td in toy_dict:
        toy_dict[td].Write()
    out_file.Close()

# ==============================================================================
if __name__ == '__main__':
    main()
