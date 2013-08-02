#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='data'
STREAM='muon'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='data_12_8TeV.Muon'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
ds_list=( "periodA:group.phys-susy.data12_8TeV.periodA.physics_Muons.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/"
          "periodB:group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/"
          "periodC:group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/"
          "periodD:group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/"
          "periodE:group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/"
          "periodG:group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/"
          "periodH:group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/"
          "periodI:group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.NTUP_SUSYSKIM.t0pro14_v01_p1542/"
          "periodJ:group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.NTUP_SUSYSKIM.t0pro14_v01_p1542/"
          "periodL:group.phys-susy.data12_8TeV.periodL.physics_Muons.PhysCont.NTUP_SUSYSKIM.t0pro14_v01_p1542/"
        )

. ${PWD}/submit_cutflow.sh
