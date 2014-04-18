#!/usr/bin/env python

import sys
import inspect
import os.path
import optparse
import time

import ROOT

import HistHandle as hh

# ==============================================================================
class EntryContainer(object):
    """
    Object to collect all the files associated with a single component of a plot
    This will be things like ttbar, Z+jets, ...
    # TODO add cross section scaling
    """
    # --------------------------------------------------------------------------
    def __init__( self
                , label
                , fill_color = 1
                , line_color = 1
                , line_width = 2
                , line_style = 1
                , marker_style = 20
                , input_file_list = []
                ):
        self.label           = label
        self.fill_color      = fill_color
        self.line_color      = line_color
        self.line_width      = line_width
        self.line_style      = line_style
        self.marker_style    = marker_style
        self.input_file_list = input_file_list

        self.file_list = [ ROOT.TFile(ifl) for ifl in self.input_file_list ]
        print self.file_list

        self.hist_info = hh.Objects.HistInfo( self.label
                                            , fill_color = self.fill_color
                                            , line_color = self.line_color
                                            , line_width = self.line_width
                                            , line_style = self.line_style
                                            , marker_style = self.marker_style
                                            )

    # --------------------------------------------------------------------------
    def genHistHandle( self
                     , dir_name
                     , hist_name
                     , lumi_modeled = 1.
                     , lumi_target  = 1.
                     ):
        return hh.Handle.HistHandle( dir_name
                                   , hist_name
                                   , self.hist_info
                                   , self.file_list
                                   , lumi_modeled
                                   , lumi_target
                                   )

# ==============================================================================
class InputContainer(object):
    """
    Object which collects all the inputs associated which are to be merged
    into a HistMerger.
    i.e. one InputContainer for numerator, one for denominator, ...

    This will hold entries for each component of the merger. i.e. one entry for
    ttbar, one for Z+jets, ...
    """
    # --------------------------------------------------------------------------
    def __init__( self
                , name
                , fill_color = 1
                , line_color = 1
                , line_width = 2
                , line_style  = 1
                , marker_style = 20
                , entry_list = []
                , lumi_modeled = 1.
                , lumi_target  = 1.
                ):
        self.name         = name
        self.fill_color   = fill_color
        self.line_color   = line_color
        self.line_width   = line_width
        self.line_style   = line_style

        self.marker_style = marker_style

        self.entries = entry_list
        # self.entries = []
        # for el in entrty_list:
        #     self.entries.append( EntryContainer( el
        #                                        )
        #                        )

        self.lumi_modeled = lumi_modeled
        self.lumi_target  = lumi_target

        self.hist_info = hh.Objects.HistInfo( self.name
                                            , fill_color = self.fill_color
                                            , line_color = self.line_color
                                            , line_width = self.line_width
                                            , line_style = self.line_style
                                            , marker_style = self.marker_style
                                            )

    # --------------------------------------------------------------------------
    def getInputFileList(self):
        input_file_list = []
        for e in self.entries:
            input_file_list.append(e.file_list)
        return hh.Helper.flatten(input_file_list)

    # --------------------------------------------------------------------------
    def genHistMerger( self
                     , dir_name
                     , hist_name
                     ):
        print 'Creating HistMerger object for:'
        print '\tName:      %s' % self.name
        print '\tDirectory: %s' % dir_name
        print '\tHist:      %s' % hist_name

        print 'getting HistHandle objects'
        hist_handle_dict = {}
        for e in self.entries:
            hist_handle_dict[e.label] = e.genHistHandle( dir_name
                                                       , hist_name
                                                       , lumi_modeled = self.lumi_modeled
                                                       , lumi_target  = self.lumi_target
                                                       )
        # generate HistMerger object
        tmp = hh.Merger.HistMerger( dir_name
                                  , hist_name
                                  , hist_handle_dict
                                  , self.hist_info
                                  )
        tmp.genMergedHist()
        return tmp

