#!/usr/bin/env python 

import ROOT

import sys
import os
sys.path.append('%s/BMinusLAnalysis/FitHelpers/' % os.environ['BASE_WORK_DIR'])
import FitHelpers as fh

# ==============================================================================
# RooRealVar variables used all over the place
# mbl
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
def main():
    ROOT.gROOT.SetBatch()

    # Create workspace to contain full analysis
    model = ROOT.RooWorkspace('model', True)

    # get toy histogram
    toy_data_dh = fh.getHistFromFile( file_name    = toy_data_file_name
                                    , hist_name    = 'toy__flavor_all__mbl_all__BMINUSL_MET'
                                    , roo_real_var = mbl_real_var
                                    , label        = 'toy'
                                    , model        = model
                                    )['dh']
    model.Print()
    print toy_data_dh

    # --------------------------------------------------------------------------
    bkg_pdf_basic = getFunctionalForm('basic', mbl_real_var, model)
    bkg_pdf_basic.fitTo(toy_data_dh)

    # --------------------------------------------------------------------------
    # draw background template to a canvas
    plot_basic_lin = fh.drawToCanvas( roo_object_list   = [ toy_data_dh, bkg_pdf_basic ]
                                    , roo_real_var      = mbl_real_var
                                    , line_colors       = [ROOT.kBlack, ROOT.kBlue]
                                    , label             = 'basic'
                                    , range_string_list = ['', '']
                                    , log               = False
                                    )
    plot_basic_log = fh.drawToCanvas( roo_object_list   = [ toy_data_dh, bkg_pdf_basic ]
                                    , roo_real_var      = mbl_real_var
                                    , line_colors       = [ROOT.kBlack, ROOT.kBlue]
                                    , label             = 'basic'
                                    , range_string_list = ['', '']
                                    , log               = True
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
