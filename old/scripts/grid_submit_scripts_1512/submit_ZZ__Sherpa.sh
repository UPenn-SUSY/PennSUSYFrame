#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.ZZ__Sherpa'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list 
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    "157814.Sherpa_CT10_VVtoeeqq:mc12_8TeV.157814.Sherpa_CT10_VVtoeeqq.merge.NTUP_SUSY.e1515_s1499_s1504_r3658_r3549_p1512/"
    "157815.Sherpa_CT10_VVtomumuqq:mc12_8TeV.157815.Sherpa_CT10_VVtomumuqq.merge.NTUP_SUSY.e1515_s1499_s1504_r3658_r3549_p1512/"
    "157816.Sherpa_CT10_VVtotautauqq:mc12_8TeV.157816.Sherpa_CT10_VVtotautauqq.merge.NTUP_SUSY.e1515_s1499_s1504_r3658_r3549_p1512/"
        )

. ${PWD}/submit_cutflow.sh
