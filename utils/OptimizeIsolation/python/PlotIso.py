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
                ):
        self.file_name = file_name
        self.file = ROOT.TFile.Open(file_name)
        self.label = label
        self.color = color

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
        h = fhl.getHist(hist_name, True)
        leg.AddEntry(    h, fhl.label)
        big_leg.AddEntry(h, fhl.label)

    return leg, big_leg

# ------------------------------------------------------------------------------
def getHistStack( file_handles
                , hist_name
                , stack_name
                , stack_title
                , x_min = None
                , x_max = None
                ):
    hist_list = []
    label_list = []
    ths = ROOT.THStack(stack_name, stack_title)
    for fh in file_handles:
        h = fh.getHist(hist_name, True)
        findTargetCut(h, 0.90)
        findTargetCut(h, 0.95)
        h.Rebin(5)
        truncateXaxis(h, x_min, x_max)

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
                  , x_min
                  , x_max
                  ):
    hist_list_2d = []
    label_list = []
    ths_list = []
    num_slices = 0
    for fh in file_handles:
        h_2d = fh.getHist(hist_name, True)
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
            h_tmp.Rebin(5)
            truncateXaxis(h_tmp, x_min, x_max)
            normalizeHist(h_tmp)
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
                              , x_min
                              , x_max
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
            h_tmp.Rebin(5)
            truncateXaxis(h_tmp, x_min, x_max)
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
                 , x_min = None
                 , x_max = None
                 , y_min = None
                 , y_max = None
                 ):
    c = ROOT.TCanvas(canvas_name)
    if ths is not None:
        if isinstance(ths, ROOT.THStack):
            ths.Draw('NOSTACK')
            if ths.GetXaxis():
                ths.GetXaxis().SetTitle(x_title)
                if x_min is not None and x_max is not None:
                    ths.GetXaxis().SetRangeUser(x_min, x_max)
            if ths.GetYaxis():
                ths.GetYaxis().SetTitle(y_title)
            if y_min is not None: ths.SetMinimum(y_min)
            if y_max is not None: ths.SetMaximum(y_max)
            ths.Draw('NOSTACK')
        else:
            if ths.GetXaxis():
                ths.GetXaxis().SetTitle(x_title)
                if x_min is not None and x_max is not None:
                    ths.GetXaxis().SetRangeUser(x_min, x_max)
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
def getCutValueLabels(chosen_cut_values):
    x_start = 0.65
    y_start = 0.8
    label_list = []
    for eff in chosen_cut_values:
        for entry in chosen_cut_values[eff]:
            text_for_label = 'eff %s (%s): %0.2f' % (eff, entry['label'], entry['cut'])
            l = ROOT.TText()
            l.SetNDC()
            l.SetText(x_start, y_start, text_for_label)
            l.SetTextColor(entry['color'])
            l.SetTextSize(0.035)
            y_start -= 0.035
            label_list.append(l)

            if 'signal' in entry['label']:
                line = ROOT.TLine(entry['cut'], 1.e-6, entry['cut'], 5)
                line.SetLineWidth(3)
                line.SetLineColor(ROOT.kGreen+3)
                label_list.append(line)

    return label_list

