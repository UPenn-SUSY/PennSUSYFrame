#!/bin/sh
# ==============================================================================
# = 
# = Usage:
# =     source ../GenerateLocalList.sh tnt_102 /eos/atlas/user/b/bjackson/tnt_102
# ==============================================================================

# ==============================================================================
LOCAL_LIST_PREFIX=${1}
LOCAL_PATH=${2}

# ------------------------------------------------------------------------------
echo "LOCAL_LIST_PREFIX: ${LOCAL_LIST_PREFIX}"
echo "LOCAL_PATH: ${LOCAL_PATH}"

# ------------------------------------------------------------------------------
function getDSTag {
  LOCAL_DIR=$1
  ds_tag=$(echo ${LOCAL_DIR} | sed "s#user\.bjackson\.\(.*\)\.tnt_.*#\1#g")
  echo $ds_tag
}

# ------------------------------------------------------------------------------
function getOutFileName {
  DS_TAG=$1
  out_file_name="${LOCAL_LIST_PREFIX}.${ds_tag}.txt"
  echo $out_file_name
}

# ==============================================================================
echo '================================================================================'
# initialize counters
total_num_local_dirs=0
total_num_files=0
total_num_ds=0
total_num_errors=0

# loop through datasets in local path
for local_dir in $(\ls ${LOCAL_PATH}); do
  echo '--------------------------------------------------------------------------------'
  echo "local_dir: $local_dir"
  if [[ $local_dir == *.txt ]] ; then
    echo "    text file - skipping"
    continue
  fi

  ds_tag=$(getDSTag ${local_dir})
  out_file_name=$(getOutFileName ${ds_tag})

  if [[ ! -f $out_file_name ]] ; then
    total_num_ds=$(( $total_num_ds + 1 ))
  fi

  echo ""
  echo "local dir: $local_dir"
  echo "ds tag: $ds_tag"
  echo "out file name: $out_file_name"

  #-----------------------------------------------------------------------------
  # loop through the files in this dataset directory
  for file_in_dir in $(\ls ${LOCAL_PATH}/${local_dir}); do
    if [[ ${file_in_dir} == *log.tgz* ]] ; then
      echo "    log file -- skipping"
      continue
    fi

    # contruct full path for this file
    full_local_path="${LOCAL_PATH}/${local_dir}/${file_in_dir}"
    echo ''
    echo "Full local path: $full_local_path"

    #- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # On first pass, try getting all numbers
    python ../GetAllNumbersFromTnt.py ${full_local_path}

    #- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # If that failed on any piece, try again for each piece individually

    # Get the number of unskimmed events
    counter=0
    while [[ ! -f tmp_events.txt ]] ; do
      counter=$[ $counter+1 ]
      python ../GetNumberUnskimmedEvents.py ${full_local_path}
      if [[ $counter == "10" ]] ; then
        echo "Error getting unskimmed events for ${full_local_path}"
        break
      fi
    done

    #- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # Get the number of enties in files
    counter=0
    while [[ ! -f tmp_entries.txt ]] ; do
      counter=$[ $counter+1 ]
      python ../GetNumberEntries.py ${full_local_path}
      if [[ $counter == "10" ]] ; then
        echo "Error getting number of entries for ${full_local_path}"
        break
      fi
    done

    #- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # Get the sum of event weights in files
    counter=0
    while [[ ! -f tmp_weights.txt ]] ; do
      counter=$[ $counter+1 ]
      python ../GetSumEventWeights.py ${full_local_path}
      if [[ $counter == "10" ]] ; then
        echo "Error getting sum of event weights for ${full_local_path}"
        break
      fi
    done

    #- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # extract the numbers from our temp files
    if [[ -f tmp_events.txt ]] ; then
      total_num_events=$(  cat tmp_events.txt  )
      echo "Found total number of events: ${total_num_events}"
      rm tmp_events.txt
    else
      total_num_events="ERROR"
      echo "did not find number of events"
      total_num_errors=$[ $total_num_errors + 1 ]
    fi

    if [[ -f tmp_entries.txt ]] ; then
      total_num_entries=$( cat tmp_entries.txt )
      echo "Found total number of entries: ${total_num_entries}"
      rm tmp_entries.txt
    else
      total_num_entries="ERROR"
      echo "did not find number of entries"
      total_num_errors=$[ $total_num_errors + 1 ]
    fi

    if [[ -f tmp_weights.txt ]] ; then
      sum_event_weights=$( cat tmp_weights.txt )
      echo "Found sum event weights: ${sum_event_weights}"
      rm tmp_weights.txt
    else
      sum_event_weights="ERROR"
      echo "did not find sum of event weights"
      total_num_errors=$[ $total_num_errors + 1 ]
    fi

    #- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # Output files list and numbers into output local file list
    echo "${full_local_path}        ${total_num_events}        ${total_num_entries}        ${sum_event_weights}"
    echo ''
    echo "${full_local_path}        ${total_num_events}        ${total_num_entries}        ${sum_event_weights}" >> ${out_file_name}
    total_num_files=$(( $total_num_files + 1 ))
  done
  total_num_local_dirs=$(( $total_num_local_dirs + 1 ))
done

echo "total num files: $total_num_files"
echo "total num dirs: $total_num_local_dirs"
echo "total num data sets: $total_num_ds"

echo "number of errors: $total_num_errors"
