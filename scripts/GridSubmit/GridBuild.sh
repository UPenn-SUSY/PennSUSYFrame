#!/bin/bash

echo "========================================================================="

# # Clean up/rebuild RootCore packages to ensure they are build for the correct
# # environment
# echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
# echo "going to RootCore"
# cd RootCore/RootCore
# ls
# 
# echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
# echo "configuring RootCore"
# ./configure
# echo "========================================================================="
# echo "Going back to base work dir"
# cd ../..

# setup work dir
echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
echo "about to set up SFrame"
source SetupEnvironment.sh

#clean up/rebuild rest of packages 
echo "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
echo "about to make clean"
make clean
echo "about to make"
make
