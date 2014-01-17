#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.single_top__McAtNloJimmy'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          "108343.McAtNloJimmy_AUET2CT10_SingleTopSChanWenu:mc12_8TeV.108343.McAtNloJimmy_AUET2CT10_SingleTopSChanWenu.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1328/"
          "108344.McAtNloJimmy_AUET2CT10_SingleTopSChanWmunu:mc12_8TeV.108344.McAtNloJimmy_AUET2CT10_SingleTopSChanWmunu.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1328/"
          "108345.McAtNloJimmy_AUET2CT10_SingleTopSChanWtaunu:mc12_8TeV.108345.McAtNloJimmy_AUET2CT10_SingleTopSChanWtaunu.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1328/"
          "108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl:mc12_8TeV.108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1328/"
)

. ${PWD}/submit_cutflow.sh