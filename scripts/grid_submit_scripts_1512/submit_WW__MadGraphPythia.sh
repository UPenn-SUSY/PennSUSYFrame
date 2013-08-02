#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.WW__MadGraphPythia'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list 
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          "167006:mc12_8TeV.167006.MadGraphPythia_AUET2BCTEQ6L1_WWWStar_lnulnulnu.merge.NTUP_SUSY.e1447_s1499_s1504_r3658_r3549_p1512/"
        )

. ${PWD}/submit_cutflow.sh
