#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.W_plus_jet'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# MC12 list
ds_list=( 
          "107680.AlpgenJimmy_AUET2CTEQ6L1_WenuNp0:mc12_8TeV.107680.AlpgenJimmy_AUET2CTEQ6L1_WenuNp0.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107681.AlpgenJimmy_AUET2CTEQ6L1_WenuNp1:mc12_8TeV.107681.AlpgenJimmy_AUET2CTEQ6L1_WenuNp1.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107682.AlpgenJimmy_AUET2CTEQ6L1_WenuNp2:mc12_8TeV.107682.AlpgenJimmy_AUET2CTEQ6L1_WenuNp2.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107683.AlpgenJimmy_AUET2CTEQ6L1_WenuNp3:mc12_8TeV.107683.AlpgenJimmy_AUET2CTEQ6L1_WenuNp3.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107684.AlpgenJimmy_AUET2CTEQ6L1_WenuNp4:mc12_8TeV.107684.AlpgenJimmy_AUET2CTEQ6L1_WenuNp4.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107685.AlpgenJimmy_AUET2CTEQ6L1_WenuNp5:mc12_8TeV.107685.AlpgenJimmy_AUET2CTEQ6L1_WenuNp5.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107690.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp0:mc12_8TeV.107690.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp0.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107691.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp1:mc12_8TeV.107691.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp1.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107692.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp2:mc12_8TeV.107692.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp2.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107693.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp3:mc12_8TeV.107693.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp3.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107694.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp4:mc12_8TeV.107694.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp4.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107695.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp5:mc12_8TeV.107695.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp5.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107700.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp0:mc12_8TeV.107700.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp0.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107701.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp1:mc12_8TeV.107701.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp1.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107702.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp2:mc12_8TeV.107702.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp2.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107703.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp3:mc12_8TeV.107703.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp3.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107704.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp4:mc12_8TeV.107704.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp4.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"
          "107705.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp5:mc12_8TeV.107705.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp5.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1328/"

        )

. ${PWD}/submit_presel.sh

