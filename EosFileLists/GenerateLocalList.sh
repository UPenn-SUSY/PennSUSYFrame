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

# ------------------------------------------------------------------------------
for local_dir in $(\ls ${LOCAL_PATH}); do
  ds_tag=$(getDSTag ${local_dir})
  out_file_name=$(getOutFileName ${ds_tag})

  echo "local_dir: '$local_dir'"
  echo "ds_tag: $ds_tag"
  echo "out_file_name: $out_file_name"

  if [[ -f ${out_file_name} ]] ; then
    echo "ERROR: File exists -- ${out_file_name}"
    echo "exiting!"
    return
  fi
  echo ""
done

# ------------------------------------------------------------------------------
echo '--------------------------------------------------------------------------------'
total_num_local_dirs=0
total_num_files=0
total_num_ds=0
for local_dir in $(\ls ${LOCAL_PATH}); do
  echo ''
  echo '--------------------------------------------------------------------------------'
  # echo "local_dir: $local_dir"
  if [[ $local_dir == *.txt ]] ; then
    echo "    text file - skipping"
    continue
  fi

  ds_tag=$(getDSTag ${local_dir})
  out_file_name=$(getOutFileName ${ds_tag})

  if [[ ! -f $out_file_name ]] ; then
    total_num_ds=$(( $total_num_ds + 1 ))
  fi

  echo "local dir: $local_dir"
  echo "ds tag: $ds_tag"
  echo "out file name: $out_file_name"

  for file_in_dir in $(\ls ${LOCAL_PATH}/${local_dir}); do
    if [[ ${file_in_dir} == *log.tgz* ]] ; then
      echo "    log file -- skipping"
      continue
    fi

    full_local_path="${LOCAL_PATH}/${local_dir}/${file_in_dir}"
    total_num_events=0
    total_num_entries=0
    echo "Full local path: $full_local_path"
    python ../GetNumberUnskimmedEvents.py ${full_local_path}
    python ../GetNumberEntries.py         ${full_local_path}
    total_num_events=$(  cat tmp_events.txt  )
    total_num_entries=$( cat tmp_entries.txt )
    rm tmp_events.txt
    rm tmp_entries.txt

    echo "${full_local_path}        ${total_num_events}        ${total_num_entries}"
    echo "${full_local_path}        ${total_num_events}        ${total_num_entries}" >> ${out_file_name}
    total_num_files=$(( $total_num_files + 1 ))
  done
  total_num_local_dirs=$(( $total_num_local_dirs + 1 ))
  echo ''
done

echo "total num files: $total_num_files"
echo "total num dirs: $total_num_local_dirs"
echo "total num data sets: $total_num_ds"

