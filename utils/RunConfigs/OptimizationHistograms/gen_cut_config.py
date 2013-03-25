#!/usr/bin/env python
# ==============================================================================
"""
Script to take template cut config, and generate cut config for each tpye of
selection (nominal, cf, fake, signal)

Usage:
    python ../gen_cut_config.py cuts.ee.dev
"""

import sys
import os.path
import optparse
import time

# ------------------------------------------------------------------------------
def main():
    if not len(sys.argv) == 2:
        print 'Please provide base name for template file'
        return

    file_base = sys.argv[1]
    template_file_name    = '%s.template.config' % file_base
    nominal_cut_file_name = '%s.nominal.config'  % file_base
    fake_cut_file_name    = '%s.fake.config'     % file_base
    signal_cut_file_name  = '%s.signal.config'   % file_base
    cf_cut_file_name      = '%s.cf.config'       % file_base
    print template_file_name
    print nominal_cut_file_name
    print fake_cut_file_name
    print signal_cut_file_name
    print cf_cut_file_name

    template_file    = open(template_file_name   , 'r')
    nominal_cut_file = open(nominal_cut_file_name, 'w')
    fake_cut_file    = open(fake_cut_file_name   , 'w')
    signal_cut_file  = open(signal_cut_file_name , 'w')
    cf_cut_file      = open(cf_cut_file_name     , 'w')

    for line in template_file:
        if '#' in line: continue

        if 'end' in line:
            nominal_cut_file.write('\n')
            fake_cut_file.write(   '\n')
            signal_cut_file.write( '\n')
            cf_cut_file.write(     '\n')

            nominal_cut_file.write('    pass_2_signal_leptons:     1\n')
            fake_cut_file.write(   '    pass_2_signal_leptons:     0\n')
            signal_cut_file.write( '    pass_2_signal_leptons:     1\n')
            cf_cut_file.write(     '    pass_2_signal_leptons:     1\n')

            nominal_cut_file.write('    pass_prompt_leptons:       1\n')
            fake_cut_file.write(   '    pass_prompt_leptons:       0\n')
            signal_cut_file.write( '    pass_prompt_leptons:       0\n')
            cf_cut_file.write(     '    pass_prompt_leptons:       1\n')

            nominal_cut_file.write('    pass_sign_channel:         ss\n')
            fake_cut_file.write(   '    pass_sign_channel:         ss\n')
            signal_cut_file.write( '    pass_sign_channel:         ss\n')
            cf_cut_file.write(     '    pass_sign_channel:         os\n')

            nominal_cut_file.write('    pass_truth_sign_channel:   ss\n')
            cf_cut_file.write(     '    pass_truth_sign_channel:   os\n')

            nominal_cut_file.write('\n')
            fake_cut_file.write(   '\n')
            signal_cut_file.write( '\n')
            cf_cut_file.write    ( '\n')

            nominal_cut_file.write('    trigger_weight:  1\n')
            fake_cut_file.write(   '    trigger_weight:  0\n')
            signal_cut_file.write( '    trigger_weight:  1\n')
            cf_cut_file.write(     '    trigger_weight:  1\n')

            nominal_cut_file.write('    lepton_weight:   1\n')
            fake_cut_file.write(   '    lepton_weight:   0\n')
            signal_cut_file.write( '    lepton_weight:   1\n')
            cf_cut_file.write(     '    lepton_weight:   1\n')

            nominal_cut_file.write('    b_tag_weight:    1\n')
            fake_cut_file.write(   '    b_tag_weight:    0\n')
            signal_cut_file.write( '    b_tag_weight:    1\n')
            cf_cut_file.write(     '    b_tag_weight:    1\n')

            if 'mm' in file_base:
                nominal_cut_file.write('    cf_weight:       0\n')
                fake_cut_file.write(   '    cf_weight:       0\n')
                signal_cut_file.write( '    cf_weight:       0\n')
                cf_cut_file.write(     '    cf_weight:       0\n')
            else:
                nominal_cut_file.write('    cf_weight:       0\n')
                fake_cut_file.write(   '    cf_weight:       0\n')
                signal_cut_file.write( '    cf_weight:       0\n')
                cf_cut_file.write(     '    cf_weight:       1\n')

            nominal_cut_file.write('    fake_weight:     0\n')
            fake_cut_file.write(   '    fake_weight:     1\n')
            signal_cut_file.write( '    fake_weight:     0\n')
            cf_cut_file.write(     '    fake_weight:     0\n')

        nominal_cut_file.write(line)
        fake_cut_file.write(   line)
        signal_cut_file.write( line)
        cf_cut_file.write(     line)

    template_file.close()
    nominal_cut_file.close()
    fake_cut_file.close()
    signal_cut_file.close()
    cf_cut_file.close()

# ==============================================================================
if __name__ == '__main__':
    main()
