#!/usr/bin/env python
# ==============================================================================
# = usage:
# = ./CreateRandomBackground.py <path to input file> {target num events> <mass to inject signal -- 0 if no signal>
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
def makeSingleToyDist(template_hist, label, num_events, inject_signal, signal_events):
    print type(template_hist)
    n_bins = template_hist.GetXaxis().GetNbins()
    x_min = template_hist.GetXaxis().GetXmin()
    x_max = template_hist.GetXaxis().GetXmax()
    print 'n_bins: %s' % n_bins
    print 'x_min: %s' % x_min
    print 'x_max: %s' % x_max

    toy = ROOT.TH1F('toy__%s' % label, label, n_bins, x_min, x_max)
    toy.FillRandom(template_hist, num_events)

    toy_signal = None
    if inject_signal > 0:
        print 'injecting fake signal'
        f = ROOT.TF1('fake_signal', 'gaus(0)', x_min, x_max)

        central_value = inject_signal
        width = inject_signal/20
        num_signal = signal_events if signal_events > 0 else num_events/10

        f.SetParameter(0, 1)
        f.SetParameter(1, central_value)
        f.SetParameter(2, width)

        print 'central_value: %s ' % central_value
        print 'width: %s ' % width
        print 'num_signal: %s ' % num_signal

        toy_signal = ROOT.TH1F('toy_signal__%s' % label, label, n_bins, x_min, x_max)
        toy_signal.FillRandom('fake_signal', num_signal)
        toy.Add(toy_signal)
        # for i in xrange(int(num_events/10)):
        #     toy.Fill(inject_signal)

    return {'toy':toy, 'toy_sig':toy_signal}

# ------------------------------------------------------------------------------
def makeToyDists(template_dict, target_events, inject_signal, signal_events):
    toy_dict = {}
    for td in template_dict:
        toy = makeSingleToyDist( template_dict[td]
                               , td
                               , target_events
                               , inject_signal
                               , signal_events
                               )
        toy_dict[td] = toy

    return toy_dict

# ==============================================================================
def main():
    input_file_name = sys.argv[1]
    target_events = int(sys.argv[2])
    inject_signal = 0 if len(sys.argv) < 4 else int(sys.argv[3])
    signal_events = 0 if len(sys.argv) < 5 else int(sys.argv[4])

    print 'input file name: %s' % input_file_name
    print 'target events: %d' % target_events
    print 'inject signal: %d' % inject_signal
    print 'signal events: %d' % signal_events

    in_file = ROOT.TFile.Open(input_file_name)
    template_dict = getDictOfTemplates(in_file)

    toy_dict = makeToyDists( template_dict
                           , target_events
                           , inject_signal
                           , signal_events
                           )

    out_file = ROOT.TFile.Open('Toys.root', 'RECREATE')
    for td in toy_dict:
        toy_dict[td]['toy'].Write()
        if not toy_dict[td]['toy_sig'] is None:
            toy_dict[td]['toy_sig'].Write()
    out_file.Close()

# ==============================================================================
if __name__ == '__main__':
    main()
