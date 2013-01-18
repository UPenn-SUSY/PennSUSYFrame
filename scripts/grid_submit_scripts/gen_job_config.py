#!/usr/bin/env python

import sys
import os.path
import optparse
import time

# ------------------------------------------------------------------------------
def parseInputs():
    parser = optparse.OptionParser( usage="%prog [options]" )

    parser.add_option( '--type'
                     , dest = 'type'
                     , action = 'store'
                     )
    parser.add_option( '--sample-name'
                     , dest = 'sample_name'
                     , action = 'store'
                     )
    parser.add_option( '--egamma'
                     , dest = 'is_egamma'
                     , action = 'store_true'
                     , default = True
                     )
    parser.add_option( '--muon'
                     , dest = 'is_egamma'
                     , action = 'store_false'
                     , default = True
                     )
    parser.add_option( '--af2'
                     , dest = 'is_af2'
                     , action = 'store_true'
                     , default = False
                     )

    return parser

# ------------------------------------------------------------------------------
def writeYmlFile(parser):
    (inputs, files) = parser.parse_args()
    f = open('job_config.yml', 'w')

    user_config_file = ''
    if inputs.type == 'data':
        user_config_file = '${SFRAME_DIR}/../run/sample_configs/user_config.presel.data.yml'
    else:
        user_config_file = '${SFRAME_DIR}/../run/sample_configs/user_config.presel.mc.yml'

    f.write('grid:             True\n')
    f.write('CycleName:        SusyDiLeptonPreselCycle\n')
    f.write('SampleName:       %s\n' % inputs.sample_name)
    f.write('input_tree_name:  susy\n')
    f.write('is_af2:           %s\n' % inputs.is_af2)
    f.write('is_egamma_stream: %s\n' % inputs.is_egamma)
    f.write('output_tree_name: presel\n')
    f.write('Type:             %s\n' % inputs.type)
    f.write('\n')

    f.write('NEventsMax:       -1\n')
    f.write('OutputDirectory:  ./\n')
    # f.write('OutputLevel:      FATAL\n')
    f.write('OutputLevel:      INFO\n')
    f.write('PrintEventInfo:   False\n')
    f.write('SuperVerboseInfo: False\n')
    f.write('Version:          1\n')
    f.write('\n')

    f.write('UserConfigFile: %s\n' % user_config_file)
    f.write('InputFiles:\n')
    for in_file in files:
        f.write('  - %s\n' % in_file)

# ------------------------------------------------------------------------------
def main():
    parser = parseInputs()
    writeYmlFile(parser)

# ==============================================================================
if __name__ == '__main__':
    main()

#type:             MC
#OutputLevel:      INFO
#OutputDirectory:  ./
#NEventsMax:       -1
#is_af2:           False
#SuperVerboseInfo: False
#PrintEventInfo:   False
#Version:          1
#CycleName:        SusyDiLeptonPreselCycle
#SampleName:       105200.ttbar_small
#
#input_tree_name:  susy
#output_tree_name: presel
#is_egamma_stream: True
#
#UserConfigFile: ${SFRAME_DIR}/../run/sample_configs/user_config.presel.mc.yml
#InputFiles:
#  - ~/work/mc12/mc12_8TeV.105200.McAtNloJimmy_CT10_ttbar_LeptonFilter.merge.NTUP_SUSY.e1193_s1469_s1470_r3542_r3549_p1181_tid00950213_00/NTUP_SUSY.00950213._000715.root.1
