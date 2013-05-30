#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='atlfast'
OUT_DS_PREFIX='mc12_8TeV.ttbar__PowhegPythia'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          "105861.PowhegPythia_AUET2BCT10_ttbar_LeptonFilter:mc12_8TeV.105861.PowhegPythia_AUET2BCT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1317_a159_a165_r3549_p1328/"
)

. ${PWD}/submit_cutflow.sh
