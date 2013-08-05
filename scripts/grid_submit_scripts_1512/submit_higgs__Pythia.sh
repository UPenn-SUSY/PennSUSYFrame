#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.Higgs'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list
ds_list=(
    "160255.Pythia8_AU2CTEQ6L1_WH125_ZZ4lep:mc12_8TeV.160255.Pythia8_AU2CTEQ6L1_WH125_ZZ4lep.merge.NTUP_SUSY.e1419_s1499_s1504_r3658_r3549_p1512/"
    "160305.Pythia8_AU2CTEQ6L1_ZH125_ZZ4lep:mc12_8TeV.160305.Pythia8_AU2CTEQ6L1_ZH125_ZZ4lep.merge.NTUP_SUSY.e1217_s1469_s1470_r3542_r3549_p1512/"
    "160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu:mc12_8TeV.160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu.merge.NTUP_SUSY.e1217_s1469_s1470_r3542_r3549_p1512/"
    "160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu:mc12_8TeV.160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu.merge.NTUP_SUSY.e1217_s1469_s1470_r3542_r3549_p1512/"       
    "161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep:mc12_8TeV.161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep.merge.NTUP_SUSY.e1285_s1469_s1470_r3542_r3549_p1512/"
    "161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep:mc12_8TeV.161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep.merge.NTUP_SUSY.e1285_s1469_s1470_r3542_r3549_p1512/"
)
. ${PWD}/submit_cutflow.sh
