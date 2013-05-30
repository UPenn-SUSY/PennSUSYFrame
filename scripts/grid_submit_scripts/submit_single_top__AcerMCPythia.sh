#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.single_top__AcerMCPythia'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          "117360.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_e:mc12_8TeV.117360.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_e.merge.NTUP_SUSY.e1346_s1499_s1504_r3658_r3549_p1328/"
          "117361.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_mu:mc12_8TeV.117361.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_mu.merge.NTUP_SUSY.e1346_s1499_s1504_r3658_r3549_p1328/"
          "117362.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_tau:mc12_8TeV.117362.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_tau.merge.NTUP_SUSY.e1346_s1499_s1504_r3658_r3549_p1328/"
)

. ${PWD}/submit_cutflow.sh
