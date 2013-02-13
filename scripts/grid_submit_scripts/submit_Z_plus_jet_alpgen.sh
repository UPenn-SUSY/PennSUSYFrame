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
ds_list=( "107650.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp0:mc12_8TeV.107650.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp0.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107651.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp1:mc12_8TeV.107651.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp1.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107652.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp2:mc12_8TeV.107652.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp2.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107653.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp3:mc12_8TeV.107653.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp3.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107654.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp4:mc12_8TeV.107654.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp4.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107655.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp5:mc12_8TeV.107655.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp5.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          ##"107660.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp0:group.phys-susy.mc12_8TeV.107660.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp0.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328.0/
          ##"107661.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp1:group.phys-susy.mc12_8TeV.107661.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp1.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328.0/
          ##"107662.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp2:group.phys-susy.mc12_8TeV.107662.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp2.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328.0/
          ##"107663.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp3:group.phys-susy.mc12_8TeV.107663.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp3.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328.0/
          ##"107664.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp4:group.phys-susy.mc12_8TeV.107664.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp4.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328.0/
          ##"107665.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp5:group.phys-susy.mc12_8TeV.107665.AlpgenJimmy_AUET2CTEQ6L1_ZmumuNp5.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328.0/
          ##"107670.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp0:
          ##"107671.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp1:
          ##"107672.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp2:
          ##"107673.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp3:
          ##"107674.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp4:
          ##"107675.AlpgenJimmy_AUET2CTEQ6L1_ZtautauNp5:
          "109300.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp0:mc12_8TeV.109300.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp0.merge.NTUP_SUSY.e1601_s1499_s1504_r3658_r3549_p1328/"
          "109301.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp1:mc12_8TeV.109301.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp1.merge.NTUP_SUSY.e1601_s1499_s1504_r3658_r3549_p1328/"
          "109302.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp2:mc12_8TeV.109302.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp2.merge.NTUP_SUSY.e1601_s1499_s1504_r3658_r3549_p1328/"
          "109303.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp3:mc12_8TeV.109303.AlpgenJimmy_AUET2CTEQ6L1_ZeebbNp3.merge.NTUP_SUSY.e1601_s1499_s1504_r3658_r3549_p1328/"          
          ##"109310.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp0:
          ##"109311.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp1:
          ##"109312.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp2:
          ##"109313.AlpgenJimmy_AUET2CTEQ6L1_ZtautaubbNp3:
          ##"117706.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp0:
          ##"117707.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp1:
          ##"117708.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp2:
          ##"117709.AlpgenJimmy_AUET2CTEQ6L1_ZtautauccNp3:
          "126415.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp1:mc12_8TeV.126415.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp1.merge.NTUP_SUSY.e1601_s1499_s1504_r3658_r3549_p1328/"
          "126416.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp2:mc12_8TeV.126416.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp2.merge.NTUP_SUSY.e1601_s1499_s1504_r3658_r3549_p1328/"
          "126417.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp3:mc12_8TeV.126417.AlpgenJimmy_AUET2CTEQ6L1_ZeeccNp3.merge.NTUP_SUSY.e1601_s1499_s1504_r3658_r3549_p1328/"

          ##"126418.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp0:
          ##"126419.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp1:
          ##"126420.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp2:
          ##"126421.AlpgenJimmy_AUET2CTEQ6L1_ZmumuccNp3:
        )

. ${PWD}/submit_presel.sh
