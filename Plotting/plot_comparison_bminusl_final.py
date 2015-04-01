#!/usr/bin/env python

import ROOT
import HistHandle as hh
import sys
import BminuslGrouping as grouping
import array

# -----------------------------------------------------------------------------
configs = {'bbll':{'dir_name':'BMINUSL_BL_PAIRING',
                   'label':'bbll',
                   'hists':{
                            'b_jet_pt_0'             :{'max_lin':250, 'max_log':1e6, 'min_log':0.02},
                            'b_jet_pt_1'             :{'max_lin':400, 'max_log':1e6, 'min_log':0.02},
                            'ht_signal'              :{'max_lin':300, 'max_log':1e6, 'min_log':0.02},
                            'jet_mult_num_b_jets'    :{'max_lin':500, 'max_log':1e6, 'min_log':0.02},
                            'jet_mult_num_jets'      :{'max_lin':300, 'max_log':1e6, 'min_log':0.02},
                            'jet_mult_num_light_jets':{'max_lin':300, 'max_log':1e6, 'min_log':0.02},
                            'lep_pt_0'               :{'max_lin':350, 'max_log':1e6, 'min_log':0.02},
                            'lep_pt_1'               :{'max_lin':400, 'max_log':1e6, 'min_log':0.02},
                            'mbl_0'                  :{'max_lin':400, 'max_log':1e6, 'min_log':0.02},
                            'mbl_1'                  :{'max_lin':300, 'max_log':1e6, 'min_log':0.02},
                            'mbl_asym'               :{'max_lin':200, 'max_log':1e6, 'min_log':0.02},
                            'met_sig_signal'         :{'max_lin':400, 'max_log':1e6, 'min_log':0.02},
                            'mll'                    :{'max_lin':400, 'max_log':1e6, 'min_log':0.02},
                           }
                  },
           'zveto':{'dir_name':'BMINUSL_ZVETO',
                    'label':'bbll+Z veto',
                    'hists':{
                             'b_jet_pt_0'             :{'max_lin':250, 'max_log':1e6, 'min_log':0.02},
                             'b_jet_pt_1'             :{'max_lin':400, 'max_log':1e6, 'min_log':0.02},
                             'ht_signal'              :{'max_lin':300, 'max_log':1e6, 'min_log':0.02},
                             'jet_mult_num_b_jets'    :{'max_lin':500, 'max_log':1e6, 'min_log':0.02},
                             'jet_mult_num_jets'      :{'max_lin':300, 'max_log':1e6, 'min_log':0.02},
                             'jet_mult_num_light_jets':{'max_lin':300, 'max_log':1e6, 'min_log':0.02},
                             'lep_pt_0'               :{'max_lin':350, 'max_log':1e6, 'min_log':0.02},
                             'lep_pt_1'               :{'max_lin':400, 'max_log':1e6, 'min_log':0.02},
                             'mbl_0'                  :{'max_lin':400, 'max_log':1e6, 'min_log':0.02},
                             'mbl_1'                  :{'max_lin':300, 'max_log':1e6, 'min_log':0.02},
                             'mbl_asym'               :{'max_lin':200, 'max_log':1e6, 'min_log':0.02},
                             'met_sig_signal'         :{'max_lin':400, 'max_log':1e6, 'min_log':0.02},
                             'mll'                    :{'max_lin':400, 'max_log':1e6, 'min_log':0.02},
                            }
                   },
           'top_cr':{'dir_name':'BMINUSL_CR_TOP_MBL_200',
                     'label':'Top CR',
                     'hists':{
                              'b_jet_pt_0'             :{'max_lin':250, 'max_log':1e4, 'min_log':0.02},
                              'b_jet_pt_1'             :{'max_lin':400, 'max_log':3e4, 'min_log':0.02},
                              'ht_signal'              :{'max_lin':300, 'max_log':1e4, 'min_log':0.02},
                              'jet_mult_num_b_jets'    :{'max_lin':500, 'max_log':5e4, 'min_log':0.02},
                              'jet_mult_num_jets'      :{'max_lin':300, 'max_log':1e5, 'min_log':0.02},
                              'jet_mult_num_light_jets':{'max_lin':300, 'max_log':3e4, 'min_log':0.02},
                              'lep_pt_0'               :{'max_lin':350, 'max_log':3e4, 'min_log':0.02},
                              'lep_pt_1'               :{'max_lin':400, 'max_log':3e4, 'min_log':0.02},
                              'mbl_0'                  :{'max_lin':400, 'max_log':4e4, 'min_log':0.02},
                              'mbl_1'                  :{'max_lin':300, 'max_log':1e4, 'min_log':0.02},
                              'mbl_asym'               :{'max_lin':200, 'max_log':1e4, 'min_log':0.02},
                             }
                    },
           'z_cr':{'dir_name':'BMINUSL_CR_Z_MBL_200',
                   'label':'Z CR',
                   'hists':{
                            'b_jet_pt_0'             :{'max_lin':250, 'max_log':1e4, 'min_log':0.02},
                            'b_jet_pt_1'             :{'max_lin':400, 'max_log':3e4, 'min_log':0.02},
                            'ht_signal'              :{'max_lin':300, 'max_log':1e4, 'min_log':0.02},
                            'jet_mult_num_b_jets'    :{'max_lin':500, 'max_log':5e4, 'min_log':0.02},
                            'jet_mult_num_jets'      :{'max_lin':300, 'max_log':1e5, 'min_log':0.02},
                            'jet_mult_num_light_jets':{'max_lin':300, 'max_log':3e4, 'min_log':0.02},
                            'lep_pt_0'               :{'max_lin':350, 'max_log':3e4, 'min_log':0.02},
                            'lep_pt_1'               :{'max_lin':400, 'max_log':3e4, 'min_log':0.02},
                            'mbl_0'                  :{'max_lin':400, 'max_log':4e4, 'min_log':0.02},
                            'mbl_1'                  :{'max_lin':300, 'max_log':1e4, 'min_log':0.02},
                            'mbl_asym'               :{'max_lin':200, 'max_log':1e4, 'min_log':0.02},
                           }
                  },
           'top_vr_1':{'dir_name':'BMINUSL_VR_TOP_1_MBL_200',
                       'label':'Top VR 1',
                       'hists':{
                                'b_jet_pt_0'             :{'max_lin':250, 'max_log':5e4, 'min_log':0.02},
                                'b_jet_pt_1'             :{'max_lin':400, 'max_log':5e4, 'min_log':0.02},
                                'ht_signal'              :{'max_lin':300, 'max_log':5e4, 'min_log':0.02},
                                'jet_mult_num_b_jets'    :{'max_lin':500, 'max_log':5e4, 'min_log':0.02},
                                'jet_mult_num_jets'      :{'max_lin':300, 'max_log':5e5, 'min_log':0.02},
                                'jet_mult_num_light_jets':{'max_lin':300, 'max_log':5e4, 'min_log':0.02},
                                'lep_pt_0'               :{'max_lin':350, 'max_log':5e4, 'min_log':0.02},
                                'lep_pt_1'               :{'max_lin':400, 'max_log':7e4, 'min_log':0.02},
                                'mbl_0'                  :{'max_lin':400, 'max_log':4e4, 'min_log':0.02},
                                'mbl_1'                  :{'max_lin':300, 'max_log':4e4, 'min_log':0.02},
                                'mbl_asym'               :{'max_lin':200, 'max_log':5e4, 'min_log':0.02},
                               }
                      },
           'top_vr_2':{'dir_name':'BMINUSL_VR_TOP_2_MBL_200',
                       'label':'Top VR 2',
                       'hists':{
                                'b_jet_pt_0'             :{'max_lin':250, 'max_log':5e4, 'min_log':0.02},
                                'b_jet_pt_1'             :{'max_lin':400, 'max_log':8e4, 'min_log':0.02},
                                'ht_signal'              :{'max_lin':300, 'max_log':5e4, 'min_log':0.02},
                                'jet_mult_num_b_jets'    :{'max_lin':500, 'max_log':5e4, 'min_log':0.02},
                                'jet_mult_num_jets'      :{'max_lin':300, 'max_log':4e5, 'min_log':0.02},
                                'jet_mult_num_light_jets':{'max_lin':300, 'max_log':3e4, 'min_log':0.02},
                                'lep_pt_0'               :{'max_lin':350, 'max_log':3e4, 'min_log':0.02},
                                'lep_pt_1'               :{'max_lin':400, 'max_log':3e4, 'min_log':0.02},
                                'mbl_0'                  :{'max_lin':400, 'max_log':4e4, 'min_log':0.02},
                                'mbl_1'                  :{'max_lin':300, 'max_log':1e5, 'min_log':0.02},
                                'mbl_asym'               :{'max_lin':200, 'max_log':6e4, 'min_log':0.02},
                               }
                      },
           'top_vr_3':{'dir_name':'BMINUSL_VR_TOP_3_MBL_200',
                       'label':'Top VR 3',
                       'hists':{
                                'b_jet_pt_0'             :{'max_lin':250, 'max_log':5e3, 'min_log':0.02},
                                'b_jet_pt_1'             :{'max_lin':400, 'max_log':2e3, 'min_log':0.02},
                                'ht_signal'              :{'max_lin':300, 'max_log':5e3, 'min_log':0.02},
                                'jet_mult_num_b_jets'    :{'max_lin':500, 'max_log':2e3, 'min_log':0.02},
                                'jet_mult_num_jets'      :{'max_lin':300, 'max_log':5e4, 'min_log':0.02},
                                'jet_mult_num_light_jets':{'max_lin':300, 'max_log':2e3, 'min_log':0.02},
                                'lep_pt_0'               :{'max_lin':350, 'max_log':1e3, 'min_log':0.02},
                                'lep_pt_1'               :{'max_lin':400, 'max_log':5e3, 'min_log':0.02},
                                'mbl_0'                  :{'max_lin':400, 'max_log':5e3, 'min_log':0.02},
                                'mbl_1'                  :{'max_lin':300, 'max_log':1e3, 'min_log':0.02},
                                'mbl_asym'               :{'max_lin':200, 'max_log':1e4, 'min_log':0.02},
                               }
                      },
           'z_vr':{'dir_name':'BMINUSL_VR_Z_MBL_200',
                   'label':'Z VR',
                   'hists':{
                            'b_jet_pt_0'             :{'max_lin':250, 'max_log':5e3, 'min_log':0.02},
                            'b_jet_pt_1'             :{'max_lin':400, 'max_log':2e3, 'min_log':0.02},
                            'ht_signal'              :{'max_lin':300, 'max_log':2e3, 'min_log':0.02},
                            'jet_mult_num_b_jets'    :{'max_lin':500, 'max_log':1e4, 'min_log':0.02},
                            'jet_mult_num_jets'      :{'max_lin':300, 'max_log':1e5, 'min_log':0.02},
                            'jet_mult_num_light_jets':{'max_lin':300, 'max_log':3e3, 'min_log':0.02},
                            'lep_pt_0'               :{'max_lin':350, 'max_log':5e3, 'min_log':0.02},
                            'lep_pt_1'               :{'max_lin':400, 'max_log':5e3, 'min_log':0.02},
                            'mbl_0'                  :{'max_lin':400, 'max_log':5e3, 'min_log':0.02},
                            'mbl_1'                  :{'max_lin':300, 'max_log':2e3, 'min_log':0.02},
                            'mbl_asym'               :{'max_lin':200, 'max_log':2e3, 'min_log':0.02},
                           }
                  },
           'sr_400':{'dir_name':'BMINUSL_SR_HT_1100_MBL_400',
                     'label':'SR 400',
                     'hists':{
                              'b_jet_pt_0'             :{'max_lin':20 , 'max_log':2e3, 'min_log':0.02},
                              'b_jet_pt_1'             :{'max_lin':31 , 'max_log':400, 'min_log':0.02},
                              'ht_signal'              :{'max_lin':55 , 'max_log':1e3, 'min_log':0.02},
                              'jet_mult_num_b_jets'    :{'max_lin':130, 'max_log':5e3, 'min_log':0.02},
                              'jet_mult_num_jets'      :{'max_lin':60 , 'max_log':3e3, 'min_log':0.02},
                              'jet_mult_num_light_jets':{'max_lin':70 , 'max_log':1e3, 'min_log':0.02},
                              'lep_pt_0'               :{'max_lin':21 , 'max_log':2e3, 'min_log':0.02},
                              'lep_pt_1'               :{'max_lin':27 , 'max_log':400, 'min_log':0.02},
                              'mbl_0'                  :{'max_lin':65 , 'max_log':1e3, 'min_log':0.02},
                              'mbl_1'                  :{'max_lin':65 , 'max_log':1e3, 'min_log':0.02},
                              'mbl_asym'               :{'max_lin':90 , 'max_log':2e3, 'min_log':0.02},
                             }
                    },
           'sr_600':{'dir_name':'BMINUSL_SR_HT_1100_MBL_600',
                     'label':'SR 600',
                     'hists':{
                              'b_jet_pt_0'             :{'max_lin':2.5, 'max_log':50 , 'min_log':0.02},
                              'b_jet_pt_1'             :{'max_lin':3.5, 'max_log':20 , 'min_log':0.02},
                              'ht_signal'              :{'max_lin':3.5, 'max_log':70 , 'min_log':0.02},
                              'jet_mult_num_b_jets'    :{'max_lin':16 , 'max_log':100, 'min_log':0.02},
                              'jet_mult_num_jets'      :{'max_lin':6  , 'max_log':100, 'min_log':0.02},
                              'jet_mult_num_light_jets':{'max_lin':6.5, 'max_log':50 , 'min_log':0.02},
                              'lep_pt_0'               :{'max_lin':2.5, 'max_log':60 , 'min_log':0.02},
                              'lep_pt_1'               :{'max_lin':3  , 'max_log':10 , 'min_log':0.02},
                              'mbl_0'                  :{'max_lin':9  , 'max_log':1e3, 'min_log':0.02},
                              'mbl_1'                  :{'max_lin':6  , 'max_log':200, 'min_log':0.02},
                              'mbl_asym'               :{'max_lin':10 , 'max_log':90 , 'min_log':0.02},
                             }
                    },
           'sr_400_minus_ht':{'dir_name':'BMINUSL_SR_HT_1100_MBL_400_MINUS_HT',
                              'label':'',
                              'hists':{
                                       'b_jet_pt_0'             :{'max_lin':120, 'max_log':4e3, 'min_log':0.01},
                                       'b_jet_pt_1'             :{'max_lin':170, 'max_log':3e3, 'min_log':0.01},
                                       'ht_signal'              :{'max_lin':130, 'max_log':5e3, 'min_log':0.01},
                                       'jet_mult_num_b_jets'    :{'max_lin':550, 'max_log':1e4, 'min_log':0.01},
                                       'jet_mult_num_jets'      :{'max_lin':220, 'max_log':7e4, 'min_log':0.01},
                                       'jet_mult_num_light_jets':{'max_lin':240, 'max_log':3e3, 'min_log':0.01},
                                       'lep_pt_0'               :{'max_lin':120, 'max_log':7e3, 'min_log':0.01},
                                       'lep_pt_1'               :{'max_lin':160, 'max_log':2e3, 'min_log':0.01},
                                       'mbl_0'                  :{'max_lin':275, 'max_log':1e4, 'min_log':0.01},
                                       'mbl_1'                  :{'max_lin':225, 'max_log':5e3, 'min_log':0.01},
                                       'mbl_asym'               :{'max_lin':300, 'max_log':5e3, 'min_log':0.01},
                                      }
                             },
           'sr_600_minus_ht':{'dir_name':'BMINUSL_SR_HT_1100_MBL_600_MINUS_HT',
                              'label':'',
                              'hists':{ 
                                       'b_jet_pt_0'             :{'max_lin':3.5, 'max_log':50 , 'min_log':0.01},
                                       'b_jet_pt_1'             :{'max_lin':3.5, 'max_log':20 , 'min_log':0.01},
                                       'ht_signal'              :{'max_lin':3.5, 'max_log':50 , 'min_log':0.01},
                                       'jet_mult_num_b_jets'    :{'max_lin':17 , 'max_log':100, 'min_log':0.01},
                                       'jet_mult_num_jets'      :{'max_lin':7  , 'max_log':100, 'min_log':0.01},
                                       'jet_mult_num_light_jets':{'max_lin':6.5, 'max_log':30 , 'min_log':0.01},
                                       'lep_pt_0'               :{'max_lin':3  , 'max_log':80 , 'min_log':0.01},
                                       'lep_pt_1'               :{'max_lin':3.5, 'max_log':20 , 'min_log':0.01},
                                       'mbl_0'                  :{'max_lin':12 , 'max_log':1e3, 'min_log':0.01},
                                       'mbl_1'                  :{'max_lin':7  , 'max_log':70 , 'min_log':0.01},
                                       'mbl_asym'               :{'max_lin':10 , 'max_log':50 , 'min_log':0.01},
                                      }
                             },
           'sr_minus_mbl':{'dir_name':'BMINUSL_SR_HT_1100_MINUS_MBL',
                           'label':'',
                           'hists':{
                                    'b_jet_pt_0'             :{'max_lin':20 , 'max_log':4e3, 'min_log':0.01},
                                    'b_jet_pt_1'             :{'max_lin':28 , 'max_log':200, 'min_log':0.01},
                                    'ht_signal'              :{'max_lin':55 , 'max_log':1e3, 'min_log':0.01},
                                    'jet_mult_num_b_jets'    :{'max_lin':130, 'max_log':1e3, 'min_log':0.01},
                                    'jet_mult_num_jets'      :{'max_lin':60 , 'max_log':5e3, 'min_log':0.01},
                                    'jet_mult_num_light_jets':{'max_lin':65 , 'max_log':500, 'min_log':0.01},
                                    'lep_pt_0'               :{'max_lin':25 , 'max_log':3e3, 'min_log':0.01},
                                    'lep_pt_1'               :{'max_lin':25 , 'max_log':200, 'min_log':0.01},
                                    'mbl_0'                  :{'max_lin':60 , 'max_log':1e3, 'min_log':0.01},
                                    'mbl_1'                  :{'max_lin':65 , 'max_log':1e3, 'min_log':0.01},
                                    'mbl_asym'               :{'max_lin':85 , 'max_log':700, 'min_log':0.01},
                                   }
                          },
           'sr_400_minus_mbl_asym':{'dir_name':'BMINUSL_SR_HT_1100_MBL_400_MINUS_MBL_ASYM',
                                    'label':'',
                                    'hists':{
                                             'b_jet_pt_0'             :{'max_lin':20 , 'max_log':5e3, 'min_log':0.01},
                                             'b_jet_pt_1'             :{'max_lin':30 , 'max_log':200, 'min_log':0.01},
                                             'ht_signal'              :{'max_lin':55 , 'max_log':1e3, 'min_log':0.01},
                                             'jet_mult_num_b_jets'    :{'max_lin':130, 'max_log':1e3, 'min_log':0.01},
                                             'jet_mult_num_jets'      :{'max_lin':65 , 'max_log':5e3, 'min_log':0.01},
                                             'jet_mult_num_light_jets':{'max_lin':60 , 'max_log':500, 'min_log':0.01},
                                             'lep_pt_0'               :{'max_lin':25 , 'max_log':5e3, 'min_log':0.01},
                                             'lep_pt_1'               :{'max_lin':26 , 'max_log':400, 'min_log':0.01},
                                             'mbl_0'                  :{'max_lin':60 , 'max_log':1e3, 'min_log':0.01},
                                             'mbl_1'                  :{'max_lin':65 , 'max_log':1e3, 'min_log':0.01},
                                             'mbl_asym'               :{'max_lin':85 , 'max_log':1e3, 'min_log':0.01},
                                            }
                                   },
           'sr_600_minus_mbl_asym':{'dir_name':'BMINUSL_SR_HT_1100_MBL_600_MINUS_MBL_ASYM',
                                    'label':'',
                                    'hists':{
                                             'b_jet_pt_0'             :{'max_lin':3  , 'max_log':60 , 'min_log':0.01},
                                             'b_jet_pt_1'             :{'max_lin':3.5, 'max_log':10 , 'min_log':0.01},
                                             'ht_signal'              :{'max_lin':4  , 'max_log':80 , 'min_log':0.01},
                                             'jet_mult_num_b_jets'    :{'max_lin':17 , 'max_log':60 , 'min_log':0.01},
                                             'jet_mult_num_jets'      :{'max_lin':6.5, 'max_log':80 , 'min_log':0.01},
                                             'jet_mult_num_light_jets':{'max_lin':6.5, 'max_log':30 , 'min_log':0.01},
                                             'lep_pt_0'               :{'max_lin':3  , 'max_log':100, 'min_log':0.01},
                                             'lep_pt_1'               :{'max_lin':3.5, 'max_log':50 , 'min_log':0.01},
                                             'mbl_0'                  :{'max_lin':10 , 'max_log':2e3, 'min_log':0.01},
                                             'mbl_1'                  :{'max_lin':6.5, 'max_log':1e3, 'min_log':0.01},
                                             'mbl_asym'               :{'max_lin':9  , 'max_log':100, 'min_log':0.01},
                                            }
                                   },
          }
