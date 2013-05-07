#!/usr/bin/env python
"""
Script to generate run config files to be submitted to batch queue

Usage:
    python GenerateRunConfigFiles.py ...
"""

import sys
import os.path
import optparse
import time

import yaml
import GetListOfSamples as samples

# ------------------------------------------------------------------------------
skipped_config = [ 'input_samples'
                 , 'file_name_base'
                 , 'ptnt_out_file_path'
                 , 'hist_out_file_path'
                 , 'in_files'
                 , 'max_job_size'
                 ]

# ------------------------------------------------------------------------------
def parseInputs():
    if len(sys.argv) != 2:
        print 'Please provide config file'
        return None

    global_config_file = sys.argv[1]
    config_dict = processConfigFile(global_config_file)

    return config_dict

# ------------------------------------------------------------------------------
def processConfigFile(config_file_name):
    print 'Config file name: %s' % config_file_name
    config_file = open(config_file_name)
    config_dict = yaml.load(config_file)

    processConfigurables(config_dict)
    return config_dict

# ------------------------------------------------------------------------------
def processConfigurables(config_dict):
    config_dict['input_samples'] = getInputSamples(
            config_dict['in_files'],
            config_dict['in_file_base_path'],
            max_job_size = config_dict['max_job_size'])

# ------------------------------------------------------------------------------
def printRunConfigs(config_dict, run_tag = 'run'):
    # Parse config dictionary, and construct template config text that will be
    # the same for all run config files
    template_config_text = ''
    for cd in config_dict:
        if cd in skipped_config: continue
        template_config_text += '\n%s: %s' % (cd, config_dict[cd])

    # Construct the run config directory -- ${PWD}/run_config/
    # Ensure this directory exists
    run_config_dir = '%s/run_configs__%s/' % (os.getcwd(), run_tag)
    ensure_dir(run_config_dir)

    config_list_merge = open('config_list__%s.merge.txt' % run_tag, 'w')
    config_list       = open('config_list__%s.txt'       % run_tag, 'w')

    # Step through input samples.  Create run config file for each chunk
    sample_list_for_jobs = config_dict['input_samples']
    for sample_name in sample_list_for_jobs:
        for sub_sample_name in sample_list_for_jobs[sample_name]:
            merge_run_config_file_name = '%s/run_config.%s.%s.__merge.config' % \
                    ( run_config_dir
                    , config_dict['file_name_base']
                    , sub_sample_name
                    )

            # Append run config file to list of run configs
            config_list_merge.write('%s\n' % merge_run_config_file_name)

            # print 'creating merged run config at %s' % merge_run_config_file_name
            merge_ptnt_file_name = '%s/ptnt.%s.%s.__merge.root' % \
                    ( config_dict['ptnt_out_file_path']
                    , config_dict['file_name_base']
                    , sub_sample_name
                    )
            merge_hist_file_name = '' if not 'hist_out_file_path' in config_dict else '%s/hist.%s.%s.__merge.root' % \
                    ( config_dict['hist_out_file_path']
                    , config_dict['file_name_base']
                    , sub_sample_name
                    )
            merge_config_out = writeConfigHeader( merge_run_config_file_name
                                                , merge_ptnt_file_name
                                                , merge_hist_file_name
                                                , config_dict['in_files'][sample_name]['sample_number']
                                                , template_config_text
                                                )

            for i, chunk in enumerate(sample_list_for_jobs[sample_name]
                                                          [sub_sample_name]):
                # Construct run config file name, and ptnt/hist file names
                run_config_file_name = '%s/run_config.%s.%s.__%d.config' % \
                        ( run_config_dir
                        , config_dict['file_name_base']
                        , sub_sample_name
                        , i
                        )

                # Append run config file to list of run configs
                config_list.write('%s\n' % run_config_file_name)

                # print 'creating run config at %s' % run_config_file_name
                ptnt_file_name = '%s/ptnt.%s.%s.__%d.root' % \
                        ( config_dict['ptnt_out_file_path']
                        , config_dict['file_name_base']
                        , sub_sample_name
                        , i
                        )
                hist_file_name = '' if not 'hist_out_file_path' in config_dict else '%s/hist.%s.%s.__%d.root' % \
                        ( config_dict['hist_out_file_path']
                        , config_dict['file_name_base']
                        , sub_sample_name
                        , i
                        )

                # Write run config to file
                run_config_out = writeConfigHeader( run_config_file_name
                                                  , ptnt_file_name
                                                  , hist_file_name
                                                  , config_dict['in_files'][sample_name]['sample_number']
                                                  , template_config_text
                                                  )

                for file in chunk:
                    merge_config_out.write( '  %s\n' % file )
                    run_config_out.write(   '  %s\n' % file )

                # Write end tag, and close file
                run_config_out.write( 'end\n' )
                run_config_out.close()

            # Write end tag, and close merge file
            merge_config_out.write( 'end\n' )
            merge_config_out.close()

# ------------------------------------------------------------------------------
def writeConfigHeader( config_file_name
                     , ptnt_file_name
                     , hist_file_name
                     , mc_channel
                     , template_config_text
                     ):
    run_config_out = open(config_file_name, 'w')
    run_config_out.write( '%s\n' % template_config_text )
    run_config_out.write( '\n' )
    run_config_out.write( 'ptnt_file: %s\n' % ptnt_file_name )
    run_config_out.write( 'hist_file: %s\n' % hist_file_name )
    run_config_out.write( '\n' )
    run_config_out.write( 'mc_channel: %s\n' % mc_channel )
    run_config_out.write( '\n' )
    run_config_out.write( 'in_files:\n' )

    return run_config_out

# ------------------------------------------------------------------------------
def ensure_dir(f):
    d = os.path.dirname(f)

    if not os.path.exists(d):
        os.makedirs(d)


# ------------------------------------------------------------------------------
def getInputSamples(in_files_dict, base_path, max_job_size = 1):
    input_samples = {}
    for sample_name in in_files_dict:
        input_samples[sample_name] = samples.getSamplesForJobs(
                # master_directory  = in_files_dict[sample_name]['base_path'],
                master_directory  = base_path,
                grep_for          = in_files_dict[sample_name]['grep_for'],
                max_files_per_job = max_job_size)

    return input_samples

# ------------------------------------------------------------------------------
def main():
    run_configs = parseInputs()
    if run_configs == None: return
    printRunConfigs(run_configs, run_tag = time.strftime('%Y_%m_%d'))

# ==============================================================================
if __name__ == '__main__':
    main()
