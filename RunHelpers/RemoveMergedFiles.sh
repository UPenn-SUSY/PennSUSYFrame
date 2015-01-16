# Remove all merged optimization ntuple files 
# Usage: ./RunHelpers/RemoveMergedFiles.sh

for each in $(\ls NextOptNtupDir.BMinusL*/*.0_of_*.root) ; do
  tag=$(echo $each | sed 's#0_of_[0-9]*\.##g')
  if [[ -f $tag ]] ; then
    echo "Removing file: $tag"
    rm -f $tag
  fi
  echo ''
done