# -----------------------------------------------------------------------------
def skipHist(dir_name, hist_name):
    """
    hack way to avoid plotting nonsense histograms
    eg. muon pt for ee events
    TODO update for new naming schemes
    """
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # skip lepton flavors that don't match with the flavor channel
    if 'ee' in dir_name and 'mu_' in hist_name:
        return True
    if 'mm' in dir_name and 'el_' in hist_name:
        return True
    if 'em' in dir_name:
        if 'el_1' in hist_name or 'mu_1' in hist_name:
            return True

    if 'flavor_error' in hist_name:
        return True

    if 'mbl_0' not in hist_name:
        return True

    return False


# ------------------------------------------------------------------------------
def makeFinalPlot(dir_name,
                  hist,
                  ic_numerator,
                  ic_denominator,
                  ic_other,
                  out_file,
                  y_max_lin,
                  y_max_log,
                  y_min_log=None,
                  do_ratio=False,
                  do_arrow=False,
                  atlas_label='Internal',
                  region_label=None):
    out_file.cd()
    if not out_file.GetDirectory(dir_name):
        out_file.mkdir(dir_name)
    out_file.cd(dir_name)

    full_hist_name = '__'.join([hist, dir_name])
    print 'dir: ', dir_name
    print 'full hist name: ', full_hist_name

    hm_num = (None if ic_numerator is None or ic_numerator.lumi_target <= 0
              else ic_numerator.genHistMerger(dir_name, full_hist_name))
    hm_denom = (None if ic_denominator is None or
                        ic_denominator.lumi_target <= 0
                else ic_denominator.genHistMerger(dir_name, full_hist_name))
    hm_other = (None if ic_other is None else
                ic_other.genHistMerger(dir_name, full_hist_name))

    print hm_denom.hist_stack
    print hm_denom.hist_sum

    for y_scale in ['lin', 'log']:
        # create the canvas for drawing
        canvas_options = (hh.Objects.canv_log_y if y_scale == 'log'
                          else hh.Objects.canv_linear)
        canvas_name = '__'.join([full_hist_name, y_scale])
        c = canvas_options.create(canvas_name)

        # flag to say if anything has been drawn yet
        first_drawn = False

        hist_list = []
        label_list = []
        draw_opt_list = []

        # simple function to prepare the fist plot
        def prepareFirstHist(hist):
            if y_scale == 'log':
                hist.SetMaximum(y_max_log)
                if y_min_log is not None:
                    hist.SetMinimum(y_min_log)
            else:
                hist.SetMaximum(y_max_lin)

            axis = hist.GetXaxis()
            bin_size = (axis.GetXmax() - axis.GetXmin())/axis.GetNbins()

            if bin_size > 0.049 and bin_size < 0.051:
                bin_size = 0.05
            if bin_size >= 1 and bin_size % 1 == 0:
                bin_size = int(bin_size)

            print 'bin size: ' , bin_size
            hist_name = hist.GetName()
            unit = 'GeV'
            if 'asym' in hist_name.lower():
                unit = ''
            elif 'jet_mult' in hist_name.lower():
                unit = ''
            elif 'met_sig' in hist_name.lower():
                unit = 'GeV^{1/2}'
            y_axis_title = 'Entries/%s %s' % (bin_size, unit)
            hist.GetYaxis().SetTitle(y_axis_title)

        # step through the denominator hist mergers and draw them
        if hm_denom is not None:
            option = 'HIST'

            if first_drawn:
                option += 'SAME'
            else:
                prepareFirstHist(hm_denom.hist_sum)

            hm_denom.hist_sum.SetLineWidth(3)
            hm_denom.hist_sum.SetLineColor(ROOT.kBlue-7)
            hm_denom.hist_sum.Draw(option)

            hist_list.append(hm_denom.hist_sum)
            label_list.append('Total background')
            draw_opt_list.append('L')

            # set line width of sub-histograms in stack and add to list for
            # legend making
            for key, hm in zip(hm_denom.hist_handles_keys, hm_denom.hist_list):
                hm.SetLineWidth(0)

                hist_list.append(hm)
                label_list.append(hh.Helper.genLegendLabel(key))
                draw_opt_list.append('F')

            option = 'HISTSAME'
            hm_denom.hist_stack.Draw(option)

            # draw again so it's on top
            hm_denom.hist_sum.Draw(option)
            hm_denom.error_band.Draw('E2SAME')

            first_drawn = True

        # check if the numerator is provided. If yes, draw it
        if hm_num is not None:
            hm_num.hist_sum.Draw('EPSAME')

            hist_list.append(hm_num.hist_sum)
            label_list.append('Data')
            draw_opt_list.append('EP')

            hist_list = hist_list[-1:] + hist_list[:-1]
            label_list = label_list[-1:] + label_list[:-1]
            draw_opt_list = draw_opt_list[-1:] + draw_opt_list[:-1]

        # step through the other hist mergers, and draw them
        if hm_other is not None:
            for key, hm in zip(hm_other.hist_handles_keys, hm_other.hist_list):
                hm.SetLineStyle(ROOT.kDashed)
                option = 'HIST'

                if first_drawn:
                    option += 'SAME'
                else:
                    prepareFirstHist(hm)

                hm.Draw(option)

                hist_list.append(hm)
                label_list.append(hh.Helper.genLegendLabel(key))
                draw_opt_list.append('L')

                first_drawn = True

        # make and draw a legend
        leg = hh.Helper.makeLegend(hist_list, label_list, draw_opt_list,
                                   width=0.37, height=0.037, y2=0.93)
        leg.Draw()

        # add ATLAS boilerplate
        label_x = 0.2
        label_y = 0.90
        delta_y = 0.07

        hh.AtlasLabels.ATLASLabel(label_x, label_y, 1, atlas_label)
        hh.AtlasLabels.myText(label_x, label_y - delta_y, 1,
                              '#sqrt{s} = 8 TeV, 20.3 fb^{-1}')
        if region_label is not None:
            hh.AtlasLabels.myText(label_x, label_y - 2*delta_y, 1, region_label)

        # add lines for cuts if it is appropriate
        if do_arrow:
            def draw_arrow(height, length, cut_value, color, line_size_top,
                        line_min=0):
                arrow_size = 0.01
                arrow_line_width = 3

                arrow = ROOT.TArrow(cut_value, height,
                                    cut_value+length, height,
                                    arrow_size, '>')
                arrow.SetLineStyle(1)
                arrow.SetLineWidth(arrow_line_width)
                arrow.SetLineColor(color)
                arrow.Draw("SAME>")

                line = ROOT.TLine(cut_value, line_min,
                                cut_value, (1+line_size_top)*height)
                line.SetLineStyle(1)
                line.SetLineWidth(arrow_line_width)
                line.SetLineColor(color)
                line.Draw("SAME")

                return (arrow, line)

            if '_minus_ht' in dir_name.lower() and 'ht_signal' in hist.lower():
                height = 200
                if 'mbl_600' in dir_name.lower():
                    height /= 100.
                arrow = draw_arrow(height=height, length=100, cut_value=1100,
                                color=ROOT.kBlue+3, line_size_top=0.5)

            if '_minus_mbl' in dir_name.lower() and 'mbl_0' in hist.lower():
                height = 13
                arrow = draw_arrow(height=height, length=40, cut_value=400,
                                color=ROOT.kBlue+3, line_size_top=0.3)
                arrow2 = draw_arrow(height=height, length=40, cut_value=600,
                                    color=ROOT.kRed+3, line_size_top=0.3)

            if '_minus_mbl_asym' in dir_name.lower() and 'mbl_asym' in hist.lower():
                height = 15
                if 'mbl_600' in dir_name.lower():
                    height /= 10.
                arrow = draw_arrow(height=height, length=-0.04, cut_value=0.20,
                                color=ROOT.kBlue+3, line_size_top=0.2)

        # add ratio plot if that is requested
        if do_ratio:
            # resize the first pad
            pad_plot = c.GetPad(0)
            pad_plot.SetBottomMargin(hh.default_ratio_pad_size)

            # create a new pad for the ratio, and draw
            pad_ratio = ROOT.TPad('pad_ratio', 'pad_ratio', 0, 0, 1,
                                  hh.default_ratio_pad_size)
            pad_ratio.SetTopMargin(0)
            pad_ratio.SetLeftMargin(hh.default_pad_left_margin)
            pad_ratio.SetRightMargin(hh.default_pad_right_margin)
            pad_ratio.SetBottomMargin(hh.default_pad_bottom_margin/
                                      (1.5*hh.default_ratio_pad_size))

            pad_ratio.Draw()
            pad_ratio.cd()

            # create the ratio plot
            ratio = hm_num.hist_sum.Clone('%s_%s__ratio' % (dir_name, hist))
            ratio.Divide(hm_denom.hist_sum)
            ratio.SetMaximum(1.6)
            ratio.SetMinimum(0.5)

            # set style options
            ratio.SetLabelSize(hh.default_label_size/
                               hh.default_ratio_pad_size*1.0, 'x')
            ratio.SetLabelSize(hh.default_label_size/ 
                               hh.default_ratio_pad_size*0.7, 'y')

            ratio.SetTitleSize(hh.default_label_size/
                               hh.default_ratio_pad_size*1.0, 'x')
            ratio.SetTitleSize(hh.default_label_size/
                               hh.default_ratio_pad_size*0.9, 'y')

            ratio.SetTitleOffset(1.1, 'x')
            ratio.SetTitleOffset(1.3*hh.default_ratio_pad_size, 'y')

            ratio.GetYaxis().SetTitle('%s/%s' % (ic_numerator.name,
                                                 ic_denominator.name))
            ratio.GetYaxis().SetNdivisions(4,8,0)
            ratio.SetMarkerStyle(21)

            # draw the ratio
            ratio.Draw('ep')

            # Draw error band on ratio plot
            rx = []
            ry = []
            erx = []
            ery = []

            num_bins = ratio.GetXaxis().GetNbins()
            for x_itr in xrange(1, num_bins+1):
                rx.append(ratio.GetXaxis().GetBinCenter(x_itr))
                ry.append(1)

                erx.append(ratio.GetBinWidth(x_itr)/2)
                error = 0
                if hm_denom.hist_sum.GetBinContent(x_itr) > 0:
                    error = (hm_denom.hist_sum.GetBinError(x_itr)/
                             hm_denom.hist_sum.GetBinContent(x_itr))
                ery.append(error)

            ratio_error = ROOT.TGraphErrors( num_bins
                                           , array.array('f', rx)
                                           , array.array('f', ry)
                                           , array.array('f', erx)
                                           , array.array('f', ery)
                                           )

            ratio_error.SetFillStyle(3004)
            ratio_error.SetFillColor(1)
            ratio_error.Draw('E2')

            # draw line at ratio = 1
            x_min = ratio.GetXaxis().GetXmin()
            x_max = ratio.GetXaxis().GetXmax()
            ratio_line = ROOT.TLine(x_max, 1, x_max, 1)
            ratio_line.SetLineStyle(ROOT.kDashed)
            ratio_line.Draw()

        # write to file
        c.Write(canvas_name)
        c.Close()

