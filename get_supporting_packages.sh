#!/bin/bash

# ----------------------------------------------------------------------------
# core SFrame package
echo "Checking out SFrame package"
svn co https://svn.code.sf.net/p/sframe/code/SFrame/tags/SFrame-03-06-21/ SFrame
mkdir SFrame/lib

# ------------------------------------------------------------------------------
# SUSYTools
echo "Checking out SUSYTools"
mkdir RootCore
cd RootCore
if [ "x$CERN_USER" = "x" ]; then
  svn co svn+ssh://svn.cern.ch/reps/atlasoff/PhysicsAnalysis/SUSYPhys/SUSYTools/tags/SUSYTools-00-03-13 SUSYTools
else
  svn co svn+ssh://${CERN_USER}@svn.cern.ch/reps/atlasoff/PhysicsAnalysis/SUSYPhys/SUSYTools/tags/SUSYTools-00-03-13 SUSYTools
fi
python SUSYTools/python/install.py

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

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
source setup_sframe.sh

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# check out RootCore packages
echo "Check out RootCore modules"
cd ${ROOTCOREDIR}/..
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
cd ${SFRAME_DIR}/..

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
mv RootCore.par ${SFRAME_LIB_PATH}

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
echo "Back to SFRAME_DIR"
cd ${SFRAME_DIR}/..

