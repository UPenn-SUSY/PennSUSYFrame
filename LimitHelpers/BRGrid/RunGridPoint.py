#!/usr/bin/env python

import os
import sys
import argparse
import subprocess
import subprocess

# Set up argument parser
parser = argparse.ArgumentParser()
parser.add_argument('--bre', type=int)
parser.add_argument('--brt', type=int)
parser.add_argument('--sr')
parser.add_argument('--blind')
parser.add_argument('--keep-config', action='store_true', default=False)

args = parser.parse_args()
print args

# extract info from argument parser
bre = args.bre
brt = args.brt
brm = 100 - bre - brt
if brm < 0 or brm > 100:
    sys.exit()
if 'sr_' in args.sr:
    sr = args.sr
else:
    sr = 'sr_ht_1100_mbl_%s' % args.sr
is_blind = True if args.blind == '1' else False

# check if config file directory exists. If not, create it
br_grid_dir = 'BRGrid'
if not os.path.exists(br_grid_dir):
    os.makedirs(br_grid_dir)

# construct config file name
config_file_name = '%s/BLStopFit_bre_%d_brm_%d_brt_%s_sr_%s_%s.py' % (br_grid_dir,
                                                                      bre,
                                                                      brm,
                                                                      brt,
                                                                      sr,
                                                                      'blind' if is_blind else 'unblind')
print config_file_name

# write config file
config_file = file(config_file_name, 'w')
config_file.write('stop_br_e = %0.2f\n' % (bre/100.))
config_file.write('stop_br_m = %0.2f\n' % (brm/100.))
config_file.write('stop_br_t = %0.2f\n' % (brt/100.))
config_file.write('test_sr = "%s"\n' % sr)
config_file.write('is_blind = %s\n' % is_blind)
config_file.write('\n')
config_file.write("execfile('/'.join([os.environ['BASE_WORK_DIR'], 'LimitHelpers', 'SampleExcl.py']))\n")
config_file.close()

# Call HistFitter on the config file!
subprocess.call(['HistFitter.py', '-p', '-t', '-w', '-f', '-F', 'excl',
                 config_file_name])

# HistFitter.py -p -t -w -f -F excl /afs/cern.ch/user/b/bjackson/work/public/PennSUSYFrame.00.03.21/LimitHelpers/BRGrid/BLStopFit_bre_100_brm_0_brt_0_sr_ht_1100_mbl_400_blind.py

if not args.keep_config:
    os.remove(config_file_name)
