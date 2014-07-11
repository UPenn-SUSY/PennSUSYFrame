#!/usr/bin/env python

import ROOT

# ------------------------------------------------------------------------------
def getColor(slice_it):
    color = ROOT.kAzure - 10 + slice_it
    if color > ROOT.kAzure+10:
        remainder = color - ROOT.kAzure+10
        color = ROOT.kTeal - 8 + remainder
    return color

# ------------------------------------------------------------------------------
def getSlices(h_2d):
    hist_name_base = h_2d.GetName()
    num_slices = h_2d.GetNbinsX()
    print num_slices

    slice_hists = []
    for slice_it in xrange(1, num_slices+1):
        print 'slice ', slice_it
        this_name = '%s__%d' % (hist_name_base, slice_it)

        this_hist = h_2d.ProjectionY(this_name, slice_it, slice_it)
        # if this_hist.GetEntries() < 20:
        if this_hist.GetEntries() < 10:
            this_hist = None
        else:
            this_hist.SetLineColor(getColor(slice_it))
            this_hist.SetLineWidth(3)

        slice_hists.append(this_hist)

    return slice_hists

# ------------------------------------------------------------------------------
def normHist(h):
    h_clone = h.Clone('%s__norm' % h.GetName())
    integral = h_clone.Integral()
    scale = 1 if integral == 0 else 1./integral
    h_clone.Scale(scale)

    return h_clone

# ------------------------------------------------------------------------------
def getNormSlices(h_list):
    norm_slice_list = []
    for h in h_list:
        if h is None:
            norm_slice_list.append(None)
            continue
        h_clone = normHist(h)
        norm_slice_list.append(h_clone)

    return norm_slice_list

# ------------------------------------------------------------------------------
def getMin(h_list):
    global_min = 99999
    global_max = -99999
    if len(h_list) == 0: return 0
    for h in h_list:
        if h is None: continue

        this_min = h.GetMinimum()
        this_max = h.GetMaximum()
        if this_min < global_min: global_min = this_min
        if this_max > global_max: global_max = this_max

    return global_min - 0.2*(global_max - global_min)

# ------------------------------------------------------------------------------
def getMax(h_list):
    global_min = 99999
    global_max = -99999
    if len(h_list) == 0: return 0
    for h in h_list:
        if h is None: continue

        this_min = h.GetMinimum()
        this_max = h.GetMaximum()
        if this_min < global_min: global_min = this_min
        if this_max > global_max: global_max = this_max

    return global_max + 0.2*(global_max - global_min)

# ------------------------------------------------------------------------------
def getFrame(h_list, global_min, global_max, name):
    # if len(h_list) == 0: return None
    # first_non_non = None
    for h in h_list:
        if h is None: continue
        frame = h.Clone(name)
        for bin in xrange(frame.GetNbinsX() + 2):
            frame.SetBinContent(bin, 0.)
            frame.SetBinError(bin, 0.)
        frame.SetEntries(0)
        frame.SetMinimum(global_min)
        frame.SetMaximum(global_max)
        return frame
    return None

# ------------------------------------------------------------------------------
def getRatioPlots(numerator_list, denom):
    ratio_list = []
    denom_clone = denom.Clone('denom__clone')
    denom_clone.Rebin()

    for nl in numerator_list:
        this_ratio = nl.Clone('%s__ratio' % nl.GetName()) if not nl is None else None
        if this_ratio is None: continue
        this_ratio.Rebin()
        # this_ratio.Divide(denom)
        this_ratio.Divide(denom_clone)
        ratio_list.append(this_ratio)
    return ratio_list

# ------------------------------------------------------------------------------
def drawSlicesToCanvas(canvas, slice_list, draw_style = '', full_projection = None):
    canvas.cd()
    # leg = ROOT.TLegend()

    text_x = 0.7
    text_y = 0.9

    text_list = []
    for i, sl in enumerate(slice_list):
        if sl is None: continue

        sl.Draw('%sSAME' % draw_style)
        this_text = ROOT.TText(text_x, text_y, 'Slice %d' % i)
        this_text.SetNDC()
        this_text.SetX(text_x)
        this_text.SetY(text_y)
        this_text.SetTextColor(sl.GetLineColor())
        this_text.Draw()
        text_y -= 0.05
        text_list.append(this_text)

    if full_projection is not None:
        full_projection.Draw('%sSAME' % draw_style)

    return text_list

