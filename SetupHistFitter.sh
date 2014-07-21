#!/bin/sh

HISTFITTER_VERSION="HistFitter-00-00-39-branch"
echo "Checking out HistFitter version $HISTFITTER_VERSION"

svn co svn+ssh://$USER@svn.cern.ch/reps/atlasphys/Physics/SUSY/Analyses/HistFitter/branches/$HISTFITTER_VERSION HistFitter

echo "Linking HistFitter config files to HistFitter dir:"
echo "BMinusL..."
ln -s ${BASE_WORK_DIR}/BMinusLAnalysis/LimitSetting/BMinusLLimitConfig.py HistFitter/python/
