#!/bin/bash

lep_pt=$1
jet_pt=$2
met_cut=$3

dir_name="output/out_2014-03-24/lep_pt_${lep_pt}__b_pt_${jet_pt}__met_${met_cut}/"

echo '--------------------------------------------------------------------------------'
echo "lep pt: $lep_pt -- jet pt: $jet_pt -- met: $met_cut"
for file_name in $(ls $dir_name) ; do
  echo '- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -'
  echo $file_name
  file_name_without_cuts=$(echo $file_name | sed "s#__lep_pt_.*__jet_pt_.*__met_.*\.hists#.hists#g")
  echo $file_name_without_cuts

  ln -s ${dir_name}/${file_name} ${file_name_without_cuts}
done
