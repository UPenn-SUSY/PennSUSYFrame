#!/bin/bash

# ==========================
# = parse input parameters =
# ==========================
TYPE=''
STREAM='egamma'
SIM_TYPE=''
JOB_CONFIG_FILE=''
DATA_SET=''
while [ "$1" != "" ]; do
  echo $1
	case $1 in
    # data/MC type
    --type )     shift
                 TYPE=$1
                 ;;
    # full sim or fastsim
    --fullsim  ) SIM_TYPE='fullsim'
                 ;;
    --atlfast )  SIM_TYPE='atlfast'
                 ;;
    # egamma or muon stream
    --egamma )   STREAM='egamma'
                 ;;
    --muon )     STREAM='muon'
                 ;;
    # data set
    --data-set ) shift
                 DATA_SET=$1
                 ;;
    # other optons are invalid
    * )          echo 'invalid option'
                 # exit 1
                 return
	esac
	shift
done

# check data set is valid
if [ "${DATA_SET}" == '' ]; then
  echo "invalid data set"
  # exit 1
fi

# get user options
echo "The data set is: "
echo ${DATA_SET}

IN_FILE_LIST=`echo ${DATA_SET} | sed "s/\,/ /g"`
echo "The file list is: "
echo ${IN_FILE_LIST}

echo "-------------------------------------------------------------------------"
cd SFrame
source setup.sh
cd .. 
echo "-------------------------------------------------------------------------"

# generate config xml files
echo "-------------------------------------------------------------------------"
echo "Generating the config file:"
ARG=""
ARG="${ARG} --type=${TYPE}"
ARG="${ARG} --sample-name=presel"
ARG="${ARG} --${STREAM}"
if [[ ${SIM_TYPE} == "atlfast" ]]; then
  ARG="${ARG} --af2"
fi
ARG=" ${ARG} ${IN_FILE_LIST}"

echo $ARG

python gen_job_config.py $ARG

python ${SFRAME_DIR}/../scripts/run_scripts/gen_susy_dilepton_config.py job_config.yml

echo "-------------------------------------------------------------------------"
ls

echo "-------------------------------------------------------------------------"
echo "jo.presel..ver_1.xml"
echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
cat jo.presel..ver_1.xml

echo "-------------------------------------------------------------------------"
EXE="sframe_main jo.presel..ver_1.xml"
echo "EXE:"
echo ${EXE}

echo "-------------------------------------------------------------------------"
echo "Running the SFrame job:"
${EXE}

echo "-------------------------------------------------------------------------"
ls
