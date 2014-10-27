#!/usr/bin/env python

# ------------------------------------------------------------------------------
# define nominal values for branching ratios which are simulated
nominal_bf_e = 0.5
nominal_bf_m = 0.5
nominal_bf_t = 0.

# ------------------------------------------------------------------------------
def getBranchingFractions(br_e, br_m, br_t):
    bf_ee = br_e*br_e
    bf_mm = br_m*br_m
    bf_tt = br_t*br_t
    bf_em = 2*br_e*br_m
    bf_et = 2*br_e*br_t
    bf_mt = 2*br_m*br_t

    return { 'ee':bf_ee
           , 'mm':bf_mm
           , 'tt':bf_tt
           , 'em':bf_em
           , 'et':bf_et
           , 'mt':bf_mt
           }

# ------------------------------------------------------------------------------
def getFlavorScaleFactors(bf_dict):
    nominal_bf = getBranchingFractions(nominal_bf_e, nominal_bf_m, nominal_bf_t)
    scale_factor_dict = {}
    for fc in bf_dict:
        scale_factor_dict[fc] = bf_dict[fc]/nominal_bf[fc] if nominal_bf[fc] != 0 else 0
    return scale_factor_dict

# ------------------------------------------------------------------------------
def getFlavorScaleFactorsFromBR(br_e, br_m, br_t):
    return getFlavorScaleFactors(getBranchingFractions(br_e, br_m, br_t))
