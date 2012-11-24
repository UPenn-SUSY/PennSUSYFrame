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
ds_list=( "117800.Sherpa_CT10_TtbarLeptLept:mc12_8TeV.117800.Sherpa_CT10_TtbarLeptLept.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
          "117801.Sherpa_CT10_TtbarLeptTaulept:mc12_8TeV.117801.Sherpa_CT10_TtbarLeptTaulept.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
          "117802.Sherpa_CT10_TtbarTauleptTaulept:mc12_8TeV.117802.Sherpa_CT10_TtbarTauleptTaulept.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
          "117803.Sherpa_CT10_TtbarLeptHad:mc12_8TeV.117803.Sherpa_CT10_TtbarLeptHad.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
          "117804.Sherpa_CT10_TtbarLeptTauhad:mc12_8TeV.117804.Sherpa_CT10_TtbarLeptTauhad.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
          "117805.Sherpa_CT10_TtbarTauleptHad:mc12_8TeV.117805.Sherpa_CT10_TtbarTauleptHad.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
          "117806.Sherpa_CT10_TtbarTauleptTauhad:mc12_8TeV.117806.Sherpa_CT10_TtbarTauleptTauhad.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
          "117808.Sherpa_CT10_TtbarHadTauhad:mc12_8TeV.117808.Sherpa_CT10_TtbarHadTauhad.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
          "117809.Sherpa_CT10_TtbarTauhadTauhad:mc12_8TeV.117809.Sherpa_CT10_TtbarTauhadTauhad.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1181/"
        )

. ${PWD}/submit_presel.sh

# "105200.McAtNloJimmy_CT10_ttbar_LeptonFilter:mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_s1469_s1470_r3842_r3549_p1181/"

## =========================
## = Define some variables =
## =========================
#DATA_MC='mc'
#STREAM='egamma'
#SIM_TYPE='atlfast'
#OUT_DS_PREFIX='mc12_8TeV.ttbar'
#EXT_FILES=''
#
## ==============================
## = define list of input files =
## ==============================
## mc12 list
#ds_list=( "105861.PowhegPythia_AUET2BCT10_ttbar_LeptonFilter:mc12_8TeV.105861.PowhegPythia_AUET2BCT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1317_a159_a165_r3549_p1181/"
#        )
#
#. ${PWD}/submit_presel.sh



