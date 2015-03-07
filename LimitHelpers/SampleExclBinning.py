# Binnings used for the SampleExcl HistFitter config file
# ==============================================================================

# stearing boolians to determine if we have single binned or multi-binned fit
single_bin_regions = True
single_bin_signal  = True

if single_bin_regions:
    single_bin_signal = True

# ==============================================================================
# flavor channel binning
flavor_channel_bin = 5
flavor_channel_min = -0.5
flavor_channel_max = flavor_channel_min + flavor_channel_bin

# ------------------------------------------------------------------------------
binning = {'flavor_channel':{'bin':flavor_channel_bin,
                             'min':flavor_channel_min,
                             'max':flavor_channel_max},
           'deta':{    'bin':4 , 'min':0   , 'max':4   },
           'dphi':{    'bin':8 , 'min':0   , 'max':3.2 },
           'dr':{      'bin':4 , 'min':0   , 'max':4   },
           'ht_full':{ 'bin':19, 'min':150 , 'max':2000},
           'ht_low':{  'bin':10, 'min':100 , 'max':500},
           'ht_mid':{  'bin':6 , 'min':500 , 'max':1100},
           'ht_sr':{   'bin':9 , 'min':1100, 'max':2000},
           'mbbll':{   'bin':6 , 'min':0   , 'max':1200},
           'mbl':{     'bin':6 , 'min':200 , 'max':800},
           'mbl_asym':{'bin':5 , 'min':0   , 'max':1.  },
           'met_et':{  'bin':5 , 'min':0   , 'max':100 },
           'met_sig':{ 'bin':10, 'min':0   , 'max':10  },
           'mll':{     'bin':10, 'min':0   , 'max':500 },
           'mll_in_z':{'bin':6 , 'min':75  , 'max':105 },
           'pt':{      'bin':10, 'min':0   , 'max':500 },
           'ptbbll':{  'bin':6 , 'min':0   , 'max':600 },
           'ptbl':{    'bin':6 , 'min':0   , 'max':600 },
           'ptll':{    'bin':6 , 'min':0   , 'max':600 },
           'default':{ 'bin':1 , 'min':0   , 'max':1   }}


# ------------------------------------------------------------------------------
def get_binning(bin_name, single_bin=single_bin_regions):
    print 'getting binning for ', bin_name, ' - default binning: ', binning[bin_name], ' - single bin: ', single_bin
    this_binning = binning[bin_name].copy()
    if single_bin:
        this_binning['bin'] = 1
    return this_binning

