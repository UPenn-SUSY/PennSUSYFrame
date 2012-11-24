#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.W_plus_jet'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# MC12 list
ds_list=( "147774.Sherpa_CT10_Wenu:mc12_8TeV.147774.Sherpa_CT10_Wenu.merge.NTUP_SUSY.e1161_s1469_s1470_r3542_r3549_p1181/"
          "147775.Sherpa_CT10_Wmunu:mc12_8TeV.147775.Sherpa_CT10_Wmunu.merge.NTUP_SUSY.e1161_s1469_s1470_r3752_r3549_p1181/"
          "147776.Sherpa_CT10_Wtaunu:mc12_8TeV.147776.Sherpa_CT10_Wtaunu.merge.NTUP_SUSY.e1161_s1469_s1470_r3542_r3549_p1181/"
        )

. ${PWD}/submit_presel.sh

