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
ds_list=(
    
    
    
    "117650.AlpgenPythia_P2011C_ZeeNp0:mc12_8TeV.117650.AlpgenPythia_P2011C_ZeeNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "117651.AlpgenPythia_P2011C_ZeeNp1:mc12_8TeV.117651.AlpgenPythia_P2011C_ZeeNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "117652.AlpgenPythia_P2011C_ZeeNp2:mc12_8TeV.117652.AlpgenPythia_P2011C_ZeeNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "117653.AlpgenPythia_P2011C_ZeeNp3:mc12_8TeV.117653.AlpgenPythia_P2011C_ZeeNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "117654.AlpgenPythia_P2011C_ZeeNp4:mc12_8TeV.117654.AlpgenPythia_P2011C_ZeeNp4.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "117655.AlpgenPythia_P2011C_ZeeNp5:mc12_8TeV.117655.AlpgenPythia_P2011C_ZeeNp5.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    
    "117660.AlpgenPythia_P2011C_ZmumuNp0:mc12_8TeV.117660.AlpgenPythia_P2011C_ZmumuNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "117661.AlpgenPythia_P2011C_ZmumuNp1:mc12_8TeV.117661.AlpgenPythia_P2011C_ZmumuNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "117662.AlpgenPythia_P2011C_ZmumuNp2:mc12_8TeV.117662.AlpgenPythia_P2011C_ZmumuNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "117663.AlpgenPythia_P2011C_ZmumuNp3:mc12_8TeV.117663.AlpgenPythia_P2011C_ZmumuNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "117664.AlpgenPythia_P2011C_ZmumuNp4:mc12_8TeV.117664.AlpgenPythia_P2011C_ZmumuNp4.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "117665.AlpgenPythia_P2011C_ZmumuNp5:mc12_8TeV.117665.AlpgenPythia_P2011C_ZmumuNp5.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    
    "117670.AlpgenPythia_P2011C_ZtautauNp0:mc12_8TeV.117670.AlpgenPythia_P2011C_ZtautauNp0.merge.NTUP_SUSY.e1711_s1581_s1586_r3658_r3549_p1512/"
    "117671.AlpgenPythia_P2011C_ZtautauNp1:mc12_8TeV.117671.AlpgenPythia_P2011C_ZtautauNp1.merge.NTUP_SUSY.e1711_s1581_s1586_r3658_r3549_p1512/"
    "117672.AlpgenPythia_P2011C_ZtautauNp2:mc12_8TeV.117672.AlpgenPythia_P2011C_ZtautauNp2.merge.NTUP_SUSY.e1711_s1581_s1586_r3658_r3549_p1512/"
    "117673.AlpgenPythia_P2011C_ZtautauNp3:mc12_8TeV.117673.AlpgenPythia_P2011C_ZtautauNp3.merge.NTUP_SUSY.e1711_s1581_s1586_r3658_r3549_p1512/"
    "117674.AlpgenPythia_P2011C_ZtautauNp4:mc12_8TeV.117674.AlpgenPythia_P2011C_ZtautauNp4.merge.NTUP_SUSY.e1711_s1581_s1586_r3658_r3549_p1512/"
    "117675.AlpgenPythia_P2011C_ZtautauNp5:mc12_8TeV.117675.AlpgenPythia_P2011C_ZtautauNp5.merge.NTUP_SUSY.e1711_s1581_s1586_r3658_r3549_p1512/"
    

    "110805.AlpgenPythia_P2011C_ZeeccNp0:mc12_8TeV.110805.AlpgenPythia_P2011C_ZeeccNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "110806.AlpgenPythia_P2011C_ZeeccNp1:mc12_8TeV.110806.AlpgenPythia_P2011C_ZeeccNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "110807.AlpgenPythia_P2011C_ZeeccNp2:mc12_8TeV.110807.AlpgenPythia_P2011C_ZeeccNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "110808.AlpgenPythia_P2011C_ZeeccNp3:mc12_8TeV.110808.AlpgenPythia_P2011C_ZeeccNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    
    "110809.AlpgenPythia_P2011C_ZmumuccNp0:mc12_8TeV.110809.AlpgenPythia_P2011C_ZmumuccNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "110810.AlpgenPythia_P2011C_ZmumuccNp1:mc12_8TeV.110810.AlpgenPythia_P2011C_ZmumuccNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "110811.AlpgenPythia_P2011C_ZmumuccNp2:mc12_8TeV.110811.AlpgenPythia_P2011C_ZmumuccNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "110812.AlpgenPythia_P2011C_ZmumuccNp3:mc12_8TeV.110812.AlpgenPythia_P2011C_ZmumuccNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    
    "110813.AlpgenPythia_P2011C_ZtautauccNp0:mc12_8TeV.110813.AlpgenPythia_P2011C_ZtautauccNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "110814.AlpgenPythia_P2011C_ZtautauccNp1:mc12_8TeV.110814.AlpgenPythia_P2011C_ZtautauccNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "110815.AlpgenPythia_P2011C_ZtautauccNp2:mc12_8TeV.110815.AlpgenPythia_P2011C_ZtautauccNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "110816.AlpgenPythia_P2011C_ZtautauccNp3:mc12_8TeV.110816.AlpgenPythia_P2011C_ZtautauccNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    
    "110817.AlpgenPythia_P2011C_ZeebbNp0:mc12_8TeV.110817.AlpgenPythia_P2011C_ZeebbNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "110818.AlpgenPythia_P2011C_ZeebbNp1:mc12_8TeV.110818.AlpgenPythia_P2011C_ZeebbNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "110819.AlpgenPythia_P2011C_ZeebbNp2:mc12_8TeV.110819.AlpgenPythia_P2011C_ZeebbNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "110820.AlpgenPythia_P2011C_ZeebbNp3:mc12_8TeV.110820.AlpgenPythia_P2011C_ZeebbNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    
    "110821.AlpgenPythia_P2011C_ZmumubbNp0:mc12_8TeV.110821.AlpgenPythia_P2011C_ZmumubbNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "110822.AlpgenPythia_P2011C_ZmumubbNp1:mc12_8TeV.110822.AlpgenPythia_P2011C_ZmumubbNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "110823.AlpgenPythia_P2011C_ZmumubbNp2:mc12_8TeV.110823.AlpgenPythia_P2011C_ZmumubbNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "110824.AlpgenPythia_P2011C_ZmumubbNp3:mc12_8TeV.110824.AlpgenPythia_P2011C_ZmumubbNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    
    "110825.AlpgenPythia_P2011C_ZtautaubbNp0:mc12_8TeV.110825.AlpgenPythia_P2011C_ZtautaubbNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "110826.AlpgenPythia_P2011C_ZtautaubbNp1:mc12_8TeV.110826.AlpgenPythia_P2011C_ZtautaubbNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "110827.AlpgenPythia_P2011C_ZtautaubbNp2:mc12_8TeV.110827.AlpgenPythia_P2011C_ZtautaubbNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"
    "110828.AlpgenPythia_P2011C_ZtautaubbNp3:mc12_8TeV.110828.AlpgenPythia_P2011C_ZtautaubbNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/"

)

. ${PWD}/submit_cutflow.sh
