#!/usr/bin/env python

# ==============================================================================
# = Script to generate the config files used in running over our flat ntuple,
# = and make histogam files
# =
# = Usage: python gen_config.py <flavor_channel> <region>
# =
# = Note: This script requires there be a files named sample_list.txt in the pwd
# ==============================================================================

import sys
import os

def main():
    f = file('sample_list.txt', 'r')
    flavor_channel = sys.argv[1]
    region = sys.argv[2]
    local_out_dir = '%s.%s' % (flavor_channel, region)

    full_out_dir = 'susy_hists/optimize/tnt.003/%s/' % local_out_dir
    print 'local_out_dir: %s' % local_out_dir
    print 'full_out_dir: %s' % full_out_dir

    for l in f:
        # skip blank lines
        if l == '\n': continue

        print '-------------------------------------------------------------------'
        # Deconstruct the file path/name - these are the addresses of important
        # pieces of the sample path
        end_path          = l.find('SusyDiLepton')
        end_prefix        = l.find('cut_flow.') + 9
        end_sample_type   = l.find('.', end_prefix)
        end_sample_number = l.find('.', end_sample_type+1)
        end_sample_label  = l.find('.', end_sample_number+1)

        # Use above addresses to obtain substrings from sample path
        data = {}
        data['l'] = l
        data['local_out_dir'] = local_out_dir
        data['path'] = l[0:end_path]
        data['prefix'] = l[end_path:end_prefix]
        data['sample_type'] = l[end_prefix:end_sample_type]
        data['sample_number'] = l[end_sample_type+1:end_sample_number]
        data['sample_label'] = l[end_sample_number+1:end_sample_label]
        data['sample_header'] = ''
        if 'mc'   in data['prefix']: data['sample_header'] = 'mc'
        if 'data' in data['prefix']: data['sample_header'] = 'data'

        print 'full sample path : %s' % l
        print 'sample path : %s'      % data['path']
        print 'prefix : %s'           % data['prefix']
        print 'header : %s'           % data['sample_header']
        print 'type : %s'             % data['sample_type']
        print 'sample number : %s'    % data['sample_number']
        print 'sample label : %s'     % data['sample_label']

        data['config_base_path'] = '%s/../utils/RunConfigs/OptimizationHistograms/tnt.003/' % os.environ['SFRAME_DIR']
        data['ptnt_base_path']   = '%s/../utils/pTNTs/OptimizationHistograms/tnt.003/%s'      % (os.environ['SFRAME_DIR'], data['local_out_dir'])
        data['hist_base_path']   = '%s/../utils/SusyHists/OptimizationHistograms/tnt.003/%s'  % (os.environ['SFRAME_DIR'], data['local_out_dir'])

        print 'config base path : %s' % data['config_base_path']
        print 'ptnt base path : %s'   % data['ptnt_base_path']
        print 'hist base path : %s'   % data['hist_base_path']

        genNominalConfigFile(data)
        genFakeConfigFile(data)
        genCFConfigFile(data)

    # clean up sample list file
    f.close()

def genNominalConfigFile(data):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # generate nominal data/mc config files
    out_file_name  = 'nominal.%s.%s.%s.%s.config' % ( data['sample_header']
                                                    , data['sample_type']
                                                    , data['sample_number']
                                                    , data['sample_label']
                                                    )
    ptnt_file_name = '%s/ptnt.nominal.%s.%s.%s.%s.root' % ( data['ptnt_base_path']
                                                          , data['sample_header']
                                                          , data['sample_type']
                                                          , data['sample_number']
                                                          , data['sample_label']
                                                          )
    hist_file_name = '%s/hists.nominal.%s.%s.%s.%s.root' % ( data['hist_base_path']
                                                           , data['sample_header']
                                                           , data['sample_type']
                                                           , data['sample_number']
                                                           , data['sample_label']
                                                           )
    print 'Nominal config file name: %s' % out_file_name
    print 'Nominal hist file name: %s'   % hist_file_name
    print 'Nominal ptnt file name: %s'   % ptnt_file_name
    out = file(out_file_name, 'w')

    # Include the correct cut config file
    out.write('cut_config:  %s/cuts.%s.%s.config\n' % ( data['config_base_path']
                                                      , data['local_out_dir']
                                                      , 'signal' if data['sample_type'] == 'signal' else 'nominal'
                                                      )
             )

    # include correct histogram config file
    out.write('hist_config: %s/hists.%s.config\n' % (data['config_base_path'], data['local_out_dir']))
    out.write('\n')

    # Output file names for ptnt and hist files
    out.write('ptnt_file:  %s\n' % ptnt_file_name)
    out.write('hist_file:  %s\n' % hist_file_name)
    out.write('\n')

    # Configs common to all "nominal" jobs
    out.write('mc_event_weight: %s\n' % ('0' if ( data['sample_header'] == 'data'
                                                or ('plus_jet' in data['sample_type'])
                                                ) 
                                        else '1'
                                        )
             )
    out.write('pile_up_weight:  %s\n' % ('0' if data['sample_header'] == 'data' else '1'))
    out.write('trigger_weight:  %s\n' % ('0' if data['sample_header'] == 'data' else '1'))
    out.write('lepton_weight:   %s\n' % ('0' if data['sample_header'] == 'data' else '1'))
    out.write('b_tag_weight:    %s\n' % ('0' if data['sample_header'] == 'data' else '1'))
    out.write('lumi_weight:     %s\n' % ('0' if data['sample_header'] == 'data' else '1'))
    out.write('cf_weight:       0\n')
    out.write('fake_weight:     0\n')
    out.write('\n')
    out.write('target_lumi: 21000\n')
    out.write('mc_channel:  %s\n' % data['sample_number'])
    out.write('\n')
    out.write('in_tree: output\n')
    out.write('in_files:\n')
    out.write('    %s' % data['l'])
    out.write('end\n')

    out.close()

