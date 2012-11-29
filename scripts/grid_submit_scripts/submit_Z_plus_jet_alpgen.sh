#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.Z_plus_jet'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list
ds_list=( "107650.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp0:mc12_8TeV.107650.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp0.merge.NTUP_SUSY.e1218_s1469_s1470_r3542_r3549_p1181/"
          "107651.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp1:mc12_8TeV.107651.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp1.merge.NTUP_SUSY.e1218_s1469_s1470_r3542_r3549_p1181/"
          "107652.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp2:mc12_8TeV.107652.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp2.merge.NTUP_SUSY.e1218_s1469_s1470_r3542_r3549_p1181/"
          "107653.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp3:mc12_8TeV.107653.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp3.merge.NTUP_SUSY.e1218_s1469_s1470_r3542_r3549_p1181/"
          "107654.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp4:mc12_8TeV.107654.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp4.merge.NTUP_SUSY.e1218_s1469_s1470_r3542_r3549_p1181/"
          "107655.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp5:mc12_8TeV.107655.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp5.merge.NTUP_SUSY.e1218_s1469_s1470_r3542_r3549_p1181/"
          "107660.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp0:mc12_8TeV.107660.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp0.merge.NTUP_SUSY.e1218_s1469_s1470_r3542_r3549_p1181/"
          "107661.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp1:mc12_8TeV.107661.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp1.merge.NTUP_SUSY.e1218_s1469_s1470_r3542_r3549_p1181/"
          "107662.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp2:mc12_8TeV.107662.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp2.merge.NTUP_SUSY.e1218_s1469_s1470_r3542_r3549_p1181/"
          "107663.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp3:mc12_8TeV.107663.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp3.merge.NTUP_SUSY.e1218_s1469_s1470_r3542_r3549_p1181/"
          "107664.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp4:mc12_8TeV.107664.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp4.merge.NTUP_SUSY.e1218_s1469_s1470_r3542_r3549_p1181/"
          "107665.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp5:mc12_8TeV.107665.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp5.merge.NTUP_SUSY.e1218_s1469_s1470_r3542_r3549_p1181/"
          "107670.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp0:mc12_8TeV.107670.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp0.merge.NTUP_SUSY.e1218_s1469_s1470_r3542_r3549_p1181/"
          "107671.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp1:mc12_8TeV.107671.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp1.merge.NTUP_SUSY.e1218_s1469_s1470_r3542_r3549_p1181/"
          "107672.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp2:mc12_8TeV.107672.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp2.merge.NTUP_SUSY.e1218_s1469_s1470_r3542_r3549_p1181/"
          "107673.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp3:mc12_8TeV.107673.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp3.merge.NTUP_SUSY.e1218_s1469_s1470_r3542_r3549_p1181/"
          "107674.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp4:mc12_8TeV.107674.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp4.merge.NTUP_SUSY.e1218_s1469_s1470_r3542_r3549_p1181/"
          "107675.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp5:mc12_8TeV.107675.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp5.merge.NTUP_SUSY.e1218_s1469_s1470_r3542_r3549_p1181/"
          "109300.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp0:mc12_8TeV.109300.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp0.merge.NTUP_SUSY.e1303_s1469_s1470_r3542_r3549_p1181/"
          "109301.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp1:mc12_8TeV.109301.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp1.merge.NTUP_SUSY.e1303_s1469_s1470_r3542_r3549_p1181/"
          "109302.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp2:mc12_8TeV.109302.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp2.merge.NTUP_SUSY.e1303_s1469_s1470_r3752_r3549_p1181/"
          "109303.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp3:mc12_8TeV.109303.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp3.merge.NTUP_SUSY.e1303_s1469_s1470_r3542_r3549_p1181/"
          "109310.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp0:mc12_8TeV.109310.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp0.merge.NTUP_SUSY.e1303_s1469_s1470_r3542_r3549_p1181/"
          "109311.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp1:mc12_8TeV.109311.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp1.merge.NTUP_SUSY.e1303_s1469_s1470_r3752_r3549_p1181/"
          "109312.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp2:mc12_8TeV.109312.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp2.merge.NTUP_SUSY.e1303_s1469_s1470_r3542_r3549_p1181/"
          "109313.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp3:mc12_8TeV.109313.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp3.merge.NTUP_SUSY.e1303_s1469_s1470_r3542_r3549_p1181/"
          "117706.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp0:mc12_8TeV.117706.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp0.merge.NTUP_SUSY.e1303_s1469_s1470_r3752_r3549_p1181/"
          "117707.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp1:mc12_8TeV.117707.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp1.merge.NTUP_SUSY.e1303_s1469_s1470_r3542_r3549_p1181/"
          "117708.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp2:mc12_8TeV.117708.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp2.merge.NTUP_SUSY.e1303_s1469_s1470_r3542_r3549_p1181/"
          "117709.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp3:mc12_8TeV.117709.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp3.merge.NTUP_SUSY.e1303_s1469_s1470_r3752_r3549_p1181/"
          "126414.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp0:mc12_8TeV.126414.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp0.merge.NTUP_SUSY.e1303_s1469_s1470_r3752_r3549_p1181/"
          "126415.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp1:mc12_8TeV.126415.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp1.merge.NTUP_SUSY.e1303_s1469_s1470_r3542_r3549_p1181/"
          "126416.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp2:mc12_8TeV.126416.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp2.merge.NTUP_SUSY.e1303_s1469_s1470_r3542_r3549_p1181/"
          "126417.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp3:mc12_8TeV.126417.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp3.merge.NTUP_SUSY.e1303_s1469_s1470_r3542_r3549_p1181/"
          "126418.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp0:mc12_8TeV.126418.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp0.merge.NTUP_SUSY.e1303_s1469_s1470_r3752_r3549_p1181/"
          "126419.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp1:mc12_8TeV.126419.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp1.merge.NTUP_SUSY.e1303_s1469_s1470_r3542_r3549_p1181/"
          "126420.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp2:mc12_8TeV.126420.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp2.merge.NTUP_SUSY.e1303_s1469_s1470_r3752_r3549_p1181/"
          "126421.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp3:mc12_8TeV.126421.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp3.merge.NTUP_SUSY.e1303_s1469_s1470_r3542_r3549_p1181/"
        )

. ${PWD}/submit_presel.sh