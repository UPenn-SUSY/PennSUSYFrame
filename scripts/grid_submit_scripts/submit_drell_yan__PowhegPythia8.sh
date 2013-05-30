#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.drell_yan__PowhegPythia8'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          "129501.PowhegPythia8_AU2CT10_DYee_20M60:mc12_8TeV.129501.PowhegPythia8_AU2CT10_DYee_20M60.merge.NTUP_SUSY.e1248_s1469_s1470_r3542_r3549_p1328/"
          "129521.PowhegPythia8_AU2CT10_DYmumu_20M60:mc12_8TeV.129521.PowhegPythia8_AU2CT10_DYmumu_20M60.merge.NTUP_SUSY.e1248_s1469_s1470_r3542_r3549_p1328/"
        )

. ${PWD}/submit_cutflow.sh
