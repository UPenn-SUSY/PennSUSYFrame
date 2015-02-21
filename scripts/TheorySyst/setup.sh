# Base setup for cvmfs-based work
export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
source $ATLAS_LOCAL_ROOT_BASE/user/atlasLocalSetup.sh

# Set up ROOT
localSetupROOT 5.34.18-x86_64-slc6-gcc4.7
localSetupPandaClient