# ==============================================================================
def getListOfFiles(input_container_list = []):
    assert isinstance(input_container_list, list)

    file_list = []
    for icl in input_container_list:
        for e in icl.entries:
            for fl in e.file_list:
                print fl
                file_list.append(fl)

    # I think this is the same as above, but test before uncommenting
    # file_list = [ f for f in e.input_file_list for e in icl.entries for icl in input_file_list ]

    return file_list

# # ==============================================================================
# class OptimizeContainer(object):
#     # --------------------------------------------------------------------------
#     def __init__(self, input_dict):
#         # self.cut_dir =      input_dict['cut_dir']
#         self.to_optimize =  input_dict['to_optimize']
#         self.direction =    input_dict['direction']
#         self.fixed_points = input_dict['fixed_points']
#         self.scan = bool(input_dict['scan'])
# 
#         if   self.direction == 'right': self.direction = hh.right
#         elif self.direction == 'left':  self.direction = hh.left
#         elif self.direction == 'equal': self.direction = hh.equal
#         else: assert False
# 
# # ------------------------------------------------------------------------------
# def parseInputs():
#     # print '---------------------------------------'
#     # print 'parseInputs()'
#     # print '---------------------------------------'
#     if len(sys.argv) != 3:
#         print 'Incorrect number of inputs'
#         print 'usage:'
#         print '  %s <config_file_name> <out_file_name>' % sys.argv[0]
#         return None
# 
#     # TODO do proper parsing so we aren't sensitive to order of inputs
#     global_config_file = sys.argv[1]
#     config_dict = processConfigFile(global_config_file)
# 
#     outfile = sys.argv[2]
# 
#     return { 'config':config_dict['config']
#            , 'files':config_dict['files']
#            , 'optimize':config_dict['optimize']
#            , 'outfile':outfile
#            }
# 
# # ------------------------------------------------------------------------------
# def interpretEnvVariables(string):
#     if type(string) == str:
#         while not string.find("$") == -1:
#             search_begin = string.find("${") + 2
#             search_end = string.find("}")
#             search_key = string[search_begin:search_end]
#             string = string.replace( "${%s}" % search_key
#                                    , os.environ.get(search_key)
#                                    )
#     return string
# 
# # ------------------------------------------------------------------------------
# def processConfigFile(config_file_name):
#     # print '---------------------------------------'
#     # print 'processConfigFile(%s)' % config_file_name
#     # print '---------------------------------------'
#     # print 'config_file_name: %s ' % config_file_name
#     config_file = open(config_file_name, 'r')
#     config_dict = yaml.load(config_file, Loader)
# 
#     input_block = processInputBlock(config_dict['Inputs'])
#     input_containers = input_block['config']
#     input_files      = input_block['files']
# 
#     optimize_block = None
#     if 'Optimize' in config_dict:
#         optimize_block = processOptimizeBlock(config_dict['Optimize'])
# 
#     return { 'config':input_containers
#            , 'files':input_files
#            , 'optimize':optimize_block
#            }
# 
# # ------------------------------------------------------------------------------
# def processInputBlock(input_dict):
#     # print '---------------------------------------'
#     # print 'processInputBlock(...)'
#     # print '    %s' % input_dict
#     # print '---------------------------------------'
#     input_containers = {}
#     input_files = []
#     for inp in input_dict:
#         key = inp['class']
#         # print 'key: %s' % key
#         # print '\tinp: %s' % inp
#         input_containers[key] = InputContainer(inp)
# 
#         input_files.append(input_containers[key].getInputFileList())
# 
#     input_files = hh.Helper.flatten(input_files)
# 
#     return {'config':input_containers, 'files':input_files}
# 
# # ------------------------------------------------------------------------------
# def processOptimizeBlock(input_dict):
#     optimizations = {}
#     for inp in input_dict:
#         optimizations[inp['to_optimize']] = OptimizeContainer(inp)
# 
#     return optimizations
