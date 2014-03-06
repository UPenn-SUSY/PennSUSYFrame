#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.ttbar__McAtNloJimmy'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list
ds_list=(
          "105200.McAtNloJimmy_CT10_ttbar_LeptonFilter:mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_s1499_s1504_r3945_r3549_p1328/"
)

. ${PWD}/submit_cutflow.sh
