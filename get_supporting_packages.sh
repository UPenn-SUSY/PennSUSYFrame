#!/bin/bash

BASE_WORK_DIR=${PWD}

## # ----------------------------------------------------------------------------
## # core SFrame package
## echo "Checking out SFrame package"
## svn co https://svn.code.sf.net/p/sframe/code/SFrame/tags/SFrame-03-06-21/ SFrame
## mkdir SFrame/lib

# ------------------------------------------------------------------------------
# SUSYTools
echo "Checking out SUSYTools"
if [[ ! -e RootCore ]] ; then
  mkdir RootCore
fi
cd RootCore
if [ "x$CERN_USER" = "x" ]; then
  svn co svn+ssh://svn.cern.ch/reps/atlasoff/PhysicsAnalysis/SUSYPhys/SUSYTools/tags/SUSYTools-00-03-14 SUSYTools
else
  svn co svn+ssh://${CERN_USER}@svn.cern.ch/reps/atlasoff/PhysicsAnalysis/SUSYPhys/SUSYTools/tags/SUSYTools-00-03-14 SUSYTools
fi
python SUSYTools/python/install.py

# ------------------------------------------------------------------------------
# get updated version of PATCore - fixes bug in Mac OS 10.9
# TODO remove this section when SUSYTools updates PATCore
echo "Removing default PATCore"
rm -rf PATCore
echo "Removing default GoodRunsLists"
rm -rf GoodRunsLists
echo "Installing updated version of PATCore"
svn co svn+ssh://svn.cern.ch/reps/atlasoff/PhysicsAnalysis/AnalysisCommon/PATCore/tags/PATCore-00-00-16 PATCore
echo "Installing updated version of GoodRunsLists"
svn co svn+ssh://svn.cern.ch/reps/atlasoff/DataQuality/GoodRunsLists/tags/GoodRunsLists-00-01-09 GoodRunsLists

# ------------------------------------------------------------------------------
# Setup RootCore
echo "Setting up RootCore"
cd RootCore
./configure
source scripts/setup.sh
cd ..
$ROOTCOREDIR/scripts/find_packages.sh
$ROOTCOREDIR/scripts/compile.sh
$ROOTCOREDIR/scripts/build.sh
cd ..

# # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# source setup_sframe.sh

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# check out additional RootCore packages
echo "Check out additional RootCore modules"
cd ${ROOTCOREDIR}/..
# cd ${BASE_WORK_DIR}/RootCore
for module in $(cat ../root_core_packages) ; do
  echo "module: $module"
  module_short=$(echo $module | sed 's#-.*##g' | sed 's#.*/##g')
  if [[ $module_short == "trunk" ]] ; then
    module_short=$(echo $module | sed "s#/trunk##g" | sed "s#.*/##g")
  fi
  echo "module short: $module_short"
  if [ "x$CERN_USER" = "x" ]; then
    svn co svn+ssh://svn.cern.ch/reps/$module $module_short
  else
    svn co svn+ssh://${CERN_USER}@svn.cern.ch/reps/$module $module_short
  fi
done
cd ${BASE_WORK_DIR}

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# comment out known std::cout statements to avoid massive log files
files="GoodRunsLists/Root/TGoodRunsList.cxx
       SUSYTools/Root/mt2_bisect.cxx
       LeptonTruthTools/Root/RecoTruthMatch.cxx"
for f in $files
do
  # cat $f | sed 's, std::cout, \/\/ std::cout,g' > $f.temp
  cat $f | sed 's,^\(\s\+\)\(.* std::cout.*\)$,\1\/\/ \2,g' > $f.temp
  mv $f.temp $f
done

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# build RootCore packages
cd ${ROOTCOREDIR}/..
echo "Preparing to build RootCore packages"
$ROOTCOREDIR/scripts/find_packages.sh
$ROOTCOREDIR/scripts/compile.sh
$ROOTCOREDIR/scripts/build.sh

echo "Build finished! Moving RootCore.par to proper location"
cd ${ROOTCOREDIR}/..
# mv RootCore.par ${SFRAME_LIB_PATH}
if [[ ! -e ${BASE_WORK_DIR}/lib ]] ; then
  mkdir ${BASE_WORK_DIR}/lib
fi
mv RootCore.par ${BASE_WORK_DIR}/lib

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# check out MultiLep/data
if [[ ! -e MultiLep ]] ; then
  mkdir MultiLep
fi
cd MultiLep
svn co svn+ssh://svn.cern.ch/reps/atlasphys/Physics/SUSY/Analyses/WeakProduction/MultiLep/tags/MultiLep-01-06-03/data

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
echo "Back to base working directory"
cd ${BASE_WORK_DIR}
