#!/bin/bash

DATA_MC=data
STREAM=egamma
VERSION_FLAG=presel.51

ds_list=( ##"Egamma.periodA."
          ##"Egamma.periodB."
          ##"Egamma.periodC."
          ##"Egamma.periodD."
          "Egamma.periodE."
          ##"Egamma.periodG."
          ##"Egamma.periodH."
          ##"Egamma.periodI."
          ##"Egamma.periodJ."
          ##"Egamma.periodL."
        )

for sample in ${ds_list[@]}
do 
  echo '---------------------------------------'
  echo $sample
  ./gen_job_configs.sh --${DATA_MC} --${STREAM} --sample-name $sample --version ${VERSION_FLAG}
done
