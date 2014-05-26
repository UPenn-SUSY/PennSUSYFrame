#!/usr/bin/env python 

import ROOT

# ==============================================================================
# RooRealVar variables used all over the place
# make RooRealVar for mbl
mbl_bins = 120
mbl_min = 0
mbl_max = 1200
mbl_real_var = ROOT.RooRealVar( 'mbl'
                              , 'mbl'
                              , mbl_min
                              , mbl_max
                              )
mbl_real_var.setBinning( ROOT.RooBinning( mbl_bins, mbl_min, mbl_max) )
mbl_real_var.setRange( 'full_range', mbl_min, mbl_max )

# ==============================================================================
# = background template files -- uncomment one of these lines
# ==============================================================================

# bkg template derived with full MC stats (after cuts)
# bkg_template_file_name = 'Templates/templates.root'

# bkg template derived using first half of MC stats (after cuts)
bkg_template_file_name = 'Templates/templates__partia_sample_0_of_2.root'

# bkg template derived using second half of MC stats (after cuts)
# bkg_template_file_name = 'Templates/templates__partia_sample_1_of_2.root'

# ==============================================================================
# = toy data files -- uncomment one of these lines
# ==============================================================================
# toy data with no injected signal - derived from full MC statistics shape
# toy_data_file_name = '../ToyBackgrounds/Toys_no_sig.root'

# toy data with injected signal - derived from full MC statistics shape
# toy_data_file_name = '../ToyBackgrounds/Toys_w_sig.root'

# toy data with no injected signal - derived from shape of first half of MC
# toy_data_file_name = '../ToyBackgrounds/Toys__partia_sample_0_of_2__no_sig.root'

# toy data with injected signal - derived from shape of first half of MC
# toy_data_file_name = '../ToyBackgrounds/Toys__partia_sample_0_of_2__w_sig.root'

# toy data with no injected signal - derived from shape of second half of MC
# toy_data_file_name = '../ToyBackgrounds/Toys__partia_sample_1_of_2__no_sig.root'

# toy data with injected signal - derived from shape of second half of MC
toy_data_file_name = '../ToyBackgrounds/Toys__partia_sample_1_of_2__w_sig.root'

# ------------------------------------------------------------------------------
def getTemplateFromFile(file_name, template_name, roo_real_var, label):
    # get template histogram
    f_template = ROOT.TFile.Open(file_name)
    h_template = f_template.Get(template_name)
    print 'integral of %s: %s' % (label, h_template.Integral())

    # make RooDataHist of template hist
    arg_list = ROOT.RooArgList(roo_real_var)
    template_dh = ROOT.RooDataHist( '%s_dh' % label
                                  , h_template.GetTitle()
                                  , arg_list
                                  , h_template
                                  , 1.0
                                  )

    # make RooHistPdf of template histogram
    arg_set = ROOT.RooArgSet(roo_real_var)
    template_pdf = ROOT.RooHistPdf( '%s_pdf' % label
                                  , h_template.GetTitle()
                                  , arg_set
                                  , template_dh
                                  )

    frame = mbl_real_var.frame()
    template_pdf.plotOn( frame
                       , ROOT.RooFit.LineColor(ROOT.kBlack)
                       , ROOT.RooFit.LineWidth(2)
                       )
    c_template = ROOT.TCanvas('template')
    frame.Draw()

    return { 'hist':h_template
           , 'dh':template_dh
           , 'pdf':template_pdf
           , 'arg_list':arg_list
           , 'arg_set':arg_set
           }

