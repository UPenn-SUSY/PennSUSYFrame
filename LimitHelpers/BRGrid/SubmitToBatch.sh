CONFIG_FILE_LIST=$1
JOB_TAG=$2
SOURCE_DIR=$3
if [[ "$3" == "" ]] ; then
  SOURCE_DIR="/afs/cern.ch/user/b/bjackson/work/public/PennSUSYFrame.00.03.21/HistFitter/"
fi

echo "Config file_list: $CONFIG_FILE_LIST"
echo "Source directory: $SOURCE_DIR"

echo "Copying HistFitter directory from source"
export BASE_WORK_DIR=${PWD}
mkdir HistFitter
ln -s $SOURCE_DIR/../LimitHelpers .
ln -s $SOURCE_DIR/../HistFitterNtuples .
cd HistFitter 
for each in $SOURCE_DIR/* ; do
  echo $each
  if [[ "$each" == "$SOURCE_DIR/results" ||
        "$each" == "$SOURCE_DIR/data" ||
        "$each" == "$SOURCE_DIR/config" ]] ; then
    echo "  Skipping!"
    echo ''
    continue
  fi
  echo "  Copying!"
  cp -rf $each .
  echo ''
done

ls

source setup.sh 
echo "Running HistFitter on $CONFIG_FILE"
while read -r CONFIG ; do
  echo $CONFIG
  eval "$CONFIG"
done < $CONFIG_FILE_LIST
echo ''

echo "Shifting files around"
cd results
echo 'before move'
ls

mkdir excl
mv *hypotest.root excl

echo 'after move'
ls

echo ''
cd ../

echo "Making sample list files"
python LimitHelpers/MakeSampleListFiles.py Nominal
python LimitHelpers/MakeSampleListFiles.py Up
python LimitHelpers/MakeSampleListFiles.py Down
echo ''

echo "Moving sample list files to afs directory"
TARGET_DIR="$SOURCE_DIR/sample_lists_from_batch/batch_$JOB_TAG"
if [[ ! -d $TARGET_DIR ]] ; then
  mkdir -p $TARGET_DIR
fi
cp SampleExcl_*_harvest_list $TARGET_DIR
echo ''

echo "All done!"
cd ..
