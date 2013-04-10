#!/bin/bash
# ==============================================================================
# ==============================================================================
# = usage
# =   source submit_all_samples.sh <version_tag>
# ==============================================================================

VERSION=$1
if [ "x${VERSION}" == "x" ]
then
  echo "Please provide a version number"
  echo "usage:"
  echo "  source submit_all_samples.sh <version_tag>"
else
  for each in `ls submit_*sh | ${REMOVE_COLOR}`
  do
    if [[  $each == submit_cutflow.sh     \
        || $each == submit_presel.sh      \
        || $each == submit_all_samples.sh \
      ]] 
    then
      continue 
    fi 
    echo "---------------------------------------------------------------------"
    echo "Submitting: $each"
    source $each --user ${USER} --ver ${VERSION}
  done
fi