# ------------------------------------------------------------------------------
def performFit( data_dh
              , bkg_template
              , roo_real_var
              , label
              , fit_ranges = []
              ):
    print 'performFit'

    # create clone of our roo_real_var
    print 'cloning roo_real_var'
    clone_roo_real_var = roo_real_var.clone('fit_var_%s' % roo_real_var.GetName())

    # get normalization of data
    print 'getting norm'
    norm = data_dh.sum(False)

    # number of fitted background events
    # set loose bounds on range
    print 'creating n_bkkg_variable'
    n_bkg = ROOT.RooRealVar('n_bkg__fit_%s' % label , 'bkg', 0.75*norm, 0, 1.25*norm)

    # define arglists and pdf needed for fit
    print 'creating arglist and pdf'
    fit_pdf_arglist = ROOT.RooArgList(bkg_template['pdf'])
    fit_value_arglist = ROOT.RooArgList(n_bkg)
    fit_pdf = ROOT.RooAddPdf( label, label, fit_pdf_arglist, fit_value_arglist)

    # set fit range (sideband)
    fit_range_string = ''
    for i, fr in enumerate(fit_ranges):
        this_fit_range_string = 'fit_range__%s__%s' % (label, i)
        clone_roo_real_var.setRange( this_fit_range_string , fr['min'], fr['max'])
        if fit_range_string == '':
            fit_range_string = this_fit_range_string
        else:
            fit_range_string = '%s,%s' % (fit_range_string, this_fit_range_string)

    # set search range
    # TODO make this more robust
    search_range_string = ''
    if len(fit_ranges) == 2:
        search_range_string = 'search_range__%s__%s' % (label, i)
        clone_roo_real_var.setRange(search_range_string, fit_ranges[0]['max'], fit_ranges[1]['min'])
        print 'setting range to : %s -- %s' % (fit_ranges[0]['max'], fit_ranges[1]['min'])

    # perform fit
    ext = ROOT.RooFit.Extended()
    sum_w2_error = ROOT.RooCmdArg.none()
    fit_range = ROOT.RooFit.Range(fit_range_string)
    print 'fit_range_string: %s -- fit range: %s' % (fit_range_string, fit_range)
    coef_range = ROOT.RooCmdArg.none()
    print_level = ROOT.RooCmdArg.none()
    print 'about to fit'
    fit_pdf.fitTo( data_dh
                 , ext
                 , sum_w2_error
                 , fit_range
                 , coef_range
                 , print_level
                 )
    print 'done fitting'

    return { 'norm':norm
           , 'n_bkg':n_bkg
           , 'pdf_arglist':fit_pdf_arglist
           , 'value_arglist':fit_value_arglist
           , 'pdf':fit_pdf
           , 'fit_range_string':fit_range_string
           , 'search_range_string':search_range_string
           , 'local_roo_real_var':clone_roo_real_var
           }

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
def fitAndDrawToCanvas( data_dh
                      , bkg_template
                      , roo_real_var
                      , label
                      , fit_ranges = []
                      # , log = False
                      ):
    # perform fit to data
    fit_dict = performFit( data_dh
                         , bkg_template
                         , roo_real_var
                         , label
                         , fit_ranges
                         )

    print 'fit and draw to canvas -- linear'
    print fit_dict['fit_range_string']
    draw_dict_lin = drawToCanvas( [data_dh, fit_dict['pdf'], fit_dict['pdf']]
                                , roo_real_var
                                , line_colors = [ROOT.kBlack, ROOT.kRed, ROOT.kGreen]
                                , label = label
                                , range_string_list = ['full_range', fit_dict['fit_range_string'], fit_dict['search_range_string']]
                                , log = False
                                )

    print 'fit and draw to canvas -- log'
    print fit_dict['fit_range_string']
    draw_dict_log = drawToCanvas( [data_dh, fit_dict['pdf'], fit_dict['pdf']]
                                , roo_real_var
                                , line_colors = [ROOT.kBlack, ROOT.kRed, ROOT.kGreen]
                                , label = label
                                , range_string_list = ['full_range', fit_dict['fit_range_string'], fit_dict['search_range_string']]
                                , log = True
                                )

    norm = fit_dict['n_bkg'].getVal()
    err = fit_dict['n_bkg'].getError()

    # get chi2 for sideband and search regions
    chi2_sideband = fit_dict['pdf'].createChi2( data_dh
                                              , ROOT.RooFit.DataError(ROOT.RooAbsData.Poisson)
                                              , ROOT.RooFit.Range(fit_dict['fit_range_string'])
                                              )
    chi2_search = fit_dict['pdf'].createChi2( data_dh
                                            , ROOT.RooFit.DataError(ROOT.RooAbsData.Poisson)
                                            , ROOT.RooFit.Range(fit_dict['search_range_string'])
                                            )

    # get ndfo for sideband and search regions
    ndof_sideband = getNumBinsInRegion( fit_dict['fit_range_string']
                                      , fit_dict['local_roo_real_var']
                                      , bkg_template['hist']
                                      )
    ndof_search = getNumBinsInRegion( fit_dict['search_range_string']
                                    , fit_dict['local_roo_real_var']
                                    , bkg_template['hist']
                                    )

    # calculate chi2/ndof for sideband and search regions
    chi2_over_ndof_sideband = chi2_sideband.getVal()/ndof_sideband
    chi2_over_ndof_search = chi2_search.getVal()/ndof_search

    # make labels for canvas
    search_region_string = ''
    if len(fit_ranges) == 0: search_region_string = 'N/A'
    # TODO make this more robust
    elif len(fit_ranges) == 2:
        search_region_string = '%d < m_{bl} < %d' % (fit_ranges[0]['max'], fit_ranges[1]['min'])

    label_info          = ROOT.TLatex(0.50, 0.85, 'Search region: %s' % (search_region_string))
    label_norm          = ROOT.TLatex(0.50, 0.80, 'Background: %0.1f #pm %0.1f' % (norm, err))
    label_chi2_sideband = ROOT.TLatex(0.50, 0.75, '#chi^{2}/ndof (sideband): %0.2f' % chi2_over_ndof_sideband)
    label_chi2_search   = ROOT.TLatex(0.50, 0.70, '#chi^{2}/ndof (search): %0.2f'   % chi2_over_ndof_search)

    label_info.SetTextSize(0.04)
    label_norm.SetTextSize(0.04)
    label_chi2_sideband.SetTextSize(0.04)
    label_chi2_search.SetTextSize(0.04)

    label_info.SetNDC()
    label_norm.SetNDC()
    label_chi2_sideband.SetNDC()
    label_chi2_search.SetNDC()

    draw_dict_lin['canv'].cd()
    label_info.Draw()
    label_norm.Draw()
    label_chi2_sideband.Draw()
    label_chi2_search.Draw()

    draw_dict_log['canv'].cd()
    label_info.Draw()
    label_norm.Draw()
    label_chi2_sideband.Draw()
    label_chi2_search.Draw()

    # save things to dictionary and return them so root doesn't lose them
    fit_dict['frame_lin'] = draw_dict_lin['frame']
    fit_dict['frame_log'] = draw_dict_log['frame']
    fit_dict['canv_lin'] = draw_dict_lin['canv']
    fit_dict['canv_log'] = draw_dict_log['canv']
    fit_dict['label_info'] = label_info
    fit_dict['label_norm'] = label_norm
    fit_dict['label_chi2_sideband'] = label_chi2_sideband
    fit_dict['label_chi2_search'] = label_chi2_search
    fit_dict['chi2_sideband'] = chi2_sideband.getVal()
    fit_dict['chi2_search'] = chi2_search.getVal()
    fit_dict['ndof_sideband'] = ndof_sideband
    fit_dict['ndof_search'] = ndof_search
    fit_dict['chi2_over_ndof_sideband'] = chi2_over_ndof_sideband
    fit_dict['chi2_over_ndof_search'] = chi2_over_ndof_search
    return fit_dict

