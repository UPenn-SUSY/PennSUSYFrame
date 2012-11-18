#!/usr/bin/env python

import sys
import os.path
import optparse
import time

import yaml
import find_latest_grl as grl

# ------------------------------------------------------------------------------
def parseInputs():
    global_config_file = sys.argv[1]
    print global_config_file

    config_dict = processConfigFile(global_config_file)

    return config_dict

# ------------------------------------------------------------------------------
def processConfigFile(global_config_file_name):
    print 'global_config_file_name: %s ' % global_config_file_name
    global_config_file = open(global_config_file_name)
    config_dict = yaml.load(global_config_file)

    user_config_file_name = config_dict['UserConfigFile']
    print 'user_config_file_name: %s' % user_config_file_name
    user_config_file = open(user_config_file_name)
    config_dict['UserConfig'] = yaml.load(user_config_file)

    processConfigurables(config_dict)

    return config_dict

# ------------------------------------------------------------------------------
def processConfigurables(config):
    # get job name and Cycle name
    config['JobName'] = config['CycleName'] = 'SusyDiLeptonCutFlowCycle'

    # construct postfix using SampleName
    config['PostFix'] = config['SampleName']

    # configure egamma energy rescale and jet calibration tools with is_af2
    if config['UserConfig']['EgammaEnergyRescale']['is_af2'] == 'CONFIG':
        config['UserConfig']['EgammaEnergyRescale']['is_af2'] = \
            config['is_af2']

    if config['UserConfig']['JetCalibration']['is_af2'] == 'CONFIG':
        config['UserConfig']['JetCalibration']['is_af2'] = \
            config['is_af2']

    # if requested, find GRL
    if config['UserConfig']['GRL']['do_grl'] \
            and config['UserConfig']['GRL']['grl_xml'] == 'FIND_ME':
        config['UserConfig']['GRL']['grl_xml'] = grl.find_latest_grl('All_Good')
        print 'Setting GRL xml to "%s"\n' % config['UserConfig']['GRL']['grl_xml']

    config['UserConfig']['super_verbose_info'] = config['SuperVerboseInfo']
    config['UserConfig']['print_event_info']   = config['PrintEventInfo']
    config['UserConfig']['input_tree_name'] = config['input_tree_name']
    config['UserConfig']['output_tree_name'] = config['output_tree_name']
