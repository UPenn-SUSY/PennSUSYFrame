#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.Triboson'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list 
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    "167008.MadGraphPythia_AUET2BCTEQ6L1_ZZZStar_nunullll:mc12_8TeV.167008.MadGraphPythia_AUET2BCTEQ6L1_ZZZStar_nunullll.merge.NTUP_SUSY.e1466_s1499_s1504_r3658_r3549_p1512/"
    "167007.MadGraphPythia_AUET2BCTEQ6L1_ZWWStar_lllnulnu:mc12_8TeV.167007.MadGraphPythia_AUET2BCTEQ6L1_ZWWStar_lllnulnu.merge.NTUP_SUSY.e1466_s1499_s1504_r3658_r3549_p1512/"
        )

. ${PWD}/submit_cutflow.sh
