#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.ZZ__PowhegPythia'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list 
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          "126937.PowhegPythia8_AU2CT10_ZZ_4e_mll4_2pt5:mc12_8TeV.126937.PowhegPythia8_AU2CT10_ZZ_4e_mll4_2pt5.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/"
          "126938.PowhegPythia8_AU2CT10_ZZ_2e2mu_mll4_2pt5:mc12_8TeV.126938.PowhegPythia8_AU2CT10_ZZ_2e2mu_mll4_2pt5.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/"
          "126939.PowhegPythia8_AU2CT10_ZZ_2e2tau_mll4_2pt5:mc12_8TeV.126939.PowhegPythia8_AU2CT10_ZZ_2e2tau_mll4_2pt5.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/"
          "126940.PowhegPythia8_AU2CT10_ZZ_4mu_mll4_2pt5:mc12_8TeV.126940.PowhegPythia8_AU2CT10_ZZ_4mu_mll4_2pt5.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/"
          "126941.PowhegPythia8_AU2CT10_ZZ_2mu2tau_mll4_2pt5:mc12_8TeV.126941.PowhegPythia8_AU2CT10_ZZ_2mu2tau_mll4_2pt5.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/"
          "126942.PowhegPythia8_AU2CT10_ZZ_4tau_mll4_2pt5:mc12_8TeV.126942.PowhegPythia8_AU2CT10_ZZ_4tau_mll4_2pt5.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/"
          "126949.PowhegPythia8_AU2CT10_ZZllnunu_ee_mll4:mc12_8TeV.126949.PowhegPythia8_AU2CT10_ZZllnunu_ee_mll4.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/"
          "126950.PowhegPythia8_AU2CT10_ZZllnunu_mm_mll4:mc12_8TeV.126950.PowhegPythia8_AU2CT10_ZZllnunu_mm_mll4.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/"
          "126951.PowhegPythia8_AU2CT10_ZZllnunu_tt_mll4:mc12_8TeV.126951.PowhegPythia8_AU2CT10_ZZllnunu_tt_mll4.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/"
        )

. ${PWD}/submit_cutflow.sh
