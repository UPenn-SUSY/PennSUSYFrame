#!/bin/bash

# ==========================
# = parse input parameters =
# ==========================
USER_NAME=$AFS_USER_NAME
OUT_DS_VERSION=''
while [ "$1" != "" ]; do
  case $1 in
    --user-name ) shift
                  USER_NAME=$1
                  ;;
    --ver )       shift
                  OUT_DS_VERSION=$1
                  ;;
    * )           echo 'invalid option'
                  return
  esac
  shift
done

# ========================
# = add common ext files =
# ========================
COMMON_EXT_FILES="data/data12_8TeV.periodAllYear_DetStatus-v58-pro14-01_DQDefects-00-00-33_PHYS_StandardGRL_All_Good.xml"
if [[ "${EXT_FILES}" == '' ]]; then
  EXT_FILES=${COMMON_EXT_FILES}
else
  EXT_FILES="${EXT_FILES},${COMMON_EXT_FILES}"
fi

# ===================
# = validate inputs =
# ===================
if [[ "${USER_NAME}" == '' ]]; then
  echo "User name must be supplied!"
  echo "Either define \$AFS_USER_NAME as an envinonment variable, or use the --user-name flag" 
  return 
fi
if [[ "${OUT_DS_VERSION}" == '' ]]; then
  echo "Please supply a version for the output data set for book keeping purposes"
  return
fi

TAR_BALL_NAME=cutflow_tar.${OUT_DS_VERSION}.tar.gz
echo "Using tar ball with the name: ${TAR_BALL_NAME}"

for hash in ${ds_list[@]} ; do
  echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
  echo $hash
  KEY=${hash%%:*}
  IN_DS=${hash##*:}
  
  echo "KEY: " $KEY
  echo "IN_DS: " $IN_DS
  echo ""
  
  out_file=''
  if [[ "${DATA_MC}" == 'data' ]]; then
    out_file="SusyDiLeptonCutFlowCycle.data.ver_1.cut_flow..root"
  elif [[ "${DATA_MC}" == 'mc' ]]; then
    out_file="SusyDiLeptonCutFlowCycle.mc.ver_1.cut_flow..root"
  fi
  
  out_ds="user.${USER_NAME}.${OUT_DS_PREFIX}.${KEY}.tnt.${OUT_DS_VERSION}/"
  
  echo "out_file: " ${out_file}
  echo "outDS: " ${out_ds}
  
  prun \
    --bexec=grid_build.sh \
    --exec="grid_run_cutflow.sh \
            --type ${DATA_MC} \
            --${STREAM} \
            --${SIM_TYPE} \
            --data-set %IN \
           " \
    --useRootCore \
    --inDS=${IN_DS} \
    --outDS=${out_ds} \
    --nGBPerJob=MAX \
    --rootVer=5.34/07 \
    --cmtConfig=x86_64-slc5-gcc43-opt \
    --extFile=${EXT_FILES} \
    --inTarBall=${TAR_BALL_NAME} \
    --outputs=${out_file} \
    --excludedSite=ANALY_FREIBURG,ANALY_AGLT2,ANALY_IN2P3-CC-T2,ANALY_MPPMU,ANALY_JINR,ANALY_RAL_XROOTD,ANALY_MANC,ANALY_INFN-FRASCATI,ANALY_INFN-ROMA1,ANALY_UAM,ANALY_RAL 
   
    
done