# ------------------------------------------------------------------------------
def plotComparisonsConfNote( ic_numerator
                           , ic_denominator
                           , ic_other
                           , out_file_name
                           , do_ratio=True
                           , atlas_label='Preliminary'
                           ):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # root stuff
    ROOT.TH1.SetDefaultSumw2()
    ROOT.gROOT.SetBatch()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    out_file = ROOT.TFile(out_file_name, 'RECREATE')

    makeFinalPlot(dir_name='BMINUSL_SR_HT_1100_MINUS_MBL',
                  hist='flavor_all__mbl_0',
                  ic_numerator=ic_numerator,
                  ic_denominator=ic_denominator,
                  ic_other=ic_other,
                  out_file=out_file,
                  y_max_lin=60,
                  y_max_log=3000,
                  y_min_log=0.01,
                  do_arrow=True,
                  atlas_label=atlas_label)

    makeFinalPlot(dir_name='BMINUSL_SR_HT_1100_MBL_400_MINUS_HT',
                  hist='flavor_all__ht_signal',
                  ic_numerator=ic_numerator,
                  ic_denominator=ic_denominator,
                  ic_other=ic_other,
                  out_file=out_file,
                  y_max_lin=600,
                  y_max_log=1000000,
                  y_min_log=0.01,
                  do_ratio=do_ratio,
                  do_arrow=True,
                  atlas_label=atlas_label)

    makeFinalPlot(dir_name='BMINUSL_SR_HT_1100_MBL_400_MINUS_MBL_ASYM',
                  hist='flavor_all__mbl_asym',
                  ic_numerator=ic_numerator,
                  ic_denominator=ic_denominator,
                  ic_other=ic_other,
                  out_file=out_file,
                  y_max_lin=100,
                  y_max_log=8000,
                  do_ratio=do_ratio,
                  do_arrow=True,
                  atlas_label=atlas_label)

    out_file.Close()