def genFakeConfigFile(data):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    if not data['sample_header'] == 'data': return

    # generate fake data/mc config files
    out_file_name  = 'fake.%s.%s.%s.%s.config' % ( data['sample_header']
                                                 , data['sample_type']
                                                 , data['sample_number']
                                                 , data['sample_label']
                                                 )
    ptnt_file_name = '%s/ptnt.fake.%s.%s.%s.%s.root' % ( data['ptnt_base_path']
                                                       , data['sample_header']
                                                       , data['sample_type']
                                                       , data['sample_number']
                                                       , data['sample_label']
                                                       )
    hist_file_name = '%s/hists.fake.%s.%s.%s.%s.root' % ( data['hist_base_path']
                                                        , data['sample_header']
                                                        , data['sample_type']
                                                        , data['sample_number']
                                                        , data['sample_label']
                                                        )
    print 'Fake config file name: %s' % out_file_name
    print 'Fake hist file name: %s'   % hist_file_name
    print 'Fake ptnt file name: %s'   % ptnt_file_name
    out = file(out_file_name, 'w')

    # Include the correct cut config file
    out.write('cut_config:  %s/cuts.%s.fake.config\n' % ( data['config_base_path']
                                                        , data['local_out_dir']
                                                        )
             )

    # include correct histogram config file
    out.write('hist_config: %s/hists.%s.config\n' % (data['config_base_path'], data['local_out_dir']))
    out.write('\n')

    # Output file names for ptnt and hist files
    out.write('ptnt_file:  %s\n' % ptnt_file_name)
    out.write('hist_file:  %s\n' % hist_file_name)
    out.write('\n')

    # Configs common to all "Fake" jobs
    out.write('mc_event_weight: 0\n')
    out.write('pile_up_weight:  0\n')
    out.write('trigger_weight:  0\n')
    out.write('lepton_weight:   0\n')
    out.write('b_tag_weight:    0\n')
    out.write('lumi_weight:     0\n')
    out.write('cf_weight:       0\n')
    out.write('fake_weight:     1\n')
    out.write('\n')
    out.write('target_lumi: 21000\n')
    out.write('mc_channel:  %s\n' % data['sample_number'])
    out.write('\n')
    out.write('in_tree: output\n')
    out.write('in_files:\n')
    out.write('    %s' % data['l'])
    out.write('end\n')

    out.close()

def genCFConfigFile(data):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    if not data['sample_header'] == 'mc' or data['sample_header'] == 'signal':
        return

    # generate cf data/mc config files
    out_file_name  = 'cf.%s.%s.%s.%s.config' % ( data['sample_header']
                                               , data['sample_type']
                                               , data['sample_number']
                                               , data['sample_label']
                                               )
    ptnt_file_name = '%s/ptnt.cf.%s.%s.%s.%s.root' % ( data['ptnt_base_path']
                                                     , data['sample_header']
                                                     , data['sample_type']
                                                     , data['sample_number']
                                                     , data['sample_label']
                                                     )
    hist_file_name = '%s/hists.cf.%s.%s.%s.%s.root' % ( data['hist_base_path']
                                                      , data['sample_header']
                                                      , data['sample_type']
                                                      , data['sample_number']
                                                      , data['sample_label']
                                                      )
    print 'CF config file name: %s' % out_file_name
    print 'CF hist file name: %s'   % hist_file_name
    print 'CF ptnt file name: %s'   % ptnt_file_name
    out = file(out_file_name, 'w')

    # Include the correct cut config file
    out.write('cut_config:  %s/cuts.%s.cf.config\n' % ( data['config_base_path']
                                                      , data['local_out_dir']
                                                      )
             )

    # include correct histogram config file
    out.write('hist_config: %s/hists.%s.config\n' % (data['config_base_path'], data['local_out_dir']))
    out.write('\n')

    # Output file names for ptnt and hist files
    out.write('ptnt_file:  %s\n' % ptnt_file_name)
    out.write('hist_file:  %s\n' % hist_file_name)
    out.write('\n')

    # Configs common to all "CF" jobs
    out.write('mc_event_weight: %s\n' % ('0' if ( data['sample_header'] == 'data'
                                                or ('plus_jet' in data['sample_type'])
                                                ) 
                                        else '1'
                                        )
             )
    out.write('pile_up_weight:  1\n')
    out.write('trigger_weight:  1\n')
    out.write('lepton_weight:   1\n')
    out.write('b_tag_weight:    1\n')
    out.write('lumi_weight:     1\n')
    out.write('cf_weight:       1\n')
    out.write('fake_weight:     0\n')
    out.write('\n')
    out.write('target_lumi: 21000\n')
    out.write('mc_channel:  %s\n' % data['sample_number'])
    out.write('\n')
    out.write('in_tree: output\n')
    out.write('in_files:\n')
    out.write('    %s' % data['l'])
    out.write('end\n')

    out.close()

if __name__ == '__main__':
    main()
