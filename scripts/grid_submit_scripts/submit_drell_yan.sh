#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.drell_yan'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list
ds_list=( "146830.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp0Excl_Mll10to60:mc12_8TeV.146830.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp0Excl_Mll10to60.merge.NTUP_SUSY.e1254_s1469_s1470_r3542_r3549_p1181/"
          "146831.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp1Excl_Mll10to60:mc12_8TeV.146831.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp1Excl_Mll10to60.merge.NTUP_SUSY.e1254_s1469_s1470_r3542_r3549_p1181/"
          "146832.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp2Excl_Mll10to60:mc12_8TeV.146832.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp2Excl_Mll10to60.merge.NTUP_SUSY.e1254_s1469_s1470_r3542_r3549_p1181/"
          "146833.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp3Excl_Mll10to60:mc12_8TeV.146833.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp3Excl_Mll10to60.merge.NTUP_SUSY.e1254_s1469_s1470_r3542_r3549_p1181/"
          "146834.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp4Excl_Mll10to60:mc12_8TeV.146834.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp4Excl_Mll10to60.merge.NTUP_SUSY.e1274_s1469_s1470_r3542_r3549_p1181/"
          "146835.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp5Incl_Mll10to60:mc12_8TeV.146835.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp5Incl_Mll10to60.merge.NTUP_SUSY.e1274_s1469_s1470_r3542_r3549_p1181/"
          "146840.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp0Excl_Mll10to60:mc12_8TeV.146840.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp0Excl_Mll10to60.merge.NTUP_SUSY.e1254_s1469_s1470_r3542_r3549_p1181/"
          "146841.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp1Excl_Mll10to60:mc12_8TeV.146841.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp1Excl_Mll10to60.merge.NTUP_SUSY.e1254_s1469_s1470_r3542_r3549_p1181/"
          "146842.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp2Excl_Mll10to60:mc12_8TeV.146842.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp2Excl_Mll10to60.merge.NTUP_SUSY.e1254_s1469_s1470_r3542_r3549_p1181/"
          "146843.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp3Excl_Mll10to60:mc12_8TeV.146843.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp3Excl_Mll10to60.merge.NTUP_SUSY.e1254_s1469_s1470_r3542_r3549_p1181/"
          "146844.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp4Excl_Mll10to60:mc12_8TeV.146844.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp4Excl_Mll10to60.merge.NTUP_SUSY.e1274_s1469_s1470_r3542_r3549_p1181/"
          "146845.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp5Incl_Mll10to60:mc12_8TeV.146845.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZmumuNp5Incl_Mll10to60.merge.NTUP_SUSY.e1274_s1469_s1470_r3542_r3549_p1181/"
          "146850.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp0Excl_Mll10to60:mc12_8TeV.146850.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp0Excl_Mll10to60.merge.NTUP_SUSY.e1254_s1469_s1470_r3542_r3549_p1181/"
          "146851.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp1Excl_Mll10to60:mc12_8TeV.146851.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp1Excl_Mll10to60.merge.NTUP_SUSY.e1254_s1469_s1470_r3542_r3549_p1181/"
          "146852.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp2Excl_Mll10to60:mc12_8TeV.146852.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp2Excl_Mll10to60.merge.NTUP_SUSY.e1254_s1469_s1470_r3542_r3549_p1181/"
          "146853.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp3Excl_Mll10to60:mc12_8TeV.146853.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp3Excl_Mll10to60.merge.NTUP_SUSY.e1254_s1469_s1470_r3542_r3549_p1181/"
          "146854.AlpgenJimmy_Auto_AUET3CTEQ6L1_ZtautauNp4Excl_Mll10to60:mc12_8TeV.146854.AlpgenJimmy_Auto_AUET3CTEQ6L1_ZtautauNp4Excl_Mll10to60.merge.NTUP_SUSY.e1274_s1469_s1470_r3542_r3549_p1181/"
          "146855.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp5Incl_Mll10to60:mc12_8TeV.146855.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZtautauNp5Incl_Mll10to60.merge.NTUP_SUSY.e1274_s1469_s1470_r3542_r3549_p1181/"
        )

. ${PWD}/submit_presel.sh
