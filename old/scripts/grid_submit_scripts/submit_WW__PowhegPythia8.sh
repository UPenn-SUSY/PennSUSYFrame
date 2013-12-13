#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.WW__PowhegPythia8'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list 
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          "126928.PowhegPythia8_AU2CT10_WpWm_ee:mc12_8TeV.126928.PowhegPythia8_AU2CT10_WpWm_ee.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126929.PowhegPythia8_AU2CT10_WpWm_me:mc12_8TeV.126929.PowhegPythia8_AU2CT10_WpWm_me.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126930.PowhegPythia8_AU2CT10_WpWm_te:mc12_8TeV.126930.PowhegPythia8_AU2CT10_WpWm_te.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126931.PowhegPythia8_AU2CT10_WpWm_em:mc12_8TeV.126931.PowhegPythia8_AU2CT10_WpWm_em.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126932.PowhegPythia8_AU2CT10_WpWm_mm:mc12_8TeV.126932.PowhegPythia8_AU2CT10_WpWm_mm.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126933.PowhegPythia8_AU2CT10_WpWm_tm:mc12_8TeV.126933.PowhegPythia8_AU2CT10_WpWm_tm.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126934.PowhegPythia8_AU2CT10_WpWm_et:mc12_8TeV.126934.PowhegPythia8_AU2CT10_WpWm_et.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126935.PowhegPythia8_AU2CT10_WpWm_mt:mc12_8TeV.126935.PowhegPythia8_AU2CT10_WpWm_mt.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126936.PowhegPythia8_AU2CT10_WpWm_tt:mc12_8TeV.126936.PowhegPythia8_AU2CT10_WpWm_tt.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
        )

. ${PWD}/submit_cutflow.sh
