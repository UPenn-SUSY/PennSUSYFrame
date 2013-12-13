#!/usr/bin/env python

import sys
import os.path
import optparse
import time

import yaml
import find_latest_grl as grl

# ------------------------------------------------------------------------------
def parseInputs():
    if len(sys.argv) is not 2:
        print '%d inputs provided' % len(sys.argv)
        print 'please provide a config file'
        return None

    global_config_file = sys.argv[1]
    print global_config_file

    config_dict = processConfigFile(global_config_file)

    return config_dict

# ------------------------------------------------------------------------------
def interpretEnvVariables(string):
    if type(string) == str:
        while not string.find("$") == -1:
            search_begin = string.find("${") + 2
            search_end = string.find("}")
            search_key = string[search_begin:search_end]
            string = string.replace( "${%s}" % search_key
                                   , os.environ.get(search_key)
                                   )
    return string

# ------------------------------------------------------------------------------
def processConfigFile(global_config_file_name):
    print 'global_config_file_name: %s ' % global_config_file_name
    global_config_file = open(global_config_file_name)
    config_dict = yaml.load(global_config_file)

    user_config_file_name = interpretEnvVariables(config_dict['UserConfigFile'])
    print 'user_config_file_name: %s' % user_config_file_name
    user_config_file = open(user_config_file_name)
    config_dict['UserConfig'] = yaml.load(user_config_file)

    processConfigurables(config_dict)

    return config_dict

# ------------------------------------------------------------------------------
def processConfigurables(config):
    # check if grid variable is defined
    if not 'grid' in config:
        config['grid'] = False

    # get job name and Cycle name
    if config['CycleName'] == '':
        sys.exit('Please provide a CycleName in the config file')
    config['JobName'] = config['CycleName']

    config['label'] = getLabel(config)

    # construct postfix using SampleName
    # config['PostFix'] = config['SampleName']
    config['PostFix'] = config['label']

    config['Version'] = 'ver_%s' % config['Version']

    # construct xml file name
    config['XmlFileName']    = getXmlFileName(config)
    config['OutputFileName'] = getOutputFileName(config)

    # configure egamma energy rescale and jet calibration tools with is_af2
    if config['UserConfig']['EgammaEnergyRescale']['is_af2'] == 'CONFIG':
        config['UserConfig']['EgammaEnergyRescale']['is_af2'] = config['is_af2']

    if config['UserConfig']['JetCalibration']['is_af2'] == 'CONFIG':
        config['UserConfig']['JetCalibration']['is_af2'] = config['is_af2']

    if config['UserConfig']['EgammaSF']['is_af2'] == 'CONFIG':
        config['UserConfig']['EgammaSF']['is_af2'] = config['is_af2']

    # if requested, find GRL
    if config['UserConfig']['GRL']['do_grl'] \
            and config['UserConfig']['GRL']['grl_xml'] == 'FIND_ME':
        config['UserConfig']['GRL']['grl_xml'] = grl.find_latest_grl('All_Good')
        print 'Setting GRL xml to "%s"\n' % config['UserConfig']['GRL']['grl_xml']

    config['UserConfig']['super_verbose_info'] = config['SuperVerboseInfo']
    config['UserConfig']['print_event_info']   = config['PrintEventInfo']
    config['UserConfig']['input_tree_name'] = config['input_tree_name']
    config['UserConfig']['output_tree_name'] = config['output_tree_name']
    config['UserConfig']['is_egamma_stream'] = config['is_egamma_stream']

# ------------------------------------------------------------------------------
def getLabel(config_dict):
    label = ''

    # add cycle name to file name
    if config_dict['CycleName'] == 'SusyDiLeptonCutFlowCycle':
        label += 'cut_flow.'
        # label += 'tnt.'
    elif config_dict['CycleName'] == 'SusyDiLeptonPreselCycle':
        label += 'presel.'

    if not config_dict['grid']:
        # add sample name to file name
        label += '%s.' % config_dict['SampleName']

        # add date to file name
        date = str(time.strftime("%Y_%m_%d"))
        label += '%s' % date

    return label

# ------------------------------------------------------------------------------
def getXmlFileName(config_dict):
    file_name = 'jo.'
    file_name += config_dict['label']
    file_name += '.%s' % config_dict['Version']
    file_name += '.xml'
    return file_name

# ------------------------------------------------------------------------------
def getOutputFileName(config_dict):
    f_name = '%(CycleName)s.%(Type)s.%(Version)s.%(label)s.root' % config_dict
    return f_name
