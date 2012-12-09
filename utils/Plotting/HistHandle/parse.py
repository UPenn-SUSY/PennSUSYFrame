#!/usr/bin/env python

import sys
import inspect
import os.path
import optparse
import time

import yaml

import metaroot
import ROOT

import HistHandle as hh

# ==============================================================================
class InputContainer(object):
    # --------------------------------------------------------------------------
    def __init__( self
                , input_dict
                ):
        self.name = input_dict['name']
        self.color = input_dict['color']
        self.marker_style = input_dict['marker_style']
        self.entries = []
        for e in input_dict['entries']:
            self.entries.append(EntryContainer(e))

        self.hist_info = hh.Objects.HistInfo( self.name
                                    , self.color
                                    , self.color
                                    , self.marker_style
                                    )

    # --------------------------------------------------------------------------
    def genHistMerger( self
                     , dir_name
                     , hist_name
                     ):
        hist_handle_dict = {}
        for e in self.entries:
            hist_handle_dict[e.label] = e.genHistHandle(dir_name, hist_name)
        tmp =  hh.Merger.HistMerger( dir_name
                                   , hist_name
                                   , hist_handle_dict
                                   , self.hist_info
                                   )
        tmp.genMergedHist()
        return tmp

# ==============================================================================
class EntryContainer(object):
    # --------------------------------------------------------------------------
    def __init__( self
                , entry_dict
                ):
        self.label =        entry_dict['label']
        self.fill_color =   entry_dict['fill_color']
        self.fill_color =   entry_dict['fill_color']
        self.line_color =   entry_dict['line_color']
        self.marker_style = entry_dict['marker_style']
        self.inputs =       entry_dict['inputs']
        self.file_list = [ ROOT.TFile(f) for f in self.inputs ]

        self.hist_info = hh.Objects.HistInfo( self.label
                                            , self.line_color
                                            , self.fill_color
                                            , self.marker_style
                                            )

    # --------------------------------------------------------------------------
    def genHistHandle( self
                     , dir_name
                     , hist_name
                     ):
        return hh.Handle.HistHandle( dir_name
                                   , hist_name
                                   , self.hist_info
                                   , self.file_list
                                   )

# ------------------------------------------------------------------------------
def parseInputs():
    # TODO do proper parsing so we aren't sensitive to order of inputs
    global_config_file = sys.argv[1]
    config_dict = processConfigFile(global_config_file)

    outfile = sys.argv[2]

    return {'config':config_dict, 'outfile':outfile}

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
def processConfigFile(config_file_name):
    print 'config_file_name: %s ' % config_file_name
    config_file = open(config_file_name)
    config_dict = yaml.load(config_file)

    input_containers = {}
    for cd in config_dict:
        input_containers[cd['class']] = InputContainer(cd)

    return input_containers

# ==============================================================================
if __name__ == '__main__':
    config = parseInputs()

    hm_num   = config['Numerator'  ].genHistMerger( 'ee_sig_lep', 'mll')
    hm_denom = config['Denominator'].genHistMerger( 'ee_sig_lep', 'mll')

    hist_painter = hp.HistPainter( num   = hm_num
                                 , denom = hm_denom
                                 )

    canv_default = metaroot.hist.CanvasOptions(width=800, height=600)
    canv_log_y   = metaroot.hist.CanvasOptions(width=800, height=600, log_y=True)

    print 'Log'
    pile_test_stack = hist_painter.pileAndRatio(
            num_type       = hh.Objects.plain_hist,
            denom_type     = hh.Objects.stack_hist,
            canvas_options = canv_log_y,
            legend         = True)
    # pile_test_stack.Print('~/Desktop/test_log.png')
    pile_test_stack.Print('test_log.png')
    pile_test_stack.Close()
