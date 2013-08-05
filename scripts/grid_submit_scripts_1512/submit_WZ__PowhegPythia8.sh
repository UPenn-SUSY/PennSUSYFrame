#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.WZ__PowhegPythia'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list 
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          "129477.PowhegPythia8_AU2CT10_WZ_Wm11Z11_mll0p250d0_2LeptonFilter5:mc12_8TeV.129477.PowhegPythia8_AU2CT10_WZ_Wm11Z11_mll0p250d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/"
          "129478.PowhegPythia8_AU2CT10_WZ_Wm11Z13_mll0p4614d0_2LeptonFilter5:mc12_8TeV.129478.PowhegPythia8_AU2CT10_WZ_Wm11Z13_mll0p4614d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/"
          "129479.PowhegPythia8_AU2CT10_WZ_Wm11Z15_mll3p804d0_2LeptonFilter5:mc12_8TeV.129479.PowhegPythia8_AU2CT10_WZ_Wm11Z15_mll3p804d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/"
          "129480.PowhegPythia8_AU2CT10_WZ_Wm13Z11_mll0p250d0_2LeptonFilter5:mc12_8TeV.129480.PowhegPythia8_AU2CT10_WZ_Wm13Z11_mll0p250d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/"
          "129481.PowhegPythia8_AU2CT10_WZ_Wm13Z13_mll0p4614d0_2LeptonFilter5:mc12_8TeV.129481.PowhegPythia8_AU2CT10_WZ_Wm13Z13_mll0p4614d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/"
          "129482.PowhegPythia8_AU2CT10_WZ_Wm13Z15_mll3p804d0_2LeptonFilter5:mc12_8TeV.129482.PowhegPythia8_AU2CT10_WZ_Wm13Z15_mll3p804d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/"
          "129483.PowhegPythia8_AU2CT10_WZ_Wm15Z11_mll0p250d0_2LeptonFilter5:mc12_8TeV.129483.PowhegPythia8_AU2CT10_WZ_Wm15Z11_mll0p250d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/"
          "129484.PowhegPythia8_AU2CT10_WZ_Wm15Z13_mll0p4614d0_2LeptonFilter5:mc12_8TeV.129484.PowhegPythia8_AU2CT10_WZ_Wm15Z13_mll0p4614d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/"
          "129485.PowhegPythia8_AU2CT10_WZ_Wm15Z15_mll3p804d0_2LeptonFilter5:mc12_8TeV.129485.PowhegPythia8_AU2CT10_WZ_Wm15Z15_mll3p804d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/"
          "129486.PowhegPythia8_AU2CT10_WZ_W11Z11_mll0p250d0_2LeptonFilter5:mc12_8TeV.129486.PowhegPythia8_AU2CT10_WZ_W11Z11_mll0p250d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/"
          "129487.PowhegPythia8_AU2CT10_WZ_W11Z13_mll0p4614d0_2LeptonFilter5:mc12_8TeV.129487.PowhegPythia8_AU2CT10_WZ_W11Z13_mll0p4614d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/"
          "129488.PowhegPythia8_AU2CT10_WZ_W11Z15_mll3p804d0_2LeptonFilter5:mc12_8TeV.129488.PowhegPythia8_AU2CT10_WZ_W11Z15_mll3p804d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/"
          "129489.PowhegPythia8_AU2CT10_WZ_W13Z11_mll0p250d0_2LeptonFilter5:mc12_8TeV.129489.PowhegPythia8_AU2CT10_WZ_W13Z11_mll0p250d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/"
          "129490.PowhegPythia8_AU2CT10_WZ_W13Z13_mll0p4614d0_2LeptonFilter5:mc12_8TeV.129490.PowhegPythia8_AU2CT10_WZ_W13Z13_mll0p4614d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/"
          "129491.PowhegPythia8_AU2CT10_WZ_W13Z15_mll3p804d0_2LeptonFilter5:mc12_8TeV.129491.PowhegPythia8_AU2CT10_WZ_W13Z15_mll3p804d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/"
          "129492.PowhegPythia8_AU2CT10_WZ_W15Z11_mll0p250d0_2LeptonFilter5:mc12_8TeV.129492.PowhegPythia8_AU2CT10_WZ_W15Z11_mll0p250d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/"
          "129493.PowhegPythia8_AU2CT10_WZ_W15Z13_mll0p4614d0_2LeptonFilter5:mc12_8TeV.129493.PowhegPythia8_AU2CT10_WZ_W15Z13_mll0p4614d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/"
          "129494.PowhegPythia8_AU2CT10_WZ_W15Z15_mll3p804d0_2LeptonFilter5:mc12_8TeV.129494.PowhegPythia8_AU2CT10_WZ_W15Z15_mll3p804d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/"
        )

. ${PWD}/submit_cutflow.sh
