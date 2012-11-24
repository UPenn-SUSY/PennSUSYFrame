#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='data'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='data_12_8TeV.Egamma'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
ds_list=( "periodA:group.phys-susy.data12_8TeV.periodA.physics_Egamma.PhysCont.NTUP_SUSYSKIM.t0pro13_v01_p1181/"
          "periodB1:group.phys-susy.data12_8TeV.periodB1.physics_Egamma.PhysCont.NTUP_SUSYSKIM.t0pro13_v01_p1181/"
          "periodB2:group.phys-susy.data12_8TeV.periodB2.physics_Egamma.PhysCont.NTUP_SUSYSKIM.t0pro13_v01_p1181/"
          "periodB3:group.phys-susy.data12_8TeV.periodB3.physics_Egamma.PhysCont.NTUP_SUSYSKIM.t0pro13_v01_p1181/"
          "periodB4:group.phys-susy.data12_8TeV.periodB4.physics_Egamma.PhysCont.NTUP_SUSYSKIM.t0pro13_v01_p1181/"
          "periodB5:group.phys-susy.data12_8TeV.periodB5.physics_Egamma.PhysCont.NTUP_SUSYSKIM.t0pro13_v01_p1181/"
          "periodB6:group.phys-susy.data12_8TeV.periodB6.physics_Egamma.PhysCont.NTUP_SUSYSKIM.t0pro13_v01_p1181/"
          "periodB7:group.phys-susy.data12_8TeV.periodB7.physics_Egamma.PhysCont.NTUP_SUSYSKIM.t0pro13_v01_p1181/"
          "periodB8:group.phys-susy.data12_8TeV.periodB8.physics_Egamma.PhysCont.NTUP_SUSYSKIM.t0pro13_v01_p1181/"
          "periodB9:group.phys-susy.data12_8TeV.periodB9.physics_Egamma.PhysCont.NTUP_SUSYSKIM.t0pro13_v01_p1181/"
          "periodB10:group.phys-susy.data12_8TeV.periodB10.physics_Egamma.PhysCont.NTUP_SUSYSKIM.t0pro13_v01_p1181/"
          "periodB11:group.phys-susy.data12_8TeV.periodB11.physics_Egamma.PhysCont.NTUP_SUSYSKIM.t0pro13_v01_p1181/"
          "periodB12:group.phys-susy.data12_8TeV.periodB12.physics_Egamma.PhysCont.NTUP_SUSYSKIM.t0pro13_v01_p1181/"
          "periodB13:group.phys-susy.data12_8TeV.periodB13.physics_Egamma.PhysCont.NTUP_SUSYSKIM.t0pro13_v01_p1181/"
          "periodB14:group.phys-susy.data12_8TeV.periodB14.physics_Egamma.PhysCont.NTUP_SUSYSKIM.t0pro13_v01_p1181/"
          "periodC:group.phys-susy.data12_8TeV.periodC.physics_Egamma.PhysCont.NTUP_SUSY.t0pro13_v01_p1181_p1182/"
          "periodD:group.phys-susy.data12_8TeV.periodD.physics_Egamma.PhysCont.NTUP_SUSY.t0pro13_v01_p1181_p1182/"
          "periodE:group.phys-susy.data12_8TeV.periodE.physics_Egamma.PhysCont.NTUP_SUSY.t0pro13_v01_p1181_p1182/"
        )

. ${PWD}/submit_presel.sh
