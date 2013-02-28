#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.signal_simplified'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list 
ds_list=( 
          "144871.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_5:mc12_8TeV.144871.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_5.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144873.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_7:mc12_8TeV.144873.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_7.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144874.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_8:mc12_8TeV.144874.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_8.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144876.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_10:mc12_8TeV.144876.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_10.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144877.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_11:mc12_8TeV.144877.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_11.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144879.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_13:mc12_8TeV.144879.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_13.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144880.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_14:mc12_8TeV.144880.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_14.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144881.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_15:mc12_8TeV.144881.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_15.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144883.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_17:mc12_8TeV.144883.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_17.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144884.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_18:mc12_8TeV.144884.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_18.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144885.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_19:mc12_8TeV.144885.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_19.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144886.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_20:mc12_8TeV.144886.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_20.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144888.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_22:mc12_8TeV.144888.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_22.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144889.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_23:mc12_8TeV.144889.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_23.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144890.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_24:mc12_8TeV.144890.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_24.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144891.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_25:mc12_8TeV.144891.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_25.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144892.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_26:mc12_8TeV.144892.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_26.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144894.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_28:mc12_8TeV.144894.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_28.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144895.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_29:mc12_8TeV.144895.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_29.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144896.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_30:mc12_8TeV.144896.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_30.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157461.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_32:mc12_8TeV.157461.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_32.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157464.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_35:mc12_8TeV.157464.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_35.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157467.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_38:mc12_8TeV.157467.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_38.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157954.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_39:mc12_8TeV.157954.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_39.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157955.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_40:mc12_8TeV.157955.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_40.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157956.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_41:mc12_8TeV.157956.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_41.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157957.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_42:mc12_8TeV.157957.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_42.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157958.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_43:mc12_8TeV.157958.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_43.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157959.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_44:mc12_8TeV.157959.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_44.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157960.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_45:mc12_8TeV.157960.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_45.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157961.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_46:mc12_8TeV.157961.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_46.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157962.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_47:mc12_8TeV.157962.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_47.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157963.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_48:mc12_8TeV.157963.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_48.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157964.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_49:mc12_8TeV.157964.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_49.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157965.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_50:mc12_8TeV.157965.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_50.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157966.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_51:mc12_8TeV.157966.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_51.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157967.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_52:mc12_8TeV.157967.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_52.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157968.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_53:mc12_8TeV.157968.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_53.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144902.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_5:mc12_8TeV.144902.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_5.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144904.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_7:mc12_8TeV.144904.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_7.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144905.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_8:mc12_8TeV.144905.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_8.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144907.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_10:mc12_8TeV.144907.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_10.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144908.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_11:mc12_8TeV.144908.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_11.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144910.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_13:mc12_8TeV.144910.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_13.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144911.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_14:mc12_8TeV.144911.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_14.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144912.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_15:mc12_8TeV.144912.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_15.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144914.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_17:mc12_8TeV.144914.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_17.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144915.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_18:mc12_8TeV.144915.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_18.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144916.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_19:mc12_8TeV.144916.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_19.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144917.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_20:mc12_8TeV.144917.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_20.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144919.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_22:mc12_8TeV.144919.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_22.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144920.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_23:mc12_8TeV.144920.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_23.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144921.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_24:mc12_8TeV.144921.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_24.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144922.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_25:mc12_8TeV.144922.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_25.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144923.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_26:mc12_8TeV.144923.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_26.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144925.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_28:mc12_8TeV.144925.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_28.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144926.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_29:mc12_8TeV.144926.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_29.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "144927.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_30:mc12_8TeV.144927.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_30.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157969.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_32:mc12_8TeV.157969.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_32.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157970.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_33:mc12_8TeV.157970.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_33.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157971.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_34:mc12_8TeV.157971.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_34.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157972.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_35:mc12_8TeV.157972.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_35.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157973.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_36:mc12_8TeV.157973.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_36.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157974.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_37:mc12_8TeV.157974.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_37.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157975.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_38:mc12_8TeV.157975.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_38.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157976.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_39:mc12_8TeV.157976.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_39.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157977.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_40:mc12_8TeV.157977.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_40.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157978.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_41:mc12_8TeV.157978.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_41.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157979.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_42:mc12_8TeV.157979.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_42.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157980.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_43:mc12_8TeV.157980.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_43.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157981.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_44:mc12_8TeV.157981.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_44.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157982.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_45:mc12_8TeV.157982.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_45.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157983.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_46:mc12_8TeV.157983.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_46.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157984.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_47:mc12_8TeV.157984.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_47.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157985.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_48:mc12_8TeV.157985.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_48.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
          "157986.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_49:mc12_8TeV.157986.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_49.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1328/"
        )

. ${PWD}/submit_cutflow.sh
