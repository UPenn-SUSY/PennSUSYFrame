#!/usr/bin/env python

import os
import stat
import subprocess

# ------------------------------------------------------------------------------
def generateTarBallScript(tnt_tag):
    file_name = './grid_jobs/grid_job_%s__0.sh' % tnt_tag
    out_script = file(file_name, 'w')
    prun_command = """prun \
  --bexec="ls" \
  --exec="ls" \
  --useRootCore \
  --extFile=./RootCore/MultiLep/data/ilumicalc_histograms_EF_2e12Tvh_loose1_200842-215643_grl_v61.root,./RootCore/PileupReweighting/share/mc12ab_defaults.prw.root \
  --outDS="user.bjackson.tar_ball.%(tnt_tag)s/" \
  --outTarBall=submit_tar.%(tnt_tag)s.tar.gz \
  --rootVer=5.34.07 \
  --cmtConfig=x86_64-slc5-gcc43-opt \
  --noSubmit \

""" % {'tnt_tag':tnt_tag}

    # print 'prun_command: %s' % prun_command
    out_script.write(prun_command)
    out_script.close()

    subprocess.call(['chmod', '+x', file_name])
    subprocess.call([file_name], shell=True)

# ------------------------------------------------------------------------------
def generateSubmitScript( in_ds
                        , out_ds_tag
                        , tnt_tag
                        , is_data
                        , is_full_mc
                        , submit_script_number
                        ):
    file_name = './grid_jobs/grid_job_%s__%s.sh' % (tnt_tag, submit_script_number)
    out_script = file(file_name, 'w')

    print 'is_data: %s' % is_data
    print 'is_full_mc: %s' % is_full_mc
    prun_command = """prun \
  --bexec="scripts/GridSubmit/GridBuild.sh" \
  --exec="\source SetupEnvironment.sh ; \
          echo '------------------------------------------------------------------------------------' ; \
          ./scripts/RunTntMaker.py %(is_data)s %(is_full_mc)s %%IN ; \
          echo '------------------------------------------------------------------------------------' ; \
          ls ; " \
  --useRootCore \
  --extFile=./RootCore/MultiLep/data/ilumicalc_histograms_EF_2e12Tvh_loose1_200842-215643_grl_v61.root,./RootCore/PileupReweighting/share/mc12ab_defaults.prw.root \
  --nGBPerJob=MAX \
  --inDS=%(in_ds)s \
  --outDS="user.bjackson.%(out_ds_tag)s.%(tnt_tag)s/" \
  --inTarBall=submit_tar.%(tnt_tag)s.tar.gz \
  --rootVer=5.34.17 \
  --cmtConfig=x86_64-slc6-gcc47-opt \
  --outputs=Tnt.root \
  --excludedSite=ANALY_LRZ,ANALY_GOEGRID,ANALY_RHUL_SL6 \

""" % {'in_ds':in_ds, 'out_ds_tag':out_ds_tag, 'tnt_tag':tnt_tag, 'is_data':is_data, 'is_full_mc':is_full_mc}

  # --rootVer=5.34.07 \
  # --cmtConfig=x86_64-slc5-gcc43-opt \
  # --cmtConfig=x86_64-slc6-gcc48-opt \

    # --nGBPerJob=MAX \
    # --nFilesPerJob=1 \

    # print 'prun command: %s' % prun_command

    out_script.write(prun_command)
    out_script.close()

    subprocess.call(['chmod', '+x', file_name])
    subprocess.call([file_name], shell = True)

# ------------------------------------------------------------------------------
def submitFromList( ds_dict_list, tnt_tag, starting_num):
    job_num = starting_num

    for ddl in ds_dict_list:
        job_num += 1
        generateSubmitScript( in_ds = ddl['ds']
                            , out_ds_tag = ddl['tag']
                            , tnt_tag = tnt_tag
                            , is_data = ddl['is_data']
                            , is_full_mc = ddl['is_full_mc']
                            , submit_script_number = job_num
                            )

    return job_num

