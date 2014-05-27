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
mbl_max = 1200
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
def getPdfFromFile(file_name, hist_name, roo_real_var, label):
    # get data histogram
    f_data = ROOT.TFile.Open(file_name)
    h_data = f_data.Get(hist_name)
    print 'integral of %s: %s' % (label, h_data.Integral())

    # make RooDataHist of data hist
    arg_list = ROOT.RooArgList(roo_real_var)
    data_dh = ROOT.RooDataHist( '%s_dh' % label
                              , h_data.GetTitle()
                              , arg_list
                              , h_data
                              , 1.0
                              )

    # make RooHistPdf of data histogram
    arg_set = ROOT.RooArgSet(roo_real_var)
    data_pdf = ROOT.RooHistPdf( '%s_pdf' % label
                              , h_data.GetTitle()
                              , arg_set
                              , data_dh
                              )

    frame = mbl_real_var.frame()
    data_pdf.plotOn( frame
                   , ROOT.RooFit.LineColor(ROOT.kBlack)
                   , ROOT.RooFit.LineWidth(2)
                   )
    c_data = ROOT.TCanvas('data_%s' % hist_name)
    frame.Draw()

    return { 'hist':h_data
           , 'dh':data_dh
           , 'pdf':data_pdf
           , 'arg_list':arg_list
           , 'arg_set':arg_set
           }

# ------------------------------------------------------------------------------
def getFunctionalForm( function_name
                     , roo_real_var
                     ):
    p0 = ROOT.RooRealVar('p0', 'p0', 1)
    p1 = ROOT.RooRealVar('p1', 'p1', 1)
    p2 = ROOT.RooRealVar('p2', 'p2', 1)
    p3 = ROOT.RooRealVar('p3', 'p3', 1)

    bkg_pdf = ROOT.RooGenericPdf('bkg_pdf', 'bkg_pdf', '@0*(1-@4)^@1 * @4^(@2+@3*log(@4))', ROOT.RooArgList(p0, p1, p2, p3, roo_real_var))

    return {'pdf':bkg_pdf , 'parameters':[p0,p1,p2,p3]}

# ------------------------------------------------------------------------------
def drawToCanvas( roo_object_list
                , roo_real_var
                , line_colors
                , label
                , range_string_list
                , log = False
                ):
    print range_string_list

    if not len(line_colors) == len(roo_object_list):
        line_colors = [ROOT.kBlack]*len(roo_object_list)

    frame = roo_real_var.frame()

    for i, rol in enumerate(roo_object_list):
        if isinstance(rol, ROOT.RooDataHist):
            rol.plotOn( frame
                      , ROOT.RooFit.LineColor(line_colors[i])
                      , ROOT.RooFit.LineWidth(3)
                      , ROOT.RooFit.DataError(ROOT.RooAbsData.SumW2)
                      # this_range
                      )
        elif range_string_list[i] == '':
            this_range = ROOT.RooFit.Range('full_range')
            rol.plotOn( frame
                      , ROOT.RooFit.LineColor(line_colors[i])
                      , ROOT.RooFit.LineWidth(3)
                      # this_range
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

    # get toy histogram
    toy_data_dict = getPdfFromFile( file_name = toy_data_file_name
                                  , hist_name = 'toy__flavor_all__mbl_all__BMINUSL_MET'
                                  , roo_real_var = mbl_real_var
                                  , label = 'toy'
                                  )


    # --------------------------------------------------------------------------
    # Crystal ball background function
    cb_mean  = ROOT.RooRealVar('cb_mean' , 'cb_mean' , 175, 0, 1000)
    cb_sigma = ROOT.RooRealVar('cb_sigma', 'cb_sigma', 10 , 0, 100)
    cb_alpha = ROOT.RooRealVar('cb_alpha', 'cb_alpha', -1 , -100, 100)
    cb_n     = ROOT.RooRealVar('cb_n'    , 'cb_n'    , 1  , -100, 100)
    bkg_cb = ROOT.RooCBShape( 'bkg_cb'
                            , 'bkg_cb'
                            , mbl_real_var
                            , cb_mean
                            , cb_sigma
                            , cb_alpha
                            , cb_n
                            )

    # argus background function
    argus_m0 = ROOT.RooRealVar('argus_m0', 'argus_m0', 4000, 400, 4000)
    argus_c  = ROOT.RooRealVar('argus_c' , 'argus_c' , -10, -100, 100)
    bkg_argus = ROOT.RooArgusBG( 'bkg_argus'
                               , 'bkg_argus'
                               , mbl_real_var
                               , argus_m0
                               , argus_c
                               )

    # combined background function
    yield_cb    = ROOT.RooRealVar('yield_cb'   , 'yield_cb'   , 1)
    yield_argus = ROOT.RooRealVar('yield_argus', 'yield_argus', 1)
    bkg_pdf = ROOT.RooAddPdf( 'bkg_pdf'
                            , 'bkg_pdf'
                            , ROOT.RooArgList(bkg_cb)
                            , ROOT.RooArgList(yield_cb)
                            # , ROOT.RooArgList(bkg_cb, bkg_argus)
                            # , ROOT.RooArgList(yield_cb, yield_argus)
                            )

    # Create workspace to contain full analysis
    model = ROOT.RooWorkspace('model', True)
    getattr(model, 'import')(bkg_pdf)

    ROOT.model.bkg_pdf.fitTo(toy_data_dict['dh'])
    # --------------------------------------------------------------------------

    # draw background template to a canvas
    mbl_frame = mbl_real_var.frame()
    toy_data_dict['dh'].plotOn(mbl_frame)
    model.pdf('bkg_pdf').plotOn(mbl_frame)
    model.pdf('bkg_pdf').paramOn(mbl_frame)

    c_basic_fit = ROOT.TCanvas('c_basic_fit')
    mbl_frame.Draw()

    out_file = ROOT.TFile('fit.root', 'RECREATE')
    out_file.cd()
    c_basic_fit.Write('c_basic_fit_lin')
    c_basic_fit.SetLogy(True)
    c_basic_fit.Write('c_basic_fit_log')

    out_file.Close()

# ==============================================================================
if __name__ == "__main__":
    main()
