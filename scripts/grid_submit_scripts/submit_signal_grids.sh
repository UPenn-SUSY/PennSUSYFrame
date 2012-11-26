#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.signal'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list 
ds_list=( 
          "144871.simplifiedModel_wA_slep_noWcascade_5.:mc12_8TeV.144871.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_5.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144873.simplifiedModel_wA_slep_noWcascade_7.:mc12_8TeV.144873.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_7.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144874.simplifiedModel_wA_slep_noWcascade_8.:mc12_8TeV.144874.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_8.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144876.simplifiedModel_wA_slep_noWcascade_10:mc12_8TeV.144876.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_10.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144877.simplifiedModel_wA_slep_noWcascade_11:mc12_8TeV.144877.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_11.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144879.simplifiedModel_wA_slep_noWcascade_13:mc12_8TeV.144879.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_13.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144880.simplifiedModel_wA_slep_noWcascade_14:mc12_8TeV.144880.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_14.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144881.simplifiedModel_wA_slep_noWcascade_15:mc12_8TeV.144881.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_15.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144883.simplifiedModel_wA_slep_noWcascade_17:mc12_8TeV.144883.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_17.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144884.simplifiedModel_wA_slep_noWcascade_18:mc12_8TeV.144884.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_18.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144885.simplifiedModel_wA_slep_noWcascade_19:mc12_8TeV.144885.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_19.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144886.simplifiedModel_wA_slep_noWcascade_20:mc12_8TeV.144886.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_20.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144888.simplifiedModel_wA_slep_noWcascade_22:mc12_8TeV.144888.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_22.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144889.simplifiedModel_wA_slep_noWcascade_23:mc12_8TeV.144889.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_23.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144890.simplifiedModel_wA_slep_noWcascade_24:mc12_8TeV.144890.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_24.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144891.simplifiedModel_wA_slep_noWcascade_25:mc12_8TeV.144891.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_25.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144892.simplifiedModel_wA_slep_noWcascade_26:mc12_8TeV.144892.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_26.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144894.simplifiedModel_wA_slep_noWcascade_28:mc12_8TeV.144894.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_28.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144895.simplifiedModel_wA_slep_noWcascade_29:mc12_8TeV.144895.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_29.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144896.simplifiedModel_wA_slep_noWcascade_30:mc12_8TeV.144896.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_30.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144902.simplifiedModel_wC_slep_noWcascade_5.:mc12_8TeV.144902.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_5.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144904.simplifiedModel_wC_slep_noWcascade_7.:mc12_8TeV.144904.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_7.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144905.simplifiedModel_wC_slep_noWcascade_8.:mc12_8TeV.144905.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_8.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144907.simplifiedModel_wC_slep_noWcascade_10:mc12_8TeV.144907.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_10.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144908.simplifiedModel_wC_slep_noWcascade_11:mc12_8TeV.144908.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_11.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144910.simplifiedModel_wC_slep_noWcascade_13:mc12_8TeV.144910.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_13.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144911.simplifiedModel_wC_slep_noWcascade_14:mc12_8TeV.144911.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_14.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144912.simplifiedModel_wC_slep_noWcascade_15:mc12_8TeV.144912.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_15.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144914.simplifiedModel_wC_slep_noWcascade_17:mc12_8TeV.144914.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_17.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144915.simplifiedModel_wC_slep_noWcascade_18:mc12_8TeV.144915.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_18.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144916.simplifiedModel_wC_slep_noWcascade_19:mc12_8TeV.144916.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_19.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144917.simplifiedModel_wC_slep_noWcascade_20:mc12_8TeV.144917.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_20.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144919.simplifiedModel_wC_slep_noWcascade_22:mc12_8TeV.144919.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_22.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144920.simplifiedModel_wC_slep_noWcascade_23:mc12_8TeV.144920.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_23.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144921.simplifiedModel_wC_slep_noWcascade_24:mc12_8TeV.144921.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_24.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144922.simplifiedModel_wC_slep_noWcascade_25:mc12_8TeV.144922.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_25.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144923.simplifiedModel_wC_slep_noWcascade_26:mc12_8TeV.144923.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_26.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144925.simplifiedModel_wC_slep_noWcascade_28:mc12_8TeV.144925.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_28.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144926.simplifiedModel_wC_slep_noWcascade_29:mc12_8TeV.144926.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_29.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "144927.simplifiedModel_wC_slep_noWcascade_30:mc12_8TeV.144927.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_30.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157461.simplifiedModel_wA_slep_noWcascade_32:mc12_8TeV.157461.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_32.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157464.simplifiedModel_wA_slep_noWcascade_35:mc12_8TeV.157464.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_35.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157467.simplifiedModel_wA_slep_noWcascade_38:mc12_8TeV.157467.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_38.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157954.simplifiedModel_wA_slep_noWcascade_39:mc12_8TeV.157954.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_39.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157955.simplifiedModel_wA_slep_noWcascade_40:mc12_8TeV.157955.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_40.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157956.simplifiedModel_wA_slep_noWcascade_41:mc12_8TeV.157956.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_41.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157957.simplifiedModel_wA_slep_noWcascade_42:mc12_8TeV.157957.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_42.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157958.simplifiedModel_wA_slep_noWcascade_43:mc12_8TeV.157958.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_43.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157959.simplifiedModel_wA_slep_noWcascade_44:mc12_8TeV.157959.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_44.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157960.simplifiedModel_wA_slep_noWcascade_45:mc12_8TeV.157960.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_45.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157961.simplifiedModel_wA_slep_noWcascade_46:mc12_8TeV.157961.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_46.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157962.simplifiedModel_wA_slep_noWcascade_47:mc12_8TeV.157962.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_47.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157963.simplifiedModel_wA_slep_noWcascade_48:mc12_8TeV.157963.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_48.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157964.simplifiedModel_wA_slep_noWcascade_49:mc12_8TeV.157964.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_49.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157965.simplifiedModel_wA_slep_noWcascade_50:mc12_8TeV.157965.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_50.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157966.simplifiedModel_wA_slep_noWcascade_51:mc12_8TeV.157966.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_51.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157967.simplifiedModel_wA_slep_noWcascade_52:mc12_8TeV.157967.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_52.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157968.simplifiedModel_wA_slep_noWcascade_53:mc12_8TeV.157968.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_53.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157969.simplifiedModel_wC_slep_noWcascade_32:mc12_8TeV.157969.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_32.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157970.simplifiedModel_wC_slep_noWcascade_33:mc12_8TeV.157970.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_33.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157971.simplifiedModel_wC_slep_noWcascade_34:mc12_8TeV.157971.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_34.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157972.simplifiedModel_wC_slep_noWcascade_35:mc12_8TeV.157972.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_35.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157973.simplifiedModel_wC_slep_noWcascade_36:mc12_8TeV.157973.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_36.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157974.simplifiedModel_wC_slep_noWcascade_37:mc12_8TeV.157974.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_37.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157975.simplifiedModel_wC_slep_noWcascade_38:mc12_8TeV.157975.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_38.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157976.simplifiedModel_wC_slep_noWcascade_39:mc12_8TeV.157976.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_39.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157977.simplifiedModel_wC_slep_noWcascade_40:mc12_8TeV.157977.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_40.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157978.simplifiedModel_wC_slep_noWcascade_41:mc12_8TeV.157978.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_41.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157979.simplifiedModel_wC_slep_noWcascade_42:mc12_8TeV.157979.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_42.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157980.simplifiedModel_wC_slep_noWcascade_43:mc12_8TeV.157980.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_43.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157981.simplifiedModel_wC_slep_noWcascade_44:mc12_8TeV.157981.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_44.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157982.simplifiedModel_wC_slep_noWcascade_45:mc12_8TeV.157982.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_45.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157983.simplifiedModel_wC_slep_noWcascade_46:mc12_8TeV.157983.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_46.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157984.simplifiedModel_wC_slep_noWcascade_47:mc12_8TeV.157984.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_47.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157985.simplifiedModel_wC_slep_noWcascade_48:mc12_8TeV.157985.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_48.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
          "157986.simplifiedModel_wC_slep_noWcascade_49:mc12_8TeV.157986.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcascade_49.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1181/"
        )

. ${PWD}/submit_presel.sh
