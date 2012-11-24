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
ds_list=( "157820.Sherpa_CT10_SingleTop_tLept_qqqq:mc12_8TeV.157820.Sherpa_CT10_SingleTop_tLept_qqqq.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
          "157821.Sherpa_CT10_SingleTop_tTau_qqqq:mc12_8TeV.157821.Sherpa_CT10_SingleTop_tTau_qqqq.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
          "157822.Sherpa_CT10_SingleTop_tbarLept_qqqq:mc12_8TeV.157822.Sherpa_CT10_SingleTop_tbarLept_qqqq.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
          "157823.Sherpa_CT10_SingleTop_tbarTau_qqqq:mc12_8TeV.157823.Sherpa_CT10_SingleTop_tbarTau_qqqq.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
          "157824.Sherpa_CT10_SingleTop_tHad_W_qqq:mc12_8TeV.157824.Sherpa_CT10_SingleTop_tHad_W_qqq.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
          "157825.Sherpa_CT10_SingleTop_tLept_W_qqq:mc12_8TeV.157825.Sherpa_CT10_SingleTop_tLept_W_qqq.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
          "157826.Sherpa_CT10_SingleTop_tTau_W_qqq:mc12_8TeV.157826.Sherpa_CT10_SingleTop_tTau_W_qqq.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
          "157827.Sherpa_CT10_SingleTop_tbarHad_W_qqq:mc12_8TeV.157827.Sherpa_CT10_SingleTop_tbarHad_W_qqq.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
          "157828.Sherpa_CT10_SingleTop_tbarLept_W_qqq:mc12_8TeV.157828.Sherpa_CT10_SingleTop_tbarLept_W_qqq.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
          "157829.Sherpa_CT10_SingleTop_tbarTau_W_qqq:mc12_8TeV.157829.Sherpa_CT10_SingleTop_tbarTau_W_qqq.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
        )

. ${PWD}/submit_presel.sh