# ------------------------------------------------------------------------------
def doSliceStack(h_2d, out_file, dir_name):
    # make and go to directory in output file
    out_file.mkdir(dir_name)
    out_file.cd(dir_name)

    # get full projection
    h_full = h_2d.ProjectionY()
    h_full.SetLineColor(ROOT.kBlack)
    h_full.SetLineWidth(4)

    # get full normalized histogram
    h_full_norm = normHist(h_full)

    # get slices from 2d hist
    slices      = getSlices(h_2d)
    norm_slices = getNormSlices(slices)
    ratio_slices = getRatioPlots(norm_slices, h_full_norm)

    global_min = max(0, getMin(slices))
    global_max = getMax(slices)
    print 'global min: ' , global_min
    print 'global max: ' , global_max

    global_norm_min = max(0, getMin(norm_slices))
    global_norm_max = getMax(norm_slices)
    print 'global norm min: ' , global_norm_min
    print 'global norm max: ' , global_norm_max

    # global_ratio_min = max(0, getMin(ratio_slices))
    # global_ratio_max = getMax(ratio_slices)
    global_ratio_min = 0.5
    global_ratio_max = 2.0
    print 'global ratio min: ' , global_ratio_min
    print 'global ratio max: ' , global_ratio_max

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # draw 2d hist
    c_2d = ROOT.TCanvas('c__base__%s' % dir_name)
    h_2d.Draw('COLZ')
    c_2d.Write()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # draw full projection
    c_full = ROOT.TCanvas('c__full__%s' % dir_name)
    h_full.Draw('hist')
    c_full.Write()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # create canvases for all slices to be piles onto (one normalized and one not)
    c_all       = ROOT.TCanvas('c__all__%s'      % dir_name)
    h_all_name  = 'h__all__%s' % dir_name
    h_all_frame = getFrame( slices
                          , global_min
                          , global_max
                          , h_all_name
                          )
    h_all_frame.Draw()

    c_all_norm       = ROOT.TCanvas('c__all_norm__%s' % dir_name)
    h_all_norm_name = 'h__all_norm__%s' % dir_name
    h_all_norm_frame = getFrame( norm_slices
                               , global_norm_min
                               , global_norm_max
                               , h_all_norm_name
                               )
    h_all_norm_frame.Draw()

    c_ratio       = ROOT.TCanvas('c__ratio__%s' % dir_name)
    h_ratio_name = 'h__ratio__%s' % dir_name
    h_ratio_frame = getFrame( norm_slices
                            , global_ratio_min
                            , global_ratio_max
                            , h_ratio_name
                            )
    h_ratio_frame.Draw()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # loop through all slices and draw to canvas
    for i, s in enumerate(slices):
        if s is None: continue

        this_c = ROOT.TCanvas('c__%d__%s' % (i, dir_name))
        s.Draw('HIST')
        this_c.Write()

    i_hate_root_0 = drawSlicesToCanvas(c_all, slices, 'hist', h_full)
    i_hate_root_1 = drawSlicesToCanvas(c_all_norm, norm_slices, 'hist', h_full_norm)
    i_hate_root_2 = drawSlicesToCanvas(c_ratio, ratio_slices)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # write canvases to file
    c_all.Write()
    c_all_norm.Write()
    c_ratio.Write()

# ------------------------------------------------------------------------------
def main():
    in_file_name = "${BASE_WORK_DIR}/NextPlotDir.BMinusL/BMinusL.117050.PowhegPythia_P2011C_ttbar.hists.root"
    # in_file_name = "${BASE_WORK_DIR}/NextPlotDir.BMinusL/BMinusL.202638.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_700.hists.root"
    in_file = ROOT.TFile.Open(in_file_name)

    print in_file.GetListOfKeys()
    list_of_dirs = [key.GetName() for key in in_file.GetListOfKeys()]


    out_file_name = 'out.root'
    out_file = ROOT.TFile.Open(out_file_name, 'recreate')

    for dir_name in list_of_dirs:
        if dir_name == 'TotalNumEvents': continue
        print 'making plots for ' , dir_name
        d = in_file.Get(dir_name)

        flavor_channel = 'all'
        h_2d = d.Get('flavor_%s__mbl_vs_ht_all__%s' % (flavor_channel, dir_name))

        doSliceStack(h_2d, out_file, dir_name)

# ==============================================================================
if __name__ == "__main__":
    ROOT.gROOT.SetBatch(1)
    main()
