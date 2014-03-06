#!/bin/bash

MASTER_DIR=/afs/cern.ch/user/b/bjackson/my_eos/tnt.010.v3/
for job in $(ls ${MASTER_DIR} | grep data | ${REMOVE_COLOR});
do
  tag=$(echo $job | sed 's/data_12_8TeV\.\(.*\)/\1/g')
  ./MakeFakeNtuple --force --dir ${MASTER_DIR}/$job/
  mv fake_ntuple.root fake_ntuple.${tag}.root
done
