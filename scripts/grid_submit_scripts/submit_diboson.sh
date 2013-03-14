#!/bin/bash

# =========================
# = Define some variables =
# =========================
DATA_MC='mc'
STREAM='egamma'
SIM_TYPE='fullsim'
OUT_DS_PREFIX='mc12_8TeV.diboson'
EXT_FILES=''

# ==============================
# = define list of input files =
# ==============================
# mc12 list 
ds_list=(
          "126892.Sherpa_CT10_llnunu_WW:mc12_8TeV.126892.Sherpa_CT10_llnunu_WW.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1328/"
          "126893.Sherpa_CT10_lllnu_WZ:mc12_8TeV.126893.Sherpa_CT10_lllnu_WZ.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1328/"
          "126894.Sherpa_CT10_llll_ZZ:mc12_8TeV.126894.Sherpa_CT10_llll_ZZ.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1328/"
          "126895.Sherpa_CT10_llnunu_ZZ:mc12_8TeV.126895.Sherpa_CT10_llnunu_ZZ.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1328/"
          "126928.PowhegPythia8_AU2CT10_WpWm_ee:mc12_8TeV.126928.PowhegPythia8_AU2CT10_WpWm_ee.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126929.PowhegPythia8_AU2CT10_WpWm_me:mc12_8TeV.126929.PowhegPythia8_AU2CT10_WpWm_me.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126930.PowhegPythia8_AU2CT10_WpWm_te:mc12_8TeV.126930.PowhegPythia8_AU2CT10_WpWm_te.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126931.PowhegPythia8_AU2CT10_WpWm_em:mc12_8TeV.126931.PowhegPythia8_AU2CT10_WpWm_em.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126932.PowhegPythia8_AU2CT10_WpWm_mm:mc12_8TeV.126932.PowhegPythia8_AU2CT10_WpWm_mm.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126933.PowhegPythia8_AU2CT10_WpWm_tm:mc12_8TeV.126933.PowhegPythia8_AU2CT10_WpWm_tm.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126934.PowhegPythia8_AU2CT10_WpWm_et:mc12_8TeV.126934.PowhegPythia8_AU2CT10_WpWm_et.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126935.PowhegPythia8_AU2CT10_WpWm_mt:mc12_8TeV.126935.PowhegPythia8_AU2CT10_WpWm_mt.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126936.PowhegPythia8_AU2CT10_WpWm_tt:mc12_8TeV.126936.PowhegPythia8_AU2CT10_WpWm_tt.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126937.PowhegPythia8_AU2CT10_ZZ_4e_mll4_2pt5:mc12_8TeV.126937.PowhegPythia8_AU2CT10_ZZ_4e_mll4_2pt5.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126938.PowhegPythia8_AU2CT10_ZZ_2e2mu_mll4_2pt5:mc12_8TeV.126938.PowhegPythia8_AU2CT10_ZZ_2e2mu_mll4_2pt5.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126939.PowhegPythia8_AU2CT10_ZZ_2e2tau_mll4_2pt5:mc12_8TeV.126939.PowhegPythia8_AU2CT10_ZZ_2e2tau_mll4_2pt5.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126940.PowhegPythia8_AU2CT10_ZZ_4mu_mll4_2pt5:mc12_8TeV.126940.PowhegPythia8_AU2CT10_ZZ_4mu_mll4_2pt5.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126941.PowhegPythia8_AU2CT10_ZZ_2mu2tau_mll4_2pt5:mc12_8TeV.126941.PowhegPythia8_AU2CT10_ZZ_2mu2tau_mll4_2pt5.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126942.PowhegPythia8_AU2CT10_ZZ_4tau_mll4_2pt5:mc12_8TeV.126942.PowhegPythia8_AU2CT10_ZZ_4tau_mll4_2pt5.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126949.PowhegPythia8_AU2CT10_ZZllnunu_ee_mll4:mc12_8TeV.126949.PowhegPythia8_AU2CT10_ZZllnunu_ee_mll4.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126950.PowhegPythia8_AU2CT10_ZZllnunu_mm_mll4:mc12_8TeV.126950.PowhegPythia8_AU2CT10_ZZllnunu_mm_mll4.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "126951.PowhegPythia8_AU2CT10_ZZllnunu_tt_mll4:mc12_8TeV.126951.PowhegPythia8_AU2CT10_ZZllnunu_tt_mll4.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1328/"
          "129477.PowhegPythia8_AU2CT10_WZ_Wm11Z11_mll0p250d0_2LeptonFilter5:mc12_8TeV.129477.PowhegPythia8_AU2CT10_WZ_Wm11Z11_mll0p250d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1328/"
          "129478.PowhegPythia8_AU2CT10_WZ_Wm11Z13_mll0p4614d0_2LeptonFilter5:mc12_8TeV.129478.PowhegPythia8_AU2CT10_WZ_Wm11Z13_mll0p4614d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1328/"
          "129479.PowhegPythia8_AU2CT10_WZ_Wm11Z15_mll3p804d0_2LeptonFilter5:mc12_8TeV.129479.PowhegPythia8_AU2CT10_WZ_Wm11Z15_mll3p804d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1328/"
          "129480.PowhegPythia8_AU2CT10_WZ_Wm13Z11_mll0p250d0_2LeptonFilter5:mc12_8TeV.129480.PowhegPythia8_AU2CT10_WZ_Wm13Z11_mll0p250d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1328/"
          "129481.PowhegPythia8_AU2CT10_WZ_Wm13Z13_mll0p4614d0_2LeptonFilter5:mc12_8TeV.129481.PowhegPythia8_AU2CT10_WZ_Wm13Z13_mll0p4614d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1328/"
          "129482.PowhegPythia8_AU2CT10_WZ_Wm13Z15_mll3p804d0_2LeptonFilter5:mc12_8TeV.129482.PowhegPythia8_AU2CT10_WZ_Wm13Z15_mll3p804d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1328/"
          "129483.PowhegPythia8_AU2CT10_WZ_Wm15Z11_mll0p250d0_2LeptonFilter5:mc12_8TeV.129483.PowhegPythia8_AU2CT10_WZ_Wm15Z11_mll0p250d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1328/"
          "129484.PowhegPythia8_AU2CT10_WZ_Wm15Z13_mll0p4614d0_2LeptonFilter5:mc12_8TeV.129484.PowhegPythia8_AU2CT10_WZ_Wm15Z13_mll0p4614d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1328/"
          "129485.PowhegPythia8_AU2CT10_WZ_Wm15Z15_mll3p804d0_2LeptonFilter5:mc12_8TeV.129485.PowhegPythia8_AU2CT10_WZ_Wm15Z15_mll3p804d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1328/"
          "129486.PowhegPythia8_AU2CT10_WZ_W11Z11_mll0p250d0_2LeptonFilter5:mc12_8TeV.129486.PowhegPythia8_AU2CT10_WZ_W11Z11_mll0p250d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1328/"
          "129487.PowhegPythia8_AU2CT10_WZ_W11Z13_mll0p4614d0_2LeptonFilter5:mc12_8TeV.129487.PowhegPythia8_AU2CT10_WZ_W11Z13_mll0p4614d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1328/"
          "129488.PowhegPythia8_AU2CT10_WZ_W11Z15_mll3p804d0_2LeptonFilter5:mc12_8TeV.129488.PowhegPythia8_AU2CT10_WZ_W11Z15_mll3p804d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1328/"
          "129489.PowhegPythia8_AU2CT10_WZ_W13Z11_mll0p250d0_2LeptonFilter5:mc12_8TeV.129489.PowhegPythia8_AU2CT10_WZ_W13Z11_mll0p250d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1328/"
          "129490.PowhegPythia8_AU2CT10_WZ_W13Z13_mll0p4614d0_2LeptonFilter5:mc12_8TeV.129490.PowhegPythia8_AU2CT10_WZ_W13Z13_mll0p4614d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1328/"
          "129491.PowhegPythia8_AU2CT10_WZ_W13Z15_mll3p804d0_2LeptonFilter5:mc12_8TeV.129491.PowhegPythia8_AU2CT10_WZ_W13Z15_mll3p804d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1328/"
          "129492.PowhegPythia8_AU2CT10_WZ_W15Z11_mll0p250d0_2LeptonFilter5:mc12_8TeV.129492.PowhegPythia8_AU2CT10_WZ_W15Z11_mll0p250d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1328/"
          "129493.PowhegPythia8_AU2CT10_WZ_W15Z13_mll0p4614d0_2LeptonFilter5:mc12_8TeV.129493.PowhegPythia8_AU2CT10_WZ_W15Z13_mll0p4614d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1328/"
          "129494.PowhegPythia8_AU2CT10_WZ_W15Z15_mll3p804d0_2LeptonFilter5:mc12_8TeV.129494.PowhegPythia8_AU2CT10_WZ_W15Z15_mll3p804d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1328/"
          "129501.PowhegPythia8_AU2CT10_DYee_20M60:mc12_8TeV.129501.PowhegPythia8_AU2CT10_DYee_20M60.merge.NTUP_SUSY.e1248_s1469_s1470_r3542_r3549_p1328/"
          "129521.PowhegPythia8_AU2CT10_DYmumu_20M60:mc12_8TeV.129521.PowhegPythia8_AU2CT10_DYmumu_20M60.merge.NTUP_SUSY.e1248_s1469_s1470_r3542_r3549_p1328/"
        )

. ${PWD}/submit_cutflow.sh
