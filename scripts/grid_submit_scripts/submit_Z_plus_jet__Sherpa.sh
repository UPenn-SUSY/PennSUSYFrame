#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='atlfast'
OUT_DS_PREFIX='mc12_8TeV.Z_plus_jet__Sherpa'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          "146820.Sherpa_CT10_ZeeLightJets:mc12_8TeV.146820.Sherpa_CT10_ZeeLightJets.merge.NTUP_SUSY.e1434_a159_a171_r3549_p1181/"
          "146821.Sherpa_CT10_ZmumuLightJets:mc12_8TeV.146821.Sherpa_CT10_ZmumuLightJets.merge.NTUP_SUSY.e1434_a159_a171_r3549_p1181/"
          "146822.Sherpa_CT10_ZtautauLightJets:mc12_8TeV.146822.Sherpa_CT10_ZtautauLightJets.merge.NTUP_SUSY.e1434_a159_a171_r3549_p1181/"
          "128975.Sherpa_CT10_ZeeHeavyJets:mc12_8TeV.128975.Sherpa_CT10_ZeeHeavyJets.merge.NTUP_SUSY.e1434_a159_a171_r3549_p1181/"
          "128976.Sherpa_CT10_ZmumuHeavyJets:mc12_8TeV.128976.Sherpa_CT10_ZmumuHeavyJets.merge.NTUP_SUSY.e1434_a159_a171_r3549_p1181/"
          "128977.Sherpa_CT10_ZtautauHeavyJets:mc12_8TeV.128977.Sherpa_CT10_ZtautauHeavyJets.merge.NTUP_SUSY.e1434_a159_a171_r3549_p1181/"
        )

. ${PWD}/submit_cutflow.sh
