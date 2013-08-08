#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='atlfast'
OUT_DS_PREFIX='mc12_8TeV.ZX__Sherpa_atlfast'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          "147770.Sherpa_CT10_Zee:mc12_8TeV.147770.Sherpa_CT10_Zee.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/"
          "147771.Sherpa_CT10_Zmumu:mc12_8TeV.147771.Sherpa_CT10_Zmumu.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/"
          "147772.Sherpa_CT10_Ztautau:mc12_8TeV.147772.Sherpa_CT10_Ztautau.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/"
          "173041.Sherpa_CT10_DYeeM08to15:mc12_8TeV.173041.Sherpa_CT10_DYeeM08to15.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1512/"
          "173042.Sherpa_CT10_DYeeM15to40:mc12_8TeV.173042.Sherpa_CT10_DYeeM15to40.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1512/"
          "173043.Sherpa_CT10_DYmumuM08to15:mc12_8TeV.173043.Sherpa_CT10_DYmumuM08to15.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1512/"
          "173044.Sherpa_CT10_DYmumuM15to40:mc12_8TeV.173044.Sherpa_CT10_DYmumuM15to40.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1512/"
          "173045.Sherpa_CT10_DYtautauM08to15:mc12_8TeV.173045.Sherpa_CT10_DYtautauM08to15.merge.NTUP_SUSY.e1669_s1581_s1586_r3658_r3549_p1512/"
          "173046.Sherpa_CT10_DYtautauM15to40:mc12_8TeV.173046.Sherpa_CT10_DYtautauM15to40.merge.NTUP_SUSY.e1669_s1581_s1586_r3658_r3549_p1512/"
        )

. ${PWD}/submit_cutflow.sh