# ------------------------------------------------------------------------------
def printAllFlavorChannels(dir_name,
                           hist_name,
                           y_max_lin,
                           region_label,
                           **kw):
    # flavor_channel_list = ['all']
    flavor_channel_list = ['all', 'ee', 'mm', 'em']
    if not 'z' in dir_name.lower():
        flavor_channel_list.append('em')

    this_y_max_lin = y_max_lin
    for fc in flavor_channel_list:
        this_hist_name = 'flavor_%s__%s' % (fc, hist_name)
        this_region_label = region_label
        if fc == 'ee':
            this_region_label += ' ee'
            this_y_max_lin /= 3
        if fc == 'mm':
            this_region_label += ' #mu#mu'
            this_y_max_lin /= 3
        if fc == 'em':
            this_region_label += ' e#mu'
            this_y_max_lin /= 3

        makeFinalPlot(dir_name=dir_name,
                      hist=this_hist_name,
                      y_max_lin=this_y_max_lin,
                      region_label=this_region_label,
                      **kw)

# ------------------------------------------------------------------------------
def plotAllHistogramsInRegion(config_key, **kw):
    for hist_name in configs[config_key]['hists']:
        printAllFlavorChannels(dir_name=configs[config_key]['dir_name'],
                               hist_name=hist_name,
                               y_max_lin=configs[config_key]['hists'][hist_name]['max_lin'],
                               y_max_log=configs[config_key]['hists'][hist_name]['max_log'],
                               y_min_log=configs[config_key]['hists'][hist_name]['min_log'],
                               region_label=configs[config_key]['label'],
                               **kw)


