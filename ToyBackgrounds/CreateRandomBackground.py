#!/usr/bin/env python
# ==============================================================================
# = usage:
# = ./CreateRandomBackground.py <path to input file> {target num events> <mass to inject singal -- 0 if no singal>
# ==============================================================================

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
def makeSingleToyDist(template_hist, label, num_events, inject_signal):
    print type(template_hist)
    n_bins = template_hist.GetXaxis().GetNbins()
    x_min = template_hist.GetXaxis().GetXmin()
    x_max = template_hist.GetXaxis().GetXmax()
    print 'n_bins: %s' % n_bins
    print 'x_min: %s' % x_min
    print 'x_max: %s' % x_max

    toy = ROOT.TH1F('toy__%s' % label, label, n_bins, x_min, x_max)
    toy.FillRandom(template_hist, num_events)

    if inject_signal > 0:
        print 'injecting fake signal'
        f = ROOT.TF1('fake_signal', 'gaus(0)', x_min, x_max)

        central_value = inject_signal
        # width = inject_signal/10
        # width = inject_signal/100
        width = 5
        num_singal = num_events/10

        f.SetParameter(0, 1)
        f.SetParameter(1, central_value)
        f.SetParameter(2, width)

        print 'central_value: %s ' % central_value
        print 'width: %s ' % width
        print 'num_singal: %s ' % num_singal

        toy_signal = ROOT.TH1F('toy_signal__%s' % label, label, n_bins, x_min, x_max)
        toy_signal.FillRandom('fake_signal', num_events/10)
        toy.Add(toy_signal)
        # for i in xrange(int(num_events/10)):
        #     toy.Fill(inject_signal)

    return toy

# ------------------------------------------------------------------------------
def makeToyDists(template_dict, target_events, inject_signal):
    toy_dict = {}
    for td in template_dict:
        toy = makeSingleToyDist(template_dict[td], td, target_events, inject_signal)
        toy_dict[td] = toy

    return toy_dict

# ==============================================================================
def main():
    input_file_name = sys.argv[1]
    target_events = int(sys.argv[2])
    inject_signal = int(sys.argv[3])

    print 'input file name: %s' % input_file_name
    print 'target events: %d' % target_events
    print 'inject singal: %d' % inject_signal

    in_file = ROOT.TFile.Open(input_file_name)
    template_dict = getDictOfTemplates(in_file)

    toy_dict = makeToyDists(template_dict, target_events, inject_signal)

    out_file = ROOT.TFile.Open('Toys.root', 'RECREATE')
    for td in toy_dict:
        toy_dict[td].Write()
    out_file.Close()

# ==============================================================================
if __name__ == '__main__':
    main()
