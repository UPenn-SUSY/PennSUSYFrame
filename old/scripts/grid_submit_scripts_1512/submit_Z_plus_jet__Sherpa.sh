#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.Z_plus_jet__Sherpa'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    "147770.Sherpa_CT10_Zee:mc12_8TeV.147770.Sherpa_CT10_Zee.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/"
    "147771.Sherpa_CT10_Zmumu:mc12_8TeV.147771.Sherpa_CT10_Zmumu.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/"
    "147772.Sherpa_CT10_Ztautau:mc12_8TeV.147772.Sherpa_CT10_Ztautau.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/"
        )

. ${PWD}/submit_cutflow.sh
