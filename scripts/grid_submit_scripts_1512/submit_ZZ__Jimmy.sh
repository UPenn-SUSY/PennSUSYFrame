#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.ZZ__Jimmy'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list 
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    "116601.gg2ZZJimmy_AUET2CT10_ZZ4e:mc12_8TeV.116601.gg2ZZJimmy_AUET2CT10_ZZ4e.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512/"
    "116603.gg2ZZJimmy_AUET2CT10_ZZ2e2mu:mc12_8TeV.116603.gg2ZZJimmy_AUET2CT10_ZZ2e2mu.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512/"
    "116600.gg2ZZJimmy_AUET2CT10_ZZ4lep:mc12_8TeV.116600.gg2ZZJimmy_AUET2CT10_ZZ4lep.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512/"
    "116602.gg2ZZJimmy_AUET2CT10_ZZ4mu:mc12_8TeV.116602.gg2ZZJimmy_AUET2CT10_ZZ4mu.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512/"
        )

. ${PWD}/submit_cutflow.sh