# ------------------------------------------------------------------------------
def plotAndPrint( file_handles
                , out_file
                , short_name
                , iso_suffix
                , x_min
                , x_max
                , y_min
                , y_max
                , x_title = 'isolation'
                ):
    # scan and pick chosen cut values for each histogram
    chosen_cut_values = { '0.90':getCutValues( file_handles
                                             , '%s%s' % (short_name, iso_suffix)
                                             , 0.90
                                             )
                        , '0.95':getCutValues( file_handles
                                             , '%s%s' % (short_name, iso_suffix)
                                             , 0.95
                                             )
                        }
    cut_value_labels = getCutValueLabels(chosen_cut_values)

    # get stack and legend
    ths, leg, big_leg = getHistStack( file_handles
                                    , '%s%s' % (short_name, iso_suffix)
                                    , 'ths_%s%s' % (short_name, iso_suffix)
                                    , '%s' % short_name
                                    , x_min
                                    , x_max
                                    )

    # print stack and legend to canvas
    c = printToCanvas( ths=ths
                     , leg=leg
                     , canvas_name='c_%s%s' % (short_name, iso_suffix)
                     , labels = cut_value_labels
                     , x_title=x_title
                     , y_title='normailzed units'
                     , x_min = x_min
                     , x_max = x_max
                     , y_min = y_min
                     , y_max = y_max
                     )
    c_big_leg = printToCanvas( leg=big_leg
                             , canvas_name='c_leg_%s%s' % (short_name, iso_suffix)
                             )

    # make directory for isolation
    safeMakeDir(out_file, '%s' % short_name)

    # print isolation
    c.SetLogy()
    c.Write('%s%s' % (short_name, iso_suffix))
    c_big_leg.Write('leg_%s%s' % (short_name, iso_suffix))
    c.Close()
    c_big_leg.Close()

# ------------------------------------------------------------------------------
def plotAndPrint2D( file_handles
                  , out_file
                  , short_name
                  , iso_suffix
                  , x_min
                  , x_max
                  , y_min
                  , y_max
                  , slice_variable_name
                  , x_title = 'isolation'
                  ):
    # get stack and legend
    ths_list, leg, big_leg = getHistStack2D( file_handles
                                           , '%s%s' % (short_name, iso_suffix)
                                           , 'ths_%s%s' % (short_name, iso_suffix)
                                           , '%s' % short_name
                                           , x_min
                                           , x_max
                                           )

    # get stacks for one sample ata time
    ths_ss_list, leg_ss_list, big_leg_ss_list = getHistStack2DSingleSample( file_handles
                                                                          , '%s%s' % (short_name, iso_suffix)
                                                                          , 'ths_%s%s' % (short_name, iso_suffix)
                                                                          , '%s' % short_name
                                                                          , x_min
                                                                          , x_max
                                                                          , slice_variable_name
                                                                          )

    # print sliced stacks canvas
    for i, ths in enumerate(ths_list):
        c = printToCanvas( ths=ths
                         , leg=leg
                         , canvas_name='c_%s%s__slice_%d' % (short_name, iso_suffix, i)
                         , x_title=x_title
                         , y_title='normailzed units'
                         , x_min = x_min
                         , x_max = x_max
                         , y_min = y_min
                         , y_max = y_max
                         )
        # print isolation
        c.SetLogy()
        safeMakeDir(out_file, '%s' % short_name)
        c.Write('%s%s__slice_%d' % (short_name, iso_suffix, i))
        c.Close()

    # print single sample sliced stacks canvas
    for i, ths in enumerate(ths_ss_list):
        label = file_handles[i].label
        c = printToCanvas( ths=ths
                         , leg=leg_ss_list[i]
                         , canvas_name='c_%s%s__%s' % (short_name, iso_suffix, label)
                         , x_title=x_title
                         , y_title='normailzed units'
                         , x_min = x_min
                         , x_max = x_max
                         , y_min = y_min
                         , y_max = y_max
                         )
        c.SetLogy()
        safeMakeDir(out_file, '%s' % short_name)
        c.Write('%s%s__%s' % (short_name, iso_suffix, label))
        c.Close()

    # print big legend
    c_big_leg = printToCanvas( leg=big_leg
                             , canvas_name='c_leg_%s%s' % (short_name, iso_suffix)
                             )
    safeMakeDir(out_file, '%s' % short_name)
    c_big_leg.Write('leg_%s%s' % (short_name, iso_suffix))
    c_big_leg.Close()


