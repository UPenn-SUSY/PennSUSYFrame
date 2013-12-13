#!/bin/bash

echo "========================================================================="
printenv
echo "========================================================================="

# Clean up/rebuild RootCore packages to ensure they are build for the correct
# environment
echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
echo "going to RootCore"
# cd RootCore
cd RootCore/RootCore
ls

echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
echo "configuring RootCore"
echo "contents of scripts/build.sh"
cat scripts/build.sh
./configure
echo "========================================================================="
printenv
echo "========================================================================="
echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
echo "contents of scripts/build.sh"
cat scripts/build.sh
# cd ..
cd ../..
echo "========================================================================="
printenv
echo "========================================================================="

# setup SFrame and RootCore
echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
echo "about to set up SFrame"
source setup_sframe.sh

echo "========================================================================="
printenv
echo "========================================================================="

# cd RootCore
# echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
# echo "cleaning RootCore packages"
# # source scripts/clean.sh
# cd $ROOTCOREDIR
# echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
# echo "building RootCore packages"
# # source scripts/build.sh
# echo "done building RootCore packages"
# echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
# echo "going back a directory"
# cd ..

#clean up/rebuild rest of packages 
echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
echo "creating ./proof directory because some grid sites want it"
# mkdir proof
echo "about to make distclean"
make distclean
echo "about to make"
make
