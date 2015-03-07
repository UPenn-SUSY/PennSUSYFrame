CONFIG_FILE_LIST=$1
SOURCE_DIR=$2
if [[ "$2" == "" ]] ; then
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

source setup.sh 
echo "Running HistFitter on $CONFIG_FILE"
for CONFIG in $(cat $CONFIG_FILE_LIST) ; do
  HistFitter.py -p -t -w -f -F excl $CONFIG
done

echo "Shifting files around"
echo $PWD
ls
echo ''
cd results
echo $PWD
ls
echo ''
mkdir excl
ls
echo ''
mv *hypotest.root excl
echo 'after move'
ls
echo ''
cd ../

echo "Making sample list files"
python LimitHelpers/MakeSampleListFiles.py Nominal
python LimitHelpers/MakeSampleListFiles.py Up
python LimitHelpers/MakeSampleListFiles.py Down

echo "Moving sample list files to afs directory"
TARGET_DIR="$SOURCE_DIR/sample_lists_from_batch"
if [[ ! -d $TARGET_DIR ]] ; then
  mkdir $TARGET_DIR
fi
cp SampleExcl_*_harvest_list $TARGET_DIR

echo "All done!"
