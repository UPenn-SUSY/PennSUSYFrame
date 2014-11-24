# Binnings used for the SampleExcl HistFitter config file
# ==============================================================================

# stearing boolians to determine if we have single binned or multi-binned fit
single_bin_regions = False
single_bin_signal  = False

if single_bin_regions:
    single_bin_signal = True

# flavor channel binning
flavor_channel_bin = 5
flavor_channel_min = -0.5
flavor_channel_max = flavor_channel_min + flavor_channel_bin

# pt binning
pt = {'bin':10 if not single_bin_regions else 1,
      'min': 0,
      'max':500}

# mbbll binning
mbbll = {'bin': 6 if not single_bin_regions else 1,
         'min':0,
         'max':1200}

# mbl binning
mbl = {'bin': 6 if not single_bin_regions else 1,
       'min':0,
       'max':1200}

mbl_signal = {'bin': (6 if not single_bin_signal else 1),
              'min':0,
              'max':1200}

# ptbl binning
ptbl = {'bin': 6 if not single_bin_regions else 1,
        'min':0,
        'max':600}

# ptll binning
ptll = {'bin': 6 if not single_bin_regions else 1,
        'min':0,
        'max':600}

# ptbbll binning
ptbbll = {'bin': 6 if not single_bin_regions else 1,
          'min':0,
          'max':600}

# mll binning
mll = {'bin': 10 if not single_bin_regions else 1,
       'min':0,
       'max':500}

mll_in_z = {'bin': 6 if not single_bin_regions else 1,
            'min':75,
            'max':105}

# ht binning
ht = {'bin': 11 if not single_bin_regions else 1,
      'min':0,
      'max':1100}

ht_sr = {'sr_bin': 19 if not single_bin_regions else 1,
         'min':1100,
         'max':3000}

# mbl asym binning
mbl_asym = {'bin':5 if not single_bin_regions else 1,
            'min':0,
            'max':1.}

# met significance binning
met_sig = {'bin': 10 if not single_bin_regions else 1,
           'min':0,
           'max':500}

# met et binning
met_et = {'bin': 5 if not single_bin_regions else 1,
         'min':0,
         'max':100}

# dphi binning
dphi = {'bin': 8 if not single_bin_regions else 1,
        'min':0,
        'max':3.2}

# deta binning
deta = {'bin': 4 if not single_bin_regions else 1,
        'min':0,
        'max':4}

# dr binning
dr = {'bin': 4 if not single_bin_regions else 1,
      'min':0,
      'max':4}