# ------------------------------------------------------------------------------
def plotComparisonsSupportNote(ic_numerator,
                               ic_denominator,
                               ic_other,
                               out_file_name,
                               do_ratio=True,
                               atlas_label='Internal',
                               do_bbll=False,
                               do_zveto=False,
                               do_top_cr=False,
                               do_z_cr=False,
                               do_top_vr_1=False,
                               do_top_vr_2=False,
                               do_top_vr_3=False,
                               do_z_vr=False,
                               do_sr_400=False,
                               do_sr_600=False,
                               do_sr_400_minus_ht=False,
                               do_sr_600_minus_ht=False,
                               do_sr_minus_mbl=False,
                               do_sr_400_minus_mbl_asym=False,
                               do_sr_600_minus_mbl_asym=False,
                              ):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # root stuff
    ROOT.TH1.SetDefaultSumw2()
    ROOT.gROOT.SetBatch()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    out_file = ROOT.TFile(out_file_name, 'RECREATE')

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    if do_bbll:
        plotAllHistogramsInRegion(config_key='bbll',
                                  ic_numerator=ic_numerator,
                                  ic_denominator=ic_denominator,
                                  ic_other=ic_other,
                                  out_file=out_file,
                                  do_ratio=do_ratio,
                                  atlas_label=atlas_label)
    if do_zveto:
        plotAllHistogramsInRegion(config_key='zveto',
                                  ic_numerator=ic_numerator,
                                  ic_denominator=ic_denominator,
                                  ic_other=ic_other,
                                  out_file=out_file,
                                  do_ratio=do_ratio,
                                  atlas_label=atlas_label)
    if do_top_cr:
        plotAllHistogramsInRegion(config_key='top_cr',
                                  ic_numerator=ic_numerator,
                                  ic_denominator=ic_denominator,
                                  ic_other=ic_other,
                                  out_file=out_file,
                                  do_ratio=do_ratio,
                                  atlas_label=atlas_label)
    if do_z_cr:
        plotAllHistogramsInRegion(config_key='z_cr',
                                  ic_numerator=ic_numerator,
                                  ic_denominator=ic_denominator,
                                  ic_other=ic_other,
                                  out_file=out_file,
                                  do_ratio=do_ratio,
                                  atlas_label=atlas_label)
    if do_top_vr_1:
        plotAllHistogramsInRegion(config_key='top_vr_1',
                                  ic_numerator=ic_numerator,
                                  ic_denominator=ic_denominator,
                                  ic_other=ic_other,
                                  out_file=out_file,
                                  do_ratio=do_ratio,
                                  atlas_label=atlas_label)
    if do_top_vr_2:
        plotAllHistogramsInRegion(config_key='top_vr_2',
                                  ic_numerator=ic_numerator,
                                  ic_denominator=ic_denominator,
                                  ic_other=ic_other,
                                  out_file=out_file,
                                  do_ratio=do_ratio,
                                  atlas_label=atlas_label)
    if do_top_vr_3:
        plotAllHistogramsInRegion(config_key='top_vr_3',
                                  ic_numerator=ic_numerator,
                                  ic_denominator=ic_denominator,
                                  ic_other=ic_other,
                                  out_file=out_file,
                                  do_ratio=do_ratio,
                                  atlas_label=atlas_label)
    if do_z_vr:
        plotAllHistogramsInRegion(config_key='z_vr',
                                  ic_numerator=ic_numerator,
                                  ic_denominator=ic_denominator,
                                  ic_other=ic_other,
                                  out_file=out_file,
                                  do_ratio=do_ratio,
                                  atlas_label=atlas_label)
    if do_sr_400:
        plotAllHistogramsInRegion(config_key='sr_400',
                                  ic_numerator=ic_numerator,
                                  ic_denominator=ic_denominator,
                                  ic_other=ic_other,
                                  out_file=out_file,
                                  do_ratio=do_ratio,
                                  atlas_label=atlas_label)
    if do_sr_600:
        plotAllHistogramsInRegion(config_key='sr_600',
                                  ic_numerator=ic_numerator,
                                  ic_denominator=ic_denominator,
                                  ic_other=ic_other,
                                  out_file=out_file,
                                  do_ratio=do_ratio,
                                  atlas_label=atlas_label)
    if do_sr_400_minus_ht:
        plotAllHistogramsInRegion(config_key='sr_400_minus_ht',
                                  ic_numerator=ic_numerator,
                                  ic_denominator=ic_denominator,
                                  ic_other=ic_other,
                                  out_file=out_file,
                                  do_ratio=do_ratio,
                                  do_arrow=True,
                                  atlas_label=atlas_label)
    if do_sr_600_minus_ht:
        plotAllHistogramsInRegion(config_key='sr_600_minus_ht',
                                  ic_numerator=ic_numerator,
                                  ic_denominator=ic_denominator,
                                  ic_other=ic_other,
                                  out_file=out_file,
                                  do_ratio=do_ratio,
                                  do_arrow=True,
                                  atlas_label=atlas_label)
    if do_sr_minus_mbl:
        plotAllHistogramsInRegion(config_key='sr_minus_mbl',
                                  ic_numerator=ic_numerator,
                                  ic_denominator=ic_denominator,
                                  ic_other=ic_other,
                                  out_file=out_file,
                                  do_ratio=do_ratio,
                                  do_arrow=True,
                                  atlas_label=atlas_label)
    if do_sr_400_minus_mbl_asym:
        plotAllHistogramsInRegion(config_key='sr_400_minus_mbl_asym',
                                  ic_numerator=ic_numerator,
                                  ic_denominator=ic_denominator,
                                  ic_other=ic_other,
                                  out_file=out_file,
                                  do_ratio=do_ratio,
                                  do_arrow=True,
                                  atlas_label=atlas_label)
    if do_sr_600_minus_mbl_asym:
        plotAllHistogramsInRegion(config_key='sr_600_minus_mbl_asym',
                                  ic_numerator=ic_numerator,
                                  ic_denominator=ic_denominator,
                                  ic_other=ic_other,
                                  out_file=out_file,
                                  do_ratio=do_ratio,
                                  do_arrow=True,
                                  atlas_label=atlas_label)

    out_file.Close()

