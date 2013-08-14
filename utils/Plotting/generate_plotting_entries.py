#!/usr/bin/env python
# ==============================================================================
# = Script to generate the entry blocks used while making plots
# =
# = TODO add more documentation
# ==============================================================================

import sys
import os.path
import optparse
import time
import argparse

import glob
import random

# ------------------------------------------------------------------------------
def getGenerator(file_name):
    if 'AcerMCPythia_AUET2BCTEQ6L1' in file_name:
        return 'AcerMCPythia_AUET2BCTEQ6L1'

    if 'AlpgenJimmy_AUET2CTEQ6L1' in file_name or 'AlpgenJimmy_Auto_AUET2CTEQ6L1' in file_name:
        return 'AlpgenJimmy_AUET2CTEQ6L1'

    if 'AlpgenPythia' in file_name or 'AlpgenPythia' in file_name:
        return 'AlpgenPythia'

    if 'MadGraphPythia_AUET2BCTEQ6L1' in file_name or 'MadgraphPythia_AUET2B_CTEQ6L1' in file_name:
        return 'MadGraphPythia_AUET2BCTEQ6L1'

    if 'McAtNloJimmy_AUET2CT10' in file_name:
        return 'McAtNloJimmy_AUET2CT10'

    if 'McAtNloJimmy' in file_name:
        return 'McAtNloJimmy'

    if 'PowhegPythia8_AU2CT10' in file_name:
        return 'PowhegPythia8_AU2CT10'

    if 'PowhegPythia_AUET2BCT10' in file_name:
        return 'PowhegPythia_AUET2BCT10'

    if 'Sherpa_CT10' in file_name:
        return 'Sherpa_CT10'

    if 'Herwigpp_UEEE3_CTEQ6L1' in file_name:
        return 'Herwigpp_UEEE3_CTEQ6L1'

    if 'gg2wwJimmy' in file_name:
        return 'gg2vvJimmy'

    if 'Pythia' in file_name:
        return 'Pythia'

    else:
        return 'uncategorized'

# ------------------------------------------------------------------------------
def getEntryType(file_name):
    if 'data' in file_name:
        # data - egamma
        if 'Egamma.period' in file_name:
            return "data_egamma"

        # data - muon
        if 'Muon.period' in file_name:
            return 'data_muon'

    if 'fake' in file_name:
        # fakes - egamma
        if 'Egamma.period' in file_name:
            return "fake_egamma"

        # data - muon
        if 'Muon.period' in file_name:
            return 'fake_muon'

    # Higgs
    if 'Higgs' in file_name:
        return 'Higgs__%s' % getGenerator(file_name)

    # W+jet
    if 'W_plus_jet' in file_name:
        return 'W_plus_jet__%s' % getGenerator(file_name)

    # Z+jets + drell yan
    if 'Z_plus_jet' in file_name or 'drell_yan' in file_name:
        return 'Z_plus_jet__%s' % getGenerator(file_name)
        # return 'drell_yan__%s' % getGenerator(file_name)

    # ZX
    if 'ZX' in file_name:
        return 'ZX__%s' % getGenerator(file_name)
        # return 'drell_yan__%s' % getGenerator(file_name)

    # diboson
    if 'diboson' in file_name:
        return 'diboson__%s' % getGenerator(file_name)

    if 'WW' in file_name:
        return 'WW__%s' % getGenerator(file_name)

    if 'WZ' in file_name:
        return 'WZ__%s' % getGenerator(file_name)

    if 'ZZ' in file_name:
        return 'ZZ__%s' % getGenerator(file_name)

    # single top
    if 'single_top' in file_name:
        return 'single_top__%s' % getGenerator(file_name)

    # ttbar
    if 'ttbar' in file_name:
        return 'ttbar__%s' % getGenerator(file_name)

    # singnal grids -- pmssm
    if 'signal_pmssm' in file_name:
        generator = getGenerator(file_name)
        # TODO make "get grid point" more robust
        grid_point = file_name.split('.')[4].strip('%s_' % generator)
        return 'signal_pmssm.%s.__%s' % (grid_point, generator)

    # signal grids -- simplified models
    if 'signal_simplified' in file_name:
        generator = getGenerator(file_name)
        # TODO make "get grid point" more robust
        # HACK because strip is not behaving
        grid_point = file_name.split('.')[4][len(generator)+1:]
        return 'signal_simplified.%s.__%s' % (grid_point,generator)

    # uncategorized
    return 'uncategorized'

