#!/bin/bash

# ----------------------------------------------------------------------------
# core SFrame package
echo "Checking out SFrame package"
svn co https://sframe.svn.sourceforge.net/svnroot/sframe/SFrame/tags/SFrame-03-06-05/ SFrame
mkdir SFrame/lib

# ----------------------------------------------------------------------------
# RootCore package
echo "Checking out RootCore package"
mkdir RootCore
cd RootCore
if [ "x$CERN_USER" = "x" ]; then
  svn co svn+ssh://svn.cern.ch/reps/atlasoff/PhysicsAnalysis/D3PDTools/RootCore/tags/RootCore-00-01-45 RootCore
  # svn co svn+ssh://svn.cern.ch/reps/atlasoff/PhysicsAnalysis/D3PDTools/RootCore/tags/RootCore-00-00-31 RootCore
else
  svn co svn+ssh://${CERN_USER}@svn.cern.ch/reps/atlasoff/PhysicsAnalysis/D3PDTools/RootCore/tags/RootCore-00-01-45 RootCore
fi
cd RootCore

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
echo "Configuring RootCore package"
./configure
cat Makefile-common | sed 's/-install_name @rpath\/lib$(PACKAGE).so/-undefined dynamic_lookup/g' > Makefile-common-temp
cp Makefile-common-temp Makefile-common

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
cd ../..
source setup_sframe.sh
cd RootCore

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# check out RootCore packages
echo "Check out RootCore modules"
$ROOTCOREDIR/scripts/checkout.sh ../root_core_packages

# comment out known std::cout statements to avoid massive log files
files="GoodRunsLists/Root/DQHelperFunctions.cxx
GoodRunsLists/Root/TGoodRunsList.cxx
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
${ROOTCOREDIR}/scripts/build.sh
mv RootCore.par ${SFRAME_LIB_PATH}
cd ${SFRAME_DIR}/..
