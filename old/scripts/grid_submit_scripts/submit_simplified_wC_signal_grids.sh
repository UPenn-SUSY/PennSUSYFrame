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
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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
          "176558.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_50:mc12_8TeV.176558.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_50.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1328/"
          "176559.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_51:mc12_8TeV.176559.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_51.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1328/"
          "176560.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_52:mc12_8TeV.176560.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_52.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1328/"
          "176561.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_53:mc12_8TeV.176561.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_53.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1328/"
          "176562.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_54:mc12_8TeV.176562.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_54.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1328/"
          "176563.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_55:mc12_8TeV.176563.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_55.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1328/"
          "176564.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_56:mc12_8TeV.176564.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_56.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1328/"
          "176565.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_57:mc12_8TeV.176565.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_57.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1328/"
          "176566.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_58:mc12_8TeV.176566.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_58.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1328/"
          "176567.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_59:mc12_8TeV.176567.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_59.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1328/"
          "176568.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_60:mc12_8TeV.176568.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_60.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1328/"
          "176569.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_61:mc12_8TeV.176569.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_61.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1328/"
          "176570.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_62:mc12_8TeV.176570.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_62.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1328/"
          "176571.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_63:mc12_8TeV.176571.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_63.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1328/"
          "176572.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_64:mc12_8TeV.176572.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_64.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1328/"
          "176573.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_65:mc12_8TeV.176573.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_slep_noWcasc_65.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1328/"
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          "164374.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_1:mc12_8TeV.164374.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_1.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164375.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_2:mc12_8TeV.164375.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_2.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164376.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_3:mc12_8TeV.164376.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_3.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164377.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_4:mc12_8TeV.164377.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_4.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164378.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_5:mc12_8TeV.164378.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_5.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164379.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_6:mc12_8TeV.164379.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_6.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164380.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_7:mc12_8TeV.164380.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_7.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164381.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_8:mc12_8TeV.164381.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_8.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164382.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_9:mc12_8TeV.164382.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_9.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164383.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_10:mc12_8TeV.164383.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_10.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164384.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_11:mc12_8TeV.164384.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_11.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164385.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_12:mc12_8TeV.164385.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_12.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164386.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_13:mc12_8TeV.164386.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_13.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164387.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_14:mc12_8TeV.164387.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_14.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164388.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_15:mc12_8TeV.164388.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_15.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164389.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_16:mc12_8TeV.164389.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_16.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164390.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_17:mc12_8TeV.164390.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_17.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164391.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_18:mc12_8TeV.164391.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_18.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164392.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_19:mc12_8TeV.164392.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_19.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164393.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_20:mc12_8TeV.164393.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_20.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164394.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_21:mc12_8TeV.164394.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_21.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164395.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_22:mc12_8TeV.164395.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_22.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164396.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_23:mc12_8TeV.164396.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_23.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164397.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_24:mc12_8TeV.164397.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_24.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164398.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_25:mc12_8TeV.164398.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_25.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164399.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_26:mc12_8TeV.164399.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_26.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164400.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_27:mc12_8TeV.164400.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_27.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164401.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_28:mc12_8TeV.164401.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_28.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164402.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_29:mc12_8TeV.164402.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_29.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164403.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_30:mc12_8TeV.164403.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_30.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164404.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_31:mc12_8TeV.164404.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_31.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164405.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_32:mc12_8TeV.164405.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_32.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164406.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_33:mc12_8TeV.164406.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_33.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164407.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_34:mc12_8TeV.164407.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_34.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164408.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_35:mc12_8TeV.164408.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_35.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164409.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_36:mc12_8TeV.164409.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_36.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164410.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_37:mc12_8TeV.164410.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_37.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164411.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_38:mc12_8TeV.164411.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_38.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164412.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_39:mc12_8TeV.164412.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_39.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164413.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_40:mc12_8TeV.164413.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_40.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164414.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_41:mc12_8TeV.164414.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_41.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164415.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_42:mc12_8TeV.164415.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_42.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164416.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_43:mc12_8TeV.164416.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_43.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164417.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_44:mc12_8TeV.164417.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_44.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164418.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_45:mc12_8TeV.164418.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_45.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164419.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_46:mc12_8TeV.164419.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_46.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164420.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_47:mc12_8TeV.164420.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_47.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164421.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_48:mc12_8TeV.164421.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_48.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164422.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_49:mc12_8TeV.164422.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_49.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
          "164423.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_50:mc12_8TeV.164423.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wC_noslep_lepW_50.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1328/"
        )

. ${PWD}/submit_cutflow.sh