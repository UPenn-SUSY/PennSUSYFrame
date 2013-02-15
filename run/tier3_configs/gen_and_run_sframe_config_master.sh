#!/bin/bash

job_config_list=(
##  'job_config.cut_flow.Egamma.periodA..yml'
##  'job_config.cut_flow.Egamma.periodB..yml'
##  'job_config.cut_flow.Egamma.periodC..yml'
##  'job_config.cut_flow.Egamma.periodD..yml'
    'job_config.cut_flow.Egamma.periodE..yml'
##    'job_config.cut_flow.Egamma.periodG..yml'
##    'job_config.cut_flow.Egamma.periodH..yml'
##    'job_config.cut_flow.Egamma.periodI..yml'
##    'job_config.cut_flow.Egamma.periodJ..yml'
##    'job_config.cut_flow.Egamma.periodL..yml'
##    'job_config.cut_flow.Z_plus_jet.107650.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp0.yml'
##    'job_config.cut_flow.Z_plus_jet.107651.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp1.yml'
##    'job_config.cut_flow.Z_plus_jet.107652.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp2.yml'
##    'job_config.cut_flow.Z_plus_jet.107653.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp3.yml'
##    'job_config.cut_flow.Z_plus_jet.107654.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp4.yml'
##    'job_config.cut_flow.Z_plus_jet.107655.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp5.yml'
)

for jc in ${job_config_list[@]}
do
  echo $jc
  sframe_command=`python ../../scripts/run_scripts/gen_susy_dilepton_config.py $jc | grep sframe_main`
  echo $sframe_command
  $sframe_command
done
