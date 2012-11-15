#!/usr/bin/env python

import sys
import os.path
import optparse
import time

import yaml

# ------------------------------------------------------------------------------
def processConfigurables(config):
    # configure egamma energy rescale and jet calibration tools with is_af2
    if config['EgammaEnergyRescale']['is_af2'] == 'CONFIG':
        config['EgammaEnergyRescale']['is_af2'] = config['Global']['is_af2']

    if config['JetCalibration']['is_af2'] == 'CONFIG':
        config['JetCalibration']['is_af2'] = config['Global']['is_af2']

    del config['Global']['is_af2']

    # if requested, find GRL
    if config['GRL']['grl_xml'] == 'FIND_ME':
        # TODO find correct GRL
        pass

# ------------------------------------------------------------------------------
def printToXml(config, out_file_name):
    out_file = open(out_file_name, "w")

    out_file.write('<UserConfig>')
    for key1 in config:
        for key2 in config[key1]:
            name = '%s_%s' % (key1, key2)
            if key1 == "Global":
                name = key2
            value = config[key1][key2]
            out_file.write(formXmlItemLine(name, value))
    out_file.write('</UserConfig>')
    out_file.close()
            
# ------------------------------------------------------------------------------
def formXmlItemLine(name, value):
    line = '<Item Name="%s" Value="%s" />\n' % (name, value)
    return line

# ------------------------------------------------------------------------------
def parseYamlInput(in_file_name, out_file_name):
    config_file = open(in_file_name)
    config = yaml.load(config_file)

    printToXml(config, out_file_name)

# ------------------------------------------------------------------------------
def main():
    config_file_name = 'job_options.yml'
    config_file = open(config_file_name)
    config = yaml.load(config_file)

    printToXml(config, 'job_options.xml')

# ==============================================================================
if __name__ == '__main__':
    main()
