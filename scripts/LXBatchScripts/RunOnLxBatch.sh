#!/bin/sh

RUN_SCRIPT=$1
QUEUE=$2
JOB_TITLE=$3

if [[ ! -d jobs ]] ; then
  mkdir jobs
fi

if [[ ! -d output ]] ; then
  mkdir output
fi

THIS_DATE=$(date +%Y-%m-%d)
if [[ ! -d output/out_$THIS_DATE ]] ; then
  mkdir output/out_$THIS_DATE
fi

echo "#!/bin/sh" > jobs/job_${JOB_TITLE}.sh
echo 'NODE_WORK_DIR=$PWD' >> jobs/job_${JOB_TITLE}.sh
echo "cd ${BASE_WORK_DIR}" >> jobs/job_${JOB_TITLE}.sh
echo 'source SetupEnvironment.sh' >> jobs/job_${JOB_TITLE}.sh
echo 'cd $NODE_WORK_DIR' >> jobs/job_${JOB_TITLE}.sh
echo '${BASE_WORK_DIR}/'$RUN_SCRIPT >> jobs/job_${JOB_TITLE}.sh
echo 'cp *root ${BASE_WORK_DIR}/output/out_'${THIS_DATE}'/' >> jobs/job_${JOB_TITLE}.sh

chmod +x jobs/job_${JOB_TITLE}.sh

bsub -q $QUEUE jobs/job_${JOB_TITLE}.sh
