#!/bin/bash

job_config_list=(
##  'job_config.cut_flow.Egamma.periodA..yml'
##  'job_config.cut_flow.Egamma.periodB..yml'
##  'job_config.cut_flow.Egamma.periodC..yml'
##  'job_config.cut_flow.Egamma.periodD..yml'
##  'job_config.cut_flow.Egamma.periodE..yml'
    'job_config.cut_flow.Z_plus_jet.107655.AlpgenJimmy_AUET2CTEQ6L1_ZeeNp5.yml'
)

for jc in ${job_config_list[@]}
do
  echo $jc
  sframe_command=`python ../../scripts/run_scripts/gen_susy_dilepton_config.py $jc | grep sframe_main`
  echo $sframe_command
  $sframe_command
done
