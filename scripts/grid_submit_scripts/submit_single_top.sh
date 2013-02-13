#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.single_top'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list

#for now matches anders list -- I think this is more than enough for 2 REAL leptons, but need to check if other samples needed for something else

ds_list=( "117360.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_e:mc12_8TeV.117360.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_e.merge.NTUP_SUSY.e1346_s1499_s1504_r3658_r3549_p1328/"
          "117361.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_mu:mc12_8TeV.117361.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_mu.merge.NTUP_SUSY.e1346_s1499_s1504_r3658_r3549_p1328/"
          "117362.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_tau:mc12_8TeV.117362.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_tau.merge.NTUP_SUSY.e1346_s1499_s1504_r3658_r3549_p1328/"
          "108343.McAtNloJimmy_AUET2CT10_SingleTopSChanWenu:mc12_8TeV.108343.McAtNloJimmy_AUET2CT10_SingleTopSChanWenu.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1328/"
          "108344.McAtNloJimmy_AUET2CT10_SingleTopSChanWmunu:mc12_8TeV.108344.McAtNloJimmy_AUET2CT10_SingleTopSChanWmunu.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1328/"
          "108345.McAtNloJimmy_AUET2CT10_SingleTopSChanWtaunu:mc12_8TeV.108345.McAtNloJimmy_AUET2CT10_SingleTopSChanWtaunu.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1328/"
          "108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl:mc12_8TeV.108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1328/"

)

. ${PWD}/submit_presel.sh