# ------------------------------------------------------------------------------
def performSlidingWindowScan( data_dh
                            , bkg_template
                            , roo_real_var
                            , label
                            ):
    scanning_window_fit_dict = {}

    for window_center in xrange(100, 1100, 100):
        print '--------------------------------------------------------------------------------'
        print 'Performing fit for window centered on %s' % window_center
        print ' - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -'
        this_label = '%s__%s' % (label, window_center)
        window_width = window_center * 0.1
        window_min = window_center - window_width
        window_max = window_center + window_width

        print 'excluding window -- %s -- %s' % (window_min, window_max)

        this_fit_dict = fitAndDrawToCanvas( data_dh
                                          , bkg_template
                                          , roo_real_var
                                          , this_label
                                          , fit_ranges = [ {'min':mbl_min   , 'max':window_min}
                                                         , {'min':window_max, 'max':mbl_max}
                                                         ]
                                          )
        scanning_window_fit_dict[this_label] = this_fit_dict

    return scanning_window_fit_dict

# ------------------------------------------------------------------------------
def main():
    ROOT.gROOT.SetBatch()

    # get template histogram
    bkg_template_dict = getTemplateFromFile( file_name = bkg_template_file_name
                                           , template_name = 'template__flavor_all__mbl_all__BMINUSL_MET'
                                           , roo_real_var = mbl_real_var
                                           , label = 'bkg_template'
                                           )

    # get toy histogram
    toy_data_dict = getTemplateFromFile( file_name = toy_data_file_name
                                       , template_name = 'toy__flavor_all__mbl_all__BMINUSL_MET'
                                       , roo_real_var = mbl_real_var
                                       , label = 'toy'
                                       )

    # draw background template to a canvas
    template_draw_dict = drawToCanvas( [bkg_template_dict['pdf']]
                                     , mbl_real_var
                                     , [ROOT.kBlack]
                                     , 'mbl_templates'
                                     , range_string_list = ['full_range']
                                     , log = True
                                     )

    # draw toy data to a canvas
    toy_draw_dict = drawToCanvas( [toy_data_dict['dh']]
                                , mbl_real_var
                                , [ROOT.kBlack]
                                , 'mbl_toy'
                                , range_string_list = ['full_range']
                                , log = True
                                )

    # Make toy histogram into RooDataHist
    mbl_toy_dh = toy_data_dict['dh']

    # do basic fit -- no sliding window
    basic_fit_dict = fitAndDrawToCanvas( mbl_toy_dh
                                       , bkg_template_dict
                                       , mbl_real_var
                                       , 'basic_fit'
                                       )

    # do sliding fit window scan
    sliding_window_scan = performSlidingWindowScan( mbl_toy_dh
                                                  , bkg_template_dict
                                                  , mbl_real_var
                                                  , 'sliding_window'
                                                  )

    # Print a bunch of info to screen
    print 'basic fit -- n_bkg: %s' % basic_fit_dict['n_bkg'].getVal()
    for sws in sorted(sliding_window_scan.iterkeys()):
        print sws
        print sliding_window_scan[sws]['n_bkg'].GetName()
        print 'fit window string: %s' % sliding_window_scan[sws]['fit_range_string']
        print 'norm: %s' % sliding_window_scan[sws]['n_bkg'].getVal()
        print 'error: %s' % sliding_window_scan[sws]['n_bkg'].getError()
        print 'chi2_sideband: %s' % sliding_window_scan[sws]['chi2_sideband']
        print 'ndof_sideband: %s' % sliding_window_scan[sws]['ndof_sideband']
        print 'chi2_over_ndof (sideband): %s' % sliding_window_scan[sws]['chi2_over_ndof_sideband']
        print 'chi2_search: %s' % sliding_window_scan[sws]['chi2_search']
        print 'ndof_search: %s' % sliding_window_scan[sws]['ndof_search']
        print 'chi2_over_ndof (search): %s' % sliding_window_scan[sws]['chi2_over_ndof_search']
        print ''

    # write canvas to file
    out_file = ROOT.TFile('fit.root', 'RECREATE')
    out_file.cd()
    template_draw_dict['canv'].Write()
    toy_draw_dict['canv'].Write()
    basic_fit_dict['canv_lin'].Write()
    basic_fit_dict['canv_log'].Write()
    for sws in sorted(sliding_window_scan.iterkeys()):
        sliding_window_scan[sws]['canv_lin'].Write()
        sliding_window_scan[sws]['canv_log'].Write()

# ==============================================================================
if __name__ == "__main__":
    main()