# ------------------------------------------------------------------------------
def plotIso(file_handles
           , out_file
           , lep_flavor = 'el'
           , iso_suffix = ''
           , x_min = None
           , x_max = None
           , x_title = 'isolation'
           ):
    plotAndPrint( file_handles = file_handles
                , out_file = out_file
                , short_name = '%s_iso' % lep_flavor
                , iso_suffix = iso_suffix
                , x_min = x_min
                , x_max = x_max
                , y_min = 1.e-6
                , y_max = 5.
                , x_title = x_title
                )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    plotAndPrint2D( file_handles = file_handles
                  , out_file = out_file
                  , short_name = '%s_iso_pt_bins' % lep_flavor
                  , iso_suffix = iso_suffix
                  , x_min = x_min
                  , x_max = x_max
                  , y_min = 1.e-6
                  , y_max = 5.
                  , x_title = x_title
                  , slice_variable_name = 'p_{T}'
                  )

    plotAndPrint2D( file_handles = file_handles
                  , out_file = out_file
                  , short_name = '%s_iso_eta_bins' % lep_flavor
                  , iso_suffix = iso_suffix
                  , x_min = x_min
                  , x_max = x_max
                  , y_min = 1.e-6
                  , y_max = 5.
                  , x_title = x_title
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
    file_handles.append(FileHandle( 'iso.105200.ttbar.root'
                                  , 'ttbar'
                                  , this_color
                                  )
                       )
    this_color += 1

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # add signal
    # rates.127994.signal.root
    # rates.127995.signal.root
    # rates.127996.signal.root
    this_color = ROOT.kRed
    file_handles.append(FileHandle( 'iso.127995.signal.root'
                                  , 'signal 127995'
                                  , this_color
                                  )
                       )
    this_color += 1


    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    out_file = ROOT.TFile('iso.canv.root', 'RECREATE')

    plotIso(file_handles, out_file, 'el', '_PTCONE30'       , 0.  , 1., x_title = 'ptcone30/p_{T}'        )
    plotIso(file_handles, out_file, 'el', '_ETCONE30'       , -0.5, 1., x_title = 'etcone30/p_{T}'        )
    plotIso(file_handles, out_file, 'el', '_PTCONE20'       , 0.  , 1., x_title = 'ptcone20/p_{T}'        )
    plotIso(file_handles, out_file, 'el', '_ETCONE20'       , -0.5, 1., x_title = 'etcone20/p_{T}'        )
    plotIso(file_handles, out_file, 'el', '_PTCONE30_CAPPED', 0.  , 1., x_title = 'ptcone30/min(p_{T},60)')
    plotIso(file_handles, out_file, 'el', '_ETCONE30_CAPPED', -0.5, 1., x_title = 'etcone30/min(p_{T},60)')
    plotIso(file_handles, out_file, 'el', '_PTCONE20_CAPPED', 0.  , 1., x_title = 'ptcone20/min(p_{T},60)')
    plotIso(file_handles, out_file, 'el', '_ETCONE20_CAPPED', -0.5, 1., x_title = 'etcone20/min(p_{T},60)')

    plotIso(file_handles, out_file, 'mu', '_PTCONE30'       , 0.  , 1., x_title = 'ptcone30/p_{T}'        )
    plotIso(file_handles, out_file, 'mu', '_ETCONE30'       , -0.5, 1., x_title = 'etcone30/p_{T}'        )
    plotIso(file_handles, out_file, 'mu', '_PTCONE20'       , 0.  , 1., x_title = 'ptcone20/p_{T}'        )
    plotIso(file_handles, out_file, 'mu', '_ETCONE20'       , -0.5, 1., x_title = 'etcone20/p_{T}'        )
    plotIso(file_handles, out_file, 'mu', '_PTCONE30_CAPPED', 0.  , 1., x_title = 'ptcone30/min(p_{T},60)')
    plotIso(file_handles, out_file, 'mu', '_ETCONE30_CAPPED', -0.5, 1., x_title = 'etcone30/min(p_{T},60)')
    plotIso(file_handles, out_file, 'mu', '_PTCONE20_CAPPED', 0.  , 1., x_title = 'ptcone20/min(p_{T},60)')
    plotIso(file_handles, out_file, 'mu', '_ETCONE20_CAPPED', -0.5, 1., x_title = 'etcone20/min(p_{T},60)')

    out_file.Close()
