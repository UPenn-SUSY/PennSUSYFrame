#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.diboson'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list 
ds_list=( "126892.Sherpa_CT10_llnunu_WW:mc12_8TeV.126892.Sherpa_CT10_llnunu_WW.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1328/"
          "126893.Sherpa_CT10_lllnu_WZ:mc12_8TeV.126893.Sherpa_CT10_lllnu_WZ.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1328/"
          "126894.Sherpa_CT10_llll_ZZ:mc12_8TeV.126894.Sherpa_CT10_llll_ZZ.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1328/"
          "126895.Sherpa_CT10_llnunu_ZZ:mc12_8TeV.126895.Sherpa_CT10_llnunu_ZZ.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1328/"
        )

. ${PWD}/submit_presel.sh
