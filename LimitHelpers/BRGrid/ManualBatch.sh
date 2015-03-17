JOB_TAG=$1

LOCAL_WORK_DIR=master_group_$JOB_TAG

cd /tmp/bjackson
if [[ -d $LOCAL_WORK_DIR ]] ; then
  rm -rf $LOCAL_WORK_DIR
fi
mkdir $LOCAL_WORK_DIR
cd $LOCAL_WORK_DIR
pwd

BR_GRID_DIR=/afs/cern.ch/user/b/bjackson/work/public/PennSUSYFrame.00.03.21/HistFitter/LimitHelpers/BRGrid/
master_group_file=${BR_GRID_DIR}/master_group_set_${JOB_TAG}.txt
for group_file in $(cat $master_group_file) ; do                                                                                                                                             
  source ${BR_GRID_DIR}/SubmitToBatch.sh ${BR_GRID_DIR}/$group_file $JOB_TAG
  # cd ..              
  rm -rf HistFitter
  rm -rf HistFitterNtuples
  rm -rf LimitHelpers                               
done

