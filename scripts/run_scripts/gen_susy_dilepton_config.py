#!/usr/bin/env python
"""
write a docstring and add an example usage
"""

import sys
import os.path
import subprocess
import optparse
import time

import SFrameHelpers

import parse_yaml_config as parse

# ------------------------------------------------------------------------------
def main():
    config_dict = parse.parseInputs()
    writeConfigXml(config_dict, 'test_file.xml')

# ------------------------------------------------------------------------------
def getJobLabel(inputs):
    label = inputs.base_label
    return label

# ------------------------------------------------------------------------------
def writeFileLines(out_file, file_name_list):
    for fn in file_name_list:
        out_file.write('      <In FileName="%s" Lumi="1.0" />\n' % fn)

# ------------------------------------------------------------------------------
def writeConfigLine(out_file, name, value):
    line = '      <Item Name="%s" Value="%s" />\n' % (name, value)
    out_file.write(line)

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
def writeUserConfigs(out_file, config_dict):
    for cd in config_dict['UserConfig']:
        if type(config_dict['UserConfig'][cd]) == dict:
            for item in config_dict['UserConfig'][cd]:
                name = '%s_%s' % (cd, item)
                value = config_dict['UserConfig'][cd][item]
                value = interpretEnvVariables(value)
                writeConfigLine(out_file, name, value)
        else:
            value = config_dict['UserConfig'][cd]
            value = interpretEnvVariables(value)
            writeConfigLine(out_file, cd, value)

# ------------------------------------------------------------------------------
def writeConfigXml(config_dict, out_file):
    f = open(out_file, 'w')

    # get base path
    base_path = os.environ['SFRAME_DIR']
    base_path = base_path[0:base_path.find('/SFrame')]
    base_path = '%s/' % base_path

    # write header information
    f.write( """<?xml version="1.0" encoding="UTF-8" standalone="no" ?>
<!DOCTYPE JobConfiguration PUBLIC "" "%s/SusyDiLepton/config/JobConfig.dtd">
""" % base_path)

    f.write( """<JobConfiguration JobName="%(JobName)s" OutputLevel="%(OutputLevel)s">
""" % config_dict)

    # write libraries that must be loaded for cycle to run 
    f.write("""  <!-- List of libraries to be loaded for the analysis. -->
  <Library Name="libGenVector" />
  <Library Name="libGraf" />
  <Library Name="libCintex" />
  <Library Name="libSFrameCintex" />
  <Library Name="libSFramePlugIns" />

  <Library Name="libGoodRunsLists" />
  <Library Name="libegammaAnalysisUtils" />
  <Library Name="libJetResolution" />
  <Library Name="libMissingETUtility" />
  <Library Name="libMuonEfficiencyCorrections" />
  <Library Name="libMuonMomentumCorrections" />
  <Library Name="libPileupReweighting" />
  <Library Name="libReweightUtils" />
  <Library Name="libCalibrationDataInterface" />
  <Library Name="libSUSYTools" />
  <Library Name="libSusyMatrixMethod" />
  <Library Name="libHistFitterTree" />
  <Library Name="libChargeFlip" />
  <Library Name="libLeptonTruthTools" />
  <Library Name="libReweightUtils" />
  <Library Name="libDGTriggerReweight" />
  <Library Name="libTriggerMatch" />
  <Library Name="libApplyJetCalibration" />
  <Library Name="libD3PDObjects" />
  <Library Name="libAtlasSFrameUtils" />
  <Library Name="libCommonTools" />
  <Library Name="libSelectionTools" />
  <Library Name="libSusyAnalysisTools" />
  <Library Name="libSusyDiLepton" />
""")
    f.write('\n')

    # this cycle
    f.write("""  <!-- List of cycles to be executed -->
  <Cycle Name="%(CycleName)s" TargetLumi="-1"
    OutputDirectory="%(OutputDirectory)s"
    PostFix=".%(PostFix)s"
    RunMode="LOCAL" >
""" % config_dict)
    f.write('\n')

    # input file info
    f.write("""  <!-- files to be inputed -->
    <InputData Type="%(Type)s" Version="%(Version)s" Lumi="0"
      NEventsMax="%(NEventsMax)s" Cacheable="False" SkipValid="False">
""" % config_dict)
    f.write('\n')

    # actual files to include
    f.write('      <!-- include input data collection -->\n')
    writeFileLines(f, config_dict['InputFiles'])
    f.write('\n')

    # finish InputData block
    f.write("""      <!-- Specify the input/output trees -->
      <InputTree Name="susy" />
      <OutputTree Name="output" />
    </InputData>
""")
    f.write('\n')

    # user configurables
    f.write('    <!-- User configurables for this Cycle -->\n')
    f.write('    <UserConfig>\n')
    writeUserConfigs(f, config_dict)
    f.write("    </UserConfig>\n")

    # close remaining black
    f.write("  </Cycle>\n")
    f.write("</JobConfiguration>\n")


# ==============================================================================
if __name__ == '__main__':
  sys.exit(main())
