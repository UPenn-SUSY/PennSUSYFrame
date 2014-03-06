#!/bin/bash

SERHAN_FILE=${1}
if [[ ${SERHAN_FILE} == "" ]]
then
  echo "Please provide a file name"
else
  echo "Reading file: $SERHAN_FILE"
  tail -n+3 ${SERHAN_FILE} | sort | awk '{split($4, a, "*") ; print $1 "\tmodel_" $1 "\t" a[1]*a[2]*a[3] "\t1.0\t1.0\t1.0"}' 
fi
