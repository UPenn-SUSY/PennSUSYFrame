#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.ttbar'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          "119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW:mc12_8TeV.119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW.merge.NTUP_SUSY.e1352_s1499_s1504_r3658_r3549_p1328/"
          "119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj:mc12_8TeV.119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj.merge.NTUP_SUSY.e1352_s1499_s1504_r3658_r3549_p1328/"
          "119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ:mc12_8TeV.119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ.merge.NTUP_SUSY.e1352_s1499_s1504_r3658_r3549_p1328/"
          "119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj:mc12_8TeV.119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj.merge.NTUP_SUSY.e1352_s1499_s1504_r3658_r3549_p1328/"
          "119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW:mc12_8TeV.119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW.merge.NTUP_SUSY.e1543_s1499_s1504_r3658_r3549_p1328/"
)

. ${PWD}/submit_cutflow.sh
