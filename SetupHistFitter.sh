#!/bin/sh

HISTFITTER_VERSION="HistFitter-00-00-39-branch"
echo "Checking out HistFitter version $HISTFITTER_VERSION"

# Checkout HistFitter
svn co svn+ssh://$USER@svn.cern.ch/reps/atlasphys/Physics/SUSY/Analyses/HistFitter/branches/$HISTFITTER_VERSION HistFitter

# move to HistFitter directory and build
cd HistFitter
source setup.sh
cd src
make
cd ..

