#!/bin/env python

import os,subprocess,shutil,glob

del_old_files = True

dsid_mapping = {
'ttbar_PowhegJimmy':[105860], 'ttbar_PowhegPythia':[105861],
'McAtNloWt':[108346], 'McAtNlo':[110001],
'PowPyWtDR':[110141], 'PowPyWtDS':[110142], 'PowJiWtDR':[110145], 'PowJiWtDS':[110147],
'ttbar_MorePS':[117209], 'ttbar_LessPS':[117210],
'AcerMore':[117245], 'AcerLess':[117246], 'AcerWt':[117360,117361,117362],
'ttbar_Sherpa':[117800], 'ttW':[119353], 'ttWjI':[119354],
'Diboson_ww':[126929,126931], 'Diboson_wz':[129478,129487],
'AlpgenTTbarNp0':[164440], 'AlpgenTTbarNp1':[164441], 'AlpgenTTbarNp2':[164442],
'AlpgenTTbarNp3p':[164443], 'AlpgenTTbarNp3':[164444], 'AlpgenTTbarNp4p':[164445],
'PowPy6_ww':[169062,169064],
'Zee_4jets':[173469], 'Zmm_4jets':[173470], 'Ztt_4jets':[173471],
'ttbar_rensc2':[174763], 'ttbar_rensc05':[174764], 'ttbar_facsc2':[174765], 'ttbar_facsc05':[174766],
'ttWj':[174830], 'ttWjjI':[174831],
'Zee_4jetsOnly':[176067], 'Zmm_4jetsOnly':[176068], 'Ztt_4jetsOnly':[176069],
'ttW_SU':[176895], 'ttW_SD':[176896], 'ttW_AU':[176897], 'ttW_AD':[176898],
'ttW_MF':[176899], 'ttW_LF':[176900], 'ttW_XU':[176901], 'ttW_XD':[176902],
'ttWjE_SU':[176903], 'ttWjE_SD':[176904], 'ttWjE_AU':[176905], 'ttWjE_AD':[176906],
'ttWjE_MF':[176907], 'ttWjE_LF':[176908], 'ttWjE_XU':[176909], 'ttWjE_XD':[176910],
'ttWjjI_SU':[176911], 'ttWjjI_SD':[176912], 'ttWjjI_AU':[176913], 'ttWjjI_AD':[176914],
'ttWjjI_MF':[176915], 'ttWjjI_LF':[176916], 'ttWjjI_XU':[176917], 'ttWjjI_XD':[176918],
    }

final_dir = '/afs/cern.ch/user/b/bjackson/work/public/TruthSyst_plots_merge/'

# Go through all the datasets
for aset in dsid_mapping:
    # See if the file is already there...
    if os.access( final_dir+aset+'.root' , os.R_OK ):
        print 'Found file already existing:',final_dir+aset+'.root'
        if del_old_files:
            old_rm = subprocess.Popen(['rm',final_dir+aset+'.root'])
            old_rm.wait()
        else: continue

    # Make a list of files
    file_list = []
    for dsid in dsid_mapping[aset]:
        file_list += glob.glob( 'user.bjackson.'+str(dsid)+'*/*root*' )
    if 0==len(file_list):
        print 'No files found for',aset,'with DSIDs',aset
        continue
    elif 1==len(file_list):
        shutil.copyfile( file_list[0] , final_dir+aset+'.root' )
    else:
        a_hadd = subprocess.Popen(['hadd',final_dir+aset+'.root']+file_list)

