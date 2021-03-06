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
COMMON_EXT_FILES=""
COMMON_EXT_FILES="data/data12_8TeV.periodAllYear_DetStatus-v53-pro13-04_CoolRunQuery-00-04-08_All_Good_HCP.xml"
COMMON_EXT_FILES="${COMMON_EXT_FILES},data/ilumicalc_histograms_EF_2e12Tvh_loose1_200842-215643.root"
COMMON_EXT_FILES="${COMMON_EXT_FILES},data/ilumicalc_histograms_EF_2e12Tvh_loose1_200841-210308.root"
COMMON_EXT_FILES="${COMMON_EXT_FILES},data/2013-Winter-rel17.2.1.4_MC12.root"
COMMON_EXT_FILES="${COMMON_EXT_FILES},data/D2012-HCP-noJVF-rel17_MC12a_D2012_HCP.root"

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

OUT_DS="user.${USER_NAME}.cutflow.${OUT_DS_VERSION}/"

TAR_BALL_NAME=cutflow_tar.${OUT_DS_VERSION}.tar.gz
echo "Creating a tar ball with the name: ${TAR_BALL_NAME}"

prun \
  --exec="echo" \
  --useRootCore \
  --outDS=${OUT_DS} \
  --nGBPerJob=MAX \
  --athenaTag=17.3.5 \
  --extFile=${EXT_FILES} \
  --outTarBall=${TAR_BALL_NAME} \
  --noSubmit