# ==============================================================================
def main():
    # root stuff
    ROOT.TH1.SetDefaultSumw2()
    ROOT.gROOT.SetBatch()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    syst_tag = 'NOMINAL'
    entry_containers = grouping.generateEntryContainers(syst_tag)

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # Collect EntryContainer into InputContainers
    ic_numerator = hh.Container.InputContainer( name = 'Data'
                                              , entry_list = [entry_containers['ec_data']]
                                              , lumi_target = 1
                                              , line_width=2
                                              )
    ic_denominator = hh.Container.InputContainer( name = 'Bkg'
                                                , entry_list = [ entry_containers['ec_ttbar_powheg']
                                                               , entry_containers['ec_Zgamma_sherpa']
                                                               , entry_containers['ec_single_top_all_channels']
                                                               , entry_containers['ec_other']
                                                               ]
                                                , lumi_target = 20300
                                                , line_width=2
                                                )
    ic_denominator_unscaled = hh.Container.InputContainer( name = 'Bkg'
                                                         , entry_list = [ entry_containers['ec_ttbar_powheg']
                                                                        , entry_containers['ec_Zgamma_sherpa_no_k_factor']
                                                                        , entry_containers['ec_single_top_all_channels']
                                                                        , entry_containers['ec_other']
                                                                        ]
                                                         , lumi_target = 20300
                                                         , line_width=2
                                                         )
    ic_signal = hh.Container.InputContainer( name = 'Signal'
                                           , entry_list = [ entry_containers['ec_bl_500']
                                                          , entry_containers['ec_bl_800']
                                                          , entry_containers['ec_bl_1000']
                                                          ]
                                           , lumi_target = 20300
                                           , line_width=2
                                           )

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # Actually plot comparisons
    out_file_name = 'compare_plots.b_minus_l.conf_note.root'
    plotComparisonsConfNote( ic_numerator   = None
                           , ic_denominator = ic_denominator
                           , ic_other       = ic_signal
                           , out_file_name  = out_file_name
                           , do_ratio       = False
                           , atlas_label    = 'Preliminary Simulation'
                           )

    out_file_name = 'compare_plots.b_minus_l.support_note.root'
    plotComparisonsSupportNote( ic_numerator             = ic_numerator
                              , ic_denominator           = ic_denominator
                              , ic_other                 = ic_signal
                              , out_file_name            = out_file_name
                              , do_ratio                 = True
                              , atlas_label              = 'Internal'
                              , do_bbll                  = False
                              , do_zveto                 = False
                              , do_top_cr                = True
                              , do_z_cr                  = True
                              , do_top_vr_1              = True
                              , do_top_vr_2              = True
                              , do_top_vr_3              = True
                              , do_z_vr                  = True
                              , do_sr_400                = True
                              , do_sr_600                = True
                              , do_sr_400_minus_ht       = False
                              , do_sr_600_minus_ht       = False
                              , do_sr_minus_mbl          = False
                              , do_sr_400_minus_mbl_asym = False
                              , do_sr_600_minus_mbl_asym = False
                              )

    out_file_name = 'compare_plots.b_minus_l.support_note.blind.root'
    plotComparisonsSupportNote( ic_numerator             = None
                              , ic_denominator           = ic_denominator
                              , ic_other                 = ic_signal
                              , out_file_name            = out_file_name
                              , do_ratio                 = False
                              , atlas_label              = 'Internal Simulation'
                              , do_bbll                  = True
                              , do_zveto                 = True
                              , do_top_cr                = False
                              , do_z_cr                  = False
                              , do_top_vr_1              = False
                              , do_top_vr_2              = False
                              , do_top_vr_3              = False
                              , do_z_vr                  = False
                              , do_sr_400                = True
                              , do_sr_600                = True
                              , do_sr_400_minus_ht       = True
                              , do_sr_600_minus_ht       = True
                              , do_sr_minus_mbl          = True
                              , do_sr_400_minus_mbl_asym = True
                              , do_sr_600_minus_mbl_asym = True
                              )

    out_file_name = 'compare_plots.b_minus_l.support_note.no_kfactor.root'
    plotComparisonsSupportNote( ic_numerator             = ic_numerator
                              , ic_denominator           = ic_denominator_unscaled
                              , ic_other                 = ic_signal
                              , out_file_name            = out_file_name
                              , do_ratio                 = True
                              , atlas_label              = 'Internal'
                              , do_bbll                  = False
                              , do_zveto                 = False
                              , do_top_cr                = True
                              , do_z_cr                  = True
                              , do_top_vr_1              = False
                              , do_top_vr_2              = False
                              , do_top_vr_3              = False
                              , do_z_vr                  = False
                              , do_sr_400                = False
                              , do_sr_600                = False
                              , do_sr_400_minus_ht       = False
                              , do_sr_600_minus_ht       = False
                              , do_sr_minus_mbl          = False
                              , do_sr_400_minus_mbl_asym = False
                              , do_sr_600_minus_mbl_asym = False
                              )

    out_file_name = 'compare_plots.b_minus_l.support_note.no_kfactor.blind.root'
    plotComparisonsSupportNote( ic_numerator             = None
                              , ic_denominator           = ic_denominator_unscaled
                              , ic_other                 = ic_signal
                              , out_file_name            = out_file_name
                              , do_ratio                 = False
                              , atlas_label              = 'Internal Simulation'
                              , do_bbll                  = True
                              , do_zveto                 = True
                              , do_top_cr                = False
                              , do_z_cr                  = False
                              , do_top_vr_1              = False
                              , do_top_vr_2              = False
                              , do_top_vr_3              = False
                              , do_z_vr                  = False
                              , do_sr_400                = False
                              , do_sr_600                = False
                              , do_sr_400_minus_ht       = False
                              , do_sr_600_minus_ht       = False
                              , do_sr_minus_mbl          = False
                              , do_sr_400_minus_mbl_asym = False
                              , do_sr_600_minus_mbl_asym = False
                              )

# ==============================================================================
if __name__ == '__main__':
    main()
