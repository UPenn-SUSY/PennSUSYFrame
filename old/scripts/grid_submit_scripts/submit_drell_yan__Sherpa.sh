#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.drell_yan__Sherpa'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          "173041.Sherpa_CT10_DYeeM08to15:mc12_8TeV.173041.Sherpa_CT10_DYeeM08to15.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1328/"
          "173042.Sherpa_CT10_DYeeM15to40:mc12_8TeV.173042.Sherpa_CT10_DYeeM15to40.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1328/"
          "173043.Sherpa_CT10_DYmumuM08to15:mc12_8TeV.173043.Sherpa_CT10_DYmumuM08to15.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1328/"
          "173044.Sherpa_CT10_DYmumuM15to40:mc12_8TeV.173044.Sherpa_CT10_DYmumuM15to40.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1328/"
          "173045.Sherpa_CT10_DYtautauM08to15:mc12_8TeV.173045.Sherpa_CT10_DYtautauM08to15.merge.NTUP_SUSY.e1669_s1581_s1586_r3658_r3549_p1328/"
          "173046.Sherpa_CT10_DYtautauM15to40:mc12_8TeV.173046.Sherpa_CT10_DYtautauM15to40.merge.NTUP_SUSY.e1669_s1581_s1586_r3658_r3549_p1328/"
        )

. ${PWD}/submit_cutflow.sh
