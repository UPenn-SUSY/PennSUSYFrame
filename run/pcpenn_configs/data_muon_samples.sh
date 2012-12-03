#!/bin/bash

DATA_MC=data
STREAM=muon

ds_list=( "Muon.periodA"
          "Muon.periodB"
          "Muon.periodC"
          "Muon.periodD"
          "Muon.periodE"
        )

for sample in ${ds_list[@]}
do 
  echo '---------------------------------------'
  echo $sample
  ./gen_job_configs.sh --${DATA_MC} --${STREAM} --sample-name $sample
done