# ==============================================================================
if __name__ == '__main__':
    tnt_tag = 'tnt_102'

    # ------------------------------------------------------------------------------
    generateTarBallScript(tnt_tag = tnt_tag)

    # ------------------------------------------------------------------------------
    job_num = 0

    # ------------------------------------------------------------------------------
    # data - egamma
    ds_dict_list = [ { 'tag':'periodA_egamma', 'ds':'group.phys-susy.data12_8TeV.periodA.physics_Egamma.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/', 'is_data':1, 'is_full_mc':0 }
                   , { 'tag':'periodB_egamma', 'ds':'group.phys-susy.data12_8TeV.periodB.physics_Egamma.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/', 'is_data':1, 'is_full_mc':0 }
                   , { 'tag':'periodC_egamma', 'ds':'group.phys-susy.data12_8TeV.periodC.physics_Egamma.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/', 'is_data':1, 'is_full_mc':0 }
                   , { 'tag':'periodD_egamma', 'ds':'group.phys-susy.data12_8TeV.periodD.physics_Egamma.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/', 'is_data':1, 'is_full_mc':0 }
                   , { 'tag':'periodE_egamma', 'ds':'group.phys-susy.data12_8TeV.periodE.physics_Egamma.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/', 'is_data':1, 'is_full_mc':0 }
                   , { 'tag':'periodG_egamma', 'ds':'group.phys-susy.data12_8TeV.periodG.physics_Egamma.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/', 'is_data':1, 'is_full_mc':0 }
                   , { 'tag':'periodH_egamma', 'ds':'group.phys-susy.data12_8TeV.periodH.physics_Egamma.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/', 'is_data':1, 'is_full_mc':0 }
                   , { 'tag':'periodI_egamma', 'ds':'group.phys-susy.data12_8TeV.periodI.physics_Egamma.PhysCont.NTUP_SUSYSKIM.t0pro14_v01_p1542/', 'is_data':1, 'is_full_mc':0 }
                   , { 'tag':'periodJ_egamma', 'ds':'group.phys-susy.data12_8TeV.periodJ.physics_Egamma.PhysCont.NTUP_SUSYSKIM.t0pro14_v01_p1542/', 'is_data':1, 'is_full_mc':0 }
                   , { 'tag':'periodL_egamma', 'ds':'group.phys-susy.data12_8TeV.periodL.physics_Egamma.PhysCont.NTUP_SUSYSKIM.t0pro14_v01_p1542/', 'is_data':1, 'is_full_mc':0 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # data - muon
    ds_dict_list = [ { 'tag':'periodA_muon', 'ds':'group.phys-susy.data12_8TeV.periodA.physics_Muons.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/' , 'is_data':1, 'is_full_mc':0 }
                   , { 'tag':'periodB_muon', 'ds':'group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/' , 'is_data':1, 'is_full_mc':0 }
                   , { 'tag':'periodC_muon', 'ds':'group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/' , 'is_data':1, 'is_full_mc':0 }
                   , { 'tag':'periodD_muon', 'ds':'group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/' , 'is_data':1, 'is_full_mc':0 }
                   , { 'tag':'periodE_muon', 'ds':'group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/' , 'is_data':1, 'is_full_mc':0 }
                   , { 'tag':'periodG_muon', 'ds':'group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/' , 'is_data':1, 'is_full_mc':0 }
                   , { 'tag':'periodH_muon', 'ds':'group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.NTUP_SUSYSKIM.repro14_v01_p1542/' , 'is_data':1, 'is_full_mc':0 }
                   , { 'tag':'periodI_muon', 'ds':'group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.NTUP_SUSYSKIM.t0pro14_v01_p1542/' , 'is_data':1, 'is_full_mc':0 }
                   , { 'tag':'periodJ_muon', 'ds':'group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.NTUP_SUSYSKIM.t0pro14_v01_p1542/' , 'is_data':1, 'is_full_mc':0 }
                   , { 'tag':'periodL_muon', 'ds':'group.phys-susy.data12_8TeV.periodL.physics_Muons.PhysCont.NTUP_SUSYSKIM.t0pro14_v01_p1542/' , 'is_data':1, 'is_full_mc':0 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - higgs powheg pythia
    ds_dict_list = [ { 'tag':'160155.PowhegPythia8_AU2CT10_ggH125_ZZ4lep'          , 'ds':'mc12_8TeV.160155.PowhegPythia8_AU2CT10_ggH125_ZZ4lep.merge.NTUP_SUSY.e1191_s1469_s1470_r3542_r3549_p1512/'          , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'160205.PowhegPythia8_AU2CT10_VBFH125_ZZ4lep'         , 'ds':'mc12_8TeV.160205.PowhegPythia8_AU2CT10_VBFH125_ZZ4lep.merge.NTUP_SUSY.e1195_s1469_s1470_r3542_r3549_p1512/'         , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu'        , 'ds':'mc12_8TeV.160655.PowhegPythia8_AU2CT10_ggH125_ZZllnunu.merge.NTUP_SUSY.e1447_s1499_s1504_r3658_r3549_p1512/'        , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu'       , 'ds':'mc12_8TeV.160705.PowhegPythia8_AU2CT10_VBFH125_ZZllnunu.merge.NTUP_SUSY.e1447_s1499_s1504_r3658_r3549_p1512/'       , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5'  , 'ds':'mc12_8TeV.161005.PowhegPythia8_AU2CT10_ggH125_WW2lep_EF_15_5.merge.NTUP_SUSY.e1285_s1469_s1470_r3542_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5' , 'ds':'mc12_8TeV.161055.PowhegPythia8_AU2CT10_VBFH125_WW2lep_EF_15_5.merge.NTUP_SUSY.e1285_s1469_s1470_r3542_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - higgs pythia
    ds_dict_list = [ { 'tag':'160255.Pythia8_AU2CTEQ6L1_WH125_ZZ4lep'       , 'ds':'mc12_8TeV.160255.Pythia8_AU2CTEQ6L1_WH125_ZZ4lep.merge.NTUP_SUSY.e1419_s1499_s1504_r3658_r3549_p1512/'       , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'160305.Pythia8_AU2CTEQ6L1_ZH125_ZZ4lep'       , 'ds':'mc12_8TeV.160305.Pythia8_AU2CTEQ6L1_ZH125_ZZ4lep.merge.NTUP_SUSY.e1217_s1469_s1470_r3542_r3549_p1512/'       , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu'     , 'ds':'mc12_8TeV.160755.Pythia8_AU2CTEQ6L1_WH125_ZZllnunu.merge.NTUP_SUSY.e1217_s1469_s1470_r3542_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu'     , 'ds':'mc12_8TeV.160805.Pythia8_AU2CTEQ6L1_ZH125_ZZllnunu.merge.NTUP_SUSY.e1217_s1469_s1470_r3542_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep'       , 'ds':'mc12_8TeV.161105.Pythia8_AU2CTEQ6L1_WH125_WW2lep.merge.NTUP_SUSY.e1285_s1469_s1470_r3542_r3549_p1512/'       , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep'       , 'ds':'mc12_8TeV.161155.Pythia8_AU2CTEQ6L1_ZH125_WW2lep.merge.NTUP_SUSY.e1285_s1469_s1470_r3542_r3549_p1512/'       , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'161305.Pythia8_AU2CTEQ6L1_ttH125_WWinclusive' , 'ds':'mc12_8TeV.161305.Pythia8_AU2CTEQ6L1_ttH125_WWinclusive.merge.NTUP_SUSY.e1530_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - top McAtNloJimmy single top
    ds_dict_list = [ { 'tag':'108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl', 'ds':'mc12_8TeV.108346.McAtNloJimmy_AUET2CT10_SingleTopWtChanIncl.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - top AcerMC single top
    ds_dict_list = [ { 'tag':'117360.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_e' , 'ds':'mc12_8TeV.117360.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_e.merge.NTUP_SUSY.e1346_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                     , { 'tag':'117361.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_mu' , 'ds':'mc12_8TeV.117361.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_mu.merge.NTUP_SUSY.e1346_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                     , { 'tag':'117362.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_tau' , 'ds':'mc12_8TeV.117362.AcerMCPythia_AUET2BCTEQ6L1_singletop_tchan_tau.merge.NTUP_SUSY.e1346_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                     ]

    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

 # ------------------------------------------------------------------------------
    # bkg - top MC@NLO single top
    ds_dict_list = [ {'tag':'108343.McAtNloJimmy_AUET2CT10_SingleTopSChanWenu' , 'ds':'mc12_8TeV.108343.McAtNloJimmy_AUET2CT10_SingleTopSChanWenu.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                     {'tag':'108344.McAtNloJimmy_AUET2CT10_SingleTopSChanWmunu' , 'ds':'mc12_8TeV.108344.McAtNloJimmy_AUET2CT10_SingleTopSChanWmunu.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                     {'tag':'108345.McAtNloJimmy_AUET2CT10_SingleTopSChanWtaunu' , 'ds':'mc12_8TeV.108345.McAtNloJimmy_AUET2CT10_SingleTopSChanWtaunu.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                     ]

    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - triboson
    ds_dict_list = [ {'tag':'167006.MadGraphPythia_AUET2BCTEQ6L1_WWWStar_lnulnulnu', 'ds':'mc12_8TeV.167006.MadGraphPythia_AUET2BCTEQ6L1_WWWStar_lnulnulnu.merge.NTUP_SUSY.e1447_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1}
                   , { 'tag':'167008.MadGraphPythia_AUET2BCTEQ6L1_ZZZStar_nunullll', 'ds':'mc12_8TeV.167008.MadGraphPythia_AUET2BCTEQ6L1_ZZZStar_nunullll.merge.NTUP_SUSY.e1466_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'167007.MadGraphPythia_AUET2BCTEQ6L1_ZWWStar_lllnulnu', 'ds':'mc12_8TeV.167007.MadGraphPythia_AUET2BCTEQ6L1_ZWWStar_lllnulnu.merge.NTUP_SUSY.e1466_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'147191.Sherpa_CT10_lnlnjj_WWjj_ls_EW6'               , 'ds':'mc12_8TeV.147191.Sherpa_CT10_lnlnjj_WWjj_ls_EW6.merge.NTUP_SUSY.e1613_s1499_s1504_r3658_r3549_p1512/'                , 'is_data':0 , 'is_full_mc':1 }
                   #, {'tag':'Sherpa_CT10_lnln_WW_ls'                               , 'ds':'mc12_8TeV.147192.Sherpa_CT10_lnln_WW_ls.merge.NTUP_SUSY.e1613_s1499_s1504_r3658_r3549_p1512/', 'is_data':0 , 'is_full_mc':1 } #Maybe not?  it's not on the 2L OS list 
                   , {'tag':'147193.Sherpa_CT10_lnlnjj_WWjj_EW6'                   , 'ds':'mc12_8TeV.147193.Sherpa_CT10_lnlnjj_WWjj_EW6.merge.NTUP_SUSY.e1613_s1499_s1504_r3658_r3549_p1512/'                   , 'is_data':0 , 'is_full_mc':1 }
                   , {'tag':'147194.Sherpa_CT10_lllnjj_WZjj_EW6'                   , 'ds':'mc12_8TeV.147194.Sherpa_CT10_lllnjj_WZjj_EW6.merge.NTUP_SUSY.e1613_s1499_s1504_r3658_r3549_p1512/'                   , 'is_data':0 , 'is_full_mc':1 }
                   , {'tag':'147195.Sherpa_CT10_llnnjj_ZZjj_EW6'                   , 'ds':'mc12_8TeV.147195.Sherpa_CT10_llnnjj_ZZjj_EW6.merge.NTUP_SUSY.e1613_s1499_s1504_r3658_r3549_p1512/'                   , 'is_data':0 , 'is_full_mc':1 }
                   , {'tag':'147196.Sherpa_CT10_lllljj_ZZjj_EW6'                   , 'ds':'mc12_8TeV.147196.Sherpa_CT10_lllljj_ZZjj_EW6.merge.NTUP_SUSY.e1613_s1499_s1504_r3658_r3549_p1512/'                   , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - ttbar__MadGraphPythia.sh
    ds_dict_list = [ { 'tag':'119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW'   , 'ds':'mc12_8TeV.119353.MadGraphPythia_AUET2BCTEQ6L1_ttbarW.merge.NTUP_SUSY.e1352_s1499_s1504_r3658_r3549_p1512/'   , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj'  , 'ds':'mc12_8TeV.119354.MadGraphPythia_AUET2BCTEQ6L1_ttbarWj.merge.NTUP_SUSY.e1352_s1499_s1504_r3658_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ'   , 'ds':'mc12_8TeV.119355.MadGraphPythia_AUET2BCTEQ6L1_ttbarZ.merge.NTUP_SUSY.e1352_s1499_s1504_r3658_r3549_p1512/'   , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj'  , 'ds':'mc12_8TeV.119356.MadGraphPythia_AUET2BCTEQ6L1_ttbarZj.merge.NTUP_SUSY.e1352_s1499_s1504_r3658_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW' , 'ds':'mc12_8TeV.119583.MadgraphPythia_AUET2B_CTEQ6L1_ttbarWW.merge.NTUP_SUSY.e1543_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - ttbar__McAtNloJimmy.sh
    ds_dict_list = [ { 'tag':'105200.McAtNloJimmy_CT10_ttbar_LeptonFilter', 'ds':'mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1513_s1499_s1504_r3945_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - ttbar__PowhegPythia.sh
    ds_dict_list = [ { 'tag':'117050.PowhegPythia_P2011C_ttbar', 'ds':'mc12_8TeV.117050.PowhegPythia_P2011C_ttbar.merge.NTUP_SUSY.e1728_s1773_s1776_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - W_plus_jet__AlpgenJimmy.sh
    ds_dict_list = [ { 'tag':'107680.AlpgenJimmy_AUET2CTEQ6L1_WenuNp0', 'ds':'mc12_8TeV.107680.AlpgenJimmy_AUET2CTEQ6L1_WenuNp0.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'107681.AlpgenJimmy_AUET2CTEQ6L1_WenuNp1', 'ds':'mc12_8TeV.107681.AlpgenJimmy_AUET2CTEQ6L1_WenuNp1.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'107682.AlpgenJimmy_AUET2CTEQ6L1_WenuNp2', 'ds':'mc12_8TeV.107682.AlpgenJimmy_AUET2CTEQ6L1_WenuNp2.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'107683.AlpgenJimmy_AUET2CTEQ6L1_WenuNp3', 'ds':'mc12_8TeV.107683.AlpgenJimmy_AUET2CTEQ6L1_WenuNp3.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'107684.AlpgenJimmy_AUET2CTEQ6L1_WenuNp4', 'ds':'mc12_8TeV.107684.AlpgenJimmy_AUET2CTEQ6L1_WenuNp4.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'107685.AlpgenJimmy_AUET2CTEQ6L1_WenuNp5', 'ds':'mc12_8TeV.107685.AlpgenJimmy_AUET2CTEQ6L1_WenuNp5.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   , { 'tag':'107690.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp0', 'ds':'mc12_8TeV.107690.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp0.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'107691.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp1', 'ds':'mc12_8TeV.107691.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp1.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'107692.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp2', 'ds':'mc12_8TeV.107692.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp2.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'107693.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp3', 'ds':'mc12_8TeV.107693.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp3.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'107694.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp4', 'ds':'mc12_8TeV.107694.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp4.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'107695.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp5', 'ds':'mc12_8TeV.107695.AlpgenJimmy_AUET2CTEQ6L1_WmunuNp5.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   , { 'tag':'107700.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp0', 'ds':'mc12_8TeV.107700.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp0.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'107701.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp1', 'ds':'mc12_8TeV.107701.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp1.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'107702.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp2', 'ds':'mc12_8TeV.107702.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp2.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'107703.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp3', 'ds':'mc12_8TeV.107703.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp3.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'107704.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp4', 'ds':'mc12_8TeV.107704.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp4.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'107705.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp5', 'ds':'mc12_8TeV.107705.AlpgenJimmy_AUET2CTEQ6L1_WtaunuNp5.merge.NTUP_SUSY.e1571_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - WW__Jimmy.sh
    ds_dict_list = [ { 'tag':'169473.gg2wwJimmy_AUET2CT10_WpWmenutaunu'   , 'ds':'mc12_8TeV.169473.gg2wwJimmy_AUET2CT10_WpWmenutaunu.merge.NTUP_SUSY.e1723_s1581_s1586_r3658_r3549_p1512/'   , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'169478.gg2wwJimmy_AUET2CT10_WpWmtaunuenu'   , 'ds':'mc12_8TeV.169478.gg2wwJimmy_AUET2CT10_WpWmtaunuenu.merge.NTUP_SUSY.e1723_s1581_s1586_r3658_r3549_p1512/'   , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'169474.gg2wwJimmy_AUET2CT10_WpWmmunumunu'   , 'ds':'mc12_8TeV.169474.gg2wwJimmy_AUET2CT10_WpWmmunumunu.merge.NTUP_SUSY.e1723_s1581_s1586_r3658_r3549_p1512/'   , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'169477.gg2wwJimmy_AUET2CT10_WpWmtaunutaunu' , 'ds':'mc12_8TeV.169477.gg2wwJimmy_AUET2CT10_WpWmtaunutaunu.merge.NTUP_SUSY.e1723_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'169476.gg2wwJimmy_AUET2CT10_WpWmmunutaunu'  , 'ds':'mc12_8TeV.169476.gg2wwJimmy_AUET2CT10_WpWmmunutaunu.merge.NTUP_SUSY.e1723_s1581_s1586_r3658_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'169472.gg2wwJimmy_AUET2CT10_WpWmenumunu'    , 'ds':'mc12_8TeV.169472.gg2wwJimmy_AUET2CT10_WpWmenumunu.merge.NTUP_SUSY.e1723_s1581_s1586_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'169479.gg2wwJimmy_AUET2CT10_WpWmtaunumunu'  , 'ds':'mc12_8TeV.169479.gg2wwJimmy_AUET2CT10_WpWmtaunumunu.merge.NTUP_SUSY.e1723_s1581_s1586_r3658_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'169475.gg2wwJimmy_AUET2CT10_WpWmmunuenu'    , 'ds':'mc12_8TeV.169475.gg2wwJimmy_AUET2CT10_WpWmmunuenu.merge.NTUP_SUSY.e1723_s1581_s1586_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'169471.gg2wwJimmy_AUET2CT10_WpWmenuenu'     , 'ds':'mc12_8TeV.169471.gg2wwJimmy_AUET2CT10_WpWmenuenu.merge.NTUP_SUSY.e1723_s1581_s1586_r3658_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

##    # ------------------------------------------------------------------------------
##    # bkg - WW__MadGraphPythia.sh This is Triboson TO DELETE AFTER CONFIRMATION WITH BRETT
##    ds_dict_list = [ { 'tag':'167006.MadGraphPythia_AUET2BCTEQ6L1_WWWStar_lnulnulnu', 'ds':'mc12_8TeV.167006.MadGraphPythia_AUET2BCTEQ6L1_WWWStar_lnulnulnu.merge.NTUP_SUSY.e1447_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
##            ]
##    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)
##
    # ------------------------------------------------------------------------------
    # bkg - WW__PowhegPythia8.sh
    ds_dict_list = [ { 'tag':'126928.PowhegPythia8_AU2CT10_WpWm_ee', 'ds':'mc12_8TeV.126928.PowhegPythia8_AU2CT10_WpWm_ee.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'126929.PowhegPythia8_AU2CT10_WpWm_me', 'ds':'mc12_8TeV.126929.PowhegPythia8_AU2CT10_WpWm_me.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'126930.PowhegPythia8_AU2CT10_WpWm_te', 'ds':'mc12_8TeV.126930.PowhegPythia8_AU2CT10_WpWm_te.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'126931.PowhegPythia8_AU2CT10_WpWm_em', 'ds':'mc12_8TeV.126931.PowhegPythia8_AU2CT10_WpWm_em.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'126932.PowhegPythia8_AU2CT10_WpWm_mm', 'ds':'mc12_8TeV.126932.PowhegPythia8_AU2CT10_WpWm_mm.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'126933.PowhegPythia8_AU2CT10_WpWm_tm', 'ds':'mc12_8TeV.126933.PowhegPythia8_AU2CT10_WpWm_tm.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'126934.PowhegPythia8_AU2CT10_WpWm_et', 'ds':'mc12_8TeV.126934.PowhegPythia8_AU2CT10_WpWm_et.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'126935.PowhegPythia8_AU2CT10_WpWm_mt', 'ds':'mc12_8TeV.126935.PowhegPythia8_AU2CT10_WpWm_mt.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'126936.PowhegPythia8_AU2CT10_WpWm_tt', 'ds':'mc12_8TeV.126936.PowhegPythia8_AU2CT10_WpWm_tt.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - WW__Sherpa.sh
    ds_dict_list = [ { 'tag':'126892.Sherpa_CT10_llnunu_WW'     , 'ds':'mc12_8TeV.126892.Sherpa_CT10_llnunu_WW.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'126988.Sherpa_CT10_llnunu_SS_EW6' , 'ds':'mc12_8TeV.126988.Sherpa_CT10_llnunu_SS_EW6.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'126989.Sherpa_CT10_llnunujj_SS'   , 'ds':'mc12_8TeV.126989.Sherpa_CT10_llnunujj_SS.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/'   , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157819.Sherpa_CT10_VVtotaunuqq'   , 'ds':'mc12_8TeV.157819.Sherpa_CT10_VVtotaunuqq.merge.NTUP_SUSY.e1515_s1499_s1504_r3658_r3549_p1512/'   , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157818.Sherpa_CT10_VVtomunuqq'    , 'ds':'mc12_8TeV.157818.Sherpa_CT10_VVtomunuqq.merge.NTUP_SUSY.e1515_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157817.Sherpa_CT10_VVtoenuqq'     , 'ds':'mc12_8TeV.157817.Sherpa_CT10_VVtoenuqq.merge.NTUP_SUSY.e1515_s1499_s1504_r3658_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - WZ__PowhegPythia8.sh
    ds_dict_list = [ { 'tag':'129477.PowhegPythia8_AU2CT10_WZ_Wm11Z11_mll0p250d0_2LeptonFilter5'  , 'ds':'mc12_8TeV.129477.PowhegPythia8_AU2CT10_WZ_Wm11Z11_mll0p250d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'129478.PowhegPythia8_AU2CT10_WZ_Wm11Z13_mll0p4614d0_2LeptonFilter5' , 'ds':'mc12_8TeV.129478.PowhegPythia8_AU2CT10_WZ_Wm11Z13_mll0p4614d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'129479.PowhegPythia8_AU2CT10_WZ_Wm11Z15_mll3p804d0_2LeptonFilter5'  , 'ds':'mc12_8TeV.129479.PowhegPythia8_AU2CT10_WZ_Wm11Z15_mll3p804d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'129480.PowhegPythia8_AU2CT10_WZ_Wm13Z11_mll0p250d0_2LeptonFilter5'  , 'ds':'mc12_8TeV.129480.PowhegPythia8_AU2CT10_WZ_Wm13Z11_mll0p250d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'129481.PowhegPythia8_AU2CT10_WZ_Wm13Z13_mll0p4614d0_2LeptonFilter5' , 'ds':'mc12_8TeV.129481.PowhegPythia8_AU2CT10_WZ_Wm13Z13_mll0p4614d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'129482.PowhegPythia8_AU2CT10_WZ_Wm13Z15_mll3p804d0_2LeptonFilter5'  , 'ds':'mc12_8TeV.129482.PowhegPythia8_AU2CT10_WZ_Wm13Z15_mll3p804d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'129483.PowhegPythia8_AU2CT10_WZ_Wm15Z11_mll0p250d0_2LeptonFilter5'  , 'ds':'mc12_8TeV.129483.PowhegPythia8_AU2CT10_WZ_Wm15Z11_mll0p250d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'129484.PowhegPythia8_AU2CT10_WZ_Wm15Z13_mll0p4614d0_2LeptonFilter5' , 'ds':'mc12_8TeV.129484.PowhegPythia8_AU2CT10_WZ_Wm15Z13_mll0p4614d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'129485.PowhegPythia8_AU2CT10_WZ_Wm15Z15_mll3p804d0_2LeptonFilter5'  , 'ds':'mc12_8TeV.129485.PowhegPythia8_AU2CT10_WZ_Wm15Z15_mll3p804d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'129486.PowhegPythia8_AU2CT10_WZ_W11Z11_mll0p250d0_2LeptonFilter5'   , 'ds':'mc12_8TeV.129486.PowhegPythia8_AU2CT10_WZ_W11Z11_mll0p250d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/'   , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'129487.PowhegPythia8_AU2CT10_WZ_W11Z13_mll0p4614d0_2LeptonFilter5'  , 'ds':'mc12_8TeV.129487.PowhegPythia8_AU2CT10_WZ_W11Z13_mll0p4614d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'129488.PowhegPythia8_AU2CT10_WZ_W11Z15_mll3p804d0_2LeptonFilter5'   , 'ds':'mc12_8TeV.129488.PowhegPythia8_AU2CT10_WZ_W11Z15_mll3p804d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/'   , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'129489.PowhegPythia8_AU2CT10_WZ_W13Z11_mll0p250d0_2LeptonFilter5'   , 'ds':'mc12_8TeV.129489.PowhegPythia8_AU2CT10_WZ_W13Z11_mll0p250d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/'   , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'129490.PowhegPythia8_AU2CT10_WZ_W13Z13_mll0p4614d0_2LeptonFilter5'  , 'ds':'mc12_8TeV.129490.PowhegPythia8_AU2CT10_WZ_W13Z13_mll0p4614d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'129491.PowhegPythia8_AU2CT10_WZ_W13Z15_mll3p804d0_2LeptonFilter5'   , 'ds':'mc12_8TeV.129491.PowhegPythia8_AU2CT10_WZ_W13Z15_mll3p804d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/'   , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'129492.PowhegPythia8_AU2CT10_WZ_W15Z11_mll0p250d0_2LeptonFilter5'   , 'ds':'mc12_8TeV.129492.PowhegPythia8_AU2CT10_WZ_W15Z11_mll0p250d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/'   , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'129493.PowhegPythia8_AU2CT10_WZ_W15Z13_mll0p4614d0_2LeptonFilter5'  , 'ds':'mc12_8TeV.129493.PowhegPythia8_AU2CT10_WZ_W15Z13_mll0p4614d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'129494.PowhegPythia8_AU2CT10_WZ_W15Z15_mll3p804d0_2LeptonFilter5'   , 'ds':'mc12_8TeV.129494.PowhegPythia8_AU2CT10_WZ_W15Z15_mll3p804d0_2LeptonFilter5.merge.NTUP_SUSY.e1300_s1469_s1470_r3542_r3549_p1512/'   , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - Z_plus_jet_alpgen.sh
    ds_dict_list = [ { 'tag':'117650.AlpgenPythia_P2011C_ZeeNp0', 'ds':'mc12_8TeV.117650.AlpgenPythia_P2011C_ZeeNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117651.AlpgenPythia_P2011C_ZeeNp1', 'ds':'mc12_8TeV.117651.AlpgenPythia_P2011C_ZeeNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117652.AlpgenPythia_P2011C_ZeeNp2', 'ds':'mc12_8TeV.117652.AlpgenPythia_P2011C_ZeeNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117653.AlpgenPythia_P2011C_ZeeNp3', 'ds':'mc12_8TeV.117653.AlpgenPythia_P2011C_ZeeNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117654.AlpgenPythia_P2011C_ZeeNp4', 'ds':'mc12_8TeV.117654.AlpgenPythia_P2011C_ZeeNp4.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117655.AlpgenPythia_P2011C_ZeeNp5', 'ds':'mc12_8TeV.117655.AlpgenPythia_P2011C_ZeeNp5.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   , { 'tag':'117660.AlpgenPythia_P2011C_ZmumuNp0', 'ds':'mc12_8TeV.117660.AlpgenPythia_P2011C_ZmumuNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117661.AlpgenPythia_P2011C_ZmumuNp1', 'ds':'mc12_8TeV.117661.AlpgenPythia_P2011C_ZmumuNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117662.AlpgenPythia_P2011C_ZmumuNp2', 'ds':'mc12_8TeV.117662.AlpgenPythia_P2011C_ZmumuNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117663.AlpgenPythia_P2011C_ZmumuNp3', 'ds':'mc12_8TeV.117663.AlpgenPythia_P2011C_ZmumuNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117664.AlpgenPythia_P2011C_ZmumuNp4', 'ds':'mc12_8TeV.117664.AlpgenPythia_P2011C_ZmumuNp4.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117665.AlpgenPythia_P2011C_ZmumuNp5', 'ds':'mc12_8TeV.117665.AlpgenPythia_P2011C_ZmumuNp5.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   ,  { 'tag':'117670.AlpgenPythia_P2011C_ZtautauNp0', 'ds':'mc12_8TeV.117670.AlpgenPythia_P2011C_ZtautauNp0.merge.NTUP_SUSY.e1711_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'117671.AlpgenPythia_P2011C_ZtautauNp1', 'ds':'mc12_8TeV.117671.AlpgenPythia_P2011C_ZtautauNp1.merge.NTUP_SUSY.e1711_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'117672.AlpgenPythia_P2011C_ZtautauNp2', 'ds':'mc12_8TeV.117672.AlpgenPythia_P2011C_ZtautauNp2.merge.NTUP_SUSY.e1711_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'117673.AlpgenPythia_P2011C_ZtautauNp3', 'ds':'mc12_8TeV.117673.AlpgenPythia_P2011C_ZtautauNp3.merge.NTUP_SUSY.e1711_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'117674.AlpgenPythia_P2011C_ZtautauNp4', 'ds':'mc12_8TeV.117674.AlpgenPythia_P2011C_ZtautauNp4.merge.NTUP_SUSY.e1711_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'117675.AlpgenPythia_P2011C_ZtautauNp5', 'ds':'mc12_8TeV.117675.AlpgenPythia_P2011C_ZtautauNp5.merge.NTUP_SUSY.e1711_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   ,  { 'tag':'110805.AlpgenPythia_P2011C_ZeeccNp0', 'ds':'mc12_8TeV.110805.AlpgenPythia_P2011C_ZeeccNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'110806.AlpgenPythia_P2011C_ZeeccNp1', 'ds':'mc12_8TeV.110806.AlpgenPythia_P2011C_ZeeccNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'110807.AlpgenPythia_P2011C_ZeeccNp2', 'ds':'mc12_8TeV.110807.AlpgenPythia_P2011C_ZeeccNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'110808.AlpgenPythia_P2011C_ZeeccNp3', 'ds':'mc12_8TeV.110808.AlpgenPythia_P2011C_ZeeccNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   ,  { 'tag':'110809.AlpgenPythia_P2011C_ZmumuccNp0', 'ds':'mc12_8TeV.110809.AlpgenPythia_P2011C_ZmumuccNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'110810.AlpgenPythia_P2011C_ZmumuccNp1', 'ds':'mc12_8TeV.110810.AlpgenPythia_P2011C_ZmumuccNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'110811.AlpgenPythia_P2011C_ZmumuccNp2', 'ds':'mc12_8TeV.110811.AlpgenPythia_P2011C_ZmumuccNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'110812.AlpgenPythia_P2011C_ZmumuccNp3', 'ds':'mc12_8TeV.110812.AlpgenPythia_P2011C_ZmumuccNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   ,  { 'tag':'110813.AlpgenPythia_P2011C_ZtautauccNp0', 'ds':'mc12_8TeV.110813.AlpgenPythia_P2011C_ZtautauccNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'110814.AlpgenPythia_P2011C_ZtautauccNp1', 'ds':'mc12_8TeV.110814.AlpgenPythia_P2011C_ZtautauccNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'110815.AlpgenPythia_P2011C_ZtautauccNp2', 'ds':'mc12_8TeV.110815.AlpgenPythia_P2011C_ZtautauccNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'110816.AlpgenPythia_P2011C_ZtautauccNp3', 'ds':'mc12_8TeV.110816.AlpgenPythia_P2011C_ZtautauccNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   ,  { 'tag':'110817.AlpgenPythia_P2011C_ZeebbNp0', 'ds':'mc12_8TeV.110817.AlpgenPythia_P2011C_ZeebbNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'110818.AlpgenPythia_P2011C_ZeebbNp1', 'ds':'mc12_8TeV.110818.AlpgenPythia_P2011C_ZeebbNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'110819.AlpgenPythia_P2011C_ZeebbNp2', 'ds':'mc12_8TeV.110819.AlpgenPythia_P2011C_ZeebbNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'110820.AlpgenPythia_P2011C_ZeebbNp3', 'ds':'mc12_8TeV.110820.AlpgenPythia_P2011C_ZeebbNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   ,  { 'tag':'110821.AlpgenPythia_P2011C_ZmumubbNp0', 'ds':'mc12_8TeV.110821.AlpgenPythia_P2011C_ZmumubbNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'110822.AlpgenPythia_P2011C_ZmumubbNp1', 'ds':'mc12_8TeV.110822.AlpgenPythia_P2011C_ZmumubbNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'110823.AlpgenPythia_P2011C_ZmumubbNp2', 'ds':'mc12_8TeV.110823.AlpgenPythia_P2011C_ZmumubbNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'110824.AlpgenPythia_P2011C_ZmumubbNp3', 'ds':'mc12_8TeV.110824.AlpgenPythia_P2011C_ZmumubbNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   ,  { 'tag':'110825.AlpgenPythia_P2011C_ZtautaubbNp0', 'ds':'mc12_8TeV.110825.AlpgenPythia_P2011C_ZtautaubbNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'110826.AlpgenPythia_P2011C_ZtautaubbNp1', 'ds':'mc12_8TeV.110826.AlpgenPythia_P2011C_ZtautaubbNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'110827.AlpgenPythia_P2011C_ZtautaubbNp2', 'ds':'mc12_8TeV.110827.AlpgenPythia_P2011C_ZtautaubbNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ,  { 'tag':'110828.AlpgenPythia_P2011C_ZtautaubbNp3', 'ds':'mc12_8TeV.110828.AlpgenPythia_P2011C_ZtautaubbNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - AlpgenPythia_Auto Z+bb
    ds_dict_list = [ { 'tag':'200332.AlpgenPythia_Auto_P2011C_ZeebbNp0'         , 'ds':'mc12_8TeV.200332.AlpgenPythia_Auto_P2011C_ZeebbNp0.merge.NTUP_SUSY.e2384_s1581_s1586_r3658_r3549_p1512/'         , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'200333.AlpgenPythia_Auto_P2011C_ZeebbNp1'         , 'ds':'mc12_8TeV.200333.AlpgenPythia_Auto_P2011C_ZeebbNp1.merge.NTUP_SUSY.e2384_s1581_s1586_r3658_r3549_p1512/'         , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'200334.AlpgenPythia_Auto_P2011C_ZeebbNp2'         , 'ds':'mc12_8TeV.200334.AlpgenPythia_Auto_P2011C_ZeebbNp2.merge.NTUP_SUSY.e2384_s1581_s1586_r3658_r3549_p1512/'         , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'200335.AlpgenPythia_Auto_P2011C_ZeebbNp3incl'     , 'ds':'mc12_8TeV.200335.AlpgenPythia_Auto_P2011C_ZeebbNp3incl.merge.NTUP_SUSY.e2384_s1581_s1586_r3658_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0'       , 'ds':'mc12_8TeV.200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0.merge.NTUP_SUSY.e2385_s1581_s1586_r3658_r3549_p1512/'       , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'200341.AlpgenPythia_Auto_P2011C_ZmumubbNp1'       , 'ds':'mc12_8TeV.200341.AlpgenPythia_Auto_P2011C_ZmumubbNp1.merge.NTUP_SUSY.e2385_s1581_s1586_r3658_r3549_p1512/'       , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'200342.AlpgenPythia_Auto_P2011C_ZmumubbNp2'       , 'ds':'mc12_8TeV.200342.AlpgenPythia_Auto_P2011C_ZmumubbNp2.merge.NTUP_SUSY.e2385_s1581_s1586_r3658_r3549_p1512/'       , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'200343.AlpgenPythia_Auto_P2011C_ZmumubbNp3incl'   , 'ds':'mc12_8TeV.200343.AlpgenPythia_Auto_P2011C_ZmumubbNp3incl.merge.NTUP_SUSY.e2385_s1581_s1586_r3658_r3549_p1512/'   , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'200348.AlpgenPythia_Auto_P2011C_ZtautaubbNp0'     , 'ds':'mc12_8TeV.200348.AlpgenPythia_Auto_P2011C_ZtautaubbNp0.merge.NTUP_SUSY.e2386_s1581_s1586_r3658_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'200349.AlpgenPythia_Auto_P2011C_ZtautaubbNp1'     , 'ds':'mc12_8TeV.200349.AlpgenPythia_Auto_P2011C_ZtautaubbNp1.merge.NTUP_SUSY.e2386_s1581_s1586_r3658_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'200350.AlpgenPythia_Auto_P2011C_ZtautaubbNp2'     , 'ds':'mc12_8TeV.200350.AlpgenPythia_Auto_P2011C_ZtautaubbNp2.merge.NTUP_SUSY.e2386_s1581_s1586_r3658_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'200351.AlpgenPythia_Auto_P2011C_ZtautaubbNp3incl' , 'ds':'mc12_8TeV.200351.AlpgenPythia_Auto_P2011C_ZtautaubbNp3incl.merge.NTUP_SUSY.e2386_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - Z_plus_jet__Sherpa.sh
    ds_dict_list = [ { 'tag':'147770.Sherpa_CT10_Zee'     , 'ds':'mc12_8TeV.147770.Sherpa_CT10_Zee.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'147771.Sherpa_CT10_Zmumu'   , 'ds':'mc12_8TeV.147771.Sherpa_CT10_Zmumu.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/'   , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'147772.Sherpa_CT10_Ztautau' , 'ds':'mc12_8TeV.147772.Sherpa_CT10_Ztautau.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - ZX__AlpgenPythia.sh
    ds_dict_list = [ { 'tag':'117650.AlpgenPythia_P2011C_ZeeNp0', 'ds':'mc12_8TeV.117650.AlpgenPythia_P2011C_ZeeNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117651.AlpgenPythia_P2011C_ZeeNp1', 'ds':'mc12_8TeV.117651.AlpgenPythia_P2011C_ZeeNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117652.AlpgenPythia_P2011C_ZeeNp2', 'ds':'mc12_8TeV.117652.AlpgenPythia_P2011C_ZeeNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117653.AlpgenPythia_P2011C_ZeeNp3', 'ds':'mc12_8TeV.117653.AlpgenPythia_P2011C_ZeeNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117654.AlpgenPythia_P2011C_ZeeNp4', 'ds':'mc12_8TeV.117654.AlpgenPythia_P2011C_ZeeNp4.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117655.AlpgenPythia_P2011C_ZeeNp5', 'ds':'mc12_8TeV.117655.AlpgenPythia_P2011C_ZeeNp5.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   , { 'tag':'117660.AlpgenPythia_P2011C_ZmumuNp0', 'ds':'mc12_8TeV.117660.AlpgenPythia_P2011C_ZmumuNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117661.AlpgenPythia_P2011C_ZmumuNp1', 'ds':'mc12_8TeV.117661.AlpgenPythia_P2011C_ZmumuNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117662.AlpgenPythia_P2011C_ZmumuNp2', 'ds':'mc12_8TeV.117662.AlpgenPythia_P2011C_ZmumuNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117663.AlpgenPythia_P2011C_ZmumuNp3', 'ds':'mc12_8TeV.117663.AlpgenPythia_P2011C_ZmumuNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117664.AlpgenPythia_P2011C_ZmumuNp4', 'ds':'mc12_8TeV.117664.AlpgenPythia_P2011C_ZmumuNp4.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117665.AlpgenPythia_P2011C_ZmumuNp5', 'ds':'mc12_8TeV.117665.AlpgenPythia_P2011C_ZmumuNp5.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   , { 'tag':'117670.AlpgenPythia_P2011C_ZtautauNp0', 'ds':'mc12_8TeV.117670.AlpgenPythia_P2011C_ZtautauNp0.merge.NTUP_SUSY.e1711_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117671.AlpgenPythia_P2011C_ZtautauNp1', 'ds':'mc12_8TeV.117671.AlpgenPythia_P2011C_ZtautauNp1.merge.NTUP_SUSY.e1711_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117672.AlpgenPythia_P2011C_ZtautauNp2', 'ds':'mc12_8TeV.117672.AlpgenPythia_P2011C_ZtautauNp2.merge.NTUP_SUSY.e1711_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117673.AlpgenPythia_P2011C_ZtautauNp3', 'ds':'mc12_8TeV.117673.AlpgenPythia_P2011C_ZtautauNp3.merge.NTUP_SUSY.e1711_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117674.AlpgenPythia_P2011C_ZtautauNp4', 'ds':'mc12_8TeV.117674.AlpgenPythia_P2011C_ZtautauNp4.merge.NTUP_SUSY.e1711_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'117675.AlpgenPythia_P2011C_ZtautauNp5', 'ds':'mc12_8TeV.117675.AlpgenPythia_P2011C_ZtautauNp5.merge.NTUP_SUSY.e1711_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   , { 'tag':'110805.AlpgenPythia_P2011C_ZeeccNp0', 'ds':'mc12_8TeV.110805.AlpgenPythia_P2011C_ZeeccNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'110806.AlpgenPythia_P2011C_ZeeccNp1', 'ds':'mc12_8TeV.110806.AlpgenPythia_P2011C_ZeeccNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'110807.AlpgenPythia_P2011C_ZeeccNp2', 'ds':'mc12_8TeV.110807.AlpgenPythia_P2011C_ZeeccNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'110808.AlpgenPythia_P2011C_ZeeccNp3', 'ds':'mc12_8TeV.110808.AlpgenPythia_P2011C_ZeeccNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   , { 'tag':'110809.AlpgenPythia_P2011C_ZmumuccNp0', 'ds':'mc12_8TeV.110809.AlpgenPythia_P2011C_ZmumuccNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'110810.AlpgenPythia_P2011C_ZmumuccNp1', 'ds':'mc12_8TeV.110810.AlpgenPythia_P2011C_ZmumuccNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'110811.AlpgenPythia_P2011C_ZmumuccNp2', 'ds':'mc12_8TeV.110811.AlpgenPythia_P2011C_ZmumuccNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'110812.AlpgenPythia_P2011C_ZmumuccNp3', 'ds':'mc12_8TeV.110812.AlpgenPythia_P2011C_ZmumuccNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   , { 'tag':'110813.AlpgenPythia_P2011C_ZtautauccNp0', 'ds':'mc12_8TeV.110813.AlpgenPythia_P2011C_ZtautauccNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'110814.AlpgenPythia_P2011C_ZtautauccNp1', 'ds':'mc12_8TeV.110814.AlpgenPythia_P2011C_ZtautauccNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'110815.AlpgenPythia_P2011C_ZtautauccNp2', 'ds':'mc12_8TeV.110815.AlpgenPythia_P2011C_ZtautauccNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'110816.AlpgenPythia_P2011C_ZtautauccNp3', 'ds':'mc12_8TeV.110816.AlpgenPythia_P2011C_ZtautauccNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   , { 'tag':'110817.AlpgenPythia_P2011C_ZeebbNp0', 'ds':'mc12_8TeV.110817.AlpgenPythia_P2011C_ZeebbNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'110818.AlpgenPythia_P2011C_ZeebbNp1', 'ds':'mc12_8TeV.110818.AlpgenPythia_P2011C_ZeebbNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'110819.AlpgenPythia_P2011C_ZeebbNp2', 'ds':'mc12_8TeV.110819.AlpgenPythia_P2011C_ZeebbNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'110820.AlpgenPythia_P2011C_ZeebbNp3', 'ds':'mc12_8TeV.110820.AlpgenPythia_P2011C_ZeebbNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   , { 'tag':'110821.AlpgenPythia_P2011C_ZmumubbNp0', 'ds':'mc12_8TeV.110821.AlpgenPythia_P2011C_ZmumubbNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'110822.AlpgenPythia_P2011C_ZmumubbNp1', 'ds':'mc12_8TeV.110822.AlpgenPythia_P2011C_ZmumubbNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'110823.AlpgenPythia_P2011C_ZmumubbNp2', 'ds':'mc12_8TeV.110823.AlpgenPythia_P2011C_ZmumubbNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'110824.AlpgenPythia_P2011C_ZmumubbNp3', 'ds':'mc12_8TeV.110824.AlpgenPythia_P2011C_ZmumubbNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   , { 'tag':'110825.AlpgenPythia_P2011C_ZtautaubbNp0', 'ds':'mc12_8TeV.110825.AlpgenPythia_P2011C_ZtautaubbNp0.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'110826.AlpgenPythia_P2011C_ZtautaubbNp1', 'ds':'mc12_8TeV.110826.AlpgenPythia_P2011C_ZtautaubbNp1.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'110827.AlpgenPythia_P2011C_ZtautaubbNp2', 'ds':'mc12_8TeV.110827.AlpgenPythia_P2011C_ZtautaubbNp2.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'110828.AlpgenPythia_P2011C_ZtautaubbNp3', 'ds':'mc12_8TeV.110828.AlpgenPythia_P2011C_ZtautaubbNp3.merge.NTUP_SUSY.e1477_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - ZX__Sherpa_atlfast.sh
    ds_dict_list = [ { 'tag':'147770.Sherpa_CT10_Zee'             , 'ds':'mc12_8TeV.147770.Sherpa_CT10_Zee.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/'             , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'147771.Sherpa_CT10_Zmumu'           , 'ds':'mc12_8TeV.147771.Sherpa_CT10_Zmumu.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/'           , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'147772.Sherpa_CT10_Ztautau'         , 'ds':'mc12_8TeV.147772.Sherpa_CT10_Ztautau.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/'         , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'173041.Sherpa_CT10_DYeeM08to15'     , 'ds':'mc12_8TeV.173041.Sherpa_CT10_DYeeM08to15.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1512/'             , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'173042.Sherpa_CT10_DYeeM15to40'     , 'ds':'mc12_8TeV.173042.Sherpa_CT10_DYeeM15to40.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1512/'             , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'173043.Sherpa_CT10_DYmumuM08to15'   , 'ds':'mc12_8TeV.173043.Sherpa_CT10_DYmumuM08to15.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1512/'           , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'173044.Sherpa_CT10_DYmumuM15to40'   , 'ds':'mc12_8TeV.173044.Sherpa_CT10_DYmumuM15to40.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1512/'           , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'173045.Sherpa_CT10_DYtautauM08to15' , 'ds':'mc12_8TeV.173045.Sherpa_CT10_DYtautauM08to15.merge.NTUP_SUSY.e1669_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'173046.Sherpa_CT10_DYtautauM15to40' , 'ds':'mc12_8TeV.173046.Sherpa_CT10_DYtautauM15to40.merge.NTUP_SUSY.e1669_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - ZX__Sherpa_fullsim.sh
    ds_dict_list = [ { 'tag':'147770.Sherpa_CT10_Zee'             , 'ds':'mc12_8TeV.147770.Sherpa_CT10_Zee.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/'             , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'147771.Sherpa_CT10_Zmumu'           , 'ds':'mc12_8TeV.147771.Sherpa_CT10_Zmumu.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/'           , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'147772.Sherpa_CT10_Ztautau'         , 'ds':'mc12_8TeV.147772.Sherpa_CT10_Ztautau.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/'         , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'173041.Sherpa_CT10_DYeeM08to15'     , 'ds':'mc12_8TeV.173041.Sherpa_CT10_DYeeM08to15.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1512/'             , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'173042.Sherpa_CT10_DYeeM15to40'     , 'ds':'mc12_8TeV.173042.Sherpa_CT10_DYeeM15to40.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1512/'             , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'173043.Sherpa_CT10_DYmumuM08to15'   , 'ds':'mc12_8TeV.173043.Sherpa_CT10_DYmumuM08to15.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1512/'           , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'173044.Sherpa_CT10_DYmumuM15to40'   , 'ds':'mc12_8TeV.173044.Sherpa_CT10_DYmumuM15to40.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1512/'           , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'173045.Sherpa_CT10_DYtautauM08to15' , 'ds':'mc12_8TeV.173045.Sherpa_CT10_DYtautauM08to15.merge.NTUP_SUSY.e1669_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'173046.Sherpa_CT10_DYtautauM15to40' , 'ds':'mc12_8TeV.173046.Sherpa_CT10_DYtautauM15to40.merge.NTUP_SUSY.e1669_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - ZX__Sherpa.sh
    ds_dict_list = [ { 'tag':'147770.Sherpa_CT10_Zee'             , 'ds':'mc12_8TeV.147770.Sherpa_CT10_Zee.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/'             , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'147771.Sherpa_CT10_Zmumu'           , 'ds':'mc12_8TeV.147771.Sherpa_CT10_Zmumu.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/'           , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'147772.Sherpa_CT10_Ztautau'         , 'ds':'mc12_8TeV.147772.Sherpa_CT10_Ztautau.merge.NTUP_SUSY.e1434_s1499_s1504_r3658_r3549_p1512/'         , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'173041.Sherpa_CT10_DYeeM08to15'     , 'ds':'mc12_8TeV.173041.Sherpa_CT10_DYeeM08to15.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1512/'             , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'173042.Sherpa_CT10_DYeeM15to40'     , 'ds':'mc12_8TeV.173042.Sherpa_CT10_DYeeM15to40.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1512/'             , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'173043.Sherpa_CT10_DYmumuM08to15'   , 'ds':'mc12_8TeV.173043.Sherpa_CT10_DYmumuM08to15.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1512/'           , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'173044.Sherpa_CT10_DYmumuM15to40'   , 'ds':'mc12_8TeV.173044.Sherpa_CT10_DYmumuM15to40.merge.NTUP_SUSY.e1669_a159_a171_r3549_p1512/'           , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'173045.Sherpa_CT10_DYtautauM08to15' , 'ds':'mc12_8TeV.173045.Sherpa_CT10_DYtautauM08to15.merge.NTUP_SUSY.e1669_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'173046.Sherpa_CT10_DYtautauM15to40' , 'ds':'mc12_8TeV.173046.Sherpa_CT10_DYtautauM15to40.merge.NTUP_SUSY.e1669_s1581_s1586_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - ZZ__Jimmy.sh
    ds_dict_list = [ { 'tag':'116600.gg2ZZJimmy_AUET2CT10_ZZ4lep'  , 'ds':'mc12_8TeV.116600.gg2ZZJimmy_AUET2CT10_ZZ4lep.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'116601.gg2ZZJimmy_AUET2CT10_ZZ4e'    , 'ds':'mc12_8TeV.116601.gg2ZZJimmy_AUET2CT10_ZZ4e.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'116603.gg2ZZJimmy_AUET2CT10_ZZ2e2mu' , 'ds':'mc12_8TeV.116603.gg2ZZJimmy_AUET2CT10_ZZ2e2mu.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'116602.gg2ZZJimmy_AUET2CT10_ZZ4mu'   , 'ds':'mc12_8TeV.116602.gg2ZZJimmy_AUET2CT10_ZZ4mu.merge.NTUP_SUSY.e1525_s1499_s1504_r3658_r3549_p1512/'   , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - ZZ__PowhegPythia8.sh
    ds_dict_list = [ { 'tag':'126937.PowhegPythia8_AU2CT10_ZZ_4e_mll4_2pt5'      , 'ds':'mc12_8TeV.126937.PowhegPythia8_AU2CT10_ZZ_4e_mll4_2pt5.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/'      , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'126938.PowhegPythia8_AU2CT10_ZZ_2e2mu_mll4_2pt5'   , 'ds':'mc12_8TeV.126938.PowhegPythia8_AU2CT10_ZZ_2e2mu_mll4_2pt5.merge.NTUP_SUSY.e1280_s1469_s1470_r3752_r3549_p1512/'   , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'126939.PowhegPythia8_AU2CT10_ZZ_2e2tau_mll4_2pt5'  , 'ds':'mc12_8TeV.126939.PowhegPythia8_AU2CT10_ZZ_2e2tau_mll4_2pt5.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'126940.PowhegPythia8_AU2CT10_ZZ_4mu_mll4_2pt5'     , 'ds':'mc12_8TeV.126940.PowhegPythia8_AU2CT10_ZZ_4mu_mll4_2pt5.merge.NTUP_SUSY.e1280_s1469_s1470_r3752_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'126941.PowhegPythia8_AU2CT10_ZZ_2mu2tau_mll4_2pt5' , 'ds':'mc12_8TeV.126941.PowhegPythia8_AU2CT10_ZZ_2mu2tau_mll4_2pt5.merge.NTUP_SUSY.e1280_s1469_s1470_r3752_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'126942.PowhegPythia8_AU2CT10_ZZ_4tau_mll4_2pt5'    , 'ds':'mc12_8TeV.126942.PowhegPythia8_AU2CT10_ZZ_4tau_mll4_2pt5.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'126949.PowhegPythia8_AU2CT10_ZZllnunu_ee_mll4'     , 'ds':'mc12_8TeV.126949.PowhegPythia8_AU2CT10_ZZllnunu_ee_mll4.merge.NTUP_SUSY.e1280_s1469_s1470_r3752_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'126950.PowhegPythia8_AU2CT10_ZZllnunu_mm_mll4'     , 'ds':'mc12_8TeV.126950.PowhegPythia8_AU2CT10_ZZllnunu_mm_mll4.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'126951.PowhegPythia8_AU2CT10_ZZllnunu_tt_mll4'     , 'ds':'mc12_8TeV.126951.PowhegPythia8_AU2CT10_ZZllnunu_tt_mll4.merge.NTUP_SUSY.e1280_s1469_s1470_r3542_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # bkg - ZZ__Sherpa.sh
    ds_dict_list = [ { 'tag':'157814.Sherpa_CT10_VVtoeeqq'     , 'ds':'mc12_8TeV.157814.Sherpa_CT10_VVtoeeqq.merge.NTUP_SUSY.e1515_s1499_s1504_r3658_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157815.Sherpa_CT10_VVtomumuqq'   , 'ds':'mc12_8TeV.157815.Sherpa_CT10_VVtomumuqq.merge.NTUP_SUSY.e1515_s1499_s1504_r3658_r3549_p1512/'   , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157816.Sherpa_CT10_VVtotautauqq' , 'ds':'mc12_8TeV.157816.Sherpa_CT10_VVtotautauqq.merge.NTUP_SUSY.e1515_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # signal - simplified_wA_signal_grids.sh
    ds_dict_list = [ { 'tag':'144871.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_5'  , 'ds':'mc12_8TeV.144871.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_5.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144873.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_7'  , 'ds':'mc12_8TeV.144873.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_7.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144874.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_8'  , 'ds':'mc12_8TeV.144874.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_8.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144876.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_10' , 'ds':'mc12_8TeV.144876.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_10.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144877.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_11' , 'ds':'mc12_8TeV.144877.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_11.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144879.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_13' , 'ds':'mc12_8TeV.144879.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_13.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144880.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_14' , 'ds':'mc12_8TeV.144880.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_14.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144881.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_15' , 'ds':'mc12_8TeV.144881.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_15.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144883.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_17' , 'ds':'mc12_8TeV.144883.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_17.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144884.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_18' , 'ds':'mc12_8TeV.144884.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_18.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144885.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_19' , 'ds':'mc12_8TeV.144885.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_19.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144886.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_20' , 'ds':'mc12_8TeV.144886.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_20.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144888.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_22' , 'ds':'mc12_8TeV.144888.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_22.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144889.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_23' , 'ds':'mc12_8TeV.144889.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_23.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144890.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_24' , 'ds':'mc12_8TeV.144890.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_24.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144891.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_25' , 'ds':'mc12_8TeV.144891.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_25.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144892.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_26' , 'ds':'mc12_8TeV.144892.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_26.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144894.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_28' , 'ds':'mc12_8TeV.144894.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_28.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144895.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_29' , 'ds':'mc12_8TeV.144895.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_29.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'144896.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_30' , 'ds':'mc12_8TeV.144896.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_30.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157461.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_32' , 'ds':'mc12_8TeV.157461.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_32.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157464.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_35' , 'ds':'mc12_8TeV.157464.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_35.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157467.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_38' , 'ds':'mc12_8TeV.157467.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_38.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157954.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_39' , 'ds':'mc12_8TeV.157954.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_39.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157955.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_40' , 'ds':'mc12_8TeV.157955.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_40.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157956.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_41' , 'ds':'mc12_8TeV.157956.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_41.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157957.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_42' , 'ds':'mc12_8TeV.157957.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_42.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157958.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_43' , 'ds':'mc12_8TeV.157958.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_43.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157959.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_44' , 'ds':'mc12_8TeV.157959.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_44.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157960.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_45' , 'ds':'mc12_8TeV.157960.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_45.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157961.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_46' , 'ds':'mc12_8TeV.157961.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_46.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157962.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_47' , 'ds':'mc12_8TeV.157962.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_47.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157963.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_48' , 'ds':'mc12_8TeV.157963.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_48.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157964.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_49' , 'ds':'mc12_8TeV.157964.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_49.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157965.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_50' , 'ds':'mc12_8TeV.157965.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_50.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157966.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_51' , 'ds':'mc12_8TeV.157966.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_51.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157967.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_52' , 'ds':'mc12_8TeV.157967.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_52.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'157968.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_53' , 'ds':'mc12_8TeV.157968.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcascade_53.merge.NTUP_SUSY.e1417_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176531.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_54'    , 'ds':'mc12_8TeV.176531.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_54.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176532.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_55'    , 'ds':'mc12_8TeV.176532.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_55.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176533.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_56'    , 'ds':'mc12_8TeV.176533.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_56.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176534.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_57'    , 'ds':'mc12_8TeV.176534.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_57.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176535.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_58'    , 'ds':'mc12_8TeV.176535.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_58.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176536.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_59'    , 'ds':'mc12_8TeV.176536.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_59.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176537.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_60'    , 'ds':'mc12_8TeV.176537.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_60.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176538.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_61'    , 'ds':'mc12_8TeV.176538.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_61.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176539.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_62'    , 'ds':'mc12_8TeV.176539.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_62.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176540.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_63'    , 'ds':'mc12_8TeV.176540.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_63.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176541.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_64'    , 'ds':'mc12_8TeV.176541.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_64.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176542.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_65'    , 'ds':'mc12_8TeV.176542.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_65.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176543.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_66'    , 'ds':'mc12_8TeV.176543.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_66.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176544.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_67'    , 'ds':'mc12_8TeV.176544.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_67.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176545.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_68'    , 'ds':'mc12_8TeV.176545.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_68.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176546.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_69'    , 'ds':'mc12_8TeV.176546.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_69.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176547.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_70'    , 'ds':'mc12_8TeV.176547.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_70.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176548.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_71'    , 'ds':'mc12_8TeV.176548.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_71.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176549.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_72'    , 'ds':'mc12_8TeV.176549.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_72.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176550.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_73'    , 'ds':'mc12_8TeV.176550.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_73.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176551.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_74'    , 'ds':'mc12_8TeV.176551.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_74.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176552.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_75'    , 'ds':'mc12_8TeV.176552.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_75.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176553.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_76'    , 'ds':'mc12_8TeV.176553.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_76.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176554.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_77'    , 'ds':'mc12_8TeV.176554.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_77.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176555.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_78'    , 'ds':'mc12_8TeV.176555.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_78.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176556.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_79'    , 'ds':'mc12_8TeV.176556.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_79.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'179580.Herwigpp_UEEE3_CTEQ6L1_sM_wA_slep_C1N2_192_5_N1_157_5_2L'     , 'ds':'mc12_8TeV.179580.Herwigpp_UEEE3_CTEQ6L1_sM_wA_slep_C1N2_192_5_N1_157_5_2L.merge.NTUP_SUSY.e2118_s1499_s1504_r3658_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'179583.Herwigpp_UEEE3_CTEQ6L1_sM_wA_slep_C1N2_260_0_N1_240_0_2L'     , 'ds':'mc12_8TeV.179583.Herwigpp_UEEE3_CTEQ6L1_sM_wA_slep_C1N2_260_0_N1_240_0_2L.merge.NTUP_SUSY.e2118_s1499_s1504_r3658_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'179579.Herwigpp_UEEE3_CTEQ6L1_sM_wA_slep_C1N2_142_5_N1_107_5_2L'     , 'ds':'mc12_8TeV.179579.Herwigpp_UEEE3_CTEQ6L1_sM_wA_slep_C1N2_142_5_N1_107_5_2L.merge.NTUP_SUSY.e2118_s1499_s1504_r3658_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'179582.Herwigpp_UEEE3_CTEQ6L1_sM_wA_slep_C1N2_185_0_N1_165_0_2L'     , 'ds':'mc12_8TeV.179582.Herwigpp_UEEE3_CTEQ6L1_sM_wA_slep_C1N2_185_0_N1_165_0_2L.merge.NTUP_SUSY.e2118_s1499_s1504_r3658_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'179581.Herwigpp_UEEE3_CTEQ6L1_sM_wA_slep_C1N2_135_0_N1_115_0_2L'     , 'ds':'mc12_8TeV.179581.Herwigpp_UEEE3_CTEQ6L1_sM_wA_slep_C1N2_135_0_N1_115_0_2L.merge.NTUP_SUSY.e2118_s1499_s1504_r3658_r3549_p1512/'     , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'179578.Herwigpp_UEEE3_CTEQ6L1_sM_wA_slep_C1N2_117_5_N1_82_5_2L'      , 'ds':'mc12_8TeV.179578.Herwigpp_UEEE3_CTEQ6L1_sM_wA_slep_C1N2_117_5_N1_82_5_2L.merge.NTUP_SUSY.e2118_s1499_s1504_r3658_r3549_p1512/'      , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'176557.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_80'    , 'ds':'mc12_8TeV.176557.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_slep_noWcasc_80.merge.NTUP_SUSY.e1708_s1499_s1504_r3658_r3549_p1512/'    , 'is_data':0 , 'is_full_mc':1 }
                   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                   , { 'tag':'164274.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_1'  , 'ds':'mc12_8TeV.164274.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_1.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164275.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_2'  , 'ds':'mc12_8TeV.164275.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_2.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164276.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_3'  , 'ds':'mc12_8TeV.164276.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_3.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164277.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_4'  , 'ds':'mc12_8TeV.164277.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_4.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164278.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_5'  , 'ds':'mc12_8TeV.164278.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_5.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164279.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_6'  , 'ds':'mc12_8TeV.164279.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_6.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164280.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_7'  , 'ds':'mc12_8TeV.164280.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_7.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164281.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_8'  , 'ds':'mc12_8TeV.164281.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_8.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164282.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_9'  , 'ds':'mc12_8TeV.164282.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_9.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/'  , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164283.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_10' , 'ds':'mc12_8TeV.164283.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_10.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164284.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_11' , 'ds':'mc12_8TeV.164284.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_11.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164285.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_12' , 'ds':'mc12_8TeV.164285.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_12.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164286.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_13' , 'ds':'mc12_8TeV.164286.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_13.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164287.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_14' , 'ds':'mc12_8TeV.164287.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_14.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164288.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_15' , 'ds':'mc12_8TeV.164288.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_15.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164289.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_16' , 'ds':'mc12_8TeV.164289.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_16.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164290.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_17' , 'ds':'mc12_8TeV.164290.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_17.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164291.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_18' , 'ds':'mc12_8TeV.164291.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_18.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164292.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_19' , 'ds':'mc12_8TeV.164292.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_19.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164293.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_20' , 'ds':'mc12_8TeV.164293.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_20.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164294.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_21' , 'ds':'mc12_8TeV.164294.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_21.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164295.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_22' , 'ds':'mc12_8TeV.164295.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_22.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164296.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_23' , 'ds':'mc12_8TeV.164296.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_23.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164297.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_24' , 'ds':'mc12_8TeV.164297.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_24.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164298.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_25' , 'ds':'mc12_8TeV.164298.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_25.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164299.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_26' , 'ds':'mc12_8TeV.164299.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_26.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164300.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_27' , 'ds':'mc12_8TeV.164300.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_27.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164301.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_28' , 'ds':'mc12_8TeV.164301.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_28.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164302.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_29' , 'ds':'mc12_8TeV.164302.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_29.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164303.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_30' , 'ds':'mc12_8TeV.164303.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_30.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164304.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_31' , 'ds':'mc12_8TeV.164304.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_31.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164305.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_32' , 'ds':'mc12_8TeV.164305.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_32.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164306.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_33' , 'ds':'mc12_8TeV.164306.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_33.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164307.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_34' , 'ds':'mc12_8TeV.164307.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_34.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164308.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_35' , 'ds':'mc12_8TeV.164308.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_35.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164309.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_36' , 'ds':'mc12_8TeV.164309.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_36.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164310.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_37' , 'ds':'mc12_8TeV.164310.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_37.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164311.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_38' , 'ds':'mc12_8TeV.164311.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_38.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164312.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_39' , 'ds':'mc12_8TeV.164312.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_39.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164313.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_40' , 'ds':'mc12_8TeV.164313.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_40.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164314.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_41' , 'ds':'mc12_8TeV.164314.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_41.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164315.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_42' , 'ds':'mc12_8TeV.164315.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_42.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164316.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_43' , 'ds':'mc12_8TeV.164316.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_43.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164317.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_44' , 'ds':'mc12_8TeV.164317.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_44.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164318.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_45' , 'ds':'mc12_8TeV.164318.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_45.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164319.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_46' , 'ds':'mc12_8TeV.164319.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_46.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164320.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_47' , 'ds':'mc12_8TeV.164320.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_47.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164321.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_48' , 'ds':'mc12_8TeV.164321.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_48.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164322.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_49' , 'ds':'mc12_8TeV.164322.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_49.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   , { 'tag':'164323.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_50' , 'ds':'mc12_8TeV.164323.Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA_noslep_lepW_50.merge.NTUP_SUSY.e1461_s1499_s1504_r3658_r3549_p1512/' , 'is_data':0 , 'is_full_mc':1 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

    # ------------------------------------------------------------------------------
    # signal - simplified_wA_signal_grids.sh
    ds_dict_list = [ { 'tag':'202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000' , 'ds':'mc12_8TeV.202641.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_1000.merge.e2808_a220_a205_r4540_p1512/' , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'202640.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_900'  , 'ds':'mc12_8TeV.202640.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_900.merge.e2808_a220_a205_r4540_p1512/'  , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'202639.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_800'  , 'ds':'mc12_8TeV.202639.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_800.merge.e2808_a220_a205_r4540_p1512/'  , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'202638.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_700'  , 'ds':'mc12_8TeV.202638.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_700.merge.e2808_a220_a205_r4540_p1512/'  , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'202637.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_600'  , 'ds':'mc12_8TeV.202637.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_600.merge.e2808_a220_a205_r4540_p1512/'  , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'202636.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_500'  , 'ds':'mc12_8TeV.202636.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_500.merge.e2808_a220_a205_r4540_p1512/'  , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'202635.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_400'  , 'ds':'mc12_8TeV.202635.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_400.merge.e2808_a220_a205_r4540_p1512/'  , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'202634.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_300'  , 'ds':'mc12_8TeV.202634.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_300.merge.e2808_a220_a205_r4540_p1512/'  , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'202633.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_200'  , 'ds':'mc12_8TeV.202633.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_200.merge.e2808_a220_a205_r4540_p1512/'  , 'is_data':0 , 'is_full_mc':0 }
                   , { 'tag':'202632.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_100'  , 'ds':'mc12_8TeV.202632.MadGraphPythia_AUET2B_CTEQ6L1_SM_TT_directBL_100.merge.e2808_a220_a205_r4540_p1512/'  , 'is_data':0 , 'is_full_mc':0 }
                   ]
    job_num = submitFromList(ds_dict_list, tnt_tag, job_num)

