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

f = file('sample_list.txt', 'r')
flavor_channel = sys.argv[1]
region = sys.argv[2]
local_out_dir = '%s.%s' % (flavor_channel, region)

full_out_dir = 'susy_hists/optimize/2013_01_22/%s/' % local_out_dir
print 'local_out_dir: %s' % local_out_dir
print 'full_out_dir: %s' % full_out_dir

for l in f:
    # skip blank lines
    if l == '\n': continue

    print '-------------------------------------------------------------------'
    # Deconstruct the file path/name - these are the addresses of important
    # pieces of the sample path
    # end_path          = l.find('SusyDiLepton')
    end_path          = l.rfind('/')
    end_prefix        = l.find('cut_flow.') + 9
    end_sample_type   = l.find('.', end_prefix)
    end_sample_number = l.find('.', end_sample_type+1)
    end_sample_label  = l.find('.', end_sample_number+1)

    # Use above addresses to obtain substrings from sample path
    path = l[0:end_path]
    prefix = l[end_path:end_prefix]
    sample_type = l[end_prefix:end_sample_type]
    sample_number = l[end_sample_type+1:end_sample_number]
    sample_label = l[end_sample_number+1:end_sample_label]
    sample_header = ''
    if 'mc'   in prefix: sample_header = 'mc'
    if 'data' in prefix: sample_header = 'data'

    print 'full sample path : %s' % l
    print 'sample path : %s'      % path
    print 'prefix : %s'           % prefix
    print 'header : %s'           % sample_header
    print 'type : %s'             % sample_type
    print 'sample number : %s'    % sample_number
    print 'sample label : %s'     % sample_label

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # generate nominal data/mc config files
    out_file_name  = 'nominal.%s.%s.%s.%s.config' % (sample_header, sample_type, sample_number, sample_label)
    hist_file_name = '%s/%s.%s.%s.%s.root' % (full_out_dir, sample_header, sample_type, sample_number, sample_label)
    print 'Nominal out file name: %s'  % out_file_name
    print 'Nominal hist file name: %s' % hist_file_name
    out = file(out_file_name, 'w')

    # Include the correct cut config file
    if sample_type == 'signal':
        out.write('cut_file:  run/OptimizationHistograms/cuts.%s.signal.config\n' % local_out_dir)
    else:
        out.write('cut_file:  run/OptimizationHistograms/cuts.%s.nominal.config\n' % local_out_dir)

    # include correct histogram config file
    out.write('hist_file: run/OptimizationHistograms/hists.%s.config\n' % local_out_dir)

    # Output configs common to all "nominal" jobs
    out.write('out_file:  %s\n' % hist_file_name)
    out.write('\n')
    out.write('mc_event_weight: %s\n' % ('0' if sample_header == 'data' or ('plus_jet' in sample_type) else '1'))
    out.write('pile_up_weight:  %s\n' % ('0' if sample_header == 'data' else '1'))
    out.write('trigger_weight:  %s\n' % ('0' if sample_header == 'data' else '1'))
    out.write('lepton_weight:   %s\n' % ('0' if sample_header == 'data' else '1'))
    out.write('b_tag_weight:    %s\n' % ('0' if sample_header == 'data' else '1'))
    out.write('lumi_weight:     %s\n' % ('0' if sample_header == 'data' else '1'))
    out.write('cf_weight:       0\n')
    out.write('fake_weight:     0\n')
    out.write('\n')
    out.write('target_lumi: 21000\n')
    out.write('mc_channel:  %s\n' % sample_number)
    out.write('\n')
    out.write('in_tree: output\n')
    out.write('in_files:\n')
    out.write('    %s' % l)
    out.write('end\n')

    out.close()

    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # generate fake data config files
    if sample_header == 'data':
        out_file_name = 'fake.%s.%s.%s.config' % (sample_type, sample_number, sample_label)
        hist_file_name = '%s/fake.%s.%s.%s.root' % (full_out_dir, sample_type, sample_number, sample_label)
        print 'Fake out file name: %s'  % out_file_name
        print 'Fake hist file name: %s' % hist_file_name
        out = file(out_file_name, 'w')

        out.write('cut_file:  run/OptimizationHistograms/cuts.%s.fake.config\n' % local_out_dir)
        out.write('hist_file: run/OptimizationHistograms/hists.%s.config\n' % local_out_dir)
        out.write('out_file:  %s\n' % hist_file_name)
        out.write('\n')
        out.write('mc_event_weight: 0\n')
        out.write('pile_up_weight:  0\n')
        out.write('trigger_weight:  0\n')
        out.write('lepton_weight:   0\n')
        out.write('b_tag_weight:    0\n')
        out.write('lumi_weight:     0\n')
        out.write('cf_weight:       0\n')
        out.write('fake_weight:     1\n')
        out.write('\n')
        # out.write('target_lumi: 13000\n')
        out.write('mc_channel:  %s\n' % sample_number)
        out.write('\n')
        out.write('in_tree: output\n')
        out.write('in_files:\n')
        out.write('    %s' % l)
        out.write('end\n')

        out.close()

    # generate charge flip config files
    if sample_header == 'mc' and not sample_type == 'signal':
        out_file_name = 'cf.%s.%s.%s.config' % (sample_type, sample_number, sample_label)
        hist_file_name = '%s/cf.%s.%s.%s.root' % (full_out_dir, sample_type, sample_number, sample_label)
        print 'CF out file name: %s'  % out_file_name
        print 'CF hist file name: %s' % hist_file_name
        out = file(out_file_name, 'w')

        out.write('cut_file:  run/OptimizationHistograms/cuts.%s.cf.config\n' % local_out_dir)
        out.write('hist_file: run/OptimizationHistograms/hists.%s.config\n' % local_out_dir)
        out.write('out_file:  %s\n' % hist_file_name)
        out.write('\n')
        out.write('mc_event_weight: %s\n' % ('0' if sample_header == 'data' or ('plus_jet' in sample_type) else '1'))
        out.write('pile_up_weight:  1\n')
        out.write('trigger_weight:  1\n')
        out.write('lepton_weight:   1\n')
        out.write('b_tag_weight:    1\n')
        out.write('lumi_weight:     1\n')
        out.write('cf_weight:       1\n')
        out.write('fake_weight:     0\n')
        out.write('\n')
        # out.write('target_lumi: 13000\n')
        out.write('target_lumi: 21000\n')
        out.write('mc_channel:  %s\n' % sample_number)
        out.write('\n')
        out.write('in_tree: output\n')
        out.write('in_files:\n')
        out.write('    %s' % l)
        out.write('end\n')

        out.close()

f.close()
