#!/bin/bash

DATA_MC=''
IS_AF2='False'
IS_EGAMMA='True'
SAMPLE_NAME=''
VERSION='1'
while [ "$1" != "" ]; do
  case $1 in
    --data )        DATA_MC='data'
                    ;;
    --mc )          DATA_MC='mc'
                    ;;
    --af2 )         IS_AF2='True'
                    ;;
    --egamma )      IS_EGAMMA='True'
                    ;;
    --muon )        IS_EGAMMA='False'
                    ;;
    --sample-name ) shift
                    SAMPLE_NAME=$1
                    ;;
    --version )     shift
                    VERSION=$1
                    ;;
    * )             echo "$1 is an invalid flag"
  esac
  shift
done

if [[ "${SAMPLE_NAME}" == '' ]]
then
  echo "Invalid sample name"
  exit 0
fi

CONFIG_FILE="job_config.cut_flow.${SAMPLE_NAME}.yml"
echo "config file: ${CONFIG_FILE}"

BASE_IN_FILE_PATH=/exports/project/data_d07_4/bjackson/
if [[ "${DATA_MC}" == "data" ]]
then
  BASE_IN_FILE_PATH="${BASE_IN_FILE_PATH}/data12/"
else
  BASE_IN_FILE_PATH="${BASE_IN_FILE_PATH}/mc12/"
fi
echo "Setting in file path to:"
echo "    ${BASE_IN_FILE_PATH}"

echo "" >> $CONFIG_FILE
echo "Type:             ${DATA_MC}" >> $CONFIG_FILE
echo "OutputLevel:      INFO" >> $CONFIG_FILE
echo "OutputDirectory:  /exports/project/data_d07_3/bjackson/Susy_output/00.01.10/" >> $CONFIG_FILE
echo "NEventsMax:       -1" >> $CONFIG_FILE
echo "is_af2:           ${IS_AF2}" >> $CONFIG_FILE
echo "SuperVerboseInfo: False" >> $CONFIG_FILE
echo "PrintEventInfo:   False" >> $CONFIG_FILE
echo "Version:          ${VERSION}" >> $CONFIG_FILE
echo "CycleName:        SusyDiLeptonCutFlowCycle" >> $CONFIG_FILE
echo "SampleName:       ${SAMPLE_NAME}" >> $CONFIG_FILE
echo "" >> $CONFIG_FILE
echo "input_tree_name:  presel" >> $CONFIG_FILE
echo "output_tree_name: output" >> $CONFIG_FILE
echo "is_egamma_stream: ${IS_EGAMMA}" >> $CONFIG_FILE
echo "" >> $CONFIG_FILE
echo "" >> $CONFIG_FILE

if [[ ${DATA_MC} == "data" ]]
then
  echo "UserConfigFile: ${SFRAME_DIR}/../run/pcpenn_configs/user_config.cut_flow.data.yml" >> $CONFIG_FILE
else
  echo "UserConfigFile: ${SFRAME_DIR}/../run/pcpenn_configs/user_config.cut_flow.mc.yml" >> $CONFIG_FILE
fi

echo "InputFiles:" >> $CONFIG_FILE

NUM_FILES=0
for in_file in `ls ${BASE_IN_FILE_PATH}/*${SAMPLE_NAME}*/*root*`; do
  echo "  - ${in_file}" >> $CONFIG_FILE
  let NUM_FILES+=1
done
# echo "  - SusyDiLeptonPreselCycle.MC.ver_1.presel.105200.ttbar_small.2012_11_27.root"

echo "Found $NUM_FILES files"

