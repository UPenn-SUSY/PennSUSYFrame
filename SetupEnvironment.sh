#!/bin/bash

DO_ROOTCORE=$1
if [[ $DO_ROOTCORE != "0" ]] ; then
  DO_ROOTCORE="1"
fi

# Allow for the ability to turn off RootCore if we don't need it, or don't have
# it set up properly
if [[ $DO_ROOTCORE == "1" ]] ; then
  cd RootCore/RootCore
  # ./configure
  source scripts/setup.sh
  cd ../../
fi

export BASE_WORK_DIR=${PWD}
