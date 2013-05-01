#!/bin/bash

if [[ -e config_list__${DATE_STR}.master.txt ]]
then
  rm config_list__${DATE_STR}.master.txt
fi
if [[ -e config_list__${DATE_STR}.merge.master.txt ]]
then
  rm config_list__${DATE_STR}.merge.master.txt
fi

# for type in cf data fake nominal signal
for type in data fake nominal signal
do
  echo $type
  DATE_STR=$(date +%Y_%m_%d)
  echo "DATE_STR: ${DATE_STR}"

  python ${SFRAME_DIR}/../utils/RunConfigs/scripts/GenerateRunConfigFiles.py  batch_config.${type}.yml
  mv config_list__${DATE_STR}.txt config_list__${DATE_STR}.${type}.txt
  mv config_list__${DATE_STR}.merge.txt config_list__${DATE_STR}.merge.${type}.txt

  cat config_list__${DATE_STR}.${type}.txt       >> config_list__${DATE_STR}.master.txt
  cat config_list__${DATE_STR}.merge.${type}.txt >> config_list__${DATE_STR}.merge.master.txt
done 