# ------------------------------------------------------------------------------
def getEntryFillColor(entry_name):
    # Fakes
    if 'fake' in entry_name:
        return 920

    # data - egamma + muon
    if 'data_egamma' in entry_name or 'data_muon' in entry_name:
        return 1

    # W+jet
    if 'W_plus_jet' in entry_name:
        return 920

    # Z-gamma*
    if 'Z_plus_jet' in entry_name:
        return 798

    # diboson
    if 'diboson' in entry_name:
        return 821

    # single top
    if 'single_top' in entry_name:
        return 856

    # ttbar
    if 'ttbar' in entry_name:
        return 633

    # singnal grids
    if 'signal' in entry_name:
        return 0

    # uncategorized
    if 'uncategorized' in entry_name:
        return 0

# ------------------------------------------------------------------------------
def getEntryLineColor(entry_name):
    if 'signal' in entry_name:
        decent_colors = [4, 6, 7, 9, 38, 44, 46, 49]
        color_it = int(1000*random.random())%len(decent_colors)
        return decent_colors[color_it]

    return 1

# ------------------------------------------------------------------------------
def getEntryLineWidth(entry_name):
    if 'signal' in entry_name:
        return 4
    return 2

# ------------------------------------------------------------------------------
def getEntryLineStyle(entry_name):
    if 'signal' in entry_name:
        return 5
    return 1

# ------------------------------------------------------------------------------
def getEntryLabel(entry_name):
    # Fakes
    if 'fake' in entry_name:
        return 'Fakes'

    # data - egamma + muon
    if 'data' in entry_name:
        return 'Data'

    # W+jet
    if 'W_plus_jet' in entry_name:
        return 'W+jets'

    # Z-gamma*
    if 'Z_plus_jet' in entry_name:
        return 'Z/\\gamma^{*}+jets'

    # diboson
    if 'diboson' in entry_name:
        return 'diboson'

    # single top
    if 'single_top' in entry_name:
        return 'Single top'

    # ttbar
    if 'ttbar' in entry_name:
        return 't\\bar{t}'

    # singnal grids
    if 'signal' in entry_name:
        return entry_name
        # return entry_name.strip('signal')

    # uncategorized
    if 'uncategorized' in entry_name:
        return 'uncategorized'

# ------------------------------------------------------------------------------
def getSubDir(entry_name):
    if 'signal' in entry_name:
        return 'signal'
    if 'data' in entry_name:
        return 'data'
    return 'background'

# ------------------------------------------------------------------------------
def getEntryCollections(path_to_files):
    file_list = glob.glob('%s/*' % path_to_files)
    entry_collections = {}
    for fl in file_list:
        print '--------------------------------------------------------'
        dir_name = os.path.dirname(path_to_files)
        file_name = fl.strip(dir_name)
        file_name = fl.split('/')[-1]
        print fl
        print '\tdir_name:  %s' % dir_name
        print '\tfile_name: %s' % file_name

        this_entry = getEntryType(file_name)
        if not this_entry in entry_collections:
            entry_collections[this_entry] = []
        entry_collections[this_entry].append(fl)

    return entry_collections

# ------------------------------------------------------------------------------
def writeEntryFile(entry_name, entry_collection):
    entry_file_name = 'entry_files/%s/%s.yml' % ( getSubDir(entry_name)
                                                , entry_name
                                                )
    print 'entry_name: %s' % entry_name
    print 'entry_collection: %s' % entry_collection
    print 'entry_file_name: %s' % entry_file_name

    ensure_dir(entry_file_name)
    f = open(entry_file_name, 'w')

    f.write('label:        %s\n' % getEntryLabel(entry_name) )
    f.write('fill_color:   %s\n' % getEntryFillColor(entry_name) )
    f.write('line_color:   %s\n' % getEntryLineColor(entry_name) )
    f.write('line_width:   %s\n' % getEntryLineWidth(entry_name) )
    f.write('line_style:   %s\n' % getEntryLineStyle(entry_name) )
    f.write('marker_style: 20\n' )
    f.write('inputs:\n' )

    for ec in entry_collection:
        f.write('               - %s\n' % ec )

    f.close()

# ------------------------------------------------------------------------------
def ensure_dir(f):
    d = os.path.dirname(f)

    if not os.path.exists(d):
        os.makedirs(d)

# ------------------------------------------------------------------------------
def help():
    print 'Usage:'
    print ' python generate_plotting_entries.py --dir=<TARGET_DIRECTORY_WITH_HIST_FILES>'

# ------------------------------------------------------------------------------
def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--dir', dest = 'target_dir', action = 'store', default = '')
    args = parser.parse_args()

    if args.target_dir == '':
        help()
        return

    entry_collections = getEntryCollections(args.target_dir)
    print '--------------------------------------------------------------------------------'
    print 'printing entry collections'
    print '--------------------------------------------------------------------------------'
    for ec in entry_collections:
        writeEntryFile(ec, entry_collections[ec])

# ==============================================================================
if __name__ == '__main__':
    main()
