#!/usr/bin/env python

user="user.bjackson."
skimversion=".plots_150128_v1"
import getopt,os,sys

verbose=True
args = sys.argv[1:]
if len(args)==0: sys.exit(1)

inputFile = args[0]

f = open(inputFile)
for line in f.readlines():

    input_ds = line.strip()
    if len(input_ds)<5 or input_ds.startswith('#'): continue # Ignore white space and comments
    if len(input_ds.split())>1:
        if input_ds.split()[1].strip().startswith('#'): input_ds = input_ds.split()[0].strip()
        else:
            print 'Warning: found space in the line that I wasnt sure how to deal with.  Skipping the sets:'
            print '\t',input_ds
            continue

    if input_ds.find('#')==0: continue # double protection never hurt

    tmp = input_ds.replace('user.bjackson.','').replace('.evgen.EVNT','').replace('/','').replace('.v1.131124','').replace('_AU2CT10','').replace('.v0.131219','').replace('v0.140715_EXT0','').replace('AUET2B_CTEQ6L1_','')

    output_ds = user+tmp+skimversion
    rootoutfile = 'truth_histograms.root'
    print " * input_ds:", input_ds
    print " * output_ds:",output_ds
    print " * root file:",rootoutfile

    cmd = 'prun --rootVer=5.34/18 --cmtConfig=x86_64-slc6-gcc47-opt --exec "./run_systs --infile %IN " --outDS='+output_ds+' --inDS='+input_ds+' --outputs='+rootoutfile+' --nGBPerJob=MAX --useShortLivedReplicas --mergeOutput --excludeFile=run_systs.o '

    print cmd
    os.system( cmd )
