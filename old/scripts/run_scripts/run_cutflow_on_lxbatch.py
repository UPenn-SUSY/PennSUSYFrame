#!/usr/bin/env python
"""
write a docstring and add an example usage
"""

import sys
import os.path
import subprocess
import optparse
import time
import math

import copy

import SFrameHelpers

import parse_yaml_config as parse

# ------------------------------------------------------------------------------
def main():
    config_dict = parse.parseInputs()
    if config_dict is None:
        return

    # make template config dictionary from the original config dictionary
    template_config_dict = copy.copy(config_dict)
    template_config_dict['OutputDirectory'] = '%s/batch_output/' % template_config_dict['OutputDirectory']
    template_config_dict['InputFiles'] = []

    # Get list of input files
    in_file_list = config_dict['InputFiles']

    # set up batch config directory
    config_dir = 'batch_configs'
    # print 'ensuring directory: %s' % config_dir
    # ensureDir(config_dir)

    # Get ouput directory name from config dictionary
    out_dir_name  = template_config_dict['OutputDirectory']

    # Break up files into sub-jobs
    num_files = len(in_file_list)
    max_files_per_job = 10
    num_jobs = int(math.ceil(float(num_files)/max_files_per_job))

    # List of config files for submitting later
    config_file_list = []

    print 'num files: %s' % len(in_file_list)
    print 'num files per job: %s' % max_files_per_job
    print 'num jobs: %s' % num_jobs

    for i in xrange(num_jobs):
        print '--------------------------------------------------------------------------------'
        this_config_dict = copy.copy(template_config_dict)
        xml_file_name = '%s/%s' % (config_dir, template_config_dict['XmlFileName'].replace('.xml', '__%s.xml' % i))

        this_config_dict['PostFix'] += ('__%s' % i)

        out_file_name = this_config_dict['OutputFileName'].replace('.root', '__%s.root' % i)
        this_config_dict['OutputFileName'] = out_file_name
        this_config_dict['InputFiles'] = []

        # ensuring directory exists
        ensureDir(xml_file_name)

        offset = i*max_files_per_job

        # num_files_for_this = (max_files_per_job if i < (num_jobs-1) else num_files%max_files_per_job) + 1)
        # print 'adding %d files for this job' % num_files_for_this
        print 'adding files for this job'

        # for j in xrange(max_files_per_job if i < (num_jobs-1) else (len(in_file_list)%max_files_per_job) + 1):
        for j in xrange(max_files_per_job):
            if offset + j >= num_files: break
            this_config_dict['InputFiles'].append(in_file_list[offset+j])

        # print '\tfiles for this job: %s' % this_config_dict['InputFiles']
        print '\tfiles for this job:'
        for in_file in this_config_dict['InputFiles']:
            print '\t\t%s' % in_file

        writeConfigXml(this_config_dict, xml_file_name)
        config_file_list.append(xml_file_name)

        print 'Config file generated: %s' % xml_file_name
        print 'To run on this xml file, type:'
        print '    sframe_main %s' % xml_file_name

        print 'The output root file will be:'
        print '    %s/%s' % (out_dir_name, this_config_dict['OutputFileName'])

        print ''

    print 'list of xml files:'
    for cfl in config_file_list:
        print '\t%s' % cfl
        bsub_script = makeBsubScript(cfl)

        submitBsubScript(bsub_script)

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

  <!-- RootCore libraries -->
  <Library Name="libGoodRunsLists" />
  <Library Name="libegammaAnalysisUtils" />
  <Library Name="libJetResolution" />
  <Library Name="libMissingETUtility" />
  <Library Name="libMuonEfficiencyCorrections" />
  <Library Name="libMuonMomentumCorrections" />
  <Library Name="libPATCore" />
  <Library Name="libElectronEfficiencyCorrection" />
  <Library Name="libPileupReweighting" />
  <Library Name="libReweightUtils" />
  <Library Name="libCalibrationDataInterface" />
  <Library Name="libTauCorrections" />
  <Library Name="libSUSYTools" />
  <Library Name="libSusyMatrixMethod" />
  <Library Name="libHistFitterTree" />
  <Library Name="libChargeFlip" />
  <Library Name="libLeptonTruthTools" />
  <Library Name="libReweightUtils" />
  <Library Name="libDGTriggerReweight" />
  <Library Name="libTriggerMatch" />
  <Library Name="libApplyJetCalibration" />
  <Library Name="libTileTripReader" />

  <!-- Our code libraries -->
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
      <InputTree Name="%(input_tree_name)s" />
      <OutputTree Name="%(output_tree_name)s" />
    </InputData>
""" % config_dict)
    f.write('\n')

    # user configurables
    f.write('    <!-- User configurables for this Cycle -->\n')
    f.write('    <UserConfig>\n')
    writeUserConfigs(f, config_dict)
    f.write("    </UserConfig>\n")

    # close remaining black
    f.write("  </Cycle>\n")
    f.write("</JobConfiguration>\n")

# ------------------------------------------------------------------------------
def makeBsubScript(xml_file):
    print 'making bsub script for xml config file: %s' % xml_file

    sframe_dir = os.environ['SFRAME_DIR']
    if sframe_dir == '':
        print 'Please setup SFrame!'
        return

    bsub_script = ""
    bsub_script += '#!/bin/sh\n'
    bsub_script += '# ------------------------------------------------\n'
    bsub_script += 'source ~/.bash_env\n' 
    bsub_script += '\n' 
    bsub_script += 'echo "start of script"\n' 
    bsub_script += 'cd %s/..\n' % sframe_dir 
    bsub_script += 'echo "setting up sframe"\n' 
    bsub_script += 'source setup_sframe.sh\n' 
    bsub_script += 'echo "moving to utils"\n'
    bsub_script += 'cd utils\n' 
    bsub_script += '\n' 

    bsub_script += 'cd %s\n' % os.environ['PWD']

    bsub_script += 'OUT_DIR=$(grep OutputDirectory %s | sed "s/.*=//g" | sed "s/\\"//g" )\n' % xml_file
    bsub_script += 'OUT_DIR=$(eval echo $OUT_DIR)\n'
    bsub_script += 'echo "out dir: $OUT_DIR"\n'
    bsub_script += 'if [[ ! -d $OUT_DIR ]]\n'
    bsub_script += 'then\n'
    bsub_script += '  echo "Making directory: $OUT_DIR"\n'
    bsub_script += '  mkdir -p $OUT_DIR\n'
    bsub_script += 'fi\n'
    bsub_script += '\n'
    bsub_script += 'sframe_main %s\n' % xml_file

    return bsub_script

# ------------------------------------------------------------------------------
def submitBsubScript(bsub_script):
    # print 'submitting bsub script:'
    # print bsub_script

    # p = subprocess.Popen( [ 'echo'
    #                       , 'bsub'
    p = subprocess.Popen( [ 'bsub'
                          , '-q'
                          , '1nh'
                          , bsub_script
                          ]
                        , stdout=subprocess.PIPE
                        ).communicate()


# ------------------------------------------------------------------------------
def ensureDir(f):
    d = os.path.dirname(f)
    if not os.path.exists(d):
        os.makedirs(d)

# ==============================================================================
if __name__ == '__main__':
  sys.exit(main())
