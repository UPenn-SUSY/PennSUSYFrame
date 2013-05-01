#!/usr/bin/env python
"""
Script to take template cut config, and generate cut config for each tpye of
selection (nominal, cf, fake, signal, data)

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
    data_cut_file_name    = '%s.data.config'       % file_base

    print template_file_name
    print nominal_cut_file_name
    print fake_cut_file_name
    print signal_cut_file_name
    print cf_cut_file_name
    print data_cut_file_name

    template_file    = open(template_file_name   , 'r')
    nominal_cut_file = open(nominal_cut_file_name, 'w')
    fake_cut_file    = open(fake_cut_file_name   , 'w')
    signal_cut_file  = open(signal_cut_file_name , 'w')
    cf_cut_file      = open(cf_cut_file_name     , 'w')
    data_cut_file    = open(data_cut_file_name     , 'w')

    SET_PASS_2_SIGNAL_LEPTONS   = False
    SET_PASS_PROMPT_LEPTONS     = False
    SET_PASS_SIGN_CHANNEL       = False
    SET_PASS_TRUTH_SIGN_CHANNEL = False
    SET_TRIGGER_WEIGHT          = False
    SET_LEPTON_WEIGHT           = False
    SET_B_TAG_WEIGHT            = False
    SET_CF_WEIGHT               = False
    SET_FAKE_WEIGHT             = False

    for line in template_file:
        if '#' in line: continue

        if 'pass_2_signal_leptons' in line:
            SET_PASS_2_SIGNAL_LEPTONS = True
        if 'pass_prompt_leptons' in line:
            SET_PASS_PROMPT_LEPTONS = True
        if 'pass_sign_channel' in line:
            SET_PASS_SIGN_CHANNEL = True
        if 'pass_truth_sign_channel' in line:
            SET_PASS_TRUTH_SIGN_CHANNEL = True
        if 'trigger_weight' in line:
            SET_TRIGGER_WEIGHT = True
        if 'lepton_weight' in line:
            SET_LEPTON_WEIGHT = True
        if 'b_tag_weight' in line:
            SET_B_TAG_WEIGHT = True
        if 'cf_weight' in line:
            SET_CF_WEIGHT = True
        if 'fake_weight' in line:
            SET_FAKE_WEIGHT = True

        if 'end' in line:
            nominal_cut_file.write('\n')
            fake_cut_file.write(   '\n')
            signal_cut_file.write( '\n')
            cf_cut_file.write(     '\n')
            data_cut_file.write(   '\n')

            if not SET_FAKE_WEIGHT:
                nominal_cut_file.write('    pass_2_signal_leptons:     1\n')
                fake_cut_file.write(   '    pass_2_signal_leptons:     0\n')
                signal_cut_file.write( '    pass_2_signal_leptons:     1\n')
                cf_cut_file.write(     '    pass_2_signal_leptons:     1\n')
                data_cut_file.write(   '    pass_2_signal_leptons:     1\n')

            if not SET_PASS_PROMPT_LEPTONS:
                nominal_cut_file.write('    pass_prompt_leptons:       1\n')
                fake_cut_file.write(   '    pass_prompt_leptons:       0\n')
                signal_cut_file.write( '    pass_prompt_leptons:       0\n')
                cf_cut_file.write(     '    pass_prompt_leptons:       1\n')
                data_cut_file.write(   '    pass_prompt_leptons:       0\n')

            if not SET_PASS_SIGN_CHANNEL:
                # nominal_cut_file.write('    pass_sign_channel:         ss\n')
                # fake_cut_file.write(   '    pass_sign_channel:         ss\n')
                # signal_cut_file.write( '    pass_sign_channel:         ss\n')
                cf_cut_file.write(     '    pass_sign_channel:         os\n')
                # data_cut_file.write(   '    pass_sign_channel:         os\n')

            if not SET_PASS_TRUTH_SIGN_CHANNEL:
                # nominal_cut_file.write('    pass_truth_sign_channel:   ss\n')
                cf_cut_file.write(     '    pass_truth_sign_channel:   os\n')

            nominal_cut_file.write('\n')
            fake_cut_file.write(   '\n')
            signal_cut_file.write( '\n')
            cf_cut_file.write    ( '\n')
            data_cut_file.write(   '\n')

            if not SET_TRIGGER_WEIGHT:
                nominal_cut_file.write('    trigger_weight:  1\n')
                fake_cut_file.write(   '    trigger_weight:  0\n')
                signal_cut_file.write( '    trigger_weight:  1\n')
                cf_cut_file.write(     '    trigger_weight:  1\n')
                data_cut_file.write(   '    trigger_weight:  0\n')

            if not SET_LEPTON_WEIGHT:
                nominal_cut_file.write('    lepton_weight:   1\n')
                fake_cut_file.write(   '    lepton_weight:   0\n')
                signal_cut_file.write( '    lepton_weight:   1\n')
                cf_cut_file.write(     '    lepton_weight:   1\n')
                data_cut_file.write(   '    lepton_weight:   0\n')

            if not SET_B_TAG_WEIGHT:
                nominal_cut_file.write('    b_tag_weight:    1\n')
                fake_cut_file.write(   '    b_tag_weight:    0\n')
                signal_cut_file.write( '    b_tag_weight:    1\n')
                cf_cut_file.write(     '    b_tag_weight:    1\n')
                data_cut_file.write(   '    b_tag_weight:    0\n')

            if not SET_CF_WEIGHT:
                nominal_cut_file.write('    cf_weight:       0\n')
                fake_cut_file.write(   '    cf_weight:       0\n')
                signal_cut_file.write( '    cf_weight:       0\n')
                cf_cut_file.write(     '    cf_weight:       %s\n' % 0 if 'mm' in file_base else 1)
                data_cut_file.write(   '    cf_weight:       0\n')

            if not SET_FAKE_WEIGHT:
                nominal_cut_file.write('    fake_weight:     0\n')
                fake_cut_file.write(   '    fake_weight:     1\n')
                signal_cut_file.write( '    fake_weight:     0\n')
                cf_cut_file.write(     '    fake_weight:     0\n')
                data_cut_file.write(   '    fake_weight:     0\n')

            # reset flags for next cut selection
            SET_PASS_2_SIGNAL_LEPTONS   = False
            SET_PASS_PROMPT_LEPTONS     = False
            SET_PASS_SIGN_CHANNEL       = False
            SET_PASS_TRUTH_SIGN_CHANNEL = False
            SET_TRIGGER_WEIGHT          = False
            SET_LEPTON_WEIGHT           = False
            SET_B_TAG_WEIGHT            = False
            SET_CF_WEIGHT               = False
            SET_FAKE_WEIGHT             = False

        nominal_cut_file.write(line)
        fake_cut_file.write(   line)
        signal_cut_file.write( line)
        if not 'pass_sign_channel' in line:
            cf_cut_file.write(     line)
        data_cut_file.write(   line)

    template_file.close()
    nominal_cut_file.close()
    fake_cut_file.close()
    signal_cut_file.close()
    cf_cut_file.close()
    data_cut_file.close()

# ==============================================================================
if __name__ == '__main__':
    main()
