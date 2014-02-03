#!/usr/bin/env python

import sys
import os.path
import optparse
import time


# ==============================================================================
# ------------------------------------------------------------------------------
def writeScriptHead(out_file):
    out_file.write("""#!/usr/bin/env python

import sys
import os.path
import optparse
import time

import ROOT
import rootlogon
import metaroot

# ==============================================================================
ROOT.gROOT.ProcessLine(".x ${ROOTCOREDIR}/scripts/load_packages.C")
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libProgressBar.so')
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libCutFlowTracker.so')
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libPennSusyFrameCore.so')
ROOT.gSystem.Load('${BASE_WORK_DIR}/lib/libEwkAnalysis.so')

""")

# ------------------------------------------------------------------------------
def writeFileList(out_file, file_list):
    out_file.write("# ==============================================================================\n")
    out_file.write("file_list = [")
    for i, fl in enumerate(file_list):
        if i == 0:
            out_file.write(' "%s"\n' % fl)
        else:
            out_file.write('            , "%s"\n' % fl)
    out_file.write("            ]\n")
    out_file.write("\n")
    out_file.write("""t = ROOT.TChain('susy')
for fl in file_list:
    t.AddFile(fl)

""")

# ------------------------------------------------------------------------------
def writeScriptTail(out_file):
    out_file.write("""# ==============================================================================
ewa = ROOT.PennSusyFrame.EwkAnalysis(t)
ewa.Loop()

# ==============================================================================
print ''
print ''
""")

# ------------------------------------------------------------------------------
def getFileList(file_list_string):
    file_list = file_list_string.split(',')
    return file_list

# ==============================================================================
if __name__ == '__main__':
    file_list_string = sys.argv[1]
    file_list = getFileList(file_list_string)

    out_file = file('run_script.py', 'w')

    writeScriptHead(out_file)
    writeFileList(out_file, file_list)
    writeScriptTail(out_file)
