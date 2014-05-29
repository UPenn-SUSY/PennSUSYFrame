#!/usr/bin/env python 

import ROOT

# ------------------------------------------------------------------------------
def getPdfFromFile( file_name
                  , hist_name
                  , roo_real_var
                  , label
                  , model
                  ):
    # get data histogram
    f_data = ROOT.TFile.Open(file_name)
    h_data = f_data.Get(hist_name)
    print 'integral of %s: %s' % (label, h_data.Integral())

    # make RooDataHist of data hist
    data_dh = ROOT.RooDataHist( '%s_dh' % label
                              , h_data.GetTitle()
                              # , arg_list
                              , ROOT.RooArgList(roo_real_var)
                              , h_data
                              , 1.0
                              )

    # make RooHistPdf of data histogram
    data_pdf = ROOT.RooHistPdf( '%s_pdf' % label
                              , h_data.GetTitle()
                              # , arg_set
                              , ROOT.RooArgSet(roo_real_var)
                              , data_dh
                              )

    getattr(model, 'import')(data_dh)
    getattr(model, 'import')(data_pdf)
    return getattr(ROOT.model, '%s_dh' % label)

# ------------------------------------------------------------------------------
def drawToCanvas( roo_object_list
                , roo_real_var
                , line_colors
                , label
                , range_string_list
                , log = False
                ):
    if not len(line_colors) == len(roo_object_list):
        line_colors = [ROOT.kBlack]*len(roo_object_list)

    frame = roo_real_var.frame()

    for i, rol in enumerate(roo_object_list):
        if isinstance(rol, ROOT.RooDataHist):
            rol.plotOn( frame
                      , ROOT.RooFit.LineColor(line_colors[i])
                      , ROOT.RooFit.LineWidth(3)
                      , ROOT.RooFit.DataError(ROOT.RooAbsData.SumW2)
                      )
        elif range_string_list[i] == '':
            this_range = ROOT.RooFit.Range('full_range')
            rol.plotOn( frame
                      , ROOT.RooFit.LineColor(line_colors[i])
                      , ROOT.RooFit.LineWidth(3)
                      )
        else:
            this_range = ROOT.RooFit.Range(range_string_list[i])
            rol.plotOn( frame
                      , ROOT.RooFit.LineColor(line_colors[i])
                      , ROOT.RooFit.LineWidth(3)
                      , this_range
                      )

    c = ROOT.TCanvas('c_%s_%s' % (label, 'log' if log else 'lin') )
    if log: c.SetLogy()
    frame.Draw()
    return {'frame':frame, 'canv':c}

# ------------------------------------------------------------------------------
def getNumBinsInRegion( region_string, roo_real_var, template_hist):
    print 'getting ndof for %s' % region_string

    ndof = 0
    if region_string == '':
        ndof = roo_real_var.getBins()
    else:
        for rs in region_string.split(','):
            if rs == '':
                continue

            this_min = roo_real_var.getMin(rs)
            this_max = roo_real_var.getMax(rs)

            min_bin = template_hist.GetXaxis().FindBin(this_min)
            max_bin = template_hist.GetXaxis().FindBin(this_max)

            ndof += (max_bin - min_bin)

    if ndof == 0: ndof = 1
    return ndof

