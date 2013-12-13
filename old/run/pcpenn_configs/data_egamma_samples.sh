#!/bin/bash

DATA_MC=data
STREAM=egamma

ds_list=( "Egamma.periodA."
          "Egamma.periodB."
          "Egamma.periodC."
          "Egamma.periodD."
          "Egamma.periodE."
        )

for sample in ${ds_list[@]}
do 
  echo '---------------------------------------'
  echo $sample
  ./gen_job_configs.sh --${DATA_MC} --${STREAM} --sample-name $sample
done
