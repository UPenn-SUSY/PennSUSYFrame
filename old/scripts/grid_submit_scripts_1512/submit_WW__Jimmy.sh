#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.WW__Jimmy'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list 
ds_list=(
          # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    "169473.gg2wwJimmy_AUET2CT10_WpWmenutaunu:mc12_8TeV.169473.gg2wwJimmy_AUET2CT10_WpWmenutaunu.merge.NTUP_SUSY.e1723_s1581_s1586_r3658_r3549_p1512/"
    "169478.gg2wwJimmy_AUET2CT10_WpWmtaunuenu:mc12_8TeV.169478.gg2wwJimmy_AUET2CT10_WpWmtaunuenu.merge.NTUP_SUSY.e1723_s1581_s1586_r3658_r3549_p1512/"
    "169474.gg2wwJimmy_AUET2CT10_WpWmmunumunu:mc12_8TeV.169474.gg2wwJimmy_AUET2CT10_WpWmmunumunu.merge.NTUP_SUSY.e1723_s1581_s1586_r3658_r3549_p1512/"
    "169477.gg2wwJimmy_AUET2CT10_WpWmtaunutaunu:mc12_8TeV.169477.gg2wwJimmy_AUET2CT10_WpWmtaunutaunu.merge.NTUP_SUSY.e1723_s1581_s1586_r3658_r3549_p1512/"
    "169476.gg2wwJimmy_AUET2CT10_WpWmmunutaunu:mc12_8TeV.169476.gg2wwJimmy_AUET2CT10_WpWmmunutaunu.merge.NTUP_SUSY.e1723_s1581_s1586_r3658_r3549_p1512/"
    "169472.gg2wwJimmy_AUET2CT10_WpWmenumunu:mc12_8TeV.169472.gg2wwJimmy_AUET2CT10_WpWmenumunu.merge.NTUP_SUSY.e1723_s1581_s1586_r3658_r3549_p1512/"
    "169479.gg2wwJimmy_AUET2CT10_WpWmtaunumunu:mc12_8TeV.169479.gg2wwJimmy_AUET2CT10_WpWmtaunumunu.merge.NTUP_SUSY.e1723_s1581_s1586_r3658_r3549_p1512/"
    "169475.gg2wwJimmy_AUET2CT10_WpWmmunuenu:mc12_8TeV.169475.gg2wwJimmy_AUET2CT10_WpWmmunuenu.merge.NTUP_SUSY.e1723_s1581_s1586_r3658_r3549_p1512/"
    "169471.gg2wwJimmy_AUET2CT10_WpWmenuenu:mc12_8TeV.169471.gg2wwJimmy_AUET2CT10_WpWmenuenu.merge.NTUP_SUSY.e1723_s1581_s1586_r3658_r3549_p1512/"
        )

. ${PWD}/submit_cutflow.sh
