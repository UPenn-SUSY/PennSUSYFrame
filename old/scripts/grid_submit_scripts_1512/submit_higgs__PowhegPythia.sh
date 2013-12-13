#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.Higgs__PowhegPythia'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list
ds_list=(
    "160155.PowhegPythia8_AU2CT10_ggH125_ZZ4lep:mc12_8TeV.160155.PowhegPythia8_AU2CT10_ggH125_ZZ4lep.merge.NTUP_SUSY.e1191_s1469_s1470_r3542_r3549_p1512/"
    "160205.PowhegPythia8_AU2CT10_VBFH125_ZZ4lep:mc12_8TeV.160205.PowhegPythia8_AU2CT10_VBFH125_ZZ4lep.merge.NTUP_SUSY.e1195_s1469_s1470_r3542_r3549_p1512/"
    "160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu:mc12_8TeV.160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu.merge.NTUP_SUSY.e1447_s1499_s1504_r3658_r3549_p1512/"
    "160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu:mc12_8TeV.160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu.merge.NTUP_SUSY.e1447_s1499_s1504_r3658_r3549_p1512/"
    "161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5:mc12_8TeV.161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5.merge.NTUP_SUSY.e1285_s1469_s1470_r3542_r3549_p1512/"
    "161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5:mc12_8TeV.161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5.merge.NTUP_SUSY.e1285_s1469_s1470_r3542_r3549_p1512/"
)
. ${PWD}/submit_cutflow.sh
