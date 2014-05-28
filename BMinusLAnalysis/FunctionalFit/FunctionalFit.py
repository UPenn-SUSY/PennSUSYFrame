#!/usr/bin/env python 

import ROOT

# ==============================================================================
# RooRealVar variables used all over the place
# make RooRealVar for mbl
# mbl_bins = 120
# mbl_min = 0
# mbl_max = 1200
mbl_bins = 50
mbl_min = 0
mbl_max = 500
mbl_real_var = ROOT.RooRealVar( 'mbl'
                              , 'mbl [GeV]'
                              , mbl_min
                              , mbl_max
                              )
mbl_real_var.setBinning( ROOT.RooBinning( mbl_bins, mbl_min, mbl_max) )
mbl_real_var.setRange( 'full_range', mbl_min, mbl_max )

# ==============================================================================
# = toy data files -- uncomment one of these lines
# ==============================================================================
# toy data with no injected signal - derived from full MC statistics shape
toy_data_file_name = '../ToyBackgrounds/Toys_no_sig.root'

# toy data with injected signal - derived from full MC statistics shape
# toy_data_file_name = '../ToyBackgrounds/Toys_w_sig.root'

# toy data with no injected signal - derived from shape of first half of MC
# toy_data_file_name = '../ToyBackgrounds/Toys__partia_sample_0_of_2__no_sig.root'

# toy data with injected signal - derived from shape of first half of MC
# toy_data_file_name = '../ToyBackgrounds/Toys__partia_sample_0_of_2__w_sig.root'

# toy data with no injected signal - derived from shape of second half of MC
# toy_data_file_name = '../ToyBackgrounds/Toys__partia_sample_1_of_2__no_sig.root'

# toy data with injected signal - derived from shape of second half of MC
# toy_data_file_name = '../ToyBackgrounds/Toys__partia_sample_1_of_2__w_sig.root'

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
def getFunctionalForm( function_tag
                     , roo_real_var
                     , model
                     ):
    # --------------------------------------------------------------------------
    # Crystal ball background function
    cb_mean  = ROOT.RooRealVar('cb_mean__%s'  % function_tag, 'cb_mean__%s'  % function_tag, 175, 0, 1000)
    cb_sigma = ROOT.RooRealVar('cb_sigma__%s' % function_tag, 'cb_sigma__%s' % function_tag, 10 , 0, 100)
    cb_alpha = ROOT.RooRealVar('cb_alpha__%s' % function_tag, 'cb_alpha__%s' % function_tag, -1 , -100, 100)
    cb_n     = ROOT.RooRealVar('cb_n__%s'     % function_tag, 'cb_n__%s'     % function_tag, 1  , -100, 100)
    bkg_cb = ROOT.RooCBShape( 'bkg_cb__%s' % function_tag
                            , 'bkg_cb__%s' % function_tag
                            , roo_real_var
                            , cb_mean
                            , cb_sigma
                            , cb_alpha
                            , cb_n
                            )

    # argus background function
    argus_m0 = ROOT.RooRealVar('argus_m0__%s' % function_tag, 'argus_m0__%s', 4000, 400, 4000)
    argus_c  = ROOT.RooRealVar('argus_c__%s'  % function_tag, 'argus_c__%s' , -10, -100, 100)
    bkg_argus = ROOT.RooArgusBG( 'bkg_argus__%s' % function_tag
                               , 'bkg_argus__%s' % function_tag
                               , roo_real_var
                               , argus_m0
                               , argus_c
                               )

    # combined background function
    yield_cb    = ROOT.RooRealVar('yield_cb__%s'   % function_tag, 'yield_cb__%s'   % function_tag, 1)
    yield_argus = ROOT.RooRealVar('yield_argus__%s'% function_tag, 'yield_argus__%s'% function_tag, 1)
    bkg_pdf = ROOT.RooAddPdf( 'bkg_pdf__%s' % function_tag
                            , 'bkg_pdf__%s' % function_tag
                            , ROOT.RooArgList(bkg_cb)
                            , ROOT.RooArgList(yield_cb)
                            # , ROOT.RooArgList(bkg_cb, bkg_argus)
                            # , ROOT.RooArgList(yield_cb, yield_argus)
                            )

    # Create workspace to contain full analysis
    getattr(model, 'import')(bkg_pdf)

    print 'returning pdf: bkg_pdf__%s' % function_tag
    return model.pdf('bkg_pdf__%s' % function_tag)

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


# ------------------------------------------------------------------------------
def main():
    ROOT.gROOT.SetBatch()

    # Create workspace to contain full analysis
    model = ROOT.RooWorkspace('model', True)

    # get toy histogram
    toy_data_dh = getPdfFromFile( file_name = toy_data_file_name
                                , hist_name = 'toy__flavor_all__mbl_all__BMINUSL_MET'
                                , roo_real_var = mbl_real_var
                                , label = 'toy'
                                , model = model
                                )
    model.Print()
    print toy_data_dh

    # --------------------------------------------------------------------------
    bkg_pdf_basic = getFunctionalForm('basic', mbl_real_var, model)
    bkg_pdf_basic.fitTo(toy_data_dh)

    # --------------------------------------------------------------------------
    # draw background template to a canvas
    plot_basic_lin = drawToCanvas( roo_object_list = [ toy_data_dh, bkg_pdf_basic ]
                                 , roo_real_var = mbl_real_var
                                 , line_colors = [ROOT.kBlack, ROOT.kBlue]
                                 , label = 'basic'
                                 , range_string_list = ['', '']
                                 , log = False
                                 )
    plot_basic_log = drawToCanvas( roo_object_list = [ toy_data_dh, bkg_pdf_basic ]
                                 , roo_real_var = mbl_real_var
                                 , line_colors = [ROOT.kBlack, ROOT.kBlue]
                                 , label = 'basic'
                                 , range_string_list = ['', '']
                                 , log = True
                                 )

    # --------------------------------------------------------------------------
    out_file = ROOT.TFile('fit.root', 'RECREATE')
    out_file.cd()
    plot_basic_lin['canv'].Write('c_fit_basic__lin')
    plot_basic_log['canv'].Write('c_fit_basic__log')
    out_file.Close()

    # --------------------------------------------------------------------------
    model.writeToFile('fit_workspace.root', True)

# ==============================================================================
if __name__ == "__main__":
    main()
