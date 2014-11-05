#!/bin/sh
# ==============================================================================
# = 
# = Usage:
# =     source ../GenerateEosList.sh tnt_102 /eos/atlas/user/b/bjackson/tnt_102
# ==============================================================================

# ==============================================================================
EOS_LIST_PREFIX=${1}
EOS_PATH=${2}
IS_TNT=${3}
if [[ $IS_TNT != 0 ]] ; then
  IS_TNT=1
fi

# ------------------------------------------------------------------------------
echo "EOS_LIST_PREFIX: ${EOS_LIST_PREFIX}"
echo "EOS_PATH: ${EOS_PATH}"
echo "IS_TNT: $IS_TNT"

# ------------------------------------------------------------------------------
function getDSTag {
  EOS_DIR=$1
  ds_tag=''
  if [[ $EOS_DIR == user.bjackson* ]] ; then
    ds_tag=$(echo ${EOS_DIR} | sed "s#user\.bjackson\.\(.*\)\.tnt_.*#\1#g")
  elif [[ $EOS_DIR == mc12* ]] ; then
    ds_tag=$(echo ${EOS_DIR} | sed "s#mc12_8TeV\.\(.*\)\.merge.*#\1#g")
  fi
  echo $ds_tag
}

# ------------------------------------------------------------------------------
function getOutFileName {
  DS_TAG=$1
  out_file_name="${EOS_LIST_PREFIX}.${ds_tag}.txt"
  echo $out_file_name
}

# ==============================================================================
echo '================================================================================'
# initialize counters
total_num_eos_dirs=0
total_num_files=0
total_num_ds=0
total_num_errors=0

# loop through datasets in eos directory
for eos_dir in $(eos ls ${EOS_PATH}); do
  echo '--------------------------------------------------------------------------------'
  echo "eos_dir: $eos_dir"
  if [[ $eos_dir == *.txt ]] ; then
    echo "    text file - skipping"
    continue
  fi

  getDSTag ${eos_dir}
  ds_tag=$(getDSTag ${eos_dir})
  out_file_name=$(getOutFileName ${ds_tag})

  if [[ ! -f $out_file_name ]] ; then
    total_num_ds=$(( $total_num_ds + 1 ))
  fi

  echo ""
  echo "eos dir: $eos_dir"
  echo "ds tag: $ds_tag"
  echo "out file name: $out_file_name"

  #-----------------------------------------------------------------------------
  # loop through the files in this dataset directory
  for file_in_dir in $(eos ls ${EOS_PATH}/${eos_dir}); do
    if [[ ${file_in_dir} == *log.tgz* ]] ; then
      echo "    log file -- skipping"
      continue
    fi

    # contruct full eos path for this file
    full_eos_path="root://eosatlas//${EOS_PATH}/${eos_dir}/${file_in_dir}"
    echo ''
    echo "Full eos path: $full_eos_path"

    if [[ $IS_TNT == 1 ]] ; then
      #- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      # On first pass, try getting all numbers
      python ../GetAllNumbersFromTnt.py ${full_eos_path}

      #- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      # If that failed on any piece, try again for each piece individually

      # Get the number of unskimmed events
      counter=0
      while [[ ! -f tmp_events.txt ]] ; do
        counter=$[ $counter+1 ]
        python ../GetNumberUnskimmedEvents.py ${full_eos_path}
        if [[ $counter == "10" ]] ; then
          echo "Error getting unskimmed events for ${full_eos_path}"
          break
        fi
      done

      #- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      # Get the number of enties in files
      counter=0
      while [[ ! -f tmp_entries.txt ]] ; do
        counter=$[ $counter+1 ]
        python ../GetNumberEntries.py ${full_eos_path}
        if [[ $counter == "10" ]] ; then
          echo "Error getting number of entries for ${full_eos_path}"
          break
        fi
      done

      #- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
      # Get the sum of event weights in files
      counter=0
      while [[ ! -f tmp_weights.txt ]] ; do
        counter=$[ $counter+1 ]
        python ../GetSumEventWeights.py ${full_eos_path}
        if [[ $counter == "10" ]] ; then
          echo "Error getting sum of event weights for ${full_eos_path}"
          break
        fi
      done
    else
      # Get the number of enties in files
      counter=0
      while [[ ! -f tmp_entries.txt ]] ; do
        counter=$[ $counter+1 ]
        python ../GetNumberEntries.py ${full_eos_path} susy
        if [[ $counter == "10" ]] ; then
          echo "Error getting number of entries for ${full_eos_path}"
          break
        fi
      done
      cp tmp_entries.txt tmp_weights.txt
      cp tmp_entries.txt tmp_events.txt
    fi

    #- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # extract the numbers from our temp files
    if [[ -f tmp_events.txt ]] ; then
      total_num_events=$(  cat tmp_events.txt  )
      echo "Found total number of events: ${total_num_events}"
      rm -f tmp_events.txt
    else
      total_num_events="ERROR"
      echo "did not find number of events"
      total_num_errors=$[ $total_num_errors + 1 ]
    fi

    if [[ -f tmp_entries.txt ]] ; then
      total_num_entries=$( cat tmp_entries.txt )
      echo "Found total number of entries: ${total_num_entries}"
      rm -f tmp_entries.txt
    else
      total_num_entries="ERROR"
      echo "did not find number of entries"
      total_num_errors=$[ $total_num_errors + 1 ]
    fi

    if [[ -f tmp_weights.txt ]] ; then
      sum_event_weights=$( cat tmp_weights.txt )
      echo "Found sum event weights: ${sum_event_weights}"
      rm -f tmp_weights.txt
    else
      sum_event_weights="ERROR"
      echo "did not find sum of event weights"
      total_num_errors=$[ $total_num_errors + 1 ]
    fi

    #- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # Output files list and numbers into output eos file list
    echo "${full_eos_path}        ${total_num_events}        ${total_num_entries}        ${sum_event_weights}"
    echo ''
    echo "${full_eos_path}        ${total_num_events}        ${total_num_entries}        ${sum_event_weights}" >> ${out_file_name}
    total_num_files=$(( $total_num_files + 1 ))
  done
  total_num_eos_dirs=$(( $total_num_eos_dirs + 1 ))
done

echo "total num files on eos: $total_num_files"
echo "total num eos dirs: $total_num_eos_dirs"
echo "total num data sets: $total_num_ds"

echo "number of errors: $total_num_errors"
