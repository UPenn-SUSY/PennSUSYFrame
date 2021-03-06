#!/usr/bin/env python

# ------------------------------------------------------------------------------
import sys
import time
import getopt
import array
import math

import ROOT

from xml.dom import minidom

# ------------------------------------------------------------------------------
def calcSignificance(num_sig, num_bkg):
    if num_sig+num_bkg <= 0: return 0
    return num_sig / math.sqrt(num_sig+num_bkg)

# ------------------------------------------------------------------------------
def getCutVal(cut_str):
    cut_val = float(cut_str)
    if cut_val > +1.e25: return 'inf'
    if cut_val < -1.e25: return '-inf'
    return '%.4f' % cut_val

# ------------------------------------------------------------------------------
def readAndDisplayCutOpt(xml_name, tot_sig, tot_bkg, out_file_name='results.txt'):
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    out_file = file(out_file_name, 'w')
    print 'tot signal: ' , tot_sig
    print 'tot background: ' , tot_bkg
    print ''
    out_file.write('tot signal: %s\n'     % tot_sig)
    out_file.write('tot background: %s\n' % tot_bkg)
    out_file.write('\n')

    f = file(xml_name, 'r')
    xml_doc = minidom.parse(f)
    f.close()

    best_it = -1
    max_significance = 0
    best_exp_sig = 0
    best_exp_bkg = 0
    best_sig_eff = 0
    best_bkg_eff = 0

    variable_elements = xml_doc.getElementsByTagName('Variables').item(0).getElementsByTagName('Variable')
    for var_it in xrange(variable_elements.length):
        print 'var_%d: %s [%s]' % ( var_it
                                  , variable_elements.item(var_it).getAttribute('Expression')
                                  , variable_elements.item(var_it).getAttribute('Unit')
                                  )
        out_file.write( 'var_%d: %s [%s]\n' % ( var_it
                                              , variable_elements.item(var_it).getAttribute('Expression')
                                              , variable_elements.item(var_it).getAttribute('Unit')
                                              )
                      )
    print ''
    out_file.write('\n')


    all_weight_elements = xml_doc.getElementsByTagName('Weights')[0].getElementsByTagName('Bin')
    for it, el in enumerate(all_weight_elements):
        this_ibin = el.getAttribute('ibin')
        this_effs = float(el.getAttribute('effS'))
        this_effb = float(el.getAttribute('effB'))

        this_exp_sig = tot_sig*this_effs
        this_exp_bkg = tot_bkg*this_effb

        this_significance = calcSignificance(this_exp_sig, this_exp_bkg)
        if this_significance > max_significance:
            best_it = it
            max_significance = this_significance
            best_sig_eff = this_effs
            best_bkg_eff = this_effb
            best_exp_sig = this_exp_sig
            best_exp_bkg = this_exp_bkg


    if best_it >= 0:
        best_element = all_weight_elements[best_it]
        cuts = best_element.getElementsByTagName('Cuts').item(0)
        print '--------------------------------------------------------------------------------'
        print 'Found the best cut working point:'
        print '  it: ' , best_it
        print '  sig eff: %.4f - events: %.2f' % (best_sig_eff, best_exp_sig)
        print '  bkg eff: %.4f - events: %.2f' % (best_bkg_eff, best_exp_bkg)
        print '  significance: %.4f' % max_significance
        print ''
        print 'cuts:'

        out_file.write( '--------------------------------------------------------------------------------\n' )
        out_file.write( 'Found the best cut working point:\n' )
        out_file.write( '  it: %s\n' % best_it )
        out_file.write( '  sig eff: %.4f - events: %.2f\n' % (best_sig_eff, best_exp_sig) )
        out_file.write( '  bkg eff: %.4f - events: %.2f\n' % (best_bkg_eff, best_exp_bkg) )
        out_file.write( '  significance: %.4f\n' % max_significance )
        out_file.write( '\n' )
        out_file.write( 'cuts:\n' )

        cut_it = 0
        while cuts.hasAttribute('cutMin_%d' % cut_it):
            print '  %s < var_%d < %s' % ( getCutVal(cuts.getAttribute('cutMin_%d' % cut_it))
                                         , cut_it
                                         , getCutVal(cuts.getAttribute('cutMax_%d' % cut_it))
                                         )
            out_file.write( '  %s < var_%d < %s\n' % ( getCutVal(cuts.getAttribute('cutMin_%d' % cut_it))
                                                     , cut_it
                                                     , getCutVal(cuts.getAttribute('cutMax_%d' % cut_it))
                                                     )
                          )
            cut_it += 1

# ------------------------------------------------------------------------------
def main():
    tot_sig = 4
    tot_bkg = 100

    readAndDisplayCutOpt( 'weights/TMVAClassification_Cuts.weights.xml'
                        , tot_sig
                        , tot_bkg
                        )

# ==============================================================================
if __name__ == '__main__':
    main()
