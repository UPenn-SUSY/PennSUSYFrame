
# Do this first:
#asetup 17.2.14.4
#localSetupPandaClient

# data_sets.txt is a list of data sets to run on.  You can comment them out and they won't be reprocessed
# Normally these are very fast grid jobs...
for aset in `cat data_sets.txt | grep -ve "#"`
do
  pathena --trf "Reco_trf.py inputEVNTFile=%IN outputNTUP_TRUTHFile=%OUT.NTUP_TRUTH.root preExec='useHfor=False' " --outDS user.`whoami`.`echo ${aset} | gawk '{split($1,a,"/");print a[1]}'`.v0_150128 --inDS ${aset} --noBuild --long --nGBPerJob=MAX #--excludedSite=...
done

