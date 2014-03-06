#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.WW__Sherpa'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list 
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          "126892.Sherpa_CT10_llnunu_WW:mc12_8TeV.126892.Sherpa_CT10_llnunu_WW.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/"
          "126988.Sherpa_CT10_llnunu_SS_EW6:mc12_8TeV.126988.Sherpa_CT10_llnunu_SS_EW6.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/"
          "126989.Sherpa_CT10_llnunujj_SS:mc12_8TeV.126989.Sherpa_CT10_llnunujj_SS.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/"
          "157819.Sherpa_CT10_VVtotaunuqq:mc12_8TeV.157819.Sherpa_CT10_VVtotaunuqq.merge.NTUP_SUSY.e1515_s1499_s1504_r3658_r3549_p1512/"
          "157818.Sherpa_CT10_VVtomunuqq:mc12_8TeV.157818.Sherpa_CT10_VVtomunuqq.merge.NTUP_SUSY.e1515_s1499_s1504_r3658_r3549_p1512/"
          "157817.Sherpa_CT10_VVtoenuqq:mc12_8TeV.157817.Sherpa_CT10_VVtoenuqq.merge.NTUP_SUSY.e1515_s1499_s1504_r3658_r3549_p1512/"
        )

. ${PWD}/submit_cutflow.sh
