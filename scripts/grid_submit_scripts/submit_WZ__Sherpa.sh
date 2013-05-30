#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.WZ__Sherpa'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list 
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          "126893.Sherpa_CT10_lllnu_WZ:mc12_8TeV.126893.Sherpa_CT10_lllnu_WZ.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1328/"
        )

. ${PWD}/submit_cutflow.sh
